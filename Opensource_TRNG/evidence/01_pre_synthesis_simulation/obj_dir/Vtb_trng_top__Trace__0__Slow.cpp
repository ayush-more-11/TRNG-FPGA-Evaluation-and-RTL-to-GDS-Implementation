// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_trng_top__Syms.h"


VL_ATTR_COLD void Vtb_trng_top___024root__trace_init_sub__TOP__0(Vtb_trng_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushNamePrefix("tb_trng_top ");
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+35,"rst_n", false,-1);
    tracep->declBit(c+1,"tx", false,-1);
    tracep->declBit(c+2,"health_fail", false,-1);
    tracep->declBit(c+3,"dbg_raw_bit", false,-1);
    tracep->declBit(c+4,"dbg_raw_valid", false,-1);
    tracep->declBus(c+5,"raw_sample_count", false,-1, 31,0);
    tracep->declBus(c+36,"tx_fall_count", false,-1, 31,0);
    tracep->pushNamePrefix("dut ");
    tracep->declBus(c+65,"NUM_RO", false,-1, 31,0);
    tracep->declBus(c+66,"SAMP_DIV", false,-1, 31,0);
    tracep->declBus(c+67,"CLK_HZ", false,-1, 31,0);
    tracep->declBus(c+68,"BAUD", false,-1, 31,0);
    tracep->declBus(c+69,"WARMUP_CYCLES", false,-1, 31,0);
    tracep->declBus(c+70,"RCT_C", false,-1, 31,0);
    tracep->declBus(c+71,"APT_W", false,-1, 31,0);
    tracep->declBus(c+72,"APT_C", false,-1, 31,0);
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+35,"rst_n", false,-1);
    tracep->declBit(c+1,"tx", false,-1);
    tracep->declBit(c+2,"health_fail", false,-1);
    tracep->declBit(c+3,"dbg_raw_bit", false,-1);
    tracep->declBit(c+4,"dbg_raw_valid", false,-1);
    tracep->declBus(c+73,"BAUD_DIV", false,-1, 31,0);
    tracep->declBit(c+37,"rst_ns", false,-1);
    tracep->declBit(c+6,"ro_en", false,-1);
    tracep->declBit(c+38,"x", false,-1);
    tracep->declBit(c+7,"s", false,-1);
    tracep->declBus(c+8,"div", false,-1, 31,0);
    tracep->declBus(c+9,"warm", false,-1, 15,0);
    tracep->declBit(c+10,"warm_done", false,-1);
    tracep->declBit(c+11,"raw_valid", false,-1);
    tracep->declBit(c+7,"raw_bit", false,-1);
    tracep->declBit(c+3,"dbg_bit_q", false,-1);
    tracep->declBit(c+4,"dbg_val_q", false,-1);
    tracep->declBit(c+12,"rct_fail", false,-1);
    tracep->declBit(c+13,"apt_fail", false,-1);
    tracep->declBit(c+14,"bit_valid", false,-1);
    tracep->declBit(c+15,"bit_out", false,-1);
    tracep->declBus(c+16,"byte_reg", false,-1, 6,0);
    tracep->declBus(c+17,"bit_idx", false,-1, 2,0);
    tracep->declBus(c+18,"tx_data", false,-1, 7,0);
    tracep->declBit(c+19,"tx_pending", false,-1);
    tracep->declBit(c+20,"tx_ready", false,-1);
    tracep->declBit(c+21,"tx_start", false,-1);
    tracep->pushNamePrefix("u_apt ");
    tracep->declBus(c+71,"W", false,-1, 31,0);
    tracep->declBus(c+72,"C", false,-1, 31,0);
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+37,"rst_n", false,-1);
    tracep->declBit(c+11,"v", false,-1);
    tracep->declBit(c+7,"b", false,-1);
    tracep->declBit(c+13,"fail", false,-1);
    tracep->declBit(c+22,"ref_bit", false,-1);
    tracep->declBus(c+23,"cnt", false,-1, 15,0);
    tracep->declBus(c+24,"idx", false,-1, 15,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_rct ");
    tracep->declBus(c+70,"C", false,-1, 31,0);
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+37,"rst_n", false,-1);
    tracep->declBit(c+11,"v", false,-1);
    tracep->declBit(c+7,"b", false,-1);
    tracep->declBit(c+12,"fail", false,-1);
    tracep->declBit(c+25,"last", false,-1);
    tracep->declBus(c+26,"cnt", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_ro_bank ");
    tracep->declBus(c+65,"NUM_RO", false,-1, 31,0);
    tracep->declBit(c+6,"en", false,-1);
    tracep->declBit(c+38,"x", false,-1);
    tracep->declBus(c+39,"ro_y", false,-1, 7,0);
    tracep->pushNamePrefix("g_ro[0] ");
    tracep->pushNamePrefix("u_ro ");
    tracep->declBus(c+74,"N", false,-1, 31,0);
    tracep->declBus(c+75,"ID", false,-1, 31,0);
    tracep->declBit(c+6,"en", false,-1);
    tracep->declBit(c+40,"y", false,-1);
    tracep->declBit(c+40,"sim_osc", false,-1);
    tracep->declBus(c+41,"seed", false,-1, 31,0);
    tracep->declBus(c+42,"delay_ns", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("g_ro[1] ");
    tracep->pushNamePrefix("u_ro ");
    tracep->declBus(c+76,"N", false,-1, 31,0);
    tracep->declBus(c+77,"ID", false,-1, 31,0);
    tracep->declBit(c+6,"en", false,-1);
    tracep->declBit(c+43,"y", false,-1);
    tracep->declBit(c+43,"sim_osc", false,-1);
    tracep->declBus(c+44,"seed", false,-1, 31,0);
    tracep->declBus(c+45,"delay_ns", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("g_ro[2] ");
    tracep->pushNamePrefix("u_ro ");
    tracep->declBus(c+78,"N", false,-1, 31,0);
    tracep->declBus(c+79,"ID", false,-1, 31,0);
    tracep->declBit(c+6,"en", false,-1);
    tracep->declBit(c+46,"y", false,-1);
    tracep->declBit(c+46,"sim_osc", false,-1);
    tracep->declBus(c+47,"seed", false,-1, 31,0);
    tracep->declBus(c+48,"delay_ns", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("g_ro[3] ");
    tracep->pushNamePrefix("u_ro ");
    tracep->declBus(c+80,"N", false,-1, 31,0);
    tracep->declBus(c+74,"ID", false,-1, 31,0);
    tracep->declBit(c+6,"en", false,-1);
    tracep->declBit(c+49,"y", false,-1);
    tracep->declBit(c+49,"sim_osc", false,-1);
    tracep->declBus(c+50,"seed", false,-1, 31,0);
    tracep->declBus(c+51,"delay_ns", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("g_ro[4] ");
    tracep->pushNamePrefix("u_ro ");
    tracep->declBus(c+81,"N", false,-1, 31,0);
    tracep->declBus(c+82,"ID", false,-1, 31,0);
    tracep->declBit(c+6,"en", false,-1);
    tracep->declBit(c+52,"y", false,-1);
    tracep->declBit(c+52,"sim_osc", false,-1);
    tracep->declBus(c+53,"seed", false,-1, 31,0);
    tracep->declBus(c+54,"delay_ns", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("g_ro[5] ");
    tracep->pushNamePrefix("u_ro ");
    tracep->declBus(c+83,"N", false,-1, 31,0);
    tracep->declBus(c+76,"ID", false,-1, 31,0);
    tracep->declBit(c+6,"en", false,-1);
    tracep->declBit(c+55,"y", false,-1);
    tracep->declBit(c+55,"sim_osc", false,-1);
    tracep->declBus(c+56,"seed", false,-1, 31,0);
    tracep->declBus(c+57,"delay_ns", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("g_ro[6] ");
    tracep->pushNamePrefix("u_ro ");
    tracep->declBus(c+84,"N", false,-1, 31,0);
    tracep->declBus(c+85,"ID", false,-1, 31,0);
    tracep->declBit(c+6,"en", false,-1);
    tracep->declBit(c+58,"y", false,-1);
    tracep->declBit(c+58,"sim_osc", false,-1);
    tracep->declBus(c+59,"seed", false,-1, 31,0);
    tracep->declBus(c+60,"delay_ns", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("g_ro[7] ");
    tracep->pushNamePrefix("u_ro ");
    tracep->declBus(c+86,"N", false,-1, 31,0);
    tracep->declBus(c+78,"ID", false,-1, 31,0);
    tracep->declBit(c+6,"en", false,-1);
    tracep->declBit(c+61,"y", false,-1);
    tracep->declBit(c+61,"sim_osc", false,-1);
    tracep->declBus(c+62,"seed", false,-1, 31,0);
    tracep->declBus(c+63,"delay_ns", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("u_rst_sync ");
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+35,"rst_n_in", false,-1);
    tracep->declBit(c+37,"rst_n_out", false,-1);
    tracep->declBus(c+64,"sr", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_sampler ");
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+38,"x", false,-1);
    tracep->declBit(c+7,"q", false,-1);
    tracep->declBit(c+27,"s0", false,-1);
    tracep->declBit(c+7,"s1", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_uart ");
    tracep->declBus(c+73,"BAUD_DIV", false,-1, 31,0);
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+37,"rst_n", false,-1);
    tracep->declBit(c+21,"tx_en", false,-1);
    tracep->declBus(c+18,"tx_data", false,-1, 7,0);
    tracep->declBit(c+1,"tx", false,-1);
    tracep->declBit(c+20,"tx_ready", false,-1);
    tracep->declBit(c+28,"busy", false,-1);
    tracep->declBus(c+29,"clk_cnt", false,-1, 15,0);
    tracep->declBus(c+30,"bit_cnt", false,-1, 3,0);
    tracep->declBus(c+31,"shreg", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_vn ");
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+37,"rst_n", false,-1);
    tracep->declBit(c+11,"v", false,-1);
    tracep->declBit(c+7,"d", false,-1);
    tracep->declBit(c+14,"ov", false,-1);
    tracep->declBit(c+15,"o", false,-1);
    tracep->declBit(c+32,"have", false,-1);
    tracep->declBit(c+33,"first", false,-1);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vtb_trng_top___024root__trace_init_top(Vtb_trng_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root__trace_init_top\n"); );
    // Body
    Vtb_trng_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_trng_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_trng_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_trng_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_trng_top___024root__trace_register(Vtb_trng_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtb_trng_top___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtb_trng_top___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtb_trng_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_trng_top___024root__trace_full_sub_0(Vtb_trng_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_trng_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root__trace_full_top_0\n"); );
    // Init
    Vtb_trng_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_trng_top___024root*>(voidSelf);
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_trng_top___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_trng_top___024root__trace_full_sub_0(Vtb_trng_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trng_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trng_top___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->tb_trng_top__DOT__tx));
    bufp->fullBit(oldp+2,(((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__apt_fail) 
                           | (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__rct_fail))));
    bufp->fullBit(oldp+3,(vlSelf->tb_trng_top__DOT__dut__DOT__dbg_bit_q));
    bufp->fullBit(oldp+4,(vlSelf->tb_trng_top__DOT__dut__DOT__dbg_val_q));
    bufp->fullIData(oldp+5,(vlSelf->tb_trng_top__DOT__raw_sample_count),32);
    bufp->fullBit(oldp+6,(vlSelf->tb_trng_top__DOT__dut__DOT__ro_en));
    bufp->fullBit(oldp+7,(vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s1));
    bufp->fullIData(oldp+8,(vlSelf->tb_trng_top__DOT__dut__DOT__div),32);
    bufp->fullSData(oldp+9,(vlSelf->tb_trng_top__DOT__dut__DOT__warm),16);
    bufp->fullBit(oldp+10,((0x100U <= (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__warm))));
    bufp->fullBit(oldp+11,(vlSelf->tb_trng_top__DOT__dut__DOT__raw_valid));
    bufp->fullBit(oldp+12,(vlSelf->tb_trng_top__DOT__dut__DOT__rct_fail));
    bufp->fullBit(oldp+13,(vlSelf->tb_trng_top__DOT__dut__DOT__apt_fail));
    bufp->fullBit(oldp+14,(vlSelf->tb_trng_top__DOT__dut__DOT__bit_valid));
    bufp->fullBit(oldp+15,(vlSelf->tb_trng_top__DOT__dut__DOT__bit_out));
    bufp->fullCData(oldp+16,(vlSelf->tb_trng_top__DOT__dut__DOT__byte_reg),7);
    bufp->fullCData(oldp+17,(vlSelf->tb_trng_top__DOT__dut__DOT__bit_idx),3);
    bufp->fullCData(oldp+18,(vlSelf->tb_trng_top__DOT__dut__DOT__tx_data),8);
    bufp->fullBit(oldp+19,(vlSelf->tb_trng_top__DOT__dut__DOT__tx_pending));
    bufp->fullBit(oldp+20,((1U & (~ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__busy)))));
    bufp->fullBit(oldp+21,(vlSelf->tb_trng_top__DOT__dut__DOT__tx_start));
    bufp->fullBit(oldp+22,(vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit));
    bufp->fullSData(oldp+23,(vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt),16);
    bufp->fullSData(oldp+24,(vlSelf->tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx),16);
    bufp->fullBit(oldp+25,(vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__last));
    bufp->fullCData(oldp+26,(vlSelf->tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt),8);
    bufp->fullBit(oldp+27,(vlSelf->tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s0));
    bufp->fullBit(oldp+28,(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__busy));
    bufp->fullSData(oldp+29,(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt),16);
    bufp->fullCData(oldp+30,(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt),4);
    bufp->fullCData(oldp+31,(vlSelf->tb_trng_top__DOT__dut__DOT__u_uart__DOT__shreg),8);
    bufp->fullBit(oldp+32,(vlSelf->tb_trng_top__DOT__dut__DOT__u_vn__DOT__have));
    bufp->fullBit(oldp+33,(vlSelf->tb_trng_top__DOT__dut__DOT__u_vn__DOT__first));
    bufp->fullBit(oldp+34,(vlSelf->tb_trng_top__DOT__clk));
    bufp->fullBit(oldp+35,(vlSelf->tb_trng_top__DOT__rst_n));
    bufp->fullIData(oldp+36,(vlSelf->tb_trng_top__DOT__tx_fall_count),32);
    bufp->fullBit(oldp+37,((1U & ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr) 
                                  >> 1U))));
    bufp->fullBit(oldp+38,(((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc) 
                            ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc) 
                               ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc) 
                                  ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc) 
                                     ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc) 
                                        ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc) 
                                           ^ ((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc) 
                                              ^ (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc))))))))));
    bufp->fullCData(oldp+39,((((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc) 
                               << 7U) | (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc) 
                                          << 6U) | 
                                         (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc) 
                                           << 5U) | 
                                          (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc) 
                                            << 4U) 
                                           | (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc) 
                                               << 3U) 
                                              | (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc))))))))),8);
    bufp->fullBit(oldp+40,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc));
    bufp->fullIData(oldp+41,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__seed),32);
    bufp->fullIData(oldp+42,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->fullBit(oldp+43,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc));
    bufp->fullIData(oldp+44,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__seed),32);
    bufp->fullIData(oldp+45,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->fullBit(oldp+46,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc));
    bufp->fullIData(oldp+47,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__seed),32);
    bufp->fullIData(oldp+48,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->fullBit(oldp+49,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc));
    bufp->fullIData(oldp+50,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__seed),32);
    bufp->fullIData(oldp+51,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->fullBit(oldp+52,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc));
    bufp->fullIData(oldp+53,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__seed),32);
    bufp->fullIData(oldp+54,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->fullBit(oldp+55,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc));
    bufp->fullIData(oldp+56,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__seed),32);
    bufp->fullIData(oldp+57,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->fullBit(oldp+58,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc));
    bufp->fullIData(oldp+59,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__seed),32);
    bufp->fullIData(oldp+60,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->fullBit(oldp+61,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc));
    bufp->fullIData(oldp+62,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__seed),32);
    bufp->fullIData(oldp+63,(vlSelf->tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__delay_ns),32);
    bufp->fullCData(oldp+64,(vlSelf->tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr),2);
    bufp->fullIData(oldp+65,(8U),32);
    bufp->fullIData(oldp+66,(0x7d0U),32);
    bufp->fullIData(oldp+67,(0x5f5e100U),32);
    bufp->fullIData(oldp+68,(0x1c200U),32);
    bufp->fullIData(oldp+69,(0x100U),32);
    bufp->fullIData(oldp+70,(0x29U),32);
    bufp->fullIData(oldp+71,(0x400U),32);
    bufp->fullIData(oldp+72,(0x319U),32);
    bufp->fullIData(oldp+73,(0x364U),32);
    bufp->fullIData(oldp+74,(3U),32);
    bufp->fullIData(oldp+75,(0U),32);
    bufp->fullIData(oldp+76,(5U),32);
    bufp->fullIData(oldp+77,(1U),32);
    bufp->fullIData(oldp+78,(7U),32);
    bufp->fullIData(oldp+79,(2U),32);
    bufp->fullIData(oldp+80,(9U),32);
    bufp->fullIData(oldp+81,(0xbU),32);
    bufp->fullIData(oldp+82,(4U),32);
    bufp->fullIData(oldp+83,(0xdU),32);
    bufp->fullIData(oldp+84,(0xfU),32);
    bufp->fullIData(oldp+85,(6U),32);
    bufp->fullIData(oldp+86,(0x11U),32);
}
