circuit AXILiteXBar :
  module AXIReadBus :
    input clock : Clock
    input reset : UInt<1>
    output io_master_readAddr_ready : UInt<1>
    input io_master_readAddr_valid : UInt<1>
    input io_master_readAddr_bits_id : UInt<4>
    input io_master_readAddr_bits_addr : UInt<32>
    input io_master_readAddr_bits_region : UInt<4>
    input io_master_readAddr_bits_len : UInt<8>
    input io_master_readAddr_bits_size : UInt<2>
    input io_master_readAddr_bits_burst : UInt<2>
    input io_master_readAddr_bits_lock : UInt<1>
    input io_master_readAddr_bits_cache : UInt<4>
    input io_master_readAddr_bits_prot : UInt<3>
    input io_master_readAddr_bits_qos : UInt<4>
    input io_master_readData_ready : UInt<1>
    output io_master_readData_valid : UInt<1>
    output io_master_readData_bits_id : UInt<4>
    output io_master_readData_bits_data : UInt<32>
    output io_master_readData_bits_resp : UInt<2>
    output io_master_readData_bits_last : UInt<1>
    input io_slave_0_readAddr_ready : UInt<1>
    output io_slave_0_readAddr_valid : UInt<1>
    output io_slave_0_readAddr_bits_id : UInt<4>
    output io_slave_0_readAddr_bits_addr : UInt<32>
    output io_slave_0_readAddr_bits_region : UInt<4>
    output io_slave_0_readAddr_bits_len : UInt<8>
    output io_slave_0_readAddr_bits_size : UInt<2>
    output io_slave_0_readAddr_bits_burst : UInt<2>
    output io_slave_0_readAddr_bits_lock : UInt<1>
    output io_slave_0_readAddr_bits_cache : UInt<4>
    output io_slave_0_readAddr_bits_prot : UInt<3>
    output io_slave_0_readAddr_bits_qos : UInt<4>
    output io_slave_0_readData_ready : UInt<1>
    input io_slave_0_readData_valid : UInt<1>
    input io_slave_0_readData_bits_id : UInt<4>
    input io_slave_0_readData_bits_data : UInt<32>
    input io_slave_0_readData_bits_resp : UInt<2>
    input io_slave_0_readData_bits_last : UInt<1>

    node _read_port_T = geq(io_master_readAddr_bits_addr, UInt<16>("h8000")) @[AXIReadBus.scala 26:35]
    node _read_port_T_1 = lt(io_master_readAddr_bits_addr, UInt<17>("h18000")) @[AXIReadBus.scala 26:85]
    node _read_port_T_2 = and(_read_port_T, _read_port_T_1) @[AXIReadBus.scala 26:53]
    node read_port = mux(_read_port_T_2, UInt<1>("h0"), UInt<1>("h0")) @[Mux.scala 101:16]
    reg read_port_reg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), read_port_reg) @[AXIReadBus.scala 28:30]
    reg read_addr_reg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), read_addr_reg) @[AXIReadBus.scala 29:30]
    reg read_addr_reg_id : UInt<4>, clock with :
      reset => (UInt<1>("h0"), read_addr_reg_id) @[AXIReadBus.scala 30:33]
    reg read_addr_reg_size : UInt<3>, clock with :
      reset => (UInt<1>("h0"), read_addr_reg_size) @[AXIReadBus.scala 31:35]
    reg read_addr_reg_valid : UInt<1>, clock with :
      reset => (UInt<1>("h0"), read_addr_reg_valid) @[AXIReadBus.scala 32:36]
    reg outstanding : UInt<1>, clock with :
      reset => (UInt<1>("h0"), outstanding) @[AXIReadBus.scala 33:28]
    node _io_master_readAddr_ready_T = not(outstanding) @[AXIReadBus.scala 63:31]
    node _T = and(io_master_readAddr_ready, io_master_readAddr_valid) @[Decoupled.scala 52:35]
    node _GEN_0 = mux(_T, UInt<1>("h1"), outstanding) @[AXIReadBus.scala 66:33 67:17 33:28]
    node _GEN_1 = mux(_T, read_port, read_port_reg) @[AXIReadBus.scala 66:33 68:19 28:30]
    node _GEN_2 = mux(_T, io_master_readAddr_bits_addr, read_addr_reg) @[AXIReadBus.scala 66:33 69:19 29:30]
    node _GEN_3 = mux(_T, io_master_readAddr_bits_id, read_addr_reg_id) @[AXIReadBus.scala 66:33 70:22 30:33]
    node _GEN_4 = mux(_T, io_master_readAddr_bits_size, read_addr_reg_size) @[AXIReadBus.scala 66:33 71:24 31:35]
    node _GEN_5 = mux(_T, UInt<1>("h1"), read_addr_reg_valid) @[AXIReadBus.scala 66:33 72:25 32:36]
    node _GEN_6 = mux(io_slave_0_readAddr_ready, UInt<1>("h0"), _GEN_5) @[AXIReadBus.scala 82:50 83:27]
    node _GEN_7 = mux(read_addr_reg_valid, _GEN_6, _GEN_5) @[AXIReadBus.scala 81:29]
    node _T_1 = and(io_master_readData_ready, io_master_readData_valid) @[Decoupled.scala 52:35]
    node _GEN_8 = mux(_T_1, UInt<1>("h0"), _GEN_0) @[AXIReadBus.scala 105:35 106:19]
    node _GEN_9 = mux(outstanding, io_slave_0_readData_valid, UInt<1>("h0")) @[AXIReadBus.scala 88:21 58:28 89:30]
    node _GEN_10 = mux(outstanding, io_slave_0_readData_bits_data, UInt<1>("h0")) @[AXIReadBus.scala 88:21 59:32 90:34]
    node _GEN_11 = mux(outstanding, io_slave_0_readData_bits_resp, UInt<1>("h0")) @[AXIReadBus.scala 88:21 60:32 91:34]
    node _GEN_12 = mux(outstanding, io_slave_0_readData_bits_last, UInt<1>("h0")) @[AXIReadBus.scala 88:21 62:32 92:34]
    node _GEN_13 = validif(outstanding, io_slave_0_readData_bits_id) @[AXIReadBus.scala 88:21 93:32]
    node _GEN_14 = mux(outstanding, read_addr_reg, UInt<1>("h0")) @[AXIReadBus.scala 88:21 45:36 94:48]
    node _GEN_15 = mux(outstanding, read_addr_reg_valid, UInt<1>("h0")) @[AXIReadBus.scala 88:21 44:32 95:44]
    node _GEN_16 = mux(outstanding, io_master_readData_ready, UInt<1>("h0")) @[AXIReadBus.scala 88:21 55:32 96:44]
    node _GEN_17 = mux(outstanding, read_addr_reg_size, UInt<1>("h0")) @[AXIReadBus.scala 88:21 49:36 97:48]
    node _GEN_18 = mux(outstanding, read_addr_reg_id, UInt<1>("h0")) @[AXIReadBus.scala 88:21 46:34 98:46]
    node _GEN_19 = mux(outstanding, _GEN_8, _GEN_0) @[AXIReadBus.scala 88:21]
    io_master_readAddr_ready <= _io_master_readAddr_ready_T @[AXIReadBus.scala 63:28]
    io_master_readData_valid <= _GEN_9
    io_master_readData_bits_id <= _GEN_13
    io_master_readData_bits_data <= _GEN_10
    io_master_readData_bits_resp <= _GEN_11
    io_master_readData_bits_last <= _GEN_12
    io_slave_0_readAddr_valid <= _GEN_15
    io_slave_0_readAddr_bits_id <= _GEN_18
    io_slave_0_readAddr_bits_addr <= _GEN_14
    io_slave_0_readAddr_bits_region is invalid
    io_slave_0_readAddr_bits_len <= UInt<8>("h0") @[AXIReadBus.scala 48:35]
    io_slave_0_readAddr_bits_size <= bits(_GEN_17, 1, 0)
    io_slave_0_readAddr_bits_burst <= UInt<2>("h0") @[AXIReadBus.scala 50:37]
    io_slave_0_readAddr_bits_lock is invalid
    io_slave_0_readAddr_bits_cache is invalid
    io_slave_0_readAddr_bits_prot is invalid
    io_slave_0_readAddr_bits_qos is invalid
    io_slave_0_readData_ready <= _GEN_16
    read_port_reg <= mux(reset, UInt<1>("h0"), _GEN_1) @[AXIReadBus.scala 28:{30,30}]
    read_addr_reg <= mux(reset, UInt<32>("h0"), _GEN_2) @[AXIReadBus.scala 29:{30,30}]
    read_addr_reg_id <= mux(reset, UInt<4>("h0"), _GEN_3) @[AXIReadBus.scala 30:{33,33}]
    read_addr_reg_size <= mux(reset, UInt<3>("h0"), _GEN_4) @[AXIReadBus.scala 31:{35,35}]
    read_addr_reg_valid <= mux(reset, UInt<1>("h0"), _GEN_7) @[AXIReadBus.scala 32:{36,36}]
    outstanding <= mux(reset, UInt<1>("h0"), _GEN_19) @[AXIReadBus.scala 33:{28,28}]

  module RRArbiter :
    input clock : Clock
    input reset : UInt<1>
    output io_in_0_ready : UInt<1>
    input io_in_0_valid : UInt<1>
    input io_in_0_bits : UInt<1>
    input io_out_ready : UInt<1>
    output io_out_valid : UInt<1>
    output io_out_bits : UInt<1>

    node _ctrl_validMask_grantMask_lastGrant_T = and(io_out_ready, io_out_valid) @[Decoupled.scala 52:35]
    node grantMask_0 = gt(UInt<1>("h0"), UInt<1>("h0")) @[Arbiter.scala 81:49]
    node validMask_0 = and(io_in_0_valid, grantMask_0) @[Arbiter.scala 82:76]
    node ctrl_1 = eq(validMask_0, UInt<1>("h0")) @[Arbiter.scala 45:78]
    node _T = and(UInt<1>("h1"), grantMask_0) @[Arbiter.scala 86:34]
    node _T_1 = or(_T, ctrl_1) @[Arbiter.scala 86:50]
    node _io_in_0_ready_T = and(_T_1, io_out_ready) @[Arbiter.scala 74:21]
    node choice = UInt<1>("h0")
    io_in_0_ready <= _io_in_0_ready_T @[Arbiter.scala 74:16]
    io_out_valid <= io_in_0_valid @[Arbiter.scala 55:16]
    io_out_bits <= io_in_0_bits @[Arbiter.scala 56:15]

  module AXISlaveReadMux :
    input clock : Clock
    input reset : UInt<1>
    input io_out_readAddr_ready : UInt<1>
    output io_out_readAddr_valid : UInt<1>
    output io_out_readAddr_bits_id : UInt<4>
    output io_out_readAddr_bits_addr : UInt<32>
    output io_out_readAddr_bits_region : UInt<4>
    output io_out_readAddr_bits_len : UInt<8>
    output io_out_readAddr_bits_size : UInt<2>
    output io_out_readAddr_bits_burst : UInt<2>
    output io_out_readAddr_bits_lock : UInt<1>
    output io_out_readAddr_bits_cache : UInt<4>
    output io_out_readAddr_bits_prot : UInt<3>
    output io_out_readAddr_bits_qos : UInt<4>
    output io_out_readData_ready : UInt<1>
    input io_out_readData_valid : UInt<1>
    input io_out_readData_bits_id : UInt<4>
    input io_out_readData_bits_data : UInt<32>
    input io_out_readData_bits_resp : UInt<2>
    input io_out_readData_bits_last : UInt<1>
    output io_in_0_readAddr_ready : UInt<1>
    input io_in_0_readAddr_valid : UInt<1>
    input io_in_0_readAddr_bits_id : UInt<4>
    input io_in_0_readAddr_bits_addr : UInt<32>
    input io_in_0_readAddr_bits_region : UInt<4>
    input io_in_0_readAddr_bits_len : UInt<8>
    input io_in_0_readAddr_bits_size : UInt<2>
    input io_in_0_readAddr_bits_burst : UInt<2>
    input io_in_0_readAddr_bits_lock : UInt<1>
    input io_in_0_readAddr_bits_cache : UInt<4>
    input io_in_0_readAddr_bits_prot : UInt<3>
    input io_in_0_readAddr_bits_qos : UInt<4>
    input io_in_0_readData_ready : UInt<1>
    output io_in_0_readData_valid : UInt<1>
    output io_in_0_readData_bits_id : UInt<4>
    output io_in_0_readData_bits_data : UInt<32>
    output io_in_0_readData_bits_resp : UInt<2>
    output io_in_0_readData_bits_last : UInt<1>

    inst arbiter of RRArbiter @[AXISlaveReadMux.scala 35:23]
    reg state : UInt<2>, clock with :
      reset => (UInt<1>("h0"), state) @[AXISlaveReadMux.scala 30:22]
    reg chosen_reg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), chosen_reg) @[AXISlaveReadMux.scala 36:27]
    reg ar_determined : UInt<1>, clock with :
      reset => (UInt<1>("h0"), ar_determined) @[AXISlaveReadMux.scala 37:30]
    reg address_reg_id : UInt<4>, clock with :
      reset => (UInt<1>("h0"), address_reg_id) @[AXISlaveReadMux.scala 38:28]
    reg address_reg_addr : UInt<32>, clock with :
      reset => (UInt<1>("h0"), address_reg_addr) @[AXISlaveReadMux.scala 38:28]
    reg address_reg_region : UInt<4>, clock with :
      reset => (UInt<1>("h0"), address_reg_region) @[AXISlaveReadMux.scala 38:28]
    reg address_reg_len : UInt<8>, clock with :
      reset => (UInt<1>("h0"), address_reg_len) @[AXISlaveReadMux.scala 38:28]
    reg address_reg_size : UInt<2>, clock with :
      reset => (UInt<1>("h0"), address_reg_size) @[AXISlaveReadMux.scala 38:28]
    reg address_reg_burst : UInt<2>, clock with :
      reset => (UInt<1>("h0"), address_reg_burst) @[AXISlaveReadMux.scala 38:28]
    reg address_reg_lock : UInt<1>, clock with :
      reset => (UInt<1>("h0"), address_reg_lock) @[AXISlaveReadMux.scala 38:28]
    reg address_reg_cache : UInt<4>, clock with :
      reset => (UInt<1>("h0"), address_reg_cache) @[AXISlaveReadMux.scala 38:28]
    reg address_reg_prot : UInt<3>, clock with :
      reset => (UInt<1>("h0"), address_reg_prot) @[AXISlaveReadMux.scala 38:28]
    reg address_reg_qos : UInt<4>, clock with :
      reset => (UInt<1>("h0"), address_reg_qos) @[AXISlaveReadMux.scala 38:28]
    reg data_reg_id : UInt<4>, clock with :
      reset => (UInt<1>("h0"), data_reg_id) @[AXISlaveReadMux.scala 43:25]
    reg data_reg_data : UInt<32>, clock with :
      reset => (UInt<1>("h0"), data_reg_data) @[AXISlaveReadMux.scala 43:25]
    reg data_reg_resp : UInt<2>, clock with :
      reset => (UInt<1>("h0"), data_reg_resp) @[AXISlaveReadMux.scala 43:25]
    reg data_reg_last : UInt<1>, clock with :
      reset => (UInt<1>("h0"), data_reg_last) @[AXISlaveReadMux.scala 43:25]
    node _T_5 = eq(state, UInt<2>("h0")) @[AXISlaveReadMux.scala 97:14]
    node _T_6 = eq(state, UInt<2>("h1")) @[AXISlaveReadMux.scala 106:19]
    node _T_9 = eq(state, UInt<2>("h2")) @[AXISlaveReadMux.scala 116:19]
    node _mask_WIRE_0 = UInt<1>("h1") @[AXISlaveReadMux.scala 24:{33,33}]
    node _GEN_23 = mux(_T_9, UInt<1>("h0"), _mask_WIRE_0) @[AXISlaveReadMux.scala 116:31 117:20]
    node _GEN_25 = mux(_T_6, UInt<1>("h0"), _GEN_23) @[AXISlaveReadMux.scala 106:33 107:22]
    node _GEN_33 = mux(_T_5, UInt<1>("h1"), _GEN_25) @[AXISlaveReadMux.scala 97:24 98:20]
    node mask_0 = _GEN_33
    node _io_in_0_readAddr_ready_T = and(arbiter.io_in_0_ready, mask_0) @[AXISlaveReadMux.scala 72:55]
    node _arbiter_io_in_0_valid_T = and(io_in_0_readAddr_valid, mask_0) @[AXISlaveReadMux.scala 73:55]
    node _T = eq(UInt<2>("h0"), state) @[AXISlaveReadMux.scala 79:16]
    node outstanding = io_in_0_readAddr_valid
    node _GEN_0 = mux(outstanding, UInt<2>("h1"), state) @[AXISlaveReadMux.scala 81:24 82:15 30:22]
    node _T_1 = eq(UInt<2>("h1"), state) @[AXISlaveReadMux.scala 79:16]
    node _T_2 = and(io_out_readData_ready, io_out_readData_valid) @[Decoupled.scala 52:35]
    node _GEN_1 = mux(_T_2, UInt<2>("h2"), state) @[AXISlaveReadMux.scala 86:33 87:15 30:22]
    node _T_3 = eq(UInt<2>("h2"), state) @[AXISlaveReadMux.scala 79:16]
    node _T_4 = and(io_in_0_readData_ready, io_in_0_readData_valid) @[Decoupled.scala 52:35]
    node _GEN_2 = mux(_T_4, UInt<2>("h0"), state) @[AXISlaveReadMux.scala 91:44 92:15 30:22]
    node _GEN_3 = mux(_T_3, _GEN_2, state) @[AXISlaveReadMux.scala 79:16 30:22]
    node _GEN_4 = mux(_T_1, _GEN_1, _GEN_3) @[AXISlaveReadMux.scala 79:16]
    node _GEN_5 = mux(_T, _GEN_0, _GEN_4) @[AXISlaveReadMux.scala 79:16]
    node _GEN_6 = mux(arbiter.io_out_valid, UInt<1>("h0"), chosen_reg) @[AXISlaveReadMux.scala 100:18 36:27 99:31]
    node _GEN_7 = mux(arbiter.io_out_valid, io_in_0_readAddr_bits_id, address_reg_id) @[AXISlaveReadMux.scala 101:19 38:28 99:31]
    node _GEN_8 = mux(arbiter.io_out_valid, io_in_0_readAddr_bits_addr, address_reg_addr) @[AXISlaveReadMux.scala 101:19 38:28 99:31]
    node _GEN_9 = mux(arbiter.io_out_valid, io_in_0_readAddr_bits_region, address_reg_region) @[AXISlaveReadMux.scala 101:19 38:28 99:31]
    node _GEN_10 = mux(arbiter.io_out_valid, io_in_0_readAddr_bits_len, address_reg_len) @[AXISlaveReadMux.scala 101:19 38:28 99:31]
    node _GEN_11 = mux(arbiter.io_out_valid, io_in_0_readAddr_bits_size, address_reg_size) @[AXISlaveReadMux.scala 101:19 38:28 99:31]
    node _GEN_12 = mux(arbiter.io_out_valid, io_in_0_readAddr_bits_burst, address_reg_burst) @[AXISlaveReadMux.scala 101:19 38:28 99:31]
    node _GEN_13 = mux(arbiter.io_out_valid, io_in_0_readAddr_bits_lock, address_reg_lock) @[AXISlaveReadMux.scala 101:19 38:28 99:31]
    node _GEN_14 = mux(arbiter.io_out_valid, io_in_0_readAddr_bits_cache, address_reg_cache) @[AXISlaveReadMux.scala 101:19 38:28 99:31]
    node _GEN_15 = mux(arbiter.io_out_valid, io_in_0_readAddr_bits_prot, address_reg_prot) @[AXISlaveReadMux.scala 101:19 38:28 99:31]
    node _GEN_16 = mux(arbiter.io_out_valid, io_in_0_readAddr_bits_qos, address_reg_qos) @[AXISlaveReadMux.scala 101:19 38:28 99:31]
    node _GEN_17 = mux(arbiter.io_out_valid, UInt<1>("h1"), ar_determined) @[AXISlaveReadMux.scala 102:21 37:30 99:31]
    node _T_7 = and(io_out_readAddr_ready, io_out_readAddr_valid) @[Decoupled.scala 52:35]
    node _GEN_18 = mux(_T_7, UInt<1>("h0"), ar_determined) @[AXISlaveReadMux.scala 108:33 109:23 37:30]
    node _T_8 = and(io_out_readData_ready, io_out_readData_valid) @[Decoupled.scala 52:35]
    node _GEN_19 = mux(_T_8, io_out_readData_bits_id, data_reg_id) @[AXISlaveReadMux.scala 111:33 112:18 43:25]
    node _GEN_20 = mux(_T_8, io_out_readData_bits_data, data_reg_data) @[AXISlaveReadMux.scala 111:33 112:18 43:25]
    node _GEN_21 = mux(_T_8, io_out_readData_bits_resp, data_reg_resp) @[AXISlaveReadMux.scala 111:33 112:18 43:25]
    node _GEN_22 = mux(_T_8, io_out_readData_bits_last, data_reg_last) @[AXISlaveReadMux.scala 111:33 112:18 43:25]
    node _GEN_24 = mux(_T_9, UInt<1>("h1"), UInt<1>("h0")) @[AXISlaveReadMux.scala 116:31 118:38 65:29]
    node _GEN_26 = mux(_T_6, _GEN_18, ar_determined) @[AXISlaveReadMux.scala 106:33 37:30]
    node _GEN_27 = mux(_T_6, _GEN_19, data_reg_id) @[AXISlaveReadMux.scala 106:33 43:25]
    node _GEN_28 = mux(_T_6, _GEN_20, data_reg_data) @[AXISlaveReadMux.scala 106:33 43:25]
    node _GEN_29 = mux(_T_6, _GEN_21, data_reg_resp) @[AXISlaveReadMux.scala 106:33 43:25]
    node _GEN_30 = mux(_T_6, _GEN_22, data_reg_last) @[AXISlaveReadMux.scala 106:33 43:25]
    node _GEN_31 = mux(_T_6, UInt<1>("h1"), UInt<1>("h0")) @[AXISlaveReadMux.scala 106:33 114:29 60:25]
    node _GEN_32 = mux(_T_6, UInt<1>("h0"), _GEN_24) @[AXISlaveReadMux.scala 106:33 65:29]
    node _GEN_34 = mux(_T_5, _GEN_6, chosen_reg) @[AXISlaveReadMux.scala 97:24 36:27]
    node _GEN_35 = mux(_T_5, _GEN_7, address_reg_id) @[AXISlaveReadMux.scala 97:24 38:28]
    node _GEN_36 = mux(_T_5, _GEN_8, address_reg_addr) @[AXISlaveReadMux.scala 97:24 38:28]
    node _GEN_37 = mux(_T_5, _GEN_9, address_reg_region) @[AXISlaveReadMux.scala 97:24 38:28]
    node _GEN_38 = mux(_T_5, _GEN_10, address_reg_len) @[AXISlaveReadMux.scala 97:24 38:28]
    node _GEN_39 = mux(_T_5, _GEN_11, address_reg_size) @[AXISlaveReadMux.scala 97:24 38:28]
    node _GEN_40 = mux(_T_5, _GEN_12, address_reg_burst) @[AXISlaveReadMux.scala 97:24 38:28]
    node _GEN_41 = mux(_T_5, _GEN_13, address_reg_lock) @[AXISlaveReadMux.scala 97:24 38:28]
    node _GEN_42 = mux(_T_5, _GEN_14, address_reg_cache) @[AXISlaveReadMux.scala 97:24 38:28]
    node _GEN_43 = mux(_T_5, _GEN_15, address_reg_prot) @[AXISlaveReadMux.scala 97:24 38:28]
    node _GEN_44 = mux(_T_5, _GEN_16, address_reg_qos) @[AXISlaveReadMux.scala 97:24 38:28]
    node _GEN_45 = mux(_T_5, _GEN_17, _GEN_26) @[AXISlaveReadMux.scala 97:24]
    node _GEN_46 = mux(_T_5, UInt<1>("h0"), _GEN_31) @[AXISlaveReadMux.scala 97:24 104:27]
    node _GEN_47 = mux(_T_5, data_reg_id, _GEN_27) @[AXISlaveReadMux.scala 97:24 43:25]
    node _GEN_48 = mux(_T_5, data_reg_data, _GEN_28) @[AXISlaveReadMux.scala 97:24 43:25]
    node _GEN_49 = mux(_T_5, data_reg_resp, _GEN_29) @[AXISlaveReadMux.scala 97:24 43:25]
    node _GEN_50 = mux(_T_5, data_reg_last, _GEN_30) @[AXISlaveReadMux.scala 97:24 43:25]
    node _GEN_51 = mux(_T_5, UInt<1>("h0"), _GEN_32) @[AXISlaveReadMux.scala 97:24 65:29]
    node _address_reg_WIRE_id = UInt<4>("h0")
    node _address_reg_WIRE_addr = UInt<32>("h0")
    node _address_reg_WIRE_region = validif(UInt<1>("h0"), UInt<4>("h0"))
    node _address_reg_WIRE_len = validif(UInt<1>("h0"), UInt<8>("h0"))
    node _address_reg_WIRE_size = UInt<2>("h0")
    node _address_reg_WIRE_burst = validif(UInt<1>("h0"), UInt<2>("h0"))
    node _address_reg_WIRE_lock = validif(UInt<1>("h0"), UInt<1>("h0"))
    node _address_reg_WIRE_cache = validif(UInt<1>("h0"), UInt<4>("h0"))
    node _address_reg_WIRE_prot = validif(UInt<1>("h0"), UInt<3>("h0"))
    node _address_reg_WIRE_qos = validif(UInt<1>("h0"), UInt<4>("h0"))
    node _data_reg_WIRE_id = UInt<4>("h0")
    node _data_reg_WIRE_data = UInt<32>("h0")
    node _data_reg_WIRE_resp = UInt<2>("h0")
    node _data_reg_WIRE_last = UInt<1>("h0")
    io_out_readAddr_valid <= ar_determined @[AXISlaveReadMux.scala 77:25]
    io_out_readAddr_bits_id <= address_reg_id @[AXISlaveReadMux.scala 121:24]
    io_out_readAddr_bits_addr <= address_reg_addr @[AXISlaveReadMux.scala 121:24]
    io_out_readAddr_bits_region <= address_reg_region @[AXISlaveReadMux.scala 121:24]
    io_out_readAddr_bits_len <= address_reg_len @[AXISlaveReadMux.scala 121:24]
    io_out_readAddr_bits_size <= address_reg_size @[AXISlaveReadMux.scala 121:24]
    io_out_readAddr_bits_burst <= address_reg_burst @[AXISlaveReadMux.scala 121:24]
    io_out_readAddr_bits_lock <= address_reg_lock @[AXISlaveReadMux.scala 121:24]
    io_out_readAddr_bits_cache <= address_reg_cache @[AXISlaveReadMux.scala 121:24]
    io_out_readAddr_bits_prot <= address_reg_prot @[AXISlaveReadMux.scala 121:24]
    io_out_readAddr_bits_qos <= address_reg_qos @[AXISlaveReadMux.scala 121:24]
    io_out_readData_ready <= _GEN_46
    io_in_0_readAddr_ready <= _io_in_0_readAddr_ready_T @[AXISlaveReadMux.scala 72:29]
    io_in_0_readData_valid <= _GEN_51
    io_in_0_readData_bits_id <= data_reg_id @[AXISlaveReadMux.scala 122:35]
    io_in_0_readData_bits_data <= data_reg_data @[AXISlaveReadMux.scala 122:35]
    io_in_0_readData_bits_resp <= data_reg_resp @[AXISlaveReadMux.scala 122:35]
    io_in_0_readData_bits_last <= data_reg_last @[AXISlaveReadMux.scala 122:35]
    state <= mux(reset, UInt<2>("h0"), _GEN_5) @[AXISlaveReadMux.scala 30:{22,22}]
    arbiter.clock <= clock
    arbiter.reset <= reset
    arbiter.io_in_0_valid <= _arbiter_io_in_0_valid_T @[AXISlaveReadMux.scala 73:28]
    arbiter.io_in_0_bits <= UInt<1>("h0") @[AXISlaveReadMux.scala 74:27]
    arbiter.io_out_ready <= UInt<1>("h1") @[AXISlaveReadMux.scala 61:24]
    chosen_reg <= mux(reset, UInt<1>("h0"), _GEN_34) @[AXISlaveReadMux.scala 36:{27,27}]
    ar_determined <= mux(reset, UInt<1>("h0"), _GEN_45) @[AXISlaveReadMux.scala 37:{30,30}]
    address_reg_id <= mux(reset, _address_reg_WIRE_id, _GEN_35) @[AXISlaveReadMux.scala 38:{28,28}]
    address_reg_addr <= mux(reset, _address_reg_WIRE_addr, _GEN_36) @[AXISlaveReadMux.scala 38:{28,28}]
    address_reg_region <= _GEN_37
    address_reg_len <= _GEN_38
    address_reg_size <= mux(reset, _address_reg_WIRE_size, _GEN_39) @[AXISlaveReadMux.scala 38:{28,28}]
    address_reg_burst <= _GEN_40
    address_reg_lock <= _GEN_41
    address_reg_cache <= _GEN_42
    address_reg_prot <= _GEN_43
    address_reg_qos <= _GEN_44
    data_reg_id <= mux(reset, _data_reg_WIRE_id, _GEN_47) @[AXISlaveReadMux.scala 43:{25,25}]
    data_reg_data <= mux(reset, _data_reg_WIRE_data, _GEN_48) @[AXISlaveReadMux.scala 43:{25,25}]
    data_reg_resp <= mux(reset, _data_reg_WIRE_resp, _GEN_49) @[AXISlaveReadMux.scala 43:{25,25}]
    data_reg_last <= mux(reset, _data_reg_WIRE_last, _GEN_50) @[AXISlaveReadMux.scala 43:{25,25}]

  module AXIWriteBus :
    input clock : Clock
    input reset : UInt<1>
    output io_master_writeAddr_ready : UInt<1>
    input io_master_writeAddr_valid : UInt<1>
    input io_master_writeAddr_bits_id : UInt<4>
    input io_master_writeAddr_bits_addr : UInt<32>
    input io_master_writeAddr_bits_region : UInt<4>
    input io_master_writeAddr_bits_len : UInt<8>
    input io_master_writeAddr_bits_size : UInt<2>
    input io_master_writeAddr_bits_burst : UInt<2>
    input io_master_writeAddr_bits_lock : UInt<1>
    input io_master_writeAddr_bits_cache : UInt<4>
    input io_master_writeAddr_bits_prot : UInt<3>
    input io_master_writeAddr_bits_qos : UInt<4>
    output io_master_writeData_ready : UInt<1>
    input io_master_writeData_valid : UInt<1>
    input io_master_writeData_bits_data : UInt<32>
    input io_master_writeData_bits_strb : UInt<4>
    input io_master_writeData_bits_last : UInt<1>
    input io_master_writeResp_ready : UInt<1>
    output io_master_writeResp_valid : UInt<1>
    output io_master_writeResp_bits_id : UInt<4>
    output io_master_writeResp_bits_resp : UInt<2>
    input io_slave_0_writeAddr_ready : UInt<1>
    output io_slave_0_writeAddr_valid : UInt<1>
    output io_slave_0_writeAddr_bits_id : UInt<4>
    output io_slave_0_writeAddr_bits_addr : UInt<32>
    output io_slave_0_writeAddr_bits_region : UInt<4>
    output io_slave_0_writeAddr_bits_len : UInt<8>
    output io_slave_0_writeAddr_bits_size : UInt<2>
    output io_slave_0_writeAddr_bits_burst : UInt<2>
    output io_slave_0_writeAddr_bits_lock : UInt<1>
    output io_slave_0_writeAddr_bits_cache : UInt<4>
    output io_slave_0_writeAddr_bits_prot : UInt<3>
    output io_slave_0_writeAddr_bits_qos : UInt<4>
    input io_slave_0_writeData_ready : UInt<1>
    output io_slave_0_writeData_valid : UInt<1>
    output io_slave_0_writeData_bits_data : UInt<32>
    output io_slave_0_writeData_bits_strb : UInt<4>
    output io_slave_0_writeData_bits_last : UInt<1>
    output io_slave_0_writeResp_ready : UInt<1>
    input io_slave_0_writeResp_valid : UInt<1>
    input io_slave_0_writeResp_bits_id : UInt<4>
    input io_slave_0_writeResp_bits_resp : UInt<2>

    node _write_port_T = geq(io_master_writeAddr_bits_addr, UInt<16>("h8000")) @[AXIWriteBus.scala 28:36]
    node _write_port_T_1 = lt(io_master_writeAddr_bits_addr, UInt<17>("h18000")) @[AXIWriteBus.scala 28:87]
    node _write_port_T_2 = and(_write_port_T, _write_port_T_1) @[AXIWriteBus.scala 28:54]
    node write_port = mux(_write_port_T_2, UInt<1>("h0"), UInt<1>("h0")) @[Mux.scala 101:16]
    reg write_port_reg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), write_port_reg) @[AXIWriteBus.scala 31:31]
    reg write_addr_reg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), write_addr_reg) @[AXIWriteBus.scala 33:31]
    reg write_addr_reg_valid : UInt<1>, clock with :
      reset => (UInt<1>("h0"), write_addr_reg_valid) @[AXIWriteBus.scala 34:37]
    reg write_addr_reg_id : UInt<4>, clock with :
      reset => (UInt<1>("h0"), write_addr_reg_id) @[AXIWriteBus.scala 35:34]
    reg write_addr_reg_size : UInt<3>, clock with :
      reset => (UInt<1>("h0"), write_addr_reg_size) @[AXIWriteBus.scala 36:36]
    reg write_data_reg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), write_data_reg) @[AXIWriteBus.scala 38:31]
    reg write_data_reg_valid : UInt<1>, clock with :
      reset => (UInt<1>("h0"), write_data_reg_valid) @[AXIWriteBus.scala 39:37]
    reg write_data_reg_strb : UInt<4>, clock with :
      reset => (UInt<1>("h0"), write_data_reg_strb) @[AXIWriteBus.scala 40:36]
    reg write_data_reg_last : UInt<1>, clock with :
      reset => (UInt<1>("h0"), write_data_reg_last) @[AXIWriteBus.scala 41:36]
    reg write_resp_reg : UInt<4>, clock with :
      reset => (UInt<1>("h0"), write_resp_reg) @[AXIWriteBus.scala 43:31]
    reg write_resp_reg_valid : UInt<1>, clock with :
      reset => (UInt<1>("h0"), write_resp_reg_valid) @[AXIWriteBus.scala 44:37]
    reg write_resp_reg_id : UInt<4>, clock with :
      reset => (UInt<1>("h0"), write_resp_reg_id) @[AXIWriteBus.scala 45:34]
    reg w_outstanding : UInt<1>, clock with :
      reset => (UInt<1>("h0"), w_outstanding) @[AXIWriteBus.scala 48:30]
    reg aw_outstanding : UInt<1>, clock with :
      reset => (UInt<1>("h0"), aw_outstanding) @[AXIWriteBus.scala 49:31]
    reg b_outstanding : UInt<1>, clock with :
      reset => (UInt<1>("h0"), b_outstanding) @[AXIWriteBus.scala 50:30]
    node _io_master_writeData_ready_T = not(w_outstanding) @[AXIWriteBus.scala 72:32]
    node _io_master_writeAddr_ready_T = not(aw_outstanding) @[AXIWriteBus.scala 73:32]
    node _T = and(io_master_writeAddr_ready, io_master_writeAddr_valid) @[Decoupled.scala 52:35]
    node _GEN_0 = mux(_T, UInt<1>("h1"), aw_outstanding) @[AXIWriteBus.scala 80:34 81:20 49:31]
    node _GEN_1 = mux(_T, write_port, write_port_reg) @[AXIWriteBus.scala 80:34 82:20 31:31]
    node _GEN_2 = mux(_T, io_master_writeAddr_bits_addr, write_addr_reg) @[AXIWriteBus.scala 80:34 83:20 33:31]
    node _GEN_3 = mux(_T, UInt<1>("h1"), write_addr_reg_valid) @[AXIWriteBus.scala 80:34 84:26 34:37]
    node _GEN_4 = mux(_T, io_master_writeAddr_bits_id, write_addr_reg_id) @[AXIWriteBus.scala 80:34 85:23 35:34]
    node _GEN_5 = mux(_T, io_master_writeAddr_bits_size, write_addr_reg_size) @[AXIWriteBus.scala 80:34 86:25 36:36]
    node _T_1 = and(io_master_writeData_ready, io_master_writeData_valid) @[Decoupled.scala 52:35]
    node _GEN_6 = mux(_T_1, UInt<1>("h1"), w_outstanding) @[AXIWriteBus.scala 88:34 89:19 48:30]
    node _GEN_7 = mux(_T_1, io_master_writeData_bits_strb, write_data_reg_strb) @[AXIWriteBus.scala 88:34 90:25 40:36]
    node _GEN_8 = mux(_T_1, io_master_writeData_bits_data, write_data_reg) @[AXIWriteBus.scala 88:34 91:20 38:31]
    node _GEN_9 = mux(_T_1, UInt<1>("h1"), write_data_reg_valid) @[AXIWriteBus.scala 88:34 92:26 39:37]
    node _GEN_10 = mux(_T_1, io_master_writeData_bits_last, write_data_reg_last) @[AXIWriteBus.scala 88:34 93:25 41:36]
    node _T_2 = and(write_addr_reg_valid, io_slave_0_writeAddr_ready) @[AXIWriteBus.scala 97:29]
    node _GEN_11 = mux(_T_2, UInt<1>("h0"), _GEN_3) @[AXIWriteBus.scala 97:74 98:28]
    node _T_3 = and(write_data_reg_valid, io_slave_0_writeData_ready) @[AXIWriteBus.scala 100:29]
    node _GEN_12 = mux(_T_3, UInt<1>("h0"), _GEN_9) @[AXIWriteBus.scala 100:74 101:28]
    node _T_4 = and(aw_outstanding, w_outstanding) @[AXIWriteBus.scala 105:23]
    node _T_5 = and(_T_4, write_resp_reg_valid) @[AXIWriteBus.scala 105:40]
    node _T_6 = and(_T_5, io_master_writeResp_ready) @[AXIWriteBus.scala 105:64]
    node _GEN_13 = mux(_T_6, UInt<1>("h0"), write_resp_reg_valid) @[AXIWriteBus.scala 105:94 106:28 44:37]
    node _GEN_14 = mux(_T_6, UInt<1>("h0"), _GEN_0) @[AXIWriteBus.scala 105:94 107:22]
    node _GEN_15 = mux(_T_6, UInt<1>("h0"), _GEN_6) @[AXIWriteBus.scala 105:94 108:21]
    node _GEN_16 = mux(_T_6, UInt<1>("h0"), b_outstanding) @[AXIWriteBus.scala 105:94 109:21 50:30]
    node _T_7 = and(io_slave_0_writeResp_ready, io_slave_0_writeResp_valid) @[Decoupled.scala 52:35]
    node _GEN_17 = mux(_T_7, UInt<1>("h1"), _GEN_16) @[AXIWriteBus.scala 114:50 115:21]
    node _GEN_18 = mux(_T_7, UInt<1>("h1"), _GEN_13) @[AXIWriteBus.scala 114:50 116:28]
    node _GEN_19 = mux(_T_7, io_slave_0_writeResp_bits_resp, write_resp_reg) @[AXIWriteBus.scala 114:50 117:22 43:31]
    node _GEN_20 = mux(_T_7, io_slave_0_writeResp_bits_id, write_resp_reg_id) @[AXIWriteBus.scala 114:50 118:25 45:34]
    node _io_slave_0_writeResp_ready_T = not(b_outstanding) @[AXIWriteBus.scala 129:49]
    node _GEN_21 = mux(aw_outstanding, _GEN_17, _GEN_16) @[AXIWriteBus.scala 112:24]
    node _GEN_22 = mux(aw_outstanding, _GEN_18, _GEN_13) @[AXIWriteBus.scala 112:24]
    node _GEN_23 = mux(aw_outstanding, _GEN_19, write_resp_reg) @[AXIWriteBus.scala 112:24 43:31]
    node _GEN_24 = mux(aw_outstanding, _GEN_20, write_resp_reg_id) @[AXIWriteBus.scala 112:24 45:34]
    node _GEN_25 = mux(aw_outstanding, write_addr_reg, UInt<1>("h0")) @[AXIWriteBus.scala 112:24 121:50 59:37]
    node _GEN_26 = mux(aw_outstanding, write_addr_reg_valid, UInt<1>("h0")) @[AXIWriteBus.scala 112:24 122:46 58:33]
    node _GEN_27 = mux(aw_outstanding, write_addr_reg_id, UInt<1>("h0")) @[AXIWriteBus.scala 112:24 123:48 60:35]
    node _GEN_28 = mux(aw_outstanding, write_addr_reg_size, UInt<1>("h0")) @[AXIWriteBus.scala 112:24 124:50 63:37]
    node _GEN_29 = mux(aw_outstanding, write_data_reg, UInt<1>("h0")) @[AXIWriteBus.scala 112:24 125:50 55:37]
    node _GEN_30 = mux(aw_outstanding, write_data_reg_strb, UInt<1>("h0")) @[AXIWriteBus.scala 112:24 126:50 56:37]
    node _GEN_31 = mux(aw_outstanding, write_data_reg_valid, UInt<1>("h0")) @[AXIWriteBus.scala 112:24 127:46 54:33]
    node _GEN_32 = mux(aw_outstanding, write_data_reg_last, UInt<1>("h0")) @[AXIWriteBus.scala 112:24 128:50 57:37]
    node _GEN_33 = mux(aw_outstanding, _io_slave_0_writeResp_ready_T, UInt<1>("h0")) @[AXIWriteBus.scala 112:24 129:46 69:33]
    io_master_writeAddr_ready <= _io_master_writeAddr_ready_T @[AXIWriteBus.scala 73:29]
    io_master_writeData_ready <= _io_master_writeData_ready_T @[AXIWriteBus.scala 72:29]
    io_master_writeResp_valid <= write_resp_reg_valid @[AXIWriteBus.scala 74:29]
    io_master_writeResp_bits_id <= write_resp_reg_id @[AXIWriteBus.scala 76:31]
    io_master_writeResp_bits_resp <= bits(write_resp_reg, 1, 0) @[AXIWriteBus.scala 75:33]
    io_slave_0_writeAddr_valid <= _GEN_26
    io_slave_0_writeAddr_bits_id <= _GEN_27
    io_slave_0_writeAddr_bits_addr <= _GEN_25
    io_slave_0_writeAddr_bits_region is invalid
    io_slave_0_writeAddr_bits_len is invalid
    io_slave_0_writeAddr_bits_size <= bits(_GEN_28, 1, 0)
    io_slave_0_writeAddr_bits_burst is invalid
    io_slave_0_writeAddr_bits_lock is invalid
    io_slave_0_writeAddr_bits_cache is invalid
    io_slave_0_writeAddr_bits_prot is invalid
    io_slave_0_writeAddr_bits_qos is invalid
    io_slave_0_writeData_valid <= _GEN_31
    io_slave_0_writeData_bits_data <= _GEN_29
    io_slave_0_writeData_bits_strb <= _GEN_30
    io_slave_0_writeData_bits_last <= _GEN_32
    io_slave_0_writeResp_ready <= _GEN_33
    write_port_reg <= mux(reset, UInt<1>("h0"), _GEN_1) @[AXIWriteBus.scala 31:{31,31}]
    write_addr_reg <= mux(reset, UInt<32>("h0"), _GEN_2) @[AXIWriteBus.scala 33:{31,31}]
    write_addr_reg_valid <= mux(reset, UInt<1>("h0"), _GEN_11) @[AXIWriteBus.scala 34:{37,37}]
    write_addr_reg_id <= mux(reset, UInt<4>("h0"), _GEN_4) @[AXIWriteBus.scala 35:{34,34}]
    write_addr_reg_size <= mux(reset, UInt<3>("h0"), _GEN_5) @[AXIWriteBus.scala 36:{36,36}]
    write_data_reg <= mux(reset, UInt<32>("h0"), _GEN_8) @[AXIWriteBus.scala 38:{31,31}]
    write_data_reg_valid <= mux(reset, UInt<1>("h0"), _GEN_12) @[AXIWriteBus.scala 39:{37,37}]
    write_data_reg_strb <= mux(reset, UInt<4>("h0"), _GEN_7) @[AXIWriteBus.scala 40:{36,36}]
    write_data_reg_last <= mux(reset, UInt<1>("h0"), _GEN_10) @[AXIWriteBus.scala 41:{36,36}]
    write_resp_reg <= mux(reset, UInt<4>("h0"), _GEN_23) @[AXIWriteBus.scala 43:{31,31}]
    write_resp_reg_valid <= mux(reset, UInt<1>("h0"), _GEN_22) @[AXIWriteBus.scala 44:{37,37}]
    write_resp_reg_id <= mux(reset, UInt<4>("h0"), _GEN_24) @[AXIWriteBus.scala 45:{34,34}]
    w_outstanding <= mux(reset, UInt<1>("h0"), _GEN_15) @[AXIWriteBus.scala 48:{30,30}]
    aw_outstanding <= mux(reset, UInt<1>("h0"), _GEN_14) @[AXIWriteBus.scala 49:{31,31}]
    b_outstanding <= mux(reset, UInt<1>("h0"), _GEN_21) @[AXIWriteBus.scala 50:{30,30}]

  module AXISlaveWriteMux :
    input clock : Clock
    input reset : UInt<1>
    input io_out_writeAddr_ready : UInt<1>
    output io_out_writeAddr_valid : UInt<1>
    output io_out_writeAddr_bits_id : UInt<4>
    output io_out_writeAddr_bits_addr : UInt<32>
    output io_out_writeAddr_bits_region : UInt<4>
    output io_out_writeAddr_bits_len : UInt<8>
    output io_out_writeAddr_bits_size : UInt<2>
    output io_out_writeAddr_bits_burst : UInt<2>
    output io_out_writeAddr_bits_lock : UInt<1>
    output io_out_writeAddr_bits_cache : UInt<4>
    output io_out_writeAddr_bits_prot : UInt<3>
    output io_out_writeAddr_bits_qos : UInt<4>
    input io_out_writeData_ready : UInt<1>
    output io_out_writeData_valid : UInt<1>
    output io_out_writeData_bits_data : UInt<32>
    output io_out_writeData_bits_strb : UInt<4>
    output io_out_writeData_bits_last : UInt<1>
    output io_out_writeResp_ready : UInt<1>
    input io_out_writeResp_valid : UInt<1>
    input io_out_writeResp_bits_id : UInt<4>
    input io_out_writeResp_bits_resp : UInt<2>
    output io_in_0_writeAddr_ready : UInt<1>
    input io_in_0_writeAddr_valid : UInt<1>
    input io_in_0_writeAddr_bits_id : UInt<4>
    input io_in_0_writeAddr_bits_addr : UInt<32>
    input io_in_0_writeAddr_bits_region : UInt<4>
    input io_in_0_writeAddr_bits_len : UInt<8>
    input io_in_0_writeAddr_bits_size : UInt<2>
    input io_in_0_writeAddr_bits_burst : UInt<2>
    input io_in_0_writeAddr_bits_lock : UInt<1>
    input io_in_0_writeAddr_bits_cache : UInt<4>
    input io_in_0_writeAddr_bits_prot : UInt<3>
    input io_in_0_writeAddr_bits_qos : UInt<4>
    output io_in_0_writeData_ready : UInt<1>
    input io_in_0_writeData_valid : UInt<1>
    input io_in_0_writeData_bits_data : UInt<32>
    input io_in_0_writeData_bits_strb : UInt<4>
    input io_in_0_writeData_bits_last : UInt<1>
    input io_in_0_writeResp_ready : UInt<1>
    output io_in_0_writeResp_valid : UInt<1>
    output io_in_0_writeResp_bits_id : UInt<4>
    output io_in_0_writeResp_bits_resp : UInt<2>

    inst arbiter of RRArbiter @[AXISlaveWriteMux.scala 38:23]
    reg state : UInt<2>, clock with :
      reset => (UInt<1>("h0"), state) @[AXISlaveWriteMux.scala 32:22]
    reg chosen_reg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), chosen_reg) @[AXISlaveWriteMux.scala 39:27]
    reg w_determined : UInt<1>, clock with :
      reset => (UInt<1>("h0"), w_determined) @[AXISlaveWriteMux.scala 40:29]
    reg aw_determined : UInt<1>, clock with :
      reset => (UInt<1>("h0"), aw_determined) @[AXISlaveWriteMux.scala 41:30]
    reg address_reg_id : UInt<4>, clock with :
      reset => (UInt<1>("h0"), address_reg_id) @[AXISlaveWriteMux.scala 43:28]
    reg address_reg_addr : UInt<32>, clock with :
      reset => (UInt<1>("h0"), address_reg_addr) @[AXISlaveWriteMux.scala 43:28]
    reg address_reg_region : UInt<4>, clock with :
      reset => (UInt<1>("h0"), address_reg_region) @[AXISlaveWriteMux.scala 43:28]
    reg address_reg_len : UInt<8>, clock with :
      reset => (UInt<1>("h0"), address_reg_len) @[AXISlaveWriteMux.scala 43:28]
    reg address_reg_size : UInt<2>, clock with :
      reset => (UInt<1>("h0"), address_reg_size) @[AXISlaveWriteMux.scala 43:28]
    reg address_reg_burst : UInt<2>, clock with :
      reset => (UInt<1>("h0"), address_reg_burst) @[AXISlaveWriteMux.scala 43:28]
    reg address_reg_lock : UInt<1>, clock with :
      reset => (UInt<1>("h0"), address_reg_lock) @[AXISlaveWriteMux.scala 43:28]
    reg address_reg_cache : UInt<4>, clock with :
      reset => (UInt<1>("h0"), address_reg_cache) @[AXISlaveWriteMux.scala 43:28]
    reg address_reg_prot : UInt<3>, clock with :
      reset => (UInt<1>("h0"), address_reg_prot) @[AXISlaveWriteMux.scala 43:28]
    reg address_reg_qos : UInt<4>, clock with :
      reset => (UInt<1>("h0"), address_reg_qos) @[AXISlaveWriteMux.scala 43:28]
    reg data_reg_data : UInt<32>, clock with :
      reset => (UInt<1>("h0"), data_reg_data) @[AXISlaveWriteMux.scala 48:25]
    reg data_reg_strb : UInt<4>, clock with :
      reset => (UInt<1>("h0"), data_reg_strb) @[AXISlaveWriteMux.scala 48:25]
    reg data_reg_last : UInt<1>, clock with :
      reset => (UInt<1>("h0"), data_reg_last) @[AXISlaveWriteMux.scala 48:25]
    reg resp_reg_id : UInt<4>, clock with :
      reset => (UInt<1>("h0"), resp_reg_id) @[AXISlaveWriteMux.scala 53:25]
    reg resp_reg_resp : UInt<2>, clock with :
      reset => (UInt<1>("h0"), resp_reg_resp) @[AXISlaveWriteMux.scala 53:25]
    node _T_8 = eq(state, UInt<2>("h0")) @[AXISlaveWriteMux.scala 117:14]
    node _T_10 = eq(state, UInt<2>("h1")) @[AXISlaveWriteMux.scala 133:19]
    node _T_13 = eq(state, UInt<2>("h2")) @[AXISlaveWriteMux.scala 144:19]
    node _T_17 = eq(state, UInt<2>("h3")) @[AXISlaveWriteMux.scala 157:19]
    node _mask_WIRE_0 = UInt<1>("h1") @[AXISlaveWriteMux.scala 26:{33,33}]
    node _GEN_38 = mux(_T_17, UInt<1>("h0"), _mask_WIRE_0) @[AXISlaveWriteMux.scala 157:31 158:20]
    node _GEN_40 = mux(_T_13, UInt<1>("h0"), _GEN_38) @[AXISlaveWriteMux.scala 144:33 145:22]
    node _GEN_47 = mux(_T_10, UInt<1>("h0"), _GEN_40) @[AXISlaveWriteMux.scala 133:33 134:20]
    node _GEN_58 = mux(_T_8, UInt<1>("h1"), _GEN_47) @[AXISlaveWriteMux.scala 117:24 119:20]
    node mask_0 = _GEN_58
    node _io_in_0_writeAddr_ready_T = and(arbiter.io_in_0_ready, mask_0) @[AXISlaveWriteMux.scala 79:56]
    node _arbiter_io_in_0_valid_T = and(io_in_0_writeAddr_valid, mask_0) @[AXISlaveWriteMux.scala 80:56]
    node _T = eq(UInt<2>("h0"), state) @[AXISlaveWriteMux.scala 88:16]
    node _T_1 = and(io_in_0_writeData_ready, io_in_0_writeData_valid) @[Decoupled.scala 52:35]
    node _GEN_0 = mux(_T_1, UInt<2>("h2"), UInt<2>("h1")) @[AXISlaveWriteMux.scala 92:61 93:17 96:17]
    node outstanding = io_in_0_writeAddr_valid
    node _GEN_1 = mux(outstanding, _GEN_0, state) @[AXISlaveWriteMux.scala 32:22 90:24]
    node _T_2 = eq(UInt<2>("h1"), state) @[AXISlaveWriteMux.scala 88:16]
    node _T_3 = and(io_in_0_writeData_ready, io_in_0_writeData_valid) @[Decoupled.scala 52:35]
    node _GEN_2 = mux(_T_3, UInt<2>("h2"), state) @[AXISlaveWriteMux.scala 101:45 102:15 32:22]
    node _T_4 = eq(UInt<2>("h2"), state) @[AXISlaveWriteMux.scala 88:16]
    node _T_5 = and(io_out_writeResp_ready, io_out_writeResp_valid) @[Decoupled.scala 52:35]
    node _GEN_3 = mux(_T_5, UInt<2>("h3"), state) @[AXISlaveWriteMux.scala 106:34 107:15 32:22]
    node _T_6 = eq(UInt<2>("h3"), state) @[AXISlaveWriteMux.scala 88:16]
    node _T_7 = and(io_in_0_writeResp_ready, io_in_0_writeResp_valid) @[Decoupled.scala 52:35]
    node _GEN_4 = mux(_T_7, UInt<2>("h0"), state) @[AXISlaveWriteMux.scala 111:45 112:15 32:22]
    node _GEN_5 = mux(_T_6, _GEN_4, state) @[AXISlaveWriteMux.scala 88:16 32:22]
    node _GEN_6 = mux(_T_4, _GEN_3, _GEN_5) @[AXISlaveWriteMux.scala 88:16]
    node _GEN_7 = mux(_T_2, _GEN_2, _GEN_6) @[AXISlaveWriteMux.scala 88:16]
    node _GEN_8 = mux(_T, _GEN_1, _GEN_7) @[AXISlaveWriteMux.scala 88:16]
    node _T_9 = and(io_in_0_writeData_ready, io_in_0_writeData_valid) @[Decoupled.scala 52:35]
    node _GEN_9 = mux(_T_9, io_in_0_writeData_bits_data, data_reg_data) @[AXISlaveWriteMux.scala 126:59 127:18 48:25]
    node _GEN_10 = mux(_T_9, io_in_0_writeData_bits_strb, data_reg_strb) @[AXISlaveWriteMux.scala 126:59 127:18 48:25]
    node _GEN_11 = mux(_T_9, io_in_0_writeData_bits_last, data_reg_last) @[AXISlaveWriteMux.scala 126:59 127:18 48:25]
    node _GEN_12 = mux(_T_9, UInt<1>("h1"), w_determined) @[AXISlaveWriteMux.scala 126:59 128:22 40:29]
    node _GEN_13 = mux(arbiter.io_out_valid, UInt<1>("h1"), UInt<1>("h0")) @[AXISlaveWriteMux.scala 121:31 122:48 72:30]
    node _GEN_14 = mux(arbiter.io_out_valid, UInt<1>("h0"), chosen_reg) @[AXISlaveWriteMux.scala 121:31 123:18 39:27]
    node _GEN_15 = mux(arbiter.io_out_valid, io_in_0_writeAddr_bits_id, address_reg_id) @[AXISlaveWriteMux.scala 121:31 124:19 43:28]
    node _GEN_16 = mux(arbiter.io_out_valid, io_in_0_writeAddr_bits_addr, address_reg_addr) @[AXISlaveWriteMux.scala 121:31 124:19 43:28]
    node _GEN_17 = mux(arbiter.io_out_valid, io_in_0_writeAddr_bits_region, address_reg_region) @[AXISlaveWriteMux.scala 121:31 124:19 43:28]
    node _GEN_18 = mux(arbiter.io_out_valid, io_in_0_writeAddr_bits_len, address_reg_len) @[AXISlaveWriteMux.scala 121:31 124:19 43:28]
    node _GEN_19 = mux(arbiter.io_out_valid, io_in_0_writeAddr_bits_size, address_reg_size) @[AXISlaveWriteMux.scala 121:31 124:19 43:28]
    node _GEN_20 = mux(arbiter.io_out_valid, io_in_0_writeAddr_bits_burst, address_reg_burst) @[AXISlaveWriteMux.scala 121:31 124:19 43:28]
    node _GEN_21 = mux(arbiter.io_out_valid, io_in_0_writeAddr_bits_lock, address_reg_lock) @[AXISlaveWriteMux.scala 121:31 124:19 43:28]
    node _GEN_22 = mux(arbiter.io_out_valid, io_in_0_writeAddr_bits_cache, address_reg_cache) @[AXISlaveWriteMux.scala 121:31 124:19 43:28]
    node _GEN_23 = mux(arbiter.io_out_valid, io_in_0_writeAddr_bits_prot, address_reg_prot) @[AXISlaveWriteMux.scala 121:31 124:19 43:28]
    node _GEN_24 = mux(arbiter.io_out_valid, io_in_0_writeAddr_bits_qos, address_reg_qos) @[AXISlaveWriteMux.scala 121:31 124:19 43:28]
    node _GEN_25 = mux(arbiter.io_out_valid, UInt<1>("h1"), aw_determined) @[AXISlaveWriteMux.scala 121:31 125:21 41:30]
    node _GEN_26 = mux(arbiter.io_out_valid, _GEN_9, data_reg_data) @[AXISlaveWriteMux.scala 121:31 48:25]
    node _GEN_27 = mux(arbiter.io_out_valid, _GEN_10, data_reg_strb) @[AXISlaveWriteMux.scala 121:31 48:25]
    node _GEN_28 = mux(arbiter.io_out_valid, _GEN_11, data_reg_last) @[AXISlaveWriteMux.scala 121:31 48:25]
    node _GEN_29 = mux(arbiter.io_out_valid, _GEN_12, w_determined) @[AXISlaveWriteMux.scala 121:31 40:29]
    node _T_11 = and(io_in_0_writeData_ready, io_in_0_writeData_valid) @[Decoupled.scala 52:35]
    node _GEN_30 = mux(_T_11, io_in_0_writeData_bits_data, data_reg_data) @[AXISlaveWriteMux.scala 135:43 136:16 48:25]
    node _GEN_31 = mux(_T_11, io_in_0_writeData_bits_strb, data_reg_strb) @[AXISlaveWriteMux.scala 135:43 136:16 48:25]
    node _GEN_32 = mux(_T_11, io_in_0_writeData_bits_last, data_reg_last) @[AXISlaveWriteMux.scala 135:43 136:16 48:25]
    node _T_12 = and(io_out_writeAddr_ready, io_out_writeAddr_valid) @[Decoupled.scala 52:35]
    node _GEN_33 = mux(_T_12, UInt<1>("h0"), aw_determined) @[AXISlaveWriteMux.scala 138:32 139:21 41:30]
    node _T_14 = and(io_out_writeAddr_ready, io_out_writeAddr_valid) @[Decoupled.scala 52:35]
    node _GEN_34 = mux(_T_14, UInt<1>("h0"), aw_determined) @[AXISlaveWriteMux.scala 146:34 147:23 41:30]
    node _T_15 = and(io_out_writeData_ready, io_out_writeData_valid) @[Decoupled.scala 52:35]
    node _GEN_35 = mux(_T_15, UInt<1>("h0"), w_determined) @[AXISlaveWriteMux.scala 149:34 150:22 40:29]
    node _T_16 = and(io_out_writeResp_ready, io_out_writeResp_valid) @[Decoupled.scala 52:35]
    node _GEN_36 = mux(_T_16, io_out_writeResp_bits_id, resp_reg_id) @[AXISlaveWriteMux.scala 152:34 153:18 53:25]
    node _GEN_37 = mux(_T_16, io_out_writeResp_bits_resp, resp_reg_resp) @[AXISlaveWriteMux.scala 152:34 153:18 53:25]
    node _GEN_39 = mux(_T_17, UInt<1>("h1"), UInt<1>("h0")) @[AXISlaveWriteMux.scala 157:31 159:39 73:30]
    node _GEN_41 = mux(_T_13, _GEN_34, aw_determined) @[AXISlaveWriteMux.scala 144:33 41:30]
    node _GEN_42 = mux(_T_13, _GEN_35, w_determined) @[AXISlaveWriteMux.scala 144:33 40:29]
    node _GEN_43 = mux(_T_13, _GEN_36, resp_reg_id) @[AXISlaveWriteMux.scala 144:33 53:25]
    node _GEN_44 = mux(_T_13, _GEN_37, resp_reg_resp) @[AXISlaveWriteMux.scala 144:33 53:25]
    node _GEN_45 = mux(_T_13, UInt<1>("h1"), UInt<1>("h0")) @[AXISlaveWriteMux.scala 144:33 155:30 68:26]
    node _GEN_46 = mux(_T_13, UInt<1>("h0"), _GEN_39) @[AXISlaveWriteMux.scala 144:33 73:30]
    node _GEN_48 = mux(_T_10, _GEN_30, data_reg_data) @[AXISlaveWriteMux.scala 133:33 48:25]
    node _GEN_49 = mux(_T_10, _GEN_31, data_reg_strb) @[AXISlaveWriteMux.scala 133:33 48:25]
    node _GEN_50 = mux(_T_10, _GEN_32, data_reg_last) @[AXISlaveWriteMux.scala 133:33 48:25]
    node _GEN_51 = mux(_T_10, _GEN_33, _GEN_41) @[AXISlaveWriteMux.scala 133:33]
    node _GEN_52 = mux(_T_10, UInt<1>("h1"), UInt<1>("h0")) @[AXISlaveWriteMux.scala 133:33 141:39 72:30]
    node _GEN_53 = mux(_T_10, UInt<1>("h0"), _GEN_45) @[AXISlaveWriteMux.scala 133:33 142:28]
    node _GEN_54 = mux(_T_10, w_determined, _GEN_42) @[AXISlaveWriteMux.scala 133:33 40:29]
    node _GEN_55 = mux(_T_10, resp_reg_id, _GEN_43) @[AXISlaveWriteMux.scala 133:33 53:25]
    node _GEN_56 = mux(_T_10, resp_reg_resp, _GEN_44) @[AXISlaveWriteMux.scala 133:33 53:25]
    node _GEN_57 = mux(_T_10, UInt<1>("h0"), _GEN_46) @[AXISlaveWriteMux.scala 133:33 73:30]
    node _GEN_59 = mux(_T_8, _GEN_13, _GEN_52) @[AXISlaveWriteMux.scala 117:24]
    node _GEN_60 = mux(_T_8, _GEN_14, chosen_reg) @[AXISlaveWriteMux.scala 117:24 39:27]
    node _GEN_61 = mux(_T_8, _GEN_15, address_reg_id) @[AXISlaveWriteMux.scala 117:24 43:28]
    node _GEN_62 = mux(_T_8, _GEN_16, address_reg_addr) @[AXISlaveWriteMux.scala 117:24 43:28]
    node _GEN_63 = mux(_T_8, _GEN_17, address_reg_region) @[AXISlaveWriteMux.scala 117:24 43:28]
    node _GEN_64 = mux(_T_8, _GEN_18, address_reg_len) @[AXISlaveWriteMux.scala 117:24 43:28]
    node _GEN_65 = mux(_T_8, _GEN_19, address_reg_size) @[AXISlaveWriteMux.scala 117:24 43:28]
    node _GEN_66 = mux(_T_8, _GEN_20, address_reg_burst) @[AXISlaveWriteMux.scala 117:24 43:28]
    node _GEN_67 = mux(_T_8, _GEN_21, address_reg_lock) @[AXISlaveWriteMux.scala 117:24 43:28]
    node _GEN_68 = mux(_T_8, _GEN_22, address_reg_cache) @[AXISlaveWriteMux.scala 117:24 43:28]
    node _GEN_69 = mux(_T_8, _GEN_23, address_reg_prot) @[AXISlaveWriteMux.scala 117:24 43:28]
    node _GEN_70 = mux(_T_8, _GEN_24, address_reg_qos) @[AXISlaveWriteMux.scala 117:24 43:28]
    node _GEN_71 = mux(_T_8, _GEN_25, _GEN_51) @[AXISlaveWriteMux.scala 117:24]
    node _GEN_72 = mux(_T_8, _GEN_26, _GEN_48) @[AXISlaveWriteMux.scala 117:24]
    node _GEN_73 = mux(_T_8, _GEN_27, _GEN_49) @[AXISlaveWriteMux.scala 117:24]
    node _GEN_74 = mux(_T_8, _GEN_28, _GEN_50) @[AXISlaveWriteMux.scala 117:24]
    node _GEN_75 = mux(_T_8, _GEN_29, _GEN_54) @[AXISlaveWriteMux.scala 117:24]
    node _GEN_76 = mux(_T_8, UInt<1>("h0"), _GEN_53) @[AXISlaveWriteMux.scala 117:24 131:28]
    node _GEN_77 = mux(_T_8, resp_reg_id, _GEN_55) @[AXISlaveWriteMux.scala 117:24 53:25]
    node _GEN_78 = mux(_T_8, resp_reg_resp, _GEN_56) @[AXISlaveWriteMux.scala 117:24 53:25]
    node _GEN_79 = mux(_T_8, UInt<1>("h0"), _GEN_57) @[AXISlaveWriteMux.scala 117:24 73:30]
    node _address_reg_WIRE_id = UInt<4>("h0")
    node _address_reg_WIRE_addr = UInt<32>("h0")
    node _address_reg_WIRE_region = validif(UInt<1>("h0"), UInt<4>("h0"))
    node _address_reg_WIRE_len = validif(UInt<1>("h0"), UInt<8>("h0"))
    node _address_reg_WIRE_size = UInt<2>("h0")
    node _address_reg_WIRE_burst = validif(UInt<1>("h0"), UInt<2>("h0"))
    node _address_reg_WIRE_lock = validif(UInt<1>("h0"), UInt<1>("h0"))
    node _address_reg_WIRE_cache = validif(UInt<1>("h0"), UInt<4>("h0"))
    node _address_reg_WIRE_prot = validif(UInt<1>("h0"), UInt<3>("h0"))
    node _address_reg_WIRE_qos = validif(UInt<1>("h0"), UInt<4>("h0"))
    node _data_reg_WIRE_data = UInt<32>("h0")
    node _data_reg_WIRE_strb = UInt<4>("h0")
    node _data_reg_WIRE_last = UInt<1>("h0")
    node _resp_reg_WIRE_id = UInt<4>("h0")
    node _resp_reg_WIRE_resp = UInt<2>("h0")
    io_out_writeAddr_valid <= aw_determined @[AXISlaveWriteMux.scala 85:26]
    io_out_writeAddr_bits_id <= address_reg_id @[AXISlaveWriteMux.scala 163:25]
    io_out_writeAddr_bits_addr <= address_reg_addr @[AXISlaveWriteMux.scala 163:25]
    io_out_writeAddr_bits_region <= address_reg_region @[AXISlaveWriteMux.scala 163:25]
    io_out_writeAddr_bits_len <= address_reg_len @[AXISlaveWriteMux.scala 163:25]
    io_out_writeAddr_bits_size <= address_reg_size @[AXISlaveWriteMux.scala 163:25]
    io_out_writeAddr_bits_burst <= address_reg_burst @[AXISlaveWriteMux.scala 163:25]
    io_out_writeAddr_bits_lock <= address_reg_lock @[AXISlaveWriteMux.scala 163:25]
    io_out_writeAddr_bits_cache <= address_reg_cache @[AXISlaveWriteMux.scala 163:25]
    io_out_writeAddr_bits_prot <= address_reg_prot @[AXISlaveWriteMux.scala 163:25]
    io_out_writeAddr_bits_qos <= address_reg_qos @[AXISlaveWriteMux.scala 163:25]
    io_out_writeData_valid <= w_determined @[AXISlaveWriteMux.scala 86:26]
    io_out_writeData_bits_data <= data_reg_data @[AXISlaveWriteMux.scala 162:25]
    io_out_writeData_bits_strb <= data_reg_strb @[AXISlaveWriteMux.scala 162:25]
    io_out_writeData_bits_last <= data_reg_last @[AXISlaveWriteMux.scala 162:25]
    io_out_writeResp_ready <= _GEN_76
    io_in_0_writeAddr_ready <= _io_in_0_writeAddr_ready_T @[AXISlaveWriteMux.scala 79:30]
    io_in_0_writeData_ready <= _GEN_59
    io_in_0_writeResp_valid <= _GEN_79
    io_in_0_writeResp_bits_id <= resp_reg_id @[AXISlaveWriteMux.scala 164:36]
    io_in_0_writeResp_bits_resp <= resp_reg_resp @[AXISlaveWriteMux.scala 164:36]
    state <= mux(reset, UInt<2>("h0"), _GEN_8) @[AXISlaveWriteMux.scala 32:{22,22}]
    arbiter.clock <= clock
    arbiter.reset <= reset
    arbiter.io_in_0_valid <= _arbiter_io_in_0_valid_T @[AXISlaveWriteMux.scala 80:28]
    arbiter.io_in_0_bits <= UInt<1>("h0") @[AXISlaveWriteMux.scala 81:27]
    arbiter.io_out_ready <= UInt<1>("h1") @[AXISlaveWriteMux.scala 69:24]
    chosen_reg <= mux(reset, UInt<1>("h0"), _GEN_60) @[AXISlaveWriteMux.scala 39:{27,27}]
    w_determined <= mux(reset, UInt<1>("h0"), _GEN_75) @[AXISlaveWriteMux.scala 40:{29,29}]
    aw_determined <= mux(reset, UInt<1>("h0"), _GEN_71) @[AXISlaveWriteMux.scala 41:{30,30}]
    address_reg_id <= mux(reset, _address_reg_WIRE_id, _GEN_61) @[AXISlaveWriteMux.scala 43:{28,28}]
    address_reg_addr <= mux(reset, _address_reg_WIRE_addr, _GEN_62) @[AXISlaveWriteMux.scala 43:{28,28}]
    address_reg_region <= _GEN_63
    address_reg_len <= _GEN_64
    address_reg_size <= mux(reset, _address_reg_WIRE_size, _GEN_65) @[AXISlaveWriteMux.scala 43:{28,28}]
    address_reg_burst <= _GEN_66
    address_reg_lock <= _GEN_67
    address_reg_cache <= _GEN_68
    address_reg_prot <= _GEN_69
    address_reg_qos <= _GEN_70
    data_reg_data <= mux(reset, _data_reg_WIRE_data, _GEN_72) @[AXISlaveWriteMux.scala 48:{25,25}]
    data_reg_strb <= mux(reset, _data_reg_WIRE_strb, _GEN_73) @[AXISlaveWriteMux.scala 48:{25,25}]
    data_reg_last <= mux(reset, _data_reg_WIRE_last, _GEN_74) @[AXISlaveWriteMux.scala 48:{25,25}]
    resp_reg_id <= mux(reset, _resp_reg_WIRE_id, _GEN_77) @[AXISlaveWriteMux.scala 53:{25,25}]
    resp_reg_resp <= mux(reset, _resp_reg_WIRE_resp, _GEN_78) @[AXISlaveWriteMux.scala 53:{25,25}]

  module AXILiteXBar :
    input clock : Clock
    input reset : UInt<1>
    output io_masters_0_aw_ready : UInt<1>
    input io_masters_0_aw_valid : UInt<1>
    input io_masters_0_aw_bits_id : UInt<4>
    input io_masters_0_aw_bits_addr : UInt<32>
    input io_masters_0_aw_bits_region : UInt<4>
    input io_masters_0_aw_bits_len : UInt<8>
    input io_masters_0_aw_bits_size : UInt<2>
    input io_masters_0_aw_bits_burst : UInt<2>
    input io_masters_0_aw_bits_lock : UInt<1>
    input io_masters_0_aw_bits_cache : UInt<4>
    input io_masters_0_aw_bits_prot : UInt<3>
    input io_masters_0_aw_bits_qos : UInt<4>
    output io_masters_0_w_ready : UInt<1>
    input io_masters_0_w_valid : UInt<1>
    input io_masters_0_w_bits_data : UInt<32>
    input io_masters_0_w_bits_strb : UInt<4>
    input io_masters_0_w_bits_last : UInt<1>
    input io_masters_0_b_ready : UInt<1>
    output io_masters_0_b_valid : UInt<1>
    output io_masters_0_b_bits_id : UInt<4>
    output io_masters_0_b_bits_resp : UInt<2>
    output io_masters_0_ar_ready : UInt<1>
    input io_masters_0_ar_valid : UInt<1>
    input io_masters_0_ar_bits_id : UInt<4>
    input io_masters_0_ar_bits_addr : UInt<32>
    input io_masters_0_ar_bits_region : UInt<4>
    input io_masters_0_ar_bits_len : UInt<8>
    input io_masters_0_ar_bits_size : UInt<2>
    input io_masters_0_ar_bits_burst : UInt<2>
    input io_masters_0_ar_bits_lock : UInt<1>
    input io_masters_0_ar_bits_cache : UInt<4>
    input io_masters_0_ar_bits_prot : UInt<3>
    input io_masters_0_ar_bits_qos : UInt<4>
    input io_masters_0_r_ready : UInt<1>
    output io_masters_0_r_valid : UInt<1>
    output io_masters_0_r_bits_id : UInt<4>
    output io_masters_0_r_bits_data : UInt<32>
    output io_masters_0_r_bits_resp : UInt<2>
    output io_masters_0_r_bits_last : UInt<1>
    input io_slaves_0_aw_ready : UInt<1>
    output io_slaves_0_aw_valid : UInt<1>
    output io_slaves_0_aw_bits_id : UInt<4>
    output io_slaves_0_aw_bits_addr : UInt<32>
    output io_slaves_0_aw_bits_region : UInt<4>
    output io_slaves_0_aw_bits_len : UInt<8>
    output io_slaves_0_aw_bits_size : UInt<2>
    output io_slaves_0_aw_bits_burst : UInt<2>
    output io_slaves_0_aw_bits_lock : UInt<1>
    output io_slaves_0_aw_bits_cache : UInt<4>
    output io_slaves_0_aw_bits_prot : UInt<3>
    output io_slaves_0_aw_bits_qos : UInt<4>
    input io_slaves_0_w_ready : UInt<1>
    output io_slaves_0_w_valid : UInt<1>
    output io_slaves_0_w_bits_data : UInt<32>
    output io_slaves_0_w_bits_strb : UInt<4>
    output io_slaves_0_w_bits_last : UInt<1>
    output io_slaves_0_b_ready : UInt<1>
    input io_slaves_0_b_valid : UInt<1>
    input io_slaves_0_b_bits_id : UInt<4>
    input io_slaves_0_b_bits_resp : UInt<2>
    input io_slaves_0_ar_ready : UInt<1>
    output io_slaves_0_ar_valid : UInt<1>
    output io_slaves_0_ar_bits_id : UInt<4>
    output io_slaves_0_ar_bits_addr : UInt<32>
    output io_slaves_0_ar_bits_region : UInt<4>
    output io_slaves_0_ar_bits_len : UInt<8>
    output io_slaves_0_ar_bits_size : UInt<2>
    output io_slaves_0_ar_bits_burst : UInt<2>
    output io_slaves_0_ar_bits_lock : UInt<1>
    output io_slaves_0_ar_bits_cache : UInt<4>
    output io_slaves_0_ar_bits_prot : UInt<3>
    output io_slaves_0_ar_bits_qos : UInt<4>
    output io_slaves_0_r_ready : UInt<1>
    input io_slaves_0_r_valid : UInt<1>
    input io_slaves_0_r_bits_id : UInt<4>
    input io_slaves_0_r_bits_data : UInt<32>
    input io_slaves_0_r_bits_resp : UInt<2>
    input io_slaves_0_r_bits_last : UInt<1>

    inst readBuses_0 of AXIReadBus @[AXILiteXBar.scala 15:11]
    inst readMuxes_0 of AXISlaveReadMux @[AXILiteXBar.scala 18:11]
    inst writeBuses_0 of AXIWriteBus @[AXILiteXBar.scala 23:11]
    inst writeMuxes_0 of AXISlaveWriteMux @[AXILiteXBar.scala 27:11]
    io_masters_0_aw_ready <= writeBuses_0.io_master_writeAddr_ready @[AXILiteXBar.scala 37:15]
    io_masters_0_w_ready <= writeBuses_0.io_master_writeData_ready @[AXILiteXBar.scala 38:14]
    io_masters_0_b_valid <= writeBuses_0.io_master_writeResp_valid @[AXILiteXBar.scala 39:14]
    io_masters_0_b_bits_id <= writeBuses_0.io_master_writeResp_bits_id @[AXILiteXBar.scala 39:14]
    io_masters_0_b_bits_resp <= writeBuses_0.io_master_writeResp_bits_resp @[AXILiteXBar.scala 39:14]
    io_masters_0_ar_ready <= readBuses_0.io_master_readAddr_ready @[AXILiteXBar.scala 32:15]
    io_masters_0_r_valid <= readBuses_0.io_master_readData_valid @[AXILiteXBar.scala 33:14]
    io_masters_0_r_bits_id <= readBuses_0.io_master_readData_bits_id @[AXILiteXBar.scala 33:14]
    io_masters_0_r_bits_data <= readBuses_0.io_master_readData_bits_data @[AXILiteXBar.scala 33:14]
    io_masters_0_r_bits_resp <= readBuses_0.io_master_readData_bits_resp @[AXILiteXBar.scala 33:14]
    io_masters_0_r_bits_last <= readBuses_0.io_master_readData_bits_last @[AXILiteXBar.scala 33:14]
    io_slaves_0_aw_valid <= writeMuxes_0.io_out_writeAddr_valid @[AXILiteXBar.scala 51:16]
    io_slaves_0_aw_bits_id <= writeMuxes_0.io_out_writeAddr_bits_id @[AXILiteXBar.scala 51:16]
    io_slaves_0_aw_bits_addr <= writeMuxes_0.io_out_writeAddr_bits_addr @[AXILiteXBar.scala 51:16]
    io_slaves_0_aw_bits_region <= writeMuxes_0.io_out_writeAddr_bits_region @[AXILiteXBar.scala 51:16]
    io_slaves_0_aw_bits_len <= writeMuxes_0.io_out_writeAddr_bits_len @[AXILiteXBar.scala 51:16]
    io_slaves_0_aw_bits_size <= writeMuxes_0.io_out_writeAddr_bits_size @[AXILiteXBar.scala 51:16]
    io_slaves_0_aw_bits_burst <= writeMuxes_0.io_out_writeAddr_bits_burst @[AXILiteXBar.scala 51:16]
    io_slaves_0_aw_bits_lock <= writeMuxes_0.io_out_writeAddr_bits_lock @[AXILiteXBar.scala 51:16]
    io_slaves_0_aw_bits_cache <= writeMuxes_0.io_out_writeAddr_bits_cache @[AXILiteXBar.scala 51:16]
    io_slaves_0_aw_bits_prot <= writeMuxes_0.io_out_writeAddr_bits_prot @[AXILiteXBar.scala 51:16]
    io_slaves_0_aw_bits_qos <= writeMuxes_0.io_out_writeAddr_bits_qos @[AXILiteXBar.scala 51:16]
    io_slaves_0_w_valid <= writeMuxes_0.io_out_writeData_valid @[AXILiteXBar.scala 52:15]
    io_slaves_0_w_bits_data <= writeMuxes_0.io_out_writeData_bits_data @[AXILiteXBar.scala 52:15]
    io_slaves_0_w_bits_strb <= writeMuxes_0.io_out_writeData_bits_strb @[AXILiteXBar.scala 52:15]
    io_slaves_0_w_bits_last <= writeMuxes_0.io_out_writeData_bits_last @[AXILiteXBar.scala 52:15]
    io_slaves_0_b_ready <= writeMuxes_0.io_out_writeResp_ready @[AXILiteXBar.scala 53:15]
    io_slaves_0_ar_valid <= readMuxes_0.io_out_readAddr_valid @[AXILiteXBar.scala 45:16]
    io_slaves_0_ar_bits_id <= readMuxes_0.io_out_readAddr_bits_id @[AXILiteXBar.scala 45:16]
    io_slaves_0_ar_bits_addr <= readMuxes_0.io_out_readAddr_bits_addr @[AXILiteXBar.scala 45:16]
    io_slaves_0_ar_bits_region <= readMuxes_0.io_out_readAddr_bits_region @[AXILiteXBar.scala 45:16]
    io_slaves_0_ar_bits_len <= readMuxes_0.io_out_readAddr_bits_len @[AXILiteXBar.scala 45:16]
    io_slaves_0_ar_bits_size <= readMuxes_0.io_out_readAddr_bits_size @[AXILiteXBar.scala 45:16]
    io_slaves_0_ar_bits_burst <= readMuxes_0.io_out_readAddr_bits_burst @[AXILiteXBar.scala 45:16]
    io_slaves_0_ar_bits_lock <= readMuxes_0.io_out_readAddr_bits_lock @[AXILiteXBar.scala 45:16]
    io_slaves_0_ar_bits_cache <= readMuxes_0.io_out_readAddr_bits_cache @[AXILiteXBar.scala 45:16]
    io_slaves_0_ar_bits_prot <= readMuxes_0.io_out_readAddr_bits_prot @[AXILiteXBar.scala 45:16]
    io_slaves_0_ar_bits_qos <= readMuxes_0.io_out_readAddr_bits_qos @[AXILiteXBar.scala 45:16]
    io_slaves_0_r_ready <= readMuxes_0.io_out_readData_ready @[AXILiteXBar.scala 46:15]
    readBuses_0.clock <= clock
    readBuses_0.reset <= reset
    readBuses_0.io_master_readAddr_valid <= io_masters_0_ar_valid @[AXILiteXBar.scala 32:15]
    readBuses_0.io_master_readAddr_bits_id <= io_masters_0_ar_bits_id @[AXILiteXBar.scala 32:15]
    readBuses_0.io_master_readAddr_bits_addr <= io_masters_0_ar_bits_addr @[AXILiteXBar.scala 32:15]
    readBuses_0.io_master_readAddr_bits_region <= io_masters_0_ar_bits_region @[AXILiteXBar.scala 32:15]
    readBuses_0.io_master_readAddr_bits_len <= io_masters_0_ar_bits_len @[AXILiteXBar.scala 32:15]
    readBuses_0.io_master_readAddr_bits_size <= io_masters_0_ar_bits_size @[AXILiteXBar.scala 32:15]
    readBuses_0.io_master_readAddr_bits_burst <= io_masters_0_ar_bits_burst @[AXILiteXBar.scala 32:15]
    readBuses_0.io_master_readAddr_bits_lock <= io_masters_0_ar_bits_lock @[AXILiteXBar.scala 32:15]
    readBuses_0.io_master_readAddr_bits_cache <= io_masters_0_ar_bits_cache @[AXILiteXBar.scala 32:15]
    readBuses_0.io_master_readAddr_bits_prot <= io_masters_0_ar_bits_prot @[AXILiteXBar.scala 32:15]
    readBuses_0.io_master_readAddr_bits_qos <= io_masters_0_ar_bits_qos @[AXILiteXBar.scala 32:15]
    readBuses_0.io_master_readData_ready <= io_masters_0_r_ready @[AXILiteXBar.scala 33:14]
    readBuses_0.io_slave_0_readAddr_ready <= readMuxes_0.io_in_0_readAddr_ready @[AXILiteXBar.scala 58:30]
    readBuses_0.io_slave_0_readData_valid <= readMuxes_0.io_in_0_readData_valid @[AXILiteXBar.scala 58:30]
    readBuses_0.io_slave_0_readData_bits_id <= readMuxes_0.io_in_0_readData_bits_id @[AXILiteXBar.scala 58:30]
    readBuses_0.io_slave_0_readData_bits_data <= readMuxes_0.io_in_0_readData_bits_data @[AXILiteXBar.scala 58:30]
    readBuses_0.io_slave_0_readData_bits_resp <= readMuxes_0.io_in_0_readData_bits_resp @[AXILiteXBar.scala 58:30]
    readBuses_0.io_slave_0_readData_bits_last <= readMuxes_0.io_in_0_readData_bits_last @[AXILiteXBar.scala 58:30]
    readMuxes_0.clock <= clock
    readMuxes_0.reset <= reset
    readMuxes_0.io_out_readAddr_ready <= io_slaves_0_ar_ready @[AXILiteXBar.scala 45:16]
    readMuxes_0.io_out_readData_valid <= io_slaves_0_r_valid @[AXILiteXBar.scala 46:15]
    readMuxes_0.io_out_readData_bits_id <= io_slaves_0_r_bits_id @[AXILiteXBar.scala 46:15]
    readMuxes_0.io_out_readData_bits_data <= io_slaves_0_r_bits_data @[AXILiteXBar.scala 46:15]
    readMuxes_0.io_out_readData_bits_resp <= io_slaves_0_r_bits_resp @[AXILiteXBar.scala 46:15]
    readMuxes_0.io_out_readData_bits_last <= io_slaves_0_r_bits_last @[AXILiteXBar.scala 46:15]
    readMuxes_0.io_in_0_readAddr_valid <= readBuses_0.io_slave_0_readAddr_valid @[AXILiteXBar.scala 58:30]
    readMuxes_0.io_in_0_readAddr_bits_id <= readBuses_0.io_slave_0_readAddr_bits_id @[AXILiteXBar.scala 58:30]
    readMuxes_0.io_in_0_readAddr_bits_addr <= readBuses_0.io_slave_0_readAddr_bits_addr @[AXILiteXBar.scala 58:30]
    readMuxes_0.io_in_0_readAddr_bits_region <= readBuses_0.io_slave_0_readAddr_bits_region @[AXILiteXBar.scala 58:30]
    readMuxes_0.io_in_0_readAddr_bits_len <= readBuses_0.io_slave_0_readAddr_bits_len @[AXILiteXBar.scala 58:30]
    readMuxes_0.io_in_0_readAddr_bits_size <= readBuses_0.io_slave_0_readAddr_bits_size @[AXILiteXBar.scala 58:30]
    readMuxes_0.io_in_0_readAddr_bits_burst <= readBuses_0.io_slave_0_readAddr_bits_burst @[AXILiteXBar.scala 58:30]
    readMuxes_0.io_in_0_readAddr_bits_lock <= readBuses_0.io_slave_0_readAddr_bits_lock @[AXILiteXBar.scala 58:30]
    readMuxes_0.io_in_0_readAddr_bits_cache <= readBuses_0.io_slave_0_readAddr_bits_cache @[AXILiteXBar.scala 58:30]
    readMuxes_0.io_in_0_readAddr_bits_prot <= readBuses_0.io_slave_0_readAddr_bits_prot @[AXILiteXBar.scala 58:30]
    readMuxes_0.io_in_0_readAddr_bits_qos <= readBuses_0.io_slave_0_readAddr_bits_qos @[AXILiteXBar.scala 58:30]
    readMuxes_0.io_in_0_readData_ready <= readBuses_0.io_slave_0_readData_ready @[AXILiteXBar.scala 58:30]
    writeBuses_0.clock <= clock
    writeBuses_0.reset <= reset
    writeBuses_0.io_master_writeAddr_valid <= io_masters_0_aw_valid @[AXILiteXBar.scala 37:15]
    writeBuses_0.io_master_writeAddr_bits_id <= io_masters_0_aw_bits_id @[AXILiteXBar.scala 37:15]
    writeBuses_0.io_master_writeAddr_bits_addr <= io_masters_0_aw_bits_addr @[AXILiteXBar.scala 37:15]
    writeBuses_0.io_master_writeAddr_bits_region <= io_masters_0_aw_bits_region @[AXILiteXBar.scala 37:15]
    writeBuses_0.io_master_writeAddr_bits_len <= io_masters_0_aw_bits_len @[AXILiteXBar.scala 37:15]
    writeBuses_0.io_master_writeAddr_bits_size <= io_masters_0_aw_bits_size @[AXILiteXBar.scala 37:15]
    writeBuses_0.io_master_writeAddr_bits_burst <= io_masters_0_aw_bits_burst @[AXILiteXBar.scala 37:15]
    writeBuses_0.io_master_writeAddr_bits_lock <= io_masters_0_aw_bits_lock @[AXILiteXBar.scala 37:15]
    writeBuses_0.io_master_writeAddr_bits_cache <= io_masters_0_aw_bits_cache @[AXILiteXBar.scala 37:15]
    writeBuses_0.io_master_writeAddr_bits_prot <= io_masters_0_aw_bits_prot @[AXILiteXBar.scala 37:15]
    writeBuses_0.io_master_writeAddr_bits_qos <= io_masters_0_aw_bits_qos @[AXILiteXBar.scala 37:15]
    writeBuses_0.io_master_writeData_valid <= io_masters_0_w_valid @[AXILiteXBar.scala 38:14]
    writeBuses_0.io_master_writeData_bits_data <= io_masters_0_w_bits_data @[AXILiteXBar.scala 38:14]
    writeBuses_0.io_master_writeData_bits_strb <= io_masters_0_w_bits_strb @[AXILiteXBar.scala 38:14]
    writeBuses_0.io_master_writeData_bits_last <= io_masters_0_w_bits_last @[AXILiteXBar.scala 38:14]
    writeBuses_0.io_master_writeResp_ready <= io_masters_0_b_ready @[AXILiteXBar.scala 39:14]
    writeBuses_0.io_slave_0_writeAddr_ready <= writeMuxes_0.io_in_0_writeAddr_ready @[AXILiteXBar.scala 62:31]
    writeBuses_0.io_slave_0_writeData_ready <= writeMuxes_0.io_in_0_writeData_ready @[AXILiteXBar.scala 62:31]
    writeBuses_0.io_slave_0_writeResp_valid <= writeMuxes_0.io_in_0_writeResp_valid @[AXILiteXBar.scala 62:31]
    writeBuses_0.io_slave_0_writeResp_bits_id <= writeMuxes_0.io_in_0_writeResp_bits_id @[AXILiteXBar.scala 62:31]
    writeBuses_0.io_slave_0_writeResp_bits_resp <= writeMuxes_0.io_in_0_writeResp_bits_resp @[AXILiteXBar.scala 62:31]
    writeMuxes_0.clock <= clock
    writeMuxes_0.reset <= reset
    writeMuxes_0.io_out_writeAddr_ready <= io_slaves_0_aw_ready @[AXILiteXBar.scala 51:16]
    writeMuxes_0.io_out_writeData_ready <= io_slaves_0_w_ready @[AXILiteXBar.scala 52:15]
    writeMuxes_0.io_out_writeResp_valid <= io_slaves_0_b_valid @[AXILiteXBar.scala 53:15]
    writeMuxes_0.io_out_writeResp_bits_id <= io_slaves_0_b_bits_id @[AXILiteXBar.scala 53:15]
    writeMuxes_0.io_out_writeResp_bits_resp <= io_slaves_0_b_bits_resp @[AXILiteXBar.scala 53:15]
    writeMuxes_0.io_in_0_writeAddr_valid <= writeBuses_0.io_slave_0_writeAddr_valid @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeAddr_bits_id <= writeBuses_0.io_slave_0_writeAddr_bits_id @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeAddr_bits_addr <= writeBuses_0.io_slave_0_writeAddr_bits_addr @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeAddr_bits_region <= writeBuses_0.io_slave_0_writeAddr_bits_region @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeAddr_bits_len <= writeBuses_0.io_slave_0_writeAddr_bits_len @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeAddr_bits_size <= writeBuses_0.io_slave_0_writeAddr_bits_size @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeAddr_bits_burst <= writeBuses_0.io_slave_0_writeAddr_bits_burst @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeAddr_bits_lock <= writeBuses_0.io_slave_0_writeAddr_bits_lock @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeAddr_bits_cache <= writeBuses_0.io_slave_0_writeAddr_bits_cache @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeAddr_bits_prot <= writeBuses_0.io_slave_0_writeAddr_bits_prot @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeAddr_bits_qos <= writeBuses_0.io_slave_0_writeAddr_bits_qos @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeData_valid <= writeBuses_0.io_slave_0_writeData_valid @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeData_bits_data <= writeBuses_0.io_slave_0_writeData_bits_data @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeData_bits_strb <= writeBuses_0.io_slave_0_writeData_bits_strb @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeData_bits_last <= writeBuses_0.io_slave_0_writeData_bits_last @[AXILiteXBar.scala 62:31]
    writeMuxes_0.io_in_0_writeResp_ready <= writeBuses_0.io_slave_0_writeResp_ready @[AXILiteXBar.scala 62:31]
