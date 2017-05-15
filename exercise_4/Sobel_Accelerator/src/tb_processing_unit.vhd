library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

-------------------------------------------------------------------------------

entity tb_processing_unit is

end tb_processing_unit;

-------------------------------------------------------------------------------

architecture behavioral of tb_processing_unit is

  component processing_unit is
    port (bus_clk : in  std_logic;
          rst     : in  std_logic;
          enable  : in  std_logic;
          GPIO    : in  std_logic_vector (7 downto 0);
          din_0   : in  std_logic_vector (7 downto 0);
          din_1   : in  std_logic_vector (7 downto 0);
          din_2   : in  std_logic_vector (7 downto 0);
          o_data  : out std_logic_vector (7 downto 0);
          o_wr_en : out std_logic;
          p_data  : out std_logic_vector (31 downto 0);
          p_wr_en : out std_logic;
          p_full  : in  std_logic
          );
  end component;

  -- the size of the frames to be processed
  constant FRAME_HEIGHT : integer := 480;
  constant FRAME_WIDTH  : integer := 854;


  signal clk         : std_logic := '0';
  signal reset       : std_logic := '0';
  signal enable_sig  : std_logic;
  signal din_0_sig   : std_logic_vector (7 downto 0);
  signal din_1_sig   : std_logic_vector (7 downto 0);
  signal din_2_sig   : std_logic_vector (7 downto 0);
  signal o_data_sig  : std_logic_vector (7 downto 0);
  signal o_wr_en_sig : std_logic;
  signal GPIO        : std_logic_vector (7 downto 0);
  signal prof_data   : std_logic_vector (31 downto 0);
  signal prof_wren   : std_logic;
  signal prof_full   : std_logic;

  -- signals as expected 
  signal Gx_exp, Gy_exp : unsigned (9 downto 0)         := (others => 'U');
  signal o_dat_exp      : std_logic_vector (7 downto 0) := (others => 'U');


begin

  -- Instantiate the Unit Under Test (UUT)
  uut : processing_unit
    port map (enable  => enable_sig,
              din_0   => din_0_sig,
              din_1   => din_1_sig,
              din_2   => din_2_sig,
              o_data  => o_data_sig,
              o_wr_en => o_wr_en_sig,
              rst     => reset,
              bus_clk => clk,
              GPIO    => GPIO,
              p_data  => prof_data,
              p_wr_en => prof_wren,
              p_full  => prof_full
              );

  -- generate a clock with 100 ns period
  clkg : process
  begin
    wait for 50 ns;
    clk <= not clk;
  end process clkg;

  -- generate some testpatterns 
  tb : process
  begin
    prof_full  <= '0';
    din_0_sig  <= X"00";
    din_1_sig  <= X"00";
    din_2_sig  <= X"00";
    GPIO       <= "00000111";
    enable_sig <= '0';

    wait for 200 ns;

    -- we reset the fsm
    reset <= '1';
    wait for 100 ns;
    reset <= '0';

    -- no we enable the unit
    enable_sig <= '1';

    -- have to wait until the processing unit is
    -- really outputting calculated values from the sobel
    -- filter (it waits 
    enable_sig <= '1';

    -- for i in 1 to (2*FRAME_WIDTH+2) loop
    wait for (2*FRAME_WIDTH+2) * 100 ns;

    din_0_sig  <= X"33";
    din_1_sig  <= X"40";
    din_2_sig  <= X"43";
    wait for 100 ns;
    din_0_sig  <= X"F5";
    din_1_sig  <= X"9B";
    din_2_sig  <= X"59";
    wait for 100 ns;
    din_0_sig  <= X"C0";
    din_1_sig  <= X"C6";
    din_2_sig  <= X"B2";
    wait for 100 ns;
    din_0_sig  <= X"02";
    din_1_sig  <= X"0D";
    din_2_sig  <= X"A0";
    wait for 100 ns;
    din_0_sig  <= X"D4";
    din_1_sig  <= X"DC";
    din_2_sig  <= X"22";
    wait for 100 ns;
    din_0_sig  <= X"41";
    din_1_sig  <= X"FC";
    din_2_sig  <= X"FF";
    wait for 100 ns;
    din_0_sig  <= X"DB";
    din_1_sig  <= X"39";
    din_2_sig  <= X"4E";
    wait for 100 ns;
    din_0_sig  <= X"85";
    din_1_sig  <= X"43";
    din_2_sig  <= X"7D";
    wait for 100 ns;
    din_0_sig  <= X"81";
    din_1_sig  <= X"57";
    din_2_sig  <= X"29";
    wait for 100 ns;
    din_0_sig  <= X"A4";
    din_1_sig  <= X"C5";
    din_2_sig  <= X"73";
    wait for 100 ns;
    enable_sig <= '1';
    wait for 300 ns;

    wait;                               -- will wait forever
  end process tb;

  gxy_exp : process
  begin
    wait for 350 ns;
    Gx_exp <= (others => '0');
    Gy_exp <= (others => '0');
    wait for ((2*FRAME_WIDTH+3)*100 ns);
    Gx_exp <= B"00" & X"1e";
    Gy_exp <= B"00" & X"02";
    wait for 100 ns;
    Gx_exp <= B"00" & X"50";
    Gy_exp <= B"00" & X"0f";
    wait for 100 ns;
    Gx_exp <= B"00" & X"41";
    Gy_exp <= B"00" & X"26";
    wait for 100 ns;
    Gx_exp <= B"00" & X"39";
    Gy_exp <= B"00" & X"03";
    wait for 100 ns;
    Gx_exp <= B"00" & X"0a";
    Gy_exp <= B"00" & X"0f";
    wait for 100 ns;
    Gx_exp <= B"00" & X"4f";
    Gy_exp <= B"00" & X"01";
    wait for 100 ns;
    Gx_exp <= B"00" & X"22";
    Gy_exp <= B"00" & X"07";
    wait for 100 ns;
    Gx_exp <= B"00" & X"36";
    Gy_exp <= B"00" & X"0c";
    wait for 100 ns;
    Gx_exp <= B"00" & X"08";
    Gy_exp <= B"00" & X"1e";
    wait for 100 ns;
    Gx_exp <= B"00" & X"23";
    Gy_exp <= B"00" & X"1d";
    wait for 100 ns;
    Gx_exp <= B"00" & X"29";
    Gy_exp <= B"00" & X"1d";
    wait for 100 ns;
    Gx_exp <= B"00" & X"00";
    Gy_exp <= B"00" & X"18";
    wait;                               -- wait forever
  end process gxy_exp;

  od_exp : process
  begin
    wait for 250 ns;
    o_dat_exp <= X"00";
    wait for 500 ns;
    o_dat_exp <= X"80";
    wait for (2*FRAME_WIDTH+2) * 100 ns;
    o_dat_exp <= X"ff";
    wait for 200 ns;
    o_dat_exp <= X"00";
    wait for 100 ns;
    o_dat_exp <= X"ff";
    wait for 600 ns;
    o_dat_exp <= X"00";
    wait;                               -- wait forever
  end process od_exp;

end behavioral;
