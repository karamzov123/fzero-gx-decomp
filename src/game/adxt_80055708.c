#pragma push
#pragma force_active on

typedef struct GcciEntry {
    int id;
    void* unk4;
    char pad8[0x10];
    int unk18;
    void* stream;
} GcciEntry;

typedef struct GcciCtx {
    char pad0[0x14];
    int unk14;
    int unk18;
    char pad1C[4];
    int unk20;
    int unk24;
    char pad28[0x10];
    GcciEntry ent[16];
} GcciCtx;

typedef struct GcciSlot {
    unsigned char unk0;
    char pad1[0x237];
} GcciSlot;

typedef struct GcciCrit {
    int a;
    int b;
} GcciCrit;

extern void DCInvalidateRange();
extern void DCStoreRange();
extern void DVDGetDriveStatus();
extern void OSGetTick();
extern void DVDOpen();
extern void DVDCancelSync();
extern void DVDReadPrio();
extern void DVDReadAsync();
extern void DVDGetCommandBlockStatusHalfword();
extern void DVDGetCommandBlockStatus();
extern void DVDCancel();
extern void ADXT_StartVoice();
extern void gcciErrPrintf(const char*, ...);
extern void gccicrit_leave();
extern void gccicrit_enter();
extern void fn_80057494();
extern void svmExitCritical();
extern void svmEnterCritical();
extern void fn_8008077C();
extern void __msl_strcpy();
extern void strcpy();
extern void memset();
extern void strlen();
extern unsigned char E0040301_handl_is_null_str[448];
extern unsigned char gcci_client_ctx[];
extern unsigned char gcci_nullcheck_callback[];
extern unsigned char gcci_dvd_cb_flag[];
extern unsigned char gcci_err_ctx[];
extern unsigned char lbl_80188974[0x104];
extern unsigned char lbl_801878B8[0xC];


extern unsigned char E0092912_handl_is_null_str[24];
extern void fn_800555C0();
extern unsigned char gcci_msg_base_str[43];
extern unsigned char E0003_lsc_null_str[35];
extern unsigned char E0010_min_param_str[33];
extern unsigned char E0012_stream_id_not_found_str[35];
extern unsigned char E0009_no_param_str[32];
extern unsigned char E0011_fname_param_str[35];
extern unsigned char lbl_80132260[104];
extern unsigned char lbl_801878B8[12];
extern unsigned char lbl_801878CC[4004];
extern unsigned char lbl_80188870[256];
extern unsigned char lbl_80188A78[16];
extern GcciSlot lbl_80188A8C[16];
extern void fn_800555C0();

// provenance: original
int gcci_client_get_field_10(void* handle)
{
    if (handle == 0) {
        typedef void (*ErrCb)(int, const char*, int);
        ErrCb cb = *(ErrCb*)gcci_client_ctx;
        if (cb != 0) {
            cb(*(int*)gcci_nullcheck_callback, (const char*)E0040301_handl_is_null_str, 0);
        }
        return 0;
    }
    return *(int*)((char*)handle + 0x10);
}

// provenance: original
int gcci_client_get_field_02(void* handle)
{
    if (handle == 0) {
        typedef void (*ErrCb)(int, const char*, int);
        ErrCb cb = *(ErrCb*)gcci_client_ctx;
        if (cb != 0) {
            cb(*(int*)gcci_nullcheck_callback, (const char*)E0092912_handl_is_null_str, 0);
        }
        return 0;
    }
    return *(signed char*)((char*)handle + 2);
}

asm void gcci_add_device(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r4, gcci_msg_base_str@ha
    stw	r0, 0x34(r1)
    stmw	r25, 0x14(r1)
    or.	r29, r3, r3
    lis     r3, lbl_801878B8@ha
    addi	r30, r4, gcci_msg_base_str@l
    addi	r31, r3, lbl_801878B8@l
    bne     _80055818
    lwz	r12, 0x10(r31)
    cmplwi	r12, 0
    beq     _80055958
    addi	r4, r30, 0x2c
    lwz	r3, 0xc(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
    b     _80055958
_80055818:
    lbz	r3, 2(r29)
    cmpwi	r3, 1
    beq     _80055958
    extsb.	r0, r3
    bne     _80055830
    b     _80055958
_80055830:
    addi	r3, r29, 0x28
    bl      DVDGetCommandBlockStatus
    bl      DVDGetDriveStatus
    addi	r26, r31, 0
    li	r0, 1
    stw	r0, 8(r26)
    addi	r3, r29, 0x28
    bl      DVDCancel
    li	r0, 0
    cmpwi	r3, 0
    stw	r0, 8(r26)
    bge     _80055884
    lwz	r12, 0x10(r31)
    cmplwi	r12, 0
    beq     _80055958
    mr	r5, r29
    addi	r4, r30, 0x90
    lwz	r3, 0xc(r31)
    mtctr	r12
    bctrl	
    b     _80055958
_80055884:
    bl      OSGetTick
    lis	r28, -0x8000
    lis	r4, 0x1062
    lwz	r0, 0xf8(r28)
    addi	r27, r4, 0x4dd3
    srwi	r0, r0, 2
    mulhwu	r0, r27, r0
    srwi	r0, r0, 6
    divwu	r25, r3, r0
    subfic	r26, r25, -1
    b     _80055918
_800558b0:
    addi	r3, r29, 0x28
    bl      DVDGetCommandBlockStatus
    stw	r3, 0xc(r29)
    lwz	r0, 0xc(r29)
    stw	r0, 0(r31)
    bl      OSGetTick
    lwz	r0, 0xf8(r28)
    srwi	r0, r0, 2
    mulhwu	r0, r27, r0
    srwi	r0, r0, 6
    divwu	r3, r3, r0
    cmplw	r3, r25
    add	r0, r26, r3
    blt     _800558ec
    subf	r0, r25, r3
_800558ec:
    cmplwi	r0, 0x7d0
    ble     _80055918
    lwz	r12, 0x10(r31)
    cmplwi	r12, 0
    beq     _8005593c
    mr	r5, r29
    addi	r4, r30, 0xac
    lwz	r3, 0xc(r31)
    mtctr	r12
    bctrl	
    b     _8005593c
_80055918:
    lwz	r3, 0xc(r29)
    li	r0, 0
    cmpwi	r3, 0
    beq     _80055930
    cmpwi	r3, 0xa
    bne     _80055934
_80055930:
    li	r0, 1
_80055934:
    cmpwi	r0, 0
    beq     _800558b0
_8005593c:
    li	r0, 0
    addi	r4, r31, 0
    stb	r0, 2(r29)
    addi	r3, r29, 0x28
    stb	r0, 4(r4)
    bl      DVDGetCommandBlockStatus
    bl      DVDGetDriveStatus
_80055958:
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_8005596C(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis	r6, gcci_msg_base_str@ha
    stw	r0, 0x34(r1)
    stmw	r23, 0xc(r1)
    or.	r27, r3, r3
    lis     r3, lbl_801878B8@ha
    mr	r25, r4
    mr	r26, r5
    addi	r4, r6, gcci_msg_base_str@l
    addi	r31, r3, lbl_801878B8@l
    bne     _800559c4
    lwz	r12, 0x10(r31)
    cmplwi	r12, 0
    beq     _800559bc
    addi	r4, r4, 0x2c
    lwz	r3, 0xc(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_800559bc:
    li	r3, 0
    b     _80055d80
_800559c4:
    cmpwi	r25, 0
    bge     _800559f4
    lwz	r12, 0x10(r31)
    cmplwi	r12, 0
    beq     _800559ec
    mr	r5, r27
    addi	r4, r4, 0xcc
    lwz	r3, 0xc(r31)
    mtctr	r12
    bctrl	
_800559ec:
    li	r3, 0
    b     _80055d80
_800559f4:
    cmplwi	r26, 0
    bne     _80055a24
    lwz	r12, 0x10(r31)
    cmplwi	r12, 0
    beq     _80055a1c
    mr	r5, r27
    addi	r4, r4, 0xec
    lwz	r3, 0xc(r31)
    mtctr	r12
    bctrl	
_80055a1c:
    li	r3, 0
    b     _80055d80
_80055a24:
    lbz	r4, 2(r27)
    li	r3, 0
    cmpwi	r4, 1
    beq     _80055a3c
    extsb.	r0, r4
    bne     _80055a40
_80055a3c:
    li	r3, 1
_80055a40:
    cmpwi	r3, 0
    bne     _80055a50
    li	r3, 0
    b     _80055d80
_80055a50:
    lwz	r3, 0xc(r27)
    li	r0, 0
    cmpwi	r3, 0
    beq     _80055a68
    cmpwi	r3, 0xa
    bne     _80055a6c
_80055a68:
    li	r0, 1
_80055a6c:
    cmpwi	r0, 0
    bne     _80055a7c
    li	r3, 0
    b     _80055d80
_80055a7c:
    addi	r29, r31, 0x14
    li	r0, 8
    mr	r4, r29
    li	r3, 0
    mtctr	r0
_80055a90:
    lbz	r0, 0(r4)
    cmpwi	r0, 1
    bne     _80055ab0
    lbz	r0, 2(r4)
    cmpwi	r0, 2
    bne     _80055ab0
    li	r0, 1
    b     _80055b40
_80055ab0:
    lbzu	r0, 0x64(r4)
    cmpwi	r0, 1
    bne     _80055ad0
    lbz	r0, 2(r4)
    cmpwi	r0, 2
    bne     _80055ad0
    li	r0, 1
    b     _80055b40
_80055ad0:
    lbzu	r0, 0x64(r4)
    cmpwi	r0, 1
    bne     _80055af0
    lbz	r0, 2(r4)
    cmpwi	r0, 2
    bne     _80055af0
    li	r0, 1
    b     _80055b40
_80055af0:
    lbzu	r0, 0x64(r4)
    cmpwi	r0, 1
    bne     _80055b10
    lbz	r0, 2(r4)
    cmpwi	r0, 2
    bne     _80055b10
    li	r0, 1
    b     _80055b40
_80055b10:
    lbzu	r0, 0x64(r4)
    cmpwi	r0, 1
    bne     _80055b30
    lbz	r0, 2(r4)
    cmpwi	r0, 2
    bne     _80055b30
    li	r0, 1
    b     _80055b40
_80055b30:
    addi	r4, r4, 0x64
    addi	r3, r3, 4
    bdnz     _80055a90
    li	r0, 0
_80055b40:
    cmpwi	r0, 0
    beq     _80055b50
    li	r3, 0
    b     _80055d80
_80055b50:
    cmpwi	r25, 0
    bne     _80055b70
    li	r0, 1
    addi	r4, r31, 0
    stb	r0, 2(r27)
    li	r3, 0
    stb	r0, 4(r4)
    b     _80055d80
_80055b70:
    li	r30, 0
    addi	r28, r31, 0
    stw	r30, 0x20(r27)
    stw	r26, 8(r27)
    stw	r25, 0x24(r27)
_80055b84:
    lbz	r0, 0(r29)
    cmpwi	r0, 1
    bne     _80055cb0
    lbz	r0, 2(r29)
    cmpwi	r0, 2
    bne     _80055cb0
    addi	r3, r29, 0x28
    bl      DVDGetCommandBlockStatus
    stw	r3, 0xc(r29)
    lwz	r0, 0xc(r29)
    cmpwi	r0, 0
    stw	r0, 0(r31)
    beq     _80055be4
    bge     _80055bc8
    cmpwi	r0, -1
    bge     _80055bd4
    b     _80055cb0
_80055bc8:
    cmpwi	r0, 0xa
    beq     _80055c68
    b     _80055cb0
_80055bd4:
    li	r0, 3
    stb	r0, 2(r29)
    stb	r0, 4(r28)
    b     _80055cb0
_80055be4:
    lwz	r4, 0x24(r29)
    lwz	r0, 0x10(r29)
    lwz	r3, 8(r29)
    mullw	r24, r4, r0
    mr	r4, r24
    bl      DCInvalidateRange
    stw	r24, 0x20(r29)
    lwz	r3, 0x1c(r29)
    lwz	r0, 0x24(r29)
    add	r0, r3, r0
    stw	r0, 0x1c(r29)
    lwz	r3, 0x1c(r29)
    lwz	r0, 0x10(r29)
    lwz	r4, 0x14(r29)
    mullw	r0, r3, r0
    cmpw	r0, r4
    ble     _80055c58
    lwz	r3, 8(r29)
    subf	r23, r4, r0
    lwz	r0, 0x20(r29)
    mr	r5, r23
    li	r4, 0
    add	r0, r3, r0
    subf	r24, r23, r0
    mr	r3, r24
    bl      memset
    mr	r3, r24
    mr	r4, r23
    bl      DCStoreRange
_80055c58:
    li	r0, 1
    stb	r0, 2(r29)
    stb	r0, 4(r28)
    b     _80055cb0
_80055c68:
    addi	r3, r29, 0x28
    bl      DVDGetCommandBlockStatusHalfword
    mr	r23, r3
    lwz	r3, 8(r29)
    mr	r4, r23
    bl      DCInvalidateRange
    lwz	r4, 0x10(r29)
    li	r0, 0
    stb	r0, 4(r28)
    divw	r3, r23, r4
    mullw	r3, r4, r3
    stw	r3, 0x20(r29)
    lwz	r3, 0x10(r29)
    lwz	r4, 0x1c(r29)
    divw	r3, r23, r3
    add	r3, r4, r3
    stw	r3, 0x1c(r29)
    stb	r0, 2(r29)
_80055cb0:
    addi	r30, r30, 1
    addi	r29, r29, 0x64
    cmpwi	r30, 0x28
    blt     _80055b84
    lwz	r3, 0x1c(r27)
    lwz	r4, 0x10(r27)
    lwz	r0, 0x24(r27)
    mullw	r24, r3, r4
    lwz	r3, 0x14(r27)
    mullw	r4, r0, r4
    add	r0, r24, r4
    cmpw	r0, r3
    ble     _80055d00
    subf.	r4, r24, r3
    bge     _80055d00
    li	r0, 1
    mr	r3, r25
    stb	r0, 2(r27)
    stb	r0, 4(r28)
    b     _80055d80
_80055d00:
    addi	r0, r4, 0x1f
    mr	r3, r26
    rlwinm	r23, r0, 0, 0, 0x1a
    mr	r4, r23
    bl      DCInvalidateRange
    lis	r3, gcci_dvd_cb_flag@ha
    lwz	r0, gcci_dvd_cb_flag@l(r3)
    cmpwi	r0, 0
    bne     _80055d48
    lis     r3, fn_800555C0@ha
    mr	r4, r26
    addi	r7, r3, fn_800555C0@l
    mr	r5, r23
    mr	r6, r24
    addi	r3, r27, 0x28
    li	r8, 2
    bl      DVDReadPrio
    b     _80055d60
_80055d48:
    mr	r4, r26
    mr	r5, r23
    mr	r6, r24
    addi	r3, r27, 0x28
    li	r7, 2
    bl      DVDReadAsync
_80055d60:
    cmpwi	r3, 0
    bne     _80055d70
    li	r3, 0
    b     _80055d80
_80055d70:
    li	r0, 2
    stb	r0, 2(r27)
    stb	r0, 4(r28)
    lwz	r3, 0x24(r27)
_80055d80:
    lmw	r23, 0xc(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

// provenance: original
int gcci_client_get_field_1C(void* handle)
{
    if (handle == 0) {
        typedef void (*ErrCb)(int, const char*, int);
        ErrCb cb = *(ErrCb*)gcci_client_ctx;
        if (cb != 0) {
            cb(*(int*)gcci_nullcheck_callback, (const char*)E0092912_handl_is_null_str, 0);
        }
        return 0;
    }
    return *(int*)((char*)handle + 0x1c);
}

asm void fn_80055DF4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _80055e40
    lis	r3, gcci_client_ctx@ha
    lwz	r12, gcci_client_ctx@l(r3)
    cmplwi	r12, 0
    beq     _80055e38
    lis     r4, gcci_nullcheck_callback@ha
    lis     r3, E0092912_handl_is_null_str@ha
    addi	r5, r4, gcci_nullcheck_callback@l
    addi	r4, r3, E0092912_handl_is_null_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_80055e38:
    li	r3, 0
    b     _80055eb0
_80055e40:
    cmpwi	r5, 0
    bne     _80055e50
    stw	r4, 0x1c(r3)
    b     _80055e7c
_80055e50:
    cmpwi	r5, 2
    bne     _80055e68
    lwz	r0, 0x18(r3)
    add	r0, r0, r4
    stw	r0, 0x1c(r3)
    b     _80055e7c
_80055e68:
    cmpwi	r5, 1
    bne     _80055e7c
    lwz	r0, 0x1c(r3)
    add	r0, r0, r4
    stw	r0, 0x1c(r3)
_80055e7c:
    lwz	r4, 0x18(r3)
    lwz	r0, 0x1c(r3)
    cmpw	r0, r4
    bge     _80055e90
    mr	r4, r0
_80055e90:
    stw	r4, 0x1c(r3)
    lwz	r0, 0x1c(r3)
    cmpwi	r0, 0
    ble     _80055ea4
    b     _80055ea8
_80055ea4:
    li	r0, 0
_80055ea8:
    stw	r0, 0x1c(r3)
    lwz	r3, 0x1c(r3)
_80055eb0:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void gcci_poll_device(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r5, gcci_msg_base_str@ha
    lis     r4, lbl_801878B8@ha
    stw	r0, 0x34(r1)
    stmw	r24, 0x10(r1)
    or.	r28, r3, r3
    addi	r30, r5, gcci_msg_base_str@l
    addi	r31, r4, lbl_801878B8@l
    beq     _80056070
    mr	r29, r3
    bne     _80055f14
    lwz	r12, 0x10(r31)
    cmplwi	r12, 0
    beq     _80056050
    addi	r4, r30, 0x2c
    lwz	r3, 0xc(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
    b     _80056050
_80055f14:
    lbz	r3, 2(r29)
    cmpwi	r3, 1
    beq     _80056050
    extsb.	r0, r3
    beq     _80056050
    addi	r3, r29, 0x28
    bl      DVDGetCommandBlockStatus
    bl      DVDGetDriveStatus
    addi	r24, r31, 0
    li	r0, 1
    stw	r0, 8(r24)
    addi	r3, r29, 0x28
    bl      DVDCancel
    li	r0, 0
    cmpwi	r3, 0
    stw	r0, 8(r24)
    bge     _80055f7c
    lwz	r12, 0x10(r31)
    cmplwi	r12, 0
    beq     _80056050
    mr	r5, r29
    addi	r4, r30, 0x90
    lwz	r3, 0xc(r31)
    mtctr	r12
    bctrl	
    b     _80056050
_80055f7c:
    bl      OSGetTick
    lis	r27, -0x8000
    lis	r4, 0x1062
    lwz	r0, 0xf8(r27)
    addi	r26, r4, 0x4dd3
    srwi	r0, r0, 2
    mulhwu	r0, r26, r0
    srwi	r0, r0, 6
    divwu	r25, r3, r0
    subfic	r24, r25, -1
    b     _80056010
_80055fa8:
    addi	r3, r29, 0x28
    bl      DVDGetCommandBlockStatus
    stw	r3, 0xc(r29)
    lwz	r0, 0xc(r29)
    stw	r0, 0(r31)
    bl      OSGetTick
    lwz	r0, 0xf8(r27)
    srwi	r0, r0, 2
    mulhwu	r0, r26, r0
    srwi	r0, r0, 6
    divwu	r3, r3, r0
    cmplw	r3, r25
    add	r0, r24, r3
    blt     _80055fe4
    subf	r0, r25, r3
_80055fe4:
    cmplwi	r0, 0x7d0
    ble     _80056010
    lwz	r12, 0x10(r31)
    cmplwi	r12, 0
    beq     _80056034
    mr	r5, r29
    addi	r4, r30, 0xac
    lwz	r3, 0xc(r31)
    mtctr	r12
    bctrl	
    b     _80056034
_80056010:
    lwz	r3, 0xc(r29)
    li	r0, 0
    cmpwi	r3, 0
    beq     _80056028
    cmpwi	r3, 0xa
    bne     _8005602c
_80056028:
    li	r0, 1
_8005602c:
    cmpwi	r0, 0
    beq     _80055fa8
_80056034:
    li	r0, 0
    addi	r4, r31, 0
    stb	r0, 2(r29)
    addi	r3, r29, 0x28
    stb	r0, 4(r4)
    bl      DVDGetCommandBlockStatus
    bl      DVDGetDriveStatus
_80056050:
    addi	r3, r28, 0x28
    bl      DVDCancelSync
    li	r0, 0
    mr	r3, r28
    stb	r0, 0(r28)
    li	r4, 0
    li	r5, 0x64
    bl      memset
_80056070:
    lmw	r24, 0x10(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void gcci_open_file(void)
{
    nofralloc
    stwu	r1, -0x120(r1)
    mflr	r0
    lis     r4, gcci_msg_base_str@ha
    stw	r0, 0x124(r1)
    stw	r31, 0x11c(r1)
    stw	r30, 0x118(r1)
    stw	r29, 0x114(r1)
    addi	r29, r4, gcci_msg_base_str@l
    stw	r28, 0x110(r1)
    or.	r28, r3, r3
    lis     r3, lbl_801878B8@ha
    addi	r30, r3, lbl_801878B8@l
    bne     _800560e0
    lwz	r12, 0x10(r30)
    cmplwi	r12, 0
    beq     _800560d8
    addi	r4, r29, 0x110
    lwz	r3, 0xc(r30)
    li	r5, 0
    mtctr	r12
    bctrl	
_800560d8:
    li	r3, 0
    b     _80056274
_800560e0:
    cmpwi	r5, 0
    beq     _80056110
    lwz	r12, 0x10(r30)
    cmplwi	r12, 0
    beq     _80056108
    addi	r4, r29, 0x134
    lwz	r3, 0xc(r30)
    li	r5, 0
    mtctr	r12
    bctrl	
_80056108:
    li	r3, 0
    b     _80056274
_80056110:
    li	r31, 0
    li	r0, 0x28
    mr	r3, r31
    addi	r4, r30, 0x14
    mtctr	r0
_80056124:
    lbz	r0, 0(r4)
    extsb.	r0, r0
    bne     _80056140
    mulli	r0, r3, 0x64
    addi	r31, r30, 0x14
    add	r31, r31, r0
    b     _8005614c
_80056140:
    addi	r4, r4, 0x64
    addi	r3, r3, 1
    bdnz     _80056124
_8005614c:
    cmplwi	r31, 0
    bne     _8005617c
    lwz	r12, 0x10(r30)
    cmplwi	r12, 0
    beq     _80056174
    addi	r4, r29, 0x158
    lwz	r3, 0xc(r30)
    li	r5, 0
    mtctr	r12
    bctrl	
_80056174:
    li	r3, 0
    b     _80056274
_8005617c:
    lis     r4, lbl_80188870@ha
    addi	r3, r1, 8
    addi	r4, r4, lbl_80188870@l
    bl      strcpy
    mr	r4, r28
    addi	r3, r1, 8
    bl      __msl_strcpy
    addi	r3, r1, 8
    bl      strlen
    addi	r4, r1, 8
    li	r0, 0x2f
    mtctr	r3
    cmplwi	r3, 0
    ble     _800561cc
_800561b4:
    lbz	r3, 0(r4)
    cmpwi	r3, 0x5c
    bne     _800561c4
    stb	r0, 0(r4)
_800561c4:
    addi	r4, r4, 1
    bdnz     _800561b4
_800561cc:
    addi	r3, r1, 8
    addi	r4, r31, 0x28
    bl      DVDOpen
    cmpwi	r3, 0
    bne     _80056218
    lwz	r12, 0x10(r30)
    cmplwi	r12, 0
    beq     _80056200
    addi	r4, r29, 0x188
    lwz	r3, 0xc(r30)
    li	r5, 0
    mtctr	r12
    bctrl	
_80056200:
    mr	r3, r31
    li	r4, 0
    li	r5, 0x64
    bl      memset
    li	r3, 0
    b     _80056274
_80056218:
    li	r0, 0x800
    stw	r0, 0x10(r31)
    lwz	r3, 0x5c(r31)
    rlwinm.	r0, r3, 0, 0, 0
    beq     _80056234
    lis	r3, -0x8000
    addi	r3, r3, -1
_80056234:
    stw	r3, 0x14(r31)
    li	r4, 0
    li	r0, 1
    mr	r3, r31
    lwz	r6, 0x10(r31)
    lwz	r5, 0x14(r31)
    add	r5, r6, r5
    addi	r5, r5, -1
    divw	r5, r5, r6
    stw	r5, 0x18(r31)
    stw	r4, 0x1c(r31)
    stw	r4, 8(r31)
    stw	r4, 0x24(r31)
    stw	r4, 0x20(r31)
    stb	r4, 2(r31)
    stb	r0, 0(r31)
_80056274:
    lwz	r0, 0x124(r1)
    lwz	r31, 0x11c(r1)
    lwz	r30, 0x118(r1)
    lwz	r29, 0x114(r1)
    lwz	r28, 0x110(r1)
    mtlr	r0
    addi	r1, r1, 0x120
    blr	
}

asm void gcci_open_stream(void)
{
    nofralloc
    stwu	r1, -0x150(r1)
    mflr	r0
    stw	r0, 0x154(r1)
    stw	r31, 0x14c(r1)
    stw	r30, 0x148(r1)
    or.	r30, r3, r3
    lis     r3, gcci_msg_base_str@ha
    addi	r31, r3, gcci_msg_base_str@l
    bne     _800562ec
    lis     r3, gcci_client_ctx@ha
    lwz	r12, gcci_client_ctx@l(r3)
    cmplwi	r12, 0
    beq     _800562e4
    lis	r3, gcci_nullcheck_callback@ha
    addi	r4, r31, 0x1ac
    addi	r3, r3, gcci_nullcheck_callback@l
    li	r5, 0
    lwz	r3, 0(r3)
    mtctr	r12
    bctrl	
_800562e4:
    li	r3, 0
    b     _800563e0
_800562ec:
    lis     r4, lbl_80188870@ha
    addi	r3, r1, 0x44
    addi	r4, r4, lbl_80188870@l
    bl      strcpy
    mr	r4, r30
    addi	r3, r1, 0x44
    bl      __msl_strcpy
    addi	r3, r1, 0x44
    bl      strlen
    addi	r4, r1, 0x44
    li	r0, 0x2f
    mtctr	r3
    cmplwi	r3, 0
    ble     _8005633c
_80056324:
    lbz	r3, 0(r4)
    cmpwi	r3, 0x5c
    bne     _80056334
    stb	r0, 0(r4)
_80056334:
    addi	r4, r4, 1
    bdnz     _80056324
_8005633c:
    addi	r3, r1, 0x44
    addi	r4, r1, 8
    bl      DVDOpen
    cmpwi	r3, 0
    bne     _80056384
    lis     r3, gcci_client_ctx@ha
    lwz	r12, gcci_client_ctx@l(r3)
    cmplwi	r12, 0
    beq     _8005637c
    lis	r3, gcci_nullcheck_callback@ha
    addi	r4, r31, 0x1d8
    addi	r3, r3, gcci_nullcheck_callback@l
    li	r5, 0
    lwz	r3, 0(r3)
    mtctr	r12
    bctrl	
_8005637c:
    li	r3, 0
    b     _800563e0
_80056384:
    lwz	r30, 0x3c(r1)
    rlwinm.	r0, r30, 0, 0, 0
    beq     _80056398
    lis	r3, -0x8000
    addi	r30, r3, -1
_80056398:
    addi	r3, r1, 8
    bl      DVDCancelSync
    cmpwi	r3, 0
    bne     _800563dc
    lis     r3, gcci_client_ctx@ha
    lwz	r12, gcci_client_ctx@l(r3)
    cmplwi	r12, 0
    beq     _800563d4
    lis	r3, gcci_nullcheck_callback@ha
    addi	r4, r31, 0x208
    addi	r3, r3, gcci_nullcheck_callback@l
    li	r5, 0
    lwz	r3, 0(r3)
    mtctr	r12
    bctrl	
_800563d4:
    li	r3, 0
    b     _800563e0
_800563dc:
    mr	r3, r30
_800563e0:
    lwz	r0, 0x154(r1)
    lwz	r31, 0x14c(r1)
    lwz	r30, 0x148(r1)
    mtlr	r0
    addi	r1, r1, 0x150
    blr	
}

// provenance: original
void gcci_set_callbacks(void* a, int b)
{
    *(void**)gcci_client_ctx = a;
    *(int*)gcci_nullcheck_callback = b;
}

asm void fn_8005640C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r4, lbl_801878CC@ha
    lis     r3, lbl_801878B8@ha
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    addi	r30, r4, lbl_801878CC@l
    li	r29, 0
    addi	r31, r3, lbl_801878B8@l
_80056430:
    lbz	r0, 0(r30)
    cmpwi	r0, 1
    bne     _80056560
    lbz	r0, 2(r30)
    cmpwi	r0, 2
    bne     _80056560
    addi	r3, r30, 0x28
    bl      DVDGetCommandBlockStatus
    stw	r3, 0xc(r30)
    lis	r3, lbl_801878B8@ha
    lwz	r0, 0xc(r30)
    cmpwi	r0, 0
    stw	r0, lbl_801878B8@l(r3)
    beq     _80056494
    bge     _80056478
    cmpwi	r0, -1
    bge     _80056484
    b     _80056560
_80056478:
    cmpwi	r0, 0xa
    beq     _80056518
    b     _80056560
_80056484:
    li	r0, 3
    stb	r0, 2(r30)
    stb	r0, 4(r31)
    b     _80056560
_80056494:
    lwz	r4, 0x24(r30)
    lwz	r0, 0x10(r30)
    lwz	r3, 8(r30)
    mullw	r28, r4, r0
    mr	r4, r28
    bl      DCInvalidateRange
    stw	r28, 0x20(r30)
    lwz	r3, 0x1c(r30)
    lwz	r0, 0x24(r30)
    add	r0, r3, r0
    stw	r0, 0x1c(r30)
    lwz	r3, 0x1c(r30)
    lwz	r0, 0x10(r30)
    lwz	r4, 0x14(r30)
    mullw	r0, r3, r0
    cmpw	r0, r4
    ble     _80056508
    lwz	r3, 8(r30)
    subf	r27, r4, r0
    lwz	r0, 0x20(r30)
    mr	r5, r27
    li	r4, 0
    add	r0, r3, r0
    subf	r28, r27, r0
    mr	r3, r28
    bl      memset
    mr	r3, r28
    mr	r4, r27
    bl      DCStoreRange
_80056508:
    li	r0, 1
    stb	r0, 2(r30)
    stb	r0, 4(r31)
    b     _80056560
_80056518:
    addi	r3, r30, 0x28
    bl      DVDGetCommandBlockStatusHalfword
    mr	r27, r3
    lwz	r3, 8(r30)
    mr	r4, r27
    bl      DCInvalidateRange
    lwz	r4, 0x10(r30)
    li	r0, 0
    stb	r0, 4(r31)
    divw	r3, r27, r4
    mullw	r3, r4, r3
    stw	r3, 0x20(r30)
    lwz	r3, 0x10(r30)
    lwz	r4, 0x1c(r30)
    divw	r3, r27, r3
    add	r3, r4, r3
    stw	r3, 0x1c(r30)
    stb	r0, 2(r30)
_80056560:
    addi	r29, r29, 1
    addi	r30, r30, 0x64
    cmpwi	r29, 0x28
    blt     _80056430
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80056584(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_80188870@ha
    lis     r4, lbl_801878B8@ha
    stw	r0, 0x14(r1)
    addi	r3, r3, lbl_80188870@l
    li	r5, 0x100
    stw	r31, 0xc(r1)
    addi	r31, r4, lbl_801878B8@l
    li	r4, 0
    lwz	r0, 0xfb4(r31)
    stw	r0, 0xfb4(r31)
    bl      memset
    li	r0, 0
    addi	r3, r31, 0
    stw	r0, 0x10(r31)
    li	r4, 0
    li	r5, 0xc
    stw	r0, 0xc(r31)
    bl      memset
    lwz	r0, 0x14(r1)
    lis     r3, lbl_80132260@ha
    addi	r3, r3, lbl_80132260@l
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: original
void fn_800565F0(int a, int b, int c, int d)
{
    *(int*)gcci_dvd_cb_flag = d;
}

asm void gcciErrPrintf(const char* fmt, ...)
{
    nofralloc
    stwu	r1, -0x80(r1)
    mflr	r0
    stw	r0, 0x84(r1)
    stw	r31, 0x7c(r1)
    stw	r30, 0x78(r1)
    bne	cr1, _80056634
    stfd	f1, 0x28(r1)
    stfd	f2, 0x30(r1)
    stfd	f3, 0x38(r1)
    stfd	f4, 0x40(r1)
    stfd	f5, 0x48(r1)
    stfd	f6, 0x50(r1)
    stfd	f7, 0x58(r1)
    stfd	f8, 0x60(r1)
_80056634:
    addi	r11, r1, 0x88
    addi	r0, r1, 8
    lis     r30, gcci_err_ctx@ha
    lis	r12, 0x100
    stw	r4, 0xc(r1)
    addi	r30, r30, gcci_err_ctx@l
    addi	r31, r1, 0x68
    mr	r4, r3
    stw	r3, 8(r1)
    addi	r3, r30, 8
    stw	r5, 0x10(r1)
    mr	r5, r31
    stw	r6, 0x14(r1)
    stw	r7, 0x18(r1)
    stw	r8, 0x1c(r1)
    stw	r9, 0x20(r1)
    stw	r10, 0x24(r1)
    stw	r12, 0x68(r1)
    stw	r11, 0x6c(r1)
    stw	r0, 0x70(r1)
    bl      fn_8008077C
    lwz	r12, 0(r30)
    cmplwi	r12, 0
    beq     _800566a4
    addi	r4, r30, 8
    lwz	r3, 4(r30)
    mtctr	r12
    bctrl	
_800566a4:
    lwz	r0, 0x84(r1)
    lwz	r31, 0x7c(r1)
    lwz	r30, 0x78(r1)
    mtlr	r0
    addi	r1, r1, 0x80
    blr	
}

// provenance: original
void gcci_set_critical_value(void* a, int b)
{
    if (a == 0) {
        *(void**)gcci_err_ctx = 0;
        *(int*)lbl_80188974 = 0;
    } else {
        *(void**)gcci_err_ctx = a;
        *(int*)lbl_80188974 = b;
    }
}

/* Retail calls these out of line: the carved unit spans more than one
   original translation unit, so no caller here ever saw a body. */
#pragma dont_inline on
// provenance: original
void gccicrit_leave()
{
    svmExitCritical();
}

// provenance: original
void gccicrit_enter()
{
    svmEnterCritical();
}

// provenance: original
void fn_80056730(void* p, char val)
{
    if (p == 0) {
        gcciErrPrintf((char*)E0003_lsc_null_str);
    } else {
        *(char*)((char*)p + 3) = val;
    }
}

// provenance: original
void fn_8005676C(void)
{
    typedef void (*Cb)(int, int);
    struct CbEntry {
        Cb cb;
        int arg1;
        int arg2;
    };
    struct CbEntry* e = (struct CbEntry*)lbl_80188A78;
    if (e->cb != 0) {
        e->cb(e->arg1, e->arg2);
    }
}

// provenance: original
int fn_800567AC(void* p)
{
    if (p == 0) {
        gcciErrPrintf((char*)E0003_lsc_null_str);
        return -1;
    }
    return *(int*)((char*)p + 0x14);
}

// provenance: original
void gcci_set_min_stream(GcciCtx* p, int n)
{
    if (p == 0) {
        gcciErrPrintf((char*)E0003_lsc_null_str);
        return;
    }
    if (n < 0 || n > p->unk18) {
        gcciErrPrintf((char*)E0010_min_param_str);
        return;
    }
    p->unk14 = n;
}

// provenance: original
void* gcci_find_stream_0(GcciCtx* p, int id)
{
    int i;

    if (p == 0) {
        gcciErrPrintf((char*)E0003_lsc_null_str);
        return 0;
    }

    for (i = 0; i < 16; i++) {
        if (p->ent[i].id == id) {
            break;
        }
    }
    if (i == 16) {
        gcciErrPrintf((char*)E0012_stream_id_not_found_str);
        return 0;
    }
    return p->ent[i].stream;
}

// provenance: original
int gcci_find_stream_1(GcciCtx* p, int id)
{
    int i;

    if (p == 0) {
        gcciErrPrintf((char*)E0003_lsc_null_str);
        return -1;
    }

    for (i = 0; i < 16; i++) {
        if (p->ent[i].id == id) {
            break;
        }
    }
    if (i == 16) {
        gcciErrPrintf((char*)E0012_stream_id_not_found_str);
        return -1;
    }
    return p->ent[i].unk18;
}

// provenance: original
void* gcci_find_stream_2(GcciCtx* p, int id)
{
    int i;

    if (p == 0) {
        gcciErrPrintf((char*)E0003_lsc_null_str);
        return 0;
    }

    for (i = 0; i < 16; i++) {
        if (p->ent[i].id == id) {
            break;
        }
    }
    if (i == 16) {
        gcciErrPrintf((char*)E0012_stream_id_not_found_str);
        return 0;
    }
    return p->ent[i].unk4;
}

// provenance: original
int gcci_get_stream_by_index(GcciCtx* p, int i)
{
    if (p == 0) {
        gcciErrPrintf((char*)E0003_lsc_null_str);
        return -1;
    }
    if (i < 0 || i >= p->unk24) {
        gcciErrPrintf((char*)E0009_no_param_str);
        return -1;
    }
    return p->ent[(p->unk20 + i) % 16].id;
}

// provenance: original
int fn_80056BE0(void* p)
{
    if (p == 0) {
        gcciErrPrintf((char*)E0003_lsc_null_str);
        return -1;
    }
    return *(int*)((char*)p + 0x24);
}

// provenance: original
int fn_80056C20(void* p)
{
    if (p == 0) {
        gcciErrPrintf((char*)E0003_lsc_null_str);
        return -1;
    }
    return *(signed char*)((char*)p + 1);
}

// provenance: original
void fn_80056C64(void)
{
    GcciCrit crit;
    int i;

    gccicrit_enter(&crit);
    for (i = 0; i < 16; i++) {
        int st = lbl_80188A8C[i].unk0;
        if (st == 1) {
            fn_80057494(&lbl_80188A8C[i]);
        }
    }
    gccicrit_leave(&crit);
}

asm void fn_80056CD0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r3, r3
    bne     _80056cfc
    lis     r3, E0003_lsc_null_str@ha
    addi	r3, r3, E0003_lsc_null_str@l
    crxor	6, 6, 6
    bl      gcciErrPrintf
    b     _80056d78
_80056cfc:
    lbz	r0, 1(r31)
    extsb.	r0, r0
    beq     _80056d78
    li	r0, 0
    stb	r0, 1(r31)
    lwz	r3, 0x28(r31)
    cmplwi	r3, 0
    beq     _80056d34
    lbz	r0, 2(r31)
    cmpwi	r0, 1
    bne     _80056d34
    bl      ADXT_StartVoice
    li	r0, 0
    stb	r0, 2(r31)
_80056d34:
    li	r3, 0
    cmplwi	r31, 0
    stw	r3, 0x2c(r31)
    bne     _80056d58
    lis     r3, E0003_lsc_null_str@ha
    addi	r3, r3, E0003_lsc_null_str@l
    crxor	6, 6, 6
    bl      gcciErrPrintf
    b     _80056d70
_80056d58:
    lbz	r0, 1(r31)
    extsb.	r0, r0
    bne     _80056d70
    stw	r3, 0x1c(r31)
    stw	r3, 0x20(r31)
    stw	r3, 0x24(r31)
_80056d70:
    li	r0, 0
    stw	r0, 0x34(r31)
_80056d78:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80056D8C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    or.	r31, r3, r3
    bne     _80056db8
    lis     r3, E0003_lsc_null_str@ha
    addi	r3, r3, E0003_lsc_null_str@l
    crxor	6, 6, 6
    bl      gcciErrPrintf
    b     _80056e88
_80056db8:
    addi	r3, r1, 8
    bl      gccicrit_enter
    lbz	r3, 1(r31)
    extsb.	r0, r3
    beq     _80056e60
    cmplwi	r31, 0
    bne     _80056de8
    lis     r3, E0003_lsc_null_str@ha
    addi	r3, r3, E0003_lsc_null_str@l
    crxor	6, 6, 6
    bl      gcciErrPrintf
    b     _80056e60
_80056de8:
    extsb.	r0, r3
    beq     _80056e60
    li	r0, 0
    stb	r0, 1(r31)
    lwz	r3, 0x28(r31)
    cmplwi	r3, 0
    beq     _80056e1c
    lbz	r0, 2(r31)
    cmpwi	r0, 1
    bne     _80056e1c
    bl      ADXT_StartVoice
    li	r0, 0
    stb	r0, 2(r31)
_80056e1c:
    li	r3, 0
    cmplwi	r31, 0
    stw	r3, 0x2c(r31)
    bne     _80056e40
    lis     r3, E0003_lsc_null_str@ha
    addi	r3, r3, E0003_lsc_null_str@l
    crxor	6, 6, 6
    bl      gcciErrPrintf
    b     _80056e58
_80056e40:
    lbz	r0, 1(r31)
    extsb.	r0, r0
    bne     _80056e58
    stw	r3, 0x1c(r31)
    stw	r3, 0x20(r31)
    stw	r3, 0x24(r31)
_80056e58:
    li	r0, 0
    stw	r0, 0x34(r31)
_80056e60:
    lwz	r0, 0x24(r31)
    cmpwi	r0, 0
    ble     _80056e78
    li	r0, 2
    stb	r0, 1(r31)
    b     _80056e80
_80056e78:
    li	r0, 1
    stb	r0, 1(r31)
_80056e80:
    addi	r3, r1, 8
    bl      gccicrit_leave
_80056e88:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void gcci_register_filename(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r25, 0x14(r1)
    or.	r25, r3, r3
    mr	r26, r5
    mr	r27, r6
    mr	r28, r7
    bne     _80056ed8
    lis     r3, E0003_lsc_null_str@ha
    addi	r3, r3, E0003_lsc_null_str@l
    crxor	6, 6, 6
    bl      gcciErrPrintf
    li	r3, -1
    b     _800570c8
_80056ed8:
    lwz	r0, 0x24(r25)
    cmpwi	r0, 0x10
    blt     _80056eec
    li	r3, -1
    b     _800570c8
_80056eec:
    cmplwi	r4, 0
    bne     _80056f0c
    lis     r3, E0011_fname_param_str@ha
    addi	r3, r3, E0011_fname_param_str@l
    crxor	6, 6, 6
    bl      gcciErrPrintf
    li	r3, -1
    b     _800570c8
_80056f0c:
    lwz	r5, 0x1c(r25)
    lis	r3, -0x8000
    addi	r0, r3, -1
    mr	r29, r4
    addi	r6, r5, 0xf
    slwi	r5, r5, 5
    slwi	r7, r6, 0x1c
    mr	r3, r4
    srwi	r6, r6, 0x1f
    addi	r31, r5, 0x38
    subf	r5, r6, r7
    rotlwi	r5, r5, 4
    add	r31, r25, r31
    add	r5, r5, r6
    slwi	r5, r5, 5
    add	r5, r25, r5
    lwz	r6, 0x38(r5)
    subf	r5, r0, r6
    subf	r0, r6, r0
    nor	r5, r5, r0
    addi	r0, r6, 1
    srawi	r5, r5, 0x1f
    andc	r30, r0, r5
    stw	r30, 0(r31)
    stw	r4, 4(r31)
    bl      strlen
    srwi	r5, r3, 2
    li	r0, 0
    cmplwi	r5, 0
    stw	r0, 8(r31)
    li	r4, 0
    ble     _8005706c
    cmplwi	r5, 8
    addi	r6, r5, -8
    ble     _8005703c
    addi	r0, r6, 7
    mr	r3, r29
    srwi	r0, r0, 3
    mtctr	r0
    cmplwi	r6, 0
    ble     _8005703c
_80056fb0:
    lwz	r6, 8(r31)
    addi	r4, r4, 8
    lwz	r0, 0(r3)
    add	r0, r6, r0
    stw	r0, 8(r31)
    lwz	r6, 8(r31)
    lwz	r0, 4(r3)
    add	r0, r6, r0
    stw	r0, 8(r31)
    lwz	r6, 8(r31)
    lwz	r0, 8(r3)
    add	r0, r6, r0
    stw	r0, 8(r31)
    lwz	r6, 8(r31)
    lwz	r0, 0xc(r3)
    add	r0, r6, r0
    stw	r0, 8(r31)
    lwz	r6, 8(r31)
    lwz	r0, 0x10(r3)
    add	r0, r6, r0
    stw	r0, 8(r31)
    lwz	r6, 8(r31)
    lwz	r0, 0x14(r3)
    add	r0, r6, r0
    stw	r0, 8(r31)
    lwz	r6, 8(r31)
    lwz	r0, 0x18(r3)
    add	r0, r6, r0
    stw	r0, 8(r31)
    lwz	r0, 0x1c(r3)
    addi	r3, r3, 0x20
    lwz	r6, 8(r31)
    add	r0, r6, r0
    stw	r0, 8(r31)
    bdnz     _80056fb0
_8005703c:
    slwi	r3, r4, 2
    subf	r0, r4, r5
    add	r6, r29, r3
    mtctr	r0
    cmplw	r4, r5
    bge     _8005706c
_80057054:
    lwz	r0, 0(r6)
    addi	r6, r6, 4
    lwz	r3, 8(r31)
    add	r0, r3, r0
    stw	r0, 8(r31)
    bdnz     _80057054
_8005706c:
    stw	r27, 0x10(r31)
    li	r0, 0
    stw	r28, 0x14(r31)
    stw	r26, 0xc(r31)
    stw	r0, 0x18(r31)
    stw	r0, 0x1c(r31)
    lwz	r3, 0x24(r25)
    addi	r0, r3, 1
    stw	r0, 0x24(r25)
    lwz	r3, 0x1c(r25)
    addi	r3, r3, 1
    slwi	r0, r3, 0x1c
    srwi	r3, r3, 0x1f
    subf	r0, r3, r0
    rotlwi	r0, r0, 4
    add	r0, r0, r3
    stw	r0, 0x1c(r25)
    lbz	r0, 1(r25)
    cmpwi	r0, 1
    bne     _800570c4
    li	r0, 2
    stb	r0, 1(r25)
_800570c4:
    mr	r3, r30
_800570c8:
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

#pragma pop
#pragma dont_inline reset
