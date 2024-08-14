// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_SoC.h for the primary calling header

#include "Vtop_SoC.h"
#include "Vtop_SoC__Syms.h"

//==========

VL_CTOR_IMP(Vtop_SoC) {
    Vtop_SoC__Syms* __restrict vlSymsp = __VlSymsp = new Vtop_SoC__Syms(this, name());
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop_SoC::__Vconfigure(Vtop_SoC__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop_SoC::~Vtop_SoC() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vtop_SoC::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_SoC::eval\n"); );
    Vtop_SoC__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top_SoC.v", 7442, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop_SoC::_eval_initial_loop(Vtop_SoC__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top_SoC.v", 7442, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop_SoC::_initial__TOP__1(Vtop_SoC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_SoC::_initial__TOP__1\n"); );
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*223:0*/ __Vtemp1[7];
    WData/*255:0*/ __Vtemp2[8];
    WData/*255:0*/ __Vtemp3[8];
    // Body
    vlTOPp->io_regs_0 = 0U;
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x696e7374U;
    __Vtemp1[2U] = 0x7263652fU;
    __Vtemp1[3U] = 0x65736f75U;
    __Vtemp1[4U] = 0x696e2f72U;
    __Vtemp1[5U] = 0x632f6d61U;
    __Vtemp1[6U] = 0x2e2f7372U;
    VL_READMEM_N(true, 8, 32768, 0, VL_CVT_PACK_STR_NW(7, __Vtemp1)
                 , vlTOPp->top_SoC__DOT__im__DOT__memory
                 , 0, ~VL_ULL(0));
    __Vtemp2[0U] = 0x2e686578U;
    __Vtemp2[1U] = 0x61746130U;
    __Vtemp2[2U] = 0x63652f64U;
    __Vtemp2[3U] = 0x736f7572U;
    __Vtemp2[4U] = 0x6e2f7265U;
    __Vtemp2[5U] = 0x2f6d6169U;
    __Vtemp2[6U] = 0x2f737263U;
    __Vtemp2[7U] = 0x2eU;
    VL_READMEM_N(true, 32, 64, 0, VL_CVT_PACK_STR_NW(8, __Vtemp2)
                 , vlTOPp->top_SoC__DOT__localMem__DOT__memory
                 , 0, ~VL_ULL(0));
    __Vtemp3[0U] = 0x2e686578U;
    __Vtemp3[1U] = 0x61746131U;
    __Vtemp3[2U] = 0x63652f64U;
    __Vtemp3[3U] = 0x736f7572U;
    __Vtemp3[4U] = 0x6e2f7265U;
    __Vtemp3[5U] = 0x2f6d6169U;
    __Vtemp3[6U] = 0x2f737263U;
    __Vtemp3[7U] = 0x2eU;
    VL_READMEM_N(true, 32, 64, 0, VL_CVT_PACK_STR_NW(8, __Vtemp3)
                 , vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                 , 0, ~VL_ULL(0));
}

VL_INLINE_OPT void Vtop_SoC::_sequent__TOP__2(Vtop_SoC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_SoC::_sequent__TOP__2\n"); );
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__top_SoC__DOT__dma__DOT__sWriteState;
    CData/*2:0*/ __Vdly__top_SoC__DOT__dma__DOT__mState;
    CData/*3:0*/ __Vdly__top_SoC__DOT__dma__DOT__sReadIDReg;
    CData/*0:0*/ __Vdly__top_SoC__DOT__dma__DOT__sReadState;
    CData/*1:0*/ __Vdly__top_SoC__DOT__cpu__DOT__wState;
    CData/*1:0*/ __Vdly__top_SoC__DOT__cpu__DOT__rState;
    CData/*0:0*/ __Vdly__top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding;
    CData/*0:0*/ __Vdly__top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding;
    CData/*1:0*/ __Vdly__top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state;
    CData/*1:0*/ __Vdly__top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state;
    CData/*1:0*/ __Vdly__top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state;
    CData/*0:0*/ __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid;
    CData/*0:0*/ __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding;
    CData/*0:0*/ __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding;
    CData/*0:0*/ __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid;
    CData/*0:0*/ __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding;
    CData/*0:0*/ __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding;
    CData/*1:0*/ __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state;
    CData/*1:0*/ __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state;
    CData/*1:0*/ __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state;
    CData/*5:0*/ __Vdlyvdim0__top_SoC__DOT__localMem__DOT__memory__v0;
    CData/*0:0*/ __Vdlyvset__top_SoC__DOT__localMem__DOT__memory__v0;
    CData/*5:0*/ __Vdlyvdim0__top_SoC__DOT__localMem__DOT__memory__v1;
    CData/*0:0*/ __Vdlyvset__top_SoC__DOT__localMem__DOT__memory__v1;
    CData/*2:0*/ __Vdly__top_SoC__DOT__localMem__DOT__writeState;
    CData/*3:0*/ __Vdly__top_SoC__DOT__localMem__DOT__readID;
    CData/*1:0*/ __Vdly__top_SoC__DOT__localMem__DOT__readState;
    CData/*5:0*/ __Vdlyvdim0__top_SoC__DOT__globalMem__DOT__memory__v0;
    CData/*0:0*/ __Vdlyvset__top_SoC__DOT__globalMem__DOT__memory__v0;
    CData/*5:0*/ __Vdlyvdim0__top_SoC__DOT__globalMem__DOT__memory__v1;
    CData/*0:0*/ __Vdlyvset__top_SoC__DOT__globalMem__DOT__memory__v1;
    CData/*2:0*/ __Vdly__top_SoC__DOT__globalMem__DOT__writeState;
    CData/*3:0*/ __Vdly__top_SoC__DOT__globalMem__DOT__readID;
    CData/*1:0*/ __Vdly__top_SoC__DOT__globalMem__DOT__readState;
    IData/*31:0*/ __Vdly__top_SoC__DOT__dma__DOT__request_counter;
    IData/*31:0*/ __Vdly__top_SoC__DOT__dma__DOT__sReadAddrReg;
    IData/*31:0*/ __Vdlyvval__top_SoC__DOT__localMem__DOT__memory__v0;
    IData/*31:0*/ __Vdlyvval__top_SoC__DOT__localMem__DOT__memory__v1;
    IData/*31:0*/ __Vdly__top_SoC__DOT__localMem__DOT__rAddrOffset;
    IData/*31:0*/ __Vdlyvval__top_SoC__DOT__globalMem__DOT__memory__v0;
    IData/*31:0*/ __Vdlyvval__top_SoC__DOT__globalMem__DOT__memory__v1;
    IData/*31:0*/ __Vdly__top_SoC__DOT__globalMem__DOT__rAddrOffset;
    // Body
    __Vdly__top_SoC__DOT__dma__DOT__sReadState = vlTOPp->top_SoC__DOT__dma__DOT__sReadState;
    __Vdly__top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding 
        = vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding;
    __Vdly__top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding 
        = vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding;
    __Vdly__top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state 
        = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state;
    __Vdly__top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state 
        = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state;
    __Vdly__top_SoC__DOT__cpu__DOT__wState = vlTOPp->top_SoC__DOT__cpu__DOT__wState;
    __Vdly__top_SoC__DOT__globalMem__DOT__rAddrOffset 
        = vlTOPp->top_SoC__DOT__globalMem__DOT__rAddrOffset;
    __Vdly__top_SoC__DOT__globalMem__DOT__readID = vlTOPp->top_SoC__DOT__globalMem__DOT__readID;
    __Vdly__top_SoC__DOT__localMem__DOT__rAddrOffset 
        = vlTOPp->top_SoC__DOT__localMem__DOT__rAddrOffset;
    __Vdly__top_SoC__DOT__localMem__DOT__readID = vlTOPp->top_SoC__DOT__localMem__DOT__readID;
    __Vdly__top_SoC__DOT__globalMem__DOT__readState 
        = vlTOPp->top_SoC__DOT__globalMem__DOT__readState;
    __Vdly__top_SoC__DOT__localMem__DOT__readState 
        = vlTOPp->top_SoC__DOT__localMem__DOT__readState;
    __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state 
        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state;
    __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state 
        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state;
    __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state 
        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state;
    __Vdly__top_SoC__DOT__localMem__DOT__writeState 
        = vlTOPp->top_SoC__DOT__localMem__DOT__writeState;
    __Vdly__top_SoC__DOT__globalMem__DOT__writeState 
        = vlTOPp->top_SoC__DOT__globalMem__DOT__writeState;
    __Vdly__top_SoC__DOT__dma__DOT__sWriteState = vlTOPp->top_SoC__DOT__dma__DOT__sWriteState;
    __Vdly__top_SoC__DOT__dma__DOT__request_counter 
        = vlTOPp->top_SoC__DOT__dma__DOT__request_counter;
    __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding 
        = vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding;
    __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid 
        = vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid;
    __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding 
        = vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding;
    __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid 
        = vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid;
    __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding 
        = vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding;
    __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding 
        = vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding;
    __Vdly__top_SoC__DOT__dma__DOT__mState = vlTOPp->top_SoC__DOT__dma__DOT__mState;
    __Vdly__top_SoC__DOT__cpu__DOT__rState = vlTOPp->top_SoC__DOT__cpu__DOT__rState;
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\t======== Data Memory Dump ========\n");
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tFrom base address 32768\n");
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[0] (address = 8000) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[1] (address = 8004) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [1U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [1U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[2] (address = 8008) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [2U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [2U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[3] (address = 800c) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [3U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [3U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[4] (address = 8010) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [4U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [4U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[5] (address = 8014) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [5U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [5U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[6] (address = 8018) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [6U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [6U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[7] (address = 801c) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [7U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [7U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[8] (address = 8020) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [8U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [8U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[9] (address = 8024) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [9U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [9U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[10] (address = 8028) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0xaU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0xaU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[11] (address = 802c) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0xbU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0xbU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[12] (address = 8030) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0xcU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0xcU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[13] (address = 8034) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0xdU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0xdU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[14] (address = 8038) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0xeU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0xeU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[15] (address = 803c) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0xfU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0xfU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[16] (address = 8040) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x10U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x10U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[17] (address = 8044) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x11U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x11U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[18] (address = 8048) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x12U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x12U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[19] (address = 804c) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x13U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x13U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[20] (address = 8050) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x14U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x14U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[21] (address = 8054) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x15U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x15U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[22] (address = 8058) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x16U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x16U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[23] (address = 805c) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x17U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x17U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[24] (address = 8060) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x18U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x18U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[25] (address = 8064) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x19U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x19U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[26] (address = 8068) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x1aU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x1aU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[27] (address = 806c) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x1bU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x1bU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[28] (address = 8070) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x1cU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x1cU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[29] (address = 8074) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x1dU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x1dU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[30] (address = 8078) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x1eU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x1eU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[31] (address = 807c) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x1fU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x1fU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[32] (address = 8080) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x20U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x20U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[33] (address = 8084) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x21U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x21U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[34] (address = 8088) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x22U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x22U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[35] (address = 808c) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x23U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x23U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[36] (address = 8090) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x24U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x24U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[37] (address = 8094) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x25U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x25U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[38] (address = 8098) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x26U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x26U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[39] (address = 809c) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x27U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x27U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[40] (address = 80a0) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x28U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x28U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[41] (address = 80a4) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x29U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x29U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[42] (address = 80a8) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x2aU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x2aU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[43] (address = 80ac) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x2bU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x2bU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[44] (address = 80b0) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x2cU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x2cU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[45] (address = 80b4) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x2dU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x2dU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[46] (address = 80b8) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x2eU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x2eU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[47] (address = 80bc) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x2fU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x2fU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[48] (address = 80c0) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x30U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x30U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[49] (address = 80c4) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x31U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x31U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[50] (address = 80c8) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x32U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x32U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[51] (address = 80cc) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x33U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x33U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[52] (address = 80d0) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x34U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x34U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[53] (address = 80d4) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x35U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x35U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[54] (address = 80d8) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x36U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x36U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[55] (address = 80dc) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x37U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x37U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[56] (address = 80e0) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x38U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x38U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[57] (address = 80e4) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x39U],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x39U]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[58] (address = 80e8) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x3aU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x3aU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[59] (address = 80ec) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x3bU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x3bU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[60] (address = 80f0) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x3cU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x3cU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[61] (address = 80f4) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x3dU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x3dU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[62] (address = 80f8) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x3eU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x3eU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\t\tDataMem[63] (address = 80fc) = 0x%x (%10#)\n",
                       32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x3fU],32,vlTOPp->top_SoC__DOT__localMem__DOT__memory
                       [0x3fU]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (VL_UNLIKELY(((IData)(vlTOPp->io_Dump_Mem) 
                         & (~ (IData)(vlTOPp->reset))))) {
            VL_FWRITEF(0x80000002U,"\n");
        }
    }
    __Vdlyvset__top_SoC__DOT__localMem__DOT__memory__v0 = 0U;
    __Vdlyvset__top_SoC__DOT__localMem__DOT__memory__v1 = 0U;
    __Vdlyvset__top_SoC__DOT__globalMem__DOT__memory__v0 = 0U;
    __Vdlyvset__top_SoC__DOT__globalMem__DOT__memory__v1 = 0U;
    __Vdly__top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state 
        = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state;
    __Vdly__top_SoC__DOT__dma__DOT__sReadIDReg = vlTOPp->top_SoC__DOT__dma__DOT__sReadIDReg;
    __Vdly__top_SoC__DOT__dma__DOT__sReadAddrReg = vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg;
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__ld_data_Reg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__ld_data_Reg 
                = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_MEM_io_Mem_Data;
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__dma__DOT__sReadState = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__dma__DOT___io_slave_ar_ready_T) {
            __Vdly__top_SoC__DOT__dma__DOT__sReadState 
                = vlTOPp->top_SoC__DOT__dma__DOT___GEN_10;
        } else {
            if (vlTOPp->top_SoC__DOT__dma__DOT__sReadState) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_out_readData_ready) {
                    __Vdly__top_SoC__DOT__dma__DOT__sReadState = 0U;
                }
            }
        }
    }
    vlTOPp->top_SoC__DOT__dma__DOT__mWriteDataSent 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_44));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_last = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_1) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_last = 1U;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_last = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_1) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_last = 1U;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_1) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg 
                = (IData)(vlTOPp->top_SoC__DOT__cpu__DOT___GEN_8);
        }
    }
    vlTOPp->top_SoC__DOT__dma__DOT__mWriteAddrSent 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_45));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__alu_out_Reg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__alu_out_Reg 
                = vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_strb = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_1) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_strb 
                = ((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                    ? (0xfU & ((IData)(vlTOPp->top_SoC__DOT__dma__DOT__mask_width) 
                               << (3U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_35))))
                    : 0xfU);
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg = 0U;
    } else {
        if ((1U & (~ (((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH) 
                       | (IData)(vlTOPp->top_SoC__DOT__cpu_io_Stall_MA)) 
                      & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)))))) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg 
                = ((2U == ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)
                            ? 2U : 0U)) ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10)
                    : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_IF__DOT___io_next_pc_T_9);
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_1) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg 
                = (IData)((VL_ULL(0x7fffffffffffffff) 
                           & ((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                               ? ((QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__data_buffer)) 
                                  << (0x18U & ((IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_35) 
                                               << 3U)))
                               : (QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__data_buffer)))));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg 
                = ((IData)(4U) + vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__pcReg);
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__immReg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Flush) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__immReg = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__immReg 
                    = ((4U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel))
                        ? ((0xffe00000U & (VL_NEGATE_I((IData)(
                                                               (1U 
                                                                & (vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_22 
                                                                   >> 0x14U)))) 
                                           << 0x15U)) 
                           | vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_22)
                        : ((5U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel))
                            ? (0xfffff000U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)
                            : ((0xffffe000U & (VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_30) 
                                                                       >> 0xcU)))) 
                                               << 0xdU)) 
                               | (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_30))));
            }
        }
    }
    __Vdly__top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding 
        = ((~ (IData)(vlTOPp->reset)) & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                          ? ((~ ((IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready) 
                                                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_valid))) 
                                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___GEN_0))
                                          : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___GEN_0)));
    __Vdly__top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding 
        = ((~ (IData)(vlTOPp->reset)) & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                          ? ((~ ((2U 
                                                  == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))) 
                                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___GEN_0))
                                          : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___GEN_0)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid 
        = ((~ (IData)(vlTOPp->reset)) & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid)
                                          ? ((~ ((2U 
                                                  == 
                                                  (3U 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                                  ? 
                                                 ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1)) 
                                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0))
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                                   ? 
                                                  ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1)) 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0))
                                                   : 
                                                  ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1)) 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0))))) 
                                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___GEN_5))
                                          : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___GEN_5)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid 
        = ((~ (IData)(vlTOPp->reset)) & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid)
                                          ? ((~ ((2U 
                                                  == 
                                                  (3U 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                                  ? 
                                                 (((1U 
                                                    > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant)) 
                                                   | (~ 
                                                      ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                                       | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid)))) 
                                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0))
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                                   ? 
                                                  (((1U 
                                                     > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant)) 
                                                    | (~ 
                                                       ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                                        | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid)))) 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0))
                                                   : 
                                                  (((1U 
                                                     > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant)) 
                                                    | (~ 
                                                       ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                                        | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid)))) 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0))))) 
                                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___GEN_5))
                                          : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___GEN_5)));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_strb = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_1) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_strb 
                = ((2U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                 >> 0xcU))) ? 0xfU : 
                   ((1U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                  >> 0xcU))) ? ((1U 
                                                 == 
                                                 (2U 
                                                  & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                 ? 0xcU
                                                 : 3U)
                     : ((0U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                      >> 0xcU))) ? 
                        ((3U == (3U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                          ? 8U : ((2U == (3U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                   ? 4U : ((1U == (3U 
                                                   & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                            ? 2U : 1U)))
                         : 0xfU)));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_26 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x1aU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_26 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_25 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x19U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_25 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_14 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0xeU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                   >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_14 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_15 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0xfU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                   >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_15 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_16 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x10U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_16 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_17 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x11U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_17 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_18 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x12U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_18 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_19 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x13U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_19 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_20 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x14U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_20 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_21 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x15U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_21 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_22 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x16U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_22 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_23 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x17U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_23 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_24 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x18U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_24 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_12 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0xcU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                   >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_12 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_11 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0xbU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                   >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_11 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_10 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0xaU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                   >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_10 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_9 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((9U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                 >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_9 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_3 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((3U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                 >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_3 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_2 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((2U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                 >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_2 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_1 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((1U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                 >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_1 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_8 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((8U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                 >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_8 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_7 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((7U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                 >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_7 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_4 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((4U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                 >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_4 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_5 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((5U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                 >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_5 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_6 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((6U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                 >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_6 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_13 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0xdU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                   >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_13 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__cpu__DOT__wState = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState))) {
            if ((0x23U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg))) {
                __Vdly__top_SoC__DOT__cpu__DOT__wState = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState))) {
                if ((1U & ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)) 
                           & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding))))) {
                    __Vdly__top_SoC__DOT__cpu__DOT__wState = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState))) {
                    __Vdly__top_SoC__DOT__cpu__DOT__wState 
                        = vlTOPp->top_SoC__DOT__cpu__DOT___GEN_2;
                }
            }
        }
    }
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid 
        = ((~ (IData)(vlTOPp->reset)) & ((~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid) 
                                             & ((2U 
                                                 == 
                                                 (3U 
                                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                                 ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeData_ready)
                                                 : 
                                                ((1U 
                                                  == 
                                                  (3U 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                                  ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeData_ready)
                                                  : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeData_ready))))) 
                                         & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_9)));
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__globalMem__DOT__readID = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))) {
            __Vdly__top_SoC__DOT__globalMem__DOT__readID 
                = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_id;
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__globalMem__DOT__rAddrOffset = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))) {
            __Vdly__top_SoC__DOT__globalMem__DOT__rAddrOffset 
                = (0x3fffffffU & ((vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_addr 
                                   - (IData)(0x10000U)) 
                                  >> 2U));
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__globalMem__DOT__readState = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__ar_determined) {
                __Vdly__top_SoC__DOT__globalMem__DOT__readState = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))) {
                if ((0x4fU == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__rLatencyCounter))) {
                    __Vdly__top_SoC__DOT__globalMem__DOT__readState = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))) {
                    __Vdly__top_SoC__DOT__globalMem__DOT__readState = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__globalMem__DOT__rLatencyCounter = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))) {
                vlTOPp->top_SoC__DOT__globalMem__DOT__rLatencyCounter 
                    = vlTOPp->top_SoC__DOT__globalMem__DOT___rLatencyCounter_T_1;
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))) {
                    vlTOPp->top_SoC__DOT__globalMem__DOT__rLatencyCounter = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__localMem__DOT__readID = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))) {
            __Vdly__top_SoC__DOT__localMem__DOT__readID 
                = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_id;
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__localMem__DOT__rAddrOffset = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))) {
            __Vdly__top_SoC__DOT__localMem__DOT__rAddrOffset 
                = (0x3fffffffU & ((vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_addr 
                                   - (IData)(0x8000U)) 
                                  >> 2U));
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__localMem__DOT__readState = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__ar_determined) {
                __Vdly__top_SoC__DOT__localMem__DOT__readState = 2U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))) {
                if ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__rLatencyCounter))) {
                    __Vdly__top_SoC__DOT__localMem__DOT__readState = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))) {
                    __Vdly__top_SoC__DOT__localMem__DOT__readState = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__localMem__DOT__rLatencyCounter = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))) {
                vlTOPp->top_SoC__DOT__localMem__DOT__rLatencyCounter 
                    = vlTOPp->top_SoC__DOT__localMem__DOT___rLatencyCounter_T_1;
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))) {
                    vlTOPp->top_SoC__DOT__localMem__DOT__rLatencyCounter = 0U;
                }
            }
        }
    }
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid 
        = ((~ (IData)(vlTOPp->reset)) & ((~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid) 
                                             & ((2U 
                                                 == 
                                                 (3U 
                                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                                 ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeData_ready)
                                                 : 
                                                ((1U 
                                                  == 
                                                  (3U 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                                  ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeData_ready)
                                                  : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeData_ready))))) 
                                         & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_9)));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__wdataReg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__wdataReg 
                = vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Flush) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg 
                    = ((0x1fU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 0xfU)))
                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31
                        : ((0x1eU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                               >> 0xfU)))
                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_30
                            : ((0x1dU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                   >> 0xfU)))
                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_29
                                : ((0x1cU == (0x1fU 
                                              & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                 >> 0xfU)))
                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_28
                                    : ((0x1bU == (0x1fU 
                                                  & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                     >> 0xfU)))
                                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_27
                                        : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_26)))));
            }
        }
    }
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid 
        = ((~ (IData)(vlTOPp->reset)) & ((~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid) 
                                             & ((2U 
                                                 == 
                                                 (3U 
                                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                                 ? 
                                                ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1)) 
                                                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0))
                                                 : 
                                                ((1U 
                                                  == 
                                                  (3U 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                                  ? 
                                                 ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1)) 
                                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0))
                                                  : 
                                                 ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1)) 
                                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0)))))) 
                                         & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_3)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid 
        = ((~ (IData)(vlTOPp->reset)) & ((~ ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid) 
                                             & ((2U 
                                                 == 
                                                 (3U 
                                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                                 ? 
                                                (((1U 
                                                   > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant)) 
                                                  | (~ 
                                                     ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1) 
                                                      | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid)))) 
                                                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0))
                                                 : 
                                                ((1U 
                                                  == 
                                                  (3U 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                                  ? 
                                                 (((1U 
                                                    > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant)) 
                                                   | (~ 
                                                      ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1) 
                                                       | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid)))) 
                                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0))
                                                  : 
                                                 (((1U 
                                                    > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant)) 
                                                   | (~ 
                                                      ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1) 
                                                       | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid)))) 
                                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0)))))) 
                                         & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_3)));
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__dma__DOT__request_counter = 0U;
    } else {
        if (((4U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
             & (vlTOPp->top_SoC__DOT__dma__DOT__request_counter 
                == (0xffU & vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3)))) {
            __Vdly__top_SoC__DOT__dma__DOT__request_counter = 0U;
        } else {
            if ((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))) {
                if (((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)) 
                     & (IData)(vlTOPp->top_SoC__DOT__dma_io_master_aw_valid))) {
                    __Vdly__top_SoC__DOT__dma__DOT__request_counter 
                        = vlTOPp->top_SoC__DOT__dma__DOT___request_counter_T_1;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_10) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg 
                    = ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp))
                        : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp))
                            : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp))));
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) {
            __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid 
                = vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_36;
        } else {
            if (((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)) 
                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)) 
                 & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_b_ready))) {
                __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid = 0U;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_id = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_10) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_id 
                    = ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id))
                        : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id))
                            : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id))));
            }
        }
    }
    __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding 
        = ((~ (IData)(vlTOPp->reset)) & ((~ ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
                                               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)) 
                                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)) 
                                             & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_b_ready))) 
                                         & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_6)));
    __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding 
        = ((~ (IData)(vlTOPp->reset)) & ((~ ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
                                               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)) 
                                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)) 
                                             & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_b_ready))) 
                                         & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_0)));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding 
                = vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_35;
        } else {
            if (((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)) 
                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)) 
                 & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_b_ready))) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding = 0U;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_10) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg 
                    = ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp)
                            : 0U) : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                      ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                                          ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp)
                                          : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp)
                                                    : 0U)));
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) {
            __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid 
                = vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_36;
        } else {
            if (((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)) 
                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid)) 
                 & (4U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)))) {
                __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid = 0U;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_id = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_10) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_id 
                    = ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id)
                            : 0U) : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                      ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                                          ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id)
                                          : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id)
                                                    : 0U)));
            }
        }
    }
    __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding 
        = ((~ (IData)(vlTOPp->reset)) & ((~ ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
                                               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)) 
                                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid)) 
                                             & (4U 
                                                == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)))) 
                                         & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_6)));
    __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding 
        = ((~ (IData)(vlTOPp->reset)) & ((~ ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
                                               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)) 
                                              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid)) 
                                             & (4U 
                                                == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)))) 
                                         & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_0)));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding 
                = vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_35;
        } else {
            if (((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)) 
                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid)) 
                 & (4U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)))) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding = 0U;
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__dma__DOT__mState = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))) {
            if ((1U == vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_0)) {
                __Vdly__top_SoC__DOT__dma__DOT__mState = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))) {
                if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)))) {
                    __Vdly__top_SoC__DOT__dma__DOT__mState = 2U;
                }
            } else {
                __Vdly__top_SoC__DOT__dma__DOT__mState 
                    = ((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                        ? (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_2)
                        : (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_6));
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__cpu__DOT__rState = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState))) {
            if (((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                 & vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_5)) {
                __Vdly__top_SoC__DOT__cpu__DOT__rState = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState))) {
                if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)))) {
                    __Vdly__top_SoC__DOT__cpu__DOT__rState = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState))) {
                    __Vdly__top_SoC__DOT__cpu__DOT__rState 
                        = vlTOPp->top_SoC__DOT__cpu__DOT___GEN_12;
                }
            }
        }
    }
    if (((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
         & ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
            & (IData)(vlTOPp->top_SoC__DOT__localMem__DOT___T_10)))) {
        __Vdlyvval__top_SoC__DOT__localMem__DOT__memory__v0 
            = (((IData)(vlTOPp->top_SoC__DOT__localMem__DOT__hi) 
                << 0x10U) | (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__lo));
        __Vdlyvset__top_SoC__DOT__localMem__DOT__memory__v0 = 1U;
        __Vdlyvdim0__top_SoC__DOT__localMem__DOT__memory__v0 
            = (0x3fU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                         - (IData)(0x8000U)) >> 2U));
    }
    if (((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
         & ((1U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
            & ((4U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined))))) {
        __Vdlyvval__top_SoC__DOT__localMem__DOT__memory__v1 
            = (((IData)(vlTOPp->top_SoC__DOT__localMem__DOT__hi) 
                << 0x10U) | (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__lo));
        __Vdlyvset__top_SoC__DOT__localMem__DOT__memory__v1 = 1U;
        __Vdlyvdim0__top_SoC__DOT__localMem__DOT__memory__v1 
            = (0x3fU & vlTOPp->top_SoC__DOT__localMem__DOT__writeAddressReg);
    }
    if (((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
         & ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
            & (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___T_10)))) {
        __Vdlyvval__top_SoC__DOT__globalMem__DOT__memory__v0 
            = (((IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__hi) 
                << 0x10U) | (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__lo));
        __Vdlyvset__top_SoC__DOT__globalMem__DOT__memory__v0 = 1U;
        __Vdlyvdim0__top_SoC__DOT__globalMem__DOT__memory__v0 
            = (0x3fU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                         - (IData)(0x10000U)) >> 2U));
    }
    if (((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
         & ((1U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
            & ((4U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined))))) {
        __Vdlyvval__top_SoC__DOT__globalMem__DOT__memory__v1 
            = (((IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__hi) 
                << 0x10U) | (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__lo));
        __Vdlyvset__top_SoC__DOT__globalMem__DOT__memory__v1 = 1U;
        __Vdlyvdim0__top_SoC__DOT__globalMem__DOT__memory__v1 
            = (0x3fU & vlTOPp->top_SoC__DOT__globalMem__DOT__writeAddressReg);
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__dma__DOT__sReadIDReg = 0U;
    } else {
        if (((~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sReadState)) 
             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined))) {
            __Vdly__top_SoC__DOT__dma__DOT__sReadIDReg 
                = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_id;
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__dma__DOT__sReadAddrReg = 0U;
    } else {
        if (((~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sReadState)) 
             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined))) {
            __Vdly__top_SoC__DOT__dma__DOT__sReadAddrReg 
                = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_addr;
        }
    }
    vlTOPp->top_SoC__DOT__cpu__DOT__wState = __Vdly__top_SoC__DOT__cpu__DOT__wState;
    vlTOPp->top_SoC__DOT__dma__DOT__request_counter 
        = __Vdly__top_SoC__DOT__dma__DOT__request_counter;
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding 
        = __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding;
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid 
        = __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid;
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid 
        = __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid;
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding 
        = __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding;
    vlTOPp->top_SoC__DOT__cpu__DOT__rState = __Vdly__top_SoC__DOT__cpu__DOT__rState;
    vlTOPp->top_SoC__DOT__dma__DOT__sReadState = __Vdly__top_SoC__DOT__dma__DOT__sReadState;
    vlTOPp->io_IF_PC = vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg;
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__dma__DOT__data_buffer = 0U;
    } else {
        if (((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))) {
            vlTOPp->top_SoC__DOT__dma__DOT__data_buffer 
                = ((((((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                       & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                       ? ((8U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_29))
                           ? (0xffU & (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data 
                                       >> 0x18U)) : 0U)
                       : 0U) << 0x18U) | (((((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                                             ? ((4U 
                                                 & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_29))
                                                 ? 
                                                (0xffU 
                                                 & (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data 
                                                    >> 0x10U))
                                                 : 0U)
                                             : 0U) 
                                           << 0x10U) 
                                          | (((((2U 
                                                 == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                                & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_29))
                                                    ? 
                                                   (0xffU 
                                                    & (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data 
                                                       >> 8U))
                                                    : 0U)
                                                : 0U) 
                                              << 8U) 
                                             | (((2U 
                                                  == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_29))
                                                  ? 
                                                 (0xffU 
                                                  & vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data)
                                                  : 0U)
                                                 : 0U)))) 
                   >> ((IData)(vlTOPp->top_SoC__DOT__dma__DOT__source_offset) 
                       << 3U));
        }
    }
    vlTOPp->io_WB_PC = ((0U < vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg)
                         ? (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg 
                            - (IData)(4U)) : vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg);
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__pcReg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__pcReg 
                = vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg;
        }
    }
    if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_out_valid) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant 
            = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_chosen;
    }
    if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_out_valid) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant 
            = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_chosen;
    }
    if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_out_valid) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant 
            = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_chosen;
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg 
                = (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10);
        }
    }
    vlTOPp->io_regs_26 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_26;
    vlTOPp->io_regs_25 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_25;
    vlTOPp->io_regs_14 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_14;
    vlTOPp->io_regs_15 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_15;
    vlTOPp->io_regs_16 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_16;
    vlTOPp->io_regs_17 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_17;
    vlTOPp->io_regs_18 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_18;
    vlTOPp->io_regs_19 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_19;
    vlTOPp->io_regs_20 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_20;
    vlTOPp->io_regs_21 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_21;
    vlTOPp->io_regs_22 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_22;
    vlTOPp->io_regs_23 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_23;
    vlTOPp->io_regs_24 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_24;
    vlTOPp->io_regs_12 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_12;
    vlTOPp->io_regs_11 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_11;
    vlTOPp->io_regs_10 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_10;
    vlTOPp->io_regs_9 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_9;
    vlTOPp->io_regs_3 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_3;
    vlTOPp->io_regs_2 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_2;
    vlTOPp->io_regs_1 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_1;
    vlTOPp->io_regs_8 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_8;
    vlTOPp->io_regs_7 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_7;
    vlTOPp->io_regs_4 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_4;
    vlTOPp->io_regs_5 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_5;
    vlTOPp->io_regs_6 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_6;
    vlTOPp->io_regs_13 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_13;
    vlTOPp->top_SoC__DOT__cpu_io_master_b_ready = (
                                                   (2U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState)) 
                                                   | (1U 
                                                      == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState)));
    vlTOPp->top_SoC__DOT__globalMem__DOT___rLatencyCounter_T_1 
        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__rLatencyCounter)));
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
            if (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_2_readAddr_valid) 
                 | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_2_readAddr_valid))) {
                __Vdly__top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___T_2) {
                    __Vdly__top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
                    __Vdly__top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state 
                        = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___GEN_6;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg 
                    = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_chosen;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__ar_determined = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
            vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__ar_determined 
                = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___GEN_41;
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___T_9) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__ar_determined = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_id = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_id 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_chosen)
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id)
                                : 0U) : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                                ? (
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id)
                                                    : 0U)
                                                : 0U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_addr = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_addr 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_chosen)
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg
                                : 0U) : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                                ? (
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                                    ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg
                                                    : 0U)
                                                : 0U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_size = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_size 
                    = (3U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_chosen)
                              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                  ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                      ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size)
                                      : 0U) : 0U) : 
                             ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size)
                                   : 0U) : 0U)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_id = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___T_2) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_id 
                        = ((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                            ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                     ? 0U : ((2U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                              ? (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readID)
                                              : 0U)));
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___T_2) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data 
                        = ((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                            ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                     ? 0U : ((2U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState))
                                              ? vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                             [(0x3fU 
                                               & vlTOPp->top_SoC__DOT__globalMem__DOT__rAddrOffset)]
                                              : 0U)));
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_resp = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___T_2) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_resp = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___T_2) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last 
                        = ((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)) 
                           & (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_15));
                }
            }
        }
    }
    vlTOPp->top_SoC__DOT__localMem__DOT___rLatencyCounter_T_1 
        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__rLatencyCounter)));
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
            if (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_1_readAddr_valid) 
                 | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_1_readAddr_valid))) {
                __Vdly__top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___T_2) {
                    __Vdly__top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
                    __Vdly__top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state 
                        = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___GEN_6;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg 
                    = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_chosen;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__ar_determined = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
            vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__ar_determined 
                = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___GEN_41;
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___T_9) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__ar_determined = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_id = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_id 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_chosen)
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                            ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id)
                                : 0U) : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                                ? (
                                                   (1U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id)
                                                    : 0U)
                                                : 0U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_addr = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_addr 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_chosen)
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                            ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg
                                : 0U) : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                                ? (
                                                   (1U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                                    ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg
                                                    : 0U)
                                                : 0U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_size = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_size 
                    = (3U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_chosen)
                              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                  ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                      ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size)
                                      : 0U) : 0U) : 
                             ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size)
                                   : 0U) : 0U)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_id = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___T_2) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_id 
                        = ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                            ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                     ? 0U : ((2U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                              ? (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readID)
                                              : 0U)));
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___T_2) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data 
                        = ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                            ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                     ? 0U : ((2U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState))
                                              ? vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                             [(0x3fU 
                                               & vlTOPp->top_SoC__DOT__localMem__DOT__rAddrOffset)]
                                              : 0U)));
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_resp = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___T_2) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_resp = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___T_2) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last 
                        = ((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)) 
                           & (IData)(vlTOPp->top_SoC__DOT__localMem__DOT___GEN_15));
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Flush) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg 
                    = ((0x1fU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 0x14U)))
                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31
                        : ((0x1eU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                               >> 0x14U)))
                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_30
                            : ((0x1dU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                   >> 0x14U)))
                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_29
                                : ((0x1cU == (0x1fU 
                                              & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                 >> 0x14U)))
                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_28
                                    : ((0x1bU == (0x1fU 
                                                  & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                     >> 0x14U)))
                                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_27
                                        : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_58)))));
            }
        }
    }
    vlTOPp->io_EXE_src1 = vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg;
    if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant 
            = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen;
    }
    if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant 
            = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen;
    }
    if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant 
            = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen;
    }
    vlTOPp->top_SoC__DOT__dma__DOT___request_counter_T_1 
        = ((IData)(1U) + vlTOPp->top_SoC__DOT__dma__DOT__request_counter);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_1 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)) 
           & (1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState)));
    vlTOPp->top_SoC__DOT__cpu__DOT___GEN_2 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)
                                               ? 0U
                                               : (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState));
    vlTOPp->top_SoC__DOT__cpu_io_master_r_ready = (
                                                   (2U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState)) 
                                                   | (1U 
                                                      == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState)));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__localMem__DOT__writeAddressReg = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))) {
                vlTOPp->top_SoC__DOT__localMem__DOT__writeAddressReg 
                    = ((IData)(vlTOPp->top_SoC__DOT__localMem__DOT___T_10)
                        ? (0x3fffffffU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                           - (IData)(0x8000U)) 
                                          >> 2U)) : vlTOPp->top_SoC__DOT__localMem__DOT___GEN_58);
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__localMem__DOT__writeID = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))) {
                vlTOPp->top_SoC__DOT__localMem__DOT__writeID 
                    = ((IData)(vlTOPp->top_SoC__DOT__localMem__DOT___T_10)
                        ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_id)
                        : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT___GEN_59));
            }
        }
    }
    __Vdly__top_SoC__DOT__localMem__DOT__writeState 
        = ((IData)(vlTOPp->reset) ? 0U : ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                           ? 1U : (
                                                   (1U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                                    ? 
                                                   (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined) 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined))
                                                     ? 3U
                                                     : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT___GEN_31))
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                                     ? (IData)(vlTOPp->top_SoC__DOT__localMem__DOT___GEN_34)
                                                     : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT___GEN_38)))));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__localMem__DOT__wLatencyCounter = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))) {
            if ((1U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))) {
                if ((4U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))) {
                    vlTOPp->top_SoC__DOT__localMem__DOT__wLatencyCounter 
                        = vlTOPp->top_SoC__DOT__localMem__DOT___GEN_76;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__globalMem__DOT__writeAddressReg = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))) {
                vlTOPp->top_SoC__DOT__globalMem__DOT__writeAddressReg 
                    = ((IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___T_10)
                        ? (0x3fffffffU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                           - (IData)(0x10000U)) 
                                          >> 2U)) : vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_58);
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__globalMem__DOT__writeID = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))) {
                vlTOPp->top_SoC__DOT__globalMem__DOT__writeID 
                    = ((IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___T_10)
                        ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_id)
                        : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_59));
            }
        }
    }
    __Vdly__top_SoC__DOT__globalMem__DOT__writeState 
        = ((IData)(vlTOPp->reset) ? 0U : ((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                           ? 1U : (
                                                   (1U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                                    ? 
                                                   (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined) 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined))
                                                     ? 2U
                                                     : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_31))
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                                     ? (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_34)
                                                     : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_38)))));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__globalMem__DOT__wLatencyCounter = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))) {
            if ((1U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))) {
                if ((4U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))) {
                    vlTOPp->top_SoC__DOT__globalMem__DOT__wLatencyCounter 
                        = vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_76;
                }
            }
        }
    }
    vlTOPp->top_SoC__DOT__dma__DOT___io_slave_ar_ready_T 
        = (1U & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sReadState)));
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
            if (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_0_readAddr_valid) 
                 | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_0_readAddr_valid))) {
                __Vdly__top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___T_2) {
                    __Vdly__top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
                    __Vdly__top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state 
                        = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___GEN_6;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg 
                    = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_chosen;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
            vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined 
                = vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___GEN_41;
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___T_9) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_id = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_id 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_chosen)
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                            ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id)
                                : 0U) : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                                ? (
                                                   (0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id)
                                                    : 0U)
                                                : 0U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_addr = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_addr 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_chosen)
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                            ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg
                                : 0U) : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                                                ? (
                                                   (0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                                    ? vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg
                                                    : 0U)
                                                : 0U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_size = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_size 
                    = (3U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_chosen)
                              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
                                  ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                                      ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size)
                                      : 0U) : 0U) : 
                             ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size)
                                   : 0U) : 0U)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_id = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___T_2) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_id 
                        = vlTOPp->top_SoC__DOT__dma__DOT__sReadIDReg;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___T_2) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data 
                        = ((0x14U == vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg)
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
                                                : 0U))))));
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_resp = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___T_2) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_resp = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___T_2) {
                    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last = 1U;
                }
            }
        }
    }
    vlTOPp->top_SoC__DOT__globalMem__DOT__readID = __Vdly__top_SoC__DOT__globalMem__DOT__readID;
    vlTOPp->top_SoC__DOT__globalMem__DOT__rAddrOffset 
        = __Vdly__top_SoC__DOT__globalMem__DOT__rAddrOffset;
    vlTOPp->top_SoC__DOT__globalMem__DOT__readState 
        = __Vdly__top_SoC__DOT__globalMem__DOT__readState;
    if (__Vdlyvset__top_SoC__DOT__globalMem__DOT__memory__v0) {
        vlTOPp->top_SoC__DOT__globalMem__DOT__memory[__Vdlyvdim0__top_SoC__DOT__globalMem__DOT__memory__v0] 
            = __Vdlyvval__top_SoC__DOT__globalMem__DOT__memory__v0;
    }
    if (__Vdlyvset__top_SoC__DOT__globalMem__DOT__memory__v1) {
        vlTOPp->top_SoC__DOT__globalMem__DOT__memory[__Vdlyvdim0__top_SoC__DOT__globalMem__DOT__memory__v1] 
            = __Vdlyvval__top_SoC__DOT__globalMem__DOT__memory__v1;
    }
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state 
        = __Vdly__top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state;
    vlTOPp->top_SoC__DOT__localMem__DOT__readID = __Vdly__top_SoC__DOT__localMem__DOT__readID;
    vlTOPp->top_SoC__DOT__localMem__DOT__rAddrOffset 
        = __Vdly__top_SoC__DOT__localMem__DOT__rAddrOffset;
    vlTOPp->top_SoC__DOT__localMem__DOT__readState 
        = __Vdly__top_SoC__DOT__localMem__DOT__readState;
    if (__Vdlyvset__top_SoC__DOT__localMem__DOT__memory__v0) {
        vlTOPp->top_SoC__DOT__localMem__DOT__memory[__Vdlyvdim0__top_SoC__DOT__localMem__DOT__memory__v0] 
            = __Vdlyvval__top_SoC__DOT__localMem__DOT__memory__v0;
    }
    if (__Vdlyvset__top_SoC__DOT__localMem__DOT__memory__v1) {
        vlTOPp->top_SoC__DOT__localMem__DOT__memory[__Vdlyvdim0__top_SoC__DOT__localMem__DOT__memory__v1] 
            = __Vdlyvval__top_SoC__DOT__localMem__DOT__memory__v1;
    }
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state 
        = __Vdly__top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state;
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_6 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_9 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid));
    vlTOPp->top_SoC__DOT__localMem__DOT__writeState 
        = __Vdly__top_SoC__DOT__localMem__DOT__writeState;
    vlTOPp->top_SoC__DOT__globalMem__DOT__writeState 
        = __Vdly__top_SoC__DOT__globalMem__DOT__writeState;
    vlTOPp->top_SoC__DOT__dma__DOT__sReadIDReg = __Vdly__top_SoC__DOT__dma__DOT__sReadIDReg;
    vlTOPp->top_SoC__DOT__dma__DOT__sReadAddrReg = __Vdly__top_SoC__DOT__dma__DOT__sReadAddrReg;
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding 
        = __Vdly__top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding;
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state 
        = __Vdly__top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state;
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding 
        = __Vdly__top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding;
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__dma__DOT__source_offset = 0U;
    } else {
        if ((1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))) {
            vlTOPp->top_SoC__DOT__dma__DOT__source_offset 
                = (3U & (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_22));
        }
    }
    vlTOPp->io_MEM_PC = vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__pcReg;
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Flush) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg;
            }
        }
    }
    vlTOPp->io_raddr = vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg;
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___T_9 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__ar_determined));
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_15 = 
        ((1U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)) 
         & (2U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_1_readData_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
              & ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_0_readData_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
              & ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
                 & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
           | ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
              & (2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___T_9 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__ar_determined));
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_15 = 
        ((1U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)) 
         & (2U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_1_readData_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
              & ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_0_readData_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
              & ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
                 & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
           | ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
              & (2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))));
    vlTOPp->io_EXE_src2 = vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg;
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrEq 
        = (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg 
           == vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg);
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x1fU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_30 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x1eU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_30 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_29 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x1dU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_29 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_28 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x1cU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_28 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_27 = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn) {
            if ((0x1bU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                    >> 7U)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_27 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
            }
        }
    }
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_76 = 
        (0xffU & ((2U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                   ? ((IData)(1U) + (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__wLatencyCounter))
                   : ((3U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                       ? 0U : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__wLatencyCounter))));
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
            if (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeAddr_valid) 
                 | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeAddr_valid))) {
                __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_1)
                        ? 2U : 1U);
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_5) {
                    __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state = 2U;
                }
            } else {
                __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state 
                    = ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))
                        ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_11)
                        : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_17));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg 
                    = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined 
                    = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_52;
            }
        } else {
            if ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_88;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined 
                = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_66;
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined 
                    = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_84;
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_84;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_id = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_id 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                            ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id)
                                : 0U) : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                                ? (
                                                   (1U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id)
                                                    : 0U)
                                                : 0U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                            ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg
                                : 0U) : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                                ? (
                                                   (1U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                                    ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg
                                                    : 0U)
                                                : 0U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_size = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_size 
                    = (3U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)
                              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                                  ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                      ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size)
                                      : 0U) : 0U) : 
                             ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                               ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size)
                                   : 0U) : 0U)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_1) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)
                            ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_data
                            : vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_data);
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_5) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_76;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_1) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb 
                        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)
                            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_strb)
                            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_strb));
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_5) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_78;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_last = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_1) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_last 
                        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)
                            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_last)
                            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_last));
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_5) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_last 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_80;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
            if ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_89;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
            if ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_90;
                }
            }
        }
    }
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_76 = 
        (0xffU & ((2U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                   ? ((IData)(1U) + (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__wLatencyCounter))
                   : ((3U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                       ? 0U : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__wLatencyCounter))));
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
            if (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeAddr_valid) 
                 | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeAddr_valid))) {
                __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_1)
                        ? 2U : 1U);
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_5) {
                    __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state = 2U;
                }
            } else {
                __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state 
                    = ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))
                        ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_11)
                        : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_17));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg 
                    = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined 
                    = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_52;
            }
        } else {
            if ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_88;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined 
                = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_66;
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined 
                    = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_84;
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_84;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_id = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_id 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id)
                                : 0U) : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                                ? (
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id)
                                                    : 0U)
                                                : 0U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg
                                : 0U) : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                                ? (
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                                    ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg
                                                    : 0U)
                                                : 0U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_size = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_size 
                    = (3U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)
                              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                                  ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                      ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size)
                                      : 0U) : 0U) : 
                             ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                               ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size)
                                   : 0U) : 0U)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_1) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)
                            ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_data
                            : vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_data);
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_5) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_76;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_1) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb 
                        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)
                            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_strb)
                            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_strb));
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_5) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_78;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_last = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_1) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_last 
                        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)
                            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_last)
                            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_last));
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_5) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_last 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_80;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
            if ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_89;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
            if ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_90;
                }
            }
        }
    }
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_10 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined) 
                                               | (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sReadState));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___T_9 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sReadState)) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id = 0U;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id = 0U;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size = 2U;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size = 2U;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg 
                = vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg 
                = (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_22);
        }
    }
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_out_readData_ready 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
           & (1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_1_readData_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
              & ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_0_readData_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
              & ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
                 & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
           | ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
              & (2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg 
                = ((0x64U > vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr)
                    ? 0U : (((0x8000U <= vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr) 
                             & (0x8800U > vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr))
                             ? 1U : (((0x10000U <= vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr) 
                                      & (0x10800U > vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr))
                                      ? 2U : 0U)));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg 
                = ((0x64U > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_22))
                    ? 0U : (((0x8000U <= (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_22)) 
                             & (0x8800U > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_22)))
                             ? 1U : (((0x10000U <= (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_22)) 
                                      & (0x10800U > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_22)))
                                      ? 2U : 0U)));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_4 = 0U;
    } else {
        if (((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)) 
             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready))) {
            if ((0U != vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)) {
                if ((4U != vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)) {
                    vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_4 
                        = vlTOPp->top_SoC__DOT__dma__DOT___GEN_66;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_2 = 0U;
    } else {
        if (((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)) 
             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready))) {
            if ((0U != vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)) {
                if ((4U != vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)) {
                    vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_2 
                        = vlTOPp->top_SoC__DOT__dma__DOT___GEN_64;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 = 0U;
    } else {
        if (((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)) 
             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready))) {
            if ((0U != vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)) {
                if ((4U != vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)) {
                    vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                        = vlTOPp->top_SoC__DOT__dma__DOT___GEN_65;
                }
            }
        }
    }
    vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_5 = ((IData)(vlTOPp->reset)
                                                    ? 0U
                                                    : 
                                                   (((2U 
                                                      == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)) 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready))
                                                     ? 
                                                    ((0U 
                                                      == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                      ? vlTOPp->top_SoC__DOT__dma__DOT___GEN_41
                                                      : 
                                                     ((4U 
                                                       == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                       ? vlTOPp->top_SoC__DOT__dma__DOT___GEN_41
                                                       : 
                                                      ((8U 
                                                        == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                        ? vlTOPp->top_SoC__DOT__dma__DOT___GEN_41
                                                        : 
                                                       ((0xcU 
                                                         == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                         ? vlTOPp->top_SoC__DOT__dma__DOT___GEN_41
                                                         : 
                                                        ((0x10U 
                                                          == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                          ? vlTOPp->top_SoC__DOT__dma__DOT___GEN_41
                                                          : 
                                                         ((0x14U 
                                                           == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                           ? vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg
                                                           : vlTOPp->top_SoC__DOT__dma__DOT___GEN_41))))))
                                                     : vlTOPp->top_SoC__DOT__dma__DOT___GEN_41));
    vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_0 = ((IData)(vlTOPp->reset)
                                                    ? 0U
                                                    : 
                                                   (((2U 
                                                      == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)) 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready))
                                                     ? 
                                                    ((0U 
                                                      == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                      ? vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg
                                                      : vlTOPp->top_SoC__DOT__dma__DOT___GEN_40)
                                                     : vlTOPp->top_SoC__DOT__dma__DOT___GEN_40));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_1 = 0U;
    } else {
        if (((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)) 
             & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready))) {
            if ((0U != vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)) {
                if ((4U == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)) {
                    vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_1 
                        = vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg;
                }
            }
        }
    }
    vlTOPp->top_SoC__DOT__dma__DOT__mState = __Vdly__top_SoC__DOT__dma__DOT__mState;
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___T_2 
        = (((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
            & (1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) 
           & ((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)) 
              & (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_15)));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___T_2 
        = (((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
            & (1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) 
           & ((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)) 
              & (IData)(vlTOPp->top_SoC__DOT__localMem__DOT___GEN_15)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state 
        = __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state;
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state 
        = __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state;
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___T_2 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_out_readData_ready) 
           & (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sReadState));
    vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr 
        = ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState))
            ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg
            : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___T 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)) 
           & (1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState)));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_44 = ((3U 
                                                == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                               & ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)) 
                                                  | (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteDataSent)));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_6 = ((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                               ? (((IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteAddrSent) 
                                                   & (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteDataSent))
                                                   ? 4U
                                                   : (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                               : ((4U 
                                                   == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                                   ? 
                                                  ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid)
                                                    ? 0U
                                                    : (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                                   : (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___T 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)) 
           & (1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_1 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)) 
           & ((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteDataSent))));
    vlTOPp->top_SoC__DOT__dma_io_master_aw_valid = 
        ((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
         & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteAddrSent)));
    vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg 
        = (0x7fffU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT___GEN_4);
    vlTOPp->io_EXE_PC = vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg;
    vlTOPp->io_regs_31 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31;
    vlTOPp->io_regs_30 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_30;
    vlTOPp->io_regs_29 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_29;
    vlTOPp->io_regs_28 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_28;
    vlTOPp->io_regs_27 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_27;
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                = vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg;
        }
    }
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_88 
        = ((~ (((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                & ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                   | (4U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)))) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined))) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined));
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_34 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined)
          ? 3U : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState));
    vlTOPp->top_SoC__DOT__localMem__DOT__lo = ((0xff00U 
                                                & (((2U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                                     ? 
                                                    (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                                                     >> 8U)
                                                     : 
                                                    (vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                                     [
                                                     (0x3fU 
                                                      & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                          - (IData)(0x8000U)) 
                                                         >> 2U))] 
                                                     >> 8U)) 
                                                   << 8U)) 
                                               | (0xffU 
                                                  & ((1U 
                                                      & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                                      ? vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data
                                                      : 
                                                     vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                                     [
                                                     (0x3fU 
                                                      & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                          - (IData)(0x8000U)) 
                                                         >> 2U))])));
    vlTOPp->top_SoC__DOT__localMem__DOT__hi = ((0xff00U 
                                                & (((8U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                                     ? 
                                                    (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                                                     >> 0x18U)
                                                     : 
                                                    (vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                                     [
                                                     (0x3fU 
                                                      & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                          - (IData)(0x8000U)) 
                                                         >> 2U))] 
                                                     >> 0x18U)) 
                                                   << 8U)) 
                                               | (0xffU 
                                                  & ((4U 
                                                      & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                                      ? 
                                                     (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                                                      >> 0x10U)
                                                      : 
                                                     (vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                                      [
                                                      (0x3fU 
                                                       & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                           - (IData)(0x8000U)) 
                                                          >> 2U))] 
                                                      >> 0x10U))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_84 
        = ((~ (((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                & (1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined))) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined));
    vlTOPp->top_SoC__DOT__localMem__DOT___T_10 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined) 
                                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined));
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_31 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined)
          ? 4U : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState));
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_58 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined)
          ? (0x3fffffffU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                             - (IData)(0x8000U)) >> 2U))
          : vlTOPp->top_SoC__DOT__localMem__DOT__writeAddressReg);
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_59 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined)
          ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_id)
          : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeID));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_out_writeResp_ready 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
              & (2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeResp_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
                 & ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
                    & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg))))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeResp_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
                 & ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
           | ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
                 & (3U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_88 
        = ((~ (((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                & ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                   | (4U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)))) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined))) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined));
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_34 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined)
          ? 2U : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState));
    vlTOPp->top_SoC__DOT__globalMem__DOT__lo = ((0xff00U 
                                                 & (((2U 
                                                      & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                                      ? 
                                                     (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                                                      >> 8U)
                                                      : 
                                                     (vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                                      [
                                                      (0x3fU 
                                                       & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                           - (IData)(0x10000U)) 
                                                          >> 2U))] 
                                                      >> 8U)) 
                                                    << 8U)) 
                                                | (0xffU 
                                                   & ((1U 
                                                       & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                                       ? vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data
                                                       : 
                                                      vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                                      [
                                                      (0x3fU 
                                                       & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                           - (IData)(0x10000U)) 
                                                          >> 2U))])));
    vlTOPp->top_SoC__DOT__globalMem__DOT__hi = ((0xff00U 
                                                 & (((8U 
                                                      & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                                      ? 
                                                     (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                                                      >> 0x18U)
                                                      : 
                                                     (vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                                      [
                                                      (0x3fU 
                                                       & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                           - (IData)(0x10000U)) 
                                                          >> 2U))] 
                                                      >> 0x18U)) 
                                                    << 8U)) 
                                                | (0xffU 
                                                   & ((4U 
                                                       & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                                       ? 
                                                      (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                                                       >> 0x10U)
                                                       : 
                                                      (vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                                       [
                                                       (0x3fU 
                                                        & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                            - (IData)(0x10000U)) 
                                                           >> 2U))] 
                                                       >> 0x10U))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_84 
        = ((~ (((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                & (1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined))) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined));
    vlTOPp->top_SoC__DOT__globalMem__DOT___T_10 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined) 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined));
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_31 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined)
          ? 4U : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState));
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_58 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined)
          ? (0x3fffffffU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                             - (IData)(0x10000U)) >> 2U))
          : vlTOPp->top_SoC__DOT__globalMem__DOT__writeAddressReg);
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_59 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined)
          ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_id)
          : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeID));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_out_writeResp_ready 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
              & (2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeResp_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
                 & ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
                    & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg))))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeResp_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
                 & ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
           | ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
                 & (3U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)))));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___GEN_0 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___GEN_5 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                    ? 0U : vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data)
                : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                    ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                        ? 0U : vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data)
                    : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                        ? 0U : vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data)))
            : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_0_readData_valid)
               : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_0_readData_valid)
                   : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_0_readData_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_0_readAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_1_readAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_2_readAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                    ? vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data
                    : 0U) : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                  ? vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data
                                  : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                            ? vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data
                                            : 0U)))
            : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___GEN_6 
        = ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                 & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
                    & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))))
              : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                 & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
                    & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready)))) 
            & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_1_readData_valid)
                : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_0_readData_valid)))
            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___GEN_6 
        = ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                 & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
                    & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))))
              : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                 & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
                    & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready)))) 
            & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_1_readData_valid)
                : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_0_readData_valid)))
            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___GEN_6 
        = ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                 & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
                    & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))))
              : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                 & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
                    & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready)))) 
            & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_1_readData_valid)
                : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_0_readData_valid)))
            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_1_readData_valid)
               : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_1_readData_valid)
                   : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_1_readData_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_0_readAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_1_readAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_2_readAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__dma__DOT___mask_width_T_8 
        = ((4U == (0xffU & (vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                            >> 8U))) ? 0xfU : ((3U 
                                                == 
                                                (0xffU 
                                                 & (vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                                                    >> 8U)))
                                                ? 7U
                                                : (
                                                   (2U 
                                                    == 
                                                    (0xffU 
                                                     & (vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                                                        >> 8U)))
                                                    ? 3U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0xffU 
                                                      & (vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                                                         >> 8U)))
                                                     ? 1U
                                                     : 0xfU))));
    vlTOPp->io_DMA_Hcf = (1U & vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_5);
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_41 = (((4U 
                                                 == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                                & (vlTOPp->top_SoC__DOT__dma__DOT__request_counter 
                                                   == 
                                                   (0xffU 
                                                    & vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3)))
                                                ? 1U
                                                : vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_5);
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_40 = (((4U 
                                                 == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                                & (vlTOPp->top_SoC__DOT__dma__DOT__request_counter 
                                                   == 
                                                   (0xffU 
                                                    & vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3)))
                                                ? 0U
                                                : vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_0);
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_22 = ((1U 
                                                == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                                ? (VL_ULL(0xffffffffff) 
                                                   & ((QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_1)) 
                                                      + 
                                                      ((QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__request_counter)) 
                                                       * (QData)((IData)(
                                                                         (0xffU 
                                                                          & (vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                                                                             >> 0x18U)))))))
                                                : VL_ULL(0));
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__dma__DOT__sWriteState = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState))) {
            if (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined) 
                 | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined))) {
                __Vdly__top_SoC__DOT__dma__DOT__sWriteState = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState))) {
                if (((IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv) 
                     & (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv))) {
                    __Vdly__top_SoC__DOT__dma__DOT__sWriteState = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState))) {
                    __Vdly__top_SoC__DOT__dma__DOT__sWriteState 
                        = vlTOPp->top_SoC__DOT__dma__DOT___GEN_16;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__dma__DOT__sWriteIDReg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__dma__DOT___io_slave_aw_ready_T_2) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined) {
                if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv)))) {
                    vlTOPp->top_SoC__DOT__dma__DOT__sWriteIDReg 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_id;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__dma__DOT___io_slave_aw_ready_T_2) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined) {
                if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv)))) {
                    vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_data;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__dma__DOT___io_slave_aw_ready_T_2) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined) {
                if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv)))) {
                    vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_addr;
                }
            }
        }
    }
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___GEN_0 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___GEN_5 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_6 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_9 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid));
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_38 = 
        ((2U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
          ? ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__wLatencyCounter))
              ? 3U : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
          : ((3U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_out_writeResp_ready)
                  ? 1U : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
              : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_7 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_out_writeResp_ready) 
           & ((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
              & ((1U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                 & ((4U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                    & ((2U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                       & (3U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)))))));
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_38 = 
        ((2U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
          ? ((0x4fU == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__wLatencyCounter))
              ? 3U : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
          : ((3U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_out_writeResp_ready)
                  ? 1U : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
              : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_7 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_out_writeResp_ready) 
           & ((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
              & ((1U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                 & ((4U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                    & ((2U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                       & (3U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)))))));
    vlTOPp->io_rdata = vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_bits_data;
    vlTOPp->top_SoC__DOT__cpu__DOT___GEN_12 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_valid)
                                                ? 0U
                                                : (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_0_readAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_1_readAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_2_readAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_2 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid)
                                               ? 3U
                                               : (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_1_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_0_readAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_1_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_1_readAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_1_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_2_readAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0));
    vlTOPp->top_SoC__DOT__dma__DOT__mask_width = ((3U 
                                                   == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                                   ? (IData)(vlTOPp->top_SoC__DOT__dma__DOT___mask_width_T_8)
                                                   : 
                                                  (((2U 
                                                     == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__dma__DOT___mask_width_T_8)
                                                    : 0U));
    vlTOPp->io_ID_PC = vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg;
    vlTOPp->io_WB_rd = (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                 >> 7U));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn 
        = ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
           | ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
              | ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                 | ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                    | ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                       | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                          | (0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_WBSel 
        = ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg))
            ? 2U : ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                    | ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                       | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                          | ((0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                             | ((0x67U != (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                                & (0x6fU != (0x7fU 
                                             & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd 
        = ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
           | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
              | ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                 | ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                    | ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                       | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                          | (0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg))))))));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                = vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg;
        }
    }
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_11 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_7)
            ? 3U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_90 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_7)
            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_89 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_7)
            ? ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                         ? 0U : ((4U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                  ? 0U : ((2U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                           ? 0U : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeID)
                                                    : 0U)))))
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_11 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_7)
            ? 3U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_90 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_7)
            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_89 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_7)
            ? ((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                         ? 0U : ((4U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                  ? 0U : ((2U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                           ? 0U : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeID)
                                                    : 0U)))))
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_1_valid) 
           & (1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant)));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_1_valid) 
           & (1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant)));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_1_valid) 
           & (1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant)));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_29 = (((2U 
                                                 == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                                & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                                                ? (0x7fU 
                                                   & ((IData)(vlTOPp->top_SoC__DOT__dma__DOT__mask_width) 
                                                      << (IData)(vlTOPp->top_SoC__DOT__dma__DOT__source_offset)))
                                                : 0U);
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_64 = ((8U 
                                                == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                ? vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg
                                                : vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_2);
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_65 = ((8U 
                                                == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3
                                                : (
                                                   (0xcU 
                                                    == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                    ? vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg
                                                    : vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_66 = ((8U 
                                                == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_4
                                                : (
                                                   (0xcU 
                                                    == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                    ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_4
                                                    : 
                                                   ((0x10U 
                                                     == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                     ? vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg
                                                     : vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_4)));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__dma__DOT___io_slave_aw_ready_T_2) {
            vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv 
                = vlTOPp->top_SoC__DOT__dma__DOT___GEN_49;
        } else {
            if ((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState))) {
                vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv = 0U;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__dma__DOT___io_slave_aw_ready_T_2) {
            vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv 
                = vlTOPp->top_SoC__DOT__dma__DOT___GEN_46;
        } else {
            if ((2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState))) {
                vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv = 0U;
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
            if (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeAddr_valid) 
                 | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeAddr_valid))) {
                __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_1)
                        ? 2U : 1U);
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_5) {
                    __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state = 2U;
                }
            } else {
                __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state 
                    = ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))
                        ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_11)
                        : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_17));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg 
                    = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined 
                    = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_52;
            }
        } else {
            if ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_88;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined 
                = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_66;
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined 
                    = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_84;
            } else {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_84;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_id = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_id 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                            ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id)
                                : 0U) : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                                ? (
                                                   (0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id)
                                                    : 0U)
                                                : 0U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_addr = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_addr 
                    = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)
                        ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                            ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg
                                : 0U) : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                                                ? (
                                                   (0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                                    ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg
                                                    : 0U)
                                                : 0U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_size = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) {
                vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_size 
                    = (3U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)
                              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
                                  ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                                      ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size)
                                      : 0U) : 0U) : 
                             ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
                               ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size)
                                   : 0U) : 0U)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_data = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_1) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_data 
                        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)
                            ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_data
                            : vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_data);
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_5) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_data 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_76;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_strb = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_1) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_strb 
                        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)
                            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_strb)
                            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_strb));
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_5) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_strb 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_78;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_last = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
            if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_1) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_last 
                        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)
                            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_last)
                            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_last));
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
                if (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_5) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_last 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_80;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
            if ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_89;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
            if ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
                if ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))) {
                    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp 
                        = vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_90;
                }
            }
        }
    }
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata 
        = ((2U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_WBSel))
            ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__ld_data_Reg
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_WBSel))
                ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__alu_out_Reg
                : ((0U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_WBSel))
                    ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg
                    : 0U)));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_chosen 
        = (1U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1) 
                 | (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_chosen 
        = (1U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1) 
                 | (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_chosen 
        = (1U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1) 
                 | (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid))));
    vlTOPp->top_SoC__DOT__dma__DOT__sWriteState = __Vdly__top_SoC__DOT__dma__DOT__sWriteState;
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state 
        = __Vdly__top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state;
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding 
        = __Vdly__top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding;
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding 
        = __Vdly__top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding;
    vlTOPp->io_WB_wdata = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_MEM_io_Mem_Data 
        = ((vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_bits_data 
            & ((2U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                             >> 0xcU))) ? 0xffffffffU
                : ((1U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                 >> 0xcU))) ? ((1U 
                                                == 
                                                (2U 
                                                 & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                ? 0xffff0000U
                                                : 0xffffU)
                    : ((0U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                     >> 0xcU))) ? (
                                                   (3U 
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
                        : 0xffffffffU)))) >> ((2U == 
                                               (7U 
                                                & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                   >> 0xcU)))
                                               ? 0U
                                               : ((1U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                       >> 0xcU)))
                                                   ? 
                                                  ((1U 
                                                    == 
                                                    (2U 
                                                     & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                    ? 0x10U
                                                    : 0U)
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
                                                     ? 0x18U
                                                     : 
                                                    ((2U 
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
                                                    : 0U))));
    vlTOPp->top_SoC__DOT__cpu__DOT___GEN_8 = ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState))
                                               ? (VL_ULL(0x7fffffffffffffff) 
                                                  & ((QData)((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__wdataReg)) 
                                                     << 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                           >> 0xcU)))
                                                       ? 0U
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                            >> 0xcU)))
                                                        ? 
                                                       ((1U 
                                                         == 
                                                         (2U 
                                                          & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                         ? 0x10U
                                                         : 0U)
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
                                                          ? 0x18U
                                                          : 
                                                         ((2U 
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
                                                         : 0U)))))
                                               : VL_ULL(0));
    vlTOPp->top_SoC__DOT__cpu_io_Stall_MA = (((3U == 
                                               (0x7fU 
                                                & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                                              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_valid))) 
                                             | ((0x23U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                                                & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd 
        = ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
           | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
              | ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                 | ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                    | ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                       | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                          | (0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg))))))));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Flush) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                    = vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg;
            }
        }
    }
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_out_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_chosen)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_1_valid)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_out_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_chosen)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_1_valid)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_out_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_chosen)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_1_valid)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid));
    vlTOPp->top_SoC__DOT__dma__DOT___io_slave_aw_ready_T_2 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)) 
           | (1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_49 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined) 
                                               | (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_46 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined) 
                                               | (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_84 
        = ((~ ((((0U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)) 
                 | (1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState))) 
                & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv))) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined))) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id = 0U;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id = 0U;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size = 2U;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size = 2U;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg 
                = vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg 
                = (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_35);
        }
    }
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
              & (2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeResp_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
                 & ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
                    & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg))))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeResp_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
                 & ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
           | ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
                 & (3U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)))));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_45 = ((3U 
                                                == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                               & ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)) 
                                                  | (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteAddrSent)));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg 
                = ((0x64U > vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr)
                    ? 0U : (((0x8000U <= vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr) 
                             & (0x8800U > vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr))
                             ? 1U : (((0x10000U <= vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr) 
                                      & (0x10800U > vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr))
                                      ? 2U : 0U)));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T) {
            vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg 
                = ((0x64U > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_35))
                    ? 0U : (((0x8000U <= (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_35)) 
                             & (0x8800U > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_35)))
                             ? 1U : (((0x10000U <= (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_35)) 
                                      & (0x10800U > (IData)(vlTOPp->top_SoC__DOT__dma__DOT___GEN_35)))
                                      ? 2U : 0U)));
        }
    }
    vlTOPp->io_wdata = (IData)(vlTOPp->top_SoC__DOT__cpu__DOT___GEN_8);
    vlTOPp->io_Stall_MA = vlTOPp->top_SoC__DOT__cpu_io_Stall_MA;
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___GEN_41 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_out_valid) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___GEN_41 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_out_valid) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__ar_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___GEN_41 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_out_valid) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__ar_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_88 
        = ((~ (((IData)(vlTOPp->top_SoC__DOT__dma__DOT___io_slave_aw_ready_T_2) 
                & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv))) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined))) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_16 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready)
                                                ? 0U
                                                : (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_7 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready) 
           & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)));
    vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr 
        = ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState))
            ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg
            : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)) 
           & (1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState)));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_35 = ((3U 
                                                == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                                ? (VL_ULL(0xffffffffff) 
                                                   & ((QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_2)) 
                                                      + 
                                                      ((QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__request_counter)) 
                                                       * (QData)((IData)(
                                                                         (0xffU 
                                                                          & (vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                                                                             >> 0x10U)))))))
                                                : VL_ULL(0));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)) 
           & (IData)(vlTOPp->top_SoC__DOT__dma_io_master_aw_valid));
    if (vlTOPp->reset) {
        vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg = 0U;
    } else {
        if (vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH) {
            vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID_io_Stall)))) {
                vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                    = vlTOPp->top_SoC__DOT__im_io_inst;
            }
        }
    }
    vlTOPp->io_EXE_Jump = ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                           | (0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)));
    vlTOPp->io_EXE_Branch = (0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd 
        = ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
           | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
              | ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                 | ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                    | ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                       | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                          | (0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT 
        = ((0x2000U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)
            ? (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg 
               < vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg)
            : VL_LTS_III(1,32,32, vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg, vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___io_E_ALUSel_T_1 
        = (0xf8U | ((0x7f00U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                >> 0x11U)) | (7U & 
                                              (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                               >> 0xcU))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_BSel 
        = ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
           | ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
              | ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                 | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                    | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                       | ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                          | ((0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                             | ((0x23U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                                | (3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ASel 
        = ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))
            ? 1U : ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))
                     ? 2U : ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                             | (0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_11 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_7)
            ? 3U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_90 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_7)
            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_89 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_7)
            ? (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteIDReg)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_0 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_3 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
            ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_strb 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
            ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_strb)
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_last 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_last)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
            ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_strb 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
            ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_strb)
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_last 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_last)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_strb 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_strb)
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_last 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_last)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeResp_ready 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeResp_ready 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeResp_ready 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_0 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_3 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
            ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_strb 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
            ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_strb)
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_last 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_last)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
            ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_strb 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
            ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_strb)
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_last 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_last)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_strb 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_strb)
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_last 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_last)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeResp_ready 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeResp_ready 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeResp_ready 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__im_io_inst = (((vlTOPp->top_SoC__DOT__im__DOT__memory
                                          [(0x7fffU 
                                            & ((IData)(3U) 
                                               + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))] 
                                          << 0x18U) 
                                         | (vlTOPp->top_SoC__DOT__im__DOT__memory
                                            [(0x7fffU 
                                              & ((IData)(2U) 
                                                 + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))] 
                                            << 0x10U)) 
                                        | ((vlTOPp->top_SoC__DOT__im__DOT__memory
                                            [(0x7fffU 
                                              & ((IData)(1U) 
                                                 + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))] 
                                            << 8U) 
                                           | vlTOPp->top_SoC__DOT__im__DOT__memory
                                           [(0x7fffU 
                                             & vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg)]));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___E_Branch_taken_T_14 
        = (1U & ((7U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                               >> 0xcU))) ? (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT))
                  : ((6U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                   >> 0xcU))) ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT)
                      : ((5U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                       >> 0xcU))) ? 
                         (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT))
                          : ((4U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                           >> 0xcU)))
                              ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT)
                              : ((1U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                               >> 0xcU)))
                                  ? (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrEq))
                                  : ((0U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                                   >> 0xcU))) 
                                     & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrEq))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel 
        = ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))
            ? ((5U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                             >> 0xcU))) ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___io_E_ALUSel_T_1)
                : (0xf8U | (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                  >> 0xcU)))) : ((0x33U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))
                                                  ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___io_E_ALUSel_T_1)
                                                  : 0xf8U));
    vlTOPp->io_ALU_src2 = ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_BSel)
                            ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__immReg
                            : vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg);
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2 
        = ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_BSel)
            ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__immReg
            : vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg);
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT___alu_src1_T_3 
        = ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ASel))
            ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg
            : vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_10 
        = (((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeResp_ready)
             : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                 ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeResp_ready)
                 : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeResp_ready))) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeResp_valid)
               : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeResp_valid)
                   : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeResp_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_76 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
            ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_data
            : vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_data);
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_78 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_strb)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_strb));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_80 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_last)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_last));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_76 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
            ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_data
            : vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_data);
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_78 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_strb)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_strb));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_80 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_last)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_last));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_76 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
            ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_data
            : vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_data);
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_78 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_strb)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_strb));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_80 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_last)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_last));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_17 
        = ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))
            ? ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                  ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeResp_ready)
                  : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeResp_ready)) 
                & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeResp_valid)
                    : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeResp_valid)))
                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_17 
        = ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))
            ? ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                  ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeResp_ready)
                  : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeResp_ready)) 
                & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeResp_valid)
                    : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeResp_valid)))
                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_17 
        = ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))
            ? ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                  ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeResp_ready)
                  : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeResp_ready)) 
                & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeResp_valid)
                    : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeResp_valid)))
                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_10 
        = (((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeResp_ready)
             : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                 ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeResp_ready)
                 : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeResp_ready))) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeResp_valid)
               : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeResp_valid)
                   : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeResp_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_1_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_1_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_1_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0));
    vlTOPp->io_Hcf = (0xbU == (0x7fU & vlTOPp->top_SoC__DOT__im_io_inst));
    vlTOPp->io_inst = vlTOPp->top_SoC__DOT__im_io_inst;
    vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall 
        = ((0xbU == (0x7fU & vlTOPp->top_SoC__DOT__im_io_inst)) 
           | (IData)(vlTOPp->top_SoC__DOT__cpu_io_Stall_MA));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_22 
        = ((0x100000U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                         >> 0xbU)) | ((0xff000U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg) 
                                      | ((0x800U & 
                                          (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 9U)) 
                                         | (0x7feU 
                                            & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                               >> 0x14U)))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_13 
        = ((0xfe0U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                      >> 0x14U)) | (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                             >> 7U)));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_13 
        = ((0xdU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                              >> 0xfU))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_13
            : ((0xcU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                  >> 0xfU))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_12
                : ((0xbU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                      >> 0xfU))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_11
                    : ((0xaU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                          >> 0xfU)))
                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_10
                        : ((9U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0xfU)))
                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_9
                            : ((8U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                >> 0xfU)))
                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_8
                                : ((7U == (0x1fU & 
                                           (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0xfU)))
                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_7
                                    : ((6U == (0x1fU 
                                               & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                  >> 0xfU)))
                                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_6
                                        : ((5U == (0x1fU 
                                                   & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                      >> 0xfU)))
                                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_5
                                            : ((4U 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                    >> 0xfU)))
                                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_4
                                                : (
                                                   (3U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                        >> 0xfU)))
                                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_3
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                         >> 0xfU)))
                                                     ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_2
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                          >> 0xfU)))
                                                      ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_1
                                                      : 0U)))))))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_45 
        = ((0xdU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                              >> 0x14U))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_13
            : ((0xcU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                  >> 0x14U))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_12
                : ((0xbU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                      >> 0x14U))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_11
                    : ((0xaU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                          >> 0x14U)))
                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_10
                        : ((9U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0x14U)))
                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_9
                            : ((8U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                >> 0x14U)))
                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_8
                                : ((7U == (0x1fU & 
                                           (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0x14U)))
                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_7
                                    : ((6U == (0x1fU 
                                               & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                  >> 0x14U)))
                                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_6
                                        : ((5U == (0x1fU 
                                                   & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                      >> 0x14U)))
                                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_5
                                            : ((4U 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                    >> 0x14U)))
                                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_4
                                                : (
                                                   (3U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                        >> 0x14U)))
                                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_3
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                         >> 0x14U)))
                                                     ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_2
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                          >> 0x14U)))
                                                      ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_1
                                                      : 0U)))))))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel 
        = ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
            ? 5U : ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                     ? 5U : ((0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                              ? 0U : ((0x13U == (0x7fU 
                                                 & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                                       ? 1U : ((0x6fU 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                                                ? 4U
                                                : (
                                                   (0x67U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                                                    ? 1U
                                                    : 
                                                   ((0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                                                     ? 3U
                                                     : 
                                                    ((0x23U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                                                      ? 2U
                                                      : 
                                                     (3U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1 
        = ((0x23U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
           | ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
              | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
                 | ((0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
                    | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
                       | (0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2 
        = ((0x23U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
           | ((0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
              | (0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))));
    vlTOPp->io_E_Branch_taken = ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                                 | ((0x67U == (0x7fU 
                                               & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                                    | ((0x63U == (0x7fU 
                                                  & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                                       & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___E_Branch_taken_T_14))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__E_Branch_taken 
        = ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
           | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
              | ((0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                 & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___E_Branch_taken_T_14))));
    vlTOPp->io_ALU_src1 = ((2U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ASel))
                            ? 0U : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT___alu_src1_T_3);
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
        = ((2U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ASel))
            ? 0U : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT___alu_src1_T_3);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_36 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_10) 
           | ((~ ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)) 
                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)) 
                  & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_b_ready))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_35 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_10) 
           | ((~ ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)) 
                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)) 
                  & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_b_ready))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_36 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_10) 
           | ((~ ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)) 
                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid)) 
                  & (4U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_35 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_10) 
           | ((~ ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)) 
                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid)) 
                  & (4U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_1_valid) 
           & (1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_1_valid) 
           & (1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_1_valid) 
           & (1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant)));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_26 
        = ((0x1aU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                               >> 0xfU))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_26
            : ((0x19U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                   >> 0xfU))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_25
                : ((0x18U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                       >> 0xfU))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_24
                    : ((0x17U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 0xfU)))
                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_23
                        : ((0x16U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                               >> 0xfU)))
                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_22
                            : ((0x15U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                   >> 0xfU)))
                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_21
                                : ((0x14U == (0x1fU 
                                              & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                 >> 0xfU)))
                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_20
                                    : ((0x13U == (0x1fU 
                                                  & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                     >> 0xfU)))
                                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_19
                                        : ((0x12U == 
                                            (0x1fU 
                                             & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                >> 0xfU)))
                                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_18
                                            : ((0x11U 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                    >> 0xfU)))
                                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_17
                                                : (
                                                   (0x10U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                        >> 0xfU)))
                                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_16
                                                    : 
                                                   ((0xfU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                         >> 0xfU)))
                                                     ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_15
                                                     : 
                                                    ((0xeU 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                          >> 0xfU)))
                                                      ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_14
                                                      : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_13)))))))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_58 
        = ((0x1aU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                               >> 0x14U))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_26
            : ((0x19U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                   >> 0x14U))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_25
                : ((0x18U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                       >> 0x14U))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_24
                    : ((0x17U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 0x14U)))
                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_23
                        : ((0x16U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                               >> 0x14U)))
                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_22
                            : ((0x15U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                   >> 0x14U)))
                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_21
                                : ((0x14U == (0x1fU 
                                              & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                 >> 0x14U)))
                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_20
                                    : ((0x13U == (0x1fU 
                                                  & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                     >> 0x14U)))
                                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_19
                                        : ((0x12U == 
                                            (0x1fU 
                                             & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                >> 0x14U)))
                                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_18
                                            : ((0x11U 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                    >> 0x14U)))
                                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_17
                                                : (
                                                   (0x10U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                        >> 0x14U)))
                                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_16
                                                    : 
                                                   ((0xfU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                         >> 0x14U)))
                                                     ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_15
                                                     : 
                                                    ((0xeU 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                          >> 0x14U)))
                                                      ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_14
                                                      : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_45)))))))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_26 
        = ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel))
            ? (0xfffU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                         >> 0x14U)) : 0U);
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH 
        = (((((((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1) 
                  & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd)) 
                 & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                              >> 0xfU)) == (0x1fU & 
                                            (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                             >> 7U)))) 
                & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                   >> 7U)))) | ((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2) 
                                                  & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd)) 
                                                 & ((0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                        >> 0x14U)) 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                                        >> 7U)))) 
                                                & (0U 
                                                   != 
                                                   (0x1fU 
                                                    & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                                       >> 7U))))) 
              | ((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1) 
                   & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd)) 
                  & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                               >> 0xfU)) == (0x1fU 
                                             & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                >> 7U)))) 
                 & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                    >> 7U))))) | ((
                                                   ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2) 
                                                    & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd)) 
                                                   & ((0x1fU 
                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                          >> 0x14U)) 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                          >> 7U)))) 
                                                  & (0U 
                                                     != 
                                                     (0x1fU 
                                                      & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                         >> 7U))))) 
            | ((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1) 
                 & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd)) 
                & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                             >> 0xfU)) == (0x1fU & 
                                           (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                            >> 7U)))) 
               & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                  >> 7U))))) | ((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2) 
                                                  & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd)) 
                                                 & ((0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                        >> 0x14U)) 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                                        >> 7U)))) 
                                                & (0U 
                                                   != 
                                                   (0x1fU 
                                                    & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                                       >> 7U)))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10 
        = ((0xf8U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
            ? (QData)((IData)((vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                               + vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
            : ((0xf9U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                ? (VL_ULL(0x7fffffffffffffff) & ((QData)((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1)) 
                                                 << 
                                                 (0x1fU 
                                                  & vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                : ((0xfaU == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                    ? (QData)((IData)(VL_LTS_III(1,32,32, vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1, vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                    : ((0xfbU == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                        ? (QData)((IData)((vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                                           < vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                        : ((0xfcU == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                            ? (QData)((IData)((vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                                               ^ vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                            : ((0xfdU == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                                ? (QData)((IData)((vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                                                   >> 
                                                   (0x1fU 
                                                    & vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2))))
                                : ((0xfeU == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                                    ? (QData)((IData)(
                                                      (vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                                                       | vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                                    : ((0xffU == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                                        ? (QData)((IData)(
                                                          (vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                                                           & vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                                        : ((0x20f8U 
                                            == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                                            ? (QData)((IData)(
                                                              (vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                                                               - vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                                            : ((0x20fdU 
                                                == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                                                ? (QData)((IData)(
                                                                  VL_SHIFTRS_III(32,32,5, vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1, 
                                                                                (0x1fU 
                                                                                & vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2))))
                                                : (
                                                   (0x1f8U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                                                    ? 
                                                   ((QData)((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1)) 
                                                    * (QData)((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                                                    : VL_ULL(0))))))))))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen 
        = (1U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1) 
                 | (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen 
        = (1U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1) 
                 | (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen 
        = (1U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1) 
                 | (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_30 
        = ((2U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel))
            ? ((0x1000U & ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_13) 
                           << 1U)) | (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_13))
            : ((3U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel))
                ? ((0x1000U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                               >> 0x13U)) | ((0x800U 
                                              & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                 << 4U)) 
                                             | ((0x7e0U 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                      >> 7U)))))
                : ((0x1000U & ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_26) 
                               << 1U)) | (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_26))));
    vlTOPp->io_Stall_DH = vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH;
    vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID_io_Stall 
        = ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH) 
           | (IData)(vlTOPp->top_SoC__DOT__cpu_io_Stall_MA));
    vlTOPp->io_EXE_alu_out = (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10);
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH 
        = ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__E_Branch_taken) 
           & ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg) 
              != (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_1_valid)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_1_valid)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_1_valid)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid));
    vlTOPp->io_Flush = vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH;
    vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Flush 
        = (((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH) 
            | (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)) 
           & (~ (IData)(vlTOPp->top_SoC__DOT__cpu_io_Stall_MA)));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_IF__DOT___io_next_pc_T_9 
        = ((1U == ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)
                    ? 2U : 0U)) ? ((IData)(4U) + vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg)
            : ((IData)(4U) + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_66 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeData_ready 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))
            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) 
               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)))
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeData_ready 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))
            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen))
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_66 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeData_ready 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))
            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) 
               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)))
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeData_ready 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))
            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen))
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_66 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeData_ready 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))
            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) 
               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)))
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeData_ready 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))
            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen))
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_5 
        = (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeData_ready)
             : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeData_ready)) 
           & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_valid)
               : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_1 
        = (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeData_ready)
             : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeData_ready)) 
           & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_valid)
               : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_5 
        = (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeData_ready)
             : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeData_ready)) 
           & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_valid)
               : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_1 
        = (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeData_ready)
             : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeData_ready)) 
           & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_valid)
               : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_5 
        = (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeData_ready)
             : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeData_ready)) 
           & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_valid)
               : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_1 
        = (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeData_ready)
             : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeData_ready)) 
           & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_valid)
               : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_52 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_52 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_52 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined));
}

void Vtop_SoC::_settle__TOP__3(Vtop_SoC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_SoC::_settle__TOP__3\n"); );
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_regs_1 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_1;
    vlTOPp->io_regs_2 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_2;
    vlTOPp->io_regs_3 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_3;
    vlTOPp->io_regs_4 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_4;
    vlTOPp->io_regs_5 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_5;
    vlTOPp->io_regs_6 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_6;
    vlTOPp->io_regs_7 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_7;
    vlTOPp->io_regs_8 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_8;
    vlTOPp->io_regs_9 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_9;
    vlTOPp->io_regs_10 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_10;
    vlTOPp->io_regs_11 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_11;
    vlTOPp->io_regs_12 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_12;
    vlTOPp->io_regs_13 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_13;
    vlTOPp->io_regs_14 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_14;
    vlTOPp->io_regs_15 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_15;
    vlTOPp->io_regs_16 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_16;
    vlTOPp->io_regs_17 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_17;
    vlTOPp->io_regs_18 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_18;
    vlTOPp->io_regs_19 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_19;
    vlTOPp->io_regs_20 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_20;
    vlTOPp->io_regs_21 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_21;
    vlTOPp->io_regs_22 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_22;
    vlTOPp->io_regs_23 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_23;
    vlTOPp->io_regs_24 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_24;
    vlTOPp->io_regs_25 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_25;
    vlTOPp->io_regs_26 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_26;
    vlTOPp->io_IF_PC = vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg;
    vlTOPp->io_WB_PC = ((0U < vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg)
                         ? (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg 
                            - (IData)(4U)) : vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg);
    vlTOPp->io_EXE_src1 = vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg;
    vlTOPp->top_SoC__DOT__dma__DOT___io_slave_ar_ready_T 
        = (1U & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sReadState)));
    vlTOPp->top_SoC__DOT__dma__DOT___request_counter_T_1 
        = ((IData)(1U) + vlTOPp->top_SoC__DOT__dma__DOT__request_counter);
    vlTOPp->top_SoC__DOT__localMem__DOT___rLatencyCounter_T_1 
        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__rLatencyCounter)));
    vlTOPp->top_SoC__DOT__globalMem__DOT___rLatencyCounter_T_1 
        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__rLatencyCounter)));
    vlTOPp->top_SoC__DOT__cpu__DOT___GEN_2 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)
                                               ? 0U
                                               : (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_1 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)) 
           & (1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState)));
    vlTOPp->top_SoC__DOT__cpu_io_master_b_ready = (
                                                   (2U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState)) 
                                                   | (1U 
                                                      == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState)));
    vlTOPp->top_SoC__DOT__cpu_io_master_r_ready = (
                                                   (2U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState)) 
                                                   | (1U 
                                                      == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState)));
    vlTOPp->io_MEM_PC = vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__pcReg;
    vlTOPp->io_EXE_src2 = vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg;
    vlTOPp->io_raddr = vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg;
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_10 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined) 
                                               | (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sReadState));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___T_9 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sReadState)) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___T_9 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__ar_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___T_9 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__ar_determined));
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_76 = 
        (0xffU & ((2U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                   ? ((IData)(1U) + (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__wLatencyCounter))
                   : ((3U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                       ? 0U : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__wLatencyCounter))));
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_76 = 
        (0xffU & ((2U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                   ? ((IData)(1U) + (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__wLatencyCounter))
                   : ((3U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                       ? 0U : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__wLatencyCounter))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_out_readData_ready 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
           & (1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)));
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_15 = 
        ((1U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)) 
         & (2U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)));
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_15 = 
        ((1U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)) 
         & (2U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_1_readData_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
              & ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_1_readData_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
              & ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_1_readData_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
              & ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
                 & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_0_readData_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
              & ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
                 & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_0_readData_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
              & ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
                 & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_0_readData_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
              & ((2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
                 & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrEq 
        = (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg 
           == vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg);
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
           | ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state)) 
              & (2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
           | ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
              & (2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
           | ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
              & (2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))));
    vlTOPp->top_SoC__DOT__cpu_io_master_ar_bits_addr 
        = ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState))
            ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg
            : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___T 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)) 
           & (1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState)));
    vlTOPp->io_regs_27 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_27;
    vlTOPp->io_regs_28 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_28;
    vlTOPp->io_regs_29 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_29;
    vlTOPp->io_regs_30 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_30;
    vlTOPp->io_regs_31 = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31;
    vlTOPp->io_EXE_PC = vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg;
    vlTOPp->io_DMA_Hcf = (1U & vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_5);
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_84 
        = ((~ (((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                & (1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined))) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_88 
        = ((~ (((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                & ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                   | (4U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)))) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined))) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_84 
        = ((~ (((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                & (1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined))) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_88 
        = ((~ (((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                & ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                   | (4U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)))) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined))) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined));
    vlTOPp->top_SoC__DOT__localMem__DOT___T_10 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined) 
                                                  & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined));
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_31 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined)
          ? 4U : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState));
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_34 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined)
          ? 3U : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState));
    vlTOPp->top_SoC__DOT__globalMem__DOT___T_10 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined) 
                                                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined));
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_31 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined)
          ? 4U : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState));
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_34 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined)
          ? 2U : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_44 = ((3U 
                                                == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                               & ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)) 
                                                  | (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteDataSent)));
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_58 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined)
          ? (0x3fffffffU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                             - (IData)(0x8000U)) >> 2U))
          : vlTOPp->top_SoC__DOT__localMem__DOT__writeAddressReg);
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_59 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined)
          ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_id)
          : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeID));
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_58 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined)
          ? (0x3fffffffU & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                             - (IData)(0x10000U)) >> 2U))
          : vlTOPp->top_SoC__DOT__globalMem__DOT__writeAddressReg);
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_59 = 
        ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined)
          ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_id)
          : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeID));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_6 = ((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                               ? (((IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteAddrSent) 
                                                   & (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteDataSent))
                                                   ? 4U
                                                   : (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                               : ((4U 
                                                   == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                                   ? 
                                                  ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid)
                                                    ? 0U
                                                    : (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                                   : (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_22 = ((1U 
                                                == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                                ? (VL_ULL(0xffffffffff) 
                                                   & ((QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_1)) 
                                                      + 
                                                      ((QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__request_counter)) 
                                                       * (QData)((IData)(
                                                                         (0xffU 
                                                                          & (vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                                                                             >> 0x18U)))))))
                                                : VL_ULL(0));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_40 = (((4U 
                                                 == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                                & (vlTOPp->top_SoC__DOT__dma__DOT__request_counter 
                                                   == 
                                                   (0xffU 
                                                    & vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3)))
                                                ? 0U
                                                : vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_0);
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_41 = (((4U 
                                                 == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                                & (vlTOPp->top_SoC__DOT__dma__DOT__request_counter 
                                                   == 
                                                   (0xffU 
                                                    & vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3)))
                                                ? 1U
                                                : vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_5);
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)
            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                    ? vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data
                    : 0U) : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                                  ? vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data
                                  : 0U) : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                                            ? vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data
                                            : 0U)))
            : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___T 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding)) 
           & (1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_1 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)) 
           & ((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteDataSent))));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding)
            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                    ? 0U : vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data)
                : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                    ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                        ? 0U : vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data)
                    : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                        ? 0U : vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data)))
            : 0U);
    vlTOPp->top_SoC__DOT__dma__DOT___mask_width_T_8 
        = ((4U == (0xffU & (vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                            >> 8U))) ? 0xfU : ((3U 
                                                == 
                                                (0xffU 
                                                 & (vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                                                    >> 8U)))
                                                ? 7U
                                                : (
                                                   (2U 
                                                    == 
                                                    (0xffU 
                                                     & (vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                                                        >> 8U)))
                                                    ? 3U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0xffU 
                                                      & (vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                                                         >> 8U)))
                                                     ? 1U
                                                     : 0xfU))));
    vlTOPp->top_SoC__DOT__dma_io_master_aw_valid = 
        ((3U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
         & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteAddrSent)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_out_writeResp_ready 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
              & (2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_out_writeResp_ready 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
              & (2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeResp_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
                 & ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
                    & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg))))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeResp_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
                 & ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeResp_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
                 & ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
                    & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg))))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeResp_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
                 & ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)))));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_0_readAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_1_readAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_2_readAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_0_readAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_1_readAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_2_readAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
           | ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
                 & (3U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
           | ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
                 & (3U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)))));
    vlTOPp->io_ID_PC = vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg;
    vlTOPp->io_WB_rd = (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                 >> 7U));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn 
        = ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
           | ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
              | ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                 | ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                    | ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                       | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                          | (0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg))))))));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_64 = ((8U 
                                                == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                ? vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg
                                                : vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_2);
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_65 = ((8U 
                                                == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3
                                                : (
                                                   (0xcU 
                                                    == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                    ? vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg
                                                    : vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_66 = ((8U 
                                                == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_4
                                                : (
                                                   (0xcU 
                                                    == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                    ? vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_4
                                                    : 
                                                   ((0x10U 
                                                     == vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrReg)
                                                     ? vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataReg
                                                     : vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_4)));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_WBSel 
        = ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg))
            ? 2U : ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                    | ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                       | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                          | ((0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                             | ((0x67U != (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                                & (0x6fU != (0x7fU 
                                             & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd 
        = ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
           | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
              | ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                 | ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                    | ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                       | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg)) 
                          | (0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg))))))));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_46 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined) 
                                               | (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_49 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined) 
                                               | (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_45 = ((3U 
                                                == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                               & ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)) 
                                                  | (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mWriteAddrSent)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_84 
        = ((~ ((((0U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)) 
                 | (1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState))) 
                & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteAddrRecv))) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined))) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined));
    vlTOPp->top_SoC__DOT__cpu__DOT___GEN_8 = ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState))
                                               ? (VL_ULL(0x7fffffffffffffff) 
                                                  & ((QData)((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__wdataReg)) 
                                                     << 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                           >> 0xcU)))
                                                       ? 0U
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                            >> 0xcU)))
                                                        ? 
                                                       ((1U 
                                                         == 
                                                         (2U 
                                                          & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                         ? 0x10U
                                                         : 0U)
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
                                                          ? 0x18U
                                                          : 
                                                         ((2U 
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
                                                         : 0U)))))
                                               : VL_ULL(0));
    vlTOPp->top_SoC__DOT__dma__DOT___io_slave_aw_ready_T_2 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)) 
           | (1U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
              & (2U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeResp_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
                 & ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
                    & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg))))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeResp_valid 
        = ((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
           & ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
                 & ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd 
        = ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
           | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
              | ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                 | ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                    | ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                       | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                          | (0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg))))))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
           | ((1U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
              & ((2U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
                 & (3U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)))));
    vlTOPp->top_SoC__DOT__cpu_io_master_aw_bits_addr 
        = ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState))
            ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg
            : 0U);
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_35 = ((3U 
                                                == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                                ? (VL_ULL(0xffffffffff) 
                                                   & ((QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_2)) 
                                                      + 
                                                      ((QData)((IData)(vlTOPp->top_SoC__DOT__dma__DOT__request_counter)) 
                                                       * (QData)((IData)(
                                                                         (0xffU 
                                                                          & (vlTOPp->top_SoC__DOT__dma__DOT__mmio_regs_3 
                                                                             >> 0x10U)))))))
                                                : VL_ULL(0));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)) 
           & (1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__wState)));
    vlTOPp->io_EXE_Jump = ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                           | (0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)));
    vlTOPp->io_EXE_Branch = (0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
            ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_strb 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
            ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_strb)
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_last 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_last)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
            ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_strb 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
            ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_strb)
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_last 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_last)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_strb 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding)
            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_strb)
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_last 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_last)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
            ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_strb 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
            ? ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_strb)
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_last 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_last)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
            ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_strb 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
            ? ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_strb)
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_last 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_last)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_data 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_strb 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)
            ? ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_strb)
                : 0U) : 0U);
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_last 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_last)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeResp_ready 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeResp_ready 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeResp_ready 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeResp_ready 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeResp_ready 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeResp_ready 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd 
        = ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
           | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
              | ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                 | ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                    | ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                       | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                          | (0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT 
        = ((0x2000U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)
            ? (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg 
               < vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg)
            : VL_LTS_III(1,32,32, vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg, vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___io_E_ALUSel_T_1 
        = (0xf8U | ((0x7f00U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                >> 0x11U)) | (7U & 
                                              (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                               >> 0xcU))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_BSel 
        = ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
           | ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
              | ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                 | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                    | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                       | ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                          | ((0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                             | ((0x23U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                                | (3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ASel 
        = ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))
            ? 1U : ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))
                     ? 2U : ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                             | (0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeAddr_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid)));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_22 
        = ((0x100000U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                         >> 0xbU)) | ((0xff000U & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg) 
                                      | ((0x800U & 
                                          (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 9U)) 
                                         | (0x7feU 
                                            & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                               >> 0x14U)))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_13 
        = ((0xfe0U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                      >> 0x14U)) | (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                             >> 7U)));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_13 
        = ((0xdU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                              >> 0xfU))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_13
            : ((0xcU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                  >> 0xfU))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_12
                : ((0xbU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                      >> 0xfU))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_11
                    : ((0xaU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                          >> 0xfU)))
                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_10
                        : ((9U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0xfU)))
                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_9
                            : ((8U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                >> 0xfU)))
                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_8
                                : ((7U == (0x1fU & 
                                           (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0xfU)))
                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_7
                                    : ((6U == (0x1fU 
                                               & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                  >> 0xfU)))
                                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_6
                                        : ((5U == (0x1fU 
                                                   & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                      >> 0xfU)))
                                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_5
                                            : ((4U 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                    >> 0xfU)))
                                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_4
                                                : (
                                                   (3U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                        >> 0xfU)))
                                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_3
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                         >> 0xfU)))
                                                     ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_2
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                          >> 0xfU)))
                                                      ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_1
                                                      : 0U)))))))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_45 
        = ((0xdU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                              >> 0x14U))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_13
            : ((0xcU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                  >> 0x14U))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_12
                : ((0xbU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                      >> 0x14U))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_11
                    : ((0xaU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                          >> 0x14U)))
                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_10
                        : ((9U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0x14U)))
                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_9
                            : ((8U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                >> 0x14U)))
                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_8
                                : ((7U == (0x1fU & 
                                           (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                            >> 0x14U)))
                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_7
                                    : ((6U == (0x1fU 
                                               & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                  >> 0x14U)))
                                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_6
                                        : ((5U == (0x1fU 
                                                   & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                      >> 0x14U)))
                                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_5
                                            : ((4U 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                    >> 0x14U)))
                                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_4
                                                : (
                                                   (3U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                        >> 0x14U)))
                                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_3
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                         >> 0x14U)))
                                                     ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_2
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                          >> 0x14U)))
                                                      ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_1
                                                      : 0U)))))))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel 
        = ((0x37U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
            ? 5U : ((0x17U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                     ? 5U : ((0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                              ? 0U : ((0x13U == (0x7fU 
                                                 & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                                       ? 1U : ((0x6fU 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                                                ? 4U
                                                : (
                                                   (0x67U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                                                    ? 1U
                                                    : 
                                                   ((0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                                                     ? 3U
                                                     : 
                                                    ((0x23U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))
                                                      ? 2U
                                                      : 
                                                     (3U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1 
        = ((0x23U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
           | ((3U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
              | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
                 | ((0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
                    | ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
                       | (0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2 
        = ((0x23U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
           | ((0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg)) 
              | (0x33U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg))));
    vlTOPp->top_SoC__DOT__im_io_inst = (((vlTOPp->top_SoC__DOT__im__DOT__memory
                                          [(0x7fffU 
                                            & ((IData)(3U) 
                                               + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))] 
                                          << 0x18U) 
                                         | (vlTOPp->top_SoC__DOT__im__DOT__memory
                                            [(0x7fffU 
                                              & ((IData)(2U) 
                                                 + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))] 
                                            << 0x10U)) 
                                        | ((vlTOPp->top_SoC__DOT__im__DOT__memory
                                            [(0x7fffU 
                                              & ((IData)(1U) 
                                                 + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg))] 
                                            << 8U) 
                                           | vlTOPp->top_SoC__DOT__im__DOT__memory
                                           [(0x7fffU 
                                             & vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg)]));
    vlTOPp->top_SoC__DOT__localMem__DOT__lo = ((0xff00U 
                                                & (((2U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                                     ? 
                                                    (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                                                     >> 8U)
                                                     : 
                                                    (vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                                     [
                                                     (0x3fU 
                                                      & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                          - (IData)(0x8000U)) 
                                                         >> 2U))] 
                                                     >> 8U)) 
                                                   << 8U)) 
                                               | (0xffU 
                                                  & ((1U 
                                                      & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                                      ? vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data
                                                      : 
                                                     vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                                     [
                                                     (0x3fU 
                                                      & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                          - (IData)(0x8000U)) 
                                                         >> 2U))])));
    vlTOPp->top_SoC__DOT__localMem__DOT__hi = ((0xff00U 
                                                & (((8U 
                                                     & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                                     ? 
                                                    (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                                                     >> 0x18U)
                                                     : 
                                                    (vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                                     [
                                                     (0x3fU 
                                                      & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                          - (IData)(0x8000U)) 
                                                         >> 2U))] 
                                                     >> 0x18U)) 
                                                   << 8U)) 
                                               | (0xffU 
                                                  & ((4U 
                                                      & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb))
                                                      ? 
                                                     (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data 
                                                      >> 0x10U)
                                                      : 
                                                     (vlTOPp->top_SoC__DOT__localMem__DOT__memory
                                                      [
                                                      (0x3fU 
                                                       & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr 
                                                           - (IData)(0x8000U)) 
                                                          >> 2U))] 
                                                      >> 0x10U))));
    vlTOPp->top_SoC__DOT__globalMem__DOT__lo = ((0xff00U 
                                                 & (((2U 
                                                      & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                                      ? 
                                                     (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                                                      >> 8U)
                                                      : 
                                                     (vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                                      [
                                                      (0x3fU 
                                                       & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                           - (IData)(0x10000U)) 
                                                          >> 2U))] 
                                                      >> 8U)) 
                                                    << 8U)) 
                                                | (0xffU 
                                                   & ((1U 
                                                       & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                                       ? vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data
                                                       : 
                                                      vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                                      [
                                                      (0x3fU 
                                                       & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                           - (IData)(0x10000U)) 
                                                          >> 2U))])));
    vlTOPp->top_SoC__DOT__globalMem__DOT__hi = ((0xff00U 
                                                 & (((8U 
                                                      & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                                      ? 
                                                     (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                                                      >> 0x18U)
                                                      : 
                                                     (vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                                      [
                                                      (0x3fU 
                                                       & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                           - (IData)(0x10000U)) 
                                                          >> 2U))] 
                                                      >> 0x18U)) 
                                                    << 8U)) 
                                                | (0xffU 
                                                   & ((4U 
                                                       & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb))
                                                       ? 
                                                      (vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data 
                                                       >> 0x10U)
                                                       : 
                                                      (vlTOPp->top_SoC__DOT__globalMem__DOT__memory
                                                       [
                                                       (0x3fU 
                                                        & ((vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr 
                                                            - (IData)(0x10000U)) 
                                                           >> 2U))] 
                                                       >> 0x10U))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_6 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_9 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___T_2 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_out_readData_ready) 
           & (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sReadState));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___T_2 
        = (((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state)) 
            & (1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state))) 
           & ((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__readState)) 
              & (IData)(vlTOPp->top_SoC__DOT__localMem__DOT___GEN_15)));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___T_2 
        = (((0U != (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state)) 
            & (1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state))) 
           & ((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__readState)) 
              & (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_15)));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_1_readData_valid)
               : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg)))
                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_1_readData_valid)
                   : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_1_readData_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___GEN_6 
        = ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                 & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
                    & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))))
              : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                 & ((0U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
                    & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready)))) 
            & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg)
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_1_readData_valid)
                : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_0_readData_valid)))
            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___GEN_6 
        = ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                 & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
                    & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))))
              : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                 & ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
                    & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready)))) 
            & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg)
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_1_readData_valid)
                : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_0_readData_valid)))
            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___GEN_6 
        = ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding) 
                 & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg))) 
                    & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))))
              : ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
                 & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg))) 
                    & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_r_ready)))) 
            & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg)
                ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_1_readData_valid)
                : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_0_readData_valid)))
            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2_io_in_0_readData_valid)
               : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg)))
                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1_io_in_0_readData_valid)
                   : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0_io_in_0_readData_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___GEN_0 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___GEN_5 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___GEN_0 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding));
    vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___GEN_5 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_6 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_9 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid));
    vlTOPp->io_rdata = vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_bits_data;
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_MEM_io_Mem_Data 
        = ((vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_bits_data 
            & ((2U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                             >> 0xcU))) ? 0xffffffffU
                : ((1U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                 >> 0xcU))) ? ((1U 
                                                == 
                                                (2U 
                                                 & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                ? 0xffff0000U
                                                : 0xffffU)
                    : ((0U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                     >> 0xcU))) ? (
                                                   (3U 
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
                        : 0xffffffffU)))) >> ((2U == 
                                               (7U 
                                                & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                   >> 0xcU)))
                                               ? 0U
                                               : ((1U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                       >> 0xcU)))
                                                   ? 
                                                  ((1U 
                                                    == 
                                                    (2U 
                                                     & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg))
                                                    ? 0x10U
                                                    : 0U)
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
                                                     ? 0x18U
                                                     : 
                                                    ((2U 
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
                                                    : 0U))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T 
        = ((~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding)) 
           & (IData)(vlTOPp->top_SoC__DOT__dma_io_master_aw_valid));
    vlTOPp->top_SoC__DOT__localMem__DOT___GEN_38 = 
        ((2U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
          ? ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__wLatencyCounter))
              ? 3U : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
          : ((3U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_out_writeResp_ready)
                  ? 1U : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
              : (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_7 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_out_writeResp_ready) 
           & ((0U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
              & ((1U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                 & ((4U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                    & ((2U != (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)) 
                       & (3U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState)))))));
    vlTOPp->top_SoC__DOT__globalMem__DOT___GEN_38 = 
        ((2U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
          ? ((0x4fU == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__wLatencyCounter))
              ? 3U : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
          : ((3U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
              ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_out_writeResp_ready)
                  ? 1U : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
              : (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_7 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_out_writeResp_ready) 
           & ((0U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
              & ((1U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                 & ((4U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                    & ((2U != (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)) 
                       & (3U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState)))))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_0_readAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_1_readAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_slave_2_readAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_1_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_0_readAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_1_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_1_readAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_1_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_slave_2_readAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata 
        = ((2U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_WBSel))
            ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__ld_data_Reg
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_WBSel))
                ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__alu_out_Reg
                : ((0U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_W_WBSel))
                    ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg
                    : 0U)));
    vlTOPp->io_wdata = (IData)(vlTOPp->top_SoC__DOT__cpu__DOT___GEN_8);
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_88 
        = ((~ (((IData)(vlTOPp->top_SoC__DOT__dma__DOT___io_slave_aw_ready_T_2) 
                & (~ (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteDataRecv))) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined))) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined));
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_16 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready)
                                                ? 0U
                                                : (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_7 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready) 
           & (2U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteState)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_0 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_3 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_76 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
            ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_data
            : vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_data);
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_78 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_strb)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_strb));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_80 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_last)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_last));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_76 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
            ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_data
            : vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_data);
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_78 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_strb)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_strb));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_80 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_last)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_last));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_76 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
            ? vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_data
            : vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_data);
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_78 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_strb)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_strb));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_80 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_last)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_last));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_10 
        = (((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeResp_ready)
             : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                 ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeResp_ready)
                 : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeResp_ready))) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeResp_valid)
               : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg)))
                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeResp_valid)
                   : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeResp_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_17 
        = ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))
            ? ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                  ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeResp_ready)
                  : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeResp_ready)) 
                & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeResp_valid)
                    : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeResp_valid)))
                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_17 
        = ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))
            ? ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                  ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeResp_ready)
                  : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeResp_ready)) 
                & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeResp_valid)
                    : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeResp_valid)))
                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_17 
        = ((3U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))
            ? ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                  ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeResp_ready)
                  : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeResp_ready)) 
                & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
                    ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeResp_valid)
                    : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeResp_valid)))
                ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_10 
        = (((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeResp_ready)
             : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                 ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeResp_ready)
                 : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeResp_ready))) 
           & ((2U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeResp_valid)
               : ((1U == (3U & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg)))
                   ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeResp_valid)
                   : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeResp_valid))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___E_Branch_taken_T_14 
        = (1U & ((7U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                               >> 0xcU))) ? (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT))
                  : ((6U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                   >> 0xcU))) ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT)
                      : ((5U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                       >> 0xcU))) ? 
                         (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT))
                          : ((4U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                           >> 0xcU)))
                              ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT)
                              : ((1U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                               >> 0xcU)))
                                  ? (~ (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrEq))
                                  : ((0U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                                   >> 0xcU))) 
                                     & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrEq))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel 
        = ((0x13U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))
            ? ((5U == (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                             >> 0xcU))) ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___io_E_ALUSel_T_1)
                : (0xf8U | (7U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                  >> 0xcU)))) : ((0x33U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg))
                                                  ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___io_E_ALUSel_T_1)
                                                  : 0xf8U));
    vlTOPp->io_ALU_src2 = ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_BSel)
                            ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__immReg
                            : vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg);
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2 
        = ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_BSel)
            ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__immReg
            : vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg);
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT___alu_src1_T_3 
        = ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ASel))
            ? vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg
            : vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg);
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_1_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_1_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_1_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeAddr_valid) 
           & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_26 
        = ((0x1aU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                               >> 0xfU))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_26
            : ((0x19U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                   >> 0xfU))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_25
                : ((0x18U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                       >> 0xfU))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_24
                    : ((0x17U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 0xfU)))
                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_23
                        : ((0x16U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                               >> 0xfU)))
                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_22
                            : ((0x15U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                   >> 0xfU)))
                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_21
                                : ((0x14U == (0x1fU 
                                              & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                 >> 0xfU)))
                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_20
                                    : ((0x13U == (0x1fU 
                                                  & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                     >> 0xfU)))
                                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_19
                                        : ((0x12U == 
                                            (0x1fU 
                                             & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                >> 0xfU)))
                                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_18
                                            : ((0x11U 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                    >> 0xfU)))
                                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_17
                                                : (
                                                   (0x10U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                        >> 0xfU)))
                                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_16
                                                    : 
                                                   ((0xfU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                         >> 0xfU)))
                                                     ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_15
                                                     : 
                                                    ((0xeU 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                          >> 0xfU)))
                                                      ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_14
                                                      : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_13)))))))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_58 
        = ((0x1aU == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                               >> 0x14U))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_26
            : ((0x19U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                   >> 0x14U))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_25
                : ((0x18U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                       >> 0x14U))) ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_24
                    : ((0x17U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                           >> 0x14U)))
                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_23
                        : ((0x16U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                               >> 0x14U)))
                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_22
                            : ((0x15U == (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                   >> 0x14U)))
                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_21
                                : ((0x14U == (0x1fU 
                                              & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                 >> 0x14U)))
                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_20
                                    : ((0x13U == (0x1fU 
                                                  & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                     >> 0x14U)))
                                        ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_19
                                        : ((0x12U == 
                                            (0x1fU 
                                             & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                >> 0x14U)))
                                            ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_18
                                            : ((0x11U 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                    >> 0x14U)))
                                                ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_17
                                                : (
                                                   (0x10U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                        >> 0x14U)))
                                                    ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_16
                                                    : 
                                                   ((0xfU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                         >> 0x14U)))
                                                     ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_15
                                                     : 
                                                    ((0xeU 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                          >> 0x14U)))
                                                      ? vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_14
                                                      : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_45)))))))))))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_26 
        = ((1U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel))
            ? (0xfffU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                         >> 0x14U)) : 0U);
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH 
        = (((((((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1) 
                  & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd)) 
                 & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                              >> 0xfU)) == (0x1fU & 
                                            (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                             >> 7U)))) 
                & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                   >> 7U)))) | ((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2) 
                                                  & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd)) 
                                                 & ((0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                        >> 0x14U)) 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                                        >> 7U)))) 
                                                & (0U 
                                                   != 
                                                   (0x1fU 
                                                    & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg 
                                                       >> 7U))))) 
              | ((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1) 
                   & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd)) 
                  & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                               >> 0xfU)) == (0x1fU 
                                             & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                >> 7U)))) 
                 & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                    >> 7U))))) | ((
                                                   ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2) 
                                                    & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd)) 
                                                   & ((0x1fU 
                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                          >> 0x14U)) 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                          >> 7U)))) 
                                                  & (0U 
                                                     != 
                                                     (0x1fU 
                                                      & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg 
                                                         >> 7U))))) 
            | ((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1) 
                 & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd)) 
                & ((0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                             >> 0xfU)) == (0x1fU & 
                                           (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                            >> 7U)))) 
               & (0U != (0x1fU & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                  >> 7U))))) | ((((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2) 
                                                  & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd)) 
                                                 & ((0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                        >> 0x14U)) 
                                                    == 
                                                    (0x1fU 
                                                     & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                                        >> 7U)))) 
                                                & (0U 
                                                   != 
                                                   (0x1fU 
                                                    & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg 
                                                       >> 7U)))));
    vlTOPp->io_Hcf = (0xbU == (0x7fU & vlTOPp->top_SoC__DOT__im_io_inst));
    vlTOPp->io_inst = vlTOPp->top_SoC__DOT__im_io_inst;
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_2 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid)
                                               ? 3U
                                               : (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState));
    vlTOPp->top_SoC__DOT__dma__DOT__mask_width = ((3U 
                                                   == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState))
                                                   ? (IData)(vlTOPp->top_SoC__DOT__dma__DOT___mask_width_T_8)
                                                   : 
                                                  (((2U 
                                                     == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__dma__DOT___mask_width_T_8)
                                                    : 0U));
    vlTOPp->top_SoC__DOT__cpu__DOT___GEN_12 = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_valid)
                                                ? 0U
                                                : (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__rState));
    vlTOPp->top_SoC__DOT__cpu_io_Stall_MA = (((3U == 
                                               (0x7fU 
                                                & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                                              & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_valid))) 
                                             | ((0x23U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg)) 
                                                & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_0 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_3 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_11 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_7)
            ? 3U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_90 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_7)
            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_89 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_7)
            ? ((0U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                         ? 0U : ((4U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                  ? 0U : ((2U == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                           ? 0U : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeState))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__localMem__DOT__writeID)
                                                    : 0U)))))
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_11 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_7)
            ? 3U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_90 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_7)
            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_89 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_7)
            ? ((0U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                ? 0U : ((1U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                         ? 0U : ((4U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                  ? 0U : ((2U == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                           ? 0U : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeState))
                                                    ? (IData)(vlTOPp->top_SoC__DOT__globalMem__DOT__writeID)
                                                    : 0U)))))
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_1_valid) 
           & (1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant)));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_1_valid) 
           & (1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant)));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_1_valid) 
           & (1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant)));
    vlTOPp->io_WB_wdata = vlTOPp->top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata;
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_11 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_7)
            ? 3U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_90 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_7)
            ? 0U : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_89 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_7)
            ? (IData)(vlTOPp->top_SoC__DOT__dma__DOT__sWriteIDReg)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_36 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_10) 
           | ((~ ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)) 
                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)) 
                  & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_b_ready))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_35 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_10) 
           | ((~ ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding)) 
                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid)) 
                  & (IData)(vlTOPp->top_SoC__DOT__cpu_io_master_b_ready))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_36 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_10) 
           | ((~ ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)) 
                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid)) 
                  & (4U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_35 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_10) 
           | ((~ ((((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding) 
                    & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding)) 
                   & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid)) 
                  & (4U == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)))) 
              & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding)));
    vlTOPp->io_E_Branch_taken = ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                                 | ((0x67U == (0x7fU 
                                               & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                                    | ((0x63U == (0x7fU 
                                                  & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                                       & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___E_Branch_taken_T_14))));
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__E_Branch_taken 
        = ((0x6fU == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
           | ((0x67U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
              | ((0x63U == (0x7fU & vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg)) 
                 & (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT___E_Branch_taken_T_14))));
    vlTOPp->io_ALU_src1 = ((2U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ASel))
                            ? 0U : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT___alu_src1_T_3);
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
        = ((2U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ASel))
            ? 0U : vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT___alu_src1_T_3);
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_1_valid) 
           & (1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_1_valid) 
           & (1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_1_valid) 
           & (1U > (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant)));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_30 
        = ((2U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel))
            ? ((0x1000U & ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_13) 
                           << 1U)) | (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_13))
            : ((3U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel))
                ? ((0x1000U & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                               >> 0x13U)) | ((0x800U 
                                              & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                 << 4U)) 
                                             | ((0x7e0U 
                                                 & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg 
                                                      >> 7U)))))
                : ((0x1000U & ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_26) 
                               << 1U)) | (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_26))));
    vlTOPp->io_Stall_DH = vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH;
    vlTOPp->top_SoC__DOT__dma__DOT___GEN_29 = (((2U 
                                                 == (IData)(vlTOPp->top_SoC__DOT__dma__DOT__mState)) 
                                                & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid))
                                                ? (0x7fU 
                                                   & ((IData)(vlTOPp->top_SoC__DOT__dma__DOT__mask_width) 
                                                      << (IData)(vlTOPp->top_SoC__DOT__dma__DOT__source_offset)))
                                                : 0U);
    vlTOPp->io_Stall_MA = vlTOPp->top_SoC__DOT__cpu_io_Stall_MA;
    vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall 
        = ((0xbU == (0x7fU & vlTOPp->top_SoC__DOT__im_io_inst)) 
           | (IData)(vlTOPp->top_SoC__DOT__cpu_io_Stall_MA));
    vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID_io_Stall 
        = ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH) 
           | (IData)(vlTOPp->top_SoC__DOT__cpu_io_Stall_MA));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_chosen 
        = (1U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1) 
                 | (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_chosen 
        = (1U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1) 
                 | (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_chosen 
        = (1U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1) 
                 | (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid))));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10 
        = ((0xf8U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
            ? (QData)((IData)((vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                               + vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
            : ((0xf9U == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                ? (VL_ULL(0x7fffffffffffffff) & ((QData)((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1)) 
                                                 << 
                                                 (0x1fU 
                                                  & vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                : ((0xfaU == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                    ? (QData)((IData)(VL_LTS_III(1,32,32, vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1, vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                    : ((0xfbU == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                        ? (QData)((IData)((vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                                           < vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                        : ((0xfcU == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                            ? (QData)((IData)((vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                                               ^ vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                            : ((0xfdU == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                                ? (QData)((IData)((vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                                                   >> 
                                                   (0x1fU 
                                                    & vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2))))
                                : ((0xfeU == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                                    ? (QData)((IData)(
                                                      (vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                                                       | vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                                    : ((0xffU == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                                        ? (QData)((IData)(
                                                          (vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                                                           & vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                                        : ((0x20f8U 
                                            == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                                            ? (QData)((IData)(
                                                              (vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 
                                                               - vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                                            : ((0x20fdU 
                                                == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                                                ? (QData)((IData)(
                                                                  VL_SHIFTRS_III(32,32,5, vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1, 
                                                                                (0x1fU 
                                                                                & vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2))))
                                                : (
                                                   (0x1f8U 
                                                    == (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel))
                                                    ? 
                                                   ((QData)((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1)) 
                                                    * (QData)((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2)))
                                                    : VL_ULL(0))))))))))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen 
        = (1U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1) 
                 | (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen 
        = (1U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1) 
                 | (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen 
        = (1U & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1) 
                 | (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid))));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_out_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_chosen)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_1_valid)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_out_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_chosen)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_1_valid)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_out_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_chosen)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_1_valid)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid));
    vlTOPp->io_EXE_alu_out = (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10);
    vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH 
        = ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller__DOT__E_Branch_taken) 
           & ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg) 
              != (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_1_valid)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_1_valid)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)
            ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_1_valid)
            : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT___GEN_41 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_out_valid) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT___GEN_41 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_out_valid) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_1__DOT__ar_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT___GEN_41 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_out_valid) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__readMuxes_2__DOT__ar_determined));
    vlTOPp->io_Flush = vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH;
    vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE_io_Flush 
        = (((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH) 
            | (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)) 
           & (~ (IData)(vlTOPp->top_SoC__DOT__cpu_io_Stall_MA)));
    vlTOPp->top_SoC__DOT__cpu__DOT__datapath_IF__DOT___io_next_pc_T_9 
        = ((1U == ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)
                    ? 2U : 0U)) ? ((IData)(4U) + vlTOPp->top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg)
            : ((IData)(4U) + vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg));
    vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT___GEN_4 
        = ((IData)(vlTOPp->reset) ? 0U : ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)
                                           ? 0U : ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID_io_Stall)
                                                    ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg)
                                                    : vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_66 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeData_ready 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))
            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) 
               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)))
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeData_ready 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state))
            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen))
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state)) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_66 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeData_ready 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))
            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) 
               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)))
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeData_ready 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state))
            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen))
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state)) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_66 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeData_ready 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))
            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) 
               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)))
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
               & (~ (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg))));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeData_ready 
        = ((0U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state))
            ? ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen))
            : ((1U == (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state)) 
               & (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_5 
        = (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeData_ready)
             : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeData_ready)) 
           & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg)
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_valid)
               : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_1 
        = (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeData_ready)
             : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeData_ready)) 
           & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen)
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_valid)
               : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_5 
        = (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeData_ready)
             : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeData_ready)) 
           & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg)
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_valid)
               : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_1 
        = (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeData_ready)
             : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeData_ready)) 
           & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen)
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_valid)
               : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_5 
        = (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeData_ready)
             : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeData_ready)) 
           & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg)
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_valid)
               : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_1 
        = (((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)
             ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeData_ready)
             : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeData_ready)) 
           & ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen)
               ? (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_valid)
               : (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_valid)));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_52 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_52 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined));
    vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_52 
        = ((IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_1) 
           | (IData)(vlTOPp->top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined));
}

VL_INLINE_OPT void Vtop_SoC::_combo__TOP__4(Vtop_SoC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_SoC::_combo__TOP__4\n"); );
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT___GEN_4 
        = ((IData)(vlTOPp->reset) ? 0U : ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH)
                                           ? 0U : ((IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID_io_Stall)
                                                    ? (IData)(vlTOPp->top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg)
                                                    : vlTOPp->top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg)));
}

void Vtop_SoC::_eval(Vtop_SoC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_SoC::_eval\n"); );
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vtop_SoC::_eval_initial(Vtop_SoC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_SoC::_eval_initial\n"); );
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vtop_SoC::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_SoC::final\n"); );
    // Variables
    Vtop_SoC__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop_SoC::_eval_settle(Vtop_SoC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_SoC::_eval_settle\n"); );
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vtop_SoC::_change_request(Vtop_SoC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_SoC::_change_request\n"); );
    Vtop_SoC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop_SoC::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_SoC::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_Dump_Mem & 0xfeU))) {
        Verilated::overWidthError("io_Dump_Mem");}
}
#endif  // VL_DEBUG

void Vtop_SoC::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_SoC::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_regs_0 = VL_RAND_RESET_I(32);
    io_regs_1 = VL_RAND_RESET_I(32);
    io_regs_2 = VL_RAND_RESET_I(32);
    io_regs_3 = VL_RAND_RESET_I(32);
    io_regs_4 = VL_RAND_RESET_I(32);
    io_regs_5 = VL_RAND_RESET_I(32);
    io_regs_6 = VL_RAND_RESET_I(32);
    io_regs_7 = VL_RAND_RESET_I(32);
    io_regs_8 = VL_RAND_RESET_I(32);
    io_regs_9 = VL_RAND_RESET_I(32);
    io_regs_10 = VL_RAND_RESET_I(32);
    io_regs_11 = VL_RAND_RESET_I(32);
    io_regs_12 = VL_RAND_RESET_I(32);
    io_regs_13 = VL_RAND_RESET_I(32);
    io_regs_14 = VL_RAND_RESET_I(32);
    io_regs_15 = VL_RAND_RESET_I(32);
    io_regs_16 = VL_RAND_RESET_I(32);
    io_regs_17 = VL_RAND_RESET_I(32);
    io_regs_18 = VL_RAND_RESET_I(32);
    io_regs_19 = VL_RAND_RESET_I(32);
    io_regs_20 = VL_RAND_RESET_I(32);
    io_regs_21 = VL_RAND_RESET_I(32);
    io_regs_22 = VL_RAND_RESET_I(32);
    io_regs_23 = VL_RAND_RESET_I(32);
    io_regs_24 = VL_RAND_RESET_I(32);
    io_regs_25 = VL_RAND_RESET_I(32);
    io_regs_26 = VL_RAND_RESET_I(32);
    io_regs_27 = VL_RAND_RESET_I(32);
    io_regs_28 = VL_RAND_RESET_I(32);
    io_regs_29 = VL_RAND_RESET_I(32);
    io_regs_30 = VL_RAND_RESET_I(32);
    io_regs_31 = VL_RAND_RESET_I(32);
    io_Hcf = VL_RAND_RESET_I(1);
    io_inst = VL_RAND_RESET_I(32);
    io_rdata = VL_RAND_RESET_I(32);
    io_wdata = VL_RAND_RESET_I(32);
    io_Dump_Mem = VL_RAND_RESET_I(1);
    io_E_Branch_taken = VL_RAND_RESET_I(1);
    io_Flush = VL_RAND_RESET_I(1);
    io_Stall_MA = VL_RAND_RESET_I(1);
    io_Stall_DH = VL_RAND_RESET_I(1);
    io_IF_PC = VL_RAND_RESET_I(32);
    io_ID_PC = VL_RAND_RESET_I(32);
    io_EXE_PC = VL_RAND_RESET_I(32);
    io_MEM_PC = VL_RAND_RESET_I(32);
    io_WB_PC = VL_RAND_RESET_I(32);
    io_EXE_alu_out = VL_RAND_RESET_I(32);
    io_EXE_src1 = VL_RAND_RESET_I(32);
    io_EXE_src2 = VL_RAND_RESET_I(32);
    io_ALU_src1 = VL_RAND_RESET_I(32);
    io_ALU_src2 = VL_RAND_RESET_I(32);
    io_raddr = VL_RAND_RESET_I(32);
    io_WB_rd = VL_RAND_RESET_I(5);
    io_WB_wdata = VL_RAND_RESET_I(32);
    io_EXE_Jump = VL_RAND_RESET_I(1);
    io_EXE_Branch = VL_RAND_RESET_I(1);
    io_DMA_Hcf = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma_io_master_aw_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu_io_master_aw_bits_addr = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu_io_master_b_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu_io_master_ar_bits_addr = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu_io_master_r_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu_io_Stall_MA = VL_RAND_RESET_I(1);
    top_SoC__DOT__im_io_inst = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT__mState = VL_RAND_RESET_I(3);
    top_SoC__DOT__dma__DOT__sReadState = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma__DOT__sWriteState = VL_RAND_RESET_I(2);
    top_SoC__DOT__dma__DOT__sReadAddrReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT__sReadIDReg = VL_RAND_RESET_I(4);
    top_SoC__DOT__dma__DOT__sWriteIDReg = VL_RAND_RESET_I(4);
    top_SoC__DOT__dma__DOT__sWriteDataRecv = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma__DOT__sWriteAddrRecv = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma__DOT__sWriteDataReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT__sWriteAddrReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT__mWriteAddrSent = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma__DOT__mWriteDataSent = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma__DOT__mmio_regs_0 = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT__mmio_regs_1 = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT__mmio_regs_2 = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT__mmio_regs_3 = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT__mmio_regs_4 = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT__mmio_regs_5 = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT__data_buffer = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT__source_offset = VL_RAND_RESET_I(2);
    top_SoC__DOT__dma__DOT__request_counter = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT___io_slave_aw_ready_T_2 = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma__DOT___io_slave_ar_ready_T = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma__DOT___GEN_2 = VL_RAND_RESET_I(3);
    top_SoC__DOT__dma__DOT___GEN_6 = VL_RAND_RESET_I(3);
    top_SoC__DOT__dma__DOT___GEN_10 = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma__DOT___GEN_16 = VL_RAND_RESET_I(2);
    top_SoC__DOT__dma__DOT___request_counter_T_1 = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT___GEN_22 = VL_RAND_RESET_Q(40);
    top_SoC__DOT__dma__DOT___mask_width_T_8 = VL_RAND_RESET_I(4);
    top_SoC__DOT__dma__DOT__mask_width = VL_RAND_RESET_I(4);
    top_SoC__DOT__dma__DOT___GEN_29 = VL_RAND_RESET_I(7);
    top_SoC__DOT__dma__DOT___GEN_35 = VL_RAND_RESET_Q(40);
    top_SoC__DOT__dma__DOT___GEN_40 = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT___GEN_41 = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT___GEN_44 = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma__DOT___GEN_45 = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma__DOT___GEN_46 = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma__DOT___GEN_49 = VL_RAND_RESET_I(1);
    top_SoC__DOT__dma__DOT___GEN_64 = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT___GEN_65 = VL_RAND_RESET_I(32);
    top_SoC__DOT__dma__DOT___GEN_66 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_ID_io_Stall = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__stage_EXE_io_Flush = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__stage_EXE_io_Stall = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__datapath_MEM_io_Mem_Data = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_WB_io_WB_wdata = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__contorller_io_Flush_BH = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__contorller_io_Stall_WB_ID_DH = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__contorller_io_D_ImmSel = VL_RAND_RESET_I(3);
    top_SoC__DOT__cpu__DOT__contorller_io_W_RegWEn = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__contorller_io_E_ASel = VL_RAND_RESET_I(2);
    top_SoC__DOT__cpu__DOT__contorller_io_E_BSel = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__contorller_io_E_ALUSel = VL_RAND_RESET_I(15);
    top_SoC__DOT__cpu__DOT__contorller_io_W_WBSel = VL_RAND_RESET_I(2);
    top_SoC__DOT__cpu__DOT__wState = VL_RAND_RESET_I(2);
    top_SoC__DOT__cpu__DOT___GEN_2 = VL_RAND_RESET_I(2);
    top_SoC__DOT__cpu__DOT___GEN_8 = VL_RAND_RESET_Q(63);
    top_SoC__DOT__cpu__DOT__rState = VL_RAND_RESET_I(2);
    top_SoC__DOT__cpu__DOT___GEN_12 = VL_RAND_RESET_I(2);
    top_SoC__DOT__cpu__DOT__stage_IF__DOT__pcReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_ID__DOT__InstReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_ID__DOT__pcReg = VL_RAND_RESET_I(15);
    top_SoC__DOT__cpu__DOT__stage_ID__DOT___GEN_4 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_EXE__DOT__pcReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_EXE__DOT__InstReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_EXE__DOT__immReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs1Reg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_EXE__DOT__rs2Reg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_MEM__DOT__InstReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_MEM__DOT__pcReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_MEM__DOT__aluReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_MEM__DOT__wdataReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_WB__DOT__pc_plus4_Reg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_WB__DOT__InstReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_WB__DOT__alu_out_Reg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__stage_WB__DOT__ld_data_Reg = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_IF__DOT___io_next_pc_T_9 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_1 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_2 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_3 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_4 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_5 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_6 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_7 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_8 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_9 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_10 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_11 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_12 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_13 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_14 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_15 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_16 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_17 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_18 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_19 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_20 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_21 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_22 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_23 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_24 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_25 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_26 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_27 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_28 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_29 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_30 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT__regs_31 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_13 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_26 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_45 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__rf__DOT___GEN_58 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_13 = VL_RAND_RESET_I(12);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_22 = VL_RAND_RESET_I(21);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_26 = VL_RAND_RESET_I(12);
    top_SoC__DOT__cpu__DOT__datapath_ID__DOT__ig__DOT___simm_T_30 = VL_RAND_RESET_I(13);
    top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrEq = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__bc_io_BrLT = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src1 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu_io_src2 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_EXE__DOT___alu_src1_T_3 = VL_RAND_RESET_I(32);
    top_SoC__DOT__cpu__DOT__datapath_EXE__DOT__alu__DOT___GEN_10 = VL_RAND_RESET_Q(64);
    top_SoC__DOT__cpu__DOT__contorller__DOT___E_Branch_taken_T_14 = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__contorller__DOT__E_Branch_taken = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__contorller__DOT___io_E_ALUSel_T_1 = VL_RAND_RESET_I(15);
    top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs1 = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__contorller__DOT__is_D_use_rs2 = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__contorller__DOT__is_E_use_rd = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__contorller__DOT__is_M_use_rd = VL_RAND_RESET_I(1);
    top_SoC__DOT__cpu__DOT__contorller__DOT__is_W_use_rd = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32768; ++__Vi0) {
            top_SoC__DOT__im__DOT__memory[__Vi0] = VL_RAND_RESET_I(8);
    }}
    top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_0_io_master_readData_bits_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__readBuses_0_io_slave_0_readAddr_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_0_io_slave_1_readAddr_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_0_io_slave_2_readAddr_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_1_io_master_readData_bits_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__readBuses_1_io_slave_0_readAddr_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_1_io_slave_1_readAddr_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_1_io_slave_2_readAddr_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0_io_out_readData_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0_io_in_0_readData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0_io_in_1_readData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1_io_in_0_readData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1_io_in_1_readData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2_io_in_0_readData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2_io_in_1_readData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeAddr_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_strb = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeData_bits_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_0_writeResp_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeAddr_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_strb = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeData_bits_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_1_writeResp_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeAddr_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_strb = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeData_bits_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0_io_slave_2_writeResp_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeAddr_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_strb = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeData_bits_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_0_writeResp_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeAddr_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_strb = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeData_bits_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_1_writeResp_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeAddr_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_strb = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeData_bits_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1_io_slave_2_writeResp_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0_io_out_writeResp_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeData_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_0_writeResp_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeData_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0_io_in_1_writeResp_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1_io_out_writeResp_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeData_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_0_writeResp_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeData_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1_io_in_1_writeResp_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2_io_out_writeResp_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeData_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_0_writeResp_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeData_ready = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2_io_in_1_writeResp_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_port_reg = VL_RAND_RESET_I(3);
    top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_size = VL_RAND_RESET_I(3);
    top_SoC__DOT__bus__DOT__readBuses_0__DOT__read_addr_reg_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_0__DOT__outstanding = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_0__DOT___T = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_0__DOT___GEN_0 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_0__DOT___GEN_5 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_port_reg = VL_RAND_RESET_I(3);
    top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_size = VL_RAND_RESET_I(3);
    top_SoC__DOT__bus__DOT__readBuses_1__DOT__read_addr_reg_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_1__DOT__outstanding = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_1__DOT___T = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_1__DOT___GEN_0 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readBuses_1__DOT___GEN_5 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_0_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_in_1_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_out_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter_io_chosen = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__state = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__chosen_reg = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__ar_determined = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_addr = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__address_reg_size = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_resp = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__data_reg_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__mask_0 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT___T_2 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT___GEN_6 = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT___GEN_41 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT___T_9 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__lastGrant = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_0__DOT__arbiter__DOT__validMask_1 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_0_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_in_1_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_out_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter_io_chosen = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__state = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__chosen_reg = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__ar_determined = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_addr = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__address_reg_size = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_resp = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__data_reg_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__mask_0 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT___T_2 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT___GEN_6 = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT___GEN_41 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT___T_9 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__lastGrant = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_1__DOT__arbiter__DOT__validMask_1 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_0_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_in_1_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_out_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter_io_chosen = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__state = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__chosen_reg = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__ar_determined = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_addr = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__address_reg_size = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_resp = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__data_reg_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__mask_0 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT___T_2 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT___GEN_6 = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT___GEN_41 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT___T_9 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__lastGrant = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__readMuxes_2__DOT__arbiter__DOT__validMask_1 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_port_reg = VL_RAND_RESET_I(3);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_addr_reg_size = VL_RAND_RESET_I(3);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_strb = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_data_reg_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__write_resp_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__w_outstanding = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__aw_outstanding = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT__b_outstanding = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_0 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_3 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_1 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_6 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_9 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT___T_10 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_35 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_0__DOT___GEN_36 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_port_reg = VL_RAND_RESET_I(3);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_addr_reg_size = VL_RAND_RESET_I(3);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_strb = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_data_reg_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__write_resp_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__w_outstanding = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__aw_outstanding = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT__b_outstanding = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_0 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_3 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_1 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_6 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_9 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT___T_10 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_35 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeBuses_1__DOT___GEN_36 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_0_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_in_1_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_out_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter_io_chosen = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__state = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__chosen_reg = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__w_determined = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__aw_determined = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_addr = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__address_reg_size = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_strb = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__data_reg_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__resp_reg_resp = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__mask_0 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_1 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_5 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___T_7 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_11 = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_17 = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_52 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_66 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_76 = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_78 = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_80 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_84 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_88 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_89 = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT___GEN_90 = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__lastGrant = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_0__DOT__arbiter__DOT__validMask_1 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_0_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_in_1_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_out_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter_io_chosen = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__state = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__chosen_reg = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__w_determined = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__aw_determined = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_addr = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__address_reg_size = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_strb = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__data_reg_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__resp_reg_resp = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__mask_0 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_1 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_5 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___T_7 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_11 = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_17 = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_52 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_66 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_76 = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_78 = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_80 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_84 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_88 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_89 = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT___GEN_90 = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__lastGrant = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_1__DOT__arbiter__DOT__validMask_1 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_0_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_in_1_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_out_valid = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter_io_chosen = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__state = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__chosen_reg = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__w_determined = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__aw_determined = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_addr = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__address_reg_size = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_data = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_strb = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__data_reg_last = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_id = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__resp_reg_resp = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__mask_0 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_1 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_5 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___T_7 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_11 = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_17 = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_52 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_66 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_76 = VL_RAND_RESET_I(32);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_78 = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_80 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_84 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_88 = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_89 = VL_RAND_RESET_I(4);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT___GEN_90 = VL_RAND_RESET_I(2);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__lastGrant = VL_RAND_RESET_I(1);
    top_SoC__DOT__bus__DOT__writeMuxes_2__DOT__arbiter__DOT__validMask_1 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
            top_SoC__DOT__localMem__DOT__memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
    top_SoC__DOT__localMem__DOT__readID = VL_RAND_RESET_I(4);
    top_SoC__DOT__localMem__DOT__rAddrOffset = VL_RAND_RESET_I(32);
    top_SoC__DOT__localMem__DOT__writeAddressReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__localMem__DOT__writeID = VL_RAND_RESET_I(4);
    top_SoC__DOT__localMem__DOT__writeState = VL_RAND_RESET_I(3);
    top_SoC__DOT__localMem__DOT__readState = VL_RAND_RESET_I(2);
    top_SoC__DOT__localMem__DOT__rLatencyCounter = VL_RAND_RESET_I(8);
    top_SoC__DOT__localMem__DOT__wLatencyCounter = VL_RAND_RESET_I(8);
    top_SoC__DOT__localMem__DOT___rLatencyCounter_T_1 = VL_RAND_RESET_I(8);
    top_SoC__DOT__localMem__DOT___GEN_15 = VL_RAND_RESET_I(1);
    top_SoC__DOT__localMem__DOT___T_10 = VL_RAND_RESET_I(1);
    top_SoC__DOT__localMem__DOT___GEN_31 = VL_RAND_RESET_I(3);
    top_SoC__DOT__localMem__DOT___GEN_34 = VL_RAND_RESET_I(3);
    top_SoC__DOT__localMem__DOT___GEN_38 = VL_RAND_RESET_I(3);
    top_SoC__DOT__localMem__DOT__lo = VL_RAND_RESET_I(16);
    top_SoC__DOT__localMem__DOT__hi = VL_RAND_RESET_I(16);
    top_SoC__DOT__localMem__DOT___GEN_58 = VL_RAND_RESET_I(32);
    top_SoC__DOT__localMem__DOT___GEN_59 = VL_RAND_RESET_I(4);
    top_SoC__DOT__localMem__DOT___GEN_76 = VL_RAND_RESET_I(8);
    top_SoC__DOT__localMem__DOT__initvar = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
            top_SoC__DOT__globalMem__DOT__memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
    top_SoC__DOT__globalMem__DOT__readID = VL_RAND_RESET_I(4);
    top_SoC__DOT__globalMem__DOT__rAddrOffset = VL_RAND_RESET_I(32);
    top_SoC__DOT__globalMem__DOT__writeAddressReg = VL_RAND_RESET_I(32);
    top_SoC__DOT__globalMem__DOT__writeID = VL_RAND_RESET_I(4);
    top_SoC__DOT__globalMem__DOT__writeState = VL_RAND_RESET_I(3);
    top_SoC__DOT__globalMem__DOT__readState = VL_RAND_RESET_I(2);
    top_SoC__DOT__globalMem__DOT__rLatencyCounter = VL_RAND_RESET_I(8);
    top_SoC__DOT__globalMem__DOT__wLatencyCounter = VL_RAND_RESET_I(8);
    top_SoC__DOT__globalMem__DOT___rLatencyCounter_T_1 = VL_RAND_RESET_I(8);
    top_SoC__DOT__globalMem__DOT___GEN_15 = VL_RAND_RESET_I(1);
    top_SoC__DOT__globalMem__DOT___T_10 = VL_RAND_RESET_I(1);
    top_SoC__DOT__globalMem__DOT___GEN_31 = VL_RAND_RESET_I(3);
    top_SoC__DOT__globalMem__DOT___GEN_34 = VL_RAND_RESET_I(3);
    top_SoC__DOT__globalMem__DOT___GEN_38 = VL_RAND_RESET_I(3);
    top_SoC__DOT__globalMem__DOT__lo = VL_RAND_RESET_I(16);
    top_SoC__DOT__globalMem__DOT__hi = VL_RAND_RESET_I(16);
    top_SoC__DOT__globalMem__DOT___GEN_58 = VL_RAND_RESET_I(32);
    top_SoC__DOT__globalMem__DOT___GEN_59 = VL_RAND_RESET_I(4);
    top_SoC__DOT__globalMem__DOT___GEN_76 = VL_RAND_RESET_I(8);
    top_SoC__DOT__globalMem__DOT__initvar = VL_RAND_RESET_I(32);
    __Vm_traceActivity = 0;
}
