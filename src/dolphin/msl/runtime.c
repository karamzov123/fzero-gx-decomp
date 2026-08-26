// dest: src/dolphin/msl/runtime.c
#pragma push
#pragma force_active on

extern unsigned char __global_destructor_chain[4];
extern unsigned char lbl_80094E30[16];
asm void memcpy_fast(void)
{
    nofralloc
    srawi.  r0, r5, 4
    mr      r6, r0
    ble     _800795cc
    rlwinm. r0, r0, 0x1e, 2, 0x1f
    mtctr   r0
    beq     _8007959c
_80079508:
    lwz     r0, 0(r4)
    stw     r0, 0(r3)
    lwz     r0, 4(r4)
    stw     r0, 4(r3)
    lwz     r0, 8(r4)
    stw     r0, 8(r3)
    lwz     r0, 0xc(r4)
    stw     r0, 0xc(r3)
    lwz     r0, 0x10(r4)
    stw     r0, 0x10(r3)
    lwz     r0, 0x14(r4)
    stw     r0, 0x14(r3)
    lwz     r0, 0x18(r4)
    stw     r0, 0x18(r3)
    lwz     r0, 0x1c(r4)
    stw     r0, 0x1c(r3)
    lwz     r0, 0x20(r4)
    stw     r0, 0x20(r3)
    lwz     r0, 0x24(r4)
    stw     r0, 0x24(r3)
    lwz     r0, 0x28(r4)
    stw     r0, 0x28(r3)
    lwz     r0, 0x2c(r4)
    stw     r0, 0x2c(r3)
    lwz     r0, 0x30(r4)
    stw     r0, 0x30(r3)
    lwz     r0, 0x34(r4)
    stw     r0, 0x34(r3)
    lwz     r0, 0x38(r4)
    stw     r0, 0x38(r3)
    lwz     r0, 0x3c(r4)
    addi    r4, r4, 0x40
    stw     r0, 0x3c(r3)
    addi    r3, r3, 0x40
    bdnz    _80079508
    andi.   r6, r6, 3
    beq     _800795cc
_8007959c:
    mtctr   r6
_800795a0:
    lwz     r0, 0(r4)
    stw     r0, 0(r3)
    lwz     r0, 4(r4)
    stw     r0, 4(r3)
    lwz     r0, 8(r4)
    stw     r0, 8(r3)
    lwz     r0, 0xc(r4)
    addi    r4, r4, 0x10
    stw     r0, 0xc(r3)
    addi    r3, r3, 0x10
    bdnz    _800795a0
_800795cc:
    clrlwi. r0, r5, 0x1c
    mr      r5, r0
    blelr
    rlwinm. r0, r0, 0x1d, 3, 0x1f
    mtctr   r0
    beq     _80079638
_800795e4:
    lbz     r0, 0(r4)
    stb     r0, 0(r3)
    lbz     r0, 1(r4)
    stb     r0, 1(r3)
    lbz     r0, 2(r4)
    stb     r0, 2(r3)
    lbz     r0, 3(r4)
    stb     r0, 3(r3)
    lbz     r0, 4(r4)
    stb     r0, 4(r3)
    lbz     r0, 5(r4)
    stb     r0, 5(r3)
    lbz     r0, 6(r4)
    stb     r0, 6(r3)
    lbz     r0, 7(r4)
    addi    r4, r4, 8
    stb     r0, 7(r3)
    addi    r3, r3, 8
    bdnz    _800795e4
    andi.   r5, r5, 7
    beqlr
_80079638:
    mtctr   r5
_8007963c:
    lbz     r0, 0(r4)
    addi    r4, r4, 1
    stb     r0, 0(r3)
    addi    r3, r3, 1
    bdnz    _8007963c
    blr
}

typedef struct NatcVaList {
    signed char mG_register;
    signed char mFloat_register;
    unsigned short pad;
    char* mInput_arg_area;
    char* mReg_save_area;
} NatcVaList;

// provenance: mkdd:libs/PowerPC_EABI_Support/src/Runtime/__va_arg.c:4
void* __va_arg(NatcVaList* v_list, int type)
{
    char* addr;
    signed char* reg;
    int g_reg;
    int maxsize;
    int size;
    int increment;
    int even;
    int fpr_offset;
    int regsize;

    g_reg = v_list->mG_register;
    reg = &v_list->mG_register;
    maxsize = 8;
    size = 4;
    increment = 1;
    even = 0;
    fpr_offset = 0;
    regsize = 4;

    if (type == 3) {
        reg = &v_list->mFloat_register;
        g_reg = v_list->mFloat_register;
        size = 8;
        fpr_offset = 32;
        regsize = 8;
    }
    if (type == 2) {
        size = 8;
        maxsize--;
        if (g_reg & 1)
            even = 1;
        increment = 2;
    }
    if (g_reg < maxsize) {
        g_reg += even;
        addr = v_list->mReg_save_area + fpr_offset + (g_reg * regsize);
        *reg = g_reg + increment;
    } else {
        *reg = 8;
        addr = v_list->mInput_arg_area;
        addr = (char*)(((unsigned long)addr + (size - 1)) & ~(size - 1));
        v_list->mInput_arg_area = addr + size;
    }
    if (type == 0)
        addr = *((char**)addr);
    return addr;
}

// provenance: original
// harvested 2026-08-26 from hard's logged 100% attempt; spliced into the current head
typedef struct Dtor {
    struct Dtor* next;
    void (*destructor)(void* obj, int flag);
    void* object;
} Dtor;

void __destroy_global_chain(void) {
    Dtor* p;
    while ((p = *(Dtor* volatile*)&__global_destructor_chain[0]) != 0) {
        *(Dtor* volatile*)&__global_destructor_chain[0] = p->next;
        p->destructor(p->object, -1);
    }
}

asm void __cvt_fp2unsigned(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    lis     r4, lbl_80094E30@h
    ori     r4, r4, lbl_80094E30@l
    li      r3, 0
    lfd     f0, 0(r4)
    lfd     f3, 8(r4)
    lfd     f4, 0x10(r4)
    fcmpu   cr0, f1, f0
    fcmpu   cr6, f1, f3
    blt     _800797b8
    addi    r3, r3, -1
    bge     cr6, _800797b8
    fcmpu   cr7, f1, f4
    fmr     f2, f1
    blt     cr7, _800797a4
    fsub    f2, f1, f4
_800797a4:
    fctiwz  f2, f2
    stfd    f2, 8(r1)
    lwz     r3, 0xc(r1)
    blt     cr7, _800797b8
    addis   r3, r3, -0x8000
_800797b8:
    addi    r1, r1, 0x10
    blr
}

#pragma pop
