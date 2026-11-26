#include "types.h"

extern void __init_registers(void);
extern void __init_hardware(void);
extern void __init_data(void);
extern void InitMetroTRK(void);
extern void InitMetroTRK_BBA(void);
extern void DBInit(void);
extern void OSInit(void);
extern void __init_user(void);
extern int main(int, char **);
extern void exit(int);
extern char _stack_addr[], _SDA2_BASE_[], _SDA_BASE_[];
extern u8 Debug_BBA;

extern void OSResetSystem(int, u32, int);

__declspec(section ".init") void __check_pad3(void) {
    if ((*(volatile u16 *)0x800030E4 & 0xEEF) == 0xEEF) {  /* fzgx-allow: A1,A2 unnamed OS memory */
        OSResetSystem(0, 0, 0);
    }
}

__declspec(section ".init") void __set_debug_bba(void) {
    Debug_BBA = 1;
}

__declspec(section ".init") u8 __get_debug_bba(void) {
    return Debug_BBA;
}

/* The GX entry point and register setup run before the normal C ABI exists.
 * These are the original frameless SDK assembly routines, transcribed from
 * the matched GX assembly. See config/original_assembly.json. */

__declspec(weak) __declspec(section ".init") asm void __start(void) {
    nofralloc
    bl __init_registers
    bl __init_hardware
    li r0, -0x1
    stwu r1, -0x8(r1)
    stw r0, 0x4(r1)
    stw r0, 0x0(r1)
    bl __init_data
    li r0, 0x0
    lis r6, 0x8000
    addi r6, r6, 0x44
    stw r0, 0x0(r6)
    lis r6, 0x8000
    addi r6, r6, 0xf4
    lwz r6, 0x0(r6)
    cmplwi r6, 0x0
    beq L_8000319C
    lwz r7, 0xc(r6)
    b L_800031BC
L_8000319C:
    lis r5, 0x8000
    addi r5, r5, 0x34
    lwz r5, 0x0(r5)
    cmplwi r5, 0x0
    beq L_800031F8
    lis r7, 0x8000
    addi r7, r7, 0x30e8
    lwz r7, 0x0(r7)
L_800031BC:
    li r5, 0x0
    cmplwi r7, 0x2
    beq L_800031E8
    cmplwi r7, 0x3
    li r5, 0x1
    beq L_800031E8
    cmplwi r7, 0x4
    bne L_800031F8
    li r5, 0x2
    bl __set_debug_bba
    b L_800031F8
L_800031E8:
    lis r6, InitMetroTRK@ha
    addi r6, r6, InitMetroTRK@l
    mtlr r6
    blrl
L_800031F8:
    lis r6, 0x8000
    addi r6, r6, 0xf4
    lwz r5, 0x0(r6)
    cmplwi r5, 0x0
    beq+ L_80003258
    lwz r6, 0x8(r5)
    cmplwi r6, 0x0
    beq+ L_80003258
    add r6, r5, r6
    lwz r14, 0x0(r6)
    cmplwi r14, 0x0
    beq L_80003258
    addi r15, r6, 0x4
    mtctr r14
L_80003230:
    addi r6, r6, 0x4
    lwz r7, 0x0(r6)
    add r7, r7, r5
    stw r7, 0x0(r6)
    bdnz L_80003230
    lis r5, 0x8000
    addi r5, r5, 0x34
    clrrwi r7, r15, 5
    stw r7, 0x0(r5)
    b L_80003260
L_80003258:
    li r14, 0x0
    li r15, 0x0
L_80003260:
    bl DBInit
    bl OSInit
    lis r4, 0x8000
    addi r4, r4, 0x30e6
    lhz r3, 0x0(r4)
    andi. r5, r3, 0x8000
    beq L_80003288
    andi. r3, r3, 0x7fff
    cmplwi r3, 0x1
    bne L_8000328C
L_80003288:
    bl __check_pad3
L_8000328C:
    bl __get_debug_bba
    cmplwi r3, 0x1
    bne L_8000329C
    bl InitMetroTRK_BBA
L_8000329C:
    bl __init_user
    mr r3, r14
    mr r4, r15
    bl main
    b exit
}

__declspec(section ".init") asm void __init_registers(void) {
    nofralloc
    li r0, 0x0
    li r3, 0x0
    li r4, 0x0
    li r5, 0x0
    li r6, 0x0
    li r7, 0x0
    li r8, 0x0
    li r9, 0x0
    li r10, 0x0
    li r11, 0x0
    li r12, 0x0
    li r14, 0x0
    li r15, 0x0
    li r16, 0x0
    li r17, 0x0
    li r18, 0x0
    li r19, 0x0
    li r20, 0x0
    li r21, 0x0
    li r22, 0x0
    li r23, 0x0
    li r24, 0x0
    li r25, 0x0
    li r26, 0x0
    li r27, 0x0
    li r28, 0x0
    li r29, 0x0
    li r30, 0x0
    li r31, 0x0
    lis r1, _stack_addr@h
    ori r1, r1, _stack_addr@l
    lis r2, _SDA2_BASE_@h
    ori r2, r2, _SDA2_BASE_@l
    lis r13, _SDA_BASE_@h
    ori r13, r13, _SDA_BASE_@l
    blr
}

typedef struct {
    void *src;  /* 0x0 */
    void *dst;  /* 0x4 */
    u32 size;   /* 0x8 */
} RomCopyInfo;

typedef struct {
    void *addr; /* 0x0 */
    u32 size;   /* 0x4 */
} BssInitInfo;

extern RomCopyInfo _rom_copy_info[];
extern BssInitInfo _bss_init_info[];
extern void *memcpy(void *, const void *, u32);
extern void *memset(void *, int, u32);
extern void __flush_cache(void *, u32);

#pragma peephole off
__declspec(section ".init") void __init_data(void) {
    void *src;
    void *dst;
    void *addr;
    u32 size;
    RomCopyInfo *p;
    BssInitInfo *q;

    for (p = _rom_copy_info; ; p++) {
        if ((size = p->size) == 0) {
            break;
        }
        src = p->src;
        dst = p->dst;
        if (size != 0 && dst != src) {
            memcpy(dst, src, size);
            __flush_cache(dst, size);
        }
    }

    for (q = _bss_init_info; ; q++) {
        if ((size = q->size) == 0) {
            break;
        }
        addr = q->addr;
        if (size != 0) {
            memset(addr, 0, size);
        }
    }
}
#pragma peephole reset
