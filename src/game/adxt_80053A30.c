#pragma push
#pragma force_active on

extern void fn_80051F38();
extern void* memset(void*, int, unsigned int);
extern unsigned char adxt_sincos_table[8320];
extern unsigned char jumptable_80130BC0[64];
extern unsigned char lbl_801319E0[2176];
extern unsigned char lbl_80187370[16];
extern unsigned char lbl_80187380[64];
extern unsigned char lbl_801873C0[24];

extern const float lbl_80091350[];

typedef struct AdxtGlobal {
    int ref_count;
    int initialized;
    float* table1;
    void* table2;
} AdxtGlobal;

#pragma dont_inline on
// provenance: original
int adxtNullCallback(void)
{
    return 0;
}
#pragma dont_inline reset

// provenance: original
void fn_80053A38(void* p)
{
    int idx = *(signed char*)((char*)p + 1);
    memset(p, 0, 0x2014);
    ((int*)lbl_80187380)[idx] = 0;
}

asm void fn_80053A84(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r5, lbl_80187370@ha
    stw	r0, 0x24(r1)
    li	r0, 2
    stw	r31, 0x1c(r1)
    addi	r31, r5, lbl_80187370@l
    stw	r30, 0x18(r1)
    li	r30, 0
    stw	r29, 0x14(r1)
    mr	r29, r3
    addi	r3, r31, 0x10
    mtctr	r0
_80053ab8:
    lwz	r0, 0(r3)
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    addi	r3, r3, 4
    addi	r30, r30, 1
    bdnz    _80053ab8
_80053b40:
    cmpwi	r30, 0x10
    bne     _80053b50
    li	r3, 0
    b       _80053b98
_80053b50:
    mr	r3, r29
    mr	r5, r4
    li	r4, 0
    bl      memset
    slwi	r3, r30, 2
    addi	r5, r31, 0x10
    stwx	r29, r5, r3
    li	r4, 0x40
    li	r0, 1
    lwzx	r3, r5, r3
    stb	r30, 1(r3)
    stw	r4, 8(r3)
    stw	r4, 4(r3)
    lwz	r4, 8(r31)
    stw	r4, 0x10(r3)
    lwz	r4, 0xc(r31)
    stw	r4, 0xc(r3)
    stb	r0, 0(r3)
_80053b98:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

// provenance: original
void fn_80053BB4(void)
{
    if (--(*(int*)lbl_80187370) == 0) {
        memset(lbl_80187380, 0, 0x40);
    }
}

// provenance: original
void fn_80053BFC(void)
{
    AdxtGlobal* g = (AdxtGlobal*)lbl_80187370;

    if (g->ref_count == 0) {
        memset((char*)g + 0x10, 0, 0x40);
        if (g->initialized == 0) {
            char* src1 = (char*)lbl_801319E0 + 0x800;
            char* dst1;
            long n;
            char* src2;
            char* dst2;

            g->table1 = (float*)(((unsigned int)lbl_801319E0 + 0x1F) & ~0x1F);
            dst1 = (char*)g->table1 + 0x800;

            for (n = 0x2AB; n > 0; n--) {
                *dst1 = *src1;
                *(dst1 - 1) = *(src1 - 1);
                *(dst1 - 2) = *(src1 - 2);
                src1 -= 3;
                dst1 -= 3;
            }

            for (n = 0; n < 0x200; n++) {
                g->table1[n] *= lbl_80091350[0];
            }

            src2 = (char*)adxt_sincos_table + 0x2000;
            g->table2 = (void*)(((unsigned int)adxt_sincos_table + 0x1F) & ~0x1F);
            dst2 = (char*)g->table2 + 0x2000;

            for (n = 0xAAB; n > 0; n--) {
                *dst2 = *src2;
                *(dst2 - 1) = *(src2 - 1);
                *(dst2 - 2) = *(src2 - 2);
                src2 -= 3;
                dst2 -= 3;
            }

            g->initialized = 1;
        }
    }
    g->ref_count++;
}

// provenance: original
void fn_80053DB4(void* obj, void* arg1, int ch, void* arg3)
{
    int* p = (int*)((char*)obj + (ch << 2));
    char* buf_ch = (char*)obj + (ch << 12);
    int r0;
    void* r28;
    void* r26;

    p[1] = (p[1] - 0x40) & 0x3FF;
    r0 = p[1];
    r28 = *(void**)((char*)obj + 0xC);
    r26 = (char*)buf_ch + 0x14 + (r0 << 2);

    *(int*)lbl_801873C0 = adxtNullCallback();

    if (((unsigned int)arg1 & 0x1F) != 0 || ((unsigned int)r28 & 0x1F) != 0) {
        while (1) {
        }
    }

    fn_80051F38(arg1, r28, r26);
    *(int*)(lbl_801873C0 + 0x10) = adxtNullCallback();

    p = (int*)p[1];
    *(int*)lbl_801873C0 = adxtNullCallback();
    ((void (**)(void*, void*, void*))jumptable_80130BC0)[(int)p >> 6](
        (char*)(buf_ch + 0x14) + ((int)p << 2), *(void**)((char*)obj + 0x10), arg3);
    *(int*)(lbl_801873C0 + 0x10) = adxtNullCallback();
}

#pragma pop
