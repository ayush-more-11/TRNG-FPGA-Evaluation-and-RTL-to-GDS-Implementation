// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_TRNG_TOP__SYMS_H_
#define VERILATED_VTB_TRNG_TOP__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "Vtb_trng_top.h"

// INCLUDE MODULE CLASSES
#include "Vtb_trng_top___024root.h"

// SYMS CLASS (contains all model state)
class Vtb_trng_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_trng_top* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_trng_top___024root         TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_tb_trng_top;

    // CONSTRUCTORS
    Vtb_trng_top__Syms(VerilatedContext* contextp, const char* namep, Vtb_trng_top* modelp);
    ~Vtb_trng_top__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
