circuit AXISlaveReadMux :
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
