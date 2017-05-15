library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

-------------------------------------------------------------------------------

entity top_system is
  port (
    clk_100     : in    std_logic;
    otg_oc      : in    std_logic;
    PS_GPIO     : inout std_logic_vector(55 downto 0);
    GPIO_LED    : out   std_logic_vector(3 downto 0);
    vga4_blue   : out   std_logic_vector(3 downto 0);
    vga4_green  : out   std_logic_vector(3 downto 0);
    vga4_red    : out   std_logic_vector(3 downto 0);
    vga_hsync   : out   std_logic;
    vga_vsync   : out   std_logic;
    audio_mclk  : out   std_logic;
    audio_dac   : out   std_logic;
    audio_adc   : in    std_logic;
    audio_bclk  : in    std_logic;
    audio_lrclk : in    std_logic;
    smb_sclk    : out   std_logic;
    smb_sdata   : inout std_logic;
    smbus_addr  : out   std_logic_vector(1 downto 0));
end top_system;

-------------------------------------------------------------------------------

architecture top_system_arch of top_system is
  component xillybus
    port (
      PS_CLK                 : in    std_logic;
      PS_PORB                : in    std_logic;
      PS_SRSTB               : in    std_logic;
      clk_100                : in    std_logic;
      otg_oc                 : in    std_logic;
      DDR_Addr               : inout std_logic_vector(14 downto 0);
      DDR_BankAddr           : inout std_logic_vector(2 downto 0);
      DDR_CAS_n              : inout std_logic;
      DDR_CKE                : inout std_logic;
      DDR_CS_n               : inout std_logic;
      DDR_Clk                : inout std_logic;
      DDR_Clk_n              : inout std_logic;
      DDR_DM                 : inout std_logic_vector(3 downto 0);
      DDR_DQ                 : inout std_logic_vector(31 downto 0);
      DDR_DQS                : inout std_logic_vector(3 downto 0);
      DDR_DQS_n              : inout std_logic_vector(3 downto 0);
      DDR_DRSTB              : inout std_logic;
      DDR_ODT                : inout std_logic;
      DDR_RAS_n              : inout std_logic;
      DDR_VRN                : inout std_logic;
      DDR_VRP                : inout std_logic;
      MIO                    : inout std_logic_vector(53 downto 0);
      PS_GPIO                : inout std_logic_vector(55 downto 0);
      DDR_WEB                : out   std_logic;
      GPIO_LED               : out   std_logic_vector(3 downto 0);
      bus_clk                : out   std_logic;
      quiesce                : out   std_logic;
      vga4_blue              : out   std_logic_vector(3 downto 0);
      vga4_green             : out   std_logic_vector(3 downto 0);
      vga4_red               : out   std_logic_vector(3 downto 0);
      vga_hsync              : out   std_logic;
      vga_vsync              : out   std_logic;
      user_r_mem_8_rden      : out   std_logic;
      user_r_mem_8_empty     : in    std_logic;
      user_r_mem_8_data      : in    std_logic_vector(7 downto 0);
      user_r_mem_8_eof       : in    std_logic;
      user_r_mem_8_open      : out   std_logic;
      user_w_mem_8_wren      : out   std_logic;
      user_w_mem_8_full      : in    std_logic;
      user_w_mem_8_data      : out   std_logic_vector(7 downto 0);
      user_w_mem_8_open      : out   std_logic;
      user_mem_8_addr        : out   std_logic_vector(4 downto 0);
      user_mem_8_addr_update : out   std_logic;
      user_r_read_32_rden    : out   std_logic;
      user_r_read_32_empty   : in    std_logic;
      user_r_read_32_data    : in    std_logic_vector(31 downto 0);
      user_r_read_32_eof     : in    std_logic;
      user_r_read_32_open    : out   std_logic;
      user_r_read_8_rden     : out   std_logic;
      user_r_read_8_empty    : in    std_logic;
      user_r_read_8_data     : in    std_logic_vector(7 downto 0);
      user_r_read_8_eof      : in    std_logic;
      user_r_read_8_open     : out   std_logic;
      user_w_write_32_wren   : out   std_logic;
      user_w_write_32_full   : in    std_logic;
      user_w_write_32_data   : out   std_logic_vector(31 downto 0);
      user_w_write_32_open   : out   std_logic;
      user_w_write_8_wren    : out   std_logic;
      user_w_write_8_full    : in    std_logic;
      user_w_write_8_data    : out   std_logic_vector(7 downto 0);
      user_w_write_8_open    : out   std_logic;
      user_r_audio_rden      : out   std_logic;
      user_r_audio_empty     : in    std_logic;
      user_r_audio_data      : in    std_logic_vector(31 downto 0);
      user_r_audio_eof       : in    std_logic;
      user_r_audio_open      : out   std_logic;
      user_w_audio_wren      : out   std_logic;
      user_w_audio_full      : in    std_logic;
      user_w_audio_data      : out   std_logic_vector(31 downto 0);
      user_w_audio_open      : out   std_logic;
      user_r_smb_rden        : out   std_logic;
      user_r_smb_empty       : in    std_logic;
      user_r_smb_data        : in    std_logic_vector(7 downto 0);
      user_r_smb_eof         : in    std_logic;
      user_r_smb_open        : out   std_logic;
      user_w_smb_wren        : out   std_logic;
      user_w_smb_full        : in    std_logic;
      user_w_smb_data        : out   std_logic_vector(7 downto 0);
      user_w_smb_open        : out   std_logic;
      user_clk               : out   std_logic;
      user_wren              : out   std_logic;
      user_wstrb             : out   std_logic_vector(3 downto 0);
      user_rden              : out   std_logic;
      user_rd_data           : in    std_logic_vector(31 downto 0);
      user_wr_data           : out   std_logic_vector(31 downto 0);
      user_addr              : out   std_logic_vector(31 downto 0);
      user_irq               : in    std_logic);
  end component;

  component sobel_top_system is
    port (bus_clk       : in  std_logic;
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
          p_rd_en       : in  std_logic
          );
  end component;


  component i2s_audio
    port (
      bus_clk            : in  std_logic;
      clk_100            : in  std_logic;
      quiesce            : in  std_logic;
      audio_mclk         : out std_logic;
      audio_dac          : out std_logic;
      audio_adc          : in  std_logic;
      audio_bclk         : in  std_logic;
      audio_lrclk        : in  std_logic;
      user_r_audio_rden  : in  std_logic;
      user_r_audio_empty : out std_logic;
      user_r_audio_data  : out std_logic_vector(31 downto 0);
      user_r_audio_eof   : out std_logic;
      user_r_audio_open  : in  std_logic;
      user_w_audio_wren  : in  std_logic;
      user_w_audio_full  : out std_logic;
      user_w_audio_data  : in  std_logic_vector(31 downto 0);
      user_w_audio_open  : in  std_logic);
  end component;

  component smbus
    port (
      bus_clk          : in    std_logic;
      quiesce          : in    std_logic;
      smb_sclk         : out   std_logic;
      smb_sdata        : inout std_logic;
      smbus_addr       : out   std_logic_vector(1 downto 0);
      user_r_smb_rden  : in    std_logic;
      user_r_smb_empty : out   std_logic;
      user_r_smb_data  : out   std_logic_vector(7 downto 0);
      user_r_smb_eof   : out   std_logic;
      user_r_smb_open  : in    std_logic;
      user_w_smb_wren  : in    std_logic;
      user_w_smb_full  : out   std_logic;
      user_w_smb_data  : in    std_logic_vector(7 downto 0);
      user_w_smb_open  : in    std_logic);
  end component;


  type demo_mem is array(0 to 31) of std_logic_vector(7 downto 0);
  signal demoarray  : demo_mem;
  signal litearray0 : demo_mem;
  signal litearray1 : demo_mem;
  signal litearray2 : demo_mem;
  signal litearray3 : demo_mem;

  signal bus_clk : std_logic;
  signal quiesce : std_logic;

  signal reset_8  : std_logic;
  signal reset_32 : std_logic;

  signal ram_addr  : integer range 0 to 31;
  signal lite_addr : integer range 0 to 31;

  signal user_r_mem_8_rden      : std_logic;
  signal user_r_mem_8_empty     : std_logic;
  signal user_r_mem_8_data      : std_logic_vector(7 downto 0);
  signal user_r_mem_8_eof       : std_logic;
  signal user_r_mem_8_open      : std_logic;
  signal user_w_mem_8_wren      : std_logic;
  signal user_w_mem_8_full      : std_logic;
  signal user_w_mem_8_data      : std_logic_vector(7 downto 0);
  signal user_w_mem_8_open      : std_logic;
  signal user_mem_8_addr        : std_logic_vector(4 downto 0);
  signal user_mem_8_addr_update : std_logic;
  signal user_r_read_32_rden    : std_logic;
  signal user_r_read_32_empty   : std_logic;
  signal user_r_read_32_data    : std_logic_vector(31 downto 0);
  signal user_r_read_32_eof     : std_logic;
  signal user_r_read_32_open    : std_logic;
  signal user_r_read_8_rden     : std_logic;
  signal user_r_read_8_empty    : std_logic;
  signal user_r_read_8_data     : std_logic_vector(7 downto 0);
  signal user_r_read_8_eof      : std_logic;
  signal user_r_read_8_open     : std_logic;
  signal user_w_write_32_wren   : std_logic;
  signal user_w_write_32_full   : std_logic;
  signal user_w_write_32_data   : std_logic_vector(31 downto 0);
  signal user_w_write_32_open   : std_logic;
  signal user_w_write_8_wren    : std_logic;
  signal user_w_write_8_full    : std_logic;
  signal user_w_write_8_data    : std_logic_vector(7 downto 0);
  signal user_w_write_8_open    : std_logic;
  signal user_r_audio_rden      : std_logic;
  signal user_r_audio_empty     : std_logic;
  signal user_r_audio_data      : std_logic_vector(31 downto 0);
  signal user_r_audio_eof       : std_logic;
  signal user_r_audio_open      : std_logic;
  signal user_w_audio_wren      : std_logic;
  signal user_w_audio_full      : std_logic;
  signal user_w_audio_data      : std_logic_vector(31 downto 0);
  signal user_w_audio_open      : std_logic;
  signal user_r_smb_rden        : std_logic;
  signal user_r_smb_empty       : std_logic;
  signal user_r_smb_data        : std_logic_vector(7 downto 0);
  signal user_r_smb_eof         : std_logic;
  signal user_r_smb_open        : std_logic;
  signal user_w_smb_wren        : std_logic;
  signal user_w_smb_full        : std_logic;
  signal user_w_smb_data        : std_logic_vector(7 downto 0);
  signal user_w_smb_open        : std_logic;
  signal user_clk               : std_logic;
  signal user_wren              : std_logic;
  signal user_wstrb             : std_logic_vector(3 downto 0);
  signal user_rden              : std_logic;
  signal user_rd_data           : std_logic_vector(31 downto 0);
  signal user_wr_data           : std_logic_vector(31 downto 0);
  signal user_addr              : std_logic_vector(31 downto 0);
  signal user_irq               : std_logic;

  -----------------------------
  -- Note that none of the ARM processor's direct connections to pads is
  -- defined as I/O on this module. Normally, they should be connected
  -- as toplevel ports here, but that confuses Vivado 2013.4 to think that
  -- some of these ports are real I/Os, causing an implementation failure.
  -- This detachment results in a lot of warnings during synthesis and
  -- implementation, but has no practical significance, as these pads are
  -- completely unrelated to the FPGA bitstream.

  signal PS_CLK       : std_logic;
  signal PS_PORB      : std_logic;
  signal PS_SRSTB     : std_logic;
  signal DDR_Addr     : std_logic_vector(14 downto 0);
  signal DDR_BankAddr : std_logic_vector(2 downto 0);
  signal DDR_CAS_n    : std_logic;
  signal DDR_CKE      : std_logic;
  signal DDR_CS_n     : std_logic;
  signal DDR_Clk      : std_logic;
  signal DDR_Clk_n    : std_logic;
  signal DDR_DM       : std_logic_vector(3 downto 0);
  signal DDR_DQ       : std_logic_vector(31 downto 0);
  signal DDR_DQS      : std_logic_vector(3 downto 0);
  signal DDR_DQS_n    : std_logic_vector(3 downto 0);
  signal DDR_DRSTB    : std_logic;
  signal DDR_ODT      : std_logic;
  signal DDR_RAS_n    : std_logic;
  signal DDR_VRN      : std_logic;
  signal DDR_VRP      : std_logic;
  signal MIO          : std_logic_vector(53 downto 0);
  signal DDR_WEB      : std_logic;
  
begin
  
  xillybus_ins : xillybus
    port map (
      -- Ports related to /dev/xillybus_mem_8
      -- FPGA to CPU signals:
      user_r_mem_8_rden      => user_r_mem_8_rden,
      user_r_mem_8_empty     => user_r_mem_8_empty,
      user_r_mem_8_data      => user_r_mem_8_data,
      user_r_mem_8_eof       => user_r_mem_8_eof,
      user_r_mem_8_open      => user_r_mem_8_open,
      -- CPU to FPGA signals:
      user_w_mem_8_wren      => user_w_mem_8_wren,
      user_w_mem_8_full      => user_w_mem_8_full,
      user_w_mem_8_data      => user_w_mem_8_data,
      user_w_mem_8_open      => user_w_mem_8_open,
      -- Address signals:
      user_mem_8_addr        => user_mem_8_addr,
      user_mem_8_addr_update => user_mem_8_addr_update,

      -- Ports related to /dev/xillybus_read_32
      -- FPGA to CPU signals:
      user_r_read_32_rden  => user_r_read_32_rden,
      user_r_read_32_empty => user_r_read_32_empty,
      user_r_read_32_data  => user_r_read_32_data,
      user_r_read_32_eof   => user_r_read_32_eof,
      user_r_read_32_open  => user_r_read_32_open,

      -- Ports related to /dev/xillybus_read_8
      -- FPGA to CPU signals:
      user_r_read_8_rden  => user_r_read_8_rden,
      user_r_read_8_empty => user_r_read_8_empty,
      user_r_read_8_data  => user_r_read_8_data,
      user_r_read_8_eof   => user_r_read_8_eof,
      user_r_read_8_open  => user_r_read_8_open,

      -- Ports related to /dev/xillybus_write_32
      -- CPU to FPGA signals:
      user_w_write_32_wren => user_w_write_32_wren,
      user_w_write_32_full => user_w_write_32_full,
      user_w_write_32_data => user_w_write_32_data,
      user_w_write_32_open => user_w_write_32_open,

      -- Ports related to /dev/xillybus_write_8
      -- CPU to FPGA signals:
      user_w_write_8_wren => user_w_write_8_wren,
      user_w_write_8_full => user_w_write_8_full,
      user_w_write_8_data => user_w_write_8_data,
      user_w_write_8_open => user_w_write_8_open,

      -- Ports related to Xillybus Lite
      user_clk     => user_clk,
      user_wren    => user_wren,
      user_wstrb   => user_wstrb,
      user_rden    => user_rden,
      user_rd_data => user_rd_data,
      user_wr_data => user_wr_data,
      user_addr    => user_addr,
      user_irq     => user_irq,

      -- Ports related to /dev/xillybus_audio
      -- FPGA to CPU signals:
      user_r_audio_rden  => user_r_audio_rden,
      user_r_audio_empty => user_r_audio_empty,
      user_r_audio_data  => user_r_audio_data,
      user_r_audio_eof   => user_r_audio_eof,
      user_r_audio_open  => user_r_audio_open,
      -- CPU to FPGA signals:
      user_w_audio_wren  => user_w_audio_wren,
      user_w_audio_full  => user_w_audio_full,
      user_w_audio_data  => user_w_audio_data,
      user_w_audio_open  => user_w_audio_open,

      -- Ports related to /dev/xillybus_smb
      -- FPGA to CPU signals:
      user_r_smb_rden  => user_r_smb_rden,
      user_r_smb_empty => user_r_smb_empty,
      user_r_smb_data  => user_r_smb_data,
      user_r_smb_eof   => user_r_smb_eof,
      user_r_smb_open  => user_r_smb_open,
      -- CPU to FPGA signals:
      user_w_smb_wren  => user_w_smb_wren,
      user_w_smb_full  => user_w_smb_full,
      user_w_smb_data  => user_w_smb_data,
      user_w_smb_open  => user_w_smb_open,

      -- General signals
      PS_CLK       => PS_CLK,
      PS_PORB      => PS_PORB,
      PS_SRSTB     => PS_SRSTB,
      clk_100      => clk_100,
      otg_oc       => otg_oc,
      DDR_Addr     => DDR_Addr,
      DDR_BankAddr => DDR_BankAddr,
      DDR_CAS_n    => DDR_CAS_n,
      DDR_CKE      => DDR_CKE,
      DDR_CS_n     => DDR_CS_n,
      DDR_Clk      => DDR_Clk,
      DDR_Clk_n    => DDR_Clk_n,
      DDR_DM       => DDR_DM,
      DDR_DQ       => DDR_DQ,
      DDR_DQS      => DDR_DQS,
      DDR_DQS_n    => DDR_DQS_n,
      DDR_DRSTB    => DDR_DRSTB,
      DDR_ODT      => DDR_ODT,
      DDR_RAS_n    => DDR_RAS_n,
      DDR_VRN      => DDR_VRN,
      DDR_VRP      => DDR_VRP,
      MIO          => MIO,
      PS_GPIO      => PS_GPIO,
      DDR_WEB      => DDR_WEB,
      GPIO_LED     => GPIO_LED,
      bus_clk      => bus_clk,
      quiesce      => quiesce,
      vga4_blue    => vga4_blue,
      vga4_green   => vga4_green,
      vga4_red     => vga4_red,
      vga_hsync    => vga_hsync,
      vga_vsync    => vga_vsync
      );

  -- Xillybus Lite
  
  user_irq <= '0';                      -- No interrupts for now

  lite_addr <= conv_integer(user_addr(6 downto 2));

  process (user_clk)
  begin
    if (user_clk'event and user_clk = '1') then
      if (user_wstrb(0) = '1') then
        litearray0(lite_addr) <= user_wr_data(7 downto 0);
      end if;

      if (user_wstrb(1) = '1') then
        litearray1(lite_addr) <= user_wr_data(15 downto 8);
      end if;

      if (user_wstrb(2) = '1') then
        litearray2(lite_addr) <= user_wr_data(23 downto 16);
      end if;

      if (user_wstrb(3) = '1') then
        litearray3(lite_addr) <= user_wr_data(31 downto 24);
      end if;

      if (user_rden = '1') then
        user_rd_data <= litearray3(lite_addr) & litearray2(lite_addr) &
                        litearray1(lite_addr) & litearray0(lite_addr);
      end if;
    end if;
  end process;

--  A simple inferred RAM

  ram_addr <= conv_integer(user_mem_8_addr);

  process (bus_clk)
  begin
    if (bus_clk'event and bus_clk = '1') then
      if (user_w_mem_8_wren = '1') then
        demoarray(ram_addr) <= user_w_mem_8_data;
      end if;
      if (user_r_mem_8_rden = '1') then
        user_r_mem_8_data <= demoarray(ram_addr);
      end if;
    end if;
  end process;

  user_r_mem_8_empty <= '0';
  user_r_mem_8_eof   <= '0';
  user_w_mem_8_full  <= '0';


  reset_32 <= not (user_w_write_32_open or user_r_read_32_open);

  user_r_read_32_eof <= '0';

  reset_8 <= not (user_w_write_8_open or user_r_read_8_open);

  user_r_read_8_eof <= '0';

  audio_ins : i2s_audio
    port map(
      bus_clk            => bus_clk,
      clk_100            => clk_100,
      quiesce            => quiesce,
      audio_mclk         => audio_mclk,
      audio_dac          => audio_dac,
      audio_adc          => audio_adc,
      audio_bclk         => audio_bclk,
      audio_lrclk        => audio_lrclk,
      user_r_audio_rden  => user_r_audio_rden,
      user_r_audio_empty => user_r_audio_empty,
      user_r_audio_data  => user_r_audio_data,
      user_r_audio_eof   => user_r_audio_eof,
      user_r_audio_open  => user_r_audio_open,
      user_w_audio_wren  => user_w_audio_wren,
      user_w_audio_full  => user_w_audio_full,
      user_w_audio_data  => user_w_audio_data,
      user_w_audio_open  => user_w_audio_open
      );

  smbus_ins : smbus
    port map(
      bus_clk          => bus_clk,
      quiesce          => quiesce,
      smb_sclk         => smb_sclk,
      smb_sdata        => smb_sdata,
      smbus_addr       => smbus_addr,
      user_r_smb_rden  => user_r_smb_rden,
      user_r_smb_empty => user_r_smb_empty,
      user_r_smb_data  => user_r_smb_data,
      user_r_smb_eof   => user_r_smb_eof,
      user_r_smb_open  => user_r_smb_open,
      user_w_smb_wren  => user_w_smb_wren,
      user_w_smb_full  => user_w_smb_full,
      user_w_smb_data  => user_w_smb_data,
      user_w_smb_open  => user_w_smb_open
      );

  sobel_ins : sobel_top_system
    port map(bus_clk          => bus_clk,
             reset_8          => reset_8,
             image_in         => user_w_write_8_data,
             i_wr_en          => user_w_write_8_wren,
             i_full           => user_w_write_8_full,
             o_rd_en          => user_r_read_8_rden,
             image_out        => user_r_read_8_data,
             o_empty          => user_r_read_8_empty,
             GPIO(6 downto 0) => PS_GPIO(17 downto 11),
             GPIO(7)          => PS_GPIO(23),
             reset_32         => reset_32,
             p_empty          => user_r_read_32_empty,
             profiling_out    => user_r_read_32_data,
             p_rd_en          => user_r_read_32_rden
             );

end top_system_arch;
