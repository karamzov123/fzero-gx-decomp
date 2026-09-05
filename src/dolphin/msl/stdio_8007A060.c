typedef void (*ExitFunc)(void);

typedef struct FileMode {
    unsigned short pad0 : 6;
    unsigned short flag1 : 1;   /* bit 1 of the high byte = value bit 9 */
    unsigned short mode : 3;    /* value bits 6..8 */
    unsigned short pad1 : 6;
} FileMode;

typedef struct FileBuffer {
    unsigned char kind : 3;   /* bits 5..7: buffer kind */
    unsigned char alloc : 1;  /* bit 4: buffer allocated */
    unsigned char pad : 4;    /* bits 0..3 */
} FileBuffer;

typedef struct File {
    unsigned int handle;                     /* +0x00 */
    FileMode open;                           /* +0x04 */
    unsigned short pad06;                    /* +0x06 */
    FileBuffer buffer;                       /* +0x08 */
    unsigned char byte09;                    /* +0x09 */
    unsigned char byte0A;                    /* +0x0A */
    unsigned char byte0B;                    /* +0x0B */
    unsigned char dyn_alloc;                 /* +0x0C: !=0 when dynamically allocated */
    unsigned char small_buf[0x0B];           /* +0x0D..+0x17 */
    unsigned int position;                   /* +0x18 */
    char* buffer_base;                       /* +0x1C */
    unsigned int buffer_size;                /* +0x20 */
    char* buffer_ptr;                        /* +0x24 */
    unsigned int buffer_length;              /* +0x28 */
    unsigned int buffer_mask;                /* +0x2C */
    unsigned int pad30;                      /* +0x30 */
    unsigned int buffer_position;            /* +0x34 */
    int (*position_func)(struct File*, long, int);        /* +0x38 */
    int (*read_func)(struct File*, char*, unsigned int*); /* +0x3C */
    int (*write_func)(struct File*, char*, unsigned int*);/* +0x40 */
    int (*close_func)(struct File*);         /* +0x44 */
    unsigned int ref_con;                    /* +0x48 */
    struct File* next;                       /* +0x4C */
} File;
// dest: src/dolphin/msl/stdio_8007A060.c
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

#pragma force_active on

extern unsigned char lbl_801A664C[4];
extern unsigned char lbl_801A6658[8];

extern void* memset();
extern void memcpy(void);
extern void _ExitProcess(void);
extern void __destroy_global_chain(void);
extern void __div2u(void);
extern void __mod2u(void);
extern void __cvt_dbl_usll(void);
extern void fn_80079EF0(void);
extern void* fn_80079FA8(unsigned int size);
extern void __memrchr(void);
extern void __stdio_atexit(void);
extern void fn_8008068C(void);
extern void fwide(void);
extern void __fp_compare_greater_equal(void);
extern void frexp(void);
extern void __fpclassifyd(void);
extern void modf(void);
extern void __msl_fp_helper(void);
extern void TRK_OpenFile_Game(void);
extern ExitFunc _dtors[]; // .dtors section anchor (0x8008FF20); symbol ref required so linker sees exit() calls destructors
extern ExitFunc __atexit_funcs[];
extern unsigned char __files[320];
extern void TRK_PositionFile_Game(void);
extern void TRK_CloseFile_Game(void);
extern void TRK_WriteFile_Game(void);
extern void TRK_ReadFile_Game(void);
extern unsigned char jumptable_8015AFD8[292];
extern unsigned char lbl_80094EC0[24];
extern unsigned char lbl_80094ED8[224];
extern unsigned char lbl_8015AF98[64];
extern unsigned char lbl_8015B100[256];
extern unsigned char lbl_8015B200[256];
extern unsigned char lbl_801A3380[56];

extern int __aborting;
extern int __atexit_curr_func;
extern ExitFunc __console_exit;
extern ExitFunc __stdio_exit;
extern unsigned char lbl_801A6DD8;
extern unsigned char lbl_801A6DE0[8];
extern unsigned char lbl_801A74B0[8];
extern unsigned char lbl_801A74C8[8];
extern unsigned char lbl_801A74D8[8];
extern unsigned char lbl_801A74C0[8];
extern unsigned char lbl_801A74B8[8];
extern unsigned char lbl_801A74D0[8];

void exit(int status);
void fn_8007A150(void* p);
void* fn_8007A1C0(void* p);
void fn_8007A23C(void* pool, void* p);
void* fn_8007A294(void* pool, void* p);
void fn_8007A2E8(void* pool, void* p);
asm void fn_8007A440(void);
void fn_8007A710(void* pool, void* p);
asm void fn_8007A9A4(void);
asm void fn_8007AA7C(void);
void* fn_8007AB58(void** headp, unsigned int size);
asm void fn_8007AC0C(void);
void fn_8007ADF0(void* blk, unsigned int size);
int fn_8007B028(void);
int fn_8007B0B4(void);
void __close_all(void);
asm void __init_file(void);
void* fn_8007B2A8(void);
asm void __sformatter(void);
asm void fn_8007C3B8(void);
asm void MSL_PrintfFloat(void);
asm void fn_8007C910(void);
asm void fn_8007CE0C(void);
asm void MSLFormatDecimalRound(void);
asm void fn_8007E69C(void);
typedef struct div_t { int quot; int rem; } div_t;
div_t fn_8007E914(int numer, int denom);
asm void fn_8007E96C(void);
asm void fn_8007EA58(void);
extern int __flush_buffer(void*, unsigned int*);
int fn_8007EC80(void* file, unsigned int* outp, int flag);
void __end_critical_region(int region);
void __begin_critical_region(int region);
void __kill_critical_regions(void);
unsigned long __fwrite(const void* buf, unsigned long size, unsigned long count, void* file);
unsigned long fwrite(const void* buf, unsigned long size, unsigned long count, void* file);
int fn_8007F13C(void* a, void* b, unsigned long n, void* file);
int fn_8007F48C(void* a, void* b, unsigned long n, void* file);
asm void fn_8007F508(void);
asm void fn_8007F684(void);
int fn_8007F8D4(void* file);
void fn_8007FA0C(void* file);
int fseek(void* file, long offset, int whence);
int fn_8007FC34(void* file, long offset, int whence);
long fn_8007FE70(void* file);

// provenance: original
void exit(int status)
{
    ExitFunc* dtor;

    if (!__aborting) {
        __begin_critical_region(0);
        __end_critical_region(0);
        __destroy_global_chain();

        for (dtor = _dtors; *dtor != 0; dtor++) {
            (*dtor)();
        }

        if (__stdio_exit != 0) {
            __stdio_exit();
            __stdio_exit = 0;
        }
    }

    __begin_critical_region(0);
    while (__atexit_curr_func > 0) {
        __atexit_funcs[--__atexit_curr_func]();
    }
    __end_critical_region(0);
    __kill_critical_regions();

    if (__console_exit != 0) {
        __console_exit();
        __console_exit = 0;
    }

    _ExitProcess();
}

// provenance: original
#pragma dont_inline on
void fn_8007A150(void* p)
{
    __begin_critical_region(1);
    if (!lbl_801A6DD8) {
        memset(lbl_801A3380, 0, 0x34);
        lbl_801A6DD8 = 1;
    }
    fn_8007A23C(lbl_801A3380, p);
    __end_critical_region(1);
}
#pragma dont_inline reset

// provenance: original
#pragma dont_inline on
void* fn_8007A1C0(void* p)
{
    void* res;
    __begin_critical_region(1);
    if (!lbl_801A6DD8) {
        memset(lbl_801A3380, 0, 0x34);
        lbl_801A6DD8 = 1;
    }
    res = fn_8007A294(lbl_801A3380, p);
    __end_critical_region(1);
    return res;
}
#pragma dont_inline reset

// provenance: original
void fn_8007A23C(void* pool, void* p)
{
    unsigned int hdr;
    unsigned int size;

    if (p == 0) {
        return;
    }

    hdr = ((unsigned int*)p)[-1];
    if ((hdr & 1) == 0) {
        size = *(unsigned int*)(hdr + 8);
    } else {
        size = ((unsigned int*)p)[-2] & ~7;
        size -= 8;
    }

    if (size <= 0x44) {
        fn_8007A2E8(pool, p);
    } else {
        fn_8007A710(pool, p);
    }
}

asm void* fn_8007A294(void* pool, void* p)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r4, 0
    stw	r0, 0x14(r1)
    bc      4, 2, _8007a2b0
    li	r3, 0
    b       _8007a2d8
_8007a2b0:
    li	r0, -0x31
    cmplw	r4, r0
    bc      4, 1, _8007a2c4
    li	r3, 0
    b       _8007a2d8
_8007a2c4:
    cmplwi	r4, 0x44
    bc      12, 1, _8007a2d4
    bl      fn_8007A440
    b       _8007a2d8
_8007a2d4:
    bl      fn_8007AA7C
_8007a2d8:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8007A2E8(void* pool, void* p)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r6, lbl_80094EC0@ha
    li	r7, 0
    stw	r0, 0x14(r1)
    addi	r6, r6, lbl_80094EC0@l
    b       _8007a30c
_8007a304:
    addi	r6, r6, 4
    addi	r7, r7, 1
_8007a30c:
    lwz	r0, 0(r6)
    cmplw	r5, r0
    bc      12, 1, _8007a304
    addi	r8, r4, -4
    slwi	r5, r7, 3
    lwz	r4, -4(r4)
    addi	r5, r5, 4
    add	r5, r3, r5
    lwz	r0, 0xc(r4)
    cmplwi	r0, 0
    bc      4, 2, _8007a3a8
    lwz	r6, 4(r5)
    cmplw	r6, r4
    bc      12, 2, _8007a3a8
    lwz	r0, 0(r5)
    cmplw	r0, r4
    bc      4, 2, _8007a368
    lwz	r0, 0(r6)
    stw	r0, 4(r5)
    lwz	r6, 0(r5)
    lwz	r0, 0(r6)
    stw	r0, 0(r5)
    b       _8007a3a8
_8007a368:
    lwz	r0, 4(r4)
    lwz	r6, 0(r4)
    stw	r0, 4(r6)
    lwz	r0, 0(r4)
    lwz	r6, 4(r4)
    stw	r0, 0(r6)
    lwz	r0, 4(r5)
    stw	r0, 4(r4)
    lwz	r6, 4(r4)
    lwz	r0, 0(r6)
    stw	r0, 0(r4)
    lwz	r6, 0(r4)
    stw	r4, 4(r6)
    lwz	r6, 4(r4)
    stw	r4, 0(r6)
    stw	r4, 4(r5)
_8007a3a8:
    lwz	r0, 0xc(r4)
    stw	r0, 4(r8)
    stw	r8, 0xc(r4)
    lwz	r6, 0x10(r4)
    addic.	r0, r6, -1
    stw	r0, 0x10(r4)
    bc      4, 2, _8007a430
    lwz	r0, 4(r5)
    cmplw	r0, r4
    bc      4, 2, _8007a3d8
    lwz	r0, 4(r4)
    stw	r0, 4(r5)
_8007a3d8:
    lwz	r0, 0(r5)
    cmplw	r0, r4
    bc      4, 2, _8007a3ec
    lwz	r0, 0(r4)
    stw	r0, 0(r5)
_8007a3ec:
    lwz	r0, 4(r4)
    lwz	r6, 0(r4)
    stw	r0, 4(r6)
    lwz	r0, 0(r4)
    lwz	r6, 4(r4)
    stw	r0, 0(r6)
    lwz	r0, 4(r5)
    cmplw	r0, r4
    bc      4, 2, _8007a418
    li	r0, 0
    stw	r0, 4(r5)
_8007a418:
    lwz	r0, 0(r5)
    cmplw	r0, r4
    bc      4, 2, _8007a42c
    li	r0, 0
    stw	r0, 0(r5)
_8007a42c:
    bl      fn_8007A710
_8007a430:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8007A440(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r5, lbl_80094EC0@ha
    li	r6, 0
    stw	r0, 0x34(r1)
    addi	r5, r5, lbl_80094EC0@l
    stmw	r26, 0x18(r1)
    mr	r28, r3
    b       _8007a46c
_8007a464:
    addi	r5, r5, 4
    addi	r6, r6, 1
_8007a46c:
    lwz	r0, 0(r5)
    cmplw	r4, r0
    bc      12, 1, _8007a464
    slwi	r4, r6, 3
    addi	r29, r4, 4
    add	r29, r28, r29
    lwz	r4, 4(r29)
    cmplwi	r4, 0
    bc      12, 2, _8007a49c
    lwz	r0, 0xc(r4)
    cmplwi	r0, 0
    bc      4, 2, _8007a6b4
_8007a49c:
    lis     r4, lbl_80094EC0@ha
    slwi	r30, r6, 2
    addi	r31, r4, lbl_80094EC0@l
    li	r5, 0xfec
    lwzx	r4, r31, r30
    addi	r0, r4, 4
    divwu	r27, r5, r0
    cmplwi	r27, 0x100
    bc      4, 1, _8007a4c4
    li	r27, 0x100
_8007a4c4:
    mr	r26, r27
    b       _8007a514
_8007a4cc:
    lwzx	r4, r31, r30
    mr	r3, r28
    addi	r5, r1, 8
    addi	r0, r4, 4
    mullw	r4, r27, r0
    addi	r4, r4, 0x14
    bl      fn_8007A9A4
    cmplwi	r3, 0
    bc      4, 2, _8007a51c
    lwz	r5, 8(r1)
    cmplwi	r5, 0x14
    bc      4, 1, _8007a510
    lwzx	r4, r31, r30
    addi	r5, r5, -0x14
    addi	r0, r4, 4
    divwu	r27, r5, r0
    b       _8007a514
_8007a510:
    li	r27, 0
_8007a514:
    cmplwi	r27, 0xa
    bc      4, 0, _8007a4cc
_8007a51c:
    cmplwi	r3, 0
    bc      4, 2, _8007a554
    cmplw	r27, r26
    bc      4, 0, _8007a554
    lwzx	r4, r31, r30
    mr	r3, r28
    addi	r0, r4, 4
    mullw	r4, r26, r0
    addi	r4, r4, 0x14
    bl      fn_8007AA7C
    cmplwi	r3, 0
    bc      4, 2, _8007a554
    li	r3, 0
    b       _8007a6fc
_8007a554:
    lwz	r4, -4(r3)
    clrlwi.	r0, r4, 0x1f
    bc      4, 2, _8007a568
    lwz	r5, 8(r4)
    b       _8007a574
_8007a568:
    lwz	r0, -8(r3)
    rlwinm	r4, r0, 0, 0, 0x1c
    addi	r5, r4, -8
_8007a574:
    lwz	r0, 4(r29)
    cmplwi	r0, 0
    bc      4, 2, _8007a588
    stw	r3, 4(r29)
    stw	r3, 0(r29)
_8007a588:
    lwzx	r4, r31, r30
    addi	r0, r5, -0x14
    lwz	r9, 4(r29)
    addi	r10, r3, 0x14
    addi	r7, r4, 4
    lwz	r8, 0(r29)
    divwu	r6, r0, r7
    li	r5, 0
    stw	r8, 0(r3)
    stw	r9, 4(r3)
    stw	r3, 4(r8)
    stw	r3, 0(r9)
    addi	r0, r6, -1
    stw	r4, 8(r3)
    cmplwi	r0, 0
    bc      4, 1, _8007a698
    cmplwi	r0, 8
    addi	r4, r6, -9
    bc      4, 1, _8007a670
    addi	r0, r4, 7
    srwi	r0, r0, 3
    mtctr	r0
    cmplwi	r4, 0
    bc      4, 1, _8007a670
_8007a5e8:
    stw	r3, 0(r10)
    add	r0, r10, r7
    mr	r4, r0
    addi	r5, r5, 8
    stw	r0, 4(r10)
    add	r0, r0, r7
    mr	r8, r0
    stw	r3, 0(r4)
    stw	r0, 4(r4)
    add	r0, r0, r7
    mr	r4, r0
    stw	r3, 0(r8)
    stw	r0, 4(r8)
    add	r0, r0, r7
    mr	r8, r0
    stw	r3, 0(r4)
    stw	r0, 4(r4)
    add	r0, r0, r7
    mr	r4, r0
    stw	r3, 0(r8)
    stw	r0, 4(r8)
    add	r0, r0, r7
    mr	r8, r0
    stw	r3, 0(r4)
    stw	r0, 4(r4)
    add	r0, r0, r7
    mr	r4, r0
    stw	r3, 0(r8)
    stw	r0, 4(r8)
    add	r0, r0, r7
    mr	r10, r0
    stw	r3, 0(r4)
    stw	r0, 4(r4)
    bc      16, 0, _8007a5e8
_8007a670:
    addi	r4, r6, -1
    subf	r0, r5, r4
    mtctr	r0
    cmplw	r5, r4
    bc      4, 0, _8007a698
_8007a684:
    stw	r3, 0(r10)
    add	r0, r10, r7
    stw	r0, 4(r10)
    mr	r10, r0
    bc      16, 0, _8007a684
_8007a698:
    stw	r3, 0(r10)
    li	r4, 0
    addi	r0, r3, 0x14
    stw	r4, 4(r10)
    stw	r0, 0xc(r3)
    stw	r4, 0x10(r3)
    stw	r3, 4(r29)
_8007a6b4:
    lwz	r3, 4(r29)
    lwz	r5, 0xc(r3)
    lwz	r0, 4(r5)
    stw	r0, 0xc(r3)
    lwz	r4, 4(r29)
    lwz	r3, 0x10(r4)
    addi	r0, r3, 1
    stw	r0, 0x10(r4)
    lwz	r3, 4(r29)
    lwz	r0, 0xc(r3)
    cmplwi	r0, 0
    bc      4, 2, _8007a6f8
    lwz	r0, 4(r3)
    stw	r0, 4(r29)
    lwz	r3, 0(r29)
    lwz	r0, 4(r3)
    stw	r0, 0(r29)
_8007a6f8:
    addi	r3, r5, 4
_8007a6fc:
    lmw	r26, 0x18(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void fn_8007A710(void* pool, void* p)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    addi	r8, r4, -8
    stw	r0, 0x14(r1)
    lwz	r4, -8(r4)
    lwz	r5, 4(r8)
    rlwinm	r0, r4, 0, 0x1f, 0x1d
    rlwinm	r6, r4, 0, 0, 0x1c
    stw	r0, 0(r8)
    add	r7, r8, r6
    rlwinm	r4, r5, 0, 0, 0x1e
    lwz	r0, 0(r7)
    rlwinm	r0, r0, 0, 0x1e, 0x1c
    stw	r0, 0(r7)
    stw	r6, -4(r7)
    lwz	r0, 0xc(r4)
    rlwinm	r5, r0, 0, 0, 0x1c
    addi	r0, r5, -4
    lwzx	r5, r4, r0
    cmplwi	r5, 0
    bc      12, 2, _8007a8ec
    lwz	r5, 8(r5)
    stw	r5, 8(r8)
    lwz	r5, 8(r8)
    stw	r8, 0xc(r5)
    lwzx	r5, r4, r0
    stw	r5, 0xc(r8)
    lwzx	r5, r4, r0
    stw	r8, 8(r5)
    stwx	r8, r4, r0
    lwzx	r9, r4, r0
    lwz	r5, 0(r9)
    rlwinm.	r5, r5, 0, 0x1d, 0x1d
    bc      4, 2, _8007a828
    lwz	r8, -4(r9)
    rlwinm.	r5, r8, 0, 0x1e, 0x1e
    bc      12, 2, _8007a7ac
    mr	r7, r9
    b       _8007a82c
_8007a7ac:
    subf	r7, r8, r9
    lwz	r5, 0(r7)
    clrlwi	r5, r5, 0x1d
    stw	r5, 0(r7)
    lwz	r5, 0(r9)
    lwz	r6, 0(r7)
    rlwinm	r5, r5, 0, 0, 0x1c
    add	r5, r8, r5
    rlwinm	r5, r5, 0, 0, 0x1c
    or	r5, r6, r5
    stw	r5, 0(r7)
    lwz	r5, 0(r7)
    rlwinm.	r5, r5, 0, 0x1e, 0x1e
    bc      4, 2, _8007a7f8
    lwz	r5, 0(r9)
    rlwinm	r5, r5, 0, 0, 0x1c
    add	r6, r8, r5
    addi	r5, r6, -4
    stwx	r6, r7, r5
_8007a7f8:
    lwzx	r5, r4, r0
    cmplw	r5, r9
    bc      4, 2, _8007a80c
    lwz	r5, 0xc(r5)
    stwx	r5, r4, r0
_8007a80c:
    lwz	r6, 8(r9)
    lwz	r5, 0xc(r9)
    stw	r6, 8(r5)
    lwz	r6, 0xc(r9)
    lwz	r5, 8(r6)
    stw	r6, 0xc(r5)
    b       _8007a82c
_8007a828:
    mr	r7, r9
_8007a82c:
    stwx	r7, r4, r0
    lwzx	r9, r4, r0
    lwz	r6, 0(r9)
    rlwinm	r10, r6, 0, 0, 0x1c
    add	r8, r9, r10
    lwz	r7, 0(r8)
    rlwinm.	r5, r7, 0, 0x1e, 0x1e
    bc      4, 2, _8007a8f8
    clrlwi	r5, r6, 0x1d
    rlwinm	r6, r7, 0, 0, 0x1c
    stw	r5, 0(r9)
    add	r7, r10, r6
    rlwinm	r5, r7, 0, 0, 0x1c
    lwz	r6, 0(r9)
    or	r5, r6, r5
    stw	r5, 0(r9)
    lwz	r5, 0(r9)
    rlwinm.	r5, r5, 0, 0x1e, 0x1e
    bc      4, 2, _8007a880
    addi	r5, r7, -4
    stwx	r7, r9, r5
_8007a880:
    lwz	r5, 0(r9)
    rlwinm.	r5, r5, 0, 0x1e, 0x1e
    bc      4, 2, _8007a89c
    lwzx	r5, r9, r7
    rlwinm	r5, r5, 0, 0x1e, 0x1c
    stwx	r5, r9, r7
    b       _8007a8a8
_8007a89c:
    lwzx	r5, r9, r7
    ori	r5, r5, 4
    stwx	r5, r9, r7
_8007a8a8:
    lwzx	r5, r4, r0
    cmplw	r5, r8
    bc      4, 2, _8007a8bc
    lwz	r5, 0xc(r5)
    stwx	r5, r4, r0
_8007a8bc:
    lwzx	r5, r4, r0
    cmplw	r5, r8
    bc      4, 2, _8007a8d0
    li	r5, 0
    stwx	r5, r4, r0
_8007a8d0:
    lwz	r6, 8(r8)
    lwz	r5, 0xc(r8)
    stw	r6, 8(r5)
    lwz	r6, 0xc(r8)
    lwz	r5, 8(r8)
    stw	r6, 0xc(r5)
    b       _8007a8f8
_8007a8ec:
    stwx	r8, r4, r0
    stw	r8, 8(r8)
    stw	r8, 0xc(r8)
_8007a8f8:
    lwzx	r5, r4, r0
    lwz	r6, 8(r4)
    lwz	r0, 0(r5)
    rlwinm	r0, r0, 0, 0, 0x1c
    cmplw	r6, r0
    bc      4, 0, _8007a914
    stw	r0, 8(r4)
_8007a914:
    lwz	r5, 0x10(r4)
    li	r7, 0
    rlwinm.	r0, r5, 0, 0x1e, 0x1e
    bc      4, 2, _8007a940
    lwz	r0, 0xc(r4)
    rlwinm	r6, r5, 0, 0, 0x1c
    rlwinm	r5, r0, 0, 0, 0x1c
    addi	r0, r5, -0x18
    cmplw	r6, r0
    bc      4, 2, _8007a940
    li	r7, 1
_8007a940:
    cmpwi	r7, 0
    bc      12, 2, _8007a994
    lwz	r5, 4(r4)
    cmplw	r5, r4
    bc      4, 2, _8007a958
    li	r5, 0
_8007a958:
    lwz	r0, 0(r3)
    cmplw	r0, r4
    bc      4, 2, _8007a968
    stw	r5, 0(r3)
_8007a968:
    cmplwi	r5, 0
    bc      12, 2, _8007a980
    lwz	r0, 0(r4)
    stw	r0, 0(r5)
    lwz	r3, 0(r5)
    stw	r5, 4(r3)
_8007a980:
    li	r0, 0
    mr	r3, r4
    stw	r0, 4(r4)
    stw	r0, 0(r4)
    bl      fn_80079EF0
_8007a994:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_8007A9A4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    addi	r0, r4, 0xf
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    mr	r30, r5
    stw	r29, 0x14(r1)
    rlwinm	r29, r0, 0, 0, 0x1c
    cmplwi	r29, 0x50
    stw	r28, 0x10(r1)
    mr	r28, r3
    bc      4, 0, _8007a9dc
    li	r29, 0x50
_8007a9dc:
    li	r0, 0
    stw	r0, 0(r30)
    lwz	r31, 0(r28)
    cmplwi	r31, 0
    bc      4, 2, _8007a9f8
    li	r3, 0
    b       _8007aa5c
_8007a9f8:
    lwz	r0, 8(r31)
    cmplw	r29, r0
    bc      12, 1, _8007aa20
    mr	r3, r31
    mr	r4, r29
    bl      fn_8007AC0C
    cmplwi	r3, 0
    bc      12, 2, _8007aa20
    stw	r31, 0(r28)
    b       _8007aa58
_8007aa20:
    lwz	r3, 8(r31)
    cmplwi	r3, 8
    bc      4, 1, _8007aa40
    lwz	r0, 0(r30)
    addi	r3, r3, -8
    cmplw	r0, r3
    bc      4, 0, _8007aa40
    stw	r3, 0(r30)
_8007aa40:
    lwz	r31, 4(r31)
    lwz	r0, 0(r28)
    cmplw	r31, r0
    bc      4, 2, _8007a9f8
    li	r3, 0
    b       _8007aa5c
_8007aa58:
    addi	r3, r3, 8
_8007aa5c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8007AA7C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    addi	r0, r4, 0xf
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    rlwinm	r30, r0, 0, 0, 0x1c
    cmplwi	r30, 0x50
    stw	r29, 0x14(r1)
    mr	r29, r3
    bc      4, 0, _8007aaac
    li	r30, 0x50
_8007aaac:
    lwz	r3, 0(r29)
    cmplwi	r3, 0
    bc      12, 2, _8007aabc
    b       _8007aac8
_8007aabc:
    mr	r3, r29
    mr	r4, r30
    bl      fn_8007AB58
_8007aac8:
    cmplwi	r3, 0
    mr	r31, r3
    bc      4, 2, _8007aadc
    li	r3, 0
    b       _8007ab3c
_8007aadc:
    lwz	r0, 8(r31)
    cmplw	r30, r0
    bc      12, 1, _8007ab04
    mr	r3, r31
    mr	r4, r30
    bl      fn_8007AC0C
    cmplwi	r3, 0
    bc      12, 2, _8007ab04
    stw	r31, 0(r29)
    b       _8007ab38
_8007ab04:
    lwz	r31, 4(r31)
    lwz	r0, 0(r29)
    cmplw	r31, r0
    bc      4, 2, _8007aadc
    mr	r3, r29
    mr	r4, r30
    bl      fn_8007AB58
    cmplwi	r3, 0
    bc      4, 2, _8007ab30
    li	r3, 0
    b       _8007ab3c
_8007ab30:
    mr	r4, r30
    bl      fn_8007AC0C
_8007ab38:
    addi	r3, r3, 8
_8007ab3c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

// provenance: original
void* fn_8007AB58(void** headp, unsigned int size)
{
    void** blk;
    unsigned int n;

    n = (size + 0x1F) & ~7;
    if (n < 0x10000) {
        n = 0x10000;
    }

    blk = (void**)fn_80079FA8(n);
    if (blk == 0) {
        return 0;
    }
    fn_8007ADF0(blk, n);

    if (*headp != 0) {
        blk[0] = ((void**)*headp)[0];
        ((void**)blk[0])[1] = blk;
        blk[1] = *headp;
        ((void**)*headp)[0] = blk;
        *headp = blk;
    } else {
        *headp = blk;
        blk[0] = blk;
        blk[1] = blk;
    }
    return blk;
}

asm void fn_8007AC0C(void)
{
    nofralloc
    lwz	r0, 0xc(r3)
    rlwinm	r5, r0, 0, 0, 0x1c
    addi	r0, r5, -4
    lwzx	r5, r3, r0
    cmplwi	r5, 0
    bc      4, 2, _8007ac34
    li	r0, 0
    stw	r0, 8(r3)
    li	r3, 0
    blr
_8007ac34:
    lwz	r0, 0(r5)
    mr	r6, r5
    rlwinm	r0, r0, 0, 0, 0x1c
    mr	r7, r0
    b       _8007ac74
_8007ac48:
    lwz	r6, 0xc(r6)
    lwz	r0, 0(r6)
    rlwinm	r0, r0, 0, 0, 0x1c
    cmplw	r7, r0
    bc      4, 0, _8007ac60
    mr	r7, r0
_8007ac60:
    cmplw	r6, r5
    bc      4, 2, _8007ac74
    stw	r7, 8(r3)
    li	r3, 0
    blr
_8007ac74:
    cmplw	r0, r4
    bc      12, 0, _8007ac48
    subf	r0, r4, r0
    cmplwi	r0, 0x50
    bc      12, 0, _8007ad64
    lwz	r0, 4(r6)
    add	r5, r6, r4
    lwz	r9, 0(r6)
    rlwinm	r7, r0, 0, 0, 0x1e
    ori	r10, r7, 1
    rlwinm	r8, r9, 0, 0x1e, 0x1e
    rlwinm.	r0, r9, 0, 0x1d, 0x1d
    stw	r10, 4(r6)
    cntlzw	r7, r8
    rlwinm	r9, r9, 0, 0, 0x1c
    srwi	r8, r7, 5
    stw	r4, 0(r6)
    cntlzw	r0, r8
    srwi	r7, r0, 5
    bc      12, 2, _8007acd0
    lwz	r0, 0(r6)
    ori	r0, r0, 4
    stw	r0, 0(r6)
_8007acd0:
    cmpwi	r7, 0
    bc      12, 2, _8007acf4
    lwz	r0, 0(r6)
    ori	r0, r0, 2
    stw	r0, 0(r6)
    lwz	r0, 0(r5)
    ori	r0, r0, 4
    stw	r0, 0(r5)
    b       _8007acf8
_8007acf4:
    stw	r4, -4(r5)
_8007acf8:
    stw	r10, 4(r5)
    subf	r4, r4, r9
    cmpwi	r7, 0
    stw	r4, 0(r5)
    bc      12, 2, _8007ad18
    lwz	r0, 0(r5)
    ori	r0, r0, 4
    stw	r0, 0(r5)
_8007ad18:
    cmpwi	r7, 0
    bc      12, 2, _8007ad3c
    lwz	r0, 0(r5)
    ori	r0, r0, 2
    stw	r0, 0(r5)
    lwzx	r0, r5, r4
    ori	r0, r0, 4
    stwx	r0, r5, r4
    b       _8007ad44
_8007ad3c:
    addi	r0, r4, -4
    stwx	r4, r5, r0
_8007ad44:
    cmpwi	r8, 0
    bc      12, 2, _8007ad64
    lwz	r0, 0xc(r6)
    stw	r0, 0xc(r5)
    lwz	r4, 0xc(r5)
    stw	r5, 8(r4)
    stw	r6, 8(r5)
    stw	r5, 0xc(r6)
_8007ad64:
    lwz	r0, 0xc(r3)
    lwz	r5, 0xc(r6)
    rlwinm	r4, r0, 0, 0, 0x1c
    addi	r0, r4, -4
    stwx	r5, r3, r0
    lwz	r4, 0(r6)
    ori	r0, r4, 2
    rlwinm	r4, r4, 0, 0, 0x1c
    stw	r0, 0(r6)
    lwzx	r0, r6, r4
    ori	r0, r0, 4
    stwx	r0, r6, r4
    lwz	r0, 0xc(r3)
    rlwinm	r4, r0, 0, 0, 0x1c
    addi	r4, r4, -4
    lwzx	r0, r3, r4
    cmplw	r0, r6
    bc      4, 2, _8007adb4
    lwz	r0, 0xc(r6)
    stwx	r0, r3, r4
_8007adb4:
    lwzx	r0, r3, r4
    cmplw	r0, r6
    bc      4, 2, _8007add0
    li	r0, 0
    stwx	r0, r3, r4
    stw	r0, 8(r3)
    b       _8007ade8
_8007add0:
    lwz	r0, 8(r6)
    lwz	r3, 0xc(r6)
    stw	r0, 8(r3)
    lwz	r0, 0xc(r6)
    lwz	r3, 8(r6)
    stw	r0, 0xc(r3)
_8007ade8:
    mr	r3, r6
    blr
}

asm void fn_8007ADF0(void* blk, unsigned int size)
{
    nofralloc
    ori	r0, r4, 3
    addi	r9, r3, 0x10
    stw	r0, 0xc(r3)
    addi	r7, r4, -8
    ori	r6, r3, 1
    addi	r0, r4, -0x18
    lwz	r8, 0xc(r3)
    add	r4, r4, r9
    li	r5, 0
    stwx	r8, r3, r7
    stw	r6, 0x14(r3)
    stw	r0, 0x10(r3)
    stw	r0, -0x1c(r4)
    stw	r0, 8(r3)
    lwz	r0, 0xc(r3)
    rlwinm	r4, r0, 0, 0, 0x1c
    addi	r0, r4, -4
    stwx	r5, r3, r0
    lwz	r4, 0x10(r3)
    rlwinm	r0, r4, 0, 0x1f, 0x1d
    rlwinm	r4, r4, 0, 0, 0x1c
    stw	r0, 0x10(r3)
    add	r5, r9, r4
    lwz	r0, 0(r5)
    rlwinm	r0, r0, 0, 0x1e, 0x1c
    stw	r0, 0(r5)
    stw	r4, -4(r5)
    lwz	r0, 0xc(r3)
    rlwinm	r4, r0, 0, 0, 0x1c
    addi	r0, r4, -4
    lwzx	r4, r3, r0
    cmplwi	r4, 0
    bc      12, 2, _8007affc
    lwz	r4, 8(r4)
    stw	r4, 8(r9)
    lwz	r4, 8(r9)
    stw	r9, 0xc(r4)
    lwzx	r4, r3, r0
    stw	r4, 0xc(r9)
    lwzx	r4, r3, r0
    stw	r9, 8(r4)
    stwx	r9, r3, r0
    lwzx	r8, r3, r0
    lwz	r4, 0(r8)
    rlwinm.	r4, r4, 0, 0x1d, 0x1d
    bc      4, 2, _8007af38
    lwz	r7, -4(r8)
    rlwinm.	r4, r7, 0, 0x1e, 0x1e
    bc      12, 2, _8007aebc
    mr	r6, r8
    b       _8007af3c
_8007aebc:
    subf	r6, r7, r8
    lwz	r4, 0(r6)
    clrlwi	r4, r4, 0x1d
    stw	r4, 0(r6)
    lwz	r4, 0(r8)
    lwz	r5, 0(r6)
    rlwinm	r4, r4, 0, 0, 0x1c
    add	r4, r7, r4
    rlwinm	r4, r4, 0, 0, 0x1c
    or	r4, r5, r4
    stw	r4, 0(r6)
    lwz	r4, 0(r6)
    rlwinm.	r4, r4, 0, 0x1e, 0x1e
    bc      4, 2, _8007af08
    lwz	r4, 0(r8)
    rlwinm	r4, r4, 0, 0, 0x1c
    add	r5, r7, r4
    addi	r4, r5, -4
    stwx	r5, r6, r4
_8007af08:
    lwzx	r4, r3, r0
    cmplw	r4, r8
    bc      4, 2, _8007af1c
    lwz	r4, 0xc(r4)
    stwx	r4, r3, r0
_8007af1c:
    lwz	r5, 8(r8)
    lwz	r4, 0xc(r8)
    stw	r5, 8(r4)
    lwz	r5, 0xc(r8)
    lwz	r4, 8(r5)
    stw	r5, 0xc(r4)
    b       _8007af3c
_8007af38:
    mr	r6, r8
_8007af3c:
    stwx	r6, r3, r0
    lwzx	r8, r3, r0
    lwz	r5, 0(r8)
    rlwinm	r9, r5, 0, 0, 0x1c
    add	r7, r8, r9
    lwz	r6, 0(r7)
    rlwinm.	r4, r6, 0, 0x1e, 0x1e
    bc      4, 2, _8007b008
    clrlwi	r4, r5, 0x1d
    rlwinm	r5, r6, 0, 0, 0x1c
    stw	r4, 0(r8)
    add	r6, r9, r5
    rlwinm	r4, r6, 0, 0, 0x1c
    lwz	r5, 0(r8)
    or	r4, r5, r4
    stw	r4, 0(r8)
    lwz	r4, 0(r8)
    rlwinm.	r4, r4, 0, 0x1e, 0x1e
    bc      4, 2, _8007af90
    addi	r4, r6, -4
    stwx	r6, r8, r4
_8007af90:
    lwz	r4, 0(r8)
    rlwinm.	r4, r4, 0, 0x1e, 0x1e
    bc      4, 2, _8007afac
    lwzx	r4, r8, r6
    rlwinm	r4, r4, 0, 0x1e, 0x1c
    stwx	r4, r8, r6
    b       _8007afb8
_8007afac:
    lwzx	r4, r8, r6
    ori	r4, r4, 4
    stwx	r4, r8, r6
_8007afb8:
    lwzx	r4, r3, r0
    cmplw	r4, r7
    bc      4, 2, _8007afcc
    lwz	r4, 0xc(r4)
    stwx	r4, r3, r0
_8007afcc:
    lwzx	r4, r3, r0
    cmplw	r4, r7
    bc      4, 2, _8007afe0
    li	r4, 0
    stwx	r4, r3, r0
_8007afe0:
    lwz	r5, 8(r7)
    lwz	r4, 0xc(r7)
    stw	r5, 8(r4)
    lwz	r5, 0xc(r7)
    lwz	r4, 8(r7)
    stw	r5, 0xc(r4)
    b       _8007b008
_8007affc:
    stwx	r9, r3, r0
    stw	r9, 8(r9)
    stw	r9, 0xc(r9)
_8007b008:
    lwzx	r4, r3, r0
    lwz	r5, 8(r3)
    lwz	r0, 0(r4)
    rlwinm	r0, r0, 0, 0, 0x1c
    cmplw	r5, r0
    bgelr	
    stw	r0, 8(r3)
    blr
}

// provenance: original
int fn_8007B028(void)
{
    int result;
    char* f;

    result = 0;
    f = (char*)__files;
    while (f != 0) {
        if (((*(unsigned short*)(f + 4) >> 6) & 7) != 0 &&
            ((*(unsigned char*)(f + 4) >> 1) & 1) != 0 &&
            (unsigned int)((*(unsigned char*)(f + 8) >> 5) & 7) == 1) {
            if (fn_8007F8D4(f) != 0) {
                result = -1;
            }
        }
        f = *(char**)(f + 0x4C);
    }
    return result;
}

// provenance: original
#pragma dont_inline on
int fn_8007B0B4(void)
{
    int result;
    char* f;

    result = 0;
    f = (char*)__files;
    while (f != 0) {
        if (((*(unsigned short*)(f + 4) >> 6) & 7) != 0) {
            if (fn_8007F8D4(f) != 0) {
                result = -1;
            }
        }
        f = *(char**)(f + 0x4C);
    }
    return result;
}
#pragma dont_inline reset

// provenance: mkdd:libs/PowerPC_EABI_Support/src/MSL_C/MSL_Common/ansi_files.c:116
void __close_all(void)
{
    char* f;
    char* cur;

    f = (char*)__files;
    __begin_critical_region(2);
    while (f != 0) {
        if (((*(unsigned short*)(f + 4) >> 6) & 7) != 0) {
            fn_8007FA0C(f);
        }
        cur = f;
        f = *(char**)(cur + 0x4C);
        if (*(unsigned char*)(cur + 0xC) != 0) {
            fn_8007A150(cur);
        } else {
            ((FileMode*)(cur + 4))->mode = 3;
            if (f != 0 && *(unsigned char*)(f + 0xC) != 0) {
                *(char**)(cur + 0x4C) = 0;
            }
        }
    }
    __end_critical_region(2);
}

asm void __init_file(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r7, 0
    cmplwi	r6, 0
    stw	r0, 0x14(r1)
    lwz	r0, 0(r4)
    stw	r31, 0xc(r1)
    mr	r31, r3
    stw	r7, 0(r3)
    stw	r0, 4(r3)
    lbz	r0, 8(r3)
    rlwimi	r0, r7, 5, 0x18, 0x1a
    stb	r0, 8(r3)
    lbz	r0, 8(r3)
    rlwimi	r0, r7, 4, 0x1b, 0x1b
    stb	r0, 8(r3)
    stb	r7, 9(r3)
    stb	r7, 0xa(r3)
    stw	r7, 0x18(r3)
    bc      12, 2, _8007b22c
    mr	r4, r5
    li	r5, 2
    bl      fn_8007EA58
    b       _8007b23c
_8007b22c:
    li	r4, 0
    li	r5, 0
    li	r6, 0
    bl      fn_8007EA58
_8007b23c:
    lwz	r3, 0x1c(r31)
    li	r0, 0
    stw	r3, 0x24(r31)
    stw	r0, 0x28(r31)
    lhz	r0, 4(r31)
    rlwinm	r0, r0, 0x1a, 0x1d, 0x1f
    cmplwi	r0, 1
    bc      4, 2, _8007b28c
    lis     r4, TRK_PositionFile_Game@ha
    lis     r3, TRK_ReadFile_Game@ha
    addi	r0, r4, TRK_PositionFile_Game@l
    lis     r4, TRK_WriteFile_Game@ha
    stw	r0, 0x38(r31)
    addi	r0, r3, TRK_ReadFile_Game@l
    lis     r3, TRK_CloseFile_Game@ha
    addi	r4, r4, TRK_WriteFile_Game@l
    stw	r0, 0x3c(r31)
    addi	r0, r3, TRK_CloseFile_Game@l
    stw	r4, 0x40(r31)
    stw	r0, 0x44(r31)
_8007b28c:
    li	r0, 0
    stw	r0, 0x48(r31)
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

// provenance: original
void* fn_8007B2A8(void)
{
    char* nf;
    char* f;
    char* prev;

    f = *(char**)((char*)__files + 0xEC);
    while (f != 0) {
        if (((*(unsigned short*)(f + 4) >> 6) & 7) == 0) {
            return f;
        }
        prev = f;
        f = *(char**)(f + 0x4C);
    }

    nf = (char*)fn_8007A1C0((void*)0x50);
    if (nf != 0) {
        memset(nf, 0, 0x50);
        *(unsigned char*)(nf + 0xC) = 1;
        *(char**)(prev + 0x4C) = nf;
        return nf;
    }
    return 0;
}

asm void __sformatter(void)
{
    nofralloc
    stwu	r1, -0x1f0(r1)
    mflr	r0
    stw	r0, 0x1f4(r1)
    lbz	r0, 4(r3)
    stw	r31, 0x1ec(r1)
    cmplwi	r0, 0
    stw	r30, 0x1e8(r1)
    stw	r29, 0x1e4(r1)
    bc      4, 2, _8007b380
    lbz	r0, 0(r3)
    lfd f1, lbl_801A74B0(r2)
    extsb.	r0, r0
    bc      4, 2, _8007b374
    lfd f2, lbl_801A74B8(r2)
    b       _8007b378
_8007b374:
    lfd f2, lbl_801A74C0(r2)
_8007b378:
    bl      __fp_compare_greater_equal
    b       _8007c39c
_8007b380:
    lbz	r0, 5(r3)
    cmpwi	r0, 0x49
    bc      12, 2, _8007b3cc
    bc      4, 0, _8007b39c
    cmpwi	r0, 0x30
    bc      12, 2, _8007b3a8
    b       _8007b51c
_8007b39c:
    cmpwi	r0, 0x4e
    bc      12, 2, _8007b3f4
    b       _8007b51c
_8007b3a8:
    lbz	r0, 0(r3)
    lfd f1, lbl_801A74B0(r2)
    extsb.	r0, r0
    bc      4, 2, _8007b3c0
    lfd f2, lbl_801A74B8(r2)
    b       _8007b3c4
_8007b3c0:
    lfd f2, lbl_801A74C0(r2)
_8007b3c4:
    bl      __fp_compare_greater_equal
    b       _8007c39c
_8007b3cc:
    lbz	r0, 0(r3)
    lis	r3, lbl_801A664C@ha
    lfs	f1, lbl_801A664C@l(r3)
    extsb.	r0, r0
    bc      4, 2, _8007b3e8
    lfd f2, lbl_801A74B8(r2)
    b       _8007b3ec
_8007b3e8:
    lfd f2, lbl_801A74C0(r2)
_8007b3ec:
    bl      __fp_compare_greater_equal
    b       _8007c39c
_8007b3f4:
    lbz	r0, 0(r3)
    li	r5, 0
    lis	r4, 0x7ff0
    stw	r5, 0x3c(r1)
    extsb.	r0, r0
    stw	r4, 0x38(r1)
    bc      12, 2, _8007b420
    lis	r0, -0x8000
    stw	r5, 0x3c(r1)
    or	r0, r4, r0
    stw	r0, 0x38(r1)
_8007b420:
    lbz	r0, 4(r3)
    cmplwi	r0, 1
    bc      4, 2, _8007b440
    lwz	r3, 0x38(r1)
    lis	r0, 8
    or	r0, r3, r0
    stw	r0, 0x38(r1)
    b       _8007b514
_8007b440:
    cmpwi	r0, 0xe
    mr	r6, r0
    addi	r7, r1, 0x39
    li	r8, 0
    li	r9, 1
    bc      4, 1, _8007b45c
    li	r6, 0xe
_8007b45c:
    lis     r4, lbl_8015B100@ha
    addi	r0, r6, -1
    addi	r5, r4, lbl_8015B100@l
    li	r10, 1
    mtctr	r0
    cmpwi	r6, 1
    bc      4, 1, _8007b4fc
_8007b478:
    addi	r0, r10, 5
    lbzx	r6, r3, r0
    lbzx	r0, r5, r6
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bc      12, 2, _8007b494
    addi	r4, r6, -0x30
    b       _8007b4b8
_8007b494:
    cmpwi	r6, -1
    bc      4, 2, _8007b4a4
    li	r4, -1
    b       _8007b4b0
_8007b4a4:
    lis     r4, lbl_8015B200@ha
    addi	r4, r4, lbl_8015B200@l
    lbzx	r4, r4, r6
_8007b4b0:
    addi	r0, r4, -0x57
    clrlwi	r4, r0, 0x18
_8007b4b8:
    clrlwi.	r0, r4, 0x18
    bc      12, 2, _8007b4c4
    li	r8, 1
_8007b4c4:
    cmpwi	r9, 0
    bc      12, 2, _8007b4e0
    lbz	r0, 0(r7)
    or	r0, r0, r4
    stb	r0, 0(r7)
    addi	r7, r7, 1
    b       _8007b4e8
_8007b4e0:
    rlwinm	r0, r4, 4, 0x18, 0x1b
    stb	r0, 0(r7)
_8007b4e8:
    cntlzw	r0, r9
    addi	r10, r10, 1
    srwi	r0, r0, 5
    mr	r9, r0
    bc      16, 0, _8007b478
_8007b4fc:
    cmpwi	r8, 0
    bc      4, 2, _8007b514
    lwz	r3, 0x38(r1)
    lis	r0, 8
    or	r0, r3, r0
    stw	r0, 0x38(r1)
_8007b514:
    lfd	f1, 0x38(r1)
    b       _8007c39c
_8007b51c:
    lwz	r0, 4(r3)
    addi	r30, r1, 0x1a5
    lwz	r29, 0(r3)
    mr	r31, r30
    stw	r0, 0x1a4(r1)
    lwz	r12, 8(r3)
    lbz	r0, 0x1a4(r1)
    lwz	r11, 0xc(r3)
    add	r0, r30, r0
    lwz	r10, 0x10(r3)
    lwz	r9, 0x14(r3)
    cmplw	r30, r0
    lwz	r8, 0x18(r3)
    subf	r4, r30, r0
    lwz	r7, 0x1c(r3)
    lwz	r6, 0x20(r3)
    lwz	r5, 0x24(r3)
    lhz	r3, 0x28(r3)
    stw	r29, 0x1a0(r1)
    stw	r12, 0x1a8(r1)
    stw	r11, 0x1ac(r1)
    stw	r10, 0x1b0(r1)
    stw	r9, 0x1b4(r1)
    stw	r8, 0x1b8(r1)
    stw	r7, 0x1bc(r1)
    stw	r6, 0x1c0(r1)
    stw	r5, 0x1c4(r1)
    sth	r3, 0x1c8(r1)
    bc      4, 0, _8007b624
    rlwinm.	r3, r4, 0x1d, 3, 0x1f
    mtctr	r3
    bc      12, 2, _8007b60c
_8007b59c:
    lbz	r3, 0(r31)
    addi	r3, r3, -0x30
    stb	r3, 0(r31)
    lbz	r3, 1(r31)
    addi	r3, r3, -0x30
    stb	r3, 1(r31)
    lbz	r3, 2(r31)
    addi	r3, r3, -0x30
    stb	r3, 2(r31)
    lbz	r3, 3(r31)
    addi	r3, r3, -0x30
    stb	r3, 3(r31)
    lbz	r3, 4(r31)
    addi	r3, r3, -0x30
    stb	r3, 4(r31)
    lbz	r3, 5(r31)
    addi	r3, r3, -0x30
    stb	r3, 5(r31)
    lbz	r3, 6(r31)
    addi	r3, r3, -0x30
    stb	r3, 6(r31)
    lbz	r3, 7(r31)
    addi	r3, r3, -0x30
    stb	r3, 7(r31)
    addi	r31, r31, 8
    bc      16, 0, _8007b59c
    andi.	r4, r4, 7
    bc      12, 2, _8007b624
_8007b60c:
    mtctr	r4
_8007b610:
    lbz	r3, 0(r31)
    addi	r3, r3, -0x30
    stb	r3, 0(r31)
    addi	r31, r31, 1
    bc      16, 0, _8007b610
_8007b624:
    lbz	r4, 0x1a5(r1)
    lis	r7, 0x4330
    lis     r3, lbl_8015AF98@ha
    stw	r7, 0x1d0(r1)
    lfd f3, lbl_801A74D0(r2)
    addi	r8, r30, 1
    stw	r4, 0x1d4(r1)
    addi	r5, r3, lbl_8015AF98@l
    lha	r4, 0x1a2(r1)
    lfd	f0, 0x1d0(r1)
    lbz	r3, 0x1a4(r1)
    fsub	f0, f0, f3
    add	r3, r3, r4
    addi	r4, r3, -1
    extsh	r3, r4
    sth	r4, 0x1a2(r1)
    mr	r31, r3
    stfd	f0, 0x30(r1)
    b       _8007b774
_8007b670:
    subf	r4, r8, r0
    li	r9, 0
    slwi	r3, r4, 0x1d
    srwi	r4, r4, 0x1f
    subf	r3, r4, r3
    rotlwi	r3, r3, 3
    add.	r10, r3, r4
    bc      4, 2, _8007b694
    li	r10, 8
_8007b694:
    cmpwi	r10, 0
    mr	r4, r10
    bc      4, 1, _8007b734
    rlwinm.	r3, r10, 0x1d, 3, 0x1f
    mtctr	r3
    bc      12, 2, _8007b71c
_8007b6ac:
    mulli	r3, r9, 0xa
    lbz	r6, 0(r8)
    add	r9, r6, r3
    lbz	r6, 1(r8)
    mulli	r3, r9, 0xa
    add	r9, r6, r3
    lbz	r6, 2(r8)
    mulli	r3, r9, 0xa
    add	r9, r6, r3
    lbz	r6, 3(r8)
    mulli	r3, r9, 0xa
    add	r9, r6, r3
    lbz	r6, 4(r8)
    mulli	r3, r9, 0xa
    add	r9, r6, r3
    lbz	r6, 5(r8)
    mulli	r3, r9, 0xa
    add	r9, r6, r3
    lbz	r6, 6(r8)
    mulli	r3, r9, 0xa
    add	r9, r6, r3
    lbz	r6, 7(r8)
    mulli	r3, r9, 0xa
    addi	r8, r8, 8
    add	r9, r6, r3
    bc      16, 0, _8007b6ac
    andi.	r4, r4, 7
    bc      12, 2, _8007b734
_8007b71c:
    mtctr	r4
_8007b720:
    mulli	r3, r9, 0xa
    lbz	r6, 0(r8)
    addi	r8, r8, 1
    add	r9, r6, r3
    bc      16, 0, _8007b720
_8007b734:
    slwi	r3, r10, 3
    stw	r9, 0x1d4(r1)
    add	r3, r5, r3
    lfd	f2, 0x30(r1)
    stw	r7, 0x1d0(r1)
    cmplwi	r9, 0
    lfd	f1, -8(r3)
    lfd	f0, 0x1d0(r1)
    fmul	f1, f2, f1
    fsub	f0, f0, f3
    fadd	f0, f1, f0
    bc      12, 2, _8007b76c
    fcmpu	cr0, f1, f0
    bc      12, 2, _8007b77c
_8007b76c:
    stfd	f0, 0x30(r1)
    subf	r31, r10, r31
_8007b774:
    cmplw	r8, r0
    bc      12, 0, _8007b670
_8007b77c:
    cmpwi	r31, 0
    bc      4, 0, _8007b7b8
    neg	r3, r31
    lis	r0, 0x4330
    xoris	r3, r3, 0x8000
    stw	r0, 0x1d0(r1)
    lfd f2, lbl_801A74D8(r2)
    stw	r3, 0x1d4(r1)
    lfd f1, lbl_801A74C8(r2)
    lfd	f0, 0x1d0(r1)
    fsub	f2, f0, f2
    bl      __msl_fp_helper
    lfd	f0, 0x30(r1)
    fdiv	f1, f0, f1
    b       _8007b7e4
_8007b7b8:
    xoris	r3, r31, 0x8000
    lis	r0, 0x4330
    stw	r3, 0x1dc(r1)
    lfd f2, lbl_801A74D8(r2)
    stw	r0, 0x1d8(r1)
    lfd f1, lbl_801A74C8(r2)
    lfd	f0, 0x1d8(r1)
    fsub	f2, f0, f2
    bl      __msl_fp_helper
    lfd	f0, 0x30(r1)
    fmul	f1, f0, f1
_8007b7e4:
    stfd	f1, 0x30(r1)
    mr	r3, r31
    bl      __fpclassifyd
    stfd	f1, 0x18(r1)
    lis	r0, 0x7ff0
    lwz	r4, 0x18(r1)
    stfd	f1, 0x30(r1)
    rlwinm	r3, r4, 0, 1, 0xb
    cmpw	r3, r0
    bc      12, 2, _8007b81c
    bc      4, 0, _8007b864
    cmpwi	r3, 0
    bc      12, 2, _8007b840
    b       _8007b864
_8007b81c:
    clrlwi.	r0, r4, 0xc
    bc      4, 2, _8007b830
    lwz	r0, 0x1c(r1)
    cmpwi	r0, 0
    bc      12, 2, _8007b838
_8007b830:
    li	r0, 1
    b       _8007b868
_8007b838:
    li	r0, 2
    b       _8007b868
_8007b840:
    clrlwi.	r0, r4, 0xc
    bc      4, 2, _8007b854
    lwz	r0, 0x1c(r1)
    cmpwi	r0, 0
    bc      12, 2, _8007b85c
_8007b854:
    li	r0, 5
    b       _8007b868
_8007b85c:
    li	r0, 3
    b       _8007b868
_8007b864:
    li	r0, 4
_8007b868:
    cmpwi	r0, 2
    bc      4, 2, _8007ba88
    li	r5, 0
    li	r0, 0x134
    lis     r3, lbl_80094ED8@ha
    stb	r5, 0x174(r1)
    addi	r6, r3, lbl_80094ED8@l
    sth	r0, 0x176(r1)
    addi	r3, r1, 0x174
    b       _8007b8a8
_8007b890:
    lbz	r4, 0(r6)
    addi	r0, r5, 5
    addi	r6, r6, 1
    addi	r5, r5, 1
    addi	r4, r4, -0x30
    stbx	r4, r3, r0
_8007b8a8:
    cmpwi	r5, 0x24
    bc      4, 0, _8007b8bc
    lbz	r0, 0(r6)
    extsb.	r0, r0
    bc      4, 2, _8007b890
_8007b8bc:
    lbz	r3, 0(r6)
    stb	r5, 0x178(r1)
    extsb.	r0, r3
    bc      12, 2, _8007b968
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007b968
    bc      12, 1, _8007b910
    addi	r3, r6, 1
    b       _8007b8f4
_8007b8e4:
    extsb	r0, r4
    cmpwi	r0, 0x30
    bc      4, 2, _8007b910
    addi	r3, r3, 1
_8007b8f4:
    lbz	r4, 0(r3)
    extsb.	r0, r4
    bc      4, 2, _8007b8e4
    addi	r3, r1, 0x178
    lbzx	r0, r3, r5
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007b968
_8007b910:
    lbz	r3, 0x178(r1)
    addi	r5, r1, 0x179
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007b924:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007b93c
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007b968
_8007b93c:
    cmplw	r4, r5
    bc      4, 2, _8007b95c
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 0x176(r1)
    addi	r0, r3, 1
    sth	r0, 0x176(r1)
    b       _8007b968
_8007b95c:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007b924
_8007b968:
    lbz	r0, 0x179(r1)
    cmplwi	r0, 0
    bc      4, 2, _8007b990
    lbz	r0, 0x1a5(r1)
    cmplwi	r0, 0
    bc      12, 2, _8007b988
    li	r0, 1
    b       _8007ba74
_8007b988:
    li	r0, 0
    b       _8007ba74
_8007b990:
    lbz	r0, 0x1a5(r1)
    cmplwi	r0, 0
    bc      4, 2, _8007b9a4
    li	r0, 0
    b       _8007ba74
_8007b9a4:
    lha	r0, 0x176(r1)
    lha	r4, 0x1a2(r1)
    cmpw	r0, r4
    bc      4, 2, _8007ba60
    lbz	r9, 0x178(r1)
    lbz	r6, 0x1a4(r1)
    mr	r0, r9
    cmpw	r9, r6
    bc      4, 1, _8007b9cc
    mr	r0, r6
_8007b9cc:
    addi	r4, r1, 0x1a0
    addi	r5, r1, 0x174
    li	r3, 0
    mtctr	r0
    cmpwi	r0, 0
    bc      4, 1, _8007ba1c
_8007b9e4:
    lbz	r7, 5(r5)
    lbz	r8, 5(r4)
    cmplw	r7, r8
    bc      4, 0, _8007b9fc
    li	r0, 1
    b       _8007ba74
_8007b9fc:
    cmplw	r8, r7
    bc      4, 0, _8007ba0c
    li	r0, 0
    b       _8007ba74
_8007ba0c:
    addi	r4, r4, 1
    addi	r5, r5, 1
    addi	r3, r3, 1
    bc      16, 0, _8007b9e4
_8007ba1c:
    cmpw	r0, r9
    bc      4, 2, _8007ba58
    addi	r4, r1, 0x1a0
    subf	r0, r3, r6
    add	r4, r4, r3
    mtctr	r0
    cmpw	r3, r6
    bc      4, 0, _8007ba58
_8007ba3c:
    lbz	r0, 5(r4)
    cmplwi	r0, 0
    bc      12, 2, _8007ba50
    li	r0, 1
    b       _8007ba74
_8007ba50:
    addi	r4, r4, 1
    bc      16, 0, _8007ba3c
_8007ba58:
    li	r0, 0
    b       _8007ba74
_8007ba60:
    xor	r0, r4, r0
    srawi	r3, r0, 1
    and	r0, r0, r4
    subf	r0, r0, r3
    srwi	r0, r0, 0x1f
_8007ba74:
    cmpwi	r0, 0
    bc      4, 2, _8007c380
    lis	r3, lbl_801A6658@ha
    lfd	f0, lbl_801A6658@l(r3)
    stfd	f0, 0x30(r1)
_8007ba88:
    lfd	f1, 0x30(r1)
    addi	r3, r1, 0x148
    bl      MSL_PrintfFloat
    addi	r3, r1, 0x148
    addi	r4, r1, 0x1a0
    bl      fn_8007CE0C
    cmpwi	r3, 0
    bc      4, 2, _8007c380
    lbz	r0, 0x14d(r1)
    cmplwi	r0, 0
    bc      4, 2, _8007bad0
    lbz	r0, 0x1a5(r1)
    cmplwi	r0, 0
    bc      12, 2, _8007bac8
    li	r0, 1
    b       _8007bbb4
_8007bac8:
    li	r0, 0
    b       _8007bbb4
_8007bad0:
    lbz	r0, 0x1a5(r1)
    cmplwi	r0, 0
    bc      4, 2, _8007bae4
    li	r0, 0
    b       _8007bbb4
_8007bae4:
    lha	r0, 0x14a(r1)
    lha	r4, 0x1a2(r1)
    cmpw	r0, r4
    bc      4, 2, _8007bba0
    lbz	r9, 0x14c(r1)
    lbz	r6, 0x1a4(r1)
    mr	r0, r9
    cmpw	r9, r6
    bc      4, 1, _8007bb0c
    mr	r0, r6
_8007bb0c:
    addi	r4, r1, 0x1a0
    addi	r5, r1, 0x148
    li	r3, 0
    mtctr	r0
    cmpwi	r0, 0
    bc      4, 1, _8007bb5c
_8007bb24:
    lbz	r7, 5(r5)
    lbz	r8, 5(r4)
    cmplw	r7, r8
    bc      4, 0, _8007bb3c
    li	r0, 1
    b       _8007bbb4
_8007bb3c:
    cmplw	r8, r7
    bc      4, 0, _8007bb4c
    li	r0, 0
    b       _8007bbb4
_8007bb4c:
    addi	r4, r4, 1
    addi	r5, r5, 1
    addi	r3, r3, 1
    bc      16, 0, _8007bb24
_8007bb5c:
    cmpw	r0, r9
    bc      4, 2, _8007bb98
    addi	r4, r1, 0x1a0
    subf	r0, r3, r6
    add	r4, r4, r3
    mtctr	r0
    cmpw	r3, r6
    bc      4, 0, _8007bb98
_8007bb7c:
    lbz	r0, 5(r4)
    cmplwi	r0, 0
    bc      12, 2, _8007bb90
    li	r0, 1
    b       _8007bbb4
_8007bb90:
    addi	r4, r4, 1
    bc      16, 0, _8007bb7c
_8007bb98:
    li	r0, 0
    b       _8007bbb4
_8007bba0:
    xor	r0, r4, r0
    srawi	r3, r0, 1
    and	r0, r0, r4
    subf	r0, r0, r3
    srwi	r0, r0, 0x1f
_8007bbb4:
    cmpwi	r0, 0
    bc      12, 2, _8007c028
    lfd	f0, 0x30(r1)
    li	r4, 1
    li	r3, 0
    lis	r0, 0x7ff0
    stfd	f0, 0x28(r1)
    lwz	r6, 0x2c(r1)
    lwz	r5, 0x28(r1)
    addc	r4, r6, r4
    adde	r3, r5, r3
    stw	r4, 0x2c(r1)
    stw	r3, 0x28(r1)
    lfd	f1, 0x28(r1)
    stfd	f1, 0x10(r1)
    lwz	r4, 0x10(r1)
    rlwinm	r3, r4, 0, 1, 0xb
    cmpw	r3, r0
    bc      12, 2, _8007bc10
    bc      4, 0, _8007bc58
    cmpwi	r3, 0
    bc      12, 2, _8007bc34
    b       _8007bc58
_8007bc10:
    clrlwi.	r0, r4, 0xc
    bc      4, 2, _8007bc24
    lwz	r0, 0x14(r1)
    cmpwi	r0, 0
    bc      12, 2, _8007bc2c
_8007bc24:
    li	r0, 1
    b       _8007bc5c
_8007bc2c:
    li	r0, 2
    b       _8007bc5c
_8007bc34:
    clrlwi.	r0, r4, 0xc
    bc      4, 2, _8007bc48
    lwz	r0, 0x14(r1)
    cmpwi	r0, 0
    bc      12, 2, _8007bc50
_8007bc48:
    li	r0, 5
    b       _8007bc5c
_8007bc50:
    li	r0, 3
    b       _8007bc5c
_8007bc58:
    li	r0, 4
_8007bc5c:
    cmpwi	r0, 2
    bc      4, 2, _8007bc6c
    stfd	f1, 0x30(r1)
    b       _8007c380
_8007bc6c:
    addi	r3, r1, 0x11c
    bl      MSL_PrintfFloat
    lis	r29, 0x7ff0
    b       _8007bd88
_8007bc7c:
    lwz	r5, 0x2c(r1)
    li	r3, 1
    lwz	r4, 0x28(r1)
    li	r0, 0
    addc	r3, r5, r3
    lfd	f0, 0x28(r1)
    adde	r0, r4, r0
    lwz	r30, 0x11c(r1)
    stw	r3, 0x2c(r1)
    lwz	r12, 0x120(r1)
    stw	r0, 0x28(r1)
    lwz	r11, 0x124(r1)
    lfd	f1, 0x28(r1)
    lwz	r10, 0x128(r1)
    stfd	f1, 8(r1)
    lwz	r9, 0x12c(r1)
    lwz	r31, 8(r1)
    lwz	r8, 0x130(r1)
    rlwinm	r0, r31, 0, 1, 0xb
    lwz	r7, 0x134(r1)
    lwz	r6, 0x138(r1)
    cmpw	r0, r29
    lwz	r5, 0x13c(r1)
    lwz	r4, 0x140(r1)
    lhz	r3, 0x144(r1)
    stw	r30, 0x148(r1)
    stw	r12, 0x14c(r1)
    stw	r11, 0x150(r1)
    stw	r10, 0x154(r1)
    stw	r9, 0x158(r1)
    stw	r8, 0x15c(r1)
    stw	r7, 0x160(r1)
    stw	r6, 0x164(r1)
    stw	r5, 0x168(r1)
    stw	r4, 0x16c(r1)
    sth	r3, 0x170(r1)
    stfd	f0, 0x30(r1)
    bc      12, 2, _8007bd24
    bc      4, 0, _8007bd6c
    cmpwi	r0, 0
    bc      12, 2, _8007bd48
    b       _8007bd6c
_8007bd24:
    clrlwi.	r0, r31, 0xc
    bc      4, 2, _8007bd38
    lwz	r0, 0xc(r1)
    cmpwi	r0, 0
    bc      12, 2, _8007bd40
_8007bd38:
    li	r0, 1
    b       _8007bd70
_8007bd40:
    li	r0, 2
    b       _8007bd70
_8007bd48:
    clrlwi.	r0, r31, 0xc
    bc      4, 2, _8007bd5c
    lwz	r0, 0xc(r1)
    cmpwi	r0, 0
    bc      12, 2, _8007bd64
_8007bd5c:
    li	r0, 5
    b       _8007bd70
_8007bd64:
    li	r0, 3
    b       _8007bd70
_8007bd6c:
    li	r0, 4
_8007bd70:
    cmpwi	r0, 2
    bc      4, 2, _8007bd80
    stfd	f1, 0x30(r1)
    b       _8007c380
_8007bd80:
    addi	r3, r1, 0x11c
    bl      MSL_PrintfFloat
_8007bd88:
    lbz	r0, 0x121(r1)
    cmplwi	r0, 0
    bc      4, 2, _8007bdb0
    lbz	r0, 0x1a5(r1)
    cmplwi	r0, 0
    bc      12, 2, _8007bda8
    li	r0, 1
    b       _8007be98
_8007bda8:
    li	r0, 0
    b       _8007be98
_8007bdb0:
    lbz	r0, 0x1a5(r1)
    cmplwi	r0, 0
    bc      4, 2, _8007bdc4
    li	r0, 0
    b       _8007be98
_8007bdc4:
    lha	r0, 0x11e(r1)
    lha	r4, 0x1a2(r1)
    cmpw	r0, r4
    bc      4, 2, _8007be84
    lbz	r9, 0x120(r1)
    lbz	r6, 0x1a4(r1)
    mr	r0, r9
    cmpw	r9, r6
    bc      4, 1, _8007bdec
    mr	r0, r6
_8007bdec:
    addi	r4, r1, 0x1a0
    addi	r5, r1, 0x11c
    li	r3, 0
    mtctr	r0
    cmpwi	r0, 0
    bc      4, 1, _8007be3c
_8007be04:
    lbz	r7, 5(r5)
    lbz	r8, 5(r4)
    cmplw	r7, r8
    bc      4, 0, _8007be1c
    li	r0, 1
    b       _8007be98
_8007be1c:
    cmplw	r8, r7
    bc      4, 0, _8007be2c
    li	r0, 0
    b       _8007be98
_8007be2c:
    addi	r4, r4, 1
    addi	r5, r5, 1
    addi	r3, r3, 1
    bc      16, 0, _8007be04
_8007be3c:
    cmpw	r0, r9
    bc      4, 2, _8007be7c
    addi	r4, r1, 0x1a0
    subf	r0, r3, r6
    add	r4, r4, r3
    mtctr	r0
    cmpw	r3, r6
    bc      4, 0, _8007be7c
_8007be5c:
    lbz	r0, 5(r4)
    cmplwi	r0, 0
    bc      12, 2, _8007be70
    li	r0, 1
    b       _8007be98
_8007be70:
    addi	r4, r4, 1
    addi	r3, r3, 1
    bc      16, 0, _8007be5c
_8007be7c:
    li	r0, 0
    b       _8007be98
_8007be84:
    xor	r0, r4, r0
    srawi	r3, r0, 1
    and	r0, r0, r4
    subf	r0, r0, r3
    srwi	r0, r0, 0x1f
_8007be98:
    cmpwi	r0, 0
    bc      4, 2, _8007bc7c
    addi	r3, r1, 0xf0
    addi	r4, r1, 0x1a0
    addi	r5, r1, 0x148
    bl      fn_8007C910
    addi	r3, r1, 0xc4
    addi	r4, r1, 0x11c
    addi	r5, r1, 0x1a0
    bl      fn_8007C910
    addi	r3, r1, 0xf0
    addi	r4, r1, 0xc4
    bl      fn_8007CE0C
    cmpwi	r3, 0
    bc      12, 2, _8007bf08
    lwz	r0, 0x30(r1)
    li	r4, 0
    lwz	r5, 0x34(r1)
    li	r3, 1
    and	r0, r0, r4
    and	r3, r5, r3
    xor	r3, r3, r4
    xor	r0, r0, r4
    or.	r0, r3, r0
    bc      12, 2, _8007c380
    lfd	f0, 0x28(r1)
    stfd	f0, 0x30(r1)
    b       _8007c380
_8007bf08:
    lbz	r0, 0xf5(r1)
    cmplwi	r0, 0
    bc      4, 2, _8007bf30
    lbz	r0, 0xc9(r1)
    cmplwi	r0, 0
    bc      12, 2, _8007bf28
    li	r0, 1
    b       _8007c014
_8007bf28:
    li	r0, 0
    b       _8007c014
_8007bf30:
    lbz	r0, 0xc9(r1)
    cmplwi	r0, 0
    bc      4, 2, _8007bf44
    li	r0, 0
    b       _8007c014
_8007bf44:
    lha	r0, 0xf2(r1)
    lha	r4, 0xc6(r1)
    cmpw	r0, r4
    bc      4, 2, _8007c000
    lbz	r9, 0xf4(r1)
    lbz	r6, 0xc8(r1)
    mr	r0, r9
    cmpw	r9, r6
    bc      4, 1, _8007bf6c
    mr	r0, r6
_8007bf6c:
    addi	r4, r1, 0xc4
    addi	r5, r1, 0xf0
    li	r3, 0
    mtctr	r0
    cmpwi	r0, 0
    bc      4, 1, _8007bfbc
_8007bf84:
    lbz	r7, 5(r5)
    lbz	r8, 5(r4)
    cmplw	r7, r8
    bc      4, 0, _8007bf9c
    li	r0, 1
    b       _8007c014
_8007bf9c:
    cmplw	r8, r7
    bc      4, 0, _8007bfac
    li	r0, 0
    b       _8007c014
_8007bfac:
    addi	r4, r4, 1
    addi	r5, r5, 1
    addi	r3, r3, 1
    bc      16, 0, _8007bf84
_8007bfbc:
    cmpw	r0, r9
    bc      4, 2, _8007bff8
    addi	r4, r1, 0xc4
    subf	r0, r3, r6
    add	r4, r4, r3
    mtctr	r0
    cmpw	r3, r6
    bc      4, 0, _8007bff8
_8007bfdc:
    lbz	r0, 5(r4)
    cmplwi	r0, 0
    bc      12, 2, _8007bff0
    li	r0, 1
    b       _8007c014
_8007bff0:
    addi	r4, r4, 1
    bc      16, 0, _8007bfdc
_8007bff8:
    li	r0, 0
    b       _8007c014
_8007c000:
    xor	r0, r4, r0
    srawi	r3, r0, 1
    and	r0, r0, r4
    subf	r0, r0, r3
    srwi	r0, r0, 0x1f
_8007c014:
    cmpwi	r0, 0
    bc      4, 2, _8007c380
    lfd	f0, 0x28(r1)
    stfd	f0, 0x30(r1)
    b       _8007c380
_8007c028:
    lfd	f0, 0x30(r1)
    li	r0, -1
    addi	r3, r1, 0x98
    stfd	f0, 0x20(r1)
    lwz	r4, 0x24(r1)
    lwz	r5, 0x20(r1)
    addc	r4, r4, r0
    adde	r0, r5, r0
    stw	r4, 0x24(r1)
    stw	r0, 0x20(r1)
    lfd	f1, 0x20(r1)
    bl      MSL_PrintfFloat
    b       _8007c0e4
_8007c05c:
    lwz	r4, 0x24(r1)
    li	r0, -1
    lwz	r5, 0x20(r1)
    addi	r3, r1, 0x98
    addc	r4, r4, r0
    lfd	f0, 0x20(r1)
    adde	r0, r5, r0
    lwz	r29, 0x98(r1)
    lwz	r30, 0x9c(r1)
    lwz	r31, 0xa0(r1)
    lwz	r12, 0xa4(r1)
    lwz	r11, 0xa8(r1)
    lwz	r10, 0xac(r1)
    lwz	r9, 0xb0(r1)
    lwz	r8, 0xb4(r1)
    lwz	r7, 0xb8(r1)
    lwz	r6, 0xbc(r1)
    lhz	r5, 0xc0(r1)
    stw	r4, 0x24(r1)
    stw	r0, 0x20(r1)
    stw	r29, 0x148(r1)
    lfd	f1, 0x20(r1)
    stw	r30, 0x14c(r1)
    stw	r31, 0x150(r1)
    stw	r12, 0x154(r1)
    stw	r11, 0x158(r1)
    stw	r10, 0x15c(r1)
    stw	r9, 0x160(r1)
    stw	r8, 0x164(r1)
    stw	r7, 0x168(r1)
    stw	r6, 0x16c(r1)
    sth	r5, 0x170(r1)
    stfd	f0, 0x30(r1)
    bl      MSL_PrintfFloat
_8007c0e4:
    lbz	r0, 0x1a5(r1)
    cmplwi	r0, 0
    bc      4, 2, _8007c10c
    lbz	r0, 0x9d(r1)
    cmplwi	r0, 0
    bc      12, 2, _8007c104
    li	r0, 1
    b       _8007c1f4
_8007c104:
    li	r0, 0
    b       _8007c1f4
_8007c10c:
    lbz	r0, 0x9d(r1)
    cmplwi	r0, 0
    bc      4, 2, _8007c120
    li	r0, 0
    b       _8007c1f4
_8007c120:
    lha	r0, 0x1a2(r1)
    lha	r4, 0x9a(r1)
    cmpw	r0, r4
    bc      4, 2, _8007c1e0
    lbz	r9, 0x1a4(r1)
    lbz	r6, 0x9c(r1)
    mr	r0, r9
    cmpw	r9, r6
    bc      4, 1, _8007c148
    mr	r0, r6
_8007c148:
    addi	r4, r1, 0x98
    addi	r5, r1, 0x1a0
    li	r3, 0
    mtctr	r0
    cmpwi	r0, 0
    bc      4, 1, _8007c198
_8007c160:
    lbz	r7, 5(r5)
    lbz	r8, 5(r4)
    cmplw	r7, r8
    bc      4, 0, _8007c178
    li	r0, 1
    b       _8007c1f4
_8007c178:
    cmplw	r8, r7
    bc      4, 0, _8007c188
    li	r0, 0
    b       _8007c1f4
_8007c188:
    addi	r4, r4, 1
    addi	r5, r5, 1
    addi	r3, r3, 1
    bc      16, 0, _8007c160
_8007c198:
    cmpw	r0, r9
    bc      4, 2, _8007c1d8
    addi	r4, r1, 0x98
    subf	r0, r3, r6
    add	r4, r4, r3
    mtctr	r0
    cmpw	r3, r6
    bc      4, 0, _8007c1d8
_8007c1b8:
    lbz	r0, 5(r4)
    cmplwi	r0, 0
    bc      12, 2, _8007c1cc
    li	r0, 1
    b       _8007c1f4
_8007c1cc:
    addi	r4, r4, 1
    addi	r3, r3, 1
    bc      16, 0, _8007c1b8
_8007c1d8:
    li	r0, 0
    b       _8007c1f4
_8007c1e0:
    xor	r0, r4, r0
    srawi	r3, r0, 1
    and	r0, r0, r4
    subf	r0, r0, r3
    srwi	r0, r0, 0x1f
_8007c1f4:
    cmpwi	r0, 0
    bc      4, 2, _8007c05c
    addi	r3, r1, 0x6c
    addi	r4, r1, 0x1a0
    addi	r5, r1, 0x98
    bl      fn_8007C910
    addi	r3, r1, 0x40
    addi	r4, r1, 0x148
    addi	r5, r1, 0x1a0
    bl      fn_8007C910
    addi	r3, r1, 0x6c
    addi	r4, r1, 0x40
    bl      fn_8007CE0C
    cmpwi	r3, 0
    bc      12, 2, _8007c264
    lwz	r0, 0x30(r1)
    li	r4, 0
    lwz	r5, 0x34(r1)
    li	r3, 1
    and	r0, r0, r4
    and	r3, r5, r3
    xor	r3, r3, r4
    xor	r0, r0, r4
    or.	r0, r3, r0
    bc      12, 2, _8007c380
    lfd	f0, 0x20(r1)
    stfd	f0, 0x30(r1)
    b       _8007c380
_8007c264:
    lbz	r0, 0x71(r1)
    cmplwi	r0, 0
    bc      4, 2, _8007c28c
    lbz	r0, 0x45(r1)
    cmplwi	r0, 0
    bc      12, 2, _8007c284
    li	r0, 1
    b       _8007c370
_8007c284:
    li	r0, 0
    b       _8007c370
_8007c28c:
    lbz	r0, 0x45(r1)
    cmplwi	r0, 0
    bc      4, 2, _8007c2a0
    li	r0, 0
    b       _8007c370
_8007c2a0:
    lha	r0, 0x6e(r1)
    lha	r4, 0x42(r1)
    cmpw	r0, r4
    bc      4, 2, _8007c35c
    lbz	r9, 0x70(r1)
    lbz	r6, 0x44(r1)
    mr	r0, r9
    cmpw	r9, r6
    bc      4, 1, _8007c2c8
    mr	r0, r6
_8007c2c8:
    addi	r4, r1, 0x40
    addi	r5, r1, 0x6c
    li	r3, 0
    mtctr	r0
    cmpwi	r0, 0
    bc      4, 1, _8007c318
_8007c2e0:
    lbz	r7, 5(r5)
    lbz	r8, 5(r4)
    cmplw	r7, r8
    bc      4, 0, _8007c2f8
    li	r0, 1
    b       _8007c370
_8007c2f8:
    cmplw	r8, r7
    bc      4, 0, _8007c308
    li	r0, 0
    b       _8007c370
_8007c308:
    addi	r4, r4, 1
    addi	r5, r5, 1
    addi	r3, r3, 1
    bc      16, 0, _8007c2e0
_8007c318:
    cmpw	r0, r9
    bc      4, 2, _8007c354
    addi	r4, r1, 0x40
    subf	r0, r3, r6
    add	r4, r4, r3
    mtctr	r0
    cmpw	r3, r6
    bc      4, 0, _8007c354
_8007c338:
    lbz	r0, 5(r4)
    cmplwi	r0, 0
    bc      12, 2, _8007c34c
    li	r0, 1
    b       _8007c370
_8007c34c:
    addi	r4, r4, 1
    bc      16, 0, _8007c338
_8007c354:
    li	r0, 0
    b       _8007c370
_8007c35c:
    xor	r0, r4, r0
    srawi	r3, r0, 1
    and	r0, r0, r4
    subf	r0, r0, r3
    srwi	r0, r0, 0x1f
_8007c370:
    cmpwi	r0, 0
    bc      12, 2, _8007c380
    lfd	f0, 0x20(r1)
    stfd	f0, 0x30(r1)
_8007c380:
    lbz	r0, 0x1a0(r1)
    extsb.	r0, r0
    bc      12, 2, _8007c398
    lfd	f0, 0x30(r1)
    fneg	f0, f0
    stfd	f0, 0x30(r1)
_8007c398:
    lfd	f1, 0x30(r1)
_8007c39c:
    lwz	r0, 0x1f4(r1)
    lwz	r31, 0x1ec(r1)
    lwz	r30, 0x1e8(r1)
    lwz	r29, 0x1e4(r1)
    mtlr	r0
    addi	r1, r1, 0x1f0
    blr
}

asm void fn_8007C3B8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r4
    stw	r30, 8(r1)
    lha	r30, 2(r3)
    mr	r3, r31
    bl      MSL_PrintfFloat
    lbz	r0, 5(r31)
    cmplwi	r0, 9
    bc      12, 1, _8007c544
    extsh	r0, r30
    cmpwi	r0, 0x24
    bc      4, 1, _8007c3f8
    li	r30, 0x24
_8007c3f8:
    extsh.	r6, r30
    bc      4, 1, _8007c4e4
    lbz	r0, 4(r31)
    cmpw	r6, r0
    bc      4, 0, _8007c4e4
    add	r5, r31, r6
    lbz	r0, 5(r5)
    cmplwi	r0, 5
    bc      4, 1, _8007c424
    li	r0, 1
    b       _8007c484
_8007c424:
    bc      4, 0, _8007c430
    li	r0, -1
    b       _8007c484
_8007c430:
    lbz	r3, 4(r31)
    addi	r4, r5, 6
    addi	r3, r3, 5
    add	r3, r31, r3
    subf	r0, r4, r3
    mtctr	r0
    cmplw	r4, r3
    bc      4, 0, _8007c46c
_8007c450:
    lbz	r0, 0(r4)
    cmplwi	r0, 0
    bc      12, 2, _8007c464
    li	r0, 1
    b       _8007c484
_8007c464:
    addi	r4, r4, 1
    bc      16, 0, _8007c450
_8007c46c:
    lbz	r0, 4(r5)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007c480
    li	r0, 1
    b       _8007c484
_8007c480:
    li	r0, -1
_8007c484:
    cmpwi	r0, 0
    stb	r6, 4(r31)
    bc      12, 0, _8007c4e4
    addi	r5, r31, 5
    addi	r4, r6, -1
    add	r4, r5, r4
    li	r0, 0
_8007c4a0:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007c4b8
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007c4e4
_8007c4b8:
    cmplw	r4, r5
    bc      4, 2, _8007c4d8
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007c4e4
_8007c4d8:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007c4a0
_8007c4e4:
    li	r5, 0
    b       _8007c500
_8007c4ec:
    lbz	r4, 4(r31)
    addi	r3, r4, 1
    addi	r0, r4, 5
    stb	r3, 4(r31)
    stbx	r5, r31, r0
_8007c500:
    lbz	r3, 4(r31)
    cmpw	r3, r6
    bc      12, 0, _8007c4ec
    lha	r0, 2(r31)
    addi	r3, r3, -1
    li	r5, 0
    subf	r0, r3, r0
    sth	r0, 2(r31)
    b       _8007c538
_8007c524:
    addi	r4, r5, 5
    addi	r5, r5, 1
    lbzx	r3, r31, r4
    addi	r0, r3, 0x30
    stbx	r0, r31, r4
_8007c538:
    lbz	r0, 4(r31)
    cmpw	r5, r0
    bc      12, 0, _8007c524
_8007c544:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void MSL_PrintfFloat(void)
{
    nofralloc
    stwu	r1, -0xb0(r1)
    mflr	r0
    lfd f0, lbl_801A74B0(r2)
    stw	r0, 0xb4(r1)
    fcmpu	cr0, f0, f1
    stfd	f31, 0xa8(r1)
    stmw	r26, 0x90(r1)
    mr	r30, r3
    stfd	f1, 8(r1)
    lwz	r0, 8(r1)
    srwi	r0, r0, 0x1f
    extsb	r31, r0
    bc      4, 2, _8007c5ac
    stb	r31, 0(r30)
    li	r3, 0
    li	r0, 1
    sth	r3, 2(r30)
    stb	r0, 4(r30)
    stb	r3, 5(r30)
    b       _8007c8f8
_8007c5ac:
    stfd	f1, 0x28(r1)
    lis	r0, 0x7ff0
    lwz	r4, 0x28(r1)
    rlwinm	r3, r4, 0, 1, 0xb
    cmpw	r3, r0
    bc      12, 2, _8007c5d4
    bc      4, 0, _8007c61c
    cmpwi	r3, 0
    bc      12, 2, _8007c5f8
    b       _8007c61c
_8007c5d4:
    clrlwi.	r0, r4, 0xc
    bc      4, 2, _8007c5e8
    lwz	r0, 0x2c(r1)
    cmpwi	r0, 0
    bc      12, 2, _8007c5f0
_8007c5e8:
    li	r0, 1
    b       _8007c620
_8007c5f0:
    li	r0, 2
    b       _8007c620
_8007c5f8:
    clrlwi.	r0, r4, 0xc
    bc      4, 2, _8007c60c
    lwz	r0, 0x2c(r1)
    cmpwi	r0, 0
    bc      12, 2, _8007c614
_8007c60c:
    li	r0, 5
    b       _8007c620
_8007c614:
    li	r0, 3
    b       _8007c620
_8007c61c:
    li	r0, 4
_8007c620:
    cmpwi	r0, 2
    bc      12, 1, _8007c6cc
    lfd	f0, 8(r1)
    li	r3, 0
    stb	r31, 0(r30)
    lis	r0, 0x7ff0
    li	r4, 1
    stfd	f0, 0x20(r1)
    lwz	r5, 0x20(r1)
    sth	r3, 2(r30)
    rlwinm	r3, r5, 0, 1, 0xb
    cmpw	r3, r0
    stb	r4, 4(r30)
    bc      12, 2, _8007c668
    bc      4, 0, _8007c6b0
    cmpwi	r3, 0
    bc      12, 2, _8007c68c
    b       _8007c6b0
_8007c668:
    clrlwi.	r0, r5, 0xc
    bc      4, 2, _8007c67c
    lwz	r0, 0x24(r1)
    cmpwi	r0, 0
    bc      12, 2, _8007c684
_8007c67c:
    li	r0, 1
    b       _8007c6b4
_8007c684:
    li	r0, 2
    b       _8007c6b4
_8007c68c:
    clrlwi.	r0, r5, 0xc
    bc      4, 2, _8007c6a0
    lwz	r0, 0x24(r1)
    cmpwi	r0, 0
    bc      12, 2, _8007c6a8
_8007c6a0:
    li	r0, 5
    b       _8007c6b4
_8007c6a8:
    li	r0, 3
    b       _8007c6b4
_8007c6b0:
    li	r0, 4
_8007c6b4:
    cmpwi	r0, 1
    li	r0, 0x49
    bc      4, 2, _8007c6c4
    li	r0, 0x4e
_8007c6c4:
    stb	r0, 5(r30)
    b       _8007c8f8
_8007c6cc:
    extsb.	r0, r31
    bc      12, 2, _8007c6dc
    fneg	f0, f1
    stfd	f0, 8(r1)
_8007c6dc:
    lfd	f1, 8(r1)
    addi	r3, r1, 0x10
    bl      frexp
    fmr	f31, f1
    stfd	f31, 0x18(r1)
    lwz	r8, 0x1c(r1)
    cmplwi	r8, 0
    bc      12, 2, _8007c768
    li	r5, 0x10
    lis	r3, 1
    li	r7, 0
    li	r6, 0x20
    mr	r4, r5
    addi	r3, r3, -1
    b       _8007c75c
_8007c718:
    and.	r0, r8, r3
    bc      4, 2, _8007c730
    add	r7, r7, r4
    srw	r8, r8, r4
    subf	r6, r4, r6
    b       _8007c738
_8007c730:
    cmplwi	r3, 1
    bc      12, 2, _8007c7dc
_8007c738:
    cmpwi	r5, 1
    bc      4, 1, _8007c74c
    srwi	r0, r5, 0x1f
    add	r0, r0, r5
    srawi	r5, r0, 1
_8007c74c:
    cmplwi	r3, 1
    bc      4, 1, _8007c75c
    srw	r3, r3, r5
    subf	r4, r5, r4
_8007c75c:
    cmpwi	r6, 0
    bc      4, 2, _8007c718
    b       _8007c7dc
_8007c768:
    lwz	r0, 0x18(r1)
    li	r5, 0x10
    lis	r3, 1
    li	r7, 0
    mr	r4, r5
    oris	r8, r0, 0x10
    addi	r3, r3, -1
    li	r6, 0x20
    b       _8007c7d0
_8007c78c:
    and.	r0, r8, r3
    bc      4, 2, _8007c7a4
    add	r7, r7, r4
    srw	r8, r8, r4
    subf	r6, r4, r6
    b       _8007c7ac
_8007c7a4:
    cmplwi	r3, 1
    bc      12, 2, _8007c7d8
_8007c7ac:
    cmpwi	r5, 1
    bc      4, 1, _8007c7c0
    srwi	r0, r5, 0x1f
    add	r0, r0, r5
    srawi	r5, r0, 1
_8007c7c0:
    cmplwi	r3, 1
    bc      4, 1, _8007c7d0
    srw	r3, r3, r5
    subf	r4, r5, r4
_8007c7d0:
    cmpwi	r6, 0
    bc      4, 2, _8007c78c
_8007c7d8:
    addi	r7, r7, 0x20
_8007c7dc:
    lwz	r0, 0x10(r1)
    subfic	r26, r7, 0x35
    addi	r3, r1, 0x38
    subf	r4, r26, r0
    bl      MSLFormatDecimalRound
    fmr	f1, f31
    mr	r3, r26
    bl      __fpclassifyd
    addi	r3, r1, 0x30
    bl      modf
    lfd	f1, 0x30(r1)
    bl      __cvt_dbl_usll
    li	r28, 0
    mr	r27, r3
    mr	r26, r4
    stb	r28, 0x64(r1)
    xor	r3, r26, r28
    xor	r0, r27, r28
    or.	r0, r3, r0
    bc      4, 2, _8007c840
    li	r0, 1
    sth	r28, 0x66(r1)
    stb	r0, 0x68(r1)
    stb	r28, 0x69(r1)
    b       _8007c8e4
_8007c840:
    stb	r28, 0x68(r1)
    addi	r29, r1, 0x64
    b       _8007c890
_8007c84c:
    mr	r3, r27
    mr	r4, r26
    li	r5, 0
    li	r6, 0xa
    bl      __mod2u
    lbz	r8, 0x68(r1)
    mr	r3, r27
    li	r5, 0
    li	r6, 0xa
    addi	r7, r8, 1
    addi	r0, r8, 5
    stb	r7, 0x68(r1)
    stbx	r4, r29, r0
    mr	r4, r26
    bl      __div2u
    mr	r26, r4
    mr	r27, r3
_8007c890:
    xor	r3, r26, r28
    xor	r0, r27, r28
    or.	r0, r3, r0
    bc      4, 2, _8007c84c
    lbz	r3, 0x68(r1)
    addi	r0, r1, 0x64
    addi	r5, r1, 0x69
    addi	r4, r3, 5
    add	r4, r0, r4
    b       _8007c8cc
_8007c8b8:
    lbz	r3, 0(r5)
    lbz	r0, 0(r4)
    stb	r0, 0(r5)
    addi	r5, r5, 1
    stb	r3, 0(r4)
_8007c8cc:
    addi	r4, r4, -1
    cmplw	r5, r4
    bc      12, 0, _8007c8b8
    lbz	r3, 0x68(r1)
    addi	r0, r3, -1
    sth	r0, 0x66(r1)
_8007c8e4:
    mr	r3, r30
    addi	r4, r1, 0x64
    addi	r5, r1, 0x38
    bl      fn_8007E69C
    stb	r31, 0(r30)
_8007c8f8:
    lfd	f31, 0xa8(r1)
    lmw	r26, 0x90(r1)
    lwz	r0, 0xb4(r1)
    mtlr	r0
    addi	r1, r1, 0xb0
    blr
}

asm void fn_8007C910(void)
{
    nofralloc
    lwz	r0, 0(r4)
    lwz	r6, 4(r4)
    stw	r0, 0(r3)
    lwz	r0, 8(r4)
    stw	r6, 4(r3)
    lwz	r6, 0xc(r4)
    stw	r0, 8(r3)
    lwz	r0, 0x10(r4)
    stw	r6, 0xc(r3)
    lwz	r6, 0x14(r4)
    stw	r0, 0x10(r3)
    lwz	r0, 0x18(r4)
    stw	r6, 0x14(r3)
    lwz	r6, 0x1c(r4)
    stw	r0, 0x18(r3)
    lwz	r0, 0x20(r4)
    stw	r6, 0x1c(r3)
    lwz	r6, 0x24(r4)
    stw	r0, 0x20(r3)
    lhz	r0, 0x28(r4)
    stw	r6, 0x24(r3)
    sth	r0, 0x28(r3)
    lbz	r0, 5(r5)
    cmplwi	r0, 0
    beqlr	
    lbz	r4, 4(r3)
    lbz	r0, 4(r5)
    mr	r8, r4
    cmpw	r4, r0
    bc      4, 0, _8007c98c
    mr	r8, r0
_8007c98c:
    lha	r4, 2(r5)
    lha	r0, 2(r3)
    subf	r0, r4, r0
    add	r8, r8, r0
    cmpwi	r8, 0x24
    bc      4, 1, _8007c9a8
    li	r8, 0x24
_8007c9a8:
    li	r7, 0
    b       _8007c9c4
_8007c9b0:
    lbz	r4, 4(r3)
    addi	r6, r4, 1
    addi	r4, r4, 5
    stb	r6, 4(r3)
    stbx	r7, r3, r4
_8007c9c4:
    lbz	r4, 4(r3)
    cmpw	r4, r8
    bc      12, 0, _8007c9b0
    lbz	r7, 4(r5)
    addi	r4, r3, 5
    add	r6, r4, r8
    add	r7, r7, r0
    cmpw	r7, r8
    bc      4, 0, _8007c9ec
    add	r6, r4, r7
_8007c9ec:
    subf	r7, r4, r6
    addi	r9, r5, 5
    subf	r7, r0, r7
    add	r10, r9, r7
    mr	r11, r10
    b       _8007cb40
_8007ca04:
    lbzu	r8, -1(r6)
    lbzu	r7, -1(r10)
    cmplw	r8, r7
    bc      4, 0, _8007cb30
    addi	r12, r6, -1
    b       _8007ca20
_8007ca1c:
    addi	r12, r12, -1
_8007ca20:
    lbz	r7, 0(r12)
    cmplwi	r7, 0
    bc      12, 2, _8007ca1c
    cmplw	r12, r6
    subf	r8, r12, r6
    bc      12, 2, _8007cb30
    rlwinm.	r7, r8, 0x1d, 3, 0x1f
    mtctr	r7
    bc      12, 2, _8007cb10
_8007ca44:
    lbz	r7, 0(r12)
    addi	r7, r7, -1
    stb	r7, 0(r12)
    lbz	r7, 1(r12)
    addi	r7, r7, 0xa
    stb	r7, 1(r12)
    lbz	r7, 1(r12)
    addi	r7, r7, -1
    stb	r7, 1(r12)
    lbz	r7, 2(r12)
    addi	r7, r7, 0xa
    stb	r7, 2(r12)
    lbz	r7, 2(r12)
    addi	r7, r7, -1
    stb	r7, 2(r12)
    lbz	r7, 3(r12)
    addi	r7, r7, 0xa
    stb	r7, 3(r12)
    lbz	r7, 3(r12)
    addi	r7, r7, -1
    stb	r7, 3(r12)
    lbz	r7, 4(r12)
    addi	r7, r7, 0xa
    stb	r7, 4(r12)
    lbz	r7, 4(r12)
    addi	r7, r7, -1
    stb	r7, 4(r12)
    lbz	r7, 5(r12)
    addi	r7, r7, 0xa
    stb	r7, 5(r12)
    lbz	r7, 5(r12)
    addi	r7, r7, -1
    stb	r7, 5(r12)
    lbz	r7, 6(r12)
    addi	r7, r7, 0xa
    stb	r7, 6(r12)
    lbz	r7, 6(r12)
    addi	r7, r7, -1
    stb	r7, 6(r12)
    lbz	r7, 7(r12)
    addi	r7, r7, 0xa
    stb	r7, 7(r12)
    lbz	r7, 7(r12)
    addi	r7, r7, -1
    stb	r7, 7(r12)
    lbz	r7, 8(r12)
    addi	r7, r7, 0xa
    stbu	r7, 8(r12)
    bc      16, 0, _8007ca44
    andi.	r8, r8, 7
    bc      12, 2, _8007cb30
_8007cb10:
    mtctr	r8
_8007cb14:
    lbz	r7, 0(r12)
    addi	r7, r7, -1
    stb	r7, 0(r12)
    lbz	r7, 1(r12)
    addi	r7, r7, 0xa
    stbu	r7, 1(r12)
    bc      16, 0, _8007cb14
_8007cb30:
    lbz	r8, 0(r10)
    lbz	r7, 0(r6)
    subf	r7, r8, r7
    stb	r7, 0(r6)
_8007cb40:
    cmplw	r6, r4
    bc      4, 1, _8007cb50
    cmplw	r10, r9
    bc      12, 1, _8007ca04
_8007cb50:
    lbz	r8, 4(r5)
    subf	r9, r9, r11
    cmpw	r9, r8
    bc      4, 0, _8007cd04
    lbz	r7, 0(r11)
    li	r10, 0
    cmplwi	r7, 5
    bc      4, 0, _8007cb78
    li	r10, 1
    b       _8007cbc8
_8007cb78:
    bc      4, 2, _8007cbc8
    addi	r7, r8, 5
    addi	r6, r11, 1
    add	r7, r5, r7
    subf	r5, r6, r7
    mtctr	r5
    cmplw	r6, r7
    bc      4, 0, _8007cbac
_8007cb98:
    lbz	r5, 0(r6)
    cmplwi	r5, 0
    bc      4, 2, _8007cd04
    addi	r6, r6, 1
    bc      16, 0, _8007cb98
_8007cbac:
    add	r5, r9, r0
    addi	r6, r5, -1
    add	r6, r4, r6
    lbz	r0, 0(r6)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007cbc8
    li	r10, 1
_8007cbc8:
    cmpwi	r10, 0
    bc      12, 2, _8007cd04
    lbz	r0, 0(r6)
    cmplwi	r0, 1
    bc      4, 0, _8007ccf8
    addi	r8, r6, -1
    b       _8007cbe8
_8007cbe4:
    addi	r8, r8, -1
_8007cbe8:
    lbz	r0, 0(r8)
    cmplwi	r0, 0
    bc      12, 2, _8007cbe4
    cmplw	r8, r6
    subf	r5, r8, r6
    bc      12, 2, _8007ccf8
    rlwinm.	r0, r5, 0x1d, 3, 0x1f
    mtctr	r0
    bc      12, 2, _8007ccd8
_8007cc0c:
    lbz	r7, 0(r8)
    addi	r0, r7, -1
    stb	r0, 0(r8)
    lbz	r7, 1(r8)
    addi	r0, r7, 0xa
    stb	r0, 1(r8)
    lbz	r7, 1(r8)
    addi	r0, r7, -1
    stb	r0, 1(r8)
    lbz	r7, 2(r8)
    addi	r0, r7, 0xa
    stb	r0, 2(r8)
    lbz	r7, 2(r8)
    addi	r0, r7, -1
    stb	r0, 2(r8)
    lbz	r7, 3(r8)
    addi	r0, r7, 0xa
    stb	r0, 3(r8)
    lbz	r7, 3(r8)
    addi	r0, r7, -1
    stb	r0, 3(r8)
    lbz	r7, 4(r8)
    addi	r0, r7, 0xa
    stb	r0, 4(r8)
    lbz	r7, 4(r8)
    addi	r0, r7, -1
    stb	r0, 4(r8)
    lbz	r7, 5(r8)
    addi	r0, r7, 0xa
    stb	r0, 5(r8)
    lbz	r7, 5(r8)
    addi	r0, r7, -1
    stb	r0, 5(r8)
    lbz	r7, 6(r8)
    addi	r0, r7, 0xa
    stb	r0, 6(r8)
    lbz	r7, 6(r8)
    addi	r0, r7, -1
    stb	r0, 6(r8)
    lbz	r7, 7(r8)
    addi	r0, r7, 0xa
    stb	r0, 7(r8)
    lbz	r7, 7(r8)
    addi	r0, r7, -1
    stb	r0, 7(r8)
    lbz	r7, 8(r8)
    addi	r0, r7, 0xa
    stbu	r0, 8(r8)
    bc      16, 0, _8007cc0c
    andi.	r5, r5, 7
    bc      12, 2, _8007ccf8
_8007ccd8:
    mtctr	r5
_8007ccdc:
    lbz	r7, 0(r8)
    addi	r0, r7, -1
    stb	r0, 0(r8)
    lbz	r7, 1(r8)
    addi	r0, r7, 0xa
    stbu	r0, 1(r8)
    bc      16, 0, _8007ccdc
_8007ccf8:
    lbz	r5, 0(r6)
    addi	r0, r5, -1
    stb	r0, 0(r6)
_8007cd04:
    mr	r6, r4
    b       _8007cd10
_8007cd0c:
    addi	r6, r6, 1
_8007cd10:
    lbz	r0, 0(r6)
    cmplwi	r0, 0
    bc      12, 2, _8007cd0c
    cmplw	r6, r4
    bc      4, 1, _8007cdd0
    subf	r5, r4, r6
    lha	r0, 2(r3)
    clrlwi	r7, r5, 0x18
    subf	r0, r7, r0
    sth	r0, 2(r3)
    lbz	r0, 4(r3)
    add	r0, r4, r0
    cmplw	r6, r0
    subf	r5, r6, r0
    bc      4, 0, _8007cdc4
    rlwinm.	r0, r5, 0x1d, 3, 0x1f
    mtctr	r0
    bc      12, 2, _8007cdac
_8007cd58:
    lbz	r0, 0(r6)
    stb	r0, 0(r4)
    lbz	r0, 1(r6)
    stb	r0, 1(r4)
    lbz	r0, 2(r6)
    stb	r0, 2(r4)
    lbz	r0, 3(r6)
    stb	r0, 3(r4)
    lbz	r0, 4(r6)
    stb	r0, 4(r4)
    lbz	r0, 5(r6)
    stb	r0, 5(r4)
    lbz	r0, 6(r6)
    stb	r0, 6(r4)
    lbz	r0, 7(r6)
    addi	r6, r6, 8
    stb	r0, 7(r4)
    addi	r4, r4, 8
    bc      16, 0, _8007cd58
    andi.	r5, r5, 7
    bc      12, 2, _8007cdc4
_8007cdac:
    mtctr	r5
_8007cdb0:
    lbz	r0, 0(r6)
    addi	r6, r6, 1
    stb	r0, 0(r4)
    addi	r4, r4, 1
    bc      16, 0, _8007cdb0
_8007cdc4:
    lbz	r0, 4(r3)
    subf	r0, r7, r0
    stb	r0, 4(r3)
_8007cdd0:
    lbz	r0, 4(r3)
    addi	r4, r3, 5
    add	r5, r4, r0
    subf	r0, r4, r5
    mtctr	r0
    cmplw	r5, r4
    bc      4, 1, _8007cdfc
_8007cdec:
    lbzu	r0, -1(r5)
    cmplwi	r0, 0
    bc      4, 2, _8007cdfc
    bc      16, 0, _8007cdec
_8007cdfc:
    subf	r4, r4, r5
    addi	r0, r4, 1
    stb	r0, 4(r3)
    blr
}

asm void fn_8007CE0C(void)
{
    nofralloc
    lbz	r5, 5(r3)
    cmplwi	r5, 0
    bc      4, 2, _8007ce28
    lbz	r0, 5(r4)
    cntlzw	r0, r0
    srwi	r3, r0, 5
    blr
_8007ce28:
    lbz	r0, 5(r4)
    cmplwi	r0, 0
    bc      4, 2, _8007ce40
    cntlzw	r0, r5
    srwi	r3, r0, 5
    blr
_8007ce40:
    lha	r5, 2(r3)
    lha	r0, 2(r4)
    cmpw	r5, r0
    bc      4, 2, _8007cf10
    lbz	r7, 4(r3)
    lbz	r6, 4(r4)
    mr	r9, r7
    cmpw	r7, r6
    bc      4, 1, _8007ce68
    mr	r9, r6
_8007ce68:
    li	r8, 0
    mtctr	r9
    cmpwi	r9, 0
    bc      4, 1, _8007ce9c
_8007ce78:
    addi	r0, r8, 5
    lbzx	r5, r3, r0
    lbzx	r0, r4, r0
    cmplw	r5, r0
    bc      12, 2, _8007ce94
    li	r3, 0
    blr
_8007ce94:
    addi	r8, r8, 1
    bc      16, 0, _8007ce78
_8007ce9c:
    cmpw	r9, r7
    bc      4, 2, _8007ced8
    subf	r0, r8, r6
    mtctr	r0
    cmpw	r8, r6
    bc      4, 0, _8007cf08
_8007ceb4:
    addi	r0, r8, 5
    lbzx	r0, r4, r0
    cmplwi	r0, 0
    bc      12, 2, _8007cecc
    li	r3, 0
    blr
_8007cecc:
    addi	r8, r8, 1
    bc      16, 0, _8007ceb4
    b       _8007cf08
_8007ced8:
    subf	r0, r8, r7
    mtctr	r0
    cmpw	r8, r7
    bc      4, 0, _8007cf08
_8007cee8:
    addi	r0, r8, 5
    lbzx	r0, r3, r0
    cmplwi	r0, 0
    bc      12, 2, _8007cf00
    li	r3, 0
    blr
_8007cf00:
    addi	r8, r8, 1
    bc      16, 0, _8007cee8
_8007cf08:
    li	r3, 1
    blr
_8007cf10:
    li	r3, 0
    blr
}

asm void MSLFormatDecimalRound(void)
{
    nofralloc
    stwu	r1, -0x70(r1)
    mflr	r0
    stw	r0, 0x74(r1)
    stw	r31, 0x6c(r1)
    mr	r31, r3
    stw	r30, 0x68(r1)
    mr	r30, r4
    addi	r0, r30, 0x40
    cmplwi	r0, 0x48
    bc      12, 1, _8007e3f4
    lis     r3, jumptable_8015AFD8@ha
    slwi	r0, r0, 2
    addi	r3, r3, jumptable_8015AFD8@l
    lwzx	r0, r3, r0
    mtctr	r0
    bctr
    li	r0, -0x14
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0x25
    b       _8007cf90
_8007cf78:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007cf90:
    cmpwi	r4, 0x24
    bc      4, 0, _8007cfa4
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007cf78
_8007cfa4:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007cff8
    addi	r3, r5, 1
    b       _8007cfdc
_8007cfcc:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007cff8
    addi	r3, r3, 1
_8007cfdc:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007cfcc
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007cff8:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007d00c:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007d024
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007d024:
    cmplw	r4, r5
    bc      4, 2, _8007d044
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007d044:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007d00c
    b       _8007e684
    li	r0, -0x10
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0x53
    b       _8007d08c
_8007d074:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007d08c:
    cmpwi	r4, 0x24
    bc      4, 0, _8007d0a0
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007d074
_8007d0a0:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007d0f4
    addi	r3, r5, 1
    b       _8007d0d8
_8007d0c8:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007d0f4
    addi	r3, r3, 1
_8007d0d8:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007d0c8
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007d0f4:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007d108:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007d120
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007d120:
    cmplw	r4, r5
    bc      4, 2, _8007d140
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007d140:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007d108
    b       _8007e684
    li	r0, -0xa
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0x7a
    b       _8007d188
_8007d170:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007d188:
    cmpwi	r4, 0x24
    bc      4, 0, _8007d19c
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007d170
_8007d19c:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007d1f0
    addi	r3, r5, 1
    b       _8007d1d4
_8007d1c4:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007d1f0
    addi	r3, r3, 1
_8007d1d4:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007d1c4
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007d1f0:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007d204:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007d21c
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007d21c:
    cmplw	r4, r5
    bc      4, 2, _8007d23c
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007d23c:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007d204
    b       _8007e684
    li	r0, -5
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0x92
    b       _8007d284
_8007d26c:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007d284:
    cmpwi	r4, 0x24
    bc      4, 0, _8007d298
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007d26c
_8007d298:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007d2ec
    addi	r3, r5, 1
    b       _8007d2d0
_8007d2c0:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007d2ec
    addi	r3, r3, 1
_8007d2d0:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007d2c0
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007d2ec:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007d300:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007d318
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007d318:
    cmplw	r4, r5
    bc      4, 2, _8007d338
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007d338:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007d300
    b       _8007e684
    li	r0, -3
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0x9f
    b       _8007d380
_8007d368:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007d380:
    cmpwi	r4, 0x24
    bc      4, 0, _8007d394
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007d368
_8007d394:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007d3e8
    addi	r3, r5, 1
    b       _8007d3cc
_8007d3bc:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007d3e8
    addi	r3, r3, 1
_8007d3cc:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007d3bc
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007d3e8:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007d3fc:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007d414
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007d414:
    cmplw	r4, r5
    bc      4, 2, _8007d434
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007d434:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007d3fc
    b       _8007e684
    li	r0, -3
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0xa6
    b       _8007d47c
_8007d464:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007d47c:
    cmpwi	r4, 0x24
    bc      4, 0, _8007d490
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007d464
_8007d490:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007d4e4
    addi	r3, r5, 1
    b       _8007d4c8
_8007d4b8:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007d4e4
    addi	r3, r3, 1
_8007d4c8:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007d4b8
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007d4e4:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007d4f8:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007d510
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007d510:
    cmplw	r4, r5
    bc      4, 2, _8007d530
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007d530:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007d4f8
    b       _8007e684
    li	r0, -2
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0xac
    b       _8007d578
_8007d560:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007d578:
    cmpwi	r4, 0x24
    bc      4, 0, _8007d58c
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007d560
_8007d58c:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007d5e0
    addi	r3, r5, 1
    b       _8007d5c4
_8007d5b4:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007d5e0
    addi	r3, r3, 1
_8007d5c4:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007d5b4
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007d5e0:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007d5f4:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007d60c
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007d60c:
    cmplw	r4, r5
    bc      4, 2, _8007d62c
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007d62c:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007d5f4
    b       _8007e684
    li	r0, -2
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0xb2
    b       _8007d674
_8007d65c:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007d674:
    cmpwi	r4, 0x24
    bc      4, 0, _8007d688
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007d65c
_8007d688:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007d6dc
    addi	r3, r5, 1
    b       _8007d6c0
_8007d6b0:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007d6dc
    addi	r3, r3, 1
_8007d6c0:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007d6b0
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007d6dc:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007d6f0:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007d708
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007d708:
    cmplw	r4, r5
    bc      4, 2, _8007d728
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007d728:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007d6f0
    b       _8007e684
    li	r0, -2
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0xb7
    b       _8007d770
_8007d758:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007d770:
    cmpwi	r4, 0x24
    bc      4, 0, _8007d784
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007d758
_8007d784:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007d7d8
    addi	r3, r5, 1
    b       _8007d7bc
_8007d7ac:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007d7d8
    addi	r3, r3, 1
_8007d7bc:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007d7ac
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007d7d8:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007d7ec:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007d804
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007d804:
    cmplw	r4, r5
    bc      4, 2, _8007d824
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007d824:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007d7ec
    b       _8007e684
    li	r0, -1
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0xbb
    b       _8007d86c
_8007d854:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007d86c:
    cmpwi	r4, 0x24
    bc      4, 0, _8007d880
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007d854
_8007d880:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007d8d4
    addi	r3, r5, 1
    b       _8007d8b8
_8007d8a8:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007d8d4
    addi	r3, r3, 1
_8007d8b8:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007d8a8
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007d8d4:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007d8e8:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007d900
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007d900:
    cmplw	r4, r5
    bc      4, 2, _8007d920
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007d920:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007d8e8
    b       _8007e684
    li	r0, -1
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0xbf
    b       _8007d968
_8007d950:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007d968:
    cmpwi	r4, 0x24
    bc      4, 0, _8007d97c
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007d950
_8007d97c:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007d9d0
    addi	r3, r5, 1
    b       _8007d9b4
_8007d9a4:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007d9d0
    addi	r3, r3, 1
_8007d9b4:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007d9a4
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007d9d0:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007d9e4:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007d9fc
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007d9fc:
    cmplw	r4, r5
    bc      4, 2, _8007da1c
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007da1c:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007d9e4
    b       _8007e684
    li	r0, -1
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0xc2
    b       _8007da64
_8007da4c:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007da64:
    cmpwi	r4, 0x24
    bc      4, 0, _8007da78
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007da4c
_8007da78:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007dacc
    addi	r3, r5, 1
    b       _8007dab0
_8007daa0:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007dacc
    addi	r3, r3, 1
_8007dab0:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007daa0
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007dacc:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007dae0:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007daf8
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007daf8:
    cmplw	r4, r5
    bc      4, 2, _8007db18
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007db18:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007dae0
    b       _8007e684
    li	r4, 0
    lis     r3, lbl_80094ED8@ha
    sth	r4, 2(r31)
    addi	r3, r3, lbl_80094ED8@l
    addi	r5, r3, 0xc4
    stb	r4, 0(r31)
    b       _8007db5c
_8007db44:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007db5c:
    cmpwi	r4, 0x24
    bc      4, 0, _8007db70
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007db44
_8007db70:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007dbc4
    addi	r3, r5, 1
    b       _8007dba8
_8007db98:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007dbc4
    addi	r3, r3, 1
_8007dba8:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007db98
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007dbc4:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007dbd8:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007dbf0
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007dbf0:
    cmplw	r4, r5
    bc      4, 2, _8007dc10
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007dc10:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007dbd8
    b       _8007e684
    li	r4, 0
    lis     r3, lbl_80094ED8@ha
    sth	r4, 2(r31)
    addi	r3, r3, lbl_80094ED8@l
    addi	r5, r3, 0xc6
    stb	r4, 0(r31)
    b       _8007dc54
_8007dc3c:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007dc54:
    cmpwi	r4, 0x24
    bc      4, 0, _8007dc68
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007dc3c
_8007dc68:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007dcbc
    addi	r3, r5, 1
    b       _8007dca0
_8007dc90:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007dcbc
    addi	r3, r3, 1
_8007dca0:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007dc90
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007dcbc:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007dcd0:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007dce8
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007dce8:
    cmplw	r4, r5
    bc      4, 2, _8007dd08
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007dd08:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007dcd0
    b       _8007e684
    li	r4, 0
    lis     r3, lbl_80094ED8@ha
    sth	r4, 2(r31)
    addi	r3, r3, lbl_80094ED8@l
    addi	r5, r3, 0xc8
    stb	r4, 0(r31)
    b       _8007dd4c
_8007dd34:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007dd4c:
    cmpwi	r4, 0x24
    bc      4, 0, _8007dd60
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007dd34
_8007dd60:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007ddb4
    addi	r3, r5, 1
    b       _8007dd98
_8007dd88:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007ddb4
    addi	r3, r3, 1
_8007dd98:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007dd88
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007ddb4:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007ddc8:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007dde0
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007dde0:
    cmplw	r4, r5
    bc      4, 2, _8007de00
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007de00:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007ddc8
    b       _8007e684
    li	r4, 0
    lis     r3, lbl_80094ED8@ha
    sth	r4, 2(r31)
    addi	r3, r3, lbl_80094ED8@l
    addi	r5, r3, 0xca
    stb	r4, 0(r31)
    b       _8007de44
_8007de2c:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007de44:
    cmpwi	r4, 0x24
    bc      4, 0, _8007de58
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007de2c
_8007de58:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007deac
    addi	r3, r5, 1
    b       _8007de90
_8007de80:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007deac
    addi	r3, r3, 1
_8007de90:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007de80
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007deac:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007dec0:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007ded8
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007ded8:
    cmplw	r4, r5
    bc      4, 2, _8007def8
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007def8:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007dec0
    b       _8007e684
    li	r0, 1
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0xcc
    b       _8007df40
_8007df28:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007df40:
    cmpwi	r4, 0x24
    bc      4, 0, _8007df54
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007df28
_8007df54:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007dfa8
    addi	r3, r5, 1
    b       _8007df8c
_8007df7c:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007dfa8
    addi	r3, r3, 1
_8007df8c:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007df7c
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007dfa8:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007dfbc:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007dfd4
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007dfd4:
    cmplw	r4, r5
    bc      4, 2, _8007dff4
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007dff4:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007dfbc
    b       _8007e684
    li	r0, 1
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0xcf
    b       _8007e03c
_8007e024:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007e03c:
    cmpwi	r4, 0x24
    bc      4, 0, _8007e050
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007e024
_8007e050:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007e0a4
    addi	r3, r5, 1
    b       _8007e088
_8007e078:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007e0a4
    addi	r3, r3, 1
_8007e088:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007e078
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007e0a4:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007e0b8:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007e0d0
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007e0d0:
    cmplw	r4, r5
    bc      4, 2, _8007e0f0
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007e0f0:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007e0b8
    b       _8007e684
    li	r0, 1
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0xd2
    b       _8007e138
_8007e120:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007e138:
    cmpwi	r4, 0x24
    bc      4, 0, _8007e14c
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007e120
_8007e14c:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007e1a0
    addi	r3, r5, 1
    b       _8007e184
_8007e174:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007e1a0
    addi	r3, r3, 1
_8007e184:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007e174
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007e1a0:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007e1b4:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007e1cc
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007e1cc:
    cmplw	r4, r5
    bc      4, 2, _8007e1ec
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007e1ec:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007e1b4
    b       _8007e684
    li	r0, 2
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0xd5
    b       _8007e234
_8007e21c:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007e234:
    cmpwi	r4, 0x24
    bc      4, 0, _8007e248
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007e21c
_8007e248:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007e29c
    addi	r3, r5, 1
    b       _8007e280
_8007e270:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007e29c
    addi	r3, r3, 1
_8007e280:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007e270
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007e29c:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007e2b0:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007e2c8
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007e2c8:
    cmplw	r4, r5
    bc      4, 2, _8007e2e8
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007e2e8:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007e2b0
    b       _8007e684
    li	r0, 2
    lis     r3, lbl_80094ED8@ha
    sth	r0, 2(r31)
    li	r4, 0
    addi	r3, r3, lbl_80094ED8@l
    stb	r4, 0(r31)
    addi	r5, r3, 0xd9
    b       _8007e330
_8007e318:
    lbz	r3, 0(r5)
    addi	r0, r4, 5
    addi	r5, r5, 1
    addi	r4, r4, 1
    addi	r3, r3, -0x30
    stbx	r3, r31, r0
_8007e330:
    cmpwi	r4, 0x24
    bc      4, 0, _8007e344
    lbz	r0, 0(r5)
    extsb.	r0, r0
    bc      4, 2, _8007e318
_8007e344:
    stb	r4, 4(r31)
    lbz	r3, 0(r5)
    extsb.	r0, r3
    bc      12, 2, _8007e684
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e684
    bc      12, 1, _8007e398
    addi	r3, r5, 1
    b       _8007e37c
_8007e36c:
    extsb	r0, r5
    cmpwi	r0, 0x30
    bc      4, 2, _8007e398
    addi	r3, r3, 1
_8007e37c:
    lbz	r5, 0(r3)
    extsb.	r0, r5
    bc      4, 2, _8007e36c
    add	r3, r31, r4
    lbz	r0, 4(r3)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e684
_8007e398:
    lbz	r3, 4(r31)
    addi	r5, r31, 5
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007e3ac:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007e3c4
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e684
_8007e3c4:
    cmplw	r4, r5
    bc      4, 2, _8007e3e4
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 2(r31)
    addi	r0, r3, 1
    sth	r0, 2(r31)
    b       _8007e684
_8007e3e4:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007e3ac
    b       _8007e684
_8007e3f4:
    srwi	r0, r30, 0x1f
    addi	r3, r1, 0x34
    add	r0, r0, r30
    srawi	r4, r0, 1
    bl      MSLFormatDecimalRound
    addi	r4, r1, 0x34
    mr	r3, r31
    mr	r5, r4
    bl      fn_8007E69C
    clrlwi.	r0, r30, 0x1f
    bc      12, 2, _8007e684
    lwz	r3, 0(r31)
    cmpwi	r30, 0
    lwz	r0, 4(r31)
    stw	r3, 8(r1)
    stw	r0, 0xc(r1)
    lwz	r3, 8(r31)
    lwz	r0, 0xc(r31)
    stw	r3, 0x10(r1)
    stw	r0, 0x14(r1)
    lwz	r3, 0x10(r31)
    lwz	r0, 0x14(r31)
    stw	r3, 0x18(r1)
    stw	r0, 0x1c(r1)
    lwz	r3, 0x18(r31)
    lwz	r0, 0x1c(r31)
    stw	r3, 0x20(r1)
    stw	r0, 0x24(r1)
    lwz	r3, 0x20(r31)
    lwz	r0, 0x24(r31)
    stw	r3, 0x28(r1)
    stw	r0, 0x2c(r1)
    lhz	r0, 0x28(r31)
    sth	r0, 0x30(r1)
    bc      4, 1, _8007e578
    li	r5, 0
    lis     r3, lbl_80094ED8@ha
    addi	r4, r3, lbl_80094ED8@l
    sth	r5, 0x36(r1)
    addi	r3, r1, 0x34
    stb	r5, 0x34(r1)
    addi	r6, r4, 0xc6
    b       _8007e4b8
_8007e4a0:
    lbz	r4, 0(r6)
    addi	r0, r5, 5
    addi	r6, r6, 1
    addi	r5, r5, 1
    addi	r4, r4, -0x30
    stbx	r4, r3, r0
_8007e4b8:
    cmpwi	r5, 0x24
    bc      4, 0, _8007e4cc
    lbz	r0, 0(r6)
    extsb.	r0, r0
    bc      4, 2, _8007e4a0
_8007e4cc:
    stb	r5, 0x38(r1)
    lbz	r3, 0(r6)
    extsb.	r0, r3
    bc      12, 2, _8007e674
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e674
    bc      12, 1, _8007e520
    addi	r3, r6, 1
    b       _8007e504
_8007e4f4:
    extsb	r0, r4
    cmpwi	r0, 0x30
    bc      4, 2, _8007e520
    addi	r3, r3, 1
_8007e504:
    lbz	r4, 0(r3)
    extsb.	r0, r4
    bc      4, 2, _8007e4f4
    addi	r3, r1, 0x38
    lbzx	r0, r3, r5
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e674
_8007e520:
    lbz	r3, 0x38(r1)
    addi	r5, r1, 0x39
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007e534:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007e54c
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e674
_8007e54c:
    cmplw	r4, r5
    bc      4, 2, _8007e56c
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 0x36(r1)
    addi	r0, r3, 1
    sth	r0, 0x36(r1)
    b       _8007e674
_8007e56c:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007e534
_8007e578:
    li	r5, 0
    lis     r3, lbl_80094ED8@ha
    li	r0, -1
    stb	r5, 0x34(r1)
    addi	r3, r3, lbl_80094ED8@l
    addi	r6, r3, 0xc2
    sth	r0, 0x36(r1)
    addi	r3, r1, 0x34
    b       _8007e5b4
_8007e59c:
    lbz	r4, 0(r6)
    addi	r0, r5, 5
    addi	r6, r6, 1
    addi	r5, r5, 1
    addi	r4, r4, -0x30
    stbx	r4, r3, r0
_8007e5b4:
    cmpwi	r5, 0x24
    bc      4, 0, _8007e5c8
    lbz	r0, 0(r6)
    extsb.	r0, r0
    bc      4, 2, _8007e59c
_8007e5c8:
    stb	r5, 0x38(r1)
    lbz	r3, 0(r6)
    extsb.	r0, r3
    bc      12, 2, _8007e674
    extsb	r0, r3
    cmpwi	r0, 5
    bc      12, 0, _8007e674
    bc      12, 1, _8007e61c
    addi	r3, r6, 1
    b       _8007e600
_8007e5f0:
    extsb	r0, r4
    cmpwi	r0, 0x30
    bc      4, 2, _8007e61c
    addi	r3, r3, 1
_8007e600:
    lbz	r4, 0(r3)
    extsb.	r0, r4
    bc      4, 2, _8007e5f0
    addi	r3, r1, 0x38
    lbzx	r0, r3, r5
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e674
_8007e61c:
    lbz	r3, 0x38(r1)
    addi	r5, r1, 0x39
    li	r0, 0
    addi	r4, r3, -1
    add	r4, r5, r4
_8007e630:
    lbz	r3, 0(r4)
    cmplwi	r3, 9
    bc      4, 0, _8007e648
    addi	r0, r3, 1
    stb	r0, 0(r4)
    b       _8007e674
_8007e648:
    cmplw	r4, r5
    bc      4, 2, _8007e668
    li	r0, 1
    stb	r0, 0(r4)
    lha	r3, 0x36(r1)
    addi	r0, r3, 1
    sth	r0, 0x36(r1)
    b       _8007e674
_8007e668:
    stb	r0, 0(r4)
    addi	r4, r4, -1
    b       _8007e630
_8007e674:
    mr	r3, r31
    addi	r4, r1, 8
    addi	r5, r1, 0x34
    bl      fn_8007E69C
_8007e684:
    lwz	r0, 0x74(r1)
    lwz	r31, 0x6c(r1)
    lwz	r30, 0x68(r1)
    mtlr	r0
    addi	r1, r1, 0x70
    blr
}

asm void fn_8007E69C(void)
{
    nofralloc
    stwu	r1, -0x70(r1)
    lis	r7, -0x3333
    lbz	r12, 4(r5)
    li	r0, 0
    stmw	r27, 0x5c(r1)
    addi	r8, r1, 8
    lbz	r31, 4(r4)
    addi	r29, r12, -1
    addi	r9, r7, -0x3333
    li	r30, 0
    add	r29, r31, r29
    addi	r6, r29, 1
    add	r6, r8, r6
    stb	r0, 0(r3)
    mr	r0, r6
    b       _8007e804
_8007e6dc:
    addi	r8, r12, -1
    subf	r7, r8, r29
    addic.	r7, r7, -1
    bc      4, 0, _8007e6f4
    li	r7, 0
    addi	r8, r29, -1
_8007e6f4:
    addi	r10, r8, 1
    subf	r11, r7, r31
    cmpw	r10, r11
    addi	r28, r7, 5
    addi	r27, r8, 5
    add	r28, r4, r28
    add	r27, r5, r27
    bc      4, 1, _8007e718
    mr	r10, r11
_8007e718:
    cmpwi	r10, 0
    mr	r8, r10
    bc      4, 1, _8007e7e4
    rlwinm.	r7, r10, 0x1d, 3, 0x1f
    mtctr	r7
    bc      12, 2, _8007e7c4
_8007e730:
    lbz	r11, 0(r28)
    lbz	r10, 0(r27)
    mullw	r7, r11, r10
    lbz	r11, 1(r28)
    lbz	r10, -1(r27)
    add	r30, r30, r7
    mullw	r7, r11, r10
    lbz	r11, 2(r28)
    lbz	r10, -2(r27)
    add	r30, r30, r7
    mullw	r7, r11, r10
    lbz	r11, 3(r28)
    lbz	r10, -3(r27)
    add	r30, r30, r7
    mullw	r7, r11, r10
    lbz	r11, 4(r28)
    lbz	r10, -4(r27)
    add	r30, r30, r7
    mullw	r7, r11, r10
    lbz	r11, 5(r28)
    lbz	r10, -5(r27)
    add	r30, r30, r7
    mullw	r7, r11, r10
    lbz	r11, 6(r28)
    lbz	r10, -6(r27)
    add	r30, r30, r7
    mullw	r7, r11, r10
    lbz	r11, 7(r28)
    lbz	r10, -7(r27)
    addi	r28, r28, 8
    addi	r27, r27, -8
    add	r30, r30, r7
    mullw	r7, r11, r10
    add	r30, r30, r7
    bc      16, 0, _8007e730
    andi.	r8, r8, 7
    bc      12, 2, _8007e7e4
_8007e7c4:
    mtctr	r8
_8007e7c8:
    lbz	r11, 0(r28)
    addi	r28, r28, 1
    lbz	r10, 0(r27)
    addi	r27, r27, -1
    mullw	r7, r11, r10
    add	r30, r30, r7
    bc      16, 0, _8007e7c8
_8007e7e4:
    mulhwu	r8, r9, r30
    addi	r29, r29, -1
    mr	r7, r8
    srwi	r8, r8, 3
    mulli	r8, r8, 0xa
    subf	r8, r8, r30
    srwi	r30, r7, 3
    stbu	r8, -1(r6)
_8007e804:
    cmpwi	r29, 0
    bc      12, 1, _8007e6dc
    lha	r7, 2(r4)
    cmplwi	r30, 0
    lha	r4, 2(r5)
    add	r4, r7, r4
    sth	r4, 2(r3)
    bc      12, 2, _8007e834
    stbu	r30, -1(r6)
    lha	r4, 2(r3)
    addi	r4, r4, 1
    sth	r4, 2(r3)
_8007e834:
    li	r7, 0
    b       _8007e850
_8007e83c:
    lbz	r5, 0(r6)
    addi	r4, r7, 5
    addi	r7, r7, 1
    addi	r6, r6, 1
    stbx	r5, r3, r4
_8007e850:
    cmpwi	r7, 0x24
    bc      4, 0, _8007e860
    cmplw	r6, r0
    bc      12, 0, _8007e83c
_8007e860:
    cmplw	r6, r0
    stb	r7, 4(r3)
    bc      4, 0, _8007e908
    lbz	r4, 0(r6)
    cmplwi	r4, 5
    bc      12, 0, _8007e908
    bc      4, 2, _8007e8b0
    addi	r5, r6, 1
    subf	r4, r5, r0
    mtctr	r4
    cmplw	r5, r0
    bc      4, 0, _8007e8a4
_8007e890:
    lbz	r0, 0(r5)
    cmplwi	r0, 0
    bc      4, 2, _8007e8b0
    addi	r5, r5, 1
    bc      16, 0, _8007e890
_8007e8a4:
    lbz	r0, -1(r6)
    clrlwi.	r0, r0, 0x1f
    bc      12, 2, _8007e908
_8007e8b0:
    lbz	r4, 4(r3)
    addi	r6, r3, 5
    li	r0, 0
    addi	r5, r4, -1
    add	r5, r6, r5
_8007e8c4:
    lbz	r4, 0(r5)
    cmplwi	r4, 9
    bc      4, 0, _8007e8dc
    addi	r0, r4, 1
    stb	r0, 0(r5)
    b       _8007e908
_8007e8dc:
    cmplw	r5, r6
    bc      4, 2, _8007e8fc
    li	r0, 1
    stb	r0, 0(r5)
    lha	r4, 2(r3)
    addi	r0, r4, 1
    sth	r0, 2(r3)
    b       _8007e908
_8007e8fc:
    stb	r0, 0(r5)
    addi	r5, r5, -1
    b       _8007e8c4
_8007e908:
    lmw	r27, 0x5c(r1)
    addi	r1, r1, 0x70
    blr
}

// provenance: original
div_t fn_8007E914(int numer, int denom)
{
    div_t result;
    int n_sign = 1;
    int d_sign = 1;

    if (numer < 0) {
        numer = -numer;
        n_sign = -1;
    }
    if (denom < 0) {
        denom = -denom;
        d_sign = -1;
    }

    result.quot = (numer / denom) * (n_sign * d_sign);
    result.rem = (numer * n_sign) - (d_sign * (result.quot * denom));
    return result;
}

asm void fn_8007E96C(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r24, 0x10(r1)
    or.	r24, r3, r3
    mr	r25, r4
    mr	r29, r5
    mr	r26, r6
    mr	r27, r7
    bc      12, 2, _8007e9b4
    cmplwi	r25, 0
    bc      12, 2, _8007e9b4
    cmplwi	r29, 0
    bc      12, 2, _8007e9b4
    cmplwi	r26, 0
    bc      12, 2, _8007e9b4
    cmplwi	r27, 0
    bc      4, 2, _8007e9bc
_8007e9b4:
    li	r3, 0
    b       _8007ea44
_8007e9bc:
    mr	r12, r27
    mr	r28, r25
    mtctr	r12
    bctrl
    cmpwi	r3, 0
    bc      4, 2, _8007e9dc
    mr	r3, r28
    b       _8007ea44
_8007e9dc:
    bc      4, 0, _8007e9e8
    li	r3, 0
    b       _8007ea44
_8007e9e8:
    addi	r29, r29, -1
    li	r30, 1
    b       _8007ea38
_8007e9f4:
    add	r0, r30, r29
    mr	r12, r27
    srwi	r28, r0, 1
    mr	r3, r24
    mullw	r0, r26, r28
    add	r31, r25, r0
    mr	r4, r31
    mtctr	r12
    bctrl
    cmpwi	r3, 0
    bc      4, 2, _8007ea28
    mr	r3, r31
    b       _8007ea44
_8007ea28:
    bc      4, 0, _8007ea34
    addi	r29, r28, -1
    b       _8007ea38
_8007ea34:
    addi	r30, r28, 1
_8007ea38:
    cmplw	r30, r29
    bc      4, 1, _8007e9f4
    li	r3, 0
_8007ea44:
    lmw	r24, 0x10(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void fn_8007EA58(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    or.	r27, r5, r5
    mr	r29, r3
    mr	r30, r4
    mr	r31, r6
    lhz	r0, 4(r3)
    rlwinm	r28, r0, 0x1a, 0x1d, 0x1f
    bc      4, 2, _8007ea88
    bl      fn_8007F8D4
_8007ea88:
    lbz	r0, 8(r29)
    rlwinm.	r0, r0, 0x1b, 0x1d, 0x1f
    bc      4, 2, _8007ea9c
    cmpwi	r28, 0
    bc      4, 2, _8007eaa4
_8007ea9c:
    li	r3, -1
    b       _8007eba8
_8007eaa4:
    cmpwi	r27, 0
    bc      12, 2, _8007eac4
    cmpwi	r27, 1
    bc      12, 2, _8007eac4
    cmpwi	r27, 2
    bc      12, 2, _8007eac4
    li	r3, -1
    b       _8007eba8
_8007eac4:
    lwz	r3, 0x1c(r29)
    cmplwi	r3, 0
    bc      12, 2, _8007eae0
    lbz	r0, 8(r29)
    rlwinm.	r0, r0, 0x1c, 0x1f, 0x1f
    bc      12, 2, _8007eae0
    bl      fn_8007A150
_8007eae0:
    li	r3, 2
    bl      __begin_critical_region
    lbz	r0, 4(r29)
    rlwimi	r0, r27, 1, 0x1d, 0x1e
    li	r5, 0
    addi	r3, r29, 0xd
    stb	r0, 4(r29)
    li	r0, 1
    cmpwi	r27, 0
    lbz	r4, 8(r29)
    rlwimi	r4, r5, 4, 0x1b, 0x1b
    stb	r4, 8(r29)
    stw	r3, 0x1c(r29)
    stw	r3, 0x24(r29)
    stw	r0, 0x20(r29)
    stw	r5, 0x28(r29)
    stw	r5, 0x2c(r29)
    bc      12, 2, _8007eb30
    cmplwi	r31, 1
    bc      4, 0, _8007eb4c
_8007eb30:
    lwz	r4, 0x24(r29)
    li	r0, 0
    li	r3, 2
    stb	r0, 0(r4)
    bl      __end_critical_region
    li	r3, 0
    b       _8007eba8
_8007eb4c:
    cmplwi	r30, 0
    bc      4, 2, _8007eb84
    mr	r3, r31
    bl      fn_8007A1C0
    or.	r30, r3, r3
    bc      4, 2, _8007eb74
    li	r3, 2
    bl      __end_critical_region
    li	r3, -1
    b       _8007eba8
_8007eb74:
    lbz	r0, 8(r29)
    li	r3, 1
    rlwimi	r0, r3, 4, 0x1b, 0x1b
    stb	r0, 8(r29)
_8007eb84:
    stw	r30, 0x1c(r29)
    li	r0, 0
    li	r3, 2
    lwz	r4, 0x1c(r29)
    stw	r4, 0x24(r29)
    stw	r31, 0x20(r29)
    stw	r0, 0x2c(r29)
    bl      __end_critical_region
    li	r3, 0
_8007eba8:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

// provenance: mkdd:libs/PowerPC_EABI_Support/src/MSL_C/MSL_Common/buffer_io.c:27
#pragma dont_inline on
int __flush_buffer(void* file_ptr, unsigned int* length)
{
    typedef struct FlushFile {
        unsigned int handle;
        unsigned char pad04[0x14];
        unsigned int position;
        char* buffer;
        unsigned int buffer_size;
        char* buffer_ptr;
        unsigned int buffer_length;
        unsigned int buffer_mask;
        unsigned int pad30;
        unsigned int buffer_position;
        unsigned char pad38[8];
        int (*write_func)(unsigned int, char*, unsigned int*, unsigned int);
        unsigned char pad44[4];
        unsigned int ref_con;
    } FlushFile;
    FlushFile* file = (FlushFile*)file_ptr;
    unsigned int buffer_len;
    int write_code;

    buffer_len = file->buffer_ptr - file->buffer;
    if (buffer_len != 0) {
        file->buffer_length = buffer_len;
        write_code = file->write_func(file->handle, file->buffer, &file->buffer_length, file->ref_con);
        if (length != 0) {
            *length = file->buffer_length;
        }
        if (write_code != 0) {
            return write_code;
        }
        file->position += file->buffer_length;
    }

    file->buffer_ptr = file->buffer;
    file->buffer_length = file->buffer_size;
    file->buffer_length -= file->position & file->buffer_mask;
    file->buffer_position = file->position;
    return 0;
}
#pragma dont_inline reset

// provenance: original
int fn_8007EC80(void* file, unsigned int* outp, int flag)
{
    char* f = (char*)file;
    int r;

    *(int*)(f + 0x24) = *(int*)(f + 0x1C);
    *(int*)(f + 0x28) = *(int*)(f + 0x20);
    *(int*)(f + 0x28) -= *(int*)(f + 0x18) & *(int*)(f + 0x2C);
    *(int*)(f + 0x34) = *(int*)(f + 0x18);
    if (flag == 1) {
        *(int*)(f + 0x28) = *(int*)(f + 0x20);
    }

    r = (*(int (**)(void*, void*, unsigned int*, void*))(f + 0x3C))(
            *(void**)f, *(void**)(f + 0x1C),
            (unsigned int*)(f + 0x28), *(void**)(f + 0x48));

    if (r == 2) {
        *(int*)(f + 0x28) = 0;
    }
    if (outp != 0) {
        *outp = *(unsigned int*)(f + 0x28);
    }
    if (r != 0) {
        return r;
    }
    *(int*)(f + 0x18) += *(int*)(f + 0x28);
    return 0;
}

// provenance: original
// harvested 2026-08-26 from hard2's logged 100% attempt; spliced into the current head
void __prep_buffer(void* p) {
    ((int*)p)[9]  = ((int*)p)[7];            /* +0x24 = +0x1c */
    ((int*)p)[10] = ((int*)p)[8];            /* +0x28 = +0x20 */
    ((int*)p)[10] = ((int*)p)[10] - (((int*)p)[6] & ((int*)p)[11]);
    ((int*)p)[13] = ((int*)p)[6];            /* +0x34 = +0x18 */
}

#pragma dont_inline on
// provenance: mkdd:libs/PowerPC_EABI_Support/src/MSL_C/PPC_EABI/critical_regions.gamecube.c:10
void __end_critical_region(int region) { return; }

// provenance: mkdd:libs/PowerPC_EABI_Support/src/MSL_C/PPC_EABI/critical_regions.gamecube.c:8
void __begin_critical_region(int region) { return; }

// provenance: mkdd:libs/PowerPC_EABI_Support/src/MSL_C/PPC_EABI/critical_regions.gamecube.c:6
void __kill_critical_regions(void) {}
#pragma dont_inline reset

// provenance: original
// harvested 2026-08-26 from hard2's logged 100% attempt; spliced into the current head
int MSL_CharAttrLookup(int c) { if (c == -1) return -1; return lbl_8015B200[(unsigned char)c]; }

asm unsigned long __fwrite(const void* buf, unsigned long size,
                          unsigned long count, void* file)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r25, 0x14(r1)
    mr	r25, r4
    mr	r26, r6
    mr	r27, r3
    mr	r28, r5
    li	r4, 0
    mr	r3, r26
    bl      fwide
    cmpwi	r3, 0
    bc      4, 2, _8007edf4
    mr	r3, r26
    li	r4, -1
    bl      fwide
_8007edf4:
    mullw.	r29, r25, r28
    bc      12, 2, _8007ee14
    lbz	r0, 0xa(r26)
    cmplwi	r0, 0
    bc      4, 2, _8007ee14
    lhz	r0, 4(r26)
    rlwinm.	r0, r0, 0x1a, 0x1d, 0x1f
    bc      4, 2, _8007ee1c
_8007ee14:
    li	r3, 0
    b       _8007f0ac
_8007ee1c:
    cmplwi	r0, 2
    bc      4, 2, _8007ee28
    bl      __stdio_atexit
_8007ee28:
    lbz	r0, 5(r26)
    li	r31, 1
    li	r3, 0
    rlwinm.	r0, r0, 0x1d, 0x1f, 0x1f
    bc      12, 2, _8007ee4c
    lbz	r0, 4(r26)
    rlwinm	r0, r0, 0x1f, 0x1e, 0x1f
    cmplwi	r0, 2
    bc      4, 2, _8007ee50
_8007ee4c:
    li	r3, 1
_8007ee50:
    cmpwi	r3, 0
    bc      4, 2, _8007ee6c
    lbz	r0, 4(r26)
    rlwinm	r0, r0, 0x1f, 0x1e, 0x1f
    cmplwi	r0, 1
    bc      12, 2, _8007ee6c
    li	r31, 0
_8007ee6c:
    lbz	r0, 8(r26)
    rlwinm.	r0, r0, 0x1b, 0x1d, 0x1f
    bc      4, 2, _8007eec8
    lbz	r3, 4(r26)
    rlwinm.	r0, r3, 0x1d, 0x1e, 0x1e
    rlwinm	r3, r3, 0x1d, 0x1d, 0x1f
    bc      12, 2, _8007eec8
    rlwinm.	r0, r3, 0, 0x1d, 0x1d
    bc      12, 2, _8007eeb0
    mr	r3, r26
    li	r4, 0
    li	r5, 2
    bl      fseek
    cmpwi	r3, 0
    bc      12, 2, _8007eeb0
    li	r3, 0
    b       _8007f0ac
_8007eeb0:
    lbz	r0, 8(r26)
    li	r3, 1
    rlwimi	r0, r3, 5, 0x18, 0x1a
    mr	r3, r26
    stb	r0, 8(r26)
    bl      __prep_buffer
_8007eec8:
    lbz	r0, 8(r26)
    rlwinm	r0, r0, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 1
    bc      12, 2, _8007eef0
    li	r3, 1
    li	r0, 0
    stb	r3, 0xa(r26)
    li	r3, 0
    stw	r0, 0x28(r26)
    b       _8007f0ac
_8007eef0:
    cmplwi	r29, 0
    mr	r30, r27
    li	r28, 0
    bc      12, 2, _8007f01c
    lwz	r4, 0x24(r26)
    lwz	r3, 0x1c(r26)
    cmplw	r4, r3
    bc      4, 2, _8007ef18
    cmpwi	r31, 0
    bc      12, 2, _8007f01c
_8007ef18:
    lwz	r0, 0x20(r26)
    subf	r3, r3, r4
    subf	r0, r3, r0
    stw	r0, 0x28(r26)
_8007ef28:
    lwz	r0, 0x28(r26)
    li	r27, 0
    cmplw	r0, r29
    stw	r0, 8(r1)
    bc      4, 1, _8007ef40
    stw	r29, 8(r1)
_8007ef40:
    lbz	r0, 4(r26)
    rlwinm	r0, r0, 0x1f, 0x1e, 0x1f
    cmplwi	r0, 1
    bc      4, 2, _8007ef7c
    lwz	r5, 8(r1)
    cmplwi	r5, 0
    bc      12, 2, _8007ef7c
    mr	r3, r30
    li	r4, 0xa
    bl      __memrchr
    or.	r27, r3, r3
    bc      12, 2, _8007ef7c
    addi	r0, r27, 1
    subf	r0, r30, r0
    stw	r0, 8(r1)
_8007ef7c:
    lwz	r5, 8(r1)
    cmplwi	r5, 0
    bc      12, 2, _8007efc0
    lwz	r3, 0x24(r26)
    mr	r4, r30
    bl      memcpy
    lwz	r3, 8(r1)
    lwz	r0, 0x24(r26)
    add	r30, r30, r3
    add	r28, r28, r3
    add	r0, r0, r3
    subf	r29, r3, r29
    stw	r0, 0x24(r26)
    lwz	r3, 8(r1)
    lwz	r0, 0x28(r26)
    subf	r0, r3, r0
    stw	r0, 0x28(r26)
_8007efc0:
    lwz	r0, 0x28(r26)
    cmplwi	r0, 0
    bc      12, 2, _8007efe0
    cmplwi	r27, 0
    bc      4, 2, _8007efe0
    lbz	r0, 4(r26)
    rlwinm.	r0, r0, 0x1f, 0x1e, 0x1f
    bc      4, 2, _8007f00c
_8007efe0:
    mr	r3, r26
    li	r4, 0
    bl      __flush_buffer
    cmpwi	r3, 0
    bc      12, 2, _8007f00c
    li	r3, 1
    li	r0, 0
    stb	r3, 0xa(r26)
    li	r29, 0
    stw	r0, 0x28(r26)
    b       _8007f01c
_8007f00c:
    cmplwi	r29, 0
    bc      12, 2, _8007f01c
    cmpwi	r31, 0
    bc      4, 2, _8007ef28
_8007f01c:
    cmplwi	r29, 0
    bc      12, 2, _8007f088
    cmpwi	r31, 0
    bc      4, 2, _8007f088
    lwz	r27, 0x1c(r26)
    add	r0, r30, r29
    lwz	r31, 0x20(r26)
    mr	r3, r26
    addi	r4, r1, 8
    stw	r30, 0x1c(r26)
    stw	r29, 0x20(r26)
    stw	r0, 0x24(r26)
    bl      __flush_buffer
    cmpwi	r3, 0
    bc      12, 2, _8007f068
    li	r3, 1
    li	r0, 0
    stb	r3, 0xa(r26)
    stw	r0, 0x28(r26)
_8007f068:
    lwz	r0, 8(r1)
    mr	r3, r26
    stw	r27, 0x1c(r26)
    add	r28, r28, r0
    stw	r31, 0x20(r26)
    bl      __prep_buffer
    li	r0, 0
    stw	r0, 0x28(r26)
_8007f088:
    lbz	r0, 4(r26)
    rlwinm	r0, r0, 0x1f, 0x1e, 0x1f
    cmplwi	r0, 2
    bc      12, 2, _8007f0a0
    li	r0, 0
    stw	r0, 0x28(r26)
_8007f0a0:
    addi	r0, r25, -1
    add	r0, r28, r0
    divwu	r3, r0, r25
_8007f0ac:
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

// provenance: mkdd:libs/PowerPC_EABI_Support/src/MSL_C/MSL_Common/direct_io.c:24
unsigned long fwrite(const void* buf, unsigned long size, unsigned long count, void* file)
{
    unsigned long n;

    __begin_critical_region(2);
    n = __fwrite(buf, size, count, file);
    __end_critical_region(2);
    return n;
}

asm int fn_8007F13C(void* a, void* b, unsigned long n, void* file)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r25, 0x14(r1)
    mr	r26, r4
    mr	r27, r6
    mr	r28, r3
    mr	r25, r5
    li	r4, 0
    mr	r3, r27
    bl      fwide
    cmpwi	r3, 0
    bc      4, 2, _8007f17c
    mr	r3, r27
    li	r4, -1
    bl      fwide
_8007f17c:
    mullw.	r29, r26, r25
    bc      12, 2, _8007f19c
    lbz	r0, 0xa(r27)
    cmplwi	r0, 0
    bc      4, 2, _8007f19c
    lhz	r0, 4(r27)
    rlwinm.	r0, r0, 0x1a, 0x1d, 0x1f
    bc      4, 2, _8007f1a4
_8007f19c:
    li	r3, 0
    b       _8007f478
_8007f1a4:
    lbz	r0, 5(r27)
    li	r31, 1
    rlwinm.	r0, r0, 0x1d, 0x1f, 0x1f
    bc      12, 2, _8007f1c8
    lbz	r0, 4(r27)
    rlwinm	r0, r0, 0x1f, 0x1e, 0x1f
    cmplwi	r0, 2
    bc      12, 2, _8007f1c8
    li	r31, 0
_8007f1c8:
    lbz	r3, 8(r27)
    rlwinm.	r0, r3, 0x1b, 0x1d, 0x1f
    bc      4, 2, _8007f1f4
    lbz	r0, 4(r27)
    rlwinm.	r0, r0, 0x1d, 0x1f, 0x1f
    bc      12, 2, _8007f1f4
    li	r0, 2
    rlwimi	r3, r0, 5, 0x18, 0x1a
    stb	r3, 8(r27)
    li	r0, 0
    stw	r0, 0x28(r27)
_8007f1f4:
    lbz	r0, 8(r27)
    rlwinm	r0, r0, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 2
    bc      4, 0, _8007f21c
    li	r3, 1
    li	r0, 0
    stb	r3, 0xa(r27)
    li	r3, 0
    stw	r0, 0x28(r27)
    b       _8007f478
_8007f21c:
    lbz	r0, 4(r27)
    rlwinm.	r0, r0, 0x1f, 0x1f, 0x1f
    bc      12, 2, _8007f24c
    bl      fn_8007B028
    cmpwi	r3, 0
    bc      12, 2, _8007f24c
    li	r3, 1
    li	r0, 0
    stb	r3, 0xa(r27)
    li	r3, 0
    stw	r0, 0x28(r27)
    b       _8007f478
_8007f24c:
    cmplwi	r29, 0
    mr	r30, r28
    li	r28, 0
    bc      12, 2, _8007f308
    lbz	r0, 8(r27)
    rlwinm	r0, r0, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 3
    bc      12, 0, _8007f308
_8007f26c:
    mr	r3, r27
    li	r4, 0
    bl      fwide
    cmpwi	r3, 1
    bc      4, 2, _8007f2a4
    lbz	r0, 8(r27)
    addi	r28, r28, 2
    addi	r29, r29, -2
    rlwinm	r3, r0, 0x1c, 0x1c, 0x1e
    addi	r0, r3, 0xc
    lhzx	r0, r27, r0
    sth	r0, 0(r30)
    addi	r30, r30, 2
    b       _8007f2c4
_8007f2a4:
    lbz	r0, 8(r27)
    addi	r28, r28, 1
    addi	r29, r29, -1
    rlwinm	r3, r0, 0x1b, 0x1d, 0x1f
    addi	r0, r3, 0xc
    lbzx	r0, r27, r0
    stb	r0, 0(r30)
    addi	r30, r30, 1
_8007f2c4:
    lbz	r4, 8(r27)
    cmplwi	r29, 0
    rlwinm	r3, r4, 0x1b, 0x1d, 0x1f
    addi	r0, r3, -1
    rlwimi	r4, r0, 5, 0x18, 0x1a
    stb	r4, 8(r27)
    bc      12, 2, _8007f2f0
    lbz	r0, 8(r27)
    rlwinm	r0, r0, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 3
    bc      4, 0, _8007f26c
_8007f2f0:
    lbz	r0, 8(r27)
    rlwinm	r0, r0, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 2
    bc      4, 2, _8007f308
    lwz	r0, 0x30(r27)
    stw	r0, 0x28(r27)
_8007f308:
    cmplwi	r29, 0
    bc      12, 2, _8007f3e4
    lwz	r0, 0x28(r27)
    cmplwi	r0, 0
    bc      4, 2, _8007f324
    cmpwi	r31, 0
    bc      12, 2, _8007f3e4
_8007f324:
    lwz	r0, 0x28(r27)
    cmplwi	r0, 0
    bc      4, 2, _8007f388
    mr	r3, r27
    li	r4, 0
    li	r5, 0
    bl      fn_8007EC80
    cmpwi	r3, 0
    bc      12, 2, _8007f388
    cmpwi	r3, 1
    bc      4, 2, _8007f364
    li	r3, 1
    li	r0, 0
    stb	r3, 0xa(r27)
    stw	r0, 0x28(r27)
    b       _8007f380
_8007f364:
    lbz	r3, 8(r27)
    li	r4, 0
    rlwimi	r3, r4, 5, 0x18, 0x1a
    li	r0, 1
    stb	r3, 8(r27)
    stb	r0, 9(r27)
    stw	r4, 0x28(r27)
_8007f380:
    li	r29, 0
    b       _8007f3e4
_8007f388:
    lwz	r0, 0x28(r27)
    cmplw	r0, r29
    stw	r0, 8(r1)
    bc      4, 1, _8007f39c
    stw	r29, 8(r1)
_8007f39c:
    lwz	r4, 0x24(r27)
    mr	r3, r30
    lwz	r5, 8(r1)
    bl      memcpy
    lwz	r3, 8(r1)
    lwz	r0, 0x24(r27)
    subf.	r29, r3, r29
    add	r30, r30, r3
    add	r0, r0, r3
    add	r28, r28, r3
    stw	r0, 0x24(r27)
    lwz	r3, 8(r1)
    lwz	r0, 0x28(r27)
    subf	r0, r3, r0
    stw	r0, 0x28(r27)
    bc      12, 2, _8007f3e4
    cmpwi	r31, 0
    bc      4, 2, _8007f324
_8007f3e4:
    cmplwi	r29, 0
    bc      12, 2, _8007f474
    cmpwi	r31, 0
    bc      4, 2, _8007f474
    lwz	r31, 0x1c(r27)
    mr	r3, r27
    lwz	r25, 0x20(r27)
    addi	r4, r1, 8
    li	r5, 1
    stw	r30, 0x1c(r27)
    stw	r29, 0x20(r27)
    bl      fn_8007EC80
    cmpwi	r3, 0
    bc      12, 2, _8007f454
    cmpwi	r3, 1
    bc      4, 2, _8007f438
    li	r3, 1
    li	r0, 0
    stb	r3, 0xa(r27)
    stw	r0, 0x28(r27)
    b       _8007f454
_8007f438:
    lbz	r3, 8(r27)
    li	r4, 0
    rlwimi	r3, r4, 5, 0x18, 0x1a
    li	r0, 1
    stb	r3, 8(r27)
    stb	r0, 9(r27)
    stw	r4, 0x28(r27)
_8007f454:
    lwz	r0, 8(r1)
    mr	r3, r27
    stw	r31, 0x1c(r27)
    add	r28, r28, r0
    stw	r25, 0x20(r27)
    bl      __prep_buffer
    li	r0, 0
    stw	r0, 0x28(r27)
_8007f474:
    divwu	r3, r28, r26
_8007f478:
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

// provenance: original
int fn_8007F48C(void* a, void* b, unsigned long n, void* file)
{
    int r;

    __begin_critical_region(2);
    r = fn_8007F13C(a, b, n, file);
    __end_critical_region(2);
    return r;
}

asm void fn_8007F508(void)
{
    nofralloc
    lhz	r5, 0(r4)
    li	r0, 1
    rlwimi	r5, r0, 6, 0x17, 0x19
    lbz	r0, 0(r3)
    sth	r5, 0(r4)
    li	r5, 0
    extsb	r6, r0
    lbz	r0, 1(r4)
    rlwimi	r0, r5, 4, 0x1a, 0x1b
    cmpwi	r6, 0x72
    stb	r0, 1(r4)
    lbz	r0, 1(r4)
    rlwimi	r0, r5, 3, 0x1c, 0x1c
    stb	r0, 1(r4)
    bc      12, 2, _8007f560
    bc      4, 0, _8007f554
    cmpwi	r6, 0x61
    bc      12, 2, _8007f570
    b       _8007f578
_8007f554:
    cmpwi	r6, 0x77
    bc      12, 2, _8007f568
    b       _8007f578
_8007f560:
    li	r7, 0
    b       _8007f580
_8007f568:
    li	r7, 2
    b       _8007f580
_8007f570:
    li	r7, 1
    b       _8007f580
_8007f578:
    li	r3, 0
    blr
_8007f580:
    lbz	r0, 1(r3)
    addi	r5, r3, 2
    lbz	r3, 0(r4)
    rlwimi	r3, r7, 6, 0x18, 0x19
    extsb	r0, r0
    cmpwi	r0, 0x62
    stb	r3, 0(r4)
    bc      12, 2, _8007f5b0
    bc      4, 0, _8007f5fc
    cmpwi	r0, 0x2b
    bc      12, 2, _8007f5d8
    b       _8007f5fc
_8007f5b0:
    lbz	r0, 0(r5)
    li	r5, 1
    lbz	r3, 1(r4)
    rlwimi	r3, r5, 3, 0x1c, 0x1c
    cmpwi	r0, 0x2b
    stb	r3, 1(r4)
    bc      4, 2, _8007f5fc
    slwi	r0, r6, 8
    ori	r6, r0, 0x2b
    b       _8007f5fc
_8007f5d8:
    lbz	r0, 0(r5)
    slwi	r3, r6, 8
    ori	r6, r3, 0x2b
    cmpwi	r0, 0x62
    bc      4, 2, _8007f5fc
    lbz	r0, 1(r4)
    li	r3, 1
    rlwimi	r0, r3, 3, 0x1c, 0x1c
    stb	r0, 1(r4)
_8007f5fc:
    cmpwi	r6, 0x612b
    bc      12, 2, _8007f66c
    bc      4, 0, _8007f62c
    cmpwi	r6, 0x72
    bc      12, 2, _8007f644
    bc      4, 0, _8007f620
    cmpwi	r6, 0x61
    bc      12, 2, _8007f654
    b       _8007f670
_8007f620:
    cmpwi	r6, 0x77
    bc      12, 2, _8007f64c
    b       _8007f670
_8007f62c:
    cmpwi	r6, 0x772b
    bc      12, 2, _8007f664
    bc      4, 0, _8007f670
    cmpwi	r6, 0x722b
    bc      12, 2, _8007f65c
    b       _8007f670
_8007f644:
    li	r8, 1
    b       _8007f670
_8007f64c:
    li	r8, 2
    b       _8007f670
_8007f654:
    li	r8, 6
    b       _8007f670
_8007f65c:
    li	r8, 3
    b       _8007f670
_8007f664:
    li	r8, 3
    b       _8007f670
_8007f66c:
    li	r8, 7
_8007f670:
    lbz	r0, 0(r4)
    rlwimi	r0, r8, 3, 0x1a, 0x1c
    li	r3, 1
    stb	r0, 0(r4)
    blr
}

asm void fn_8007F684(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    stw	r30, 0x28(r1)
    mr	r30, r4
    stw	r29, 0x24(r1)
    mr	r29, r3
    li	r3, 2
    stw	r28, 0x20(r1)
    bl      __begin_critical_region
    bl      fn_8007B2A8
    mr	r31, r3
    bl      __stdio_atexit
    cmplwi	r31, 0
    bc      4, 2, _8007f6cc
    li	r31, 0
    b       _8007f8a8
_8007f6cc:
    bc      12, 2, _8007f800
    lhz	r0, 4(r31)
    rlwinm.	r3, r0, 0x1a, 0x1d, 0x1f
    bc      12, 2, _8007f800
    cmplwi	r31, 0
    bc      4, 2, _8007f6ec
    bl      fn_8007B0B4
    b       _8007f7c8
_8007f6ec:
    lbz	r0, 0xa(r31)
    cmplwi	r0, 0
    bc      4, 2, _8007f7c8
    cmplwi	r3, 0
    bc      12, 2, _8007f7c8
    lbz	r0, 4(r31)
    rlwinm	r0, r0, 0x1d, 0x1d, 0x1f
    cmplwi	r0, 1
    bc      12, 2, _8007f7c8
    lbz	r3, 8(r31)
    rlwinm	r0, r3, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 3
    bc      12, 0, _8007f72c
    li	r0, 2
    rlwimi	r3, r0, 5, 0x18, 0x1a
    stb	r3, 8(r31)
_8007f72c:
    lbz	r0, 8(r31)
    rlwinm	r0, r0, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 2
    bc      4, 2, _8007f744
    li	r0, 0
    stw	r0, 0x28(r31)
_8007f744:
    lbz	r3, 8(r31)
    rlwinm	r0, r3, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 1
    bc      12, 2, _8007f764
    li	r0, 0
    rlwimi	r3, r0, 5, 0x18, 0x1a
    stb	r3, 8(r31)
    b       _8007f7c8
_8007f764:
    lhz	r0, 4(r31)
    rlwinm	r0, r0, 0x1a, 0x1d, 0x1f
    cmplwi	r0, 1
    bc      12, 2, _8007f77c
    li	r28, 0
    b       _8007f788
_8007f77c:
    mr	r3, r31
    bl      fn_8007FE70
    mr	r28, r3
_8007f788:
    mr	r3, r31
    li	r4, 0
    bl      __flush_buffer
    cmpwi	r3, 0
    bc      12, 2, _8007f7b0
    li	r3, 1
    li	r0, 0
    stb	r3, 0xa(r31)
    stw	r0, 0x28(r31)
    b       _8007f7c8
_8007f7b0:
    lbz	r0, 8(r31)
    li	r3, 0
    rlwimi	r0, r3, 5, 0x18, 0x1a
    stb	r0, 8(r31)
    stw	r28, 0x18(r31)
    stw	r3, 0x28(r31)
_8007f7c8:
    lwz	r12, 0x44(r31)
    lwz	r3, 0(r31)
    mtctr	r12
    bctrl
    lhz	r0, 4(r31)
    li	r3, 0
    rlwimi	r0, r3, 6, 0x17, 0x19
    sth	r0, 4(r31)
    stw	r3, 0(r31)
    lbz	r0, 8(r31)
    rlwinm.	r0, r0, 0x1c, 0x1f, 0x1f
    bc      12, 2, _8007f800
    lwz	r3, 0x1c(r31)
    bl      fn_8007A150
_8007f800:
    mr	r3, r31
    bl      fn_8008068C
    mr	r3, r30
    addi	r4, r1, 8
    bl      fn_8007F508
    cmpwi	r3, 0
    bc      4, 2, _8007f824
    li	r31, 0
    b       _8007f8a8
_8007f824:
    lwz	r0, 8(r1)
    mr	r3, r31
    addi	r4, r1, 0xc
    li	r5, 0
    stw	r0, 0xc(r1)
    li	r6, 0x400
    bl      __init_file
    lwz	r0, 8(r1)
    mr	r3, r29
    mr	r5, r31
    addi	r4, r1, 0x10
    stw	r0, 0x10(r1)
    bl      TRK_OpenFile_Game
    cmpwi	r3, 0
    bc      12, 2, _8007f88c
    lhz	r0, 4(r31)
    li	r3, 0
    rlwimi	r0, r3, 6, 0x17, 0x19
    sth	r0, 4(r31)
    lbz	r0, 8(r31)
    rlwinm.	r0, r0, 0x1c, 0x1f, 0x1f
    bc      12, 2, _8007f884
    lwz	r3, 0x1c(r31)
    bl      fn_8007A150
_8007f884:
    li	r31, 0
    b       _8007f8a8
_8007f88c:
    lbz	r0, 8(r1)
    rlwinm.	r0, r0, 0x1d, 0x1d, 0x1d
    bc      12, 2, _8007f8a8
    mr	r3, r31
    li	r4, 0
    li	r5, 2
    bl      fseek
_8007f8a8:
    li	r3, 2
    bl      __end_critical_region
    lwz	r0, 0x34(r1)
    mr	r3, r31
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    lwz	r28, 0x20(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

// provenance: original
int fn_8007F8D4(void* file_p)
{
    File* file = (File*)file_p;
    long pos;
    int r;

    if (file == 0) {
        return fn_8007B0B4();
    }
    if (file->byte0A != 0 || file->open.mode == 0) {
        return -1;
    }
    if ((((unsigned int)(*(unsigned char*)((char*)file + 4)) >> 3) & 7) == 1) {
        return 0;
    }
    if (file->buffer.kind >= 3) {
        file->buffer.kind = 2;
    }
    if (file->buffer.kind == 2) {
        file->buffer_length = 0;
    }
    if (file->buffer.kind != 1) {
        file->buffer.kind = 0;
        return 0;
    }
    if (file->open.mode != 1) {
        pos = 0;
    } else {
        pos = fn_8007FE70(file);
    }
    r = __flush_buffer(file, 0);
    if (r != 0) {
        file->byte0A = 1;
        file->buffer_length = 0;
        return -1;
    }
    file->buffer.kind = 0;
    file->position = pos;
    file->buffer_length = 0;
    return 0;
}

asm void fn_8007FA0C(void* file)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    or.	r31, r3, r3
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    bc      4, 2, _8007fa34
    li	r3, -1
    b       _8007fbac
_8007fa34:
    lhz	r0, 4(r31)
    rlwinm.	r3, r0, 0x1a, 0x1d, 0x1f
    bc      4, 2, _8007fa48
    li	r3, 0
    b       _8007fbac
_8007fa48:
    cmplwi	r31, 0
    bc      4, 2, _8007fa5c
    bl      fn_8007B0B4
    mr	r29, r3
    b       _8007fb4c
_8007fa5c:
    lbz	r0, 0xa(r31)
    cmplwi	r0, 0
    bc      4, 2, _8007fa70
    cmplwi	r3, 0
    bc      4, 2, _8007fa78
_8007fa70:
    li	r29, -1
    b       _8007fb4c
_8007fa78:
    lbz	r0, 4(r31)
    rlwinm	r0, r0, 0x1d, 0x1d, 0x1f
    cmplwi	r0, 1
    bc      4, 2, _8007fa90
    li	r29, 0
    b       _8007fb4c
_8007fa90:
    lbz	r3, 8(r31)
    rlwinm	r0, r3, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 3
    bc      12, 0, _8007faac
    li	r0, 2
    rlwimi	r3, r0, 5, 0x18, 0x1a
    stb	r3, 8(r31)
_8007faac:
    lbz	r0, 8(r31)
    rlwinm	r0, r0, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 2
    bc      4, 2, _8007fac4
    li	r0, 0
    stw	r0, 0x28(r31)
_8007fac4:
    lbz	r3, 8(r31)
    rlwinm	r0, r3, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 1
    bc      12, 2, _8007fae4
    li	r29, 0
    rlwimi	r3, r29, 5, 0x18, 0x1a
    stb	r3, 8(r31)
    b       _8007fb4c
_8007fae4:
    lhz	r0, 4(r31)
    rlwinm	r0, r0, 0x1a, 0x1d, 0x1f
    cmplwi	r0, 1
    bc      12, 2, _8007fafc
    li	r30, 0
    b       _8007fb08
_8007fafc:
    mr	r3, r31
    bl      fn_8007FE70
    mr	r30, r3
_8007fb08:
    mr	r3, r31
    li	r4, 0
    bl      __flush_buffer
    cmpwi	r3, 0
    bc      12, 2, _8007fb34
    li	r3, 1
    li	r0, 0
    stb	r3, 0xa(r31)
    li	r29, -1
    stw	r0, 0x28(r31)
    b       _8007fb4c
_8007fb34:
    li	r29, 0
    lbz	r0, 8(r31)
    rlwimi	r0, r29, 5, 0x18, 0x1a
    stb	r0, 8(r31)
    stw	r30, 0x18(r31)
    stw	r29, 0x28(r31)
_8007fb4c:
    lwz	r12, 0x44(r31)
    lwz	r3, 0(r31)
    mtctr	r12
    bctrl
    lhz	r0, 4(r31)
    li	r4, 0
    rlwimi	r0, r4, 6, 0x17, 0x19
    mr	r30, r3
    sth	r0, 4(r31)
    stw	r4, 0(r31)
    lbz	r0, 8(r31)
    rlwinm.	r0, r0, 0x1c, 0x1f, 0x1f
    bc      12, 2, _8007fb88
    lwz	r3, 0x1c(r31)
    bl      fn_8007A150
_8007fb88:
    cmpwi	r29, 0
    li	r3, 0
    bc      4, 2, _8007fb9c
    cmpwi	r30, 0
    bc      12, 2, _8007fba0
_8007fb9c:
    li	r3, 1
_8007fba0:
    neg	r0, r3
    or	r0, r0, r3
    srawi	r3, r0, 0x1f
_8007fbac:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

// provenance: mkdd:libs/PowerPC_EABI_Support/src/MSL_C/MSL_Common/file_io.c (fseek wrapper shape)
int fseek(void* file, long offset, int whence)
{
    int r;

    __begin_critical_region(2);
    r = fn_8007FC34(file, offset, whence);
    __end_critical_region(2);
    return r;
}

asm int fn_8007FC34(void* file, long offset, int whence)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r5
    stw	r30, 0x18(r1)
    mr	r30, r3
    stw	r4, 8(r1)
    lhz	r0, 4(r3)
    rlwinm	r0, r0, 0x1a, 0x1d, 0x1f
    cmplwi	r0, 1
    bc      4, 2, _8007fc70
    lbz	r0, 0xa(r30)
    cmplwi	r0, 0
    bc      12, 2, _8007fc80
_8007fc70:
    li	r0, 0x28
    li	r3, -1
    stw	r0, lbl_801A6DE0
    b       _8007fe58
_8007fc80:
    lbz	r0, 8(r30)
    rlwinm	r0, r0, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 1
    bc      4, 2, _8007fcc0
    li	r4, 0
    bl      __flush_buffer
    cmpwi	r3, 0
    bc      12, 2, _8007fcc0
    li	r0, 1
    li	r4, 0
    stb	r0, 0xa(r30)
    li	r0, 0x28
    li	r3, -1
    stw	r4, 0x28(r30)
    stw	r0, lbl_801A6DE0
    b       _8007fe58
_8007fcc0:
    cmpwi	r31, 1
    bc      4, 2, _8007fd44
    lhz	r0, 4(r30)
    li	r31, 0
    rlwinm	r0, r0, 0x1a, 0x1d, 0x1f
    cmplwi	r0, 1
    bc      12, 2, _8007fce4
    cmplwi	r0, 2
    bc      4, 2, _8007fcf0
_8007fce4:
    lbz	r0, 0xa(r30)
    cmplwi	r0, 0
    bc      12, 2, _8007fd00
_8007fcf0:
    li	r0, 0x28
    li	r3, -1
    stw	r0, lbl_801A6DE0
    b       _8007fd38
_8007fd00:
    lbz	r0, 8(r30)
    rlwinm.	r5, r0, 0x1b, 0x1d, 0x1f
    bc      4, 2, _8007fd14
    lwz	r3, 0x18(r30)
    b       _8007fd38
_8007fd14:
    lwz	r3, 0x1c(r30)
    cmplwi	r5, 3
    lwz	r0, 0x24(r30)
    lwz	r4, 0x34(r30)
    subf	r0, r3, r0
    add	r3, r4, r0
    bc      12, 0, _8007fd38
    addi	r0, r5, -2
    subf	r3, r0, r3
_8007fd38:
    lwz	r0, 8(r1)
    add	r0, r0, r3
    stw	r0, 8(r1)
_8007fd44:
    cmpwi	r31, 2
    bc      12, 2, _8007fdd8
    lbz	r0, 4(r30)
    rlwinm	r0, r0, 0x1d, 0x1d, 0x1f
    cmplwi	r0, 3
    bc      12, 2, _8007fdd8
    lbz	r0, 8(r30)
    rlwinm	r0, r0, 0x1b, 0x1d, 0x1f
    cmplwi	r0, 2
    bc      12, 2, _8007fd74
    cmplwi	r0, 3
    bc      4, 2, _8007fdd8
_8007fd74:
    lwz	r3, 8(r1)
    lwz	r0, 0x18(r30)
    cmplw	r3, r0
    bc      4, 0, _8007fd90
    lwz	r0, 0x34(r30)
    cmplw	r3, r0
    bc      4, 0, _8007fda4
_8007fd90:
    lbz	r0, 8(r30)
    li	r3, 0
    rlwimi	r0, r3, 5, 0x18, 0x1a
    stb	r0, 8(r30)
    b       _8007fde8
_8007fda4:
    lwz	r4, 0x1c(r30)
    subf	r0, r0, r3
    li	r3, 2
    add	r0, r4, r0
    stw	r0, 0x24(r30)
    lwz	r4, 8(r1)
    lwz	r0, 0x18(r30)
    subf	r0, r4, r0
    stw	r0, 0x28(r30)
    lbz	r0, 8(r30)
    rlwimi	r0, r3, 5, 0x18, 0x1a
    stb	r0, 8(r30)
    b       _8007fde8
_8007fdd8:
    lbz	r0, 8(r30)
    li	r3, 0
    rlwimi	r0, r3, 5, 0x18, 0x1a
    stb	r0, 8(r30)
_8007fde8:
    lbz	r0, 8(r30)
    rlwinm.	r0, r0, 0x1b, 0x1d, 0x1f
    bc      4, 2, _8007fe54
    lwz	r12, 0x38(r30)
    cmplwi	r12, 0
    bc      12, 2, _8007fe40
    mr	r5, r31
    addi	r4, r1, 8
    lwz	r3, 0(r30)
    lwz	r6, 0x48(r30)
    mtctr	r12
    bctrl
    cmpwi	r3, 0
    bc      12, 2, _8007fe40
    li	r0, 1
    li	r4, 0
    stb	r0, 0xa(r30)
    li	r0, 0x28
    li	r3, -1
    stw	r4, 0x28(r30)
    stw	r0, lbl_801A6DE0
    b       _8007fe58
_8007fe40:
    li	r3, 0
    stb	r3, 9(r30)
    lwz	r0, 8(r1)
    stw	r0, 0x18(r30)
    stw	r3, 0x28(r30)
_8007fe54:
    li	r3, 0
_8007fe58:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

// provenance: original
long fn_8007FE70(void* file)
{
    char* f = (char*)file;
    unsigned int mode;
    unsigned int kind;
    long pos;

    __begin_critical_region(2);
    mode = (*(unsigned short*)(f + 4) >> 6) & 7;
    if ((mode != 1 && mode != 2) || *(unsigned char*)(f + 0xA) != 0) {
        *(int*)lbl_801A6DE0 = 0x28;
        pos = -1;
    } else {
        kind = (*(unsigned char*)(f + 8) >> 5) & 7;
        if (kind == 0) {
            pos = *(long*)(f + 0x18);
        } else {
            pos = *(long*)(f + 0x34) +
                  (*(long*)(f + 0x24) - *(long*)(f + 0x1C));
            if (kind >= 3) {
                pos -= (long)(kind - 2);
            }
        }
    }
    __end_critical_region(2);
    return pos;
}

#pragma force_active off
