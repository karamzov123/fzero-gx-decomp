# DOSSIER — main/dolphin/ai/airegs (AIStartDMA / AIStopDMA)

Status: PLATEAUED at attempt ~22. Best candidate = cand9 (83%/83%): semantically
correct, maintainable C, but MWCC 1.2.5n folds the hardware address into D-form
offsets (`lhz r0, 0x5036(r3)`) while retail materializes the address in two
steps (`lis r3,0xCC00; addi r3,r3,0x5000; lhz r0,0x36(r3)`).

Diff class: literal_layout / instr_select (address materialization).

Shapes tried (all compile clean, all fold): raw volatile pointer (cand1/9),
static const ptr (cand2), helper fn returning ptr (cand3/10/12), array element
(cand4/8/11/15), struct member (cand16/32), char* step (cand23/25), u32 split
const (cand20/31), non-const local index (cand33), file-scope macro on extern
array (cand26 — produces the EXACT instruction multiset but with @ha/@l RELOCS
against a symbol at 0xCC005036 that does not exist and cannot be added by a
conversion worker per T24).

Compiler discriminator run (step 7): GC/1.2.5 83%, GC/1.3 78%, GC/1.3.2 78%,
-O3,p 83%. No version reproduces the two-step materialization from pure-C
constant expressions.

Root cause hypothesis: retail was compiled with the SDK's hw_regs.h-style
absolute-address annotation (`volatile u16 __DSPRegs[] : 0xCC005000;` syntax,
see Melee include/dolphin/hw_regs.h line 8) which MWCC treats as an absolute
symbol -> lis/addi materialization without folding. GFZE01's build has no such
annotation support wired up.

Path forward (integrator): either add absolute symbols for hardware registers
to symbols.txt (then cand26 shape matches exactly), or accept these two
functions as asm bodies permanently. T4 note: because BOTH functions must stay
asm until resolved, they are already last in the TU - no clrlwi fusion risk to
later C functions in this unit (there are none).

Best candidate source: build/natc/airegs/cand9.c (also copied here).
