typedef int BOOL;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned short u16;

extern s32 __OSReadROM(s32 arg0, s32 arg1, s32 arg2);
extern s32 fn_8000CAC8(s32 code);
extern void fn_8000CC64(void* dst, void* src);
extern u16 fn_8000CDD8(void);
extern void fn_8000CE30(u8* dest, s32 size, u8* data);
extern unsigned char lbl_80122F50[];
extern unsigned char lbl_801230D0[];

/* SDA displacement notes:
   lbl_801A6438 (.sdata) -> -0x7F88(r13)
   lbl_801A6798 (.sbss)  -> -0x7C28(r13)
   lbl_801A679C (.sbss)  -> -0x7C24(r13)
   lbl_801A67A0 (.sbss)  -> -0x7C20(r13)
   lbl_801A67A4 (.sbss)  -> -0x7C1C(r13)
   lbl_801A6F40 (.sdata2)-> -0x7F00(r2)
   lbl_801A6F44 (.sdata2)-> -0x7EFC(r2) */

#pragma push
#pragma force_active on

asm s32 fn_8000CAC8(register s32 code)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    mr      r31, r3
    bl      fn_8000CDD8
    clrlwi  r0, r3, 16
    cmplwi  r0, 1
    bne     Yay0Idx_noStream
    clrlwi  r0, r31, 16
    cmplwi  r0, 0x20
    blt     Yay0Idx_range2
    cmplwi  r0, 0xDF
    bgt     Yay0Idx_range2
    lis     r3, lbl_80122F50@ha
    addi    r3, r3, lbl_80122F50@l
    slwi    r0, r0, 1
    add     r3, r3, r0
    lhz     r3, -0x40(r3)
    b       Yay0Idx_done
Yay0Idx_range2:
    clrlwi  r0, r31, 16
    cmplwi  r0, 0x889E
    ble     Yay0Idx_range3
    cmplwi  r0, 0x9872
    bgt     Yay0Idx_range3
    srawi   r3, r0, 8
    clrlwi  r4, r0, 24
    subi    r0, r3, 0x88
    cmplwi  r4, 0x40
    mulli   r5, r0, 0xBC
    li      r3, 0
    addi    r0, r3, 0
    blt     Yay0Idx_chkHi
    cmplwi  r4, 0xFC
    bgt     Yay0Idx_chkHi
    li      r0, 1
Yay0Idx_chkHi:
    cmpwi   r0, 0
    beq     Yay0Idx_retZero1
    clrlwi  r0, r4, 24
    cmplwi  r0, 0x7F
    beq     Yay0Idx_retZero1
    li      r3, 1
Yay0Idx_retZero1:
    cmpwi   r3, 0
    bne     Yay0Idx_calc1
    li      r3, 0
    b       Yay0Idx_done
Yay0Idx_calc1:
    subi    r3, r4, 0x40
    cmpwi   r3, 0x40
    blt     Yay0Idx_addBase1
    subi    r3, r3, 1
Yay0Idx_addBase1:
    addi    r3, r3, 0x2BE
    add     r3, r5, r3
    b       Yay0Idx_done
Yay0Idx_range3:
    clrlwi  r0, r31, 16
    cmplwi  r0, 0x8140
    blt     Yay0Idx_retZero2
    cmplwi  r0, 0x879E
    bge     Yay0Idx_retZero2
    srawi   r3, r0, 8
    clrlwi  r4, r0, 24
    subi    r0, r3, 0x81
    cmplwi  r4, 0x40
    mulli   r5, r0, 0xBC
    li      r3, 0
    addi    r0, r3, 0
    blt     Yay0Idx_chkHi2
    cmplwi  r4, 0xFC
    bgt     Yay0Idx_chkHi2
    li      r0, 1
Yay0Idx_chkHi2:
    cmpwi   r0, 0
    beq     Yay0Idx_retZero3
    clrlwi  r0, r4, 24
    cmplwi  r0, 0x7F
    beq     Yay0Idx_retZero3
    li      r3, 1
Yay0Idx_retZero3:
    cmpwi   r3, 0
    bne     Yay0Idx_calc2
    li      r3, 0
    b       Yay0Idx_done
Yay0Idx_calc2:
    subi    r3, r4, 0x40
    cmpwi   r3, 0x40
    blt     Yay0Idx_addBase2
    subi    r3, r3, 1
Yay0Idx_addBase2:
    add     r0, r5, r3
    lis     r3, lbl_801230D0@ha
    slwi    r4, r0, 1
    addi    r3, r3, lbl_801230D0@l
    add     r3, r0, r4
    lhz     r3, 0(r3)
    b       Yay0Idx_done
Yay0Idx_noStream:
    clrlwi  r3, r31, 16
    cmplwi  r3, 0x20
    ble     Yay0Idx_retZero2
    cmplwi  r3, 0xFF
    bgt     Yay0Idx_retZero2
    subi    r3, r3, 0x20
    b       Yay0Idx_done
Yay0Idx_retZero2:
    li      r3, 0
Yay0Idx_done:
    lwz     r0, 0x1C(r1)
    lwz     r31, 0x14(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

asm void fn_8000CC64(register void* dst, register void* src)
{
    nofralloc
    stwu    r1, -0x20(r1)
    addi    r6, r3, 0x10
    li      r10, 0
    stw     r31, 0x1C(r1)
    stw     r30, 0x18(r1)
    li      r30, 0
    stw     r29, 0x14(r1)
    lwz     r31, 4(r3)
    lwz     r11, 8(r3)
    lwz     r12, 0xC(r3)
Yay0Dec_loop:
    cmplwi  r30, 0
    bne     Yay0Dec_haveGroup
    lwz     r29, 0(r6)
    li      r30, 0x20
    addi    r6, r6, 4
Yay0Dec_haveGroup:
    clrrwi. r0, r29, 31
    beq     Yay0Dec_backref
    mr      r0, r12
    lbzx    r5, r3, r0
    mr      r0, r10
    addi    r10, r10, 1
    stbx    r5, r4, r0
    addi    r12, r12, 1
    b       Yay0Dec_endIter
Yay0Dec_backref:
    add     r7, r3, r11
    lbz     r5, 0(r7)
    addi    r11, r11, 2
    lbz     r0, 1(r7)
    rlwimi  r0, r5, 8, 16, 23
    srawi.  r5, r0, 12
    clrlwi  r0, r0, 20
    subf    r9, r0, r10
    bne     Yay0Dec_nzCount
    mr      r0, r12
    lbzx    r5, r3, r0
    addi    r12, r12, 1
    addi    r0, r5, 0x12
    b       Yay0Dec_haveLen
Yay0Dec_nzCount:
    addi    r0, r5, 2
Yay0Dec_haveLen:
    cmpwi   r0, 0
    mr      r5, r0
    add     r7, r4, r10
    ble     Yay0Dec_endIter
    srwi.   r0, r5, 3
    mtctr   r0
    beq     Yay0Dec_tailBits
Yay0Dec_copy8:
    subi    r8, r9, 1
    lbzx    r0, r4, r8
    addi    r8, r9, 0
    addi    r10, r10, 8
    stb     r0, 0(r7)
    lbzx    r0, r4, r8
    addi    r8, r9, 1
    stb     r0, 1(r7)
    lbzx    r0, r4, r8
    addi    r8, r9, 2
    stb     r0, 2(r7)
    lbzx    r0, r4, r8
    addi    r8, r9, 3
    stb     r0, 3(r7)
    lbzx    r0, r4, r8
    addi    r8, r9, 4
    stb     r0, 4(r7)
    lbzx    r0, r4, r8
    addi    r8, r9, 5
    stb     r0, 5(r7)
    lbzx    r0, r4, r8
    addi    r8, r9, 6
    addi    r9, r9, 8
    stb     r0, 6(r7)
    lbzx    r0, r4, r8
    stb     r0, 7(r7)
    addi    r7, r7, 8
    bdnz    Yay0Dec_copy8
    andi.   r5, r5, 7
    beq     Yay0Dec_endIter
Yay0Dec_tailBits:
    mtctr   r5
Yay0Dec_copy1:
    subi    r8, r9, 1
    lbzx    r0, r4, r8
    addi    r10, r10, 1
    addi    r9, r9, 1
    stb     r0, 0(r7)
    addi    r7, r7, 1
    bdnz    Yay0Dec_copy1
Yay0Dec_endIter:
    cmpw    r10, r31
    slwi    r29, r29, 1
    subi    r30, r30, 1
    blt     Yay0Dec_loop
    lwz     r31, 0x1C(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    addi    r1, r1, 0x20
    blr
}

asm u16 fn_8000CDD8(void)
{
    nofralloc
    lhz     r3, -0x7F88(r13)
    cmplwi  r3, 1
    blelr
    lis     r3, 0x8000
    lwz     r0, 0xCC(r3)
    cmpwi   r0, 0
    beq     Yay0Ready_readHW
    blt     Yay0Ready_clear
    b       Yay0Ready_clear
Yay0Ready_readHW:
    lis     r3, 0xCC00
    lhz     r0, 0x206E(r3)
    rlwinm. r0, r0, 0, 30, 30
    beq     Yay0Ready_setZero
    li      r0, 1
    b       Yay0Ready_store
Yay0Ready_setZero:
    li      r0, 0
Yay0Ready_store:
    sth     r0, -0x7F88(r13)
    b       Yay0Ready_return
Yay0Ready_clear:
    li      r0, 0
    sth     r0, -0x7F88(r13)
Yay0Ready_return:
    lhz     r3, -0x7F88(r13)
    blr
}

asm void fn_8000CE30(register u8* dest, register s32 size, register u8* data)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x28(r1)
    stw     r31, 0x24(r1)
    stw     r30, 0x20(r1)
    addi    r30, r5, 0
    stw     r29, 0x1C(r1)
    addi    r29, r4, 0
    stw     r28, 0x18(r1)
    addi    r28, r3, 0
    b       Yay0Write_check
Yay0Write_clamp:
    cmpwi   r29, 0x100
    bgt     Yay0Write_cap
    mr      r31, r29
    b       Yay0Write_sub
Yay0Write_cap:
    li      r31, 0x100
Yay0Write_sub:
    subf    r29, r31, r29
Yay0Write_retry:
    addi    r3, r28, 0
    addi    r4, r31, 0
    addi    r5, r30, 0
    bl      __OSReadROM
    cmpwi   r3, 0
    beq     Yay0Write_retry
    add     r30, r30, r31
    add     r28, r28, r31
Yay0Write_check:
    cmpwi   r29, 0
    bgt     Yay0Write_clamp
    lwz     r0, 0x2C(r1)
    lwz     r31, 0x24(r1)
    lwz     r30, 0x20(r1)
    lwz     r29, 0x1C(r1)
    lwz     r28, 0x18(r1)
    addi    r1, r1, 0x28
    mtlr    r0
    blr
}

asm s32 fn_8000CEBC(register u8* arcData, register void* work)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    li      r0, 0
    stwu    r1, -0x40(r1)
    stw     r31, 0x3C(r1)
    stw     r30, 0x38(r1)
    addi    r30, r4, 0
    stw     r29, 0x34(r1)
    addi    r29, r3, 0
    stw     r0, -0x7C24(r13)
    bl      fn_8000CDD8
    clrlwi  r0, r3, 16
    cmplwi  r0, 1
    bne     Yay0Arc_notStreaming
    lis     r4, 0x5
    lis     r5, 0x1B
    addi    r3, r30, 0
    subi    r4, r4, 0x3000
    subi    r5, r5, 0x100
    bl      fn_8000CE30
    b       Yay0Arc_headerDone
Yay0Arc_notStreaming:
    lis     r4, 0x20
    addi    r3, r30, 0
    subi    r5, r4, 0x3100
    li      r4, 0x3000
    bl      fn_8000CE30
Yay0Arc_headerDone:
    lbz     r0, 0(r30)
    cmplwi  r0, 0x59
    bne     Yay0Arc_badMagic
    lbz     r0, 1(r30)
    cmplwi  r0, 0x61
    bne     Yay0Arc_badMagic
    lbz     r0, 2(r30)
    cmplwi  r0, 0x79
    bne     Yay0Arc_badMagic
    lwz     r31, 4(r30)
    b       Yay0Arc_gotSize
Yay0Arc_badMagic:
    li      r31, 0
Yay0Arc_gotSize:
    cmplwi  r31, 0
    beq     Yay0Arc_exit
    addi    r3, r30, 0
    addi    r4, r29, 0
    bl      fn_8000CC64
    stw     r29, -0x7C28(r13)
    lhz     r4, -0x7F88(r13)
    lhz     r0, 0x22(r29)
    cmplwi  r4, 1
    add     r0, r29, r0
    stw     r0, -0x7C20(r13)
    lhz     r3, 0x1A(r29)
    lhz     r0, 0x1C(r29)
    mullw   r0, r3, r0
    stw     r0, -0x7C1C(r13)
    bgt     Yay0Arc_streaming
    b       Yay0Arc_readyCheck
Yay0Arc_streaming:
    lis     r3, 0x8000
    lwz     r0, 0xCC(r3)
    cmpwi   r0, 0
    beq     Yay0Arc_readVI
    blt     Yay0Arc_clearReady
    b       Yay0Arc_clearReady
Yay0Arc_readVI:
    lis     r3, 0xCC00
    lhz     r0, 0x206E(r3)
    rlwinm. r0, r0, 0, 30, 30
    beq     Yay0Arc_setReady
    li      r0, 1
    b       Yay0Arc_storeReady
Yay0Arc_setReady:
    li      r0, 0
Yay0Arc_storeReady:
    sth     r0, -0x7F88(r13)
    b       Yay0Arc_afterReady
Yay0Arc_clearReady:
    li      r0, 0
    sth     r0, -0x7F88(r13)
Yay0Arc_afterReady:
    lhz     r4, -0x7F88(r13)
Yay0Arc_readyCheck:
    clrlwi  r0, r4, 16
    cmplwi  r0, 1
    bne     Yay0Arc_exit
    lwz     r4, -0x7F00(r2)
    li      r3, 0x54
    lwz     r0, -0x7EFC(r2)
    stw     r4, 0x1C(r1)
    stw     r0, 0x20(r1)
    bl      fn_8000CAC8
    lwz     r5, -0x7C1C(r13)
    lwz     r12, -0x7C28(r13)
    divw    r10, r3, r5
    lhz     r6, 0x1C(r1)
    lhz     r0, 0x1E(r12)
    lwz     r4, 0x14(r12)
    lwz     r11, 0x24(r12)
    mullw   r8, r10, r5
    lhz     r9, 0x1A(r12)
    lhz     r5, 0x12(r12)
    lhz     r7, 0x10(r12)
    subf    r30, r8, r3
    divw    r8, r30, r9
    mullw   r3, r8, r9
    mullw   r5, r8, r5
    srawi   r0, r0, 3
    subf    r3, r3, r30
    addze   r0, r0
    slwi    r0, r0, 5
    srawi   r9, r0, 1
    mullw   r10, r10, r4
    mullw   r3, r3, r7
    addze   r9, r9
    addi    r0, r5, 4
    srawi   r4, r0, 3
    addze   r4, r4
    srawi   r8, r3, 3
    addze   r8, r8
    srawi   r7, r0, 3
    addze   r7, r7
    slwi    r7, r7, 3
    subfc   r7, r7, r0
    srawi   r0, r3, 3
    addze   r0, r0
    slwi    r0, r0, 3
    subfc   r0, r0, r3
    srawi   r3, r0, 2
    mullw   r0, r9, r4
    add     r4, r12, r11
    srwi    r9, r10, 1
    add     r4, r4, r9
    add     r9, r4, r0
    slwi    r0, r8, 4
    add     r9, r9, r0
    slwi    r7, r7, 1
    add     r9, r9, r7
    addze   r3, r3
    add     r9, r9, r3
    sth     r6, 0(r9)
    addi    r10, r5, 5
    addi    r9, r5, 6
    lwz     r7, -0x7C28(r13)
    addi    r6, r5, 7
    lhz     r5, 0x1E(r1)
    lhz     r7, 0x1E(r7)
    srawi   r7, r7, 3
    addze   r7, r7
    slwi    r7, r7, 5
    srawi   r8, r7, 1
    addze   r8, r8
    srawi   r7, r10, 3
    addze   r7, r7
    mullw   r8, r8, r7
    srawi   r7, r10, 3
    addze   r7, r7
    slwi    r7, r7, 3
    add     r8, r4, r8
    subfc   r7, r7, r10
    add     r8, r8, r0
    slwi    r7, r7, 1
    add     r8, r8, r7
    add     r8, r8, r3
    sth     r5, 0(r8)
    lwz     r7, -0x7C28(r13)
    lhz     r5, 0x20(r1)
    lhz     r7, 0x1E(r7)
    srawi   r7, r7, 3
    addze   r7, r7
    slwi    r7, r7, 5
    srawi   r8, r7, 1
    addze   r8, r8
    srawi   r7, r9, 3
    addze   r7, r7
    mullw   r8, r8, r7
    srawi   r7, r9, 3
    addze   r7, r7
    slwi    r7, r7, 3
    add     r8, r4, r8
    subfc   r7, r7, r9
    add     r8, r8, r0
    slwi    r7, r7, 1
    add     r8, r8, r7
    add     r8, r8, r3
    sth     r5, 0(r8)
    lwz     r5, -0x7C28(r13)
    lhz     r5, 0x1E(r5)
    srawi   r5, r5, 3
    addze   r5, r5
    slwi    r5, r5, 5
    srawi   r7, r5, 1
    addze   r7, r7
    srawi   r5, r6, 3
    addze   r5, r5
    mullw   r5, r7, r5
    add     r7, r4, r5
    srawi   r5, r6, 3
    lhz     r4, 0x22(r1)
    addze   r5, r5
    slwi    r5, r5, 3
    subfc   r5, r5, r6
    add     r7, r7, r0
    slwi    r0, r5, 1
    add     r7, r7, r0
    add     r7, r7, r3
    sth     r4, 0(r7)
Yay0Arc_exit:
    mr      r3, r31
    lwz     r0, 0x44(r1)
    lwz     r31, 0x3C(r1)
    lwz     r30, 0x38(r1)
    lwz     r29, 0x34(r1)
    addi    r1, r1, 0x40
    mtlr    r0
    blr
}

asm char* fn_8000D1F0(register char* stream, register u8* texBuffer,
                      register u8* palette, register s32 param6,
                      register void* outParam)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x60(r1)
    stmw    r17, 0x24(r1)
    mr      r28, r3
    addi    r29, r4, 0
    addi    r30, r5, 0
    addi    r24, r6, 0
    addi    r31, r7, 0
    lbz     r0, 0(r3)
    cmplwi  r0, 0
    mr      r3, r0
    bne     Yay0Draw_haveCmd
    mr      r3, r28
    b       Yay0Draw_exit
Yay0Draw_haveCmd:
    lhz     r0, -0x7F88(r13)
    addi    r28, r28, 1
    cmplwi  r0, 1
    bgt     Yay0Draw_pollReady
    b       Yay0Draw_checkReady
Yay0Draw_pollReady:
    lis     r4, 0x8000
    lwz     r0, 0xCC(r4)
    cmpwi   r0, 0
    beq     Yay0Draw_readVI
    blt     Yay0Draw_clearReady
    b       Yay0Draw_clearReady
Yay0Draw_readVI:
    lis     r4, 0xCC00
    lhz     r0, 0x206E(r4)
    rlwinm. r0, r0, 0, 30, 30
    beq     Yay0Draw_setReady
    li      r0, 1
    b       Yay0Draw_storeReady
Yay0Draw_setReady:
    li      r0, 0
Yay0Draw_storeReady:
    sth     r0, -0x7F88(r13)
    b       Yay0Draw_afterReady
Yay0Draw_clearReady:
    li      r0, 0
    sth     r0, -0x7F88(r13)
Yay0Draw_afterReady:
    lhz     r0, -0x7F88(r13)
Yay0Draw_checkReady:
    clrlwi  r0, r0, 16
    cmplwi  r0, 1
    bne     Yay0Draw_setup
    clrlwi  r0, r3, 24
    cmplwi  r0, 0x81
    li      r4, 1
    li      r5, 0
    blt     Yay0Draw_rangeB
    cmplwi  r0, 0x9F
    bgt     Yay0Draw_rangeB
    mr      r5, r4
Yay0Draw_rangeB:
    cmpwi   r5, 0
    bne     Yay0Draw_isRangeA
    clrlwi  r0, r3, 24
    cmplwi  r0, 0xE0
    li      r5, 0
    blt     Yay0Draw_rangeC
    cmplwi  r0, 0xFC
    bgt     Yay0Draw_rangeC
    li      r5, 1
Yay0Draw_rangeC:
    cmpwi   r5, 0
    bne     Yay0Draw_isRangeA
    li      r4, 0
Yay0Draw_isRangeA:
    cmpwi   r4, 0
    beq     Yay0Draw_setup
    lbz     r4, 0(r28)
    extsb.  r0, r4
    beq     Yay0Draw_setup
    clrlslwi r0, r3, 16, 8
    or      r3, r0, r4
    addi    r28, r28, 1
Yay0Draw_setup:
    lwz     r4, -0x7C28(r13)
    addi    r25, r4, 0x2C
    bl      fn_8000CAC8
    lwz     r6, -0x7C1C(r13)
    slwi    r0, r24, 2
    lwz     r12, -0x7C28(r13)
    srawi   r0, r0, 3
    divw    r11, r3, r6
    lwz     r4, 0x14(r12)
    lwz     r5, 0x24(r12)
    lhz     r9, 0x1A(r12)
    lhz     r7, 0x12(r12)
    mullw   r8, r11, r6
    lhz     r6, 0x10(r12)
    subf    r17, r8, r3
    divw    r10, r17, r9
    mullw   r8, r10, r9
    mullw   r4, r11, r4
    subf    r11, r8, r17
    addze   r0, r0
    mullw   r10, r10, r7
    mullw   r11, r11, r6
    add     r24, r12, r5
    srwi    r4, r4, 1
    add     r24, r24, r4
    slwi    r7, r0, 5
    li      r27, 0
    b       Yay0Draw_rowCheck
Yay0Draw_rowLoop:
    add     r4, r10, r27
    srawi   r0, r4, 3
    addze   r0, r0
    srawi   r8, r4, 3
    addze   r8, r8
    slwi    r8, r8, 3
    subfc   r8, r8, r4
    srawi   r4, r27, 3
    addze   r4, r4
    mullw   r5, r4, r7
    srawi   r6, r27, 3
    addze   r6, r6
    slwi    r6, r6, 3
    subfc   r6, r6, r27
    slwi    r4, r8, 1
    add     r5, r29, r5
    slwi    r6, r6, 2
    li      r12, 0
    b       Yay0Draw_colCheck
Yay0Draw_colLoop:
    lhz     r9, 0x1E(r9)
    add     r21, r11, r12
    add     r8, r30, r12
    srawi   r9, r9, 3
    addze   r9, r9
    slwi    r9, r9, 5
    srawi   r18, r9, 1
    addze   r18, r18
    srawi   r19, r21, 3
    addze   r19, r19
    srawi   r9, r21, 3
    addze   r9, r9
    slwi    r9, r9, 3
    subfc   r9, r9, r21
    srawi   r20, r9, 2
    addze   r20, r20
    srawi   r26, r21, 2
    addze   r26, r26
    slwi    r26, r26, 2
    subfc   r26, r26, r21
    srawi   r21, r8, 3
    addze   r21, r21
    srawi   r9, r8, 3
    addze   r9, r9
    slwi    r9, r9, 3
    mullw   r18, r18, r0
    subfc   r9, r9, r8
    srawi   r22, r9, 1
    addze   r22, r22
    srawi   r23, r8, 1
    addze   r23, r23
    slwi    r9, r21, 5
    slwi    r23, r23, 1
    add     r9, r5, r9
    add     r9, r9, r6
    add     r17, r24, r18
    slwi    r21, r19, 4
    add     r17, r17, r21
    add     r17, r17, r4
    subfc.  r23, r23, r8
    add     r17, r17, r20
    add     r9, r9, r22
    beq     Yay0Draw_hiNibble
    li      r18, 0xF
    b       Yay0Draw_merge
Yay0Draw_hiNibble:
    li      r18, 0xF0
Yay0Draw_merge:
    slwi    r8, r26, 1
    lbz     r26, 0(r17)
    subfic  r8, r8, 6
    lbz     r23, 0(r9)
    sraw    r8, r26, r8
    clrlwi  r8, r8, 30
    lbzx    r8, r25, r8
    addi    r12, r12, 1
    and     r8, r8, r18
    or      r8, r23, r8
    stb     r8, 0(r9)
Yay0Draw_colCheck:
    lwz     r9, -0x7C28(r13)
    lhz     r8, 0x10(r9)
    cmpw    r12, r8
    blt     Yay0Draw_colLoop
    addi    r27, r27, 1
Yay0Draw_rowCheck:
    lwz     r4, -0x7C28(r13)
    lhz     r0, 0x12(r4)
    cmpw    r27, r0
    blt     Yay0Draw_rowLoop
    cmplwi  r31, 0
    beq     Yay0Draw_skipOut
    lwz     r4, -0x7C20(r13)
    lbzx    r0, r4, r3
    stw     r0, 0(r31)
Yay0Draw_skipOut:
    mr      r3, r28
Yay0Draw_exit:
    lmw     r17, 0x24(r1)
    lwz     r0, 0x64(r1)
    addi    r1, r1, 0x60
    mtlr    r0
    blr
}

#pragma pop
