
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tresor_fsm is
    Port ( clk : in std_logic;
           res : in std_logic;
           key_ok : in std_logic;
           code_ok : in std_logic;
           daytime : in std_logic;
           green_led : out std_logic;
           yellow_led : out std_logic;
           open_door : out std_logic);
end tresor_fsm;

architecture Behavioral of tresor_fsm is

	-- fill in here

begin
	-- process for generating the registers (current state & output values)
	regs : PROCESS( )-- fill in here)
	BEGIN

		-- fill in here

	END PROCESS;

	-- process for generating nextstate
	ns_logic : PROCESS( )-- fill in here)
	BEGIN
	
		-- fill in here	
	
	END PROCESS;

	-- process for generating output that is going to be registered
	o_logic : PROCESS( )-- fill in here )
	BEGIN
	
		-- fill in here
	
	END PROCESS;

end Behavioral;
