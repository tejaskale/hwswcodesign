module xillybus_lite #(
  parameter C_S_AXI_DATA_WIDTH = 32,
  parameter C_S_AXI_ADDR_WIDTH = 32
)
(
  input S_AXI_ACLK,
  input S_AXI_ARESETN,
  input [(C_S_AXI_ADDR_WIDTH-1):0] S_AXI_ARADDR,
  input S_AXI_ARVALID, 
  input [(C_S_AXI_ADDR_WIDTH-1):0] S_AXI_AWADDR,
  input S_AXI_AWVALID,
  input	S_AXI_BREADY,
  input S_AXI_RREADY,
  input [(C_S_AXI_DATA_WIDTH-1):0] S_AXI_WDATA,
  input [(C_S_AXI_DATA_WIDTH/8)-1:0] S_AXI_WSTRB,
  input S_AXI_WVALID,
  input user_irq,
  input [31:0] user_rd_data,
  output S_AXI_ARREADY,
  output S_AXI_AWREADY,
  output [1:0] S_AXI_BRESP,
  output S_AXI_BVALID,
  output [(C_S_AXI_DATA_WIDTH-1):0] S_AXI_RDATA,
  output [1:0] S_AXI_RRESP,
  output S_AXI_RVALID,
  output S_AXI_WREADY,
  output user_clk,
  output user_wren,
  output user_rden,
  output [3:0] user_wstrb,
  output [31:0] user_wr_data,
  output [31:0] user_addr,
  output host_interrupt
);
endmodule // xillybus_lite
