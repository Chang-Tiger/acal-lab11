// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_SoC__Syms.h"


//======================

void Vtop_SoC::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vtop_SoC::traceInit, &Vtop_SoC::traceFull, &Vtop_SoC::traceChg, this);
}
void Vtop_SoC::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop_SoC* t = (Vtop_SoC*)userthis;
    Vtop_SoC__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop_SoC::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop_SoC* t = (Vtop_SoC*)userthis;
    Vtop_SoC__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vtop_SoC::traceInitThis(Vtop_SoC__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop_SoC::traceFullThis(Vtop_SoC__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop_SoC::traceInitThis__1(Vtop_SoC__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+5993,"clock", false,-1);
        vcdp->declBit(c+6001,"reset", false,-1);
        vcdp->declBus(c+6009,"io_regs_0", false,-1, 31,0);
        vcdp->declBus(c+6017,"io_regs_1", false,-1, 31,0);
        vcdp->declBus(c+6025,"io_regs_2", false,-1, 31,0);
        vcdp->declBus(c+6033,"io_regs_3", false,-1, 31,0);
        vcdp->declBus(c+6041,"io_regs_4", false,-1, 31,0);
        vcdp->declBus(c+6049,"io_regs_5", false,-1, 31,0);
        vcdp->declBus(c+6057,"io_regs_6", false,-1, 31,0);
        vcdp->declBus(c+6065,"io_regs_7", false,-1, 31,0);
        vcdp->declBus(c+6073,"io_regs_8", false,-1, 31,0);
        vcdp->declBus(c+6081,"io_regs_9", false,-1, 31,0);
        vcdp->declBus(c+6089,"io_regs_10", false,-1, 31,0);
        vcdp->declBus(c+6097,"io_regs_11", false,-1, 31,0);
        vcdp->declBus(c+6105,"io_regs_12", false,-1, 31,0);
        vcdp->declBus(c+6113,"io_regs_13", false,-1, 31,0);
        vcdp->declBus(c+6121,"io_regs_14", false,-1, 31,0);
        vcdp->declBus(c+6129,"io_regs_15", false,-1, 31,0);
        vcdp->declBus(c+6137,"io_regs_16", false,-1, 31,0);
        vcdp->declBus(c+6145,"io_regs_17", false,-1, 31,0);
        vcdp->declBus(c+6153,"io_regs_18", false,-1, 31,0);
        vcdp->declBus(c+6161,"io_regs_19", false,-1, 31,0);
        vcdp->declBus(c+6169,"io_regs_20", false,-1, 31,0);
        vcdp->declBus(c+6177,"io_regs_21", false,-1, 31,0);
        vcdp->declBus(c+6185,"io_regs_22", false,-1, 31,0);
        vcdp->declBus(c+6193,"io_regs_23", false,-1, 31,0);
        vcdp->declBus(c+6201,"io_regs_24", false,-1, 31,0);
        vcdp->declBus(c+6209,"io_regs_25", false,-1, 31,0);
        vcdp->declBus(c+6217,"io_regs_26", false,-1, 31,0);
        vcdp->declBus(c+6225,"io_regs_27", false,-1, 31,0);
        vcdp->declBus(c+6233,"io_regs_28", false,-1, 31,0);
        vcdp->declBus(c+6241,"io_regs_29", false,-1, 31,0);
        vcdp->declBus(c+6249,"io_regs_30", false,-1, 31,0);
        vcdp->declBus(c+6257,"io_regs_31", false,-1, 31,0);
        vcdp->declBit(c+6265,"io_Hcf", false,-1);
        vcdp->declBus(c+6273,"io_inst", false,-1, 31,0);
        vcdp->declBus(c+6281,"io_rdata", false,-1, 31,0);
        vcdp->declBus(c+6289,"io_wdata", false,-1, 31,0);
        vcdp->declBit(c+6297,"io_Dump_Mem", false,-1);
        vcdp->declBit(c+6305,"io_E_Branch_taken", false,-1);
        vcdp->declBit(c+6313,"io_Flush", false,-1);
        vcdp->declBit(c+6321,"io_Stall_MA", false,-1);
        vcdp->declBit(c+6329,"io_Stall_DH", false,-1);
        vcdp->declBus(c+6337,"io_IF_PC", false,-1, 31,0);
        vcdp->declBus(c+6345,"io_ID_PC", false,-1, 31,0);
        vcdp->declBus(c+6353,"io_EXE_PC", false,-1, 31,0);
        vcdp->declBus(c+6361,"io_MEM_PC", false,-1, 31,0);
        vcdp->declBus(c+6369,"io_WB_PC", false,-1, 31,0);
        vcdp->declBus(c+6377,"io_EXE_alu_out", false,-1, 31,0);
        vcdp->declBus(c+6385,"io_EXE_src1", false,-1, 31,0);
        vcdp->declBus(c+6393,"io_EXE_src2", false,-1, 31,0);
        vcdp->declBus(c+6401,"io_ALU_src1", false,-1, 31,0);
        vcdp->declBus(c+6409,"io_ALU_src2", false,-1, 31,0);
        vcdp->declBus(c+6417,"io_raddr", false,-1, 31,0);
        vcdp->declBus(c+6425,"io_WB_rd", false,-1, 4,0);
        vcdp->declBus(c+6433,"io_WB_wdata", false,-1, 31,0);
        vcdp->declBit(c+6441,"io_EXE_Jump", false,-1);
        vcdp->declBit(c+6449,"io_EXE_Branch", false,-1);
        vcdp->declBit(c+6457,"io_DMA_Hcf", false,-1);
        vcdp->declBit(c+5993,"top_SoC clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC reset", false,-1);
        vcdp->declBus(c+6009,"top_SoC io_regs_0", false,-1, 31,0);
        vcdp->declBus(c+6017,"top_SoC io_regs_1", false,-1, 31,0);
        vcdp->declBus(c+6025,"top_SoC io_regs_2", false,-1, 31,0);
        vcdp->declBus(c+6033,"top_SoC io_regs_3", false,-1, 31,0);
        vcdp->declBus(c+6041,"top_SoC io_regs_4", false,-1, 31,0);
        vcdp->declBus(c+6049,"top_SoC io_regs_5", false,-1, 31,0);
        vcdp->declBus(c+6057,"top_SoC io_regs_6", false,-1, 31,0);
        vcdp->declBus(c+6065,"top_SoC io_regs_7", false,-1, 31,0);
        vcdp->declBus(c+6073,"top_SoC io_regs_8", false,-1, 31,0);
        vcdp->declBus(c+6081,"top_SoC io_regs_9", false,-1, 31,0);
        vcdp->declBus(c+6089,"top_SoC io_regs_10", false,-1, 31,0);
        vcdp->declBus(c+6097,"top_SoC io_regs_11", false,-1, 31,0);
        vcdp->declBus(c+6105,"top_SoC io_regs_12", false,-1, 31,0);
        vcdp->declBus(c+6113,"top_SoC io_regs_13", false,-1, 31,0);
        vcdp->declBus(c+6121,"top_SoC io_regs_14", false,-1, 31,0);
        vcdp->declBus(c+6129,"top_SoC io_regs_15", false,-1, 31,0);
        vcdp->declBus(c+6137,"top_SoC io_regs_16", false,-1, 31,0);
        vcdp->declBus(c+6145,"top_SoC io_regs_17", false,-1, 31,0);
        vcdp->declBus(c+6153,"top_SoC io_regs_18", false,-1, 31,0);
        vcdp->declBus(c+6161,"top_SoC io_regs_19", false,-1, 31,0);
        vcdp->declBus(c+6169,"top_SoC io_regs_20", false,-1, 31,0);
        vcdp->declBus(c+6177,"top_SoC io_regs_21", false,-1, 31,0);
        vcdp->declBus(c+6185,"top_SoC io_regs_22", false,-1, 31,0);
        vcdp->declBus(c+6193,"top_SoC io_regs_23", false,-1, 31,0);
        vcdp->declBus(c+6201,"top_SoC io_regs_24", false,-1, 31,0);
        vcdp->declBus(c+6209,"top_SoC io_regs_25", false,-1, 31,0);
        vcdp->declBus(c+6217,"top_SoC io_regs_26", false,-1, 31,0);
        vcdp->declBus(c+6225,"top_SoC io_regs_27", false,-1, 31,0);
        vcdp->declBus(c+6233,"top_SoC io_regs_28", false,-1, 31,0);
        vcdp->declBus(c+6241,"top_SoC io_regs_29", false,-1, 31,0);
        vcdp->declBus(c+6249,"top_SoC io_regs_30", false,-1, 31,0);
        vcdp->declBus(c+6257,"top_SoC io_regs_31", false,-1, 31,0);
        vcdp->declBit(c+6265,"top_SoC io_Hcf", false,-1);
        vcdp->declBus(c+6273,"top_SoC io_inst", false,-1, 31,0);
        vcdp->declBus(c+6281,"top_SoC io_rdata", false,-1, 31,0);
        vcdp->declBus(c+6289,"top_SoC io_wdata", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC io_Dump_Mem", false,-1);
        vcdp->declBit(c+6305,"top_SoC io_E_Branch_taken", false,-1);
        vcdp->declBit(c+6313,"top_SoC io_Flush", false,-1);
        vcdp->declBit(c+6321,"top_SoC io_Stall_MA", false,-1);
        vcdp->declBit(c+6329,"top_SoC io_Stall_DH", false,-1);
        vcdp->declBus(c+6337,"top_SoC io_IF_PC", false,-1, 31,0);
        vcdp->declBus(c+6345,"top_SoC io_ID_PC", false,-1, 31,0);
        vcdp->declBus(c+6353,"top_SoC io_EXE_PC", false,-1, 31,0);
        vcdp->declBus(c+6361,"top_SoC io_MEM_PC", false,-1, 31,0);
        vcdp->declBus(c+6369,"top_SoC io_WB_PC", false,-1, 31,0);
        vcdp->declBus(c+6377,"top_SoC io_EXE_alu_out", false,-1, 31,0);
        vcdp->declBus(c+6385,"top_SoC io_EXE_src1", false,-1, 31,0);
        vcdp->declBus(c+6393,"top_SoC io_EXE_src2", false,-1, 31,0);
        vcdp->declBus(c+6401,"top_SoC io_ALU_src1", false,-1, 31,0);
        vcdp->declBus(c+6409,"top_SoC io_ALU_src2", false,-1, 31,0);
        vcdp->declBus(c+6417,"top_SoC io_raddr", false,-1, 31,0);
        vcdp->declBus(c+6425,"top_SoC io_WB_rd", false,-1, 4,0);
        vcdp->declBus(c+6433,"top_SoC io_WB_wdata", false,-1, 31,0);
        vcdp->declBit(c+6441,"top_SoC io_EXE_Jump", false,-1);
        vcdp->declBit(c+6449,"top_SoC io_EXE_Branch", false,-1);
        vcdp->declBit(c+6457,"top_SoC io_DMA_Hcf", false,-1);
        vcdp->declBit(c+5993,"top_SoC dma_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC dma_reset", false,-1);
        vcdp->declBit(c+2969,"top_SoC dma_io_slave_aw_ready", false,-1);
        vcdp->declBit(c+2977,"top_SoC dma_io_slave_aw_valid", false,-1);
        vcdp->declBus(c+2985,"top_SoC dma_io_slave_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+2993,"top_SoC dma_io_slave_aw_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6465,"top_SoC dma_io_slave_aw_bits_region", false,-1, 3,0);
        vcdp->declBus(c+6473,"top_SoC dma_io_slave_aw_bits_len", false,-1, 7,0);
        vcdp->declBus(c+3001,"top_SoC dma_io_slave_aw_bits_size", false,-1, 1,0);
        vcdp->declBus(c+6481,"top_SoC dma_io_slave_aw_bits_burst", false,-1, 1,0);
        vcdp->declBit(c+6489,"top_SoC dma_io_slave_aw_bits_lock", false,-1);
        vcdp->declBus(c+6465,"top_SoC dma_io_slave_aw_bits_cache", false,-1, 3,0);
        vcdp->declBus(c+6497,"top_SoC dma_io_slave_aw_bits_prot", false,-1, 2,0);
        vcdp->declBus(c+6465,"top_SoC dma_io_slave_aw_bits_qos", false,-1, 3,0);
        vcdp->declBit(c+1,"top_SoC dma_io_slave_w_ready", false,-1);
        vcdp->declBit(c+3009,"top_SoC dma_io_slave_w_valid", false,-1);
        vcdp->declBus(c+3017,"top_SoC dma_io_slave_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3025,"top_SoC dma_io_slave_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3033,"top_SoC dma_io_slave_w_bits_last", false,-1);
        vcdp->declBit(c+9,"top_SoC dma_io_slave_b_ready", false,-1);
        vcdp->declBit(c+3041,"top_SoC dma_io_slave_b_valid", false,-1);
        vcdp->declBus(c+3049,"top_SoC dma_io_slave_b_bits_id", false,-1, 3,0);
        vcdp->declBus(c+6481,"top_SoC dma_io_slave_b_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3057,"top_SoC dma_io_slave_ar_ready", false,-1);
        vcdp->declBit(c+3065,"top_SoC dma_io_slave_ar_valid", false,-1);
        vcdp->declBus(c+3073,"top_SoC dma_io_slave_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3081,"top_SoC dma_io_slave_ar_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6465,"top_SoC dma_io_slave_ar_bits_region", false,-1, 3,0);
        vcdp->declBus(c+6473,"top_SoC dma_io_slave_ar_bits_len", false,-1, 7,0);
        vcdp->declBus(c+3089,"top_SoC dma_io_slave_ar_bits_size", false,-1, 1,0);
        vcdp->declBus(c+6481,"top_SoC dma_io_slave_ar_bits_burst", false,-1, 1,0);
        vcdp->declBit(c+6489,"top_SoC dma_io_slave_ar_bits_lock", false,-1);
        vcdp->declBus(c+6465,"top_SoC dma_io_slave_ar_bits_cache", false,-1, 3,0);
        vcdp->declBus(c+6497,"top_SoC dma_io_slave_ar_bits_prot", false,-1, 2,0);
        vcdp->declBus(c+6465,"top_SoC dma_io_slave_ar_bits_qos", false,-1, 3,0);
        vcdp->declBit(c+17,"top_SoC dma_io_slave_r_ready", false,-1);
        vcdp->declBit(c+3097,"top_SoC dma_io_slave_r_valid", false,-1);
        vcdp->declBus(c+3105,"top_SoC dma_io_slave_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3113,"top_SoC dma_io_slave_r_bits_data", false,-1, 31,0);
        vcdp->declBus(c+6481,"top_SoC dma_io_slave_r_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+6505,"top_SoC dma_io_slave_r_bits_last", false,-1);
        vcdp->declBit(c+3121,"top_SoC dma_io_master_aw_ready", false,-1);
        vcdp->declBit(c+25,"top_SoC dma_io_master_aw_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC dma_io_master_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+33,"top_SoC dma_io_master_aw_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6465,"top_SoC dma_io_master_aw_bits_region", false,-1, 3,0);
        vcdp->declBus(c+6473,"top_SoC dma_io_master_aw_bits_len", false,-1, 7,0);
        vcdp->declBus(c+6513,"top_SoC dma_io_master_aw_bits_size", false,-1, 1,0);
        vcdp->declBus(c+6481,"top_SoC dma_io_master_aw_bits_burst", false,-1, 1,0);
        vcdp->declBit(c+6489,"top_SoC dma_io_master_aw_bits_lock", false,-1);
        vcdp->declBus(c+6465,"top_SoC dma_io_master_aw_bits_cache", false,-1, 3,0);
        vcdp->declBus(c+6497,"top_SoC dma_io_master_aw_bits_prot", false,-1, 2,0);
        vcdp->declBus(c+6465,"top_SoC dma_io_master_aw_bits_qos", false,-1, 3,0);
        vcdp->declBit(c+3129,"top_SoC dma_io_master_w_ready", false,-1);
        vcdp->declBit(c+3137,"top_SoC dma_io_master_w_valid", false,-1);
        vcdp->declBus(c+41,"top_SoC dma_io_master_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+49,"top_SoC dma_io_master_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+6505,"top_SoC dma_io_master_w_bits_last", false,-1);
        vcdp->declBit(c+3145,"top_SoC dma_io_master_b_ready", false,-1);
        vcdp->declBit(c+3153,"top_SoC dma_io_master_b_valid", false,-1);
        vcdp->declBus(c+3161,"top_SoC dma_io_master_b_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3169,"top_SoC dma_io_master_b_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3177,"top_SoC dma_io_master_ar_ready", false,-1);
        vcdp->declBit(c+3185,"top_SoC dma_io_master_ar_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC dma_io_master_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+57,"top_SoC dma_io_master_ar_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6465,"top_SoC dma_io_master_ar_bits_region", false,-1, 3,0);
        vcdp->declBus(c+6473,"top_SoC dma_io_master_ar_bits_len", false,-1, 7,0);
        vcdp->declBus(c+6513,"top_SoC dma_io_master_ar_bits_size", false,-1, 1,0);
        vcdp->declBus(c+6481,"top_SoC dma_io_master_ar_bits_burst", false,-1, 1,0);
        vcdp->declBit(c+6489,"top_SoC dma_io_master_ar_bits_lock", false,-1);
        vcdp->declBus(c+6465,"top_SoC dma_io_master_ar_bits_cache", false,-1, 3,0);
        vcdp->declBus(c+6497,"top_SoC dma_io_master_ar_bits_prot", false,-1, 2,0);
        vcdp->declBus(c+6465,"top_SoC dma_io_master_ar_bits_qos", false,-1, 3,0);
        vcdp->declBit(c+3193,"top_SoC dma_io_master_r_ready", false,-1);
        vcdp->declBit(c+65,"top_SoC dma_io_master_r_valid", false,-1);
        vcdp->declBus(c+3201,"top_SoC dma_io_master_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+73,"top_SoC dma_io_master_r_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3209,"top_SoC dma_io_master_r_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3217,"top_SoC dma_io_master_r_bits_last", false,-1);
        vcdp->declBit(c+3225,"top_SoC dma_io_Hcf", false,-1);
        vcdp->declBit(c+5993,"top_SoC cpu_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu_reset", false,-1);
        vcdp->declBus(c+3233,"top_SoC cpu_io_InstMem_raddr", false,-1, 14,0);
        vcdp->declBus(c+81,"top_SoC cpu_io_InstMem_rdata", false,-1, 31,0);
        vcdp->declBit(c+3241,"top_SoC cpu_io_DataMem_Mem_R", false,-1);
        vcdp->declBit(c+3249,"top_SoC cpu_io_DataMem_Mem_W", false,-1);
        vcdp->declBus(c+3257,"top_SoC cpu_io_DataMem_Length", false,-1, 3,0);
        vcdp->declBus(c+3265,"top_SoC cpu_io_DataMem_raddr", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu_io_DataMem_waddr", false,-1, 31,0);
        vcdp->declBus(c+3273,"top_SoC cpu_io_DataMem_wdata", false,-1, 31,0);
        vcdp->declBit(c+3281,"top_SoC cpu_io_master_aw_ready", false,-1);
        vcdp->declBit(c+3289,"top_SoC cpu_io_master_aw_valid", false,-1);
        vcdp->declBus(c+89,"top_SoC cpu_io_master_aw_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+3297,"top_SoC cpu_io_master_w_ready", false,-1);
        vcdp->declBit(c+3289,"top_SoC cpu_io_master_w_valid", false,-1);
        vcdp->declBus(c+97,"top_SoC cpu_io_master_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3305,"top_SoC cpu_io_master_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+105,"top_SoC cpu_io_master_b_ready", false,-1);
        vcdp->declBit(c+3313,"top_SoC cpu_io_master_b_valid", false,-1);
        vcdp->declBit(c+3321,"top_SoC cpu_io_master_ar_ready", false,-1);
        vcdp->declBit(c+3329,"top_SoC cpu_io_master_ar_valid", false,-1);
        vcdp->declBus(c+113,"top_SoC cpu_io_master_ar_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+121,"top_SoC cpu_io_master_r_ready", false,-1);
        vcdp->declBit(c+129,"top_SoC cpu_io_master_r_valid", false,-1);
        vcdp->declBus(c+137,"top_SoC cpu_io_master_r_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3337,"top_SoC cpu_io_regs_1", false,-1, 31,0);
        vcdp->declBus(c+3345,"top_SoC cpu_io_regs_2", false,-1, 31,0);
        vcdp->declBus(c+3353,"top_SoC cpu_io_regs_3", false,-1, 31,0);
        vcdp->declBus(c+3361,"top_SoC cpu_io_regs_4", false,-1, 31,0);
        vcdp->declBus(c+3369,"top_SoC cpu_io_regs_5", false,-1, 31,0);
        vcdp->declBus(c+3377,"top_SoC cpu_io_regs_6", false,-1, 31,0);
        vcdp->declBus(c+3385,"top_SoC cpu_io_regs_7", false,-1, 31,0);
        vcdp->declBus(c+3393,"top_SoC cpu_io_regs_8", false,-1, 31,0);
        vcdp->declBus(c+3401,"top_SoC cpu_io_regs_9", false,-1, 31,0);
        vcdp->declBus(c+3409,"top_SoC cpu_io_regs_10", false,-1, 31,0);
        vcdp->declBus(c+3417,"top_SoC cpu_io_regs_11", false,-1, 31,0);
        vcdp->declBus(c+3425,"top_SoC cpu_io_regs_12", false,-1, 31,0);
        vcdp->declBus(c+3433,"top_SoC cpu_io_regs_13", false,-1, 31,0);
        vcdp->declBus(c+3441,"top_SoC cpu_io_regs_14", false,-1, 31,0);
        vcdp->declBus(c+3449,"top_SoC cpu_io_regs_15", false,-1, 31,0);
        vcdp->declBus(c+3457,"top_SoC cpu_io_regs_16", false,-1, 31,0);
        vcdp->declBus(c+3465,"top_SoC cpu_io_regs_17", false,-1, 31,0);
        vcdp->declBus(c+3473,"top_SoC cpu_io_regs_18", false,-1, 31,0);
        vcdp->declBus(c+3481,"top_SoC cpu_io_regs_19", false,-1, 31,0);
        vcdp->declBus(c+3489,"top_SoC cpu_io_regs_20", false,-1, 31,0);
        vcdp->declBus(c+3497,"top_SoC cpu_io_regs_21", false,-1, 31,0);
        vcdp->declBus(c+3505,"top_SoC cpu_io_regs_22", false,-1, 31,0);
        vcdp->declBus(c+3513,"top_SoC cpu_io_regs_23", false,-1, 31,0);
        vcdp->declBus(c+3521,"top_SoC cpu_io_regs_24", false,-1, 31,0);
        vcdp->declBus(c+3529,"top_SoC cpu_io_regs_25", false,-1, 31,0);
        vcdp->declBus(c+3537,"top_SoC cpu_io_regs_26", false,-1, 31,0);
        vcdp->declBus(c+3545,"top_SoC cpu_io_regs_27", false,-1, 31,0);
        vcdp->declBus(c+3553,"top_SoC cpu_io_regs_28", false,-1, 31,0);
        vcdp->declBus(c+3561,"top_SoC cpu_io_regs_29", false,-1, 31,0);
        vcdp->declBus(c+3569,"top_SoC cpu_io_regs_30", false,-1, 31,0);
        vcdp->declBus(c+3577,"top_SoC cpu_io_regs_31", false,-1, 31,0);
        vcdp->declBit(c+145,"top_SoC cpu_io_Hcf", false,-1);
        vcdp->declBit(c+3225,"top_SoC cpu_io_DMA_Hcf", false,-1);
        vcdp->declBit(c+153,"top_SoC cpu_io_E_Branch_taken", false,-1);
        vcdp->declBit(c+161,"top_SoC cpu_io_Flush", false,-1);
        vcdp->declBit(c+169,"top_SoC cpu_io_Stall_MA", false,-1);
        vcdp->declBit(c+177,"top_SoC cpu_io_Stall_DH", false,-1);
        vcdp->declBus(c+3585,"top_SoC cpu_io_IF_PC", false,-1, 31,0);
        vcdp->declBus(c+3593,"top_SoC cpu_io_ID_PC", false,-1, 31,0);
        vcdp->declBus(c+3601,"top_SoC cpu_io_EXE_PC", false,-1, 31,0);
        vcdp->declBus(c+3609,"top_SoC cpu_io_MEM_PC", false,-1, 31,0);
        vcdp->declBus(c+3617,"top_SoC cpu_io_WB_PC", false,-1, 31,0);
        vcdp->declBus(c+3625,"top_SoC cpu_io_EXE_src1", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu_io_EXE_src2", false,-1, 31,0);
        vcdp->declBus(c+185,"top_SoC cpu_io_ALU_src1", false,-1, 31,0);
        vcdp->declBus(c+193,"top_SoC cpu_io_ALU_src2", false,-1, 31,0);
        vcdp->declBus(c+201,"top_SoC cpu_io_EXE_alu_out", false,-1, 31,0);
        vcdp->declBus(c+3641,"top_SoC cpu_io_WB_rd", false,-1, 4,0);
        vcdp->declBus(c+209,"top_SoC cpu_io_WB_wdata", false,-1, 31,0);
        vcdp->declBit(c+3649,"top_SoC cpu_io_EXE_Jump", false,-1);
        vcdp->declBit(c+3657,"top_SoC cpu_io_EXE_Branch", false,-1);
        vcdp->declBit(c+5993,"top_SoC im_clock", false,-1);
        vcdp->declBus(c+3233,"top_SoC im_io_raddr", false,-1, 14,0);
        vcdp->declBus(c+81,"top_SoC im_io_inst", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC bus_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus_reset", false,-1);
        vcdp->declBit(c+3281,"top_SoC bus_io_masters_0_aw_ready", false,-1);
        vcdp->declBit(c+3289,"top_SoC bus_io_masters_0_aw_valid", false,-1);
        vcdp->declBus(c+89,"top_SoC bus_io_masters_0_aw_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+3297,"top_SoC bus_io_masters_0_w_ready", false,-1);
        vcdp->declBit(c+3289,"top_SoC bus_io_masters_0_w_valid", false,-1);
        vcdp->declBus(c+97,"top_SoC bus_io_masters_0_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3305,"top_SoC bus_io_masters_0_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+105,"top_SoC bus_io_masters_0_b_ready", false,-1);
        vcdp->declBit(c+3313,"top_SoC bus_io_masters_0_b_valid", false,-1);
        vcdp->declBit(c+3321,"top_SoC bus_io_masters_0_ar_ready", false,-1);
        vcdp->declBit(c+3329,"top_SoC bus_io_masters_0_ar_valid", false,-1);
        vcdp->declBus(c+113,"top_SoC bus_io_masters_0_ar_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+121,"top_SoC bus_io_masters_0_r_ready", false,-1);
        vcdp->declBit(c+129,"top_SoC bus_io_masters_0_r_valid", false,-1);
        vcdp->declBus(c+137,"top_SoC bus_io_masters_0_r_bits_data", false,-1, 31,0);
        vcdp->declBit(c+3121,"top_SoC bus_io_masters_1_aw_ready", false,-1);
        vcdp->declBit(c+25,"top_SoC bus_io_masters_1_aw_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC bus_io_masters_1_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+33,"top_SoC bus_io_masters_1_aw_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6513,"top_SoC bus_io_masters_1_aw_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3129,"top_SoC bus_io_masters_1_w_ready", false,-1);
        vcdp->declBit(c+3137,"top_SoC bus_io_masters_1_w_valid", false,-1);
        vcdp->declBus(c+41,"top_SoC bus_io_masters_1_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+49,"top_SoC bus_io_masters_1_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+6505,"top_SoC bus_io_masters_1_w_bits_last", false,-1);
        vcdp->declBit(c+3145,"top_SoC bus_io_masters_1_b_ready", false,-1);
        vcdp->declBit(c+3153,"top_SoC bus_io_masters_1_b_valid", false,-1);
        vcdp->declBus(c+3161,"top_SoC bus_io_masters_1_b_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3169,"top_SoC bus_io_masters_1_b_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3177,"top_SoC bus_io_masters_1_ar_ready", false,-1);
        vcdp->declBit(c+3185,"top_SoC bus_io_masters_1_ar_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC bus_io_masters_1_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+57,"top_SoC bus_io_masters_1_ar_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6513,"top_SoC bus_io_masters_1_ar_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3193,"top_SoC bus_io_masters_1_r_ready", false,-1);
        vcdp->declBit(c+65,"top_SoC bus_io_masters_1_r_valid", false,-1);
        vcdp->declBus(c+3201,"top_SoC bus_io_masters_1_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+73,"top_SoC bus_io_masters_1_r_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3209,"top_SoC bus_io_masters_1_r_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3217,"top_SoC bus_io_masters_1_r_bits_last", false,-1);
        vcdp->declBit(c+2969,"top_SoC bus_io_slaves_0_aw_ready", false,-1);
        vcdp->declBit(c+2977,"top_SoC bus_io_slaves_0_aw_valid", false,-1);
        vcdp->declBus(c+2985,"top_SoC bus_io_slaves_0_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+2993,"top_SoC bus_io_slaves_0_aw_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+3001,"top_SoC bus_io_slaves_0_aw_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1,"top_SoC bus_io_slaves_0_w_ready", false,-1);
        vcdp->declBit(c+3009,"top_SoC bus_io_slaves_0_w_valid", false,-1);
        vcdp->declBus(c+3017,"top_SoC bus_io_slaves_0_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3025,"top_SoC bus_io_slaves_0_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3033,"top_SoC bus_io_slaves_0_w_bits_last", false,-1);
        vcdp->declBit(c+9,"top_SoC bus_io_slaves_0_b_ready", false,-1);
        vcdp->declBit(c+3041,"top_SoC bus_io_slaves_0_b_valid", false,-1);
        vcdp->declBus(c+3049,"top_SoC bus_io_slaves_0_b_bits_id", false,-1, 3,0);
        vcdp->declBus(c+6481,"top_SoC bus_io_slaves_0_b_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3057,"top_SoC bus_io_slaves_0_ar_ready", false,-1);
        vcdp->declBit(c+3065,"top_SoC bus_io_slaves_0_ar_valid", false,-1);
        vcdp->declBus(c+3073,"top_SoC bus_io_slaves_0_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3081,"top_SoC bus_io_slaves_0_ar_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+3089,"top_SoC bus_io_slaves_0_ar_bits_size", false,-1, 1,0);
        vcdp->declBit(c+17,"top_SoC bus_io_slaves_0_r_ready", false,-1);
        vcdp->declBit(c+3097,"top_SoC bus_io_slaves_0_r_valid", false,-1);
        vcdp->declBus(c+3105,"top_SoC bus_io_slaves_0_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3113,"top_SoC bus_io_slaves_0_r_bits_data", false,-1, 31,0);
        vcdp->declBus(c+6481,"top_SoC bus_io_slaves_0_r_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+6505,"top_SoC bus_io_slaves_0_r_bits_last", false,-1);
        vcdp->declBit(c+3665,"top_SoC bus_io_slaves_1_aw_ready", false,-1);
        vcdp->declBit(c+3673,"top_SoC bus_io_slaves_1_aw_valid", false,-1);
        vcdp->declBus(c+3681,"top_SoC bus_io_slaves_1_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3689,"top_SoC bus_io_slaves_1_aw_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+3697,"top_SoC bus_io_slaves_1_w_ready", false,-1);
        vcdp->declBit(c+3705,"top_SoC bus_io_slaves_1_w_valid", false,-1);
        vcdp->declBus(c+3713,"top_SoC bus_io_slaves_1_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3721,"top_SoC bus_io_slaves_1_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3729,"top_SoC bus_io_slaves_1_w_bits_last", false,-1);
        vcdp->declBit(c+217,"top_SoC bus_io_slaves_1_b_ready", false,-1);
        vcdp->declBit(c+3737,"top_SoC bus_io_slaves_1_b_valid", false,-1);
        vcdp->declBus(c+3745,"top_SoC bus_io_slaves_1_b_bits_id", false,-1, 3,0);
        vcdp->declBit(c+3753,"top_SoC bus_io_slaves_1_ar_ready", false,-1);
        vcdp->declBit(c+3761,"top_SoC bus_io_slaves_1_ar_valid", false,-1);
        vcdp->declBus(c+3769,"top_SoC bus_io_slaves_1_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3777,"top_SoC bus_io_slaves_1_ar_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+225,"top_SoC bus_io_slaves_1_r_ready", false,-1);
        vcdp->declBit(c+233,"top_SoC bus_io_slaves_1_r_valid", false,-1);
        vcdp->declBus(c+3785,"top_SoC bus_io_slaves_1_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+241,"top_SoC bus_io_slaves_1_r_bits_data", false,-1, 31,0);
        vcdp->declBit(c+3793,"top_SoC bus_io_slaves_1_r_bits_last", false,-1);
        vcdp->declBit(c+3801,"top_SoC bus_io_slaves_2_aw_ready", false,-1);
        vcdp->declBit(c+3809,"top_SoC bus_io_slaves_2_aw_valid", false,-1);
        vcdp->declBus(c+3817,"top_SoC bus_io_slaves_2_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3825,"top_SoC bus_io_slaves_2_aw_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+3833,"top_SoC bus_io_slaves_2_w_ready", false,-1);
        vcdp->declBit(c+3841,"top_SoC bus_io_slaves_2_w_valid", false,-1);
        vcdp->declBus(c+3849,"top_SoC bus_io_slaves_2_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3857,"top_SoC bus_io_slaves_2_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3865,"top_SoC bus_io_slaves_2_w_bits_last", false,-1);
        vcdp->declBit(c+249,"top_SoC bus_io_slaves_2_b_ready", false,-1);
        vcdp->declBit(c+3873,"top_SoC bus_io_slaves_2_b_valid", false,-1);
        vcdp->declBus(c+3881,"top_SoC bus_io_slaves_2_b_bits_id", false,-1, 3,0);
        vcdp->declBit(c+3889,"top_SoC bus_io_slaves_2_ar_ready", false,-1);
        vcdp->declBit(c+3897,"top_SoC bus_io_slaves_2_ar_valid", false,-1);
        vcdp->declBus(c+3905,"top_SoC bus_io_slaves_2_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3913,"top_SoC bus_io_slaves_2_ar_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+257,"top_SoC bus_io_slaves_2_r_ready", false,-1);
        vcdp->declBit(c+265,"top_SoC bus_io_slaves_2_r_valid", false,-1);
        vcdp->declBus(c+3921,"top_SoC bus_io_slaves_2_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+273,"top_SoC bus_io_slaves_2_r_bits_data", false,-1, 31,0);
        vcdp->declBit(c+3929,"top_SoC bus_io_slaves_2_r_bits_last", false,-1);
        vcdp->declBit(c+5993,"top_SoC localMem_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC localMem_reset", false,-1);
        vcdp->declBit(c+3665,"top_SoC localMem_io_slave_aw_ready", false,-1);
        vcdp->declBit(c+3673,"top_SoC localMem_io_slave_aw_valid", false,-1);
        vcdp->declBus(c+3681,"top_SoC localMem_io_slave_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3689,"top_SoC localMem_io_slave_aw_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+3697,"top_SoC localMem_io_slave_w_ready", false,-1);
        vcdp->declBit(c+3705,"top_SoC localMem_io_slave_w_valid", false,-1);
        vcdp->declBus(c+3713,"top_SoC localMem_io_slave_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3721,"top_SoC localMem_io_slave_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3729,"top_SoC localMem_io_slave_w_bits_last", false,-1);
        vcdp->declBit(c+217,"top_SoC localMem_io_slave_b_ready", false,-1);
        vcdp->declBit(c+3737,"top_SoC localMem_io_slave_b_valid", false,-1);
        vcdp->declBus(c+3745,"top_SoC localMem_io_slave_b_bits_id", false,-1, 3,0);
        vcdp->declBit(c+3753,"top_SoC localMem_io_slave_ar_ready", false,-1);
        vcdp->declBit(c+3761,"top_SoC localMem_io_slave_ar_valid", false,-1);
        vcdp->declBus(c+3769,"top_SoC localMem_io_slave_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3777,"top_SoC localMem_io_slave_ar_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+225,"top_SoC localMem_io_slave_r_ready", false,-1);
        vcdp->declBit(c+233,"top_SoC localMem_io_slave_r_valid", false,-1);
        vcdp->declBus(c+3785,"top_SoC localMem_io_slave_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+241,"top_SoC localMem_io_slave_r_bits_data", false,-1, 31,0);
        vcdp->declBit(c+3793,"top_SoC localMem_io_slave_r_bits_last", false,-1);
        vcdp->declBit(c+6297,"top_SoC localMem_io_dump", false,-1);
        vcdp->declBit(c+5993,"top_SoC globalMem_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC globalMem_reset", false,-1);
        vcdp->declBit(c+3801,"top_SoC globalMem_io_slave_aw_ready", false,-1);
        vcdp->declBit(c+3809,"top_SoC globalMem_io_slave_aw_valid", false,-1);
        vcdp->declBus(c+3817,"top_SoC globalMem_io_slave_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3825,"top_SoC globalMem_io_slave_aw_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+3833,"top_SoC globalMem_io_slave_w_ready", false,-1);
        vcdp->declBit(c+3841,"top_SoC globalMem_io_slave_w_valid", false,-1);
        vcdp->declBus(c+3849,"top_SoC globalMem_io_slave_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3857,"top_SoC globalMem_io_slave_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3865,"top_SoC globalMem_io_slave_w_bits_last", false,-1);
        vcdp->declBit(c+249,"top_SoC globalMem_io_slave_b_ready", false,-1);
        vcdp->declBit(c+3873,"top_SoC globalMem_io_slave_b_valid", false,-1);
        vcdp->declBus(c+3881,"top_SoC globalMem_io_slave_b_bits_id", false,-1, 3,0);
        vcdp->declBit(c+3889,"top_SoC globalMem_io_slave_ar_ready", false,-1);
        vcdp->declBit(c+3897,"top_SoC globalMem_io_slave_ar_valid", false,-1);
        vcdp->declBus(c+3905,"top_SoC globalMem_io_slave_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3913,"top_SoC globalMem_io_slave_ar_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+257,"top_SoC globalMem_io_slave_r_ready", false,-1);
        vcdp->declBit(c+265,"top_SoC globalMem_io_slave_r_valid", false,-1);
        vcdp->declBus(c+3921,"top_SoC globalMem_io_slave_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+273,"top_SoC globalMem_io_slave_r_bits_data", false,-1, 31,0);
        vcdp->declBit(c+3929,"top_SoC globalMem_io_slave_r_bits_last", false,-1);
        vcdp->declBit(c+5993,"top_SoC dma clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC dma reset", false,-1);
        vcdp->declBit(c+2969,"top_SoC dma io_slave_aw_ready", false,-1);
        vcdp->declBit(c+2977,"top_SoC dma io_slave_aw_valid", false,-1);
        vcdp->declBus(c+2985,"top_SoC dma io_slave_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+2993,"top_SoC dma io_slave_aw_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6465,"top_SoC dma io_slave_aw_bits_region", false,-1, 3,0);
        vcdp->declBus(c+6473,"top_SoC dma io_slave_aw_bits_len", false,-1, 7,0);
        vcdp->declBus(c+3001,"top_SoC dma io_slave_aw_bits_size", false,-1, 1,0);
        vcdp->declBus(c+6481,"top_SoC dma io_slave_aw_bits_burst", false,-1, 1,0);
        vcdp->declBit(c+6489,"top_SoC dma io_slave_aw_bits_lock", false,-1);
        vcdp->declBus(c+6465,"top_SoC dma io_slave_aw_bits_cache", false,-1, 3,0);
        vcdp->declBus(c+6497,"top_SoC dma io_slave_aw_bits_prot", false,-1, 2,0);
        vcdp->declBus(c+6465,"top_SoC dma io_slave_aw_bits_qos", false,-1, 3,0);
        vcdp->declBit(c+1,"top_SoC dma io_slave_w_ready", false,-1);
        vcdp->declBit(c+3009,"top_SoC dma io_slave_w_valid", false,-1);
        vcdp->declBus(c+3017,"top_SoC dma io_slave_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3025,"top_SoC dma io_slave_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3033,"top_SoC dma io_slave_w_bits_last", false,-1);
        vcdp->declBit(c+9,"top_SoC dma io_slave_b_ready", false,-1);
        vcdp->declBit(c+3041,"top_SoC dma io_slave_b_valid", false,-1);
        vcdp->declBus(c+3049,"top_SoC dma io_slave_b_bits_id", false,-1, 3,0);
        vcdp->declBus(c+6481,"top_SoC dma io_slave_b_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3057,"top_SoC dma io_slave_ar_ready", false,-1);
        vcdp->declBit(c+3065,"top_SoC dma io_slave_ar_valid", false,-1);
        vcdp->declBus(c+3073,"top_SoC dma io_slave_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3081,"top_SoC dma io_slave_ar_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6465,"top_SoC dma io_slave_ar_bits_region", false,-1, 3,0);
        vcdp->declBus(c+6473,"top_SoC dma io_slave_ar_bits_len", false,-1, 7,0);
        vcdp->declBus(c+3089,"top_SoC dma io_slave_ar_bits_size", false,-1, 1,0);
        vcdp->declBus(c+6481,"top_SoC dma io_slave_ar_bits_burst", false,-1, 1,0);
        vcdp->declBit(c+6489,"top_SoC dma io_slave_ar_bits_lock", false,-1);
        vcdp->declBus(c+6465,"top_SoC dma io_slave_ar_bits_cache", false,-1, 3,0);
        vcdp->declBus(c+6497,"top_SoC dma io_slave_ar_bits_prot", false,-1, 2,0);
        vcdp->declBus(c+6465,"top_SoC dma io_slave_ar_bits_qos", false,-1, 3,0);
        vcdp->declBit(c+17,"top_SoC dma io_slave_r_ready", false,-1);
        vcdp->declBit(c+3097,"top_SoC dma io_slave_r_valid", false,-1);
        vcdp->declBus(c+3105,"top_SoC dma io_slave_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3113,"top_SoC dma io_slave_r_bits_data", false,-1, 31,0);
        vcdp->declBus(c+6481,"top_SoC dma io_slave_r_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+6505,"top_SoC dma io_slave_r_bits_last", false,-1);
        vcdp->declBit(c+3121,"top_SoC dma io_master_aw_ready", false,-1);
        vcdp->declBit(c+25,"top_SoC dma io_master_aw_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC dma io_master_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+33,"top_SoC dma io_master_aw_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6465,"top_SoC dma io_master_aw_bits_region", false,-1, 3,0);
        vcdp->declBus(c+6473,"top_SoC dma io_master_aw_bits_len", false,-1, 7,0);
        vcdp->declBus(c+6513,"top_SoC dma io_master_aw_bits_size", false,-1, 1,0);
        vcdp->declBus(c+6481,"top_SoC dma io_master_aw_bits_burst", false,-1, 1,0);
        vcdp->declBit(c+6489,"top_SoC dma io_master_aw_bits_lock", false,-1);
        vcdp->declBus(c+6465,"top_SoC dma io_master_aw_bits_cache", false,-1, 3,0);
        vcdp->declBus(c+6497,"top_SoC dma io_master_aw_bits_prot", false,-1, 2,0);
        vcdp->declBus(c+6465,"top_SoC dma io_master_aw_bits_qos", false,-1, 3,0);
        vcdp->declBit(c+3129,"top_SoC dma io_master_w_ready", false,-1);
        vcdp->declBit(c+3137,"top_SoC dma io_master_w_valid", false,-1);
        vcdp->declBus(c+41,"top_SoC dma io_master_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+49,"top_SoC dma io_master_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+6505,"top_SoC dma io_master_w_bits_last", false,-1);
        vcdp->declBit(c+3145,"top_SoC dma io_master_b_ready", false,-1);
        vcdp->declBit(c+3153,"top_SoC dma io_master_b_valid", false,-1);
        vcdp->declBus(c+3161,"top_SoC dma io_master_b_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3169,"top_SoC dma io_master_b_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3177,"top_SoC dma io_master_ar_ready", false,-1);
        vcdp->declBit(c+3185,"top_SoC dma io_master_ar_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC dma io_master_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+57,"top_SoC dma io_master_ar_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6465,"top_SoC dma io_master_ar_bits_region", false,-1, 3,0);
        vcdp->declBus(c+6473,"top_SoC dma io_master_ar_bits_len", false,-1, 7,0);
        vcdp->declBus(c+6513,"top_SoC dma io_master_ar_bits_size", false,-1, 1,0);
        vcdp->declBus(c+6481,"top_SoC dma io_master_ar_bits_burst", false,-1, 1,0);
        vcdp->declBit(c+6489,"top_SoC dma io_master_ar_bits_lock", false,-1);
        vcdp->declBus(c+6465,"top_SoC dma io_master_ar_bits_cache", false,-1, 3,0);
        vcdp->declBus(c+6497,"top_SoC dma io_master_ar_bits_prot", false,-1, 2,0);
        vcdp->declBus(c+6465,"top_SoC dma io_master_ar_bits_qos", false,-1, 3,0);
        vcdp->declBit(c+3193,"top_SoC dma io_master_r_ready", false,-1);
        vcdp->declBit(c+65,"top_SoC dma io_master_r_valid", false,-1);
        vcdp->declBus(c+3201,"top_SoC dma io_master_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+73,"top_SoC dma io_master_r_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3209,"top_SoC dma io_master_r_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3217,"top_SoC dma io_master_r_bits_last", false,-1);
        vcdp->declBit(c+3225,"top_SoC dma io_Hcf", false,-1);
        vcdp->declBus(c+3937,"top_SoC dma mState", false,-1, 2,0);
        vcdp->declBit(c+3097,"top_SoC dma sReadState", false,-1);
        vcdp->declBus(c+3945,"top_SoC dma sWriteState", false,-1, 1,0);
        vcdp->declBus(c+3953,"top_SoC dma sReadAddrReg", false,-1, 31,0);
        vcdp->declBus(c+3105,"top_SoC dma sReadIDReg", false,-1, 3,0);
        vcdp->declBus(c+3049,"top_SoC dma sWriteIDReg", false,-1, 3,0);
        vcdp->declBit(c+3961,"top_SoC dma sWriteDataRecv", false,-1);
        vcdp->declBit(c+3969,"top_SoC dma sWriteAddrRecv", false,-1);
        vcdp->declBus(c+3977,"top_SoC dma sWriteDataReg", false,-1, 31,0);
        vcdp->declBus(c+3985,"top_SoC dma sWriteAddrReg", false,-1, 31,0);
        vcdp->declBus(c+3985,"top_SoC dma sWriteAddrOffset", false,-1, 31,0);
        vcdp->declBus(c+3953,"top_SoC dma sReadAddrOffset", false,-1, 31,0);
        vcdp->declBit(c+3993,"top_SoC dma mWriteAddrSent", false,-1);
        vcdp->declBit(c+4001,"top_SoC dma mWriteDataSent", false,-1);
        vcdp->declBit(c+4009,"top_SoC dma mReadlast", false,-1);
        vcdp->declBus(c+4017,"top_SoC dma mmio_regs_0", false,-1, 31,0);
        vcdp->declBus(c+4025,"top_SoC dma mmio_regs_1", false,-1, 31,0);
        vcdp->declBus(c+4033,"top_SoC dma mmio_regs_2", false,-1, 31,0);
        vcdp->declBus(c+4041,"top_SoC dma mmio_regs_3", false,-1, 31,0);
        vcdp->declBus(c+4049,"top_SoC dma mmio_regs_4", false,-1, 31,0);
        vcdp->declBus(c+4057,"top_SoC dma mmio_regs_5", false,-1, 31,0);
        vcdp->declBus(c+4065,"top_SoC dma data_buffer", false,-1, 31,0);
        vcdp->declBus(c+4073,"top_SoC dma source_offset", false,-1, 1,0);
        vcdp->declBus(c+281,"top_SoC dma dest_offset", false,-1, 1,0);
        vcdp->declBus(c+4081,"top_SoC dma request_counter", false,-1, 31,0);
        vcdp->declBus(c+289,"top_SoC dma mask_width", false,-1, 3,0);
        vcdp->declBus(c+297,"top_SoC dma rData_mask", false,-1, 3,0);
        vcdp->declBus(c+305,"top_SoC dma rData_1", false,-1, 7,0);
        vcdp->declBus(c+313,"top_SoC dma rData_0", false,-1, 7,0);
        vcdp->declBus(c+321,"top_SoC dma rData_3", false,-1, 7,0);
        vcdp->declBus(c+329,"top_SoC dma rData_2", false,-1, 7,0);
        vcdp->declBit(c+5993,"top_SoC cpu clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu reset", false,-1);
        vcdp->declBus(c+3233,"top_SoC cpu io_InstMem_raddr", false,-1, 14,0);
        vcdp->declBus(c+81,"top_SoC cpu io_InstMem_rdata", false,-1, 31,0);
        vcdp->declBit(c+3241,"top_SoC cpu io_DataMem_Mem_R", false,-1);
        vcdp->declBit(c+3249,"top_SoC cpu io_DataMem_Mem_W", false,-1);
        vcdp->declBus(c+3257,"top_SoC cpu io_DataMem_Length", false,-1, 3,0);
        vcdp->declBus(c+3265,"top_SoC cpu io_DataMem_raddr", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu io_DataMem_waddr", false,-1, 31,0);
        vcdp->declBus(c+3273,"top_SoC cpu io_DataMem_wdata", false,-1, 31,0);
        vcdp->declBit(c+3281,"top_SoC cpu io_master_aw_ready", false,-1);
        vcdp->declBit(c+3289,"top_SoC cpu io_master_aw_valid", false,-1);
        vcdp->declBus(c+89,"top_SoC cpu io_master_aw_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+3297,"top_SoC cpu io_master_w_ready", false,-1);
        vcdp->declBit(c+3289,"top_SoC cpu io_master_w_valid", false,-1);
        vcdp->declBus(c+97,"top_SoC cpu io_master_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3305,"top_SoC cpu io_master_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+105,"top_SoC cpu io_master_b_ready", false,-1);
        vcdp->declBit(c+3313,"top_SoC cpu io_master_b_valid", false,-1);
        vcdp->declBit(c+3321,"top_SoC cpu io_master_ar_ready", false,-1);
        vcdp->declBit(c+3329,"top_SoC cpu io_master_ar_valid", false,-1);
        vcdp->declBus(c+113,"top_SoC cpu io_master_ar_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+121,"top_SoC cpu io_master_r_ready", false,-1);
        vcdp->declBit(c+129,"top_SoC cpu io_master_r_valid", false,-1);
        vcdp->declBus(c+137,"top_SoC cpu io_master_r_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3337,"top_SoC cpu io_regs_1", false,-1, 31,0);
        vcdp->declBus(c+3345,"top_SoC cpu io_regs_2", false,-1, 31,0);
        vcdp->declBus(c+3353,"top_SoC cpu io_regs_3", false,-1, 31,0);
        vcdp->declBus(c+3361,"top_SoC cpu io_regs_4", false,-1, 31,0);
        vcdp->declBus(c+3369,"top_SoC cpu io_regs_5", false,-1, 31,0);
        vcdp->declBus(c+3377,"top_SoC cpu io_regs_6", false,-1, 31,0);
        vcdp->declBus(c+3385,"top_SoC cpu io_regs_7", false,-1, 31,0);
        vcdp->declBus(c+3393,"top_SoC cpu io_regs_8", false,-1, 31,0);
        vcdp->declBus(c+3401,"top_SoC cpu io_regs_9", false,-1, 31,0);
        vcdp->declBus(c+3409,"top_SoC cpu io_regs_10", false,-1, 31,0);
        vcdp->declBus(c+3417,"top_SoC cpu io_regs_11", false,-1, 31,0);
        vcdp->declBus(c+3425,"top_SoC cpu io_regs_12", false,-1, 31,0);
        vcdp->declBus(c+3433,"top_SoC cpu io_regs_13", false,-1, 31,0);
        vcdp->declBus(c+3441,"top_SoC cpu io_regs_14", false,-1, 31,0);
        vcdp->declBus(c+3449,"top_SoC cpu io_regs_15", false,-1, 31,0);
        vcdp->declBus(c+3457,"top_SoC cpu io_regs_16", false,-1, 31,0);
        vcdp->declBus(c+3465,"top_SoC cpu io_regs_17", false,-1, 31,0);
        vcdp->declBus(c+3473,"top_SoC cpu io_regs_18", false,-1, 31,0);
        vcdp->declBus(c+3481,"top_SoC cpu io_regs_19", false,-1, 31,0);
        vcdp->declBus(c+3489,"top_SoC cpu io_regs_20", false,-1, 31,0);
        vcdp->declBus(c+3497,"top_SoC cpu io_regs_21", false,-1, 31,0);
        vcdp->declBus(c+3505,"top_SoC cpu io_regs_22", false,-1, 31,0);
        vcdp->declBus(c+3513,"top_SoC cpu io_regs_23", false,-1, 31,0);
        vcdp->declBus(c+3521,"top_SoC cpu io_regs_24", false,-1, 31,0);
        vcdp->declBus(c+3529,"top_SoC cpu io_regs_25", false,-1, 31,0);
        vcdp->declBus(c+3537,"top_SoC cpu io_regs_26", false,-1, 31,0);
        vcdp->declBus(c+3545,"top_SoC cpu io_regs_27", false,-1, 31,0);
        vcdp->declBus(c+3553,"top_SoC cpu io_regs_28", false,-1, 31,0);
        vcdp->declBus(c+3561,"top_SoC cpu io_regs_29", false,-1, 31,0);
        vcdp->declBus(c+3569,"top_SoC cpu io_regs_30", false,-1, 31,0);
        vcdp->declBus(c+3577,"top_SoC cpu io_regs_31", false,-1, 31,0);
        vcdp->declBit(c+145,"top_SoC cpu io_Hcf", false,-1);
        vcdp->declBit(c+3225,"top_SoC cpu io_DMA_Hcf", false,-1);
        vcdp->declBit(c+153,"top_SoC cpu io_E_Branch_taken", false,-1);
        vcdp->declBit(c+161,"top_SoC cpu io_Flush", false,-1);
        vcdp->declBit(c+169,"top_SoC cpu io_Stall_MA", false,-1);
        vcdp->declBit(c+177,"top_SoC cpu io_Stall_DH", false,-1);
        vcdp->declBus(c+3585,"top_SoC cpu io_IF_PC", false,-1, 31,0);
        vcdp->declBus(c+3593,"top_SoC cpu io_ID_PC", false,-1, 31,0);
        vcdp->declBus(c+3601,"top_SoC cpu io_EXE_PC", false,-1, 31,0);
        vcdp->declBus(c+3609,"top_SoC cpu io_MEM_PC", false,-1, 31,0);
        vcdp->declBus(c+3617,"top_SoC cpu io_WB_PC", false,-1, 31,0);
        vcdp->declBus(c+3625,"top_SoC cpu io_EXE_src1", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu io_EXE_src2", false,-1, 31,0);
        vcdp->declBus(c+185,"top_SoC cpu io_ALU_src1", false,-1, 31,0);
        vcdp->declBus(c+193,"top_SoC cpu io_ALU_src2", false,-1, 31,0);
        vcdp->declBus(c+201,"top_SoC cpu io_EXE_alu_out", false,-1, 31,0);
        vcdp->declBus(c+3641,"top_SoC cpu io_WB_rd", false,-1, 4,0);
        vcdp->declBus(c+209,"top_SoC cpu io_WB_wdata", false,-1, 31,0);
        vcdp->declBit(c+3649,"top_SoC cpu io_EXE_Jump", false,-1);
        vcdp->declBit(c+3657,"top_SoC cpu io_EXE_Branch", false,-1);
        vcdp->declBit(c+5993,"top_SoC cpu stage_IF_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu stage_IF_reset", false,-1);
        vcdp->declBit(c+337,"top_SoC cpu stage_IF_io_Stall", false,-1);
        vcdp->declBus(c+345,"top_SoC cpu stage_IF_io_next_pc_in", false,-1, 31,0);
        vcdp->declBus(c+3585,"top_SoC cpu stage_IF_io_pc", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC cpu stage_ID_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu stage_ID_reset", false,-1);
        vcdp->declBit(c+161,"top_SoC cpu stage_ID_io_Flush", false,-1);
        vcdp->declBit(c+353,"top_SoC cpu stage_ID_io_Stall", false,-1);
        vcdp->declBus(c+3585,"top_SoC cpu stage_ID_io_pc_in", false,-1, 31,0);
        vcdp->declBus(c+81,"top_SoC cpu stage_ID_io_inst_in", false,-1, 31,0);
        vcdp->declBus(c+3593,"top_SoC cpu stage_ID_io_pc", false,-1, 31,0);
        vcdp->declBus(c+4089,"top_SoC cpu stage_ID_io_inst", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC cpu stage_EXE_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu stage_EXE_reset", false,-1);
        vcdp->declBit(c+361,"top_SoC cpu stage_EXE_io_Flush", false,-1);
        vcdp->declBit(c+369,"top_SoC cpu stage_EXE_io_Stall", false,-1);
        vcdp->declBus(c+4089,"top_SoC cpu stage_EXE_io_inst_in", false,-1, 31,0);
        vcdp->declBus(c+3593,"top_SoC cpu stage_EXE_io_pc_in", false,-1, 31,0);
        vcdp->declBus(c+377,"top_SoC cpu stage_EXE_io_rs1_rdata_in", false,-1, 31,0);
        vcdp->declBus(c+385,"top_SoC cpu stage_EXE_io_rs2_rdata_in", false,-1, 31,0);
        vcdp->declBus(c+393,"top_SoC cpu stage_EXE_io_imm_in", false,-1, 31,0);
        vcdp->declBus(c+4097,"top_SoC cpu stage_EXE_io_inst", false,-1, 31,0);
        vcdp->declBus(c+3601,"top_SoC cpu stage_EXE_io_pc", false,-1, 31,0);
        vcdp->declBus(c+3625,"top_SoC cpu stage_EXE_io_rs1_rdata", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu stage_EXE_io_rs2_rdata", false,-1, 31,0);
        vcdp->declBus(c+4105,"top_SoC cpu stage_EXE_io_imm", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC cpu stage_MEM_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu stage_MEM_reset", false,-1);
        vcdp->declBit(c+369,"top_SoC cpu stage_MEM_io_Stall", false,-1);
        vcdp->declBus(c+3601,"top_SoC cpu stage_MEM_io_pc_in", false,-1, 31,0);
        vcdp->declBus(c+4097,"top_SoC cpu stage_MEM_io_inst_in", false,-1, 31,0);
        vcdp->declBus(c+201,"top_SoC cpu stage_MEM_io_alu_out_in", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu stage_MEM_io_DM_wdata_in", false,-1, 31,0);
        vcdp->declBus(c+3609,"top_SoC cpu stage_MEM_io_pc", false,-1, 31,0);
        vcdp->declBus(c+4113,"top_SoC cpu stage_MEM_io_inst", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu stage_MEM_io_alu_out", false,-1, 31,0);
        vcdp->declBus(c+3273,"top_SoC cpu stage_MEM_io_DM_wdata", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC cpu stage_WB_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu stage_WB_reset", false,-1);
        vcdp->declBit(c+369,"top_SoC cpu stage_WB_io_Stall", false,-1);
        vcdp->declBus(c+4121,"top_SoC cpu stage_WB_io_pc_plus4_in", false,-1, 31,0);
        vcdp->declBus(c+4113,"top_SoC cpu stage_WB_io_inst_in", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu stage_WB_io_alu_out_in", false,-1, 31,0);
        vcdp->declBus(c+401,"top_SoC cpu stage_WB_io_ld_data_in", false,-1, 31,0);
        vcdp->declBus(c+4129,"top_SoC cpu stage_WB_io_pc_plus4", false,-1, 31,0);
        vcdp->declBus(c+4137,"top_SoC cpu stage_WB_io_inst", false,-1, 31,0);
        vcdp->declBus(c+4145,"top_SoC cpu stage_WB_io_alu_out", false,-1, 31,0);
        vcdp->declBus(c+4153,"top_SoC cpu stage_WB_io_ld_data", false,-1, 31,0);
        vcdp->declBus(c+409,"top_SoC cpu datapath_IF_io_PCSel", false,-1, 1,0);
        vcdp->declBus(c+3585,"top_SoC cpu datapath_IF_io_IF_pc_in", false,-1, 31,0);
        vcdp->declBus(c+3601,"top_SoC cpu datapath_IF_io_EXE_pc_in", false,-1, 31,0);
        vcdp->declBus(c+201,"top_SoC cpu datapath_IF_io_EXE_target_pc_in", false,-1, 31,0);
        vcdp->declBus(c+81,"top_SoC cpu datapath_IF_io_Mem_data", false,-1, 31,0);
        vcdp->declBus(c+345,"top_SoC cpu datapath_IF_io_next_pc", false,-1, 31,0);
        vcdp->declBus(c+3585,"top_SoC cpu datapath_IF_io_Mem_Addr", false,-1, 31,0);
        vcdp->declBus(c+81,"top_SoC cpu datapath_IF_io_inst", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC cpu datapath_ID_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu datapath_ID_reset", false,-1);
        vcdp->declBus(c+4089,"top_SoC cpu datapath_ID_io_ID_inst_in", false,-1, 31,0);
        vcdp->declBus(c+3641,"top_SoC cpu datapath_ID_io_WB_index", false,-1, 4,0);
        vcdp->declBus(c+209,"top_SoC cpu datapath_ID_io_WB_wdata", false,-1, 31,0);
        vcdp->declBit(c+417,"top_SoC cpu datapath_ID_io_WB_RegWEn", false,-1);
        vcdp->declBus(c+425,"top_SoC cpu datapath_ID_io_ImmSel", false,-1, 2,0);
        vcdp->declBus(c+377,"top_SoC cpu datapath_ID_io_ID_rs1_rdata", false,-1, 31,0);
        vcdp->declBus(c+385,"top_SoC cpu datapath_ID_io_ID_rs2_rdata", false,-1, 31,0);
        vcdp->declBus(c+393,"top_SoC cpu datapath_ID_io_imm", false,-1, 31,0);
        vcdp->declBus(c+3337,"top_SoC cpu datapath_ID_io_regs_1", false,-1, 31,0);
        vcdp->declBus(c+3345,"top_SoC cpu datapath_ID_io_regs_2", false,-1, 31,0);
        vcdp->declBus(c+3353,"top_SoC cpu datapath_ID_io_regs_3", false,-1, 31,0);
        vcdp->declBus(c+3361,"top_SoC cpu datapath_ID_io_regs_4", false,-1, 31,0);
        vcdp->declBus(c+3369,"top_SoC cpu datapath_ID_io_regs_5", false,-1, 31,0);
        vcdp->declBus(c+3377,"top_SoC cpu datapath_ID_io_regs_6", false,-1, 31,0);
        vcdp->declBus(c+3385,"top_SoC cpu datapath_ID_io_regs_7", false,-1, 31,0);
        vcdp->declBus(c+3393,"top_SoC cpu datapath_ID_io_regs_8", false,-1, 31,0);
        vcdp->declBus(c+3401,"top_SoC cpu datapath_ID_io_regs_9", false,-1, 31,0);
        vcdp->declBus(c+3409,"top_SoC cpu datapath_ID_io_regs_10", false,-1, 31,0);
        vcdp->declBus(c+3417,"top_SoC cpu datapath_ID_io_regs_11", false,-1, 31,0);
        vcdp->declBus(c+3425,"top_SoC cpu datapath_ID_io_regs_12", false,-1, 31,0);
        vcdp->declBus(c+3433,"top_SoC cpu datapath_ID_io_regs_13", false,-1, 31,0);
        vcdp->declBus(c+3441,"top_SoC cpu datapath_ID_io_regs_14", false,-1, 31,0);
        vcdp->declBus(c+3449,"top_SoC cpu datapath_ID_io_regs_15", false,-1, 31,0);
        vcdp->declBus(c+3457,"top_SoC cpu datapath_ID_io_regs_16", false,-1, 31,0);
        vcdp->declBus(c+3465,"top_SoC cpu datapath_ID_io_regs_17", false,-1, 31,0);
        vcdp->declBus(c+3473,"top_SoC cpu datapath_ID_io_regs_18", false,-1, 31,0);
        vcdp->declBus(c+3481,"top_SoC cpu datapath_ID_io_regs_19", false,-1, 31,0);
        vcdp->declBus(c+3489,"top_SoC cpu datapath_ID_io_regs_20", false,-1, 31,0);
        vcdp->declBus(c+3497,"top_SoC cpu datapath_ID_io_regs_21", false,-1, 31,0);
        vcdp->declBus(c+3505,"top_SoC cpu datapath_ID_io_regs_22", false,-1, 31,0);
        vcdp->declBus(c+3513,"top_SoC cpu datapath_ID_io_regs_23", false,-1, 31,0);
        vcdp->declBus(c+3521,"top_SoC cpu datapath_ID_io_regs_24", false,-1, 31,0);
        vcdp->declBus(c+3529,"top_SoC cpu datapath_ID_io_regs_25", false,-1, 31,0);
        vcdp->declBus(c+3537,"top_SoC cpu datapath_ID_io_regs_26", false,-1, 31,0);
        vcdp->declBus(c+3545,"top_SoC cpu datapath_ID_io_regs_27", false,-1, 31,0);
        vcdp->declBus(c+3553,"top_SoC cpu datapath_ID_io_regs_28", false,-1, 31,0);
        vcdp->declBus(c+3561,"top_SoC cpu datapath_ID_io_regs_29", false,-1, 31,0);
        vcdp->declBus(c+3569,"top_SoC cpu datapath_ID_io_regs_30", false,-1, 31,0);
        vcdp->declBus(c+3577,"top_SoC cpu datapath_ID_io_regs_31", false,-1, 31,0);
        vcdp->declBus(c+3601,"top_SoC cpu datapath_EXE_io_EXE_pc_in", false,-1, 31,0);
        vcdp->declBus(c+4105,"top_SoC cpu datapath_EXE_io_EXE_imm_in", false,-1, 31,0);
        vcdp->declBus(c+3625,"top_SoC cpu datapath_EXE_io_EXE_rs1_rdata_in", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu datapath_EXE_io_EXE_rs2_rdata_in", false,-1, 31,0);
        vcdp->declBus(c+433,"top_SoC cpu datapath_EXE_io_E_ASel", false,-1, 1,0);
        vcdp->declBit(c+441,"top_SoC cpu datapath_EXE_io_E_BSel", false,-1);
        vcdp->declBit(c+4161,"top_SoC cpu datapath_EXE_io_E_BrUn", false,-1);
        vcdp->declBus(c+449,"top_SoC cpu datapath_EXE_io_E_ALUSel", false,-1, 14,0);
        vcdp->declBus(c+201,"top_SoC cpu datapath_EXE_io_EXE_target_pc_out", false,-1, 31,0);
        vcdp->declBus(c+201,"top_SoC cpu datapath_EXE_io_EXE_alu_out", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu datapath_EXE_io_EXE_rs2_rdata_out", false,-1, 31,0);
        vcdp->declBit(c+457,"top_SoC cpu datapath_EXE_io_E_BrEq", false,-1);
        vcdp->declBit(c+465,"top_SoC cpu datapath_EXE_io_E_BrLT", false,-1);
        vcdp->declBus(c+185,"top_SoC cpu datapath_EXE_io_alu_src1", false,-1, 31,0);
        vcdp->declBus(c+193,"top_SoC cpu datapath_EXE_io_alu_src2", false,-1, 31,0);
        vcdp->declBus(c+3625,"top_SoC cpu datapath_EXE_io_EXE_src1", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu datapath_EXE_io_EXE_src2", false,-1, 31,0);
        vcdp->declBus(c+3609,"top_SoC cpu datapath_MEM_io_MEM_pc_in", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu datapath_MEM_io_MEM_alu_out_in", false,-1, 31,0);
        vcdp->declBus(c+3273,"top_SoC cpu datapath_MEM_io_MEM_DM_wdata_in", false,-1, 31,0);
        vcdp->declBus(c+4121,"top_SoC cpu datapath_MEM_io_MEM_pc_plus_4", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu datapath_MEM_io_MEM_alu_out", false,-1, 31,0);
        vcdp->declBus(c+401,"top_SoC cpu datapath_MEM_io_MEM_ld_data", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu datapath_MEM_io_Mem_Addr", false,-1, 31,0);
        vcdp->declBus(c+3273,"top_SoC cpu datapath_MEM_io_Mem_Write_Data", false,-1, 31,0);
        vcdp->declBus(c+401,"top_SoC cpu datapath_MEM_io_Mem_Data", false,-1, 31,0);
        vcdp->declBus(c+4129,"top_SoC cpu datapath_WB_io_WB_pc_plus4_in", false,-1, 31,0);
        vcdp->declBus(c+4145,"top_SoC cpu datapath_WB_io_WB_alu_out_in", false,-1, 31,0);
        vcdp->declBus(c+4153,"top_SoC cpu datapath_WB_io_WB_ld_data_in", false,-1, 31,0);
        vcdp->declBus(c+473,"top_SoC cpu datapath_WB_io_W_WBSel", false,-1, 1,0);
        vcdp->declBus(c+209,"top_SoC cpu datapath_WB_io_WB_wdata", false,-1, 31,0);
        vcdp->declBit(c+3241,"top_SoC cpu contorller_io_DM_Mem_R", false,-1);
        vcdp->declBit(c+3249,"top_SoC cpu contorller_io_DM_Mem_W", false,-1);
        vcdp->declBus(c+3257,"top_SoC cpu contorller_io_DM_Length", false,-1, 3,0);
        vcdp->declBit(c+457,"top_SoC cpu contorller_io_E_BrEq", false,-1);
        vcdp->declBit(c+465,"top_SoC cpu contorller_io_E_BrLT", false,-1);
        vcdp->declBit(c+153,"top_SoC cpu contorller_io_E_Branch_taken", false,-1);
        vcdp->declBus(c+3593,"top_SoC cpu contorller_io_ID_pc", false,-1, 31,0);
        vcdp->declBus(c+201,"top_SoC cpu contorller_io_EXE_target_pc", false,-1, 31,0);
        vcdp->declBit(c+177,"top_SoC cpu contorller_io_Flush_WB_ID_DH", false,-1);
        vcdp->declBit(c+161,"top_SoC cpu contorller_io_Flush_BH", false,-1);
        vcdp->declBit(c+177,"top_SoC cpu contorller_io_Stall_WB_ID_DH", false,-1);
        vcdp->declBus(c+81,"top_SoC cpu contorller_io_IF_Inst", false,-1, 31,0);
        vcdp->declBus(c+4089,"top_SoC cpu contorller_io_ID_Inst", false,-1, 31,0);
        vcdp->declBus(c+4097,"top_SoC cpu contorller_io_EXE_Inst", false,-1, 31,0);
        vcdp->declBus(c+4113,"top_SoC cpu contorller_io_MEM_Inst", false,-1, 31,0);
        vcdp->declBus(c+4137,"top_SoC cpu contorller_io_WB_Inst", false,-1, 31,0);
        vcdp->declBus(c+409,"top_SoC cpu contorller_io_PCSel", false,-1, 1,0);
        vcdp->declBus(c+425,"top_SoC cpu contorller_io_D_ImmSel", false,-1, 2,0);
        vcdp->declBit(c+417,"top_SoC cpu contorller_io_W_RegWEn", false,-1);
        vcdp->declBit(c+4161,"top_SoC cpu contorller_io_E_BrUn", false,-1);
        vcdp->declBus(c+433,"top_SoC cpu contorller_io_E_ASel", false,-1, 1,0);
        vcdp->declBit(c+441,"top_SoC cpu contorller_io_E_BSel", false,-1);
        vcdp->declBus(c+449,"top_SoC cpu contorller_io_E_ALUSel", false,-1, 14,0);
        vcdp->declBus(c+473,"top_SoC cpu contorller_io_W_WBSel", false,-1, 1,0);
        vcdp->declBit(c+145,"top_SoC cpu contorller_io_Hcf", false,-1);
        vcdp->declBus(c+4169,"top_SoC cpu w_choose_byte", false,-1, 31,0);
        vcdp->declBus(c+4177,"top_SoC cpu w_choose_half", false,-1, 31,0);
        vcdp->declBus(c+4185,"top_SoC cpu write_shift_bit", false,-1, 4,0);
        vcdp->declBus(c+4169,"top_SoC cpu r_choose_byte", false,-1, 31,0);
        vcdp->declBus(c+4177,"top_SoC cpu r_choose_half", false,-1, 31,0);
        vcdp->declBus(c+4193,"top_SoC cpu r_mask", false,-1, 31,0);
        vcdp->declBus(c+4185,"top_SoC cpu read_shift_bit", false,-1, 4,0);
        vcdp->declBit(c+4201,"top_SoC cpu WMEM_Stall", false,-1);
        vcdp->declBit(c+481,"top_SoC cpu RMEM_Stall", false,-1);
        vcdp->declBus(c+4209,"top_SoC cpu wState", false,-1, 1,0);
        vcdp->declBus(c+4217,"top_SoC cpu rState", false,-1, 1,0);
        vcdp->declBit(c+5993,"top_SoC cpu stage_IF clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu stage_IF reset", false,-1);
        vcdp->declBit(c+337,"top_SoC cpu stage_IF io_Stall", false,-1);
        vcdp->declBus(c+345,"top_SoC cpu stage_IF io_next_pc_in", false,-1, 31,0);
        vcdp->declBus(c+3585,"top_SoC cpu stage_IF io_pc", false,-1, 31,0);
        vcdp->declBus(c+3585,"top_SoC cpu stage_IF pcReg", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC cpu stage_ID clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu stage_ID reset", false,-1);
        vcdp->declBit(c+161,"top_SoC cpu stage_ID io_Flush", false,-1);
        vcdp->declBit(c+353,"top_SoC cpu stage_ID io_Stall", false,-1);
        vcdp->declBus(c+3585,"top_SoC cpu stage_ID io_pc_in", false,-1, 31,0);
        vcdp->declBus(c+81,"top_SoC cpu stage_ID io_inst_in", false,-1, 31,0);
        vcdp->declBus(c+3593,"top_SoC cpu stage_ID io_pc", false,-1, 31,0);
        vcdp->declBus(c+4089,"top_SoC cpu stage_ID io_inst", false,-1, 31,0);
        vcdp->declBus(c+4089,"top_SoC cpu stage_ID InstReg", false,-1, 31,0);
        vcdp->declBus(c+4225,"top_SoC cpu stage_ID pcReg", false,-1, 14,0);
        vcdp->declBit(c+5993,"top_SoC cpu stage_EXE clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu stage_EXE reset", false,-1);
        vcdp->declBit(c+361,"top_SoC cpu stage_EXE io_Flush", false,-1);
        vcdp->declBit(c+369,"top_SoC cpu stage_EXE io_Stall", false,-1);
        vcdp->declBus(c+4089,"top_SoC cpu stage_EXE io_inst_in", false,-1, 31,0);
        vcdp->declBus(c+3593,"top_SoC cpu stage_EXE io_pc_in", false,-1, 31,0);
        vcdp->declBus(c+377,"top_SoC cpu stage_EXE io_rs1_rdata_in", false,-1, 31,0);
        vcdp->declBus(c+385,"top_SoC cpu stage_EXE io_rs2_rdata_in", false,-1, 31,0);
        vcdp->declBus(c+393,"top_SoC cpu stage_EXE io_imm_in", false,-1, 31,0);
        vcdp->declBus(c+4097,"top_SoC cpu stage_EXE io_inst", false,-1, 31,0);
        vcdp->declBus(c+3601,"top_SoC cpu stage_EXE io_pc", false,-1, 31,0);
        vcdp->declBus(c+3625,"top_SoC cpu stage_EXE io_rs1_rdata", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu stage_EXE io_rs2_rdata", false,-1, 31,0);
        vcdp->declBus(c+4105,"top_SoC cpu stage_EXE io_imm", false,-1, 31,0);
        vcdp->declBus(c+3601,"top_SoC cpu stage_EXE pcReg", false,-1, 31,0);
        vcdp->declBus(c+4097,"top_SoC cpu stage_EXE InstReg", false,-1, 31,0);
        vcdp->declBus(c+4105,"top_SoC cpu stage_EXE immReg", false,-1, 31,0);
        vcdp->declBus(c+3625,"top_SoC cpu stage_EXE rs1Reg", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu stage_EXE rs2Reg", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC cpu stage_MEM clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu stage_MEM reset", false,-1);
        vcdp->declBit(c+369,"top_SoC cpu stage_MEM io_Stall", false,-1);
        vcdp->declBus(c+3601,"top_SoC cpu stage_MEM io_pc_in", false,-1, 31,0);
        vcdp->declBus(c+4097,"top_SoC cpu stage_MEM io_inst_in", false,-1, 31,0);
        vcdp->declBus(c+201,"top_SoC cpu stage_MEM io_alu_out_in", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu stage_MEM io_DM_wdata_in", false,-1, 31,0);
        vcdp->declBus(c+3609,"top_SoC cpu stage_MEM io_pc", false,-1, 31,0);
        vcdp->declBus(c+4113,"top_SoC cpu stage_MEM io_inst", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu stage_MEM io_alu_out", false,-1, 31,0);
        vcdp->declBus(c+3273,"top_SoC cpu stage_MEM io_DM_wdata", false,-1, 31,0);
        vcdp->declBus(c+4113,"top_SoC cpu stage_MEM InstReg", false,-1, 31,0);
        vcdp->declBus(c+3609,"top_SoC cpu stage_MEM pcReg", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu stage_MEM aluReg", false,-1, 31,0);
        vcdp->declBus(c+3273,"top_SoC cpu stage_MEM wdataReg", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC cpu stage_WB clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu stage_WB reset", false,-1);
        vcdp->declBit(c+369,"top_SoC cpu stage_WB io_Stall", false,-1);
        vcdp->declBus(c+4121,"top_SoC cpu stage_WB io_pc_plus4_in", false,-1, 31,0);
        vcdp->declBus(c+4113,"top_SoC cpu stage_WB io_inst_in", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu stage_WB io_alu_out_in", false,-1, 31,0);
        vcdp->declBus(c+401,"top_SoC cpu stage_WB io_ld_data_in", false,-1, 31,0);
        vcdp->declBus(c+4129,"top_SoC cpu stage_WB io_pc_plus4", false,-1, 31,0);
        vcdp->declBus(c+4137,"top_SoC cpu stage_WB io_inst", false,-1, 31,0);
        vcdp->declBus(c+4145,"top_SoC cpu stage_WB io_alu_out", false,-1, 31,0);
        vcdp->declBus(c+4153,"top_SoC cpu stage_WB io_ld_data", false,-1, 31,0);
        vcdp->declBus(c+4129,"top_SoC cpu stage_WB pc_plus4_Reg", false,-1, 31,0);
        vcdp->declBus(c+4137,"top_SoC cpu stage_WB InstReg", false,-1, 31,0);
        vcdp->declBus(c+4145,"top_SoC cpu stage_WB alu_out_Reg", false,-1, 31,0);
        vcdp->declBus(c+4153,"top_SoC cpu stage_WB ld_data_Reg", false,-1, 31,0);
        vcdp->declBus(c+409,"top_SoC cpu datapath_IF io_PCSel", false,-1, 1,0);
        vcdp->declBus(c+3585,"top_SoC cpu datapath_IF io_IF_pc_in", false,-1, 31,0);
        vcdp->declBus(c+3601,"top_SoC cpu datapath_IF io_EXE_pc_in", false,-1, 31,0);
        vcdp->declBus(c+201,"top_SoC cpu datapath_IF io_EXE_target_pc_in", false,-1, 31,0);
        vcdp->declBus(c+81,"top_SoC cpu datapath_IF io_Mem_data", false,-1, 31,0);
        vcdp->declBus(c+345,"top_SoC cpu datapath_IF io_next_pc", false,-1, 31,0);
        vcdp->declBus(c+3585,"top_SoC cpu datapath_IF io_Mem_Addr", false,-1, 31,0);
        vcdp->declBus(c+81,"top_SoC cpu datapath_IF io_inst", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC cpu datapath_ID clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu datapath_ID reset", false,-1);
        vcdp->declBus(c+4089,"top_SoC cpu datapath_ID io_ID_inst_in", false,-1, 31,0);
        vcdp->declBus(c+3641,"top_SoC cpu datapath_ID io_WB_index", false,-1, 4,0);
        vcdp->declBus(c+209,"top_SoC cpu datapath_ID io_WB_wdata", false,-1, 31,0);
        vcdp->declBit(c+417,"top_SoC cpu datapath_ID io_WB_RegWEn", false,-1);
        vcdp->declBus(c+425,"top_SoC cpu datapath_ID io_ImmSel", false,-1, 2,0);
        vcdp->declBus(c+377,"top_SoC cpu datapath_ID io_ID_rs1_rdata", false,-1, 31,0);
        vcdp->declBus(c+385,"top_SoC cpu datapath_ID io_ID_rs2_rdata", false,-1, 31,0);
        vcdp->declBus(c+393,"top_SoC cpu datapath_ID io_imm", false,-1, 31,0);
        vcdp->declBus(c+3337,"top_SoC cpu datapath_ID io_regs_1", false,-1, 31,0);
        vcdp->declBus(c+3345,"top_SoC cpu datapath_ID io_regs_2", false,-1, 31,0);
        vcdp->declBus(c+3353,"top_SoC cpu datapath_ID io_regs_3", false,-1, 31,0);
        vcdp->declBus(c+3361,"top_SoC cpu datapath_ID io_regs_4", false,-1, 31,0);
        vcdp->declBus(c+3369,"top_SoC cpu datapath_ID io_regs_5", false,-1, 31,0);
        vcdp->declBus(c+3377,"top_SoC cpu datapath_ID io_regs_6", false,-1, 31,0);
        vcdp->declBus(c+3385,"top_SoC cpu datapath_ID io_regs_7", false,-1, 31,0);
        vcdp->declBus(c+3393,"top_SoC cpu datapath_ID io_regs_8", false,-1, 31,0);
        vcdp->declBus(c+3401,"top_SoC cpu datapath_ID io_regs_9", false,-1, 31,0);
        vcdp->declBus(c+3409,"top_SoC cpu datapath_ID io_regs_10", false,-1, 31,0);
        vcdp->declBus(c+3417,"top_SoC cpu datapath_ID io_regs_11", false,-1, 31,0);
        vcdp->declBus(c+3425,"top_SoC cpu datapath_ID io_regs_12", false,-1, 31,0);
        vcdp->declBus(c+3433,"top_SoC cpu datapath_ID io_regs_13", false,-1, 31,0);
        vcdp->declBus(c+3441,"top_SoC cpu datapath_ID io_regs_14", false,-1, 31,0);
        vcdp->declBus(c+3449,"top_SoC cpu datapath_ID io_regs_15", false,-1, 31,0);
        vcdp->declBus(c+3457,"top_SoC cpu datapath_ID io_regs_16", false,-1, 31,0);
        vcdp->declBus(c+3465,"top_SoC cpu datapath_ID io_regs_17", false,-1, 31,0);
        vcdp->declBus(c+3473,"top_SoC cpu datapath_ID io_regs_18", false,-1, 31,0);
        vcdp->declBus(c+3481,"top_SoC cpu datapath_ID io_regs_19", false,-1, 31,0);
        vcdp->declBus(c+3489,"top_SoC cpu datapath_ID io_regs_20", false,-1, 31,0);
        vcdp->declBus(c+3497,"top_SoC cpu datapath_ID io_regs_21", false,-1, 31,0);
        vcdp->declBus(c+3505,"top_SoC cpu datapath_ID io_regs_22", false,-1, 31,0);
        vcdp->declBus(c+3513,"top_SoC cpu datapath_ID io_regs_23", false,-1, 31,0);
        vcdp->declBus(c+3521,"top_SoC cpu datapath_ID io_regs_24", false,-1, 31,0);
        vcdp->declBus(c+3529,"top_SoC cpu datapath_ID io_regs_25", false,-1, 31,0);
        vcdp->declBus(c+3537,"top_SoC cpu datapath_ID io_regs_26", false,-1, 31,0);
        vcdp->declBus(c+3545,"top_SoC cpu datapath_ID io_regs_27", false,-1, 31,0);
        vcdp->declBus(c+3553,"top_SoC cpu datapath_ID io_regs_28", false,-1, 31,0);
        vcdp->declBus(c+3561,"top_SoC cpu datapath_ID io_regs_29", false,-1, 31,0);
        vcdp->declBus(c+3569,"top_SoC cpu datapath_ID io_regs_30", false,-1, 31,0);
        vcdp->declBus(c+3577,"top_SoC cpu datapath_ID io_regs_31", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC cpu datapath_ID rf_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu datapath_ID rf_reset", false,-1);
        vcdp->declBit(c+417,"top_SoC cpu datapath_ID rf_io_wen", false,-1);
        vcdp->declBus(c+3641,"top_SoC cpu datapath_ID rf_io_waddr", false,-1, 4,0);
        vcdp->declBus(c+209,"top_SoC cpu datapath_ID rf_io_wdata", false,-1, 31,0);
        vcdp->declBus(c+4233,"top_SoC cpu datapath_ID rf_io_raddr_0", false,-1, 4,0);
        vcdp->declBus(c+4241,"top_SoC cpu datapath_ID rf_io_raddr_1", false,-1, 4,0);
        vcdp->declBus(c+377,"top_SoC cpu datapath_ID rf_io_rdata_0", false,-1, 31,0);
        vcdp->declBus(c+385,"top_SoC cpu datapath_ID rf_io_rdata_1", false,-1, 31,0);
        vcdp->declBus(c+3337,"top_SoC cpu datapath_ID rf_io_regs_1", false,-1, 31,0);
        vcdp->declBus(c+3345,"top_SoC cpu datapath_ID rf_io_regs_2", false,-1, 31,0);
        vcdp->declBus(c+3353,"top_SoC cpu datapath_ID rf_io_regs_3", false,-1, 31,0);
        vcdp->declBus(c+3361,"top_SoC cpu datapath_ID rf_io_regs_4", false,-1, 31,0);
        vcdp->declBus(c+3369,"top_SoC cpu datapath_ID rf_io_regs_5", false,-1, 31,0);
        vcdp->declBus(c+3377,"top_SoC cpu datapath_ID rf_io_regs_6", false,-1, 31,0);
        vcdp->declBus(c+3385,"top_SoC cpu datapath_ID rf_io_regs_7", false,-1, 31,0);
        vcdp->declBus(c+3393,"top_SoC cpu datapath_ID rf_io_regs_8", false,-1, 31,0);
        vcdp->declBus(c+3401,"top_SoC cpu datapath_ID rf_io_regs_9", false,-1, 31,0);
        vcdp->declBus(c+3409,"top_SoC cpu datapath_ID rf_io_regs_10", false,-1, 31,0);
        vcdp->declBus(c+3417,"top_SoC cpu datapath_ID rf_io_regs_11", false,-1, 31,0);
        vcdp->declBus(c+3425,"top_SoC cpu datapath_ID rf_io_regs_12", false,-1, 31,0);
        vcdp->declBus(c+3433,"top_SoC cpu datapath_ID rf_io_regs_13", false,-1, 31,0);
        vcdp->declBus(c+3441,"top_SoC cpu datapath_ID rf_io_regs_14", false,-1, 31,0);
        vcdp->declBus(c+3449,"top_SoC cpu datapath_ID rf_io_regs_15", false,-1, 31,0);
        vcdp->declBus(c+3457,"top_SoC cpu datapath_ID rf_io_regs_16", false,-1, 31,0);
        vcdp->declBus(c+3465,"top_SoC cpu datapath_ID rf_io_regs_17", false,-1, 31,0);
        vcdp->declBus(c+3473,"top_SoC cpu datapath_ID rf_io_regs_18", false,-1, 31,0);
        vcdp->declBus(c+3481,"top_SoC cpu datapath_ID rf_io_regs_19", false,-1, 31,0);
        vcdp->declBus(c+3489,"top_SoC cpu datapath_ID rf_io_regs_20", false,-1, 31,0);
        vcdp->declBus(c+3497,"top_SoC cpu datapath_ID rf_io_regs_21", false,-1, 31,0);
        vcdp->declBus(c+3505,"top_SoC cpu datapath_ID rf_io_regs_22", false,-1, 31,0);
        vcdp->declBus(c+3513,"top_SoC cpu datapath_ID rf_io_regs_23", false,-1, 31,0);
        vcdp->declBus(c+3521,"top_SoC cpu datapath_ID rf_io_regs_24", false,-1, 31,0);
        vcdp->declBus(c+3529,"top_SoC cpu datapath_ID rf_io_regs_25", false,-1, 31,0);
        vcdp->declBus(c+3537,"top_SoC cpu datapath_ID rf_io_regs_26", false,-1, 31,0);
        vcdp->declBus(c+3545,"top_SoC cpu datapath_ID rf_io_regs_27", false,-1, 31,0);
        vcdp->declBus(c+3553,"top_SoC cpu datapath_ID rf_io_regs_28", false,-1, 31,0);
        vcdp->declBus(c+3561,"top_SoC cpu datapath_ID rf_io_regs_29", false,-1, 31,0);
        vcdp->declBus(c+3569,"top_SoC cpu datapath_ID rf_io_regs_30", false,-1, 31,0);
        vcdp->declBus(c+3577,"top_SoC cpu datapath_ID rf_io_regs_31", false,-1, 31,0);
        vcdp->declBus(c+4249,"top_SoC cpu datapath_ID ig_io_inst_31_7", false,-1, 24,0);
        vcdp->declBus(c+425,"top_SoC cpu datapath_ID ig_io_ImmSel", false,-1, 2,0);
        vcdp->declBus(c+393,"top_SoC cpu datapath_ID ig_io_imm", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC cpu datapath_ID rf clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC cpu datapath_ID rf reset", false,-1);
        vcdp->declBit(c+417,"top_SoC cpu datapath_ID rf io_wen", false,-1);
        vcdp->declBus(c+3641,"top_SoC cpu datapath_ID rf io_waddr", false,-1, 4,0);
        vcdp->declBus(c+209,"top_SoC cpu datapath_ID rf io_wdata", false,-1, 31,0);
        vcdp->declBus(c+4233,"top_SoC cpu datapath_ID rf io_raddr_0", false,-1, 4,0);
        vcdp->declBus(c+4241,"top_SoC cpu datapath_ID rf io_raddr_1", false,-1, 4,0);
        vcdp->declBus(c+377,"top_SoC cpu datapath_ID rf io_rdata_0", false,-1, 31,0);
        vcdp->declBus(c+385,"top_SoC cpu datapath_ID rf io_rdata_1", false,-1, 31,0);
        vcdp->declBus(c+3337,"top_SoC cpu datapath_ID rf io_regs_1", false,-1, 31,0);
        vcdp->declBus(c+3345,"top_SoC cpu datapath_ID rf io_regs_2", false,-1, 31,0);
        vcdp->declBus(c+3353,"top_SoC cpu datapath_ID rf io_regs_3", false,-1, 31,0);
        vcdp->declBus(c+3361,"top_SoC cpu datapath_ID rf io_regs_4", false,-1, 31,0);
        vcdp->declBus(c+3369,"top_SoC cpu datapath_ID rf io_regs_5", false,-1, 31,0);
        vcdp->declBus(c+3377,"top_SoC cpu datapath_ID rf io_regs_6", false,-1, 31,0);
        vcdp->declBus(c+3385,"top_SoC cpu datapath_ID rf io_regs_7", false,-1, 31,0);
        vcdp->declBus(c+3393,"top_SoC cpu datapath_ID rf io_regs_8", false,-1, 31,0);
        vcdp->declBus(c+3401,"top_SoC cpu datapath_ID rf io_regs_9", false,-1, 31,0);
        vcdp->declBus(c+3409,"top_SoC cpu datapath_ID rf io_regs_10", false,-1, 31,0);
        vcdp->declBus(c+3417,"top_SoC cpu datapath_ID rf io_regs_11", false,-1, 31,0);
        vcdp->declBus(c+3425,"top_SoC cpu datapath_ID rf io_regs_12", false,-1, 31,0);
        vcdp->declBus(c+3433,"top_SoC cpu datapath_ID rf io_regs_13", false,-1, 31,0);
        vcdp->declBus(c+3441,"top_SoC cpu datapath_ID rf io_regs_14", false,-1, 31,0);
        vcdp->declBus(c+3449,"top_SoC cpu datapath_ID rf io_regs_15", false,-1, 31,0);
        vcdp->declBus(c+3457,"top_SoC cpu datapath_ID rf io_regs_16", false,-1, 31,0);
        vcdp->declBus(c+3465,"top_SoC cpu datapath_ID rf io_regs_17", false,-1, 31,0);
        vcdp->declBus(c+3473,"top_SoC cpu datapath_ID rf io_regs_18", false,-1, 31,0);
        vcdp->declBus(c+3481,"top_SoC cpu datapath_ID rf io_regs_19", false,-1, 31,0);
        vcdp->declBus(c+3489,"top_SoC cpu datapath_ID rf io_regs_20", false,-1, 31,0);
        vcdp->declBus(c+3497,"top_SoC cpu datapath_ID rf io_regs_21", false,-1, 31,0);
        vcdp->declBus(c+3505,"top_SoC cpu datapath_ID rf io_regs_22", false,-1, 31,0);
        vcdp->declBus(c+3513,"top_SoC cpu datapath_ID rf io_regs_23", false,-1, 31,0);
        vcdp->declBus(c+3521,"top_SoC cpu datapath_ID rf io_regs_24", false,-1, 31,0);
        vcdp->declBus(c+3529,"top_SoC cpu datapath_ID rf io_regs_25", false,-1, 31,0);
        vcdp->declBus(c+3537,"top_SoC cpu datapath_ID rf io_regs_26", false,-1, 31,0);
        vcdp->declBus(c+3545,"top_SoC cpu datapath_ID rf io_regs_27", false,-1, 31,0);
        vcdp->declBus(c+3553,"top_SoC cpu datapath_ID rf io_regs_28", false,-1, 31,0);
        vcdp->declBus(c+3561,"top_SoC cpu datapath_ID rf io_regs_29", false,-1, 31,0);
        vcdp->declBus(c+3569,"top_SoC cpu datapath_ID rf io_regs_30", false,-1, 31,0);
        vcdp->declBus(c+3577,"top_SoC cpu datapath_ID rf io_regs_31", false,-1, 31,0);
        vcdp->declBus(c+3337,"top_SoC cpu datapath_ID rf regs_1", false,-1, 31,0);
        vcdp->declBus(c+3345,"top_SoC cpu datapath_ID rf regs_2", false,-1, 31,0);
        vcdp->declBus(c+3353,"top_SoC cpu datapath_ID rf regs_3", false,-1, 31,0);
        vcdp->declBus(c+3361,"top_SoC cpu datapath_ID rf regs_4", false,-1, 31,0);
        vcdp->declBus(c+3369,"top_SoC cpu datapath_ID rf regs_5", false,-1, 31,0);
        vcdp->declBus(c+3377,"top_SoC cpu datapath_ID rf regs_6", false,-1, 31,0);
        vcdp->declBus(c+3385,"top_SoC cpu datapath_ID rf regs_7", false,-1, 31,0);
        vcdp->declBus(c+3393,"top_SoC cpu datapath_ID rf regs_8", false,-1, 31,0);
        vcdp->declBus(c+3401,"top_SoC cpu datapath_ID rf regs_9", false,-1, 31,0);
        vcdp->declBus(c+3409,"top_SoC cpu datapath_ID rf regs_10", false,-1, 31,0);
        vcdp->declBus(c+3417,"top_SoC cpu datapath_ID rf regs_11", false,-1, 31,0);
        vcdp->declBus(c+3425,"top_SoC cpu datapath_ID rf regs_12", false,-1, 31,0);
        vcdp->declBus(c+3433,"top_SoC cpu datapath_ID rf regs_13", false,-1, 31,0);
        vcdp->declBus(c+3441,"top_SoC cpu datapath_ID rf regs_14", false,-1, 31,0);
        vcdp->declBus(c+3449,"top_SoC cpu datapath_ID rf regs_15", false,-1, 31,0);
        vcdp->declBus(c+3457,"top_SoC cpu datapath_ID rf regs_16", false,-1, 31,0);
        vcdp->declBus(c+3465,"top_SoC cpu datapath_ID rf regs_17", false,-1, 31,0);
        vcdp->declBus(c+3473,"top_SoC cpu datapath_ID rf regs_18", false,-1, 31,0);
        vcdp->declBus(c+3481,"top_SoC cpu datapath_ID rf regs_19", false,-1, 31,0);
        vcdp->declBus(c+3489,"top_SoC cpu datapath_ID rf regs_20", false,-1, 31,0);
        vcdp->declBus(c+3497,"top_SoC cpu datapath_ID rf regs_21", false,-1, 31,0);
        vcdp->declBus(c+3505,"top_SoC cpu datapath_ID rf regs_22", false,-1, 31,0);
        vcdp->declBus(c+3513,"top_SoC cpu datapath_ID rf regs_23", false,-1, 31,0);
        vcdp->declBus(c+3521,"top_SoC cpu datapath_ID rf regs_24", false,-1, 31,0);
        vcdp->declBus(c+3529,"top_SoC cpu datapath_ID rf regs_25", false,-1, 31,0);
        vcdp->declBus(c+3537,"top_SoC cpu datapath_ID rf regs_26", false,-1, 31,0);
        vcdp->declBus(c+3545,"top_SoC cpu datapath_ID rf regs_27", false,-1, 31,0);
        vcdp->declBus(c+3553,"top_SoC cpu datapath_ID rf regs_28", false,-1, 31,0);
        vcdp->declBus(c+3561,"top_SoC cpu datapath_ID rf regs_29", false,-1, 31,0);
        vcdp->declBus(c+3569,"top_SoC cpu datapath_ID rf regs_30", false,-1, 31,0);
        vcdp->declBus(c+3577,"top_SoC cpu datapath_ID rf regs_31", false,-1, 31,0);
        vcdp->declBus(c+4249,"top_SoC cpu datapath_ID ig io_inst_31_7", false,-1, 24,0);
        vcdp->declBus(c+425,"top_SoC cpu datapath_ID ig io_ImmSel", false,-1, 2,0);
        vcdp->declBus(c+393,"top_SoC cpu datapath_ID ig io_imm", false,-1, 31,0);
        vcdp->declBus(c+4257,"top_SoC cpu datapath_ID ig inst_shift", false,-1, 31,0);
        vcdp->declBus(c+3601,"top_SoC cpu datapath_EXE io_EXE_pc_in", false,-1, 31,0);
        vcdp->declBus(c+4105,"top_SoC cpu datapath_EXE io_EXE_imm_in", false,-1, 31,0);
        vcdp->declBus(c+3625,"top_SoC cpu datapath_EXE io_EXE_rs1_rdata_in", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu datapath_EXE io_EXE_rs2_rdata_in", false,-1, 31,0);
        vcdp->declBus(c+433,"top_SoC cpu datapath_EXE io_E_ASel", false,-1, 1,0);
        vcdp->declBit(c+441,"top_SoC cpu datapath_EXE io_E_BSel", false,-1);
        vcdp->declBit(c+4161,"top_SoC cpu datapath_EXE io_E_BrUn", false,-1);
        vcdp->declBus(c+449,"top_SoC cpu datapath_EXE io_E_ALUSel", false,-1, 14,0);
        vcdp->declBus(c+201,"top_SoC cpu datapath_EXE io_EXE_target_pc_out", false,-1, 31,0);
        vcdp->declBus(c+201,"top_SoC cpu datapath_EXE io_EXE_alu_out", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu datapath_EXE io_EXE_rs2_rdata_out", false,-1, 31,0);
        vcdp->declBit(c+457,"top_SoC cpu datapath_EXE io_E_BrEq", false,-1);
        vcdp->declBit(c+465,"top_SoC cpu datapath_EXE io_E_BrLT", false,-1);
        vcdp->declBus(c+185,"top_SoC cpu datapath_EXE io_alu_src1", false,-1, 31,0);
        vcdp->declBus(c+193,"top_SoC cpu datapath_EXE io_alu_src2", false,-1, 31,0);
        vcdp->declBus(c+3625,"top_SoC cpu datapath_EXE io_EXE_src1", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu datapath_EXE io_EXE_src2", false,-1, 31,0);
        vcdp->declBit(c+4161,"top_SoC cpu datapath_EXE bc_io_BrUn", false,-1);
        vcdp->declBus(c+3625,"top_SoC cpu datapath_EXE bc_io_src1", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu datapath_EXE bc_io_src2", false,-1, 31,0);
        vcdp->declBit(c+457,"top_SoC cpu datapath_EXE bc_io_BrEq", false,-1);
        vcdp->declBit(c+465,"top_SoC cpu datapath_EXE bc_io_BrLT", false,-1);
        vcdp->declBus(c+489,"top_SoC cpu datapath_EXE alu_io_src1", false,-1, 31,0);
        vcdp->declBus(c+497,"top_SoC cpu datapath_EXE alu_io_src2", false,-1, 31,0);
        vcdp->declBus(c+449,"top_SoC cpu datapath_EXE alu_io_ALUSel", false,-1, 14,0);
        vcdp->declBus(c+201,"top_SoC cpu datapath_EXE alu_io_out", false,-1, 31,0);
        vcdp->declBit(c+4161,"top_SoC cpu datapath_EXE bc io_BrUn", false,-1);
        vcdp->declBus(c+3625,"top_SoC cpu datapath_EXE bc io_src1", false,-1, 31,0);
        vcdp->declBus(c+3633,"top_SoC cpu datapath_EXE bc io_src2", false,-1, 31,0);
        vcdp->declBit(c+457,"top_SoC cpu datapath_EXE bc io_BrEq", false,-1);
        vcdp->declBit(c+465,"top_SoC cpu datapath_EXE bc io_BrLT", false,-1);
        vcdp->declBus(c+489,"top_SoC cpu datapath_EXE alu io_src1", false,-1, 31,0);
        vcdp->declBus(c+497,"top_SoC cpu datapath_EXE alu io_src2", false,-1, 31,0);
        vcdp->declBus(c+449,"top_SoC cpu datapath_EXE alu io_ALUSel", false,-1, 14,0);
        vcdp->declBus(c+201,"top_SoC cpu datapath_EXE alu io_out", false,-1, 31,0);
        vcdp->declBus(c+3609,"top_SoC cpu datapath_MEM io_MEM_pc_in", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu datapath_MEM io_MEM_alu_out_in", false,-1, 31,0);
        vcdp->declBus(c+3273,"top_SoC cpu datapath_MEM io_MEM_DM_wdata_in", false,-1, 31,0);
        vcdp->declBus(c+4121,"top_SoC cpu datapath_MEM io_MEM_pc_plus_4", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu datapath_MEM io_MEM_alu_out", false,-1, 31,0);
        vcdp->declBus(c+401,"top_SoC cpu datapath_MEM io_MEM_ld_data", false,-1, 31,0);
        vcdp->declBus(c+3265,"top_SoC cpu datapath_MEM io_Mem_Addr", false,-1, 31,0);
        vcdp->declBus(c+3273,"top_SoC cpu datapath_MEM io_Mem_Write_Data", false,-1, 31,0);
        vcdp->declBus(c+401,"top_SoC cpu datapath_MEM io_Mem_Data", false,-1, 31,0);
        vcdp->declBus(c+4129,"top_SoC cpu datapath_WB io_WB_pc_plus4_in", false,-1, 31,0);
        vcdp->declBus(c+4145,"top_SoC cpu datapath_WB io_WB_alu_out_in", false,-1, 31,0);
        vcdp->declBus(c+4153,"top_SoC cpu datapath_WB io_WB_ld_data_in", false,-1, 31,0);
        vcdp->declBus(c+473,"top_SoC cpu datapath_WB io_W_WBSel", false,-1, 1,0);
        vcdp->declBus(c+209,"top_SoC cpu datapath_WB io_WB_wdata", false,-1, 31,0);
        vcdp->declBit(c+3241,"top_SoC cpu contorller io_DM_Mem_R", false,-1);
        vcdp->declBit(c+3249,"top_SoC cpu contorller io_DM_Mem_W", false,-1);
        vcdp->declBus(c+3257,"top_SoC cpu contorller io_DM_Length", false,-1, 3,0);
        vcdp->declBit(c+457,"top_SoC cpu contorller io_E_BrEq", false,-1);
        vcdp->declBit(c+465,"top_SoC cpu contorller io_E_BrLT", false,-1);
        vcdp->declBit(c+153,"top_SoC cpu contorller io_E_Branch_taken", false,-1);
        vcdp->declBus(c+3593,"top_SoC cpu contorller io_ID_pc", false,-1, 31,0);
        vcdp->declBus(c+201,"top_SoC cpu contorller io_EXE_target_pc", false,-1, 31,0);
        vcdp->declBit(c+177,"top_SoC cpu contorller io_Flush_WB_ID_DH", false,-1);
        vcdp->declBit(c+161,"top_SoC cpu contorller io_Flush_BH", false,-1);
        vcdp->declBit(c+177,"top_SoC cpu contorller io_Stall_WB_ID_DH", false,-1);
        vcdp->declBus(c+81,"top_SoC cpu contorller io_IF_Inst", false,-1, 31,0);
        vcdp->declBus(c+4089,"top_SoC cpu contorller io_ID_Inst", false,-1, 31,0);
        vcdp->declBus(c+4097,"top_SoC cpu contorller io_EXE_Inst", false,-1, 31,0);
        vcdp->declBus(c+4113,"top_SoC cpu contorller io_MEM_Inst", false,-1, 31,0);
        vcdp->declBus(c+4137,"top_SoC cpu contorller io_WB_Inst", false,-1, 31,0);
        vcdp->declBus(c+409,"top_SoC cpu contorller io_PCSel", false,-1, 1,0);
        vcdp->declBus(c+425,"top_SoC cpu contorller io_D_ImmSel", false,-1, 2,0);
        vcdp->declBit(c+417,"top_SoC cpu contorller io_W_RegWEn", false,-1);
        vcdp->declBit(c+4161,"top_SoC cpu contorller io_E_BrUn", false,-1);
        vcdp->declBus(c+433,"top_SoC cpu contorller io_E_ASel", false,-1, 1,0);
        vcdp->declBit(c+441,"top_SoC cpu contorller io_E_BSel", false,-1);
        vcdp->declBus(c+449,"top_SoC cpu contorller io_E_ALUSel", false,-1, 14,0);
        vcdp->declBus(c+473,"top_SoC cpu contorller io_W_WBSel", false,-1, 1,0);
        vcdp->declBit(c+145,"top_SoC cpu contorller io_Hcf", false,-1);
        vcdp->declBus(c+505,"top_SoC cpu contorller IF_opcode", false,-1, 6,0);
        vcdp->declBus(c+4265,"top_SoC cpu contorller ID_opcode", false,-1, 6,0);
        vcdp->declBus(c+4273,"top_SoC cpu contorller EXE_opcode", false,-1, 6,0);
        vcdp->declBus(c+4281,"top_SoC cpu contorller EXE_funct3", false,-1, 2,0);
        vcdp->declBus(c+4289,"top_SoC cpu contorller EXE_funct7", false,-1, 6,0);
        vcdp->declBus(c+4297,"top_SoC cpu contorller MEM_opcode", false,-1, 6,0);
        vcdp->declBus(c+4305,"top_SoC cpu contorller MEM_funct3", false,-1, 2,0);
        vcdp->declBus(c+4313,"top_SoC cpu contorller WB_opcode", false,-1, 6,0);
        vcdp->declBit(c+513,"top_SoC cpu contorller E_Branch_taken", false,-1);
        vcdp->declBit(c+161,"top_SoC cpu contorller Predict_Miss", false,-1);
        vcdp->declBit(c+521,"top_SoC cpu contorller is_D_use_rs1", false,-1);
        vcdp->declBit(c+529,"top_SoC cpu contorller is_D_use_rs2", false,-1);
        vcdp->declBit(c+537,"top_SoC cpu contorller is_E_use_rd", false,-1);
        vcdp->declBit(c+545,"top_SoC cpu contorller is_M_use_rd", false,-1);
        vcdp->declBit(c+553,"top_SoC cpu contorller is_W_use_rd", false,-1);
        vcdp->declBus(c+4233,"top_SoC cpu contorller ID_rs1", false,-1, 4,0);
        vcdp->declBus(c+4241,"top_SoC cpu contorller ID_rs2", false,-1, 4,0);
        vcdp->declBus(c+4321,"top_SoC cpu contorller EXE_rd", false,-1, 4,0);
        vcdp->declBus(c+4329,"top_SoC cpu contorller MEM_rd", false,-1, 4,0);
        vcdp->declBus(c+3641,"top_SoC cpu contorller WB_rd", false,-1, 4,0);
        vcdp->declBit(c+561,"top_SoC cpu contorller is_D_rs1_E_rd_overlap", false,-1);
        vcdp->declBit(c+569,"top_SoC cpu contorller is_D_rs2_E_rd_overlap", false,-1);
        vcdp->declBit(c+577,"top_SoC cpu contorller is_D_rs1_M_rd_overlap", false,-1);
        vcdp->declBit(c+585,"top_SoC cpu contorller is_D_rs2_M_rd_overlap", false,-1);
        vcdp->declBit(c+593,"top_SoC cpu contorller is_D_rs1_W_rd_overlap", false,-1);
        vcdp->declBit(c+601,"top_SoC cpu contorller is_D_rs2_W_rd_overlap", false,-1);
        vcdp->declBit(c+5993,"top_SoC im clock", false,-1);
        vcdp->declBus(c+3233,"top_SoC im io_raddr", false,-1, 14,0);
        vcdp->declBus(c+81,"top_SoC im io_inst", false,-1, 31,0);
        vcdp->declBit(c+6505,"top_SoC im memory_rdata_MPORT_en", false,-1);
        vcdp->declBus(c+4337,"top_SoC im memory_rdata_MPORT_addr", false,-1, 14,0);
        vcdp->declBus(c+609,"top_SoC im memory_rdata_MPORT_data", false,-1, 7,0);
        vcdp->declBit(c+6505,"top_SoC im memory_rdata_MPORT_1_en", false,-1);
        vcdp->declBus(c+4345,"top_SoC im memory_rdata_MPORT_1_addr", false,-1, 14,0);
        vcdp->declBus(c+617,"top_SoC im memory_rdata_MPORT_1_data", false,-1, 7,0);
        vcdp->declBit(c+6505,"top_SoC im memory_rdata_MPORT_2_en", false,-1);
        vcdp->declBus(c+4353,"top_SoC im memory_rdata_MPORT_2_addr", false,-1, 14,0);
        vcdp->declBus(c+625,"top_SoC im memory_rdata_MPORT_2_data", false,-1, 7,0);
        vcdp->declBit(c+6505,"top_SoC im memory_rdata_MPORT_3_en", false,-1);
        vcdp->declBus(c+3233,"top_SoC im memory_rdata_MPORT_3_addr", false,-1, 14,0);
        vcdp->declBus(c+633,"top_SoC im memory_rdata_MPORT_3_data", false,-1, 7,0);
        vcdp->declBus(c+641,"top_SoC im rdata_lo", false,-1, 15,0);
        vcdp->declBus(c+649,"top_SoC im rdata_hi", false,-1, 15,0);
        vcdp->declBit(c+5993,"top_SoC im BindsTo_0_InstMem_Inst clock", false,-1);
        vcdp->declBus(c+3233,"top_SoC im BindsTo_0_InstMem_Inst io_raddr", false,-1, 14,0);
        vcdp->declBus(c+81,"top_SoC im BindsTo_0_InstMem_Inst io_inst", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC bus clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus reset", false,-1);
        vcdp->declBit(c+3281,"top_SoC bus io_masters_0_aw_ready", false,-1);
        vcdp->declBit(c+3289,"top_SoC bus io_masters_0_aw_valid", false,-1);
        vcdp->declBus(c+89,"top_SoC bus io_masters_0_aw_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+3297,"top_SoC bus io_masters_0_w_ready", false,-1);
        vcdp->declBit(c+3289,"top_SoC bus io_masters_0_w_valid", false,-1);
        vcdp->declBus(c+97,"top_SoC bus io_masters_0_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3305,"top_SoC bus io_masters_0_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+105,"top_SoC bus io_masters_0_b_ready", false,-1);
        vcdp->declBit(c+3313,"top_SoC bus io_masters_0_b_valid", false,-1);
        vcdp->declBit(c+3321,"top_SoC bus io_masters_0_ar_ready", false,-1);
        vcdp->declBit(c+3329,"top_SoC bus io_masters_0_ar_valid", false,-1);
        vcdp->declBus(c+113,"top_SoC bus io_masters_0_ar_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+121,"top_SoC bus io_masters_0_r_ready", false,-1);
        vcdp->declBit(c+129,"top_SoC bus io_masters_0_r_valid", false,-1);
        vcdp->declBus(c+137,"top_SoC bus io_masters_0_r_bits_data", false,-1, 31,0);
        vcdp->declBit(c+3121,"top_SoC bus io_masters_1_aw_ready", false,-1);
        vcdp->declBit(c+25,"top_SoC bus io_masters_1_aw_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC bus io_masters_1_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+33,"top_SoC bus io_masters_1_aw_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6513,"top_SoC bus io_masters_1_aw_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3129,"top_SoC bus io_masters_1_w_ready", false,-1);
        vcdp->declBit(c+3137,"top_SoC bus io_masters_1_w_valid", false,-1);
        vcdp->declBus(c+41,"top_SoC bus io_masters_1_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+49,"top_SoC bus io_masters_1_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+6505,"top_SoC bus io_masters_1_w_bits_last", false,-1);
        vcdp->declBit(c+3145,"top_SoC bus io_masters_1_b_ready", false,-1);
        vcdp->declBit(c+3153,"top_SoC bus io_masters_1_b_valid", false,-1);
        vcdp->declBus(c+3161,"top_SoC bus io_masters_1_b_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3169,"top_SoC bus io_masters_1_b_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3177,"top_SoC bus io_masters_1_ar_ready", false,-1);
        vcdp->declBit(c+3185,"top_SoC bus io_masters_1_ar_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC bus io_masters_1_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+57,"top_SoC bus io_masters_1_ar_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6513,"top_SoC bus io_masters_1_ar_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3193,"top_SoC bus io_masters_1_r_ready", false,-1);
        vcdp->declBit(c+65,"top_SoC bus io_masters_1_r_valid", false,-1);
        vcdp->declBus(c+3201,"top_SoC bus io_masters_1_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+73,"top_SoC bus io_masters_1_r_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3209,"top_SoC bus io_masters_1_r_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3217,"top_SoC bus io_masters_1_r_bits_last", false,-1);
        vcdp->declBit(c+2969,"top_SoC bus io_slaves_0_aw_ready", false,-1);
        vcdp->declBit(c+2977,"top_SoC bus io_slaves_0_aw_valid", false,-1);
        vcdp->declBus(c+2985,"top_SoC bus io_slaves_0_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+2993,"top_SoC bus io_slaves_0_aw_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+3001,"top_SoC bus io_slaves_0_aw_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1,"top_SoC bus io_slaves_0_w_ready", false,-1);
        vcdp->declBit(c+3009,"top_SoC bus io_slaves_0_w_valid", false,-1);
        vcdp->declBus(c+3017,"top_SoC bus io_slaves_0_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3025,"top_SoC bus io_slaves_0_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3033,"top_SoC bus io_slaves_0_w_bits_last", false,-1);
        vcdp->declBit(c+9,"top_SoC bus io_slaves_0_b_ready", false,-1);
        vcdp->declBit(c+3041,"top_SoC bus io_slaves_0_b_valid", false,-1);
        vcdp->declBus(c+3049,"top_SoC bus io_slaves_0_b_bits_id", false,-1, 3,0);
        vcdp->declBus(c+6481,"top_SoC bus io_slaves_0_b_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3057,"top_SoC bus io_slaves_0_ar_ready", false,-1);
        vcdp->declBit(c+3065,"top_SoC bus io_slaves_0_ar_valid", false,-1);
        vcdp->declBus(c+3073,"top_SoC bus io_slaves_0_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3081,"top_SoC bus io_slaves_0_ar_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+3089,"top_SoC bus io_slaves_0_ar_bits_size", false,-1, 1,0);
        vcdp->declBit(c+17,"top_SoC bus io_slaves_0_r_ready", false,-1);
        vcdp->declBit(c+3097,"top_SoC bus io_slaves_0_r_valid", false,-1);
        vcdp->declBus(c+3105,"top_SoC bus io_slaves_0_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3113,"top_SoC bus io_slaves_0_r_bits_data", false,-1, 31,0);
        vcdp->declBus(c+6481,"top_SoC bus io_slaves_0_r_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+6505,"top_SoC bus io_slaves_0_r_bits_last", false,-1);
        vcdp->declBit(c+3665,"top_SoC bus io_slaves_1_aw_ready", false,-1);
        vcdp->declBit(c+3673,"top_SoC bus io_slaves_1_aw_valid", false,-1);
        vcdp->declBus(c+3681,"top_SoC bus io_slaves_1_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3689,"top_SoC bus io_slaves_1_aw_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+3697,"top_SoC bus io_slaves_1_w_ready", false,-1);
        vcdp->declBit(c+3705,"top_SoC bus io_slaves_1_w_valid", false,-1);
        vcdp->declBus(c+3713,"top_SoC bus io_slaves_1_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3721,"top_SoC bus io_slaves_1_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3729,"top_SoC bus io_slaves_1_w_bits_last", false,-1);
        vcdp->declBit(c+217,"top_SoC bus io_slaves_1_b_ready", false,-1);
        vcdp->declBit(c+3737,"top_SoC bus io_slaves_1_b_valid", false,-1);
        vcdp->declBus(c+3745,"top_SoC bus io_slaves_1_b_bits_id", false,-1, 3,0);
        vcdp->declBit(c+3753,"top_SoC bus io_slaves_1_ar_ready", false,-1);
        vcdp->declBit(c+3761,"top_SoC bus io_slaves_1_ar_valid", false,-1);
        vcdp->declBus(c+3769,"top_SoC bus io_slaves_1_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3777,"top_SoC bus io_slaves_1_ar_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+225,"top_SoC bus io_slaves_1_r_ready", false,-1);
        vcdp->declBit(c+233,"top_SoC bus io_slaves_1_r_valid", false,-1);
        vcdp->declBus(c+3785,"top_SoC bus io_slaves_1_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+241,"top_SoC bus io_slaves_1_r_bits_data", false,-1, 31,0);
        vcdp->declBit(c+3793,"top_SoC bus io_slaves_1_r_bits_last", false,-1);
        vcdp->declBit(c+3801,"top_SoC bus io_slaves_2_aw_ready", false,-1);
        vcdp->declBit(c+3809,"top_SoC bus io_slaves_2_aw_valid", false,-1);
        vcdp->declBus(c+3817,"top_SoC bus io_slaves_2_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3825,"top_SoC bus io_slaves_2_aw_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+3833,"top_SoC bus io_slaves_2_w_ready", false,-1);
        vcdp->declBit(c+3841,"top_SoC bus io_slaves_2_w_valid", false,-1);
        vcdp->declBus(c+3849,"top_SoC bus io_slaves_2_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3857,"top_SoC bus io_slaves_2_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3865,"top_SoC bus io_slaves_2_w_bits_last", false,-1);
        vcdp->declBit(c+249,"top_SoC bus io_slaves_2_b_ready", false,-1);
        vcdp->declBit(c+3873,"top_SoC bus io_slaves_2_b_valid", false,-1);
        vcdp->declBus(c+3881,"top_SoC bus io_slaves_2_b_bits_id", false,-1, 3,0);
        vcdp->declBit(c+3889,"top_SoC bus io_slaves_2_ar_ready", false,-1);
        vcdp->declBit(c+3897,"top_SoC bus io_slaves_2_ar_valid", false,-1);
        vcdp->declBus(c+3905,"top_SoC bus io_slaves_2_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3913,"top_SoC bus io_slaves_2_ar_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+257,"top_SoC bus io_slaves_2_r_ready", false,-1);
        vcdp->declBit(c+265,"top_SoC bus io_slaves_2_r_valid", false,-1);
        vcdp->declBus(c+3921,"top_SoC bus io_slaves_2_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+273,"top_SoC bus io_slaves_2_r_bits_data", false,-1, 31,0);
        vcdp->declBit(c+3929,"top_SoC bus io_slaves_2_r_bits_last", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readBuses_0_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus readBuses_0_reset", false,-1);
        vcdp->declBit(c+3321,"top_SoC bus readBuses_0_io_master_readAddr_ready", false,-1);
        vcdp->declBit(c+3329,"top_SoC bus readBuses_0_io_master_readAddr_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC bus readBuses_0_io_master_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+113,"top_SoC bus readBuses_0_io_master_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6513,"top_SoC bus readBuses_0_io_master_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+121,"top_SoC bus readBuses_0_io_master_readData_ready", false,-1);
        vcdp->declBit(c+129,"top_SoC bus readBuses_0_io_master_readData_valid", false,-1);
        vcdp->declBus(c+4361,"top_SoC bus readBuses_0_io_master_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+137,"top_SoC bus readBuses_0_io_master_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4369,"top_SoC bus readBuses_0_io_master_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4377,"top_SoC bus readBuses_0_io_master_readData_bits_last", false,-1);
        vcdp->declBit(c+657,"top_SoC bus readBuses_0_io_slave_0_readAddr_ready", false,-1);
        vcdp->declBit(c+665,"top_SoC bus readBuses_0_io_slave_0_readAddr_valid", false,-1);
        vcdp->declBus(c+4385,"top_SoC bus readBuses_0_io_slave_0_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4393,"top_SoC bus readBuses_0_io_slave_0_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4401,"top_SoC bus readBuses_0_io_slave_0_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+673,"top_SoC bus readBuses_0_io_slave_0_readData_ready", false,-1);
        vcdp->declBit(c+681,"top_SoC bus readBuses_0_io_slave_0_readData_valid", false,-1);
        vcdp->declBus(c+4409,"top_SoC bus readBuses_0_io_slave_0_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4417,"top_SoC bus readBuses_0_io_slave_0_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4425,"top_SoC bus readBuses_0_io_slave_0_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4433,"top_SoC bus readBuses_0_io_slave_0_readData_bits_last", false,-1);
        vcdp->declBit(c+689,"top_SoC bus readBuses_0_io_slave_1_readAddr_ready", false,-1);
        vcdp->declBit(c+697,"top_SoC bus readBuses_0_io_slave_1_readAddr_valid", false,-1);
        vcdp->declBus(c+4441,"top_SoC bus readBuses_0_io_slave_1_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4449,"top_SoC bus readBuses_0_io_slave_1_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4457,"top_SoC bus readBuses_0_io_slave_1_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+705,"top_SoC bus readBuses_0_io_slave_1_readData_ready", false,-1);
        vcdp->declBit(c+713,"top_SoC bus readBuses_0_io_slave_1_readData_valid", false,-1);
        vcdp->declBus(c+4465,"top_SoC bus readBuses_0_io_slave_1_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4473,"top_SoC bus readBuses_0_io_slave_1_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4481,"top_SoC bus readBuses_0_io_slave_1_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4489,"top_SoC bus readBuses_0_io_slave_1_readData_bits_last", false,-1);
        vcdp->declBit(c+721,"top_SoC bus readBuses_0_io_slave_2_readAddr_ready", false,-1);
        vcdp->declBit(c+729,"top_SoC bus readBuses_0_io_slave_2_readAddr_valid", false,-1);
        vcdp->declBus(c+4497,"top_SoC bus readBuses_0_io_slave_2_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4505,"top_SoC bus readBuses_0_io_slave_2_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4513,"top_SoC bus readBuses_0_io_slave_2_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+737,"top_SoC bus readBuses_0_io_slave_2_readData_ready", false,-1);
        vcdp->declBit(c+745,"top_SoC bus readBuses_0_io_slave_2_readData_valid", false,-1);
        vcdp->declBus(c+4521,"top_SoC bus readBuses_0_io_slave_2_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4529,"top_SoC bus readBuses_0_io_slave_2_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4537,"top_SoC bus readBuses_0_io_slave_2_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4545,"top_SoC bus readBuses_0_io_slave_2_readData_bits_last", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readBuses_1_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus readBuses_1_reset", false,-1);
        vcdp->declBit(c+3177,"top_SoC bus readBuses_1_io_master_readAddr_ready", false,-1);
        vcdp->declBit(c+3185,"top_SoC bus readBuses_1_io_master_readAddr_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC bus readBuses_1_io_master_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+57,"top_SoC bus readBuses_1_io_master_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6513,"top_SoC bus readBuses_1_io_master_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3193,"top_SoC bus readBuses_1_io_master_readData_ready", false,-1);
        vcdp->declBit(c+65,"top_SoC bus readBuses_1_io_master_readData_valid", false,-1);
        vcdp->declBus(c+3201,"top_SoC bus readBuses_1_io_master_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+73,"top_SoC bus readBuses_1_io_master_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3209,"top_SoC bus readBuses_1_io_master_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3217,"top_SoC bus readBuses_1_io_master_readData_bits_last", false,-1);
        vcdp->declBit(c+753,"top_SoC bus readBuses_1_io_slave_0_readAddr_ready", false,-1);
        vcdp->declBit(c+761,"top_SoC bus readBuses_1_io_slave_0_readAddr_valid", false,-1);
        vcdp->declBus(c+4553,"top_SoC bus readBuses_1_io_slave_0_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4561,"top_SoC bus readBuses_1_io_slave_0_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4569,"top_SoC bus readBuses_1_io_slave_0_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+4577,"top_SoC bus readBuses_1_io_slave_0_readData_ready", false,-1);
        vcdp->declBit(c+769,"top_SoC bus readBuses_1_io_slave_0_readData_valid", false,-1);
        vcdp->declBus(c+4585,"top_SoC bus readBuses_1_io_slave_0_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4593,"top_SoC bus readBuses_1_io_slave_0_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4601,"top_SoC bus readBuses_1_io_slave_0_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4609,"top_SoC bus readBuses_1_io_slave_0_readData_bits_last", false,-1);
        vcdp->declBit(c+777,"top_SoC bus readBuses_1_io_slave_1_readAddr_ready", false,-1);
        vcdp->declBit(c+785,"top_SoC bus readBuses_1_io_slave_1_readAddr_valid", false,-1);
        vcdp->declBus(c+4617,"top_SoC bus readBuses_1_io_slave_1_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4625,"top_SoC bus readBuses_1_io_slave_1_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4633,"top_SoC bus readBuses_1_io_slave_1_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+4641,"top_SoC bus readBuses_1_io_slave_1_readData_ready", false,-1);
        vcdp->declBit(c+793,"top_SoC bus readBuses_1_io_slave_1_readData_valid", false,-1);
        vcdp->declBus(c+4649,"top_SoC bus readBuses_1_io_slave_1_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4657,"top_SoC bus readBuses_1_io_slave_1_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4665,"top_SoC bus readBuses_1_io_slave_1_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4673,"top_SoC bus readBuses_1_io_slave_1_readData_bits_last", false,-1);
        vcdp->declBit(c+801,"top_SoC bus readBuses_1_io_slave_2_readAddr_ready", false,-1);
        vcdp->declBit(c+809,"top_SoC bus readBuses_1_io_slave_2_readAddr_valid", false,-1);
        vcdp->declBus(c+4681,"top_SoC bus readBuses_1_io_slave_2_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4689,"top_SoC bus readBuses_1_io_slave_2_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4697,"top_SoC bus readBuses_1_io_slave_2_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+4705,"top_SoC bus readBuses_1_io_slave_2_readData_ready", false,-1);
        vcdp->declBit(c+817,"top_SoC bus readBuses_1_io_slave_2_readData_valid", false,-1);
        vcdp->declBus(c+4713,"top_SoC bus readBuses_1_io_slave_2_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4721,"top_SoC bus readBuses_1_io_slave_2_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4729,"top_SoC bus readBuses_1_io_slave_2_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4737,"top_SoC bus readBuses_1_io_slave_2_readData_bits_last", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readMuxes_0_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus readMuxes_0_reset", false,-1);
        vcdp->declBit(c+3057,"top_SoC bus readMuxes_0_io_out_readAddr_ready", false,-1);
        vcdp->declBit(c+3065,"top_SoC bus readMuxes_0_io_out_readAddr_valid", false,-1);
        vcdp->declBus(c+3073,"top_SoC bus readMuxes_0_io_out_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3081,"top_SoC bus readMuxes_0_io_out_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+3089,"top_SoC bus readMuxes_0_io_out_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+17,"top_SoC bus readMuxes_0_io_out_readData_ready", false,-1);
        vcdp->declBit(c+3097,"top_SoC bus readMuxes_0_io_out_readData_valid", false,-1);
        vcdp->declBus(c+3105,"top_SoC bus readMuxes_0_io_out_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3113,"top_SoC bus readMuxes_0_io_out_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+6481,"top_SoC bus readMuxes_0_io_out_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+6505,"top_SoC bus readMuxes_0_io_out_readData_bits_last", false,-1);
        vcdp->declBit(c+657,"top_SoC bus readMuxes_0_io_in_0_readAddr_ready", false,-1);
        vcdp->declBit(c+665,"top_SoC bus readMuxes_0_io_in_0_readAddr_valid", false,-1);
        vcdp->declBus(c+4385,"top_SoC bus readMuxes_0_io_in_0_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4393,"top_SoC bus readMuxes_0_io_in_0_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4401,"top_SoC bus readMuxes_0_io_in_0_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+673,"top_SoC bus readMuxes_0_io_in_0_readData_ready", false,-1);
        vcdp->declBit(c+681,"top_SoC bus readMuxes_0_io_in_0_readData_valid", false,-1);
        vcdp->declBus(c+4409,"top_SoC bus readMuxes_0_io_in_0_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4417,"top_SoC bus readMuxes_0_io_in_0_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4425,"top_SoC bus readMuxes_0_io_in_0_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4433,"top_SoC bus readMuxes_0_io_in_0_readData_bits_last", false,-1);
        vcdp->declBit(c+753,"top_SoC bus readMuxes_0_io_in_1_readAddr_ready", false,-1);
        vcdp->declBit(c+761,"top_SoC bus readMuxes_0_io_in_1_readAddr_valid", false,-1);
        vcdp->declBus(c+4553,"top_SoC bus readMuxes_0_io_in_1_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4561,"top_SoC bus readMuxes_0_io_in_1_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4569,"top_SoC bus readMuxes_0_io_in_1_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+4577,"top_SoC bus readMuxes_0_io_in_1_readData_ready", false,-1);
        vcdp->declBit(c+769,"top_SoC bus readMuxes_0_io_in_1_readData_valid", false,-1);
        vcdp->declBus(c+4585,"top_SoC bus readMuxes_0_io_in_1_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4593,"top_SoC bus readMuxes_0_io_in_1_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4601,"top_SoC bus readMuxes_0_io_in_1_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4609,"top_SoC bus readMuxes_0_io_in_1_readData_bits_last", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readMuxes_1_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus readMuxes_1_reset", false,-1);
        vcdp->declBit(c+3753,"top_SoC bus readMuxes_1_io_out_readAddr_ready", false,-1);
        vcdp->declBit(c+3761,"top_SoC bus readMuxes_1_io_out_readAddr_valid", false,-1);
        vcdp->declBus(c+3769,"top_SoC bus readMuxes_1_io_out_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3777,"top_SoC bus readMuxes_1_io_out_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4745,"top_SoC bus readMuxes_1_io_out_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+225,"top_SoC bus readMuxes_1_io_out_readData_ready", false,-1);
        vcdp->declBit(c+233,"top_SoC bus readMuxes_1_io_out_readData_valid", false,-1);
        vcdp->declBus(c+3785,"top_SoC bus readMuxes_1_io_out_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+241,"top_SoC bus readMuxes_1_io_out_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+6481,"top_SoC bus readMuxes_1_io_out_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3793,"top_SoC bus readMuxes_1_io_out_readData_bits_last", false,-1);
        vcdp->declBit(c+689,"top_SoC bus readMuxes_1_io_in_0_readAddr_ready", false,-1);
        vcdp->declBit(c+697,"top_SoC bus readMuxes_1_io_in_0_readAddr_valid", false,-1);
        vcdp->declBus(c+4441,"top_SoC bus readMuxes_1_io_in_0_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4449,"top_SoC bus readMuxes_1_io_in_0_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4457,"top_SoC bus readMuxes_1_io_in_0_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+705,"top_SoC bus readMuxes_1_io_in_0_readData_ready", false,-1);
        vcdp->declBit(c+713,"top_SoC bus readMuxes_1_io_in_0_readData_valid", false,-1);
        vcdp->declBus(c+4465,"top_SoC bus readMuxes_1_io_in_0_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4473,"top_SoC bus readMuxes_1_io_in_0_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4481,"top_SoC bus readMuxes_1_io_in_0_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4489,"top_SoC bus readMuxes_1_io_in_0_readData_bits_last", false,-1);
        vcdp->declBit(c+777,"top_SoC bus readMuxes_1_io_in_1_readAddr_ready", false,-1);
        vcdp->declBit(c+785,"top_SoC bus readMuxes_1_io_in_1_readAddr_valid", false,-1);
        vcdp->declBus(c+4617,"top_SoC bus readMuxes_1_io_in_1_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4625,"top_SoC bus readMuxes_1_io_in_1_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4633,"top_SoC bus readMuxes_1_io_in_1_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+4641,"top_SoC bus readMuxes_1_io_in_1_readData_ready", false,-1);
        vcdp->declBit(c+793,"top_SoC bus readMuxes_1_io_in_1_readData_valid", false,-1);
        vcdp->declBus(c+4649,"top_SoC bus readMuxes_1_io_in_1_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4657,"top_SoC bus readMuxes_1_io_in_1_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4665,"top_SoC bus readMuxes_1_io_in_1_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4673,"top_SoC bus readMuxes_1_io_in_1_readData_bits_last", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readMuxes_2_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus readMuxes_2_reset", false,-1);
        vcdp->declBit(c+3889,"top_SoC bus readMuxes_2_io_out_readAddr_ready", false,-1);
        vcdp->declBit(c+3897,"top_SoC bus readMuxes_2_io_out_readAddr_valid", false,-1);
        vcdp->declBus(c+3905,"top_SoC bus readMuxes_2_io_out_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3913,"top_SoC bus readMuxes_2_io_out_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4753,"top_SoC bus readMuxes_2_io_out_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+257,"top_SoC bus readMuxes_2_io_out_readData_ready", false,-1);
        vcdp->declBit(c+265,"top_SoC bus readMuxes_2_io_out_readData_valid", false,-1);
        vcdp->declBus(c+3921,"top_SoC bus readMuxes_2_io_out_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+273,"top_SoC bus readMuxes_2_io_out_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+6481,"top_SoC bus readMuxes_2_io_out_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3929,"top_SoC bus readMuxes_2_io_out_readData_bits_last", false,-1);
        vcdp->declBit(c+721,"top_SoC bus readMuxes_2_io_in_0_readAddr_ready", false,-1);
        vcdp->declBit(c+729,"top_SoC bus readMuxes_2_io_in_0_readAddr_valid", false,-1);
        vcdp->declBus(c+4497,"top_SoC bus readMuxes_2_io_in_0_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4505,"top_SoC bus readMuxes_2_io_in_0_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4513,"top_SoC bus readMuxes_2_io_in_0_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+737,"top_SoC bus readMuxes_2_io_in_0_readData_ready", false,-1);
        vcdp->declBit(c+745,"top_SoC bus readMuxes_2_io_in_0_readData_valid", false,-1);
        vcdp->declBus(c+4521,"top_SoC bus readMuxes_2_io_in_0_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4529,"top_SoC bus readMuxes_2_io_in_0_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4537,"top_SoC bus readMuxes_2_io_in_0_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4545,"top_SoC bus readMuxes_2_io_in_0_readData_bits_last", false,-1);
        vcdp->declBit(c+801,"top_SoC bus readMuxes_2_io_in_1_readAddr_ready", false,-1);
        vcdp->declBit(c+809,"top_SoC bus readMuxes_2_io_in_1_readAddr_valid", false,-1);
        vcdp->declBus(c+4681,"top_SoC bus readMuxes_2_io_in_1_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4689,"top_SoC bus readMuxes_2_io_in_1_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4697,"top_SoC bus readMuxes_2_io_in_1_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+4705,"top_SoC bus readMuxes_2_io_in_1_readData_ready", false,-1);
        vcdp->declBit(c+817,"top_SoC bus readMuxes_2_io_in_1_readData_valid", false,-1);
        vcdp->declBus(c+4713,"top_SoC bus readMuxes_2_io_in_1_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4721,"top_SoC bus readMuxes_2_io_in_1_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4729,"top_SoC bus readMuxes_2_io_in_1_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4737,"top_SoC bus readMuxes_2_io_in_1_readData_bits_last", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus writeBuses_0_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus writeBuses_0_reset", false,-1);
        vcdp->declBit(c+3281,"top_SoC bus writeBuses_0_io_master_writeAddr_ready", false,-1);
        vcdp->declBit(c+3289,"top_SoC bus writeBuses_0_io_master_writeAddr_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC bus writeBuses_0_io_master_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+89,"top_SoC bus writeBuses_0_io_master_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6513,"top_SoC bus writeBuses_0_io_master_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3297,"top_SoC bus writeBuses_0_io_master_writeData_ready", false,-1);
        vcdp->declBit(c+3289,"top_SoC bus writeBuses_0_io_master_writeData_valid", false,-1);
        vcdp->declBus(c+97,"top_SoC bus writeBuses_0_io_master_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3305,"top_SoC bus writeBuses_0_io_master_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+6505,"top_SoC bus writeBuses_0_io_master_writeData_bits_last", false,-1);
        vcdp->declBit(c+105,"top_SoC bus writeBuses_0_io_master_writeResp_ready", false,-1);
        vcdp->declBit(c+3313,"top_SoC bus writeBuses_0_io_master_writeResp_valid", false,-1);
        vcdp->declBus(c+4761,"top_SoC bus writeBuses_0_io_master_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4769,"top_SoC bus writeBuses_0_io_master_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+825,"top_SoC bus writeBuses_0_io_slave_0_writeAddr_ready", false,-1);
        vcdp->declBit(c+833,"top_SoC bus writeBuses_0_io_slave_0_writeAddr_valid", false,-1);
        vcdp->declBus(c+4777,"top_SoC bus writeBuses_0_io_slave_0_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4785,"top_SoC bus writeBuses_0_io_slave_0_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4793,"top_SoC bus writeBuses_0_io_slave_0_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+841,"top_SoC bus writeBuses_0_io_slave_0_writeData_ready", false,-1);
        vcdp->declBit(c+849,"top_SoC bus writeBuses_0_io_slave_0_writeData_valid", false,-1);
        vcdp->declBus(c+857,"top_SoC bus writeBuses_0_io_slave_0_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+865,"top_SoC bus writeBuses_0_io_slave_0_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+873,"top_SoC bus writeBuses_0_io_slave_0_writeData_bits_last", false,-1);
        vcdp->declBit(c+881,"top_SoC bus writeBuses_0_io_slave_0_writeResp_ready", false,-1);
        vcdp->declBit(c+889,"top_SoC bus writeBuses_0_io_slave_0_writeResp_valid", false,-1);
        vcdp->declBus(c+4801,"top_SoC bus writeBuses_0_io_slave_0_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4809,"top_SoC bus writeBuses_0_io_slave_0_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+897,"top_SoC bus writeBuses_0_io_slave_1_writeAddr_ready", false,-1);
        vcdp->declBit(c+905,"top_SoC bus writeBuses_0_io_slave_1_writeAddr_valid", false,-1);
        vcdp->declBus(c+4817,"top_SoC bus writeBuses_0_io_slave_1_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4825,"top_SoC bus writeBuses_0_io_slave_1_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4833,"top_SoC bus writeBuses_0_io_slave_1_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+913,"top_SoC bus writeBuses_0_io_slave_1_writeData_ready", false,-1);
        vcdp->declBit(c+921,"top_SoC bus writeBuses_0_io_slave_1_writeData_valid", false,-1);
        vcdp->declBus(c+929,"top_SoC bus writeBuses_0_io_slave_1_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+937,"top_SoC bus writeBuses_0_io_slave_1_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+945,"top_SoC bus writeBuses_0_io_slave_1_writeData_bits_last", false,-1);
        vcdp->declBit(c+953,"top_SoC bus writeBuses_0_io_slave_1_writeResp_ready", false,-1);
        vcdp->declBit(c+961,"top_SoC bus writeBuses_0_io_slave_1_writeResp_valid", false,-1);
        vcdp->declBus(c+4841,"top_SoC bus writeBuses_0_io_slave_1_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4849,"top_SoC bus writeBuses_0_io_slave_1_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+969,"top_SoC bus writeBuses_0_io_slave_2_writeAddr_ready", false,-1);
        vcdp->declBit(c+977,"top_SoC bus writeBuses_0_io_slave_2_writeAddr_valid", false,-1);
        vcdp->declBus(c+4857,"top_SoC bus writeBuses_0_io_slave_2_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4865,"top_SoC bus writeBuses_0_io_slave_2_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4873,"top_SoC bus writeBuses_0_io_slave_2_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+985,"top_SoC bus writeBuses_0_io_slave_2_writeData_ready", false,-1);
        vcdp->declBit(c+993,"top_SoC bus writeBuses_0_io_slave_2_writeData_valid", false,-1);
        vcdp->declBus(c+1001,"top_SoC bus writeBuses_0_io_slave_2_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1009,"top_SoC bus writeBuses_0_io_slave_2_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1017,"top_SoC bus writeBuses_0_io_slave_2_writeData_bits_last", false,-1);
        vcdp->declBit(c+1025,"top_SoC bus writeBuses_0_io_slave_2_writeResp_ready", false,-1);
        vcdp->declBit(c+1033,"top_SoC bus writeBuses_0_io_slave_2_writeResp_valid", false,-1);
        vcdp->declBus(c+4881,"top_SoC bus writeBuses_0_io_slave_2_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4889,"top_SoC bus writeBuses_0_io_slave_2_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+5993,"top_SoC bus writeBuses_1_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus writeBuses_1_reset", false,-1);
        vcdp->declBit(c+3121,"top_SoC bus writeBuses_1_io_master_writeAddr_ready", false,-1);
        vcdp->declBit(c+25,"top_SoC bus writeBuses_1_io_master_writeAddr_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC bus writeBuses_1_io_master_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+33,"top_SoC bus writeBuses_1_io_master_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6513,"top_SoC bus writeBuses_1_io_master_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3129,"top_SoC bus writeBuses_1_io_master_writeData_ready", false,-1);
        vcdp->declBit(c+3137,"top_SoC bus writeBuses_1_io_master_writeData_valid", false,-1);
        vcdp->declBus(c+41,"top_SoC bus writeBuses_1_io_master_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+49,"top_SoC bus writeBuses_1_io_master_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+6505,"top_SoC bus writeBuses_1_io_master_writeData_bits_last", false,-1);
        vcdp->declBit(c+3145,"top_SoC bus writeBuses_1_io_master_writeResp_ready", false,-1);
        vcdp->declBit(c+3153,"top_SoC bus writeBuses_1_io_master_writeResp_valid", false,-1);
        vcdp->declBus(c+3161,"top_SoC bus writeBuses_1_io_master_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3169,"top_SoC bus writeBuses_1_io_master_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+1041,"top_SoC bus writeBuses_1_io_slave_0_writeAddr_ready", false,-1);
        vcdp->declBit(c+1049,"top_SoC bus writeBuses_1_io_slave_0_writeAddr_valid", false,-1);
        vcdp->declBus(c+4897,"top_SoC bus writeBuses_1_io_slave_0_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4905,"top_SoC bus writeBuses_1_io_slave_0_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4913,"top_SoC bus writeBuses_1_io_slave_0_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1057,"top_SoC bus writeBuses_1_io_slave_0_writeData_ready", false,-1);
        vcdp->declBit(c+1065,"top_SoC bus writeBuses_1_io_slave_0_writeData_valid", false,-1);
        vcdp->declBus(c+1073,"top_SoC bus writeBuses_1_io_slave_0_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1081,"top_SoC bus writeBuses_1_io_slave_0_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1089,"top_SoC bus writeBuses_1_io_slave_0_writeData_bits_last", false,-1);
        vcdp->declBit(c+1097,"top_SoC bus writeBuses_1_io_slave_0_writeResp_ready", false,-1);
        vcdp->declBit(c+1105,"top_SoC bus writeBuses_1_io_slave_0_writeResp_valid", false,-1);
        vcdp->declBus(c+4921,"top_SoC bus writeBuses_1_io_slave_0_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4929,"top_SoC bus writeBuses_1_io_slave_0_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+1113,"top_SoC bus writeBuses_1_io_slave_1_writeAddr_ready", false,-1);
        vcdp->declBit(c+1121,"top_SoC bus writeBuses_1_io_slave_1_writeAddr_valid", false,-1);
        vcdp->declBus(c+4937,"top_SoC bus writeBuses_1_io_slave_1_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4945,"top_SoC bus writeBuses_1_io_slave_1_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4953,"top_SoC bus writeBuses_1_io_slave_1_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1129,"top_SoC bus writeBuses_1_io_slave_1_writeData_ready", false,-1);
        vcdp->declBit(c+1137,"top_SoC bus writeBuses_1_io_slave_1_writeData_valid", false,-1);
        vcdp->declBus(c+1145,"top_SoC bus writeBuses_1_io_slave_1_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1153,"top_SoC bus writeBuses_1_io_slave_1_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1161,"top_SoC bus writeBuses_1_io_slave_1_writeData_bits_last", false,-1);
        vcdp->declBit(c+1169,"top_SoC bus writeBuses_1_io_slave_1_writeResp_ready", false,-1);
        vcdp->declBit(c+1177,"top_SoC bus writeBuses_1_io_slave_1_writeResp_valid", false,-1);
        vcdp->declBus(c+4961,"top_SoC bus writeBuses_1_io_slave_1_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4969,"top_SoC bus writeBuses_1_io_slave_1_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+1185,"top_SoC bus writeBuses_1_io_slave_2_writeAddr_ready", false,-1);
        vcdp->declBit(c+1193,"top_SoC bus writeBuses_1_io_slave_2_writeAddr_valid", false,-1);
        vcdp->declBus(c+4977,"top_SoC bus writeBuses_1_io_slave_2_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4985,"top_SoC bus writeBuses_1_io_slave_2_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4993,"top_SoC bus writeBuses_1_io_slave_2_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1201,"top_SoC bus writeBuses_1_io_slave_2_writeData_ready", false,-1);
        vcdp->declBit(c+1209,"top_SoC bus writeBuses_1_io_slave_2_writeData_valid", false,-1);
        vcdp->declBus(c+1217,"top_SoC bus writeBuses_1_io_slave_2_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1225,"top_SoC bus writeBuses_1_io_slave_2_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1233,"top_SoC bus writeBuses_1_io_slave_2_writeData_bits_last", false,-1);
        vcdp->declBit(c+1241,"top_SoC bus writeBuses_1_io_slave_2_writeResp_ready", false,-1);
        vcdp->declBit(c+1249,"top_SoC bus writeBuses_1_io_slave_2_writeResp_valid", false,-1);
        vcdp->declBus(c+5001,"top_SoC bus writeBuses_1_io_slave_2_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+5009,"top_SoC bus writeBuses_1_io_slave_2_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+5993,"top_SoC bus writeMuxes_0_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus writeMuxes_0_reset", false,-1);
        vcdp->declBit(c+2969,"top_SoC bus writeMuxes_0_io_out_writeAddr_ready", false,-1);
        vcdp->declBit(c+2977,"top_SoC bus writeMuxes_0_io_out_writeAddr_valid", false,-1);
        vcdp->declBus(c+2985,"top_SoC bus writeMuxes_0_io_out_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+2993,"top_SoC bus writeMuxes_0_io_out_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+3001,"top_SoC bus writeMuxes_0_io_out_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1,"top_SoC bus writeMuxes_0_io_out_writeData_ready", false,-1);
        vcdp->declBit(c+3009,"top_SoC bus writeMuxes_0_io_out_writeData_valid", false,-1);
        vcdp->declBus(c+3017,"top_SoC bus writeMuxes_0_io_out_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3025,"top_SoC bus writeMuxes_0_io_out_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3033,"top_SoC bus writeMuxes_0_io_out_writeData_bits_last", false,-1);
        vcdp->declBit(c+9,"top_SoC bus writeMuxes_0_io_out_writeResp_ready", false,-1);
        vcdp->declBit(c+3041,"top_SoC bus writeMuxes_0_io_out_writeResp_valid", false,-1);
        vcdp->declBus(c+3049,"top_SoC bus writeMuxes_0_io_out_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+6481,"top_SoC bus writeMuxes_0_io_out_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+825,"top_SoC bus writeMuxes_0_io_in_0_writeAddr_ready", false,-1);
        vcdp->declBit(c+833,"top_SoC bus writeMuxes_0_io_in_0_writeAddr_valid", false,-1);
        vcdp->declBus(c+4777,"top_SoC bus writeMuxes_0_io_in_0_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4785,"top_SoC bus writeMuxes_0_io_in_0_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4793,"top_SoC bus writeMuxes_0_io_in_0_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+841,"top_SoC bus writeMuxes_0_io_in_0_writeData_ready", false,-1);
        vcdp->declBit(c+849,"top_SoC bus writeMuxes_0_io_in_0_writeData_valid", false,-1);
        vcdp->declBus(c+857,"top_SoC bus writeMuxes_0_io_in_0_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+865,"top_SoC bus writeMuxes_0_io_in_0_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+873,"top_SoC bus writeMuxes_0_io_in_0_writeData_bits_last", false,-1);
        vcdp->declBit(c+881,"top_SoC bus writeMuxes_0_io_in_0_writeResp_ready", false,-1);
        vcdp->declBit(c+889,"top_SoC bus writeMuxes_0_io_in_0_writeResp_valid", false,-1);
        vcdp->declBus(c+4801,"top_SoC bus writeMuxes_0_io_in_0_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4809,"top_SoC bus writeMuxes_0_io_in_0_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+1041,"top_SoC bus writeMuxes_0_io_in_1_writeAddr_ready", false,-1);
        vcdp->declBit(c+1049,"top_SoC bus writeMuxes_0_io_in_1_writeAddr_valid", false,-1);
        vcdp->declBus(c+4897,"top_SoC bus writeMuxes_0_io_in_1_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4905,"top_SoC bus writeMuxes_0_io_in_1_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4913,"top_SoC bus writeMuxes_0_io_in_1_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1057,"top_SoC bus writeMuxes_0_io_in_1_writeData_ready", false,-1);
        vcdp->declBit(c+1065,"top_SoC bus writeMuxes_0_io_in_1_writeData_valid", false,-1);
        vcdp->declBus(c+1073,"top_SoC bus writeMuxes_0_io_in_1_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1081,"top_SoC bus writeMuxes_0_io_in_1_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1089,"top_SoC bus writeMuxes_0_io_in_1_writeData_bits_last", false,-1);
        vcdp->declBit(c+1097,"top_SoC bus writeMuxes_0_io_in_1_writeResp_ready", false,-1);
        vcdp->declBit(c+1105,"top_SoC bus writeMuxes_0_io_in_1_writeResp_valid", false,-1);
        vcdp->declBus(c+4921,"top_SoC bus writeMuxes_0_io_in_1_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4929,"top_SoC bus writeMuxes_0_io_in_1_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+5993,"top_SoC bus writeMuxes_1_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus writeMuxes_1_reset", false,-1);
        vcdp->declBit(c+3665,"top_SoC bus writeMuxes_1_io_out_writeAddr_ready", false,-1);
        vcdp->declBit(c+3673,"top_SoC bus writeMuxes_1_io_out_writeAddr_valid", false,-1);
        vcdp->declBus(c+3681,"top_SoC bus writeMuxes_1_io_out_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3689,"top_SoC bus writeMuxes_1_io_out_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+5017,"top_SoC bus writeMuxes_1_io_out_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3697,"top_SoC bus writeMuxes_1_io_out_writeData_ready", false,-1);
        vcdp->declBit(c+3705,"top_SoC bus writeMuxes_1_io_out_writeData_valid", false,-1);
        vcdp->declBus(c+3713,"top_SoC bus writeMuxes_1_io_out_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3721,"top_SoC bus writeMuxes_1_io_out_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3729,"top_SoC bus writeMuxes_1_io_out_writeData_bits_last", false,-1);
        vcdp->declBit(c+217,"top_SoC bus writeMuxes_1_io_out_writeResp_ready", false,-1);
        vcdp->declBit(c+3737,"top_SoC bus writeMuxes_1_io_out_writeResp_valid", false,-1);
        vcdp->declBus(c+3745,"top_SoC bus writeMuxes_1_io_out_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+6481,"top_SoC bus writeMuxes_1_io_out_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+897,"top_SoC bus writeMuxes_1_io_in_0_writeAddr_ready", false,-1);
        vcdp->declBit(c+905,"top_SoC bus writeMuxes_1_io_in_0_writeAddr_valid", false,-1);
        vcdp->declBus(c+4817,"top_SoC bus writeMuxes_1_io_in_0_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4825,"top_SoC bus writeMuxes_1_io_in_0_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4833,"top_SoC bus writeMuxes_1_io_in_0_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+913,"top_SoC bus writeMuxes_1_io_in_0_writeData_ready", false,-1);
        vcdp->declBit(c+921,"top_SoC bus writeMuxes_1_io_in_0_writeData_valid", false,-1);
        vcdp->declBus(c+929,"top_SoC bus writeMuxes_1_io_in_0_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+937,"top_SoC bus writeMuxes_1_io_in_0_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+945,"top_SoC bus writeMuxes_1_io_in_0_writeData_bits_last", false,-1);
        vcdp->declBit(c+953,"top_SoC bus writeMuxes_1_io_in_0_writeResp_ready", false,-1);
        vcdp->declBit(c+961,"top_SoC bus writeMuxes_1_io_in_0_writeResp_valid", false,-1);
        vcdp->declBus(c+4841,"top_SoC bus writeMuxes_1_io_in_0_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4849,"top_SoC bus writeMuxes_1_io_in_0_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+1113,"top_SoC bus writeMuxes_1_io_in_1_writeAddr_ready", false,-1);
        vcdp->declBit(c+1121,"top_SoC bus writeMuxes_1_io_in_1_writeAddr_valid", false,-1);
        vcdp->declBus(c+4937,"top_SoC bus writeMuxes_1_io_in_1_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4945,"top_SoC bus writeMuxes_1_io_in_1_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4953,"top_SoC bus writeMuxes_1_io_in_1_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1129,"top_SoC bus writeMuxes_1_io_in_1_writeData_ready", false,-1);
        vcdp->declBit(c+1137,"top_SoC bus writeMuxes_1_io_in_1_writeData_valid", false,-1);
        vcdp->declBus(c+1145,"top_SoC bus writeMuxes_1_io_in_1_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1153,"top_SoC bus writeMuxes_1_io_in_1_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1161,"top_SoC bus writeMuxes_1_io_in_1_writeData_bits_last", false,-1);
        vcdp->declBit(c+1169,"top_SoC bus writeMuxes_1_io_in_1_writeResp_ready", false,-1);
        vcdp->declBit(c+1177,"top_SoC bus writeMuxes_1_io_in_1_writeResp_valid", false,-1);
        vcdp->declBus(c+4961,"top_SoC bus writeMuxes_1_io_in_1_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4969,"top_SoC bus writeMuxes_1_io_in_1_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+5993,"top_SoC bus writeMuxes_2_clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus writeMuxes_2_reset", false,-1);
        vcdp->declBit(c+3801,"top_SoC bus writeMuxes_2_io_out_writeAddr_ready", false,-1);
        vcdp->declBit(c+3809,"top_SoC bus writeMuxes_2_io_out_writeAddr_valid", false,-1);
        vcdp->declBus(c+3817,"top_SoC bus writeMuxes_2_io_out_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3825,"top_SoC bus writeMuxes_2_io_out_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+5025,"top_SoC bus writeMuxes_2_io_out_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3833,"top_SoC bus writeMuxes_2_io_out_writeData_ready", false,-1);
        vcdp->declBit(c+3841,"top_SoC bus writeMuxes_2_io_out_writeData_valid", false,-1);
        vcdp->declBus(c+3849,"top_SoC bus writeMuxes_2_io_out_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3857,"top_SoC bus writeMuxes_2_io_out_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3865,"top_SoC bus writeMuxes_2_io_out_writeData_bits_last", false,-1);
        vcdp->declBit(c+249,"top_SoC bus writeMuxes_2_io_out_writeResp_ready", false,-1);
        vcdp->declBit(c+3873,"top_SoC bus writeMuxes_2_io_out_writeResp_valid", false,-1);
        vcdp->declBus(c+3881,"top_SoC bus writeMuxes_2_io_out_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+6481,"top_SoC bus writeMuxes_2_io_out_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+969,"top_SoC bus writeMuxes_2_io_in_0_writeAddr_ready", false,-1);
        vcdp->declBit(c+977,"top_SoC bus writeMuxes_2_io_in_0_writeAddr_valid", false,-1);
        vcdp->declBus(c+4857,"top_SoC bus writeMuxes_2_io_in_0_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4865,"top_SoC bus writeMuxes_2_io_in_0_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4873,"top_SoC bus writeMuxes_2_io_in_0_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+985,"top_SoC bus writeMuxes_2_io_in_0_writeData_ready", false,-1);
        vcdp->declBit(c+993,"top_SoC bus writeMuxes_2_io_in_0_writeData_valid", false,-1);
        vcdp->declBus(c+1001,"top_SoC bus writeMuxes_2_io_in_0_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1009,"top_SoC bus writeMuxes_2_io_in_0_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1017,"top_SoC bus writeMuxes_2_io_in_0_writeData_bits_last", false,-1);
        vcdp->declBit(c+1025,"top_SoC bus writeMuxes_2_io_in_0_writeResp_ready", false,-1);
        vcdp->declBit(c+1033,"top_SoC bus writeMuxes_2_io_in_0_writeResp_valid", false,-1);
        vcdp->declBus(c+4881,"top_SoC bus writeMuxes_2_io_in_0_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4889,"top_SoC bus writeMuxes_2_io_in_0_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+1185,"top_SoC bus writeMuxes_2_io_in_1_writeAddr_ready", false,-1);
        vcdp->declBit(c+1193,"top_SoC bus writeMuxes_2_io_in_1_writeAddr_valid", false,-1);
        vcdp->declBus(c+4977,"top_SoC bus writeMuxes_2_io_in_1_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4985,"top_SoC bus writeMuxes_2_io_in_1_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4993,"top_SoC bus writeMuxes_2_io_in_1_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1201,"top_SoC bus writeMuxes_2_io_in_1_writeData_ready", false,-1);
        vcdp->declBit(c+1209,"top_SoC bus writeMuxes_2_io_in_1_writeData_valid", false,-1);
        vcdp->declBus(c+1217,"top_SoC bus writeMuxes_2_io_in_1_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1225,"top_SoC bus writeMuxes_2_io_in_1_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1233,"top_SoC bus writeMuxes_2_io_in_1_writeData_bits_last", false,-1);
        vcdp->declBit(c+1241,"top_SoC bus writeMuxes_2_io_in_1_writeResp_ready", false,-1);
        vcdp->declBit(c+1249,"top_SoC bus writeMuxes_2_io_in_1_writeResp_valid", false,-1);
        vcdp->declBus(c+5001,"top_SoC bus writeMuxes_2_io_in_1_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+5009,"top_SoC bus writeMuxes_2_io_in_1_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+5993,"top_SoC bus readBuses_0 clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus readBuses_0 reset", false,-1);
        vcdp->declBit(c+3321,"top_SoC bus readBuses_0 io_master_readAddr_ready", false,-1);
        vcdp->declBit(c+3329,"top_SoC bus readBuses_0 io_master_readAddr_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC bus readBuses_0 io_master_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+113,"top_SoC bus readBuses_0 io_master_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6513,"top_SoC bus readBuses_0 io_master_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+121,"top_SoC bus readBuses_0 io_master_readData_ready", false,-1);
        vcdp->declBit(c+129,"top_SoC bus readBuses_0 io_master_readData_valid", false,-1);
        vcdp->declBus(c+4361,"top_SoC bus readBuses_0 io_master_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+137,"top_SoC bus readBuses_0 io_master_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4369,"top_SoC bus readBuses_0 io_master_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4377,"top_SoC bus readBuses_0 io_master_readData_bits_last", false,-1);
        vcdp->declBit(c+657,"top_SoC bus readBuses_0 io_slave_0_readAddr_ready", false,-1);
        vcdp->declBit(c+665,"top_SoC bus readBuses_0 io_slave_0_readAddr_valid", false,-1);
        vcdp->declBus(c+4385,"top_SoC bus readBuses_0 io_slave_0_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4393,"top_SoC bus readBuses_0 io_slave_0_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4401,"top_SoC bus readBuses_0 io_slave_0_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+673,"top_SoC bus readBuses_0 io_slave_0_readData_ready", false,-1);
        vcdp->declBit(c+681,"top_SoC bus readBuses_0 io_slave_0_readData_valid", false,-1);
        vcdp->declBus(c+4409,"top_SoC bus readBuses_0 io_slave_0_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4417,"top_SoC bus readBuses_0 io_slave_0_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4425,"top_SoC bus readBuses_0 io_slave_0_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4433,"top_SoC bus readBuses_0 io_slave_0_readData_bits_last", false,-1);
        vcdp->declBit(c+689,"top_SoC bus readBuses_0 io_slave_1_readAddr_ready", false,-1);
        vcdp->declBit(c+697,"top_SoC bus readBuses_0 io_slave_1_readAddr_valid", false,-1);
        vcdp->declBus(c+4441,"top_SoC bus readBuses_0 io_slave_1_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4449,"top_SoC bus readBuses_0 io_slave_1_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4457,"top_SoC bus readBuses_0 io_slave_1_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+705,"top_SoC bus readBuses_0 io_slave_1_readData_ready", false,-1);
        vcdp->declBit(c+713,"top_SoC bus readBuses_0 io_slave_1_readData_valid", false,-1);
        vcdp->declBus(c+4465,"top_SoC bus readBuses_0 io_slave_1_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4473,"top_SoC bus readBuses_0 io_slave_1_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4481,"top_SoC bus readBuses_0 io_slave_1_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4489,"top_SoC bus readBuses_0 io_slave_1_readData_bits_last", false,-1);
        vcdp->declBit(c+721,"top_SoC bus readBuses_0 io_slave_2_readAddr_ready", false,-1);
        vcdp->declBit(c+729,"top_SoC bus readBuses_0 io_slave_2_readAddr_valid", false,-1);
        vcdp->declBus(c+4497,"top_SoC bus readBuses_0 io_slave_2_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4505,"top_SoC bus readBuses_0 io_slave_2_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4513,"top_SoC bus readBuses_0 io_slave_2_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+737,"top_SoC bus readBuses_0 io_slave_2_readData_ready", false,-1);
        vcdp->declBit(c+745,"top_SoC bus readBuses_0 io_slave_2_readData_valid", false,-1);
        vcdp->declBus(c+4521,"top_SoC bus readBuses_0 io_slave_2_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4529,"top_SoC bus readBuses_0 io_slave_2_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4537,"top_SoC bus readBuses_0 io_slave_2_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4545,"top_SoC bus readBuses_0 io_slave_2_readData_bits_last", false,-1);
        vcdp->declBus(c+1257,"top_SoC bus readBuses_0 read_port", false,-1, 1,0);
        vcdp->declBus(c+5033,"top_SoC bus readBuses_0 read_port_reg", false,-1, 2,0);
        vcdp->declBus(c+5041,"top_SoC bus readBuses_0 read_addr_reg", false,-1, 31,0);
        vcdp->declBus(c+5049,"top_SoC bus readBuses_0 read_addr_reg_id", false,-1, 3,0);
        vcdp->declBus(c+5057,"top_SoC bus readBuses_0 read_addr_reg_size", false,-1, 2,0);
        vcdp->declBit(c+5065,"top_SoC bus readBuses_0 read_addr_reg_valid", false,-1);
        vcdp->declBit(c+5073,"top_SoC bus readBuses_0 outstanding", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readBuses_1 clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus readBuses_1 reset", false,-1);
        vcdp->declBit(c+3177,"top_SoC bus readBuses_1 io_master_readAddr_ready", false,-1);
        vcdp->declBit(c+3185,"top_SoC bus readBuses_1 io_master_readAddr_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC bus readBuses_1 io_master_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+57,"top_SoC bus readBuses_1 io_master_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6513,"top_SoC bus readBuses_1 io_master_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3193,"top_SoC bus readBuses_1 io_master_readData_ready", false,-1);
        vcdp->declBit(c+65,"top_SoC bus readBuses_1 io_master_readData_valid", false,-1);
        vcdp->declBus(c+3201,"top_SoC bus readBuses_1 io_master_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+73,"top_SoC bus readBuses_1 io_master_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3209,"top_SoC bus readBuses_1 io_master_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3217,"top_SoC bus readBuses_1 io_master_readData_bits_last", false,-1);
        vcdp->declBit(c+753,"top_SoC bus readBuses_1 io_slave_0_readAddr_ready", false,-1);
        vcdp->declBit(c+761,"top_SoC bus readBuses_1 io_slave_0_readAddr_valid", false,-1);
        vcdp->declBus(c+4553,"top_SoC bus readBuses_1 io_slave_0_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4561,"top_SoC bus readBuses_1 io_slave_0_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4569,"top_SoC bus readBuses_1 io_slave_0_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+4577,"top_SoC bus readBuses_1 io_slave_0_readData_ready", false,-1);
        vcdp->declBit(c+769,"top_SoC bus readBuses_1 io_slave_0_readData_valid", false,-1);
        vcdp->declBus(c+4585,"top_SoC bus readBuses_1 io_slave_0_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4593,"top_SoC bus readBuses_1 io_slave_0_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4601,"top_SoC bus readBuses_1 io_slave_0_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4609,"top_SoC bus readBuses_1 io_slave_0_readData_bits_last", false,-1);
        vcdp->declBit(c+777,"top_SoC bus readBuses_1 io_slave_1_readAddr_ready", false,-1);
        vcdp->declBit(c+785,"top_SoC bus readBuses_1 io_slave_1_readAddr_valid", false,-1);
        vcdp->declBus(c+4617,"top_SoC bus readBuses_1 io_slave_1_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4625,"top_SoC bus readBuses_1 io_slave_1_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4633,"top_SoC bus readBuses_1 io_slave_1_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+4641,"top_SoC bus readBuses_1 io_slave_1_readData_ready", false,-1);
        vcdp->declBit(c+793,"top_SoC bus readBuses_1 io_slave_1_readData_valid", false,-1);
        vcdp->declBus(c+4649,"top_SoC bus readBuses_1 io_slave_1_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4657,"top_SoC bus readBuses_1 io_slave_1_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4665,"top_SoC bus readBuses_1 io_slave_1_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4673,"top_SoC bus readBuses_1 io_slave_1_readData_bits_last", false,-1);
        vcdp->declBit(c+801,"top_SoC bus readBuses_1 io_slave_2_readAddr_ready", false,-1);
        vcdp->declBit(c+809,"top_SoC bus readBuses_1 io_slave_2_readAddr_valid", false,-1);
        vcdp->declBus(c+4681,"top_SoC bus readBuses_1 io_slave_2_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4689,"top_SoC bus readBuses_1 io_slave_2_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4697,"top_SoC bus readBuses_1 io_slave_2_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+4705,"top_SoC bus readBuses_1 io_slave_2_readData_ready", false,-1);
        vcdp->declBit(c+817,"top_SoC bus readBuses_1 io_slave_2_readData_valid", false,-1);
        vcdp->declBus(c+4713,"top_SoC bus readBuses_1 io_slave_2_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4721,"top_SoC bus readBuses_1 io_slave_2_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4729,"top_SoC bus readBuses_1 io_slave_2_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4737,"top_SoC bus readBuses_1 io_slave_2_readData_bits_last", false,-1);
        vcdp->declBus(c+1265,"top_SoC bus readBuses_1 read_port", false,-1, 1,0);
        vcdp->declBus(c+5081,"top_SoC bus readBuses_1 read_port_reg", false,-1, 2,0);
        vcdp->declBus(c+5089,"top_SoC bus readBuses_1 read_addr_reg", false,-1, 31,0);
        vcdp->declBus(c+5097,"top_SoC bus readBuses_1 read_addr_reg_id", false,-1, 3,0);
        vcdp->declBus(c+5105,"top_SoC bus readBuses_1 read_addr_reg_size", false,-1, 2,0);
        vcdp->declBit(c+5113,"top_SoC bus readBuses_1 read_addr_reg_valid", false,-1);
        vcdp->declBit(c+5121,"top_SoC bus readBuses_1 outstanding", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readMuxes_0 clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus readMuxes_0 reset", false,-1);
        vcdp->declBit(c+3057,"top_SoC bus readMuxes_0 io_out_readAddr_ready", false,-1);
        vcdp->declBit(c+3065,"top_SoC bus readMuxes_0 io_out_readAddr_valid", false,-1);
        vcdp->declBus(c+3073,"top_SoC bus readMuxes_0 io_out_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3081,"top_SoC bus readMuxes_0 io_out_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+3089,"top_SoC bus readMuxes_0 io_out_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+17,"top_SoC bus readMuxes_0 io_out_readData_ready", false,-1);
        vcdp->declBit(c+3097,"top_SoC bus readMuxes_0 io_out_readData_valid", false,-1);
        vcdp->declBus(c+3105,"top_SoC bus readMuxes_0 io_out_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3113,"top_SoC bus readMuxes_0 io_out_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+6481,"top_SoC bus readMuxes_0 io_out_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+6505,"top_SoC bus readMuxes_0 io_out_readData_bits_last", false,-1);
        vcdp->declBit(c+657,"top_SoC bus readMuxes_0 io_in_0_readAddr_ready", false,-1);
        vcdp->declBit(c+665,"top_SoC bus readMuxes_0 io_in_0_readAddr_valid", false,-1);
        vcdp->declBus(c+4385,"top_SoC bus readMuxes_0 io_in_0_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4393,"top_SoC bus readMuxes_0 io_in_0_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4401,"top_SoC bus readMuxes_0 io_in_0_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+673,"top_SoC bus readMuxes_0 io_in_0_readData_ready", false,-1);
        vcdp->declBit(c+681,"top_SoC bus readMuxes_0 io_in_0_readData_valid", false,-1);
        vcdp->declBus(c+4409,"top_SoC bus readMuxes_0 io_in_0_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4417,"top_SoC bus readMuxes_0 io_in_0_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4425,"top_SoC bus readMuxes_0 io_in_0_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4433,"top_SoC bus readMuxes_0 io_in_0_readData_bits_last", false,-1);
        vcdp->declBit(c+753,"top_SoC bus readMuxes_0 io_in_1_readAddr_ready", false,-1);
        vcdp->declBit(c+761,"top_SoC bus readMuxes_0 io_in_1_readAddr_valid", false,-1);
        vcdp->declBus(c+4553,"top_SoC bus readMuxes_0 io_in_1_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4561,"top_SoC bus readMuxes_0 io_in_1_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4569,"top_SoC bus readMuxes_0 io_in_1_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+4577,"top_SoC bus readMuxes_0 io_in_1_readData_ready", false,-1);
        vcdp->declBit(c+769,"top_SoC bus readMuxes_0 io_in_1_readData_valid", false,-1);
        vcdp->declBus(c+4585,"top_SoC bus readMuxes_0 io_in_1_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4593,"top_SoC bus readMuxes_0 io_in_1_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4601,"top_SoC bus readMuxes_0 io_in_1_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4609,"top_SoC bus readMuxes_0 io_in_1_readData_bits_last", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readMuxes_0 arbiter_clock", false,-1);
        vcdp->declBit(c+1273,"top_SoC bus readMuxes_0 arbiter_io_in_0_ready", false,-1);
        vcdp->declBit(c+1281,"top_SoC bus readMuxes_0 arbiter_io_in_0_valid", false,-1);
        vcdp->declBit(c+1289,"top_SoC bus readMuxes_0 arbiter_io_in_1_ready", false,-1);
        vcdp->declBit(c+1297,"top_SoC bus readMuxes_0 arbiter_io_in_1_valid", false,-1);
        vcdp->declBit(c+1305,"top_SoC bus readMuxes_0 arbiter_io_out_valid", false,-1);
        vcdp->declBit(c+1313,"top_SoC bus readMuxes_0 arbiter_io_chosen", false,-1);
        vcdp->declBus(c+5129,"top_SoC bus readMuxes_0 state", false,-1, 1,0);
        vcdp->declBit(c+1321,"top_SoC bus readMuxes_0 outstanding", false,-1);
        vcdp->declBit(c+5137,"top_SoC bus readMuxes_0 chosen_reg", false,-1);
        vcdp->declBit(c+3065,"top_SoC bus readMuxes_0 ar_determined", false,-1);
        vcdp->declBus(c+3073,"top_SoC bus readMuxes_0 address_reg_id", false,-1, 3,0);
        vcdp->declBus(c+3081,"top_SoC bus readMuxes_0 address_reg_addr", false,-1, 31,0);
        vcdp->declBus(c+3089,"top_SoC bus readMuxes_0 address_reg_size", false,-1, 1,0);
        vcdp->declBus(c+5145,"top_SoC bus readMuxes_0 data_reg_id", false,-1, 3,0);
        vcdp->declBus(c+5153,"top_SoC bus readMuxes_0 data_reg_data", false,-1, 31,0);
        vcdp->declBus(c+5161,"top_SoC bus readMuxes_0 data_reg_resp", false,-1, 1,0);
        vcdp->declBit(c+5169,"top_SoC bus readMuxes_0 data_reg_last", false,-1);
        vcdp->declBit(c+1329,"top_SoC bus readMuxes_0 mask_0", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readMuxes_0 arbiter clock", false,-1);
        vcdp->declBit(c+1273,"top_SoC bus readMuxes_0 arbiter io_in_0_ready", false,-1);
        vcdp->declBit(c+1281,"top_SoC bus readMuxes_0 arbiter io_in_0_valid", false,-1);
        vcdp->declBit(c+1289,"top_SoC bus readMuxes_0 arbiter io_in_1_ready", false,-1);
        vcdp->declBit(c+1297,"top_SoC bus readMuxes_0 arbiter io_in_1_valid", false,-1);
        vcdp->declBit(c+1305,"top_SoC bus readMuxes_0 arbiter io_out_valid", false,-1);
        vcdp->declBit(c+1313,"top_SoC bus readMuxes_0 arbiter io_chosen", false,-1);
        vcdp->declBit(c+5177,"top_SoC bus readMuxes_0 arbiter lastGrant", false,-1);
        vcdp->declBit(c+5185,"top_SoC bus readMuxes_0 arbiter grantMask_1", false,-1);
        vcdp->declBit(c+1337,"top_SoC bus readMuxes_0 arbiter validMask_1", false,-1);
        vcdp->declBit(c+1345,"top_SoC bus readMuxes_0 arbiter ctrl_3", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readMuxes_1 clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus readMuxes_1 reset", false,-1);
        vcdp->declBit(c+3753,"top_SoC bus readMuxes_1 io_out_readAddr_ready", false,-1);
        vcdp->declBit(c+3761,"top_SoC bus readMuxes_1 io_out_readAddr_valid", false,-1);
        vcdp->declBus(c+3769,"top_SoC bus readMuxes_1 io_out_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3777,"top_SoC bus readMuxes_1 io_out_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4745,"top_SoC bus readMuxes_1 io_out_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+225,"top_SoC bus readMuxes_1 io_out_readData_ready", false,-1);
        vcdp->declBit(c+233,"top_SoC bus readMuxes_1 io_out_readData_valid", false,-1);
        vcdp->declBus(c+3785,"top_SoC bus readMuxes_1 io_out_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+241,"top_SoC bus readMuxes_1 io_out_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+6481,"top_SoC bus readMuxes_1 io_out_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3793,"top_SoC bus readMuxes_1 io_out_readData_bits_last", false,-1);
        vcdp->declBit(c+689,"top_SoC bus readMuxes_1 io_in_0_readAddr_ready", false,-1);
        vcdp->declBit(c+697,"top_SoC bus readMuxes_1 io_in_0_readAddr_valid", false,-1);
        vcdp->declBus(c+4441,"top_SoC bus readMuxes_1 io_in_0_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4449,"top_SoC bus readMuxes_1 io_in_0_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4457,"top_SoC bus readMuxes_1 io_in_0_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+705,"top_SoC bus readMuxes_1 io_in_0_readData_ready", false,-1);
        vcdp->declBit(c+713,"top_SoC bus readMuxes_1 io_in_0_readData_valid", false,-1);
        vcdp->declBus(c+4465,"top_SoC bus readMuxes_1 io_in_0_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4473,"top_SoC bus readMuxes_1 io_in_0_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4481,"top_SoC bus readMuxes_1 io_in_0_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4489,"top_SoC bus readMuxes_1 io_in_0_readData_bits_last", false,-1);
        vcdp->declBit(c+777,"top_SoC bus readMuxes_1 io_in_1_readAddr_ready", false,-1);
        vcdp->declBit(c+785,"top_SoC bus readMuxes_1 io_in_1_readAddr_valid", false,-1);
        vcdp->declBus(c+4617,"top_SoC bus readMuxes_1 io_in_1_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4625,"top_SoC bus readMuxes_1 io_in_1_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4633,"top_SoC bus readMuxes_1 io_in_1_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+4641,"top_SoC bus readMuxes_1 io_in_1_readData_ready", false,-1);
        vcdp->declBit(c+793,"top_SoC bus readMuxes_1 io_in_1_readData_valid", false,-1);
        vcdp->declBus(c+4649,"top_SoC bus readMuxes_1 io_in_1_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4657,"top_SoC bus readMuxes_1 io_in_1_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4665,"top_SoC bus readMuxes_1 io_in_1_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4673,"top_SoC bus readMuxes_1 io_in_1_readData_bits_last", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readMuxes_1 arbiter_clock", false,-1);
        vcdp->declBit(c+1353,"top_SoC bus readMuxes_1 arbiter_io_in_0_ready", false,-1);
        vcdp->declBit(c+1361,"top_SoC bus readMuxes_1 arbiter_io_in_0_valid", false,-1);
        vcdp->declBit(c+1369,"top_SoC bus readMuxes_1 arbiter_io_in_1_ready", false,-1);
        vcdp->declBit(c+1377,"top_SoC bus readMuxes_1 arbiter_io_in_1_valid", false,-1);
        vcdp->declBit(c+1385,"top_SoC bus readMuxes_1 arbiter_io_out_valid", false,-1);
        vcdp->declBit(c+1393,"top_SoC bus readMuxes_1 arbiter_io_chosen", false,-1);
        vcdp->declBus(c+5193,"top_SoC bus readMuxes_1 state", false,-1, 1,0);
        vcdp->declBit(c+1401,"top_SoC bus readMuxes_1 outstanding", false,-1);
        vcdp->declBit(c+5201,"top_SoC bus readMuxes_1 chosen_reg", false,-1);
        vcdp->declBit(c+3761,"top_SoC bus readMuxes_1 ar_determined", false,-1);
        vcdp->declBus(c+3769,"top_SoC bus readMuxes_1 address_reg_id", false,-1, 3,0);
        vcdp->declBus(c+3777,"top_SoC bus readMuxes_1 address_reg_addr", false,-1, 31,0);
        vcdp->declBus(c+4745,"top_SoC bus readMuxes_1 address_reg_size", false,-1, 1,0);
        vcdp->declBus(c+5209,"top_SoC bus readMuxes_1 data_reg_id", false,-1, 3,0);
        vcdp->declBus(c+5217,"top_SoC bus readMuxes_1 data_reg_data", false,-1, 31,0);
        vcdp->declBus(c+5225,"top_SoC bus readMuxes_1 data_reg_resp", false,-1, 1,0);
        vcdp->declBit(c+5233,"top_SoC bus readMuxes_1 data_reg_last", false,-1);
        vcdp->declBit(c+1409,"top_SoC bus readMuxes_1 mask_0", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readMuxes_1 arbiter clock", false,-1);
        vcdp->declBit(c+1353,"top_SoC bus readMuxes_1 arbiter io_in_0_ready", false,-1);
        vcdp->declBit(c+1361,"top_SoC bus readMuxes_1 arbiter io_in_0_valid", false,-1);
        vcdp->declBit(c+1369,"top_SoC bus readMuxes_1 arbiter io_in_1_ready", false,-1);
        vcdp->declBit(c+1377,"top_SoC bus readMuxes_1 arbiter io_in_1_valid", false,-1);
        vcdp->declBit(c+1385,"top_SoC bus readMuxes_1 arbiter io_out_valid", false,-1);
        vcdp->declBit(c+1393,"top_SoC bus readMuxes_1 arbiter io_chosen", false,-1);
        vcdp->declBit(c+5241,"top_SoC bus readMuxes_1 arbiter lastGrant", false,-1);
        vcdp->declBit(c+5249,"top_SoC bus readMuxes_1 arbiter grantMask_1", false,-1);
        vcdp->declBit(c+1417,"top_SoC bus readMuxes_1 arbiter validMask_1", false,-1);
        vcdp->declBit(c+1425,"top_SoC bus readMuxes_1 arbiter ctrl_3", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readMuxes_2 clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus readMuxes_2 reset", false,-1);
        vcdp->declBit(c+3889,"top_SoC bus readMuxes_2 io_out_readAddr_ready", false,-1);
        vcdp->declBit(c+3897,"top_SoC bus readMuxes_2 io_out_readAddr_valid", false,-1);
        vcdp->declBus(c+3905,"top_SoC bus readMuxes_2 io_out_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3913,"top_SoC bus readMuxes_2 io_out_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4753,"top_SoC bus readMuxes_2 io_out_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+257,"top_SoC bus readMuxes_2 io_out_readData_ready", false,-1);
        vcdp->declBit(c+265,"top_SoC bus readMuxes_2 io_out_readData_valid", false,-1);
        vcdp->declBus(c+3921,"top_SoC bus readMuxes_2 io_out_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+273,"top_SoC bus readMuxes_2 io_out_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+6481,"top_SoC bus readMuxes_2 io_out_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+3929,"top_SoC bus readMuxes_2 io_out_readData_bits_last", false,-1);
        vcdp->declBit(c+721,"top_SoC bus readMuxes_2 io_in_0_readAddr_ready", false,-1);
        vcdp->declBit(c+729,"top_SoC bus readMuxes_2 io_in_0_readAddr_valid", false,-1);
        vcdp->declBus(c+4497,"top_SoC bus readMuxes_2 io_in_0_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4505,"top_SoC bus readMuxes_2 io_in_0_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4513,"top_SoC bus readMuxes_2 io_in_0_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+737,"top_SoC bus readMuxes_2 io_in_0_readData_ready", false,-1);
        vcdp->declBit(c+745,"top_SoC bus readMuxes_2 io_in_0_readData_valid", false,-1);
        vcdp->declBus(c+4521,"top_SoC bus readMuxes_2 io_in_0_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4529,"top_SoC bus readMuxes_2 io_in_0_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4537,"top_SoC bus readMuxes_2 io_in_0_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4545,"top_SoC bus readMuxes_2 io_in_0_readData_bits_last", false,-1);
        vcdp->declBit(c+801,"top_SoC bus readMuxes_2 io_in_1_readAddr_ready", false,-1);
        vcdp->declBit(c+809,"top_SoC bus readMuxes_2 io_in_1_readAddr_valid", false,-1);
        vcdp->declBus(c+4681,"top_SoC bus readMuxes_2 io_in_1_readAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4689,"top_SoC bus readMuxes_2 io_in_1_readAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4697,"top_SoC bus readMuxes_2 io_in_1_readAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+4705,"top_SoC bus readMuxes_2 io_in_1_readData_ready", false,-1);
        vcdp->declBit(c+817,"top_SoC bus readMuxes_2 io_in_1_readData_valid", false,-1);
        vcdp->declBus(c+4713,"top_SoC bus readMuxes_2 io_in_1_readData_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4721,"top_SoC bus readMuxes_2 io_in_1_readData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+4729,"top_SoC bus readMuxes_2 io_in_1_readData_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+4737,"top_SoC bus readMuxes_2 io_in_1_readData_bits_last", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readMuxes_2 arbiter_clock", false,-1);
        vcdp->declBit(c+1433,"top_SoC bus readMuxes_2 arbiter_io_in_0_ready", false,-1);
        vcdp->declBit(c+1441,"top_SoC bus readMuxes_2 arbiter_io_in_0_valid", false,-1);
        vcdp->declBit(c+1449,"top_SoC bus readMuxes_2 arbiter_io_in_1_ready", false,-1);
        vcdp->declBit(c+1457,"top_SoC bus readMuxes_2 arbiter_io_in_1_valid", false,-1);
        vcdp->declBit(c+1465,"top_SoC bus readMuxes_2 arbiter_io_out_valid", false,-1);
        vcdp->declBit(c+1473,"top_SoC bus readMuxes_2 arbiter_io_chosen", false,-1);
        vcdp->declBus(c+5257,"top_SoC bus readMuxes_2 state", false,-1, 1,0);
        vcdp->declBit(c+1481,"top_SoC bus readMuxes_2 outstanding", false,-1);
        vcdp->declBit(c+5265,"top_SoC bus readMuxes_2 chosen_reg", false,-1);
        vcdp->declBit(c+3897,"top_SoC bus readMuxes_2 ar_determined", false,-1);
        vcdp->declBus(c+3905,"top_SoC bus readMuxes_2 address_reg_id", false,-1, 3,0);
        vcdp->declBus(c+3913,"top_SoC bus readMuxes_2 address_reg_addr", false,-1, 31,0);
        vcdp->declBus(c+4753,"top_SoC bus readMuxes_2 address_reg_size", false,-1, 1,0);
        vcdp->declBus(c+5273,"top_SoC bus readMuxes_2 data_reg_id", false,-1, 3,0);
        vcdp->declBus(c+5281,"top_SoC bus readMuxes_2 data_reg_data", false,-1, 31,0);
        vcdp->declBus(c+5289,"top_SoC bus readMuxes_2 data_reg_resp", false,-1, 1,0);
        vcdp->declBit(c+5297,"top_SoC bus readMuxes_2 data_reg_last", false,-1);
        vcdp->declBit(c+1489,"top_SoC bus readMuxes_2 mask_0", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus readMuxes_2 arbiter clock", false,-1);
        vcdp->declBit(c+1433,"top_SoC bus readMuxes_2 arbiter io_in_0_ready", false,-1);
        vcdp->declBit(c+1441,"top_SoC bus readMuxes_2 arbiter io_in_0_valid", false,-1);
        vcdp->declBit(c+1449,"top_SoC bus readMuxes_2 arbiter io_in_1_ready", false,-1);
        vcdp->declBit(c+1457,"top_SoC bus readMuxes_2 arbiter io_in_1_valid", false,-1);
        vcdp->declBit(c+1465,"top_SoC bus readMuxes_2 arbiter io_out_valid", false,-1);
        vcdp->declBit(c+1473,"top_SoC bus readMuxes_2 arbiter io_chosen", false,-1);
        vcdp->declBit(c+5305,"top_SoC bus readMuxes_2 arbiter lastGrant", false,-1);
        vcdp->declBit(c+5313,"top_SoC bus readMuxes_2 arbiter grantMask_1", false,-1);
        vcdp->declBit(c+1497,"top_SoC bus readMuxes_2 arbiter validMask_1", false,-1);
        vcdp->declBit(c+1505,"top_SoC bus readMuxes_2 arbiter ctrl_3", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus writeBuses_0 clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus writeBuses_0 reset", false,-1);
        vcdp->declBit(c+3281,"top_SoC bus writeBuses_0 io_master_writeAddr_ready", false,-1);
        vcdp->declBit(c+3289,"top_SoC bus writeBuses_0 io_master_writeAddr_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC bus writeBuses_0 io_master_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+89,"top_SoC bus writeBuses_0 io_master_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6513,"top_SoC bus writeBuses_0 io_master_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3297,"top_SoC bus writeBuses_0 io_master_writeData_ready", false,-1);
        vcdp->declBit(c+3289,"top_SoC bus writeBuses_0 io_master_writeData_valid", false,-1);
        vcdp->declBus(c+97,"top_SoC bus writeBuses_0 io_master_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3305,"top_SoC bus writeBuses_0 io_master_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+6505,"top_SoC bus writeBuses_0 io_master_writeData_bits_last", false,-1);
        vcdp->declBit(c+105,"top_SoC bus writeBuses_0 io_master_writeResp_ready", false,-1);
        vcdp->declBit(c+3313,"top_SoC bus writeBuses_0 io_master_writeResp_valid", false,-1);
        vcdp->declBus(c+4761,"top_SoC bus writeBuses_0 io_master_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4769,"top_SoC bus writeBuses_0 io_master_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+825,"top_SoC bus writeBuses_0 io_slave_0_writeAddr_ready", false,-1);
        vcdp->declBit(c+833,"top_SoC bus writeBuses_0 io_slave_0_writeAddr_valid", false,-1);
        vcdp->declBus(c+4777,"top_SoC bus writeBuses_0 io_slave_0_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4785,"top_SoC bus writeBuses_0 io_slave_0_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4793,"top_SoC bus writeBuses_0 io_slave_0_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+841,"top_SoC bus writeBuses_0 io_slave_0_writeData_ready", false,-1);
        vcdp->declBit(c+849,"top_SoC bus writeBuses_0 io_slave_0_writeData_valid", false,-1);
        vcdp->declBus(c+857,"top_SoC bus writeBuses_0 io_slave_0_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+865,"top_SoC bus writeBuses_0 io_slave_0_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+873,"top_SoC bus writeBuses_0 io_slave_0_writeData_bits_last", false,-1);
        vcdp->declBit(c+881,"top_SoC bus writeBuses_0 io_slave_0_writeResp_ready", false,-1);
        vcdp->declBit(c+889,"top_SoC bus writeBuses_0 io_slave_0_writeResp_valid", false,-1);
        vcdp->declBus(c+4801,"top_SoC bus writeBuses_0 io_slave_0_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4809,"top_SoC bus writeBuses_0 io_slave_0_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+897,"top_SoC bus writeBuses_0 io_slave_1_writeAddr_ready", false,-1);
        vcdp->declBit(c+905,"top_SoC bus writeBuses_0 io_slave_1_writeAddr_valid", false,-1);
        vcdp->declBus(c+4817,"top_SoC bus writeBuses_0 io_slave_1_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4825,"top_SoC bus writeBuses_0 io_slave_1_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4833,"top_SoC bus writeBuses_0 io_slave_1_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+913,"top_SoC bus writeBuses_0 io_slave_1_writeData_ready", false,-1);
        vcdp->declBit(c+921,"top_SoC bus writeBuses_0 io_slave_1_writeData_valid", false,-1);
        vcdp->declBus(c+929,"top_SoC bus writeBuses_0 io_slave_1_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+937,"top_SoC bus writeBuses_0 io_slave_1_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+945,"top_SoC bus writeBuses_0 io_slave_1_writeData_bits_last", false,-1);
        vcdp->declBit(c+953,"top_SoC bus writeBuses_0 io_slave_1_writeResp_ready", false,-1);
        vcdp->declBit(c+961,"top_SoC bus writeBuses_0 io_slave_1_writeResp_valid", false,-1);
        vcdp->declBus(c+4841,"top_SoC bus writeBuses_0 io_slave_1_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4849,"top_SoC bus writeBuses_0 io_slave_1_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+969,"top_SoC bus writeBuses_0 io_slave_2_writeAddr_ready", false,-1);
        vcdp->declBit(c+977,"top_SoC bus writeBuses_0 io_slave_2_writeAddr_valid", false,-1);
        vcdp->declBus(c+4857,"top_SoC bus writeBuses_0 io_slave_2_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4865,"top_SoC bus writeBuses_0 io_slave_2_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4873,"top_SoC bus writeBuses_0 io_slave_2_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+985,"top_SoC bus writeBuses_0 io_slave_2_writeData_ready", false,-1);
        vcdp->declBit(c+993,"top_SoC bus writeBuses_0 io_slave_2_writeData_valid", false,-1);
        vcdp->declBus(c+1001,"top_SoC bus writeBuses_0 io_slave_2_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1009,"top_SoC bus writeBuses_0 io_slave_2_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1017,"top_SoC bus writeBuses_0 io_slave_2_writeData_bits_last", false,-1);
        vcdp->declBit(c+1025,"top_SoC bus writeBuses_0 io_slave_2_writeResp_ready", false,-1);
        vcdp->declBit(c+1033,"top_SoC bus writeBuses_0 io_slave_2_writeResp_valid", false,-1);
        vcdp->declBus(c+4881,"top_SoC bus writeBuses_0 io_slave_2_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4889,"top_SoC bus writeBuses_0 io_slave_2_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBus(c+1513,"top_SoC bus writeBuses_0 write_port", false,-1, 1,0);
        vcdp->declBus(c+5321,"top_SoC bus writeBuses_0 write_port_reg", false,-1, 2,0);
        vcdp->declBus(c+5329,"top_SoC bus writeBuses_0 write_addr_reg", false,-1, 31,0);
        vcdp->declBit(c+5337,"top_SoC bus writeBuses_0 write_addr_reg_valid", false,-1);
        vcdp->declBus(c+5345,"top_SoC bus writeBuses_0 write_addr_reg_id", false,-1, 3,0);
        vcdp->declBus(c+5353,"top_SoC bus writeBuses_0 write_addr_reg_size", false,-1, 2,0);
        vcdp->declBus(c+5361,"top_SoC bus writeBuses_0 write_data_reg", false,-1, 31,0);
        vcdp->declBit(c+5369,"top_SoC bus writeBuses_0 write_data_reg_valid", false,-1);
        vcdp->declBus(c+5377,"top_SoC bus writeBuses_0 write_data_reg_strb", false,-1, 3,0);
        vcdp->declBit(c+5385,"top_SoC bus writeBuses_0 write_data_reg_last", false,-1);
        vcdp->declBus(c+5393,"top_SoC bus writeBuses_0 write_resp_reg", false,-1, 3,0);
        vcdp->declBit(c+3313,"top_SoC bus writeBuses_0 write_resp_reg_valid", false,-1);
        vcdp->declBus(c+4761,"top_SoC bus writeBuses_0 write_resp_reg_id", false,-1, 3,0);
        vcdp->declBit(c+5401,"top_SoC bus writeBuses_0 w_outstanding", false,-1);
        vcdp->declBit(c+5409,"top_SoC bus writeBuses_0 aw_outstanding", false,-1);
        vcdp->declBit(c+5417,"top_SoC bus writeBuses_0 b_outstanding", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus writeBuses_1 clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus writeBuses_1 reset", false,-1);
        vcdp->declBit(c+3121,"top_SoC bus writeBuses_1 io_master_writeAddr_ready", false,-1);
        vcdp->declBit(c+25,"top_SoC bus writeBuses_1 io_master_writeAddr_valid", false,-1);
        vcdp->declBus(c+6465,"top_SoC bus writeBuses_1 io_master_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+33,"top_SoC bus writeBuses_1 io_master_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+6513,"top_SoC bus writeBuses_1 io_master_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3129,"top_SoC bus writeBuses_1 io_master_writeData_ready", false,-1);
        vcdp->declBit(c+3137,"top_SoC bus writeBuses_1 io_master_writeData_valid", false,-1);
        vcdp->declBus(c+41,"top_SoC bus writeBuses_1 io_master_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+49,"top_SoC bus writeBuses_1 io_master_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+6505,"top_SoC bus writeBuses_1 io_master_writeData_bits_last", false,-1);
        vcdp->declBit(c+3145,"top_SoC bus writeBuses_1 io_master_writeResp_ready", false,-1);
        vcdp->declBit(c+3153,"top_SoC bus writeBuses_1 io_master_writeResp_valid", false,-1);
        vcdp->declBus(c+3161,"top_SoC bus writeBuses_1 io_master_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3169,"top_SoC bus writeBuses_1 io_master_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+1041,"top_SoC bus writeBuses_1 io_slave_0_writeAddr_ready", false,-1);
        vcdp->declBit(c+1049,"top_SoC bus writeBuses_1 io_slave_0_writeAddr_valid", false,-1);
        vcdp->declBus(c+4897,"top_SoC bus writeBuses_1 io_slave_0_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4905,"top_SoC bus writeBuses_1 io_slave_0_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4913,"top_SoC bus writeBuses_1 io_slave_0_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1057,"top_SoC bus writeBuses_1 io_slave_0_writeData_ready", false,-1);
        vcdp->declBit(c+1065,"top_SoC bus writeBuses_1 io_slave_0_writeData_valid", false,-1);
        vcdp->declBus(c+1073,"top_SoC bus writeBuses_1 io_slave_0_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1081,"top_SoC bus writeBuses_1 io_slave_0_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1089,"top_SoC bus writeBuses_1 io_slave_0_writeData_bits_last", false,-1);
        vcdp->declBit(c+1097,"top_SoC bus writeBuses_1 io_slave_0_writeResp_ready", false,-1);
        vcdp->declBit(c+1105,"top_SoC bus writeBuses_1 io_slave_0_writeResp_valid", false,-1);
        vcdp->declBus(c+4921,"top_SoC bus writeBuses_1 io_slave_0_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4929,"top_SoC bus writeBuses_1 io_slave_0_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+1113,"top_SoC bus writeBuses_1 io_slave_1_writeAddr_ready", false,-1);
        vcdp->declBit(c+1121,"top_SoC bus writeBuses_1 io_slave_1_writeAddr_valid", false,-1);
        vcdp->declBus(c+4937,"top_SoC bus writeBuses_1 io_slave_1_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4945,"top_SoC bus writeBuses_1 io_slave_1_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4953,"top_SoC bus writeBuses_1 io_slave_1_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1129,"top_SoC bus writeBuses_1 io_slave_1_writeData_ready", false,-1);
        vcdp->declBit(c+1137,"top_SoC bus writeBuses_1 io_slave_1_writeData_valid", false,-1);
        vcdp->declBus(c+1145,"top_SoC bus writeBuses_1 io_slave_1_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1153,"top_SoC bus writeBuses_1 io_slave_1_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1161,"top_SoC bus writeBuses_1 io_slave_1_writeData_bits_last", false,-1);
        vcdp->declBit(c+1169,"top_SoC bus writeBuses_1 io_slave_1_writeResp_ready", false,-1);
        vcdp->declBit(c+1177,"top_SoC bus writeBuses_1 io_slave_1_writeResp_valid", false,-1);
        vcdp->declBus(c+4961,"top_SoC bus writeBuses_1 io_slave_1_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4969,"top_SoC bus writeBuses_1 io_slave_1_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+1185,"top_SoC bus writeBuses_1 io_slave_2_writeAddr_ready", false,-1);
        vcdp->declBit(c+1193,"top_SoC bus writeBuses_1 io_slave_2_writeAddr_valid", false,-1);
        vcdp->declBus(c+4977,"top_SoC bus writeBuses_1 io_slave_2_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4985,"top_SoC bus writeBuses_1 io_slave_2_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4993,"top_SoC bus writeBuses_1 io_slave_2_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1201,"top_SoC bus writeBuses_1 io_slave_2_writeData_ready", false,-1);
        vcdp->declBit(c+1209,"top_SoC bus writeBuses_1 io_slave_2_writeData_valid", false,-1);
        vcdp->declBus(c+1217,"top_SoC bus writeBuses_1 io_slave_2_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1225,"top_SoC bus writeBuses_1 io_slave_2_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1233,"top_SoC bus writeBuses_1 io_slave_2_writeData_bits_last", false,-1);
        vcdp->declBit(c+1241,"top_SoC bus writeBuses_1 io_slave_2_writeResp_ready", false,-1);
        vcdp->declBit(c+1249,"top_SoC bus writeBuses_1 io_slave_2_writeResp_valid", false,-1);
        vcdp->declBus(c+5001,"top_SoC bus writeBuses_1 io_slave_2_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+5009,"top_SoC bus writeBuses_1 io_slave_2_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBus(c+1521,"top_SoC bus writeBuses_1 write_port", false,-1, 1,0);
        vcdp->declBus(c+5425,"top_SoC bus writeBuses_1 write_port_reg", false,-1, 2,0);
        vcdp->declBus(c+5433,"top_SoC bus writeBuses_1 write_addr_reg", false,-1, 31,0);
        vcdp->declBit(c+5441,"top_SoC bus writeBuses_1 write_addr_reg_valid", false,-1);
        vcdp->declBus(c+5449,"top_SoC bus writeBuses_1 write_addr_reg_id", false,-1, 3,0);
        vcdp->declBus(c+5457,"top_SoC bus writeBuses_1 write_addr_reg_size", false,-1, 2,0);
        vcdp->declBus(c+5465,"top_SoC bus writeBuses_1 write_data_reg", false,-1, 31,0);
        vcdp->declBit(c+5473,"top_SoC bus writeBuses_1 write_data_reg_valid", false,-1);
        vcdp->declBus(c+5481,"top_SoC bus writeBuses_1 write_data_reg_strb", false,-1, 3,0);
        vcdp->declBit(c+5489,"top_SoC bus writeBuses_1 write_data_reg_last", false,-1);
        vcdp->declBus(c+5497,"top_SoC bus writeBuses_1 write_resp_reg", false,-1, 3,0);
        vcdp->declBit(c+3153,"top_SoC bus writeBuses_1 write_resp_reg_valid", false,-1);
        vcdp->declBus(c+3161,"top_SoC bus writeBuses_1 write_resp_reg_id", false,-1, 3,0);
        vcdp->declBit(c+5505,"top_SoC bus writeBuses_1 w_outstanding", false,-1);
        vcdp->declBit(c+5513,"top_SoC bus writeBuses_1 aw_outstanding", false,-1);
        vcdp->declBit(c+5521,"top_SoC bus writeBuses_1 b_outstanding", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus writeMuxes_0 clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus writeMuxes_0 reset", false,-1);
        vcdp->declBit(c+2969,"top_SoC bus writeMuxes_0 io_out_writeAddr_ready", false,-1);
        vcdp->declBit(c+2977,"top_SoC bus writeMuxes_0 io_out_writeAddr_valid", false,-1);
        vcdp->declBus(c+2985,"top_SoC bus writeMuxes_0 io_out_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+2993,"top_SoC bus writeMuxes_0 io_out_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+3001,"top_SoC bus writeMuxes_0 io_out_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1,"top_SoC bus writeMuxes_0 io_out_writeData_ready", false,-1);
        vcdp->declBit(c+3009,"top_SoC bus writeMuxes_0 io_out_writeData_valid", false,-1);
        vcdp->declBus(c+3017,"top_SoC bus writeMuxes_0 io_out_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3025,"top_SoC bus writeMuxes_0 io_out_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3033,"top_SoC bus writeMuxes_0 io_out_writeData_bits_last", false,-1);
        vcdp->declBit(c+9,"top_SoC bus writeMuxes_0 io_out_writeResp_ready", false,-1);
        vcdp->declBit(c+3041,"top_SoC bus writeMuxes_0 io_out_writeResp_valid", false,-1);
        vcdp->declBus(c+3049,"top_SoC bus writeMuxes_0 io_out_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+6481,"top_SoC bus writeMuxes_0 io_out_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+825,"top_SoC bus writeMuxes_0 io_in_0_writeAddr_ready", false,-1);
        vcdp->declBit(c+833,"top_SoC bus writeMuxes_0 io_in_0_writeAddr_valid", false,-1);
        vcdp->declBus(c+4777,"top_SoC bus writeMuxes_0 io_in_0_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4785,"top_SoC bus writeMuxes_0 io_in_0_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4793,"top_SoC bus writeMuxes_0 io_in_0_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+841,"top_SoC bus writeMuxes_0 io_in_0_writeData_ready", false,-1);
        vcdp->declBit(c+849,"top_SoC bus writeMuxes_0 io_in_0_writeData_valid", false,-1);
        vcdp->declBus(c+857,"top_SoC bus writeMuxes_0 io_in_0_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+865,"top_SoC bus writeMuxes_0 io_in_0_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+873,"top_SoC bus writeMuxes_0 io_in_0_writeData_bits_last", false,-1);
        vcdp->declBit(c+881,"top_SoC bus writeMuxes_0 io_in_0_writeResp_ready", false,-1);
        vcdp->declBit(c+889,"top_SoC bus writeMuxes_0 io_in_0_writeResp_valid", false,-1);
        vcdp->declBus(c+4801,"top_SoC bus writeMuxes_0 io_in_0_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4809,"top_SoC bus writeMuxes_0 io_in_0_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+1041,"top_SoC bus writeMuxes_0 io_in_1_writeAddr_ready", false,-1);
        vcdp->declBit(c+1049,"top_SoC bus writeMuxes_0 io_in_1_writeAddr_valid", false,-1);
        vcdp->declBus(c+4897,"top_SoC bus writeMuxes_0 io_in_1_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4905,"top_SoC bus writeMuxes_0 io_in_1_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4913,"top_SoC bus writeMuxes_0 io_in_1_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1057,"top_SoC bus writeMuxes_0 io_in_1_writeData_ready", false,-1);
        vcdp->declBit(c+1065,"top_SoC bus writeMuxes_0 io_in_1_writeData_valid", false,-1);
        vcdp->declBus(c+1073,"top_SoC bus writeMuxes_0 io_in_1_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1081,"top_SoC bus writeMuxes_0 io_in_1_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1089,"top_SoC bus writeMuxes_0 io_in_1_writeData_bits_last", false,-1);
        vcdp->declBit(c+1097,"top_SoC bus writeMuxes_0 io_in_1_writeResp_ready", false,-1);
        vcdp->declBit(c+1105,"top_SoC bus writeMuxes_0 io_in_1_writeResp_valid", false,-1);
        vcdp->declBus(c+4921,"top_SoC bus writeMuxes_0 io_in_1_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4929,"top_SoC bus writeMuxes_0 io_in_1_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+5993,"top_SoC bus writeMuxes_0 arbiter_clock", false,-1);
        vcdp->declBit(c+1529,"top_SoC bus writeMuxes_0 arbiter_io_in_0_ready", false,-1);
        vcdp->declBit(c+1537,"top_SoC bus writeMuxes_0 arbiter_io_in_0_valid", false,-1);
        vcdp->declBit(c+1545,"top_SoC bus writeMuxes_0 arbiter_io_in_1_ready", false,-1);
        vcdp->declBit(c+1553,"top_SoC bus writeMuxes_0 arbiter_io_in_1_valid", false,-1);
        vcdp->declBit(c+1561,"top_SoC bus writeMuxes_0 arbiter_io_out_valid", false,-1);
        vcdp->declBit(c+1569,"top_SoC bus writeMuxes_0 arbiter_io_chosen", false,-1);
        vcdp->declBus(c+5529,"top_SoC bus writeMuxes_0 state", false,-1, 1,0);
        vcdp->declBit(c+1577,"top_SoC bus writeMuxes_0 outstanding", false,-1);
        vcdp->declBit(c+5537,"top_SoC bus writeMuxes_0 chosen_reg", false,-1);
        vcdp->declBit(c+3009,"top_SoC bus writeMuxes_0 w_determined", false,-1);
        vcdp->declBit(c+2977,"top_SoC bus writeMuxes_0 aw_determined", false,-1);
        vcdp->declBus(c+2985,"top_SoC bus writeMuxes_0 address_reg_id", false,-1, 3,0);
        vcdp->declBus(c+2993,"top_SoC bus writeMuxes_0 address_reg_addr", false,-1, 31,0);
        vcdp->declBus(c+3001,"top_SoC bus writeMuxes_0 address_reg_size", false,-1, 1,0);
        vcdp->declBus(c+3017,"top_SoC bus writeMuxes_0 data_reg_data", false,-1, 31,0);
        vcdp->declBus(c+3025,"top_SoC bus writeMuxes_0 data_reg_strb", false,-1, 3,0);
        vcdp->declBit(c+3033,"top_SoC bus writeMuxes_0 data_reg_last", false,-1);
        vcdp->declBus(c+5545,"top_SoC bus writeMuxes_0 resp_reg_id", false,-1, 3,0);
        vcdp->declBus(c+5553,"top_SoC bus writeMuxes_0 resp_reg_resp", false,-1, 1,0);
        vcdp->declBit(c+1585,"top_SoC bus writeMuxes_0 mask_0", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus writeMuxes_0 arbiter clock", false,-1);
        vcdp->declBit(c+1529,"top_SoC bus writeMuxes_0 arbiter io_in_0_ready", false,-1);
        vcdp->declBit(c+1537,"top_SoC bus writeMuxes_0 arbiter io_in_0_valid", false,-1);
        vcdp->declBit(c+1545,"top_SoC bus writeMuxes_0 arbiter io_in_1_ready", false,-1);
        vcdp->declBit(c+1553,"top_SoC bus writeMuxes_0 arbiter io_in_1_valid", false,-1);
        vcdp->declBit(c+1561,"top_SoC bus writeMuxes_0 arbiter io_out_valid", false,-1);
        vcdp->declBit(c+1569,"top_SoC bus writeMuxes_0 arbiter io_chosen", false,-1);
        vcdp->declBit(c+5561,"top_SoC bus writeMuxes_0 arbiter lastGrant", false,-1);
        vcdp->declBit(c+5569,"top_SoC bus writeMuxes_0 arbiter grantMask_1", false,-1);
        vcdp->declBit(c+1593,"top_SoC bus writeMuxes_0 arbiter validMask_1", false,-1);
        vcdp->declBit(c+1601,"top_SoC bus writeMuxes_0 arbiter ctrl_3", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus writeMuxes_1 clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus writeMuxes_1 reset", false,-1);
        vcdp->declBit(c+3665,"top_SoC bus writeMuxes_1 io_out_writeAddr_ready", false,-1);
        vcdp->declBit(c+3673,"top_SoC bus writeMuxes_1 io_out_writeAddr_valid", false,-1);
        vcdp->declBus(c+3681,"top_SoC bus writeMuxes_1 io_out_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3689,"top_SoC bus writeMuxes_1 io_out_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+5017,"top_SoC bus writeMuxes_1 io_out_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3697,"top_SoC bus writeMuxes_1 io_out_writeData_ready", false,-1);
        vcdp->declBit(c+3705,"top_SoC bus writeMuxes_1 io_out_writeData_valid", false,-1);
        vcdp->declBus(c+3713,"top_SoC bus writeMuxes_1 io_out_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3721,"top_SoC bus writeMuxes_1 io_out_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3729,"top_SoC bus writeMuxes_1 io_out_writeData_bits_last", false,-1);
        vcdp->declBit(c+217,"top_SoC bus writeMuxes_1 io_out_writeResp_ready", false,-1);
        vcdp->declBit(c+3737,"top_SoC bus writeMuxes_1 io_out_writeResp_valid", false,-1);
        vcdp->declBus(c+3745,"top_SoC bus writeMuxes_1 io_out_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+6481,"top_SoC bus writeMuxes_1 io_out_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+897,"top_SoC bus writeMuxes_1 io_in_0_writeAddr_ready", false,-1);
        vcdp->declBit(c+905,"top_SoC bus writeMuxes_1 io_in_0_writeAddr_valid", false,-1);
        vcdp->declBus(c+4817,"top_SoC bus writeMuxes_1 io_in_0_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4825,"top_SoC bus writeMuxes_1 io_in_0_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4833,"top_SoC bus writeMuxes_1 io_in_0_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+913,"top_SoC bus writeMuxes_1 io_in_0_writeData_ready", false,-1);
        vcdp->declBit(c+921,"top_SoC bus writeMuxes_1 io_in_0_writeData_valid", false,-1);
        vcdp->declBus(c+929,"top_SoC bus writeMuxes_1 io_in_0_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+937,"top_SoC bus writeMuxes_1 io_in_0_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+945,"top_SoC bus writeMuxes_1 io_in_0_writeData_bits_last", false,-1);
        vcdp->declBit(c+953,"top_SoC bus writeMuxes_1 io_in_0_writeResp_ready", false,-1);
        vcdp->declBit(c+961,"top_SoC bus writeMuxes_1 io_in_0_writeResp_valid", false,-1);
        vcdp->declBus(c+4841,"top_SoC bus writeMuxes_1 io_in_0_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4849,"top_SoC bus writeMuxes_1 io_in_0_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+1113,"top_SoC bus writeMuxes_1 io_in_1_writeAddr_ready", false,-1);
        vcdp->declBit(c+1121,"top_SoC bus writeMuxes_1 io_in_1_writeAddr_valid", false,-1);
        vcdp->declBus(c+4937,"top_SoC bus writeMuxes_1 io_in_1_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4945,"top_SoC bus writeMuxes_1 io_in_1_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4953,"top_SoC bus writeMuxes_1 io_in_1_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1129,"top_SoC bus writeMuxes_1 io_in_1_writeData_ready", false,-1);
        vcdp->declBit(c+1137,"top_SoC bus writeMuxes_1 io_in_1_writeData_valid", false,-1);
        vcdp->declBus(c+1145,"top_SoC bus writeMuxes_1 io_in_1_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1153,"top_SoC bus writeMuxes_1 io_in_1_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1161,"top_SoC bus writeMuxes_1 io_in_1_writeData_bits_last", false,-1);
        vcdp->declBit(c+1169,"top_SoC bus writeMuxes_1 io_in_1_writeResp_ready", false,-1);
        vcdp->declBit(c+1177,"top_SoC bus writeMuxes_1 io_in_1_writeResp_valid", false,-1);
        vcdp->declBus(c+4961,"top_SoC bus writeMuxes_1 io_in_1_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4969,"top_SoC bus writeMuxes_1 io_in_1_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+5993,"top_SoC bus writeMuxes_1 arbiter_clock", false,-1);
        vcdp->declBit(c+1609,"top_SoC bus writeMuxes_1 arbiter_io_in_0_ready", false,-1);
        vcdp->declBit(c+1617,"top_SoC bus writeMuxes_1 arbiter_io_in_0_valid", false,-1);
        vcdp->declBit(c+1625,"top_SoC bus writeMuxes_1 arbiter_io_in_1_ready", false,-1);
        vcdp->declBit(c+1633,"top_SoC bus writeMuxes_1 arbiter_io_in_1_valid", false,-1);
        vcdp->declBit(c+1641,"top_SoC bus writeMuxes_1 arbiter_io_out_valid", false,-1);
        vcdp->declBit(c+1649,"top_SoC bus writeMuxes_1 arbiter_io_chosen", false,-1);
        vcdp->declBus(c+5577,"top_SoC bus writeMuxes_1 state", false,-1, 1,0);
        vcdp->declBit(c+1657,"top_SoC bus writeMuxes_1 outstanding", false,-1);
        vcdp->declBit(c+5585,"top_SoC bus writeMuxes_1 chosen_reg", false,-1);
        vcdp->declBit(c+3705,"top_SoC bus writeMuxes_1 w_determined", false,-1);
        vcdp->declBit(c+3673,"top_SoC bus writeMuxes_1 aw_determined", false,-1);
        vcdp->declBus(c+3681,"top_SoC bus writeMuxes_1 address_reg_id", false,-1, 3,0);
        vcdp->declBus(c+3689,"top_SoC bus writeMuxes_1 address_reg_addr", false,-1, 31,0);
        vcdp->declBus(c+5017,"top_SoC bus writeMuxes_1 address_reg_size", false,-1, 1,0);
        vcdp->declBus(c+3713,"top_SoC bus writeMuxes_1 data_reg_data", false,-1, 31,0);
        vcdp->declBus(c+3721,"top_SoC bus writeMuxes_1 data_reg_strb", false,-1, 3,0);
        vcdp->declBit(c+3729,"top_SoC bus writeMuxes_1 data_reg_last", false,-1);
        vcdp->declBus(c+5593,"top_SoC bus writeMuxes_1 resp_reg_id", false,-1, 3,0);
        vcdp->declBus(c+5601,"top_SoC bus writeMuxes_1 resp_reg_resp", false,-1, 1,0);
        vcdp->declBit(c+1665,"top_SoC bus writeMuxes_1 mask_0", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus writeMuxes_1 arbiter clock", false,-1);
        vcdp->declBit(c+1609,"top_SoC bus writeMuxes_1 arbiter io_in_0_ready", false,-1);
        vcdp->declBit(c+1617,"top_SoC bus writeMuxes_1 arbiter io_in_0_valid", false,-1);
        vcdp->declBit(c+1625,"top_SoC bus writeMuxes_1 arbiter io_in_1_ready", false,-1);
        vcdp->declBit(c+1633,"top_SoC bus writeMuxes_1 arbiter io_in_1_valid", false,-1);
        vcdp->declBit(c+1641,"top_SoC bus writeMuxes_1 arbiter io_out_valid", false,-1);
        vcdp->declBit(c+1649,"top_SoC bus writeMuxes_1 arbiter io_chosen", false,-1);
        vcdp->declBit(c+5609,"top_SoC bus writeMuxes_1 arbiter lastGrant", false,-1);
        vcdp->declBit(c+5617,"top_SoC bus writeMuxes_1 arbiter grantMask_1", false,-1);
        vcdp->declBit(c+1673,"top_SoC bus writeMuxes_1 arbiter validMask_1", false,-1);
        vcdp->declBit(c+1681,"top_SoC bus writeMuxes_1 arbiter ctrl_3", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus writeMuxes_2 clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC bus writeMuxes_2 reset", false,-1);
        vcdp->declBit(c+3801,"top_SoC bus writeMuxes_2 io_out_writeAddr_ready", false,-1);
        vcdp->declBit(c+3809,"top_SoC bus writeMuxes_2 io_out_writeAddr_valid", false,-1);
        vcdp->declBus(c+3817,"top_SoC bus writeMuxes_2 io_out_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3825,"top_SoC bus writeMuxes_2 io_out_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+5025,"top_SoC bus writeMuxes_2 io_out_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+3833,"top_SoC bus writeMuxes_2 io_out_writeData_ready", false,-1);
        vcdp->declBit(c+3841,"top_SoC bus writeMuxes_2 io_out_writeData_valid", false,-1);
        vcdp->declBus(c+3849,"top_SoC bus writeMuxes_2 io_out_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3857,"top_SoC bus writeMuxes_2 io_out_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3865,"top_SoC bus writeMuxes_2 io_out_writeData_bits_last", false,-1);
        vcdp->declBit(c+249,"top_SoC bus writeMuxes_2 io_out_writeResp_ready", false,-1);
        vcdp->declBit(c+3873,"top_SoC bus writeMuxes_2 io_out_writeResp_valid", false,-1);
        vcdp->declBus(c+3881,"top_SoC bus writeMuxes_2 io_out_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+6481,"top_SoC bus writeMuxes_2 io_out_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+969,"top_SoC bus writeMuxes_2 io_in_0_writeAddr_ready", false,-1);
        vcdp->declBit(c+977,"top_SoC bus writeMuxes_2 io_in_0_writeAddr_valid", false,-1);
        vcdp->declBus(c+4857,"top_SoC bus writeMuxes_2 io_in_0_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4865,"top_SoC bus writeMuxes_2 io_in_0_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4873,"top_SoC bus writeMuxes_2 io_in_0_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+985,"top_SoC bus writeMuxes_2 io_in_0_writeData_ready", false,-1);
        vcdp->declBit(c+993,"top_SoC bus writeMuxes_2 io_in_0_writeData_valid", false,-1);
        vcdp->declBus(c+1001,"top_SoC bus writeMuxes_2 io_in_0_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1009,"top_SoC bus writeMuxes_2 io_in_0_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1017,"top_SoC bus writeMuxes_2 io_in_0_writeData_bits_last", false,-1);
        vcdp->declBit(c+1025,"top_SoC bus writeMuxes_2 io_in_0_writeResp_ready", false,-1);
        vcdp->declBit(c+1033,"top_SoC bus writeMuxes_2 io_in_0_writeResp_valid", false,-1);
        vcdp->declBus(c+4881,"top_SoC bus writeMuxes_2 io_in_0_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4889,"top_SoC bus writeMuxes_2 io_in_0_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+1185,"top_SoC bus writeMuxes_2 io_in_1_writeAddr_ready", false,-1);
        vcdp->declBit(c+1193,"top_SoC bus writeMuxes_2 io_in_1_writeAddr_valid", false,-1);
        vcdp->declBus(c+4977,"top_SoC bus writeMuxes_2 io_in_1_writeAddr_bits_id", false,-1, 3,0);
        vcdp->declBus(c+4985,"top_SoC bus writeMuxes_2 io_in_1_writeAddr_bits_addr", false,-1, 31,0);
        vcdp->declBus(c+4993,"top_SoC bus writeMuxes_2 io_in_1_writeAddr_bits_size", false,-1, 1,0);
        vcdp->declBit(c+1201,"top_SoC bus writeMuxes_2 io_in_1_writeData_ready", false,-1);
        vcdp->declBit(c+1209,"top_SoC bus writeMuxes_2 io_in_1_writeData_valid", false,-1);
        vcdp->declBus(c+1217,"top_SoC bus writeMuxes_2 io_in_1_writeData_bits_data", false,-1, 31,0);
        vcdp->declBus(c+1225,"top_SoC bus writeMuxes_2 io_in_1_writeData_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+1233,"top_SoC bus writeMuxes_2 io_in_1_writeData_bits_last", false,-1);
        vcdp->declBit(c+1241,"top_SoC bus writeMuxes_2 io_in_1_writeResp_ready", false,-1);
        vcdp->declBit(c+1249,"top_SoC bus writeMuxes_2 io_in_1_writeResp_valid", false,-1);
        vcdp->declBus(c+5001,"top_SoC bus writeMuxes_2 io_in_1_writeResp_bits_id", false,-1, 3,0);
        vcdp->declBus(c+5009,"top_SoC bus writeMuxes_2 io_in_1_writeResp_bits_resp", false,-1, 1,0);
        vcdp->declBit(c+5993,"top_SoC bus writeMuxes_2 arbiter_clock", false,-1);
        vcdp->declBit(c+1689,"top_SoC bus writeMuxes_2 arbiter_io_in_0_ready", false,-1);
        vcdp->declBit(c+1697,"top_SoC bus writeMuxes_2 arbiter_io_in_0_valid", false,-1);
        vcdp->declBit(c+1705,"top_SoC bus writeMuxes_2 arbiter_io_in_1_ready", false,-1);
        vcdp->declBit(c+1713,"top_SoC bus writeMuxes_2 arbiter_io_in_1_valid", false,-1);
        vcdp->declBit(c+1721,"top_SoC bus writeMuxes_2 arbiter_io_out_valid", false,-1);
        vcdp->declBit(c+1729,"top_SoC bus writeMuxes_2 arbiter_io_chosen", false,-1);
        vcdp->declBus(c+5625,"top_SoC bus writeMuxes_2 state", false,-1, 1,0);
        vcdp->declBit(c+1737,"top_SoC bus writeMuxes_2 outstanding", false,-1);
        vcdp->declBit(c+5633,"top_SoC bus writeMuxes_2 chosen_reg", false,-1);
        vcdp->declBit(c+3841,"top_SoC bus writeMuxes_2 w_determined", false,-1);
        vcdp->declBit(c+3809,"top_SoC bus writeMuxes_2 aw_determined", false,-1);
        vcdp->declBus(c+3817,"top_SoC bus writeMuxes_2 address_reg_id", false,-1, 3,0);
        vcdp->declBus(c+3825,"top_SoC bus writeMuxes_2 address_reg_addr", false,-1, 31,0);
        vcdp->declBus(c+5025,"top_SoC bus writeMuxes_2 address_reg_size", false,-1, 1,0);
        vcdp->declBus(c+3849,"top_SoC bus writeMuxes_2 data_reg_data", false,-1, 31,0);
        vcdp->declBus(c+3857,"top_SoC bus writeMuxes_2 data_reg_strb", false,-1, 3,0);
        vcdp->declBit(c+3865,"top_SoC bus writeMuxes_2 data_reg_last", false,-1);
        vcdp->declBus(c+5641,"top_SoC bus writeMuxes_2 resp_reg_id", false,-1, 3,0);
        vcdp->declBus(c+5649,"top_SoC bus writeMuxes_2 resp_reg_resp", false,-1, 1,0);
        vcdp->declBit(c+1745,"top_SoC bus writeMuxes_2 mask_0", false,-1);
        vcdp->declBit(c+5993,"top_SoC bus writeMuxes_2 arbiter clock", false,-1);
        vcdp->declBit(c+1689,"top_SoC bus writeMuxes_2 arbiter io_in_0_ready", false,-1);
        vcdp->declBit(c+1697,"top_SoC bus writeMuxes_2 arbiter io_in_0_valid", false,-1);
        vcdp->declBit(c+1705,"top_SoC bus writeMuxes_2 arbiter io_in_1_ready", false,-1);
        vcdp->declBit(c+1713,"top_SoC bus writeMuxes_2 arbiter io_in_1_valid", false,-1);
        vcdp->declBit(c+1721,"top_SoC bus writeMuxes_2 arbiter io_out_valid", false,-1);
        vcdp->declBit(c+1729,"top_SoC bus writeMuxes_2 arbiter io_chosen", false,-1);
        vcdp->declBit(c+5657,"top_SoC bus writeMuxes_2 arbiter lastGrant", false,-1);
        vcdp->declBit(c+5665,"top_SoC bus writeMuxes_2 arbiter grantMask_1", false,-1);
        vcdp->declBit(c+1753,"top_SoC bus writeMuxes_2 arbiter validMask_1", false,-1);
        vcdp->declBit(c+1761,"top_SoC bus writeMuxes_2 arbiter ctrl_3", false,-1);
        vcdp->declBit(c+5993,"top_SoC localMem clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC localMem reset", false,-1);
        vcdp->declBit(c+3665,"top_SoC localMem io_slave_aw_ready", false,-1);
        vcdp->declBit(c+3673,"top_SoC localMem io_slave_aw_valid", false,-1);
        vcdp->declBus(c+3681,"top_SoC localMem io_slave_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3689,"top_SoC localMem io_slave_aw_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+3697,"top_SoC localMem io_slave_w_ready", false,-1);
        vcdp->declBit(c+3705,"top_SoC localMem io_slave_w_valid", false,-1);
        vcdp->declBus(c+3713,"top_SoC localMem io_slave_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3721,"top_SoC localMem io_slave_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3729,"top_SoC localMem io_slave_w_bits_last", false,-1);
        vcdp->declBit(c+217,"top_SoC localMem io_slave_b_ready", false,-1);
        vcdp->declBit(c+3737,"top_SoC localMem io_slave_b_valid", false,-1);
        vcdp->declBus(c+3745,"top_SoC localMem io_slave_b_bits_id", false,-1, 3,0);
        vcdp->declBit(c+3753,"top_SoC localMem io_slave_ar_ready", false,-1);
        vcdp->declBit(c+3761,"top_SoC localMem io_slave_ar_valid", false,-1);
        vcdp->declBus(c+3769,"top_SoC localMem io_slave_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3777,"top_SoC localMem io_slave_ar_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+225,"top_SoC localMem io_slave_r_ready", false,-1);
        vcdp->declBit(c+233,"top_SoC localMem io_slave_r_valid", false,-1);
        vcdp->declBus(c+3785,"top_SoC localMem io_slave_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+241,"top_SoC localMem io_slave_r_bits_data", false,-1, 31,0);
        vcdp->declBit(c+3793,"top_SoC localMem io_slave_r_bits_last", false,-1);
        vcdp->declBit(c+6297,"top_SoC localMem io_dump", false,-1);
        vcdp->declBit(c+1769,"top_SoC localMem memory_io_slave_r_bits_data_MPORT_en", false,-1);
        vcdp->declBus(c+5673,"top_SoC localMem memory_io_slave_r_bits_data_MPORT_addr", false,-1, 5,0);
        vcdp->declBus(c+1777,"top_SoC localMem memory_io_slave_r_bits_data_MPORT_data", false,-1, 31,0);
        vcdp->declBit(c+5681,"top_SoC localMem memory_writeData_0_MPORT_en", false,-1);
        vcdp->declBus(c+5689,"top_SoC localMem memory_writeData_0_MPORT_addr", false,-1, 5,0);
        vcdp->declBus(c+1785,"top_SoC localMem memory_writeData_0_MPORT_data", false,-1, 31,0);
        vcdp->declBit(c+5697,"top_SoC localMem memory_writeData_1_MPORT_en", false,-1);
        vcdp->declBus(c+5689,"top_SoC localMem memory_writeData_1_MPORT_addr", false,-1, 5,0);
        vcdp->declBus(c+1785,"top_SoC localMem memory_writeData_1_MPORT_data", false,-1, 31,0);
        vcdp->declBit(c+5705,"top_SoC localMem memory_writeData_2_MPORT_en", false,-1);
        vcdp->declBus(c+5689,"top_SoC localMem memory_writeData_2_MPORT_addr", false,-1, 5,0);
        vcdp->declBus(c+1785,"top_SoC localMem memory_writeData_2_MPORT_data", false,-1, 31,0);
        vcdp->declBit(c+5713,"top_SoC localMem memory_writeData_3_MPORT_en", false,-1);
        vcdp->declBus(c+5689,"top_SoC localMem memory_writeData_3_MPORT_addr", false,-1, 5,0);
        vcdp->declBus(c+1785,"top_SoC localMem memory_writeData_3_MPORT_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_en", false,-1);
        vcdp->declBus(c+6521,"top_SoC localMem memory_data_MPORT_addr", false,-1, 5,0);
        vcdp->declBus(c+1793,"top_SoC localMem memory_data_MPORT_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_1_en", false,-1);
        vcdp->declBus(c+6529,"top_SoC localMem memory_data_MPORT_1_addr", false,-1, 5,0);
        vcdp->declBus(c+1801,"top_SoC localMem memory_data_MPORT_1_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_2_en", false,-1);
        vcdp->declBus(c+6537,"top_SoC localMem memory_data_MPORT_2_addr", false,-1, 5,0);
        vcdp->declBus(c+1809,"top_SoC localMem memory_data_MPORT_2_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_3_en", false,-1);
        vcdp->declBus(c+6545,"top_SoC localMem memory_data_MPORT_3_addr", false,-1, 5,0);
        vcdp->declBus(c+1817,"top_SoC localMem memory_data_MPORT_3_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_4_en", false,-1);
        vcdp->declBus(c+6553,"top_SoC localMem memory_data_MPORT_4_addr", false,-1, 5,0);
        vcdp->declBus(c+1825,"top_SoC localMem memory_data_MPORT_4_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_5_en", false,-1);
        vcdp->declBus(c+6561,"top_SoC localMem memory_data_MPORT_5_addr", false,-1, 5,0);
        vcdp->declBus(c+1833,"top_SoC localMem memory_data_MPORT_5_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_6_en", false,-1);
        vcdp->declBus(c+6569,"top_SoC localMem memory_data_MPORT_6_addr", false,-1, 5,0);
        vcdp->declBus(c+1841,"top_SoC localMem memory_data_MPORT_6_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_7_en", false,-1);
        vcdp->declBus(c+6577,"top_SoC localMem memory_data_MPORT_7_addr", false,-1, 5,0);
        vcdp->declBus(c+1849,"top_SoC localMem memory_data_MPORT_7_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_8_en", false,-1);
        vcdp->declBus(c+6585,"top_SoC localMem memory_data_MPORT_8_addr", false,-1, 5,0);
        vcdp->declBus(c+1857,"top_SoC localMem memory_data_MPORT_8_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_9_en", false,-1);
        vcdp->declBus(c+6593,"top_SoC localMem memory_data_MPORT_9_addr", false,-1, 5,0);
        vcdp->declBus(c+1865,"top_SoC localMem memory_data_MPORT_9_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_10_en", false,-1);
        vcdp->declBus(c+6601,"top_SoC localMem memory_data_MPORT_10_addr", false,-1, 5,0);
        vcdp->declBus(c+1873,"top_SoC localMem memory_data_MPORT_10_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_11_en", false,-1);
        vcdp->declBus(c+6609,"top_SoC localMem memory_data_MPORT_11_addr", false,-1, 5,0);
        vcdp->declBus(c+1881,"top_SoC localMem memory_data_MPORT_11_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_12_en", false,-1);
        vcdp->declBus(c+6617,"top_SoC localMem memory_data_MPORT_12_addr", false,-1, 5,0);
        vcdp->declBus(c+1889,"top_SoC localMem memory_data_MPORT_12_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_13_en", false,-1);
        vcdp->declBus(c+6625,"top_SoC localMem memory_data_MPORT_13_addr", false,-1, 5,0);
        vcdp->declBus(c+1897,"top_SoC localMem memory_data_MPORT_13_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_14_en", false,-1);
        vcdp->declBus(c+6633,"top_SoC localMem memory_data_MPORT_14_addr", false,-1, 5,0);
        vcdp->declBus(c+1905,"top_SoC localMem memory_data_MPORT_14_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_15_en", false,-1);
        vcdp->declBus(c+6641,"top_SoC localMem memory_data_MPORT_15_addr", false,-1, 5,0);
        vcdp->declBus(c+1913,"top_SoC localMem memory_data_MPORT_15_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_16_en", false,-1);
        vcdp->declBus(c+6649,"top_SoC localMem memory_data_MPORT_16_addr", false,-1, 5,0);
        vcdp->declBus(c+1921,"top_SoC localMem memory_data_MPORT_16_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_17_en", false,-1);
        vcdp->declBus(c+6657,"top_SoC localMem memory_data_MPORT_17_addr", false,-1, 5,0);
        vcdp->declBus(c+1929,"top_SoC localMem memory_data_MPORT_17_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_18_en", false,-1);
        vcdp->declBus(c+6665,"top_SoC localMem memory_data_MPORT_18_addr", false,-1, 5,0);
        vcdp->declBus(c+1937,"top_SoC localMem memory_data_MPORT_18_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_19_en", false,-1);
        vcdp->declBus(c+6673,"top_SoC localMem memory_data_MPORT_19_addr", false,-1, 5,0);
        vcdp->declBus(c+1945,"top_SoC localMem memory_data_MPORT_19_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_20_en", false,-1);
        vcdp->declBus(c+6681,"top_SoC localMem memory_data_MPORT_20_addr", false,-1, 5,0);
        vcdp->declBus(c+1953,"top_SoC localMem memory_data_MPORT_20_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_21_en", false,-1);
        vcdp->declBus(c+6689,"top_SoC localMem memory_data_MPORT_21_addr", false,-1, 5,0);
        vcdp->declBus(c+1961,"top_SoC localMem memory_data_MPORT_21_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_22_en", false,-1);
        vcdp->declBus(c+6697,"top_SoC localMem memory_data_MPORT_22_addr", false,-1, 5,0);
        vcdp->declBus(c+1969,"top_SoC localMem memory_data_MPORT_22_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_23_en", false,-1);
        vcdp->declBus(c+6705,"top_SoC localMem memory_data_MPORT_23_addr", false,-1, 5,0);
        vcdp->declBus(c+1977,"top_SoC localMem memory_data_MPORT_23_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_24_en", false,-1);
        vcdp->declBus(c+6713,"top_SoC localMem memory_data_MPORT_24_addr", false,-1, 5,0);
        vcdp->declBus(c+1985,"top_SoC localMem memory_data_MPORT_24_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_25_en", false,-1);
        vcdp->declBus(c+6721,"top_SoC localMem memory_data_MPORT_25_addr", false,-1, 5,0);
        vcdp->declBus(c+1993,"top_SoC localMem memory_data_MPORT_25_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_26_en", false,-1);
        vcdp->declBus(c+6729,"top_SoC localMem memory_data_MPORT_26_addr", false,-1, 5,0);
        vcdp->declBus(c+2001,"top_SoC localMem memory_data_MPORT_26_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_27_en", false,-1);
        vcdp->declBus(c+6737,"top_SoC localMem memory_data_MPORT_27_addr", false,-1, 5,0);
        vcdp->declBus(c+2009,"top_SoC localMem memory_data_MPORT_27_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_28_en", false,-1);
        vcdp->declBus(c+6745,"top_SoC localMem memory_data_MPORT_28_addr", false,-1, 5,0);
        vcdp->declBus(c+2017,"top_SoC localMem memory_data_MPORT_28_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_29_en", false,-1);
        vcdp->declBus(c+6753,"top_SoC localMem memory_data_MPORT_29_addr", false,-1, 5,0);
        vcdp->declBus(c+2025,"top_SoC localMem memory_data_MPORT_29_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_30_en", false,-1);
        vcdp->declBus(c+6761,"top_SoC localMem memory_data_MPORT_30_addr", false,-1, 5,0);
        vcdp->declBus(c+2033,"top_SoC localMem memory_data_MPORT_30_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_31_en", false,-1);
        vcdp->declBus(c+6769,"top_SoC localMem memory_data_MPORT_31_addr", false,-1, 5,0);
        vcdp->declBus(c+2041,"top_SoC localMem memory_data_MPORT_31_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_32_en", false,-1);
        vcdp->declBus(c+6777,"top_SoC localMem memory_data_MPORT_32_addr", false,-1, 5,0);
        vcdp->declBus(c+2049,"top_SoC localMem memory_data_MPORT_32_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_33_en", false,-1);
        vcdp->declBus(c+6785,"top_SoC localMem memory_data_MPORT_33_addr", false,-1, 5,0);
        vcdp->declBus(c+2057,"top_SoC localMem memory_data_MPORT_33_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_34_en", false,-1);
        vcdp->declBus(c+6793,"top_SoC localMem memory_data_MPORT_34_addr", false,-1, 5,0);
        vcdp->declBus(c+2065,"top_SoC localMem memory_data_MPORT_34_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_35_en", false,-1);
        vcdp->declBus(c+6801,"top_SoC localMem memory_data_MPORT_35_addr", false,-1, 5,0);
        vcdp->declBus(c+2073,"top_SoC localMem memory_data_MPORT_35_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_36_en", false,-1);
        vcdp->declBus(c+6809,"top_SoC localMem memory_data_MPORT_36_addr", false,-1, 5,0);
        vcdp->declBus(c+2081,"top_SoC localMem memory_data_MPORT_36_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_37_en", false,-1);
        vcdp->declBus(c+6817,"top_SoC localMem memory_data_MPORT_37_addr", false,-1, 5,0);
        vcdp->declBus(c+2089,"top_SoC localMem memory_data_MPORT_37_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_38_en", false,-1);
        vcdp->declBus(c+6825,"top_SoC localMem memory_data_MPORT_38_addr", false,-1, 5,0);
        vcdp->declBus(c+2097,"top_SoC localMem memory_data_MPORT_38_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_39_en", false,-1);
        vcdp->declBus(c+6833,"top_SoC localMem memory_data_MPORT_39_addr", false,-1, 5,0);
        vcdp->declBus(c+2105,"top_SoC localMem memory_data_MPORT_39_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_40_en", false,-1);
        vcdp->declBus(c+6841,"top_SoC localMem memory_data_MPORT_40_addr", false,-1, 5,0);
        vcdp->declBus(c+2113,"top_SoC localMem memory_data_MPORT_40_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_41_en", false,-1);
        vcdp->declBus(c+6849,"top_SoC localMem memory_data_MPORT_41_addr", false,-1, 5,0);
        vcdp->declBus(c+2121,"top_SoC localMem memory_data_MPORT_41_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_42_en", false,-1);
        vcdp->declBus(c+6857,"top_SoC localMem memory_data_MPORT_42_addr", false,-1, 5,0);
        vcdp->declBus(c+2129,"top_SoC localMem memory_data_MPORT_42_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_43_en", false,-1);
        vcdp->declBus(c+6865,"top_SoC localMem memory_data_MPORT_43_addr", false,-1, 5,0);
        vcdp->declBus(c+2137,"top_SoC localMem memory_data_MPORT_43_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_44_en", false,-1);
        vcdp->declBus(c+6873,"top_SoC localMem memory_data_MPORT_44_addr", false,-1, 5,0);
        vcdp->declBus(c+2145,"top_SoC localMem memory_data_MPORT_44_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_45_en", false,-1);
        vcdp->declBus(c+6881,"top_SoC localMem memory_data_MPORT_45_addr", false,-1, 5,0);
        vcdp->declBus(c+2153,"top_SoC localMem memory_data_MPORT_45_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_46_en", false,-1);
        vcdp->declBus(c+6889,"top_SoC localMem memory_data_MPORT_46_addr", false,-1, 5,0);
        vcdp->declBus(c+2161,"top_SoC localMem memory_data_MPORT_46_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_47_en", false,-1);
        vcdp->declBus(c+6897,"top_SoC localMem memory_data_MPORT_47_addr", false,-1, 5,0);
        vcdp->declBus(c+2169,"top_SoC localMem memory_data_MPORT_47_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_48_en", false,-1);
        vcdp->declBus(c+6905,"top_SoC localMem memory_data_MPORT_48_addr", false,-1, 5,0);
        vcdp->declBus(c+2177,"top_SoC localMem memory_data_MPORT_48_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_49_en", false,-1);
        vcdp->declBus(c+6913,"top_SoC localMem memory_data_MPORT_49_addr", false,-1, 5,0);
        vcdp->declBus(c+2185,"top_SoC localMem memory_data_MPORT_49_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_50_en", false,-1);
        vcdp->declBus(c+6921,"top_SoC localMem memory_data_MPORT_50_addr", false,-1, 5,0);
        vcdp->declBus(c+2193,"top_SoC localMem memory_data_MPORT_50_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_51_en", false,-1);
        vcdp->declBus(c+6929,"top_SoC localMem memory_data_MPORT_51_addr", false,-1, 5,0);
        vcdp->declBus(c+2201,"top_SoC localMem memory_data_MPORT_51_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_52_en", false,-1);
        vcdp->declBus(c+6937,"top_SoC localMem memory_data_MPORT_52_addr", false,-1, 5,0);
        vcdp->declBus(c+2209,"top_SoC localMem memory_data_MPORT_52_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_53_en", false,-1);
        vcdp->declBus(c+6945,"top_SoC localMem memory_data_MPORT_53_addr", false,-1, 5,0);
        vcdp->declBus(c+2217,"top_SoC localMem memory_data_MPORT_53_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_54_en", false,-1);
        vcdp->declBus(c+6953,"top_SoC localMem memory_data_MPORT_54_addr", false,-1, 5,0);
        vcdp->declBus(c+2225,"top_SoC localMem memory_data_MPORT_54_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_55_en", false,-1);
        vcdp->declBus(c+6961,"top_SoC localMem memory_data_MPORT_55_addr", false,-1, 5,0);
        vcdp->declBus(c+2233,"top_SoC localMem memory_data_MPORT_55_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_56_en", false,-1);
        vcdp->declBus(c+6969,"top_SoC localMem memory_data_MPORT_56_addr", false,-1, 5,0);
        vcdp->declBus(c+2241,"top_SoC localMem memory_data_MPORT_56_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_57_en", false,-1);
        vcdp->declBus(c+6977,"top_SoC localMem memory_data_MPORT_57_addr", false,-1, 5,0);
        vcdp->declBus(c+2249,"top_SoC localMem memory_data_MPORT_57_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_58_en", false,-1);
        vcdp->declBus(c+6985,"top_SoC localMem memory_data_MPORT_58_addr", false,-1, 5,0);
        vcdp->declBus(c+2257,"top_SoC localMem memory_data_MPORT_58_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_59_en", false,-1);
        vcdp->declBus(c+6993,"top_SoC localMem memory_data_MPORT_59_addr", false,-1, 5,0);
        vcdp->declBus(c+2265,"top_SoC localMem memory_data_MPORT_59_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_60_en", false,-1);
        vcdp->declBus(c+7001,"top_SoC localMem memory_data_MPORT_60_addr", false,-1, 5,0);
        vcdp->declBus(c+2273,"top_SoC localMem memory_data_MPORT_60_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_61_en", false,-1);
        vcdp->declBus(c+7009,"top_SoC localMem memory_data_MPORT_61_addr", false,-1, 5,0);
        vcdp->declBus(c+2281,"top_SoC localMem memory_data_MPORT_61_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_62_en", false,-1);
        vcdp->declBus(c+7017,"top_SoC localMem memory_data_MPORT_62_addr", false,-1, 5,0);
        vcdp->declBus(c+2289,"top_SoC localMem memory_data_MPORT_62_data", false,-1, 31,0);
        vcdp->declBit(c+6297,"top_SoC localMem memory_data_MPORT_63_en", false,-1);
        vcdp->declBus(c+7025,"top_SoC localMem memory_data_MPORT_63_addr", false,-1, 5,0);
        vcdp->declBus(c+2297,"top_SoC localMem memory_data_MPORT_63_data", false,-1, 31,0);
        vcdp->declBus(c+2305,"top_SoC localMem memory_MPORT_data", false,-1, 31,0);
        vcdp->declBus(c+5689,"top_SoC localMem memory_MPORT_addr", false,-1, 5,0);
        vcdp->declBit(c+6505,"top_SoC localMem memory_MPORT_mask", false,-1);
        vcdp->declBit(c+5721,"top_SoC localMem memory_MPORT_en", false,-1);
        vcdp->declBus(c+2305,"top_SoC localMem memory_MPORT_1_data", false,-1, 31,0);
        vcdp->declBus(c+5729,"top_SoC localMem memory_MPORT_1_addr", false,-1, 5,0);
        vcdp->declBit(c+6505,"top_SoC localMem memory_MPORT_1_mask", false,-1);
        vcdp->declBit(c+5737,"top_SoC localMem memory_MPORT_1_en", false,-1);
        vcdp->declBus(c+5745,"top_SoC localMem readID", false,-1, 3,0);
        vcdp->declBus(c+5753,"top_SoC localMem rAddrOffset", false,-1, 31,0);
        vcdp->declBus(c+5761,"top_SoC localMem wAddrOffset", false,-1, 31,0);
        vcdp->declBus(c+5769,"top_SoC localMem writeAddressReg", false,-1, 31,0);
        vcdp->declBus(c+5777,"top_SoC localMem writeID", false,-1, 3,0);
        vcdp->declBus(c+5785,"top_SoC localMem writeState", false,-1, 2,0);
        vcdp->declBus(c+5793,"top_SoC localMem readState", false,-1, 1,0);
        vcdp->declBus(c+5801,"top_SoC localMem rLatencyCounter", false,-1, 7,0);
        vcdp->declBus(c+5809,"top_SoC localMem wLatencyCounter", false,-1, 7,0);
        vcdp->declBus(c+5817,"top_SoC localMem rlength", false,-1, 3,0);
        vcdp->declBus(c+5825,"top_SoC localMem rburst_counter", false,-1, 3,0);
        vcdp->declBit(c+2313,"top_SoC localMem readLast", false,-1);
        vcdp->declBus(c+2321,"top_SoC localMem writeData_0", false,-1, 7,0);
        vcdp->declBus(c+2329,"top_SoC localMem writeData_1", false,-1, 7,0);
        vcdp->declBus(c+2337,"top_SoC localMem writeData_2", false,-1, 7,0);
        vcdp->declBus(c+2345,"top_SoC localMem writeData_3", false,-1, 7,0);
        vcdp->declBus(c+2353,"top_SoC localMem lo", false,-1, 15,0);
        vcdp->declBus(c+2361,"top_SoC localMem hi", false,-1, 15,0);
        vcdp->declBus(c+7033,"top_SoC localMem initvar", false,-1, 31,0);
        vcdp->declBit(c+5993,"top_SoC globalMem clock", false,-1);
        vcdp->declBit(c+6001,"top_SoC globalMem reset", false,-1);
        vcdp->declBit(c+3801,"top_SoC globalMem io_slave_aw_ready", false,-1);
        vcdp->declBit(c+3809,"top_SoC globalMem io_slave_aw_valid", false,-1);
        vcdp->declBus(c+3817,"top_SoC globalMem io_slave_aw_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3825,"top_SoC globalMem io_slave_aw_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+3833,"top_SoC globalMem io_slave_w_ready", false,-1);
        vcdp->declBit(c+3841,"top_SoC globalMem io_slave_w_valid", false,-1);
        vcdp->declBus(c+3849,"top_SoC globalMem io_slave_w_bits_data", false,-1, 31,0);
        vcdp->declBus(c+3857,"top_SoC globalMem io_slave_w_bits_strb", false,-1, 3,0);
        vcdp->declBit(c+3865,"top_SoC globalMem io_slave_w_bits_last", false,-1);
        vcdp->declBit(c+249,"top_SoC globalMem io_slave_b_ready", false,-1);
        vcdp->declBit(c+3873,"top_SoC globalMem io_slave_b_valid", false,-1);
        vcdp->declBus(c+3881,"top_SoC globalMem io_slave_b_bits_id", false,-1, 3,0);
        vcdp->declBit(c+3889,"top_SoC globalMem io_slave_ar_ready", false,-1);
        vcdp->declBit(c+3897,"top_SoC globalMem io_slave_ar_valid", false,-1);
        vcdp->declBus(c+3905,"top_SoC globalMem io_slave_ar_bits_id", false,-1, 3,0);
        vcdp->declBus(c+3913,"top_SoC globalMem io_slave_ar_bits_addr", false,-1, 31,0);
        vcdp->declBit(c+257,"top_SoC globalMem io_slave_r_ready", false,-1);
        vcdp->declBit(c+265,"top_SoC globalMem io_slave_r_valid", false,-1);
        vcdp->declBus(c+3921,"top_SoC globalMem io_slave_r_bits_id", false,-1, 3,0);
        vcdp->declBus(c+273,"top_SoC globalMem io_slave_r_bits_data", false,-1, 31,0);
        vcdp->declBit(c+3929,"top_SoC globalMem io_slave_r_bits_last", false,-1);
        vcdp->declBit(c+2369,"top_SoC globalMem memory_io_slave_r_bits_data_MPORT_en", false,-1);
        vcdp->declBus(c+5833,"top_SoC globalMem memory_io_slave_r_bits_data_MPORT_addr", false,-1, 5,0);
        vcdp->declBus(c+2377,"top_SoC globalMem memory_io_slave_r_bits_data_MPORT_data", false,-1, 31,0);
        vcdp->declBit(c+5841,"top_SoC globalMem memory_writeData_0_MPORT_en", false,-1);
        vcdp->declBus(c+5849,"top_SoC globalMem memory_writeData_0_MPORT_addr", false,-1, 5,0);
        vcdp->declBus(c+2385,"top_SoC globalMem memory_writeData_0_MPORT_data", false,-1, 31,0);
        vcdp->declBit(c+5857,"top_SoC globalMem memory_writeData_1_MPORT_en", false,-1);
        vcdp->declBus(c+5849,"top_SoC globalMem memory_writeData_1_MPORT_addr", false,-1, 5,0);
        vcdp->declBus(c+2385,"top_SoC globalMem memory_writeData_1_MPORT_data", false,-1, 31,0);
        vcdp->declBit(c+5865,"top_SoC globalMem memory_writeData_2_MPORT_en", false,-1);
        vcdp->declBus(c+5849,"top_SoC globalMem memory_writeData_2_MPORT_addr", false,-1, 5,0);
        vcdp->declBus(c+2385,"top_SoC globalMem memory_writeData_2_MPORT_data", false,-1, 31,0);
        vcdp->declBit(c+5873,"top_SoC globalMem memory_writeData_3_MPORT_en", false,-1);
        vcdp->declBus(c+5849,"top_SoC globalMem memory_writeData_3_MPORT_addr", false,-1, 5,0);
        vcdp->declBus(c+2385,"top_SoC globalMem memory_writeData_3_MPORT_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_en", false,-1);
        vcdp->declBus(c+6521,"top_SoC globalMem memory_data_MPORT_addr", false,-1, 5,0);
        vcdp->declBus(c+2393,"top_SoC globalMem memory_data_MPORT_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_1_en", false,-1);
        vcdp->declBus(c+6529,"top_SoC globalMem memory_data_MPORT_1_addr", false,-1, 5,0);
        vcdp->declBus(c+2401,"top_SoC globalMem memory_data_MPORT_1_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_2_en", false,-1);
        vcdp->declBus(c+6537,"top_SoC globalMem memory_data_MPORT_2_addr", false,-1, 5,0);
        vcdp->declBus(c+2409,"top_SoC globalMem memory_data_MPORT_2_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_3_en", false,-1);
        vcdp->declBus(c+6545,"top_SoC globalMem memory_data_MPORT_3_addr", false,-1, 5,0);
        vcdp->declBus(c+2417,"top_SoC globalMem memory_data_MPORT_3_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_4_en", false,-1);
        vcdp->declBus(c+6553,"top_SoC globalMem memory_data_MPORT_4_addr", false,-1, 5,0);
        vcdp->declBus(c+2425,"top_SoC globalMem memory_data_MPORT_4_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_5_en", false,-1);
        vcdp->declBus(c+6561,"top_SoC globalMem memory_data_MPORT_5_addr", false,-1, 5,0);
        vcdp->declBus(c+2433,"top_SoC globalMem memory_data_MPORT_5_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_6_en", false,-1);
        vcdp->declBus(c+6569,"top_SoC globalMem memory_data_MPORT_6_addr", false,-1, 5,0);
        vcdp->declBus(c+2441,"top_SoC globalMem memory_data_MPORT_6_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_7_en", false,-1);
        vcdp->declBus(c+6577,"top_SoC globalMem memory_data_MPORT_7_addr", false,-1, 5,0);
        vcdp->declBus(c+2449,"top_SoC globalMem memory_data_MPORT_7_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_8_en", false,-1);
        vcdp->declBus(c+6585,"top_SoC globalMem memory_data_MPORT_8_addr", false,-1, 5,0);
        vcdp->declBus(c+2457,"top_SoC globalMem memory_data_MPORT_8_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_9_en", false,-1);
        vcdp->declBus(c+6593,"top_SoC globalMem memory_data_MPORT_9_addr", false,-1, 5,0);
        vcdp->declBus(c+2465,"top_SoC globalMem memory_data_MPORT_9_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_10_en", false,-1);
        vcdp->declBus(c+6601,"top_SoC globalMem memory_data_MPORT_10_addr", false,-1, 5,0);
        vcdp->declBus(c+2473,"top_SoC globalMem memory_data_MPORT_10_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_11_en", false,-1);
        vcdp->declBus(c+6609,"top_SoC globalMem memory_data_MPORT_11_addr", false,-1, 5,0);
        vcdp->declBus(c+2481,"top_SoC globalMem memory_data_MPORT_11_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_12_en", false,-1);
        vcdp->declBus(c+6617,"top_SoC globalMem memory_data_MPORT_12_addr", false,-1, 5,0);
        vcdp->declBus(c+2489,"top_SoC globalMem memory_data_MPORT_12_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_13_en", false,-1);
        vcdp->declBus(c+6625,"top_SoC globalMem memory_data_MPORT_13_addr", false,-1, 5,0);
        vcdp->declBus(c+2497,"top_SoC globalMem memory_data_MPORT_13_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_14_en", false,-1);
        vcdp->declBus(c+6633,"top_SoC globalMem memory_data_MPORT_14_addr", false,-1, 5,0);
        vcdp->declBus(c+2505,"top_SoC globalMem memory_data_MPORT_14_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_15_en", false,-1);
        vcdp->declBus(c+6641,"top_SoC globalMem memory_data_MPORT_15_addr", false,-1, 5,0);
        vcdp->declBus(c+2513,"top_SoC globalMem memory_data_MPORT_15_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_16_en", false,-1);
        vcdp->declBus(c+6649,"top_SoC globalMem memory_data_MPORT_16_addr", false,-1, 5,0);
        vcdp->declBus(c+2521,"top_SoC globalMem memory_data_MPORT_16_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_17_en", false,-1);
        vcdp->declBus(c+6657,"top_SoC globalMem memory_data_MPORT_17_addr", false,-1, 5,0);
        vcdp->declBus(c+2529,"top_SoC globalMem memory_data_MPORT_17_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_18_en", false,-1);
        vcdp->declBus(c+6665,"top_SoC globalMem memory_data_MPORT_18_addr", false,-1, 5,0);
        vcdp->declBus(c+2537,"top_SoC globalMem memory_data_MPORT_18_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_19_en", false,-1);
        vcdp->declBus(c+6673,"top_SoC globalMem memory_data_MPORT_19_addr", false,-1, 5,0);
        vcdp->declBus(c+2545,"top_SoC globalMem memory_data_MPORT_19_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_20_en", false,-1);
        vcdp->declBus(c+6681,"top_SoC globalMem memory_data_MPORT_20_addr", false,-1, 5,0);
        vcdp->declBus(c+2553,"top_SoC globalMem memory_data_MPORT_20_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_21_en", false,-1);
        vcdp->declBus(c+6689,"top_SoC globalMem memory_data_MPORT_21_addr", false,-1, 5,0);
        vcdp->declBus(c+2561,"top_SoC globalMem memory_data_MPORT_21_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_22_en", false,-1);
        vcdp->declBus(c+6697,"top_SoC globalMem memory_data_MPORT_22_addr", false,-1, 5,0);
        vcdp->declBus(c+2569,"top_SoC globalMem memory_data_MPORT_22_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_23_en", false,-1);
        vcdp->declBus(c+6705,"top_SoC globalMem memory_data_MPORT_23_addr", false,-1, 5,0);
        vcdp->declBus(c+2577,"top_SoC globalMem memory_data_MPORT_23_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_24_en", false,-1);
        vcdp->declBus(c+6713,"top_SoC globalMem memory_data_MPORT_24_addr", false,-1, 5,0);
        vcdp->declBus(c+2585,"top_SoC globalMem memory_data_MPORT_24_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_25_en", false,-1);
        vcdp->declBus(c+6721,"top_SoC globalMem memory_data_MPORT_25_addr", false,-1, 5,0);
        vcdp->declBus(c+2593,"top_SoC globalMem memory_data_MPORT_25_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_26_en", false,-1);
        vcdp->declBus(c+6729,"top_SoC globalMem memory_data_MPORT_26_addr", false,-1, 5,0);
        vcdp->declBus(c+2601,"top_SoC globalMem memory_data_MPORT_26_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_27_en", false,-1);
        vcdp->declBus(c+6737,"top_SoC globalMem memory_data_MPORT_27_addr", false,-1, 5,0);
        vcdp->declBus(c+2609,"top_SoC globalMem memory_data_MPORT_27_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_28_en", false,-1);
        vcdp->declBus(c+6745,"top_SoC globalMem memory_data_MPORT_28_addr", false,-1, 5,0);
        vcdp->declBus(c+2617,"top_SoC globalMem memory_data_MPORT_28_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_29_en", false,-1);
        vcdp->declBus(c+6753,"top_SoC globalMem memory_data_MPORT_29_addr", false,-1, 5,0);
        vcdp->declBus(c+2625,"top_SoC globalMem memory_data_MPORT_29_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_30_en", false,-1);
        vcdp->declBus(c+6761,"top_SoC globalMem memory_data_MPORT_30_addr", false,-1, 5,0);
        vcdp->declBus(c+2633,"top_SoC globalMem memory_data_MPORT_30_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_31_en", false,-1);
        vcdp->declBus(c+6769,"top_SoC globalMem memory_data_MPORT_31_addr", false,-1, 5,0);
        vcdp->declBus(c+2641,"top_SoC globalMem memory_data_MPORT_31_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_32_en", false,-1);
        vcdp->declBus(c+6777,"top_SoC globalMem memory_data_MPORT_32_addr", false,-1, 5,0);
        vcdp->declBus(c+2649,"top_SoC globalMem memory_data_MPORT_32_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_33_en", false,-1);
        vcdp->declBus(c+6785,"top_SoC globalMem memory_data_MPORT_33_addr", false,-1, 5,0);
        vcdp->declBus(c+2657,"top_SoC globalMem memory_data_MPORT_33_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_34_en", false,-1);
        vcdp->declBus(c+6793,"top_SoC globalMem memory_data_MPORT_34_addr", false,-1, 5,0);
        vcdp->declBus(c+2665,"top_SoC globalMem memory_data_MPORT_34_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_35_en", false,-1);
        vcdp->declBus(c+6801,"top_SoC globalMem memory_data_MPORT_35_addr", false,-1, 5,0);
        vcdp->declBus(c+2673,"top_SoC globalMem memory_data_MPORT_35_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_36_en", false,-1);
        vcdp->declBus(c+6809,"top_SoC globalMem memory_data_MPORT_36_addr", false,-1, 5,0);
        vcdp->declBus(c+2681,"top_SoC globalMem memory_data_MPORT_36_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_37_en", false,-1);
        vcdp->declBus(c+6817,"top_SoC globalMem memory_data_MPORT_37_addr", false,-1, 5,0);
        vcdp->declBus(c+2689,"top_SoC globalMem memory_data_MPORT_37_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_38_en", false,-1);
        vcdp->declBus(c+6825,"top_SoC globalMem memory_data_MPORT_38_addr", false,-1, 5,0);
        vcdp->declBus(c+2697,"top_SoC globalMem memory_data_MPORT_38_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_39_en", false,-1);
        vcdp->declBus(c+6833,"top_SoC globalMem memory_data_MPORT_39_addr", false,-1, 5,0);
        vcdp->declBus(c+2705,"top_SoC globalMem memory_data_MPORT_39_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_40_en", false,-1);
        vcdp->declBus(c+6841,"top_SoC globalMem memory_data_MPORT_40_addr", false,-1, 5,0);
        vcdp->declBus(c+2713,"top_SoC globalMem memory_data_MPORT_40_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_41_en", false,-1);
        vcdp->declBus(c+6849,"top_SoC globalMem memory_data_MPORT_41_addr", false,-1, 5,0);
        vcdp->declBus(c+2721,"top_SoC globalMem memory_data_MPORT_41_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_42_en", false,-1);
        vcdp->declBus(c+6857,"top_SoC globalMem memory_data_MPORT_42_addr", false,-1, 5,0);
        vcdp->declBus(c+2729,"top_SoC globalMem memory_data_MPORT_42_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_43_en", false,-1);
        vcdp->declBus(c+6865,"top_SoC globalMem memory_data_MPORT_43_addr", false,-1, 5,0);
        vcdp->declBus(c+2737,"top_SoC globalMem memory_data_MPORT_43_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_44_en", false,-1);
        vcdp->declBus(c+6873,"top_SoC globalMem memory_data_MPORT_44_addr", false,-1, 5,0);
        vcdp->declBus(c+2745,"top_SoC globalMem memory_data_MPORT_44_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_45_en", false,-1);
        vcdp->declBus(c+6881,"top_SoC globalMem memory_data_MPORT_45_addr", false,-1, 5,0);
        vcdp->declBus(c+2753,"top_SoC globalMem memory_data_MPORT_45_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_46_en", false,-1);
        vcdp->declBus(c+6889,"top_SoC globalMem memory_data_MPORT_46_addr", false,-1, 5,0);
        vcdp->declBus(c+2761,"top_SoC globalMem memory_data_MPORT_46_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_47_en", false,-1);
        vcdp->declBus(c+6897,"top_SoC globalMem memory_data_MPORT_47_addr", false,-1, 5,0);
        vcdp->declBus(c+2769,"top_SoC globalMem memory_data_MPORT_47_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_48_en", false,-1);
        vcdp->declBus(c+6905,"top_SoC globalMem memory_data_MPORT_48_addr", false,-1, 5,0);
        vcdp->declBus(c+2777,"top_SoC globalMem memory_data_MPORT_48_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_49_en", false,-1);
        vcdp->declBus(c+6913,"top_SoC globalMem memory_data_MPORT_49_addr", false,-1, 5,0);
        vcdp->declBus(c+2785,"top_SoC globalMem memory_data_MPORT_49_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_50_en", false,-1);
        vcdp->declBus(c+6921,"top_SoC globalMem memory_data_MPORT_50_addr", false,-1, 5,0);
        vcdp->declBus(c+2793,"top_SoC globalMem memory_data_MPORT_50_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_51_en", false,-1);
        vcdp->declBus(c+6929,"top_SoC globalMem memory_data_MPORT_51_addr", false,-1, 5,0);
        vcdp->declBus(c+2801,"top_SoC globalMem memory_data_MPORT_51_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_52_en", false,-1);
        vcdp->declBus(c+6937,"top_SoC globalMem memory_data_MPORT_52_addr", false,-1, 5,0);
        vcdp->declBus(c+2809,"top_SoC globalMem memory_data_MPORT_52_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_53_en", false,-1);
        vcdp->declBus(c+6945,"top_SoC globalMem memory_data_MPORT_53_addr", false,-1, 5,0);
        vcdp->declBus(c+2817,"top_SoC globalMem memory_data_MPORT_53_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_54_en", false,-1);
        vcdp->declBus(c+6953,"top_SoC globalMem memory_data_MPORT_54_addr", false,-1, 5,0);
        vcdp->declBus(c+2825,"top_SoC globalMem memory_data_MPORT_54_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_55_en", false,-1);
        vcdp->declBus(c+6961,"top_SoC globalMem memory_data_MPORT_55_addr", false,-1, 5,0);
        vcdp->declBus(c+2833,"top_SoC globalMem memory_data_MPORT_55_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_56_en", false,-1);
        vcdp->declBus(c+6969,"top_SoC globalMem memory_data_MPORT_56_addr", false,-1, 5,0);
        vcdp->declBus(c+2841,"top_SoC globalMem memory_data_MPORT_56_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_57_en", false,-1);
        vcdp->declBus(c+6977,"top_SoC globalMem memory_data_MPORT_57_addr", false,-1, 5,0);
        vcdp->declBus(c+2849,"top_SoC globalMem memory_data_MPORT_57_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_58_en", false,-1);
        vcdp->declBus(c+6985,"top_SoC globalMem memory_data_MPORT_58_addr", false,-1, 5,0);
        vcdp->declBus(c+2857,"top_SoC globalMem memory_data_MPORT_58_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_59_en", false,-1);
        vcdp->declBus(c+6993,"top_SoC globalMem memory_data_MPORT_59_addr", false,-1, 5,0);
        vcdp->declBus(c+2865,"top_SoC globalMem memory_data_MPORT_59_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_60_en", false,-1);
        vcdp->declBus(c+7001,"top_SoC globalMem memory_data_MPORT_60_addr", false,-1, 5,0);
        vcdp->declBus(c+2873,"top_SoC globalMem memory_data_MPORT_60_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_61_en", false,-1);
        vcdp->declBus(c+7009,"top_SoC globalMem memory_data_MPORT_61_addr", false,-1, 5,0);
        vcdp->declBus(c+2881,"top_SoC globalMem memory_data_MPORT_61_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_62_en", false,-1);
        vcdp->declBus(c+7017,"top_SoC globalMem memory_data_MPORT_62_addr", false,-1, 5,0);
        vcdp->declBus(c+2889,"top_SoC globalMem memory_data_MPORT_62_data", false,-1, 31,0);
        vcdp->declBit(c+6489,"top_SoC globalMem memory_data_MPORT_63_en", false,-1);
        vcdp->declBus(c+7025,"top_SoC globalMem memory_data_MPORT_63_addr", false,-1, 5,0);
        vcdp->declBus(c+2897,"top_SoC globalMem memory_data_MPORT_63_data", false,-1, 31,0);
        vcdp->declBus(c+2905,"top_SoC globalMem memory_MPORT_data", false,-1, 31,0);
        vcdp->declBus(c+5849,"top_SoC globalMem memory_MPORT_addr", false,-1, 5,0);
        vcdp->declBit(c+6505,"top_SoC globalMem memory_MPORT_mask", false,-1);
        vcdp->declBit(c+5881,"top_SoC globalMem memory_MPORT_en", false,-1);
        vcdp->declBus(c+2905,"top_SoC globalMem memory_MPORT_1_data", false,-1, 31,0);
        vcdp->declBus(c+5889,"top_SoC globalMem memory_MPORT_1_addr", false,-1, 5,0);
        vcdp->declBit(c+6505,"top_SoC globalMem memory_MPORT_1_mask", false,-1);
        vcdp->declBit(c+5897,"top_SoC globalMem memory_MPORT_1_en", false,-1);
        vcdp->declBus(c+5905,"top_SoC globalMem readID", false,-1, 3,0);
        vcdp->declBus(c+5913,"top_SoC globalMem rAddrOffset", false,-1, 31,0);
        vcdp->declBus(c+5921,"top_SoC globalMem wAddrOffset", false,-1, 31,0);
        vcdp->declBus(c+5929,"top_SoC globalMem writeAddressReg", false,-1, 31,0);
        vcdp->declBus(c+5937,"top_SoC globalMem writeID", false,-1, 3,0);
        vcdp->declBus(c+5945,"top_SoC globalMem writeState", false,-1, 2,0);
        vcdp->declBus(c+5953,"top_SoC globalMem readState", false,-1, 1,0);
        vcdp->declBus(c+5961,"top_SoC globalMem rLatencyCounter", false,-1, 7,0);
        vcdp->declBus(c+5969,"top_SoC globalMem wLatencyCounter", false,-1, 7,0);
        vcdp->declBus(c+5977,"top_SoC globalMem rlength", false,-1, 3,0);
        vcdp->declBus(c+5985,"top_SoC globalMem rburst_counter", false,-1, 3,0);
        vcdp->declBit(c+2913,"top_SoC globalMem readLast", false,-1);
        vcdp->declBus(c+2921,"top_SoC globalMem writeData_0", false,-1, 7,0);
        vcdp->declBus(c+2929,"top_SoC globalMem writeData_1", false,-1, 7,0);
        vcdp->declBus(c+2937,"top_SoC globalMem writeData_2", false,-1, 7,0);
        vcdp->declBus(c+2945,"top_SoC globalMem writeData_3", false,-1, 7,0);
        vcdp->declBus(c+2953,"top_SoC globalMem lo", false,-1, 15,0);
        vcdp->declBus(c+2961,"top_SoC globalMem hi", false,-1, 15,0);
        vcdp->declBus(c+7041,"top_SoC globalMem initvar", false,-1, 31,0);
    }
}

void Vtop_SoC::traceFullThis__1(Vtop_SoC__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(((IData)(vlTOPp->top_SoC__DOT__dma__DOT___io_slave_aw_ready_T_2) 
                            & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv)))));
        vcdp->fullBit(c+9,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready));
        vcdp->fullBit(c+17,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_out_readData_ready));
        vcdp->fullBit(c+25,(vlTOPp->top_SoC__DOT__dma_io_master_aw_valid));
        vcdp->fullBus(c+33,((IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38)),32);
        vcdp->fullBus(c+41,((IData)((VL_ULL(0x7fffffffffffffff) 
                                     & ((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                         ? ((QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__data_buffer)) 
                                            << (0x18U 
                                                & ((IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38) 
                                                   << 3U)))
                                         : (QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__data_buffer)))))),32);
        vcdp->fullBus(c+49,(((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                              ? (0xfU & ((IData)(vlTOPp->top_SoC__DOT__dma__DOT__mask_width) 
                                         << (3U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38))))
                              : 0xfU)),4);
        vcdp->fullBus(c+57,((IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_24)),32);
        vcdp->fullBit(c+65,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid));
        vcdp->fullBus(c+73,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data),32);
        vcdp->fullBus(c+81,(vlTOPp->top_SoC__DOT__im_io_inst),32);
        vcdp->fullBus(c+89,(vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr),32);
        vcdp->fullBus(c+97,((IData)(vlTOPp->top_SoC__DOT__cpu__DOT___GEN_8)),32);
        vcdp->fullBit(c+105,(vlTOPp->top_SoC__DOT__cpu_io_master_b_ready));
        vcdp->fullBus(c+113,(vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr),32);
        vcdp->fullBit(c+121,(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready));
        vcdp->fullBit(c+129,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_valid));
        vcdp->fullBus(c+137,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_bits_data),32);
        vcdp->fullBit(c+145,((0xbU == (0x7fU & vlTOPp->top_SoC__DOT__im_io_inst))));
        vcdp->fullBit(c+153,(((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                              | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                                 | ((0x63U == (0x7fU 
                                               & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                                    & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___E_Branch_taken_T_14))))));
        vcdp->fullBit(c+161,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH));
        vcdp->fullBit(c+169,(vlTOPp->top_SoC__DOT__cpu_io_Stall_MA));
        vcdp->fullBit(c+177,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH));
        vcdp->fullBus(c+185,(((2U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ASel))
                               ? 0U : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT___alu_src1_T_3)),32);
        vcdp->fullBus(c+193,(((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_BSel)
                               ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__immReg
                               : vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg)),32);
        vcdp->fullBus(c+201,((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10)),32);
        vcdp->fullBus(c+209,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata),32);
        vcdp->fullBit(c+217,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_out_writeResp_ready));
        vcdp->fullBit(c+225,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_out_readData_ready));
        vcdp->fullBit(c+233,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)) 
                              & (IData)(vlTOPp->top_SoC__DOT__localMem__DOT___GEN_29))));
        vcdp->fullBus(c+241,(((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                               ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                        ? 0U : ((2U 
                                                 == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                                 ? 0U
                                                 : 
                                                ((3U 
                                                  == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                                  ? 
                                                 vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                                 [(0x3fU 
                                                   & vlTOPp->top_SoC__DOT__localMem__DOT__rAddrOffset)]
                                                  : 0U))))),32);
        vcdp->fullBit(c+249,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_out_writeResp_ready));
        vcdp->fullBit(c+257,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_out_readData_ready));
        vcdp->fullBit(c+265,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)) 
                              & (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_29))));
        vcdp->fullBus(c+273,(((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                               ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                        ? 0U : ((2U 
                                                 == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                                 ? 0U
                                                 : 
                                                ((3U 
                                                  == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                                  ? 
                                                 vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                                 [(0x3fU 
                                                   & vlTOPp->top_SoC__DOT__globalMem__DOT__rAddrOffset)]
                                                  : 0U))))),32);
        vcdp->fullBus(c+281,((3U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38))),2);
        vcdp->fullBus(c+289,(vlTOPp->top_SoC__DOT__dma__DOT__mask_width),4);
        vcdp->fullBus(c+297,((0xfU & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_32))),4);
        vcdp->fullBus(c+305,((((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                               ? ((2U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_32))
                                   ? (0xffU & (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data 
                                               >> 8U))
                                   : 0U) : 0U)),8);
        vcdp->fullBus(c+313,((((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                               ? ((1U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_32))
                                   ? (0xffU & vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data)
                                   : 0U) : 0U)),8);
        vcdp->fullBus(c+321,((((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                               ? ((8U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_32))
                                   ? (0xffU & (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data 
                                               >> 0x18U))
                                   : 0U) : 0U)),8);
        vcdp->fullBus(c+329,((((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                               ? ((4U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_32))
                                   ? (0xffU & (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data 
                                               >> 0x10U))
                                   : 0U) : 0U)),8);
        vcdp->fullBit(c+337,((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH) 
                               | (IData)(vlTOPp->top_SoC__DOT__cpu_io_Stall_MA)) 
                              & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)))));
        vcdp->fullBus(c+345,(((2U == ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)
                                       ? 2U : 0U)) ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10)
                               : ((1U == ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)
                                           ? 2U : 0U))
                                   ? ((IData)(4U) + vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg)
                                   : ((IData)(4U) + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg)))),32);
        vcdp->fullBit(c+353,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID_io_Stall));
        vcdp->fullBit(c+361,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Flush));
        vcdp->fullBit(c+369,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall));
        vcdp->fullBus(c+377,(((0x1fU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                  >> 0xfU)))
                               ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31
                               : ((0x1eU == (0x1fU 
                                             & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                >> 0xfU)))
                                   ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_30
                                   : ((0x1dU == (0x1fU 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                    >> 0xfU)))
                                       ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_29
                                       : ((0x1cU == 
                                           (0x1fU & 
                                            (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                             >> 0xfU)))
                                           ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_28
                                           : ((0x1bU 
                                               == (0x1fU 
                                                   & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                      >> 0xfU)))
                                               ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_27
                                               : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_26)))))),32);
        vcdp->fullBus(c+385,(((0x1fU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                  >> 0x14U)))
                               ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31
                               : ((0x1eU == (0x1fU 
                                             & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                >> 0x14U)))
                                   ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_30
                                   : ((0x1dU == (0x1fU 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                    >> 0x14U)))
                                       ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_29
                                       : ((0x1cU == 
                                           (0x1fU & 
                                            (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                             >> 0x14U)))
                                           ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_28
                                           : ((0x1bU 
                                               == (0x1fU 
                                                   & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                      >> 0x14U)))
                                               ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_27
                                               : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_58)))))),32);
        vcdp->fullBus(c+393,(((4U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel))
                               ? ((0xffe00000U & (VL_NEGATE_I((IData)(
                                                                      (1U 
                                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_22 
                                                                          >> 0x14U)))) 
                                                  << 0x15U)) 
                                  | vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_22)
                               : ((5U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel))
                                   ? (0xfffff000U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)
                                   : ((0xffffe000U 
                                       & (VL_NEGATE_I((IData)(
                                                              (1U 
                                                               & ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_30) 
                                                                  >> 0xcU)))) 
                                          << 0xdU)) 
                                      | (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_30))))),32);
        vcdp->fullBus(c+401,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_MEM_io_Mem_Data),32);
        vcdp->fullBus(c+409,(((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)
                               ? 2U : 0U)),2);
        vcdp->fullBit(c+417,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn));
        vcdp->fullBus(c+425,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel),3);
        vcdp->fullBus(c+433,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ASel),2);
        vcdp->fullBit(c+441,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_BSel));
        vcdp->fullBus(c+449,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel),15);
        vcdp->fullBit(c+457,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrEq));
        vcdp->fullBit(c+465,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT));
        vcdp->fullBus(c+473,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_WBSel),2);
        vcdp->fullBit(c+481,(((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_valid)))));
        vcdp->fullBus(c+489,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1),32);
        vcdp->fullBus(c+497,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2),32);
        vcdp->fullBus(c+505,((0x7fU & vlTOPp->top_SoC__DOT__im_io_inst)),7);
        vcdp->fullBit(c+513,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__E_Branch_taken));
        vcdp->fullBit(c+521,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1));
        vcdp->fullBit(c+529,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2));
        vcdp->fullBit(c+537,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd));
        vcdp->fullBit(c+545,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd));
        vcdp->fullBit(c+553,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd));
        vcdp->fullBit(c+561,(((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1) 
                                & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd)) 
                               & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0xfU)) 
                                  == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                               >> 7U)))) 
                              & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                                 >> 7U))))));
        vcdp->fullBit(c+569,(((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2) 
                                & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd)) 
                               & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0x14U)) 
                                  == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                               >> 7U)))) 
                              & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                                 >> 7U))))));
        vcdp->fullBit(c+577,(((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1) 
                                & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd)) 
                               & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0xfU)) 
                                  == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                               >> 7U)))) 
                              & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                 >> 7U))))));
        vcdp->fullBit(c+585,(((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2) 
                                & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd)) 
                               & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0x14U)) 
                                  == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                               >> 7U)))) 
                              & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                 >> 7U))))));
        vcdp->fullBit(c+593,(((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1) 
                                & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd)) 
                               & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0xfU)) 
                                  == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                               >> 7U)))) 
                              & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                                 >> 7U))))));
        vcdp->fullBit(c+601,(((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2) 
                                & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd)) 
                               & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0x14U)) 
                                  == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                               >> 7U)))) 
                              & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                                 >> 7U))))));
        vcdp->fullBus(c+609,(vlTOPp->top_SoC__DOT__im__DOT__memory
                             [(0x7fffU & ((IData)(3U) 
                                          + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))]),8);
        vcdp->fullBus(c+617,(vlTOPp->top_SoC__DOT__im__DOT__memory
                             [(0x7fffU & ((IData)(2U) 
                                          + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))]),8);
        vcdp->fullBus(c+625,(vlTOPp->top_SoC__DOT__im__DOT__memory
                             [(0x7fffU & ((IData)(1U) 
                                          + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))]),8);
        vcdp->fullBus(c+633,(vlTOPp->top_SoC__DOT__im__DOT__memory
                             [(0x7fffU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg)]),8);
        vcdp->fullBus(c+641,(((vlTOPp->top_SoC__DOT__im__DOT__memory
                               [(0x7fffU & ((IData)(1U) 
                                            + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))] 
                               << 8U) | vlTOPp->top_SoC__DOT__im__DOT__memory
                              [(0x7fffU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg)])),16);
        vcdp->fullBus(c+649,(((vlTOPp->top_SoC__DOT__im__DOT__memory
                               [(0x7fffU & ((IData)(3U) 
                                            + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))] 
                               << 8U) | vlTOPp->top_SoC__DOT__im__DOT__memory
                              [(0x7fffU & ((IData)(2U) 
                                           + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))])),16);
        vcdp->fullBit(c+657,(((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1)) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0))));
        vcdp->fullBit(c+665,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_0_readAddr_valid));
        vcdp->fullBit(c+673,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                              & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
                                 & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready)))));
        vcdp->fullBit(c+681,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_0_readData_valid));
        vcdp->fullBit(c+689,(((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1)) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0))));
        vcdp->fullBit(c+697,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_1_readAddr_valid));
        vcdp->fullBit(c+705,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                              & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
                                 & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready)))));
        vcdp->fullBit(c+713,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_0_readData_valid));
        vcdp->fullBit(c+721,(((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1)) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0))));
        vcdp->fullBit(c+729,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_2_readAddr_valid));
        vcdp->fullBit(c+737,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                              & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
                                 & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready)))));
        vcdp->fullBit(c+745,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_0_readData_valid));
        vcdp->fullBit(c+753,((((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant)) 
                               | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                     | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid)))) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0))));
        vcdp->fullBit(c+761,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_0_readAddr_valid));
        vcdp->fullBit(c+769,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_1_readData_valid));
        vcdp->fullBit(c+777,((((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant)) 
                               | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                     | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid)))) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0))));
        vcdp->fullBit(c+785,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_1_readAddr_valid));
        vcdp->fullBit(c+793,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_1_readData_valid));
        vcdp->fullBit(c+801,((((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant)) 
                               | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                     | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid)))) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0))));
        vcdp->fullBit(c+809,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_2_readAddr_valid));
        vcdp->fullBit(c+817,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_1_readData_valid));
        vcdp->fullBit(c+825,(((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1)) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0))));
        vcdp->fullBit(c+833,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeAddr_valid));
        vcdp->fullBit(c+841,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeData_ready));
        vcdp->fullBit(c+849,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_valid));
        vcdp->fullBus(c+857,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_data),32);
        vcdp->fullBus(c+865,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_strb),4);
        vcdp->fullBit(c+873,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_last));
        vcdp->fullBit(c+881,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeResp_ready));
        vcdp->fullBit(c+889,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeResp_valid));
        vcdp->fullBit(c+897,(((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1)) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0))));
        vcdp->fullBit(c+905,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeAddr_valid));
        vcdp->fullBit(c+913,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeData_ready));
        vcdp->fullBit(c+921,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_valid));
        vcdp->fullBus(c+929,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_data),32);
        vcdp->fullBus(c+937,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_strb),4);
        vcdp->fullBit(c+945,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_last));
        vcdp->fullBit(c+953,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeResp_ready));
        vcdp->fullBit(c+961,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeResp_valid));
        vcdp->fullBit(c+969,(((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1)) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0))));
        vcdp->fullBit(c+977,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeAddr_valid));
        vcdp->fullBit(c+985,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeData_ready));
        vcdp->fullBit(c+993,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_valid));
        vcdp->fullBus(c+1001,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_data),32);
        vcdp->fullBus(c+1009,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_strb),4);
        vcdp->fullBit(c+1017,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_last));
        vcdp->fullBit(c+1025,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeResp_ready));
        vcdp->fullBit(c+1033,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeResp_valid));
        vcdp->fullBit(c+1041,((((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant)) 
                                | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                      | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid)))) 
                               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0))));
        vcdp->fullBit(c+1049,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeAddr_valid));
        vcdp->fullBit(c+1057,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeData_ready));
        vcdp->fullBit(c+1065,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_valid));
        vcdp->fullBus(c+1073,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_data),32);
        vcdp->fullBus(c+1081,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_strb),4);
        vcdp->fullBit(c+1089,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_last));
        vcdp->fullBit(c+1097,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeResp_ready));
        vcdp->fullBit(c+1105,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeResp_valid));
        vcdp->fullBit(c+1113,((((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant)) 
                                | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                      | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid)))) 
                               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0))));
        vcdp->fullBit(c+1121,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeAddr_valid));
        vcdp->fullBit(c+1129,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeData_ready));
        vcdp->fullBit(c+1137,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_valid));
        vcdp->fullBus(c+1145,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_data),32);
        vcdp->fullBus(c+1153,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_strb),4);
        vcdp->fullBit(c+1161,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_last));
        vcdp->fullBit(c+1169,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeResp_ready));
        vcdp->fullBit(c+1177,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeResp_valid));
        vcdp->fullBit(c+1185,((((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant)) 
                                | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                      | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid)))) 
                               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0))));
        vcdp->fullBit(c+1193,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeAddr_valid));
        vcdp->fullBit(c+1201,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeData_ready));
        vcdp->fullBit(c+1209,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_valid));
        vcdp->fullBus(c+1217,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_data),32);
        vcdp->fullBus(c+1225,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_strb),4);
        vcdp->fullBit(c+1233,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_last));
        vcdp->fullBit(c+1241,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeResp_ready));
        vcdp->fullBit(c+1249,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeResp_valid));
        vcdp->fullBus(c+1257,(((0x64U > vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr)
                                ? 0U : (((0x8000U <= vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr) 
                                         & (0x8800U 
                                            > vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr))
                                         ? 1U : (((0x10000U 
                                                   <= vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr) 
                                                  & (0x10800U 
                                                     > vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr))
                                                  ? 2U
                                                  : 0U)))),2);
        vcdp->fullBus(c+1265,(((0x64U > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_24))
                                ? 0U : (((0x8000U <= (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_24)) 
                                         & (0x8800U 
                                            > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_24)))
                                         ? 1U : (((0x10000U 
                                                   <= (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_24)) 
                                                  & (0x10800U 
                                                     > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_24)))
                                                  ? 2U
                                                  : 0U)))),2);
        vcdp->fullBit(c+1273,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1)))));
        vcdp->fullBit(c+1281,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid));
        vcdp->fullBit(c+1289,((1U & ((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant)) 
                                     | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid)))))));
        vcdp->fullBit(c+1297,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_1_valid));
        vcdp->fullBit(c+1305,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_out_valid));
        vcdp->fullBit(c+1313,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_chosen));
        vcdp->fullBit(c+1321,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_0_readAddr_valid) 
                               | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_0_readAddr_valid))));
        vcdp->fullBit(c+1329,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0));
        vcdp->fullBit(c+1337,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1));
        vcdp->fullBit(c+1345,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                        | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid))))));
        vcdp->fullBit(c+1353,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1)))));
        vcdp->fullBit(c+1361,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid));
        vcdp->fullBit(c+1369,((1U & ((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant)) 
                                     | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid)))))));
        vcdp->fullBit(c+1377,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_1_valid));
        vcdp->fullBit(c+1385,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_out_valid));
        vcdp->fullBit(c+1393,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_chosen));
        vcdp->fullBit(c+1401,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_1_readAddr_valid) 
                               | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_1_readAddr_valid))));
        vcdp->fullBit(c+1409,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0));
        vcdp->fullBit(c+1417,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1));
        vcdp->fullBit(c+1425,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                        | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid))))));
        vcdp->fullBit(c+1433,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1)))));
        vcdp->fullBit(c+1441,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid));
        vcdp->fullBit(c+1449,((1U & ((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant)) 
                                     | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid)))))));
        vcdp->fullBit(c+1457,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_1_valid));
        vcdp->fullBit(c+1465,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_out_valid));
        vcdp->fullBit(c+1473,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_chosen));
        vcdp->fullBit(c+1481,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_2_readAddr_valid) 
                               | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_2_readAddr_valid))));
        vcdp->fullBit(c+1489,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0));
        vcdp->fullBit(c+1497,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1));
        vcdp->fullBit(c+1505,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                        | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid))))));
        vcdp->fullBus(c+1513,(((0x64U > vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr)
                                ? 0U : (((0x8000U <= vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr) 
                                         & (0x8800U 
                                            > vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr))
                                         ? 1U : (((0x10000U 
                                                   <= vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr) 
                                                  & (0x10800U 
                                                     > vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr))
                                                  ? 2U
                                                  : 0U)))),2);
        vcdp->fullBus(c+1521,(((0x64U > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38))
                                ? 0U : (((0x8000U <= (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38)) 
                                         & (0x8800U 
                                            > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38)))
                                         ? 1U : (((0x10000U 
                                                   <= (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38)) 
                                                  & (0x10800U 
                                                     > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38)))
                                                  ? 2U
                                                  : 0U)))),2);
        vcdp->fullBit(c+1529,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1)))));
        vcdp->fullBit(c+1537,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid));
        vcdp->fullBit(c+1545,((1U & ((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant)) 
                                     | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid)))))));
        vcdp->fullBit(c+1553,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_1_valid));
        vcdp->fullBit(c+1561,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid));
        vcdp->fullBit(c+1569,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen));
        vcdp->fullBit(c+1577,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeAddr_valid) 
                               | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeAddr_valid))));
        vcdp->fullBit(c+1585,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0));
        vcdp->fullBit(c+1593,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1));
        vcdp->fullBit(c+1601,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                        | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid))))));
        vcdp->fullBit(c+1609,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1)))));
        vcdp->fullBit(c+1617,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid));
        vcdp->fullBit(c+1625,((1U & ((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant)) 
                                     | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid)))))));
        vcdp->fullBit(c+1633,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_1_valid));
        vcdp->fullBit(c+1641,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid));
        vcdp->fullBit(c+1649,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen));
        vcdp->fullBit(c+1657,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeAddr_valid) 
                               | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeAddr_valid))));
        vcdp->fullBit(c+1665,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0));
        vcdp->fullBit(c+1673,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1));
        vcdp->fullBit(c+1681,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                        | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid))))));
        vcdp->fullBit(c+1689,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1)))));
        vcdp->fullBit(c+1697,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid));
        vcdp->fullBit(c+1705,((1U & ((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant)) 
                                     | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid)))))));
        vcdp->fullBit(c+1713,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_1_valid));
        vcdp->fullBit(c+1721,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid));
        vcdp->fullBit(c+1729,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen));
        vcdp->fullBit(c+1737,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeAddr_valid) 
                               | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeAddr_valid))));
        vcdp->fullBit(c+1745,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0));
        vcdp->fullBit(c+1753,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1));
        vcdp->fullBit(c+1761,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                        | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid))))));
        vcdp->fullBit(c+1769,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)) 
                               & (IData)(vlTOPp->top_SoC__DOT__localMem__DOT___GEN_29))));
        vcdp->fullBus(c+1777,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [(0x3fU & vlTOPp->top_SoC__DOT__localMem__DOT__rAddrOffset)]),32);
        vcdp->fullBus(c+1785,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [(0x3fU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                          - (IData)(0x8000U)) 
                                         >> 2U))]),32);
        vcdp->fullBus(c+1793,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0U]),32);
        vcdp->fullBus(c+1801,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [1U]),32);
        vcdp->fullBus(c+1809,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [2U]),32);
        vcdp->fullBus(c+1817,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [3U]),32);
        vcdp->fullBus(c+1825,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [4U]),32);
        vcdp->fullBus(c+1833,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [5U]),32);
        vcdp->fullBus(c+1841,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [6U]),32);
        vcdp->fullBus(c+1849,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [7U]),32);
        vcdp->fullBus(c+1857,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [8U]),32);
        vcdp->fullBus(c+1865,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [9U]),32);
        vcdp->fullBus(c+1873,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0xaU]),32);
        vcdp->fullBus(c+1881,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0xbU]),32);
        vcdp->fullBus(c+1889,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0xcU]),32);
        vcdp->fullBus(c+1897,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0xdU]),32);
        vcdp->fullBus(c+1905,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0xeU]),32);
        vcdp->fullBus(c+1913,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0xfU]),32);
        vcdp->fullBus(c+1921,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x10U]),32);
        vcdp->fullBus(c+1929,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x11U]),32);
        vcdp->fullBus(c+1937,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x12U]),32);
        vcdp->fullBus(c+1945,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x13U]),32);
        vcdp->fullBus(c+1953,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x14U]),32);
        vcdp->fullBus(c+1961,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x15U]),32);
        vcdp->fullBus(c+1969,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x16U]),32);
        vcdp->fullBus(c+1977,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x17U]),32);
        vcdp->fullBus(c+1985,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x18U]),32);
        vcdp->fullBus(c+1993,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x19U]),32);
        vcdp->fullBus(c+2001,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x1aU]),32);
        vcdp->fullBus(c+2009,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x1bU]),32);
        vcdp->fullBus(c+2017,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x1cU]),32);
        vcdp->fullBus(c+2025,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x1dU]),32);
        vcdp->fullBus(c+2033,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x1eU]),32);
        vcdp->fullBus(c+2041,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x1fU]),32);
        vcdp->fullBus(c+2049,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x20U]),32);
        vcdp->fullBus(c+2057,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x21U]),32);
        vcdp->fullBus(c+2065,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x22U]),32);
        vcdp->fullBus(c+2073,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x23U]),32);
        vcdp->fullBus(c+2081,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x24U]),32);
        vcdp->fullBus(c+2089,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x25U]),32);
        vcdp->fullBus(c+2097,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x26U]),32);
        vcdp->fullBus(c+2105,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x27U]),32);
        vcdp->fullBus(c+2113,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x28U]),32);
        vcdp->fullBus(c+2121,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x29U]),32);
        vcdp->fullBus(c+2129,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x2aU]),32);
        vcdp->fullBus(c+2137,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x2bU]),32);
        vcdp->fullBus(c+2145,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x2cU]),32);
        vcdp->fullBus(c+2153,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x2dU]),32);
        vcdp->fullBus(c+2161,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x2eU]),32);
        vcdp->fullBus(c+2169,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x2fU]),32);
        vcdp->fullBus(c+2177,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x30U]),32);
        vcdp->fullBus(c+2185,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x31U]),32);
        vcdp->fullBus(c+2193,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x32U]),32);
        vcdp->fullBus(c+2201,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x33U]),32);
        vcdp->fullBus(c+2209,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x34U]),32);
        vcdp->fullBus(c+2217,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x35U]),32);
        vcdp->fullBus(c+2225,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x36U]),32);
        vcdp->fullBus(c+2233,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x37U]),32);
        vcdp->fullBus(c+2241,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x38U]),32);
        vcdp->fullBus(c+2249,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x39U]),32);
        vcdp->fullBus(c+2257,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x3aU]),32);
        vcdp->fullBus(c+2265,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x3bU]),32);
        vcdp->fullBus(c+2273,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x3cU]),32);
        vcdp->fullBus(c+2281,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x3dU]),32);
        vcdp->fullBus(c+2289,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x3eU]),32);
        vcdp->fullBus(c+2297,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                              [0x3fU]),32);
        vcdp->fullBus(c+2305,((((IData)(vlTOPp->top_SoC__DOT__localMem__DOT__hi) 
                                << 0x10U) | (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__lo))),32);
        vcdp->fullBit(c+2313,(vlTOPp->top_SoC__DOT__localMem__DOT__readLast));
        vcdp->fullBus(c+2321,((0xffU & ((1U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                         ? vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data
                                         : vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                        [(0x3fU & (
                                                   (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                    - (IData)(0x8000U)) 
                                                   >> 2U))]))),8);
        vcdp->fullBus(c+2329,((0xffU & ((2U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                         ? (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                                            >> 8U) : 
                                        (vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                         [(0x3fU & 
                                           ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                             - (IData)(0x8000U)) 
                                            >> 2U))] 
                                         >> 8U)))),8);
        vcdp->fullBus(c+2337,((0xffU & ((4U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                         ? (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                                            >> 0x10U)
                                         : (vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                            [(0x3fU 
                                              & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                  - (IData)(0x8000U)) 
                                                 >> 2U))] 
                                            >> 0x10U)))),8);
        vcdp->fullBus(c+2345,((0xffU & ((8U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                         ? (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                                            >> 0x18U)
                                         : (vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                            [(0x3fU 
                                              & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                  - (IData)(0x8000U)) 
                                                 >> 2U))] 
                                            >> 0x18U)))),8);
        vcdp->fullBus(c+2353,(vlTOPp->top_SoC__DOT__localMem__DOT__lo),16);
        vcdp->fullBus(c+2361,(vlTOPp->top_SoC__DOT__localMem__DOT__hi),16);
        vcdp->fullBit(c+2369,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)) 
                               & (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_29))));
        vcdp->fullBus(c+2377,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [(0x3fU & vlTOPp->top_SoC__DOT__globalMem__DOT__rAddrOffset)]),32);
        vcdp->fullBus(c+2385,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [(0x3fU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                          - (IData)(0x10000U)) 
                                         >> 2U))]),32);
        vcdp->fullBus(c+2393,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0U]),32);
        vcdp->fullBus(c+2401,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [1U]),32);
        vcdp->fullBus(c+2409,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [2U]),32);
        vcdp->fullBus(c+2417,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [3U]),32);
        vcdp->fullBus(c+2425,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [4U]),32);
        vcdp->fullBus(c+2433,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [5U]),32);
        vcdp->fullBus(c+2441,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [6U]),32);
        vcdp->fullBus(c+2449,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [7U]),32);
        vcdp->fullBus(c+2457,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [8U]),32);
        vcdp->fullBus(c+2465,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [9U]),32);
        vcdp->fullBus(c+2473,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0xaU]),32);
        vcdp->fullBus(c+2481,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0xbU]),32);
        vcdp->fullBus(c+2489,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0xcU]),32);
        vcdp->fullBus(c+2497,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0xdU]),32);
        vcdp->fullBus(c+2505,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0xeU]),32);
        vcdp->fullBus(c+2513,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0xfU]),32);
        vcdp->fullBus(c+2521,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x10U]),32);
        vcdp->fullBus(c+2529,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x11U]),32);
        vcdp->fullBus(c+2537,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x12U]),32);
        vcdp->fullBus(c+2545,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x13U]),32);
        vcdp->fullBus(c+2553,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x14U]),32);
        vcdp->fullBus(c+2561,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x15U]),32);
        vcdp->fullBus(c+2569,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x16U]),32);
        vcdp->fullBus(c+2577,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x17U]),32);
        vcdp->fullBus(c+2585,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x18U]),32);
        vcdp->fullBus(c+2593,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x19U]),32);
        vcdp->fullBus(c+2601,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x1aU]),32);
        vcdp->fullBus(c+2609,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x1bU]),32);
        vcdp->fullBus(c+2617,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x1cU]),32);
        vcdp->fullBus(c+2625,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x1dU]),32);
        vcdp->fullBus(c+2633,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x1eU]),32);
        vcdp->fullBus(c+2641,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x1fU]),32);
        vcdp->fullBus(c+2649,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x20U]),32);
        vcdp->fullBus(c+2657,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x21U]),32);
        vcdp->fullBus(c+2665,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x22U]),32);
        vcdp->fullBus(c+2673,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x23U]),32);
        vcdp->fullBus(c+2681,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x24U]),32);
        vcdp->fullBus(c+2689,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x25U]),32);
        vcdp->fullBus(c+2697,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x26U]),32);
        vcdp->fullBus(c+2705,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x27U]),32);
        vcdp->fullBus(c+2713,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x28U]),32);
        vcdp->fullBus(c+2721,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x29U]),32);
        vcdp->fullBus(c+2729,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x2aU]),32);
        vcdp->fullBus(c+2737,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x2bU]),32);
        vcdp->fullBus(c+2745,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x2cU]),32);
        vcdp->fullBus(c+2753,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x2dU]),32);
        vcdp->fullBus(c+2761,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x2eU]),32);
        vcdp->fullBus(c+2769,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x2fU]),32);
        vcdp->fullBus(c+2777,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x30U]),32);
        vcdp->fullBus(c+2785,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x31U]),32);
        vcdp->fullBus(c+2793,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x32U]),32);
        vcdp->fullBus(c+2801,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x33U]),32);
        vcdp->fullBus(c+2809,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x34U]),32);
        vcdp->fullBus(c+2817,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x35U]),32);
        vcdp->fullBus(c+2825,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x36U]),32);
        vcdp->fullBus(c+2833,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x37U]),32);
        vcdp->fullBus(c+2841,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x38U]),32);
        vcdp->fullBus(c+2849,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x39U]),32);
        vcdp->fullBus(c+2857,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x3aU]),32);
        vcdp->fullBus(c+2865,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x3bU]),32);
        vcdp->fullBus(c+2873,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x3cU]),32);
        vcdp->fullBus(c+2881,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x3dU]),32);
        vcdp->fullBus(c+2889,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x3eU]),32);
        vcdp->fullBus(c+2897,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                              [0x3fU]),32);
        vcdp->fullBus(c+2905,((((IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__hi) 
                                << 0x10U) | (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__lo))),32);
        vcdp->fullBit(c+2913,(vlTOPp->top_SoC__DOT__globalMem__DOT__readLast));
        vcdp->fullBus(c+2921,((0xffU & ((1U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                         ? vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data
                                         : vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                        [(0x3fU & (
                                                   (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                    - (IData)(0x10000U)) 
                                                   >> 2U))]))),8);
        vcdp->fullBus(c+2929,((0xffU & ((2U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                         ? (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                                            >> 8U) : 
                                        (vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                         [(0x3fU & 
                                           ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                             - (IData)(0x10000U)) 
                                            >> 2U))] 
                                         >> 8U)))),8);
        vcdp->fullBus(c+2937,((0xffU & ((4U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                         ? (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                                            >> 0x10U)
                                         : (vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                            [(0x3fU 
                                              & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                  - (IData)(0x10000U)) 
                                                 >> 2U))] 
                                            >> 0x10U)))),8);
        vcdp->fullBus(c+2945,((0xffU & ((8U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                         ? (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                                            >> 0x18U)
                                         : (vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                            [(0x3fU 
                                              & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                  - (IData)(0x10000U)) 
                                                 >> 2U))] 
                                            >> 0x18U)))),8);
        vcdp->fullBus(c+2953,(vlTOPp->top_SoC__DOT__globalMem__DOT__lo),16);
        vcdp->fullBus(c+2961,(vlTOPp->top_SoC__DOT__globalMem__DOT__hi),16);
        vcdp->fullBit(c+2969,((((0U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)) 
                                | (1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState))) 
                               & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv)))));
        vcdp->fullBit(c+2977,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined));
        vcdp->fullBus(c+2985,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_id),4);
        vcdp->fullBus(c+2993,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_addr),32);
        vcdp->fullBus(c+3001,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_size),2);
        vcdp->fullBit(c+3009,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined));
        vcdp->fullBus(c+3017,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_data),32);
        vcdp->fullBus(c+3025,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_strb),4);
        vcdp->fullBit(c+3033,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_last));
        vcdp->fullBit(c+3041,((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState))));
        vcdp->fullBus(c+3049,(vlTOPp->top_SoC__DOT__dma__DOT__sWriteIDReg),4);
        vcdp->fullBit(c+3057,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sReadState)))));
        vcdp->fullBit(c+3065,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined));
        vcdp->fullBus(c+3073,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_id),4);
        vcdp->fullBus(c+3081,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_addr),32);
        vcdp->fullBus(c+3089,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_size),2);
        vcdp->fullBit(c+3097,(vlTOPp->top_SoC__DOT__dma__DOT__sReadState));
        vcdp->fullBus(c+3105,(vlTOPp->top_SoC__DOT__dma__DOT__sReadIDReg),4);
        vcdp->fullBus(c+3113,(((0x14U == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
                                ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_5
                                : ((0x10U == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
                                    ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_4
                                    : ((0xcU == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
                                        ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3
                                        : ((8U == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
                                            ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_2
                                            : ((4U 
                                                == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
                                                ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_1
                                                : (
                                                   (0U 
                                                    == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
                                                    ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_0
                                                    : 0U))))))),32);
        vcdp->fullBit(c+3121,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)))));
        vcdp->fullBit(c+3129,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)))));
        vcdp->fullBit(c+3137,(((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                               & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteDataSent)))));
        vcdp->fullBit(c+3145,((4U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))));
        vcdp->fullBit(c+3153,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid));
        vcdp->fullBus(c+3161,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_id),4);
        vcdp->fullBus(c+3169,((3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg))),2);
        vcdp->fullBit(c+3177,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)))));
        vcdp->fullBit(c+3185,((1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))));
        vcdp->fullBit(c+3193,((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))));
        vcdp->fullBus(c+3201,(((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_id)
                                    : 0U) : ((1U == 
                                              (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                                  ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_id)
                                                  : 0U)
                                              : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                                  ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_id)
                                                  : 0U)))),4);
        vcdp->fullBus(c+3209,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                    ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                                        ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_resp)
                                        : 0U) : ((1U 
                                                  == 
                                                  (3U 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                                  ? 
                                                 ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_resp)
                                                   : 0U)
                                                  : 
                                                 ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_resp)
                                                   : 0U)))
                                : 0U)),2);
        vcdp->fullBit(c+3217,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                               & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                   ? ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)) 
                                      | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last))
                                   : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                       ? ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)) 
                                          | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last))
                                       : ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)) 
                                          | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last)))))));
        vcdp->fullBit(c+3225,((1U & vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_5)));
        vcdp->fullBus(c+3233,((0x7fffU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg)),15);
        vcdp->fullBit(c+3241,((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg))));
        vcdp->fullBit(c+3249,((0x23U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg))));
        vcdp->fullBus(c+3257,((7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                     >> 0xcU))),4);
        vcdp->fullBus(c+3265,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg),32);
        vcdp->fullBus(c+3273,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__wdataReg),32);
        vcdp->fullBit(c+3281,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)))));
        vcdp->fullBit(c+3289,((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState))));
        vcdp->fullBit(c+3297,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)))));
        vcdp->fullBus(c+3305,(((2U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                             >> 0xcU)))
                                ? 0xfU : ((1U == (7U 
                                                  & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                     >> 0xcU)))
                                           ? ((1U == 
                                               (2U 
                                                & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                               ? 0xcU
                                               : 3U)
                                           : ((0U == 
                                               (7U 
                                                & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                   >> 0xcU)))
                                               ? ((3U 
                                                   == 
                                                   (3U 
                                                    & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                   ? 8U
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                    ? 4U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                     ? 2U
                                                     : 1U)))
                                               : 0xfU)))),4);
        vcdp->fullBit(c+3313,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid));
        vcdp->fullBit(c+3321,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)))));
        vcdp->fullBit(c+3329,((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState))));
        vcdp->fullBus(c+3337,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_1),32);
        vcdp->fullBus(c+3345,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_2),32);
        vcdp->fullBus(c+3353,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_3),32);
        vcdp->fullBus(c+3361,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_4),32);
        vcdp->fullBus(c+3369,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_5),32);
        vcdp->fullBus(c+3377,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_6),32);
        vcdp->fullBus(c+3385,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_7),32);
        vcdp->fullBus(c+3393,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_8),32);
        vcdp->fullBus(c+3401,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_9),32);
        vcdp->fullBus(c+3409,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_10),32);
        vcdp->fullBus(c+3417,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_11),32);
        vcdp->fullBus(c+3425,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_12),32);
        vcdp->fullBus(c+3433,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_13),32);
        vcdp->fullBus(c+3441,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_14),32);
        vcdp->fullBus(c+3449,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_15),32);
        vcdp->fullBus(c+3457,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_16),32);
        vcdp->fullBus(c+3465,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_17),32);
        vcdp->fullBus(c+3473,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_18),32);
        vcdp->fullBus(c+3481,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_19),32);
        vcdp->fullBus(c+3489,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_20),32);
        vcdp->fullBus(c+3497,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_21),32);
        vcdp->fullBus(c+3505,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_22),32);
        vcdp->fullBus(c+3513,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_23),32);
        vcdp->fullBus(c+3521,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_24),32);
        vcdp->fullBus(c+3529,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_25),32);
        vcdp->fullBus(c+3537,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_26),32);
        vcdp->fullBus(c+3545,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_27),32);
        vcdp->fullBus(c+3553,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_28),32);
        vcdp->fullBus(c+3561,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_29),32);
        vcdp->fullBus(c+3569,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_30),32);
        vcdp->fullBus(c+3577,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31),32);
        vcdp->fullBus(c+3585,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg),32);
        vcdp->fullBus(c+3593,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg),32);
        vcdp->fullBus(c+3601,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg),32);
        vcdp->fullBus(c+3609,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__pcReg),32);
        vcdp->fullBus(c+3617,(((0U < vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg)
                                ? (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg 
                                   - (IData)(4U)) : vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg)),32);
        vcdp->fullBus(c+3625,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg),32);
        vcdp->fullBus(c+3633,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg),32);
        vcdp->fullBus(c+3641,((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                        >> 7U))),5);
        vcdp->fullBit(c+3649,(((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                               | (0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)))));
        vcdp->fullBit(c+3657,((0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))));
        vcdp->fullBit(c+3665,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                               & (1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)))));
        vcdp->fullBit(c+3673,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined));
        vcdp->fullBus(c+3681,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_id),4);
        vcdp->fullBus(c+3689,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr),32);
        vcdp->fullBit(c+3697,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                               & ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                  | (4U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))))));
        vcdp->fullBit(c+3705,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined));
        vcdp->fullBus(c+3713,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data),32);
        vcdp->fullBus(c+3721,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb),4);
        vcdp->fullBit(c+3729,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_last));
        vcdp->fullBit(c+3737,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                               & ((1U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                  & ((4U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                     & ((2U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                        & ((5U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                           & (3U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)))))))));
        vcdp->fullBus(c+3745,(((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                         ? 0U : ((4U 
                                                  == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                                   ? 0U
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeID)
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                                     ? (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeID)
                                                     : 0U))))))),4);
        vcdp->fullBit(c+3753,((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))));
        vcdp->fullBit(c+3761,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__ar_determined));
        vcdp->fullBus(c+3769,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_id),4);
        vcdp->fullBus(c+3777,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_addr),32);
        vcdp->fullBus(c+3785,(((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                         ? 0U : ((2U 
                                                  == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                                  ? 0U
                                                  : 
                                                 ((3U 
                                                   == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                                   ? (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readID)
                                                   : 0U))))),4);
        vcdp->fullBit(c+3793,(((IData)(vlTOPp->top_SoC__DOT__localMem__DOT__rburst_counter) 
                               == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__rlength))));
        vcdp->fullBit(c+3801,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                               & (1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)))));
        vcdp->fullBit(c+3809,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined));
        vcdp->fullBus(c+3817,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_id),4);
        vcdp->fullBus(c+3825,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr),32);
        vcdp->fullBit(c+3833,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                               & ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                  | (4U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))))));
        vcdp->fullBit(c+3841,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined));
        vcdp->fullBus(c+3849,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data),32);
        vcdp->fullBus(c+3857,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb),4);
        vcdp->fullBit(c+3865,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_last));
        vcdp->fullBit(c+3873,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                               & ((1U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                  & ((4U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                     & ((2U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                        & ((5U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                           & (3U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)))))))));
        vcdp->fullBus(c+3881,(((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                         ? 0U : ((4U 
                                                  == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                                   ? 0U
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeID)
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                                     ? (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeID)
                                                     : 0U))))))),4);
        vcdp->fullBit(c+3889,((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))));
        vcdp->fullBit(c+3897,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__ar_determined));
        vcdp->fullBus(c+3905,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_id),4);
        vcdp->fullBus(c+3913,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_addr),32);
        vcdp->fullBus(c+3921,(((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                         ? 0U : ((2U 
                                                  == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                                  ? 0U
                                                  : 
                                                 ((3U 
                                                   == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                                   ? (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readID)
                                                   : 0U))))),4);
        vcdp->fullBit(c+3929,(((IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__rburst_counter) 
                               == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__rlength))));
        vcdp->fullBus(c+3937,(vlTOPp->top_SoC__DOT__dma__DOT__mState),3);
        vcdp->fullBus(c+3945,(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState),2);
        vcdp->fullBus(c+3953,(vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg),32);
        vcdp->fullBit(c+3961,(vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv));
        vcdp->fullBit(c+3969,(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv));
        vcdp->fullBus(c+3977,(vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg),32);
        vcdp->fullBus(c+3985,(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg),32);
        vcdp->fullBit(c+3993,(vlTOPp->top_SoC__DOT__dma__DOT__mWriteAddrSent));
        vcdp->fullBit(c+4001,(vlTOPp->top_SoC__DOT__dma__DOT__mWriteDataSent));
        vcdp->fullBit(c+4009,(vlTOPp->top_SoC__DOT__dma__DOT__mReadlast));
        vcdp->fullBus(c+4017,(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_0),32);
        vcdp->fullBus(c+4025,(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_1),32);
        vcdp->fullBus(c+4033,(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_2),32);
        vcdp->fullBus(c+4041,(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3),32);
        vcdp->fullBus(c+4049,(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_4),32);
        vcdp->fullBus(c+4057,(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_5),32);
        vcdp->fullBus(c+4065,(vlTOPp->top_SoC__DOT__dma__DOT__data_buffer),32);
        vcdp->fullBus(c+4073,(vlTOPp->top_SoC__DOT__dma__DOT__source_offset),2);
        vcdp->fullBus(c+4081,(vlTOPp->top_SoC__DOT__dma__DOT__request_counter),32);
        vcdp->fullBus(c+4089,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg),32);
        vcdp->fullBus(c+4097,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg),32);
        vcdp->fullBus(c+4105,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__immReg),32);
        vcdp->fullBus(c+4113,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg),32);
        vcdp->fullBus(c+4121,(((IData)(4U) + vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__pcReg)),32);
        vcdp->fullBus(c+4129,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg),32);
        vcdp->fullBus(c+4137,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg),32);
        vcdp->fullBus(c+4145,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__alu_out_Reg),32);
        vcdp->fullBus(c+4153,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__ld_data_Reg),32);
        vcdp->fullBit(c+4161,((1U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                     >> 0xdU))));
        vcdp->fullBus(c+4169,((3U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg)),32);
        vcdp->fullBus(c+4177,((2U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg)),32);
        vcdp->fullBus(c+4185,(((2U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                             >> 0xcU)))
                                ? 0U : ((1U == (7U 
                                                & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                   >> 0xcU)))
                                         ? ((1U == 
                                             (2U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                             ? 0x10U
                                             : 0U) : 
                                        ((0U == (7U 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                    >> 0xcU)))
                                          ? ((3U == 
                                              (3U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                              ? 0x18U
                                              : ((2U 
                                                  == 
                                                  (3U 
                                                   & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                  ? 0x10U
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (3U 
                                                    & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                   ? 8U
                                                   : 0U)))
                                          : 0U)))),5);
        vcdp->fullBus(c+4193,(((2U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                             >> 0xcU)))
                                ? 0xffffffffU : ((1U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                      >> 0xcU)))
                                                  ? 
                                                 ((1U 
                                                   == 
                                                   (2U 
                                                    & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                   ? 0xffff0000U
                                                   : 0xffffU)
                                                  : 
                                                 ((0U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                       >> 0xcU)))
                                                   ? 
                                                  ((3U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                    ? 0xff000000U
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                     ? 0xff0000U
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (3U 
                                                       & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                      ? 0xff00U
                                                      : 0xffU)))
                                                   : 0xffffffffU)))),32);
        vcdp->fullBit(c+4201,(((0x23U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)))));
        vcdp->fullBus(c+4209,(vlTOPp->top_SoC__DOT__cpu__DOT__wState),2);
        vcdp->fullBus(c+4217,(vlTOPp->top_SoC__DOT__cpu__DOT__rState),2);
        vcdp->fullBus(c+4225,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg),15);
        vcdp->fullBus(c+4233,((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                        >> 0xfU))),5);
        vcdp->fullBus(c+4241,((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                        >> 0x14U))),5);
        vcdp->fullBus(c+4249,((0x1ffffffU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                             >> 7U))),25);
        vcdp->fullBus(c+4257,((0xffffff80U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)),32);
        vcdp->fullBus(c+4265,((0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)),7);
        vcdp->fullBus(c+4273,((0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)),7);
        vcdp->fullBus(c+4281,((7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                     >> 0xcU))),3);
        vcdp->fullBus(c+4289,((0x7fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                        >> 0x19U))),7);
        vcdp->fullBus(c+4297,((0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)),7);
        vcdp->fullBus(c+4305,((7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                     >> 0xcU))),3);
        vcdp->fullBus(c+4313,((0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)),7);
        vcdp->fullBus(c+4321,((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                        >> 7U))),5);
        vcdp->fullBus(c+4329,((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                        >> 7U))),5);
        vcdp->fullBus(c+4337,((0x7fffU & ((IData)(3U) 
                                          + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))),15);
        vcdp->fullBus(c+4345,((0x7fffU & ((IData)(2U) 
                                          + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))),15);
        vcdp->fullBus(c+4353,((0x7fffU & ((IData)(1U) 
                                          + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))),15);
        vcdp->fullBus(c+4361,(((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                                    ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_id))
                                : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                    ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                        ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_id))
                                    : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                        ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_id))))),4);
        vcdp->fullBus(c+4369,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                    ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                                        ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_resp))
                                    : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_resp))
                                        : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_resp))))
                                : 0U)),2);
        vcdp->fullBit(c+4377,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                               & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg) 
                                      | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last))
                                   : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                       ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg) 
                                          | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last))
                                       : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg) 
                                          | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last)))))));
        vcdp->fullBus(c+4385,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id)
                                    : 0U) : 0U)),4);
        vcdp->fullBus(c+4393,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                    ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg
                                    : 0U) : 0U)),32);
        vcdp->fullBus(c+4401,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                    ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size))
                                    : 0U) : 0U)),2);
        vcdp->fullBus(c+4409,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_id))),4);
        vcdp->fullBus(c+4417,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                ? 0U : vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data)),32);
        vcdp->fullBus(c+4425,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_resp))),2);
        vcdp->fullBit(c+4433,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg) 
                               | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last))));
        vcdp->fullBus(c+4441,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id)
                                    : 0U) : 0U)),4);
        vcdp->fullBus(c+4449,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                    ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg
                                    : 0U) : 0U)),32);
        vcdp->fullBus(c+4457,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                    ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size))
                                    : 0U) : 0U)),2);
        vcdp->fullBus(c+4465,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_id))),4);
        vcdp->fullBus(c+4473,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                ? 0U : vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data)),32);
        vcdp->fullBus(c+4481,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_resp))),2);
        vcdp->fullBit(c+4489,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg) 
                               | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last))));
        vcdp->fullBus(c+4497,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id)
                                    : 0U) : 0U)),4);
        vcdp->fullBus(c+4505,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                    ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg
                                    : 0U) : 0U)),32);
        vcdp->fullBus(c+4513,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                    ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size))
                                    : 0U) : 0U)),2);
        vcdp->fullBus(c+4521,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_id))),4);
        vcdp->fullBus(c+4529,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                                ? 0U : vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data)),32);
        vcdp->fullBus(c+4537,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_resp))),2);
        vcdp->fullBit(c+4545,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg) 
                               | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last))));
        vcdp->fullBus(c+4553,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id)
                                    : 0U) : 0U)),4);
        vcdp->fullBus(c+4561,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                    ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg
                                    : 0U) : 0U)),32);
        vcdp->fullBus(c+4569,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                    ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size))
                                    : 0U) : 0U)),2);
        vcdp->fullBit(c+4577,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                               & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
                                  & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))))));
        vcdp->fullBus(c+4585,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_id)
                                : 0U)),4);
        vcdp->fullBus(c+4593,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                ? vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data
                                : 0U)),32);
        vcdp->fullBus(c+4601,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_resp)
                                : 0U)),2);
        vcdp->fullBit(c+4609,((1U & ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)) 
                                     | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last)))));
        vcdp->fullBus(c+4617,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id)
                                    : 0U) : 0U)),4);
        vcdp->fullBus(c+4625,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                    ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg
                                    : 0U) : 0U)),32);
        vcdp->fullBus(c+4633,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                    ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size))
                                    : 0U) : 0U)),2);
        vcdp->fullBit(c+4641,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                               & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
                                  & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))))));
        vcdp->fullBus(c+4649,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_id)
                                : 0U)),4);
        vcdp->fullBus(c+4657,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                ? vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data
                                : 0U)),32);
        vcdp->fullBus(c+4665,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_resp)
                                : 0U)),2);
        vcdp->fullBit(c+4673,((1U & ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)) 
                                     | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last)))));
        vcdp->fullBus(c+4681,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id)
                                    : 0U) : 0U)),4);
        vcdp->fullBus(c+4689,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                    ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg
                                    : 0U) : 0U)),32);
        vcdp->fullBus(c+4697,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                    ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size))
                                    : 0U) : 0U)),2);
        vcdp->fullBit(c+4705,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                               & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
                                  & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))))));
        vcdp->fullBus(c+4713,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_id)
                                : 0U)),4);
        vcdp->fullBus(c+4721,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                                ? vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data
                                : 0U)),32);
        vcdp->fullBus(c+4729,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_resp)
                                : 0U)),2);
        vcdp->fullBit(c+4737,((1U & ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)) 
                                     | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last)))));
        vcdp->fullBus(c+4745,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_size),2);
        vcdp->fullBus(c+4753,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_size),2);
        vcdp->fullBus(c+4761,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_id),4);
        vcdp->fullBus(c+4769,((3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg))),2);
        vcdp->fullBus(c+4777,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id)
                                    : 0U) : 0U)),4);
        vcdp->fullBus(c+4785,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                    ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg
                                    : 0U) : 0U)),32);
        vcdp->fullBus(c+4793,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                    ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size))
                                    : 0U) : 0U)),2);
        vcdp->fullBus(c+4801,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id))),4);
        vcdp->fullBus(c+4809,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp))),2);
        vcdp->fullBus(c+4817,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id)
                                    : 0U) : 0U)),4);
        vcdp->fullBus(c+4825,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                    ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg
                                    : 0U) : 0U)),32);
        vcdp->fullBus(c+4833,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                    ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size))
                                    : 0U) : 0U)),2);
        vcdp->fullBus(c+4841,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id))),4);
        vcdp->fullBus(c+4849,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp))),2);
        vcdp->fullBus(c+4857,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id)
                                    : 0U) : 0U)),4);
        vcdp->fullBus(c+4865,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                    ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg
                                    : 0U) : 0U)),32);
        vcdp->fullBus(c+4873,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                    ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size))
                                    : 0U) : 0U)),2);
        vcdp->fullBus(c+4881,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id))),4);
        vcdp->fullBus(c+4889,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp))),2);
        vcdp->fullBus(c+4897,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                                ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id)
                                    : 0U) : 0U)),4);
        vcdp->fullBus(c+4905,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                                ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                    ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg
                                    : 0U) : 0U)),32);
        vcdp->fullBus(c+4913,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                                ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                    ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size))
                                    : 0U) : 0U)),2);
        vcdp->fullBus(c+4921,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id)
                                : 0U)),4);
        vcdp->fullBus(c+4929,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp)
                                : 0U)),2);
        vcdp->fullBus(c+4937,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                                ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id)
                                    : 0U) : 0U)),4);
        vcdp->fullBus(c+4945,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                                ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                    ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg
                                    : 0U) : 0U)),32);
        vcdp->fullBus(c+4953,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                                ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                    ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size))
                                    : 0U) : 0U)),2);
        vcdp->fullBus(c+4961,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id)
                                : 0U)),4);
        vcdp->fullBus(c+4969,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp)
                                : 0U)),2);
        vcdp->fullBus(c+4977,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id)
                                    : 0U) : 0U)),4);
        vcdp->fullBus(c+4985,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                    ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg
                                    : 0U) : 0U)),32);
        vcdp->fullBus(c+4993,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                                ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                    ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size))
                                    : 0U) : 0U)),2);
        vcdp->fullBus(c+5001,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id)
                                : 0U)),4);
        vcdp->fullBus(c+5009,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp)
                                : 0U)),2);
        vcdp->fullBus(c+5017,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_size),2);
        vcdp->fullBus(c+5025,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_size),2);
        vcdp->fullBus(c+5033,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg),3);
        vcdp->fullBus(c+5041,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg),32);
        vcdp->fullBus(c+5049,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id),4);
        vcdp->fullBus(c+5057,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size),3);
        vcdp->fullBit(c+5065,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid));
        vcdp->fullBit(c+5073,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding));
        vcdp->fullBus(c+5081,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg),3);
        vcdp->fullBus(c+5089,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg),32);
        vcdp->fullBus(c+5097,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id),4);
        vcdp->fullBus(c+5105,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size),3);
        vcdp->fullBit(c+5113,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid));
        vcdp->fullBit(c+5121,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding));
        vcdp->fullBus(c+5129,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state),2);
        vcdp->fullBit(c+5137,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg));
        vcdp->fullBus(c+5145,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_id),4);
        vcdp->fullBus(c+5153,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data),32);
        vcdp->fullBus(c+5161,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_resp),2);
        vcdp->fullBit(c+5169,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last));
        vcdp->fullBit(c+5177,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant));
        vcdp->fullBit(c+5185,((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant))));
        vcdp->fullBus(c+5193,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state),2);
        vcdp->fullBit(c+5201,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg));
        vcdp->fullBus(c+5209,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_id),4);
        vcdp->fullBus(c+5217,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data),32);
        vcdp->fullBus(c+5225,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_resp),2);
        vcdp->fullBit(c+5233,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last));
        vcdp->fullBit(c+5241,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant));
        vcdp->fullBit(c+5249,((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant))));
        vcdp->fullBus(c+5257,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state),2);
        vcdp->fullBit(c+5265,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg));
        vcdp->fullBus(c+5273,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_id),4);
        vcdp->fullBus(c+5281,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data),32);
        vcdp->fullBus(c+5289,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_resp),2);
        vcdp->fullBit(c+5297,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last));
        vcdp->fullBit(c+5305,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant));
        vcdp->fullBit(c+5313,((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant))));
        vcdp->fullBus(c+5321,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg),3);
        vcdp->fullBus(c+5329,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg),32);
        vcdp->fullBit(c+5337,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid));
        vcdp->fullBus(c+5345,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id),4);
        vcdp->fullBus(c+5353,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size),3);
        vcdp->fullBus(c+5361,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg),32);
        vcdp->fullBit(c+5369,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid));
        vcdp->fullBus(c+5377,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_strb),4);
        vcdp->fullBit(c+5385,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_last));
        vcdp->fullBus(c+5393,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg),4);
        vcdp->fullBit(c+5401,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding));
        vcdp->fullBit(c+5409,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding));
        vcdp->fullBit(c+5417,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding));
        vcdp->fullBus(c+5425,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg),3);
        vcdp->fullBus(c+5433,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg),32);
        vcdp->fullBit(c+5441,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid));
        vcdp->fullBus(c+5449,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id),4);
        vcdp->fullBus(c+5457,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size),3);
        vcdp->fullBus(c+5465,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg),32);
        vcdp->fullBit(c+5473,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid));
        vcdp->fullBus(c+5481,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_strb),4);
        vcdp->fullBit(c+5489,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_last));
        vcdp->fullBus(c+5497,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg),4);
        vcdp->fullBit(c+5505,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding));
        vcdp->fullBit(c+5513,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding));
        vcdp->fullBit(c+5521,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding));
        vcdp->fullBus(c+5529,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state),2);
        vcdp->fullBit(c+5537,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg));
        vcdp->fullBus(c+5545,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id),4);
        vcdp->fullBus(c+5553,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp),2);
        vcdp->fullBit(c+5561,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant));
        vcdp->fullBit(c+5569,((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant))));
        vcdp->fullBus(c+5577,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state),2);
        vcdp->fullBit(c+5585,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg));
        vcdp->fullBus(c+5593,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id),4);
        vcdp->fullBus(c+5601,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp),2);
        vcdp->fullBit(c+5609,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant));
        vcdp->fullBit(c+5617,((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant))));
        vcdp->fullBus(c+5625,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state),2);
        vcdp->fullBit(c+5633,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg));
        vcdp->fullBus(c+5641,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id),4);
        vcdp->fullBus(c+5649,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp),2);
        vcdp->fullBit(c+5657,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant));
        vcdp->fullBit(c+5665,((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant))));
        vcdp->fullBus(c+5673,((0x3fU & vlTOPp->top_SoC__DOT__localMem__DOT__rAddrOffset)),6);
        vcdp->fullBit(c+5681,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb)))));
        vcdp->fullBus(c+5689,((0x3fU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                         - (IData)(0x8000U)) 
                                        >> 2U))),6);
        vcdp->fullBit(c+5697,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb) 
                                        >> 1U)))));
        vcdp->fullBit(c+5705,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb) 
                                        >> 2U)))));
        vcdp->fullBit(c+5713,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb) 
                                        >> 3U)))));
        vcdp->fullBit(c+5721,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                               & ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined)))));
        vcdp->fullBus(c+5729,((0x3fU & vlTOPp->top_SoC__DOT__localMem__DOT__writeAddressReg)),6);
        vcdp->fullBit(c+5737,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                               & ((1U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                  & ((4U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined))))));
        vcdp->fullBus(c+5745,(vlTOPp->top_SoC__DOT__localMem__DOT__readID),4);
        vcdp->fullBus(c+5753,(vlTOPp->top_SoC__DOT__localMem__DOT__rAddrOffset),32);
        vcdp->fullBus(c+5761,((0x3fffffffU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                               - (IData)(0x8000U)) 
                                              >> 2U))),32);
        vcdp->fullBus(c+5769,(vlTOPp->top_SoC__DOT__localMem__DOT__writeAddressReg),32);
        vcdp->fullBus(c+5777,(vlTOPp->top_SoC__DOT__localMem__DOT__writeID),4);
        vcdp->fullBus(c+5785,(vlTOPp->top_SoC__DOT__localMem__DOT__writeState),3);
        vcdp->fullBus(c+5793,(vlTOPp->top_SoC__DOT__localMem__DOT__readState),2);
        vcdp->fullBus(c+5801,(vlTOPp->top_SoC__DOT__localMem__DOT__rLatencyCounter),8);
        vcdp->fullBus(c+5809,(vlTOPp->top_SoC__DOT__localMem__DOT__wLatencyCounter),8);
        vcdp->fullBus(c+5817,(vlTOPp->top_SoC__DOT__localMem__DOT__rlength),4);
        vcdp->fullBus(c+5825,(vlTOPp->top_SoC__DOT__localMem__DOT__rburst_counter),4);
        vcdp->fullBus(c+5833,((0x3fU & vlTOPp->top_SoC__DOT__globalMem__DOT__rAddrOffset)),6);
        vcdp->fullBit(c+5841,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb)))));
        vcdp->fullBus(c+5849,((0x3fU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                         - (IData)(0x10000U)) 
                                        >> 2U))),6);
        vcdp->fullBit(c+5857,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb) 
                                        >> 1U)))));
        vcdp->fullBit(c+5865,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb) 
                                        >> 2U)))));
        vcdp->fullBit(c+5873,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb) 
                                        >> 3U)))));
        vcdp->fullBit(c+5881,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                               & ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined)))));
        vcdp->fullBus(c+5889,((0x3fU & vlTOPp->top_SoC__DOT__globalMem__DOT__writeAddressReg)),6);
        vcdp->fullBit(c+5897,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                               & ((1U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                  & ((4U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined))))));
        vcdp->fullBus(c+5905,(vlTOPp->top_SoC__DOT__globalMem__DOT__readID),4);
        vcdp->fullBus(c+5913,(vlTOPp->top_SoC__DOT__globalMem__DOT__rAddrOffset),32);
        vcdp->fullBus(c+5921,((0x3fffffffU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                               - (IData)(0x10000U)) 
                                              >> 2U))),32);
        vcdp->fullBus(c+5929,(vlTOPp->top_SoC__DOT__globalMem__DOT__writeAddressReg),32);
        vcdp->fullBus(c+5937,(vlTOPp->top_SoC__DOT__globalMem__DOT__writeID),4);
        vcdp->fullBus(c+5945,(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState),3);
        vcdp->fullBus(c+5953,(vlTOPp->top_SoC__DOT__globalMem__DOT__readState),2);
        vcdp->fullBus(c+5961,(vlTOPp->top_SoC__DOT__globalMem__DOT__rLatencyCounter),8);
        vcdp->fullBus(c+5969,(vlTOPp->top_SoC__DOT__globalMem__DOT__wLatencyCounter),8);
        vcdp->fullBus(c+5977,(vlTOPp->top_SoC__DOT__globalMem__DOT__rlength),4);
        vcdp->fullBus(c+5985,(vlTOPp->top_SoC__DOT__globalMem__DOT__rburst_counter),4);
        vcdp->fullBit(c+5993,(vlTOPp->clock));
        vcdp->fullBit(c+6001,(vlTOPp->reset));
        vcdp->fullBus(c+6009,(vlTOPp->io_regs_0),32);
        vcdp->fullBus(c+6017,(vlTOPp->io_regs_1),32);
        vcdp->fullBus(c+6025,(vlTOPp->io_regs_2),32);
        vcdp->fullBus(c+6033,(vlTOPp->io_regs_3),32);
        vcdp->fullBus(c+6041,(vlTOPp->io_regs_4),32);
        vcdp->fullBus(c+6049,(vlTOPp->io_regs_5),32);
        vcdp->fullBus(c+6057,(vlTOPp->io_regs_6),32);
        vcdp->fullBus(c+6065,(vlTOPp->io_regs_7),32);
        vcdp->fullBus(c+6073,(vlTOPp->io_regs_8),32);
        vcdp->fullBus(c+6081,(vlTOPp->io_regs_9),32);
        vcdp->fullBus(c+6089,(vlTOPp->io_regs_10),32);
        vcdp->fullBus(c+6097,(vlTOPp->io_regs_11),32);
        vcdp->fullBus(c+6105,(vlTOPp->io_regs_12),32);
        vcdp->fullBus(c+6113,(vlTOPp->io_regs_13),32);
        vcdp->fullBus(c+6121,(vlTOPp->io_regs_14),32);
        vcdp->fullBus(c+6129,(vlTOPp->io_regs_15),32);
        vcdp->fullBus(c+6137,(vlTOPp->io_regs_16),32);
        vcdp->fullBus(c+6145,(vlTOPp->io_regs_17),32);
        vcdp->fullBus(c+6153,(vlTOPp->io_regs_18),32);
        vcdp->fullBus(c+6161,(vlTOPp->io_regs_19),32);
        vcdp->fullBus(c+6169,(vlTOPp->io_regs_20),32);
        vcdp->fullBus(c+6177,(vlTOPp->io_regs_21),32);
        vcdp->fullBus(c+6185,(vlTOPp->io_regs_22),32);
        vcdp->fullBus(c+6193,(vlTOPp->io_regs_23),32);
        vcdp->fullBus(c+6201,(vlTOPp->io_regs_24),32);
        vcdp->fullBus(c+6209,(vlTOPp->io_regs_25),32);
        vcdp->fullBus(c+6217,(vlTOPp->io_regs_26),32);
        vcdp->fullBus(c+6225,(vlTOPp->io_regs_27),32);
        vcdp->fullBus(c+6233,(vlTOPp->io_regs_28),32);
        vcdp->fullBus(c+6241,(vlTOPp->io_regs_29),32);
        vcdp->fullBus(c+6249,(vlTOPp->io_regs_30),32);
        vcdp->fullBus(c+6257,(vlTOPp->io_regs_31),32);
        vcdp->fullBit(c+6265,(vlTOPp->io_Hcf));
        vcdp->fullBus(c+6273,(vlTOPp->io_inst),32);
        vcdp->fullBus(c+6281,(vlTOPp->io_rdata),32);
        vcdp->fullBus(c+6289,(vlTOPp->io_wdata),32);
        vcdp->fullBit(c+6297,(vlTOPp->io_Dump_Mem));
        vcdp->fullBit(c+6305,(vlTOPp->io_E_Branch_taken));
        vcdp->fullBit(c+6313,(vlTOPp->io_Flush));
        vcdp->fullBit(c+6321,(vlTOPp->io_Stall_MA));
        vcdp->fullBit(c+6329,(vlTOPp->io_Stall_DH));
        vcdp->fullBus(c+6337,(vlTOPp->io_IF_PC),32);
        vcdp->fullBus(c+6345,(vlTOPp->io_ID_PC),32);
        vcdp->fullBus(c+6353,(vlTOPp->io_EXE_PC),32);
        vcdp->fullBus(c+6361,(vlTOPp->io_MEM_PC),32);
        vcdp->fullBus(c+6369,(vlTOPp->io_WB_PC),32);
        vcdp->fullBus(c+6377,(vlTOPp->io_EXE_alu_out),32);
        vcdp->fullBus(c+6385,(vlTOPp->io_EXE_src1),32);
        vcdp->fullBus(c+6393,(vlTOPp->io_EXE_src2),32);
        vcdp->fullBus(c+6401,(vlTOPp->io_ALU_src1),32);
        vcdp->fullBus(c+6409,(vlTOPp->io_ALU_src2),32);
        vcdp->fullBus(c+6417,(vlTOPp->io_raddr),32);
        vcdp->fullBus(c+6425,(vlTOPp->io_WB_rd),5);
        vcdp->fullBus(c+6433,(vlTOPp->io_WB_wdata),32);
        vcdp->fullBit(c+6441,(vlTOPp->io_EXE_Jump));
        vcdp->fullBit(c+6449,(vlTOPp->io_EXE_Branch));
        vcdp->fullBit(c+6457,(vlTOPp->io_DMA_Hcf));
        vcdp->fullBus(c+6465,(0U),4);
        vcdp->fullBus(c+6473,(0U),8);
        vcdp->fullBus(c+6481,(0U),2);
        vcdp->fullBit(c+6489,(0U));
        vcdp->fullBus(c+6497,(0U),3);
        vcdp->fullBit(c+6505,(1U));
        vcdp->fullBus(c+6513,(2U),2);
        vcdp->fullBus(c+6521,(0U),6);
        vcdp->fullBus(c+6529,(1U),6);
        vcdp->fullBus(c+6537,(2U),6);
        vcdp->fullBus(c+6545,(3U),6);
        vcdp->fullBus(c+6553,(4U),6);
        vcdp->fullBus(c+6561,(5U),6);
        vcdp->fullBus(c+6569,(6U),6);
        vcdp->fullBus(c+6577,(7U),6);
        vcdp->fullBus(c+6585,(8U),6);
        vcdp->fullBus(c+6593,(9U),6);
        vcdp->fullBus(c+6601,(0xaU),6);
        vcdp->fullBus(c+6609,(0xbU),6);
        vcdp->fullBus(c+6617,(0xcU),6);
        vcdp->fullBus(c+6625,(0xdU),6);
        vcdp->fullBus(c+6633,(0xeU),6);
        vcdp->fullBus(c+6641,(0xfU),6);
        vcdp->fullBus(c+6649,(0x10U),6);
        vcdp->fullBus(c+6657,(0x11U),6);
        vcdp->fullBus(c+6665,(0x12U),6);
        vcdp->fullBus(c+6673,(0x13U),6);
        vcdp->fullBus(c+6681,(0x14U),6);
        vcdp->fullBus(c+6689,(0x15U),6);
        vcdp->fullBus(c+6697,(0x16U),6);
        vcdp->fullBus(c+6705,(0x17U),6);
        vcdp->fullBus(c+6713,(0x18U),6);
        vcdp->fullBus(c+6721,(0x19U),6);
        vcdp->fullBus(c+6729,(0x1aU),6);
        vcdp->fullBus(c+6737,(0x1bU),6);
        vcdp->fullBus(c+6745,(0x1cU),6);
        vcdp->fullBus(c+6753,(0x1dU),6);
        vcdp->fullBus(c+6761,(0x1eU),6);
        vcdp->fullBus(c+6769,(0x1fU),6);
        vcdp->fullBus(c+6777,(0x20U),6);
        vcdp->fullBus(c+6785,(0x21U),6);
        vcdp->fullBus(c+6793,(0x22U),6);
        vcdp->fullBus(c+6801,(0x23U),6);
        vcdp->fullBus(c+6809,(0x24U),6);
        vcdp->fullBus(c+6817,(0x25U),6);
        vcdp->fullBus(c+6825,(0x26U),6);
        vcdp->fullBus(c+6833,(0x27U),6);
        vcdp->fullBus(c+6841,(0x28U),6);
        vcdp->fullBus(c+6849,(0x29U),6);
        vcdp->fullBus(c+6857,(0x2aU),6);
        vcdp->fullBus(c+6865,(0x2bU),6);
        vcdp->fullBus(c+6873,(0x2cU),6);
        vcdp->fullBus(c+6881,(0x2dU),6);
        vcdp->fullBus(c+6889,(0x2eU),6);
        vcdp->fullBus(c+6897,(0x2fU),6);
        vcdp->fullBus(c+6905,(0x30U),6);
        vcdp->fullBus(c+6913,(0x31U),6);
        vcdp->fullBus(c+6921,(0x32U),6);
        vcdp->fullBus(c+6929,(0x33U),6);
        vcdp->fullBus(c+6937,(0x34U),6);
        vcdp->fullBus(c+6945,(0x35U),6);
        vcdp->fullBus(c+6953,(0x36U),6);
        vcdp->fullBus(c+6961,(0x37U),6);
        vcdp->fullBus(c+6969,(0x38U),6);
        vcdp->fullBus(c+6977,(0x39U),6);
        vcdp->fullBus(c+6985,(0x3aU),6);
        vcdp->fullBus(c+6993,(0x3bU),6);
        vcdp->fullBus(c+7001,(0x3cU),6);
        vcdp->fullBus(c+7009,(0x3dU),6);
        vcdp->fullBus(c+7017,(0x3eU),6);
        vcdp->fullBus(c+7025,(0x3fU),6);
        vcdp->fullBus(c+7033,(vlTOPp->top_SoC__DOT__localMem__DOT__initvar),32);
        vcdp->fullBus(c+7041,(vlTOPp->top_SoC__DOT__globalMem__DOT__initvar),32);
    }
}
