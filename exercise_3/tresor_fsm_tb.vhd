--------------------------------------------------------------------------------
-- Design Name:   tresor_fsm
-- Module Name:   tresor_fsm_tb.vhd
-- Project Name:  fsm
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: tresor_fsm
--
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends 
-- that these types always be used for the top-level I/O of a design in order 
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.ALL;

ENTITY tresor_fsm_tb_vhd IS
END tresor_fsm_tb_vhd;

ARCHITECTURE behavior OF tresor_fsm_tb_vhd IS 

	-- Component Declaration for the Unit Under Test (UUT)
	COMPONENT tresor_fsm
	PORT(
		clk : IN std_logic;
		res : IN std_logic;
		key_ok : IN std_logic;
		code_ok : IN std_logic;
		daytime : IN std_logic;          
		green_led : OUT std_logic;
		yellow_led : OUT std_logic;
		open_door : OUT std_logic
		);
	END COMPONENT;

	--Inputs
	SIGNAL clk :  std_logic := '0';
	SIGNAL res :  std_logic := '0';
	SIGNAL key_ok :  std_logic := '0';
	SIGNAL code_ok :  std_logic := '0';
	SIGNAL daytime :  std_logic := '0';

	--Outputs
	SIGNAL green_led :  std_logic;
	SIGNAL yellow_led :  std_logic;
	SIGNAL open_door :  std_logic;

	-- expected Outputs (for comparison)
	SIGNAL green_led_exp :  std_logic;
	SIGNAL yellow_led_exp :  std_logic;
	SIGNAL open_door_exp :  std_logic;


BEGIN

	-- Instantiate the Unit Under Test (UUT)
	uut: tresor_fsm PORT MAP(
		clk => clk,
		res => res,
		key_ok => key_ok,
		code_ok => code_ok,
		daytime => daytime,
		green_led => green_led,
		yellow_led => yellow_led,
		open_door => open_door
	);

   -- generate a clock with 100 ns period
	clkg : PROCESS
	BEGIN
		WAIT FOR 50 ns;
		clk <= NOT clk;
	END PROCESS;

	-- generate stimuli
	tb : PROCESS
	BEGIN
		-- we reset the fsm
		wait for 200 ns;
		res <= '1';
		wait for 100 ns;
		res <= '0';
		-- now we create some stimuli
		wait for 200 ns;
		daytime <= '1';
		wait for 300 ns;
		key_ok <= '1';
		wait for 200 ns;
		code_ok <= '1';
		wait for 300 ns;
		key_ok <= '0';
		wait for 400 ns;
		code_ok <= '0';
		wait for 600 ns;
		key_ok <= '1';
		wait for 300 ns;
		key_ok <= '0';
		wait for 600 ns;
		code_ok <= '1';
		wait for 200 ns;
		code_ok <= '0';
		wait for 600 ns;
		code_ok <= '1';
		wait for 200 ns;
		key_ok <= '1';
		wait for 300 ns;
		code_ok <= '0';
		wait for 300 ns;
		key_ok <= '0';
		wait for 600 ns;
		daytime <= '0';
		wait for 300 ns;
		key_ok <= '1';
		wait for 200 ns;
		code_ok <= '1';
		wait for 300 ns;
		key_ok <= '0';
		code_ok <= '0';
		daytime <= '1';
		wait for 600 ns;
		key_ok <= '1';
		wait for 200 ns;
		code_ok <= '1';
		wait for 300 ns;
		res <= '1';
		wait for 300 ns;
		res <= '0';
		wait for 200 ns;
		key_ok <= '1';
		wait for 200 ns;
		code_ok <= '1';
		wait for 300 ns;


		wait; -- will wait forever
	END PROCESS;

	-- generate expected response signals
	resp : PROCESS
	BEGIN
		yellow_led_exp <= '0';
		green_led_exp <= '0';
		wait for 850 ns;
		yellow_led_exp <= '1';
		wait for 200 ns;
		yellow_led_exp <= '0';
		green_led_exp <= '1';
		wait for 300 ns;
		green_led_exp <= '0';
		wait for 1000 ns;
		yellow_led_exp <= '1';
		wait for 300 ns;
		yellow_led_exp <= '0';
		wait for 1600 ns;
		yellow_led_exp <= '1';
		wait for 100 ns;
		yellow_led_exp <= '0';
		green_led_exp <= '1';
		wait for 500 ns;
		green_led_exp <= '0';
		wait for 2000 ns;
		yellow_led_exp <= '1';
		wait for 200 ns;
		yellow_led_exp <= '0';
		green_led_exp <= '1';
		wait for 300 ns;
		green_led_exp <= '0';
		wait for 400 ns;
		yellow_led_exp <= '1';
		wait for 100 ns;
		yellow_led_exp <= '0';
		green_led_exp <= '1';

		wait;
	end process;

	open_door_exp <= green_led_exp;

END;
