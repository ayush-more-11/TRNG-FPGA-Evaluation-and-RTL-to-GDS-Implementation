// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_trng_top__Syms.h"


void Vtb_trng_top___024root__trace_chg_sub_0(Vtb_trng_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_trng_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root__trace_chg_top_0\n"); );
    // Init
    Vtb_trng_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_trng_top___024root*>(voidSelf);
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_trng_top___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_trng_top___024root__trace_chg_sub_0(Vtb_trng_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->tb_trng_top__DOT__tx));
        bufp->chgBit(oldp+1,(((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__apt_fail) 
                              | (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__rct_fail))));
        bufp->chgBit(oldp+2,(vlSelf->tb_trng_top__DOT__dut__DOT__dbg_bit_q));
        bufp->chgBit(oldp+3,(vlSelf->tb_trng_top__DOT__dut__DOT__dbg_val_q));
        bufp->chgIData(oldp+4,(vlSelf->tb_trng_top__DOT__raw_sample_count),32);
        bufp->chgBit(oldp+5,(vlSelf->tb_trng_top__DOT__dut__DOT__ro_en));
        bufp->chgBit(oldp+6,(vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s1));
        bufp->chgIData(oldp+7,(vlSelf->tb_trng_top__DOT__dut__DOT__div),32);
        bufp->chgSData(oldp+8,(vlSelf->tb_trng_top__DOT__dut__DOT__warm),16);
        bufp->chgBit(oldp+9,((0x100U <= (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__warm))));
        bufp->chgBit(oldp+10,(vlSelf->tb_trng_top__DOT__dut__DOT__raw_valid));
        bufp->chgBit(oldp+11,(vlSelf->tb_trng_top__DOT__dut__DOT__rct_fail));
        bufp->chgBit(oldp+12,(vlSelf->tb_trng_top__DOT__dut__DOT__apt_fail));
        bufp->chgBit(oldp+13,(vlSelf->tb_trng_top__DOT__dut__DOT__bit_valid));
        bufp->chgBit(oldp+14,(vlSelf->tb_trng_top__DOT__dut__DOT__bit_out));
        bufp->chgCData(oldp+15,(vlSelf->tb_trng_top__DOT__dut__DOT__byte_reg),7);
        bufp->chgCData(oldp+16,(vlSelf->tb_trng_top__DOT__dut__DOT__bit_idx),3);
        bufp->chgCData(oldp+17,(vlSelf->tb_trng_top__DOT__dut__DOT__tx_data),8);
        bufp->chgBit(oldp+18,(vlSelf->tb_trng_top__DOT__dut__DOT__tx_pending));
        bufp->chgBit(oldp+19,((1U & (~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__busy)))));
        bufp->chgBit(oldp+20,(vlSelf->tb_trng_top__DOT__dut__DOT__tx_start));
        bufp->chgBit(oldp+21,(vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit));
        bufp->chgSData(oldp+22,(vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt),16);
        bufp->chgSData(oldp+23,(vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx),16);
        bufp->chgBit(oldp+24,(vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__last));
        bufp->chgCData(oldp+25,(vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt),8);
        bufp->chgBit(oldp+26,(vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s0));
        bufp->chgBit(oldp+27,(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__busy));
        bufp->chgSData(oldp+28,(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt),16);
        bufp->chgCData(oldp+29,(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt),4);
        bufp->chgCData(oldp+30,(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__shreg),8);
        bufp->chgBit(oldp+31,(vlSelf->tb_trng_top__DOT__dut__DOT__u_vn__DOT__have));
        bufp->chgBit(oldp+32,(vlSelf->tb_trng_top__DOT__dut__DOT__u_vn__DOT__first));
    }
    bufp->chgBit(oldp+33,(vlSelf->tb_trng_top__DOT__clk));
    bufp->chgBit(oldp+34,(vlSelf->tb_trng_top__DOT__rst_n));
    bufp->chgIData(oldp+35,(vlSelf->tb_trng_top__DOT__tx_fall_count),32);
    bufp->chgBit(oldp+36,((1U & ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr) 
                                 >> 1U))));
    bufp->chgBit(oldp+37,(((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc) 
                           ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc) 
                              ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc) 
                                 ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc) 
                                    ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc) 
                                       ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc) 
                                          ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc) 
                                             ^ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc))))))))));
    bufp->chgCData(oldp+38,((((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc) 
                              << 7U) | (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc) 
                                         << 6U) | (
                                                   ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc) 
                                                    << 5U) 
                                                   | (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc) 
                                                       << 4U) 
                                                      | (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc) 
                                                          << 3U) 
                                                         | (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc) 
                                                             << 2U) 
                                                            | (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc) 
                                                                << 1U) 
                                                               | (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc))))))))),8);
    bufp->chgBit(oldp+39,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc));
    bufp->chgIData(oldp+40,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__seed),32);
    bufp->chgIData(oldp+41,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->chgBit(oldp+42,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc));
    bufp->chgIData(oldp+43,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__seed),32);
    bufp->chgIData(oldp+44,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->chgBit(oldp+45,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc));
    bufp->chgIData(oldp+46,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__seed),32);
    bufp->chgIData(oldp+47,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->chgBit(oldp+48,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc));
    bufp->chgIData(oldp+49,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__seed),32);
    bufp->chgIData(oldp+50,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->chgBit(oldp+51,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc));
    bufp->chgIData(oldp+52,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__seed),32);
    bufp->chgIData(oldp+53,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->chgBit(oldp+54,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc));
    bufp->chgIData(oldp+55,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__seed),32);
    bufp->chgIData(oldp+56,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->chgBit(oldp+57,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc));
    bufp->chgIData(oldp+58,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__seed),32);
    bufp->chgIData(oldp+59,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->chgBit(oldp+60,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc));
    bufp->chgIData(oldp+61,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__seed),32);
    bufp->chgIData(oldp+62,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->chgCData(oldp+63,(vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr),2);
}

void Vtb_trng_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root__trace_cleanup\n"); );
    // Init
    Vtb_trng_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_trng_top___024root*>(voidSelf);
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
