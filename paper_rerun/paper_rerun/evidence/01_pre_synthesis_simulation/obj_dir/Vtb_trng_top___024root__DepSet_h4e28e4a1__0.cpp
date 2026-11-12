// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_trng_top.h for the primary calling header

#include "verilated.h"

#include "Vtb_trng_top___024root.h"

VL_ATTR_COLD void Vtb_trng_top___024root___eval_initial__TOP(Vtb_trng_top___024root* vlSelf);
VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__0(Vtb_trng_top___024root* vlSelf);
VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__1(Vtb_trng_top___024root* vlSelf);
VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__2(Vtb_trng_top___024root* vlSelf);
VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__3(Vtb_trng_top___024root* vlSelf);
VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__4(Vtb_trng_top___024root* vlSelf);
VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__5(Vtb_trng_top___024root* vlSelf);
VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__6(Vtb_trng_top___024root* vlSelf);
VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__7(Vtb_trng_top___024root* vlSelf);
VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__8(Vtb_trng_top___024root* vlSelf);
VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__9(Vtb_trng_top___024root* vlSelf);

void Vtb_trng_top___024root___eval_initial(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_initial\n"); );
    // Body
    Vtb_trng_top___024root___eval_initial__TOP(vlSelf);
    Vtb_trng_top___024root___eval_initial__TOP__0(vlSelf);
    Vtb_trng_top___024root___eval_initial__TOP__1(vlSelf);
    Vtb_trng_top___024root___eval_initial__TOP__2(vlSelf);
    Vtb_trng_top___024root___eval_initial__TOP__3(vlSelf);
    Vtb_trng_top___024root___eval_initial__TOP__4(vlSelf);
    Vtb_trng_top___024root___eval_initial__TOP__5(vlSelf);
    Vtb_trng_top___024root___eval_initial__TOP__6(vlSelf);
    Vtb_trng_top___024root___eval_initial__TOP__7(vlSelf);
    Vtb_trng_top___024root___eval_initial__TOP__8(vlSelf);
    Vtb_trng_top___024root___eval_initial__TOP__9(vlSelf);
    vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__clk 
        = vlSelf->tb_trng_top__DOT__clk;
    vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__tx 
        = vlSelf->tb_trng_top__DOT__tx;
    vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__rst_n 
        = vlSelf->tb_trng_top__DOT__rst_n;
    vlSelf->__Vtrigrprev__TOP__tb_trng_top__DOT__dut__DOT__ro_en 
        = vlSelf->tb_trng_top__DOT__dut__DOT__ro_en;
}

VL_INLINE_OPT VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__1(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_initial__TOP__1\n"); );
    // Body
    while (1U) {
        if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__delay_ns 
                = ((IData)(0x22U) + (IData)(VL_MODDIV_III(32, (IData)(
                                                                      VL_RANDOM_SEEDED_II(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__seed)), (IData)(5U))));
            co_await vlSelf->__VdlySched.delay((0x3e8ULL 
                                                * (QData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__delay_ns)), 
                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                               53);
            if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
                vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc 
                    = (1U & (~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc)));
            }
        } else {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc = 0U;
            co_await vlSelf->__VtrigSched_h1db52719__0.trigger(
                                                               "@([changed] tb_trng_top.dut.ro_en)", 
                                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                                               59);
        }
    }
}

VL_INLINE_OPT VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__2(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_initial__TOP__2\n"); );
    // Body
    while (1U) {
        if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__delay_ns 
                = ((IData)(0x1eU) + (IData)(VL_MODDIV_III(32, (IData)(
                                                                      VL_RANDOM_SEEDED_II(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__seed)), (IData)(5U))));
            co_await vlSelf->__VdlySched.delay((0x3e8ULL 
                                                * (QData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__delay_ns)), 
                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                               53);
            if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
                vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc 
                    = (1U & (~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc)));
            }
        } else {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc = 0U;
            co_await vlSelf->__VtrigSched_h1db52719__0.trigger(
                                                               "@([changed] tb_trng_top.dut.ro_en)", 
                                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                                               59);
        }
    }
}

VL_INLINE_OPT VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__3(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_initial__TOP__3\n"); );
    // Body
    while (1U) {
        if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__delay_ns 
                = ((IData)(0x1aU) + (IData)(VL_MODDIV_III(32, (IData)(
                                                                      VL_RANDOM_SEEDED_II(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__seed)), (IData)(5U))));
            co_await vlSelf->__VdlySched.delay((0x3e8ULL 
                                                * (QData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__delay_ns)), 
                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                               53);
            if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
                vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc 
                    = (1U & (~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc)));
            }
        } else {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc = 0U;
            co_await vlSelf->__VtrigSched_h1db52719__0.trigger(
                                                               "@([changed] tb_trng_top.dut.ro_en)", 
                                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                                               59);
        }
    }
}

VL_INLINE_OPT VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__4(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_initial__TOP__4\n"); );
    // Body
    while (1U) {
        if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__delay_ns 
                = ((IData)(0x16U) + (IData)(VL_MODDIV_III(32, (IData)(
                                                                      VL_RANDOM_SEEDED_II(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__seed)), (IData)(5U))));
            co_await vlSelf->__VdlySched.delay((0x3e8ULL 
                                                * (QData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__delay_ns)), 
                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                               53);
            if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
                vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc 
                    = (1U & (~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc)));
            }
        } else {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc = 0U;
            co_await vlSelf->__VtrigSched_h1db52719__0.trigger(
                                                               "@([changed] tb_trng_top.dut.ro_en)", 
                                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                                               59);
        }
    }
}

VL_INLINE_OPT VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__5(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_initial__TOP__5\n"); );
    // Body
    while (1U) {
        if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__delay_ns 
                = ((IData)(0x12U) + (IData)(VL_MODDIV_III(32, (IData)(
                                                                      VL_RANDOM_SEEDED_II(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__seed)), (IData)(5U))));
            co_await vlSelf->__VdlySched.delay((0x3e8ULL 
                                                * (QData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__delay_ns)), 
                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                               53);
            if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
                vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc 
                    = (1U & (~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc)));
            }
        } else {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc = 0U;
            co_await vlSelf->__VtrigSched_h1db52719__0.trigger(
                                                               "@([changed] tb_trng_top.dut.ro_en)", 
                                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                                               59);
        }
    }
}

VL_INLINE_OPT VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__6(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_initial__TOP__6\n"); );
    // Body
    while (1U) {
        if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__delay_ns 
                = ((IData)(0xeU) + (IData)(VL_MODDIV_III(32, (IData)(
                                                                     VL_RANDOM_SEEDED_II(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__seed)), (IData)(5U))));
            co_await vlSelf->__VdlySched.delay((0x3e8ULL 
                                                * (QData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__delay_ns)), 
                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                               53);
            if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
                vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc 
                    = (1U & (~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc)));
            }
        } else {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc = 0U;
            co_await vlSelf->__VtrigSched_h1db52719__0.trigger(
                                                               "@([changed] tb_trng_top.dut.ro_en)", 
                                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                                               59);
        }
    }
}

VL_INLINE_OPT VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__7(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_initial__TOP__7\n"); );
    // Body
    while (1U) {
        if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__delay_ns 
                = ((IData)(0xaU) + (IData)(VL_MODDIV_III(32, (IData)(
                                                                     VL_RANDOM_SEEDED_II(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__seed)), (IData)(5U))));
            co_await vlSelf->__VdlySched.delay((0x3e8ULL 
                                                * (QData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__delay_ns)), 
                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                               53);
            if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
                vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc 
                    = (1U & (~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc)));
            }
        } else {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc = 0U;
            co_await vlSelf->__VtrigSched_h1db52719__0.trigger(
                                                               "@([changed] tb_trng_top.dut.ro_en)", 
                                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                                               59);
        }
    }
}

VL_INLINE_OPT VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__8(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_initial__TOP__8\n"); );
    // Body
    while (1U) {
        if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__delay_ns 
                = ((IData)(6U) + (IData)(VL_MODDIV_III(32, (IData)(
                                                                   VL_RANDOM_SEEDED_II(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__seed)), (IData)(5U))));
            co_await vlSelf->__VdlySched.delay((0x3e8ULL 
                                                * (QData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__delay_ns)), 
                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                               53);
            if (vlSelf->tb_trng_top__DOT__dut__DOT__ro_en) {
                vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc 
                    = (1U & (~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc)));
            }
        } else {
            vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc = 0U;
            co_await vlSelf->__VtrigSched_h1db52719__0.trigger(
                                                               "@([changed] tb_trng_top.dut.ro_en)", 
                                                               "/openlane/designs/trng_top/paper_rerun/design/src/trng_top.v", 
                                                               59);
        }
    }
}

VL_INLINE_OPT VlCoroutine Vtb_trng_top___024root___eval_initial__TOP__9(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_initial__TOP__9\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           "/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 
                                           16);
        vlSelf->tb_trng_top__DOT__clk = (1U & (~ (IData)(vlSelf->tb_trng_top__DOT__clk)));
    }
}

void Vtb_trng_top___024root___eval_act(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_trng_top___024root___nba_sequent__TOP__0(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr 
        = vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr;
    vlSelf->__Vdly__tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr 
        = ((IData)(vlSelf->tb_trng_top__DOT__rst_n)
            ? (1U | (2U & ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr) 
                           << 1U))) : 0U);
}

extern const VlUnpacked<CData/*0:0*/, 32> Vtb_trng_top__ConstPool__TABLE_h1f523c37_0;
extern const VlUnpacked<CData/*3:0*/, 32> Vtb_trng_top__ConstPool__TABLE_h8ed2dc59_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vtb_trng_top__ConstPool__TABLE_h5ad1ec46_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vtb_trng_top__ConstPool__TABLE_h4c997901_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vtb_trng_top__ConstPool__TABLE_h1953ad9d_0;

VL_INLINE_OPT void Vtb_trng_top___024root___nba_sequent__TOP__1(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*0:0*/ __Vdly__tb_trng_top__DOT__dut__DOT__tx_pending;
    __Vdly__tb_trng_top__DOT__dut__DOT__tx_pending = 0;
    CData/*2:0*/ __Vdly__tb_trng_top__DOT__dut__DOT__bit_idx;
    __Vdly__tb_trng_top__DOT__dut__DOT__bit_idx = 0;
    CData/*7:0*/ __Vdly__tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt;
    __Vdly__tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt = 0;
    CData/*0:0*/ __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit;
    __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit = 0;
    SData/*15:0*/ __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt;
    __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt = 0;
    SData/*15:0*/ __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx;
    __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx = 0;
    SData/*15:0*/ __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt;
    __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt = 0;
    CData/*3:0*/ __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt;
    __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt = 0;
    // Body
    __Vdly__tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt 
        = vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt;
    __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx 
        = vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx;
    __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt 
        = vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt;
    __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit 
        = vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit;
    __Vdly__tb_trng_top__DOT__dut__DOT__bit_idx = vlSelf->tb_trng_top__DOT__dut__DOT__bit_idx;
    __Vdly__tb_trng_top__DOT__dut__DOT__tx_pending 
        = vlSelf->tb_trng_top__DOT__dut__DOT__tx_pending;
    __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt 
        = vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt;
    __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt 
        = vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt;
    if (((IData)(vlSelf->tb_trng_top__DOT__rst_n) & (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__dbg_val_q))) {
        vlSelf->tb_trng_top__DOT__raw_sample_count 
            = ((IData)(1U) + vlSelf->tb_trng_top__DOT__raw_sample_count);
    }
    if ((2U & (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr))) {
        vlSelf->tb_trng_top__DOT__dut__DOT__div = (
                                                   (0x7cfU 
                                                    == vlSelf->tb_trng_top__DOT__dut__DOT__div)
                                                    ? 0U
                                                    : 
                                                   ((IData)(1U) 
                                                    + vlSelf->tb_trng_top__DOT__dut__DOT__div));
        if ((1U & (~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__warm_done)))) {
            vlSelf->tb_trng_top__DOT__dut__DOT__warm 
                = (0xffffU & ((IData)(1U) + (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__warm)));
        }
        if (vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__busy) {
            if ((0x363U == (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt))) {
                __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt = 0U;
                if ((8U > (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt))) {
                    __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt)));
                    vlSelf->tb_trng_top__DOT__tx = 
                        (1U & (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__shreg));
                    vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__shreg 
                        = (0x80U | (0x7fU & ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__shreg) 
                                             >> 1U)));
                } else if ((8U == (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt))) {
                    __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt = 9U;
                    vlSelf->tb_trng_top__DOT__tx = 1U;
                } else {
                    __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt = 0U;
                    vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__busy = 0U;
                }
            } else {
                __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt)));
            }
        } else {
            vlSelf->tb_trng_top__DOT__tx = 1U;
            if (vlSelf->tb_trng_top__DOT__dut__DOT__tx_start) {
                vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__shreg 
                    = vlSelf->tb_trng_top__DOT__dut__DOT__tx_data;
                __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt = 0U;
                vlSelf->tb_trng_top__DOT__tx = 0U;
                vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__busy = 1U;
                __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt = 0U;
            }
        }
        if (vlSelf->tb_trng_top__DOT__dut__DOT__tx_start) {
            __Vdly__tb_trng_top__DOT__dut__DOT__tx_pending = 0U;
        }
        if (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__bit_valid) 
             & (~ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__apt_fail) 
                   | (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__rct_fail))))) {
            if ((7U == (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__bit_idx))) {
                __Vdly__tb_trng_top__DOT__dut__DOT__bit_idx = 0U;
                if ((1U & (~ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__tx_pending) 
                              & (~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__tx_start)))))) {
                    vlSelf->tb_trng_top__DOT__dut__DOT__tx_data 
                        = (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__bit_out) 
                            << 7U) | (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__byte_reg));
                    __Vdly__tb_trng_top__DOT__dut__DOT__tx_pending = 1U;
                }
                vlSelf->tb_trng_top__DOT__dut__DOT__byte_reg = 0U;
            } else {
                vlSelf->tb_trng_top__DOT__dut__DOT____Vlvbound_h36c0d37c__0 
                    = vlSelf->tb_trng_top__DOT__dut__DOT__bit_out;
                if ((6U >= (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__bit_idx))) {
                    vlSelf->tb_trng_top__DOT__dut__DOT__byte_reg 
                        = (((~ ((IData)(1U) << (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__bit_idx))) 
                            & (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__byte_reg)) 
                           | (0x7fU & ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT____Vlvbound_h36c0d37c__0) 
                                       << (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__bit_idx))));
                }
                __Vdly__tb_trng_top__DOT__dut__DOT__bit_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__bit_idx)));
            }
        }
        if (vlSelf->tb_trng_top__DOT__dut__DOT__raw_valid) {
            if (((0U != (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt)) 
                 & ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s1) 
                    == (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__last)))) {
                if ((0xffU != (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt))) {
                    __Vdly__tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt)));
                }
                if ((0x29U <= ((IData)(1U) + (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt)))) {
                    vlSelf->tb_trng_top__DOT__dut__DOT__rct_fail = 1U;
                }
            } else {
                vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__last 
                    = vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s1;
                __Vdly__tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt = 1U;
            }
            if ((0U == (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx))) {
                __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit 
                    = vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s1;
                __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt = 1U;
                __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx = 1U;
            } else {
                __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx 
                    = ((0x3ffU == (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx))
                        ? 0U : (0xffffU & ((IData)(1U) 
                                           + (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx))));
                if (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s1) 
                     == (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit))) {
                    __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt)));
                    if ((0x319U <= ((IData)(1U) + (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt)))) {
                        vlSelf->tb_trng_top__DOT__dut__DOT__apt_fail = 1U;
                    }
                }
            }
        }
    } else {
        vlSelf->tb_trng_top__DOT__dut__DOT__div = 0U;
        vlSelf->tb_trng_top__DOT__dut__DOT__warm = 0U;
        __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt = 0U;
        vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__shreg = 0U;
        vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__busy = 0U;
        __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt = 0U;
        vlSelf->tb_trng_top__DOT__tx = 1U;
        __Vdly__tb_trng_top__DOT__dut__DOT__tx_pending = 0U;
        vlSelf->tb_trng_top__DOT__dut__DOT__byte_reg = 0U;
        __Vdly__tb_trng_top__DOT__dut__DOT__bit_idx = 0U;
        vlSelf->tb_trng_top__DOT__dut__DOT__tx_data = 0U;
        vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__last = 0U;
        __Vdly__tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt = 0U;
        vlSelf->tb_trng_top__DOT__dut__DOT__rct_fail = 0U;
        __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit = 0U;
        __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt = 0U;
        __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx = 0U;
        vlSelf->tb_trng_top__DOT__dut__DOT__apt_fail = 0U;
    }
    vlSelf->tb_trng_top__DOT__dut__DOT__ro_en = (1U 
                                                 & ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr) 
                                                    >> 1U));
    vlSelf->tb_trng_top__DOT__dut__DOT__dbg_bit_q = 
        (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr) 
          >> 1U) & (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s1));
    vlSelf->tb_trng_top__DOT__dut__DOT__dbg_val_q = 
        (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr) 
          >> 1U) & (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__raw_valid));
    vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt 
        = __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt 
        = __Vdly__tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt;
    vlSelf->tb_trng_top__DOT__dut__DOT__warm_done = 
        (0x100U <= (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__warm));
    vlSelf->tb_trng_top__DOT__dut__DOT__bit_idx = __Vdly__tb_trng_top__DOT__dut__DOT__bit_idx;
    vlSelf->tb_trng_top__DOT__dut__DOT__tx_pending 
        = __Vdly__tb_trng_top__DOT__dut__DOT__tx_pending;
    vlSelf->tb_trng_top__DOT__dut__DOT__tx_start = 
        ((~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__busy)) 
         & (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__tx_pending));
    __Vtableidx1 = (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s1) 
                     << 4U) | (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_vn__DOT__first) 
                                << 3U) | (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_vn__DOT__have) 
                                           << 2U) | 
                                          (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__raw_valid) 
                                            << 1U) 
                                           | (1U & 
                                              ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr) 
                                               >> 1U))))));
    vlSelf->tb_trng_top__DOT__dut__DOT__bit_valid = 
        Vtb_trng_top__ConstPool__TABLE_h1f523c37_0[__Vtableidx1];
    if ((2U & Vtb_trng_top__ConstPool__TABLE_h8ed2dc59_0
         [__Vtableidx1])) {
        vlSelf->tb_trng_top__DOT__dut__DOT__u_vn__DOT__have 
            = Vtb_trng_top__ConstPool__TABLE_h5ad1ec46_0
            [__Vtableidx1];
    }
    if ((4U & Vtb_trng_top__ConstPool__TABLE_h8ed2dc59_0
         [__Vtableidx1])) {
        vlSelf->tb_trng_top__DOT__dut__DOT__bit_out 
            = Vtb_trng_top__ConstPool__TABLE_h4c997901_0
            [__Vtableidx1];
    }
    if ((8U & Vtb_trng_top__ConstPool__TABLE_h8ed2dc59_0
         [__Vtableidx1])) {
        vlSelf->tb_trng_top__DOT__dut__DOT__u_vn__DOT__first 
            = Vtb_trng_top__ConstPool__TABLE_h1953ad9d_0
            [__Vtableidx1];
    }
    vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt 
        = __Vdly__tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit 
        = __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt 
        = __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx 
        = __Vdly__tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx;
    vlSelf->tb_trng_top__DOT__dut__DOT__raw_valid = 
        ((0x100U <= (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__warm)) 
         & (0x7cfU == vlSelf->tb_trng_top__DOT__dut__DOT__div));
    vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s1 
        = vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s0;
    vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s0 
        = ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc) 
           ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc) 
              ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc) 
                 ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc) 
                    ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc) 
                       ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc) 
                          ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc) 
                             ^ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc))))))));
}

VL_INLINE_OPT void Vtb_trng_top___024root___nba_sequent__TOP__2(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___nba_sequent__TOP__2\n"); );
    // Body
    if (vlSelf->tb_trng_top__DOT__rst_n) {
        vlSelf->tb_trng_top__DOT__tx_fall_count = ((IData)(1U) 
                                                   + vlSelf->tb_trng_top__DOT__tx_fall_count);
    }
}

VL_INLINE_OPT void Vtb_trng_top___024root___nba_sequent__TOP__3(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr 
        = vlSelf->__Vdly__tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr;
}

void Vtb_trng_top___024root___eval_nba(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vtb_trng_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtb_trng_top___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtb_trng_top___024root___nba_sequent__TOP__2(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vtb_trng_top___024root___nba_sequent__TOP__3(vlSelf);
    }
}

void Vtb_trng_top___024root___eval_triggers__act(Vtb_trng_top___024root* vlSelf);
void Vtb_trng_top___024root___timing_commit(Vtb_trng_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trng_top___024root___dump_triggers__act(Vtb_trng_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_trng_top___024root___timing_resume(Vtb_trng_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trng_top___024root___dump_triggers__nba(Vtb_trng_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_trng_top___024root___eval(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval\n"); );
    // Init
    VlTriggerVec<5> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtb_trng_top___024root___eval_triggers__act(vlSelf);
            Vtb_trng_top___024root___timing_commit(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtb_trng_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 3, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtb_trng_top___024root___timing_resume(vlSelf);
                Vtb_trng_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtb_trng_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/openlane/designs/trng_top/paper_rerun/verification/tb/tb_trng_top_rtl.v", 3, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtb_trng_top___024root___eval_nba(vlSelf);
        }
    }
}

void Vtb_trng_top___024root___timing_commit(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___timing_commit\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.at(0U))))) {
        vlSelf->__VtrigSched_h7a1314a4__0.commit("@(posedge tb_trng_top.clk)");
    }
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.at(4U))))) {
        vlSelf->__VtrigSched_h1db52719__0.commit("@([changed] tb_trng_top.dut.ro_en)");
    }
}

void Vtb_trng_top___024root___timing_resume(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___timing_resume\n"); );
    // Body
    if (vlSelf->__VactTriggered.at(0U)) {
        vlSelf->__VtrigSched_h7a1314a4__0.resume("@(posedge tb_trng_top.clk)");
    }
    if (vlSelf->__VactTriggered.at(3U)) {
        vlSelf->__VdlySched.resume();
    }
    if (vlSelf->__VactTriggered.at(4U)) {
        vlSelf->__VtrigSched_h1db52719__0.resume("@([changed] tb_trng_top.dut.ro_en)");
    }
}

#ifdef VL_DEBUG
void Vtb_trng_top___024root___eval_debug_assertions(Vtb_trng_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
