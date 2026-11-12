// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_trng_top.h for the primary calling header

#ifndef VERILATED_VTB_TRNG_TOP___024ROOT_H_
#define VERILATED_VTB_TRNG_TOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"

class Vtb_trng_top__Syms;

class Vtb_trng_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_trng_top__DOT__clk;
        CData/*0:0*/ tb_trng_top__DOT__rst_n;
        CData/*0:0*/ tb_trng_top__DOT__tx;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__ro_en;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__warm_done;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__raw_valid;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__dbg_bit_q;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__dbg_val_q;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__rct_fail;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__apt_fail;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__bit_valid;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__bit_out;
        CData/*6:0*/ tb_trng_top__DOT__dut__DOT__byte_reg;
        CData/*2:0*/ tb_trng_top__DOT__dut__DOT__bit_idx;
        CData/*7:0*/ tb_trng_top__DOT__dut__DOT__tx_data;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__tx_pending;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__tx_start;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT____Vlvbound_h36c0d37c__0;
        CData/*1:0*/ tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__sim_osc;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__sim_osc;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__sim_osc;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__sim_osc;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__sim_osc;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__sim_osc;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__sim_osc;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__sim_osc;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s0;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_sampler__DOT__s1;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_rct__DOT__last;
        CData/*7:0*/ tb_trng_top__DOT__dut__DOT__u_rct__DOT__cnt;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_apt__DOT__ref_bit;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_vn__DOT__have;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_vn__DOT__first;
        CData/*0:0*/ tb_trng_top__DOT__dut__DOT__u_uart__DOT__busy;
        CData/*3:0*/ tb_trng_top__DOT__dut__DOT__u_uart__DOT__bit_cnt;
        CData/*7:0*/ tb_trng_top__DOT__dut__DOT__u_uart__DOT__shreg;
        CData/*1:0*/ __Vdly__tb_trng_top__DOT__dut__DOT__u_rst_sync__DOT__sr;
        CData/*0:0*/ __Vtrigrprev__TOP__tb_trng_top__DOT__clk;
        CData/*0:0*/ __Vtrigrprev__TOP__tb_trng_top__DOT__tx;
        CData/*0:0*/ __Vtrigrprev__TOP__tb_trng_top__DOT__rst_n;
        CData/*0:0*/ __Vtrigrprev__TOP__tb_trng_top__DOT__dut__DOT__ro_en;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ tb_trng_top__DOT__dut__DOT__warm;
        SData/*15:0*/ tb_trng_top__DOT__dut__DOT__u_apt__DOT__cnt;
        SData/*15:0*/ tb_trng_top__DOT__dut__DOT__u_apt__DOT__idx;
        SData/*15:0*/ tb_trng_top__DOT__dut__DOT__u_uart__DOT__clk_cnt;
        IData/*31:0*/ tb_trng_top__DOT__raw_sample_count;
        IData/*31:0*/ tb_trng_top__DOT__tx_fall_count;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__div;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__seed;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__0__KET____DOT__u_ro__DOT__delay_ns;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__seed;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__1__KET____DOT__u_ro__DOT__delay_ns;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__seed;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__2__KET____DOT__u_ro__DOT__delay_ns;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__seed;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__3__KET____DOT__u_ro__DOT__delay_ns;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__seed;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__4__KET____DOT__u_ro__DOT__delay_ns;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__seed;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__5__KET____DOT__u_ro__DOT__delay_ns;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__seed;
    };
    struct {
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__6__KET____DOT__u_ro__DOT__delay_ns;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__seed;
        IData/*31:0*/ tb_trng_top__DOT__dut__DOT__u_ro_bank__DOT__g_ro__BRA__7__KET____DOT__u_ro__DOT__delay_ns;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h7a1314a4__0;
    VlTriggerScheduler __VtrigSched_h1db52719__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<5> __VactTriggered;
    VlTriggerVec<5> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_trng_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_trng_top___024root(Vtb_trng_top__Syms* symsp, const char* v__name);
    ~Vtb_trng_top___024root();
    VL_UNCOPYABLE(Vtb_trng_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
