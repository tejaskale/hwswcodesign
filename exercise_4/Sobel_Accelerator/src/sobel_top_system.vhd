
library ieee;
use ieee.std_logic_1164.all;

-------------------------------------------------------------------------------

entity sobel_top_system is
  port(bus_clk       : in  std_logic;
       reset_8       : in  std_logic;
       image_in      : in  std_logic_vector(7 downto 0);
       i_wr_en       : in  std_logic;
       i_full        : out std_logic;
       o_rd_en       : in  std_logic;
       image_out     : out std_logic_vector(7 downto 0);
       o_empty       : out std_logic;
       GPIO          : in  std_logic_vector (7 downto 0);
       reset_32      : in  std_logic;
       p_empty       : out std_logic;
       profiling_out : out std_logic_vector(31 downto 0);
       p_rd_en       : in  std_logic := '0'
       ); 
end sobel_top_system;

-------------------------------------------------------------------------------
architecture arch of sobel_top_system is

  component fifo_8x2048
    port(
      clk   : in  std_logic;
      srst  : in  std_logic;
      din   : in  std_logic_vector(7 downto 0);
      wr_en : in  std_logic;
      rd_en : in  std_logic;
      dout  : out std_logic_vector(7 downto 0);
      full  : out std_logic;
      empty : out std_logic
      );
  end component;

  component fifo_32x512
    port(
      clk   : in  std_logic;
      srst  : in  std_logic;
      din   : in  std_logic_vector(31 downto 0);
      wr_en : in  std_logic;
      rd_en : in  std_logic;
      dout  : out std_logic_vector(31 downto 0);
      full  : out std_logic;
      empty : out std_logic
      );
  end component;

  component shift_ram
    port (
      clk : in  std_logic;
      ce  : in  std_logic;
      d   : in  std_logic_vector(7 downto 0);
      q   : out std_logic_vector(7 downto 0)
      );
  end component;

  component pipe_control_logic
    port (i_empty : in  std_logic;
          o_full  : in  std_logic;
          enable  : out std_logic
          );
  end component;

  component processing_unit
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



  attribute syn_black_box                : boolean;
  attribute syn_black_box of fifo_8x2048 : component is true;
  attribute syn_black_box of shift_ram   : component is true;
  attribute syn_black_box of fifo_32x512 : component is true;

  signal enable_sig  : std_logic;
  signal o_data_sig  : std_logic_vector(7 downto 0);
  signal o_wr_en_sig : std_logic;
  signal o_full_sig  : std_logic;
  signal i_empty_sig : std_logic;
  signal din_0_sig   : std_logic_vector(7 downto 0);
  signal din_1_sig   : std_logic_vector(7 downto 0);
  signal din_2_sig   : std_logic_vector(7 downto 0);
  signal p_data_sig  : std_logic_vector (31 downto 0);
  signal p_wr_en_sig : std_logic;
  signal p_full_sig  : std_logic;

begin

  pipe_control : pipe_control_logic
    port map (i_empty => i_empty_sig,
              o_full  => o_full_sig,
              enable  => enable_sig
              ); 

  fifo_8_in : fifo_8x2048
    port map(
      clk   => bus_clk,
      srst  => reset_8,
      din   => image_in,
      wr_en => i_wr_en,
      rd_en => enable_sig,
      dout  => din_2_sig,
      full  => i_full,
      empty => i_empty_sig
      );

  fifo_8_out : fifo_8x2048
    port map(
      clk   => bus_clk,
      srst  => reset_8,
      din   => o_data_sig,
      wr_en => o_wr_en_sig,
      rd_en => o_rd_en,
      dout  => image_out,
      full  => o_full_sig,
      empty => o_empty
      );

  fifo_32 : fifo_32x512
    port map(
      clk   => bus_clk,
      srst  => reset_32,
      din   => p_data_sig,
      wr_en => p_wr_en_sig,
      rd_en => p_rd_en,
      dout  => profiling_out,
      full  => p_full_sig,
      empty => p_empty
      );

  shift1 : shift_ram
    port map(
      clk => bus_clk,
      ce  => enable_sig,
      d   => din_2_sig,
      q   => din_1_sig
      );

  shift0 : shift_ram
    port map(
      clk => bus_clk,
      ce  => enable_sig,
      d   => din_1_sig,
      q   => din_0_sig
      );

  proc : processing_unit
    port map (enable  => enable_sig,
              din_0   => din_0_sig,
              din_1   => din_1_sig,
              din_2   => din_2_sig,
              o_data  => o_data_sig,
              o_wr_en => o_wr_en_sig,
              rst     => reset_8,
              bus_clk => bus_clk,
              GPIO    => GPIO,
              p_data  => p_data_sig,
              p_wr_en => p_wr_en_sig,
              p_full  => p_full_sig
              );

end arch;
