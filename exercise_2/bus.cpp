// bus.cpp

#include "bus.h"

void bus::b_transport(int SocketId, tlm_generic_payload& trans, sc_time& t)
{

    unsigned int portId;
    unsigned int length;
    
    sc_time b_transport_start_time;

    // check if secondary access has already been arbitrated (bus is busy). If yes return with error.
    // (also in case the b_transport_call to a slave has not yet returned due to wait() in the slave)
    // there is no priority mechanism to resolve access attempts by different masters at the same time
    if(secondary_access_arbitrated)
	{
	if(LOG)
	  cout<<sc_time_stamp()<<" "<<masters[SocketId]<<" wants to access bus, request denied"<< endl;
	trans.set_response_status(TLM_GENERIC_ERROR_RESPONSE);
	// even if access failed it costs at least the arbitration delay (master will wait for this amount of time
	t += sc_time(BUS_ARBITRATION_LATENCY*BUS_CLK_PERIOD, SC_NS);
	return;
	}
    else if (sc_time_stamp() < bus_busy_end_time || ongoing_b_transport) // bus is busy but no secondary access
									 // has already been arbitrated
    {
	if(LOG)
	  cout<<sc_time_stamp()<<" "<<masters[SocketId]<<" wants to access bus, it is a secondary access, has to wait..."<< endl;
	secondary_access_arbitrated = true;
	wait(primary_access_done);	      // we have to wait until primary access finishes
	secondary_access_arbitrated = false;  // secondary becomes primary, we can allow a new secondary
    }

    // take into account bus arbitration latency
    t = t + sc_time(BUS_ARBITRATION_LATENCY*BUS_CLK_PERIOD, SC_NS);

    // determine the correct slave identified via the address contained in the generic payload
    // the address is used in a very simplistic way and differentiates only between the slaves
    // according to the slave ID
    portId = trans.get_address();
    assert(portId < NR_OF_SLAVES);

    if(LOG)
      cout<<sc_time_stamp()<<" "<<name()<<": "<<masters[SocketId]<<" accesses "<<slaves[portId]<<"."<<endl;

	
    ongoing_b_transport=true;
    b_transport_start_time=sc_time_stamp();

    // call the b_transport function of the target slave using the appropriate socket
    bus_initiator_socket[portId]->b_transport(trans, t);

    ongoing_b_transport=false;
    total_busy_time += sc_time_stamp()-b_transport_start_time; // account for possible time spent in sclave
    //cout<<sc_time_stamp()<<" "<<name()<<" add. time: " <<sc_time_stamp()-b_transport_start_time<<endl;
    
    bus_busy_end_time = t + sc_time_stamp();
    total_busy_time += t;
    //cout<<sc_time_stamp()<<" "<<name()<<"  normal tranfer time: " << t <<endl;
    //cout<<sc_time_stamp()<<" "<<name()<<": "<<masters[SocketId]<<" accesses "<<slaves[portId]<<\
    	". Ongoing access ends at time "<< bus_busy_end_time <<endl;

    primary_access_done.notify(t); // after time t from now the ongoing primary access is over
				   // if a secondary access was waiting it can now become active (i.e. primary access)

    return;
}

void bus::output_load()
{
	// necessary correction for bus load calculation 
	// if bus_busy_end_time is after end of simulation difference has to be subtracted
	if(bus_busy_end_time > sc_time_stamp())
		total_busy_time -= (bus_busy_end_time - sc_time_stamp());
	if(LOG)
	  cout << name() << " total_busy_time " << total_busy_time <<endl;
	cout << name() <<fixed<<setprecision(1)<< " load: " << (total_busy_time)/(sc_time_stamp())*100 << "%"<<endl;
}


