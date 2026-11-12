// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_trng_top.h for the primary calling header

#include "verilated.h"

#include "Vtb_trng_top__Syms.h"
#include "Vtb_trng_top___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__0(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_initial__TOP__0\n"); );
    // Init
    VlWide<7>/*223:0*/ __Vtemp_he57977de__0;
    // Body
    __Vtemp_he57977de__0[0U] = 0x2e766364U;
    __Vtemp_he57977de__0[1U] = 0x74696f6eU;
    __Vtemp_he57977de__0[2U] = 0x6d756c61U;
    __Vtemp_he57977de__0[3U] = 0x735f7369U;
    __Vtemp_he57977de__0[4U] = 0x68657369U;
    __Vtemp_he57977de__0[5U] = 0x73796e74U;
    __Vtemp_he57977de__0[6U] = 0x5072655fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(7, __Vtemp_he57977de__0));
    vlSymsp->_traceDumpOpen();
    co_await vlSelf->__VtrigSched_h7a1314a4__0.trigger(
                                                       "@(posedge tb_trng_top.clk)", 
                                                       "/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 
                                                       50);
    co_await vlSelf->__VtrigSched_h7a1314a4__0.trigger(
                                                       "@(posedge tb_trng_top.clk)", 
                                                       "/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 
                                                       50);
    co_await vlSelf->__VtrigSched_h7a1314a4__0.trigger(
                                                       "@(posedge tb_trng_top.clk)", 
                                                       "/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 
                                                       50);
    co_await vlSelf->__VtrigSched_h7a1314a4__0.trigger(
                                                       "@(posedge tb_trng_top.clk)", 
                                                       "/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 
                                                       50);
    co_await vlSelf->__VtrigSched_h7a1314a4__0.trigger(
                                                       "@(posedge tb_trng_top.clk)", 
                                                       "/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 
                                                       50);
    co_await vlSelf->__VtrigSched_h7a1314a4__0.trigger(
                                                       "@(posedge tb_trng_top.clk)", 
                                                       "/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 
                                                       50);
    co_await vlSelf->__VtrigSched_h7a1314a4__0.trigger(
                                                       "@(posedge tb_trng_top.clk)", 
                                                       "/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 
                                                       50);
    co_await vlSelf->__VtrigSched_h7a1314a4__0.trigger(
                                                       "@(posedge tb_trng_top.clk)", 
                                                       "/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 
                                                       50);
    co_await vlSelf->__VtrigSched_h7a1314a4__0.trigger(
                                                       "@(posedge tb_trng_top.clk)", 
                                                       "/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 
                                                       50);
    co_await vlSelf->__VtrigSched_h7a1314a4__0.trigger(
                                                       "@(posedge tb_trng_top.clk)", 
                                                       "/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 
                                                       50);
    vlSelf->tb_trng_top__DOT__rst_n = 1U;
    co_await vlSelf->__VdlySched.delay(0xb2d05e00ULL, 
                                       "/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 
                                       53);
    VL_WRITEF("RTL_SIM_SUMMARY raw_sample_count=%0d tx_fall_count=%0d health_fail=%b\n",
              32,vlSelf->tb_trng_top__DOT__raw_sample_count,
              32,vlSelf->tb_trng_top__DOT__tx_fall_count,
              1,((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__apt_fail) 
                 | (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__rct_fail)));
    if (VL_UNLIKELY(VL_GTS_III(32, 0x64U, vlSelf->tb_trng_top__DOT__raw_sample_count))) {
        VL_WRITEF("RTL_SIM_FAIL: fewer than 100 raw samples\n[%0t] %%Fatal: tb_trng_top_rtl.v:62: Assertion failed in %Ntb_trng_top\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 62, "");
    }
    if (VL_UNLIKELY(VL_GTS_III(32, 1U, vlSelf->tb_trng_top__DOT__tx_fall_count))) {
        VL_WRITEF("RTL_SIM_FAIL: no UART activity\n[%0t] %%Fatal: tb_trng_top_rtl.v:67: Assertion failed in %Ntb_trng_top\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 67, "");
    }
    VL_WRITEF("RTL_SIM_PASS: behavioral functional test only; not an entropy measurement\n");
    VL_FINISH_MT("/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 74, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trng_top___024root___dump_triggers__act(Vtb_trng_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_trng_top___024root___eval_triggers__act(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->tb_trng_top__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__clk)));
    vlSelf->__VactTriggered.at(1U) = ((~ (IData)(vlSelf->tb_trng_top__DOT__tx)) 
                                      & (IData)(vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__tx));
    vlSelf->__VactTriggered.at(2U) = (((IData)(vlSelf->tb_trng_top__DOT__clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__clk))) 
                                      | ((~ (IData)(vlSelf->tb_trng_top__DOT__rst_n)) 
                                         & (IData)(vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__rst_n)));
    vlSelf->__VactTriggered.at(3U) = vlSelf->__VdlySched.awaitingCurrentTime();
    vlSelf->__VactTriggered.at(4U) = ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__dut__DOT__ro_en));
    vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__clk 
        = vlSelf->tb_trng_top__DOT__clk;
    vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__tx 
        = vlSelf->tb_trng_top__DOT__tx;
    vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__rst_n 
        = vlSelf->tb_trng_top__DOT__rst_n;
    vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__dut__DOT__ro_en 
        = vlSelf->tb_trng_top__DOT__dut__DOT__ro_en;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.at(4U) = 1U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_trng_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
