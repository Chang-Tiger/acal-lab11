module DMA(
  input         clock,
  input         reset,
  output        io_slave_aw_ready,
  input         io_slave_aw_valid,
  input  [3:0]  io_slave_aw_bits_id,
  input  [31:0] io_slave_aw_bits_addr,
  input  [3:0]  io_slave_aw_bits_region,
  input  [7:0]  io_slave_aw_bits_len,
  input  [1:0]  io_slave_aw_bits_size,
  input  [1:0]  io_slave_aw_bits_burst,
  input         io_slave_aw_bits_lock,
  input  [3:0]  io_slave_aw_bits_cache,
  input  [2:0]  io_slave_aw_bits_prot,
  input  [3:0]  io_slave_aw_bits_qos,
  output        io_slave_w_ready,
  input         io_slave_w_valid,
  input  [31:0] io_slave_w_bits_data,
  input  [3:0]  io_slave_w_bits_strb,
  input         io_slave_w_bits_last,
  input         io_slave_b_ready,
  output        io_slave_b_valid,
  output [3:0]  io_slave_b_bits_id,
  output [1:0]  io_slave_b_bits_resp,
  output        io_slave_ar_ready,
  input         io_slave_ar_valid,
  input  [3:0]  io_slave_ar_bits_id,
  input  [31:0] io_slave_ar_bits_addr,
  input  [3:0]  io_slave_ar_bits_region,
  input  [7:0]  io_slave_ar_bits_len,
  input  [1:0]  io_slave_ar_bits_size,
  input  [1:0]  io_slave_ar_bits_burst,
  input         io_slave_ar_bits_lock,
  input  [3:0]  io_slave_ar_bits_cache,
  input  [2:0]  io_slave_ar_bits_prot,
  input  [3:0]  io_slave_ar_bits_qos,
  input         io_slave_r_ready,
  output        io_slave_r_valid,
  output [3:0]  io_slave_r_bits_id,
  output [31:0] io_slave_r_bits_data,
  output [1:0]  io_slave_r_bits_resp,
  output        io_slave_r_bits_last,
  input         io_master_aw_ready,
  output        io_master_aw_valid,
  output [3:0]  io_master_aw_bits_id,
  output [31:0] io_master_aw_bits_addr,
  output [3:0]  io_master_aw_bits_region,
  output [7:0]  io_master_aw_bits_len,
  output [1:0]  io_master_aw_bits_size,
  output [1:0]  io_master_aw_bits_burst,
  output        io_master_aw_bits_lock,
  output [3:0]  io_master_aw_bits_cache,
  output [2:0]  io_master_aw_bits_prot,
  output [3:0]  io_master_aw_bits_qos,
  input         io_master_w_ready,
  output        io_master_w_valid,
  output [31:0] io_master_w_bits_data,
  output [3:0]  io_master_w_bits_strb,
  output        io_master_w_bits_last,
  output        io_master_b_ready,
  input         io_master_b_valid,
  input  [3:0]  io_master_b_bits_id,
  input  [1:0]  io_master_b_bits_resp,
  input         io_master_ar_ready,
  output        io_master_ar_valid,
  output [3:0]  io_master_ar_bits_id,
  output [31:0] io_master_ar_bits_addr,
  output [3:0]  io_master_ar_bits_region,
  output [7:0]  io_master_ar_bits_len,
  output [1:0]  io_master_ar_bits_size,
  output [1:0]  io_master_ar_bits_burst,
  output        io_master_ar_bits_lock,
  output [3:0]  io_master_ar_bits_cache,
  output [2:0]  io_master_ar_bits_prot,
  output [3:0]  io_master_ar_bits_qos,
  output        io_master_r_ready,
  input         io_master_r_valid,
  input  [3:0]  io_master_r_bits_id,
  input  [31:0] io_master_r_bits_data,
  input  [1:0]  io_master_r_bits_resp,
  input         io_master_r_bits_last,
  output        io_Hcf
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
`endif // RANDOMIZE_REG_INIT
  reg [2:0] mState; // @[DMA.scala 17:24]
  reg  sReadState; // @[DMA.scala 23:28]
  reg [1:0] sWriteState; // @[DMA.scala 24:28]
  reg [31:0] sReadAddrReg; // @[DMA.scala 26:33]
  reg [3:0] sReadIDReg; // @[DMA.scala 27:33]
  reg [3:0] sWriteIDReg; // @[DMA.scala 28:33]
  reg  sWriteDataRecv; // @[DMA.scala 29:33]
  reg  sWriteAddrRecv; // @[DMA.scala 30:33]
  reg [31:0] sWriteDataReg; // @[DMA.scala 31:33]
  reg [31:0] sWriteAddrReg; // @[DMA.scala 32:33]
  wire [31:0] sWriteAddrOffset = sWriteAddrReg - 32'h0; // @[DMA.scala 33:52]
  wire [31:0] sReadAddrOffset = sReadAddrReg - 32'h0; // @[DMA.scala 34:51]
  reg  mWriteAddrSent; // @[DMA.scala 36:31]
  reg  mWriteDataSent; // @[DMA.scala 37:31]
  reg  mReadlast; // @[DMA.scala 38:26]
  reg [31:0] mmio_regs_0; // @[DMA.scala 40:34]
  reg [31:0] mmio_regs_1; // @[DMA.scala 40:34]
  reg [31:0] mmio_regs_2; // @[DMA.scala 40:34]
  reg [31:0] mmio_regs_3; // @[DMA.scala 40:34]
  reg [31:0] mmio_regs_4; // @[DMA.scala 40:34]
  reg [31:0] mmio_regs_5; // @[DMA.scala 40:34]
  reg [31:0] data_buffer; // @[DMA.scala 49:31]
  reg [1:0] source_offset; // @[DMA.scala 52:31]
  wire [1:0] dest_offset = io_master_aw_bits_addr[1:0]; // @[DMA.scala 55:55]
  reg [31:0] request_counter; // @[DMA.scala 58:32]
  wire [31:0] _sReadData_T_1 = 32'h0 == sReadAddrOffset ? mmio_regs_0 : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _sReadData_T_3 = 32'h4 == sReadAddrOffset ? mmio_regs_1 : _sReadData_T_1; // @[Mux.scala 81:58]
  wire [31:0] _sReadData_T_5 = 32'h8 == sReadAddrOffset ? mmio_regs_2 : _sReadData_T_3; // @[Mux.scala 81:58]
  wire [31:0] _sReadData_T_7 = 32'hc == sReadAddrOffset ? mmio_regs_3 : _sReadData_T_5; // @[Mux.scala 81:58]
  wire [31:0] _sReadData_T_9 = 32'h10 == sReadAddrOffset ? mmio_regs_4 : _sReadData_T_7; // @[Mux.scala 81:58]
  wire  _io_master_aw_valid_T = mState == 3'h3; // @[DMA.scala 77:38]
  wire  _io_master_ar_valid_T = mState == 3'h1; // @[DMA.scala 89:38]
  wire  _io_master_r_ready_T = mState == 3'h2; // @[DMA.scala 106:31]
  wire  _io_master_b_ready_T = mState == 3'h4; // @[DMA.scala 108:31]
  wire  _io_slave_aw_ready_T_2 = sWriteState == 2'h0 | sWriteState == 2'h1; // @[DMA.scala 110:52]
  wire  _io_slave_ar_ready_T = ~sReadState; // @[DMA.scala 113:35]
  wire  _io_slave_b_valid_T = sWriteState == 2'h2; // @[DMA.scala 121:39]
  wire [2:0] _GEN_2 = io_master_r_valid ? 3'h3 : mState; // @[DMA.scala 145:31 146:16 17:24]
  wire [2:0] _GEN_3 = mWriteAddrSent & mWriteDataSent ? 3'h4 : mState; // @[DMA.scala 151:46 152:16 17:24]
  wire [2:0] _GEN_4 = io_master_b_valid & ~mReadlast ? 3'h2 : mState; // @[DMA.scala 159:50 160:16 17:24]
  wire [2:0] _GEN_5 = io_master_b_valid & mReadlast ? 3'h0 : _GEN_4; // @[DMA.scala 157:44 158:16]
  wire [2:0] _GEN_6 = 3'h4 == mState ? _GEN_5 : mState; // @[DMA.scala 126:18 17:24]
  wire [2:0] _GEN_7 = 3'h3 == mState ? _GEN_3 : _GEN_6; // @[DMA.scala 126:18]
  wire  _GEN_11 = io_slave_ar_valid | sReadState; // @[DMA.scala 168:31 169:20 23:28]
  wire [1:0] _GEN_17 = io_slave_b_ready ? 2'h0 : sWriteState; // @[DMA.scala 191:30 192:21 24:28]
  wire  _T_18 = io_master_aw_ready & io_master_aw_valid; // @[Decoupled.scala 52:35]
  wire [31:0] _request_counter_T_1 = request_counter + 32'h1; // @[DMA.scala 201:42]
  wire [39:0] _io_master_ar_bits_addr_T_1 = request_counter * mmio_regs_3[31:24]; // @[DMA.scala 208:67]
  wire [39:0] _GEN_90 = {{8'd0}, mmio_regs_1}; // @[DMA.scala 208:48]
  wire [39:0] _io_master_ar_bits_addr_T_3 = _GEN_90 + _io_master_ar_bits_addr_T_1; // @[DMA.scala 208:48]
  wire [39:0] _GEN_24 = _io_master_ar_valid_T ? _io_master_ar_bits_addr_T_3 : 40'h0; // @[DMA.scala 205:30 208:28 90:28]
  wire [3:0] _mask_width_T_2 = 8'h1 == mmio_regs_3[15:8] ? 4'h1 : 4'hf; // @[Mux.scala 81:58]
  wire [3:0] _mask_width_T_4 = 8'h2 == mmio_regs_3[15:8] ? 4'h3 : _mask_width_T_2; // @[Mux.scala 81:58]
  wire [3:0] _mask_width_T_6 = 8'h3 == mmio_regs_3[15:8] ? 4'h7 : _mask_width_T_4; // @[Mux.scala 81:58]
  wire [3:0] _mask_width_T_8 = 8'h4 == mmio_regs_3[15:8] ? 4'hf : _mask_width_T_6; // @[Mux.scala 81:58]
  wire [3:0] _GEN_30 = _io_master_r_ready_T & io_master_r_valid ? _mask_width_T_8 : 4'h0; // @[DMA.scala 215:51 218:16]
  wire [3:0] mask_width = _io_master_aw_valid_T ? _mask_width_T_8 : _GEN_30; // @[DMA.scala 244:31 250:16]
  wire [6:0] _GEN_33 = {{3'd0}, mask_width}; // @[DMA.scala 228:30]
  wire [6:0] _rData_mask_T = _GEN_33 << source_offset; // @[DMA.scala 228:30]
  wire [6:0] _GEN_32 = _io_master_r_ready_T & io_master_r_valid ? _rData_mask_T : 7'h0; // @[DMA.scala 215:51 228:16]
  wire [3:0] rData_mask = _GEN_32[3:0];
  wire [7:0] _GEN_26 = rData_mask[0] ? io_master_r_bits_data[7:0] : 8'h0; // @[DMA.scala 232:35 233:18 236:18]
  wire [7:0] _GEN_27 = rData_mask[1] ? io_master_r_bits_data[15:8] : 8'h0; // @[DMA.scala 232:35 233:18 236:18]
  wire [7:0] _GEN_28 = rData_mask[2] ? io_master_r_bits_data[23:16] : 8'h0; // @[DMA.scala 232:35 233:18 236:18]
  wire [7:0] _GEN_29 = rData_mask[3] ? io_master_r_bits_data[31:24] : 8'h0; // @[DMA.scala 232:35 233:18 236:18]
  wire [7:0] rData_1 = _io_master_r_ready_T & io_master_r_valid ? _GEN_27 : 8'h0; // @[DMA.scala 215:51]
  wire [7:0] rData_0 = _io_master_r_ready_T & io_master_r_valid ? _GEN_26 : 8'h0; // @[DMA.scala 215:51]
  wire [7:0] rData_3 = _io_master_r_ready_T & io_master_r_valid ? _GEN_29 : 8'h0; // @[DMA.scala 215:51]
  wire [7:0] rData_2 = _io_master_r_ready_T & io_master_r_valid ? _GEN_28 : 8'h0; // @[DMA.scala 215:51]
  wire [31:0] _data_buffer_T = {rData_3,rData_2,rData_1,rData_0}; // @[DMA.scala 241:26]
  wire [4:0] _data_buffer_T_1 = {source_offset, 3'h0}; // @[DMA.scala 241:51]
  wire [31:0] _data_buffer_T_2 = _data_buffer_T >> _data_buffer_T_1; // @[DMA.scala 241:33]
  wire [39:0] _io_master_aw_bits_addr_T_1 = request_counter * mmio_regs_3[23:16]; // @[DMA.scala 247:65]
  wire [39:0] _GEN_91 = {{8'd0}, mmio_regs_2}; // @[DMA.scala 247:46]
  wire [39:0] _io_master_aw_bits_addr_T_3 = _GEN_91 + _io_master_aw_bits_addr_T_1; // @[DMA.scala 247:46]
  wire [6:0] _GEN_34 = {{3'd0}, mask_width}; // @[DMA.scala 257:41]
  wire [6:0] _io_master_w_bits_strb_T = _GEN_34 << dest_offset; // @[DMA.scala 257:41]
  wire [4:0] _io_master_w_bits_data_T = {dest_offset, 3'h0}; // @[DMA.scala 260:58]
  wire [62:0] _GEN_35 = {{31'd0}, data_buffer}; // @[DMA.scala 260:42]
  wire [62:0] _io_master_w_bits_data_T_1 = _GEN_35 << _io_master_w_bits_data_T; // @[DMA.scala 260:42]
  wire [39:0] _GEN_38 = _io_master_aw_valid_T ? _io_master_aw_bits_addr_T_3 : 40'h0; // @[DMA.scala 244:31 247:28 78:28]
  wire [6:0] _GEN_40 = _io_master_aw_valid_T ? _io_master_w_bits_strb_T : 7'hf; // @[DMA.scala 103:25 244:31 257:27]
  wire [62:0] _GEN_41 = _io_master_aw_valid_T ? _io_master_w_bits_data_T_1 : {{31'd0}, data_buffer}; // @[DMA.scala 102:25 244:31 260:27]
  wire [31:0] _GEN_92 = {{24'd0}, mmio_regs_3[7:0]}; // @[DMA.scala 265:49]
  wire [31:0] _GEN_43 = _io_master_b_ready_T & request_counter == _GEN_92 ? 32'h0 : mmio_regs_0; // @[DMA.scala 265:73 267:17 40:34]
  wire [31:0] _GEN_44 = _io_master_b_ready_T & request_counter == _GEN_92 ? 32'h1 : mmio_regs_5; // @[DMA.scala 265:73 268:17 40:34]
  wire  _GEN_45 = io_master_w_ready | mWriteDataSent; // @[DMA.scala 273:29 274:22 37:31]
  wire  _GEN_46 = io_master_aw_ready | mWriteAddrSent; // @[DMA.scala 276:30 277:22 36:31]
  wire  _GEN_47 = _io_master_aw_valid_T & _GEN_45; // @[DMA.scala 272:31 281:20]
  wire  _GEN_48 = _io_master_aw_valid_T & _GEN_46; // @[DMA.scala 272:31 280:20]
  wire  _GEN_49 = io_slave_aw_valid | sWriteAddrRecv; // @[DMA.scala 288:29 289:23 30:33]
  wire  _GEN_52 = io_slave_w_valid | sWriteDataRecv; // @[DMA.scala 301:28 302:22 29:33]
  wire [31:0] _GEN_61 = 32'h14 == sWriteAddrOffset ? sWriteDataReg : _GEN_44; // @[DMA.scala 312:30 329:22]
  wire [31:0] _GEN_62 = 32'h10 == sWriteAddrOffset ? sWriteDataReg : mmio_regs_4; // @[DMA.scala 312:30 326:22 40:34]
  wire [31:0] _GEN_63 = 32'h10 == sWriteAddrOffset ? _GEN_44 : _GEN_61; // @[DMA.scala 312:30]
  wire [31:0] _GEN_64 = 32'hc == sWriteAddrOffset ? sWriteDataReg : mmio_regs_3; // @[DMA.scala 312:30 323:22 40:34]
  wire [31:0] _GEN_65 = 32'hc == sWriteAddrOffset ? mmio_regs_4 : _GEN_62; // @[DMA.scala 312:30 40:34]
  wire [31:0] _GEN_66 = 32'hc == sWriteAddrOffset ? _GEN_44 : _GEN_63; // @[DMA.scala 312:30]
  wire [31:0] _GEN_67 = 32'h8 == sWriteAddrOffset ? sWriteDataReg : mmio_regs_2; // @[DMA.scala 312:30 320:22 40:34]
  wire [31:0] _GEN_68 = 32'h8 == sWriteAddrOffset ? mmio_regs_3 : _GEN_64; // @[DMA.scala 312:30 40:34]
  wire [31:0] _GEN_69 = 32'h8 == sWriteAddrOffset ? mmio_regs_4 : _GEN_65; // @[DMA.scala 312:30 40:34]
  wire [31:0] _GEN_70 = 32'h8 == sWriteAddrOffset ? _GEN_44 : _GEN_66; // @[DMA.scala 312:30]
  assign io_slave_aw_ready = (sWriteState == 2'h0 | sWriteState == 2'h1) & ~sWriteAddrRecv; // @[DMA.scala 110:83]
  assign io_slave_w_ready = _io_slave_aw_ready_T_2 & ~sWriteDataRecv; // @[DMA.scala 111:82]
  assign io_slave_b_valid = sWriteState == 2'h2; // @[DMA.scala 121:39]
  assign io_slave_b_bits_id = sWriteIDReg; // @[DMA.scala 122:24]
  assign io_slave_b_bits_resp = 2'h0; // @[DMA.scala 123:24]
  assign io_slave_ar_ready = ~sReadState; // @[DMA.scala 113:35]
  assign io_slave_r_valid = sReadState; // @[DMA.scala 115:38]
  assign io_slave_r_bits_id = sReadIDReg; // @[DMA.scala 117:24]
  assign io_slave_r_bits_data = 32'h14 == sReadAddrOffset ? mmio_regs_5 : _sReadData_T_9; // @[Mux.scala 81:58]
  assign io_slave_r_bits_resp = 2'h0; // @[DMA.scala 119:24]
  assign io_slave_r_bits_last = 1'h1; // @[DMA.scala 118:24]
  assign io_master_aw_valid = mState == 3'h3 & ~mWriteAddrSent; // @[DMA.scala 77:53]
  assign io_master_aw_bits_id = 4'h0; // @[DMA.scala 83:28]
  assign io_master_aw_bits_addr = _GEN_38[31:0];
  assign io_master_aw_bits_region = 4'h0; // @[DMA.scala 87:28]
  assign io_master_aw_bits_len = 8'h0; // @[DMA.scala 80:28]
  assign io_master_aw_bits_size = 2'h2; // @[DMA.scala 81:28]
  assign io_master_aw_bits_burst = 2'h0; // @[DMA.scala 79:28]
  assign io_master_aw_bits_lock = 1'h0; // @[DMA.scala 85:28]
  assign io_master_aw_bits_cache = 4'h0; // @[DMA.scala 82:28]
  assign io_master_aw_bits_prot = 3'h0; // @[DMA.scala 84:28]
  assign io_master_aw_bits_qos = 4'h0; // @[DMA.scala 86:28]
  assign io_master_w_valid = _io_master_aw_valid_T & ~mWriteDataSent; // @[DMA.scala 101:50]
  assign io_master_w_bits_data = _GEN_41[31:0];
  assign io_master_w_bits_strb = _GEN_40[3:0];
  assign io_master_w_bits_last = 1'h1; // @[DMA.scala 104:25]
  assign io_master_b_ready = mState == 3'h4; // @[DMA.scala 108:31]
  assign io_master_ar_valid = mState == 3'h1; // @[DMA.scala 89:38]
  assign io_master_ar_bits_id = 4'h0; // @[DMA.scala 95:28]
  assign io_master_ar_bits_addr = _GEN_24[31:0];
  assign io_master_ar_bits_region = 4'h0; // @[DMA.scala 99:28]
  assign io_master_ar_bits_len = 8'h4; // @[DMA.scala 92:28]
  assign io_master_ar_bits_size = 2'h2; // @[DMA.scala 93:28]
  assign io_master_ar_bits_burst = 2'h0; // @[DMA.scala 91:28]
  assign io_master_ar_bits_lock = 1'h0; // @[DMA.scala 97:28]
  assign io_master_ar_bits_cache = 4'h0; // @[DMA.scala 94:28]
  assign io_master_ar_bits_prot = 3'h0; // @[DMA.scala 96:28]
  assign io_master_ar_bits_qos = 4'h0; // @[DMA.scala 98:28]
  assign io_master_r_ready = mState == 3'h2; // @[DMA.scala 106:31]
  assign io_Hcf = mmio_regs_5[0]; // @[DMA.scala 74:10]
  always @(posedge clock) begin
    if (reset) begin // @[DMA.scala 17:24]
      mState <= 3'h0; // @[DMA.scala 17:24]
    end else if (3'h0 == mState) begin // @[DMA.scala 126:18]
      if (mmio_regs_0 == 32'h1) begin // @[DMA.scala 129:33]
        mState <= 3'h1; // @[DMA.scala 130:16]
      end
    end else if (3'h1 == mState) begin // @[DMA.scala 126:18]
      if (io_master_ar_ready) begin // @[DMA.scala 137:32]
        mState <= 3'h2; // @[DMA.scala 138:16]
      end
    end else if (3'h2 == mState) begin // @[DMA.scala 126:18]
      mState <= _GEN_2;
    end else begin
      mState <= _GEN_7;
    end
    if (reset) begin // @[DMA.scala 23:28]
      sReadState <= 1'h0; // @[DMA.scala 23:28]
    end else if (_io_slave_ar_ready_T) begin // @[DMA.scala 166:22]
      sReadState <= _GEN_11;
    end else if (sReadState) begin // @[DMA.scala 166:22]
      if (io_slave_r_ready) begin // @[DMA.scala 173:30]
        sReadState <= 1'h0; // @[DMA.scala 174:20]
      end
    end
    if (reset) begin // @[DMA.scala 24:28]
      sWriteState <= 2'h0; // @[DMA.scala 24:28]
    end else if (2'h0 == sWriteState) begin // @[DMA.scala 179:23]
      if (io_slave_aw_valid | io_slave_w_valid) begin // @[DMA.scala 181:51]
        sWriteState <= 2'h1; // @[DMA.scala 182:21]
      end
    end else if (2'h1 == sWriteState) begin // @[DMA.scala 179:23]
      if (sWriteDataRecv & sWriteAddrRecv) begin // @[DMA.scala 186:46]
        sWriteState <= 2'h2; // @[DMA.scala 187:21]
      end
    end else if (2'h2 == sWriteState) begin // @[DMA.scala 179:23]
      sWriteState <= _GEN_17;
    end
    if (reset) begin // @[DMA.scala 26:33]
      sReadAddrReg <= 32'h0; // @[DMA.scala 26:33]
    end else if (_io_slave_ar_ready_T & io_slave_ar_valid) begin // @[DMA.scala 333:55]
      sReadAddrReg <= io_slave_ar_bits_addr; // @[DMA.scala 334:18]
    end
    if (reset) begin // @[DMA.scala 27:33]
      sReadIDReg <= 4'h0; // @[DMA.scala 27:33]
    end else if (_io_slave_ar_ready_T & io_slave_ar_valid) begin // @[DMA.scala 333:55]
      sReadIDReg <= io_slave_ar_bits_id; // @[DMA.scala 335:18]
    end
    if (reset) begin // @[DMA.scala 28:33]
      sWriteIDReg <= 4'h0; // @[DMA.scala 28:33]
    end else if (_io_slave_aw_ready_T_2) begin // @[DMA.scala 287:66]
      if (io_slave_aw_valid) begin // @[DMA.scala 288:29]
        if (!(sWriteAddrRecv)) begin // @[DMA.scala 295:29]
          sWriteIDReg <= io_slave_aw_bits_id;
        end
      end
    end
    if (reset) begin // @[DMA.scala 29:33]
      sWriteDataRecv <= 1'h0; // @[DMA.scala 29:33]
    end else if (_io_slave_aw_ready_T_2) begin // @[DMA.scala 287:66]
      sWriteDataRecv <= _GEN_52;
    end else if (_io_slave_b_valid_T) begin // @[DMA.scala 305:42]
      sWriteDataRecv <= 1'h0; // @[DMA.scala 307:20]
    end
    if (reset) begin // @[DMA.scala 30:33]
      sWriteAddrRecv <= 1'h0; // @[DMA.scala 30:33]
    end else if (_io_slave_aw_ready_T_2) begin // @[DMA.scala 287:66]
      sWriteAddrRecv <= _GEN_49;
    end else if (_io_slave_b_valid_T) begin // @[DMA.scala 305:42]
      sWriteAddrRecv <= 1'h0; // @[DMA.scala 306:20]
    end
    if (reset) begin // @[DMA.scala 31:33]
      sWriteDataReg <= 32'h0; // @[DMA.scala 31:33]
    end else if (_io_slave_aw_ready_T_2) begin // @[DMA.scala 287:66]
      if (io_slave_w_valid) begin // @[DMA.scala 301:28]
        if (!(sWriteDataRecv)) begin // @[DMA.scala 303:28]
          sWriteDataReg <= io_slave_w_bits_data;
        end
      end
    end
    if (reset) begin // @[DMA.scala 32:33]
      sWriteAddrReg <= 32'h0; // @[DMA.scala 32:33]
    end else if (_io_slave_aw_ready_T_2) begin // @[DMA.scala 287:66]
      if (io_slave_aw_valid) begin // @[DMA.scala 288:29]
        if (!(sWriteAddrRecv)) begin // @[DMA.scala 290:29]
          sWriteAddrReg <= io_slave_aw_bits_addr;
        end
      end
    end
    if (reset) begin // @[DMA.scala 36:31]
      mWriteAddrSent <= 1'h0; // @[DMA.scala 36:31]
    end else begin
      mWriteAddrSent <= _GEN_48;
    end
    if (reset) begin // @[DMA.scala 37:31]
      mWriteDataSent <= 1'h0; // @[DMA.scala 37:31]
    end else begin
      mWriteDataSent <= _GEN_47;
    end
    if (reset) begin // @[DMA.scala 38:26]
      mReadlast <= 1'h0; // @[DMA.scala 38:26]
    end else if (_io_master_r_ready_T & io_master_r_valid) begin // @[DMA.scala 215:51]
      mReadlast <= io_master_r_bits_last; // @[DMA.scala 225:15]
    end else if (mState == 3'h0) begin // @[DMA.scala 204:25]
      mReadlast <= 1'h0; // @[DMA.scala 204:36]
    end
    if (reset) begin // @[DMA.scala 40:34]
      mmio_regs_0 <= 32'h0; // @[DMA.scala 40:34]
    end else if (_io_slave_b_valid_T & io_slave_b_ready) begin // @[DMA.scala 311:56]
      if (32'h0 == sWriteAddrOffset) begin // @[DMA.scala 312:30]
        mmio_regs_0 <= sWriteDataReg; // @[DMA.scala 314:22]
      end else begin
        mmio_regs_0 <= _GEN_43;
      end
    end else begin
      mmio_regs_0 <= _GEN_43;
    end
    if (reset) begin // @[DMA.scala 40:34]
      mmio_regs_1 <= 32'h0; // @[DMA.scala 40:34]
    end else if (_io_slave_b_valid_T & io_slave_b_ready) begin // @[DMA.scala 311:56]
      if (!(32'h0 == sWriteAddrOffset)) begin // @[DMA.scala 312:30]
        if (32'h4 == sWriteAddrOffset) begin // @[DMA.scala 312:30]
          mmio_regs_1 <= sWriteDataReg; // @[DMA.scala 317:22]
        end
      end
    end
    if (reset) begin // @[DMA.scala 40:34]
      mmio_regs_2 <= 32'h0; // @[DMA.scala 40:34]
    end else if (_io_slave_b_valid_T & io_slave_b_ready) begin // @[DMA.scala 311:56]
      if (!(32'h0 == sWriteAddrOffset)) begin // @[DMA.scala 312:30]
        if (!(32'h4 == sWriteAddrOffset)) begin // @[DMA.scala 312:30]
          mmio_regs_2 <= _GEN_67;
        end
      end
    end
    if (reset) begin // @[DMA.scala 40:34]
      mmio_regs_3 <= 32'h0; // @[DMA.scala 40:34]
    end else if (_io_slave_b_valid_T & io_slave_b_ready) begin // @[DMA.scala 311:56]
      if (!(32'h0 == sWriteAddrOffset)) begin // @[DMA.scala 312:30]
        if (!(32'h4 == sWriteAddrOffset)) begin // @[DMA.scala 312:30]
          mmio_regs_3 <= _GEN_68;
        end
      end
    end
    if (reset) begin // @[DMA.scala 40:34]
      mmio_regs_4 <= 32'h0; // @[DMA.scala 40:34]
    end else if (_io_slave_b_valid_T & io_slave_b_ready) begin // @[DMA.scala 311:56]
      if (!(32'h0 == sWriteAddrOffset)) begin // @[DMA.scala 312:30]
        if (!(32'h4 == sWriteAddrOffset)) begin // @[DMA.scala 312:30]
          mmio_regs_4 <= _GEN_69;
        end
      end
    end
    if (reset) begin // @[DMA.scala 40:34]
      mmio_regs_5 <= 32'h0; // @[DMA.scala 40:34]
    end else if (_io_slave_b_valid_T & io_slave_b_ready) begin // @[DMA.scala 311:56]
      if (32'h0 == sWriteAddrOffset) begin // @[DMA.scala 312:30]
        mmio_regs_5 <= _GEN_44;
      end else if (32'h4 == sWriteAddrOffset) begin // @[DMA.scala 312:30]
        mmio_regs_5 <= _GEN_44;
      end else begin
        mmio_regs_5 <= _GEN_70;
      end
    end else begin
      mmio_regs_5 <= _GEN_44;
    end
    if (reset) begin // @[DMA.scala 49:31]
      data_buffer <= 32'h0; // @[DMA.scala 49:31]
    end else if (_io_master_r_ready_T & io_master_r_valid) begin // @[DMA.scala 215:51]
      data_buffer <= _data_buffer_T_2; // @[DMA.scala 241:17]
    end
    if (reset) begin // @[DMA.scala 52:31]
      source_offset <= 2'h0; // @[DMA.scala 52:31]
    end else if (_io_master_ar_valid_T) begin // @[DMA.scala 205:30]
      source_offset <= io_master_ar_bits_addr[1:0]; // @[DMA.scala 212:19]
    end
    if (reset) begin // @[DMA.scala 58:32]
      request_counter <= 32'h0; // @[DMA.scala 58:32]
    end else if (_io_master_b_ready_T & request_counter == _GEN_92) begin // @[DMA.scala 265:73]
      request_counter <= 32'h0; // @[DMA.scala 266:21]
    end else if (_io_master_aw_valid_T) begin // @[DMA.scala 198:31]
      if (_T_18) begin // @[DMA.scala 199:29]
        request_counter <= _request_counter_T_1; // @[DMA.scala 201:23]
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  mState = _RAND_0[2:0];
  _RAND_1 = {1{`RANDOM}};
  sReadState = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  sWriteState = _RAND_2[1:0];
  _RAND_3 = {1{`RANDOM}};
  sReadAddrReg = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  sReadIDReg = _RAND_4[3:0];
  _RAND_5 = {1{`RANDOM}};
  sWriteIDReg = _RAND_5[3:0];
  _RAND_6 = {1{`RANDOM}};
  sWriteDataRecv = _RAND_6[0:0];
  _RAND_7 = {1{`RANDOM}};
  sWriteAddrRecv = _RAND_7[0:0];
  _RAND_8 = {1{`RANDOM}};
  sWriteDataReg = _RAND_8[31:0];
  _RAND_9 = {1{`RANDOM}};
  sWriteAddrReg = _RAND_9[31:0];
  _RAND_10 = {1{`RANDOM}};
  mWriteAddrSent = _RAND_10[0:0];
  _RAND_11 = {1{`RANDOM}};
  mWriteDataSent = _RAND_11[0:0];
  _RAND_12 = {1{`RANDOM}};
  mReadlast = _RAND_12[0:0];
  _RAND_13 = {1{`RANDOM}};
  mmio_regs_0 = _RAND_13[31:0];
  _RAND_14 = {1{`RANDOM}};
  mmio_regs_1 = _RAND_14[31:0];
  _RAND_15 = {1{`RANDOM}};
  mmio_regs_2 = _RAND_15[31:0];
  _RAND_16 = {1{`RANDOM}};
  mmio_regs_3 = _RAND_16[31:0];
  _RAND_17 = {1{`RANDOM}};
  mmio_regs_4 = _RAND_17[31:0];
  _RAND_18 = {1{`RANDOM}};
  mmio_regs_5 = _RAND_18[31:0];
  _RAND_19 = {1{`RANDOM}};
  data_buffer = _RAND_19[31:0];
  _RAND_20 = {1{`RANDOM}};
  source_offset = _RAND_20[1:0];
  _RAND_21 = {1{`RANDOM}};
  request_counter = _RAND_21[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Reg_IF(
  input         clock,
  input         reset,
  input         io_Stall,
  input  [31:0] io_next_pc_in,
  output [31:0] io_pc
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] pcReg; // @[Reg_IF.scala 15:24]
  assign io_pc = pcReg; // @[Reg_IF.scala 23:11]
  always @(posedge clock) begin
    if (reset) begin // @[Reg_IF.scala 15:24]
      pcReg <= 32'h0; // @[Reg_IF.scala 15:24]
    end else if (!(io_Stall)) begin // @[Reg_IF.scala 17:19]
      pcReg <= io_next_pc_in; // @[Reg_IF.scala 20:15]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  pcReg = _RAND_0[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Reg_ID(
  input         clock,
  input         reset,
  input         io_Flush,
  input         io_Stall,
  input  [31:0] io_pc_in,
  input  [31:0] io_inst_in,
  output [31:0] io_pc,
  output [31:0] io_inst
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] InstReg; // @[Reg_ID.scala 19:26]
  reg [14:0] pcReg; // @[Reg_ID.scala 20:25]
  wire [31:0] _GEN_1 = io_Stall ? {{17'd0}, pcReg} : io_pc_in; // @[Reg_ID.scala 27:25 29:15 32:15]
  wire [31:0] _GEN_3 = io_Flush ? 32'h0 : _GEN_1; // @[Reg_ID.scala 24:19 26:15]
  wire [31:0] _GEN_4 = reset ? 32'h0 : _GEN_3; // @[Reg_ID.scala 20:{25,25}]
  assign io_pc = {{17'd0}, pcReg}; // @[Reg_ID.scala 36:11]
  assign io_inst = InstReg; // @[Reg_ID.scala 35:13]
  always @(posedge clock) begin
    if (reset) begin // @[Reg_ID.scala 19:26]
      InstReg <= 32'h0; // @[Reg_ID.scala 19:26]
    end else if (io_Flush) begin // @[Reg_ID.scala 24:19]
      InstReg <= 32'h0; // @[Reg_ID.scala 25:17]
    end else if (!(io_Stall)) begin // @[Reg_ID.scala 27:25]
      InstReg <= io_inst_in; // @[Reg_ID.scala 31:17]
    end
    pcReg <= _GEN_4[14:0]; // @[Reg_ID.scala 20:{25,25}]
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  InstReg = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  pcReg = _RAND_1[14:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Reg_EXE(
  input         clock,
  input         reset,
  input         io_Flush,
  input         io_Stall,
  input  [31:0] io_inst_in,
  input  [31:0] io_pc_in,
  input  [31:0] io_rs1_rdata_in,
  input  [31:0] io_rs2_rdata_in,
  input  [31:0] io_imm_in,
  output [31:0] io_inst,
  output [31:0] io_pc,
  output [31:0] io_rs1_rdata,
  output [31:0] io_rs2_rdata,
  output [31:0] io_imm
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] pcReg; // @[Reg_EXE.scala 27:25]
  reg [31:0] InstReg; // @[Reg_EXE.scala 28:26]
  reg [31:0] immReg; // @[Reg_EXE.scala 29:25]
  reg [31:0] rs1Reg; // @[Reg_EXE.scala 30:25]
  reg [31:0] rs2Reg; // @[Reg_EXE.scala 31:25]
  assign io_inst = InstReg; // @[Reg_EXE.scala 54:13]
  assign io_pc = pcReg; // @[Reg_EXE.scala 56:11]
  assign io_rs1_rdata = rs1Reg; // @[Reg_EXE.scala 57:18]
  assign io_rs2_rdata = rs2Reg; // @[Reg_EXE.scala 58:18]
  assign io_imm = immReg; // @[Reg_EXE.scala 55:12]
  always @(posedge clock) begin
    if (reset) begin // @[Reg_EXE.scala 27:25]
      pcReg <= 32'h0; // @[Reg_EXE.scala 27:25]
    end else if (io_Flush) begin // @[Reg_EXE.scala 34:19]
      pcReg <= 32'h0; // @[Reg_EXE.scala 37:15]
    end else if (!(io_Stall)) begin // @[Reg_EXE.scala 40:25]
      pcReg <= io_pc_in; // @[Reg_EXE.scala 49:15]
    end
    if (reset) begin // @[Reg_EXE.scala 28:26]
      InstReg <= 32'h0; // @[Reg_EXE.scala 28:26]
    end else if (io_Flush) begin // @[Reg_EXE.scala 34:19]
      InstReg <= 32'h0; // @[Reg_EXE.scala 36:17]
    end else if (!(io_Stall)) begin // @[Reg_EXE.scala 40:25]
      InstReg <= io_inst_in; // @[Reg_EXE.scala 47:17]
    end
    if (reset) begin // @[Reg_EXE.scala 29:25]
      immReg <= 32'h0; // @[Reg_EXE.scala 29:25]
    end else if (io_Flush) begin // @[Reg_EXE.scala 34:19]
      immReg <= 32'h0; // @[Reg_EXE.scala 35:16]
    end else if (!(io_Stall)) begin // @[Reg_EXE.scala 40:25]
      immReg <= io_imm_in; // @[Reg_EXE.scala 48:16]
    end
    if (reset) begin // @[Reg_EXE.scala 30:25]
      rs1Reg <= 32'h0; // @[Reg_EXE.scala 30:25]
    end else if (io_Flush) begin // @[Reg_EXE.scala 34:19]
      rs1Reg <= 32'h0; // @[Reg_EXE.scala 38:16]
    end else if (!(io_Stall)) begin // @[Reg_EXE.scala 40:25]
      rs1Reg <= io_rs1_rdata_in; // @[Reg_EXE.scala 50:16]
    end
    if (reset) begin // @[Reg_EXE.scala 31:25]
      rs2Reg <= 32'h0; // @[Reg_EXE.scala 31:25]
    end else if (io_Flush) begin // @[Reg_EXE.scala 34:19]
      rs2Reg <= 32'h0; // @[Reg_EXE.scala 39:16]
    end else if (!(io_Stall)) begin // @[Reg_EXE.scala 40:25]
      rs2Reg <= io_rs2_rdata_in; // @[Reg_EXE.scala 51:16]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  pcReg = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  InstReg = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  immReg = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  rs1Reg = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  rs2Reg = _RAND_4[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Reg_MEM(
  input         clock,
  input         reset,
  input         io_Stall,
  input  [31:0] io_pc_in,
  input  [31:0] io_inst_in,
  input  [31:0] io_alu_out_in,
  input  [31:0] io_DM_wdata_in,
  output [31:0] io_pc,
  output [31:0] io_inst,
  output [31:0] io_alu_out,
  output [31:0] io_DM_wdata
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] InstReg; // @[Reg_MEM.scala 22:26]
  reg [31:0] pcReg; // @[Reg_MEM.scala 23:25]
  reg [31:0] aluReg; // @[Reg_MEM.scala 24:25]
  reg [31:0] wdataReg; // @[Reg_MEM.scala 25:27]
  assign io_pc = pcReg; // @[Reg_MEM.scala 41:11]
  assign io_inst = InstReg; // @[Reg_MEM.scala 40:13]
  assign io_alu_out = aluReg; // @[Reg_MEM.scala 42:16]
  assign io_DM_wdata = wdataReg; // @[Reg_MEM.scala 43:17]
  always @(posedge clock) begin
    if (reset) begin // @[Reg_MEM.scala 22:26]
      InstReg <= 32'h0; // @[Reg_MEM.scala 22:26]
    end else if (!(io_Stall)) begin // @[Reg_MEM.scala 28:19]
      InstReg <= io_inst_in; // @[Reg_MEM.scala 34:17]
    end
    if (reset) begin // @[Reg_MEM.scala 23:25]
      pcReg <= 32'h0; // @[Reg_MEM.scala 23:25]
    end else if (!(io_Stall)) begin // @[Reg_MEM.scala 28:19]
      pcReg <= io_pc_in; // @[Reg_MEM.scala 35:15]
    end
    if (reset) begin // @[Reg_MEM.scala 24:25]
      aluReg <= 32'h0; // @[Reg_MEM.scala 24:25]
    end else if (!(io_Stall)) begin // @[Reg_MEM.scala 28:19]
      aluReg <= io_alu_out_in; // @[Reg_MEM.scala 36:16]
    end
    if (reset) begin // @[Reg_MEM.scala 25:27]
      wdataReg <= 32'h0; // @[Reg_MEM.scala 25:27]
    end else if (!(io_Stall)) begin // @[Reg_MEM.scala 28:19]
      wdataReg <= io_DM_wdata_in; // @[Reg_MEM.scala 37:18]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  InstReg = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  pcReg = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  aluReg = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  wdataReg = _RAND_3[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Reg_WB(
  input         clock,
  input         reset,
  input         io_Stall,
  input  [31:0] io_pc_plus4_in,
  input  [31:0] io_inst_in,
  input  [31:0] io_alu_out_in,
  input  [31:0] io_ld_data_in,
  output [31:0] io_pc_plus4,
  output [31:0] io_inst,
  output [31:0] io_alu_out,
  output [31:0] io_ld_data
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] pc_plus4_Reg; // @[Reg_WB.scala 22:32]
  reg [31:0] InstReg; // @[Reg_WB.scala 23:26]
  reg [31:0] alu_out_Reg; // @[Reg_WB.scala 24:30]
  reg [31:0] ld_data_Reg; // @[Reg_WB.scala 25:30]
  assign io_pc_plus4 = pc_plus4_Reg; // @[Reg_WB.scala 40:17]
  assign io_inst = InstReg; // @[Reg_WB.scala 41:13]
  assign io_alu_out = alu_out_Reg; // @[Reg_WB.scala 42:16]
  assign io_ld_data = ld_data_Reg; // @[Reg_WB.scala 43:16]
  always @(posedge clock) begin
    if (reset) begin // @[Reg_WB.scala 22:32]
      pc_plus4_Reg <= 32'h0; // @[Reg_WB.scala 22:32]
    end else if (!(io_Stall)) begin // @[Reg_WB.scala 28:19]
      pc_plus4_Reg <= io_pc_plus4_in; // @[Reg_WB.scala 34:22]
    end
    if (reset) begin // @[Reg_WB.scala 23:26]
      InstReg <= 32'h0; // @[Reg_WB.scala 23:26]
    end else if (!(io_Stall)) begin // @[Reg_WB.scala 28:19]
      InstReg <= io_inst_in; // @[Reg_WB.scala 35:17]
    end
    if (reset) begin // @[Reg_WB.scala 24:30]
      alu_out_Reg <= 32'h0; // @[Reg_WB.scala 24:30]
    end else if (!(io_Stall)) begin // @[Reg_WB.scala 28:19]
      alu_out_Reg <= io_alu_out_in; // @[Reg_WB.scala 36:21]
    end
    if (reset) begin // @[Reg_WB.scala 25:30]
      ld_data_Reg <= 32'h0; // @[Reg_WB.scala 25:30]
    end else if (!(io_Stall)) begin // @[Reg_WB.scala 28:19]
      ld_data_Reg <= io_ld_data_in; // @[Reg_WB.scala 37:21]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  pc_plus4_Reg = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  InstReg = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  alu_out_Reg = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  ld_data_Reg = _RAND_3[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Path_IF(
  input  [1:0]  io_PCSel,
  input  [31:0] io_IF_pc_in,
  input  [31:0] io_EXE_pc_in,
  input  [31:0] io_EXE_target_pc_in,
  input  [31:0] io_Mem_data,
  output [31:0] io_next_pc,
  output [31:0] io_Mem_Addr,
  output [31:0] io_inst
);
  wire [31:0] _io_next_pc_T_1 = io_IF_pc_in + 32'h4; // @[Path_IF.scala 23:52]
  wire [31:0] _io_next_pc_T_5 = io_EXE_pc_in + 32'h4; // @[Path_IF.scala 25:40]
  wire [31:0] _io_next_pc_T_7 = 2'h0 == io_PCSel ? _io_next_pc_T_1 : _io_next_pc_T_1; // @[Mux.scala 81:58]
  wire [31:0] _io_next_pc_T_9 = 2'h1 == io_PCSel ? _io_next_pc_T_5 : _io_next_pc_T_7; // @[Mux.scala 81:58]
  assign io_next_pc = 2'h2 == io_PCSel ? io_EXE_target_pc_in : _io_next_pc_T_9; // @[Mux.scala 81:58]
  assign io_Mem_Addr = io_IF_pc_in; // @[Path_IF.scala 29:17]
  assign io_inst = io_Mem_data; // @[Path_IF.scala 30:13]
endmodule
module RegFile(
  input         clock,
  input         reset,
  input         io_wen,
  input  [4:0]  io_waddr,
  input  [31:0] io_wdata,
  input  [4:0]  io_raddr_0,
  input  [4:0]  io_raddr_1,
  output [31:0] io_rdata_0,
  output [31:0] io_rdata_1,
  output [31:0] io_regs_1,
  output [31:0] io_regs_2,
  output [31:0] io_regs_3,
  output [31:0] io_regs_4,
  output [31:0] io_regs_5,
  output [31:0] io_regs_6,
  output [31:0] io_regs_7,
  output [31:0] io_regs_8,
  output [31:0] io_regs_9,
  output [31:0] io_regs_10,
  output [31:0] io_regs_11,
  output [31:0] io_regs_12,
  output [31:0] io_regs_13,
  output [31:0] io_regs_14,
  output [31:0] io_regs_15,
  output [31:0] io_regs_16,
  output [31:0] io_regs_17,
  output [31:0] io_regs_18,
  output [31:0] io_regs_19,
  output [31:0] io_regs_20,
  output [31:0] io_regs_21,
  output [31:0] io_regs_22,
  output [31:0] io_regs_23,
  output [31:0] io_regs_24,
  output [31:0] io_regs_25,
  output [31:0] io_regs_26,
  output [31:0] io_regs_27,
  output [31:0] io_regs_28,
  output [31:0] io_regs_29,
  output [31:0] io_regs_30,
  output [31:0] io_regs_31
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
  reg [31:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [31:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [31:0] _RAND_30;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] regs_1; // @[RegFile.scala 16:21]
  reg [31:0] regs_2; // @[RegFile.scala 16:21]
  reg [31:0] regs_3; // @[RegFile.scala 16:21]
  reg [31:0] regs_4; // @[RegFile.scala 16:21]
  reg [31:0] regs_5; // @[RegFile.scala 16:21]
  reg [31:0] regs_6; // @[RegFile.scala 16:21]
  reg [31:0] regs_7; // @[RegFile.scala 16:21]
  reg [31:0] regs_8; // @[RegFile.scala 16:21]
  reg [31:0] regs_9; // @[RegFile.scala 16:21]
  reg [31:0] regs_10; // @[RegFile.scala 16:21]
  reg [31:0] regs_11; // @[RegFile.scala 16:21]
  reg [31:0] regs_12; // @[RegFile.scala 16:21]
  reg [31:0] regs_13; // @[RegFile.scala 16:21]
  reg [31:0] regs_14; // @[RegFile.scala 16:21]
  reg [31:0] regs_15; // @[RegFile.scala 16:21]
  reg [31:0] regs_16; // @[RegFile.scala 16:21]
  reg [31:0] regs_17; // @[RegFile.scala 16:21]
  reg [31:0] regs_18; // @[RegFile.scala 16:21]
  reg [31:0] regs_19; // @[RegFile.scala 16:21]
  reg [31:0] regs_20; // @[RegFile.scala 16:21]
  reg [31:0] regs_21; // @[RegFile.scala 16:21]
  reg [31:0] regs_22; // @[RegFile.scala 16:21]
  reg [31:0] regs_23; // @[RegFile.scala 16:21]
  reg [31:0] regs_24; // @[RegFile.scala 16:21]
  reg [31:0] regs_25; // @[RegFile.scala 16:21]
  reg [31:0] regs_26; // @[RegFile.scala 16:21]
  reg [31:0] regs_27; // @[RegFile.scala 16:21]
  reg [31:0] regs_28; // @[RegFile.scala 16:21]
  reg [31:0] regs_29; // @[RegFile.scala 16:21]
  reg [31:0] regs_30; // @[RegFile.scala 16:21]
  reg [31:0] regs_31; // @[RegFile.scala 16:21]
  wire [31:0] _GEN_1 = 5'h1 == io_raddr_0 ? regs_1 : 32'h0; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_2 = 5'h2 == io_raddr_0 ? regs_2 : _GEN_1; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_3 = 5'h3 == io_raddr_0 ? regs_3 : _GEN_2; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_4 = 5'h4 == io_raddr_0 ? regs_4 : _GEN_3; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_5 = 5'h5 == io_raddr_0 ? regs_5 : _GEN_4; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_6 = 5'h6 == io_raddr_0 ? regs_6 : _GEN_5; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_7 = 5'h7 == io_raddr_0 ? regs_7 : _GEN_6; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_8 = 5'h8 == io_raddr_0 ? regs_8 : _GEN_7; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_9 = 5'h9 == io_raddr_0 ? regs_9 : _GEN_8; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_10 = 5'ha == io_raddr_0 ? regs_10 : _GEN_9; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_11 = 5'hb == io_raddr_0 ? regs_11 : _GEN_10; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_12 = 5'hc == io_raddr_0 ? regs_12 : _GEN_11; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_13 = 5'hd == io_raddr_0 ? regs_13 : _GEN_12; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_14 = 5'he == io_raddr_0 ? regs_14 : _GEN_13; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_15 = 5'hf == io_raddr_0 ? regs_15 : _GEN_14; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_16 = 5'h10 == io_raddr_0 ? regs_16 : _GEN_15; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_17 = 5'h11 == io_raddr_0 ? regs_17 : _GEN_16; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_18 = 5'h12 == io_raddr_0 ? regs_18 : _GEN_17; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_19 = 5'h13 == io_raddr_0 ? regs_19 : _GEN_18; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_20 = 5'h14 == io_raddr_0 ? regs_20 : _GEN_19; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_21 = 5'h15 == io_raddr_0 ? regs_21 : _GEN_20; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_22 = 5'h16 == io_raddr_0 ? regs_22 : _GEN_21; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_23 = 5'h17 == io_raddr_0 ? regs_23 : _GEN_22; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_24 = 5'h18 == io_raddr_0 ? regs_24 : _GEN_23; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_25 = 5'h19 == io_raddr_0 ? regs_25 : _GEN_24; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_26 = 5'h1a == io_raddr_0 ? regs_26 : _GEN_25; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_27 = 5'h1b == io_raddr_0 ? regs_27 : _GEN_26; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_28 = 5'h1c == io_raddr_0 ? regs_28 : _GEN_27; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_29 = 5'h1d == io_raddr_0 ? regs_29 : _GEN_28; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_30 = 5'h1e == io_raddr_0 ? regs_30 : _GEN_29; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_33 = 5'h1 == io_raddr_1 ? regs_1 : 32'h0; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_34 = 5'h2 == io_raddr_1 ? regs_2 : _GEN_33; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_35 = 5'h3 == io_raddr_1 ? regs_3 : _GEN_34; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_36 = 5'h4 == io_raddr_1 ? regs_4 : _GEN_35; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_37 = 5'h5 == io_raddr_1 ? regs_5 : _GEN_36; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_38 = 5'h6 == io_raddr_1 ? regs_6 : _GEN_37; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_39 = 5'h7 == io_raddr_1 ? regs_7 : _GEN_38; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_40 = 5'h8 == io_raddr_1 ? regs_8 : _GEN_39; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_41 = 5'h9 == io_raddr_1 ? regs_9 : _GEN_40; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_42 = 5'ha == io_raddr_1 ? regs_10 : _GEN_41; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_43 = 5'hb == io_raddr_1 ? regs_11 : _GEN_42; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_44 = 5'hc == io_raddr_1 ? regs_12 : _GEN_43; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_45 = 5'hd == io_raddr_1 ? regs_13 : _GEN_44; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_46 = 5'he == io_raddr_1 ? regs_14 : _GEN_45; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_47 = 5'hf == io_raddr_1 ? regs_15 : _GEN_46; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_48 = 5'h10 == io_raddr_1 ? regs_16 : _GEN_47; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_49 = 5'h11 == io_raddr_1 ? regs_17 : _GEN_48; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_50 = 5'h12 == io_raddr_1 ? regs_18 : _GEN_49; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_51 = 5'h13 == io_raddr_1 ? regs_19 : _GEN_50; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_52 = 5'h14 == io_raddr_1 ? regs_20 : _GEN_51; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_53 = 5'h15 == io_raddr_1 ? regs_21 : _GEN_52; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_54 = 5'h16 == io_raddr_1 ? regs_22 : _GEN_53; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_55 = 5'h17 == io_raddr_1 ? regs_23 : _GEN_54; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_56 = 5'h18 == io_raddr_1 ? regs_24 : _GEN_55; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_57 = 5'h19 == io_raddr_1 ? regs_25 : _GEN_56; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_58 = 5'h1a == io_raddr_1 ? regs_26 : _GEN_57; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_59 = 5'h1b == io_raddr_1 ? regs_27 : _GEN_58; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_60 = 5'h1c == io_raddr_1 ? regs_28 : _GEN_59; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_61 = 5'h1d == io_raddr_1 ? regs_29 : _GEN_60; // @[RegFile.scala 22:{52,52}]
  wire [31:0] _GEN_62 = 5'h1e == io_raddr_1 ? regs_30 : _GEN_61; // @[RegFile.scala 22:{52,52}]
  assign io_rdata_0 = 5'h1f == io_raddr_0 ? regs_31 : _GEN_30; // @[RegFile.scala 22:{52,52}]
  assign io_rdata_1 = 5'h1f == io_raddr_1 ? regs_31 : _GEN_62; // @[RegFile.scala 22:{52,52}]
  assign io_regs_1 = regs_1; // @[RegFile.scala 26:11]
  assign io_regs_2 = regs_2; // @[RegFile.scala 26:11]
  assign io_regs_3 = regs_3; // @[RegFile.scala 26:11]
  assign io_regs_4 = regs_4; // @[RegFile.scala 26:11]
  assign io_regs_5 = regs_5; // @[RegFile.scala 26:11]
  assign io_regs_6 = regs_6; // @[RegFile.scala 26:11]
  assign io_regs_7 = regs_7; // @[RegFile.scala 26:11]
  assign io_regs_8 = regs_8; // @[RegFile.scala 26:11]
  assign io_regs_9 = regs_9; // @[RegFile.scala 26:11]
  assign io_regs_10 = regs_10; // @[RegFile.scala 26:11]
  assign io_regs_11 = regs_11; // @[RegFile.scala 26:11]
  assign io_regs_12 = regs_12; // @[RegFile.scala 26:11]
  assign io_regs_13 = regs_13; // @[RegFile.scala 26:11]
  assign io_regs_14 = regs_14; // @[RegFile.scala 26:11]
  assign io_regs_15 = regs_15; // @[RegFile.scala 26:11]
  assign io_regs_16 = regs_16; // @[RegFile.scala 26:11]
  assign io_regs_17 = regs_17; // @[RegFile.scala 26:11]
  assign io_regs_18 = regs_18; // @[RegFile.scala 26:11]
  assign io_regs_19 = regs_19; // @[RegFile.scala 26:11]
  assign io_regs_20 = regs_20; // @[RegFile.scala 26:11]
  assign io_regs_21 = regs_21; // @[RegFile.scala 26:11]
  assign io_regs_22 = regs_22; // @[RegFile.scala 26:11]
  assign io_regs_23 = regs_23; // @[RegFile.scala 26:11]
  assign io_regs_24 = regs_24; // @[RegFile.scala 26:11]
  assign io_regs_25 = regs_25; // @[RegFile.scala 26:11]
  assign io_regs_26 = regs_26; // @[RegFile.scala 26:11]
  assign io_regs_27 = regs_27; // @[RegFile.scala 26:11]
  assign io_regs_28 = regs_28; // @[RegFile.scala 26:11]
  assign io_regs_29 = regs_29; // @[RegFile.scala 26:11]
  assign io_regs_30 = regs_30; // @[RegFile.scala 26:11]
  assign io_regs_31 = regs_31; // @[RegFile.scala 26:11]
  always @(posedge clock) begin
    if (reset) begin // @[RegFile.scala 16:21]
      regs_1 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h1 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_1 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_2 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h2 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_2 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_3 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h3 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_3 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_4 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h4 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_4 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_5 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h5 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_5 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_6 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h6 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_6 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_7 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h7 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_7 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_8 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h8 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_8 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_9 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h9 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_9 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_10 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'ha == io_waddr) begin // @[RegFile.scala 23:32]
        regs_10 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_11 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'hb == io_waddr) begin // @[RegFile.scala 23:32]
        regs_11 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_12 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'hc == io_waddr) begin // @[RegFile.scala 23:32]
        regs_12 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_13 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'hd == io_waddr) begin // @[RegFile.scala 23:32]
        regs_13 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_14 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'he == io_waddr) begin // @[RegFile.scala 23:32]
        regs_14 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_15 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'hf == io_waddr) begin // @[RegFile.scala 23:32]
        regs_15 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_16 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h10 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_16 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_17 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h11 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_17 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_18 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h12 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_18 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_19 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h13 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_19 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_20 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h14 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_20 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_21 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h15 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_21 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_22 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h16 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_22 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_23 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h17 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_23 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_24 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h18 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_24 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_25 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h19 == io_waddr) begin // @[RegFile.scala 23:32]
        regs_25 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_26 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h1a == io_waddr) begin // @[RegFile.scala 23:32]
        regs_26 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_27 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h1b == io_waddr) begin // @[RegFile.scala 23:32]
        regs_27 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_28 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h1c == io_waddr) begin // @[RegFile.scala 23:32]
        regs_28 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_29 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h1d == io_waddr) begin // @[RegFile.scala 23:32]
        regs_29 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_30 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h1e == io_waddr) begin // @[RegFile.scala 23:32]
        regs_30 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
    if (reset) begin // @[RegFile.scala 16:21]
      regs_31 <= 32'h0; // @[RegFile.scala 16:21]
    end else if (io_wen) begin // @[RegFile.scala 23:16]
      if (5'h1f == io_waddr) begin // @[RegFile.scala 23:32]
        regs_31 <= io_wdata; // @[RegFile.scala 23:32]
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  regs_1 = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  regs_2 = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  regs_3 = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  regs_4 = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  regs_5 = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  regs_6 = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  regs_7 = _RAND_6[31:0];
  _RAND_7 = {1{`RANDOM}};
  regs_8 = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  regs_9 = _RAND_8[31:0];
  _RAND_9 = {1{`RANDOM}};
  regs_10 = _RAND_9[31:0];
  _RAND_10 = {1{`RANDOM}};
  regs_11 = _RAND_10[31:0];
  _RAND_11 = {1{`RANDOM}};
  regs_12 = _RAND_11[31:0];
  _RAND_12 = {1{`RANDOM}};
  regs_13 = _RAND_12[31:0];
  _RAND_13 = {1{`RANDOM}};
  regs_14 = _RAND_13[31:0];
  _RAND_14 = {1{`RANDOM}};
  regs_15 = _RAND_14[31:0];
  _RAND_15 = {1{`RANDOM}};
  regs_16 = _RAND_15[31:0];
  _RAND_16 = {1{`RANDOM}};
  regs_17 = _RAND_16[31:0];
  _RAND_17 = {1{`RANDOM}};
  regs_18 = _RAND_17[31:0];
  _RAND_18 = {1{`RANDOM}};
  regs_19 = _RAND_18[31:0];
  _RAND_19 = {1{`RANDOM}};
  regs_20 = _RAND_19[31:0];
  _RAND_20 = {1{`RANDOM}};
  regs_21 = _RAND_20[31:0];
  _RAND_21 = {1{`RANDOM}};
  regs_22 = _RAND_21[31:0];
  _RAND_22 = {1{`RANDOM}};
  regs_23 = _RAND_22[31:0];
  _RAND_23 = {1{`RANDOM}};
  regs_24 = _RAND_23[31:0];
  _RAND_24 = {1{`RANDOM}};
  regs_25 = _RAND_24[31:0];
  _RAND_25 = {1{`RANDOM}};
  regs_26 = _RAND_25[31:0];
  _RAND_26 = {1{`RANDOM}};
  regs_27 = _RAND_26[31:0];
  _RAND_27 = {1{`RANDOM}};
  regs_28 = _RAND_27[31:0];
  _RAND_28 = {1{`RANDOM}};
  regs_29 = _RAND_28[31:0];
  _RAND_29 = {1{`RANDOM}};
  regs_30 = _RAND_29[31:0];
  _RAND_30 = {1{`RANDOM}};
  regs_31 = _RAND_30[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module ImmGen(
  input  [24:0] io_inst_31_7,
  input  [2:0]  io_ImmSel,
  output [31:0] io_imm
);
  wire [31:0] inst_shift = {io_inst_31_7,7'h0}; // @[Cat.scala 33:92]
  wire [11:0] _simm_T_1 = inst_shift[31:20]; // @[ImmGen.scala 25:37]
  wire [12:0] _simm_T_7 = {inst_shift[31],inst_shift[7],inst_shift[30:25],inst_shift[11:8],1'h0}; // @[ImmGen.scala 32:28]
  wire [11:0] _simm_T_13 = {inst_shift[31],inst_shift[30:25],inst_shift[11:8],inst_shift[7]}; // @[ImmGen.scala 38:32]
  wire [31:0] _simm_T_16 = {inst_shift[31:12],12'h0}; // @[ImmGen.scala 41:52]
  wire [20:0] _simm_T_22 = {inst_shift[31],inst_shift[19:12],inst_shift[20],inst_shift[30:21],1'h0}; // @[ImmGen.scala 48:28]
  wire [11:0] _simm_T_26 = 3'h1 == io_ImmSel ? $signed(_simm_T_1) : $signed(12'sh0); // @[Mux.scala 81:58]
  wire [12:0] _simm_T_28 = 3'h3 == io_ImmSel ? $signed(_simm_T_7) : $signed({{1{_simm_T_26[11]}},_simm_T_26}); // @[Mux.scala 81:58]
  wire [12:0] _simm_T_30 = 3'h2 == io_ImmSel ? $signed({{1{_simm_T_13[11]}},_simm_T_13}) : $signed(_simm_T_28); // @[Mux.scala 81:58]
  wire [31:0] _simm_T_32 = 3'h5 == io_ImmSel ? $signed(_simm_T_16) : $signed({{19{_simm_T_30[12]}},_simm_T_30}); // @[Mux.scala 81:58]
  assign io_imm = 3'h4 == io_ImmSel ? $signed({{11{_simm_T_22[20]}},_simm_T_22}) : $signed(_simm_T_32); // @[ImmGen.scala 52:20]
endmodule
module Path_ID(
  input         clock,
  input         reset,
  input  [31:0] io_ID_inst_in,
  input  [4:0]  io_WB_index,
  input  [31:0] io_WB_wdata,
  input         io_WB_RegWEn,
  input  [2:0]  io_ImmSel,
  output [31:0] io_ID_rs1_rdata,
  output [31:0] io_ID_rs2_rdata,
  output [31:0] io_imm,
  output [31:0] io_regs_1,
  output [31:0] io_regs_2,
  output [31:0] io_regs_3,
  output [31:0] io_regs_4,
  output [31:0] io_regs_5,
  output [31:0] io_regs_6,
  output [31:0] io_regs_7,
  output [31:0] io_regs_8,
  output [31:0] io_regs_9,
  output [31:0] io_regs_10,
  output [31:0] io_regs_11,
  output [31:0] io_regs_12,
  output [31:0] io_regs_13,
  output [31:0] io_regs_14,
  output [31:0] io_regs_15,
  output [31:0] io_regs_16,
  output [31:0] io_regs_17,
  output [31:0] io_regs_18,
  output [31:0] io_regs_19,
  output [31:0] io_regs_20,
  output [31:0] io_regs_21,
  output [31:0] io_regs_22,
  output [31:0] io_regs_23,
  output [31:0] io_regs_24,
  output [31:0] io_regs_25,
  output [31:0] io_regs_26,
  output [31:0] io_regs_27,
  output [31:0] io_regs_28,
  output [31:0] io_regs_29,
  output [31:0] io_regs_30,
  output [31:0] io_regs_31
);
  wire  rf_clock; // @[Path_ID.scala 27:20]
  wire  rf_reset; // @[Path_ID.scala 27:20]
  wire  rf_io_wen; // @[Path_ID.scala 27:20]
  wire [4:0] rf_io_waddr; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_wdata; // @[Path_ID.scala 27:20]
  wire [4:0] rf_io_raddr_0; // @[Path_ID.scala 27:20]
  wire [4:0] rf_io_raddr_1; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_rdata_0; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_rdata_1; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_1; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_2; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_3; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_4; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_5; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_6; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_7; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_8; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_9; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_10; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_11; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_12; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_13; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_14; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_15; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_16; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_17; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_18; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_19; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_20; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_21; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_22; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_23; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_24; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_25; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_26; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_27; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_28; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_29; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_30; // @[Path_ID.scala 27:20]
  wire [31:0] rf_io_regs_31; // @[Path_ID.scala 27:20]
  wire [24:0] ig_io_inst_31_7; // @[Path_ID.scala 38:20]
  wire [2:0] ig_io_ImmSel; // @[Path_ID.scala 38:20]
  wire [31:0] ig_io_imm; // @[Path_ID.scala 38:20]
  RegFile rf ( // @[Path_ID.scala 27:20]
    .clock(rf_clock),
    .reset(rf_reset),
    .io_wen(rf_io_wen),
    .io_waddr(rf_io_waddr),
    .io_wdata(rf_io_wdata),
    .io_raddr_0(rf_io_raddr_0),
    .io_raddr_1(rf_io_raddr_1),
    .io_rdata_0(rf_io_rdata_0),
    .io_rdata_1(rf_io_rdata_1),
    .io_regs_1(rf_io_regs_1),
    .io_regs_2(rf_io_regs_2),
    .io_regs_3(rf_io_regs_3),
    .io_regs_4(rf_io_regs_4),
    .io_regs_5(rf_io_regs_5),
    .io_regs_6(rf_io_regs_6),
    .io_regs_7(rf_io_regs_7),
    .io_regs_8(rf_io_regs_8),
    .io_regs_9(rf_io_regs_9),
    .io_regs_10(rf_io_regs_10),
    .io_regs_11(rf_io_regs_11),
    .io_regs_12(rf_io_regs_12),
    .io_regs_13(rf_io_regs_13),
    .io_regs_14(rf_io_regs_14),
    .io_regs_15(rf_io_regs_15),
    .io_regs_16(rf_io_regs_16),
    .io_regs_17(rf_io_regs_17),
    .io_regs_18(rf_io_regs_18),
    .io_regs_19(rf_io_regs_19),
    .io_regs_20(rf_io_regs_20),
    .io_regs_21(rf_io_regs_21),
    .io_regs_22(rf_io_regs_22),
    .io_regs_23(rf_io_regs_23),
    .io_regs_24(rf_io_regs_24),
    .io_regs_25(rf_io_regs_25),
    .io_regs_26(rf_io_regs_26),
    .io_regs_27(rf_io_regs_27),
    .io_regs_28(rf_io_regs_28),
    .io_regs_29(rf_io_regs_29),
    .io_regs_30(rf_io_regs_30),
    .io_regs_31(rf_io_regs_31)
  );
  ImmGen ig ( // @[Path_ID.scala 38:20]
    .io_inst_31_7(ig_io_inst_31_7),
    .io_ImmSel(ig_io_ImmSel),
    .io_imm(ig_io_imm)
  );
  assign io_ID_rs1_rdata = rf_io_rdata_0; // @[Path_ID.scala 33:21]
  assign io_ID_rs2_rdata = rf_io_rdata_1; // @[Path_ID.scala 34:21]
  assign io_imm = ig_io_imm; // @[Path_ID.scala 41:12]
  assign io_regs_1 = rf_io_regs_1; // @[Path_ID.scala 35:13]
  assign io_regs_2 = rf_io_regs_2; // @[Path_ID.scala 35:13]
  assign io_regs_3 = rf_io_regs_3; // @[Path_ID.scala 35:13]
  assign io_regs_4 = rf_io_regs_4; // @[Path_ID.scala 35:13]
  assign io_regs_5 = rf_io_regs_5; // @[Path_ID.scala 35:13]
  assign io_regs_6 = rf_io_regs_6; // @[Path_ID.scala 35:13]
  assign io_regs_7 = rf_io_regs_7; // @[Path_ID.scala 35:13]
  assign io_regs_8 = rf_io_regs_8; // @[Path_ID.scala 35:13]
  assign io_regs_9 = rf_io_regs_9; // @[Path_ID.scala 35:13]
  assign io_regs_10 = rf_io_regs_10; // @[Path_ID.scala 35:13]
  assign io_regs_11 = rf_io_regs_11; // @[Path_ID.scala 35:13]
  assign io_regs_12 = rf_io_regs_12; // @[Path_ID.scala 35:13]
  assign io_regs_13 = rf_io_regs_13; // @[Path_ID.scala 35:13]
  assign io_regs_14 = rf_io_regs_14; // @[Path_ID.scala 35:13]
  assign io_regs_15 = rf_io_regs_15; // @[Path_ID.scala 35:13]
  assign io_regs_16 = rf_io_regs_16; // @[Path_ID.scala 35:13]
  assign io_regs_17 = rf_io_regs_17; // @[Path_ID.scala 35:13]
  assign io_regs_18 = rf_io_regs_18; // @[Path_ID.scala 35:13]
  assign io_regs_19 = rf_io_regs_19; // @[Path_ID.scala 35:13]
  assign io_regs_20 = rf_io_regs_20; // @[Path_ID.scala 35:13]
  assign io_regs_21 = rf_io_regs_21; // @[Path_ID.scala 35:13]
  assign io_regs_22 = rf_io_regs_22; // @[Path_ID.scala 35:13]
  assign io_regs_23 = rf_io_regs_23; // @[Path_ID.scala 35:13]
  assign io_regs_24 = rf_io_regs_24; // @[Path_ID.scala 35:13]
  assign io_regs_25 = rf_io_regs_25; // @[Path_ID.scala 35:13]
  assign io_regs_26 = rf_io_regs_26; // @[Path_ID.scala 35:13]
  assign io_regs_27 = rf_io_regs_27; // @[Path_ID.scala 35:13]
  assign io_regs_28 = rf_io_regs_28; // @[Path_ID.scala 35:13]
  assign io_regs_29 = rf_io_regs_29; // @[Path_ID.scala 35:13]
  assign io_regs_30 = rf_io_regs_30; // @[Path_ID.scala 35:13]
  assign io_regs_31 = rf_io_regs_31; // @[Path_ID.scala 35:13]
  assign rf_clock = clock;
  assign rf_reset = reset;
  assign rf_io_wen = io_WB_RegWEn; // @[Path_ID.scala 28:15]
  assign rf_io_waddr = io_WB_index; // @[Path_ID.scala 29:17]
  assign rf_io_wdata = io_WB_wdata; // @[Path_ID.scala 30:17]
  assign rf_io_raddr_0 = io_ID_inst_in[19:15]; // @[Path_ID.scala 23:34]
  assign rf_io_raddr_1 = io_ID_inst_in[24:20]; // @[Path_ID.scala 24:34]
  assign ig_io_inst_31_7 = io_ID_inst_in[31:7]; // @[Path_ID.scala 40:37]
  assign ig_io_ImmSel = io_ImmSel; // @[Path_ID.scala 39:18]
endmodule
module BranchComp(
  input         io_BrUn,
  input  [31:0] io_src1,
  input  [31:0] io_src2,
  output        io_BrEq,
  output        io_BrLT
);
  wire  _T = io_src1 < io_src2; // @[BranchComp.scala 20:20]
  wire  _T_3 = $signed(io_src1) < $signed(io_src2); // @[BranchComp.scala 22:27]
  assign io_BrEq = io_src1 == io_src2; // @[BranchComp.scala 25:22]
  assign io_BrLT = io_BrUn ? _T : _T_3; // @[BranchComp.scala 19:18]
endmodule
module ALU(
  input  [31:0] io_src1,
  input  [31:0] io_src2,
  input  [14:0] io_ALUSel,
  output [31:0] io_out
);
  wire [31:0] _io_out_T_1 = io_src1 + io_src2; // @[ALU.scala 21:31]
  wire [62:0] _GEN_11 = {{31'd0}, io_src1}; // @[ALU.scala 22:32]
  wire [62:0] _io_out_T_3 = _GEN_11 << io_src2[4:0]; // @[ALU.scala 22:32]
  wire [31:0] _io_out_T_4 = io_src1; // @[ALU.scala 23:36]
  wire [31:0] _io_out_T_5 = io_src2; // @[ALU.scala 23:53]
  wire [31:0] _io_out_T_10 = io_src1 ^ io_src2; // @[ALU.scala 25:31]
  wire [31:0] _io_out_T_12 = io_src1 >> io_src2[4:0]; // @[ALU.scala 26:32]
  wire [31:0] _io_out_T_13 = io_src1 | io_src2; // @[ALU.scala 27:31]
  wire [31:0] _io_out_T_14 = io_src1 & io_src2; // @[ALU.scala 28:31]
  wire [31:0] _io_out_T_16 = io_src1 - io_src2; // @[ALU.scala 29:31]
  wire [31:0] _io_out_T_20 = $signed(io_src1) >>> io_src2[4:0]; // @[ALU.scala 30:57]
  wire [63:0] _io_out_T_21 = io_src1 * io_src2; // @[ALU.scala 31:32]
  wire [63:0] _GEN_0 = 15'h1f8 == io_ALUSel ? _io_out_T_21 : 64'h0; // @[ALU.scala 19:10 20:20 31:21]
  wire [63:0] _GEN_1 = 15'h20fd == io_ALUSel ? {{32'd0}, _io_out_T_20} : _GEN_0; // @[ALU.scala 20:20 30:21]
  wire [63:0] _GEN_2 = 15'h20f8 == io_ALUSel ? {{32'd0}, _io_out_T_16} : _GEN_1; // @[ALU.scala 20:20 29:21]
  wire [63:0] _GEN_3 = 15'hff == io_ALUSel ? {{32'd0}, _io_out_T_14} : _GEN_2; // @[ALU.scala 20:20 28:21]
  wire [63:0] _GEN_4 = 15'hfe == io_ALUSel ? {{32'd0}, _io_out_T_13} : _GEN_3; // @[ALU.scala 20:20 27:21]
  wire [63:0] _GEN_5 = 15'hfd == io_ALUSel ? {{32'd0}, _io_out_T_12} : _GEN_4; // @[ALU.scala 20:20 26:21]
  wire [63:0] _GEN_6 = 15'hfc == io_ALUSel ? {{32'd0}, _io_out_T_10} : _GEN_5; // @[ALU.scala 20:20 25:21]
  wire [63:0] _GEN_7 = 15'hfb == io_ALUSel ? {{63'd0}, io_src1 < io_src2} : _GEN_6; // @[ALU.scala 20:20 24:21]
  wire [63:0] _GEN_8 = 15'hfa == io_ALUSel ? {{63'd0}, $signed(_io_out_T_4) < $signed(_io_out_T_5)} : _GEN_7; // @[ALU.scala 20:20 23:21]
  wire [63:0] _GEN_9 = 15'hf9 == io_ALUSel ? {{1'd0}, _io_out_T_3} : _GEN_8; // @[ALU.scala 20:20 22:21]
  wire [63:0] _GEN_10 = 15'hf8 == io_ALUSel ? {{32'd0}, _io_out_T_1} : _GEN_9; // @[ALU.scala 20:20 21:21]
  assign io_out = _GEN_10[31:0];
endmodule
module Path_EXE(
  input  [31:0] io_EXE_pc_in,
  input  [31:0] io_EXE_imm_in,
  input  [31:0] io_EXE_rs1_rdata_in,
  input  [31:0] io_EXE_rs2_rdata_in,
  input  [1:0]  io_E_ASel,
  input         io_E_BSel,
  input         io_E_BrUn,
  input  [14:0] io_E_ALUSel,
  output [31:0] io_EXE_target_pc_out,
  output [31:0] io_EXE_alu_out,
  output [31:0] io_EXE_rs2_rdata_out,
  output        io_E_BrEq,
  output        io_E_BrLT,
  output [31:0] io_alu_src1,
  output [31:0] io_alu_src2,
  output [31:0] io_EXE_src1,
  output [31:0] io_EXE_src2
);
  wire  bc_io_BrUn; // @[Path_EXE.scala 36:20]
  wire [31:0] bc_io_src1; // @[Path_EXE.scala 36:20]
  wire [31:0] bc_io_src2; // @[Path_EXE.scala 36:20]
  wire  bc_io_BrEq; // @[Path_EXE.scala 36:20]
  wire  bc_io_BrLT; // @[Path_EXE.scala 36:20]
  wire [31:0] alu_io_src1; // @[Path_EXE.scala 44:21]
  wire [31:0] alu_io_src2; // @[Path_EXE.scala 44:21]
  wire [14:0] alu_io_ALUSel; // @[Path_EXE.scala 44:21]
  wire [31:0] alu_io_out; // @[Path_EXE.scala 44:21]
  wire [31:0] _alu_src1_T_3 = 2'h1 == io_E_ASel ? io_EXE_pc_in : io_EXE_rs1_rdata_in; // @[Mux.scala 81:58]
  BranchComp bc ( // @[Path_EXE.scala 36:20]
    .io_BrUn(bc_io_BrUn),
    .io_src1(bc_io_src1),
    .io_src2(bc_io_src2),
    .io_BrEq(bc_io_BrEq),
    .io_BrLT(bc_io_BrLT)
  );
  ALU alu ( // @[Path_EXE.scala 44:21]
    .io_src1(alu_io_src1),
    .io_src2(alu_io_src2),
    .io_ALUSel(alu_io_ALUSel),
    .io_out(alu_io_out)
  );
  assign io_EXE_target_pc_out = alu_io_out; // @[Path_EXE.scala 61:39]
  assign io_EXE_alu_out = alu_io_out; // @[Path_EXE.scala 57:20]
  assign io_EXE_rs2_rdata_out = io_EXE_rs2_rdata_in; // @[Path_EXE.scala 60:26]
  assign io_E_BrEq = bc_io_BrEq; // @[Path_EXE.scala 40:15]
  assign io_E_BrLT = bc_io_BrLT; // @[Path_EXE.scala 41:15]
  assign io_alu_src1 = 2'h2 == io_E_ASel ? 32'h0 : _alu_src1_T_3; // @[Mux.scala 81:58]
  assign io_alu_src2 = io_E_BSel ? io_EXE_imm_in : io_EXE_rs2_rdata_in; // @[Mux.scala 81:58]
  assign io_EXE_src1 = io_EXE_rs1_rdata_in; // @[Path_EXE.scala 64:17]
  assign io_EXE_src2 = io_EXE_rs2_rdata_in; // @[Path_EXE.scala 65:17]
  assign bc_io_BrUn = io_E_BrUn; // @[Path_EXE.scala 37:16]
  assign bc_io_src1 = io_EXE_rs1_rdata_in; // @[Path_EXE.scala 38:16]
  assign bc_io_src2 = io_EXE_rs2_rdata_in; // @[Path_EXE.scala 39:16]
  assign alu_io_src1 = 2'h2 == io_E_ASel ? 32'h0 : _alu_src1_T_3; // @[Mux.scala 81:58]
  assign alu_io_src2 = io_E_BSel ? io_EXE_imm_in : io_EXE_rs2_rdata_in; // @[Mux.scala 81:58]
  assign alu_io_ALUSel = io_E_ALUSel; // @[Path_EXE.scala 56:19]
endmodule
module Path_MEM(
  input  [31:0] io_MEM_pc_in,
  input  [31:0] io_MEM_alu_out_in,
  input  [31:0] io_MEM_DM_wdata_in,
  output [31:0] io_MEM_pc_plus_4,
  output [31:0] io_MEM_alu_out,
  output [31:0] io_MEM_ld_data,
  output [31:0] io_Mem_Addr,
  output [31:0] io_Mem_Write_Data,
  input  [31:0] io_Mem_Data
);
  assign io_MEM_pc_plus_4 = io_MEM_pc_in + 32'h4; // @[Path_MEM.scala 24:38]
  assign io_MEM_alu_out = io_MEM_alu_out_in; // @[Path_MEM.scala 32:20]
  assign io_MEM_ld_data = io_Mem_Data; // @[Path_MEM.scala 29:20]
  assign io_Mem_Addr = io_MEM_alu_out_in; // @[Path_MEM.scala 27:37]
  assign io_Mem_Write_Data = io_MEM_DM_wdata_in; // @[Path_MEM.scala 28:23]
endmodule
module Path_WB(
  input  [31:0] io_WB_pc_plus4_in,
  input  [31:0] io_WB_alu_out_in,
  input  [31:0] io_WB_ld_data_in,
  input  [1:0]  io_W_WBSel,
  output [31:0] io_WB_wdata
);
  wire [31:0] _io_WB_wdata_T_1 = 2'h0 == io_W_WBSel ? io_WB_pc_plus4_in : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _io_WB_wdata_T_3 = 2'h1 == io_W_WBSel ? io_WB_alu_out_in : _io_WB_wdata_T_1; // @[Mux.scala 81:58]
  assign io_WB_wdata = 2'h2 == io_W_WBSel ? io_WB_ld_data_in : _io_WB_wdata_T_3; // @[Mux.scala 81:58]
endmodule
module Controller(
  output        io_DM_Mem_R,
  output        io_DM_Mem_W,
  output [3:0]  io_DM_Length,
  input         io_E_BrEq,
  input         io_E_BrLT,
  output        io_E_Branch_taken,
  input  [31:0] io_ID_pc,
  input  [31:0] io_EXE_target_pc,
  output        io_Flush_WB_ID_DH,
  output        io_Flush_BH,
  output        io_Stall_WB_ID_DH,
  input  [31:0] io_IF_Inst,
  input  [31:0] io_ID_Inst,
  input  [31:0] io_EXE_Inst,
  input  [31:0] io_MEM_Inst,
  input  [31:0] io_WB_Inst,
  output [1:0]  io_PCSel,
  output [2:0]  io_D_ImmSel,
  output        io_W_RegWEn,
  output        io_E_BrUn,
  output [1:0]  io_E_ASel,
  output        io_E_BSel,
  output [14:0] io_E_ALUSel,
  output [1:0]  io_W_WBSel,
  output        io_Hcf
);
  wire [6:0] IF_opcode = io_IF_Inst[6:0]; // @[Controller.scala 67:29]
  wire [6:0] ID_opcode = io_ID_Inst[6:0]; // @[Controller.scala 69:29]
  wire [6:0] EXE_opcode = io_EXE_Inst[6:0]; // @[Controller.scala 71:31]
  wire [2:0] EXE_funct3 = io_EXE_Inst[14:12]; // @[Controller.scala 72:31]
  wire [6:0] EXE_funct7 = io_EXE_Inst[31:25]; // @[Controller.scala 73:31]
  wire [6:0] MEM_opcode = io_MEM_Inst[6:0]; // @[Controller.scala 75:31]
  wire [2:0] MEM_funct3 = io_MEM_Inst[14:12]; // @[Controller.scala 76:31]
  wire [6:0] WB_opcode = io_WB_Inst[6:0]; // @[Controller.scala 78:29]
  wire  _E_Branch_taken_T = ~io_E_BrEq; // @[Controller.scala 88:31]
  wire  _E_Branch_taken_T_1 = ~io_E_BrLT; // @[Controller.scala 90:31]
  wire  _E_Branch_taken_T_6 = 3'h1 == EXE_funct3 ? _E_Branch_taken_T : 3'h0 == EXE_funct3 & io_E_BrEq; // @[Mux.scala 81:58]
  wire  _E_Branch_taken_T_8 = 3'h4 == EXE_funct3 ? io_E_BrLT : _E_Branch_taken_T_6; // @[Mux.scala 81:58]
  wire  _E_Branch_taken_T_10 = 3'h5 == EXE_funct3 ? _E_Branch_taken_T_1 : _E_Branch_taken_T_8; // @[Mux.scala 81:58]
  wire  _E_Branch_taken_T_12 = 3'h6 == EXE_funct3 ? io_E_BrLT : _E_Branch_taken_T_10; // @[Mux.scala 81:58]
  wire  _E_Branch_taken_T_14 = 3'h7 == EXE_funct3 ? _E_Branch_taken_T_1 : _E_Branch_taken_T_12; // @[Mux.scala 81:58]
  wire  E_Branch_taken = 7'h6f == EXE_opcode | (7'h67 == EXE_opcode | 7'h63 == EXE_opcode & _E_Branch_taken_T_14); // @[Mux.scala 81:58]
  wire  Predict_Miss = E_Branch_taken & io_ID_pc != io_EXE_target_pc; // @[Controller.scala 103:35]
  wire [1:0] _io_D_ImmSel_T_3 = 7'h23 == ID_opcode ? 2'h2 : {{1'd0}, 7'h3 == ID_opcode}; // @[Mux.scala 81:58]
  wire [1:0] _io_D_ImmSel_T_5 = 7'h63 == ID_opcode ? 2'h3 : _io_D_ImmSel_T_3; // @[Mux.scala 81:58]
  wire [1:0] _io_D_ImmSel_T_7 = 7'h67 == ID_opcode ? 2'h1 : _io_D_ImmSel_T_5; // @[Mux.scala 81:58]
  wire [2:0] _io_D_ImmSel_T_9 = 7'h6f == ID_opcode ? 3'h4 : {{1'd0}, _io_D_ImmSel_T_7}; // @[Mux.scala 81:58]
  wire [2:0] _io_D_ImmSel_T_11 = 7'h13 == ID_opcode ? 3'h1 : _io_D_ImmSel_T_9; // @[Mux.scala 81:58]
  wire [2:0] _io_D_ImmSel_T_13 = 7'h33 == ID_opcode ? 3'h0 : _io_D_ImmSel_T_11; // @[Mux.scala 81:58]
  wire [2:0] _io_D_ImmSel_T_15 = 7'h17 == ID_opcode ? 3'h5 : _io_D_ImmSel_T_13; // @[Mux.scala 81:58]
  wire  _io_E_ASel_T_3 = 7'h17 == EXE_opcode | 7'h63 == EXE_opcode; // @[Mux.scala 81:58]
  wire [1:0] _io_E_ASel_T_5 = 7'h37 == EXE_opcode ? 2'h2 : {{1'd0}, _io_E_ASel_T_3}; // @[Mux.scala 81:58]
  wire [14:0] _io_E_ALUSel_T_1 = {EXE_funct7,5'h1f,EXE_funct3}; // @[Cat.scala 33:92]
  wire [14:0] _io_E_ALUSel_T_2 = {12'h1f,EXE_funct3}; // @[Cat.scala 33:92]
  wire [14:0] _io_E_ALUSel_T_5 = 3'h5 == EXE_funct3 ? _io_E_ALUSel_T_1 : _io_E_ALUSel_T_2; // @[Mux.scala 81:58]
  wire [14:0] _io_E_ALUSel_T_7 = 7'h33 == EXE_opcode ? _io_E_ALUSel_T_1 : 15'hf8; // @[Mux.scala 81:58]
  wire  _io_W_WBSel_T_1 = 7'h6f == WB_opcode ? 1'h0 : 1'h1; // @[Mux.scala 81:58]
  wire  _io_W_WBSel_T_3 = 7'h67 == WB_opcode ? 1'h0 : _io_W_WBSel_T_1; // @[Mux.scala 81:58]
  wire  _io_W_WBSel_T_11 = 7'h17 == WB_opcode | (7'h37 == WB_opcode | (7'h13 == WB_opcode | (7'h33 == WB_opcode |
    _io_W_WBSel_T_3))); // @[Mux.scala 81:58]
  wire  is_D_use_rs1 = 7'h23 == ID_opcode | (7'h3 == ID_opcode | (7'h67 == ID_opcode | (7'h63 == ID_opcode | (7'h13 ==
    ID_opcode | 7'h33 == ID_opcode)))); // @[Mux.scala 81:58]
  wire  is_D_use_rs2 = 7'h23 == ID_opcode | (7'h63 == ID_opcode | 7'h33 == ID_opcode); // @[Mux.scala 81:58]
  wire  is_E_use_rd = 7'h3 == EXE_opcode | (7'h67 == EXE_opcode | (7'h6f == EXE_opcode | (7'h37 == EXE_opcode | (7'h17
     == EXE_opcode | (7'h13 == EXE_opcode | 7'h33 == EXE_opcode))))); // @[Mux.scala 81:58]
  wire  is_M_use_rd = 7'h3 == MEM_opcode | (7'h67 == MEM_opcode | (7'h6f == MEM_opcode | (7'h37 == MEM_opcode | (7'h17
     == MEM_opcode | (7'h13 == MEM_opcode | 7'h33 == MEM_opcode))))); // @[Mux.scala 81:58]
  wire  is_W_use_rd = 7'h3 == WB_opcode | (7'h67 == WB_opcode | (7'h6f == WB_opcode | (7'h37 == WB_opcode | (7'h17 ==
    WB_opcode | (7'h13 == WB_opcode | 7'h33 == WB_opcode))))); // @[Mux.scala 81:58]
  wire [4:0] ID_rs1 = io_ID_Inst[19:15]; // @[Controller.scala 258:26]
  wire [4:0] ID_rs2 = io_ID_Inst[24:20]; // @[Controller.scala 259:26]
  wire [4:0] EXE_rd = io_EXE_Inst[11:7]; // @[Controller.scala 261:27]
  wire [4:0] MEM_rd = io_MEM_Inst[11:7]; // @[Controller.scala 262:27]
  wire [4:0] WB_rd = io_WB_Inst[11:7]; // @[Controller.scala 263:25]
  wire  _is_D_rs1_E_rd_overlap_T_3 = EXE_rd != 5'h0; // @[Controller.scala 265:90]
  wire  is_D_rs1_E_rd_overlap = is_D_use_rs1 & is_E_use_rd & ID_rs1 == EXE_rd & EXE_rd != 5'h0; // @[Controller.scala 265:79]
  wire  is_D_rs2_E_rd_overlap = is_D_use_rs2 & is_E_use_rd & ID_rs2 == EXE_rd & _is_D_rs1_E_rd_overlap_T_3; // @[Controller.scala 266:79]
  wire  _is_D_rs1_M_rd_overlap_T_3 = MEM_rd != 5'h0; // @[Controller.scala 268:90]
  wire  is_D_rs1_M_rd_overlap = is_D_use_rs1 & is_M_use_rd & ID_rs1 == MEM_rd & MEM_rd != 5'h0; // @[Controller.scala 268:79]
  wire  is_D_rs2_M_rd_overlap = is_D_use_rs2 & is_M_use_rd & ID_rs2 == MEM_rd & _is_D_rs1_M_rd_overlap_T_3; // @[Controller.scala 269:79]
  wire  _is_D_rs1_W_rd_overlap_T_3 = WB_rd != 5'h0; // @[Controller.scala 271:88]
  wire  is_D_rs1_W_rd_overlap = is_D_use_rs1 & is_W_use_rd & ID_rs1 == WB_rd & WB_rd != 5'h0; // @[Controller.scala 271:78]
  wire  is_D_rs2_W_rd_overlap = is_D_use_rs2 & is_W_use_rd & ID_rs2 == WB_rd & _is_D_rs1_W_rd_overlap_T_3; // @[Controller.scala 272:78]
  wire  _io_Stall_WB_ID_DH_T_1 = is_D_rs1_E_rd_overlap | is_D_rs2_E_rd_overlap | is_D_rs1_M_rd_overlap; // @[Controller.scala 276:72]
  assign io_DM_Mem_R = MEM_opcode == 7'h3; // @[Controller.scala 156:29]
  assign io_DM_Mem_W = MEM_opcode == 7'h23; // @[Controller.scala 157:29]
  assign io_DM_Length = {1'h0,MEM_funct3}; // @[Cat.scala 33:92]
  assign io_E_Branch_taken = 7'h6f == EXE_opcode | (7'h67 == EXE_opcode | 7'h63 == EXE_opcode & _E_Branch_taken_T_14); // @[Mux.scala 81:58]
  assign io_Flush_WB_ID_DH = io_Stall_WB_ID_DH; // @[Controller.scala 278:21]
  assign io_Flush_BH = E_Branch_taken & io_ID_pc != io_EXE_target_pc; // @[Controller.scala 103:35]
  assign io_Stall_WB_ID_DH = _io_Stall_WB_ID_DH_T_1 | is_D_rs2_M_rd_overlap | is_D_rs1_W_rd_overlap |
    is_D_rs2_W_rd_overlap; // @[Controller.scala 277:75]
  assign io_PCSel = Predict_Miss ? 2'h2 : 2'h0; // @[Controller.scala 106:21 107:14 109:14]
  assign io_D_ImmSel = 7'h37 == ID_opcode ? 3'h5 : _io_D_ImmSel_T_15; // @[Mux.scala 81:58]
  assign io_W_RegWEn = 7'h67 == WB_opcode | (7'h6f == WB_opcode | (7'h17 == WB_opcode | (7'h37 == WB_opcode | (7'h3 ==
    WB_opcode | (7'h13 == WB_opcode | 7'h33 == WB_opcode))))); // @[Mux.scala 81:58]
  assign io_E_BrUn = io_EXE_Inst[13]; // @[Controller.scala 113:28]
  assign io_E_ASel = 7'h6f == EXE_opcode ? 2'h1 : _io_E_ASel_T_5; // @[Mux.scala 81:58]
  assign io_E_BSel = 7'h3 == EXE_opcode | (7'h37 == EXE_opcode | (7'h17 == EXE_opcode | (7'h13 == EXE_opcode | (7'h67
     == EXE_opcode | (7'h6f == EXE_opcode | (7'h63 == EXE_opcode | (7'h23 == EXE_opcode | 7'h3 == EXE_opcode))))))); // @[Mux.scala 81:58]
  assign io_E_ALUSel = 7'h13 == EXE_opcode ? _io_E_ALUSel_T_5 : _io_E_ALUSel_T_7; // @[Mux.scala 81:58]
  assign io_W_WBSel = 7'h3 == WB_opcode ? 2'h2 : {{1'd0}, _io_W_WBSel_T_11}; // @[Mux.scala 81:58]
  assign io_Hcf = IF_opcode == 7'hb; // @[Controller.scala 188:24]
endmodule
module PipelinedCPU(
  input         clock,
  input         reset,
  output [14:0] io_InstMem_raddr,
  input  [31:0] io_InstMem_rdata,
  output        io_DataMem_Mem_R,
  output        io_DataMem_Mem_W,
  output [3:0]  io_DataMem_Length,
  output [31:0] io_DataMem_raddr,
  output [31:0] io_DataMem_waddr,
  output [31:0] io_DataMem_wdata,
  input         io_master_aw_ready,
  output        io_master_aw_valid,
  output [31:0] io_master_aw_bits_addr,
  input         io_master_w_ready,
  output        io_master_w_valid,
  output [31:0] io_master_w_bits_data,
  output [3:0]  io_master_w_bits_strb,
  output        io_master_b_ready,
  input         io_master_b_valid,
  input         io_master_ar_ready,
  output        io_master_ar_valid,
  output [31:0] io_master_ar_bits_addr,
  output        io_master_r_ready,
  input         io_master_r_valid,
  input  [31:0] io_master_r_bits_data,
  output [31:0] io_regs_1,
  output [31:0] io_regs_2,
  output [31:0] io_regs_3,
  output [31:0] io_regs_4,
  output [31:0] io_regs_5,
  output [31:0] io_regs_6,
  output [31:0] io_regs_7,
  output [31:0] io_regs_8,
  output [31:0] io_regs_9,
  output [31:0] io_regs_10,
  output [31:0] io_regs_11,
  output [31:0] io_regs_12,
  output [31:0] io_regs_13,
  output [31:0] io_regs_14,
  output [31:0] io_regs_15,
  output [31:0] io_regs_16,
  output [31:0] io_regs_17,
  output [31:0] io_regs_18,
  output [31:0] io_regs_19,
  output [31:0] io_regs_20,
  output [31:0] io_regs_21,
  output [31:0] io_regs_22,
  output [31:0] io_regs_23,
  output [31:0] io_regs_24,
  output [31:0] io_regs_25,
  output [31:0] io_regs_26,
  output [31:0] io_regs_27,
  output [31:0] io_regs_28,
  output [31:0] io_regs_29,
  output [31:0] io_regs_30,
  output [31:0] io_regs_31,
  output        io_Hcf,
  input         io_DMA_Hcf,
  output        io_E_Branch_taken,
  output        io_Flush,
  output        io_Stall_MA,
  output        io_Stall_DH,
  output [31:0] io_IF_PC,
  output [31:0] io_ID_PC,
  output [31:0] io_EXE_PC,
  output [31:0] io_MEM_PC,
  output [31:0] io_WB_PC,
  output [31:0] io_EXE_src1,
  output [31:0] io_EXE_src2,
  output [31:0] io_ALU_src1,
  output [31:0] io_ALU_src2,
  output [31:0] io_EXE_alu_out,
  output [4:0]  io_WB_rd,
  output [31:0] io_WB_wdata,
  output        io_EXE_Jump,
  output        io_EXE_Branch
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  wire  stage_IF_clock; // @[PiplinedCPU.scala 52:26]
  wire  stage_IF_reset; // @[PiplinedCPU.scala 52:26]
  wire  stage_IF_io_Stall; // @[PiplinedCPU.scala 52:26]
  wire [31:0] stage_IF_io_next_pc_in; // @[PiplinedCPU.scala 52:26]
  wire [31:0] stage_IF_io_pc; // @[PiplinedCPU.scala 52:26]
  wire  stage_ID_clock; // @[PiplinedCPU.scala 53:26]
  wire  stage_ID_reset; // @[PiplinedCPU.scala 53:26]
  wire  stage_ID_io_Flush; // @[PiplinedCPU.scala 53:26]
  wire  stage_ID_io_Stall; // @[PiplinedCPU.scala 53:26]
  wire [31:0] stage_ID_io_pc_in; // @[PiplinedCPU.scala 53:26]
  wire [31:0] stage_ID_io_inst_in; // @[PiplinedCPU.scala 53:26]
  wire [31:0] stage_ID_io_pc; // @[PiplinedCPU.scala 53:26]
  wire [31:0] stage_ID_io_inst; // @[PiplinedCPU.scala 53:26]
  wire  stage_EXE_clock; // @[PiplinedCPU.scala 54:27]
  wire  stage_EXE_reset; // @[PiplinedCPU.scala 54:27]
  wire  stage_EXE_io_Flush; // @[PiplinedCPU.scala 54:27]
  wire  stage_EXE_io_Stall; // @[PiplinedCPU.scala 54:27]
  wire [31:0] stage_EXE_io_inst_in; // @[PiplinedCPU.scala 54:27]
  wire [31:0] stage_EXE_io_pc_in; // @[PiplinedCPU.scala 54:27]
  wire [31:0] stage_EXE_io_rs1_rdata_in; // @[PiplinedCPU.scala 54:27]
  wire [31:0] stage_EXE_io_rs2_rdata_in; // @[PiplinedCPU.scala 54:27]
  wire [31:0] stage_EXE_io_imm_in; // @[PiplinedCPU.scala 54:27]
  wire [31:0] stage_EXE_io_inst; // @[PiplinedCPU.scala 54:27]
  wire [31:0] stage_EXE_io_pc; // @[PiplinedCPU.scala 54:27]
  wire [31:0] stage_EXE_io_rs1_rdata; // @[PiplinedCPU.scala 54:27]
  wire [31:0] stage_EXE_io_rs2_rdata; // @[PiplinedCPU.scala 54:27]
  wire [31:0] stage_EXE_io_imm; // @[PiplinedCPU.scala 54:27]
  wire  stage_MEM_clock; // @[PiplinedCPU.scala 55:27]
  wire  stage_MEM_reset; // @[PiplinedCPU.scala 55:27]
  wire  stage_MEM_io_Stall; // @[PiplinedCPU.scala 55:27]
  wire [31:0] stage_MEM_io_pc_in; // @[PiplinedCPU.scala 55:27]
  wire [31:0] stage_MEM_io_inst_in; // @[PiplinedCPU.scala 55:27]
  wire [31:0] stage_MEM_io_alu_out_in; // @[PiplinedCPU.scala 55:27]
  wire [31:0] stage_MEM_io_DM_wdata_in; // @[PiplinedCPU.scala 55:27]
  wire [31:0] stage_MEM_io_pc; // @[PiplinedCPU.scala 55:27]
  wire [31:0] stage_MEM_io_inst; // @[PiplinedCPU.scala 55:27]
  wire [31:0] stage_MEM_io_alu_out; // @[PiplinedCPU.scala 55:27]
  wire [31:0] stage_MEM_io_DM_wdata; // @[PiplinedCPU.scala 55:27]
  wire  stage_WB_clock; // @[PiplinedCPU.scala 56:26]
  wire  stage_WB_reset; // @[PiplinedCPU.scala 56:26]
  wire  stage_WB_io_Stall; // @[PiplinedCPU.scala 56:26]
  wire [31:0] stage_WB_io_pc_plus4_in; // @[PiplinedCPU.scala 56:26]
  wire [31:0] stage_WB_io_inst_in; // @[PiplinedCPU.scala 56:26]
  wire [31:0] stage_WB_io_alu_out_in; // @[PiplinedCPU.scala 56:26]
  wire [31:0] stage_WB_io_ld_data_in; // @[PiplinedCPU.scala 56:26]
  wire [31:0] stage_WB_io_pc_plus4; // @[PiplinedCPU.scala 56:26]
  wire [31:0] stage_WB_io_inst; // @[PiplinedCPU.scala 56:26]
  wire [31:0] stage_WB_io_alu_out; // @[PiplinedCPU.scala 56:26]
  wire [31:0] stage_WB_io_ld_data; // @[PiplinedCPU.scala 56:26]
  wire [1:0] datapath_IF_io_PCSel; // @[PiplinedCPU.scala 59:29]
  wire [31:0] datapath_IF_io_IF_pc_in; // @[PiplinedCPU.scala 59:29]
  wire [31:0] datapath_IF_io_EXE_pc_in; // @[PiplinedCPU.scala 59:29]
  wire [31:0] datapath_IF_io_EXE_target_pc_in; // @[PiplinedCPU.scala 59:29]
  wire [31:0] datapath_IF_io_Mem_data; // @[PiplinedCPU.scala 59:29]
  wire [31:0] datapath_IF_io_next_pc; // @[PiplinedCPU.scala 59:29]
  wire [31:0] datapath_IF_io_Mem_Addr; // @[PiplinedCPU.scala 59:29]
  wire [31:0] datapath_IF_io_inst; // @[PiplinedCPU.scala 59:29]
  wire  datapath_ID_clock; // @[PiplinedCPU.scala 60:29]
  wire  datapath_ID_reset; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_ID_inst_in; // @[PiplinedCPU.scala 60:29]
  wire [4:0] datapath_ID_io_WB_index; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_WB_wdata; // @[PiplinedCPU.scala 60:29]
  wire  datapath_ID_io_WB_RegWEn; // @[PiplinedCPU.scala 60:29]
  wire [2:0] datapath_ID_io_ImmSel; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_ID_rs1_rdata; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_ID_rs2_rdata; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_imm; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_1; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_2; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_3; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_4; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_5; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_6; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_7; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_8; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_9; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_10; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_11; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_12; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_13; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_14; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_15; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_16; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_17; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_18; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_19; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_20; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_21; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_22; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_23; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_24; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_25; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_26; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_27; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_28; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_29; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_30; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_ID_io_regs_31; // @[PiplinedCPU.scala 60:29]
  wire [31:0] datapath_EXE_io_EXE_pc_in; // @[PiplinedCPU.scala 61:30]
  wire [31:0] datapath_EXE_io_EXE_imm_in; // @[PiplinedCPU.scala 61:30]
  wire [31:0] datapath_EXE_io_EXE_rs1_rdata_in; // @[PiplinedCPU.scala 61:30]
  wire [31:0] datapath_EXE_io_EXE_rs2_rdata_in; // @[PiplinedCPU.scala 61:30]
  wire [1:0] datapath_EXE_io_E_ASel; // @[PiplinedCPU.scala 61:30]
  wire  datapath_EXE_io_E_BSel; // @[PiplinedCPU.scala 61:30]
  wire  datapath_EXE_io_E_BrUn; // @[PiplinedCPU.scala 61:30]
  wire [14:0] datapath_EXE_io_E_ALUSel; // @[PiplinedCPU.scala 61:30]
  wire [31:0] datapath_EXE_io_EXE_target_pc_out; // @[PiplinedCPU.scala 61:30]
  wire [31:0] datapath_EXE_io_EXE_alu_out; // @[PiplinedCPU.scala 61:30]
  wire [31:0] datapath_EXE_io_EXE_rs2_rdata_out; // @[PiplinedCPU.scala 61:30]
  wire  datapath_EXE_io_E_BrEq; // @[PiplinedCPU.scala 61:30]
  wire  datapath_EXE_io_E_BrLT; // @[PiplinedCPU.scala 61:30]
  wire [31:0] datapath_EXE_io_alu_src1; // @[PiplinedCPU.scala 61:30]
  wire [31:0] datapath_EXE_io_alu_src2; // @[PiplinedCPU.scala 61:30]
  wire [31:0] datapath_EXE_io_EXE_src1; // @[PiplinedCPU.scala 61:30]
  wire [31:0] datapath_EXE_io_EXE_src2; // @[PiplinedCPU.scala 61:30]
  wire [31:0] datapath_MEM_io_MEM_pc_in; // @[PiplinedCPU.scala 62:30]
  wire [31:0] datapath_MEM_io_MEM_alu_out_in; // @[PiplinedCPU.scala 62:30]
  wire [31:0] datapath_MEM_io_MEM_DM_wdata_in; // @[PiplinedCPU.scala 62:30]
  wire [31:0] datapath_MEM_io_MEM_pc_plus_4; // @[PiplinedCPU.scala 62:30]
  wire [31:0] datapath_MEM_io_MEM_alu_out; // @[PiplinedCPU.scala 62:30]
  wire [31:0] datapath_MEM_io_MEM_ld_data; // @[PiplinedCPU.scala 62:30]
  wire [31:0] datapath_MEM_io_Mem_Addr; // @[PiplinedCPU.scala 62:30]
  wire [31:0] datapath_MEM_io_Mem_Write_Data; // @[PiplinedCPU.scala 62:30]
  wire [31:0] datapath_MEM_io_Mem_Data; // @[PiplinedCPU.scala 62:30]
  wire [31:0] datapath_WB_io_WB_pc_plus4_in; // @[PiplinedCPU.scala 63:29]
  wire [31:0] datapath_WB_io_WB_alu_out_in; // @[PiplinedCPU.scala 63:29]
  wire [31:0] datapath_WB_io_WB_ld_data_in; // @[PiplinedCPU.scala 63:29]
  wire [1:0] datapath_WB_io_W_WBSel; // @[PiplinedCPU.scala 63:29]
  wire [31:0] datapath_WB_io_WB_wdata; // @[PiplinedCPU.scala 63:29]
  wire  contorller_io_DM_Mem_R; // @[PiplinedCPU.scala 66:28]
  wire  contorller_io_DM_Mem_W; // @[PiplinedCPU.scala 66:28]
  wire [3:0] contorller_io_DM_Length; // @[PiplinedCPU.scala 66:28]
  wire  contorller_io_E_BrEq; // @[PiplinedCPU.scala 66:28]
  wire  contorller_io_E_BrLT; // @[PiplinedCPU.scala 66:28]
  wire  contorller_io_E_Branch_taken; // @[PiplinedCPU.scala 66:28]
  wire [31:0] contorller_io_ID_pc; // @[PiplinedCPU.scala 66:28]
  wire [31:0] contorller_io_EXE_target_pc; // @[PiplinedCPU.scala 66:28]
  wire  contorller_io_Flush_WB_ID_DH; // @[PiplinedCPU.scala 66:28]
  wire  contorller_io_Flush_BH; // @[PiplinedCPU.scala 66:28]
  wire  contorller_io_Stall_WB_ID_DH; // @[PiplinedCPU.scala 66:28]
  wire [31:0] contorller_io_IF_Inst; // @[PiplinedCPU.scala 66:28]
  wire [31:0] contorller_io_ID_Inst; // @[PiplinedCPU.scala 66:28]
  wire [31:0] contorller_io_EXE_Inst; // @[PiplinedCPU.scala 66:28]
  wire [31:0] contorller_io_MEM_Inst; // @[PiplinedCPU.scala 66:28]
  wire [31:0] contorller_io_WB_Inst; // @[PiplinedCPU.scala 66:28]
  wire [1:0] contorller_io_PCSel; // @[PiplinedCPU.scala 66:28]
  wire [2:0] contorller_io_D_ImmSel; // @[PiplinedCPU.scala 66:28]
  wire  contorller_io_W_RegWEn; // @[PiplinedCPU.scala 66:28]
  wire  contorller_io_E_BrUn; // @[PiplinedCPU.scala 66:28]
  wire [1:0] contorller_io_E_ASel; // @[PiplinedCPU.scala 66:28]
  wire  contorller_io_E_BSel; // @[PiplinedCPU.scala 66:28]
  wire [14:0] contorller_io_E_ALUSel; // @[PiplinedCPU.scala 66:28]
  wire [1:0] contorller_io_W_WBSel; // @[PiplinedCPU.scala 66:28]
  wire  contorller_io_Hcf; // @[PiplinedCPU.scala 66:28]
  wire [31:0] w_choose_byte = io_DataMem_waddr & 32'h3; // @[PiplinedCPU.scala 69:42]
  wire [31:0] w_choose_half = io_DataMem_waddr & 32'h2; // @[PiplinedCPU.scala 70:42]
  wire [1:0] _io_master_w_bits_strb_T_3 = 32'h1 == w_choose_byte ? 2'h2 : 2'h1; // @[Mux.scala 81:58]
  wire [2:0] _io_master_w_bits_strb_T_5 = 32'h2 == w_choose_byte ? 3'h4 : {{1'd0}, _io_master_w_bits_strb_T_3}; // @[Mux.scala 81:58]
  wire [3:0] _io_master_w_bits_strb_T_7 = 32'h3 == w_choose_byte ? 4'h8 : {{1'd0}, _io_master_w_bits_strb_T_5}; // @[Mux.scala 81:58]
  wire [3:0] _io_master_w_bits_strb_T_11 = 32'h1 == w_choose_half ? 4'hc : 4'h3; // @[Mux.scala 81:58]
  wire [3:0] _io_master_w_bits_strb_T_13 = 4'h0 == io_DataMem_Length ? _io_master_w_bits_strb_T_7 : 4'hf; // @[Mux.scala 81:58]
  wire [3:0] _io_master_w_bits_strb_T_15 = 4'h1 == io_DataMem_Length ? _io_master_w_bits_strb_T_11 :
    _io_master_w_bits_strb_T_13; // @[Mux.scala 81:58]
  wire [3:0] _write_shift_bit_T_3 = 32'h1 == w_choose_byte ? 4'h8 : 4'h0; // @[Mux.scala 81:58]
  wire [4:0] _write_shift_bit_T_5 = 32'h2 == w_choose_byte ? 5'h10 : {{1'd0}, _write_shift_bit_T_3}; // @[Mux.scala 81:58]
  wire [4:0] _write_shift_bit_T_7 = 32'h3 == w_choose_byte ? 5'h18 : _write_shift_bit_T_5; // @[Mux.scala 81:58]
  wire [4:0] _write_shift_bit_T_11 = 32'h1 == w_choose_half ? 5'h10 : 5'h0; // @[Mux.scala 81:58]
  wire [4:0] _write_shift_bit_T_13 = 4'h0 == io_DataMem_Length ? _write_shift_bit_T_7 : 5'h0; // @[Mux.scala 81:58]
  wire [4:0] _write_shift_bit_T_15 = 4'h1 == io_DataMem_Length ? _write_shift_bit_T_11 : _write_shift_bit_T_13; // @[Mux.scala 81:58]
  wire [4:0] write_shift_bit = 4'h2 == io_DataMem_Length ? 5'h0 : _write_shift_bit_T_15; // @[Mux.scala 81:58]
  wire [31:0] r_choose_byte = io_DataMem_raddr & 32'h3; // @[PiplinedCPU.scala 100:42]
  wire [31:0] r_choose_half = io_DataMem_raddr & 32'h2; // @[PiplinedCPU.scala 101:42]
  wire [31:0] _r_mask_T_3 = 32'h1 == r_choose_byte ? 32'hff00 : 32'hff; // @[Mux.scala 81:58]
  wire [31:0] _r_mask_T_5 = 32'h2 == r_choose_byte ? 32'hff0000 : _r_mask_T_3; // @[Mux.scala 81:58]
  wire [31:0] _r_mask_T_7 = 32'h3 == r_choose_byte ? 32'hff000000 : _r_mask_T_5; // @[Mux.scala 81:58]
  wire [31:0] _r_mask_T_11 = 32'h1 == r_choose_half ? 32'hffff0000 : 32'hffff; // @[Mux.scala 81:58]
  wire [31:0] _r_mask_T_13 = 4'h0 == io_DataMem_Length ? _r_mask_T_7 : 32'hffffffff; // @[Mux.scala 81:58]
  wire [31:0] _r_mask_T_15 = 4'h1 == io_DataMem_Length ? _r_mask_T_11 : _r_mask_T_13; // @[Mux.scala 81:58]
  wire [31:0] r_mask = 4'h2 == io_DataMem_Length ? 32'hffffffff : _r_mask_T_15; // @[Mux.scala 81:58]
  wire [3:0] _read_shift_bit_T_3 = 32'h1 == r_choose_byte ? 4'h8 : 4'h0; // @[Mux.scala 81:58]
  wire [4:0] _read_shift_bit_T_5 = 32'h2 == r_choose_byte ? 5'h10 : {{1'd0}, _read_shift_bit_T_3}; // @[Mux.scala 81:58]
  wire [4:0] _read_shift_bit_T_7 = 32'h3 == r_choose_byte ? 5'h18 : _read_shift_bit_T_5; // @[Mux.scala 81:58]
  wire [4:0] _read_shift_bit_T_11 = 32'h1 == r_choose_half ? 5'h10 : 5'h0; // @[Mux.scala 81:58]
  wire [4:0] _read_shift_bit_T_13 = 4'h0 == io_DataMem_Length ? _read_shift_bit_T_7 : 5'h0; // @[Mux.scala 81:58]
  wire [4:0] _read_shift_bit_T_15 = 4'h1 == io_DataMem_Length ? _read_shift_bit_T_11 : _read_shift_bit_T_13; // @[Mux.scala 81:58]
  wire [4:0] read_shift_bit = 4'h2 == io_DataMem_Length ? 5'h0 : _read_shift_bit_T_15; // @[Mux.scala 81:58]
  wire  WMEM_Stall = io_DataMem_Mem_W & ~io_master_b_valid; // @[PiplinedCPU.scala 178:36]
  wire  RMEM_Stall = io_DataMem_Mem_R & ~io_master_r_valid; // @[PiplinedCPU.scala 179:36]
  reg [1:0] wState; // @[PiplinedCPU.scala 183:25]
  wire [1:0] _GEN_2 = io_master_b_valid ? 2'h0 : wState; // @[PiplinedCPU.scala 197:37 198:24 183:25]
  wire  _T_4 = wState == 2'h1; // @[PiplinedCPU.scala 203:17]
  wire [62:0] _GEN_6 = {{31'd0}, io_DataMem_wdata}; // @[PiplinedCPU.scala 207:52]
  wire [62:0] _io_master_w_bits_data_T = _GEN_6 << write_shift_bit; // @[PiplinedCPU.scala 207:52]
  wire [62:0] _GEN_8 = wState == 2'h1 ? _io_master_w_bits_data_T : 63'h0; // @[PiplinedCPU.scala 151:27 203:28 207:32]
  reg [1:0] rState; // @[PiplinedCPU.scala 217:25]
  wire [1:0] _GEN_12 = io_master_r_valid ? 2'h0 : rState; // @[PiplinedCPU.scala 231:37 232:24 217:25]
  wire  _T_10 = rState == 2'h1; // @[PiplinedCPU.scala 237:17]
  wire [31:0] _datapath_MEM_io_Mem_Data_T = io_master_r_bits_data & r_mask; // @[PiplinedCPU.scala 313:56]
  wire [31:0] _io_WB_PC_T_2 = stage_WB_io_pc_plus4 - 32'h4; // @[PiplinedCPU.scala 368:70]
  Reg_IF stage_IF ( // @[PiplinedCPU.scala 52:26]
    .clock(stage_IF_clock),
    .reset(stage_IF_reset),
    .io_Stall(stage_IF_io_Stall),
    .io_next_pc_in(stage_IF_io_next_pc_in),
    .io_pc(stage_IF_io_pc)
  );
  Reg_ID stage_ID ( // @[PiplinedCPU.scala 53:26]
    .clock(stage_ID_clock),
    .reset(stage_ID_reset),
    .io_Flush(stage_ID_io_Flush),
    .io_Stall(stage_ID_io_Stall),
    .io_pc_in(stage_ID_io_pc_in),
    .io_inst_in(stage_ID_io_inst_in),
    .io_pc(stage_ID_io_pc),
    .io_inst(stage_ID_io_inst)
  );
  Reg_EXE stage_EXE ( // @[PiplinedCPU.scala 54:27]
    .clock(stage_EXE_clock),
    .reset(stage_EXE_reset),
    .io_Flush(stage_EXE_io_Flush),
    .io_Stall(stage_EXE_io_Stall),
    .io_inst_in(stage_EXE_io_inst_in),
    .io_pc_in(stage_EXE_io_pc_in),
    .io_rs1_rdata_in(stage_EXE_io_rs1_rdata_in),
    .io_rs2_rdata_in(stage_EXE_io_rs2_rdata_in),
    .io_imm_in(stage_EXE_io_imm_in),
    .io_inst(stage_EXE_io_inst),
    .io_pc(stage_EXE_io_pc),
    .io_rs1_rdata(stage_EXE_io_rs1_rdata),
    .io_rs2_rdata(stage_EXE_io_rs2_rdata),
    .io_imm(stage_EXE_io_imm)
  );
  Reg_MEM stage_MEM ( // @[PiplinedCPU.scala 55:27]
    .clock(stage_MEM_clock),
    .reset(stage_MEM_reset),
    .io_Stall(stage_MEM_io_Stall),
    .io_pc_in(stage_MEM_io_pc_in),
    .io_inst_in(stage_MEM_io_inst_in),
    .io_alu_out_in(stage_MEM_io_alu_out_in),
    .io_DM_wdata_in(stage_MEM_io_DM_wdata_in),
    .io_pc(stage_MEM_io_pc),
    .io_inst(stage_MEM_io_inst),
    .io_alu_out(stage_MEM_io_alu_out),
    .io_DM_wdata(stage_MEM_io_DM_wdata)
  );
  Reg_WB stage_WB ( // @[PiplinedCPU.scala 56:26]
    .clock(stage_WB_clock),
    .reset(stage_WB_reset),
    .io_Stall(stage_WB_io_Stall),
    .io_pc_plus4_in(stage_WB_io_pc_plus4_in),
    .io_inst_in(stage_WB_io_inst_in),
    .io_alu_out_in(stage_WB_io_alu_out_in),
    .io_ld_data_in(stage_WB_io_ld_data_in),
    .io_pc_plus4(stage_WB_io_pc_plus4),
    .io_inst(stage_WB_io_inst),
    .io_alu_out(stage_WB_io_alu_out),
    .io_ld_data(stage_WB_io_ld_data)
  );
  Path_IF datapath_IF ( // @[PiplinedCPU.scala 59:29]
    .io_PCSel(datapath_IF_io_PCSel),
    .io_IF_pc_in(datapath_IF_io_IF_pc_in),
    .io_EXE_pc_in(datapath_IF_io_EXE_pc_in),
    .io_EXE_target_pc_in(datapath_IF_io_EXE_target_pc_in),
    .io_Mem_data(datapath_IF_io_Mem_data),
    .io_next_pc(datapath_IF_io_next_pc),
    .io_Mem_Addr(datapath_IF_io_Mem_Addr),
    .io_inst(datapath_IF_io_inst)
  );
  Path_ID datapath_ID ( // @[PiplinedCPU.scala 60:29]
    .clock(datapath_ID_clock),
    .reset(datapath_ID_reset),
    .io_ID_inst_in(datapath_ID_io_ID_inst_in),
    .io_WB_index(datapath_ID_io_WB_index),
    .io_WB_wdata(datapath_ID_io_WB_wdata),
    .io_WB_RegWEn(datapath_ID_io_WB_RegWEn),
    .io_ImmSel(datapath_ID_io_ImmSel),
    .io_ID_rs1_rdata(datapath_ID_io_ID_rs1_rdata),
    .io_ID_rs2_rdata(datapath_ID_io_ID_rs2_rdata),
    .io_imm(datapath_ID_io_imm),
    .io_regs_1(datapath_ID_io_regs_1),
    .io_regs_2(datapath_ID_io_regs_2),
    .io_regs_3(datapath_ID_io_regs_3),
    .io_regs_4(datapath_ID_io_regs_4),
    .io_regs_5(datapath_ID_io_regs_5),
    .io_regs_6(datapath_ID_io_regs_6),
    .io_regs_7(datapath_ID_io_regs_7),
    .io_regs_8(datapath_ID_io_regs_8),
    .io_regs_9(datapath_ID_io_regs_9),
    .io_regs_10(datapath_ID_io_regs_10),
    .io_regs_11(datapath_ID_io_regs_11),
    .io_regs_12(datapath_ID_io_regs_12),
    .io_regs_13(datapath_ID_io_regs_13),
    .io_regs_14(datapath_ID_io_regs_14),
    .io_regs_15(datapath_ID_io_regs_15),
    .io_regs_16(datapath_ID_io_regs_16),
    .io_regs_17(datapath_ID_io_regs_17),
    .io_regs_18(datapath_ID_io_regs_18),
    .io_regs_19(datapath_ID_io_regs_19),
    .io_regs_20(datapath_ID_io_regs_20),
    .io_regs_21(datapath_ID_io_regs_21),
    .io_regs_22(datapath_ID_io_regs_22),
    .io_regs_23(datapath_ID_io_regs_23),
    .io_regs_24(datapath_ID_io_regs_24),
    .io_regs_25(datapath_ID_io_regs_25),
    .io_regs_26(datapath_ID_io_regs_26),
    .io_regs_27(datapath_ID_io_regs_27),
    .io_regs_28(datapath_ID_io_regs_28),
    .io_regs_29(datapath_ID_io_regs_29),
    .io_regs_30(datapath_ID_io_regs_30),
    .io_regs_31(datapath_ID_io_regs_31)
  );
  Path_EXE datapath_EXE ( // @[PiplinedCPU.scala 61:30]
    .io_EXE_pc_in(datapath_EXE_io_EXE_pc_in),
    .io_EXE_imm_in(datapath_EXE_io_EXE_imm_in),
    .io_EXE_rs1_rdata_in(datapath_EXE_io_EXE_rs1_rdata_in),
    .io_EXE_rs2_rdata_in(datapath_EXE_io_EXE_rs2_rdata_in),
    .io_E_ASel(datapath_EXE_io_E_ASel),
    .io_E_BSel(datapath_EXE_io_E_BSel),
    .io_E_BrUn(datapath_EXE_io_E_BrUn),
    .io_E_ALUSel(datapath_EXE_io_E_ALUSel),
    .io_EXE_target_pc_out(datapath_EXE_io_EXE_target_pc_out),
    .io_EXE_alu_out(datapath_EXE_io_EXE_alu_out),
    .io_EXE_rs2_rdata_out(datapath_EXE_io_EXE_rs2_rdata_out),
    .io_E_BrEq(datapath_EXE_io_E_BrEq),
    .io_E_BrLT(datapath_EXE_io_E_BrLT),
    .io_alu_src1(datapath_EXE_io_alu_src1),
    .io_alu_src2(datapath_EXE_io_alu_src2),
    .io_EXE_src1(datapath_EXE_io_EXE_src1),
    .io_EXE_src2(datapath_EXE_io_EXE_src2)
  );
  Path_MEM datapath_MEM ( // @[PiplinedCPU.scala 62:30]
    .io_MEM_pc_in(datapath_MEM_io_MEM_pc_in),
    .io_MEM_alu_out_in(datapath_MEM_io_MEM_alu_out_in),
    .io_MEM_DM_wdata_in(datapath_MEM_io_MEM_DM_wdata_in),
    .io_MEM_pc_plus_4(datapath_MEM_io_MEM_pc_plus_4),
    .io_MEM_alu_out(datapath_MEM_io_MEM_alu_out),
    .io_MEM_ld_data(datapath_MEM_io_MEM_ld_data),
    .io_Mem_Addr(datapath_MEM_io_Mem_Addr),
    .io_Mem_Write_Data(datapath_MEM_io_Mem_Write_Data),
    .io_Mem_Data(datapath_MEM_io_Mem_Data)
  );
  Path_WB datapath_WB ( // @[PiplinedCPU.scala 63:29]
    .io_WB_pc_plus4_in(datapath_WB_io_WB_pc_plus4_in),
    .io_WB_alu_out_in(datapath_WB_io_WB_alu_out_in),
    .io_WB_ld_data_in(datapath_WB_io_WB_ld_data_in),
    .io_W_WBSel(datapath_WB_io_W_WBSel),
    .io_WB_wdata(datapath_WB_io_WB_wdata)
  );
  Controller contorller ( // @[PiplinedCPU.scala 66:28]
    .io_DM_Mem_R(contorller_io_DM_Mem_R),
    .io_DM_Mem_W(contorller_io_DM_Mem_W),
    .io_DM_Length(contorller_io_DM_Length),
    .io_E_BrEq(contorller_io_E_BrEq),
    .io_E_BrLT(contorller_io_E_BrLT),
    .io_E_Branch_taken(contorller_io_E_Branch_taken),
    .io_ID_pc(contorller_io_ID_pc),
    .io_EXE_target_pc(contorller_io_EXE_target_pc),
    .io_Flush_WB_ID_DH(contorller_io_Flush_WB_ID_DH),
    .io_Flush_BH(contorller_io_Flush_BH),
    .io_Stall_WB_ID_DH(contorller_io_Stall_WB_ID_DH),
    .io_IF_Inst(contorller_io_IF_Inst),
    .io_ID_Inst(contorller_io_ID_Inst),
    .io_EXE_Inst(contorller_io_EXE_Inst),
    .io_MEM_Inst(contorller_io_MEM_Inst),
    .io_WB_Inst(contorller_io_WB_Inst),
    .io_PCSel(contorller_io_PCSel),
    .io_D_ImmSel(contorller_io_D_ImmSel),
    .io_W_RegWEn(contorller_io_W_RegWEn),
    .io_E_BrUn(contorller_io_E_BrUn),
    .io_E_ASel(contorller_io_E_ASel),
    .io_E_BSel(contorller_io_E_BSel),
    .io_E_ALUSel(contorller_io_E_ALUSel),
    .io_W_WBSel(contorller_io_W_WBSel),
    .io_Hcf(contorller_io_Hcf)
  );
  assign io_InstMem_raddr = datapath_IF_io_Mem_Addr[14:0]; // @[PiplinedCPU.scala 265:22]
  assign io_DataMem_Mem_R = contorller_io_DM_Mem_R; // @[PiplinedCPU.scala 316:22]
  assign io_DataMem_Mem_W = contorller_io_DM_Mem_W; // @[PiplinedCPU.scala 317:22]
  assign io_DataMem_Length = contorller_io_DM_Length; // @[PiplinedCPU.scala 318:23]
  assign io_DataMem_raddr = datapath_MEM_io_Mem_Addr; // @[PiplinedCPU.scala 319:22]
  assign io_DataMem_waddr = datapath_MEM_io_Mem_Addr; // @[PiplinedCPU.scala 320:22]
  assign io_DataMem_wdata = datapath_MEM_io_Mem_Write_Data; // @[PiplinedCPU.scala 321:22]
  assign io_master_aw_valid = wState == 2'h1; // @[PiplinedCPU.scala 203:17]
  assign io_master_aw_bits_addr = wState == 2'h1 ? io_DataMem_waddr : 32'h0; // @[PiplinedCPU.scala 203:28 139:30 206:32]
  assign io_master_w_valid = wState == 2'h1; // @[PiplinedCPU.scala 203:17]
  assign io_master_w_bits_data = _GEN_8[31:0];
  assign io_master_w_bits_strb = 4'h2 == io_DataMem_Length ? 4'hf : _io_master_w_bits_strb_T_15; // @[Mux.scala 81:58]
  assign io_master_b_ready = wState == 2'h2 | _T_4; // @[PiplinedCPU.scala 211:32 212:32]
  assign io_master_ar_valid = rState == 2'h1; // @[PiplinedCPU.scala 237:17]
  assign io_master_ar_bits_addr = rState == 2'h1 ? io_DataMem_raddr : 32'h0; // @[PiplinedCPU.scala 237:28 159:30 239:33]
  assign io_master_r_ready = rState == 2'h2 | _T_10; // @[PiplinedCPU.scala 242:33 243:33]
  assign io_regs_1 = datapath_ID_io_regs_1; // @[PiplinedCPU.scala 355:13]
  assign io_regs_2 = datapath_ID_io_regs_2; // @[PiplinedCPU.scala 355:13]
  assign io_regs_3 = datapath_ID_io_regs_3; // @[PiplinedCPU.scala 355:13]
  assign io_regs_4 = datapath_ID_io_regs_4; // @[PiplinedCPU.scala 355:13]
  assign io_regs_5 = datapath_ID_io_regs_5; // @[PiplinedCPU.scala 355:13]
  assign io_regs_6 = datapath_ID_io_regs_6; // @[PiplinedCPU.scala 355:13]
  assign io_regs_7 = datapath_ID_io_regs_7; // @[PiplinedCPU.scala 355:13]
  assign io_regs_8 = datapath_ID_io_regs_8; // @[PiplinedCPU.scala 355:13]
  assign io_regs_9 = datapath_ID_io_regs_9; // @[PiplinedCPU.scala 355:13]
  assign io_regs_10 = datapath_ID_io_regs_10; // @[PiplinedCPU.scala 355:13]
  assign io_regs_11 = datapath_ID_io_regs_11; // @[PiplinedCPU.scala 355:13]
  assign io_regs_12 = datapath_ID_io_regs_12; // @[PiplinedCPU.scala 355:13]
  assign io_regs_13 = datapath_ID_io_regs_13; // @[PiplinedCPU.scala 355:13]
  assign io_regs_14 = datapath_ID_io_regs_14; // @[PiplinedCPU.scala 355:13]
  assign io_regs_15 = datapath_ID_io_regs_15; // @[PiplinedCPU.scala 355:13]
  assign io_regs_16 = datapath_ID_io_regs_16; // @[PiplinedCPU.scala 355:13]
  assign io_regs_17 = datapath_ID_io_regs_17; // @[PiplinedCPU.scala 355:13]
  assign io_regs_18 = datapath_ID_io_regs_18; // @[PiplinedCPU.scala 355:13]
  assign io_regs_19 = datapath_ID_io_regs_19; // @[PiplinedCPU.scala 355:13]
  assign io_regs_20 = datapath_ID_io_regs_20; // @[PiplinedCPU.scala 355:13]
  assign io_regs_21 = datapath_ID_io_regs_21; // @[PiplinedCPU.scala 355:13]
  assign io_regs_22 = datapath_ID_io_regs_22; // @[PiplinedCPU.scala 355:13]
  assign io_regs_23 = datapath_ID_io_regs_23; // @[PiplinedCPU.scala 355:13]
  assign io_regs_24 = datapath_ID_io_regs_24; // @[PiplinedCPU.scala 355:13]
  assign io_regs_25 = datapath_ID_io_regs_25; // @[PiplinedCPU.scala 355:13]
  assign io_regs_26 = datapath_ID_io_regs_26; // @[PiplinedCPU.scala 355:13]
  assign io_regs_27 = datapath_ID_io_regs_27; // @[PiplinedCPU.scala 355:13]
  assign io_regs_28 = datapath_ID_io_regs_28; // @[PiplinedCPU.scala 355:13]
  assign io_regs_29 = datapath_ID_io_regs_29; // @[PiplinedCPU.scala 355:13]
  assign io_regs_30 = datapath_ID_io_regs_30; // @[PiplinedCPU.scala 355:13]
  assign io_regs_31 = datapath_ID_io_regs_31; // @[PiplinedCPU.scala 355:13]
  assign io_Hcf = contorller_io_Hcf; // @[PiplinedCPU.scala 356:12]
  assign io_E_Branch_taken = contorller_io_E_Branch_taken; // @[PiplinedCPU.scala 359:23]
  assign io_Flush = contorller_io_Flush_BH; // @[PiplinedCPU.scala 360:14]
  assign io_Stall_MA = RMEM_Stall | WMEM_Stall; // @[PiplinedCPU.scala 363:31]
  assign io_Stall_DH = contorller_io_Stall_WB_ID_DH; // @[PiplinedCPU.scala 361:17]
  assign io_IF_PC = stage_IF_io_pc; // @[PiplinedCPU.scala 364:14]
  assign io_ID_PC = stage_ID_io_pc; // @[PiplinedCPU.scala 365:14]
  assign io_EXE_PC = stage_EXE_io_pc; // @[PiplinedCPU.scala 366:15]
  assign io_MEM_PC = stage_MEM_io_pc; // @[PiplinedCPU.scala 367:15]
  assign io_WB_PC = stage_WB_io_pc_plus4 > 32'h0 ? _io_WB_PC_T_2 : stage_WB_io_pc_plus4; // @[PiplinedCPU.scala 368:20]
  assign io_EXE_src1 = datapath_EXE_io_EXE_src1; // @[PiplinedCPU.scala 370:17]
  assign io_EXE_src2 = datapath_EXE_io_EXE_src2; // @[PiplinedCPU.scala 371:17]
  assign io_ALU_src1 = datapath_EXE_io_alu_src1; // @[PiplinedCPU.scala 372:17]
  assign io_ALU_src2 = datapath_EXE_io_alu_src2; // @[PiplinedCPU.scala 373:17]
  assign io_EXE_alu_out = datapath_EXE_io_EXE_alu_out; // @[PiplinedCPU.scala 369:20]
  assign io_WB_rd = stage_WB_io_inst[11:7]; // @[PiplinedCPU.scala 375:33]
  assign io_WB_wdata = datapath_WB_io_WB_wdata; // @[PiplinedCPU.scala 374:17]
  assign io_EXE_Jump = stage_EXE_io_inst[6:0] == 7'h6f | stage_EXE_io_inst[6:0] == 7'h67; // @[PiplinedCPU.scala 376:52]
  assign io_EXE_Branch = stage_EXE_io_inst[6:0] == 7'h63; // @[PiplinedCPU.scala 377:46]
  assign stage_IF_clock = clock;
  assign stage_IF_reset = reset;
  assign stage_IF_io_Stall = (io_Stall_DH | io_Stall_MA) & ~contorller_io_Flush_BH; // @[PiplinedCPU.scala 251:55]
  assign stage_IF_io_next_pc_in = datapath_IF_io_next_pc; // @[PiplinedCPU.scala 252:28]
  assign stage_ID_clock = clock;
  assign stage_ID_reset = reset;
  assign stage_ID_io_Flush = contorller_io_Flush_BH; // @[PiplinedCPU.scala 270:23]
  assign stage_ID_io_Stall = io_Stall_DH | io_Stall_MA; // @[PiplinedCPU.scala 271:38]
  assign stage_ID_io_pc_in = stage_IF_io_pc; // @[PiplinedCPU.scala 273:23]
  assign stage_ID_io_inst_in = datapath_IF_io_inst; // @[PiplinedCPU.scala 272:25]
  assign stage_EXE_clock = clock;
  assign stage_EXE_reset = reset;
  assign stage_EXE_io_Flush = (contorller_io_Flush_WB_ID_DH | contorller_io_Flush_BH) & ~io_Stall_MA; // @[PiplinedCPU.scala 283:84]
  assign stage_EXE_io_Stall = contorller_io_Hcf | io_Stall_MA; // @[PiplinedCPU.scala 284:45]
  assign stage_EXE_io_inst_in = stage_ID_io_inst; // @[PiplinedCPU.scala 286:26]
  assign stage_EXE_io_pc_in = stage_ID_io_pc; // @[PiplinedCPU.scala 285:24]
  assign stage_EXE_io_rs1_rdata_in = datapath_ID_io_ID_rs1_rdata; // @[PiplinedCPU.scala 288:31]
  assign stage_EXE_io_rs2_rdata_in = datapath_ID_io_ID_rs2_rdata; // @[PiplinedCPU.scala 289:31]
  assign stage_EXE_io_imm_in = datapath_ID_io_imm; // @[PiplinedCPU.scala 287:25]
  assign stage_MEM_clock = clock;
  assign stage_MEM_reset = reset;
  assign stage_MEM_io_Stall = contorller_io_Hcf | io_Stall_MA; // @[PiplinedCPU.scala 302:45]
  assign stage_MEM_io_pc_in = stage_EXE_io_pc; // @[PiplinedCPU.scala 303:24]
  assign stage_MEM_io_inst_in = stage_EXE_io_inst; // @[PiplinedCPU.scala 304:26]
  assign stage_MEM_io_alu_out_in = datapath_EXE_io_EXE_alu_out; // @[PiplinedCPU.scala 306:29]
  assign stage_MEM_io_DM_wdata_in = datapath_EXE_io_EXE_rs2_rdata_out; // @[PiplinedCPU.scala 305:30]
  assign stage_WB_clock = clock;
  assign stage_WB_reset = reset;
  assign stage_WB_io_Stall = contorller_io_Hcf | io_Stall_MA; // @[PiplinedCPU.scala 324:44]
  assign stage_WB_io_pc_plus4_in = datapath_MEM_io_MEM_pc_plus_4; // @[PiplinedCPU.scala 325:29]
  assign stage_WB_io_inst_in = stage_MEM_io_inst; // @[PiplinedCPU.scala 326:25]
  assign stage_WB_io_alu_out_in = datapath_MEM_io_MEM_alu_out; // @[PiplinedCPU.scala 327:28]
  assign stage_WB_io_ld_data_in = datapath_MEM_io_MEM_ld_data; // @[PiplinedCPU.scala 328:28]
  assign datapath_IF_io_PCSel = contorller_io_PCSel; // @[PiplinedCPU.scala 255:26]
  assign datapath_IF_io_IF_pc_in = stage_IF_io_pc; // @[PiplinedCPU.scala 256:29]
  assign datapath_IF_io_EXE_pc_in = stage_EXE_io_pc; // @[PiplinedCPU.scala 257:30]
  assign datapath_IF_io_EXE_target_pc_in = datapath_EXE_io_EXE_target_pc_out; // @[PiplinedCPU.scala 258:37]
  assign datapath_IF_io_Mem_data = io_InstMem_rdata; // @[PiplinedCPU.scala 259:48]
  assign datapath_ID_clock = clock;
  assign datapath_ID_reset = reset;
  assign datapath_ID_io_ID_inst_in = stage_ID_io_inst; // @[PiplinedCPU.scala 276:31]
  assign datapath_ID_io_WB_index = stage_WB_io_inst[11:7]; // @[PiplinedCPU.scala 277:48]
  assign datapath_ID_io_WB_wdata = datapath_WB_io_WB_wdata; // @[PiplinedCPU.scala 278:29]
  assign datapath_ID_io_WB_RegWEn = contorller_io_W_RegWEn; // @[PiplinedCPU.scala 279:30]
  assign datapath_ID_io_ImmSel = contorller_io_D_ImmSel; // @[PiplinedCPU.scala 280:27]
  assign datapath_EXE_io_EXE_pc_in = stage_EXE_io_pc; // @[PiplinedCPU.scala 292:31]
  assign datapath_EXE_io_EXE_imm_in = stage_EXE_io_imm; // @[PiplinedCPU.scala 293:32]
  assign datapath_EXE_io_EXE_rs1_rdata_in = stage_EXE_io_rs1_rdata; // @[PiplinedCPU.scala 294:38]
  assign datapath_EXE_io_EXE_rs2_rdata_in = stage_EXE_io_rs2_rdata; // @[PiplinedCPU.scala 295:38]
  assign datapath_EXE_io_E_ASel = contorller_io_E_ASel; // @[PiplinedCPU.scala 296:28]
  assign datapath_EXE_io_E_BSel = contorller_io_E_BSel; // @[PiplinedCPU.scala 297:28]
  assign datapath_EXE_io_E_BrUn = contorller_io_E_BrUn; // @[PiplinedCPU.scala 298:28]
  assign datapath_EXE_io_E_ALUSel = contorller_io_E_ALUSel; // @[PiplinedCPU.scala 299:30]
  assign datapath_MEM_io_MEM_pc_in = stage_MEM_io_pc; // @[PiplinedCPU.scala 309:31]
  assign datapath_MEM_io_MEM_alu_out_in = stage_MEM_io_alu_out; // @[PiplinedCPU.scala 310:36]
  assign datapath_MEM_io_MEM_DM_wdata_in = stage_MEM_io_DM_wdata; // @[PiplinedCPU.scala 311:37]
  assign datapath_MEM_io_Mem_Data = _datapath_MEM_io_Mem_Data_T >> read_shift_bit; // @[PiplinedCPU.scala 313:66]
  assign datapath_WB_io_WB_pc_plus4_in = stage_WB_io_pc_plus4; // @[PiplinedCPU.scala 331:35]
  assign datapath_WB_io_WB_alu_out_in = stage_WB_io_alu_out; // @[PiplinedCPU.scala 332:34]
  assign datapath_WB_io_WB_ld_data_in = stage_WB_io_ld_data; // @[PiplinedCPU.scala 333:34]
  assign datapath_WB_io_W_WBSel = contorller_io_W_WBSel; // @[PiplinedCPU.scala 334:28]
  assign contorller_io_E_BrEq = datapath_EXE_io_E_BrEq; // @[PiplinedCPU.scala 343:26]
  assign contorller_io_E_BrLT = datapath_EXE_io_E_BrLT; // @[PiplinedCPU.scala 344:26]
  assign contorller_io_ID_pc = stage_ID_io_pc; // @[PiplinedCPU.scala 346:25]
  assign contorller_io_EXE_target_pc = datapath_EXE_io_EXE_target_pc_out; // @[PiplinedCPU.scala 348:33]
  assign contorller_io_IF_Inst = io_InstMem_rdata; // @[PiplinedCPU.scala 337:27]
  assign contorller_io_ID_Inst = stage_ID_io_inst; // @[PiplinedCPU.scala 338:27]
  assign contorller_io_EXE_Inst = stage_EXE_io_inst; // @[PiplinedCPU.scala 339:28]
  assign contorller_io_MEM_Inst = stage_MEM_io_inst; // @[PiplinedCPU.scala 340:28]
  assign contorller_io_WB_Inst = stage_WB_io_inst; // @[PiplinedCPU.scala 341:27]
  always @(posedge clock) begin
    if (reset) begin // @[PiplinedCPU.scala 183:25]
      wState <= 2'h0; // @[PiplinedCPU.scala 183:25]
    end else if (2'h0 == wState) begin // @[PiplinedCPU.scala 185:20]
      if (io_DataMem_Mem_W) begin // @[PiplinedCPU.scala 187:37]
        wState <= 2'h1; // @[PiplinedCPU.scala 188:24]
      end
    end else if (2'h1 == wState) begin // @[PiplinedCPU.scala 185:20]
      if (io_master_w_ready & io_master_aw_ready) begin // @[PiplinedCPU.scala 192:60]
        wState <= 2'h2; // @[PiplinedCPU.scala 193:24]
      end
    end else if (2'h2 == wState) begin // @[PiplinedCPU.scala 185:20]
      wState <= _GEN_2;
    end
    if (reset) begin // @[PiplinedCPU.scala 217:25]
      rState <= 2'h0; // @[PiplinedCPU.scala 217:25]
    end else if (2'h0 == rState) begin // @[PiplinedCPU.scala 219:20]
      if (io_DataMem_Mem_R & io_DMA_Hcf) begin // @[PiplinedCPU.scala 221:52]
        rState <= 2'h1; // @[PiplinedCPU.scala 222:24]
      end
    end else if (2'h1 == rState) begin // @[PiplinedCPU.scala 219:20]
      if (io_master_ar_ready) begin // @[PiplinedCPU.scala 226:39]
        rState <= 2'h2; // @[PiplinedCPU.scala 227:24]
      end
    end else if (2'h2 == rState) begin // @[PiplinedCPU.scala 219:20]
      rState <= _GEN_12;
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  wState = _RAND_0[1:0];
  _RAND_1 = {1{`RANDOM}};
  rState = _RAND_1[1:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module InstMem(
  input         clock,
  input  [14:0] io_raddr,
  output [31:0] io_inst
);
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
  reg [7:0] memory [0:32767]; // @[InstMem.scala 14:19]
  wire  memory_rdata_MPORT_en; // @[InstMem.scala 14:19]
  wire [14:0] memory_rdata_MPORT_addr; // @[InstMem.scala 14:19]
  wire [7:0] memory_rdata_MPORT_data; // @[InstMem.scala 14:19]
  wire  memory_rdata_MPORT_1_en; // @[InstMem.scala 14:19]
  wire [14:0] memory_rdata_MPORT_1_addr; // @[InstMem.scala 14:19]
  wire [7:0] memory_rdata_MPORT_1_data; // @[InstMem.scala 14:19]
  wire  memory_rdata_MPORT_2_en; // @[InstMem.scala 14:19]
  wire [14:0] memory_rdata_MPORT_2_addr; // @[InstMem.scala 14:19]
  wire [7:0] memory_rdata_MPORT_2_data; // @[InstMem.scala 14:19]
  wire  memory_rdata_MPORT_3_en; // @[InstMem.scala 14:19]
  wire [14:0] memory_rdata_MPORT_3_addr; // @[InstMem.scala 14:19]
  wire [7:0] memory_rdata_MPORT_3_data; // @[InstMem.scala 14:19]
  wire [15:0] _rdata_T_6 = {{1'd0}, io_raddr}; // @[InstMem.scala 21:31]
  wire [15:0] rdata_lo = {memory_rdata_MPORT_2_data,memory_rdata_MPORT_3_data}; // @[Cat.scala 33:92]
  wire [15:0] rdata_hi = {memory_rdata_MPORT_data,memory_rdata_MPORT_1_data}; // @[Cat.scala 33:92]
  assign memory_rdata_MPORT_en = 1'h1;
  assign memory_rdata_MPORT_addr = io_raddr + 15'h3;
  assign memory_rdata_MPORT_data = memory[memory_rdata_MPORT_addr]; // @[InstMem.scala 14:19]
  assign memory_rdata_MPORT_1_en = 1'h1;
  assign memory_rdata_MPORT_1_addr = io_raddr + 15'h2;
  assign memory_rdata_MPORT_1_data = memory[memory_rdata_MPORT_1_addr]; // @[InstMem.scala 14:19]
  assign memory_rdata_MPORT_2_en = 1'h1;
  assign memory_rdata_MPORT_2_addr = io_raddr + 15'h1;
  assign memory_rdata_MPORT_2_data = memory[memory_rdata_MPORT_2_addr]; // @[InstMem.scala 14:19]
  assign memory_rdata_MPORT_3_en = 1'h1;
  assign memory_rdata_MPORT_3_addr = _rdata_T_6[14:0];
  assign memory_rdata_MPORT_3_data = memory[memory_rdata_MPORT_3_addr]; // @[InstMem.scala 14:19]
  assign io_inst = {rdata_hi,rdata_lo}; // @[Cat.scala 33:92]
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {1{`RANDOM}};
  for (initvar = 0; initvar < 32768; initvar = initvar+1)
    memory[initvar] = _RAND_0[7:0];
`endif // RANDOMIZE_MEM_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module AXIReadBus(
  input         clock,
  input         reset,
  output        io_master_readAddr_ready,
  input         io_master_readAddr_valid,
  input  [3:0]  io_master_readAddr_bits_id,
  input  [31:0] io_master_readAddr_bits_addr,
  input  [1:0]  io_master_readAddr_bits_size,
  input         io_master_readData_ready,
  output        io_master_readData_valid,
  output [3:0]  io_master_readData_bits_id,
  output [31:0] io_master_readData_bits_data,
  output [1:0]  io_master_readData_bits_resp,
  output        io_master_readData_bits_last,
  input         io_slave_0_readAddr_ready,
  output        io_slave_0_readAddr_valid,
  output [3:0]  io_slave_0_readAddr_bits_id,
  output [31:0] io_slave_0_readAddr_bits_addr,
  output [1:0]  io_slave_0_readAddr_bits_size,
  output        io_slave_0_readData_ready,
  input         io_slave_0_readData_valid,
  input  [3:0]  io_slave_0_readData_bits_id,
  input  [31:0] io_slave_0_readData_bits_data,
  input  [1:0]  io_slave_0_readData_bits_resp,
  input         io_slave_0_readData_bits_last,
  input         io_slave_1_readAddr_ready,
  output        io_slave_1_readAddr_valid,
  output [3:0]  io_slave_1_readAddr_bits_id,
  output [31:0] io_slave_1_readAddr_bits_addr,
  output [1:0]  io_slave_1_readAddr_bits_size,
  output        io_slave_1_readData_ready,
  input         io_slave_1_readData_valid,
  input  [3:0]  io_slave_1_readData_bits_id,
  input  [31:0] io_slave_1_readData_bits_data,
  input  [1:0]  io_slave_1_readData_bits_resp,
  input         io_slave_1_readData_bits_last,
  input         io_slave_2_readAddr_ready,
  output        io_slave_2_readAddr_valid,
  output [3:0]  io_slave_2_readAddr_bits_id,
  output [31:0] io_slave_2_readAddr_bits_addr,
  output [1:0]  io_slave_2_readAddr_bits_size,
  output        io_slave_2_readData_ready,
  input         io_slave_2_readData_valid,
  input  [3:0]  io_slave_2_readData_bits_id,
  input  [31:0] io_slave_2_readData_bits_data,
  input  [1:0]  io_slave_2_readData_bits_resp,
  input         io_slave_2_readData_bits_last
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
`endif // RANDOMIZE_REG_INIT
  wire  _read_port_T_1 = io_master_readAddr_bits_addr < 32'h64; // @[AXIReadBus.scala 26:85]
  wire  _read_port_T_5 = io_master_readAddr_bits_addr >= 32'h8000 & io_master_readAddr_bits_addr < 32'h8800; // @[AXIReadBus.scala 26:53]
  wire  _read_port_T_8 = io_master_readAddr_bits_addr >= 32'h10000 & io_master_readAddr_bits_addr < 32'h10800; // @[AXIReadBus.scala 26:53]
  wire [1:0] _read_port_T_9 = _read_port_T_8 ? 2'h2 : 2'h0; // @[Mux.scala 101:16]
  wire [1:0] _read_port_T_10 = _read_port_T_5 ? 2'h1 : _read_port_T_9; // @[Mux.scala 101:16]
  wire [1:0] read_port = _read_port_T_1 ? 2'h0 : _read_port_T_10; // @[Mux.scala 101:16]
  reg [2:0] read_port_reg; // @[AXIReadBus.scala 28:30]
  reg [31:0] read_addr_reg; // @[AXIReadBus.scala 29:30]
  reg [3:0] read_addr_reg_id; // @[AXIReadBus.scala 30:33]
  reg [2:0] read_addr_reg_size; // @[AXIReadBus.scala 31:35]
  reg  read_addr_reg_valid; // @[AXIReadBus.scala 32:36]
  reg  outstanding; // @[AXIReadBus.scala 33:28]
  wire  _T = io_master_readAddr_ready & io_master_readAddr_valid; // @[Decoupled.scala 52:35]
  wire  _GEN_0 = _T | outstanding; // @[AXIReadBus.scala 66:33 67:17 33:28]
  wire  _GEN_5 = _T | read_addr_reg_valid; // @[AXIReadBus.scala 66:33 72:25 32:36]
  wire  _GEN_7 = 2'h1 == read_port_reg[1:0] ? io_slave_1_readAddr_ready : io_slave_0_readAddr_ready; // @[AXIReadBus.scala 82:{50,50}]
  wire  _GEN_8 = 2'h2 == read_port_reg[1:0] ? io_slave_2_readAddr_ready : _GEN_7; // @[AXIReadBus.scala 82:{50,50}]
  wire  _GEN_12 = 2'h1 == read_port_reg[1:0] ? io_slave_1_readData_valid : io_slave_0_readData_valid; // @[AXIReadBus.scala 89:{30,30}]
  wire  _GEN_13 = 2'h2 == read_port_reg[1:0] ? io_slave_2_readData_valid : _GEN_12; // @[AXIReadBus.scala 89:{30,30}]
  wire [31:0] _GEN_15 = 2'h1 == read_port_reg[1:0] ? io_slave_1_readData_bits_data : io_slave_0_readData_bits_data; // @[AXIReadBus.scala 90:{34,34}]
  wire [31:0] _GEN_16 = 2'h2 == read_port_reg[1:0] ? io_slave_2_readData_bits_data : _GEN_15; // @[AXIReadBus.scala 90:{34,34}]
  wire [1:0] _GEN_18 = 2'h1 == read_port_reg[1:0] ? io_slave_1_readData_bits_resp : io_slave_0_readData_bits_resp; // @[AXIReadBus.scala 91:{34,34}]
  wire [1:0] _GEN_19 = 2'h2 == read_port_reg[1:0] ? io_slave_2_readData_bits_resp : _GEN_18; // @[AXIReadBus.scala 91:{34,34}]
  wire  _GEN_21 = 2'h1 == read_port_reg[1:0] ? io_slave_1_readData_bits_last : io_slave_0_readData_bits_last; // @[AXIReadBus.scala 92:{34,34}]
  wire  _GEN_22 = 2'h2 == read_port_reg[1:0] ? io_slave_2_readData_bits_last : _GEN_21; // @[AXIReadBus.scala 92:{34,34}]
  wire [3:0] _GEN_24 = 2'h1 == read_port_reg[1:0] ? io_slave_1_readData_bits_id : io_slave_0_readData_bits_id; // @[AXIReadBus.scala 93:{32,32}]
  wire [31:0] _GEN_26 = 2'h0 == read_port_reg[1:0] ? read_addr_reg : 32'h0; // @[AXIReadBus.scala 45:36 94:{48,48}]
  wire [31:0] _GEN_27 = 2'h1 == read_port_reg[1:0] ? read_addr_reg : 32'h0; // @[AXIReadBus.scala 45:36 94:{48,48}]
  wire [31:0] _GEN_28 = 2'h2 == read_port_reg[1:0] ? read_addr_reg : 32'h0; // @[AXIReadBus.scala 45:36 94:{48,48}]
  wire  _GEN_63 = 2'h0 == read_port_reg[1:0]; // @[AXIReadBus.scala 44:32 95:{44,44}]
  wire  _GEN_29 = 2'h0 == read_port_reg[1:0] & read_addr_reg_valid; // @[AXIReadBus.scala 44:32 95:{44,44}]
  wire  _GEN_64 = 2'h1 == read_port_reg[1:0]; // @[AXIReadBus.scala 44:32 95:{44,44}]
  wire  _GEN_30 = 2'h1 == read_port_reg[1:0] & read_addr_reg_valid; // @[AXIReadBus.scala 44:32 95:{44,44}]
  wire  _GEN_65 = 2'h2 == read_port_reg[1:0]; // @[AXIReadBus.scala 44:32 95:{44,44}]
  wire  _GEN_31 = 2'h2 == read_port_reg[1:0] & read_addr_reg_valid; // @[AXIReadBus.scala 44:32 95:{44,44}]
  wire  _GEN_32 = _GEN_63 & io_master_readData_ready; // @[AXIReadBus.scala 55:32 96:{44,44}]
  wire  _GEN_33 = _GEN_64 & io_master_readData_ready; // @[AXIReadBus.scala 55:32 96:{44,44}]
  wire  _GEN_34 = _GEN_65 & io_master_readData_ready; // @[AXIReadBus.scala 55:32 96:{44,44}]
  wire [1:0] _GEN_35 = 2'h0 == read_port_reg[1:0] ? read_addr_reg_size[1:0] : 2'h0; // @[AXIReadBus.scala 49:36 97:{48,48}]
  wire [1:0] _GEN_36 = 2'h1 == read_port_reg[1:0] ? read_addr_reg_size[1:0] : 2'h0; // @[AXIReadBus.scala 49:36 97:{48,48}]
  wire [1:0] _GEN_37 = 2'h2 == read_port_reg[1:0] ? read_addr_reg_size[1:0] : 2'h0; // @[AXIReadBus.scala 49:36 97:{48,48}]
  wire [3:0] _GEN_38 = 2'h0 == read_port_reg[1:0] ? read_addr_reg_id : 4'h0; // @[AXIReadBus.scala 46:34 98:{46,46}]
  wire [3:0] _GEN_39 = 2'h1 == read_port_reg[1:0] ? read_addr_reg_id : 4'h0; // @[AXIReadBus.scala 46:34 98:{46,46}]
  wire [3:0] _GEN_40 = 2'h2 == read_port_reg[1:0] ? read_addr_reg_id : 4'h0; // @[AXIReadBus.scala 46:34 98:{46,46}]
  wire  _T_7 = io_master_readData_ready & io_master_readData_valid; // @[Decoupled.scala 52:35]
  assign io_master_readAddr_ready = ~outstanding; // @[AXIReadBus.scala 63:31]
  assign io_master_readData_valid = outstanding & _GEN_13; // @[AXIReadBus.scala 88:21 58:28 89:30]
  assign io_master_readData_bits_id = 2'h2 == read_port_reg[1:0] ? io_slave_2_readData_bits_id : _GEN_24; // @[AXIReadBus.scala 93:{32,32}]
  assign io_master_readData_bits_data = outstanding ? _GEN_16 : 32'h0; // @[AXIReadBus.scala 88:21 59:32 90:34]
  assign io_master_readData_bits_resp = outstanding ? _GEN_19 : 2'h0; // @[AXIReadBus.scala 88:21 60:32 91:34]
  assign io_master_readData_bits_last = outstanding & _GEN_22; // @[AXIReadBus.scala 88:21 62:32 92:34]
  assign io_slave_0_readAddr_valid = outstanding & _GEN_29; // @[AXIReadBus.scala 88:21 44:32]
  assign io_slave_0_readAddr_bits_id = outstanding ? _GEN_38 : 4'h0; // @[AXIReadBus.scala 88:21 46:34]
  assign io_slave_0_readAddr_bits_addr = outstanding ? _GEN_26 : 32'h0; // @[AXIReadBus.scala 88:21 45:36]
  assign io_slave_0_readAddr_bits_size = outstanding ? _GEN_35 : 2'h0; // @[AXIReadBus.scala 88:21 49:36]
  assign io_slave_0_readData_ready = outstanding & _GEN_32; // @[AXIReadBus.scala 88:21 55:32]
  assign io_slave_1_readAddr_valid = outstanding & _GEN_30; // @[AXIReadBus.scala 88:21 44:32]
  assign io_slave_1_readAddr_bits_id = outstanding ? _GEN_39 : 4'h0; // @[AXIReadBus.scala 88:21 46:34]
  assign io_slave_1_readAddr_bits_addr = outstanding ? _GEN_27 : 32'h0; // @[AXIReadBus.scala 88:21 45:36]
  assign io_slave_1_readAddr_bits_size = outstanding ? _GEN_36 : 2'h0; // @[AXIReadBus.scala 88:21 49:36]
  assign io_slave_1_readData_ready = outstanding & _GEN_33; // @[AXIReadBus.scala 88:21 55:32]
  assign io_slave_2_readAddr_valid = outstanding & _GEN_31; // @[AXIReadBus.scala 88:21 44:32]
  assign io_slave_2_readAddr_bits_id = outstanding ? _GEN_40 : 4'h0; // @[AXIReadBus.scala 88:21 46:34]
  assign io_slave_2_readAddr_bits_addr = outstanding ? _GEN_28 : 32'h0; // @[AXIReadBus.scala 88:21 45:36]
  assign io_slave_2_readAddr_bits_size = outstanding ? _GEN_37 : 2'h0; // @[AXIReadBus.scala 88:21 49:36]
  assign io_slave_2_readData_ready = outstanding & _GEN_34; // @[AXIReadBus.scala 88:21 55:32]
  always @(posedge clock) begin
    if (reset) begin // @[AXIReadBus.scala 28:30]
      read_port_reg <= 3'h0; // @[AXIReadBus.scala 28:30]
    end else if (_T) begin // @[AXIReadBus.scala 66:33]
      read_port_reg <= {{1'd0}, read_port}; // @[AXIReadBus.scala 68:19]
    end
    if (reset) begin // @[AXIReadBus.scala 29:30]
      read_addr_reg <= 32'h0; // @[AXIReadBus.scala 29:30]
    end else if (_T) begin // @[AXIReadBus.scala 66:33]
      read_addr_reg <= io_master_readAddr_bits_addr; // @[AXIReadBus.scala 69:19]
    end
    if (reset) begin // @[AXIReadBus.scala 30:33]
      read_addr_reg_id <= 4'h0; // @[AXIReadBus.scala 30:33]
    end else if (_T) begin // @[AXIReadBus.scala 66:33]
      read_addr_reg_id <= io_master_readAddr_bits_id; // @[AXIReadBus.scala 70:22]
    end
    if (reset) begin // @[AXIReadBus.scala 31:35]
      read_addr_reg_size <= 3'h0; // @[AXIReadBus.scala 31:35]
    end else if (_T) begin // @[AXIReadBus.scala 66:33]
      read_addr_reg_size <= {{1'd0}, io_master_readAddr_bits_size}; // @[AXIReadBus.scala 71:24]
    end
    if (reset) begin // @[AXIReadBus.scala 32:36]
      read_addr_reg_valid <= 1'h0; // @[AXIReadBus.scala 32:36]
    end else if (read_addr_reg_valid) begin // @[AXIReadBus.scala 81:29]
      if (_GEN_8) begin // @[AXIReadBus.scala 82:50]
        read_addr_reg_valid <= 1'h0; // @[AXIReadBus.scala 83:27]
      end else begin
        read_addr_reg_valid <= _GEN_5;
      end
    end else begin
      read_addr_reg_valid <= _GEN_5;
    end
    if (reset) begin // @[AXIReadBus.scala 33:28]
      outstanding <= 1'h0; // @[AXIReadBus.scala 33:28]
    end else if (outstanding) begin // @[AXIReadBus.scala 88:21]
      if (_T_7) begin // @[AXIReadBus.scala 105:35]
        outstanding <= 1'h0; // @[AXIReadBus.scala 106:19]
      end else begin
        outstanding <= _GEN_0;
      end
    end else begin
      outstanding <= _GEN_0;
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  read_port_reg = _RAND_0[2:0];
  _RAND_1 = {1{`RANDOM}};
  read_addr_reg = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  read_addr_reg_id = _RAND_2[3:0];
  _RAND_3 = {1{`RANDOM}};
  read_addr_reg_size = _RAND_3[2:0];
  _RAND_4 = {1{`RANDOM}};
  read_addr_reg_valid = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  outstanding = _RAND_5[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module RRArbiter(
  input   clock,
  output  io_in_0_ready,
  input   io_in_0_valid,
  output  io_in_1_ready,
  input   io_in_1_valid,
  output  io_out_valid,
  output  io_chosen
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg  lastGrant; // @[Reg.scala 19:16]
  wire  grantMask_1 = 1'h1 > lastGrant; // @[Arbiter.scala 81:49]
  wire  validMask_1 = io_in_1_valid & grantMask_1; // @[Arbiter.scala 82:76]
  wire  ctrl_3 = ~(validMask_1 | io_in_0_valid); // @[Arbiter.scala 45:78]
  wire  _GEN_5 = io_in_0_valid ? 1'h0 : 1'h1; // @[Arbiter.scala 91:{26,35}]
  assign io_in_0_ready = ~validMask_1; // @[Arbiter.scala 45:78]
  assign io_in_1_ready = grantMask_1 | ctrl_3; // @[Arbiter.scala 86:50]
  assign io_out_valid = io_chosen ? io_in_1_valid : io_in_0_valid; // @[Arbiter.scala 55:{16,16}]
  assign io_chosen = validMask_1 | _GEN_5; // @[Arbiter.scala 93:{24,33}]
  always @(posedge clock) begin
    if (io_out_valid) begin // @[Reg.scala 20:18]
      lastGrant <= io_chosen; // @[Reg.scala 20:22]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  lastGrant = _RAND_0[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module AXISlaveReadMux(
  input         clock,
  input         reset,
  input         io_out_readAddr_ready,
  output        io_out_readAddr_valid,
  output [3:0]  io_out_readAddr_bits_id,
  output [31:0] io_out_readAddr_bits_addr,
  output [1:0]  io_out_readAddr_bits_size,
  output        io_out_readData_ready,
  input         io_out_readData_valid,
  input  [3:0]  io_out_readData_bits_id,
  input  [31:0] io_out_readData_bits_data,
  input  [1:0]  io_out_readData_bits_resp,
  input         io_out_readData_bits_last,
  output        io_in_0_readAddr_ready,
  input         io_in_0_readAddr_valid,
  input  [3:0]  io_in_0_readAddr_bits_id,
  input  [31:0] io_in_0_readAddr_bits_addr,
  input  [1:0]  io_in_0_readAddr_bits_size,
  input         io_in_0_readData_ready,
  output        io_in_0_readData_valid,
  output [3:0]  io_in_0_readData_bits_id,
  output [31:0] io_in_0_readData_bits_data,
  output [1:0]  io_in_0_readData_bits_resp,
  output        io_in_0_readData_bits_last,
  output        io_in_1_readAddr_ready,
  input         io_in_1_readAddr_valid,
  input  [3:0]  io_in_1_readAddr_bits_id,
  input  [31:0] io_in_1_readAddr_bits_addr,
  input  [1:0]  io_in_1_readAddr_bits_size,
  input         io_in_1_readData_ready,
  output        io_in_1_readData_valid,
  output [3:0]  io_in_1_readData_bits_id,
  output [31:0] io_in_1_readData_bits_data,
  output [1:0]  io_in_1_readData_bits_resp,
  output        io_in_1_readData_bits_last
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
`endif // RANDOMIZE_REG_INIT
  wire  arbiter_clock; // @[AXISlaveReadMux.scala 35:23]
  wire  arbiter_io_in_0_ready; // @[AXISlaveReadMux.scala 35:23]
  wire  arbiter_io_in_0_valid; // @[AXISlaveReadMux.scala 35:23]
  wire  arbiter_io_in_1_ready; // @[AXISlaveReadMux.scala 35:23]
  wire  arbiter_io_in_1_valid; // @[AXISlaveReadMux.scala 35:23]
  wire  arbiter_io_out_valid; // @[AXISlaveReadMux.scala 35:23]
  wire  arbiter_io_chosen; // @[AXISlaveReadMux.scala 35:23]
  reg [1:0] state; // @[AXISlaveReadMux.scala 30:22]
  wire  outstanding = io_in_0_readAddr_valid | io_in_1_readAddr_valid; // @[AXISlaveReadMux.scala 33:95]
  reg  chosen_reg; // @[AXISlaveReadMux.scala 36:27]
  reg  ar_determined; // @[AXISlaveReadMux.scala 37:30]
  reg [3:0] address_reg_id; // @[AXISlaveReadMux.scala 38:28]
  reg [31:0] address_reg_addr; // @[AXISlaveReadMux.scala 38:28]
  reg [1:0] address_reg_size; // @[AXISlaveReadMux.scala 38:28]
  reg [3:0] data_reg_id; // @[AXISlaveReadMux.scala 43:25]
  reg [31:0] data_reg_data; // @[AXISlaveReadMux.scala 43:25]
  reg [1:0] data_reg_resp; // @[AXISlaveReadMux.scala 43:25]
  reg  data_reg_last; // @[AXISlaveReadMux.scala 43:25]
  wire  _T_8 = state == 2'h1; // @[AXISlaveReadMux.scala 106:19]
  wire  _GEN_49 = state == 2'h2 ? 1'h0 : 1'h1; // @[AXISlaveReadMux.scala 116:31 117:20]
  wire  _GEN_53 = state == 2'h1 ? 1'h0 : _GEN_49; // @[AXISlaveReadMux.scala 106:33 107:22]
  wire  mask_0 = state == 2'h0 | _GEN_53; // @[AXISlaveReadMux.scala 97:24 98:20]
  wire  _T_2 = io_out_readData_ready & io_out_readData_valid; // @[Decoupled.scala 52:35]
  wire  _GEN_3 = chosen_reg ? io_in_1_readData_ready : io_in_0_readData_ready; // @[Decoupled.scala 52:{35,35}]
  wire  _GEN_5 = chosen_reg ? io_in_1_readData_valid : io_in_0_readData_valid; // @[Decoupled.scala 52:{35,35}]
  wire  _T_6 = _GEN_3 & _GEN_5; // @[Decoupled.scala 52:35]
  wire [1:0] _GEN_6 = _T_6 ? 2'h0 : state; // @[AXISlaveReadMux.scala 91:44 92:15 30:22]
  wire  _GEN_41 = arbiter_io_out_valid | ar_determined; // @[AXISlaveReadMux.scala 102:21 37:30 99:31]
  wire  _T_9 = io_out_readAddr_ready & io_out_readAddr_valid; // @[Decoupled.scala 52:35]
  wire  _GEN_47 = ~chosen_reg; // @[AXISlaveReadMux.scala 118:{38,38} 65:29]
  wire  _GEN_51 = state == 2'h2 & _GEN_47; // @[AXISlaveReadMux.scala 116:31 65:29]
  wire  _GEN_52 = state == 2'h2 & chosen_reg; // @[AXISlaveReadMux.scala 116:31 65:29]
  wire  _GEN_61 = state == 2'h1 ? 1'h0 : _GEN_51; // @[AXISlaveReadMux.scala 106:33 65:29]
  wire  _GEN_62 = state == 2'h1 ? 1'h0 : _GEN_52; // @[AXISlaveReadMux.scala 106:33 65:29]
  RRArbiter arbiter ( // @[AXISlaveReadMux.scala 35:23]
    .clock(arbiter_clock),
    .io_in_0_ready(arbiter_io_in_0_ready),
    .io_in_0_valid(arbiter_io_in_0_valid),
    .io_in_1_ready(arbiter_io_in_1_ready),
    .io_in_1_valid(arbiter_io_in_1_valid),
    .io_out_valid(arbiter_io_out_valid),
    .io_chosen(arbiter_io_chosen)
  );
  assign io_out_readAddr_valid = ar_determined; // @[AXISlaveReadMux.scala 77:25]
  assign io_out_readAddr_bits_id = address_reg_id; // @[AXISlaveReadMux.scala 121:24]
  assign io_out_readAddr_bits_addr = address_reg_addr; // @[AXISlaveReadMux.scala 121:24]
  assign io_out_readAddr_bits_size = address_reg_size; // @[AXISlaveReadMux.scala 121:24]
  assign io_out_readData_ready = state == 2'h0 ? 1'h0 : _T_8; // @[AXISlaveReadMux.scala 97:24 104:27]
  assign io_in_0_readAddr_ready = arbiter_io_in_0_ready & mask_0; // @[AXISlaveReadMux.scala 72:55]
  assign io_in_0_readData_valid = state == 2'h0 ? 1'h0 : _GEN_61; // @[AXISlaveReadMux.scala 97:24 65:29]
  assign io_in_0_readData_bits_id = ~chosen_reg ? data_reg_id : 4'h0; // @[AXISlaveReadMux.scala 122:{35,35} 67:31]
  assign io_in_0_readData_bits_data = ~chosen_reg ? data_reg_data : 32'h0; // @[AXISlaveReadMux.scala 122:{35,35} 64:33]
  assign io_in_0_readData_bits_resp = ~chosen_reg ? data_reg_resp : 2'h0; // @[AXISlaveReadMux.scala 122:{35,35} 66:33]
  assign io_in_0_readData_bits_last = ~chosen_reg ? data_reg_last : 1'h1; // @[AXISlaveReadMux.scala 122:{35,35} 68:33]
  assign io_in_1_readAddr_ready = arbiter_io_in_1_ready & mask_0; // @[AXISlaveReadMux.scala 72:55]
  assign io_in_1_readData_valid = state == 2'h0 ? 1'h0 : _GEN_62; // @[AXISlaveReadMux.scala 97:24 65:29]
  assign io_in_1_readData_bits_id = chosen_reg ? data_reg_id : 4'h0; // @[AXISlaveReadMux.scala 122:{35,35} 67:31]
  assign io_in_1_readData_bits_data = chosen_reg ? data_reg_data : 32'h0; // @[AXISlaveReadMux.scala 122:{35,35} 64:33]
  assign io_in_1_readData_bits_resp = chosen_reg ? data_reg_resp : 2'h0; // @[AXISlaveReadMux.scala 122:{35,35} 66:33]
  assign io_in_1_readData_bits_last = chosen_reg ? data_reg_last : 1'h1; // @[AXISlaveReadMux.scala 122:{35,35} 68:33]
  assign arbiter_clock = clock;
  assign arbiter_io_in_0_valid = io_in_0_readAddr_valid & mask_0; // @[AXISlaveReadMux.scala 73:55]
  assign arbiter_io_in_1_valid = io_in_1_readAddr_valid & mask_0; // @[AXISlaveReadMux.scala 73:55]
  always @(posedge clock) begin
    if (reset) begin // @[AXISlaveReadMux.scala 30:22]
      state <= 2'h0; // @[AXISlaveReadMux.scala 30:22]
    end else if (2'h0 == state) begin // @[AXISlaveReadMux.scala 79:16]
      if (outstanding) begin // @[AXISlaveReadMux.scala 81:24]
        state <= 2'h1; // @[AXISlaveReadMux.scala 82:15]
      end
    end else if (2'h1 == state) begin // @[AXISlaveReadMux.scala 79:16]
      if (_T_2) begin // @[AXISlaveReadMux.scala 86:33]
        state <= 2'h2; // @[AXISlaveReadMux.scala 87:15]
      end
    end else if (2'h2 == state) begin // @[AXISlaveReadMux.scala 79:16]
      state <= _GEN_6;
    end
    if (reset) begin // @[AXISlaveReadMux.scala 36:27]
      chosen_reg <= 1'h0; // @[AXISlaveReadMux.scala 36:27]
    end else if (state == 2'h0) begin // @[AXISlaveReadMux.scala 97:24]
      if (arbiter_io_out_valid) begin // @[AXISlaveReadMux.scala 99:31]
        chosen_reg <= arbiter_io_chosen; // @[AXISlaveReadMux.scala 100:18]
      end
    end
    if (reset) begin // @[AXISlaveReadMux.scala 37:30]
      ar_determined <= 1'h0; // @[AXISlaveReadMux.scala 37:30]
    end else if (state == 2'h0) begin // @[AXISlaveReadMux.scala 97:24]
      ar_determined <= _GEN_41;
    end else if (state == 2'h1) begin // @[AXISlaveReadMux.scala 106:33]
      if (_T_9) begin // @[AXISlaveReadMux.scala 108:33]
        ar_determined <= 1'h0; // @[AXISlaveReadMux.scala 109:23]
      end
    end
    if (reset) begin // @[AXISlaveReadMux.scala 38:28]
      address_reg_id <= 4'h0; // @[AXISlaveReadMux.scala 38:28]
    end else if (state == 2'h0) begin // @[AXISlaveReadMux.scala 97:24]
      if (arbiter_io_out_valid) begin // @[AXISlaveReadMux.scala 99:31]
        if (arbiter_io_chosen) begin // @[AXISlaveReadMux.scala 101:19]
          address_reg_id <= io_in_1_readAddr_bits_id; // @[AXISlaveReadMux.scala 101:19]
        end else begin
          address_reg_id <= io_in_0_readAddr_bits_id;
        end
      end
    end
    if (reset) begin // @[AXISlaveReadMux.scala 38:28]
      address_reg_addr <= 32'h0; // @[AXISlaveReadMux.scala 38:28]
    end else if (state == 2'h0) begin // @[AXISlaveReadMux.scala 97:24]
      if (arbiter_io_out_valid) begin // @[AXISlaveReadMux.scala 99:31]
        if (arbiter_io_chosen) begin // @[AXISlaveReadMux.scala 101:19]
          address_reg_addr <= io_in_1_readAddr_bits_addr; // @[AXISlaveReadMux.scala 101:19]
        end else begin
          address_reg_addr <= io_in_0_readAddr_bits_addr;
        end
      end
    end
    if (reset) begin // @[AXISlaveReadMux.scala 38:28]
      address_reg_size <= 2'h0; // @[AXISlaveReadMux.scala 38:28]
    end else if (state == 2'h0) begin // @[AXISlaveReadMux.scala 97:24]
      if (arbiter_io_out_valid) begin // @[AXISlaveReadMux.scala 99:31]
        if (arbiter_io_chosen) begin // @[AXISlaveReadMux.scala 101:19]
          address_reg_size <= io_in_1_readAddr_bits_size; // @[AXISlaveReadMux.scala 101:19]
        end else begin
          address_reg_size <= io_in_0_readAddr_bits_size;
        end
      end
    end
    if (reset) begin // @[AXISlaveReadMux.scala 43:25]
      data_reg_id <= 4'h0; // @[AXISlaveReadMux.scala 43:25]
    end else if (!(state == 2'h0)) begin // @[AXISlaveReadMux.scala 97:24]
      if (state == 2'h1) begin // @[AXISlaveReadMux.scala 106:33]
        if (_T_2) begin // @[AXISlaveReadMux.scala 111:33]
          data_reg_id <= io_out_readData_bits_id; // @[AXISlaveReadMux.scala 112:18]
        end
      end
    end
    if (reset) begin // @[AXISlaveReadMux.scala 43:25]
      data_reg_data <= 32'h0; // @[AXISlaveReadMux.scala 43:25]
    end else if (!(state == 2'h0)) begin // @[AXISlaveReadMux.scala 97:24]
      if (state == 2'h1) begin // @[AXISlaveReadMux.scala 106:33]
        if (_T_2) begin // @[AXISlaveReadMux.scala 111:33]
          data_reg_data <= io_out_readData_bits_data; // @[AXISlaveReadMux.scala 112:18]
        end
      end
    end
    if (reset) begin // @[AXISlaveReadMux.scala 43:25]
      data_reg_resp <= 2'h0; // @[AXISlaveReadMux.scala 43:25]
    end else if (!(state == 2'h0)) begin // @[AXISlaveReadMux.scala 97:24]
      if (state == 2'h1) begin // @[AXISlaveReadMux.scala 106:33]
        if (_T_2) begin // @[AXISlaveReadMux.scala 111:33]
          data_reg_resp <= io_out_readData_bits_resp; // @[AXISlaveReadMux.scala 112:18]
        end
      end
    end
    if (reset) begin // @[AXISlaveReadMux.scala 43:25]
      data_reg_last <= 1'h0; // @[AXISlaveReadMux.scala 43:25]
    end else if (!(state == 2'h0)) begin // @[AXISlaveReadMux.scala 97:24]
      if (state == 2'h1) begin // @[AXISlaveReadMux.scala 106:33]
        if (_T_2) begin // @[AXISlaveReadMux.scala 111:33]
          data_reg_last <= io_out_readData_bits_last; // @[AXISlaveReadMux.scala 112:18]
        end
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  state = _RAND_0[1:0];
  _RAND_1 = {1{`RANDOM}};
  chosen_reg = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  ar_determined = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  address_reg_id = _RAND_3[3:0];
  _RAND_4 = {1{`RANDOM}};
  address_reg_addr = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  address_reg_size = _RAND_5[1:0];
  _RAND_6 = {1{`RANDOM}};
  data_reg_id = _RAND_6[3:0];
  _RAND_7 = {1{`RANDOM}};
  data_reg_data = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  data_reg_resp = _RAND_8[1:0];
  _RAND_9 = {1{`RANDOM}};
  data_reg_last = _RAND_9[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module AXIWriteBus(
  input         clock,
  input         reset,
  output        io_master_writeAddr_ready,
  input         io_master_writeAddr_valid,
  input  [3:0]  io_master_writeAddr_bits_id,
  input  [31:0] io_master_writeAddr_bits_addr,
  input  [1:0]  io_master_writeAddr_bits_size,
  output        io_master_writeData_ready,
  input         io_master_writeData_valid,
  input  [31:0] io_master_writeData_bits_data,
  input  [3:0]  io_master_writeData_bits_strb,
  input         io_master_writeData_bits_last,
  input         io_master_writeResp_ready,
  output        io_master_writeResp_valid,
  output [3:0]  io_master_writeResp_bits_id,
  output [1:0]  io_master_writeResp_bits_resp,
  input         io_slave_0_writeAddr_ready,
  output        io_slave_0_writeAddr_valid,
  output [3:0]  io_slave_0_writeAddr_bits_id,
  output [31:0] io_slave_0_writeAddr_bits_addr,
  output [1:0]  io_slave_0_writeAddr_bits_size,
  input         io_slave_0_writeData_ready,
  output        io_slave_0_writeData_valid,
  output [31:0] io_slave_0_writeData_bits_data,
  output [3:0]  io_slave_0_writeData_bits_strb,
  output        io_slave_0_writeData_bits_last,
  output        io_slave_0_writeResp_ready,
  input         io_slave_0_writeResp_valid,
  input  [3:0]  io_slave_0_writeResp_bits_id,
  input  [1:0]  io_slave_0_writeResp_bits_resp,
  input         io_slave_1_writeAddr_ready,
  output        io_slave_1_writeAddr_valid,
  output [3:0]  io_slave_1_writeAddr_bits_id,
  output [31:0] io_slave_1_writeAddr_bits_addr,
  output [1:0]  io_slave_1_writeAddr_bits_size,
  input         io_slave_1_writeData_ready,
  output        io_slave_1_writeData_valid,
  output [31:0] io_slave_1_writeData_bits_data,
  output [3:0]  io_slave_1_writeData_bits_strb,
  output        io_slave_1_writeData_bits_last,
  output        io_slave_1_writeResp_ready,
  input         io_slave_1_writeResp_valid,
  input  [3:0]  io_slave_1_writeResp_bits_id,
  input  [1:0]  io_slave_1_writeResp_bits_resp,
  input         io_slave_2_writeAddr_ready,
  output        io_slave_2_writeAddr_valid,
  output [3:0]  io_slave_2_writeAddr_bits_id,
  output [31:0] io_slave_2_writeAddr_bits_addr,
  output [1:0]  io_slave_2_writeAddr_bits_size,
  input         io_slave_2_writeData_ready,
  output        io_slave_2_writeData_valid,
  output [31:0] io_slave_2_writeData_bits_data,
  output [3:0]  io_slave_2_writeData_bits_strb,
  output        io_slave_2_writeData_bits_last,
  output        io_slave_2_writeResp_ready,
  input         io_slave_2_writeResp_valid,
  input  [3:0]  io_slave_2_writeResp_bits_id,
  input  [1:0]  io_slave_2_writeResp_bits_resp
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
`endif // RANDOMIZE_REG_INIT
  wire  _write_port_T_1 = io_master_writeAddr_bits_addr < 32'h64; // @[AXIWriteBus.scala 28:87]
  wire  _write_port_T_5 = io_master_writeAddr_bits_addr >= 32'h8000 & io_master_writeAddr_bits_addr < 32'h8800; // @[AXIWriteBus.scala 28:54]
  wire  _write_port_T_8 = io_master_writeAddr_bits_addr >= 32'h10000 & io_master_writeAddr_bits_addr < 32'h10800; // @[AXIWriteBus.scala 28:54]
  wire [1:0] _write_port_T_9 = _write_port_T_8 ? 2'h2 : 2'h0; // @[Mux.scala 101:16]
  wire [1:0] _write_port_T_10 = _write_port_T_5 ? 2'h1 : _write_port_T_9; // @[Mux.scala 101:16]
  wire [1:0] write_port = _write_port_T_1 ? 2'h0 : _write_port_T_10; // @[Mux.scala 101:16]
  reg [2:0] write_port_reg; // @[AXIWriteBus.scala 31:31]
  reg [31:0] write_addr_reg; // @[AXIWriteBus.scala 33:31]
  reg  write_addr_reg_valid; // @[AXIWriteBus.scala 34:37]
  reg [3:0] write_addr_reg_id; // @[AXIWriteBus.scala 35:34]
  reg [2:0] write_addr_reg_size; // @[AXIWriteBus.scala 36:36]
  reg [31:0] write_data_reg; // @[AXIWriteBus.scala 38:31]
  reg  write_data_reg_valid; // @[AXIWriteBus.scala 39:37]
  reg [3:0] write_data_reg_strb; // @[AXIWriteBus.scala 40:36]
  reg  write_data_reg_last; // @[AXIWriteBus.scala 41:36]
  reg [3:0] write_resp_reg; // @[AXIWriteBus.scala 43:31]
  reg  write_resp_reg_valid; // @[AXIWriteBus.scala 44:37]
  reg [3:0] write_resp_reg_id; // @[AXIWriteBus.scala 45:34]
  reg  w_outstanding; // @[AXIWriteBus.scala 48:30]
  reg  aw_outstanding; // @[AXIWriteBus.scala 49:31]
  reg  b_outstanding; // @[AXIWriteBus.scala 50:30]
  wire  _T = io_master_writeAddr_ready & io_master_writeAddr_valid; // @[Decoupled.scala 52:35]
  wire  _GEN_0 = _T | aw_outstanding; // @[AXIWriteBus.scala 80:34 81:20 49:31]
  wire  _GEN_3 = _T | write_addr_reg_valid; // @[AXIWriteBus.scala 80:34 84:26 34:37]
  wire  _T_1 = io_master_writeData_ready & io_master_writeData_valid; // @[Decoupled.scala 52:35]
  wire  _GEN_6 = _T_1 | w_outstanding; // @[AXIWriteBus.scala 88:34 89:19 48:30]
  wire  _GEN_9 = _T_1 | write_data_reg_valid; // @[AXIWriteBus.scala 88:34 92:26 39:37]
  wire  _GEN_12 = 2'h1 == write_port_reg[1:0] ? io_slave_1_writeAddr_ready : io_slave_0_writeAddr_ready; // @[AXIWriteBus.scala 97:{29,29}]
  wire  _GEN_13 = 2'h2 == write_port_reg[1:0] ? io_slave_2_writeAddr_ready : _GEN_12; // @[AXIWriteBus.scala 97:{29,29}]
  wire  _GEN_16 = 2'h1 == write_port_reg[1:0] ? io_slave_1_writeData_ready : io_slave_0_writeData_ready; // @[AXIWriteBus.scala 100:{29,29}]
  wire  _GEN_17 = 2'h2 == write_port_reg[1:0] ? io_slave_2_writeData_ready : _GEN_16; // @[AXIWriteBus.scala 100:{29,29}]
  wire  _GEN_19 = aw_outstanding & w_outstanding & write_resp_reg_valid & io_master_writeResp_ready ? 1'h0 :
    write_resp_reg_valid; // @[AXIWriteBus.scala 105:94 106:28 44:37]
  wire  _GEN_22 = aw_outstanding & w_outstanding & write_resp_reg_valid & io_master_writeResp_ready ? 1'h0 :
    b_outstanding; // @[AXIWriteBus.scala 105:94 109:21 50:30]
  wire  _GEN_24 = 2'h1 == write_port_reg[1:0] ? io_slave_1_writeResp_ready : io_slave_0_writeResp_ready; // @[Decoupled.scala 52:{35,35}]
  wire  _GEN_25 = 2'h2 == write_port_reg[1:0] ? io_slave_2_writeResp_ready : _GEN_24; // @[Decoupled.scala 52:{35,35}]
  wire  _GEN_27 = 2'h1 == write_port_reg[1:0] ? io_slave_1_writeResp_valid : io_slave_0_writeResp_valid; // @[Decoupled.scala 52:{35,35}]
  wire  _GEN_28 = 2'h2 == write_port_reg[1:0] ? io_slave_2_writeResp_valid : _GEN_27; // @[Decoupled.scala 52:{35,35}]
  wire  _T_10 = _GEN_25 & _GEN_28; // @[Decoupled.scala 52:35]
  wire [1:0] _GEN_30 = 2'h1 == write_port_reg[1:0] ? io_slave_1_writeResp_bits_resp : io_slave_0_writeResp_bits_resp; // @[AXIWriteBus.scala 117:{22,22}]
  wire [1:0] _GEN_31 = 2'h2 == write_port_reg[1:0] ? io_slave_2_writeResp_bits_resp : _GEN_30; // @[AXIWriteBus.scala 117:{22,22}]
  wire [3:0] _GEN_33 = 2'h1 == write_port_reg[1:0] ? io_slave_1_writeResp_bits_id : io_slave_0_writeResp_bits_id; // @[AXIWriteBus.scala 118:{25,25}]
  wire  _GEN_35 = _T_10 | _GEN_22; // @[AXIWriteBus.scala 114:50 115:21]
  wire  _GEN_36 = _T_10 | _GEN_19; // @[AXIWriteBus.scala 114:50 116:28]
  wire [31:0] _GEN_39 = 2'h0 == write_port_reg[1:0] ? write_addr_reg : 32'h0; // @[AXIWriteBus.scala 121:{50,50} 59:37]
  wire [31:0] _GEN_40 = 2'h1 == write_port_reg[1:0] ? write_addr_reg : 32'h0; // @[AXIWriteBus.scala 121:{50,50} 59:37]
  wire [31:0] _GEN_41 = 2'h2 == write_port_reg[1:0] ? write_addr_reg : 32'h0; // @[AXIWriteBus.scala 121:{50,50} 59:37]
  wire  _GEN_97 = 2'h0 == write_port_reg[1:0]; // @[AXIWriteBus.scala 122:{46,46} 58:33]
  wire  _GEN_42 = 2'h0 == write_port_reg[1:0] & write_addr_reg_valid; // @[AXIWriteBus.scala 122:{46,46} 58:33]
  wire  _GEN_98 = 2'h1 == write_port_reg[1:0]; // @[AXIWriteBus.scala 122:{46,46} 58:33]
  wire  _GEN_43 = 2'h1 == write_port_reg[1:0] & write_addr_reg_valid; // @[AXIWriteBus.scala 122:{46,46} 58:33]
  wire  _GEN_99 = 2'h2 == write_port_reg[1:0]; // @[AXIWriteBus.scala 122:{46,46} 58:33]
  wire  _GEN_44 = 2'h2 == write_port_reg[1:0] & write_addr_reg_valid; // @[AXIWriteBus.scala 122:{46,46} 58:33]
  wire [3:0] _GEN_45 = 2'h0 == write_port_reg[1:0] ? write_addr_reg_id : 4'h0; // @[AXIWriteBus.scala 123:{48,48} 60:35]
  wire [3:0] _GEN_46 = 2'h1 == write_port_reg[1:0] ? write_addr_reg_id : 4'h0; // @[AXIWriteBus.scala 123:{48,48} 60:35]
  wire [3:0] _GEN_47 = 2'h2 == write_port_reg[1:0] ? write_addr_reg_id : 4'h0; // @[AXIWriteBus.scala 123:{48,48} 60:35]
  wire [1:0] _GEN_48 = 2'h0 == write_port_reg[1:0] ? write_addr_reg_size[1:0] : 2'h0; // @[AXIWriteBus.scala 124:{50,50} 63:37]
  wire [1:0] _GEN_49 = 2'h1 == write_port_reg[1:0] ? write_addr_reg_size[1:0] : 2'h0; // @[AXIWriteBus.scala 124:{50,50} 63:37]
  wire [1:0] _GEN_50 = 2'h2 == write_port_reg[1:0] ? write_addr_reg_size[1:0] : 2'h0; // @[AXIWriteBus.scala 124:{50,50} 63:37]
  wire [31:0] _GEN_51 = 2'h0 == write_port_reg[1:0] ? write_data_reg : 32'h0; // @[AXIWriteBus.scala 125:{50,50} 55:37]
  wire [31:0] _GEN_52 = 2'h1 == write_port_reg[1:0] ? write_data_reg : 32'h0; // @[AXIWriteBus.scala 125:{50,50} 55:37]
  wire [31:0] _GEN_53 = 2'h2 == write_port_reg[1:0] ? write_data_reg : 32'h0; // @[AXIWriteBus.scala 125:{50,50} 55:37]
  wire [3:0] _GEN_54 = 2'h0 == write_port_reg[1:0] ? write_data_reg_strb : 4'h0; // @[AXIWriteBus.scala 126:{50,50} 56:37]
  wire [3:0] _GEN_55 = 2'h1 == write_port_reg[1:0] ? write_data_reg_strb : 4'h0; // @[AXIWriteBus.scala 126:{50,50} 56:37]
  wire [3:0] _GEN_56 = 2'h2 == write_port_reg[1:0] ? write_data_reg_strb : 4'h0; // @[AXIWriteBus.scala 126:{50,50} 56:37]
  wire  _GEN_57 = _GEN_97 & write_data_reg_valid; // @[AXIWriteBus.scala 127:{46,46} 54:33]
  wire  _GEN_58 = _GEN_98 & write_data_reg_valid; // @[AXIWriteBus.scala 127:{46,46} 54:33]
  wire  _GEN_59 = _GEN_99 & write_data_reg_valid; // @[AXIWriteBus.scala 127:{46,46} 54:33]
  wire  _GEN_60 = _GEN_97 & write_data_reg_last; // @[AXIWriteBus.scala 128:{50,50} 57:37]
  wire  _GEN_61 = _GEN_98 & write_data_reg_last; // @[AXIWriteBus.scala 128:{50,50} 57:37]
  wire  _GEN_62 = _GEN_99 & write_data_reg_last; // @[AXIWriteBus.scala 128:{50,50} 57:37]
  wire  _GEN_63 = _GEN_97 & ~b_outstanding; // @[AXIWriteBus.scala 129:{46,46} 69:33]
  wire  _GEN_64 = _GEN_98 & ~b_outstanding; // @[AXIWriteBus.scala 129:{46,46} 69:33]
  wire  _GEN_65 = _GEN_99 & ~b_outstanding; // @[AXIWriteBus.scala 129:{46,46} 69:33]
  assign io_master_writeAddr_ready = ~aw_outstanding; // @[AXIWriteBus.scala 73:32]
  assign io_master_writeData_ready = ~w_outstanding; // @[AXIWriteBus.scala 72:32]
  assign io_master_writeResp_valid = write_resp_reg_valid; // @[AXIWriteBus.scala 74:29]
  assign io_master_writeResp_bits_id = write_resp_reg_id; // @[AXIWriteBus.scala 76:31]
  assign io_master_writeResp_bits_resp = write_resp_reg[1:0]; // @[AXIWriteBus.scala 75:33]
  assign io_slave_0_writeAddr_valid = aw_outstanding & _GEN_42; // @[AXIWriteBus.scala 112:24 58:33]
  assign io_slave_0_writeAddr_bits_id = aw_outstanding ? _GEN_45 : 4'h0; // @[AXIWriteBus.scala 112:24 60:35]
  assign io_slave_0_writeAddr_bits_addr = aw_outstanding ? _GEN_39 : 32'h0; // @[AXIWriteBus.scala 112:24 59:37]
  assign io_slave_0_writeAddr_bits_size = aw_outstanding ? _GEN_48 : 2'h0; // @[AXIWriteBus.scala 112:24 63:37]
  assign io_slave_0_writeData_valid = aw_outstanding & _GEN_57; // @[AXIWriteBus.scala 112:24 54:33]
  assign io_slave_0_writeData_bits_data = aw_outstanding ? _GEN_51 : 32'h0; // @[AXIWriteBus.scala 112:24 55:37]
  assign io_slave_0_writeData_bits_strb = aw_outstanding ? _GEN_54 : 4'h0; // @[AXIWriteBus.scala 112:24 56:37]
  assign io_slave_0_writeData_bits_last = aw_outstanding & _GEN_60; // @[AXIWriteBus.scala 112:24 57:37]
  assign io_slave_0_writeResp_ready = aw_outstanding & _GEN_63; // @[AXIWriteBus.scala 112:24 69:33]
  assign io_slave_1_writeAddr_valid = aw_outstanding & _GEN_43; // @[AXIWriteBus.scala 112:24 58:33]
  assign io_slave_1_writeAddr_bits_id = aw_outstanding ? _GEN_46 : 4'h0; // @[AXIWriteBus.scala 112:24 60:35]
  assign io_slave_1_writeAddr_bits_addr = aw_outstanding ? _GEN_40 : 32'h0; // @[AXIWriteBus.scala 112:24 59:37]
  assign io_slave_1_writeAddr_bits_size = aw_outstanding ? _GEN_49 : 2'h0; // @[AXIWriteBus.scala 112:24 63:37]
  assign io_slave_1_writeData_valid = aw_outstanding & _GEN_58; // @[AXIWriteBus.scala 112:24 54:33]
  assign io_slave_1_writeData_bits_data = aw_outstanding ? _GEN_52 : 32'h0; // @[AXIWriteBus.scala 112:24 55:37]
  assign io_slave_1_writeData_bits_strb = aw_outstanding ? _GEN_55 : 4'h0; // @[AXIWriteBus.scala 112:24 56:37]
  assign io_slave_1_writeData_bits_last = aw_outstanding & _GEN_61; // @[AXIWriteBus.scala 112:24 57:37]
  assign io_slave_1_writeResp_ready = aw_outstanding & _GEN_64; // @[AXIWriteBus.scala 112:24 69:33]
  assign io_slave_2_writeAddr_valid = aw_outstanding & _GEN_44; // @[AXIWriteBus.scala 112:24 58:33]
  assign io_slave_2_writeAddr_bits_id = aw_outstanding ? _GEN_47 : 4'h0; // @[AXIWriteBus.scala 112:24 60:35]
  assign io_slave_2_writeAddr_bits_addr = aw_outstanding ? _GEN_41 : 32'h0; // @[AXIWriteBus.scala 112:24 59:37]
  assign io_slave_2_writeAddr_bits_size = aw_outstanding ? _GEN_50 : 2'h0; // @[AXIWriteBus.scala 112:24 63:37]
  assign io_slave_2_writeData_valid = aw_outstanding & _GEN_59; // @[AXIWriteBus.scala 112:24 54:33]
  assign io_slave_2_writeData_bits_data = aw_outstanding ? _GEN_53 : 32'h0; // @[AXIWriteBus.scala 112:24 55:37]
  assign io_slave_2_writeData_bits_strb = aw_outstanding ? _GEN_56 : 4'h0; // @[AXIWriteBus.scala 112:24 56:37]
  assign io_slave_2_writeData_bits_last = aw_outstanding & _GEN_62; // @[AXIWriteBus.scala 112:24 57:37]
  assign io_slave_2_writeResp_ready = aw_outstanding & _GEN_65; // @[AXIWriteBus.scala 112:24 69:33]
  always @(posedge clock) begin
    if (reset) begin // @[AXIWriteBus.scala 31:31]
      write_port_reg <= 3'h0; // @[AXIWriteBus.scala 31:31]
    end else if (_T) begin // @[AXIWriteBus.scala 80:34]
      write_port_reg <= {{1'd0}, write_port}; // @[AXIWriteBus.scala 82:20]
    end
    if (reset) begin // @[AXIWriteBus.scala 33:31]
      write_addr_reg <= 32'h0; // @[AXIWriteBus.scala 33:31]
    end else if (_T) begin // @[AXIWriteBus.scala 80:34]
      write_addr_reg <= io_master_writeAddr_bits_addr; // @[AXIWriteBus.scala 83:20]
    end
    if (reset) begin // @[AXIWriteBus.scala 34:37]
      write_addr_reg_valid <= 1'h0; // @[AXIWriteBus.scala 34:37]
    end else if (write_addr_reg_valid & _GEN_13) begin // @[AXIWriteBus.scala 97:74]
      write_addr_reg_valid <= 1'h0; // @[AXIWriteBus.scala 98:28]
    end else begin
      write_addr_reg_valid <= _GEN_3;
    end
    if (reset) begin // @[AXIWriteBus.scala 35:34]
      write_addr_reg_id <= 4'h0; // @[AXIWriteBus.scala 35:34]
    end else if (_T) begin // @[AXIWriteBus.scala 80:34]
      write_addr_reg_id <= io_master_writeAddr_bits_id; // @[AXIWriteBus.scala 85:23]
    end
    if (reset) begin // @[AXIWriteBus.scala 36:36]
      write_addr_reg_size <= 3'h0; // @[AXIWriteBus.scala 36:36]
    end else if (_T) begin // @[AXIWriteBus.scala 80:34]
      write_addr_reg_size <= {{1'd0}, io_master_writeAddr_bits_size}; // @[AXIWriteBus.scala 86:25]
    end
    if (reset) begin // @[AXIWriteBus.scala 38:31]
      write_data_reg <= 32'h0; // @[AXIWriteBus.scala 38:31]
    end else if (_T_1) begin // @[AXIWriteBus.scala 88:34]
      write_data_reg <= io_master_writeData_bits_data; // @[AXIWriteBus.scala 91:20]
    end
    if (reset) begin // @[AXIWriteBus.scala 39:37]
      write_data_reg_valid <= 1'h0; // @[AXIWriteBus.scala 39:37]
    end else if (write_data_reg_valid & _GEN_17) begin // @[AXIWriteBus.scala 100:74]
      write_data_reg_valid <= 1'h0; // @[AXIWriteBus.scala 101:28]
    end else begin
      write_data_reg_valid <= _GEN_9;
    end
    if (reset) begin // @[AXIWriteBus.scala 40:36]
      write_data_reg_strb <= 4'h0; // @[AXIWriteBus.scala 40:36]
    end else if (_T_1) begin // @[AXIWriteBus.scala 88:34]
      write_data_reg_strb <= io_master_writeData_bits_strb; // @[AXIWriteBus.scala 90:25]
    end
    if (reset) begin // @[AXIWriteBus.scala 41:36]
      write_data_reg_last <= 1'h0; // @[AXIWriteBus.scala 41:36]
    end else if (_T_1) begin // @[AXIWriteBus.scala 88:34]
      write_data_reg_last <= io_master_writeData_bits_last; // @[AXIWriteBus.scala 93:25]
    end
    if (reset) begin // @[AXIWriteBus.scala 43:31]
      write_resp_reg <= 4'h0; // @[AXIWriteBus.scala 43:31]
    end else if (aw_outstanding) begin // @[AXIWriteBus.scala 112:24]
      if (_T_10) begin // @[AXIWriteBus.scala 114:50]
        write_resp_reg <= {{2'd0}, _GEN_31}; // @[AXIWriteBus.scala 117:22]
      end
    end
    if (reset) begin // @[AXIWriteBus.scala 44:37]
      write_resp_reg_valid <= 1'h0; // @[AXIWriteBus.scala 44:37]
    end else if (aw_outstanding) begin // @[AXIWriteBus.scala 112:24]
      write_resp_reg_valid <= _GEN_36;
    end else if (aw_outstanding & w_outstanding & write_resp_reg_valid & io_master_writeResp_ready) begin // @[AXIWriteBus.scala 105:94]
      write_resp_reg_valid <= 1'h0; // @[AXIWriteBus.scala 106:28]
    end
    if (reset) begin // @[AXIWriteBus.scala 45:34]
      write_resp_reg_id <= 4'h0; // @[AXIWriteBus.scala 45:34]
    end else if (aw_outstanding) begin // @[AXIWriteBus.scala 112:24]
      if (_T_10) begin // @[AXIWriteBus.scala 114:50]
        if (2'h2 == write_port_reg[1:0]) begin // @[AXIWriteBus.scala 118:25]
          write_resp_reg_id <= io_slave_2_writeResp_bits_id; // @[AXIWriteBus.scala 118:25]
        end else begin
          write_resp_reg_id <= _GEN_33;
        end
      end
    end
    if (reset) begin // @[AXIWriteBus.scala 48:30]
      w_outstanding <= 1'h0; // @[AXIWriteBus.scala 48:30]
    end else if (aw_outstanding & w_outstanding & write_resp_reg_valid & io_master_writeResp_ready) begin // @[AXIWriteBus.scala 105:94]
      w_outstanding <= 1'h0; // @[AXIWriteBus.scala 108:21]
    end else begin
      w_outstanding <= _GEN_6;
    end
    if (reset) begin // @[AXIWriteBus.scala 49:31]
      aw_outstanding <= 1'h0; // @[AXIWriteBus.scala 49:31]
    end else if (aw_outstanding & w_outstanding & write_resp_reg_valid & io_master_writeResp_ready) begin // @[AXIWriteBus.scala 105:94]
      aw_outstanding <= 1'h0; // @[AXIWriteBus.scala 107:22]
    end else begin
      aw_outstanding <= _GEN_0;
    end
    if (reset) begin // @[AXIWriteBus.scala 50:30]
      b_outstanding <= 1'h0; // @[AXIWriteBus.scala 50:30]
    end else if (aw_outstanding) begin // @[AXIWriteBus.scala 112:24]
      b_outstanding <= _GEN_35;
    end else if (aw_outstanding & w_outstanding & write_resp_reg_valid & io_master_writeResp_ready) begin // @[AXIWriteBus.scala 105:94]
      b_outstanding <= 1'h0; // @[AXIWriteBus.scala 109:21]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  write_port_reg = _RAND_0[2:0];
  _RAND_1 = {1{`RANDOM}};
  write_addr_reg = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  write_addr_reg_valid = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  write_addr_reg_id = _RAND_3[3:0];
  _RAND_4 = {1{`RANDOM}};
  write_addr_reg_size = _RAND_4[2:0];
  _RAND_5 = {1{`RANDOM}};
  write_data_reg = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  write_data_reg_valid = _RAND_6[0:0];
  _RAND_7 = {1{`RANDOM}};
  write_data_reg_strb = _RAND_7[3:0];
  _RAND_8 = {1{`RANDOM}};
  write_data_reg_last = _RAND_8[0:0];
  _RAND_9 = {1{`RANDOM}};
  write_resp_reg = _RAND_9[3:0];
  _RAND_10 = {1{`RANDOM}};
  write_resp_reg_valid = _RAND_10[0:0];
  _RAND_11 = {1{`RANDOM}};
  write_resp_reg_id = _RAND_11[3:0];
  _RAND_12 = {1{`RANDOM}};
  w_outstanding = _RAND_12[0:0];
  _RAND_13 = {1{`RANDOM}};
  aw_outstanding = _RAND_13[0:0];
  _RAND_14 = {1{`RANDOM}};
  b_outstanding = _RAND_14[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module AXISlaveWriteMux(
  input         clock,
  input         reset,
  input         io_out_writeAddr_ready,
  output        io_out_writeAddr_valid,
  output [3:0]  io_out_writeAddr_bits_id,
  output [31:0] io_out_writeAddr_bits_addr,
  output [1:0]  io_out_writeAddr_bits_size,
  input         io_out_writeData_ready,
  output        io_out_writeData_valid,
  output [31:0] io_out_writeData_bits_data,
  output [3:0]  io_out_writeData_bits_strb,
  output        io_out_writeData_bits_last,
  output        io_out_writeResp_ready,
  input         io_out_writeResp_valid,
  input  [3:0]  io_out_writeResp_bits_id,
  input  [1:0]  io_out_writeResp_bits_resp,
  output        io_in_0_writeAddr_ready,
  input         io_in_0_writeAddr_valid,
  input  [3:0]  io_in_0_writeAddr_bits_id,
  input  [31:0] io_in_0_writeAddr_bits_addr,
  input  [1:0]  io_in_0_writeAddr_bits_size,
  output        io_in_0_writeData_ready,
  input         io_in_0_writeData_valid,
  input  [31:0] io_in_0_writeData_bits_data,
  input  [3:0]  io_in_0_writeData_bits_strb,
  input         io_in_0_writeData_bits_last,
  input         io_in_0_writeResp_ready,
  output        io_in_0_writeResp_valid,
  output [3:0]  io_in_0_writeResp_bits_id,
  output [1:0]  io_in_0_writeResp_bits_resp,
  output        io_in_1_writeAddr_ready,
  input         io_in_1_writeAddr_valid,
  input  [3:0]  io_in_1_writeAddr_bits_id,
  input  [31:0] io_in_1_writeAddr_bits_addr,
  input  [1:0]  io_in_1_writeAddr_bits_size,
  output        io_in_1_writeData_ready,
  input         io_in_1_writeData_valid,
  input  [31:0] io_in_1_writeData_bits_data,
  input  [3:0]  io_in_1_writeData_bits_strb,
  input         io_in_1_writeData_bits_last,
  input         io_in_1_writeResp_ready,
  output        io_in_1_writeResp_valid,
  output [3:0]  io_in_1_writeResp_bits_id,
  output [1:0]  io_in_1_writeResp_bits_resp
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
`endif // RANDOMIZE_REG_INIT
  wire  arbiter_clock; // @[AXISlaveWriteMux.scala 38:23]
  wire  arbiter_io_in_0_ready; // @[AXISlaveWriteMux.scala 38:23]
  wire  arbiter_io_in_0_valid; // @[AXISlaveWriteMux.scala 38:23]
  wire  arbiter_io_in_1_ready; // @[AXISlaveWriteMux.scala 38:23]
  wire  arbiter_io_in_1_valid; // @[AXISlaveWriteMux.scala 38:23]
  wire  arbiter_io_out_valid; // @[AXISlaveWriteMux.scala 38:23]
  wire  arbiter_io_chosen; // @[AXISlaveWriteMux.scala 38:23]
  reg [1:0] state; // @[AXISlaveWriteMux.scala 32:22]
  wire  outstanding = io_in_0_writeAddr_valid | io_in_1_writeAddr_valid; // @[AXISlaveWriteMux.scala 35:96]
  reg  chosen_reg; // @[AXISlaveWriteMux.scala 39:27]
  reg  w_determined; // @[AXISlaveWriteMux.scala 40:29]
  reg  aw_determined; // @[AXISlaveWriteMux.scala 41:30]
  reg [3:0] address_reg_id; // @[AXISlaveWriteMux.scala 43:28]
  reg [31:0] address_reg_addr; // @[AXISlaveWriteMux.scala 43:28]
  reg [1:0] address_reg_size; // @[AXISlaveWriteMux.scala 43:28]
  reg [31:0] data_reg_data; // @[AXISlaveWriteMux.scala 48:25]
  reg [3:0] data_reg_strb; // @[AXISlaveWriteMux.scala 48:25]
  reg  data_reg_last; // @[AXISlaveWriteMux.scala 48:25]
  reg [3:0] resp_reg_id; // @[AXISlaveWriteMux.scala 53:25]
  reg [1:0] resp_reg_resp; // @[AXISlaveWriteMux.scala 53:25]
  wire  _T_21 = state == 2'h2; // @[AXISlaveWriteMux.scala 144:19]
  wire  _GEN_93 = state == 2'h3 ? 1'h0 : 1'h1; // @[AXISlaveWriteMux.scala 157:31 158:20]
  wire  _GEN_97 = state == 2'h2 ? 1'h0 : _GEN_93; // @[AXISlaveWriteMux.scala 144:33 145:22]
  wire  _GEN_106 = state == 2'h1 ? 1'h0 : _GEN_97; // @[AXISlaveWriteMux.scala 133:33 134:20]
  wire  mask_0 = state == 2'h0 | _GEN_106; // @[AXISlaveWriteMux.scala 117:24 119:20]
  wire  _GEN_1 = arbiter_io_chosen ? io_in_1_writeData_ready : io_in_0_writeData_ready; // @[Decoupled.scala 52:{35,35}]
  wire  _GEN_3 = arbiter_io_chosen ? io_in_1_writeData_valid : io_in_0_writeData_valid; // @[Decoupled.scala 52:{35,35}]
  wire  _T_1 = _GEN_1 & _GEN_3; // @[Decoupled.scala 52:35]
  wire  _GEN_7 = chosen_reg ? io_in_1_writeData_ready : io_in_0_writeData_ready; // @[Decoupled.scala 52:{35,35}]
  wire  _GEN_9 = chosen_reg ? io_in_1_writeData_valid : io_in_0_writeData_valid; // @[Decoupled.scala 52:{35,35}]
  wire  _T_5 = _GEN_7 & _GEN_9; // @[Decoupled.scala 52:35]
  wire  _T_7 = io_out_writeResp_ready & io_out_writeResp_valid; // @[Decoupled.scala 52:35]
  wire [1:0] _GEN_11 = _T_7 ? 2'h3 : state; // @[AXISlaveWriteMux.scala 106:34 107:15 32:22]
  wire  _GEN_13 = chosen_reg ? io_in_1_writeResp_ready : io_in_0_writeResp_ready; // @[Decoupled.scala 52:{35,35}]
  wire  _GEN_15 = chosen_reg ? io_in_1_writeResp_valid : io_in_0_writeResp_valid; // @[Decoupled.scala 52:{35,35}]
  wire  _T_11 = _GEN_13 & _GEN_15; // @[Decoupled.scala 52:35]
  wire [1:0] _GEN_16 = _T_11 ? 2'h0 : state; // @[AXISlaveWriteMux.scala 111:45 112:15 32:22]
  wire [1:0] _GEN_17 = 2'h3 == state ? _GEN_16 : state; // @[AXISlaveWriteMux.scala 88:16 32:22]
  wire  _GEN_21 = ~arbiter_io_chosen; // @[AXISlaveWriteMux.scala 122:{48,48} 72:30]
  wire  _GEN_22 = arbiter_io_chosen; // @[AXISlaveWriteMux.scala 122:{48,48} 72:30]
  wire [31:0] _GEN_44 = arbiter_io_chosen ? io_in_1_writeData_bits_data : io_in_0_writeData_bits_data; // @[AXISlaveWriteMux.scala 127:{18,18}]
  wire [3:0] _GEN_46 = arbiter_io_chosen ? io_in_1_writeData_bits_strb : io_in_0_writeData_bits_strb; // @[AXISlaveWriteMux.scala 127:{18,18}]
  wire  _GEN_48 = arbiter_io_chosen ? io_in_1_writeData_bits_last : io_in_0_writeData_bits_last; // @[AXISlaveWriteMux.scala 127:{18,18}]
  wire  _GEN_52 = _T_1 | w_determined; // @[AXISlaveWriteMux.scala 126:59 128:22 40:29]
  wire  _GEN_53 = arbiter_io_out_valid & _GEN_21; // @[AXISlaveWriteMux.scala 121:31 72:30]
  wire  _GEN_54 = arbiter_io_out_valid & _GEN_22; // @[AXISlaveWriteMux.scala 121:31 72:30]
  wire  _GEN_66 = arbiter_io_out_valid | aw_determined; // @[AXISlaveWriteMux.scala 121:31 125:21 41:30]
  wire [31:0] _GEN_76 = chosen_reg ? io_in_1_writeData_bits_data : io_in_0_writeData_bits_data; // @[AXISlaveWriteMux.scala 136:{16,16}]
  wire [3:0] _GEN_78 = chosen_reg ? io_in_1_writeData_bits_strb : io_in_0_writeData_bits_strb; // @[AXISlaveWriteMux.scala 136:{16,16}]
  wire  _GEN_80 = chosen_reg ? io_in_1_writeData_bits_last : io_in_0_writeData_bits_last; // @[AXISlaveWriteMux.scala 136:{16,16}]
  wire  _T_18 = io_out_writeAddr_ready & io_out_writeAddr_valid; // @[Decoupled.scala 52:35]
  wire  _GEN_84 = _T_18 ? 1'h0 : aw_determined; // @[AXISlaveWriteMux.scala 138:32 139:21 41:30]
  wire  _GEN_85 = ~chosen_reg; // @[AXISlaveWriteMux.scala 141:{39,39} 72:30]
  wire  _T_23 = io_out_writeData_ready & io_out_writeData_valid; // @[Decoupled.scala 52:35]
  wire  _GEN_88 = _T_23 ? 1'h0 : w_determined; // @[AXISlaveWriteMux.scala 149:34 150:22 40:29]
  wire [3:0] _GEN_89 = _T_7 ? io_out_writeResp_bits_id : resp_reg_id; // @[AXISlaveWriteMux.scala 152:34 153:18 53:25]
  wire [1:0] _GEN_90 = _T_7 ? io_out_writeResp_bits_resp : resp_reg_resp; // @[AXISlaveWriteMux.scala 152:34 153:18 53:25]
  wire  _GEN_95 = state == 2'h3 & _GEN_85; // @[AXISlaveWriteMux.scala 157:31 73:30]
  wire  _GEN_96 = state == 2'h3 & chosen_reg; // @[AXISlaveWriteMux.scala 157:31 73:30]
  wire  _GEN_104 = state == 2'h2 ? 1'h0 : _GEN_95; // @[AXISlaveWriteMux.scala 144:33 73:30]
  wire  _GEN_105 = state == 2'h2 ? 1'h0 : _GEN_96; // @[AXISlaveWriteMux.scala 144:33 73:30]
  wire  _GEN_112 = state == 2'h1 & _GEN_85; // @[AXISlaveWriteMux.scala 133:33 72:30]
  wire  _GEN_113 = state == 2'h1 & chosen_reg; // @[AXISlaveWriteMux.scala 133:33 72:30]
  wire  _GEN_114 = state == 2'h1 ? 1'h0 : _T_21; // @[AXISlaveWriteMux.scala 133:33 142:28]
  wire  _GEN_118 = state == 2'h1 ? 1'h0 : _GEN_104; // @[AXISlaveWriteMux.scala 133:33 73:30]
  wire  _GEN_119 = state == 2'h1 ? 1'h0 : _GEN_105; // @[AXISlaveWriteMux.scala 133:33 73:30]
  RRArbiter arbiter ( // @[AXISlaveWriteMux.scala 38:23]
    .clock(arbiter_clock),
    .io_in_0_ready(arbiter_io_in_0_ready),
    .io_in_0_valid(arbiter_io_in_0_valid),
    .io_in_1_ready(arbiter_io_in_1_ready),
    .io_in_1_valid(arbiter_io_in_1_valid),
    .io_out_valid(arbiter_io_out_valid),
    .io_chosen(arbiter_io_chosen)
  );
  assign io_out_writeAddr_valid = aw_determined; // @[AXISlaveWriteMux.scala 85:26]
  assign io_out_writeAddr_bits_id = address_reg_id; // @[AXISlaveWriteMux.scala 163:25]
  assign io_out_writeAddr_bits_addr = address_reg_addr; // @[AXISlaveWriteMux.scala 163:25]
  assign io_out_writeAddr_bits_size = address_reg_size; // @[AXISlaveWriteMux.scala 163:25]
  assign io_out_writeData_valid = w_determined; // @[AXISlaveWriteMux.scala 86:26]
  assign io_out_writeData_bits_data = data_reg_data; // @[AXISlaveWriteMux.scala 162:25]
  assign io_out_writeData_bits_strb = data_reg_strb; // @[AXISlaveWriteMux.scala 162:25]
  assign io_out_writeData_bits_last = data_reg_last; // @[AXISlaveWriteMux.scala 162:25]
  assign io_out_writeResp_ready = state == 2'h0 ? 1'h0 : _GEN_114; // @[AXISlaveWriteMux.scala 117:24 131:28]
  assign io_in_0_writeAddr_ready = arbiter_io_in_0_ready & mask_0; // @[AXISlaveWriteMux.scala 79:56]
  assign io_in_0_writeData_ready = state == 2'h0 ? _GEN_53 : _GEN_112; // @[AXISlaveWriteMux.scala 117:24]
  assign io_in_0_writeResp_valid = state == 2'h0 ? 1'h0 : _GEN_118; // @[AXISlaveWriteMux.scala 117:24 73:30]
  assign io_in_0_writeResp_bits_id = ~chosen_reg ? resp_reg_id : 4'h0; // @[AXISlaveWriteMux.scala 164:{36,36} 74:32]
  assign io_in_0_writeResp_bits_resp = ~chosen_reg ? resp_reg_resp : 2'h0; // @[AXISlaveWriteMux.scala 164:{36,36} 75:34]
  assign io_in_1_writeAddr_ready = arbiter_io_in_1_ready & mask_0; // @[AXISlaveWriteMux.scala 79:56]
  assign io_in_1_writeData_ready = state == 2'h0 ? _GEN_54 : _GEN_113; // @[AXISlaveWriteMux.scala 117:24]
  assign io_in_1_writeResp_valid = state == 2'h0 ? 1'h0 : _GEN_119; // @[AXISlaveWriteMux.scala 117:24 73:30]
  assign io_in_1_writeResp_bits_id = chosen_reg ? resp_reg_id : 4'h0; // @[AXISlaveWriteMux.scala 164:{36,36} 74:32]
  assign io_in_1_writeResp_bits_resp = chosen_reg ? resp_reg_resp : 2'h0; // @[AXISlaveWriteMux.scala 164:{36,36} 75:34]
  assign arbiter_clock = clock;
  assign arbiter_io_in_0_valid = io_in_0_writeAddr_valid & mask_0; // @[AXISlaveWriteMux.scala 80:56]
  assign arbiter_io_in_1_valid = io_in_1_writeAddr_valid & mask_0; // @[AXISlaveWriteMux.scala 80:56]
  always @(posedge clock) begin
    if (reset) begin // @[AXISlaveWriteMux.scala 32:22]
      state <= 2'h0; // @[AXISlaveWriteMux.scala 32:22]
    end else if (2'h0 == state) begin // @[AXISlaveWriteMux.scala 88:16]
      if (outstanding) begin // @[AXISlaveWriteMux.scala 90:24]
        if (_T_1) begin // @[AXISlaveWriteMux.scala 92:61]
          state <= 2'h2; // @[AXISlaveWriteMux.scala 93:17]
        end else begin
          state <= 2'h1; // @[AXISlaveWriteMux.scala 96:17]
        end
      end
    end else if (2'h1 == state) begin // @[AXISlaveWriteMux.scala 88:16]
      if (_T_5) begin // @[AXISlaveWriteMux.scala 101:45]
        state <= 2'h2; // @[AXISlaveWriteMux.scala 102:15]
      end
    end else if (2'h2 == state) begin // @[AXISlaveWriteMux.scala 88:16]
      state <= _GEN_11;
    end else begin
      state <= _GEN_17;
    end
    if (reset) begin // @[AXISlaveWriteMux.scala 39:27]
      chosen_reg <= 1'h0; // @[AXISlaveWriteMux.scala 39:27]
    end else if (state == 2'h0) begin // @[AXISlaveWriteMux.scala 117:24]
      if (arbiter_io_out_valid) begin // @[AXISlaveWriteMux.scala 121:31]
        chosen_reg <= arbiter_io_chosen; // @[AXISlaveWriteMux.scala 123:18]
      end
    end
    if (reset) begin // @[AXISlaveWriteMux.scala 40:29]
      w_determined <= 1'h0; // @[AXISlaveWriteMux.scala 40:29]
    end else if (state == 2'h0) begin // @[AXISlaveWriteMux.scala 117:24]
      if (arbiter_io_out_valid) begin // @[AXISlaveWriteMux.scala 121:31]
        w_determined <= _GEN_52;
      end
    end else if (!(state == 2'h1)) begin // @[AXISlaveWriteMux.scala 133:33]
      if (state == 2'h2) begin // @[AXISlaveWriteMux.scala 144:33]
        w_determined <= _GEN_88;
      end
    end
    if (reset) begin // @[AXISlaveWriteMux.scala 41:30]
      aw_determined <= 1'h0; // @[AXISlaveWriteMux.scala 41:30]
    end else if (state == 2'h0) begin // @[AXISlaveWriteMux.scala 117:24]
      aw_determined <= _GEN_66;
    end else if (state == 2'h1) begin // @[AXISlaveWriteMux.scala 133:33]
      aw_determined <= _GEN_84;
    end else if (state == 2'h2) begin // @[AXISlaveWriteMux.scala 144:33]
      aw_determined <= _GEN_84;
    end
    if (reset) begin // @[AXISlaveWriteMux.scala 43:28]
      address_reg_id <= 4'h0; // @[AXISlaveWriteMux.scala 43:28]
    end else if (state == 2'h0) begin // @[AXISlaveWriteMux.scala 117:24]
      if (arbiter_io_out_valid) begin // @[AXISlaveWriteMux.scala 121:31]
        if (arbiter_io_chosen) begin // @[AXISlaveWriteMux.scala 124:19]
          address_reg_id <= io_in_1_writeAddr_bits_id; // @[AXISlaveWriteMux.scala 124:19]
        end else begin
          address_reg_id <= io_in_0_writeAddr_bits_id;
        end
      end
    end
    if (reset) begin // @[AXISlaveWriteMux.scala 43:28]
      address_reg_addr <= 32'h0; // @[AXISlaveWriteMux.scala 43:28]
    end else if (state == 2'h0) begin // @[AXISlaveWriteMux.scala 117:24]
      if (arbiter_io_out_valid) begin // @[AXISlaveWriteMux.scala 121:31]
        if (arbiter_io_chosen) begin // @[AXISlaveWriteMux.scala 124:19]
          address_reg_addr <= io_in_1_writeAddr_bits_addr; // @[AXISlaveWriteMux.scala 124:19]
        end else begin
          address_reg_addr <= io_in_0_writeAddr_bits_addr;
        end
      end
    end
    if (reset) begin // @[AXISlaveWriteMux.scala 43:28]
      address_reg_size <= 2'h0; // @[AXISlaveWriteMux.scala 43:28]
    end else if (state == 2'h0) begin // @[AXISlaveWriteMux.scala 117:24]
      if (arbiter_io_out_valid) begin // @[AXISlaveWriteMux.scala 121:31]
        if (arbiter_io_chosen) begin // @[AXISlaveWriteMux.scala 124:19]
          address_reg_size <= io_in_1_writeAddr_bits_size; // @[AXISlaveWriteMux.scala 124:19]
        end else begin
          address_reg_size <= io_in_0_writeAddr_bits_size;
        end
      end
    end
    if (reset) begin // @[AXISlaveWriteMux.scala 48:25]
      data_reg_data <= 32'h0; // @[AXISlaveWriteMux.scala 48:25]
    end else if (state == 2'h0) begin // @[AXISlaveWriteMux.scala 117:24]
      if (arbiter_io_out_valid) begin // @[AXISlaveWriteMux.scala 121:31]
        if (_T_1) begin // @[AXISlaveWriteMux.scala 126:59]
          data_reg_data <= _GEN_44; // @[AXISlaveWriteMux.scala 127:18]
        end
      end
    end else if (state == 2'h1) begin // @[AXISlaveWriteMux.scala 133:33]
      if (_T_5) begin // @[AXISlaveWriteMux.scala 135:43]
        data_reg_data <= _GEN_76; // @[AXISlaveWriteMux.scala 136:16]
      end
    end
    if (reset) begin // @[AXISlaveWriteMux.scala 48:25]
      data_reg_strb <= 4'h0; // @[AXISlaveWriteMux.scala 48:25]
    end else if (state == 2'h0) begin // @[AXISlaveWriteMux.scala 117:24]
      if (arbiter_io_out_valid) begin // @[AXISlaveWriteMux.scala 121:31]
        if (_T_1) begin // @[AXISlaveWriteMux.scala 126:59]
          data_reg_strb <= _GEN_46; // @[AXISlaveWriteMux.scala 127:18]
        end
      end
    end else if (state == 2'h1) begin // @[AXISlaveWriteMux.scala 133:33]
      if (_T_5) begin // @[AXISlaveWriteMux.scala 135:43]
        data_reg_strb <= _GEN_78; // @[AXISlaveWriteMux.scala 136:16]
      end
    end
    if (reset) begin // @[AXISlaveWriteMux.scala 48:25]
      data_reg_last <= 1'h0; // @[AXISlaveWriteMux.scala 48:25]
    end else if (state == 2'h0) begin // @[AXISlaveWriteMux.scala 117:24]
      if (arbiter_io_out_valid) begin // @[AXISlaveWriteMux.scala 121:31]
        if (_T_1) begin // @[AXISlaveWriteMux.scala 126:59]
          data_reg_last <= _GEN_48; // @[AXISlaveWriteMux.scala 127:18]
        end
      end
    end else if (state == 2'h1) begin // @[AXISlaveWriteMux.scala 133:33]
      if (_T_5) begin // @[AXISlaveWriteMux.scala 135:43]
        data_reg_last <= _GEN_80; // @[AXISlaveWriteMux.scala 136:16]
      end
    end
    if (reset) begin // @[AXISlaveWriteMux.scala 53:25]
      resp_reg_id <= 4'h0; // @[AXISlaveWriteMux.scala 53:25]
    end else if (!(state == 2'h0)) begin // @[AXISlaveWriteMux.scala 117:24]
      if (!(state == 2'h1)) begin // @[AXISlaveWriteMux.scala 133:33]
        if (state == 2'h2) begin // @[AXISlaveWriteMux.scala 144:33]
          resp_reg_id <= _GEN_89;
        end
      end
    end
    if (reset) begin // @[AXISlaveWriteMux.scala 53:25]
      resp_reg_resp <= 2'h0; // @[AXISlaveWriteMux.scala 53:25]
    end else if (!(state == 2'h0)) begin // @[AXISlaveWriteMux.scala 117:24]
      if (!(state == 2'h1)) begin // @[AXISlaveWriteMux.scala 133:33]
        if (state == 2'h2) begin // @[AXISlaveWriteMux.scala 144:33]
          resp_reg_resp <= _GEN_90;
        end
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  state = _RAND_0[1:0];
  _RAND_1 = {1{`RANDOM}};
  chosen_reg = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  w_determined = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  aw_determined = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  address_reg_id = _RAND_4[3:0];
  _RAND_5 = {1{`RANDOM}};
  address_reg_addr = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  address_reg_size = _RAND_6[1:0];
  _RAND_7 = {1{`RANDOM}};
  data_reg_data = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  data_reg_strb = _RAND_8[3:0];
  _RAND_9 = {1{`RANDOM}};
  data_reg_last = _RAND_9[0:0];
  _RAND_10 = {1{`RANDOM}};
  resp_reg_id = _RAND_10[3:0];
  _RAND_11 = {1{`RANDOM}};
  resp_reg_resp = _RAND_11[1:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module AXILiteXBar(
  input         clock,
  input         reset,
  output        io_masters_0_aw_ready,
  input         io_masters_0_aw_valid,
  input  [31:0] io_masters_0_aw_bits_addr,
  output        io_masters_0_w_ready,
  input         io_masters_0_w_valid,
  input  [31:0] io_masters_0_w_bits_data,
  input  [3:0]  io_masters_0_w_bits_strb,
  input         io_masters_0_b_ready,
  output        io_masters_0_b_valid,
  output        io_masters_0_ar_ready,
  input         io_masters_0_ar_valid,
  input  [31:0] io_masters_0_ar_bits_addr,
  input         io_masters_0_r_ready,
  output        io_masters_0_r_valid,
  output [31:0] io_masters_0_r_bits_data,
  output        io_masters_1_aw_ready,
  input         io_masters_1_aw_valid,
  input  [3:0]  io_masters_1_aw_bits_id,
  input  [31:0] io_masters_1_aw_bits_addr,
  input  [1:0]  io_masters_1_aw_bits_size,
  output        io_masters_1_w_ready,
  input         io_masters_1_w_valid,
  input  [31:0] io_masters_1_w_bits_data,
  input  [3:0]  io_masters_1_w_bits_strb,
  input         io_masters_1_w_bits_last,
  input         io_masters_1_b_ready,
  output        io_masters_1_b_valid,
  output [3:0]  io_masters_1_b_bits_id,
  output [1:0]  io_masters_1_b_bits_resp,
  output        io_masters_1_ar_ready,
  input         io_masters_1_ar_valid,
  input  [3:0]  io_masters_1_ar_bits_id,
  input  [31:0] io_masters_1_ar_bits_addr,
  input  [1:0]  io_masters_1_ar_bits_size,
  input         io_masters_1_r_ready,
  output        io_masters_1_r_valid,
  output [3:0]  io_masters_1_r_bits_id,
  output [31:0] io_masters_1_r_bits_data,
  output [1:0]  io_masters_1_r_bits_resp,
  output        io_masters_1_r_bits_last,
  input         io_slaves_0_aw_ready,
  output        io_slaves_0_aw_valid,
  output [3:0]  io_slaves_0_aw_bits_id,
  output [31:0] io_slaves_0_aw_bits_addr,
  output [1:0]  io_slaves_0_aw_bits_size,
  input         io_slaves_0_w_ready,
  output        io_slaves_0_w_valid,
  output [31:0] io_slaves_0_w_bits_data,
  output [3:0]  io_slaves_0_w_bits_strb,
  output        io_slaves_0_w_bits_last,
  output        io_slaves_0_b_ready,
  input         io_slaves_0_b_valid,
  input  [3:0]  io_slaves_0_b_bits_id,
  input  [1:0]  io_slaves_0_b_bits_resp,
  input         io_slaves_0_ar_ready,
  output        io_slaves_0_ar_valid,
  output [3:0]  io_slaves_0_ar_bits_id,
  output [31:0] io_slaves_0_ar_bits_addr,
  output [1:0]  io_slaves_0_ar_bits_size,
  output        io_slaves_0_r_ready,
  input         io_slaves_0_r_valid,
  input  [3:0]  io_slaves_0_r_bits_id,
  input  [31:0] io_slaves_0_r_bits_data,
  input  [1:0]  io_slaves_0_r_bits_resp,
  input         io_slaves_0_r_bits_last,
  input         io_slaves_1_aw_ready,
  output        io_slaves_1_aw_valid,
  output [3:0]  io_slaves_1_aw_bits_id,
  output [31:0] io_slaves_1_aw_bits_addr,
  input         io_slaves_1_w_ready,
  output        io_slaves_1_w_valid,
  output [31:0] io_slaves_1_w_bits_data,
  output [3:0]  io_slaves_1_w_bits_strb,
  output        io_slaves_1_w_bits_last,
  output        io_slaves_1_b_ready,
  input         io_slaves_1_b_valid,
  input  [3:0]  io_slaves_1_b_bits_id,
  input         io_slaves_1_ar_ready,
  output        io_slaves_1_ar_valid,
  output [3:0]  io_slaves_1_ar_bits_id,
  output [31:0] io_slaves_1_ar_bits_addr,
  output        io_slaves_1_r_ready,
  input         io_slaves_1_r_valid,
  input  [3:0]  io_slaves_1_r_bits_id,
  input  [31:0] io_slaves_1_r_bits_data,
  input         io_slaves_1_r_bits_last,
  input         io_slaves_2_aw_ready,
  output        io_slaves_2_aw_valid,
  output [3:0]  io_slaves_2_aw_bits_id,
  output [31:0] io_slaves_2_aw_bits_addr,
  input         io_slaves_2_w_ready,
  output        io_slaves_2_w_valid,
  output [31:0] io_slaves_2_w_bits_data,
  output [3:0]  io_slaves_2_w_bits_strb,
  output        io_slaves_2_w_bits_last,
  output        io_slaves_2_b_ready,
  input         io_slaves_2_b_valid,
  input  [3:0]  io_slaves_2_b_bits_id,
  input         io_slaves_2_ar_ready,
  output        io_slaves_2_ar_valid,
  output [3:0]  io_slaves_2_ar_bits_id,
  output [31:0] io_slaves_2_ar_bits_addr,
  output        io_slaves_2_r_ready,
  input         io_slaves_2_r_valid,
  input  [3:0]  io_slaves_2_r_bits_id,
  input  [31:0] io_slaves_2_r_bits_data,
  input         io_slaves_2_r_bits_last
);
  wire  readBuses_0_clock; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_reset; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_master_readAddr_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_master_readAddr_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_0_io_master_readAddr_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_0_io_master_readAddr_bits_addr; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_0_io_master_readAddr_bits_size; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_master_readData_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_master_readData_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_0_io_master_readData_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_0_io_master_readData_bits_data; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_0_io_master_readData_bits_resp; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_master_readData_bits_last; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_0_readAddr_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_0_readAddr_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_0_io_slave_0_readAddr_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_0_io_slave_0_readAddr_bits_addr; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_0_io_slave_0_readAddr_bits_size; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_0_readData_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_0_readData_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_0_io_slave_0_readData_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_0_io_slave_0_readData_bits_data; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_0_io_slave_0_readData_bits_resp; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_0_readData_bits_last; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_1_readAddr_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_1_readAddr_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_0_io_slave_1_readAddr_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_0_io_slave_1_readAddr_bits_addr; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_0_io_slave_1_readAddr_bits_size; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_1_readData_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_1_readData_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_0_io_slave_1_readData_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_0_io_slave_1_readData_bits_data; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_0_io_slave_1_readData_bits_resp; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_1_readData_bits_last; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_2_readAddr_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_2_readAddr_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_0_io_slave_2_readAddr_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_0_io_slave_2_readAddr_bits_addr; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_0_io_slave_2_readAddr_bits_size; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_2_readData_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_2_readData_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_0_io_slave_2_readData_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_0_io_slave_2_readData_bits_data; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_0_io_slave_2_readData_bits_resp; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_0_io_slave_2_readData_bits_last; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_clock; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_reset; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_master_readAddr_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_master_readAddr_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_1_io_master_readAddr_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_1_io_master_readAddr_bits_addr; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_1_io_master_readAddr_bits_size; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_master_readData_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_master_readData_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_1_io_master_readData_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_1_io_master_readData_bits_data; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_1_io_master_readData_bits_resp; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_master_readData_bits_last; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_0_readAddr_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_0_readAddr_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_1_io_slave_0_readAddr_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_1_io_slave_0_readAddr_bits_addr; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_1_io_slave_0_readAddr_bits_size; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_0_readData_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_0_readData_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_1_io_slave_0_readData_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_1_io_slave_0_readData_bits_data; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_1_io_slave_0_readData_bits_resp; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_0_readData_bits_last; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_1_readAddr_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_1_readAddr_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_1_io_slave_1_readAddr_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_1_io_slave_1_readAddr_bits_addr; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_1_io_slave_1_readAddr_bits_size; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_1_readData_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_1_readData_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_1_io_slave_1_readData_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_1_io_slave_1_readData_bits_data; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_1_io_slave_1_readData_bits_resp; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_1_readData_bits_last; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_2_readAddr_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_2_readAddr_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_1_io_slave_2_readAddr_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_1_io_slave_2_readAddr_bits_addr; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_1_io_slave_2_readAddr_bits_size; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_2_readData_ready; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_2_readData_valid; // @[AXILiteXBar.scala 15:11]
  wire [3:0] readBuses_1_io_slave_2_readData_bits_id; // @[AXILiteXBar.scala 15:11]
  wire [31:0] readBuses_1_io_slave_2_readData_bits_data; // @[AXILiteXBar.scala 15:11]
  wire [1:0] readBuses_1_io_slave_2_readData_bits_resp; // @[AXILiteXBar.scala 15:11]
  wire  readBuses_1_io_slave_2_readData_bits_last; // @[AXILiteXBar.scala 15:11]
  wire  readMuxes_0_clock; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_reset; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_out_readAddr_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_out_readAddr_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_0_io_out_readAddr_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_0_io_out_readAddr_bits_addr; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_0_io_out_readAddr_bits_size; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_out_readData_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_out_readData_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_0_io_out_readData_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_0_io_out_readData_bits_data; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_0_io_out_readData_bits_resp; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_out_readData_bits_last; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_in_0_readAddr_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_in_0_readAddr_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_0_io_in_0_readAddr_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_0_io_in_0_readAddr_bits_addr; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_0_io_in_0_readAddr_bits_size; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_in_0_readData_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_in_0_readData_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_0_io_in_0_readData_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_0_io_in_0_readData_bits_data; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_0_io_in_0_readData_bits_resp; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_in_0_readData_bits_last; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_in_1_readAddr_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_in_1_readAddr_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_0_io_in_1_readAddr_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_0_io_in_1_readAddr_bits_addr; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_0_io_in_1_readAddr_bits_size; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_in_1_readData_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_in_1_readData_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_0_io_in_1_readData_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_0_io_in_1_readData_bits_data; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_0_io_in_1_readData_bits_resp; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_0_io_in_1_readData_bits_last; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_clock; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_reset; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_out_readAddr_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_out_readAddr_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_1_io_out_readAddr_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_1_io_out_readAddr_bits_addr; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_1_io_out_readAddr_bits_size; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_out_readData_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_out_readData_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_1_io_out_readData_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_1_io_out_readData_bits_data; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_1_io_out_readData_bits_resp; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_out_readData_bits_last; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_in_0_readAddr_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_in_0_readAddr_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_1_io_in_0_readAddr_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_1_io_in_0_readAddr_bits_addr; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_1_io_in_0_readAddr_bits_size; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_in_0_readData_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_in_0_readData_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_1_io_in_0_readData_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_1_io_in_0_readData_bits_data; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_1_io_in_0_readData_bits_resp; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_in_0_readData_bits_last; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_in_1_readAddr_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_in_1_readAddr_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_1_io_in_1_readAddr_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_1_io_in_1_readAddr_bits_addr; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_1_io_in_1_readAddr_bits_size; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_in_1_readData_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_in_1_readData_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_1_io_in_1_readData_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_1_io_in_1_readData_bits_data; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_1_io_in_1_readData_bits_resp; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_1_io_in_1_readData_bits_last; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_clock; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_reset; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_out_readAddr_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_out_readAddr_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_2_io_out_readAddr_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_2_io_out_readAddr_bits_addr; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_2_io_out_readAddr_bits_size; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_out_readData_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_out_readData_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_2_io_out_readData_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_2_io_out_readData_bits_data; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_2_io_out_readData_bits_resp; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_out_readData_bits_last; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_in_0_readAddr_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_in_0_readAddr_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_2_io_in_0_readAddr_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_2_io_in_0_readAddr_bits_addr; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_2_io_in_0_readAddr_bits_size; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_in_0_readData_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_in_0_readData_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_2_io_in_0_readData_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_2_io_in_0_readData_bits_data; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_2_io_in_0_readData_bits_resp; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_in_0_readData_bits_last; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_in_1_readAddr_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_in_1_readAddr_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_2_io_in_1_readAddr_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_2_io_in_1_readAddr_bits_addr; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_2_io_in_1_readAddr_bits_size; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_in_1_readData_ready; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_in_1_readData_valid; // @[AXILiteXBar.scala 18:11]
  wire [3:0] readMuxes_2_io_in_1_readData_bits_id; // @[AXILiteXBar.scala 18:11]
  wire [31:0] readMuxes_2_io_in_1_readData_bits_data; // @[AXILiteXBar.scala 18:11]
  wire [1:0] readMuxes_2_io_in_1_readData_bits_resp; // @[AXILiteXBar.scala 18:11]
  wire  readMuxes_2_io_in_1_readData_bits_last; // @[AXILiteXBar.scala 18:11]
  wire  writeBuses_0_clock; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_reset; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_master_writeAddr_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_master_writeAddr_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_0_io_master_writeAddr_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_0_io_master_writeAddr_bits_addr; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_0_io_master_writeAddr_bits_size; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_master_writeData_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_master_writeData_valid; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_0_io_master_writeData_bits_data; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_0_io_master_writeData_bits_strb; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_master_writeData_bits_last; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_master_writeResp_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_master_writeResp_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_0_io_master_writeResp_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_0_io_master_writeResp_bits_resp; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_0_writeAddr_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_0_writeAddr_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_0_io_slave_0_writeAddr_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_0_io_slave_0_writeAddr_bits_addr; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_0_io_slave_0_writeAddr_bits_size; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_0_writeData_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_0_writeData_valid; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_0_io_slave_0_writeData_bits_data; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_0_io_slave_0_writeData_bits_strb; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_0_writeData_bits_last; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_0_writeResp_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_0_writeResp_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_0_io_slave_0_writeResp_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_0_io_slave_0_writeResp_bits_resp; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_1_writeAddr_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_1_writeAddr_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_0_io_slave_1_writeAddr_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_0_io_slave_1_writeAddr_bits_addr; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_0_io_slave_1_writeAddr_bits_size; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_1_writeData_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_1_writeData_valid; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_0_io_slave_1_writeData_bits_data; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_0_io_slave_1_writeData_bits_strb; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_1_writeData_bits_last; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_1_writeResp_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_1_writeResp_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_0_io_slave_1_writeResp_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_0_io_slave_1_writeResp_bits_resp; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_2_writeAddr_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_2_writeAddr_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_0_io_slave_2_writeAddr_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_0_io_slave_2_writeAddr_bits_addr; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_0_io_slave_2_writeAddr_bits_size; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_2_writeData_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_2_writeData_valid; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_0_io_slave_2_writeData_bits_data; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_0_io_slave_2_writeData_bits_strb; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_2_writeData_bits_last; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_2_writeResp_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_0_io_slave_2_writeResp_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_0_io_slave_2_writeResp_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_0_io_slave_2_writeResp_bits_resp; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_clock; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_reset; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_master_writeAddr_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_master_writeAddr_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_1_io_master_writeAddr_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_1_io_master_writeAddr_bits_addr; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_1_io_master_writeAddr_bits_size; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_master_writeData_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_master_writeData_valid; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_1_io_master_writeData_bits_data; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_1_io_master_writeData_bits_strb; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_master_writeData_bits_last; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_master_writeResp_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_master_writeResp_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_1_io_master_writeResp_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_1_io_master_writeResp_bits_resp; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_0_writeAddr_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_0_writeAddr_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_1_io_slave_0_writeAddr_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_1_io_slave_0_writeAddr_bits_addr; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_1_io_slave_0_writeAddr_bits_size; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_0_writeData_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_0_writeData_valid; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_1_io_slave_0_writeData_bits_data; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_1_io_slave_0_writeData_bits_strb; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_0_writeData_bits_last; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_0_writeResp_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_0_writeResp_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_1_io_slave_0_writeResp_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_1_io_slave_0_writeResp_bits_resp; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_1_writeAddr_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_1_writeAddr_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_1_io_slave_1_writeAddr_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_1_io_slave_1_writeAddr_bits_addr; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_1_io_slave_1_writeAddr_bits_size; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_1_writeData_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_1_writeData_valid; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_1_io_slave_1_writeData_bits_data; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_1_io_slave_1_writeData_bits_strb; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_1_writeData_bits_last; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_1_writeResp_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_1_writeResp_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_1_io_slave_1_writeResp_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_1_io_slave_1_writeResp_bits_resp; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_2_writeAddr_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_2_writeAddr_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_1_io_slave_2_writeAddr_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_1_io_slave_2_writeAddr_bits_addr; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_1_io_slave_2_writeAddr_bits_size; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_2_writeData_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_2_writeData_valid; // @[AXILiteXBar.scala 23:11]
  wire [31:0] writeBuses_1_io_slave_2_writeData_bits_data; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_1_io_slave_2_writeData_bits_strb; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_2_writeData_bits_last; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_2_writeResp_ready; // @[AXILiteXBar.scala 23:11]
  wire  writeBuses_1_io_slave_2_writeResp_valid; // @[AXILiteXBar.scala 23:11]
  wire [3:0] writeBuses_1_io_slave_2_writeResp_bits_id; // @[AXILiteXBar.scala 23:11]
  wire [1:0] writeBuses_1_io_slave_2_writeResp_bits_resp; // @[AXILiteXBar.scala 23:11]
  wire  writeMuxes_0_clock; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_reset; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_out_writeAddr_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_out_writeAddr_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_0_io_out_writeAddr_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_0_io_out_writeAddr_bits_addr; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_0_io_out_writeAddr_bits_size; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_out_writeData_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_out_writeData_valid; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_0_io_out_writeData_bits_data; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_0_io_out_writeData_bits_strb; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_out_writeData_bits_last; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_out_writeResp_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_out_writeResp_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_0_io_out_writeResp_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_0_io_out_writeResp_bits_resp; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_0_writeAddr_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_0_writeAddr_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_0_io_in_0_writeAddr_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_0_io_in_0_writeAddr_bits_addr; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_0_io_in_0_writeAddr_bits_size; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_0_writeData_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_0_writeData_valid; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_0_io_in_0_writeData_bits_data; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_0_io_in_0_writeData_bits_strb; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_0_writeData_bits_last; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_0_writeResp_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_0_writeResp_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_0_io_in_0_writeResp_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_0_io_in_0_writeResp_bits_resp; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_1_writeAddr_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_1_writeAddr_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_0_io_in_1_writeAddr_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_0_io_in_1_writeAddr_bits_addr; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_0_io_in_1_writeAddr_bits_size; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_1_writeData_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_1_writeData_valid; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_0_io_in_1_writeData_bits_data; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_0_io_in_1_writeData_bits_strb; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_1_writeData_bits_last; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_1_writeResp_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_0_io_in_1_writeResp_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_0_io_in_1_writeResp_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_0_io_in_1_writeResp_bits_resp; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_clock; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_reset; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_out_writeAddr_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_out_writeAddr_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_1_io_out_writeAddr_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_1_io_out_writeAddr_bits_addr; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_1_io_out_writeAddr_bits_size; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_out_writeData_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_out_writeData_valid; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_1_io_out_writeData_bits_data; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_1_io_out_writeData_bits_strb; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_out_writeData_bits_last; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_out_writeResp_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_out_writeResp_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_1_io_out_writeResp_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_1_io_out_writeResp_bits_resp; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_0_writeAddr_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_0_writeAddr_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_1_io_in_0_writeAddr_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_1_io_in_0_writeAddr_bits_addr; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_1_io_in_0_writeAddr_bits_size; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_0_writeData_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_0_writeData_valid; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_1_io_in_0_writeData_bits_data; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_1_io_in_0_writeData_bits_strb; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_0_writeData_bits_last; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_0_writeResp_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_0_writeResp_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_1_io_in_0_writeResp_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_1_io_in_0_writeResp_bits_resp; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_1_writeAddr_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_1_writeAddr_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_1_io_in_1_writeAddr_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_1_io_in_1_writeAddr_bits_addr; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_1_io_in_1_writeAddr_bits_size; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_1_writeData_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_1_writeData_valid; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_1_io_in_1_writeData_bits_data; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_1_io_in_1_writeData_bits_strb; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_1_writeData_bits_last; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_1_writeResp_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_1_io_in_1_writeResp_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_1_io_in_1_writeResp_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_1_io_in_1_writeResp_bits_resp; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_clock; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_reset; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_out_writeAddr_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_out_writeAddr_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_2_io_out_writeAddr_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_2_io_out_writeAddr_bits_addr; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_2_io_out_writeAddr_bits_size; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_out_writeData_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_out_writeData_valid; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_2_io_out_writeData_bits_data; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_2_io_out_writeData_bits_strb; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_out_writeData_bits_last; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_out_writeResp_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_out_writeResp_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_2_io_out_writeResp_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_2_io_out_writeResp_bits_resp; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_0_writeAddr_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_0_writeAddr_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_2_io_in_0_writeAddr_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_2_io_in_0_writeAddr_bits_addr; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_2_io_in_0_writeAddr_bits_size; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_0_writeData_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_0_writeData_valid; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_2_io_in_0_writeData_bits_data; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_2_io_in_0_writeData_bits_strb; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_0_writeData_bits_last; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_0_writeResp_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_0_writeResp_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_2_io_in_0_writeResp_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_2_io_in_0_writeResp_bits_resp; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_1_writeAddr_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_1_writeAddr_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_2_io_in_1_writeAddr_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_2_io_in_1_writeAddr_bits_addr; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_2_io_in_1_writeAddr_bits_size; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_1_writeData_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_1_writeData_valid; // @[AXILiteXBar.scala 27:11]
  wire [31:0] writeMuxes_2_io_in_1_writeData_bits_data; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_2_io_in_1_writeData_bits_strb; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_1_writeData_bits_last; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_1_writeResp_ready; // @[AXILiteXBar.scala 27:11]
  wire  writeMuxes_2_io_in_1_writeResp_valid; // @[AXILiteXBar.scala 27:11]
  wire [3:0] writeMuxes_2_io_in_1_writeResp_bits_id; // @[AXILiteXBar.scala 27:11]
  wire [1:0] writeMuxes_2_io_in_1_writeResp_bits_resp; // @[AXILiteXBar.scala 27:11]
  AXIReadBus readBuses_0 ( // @[AXILiteXBar.scala 15:11]
    .clock(readBuses_0_clock),
    .reset(readBuses_0_reset),
    .io_master_readAddr_ready(readBuses_0_io_master_readAddr_ready),
    .io_master_readAddr_valid(readBuses_0_io_master_readAddr_valid),
    .io_master_readAddr_bits_id(readBuses_0_io_master_readAddr_bits_id),
    .io_master_readAddr_bits_addr(readBuses_0_io_master_readAddr_bits_addr),
    .io_master_readAddr_bits_size(readBuses_0_io_master_readAddr_bits_size),
    .io_master_readData_ready(readBuses_0_io_master_readData_ready),
    .io_master_readData_valid(readBuses_0_io_master_readData_valid),
    .io_master_readData_bits_id(readBuses_0_io_master_readData_bits_id),
    .io_master_readData_bits_data(readBuses_0_io_master_readData_bits_data),
    .io_master_readData_bits_resp(readBuses_0_io_master_readData_bits_resp),
    .io_master_readData_bits_last(readBuses_0_io_master_readData_bits_last),
    .io_slave_0_readAddr_ready(readBuses_0_io_slave_0_readAddr_ready),
    .io_slave_0_readAddr_valid(readBuses_0_io_slave_0_readAddr_valid),
    .io_slave_0_readAddr_bits_id(readBuses_0_io_slave_0_readAddr_bits_id),
    .io_slave_0_readAddr_bits_addr(readBuses_0_io_slave_0_readAddr_bits_addr),
    .io_slave_0_readAddr_bits_size(readBuses_0_io_slave_0_readAddr_bits_size),
    .io_slave_0_readData_ready(readBuses_0_io_slave_0_readData_ready),
    .io_slave_0_readData_valid(readBuses_0_io_slave_0_readData_valid),
    .io_slave_0_readData_bits_id(readBuses_0_io_slave_0_readData_bits_id),
    .io_slave_0_readData_bits_data(readBuses_0_io_slave_0_readData_bits_data),
    .io_slave_0_readData_bits_resp(readBuses_0_io_slave_0_readData_bits_resp),
    .io_slave_0_readData_bits_last(readBuses_0_io_slave_0_readData_bits_last),
    .io_slave_1_readAddr_ready(readBuses_0_io_slave_1_readAddr_ready),
    .io_slave_1_readAddr_valid(readBuses_0_io_slave_1_readAddr_valid),
    .io_slave_1_readAddr_bits_id(readBuses_0_io_slave_1_readAddr_bits_id),
    .io_slave_1_readAddr_bits_addr(readBuses_0_io_slave_1_readAddr_bits_addr),
    .io_slave_1_readAddr_bits_size(readBuses_0_io_slave_1_readAddr_bits_size),
    .io_slave_1_readData_ready(readBuses_0_io_slave_1_readData_ready),
    .io_slave_1_readData_valid(readBuses_0_io_slave_1_readData_valid),
    .io_slave_1_readData_bits_id(readBuses_0_io_slave_1_readData_bits_id),
    .io_slave_1_readData_bits_data(readBuses_0_io_slave_1_readData_bits_data),
    .io_slave_1_readData_bits_resp(readBuses_0_io_slave_1_readData_bits_resp),
    .io_slave_1_readData_bits_last(readBuses_0_io_slave_1_readData_bits_last),
    .io_slave_2_readAddr_ready(readBuses_0_io_slave_2_readAddr_ready),
    .io_slave_2_readAddr_valid(readBuses_0_io_slave_2_readAddr_valid),
    .io_slave_2_readAddr_bits_id(readBuses_0_io_slave_2_readAddr_bits_id),
    .io_slave_2_readAddr_bits_addr(readBuses_0_io_slave_2_readAddr_bits_addr),
    .io_slave_2_readAddr_bits_size(readBuses_0_io_slave_2_readAddr_bits_size),
    .io_slave_2_readData_ready(readBuses_0_io_slave_2_readData_ready),
    .io_slave_2_readData_valid(readBuses_0_io_slave_2_readData_valid),
    .io_slave_2_readData_bits_id(readBuses_0_io_slave_2_readData_bits_id),
    .io_slave_2_readData_bits_data(readBuses_0_io_slave_2_readData_bits_data),
    .io_slave_2_readData_bits_resp(readBuses_0_io_slave_2_readData_bits_resp),
    .io_slave_2_readData_bits_last(readBuses_0_io_slave_2_readData_bits_last)
  );
  AXIReadBus readBuses_1 ( // @[AXILiteXBar.scala 15:11]
    .clock(readBuses_1_clock),
    .reset(readBuses_1_reset),
    .io_master_readAddr_ready(readBuses_1_io_master_readAddr_ready),
    .io_master_readAddr_valid(readBuses_1_io_master_readAddr_valid),
    .io_master_readAddr_bits_id(readBuses_1_io_master_readAddr_bits_id),
    .io_master_readAddr_bits_addr(readBuses_1_io_master_readAddr_bits_addr),
    .io_master_readAddr_bits_size(readBuses_1_io_master_readAddr_bits_size),
    .io_master_readData_ready(readBuses_1_io_master_readData_ready),
    .io_master_readData_valid(readBuses_1_io_master_readData_valid),
    .io_master_readData_bits_id(readBuses_1_io_master_readData_bits_id),
    .io_master_readData_bits_data(readBuses_1_io_master_readData_bits_data),
    .io_master_readData_bits_resp(readBuses_1_io_master_readData_bits_resp),
    .io_master_readData_bits_last(readBuses_1_io_master_readData_bits_last),
    .io_slave_0_readAddr_ready(readBuses_1_io_slave_0_readAddr_ready),
    .io_slave_0_readAddr_valid(readBuses_1_io_slave_0_readAddr_valid),
    .io_slave_0_readAddr_bits_id(readBuses_1_io_slave_0_readAddr_bits_id),
    .io_slave_0_readAddr_bits_addr(readBuses_1_io_slave_0_readAddr_bits_addr),
    .io_slave_0_readAddr_bits_size(readBuses_1_io_slave_0_readAddr_bits_size),
    .io_slave_0_readData_ready(readBuses_1_io_slave_0_readData_ready),
    .io_slave_0_readData_valid(readBuses_1_io_slave_0_readData_valid),
    .io_slave_0_readData_bits_id(readBuses_1_io_slave_0_readData_bits_id),
    .io_slave_0_readData_bits_data(readBuses_1_io_slave_0_readData_bits_data),
    .io_slave_0_readData_bits_resp(readBuses_1_io_slave_0_readData_bits_resp),
    .io_slave_0_readData_bits_last(readBuses_1_io_slave_0_readData_bits_last),
    .io_slave_1_readAddr_ready(readBuses_1_io_slave_1_readAddr_ready),
    .io_slave_1_readAddr_valid(readBuses_1_io_slave_1_readAddr_valid),
    .io_slave_1_readAddr_bits_id(readBuses_1_io_slave_1_readAddr_bits_id),
    .io_slave_1_readAddr_bits_addr(readBuses_1_io_slave_1_readAddr_bits_addr),
    .io_slave_1_readAddr_bits_size(readBuses_1_io_slave_1_readAddr_bits_size),
    .io_slave_1_readData_ready(readBuses_1_io_slave_1_readData_ready),
    .io_slave_1_readData_valid(readBuses_1_io_slave_1_readData_valid),
    .io_slave_1_readData_bits_id(readBuses_1_io_slave_1_readData_bits_id),
    .io_slave_1_readData_bits_data(readBuses_1_io_slave_1_readData_bits_data),
    .io_slave_1_readData_bits_resp(readBuses_1_io_slave_1_readData_bits_resp),
    .io_slave_1_readData_bits_last(readBuses_1_io_slave_1_readData_bits_last),
    .io_slave_2_readAddr_ready(readBuses_1_io_slave_2_readAddr_ready),
    .io_slave_2_readAddr_valid(readBuses_1_io_slave_2_readAddr_valid),
    .io_slave_2_readAddr_bits_id(readBuses_1_io_slave_2_readAddr_bits_id),
    .io_slave_2_readAddr_bits_addr(readBuses_1_io_slave_2_readAddr_bits_addr),
    .io_slave_2_readAddr_bits_size(readBuses_1_io_slave_2_readAddr_bits_size),
    .io_slave_2_readData_ready(readBuses_1_io_slave_2_readData_ready),
    .io_slave_2_readData_valid(readBuses_1_io_slave_2_readData_valid),
    .io_slave_2_readData_bits_id(readBuses_1_io_slave_2_readData_bits_id),
    .io_slave_2_readData_bits_data(readBuses_1_io_slave_2_readData_bits_data),
    .io_slave_2_readData_bits_resp(readBuses_1_io_slave_2_readData_bits_resp),
    .io_slave_2_readData_bits_last(readBuses_1_io_slave_2_readData_bits_last)
  );
  AXISlaveReadMux readMuxes_0 ( // @[AXILiteXBar.scala 18:11]
    .clock(readMuxes_0_clock),
    .reset(readMuxes_0_reset),
    .io_out_readAddr_ready(readMuxes_0_io_out_readAddr_ready),
    .io_out_readAddr_valid(readMuxes_0_io_out_readAddr_valid),
    .io_out_readAddr_bits_id(readMuxes_0_io_out_readAddr_bits_id),
    .io_out_readAddr_bits_addr(readMuxes_0_io_out_readAddr_bits_addr),
    .io_out_readAddr_bits_size(readMuxes_0_io_out_readAddr_bits_size),
    .io_out_readData_ready(readMuxes_0_io_out_readData_ready),
    .io_out_readData_valid(readMuxes_0_io_out_readData_valid),
    .io_out_readData_bits_id(readMuxes_0_io_out_readData_bits_id),
    .io_out_readData_bits_data(readMuxes_0_io_out_readData_bits_data),
    .io_out_readData_bits_resp(readMuxes_0_io_out_readData_bits_resp),
    .io_out_readData_bits_last(readMuxes_0_io_out_readData_bits_last),
    .io_in_0_readAddr_ready(readMuxes_0_io_in_0_readAddr_ready),
    .io_in_0_readAddr_valid(readMuxes_0_io_in_0_readAddr_valid),
    .io_in_0_readAddr_bits_id(readMuxes_0_io_in_0_readAddr_bits_id),
    .io_in_0_readAddr_bits_addr(readMuxes_0_io_in_0_readAddr_bits_addr),
    .io_in_0_readAddr_bits_size(readMuxes_0_io_in_0_readAddr_bits_size),
    .io_in_0_readData_ready(readMuxes_0_io_in_0_readData_ready),
    .io_in_0_readData_valid(readMuxes_0_io_in_0_readData_valid),
    .io_in_0_readData_bits_id(readMuxes_0_io_in_0_readData_bits_id),
    .io_in_0_readData_bits_data(readMuxes_0_io_in_0_readData_bits_data),
    .io_in_0_readData_bits_resp(readMuxes_0_io_in_0_readData_bits_resp),
    .io_in_0_readData_bits_last(readMuxes_0_io_in_0_readData_bits_last),
    .io_in_1_readAddr_ready(readMuxes_0_io_in_1_readAddr_ready),
    .io_in_1_readAddr_valid(readMuxes_0_io_in_1_readAddr_valid),
    .io_in_1_readAddr_bits_id(readMuxes_0_io_in_1_readAddr_bits_id),
    .io_in_1_readAddr_bits_addr(readMuxes_0_io_in_1_readAddr_bits_addr),
    .io_in_1_readAddr_bits_size(readMuxes_0_io_in_1_readAddr_bits_size),
    .io_in_1_readData_ready(readMuxes_0_io_in_1_readData_ready),
    .io_in_1_readData_valid(readMuxes_0_io_in_1_readData_valid),
    .io_in_1_readData_bits_id(readMuxes_0_io_in_1_readData_bits_id),
    .io_in_1_readData_bits_data(readMuxes_0_io_in_1_readData_bits_data),
    .io_in_1_readData_bits_resp(readMuxes_0_io_in_1_readData_bits_resp),
    .io_in_1_readData_bits_last(readMuxes_0_io_in_1_readData_bits_last)
  );
  AXISlaveReadMux readMuxes_1 ( // @[AXILiteXBar.scala 18:11]
    .clock(readMuxes_1_clock),
    .reset(readMuxes_1_reset),
    .io_out_readAddr_ready(readMuxes_1_io_out_readAddr_ready),
    .io_out_readAddr_valid(readMuxes_1_io_out_readAddr_valid),
    .io_out_readAddr_bits_id(readMuxes_1_io_out_readAddr_bits_id),
    .io_out_readAddr_bits_addr(readMuxes_1_io_out_readAddr_bits_addr),
    .io_out_readAddr_bits_size(readMuxes_1_io_out_readAddr_bits_size),
    .io_out_readData_ready(readMuxes_1_io_out_readData_ready),
    .io_out_readData_valid(readMuxes_1_io_out_readData_valid),
    .io_out_readData_bits_id(readMuxes_1_io_out_readData_bits_id),
    .io_out_readData_bits_data(readMuxes_1_io_out_readData_bits_data),
    .io_out_readData_bits_resp(readMuxes_1_io_out_readData_bits_resp),
    .io_out_readData_bits_last(readMuxes_1_io_out_readData_bits_last),
    .io_in_0_readAddr_ready(readMuxes_1_io_in_0_readAddr_ready),
    .io_in_0_readAddr_valid(readMuxes_1_io_in_0_readAddr_valid),
    .io_in_0_readAddr_bits_id(readMuxes_1_io_in_0_readAddr_bits_id),
    .io_in_0_readAddr_bits_addr(readMuxes_1_io_in_0_readAddr_bits_addr),
    .io_in_0_readAddr_bits_size(readMuxes_1_io_in_0_readAddr_bits_size),
    .io_in_0_readData_ready(readMuxes_1_io_in_0_readData_ready),
    .io_in_0_readData_valid(readMuxes_1_io_in_0_readData_valid),
    .io_in_0_readData_bits_id(readMuxes_1_io_in_0_readData_bits_id),
    .io_in_0_readData_bits_data(readMuxes_1_io_in_0_readData_bits_data),
    .io_in_0_readData_bits_resp(readMuxes_1_io_in_0_readData_bits_resp),
    .io_in_0_readData_bits_last(readMuxes_1_io_in_0_readData_bits_last),
    .io_in_1_readAddr_ready(readMuxes_1_io_in_1_readAddr_ready),
    .io_in_1_readAddr_valid(readMuxes_1_io_in_1_readAddr_valid),
    .io_in_1_readAddr_bits_id(readMuxes_1_io_in_1_readAddr_bits_id),
    .io_in_1_readAddr_bits_addr(readMuxes_1_io_in_1_readAddr_bits_addr),
    .io_in_1_readAddr_bits_size(readMuxes_1_io_in_1_readAddr_bits_size),
    .io_in_1_readData_ready(readMuxes_1_io_in_1_readData_ready),
    .io_in_1_readData_valid(readMuxes_1_io_in_1_readData_valid),
    .io_in_1_readData_bits_id(readMuxes_1_io_in_1_readData_bits_id),
    .io_in_1_readData_bits_data(readMuxes_1_io_in_1_readData_bits_data),
    .io_in_1_readData_bits_resp(readMuxes_1_io_in_1_readData_bits_resp),
    .io_in_1_readData_bits_last(readMuxes_1_io_in_1_readData_bits_last)
  );
  AXISlaveReadMux readMuxes_2 ( // @[AXILiteXBar.scala 18:11]
    .clock(readMuxes_2_clock),
    .reset(readMuxes_2_reset),
    .io_out_readAddr_ready(readMuxes_2_io_out_readAddr_ready),
    .io_out_readAddr_valid(readMuxes_2_io_out_readAddr_valid),
    .io_out_readAddr_bits_id(readMuxes_2_io_out_readAddr_bits_id),
    .io_out_readAddr_bits_addr(readMuxes_2_io_out_readAddr_bits_addr),
    .io_out_readAddr_bits_size(readMuxes_2_io_out_readAddr_bits_size),
    .io_out_readData_ready(readMuxes_2_io_out_readData_ready),
    .io_out_readData_valid(readMuxes_2_io_out_readData_valid),
    .io_out_readData_bits_id(readMuxes_2_io_out_readData_bits_id),
    .io_out_readData_bits_data(readMuxes_2_io_out_readData_bits_data),
    .io_out_readData_bits_resp(readMuxes_2_io_out_readData_bits_resp),
    .io_out_readData_bits_last(readMuxes_2_io_out_readData_bits_last),
    .io_in_0_readAddr_ready(readMuxes_2_io_in_0_readAddr_ready),
    .io_in_0_readAddr_valid(readMuxes_2_io_in_0_readAddr_valid),
    .io_in_0_readAddr_bits_id(readMuxes_2_io_in_0_readAddr_bits_id),
    .io_in_0_readAddr_bits_addr(readMuxes_2_io_in_0_readAddr_bits_addr),
    .io_in_0_readAddr_bits_size(readMuxes_2_io_in_0_readAddr_bits_size),
    .io_in_0_readData_ready(readMuxes_2_io_in_0_readData_ready),
    .io_in_0_readData_valid(readMuxes_2_io_in_0_readData_valid),
    .io_in_0_readData_bits_id(readMuxes_2_io_in_0_readData_bits_id),
    .io_in_0_readData_bits_data(readMuxes_2_io_in_0_readData_bits_data),
    .io_in_0_readData_bits_resp(readMuxes_2_io_in_0_readData_bits_resp),
    .io_in_0_readData_bits_last(readMuxes_2_io_in_0_readData_bits_last),
    .io_in_1_readAddr_ready(readMuxes_2_io_in_1_readAddr_ready),
    .io_in_1_readAddr_valid(readMuxes_2_io_in_1_readAddr_valid),
    .io_in_1_readAddr_bits_id(readMuxes_2_io_in_1_readAddr_bits_id),
    .io_in_1_readAddr_bits_addr(readMuxes_2_io_in_1_readAddr_bits_addr),
    .io_in_1_readAddr_bits_size(readMuxes_2_io_in_1_readAddr_bits_size),
    .io_in_1_readData_ready(readMuxes_2_io_in_1_readData_ready),
    .io_in_1_readData_valid(readMuxes_2_io_in_1_readData_valid),
    .io_in_1_readData_bits_id(readMuxes_2_io_in_1_readData_bits_id),
    .io_in_1_readData_bits_data(readMuxes_2_io_in_1_readData_bits_data),
    .io_in_1_readData_bits_resp(readMuxes_2_io_in_1_readData_bits_resp),
    .io_in_1_readData_bits_last(readMuxes_2_io_in_1_readData_bits_last)
  );
  AXIWriteBus writeBuses_0 ( // @[AXILiteXBar.scala 23:11]
    .clock(writeBuses_0_clock),
    .reset(writeBuses_0_reset),
    .io_master_writeAddr_ready(writeBuses_0_io_master_writeAddr_ready),
    .io_master_writeAddr_valid(writeBuses_0_io_master_writeAddr_valid),
    .io_master_writeAddr_bits_id(writeBuses_0_io_master_writeAddr_bits_id),
    .io_master_writeAddr_bits_addr(writeBuses_0_io_master_writeAddr_bits_addr),
    .io_master_writeAddr_bits_size(writeBuses_0_io_master_writeAddr_bits_size),
    .io_master_writeData_ready(writeBuses_0_io_master_writeData_ready),
    .io_master_writeData_valid(writeBuses_0_io_master_writeData_valid),
    .io_master_writeData_bits_data(writeBuses_0_io_master_writeData_bits_data),
    .io_master_writeData_bits_strb(writeBuses_0_io_master_writeData_bits_strb),
    .io_master_writeData_bits_last(writeBuses_0_io_master_writeData_bits_last),
    .io_master_writeResp_ready(writeBuses_0_io_master_writeResp_ready),
    .io_master_writeResp_valid(writeBuses_0_io_master_writeResp_valid),
    .io_master_writeResp_bits_id(writeBuses_0_io_master_writeResp_bits_id),
    .io_master_writeResp_bits_resp(writeBuses_0_io_master_writeResp_bits_resp),
    .io_slave_0_writeAddr_ready(writeBuses_0_io_slave_0_writeAddr_ready),
    .io_slave_0_writeAddr_valid(writeBuses_0_io_slave_0_writeAddr_valid),
    .io_slave_0_writeAddr_bits_id(writeBuses_0_io_slave_0_writeAddr_bits_id),
    .io_slave_0_writeAddr_bits_addr(writeBuses_0_io_slave_0_writeAddr_bits_addr),
    .io_slave_0_writeAddr_bits_size(writeBuses_0_io_slave_0_writeAddr_bits_size),
    .io_slave_0_writeData_ready(writeBuses_0_io_slave_0_writeData_ready),
    .io_slave_0_writeData_valid(writeBuses_0_io_slave_0_writeData_valid),
    .io_slave_0_writeData_bits_data(writeBuses_0_io_slave_0_writeData_bits_data),
    .io_slave_0_writeData_bits_strb(writeBuses_0_io_slave_0_writeData_bits_strb),
    .io_slave_0_writeData_bits_last(writeBuses_0_io_slave_0_writeData_bits_last),
    .io_slave_0_writeResp_ready(writeBuses_0_io_slave_0_writeResp_ready),
    .io_slave_0_writeResp_valid(writeBuses_0_io_slave_0_writeResp_valid),
    .io_slave_0_writeResp_bits_id(writeBuses_0_io_slave_0_writeResp_bits_id),
    .io_slave_0_writeResp_bits_resp(writeBuses_0_io_slave_0_writeResp_bits_resp),
    .io_slave_1_writeAddr_ready(writeBuses_0_io_slave_1_writeAddr_ready),
    .io_slave_1_writeAddr_valid(writeBuses_0_io_slave_1_writeAddr_valid),
    .io_slave_1_writeAddr_bits_id(writeBuses_0_io_slave_1_writeAddr_bits_id),
    .io_slave_1_writeAddr_bits_addr(writeBuses_0_io_slave_1_writeAddr_bits_addr),
    .io_slave_1_writeAddr_bits_size(writeBuses_0_io_slave_1_writeAddr_bits_size),
    .io_slave_1_writeData_ready(writeBuses_0_io_slave_1_writeData_ready),
    .io_slave_1_writeData_valid(writeBuses_0_io_slave_1_writeData_valid),
    .io_slave_1_writeData_bits_data(writeBuses_0_io_slave_1_writeData_bits_data),
    .io_slave_1_writeData_bits_strb(writeBuses_0_io_slave_1_writeData_bits_strb),
    .io_slave_1_writeData_bits_last(writeBuses_0_io_slave_1_writeData_bits_last),
    .io_slave_1_writeResp_ready(writeBuses_0_io_slave_1_writeResp_ready),
    .io_slave_1_writeResp_valid(writeBuses_0_io_slave_1_writeResp_valid),
    .io_slave_1_writeResp_bits_id(writeBuses_0_io_slave_1_writeResp_bits_id),
    .io_slave_1_writeResp_bits_resp(writeBuses_0_io_slave_1_writeResp_bits_resp),
    .io_slave_2_writeAddr_ready(writeBuses_0_io_slave_2_writeAddr_ready),
    .io_slave_2_writeAddr_valid(writeBuses_0_io_slave_2_writeAddr_valid),
    .io_slave_2_writeAddr_bits_id(writeBuses_0_io_slave_2_writeAddr_bits_id),
    .io_slave_2_writeAddr_bits_addr(writeBuses_0_io_slave_2_writeAddr_bits_addr),
    .io_slave_2_writeAddr_bits_size(writeBuses_0_io_slave_2_writeAddr_bits_size),
    .io_slave_2_writeData_ready(writeBuses_0_io_slave_2_writeData_ready),
    .io_slave_2_writeData_valid(writeBuses_0_io_slave_2_writeData_valid),
    .io_slave_2_writeData_bits_data(writeBuses_0_io_slave_2_writeData_bits_data),
    .io_slave_2_writeData_bits_strb(writeBuses_0_io_slave_2_writeData_bits_strb),
    .io_slave_2_writeData_bits_last(writeBuses_0_io_slave_2_writeData_bits_last),
    .io_slave_2_writeResp_ready(writeBuses_0_io_slave_2_writeResp_ready),
    .io_slave_2_writeResp_valid(writeBuses_0_io_slave_2_writeResp_valid),
    .io_slave_2_writeResp_bits_id(writeBuses_0_io_slave_2_writeResp_bits_id),
    .io_slave_2_writeResp_bits_resp(writeBuses_0_io_slave_2_writeResp_bits_resp)
  );
  AXIWriteBus writeBuses_1 ( // @[AXILiteXBar.scala 23:11]
    .clock(writeBuses_1_clock),
    .reset(writeBuses_1_reset),
    .io_master_writeAddr_ready(writeBuses_1_io_master_writeAddr_ready),
    .io_master_writeAddr_valid(writeBuses_1_io_master_writeAddr_valid),
    .io_master_writeAddr_bits_id(writeBuses_1_io_master_writeAddr_bits_id),
    .io_master_writeAddr_bits_addr(writeBuses_1_io_master_writeAddr_bits_addr),
    .io_master_writeAddr_bits_size(writeBuses_1_io_master_writeAddr_bits_size),
    .io_master_writeData_ready(writeBuses_1_io_master_writeData_ready),
    .io_master_writeData_valid(writeBuses_1_io_master_writeData_valid),
    .io_master_writeData_bits_data(writeBuses_1_io_master_writeData_bits_data),
    .io_master_writeData_bits_strb(writeBuses_1_io_master_writeData_bits_strb),
    .io_master_writeData_bits_last(writeBuses_1_io_master_writeData_bits_last),
    .io_master_writeResp_ready(writeBuses_1_io_master_writeResp_ready),
    .io_master_writeResp_valid(writeBuses_1_io_master_writeResp_valid),
    .io_master_writeResp_bits_id(writeBuses_1_io_master_writeResp_bits_id),
    .io_master_writeResp_bits_resp(writeBuses_1_io_master_writeResp_bits_resp),
    .io_slave_0_writeAddr_ready(writeBuses_1_io_slave_0_writeAddr_ready),
    .io_slave_0_writeAddr_valid(writeBuses_1_io_slave_0_writeAddr_valid),
    .io_slave_0_writeAddr_bits_id(writeBuses_1_io_slave_0_writeAddr_bits_id),
    .io_slave_0_writeAddr_bits_addr(writeBuses_1_io_slave_0_writeAddr_bits_addr),
    .io_slave_0_writeAddr_bits_size(writeBuses_1_io_slave_0_writeAddr_bits_size),
    .io_slave_0_writeData_ready(writeBuses_1_io_slave_0_writeData_ready),
    .io_slave_0_writeData_valid(writeBuses_1_io_slave_0_writeData_valid),
    .io_slave_0_writeData_bits_data(writeBuses_1_io_slave_0_writeData_bits_data),
    .io_slave_0_writeData_bits_strb(writeBuses_1_io_slave_0_writeData_bits_strb),
    .io_slave_0_writeData_bits_last(writeBuses_1_io_slave_0_writeData_bits_last),
    .io_slave_0_writeResp_ready(writeBuses_1_io_slave_0_writeResp_ready),
    .io_slave_0_writeResp_valid(writeBuses_1_io_slave_0_writeResp_valid),
    .io_slave_0_writeResp_bits_id(writeBuses_1_io_slave_0_writeResp_bits_id),
    .io_slave_0_writeResp_bits_resp(writeBuses_1_io_slave_0_writeResp_bits_resp),
    .io_slave_1_writeAddr_ready(writeBuses_1_io_slave_1_writeAddr_ready),
    .io_slave_1_writeAddr_valid(writeBuses_1_io_slave_1_writeAddr_valid),
    .io_slave_1_writeAddr_bits_id(writeBuses_1_io_slave_1_writeAddr_bits_id),
    .io_slave_1_writeAddr_bits_addr(writeBuses_1_io_slave_1_writeAddr_bits_addr),
    .io_slave_1_writeAddr_bits_size(writeBuses_1_io_slave_1_writeAddr_bits_size),
    .io_slave_1_writeData_ready(writeBuses_1_io_slave_1_writeData_ready),
    .io_slave_1_writeData_valid(writeBuses_1_io_slave_1_writeData_valid),
    .io_slave_1_writeData_bits_data(writeBuses_1_io_slave_1_writeData_bits_data),
    .io_slave_1_writeData_bits_strb(writeBuses_1_io_slave_1_writeData_bits_strb),
    .io_slave_1_writeData_bits_last(writeBuses_1_io_slave_1_writeData_bits_last),
    .io_slave_1_writeResp_ready(writeBuses_1_io_slave_1_writeResp_ready),
    .io_slave_1_writeResp_valid(writeBuses_1_io_slave_1_writeResp_valid),
    .io_slave_1_writeResp_bits_id(writeBuses_1_io_slave_1_writeResp_bits_id),
    .io_slave_1_writeResp_bits_resp(writeBuses_1_io_slave_1_writeResp_bits_resp),
    .io_slave_2_writeAddr_ready(writeBuses_1_io_slave_2_writeAddr_ready),
    .io_slave_2_writeAddr_valid(writeBuses_1_io_slave_2_writeAddr_valid),
    .io_slave_2_writeAddr_bits_id(writeBuses_1_io_slave_2_writeAddr_bits_id),
    .io_slave_2_writeAddr_bits_addr(writeBuses_1_io_slave_2_writeAddr_bits_addr),
    .io_slave_2_writeAddr_bits_size(writeBuses_1_io_slave_2_writeAddr_bits_size),
    .io_slave_2_writeData_ready(writeBuses_1_io_slave_2_writeData_ready),
    .io_slave_2_writeData_valid(writeBuses_1_io_slave_2_writeData_valid),
    .io_slave_2_writeData_bits_data(writeBuses_1_io_slave_2_writeData_bits_data),
    .io_slave_2_writeData_bits_strb(writeBuses_1_io_slave_2_writeData_bits_strb),
    .io_slave_2_writeData_bits_last(writeBuses_1_io_slave_2_writeData_bits_last),
    .io_slave_2_writeResp_ready(writeBuses_1_io_slave_2_writeResp_ready),
    .io_slave_2_writeResp_valid(writeBuses_1_io_slave_2_writeResp_valid),
    .io_slave_2_writeResp_bits_id(writeBuses_1_io_slave_2_writeResp_bits_id),
    .io_slave_2_writeResp_bits_resp(writeBuses_1_io_slave_2_writeResp_bits_resp)
  );
  AXISlaveWriteMux writeMuxes_0 ( // @[AXILiteXBar.scala 27:11]
    .clock(writeMuxes_0_clock),
    .reset(writeMuxes_0_reset),
    .io_out_writeAddr_ready(writeMuxes_0_io_out_writeAddr_ready),
    .io_out_writeAddr_valid(writeMuxes_0_io_out_writeAddr_valid),
    .io_out_writeAddr_bits_id(writeMuxes_0_io_out_writeAddr_bits_id),
    .io_out_writeAddr_bits_addr(writeMuxes_0_io_out_writeAddr_bits_addr),
    .io_out_writeAddr_bits_size(writeMuxes_0_io_out_writeAddr_bits_size),
    .io_out_writeData_ready(writeMuxes_0_io_out_writeData_ready),
    .io_out_writeData_valid(writeMuxes_0_io_out_writeData_valid),
    .io_out_writeData_bits_data(writeMuxes_0_io_out_writeData_bits_data),
    .io_out_writeData_bits_strb(writeMuxes_0_io_out_writeData_bits_strb),
    .io_out_writeData_bits_last(writeMuxes_0_io_out_writeData_bits_last),
    .io_out_writeResp_ready(writeMuxes_0_io_out_writeResp_ready),
    .io_out_writeResp_valid(writeMuxes_0_io_out_writeResp_valid),
    .io_out_writeResp_bits_id(writeMuxes_0_io_out_writeResp_bits_id),
    .io_out_writeResp_bits_resp(writeMuxes_0_io_out_writeResp_bits_resp),
    .io_in_0_writeAddr_ready(writeMuxes_0_io_in_0_writeAddr_ready),
    .io_in_0_writeAddr_valid(writeMuxes_0_io_in_0_writeAddr_valid),
    .io_in_0_writeAddr_bits_id(writeMuxes_0_io_in_0_writeAddr_bits_id),
    .io_in_0_writeAddr_bits_addr(writeMuxes_0_io_in_0_writeAddr_bits_addr),
    .io_in_0_writeAddr_bits_size(writeMuxes_0_io_in_0_writeAddr_bits_size),
    .io_in_0_writeData_ready(writeMuxes_0_io_in_0_writeData_ready),
    .io_in_0_writeData_valid(writeMuxes_0_io_in_0_writeData_valid),
    .io_in_0_writeData_bits_data(writeMuxes_0_io_in_0_writeData_bits_data),
    .io_in_0_writeData_bits_strb(writeMuxes_0_io_in_0_writeData_bits_strb),
    .io_in_0_writeData_bits_last(writeMuxes_0_io_in_0_writeData_bits_last),
    .io_in_0_writeResp_ready(writeMuxes_0_io_in_0_writeResp_ready),
    .io_in_0_writeResp_valid(writeMuxes_0_io_in_0_writeResp_valid),
    .io_in_0_writeResp_bits_id(writeMuxes_0_io_in_0_writeResp_bits_id),
    .io_in_0_writeResp_bits_resp(writeMuxes_0_io_in_0_writeResp_bits_resp),
    .io_in_1_writeAddr_ready(writeMuxes_0_io_in_1_writeAddr_ready),
    .io_in_1_writeAddr_valid(writeMuxes_0_io_in_1_writeAddr_valid),
    .io_in_1_writeAddr_bits_id(writeMuxes_0_io_in_1_writeAddr_bits_id),
    .io_in_1_writeAddr_bits_addr(writeMuxes_0_io_in_1_writeAddr_bits_addr),
    .io_in_1_writeAddr_bits_size(writeMuxes_0_io_in_1_writeAddr_bits_size),
    .io_in_1_writeData_ready(writeMuxes_0_io_in_1_writeData_ready),
    .io_in_1_writeData_valid(writeMuxes_0_io_in_1_writeData_valid),
    .io_in_1_writeData_bits_data(writeMuxes_0_io_in_1_writeData_bits_data),
    .io_in_1_writeData_bits_strb(writeMuxes_0_io_in_1_writeData_bits_strb),
    .io_in_1_writeData_bits_last(writeMuxes_0_io_in_1_writeData_bits_last),
    .io_in_1_writeResp_ready(writeMuxes_0_io_in_1_writeResp_ready),
    .io_in_1_writeResp_valid(writeMuxes_0_io_in_1_writeResp_valid),
    .io_in_1_writeResp_bits_id(writeMuxes_0_io_in_1_writeResp_bits_id),
    .io_in_1_writeResp_bits_resp(writeMuxes_0_io_in_1_writeResp_bits_resp)
  );
  AXISlaveWriteMux writeMuxes_1 ( // @[AXILiteXBar.scala 27:11]
    .clock(writeMuxes_1_clock),
    .reset(writeMuxes_1_reset),
    .io_out_writeAddr_ready(writeMuxes_1_io_out_writeAddr_ready),
    .io_out_writeAddr_valid(writeMuxes_1_io_out_writeAddr_valid),
    .io_out_writeAddr_bits_id(writeMuxes_1_io_out_writeAddr_bits_id),
    .io_out_writeAddr_bits_addr(writeMuxes_1_io_out_writeAddr_bits_addr),
    .io_out_writeAddr_bits_size(writeMuxes_1_io_out_writeAddr_bits_size),
    .io_out_writeData_ready(writeMuxes_1_io_out_writeData_ready),
    .io_out_writeData_valid(writeMuxes_1_io_out_writeData_valid),
    .io_out_writeData_bits_data(writeMuxes_1_io_out_writeData_bits_data),
    .io_out_writeData_bits_strb(writeMuxes_1_io_out_writeData_bits_strb),
    .io_out_writeData_bits_last(writeMuxes_1_io_out_writeData_bits_last),
    .io_out_writeResp_ready(writeMuxes_1_io_out_writeResp_ready),
    .io_out_writeResp_valid(writeMuxes_1_io_out_writeResp_valid),
    .io_out_writeResp_bits_id(writeMuxes_1_io_out_writeResp_bits_id),
    .io_out_writeResp_bits_resp(writeMuxes_1_io_out_writeResp_bits_resp),
    .io_in_0_writeAddr_ready(writeMuxes_1_io_in_0_writeAddr_ready),
    .io_in_0_writeAddr_valid(writeMuxes_1_io_in_0_writeAddr_valid),
    .io_in_0_writeAddr_bits_id(writeMuxes_1_io_in_0_writeAddr_bits_id),
    .io_in_0_writeAddr_bits_addr(writeMuxes_1_io_in_0_writeAddr_bits_addr),
    .io_in_0_writeAddr_bits_size(writeMuxes_1_io_in_0_writeAddr_bits_size),
    .io_in_0_writeData_ready(writeMuxes_1_io_in_0_writeData_ready),
    .io_in_0_writeData_valid(writeMuxes_1_io_in_0_writeData_valid),
    .io_in_0_writeData_bits_data(writeMuxes_1_io_in_0_writeData_bits_data),
    .io_in_0_writeData_bits_strb(writeMuxes_1_io_in_0_writeData_bits_strb),
    .io_in_0_writeData_bits_last(writeMuxes_1_io_in_0_writeData_bits_last),
    .io_in_0_writeResp_ready(writeMuxes_1_io_in_0_writeResp_ready),
    .io_in_0_writeResp_valid(writeMuxes_1_io_in_0_writeResp_valid),
    .io_in_0_writeResp_bits_id(writeMuxes_1_io_in_0_writeResp_bits_id),
    .io_in_0_writeResp_bits_resp(writeMuxes_1_io_in_0_writeResp_bits_resp),
    .io_in_1_writeAddr_ready(writeMuxes_1_io_in_1_writeAddr_ready),
    .io_in_1_writeAddr_valid(writeMuxes_1_io_in_1_writeAddr_valid),
    .io_in_1_writeAddr_bits_id(writeMuxes_1_io_in_1_writeAddr_bits_id),
    .io_in_1_writeAddr_bits_addr(writeMuxes_1_io_in_1_writeAddr_bits_addr),
    .io_in_1_writeAddr_bits_size(writeMuxes_1_io_in_1_writeAddr_bits_size),
    .io_in_1_writeData_ready(writeMuxes_1_io_in_1_writeData_ready),
    .io_in_1_writeData_valid(writeMuxes_1_io_in_1_writeData_valid),
    .io_in_1_writeData_bits_data(writeMuxes_1_io_in_1_writeData_bits_data),
    .io_in_1_writeData_bits_strb(writeMuxes_1_io_in_1_writeData_bits_strb),
    .io_in_1_writeData_bits_last(writeMuxes_1_io_in_1_writeData_bits_last),
    .io_in_1_writeResp_ready(writeMuxes_1_io_in_1_writeResp_ready),
    .io_in_1_writeResp_valid(writeMuxes_1_io_in_1_writeResp_valid),
    .io_in_1_writeResp_bits_id(writeMuxes_1_io_in_1_writeResp_bits_id),
    .io_in_1_writeResp_bits_resp(writeMuxes_1_io_in_1_writeResp_bits_resp)
  );
  AXISlaveWriteMux writeMuxes_2 ( // @[AXILiteXBar.scala 27:11]
    .clock(writeMuxes_2_clock),
    .reset(writeMuxes_2_reset),
    .io_out_writeAddr_ready(writeMuxes_2_io_out_writeAddr_ready),
    .io_out_writeAddr_valid(writeMuxes_2_io_out_writeAddr_valid),
    .io_out_writeAddr_bits_id(writeMuxes_2_io_out_writeAddr_bits_id),
    .io_out_writeAddr_bits_addr(writeMuxes_2_io_out_writeAddr_bits_addr),
    .io_out_writeAddr_bits_size(writeMuxes_2_io_out_writeAddr_bits_size),
    .io_out_writeData_ready(writeMuxes_2_io_out_writeData_ready),
    .io_out_writeData_valid(writeMuxes_2_io_out_writeData_valid),
    .io_out_writeData_bits_data(writeMuxes_2_io_out_writeData_bits_data),
    .io_out_writeData_bits_strb(writeMuxes_2_io_out_writeData_bits_strb),
    .io_out_writeData_bits_last(writeMuxes_2_io_out_writeData_bits_last),
    .io_out_writeResp_ready(writeMuxes_2_io_out_writeResp_ready),
    .io_out_writeResp_valid(writeMuxes_2_io_out_writeResp_valid),
    .io_out_writeResp_bits_id(writeMuxes_2_io_out_writeResp_bits_id),
    .io_out_writeResp_bits_resp(writeMuxes_2_io_out_writeResp_bits_resp),
    .io_in_0_writeAddr_ready(writeMuxes_2_io_in_0_writeAddr_ready),
    .io_in_0_writeAddr_valid(writeMuxes_2_io_in_0_writeAddr_valid),
    .io_in_0_writeAddr_bits_id(writeMuxes_2_io_in_0_writeAddr_bits_id),
    .io_in_0_writeAddr_bits_addr(writeMuxes_2_io_in_0_writeAddr_bits_addr),
    .io_in_0_writeAddr_bits_size(writeMuxes_2_io_in_0_writeAddr_bits_size),
    .io_in_0_writeData_ready(writeMuxes_2_io_in_0_writeData_ready),
    .io_in_0_writeData_valid(writeMuxes_2_io_in_0_writeData_valid),
    .io_in_0_writeData_bits_data(writeMuxes_2_io_in_0_writeData_bits_data),
    .io_in_0_writeData_bits_strb(writeMuxes_2_io_in_0_writeData_bits_strb),
    .io_in_0_writeData_bits_last(writeMuxes_2_io_in_0_writeData_bits_last),
    .io_in_0_writeResp_ready(writeMuxes_2_io_in_0_writeResp_ready),
    .io_in_0_writeResp_valid(writeMuxes_2_io_in_0_writeResp_valid),
    .io_in_0_writeResp_bits_id(writeMuxes_2_io_in_0_writeResp_bits_id),
    .io_in_0_writeResp_bits_resp(writeMuxes_2_io_in_0_writeResp_bits_resp),
    .io_in_1_writeAddr_ready(writeMuxes_2_io_in_1_writeAddr_ready),
    .io_in_1_writeAddr_valid(writeMuxes_2_io_in_1_writeAddr_valid),
    .io_in_1_writeAddr_bits_id(writeMuxes_2_io_in_1_writeAddr_bits_id),
    .io_in_1_writeAddr_bits_addr(writeMuxes_2_io_in_1_writeAddr_bits_addr),
    .io_in_1_writeAddr_bits_size(writeMuxes_2_io_in_1_writeAddr_bits_size),
    .io_in_1_writeData_ready(writeMuxes_2_io_in_1_writeData_ready),
    .io_in_1_writeData_valid(writeMuxes_2_io_in_1_writeData_valid),
    .io_in_1_writeData_bits_data(writeMuxes_2_io_in_1_writeData_bits_data),
    .io_in_1_writeData_bits_strb(writeMuxes_2_io_in_1_writeData_bits_strb),
    .io_in_1_writeData_bits_last(writeMuxes_2_io_in_1_writeData_bits_last),
    .io_in_1_writeResp_ready(writeMuxes_2_io_in_1_writeResp_ready),
    .io_in_1_writeResp_valid(writeMuxes_2_io_in_1_writeResp_valid),
    .io_in_1_writeResp_bits_id(writeMuxes_2_io_in_1_writeResp_bits_id),
    .io_in_1_writeResp_bits_resp(writeMuxes_2_io_in_1_writeResp_bits_resp)
  );
  assign io_masters_0_aw_ready = writeBuses_0_io_master_writeAddr_ready; // @[AXILiteXBar.scala 37:15]
  assign io_masters_0_w_ready = writeBuses_0_io_master_writeData_ready; // @[AXILiteXBar.scala 38:14]
  assign io_masters_0_b_valid = writeBuses_0_io_master_writeResp_valid; // @[AXILiteXBar.scala 39:14]
  assign io_masters_0_ar_ready = readBuses_0_io_master_readAddr_ready; // @[AXILiteXBar.scala 32:15]
  assign io_masters_0_r_valid = readBuses_0_io_master_readData_valid; // @[AXILiteXBar.scala 33:14]
  assign io_masters_0_r_bits_data = readBuses_0_io_master_readData_bits_data; // @[AXILiteXBar.scala 33:14]
  assign io_masters_1_aw_ready = writeBuses_1_io_master_writeAddr_ready; // @[AXILiteXBar.scala 37:15]
  assign io_masters_1_w_ready = writeBuses_1_io_master_writeData_ready; // @[AXILiteXBar.scala 38:14]
  assign io_masters_1_b_valid = writeBuses_1_io_master_writeResp_valid; // @[AXILiteXBar.scala 39:14]
  assign io_masters_1_b_bits_id = writeBuses_1_io_master_writeResp_bits_id; // @[AXILiteXBar.scala 39:14]
  assign io_masters_1_b_bits_resp = writeBuses_1_io_master_writeResp_bits_resp; // @[AXILiteXBar.scala 39:14]
  assign io_masters_1_ar_ready = readBuses_1_io_master_readAddr_ready; // @[AXILiteXBar.scala 32:15]
  assign io_masters_1_r_valid = readBuses_1_io_master_readData_valid; // @[AXILiteXBar.scala 33:14]
  assign io_masters_1_r_bits_id = readBuses_1_io_master_readData_bits_id; // @[AXILiteXBar.scala 33:14]
  assign io_masters_1_r_bits_data = readBuses_1_io_master_readData_bits_data; // @[AXILiteXBar.scala 33:14]
  assign io_masters_1_r_bits_resp = readBuses_1_io_master_readData_bits_resp; // @[AXILiteXBar.scala 33:14]
  assign io_masters_1_r_bits_last = readBuses_1_io_master_readData_bits_last; // @[AXILiteXBar.scala 33:14]
  assign io_slaves_0_aw_valid = writeMuxes_0_io_out_writeAddr_valid; // @[AXILiteXBar.scala 51:16]
  assign io_slaves_0_aw_bits_id = writeMuxes_0_io_out_writeAddr_bits_id; // @[AXILiteXBar.scala 51:16]
  assign io_slaves_0_aw_bits_addr = writeMuxes_0_io_out_writeAddr_bits_addr; // @[AXILiteXBar.scala 51:16]
  assign io_slaves_0_aw_bits_size = writeMuxes_0_io_out_writeAddr_bits_size; // @[AXILiteXBar.scala 51:16]
  assign io_slaves_0_w_valid = writeMuxes_0_io_out_writeData_valid; // @[AXILiteXBar.scala 52:15]
  assign io_slaves_0_w_bits_data = writeMuxes_0_io_out_writeData_bits_data; // @[AXILiteXBar.scala 52:15]
  assign io_slaves_0_w_bits_strb = writeMuxes_0_io_out_writeData_bits_strb; // @[AXILiteXBar.scala 52:15]
  assign io_slaves_0_w_bits_last = writeMuxes_0_io_out_writeData_bits_last; // @[AXILiteXBar.scala 52:15]
  assign io_slaves_0_b_ready = writeMuxes_0_io_out_writeResp_ready; // @[AXILiteXBar.scala 53:15]
  assign io_slaves_0_ar_valid = readMuxes_0_io_out_readAddr_valid; // @[AXILiteXBar.scala 45:16]
  assign io_slaves_0_ar_bits_id = readMuxes_0_io_out_readAddr_bits_id; // @[AXILiteXBar.scala 45:16]
  assign io_slaves_0_ar_bits_addr = readMuxes_0_io_out_readAddr_bits_addr; // @[AXILiteXBar.scala 45:16]
  assign io_slaves_0_ar_bits_size = readMuxes_0_io_out_readAddr_bits_size; // @[AXILiteXBar.scala 45:16]
  assign io_slaves_0_r_ready = readMuxes_0_io_out_readData_ready; // @[AXILiteXBar.scala 46:15]
  assign io_slaves_1_aw_valid = writeMuxes_1_io_out_writeAddr_valid; // @[AXILiteXBar.scala 51:16]
  assign io_slaves_1_aw_bits_id = writeMuxes_1_io_out_writeAddr_bits_id; // @[AXILiteXBar.scala 51:16]
  assign io_slaves_1_aw_bits_addr = writeMuxes_1_io_out_writeAddr_bits_addr; // @[AXILiteXBar.scala 51:16]
  assign io_slaves_1_w_valid = writeMuxes_1_io_out_writeData_valid; // @[AXILiteXBar.scala 52:15]
  assign io_slaves_1_w_bits_data = writeMuxes_1_io_out_writeData_bits_data; // @[AXILiteXBar.scala 52:15]
  assign io_slaves_1_w_bits_strb = writeMuxes_1_io_out_writeData_bits_strb; // @[AXILiteXBar.scala 52:15]
  assign io_slaves_1_w_bits_last = writeMuxes_1_io_out_writeData_bits_last; // @[AXILiteXBar.scala 52:15]
  assign io_slaves_1_b_ready = writeMuxes_1_io_out_writeResp_ready; // @[AXILiteXBar.scala 53:15]
  assign io_slaves_1_ar_valid = readMuxes_1_io_out_readAddr_valid; // @[AXILiteXBar.scala 45:16]
  assign io_slaves_1_ar_bits_id = readMuxes_1_io_out_readAddr_bits_id; // @[AXILiteXBar.scala 45:16]
  assign io_slaves_1_ar_bits_addr = readMuxes_1_io_out_readAddr_bits_addr; // @[AXILiteXBar.scala 45:16]
  assign io_slaves_1_r_ready = readMuxes_1_io_out_readData_ready; // @[AXILiteXBar.scala 46:15]
  assign io_slaves_2_aw_valid = writeMuxes_2_io_out_writeAddr_valid; // @[AXILiteXBar.scala 51:16]
  assign io_slaves_2_aw_bits_id = writeMuxes_2_io_out_writeAddr_bits_id; // @[AXILiteXBar.scala 51:16]
  assign io_slaves_2_aw_bits_addr = writeMuxes_2_io_out_writeAddr_bits_addr; // @[AXILiteXBar.scala 51:16]
  assign io_slaves_2_w_valid = writeMuxes_2_io_out_writeData_valid; // @[AXILiteXBar.scala 52:15]
  assign io_slaves_2_w_bits_data = writeMuxes_2_io_out_writeData_bits_data; // @[AXILiteXBar.scala 52:15]
  assign io_slaves_2_w_bits_strb = writeMuxes_2_io_out_writeData_bits_strb; // @[AXILiteXBar.scala 52:15]
  assign io_slaves_2_w_bits_last = writeMuxes_2_io_out_writeData_bits_last; // @[AXILiteXBar.scala 52:15]
  assign io_slaves_2_b_ready = writeMuxes_2_io_out_writeResp_ready; // @[AXILiteXBar.scala 53:15]
  assign io_slaves_2_ar_valid = readMuxes_2_io_out_readAddr_valid; // @[AXILiteXBar.scala 45:16]
  assign io_slaves_2_ar_bits_id = readMuxes_2_io_out_readAddr_bits_id; // @[AXILiteXBar.scala 45:16]
  assign io_slaves_2_ar_bits_addr = readMuxes_2_io_out_readAddr_bits_addr; // @[AXILiteXBar.scala 45:16]
  assign io_slaves_2_r_ready = readMuxes_2_io_out_readData_ready; // @[AXILiteXBar.scala 46:15]
  assign readBuses_0_clock = clock;
  assign readBuses_0_reset = reset;
  assign readBuses_0_io_master_readAddr_valid = io_masters_0_ar_valid; // @[AXILiteXBar.scala 32:15]
  assign readBuses_0_io_master_readAddr_bits_id = 4'h0; // @[AXILiteXBar.scala 32:15]
  assign readBuses_0_io_master_readAddr_bits_addr = io_masters_0_ar_bits_addr; // @[AXILiteXBar.scala 32:15]
  assign readBuses_0_io_master_readAddr_bits_size = 2'h2; // @[AXILiteXBar.scala 32:15]
  assign readBuses_0_io_master_readData_ready = io_masters_0_r_ready; // @[AXILiteXBar.scala 33:14]
  assign readBuses_0_io_slave_0_readAddr_ready = readMuxes_0_io_in_0_readAddr_ready; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_0_readData_valid = readMuxes_0_io_in_0_readData_valid; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_0_readData_bits_id = readMuxes_0_io_in_0_readData_bits_id; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_0_readData_bits_data = readMuxes_0_io_in_0_readData_bits_data; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_0_readData_bits_resp = readMuxes_0_io_in_0_readData_bits_resp; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_0_readData_bits_last = readMuxes_0_io_in_0_readData_bits_last; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_1_readAddr_ready = readMuxes_1_io_in_0_readAddr_ready; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_1_readData_valid = readMuxes_1_io_in_0_readData_valid; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_1_readData_bits_id = readMuxes_1_io_in_0_readData_bits_id; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_1_readData_bits_data = readMuxes_1_io_in_0_readData_bits_data; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_1_readData_bits_resp = readMuxes_1_io_in_0_readData_bits_resp; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_1_readData_bits_last = readMuxes_1_io_in_0_readData_bits_last; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_2_readAddr_ready = readMuxes_2_io_in_0_readAddr_ready; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_2_readData_valid = readMuxes_2_io_in_0_readData_valid; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_2_readData_bits_id = readMuxes_2_io_in_0_readData_bits_id; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_2_readData_bits_data = readMuxes_2_io_in_0_readData_bits_data; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_2_readData_bits_resp = readMuxes_2_io_in_0_readData_bits_resp; // @[AXILiteXBar.scala 58:30]
  assign readBuses_0_io_slave_2_readData_bits_last = readMuxes_2_io_in_0_readData_bits_last; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_clock = clock;
  assign readBuses_1_reset = reset;
  assign readBuses_1_io_master_readAddr_valid = io_masters_1_ar_valid; // @[AXILiteXBar.scala 32:15]
  assign readBuses_1_io_master_readAddr_bits_id = io_masters_1_ar_bits_id; // @[AXILiteXBar.scala 32:15]
  assign readBuses_1_io_master_readAddr_bits_addr = io_masters_1_ar_bits_addr; // @[AXILiteXBar.scala 32:15]
  assign readBuses_1_io_master_readAddr_bits_size = io_masters_1_ar_bits_size; // @[AXILiteXBar.scala 32:15]
  assign readBuses_1_io_master_readData_ready = io_masters_1_r_ready; // @[AXILiteXBar.scala 33:14]
  assign readBuses_1_io_slave_0_readAddr_ready = readMuxes_0_io_in_1_readAddr_ready; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_0_readData_valid = readMuxes_0_io_in_1_readData_valid; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_0_readData_bits_id = readMuxes_0_io_in_1_readData_bits_id; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_0_readData_bits_data = readMuxes_0_io_in_1_readData_bits_data; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_0_readData_bits_resp = readMuxes_0_io_in_1_readData_bits_resp; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_0_readData_bits_last = readMuxes_0_io_in_1_readData_bits_last; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_1_readAddr_ready = readMuxes_1_io_in_1_readAddr_ready; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_1_readData_valid = readMuxes_1_io_in_1_readData_valid; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_1_readData_bits_id = readMuxes_1_io_in_1_readData_bits_id; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_1_readData_bits_data = readMuxes_1_io_in_1_readData_bits_data; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_1_readData_bits_resp = readMuxes_1_io_in_1_readData_bits_resp; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_1_readData_bits_last = readMuxes_1_io_in_1_readData_bits_last; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_2_readAddr_ready = readMuxes_2_io_in_1_readAddr_ready; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_2_readData_valid = readMuxes_2_io_in_1_readData_valid; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_2_readData_bits_id = readMuxes_2_io_in_1_readData_bits_id; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_2_readData_bits_data = readMuxes_2_io_in_1_readData_bits_data; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_2_readData_bits_resp = readMuxes_2_io_in_1_readData_bits_resp; // @[AXILiteXBar.scala 58:30]
  assign readBuses_1_io_slave_2_readData_bits_last = readMuxes_2_io_in_1_readData_bits_last; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_0_clock = clock;
  assign readMuxes_0_reset = reset;
  assign readMuxes_0_io_out_readAddr_ready = io_slaves_0_ar_ready; // @[AXILiteXBar.scala 45:16]
  assign readMuxes_0_io_out_readData_valid = io_slaves_0_r_valid; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_0_io_out_readData_bits_id = io_slaves_0_r_bits_id; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_0_io_out_readData_bits_data = io_slaves_0_r_bits_data; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_0_io_out_readData_bits_resp = io_slaves_0_r_bits_resp; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_0_io_out_readData_bits_last = io_slaves_0_r_bits_last; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_0_io_in_0_readAddr_valid = readBuses_0_io_slave_0_readAddr_valid; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_0_io_in_0_readAddr_bits_id = readBuses_0_io_slave_0_readAddr_bits_id; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_0_io_in_0_readAddr_bits_addr = readBuses_0_io_slave_0_readAddr_bits_addr; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_0_io_in_0_readAddr_bits_size = readBuses_0_io_slave_0_readAddr_bits_size; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_0_io_in_0_readData_ready = readBuses_0_io_slave_0_readData_ready; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_0_io_in_1_readAddr_valid = readBuses_1_io_slave_0_readAddr_valid; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_0_io_in_1_readAddr_bits_id = readBuses_1_io_slave_0_readAddr_bits_id; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_0_io_in_1_readAddr_bits_addr = readBuses_1_io_slave_0_readAddr_bits_addr; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_0_io_in_1_readAddr_bits_size = readBuses_1_io_slave_0_readAddr_bits_size; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_0_io_in_1_readData_ready = readBuses_1_io_slave_0_readData_ready; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_1_clock = clock;
  assign readMuxes_1_reset = reset;
  assign readMuxes_1_io_out_readAddr_ready = io_slaves_1_ar_ready; // @[AXILiteXBar.scala 45:16]
  assign readMuxes_1_io_out_readData_valid = io_slaves_1_r_valid; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_1_io_out_readData_bits_id = io_slaves_1_r_bits_id; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_1_io_out_readData_bits_data = io_slaves_1_r_bits_data; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_1_io_out_readData_bits_resp = 2'h0; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_1_io_out_readData_bits_last = io_slaves_1_r_bits_last; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_1_io_in_0_readAddr_valid = readBuses_0_io_slave_1_readAddr_valid; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_1_io_in_0_readAddr_bits_id = readBuses_0_io_slave_1_readAddr_bits_id; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_1_io_in_0_readAddr_bits_addr = readBuses_0_io_slave_1_readAddr_bits_addr; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_1_io_in_0_readAddr_bits_size = readBuses_0_io_slave_1_readAddr_bits_size; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_1_io_in_0_readData_ready = readBuses_0_io_slave_1_readData_ready; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_1_io_in_1_readAddr_valid = readBuses_1_io_slave_1_readAddr_valid; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_1_io_in_1_readAddr_bits_id = readBuses_1_io_slave_1_readAddr_bits_id; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_1_io_in_1_readAddr_bits_addr = readBuses_1_io_slave_1_readAddr_bits_addr; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_1_io_in_1_readAddr_bits_size = readBuses_1_io_slave_1_readAddr_bits_size; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_1_io_in_1_readData_ready = readBuses_1_io_slave_1_readData_ready; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_2_clock = clock;
  assign readMuxes_2_reset = reset;
  assign readMuxes_2_io_out_readAddr_ready = io_slaves_2_ar_ready; // @[AXILiteXBar.scala 45:16]
  assign readMuxes_2_io_out_readData_valid = io_slaves_2_r_valid; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_2_io_out_readData_bits_id = io_slaves_2_r_bits_id; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_2_io_out_readData_bits_data = io_slaves_2_r_bits_data; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_2_io_out_readData_bits_resp = 2'h0; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_2_io_out_readData_bits_last = io_slaves_2_r_bits_last; // @[AXILiteXBar.scala 46:15]
  assign readMuxes_2_io_in_0_readAddr_valid = readBuses_0_io_slave_2_readAddr_valid; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_2_io_in_0_readAddr_bits_id = readBuses_0_io_slave_2_readAddr_bits_id; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_2_io_in_0_readAddr_bits_addr = readBuses_0_io_slave_2_readAddr_bits_addr; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_2_io_in_0_readAddr_bits_size = readBuses_0_io_slave_2_readAddr_bits_size; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_2_io_in_0_readData_ready = readBuses_0_io_slave_2_readData_ready; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_2_io_in_1_readAddr_valid = readBuses_1_io_slave_2_readAddr_valid; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_2_io_in_1_readAddr_bits_id = readBuses_1_io_slave_2_readAddr_bits_id; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_2_io_in_1_readAddr_bits_addr = readBuses_1_io_slave_2_readAddr_bits_addr; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_2_io_in_1_readAddr_bits_size = readBuses_1_io_slave_2_readAddr_bits_size; // @[AXILiteXBar.scala 58:30]
  assign readMuxes_2_io_in_1_readData_ready = readBuses_1_io_slave_2_readData_ready; // @[AXILiteXBar.scala 58:30]
  assign writeBuses_0_clock = clock;
  assign writeBuses_0_reset = reset;
  assign writeBuses_0_io_master_writeAddr_valid = io_masters_0_aw_valid; // @[AXILiteXBar.scala 37:15]
  assign writeBuses_0_io_master_writeAddr_bits_id = 4'h0; // @[AXILiteXBar.scala 37:15]
  assign writeBuses_0_io_master_writeAddr_bits_addr = io_masters_0_aw_bits_addr; // @[AXILiteXBar.scala 37:15]
  assign writeBuses_0_io_master_writeAddr_bits_size = 2'h2; // @[AXILiteXBar.scala 37:15]
  assign writeBuses_0_io_master_writeData_valid = io_masters_0_w_valid; // @[AXILiteXBar.scala 38:14]
  assign writeBuses_0_io_master_writeData_bits_data = io_masters_0_w_bits_data; // @[AXILiteXBar.scala 38:14]
  assign writeBuses_0_io_master_writeData_bits_strb = io_masters_0_w_bits_strb; // @[AXILiteXBar.scala 38:14]
  assign writeBuses_0_io_master_writeData_bits_last = 1'h1; // @[AXILiteXBar.scala 38:14]
  assign writeBuses_0_io_master_writeResp_ready = io_masters_0_b_ready; // @[AXILiteXBar.scala 39:14]
  assign writeBuses_0_io_slave_0_writeAddr_ready = writeMuxes_0_io_in_0_writeAddr_ready; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_0_writeData_ready = writeMuxes_0_io_in_0_writeData_ready; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_0_writeResp_valid = writeMuxes_0_io_in_0_writeResp_valid; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_0_writeResp_bits_id = writeMuxes_0_io_in_0_writeResp_bits_id; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_0_writeResp_bits_resp = writeMuxes_0_io_in_0_writeResp_bits_resp; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_1_writeAddr_ready = writeMuxes_1_io_in_0_writeAddr_ready; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_1_writeData_ready = writeMuxes_1_io_in_0_writeData_ready; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_1_writeResp_valid = writeMuxes_1_io_in_0_writeResp_valid; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_1_writeResp_bits_id = writeMuxes_1_io_in_0_writeResp_bits_id; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_1_writeResp_bits_resp = writeMuxes_1_io_in_0_writeResp_bits_resp; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_2_writeAddr_ready = writeMuxes_2_io_in_0_writeAddr_ready; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_2_writeData_ready = writeMuxes_2_io_in_0_writeData_ready; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_2_writeResp_valid = writeMuxes_2_io_in_0_writeResp_valid; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_2_writeResp_bits_id = writeMuxes_2_io_in_0_writeResp_bits_id; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_0_io_slave_2_writeResp_bits_resp = writeMuxes_2_io_in_0_writeResp_bits_resp; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_clock = clock;
  assign writeBuses_1_reset = reset;
  assign writeBuses_1_io_master_writeAddr_valid = io_masters_1_aw_valid; // @[AXILiteXBar.scala 37:15]
  assign writeBuses_1_io_master_writeAddr_bits_id = io_masters_1_aw_bits_id; // @[AXILiteXBar.scala 37:15]
  assign writeBuses_1_io_master_writeAddr_bits_addr = io_masters_1_aw_bits_addr; // @[AXILiteXBar.scala 37:15]
  assign writeBuses_1_io_master_writeAddr_bits_size = io_masters_1_aw_bits_size; // @[AXILiteXBar.scala 37:15]
  assign writeBuses_1_io_master_writeData_valid = io_masters_1_w_valid; // @[AXILiteXBar.scala 38:14]
  assign writeBuses_1_io_master_writeData_bits_data = io_masters_1_w_bits_data; // @[AXILiteXBar.scala 38:14]
  assign writeBuses_1_io_master_writeData_bits_strb = io_masters_1_w_bits_strb; // @[AXILiteXBar.scala 38:14]
  assign writeBuses_1_io_master_writeData_bits_last = io_masters_1_w_bits_last; // @[AXILiteXBar.scala 38:14]
  assign writeBuses_1_io_master_writeResp_ready = io_masters_1_b_ready; // @[AXILiteXBar.scala 39:14]
  assign writeBuses_1_io_slave_0_writeAddr_ready = writeMuxes_0_io_in_1_writeAddr_ready; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_0_writeData_ready = writeMuxes_0_io_in_1_writeData_ready; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_0_writeResp_valid = writeMuxes_0_io_in_1_writeResp_valid; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_0_writeResp_bits_id = writeMuxes_0_io_in_1_writeResp_bits_id; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_0_writeResp_bits_resp = writeMuxes_0_io_in_1_writeResp_bits_resp; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_1_writeAddr_ready = writeMuxes_1_io_in_1_writeAddr_ready; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_1_writeData_ready = writeMuxes_1_io_in_1_writeData_ready; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_1_writeResp_valid = writeMuxes_1_io_in_1_writeResp_valid; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_1_writeResp_bits_id = writeMuxes_1_io_in_1_writeResp_bits_id; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_1_writeResp_bits_resp = writeMuxes_1_io_in_1_writeResp_bits_resp; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_2_writeAddr_ready = writeMuxes_2_io_in_1_writeAddr_ready; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_2_writeData_ready = writeMuxes_2_io_in_1_writeData_ready; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_2_writeResp_valid = writeMuxes_2_io_in_1_writeResp_valid; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_2_writeResp_bits_id = writeMuxes_2_io_in_1_writeResp_bits_id; // @[AXILiteXBar.scala 62:31]
  assign writeBuses_1_io_slave_2_writeResp_bits_resp = writeMuxes_2_io_in_1_writeResp_bits_resp; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_clock = clock;
  assign writeMuxes_0_reset = reset;
  assign writeMuxes_0_io_out_writeAddr_ready = io_slaves_0_aw_ready; // @[AXILiteXBar.scala 51:16]
  assign writeMuxes_0_io_out_writeData_ready = io_slaves_0_w_ready; // @[AXILiteXBar.scala 52:15]
  assign writeMuxes_0_io_out_writeResp_valid = io_slaves_0_b_valid; // @[AXILiteXBar.scala 53:15]
  assign writeMuxes_0_io_out_writeResp_bits_id = io_slaves_0_b_bits_id; // @[AXILiteXBar.scala 53:15]
  assign writeMuxes_0_io_out_writeResp_bits_resp = io_slaves_0_b_bits_resp; // @[AXILiteXBar.scala 53:15]
  assign writeMuxes_0_io_in_0_writeAddr_valid = writeBuses_0_io_slave_0_writeAddr_valid; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_0_writeAddr_bits_id = writeBuses_0_io_slave_0_writeAddr_bits_id; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_0_writeAddr_bits_addr = writeBuses_0_io_slave_0_writeAddr_bits_addr; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_0_writeAddr_bits_size = writeBuses_0_io_slave_0_writeAddr_bits_size; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_0_writeData_valid = writeBuses_0_io_slave_0_writeData_valid; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_0_writeData_bits_data = writeBuses_0_io_slave_0_writeData_bits_data; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_0_writeData_bits_strb = writeBuses_0_io_slave_0_writeData_bits_strb; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_0_writeData_bits_last = writeBuses_0_io_slave_0_writeData_bits_last; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_0_writeResp_ready = writeBuses_0_io_slave_0_writeResp_ready; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_1_writeAddr_valid = writeBuses_1_io_slave_0_writeAddr_valid; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_1_writeAddr_bits_id = writeBuses_1_io_slave_0_writeAddr_bits_id; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_1_writeAddr_bits_addr = writeBuses_1_io_slave_0_writeAddr_bits_addr; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_1_writeAddr_bits_size = writeBuses_1_io_slave_0_writeAddr_bits_size; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_1_writeData_valid = writeBuses_1_io_slave_0_writeData_valid; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_1_writeData_bits_data = writeBuses_1_io_slave_0_writeData_bits_data; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_1_writeData_bits_strb = writeBuses_1_io_slave_0_writeData_bits_strb; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_1_writeData_bits_last = writeBuses_1_io_slave_0_writeData_bits_last; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_0_io_in_1_writeResp_ready = writeBuses_1_io_slave_0_writeResp_ready; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_clock = clock;
  assign writeMuxes_1_reset = reset;
  assign writeMuxes_1_io_out_writeAddr_ready = io_slaves_1_aw_ready; // @[AXILiteXBar.scala 51:16]
  assign writeMuxes_1_io_out_writeData_ready = io_slaves_1_w_ready; // @[AXILiteXBar.scala 52:15]
  assign writeMuxes_1_io_out_writeResp_valid = io_slaves_1_b_valid; // @[AXILiteXBar.scala 53:15]
  assign writeMuxes_1_io_out_writeResp_bits_id = io_slaves_1_b_bits_id; // @[AXILiteXBar.scala 53:15]
  assign writeMuxes_1_io_out_writeResp_bits_resp = 2'h0; // @[AXILiteXBar.scala 53:15]
  assign writeMuxes_1_io_in_0_writeAddr_valid = writeBuses_0_io_slave_1_writeAddr_valid; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_0_writeAddr_bits_id = writeBuses_0_io_slave_1_writeAddr_bits_id; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_0_writeAddr_bits_addr = writeBuses_0_io_slave_1_writeAddr_bits_addr; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_0_writeAddr_bits_size = writeBuses_0_io_slave_1_writeAddr_bits_size; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_0_writeData_valid = writeBuses_0_io_slave_1_writeData_valid; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_0_writeData_bits_data = writeBuses_0_io_slave_1_writeData_bits_data; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_0_writeData_bits_strb = writeBuses_0_io_slave_1_writeData_bits_strb; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_0_writeData_bits_last = writeBuses_0_io_slave_1_writeData_bits_last; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_0_writeResp_ready = writeBuses_0_io_slave_1_writeResp_ready; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_1_writeAddr_valid = writeBuses_1_io_slave_1_writeAddr_valid; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_1_writeAddr_bits_id = writeBuses_1_io_slave_1_writeAddr_bits_id; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_1_writeAddr_bits_addr = writeBuses_1_io_slave_1_writeAddr_bits_addr; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_1_writeAddr_bits_size = writeBuses_1_io_slave_1_writeAddr_bits_size; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_1_writeData_valid = writeBuses_1_io_slave_1_writeData_valid; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_1_writeData_bits_data = writeBuses_1_io_slave_1_writeData_bits_data; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_1_writeData_bits_strb = writeBuses_1_io_slave_1_writeData_bits_strb; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_1_writeData_bits_last = writeBuses_1_io_slave_1_writeData_bits_last; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_1_io_in_1_writeResp_ready = writeBuses_1_io_slave_1_writeResp_ready; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_clock = clock;
  assign writeMuxes_2_reset = reset;
  assign writeMuxes_2_io_out_writeAddr_ready = io_slaves_2_aw_ready; // @[AXILiteXBar.scala 51:16]
  assign writeMuxes_2_io_out_writeData_ready = io_slaves_2_w_ready; // @[AXILiteXBar.scala 52:15]
  assign writeMuxes_2_io_out_writeResp_valid = io_slaves_2_b_valid; // @[AXILiteXBar.scala 53:15]
  assign writeMuxes_2_io_out_writeResp_bits_id = io_slaves_2_b_bits_id; // @[AXILiteXBar.scala 53:15]
  assign writeMuxes_2_io_out_writeResp_bits_resp = 2'h0; // @[AXILiteXBar.scala 53:15]
  assign writeMuxes_2_io_in_0_writeAddr_valid = writeBuses_0_io_slave_2_writeAddr_valid; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_0_writeAddr_bits_id = writeBuses_0_io_slave_2_writeAddr_bits_id; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_0_writeAddr_bits_addr = writeBuses_0_io_slave_2_writeAddr_bits_addr; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_0_writeAddr_bits_size = writeBuses_0_io_slave_2_writeAddr_bits_size; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_0_writeData_valid = writeBuses_0_io_slave_2_writeData_valid; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_0_writeData_bits_data = writeBuses_0_io_slave_2_writeData_bits_data; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_0_writeData_bits_strb = writeBuses_0_io_slave_2_writeData_bits_strb; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_0_writeData_bits_last = writeBuses_0_io_slave_2_writeData_bits_last; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_0_writeResp_ready = writeBuses_0_io_slave_2_writeResp_ready; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_1_writeAddr_valid = writeBuses_1_io_slave_2_writeAddr_valid; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_1_writeAddr_bits_id = writeBuses_1_io_slave_2_writeAddr_bits_id; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_1_writeAddr_bits_addr = writeBuses_1_io_slave_2_writeAddr_bits_addr; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_1_writeAddr_bits_size = writeBuses_1_io_slave_2_writeAddr_bits_size; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_1_writeData_valid = writeBuses_1_io_slave_2_writeData_valid; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_1_writeData_bits_data = writeBuses_1_io_slave_2_writeData_bits_data; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_1_writeData_bits_strb = writeBuses_1_io_slave_2_writeData_bits_strb; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_1_writeData_bits_last = writeBuses_1_io_slave_2_writeData_bits_last; // @[AXILiteXBar.scala 62:31]
  assign writeMuxes_2_io_in_1_writeResp_ready = writeBuses_1_io_slave_2_writeResp_ready; // @[AXILiteXBar.scala 62:31]
endmodule
module DataMem(
  input         clock,
  input         reset,
  output        io_slave_aw_ready,
  input         io_slave_aw_valid,
  input  [3:0]  io_slave_aw_bits_id,
  input  [31:0] io_slave_aw_bits_addr,
  output        io_slave_w_ready,
  input         io_slave_w_valid,
  input  [31:0] io_slave_w_bits_data,
  input  [3:0]  io_slave_w_bits_strb,
  input         io_slave_w_bits_last,
  input         io_slave_b_ready,
  output        io_slave_b_valid,
  output [3:0]  io_slave_b_bits_id,
  output        io_slave_ar_ready,
  input         io_slave_ar_valid,
  input  [3:0]  io_slave_ar_bits_id,
  input  [31:0] io_slave_ar_bits_addr,
  input         io_slave_r_ready,
  output        io_slave_r_valid,
  output [3:0]  io_slave_r_bits_id,
  output [31:0] io_slave_r_bits_data,
  output        io_slave_r_bits_last,
  input         io_dump
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] memory [0:63]; // @[DataMem.scala 23:19]
  wire  memory_io_slave_r_bits_data_MPORT_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_io_slave_r_bits_data_MPORT_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_io_slave_r_bits_data_MPORT_data; // @[DataMem.scala 23:19]
  wire  memory_writeData_0_MPORT_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_writeData_0_MPORT_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_writeData_0_MPORT_data; // @[DataMem.scala 23:19]
  wire  memory_writeData_1_MPORT_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_writeData_1_MPORT_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_writeData_1_MPORT_data; // @[DataMem.scala 23:19]
  wire  memory_writeData_2_MPORT_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_writeData_2_MPORT_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_writeData_2_MPORT_data; // @[DataMem.scala 23:19]
  wire  memory_writeData_3_MPORT_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_writeData_3_MPORT_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_writeData_3_MPORT_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_1_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_1_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_1_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_2_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_2_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_2_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_3_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_3_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_3_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_4_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_4_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_4_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_5_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_5_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_5_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_6_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_6_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_6_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_7_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_7_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_7_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_8_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_8_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_8_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_9_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_9_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_9_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_10_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_10_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_10_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_11_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_11_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_11_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_12_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_12_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_12_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_13_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_13_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_13_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_14_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_14_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_14_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_15_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_15_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_15_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_16_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_16_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_16_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_17_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_17_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_17_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_18_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_18_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_18_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_19_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_19_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_19_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_20_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_20_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_20_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_21_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_21_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_21_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_22_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_22_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_22_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_23_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_23_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_23_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_24_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_24_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_24_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_25_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_25_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_25_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_26_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_26_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_26_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_27_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_27_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_27_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_28_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_28_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_28_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_29_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_29_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_29_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_30_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_30_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_30_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_31_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_31_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_31_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_32_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_32_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_32_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_33_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_33_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_33_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_34_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_34_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_34_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_35_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_35_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_35_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_36_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_36_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_36_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_37_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_37_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_37_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_38_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_38_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_38_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_39_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_39_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_39_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_40_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_40_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_40_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_41_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_41_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_41_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_42_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_42_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_42_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_43_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_43_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_43_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_44_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_44_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_44_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_45_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_45_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_45_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_46_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_46_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_46_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_47_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_47_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_47_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_48_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_48_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_48_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_49_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_49_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_49_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_50_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_50_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_50_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_51_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_51_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_51_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_52_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_52_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_52_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_53_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_53_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_53_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_54_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_54_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_54_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_55_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_55_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_55_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_56_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_56_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_56_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_57_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_57_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_57_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_58_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_58_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_58_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_59_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_59_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_59_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_60_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_60_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_60_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_61_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_61_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_61_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_62_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_62_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_62_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_63_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_63_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_63_data; // @[DataMem.scala 23:19]
  wire [31:0] memory_MPORT_data; // @[DataMem.scala 23:19]
  wire [5:0] memory_MPORT_addr; // @[DataMem.scala 23:19]
  wire  memory_MPORT_mask; // @[DataMem.scala 23:19]
  wire  memory_MPORT_en; // @[DataMem.scala 23:19]
  wire [31:0] memory_MPORT_1_data; // @[DataMem.scala 23:19]
  wire [5:0] memory_MPORT_1_addr; // @[DataMem.scala 23:19]
  wire  memory_MPORT_1_mask; // @[DataMem.scala 23:19]
  wire  memory_MPORT_1_en; // @[DataMem.scala 23:19]
  reg [3:0] readID; // @[DataMem.scala 28:23]
  reg [31:0] rAddrOffset; // @[DataMem.scala 29:28]
  wire [31:0] _wAddrOffset_T_1 = io_slave_aw_bits_addr - 32'h8000; // @[DataMem.scala 31:29]
  wire [31:0] _wAddrOffset_T_3 = _wAddrOffset_T_1 & 32'hfffffffc; // @[DataMem.scala 31:43]
  wire [31:0] wAddrOffset = {{2'd0}, _wAddrOffset_T_3[31:2]}; // @[DataMem.scala 31:62]
  reg [31:0] writeAddressReg; // @[DataMem.scala 33:32]
  reg [3:0] writeID; // @[DataMem.scala 34:24]
  reg [2:0] writeState; // @[DataMem.scala 37:27]
  reg [1:0] readState; // @[DataMem.scala 38:26]
  reg [7:0] rLatencyCounter; // @[DataMem.scala 39:32]
  reg [7:0] wLatencyCounter; // @[DataMem.scala 40:32]
  reg [3:0] rlength; // @[DataMem.scala 43:31]
  reg [3:0] rburst_counter; // @[DataMem.scala 44:31]
  wire  readLast = rburst_counter == rlength; // @[DataMem.scala 47:50]
  wire [1:0] _GEN_3 = io_slave_r_ready ? 2'h3 : readState; // @[DataMem.scala 91:29 92:19 38:26]
  wire [1:0] _GEN_4 = readLast ? 2'h0 : 2'h2; // @[DataMem.scala 96:21 97:19 99:19]
  wire [1:0] _GEN_5 = 2'h3 == readState ? _GEN_4 : readState; // @[DataMem.scala 74:21 38:26]
  wire  _T_6 = readState == 2'h0; // @[DataMem.scala 104:18]
  wire [31:0] _rAddrOffset_T_1 = io_slave_ar_bits_addr - 32'h8000; // @[DataMem.scala 107:44]
  wire [31:0] _rAddrOffset_T_3 = _rAddrOffset_T_1 & 32'hfffffffc; // @[DataMem.scala 107:58]
  wire [31:0] _rAddrOffset_T_4 = {{2'd0}, _rAddrOffset_T_3[31:2]}; // @[DataMem.scala 107:77]
  wire [7:0] _rlength_T = io_slave_ar_valid ? 8'h0 : {{4'd0}, rlength}; // @[DataMem.scala 111:19]
  wire [7:0] _rLatencyCounter_T_1 = rLatencyCounter + 8'h1; // @[DataMem.scala 116:40]
  wire  _T_9 = readState == 2'h3; // @[DataMem.scala 121:23]
  wire [3:0] _rburst_counter_T_3 = rburst_counter + 4'h1; // @[DataMem.scala 130:22]
  wire [3:0] _rburst_counter_T_5 = io_slave_r_ready & readLast ? 4'h0 : rburst_counter; // @[DataMem.scala 131:10]
  wire [3:0] _rburst_counter_T_6 = io_slave_r_ready & ~readLast ? _rburst_counter_T_3 : _rburst_counter_T_5; // @[DataMem.scala 129:26]
  wire [31:0] _rAddrOffset_T_6 = rAddrOffset + 32'h4; // @[DataMem.scala 136:54]
  wire [31:0] _rAddrOffset_T_7 = io_slave_r_ready ? _rAddrOffset_T_6 : rAddrOffset; // @[DataMem.scala 136:23]
  wire [7:0] _GEN_9 = readState == 2'h3 ? 8'h0 : rLatencyCounter; // @[DataMem.scala 121:34 122:21 39:32]
  wire [31:0] _GEN_14 = readState == 2'h3 ? memory_io_slave_r_bits_data_MPORT_data : 32'h0; // @[DataMem.scala 121:34 125:26 67:24]
  wire [3:0] _GEN_15 = readState == 2'h3 ? readID : 4'h0; // @[DataMem.scala 121:34 126:24 66:22]
  wire [3:0] _GEN_16 = readState == 2'h3 ? _rburst_counter_T_6 : rburst_counter; // @[DataMem.scala 121:34 129:20 44:31]
  wire [31:0] _GEN_17 = readState == 2'h3 ? _rAddrOffset_T_7 : rAddrOffset; // @[DataMem.scala 121:34 136:17 29:28]
  wire  _GEN_20 = readState == 2'h2 ? 1'h0 : _T_9; // @[DataMem.scala 118:38 70:20]
  wire [31:0] _GEN_23 = readState == 2'h2 ? 32'h0 : _GEN_14; // @[DataMem.scala 118:38 67:24]
  wire [3:0] _GEN_24 = readState == 2'h2 ? 4'h0 : _GEN_15; // @[DataMem.scala 118:38 66:22]
  wire  _GEN_29 = readState == 2'h1 ? 1'h0 : _GEN_20; // @[DataMem.scala 115:38 70:20]
  wire [31:0] _GEN_32 = readState == 2'h1 ? 32'h0 : _GEN_23; // @[DataMem.scala 115:38 67:24]
  wire [3:0] _GEN_33 = readState == 2'h1 ? 4'h0 : _GEN_24; // @[DataMem.scala 115:38 66:22]
  wire [7:0] _GEN_40 = readState == 2'h0 ? _rlength_T : {{4'd0}, rlength}; // @[DataMem.scala 104:29 111:13 43:31]
  wire [2:0] _GEN_49 = io_slave_w_bits_last ? 3'h3 : 3'h5; // @[DataMem.scala 147:56 148:22]
  wire [2:0] _GEN_50 = io_slave_aw_valid ? 3'h4 : writeState; // @[DataMem.scala 156:36 157:20 37:27]
  wire [2:0] _GEN_54 = io_slave_w_valid ? _GEN_49 : writeState; // @[DataMem.scala 161:30 37:27]
  wire  _T_22 = wLatencyCounter == 8'h0; // @[DataMem.scala 172:28]
  wire [2:0] _GEN_55 = _T_22 ? 3'h5 : writeState; // @[DataMem.scala 174:54 175:20 37:27]
  wire [2:0] _GEN_56 = wLatencyCounter == 8'h0 & io_slave_w_bits_last ? 3'h3 : _GEN_55; // @[DataMem.scala 172:71 173:20]
  wire [2:0] _GEN_57 = io_slave_b_ready ? 3'h1 : writeState; // @[DataMem.scala 182:30 183:20 37:27]
  wire [2:0] _GEN_58 = 3'h3 == writeState ? _GEN_57 : writeState; // @[DataMem.scala 140:22 37:27]
  wire [2:0] _GEN_59 = 3'h5 == writeState ? 3'h1 : _GEN_58; // @[DataMem.scala 140:22 179:18]
  wire [2:0] _GEN_60 = 3'h2 == writeState ? _GEN_56 : _GEN_59; // @[DataMem.scala 140:22]
  wire [7:0] writeData_0 = io_slave_w_bits_strb[0] ? io_slave_w_bits_data[7:0] : memory_writeData_0_MPORT_data[7:0]; // @[DataMem.scala 190:43 191:20 193:20]
  wire [7:0] writeData_1 = io_slave_w_bits_strb[1] ? io_slave_w_bits_data[15:8] : memory_writeData_1_MPORT_data[15:8]; // @[DataMem.scala 190:43 191:20 193:20]
  wire [7:0] writeData_2 = io_slave_w_bits_strb[2] ? io_slave_w_bits_data[23:16] : memory_writeData_2_MPORT_data[23:16]; // @[DataMem.scala 190:43 191:20 193:20]
  wire [7:0] writeData_3 = io_slave_w_bits_strb[3] ? io_slave_w_bits_data[31:24] : memory_writeData_3_MPORT_data[31:24]; // @[DataMem.scala 190:43 191:20 193:20]
  wire  _T_35 = writeState == 3'h0; // @[DataMem.scala 197:19]
  wire  _T_36 = writeState == 3'h1; // @[DataMem.scala 203:24]
  wire [15:0] lo = {writeData_1,writeData_0}; // @[DataMem.scala 207:46]
  wire [15:0] hi = {writeData_3,writeData_2}; // @[DataMem.scala 207:46]
  wire [31:0] _GEN_80 = io_slave_aw_valid ? wAddrOffset : writeAddressReg; // @[DataMem.scala 211:34 212:23 33:32]
  wire [3:0] _GEN_81 = io_slave_aw_valid ? io_slave_aw_bits_id : writeID; // @[DataMem.scala 211:34 213:15 34:24]
  wire  _T_40 = writeState == 3'h4; // @[DataMem.scala 229:24]
  wire [7:0] _wLatencyCounter_T_1 = wLatencyCounter + 8'h1; // @[DataMem.scala 241:40]
  wire  _T_45 = writeState == 3'h3; // @[DataMem.scala 252:24]
  wire [7:0] _GEN_91 = writeState == 3'h3 ? 8'h0 : wLatencyCounter; // @[DataMem.scala 252:37 253:21 40:32]
  wire [3:0] _GEN_93 = writeState == 3'h3 ? writeID : 4'h0; // @[DataMem.scala 252:37 257:24 58:22]
  wire [7:0] _GEN_96 = writeState == 3'h5 ? 8'h0 : _GEN_91; // @[DataMem.scala 243:38 244:21]
  wire [3:0] _GEN_98 = writeState == 3'h5 ? writeID : _GEN_93; // @[DataMem.scala 243:38 248:24]
  wire  _GEN_99 = writeState == 3'h5 ? 1'h0 : _T_45; // @[DataMem.scala 243:38 60:20]
  wire [7:0] _GEN_101 = writeState == 3'h2 ? _wLatencyCounter_T_1 : _GEN_96; // @[DataMem.scala 240:39 241:21]
  wire [3:0] _GEN_103 = writeState == 3'h2 ? 4'h0 : _GEN_98; // @[DataMem.scala 240:39 58:22]
  wire  _GEN_104 = writeState == 3'h2 ? 1'h0 : _GEN_99; // @[DataMem.scala 240:39 60:20]
  wire  _GEN_108 = writeState == 3'h4 ? 1'h0 : _GEN_104; // @[DataMem.scala 229:39 233:22]
  wire  _GEN_111 = writeState == 3'h4 & io_slave_w_valid; // @[DataMem.scala 229:39 23:19]
  wire [3:0] _GEN_115 = writeState == 3'h4 ? 4'h0 : _GEN_103; // @[DataMem.scala 229:39 58:22]
  wire  _GEN_118 = writeState == 3'h1 | _T_40; // @[DataMem.scala 203:36 205:22]
  wire  _GEN_121 = writeState == 3'h1 & io_slave_w_valid; // @[DataMem.scala 203:36 23:19]
  wire  _GEN_127 = writeState == 3'h1 ? 1'h0 : _GEN_108; // @[DataMem.scala 203:36 216:22]
  wire  _GEN_131 = writeState == 3'h1 ? 1'h0 : _GEN_111; // @[DataMem.scala 203:36 23:19]
  wire [3:0] _GEN_135 = writeState == 3'h1 ? 4'h0 : _GEN_115; // @[DataMem.scala 203:36 58:22]
  wire  _T_47 = ~reset; // @[DataMem.scala 265:11]
  wire [7:0] _GEN_223 = reset ? 8'h0 : _GEN_40; // @[DataMem.scala 43:{31,31}]
  assign memory_io_slave_r_bits_data_MPORT_en = _T_6 ? 1'h0 : _GEN_29;
  assign memory_io_slave_r_bits_data_MPORT_addr = rAddrOffset[5:0];
  assign memory_io_slave_r_bits_data_MPORT_data = memory[memory_io_slave_r_bits_data_MPORT_addr]; // @[DataMem.scala 23:19]
  assign memory_writeData_0_MPORT_en = io_slave_w_bits_strb[0] ? 1'h0 : 1'h1;
  assign memory_writeData_0_MPORT_addr = wAddrOffset[5:0];
  assign memory_writeData_0_MPORT_data = memory[memory_writeData_0_MPORT_addr]; // @[DataMem.scala 23:19]
  assign memory_writeData_1_MPORT_en = io_slave_w_bits_strb[1] ? 1'h0 : 1'h1;
  assign memory_writeData_1_MPORT_addr = wAddrOffset[5:0];
  assign memory_writeData_1_MPORT_data = memory[memory_writeData_1_MPORT_addr]; // @[DataMem.scala 23:19]
  assign memory_writeData_2_MPORT_en = io_slave_w_bits_strb[2] ? 1'h0 : 1'h1;
  assign memory_writeData_2_MPORT_addr = wAddrOffset[5:0];
  assign memory_writeData_2_MPORT_data = memory[memory_writeData_2_MPORT_addr]; // @[DataMem.scala 23:19]
  assign memory_writeData_3_MPORT_en = io_slave_w_bits_strb[3] ? 1'h0 : 1'h1;
  assign memory_writeData_3_MPORT_addr = wAddrOffset[5:0];
  assign memory_writeData_3_MPORT_data = memory[memory_writeData_3_MPORT_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_en = io_dump;
  assign memory_data_MPORT_addr = 6'h0;
  assign memory_data_MPORT_data = memory[memory_data_MPORT_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_1_en = io_dump;
  assign memory_data_MPORT_1_addr = 6'h1;
  assign memory_data_MPORT_1_data = memory[memory_data_MPORT_1_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_2_en = io_dump;
  assign memory_data_MPORT_2_addr = 6'h2;
  assign memory_data_MPORT_2_data = memory[memory_data_MPORT_2_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_3_en = io_dump;
  assign memory_data_MPORT_3_addr = 6'h3;
  assign memory_data_MPORT_3_data = memory[memory_data_MPORT_3_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_4_en = io_dump;
  assign memory_data_MPORT_4_addr = 6'h4;
  assign memory_data_MPORT_4_data = memory[memory_data_MPORT_4_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_5_en = io_dump;
  assign memory_data_MPORT_5_addr = 6'h5;
  assign memory_data_MPORT_5_data = memory[memory_data_MPORT_5_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_6_en = io_dump;
  assign memory_data_MPORT_6_addr = 6'h6;
  assign memory_data_MPORT_6_data = memory[memory_data_MPORT_6_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_7_en = io_dump;
  assign memory_data_MPORT_7_addr = 6'h7;
  assign memory_data_MPORT_7_data = memory[memory_data_MPORT_7_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_8_en = io_dump;
  assign memory_data_MPORT_8_addr = 6'h8;
  assign memory_data_MPORT_8_data = memory[memory_data_MPORT_8_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_9_en = io_dump;
  assign memory_data_MPORT_9_addr = 6'h9;
  assign memory_data_MPORT_9_data = memory[memory_data_MPORT_9_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_10_en = io_dump;
  assign memory_data_MPORT_10_addr = 6'ha;
  assign memory_data_MPORT_10_data = memory[memory_data_MPORT_10_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_11_en = io_dump;
  assign memory_data_MPORT_11_addr = 6'hb;
  assign memory_data_MPORT_11_data = memory[memory_data_MPORT_11_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_12_en = io_dump;
  assign memory_data_MPORT_12_addr = 6'hc;
  assign memory_data_MPORT_12_data = memory[memory_data_MPORT_12_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_13_en = io_dump;
  assign memory_data_MPORT_13_addr = 6'hd;
  assign memory_data_MPORT_13_data = memory[memory_data_MPORT_13_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_14_en = io_dump;
  assign memory_data_MPORT_14_addr = 6'he;
  assign memory_data_MPORT_14_data = memory[memory_data_MPORT_14_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_15_en = io_dump;
  assign memory_data_MPORT_15_addr = 6'hf;
  assign memory_data_MPORT_15_data = memory[memory_data_MPORT_15_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_16_en = io_dump;
  assign memory_data_MPORT_16_addr = 6'h10;
  assign memory_data_MPORT_16_data = memory[memory_data_MPORT_16_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_17_en = io_dump;
  assign memory_data_MPORT_17_addr = 6'h11;
  assign memory_data_MPORT_17_data = memory[memory_data_MPORT_17_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_18_en = io_dump;
  assign memory_data_MPORT_18_addr = 6'h12;
  assign memory_data_MPORT_18_data = memory[memory_data_MPORT_18_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_19_en = io_dump;
  assign memory_data_MPORT_19_addr = 6'h13;
  assign memory_data_MPORT_19_data = memory[memory_data_MPORT_19_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_20_en = io_dump;
  assign memory_data_MPORT_20_addr = 6'h14;
  assign memory_data_MPORT_20_data = memory[memory_data_MPORT_20_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_21_en = io_dump;
  assign memory_data_MPORT_21_addr = 6'h15;
  assign memory_data_MPORT_21_data = memory[memory_data_MPORT_21_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_22_en = io_dump;
  assign memory_data_MPORT_22_addr = 6'h16;
  assign memory_data_MPORT_22_data = memory[memory_data_MPORT_22_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_23_en = io_dump;
  assign memory_data_MPORT_23_addr = 6'h17;
  assign memory_data_MPORT_23_data = memory[memory_data_MPORT_23_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_24_en = io_dump;
  assign memory_data_MPORT_24_addr = 6'h18;
  assign memory_data_MPORT_24_data = memory[memory_data_MPORT_24_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_25_en = io_dump;
  assign memory_data_MPORT_25_addr = 6'h19;
  assign memory_data_MPORT_25_data = memory[memory_data_MPORT_25_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_26_en = io_dump;
  assign memory_data_MPORT_26_addr = 6'h1a;
  assign memory_data_MPORT_26_data = memory[memory_data_MPORT_26_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_27_en = io_dump;
  assign memory_data_MPORT_27_addr = 6'h1b;
  assign memory_data_MPORT_27_data = memory[memory_data_MPORT_27_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_28_en = io_dump;
  assign memory_data_MPORT_28_addr = 6'h1c;
  assign memory_data_MPORT_28_data = memory[memory_data_MPORT_28_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_29_en = io_dump;
  assign memory_data_MPORT_29_addr = 6'h1d;
  assign memory_data_MPORT_29_data = memory[memory_data_MPORT_29_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_30_en = io_dump;
  assign memory_data_MPORT_30_addr = 6'h1e;
  assign memory_data_MPORT_30_data = memory[memory_data_MPORT_30_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_31_en = io_dump;
  assign memory_data_MPORT_31_addr = 6'h1f;
  assign memory_data_MPORT_31_data = memory[memory_data_MPORT_31_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_32_en = io_dump;
  assign memory_data_MPORT_32_addr = 6'h20;
  assign memory_data_MPORT_32_data = memory[memory_data_MPORT_32_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_33_en = io_dump;
  assign memory_data_MPORT_33_addr = 6'h21;
  assign memory_data_MPORT_33_data = memory[memory_data_MPORT_33_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_34_en = io_dump;
  assign memory_data_MPORT_34_addr = 6'h22;
  assign memory_data_MPORT_34_data = memory[memory_data_MPORT_34_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_35_en = io_dump;
  assign memory_data_MPORT_35_addr = 6'h23;
  assign memory_data_MPORT_35_data = memory[memory_data_MPORT_35_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_36_en = io_dump;
  assign memory_data_MPORT_36_addr = 6'h24;
  assign memory_data_MPORT_36_data = memory[memory_data_MPORT_36_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_37_en = io_dump;
  assign memory_data_MPORT_37_addr = 6'h25;
  assign memory_data_MPORT_37_data = memory[memory_data_MPORT_37_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_38_en = io_dump;
  assign memory_data_MPORT_38_addr = 6'h26;
  assign memory_data_MPORT_38_data = memory[memory_data_MPORT_38_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_39_en = io_dump;
  assign memory_data_MPORT_39_addr = 6'h27;
  assign memory_data_MPORT_39_data = memory[memory_data_MPORT_39_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_40_en = io_dump;
  assign memory_data_MPORT_40_addr = 6'h28;
  assign memory_data_MPORT_40_data = memory[memory_data_MPORT_40_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_41_en = io_dump;
  assign memory_data_MPORT_41_addr = 6'h29;
  assign memory_data_MPORT_41_data = memory[memory_data_MPORT_41_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_42_en = io_dump;
  assign memory_data_MPORT_42_addr = 6'h2a;
  assign memory_data_MPORT_42_data = memory[memory_data_MPORT_42_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_43_en = io_dump;
  assign memory_data_MPORT_43_addr = 6'h2b;
  assign memory_data_MPORT_43_data = memory[memory_data_MPORT_43_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_44_en = io_dump;
  assign memory_data_MPORT_44_addr = 6'h2c;
  assign memory_data_MPORT_44_data = memory[memory_data_MPORT_44_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_45_en = io_dump;
  assign memory_data_MPORT_45_addr = 6'h2d;
  assign memory_data_MPORT_45_data = memory[memory_data_MPORT_45_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_46_en = io_dump;
  assign memory_data_MPORT_46_addr = 6'h2e;
  assign memory_data_MPORT_46_data = memory[memory_data_MPORT_46_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_47_en = io_dump;
  assign memory_data_MPORT_47_addr = 6'h2f;
  assign memory_data_MPORT_47_data = memory[memory_data_MPORT_47_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_48_en = io_dump;
  assign memory_data_MPORT_48_addr = 6'h30;
  assign memory_data_MPORT_48_data = memory[memory_data_MPORT_48_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_49_en = io_dump;
  assign memory_data_MPORT_49_addr = 6'h31;
  assign memory_data_MPORT_49_data = memory[memory_data_MPORT_49_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_50_en = io_dump;
  assign memory_data_MPORT_50_addr = 6'h32;
  assign memory_data_MPORT_50_data = memory[memory_data_MPORT_50_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_51_en = io_dump;
  assign memory_data_MPORT_51_addr = 6'h33;
  assign memory_data_MPORT_51_data = memory[memory_data_MPORT_51_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_52_en = io_dump;
  assign memory_data_MPORT_52_addr = 6'h34;
  assign memory_data_MPORT_52_data = memory[memory_data_MPORT_52_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_53_en = io_dump;
  assign memory_data_MPORT_53_addr = 6'h35;
  assign memory_data_MPORT_53_data = memory[memory_data_MPORT_53_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_54_en = io_dump;
  assign memory_data_MPORT_54_addr = 6'h36;
  assign memory_data_MPORT_54_data = memory[memory_data_MPORT_54_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_55_en = io_dump;
  assign memory_data_MPORT_55_addr = 6'h37;
  assign memory_data_MPORT_55_data = memory[memory_data_MPORT_55_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_56_en = io_dump;
  assign memory_data_MPORT_56_addr = 6'h38;
  assign memory_data_MPORT_56_data = memory[memory_data_MPORT_56_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_57_en = io_dump;
  assign memory_data_MPORT_57_addr = 6'h39;
  assign memory_data_MPORT_57_data = memory[memory_data_MPORT_57_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_58_en = io_dump;
  assign memory_data_MPORT_58_addr = 6'h3a;
  assign memory_data_MPORT_58_data = memory[memory_data_MPORT_58_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_59_en = io_dump;
  assign memory_data_MPORT_59_addr = 6'h3b;
  assign memory_data_MPORT_59_data = memory[memory_data_MPORT_59_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_60_en = io_dump;
  assign memory_data_MPORT_60_addr = 6'h3c;
  assign memory_data_MPORT_60_data = memory[memory_data_MPORT_60_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_61_en = io_dump;
  assign memory_data_MPORT_61_addr = 6'h3d;
  assign memory_data_MPORT_61_data = memory[memory_data_MPORT_61_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_62_en = io_dump;
  assign memory_data_MPORT_62_addr = 6'h3e;
  assign memory_data_MPORT_62_data = memory[memory_data_MPORT_62_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_63_en = io_dump;
  assign memory_data_MPORT_63_addr = 6'h3f;
  assign memory_data_MPORT_63_data = memory[memory_data_MPORT_63_addr]; // @[DataMem.scala 23:19]
  assign memory_MPORT_data = {hi,lo};
  assign memory_MPORT_addr = wAddrOffset[5:0];
  assign memory_MPORT_mask = 1'h1;
  assign memory_MPORT_en = _T_35 ? 1'h0 : _GEN_121;
  assign memory_MPORT_1_data = {hi,lo};
  assign memory_MPORT_1_addr = writeAddressReg[5:0];
  assign memory_MPORT_1_mask = 1'h1;
  assign memory_MPORT_1_en = _T_35 ? 1'h0 : _GEN_131;
  assign io_slave_aw_ready = writeState == 3'h0 ? 1'h0 : _T_36; // @[DataMem.scala 197:30 198:23]
  assign io_slave_w_ready = writeState == 3'h0 ? 1'h0 : _GEN_118; // @[DataMem.scala 197:30 199:22]
  assign io_slave_b_valid = writeState == 3'h0 ? 1'h0 : _GEN_127; // @[DataMem.scala 197:30 201:22]
  assign io_slave_b_bits_id = writeState == 3'h0 ? 4'h0 : _GEN_135; // @[DataMem.scala 197:30 58:22]
  assign io_slave_ar_ready = readState == 2'h0; // @[DataMem.scala 104:18]
  assign io_slave_r_valid = readState == 2'h0 ? 1'h0 : _GEN_29; // @[DataMem.scala 104:29 106:22]
  assign io_slave_r_bits_id = readState == 2'h0 ? 4'h0 : _GEN_33; // @[DataMem.scala 104:29 66:22]
  assign io_slave_r_bits_data = readState == 2'h0 ? 32'h0 : _GEN_32; // @[DataMem.scala 104:29 67:24]
  assign io_slave_r_bits_last = rburst_counter == rlength; // @[DataMem.scala 47:50]
  always @(posedge clock) begin
    if (memory_MPORT_en & memory_MPORT_mask) begin
      memory[memory_MPORT_addr] <= memory_MPORT_data; // @[DataMem.scala 23:19]
    end
    if (memory_MPORT_1_en & memory_MPORT_1_mask) begin
      memory[memory_MPORT_1_addr] <= memory_MPORT_1_data; // @[DataMem.scala 23:19]
    end
    if (reset) begin // @[DataMem.scala 28:23]
      readID <= 4'h0; // @[DataMem.scala 28:23]
    end else if (readState == 2'h0) begin // @[DataMem.scala 104:29]
      readID <= io_slave_ar_bits_id; // @[DataMem.scala 108:12]
    end
    if (reset) begin // @[DataMem.scala 29:28]
      rAddrOffset <= 32'h0; // @[DataMem.scala 29:28]
    end else if (readState == 2'h0) begin // @[DataMem.scala 104:29]
      rAddrOffset <= _rAddrOffset_T_4; // @[DataMem.scala 107:17]
    end else if (!(readState == 2'h1)) begin // @[DataMem.scala 115:38]
      if (!(readState == 2'h2)) begin // @[DataMem.scala 118:38]
        rAddrOffset <= _GEN_17;
      end
    end
    if (reset) begin // @[DataMem.scala 33:32]
      writeAddressReg <= 32'h0; // @[DataMem.scala 33:32]
    end else if (!(writeState == 3'h0)) begin // @[DataMem.scala 197:30]
      if (writeState == 3'h1) begin // @[DataMem.scala 203:36]
        if (io_slave_w_valid) begin // @[DataMem.scala 206:28]
          writeAddressReg <= wAddrOffset; // @[DataMem.scala 208:23]
        end else begin
          writeAddressReg <= _GEN_80;
        end
      end
    end
    if (reset) begin // @[DataMem.scala 34:24]
      writeID <= 4'h0; // @[DataMem.scala 34:24]
    end else if (!(writeState == 3'h0)) begin // @[DataMem.scala 197:30]
      if (writeState == 3'h1) begin // @[DataMem.scala 203:36]
        if (io_slave_w_valid) begin // @[DataMem.scala 206:28]
          writeID <= io_slave_aw_bits_id; // @[DataMem.scala 209:15]
        end else begin
          writeID <= _GEN_81;
        end
      end
    end
    if (reset) begin // @[DataMem.scala 37:27]
      writeState <= 3'h0; // @[DataMem.scala 37:27]
    end else if (3'h0 == writeState) begin // @[DataMem.scala 140:22]
      writeState <= 3'h1; // @[DataMem.scala 142:18]
    end else if (3'h1 == writeState) begin // @[DataMem.scala 140:22]
      if (io_slave_w_valid | io_slave_aw_valid & io_slave_w_valid) begin // @[DataMem.scala 146:73]
        writeState <= _GEN_49;
      end else begin
        writeState <= _GEN_50;
      end
    end else if (3'h4 == writeState) begin // @[DataMem.scala 140:22]
      writeState <= _GEN_54;
    end else begin
      writeState <= _GEN_60;
    end
    if (reset) begin // @[DataMem.scala 38:26]
      readState <= 2'h0; // @[DataMem.scala 38:26]
    end else if (2'h0 == readState) begin // @[DataMem.scala 74:21]
      if (io_slave_ar_valid) begin // @[DataMem.scala 76:31]
        readState <= 2'h2;
      end
    end else if (2'h1 == readState) begin // @[DataMem.scala 74:21]
      if (rLatencyCounter == 8'h0) begin // @[DataMem.scala 86:49]
        readState <= 2'h2; // @[DataMem.scala 87:19]
      end
    end else if (2'h2 == readState) begin // @[DataMem.scala 74:21]
      readState <= _GEN_3;
    end else begin
      readState <= _GEN_5;
    end
    if (reset) begin // @[DataMem.scala 39:32]
      rLatencyCounter <= 8'h0; // @[DataMem.scala 39:32]
    end else if (!(readState == 2'h0)) begin // @[DataMem.scala 104:29]
      if (readState == 2'h1) begin // @[DataMem.scala 115:38]
        rLatencyCounter <= _rLatencyCounter_T_1; // @[DataMem.scala 116:21]
      end else if (!(readState == 2'h2)) begin // @[DataMem.scala 118:38]
        rLatencyCounter <= _GEN_9;
      end
    end
    if (reset) begin // @[DataMem.scala 40:32]
      wLatencyCounter <= 8'h0; // @[DataMem.scala 40:32]
    end else if (!(writeState == 3'h0)) begin // @[DataMem.scala 197:30]
      if (!(writeState == 3'h1)) begin // @[DataMem.scala 203:36]
        if (!(writeState == 3'h4)) begin // @[DataMem.scala 229:39]
          wLatencyCounter <= _GEN_101;
        end
      end
    end
    rlength <= _GEN_223[3:0]; // @[DataMem.scala 43:{31,31}]
    if (reset) begin // @[DataMem.scala 44:31]
      rburst_counter <= 4'h0; // @[DataMem.scala 44:31]
    end else if (!(readState == 2'h0)) begin // @[DataMem.scala 104:29]
      if (!(readState == 2'h1)) begin // @[DataMem.scala 115:38]
        if (!(readState == 2'h2)) begin // @[DataMem.scala 118:38]
          rburst_counter <= _GEN_16;
        end
      end
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & ~reset) begin
          $fwrite(32'h80000002,"\t\t======== Data Memory Dump ========\n"); // @[DataMem.scala 265:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tFrom base address 32768\n"); // @[DataMem.scala 266:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[0] (address = %x) = 0x%x (%d)\n",16'h8000,memory_data_MPORT_data,
            memory_data_MPORT_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[1] (address = %x) = 0x%x (%d)\n",16'h8004,memory_data_MPORT_1_data,
            memory_data_MPORT_1_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[2] (address = %x) = 0x%x (%d)\n",16'h8008,memory_data_MPORT_2_data,
            memory_data_MPORT_2_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[3] (address = %x) = 0x%x (%d)\n",16'h800c,memory_data_MPORT_3_data,
            memory_data_MPORT_3_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[4] (address = %x) = 0x%x (%d)\n",16'h8010,memory_data_MPORT_4_data,
            memory_data_MPORT_4_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[5] (address = %x) = 0x%x (%d)\n",16'h8014,memory_data_MPORT_5_data,
            memory_data_MPORT_5_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[6] (address = %x) = 0x%x (%d)\n",16'h8018,memory_data_MPORT_6_data,
            memory_data_MPORT_6_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[7] (address = %x) = 0x%x (%d)\n",16'h801c,memory_data_MPORT_7_data,
            memory_data_MPORT_7_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[8] (address = %x) = 0x%x (%d)\n",16'h8020,memory_data_MPORT_8_data,
            memory_data_MPORT_8_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[9] (address = %x) = 0x%x (%d)\n",16'h8024,memory_data_MPORT_9_data,
            memory_data_MPORT_9_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[10] (address = %x) = 0x%x (%d)\n",16'h8028,memory_data_MPORT_10_data,
            memory_data_MPORT_10_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[11] (address = %x) = 0x%x (%d)\n",16'h802c,memory_data_MPORT_11_data,
            memory_data_MPORT_11_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[12] (address = %x) = 0x%x (%d)\n",16'h8030,memory_data_MPORT_12_data,
            memory_data_MPORT_12_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[13] (address = %x) = 0x%x (%d)\n",16'h8034,memory_data_MPORT_13_data,
            memory_data_MPORT_13_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[14] (address = %x) = 0x%x (%d)\n",16'h8038,memory_data_MPORT_14_data,
            memory_data_MPORT_14_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[15] (address = %x) = 0x%x (%d)\n",16'h803c,memory_data_MPORT_15_data,
            memory_data_MPORT_15_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[16] (address = %x) = 0x%x (%d)\n",16'h8040,memory_data_MPORT_16_data,
            memory_data_MPORT_16_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[17] (address = %x) = 0x%x (%d)\n",16'h8044,memory_data_MPORT_17_data,
            memory_data_MPORT_17_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[18] (address = %x) = 0x%x (%d)\n",16'h8048,memory_data_MPORT_18_data,
            memory_data_MPORT_18_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[19] (address = %x) = 0x%x (%d)\n",16'h804c,memory_data_MPORT_19_data,
            memory_data_MPORT_19_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[20] (address = %x) = 0x%x (%d)\n",16'h8050,memory_data_MPORT_20_data,
            memory_data_MPORT_20_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[21] (address = %x) = 0x%x (%d)\n",16'h8054,memory_data_MPORT_21_data,
            memory_data_MPORT_21_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[22] (address = %x) = 0x%x (%d)\n",16'h8058,memory_data_MPORT_22_data,
            memory_data_MPORT_22_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[23] (address = %x) = 0x%x (%d)\n",16'h805c,memory_data_MPORT_23_data,
            memory_data_MPORT_23_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[24] (address = %x) = 0x%x (%d)\n",16'h8060,memory_data_MPORT_24_data,
            memory_data_MPORT_24_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[25] (address = %x) = 0x%x (%d)\n",16'h8064,memory_data_MPORT_25_data,
            memory_data_MPORT_25_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[26] (address = %x) = 0x%x (%d)\n",16'h8068,memory_data_MPORT_26_data,
            memory_data_MPORT_26_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[27] (address = %x) = 0x%x (%d)\n",16'h806c,memory_data_MPORT_27_data,
            memory_data_MPORT_27_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[28] (address = %x) = 0x%x (%d)\n",16'h8070,memory_data_MPORT_28_data,
            memory_data_MPORT_28_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[29] (address = %x) = 0x%x (%d)\n",16'h8074,memory_data_MPORT_29_data,
            memory_data_MPORT_29_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[30] (address = %x) = 0x%x (%d)\n",16'h8078,memory_data_MPORT_30_data,
            memory_data_MPORT_30_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[31] (address = %x) = 0x%x (%d)\n",16'h807c,memory_data_MPORT_31_data,
            memory_data_MPORT_31_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[32] (address = %x) = 0x%x (%d)\n",16'h8080,memory_data_MPORT_32_data,
            memory_data_MPORT_32_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[33] (address = %x) = 0x%x (%d)\n",16'h8084,memory_data_MPORT_33_data,
            memory_data_MPORT_33_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[34] (address = %x) = 0x%x (%d)\n",16'h8088,memory_data_MPORT_34_data,
            memory_data_MPORT_34_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[35] (address = %x) = 0x%x (%d)\n",16'h808c,memory_data_MPORT_35_data,
            memory_data_MPORT_35_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[36] (address = %x) = 0x%x (%d)\n",16'h8090,memory_data_MPORT_36_data,
            memory_data_MPORT_36_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[37] (address = %x) = 0x%x (%d)\n",16'h8094,memory_data_MPORT_37_data,
            memory_data_MPORT_37_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[38] (address = %x) = 0x%x (%d)\n",16'h8098,memory_data_MPORT_38_data,
            memory_data_MPORT_38_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[39] (address = %x) = 0x%x (%d)\n",16'h809c,memory_data_MPORT_39_data,
            memory_data_MPORT_39_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[40] (address = %x) = 0x%x (%d)\n",16'h80a0,memory_data_MPORT_40_data,
            memory_data_MPORT_40_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[41] (address = %x) = 0x%x (%d)\n",16'h80a4,memory_data_MPORT_41_data,
            memory_data_MPORT_41_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[42] (address = %x) = 0x%x (%d)\n",16'h80a8,memory_data_MPORT_42_data,
            memory_data_MPORT_42_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[43] (address = %x) = 0x%x (%d)\n",16'h80ac,memory_data_MPORT_43_data,
            memory_data_MPORT_43_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[44] (address = %x) = 0x%x (%d)\n",16'h80b0,memory_data_MPORT_44_data,
            memory_data_MPORT_44_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[45] (address = %x) = 0x%x (%d)\n",16'h80b4,memory_data_MPORT_45_data,
            memory_data_MPORT_45_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[46] (address = %x) = 0x%x (%d)\n",16'h80b8,memory_data_MPORT_46_data,
            memory_data_MPORT_46_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[47] (address = %x) = 0x%x (%d)\n",16'h80bc,memory_data_MPORT_47_data,
            memory_data_MPORT_47_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[48] (address = %x) = 0x%x (%d)\n",16'h80c0,memory_data_MPORT_48_data,
            memory_data_MPORT_48_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[49] (address = %x) = 0x%x (%d)\n",16'h80c4,memory_data_MPORT_49_data,
            memory_data_MPORT_49_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[50] (address = %x) = 0x%x (%d)\n",16'h80c8,memory_data_MPORT_50_data,
            memory_data_MPORT_50_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[51] (address = %x) = 0x%x (%d)\n",16'h80cc,memory_data_MPORT_51_data,
            memory_data_MPORT_51_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[52] (address = %x) = 0x%x (%d)\n",16'h80d0,memory_data_MPORT_52_data,
            memory_data_MPORT_52_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[53] (address = %x) = 0x%x (%d)\n",16'h80d4,memory_data_MPORT_53_data,
            memory_data_MPORT_53_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[54] (address = %x) = 0x%x (%d)\n",16'h80d8,memory_data_MPORT_54_data,
            memory_data_MPORT_54_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[55] (address = %x) = 0x%x (%d)\n",16'h80dc,memory_data_MPORT_55_data,
            memory_data_MPORT_55_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[56] (address = %x) = 0x%x (%d)\n",16'h80e0,memory_data_MPORT_56_data,
            memory_data_MPORT_56_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[57] (address = %x) = 0x%x (%d)\n",16'h80e4,memory_data_MPORT_57_data,
            memory_data_MPORT_57_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[58] (address = %x) = 0x%x (%d)\n",16'h80e8,memory_data_MPORT_58_data,
            memory_data_MPORT_58_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[59] (address = %x) = 0x%x (%d)\n",16'h80ec,memory_data_MPORT_59_data,
            memory_data_MPORT_59_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[60] (address = %x) = 0x%x (%d)\n",16'h80f0,memory_data_MPORT_60_data,
            memory_data_MPORT_60_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[61] (address = %x) = 0x%x (%d)\n",16'h80f4,memory_data_MPORT_61_data,
            memory_data_MPORT_61_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[62] (address = %x) = 0x%x (%d)\n",16'h80f8,memory_data_MPORT_62_data,
            memory_data_MPORT_62_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\t\tDataMem[63] (address = %x) = 0x%x (%d)\n",16'h80fc,memory_data_MPORT_63_data,
            memory_data_MPORT_63_data); // @[DataMem.scala 270:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_dump & _T_47) begin
          $fwrite(32'h80000002,"\n"); // @[DataMem.scala 274:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
  integer initvar;
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  readID = _RAND_0[3:0];
  _RAND_1 = {1{`RANDOM}};
  rAddrOffset = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  writeAddressReg = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  writeID = _RAND_3[3:0];
  _RAND_4 = {1{`RANDOM}};
  writeState = _RAND_4[2:0];
  _RAND_5 = {1{`RANDOM}};
  readState = _RAND_5[1:0];
  _RAND_6 = {1{`RANDOM}};
  rLatencyCounter = _RAND_6[7:0];
  _RAND_7 = {1{`RANDOM}};
  wLatencyCounter = _RAND_7[7:0];
  _RAND_8 = {1{`RANDOM}};
  rlength = _RAND_8[3:0];
  _RAND_9 = {1{`RANDOM}};
  rburst_counter = _RAND_9[3:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
  $readmemh("./src/main/resource/data0.hex", memory);
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module DataMem_1(
  input         clock,
  input         reset,
  output        io_slave_aw_ready,
  input         io_slave_aw_valid,
  input  [3:0]  io_slave_aw_bits_id,
  input  [31:0] io_slave_aw_bits_addr,
  output        io_slave_w_ready,
  input         io_slave_w_valid,
  input  [31:0] io_slave_w_bits_data,
  input  [3:0]  io_slave_w_bits_strb,
  input         io_slave_w_bits_last,
  input         io_slave_b_ready,
  output        io_slave_b_valid,
  output [3:0]  io_slave_b_bits_id,
  output        io_slave_ar_ready,
  input         io_slave_ar_valid,
  input  [3:0]  io_slave_ar_bits_id,
  input  [31:0] io_slave_ar_bits_addr,
  input         io_slave_r_ready,
  output        io_slave_r_valid,
  output [3:0]  io_slave_r_bits_id,
  output [31:0] io_slave_r_bits_data,
  output        io_slave_r_bits_last
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] memory [0:63]; // @[DataMem.scala 23:19]
  wire  memory_io_slave_r_bits_data_MPORT_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_io_slave_r_bits_data_MPORT_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_io_slave_r_bits_data_MPORT_data; // @[DataMem.scala 23:19]
  wire  memory_writeData_0_MPORT_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_writeData_0_MPORT_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_writeData_0_MPORT_data; // @[DataMem.scala 23:19]
  wire  memory_writeData_1_MPORT_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_writeData_1_MPORT_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_writeData_1_MPORT_data; // @[DataMem.scala 23:19]
  wire  memory_writeData_2_MPORT_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_writeData_2_MPORT_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_writeData_2_MPORT_data; // @[DataMem.scala 23:19]
  wire  memory_writeData_3_MPORT_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_writeData_3_MPORT_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_writeData_3_MPORT_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_1_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_1_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_1_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_2_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_2_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_2_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_3_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_3_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_3_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_4_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_4_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_4_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_5_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_5_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_5_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_6_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_6_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_6_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_7_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_7_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_7_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_8_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_8_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_8_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_9_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_9_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_9_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_10_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_10_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_10_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_11_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_11_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_11_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_12_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_12_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_12_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_13_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_13_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_13_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_14_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_14_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_14_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_15_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_15_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_15_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_16_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_16_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_16_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_17_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_17_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_17_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_18_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_18_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_18_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_19_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_19_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_19_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_20_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_20_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_20_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_21_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_21_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_21_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_22_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_22_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_22_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_23_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_23_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_23_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_24_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_24_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_24_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_25_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_25_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_25_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_26_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_26_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_26_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_27_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_27_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_27_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_28_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_28_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_28_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_29_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_29_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_29_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_30_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_30_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_30_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_31_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_31_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_31_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_32_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_32_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_32_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_33_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_33_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_33_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_34_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_34_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_34_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_35_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_35_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_35_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_36_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_36_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_36_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_37_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_37_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_37_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_38_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_38_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_38_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_39_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_39_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_39_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_40_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_40_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_40_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_41_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_41_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_41_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_42_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_42_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_42_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_43_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_43_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_43_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_44_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_44_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_44_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_45_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_45_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_45_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_46_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_46_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_46_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_47_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_47_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_47_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_48_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_48_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_48_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_49_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_49_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_49_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_50_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_50_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_50_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_51_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_51_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_51_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_52_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_52_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_52_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_53_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_53_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_53_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_54_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_54_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_54_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_55_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_55_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_55_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_56_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_56_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_56_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_57_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_57_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_57_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_58_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_58_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_58_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_59_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_59_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_59_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_60_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_60_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_60_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_61_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_61_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_61_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_62_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_62_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_62_data; // @[DataMem.scala 23:19]
  wire  memory_data_MPORT_63_en; // @[DataMem.scala 23:19]
  wire [5:0] memory_data_MPORT_63_addr; // @[DataMem.scala 23:19]
  wire [31:0] memory_data_MPORT_63_data; // @[DataMem.scala 23:19]
  wire [31:0] memory_MPORT_data; // @[DataMem.scala 23:19]
  wire [5:0] memory_MPORT_addr; // @[DataMem.scala 23:19]
  wire  memory_MPORT_mask; // @[DataMem.scala 23:19]
  wire  memory_MPORT_en; // @[DataMem.scala 23:19]
  wire [31:0] memory_MPORT_1_data; // @[DataMem.scala 23:19]
  wire [5:0] memory_MPORT_1_addr; // @[DataMem.scala 23:19]
  wire  memory_MPORT_1_mask; // @[DataMem.scala 23:19]
  wire  memory_MPORT_1_en; // @[DataMem.scala 23:19]
  reg [3:0] readID; // @[DataMem.scala 28:23]
  reg [31:0] rAddrOffset; // @[DataMem.scala 29:28]
  wire [31:0] _wAddrOffset_T_1 = io_slave_aw_bits_addr - 32'h10000; // @[DataMem.scala 31:29]
  wire [31:0] _wAddrOffset_T_3 = _wAddrOffset_T_1 & 32'hfffffffc; // @[DataMem.scala 31:43]
  wire [31:0] wAddrOffset = {{2'd0}, _wAddrOffset_T_3[31:2]}; // @[DataMem.scala 31:62]
  reg [31:0] writeAddressReg; // @[DataMem.scala 33:32]
  reg [3:0] writeID; // @[DataMem.scala 34:24]
  reg [2:0] writeState; // @[DataMem.scala 37:27]
  reg [1:0] readState; // @[DataMem.scala 38:26]
  reg [7:0] rLatencyCounter; // @[DataMem.scala 39:32]
  reg [7:0] wLatencyCounter; // @[DataMem.scala 40:32]
  reg [3:0] rlength; // @[DataMem.scala 43:31]
  reg [3:0] rburst_counter; // @[DataMem.scala 44:31]
  wire  readLast = rburst_counter == rlength; // @[DataMem.scala 47:50]
  wire [1:0] _GEN_3 = io_slave_r_ready ? 2'h3 : readState; // @[DataMem.scala 91:29 92:19 38:26]
  wire [1:0] _GEN_4 = readLast ? 2'h0 : 2'h2; // @[DataMem.scala 96:21 97:19 99:19]
  wire [1:0] _GEN_5 = 2'h3 == readState ? _GEN_4 : readState; // @[DataMem.scala 74:21 38:26]
  wire  _T_6 = readState == 2'h0; // @[DataMem.scala 104:18]
  wire [31:0] _rAddrOffset_T_1 = io_slave_ar_bits_addr - 32'h10000; // @[DataMem.scala 107:44]
  wire [31:0] _rAddrOffset_T_3 = _rAddrOffset_T_1 & 32'hfffffffc; // @[DataMem.scala 107:58]
  wire [31:0] _rAddrOffset_T_4 = {{2'd0}, _rAddrOffset_T_3[31:2]}; // @[DataMem.scala 107:77]
  wire [7:0] _rlength_T = io_slave_ar_valid ? 8'h0 : {{4'd0}, rlength}; // @[DataMem.scala 111:19]
  wire [7:0] _rLatencyCounter_T_1 = rLatencyCounter + 8'h1; // @[DataMem.scala 116:40]
  wire  _T_9 = readState == 2'h3; // @[DataMem.scala 121:23]
  wire [3:0] _rburst_counter_T_3 = rburst_counter + 4'h1; // @[DataMem.scala 130:22]
  wire [3:0] _rburst_counter_T_5 = io_slave_r_ready & readLast ? 4'h0 : rburst_counter; // @[DataMem.scala 131:10]
  wire [3:0] _rburst_counter_T_6 = io_slave_r_ready & ~readLast ? _rburst_counter_T_3 : _rburst_counter_T_5; // @[DataMem.scala 129:26]
  wire [31:0] _rAddrOffset_T_6 = rAddrOffset + 32'h4; // @[DataMem.scala 136:54]
  wire [31:0] _rAddrOffset_T_7 = io_slave_r_ready ? _rAddrOffset_T_6 : rAddrOffset; // @[DataMem.scala 136:23]
  wire [7:0] _GEN_9 = readState == 2'h3 ? 8'h0 : rLatencyCounter; // @[DataMem.scala 121:34 122:21 39:32]
  wire [31:0] _GEN_14 = readState == 2'h3 ? memory_io_slave_r_bits_data_MPORT_data : 32'h0; // @[DataMem.scala 121:34 125:26 67:24]
  wire [3:0] _GEN_15 = readState == 2'h3 ? readID : 4'h0; // @[DataMem.scala 121:34 126:24 66:22]
  wire [3:0] _GEN_16 = readState == 2'h3 ? _rburst_counter_T_6 : rburst_counter; // @[DataMem.scala 121:34 129:20 44:31]
  wire [31:0] _GEN_17 = readState == 2'h3 ? _rAddrOffset_T_7 : rAddrOffset; // @[DataMem.scala 121:34 136:17 29:28]
  wire  _GEN_20 = readState == 2'h2 ? 1'h0 : _T_9; // @[DataMem.scala 118:38 70:20]
  wire [31:0] _GEN_23 = readState == 2'h2 ? 32'h0 : _GEN_14; // @[DataMem.scala 118:38 67:24]
  wire [3:0] _GEN_24 = readState == 2'h2 ? 4'h0 : _GEN_15; // @[DataMem.scala 118:38 66:22]
  wire  _GEN_29 = readState == 2'h1 ? 1'h0 : _GEN_20; // @[DataMem.scala 115:38 70:20]
  wire [31:0] _GEN_32 = readState == 2'h1 ? 32'h0 : _GEN_23; // @[DataMem.scala 115:38 67:24]
  wire [3:0] _GEN_33 = readState == 2'h1 ? 4'h0 : _GEN_24; // @[DataMem.scala 115:38 66:22]
  wire [7:0] _GEN_40 = readState == 2'h0 ? _rlength_T : {{4'd0}, rlength}; // @[DataMem.scala 104:29 111:13 43:31]
  wire [2:0] _GEN_50 = io_slave_aw_valid ? 3'h4 : writeState; // @[DataMem.scala 156:36 157:20 37:27]
  wire [2:0] _GEN_54 = io_slave_w_valid ? 3'h2 : writeState; // @[DataMem.scala 161:30 37:27]
  wire  _T_22 = wLatencyCounter == 8'h4f; // @[DataMem.scala 172:28]
  wire [2:0] _GEN_55 = _T_22 ? 3'h5 : writeState; // @[DataMem.scala 174:54 175:20 37:27]
  wire [2:0] _GEN_56 = wLatencyCounter == 8'h4f & io_slave_w_bits_last ? 3'h3 : _GEN_55; // @[DataMem.scala 172:71 173:20]
  wire [2:0] _GEN_57 = io_slave_b_ready ? 3'h1 : writeState; // @[DataMem.scala 182:30 183:20 37:27]
  wire [2:0] _GEN_58 = 3'h3 == writeState ? _GEN_57 : writeState; // @[DataMem.scala 140:22 37:27]
  wire [2:0] _GEN_59 = 3'h5 == writeState ? 3'h1 : _GEN_58; // @[DataMem.scala 140:22 179:18]
  wire [2:0] _GEN_60 = 3'h2 == writeState ? _GEN_56 : _GEN_59; // @[DataMem.scala 140:22]
  wire [7:0] writeData_0 = io_slave_w_bits_strb[0] ? io_slave_w_bits_data[7:0] : memory_writeData_0_MPORT_data[7:0]; // @[DataMem.scala 190:43 191:20 193:20]
  wire [7:0] writeData_1 = io_slave_w_bits_strb[1] ? io_slave_w_bits_data[15:8] : memory_writeData_1_MPORT_data[15:8]; // @[DataMem.scala 190:43 191:20 193:20]
  wire [7:0] writeData_2 = io_slave_w_bits_strb[2] ? io_slave_w_bits_data[23:16] : memory_writeData_2_MPORT_data[23:16]; // @[DataMem.scala 190:43 191:20 193:20]
  wire [7:0] writeData_3 = io_slave_w_bits_strb[3] ? io_slave_w_bits_data[31:24] : memory_writeData_3_MPORT_data[31:24]; // @[DataMem.scala 190:43 191:20 193:20]
  wire  _T_35 = writeState == 3'h0; // @[DataMem.scala 197:19]
  wire  _T_36 = writeState == 3'h1; // @[DataMem.scala 203:24]
  wire [15:0] lo = {writeData_1,writeData_0}; // @[DataMem.scala 207:46]
  wire [15:0] hi = {writeData_3,writeData_2}; // @[DataMem.scala 207:46]
  wire [31:0] _GEN_80 = io_slave_aw_valid ? wAddrOffset : writeAddressReg; // @[DataMem.scala 211:34 212:23 33:32]
  wire [3:0] _GEN_81 = io_slave_aw_valid ? io_slave_aw_bits_id : writeID; // @[DataMem.scala 211:34 213:15 34:24]
  wire  _T_40 = writeState == 3'h4; // @[DataMem.scala 229:24]
  wire [7:0] _wLatencyCounter_T_1 = wLatencyCounter + 8'h1; // @[DataMem.scala 241:40]
  wire  _T_45 = writeState == 3'h3; // @[DataMem.scala 252:24]
  wire [7:0] _GEN_91 = writeState == 3'h3 ? 8'h0 : wLatencyCounter; // @[DataMem.scala 252:37 253:21 40:32]
  wire [3:0] _GEN_93 = writeState == 3'h3 ? writeID : 4'h0; // @[DataMem.scala 252:37 257:24 58:22]
  wire [7:0] _GEN_96 = writeState == 3'h5 ? 8'h0 : _GEN_91; // @[DataMem.scala 243:38 244:21]
  wire [3:0] _GEN_98 = writeState == 3'h5 ? writeID : _GEN_93; // @[DataMem.scala 243:38 248:24]
  wire  _GEN_99 = writeState == 3'h5 ? 1'h0 : _T_45; // @[DataMem.scala 243:38 60:20]
  wire [7:0] _GEN_101 = writeState == 3'h2 ? _wLatencyCounter_T_1 : _GEN_96; // @[DataMem.scala 240:39 241:21]
  wire [3:0] _GEN_103 = writeState == 3'h2 ? 4'h0 : _GEN_98; // @[DataMem.scala 240:39 58:22]
  wire  _GEN_104 = writeState == 3'h2 ? 1'h0 : _GEN_99; // @[DataMem.scala 240:39 60:20]
  wire  _GEN_108 = writeState == 3'h4 ? 1'h0 : _GEN_104; // @[DataMem.scala 229:39 233:22]
  wire  _GEN_111 = writeState == 3'h4 & io_slave_w_valid; // @[DataMem.scala 229:39 23:19]
  wire [3:0] _GEN_115 = writeState == 3'h4 ? 4'h0 : _GEN_103; // @[DataMem.scala 229:39 58:22]
  wire  _GEN_118 = writeState == 3'h1 | _T_40; // @[DataMem.scala 203:36 205:22]
  wire  _GEN_121 = writeState == 3'h1 & io_slave_w_valid; // @[DataMem.scala 203:36 23:19]
  wire  _GEN_127 = writeState == 3'h1 ? 1'h0 : _GEN_108; // @[DataMem.scala 203:36 216:22]
  wire  _GEN_131 = writeState == 3'h1 ? 1'h0 : _GEN_111; // @[DataMem.scala 203:36 23:19]
  wire [3:0] _GEN_135 = writeState == 3'h1 ? 4'h0 : _GEN_115; // @[DataMem.scala 203:36 58:22]
  wire [7:0] _GEN_223 = reset ? 8'h0 : _GEN_40; // @[DataMem.scala 43:{31,31}]
  assign memory_io_slave_r_bits_data_MPORT_en = _T_6 ? 1'h0 : _GEN_29;
  assign memory_io_slave_r_bits_data_MPORT_addr = rAddrOffset[5:0];
  assign memory_io_slave_r_bits_data_MPORT_data = memory[memory_io_slave_r_bits_data_MPORT_addr]; // @[DataMem.scala 23:19]
  assign memory_writeData_0_MPORT_en = io_slave_w_bits_strb[0] ? 1'h0 : 1'h1;
  assign memory_writeData_0_MPORT_addr = wAddrOffset[5:0];
  assign memory_writeData_0_MPORT_data = memory[memory_writeData_0_MPORT_addr]; // @[DataMem.scala 23:19]
  assign memory_writeData_1_MPORT_en = io_slave_w_bits_strb[1] ? 1'h0 : 1'h1;
  assign memory_writeData_1_MPORT_addr = wAddrOffset[5:0];
  assign memory_writeData_1_MPORT_data = memory[memory_writeData_1_MPORT_addr]; // @[DataMem.scala 23:19]
  assign memory_writeData_2_MPORT_en = io_slave_w_bits_strb[2] ? 1'h0 : 1'h1;
  assign memory_writeData_2_MPORT_addr = wAddrOffset[5:0];
  assign memory_writeData_2_MPORT_data = memory[memory_writeData_2_MPORT_addr]; // @[DataMem.scala 23:19]
  assign memory_writeData_3_MPORT_en = io_slave_w_bits_strb[3] ? 1'h0 : 1'h1;
  assign memory_writeData_3_MPORT_addr = wAddrOffset[5:0];
  assign memory_writeData_3_MPORT_data = memory[memory_writeData_3_MPORT_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_en = 1'h0;
  assign memory_data_MPORT_addr = 6'h0;
  assign memory_data_MPORT_data = memory[memory_data_MPORT_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_1_en = 1'h0;
  assign memory_data_MPORT_1_addr = 6'h1;
  assign memory_data_MPORT_1_data = memory[memory_data_MPORT_1_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_2_en = 1'h0;
  assign memory_data_MPORT_2_addr = 6'h2;
  assign memory_data_MPORT_2_data = memory[memory_data_MPORT_2_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_3_en = 1'h0;
  assign memory_data_MPORT_3_addr = 6'h3;
  assign memory_data_MPORT_3_data = memory[memory_data_MPORT_3_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_4_en = 1'h0;
  assign memory_data_MPORT_4_addr = 6'h4;
  assign memory_data_MPORT_4_data = memory[memory_data_MPORT_4_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_5_en = 1'h0;
  assign memory_data_MPORT_5_addr = 6'h5;
  assign memory_data_MPORT_5_data = memory[memory_data_MPORT_5_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_6_en = 1'h0;
  assign memory_data_MPORT_6_addr = 6'h6;
  assign memory_data_MPORT_6_data = memory[memory_data_MPORT_6_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_7_en = 1'h0;
  assign memory_data_MPORT_7_addr = 6'h7;
  assign memory_data_MPORT_7_data = memory[memory_data_MPORT_7_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_8_en = 1'h0;
  assign memory_data_MPORT_8_addr = 6'h8;
  assign memory_data_MPORT_8_data = memory[memory_data_MPORT_8_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_9_en = 1'h0;
  assign memory_data_MPORT_9_addr = 6'h9;
  assign memory_data_MPORT_9_data = memory[memory_data_MPORT_9_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_10_en = 1'h0;
  assign memory_data_MPORT_10_addr = 6'ha;
  assign memory_data_MPORT_10_data = memory[memory_data_MPORT_10_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_11_en = 1'h0;
  assign memory_data_MPORT_11_addr = 6'hb;
  assign memory_data_MPORT_11_data = memory[memory_data_MPORT_11_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_12_en = 1'h0;
  assign memory_data_MPORT_12_addr = 6'hc;
  assign memory_data_MPORT_12_data = memory[memory_data_MPORT_12_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_13_en = 1'h0;
  assign memory_data_MPORT_13_addr = 6'hd;
  assign memory_data_MPORT_13_data = memory[memory_data_MPORT_13_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_14_en = 1'h0;
  assign memory_data_MPORT_14_addr = 6'he;
  assign memory_data_MPORT_14_data = memory[memory_data_MPORT_14_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_15_en = 1'h0;
  assign memory_data_MPORT_15_addr = 6'hf;
  assign memory_data_MPORT_15_data = memory[memory_data_MPORT_15_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_16_en = 1'h0;
  assign memory_data_MPORT_16_addr = 6'h10;
  assign memory_data_MPORT_16_data = memory[memory_data_MPORT_16_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_17_en = 1'h0;
  assign memory_data_MPORT_17_addr = 6'h11;
  assign memory_data_MPORT_17_data = memory[memory_data_MPORT_17_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_18_en = 1'h0;
  assign memory_data_MPORT_18_addr = 6'h12;
  assign memory_data_MPORT_18_data = memory[memory_data_MPORT_18_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_19_en = 1'h0;
  assign memory_data_MPORT_19_addr = 6'h13;
  assign memory_data_MPORT_19_data = memory[memory_data_MPORT_19_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_20_en = 1'h0;
  assign memory_data_MPORT_20_addr = 6'h14;
  assign memory_data_MPORT_20_data = memory[memory_data_MPORT_20_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_21_en = 1'h0;
  assign memory_data_MPORT_21_addr = 6'h15;
  assign memory_data_MPORT_21_data = memory[memory_data_MPORT_21_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_22_en = 1'h0;
  assign memory_data_MPORT_22_addr = 6'h16;
  assign memory_data_MPORT_22_data = memory[memory_data_MPORT_22_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_23_en = 1'h0;
  assign memory_data_MPORT_23_addr = 6'h17;
  assign memory_data_MPORT_23_data = memory[memory_data_MPORT_23_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_24_en = 1'h0;
  assign memory_data_MPORT_24_addr = 6'h18;
  assign memory_data_MPORT_24_data = memory[memory_data_MPORT_24_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_25_en = 1'h0;
  assign memory_data_MPORT_25_addr = 6'h19;
  assign memory_data_MPORT_25_data = memory[memory_data_MPORT_25_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_26_en = 1'h0;
  assign memory_data_MPORT_26_addr = 6'h1a;
  assign memory_data_MPORT_26_data = memory[memory_data_MPORT_26_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_27_en = 1'h0;
  assign memory_data_MPORT_27_addr = 6'h1b;
  assign memory_data_MPORT_27_data = memory[memory_data_MPORT_27_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_28_en = 1'h0;
  assign memory_data_MPORT_28_addr = 6'h1c;
  assign memory_data_MPORT_28_data = memory[memory_data_MPORT_28_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_29_en = 1'h0;
  assign memory_data_MPORT_29_addr = 6'h1d;
  assign memory_data_MPORT_29_data = memory[memory_data_MPORT_29_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_30_en = 1'h0;
  assign memory_data_MPORT_30_addr = 6'h1e;
  assign memory_data_MPORT_30_data = memory[memory_data_MPORT_30_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_31_en = 1'h0;
  assign memory_data_MPORT_31_addr = 6'h1f;
  assign memory_data_MPORT_31_data = memory[memory_data_MPORT_31_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_32_en = 1'h0;
  assign memory_data_MPORT_32_addr = 6'h20;
  assign memory_data_MPORT_32_data = memory[memory_data_MPORT_32_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_33_en = 1'h0;
  assign memory_data_MPORT_33_addr = 6'h21;
  assign memory_data_MPORT_33_data = memory[memory_data_MPORT_33_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_34_en = 1'h0;
  assign memory_data_MPORT_34_addr = 6'h22;
  assign memory_data_MPORT_34_data = memory[memory_data_MPORT_34_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_35_en = 1'h0;
  assign memory_data_MPORT_35_addr = 6'h23;
  assign memory_data_MPORT_35_data = memory[memory_data_MPORT_35_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_36_en = 1'h0;
  assign memory_data_MPORT_36_addr = 6'h24;
  assign memory_data_MPORT_36_data = memory[memory_data_MPORT_36_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_37_en = 1'h0;
  assign memory_data_MPORT_37_addr = 6'h25;
  assign memory_data_MPORT_37_data = memory[memory_data_MPORT_37_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_38_en = 1'h0;
  assign memory_data_MPORT_38_addr = 6'h26;
  assign memory_data_MPORT_38_data = memory[memory_data_MPORT_38_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_39_en = 1'h0;
  assign memory_data_MPORT_39_addr = 6'h27;
  assign memory_data_MPORT_39_data = memory[memory_data_MPORT_39_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_40_en = 1'h0;
  assign memory_data_MPORT_40_addr = 6'h28;
  assign memory_data_MPORT_40_data = memory[memory_data_MPORT_40_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_41_en = 1'h0;
  assign memory_data_MPORT_41_addr = 6'h29;
  assign memory_data_MPORT_41_data = memory[memory_data_MPORT_41_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_42_en = 1'h0;
  assign memory_data_MPORT_42_addr = 6'h2a;
  assign memory_data_MPORT_42_data = memory[memory_data_MPORT_42_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_43_en = 1'h0;
  assign memory_data_MPORT_43_addr = 6'h2b;
  assign memory_data_MPORT_43_data = memory[memory_data_MPORT_43_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_44_en = 1'h0;
  assign memory_data_MPORT_44_addr = 6'h2c;
  assign memory_data_MPORT_44_data = memory[memory_data_MPORT_44_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_45_en = 1'h0;
  assign memory_data_MPORT_45_addr = 6'h2d;
  assign memory_data_MPORT_45_data = memory[memory_data_MPORT_45_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_46_en = 1'h0;
  assign memory_data_MPORT_46_addr = 6'h2e;
  assign memory_data_MPORT_46_data = memory[memory_data_MPORT_46_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_47_en = 1'h0;
  assign memory_data_MPORT_47_addr = 6'h2f;
  assign memory_data_MPORT_47_data = memory[memory_data_MPORT_47_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_48_en = 1'h0;
  assign memory_data_MPORT_48_addr = 6'h30;
  assign memory_data_MPORT_48_data = memory[memory_data_MPORT_48_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_49_en = 1'h0;
  assign memory_data_MPORT_49_addr = 6'h31;
  assign memory_data_MPORT_49_data = memory[memory_data_MPORT_49_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_50_en = 1'h0;
  assign memory_data_MPORT_50_addr = 6'h32;
  assign memory_data_MPORT_50_data = memory[memory_data_MPORT_50_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_51_en = 1'h0;
  assign memory_data_MPORT_51_addr = 6'h33;
  assign memory_data_MPORT_51_data = memory[memory_data_MPORT_51_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_52_en = 1'h0;
  assign memory_data_MPORT_52_addr = 6'h34;
  assign memory_data_MPORT_52_data = memory[memory_data_MPORT_52_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_53_en = 1'h0;
  assign memory_data_MPORT_53_addr = 6'h35;
  assign memory_data_MPORT_53_data = memory[memory_data_MPORT_53_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_54_en = 1'h0;
  assign memory_data_MPORT_54_addr = 6'h36;
  assign memory_data_MPORT_54_data = memory[memory_data_MPORT_54_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_55_en = 1'h0;
  assign memory_data_MPORT_55_addr = 6'h37;
  assign memory_data_MPORT_55_data = memory[memory_data_MPORT_55_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_56_en = 1'h0;
  assign memory_data_MPORT_56_addr = 6'h38;
  assign memory_data_MPORT_56_data = memory[memory_data_MPORT_56_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_57_en = 1'h0;
  assign memory_data_MPORT_57_addr = 6'h39;
  assign memory_data_MPORT_57_data = memory[memory_data_MPORT_57_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_58_en = 1'h0;
  assign memory_data_MPORT_58_addr = 6'h3a;
  assign memory_data_MPORT_58_data = memory[memory_data_MPORT_58_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_59_en = 1'h0;
  assign memory_data_MPORT_59_addr = 6'h3b;
  assign memory_data_MPORT_59_data = memory[memory_data_MPORT_59_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_60_en = 1'h0;
  assign memory_data_MPORT_60_addr = 6'h3c;
  assign memory_data_MPORT_60_data = memory[memory_data_MPORT_60_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_61_en = 1'h0;
  assign memory_data_MPORT_61_addr = 6'h3d;
  assign memory_data_MPORT_61_data = memory[memory_data_MPORT_61_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_62_en = 1'h0;
  assign memory_data_MPORT_62_addr = 6'h3e;
  assign memory_data_MPORT_62_data = memory[memory_data_MPORT_62_addr]; // @[DataMem.scala 23:19]
  assign memory_data_MPORT_63_en = 1'h0;
  assign memory_data_MPORT_63_addr = 6'h3f;
  assign memory_data_MPORT_63_data = memory[memory_data_MPORT_63_addr]; // @[DataMem.scala 23:19]
  assign memory_MPORT_data = {hi,lo};
  assign memory_MPORT_addr = wAddrOffset[5:0];
  assign memory_MPORT_mask = 1'h1;
  assign memory_MPORT_en = _T_35 ? 1'h0 : _GEN_121;
  assign memory_MPORT_1_data = {hi,lo};
  assign memory_MPORT_1_addr = writeAddressReg[5:0];
  assign memory_MPORT_1_mask = 1'h1;
  assign memory_MPORT_1_en = _T_35 ? 1'h0 : _GEN_131;
  assign io_slave_aw_ready = writeState == 3'h0 ? 1'h0 : _T_36; // @[DataMem.scala 197:30 198:23]
  assign io_slave_w_ready = writeState == 3'h0 ? 1'h0 : _GEN_118; // @[DataMem.scala 197:30 199:22]
  assign io_slave_b_valid = writeState == 3'h0 ? 1'h0 : _GEN_127; // @[DataMem.scala 197:30 201:22]
  assign io_slave_b_bits_id = writeState == 3'h0 ? 4'h0 : _GEN_135; // @[DataMem.scala 197:30 58:22]
  assign io_slave_ar_ready = readState == 2'h0; // @[DataMem.scala 104:18]
  assign io_slave_r_valid = readState == 2'h0 ? 1'h0 : _GEN_29; // @[DataMem.scala 104:29 106:22]
  assign io_slave_r_bits_id = readState == 2'h0 ? 4'h0 : _GEN_33; // @[DataMem.scala 104:29 66:22]
  assign io_slave_r_bits_data = readState == 2'h0 ? 32'h0 : _GEN_32; // @[DataMem.scala 104:29 67:24]
  assign io_slave_r_bits_last = rburst_counter == rlength; // @[DataMem.scala 47:50]
  always @(posedge clock) begin
    if (memory_MPORT_en & memory_MPORT_mask) begin
      memory[memory_MPORT_addr] <= memory_MPORT_data; // @[DataMem.scala 23:19]
    end
    if (memory_MPORT_1_en & memory_MPORT_1_mask) begin
      memory[memory_MPORT_1_addr] <= memory_MPORT_1_data; // @[DataMem.scala 23:19]
    end
    if (reset) begin // @[DataMem.scala 28:23]
      readID <= 4'h0; // @[DataMem.scala 28:23]
    end else if (readState == 2'h0) begin // @[DataMem.scala 104:29]
      readID <= io_slave_ar_bits_id; // @[DataMem.scala 108:12]
    end
    if (reset) begin // @[DataMem.scala 29:28]
      rAddrOffset <= 32'h0; // @[DataMem.scala 29:28]
    end else if (readState == 2'h0) begin // @[DataMem.scala 104:29]
      rAddrOffset <= _rAddrOffset_T_4; // @[DataMem.scala 107:17]
    end else if (!(readState == 2'h1)) begin // @[DataMem.scala 115:38]
      if (!(readState == 2'h2)) begin // @[DataMem.scala 118:38]
        rAddrOffset <= _GEN_17;
      end
    end
    if (reset) begin // @[DataMem.scala 33:32]
      writeAddressReg <= 32'h0; // @[DataMem.scala 33:32]
    end else if (!(writeState == 3'h0)) begin // @[DataMem.scala 197:30]
      if (writeState == 3'h1) begin // @[DataMem.scala 203:36]
        if (io_slave_w_valid) begin // @[DataMem.scala 206:28]
          writeAddressReg <= wAddrOffset; // @[DataMem.scala 208:23]
        end else begin
          writeAddressReg <= _GEN_80;
        end
      end
    end
    if (reset) begin // @[DataMem.scala 34:24]
      writeID <= 4'h0; // @[DataMem.scala 34:24]
    end else if (!(writeState == 3'h0)) begin // @[DataMem.scala 197:30]
      if (writeState == 3'h1) begin // @[DataMem.scala 203:36]
        if (io_slave_w_valid) begin // @[DataMem.scala 206:28]
          writeID <= io_slave_aw_bits_id; // @[DataMem.scala 209:15]
        end else begin
          writeID <= _GEN_81;
        end
      end
    end
    if (reset) begin // @[DataMem.scala 37:27]
      writeState <= 3'h0; // @[DataMem.scala 37:27]
    end else if (3'h0 == writeState) begin // @[DataMem.scala 140:22]
      writeState <= 3'h1; // @[DataMem.scala 142:18]
    end else if (3'h1 == writeState) begin // @[DataMem.scala 140:22]
      if (io_slave_w_valid | io_slave_aw_valid & io_slave_w_valid) begin // @[DataMem.scala 146:73]
        writeState <= 3'h2;
      end else begin
        writeState <= _GEN_50;
      end
    end else if (3'h4 == writeState) begin // @[DataMem.scala 140:22]
      writeState <= _GEN_54;
    end else begin
      writeState <= _GEN_60;
    end
    if (reset) begin // @[DataMem.scala 38:26]
      readState <= 2'h0; // @[DataMem.scala 38:26]
    end else if (2'h0 == readState) begin // @[DataMem.scala 74:21]
      if (io_slave_ar_valid) begin // @[DataMem.scala 76:31]
        readState <= 2'h1;
      end
    end else if (2'h1 == readState) begin // @[DataMem.scala 74:21]
      if (rLatencyCounter == 8'h4f) begin // @[DataMem.scala 86:49]
        readState <= 2'h2; // @[DataMem.scala 87:19]
      end
    end else if (2'h2 == readState) begin // @[DataMem.scala 74:21]
      readState <= _GEN_3;
    end else begin
      readState <= _GEN_5;
    end
    if (reset) begin // @[DataMem.scala 39:32]
      rLatencyCounter <= 8'h0; // @[DataMem.scala 39:32]
    end else if (!(readState == 2'h0)) begin // @[DataMem.scala 104:29]
      if (readState == 2'h1) begin // @[DataMem.scala 115:38]
        rLatencyCounter <= _rLatencyCounter_T_1; // @[DataMem.scala 116:21]
      end else if (!(readState == 2'h2)) begin // @[DataMem.scala 118:38]
        rLatencyCounter <= _GEN_9;
      end
    end
    if (reset) begin // @[DataMem.scala 40:32]
      wLatencyCounter <= 8'h0; // @[DataMem.scala 40:32]
    end else if (!(writeState == 3'h0)) begin // @[DataMem.scala 197:30]
      if (!(writeState == 3'h1)) begin // @[DataMem.scala 203:36]
        if (!(writeState == 3'h4)) begin // @[DataMem.scala 229:39]
          wLatencyCounter <= _GEN_101;
        end
      end
    end
    rlength <= _GEN_223[3:0]; // @[DataMem.scala 43:{31,31}]
    if (reset) begin // @[DataMem.scala 44:31]
      rburst_counter <= 4'h0; // @[DataMem.scala 44:31]
    end else if (!(readState == 2'h0)) begin // @[DataMem.scala 104:29]
      if (!(readState == 2'h1)) begin // @[DataMem.scala 115:38]
        if (!(readState == 2'h2)) begin // @[DataMem.scala 118:38]
          rburst_counter <= _GEN_16;
        end
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
  integer initvar;
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  readID = _RAND_0[3:0];
  _RAND_1 = {1{`RANDOM}};
  rAddrOffset = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  writeAddressReg = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  writeID = _RAND_3[3:0];
  _RAND_4 = {1{`RANDOM}};
  writeState = _RAND_4[2:0];
  _RAND_5 = {1{`RANDOM}};
  readState = _RAND_5[1:0];
  _RAND_6 = {1{`RANDOM}};
  rLatencyCounter = _RAND_6[7:0];
  _RAND_7 = {1{`RANDOM}};
  wLatencyCounter = _RAND_7[7:0];
  _RAND_8 = {1{`RANDOM}};
  rlength = _RAND_8[3:0];
  _RAND_9 = {1{`RANDOM}};
  rburst_counter = _RAND_9[3:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
  $readmemh("./src/main/resource/data1.hex", memory);
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module top_SoC(
  input         clock,
  input         reset,
  output [31:0] io_regs_0,
  output [31:0] io_regs_1,
  output [31:0] io_regs_2,
  output [31:0] io_regs_3,
  output [31:0] io_regs_4,
  output [31:0] io_regs_5,
  output [31:0] io_regs_6,
  output [31:0] io_regs_7,
  output [31:0] io_regs_8,
  output [31:0] io_regs_9,
  output [31:0] io_regs_10,
  output [31:0] io_regs_11,
  output [31:0] io_regs_12,
  output [31:0] io_regs_13,
  output [31:0] io_regs_14,
  output [31:0] io_regs_15,
  output [31:0] io_regs_16,
  output [31:0] io_regs_17,
  output [31:0] io_regs_18,
  output [31:0] io_regs_19,
  output [31:0] io_regs_20,
  output [31:0] io_regs_21,
  output [31:0] io_regs_22,
  output [31:0] io_regs_23,
  output [31:0] io_regs_24,
  output [31:0] io_regs_25,
  output [31:0] io_regs_26,
  output [31:0] io_regs_27,
  output [31:0] io_regs_28,
  output [31:0] io_regs_29,
  output [31:0] io_regs_30,
  output [31:0] io_regs_31,
  output        io_Hcf,
  output [31:0] io_inst,
  output [31:0] io_rdata,
  output [31:0] io_wdata,
  input         io_Dump_Mem,
  output        io_E_Branch_taken,
  output        io_Flush,
  output        io_Stall_MA,
  output        io_Stall_DH,
  output [31:0] io_IF_PC,
  output [31:0] io_ID_PC,
  output [31:0] io_EXE_PC,
  output [31:0] io_MEM_PC,
  output [31:0] io_WB_PC,
  output [31:0] io_EXE_alu_out,
  output [31:0] io_EXE_src1,
  output [31:0] io_EXE_src2,
  output [31:0] io_ALU_src1,
  output [31:0] io_ALU_src2,
  output [31:0] io_raddr,
  output [4:0]  io_WB_rd,
  output [31:0] io_WB_wdata,
  output        io_EXE_Jump,
  output        io_EXE_Branch,
  output        io_DMA_Hcf
);
  wire  dma_clock; // @[top_SoC.scala 75:21]
  wire  dma_reset; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_aw_ready; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_aw_valid; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_slave_aw_bits_id; // @[top_SoC.scala 75:21]
  wire [31:0] dma_io_slave_aw_bits_addr; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_slave_aw_bits_region; // @[top_SoC.scala 75:21]
  wire [7:0] dma_io_slave_aw_bits_len; // @[top_SoC.scala 75:21]
  wire [1:0] dma_io_slave_aw_bits_size; // @[top_SoC.scala 75:21]
  wire [1:0] dma_io_slave_aw_bits_burst; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_aw_bits_lock; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_slave_aw_bits_cache; // @[top_SoC.scala 75:21]
  wire [2:0] dma_io_slave_aw_bits_prot; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_slave_aw_bits_qos; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_w_ready; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_w_valid; // @[top_SoC.scala 75:21]
  wire [31:0] dma_io_slave_w_bits_data; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_slave_w_bits_strb; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_w_bits_last; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_b_ready; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_b_valid; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_slave_b_bits_id; // @[top_SoC.scala 75:21]
  wire [1:0] dma_io_slave_b_bits_resp; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_ar_ready; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_ar_valid; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_slave_ar_bits_id; // @[top_SoC.scala 75:21]
  wire [31:0] dma_io_slave_ar_bits_addr; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_slave_ar_bits_region; // @[top_SoC.scala 75:21]
  wire [7:0] dma_io_slave_ar_bits_len; // @[top_SoC.scala 75:21]
  wire [1:0] dma_io_slave_ar_bits_size; // @[top_SoC.scala 75:21]
  wire [1:0] dma_io_slave_ar_bits_burst; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_ar_bits_lock; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_slave_ar_bits_cache; // @[top_SoC.scala 75:21]
  wire [2:0] dma_io_slave_ar_bits_prot; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_slave_ar_bits_qos; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_r_ready; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_r_valid; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_slave_r_bits_id; // @[top_SoC.scala 75:21]
  wire [31:0] dma_io_slave_r_bits_data; // @[top_SoC.scala 75:21]
  wire [1:0] dma_io_slave_r_bits_resp; // @[top_SoC.scala 75:21]
  wire  dma_io_slave_r_bits_last; // @[top_SoC.scala 75:21]
  wire  dma_io_master_aw_ready; // @[top_SoC.scala 75:21]
  wire  dma_io_master_aw_valid; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_master_aw_bits_id; // @[top_SoC.scala 75:21]
  wire [31:0] dma_io_master_aw_bits_addr; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_master_aw_bits_region; // @[top_SoC.scala 75:21]
  wire [7:0] dma_io_master_aw_bits_len; // @[top_SoC.scala 75:21]
  wire [1:0] dma_io_master_aw_bits_size; // @[top_SoC.scala 75:21]
  wire [1:0] dma_io_master_aw_bits_burst; // @[top_SoC.scala 75:21]
  wire  dma_io_master_aw_bits_lock; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_master_aw_bits_cache; // @[top_SoC.scala 75:21]
  wire [2:0] dma_io_master_aw_bits_prot; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_master_aw_bits_qos; // @[top_SoC.scala 75:21]
  wire  dma_io_master_w_ready; // @[top_SoC.scala 75:21]
  wire  dma_io_master_w_valid; // @[top_SoC.scala 75:21]
  wire [31:0] dma_io_master_w_bits_data; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_master_w_bits_strb; // @[top_SoC.scala 75:21]
  wire  dma_io_master_w_bits_last; // @[top_SoC.scala 75:21]
  wire  dma_io_master_b_ready; // @[top_SoC.scala 75:21]
  wire  dma_io_master_b_valid; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_master_b_bits_id; // @[top_SoC.scala 75:21]
  wire [1:0] dma_io_master_b_bits_resp; // @[top_SoC.scala 75:21]
  wire  dma_io_master_ar_ready; // @[top_SoC.scala 75:21]
  wire  dma_io_master_ar_valid; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_master_ar_bits_id; // @[top_SoC.scala 75:21]
  wire [31:0] dma_io_master_ar_bits_addr; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_master_ar_bits_region; // @[top_SoC.scala 75:21]
  wire [7:0] dma_io_master_ar_bits_len; // @[top_SoC.scala 75:21]
  wire [1:0] dma_io_master_ar_bits_size; // @[top_SoC.scala 75:21]
  wire [1:0] dma_io_master_ar_bits_burst; // @[top_SoC.scala 75:21]
  wire  dma_io_master_ar_bits_lock; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_master_ar_bits_cache; // @[top_SoC.scala 75:21]
  wire [2:0] dma_io_master_ar_bits_prot; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_master_ar_bits_qos; // @[top_SoC.scala 75:21]
  wire  dma_io_master_r_ready; // @[top_SoC.scala 75:21]
  wire  dma_io_master_r_valid; // @[top_SoC.scala 75:21]
  wire [3:0] dma_io_master_r_bits_id; // @[top_SoC.scala 75:21]
  wire [31:0] dma_io_master_r_bits_data; // @[top_SoC.scala 75:21]
  wire [1:0] dma_io_master_r_bits_resp; // @[top_SoC.scala 75:21]
  wire  dma_io_master_r_bits_last; // @[top_SoC.scala 75:21]
  wire  dma_io_Hcf; // @[top_SoC.scala 75:21]
  wire  cpu_clock; // @[top_SoC.scala 76:21]
  wire  cpu_reset; // @[top_SoC.scala 76:21]
  wire [14:0] cpu_io_InstMem_raddr; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_InstMem_rdata; // @[top_SoC.scala 76:21]
  wire  cpu_io_DataMem_Mem_R; // @[top_SoC.scala 76:21]
  wire  cpu_io_DataMem_Mem_W; // @[top_SoC.scala 76:21]
  wire [3:0] cpu_io_DataMem_Length; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_DataMem_raddr; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_DataMem_waddr; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_DataMem_wdata; // @[top_SoC.scala 76:21]
  wire  cpu_io_master_aw_ready; // @[top_SoC.scala 76:21]
  wire  cpu_io_master_aw_valid; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_master_aw_bits_addr; // @[top_SoC.scala 76:21]
  wire  cpu_io_master_w_ready; // @[top_SoC.scala 76:21]
  wire  cpu_io_master_w_valid; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_master_w_bits_data; // @[top_SoC.scala 76:21]
  wire [3:0] cpu_io_master_w_bits_strb; // @[top_SoC.scala 76:21]
  wire  cpu_io_master_b_ready; // @[top_SoC.scala 76:21]
  wire  cpu_io_master_b_valid; // @[top_SoC.scala 76:21]
  wire  cpu_io_master_ar_ready; // @[top_SoC.scala 76:21]
  wire  cpu_io_master_ar_valid; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_master_ar_bits_addr; // @[top_SoC.scala 76:21]
  wire  cpu_io_master_r_ready; // @[top_SoC.scala 76:21]
  wire  cpu_io_master_r_valid; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_master_r_bits_data; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_1; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_2; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_3; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_4; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_5; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_6; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_7; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_8; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_9; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_10; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_11; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_12; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_13; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_14; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_15; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_16; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_17; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_18; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_19; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_20; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_21; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_22; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_23; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_24; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_25; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_26; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_27; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_28; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_29; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_30; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_regs_31; // @[top_SoC.scala 76:21]
  wire  cpu_io_Hcf; // @[top_SoC.scala 76:21]
  wire  cpu_io_DMA_Hcf; // @[top_SoC.scala 76:21]
  wire  cpu_io_E_Branch_taken; // @[top_SoC.scala 76:21]
  wire  cpu_io_Flush; // @[top_SoC.scala 76:21]
  wire  cpu_io_Stall_MA; // @[top_SoC.scala 76:21]
  wire  cpu_io_Stall_DH; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_IF_PC; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_ID_PC; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_EXE_PC; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_MEM_PC; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_WB_PC; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_EXE_src1; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_EXE_src2; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_ALU_src1; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_ALU_src2; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_EXE_alu_out; // @[top_SoC.scala 76:21]
  wire [4:0] cpu_io_WB_rd; // @[top_SoC.scala 76:21]
  wire [31:0] cpu_io_WB_wdata; // @[top_SoC.scala 76:21]
  wire  cpu_io_EXE_Jump; // @[top_SoC.scala 76:21]
  wire  cpu_io_EXE_Branch; // @[top_SoC.scala 76:21]
  wire  im_clock; // @[top_SoC.scala 77:20]
  wire [14:0] im_io_raddr; // @[top_SoC.scala 77:20]
  wire [31:0] im_io_inst; // @[top_SoC.scala 77:20]
  wire  bus_clock; // @[top_SoC.scala 79:21]
  wire  bus_reset; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_0_aw_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_0_aw_valid; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_masters_0_aw_bits_addr; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_0_w_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_0_w_valid; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_masters_0_w_bits_data; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_masters_0_w_bits_strb; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_0_b_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_0_b_valid; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_0_ar_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_0_ar_valid; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_masters_0_ar_bits_addr; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_0_r_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_0_r_valid; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_masters_0_r_bits_data; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_1_aw_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_1_aw_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_masters_1_aw_bits_id; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_masters_1_aw_bits_addr; // @[top_SoC.scala 79:21]
  wire [1:0] bus_io_masters_1_aw_bits_size; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_1_w_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_1_w_valid; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_masters_1_w_bits_data; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_masters_1_w_bits_strb; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_1_w_bits_last; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_1_b_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_1_b_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_masters_1_b_bits_id; // @[top_SoC.scala 79:21]
  wire [1:0] bus_io_masters_1_b_bits_resp; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_1_ar_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_1_ar_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_masters_1_ar_bits_id; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_masters_1_ar_bits_addr; // @[top_SoC.scala 79:21]
  wire [1:0] bus_io_masters_1_ar_bits_size; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_1_r_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_1_r_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_masters_1_r_bits_id; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_masters_1_r_bits_data; // @[top_SoC.scala 79:21]
  wire [1:0] bus_io_masters_1_r_bits_resp; // @[top_SoC.scala 79:21]
  wire  bus_io_masters_1_r_bits_last; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_0_aw_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_0_aw_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_0_aw_bits_id; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_slaves_0_aw_bits_addr; // @[top_SoC.scala 79:21]
  wire [1:0] bus_io_slaves_0_aw_bits_size; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_0_w_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_0_w_valid; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_slaves_0_w_bits_data; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_0_w_bits_strb; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_0_w_bits_last; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_0_b_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_0_b_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_0_b_bits_id; // @[top_SoC.scala 79:21]
  wire [1:0] bus_io_slaves_0_b_bits_resp; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_0_ar_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_0_ar_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_0_ar_bits_id; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_slaves_0_ar_bits_addr; // @[top_SoC.scala 79:21]
  wire [1:0] bus_io_slaves_0_ar_bits_size; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_0_r_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_0_r_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_0_r_bits_id; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_slaves_0_r_bits_data; // @[top_SoC.scala 79:21]
  wire [1:0] bus_io_slaves_0_r_bits_resp; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_0_r_bits_last; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_1_aw_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_1_aw_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_1_aw_bits_id; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_slaves_1_aw_bits_addr; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_1_w_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_1_w_valid; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_slaves_1_w_bits_data; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_1_w_bits_strb; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_1_w_bits_last; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_1_b_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_1_b_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_1_b_bits_id; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_1_ar_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_1_ar_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_1_ar_bits_id; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_slaves_1_ar_bits_addr; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_1_r_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_1_r_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_1_r_bits_id; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_slaves_1_r_bits_data; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_1_r_bits_last; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_2_aw_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_2_aw_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_2_aw_bits_id; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_slaves_2_aw_bits_addr; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_2_w_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_2_w_valid; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_slaves_2_w_bits_data; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_2_w_bits_strb; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_2_w_bits_last; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_2_b_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_2_b_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_2_b_bits_id; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_2_ar_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_2_ar_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_2_ar_bits_id; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_slaves_2_ar_bits_addr; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_2_r_ready; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_2_r_valid; // @[top_SoC.scala 79:21]
  wire [3:0] bus_io_slaves_2_r_bits_id; // @[top_SoC.scala 79:21]
  wire [31:0] bus_io_slaves_2_r_bits_data; // @[top_SoC.scala 79:21]
  wire  bus_io_slaves_2_r_bits_last; // @[top_SoC.scala 79:21]
  wire  localMem_clock; // @[top_SoC.scala 94:26]
  wire  localMem_reset; // @[top_SoC.scala 94:26]
  wire  localMem_io_slave_aw_ready; // @[top_SoC.scala 94:26]
  wire  localMem_io_slave_aw_valid; // @[top_SoC.scala 94:26]
  wire [3:0] localMem_io_slave_aw_bits_id; // @[top_SoC.scala 94:26]
  wire [31:0] localMem_io_slave_aw_bits_addr; // @[top_SoC.scala 94:26]
  wire  localMem_io_slave_w_ready; // @[top_SoC.scala 94:26]
  wire  localMem_io_slave_w_valid; // @[top_SoC.scala 94:26]
  wire [31:0] localMem_io_slave_w_bits_data; // @[top_SoC.scala 94:26]
  wire [3:0] localMem_io_slave_w_bits_strb; // @[top_SoC.scala 94:26]
  wire  localMem_io_slave_w_bits_last; // @[top_SoC.scala 94:26]
  wire  localMem_io_slave_b_ready; // @[top_SoC.scala 94:26]
  wire  localMem_io_slave_b_valid; // @[top_SoC.scala 94:26]
  wire [3:0] localMem_io_slave_b_bits_id; // @[top_SoC.scala 94:26]
  wire  localMem_io_slave_ar_ready; // @[top_SoC.scala 94:26]
  wire  localMem_io_slave_ar_valid; // @[top_SoC.scala 94:26]
  wire [3:0] localMem_io_slave_ar_bits_id; // @[top_SoC.scala 94:26]
  wire [31:0] localMem_io_slave_ar_bits_addr; // @[top_SoC.scala 94:26]
  wire  localMem_io_slave_r_ready; // @[top_SoC.scala 94:26]
  wire  localMem_io_slave_r_valid; // @[top_SoC.scala 94:26]
  wire [3:0] localMem_io_slave_r_bits_id; // @[top_SoC.scala 94:26]
  wire [31:0] localMem_io_slave_r_bits_data; // @[top_SoC.scala 94:26]
  wire  localMem_io_slave_r_bits_last; // @[top_SoC.scala 94:26]
  wire  localMem_io_dump; // @[top_SoC.scala 94:26]
  wire  globalMem_clock; // @[top_SoC.scala 106:27]
  wire  globalMem_reset; // @[top_SoC.scala 106:27]
  wire  globalMem_io_slave_aw_ready; // @[top_SoC.scala 106:27]
  wire  globalMem_io_slave_aw_valid; // @[top_SoC.scala 106:27]
  wire [3:0] globalMem_io_slave_aw_bits_id; // @[top_SoC.scala 106:27]
  wire [31:0] globalMem_io_slave_aw_bits_addr; // @[top_SoC.scala 106:27]
  wire  globalMem_io_slave_w_ready; // @[top_SoC.scala 106:27]
  wire  globalMem_io_slave_w_valid; // @[top_SoC.scala 106:27]
  wire [31:0] globalMem_io_slave_w_bits_data; // @[top_SoC.scala 106:27]
  wire [3:0] globalMem_io_slave_w_bits_strb; // @[top_SoC.scala 106:27]
  wire  globalMem_io_slave_w_bits_last; // @[top_SoC.scala 106:27]
  wire  globalMem_io_slave_b_ready; // @[top_SoC.scala 106:27]
  wire  globalMem_io_slave_b_valid; // @[top_SoC.scala 106:27]
  wire [3:0] globalMem_io_slave_b_bits_id; // @[top_SoC.scala 106:27]
  wire  globalMem_io_slave_ar_ready; // @[top_SoC.scala 106:27]
  wire  globalMem_io_slave_ar_valid; // @[top_SoC.scala 106:27]
  wire [3:0] globalMem_io_slave_ar_bits_id; // @[top_SoC.scala 106:27]
  wire [31:0] globalMem_io_slave_ar_bits_addr; // @[top_SoC.scala 106:27]
  wire  globalMem_io_slave_r_ready; // @[top_SoC.scala 106:27]
  wire  globalMem_io_slave_r_valid; // @[top_SoC.scala 106:27]
  wire [3:0] globalMem_io_slave_r_bits_id; // @[top_SoC.scala 106:27]
  wire [31:0] globalMem_io_slave_r_bits_data; // @[top_SoC.scala 106:27]
  wire  globalMem_io_slave_r_bits_last; // @[top_SoC.scala 106:27]
  DMA dma ( // @[top_SoC.scala 75:21]
    .clock(dma_clock),
    .reset(dma_reset),
    .io_slave_aw_ready(dma_io_slave_aw_ready),
    .io_slave_aw_valid(dma_io_slave_aw_valid),
    .io_slave_aw_bits_id(dma_io_slave_aw_bits_id),
    .io_slave_aw_bits_addr(dma_io_slave_aw_bits_addr),
    .io_slave_aw_bits_region(dma_io_slave_aw_bits_region),
    .io_slave_aw_bits_len(dma_io_slave_aw_bits_len),
    .io_slave_aw_bits_size(dma_io_slave_aw_bits_size),
    .io_slave_aw_bits_burst(dma_io_slave_aw_bits_burst),
    .io_slave_aw_bits_lock(dma_io_slave_aw_bits_lock),
    .io_slave_aw_bits_cache(dma_io_slave_aw_bits_cache),
    .io_slave_aw_bits_prot(dma_io_slave_aw_bits_prot),
    .io_slave_aw_bits_qos(dma_io_slave_aw_bits_qos),
    .io_slave_w_ready(dma_io_slave_w_ready),
    .io_slave_w_valid(dma_io_slave_w_valid),
    .io_slave_w_bits_data(dma_io_slave_w_bits_data),
    .io_slave_w_bits_strb(dma_io_slave_w_bits_strb),
    .io_slave_w_bits_last(dma_io_slave_w_bits_last),
    .io_slave_b_ready(dma_io_slave_b_ready),
    .io_slave_b_valid(dma_io_slave_b_valid),
    .io_slave_b_bits_id(dma_io_slave_b_bits_id),
    .io_slave_b_bits_resp(dma_io_slave_b_bits_resp),
    .io_slave_ar_ready(dma_io_slave_ar_ready),
    .io_slave_ar_valid(dma_io_slave_ar_valid),
    .io_slave_ar_bits_id(dma_io_slave_ar_bits_id),
    .io_slave_ar_bits_addr(dma_io_slave_ar_bits_addr),
    .io_slave_ar_bits_region(dma_io_slave_ar_bits_region),
    .io_slave_ar_bits_len(dma_io_slave_ar_bits_len),
    .io_slave_ar_bits_size(dma_io_slave_ar_bits_size),
    .io_slave_ar_bits_burst(dma_io_slave_ar_bits_burst),
    .io_slave_ar_bits_lock(dma_io_slave_ar_bits_lock),
    .io_slave_ar_bits_cache(dma_io_slave_ar_bits_cache),
    .io_slave_ar_bits_prot(dma_io_slave_ar_bits_prot),
    .io_slave_ar_bits_qos(dma_io_slave_ar_bits_qos),
    .io_slave_r_ready(dma_io_slave_r_ready),
    .io_slave_r_valid(dma_io_slave_r_valid),
    .io_slave_r_bits_id(dma_io_slave_r_bits_id),
    .io_slave_r_bits_data(dma_io_slave_r_bits_data),
    .io_slave_r_bits_resp(dma_io_slave_r_bits_resp),
    .io_slave_r_bits_last(dma_io_slave_r_bits_last),
    .io_master_aw_ready(dma_io_master_aw_ready),
    .io_master_aw_valid(dma_io_master_aw_valid),
    .io_master_aw_bits_id(dma_io_master_aw_bits_id),
    .io_master_aw_bits_addr(dma_io_master_aw_bits_addr),
    .io_master_aw_bits_region(dma_io_master_aw_bits_region),
    .io_master_aw_bits_len(dma_io_master_aw_bits_len),
    .io_master_aw_bits_size(dma_io_master_aw_bits_size),
    .io_master_aw_bits_burst(dma_io_master_aw_bits_burst),
    .io_master_aw_bits_lock(dma_io_master_aw_bits_lock),
    .io_master_aw_bits_cache(dma_io_master_aw_bits_cache),
    .io_master_aw_bits_prot(dma_io_master_aw_bits_prot),
    .io_master_aw_bits_qos(dma_io_master_aw_bits_qos),
    .io_master_w_ready(dma_io_master_w_ready),
    .io_master_w_valid(dma_io_master_w_valid),
    .io_master_w_bits_data(dma_io_master_w_bits_data),
    .io_master_w_bits_strb(dma_io_master_w_bits_strb),
    .io_master_w_bits_last(dma_io_master_w_bits_last),
    .io_master_b_ready(dma_io_master_b_ready),
    .io_master_b_valid(dma_io_master_b_valid),
    .io_master_b_bits_id(dma_io_master_b_bits_id),
    .io_master_b_bits_resp(dma_io_master_b_bits_resp),
    .io_master_ar_ready(dma_io_master_ar_ready),
    .io_master_ar_valid(dma_io_master_ar_valid),
    .io_master_ar_bits_id(dma_io_master_ar_bits_id),
    .io_master_ar_bits_addr(dma_io_master_ar_bits_addr),
    .io_master_ar_bits_region(dma_io_master_ar_bits_region),
    .io_master_ar_bits_len(dma_io_master_ar_bits_len),
    .io_master_ar_bits_size(dma_io_master_ar_bits_size),
    .io_master_ar_bits_burst(dma_io_master_ar_bits_burst),
    .io_master_ar_bits_lock(dma_io_master_ar_bits_lock),
    .io_master_ar_bits_cache(dma_io_master_ar_bits_cache),
    .io_master_ar_bits_prot(dma_io_master_ar_bits_prot),
    .io_master_ar_bits_qos(dma_io_master_ar_bits_qos),
    .io_master_r_ready(dma_io_master_r_ready),
    .io_master_r_valid(dma_io_master_r_valid),
    .io_master_r_bits_id(dma_io_master_r_bits_id),
    .io_master_r_bits_data(dma_io_master_r_bits_data),
    .io_master_r_bits_resp(dma_io_master_r_bits_resp),
    .io_master_r_bits_last(dma_io_master_r_bits_last),
    .io_Hcf(dma_io_Hcf)
  );
  PipelinedCPU cpu ( // @[top_SoC.scala 76:21]
    .clock(cpu_clock),
    .reset(cpu_reset),
    .io_InstMem_raddr(cpu_io_InstMem_raddr),
    .io_InstMem_rdata(cpu_io_InstMem_rdata),
    .io_DataMem_Mem_R(cpu_io_DataMem_Mem_R),
    .io_DataMem_Mem_W(cpu_io_DataMem_Mem_W),
    .io_DataMem_Length(cpu_io_DataMem_Length),
    .io_DataMem_raddr(cpu_io_DataMem_raddr),
    .io_DataMem_waddr(cpu_io_DataMem_waddr),
    .io_DataMem_wdata(cpu_io_DataMem_wdata),
    .io_master_aw_ready(cpu_io_master_aw_ready),
    .io_master_aw_valid(cpu_io_master_aw_valid),
    .io_master_aw_bits_addr(cpu_io_master_aw_bits_addr),
    .io_master_w_ready(cpu_io_master_w_ready),
    .io_master_w_valid(cpu_io_master_w_valid),
    .io_master_w_bits_data(cpu_io_master_w_bits_data),
    .io_master_w_bits_strb(cpu_io_master_w_bits_strb),
    .io_master_b_ready(cpu_io_master_b_ready),
    .io_master_b_valid(cpu_io_master_b_valid),
    .io_master_ar_ready(cpu_io_master_ar_ready),
    .io_master_ar_valid(cpu_io_master_ar_valid),
    .io_master_ar_bits_addr(cpu_io_master_ar_bits_addr),
    .io_master_r_ready(cpu_io_master_r_ready),
    .io_master_r_valid(cpu_io_master_r_valid),
    .io_master_r_bits_data(cpu_io_master_r_bits_data),
    .io_regs_1(cpu_io_regs_1),
    .io_regs_2(cpu_io_regs_2),
    .io_regs_3(cpu_io_regs_3),
    .io_regs_4(cpu_io_regs_4),
    .io_regs_5(cpu_io_regs_5),
    .io_regs_6(cpu_io_regs_6),
    .io_regs_7(cpu_io_regs_7),
    .io_regs_8(cpu_io_regs_8),
    .io_regs_9(cpu_io_regs_9),
    .io_regs_10(cpu_io_regs_10),
    .io_regs_11(cpu_io_regs_11),
    .io_regs_12(cpu_io_regs_12),
    .io_regs_13(cpu_io_regs_13),
    .io_regs_14(cpu_io_regs_14),
    .io_regs_15(cpu_io_regs_15),
    .io_regs_16(cpu_io_regs_16),
    .io_regs_17(cpu_io_regs_17),
    .io_regs_18(cpu_io_regs_18),
    .io_regs_19(cpu_io_regs_19),
    .io_regs_20(cpu_io_regs_20),
    .io_regs_21(cpu_io_regs_21),
    .io_regs_22(cpu_io_regs_22),
    .io_regs_23(cpu_io_regs_23),
    .io_regs_24(cpu_io_regs_24),
    .io_regs_25(cpu_io_regs_25),
    .io_regs_26(cpu_io_regs_26),
    .io_regs_27(cpu_io_regs_27),
    .io_regs_28(cpu_io_regs_28),
    .io_regs_29(cpu_io_regs_29),
    .io_regs_30(cpu_io_regs_30),
    .io_regs_31(cpu_io_regs_31),
    .io_Hcf(cpu_io_Hcf),
    .io_DMA_Hcf(cpu_io_DMA_Hcf),
    .io_E_Branch_taken(cpu_io_E_Branch_taken),
    .io_Flush(cpu_io_Flush),
    .io_Stall_MA(cpu_io_Stall_MA),
    .io_Stall_DH(cpu_io_Stall_DH),
    .io_IF_PC(cpu_io_IF_PC),
    .io_ID_PC(cpu_io_ID_PC),
    .io_EXE_PC(cpu_io_EXE_PC),
    .io_MEM_PC(cpu_io_MEM_PC),
    .io_WB_PC(cpu_io_WB_PC),
    .io_EXE_src1(cpu_io_EXE_src1),
    .io_EXE_src2(cpu_io_EXE_src2),
    .io_ALU_src1(cpu_io_ALU_src1),
    .io_ALU_src2(cpu_io_ALU_src2),
    .io_EXE_alu_out(cpu_io_EXE_alu_out),
    .io_WB_rd(cpu_io_WB_rd),
    .io_WB_wdata(cpu_io_WB_wdata),
    .io_EXE_Jump(cpu_io_EXE_Jump),
    .io_EXE_Branch(cpu_io_EXE_Branch)
  );
  InstMem im ( // @[top_SoC.scala 77:20]
    .clock(im_clock),
    .io_raddr(im_io_raddr),
    .io_inst(im_io_inst)
  );
  AXILiteXBar bus ( // @[top_SoC.scala 79:21]
    .clock(bus_clock),
    .reset(bus_reset),
    .io_masters_0_aw_ready(bus_io_masters_0_aw_ready),
    .io_masters_0_aw_valid(bus_io_masters_0_aw_valid),
    .io_masters_0_aw_bits_addr(bus_io_masters_0_aw_bits_addr),
    .io_masters_0_w_ready(bus_io_masters_0_w_ready),
    .io_masters_0_w_valid(bus_io_masters_0_w_valid),
    .io_masters_0_w_bits_data(bus_io_masters_0_w_bits_data),
    .io_masters_0_w_bits_strb(bus_io_masters_0_w_bits_strb),
    .io_masters_0_b_ready(bus_io_masters_0_b_ready),
    .io_masters_0_b_valid(bus_io_masters_0_b_valid),
    .io_masters_0_ar_ready(bus_io_masters_0_ar_ready),
    .io_masters_0_ar_valid(bus_io_masters_0_ar_valid),
    .io_masters_0_ar_bits_addr(bus_io_masters_0_ar_bits_addr),
    .io_masters_0_r_ready(bus_io_masters_0_r_ready),
    .io_masters_0_r_valid(bus_io_masters_0_r_valid),
    .io_masters_0_r_bits_data(bus_io_masters_0_r_bits_data),
    .io_masters_1_aw_ready(bus_io_masters_1_aw_ready),
    .io_masters_1_aw_valid(bus_io_masters_1_aw_valid),
    .io_masters_1_aw_bits_id(bus_io_masters_1_aw_bits_id),
    .io_masters_1_aw_bits_addr(bus_io_masters_1_aw_bits_addr),
    .io_masters_1_aw_bits_size(bus_io_masters_1_aw_bits_size),
    .io_masters_1_w_ready(bus_io_masters_1_w_ready),
    .io_masters_1_w_valid(bus_io_masters_1_w_valid),
    .io_masters_1_w_bits_data(bus_io_masters_1_w_bits_data),
    .io_masters_1_w_bits_strb(bus_io_masters_1_w_bits_strb),
    .io_masters_1_w_bits_last(bus_io_masters_1_w_bits_last),
    .io_masters_1_b_ready(bus_io_masters_1_b_ready),
    .io_masters_1_b_valid(bus_io_masters_1_b_valid),
    .io_masters_1_b_bits_id(bus_io_masters_1_b_bits_id),
    .io_masters_1_b_bits_resp(bus_io_masters_1_b_bits_resp),
    .io_masters_1_ar_ready(bus_io_masters_1_ar_ready),
    .io_masters_1_ar_valid(bus_io_masters_1_ar_valid),
    .io_masters_1_ar_bits_id(bus_io_masters_1_ar_bits_id),
    .io_masters_1_ar_bits_addr(bus_io_masters_1_ar_bits_addr),
    .io_masters_1_ar_bits_size(bus_io_masters_1_ar_bits_size),
    .io_masters_1_r_ready(bus_io_masters_1_r_ready),
    .io_masters_1_r_valid(bus_io_masters_1_r_valid),
    .io_masters_1_r_bits_id(bus_io_masters_1_r_bits_id),
    .io_masters_1_r_bits_data(bus_io_masters_1_r_bits_data),
    .io_masters_1_r_bits_resp(bus_io_masters_1_r_bits_resp),
    .io_masters_1_r_bits_last(bus_io_masters_1_r_bits_last),
    .io_slaves_0_aw_ready(bus_io_slaves_0_aw_ready),
    .io_slaves_0_aw_valid(bus_io_slaves_0_aw_valid),
    .io_slaves_0_aw_bits_id(bus_io_slaves_0_aw_bits_id),
    .io_slaves_0_aw_bits_addr(bus_io_slaves_0_aw_bits_addr),
    .io_slaves_0_aw_bits_size(bus_io_slaves_0_aw_bits_size),
    .io_slaves_0_w_ready(bus_io_slaves_0_w_ready),
    .io_slaves_0_w_valid(bus_io_slaves_0_w_valid),
    .io_slaves_0_w_bits_data(bus_io_slaves_0_w_bits_data),
    .io_slaves_0_w_bits_strb(bus_io_slaves_0_w_bits_strb),
    .io_slaves_0_w_bits_last(bus_io_slaves_0_w_bits_last),
    .io_slaves_0_b_ready(bus_io_slaves_0_b_ready),
    .io_slaves_0_b_valid(bus_io_slaves_0_b_valid),
    .io_slaves_0_b_bits_id(bus_io_slaves_0_b_bits_id),
    .io_slaves_0_b_bits_resp(bus_io_slaves_0_b_bits_resp),
    .io_slaves_0_ar_ready(bus_io_slaves_0_ar_ready),
    .io_slaves_0_ar_valid(bus_io_slaves_0_ar_valid),
    .io_slaves_0_ar_bits_id(bus_io_slaves_0_ar_bits_id),
    .io_slaves_0_ar_bits_addr(bus_io_slaves_0_ar_bits_addr),
    .io_slaves_0_ar_bits_size(bus_io_slaves_0_ar_bits_size),
    .io_slaves_0_r_ready(bus_io_slaves_0_r_ready),
    .io_slaves_0_r_valid(bus_io_slaves_0_r_valid),
    .io_slaves_0_r_bits_id(bus_io_slaves_0_r_bits_id),
    .io_slaves_0_r_bits_data(bus_io_slaves_0_r_bits_data),
    .io_slaves_0_r_bits_resp(bus_io_slaves_0_r_bits_resp),
    .io_slaves_0_r_bits_last(bus_io_slaves_0_r_bits_last),
    .io_slaves_1_aw_ready(bus_io_slaves_1_aw_ready),
    .io_slaves_1_aw_valid(bus_io_slaves_1_aw_valid),
    .io_slaves_1_aw_bits_id(bus_io_slaves_1_aw_bits_id),
    .io_slaves_1_aw_bits_addr(bus_io_slaves_1_aw_bits_addr),
    .io_slaves_1_w_ready(bus_io_slaves_1_w_ready),
    .io_slaves_1_w_valid(bus_io_slaves_1_w_valid),
    .io_slaves_1_w_bits_data(bus_io_slaves_1_w_bits_data),
    .io_slaves_1_w_bits_strb(bus_io_slaves_1_w_bits_strb),
    .io_slaves_1_w_bits_last(bus_io_slaves_1_w_bits_last),
    .io_slaves_1_b_ready(bus_io_slaves_1_b_ready),
    .io_slaves_1_b_valid(bus_io_slaves_1_b_valid),
    .io_slaves_1_b_bits_id(bus_io_slaves_1_b_bits_id),
    .io_slaves_1_ar_ready(bus_io_slaves_1_ar_ready),
    .io_slaves_1_ar_valid(bus_io_slaves_1_ar_valid),
    .io_slaves_1_ar_bits_id(bus_io_slaves_1_ar_bits_id),
    .io_slaves_1_ar_bits_addr(bus_io_slaves_1_ar_bits_addr),
    .io_slaves_1_r_ready(bus_io_slaves_1_r_ready),
    .io_slaves_1_r_valid(bus_io_slaves_1_r_valid),
    .io_slaves_1_r_bits_id(bus_io_slaves_1_r_bits_id),
    .io_slaves_1_r_bits_data(bus_io_slaves_1_r_bits_data),
    .io_slaves_1_r_bits_last(bus_io_slaves_1_r_bits_last),
    .io_slaves_2_aw_ready(bus_io_slaves_2_aw_ready),
    .io_slaves_2_aw_valid(bus_io_slaves_2_aw_valid),
    .io_slaves_2_aw_bits_id(bus_io_slaves_2_aw_bits_id),
    .io_slaves_2_aw_bits_addr(bus_io_slaves_2_aw_bits_addr),
    .io_slaves_2_w_ready(bus_io_slaves_2_w_ready),
    .io_slaves_2_w_valid(bus_io_slaves_2_w_valid),
    .io_slaves_2_w_bits_data(bus_io_slaves_2_w_bits_data),
    .io_slaves_2_w_bits_strb(bus_io_slaves_2_w_bits_strb),
    .io_slaves_2_w_bits_last(bus_io_slaves_2_w_bits_last),
    .io_slaves_2_b_ready(bus_io_slaves_2_b_ready),
    .io_slaves_2_b_valid(bus_io_slaves_2_b_valid),
    .io_slaves_2_b_bits_id(bus_io_slaves_2_b_bits_id),
    .io_slaves_2_ar_ready(bus_io_slaves_2_ar_ready),
    .io_slaves_2_ar_valid(bus_io_slaves_2_ar_valid),
    .io_slaves_2_ar_bits_id(bus_io_slaves_2_ar_bits_id),
    .io_slaves_2_ar_bits_addr(bus_io_slaves_2_ar_bits_addr),
    .io_slaves_2_r_ready(bus_io_slaves_2_r_ready),
    .io_slaves_2_r_valid(bus_io_slaves_2_r_valid),
    .io_slaves_2_r_bits_id(bus_io_slaves_2_r_bits_id),
    .io_slaves_2_r_bits_data(bus_io_slaves_2_r_bits_data),
    .io_slaves_2_r_bits_last(bus_io_slaves_2_r_bits_last)
  );
  DataMem localMem ( // @[top_SoC.scala 94:26]
    .clock(localMem_clock),
    .reset(localMem_reset),
    .io_slave_aw_ready(localMem_io_slave_aw_ready),
    .io_slave_aw_valid(localMem_io_slave_aw_valid),
    .io_slave_aw_bits_id(localMem_io_slave_aw_bits_id),
    .io_slave_aw_bits_addr(localMem_io_slave_aw_bits_addr),
    .io_slave_w_ready(localMem_io_slave_w_ready),
    .io_slave_w_valid(localMem_io_slave_w_valid),
    .io_slave_w_bits_data(localMem_io_slave_w_bits_data),
    .io_slave_w_bits_strb(localMem_io_slave_w_bits_strb),
    .io_slave_w_bits_last(localMem_io_slave_w_bits_last),
    .io_slave_b_ready(localMem_io_slave_b_ready),
    .io_slave_b_valid(localMem_io_slave_b_valid),
    .io_slave_b_bits_id(localMem_io_slave_b_bits_id),
    .io_slave_ar_ready(localMem_io_slave_ar_ready),
    .io_slave_ar_valid(localMem_io_slave_ar_valid),
    .io_slave_ar_bits_id(localMem_io_slave_ar_bits_id),
    .io_slave_ar_bits_addr(localMem_io_slave_ar_bits_addr),
    .io_slave_r_ready(localMem_io_slave_r_ready),
    .io_slave_r_valid(localMem_io_slave_r_valid),
    .io_slave_r_bits_id(localMem_io_slave_r_bits_id),
    .io_slave_r_bits_data(localMem_io_slave_r_bits_data),
    .io_slave_r_bits_last(localMem_io_slave_r_bits_last),
    .io_dump(localMem_io_dump)
  );
  DataMem_1 globalMem ( // @[top_SoC.scala 106:27]
    .clock(globalMem_clock),
    .reset(globalMem_reset),
    .io_slave_aw_ready(globalMem_io_slave_aw_ready),
    .io_slave_aw_valid(globalMem_io_slave_aw_valid),
    .io_slave_aw_bits_id(globalMem_io_slave_aw_bits_id),
    .io_slave_aw_bits_addr(globalMem_io_slave_aw_bits_addr),
    .io_slave_w_ready(globalMem_io_slave_w_ready),
    .io_slave_w_valid(globalMem_io_slave_w_valid),
    .io_slave_w_bits_data(globalMem_io_slave_w_bits_data),
    .io_slave_w_bits_strb(globalMem_io_slave_w_bits_strb),
    .io_slave_w_bits_last(globalMem_io_slave_w_bits_last),
    .io_slave_b_ready(globalMem_io_slave_b_ready),
    .io_slave_b_valid(globalMem_io_slave_b_valid),
    .io_slave_b_bits_id(globalMem_io_slave_b_bits_id),
    .io_slave_ar_ready(globalMem_io_slave_ar_ready),
    .io_slave_ar_valid(globalMem_io_slave_ar_valid),
    .io_slave_ar_bits_id(globalMem_io_slave_ar_bits_id),
    .io_slave_ar_bits_addr(globalMem_io_slave_ar_bits_addr),
    .io_slave_r_ready(globalMem_io_slave_r_ready),
    .io_slave_r_valid(globalMem_io_slave_r_valid),
    .io_slave_r_bits_id(globalMem_io_slave_r_bits_id),
    .io_slave_r_bits_data(globalMem_io_slave_r_bits_data),
    .io_slave_r_bits_last(globalMem_io_slave_r_bits_last)
  );
  assign io_regs_0 = 32'h0; // @[top_SoC.scala 141:13]
  assign io_regs_1 = cpu_io_regs_1; // @[top_SoC.scala 141:13]
  assign io_regs_2 = cpu_io_regs_2; // @[top_SoC.scala 141:13]
  assign io_regs_3 = cpu_io_regs_3; // @[top_SoC.scala 141:13]
  assign io_regs_4 = cpu_io_regs_4; // @[top_SoC.scala 141:13]
  assign io_regs_5 = cpu_io_regs_5; // @[top_SoC.scala 141:13]
  assign io_regs_6 = cpu_io_regs_6; // @[top_SoC.scala 141:13]
  assign io_regs_7 = cpu_io_regs_7; // @[top_SoC.scala 141:13]
  assign io_regs_8 = cpu_io_regs_8; // @[top_SoC.scala 141:13]
  assign io_regs_9 = cpu_io_regs_9; // @[top_SoC.scala 141:13]
  assign io_regs_10 = cpu_io_regs_10; // @[top_SoC.scala 141:13]
  assign io_regs_11 = cpu_io_regs_11; // @[top_SoC.scala 141:13]
  assign io_regs_12 = cpu_io_regs_12; // @[top_SoC.scala 141:13]
  assign io_regs_13 = cpu_io_regs_13; // @[top_SoC.scala 141:13]
  assign io_regs_14 = cpu_io_regs_14; // @[top_SoC.scala 141:13]
  assign io_regs_15 = cpu_io_regs_15; // @[top_SoC.scala 141:13]
  assign io_regs_16 = cpu_io_regs_16; // @[top_SoC.scala 141:13]
  assign io_regs_17 = cpu_io_regs_17; // @[top_SoC.scala 141:13]
  assign io_regs_18 = cpu_io_regs_18; // @[top_SoC.scala 141:13]
  assign io_regs_19 = cpu_io_regs_19; // @[top_SoC.scala 141:13]
  assign io_regs_20 = cpu_io_regs_20; // @[top_SoC.scala 141:13]
  assign io_regs_21 = cpu_io_regs_21; // @[top_SoC.scala 141:13]
  assign io_regs_22 = cpu_io_regs_22; // @[top_SoC.scala 141:13]
  assign io_regs_23 = cpu_io_regs_23; // @[top_SoC.scala 141:13]
  assign io_regs_24 = cpu_io_regs_24; // @[top_SoC.scala 141:13]
  assign io_regs_25 = cpu_io_regs_25; // @[top_SoC.scala 141:13]
  assign io_regs_26 = cpu_io_regs_26; // @[top_SoC.scala 141:13]
  assign io_regs_27 = cpu_io_regs_27; // @[top_SoC.scala 141:13]
  assign io_regs_28 = cpu_io_regs_28; // @[top_SoC.scala 141:13]
  assign io_regs_29 = cpu_io_regs_29; // @[top_SoC.scala 141:13]
  assign io_regs_30 = cpu_io_regs_30; // @[top_SoC.scala 141:13]
  assign io_regs_31 = cpu_io_regs_31; // @[top_SoC.scala 141:13]
  assign io_Hcf = cpu_io_Hcf; // @[top_SoC.scala 142:12]
  assign io_inst = im_io_inst; // @[top_SoC.scala 143:13]
  assign io_rdata = cpu_io_master_r_bits_data; // @[top_SoC.scala 144:14]
  assign io_wdata = cpu_io_master_w_bits_data; // @[top_SoC.scala 145:14]
  assign io_E_Branch_taken = cpu_io_E_Branch_taken; // @[top_SoC.scala 155:23]
  assign io_Flush = cpu_io_Flush; // @[top_SoC.scala 156:14]
  assign io_Stall_MA = cpu_io_Stall_MA; // @[top_SoC.scala 157:17]
  assign io_Stall_DH = cpu_io_Stall_DH; // @[top_SoC.scala 158:17]
  assign io_IF_PC = cpu_io_IF_PC; // @[top_SoC.scala 159:14]
  assign io_ID_PC = cpu_io_ID_PC; // @[top_SoC.scala 160:14]
  assign io_EXE_PC = cpu_io_EXE_PC; // @[top_SoC.scala 161:15]
  assign io_MEM_PC = cpu_io_MEM_PC; // @[top_SoC.scala 162:15]
  assign io_WB_PC = cpu_io_WB_PC; // @[top_SoC.scala 163:14]
  assign io_EXE_alu_out = cpu_io_EXE_alu_out; // @[top_SoC.scala 164:20]
  assign io_EXE_src1 = cpu_io_EXE_src1; // @[top_SoC.scala 165:17]
  assign io_EXE_src2 = cpu_io_EXE_src2; // @[top_SoC.scala 166:17]
  assign io_ALU_src1 = cpu_io_ALU_src1; // @[top_SoC.scala 167:17]
  assign io_ALU_src2 = cpu_io_ALU_src2; // @[top_SoC.scala 168:17]
  assign io_raddr = cpu_io_DataMem_raddr; // @[top_SoC.scala 169:14]
  assign io_WB_rd = cpu_io_WB_rd; // @[top_SoC.scala 170:14]
  assign io_WB_wdata = cpu_io_WB_wdata; // @[top_SoC.scala 171:17]
  assign io_EXE_Jump = cpu_io_EXE_Jump; // @[top_SoC.scala 172:17]
  assign io_EXE_Branch = cpu_io_EXE_Branch; // @[top_SoC.scala 173:19]
  assign io_DMA_Hcf = dma_io_Hcf; // @[top_SoC.scala 140:16]
  assign dma_clock = clock;
  assign dma_reset = reset;
  assign dma_io_slave_aw_valid = bus_io_slaves_0_aw_valid; // @[top_SoC.scala 125:22]
  assign dma_io_slave_aw_bits_id = bus_io_slaves_0_aw_bits_id; // @[top_SoC.scala 125:22]
  assign dma_io_slave_aw_bits_addr = bus_io_slaves_0_aw_bits_addr; // @[top_SoC.scala 125:22]
  assign dma_io_slave_aw_bits_region = 4'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_aw_bits_len = 8'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_aw_bits_size = bus_io_slaves_0_aw_bits_size; // @[top_SoC.scala 125:22]
  assign dma_io_slave_aw_bits_burst = 2'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_aw_bits_lock = 1'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_aw_bits_cache = 4'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_aw_bits_prot = 3'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_aw_bits_qos = 4'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_w_valid = bus_io_slaves_0_w_valid; // @[top_SoC.scala 125:22]
  assign dma_io_slave_w_bits_data = bus_io_slaves_0_w_bits_data; // @[top_SoC.scala 125:22]
  assign dma_io_slave_w_bits_strb = bus_io_slaves_0_w_bits_strb; // @[top_SoC.scala 125:22]
  assign dma_io_slave_w_bits_last = bus_io_slaves_0_w_bits_last; // @[top_SoC.scala 125:22]
  assign dma_io_slave_b_ready = bus_io_slaves_0_b_ready; // @[top_SoC.scala 125:22]
  assign dma_io_slave_ar_valid = bus_io_slaves_0_ar_valid; // @[top_SoC.scala 125:22]
  assign dma_io_slave_ar_bits_id = bus_io_slaves_0_ar_bits_id; // @[top_SoC.scala 125:22]
  assign dma_io_slave_ar_bits_addr = bus_io_slaves_0_ar_bits_addr; // @[top_SoC.scala 125:22]
  assign dma_io_slave_ar_bits_region = 4'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_ar_bits_len = 8'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_ar_bits_size = bus_io_slaves_0_ar_bits_size; // @[top_SoC.scala 125:22]
  assign dma_io_slave_ar_bits_burst = 2'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_ar_bits_lock = 1'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_ar_bits_cache = 4'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_ar_bits_prot = 3'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_ar_bits_qos = 4'h0; // @[top_SoC.scala 125:22]
  assign dma_io_slave_r_ready = bus_io_slaves_0_r_ready; // @[top_SoC.scala 125:22]
  assign dma_io_master_aw_ready = bus_io_masters_1_aw_ready; // @[top_SoC.scala 123:23]
  assign dma_io_master_w_ready = bus_io_masters_1_w_ready; // @[top_SoC.scala 123:23]
  assign dma_io_master_b_valid = bus_io_masters_1_b_valid; // @[top_SoC.scala 123:23]
  assign dma_io_master_b_bits_id = bus_io_masters_1_b_bits_id; // @[top_SoC.scala 123:23]
  assign dma_io_master_b_bits_resp = bus_io_masters_1_b_bits_resp; // @[top_SoC.scala 123:23]
  assign dma_io_master_ar_ready = bus_io_masters_1_ar_ready; // @[top_SoC.scala 123:23]
  assign dma_io_master_r_valid = bus_io_masters_1_r_valid; // @[top_SoC.scala 123:23]
  assign dma_io_master_r_bits_id = bus_io_masters_1_r_bits_id; // @[top_SoC.scala 123:23]
  assign dma_io_master_r_bits_data = bus_io_masters_1_r_bits_data; // @[top_SoC.scala 123:23]
  assign dma_io_master_r_bits_resp = bus_io_masters_1_r_bits_resp; // @[top_SoC.scala 123:23]
  assign dma_io_master_r_bits_last = bus_io_masters_1_r_bits_last; // @[top_SoC.scala 123:23]
  assign cpu_clock = clock;
  assign cpu_reset = reset;
  assign cpu_io_InstMem_rdata = im_io_inst; // @[top_SoC.scala 137:26]
  assign cpu_io_master_aw_ready = bus_io_masters_0_aw_ready; // @[top_SoC.scala 122:23]
  assign cpu_io_master_w_ready = bus_io_masters_0_w_ready; // @[top_SoC.scala 122:23]
  assign cpu_io_master_b_valid = bus_io_masters_0_b_valid; // @[top_SoC.scala 122:23]
  assign cpu_io_master_ar_ready = bus_io_masters_0_ar_ready; // @[top_SoC.scala 122:23]
  assign cpu_io_master_r_valid = bus_io_masters_0_r_valid; // @[top_SoC.scala 122:23]
  assign cpu_io_master_r_bits_data = bus_io_masters_0_r_bits_data; // @[top_SoC.scala 122:23]
  assign cpu_io_DMA_Hcf = dma_io_Hcf; // @[top_SoC.scala 146:20]
  assign im_clock = clock;
  assign im_io_raddr = cpu_io_InstMem_raddr; // @[top_SoC.scala 136:17]
  assign bus_clock = clock;
  assign bus_reset = reset;
  assign bus_io_masters_0_aw_valid = cpu_io_master_aw_valid; // @[top_SoC.scala 122:23]
  assign bus_io_masters_0_aw_bits_addr = cpu_io_master_aw_bits_addr; // @[top_SoC.scala 122:23]
  assign bus_io_masters_0_w_valid = cpu_io_master_w_valid; // @[top_SoC.scala 122:23]
  assign bus_io_masters_0_w_bits_data = cpu_io_master_w_bits_data; // @[top_SoC.scala 122:23]
  assign bus_io_masters_0_w_bits_strb = cpu_io_master_w_bits_strb; // @[top_SoC.scala 122:23]
  assign bus_io_masters_0_b_ready = cpu_io_master_b_ready; // @[top_SoC.scala 122:23]
  assign bus_io_masters_0_ar_valid = cpu_io_master_ar_valid; // @[top_SoC.scala 122:23]
  assign bus_io_masters_0_ar_bits_addr = cpu_io_master_ar_bits_addr; // @[top_SoC.scala 122:23]
  assign bus_io_masters_0_r_ready = cpu_io_master_r_ready; // @[top_SoC.scala 122:23]
  assign bus_io_masters_1_aw_valid = dma_io_master_aw_valid; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_aw_bits_id = dma_io_master_aw_bits_id; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_aw_bits_addr = dma_io_master_aw_bits_addr; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_aw_bits_size = dma_io_master_aw_bits_size; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_w_valid = dma_io_master_w_valid; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_w_bits_data = dma_io_master_w_bits_data; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_w_bits_strb = dma_io_master_w_bits_strb; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_w_bits_last = dma_io_master_w_bits_last; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_b_ready = dma_io_master_b_ready; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_ar_valid = dma_io_master_ar_valid; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_ar_bits_id = dma_io_master_ar_bits_id; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_ar_bits_addr = dma_io_master_ar_bits_addr; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_ar_bits_size = dma_io_master_ar_bits_size; // @[top_SoC.scala 123:23]
  assign bus_io_masters_1_r_ready = dma_io_master_r_ready; // @[top_SoC.scala 123:23]
  assign bus_io_slaves_0_aw_ready = dma_io_slave_aw_ready; // @[top_SoC.scala 125:22]
  assign bus_io_slaves_0_w_ready = dma_io_slave_w_ready; // @[top_SoC.scala 125:22]
  assign bus_io_slaves_0_b_valid = dma_io_slave_b_valid; // @[top_SoC.scala 125:22]
  assign bus_io_slaves_0_b_bits_id = dma_io_slave_b_bits_id; // @[top_SoC.scala 125:22]
  assign bus_io_slaves_0_b_bits_resp = dma_io_slave_b_bits_resp; // @[top_SoC.scala 125:22]
  assign bus_io_slaves_0_ar_ready = dma_io_slave_ar_ready; // @[top_SoC.scala 125:22]
  assign bus_io_slaves_0_r_valid = dma_io_slave_r_valid; // @[top_SoC.scala 125:22]
  assign bus_io_slaves_0_r_bits_id = dma_io_slave_r_bits_id; // @[top_SoC.scala 125:22]
  assign bus_io_slaves_0_r_bits_data = dma_io_slave_r_bits_data; // @[top_SoC.scala 125:22]
  assign bus_io_slaves_0_r_bits_resp = dma_io_slave_r_bits_resp; // @[top_SoC.scala 125:22]
  assign bus_io_slaves_0_r_bits_last = dma_io_slave_r_bits_last; // @[top_SoC.scala 125:22]
  assign bus_io_slaves_1_aw_ready = localMem_io_slave_aw_ready; // @[top_SoC.scala 126:22]
  assign bus_io_slaves_1_w_ready = localMem_io_slave_w_ready; // @[top_SoC.scala 126:22]
  assign bus_io_slaves_1_b_valid = localMem_io_slave_b_valid; // @[top_SoC.scala 126:22]
  assign bus_io_slaves_1_b_bits_id = localMem_io_slave_b_bits_id; // @[top_SoC.scala 126:22]
  assign bus_io_slaves_1_ar_ready = localMem_io_slave_ar_ready; // @[top_SoC.scala 126:22]
  assign bus_io_slaves_1_r_valid = localMem_io_slave_r_valid; // @[top_SoC.scala 126:22]
  assign bus_io_slaves_1_r_bits_id = localMem_io_slave_r_bits_id; // @[top_SoC.scala 126:22]
  assign bus_io_slaves_1_r_bits_data = localMem_io_slave_r_bits_data; // @[top_SoC.scala 126:22]
  assign bus_io_slaves_1_r_bits_last = localMem_io_slave_r_bits_last; // @[top_SoC.scala 126:22]
  assign bus_io_slaves_2_aw_ready = globalMem_io_slave_aw_ready; // @[top_SoC.scala 127:22]
  assign bus_io_slaves_2_w_ready = globalMem_io_slave_w_ready; // @[top_SoC.scala 127:22]
  assign bus_io_slaves_2_b_valid = globalMem_io_slave_b_valid; // @[top_SoC.scala 127:22]
  assign bus_io_slaves_2_b_bits_id = globalMem_io_slave_b_bits_id; // @[top_SoC.scala 127:22]
  assign bus_io_slaves_2_ar_ready = globalMem_io_slave_ar_ready; // @[top_SoC.scala 127:22]
  assign bus_io_slaves_2_r_valid = globalMem_io_slave_r_valid; // @[top_SoC.scala 127:22]
  assign bus_io_slaves_2_r_bits_id = globalMem_io_slave_r_bits_id; // @[top_SoC.scala 127:22]
  assign bus_io_slaves_2_r_bits_data = globalMem_io_slave_r_bits_data; // @[top_SoC.scala 127:22]
  assign bus_io_slaves_2_r_bits_last = globalMem_io_slave_r_bits_last; // @[top_SoC.scala 127:22]
  assign localMem_clock = clock;
  assign localMem_reset = reset;
  assign localMem_io_slave_aw_valid = bus_io_slaves_1_aw_valid; // @[top_SoC.scala 126:22]
  assign localMem_io_slave_aw_bits_id = bus_io_slaves_1_aw_bits_id; // @[top_SoC.scala 126:22]
  assign localMem_io_slave_aw_bits_addr = bus_io_slaves_1_aw_bits_addr; // @[top_SoC.scala 126:22]
  assign localMem_io_slave_w_valid = bus_io_slaves_1_w_valid; // @[top_SoC.scala 126:22]
  assign localMem_io_slave_w_bits_data = bus_io_slaves_1_w_bits_data; // @[top_SoC.scala 126:22]
  assign localMem_io_slave_w_bits_strb = bus_io_slaves_1_w_bits_strb; // @[top_SoC.scala 126:22]
  assign localMem_io_slave_w_bits_last = bus_io_slaves_1_w_bits_last; // @[top_SoC.scala 126:22]
  assign localMem_io_slave_b_ready = bus_io_slaves_1_b_ready; // @[top_SoC.scala 126:22]
  assign localMem_io_slave_ar_valid = bus_io_slaves_1_ar_valid; // @[top_SoC.scala 126:22]
  assign localMem_io_slave_ar_bits_id = bus_io_slaves_1_ar_bits_id; // @[top_SoC.scala 126:22]
  assign localMem_io_slave_ar_bits_addr = bus_io_slaves_1_ar_bits_addr; // @[top_SoC.scala 126:22]
  assign localMem_io_slave_r_ready = bus_io_slaves_1_r_ready; // @[top_SoC.scala 126:22]
  assign localMem_io_dump = io_Dump_Mem; // @[top_SoC.scala 131:22]
  assign globalMem_clock = clock;
  assign globalMem_reset = reset;
  assign globalMem_io_slave_aw_valid = bus_io_slaves_2_aw_valid; // @[top_SoC.scala 127:22]
  assign globalMem_io_slave_aw_bits_id = bus_io_slaves_2_aw_bits_id; // @[top_SoC.scala 127:22]
  assign globalMem_io_slave_aw_bits_addr = bus_io_slaves_2_aw_bits_addr; // @[top_SoC.scala 127:22]
  assign globalMem_io_slave_w_valid = bus_io_slaves_2_w_valid; // @[top_SoC.scala 127:22]
  assign globalMem_io_slave_w_bits_data = bus_io_slaves_2_w_bits_data; // @[top_SoC.scala 127:22]
  assign globalMem_io_slave_w_bits_strb = bus_io_slaves_2_w_bits_strb; // @[top_SoC.scala 127:22]
  assign globalMem_io_slave_w_bits_last = bus_io_slaves_2_w_bits_last; // @[top_SoC.scala 127:22]
  assign globalMem_io_slave_b_ready = bus_io_slaves_2_b_ready; // @[top_SoC.scala 127:22]
  assign globalMem_io_slave_ar_valid = bus_io_slaves_2_ar_valid; // @[top_SoC.scala 127:22]
  assign globalMem_io_slave_ar_bits_id = bus_io_slaves_2_ar_bits_id; // @[top_SoC.scala 127:22]
  assign globalMem_io_slave_ar_bits_addr = bus_io_slaves_2_ar_bits_addr; // @[top_SoC.scala 127:22]
  assign globalMem_io_slave_r_ready = bus_io_slaves_2_r_ready; // @[top_SoC.scala 127:22]
endmodule
