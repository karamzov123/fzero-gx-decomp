#include "dol/trk_memory.h"

struct gTRKState_t {
    u8 pad_0[0x8C];
    u32 unk_8C;
    u8 pad_90[0x8];
    u32 unk_98;
};

struct lbl_801A5638_t {
    u32 unk_0;
};

extern struct gTRKState_t gTRKState;
extern struct lbl_801A5638_t lbl_801A5638[];
extern u32 gTRKCPUState[];
extern u32 lbl_8015B898[];
extern u8 gTRKInterruptVectorTable[];

extern u32 fn_8008B0E0(void);
extern void fn_8008AFF0(u32, u32);
extern u32 fn_8008D440(void);

void TRKSaveExtended1Block(void);
void InitMetroTRKCommTable(int hwId);
void TRK_main(void);
extern u8 _db_stack_addr[];

/* MetroTRK Os/dolphin/dolphin_trk.c: InitMetroTRK and InitMetroTRK_BBA are CodeWarrior asm
 * functions in the original. They save the caller's register file into gTRKCPUState with
 * stmw, disable external interrupts in the MSR, switch r1 to the debugger stack and enter
 * TRK_main, with no compiler frame. The register file is reloaded with `lmw r0`, an invalid
 * form GNU as rejects but CodeWarrior assembles. */
asm void InitMetroTRK(void) {
    nofralloc
    subi r1, r1, 0x4
    stw r3, 0x0(r1)
    lis r3, gTRKCPUState@h
    ori r3, r3, gTRKCPUState@l
    stmw r0, 0x0(r3)
    lwz r4, 0x0(r1)
    addi r1, r1, 0x4
    stw r1, 0x4(r3)
    stw r4, 0xc(r3)
    mflr r4
    stw r4, 0x84(r3)
    stw r4, 0x80(r3)
    mfcr r4
    stw r4, 0x88(r3)
    mfmsr r4
    ori r3, r4, 0x8000
    xori r3, r3, 0x8000
    mtmsr r3
    mtsrr1 r4
    bl TRKSaveExtended1Block
    lis r3, gTRKCPUState@h
    ori r3, r3, gTRKCPUState@l
    lmw r0, 0x0(r3)
    li r0, 0x0
    mtspr 1010, r0
    mtspr 1013, r0
    lis r1, _db_stack_addr@h
    ori r1, r1, _db_stack_addr@l
    mr r3, r5
    bl InitMetroTRKCommTable
    cmpwi r3, 0x1
    bne L_8008CF40
    lwz r4, 0x84(r3)
    mtlr r4
    lmw r0, 0x0(r3)
    blr
L_8008CF40:
    b TRK_main
    blr
}

__declspec(weak) asm void InitMetroTRK_BBA(void) {
    nofralloc
    subi r1, r1, 0x4
    stw r3, 0x0(r1)
    lis r3, gTRKCPUState@h
    ori r3, r3, gTRKCPUState@l
    stmw r0, 0x0(r3)
    lwz r4, 0x0(r1)
    addi r1, r1, 0x4
    stw r1, 0x4(r3)
    stw r4, 0xc(r3)
    mflr r4
    stw r4, 0x84(r3)
    stw r4, 0x80(r3)
    mfcr r4
    stw r4, 0x88(r3)
    mfmsr r4
    ori r3, r4, 0x8000
    mtmsr r3
    mtsrr1 r4
    bl TRKSaveExtended1Block
    lis r3, gTRKCPUState@h
    ori r3, r3, gTRKCPUState@l
    lmw r0, 0x0(r3)
    li r0, 0x0
    mtspr 1010, r0
    mtspr 1013, r0
    lis r1, _db_stack_addr@h
    ori r1, r1, _db_stack_addr@l
    li r3, 0x2
    bl InitMetroTRKCommTable
    cmpwi r3, 0x1
    bne L_8008CFD4
    lwz r4, 0x84(r3)
    mtlr r4
    lmw r0, 0x0(r3)
    blr
L_8008CFD4:
    b TRK_main
    blr
}

s32 TRKInitializeTarget(void) {
    u32 t0;
    gTRKState.unk_98 = 1;
    t0 = fn_8008B0E0();
    gTRKState.unk_8C = t0;
    lbl_801A5638[0].unk_0 = 0xE0000000;
    return 0;
}

#pragma use_lmw_stmw on
#pragma opt_dead_assignments off
#pragma opt_common_subs off
void fn_8008D028(void) {
    u32 addr;
    u32 *pCPU;
    s32 i;
    u32 mask;
    u32 *tbl;
    u32 v2;
    u32 v0;

    v0 = lbl_801A5638[0].unk_0;
    if (v0 <= 0x44 && (v0 + 0x4000) > 0x44 && (gTRKCPUState[0x238 / 4] & 3) != 0) {
        v2 = 0x44; /* fzgx-allow: A1 low physical word */
    } else {
        v2 = 0x80000044; /* fzgx-allow: A1 cached alias of the low physical word */
    }
    mask = *(u32 *)v2;
    tbl = lbl_8015B898;
    pCPU = gTRKCPUState;
    for (i = 0; i <= 0xe; i++) {
        u32 t0;
        if ((mask & (1 << i)) != 0 && i != 4) {
            t0 = tbl[i];
            if (t0 >= lbl_801A5638[0].unk_0 && t0 < lbl_801A5638[0].unk_0 + 0x4000 &&
                (pCPU[0x238 / 4] & 3) != 0) {
                addr = t0;
            } else if (t0 >= 0x7E000000 && t0 <= 0x80000000) {
                addr = t0;
            } else {
                addr = (t0 & 0x3FFFFFFF) | 0x80000000;
            }
            fn_800035C0((void *)addr, gTRKInterruptVectorTable + t0, 0x100);
            fn_8008AFF0(addr, 0x100);
        }
    }
}
#pragma opt_common_subs reset
#pragma opt_dead_assignments reset
#pragma use_lmw_stmw reset

u32 fn_8008D154(u32 arg0) {
    u32 v0;
    u32 v1;
    v0 = lbl_801A5638[0].unk_0;
    v1 = v0;
    if (arg0 >= v0) {
        if (arg0 < (v1 + 16384)) {
            v1 = (u32)&gTRKCPUState;
            if ((*(u32 *)(v1 + 568) & 0x3) != 0) {
                return arg0;
            }
        }
    }
    if (arg0 >= 0x7E000000) {
        if (arg0 <= 0x80000000) {
            return arg0;
        }
    }
    return ((arg0 & 0x3FFFFFFF) | 0x80000000);
}

void EnableMetroTRKInterrupts(void) {
    fn_8008D440();
}
