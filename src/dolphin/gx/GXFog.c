typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GXSetDrawSync(register u16 token);
extern void GXSetDrawSyncCallback(register void* callback);
extern void __GXGetTexBufferSize(register void* p1, register void* p2, register int id, register void* p4);
extern int fn_80039AFC(void);
extern int fn_80039B38(register u32 a);
extern void fn_80039B7C(register u32 a);
extern int fn_80039C40(register u32 a, register u32 b);
extern int fn_80039E48(register u32 a);
extern void GXCallDisplayList(register void* p);
extern int fn_8003A3D4(register u32 a);
extern int fn_8003AB08(register u32 a);
extern int fn_8003B010(register u32 a);
extern int fn_8003B9AC(register u32 a);
extern void memset(void*, int, unsigned long);
extern void DCStoreRange(register void* addr, register unsigned long n);
extern void OSReport(const char* fmt, ...);
extern void OSRegisterVersion(const char* version);
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern void PPCMtmmcr0(register u32 v);
extern void PPCMtmmcr1(register u32 v);
extern void PPCMfpmc1(register u32 v);
extern void PPCMtpmc1(register u32 v);
extern void PPCMfpmc2(register u32 v);
extern void PPCMtpmc2(register u32 v);
extern void PPCMfpmc3(register u32 v);
extern void PPCMtpmc3(register u32 v);
extern void PPCMfpmc4(register u32 v);
extern void PPCMtpmc4(register u32 v);
asm void fn_8003BB30(register u32 a);
asm int fn_8003BCE4(register u32 a);
asm int fn_8003BD78(register u32 a);
asm int fn_8003D4E0(register u32 a);
asm int PerfmonCopyConfig(register u32 a);
asm int fn_8003E13C(register u32 a);
asm int fn_8003E284(register u32 a);
extern void fn_8003E9EC(void);
extern unsigned char perf_unknown_event_str[62];
extern unsigned char perf_event_still_open_cpu_str[37];
extern unsigned char perf_end_never_started_str[44];
extern unsigned char lbl_801789C0[560];

#pragma push
#pragma force_active on

asm void fn_8003BB30(register u32 a)
{
    nofralloc
    lfs     f0, -0x7cac(r2)
    lfs     f1, -0x7ca8(r2)
    lfs     f2, -0x7ca4(r2)
    lfs     f3, -0x7ca0(r2)
    ps_merge00 f4, f1, f2
    ps_merge00 f5, f1, f3
    cmplwi  r7, 0
    addi    r7, r7, 1
    srwi    r7, r7, 1
    blelr   
    rlwinm. r0, r7, 0x1d, 3, 0x1f
    mtctr   r0
    beq     _8003bcb0
_8003bb64:
    psq_lu  f1, 0x2(r4), 0, 2
    psq_lu  f3, 0x2(r6), 0, 7
    psq_lu  f2, 0x2(r5), 0, 7
    ps_sum0 f3, f3, f1, f3
    ps_sum1 f1, f2, f1, f2
    ps_merge10 f3, f3, f3
    ps_madd f1, f1, f4, f0
    ps_madd f3, f3, f5, f0
    psq_stu f1, 0x2(r3), 0, 2
    psq_stu f3, 0x2(r3), 0, 2
    psq_lu  f1, 0x2(r4), 0, 2
    psq_lu  f3, 0x2(r6), 0, 7
    psq_lu  f2, 0x2(r5), 0, 7
    ps_sum0 f3, f3, f1, f3
    ps_sum1 f1, f2, f1, f2
    ps_merge10 f3, f3, f3
    ps_madd f1, f1, f4, f0
    ps_madd f3, f3, f5, f0
    psq_stu f1, 0x2(r3), 0, 2
    psq_stu f3, 0x2(r3), 0, 2
    psq_lu  f1, 0x2(r4), 0, 2
    psq_lu  f3, 0x2(r6), 0, 7
    psq_lu  f2, 0x2(r5), 0, 7
    ps_sum0 f3, f3, f1, f3
    ps_sum1 f1, f2, f1, f2
    ps_merge10 f3, f3, f3
    ps_madd f1, f1, f4, f0
    ps_madd f3, f3, f5, f0
    psq_stu f1, 0x2(r3), 0, 2
    psq_stu f3, 0x2(r3), 0, 2
    psq_lu  f1, 0x2(r4), 0, 2
    psq_lu  f3, 0x2(r6), 0, 7
    psq_lu  f2, 0x2(r5), 0, 7
    ps_sum0 f3, f3, f1, f3
    ps_sum1 f1, f2, f1, f2
    ps_merge10 f3, f3, f3
    ps_madd f1, f1, f4, f0
    ps_madd f3, f3, f5, f0
    psq_stu f1, 0x2(r3), 0, 2
    psq_stu f3, 0x2(r3), 0, 2
    psq_lu  f1, 0x2(r4), 0, 2
    psq_lu  f3, 0x2(r6), 0, 7
    psq_lu  f2, 0x2(r5), 0, 7
    ps_sum0 f3, f3, f1, f3
    ps_sum1 f1, f2, f1, f2
    ps_merge10 f3, f3, f3
    ps_madd f1, f1, f4, f0
    ps_madd f3, f3, f5, f0
    psq_stu f1, 0x2(r3), 0, 2
    psq_stu f3, 0x2(r3), 0, 2
    psq_lu  f1, 0x2(r4), 0, 2
    psq_lu  f3, 0x2(r6), 0, 7
    psq_lu  f2, 0x2(r5), 0, 7
    ps_sum0 f3, f3, f1, f3
    ps_sum1 f1, f2, f1, f2
    ps_merge10 f3, f3, f3
    ps_madd f1, f1, f4, f0
    ps_madd f3, f3, f5, f0
    psq_stu f1, 0x2(r3), 0, 2
    psq_stu f3, 0x2(r3), 0, 2
    psq_lu  f1, 0x2(r4), 0, 2
    psq_lu  f3, 0x2(r6), 0, 7
    psq_lu  f2, 0x2(r5), 0, 7
    ps_sum0 f3, f3, f1, f3
    ps_sum1 f1, f2, f1, f2
    ps_merge10 f3, f3, f3
    ps_madd f1, f1, f4, f0
    ps_madd f3, f3, f5, f0
    psq_stu f1, 0x2(r3), 0, 2
    psq_stu f3, 0x2(r3), 0, 2
    psq_lu  f1, 0x2(r4), 0, 2
    psq_lu  f3, 0x2(r6), 0, 7
    psq_lu  f2, 0x2(r5), 0, 7
    ps_sum0 f3, f3, f1, f3
    ps_sum1 f1, f2, f1, f2
    ps_merge10 f3, f3, f3
    ps_madd f1, f1, f4, f0
    ps_madd f3, f3, f5, f0
    psq_stu f1, 0x2(r3), 0, 2
    psq_stu f3, 0x2(r3), 0, 2
    bdnz    _8003bb64
    andi.   r7, r7, 7
    beqlr   
_8003bcb0:
    mtctr   r7
_8003bcb4:
    psq_lu  f1, 0x2(r4), 0, 2
    psq_lu  f3, 0x2(r6), 0, 7
    psq_lu  f2, 0x2(r5), 0, 7
    ps_sum0 f3, f3, f1, f3
    ps_sum1 f1, f2, f1, f2
    ps_merge10 f3, f3, f3
    ps_madd f1, f1, f4, f0
    ps_madd f3, f3, f5, f0
    psq_stu f1, 0x2(r3), 0, 2
    psq_stu f3, 0x2(r3), 0, 2
    bdnz    _8003bcb4
    blr     
}

asm int fn_8003BCE4(register u32 a)
{
    nofralloc
    lfs     f0, -0x7c9c(r2)
    lfs     f1, -0x7c98(r2)
    lfs     f2, -0x7c94(r2)
    lfs     f3, -0x7c90(r2)
    lfs     f4, -0x7c8c(r2)
    psq_l   f5, 0x0(r5), 0, 2
    psq_l   f6, 0x0(r6), 0, 2
    ps_sub  f5, f5, f0
    ps_sub  f6, f6, f0
    psq_l   f0, 0x0(r4), 0, 2
    psq_l   f9, 0x0(r7), 1, 2
    ps_madds0 f8, f4, f5, f0
    ps_madds0 f7, f2, f6, f0
    ps_madds0 f0, f1, f6, f0
    ps_madds0 f7, f3, f5, f7
    ps_merge00 f10, f9, f0
    ps_merge00 f11, f7, f8
    psq_st  f10, 0x0(r3), 0, 2
    psq_st  f11, 0x20(r3), 0, 2
    ps_merge01 f10, f9, f0
    ps_merge11 f11, f7, f8
    psq_st  f10, 0x2(r3), 0, 2
    psq_st  f11, 0x22(r3), 0, 2
    psq_l   f0, 0x2(r4), 0, 2
    ps_madds1 f8, f4, f5, f0
    ps_madds1 f7, f2, f6, f0
    ps_madds1 f0, f1, f6, f0
    ps_madds1 f7, f3, f5, f7
    ps_merge00 f10, f9, f0
    ps_merge00 f11, f7, f8
    psq_st  f10, 0x4(r3), 0, 2
    psq_st  f11, 0x24(r3), 0, 2
    ps_merge01 f10, f9, f0
    ps_merge11 f11, f7, f8
    psq_st  f10, 0x6(r3), 0, 2
    psq_st  f11, 0x26(r3), 0, 2
    blr     
}

asm int fn_8003BD78(register u32 a)
{
    nofralloc
    lfs     f0, -0x7c9c(r2)
    lfs     f1, -0x7c98(r2)
    lfs     f2, -0x7c94(r2)
    lfs     f3, -0x7c90(r2)
    lfs     f4, -0x7c8c(r2)
    psq_l   f6, 0x0(r5), 0, 2
    psq_l   f7, 0x0(r6), 0, 2
    ps_sub  f6, f6, f0
    ps_sub  f7, f7, f0
    psq_l   f5, 0x0(r4), 0, 2
    psq_l   f10, 0x0(r7), 1, 2
    ps_madd f9, f6, f4, f5
    ps_madd f8, f7, f2, f5
    ps_madd f5, f7, f1, f5
    ps_madd f8, f6, f3, f8
    ps_merge00 f6, f10, f5
    ps_merge00 f7, f8, f9
    psq_st  f6, 0x0(r3), 0, 2
    psq_st  f7, 0x20(r3), 0, 2
    ps_merge01 f6, f10, f5
    ps_merge11 f7, f8, f9
    psq_st  f6, 0x2(r3), 0, 2
    psq_st  f7, 0x22(r3), 0, 2
    psq_l   f6, 0x2(r5), 0, 2
    psq_l   f7, 0x2(r6), 0, 2
    ps_sub  f6, f6, f0
    ps_sub  f7, f7, f0
    psq_l   f5, 0x2(r4), 0, 2
    ps_madd f9, f6, f4, f5
    ps_madd f8, f7, f2, f5
    ps_madd f5, f7, f1, f5
    ps_madd f8, f6, f3, f8
    ps_merge00 f6, f10, f5
    ps_merge00 f7, f8, f9
    psq_st  f6, 0x4(r3), 0, 2
    psq_st  f7, 0x24(r3), 0, 2
    ps_merge01 f6, f10, f5
    ps_merge11 f7, f8, f9
    psq_st  f6, 0x6(r3), 0, 2
    psq_st  f7, 0x26(r3), 0, 2
    blr     
}

asm int fn_8003BE1C(register u32 a)
{
    nofralloc
    mflr    r0
    li      r5, 8
    stw     r0, 4(r1)
    stwu    r1, -0x40(r1)
    stmw    r26, 0x28(r1)
    addi    r31, r4, 0
    addi    r30, r3, 0
    addi    r3, r31, 0
    li      r4, 0
    bl      memset
    lbz     r0, 0(r30)
    lbz     r3, 1(r30)
    addi    r30, r30, 2
    cmplwi  r0, 0xff
    bne     _8003be60
    cmplwi  r3, 0xd8
    beq     _8003be68
_8003be60:
    li      r3, 0
    b       _8003c190
_8003be68:
    lbz     r0, 0(r30)
    addi    r30, r30, 1
    cmplwi  r0, 0xff
    beq     _8003be88
    li      r3, 0
    b       _8003c190
    b       _8003be88
_8003be84:
    addi    r30, r30, 1
_8003be88:
    lbz     r0, 0(r30)
    cmplwi  r0, 0xff
    beq     _8003be84
    cmplwi  r0, 0xc0
    addi    r30, r30, 1
    bne     _8003c0ec
    lbz     r0, 3(r30)
    lbz     r3, 4(r30)
    rlwimi  r3, r0, 8, 0x10, 0x17
    sth     r3, 2(r31)
    lbz     r0, 5(r30)
    lbz     r3, 6(r30)
    rlwimi  r3, r0, 8, 0x10, 0x17
    sth     r3, 0(r31)
    lbz     r3, 7(r30)
    addi    r30, r30, 8
    cmplwi  r3, 3
    beq     _8003bed8
    li      r3, 0
    b       _8003c190
_8003bed8:
    cmplwi  r3, 0
    li      r4, 0
    ble     _8003c034
    cmplwi  r3, 8
    addi    r0, r3, -8
    ble     _8003c174
    addi    r8, r1, 0x24
    addi    r9, r1, 0x20
    addi    r7, r8, 0
    addi    r6, r9, 0
    clrlwi  r0, r0, 0x18
    b       _8003bff0
_8003bf08:
    lbz     r11, 1(r30)
    addi    r10, r4, 1
    addi    r12, r4, 3
    srawi   r5, r11, 4
    stb     r5, 0(r8)
    clrlwi  r5, r11, 0x1c
    addi    r11, r4, 2
    stb     r5, 0(r9)
    addi    r29, r4, 4
    addi    r28, r4, 5
    lbz     r26, 4(r30)
    addi    r27, r4, 7
    clrlwi  r10, r10, 0x18
    srawi   r5, r26, 4
    stbx    r5, r7, r10
    clrlwi  r5, r26, 0x1c
    clrlwi  r11, r11, 0x18
    stbx    r5, r6, r10
    addi    r10, r4, 6
    clrlwi  r12, r12, 0x18
    lbz     r26, 7(r30)
    clrlwi  r29, r29, 0x18
    clrlwi  r28, r28, 0x18
    srawi   r5, r26, 4
    stbx    r5, r7, r11
    clrlwi  r5, r26, 0x1c
    clrlwi  r10, r10, 0x18
    stbx    r5, r6, r11
    clrlwi  r27, r27, 0x18
    addi    r8, r8, 8
    lbz     r11, 0xa(r30)
    addi    r9, r9, 8
    addi    r4, r4, 8
    srawi   r5, r11, 4
    stbx    r5, r7, r12
    clrlwi  r5, r11, 0x1c
    stbx    r5, r6, r12
    lbz     r11, 0xd(r30)
    srawi   r5, r11, 4
    stbx    r5, r7, r29
    clrlwi  r5, r11, 0x1c
    stbx    r5, r6, r29
    lbz     r11, 0x10(r30)
    srawi   r5, r11, 4
    stbx    r5, r7, r28
    clrlwi  r5, r11, 0x1c
    stbx    r5, r6, r28
    lbz     r11, 0x13(r30)
    srawi   r5, r11, 4
    stbx    r5, r7, r10
    clrlwi  r5, r11, 0x1c
    stbx    r5, r6, r10
    lbz     r10, 0x16(r30)
    addi    r30, r30, 0x18
    srawi   r5, r10, 4
    stbx    r5, r7, r27
    clrlwi  r5, r10, 0x1c
    stbx    r5, r6, r27
_8003bff0:
    clrlwi  r5, r4, 0x18
    cmplw   r5, r0
    blt     _8003bf08
    b       _8003c174
    b       _8003c028
_8003c004:
    lbz     r7, 1(r30)
    addi    r4, r4, 1
    addi    r30, r30, 3
    srawi   r0, r7, 4
    stb     r0, 0(r5)
    clrlwi  r0, r7, 0x1c
    addi    r5, r5, 1
    stb     r0, 0(r6)
    addi    r6, r6, 1
_8003c028:
    clrlwi  r0, r4, 0x18
    cmplw   r0, r3
    blt     _8003c004
_8003c034:
    lbz     r4, 0x24(r1)
    lbz     r3, 0x25(r1)
    divw    r0, r4, r3
    cmpwi   r0, 2
    bne     _8003c0a8
    lbz     r0, 0x26(r1)
    divw    r0, r4, r0
    cmpwi   r0, 2
    bne     _8003c0a8
    lbz     r4, 0x20(r1)
    lbz     r3, 0x21(r1)
    divw    r0, r4, r3
    cmpwi   r0, 2
    bne     _8003c088
    lbz     r0, 0x22(r1)
    divw    r0, r4, r0
    cmpwi   r0, 2
    bne     _8003c088
    li      r0, 4
    stw     r0, 4(r31)
    b       _8003c16c
_8003c088:
    cmplw   r4, r3
    bne     _8003c16c
    lbz     r0, 0x22(r1)
    cmplw   r4, r0
    bne     _8003c16c
    li      r0, 2
    stw     r0, 4(r31)
    b       _8003c16c
_8003c0a8:
    cmplw   r4, r3
    bne     _8003c0e4
    lbz     r0, 0x26(r1)
    cmplw   r4, r0
    bne     _8003c0e4
    lbz     r3, 0x20(r1)
    lbz     r0, 0x21(r1)
    cmplw   r3, r0
    bne     _8003c16c
    lbz     r0, 0x22(r1)
    cmplw   r3, r0
    bne     _8003c16c
    li      r0, 1
    stw     r0, 4(r31)
    b       _8003c16c
_8003c0e4:
    li      r3, 0
    b       _8003c190
_8003c0ec:
    blt     _8003c164
    cmplwi  r0, 0xfe
    bgt     _8003c164
    lbz     r0, 0(r30)
    li      r5, 0
    lbz     r3, 1(r30)
    addi    r30, r30, 2
    rlwimi  r3, r0, 8, 0x10, 0x17
    clrlwi  r3, r3, 0x10
    addi    r4, r3, -2
    cmplwi  r4, 0
    ble     _8003be68
    cmplwi  r4, 8
    addi    r3, r4, -8
    ble     _8003c148
    addi    r0, r3, 7
    srwi    r0, r0, 3
    cmplwi  r3, 0
    mtctr   r0
    ble     _8003c148
_8003c13c:
    addi    r30, r30, 8
    addi    r5, r5, 8
    bdnz    _8003c13c
_8003c148:
    subf    r0, r5, r4
    cmplw   r5, r4
    mtctr   r0
    bge     _8003be68
_8003c158:
    addi    r30, r30, 1
    bdnz    _8003c158
    b       _8003be68
_8003c164:
    li      r3, 0
    b       _8003c190
_8003c16c:
    li      r3, 1
    b       _8003c190
_8003c174:
    clrlwi  r0, r4, 0x18
    addi    r5, r1, 0x24
    addi    r6, r1, 0x20
    add     r5, r5, r0
    add     r6, r6, r0
    b       _8003c028
    b       _8003c148
_8003c190:
    lmw     r26, 0x28(r1)
    lwz     r0, 0x44(r1)
    addi    r1, r1, 0x40
    mtlr    r0
    blr     
}

asm int GXSetFog(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x40(r1)
    stw     r31, 0x3c(r1)
    addi    r31, r3, 0
    li      r3, 0
    stw     r30, 0x38(r1)
    addi    r30, r5, 0
    stw     r29, 0x34(r1)
    mr      r29, r7
    stw     r28, 0x30(r1)
    addi    r28, r4, 0
    lwz     r0, 4(r7)
    cmpwi   r0, 3
    beq     _8003c244
    bge     _8003c1f4
    cmpwi   r0, 1
    beq     _8003c200
    bge     _8003c218
    b       _8003c244
_8003c1f4:
    cmpwi   r0, 5
    bge     _8003c244
    b       _8003c230
_8003c200:
    lhz     r3, 0(r29)
    lhz     r0, 2(r29)
    clrlwi  r3, r3, 0x1d
    clrlwi  r0, r0, 0x1d
    or      r3, r3, r0
    b       _8003c244
_8003c218:
    lhz     r3, 0(r29)
    lhz     r0, 2(r29)
    clrlwi  r3, r3, 0x1c
    clrlwi  r0, r0, 0x1d
    or      r3, r3, r0
    b       _8003c244
_8003c230:
    lhz     r3, 0(r29)
    lhz     r0, 2(r29)
    clrlwi  r3, r3, 0x1c
    clrlwi  r0, r0, 0x1c
    or      r3, r3, r0
_8003c244:
    cmplwi  r3, 0
    bne     _8003c69c
    lhz     r0, 0(r29)
    cmplwi  r0, 0x400
    bgt     _8003c69c
    lhz     r0, 2(r29)
    cmplwi  r0, 0x400
    bgt     _8003c69c
    stw     r6, 0(r31)
    cmplwi  r30, 0
    stw     r30, 4(r31)
    beq     _8003c67c
    addi    r3, r30, 0
    li      r4, 0
    li      r5, 0x7c8
    bl      memset
    stw     r30, 0x7b4(r30)
    li      r0, 0x21
    li      r6, 0
    lwz     r3, 0x7b4(r30)
    addi    r7, r30, 0
    addi    r3, r3, 0x7e0
    stw     r3, 0x7b4(r30)
    lwz     r3, 0x404(r30)
    stw     r3, 0x400(r30)
    stw     r0, 0x414(r30)
    sth     r6, 0x7aa(r30)
    sth     r6, 0x7ac(r30)
    sth     r6, 0x7a6(r30)
    stb     r6, 0x41d(r30)
    sth     r6, 0x40c(r30)
    sth     r6, 0x40e(r30)
    stb     r6, 0x418(r30)
    stb     r6, 0x419(r30)
    lwz     r3, 0x7b4(r30)
    addi    r0, r3, 0x1f
    rlwinm  r8, r0, 0, 0, 0x1a
    addi    r0, r8, 0x800
    stw     r0, 0x7b4(r30)
    b       _8003c32c
_8003c2e4:
    stw     r8, 0x750(r7)
    addi    r0, r8, 0x80
    addi    r3, r8, 0x100
    stw     r0, 0x754(r7)
    addi    r0, r8, 0x180
    addi    r5, r8, 0x200
    stw     r3, 0x758(r7)
    addi    r4, r8, 0x280
    addi    r3, r8, 0x300
    stw     r0, 0x75c(r7)
    addi    r0, r8, 0x380
    addi    r8, r8, 0x400
    stw     r5, 0x760(r7)
    addi    r6, r6, 8
    stw     r4, 0x764(r7)
    stw     r3, 0x768(r7)
    stw     r0, 0x76c(r7)
    addi    r7, r7, 0x20
_8003c32c:
    clrlwi  r0, r6, 0x18
    cmplwi  r0, 0x10
    blt     _8003c2e4
    lwz     r0, 0(r31)
    li      r31, 0
    stw     r0, 0x400(r30)
_8003c344:
    lwz     r3, 0x400(r30)
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
    lbz     r0, 0(r3)
    cmplwi  r0, 0xff
    bne     _8003c688
    b       _8003c36c
_8003c360:
    lwz     r3, 0x400(r30)
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
_8003c36c:
    lwz     r3, 0x400(r30)
    lbz     r0, 0(r3)
    cmplwi  r0, 0xff
    beq     _8003c360
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
    lbz     r0, 0(r3)
    cmplwi  r0, 0xd7
    bgt     _8003c3e0
    cmplwi  r0, 0xc4
    bne     _8003c3ac
    mr      r3, r30
    bl      GXCallDisplayList
    clrlwi. r0, r3, 0x18
    bne     _8003c694
    b       _8003c664
_8003c3ac:
    cmplwi  r0, 0xc0
    bne     _8003c3d0
    mr      r3, r30
    bl      fn_80039C40
    lwz     r4, 4(r29)
    clrlwi. r0, r3, 0x18
    stb     r4, 0x41f(r30)
    bne     _8003c694
    b       _8003c664
_8003c3d0:
    li      r0, 5
    stb     r0, 0(r28)
    li      r3, 0
    b       _8003c6b0
_8003c3e0:
    cmplwi  r0, 0xd8
    blt     _8003c494
    cmplwi  r0, 0xdf
    bgt     _8003c494
    cmplwi  r0, 0xdd
    bne     _8003c438
    li      r0, 1
    stb     r0, 0x41e(r30)
    lwz     r3, 0x400(r30)
    addi    r0, r3, 2
    stw     r0, 0x400(r30)
    lwz     r4, 0x400(r30)
    lbz     r3, 0(r4)
    lbz     r0, 1(r4)
    rlwimi  r0, r3, 8, 0x10, 0x17
    sth     r0, 0x7ae(r30)
    lwz     r3, 0x400(r30)
    addi    r0, r3, 2
    stw     r0, 0x400(r30)
    lhz     r0, 0x7ae(r30)
    sth     r0, 0x7b0(r30)
    b       _8003c664
_8003c438:
    cmplwi  r0, 0xdb
    bne     _8003c454
    mr      r3, r30
    bl      fn_80039E48
    clrlwi. r0, r3, 0x18
    bne     _8003c694
    b       _8003c664
_8003c454:
    cmplwi  r0, 0xda
    bne     _8003c47c
    mr      r3, r30
    bl      fn_8003A3D4
    clrlwi. r0, r3, 0x18
    bne     _8003c694
    lwz     r0, 0x400(r30)
    li      r31, 1
    stw     r0, 0x404(r30)
    b       _8003c664
_8003c47c:
    cmplwi  r0, 0xd8
    beq     _8003c664
    li      r0, 5
    stb     r0, 0(r28)
    li      r3, 0
    b       _8003c6b0
_8003c494:
    cmplwi  r0, 0xe0
    blt     _8003c664
    blt     _8003c574
    cmplwi  r0, 0xef
    bgt     _8003c574
    lwz     r4, 0x400(r30)
    li      r5, 0
    lbz     r3, 0(r4)
    lbz     r0, 1(r4)
    rlwimi  r0, r3, 8, 0x10, 0x17
    clrlwi  r4, r0, 0x10
    cmplwi  r4, 0
    ble     _8003c664
    cmplwi  r4, 8
    addi    r3, r4, -8
    ble     _8003c550
    addi    r0, r3, 7
    srwi    r0, r0, 3
    cmplwi  r3, 0
    mtctr   r0
    ble     _8003c550
_8003c4e8:
    lwz     r3, 0x400(r30)
    addi    r5, r5, 8
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
    lwz     r3, 0x400(r30)
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
    lwz     r3, 0x400(r30)
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
    lwz     r3, 0x400(r30)
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
    lwz     r3, 0x400(r30)
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
    lwz     r3, 0x400(r30)
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
    lwz     r3, 0x400(r30)
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
    lwz     r3, 0x400(r30)
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
    bdnz    _8003c4e8
_8003c550:
    subf    r0, r5, r4
    cmplw   r5, r4
    mtctr   r0
    bge     _8003c664
_8003c560:
    lwz     r3, 0x400(r30)
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
    bdnz    _8003c560
    b       _8003c664
_8003c574:
    cmplwi  r0, 0xfe
    bne     _8003c654
    lwz     r4, 0x400(r30)
    li      r3, 0
    lbz     r5, 0(r4)
    addi    r0, r4, 2
    lbz     r6, 1(r4)
    rlwimi  r6, r5, 8, 0x10, 0x17
    stw     r0, 0x400(r30)
    addi    r0, r6, -2
    cmplwi  r0, 0
    ble     _8003c664
    cmplwi  r0, 8
    addi    r4, r6, -0xa
    ble     _8003c62c
    addi    r0, r4, 7
    srwi    r0, r0, 3
    cmplwi  r4, 0
    mtctr   r0
    ble     _8003c62c
_8003c5c4:
    lwz     r4, 0x400(r30)
    addi    r3, r3, 8
    addi    r0, r4, 1
    stw     r0, 0x400(r30)
    lwz     r4, 0x400(r30)
    addi    r0, r4, 1
    stw     r0, 0x400(r30)
    lwz     r4, 0x400(r30)
    addi    r0, r4, 1
    stw     r0, 0x400(r30)
    lwz     r4, 0x400(r30)
    addi    r0, r4, 1
    stw     r0, 0x400(r30)
    lwz     r4, 0x400(r30)
    addi    r0, r4, 1
    stw     r0, 0x400(r30)
    lwz     r4, 0x400(r30)
    addi    r0, r4, 1
    stw     r0, 0x400(r30)
    lwz     r4, 0x400(r30)
    addi    r0, r4, 1
    stw     r0, 0x400(r30)
    lwz     r4, 0x400(r30)
    addi    r0, r4, 1
    stw     r0, 0x400(r30)
    bdnz    _8003c5c4
_8003c62c:
    addi    r4, r6, -2
    subf    r0, r3, r4
    cmplw   r3, r4
    mtctr   r0
    bge     _8003c664
_8003c640:
    lwz     r3, 0x400(r30)
    addi    r0, r3, 1
    stw     r0, 0x400(r30)
    bdnz    _8003c640
    b       _8003c664
_8003c654:
    li      r0, 5
    stb     r0, 0(r28)
    li      r3, 0
    b       _8003c6b0
_8003c664:
    clrlwi. r0, r31, 0x18
    beq     _8003c344
    li      r0, 0
    stb     r0, 0(r28)
    li      r3, 1
    b       _8003c6b0
_8003c67c:
    li      r0, 2
    stb     r0, 0(r28)
    b       _8003c6a4
_8003c688:
    li      r0, 1
    stb     r0, 0(r28)
    b       _8003c6a4
_8003c694:
    stb     r3, 0(r28)
    b       _8003c6a4
_8003c69c:
    li      r0, 0xd
    stb     r0, 0(r28)
_8003c6a4:
    li      r3, 0
    b       _8003c6b0
    b       _8003c550
_8003c6b0:
    lwz     r0, 0x44(r1)
    lwz     r31, 0x3c(r1)
    lwz     r30, 0x38(r1)
    lwz     r29, 0x34(r1)
    lwz     r28, 0x30(r1)
    addi    r1, r1, 0x40
    mtlr    r0
    blr     
}

asm int GXSetFogRangeAdj(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    li      r0, 0
    stwu    r1, -0x58(r1)
    stmw    r16, 0x18(r1)
    addi    r28, r4, 0
    addi    r29, r5, 0
    addi    r30, r6, 0
    addi    r19, r28, -2
    lwz     r31, 4(r3)
    li      r3, 0x21
    lwz     r4, 0x404(r31)
    stw     r4, 0x400(r31)
    stw     r3, 0x414(r31)
    sth     r0, 0x7aa(r31)
    sth     r0, 0x7ac(r31)
    sth     r0, 0x7a6(r31)
    stb     r0, 0x41d(r31)
    sth     r0, 0x40c(r31)
    sth     r0, 0x40e(r31)
    lhz     r0, 0x408(r31)
    cmplw   r0, r29
    ble     _8003c730
    mr      r0, r29
_8003c730:
    lhz     r24, 0x40a(r31)
    mr      r20, r0
    cmplw   r24, r30
    ble     _8003c744
    mr      r24, r30
_8003c744:
    lbz     r6, 0x6f1(r31)
    li      r7, 0
    lbz     r5, 0x41a(r31)
    li      r3, 0
    lbz     r4, 0x6f2(r31)
    lbz     r0, 0x41b(r31)
    subf    r25, r6, r5
    lwz     r22, 0x6c8(r31)
    lwz     r21, 0x6f8(r31)
    subf    r26, r4, r0
    b       _8003c784
_8003c770:
    add     r4, r31, r3
    lwz     r0, 0x6d0(r4)
    addi    r7, r7, 1
    addi    r3, r3, 0x30
    stw     r0, 0x6d4(r4)
_8003c784:
    lbz     r0, 0x41c(r31)
    cmplw   r7, r0
    blt     _8003c770
    li      r0, 0
    sth     r0, 0x7ac(r31)
    li      r3, 0
    bl      PPCMtmmcr1
    li      r3, 0
    bl      PPCMtmmcr0
    bl      PPCMfpmc4
    lis     r4, lbl_801789C0@ha
    addi    r16, r4, lbl_801789C0@l
    stw     r3, 0x118(r16)
    bl      PPCMfpmc3
    stw     r3, 0x128(r16)
    bl      PPCMfpmc2
    stw     r3, 0x120(r16)
    bl      PPCMfpmc1
    stw     r3, 0x130(r16)
    li      r3, 0x8b
    bl      PPCMtmmcr0
    lis     r3, 0x7840
    bl      PPCMtmmcr1
    mfspr   r0, 0x392
    stw     r0, 0x7b8(r31)
    li      r0, 4
    oris    r0, r0, 4
    mtspr   0x392, r0
    mfspr   r0, 0x395
    stw     r0, 0x7bc(r31)
    li      r0, 7
    oris    r0, r0, 7
    mtspr   0x395, r0
    mfspr   r0, 0x396
    stw     r0, 0x7c0(r31)
    li      r0, 0x3d04
    oris    r0, r0, 0x3d04
    mtspr   0x396, r0
    mfspr   r0, 0x397
    stw     r0, 0x7c4(r31)
    li      r0, 0x104
    oris    r0, r0, 0x104
    mtspr   0x397, r0
    slwi    r27, r29, 1
    clrlwi  r26, r26, 0x18
    clrlwi  r25, r25, 0x18
    b       _8003c970
_8003c840:
    li      r0, 0
    sth     r0, 0x7aa(r31)
    mr      r3, r31
    bl      fn_8003AB08
    lhz     r3, 0x7ac(r31)
    cmplwi  r25, 0
    lhz     r0, 0x7a8(r31)
    add     r0, r3, r0
    sth     r0, 0x7ac(r31)
    lwz     r5, 0x6d4(r31)
    lwz     r4, 0x704(r31)
    lwz     r3, 0x734(r31)
    addi    r18, r5, -2
    addi    r17, r4, -2
    addi    r16, r3, -2
    bne     _8003c8c4
    li      r23, 0
    b       _8003c8b4
_8003c888:
    addi    r3, r19, 0
    addi    r4, r18, 0
    addi    r5, r17, 0
    addi    r6, r16, 0
    addi    r7, r20, 0
    bl      fn_8003BB30
    add     r19, r19, r27
    add     r18, r18, r22
    add     r17, r17, r21
    add     r16, r16, r21
    addi    r23, r23, 1
_8003c8b4:
    lhz     r0, 0x7a8(r31)
    cmplw   r23, r0
    blt     _8003c888
    b       _8003c970
_8003c8c4:
    cmplwi  r26, 0
    bne     _8003c910
    li      r23, 0
    b       _8003c900
_8003c8d4:
    addi    r3, r19, 0
    addi    r4, r18, 0
    addi    r5, r17, 0
    addi    r6, r16, 0
    addi    r7, r20, 0
    bl      fn_8003B9AC
    add     r19, r19, r27
    add     r18, r18, r22
    add     r17, r17, r21
    add     r16, r16, r21
    addi    r23, r23, 1
_8003c900:
    lhz     r0, 0x7a8(r31)
    cmplw   r23, r0
    blt     _8003c8d4
    b       _8003c970
_8003c910:
    li      r23, 0
    b       _8003c964
_8003c918:
    addi    r3, r19, 0
    addi    r4, r18, 0
    addi    r5, r17, 0
    addi    r6, r16, 0
    addi    r7, r20, 0
    bl      fn_8003B9AC
    add     r19, r19, r27
    add     r18, r18, r22
    addi    r3, r19, 0
    addi    r4, r18, 0
    addi    r5, r17, 0
    addi    r6, r16, 0
    addi    r7, r20, 0
    bl      fn_8003B9AC
    add     r19, r19, r27
    add     r18, r18, r22
    add     r17, r17, r21
    add     r16, r16, r21
    addi    r23, r23, 2
_8003c964:
    lhz     r0, 0x7a8(r31)
    cmplw   r23, r0
    blt     _8003c918
_8003c970:
    lhz     r0, 0x7ac(r31)
    cmplw   r0, r24
    blt     _8003c840
    li      r3, 0
    bl      PPCMtmmcr1
    li      r3, 0
    bl      PPCMtmmcr0
    lis     r3, lbl_801789C0@ha
    addi    r16, r3, lbl_801789C0@l
    lwz     r3, 0x14c(r16)
    addi    r0, r3, 1
    stw     r0, 0x14c(r16)
    bl      PPCMfpmc4
    stw     r3, 0x11c(r16)
    bl      PPCMfpmc3
    stw     r3, 0x12c(r16)
    bl      PPCMfpmc2
    stw     r3, 0x124(r16)
    bl      PPCMfpmc1
    stw     r3, 0x134(r16)
    lwz     r3, 0x118(r16)
    lwz     r0, 0x11c(r16)
    lwz     r4, 0x148(r16)
    subf    r0, r3, r0
    cmplw   r0, r4
    ble     _8003c9dc
    mr      r4, r0
_8003c9dc:
    lis     r3, lbl_801789C0@ha
    addi    r27, r3, lbl_801789C0@l
    stw     r4, 0x148(r27)
    li      r3, 0x8b
    lwz     r4, 0x118(r27)
    lwz     r0, 0x11c(r27)
    lwz     r5, 0x138(r27)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x138(r27)
    lwz     r4, 0x128(r27)
    lwz     r0, 0x12c(r27)
    lwz     r5, 0x140(r27)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x140(r27)
    lwz     r4, 0x120(r27)
    lwz     r0, 0x124(r27)
    lwz     r5, 0x13c(r27)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x13c(r27)
    lwz     r4, 0x130(r27)
    lwz     r0, 0x134(r27)
    lwz     r5, 0x144(r27)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x144(r27)
    bl      PPCMtmmcr0
    lis     r3, 0x7840
    bl      PPCMtmmcr1
    li      r3, 0
    bl      PPCMtmmcr1
    li      r3, 0
    bl      PPCMtmmcr0
    bl      PPCMfpmc4
    stw     r3, 0x1f8(r27)
    bl      PPCMfpmc3
    stw     r3, 0x208(r27)
    bl      PPCMfpmc2
    stw     r3, 0x200(r27)
    bl      PPCMfpmc1
    stw     r3, 0x210(r27)
    li      r3, 0x8b
    bl      PPCMtmmcr0
    lis     r3, 0x7840
    bl      PPCMtmmcr1
    mullw   r0, r29, r30
    addi    r3, r28, 0
    slwi    r4, r0, 1
    bl      DCStoreRange
    li      r3, 0
    bl      PPCMtmmcr1
    li      r3, 0
    bl      PPCMtmmcr0
    lwz     r3, 0x22c(r27)
    addi    r0, r3, 1
    stw     r0, 0x22c(r27)
    bl      PPCMfpmc4
    stw     r3, 0x1fc(r27)
    bl      PPCMfpmc3
    stw     r3, 0x20c(r27)
    bl      PPCMfpmc2
    stw     r3, 0x204(r27)
    bl      PPCMfpmc1
    stw     r3, 0x214(r27)
    lwz     r3, 0x1f8(r27)
    lwz     r0, 0x1fc(r27)
    lwz     r4, 0x228(r27)
    subf    r0, r3, r0
    cmplw   r0, r4
    ble     _8003cb00
    mr      r4, r0
_8003cb00:
    lis     r3, lbl_801789C0@ha
    addi    r6, r3, lbl_801789C0@l
    stw     r4, 0x228(r6)
    li      r3, 0x8b
    lwz     r4, 0x1f8(r6)
    lwz     r0, 0x1fc(r6)
    lwz     r5, 0x218(r6)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x218(r6)
    lwz     r4, 0x208(r6)
    lwz     r0, 0x20c(r6)
    lwz     r5, 0x220(r6)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x220(r6)
    lwz     r4, 0x200(r6)
    lwz     r0, 0x204(r6)
    lwz     r5, 0x21c(r6)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x21c(r6)
    lwz     r4, 0x210(r6)
    lwz     r0, 0x214(r6)
    lwz     r5, 0x224(r6)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x224(r6)
    bl      PPCMtmmcr0
    lis     r3, 0x7840
    bl      PPCMtmmcr1
    lwz     r0, 0x7b8(r31)
    mtspr   0x392, r0
    lwz     r0, 0x7bc(r31)
    mtspr   0x395, r0
    lwz     r0, 0x7c0(r31)
    mtspr   0x396, r0
    lwz     r0, 0x7c4(r31)
    mtspr   0x397, r0
    lmw     r16, 0x18(r1)
    lwz     r0, 0x5c(r1)
    addi    r1, r1, 0x58
    mtlr    r0
    blr     
}

asm int fn_8003CBB0(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    li      r0, 0
    stwu    r1, -0x30(r1)
    stmw    r27, 0x1c(r1)
    addi    r28, r4, 0
    addi    r29, r5, 0
    mr      r30, r6
    lwz     r31, 4(r3)
    li      r3, 0x21
    lwz     r7, 0x404(r31)
    stw     r7, 0x400(r31)
    stw     r3, 0x414(r31)
    sth     r0, 0x7aa(r31)
    sth     r0, 0x7ac(r31)
    sth     r0, 0x7a6(r31)
    stb     r0, 0x41d(r31)
    sth     r0, 0x40c(r31)
    sth     r0, 0x40e(r31)
    sth     r0, 0x7ac(r31)
    stw     r28, 0x6d4(r31)
    lbz     r0, 0x41c(r31)
    cmplwi  r0, 2
    blt     _8003cc14
    stw     r29, 0x704(r31)
_8003cc14:
    lbz     r0, 0x41c(r31)
    cmplwi  r0, 3
    blt     _8003cc24
    stw     r30, 0x734(r31)
_8003cc24:
    mfspr   r0, 0x392
    stw     r0, 0x7b8(r31)
    li      r0, 4
    oris    r0, r0, 4
    mtspr   0x392, r0
    mfspr   r0, 0x395
    stw     r0, 0x7bc(r31)
    li      r0, 7
    oris    r0, r0, 7
    mtspr   0x395, r0
    mfspr   r0, 0x396
    stw     r0, 0x7c0(r31)
    li      r0, 0x3d04
    oris    r0, r0, 0x3d04
    mtspr   0x396, r0
    mfspr   r0, 0x397
    stw     r0, 0x7c4(r31)
    li      r0, 0x104
    oris    r0, r0, 0x104
    mtspr   0x397, r0
    b       _8003ccdc
_8003cc78:
    li      r27, 0
    sth     r27, 0x7aa(r31)
    mr      r3, r31
    bl      fn_8003B010
    lhz     r3, 0x7ac(r31)
    li      r6, 0
    lhz     r0, 0x7a8(r31)
    add     r0, r3, r0
    sth     r0, 0x7ac(r31)
    b       _8003ccd0
_8003cca0:
    add     r5, r31, r27
    lhz     r3, 0x7a0(r31)
    lwz     r0, 0x6dc(r5)
    addi    r6, r6, 1
    lwz     r4, 0x6d8(r5)
    addi    r27, r27, 0x30
    mullw   r0, r3, r0
    lwz     r3, 0x6d4(r5)
    mullw   r0, r4, r0
    slwi    r0, r0, 6
    add     r0, r3, r0
    stw     r0, 0x6d4(r5)
_8003ccd0:
    lbz     r0, 0x41c(r31)
    cmplw   r6, r0
    blt     _8003cca0
_8003ccdc:
    lhz     r3, 0x7ac(r31)
    lhz     r0, 0x40a(r31)
    cmplw   r3, r0
    blt     _8003cc78
    li      r3, 0
    bl      PPCMtmmcr1
    li      r3, 0
    bl      PPCMtmmcr0
    bl      PPCMfpmc4
    lis     r4, lbl_801789C0@ha
    addi    r27, r4, lbl_801789C0@l
    stw     r3, 0x70(r27)
    bl      PPCMfpmc3
    stw     r3, 0x80(r27)
    bl      PPCMfpmc2
    stw     r3, 0x78(r27)
    bl      PPCMfpmc1
    stw     r3, 0x88(r27)
    li      r3, 0x8b
    bl      PPCMtmmcr0
    lis     r3, 0x7840
    bl      PPCMtmmcr1
    lwz     r6, 0x6c8(r31)
    mr      r3, r28
    lwz     r4, 0x6cc(r31)
    lwz     r5, 0x6f8(r31)
    lwz     r0, 0x6fc(r31)
    mullw   r4, r6, r4
    mullw   r28, r5, r0
    bl      DCStoreRange
    addi    r3, r29, 0
    addi    r4, r28, 0
    bl      DCStoreRange
    addi    r3, r30, 0
    addi    r4, r28, 0
    bl      DCStoreRange
    li      r3, 0
    bl      PPCMtmmcr1
    li      r3, 0
    bl      PPCMtmmcr0
    lwz     r3, 0xa4(r27)
    addi    r0, r3, 1
    stw     r0, 0xa4(r27)
    bl      PPCMfpmc4
    stw     r3, 0x74(r27)
    bl      PPCMfpmc3
    stw     r3, 0x84(r27)
    bl      PPCMfpmc2
    stw     r3, 0x7c(r27)
    bl      PPCMfpmc1
    stw     r3, 0x8c(r27)
    lwz     r3, 0x70(r27)
    lwz     r0, 0x74(r27)
    lwz     r4, 0xa0(r27)
    subf    r0, r3, r0
    cmplw   r0, r4
    ble     _8003cdc4
    mr      r4, r0
_8003cdc4:
    lis     r3, lbl_801789C0@ha
    addi    r6, r3, lbl_801789C0@l
    stw     r4, 0xa0(r6)
    li      r3, 0x8b
    lwz     r4, 0x70(r6)
    lwz     r0, 0x74(r6)
    lwz     r5, 0x90(r6)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x90(r6)
    lwz     r4, 0x80(r6)
    lwz     r0, 0x84(r6)
    lwz     r5, 0x98(r6)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x98(r6)
    lwz     r4, 0x78(r6)
    lwz     r0, 0x7c(r6)
    lwz     r5, 0x94(r6)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x94(r6)
    lwz     r4, 0x88(r6)
    lwz     r0, 0x8c(r6)
    lwz     r5, 0x9c(r6)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x9c(r6)
    bl      PPCMtmmcr0
    lis     r3, 0x7840
    bl      PPCMtmmcr1
    lwz     r0, 0x7b8(r31)
    mtspr   0x392, r0
    lwz     r0, 0x7bc(r31)
    mtspr   0x395, r0
    lwz     r0, 0x7c0(r31)
    mtspr   0x396, r0
    lwz     r0, 0x7c4(r31)
    mtspr   0x397, r0
    lmw     r27, 0x1c(r1)
    lwz     r0, 0x34(r1)
    addi    r1, r1, 0x30
    mtlr    r0
    blr     
}

asm int GXInitFogAdjTable(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    li      r0, 0x21
    stwu    r1, -0x60(r1)
    stmw    r14, 0x18(r1)
    li      r27, 0
    stw     r4, 0x14(r1)
    lwz     r31, 0x14(r1)
    stb     r5, 0x10(r1)
    li      r5, 0
    lwz     r18, 4(r3)
    lwz     r3, 0x404(r18)
    stw     r3, 0x400(r18)
    stw     r0, 0x414(r18)
    sth     r5, 0x7aa(r18)
    sth     r5, 0x7ac(r18)
    sth     r5, 0x7a6(r18)
    stb     r5, 0x41d(r18)
    sth     r5, 0x40c(r18)
    sth     r5, 0x40e(r18)
    lbz     r6, 0x6f1(r18)
    lbz     r4, 0x41a(r18)
    lbz     r3, 0x6f2(r18)
    lbz     r0, 0x41b(r18)
    subf    r15, r6, r4
    lwz     r25, 0x6c8(r18)
    lwz     r26, 0x6f8(r18)
    subf    r14, r3, r0
    b       _8003cefc
_8003cee8:
    add     r3, r18, r5
    lwz     r0, 0x6d0(r3)
    addi    r27, r27, 1
    addi    r5, r5, 0x30
    stw     r0, 0x6d4(r3)
_8003cefc:
    lbz     r0, 0x41c(r18)
    cmplw   r27, r0
    blt     _8003cee8
    li      r0, 0
    sth     r0, 0x7ac(r18)
    li      r3, 0
    bl      PPCMtmmcr1
    li      r3, 0
    bl      PPCMtmmcr0
    bl      PPCMfpmc4
    lis     r4, lbl_801789C0@ha
    addi    r16, r4, lbl_801789C0@l
    stw     r3, 0x118(r16)
    bl      PPCMfpmc3
    stw     r3, 0x128(r16)
    bl      PPCMfpmc2
    stw     r3, 0x120(r16)
    bl      PPCMfpmc1
    stw     r3, 0x130(r16)
    li      r3, 0x8b
    bl      PPCMtmmcr0
    lis     r3, 0x7840
    bl      PPCMtmmcr1
    mfspr   r0, 0x392
    stw     r0, 0x7b8(r18)
    li      r0, 4
    oris    r0, r0, 4
    mtspr   0x392, r0
    mfspr   r0, 0x395
    stw     r0, 0x7bc(r18)
    li      r0, 7
    oris    r0, r0, 7
    mtspr   0x395, r0
    mfspr   r0, 0x396
    stw     r0, 0x7c0(r18)
    li      r0, 0x3d04
    oris    r0, r0, 0x3d04
    mtspr   0x396, r0
    mfspr   r0, 0x397
    stw     r0, 0x7c4(r18)
    li      r0, 0x104
    oris    r0, r0, 0x104
    mtspr   0x397, r0
    mulli   r16, r25, 3
    mulli   r17, r26, 3
    srwi    r20, r25, 2
    clrlwi  r14, r14, 0x18
    clrlwi  r15, r15, 0x18
    b       _8003d1d4
_8003cfc0:
    li      r0, 0
    sth     r0, 0x7aa(r18)
    mr      r3, r18
    bl      fn_8003AB08
    lhz     r3, 0x7ac(r18)
    cmplwi  r15, 0
    lhz     r0, 0x7a8(r18)
    add     r0, r3, r0
    sth     r0, 0x7ac(r18)
    lwz     r22, 0x6d4(r18)
    lwz     r23, 0x704(r18)
    lwz     r24, 0x734(r18)
    bne     _8003d088
    li      r19, 0
    b       _8003d074
_8003cffc:
    li      r21, 0
    b       _8003d05c
_8003d004:
    addi    r30, r22, 0
    addi    r28, r23, 0
    addi    r29, r24, 0
    li      r27, 0
_8003d014:
    addi    r3, r31, 0
    addi    r4, r30, 0
    addi    r5, r28, 0
    addi    r6, r29, 0
    addi    r7, r1, 0x10
    bl      fn_8003BD78
    addi    r27, r27, 1
    cmplwi  r27, 4
    add     r30, r30, r25
    add     r28, r28, r26
    add     r29, r29, r26
    addi    r31, r31, 8
    blt     _8003d014
    addi    r31, r31, 0x20
    addi    r22, r22, 4
    addi    r23, r23, 4
    addi    r24, r24, 4
    addi    r21, r21, 1
_8003d05c:
    cmplw   r21, r20
    blt     _8003d004
    add     r22, r22, r16
    add     r23, r23, r17
    add     r24, r24, r17
    addi    r19, r19, 1
_8003d074:
    lhz     r0, 0x7a8(r18)
    srawi   r0, r0, 2
    cmplw   r19, r0
    blt     _8003cffc
    b       _8003d1d4
_8003d088:
    cmplwi  r14, 0
    bne     _8003d124
    li      r19, 0
    b       _8003d110
_8003d098:
    li      r21, 0
    b       _8003d0f8
_8003d0a0:
    addi    r30, r22, 0
    addi    r28, r23, 0
    addi    r29, r24, 0
    li      r27, 0
_8003d0b0:
    addi    r3, r31, 0
    addi    r4, r30, 0
    addi    r5, r28, 0
    addi    r6, r29, 0
    addi    r7, r1, 0x10
    bl      fn_8003BCE4
    addi    r27, r27, 1
    cmplwi  r27, 4
    add     r30, r30, r25
    add     r28, r28, r26
    add     r29, r29, r26
    addi    r31, r31, 8
    blt     _8003d0b0
    addi    r31, r31, 0x20
    addi    r22, r22, 4
    addi    r23, r23, 2
    addi    r24, r24, 2
    addi    r21, r21, 1
_8003d0f8:
    cmplw   r21, r20
    blt     _8003d0a0
    add     r22, r22, r16
    add     r23, r23, r17
    add     r24, r24, r17
    addi    r19, r19, 1
_8003d110:
    lhz     r0, 0x7a8(r18)
    srawi   r0, r0, 2
    cmplw   r19, r0
    blt     _8003d098
    b       _8003d1d4
_8003d124:
    li      r19, 0
    b       _8003d1c4
_8003d12c:
    li      r21, 0
    b       _8003d1ac
_8003d134:
    addi    r30, r22, 0
    addi    r28, r23, 0
    addi    r29, r24, 0
    li      r27, 0
_8003d144:
    addi    r3, r31, 0
    addi    r4, r30, 0
    addi    r5, r28, 0
    addi    r6, r29, 0
    addi    r7, r1, 0x10
    bl      fn_8003BCE4
    add     r30, r30, r25
    addi    r31, r31, 8
    addi    r3, r31, 0
    addi    r4, r30, 0
    addi    r5, r28, 0
    addi    r6, r29, 0
    addi    r7, r1, 0x10
    bl      fn_8003BCE4
    addi    r27, r27, 1
    cmplwi  r27, 2
    add     r30, r30, r25
    add     r28, r28, r26
    add     r29, r29, r26
    addi    r31, r31, 8
    blt     _8003d144
    addi    r31, r31, 0x20
    addi    r22, r22, 4
    addi    r23, r23, 2
    addi    r24, r24, 2
    addi    r21, r21, 1
_8003d1ac:
    cmplw   r21, r20
    blt     _8003d134
    add     r22, r22, r16
    add     r23, r23, r26
    add     r24, r24, r26
    addi    r19, r19, 1
_8003d1c4:
    lhz     r0, 0x7a8(r18)
    srawi   r0, r0, 2
    cmplw   r19, r0
    blt     _8003d12c
_8003d1d4:
    lhz     r3, 0x7ac(r18)
    lhz     r0, 0x40a(r18)
    cmplw   r3, r0
    blt     _8003cfc0
    li      r3, 0
    bl      PPCMtmmcr1
    li      r3, 0
    bl      PPCMtmmcr0
    lis     r3, lbl_801789C0@ha
    addi    r16, r3, lbl_801789C0@l
    lwz     r3, 0x14c(r16)
    addi    r0, r3, 1
    stw     r0, 0x14c(r16)
    bl      PPCMfpmc4
    stw     r3, 0x11c(r16)
    bl      PPCMfpmc3
    stw     r3, 0x12c(r16)
    bl      PPCMfpmc2
    stw     r3, 0x124(r16)
    bl      PPCMfpmc1
    stw     r3, 0x134(r16)
    lwz     r3, 0x118(r16)
    lwz     r0, 0x11c(r16)
    lwz     r4, 0x148(r16)
    subf    r0, r3, r0
    cmplw   r0, r4
    ble     _8003d244
    mr      r4, r0
_8003d244:
    lis     r3, lbl_801789C0@ha
    addi    r16, r3, lbl_801789C0@l
    stw     r4, 0x148(r16)
    li      r3, 0x8b
    lwz     r4, 0x118(r16)
    lwz     r0, 0x11c(r16)
    lwz     r5, 0x138(r16)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x138(r16)
    lwz     r4, 0x128(r16)
    lwz     r0, 0x12c(r16)
    lwz     r5, 0x140(r16)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x140(r16)
    lwz     r4, 0x120(r16)
    lwz     r0, 0x124(r16)
    lwz     r5, 0x13c(r16)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x13c(r16)
    lwz     r4, 0x130(r16)
    lwz     r0, 0x134(r16)
    lwz     r5, 0x144(r16)
    subf    r0, r4, r0
    add     r0, r5, r0
    stw     r0, 0x144(r16)
    bl      PPCMtmmcr0
    lis     r3, 0x7840
    bl      PPCMtmmcr1
    li      r3, 0
    bl      PPCMtmmcr1
    li      r3, 0
    bl      PPCMtmmcr0
    bl      PPCMfpmc4
    stw     r3, 0x70(r16)
    bl      PPCMfpmc3
    stw     r3, 0x80(r16)
    bl      PPCMfpmc2
    stw     r3, 0x78(r16)
    bl      PPCMfpmc1
    stw     r3, 0x88(r16)
    li      r3, 0x8b
    bl      PPCMtmmcr0
    lis     r3, 0x7840
    bl      PPCMtmmcr1
    lhz     r3, 0x408(r18)
    li      r5, 6
    lhz     r4, 0x40a(r18)
    li      r6, 0
    li      r7, 0
    bl      __GXGetTexBufferSize
    mr      r4, r3
    lwz     r3, 0x14(r1)
    bl      DCStoreRange
    li      r3, 0
    bl      PPCMtmmcr1
    li      r3, 0
    bl      PPCMtmmcr0
    lwz     r3, 0xa4(r16)
    addi    r0, r3, 1
    stw     r0, 0xa4(r16)
    bl      PPCMfpmc4
    stw     r3, 0x74(r16)
    bl      PPCMfpmc3
    stw     r3, 0x84(r16)
    bl      PPCMfpmc2
    stw     r3, 0x7c(r16)
    bl      PPCMfpmc1
    stw     r3, 0x8c(r16)
    lwz     r3, 0x70(r16)
    lwz     r0, 0x74(r16)
    lwz     r5, 0xa0(r16)
    subf    r0, r3, r0
    cmplw   r0, r5
    ble     _8003d37c
    mr      r5, r0
_8003d37c:
    lis     r3, lbl_801789C0@ha
    addi    r4, r3, lbl_801789C0@l
    stw     r5, 0xa0(r4)
    li      r3, 0x8b
    lwz     r5, 0x70(r4)
    lwz     r0, 0x74(r4)
    lwz     r6, 0x90(r4)
    subf    r0, r5, r0
    add     r0, r6, r0
    stw     r0, 0x90(r4)
    lwz     r5, 0x80(r4)
    lwz     r0, 0x84(r4)
    lwz     r6, 0x98(r4)
    subf    r0, r5, r0
    add     r0, r6, r0
    stw     r0, 0x98(r4)
    lwz     r5, 0x78(r4)
    lwz     r0, 0x7c(r4)
    lwz     r6, 0x94(r4)
    subf    r0, r5, r0
    add     r0, r6, r0
    stw     r0, 0x94(r4)
    lwz     r5, 0x88(r4)
    lwz     r0, 0x8c(r4)
    lwz     r6, 0x9c(r4)
    subf    r0, r5, r0
    add     r0, r6, r0
    stw     r0, 0x9c(r4)
    bl      PPCMtmmcr0
    lis     r3, 0x7840
    bl      PPCMtmmcr1
    lwz     r0, 0x7b8(r18)
    mtspr   0x392, r0
    lwz     r0, 0x7bc(r18)
    mtspr   0x395, r0
    lwz     r0, 0x7c0(r18)
    mtspr   0x396, r0
    lwz     r0, 0x7c4(r18)
    mtspr   0x397, r0
    lmw     r14, 0x18(r1)
    lwz     r0, 0x64(r1)
    addi    r1, r1, 0x60
    mtlr    r0
    blr     
}

asm void __GXSetFog(void)
{
    nofralloc
    lwz     r4, 0x414(r3)
    cmpwi   r4, 0x21
    bne     _8003d4a8
    lwz     r4, 0x400(r3)
    li      r0, 0x1a
    lbz     r5, 0(r4)
    stw     r0, 0x414(r3)
    cmplwi  r5, 0xff
    beq     _8003d468
    addi    r0, r4, 1
    stw     r5, 0x410(r3)
    rlwinm  r5, r5, 0x19, 0x1f, 0x1f
    stw     r0, 0x400(r3)
    b       _8003d4b8
_8003d464:
    addi    r4, r4, -1
_8003d468:
    lbz     r0, 1(r4)
    cmplwi  r0, 0
    beq     _8003d494
    lbz     r5, 2(r4)
    addi    r4, r4, 3
    cmplwi  r5, 0xff
    beq     _8003d464
    stw     r5, 0x410(r3)
    rlwinm  r5, r5, 0x19, 0x1f, 0x1f
    stw     r4, 0x400(r3)
    b       _8003d4b8
_8003d494:
    addi    r4, r4, 2
    stw     r5, 0x410(r3)
    rlwinm  r5, r5, 0x19, 0x1f, 0x1f
    stw     r4, 0x400(r3)
    b       _8003d4b8
_8003d4a8:
    lwz     r5, 0x410(r3)
    addi    r0, r4, 1
    stw     r0, 0x414(r3)
    rlwnm   r5, r5, r4, 0x1f, 0x1f
_8003d4b8:
    mr      r3, r5
    blr     
}

asm int fn_8003D4C0(register u32 a)
{
    nofralloc
    mfspr   r3, 0x39c
    mfspr   r4, 0x39d
    mfspr   r5, 0x39e
    mfspr   r6, 0x39f
    xor     r3, r3, r4
    xor     r3, r3, r5
    xor     r3, r3, r6
    blr     
}

asm int fn_8003D4E0(register u32 a)
{
    nofralloc
    lwz     r3, -0x77ec(r13)
    li      r0, 0
    sth     r0, 0x32(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x34(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x36(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x38(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x3c(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x3a(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x40(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x3e(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x44(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x42(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x48(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x46(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x4c(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x4a(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x50(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x4e(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x54(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x52(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x58(r3)
    lwz     r3, -0x77ec(r13)
    sth     r0, 0x56(r3)
    blr     
}

asm int PerfmonCopyConfig(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    slwi    r0, r4, 2
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    add     r31, r3, r0
    addi    r3, r31, 0x90
    addi    r4, r31, 0x98
    addi    r5, r31, 0xa0
    addi    r6, r31, 0xa8
    bl      fn_80039B7C
    lwz     r3, -0x77ec(r13)
    lhz     r4, 0x32(r3)
    lhz     r0, 0x34(r3)
    rlwimi  r0, r4, 0x10, 0, 0xf
    stw     r0, 0x40(r31)
    lwz     r3, -0x77ec(r13)
    lhz     r4, 0x36(r3)
    lhz     r0, 0x38(r3)
    rlwimi  r0, r4, 0x10, 0, 0xf
    stw     r0, 0x48(r31)
    lwz     r3, -0x77ec(r13)
    lhz     r4, 0x3a(r3)
    lhz     r0, 0x3c(r3)
    rlwimi  r0, r4, 0x10, 0, 0xf
    stw     r0, 0x50(r31)
    lwz     r3, -0x77ec(r13)
    lhz     r4, 0x3e(r3)
    lhz     r0, 0x40(r3)
    rlwimi  r0, r4, 0x10, 0, 0xf
    stw     r0, 0x58(r31)
    lwz     r3, -0x77ec(r13)
    lhz     r4, 0x42(r3)
    lhz     r0, 0x44(r3)
    rlwimi  r0, r4, 0x10, 0, 0xf
    stw     r0, 0x60(r31)
    lwz     r3, -0x77ec(r13)
    lhz     r4, 0x46(r3)
    lhz     r0, 0x48(r3)
    rlwimi  r0, r4, 0x10, 0, 0xf
    stw     r0, 0x68(r31)
    lwz     r3, -0x77ec(r13)
    lhz     r4, 0x4a(r3)
    lhz     r0, 0x4c(r3)
    rlwimi  r0, r4, 0x10, 0, 0xf
    stw     r0, 0x70(r31)
    lwz     r3, -0x77ec(r13)
    lhz     r4, 0x4e(r3)
    lhz     r0, 0x50(r3)
    rlwimi  r0, r4, 0x10, 0, 0xf
    stw     r0, 0x78(r31)
    lwz     r3, -0x77ec(r13)
    lhz     r0, 0x52(r3)
    lhz     r3, 0x54(r3)
    rlwimi  r3, r0, 0x10, 0, 0xf
    stw     r3, 0x80(r31)
    lwz     r4, -0x77ec(r13)
    lhz     r3, 0x56(r4)
    lhz     r0, 0x58(r4)
    rlwimi  r0, r3, 0x10, 0, 0xf
    stw     r0, 0x88(r31)
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr     
}

asm int fn_8003D690(register u32 a)
{
    nofralloc
    stw     r3, -0x7784(r13)
    blr     
}

asm int fn_8003D698(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    clrlwi  r31, r3, 0x10
    cmplwi  r31, 0xe000
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    addi    r29, r3, 0
    blt     _8003d6dc
    lbz     r0, -0x7790(r13)
    rlwinm  r3, r31, 0x18, 0x1c, 0x1f
    cmpw    r3, r0
    bne     _8003d6dc
    lwz     r0, -0x7780(r13)
    cmpwi   r0, 0
    bne     _8003d6f8
_8003d6dc:
    lwz     r12, -0x7784(r13)
    cmplwi  r12, 0
    beq     _8003d8fc
    mtlr    r12
    addi    r3, r29, 0
    blrl    
    b       _8003d8fc
_8003d6f8:
    cmplwi  r31, 0xf000
    blt     _8003d7d4
    lwz     r0, -0x7e38(r13)
    cmplwi  r0, 0xffff
    bne     _8003d718
    bl      fn_8003E284
    bl      fn_8003E13C
    b       _8003d8fc
_8003d718:
    lwz     r0, -0x7e38(r13)
    clrlwi  r3, r31, 0x18
    addi    r29, r3, 0
    clrlwi  r0, r0, 0x18
    cmpw    r0, r3
    beq     _8003d73c
    lwz     r0, -0x7e38(r13)
    clrlwi  r0, r0, 0x18
    mr      r29, r0
_8003d73c:
    bl      PPCMfpmc4
    lwz     r0, -0x777c(r13)
    mulli   r31, r29, 0xb0
    lwz     r4, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r4, r0
    add     r4, r0, r31
    stw     r3, 0x10(r4)
    bl      PPCMfpmc3
    lwz     r0, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r4, r0
    add     r4, r0, r31
    stw     r3, 0x24(r4)
    bl      PPCMfpmc1
    lwz     r0, -0x777c(r13)
    li      r4, 1
    lwz     r5, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r5, r0
    add     r5, r0, r31
    stw     r3, 0x34(r5)
    lwz     r0, -0x777c(r13)
    lwz     r3, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r3, r0
    add     r3, r0, r31
    bl      PerfmonCopyConfig
    lwz     r0, -0x7e3c(r13)
    cmpwi   r0, 0
    blt     _8003d7c0
    bl      fn_8003E284
_8003d7c0:
    lis     r3, 1
    addi    r0, r3, -1
    stw     r0, -0x7e38(r13)
    bl      fn_8003E13C
    b       _8003d8fc
_8003d7d4:
    lwz     r0, -0x7e38(r13)
    cmplwi  r0, 0xffff
    bge     _8003d860
    lwz     r0, -0x7e38(r13)
    clrlwi  r30, r0, 0x18
    bl      PPCMfpmc4
    lwz     r0, -0x777c(r13)
    mulli   r30, r30, 0xb0
    lwz     r4, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r4, r0
    add     r4, r0, r30
    stw     r3, 0x10(r4)
    bl      PPCMfpmc3
    lwz     r0, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r4, r0
    add     r4, r0, r30
    stw     r3, 0x24(r4)
    bl      PPCMfpmc1
    lwz     r0, -0x777c(r13)
    li      r4, 1
    lwz     r5, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r5, r0
    add     r5, r0, r30
    stw     r3, 0x34(r5)
    lwz     r0, -0x777c(r13)
    lwz     r3, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r3, r0
    add     r3, r0, r30
    bl      PerfmonCopyConfig
    b       _8003d864
_8003d860:
    bl      fn_8003E284
_8003d864:
    bl      PPCMfpmc3
    lwz     r4, -0x777c(r13)
    clrlwi  r0, r31, 0x18
    lwz     r5, -0x7774(r13)
    mulli   r30, r0, 0xb0
    slwi    r0, r4, 4
    lwzx    r0, r5, r0
    add     r4, r0, r30
    stw     r3, 0x20(r4)
    bl      PPCMfpmc1
    lwz     r0, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r4, r0
    add     r4, r0, r30
    stw     r3, 0x30(r4)
    bl      PPCMfpmc4
    lwz     r0, -0x777c(r13)
    li      r4, 0
    lwz     r5, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r5, r0
    add     r5, r0, r30
    stw     r3, 0x1c(r5)
    lwz     r0, -0x777c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r5, r0
    add     r5, r0, r30
    stw     r3, 0xc(r5)
    lwz     r0, -0x777c(r13)
    lwz     r3, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r3, r0
    add     r3, r0, r30
    bl      PerfmonCopyConfig
    clrlwi  r0, r29, 0x10
    stw     r0, -0x7e38(r13)
_8003d8fc:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr     
}

asm int fn_8003D918(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x50(r1)
    stmw    r23, 0x2c(r1)
    mr      r27, r3
    addi    r26, r4, 0
    addi    r29, r5, 0
    addi    r24, r6, 0
    addi    r23, r7, 0
    addi    r30, r8, 0
    lwz     r3, -0x7e40(r13)
    bl      OSRegisterVersion
    mulli   r25, r27, 0xb0
    stw     r24, -0x778c(r13)
    stw     r23, -0x7788(r13)
    mullw   r0, r26, r25
    stw     r26, -0x7768(r13)
    stw     r29, -0x776c(r13)
    slwi    r3, r26, 4
    stw     r27, -0x7770(r13)
    addi    r12, r24, 0
    mtlr    r12
    add     r31, r3, r0
    slwi    r26, r29, 4
    add     r31, r31, r26
    blrl    
    li      r24, 0
    stw     r3, -0x7774(r13)
    addi    r23, r24, 0
    li      r27, 0
    b       _8003d9c0
_8003d994:
    lwz     r12, -0x778c(r13)
    addi    r3, r25, 0
    mtlr    r12
    blrl    
    lwz     r4, -0x7774(r13)
    addi    r0, r24, 4
    addi    r27, r27, 1
    stwx    r3, r4, r24
    addi    r24, r24, 0x10
    lwz     r3, -0x7774(r13)
    stwx    r23, r3, r0
_8003d9c0:
    lwz     r0, -0x7768(r13)
    cmplw   r27, r0
    blt     _8003d994
    lwz     r12, -0x778c(r13)
    addi    r3, r26, 0
    mtlr    r12
    blrl    
    cmplwi  r29, 0
    stw     r3, -0x7778(r13)
    li      r5, 0
    ble     _8003db18
    cmplwi  r29, 8
    addi    r3, r29, -8
    ble     _8003db38
    addi    r0, r3, 7
    srwi    r0, r0, 3
    cmplwi  r3, 0
    mtctr   r0
    addi    r4, r5, 0
    ble     _8003db38
_8003da10:
    lwz     r6, -0x7778(r13)
    li      r3, 0
    addi    r8, r4, 8
    stwx    r3, r6, r4
    li      r0, -1
    addi    r7, r4, 0x10
    lwz     r9, -0x7778(r13)
    addi    r6, r4, 0x18
    addi    r24, r4, 0x20
    stwx    r0, r9, r8
    addi    r25, r4, 0x28
    addi    r26, r4, 0x30
    lwz     r8, -0x7778(r13)
    addi    r27, r4, 0x38
    addi    r28, r4, 0x40
    stwx    r3, r8, r7
    addi    r12, r4, 0x48
    addi    r11, r4, 0x50
    lwz     r7, -0x7778(r13)
    addi    r10, r4, 0x58
    addi    r9, r4, 0x60
    stwx    r0, r7, r6
    addi    r8, r4, 0x68
    addi    r7, r4, 0x70
    lwz     r23, -0x7778(r13)
    addi    r6, r4, 0x78
    addi    r4, r4, 0x80
    stwx    r3, r23, r24
    addi    r5, r5, 8
    lwz     r24, -0x7778(r13)
    stwx    r0, r24, r25
    lwz     r25, -0x7778(r13)
    stwx    r3, r25, r26
    lwz     r26, -0x7778(r13)
    stwx    r0, r26, r27
    lwz     r27, -0x7778(r13)
    stwx    r3, r27, r28
    lwz     r28, -0x7778(r13)
    stwx    r0, r28, r12
    lwz     r12, -0x7778(r13)
    stwx    r3, r12, r11
    lwz     r11, -0x7778(r13)
    stwx    r0, r11, r10
    lwz     r10, -0x7778(r13)
    stwx    r3, r10, r9
    lwz     r9, -0x7778(r13)
    stwx    r0, r9, r8
    lwz     r8, -0x7778(r13)
    stwx    r3, r8, r7
    lwz     r3, -0x7778(r13)
    stwx    r0, r3, r6
    bdnz    _8003da10
    b       _8003db38
_8003dae4:
    subf    r0, r5, r29
    cmplw   r5, r29
    mtctr   r0
    li      r5, 0
    li      r4, -1
    bge     _8003db18
_8003dafc:
    lwz     r3, -0x7778(r13)
    addi    r0, r6, 8
    stwx    r5, r3, r6
    addi    r6, r6, 0x10
    lwz     r3, -0x7778(r13)
    stwx    r4, r3, r0
    bdnz    _8003dafc
_8003db18:
    mr      r3, r30
    bl      fn_8003E9EC
    lis     r3, fn_8003D698@ha
    addi    r3, r3, fn_8003D698@l
    bl      GXSetDrawSyncCallback
    bl      fn_80039B38
    mr      r3, r31
    b       _8003db40
_8003db38:
    slwi    r6, r5, 4
    b       _8003dae4
_8003db40:
    lmw     r23, 0x2c(r1)
    lwz     r0, 0x54(r1)
    addi    r1, r1, 0x50
    mtlr    r0
    blr     
}

asm int fn_8003DB54(register u32 a)
{
    nofralloc
    stwu    r1, -0x18(r1)
    rlwinm  r8, r3, 4, 0x14, 0x1b
    li      r6, -1
    lwz     r0, -0x7c88(r2)
    lwz     r7, -0x7778(r13)
    stw     r0, 0x14(r1)
    stwx    r4, r7, r8
    lwz     r0, -0x7778(r13)
    add     r3, r0, r8
    stw     r5, 4(r3)
    lwz     r0, -0x7778(r13)
    add     r3, r0, r8
    stw     r6, 8(r3)
    lwz     r3, -0x7778(r13)
    lwz     r0, 0x14(r1)
    add     r3, r3, r8
    stw     r0, 0xc(r3)
    addi    r1, r1, 0x18
    blr     
}

asm int fn_8003DBA0(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x10(r1)
    stw     r31, 0xc(r1)
    stw     r30, 8(r1)
    bl      OSDisableInterrupts
    li      r31, 0
    lis     r4, 1
    stw     r31, -0x7780(r13)
    addi    r0, r4, -1
    lis     r4, fn_8003D698@ha
    stw     r0, -0x7e38(r13)
    addi    r0, r4, fn_8003D698@l
    addi    r30, r3, 0
    mr      r3, r0
    bl      GXSetDrawSyncCallback
    lwz     r0, -0x777c(r13)
    lwz     r3, -0x7774(r13)
    slwi    r0, r0, 4
    add     r3, r3, r0
    stw     r31, 4(r3)
    bl      fn_8003D4E0
    bl      fn_80039AFC
    li      r3, 0
    bl      PPCMtpmc1
    li      r3, 0
    bl      PPCMtpmc2
    li      r3, 0
    bl      PPCMtpmc3
    li      r3, 0
    bl      PPCMtpmc4
    li      r3, 0x8b
    bl      PPCMtmmcr0
    lis     r3, 0x7840
    bl      PPCMtmmcr1
    bl      fn_8003E13C
    mr      r3, r30
    bl      OSRestoreInterrupts
    lwz     r0, 0x14(r1)
    lwz     r31, 0xc(r1)
    lwz     r30, 8(r1)
    addi    r1, r1, 0x10
    mtlr    r0
    blr     
}

asm int fn_8003DC50(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x10(r1)
    stw     r31, 0xc(r1)
    bl      OSDisableInterrupts
    mr      r31, r3
    bl      fn_8003E284
    lwz     r3, -0x7784(r13)
    bl      GXSetDrawSyncCallback
    bl      PPCMfpmc4
    lwz     r0, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r0, r0, 4
    add     r4, r4, r0
    stw     r3, 8(r4)
    lwz     r0, -0x777c(r13)
    lwz     r3, -0x7774(r13)
    slwi    r0, r0, 4
    lwz     r4, -0x7780(r13)
    add     r3, r3, r0
    stw     r4, 4(r3)
    bl      PPCMfpmc3
    lwz     r0, -0x777c(r13)
    li      r6, 0
    lwz     r4, -0x7774(r13)
    li      r7, 0
    slwi    r0, r0, 4
    add     r4, r4, r0
    stw     r3, 0xc(r4)
    li      r4, -1
    lwz     r5, -0x777c(r13)
    lwz     r3, -0x7768(r13)
    addi    r5, r5, 1
    stw     r6, -0x7780(r13)
    divwu   r0, r5, r3
    mullw   r0, r0, r3
    subf    r0, r0, r5
    stw     r0, -0x777c(r13)
    b       _8003dd00
_8003dcec:
    lwz     r3, -0x7778(r13)
    addi    r0, r6, 8
    addi    r7, r7, 1
    stwx    r4, r3, r0
    addi    r6, r6, 0x10
_8003dd00:
    lwz     r0, -0x776c(r13)
    cmplw   r7, r0
    blt     _8003dcec
    lbz     r3, -0x7790(r13)
    addi    r0, r3, 1
    stb     r0, -0x7790(r13)
    lbz     r0, -0x7790(r13)
    cmplwi  r0, 0x10
    blt     _8003dd2c
    li      r0, 0
    stb     r0, -0x7790(r13)
_8003dd2c:
    mr      r3, r31
    bl      OSRestoreInterrupts
    lwz     r0, 0x14(r1)
    lwz     r31, 0xc(r1)
    addi    r1, r1, 0x10
    mtlr    r0
    blr     
}

asm int fn_8003DD48(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    stw     r28, 0x10(r1)
    mr      r28, r3
    bl      OSDisableInterrupts
    lwz     r0, -0x7778(r13)
    rlwinm  r5, r28, 4, 0x14, 0x1b
    addi    r29, r3, 0
    add     r4, r0, r5
    lwzu    r0, 8(r4)
    cmpwi   r0, 0
    bge     _8003dfc0
    lwz     r3, -0x7770(r13)
    lwz     r0, -0x7780(r13)
    addi    r3, r3, -1
    cmplw   r0, r3
    blt     _8003dda8
    stw     r3, -0x7780(r13)
    lwz     r31, -0x7780(r13)
    b       _8003ddb4
_8003dda8:
    lwz     r31, -0x7780(r13)
    addi    r0, r31, 1
    stw     r0, -0x7780(r13)
_8003ddb4:
    stw     r31, 0(r4)
    mulli   r30, r31, 0xb0
    lwz     r3, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    li      r0, 0
    slwi    r3, r3, 4
    lwzx    r3, r4, r3
    stbx    r28, r3, r30
    lwz     r3, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r3, r3, 4
    lwzx    r3, r4, r3
    add     r3, r3, r30
    stw     r0, 0x14(r3)
    lwz     r3, -0x7778(r13)
    add     r3, r3, r5
    lwz     r3, 4(r3)
    cmpwi   r3, 1
    beq     _8003de98
    bge     _8003de10
    cmpwi   r3, 0
    bge     _8003df1c
    b       _8003dfa8
_8003de10:
    cmpwi   r3, 3
    bge     _8003dfa8
    lwz     r4, -0x777c(r13)
    clrlwi  r3, r31, 0x10
    lwz     r5, -0x7774(r13)
    addis   r3, r3, 1
    slwi    r4, r4, 4
    lwzx    r4, r5, r4
    add     r4, r4, r30
    stw     r0, 0x20(r4)
    lwz     r4, -0x777c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r4, r4, 4
    lwzx    r4, r5, r4
    add     r4, r4, r30
    stw     r0, 0x30(r4)
    lwz     r4, -0x777c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r4, r4, 4
    lwzx    r4, r5, r4
    add     r4, r4, r30
    stw     r0, 0xc(r4)
    lwz     r4, -0x777c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r4, r4, 4
    lwzx    r4, r5, r4
    add     r4, r4, r30
    stw     r0, 0x10(r4)
    lbz     r0, -0x7790(r13)
    rlwinm  r0, r0, 8, 0x10, 0x17
    add     r3, r3, r0
    addi    r3, r3, -0x2000
    bl      GXSetDrawSync
    b       _8003dfd0
_8003de98:
    lwz     r3, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r3, r3, 4
    lwzx    r3, r4, r3
    add     r3, r3, r30
    stw     r0, 0xc(r3)
    lwz     r3, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r3, r3, 4
    lwzx    r3, r4, r3
    add     r3, r3, r30
    stw     r0, 0x10(r3)
    bl      PPCMfpmc3
    lwz     r0, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r4, r0
    add     r4, r0, r30
    stw     r3, 0x20(r4)
    bl      PPCMfpmc1
    lwz     r0, -0x777c(r13)
    clrlwi  r4, r31, 0x10
    lwz     r5, -0x7774(r13)
    addis   r4, r4, 1
    slwi    r0, r0, 4
    lwzx    r0, r5, r0
    add     r5, r0, r30
    stw     r3, 0x30(r5)
    lbz     r0, -0x7790(r13)
    rlwinm  r0, r0, 8, 0x10, 0x17
    add     r3, r4, r0
    addi    r3, r3, -0x2000
    bl      GXSetDrawSync
_8003df1c:
    bl      PPCMfpmc3
    lwz     r0, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r4, r0
    add     r4, r0, r30
    stw     r3, 0x28(r4)
    bl      PPCMfpmc1
    lwz     r0, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r4, r0
    add     r4, r0, r30
    stw     r3, 0x38(r4)
    bl      PPCMfpmc4
    lwz     r0, -0x777c(r13)
    li      r4, 0
    lwz     r5, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r5, r0
    add     r5, r0, r30
    stw     r3, 4(r5)
    lwz     r0, -0x777c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r5, r0
    add     r5, r0, r30
    stw     r3, 0x18(r5)
    lwz     r0, -0x777c(r13)
    lwz     r3, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r3, r0
    add     r3, r0, r30
    stw     r4, 8(r3)
    b       _8003dfd0
_8003dfa8:
    lis     r3, perf_unknown_event_str@ha
    crxor   6, 6, 6
    addi    r3, r3, perf_unknown_event_str@l
    clrlwi  r4, r28, 0x18
    bl      OSReport
    b       _8003dfd0
_8003dfc0:
    lis     r3, perf_event_still_open_cpu_str@ha
    crxor   6, 6, 6
    addi    r3, r3, perf_event_still_open_cpu_str@l
    bl      OSReport
_8003dfd0:
    mr      r3, r29
    bl      OSRestoreInterrupts
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    lwz     r28, 0x10(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr     
}

asm int fn_8003DFF8(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    mr      r29, r3
    bl      OSDisableInterrupts
    lwz     r0, -0x7778(r13)
    rlwinm  r31, r29, 4, 0x14, 0x1b
    addi    r30, r3, 0
    add     r4, r0, r31
    lwz     r29, 8(r4)
    cmpwi   r29, 0
    bge     _8003e050
    lis     r3, perf_end_never_started_str@ha
    crxor   6, 6, 6
    addi    r3, r3, perf_end_never_started_str@l
    bl      OSReport
    mr      r3, r30
    bl      OSRestoreInterrupts
    b       _8003e120
_8003e050:
    lwz     r0, 4(r4)
    cmpwi   r0, 1
    beq     _8003e094
    bge     _8003e06c
    cmpwi   r0, 0
    bge     _8003e0b0
    b       _8003e108
_8003e06c:
    cmpwi   r0, 3
    bge     _8003e108
    lbz     r0, -0x7790(r13)
    clrlwi  r3, r29, 0x10
    addis   r3, r3, 1
    rlwinm  r0, r0, 8, 0x10, 0x17
    add     r3, r3, r0
    addi    r3, r3, -0x1000
    bl      GXSetDrawSync
    b       _8003e108
_8003e094:
    lbz     r0, -0x7790(r13)
    clrlwi  r3, r29, 0x10
    addis   r3, r3, 1
    rlwinm  r0, r0, 8, 0x10, 0x17
    add     r3, r3, r0
    addi    r3, r3, -0x1000
    bl      GXSetDrawSync
_8003e0b0:
    bl      PPCMfpmc4
    lwz     r0, -0x777c(r13)
    mulli   r29, r29, 0xb0
    lwz     r4, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r4, r0
    add     r4, r0, r29
    stw     r3, 8(r4)
    bl      PPCMfpmc3
    lwz     r0, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r4, r0
    add     r4, r0, r29
    stw     r3, 0x2c(r4)
    bl      PPCMfpmc1
    lwz     r0, -0x777c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r0, r0, 4
    lwzx    r0, r4, r0
    add     r4, r0, r29
    stw     r3, 0x3c(r4)
_8003e108:
    lwz     r0, -0x7778(r13)
    li      r5, -1
    addi    r3, r30, 0
    add     r4, r0, r31
    stw     r5, 8(r4)
    bl      OSRestoreInterrupts
_8003e120:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr     
}

asm int fn_8003E13C(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x10(r1)
    stw     r31, 0xc(r1)
    lwz     r3, -0x7770(r13)
    lwz     r0, -0x7780(r13)
    addi    r3, r3, -1
    cmplw   r0, r3
    blt     _8003e16c
    stw     r3, -0x7780(r13)
    lwz     r3, -0x7780(r13)
    b       _8003e178
_8003e16c:
    lwz     r3, -0x7780(r13)
    addi    r0, r3, 1
    stw     r0, -0x7780(r13)
_8003e178:
    stw     r3, -0x7e3c(r13)
    li      r5, 0xff
    lwz     r3, -0x777c(r13)
    li      r31, 0
    lwz     r0, -0x7e3c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r3, r3, 4
    mulli   r0, r0, 0xb0
    lwzx    r3, r4, r3
    stbx    r5, r3, r0
    li      r4, 0
    lwz     r3, -0x777c(r13)
    lwz     r0, -0x7e3c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r3, r3, 4
    mulli   r0, r0, 0xb0
    lwzx    r3, r5, r3
    add     r3, r3, r0
    stw     r31, 0x14(r3)
    lwz     r3, -0x777c(r13)
    lwz     r0, -0x7e3c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r3, r3, 4
    mulli   r0, r0, 0xb0
    lwzx    r3, r5, r3
    add     r3, r3, r0
    bl      PerfmonCopyConfig
    bl      PPCMfpmc4
    lwz     r4, -0x777c(r13)
    lwz     r0, -0x7e3c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r4, r4, 4
    mulli   r0, r0, 0xb0
    lwzx    r4, r5, r4
    add     r4, r4, r0
    stw     r3, 0xc(r4)
    lwz     r3, -0x777c(r13)
    lwz     r0, -0x7e3c(r13)
    lwz     r4, -0x7774(r13)
    slwi    r3, r3, 4
    mulli   r0, r0, 0xb0
    lwzx    r3, r4, r3
    add     r3, r3, r0
    stw     r31, 0x10(r3)
    bl      PPCMfpmc3
    lwz     r4, -0x777c(r13)
    lwz     r0, -0x7e3c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r4, r4, 4
    mulli   r0, r0, 0xb0
    lwzx    r4, r5, r4
    add     r4, r4, r0
    stw     r3, 0x20(r4)
    bl      PPCMfpmc1
    lwz     r4, -0x777c(r13)
    lwz     r0, -0x7e3c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r4, r4, 4
    mulli   r0, r0, 0xb0
    lwzx    r4, r5, r4
    add     r4, r4, r0
    stw     r3, 0x30(r4)
    lwz     r0, 0x14(r1)
    lwz     r31, 0xc(r1)
    addi    r1, r1, 0x10
    mtlr    r0
    blr     
}

asm int fn_8003E284(register u32 a)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -8(r1)
    lwz     r0, -0x7e3c(r13)
    cmpwi   r0, 0
    blt     _8003e32c
    bl      PPCMfpmc4
    lwz     r5, -0x777c(r13)
    li      r4, 1
    lwz     r0, -0x7e3c(r13)
    lwz     r6, -0x7774(r13)
    slwi    r5, r5, 4
    mulli   r0, r0, 0xb0
    lwzx    r5, r6, r5
    add     r5, r5, r0
    stw     r3, 0x10(r5)
    lwz     r3, -0x777c(r13)
    lwz     r0, -0x7e3c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r3, r3, 4
    mulli   r0, r0, 0xb0
    lwzx    r3, r5, r3
    add     r3, r3, r0
    bl      PerfmonCopyConfig
    bl      PPCMfpmc3
    lwz     r4, -0x777c(r13)
    lwz     r0, -0x7e3c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r4, r4, 4
    mulli   r0, r0, 0xb0
    lwzx    r4, r5, r4
    add     r4, r4, r0
    stw     r3, 0x24(r4)
    bl      PPCMfpmc1
    lwz     r4, -0x777c(r13)
    lwz     r0, -0x7e3c(r13)
    lwz     r5, -0x7774(r13)
    slwi    r4, r4, 4
    mulli   r0, r0, 0xb0
    lwzx    r4, r5, r4
    add     r4, r4, r0
    stw     r3, 0x34(r4)
_8003e32c:
    li      r0, -1
    stw     r0, -0x7e3c(r13)
    lwz     r0, 0xc(r1)
    addi    r1, r1, 8
    mtlr    r0
    blr     
}

#pragma pop
