// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_SoC__Syms.h"


//======================

void Vtop_SoC::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop_SoC* t = (Vtop_SoC*)userthis;
    Vtop_SoC__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vtop_SoC::traceChgThis(Vtop_SoC__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop_SoC::traceChgThis__2(Vtop_SoC__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(((IData)(vlTOPp->top_SoC__DOT__dma__DOT___io_slave_aw_ready_T_2) 
                           & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv)))));
        vcdp->chgBit(c+9,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready));
        vcdp->chgBit(c+17,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_out_readData_ready));
        vcdp->chgBit(c+25,(vlTOPp->top_SoC__DOT__dma_io_master_aw_valid));
        vcdp->chgBus(c+33,((IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38)),32);
        vcdp->chgBus(c+41,((IData)((VL_ULL(0x7fffffffffffffff) 
                                    & ((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                        ? ((QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__data_buffer)) 
                                           << (0x18U 
                                               & ((IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38) 
                                                  << 3U)))
                                        : (QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__data_buffer)))))),32);
        vcdp->chgBus(c+49,(((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                             ? (0xfU & ((IData)(vlTOPp->top_SoC__DOT__dma__DOT__mask_width) 
                                        << (3U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38))))
                             : 0xfU)),4);
        vcdp->chgBus(c+57,((IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_24)),32);
        vcdp->chgBit(c+65,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid));
        vcdp->chgBus(c+73,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data),32);
        vcdp->chgBus(c+81,(vlTOPp->top_SoC__DOT__im_io_inst),32);
        vcdp->chgBus(c+89,(vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr),32);
        vcdp->chgBus(c+97,((IData)(vlTOPp->top_SoC__DOT__cpu__DOT___GEN_8)),32);
        vcdp->chgBit(c+105,(vlTOPp->top_SoC__DOT__cpu_io_master_b_ready));
        vcdp->chgBus(c+113,(vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr),32);
        vcdp->chgBit(c+121,(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready));
        vcdp->chgBit(c+129,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_valid));
        vcdp->chgBus(c+137,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_bits_data),32);
        vcdp->chgBit(c+145,((0xbU == (0x7fU & vlTOPp->top_SoC__DOT__im_io_inst))));
        vcdp->chgBit(c+153,(((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                             | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                                | ((0x63U == (0x7fU 
                                              & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                                   & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___E_Branch_taken_T_14))))));
        vcdp->chgBit(c+161,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH));
        vcdp->chgBit(c+169,(vlTOPp->top_SoC__DOT__cpu_io_Stall_MA));
        vcdp->chgBit(c+177,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH));
        vcdp->chgBus(c+185,(((2U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ASel))
                              ? 0U : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT___alu_src1_T_3)),32);
        vcdp->chgBus(c+193,(((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_BSel)
                              ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__immReg
                              : vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg)),32);
        vcdp->chgBus(c+201,((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10)),32);
        vcdp->chgBus(c+209,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata),32);
        vcdp->chgBit(c+217,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_out_writeResp_ready));
        vcdp->chgBit(c+225,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_out_readData_ready));
        vcdp->chgBit(c+233,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)) 
                             & (IData)(vlTOPp->top_SoC__DOT__localMem__DOT___GEN_29))));
        vcdp->chgBus(c+241,(((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                              ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                       ? 0U : ((2U 
                                                == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                                ? 0U
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                                    ? 
                                                   vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                                   [
                                                   (0x3fU 
                                                    & vlTOPp->top_SoC__DOT__localMem__DOT__rAddrOffset)]
                                                    : 0U))))),32);
        vcdp->chgBit(c+249,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_out_writeResp_ready));
        vcdp->chgBit(c+257,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_out_readData_ready));
        vcdp->chgBit(c+265,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)) 
                             & (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_29))));
        vcdp->chgBus(c+273,(((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                              ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                       ? 0U : ((2U 
                                                == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                                ? 0U
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                                    ? 
                                                   vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                                   [
                                                   (0x3fU 
                                                    & vlTOPp->top_SoC__DOT__globalMem__DOT__rAddrOffset)]
                                                    : 0U))))),32);
        vcdp->chgBus(c+281,((3U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38))),2);
        vcdp->chgBus(c+289,(vlTOPp->top_SoC__DOT__dma__DOT__mask_width),4);
        vcdp->chgBus(c+297,((0xfU & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_32))),4);
        vcdp->chgBus(c+305,((((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                              ? ((2U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_32))
                                  ? (0xffU & (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data 
                                              >> 8U))
                                  : 0U) : 0U)),8);
        vcdp->chgBus(c+313,((((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                              ? ((1U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_32))
                                  ? (0xffU & vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data)
                                  : 0U) : 0U)),8);
        vcdp->chgBus(c+321,((((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                              ? ((8U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_32))
                                  ? (0xffU & (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data 
                                              >> 0x18U))
                                  : 0U) : 0U)),8);
        vcdp->chgBus(c+329,((((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                              ? ((4U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_32))
                                  ? (0xffU & (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data 
                                              >> 0x10U))
                                  : 0U) : 0U)),8);
        vcdp->chgBit(c+337,((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH) 
                              | (IData)(vlTOPp->top_SoC__DOT__cpu_io_Stall_MA)) 
                             & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)))));
        vcdp->chgBus(c+345,(((2U == ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)
                                      ? 2U : 0U)) ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10)
                              : ((1U == ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)
                                          ? 2U : 0U))
                                  ? ((IData)(4U) + vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg)
                                  : ((IData)(4U) + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg)))),32);
        vcdp->chgBit(c+353,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID_io_Stall));
        vcdp->chgBit(c+361,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Flush));
        vcdp->chgBit(c+369,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall));
        vcdp->chgBus(c+377,(((0x1fU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                 >> 0xfU)))
                              ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31
                              : ((0x1eU == (0x1fU & 
                                            (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
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
        vcdp->chgBus(c+385,(((0x1fU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                 >> 0x14U)))
                              ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31
                              : ((0x1eU == (0x1fU & 
                                            (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
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
        vcdp->chgBus(c+393,(((4U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel))
                              ? ((0xffe00000U & (VL_NEGATE_I((IData)(
                                                                     (1U 
                                                                      & (vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_22 
                                                                         >> 0x14U)))) 
                                                 << 0x15U)) 
                                 | vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_22)
                              : ((5U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel))
                                  ? (0xfffff000U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)
                                  : ((0xffffe000U & 
                                      (VL_NEGATE_I((IData)(
                                                           (1U 
                                                            & ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_30) 
                                                               >> 0xcU)))) 
                                       << 0xdU)) | (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_30))))),32);
        vcdp->chgBus(c+401,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_MEM_io_Mem_Data),32);
        vcdp->chgBus(c+409,(((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)
                              ? 2U : 0U)),2);
        vcdp->chgBit(c+417,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn));
        vcdp->chgBus(c+425,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel),3);
        vcdp->chgBus(c+433,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ASel),2);
        vcdp->chgBit(c+441,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_BSel));
        vcdp->chgBus(c+449,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel),15);
        vcdp->chgBit(c+457,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrEq));
        vcdp->chgBit(c+465,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT));
        vcdp->chgBus(c+473,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_WBSel),2);
        vcdp->chgBit(c+481,(((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                             & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_valid)))));
        vcdp->chgBus(c+489,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1),32);
        vcdp->chgBus(c+497,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2),32);
        vcdp->chgBus(c+505,((0x7fU & vlTOPp->top_SoC__DOT__im_io_inst)),7);
        vcdp->chgBit(c+513,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__E_Branch_taken));
        vcdp->chgBit(c+521,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1));
        vcdp->chgBit(c+529,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2));
        vcdp->chgBit(c+537,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd));
        vcdp->chgBit(c+545,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd));
        vcdp->chgBit(c+553,(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd));
        vcdp->chgBit(c+561,(((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1) 
                               & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd)) 
                              & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 0xfU)) 
                                 == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                              >> 7U)))) 
                             & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                                >> 7U))))));
        vcdp->chgBit(c+569,(((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2) 
                               & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd)) 
                              & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 0x14U)) 
                                 == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                              >> 7U)))) 
                             & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                                >> 7U))))));
        vcdp->chgBit(c+577,(((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1) 
                               & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd)) 
                              & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 0xfU)) 
                                 == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                              >> 7U)))) 
                             & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                >> 7U))))));
        vcdp->chgBit(c+585,(((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2) 
                               & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd)) 
                              & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 0x14U)) 
                                 == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                              >> 7U)))) 
                             & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                >> 7U))))));
        vcdp->chgBit(c+593,(((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1) 
                               & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd)) 
                              & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 0xfU)) 
                                 == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                              >> 7U)))) 
                             & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                                >> 7U))))));
        vcdp->chgBit(c+601,(((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2) 
                               & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd)) 
                              & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 0x14U)) 
                                 == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                              >> 7U)))) 
                             & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                                >> 7U))))));
        vcdp->chgBus(c+609,(vlTOPp->top_SoC__DOT__im__DOT__memory
                            [(0x7fffU & ((IData)(3U) 
                                         + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))]),8);
        vcdp->chgBus(c+617,(vlTOPp->top_SoC__DOT__im__DOT__memory
                            [(0x7fffU & ((IData)(2U) 
                                         + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))]),8);
        vcdp->chgBus(c+625,(vlTOPp->top_SoC__DOT__im__DOT__memory
                            [(0x7fffU & ((IData)(1U) 
                                         + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))]),8);
        vcdp->chgBus(c+633,(vlTOPp->top_SoC__DOT__im__DOT__memory
                            [(0x7fffU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg)]),8);
        vcdp->chgBus(c+641,(((vlTOPp->top_SoC__DOT__im__DOT__memory
                              [(0x7fffU & ((IData)(1U) 
                                           + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))] 
                              << 8U) | vlTOPp->top_SoC__DOT__im__DOT__memory
                             [(0x7fffU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg)])),16);
        vcdp->chgBus(c+649,(((vlTOPp->top_SoC__DOT__im__DOT__memory
                              [(0x7fffU & ((IData)(3U) 
                                           + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))] 
                              << 8U) | vlTOPp->top_SoC__DOT__im__DOT__memory
                             [(0x7fffU & ((IData)(2U) 
                                          + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))])),16);
        vcdp->chgBit(c+657,(((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1)) 
                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0))));
        vcdp->chgBit(c+665,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_0_readAddr_valid));
        vcdp->chgBit(c+673,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                             & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
                                & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready)))));
        vcdp->chgBit(c+681,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_0_readData_valid));
        vcdp->chgBit(c+689,(((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1)) 
                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0))));
        vcdp->chgBit(c+697,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_1_readAddr_valid));
        vcdp->chgBit(c+705,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                             & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
                                & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready)))));
        vcdp->chgBit(c+713,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_0_readData_valid));
        vcdp->chgBit(c+721,(((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1)) 
                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0))));
        vcdp->chgBit(c+729,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_2_readAddr_valid));
        vcdp->chgBit(c+737,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                             & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
                                & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready)))));
        vcdp->chgBit(c+745,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_0_readData_valid));
        vcdp->chgBit(c+753,((((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant)) 
                              | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                    | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid)))) 
                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0))));
        vcdp->chgBit(c+761,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_0_readAddr_valid));
        vcdp->chgBit(c+769,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_1_readData_valid));
        vcdp->chgBit(c+777,((((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant)) 
                              | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                    | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid)))) 
                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0))));
        vcdp->chgBit(c+785,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_1_readAddr_valid));
        vcdp->chgBit(c+793,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_1_readData_valid));
        vcdp->chgBit(c+801,((((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant)) 
                              | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                    | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid)))) 
                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0))));
        vcdp->chgBit(c+809,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_2_readAddr_valid));
        vcdp->chgBit(c+817,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_1_readData_valid));
        vcdp->chgBit(c+825,(((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1)) 
                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0))));
        vcdp->chgBit(c+833,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeAddr_valid));
        vcdp->chgBit(c+841,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeData_ready));
        vcdp->chgBit(c+849,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_valid));
        vcdp->chgBus(c+857,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_data),32);
        vcdp->chgBus(c+865,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_strb),4);
        vcdp->chgBit(c+873,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_last));
        vcdp->chgBit(c+881,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeResp_ready));
        vcdp->chgBit(c+889,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeResp_valid));
        vcdp->chgBit(c+897,(((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1)) 
                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0))));
        vcdp->chgBit(c+905,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeAddr_valid));
        vcdp->chgBit(c+913,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeData_ready));
        vcdp->chgBit(c+921,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_valid));
        vcdp->chgBus(c+929,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_data),32);
        vcdp->chgBus(c+937,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_strb),4);
        vcdp->chgBit(c+945,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_last));
        vcdp->chgBit(c+953,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeResp_ready));
        vcdp->chgBit(c+961,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeResp_valid));
        vcdp->chgBit(c+969,(((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1)) 
                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0))));
        vcdp->chgBit(c+977,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeAddr_valid));
        vcdp->chgBit(c+985,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeData_ready));
        vcdp->chgBit(c+993,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_valid));
        vcdp->chgBus(c+1001,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_data),32);
        vcdp->chgBus(c+1009,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_strb),4);
        vcdp->chgBit(c+1017,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_last));
        vcdp->chgBit(c+1025,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeResp_ready));
        vcdp->chgBit(c+1033,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeResp_valid));
        vcdp->chgBit(c+1041,((((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant)) 
                               | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                     | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid)))) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0))));
        vcdp->chgBit(c+1049,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeAddr_valid));
        vcdp->chgBit(c+1057,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeData_ready));
        vcdp->chgBit(c+1065,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_valid));
        vcdp->chgBus(c+1073,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_data),32);
        vcdp->chgBus(c+1081,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_strb),4);
        vcdp->chgBit(c+1089,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_last));
        vcdp->chgBit(c+1097,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeResp_ready));
        vcdp->chgBit(c+1105,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeResp_valid));
        vcdp->chgBit(c+1113,((((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant)) 
                               | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                     | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid)))) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0))));
        vcdp->chgBit(c+1121,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeAddr_valid));
        vcdp->chgBit(c+1129,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeData_ready));
        vcdp->chgBit(c+1137,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_valid));
        vcdp->chgBus(c+1145,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_data),32);
        vcdp->chgBus(c+1153,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_strb),4);
        vcdp->chgBit(c+1161,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_last));
        vcdp->chgBit(c+1169,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeResp_ready));
        vcdp->chgBit(c+1177,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeResp_valid));
        vcdp->chgBit(c+1185,((((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant)) 
                               | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                     | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid)))) 
                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0))));
        vcdp->chgBit(c+1193,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeAddr_valid));
        vcdp->chgBit(c+1201,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeData_ready));
        vcdp->chgBit(c+1209,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_valid));
        vcdp->chgBus(c+1217,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_data),32);
        vcdp->chgBus(c+1225,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_strb),4);
        vcdp->chgBit(c+1233,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_last));
        vcdp->chgBit(c+1241,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeResp_ready));
        vcdp->chgBit(c+1249,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeResp_valid));
        vcdp->chgBus(c+1257,(((0x64U > vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr)
                               ? 0U : (((0x8000U <= vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr) 
                                        & (0x8800U 
                                           > vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr))
                                        ? 1U : (((0x10000U 
                                                  <= vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr) 
                                                 & (0x10800U 
                                                    > vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr))
                                                 ? 2U
                                                 : 0U)))),2);
        vcdp->chgBus(c+1265,(((0x64U > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_24))
                               ? 0U : (((0x8000U <= (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_24)) 
                                        & (0x8800U 
                                           > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_24)))
                                        ? 1U : (((0x10000U 
                                                  <= (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_24)) 
                                                 & (0x10800U 
                                                    > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_24)))
                                                 ? 2U
                                                 : 0U)))),2);
        vcdp->chgBit(c+1273,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1)))));
        vcdp->chgBit(c+1281,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid));
        vcdp->chgBit(c+1289,((1U & ((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant)) 
                                    | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                          | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid)))))));
        vcdp->chgBit(c+1297,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_1_valid));
        vcdp->chgBit(c+1305,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_out_valid));
        vcdp->chgBit(c+1313,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_chosen));
        vcdp->chgBit(c+1321,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_0_readAddr_valid) 
                              | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_0_readAddr_valid))));
        vcdp->chgBit(c+1329,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0));
        vcdp->chgBit(c+1337,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1));
        vcdp->chgBit(c+1345,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                       | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid))))));
        vcdp->chgBit(c+1353,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1)))));
        vcdp->chgBit(c+1361,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid));
        vcdp->chgBit(c+1369,((1U & ((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant)) 
                                    | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                          | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid)))))));
        vcdp->chgBit(c+1377,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_1_valid));
        vcdp->chgBit(c+1385,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_out_valid));
        vcdp->chgBit(c+1393,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_chosen));
        vcdp->chgBit(c+1401,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_1_readAddr_valid) 
                              | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_1_readAddr_valid))));
        vcdp->chgBit(c+1409,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0));
        vcdp->chgBit(c+1417,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1));
        vcdp->chgBit(c+1425,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                       | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid))))));
        vcdp->chgBit(c+1433,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1)))));
        vcdp->chgBit(c+1441,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid));
        vcdp->chgBit(c+1449,((1U & ((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant)) 
                                    | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                          | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid)))))));
        vcdp->chgBit(c+1457,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_1_valid));
        vcdp->chgBit(c+1465,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_out_valid));
        vcdp->chgBit(c+1473,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_chosen));
        vcdp->chgBit(c+1481,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_2_readAddr_valid) 
                              | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_2_readAddr_valid))));
        vcdp->chgBit(c+1489,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0));
        vcdp->chgBit(c+1497,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1));
        vcdp->chgBit(c+1505,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                       | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid))))));
        vcdp->chgBus(c+1513,(((0x64U > vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr)
                               ? 0U : (((0x8000U <= vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr) 
                                        & (0x8800U 
                                           > vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr))
                                        ? 1U : (((0x10000U 
                                                  <= vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr) 
                                                 & (0x10800U 
                                                    > vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr))
                                                 ? 2U
                                                 : 0U)))),2);
        vcdp->chgBus(c+1521,(((0x64U > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38))
                               ? 0U : (((0x8000U <= (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38)) 
                                        & (0x8800U 
                                           > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38)))
                                        ? 1U : (((0x10000U 
                                                  <= (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38)) 
                                                 & (0x10800U 
                                                    > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_38)))
                                                 ? 2U
                                                 : 0U)))),2);
        vcdp->chgBit(c+1529,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1)))));
        vcdp->chgBit(c+1537,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid));
        vcdp->chgBit(c+1545,((1U & ((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant)) 
                                    | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                          | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid)))))));
        vcdp->chgBit(c+1553,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_1_valid));
        vcdp->chgBit(c+1561,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid));
        vcdp->chgBit(c+1569,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen));
        vcdp->chgBit(c+1577,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeAddr_valid) 
                              | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeAddr_valid))));
        vcdp->chgBit(c+1585,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0));
        vcdp->chgBit(c+1593,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1));
        vcdp->chgBit(c+1601,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                       | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid))))));
        vcdp->chgBit(c+1609,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1)))));
        vcdp->chgBit(c+1617,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid));
        vcdp->chgBit(c+1625,((1U & ((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant)) 
                                    | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                          | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid)))))));
        vcdp->chgBit(c+1633,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_1_valid));
        vcdp->chgBit(c+1641,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid));
        vcdp->chgBit(c+1649,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen));
        vcdp->chgBit(c+1657,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeAddr_valid) 
                              | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeAddr_valid))));
        vcdp->chgBit(c+1665,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0));
        vcdp->chgBit(c+1673,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1));
        vcdp->chgBit(c+1681,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                       | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid))))));
        vcdp->chgBit(c+1689,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1)))));
        vcdp->chgBit(c+1697,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid));
        vcdp->chgBit(c+1705,((1U & ((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant)) 
                                    | (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                          | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid)))))));
        vcdp->chgBit(c+1713,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_1_valid));
        vcdp->chgBit(c+1721,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid));
        vcdp->chgBit(c+1729,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen));
        vcdp->chgBit(c+1737,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeAddr_valid) 
                              | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeAddr_valid))));
        vcdp->chgBit(c+1745,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0));
        vcdp->chgBit(c+1753,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1));
        vcdp->chgBit(c+1761,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                       | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid))))));
        vcdp->chgBit(c+1769,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)) 
                              & (IData)(vlTOPp->top_SoC__DOT__localMem__DOT___GEN_29))));
        vcdp->chgBus(c+1777,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [(0x3fU & vlTOPp->top_SoC__DOT__localMem__DOT__rAddrOffset)]),32);
        vcdp->chgBus(c+1785,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [(0x3fU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                         - (IData)(0x8000U)) 
                                        >> 2U))]),32);
        vcdp->chgBus(c+1793,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0U]),32);
        vcdp->chgBus(c+1801,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [1U]),32);
        vcdp->chgBus(c+1809,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [2U]),32);
        vcdp->chgBus(c+1817,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [3U]),32);
        vcdp->chgBus(c+1825,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [4U]),32);
        vcdp->chgBus(c+1833,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [5U]),32);
        vcdp->chgBus(c+1841,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [6U]),32);
        vcdp->chgBus(c+1849,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [7U]),32);
        vcdp->chgBus(c+1857,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [8U]),32);
        vcdp->chgBus(c+1865,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [9U]),32);
        vcdp->chgBus(c+1873,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0xaU]),32);
        vcdp->chgBus(c+1881,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0xbU]),32);
        vcdp->chgBus(c+1889,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0xcU]),32);
        vcdp->chgBus(c+1897,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0xdU]),32);
        vcdp->chgBus(c+1905,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0xeU]),32);
        vcdp->chgBus(c+1913,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0xfU]),32);
        vcdp->chgBus(c+1921,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x10U]),32);
        vcdp->chgBus(c+1929,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x11U]),32);
        vcdp->chgBus(c+1937,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x12U]),32);
        vcdp->chgBus(c+1945,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x13U]),32);
        vcdp->chgBus(c+1953,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x14U]),32);
        vcdp->chgBus(c+1961,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x15U]),32);
        vcdp->chgBus(c+1969,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x16U]),32);
        vcdp->chgBus(c+1977,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x17U]),32);
        vcdp->chgBus(c+1985,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x18U]),32);
        vcdp->chgBus(c+1993,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x19U]),32);
        vcdp->chgBus(c+2001,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x1aU]),32);
        vcdp->chgBus(c+2009,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x1bU]),32);
        vcdp->chgBus(c+2017,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x1cU]),32);
        vcdp->chgBus(c+2025,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x1dU]),32);
        vcdp->chgBus(c+2033,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x1eU]),32);
        vcdp->chgBus(c+2041,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x1fU]),32);
        vcdp->chgBus(c+2049,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x20U]),32);
        vcdp->chgBus(c+2057,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x21U]),32);
        vcdp->chgBus(c+2065,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x22U]),32);
        vcdp->chgBus(c+2073,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x23U]),32);
        vcdp->chgBus(c+2081,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x24U]),32);
        vcdp->chgBus(c+2089,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x25U]),32);
        vcdp->chgBus(c+2097,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x26U]),32);
        vcdp->chgBus(c+2105,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x27U]),32);
        vcdp->chgBus(c+2113,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x28U]),32);
        vcdp->chgBus(c+2121,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x29U]),32);
        vcdp->chgBus(c+2129,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x2aU]),32);
        vcdp->chgBus(c+2137,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x2bU]),32);
        vcdp->chgBus(c+2145,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x2cU]),32);
        vcdp->chgBus(c+2153,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x2dU]),32);
        vcdp->chgBus(c+2161,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x2eU]),32);
        vcdp->chgBus(c+2169,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x2fU]),32);
        vcdp->chgBus(c+2177,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x30U]),32);
        vcdp->chgBus(c+2185,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x31U]),32);
        vcdp->chgBus(c+2193,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x32U]),32);
        vcdp->chgBus(c+2201,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x33U]),32);
        vcdp->chgBus(c+2209,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x34U]),32);
        vcdp->chgBus(c+2217,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x35U]),32);
        vcdp->chgBus(c+2225,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x36U]),32);
        vcdp->chgBus(c+2233,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x37U]),32);
        vcdp->chgBus(c+2241,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x38U]),32);
        vcdp->chgBus(c+2249,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x39U]),32);
        vcdp->chgBus(c+2257,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x3aU]),32);
        vcdp->chgBus(c+2265,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x3bU]),32);
        vcdp->chgBus(c+2273,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x3cU]),32);
        vcdp->chgBus(c+2281,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x3dU]),32);
        vcdp->chgBus(c+2289,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x3eU]),32);
        vcdp->chgBus(c+2297,(vlTOPp->top_SoC__DOT__localMem__DOT__memory
                             [0x3fU]),32);
        vcdp->chgBus(c+2305,((((IData)(vlTOPp->top_SoC__DOT__localMem__DOT__hi) 
                               << 0x10U) | (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__lo))),32);
        vcdp->chgBit(c+2313,(vlTOPp->top_SoC__DOT__localMem__DOT__readLast));
        vcdp->chgBus(c+2321,((0xffU & ((1U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                        ? vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data
                                        : vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                       [(0x3fU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                   - (IData)(0x8000U)) 
                                                  >> 2U))]))),8);
        vcdp->chgBus(c+2329,((0xffU & ((2U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                        ? (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                                           >> 8U) : 
                                       (vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                        [(0x3fU & (
                                                   (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                    - (IData)(0x8000U)) 
                                                   >> 2U))] 
                                        >> 8U)))),8);
        vcdp->chgBus(c+2337,((0xffU & ((4U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                        ? (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                                           >> 0x10U)
                                        : (vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                           [(0x3fU 
                                             & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                 - (IData)(0x8000U)) 
                                                >> 2U))] 
                                           >> 0x10U)))),8);
        vcdp->chgBus(c+2345,((0xffU & ((8U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                        ? (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                                           >> 0x18U)
                                        : (vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                           [(0x3fU 
                                             & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                 - (IData)(0x8000U)) 
                                                >> 2U))] 
                                           >> 0x18U)))),8);
        vcdp->chgBus(c+2353,(vlTOPp->top_SoC__DOT__localMem__DOT__lo),16);
        vcdp->chgBus(c+2361,(vlTOPp->top_SoC__DOT__localMem__DOT__hi),16);
        vcdp->chgBit(c+2369,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)) 
                              & (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_29))));
        vcdp->chgBus(c+2377,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [(0x3fU & vlTOPp->top_SoC__DOT__globalMem__DOT__rAddrOffset)]),32);
        vcdp->chgBus(c+2385,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [(0x3fU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                         - (IData)(0x10000U)) 
                                        >> 2U))]),32);
        vcdp->chgBus(c+2393,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0U]),32);
        vcdp->chgBus(c+2401,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [1U]),32);
        vcdp->chgBus(c+2409,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [2U]),32);
        vcdp->chgBus(c+2417,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [3U]),32);
        vcdp->chgBus(c+2425,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [4U]),32);
        vcdp->chgBus(c+2433,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [5U]),32);
        vcdp->chgBus(c+2441,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [6U]),32);
        vcdp->chgBus(c+2449,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [7U]),32);
        vcdp->chgBus(c+2457,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [8U]),32);
        vcdp->chgBus(c+2465,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [9U]),32);
        vcdp->chgBus(c+2473,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0xaU]),32);
        vcdp->chgBus(c+2481,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0xbU]),32);
        vcdp->chgBus(c+2489,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0xcU]),32);
        vcdp->chgBus(c+2497,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0xdU]),32);
        vcdp->chgBus(c+2505,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0xeU]),32);
        vcdp->chgBus(c+2513,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0xfU]),32);
        vcdp->chgBus(c+2521,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x10U]),32);
        vcdp->chgBus(c+2529,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x11U]),32);
        vcdp->chgBus(c+2537,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x12U]),32);
        vcdp->chgBus(c+2545,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x13U]),32);
        vcdp->chgBus(c+2553,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x14U]),32);
        vcdp->chgBus(c+2561,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x15U]),32);
        vcdp->chgBus(c+2569,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x16U]),32);
        vcdp->chgBus(c+2577,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x17U]),32);
        vcdp->chgBus(c+2585,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x18U]),32);
        vcdp->chgBus(c+2593,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x19U]),32);
        vcdp->chgBus(c+2601,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x1aU]),32);
        vcdp->chgBus(c+2609,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x1bU]),32);
        vcdp->chgBus(c+2617,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x1cU]),32);
        vcdp->chgBus(c+2625,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x1dU]),32);
        vcdp->chgBus(c+2633,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x1eU]),32);
        vcdp->chgBus(c+2641,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x1fU]),32);
        vcdp->chgBus(c+2649,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x20U]),32);
        vcdp->chgBus(c+2657,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x21U]),32);
        vcdp->chgBus(c+2665,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x22U]),32);
        vcdp->chgBus(c+2673,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x23U]),32);
        vcdp->chgBus(c+2681,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x24U]),32);
        vcdp->chgBus(c+2689,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x25U]),32);
        vcdp->chgBus(c+2697,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x26U]),32);
        vcdp->chgBus(c+2705,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x27U]),32);
        vcdp->chgBus(c+2713,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x28U]),32);
        vcdp->chgBus(c+2721,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x29U]),32);
        vcdp->chgBus(c+2729,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x2aU]),32);
        vcdp->chgBus(c+2737,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x2bU]),32);
        vcdp->chgBus(c+2745,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x2cU]),32);
        vcdp->chgBus(c+2753,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x2dU]),32);
        vcdp->chgBus(c+2761,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x2eU]),32);
        vcdp->chgBus(c+2769,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x2fU]),32);
        vcdp->chgBus(c+2777,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x30U]),32);
        vcdp->chgBus(c+2785,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x31U]),32);
        vcdp->chgBus(c+2793,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x32U]),32);
        vcdp->chgBus(c+2801,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x33U]),32);
        vcdp->chgBus(c+2809,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x34U]),32);
        vcdp->chgBus(c+2817,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x35U]),32);
        vcdp->chgBus(c+2825,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x36U]),32);
        vcdp->chgBus(c+2833,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x37U]),32);
        vcdp->chgBus(c+2841,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x38U]),32);
        vcdp->chgBus(c+2849,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x39U]),32);
        vcdp->chgBus(c+2857,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x3aU]),32);
        vcdp->chgBus(c+2865,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x3bU]),32);
        vcdp->chgBus(c+2873,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x3cU]),32);
        vcdp->chgBus(c+2881,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x3dU]),32);
        vcdp->chgBus(c+2889,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x3eU]),32);
        vcdp->chgBus(c+2897,(vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                             [0x3fU]),32);
        vcdp->chgBus(c+2905,((((IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__hi) 
                               << 0x10U) | (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__lo))),32);
        vcdp->chgBit(c+2913,(vlTOPp->top_SoC__DOT__globalMem__DOT__readLast));
        vcdp->chgBus(c+2921,((0xffU & ((1U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                        ? vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data
                                        : vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                       [(0x3fU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                   - (IData)(0x10000U)) 
                                                  >> 2U))]))),8);
        vcdp->chgBus(c+2929,((0xffU & ((2U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                        ? (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                                           >> 8U) : 
                                       (vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                        [(0x3fU & (
                                                   (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                    - (IData)(0x10000U)) 
                                                   >> 2U))] 
                                        >> 8U)))),8);
        vcdp->chgBus(c+2937,((0xffU & ((4U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                        ? (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                                           >> 0x10U)
                                        : (vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                           [(0x3fU 
                                             & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                 - (IData)(0x10000U)) 
                                                >> 2U))] 
                                           >> 0x10U)))),8);
        vcdp->chgBus(c+2945,((0xffU & ((8U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                        ? (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                                           >> 0x18U)
                                        : (vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                           [(0x3fU 
                                             & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                 - (IData)(0x10000U)) 
                                                >> 2U))] 
                                           >> 0x18U)))),8);
        vcdp->chgBus(c+2953,(vlTOPp->top_SoC__DOT__globalMem__DOT__lo),16);
        vcdp->chgBus(c+2961,(vlTOPp->top_SoC__DOT__globalMem__DOT__hi),16);
    }
}

void Vtop_SoC::traceChgThis__3(Vtop_SoC__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+2969,((((0U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)) 
                               | (1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState))) 
                              & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv)))));
        vcdp->chgBit(c+2977,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined));
        vcdp->chgBus(c+2985,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_id),4);
        vcdp->chgBus(c+2993,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_addr),32);
        vcdp->chgBus(c+3001,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_size),2);
        vcdp->chgBit(c+3009,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined));
        vcdp->chgBus(c+3017,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_data),32);
        vcdp->chgBus(c+3025,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_strb),4);
        vcdp->chgBit(c+3033,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_last));
        vcdp->chgBit(c+3041,((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState))));
        vcdp->chgBus(c+3049,(vlTOPp->top_SoC__DOT__dma__DOT__sWriteIDReg),4);
        vcdp->chgBit(c+3057,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sReadState)))));
        vcdp->chgBit(c+3065,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined));
        vcdp->chgBus(c+3073,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_id),4);
        vcdp->chgBus(c+3081,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_addr),32);
        vcdp->chgBus(c+3089,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_size),2);
        vcdp->chgBit(c+3097,(vlTOPp->top_SoC__DOT__dma__DOT__sReadState));
        vcdp->chgBus(c+3105,(vlTOPp->top_SoC__DOT__dma__DOT__sReadIDReg),4);
        vcdp->chgBus(c+3113,(((0x14U == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
                               ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_5
                               : ((0x10U == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
                                   ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_4
                                   : ((0xcU == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
                                       ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3
                                       : ((8U == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
                                           ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_2
                                           : ((4U == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
                                               ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_1
                                               : ((0U 
                                                   == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
                                                   ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_0
                                                   : 0U))))))),32);
        vcdp->chgBit(c+3121,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)))));
        vcdp->chgBit(c+3129,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)))));
        vcdp->chgBit(c+3137,(((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                              & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteDataSent)))));
        vcdp->chgBit(c+3145,((4U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))));
        vcdp->chgBit(c+3153,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid));
        vcdp->chgBus(c+3161,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_id),4);
        vcdp->chgBus(c+3169,((3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg))),2);
        vcdp->chgBit(c+3177,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)))));
        vcdp->chgBit(c+3185,((1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))));
        vcdp->chgBit(c+3193,((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))));
        vcdp->chgBus(c+3201,(((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
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
        vcdp->chgBus(c+3209,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
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
        vcdp->chgBit(c+3217,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                              & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                  ? ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)) 
                                     | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last))
                                  : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                      ? ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)) 
                                         | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last))
                                      : ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)) 
                                         | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last)))))));
        vcdp->chgBit(c+3225,((1U & vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_5)));
        vcdp->chgBus(c+3233,((0x7fffU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg)),15);
        vcdp->chgBit(c+3241,((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg))));
        vcdp->chgBit(c+3249,((0x23U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg))));
        vcdp->chgBus(c+3257,((7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                    >> 0xcU))),4);
        vcdp->chgBus(c+3265,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg),32);
        vcdp->chgBus(c+3273,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__wdataReg),32);
        vcdp->chgBit(c+3281,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)))));
        vcdp->chgBit(c+3289,((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState))));
        vcdp->chgBit(c+3297,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)))));
        vcdp->chgBus(c+3305,(((2U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                            >> 0xcU)))
                               ? 0xfU : ((1U == (7U 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                    >> 0xcU)))
                                          ? ((1U == 
                                              (2U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                              ? 0xcU
                                              : 3U)
                                          : ((0U == 
                                              (7U & 
                                               (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
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
        vcdp->chgBit(c+3313,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid));
        vcdp->chgBit(c+3321,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)))));
        vcdp->chgBit(c+3329,((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState))));
        vcdp->chgBus(c+3337,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_1),32);
        vcdp->chgBus(c+3345,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_2),32);
        vcdp->chgBus(c+3353,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_3),32);
        vcdp->chgBus(c+3361,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_4),32);
        vcdp->chgBus(c+3369,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_5),32);
        vcdp->chgBus(c+3377,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_6),32);
        vcdp->chgBus(c+3385,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_7),32);
        vcdp->chgBus(c+3393,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_8),32);
        vcdp->chgBus(c+3401,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_9),32);
        vcdp->chgBus(c+3409,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_10),32);
        vcdp->chgBus(c+3417,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_11),32);
        vcdp->chgBus(c+3425,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_12),32);
        vcdp->chgBus(c+3433,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_13),32);
        vcdp->chgBus(c+3441,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_14),32);
        vcdp->chgBus(c+3449,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_15),32);
        vcdp->chgBus(c+3457,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_16),32);
        vcdp->chgBus(c+3465,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_17),32);
        vcdp->chgBus(c+3473,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_18),32);
        vcdp->chgBus(c+3481,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_19),32);
        vcdp->chgBus(c+3489,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_20),32);
        vcdp->chgBus(c+3497,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_21),32);
        vcdp->chgBus(c+3505,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_22),32);
        vcdp->chgBus(c+3513,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_23),32);
        vcdp->chgBus(c+3521,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_24),32);
        vcdp->chgBus(c+3529,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_25),32);
        vcdp->chgBus(c+3537,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_26),32);
        vcdp->chgBus(c+3545,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_27),32);
        vcdp->chgBus(c+3553,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_28),32);
        vcdp->chgBus(c+3561,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_29),32);
        vcdp->chgBus(c+3569,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_30),32);
        vcdp->chgBus(c+3577,(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31),32);
        vcdp->chgBus(c+3585,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg),32);
        vcdp->chgBus(c+3593,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg),32);
        vcdp->chgBus(c+3601,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg),32);
        vcdp->chgBus(c+3609,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__pcReg),32);
        vcdp->chgBus(c+3617,(((0U < vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg)
                               ? (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg 
                                  - (IData)(4U)) : vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg)),32);
        vcdp->chgBus(c+3625,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg),32);
        vcdp->chgBus(c+3633,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg),32);
        vcdp->chgBus(c+3641,((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                       >> 7U))),5);
        vcdp->chgBit(c+3649,(((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                              | (0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)))));
        vcdp->chgBit(c+3657,((0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))));
        vcdp->chgBit(c+3665,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                              & (1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)))));
        vcdp->chgBit(c+3673,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined));
        vcdp->chgBus(c+3681,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_id),4);
        vcdp->chgBus(c+3689,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr),32);
        vcdp->chgBit(c+3697,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                              & ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                 | (4U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))))));
        vcdp->chgBit(c+3705,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined));
        vcdp->chgBus(c+3713,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data),32);
        vcdp->chgBus(c+3721,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb),4);
        vcdp->chgBit(c+3729,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_last));
        vcdp->chgBit(c+3737,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                              & ((1U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                 & ((4U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                    & ((2U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                       & ((5U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                          & (3U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)))))))));
        vcdp->chgBus(c+3745,(((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
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
        vcdp->chgBit(c+3753,((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))));
        vcdp->chgBit(c+3761,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__ar_determined));
        vcdp->chgBus(c+3769,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_id),4);
        vcdp->chgBus(c+3777,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_addr),32);
        vcdp->chgBus(c+3785,(((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                               ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                        ? 0U : ((2U 
                                                 == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                                 ? 0U
                                                 : 
                                                ((3U 
                                                  == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                                  ? (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readID)
                                                  : 0U))))),4);
        vcdp->chgBit(c+3793,(((IData)(vlTOPp->top_SoC__DOT__localMem__DOT__rburst_counter) 
                              == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__rlength))));
        vcdp->chgBit(c+3801,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                              & (1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)))));
        vcdp->chgBit(c+3809,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined));
        vcdp->chgBus(c+3817,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_id),4);
        vcdp->chgBus(c+3825,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr),32);
        vcdp->chgBit(c+3833,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                              & ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                 | (4U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))))));
        vcdp->chgBit(c+3841,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined));
        vcdp->chgBus(c+3849,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data),32);
        vcdp->chgBus(c+3857,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb),4);
        vcdp->chgBit(c+3865,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_last));
        vcdp->chgBit(c+3873,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                              & ((1U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                 & ((4U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                    & ((2U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                       & ((5U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                          & (3U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)))))))));
        vcdp->chgBus(c+3881,(((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
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
        vcdp->chgBit(c+3889,((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))));
        vcdp->chgBit(c+3897,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__ar_determined));
        vcdp->chgBus(c+3905,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_id),4);
        vcdp->chgBus(c+3913,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_addr),32);
        vcdp->chgBus(c+3921,(((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                               ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                        ? 0U : ((2U 
                                                 == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                                 ? 0U
                                                 : 
                                                ((3U 
                                                  == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                                  ? (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readID)
                                                  : 0U))))),4);
        vcdp->chgBit(c+3929,(((IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__rburst_counter) 
                              == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__rlength))));
        vcdp->chgBus(c+3937,(vlTOPp->top_SoC__DOT__dma__DOT__mState),3);
        vcdp->chgBus(c+3945,(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState),2);
        vcdp->chgBus(c+3953,(vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg),32);
        vcdp->chgBit(c+3961,(vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv));
        vcdp->chgBit(c+3969,(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv));
        vcdp->chgBus(c+3977,(vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg),32);
        vcdp->chgBus(c+3985,(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg),32);
        vcdp->chgBit(c+3993,(vlTOPp->top_SoC__DOT__dma__DOT__mWriteAddrSent));
        vcdp->chgBit(c+4001,(vlTOPp->top_SoC__DOT__dma__DOT__mWriteDataSent));
        vcdp->chgBit(c+4009,(vlTOPp->top_SoC__DOT__dma__DOT__mReadlast));
        vcdp->chgBus(c+4017,(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_0),32);
        vcdp->chgBus(c+4025,(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_1),32);
        vcdp->chgBus(c+4033,(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_2),32);
        vcdp->chgBus(c+4041,(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3),32);
        vcdp->chgBus(c+4049,(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_4),32);
        vcdp->chgBus(c+4057,(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_5),32);
        vcdp->chgBus(c+4065,(vlTOPp->top_SoC__DOT__dma__DOT__data_buffer),32);
        vcdp->chgBus(c+4073,(vlTOPp->top_SoC__DOT__dma__DOT__source_offset),2);
        vcdp->chgBus(c+4081,(vlTOPp->top_SoC__DOT__dma__DOT__request_counter),32);
        vcdp->chgBus(c+4089,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg),32);
        vcdp->chgBus(c+4097,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg),32);
        vcdp->chgBus(c+4105,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__immReg),32);
        vcdp->chgBus(c+4113,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg),32);
        vcdp->chgBus(c+4121,(((IData)(4U) + vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__pcReg)),32);
        vcdp->chgBus(c+4129,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg),32);
        vcdp->chgBus(c+4137,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg),32);
        vcdp->chgBus(c+4145,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__alu_out_Reg),32);
        vcdp->chgBus(c+4153,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__ld_data_Reg),32);
        vcdp->chgBit(c+4161,((1U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                    >> 0xdU))));
        vcdp->chgBus(c+4169,((3U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg)),32);
        vcdp->chgBus(c+4177,((2U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg)),32);
        vcdp->chgBus(c+4185,(((2U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                            >> 0xcU)))
                               ? 0U : ((1U == (7U & 
                                               (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                >> 0xcU)))
                                        ? ((1U == (2U 
                                                   & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
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
        vcdp->chgBus(c+4193,(((2U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
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
        vcdp->chgBit(c+4201,(((0x23U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)))));
        vcdp->chgBus(c+4209,(vlTOPp->top_SoC__DOT__cpu__DOT__wState),2);
        vcdp->chgBus(c+4217,(vlTOPp->top_SoC__DOT__cpu__DOT__rState),2);
        vcdp->chgBus(c+4225,(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg),15);
        vcdp->chgBus(c+4233,((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                       >> 0xfU))),5);
        vcdp->chgBus(c+4241,((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                       >> 0x14U))),5);
        vcdp->chgBus(c+4249,((0x1ffffffU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 7U))),25);
        vcdp->chgBus(c+4257,((0xffffff80U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)),32);
        vcdp->chgBus(c+4265,((0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)),7);
        vcdp->chgBus(c+4273,((0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)),7);
        vcdp->chgBus(c+4281,((7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                    >> 0xcU))),3);
        vcdp->chgBus(c+4289,((0x7fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                       >> 0x19U))),7);
        vcdp->chgBus(c+4297,((0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)),7);
        vcdp->chgBus(c+4305,((7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                    >> 0xcU))),3);
        vcdp->chgBus(c+4313,((0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)),7);
        vcdp->chgBus(c+4321,((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                       >> 7U))),5);
        vcdp->chgBus(c+4329,((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                       >> 7U))),5);
        vcdp->chgBus(c+4337,((0x7fffU & ((IData)(3U) 
                                         + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))),15);
        vcdp->chgBus(c+4345,((0x7fffU & ((IData)(2U) 
                                         + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))),15);
        vcdp->chgBus(c+4353,((0x7fffU & ((IData)(1U) 
                                         + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))),15);
        vcdp->chgBus(c+4361,(((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                               ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                                   ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_id))
                               : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                       ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_id))
                                   : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                       ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_id))))),4);
        vcdp->chgBus(c+4369,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                                       ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_resp))
                                   : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                       ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                           ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_resp))
                                       : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                           ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_resp))))
                               : 0U)),2);
        vcdp->chgBit(c+4377,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                              & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                  ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg) 
                                     | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last))
                                  : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                      ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg) 
                                         | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last))
                                      : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg) 
                                         | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last)))))));
        vcdp->chgBus(c+4385,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id)
                                   : 0U) : 0U)),4);
        vcdp->chgBus(c+4393,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg
                                   : 0U) : 0U)),32);
        vcdp->chgBus(c+4401,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size))
                                   : 0U) : 0U)),2);
        vcdp->chgBus(c+4409,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                               ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_id))),4);
        vcdp->chgBus(c+4417,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                               ? 0U : vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data)),32);
        vcdp->chgBus(c+4425,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                               ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_resp))),2);
        vcdp->chgBit(c+4433,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg) 
                              | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last))));
        vcdp->chgBus(c+4441,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id)
                                   : 0U) : 0U)),4);
        vcdp->chgBus(c+4449,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg
                                   : 0U) : 0U)),32);
        vcdp->chgBus(c+4457,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size))
                                   : 0U) : 0U)),2);
        vcdp->chgBus(c+4465,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                               ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_id))),4);
        vcdp->chgBus(c+4473,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                               ? 0U : vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data)),32);
        vcdp->chgBus(c+4481,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                               ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_resp))),2);
        vcdp->chgBit(c+4489,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg) 
                              | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last))));
        vcdp->chgBus(c+4497,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id)
                                   : 0U) : 0U)),4);
        vcdp->chgBus(c+4505,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg
                                   : 0U) : 0U)),32);
        vcdp->chgBus(c+4513,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size))
                                   : 0U) : 0U)),2);
        vcdp->chgBus(c+4521,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                               ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_id))),4);
        vcdp->chgBus(c+4529,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                               ? 0U : vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data)),32);
        vcdp->chgBus(c+4537,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                               ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_resp))),2);
        vcdp->chgBit(c+4545,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg) 
                              | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last))));
        vcdp->chgBus(c+4553,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id)
                                   : 0U) : 0U)),4);
        vcdp->chgBus(c+4561,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                   ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg
                                   : 0U) : 0U)),32);
        vcdp->chgBus(c+4569,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                   ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size))
                                   : 0U) : 0U)),2);
        vcdp->chgBit(c+4577,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                              & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
                                 & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))))));
        vcdp->chgBus(c+4585,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_id)
                               : 0U)),4);
        vcdp->chgBus(c+4593,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                               ? vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data
                               : 0U)),32);
        vcdp->chgBus(c+4601,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_resp)
                               : 0U)),2);
        vcdp->chgBit(c+4609,((1U & ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)) 
                                    | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last)))));
        vcdp->chgBus(c+4617,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id)
                                   : 0U) : 0U)),4);
        vcdp->chgBus(c+4625,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                   ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg
                                   : 0U) : 0U)),32);
        vcdp->chgBus(c+4633,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                   ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size))
                                   : 0U) : 0U)),2);
        vcdp->chgBit(c+4641,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                              & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
                                 & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))))));
        vcdp->chgBus(c+4649,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_id)
                               : 0U)),4);
        vcdp->chgBus(c+4657,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                               ? vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data
                               : 0U)),32);
        vcdp->chgBus(c+4665,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_resp)
                               : 0U)),2);
        vcdp->chgBit(c+4673,((1U & ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)) 
                                    | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last)))));
        vcdp->chgBus(c+4681,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id)
                                   : 0U) : 0U)),4);
        vcdp->chgBus(c+4689,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                   ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg
                                   : 0U) : 0U)),32);
        vcdp->chgBus(c+4697,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                   ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size))
                                   : 0U) : 0U)),2);
        vcdp->chgBit(c+4705,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                              & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
                                 & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))))));
        vcdp->chgBus(c+4713,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_id)
                               : 0U)),4);
        vcdp->chgBus(c+4721,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                               ? vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data
                               : 0U)),32);
        vcdp->chgBus(c+4729,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_resp)
                               : 0U)),2);
        vcdp->chgBit(c+4737,((1U & ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)) 
                                    | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last)))));
        vcdp->chgBus(c+4745,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_size),2);
        vcdp->chgBus(c+4753,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_size),2);
        vcdp->chgBus(c+4761,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_id),4);
        vcdp->chgBus(c+4769,((3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg))),2);
        vcdp->chgBus(c+4777,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id)
                                   : 0U) : 0U)),4);
        vcdp->chgBus(c+4785,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                   ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg
                                   : 0U) : 0U)),32);
        vcdp->chgBus(c+4793,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                   ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size))
                                   : 0U) : 0U)),2);
        vcdp->chgBus(c+4801,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                               ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id))),4);
        vcdp->chgBus(c+4809,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                               ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp))),2);
        vcdp->chgBus(c+4817,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id)
                                   : 0U) : 0U)),4);
        vcdp->chgBus(c+4825,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                   ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg
                                   : 0U) : 0U)),32);
        vcdp->chgBus(c+4833,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                   ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size))
                                   : 0U) : 0U)),2);
        vcdp->chgBus(c+4841,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                               ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id))),4);
        vcdp->chgBus(c+4849,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                               ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp))),2);
        vcdp->chgBus(c+4857,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id)
                                   : 0U) : 0U)),4);
        vcdp->chgBus(c+4865,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                   ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg
                                   : 0U) : 0U)),32);
        vcdp->chgBus(c+4873,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                   ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size))
                                   : 0U) : 0U)),2);
        vcdp->chgBus(c+4881,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                               ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id))),4);
        vcdp->chgBus(c+4889,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                               ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp))),2);
        vcdp->chgBus(c+4897,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id)
                                   : 0U) : 0U)),4);
        vcdp->chgBus(c+4905,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                   ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg
                                   : 0U) : 0U)),32);
        vcdp->chgBus(c+4913,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                   ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size))
                                   : 0U) : 0U)),2);
        vcdp->chgBus(c+4921,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id)
                               : 0U)),4);
        vcdp->chgBus(c+4929,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp)
                               : 0U)),2);
        vcdp->chgBus(c+4937,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id)
                                   : 0U) : 0U)),4);
        vcdp->chgBus(c+4945,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                   ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg
                                   : 0U) : 0U)),32);
        vcdp->chgBus(c+4953,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                   ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size))
                                   : 0U) : 0U)),2);
        vcdp->chgBus(c+4961,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id)
                               : 0U)),4);
        vcdp->chgBus(c+4969,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp)
                               : 0U)),2);
        vcdp->chgBus(c+4977,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id)
                                   : 0U) : 0U)),4);
        vcdp->chgBus(c+4985,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                   ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg
                                   : 0U) : 0U)),32);
        vcdp->chgBus(c+4993,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                   ? (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size))
                                   : 0U) : 0U)),2);
        vcdp->chgBus(c+5001,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id)
                               : 0U)),4);
        vcdp->chgBus(c+5009,(((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp)
                               : 0U)),2);
        vcdp->chgBus(c+5017,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_size),2);
        vcdp->chgBus(c+5025,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_size),2);
        vcdp->chgBus(c+5033,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg),3);
        vcdp->chgBus(c+5041,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg),32);
        vcdp->chgBus(c+5049,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id),4);
        vcdp->chgBus(c+5057,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size),3);
        vcdp->chgBit(c+5065,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid));
        vcdp->chgBit(c+5073,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding));
        vcdp->chgBus(c+5081,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg),3);
        vcdp->chgBus(c+5089,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg),32);
        vcdp->chgBus(c+5097,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id),4);
        vcdp->chgBus(c+5105,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size),3);
        vcdp->chgBit(c+5113,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid));
        vcdp->chgBit(c+5121,(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding));
        vcdp->chgBus(c+5129,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state),2);
        vcdp->chgBit(c+5137,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg));
        vcdp->chgBus(c+5145,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_id),4);
        vcdp->chgBus(c+5153,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data),32);
        vcdp->chgBus(c+5161,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_resp),2);
        vcdp->chgBit(c+5169,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last));
        vcdp->chgBit(c+5177,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant));
        vcdp->chgBit(c+5185,((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant))));
        vcdp->chgBus(c+5193,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state),2);
        vcdp->chgBit(c+5201,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg));
        vcdp->chgBus(c+5209,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_id),4);
        vcdp->chgBus(c+5217,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data),32);
        vcdp->chgBus(c+5225,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_resp),2);
        vcdp->chgBit(c+5233,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last));
        vcdp->chgBit(c+5241,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant));
        vcdp->chgBit(c+5249,((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant))));
        vcdp->chgBus(c+5257,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state),2);
        vcdp->chgBit(c+5265,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg));
        vcdp->chgBus(c+5273,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_id),4);
        vcdp->chgBus(c+5281,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data),32);
        vcdp->chgBus(c+5289,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_resp),2);
        vcdp->chgBit(c+5297,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last));
        vcdp->chgBit(c+5305,(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant));
        vcdp->chgBit(c+5313,((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant))));
        vcdp->chgBus(c+5321,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg),3);
        vcdp->chgBus(c+5329,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg),32);
        vcdp->chgBit(c+5337,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid));
        vcdp->chgBus(c+5345,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id),4);
        vcdp->chgBus(c+5353,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size),3);
        vcdp->chgBus(c+5361,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg),32);
        vcdp->chgBit(c+5369,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid));
        vcdp->chgBus(c+5377,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_strb),4);
        vcdp->chgBit(c+5385,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_last));
        vcdp->chgBus(c+5393,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg),4);
        vcdp->chgBit(c+5401,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding));
        vcdp->chgBit(c+5409,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding));
        vcdp->chgBit(c+5417,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding));
        vcdp->chgBus(c+5425,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg),3);
        vcdp->chgBus(c+5433,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg),32);
        vcdp->chgBit(c+5441,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid));
        vcdp->chgBus(c+5449,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id),4);
        vcdp->chgBus(c+5457,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size),3);
        vcdp->chgBus(c+5465,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg),32);
        vcdp->chgBit(c+5473,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid));
        vcdp->chgBus(c+5481,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_strb),4);
        vcdp->chgBit(c+5489,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_last));
        vcdp->chgBus(c+5497,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg),4);
        vcdp->chgBit(c+5505,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding));
        vcdp->chgBit(c+5513,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding));
        vcdp->chgBit(c+5521,(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding));
        vcdp->chgBus(c+5529,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state),2);
        vcdp->chgBit(c+5537,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg));
        vcdp->chgBus(c+5545,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id),4);
        vcdp->chgBus(c+5553,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp),2);
        vcdp->chgBit(c+5561,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant));
        vcdp->chgBit(c+5569,((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant))));
        vcdp->chgBus(c+5577,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state),2);
        vcdp->chgBit(c+5585,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg));
        vcdp->chgBus(c+5593,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id),4);
        vcdp->chgBus(c+5601,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp),2);
        vcdp->chgBit(c+5609,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant));
        vcdp->chgBit(c+5617,((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant))));
        vcdp->chgBus(c+5625,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state),2);
        vcdp->chgBit(c+5633,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg));
        vcdp->chgBus(c+5641,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id),4);
        vcdp->chgBus(c+5649,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp),2);
        vcdp->chgBit(c+5657,(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant));
        vcdp->chgBit(c+5665,((1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant))));
        vcdp->chgBus(c+5673,((0x3fU & vlTOPp->top_SoC__DOT__localMem__DOT__rAddrOffset)),6);
        vcdp->chgBit(c+5681,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb)))));
        vcdp->chgBus(c+5689,((0x3fU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                        - (IData)(0x8000U)) 
                                       >> 2U))),6);
        vcdp->chgBit(c+5697,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb) 
                                       >> 1U)))));
        vcdp->chgBit(c+5705,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb) 
                                       >> 2U)))));
        vcdp->chgBit(c+5713,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb) 
                                       >> 3U)))));
        vcdp->chgBit(c+5721,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                              & ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined)))));
        vcdp->chgBus(c+5729,((0x3fU & vlTOPp->top_SoC__DOT__localMem__DOT__writeAddressReg)),6);
        vcdp->chgBit(c+5737,(((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                              & ((1U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                 & ((4U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined))))));
        vcdp->chgBus(c+5745,(vlTOPp->top_SoC__DOT__localMem__DOT__readID),4);
        vcdp->chgBus(c+5753,(vlTOPp->top_SoC__DOT__localMem__DOT__rAddrOffset),32);
        vcdp->chgBus(c+5761,((0x3fffffffU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                              - (IData)(0x8000U)) 
                                             >> 2U))),32);
        vcdp->chgBus(c+5769,(vlTOPp->top_SoC__DOT__localMem__DOT__writeAddressReg),32);
        vcdp->chgBus(c+5777,(vlTOPp->top_SoC__DOT__localMem__DOT__writeID),4);
        vcdp->chgBus(c+5785,(vlTOPp->top_SoC__DOT__localMem__DOT__writeState),3);
        vcdp->chgBus(c+5793,(vlTOPp->top_SoC__DOT__localMem__DOT__readState),2);
        vcdp->chgBus(c+5801,(vlTOPp->top_SoC__DOT__localMem__DOT__rLatencyCounter),8);
        vcdp->chgBus(c+5809,(vlTOPp->top_SoC__DOT__localMem__DOT__wLatencyCounter),8);
        vcdp->chgBus(c+5817,(vlTOPp->top_SoC__DOT__localMem__DOT__rlength),4);
        vcdp->chgBus(c+5825,(vlTOPp->top_SoC__DOT__localMem__DOT__rburst_counter),4);
        vcdp->chgBus(c+5833,((0x3fU & vlTOPp->top_SoC__DOT__globalMem__DOT__rAddrOffset)),6);
        vcdp->chgBit(c+5841,((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb)))));
        vcdp->chgBus(c+5849,((0x3fU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                        - (IData)(0x10000U)) 
                                       >> 2U))),6);
        vcdp->chgBit(c+5857,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb) 
                                       >> 1U)))));
        vcdp->chgBit(c+5865,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb) 
                                       >> 2U)))));
        vcdp->chgBit(c+5873,((1U & (~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb) 
                                       >> 3U)))));
        vcdp->chgBit(c+5881,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                              & ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined)))));
        vcdp->chgBus(c+5889,((0x3fU & vlTOPp->top_SoC__DOT__globalMem__DOT__writeAddressReg)),6);
        vcdp->chgBit(c+5897,(((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                              & ((1U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                 & ((4U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined))))));
        vcdp->chgBus(c+5905,(vlTOPp->top_SoC__DOT__globalMem__DOT__readID),4);
        vcdp->chgBus(c+5913,(vlTOPp->top_SoC__DOT__globalMem__DOT__rAddrOffset),32);
        vcdp->chgBus(c+5921,((0x3fffffffU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                              - (IData)(0x10000U)) 
                                             >> 2U))),32);
        vcdp->chgBus(c+5929,(vlTOPp->top_SoC__DOT__globalMem__DOT__writeAddressReg),32);
        vcdp->chgBus(c+5937,(vlTOPp->top_SoC__DOT__globalMem__DOT__writeID),4);
        vcdp->chgBus(c+5945,(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState),3);
        vcdp->chgBus(c+5953,(vlTOPp->top_SoC__DOT__globalMem__DOT__readState),2);
        vcdp->chgBus(c+5961,(vlTOPp->top_SoC__DOT__globalMem__DOT__rLatencyCounter),8);
        vcdp->chgBus(c+5969,(vlTOPp->top_SoC__DOT__globalMem__DOT__wLatencyCounter),8);
        vcdp->chgBus(c+5977,(vlTOPp->top_SoC__DOT__globalMem__DOT__rlength),4);
        vcdp->chgBus(c+5985,(vlTOPp->top_SoC__DOT__globalMem__DOT__rburst_counter),4);
    }
}

void Vtop_SoC::traceChgThis__4(Vtop_SoC__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+5993,(vlTOPp->clock));
        vcdp->chgBit(c+6001,(vlTOPp->reset));
        vcdp->chgBus(c+6009,(vlTOPp->io_regs_0),32);
        vcdp->chgBus(c+6017,(vlTOPp->io_regs_1),32);
        vcdp->chgBus(c+6025,(vlTOPp->io_regs_2),32);
        vcdp->chgBus(c+6033,(vlTOPp->io_regs_3),32);
        vcdp->chgBus(c+6041,(vlTOPp->io_regs_4),32);
        vcdp->chgBus(c+6049,(vlTOPp->io_regs_5),32);
        vcdp->chgBus(c+6057,(vlTOPp->io_regs_6),32);
        vcdp->chgBus(c+6065,(vlTOPp->io_regs_7),32);
        vcdp->chgBus(c+6073,(vlTOPp->io_regs_8),32);
        vcdp->chgBus(c+6081,(vlTOPp->io_regs_9),32);
        vcdp->chgBus(c+6089,(vlTOPp->io_regs_10),32);
        vcdp->chgBus(c+6097,(vlTOPp->io_regs_11),32);
        vcdp->chgBus(c+6105,(vlTOPp->io_regs_12),32);
        vcdp->chgBus(c+6113,(vlTOPp->io_regs_13),32);
        vcdp->chgBus(c+6121,(vlTOPp->io_regs_14),32);
        vcdp->chgBus(c+6129,(vlTOPp->io_regs_15),32);
        vcdp->chgBus(c+6137,(vlTOPp->io_regs_16),32);
        vcdp->chgBus(c+6145,(vlTOPp->io_regs_17),32);
        vcdp->chgBus(c+6153,(vlTOPp->io_regs_18),32);
        vcdp->chgBus(c+6161,(vlTOPp->io_regs_19),32);
        vcdp->chgBus(c+6169,(vlTOPp->io_regs_20),32);
        vcdp->chgBus(c+6177,(vlTOPp->io_regs_21),32);
        vcdp->chgBus(c+6185,(vlTOPp->io_regs_22),32);
        vcdp->chgBus(c+6193,(vlTOPp->io_regs_23),32);
        vcdp->chgBus(c+6201,(vlTOPp->io_regs_24),32);
        vcdp->chgBus(c+6209,(vlTOPp->io_regs_25),32);
        vcdp->chgBus(c+6217,(vlTOPp->io_regs_26),32);
        vcdp->chgBus(c+6225,(vlTOPp->io_regs_27),32);
        vcdp->chgBus(c+6233,(vlTOPp->io_regs_28),32);
        vcdp->chgBus(c+6241,(vlTOPp->io_regs_29),32);
        vcdp->chgBus(c+6249,(vlTOPp->io_regs_30),32);
        vcdp->chgBus(c+6257,(vlTOPp->io_regs_31),32);
        vcdp->chgBit(c+6265,(vlTOPp->io_Hcf));
        vcdp->chgBus(c+6273,(vlTOPp->io_inst),32);
        vcdp->chgBus(c+6281,(vlTOPp->io_rdata),32);
        vcdp->chgBus(c+6289,(vlTOPp->io_wdata),32);
        vcdp->chgBit(c+6297,(vlTOPp->io_Dump_Mem));
        vcdp->chgBit(c+6305,(vlTOPp->io_E_Branch_taken));
        vcdp->chgBit(c+6313,(vlTOPp->io_Flush));
        vcdp->chgBit(c+6321,(vlTOPp->io_Stall_MA));
        vcdp->chgBit(c+6329,(vlTOPp->io_Stall_DH));
        vcdp->chgBus(c+6337,(vlTOPp->io_IF_PC),32);
        vcdp->chgBus(c+6345,(vlTOPp->io_ID_PC),32);
        vcdp->chgBus(c+6353,(vlTOPp->io_EXE_PC),32);
        vcdp->chgBus(c+6361,(vlTOPp->io_MEM_PC),32);
        vcdp->chgBus(c+6369,(vlTOPp->io_WB_PC),32);
        vcdp->chgBus(c+6377,(vlTOPp->io_EXE_alu_out),32);
        vcdp->chgBus(c+6385,(vlTOPp->io_EXE_src1),32);
        vcdp->chgBus(c+6393,(vlTOPp->io_EXE_src2),32);
        vcdp->chgBus(c+6401,(vlTOPp->io_ALU_src1),32);
        vcdp->chgBus(c+6409,(vlTOPp->io_ALU_src2),32);
        vcdp->chgBus(c+6417,(vlTOPp->io_raddr),32);
        vcdp->chgBus(c+6425,(vlTOPp->io_WB_rd),5);
        vcdp->chgBus(c+6433,(vlTOPp->io_WB_wdata),32);
        vcdp->chgBit(c+6441,(vlTOPp->io_EXE_Jump));
        vcdp->chgBit(c+6449,(vlTOPp->io_EXE_Branch));
        vcdp->chgBit(c+6457,(vlTOPp->io_DMA_Hcf));
    }
}
