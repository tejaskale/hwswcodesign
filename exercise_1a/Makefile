
MODULE_1 = sim_1

SRCS_1 = prod_1.cpp fifo_1.cpp consum_1.cpp main_1.cpp
OBJS_1 = $(SRCS_1:.cpp=.o)


## Variable that points to SystemC installation path
##SYSTEMC = /nfs/lis/tools/systemc/2.3.1


SHELL  = /bin/sh

CC     = g++
OPT    = -O3
DEBUG  = -g
OTHER  = -Wno-deprecated `pkg-config --cflags systemc`
CFLAGS = $(DEBUG) $(OTHER)
LIBS   = `pkg-config --libs systemc`

EXE_1  = $(MODULE_1).x

.SUFFIXES: .cc .cpp .o .x

$(EXE_1): $(OBJS_1)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $(OBJS_1) 2>&1 | c++filt

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

.cc.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_1) *~ $(EXE_1) core
	makedepend --clean

depend:
	makedepend $(CFLAGS) $(SRCS_1) > /dev/null 2>&1

# DO NOT DELETE

threadprod_1.o: prod_1.h /nfs/tools/systemc/2.3.1a/include/systemc.h
threadprod_1.o: /usr/include/stdint.h /usr/include/features.h
threadprod_1.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
threadprod_1.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
threadprod_1.o: /usr/include/bits/wchar.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/systemc
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_cmnhdr.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config.hpp
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/user.hpp
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/select_compiler_config.hpp
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/compiler/gcc.hpp
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/select_stdlib_config.hpp
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/select_platform_config.hpp
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/posix_features.hpp
threadprod_1.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
threadprod_1.o: /usr/include/bits/environments.h /usr/include/bits/types.h
threadprod_1.o: /usr/include/bits/typesizes.h /usr/include/bits/confname.h
threadprod_1.o: /usr/include/getopt.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/suffix.hpp
threadprod_1.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
threadprod_1.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
threadprod_1.o: /usr/include/bits/posix2_lim.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_externs.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_except.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_module.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_kernel_ids.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_report.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_report_handler.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_process.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_iostream.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_constants.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_object.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_attribute.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_export.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_communication_ids.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_interface.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_module_name.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_sensitive.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_time.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_nbdefs.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/scfx_ieee.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/sc_fxdefs.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_machine.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/detail/endian.hpp
threadprod_1.o: /usr/include/endian.h /usr/include/bits/endian.h
threadprod_1.o: /usr/include/bits/byteswap.h /usr/include/bits/byteswap-16.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/sc_fx_ids.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_nbutils.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bit_ids.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_int_ids.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_wait.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_simcontext.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_status.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_hash.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_pq.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_wait_cthread.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_logic.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_macros.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_mempool.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bit.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_ifs.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_writer_policy.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_process_handle.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_list.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_ver.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_buffer.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_port.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_event.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_prim_channel.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/tracing/sc_trace.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_clock.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_clock_ports.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_ports.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_event_finder.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_event_queue.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_fifo.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_fifo_ifs.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_fifo_ports.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_mutex.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_mutex_if.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_semaphore.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_semaphore_if.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_resolved.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_resolved_ports.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_rv.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_lv.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_lv_base.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bv_base.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bit_proxies.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_proxy.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_signed.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/misc/sc_value_base.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_temporary.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_length_param.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/sc_context.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_nbexterns.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_unsigned.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_int_base.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_uint_base.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_rv_ports.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bv.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_bigint.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_biguint.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_int.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_uint.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/misc/sc_concatref.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_utils_ids.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_pvector.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_vector.h
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config.hpp
threadprod_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/utility/enable_if.hpp
threadfifo_1.o: fifo_1.h /nfs/tools/systemc/2.3.1a/include/systemc.h
threadfifo_1.o: /usr/include/stdint.h /usr/include/features.h
threadfifo_1.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
threadfifo_1.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
threadfifo_1.o: /usr/include/bits/wchar.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/systemc
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_cmnhdr.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config.hpp
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/user.hpp
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/select_compiler_config.hpp
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/compiler/gcc.hpp
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/select_stdlib_config.hpp
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/select_platform_config.hpp
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/posix_features.hpp
threadfifo_1.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
threadfifo_1.o: /usr/include/bits/environments.h /usr/include/bits/types.h
threadfifo_1.o: /usr/include/bits/typesizes.h /usr/include/bits/confname.h
threadfifo_1.o: /usr/include/getopt.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/suffix.hpp
threadfifo_1.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
threadfifo_1.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
threadfifo_1.o: /usr/include/bits/posix2_lim.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_externs.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_except.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_module.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_kernel_ids.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_report.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_report_handler.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_process.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_iostream.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_constants.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_object.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_attribute.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_export.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_communication_ids.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_interface.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_module_name.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_sensitive.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_time.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_nbdefs.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/scfx_ieee.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/sc_fxdefs.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_machine.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/detail/endian.hpp
threadfifo_1.o: /usr/include/endian.h /usr/include/bits/endian.h
threadfifo_1.o: /usr/include/bits/byteswap.h /usr/include/bits/byteswap-16.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/sc_fx_ids.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_nbutils.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bit_ids.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_int_ids.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_wait.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_simcontext.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_status.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_hash.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_pq.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_wait_cthread.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_logic.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_macros.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_mempool.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bit.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_ifs.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_writer_policy.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_process_handle.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_list.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_ver.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_buffer.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_port.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_event.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_prim_channel.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/tracing/sc_trace.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_clock.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_clock_ports.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_ports.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_event_finder.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_event_queue.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_fifo.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_fifo_ifs.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_fifo_ports.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_mutex.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_mutex_if.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_semaphore.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_semaphore_if.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_resolved.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_resolved_ports.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_rv.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_lv.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_lv_base.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bv_base.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bit_proxies.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_proxy.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_signed.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/misc/sc_value_base.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_temporary.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_length_param.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/sc_context.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_nbexterns.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_unsigned.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_int_base.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_uint_base.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_rv_ports.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bv.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_bigint.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_biguint.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_int.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_uint.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/misc/sc_concatref.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_utils_ids.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_pvector.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_vector.h
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config.hpp
threadfifo_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/utility/enable_if.hpp
threadconsum_1.o: consum_1.h /nfs/tools/systemc/2.3.1a/include/systemc.h
threadconsum_1.o: /usr/include/stdint.h /usr/include/features.h
threadconsum_1.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
threadconsum_1.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
threadconsum_1.o: /usr/include/bits/wchar.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/systemc
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_cmnhdr.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config.hpp
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/user.hpp
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/select_compiler_config.hpp
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/compiler/gcc.hpp
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/select_stdlib_config.hpp
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/select_platform_config.hpp
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/posix_features.hpp
threadconsum_1.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
threadconsum_1.o: /usr/include/bits/environments.h /usr/include/bits/types.h
threadconsum_1.o: /usr/include/bits/typesizes.h /usr/include/bits/confname.h
threadconsum_1.o: /usr/include/getopt.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/suffix.hpp
threadconsum_1.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
threadconsum_1.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
threadconsum_1.o: /usr/include/bits/posix2_lim.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_externs.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_except.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_module.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_kernel_ids.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_report.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_report_handler.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_process.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_iostream.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_constants.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_object.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_attribute.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_export.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_communication_ids.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_interface.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_module_name.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_sensitive.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_time.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_nbdefs.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/scfx_ieee.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/sc_fxdefs.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_machine.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/detail/endian.hpp
threadconsum_1.o: /usr/include/endian.h /usr/include/bits/endian.h
threadconsum_1.o: /usr/include/bits/byteswap.h
threadconsum_1.o: /usr/include/bits/byteswap-16.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/sc_fx_ids.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_nbutils.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bit_ids.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_int_ids.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_wait.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_simcontext.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_status.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_hash.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_pq.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_wait_cthread.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_logic.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_macros.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_mempool.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bit.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_ifs.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_writer_policy.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_process_handle.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_list.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_ver.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_buffer.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_port.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_event.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_prim_channel.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/tracing/sc_trace.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_clock.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_clock_ports.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_ports.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_event_finder.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_event_queue.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_fifo.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_fifo_ifs.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_fifo_ports.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_mutex.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_mutex_if.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_semaphore.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_semaphore_if.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_resolved.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_resolved_ports.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_rv.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_lv.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_lv_base.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bv_base.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bit_proxies.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_proxy.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_signed.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/misc/sc_value_base.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_temporary.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_length_param.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/sc_context.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_nbexterns.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_unsigned.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_int_base.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_uint_base.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_rv_ports.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bv.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_bigint.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_biguint.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_int.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_uint.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/misc/sc_concatref.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_utils_ids.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_pvector.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_vector.h
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config.hpp
threadconsum_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/utility/enable_if.hpp
threadmain_1.o: consum_1.h /nfs/tools/systemc/2.3.1a/include/systemc.h
threadmain_1.o: /usr/include/stdint.h /usr/include/features.h
threadmain_1.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
threadmain_1.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
threadmain_1.o: /usr/include/bits/wchar.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/systemc
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_cmnhdr.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config.hpp
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/user.hpp
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/select_compiler_config.hpp
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/compiler/gcc.hpp
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/select_stdlib_config.hpp
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/select_platform_config.hpp
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/posix_features.hpp
threadmain_1.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
threadmain_1.o: /usr/include/bits/environments.h /usr/include/bits/types.h
threadmain_1.o: /usr/include/bits/typesizes.h /usr/include/bits/confname.h
threadmain_1.o: /usr/include/getopt.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config/suffix.hpp
threadmain_1.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
threadmain_1.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
threadmain_1.o: /usr/include/bits/posix2_lim.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_externs.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_except.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_module.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_kernel_ids.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_report.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_report_handler.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_process.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_iostream.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_constants.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_object.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_attribute.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_export.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_communication_ids.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_interface.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_module_name.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_sensitive.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_time.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_nbdefs.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/scfx_ieee.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/sc_fxdefs.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_machine.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/detail/endian.hpp
threadmain_1.o: /usr/include/endian.h /usr/include/bits/endian.h
threadmain_1.o: /usr/include/bits/byteswap.h /usr/include/bits/byteswap-16.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/sc_fx_ids.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_nbutils.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bit_ids.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_int_ids.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_wait.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_simcontext.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_status.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_hash.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_pq.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_wait_cthread.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_logic.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_macros.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_mempool.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bit.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_ifs.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_writer_policy.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_process_handle.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_list.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_ver.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_buffer.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_port.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/kernel/sc_event.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_prim_channel.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/tracing/sc_trace.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_clock.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_clock_ports.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_ports.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_event_finder.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_event_queue.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_fifo.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_fifo_ifs.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_fifo_ports.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_mutex.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_mutex_if.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_semaphore.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_semaphore_if.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_resolved.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_resolved_ports.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_rv.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_lv.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_lv_base.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bv_base.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bit_proxies.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_proxy.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_signed.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/misc/sc_value_base.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_temporary.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_length_param.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/fx/sc_context.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_nbexterns.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_unsigned.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_int_base.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_uint_base.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/communication/sc_signal_rv_ports.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/bit/sc_bv.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_bigint.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_biguint.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_int.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/int/sc_uint.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/datatypes/misc/sc_concatref.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_utils_ids.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_pvector.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/utils/sc_vector.h
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/config.hpp
threadmain_1.o: /nfs/tools/systemc/2.3.1a/include/sysc/packages/boost/utility/enable_if.hpp
threadmain_1.o: prod_1.h fifo_1.h
