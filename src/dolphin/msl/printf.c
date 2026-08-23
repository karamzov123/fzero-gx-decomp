#pragma push
#pragma force_active on

int vprintf(const char* fmt, void* arg);
int fn_8008088C(void);
int fn_80080974(void);
void* __FileWrite(void* file, const char* buf, unsigned long n);
int __pformatter(void* writeProc, void* writeParam, const char* fmt, void* arg);
char* float2str(void* arg, char* buff, void* format, unsigned long* prec);
void fn_800818C8(void);
char* double2hex(void* arg, char* buff, void* format);
char* longlong2str(long long num, char* pBuf, void* format);
char* long2str(long num, char* buff, void* format);
const char* parse_format(const char* fmt, void* arg, void* format);
extern void __end_critical_region(int region);
extern void __begin_critical_region(int region);
extern int fwide(int mode, int n);
extern void* memcpy(void* dst, const void* src, unsigned long n);
extern unsigned long fwrite(const void* buf, unsigned long size, unsigned long count, void* file);
extern void* __va_arg(void* params, unsigned long size);
extern unsigned long wcstombs(char* dst, const unsigned short* src, unsigned long n);
extern void* memchr(const void* s, int c, unsigned long n);
extern char* strchr(const char* s, int c);
extern unsigned long strlen(const char* s);
extern void fn_8007C3B8(void);
extern void strcpy(void);
extern void __div2u(void);
extern void __mod2u(void);
extern unsigned char __files[320];
extern unsigned char jumptable_8015B4BC[132];
extern unsigned char jumptable_8015B540[224];
extern unsigned char jumptable_8015B620[68];
extern unsigned char lbl_8015B100[256];
void* __FileWrite(void* file, const char* buf, unsigned long n);

asm int vprintf(const char* fmt, void* arg)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r5, __files@ha
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    mr	r30, r4
    addi	r4, r5, __files@l
    stw	r29, 0x14(r1)
    addi	r31, r4, 0x50
    mr	r29, r3
    li	r4, -1
    mr	r3, r31
    bl      fwide
    cmpwi	r3, 0
    blt     _8008083c
    li	r3, -1
    b       _80080870
_8008083c:
    li	r3, 2
    bl      __begin_critical_region
    lis     r3, __FileWrite@ha
    mr	r4, r31
    addi	r3, r3, __FileWrite@l
    mr	r5, r29
    mr	r6, r30
    bl      __pformatter
    mr	r0, r3
    li	r3, 2
    mr	r31, r0
    bl      __end_critical_region
    mr	r3, r31
_80080870:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm int fn_8008088C(void)
{
    nofralloc
    stwu	r1, -0x80(r1)
    mflr	r0
    stw	r0, 0x84(r1)
    stw	r31, 0x7c(r1)
    stw	r30, 0x78(r1)
    mr	r30, r3
    bne     cr1, _800808c8
    stfd	f1, 0x28(r1)
    stfd	f2, 0x30(r1)
    stfd	f3, 0x38(r1)
    stfd	f4, 0x40(r1)
    stfd	f5, 0x48(r1)
    stfd	f6, 0x50(r1)
    stfd	f7, 0x58(r1)
    stfd	f8, 0x60(r1)
_800808c8:
    lis     r11, __files@ha
    stw	r4, 0xc(r1)
    addi	r11, r11, __files@l
    li	r4, -1
    stw	r3, 8(r1)
    addi	r31, r11, 0x50
    mr	r3, r31
    stw	r5, 0x10(r1)
    stw	r6, 0x14(r1)
    stw	r7, 0x18(r1)
    stw	r8, 0x1c(r1)
    stw	r9, 0x20(r1)
    stw	r10, 0x24(r1)
    bl      fwide
    cmpwi	r3, 0
    blt     _80080910
    li	r3, -1
    b       _8008095c
_80080910:
    li	r3, 2
    bl      __begin_critical_region
    addi	r5, r1, 0x88
    addi	r0, r1, 8
    lis	r4, 0x100
    lis     r3, __FileWrite@ha
    stw	r4, 0x68(r1)
    addi	r6, r1, 0x68
    addi	r3, r3, __FileWrite@l
    mr	r4, r31
    stw	r5, 0x6c(r1)
    mr	r5, r30
    stw	r0, 0x70(r1)
    bl      __pformatter
    mr	r0, r3
    li	r3, 2
    mr	r31, r0
    bl      __end_critical_region
    mr	r3, r31
_8008095c:
    lwz	r0, 0x84(r1)
    lwz	r31, 0x7c(r1)
    lwz	r30, 0x78(r1)
    mtlr	r0
    addi	r1, r1, 0x80
    blr	
}

asm int fn_80080974(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    mr	r30, r3
    lwz	r3, 8(r3)
    lwz	r6, 4(r30)
    add	r0, r3, r5
    cmplw	r0, r6
    subf	r31, r3, r6
    bgt     _800809a8
    mr	r31, r5
_800809a8:
    lwz	r0, 0(r30)
    mr	r5, r31
    add	r3, r0, r3
    bl      memcpy
    lwz	r0, 8(r30)
    li	r3, 1
    add	r0, r0, r31
    stw	r0, 8(r30)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void* __FileWrite(void* file, const char* buf, unsigned long n)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r5
    stw	r30, 8(r1)
    mr	r30, r3
    mr	r3, r4
    li	r4, 1
    mr	r6, r30
    bl      fwrite
    cmplw	r31, r3
    bne     _80080a1c
    mr	r3, r30
    b       _80080a20
_80080a1c:
    li	r3, 0
_80080a20:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm int __pformatter(void* writeProc, void* writeParam, const char* fmt, void* arg)
{
    nofralloc
    stwu	r1, -0x2c0(r1)
    mflr	r0
    stw	r0, 0x2c4(r1)
    li	r0, 0x20
    stmw	r19, 0x28c(r1)
    mr	r31, r3
    mr	r30, r4
    mr	r29, r6
    mr	r26, r5
    addi	r24, r1, 0x27c
    addi	r21, r1, 0x27b
    li	r27, 0
    stb	r0, 9(r1)
    b       _80081188
_80080a70:
    mr	r3, r26
    li	r4, 0x25
    bl      strchr
    or.	r25, r3, r3
    bne     _80080abc
    mr	r3, r26
    bl      strlen
    or.	r5, r3, r3
    add	r27, r27, r5
    beq     _80081194
    mr	r12, r31
    mr	r3, r30
    mr	r4, r26
    mtctr	r12
    bctrl	
    cmplwi	r3, 0
    bne     _80081194
    li	r3, -1
    b       _80081198
_80080abc:
    subf.	r5, r26, r25
    add	r27, r27, r5
    beq     _80080aec
    mr	r12, r31
    mr	r3, r30
    mr	r4, r26
    mtctr	r12
    bctrl	
    cmplwi	r3, 0
    bne     _80080aec
    li	r3, -1
    b       _80081198
_80080aec:
    mr	r3, r25
    mr	r4, r29
    addi	r5, r1, 0x6c
    bl      parse_format
    lbz	r0, 0x71(r1)
    mr	r26, r3
    cmpwi	r0, 0x68
    beq     _80081008
    bge     _80080b6c
    cmpwi	r0, 0x58
    beq     _80080cc4
    bge     _80080b48
    cmpwi	r0, 0x41
    beq     _80080e2c
    bge     _80080b34
    cmpwi	r0, 0x25
    beq     _80080ff4
    b       _80081008
_80080b34:
    cmpwi	r0, 0x48
    bge     _80081008
    cmpwi	r0, 0x45
    bge     _80080dc0
    b       _80081008
_80080b48:
    cmpwi	r0, 0x63
    beq     _80080fd4
    bge     _80080b60
    cmpwi	r0, 0x61
    beq     _80080e2c
    b       _80081008
_80080b60:
    cmpwi	r0, 0x65
    bge     _80080dc0
    b       _80080bc8
_80080b6c:
    cmpwi	r0, 0x74
    beq     _80081008
    bge     _80080ba4
    cmpwi	r0, 0x6f
    beq     _80080cc4
    bge     _80080b98
    cmpwi	r0, 0x6e
    bge     _80080f70
    cmpwi	r0, 0x6a
    bge     _80081008
    b       _80080bc8
_80080b98:
    cmpwi	r0, 0x73
    bge     _80080e98
    b       _80081008
_80080ba4:
    cmpwi	r0, 0x78
    beq     _80080cc4
    bge     _80080bbc
    cmpwi	r0, 0x76
    bge     _80081008
    b       _80080cc4
_80080bbc:
    cmpwi	r0, 0xff
    beq     _80081008
    b       _80081008
_80080bc8:
    lbz	r0, 0x70(r1)
    cmplwi	r0, 3
    bne     _80080be8
    mr	r3, r29
    li	r4, 1
    bl      __va_arg
    lwz	r28, 0(r3)
    b       _80080c18
_80080be8:
    cmplwi	r0, 4
    bne     _80080c08
    mr	r3, r29
    li	r4, 2
    bl      __va_arg
    lwz	r22, 0(r3)
    lwz	r23, 4(r3)
    b       _80080c18
_80080c08:
    mr	r3, r29
    li	r4, 1
    bl      __va_arg
    lwz	r28, 0(r3)
_80080c18:
    lbz	r3, 0x70(r1)
    cmplwi	r3, 2
    bne     _80080c2c
    extsh	r0, r28
    mr	r28, r0
_80080c2c:
    cmplwi	r3, 1
    bne     _80080c3c
    extsb	r0, r28
    mr	r28, r0
_80080c3c:
    cmplwi	r3, 4
    bne     _80080c84
    lwz	r9, 0x6c(r1)
    mr	r4, r23
    lwz	r8, 0x70(r1)
    mr	r3, r22
    lwz	r7, 0x74(r1)
    mr	r5, r24
    lwz	r0, 0x78(r1)
    addi	r6, r1, 0x5c
    stw	r9, 0x5c(r1)
    stw	r8, 0x60(r1)
    stw	r7, 0x64(r1)
    stw	r0, 0x68(r1)
    bl      longlong2str
    or.	r20, r3, r3
    beq     _80081008
    b       _80080cbc
_80080c84:
    lwz	r8, 0x6c(r1)
    mr	r3, r28
    lwz	r7, 0x70(r1)
    mr	r4, r24
    lwz	r6, 0x74(r1)
    addi	r5, r1, 0x4c
    lwz	r0, 0x78(r1)
    stw	r8, 0x4c(r1)
    stw	r7, 0x50(r1)
    stw	r6, 0x54(r1)
    stw	r0, 0x58(r1)
    bl      long2str
    or.	r20, r3, r3
    beq     _80081008
_80080cbc:
    subf	r25, r20, r21
    b       _80081048
_80080cc4:
    lbz	r0, 0x70(r1)
    cmplwi	r0, 3
    bne     _80080ce4
    mr	r3, r29
    li	r4, 1
    bl      __va_arg
    lwz	r28, 0(r3)
    b       _80080d14
_80080ce4:
    cmplwi	r0, 4
    bne     _80080d04
    mr	r3, r29
    li	r4, 2
    bl      __va_arg
    lwz	r22, 0(r3)
    lwz	r23, 4(r3)
    b       _80080d14
_80080d04:
    mr	r3, r29
    li	r4, 1
    bl      __va_arg
    lwz	r28, 0(r3)
_80080d14:
    lbz	r3, 0x70(r1)
    cmplwi	r3, 2
    bne     _80080d28
    clrlwi	r0, r28, 0x10
    mr	r28, r0
_80080d28:
    cmplwi	r3, 1
    bne     _80080d38
    clrlwi	r0, r28, 0x18
    mr	r28, r0
_80080d38:
    cmplwi	r3, 4
    bne     _80080d80
    lwz	r9, 0x6c(r1)
    mr	r4, r23
    lwz	r8, 0x70(r1)
    mr	r3, r22
    lwz	r7, 0x74(r1)
    mr	r5, r24
    lwz	r0, 0x78(r1)
    addi	r6, r1, 0x3c
    stw	r9, 0x3c(r1)
    stw	r8, 0x40(r1)
    stw	r7, 0x44(r1)
    stw	r0, 0x48(r1)
    bl      longlong2str
    or.	r20, r3, r3
    beq     _80081008
    b       _80080db8
_80080d80:
    lwz	r8, 0x6c(r1)
    mr	r3, r28
    lwz	r7, 0x70(r1)
    mr	r4, r24
    lwz	r6, 0x74(r1)
    addi	r5, r1, 0x2c
    lwz	r0, 0x78(r1)
    stw	r8, 0x2c(r1)
    stw	r7, 0x30(r1)
    stw	r6, 0x34(r1)
    stw	r0, 0x38(r1)
    bl      long2str
    or.	r20, r3, r3
    beq     _80081008
_80080db8:
    subf	r25, r20, r21
    b       _80081048
_80080dc0:
    lbz	r0, 0x70(r1)
    cmplwi	r0, 5
    bne     _80080de0
    mr	r3, r29
    li	r4, 3
    bl      __va_arg
    lfd	f1, 0(r3)
    b       _80080df0
_80080de0:
    mr	r3, r29
    li	r4, 3
    bl      __va_arg
    lfd	f1, 0(r3)
_80080df0:
    lwz	r7, 0x6c(r1)
    mr	r3, r24
    lwz	r6, 0x70(r1)
    addi	r4, r1, 0x1c
    lwz	r5, 0x74(r1)
    lwz	r0, 0x78(r1)
    stw	r7, 0x1c(r1)
    stw	r6, 0x20(r1)
    stw	r5, 0x24(r1)
    stw	r0, 0x28(r1)
    bl      float2str
    or.	r20, r3, r3
    beq     _80081008
    subf	r25, r20, r21
    b       _80081048
_80080e2c:
    lbz	r0, 0x70(r1)
    cmplwi	r0, 5
    bne     _80080e4c
    mr	r3, r29
    li	r4, 3
    bl      __va_arg
    lfd	f1, 0(r3)
    b       _80080e5c
_80080e4c:
    mr	r3, r29
    li	r4, 3
    bl      __va_arg
    lfd	f1, 0(r3)
_80080e5c:
    lwz	r7, 0x6c(r1)
    mr	r3, r24
    lwz	r6, 0x70(r1)
    addi	r4, r1, 0xc
    lwz	r5, 0x74(r1)
    lwz	r0, 0x78(r1)
    stw	r7, 0xc(r1)
    stw	r6, 0x10(r1)
    stw	r5, 0x14(r1)
    stw	r0, 0x18(r1)
    bl      double2hex
    or.	r20, r3, r3
    beq     _80081008
    subf	r25, r20, r21
    b       _80081048
_80080e98:
    lbz	r0, 0x70(r1)
    cmplwi	r0, 6
    bne     _80080edc
    mr	r3, r29
    li	r4, 1
    bl      __va_arg
    lwz	r4, 0(r3)
    cmplwi	r4, 0
    bne     _80080ec0
    addi	r4, r13, -0x7d90
_80080ec0:
    addi	r3, r1, 0x7c
    li	r5, 0x200
    bl      wcstombs
    cmpwi	r3, 0
    blt     _80081008
    addi	r20, r1, 0x7c
    b       _80080eec
_80080edc:
    mr	r3, r29
    li	r4, 1
    bl      __va_arg
    lwz	r20, 0(r3)
_80080eec:
    cmplwi	r20, 0
    bne     _80080efc
    lis	r3, -0x7ff7
    addi	r20, r3, 0x4fc0
_80080efc:
    lbz	r0, 0x6f(r1)
    cmplwi	r0, 0
    beq     _80080f30
    lbz	r0, 0x6e(r1)
    lbz	r25, 0(r20)
    addi	r20, r20, 1
    cmplwi	r0, 0
    beq     _80081048
    lwz	r0, 0x78(r1)
    cmpw	r25, r0
    ble     _80081048
    mr	r25, r0
    b       _80081048
_80080f30:
    lbz	r0, 0x6e(r1)
    cmplwi	r0, 0
    beq     _80080f60
    lwz	r25, 0x78(r1)
    mr	r3, r20
    li	r4, 0
    mr	r5, r25
    bl      memchr
    cmplwi	r3, 0
    beq     _80081048
    subf	r25, r20, r3
    b       _80081048
_80080f60:
    mr	r3, r20
    bl      strlen
    mr	r25, r3
    b       _80081048
_80080f70:
    mr	r3, r29
    li	r4, 1
    bl      __va_arg
    lbz	r0, 0x70(r1)
    lwz	r3, 0(r3)
    cmpwi	r0, 2
    beq     _80080fb4
    bge     _80080f9c
    cmpwi	r0, 0
    beq     _80080fac
    b       _80081188
_80080f9c:
    cmpwi	r0, 4
    beq     _80080fc4
    bge     _80081188
    b       _80080fbc
_80080fac:
    stw	r27, 0(r3)
    b       _80081188
_80080fb4:
    sth	r27, 0(r3)
    b       _80081188
_80080fbc:
    stw	r27, 0(r3)
    b       _80081188
_80080fc4:
    stw	r27, 4(r3)
    srawi	r0, r27, 0x1f
    stw	r0, 0(r3)
    b       _80081188
_80080fd4:
    mr	r3, r29
    addi	r20, r1, 0x7c
    li	r4, 1
    bl      __va_arg
    lwz	r0, 0(r3)
    li	r25, 1
    stb	r0, 0x7c(r1)
    b       _80081048
_80080ff4:
    li	r0, 0x25
    addi	r20, r1, 0x7c
    stb	r0, 0x7c(r1)
    li	r25, 1
    b       _80081048
_80081008:
    mr	r3, r25
    bl      strlen
    or.	r5, r3, r3
    add	r27, r27, r5
    beq     _80081040
    mr	r12, r31
    mr	r3, r30
    mr	r4, r25
    mtctr	r12
    bctrl	
    cmplwi	r3, 0
    bne     _80081040
    li	r3, -1
    b       _80081198
_80081040:
    mr	r3, r27
    b       _80081198
_80081048:
    lbz	r0, 0x6c(r1)
    mr	r19, r25
    cmplwi	r0, 0
    beq     _80081104
    cmplwi	r0, 2
    li	r0, 0x20
    bne     _80081068
    li	r0, 0x30
_80081068:
    stb	r0, 9(r1)
    lbz	r0, 0(r20)
    extsb	r0, r0
    cmpwi	r0, 0x2b
    beq     _8008108c
    cmpwi	r0, 0x2d
    beq     _8008108c
    cmpwi	r0, 0x20
    bne     _800810f8
_8008108c:
    lbz	r0, 9(r1)
    cmpwi	r0, 0x30
    bne     _800810f8
    mr	r12, r31
    mr	r3, r30
    mr	r4, r20
    li	r5, 1
    mtctr	r12
    bctrl	
    cmplwi	r3, 0
    bne     _800810c0
    li	r3, -1
    b       _80081198
_800810c0:
    addi	r20, r20, 1
    addi	r25, r25, -1
    b       _800810f8
_800810cc:
    mr	r12, r31
    mr	r3, r30
    addi	r4, r1, 9
    li	r5, 1
    mtctr	r12
    bctrl	
    cmplwi	r3, 0
    bne     _800810f4
    li	r3, -1
    b       _80081198
_800810f4:
    addi	r19, r19, 1
_800810f8:
    lwz	r0, 0x74(r1)
    cmpw	r19, r0
    blt     _800810cc
_80081104:
    cmpwi	r25, 0
    beq     _80081134
    mr	r12, r31
    mr	r3, r30
    mr	r4, r20
    mr	r5, r25
    mtctr	r12
    bctrl	
    cmplwi	r3, 0
    bne     _80081134
    li	r3, -1
    b       _80081198
_80081134:
    lbz	r0, 0x6c(r1)
    cmplwi	r0, 0
    bne     _80081184
    li	r20, 0x20
    b       _80081178
_80081148:
    mr	r12, r31
    mr	r3, r30
    stb	r20, 8(r1)
    addi	r4, r1, 8
    li	r5, 1
    mtctr	r12
    bctrl	
    cmplwi	r3, 0
    bne     _80081174
    li	r3, -1
    b       _80081198
_80081174:
    addi	r19, r19, 1
_80081178:
    lwz	r0, 0x74(r1)
    cmpw	r19, r0
    blt     _80081148
_80081184:
    add	r27, r27, r19
_80081188:
    lbz	r0, 0(r26)
    extsb.	r0, r0
    bne     _80080a70
_80081194:
    mr	r3, r27
_80081198:
    lmw	r19, 0x28c(r1)
    lwz	r0, 0x2c4(r1)
    mtlr	r0
    addi	r1, r1, 0x2c0
    blr	
}

asm char* float2str(void* arg, char* buff, void* format, unsigned long* prec)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    lwz	r0, 0xc(r4)
    stfd	f31, 0x48(r1)
    fmr	f31, f1
    cmpwi	r0, 0x1fd
    stw	r31, 0x44(r1)
    stw	r30, 0x40(r1)
    stw	r29, 0x3c(r1)
    mr	r29, r4
    stw	r28, 0x38(r1)
    mr	r28, r3
    ble     _800811ec
    li	r3, 0
    b       _800818a4
_800811ec:
    li	r3, 0
    li	r0, 0x20
    stb	r3, 8(r1)
    addi	r3, r1, 8
    addi	r4, r1, 0xc
    sth	r0, 0xa(r1)
    bl      fn_8007C3B8
    lbz	r0, 0x10(r1)
    addi	r31, r1, 0x11
    add	r5, r31, r0
    b       _80081230
_80081218:
    lbz	r4, 0x10(r1)
    lha	r3, 0xe(r1)
    addi	r4, r4, -1
    addi	r0, r3, 1
    stb	r4, 0x10(r1)
    sth	r0, 0xe(r1)
_80081230:
    lbz	r0, 0x10(r1)
    cmplwi	r0, 1
    ble     _80081248
    lbzu	r0, -1(r5)
    cmpwi	r0, 0x30
    beq     _80081218
_80081248:
    lbz	r0, 0x11(r1)
    cmpwi	r0, 0x49
    beq     _8008127c
    bge     _80081264
    cmpwi	r0, 0x30
    beq     _80081270
    b       _800813cc
_80081264:
    cmpwi	r0, 0x4e
    beq     _80081324
    b       _800813cc
_80081270:
    li	r0, 0
    sth	r0, 0xe(r1)
    b       _800813cc
_8008127c:
    lfd	f0, -0x7958(r2)
    fcmpo	cr0, f31, f0
    bge     _800812d4
    lis     r3, lbl_8015B100@ha
    lbz	r0, 5(r29)
    addi	r3, r3, lbl_8015B100@l
    addi	r28, r28, -5
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x18, 0x18
    beq     _800812bc
    lis	r4, -0x7ff7
    mr	r3, r28
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 1
    bl      strcpy
    b       _8008131c
_800812bc:
    lis	r4, -0x7ff7
    mr	r3, r28
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 6
    bl      strcpy
    b       _8008131c
_800812d4:
    lis     r3, lbl_8015B100@ha
    lbz	r0, 5(r29)
    addi	r3, r3, lbl_8015B100@l
    addi	r28, r28, -4
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x18, 0x18
    beq     _80081308
    lis	r4, -0x7ff7
    mr	r3, r28
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 0xb
    bl      strcpy
    b       _8008131c
_80081308:
    lis	r4, -0x7ff7
    mr	r3, r28
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 0xf
    bl      strcpy
_8008131c:
    mr	r3, r28
    b       _800818a4
_80081324:
    lbz	r0, 0xc(r1)
    extsb.	r0, r0
    beq     _8008137c
    lis     r3, lbl_8015B100@ha
    lbz	r0, 5(r29)
    addi	r3, r3, lbl_8015B100@l
    addi	r28, r28, -5
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x18, 0x18
    beq     _80081364
    lis	r4, -0x7ff7
    mr	r3, r28
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 0x13
    bl      strcpy
    b       _800813c4
_80081364:
    lis	r4, -0x7ff7
    mr	r3, r28
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 0x18
    bl      strcpy
    b       _800813c4
_8008137c:
    lis     r3, lbl_8015B100@ha
    lbz	r0, 5(r29)
    addi	r3, r3, lbl_8015B100@l
    addi	r28, r28, -4
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x18, 0x18
    beq     _800813b0
    lis	r4, -0x7ff7
    mr	r3, r28
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 0x1d
    bl      strcpy
    b       _800813c4
_800813b0:
    lis	r4, -0x7ff7
    mr	r3, r28
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 0x21
    bl      strcpy
_800813c4:
    mr	r3, r28
    b       _800818a4
_800813cc:
    lha	r5, 0xe(r1)
    li	r3, 0
    lbz	r4, 0x10(r1)
    addi	r30, r28, -1
    lbz	r0, 5(r29)
    add	r4, r4, r5
    addi	r4, r4, -1
    cmpwi	r0, 0x65
    sth	r4, 0xe(r1)
    stb	r3, -1(r28)
    beq     _800814e8
    bge     _80081420
    cmpwi	r0, 0x46
    beq     _8008164c
    bge     _80081414
    cmpwi	r0, 0x45
    bge     _800814e8
    b       _800818a0
_80081414:
    cmpwi	r0, 0x48
    bge     _800818a0
    b       _80081430
_80081420:
    cmpwi	r0, 0x67
    beq     _80081430
    bge     _800818a0
    b       _8008164c
_80081430:
    lbz	r0, 0x10(r1)
    lwz	r4, 0xc(r29)
    cmpw	r0, r4
    ble     _80081448
    addi	r3, r1, 0xc
    bl      fn_800818C8
_80081448:
    lha	r4, 0xe(r1)
    cmpwi	r4, -4
    blt     _80081460
    lwz	r3, 0xc(r29)
    cmpw	r4, r3
    blt     _800814ac
_80081460:
    lbz	r0, 3(r29)
    cmplwi	r0, 0
    beq     _8008147c
    lwz	r3, 0xc(r29)
    addi	r0, r3, -1
    stw	r0, 0xc(r29)
    b       _80081488
_8008147c:
    lbz	r3, 0x10(r1)
    addi	r0, r3, -1
    stw	r0, 0xc(r29)
_80081488:
    lbz	r0, 5(r29)
    cmplwi	r0, 0x67
    bne     _800814a0
    li	r0, 0x65
    stb	r0, 5(r29)
    b       _800814e8
_800814a0:
    li	r0, 0x45
    stb	r0, 5(r29)
    b       _800814e8
_800814ac:
    lbz	r0, 3(r29)
    cmplwi	r0, 0
    beq     _800814c8
    addi	r0, r4, 1
    subf	r0, r0, r3
    stw	r0, 0xc(r29)
    b       _8008164c
_800814c8:
    lbz	r0, 0x10(r1)
    addi	r3, r4, 1
    subf.	r0, r3, r0
    stw	r0, 0xc(r29)
    bge     _8008164c
    li	r0, 0
    stw	r0, 0xc(r29)
    b       _8008164c
_800814e8:
    lwz	r3, 0xc(r29)
    lbz	r0, 0x10(r1)
    addi	r4, r3, 1
    cmpw	r0, r4
    ble     _80081504
    addi	r3, r1, 0xc
    bl      fn_800818C8
_80081504:
    lha	r6, 0xe(r1)
    li	r8, 0x2b
    cmpwi	r6, 0
    bge     _8008151c
    neg	r6, r6
    li	r8, 0x2d
_8008151c:
    lis	r3, 0x6666
    li	r7, 0
    addi	r5, r3, 0x6667
    b       _80081560
_8008152c:
    mulhw	r0, r5, r6
    addi	r7, r7, 1
    srawi	r3, r0, 2
    srwi	r4, r3, 0x1f
    srawi	r0, r0, 2
    add	r3, r3, r4
    mulli	r4, r3, 0xa
    srwi	r3, r0, 0x1f
    subf	r4, r4, r6
    add	r6, r0, r3
    addi	r0, r4, 0x30
    stb	r0, -1(r30)
    addi	r30, r30, -1
_80081560:
    cmpwi	r6, 0
    bne     _8008152c
    cmpwi	r7, 2
    blt     _8008152c
    lbz	r0, 5(r29)
    stb	r8, -1(r30)
    lwz	r3, 0xc(r29)
    stbu	r0, -2(r30)
    subf	r0, r30, r28
    add	r0, r3, r0
    cmpwi	r0, 0x1fd
    ble     _80081598
    li	r3, 0
    b       _800818a4
_80081598:
    lbz	r4, 0x10(r1)
    addi	r0, r3, 1
    cmpw	r4, r0
    bge     _800815c4
    addi	r3, r3, 2
    li	r0, 0x30
    subf	r3, r4, r3
    b       _800815bc
_800815b8:
    stbu	r0, -1(r30)
_800815bc:
    addic.	r3, r3, -1
    bne     _800815b8
_800815c4:
    lbz	r3, 0x10(r1)
    add	r4, r31, r3
    b       _800815d8
_800815d0:
    lbzu	r0, -1(r4)
    stbu	r0, -1(r30)
_800815d8:
    addic.	r3, r3, -1
    bne     _800815d0
    lwz	r0, 0xc(r29)
    cmpwi	r0, 0
    bne     _800815f8
    lbz	r0, 3(r29)
    cmplwi	r0, 0
    beq     _80081600
_800815f8:
    li	r0, 0x2e
    stbu	r0, -1(r30)
_80081600:
    lbz	r0, 0x11(r1)
    stbu	r0, -1(r30)
    lbz	r0, 0xc(r1)
    extsb.	r0, r0
    beq     _80081620
    li	r0, 0x2d
    stbu	r0, -1(r30)
    b       _800818a0
_80081620:
    lbz	r0, 1(r29)
    cmplwi	r0, 1
    bne     _80081638
    li	r0, 0x2b
    stbu	r0, -1(r30)
    b       _800818a0
_80081638:
    cmplwi	r0, 2
    bne     _800818a0
    li	r0, 0x20
    stbu	r0, -1(r30)
    b       _800818a0
_8008164c:
    lha	r0, 0xe(r1)
    lbz	r4, 0x10(r1)
    subf	r3, r0, r4
    addic.	r7, r3, -1
    bge     _80081664
    li	r7, 0
_80081664:
    lwz	r0, 0xc(r29)
    cmpw	r7, r0
    ble     _80081698
    subf	r0, r0, r7
    addi	r3, r1, 0xc
    subf	r4, r0, r4
    bl      fn_800818C8
    lha	r3, 0xe(r1)
    lbz	r0, 0x10(r1)
    subf	r3, r3, r0
    addic.	r7, r3, -1
    bge     _80081698
    li	r7, 0
_80081698:
    lha	r3, 0xe(r1)
    addic.	r6, r3, 1
    bge     _800816a8
    li	r6, 0
_800816a8:
    add	r0, r6, r7
    cmpwi	r0, 0x1fd
    ble     _800816bc
    li	r3, 0
    b       _800818a4
_800816bc:
    lwz	r0, 0xc(r29)
    li	r4, 0x30
    lbz	r5, 0x10(r1)
    subf.	r3, r7, r0
    add	r5, r31, r5
    ble     _80081718
    rlwinm.	r0, r3, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _8008170c
_800816e0:
    stb	r4, -1(r30)
    stb	r4, -2(r30)
    stb	r4, -3(r30)
    stb	r4, -4(r30)
    stb	r4, -5(r30)
    stb	r4, -6(r30)
    stb	r4, -7(r30)
    stbu	r4, -8(r30)
    bdnz    _800816e0
    andi.	r3, r3, 7
    beq     _80081718
_8008170c:
    mtctr	r3
_80081710:
    stbu	r4, -1(r30)
    bdnz    _80081710
_80081718:
    li	r3, 0
    b       _8008172c
_80081720:
    lbzu	r0, -1(r5)
    addi	r3, r3, 1
    stbu	r0, -1(r30)
_8008172c:
    cmpw	r3, r7
    bge     _80081740
    lbz	r0, 0x10(r1)
    cmpw	r3, r0
    blt     _80081720
_80081740:
    cmpw	r3, r7
    subf	r3, r3, r7
    li	r4, 0x30
    bge     _80081794
    rlwinm.	r0, r3, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _80081788
_8008175c:
    stb	r4, -1(r30)
    stb	r4, -2(r30)
    stb	r4, -3(r30)
    stb	r4, -4(r30)
    stb	r4, -5(r30)
    stb	r4, -6(r30)
    stb	r4, -7(r30)
    stbu	r4, -8(r30)
    bdnz    _8008175c
    andi.	r3, r3, 7
    beq     _80081794
_80081788:
    mtctr	r3
_8008178c:
    stbu	r4, -1(r30)
    bdnz    _8008178c
_80081794:
    lwz	r0, 0xc(r29)
    cmpwi	r0, 0
    bne     _800817ac
    lbz	r0, 3(r29)
    cmplwi	r0, 0
    beq     _800817b4
_800817ac:
    li	r0, 0x2e
    stbu	r0, -1(r30)
_800817b4:
    cmpwi	r6, 0
    beq     _80081858
    li	r4, 0
    li	r3, 0x30
    b       _800817d0
_800817c8:
    stbu	r3, -1(r30)
    addi	r4, r4, 1
_800817d0:
    lbz	r0, 0x10(r1)
    subf	r0, r0, r6
    cmpw	r4, r0
    blt     _800817c8
    cmpw	r4, r6
    subf	r3, r4, r6
    bge     _80081860
    rlwinm.	r0, r3, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _80081844
_800817f8:
    lbz	r0, -1(r5)
    stb	r0, -1(r30)
    lbz	r0, -2(r5)
    stb	r0, -2(r30)
    lbz	r0, -3(r5)
    stb	r0, -3(r30)
    lbz	r0, -4(r5)
    stb	r0, -4(r30)
    lbz	r0, -5(r5)
    stb	r0, -5(r30)
    lbz	r0, -6(r5)
    stb	r0, -6(r30)
    lbz	r0, -7(r5)
    stb	r0, -7(r30)
    lbzu	r0, -8(r5)
    stbu	r0, -8(r30)
    bdnz    _800817f8
    andi.	r3, r3, 7
    beq     _80081860
_80081844:
    mtctr	r3
_80081848:
    lbzu	r0, -1(r5)
    stbu	r0, -1(r30)
    bdnz    _80081848
    b       _80081860
_80081858:
    li	r0, 0x30
    stbu	r0, -1(r30)
_80081860:
    lbz	r0, 0xc(r1)
    extsb.	r0, r0
    beq     _80081878
    li	r0, 0x2d
    stbu	r0, -1(r30)
    b       _800818a0
_80081878:
    lbz	r0, 1(r29)
    cmplwi	r0, 1
    bne     _80081890
    li	r0, 0x2b
    stbu	r0, -1(r30)
    b       _800818a0
_80081890:
    cmplwi	r0, 2
    bne     _800818a0
    li	r0, 0x20
    stbu	r0, -1(r30)
_800818a0:
    mr	r3, r30
_800818a4:
    lwz	r0, 0x54(r1)
    lfd	f31, 0x48(r1)
    lwz	r31, 0x44(r1)
    lwz	r30, 0x40(r1)
    lwz	r29, 0x3c(r1)
    lwz	r28, 0x38(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void fn_800818C8(void)
{
    nofralloc
    cmpwi	r4, 0
    bge     _800818ec
_800818d0:
    li	r0, 0
    li	r4, 1
    sth	r0, 2(r3)
    li	r0, 0x30
    stb	r4, 4(r3)
    stb	r0, 5(r3)
    blr	
_800818ec:
    lbz	r7, 4(r3)
    cmpw	r4, r7
    bgelr	
    add	r6, r3, r4
    lbz	r5, 5(r6)
    addi	r8, r6, 5
    addi	r0, r5, -0x30
    extsb	r6, r0
    cmpwi	r6, 5
    bne     _80081950
    add	r5, r3, r7
    addi	r5, r5, 5
_8008191c:
    addi	r5, r5, -1
    cmplw	r5, r8
    ble     _80081934
    lbz	r0, 0(r5)
    cmpwi	r0, 0x30
    beq     _8008191c
_80081934:
    cmplw	r5, r8
    bne     _80081948
    lbz	r0, -1(r8)
    clrlwi	r5, r0, 0x1f
    b       _800819b0
_80081948:
    li	r5, 1
    b       _800819b0
_80081950:
    li	r0, 5
    xor	r0, r6, r0
    srawi	r5, r0, 1
    and	r0, r0, r6
    subf	r0, r0, r5
    srwi	r5, r0, 0x1f
    b       _800819b0
_8008196c:
    lbzu	r0, -1(r8)
    add	r5, r0, r5
    addi	r0, r5, -0x30
    extsb	r7, r0
    xor	r0, r7, r6
    srawi	r5, r0, 1
    and	r0, r0, r7
    subf	r0, r0, r5
    rlwinm.	r5, r0, 1, 0x1f, 0x1f
    bne     _8008199c
    extsb.	r0, r7
    bne     _800819a4
_8008199c:
    addi	r4, r4, -1
    b       _800819b4
_800819a4:
    addi	r0, r7, 0x30
    stb	r0, 0(r8)
    b       _800819bc
_800819b0:
    li	r6, 9
_800819b4:
    cmpwi	r4, 0
    bne     _8008196c
_800819bc:
    cmpwi	r5, 0
    beq     _800819e4
    lha	r5, 2(r3)
    li	r4, 1
    li	r0, 0x31
    addi	r5, r5, 1
    sth	r5, 2(r3)
    stb	r4, 4(r3)
    stb	r0, 5(r3)
    blr	
_800819e4:
    cmpwi	r4, 0
    beq     _800818d0
    stb	r4, 4(r3)
    blr	
}

asm char* double2hex(void* arg, char* buff, void* format)
{
    nofralloc
    stwu	r1, -0x80(r1)
    mflr	r0
    stw	r0, 0x84(r1)
    lwz	r0, 0xc(r4)
    stw	r31, 0x7c(r1)
    mr	r31, r4
    cmpwi	r0, 0x1fd
    stw	r30, 0x78(r1)
    mr	r30, r3
    stfd	f1, 8(r1)
    stfd	f1, 0x18(r1)
    ble     _80081a2c
    li	r3, 0
    b       _80081d14
_80081a2c:
    li	r3, 0
    li	r0, 0x20
    stb	r3, 0x10(r1)
    addi	r3, r1, 0x10
    addi	r4, r1, 0x40
    sth	r0, 0x12(r1)
    bl      fn_8007C3B8
    lbz	r0, 0x45(r1)
    cmplwi	r0, 0x49
    bne     _80081ae4
    lha	r0, 0x18(r1)
    rlwinm.	r0, r0, 0, 0x10, 0x10
    beq     _80081aa0
    lbz	r0, 5(r31)
    addi	r30, r30, -5
    cmplwi	r0, 0x41
    bne     _80081a88
    lis	r4, -0x7ff7
    mr	r3, r30
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 1
    bl      strcpy
    b       _80081adc
_80081a88:
    lis	r4, -0x7ff7
    mr	r3, r30
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 6
    bl      strcpy
    b       _80081adc
_80081aa0:
    lbz	r0, 5(r31)
    addi	r30, r30, -4
    cmplwi	r0, 0x41
    bne     _80081ac8
    lis	r4, -0x7ff7
    mr	r3, r30
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 0xb
    bl      strcpy
    b       _80081adc
_80081ac8:
    lis	r4, -0x7ff7
    mr	r3, r30
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 0xf
    bl      strcpy
_80081adc:
    mr	r3, r30
    b       _80081d14
_80081ae4:
    cmplwi	r0, 0x4e
    bne     _80081b7c
    lbz	r0, 8(r1)
    rlwinm.	r0, r0, 0, 0x18, 0x18
    beq     _80081b38
    lbz	r0, 5(r31)
    addi	r30, r30, -5
    cmplwi	r0, 0x41
    bne     _80081b20
    lis	r4, -0x7ff7
    mr	r3, r30
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 0x13
    bl      strcpy
    b       _80081b74
_80081b20:
    lis	r4, -0x7ff7
    mr	r3, r30
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 0x18
    bl      strcpy
    b       _80081b74
_80081b38:
    lbz	r0, 5(r31)
    addi	r30, r30, -4
    cmplwi	r0, 0x41
    bne     _80081b60
    lis	r4, -0x7ff7
    mr	r3, r30
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 0x1d
    bl      strcpy
    b       _80081b74
_80081b60:
    lis	r4, -0x7ff7
    mr	r3, r30
    addi	r4, r4, 0x4fc0
    addi	r4, r4, 0x21
    bl      strcpy
_80081b74:
    mr	r3, r30
    b       _80081d14
_80081b7c:
    li	r8, 0
    li	r9, 1
    lha	r0, 0x18(r1)
    li	r7, 0x64
    stb	r9, 0x30(r1)
    mr	r4, r30
    rlwinm	r0, r0, 0x1c, 0x15, 0x1f
    addi	r5, r1, 0x20
    extsh	r3, r0
    stb	r9, 0x31(r1)
    addi	r3, r3, -0x3ff
    stb	r8, 0x32(r1)
    stb	r8, 0x33(r1)
    lwz	r6, 0x30(r1)
    stb	r8, 0x34(r1)
    stb	r7, 0x35(r1)
    lwz	r0, 0x34(r1)
    stw	r8, 0x38(r1)
    stw	r9, 0x3c(r1)
    stw	r6, 0x20(r1)
    stw	r0, 0x24(r1)
    stw	r8, 0x28(r1)
    stw	r9, 0x2c(r1)
    bl      long2str
    lbz	r0, 5(r31)
    cmplwi	r0, 0x61
    bne     _80081bf8
    li	r0, 0x70
    addi	r4, r3, -1
    stb	r0, -1(r3)
    b       _80081c04
_80081bf8:
    li	r0, 0x50
    addi	r4, r3, -1
    stb	r0, -1(r3)
_80081c04:
    lwz	r8, 0xc(r31)
    addi	r6, r1, 8
    mtctr	r8
    cmpwi	r8, 1
    blt     _80081c80
_80081c18:
    srwi	r5, r8, 0x1f
    clrlwi	r0, r8, 0x1f
    add	r3, r5, r8
    srawi	r3, r3, 1
    xor	r0, r0, r5
    addi	r3, r3, 1
    lbzx	r7, r6, r3
    subf.	r0, r5, r0
    rlwinm	r0, r7, 0x1c, 0x1c, 0x1f
    extsb	r3, r0
    beq     _80081c48
    clrlwi	r3, r7, 0x1c
_80081c48:
    extsb	r0, r3
    cmpwi	r0, 0xa
    bge     _80081c5c
    addi	r0, r3, 0x30
    b       _80081c74
_80081c5c:
    lbz	r0, 5(r31)
    cmplwi	r0, 0x61
    bne     _80081c70
    addi	r0, r3, 0x57
    b       _80081c74
_80081c70:
    addi	r0, r3, 0x37
_80081c74:
    stbu	r0, -1(r4)
    addi	r8, r8, -1
    bdnz    _80081c18
_80081c80:
    lwz	r0, 0xc(r31)
    cmpwi	r0, 0
    bne     _80081c98
    lbz	r0, 3(r31)
    cmplwi	r0, 0
    beq     _80081ca0
_80081c98:
    li	r0, 0x2e
    stbu	r0, -1(r4)
_80081ca0:
    lbz	r0, 5(r31)
    li	r3, 0x31
    stb	r3, -1(r4)
    cmplwi	r0, 0x61
    bne     _80081cc0
    li	r0, 0x78
    stbu	r0, -2(r4)
    b       _80081cc8
_80081cc0:
    li	r0, 0x58
    stbu	r0, -2(r4)
_80081cc8:
    lha	r0, 0x18(r1)
    li	r3, 0x30
    stbu	r3, -1(r4)
    rlwinm.	r0, r0, 0, 0x10, 0x10
    beq     _80081ce8
    li	r0, 0x2d
    stbu	r0, -1(r4)
    b       _80081d10
_80081ce8:
    lbz	r0, 1(r31)
    cmplwi	r0, 1
    bne     _80081d00
    li	r0, 0x2b
    stbu	r0, -1(r4)
    b       _80081d10
_80081d00:
    cmplwi	r0, 2
    bne     _80081d10
    li	r0, 0x20
    stbu	r0, -1(r4)
_80081d10:
    mr	r3, r4
_80081d14:
    lwz	r0, 0x84(r1)
    lwz	r31, 0x7c(r1)
    lwz	r30, 0x78(r1)
    mtlr	r0
    addi	r1, r1, 0x80
    blr	
}

asm char* longlong2str(long long num, char* pBuf, void* format)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    li	r0, 0
    stmw	r22, 8(r1)
    mr	r23, r5
    xor	r5, r4, r0
    mr	r24, r6
    mr	r30, r4
    mr	r31, r3
    addi	r27, r23, -1
    li	r25, 0
    li	r26, 0
    stb	r0, -1(r23)
    xor	r0, r3, r0
    or.	r0, r5, r0
    bne     _80081d9c
    lwz	r0, 0xc(r24)
    cmpwi	r0, 0
    bne     _80081d9c
    lbz	r0, 3(r24)
    cmplwi	r0, 0
    beq     _80081d94
    lbz	r0, 5(r24)
    cmplwi	r0, 0x6f
    beq     _80081d9c
_80081d94:
    mr	r3, r27
    b       _8008202c
_80081d9c:
    lbz	r5, 5(r24)
    addi	r0, r5, -0x58
    cmplwi	r0, 0x20
    bgt     _80081e34
    lis	r5, -0x7fea
    slwi	r0, r0, 2
    addi	r5, r5, -0x4bc8
    lwzx	r0, r5, r0
    mtctr	r0
    bctr	
    li	r0, 0
    xoris	r5, r3, 0x8000
    xoris	r3, r0, 0x8000
    li	r28, 0xa
    subfc	r0, r0, r4
    li	r29, 0
    subfe	r3, r3, r5
    subfe	r3, r5, r5
    neg.	r3, r3
    beq     _80081e34
    subfic	r30, r30, 0
    li	r25, 1
    subfze	r31, r31
    b       _80081e34
    li	r0, 0
    li	r28, 8
    stb	r0, 1(r24)
    li	r29, 0
    b       _80081e34
    li	r0, 0
    li	r28, 0xa
    stb	r0, 1(r24)
    li	r29, 0
    b       _80081e34
    li	r0, 0
    li	r28, 0x10
    stb	r0, 1(r24)
    li	r29, 0
_80081e34:
    mr	r3, r31
    mr	r4, r30
    mr	r5, r29
    mr	r6, r28
    bl      __mod2u
    mr	r22, r4
    mr	r3, r31
    mr	r4, r30
    mr	r5, r29
    mr	r6, r28
    bl      __div2u
    cmpwi	r22, 0xa
    mr	r30, r4
    mr	r31, r3
    bge     _80081e78
    addi	r0, r22, 0x30
    b       _80081e90
_80081e78:
    lbz	r0, 5(r24)
    cmplwi	r0, 0x78
    bne     _80081e8c
    addi	r0, r22, 0x57
    b       _80081e90
_80081e8c:
    addi	r0, r22, 0x37
_80081e90:
    li	r4, 0
    stbu	r0, -1(r27)
    xor	r3, r30, r4
    addi	r26, r26, 1
    xor	r0, r31, r4
    or.	r0, r3, r0
    bne     _80081e34
    li	r3, 8
    xor	r0, r29, r4
    xor	r3, r28, r3
    or.	r0, r3, r0
    bne     _80081ee4
    lbz	r0, 3(r24)
    cmplwi	r0, 0
    beq     _80081ee4
    lbz	r0, 0(r27)
    cmpwi	r0, 0x30
    beq     _80081ee4
    li	r0, 0x30
    addi	r26, r26, 1
    stbu	r0, -1(r27)
_80081ee4:
    lbz	r0, 0(r24)
    cmplwi	r0, 2
    bne     _80081f48
    lwz	r0, 8(r24)
    cmpwi	r25, 0
    stw	r0, 0xc(r24)
    bne     _80081f0c
    lbz	r0, 1(r24)
    cmplwi	r0, 0
    beq     _80081f18
_80081f0c:
    lwz	r3, 0xc(r24)
    addi	r0, r3, -1
    stw	r0, 0xc(r24)
_80081f18:
    li	r3, 0x10
    li	r0, 0
    xor	r3, r28, r3
    xor	r0, r29, r0
    or.	r0, r3, r0
    bne     _80081f48
    lbz	r0, 3(r24)
    cmplwi	r0, 0
    beq     _80081f48
    lwz	r3, 0xc(r24)
    addi	r0, r3, -2
    stw	r0, 0xc(r24)
_80081f48:
    lwz	r3, 0xc(r24)
    subf	r0, r27, r23
    add	r0, r3, r0
    cmpwi	r0, 0x1fd
    ble     _80081f64
    li	r3, 0
    b       _8008202c
_80081f64:
    cmpw	r26, r3
    subf	r3, r26, r3
    li	r4, 0x30
    bge     _80081fb8
    rlwinm.	r0, r3, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _80081fac
_80081f80:
    stb	r4, -1(r27)
    stb	r4, -2(r27)
    stb	r4, -3(r27)
    stb	r4, -4(r27)
    stb	r4, -5(r27)
    stb	r4, -6(r27)
    stb	r4, -7(r27)
    stbu	r4, -8(r27)
    bdnz    _80081f80
    andi.	r3, r3, 7
    beq     _80081fb8
_80081fac:
    mtctr	r3
_80081fb0:
    stbu	r4, -1(r27)
    bdnz    _80081fb0
_80081fb8:
    li	r3, 0x10
    li	r0, 0
    xor	r3, r28, r3
    xor	r0, r29, r0
    or.	r0, r3, r0
    bne     _80081fec
    lbz	r0, 3(r24)
    cmplwi	r0, 0
    beq     _80081fec
    lbz	r3, 5(r24)
    li	r0, 0x30
    stb	r3, -1(r27)
    stbu	r0, -2(r27)
_80081fec:
    cmpwi	r25, 0
    beq     _80082000
    li	r0, 0x2d
    stbu	r0, -1(r27)
    b       _80082028
_80082000:
    lbz	r0, 1(r24)
    cmplwi	r0, 1
    bne     _80082018
    li	r0, 0x2b
    stbu	r0, -1(r27)
    b       _80082028
_80082018:
    cmplwi	r0, 2
    bne     _80082028
    li	r0, 0x20
    stbu	r0, -1(r27)
_80082028:
    mr	r3, r27
_8008202c:
    lmw	r22, 8(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm char* long2str(long num, char* buff, void* format)
{
    nofralloc
    li	r6, 0
    cmpwi	r3, 0
    stb	r6, -1(r4)
    addi	r6, r4, -1
    li	r8, 0
    li	r7, 0
    bne     _80082088
    lwz	r9, 0xc(r5)
    cmpwi	r9, 0
    bne     _80082088
    lbz	r9, 3(r5)
    cmplwi	r9, 0
    beq     _80082080
    lbz	r9, 5(r5)
    cmplwi	r9, 0x6f
    beq     _80082088
_80082080:
    mr	r3, r6
    blr	
_80082088:
    lbz	r9, 5(r5)
    addi	r10, r9, -0x58
    cmplwi	r10, 0x20
    bgt     _800820f4
    lis     r9, -0x7fea
    slwi	r10, r10, 2
    addi	r9, r9, -0x4b44
    lwzx	r9, r9, r10
    mtctr	r9
    bctr	
    cmpwi	r3, 0
    li	r0, 0xa
    bge     _800820f4
    neg	r3, r3
    li	r8, 1
    b       _800820f4
    li	r9, 0
    li	r0, 8
    stb	r9, 1(r5)
    b       _800820f4
    li	r9, 0
    li	r0, 0xa
    stb	r9, 1(r5)
    b       _800820f4
    li	r9, 0
    li	r0, 0x10
    stb	r9, 1(r5)
_800820f4:
    lbz	r9, 5(r5)
_800820f8:
    divwu	r10, r3, r0
    mullw	r10, r10, r0
    subf	r10, r10, r3
    divwu	r3, r3, r0
    cmpwi	r10, 0xa
    bge     _80082118
    addi	r10, r10, 0x30
    b       _8008212c
_80082118:
    cmplwi	r9, 0x78
    bne     _80082128
    addi	r10, r10, 0x57
    b       _8008212c
_80082128:
    addi	r10, r10, 0x37
_8008212c:
    cmplwi	r3, 0
    stb	r10, -1(r6)
    addi	r6, r6, -1
    addi	r7, r7, 1
    bne     _800820f8
    cmplwi	r0, 8
    bne     _8008216c
    lbz	r3, 3(r5)
    cmplwi	r3, 0
    beq     _8008216c
    lbz	r3, 0(r6)
    cmpwi	r3, 0x30
    beq     _8008216c
    li	r3, 0x30
    addi	r7, r7, 1
    stbu	r3, -1(r6)
_8008216c:
    lbz	r3, 0(r5)
    cmplwi	r3, 2
    bne     _800821c0
    lwz	r3, 8(r5)
    cmpwi	r8, 0
    stw	r3, 0xc(r5)
    bne     _80082194
    lbz	r3, 1(r5)
    cmplwi	r3, 0
    beq     _800821a0
_80082194:
    lwz	r3, 0xc(r5)
    addi	r3, r3, -1
    stw	r3, 0xc(r5)
_800821a0:
    cmplwi	r0, 0x10
    bne     _800821c0
    lbz	r3, 3(r5)
    cmplwi	r3, 0
    beq     _800821c0
    lwz	r3, 0xc(r5)
    addi	r3, r3, -2
    stw	r3, 0xc(r5)
_800821c0:
    lwz	r9, 0xc(r5)
    subf	r3, r6, r4
    add	r3, r9, r3
    cmpwi	r3, 0x1fd
    ble     _800821dc
    li	r3, 0
    blr	
_800821dc:
    cmpw	r7, r9
    subf	r4, r7, r9
    li	r7, 0x30
    bge     _80082230
    rlwinm.	r3, r4, 0x1d, 3, 0x1f
    mtctr	r3
    beq     _80082224
_800821f8:
    stb	r7, -1(r6)
    stb	r7, -2(r6)
    stb	r7, -3(r6)
    stb	r7, -4(r6)
    stb	r7, -5(r6)
    stb	r7, -6(r6)
    stb	r7, -7(r6)
    stbu	r7, -8(r6)
    bdnz    _800821f8
    andi.	r4, r4, 7
    beq     _80082230
_80082224:
    mtctr	r4
_80082228:
    stbu	r7, -1(r6)
    bdnz    _80082228
_80082230:
    cmplwi	r0, 0x10
    bne     _80082254
    lbz	r0, 3(r5)
    cmplwi	r0, 0
    beq     _80082254
    lbz	r3, 5(r5)
    li	r0, 0x30
    stb	r3, -1(r6)
    stbu	r0, -2(r6)
_80082254:
    cmpwi	r8, 0
    beq     _80082268
    li	r0, 0x2d
    stbu	r0, -1(r6)
    b       _80082290
_80082268:
    lbz	r0, 1(r5)
    cmplwi	r0, 1
    bne     _80082280
    li	r0, 0x2b
    stbu	r0, -1(r6)
    b       _80082290
_80082280:
    cmplwi	r0, 2
    bne     _80082290
    li	r0, 0x20
    stbu	r0, -1(r6)
_80082290:
    mr	r3, r6
    blr	
}

asm const char* parse_format(const char* fmt, void* arg, void* format)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    li	r7, 0
    lbz	r6, 1(r3)
    stw	r0, 0x34(r1)
    li	r0, 1
    extsb	r6, r6
    stw	r31, 0x2c(r1)
    cmpwi	r6, 0x25
    addi	r31, r3, 1
    stw	r30, 0x28(r1)
    mr	r30, r5
    stw	r29, 0x24(r1)
    mr	r29, r4
    stb	r7, 9(r1)
    stb	r0, 8(r1)
    stb	r7, 0xa(r1)
    stb	r7, 0xb(r1)
    stb	r7, 0xc(r1)
    stw	r7, 0x10(r1)
    stw	r7, 0x14(r1)
    bne     _80082314
    stb	r6, 0xd(r1)
    addi	r3, r31, 1
    lwz	r4, 8(r1)
    lwz	r0, 0xc(r1)
    stw	r4, 0(r30)
    stw	r0, 4(r30)
    stw	r7, 8(r30)
    stw	r7, 0xc(r30)
    b       _80082780
_80082314:
    addi	r0, r6, -0x20
    li	r4, 1
    cmplwi	r0, 0x10
    bgt     _80082390
    lis     r3, -0x7fea
    slwi	r0, r0, 2
    addi	r3, r3, -0x49e0
    lwzx	r0, r3, r0
    mtctr	r0
    bctr	
    li	r0, 0
    stb	r0, 8(r1)
    b       _80082394
    li	r0, 1
    stb	r0, 9(r1)
    b       _80082394
    lbz	r0, 9(r1)
    cmplwi	r0, 1
    beq     _80082394
    li	r0, 2
    stb	r0, 9(r1)
    b       _80082394
    li	r0, 1
    stb	r0, 0xb(r1)
    b       _80082394
    lbz	r0, 8(r1)
    cmplwi	r0, 0
    beq     _80082394
    li	r0, 2
    stb	r0, 8(r1)
    b       _80082394
_80082390:
    li	r4, 0
_80082394:
    cmpwi	r4, 0
    beq     _800823a8
    lbzu	r6, 1(r31)
    extsb	r6, r6
    b       _80082314
_800823a8:
    cmpwi	r6, 0x2a
    bne     _800823e8
    mr	r3, r29
    li	r4, 1
    bl      __va_arg
    lwz	r0, 0(r3)
    cmpwi	r0, 0
    stw	r0, 0x10(r1)
    bge     _800823dc
    neg	r0, r0
    li	r3, 0
    stb	r3, 8(r1)
    stw	r0, 0x10(r1)
_800823dc:
    lbzu	r6, 1(r31)
    extsb	r6, r6
    b       _80082420
_800823e8:
    lis     r3, lbl_8015B100@ha
    addi	r3, r3, lbl_8015B100@l
    b       _80082410
_800823f4:
    lwz	r0, 0x10(r1)
    mulli	r0, r0, 0xa
    add	r4, r6, r0
    lbzu	r6, 1(r31)
    addi	r0, r4, -0x30
    stw	r0, 0x10(r1)
    extsb	r6, r6
_80082410:
    clrlwi	r0, r6, 0x18
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bne     _800823f4
_80082420:
    lwz	r5, 0x10(r1)
    cmpwi	r5, 0x1fd
    ble     _80082458
    li	r0, 0xff
    lwz	r4, 8(r1)
    stb	r0, 0xd(r1)
    addi	r3, r31, 1
    lwz	r0, 0x14(r1)
    stw	r4, 0(r30)
    lwz	r4, 0xc(r1)
    stw	r4, 4(r30)
    stw	r5, 8(r30)
    stw	r0, 0xc(r30)
    b       _80082780
_80082458:
    cmpwi	r6, 0x2e
    bne     _800824e0
    lbzu	r6, 1(r31)
    li	r0, 1
    stb	r0, 0xa(r1)
    extsb	r6, r6
    cmpwi	r6, 0x2a
    bne     _800824a8
    mr	r3, r29
    li	r4, 1
    bl      __va_arg
    lwz	r0, 0(r3)
    cmpwi	r0, 0
    stw	r0, 0x14(r1)
    bge     _8008249c
    li	r0, 0
    stb	r0, 0xa(r1)
_8008249c:
    lbzu	r6, 1(r31)
    extsb	r6, r6
    b       _800824e0
_800824a8:
    lis     r3, lbl_8015B100@ha
    addi	r3, r3, lbl_8015B100@l
    b       _800824d0
_800824b4:
    lwz	r0, 0x14(r1)
    mulli	r0, r0, 0xa
    add	r4, r6, r0
    lbzu	r6, 1(r31)
    addi	r0, r4, -0x30
    stw	r0, 0x14(r1)
    extsb	r6, r6
_800824d0:
    clrlwi	r0, r6, 0x18
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bne     _800824b4
_800824e0:
    cmpwi	r6, 0x68
    li	r4, 1
    beq     _80082508
    bge     _800824fc
    cmpwi	r6, 0x4c
    beq     _8008255c
    b       _80082568
_800824fc:
    cmpwi	r6, 0x6c
    beq     _80082530
    b       _80082568
_80082508:
    lbz	r0, 1(r31)
    li	r3, 2
    stb	r3, 0xc(r1)
    extsb	r0, r0
    cmpwi	r0, 0x68
    bne     _8008256c
    stb	r4, 0xc(r1)
    mr	r6, r0
    addi	r31, r31, 1
    b       _8008256c
_80082530:
    lbz	r0, 1(r31)
    li	r3, 3
    stb	r3, 0xc(r1)
    extsb	r3, r0
    cmpwi	r3, 0x6c
    bne     _8008256c
    li	r0, 4
    mr	r6, r3
    stb	r0, 0xc(r1)
    addi	r31, r31, 1
    b       _8008256c
_8008255c:
    li	r0, 5
    stb	r0, 0xc(r1)
    b       _8008256c
_80082568:
    li	r4, 0
_8008256c:
    cmpwi	r4, 0
    beq     _8008257c
    lbzu	r6, 1(r31)
    extsb	r6, r6
_8008257c:
    addi	r0, r6, -0x41
    stb	r6, 0xd(r1)
    cmplwi	r0, 0x37
    bgt     _80082754
    lis     r3, -0x7fea
    slwi	r0, r0, 2
    addi	r3, r3, -0x4ac0
    lwzx	r0, r3, r0
    mtctr	r0
    bctr	
    lbz	r0, 0xc(r1)
    cmplwi	r0, 5
    bne     _800825bc
    li	r0, 0xff
    stb	r0, 0xd(r1)
    b       _8008275c
_800825bc:
    lbz	r0, 0xa(r1)
    cmplwi	r0, 0
    bne     _800825d4
    li	r0, 1
    stw	r0, 0x14(r1)
    b       _8008275c
_800825d4:
    lbz	r0, 8(r1)
    cmplwi	r0, 2
    bne     _8008275c
    li	r0, 1
    stb	r0, 8(r1)
    b       _8008275c
    lbz	r0, 0xc(r1)
    cmplwi	r0, 2
    beq     _80082600
    cmplwi	r0, 4
    bne     _8008260c
_80082600:
    li	r0, 0xff
    stb	r0, 0xd(r1)
    b       _8008275c
_8008260c:
    lbz	r0, 0xa(r1)
    cmplwi	r0, 0
    bne     _8008275c
    li	r0, 6
    stw	r0, 0x14(r1)
    b       _8008275c
    lbz	r0, 0xa(r1)
    cmplwi	r0, 0
    bne     _80082638
    li	r0, 0xd
    stw	r0, 0x14(r1)
_80082638:
    lbz	r0, 0xc(r1)
    cmplwi	r0, 2
    beq     _80082654
    cmplwi	r0, 4
    beq     _80082654
    cmplwi	r0, 1
    bne     _8008275c
_80082654:
    li	r0, 0xff
    stb	r0, 0xd(r1)
    b       _8008275c
    lwz	r0, 0x14(r1)
    cmpwi	r0, 0
    bne     _80082674
    li	r0, 1
    stw	r0, 0x14(r1)
_80082674:
    lbz	r0, 0xc(r1)
    cmplwi	r0, 2
    beq     _80082690
    cmplwi	r0, 4
    beq     _80082690
    cmplwi	r0, 1
    bne     _8008269c
_80082690:
    li	r0, 0xff
    stb	r0, 0xd(r1)
    b       _8008275c
_8008269c:
    lbz	r0, 0xa(r1)
    cmplwi	r0, 0
    bne     _8008275c
    li	r0, 6
    stw	r0, 0x14(r1)
    b       _8008275c
    li	r5, 0x78
    li	r4, 1
    li	r3, 3
    li	r0, 8
    stb	r5, 0xd(r1)
    stb	r4, 0xb(r1)
    stb	r3, 0xc(r1)
    stw	r0, 0x14(r1)
    b       _8008275c
    lbz	r3, 0xc(r1)
    cmplwi	r3, 3
    bne     _800826f0
    li	r0, 6
    stb	r0, 0xc(r1)
    b       _8008275c
_800826f0:
    lbz	r0, 0xa(r1)
    cmplwi	r0, 0
    bne     _80082704
    cmplwi	r3, 0
    beq     _8008275c
_80082704:
    li	r0, 0xff
    stb	r0, 0xd(r1)
    b       _8008275c
    lbz	r0, 0xc(r1)
    cmplwi	r0, 3
    bne     _80082728
    li	r0, 6
    stb	r0, 0xc(r1)
    b       _8008275c
_80082728:
    cmplwi	r0, 0
    beq     _8008275c
    li	r0, 0xff
    stb	r0, 0xd(r1)
    b       _8008275c
    lbz	r0, 0xc(r1)
    cmplwi	r0, 5
    bne     _8008275c
    li	r0, 0xff
    stb	r0, 0xd(r1)
    b       _8008275c
_80082754:
    li	r0, 0xff
    stb	r0, 0xd(r1)
_8008275c:
    lwz	r4, 8(r1)
    addi	r3, r31, 1
    lwz	r0, 0xc(r1)
    stw	r4, 0(r30)
    lwz	r4, 0x10(r1)
    stw	r0, 4(r30)
    lwz	r0, 0x14(r1)
    stw	r4, 8(r30)
    stw	r0, 0xc(r30)
_80082780:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

#pragma pop
