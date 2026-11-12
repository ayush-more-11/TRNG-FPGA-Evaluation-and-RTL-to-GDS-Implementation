// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_trng_top.h for the primary calling header

#include "verilated.h"

#include "Vtb_trng_top___024root.h"

VL_ATTR_COLD void Vtb_trng_top___024root___eval_static__TOP(Vtb_trng_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_trng_top___024root___eval_static(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_static\n"); );
    // Body
    Vtb_trng_top___024root___eval_static__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtb_trng_top___024root___eval_static__TOP(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb_trng_top__DOT__clk = 0U;
    vlSelf->tb_trng_top__DOT__rst_n = 0U;
    vlSelf->tb_trng_top__DOT__raw_sample_count = 0U;
    vlSelf->tb_trng_top__DOT__tx_fall_count = 0U;
}

VL_ATTR_COLD void Vtb_trng_top___024root___eval_initial__TOP(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc = 0U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__seed = 0x13579d0eU;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc = 1U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__seed = 0x1357bcc7U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc = 0U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__seed = 0x1357dc80U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc = 1U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__seed = 0x1357fc39U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc = 0U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__seed = 0x13581bf2U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc = 1U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__seed = 0x13583babU;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc = 0U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__seed = 0x13585b64U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc = 1U;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__seed = 0x13587b1dU;
}

VL_ATTR_COLD void Vtb_trng_top___024root___eval_final(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtb_trng_top___024root___eval_triggers__stl(Vtb_trng_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trng_top___024root___dump_triggers__stl(Vtb_trng_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtb_trng_top___024root___eval_stl(Vtb_trng_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_trng_top___024root___eval_settle(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtb_trng_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtb_trng_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 3, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtb_trng_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trng_top___024root___dump_triggers__stl(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_trng_top___024root___stl_sequent__TOP__0(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb_trng_top__DOT__dut__DOT__warm_done = 
        (0x100U <= (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__warm));
    vlSelf->tb_trng_top__DOT__dut__DOT__raw_valid = 
        ((0x100U <= (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__warm)) 
         & (0x7cfU == vlSelf->tb_trng_top__DOT__dut__DOT__div));
    vlSelf->tb_trng_top__DOT__dut__DOT__tx_start = 
        ((~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__busy)) 
         & (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__tx_pending));
}

VL_ATTR_COLD void Vtb_trng_top___024root___eval_stl(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtb_trng_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trng_top___024root___dump_triggers__act(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_trng_top.clk)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_trng_top.tx)\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge tb_trng_top.clk or negedge tb_trng_top.rst_n)\n");
    }
    if (vlSelf->__VactTriggered.at(3U)) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if (vlSelf->__VactTriggered.at(4U)) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([changed] tb_trng_top.dut.ro_en)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trng_top___024root___dump_triggers__nba(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_trng_top.clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_trng_top.tx)\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge tb_trng_top.clk or negedge tb_trng_top.rst_n)\n");
    }
    if (vlSelf->__VnbaTriggered.at(3U)) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if (vlSelf->__VnbaTriggered.at(4U)) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([changed] tb_trng_top.dut.ro_en)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_trng_top___024root___ctor_var_reset(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_trng_top__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__tx = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__raw_sample_count = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__tx_fall_count = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__ro_en = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__div = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__warm = VL_RAND_RESET_I(16);
    vlSelf->tb_trng_top__DOT__dut__DOT__warm_done = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__raw_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__dbg_bit_q = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__dbg_val_q = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__rct_fail = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__apt_fail = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__bit_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__bit_out = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__byte_reg = VL_RAND_RESET_I(7);
    vlSelf->tb_trng_top__DOT__dut__DOT__bit_idx = VL_RAND_RESET_I(3);
    vlSelf->tb_trng_top__DOT__dut__DOT__tx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_trng_top__DOT__dut__DOT__tx_pending = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__tx_start = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT____Vlvbound_h36c0d37c__0 = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr = VL_RAND_RESET_I(2);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__seed = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__delay_ns = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__seed = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__delay_ns = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__seed = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__delay_ns = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__seed = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__delay_ns = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__seed = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__delay_ns = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__seed = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__delay_ns = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__seed = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__delay_ns = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__seed = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__delay_ns = VL_RAND_RESET_I(32);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s0 = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s1 = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__last = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt = VL_RAND_RESET_I(8);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt = VL_RAND_RESET_I(16);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx = VL_RAND_RESET_I(16);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_vn__DOT__have = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_vn__DOT__first = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__busy = VL_RAND_RESET_I(1);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt = VL_RAND_RESET_I(16);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt = VL_RAND_RESET_I(4);
    vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__shreg = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__tx = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__dut__DOT__ro_en = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
