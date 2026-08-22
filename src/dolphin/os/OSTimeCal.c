typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct OSCalendarTime {
    int sec;
    int min;
    int hour;
    int mday;
    int mon;
    int year;
    int wday;
    int yday;
    int msec;
    int usec;
} OSCalendarTime;

extern int lbl_80123AF0[];
extern int lbl_80123B20[];
extern int OSDisableInterrupts(void);
extern void fn_80079BF8(void);
extern void fn_800799DC(void);
extern void OSRestoreInterrupts(int level);

asm s64 __OSTimeToSystemTime(register s64 time)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x20(r1)
    stw         r31, 0x1c(r1)
    stw         r30, 0x18(r1)
    mr          r31, r3
    mr          r30, r4
    bl          OSDisableInterrupts
    lis         r5, 0x8000
    lwz         r4, 0x30dc(r5)
    lwz         r0, 0x30d8(r5)
    addc        r30, r4, r30
    adde        r31, r0, r31
    bl          OSRestoreInterrupts
    mr          r4, r30
    mr          r3, r31
    lwz         r0, 0x24(r1)
    lwz         r31, 0x1c(r1)
    lwz         r30, 0x18(r1)
    addi        r1, r1, 0x20
    mtlr        r0
    blr
}

#pragma push
#pragma force_active on
asm void GetDates(register int days, register OSCalendarTime* td)
{
    nofralloc
    lis         r5, 0x9249
    addi        r0, r5, 0x2493
    addi        r7, days, 0x6
    mulhw       r6, r0, r7
    lis         r5, 0xb38d
    subi        r0, r5, 0x64f
    mulhw       r0, r0, days
    add         r5, r6, r7
    srawi       r5, r5, 2
    srwi        r6, r5, 31
    add         r5, r5, r6
    add         r0, r0, days
    mulli       r6, r5, 0x7
    srawi       r0, r0, 8
    srwi        r5, r0, 31
    add         r5, r0, r5
    subf        r0, r6, r7
    mulli       r11, r5, 0x16d
    stw         r0, 0x18(td)
    b           lbl_80011538
lbl_80011538:
    lis         r6, 0x51ec
    subi        r10, r6, 0x7ae1
    b           lbl_80011544
lbl_80011544:
    b           lbl_80011550
lbl_80011548:
    subi        r11, r11, 0x16d
    subi        r5, r5, 0x1
lbl_80011550:
    cmpwi       r5, 0x1
    bge         lbl_80011560
    li          r0, 0x0
    b           lbl_80011594
lbl_80011560:
    subi        r0, r5, 0x1
    mulhw       r0, r10, r0
    srawi       r8, r0, 7
    srawi       r6, r0, 5
    addi        r0, r5, 0x3
    srwi        r7, r6, 31
    srawi       r0, r0, 2
    srwi        r9, r8, 31
    add         r6, r6, r7
    addze       r0, r0
    add         r7, r8, r9
    subf        r0, r6, r0
    add         r0, r7, r0
lbl_80011594:
    add         r0, r11, r0
    cmpw        days, r0
    blt         lbl_80011548
    srawi       r6, r5, 2
    stw         r5, 0x14(td)
    addze       r6, r6
    slwi        r6, r6, 2
    subfc       r6, r6, r5
    subf        r0, r0, days
    cmpwi       r6, 0x0
    stw         r0, 0x1c(td)
    li          r7, 0x1
    li          r8, 0x0
    bne         lbl_800115F8
    lis         r3, 0x51ec
    subi        r3, r3, 0x7ae1
    mulhw       r3, r3, r5
    srawi       r3, r3, 5
    srwi        r6, r3, 31
    add         r3, r3, r6
    mulli       r3, r3, 0x64
    subf        r3, r3, r5
    cmpwi       r3, 0x0
    beq         lbl_800115F8
    mr          r8, r7
lbl_800115F8:
    cmpwi       r8, 0x0
    bne         lbl_8001162C
    lis         r3, 0x51ec
    subi        r3, r3, 0x7ae1
    mulhw       r3, r3, r5
    srawi       r3, r3, 7
    srwi        r6, r3, 31
    add         r3, r3, r6
    mulli       r3, r3, 0x190
    subf        r3, r3, r5
    cmpwi       r3, 0x0
    beq         lbl_8001162C
    li          r7, 0x0
lbl_8001162C:
    cmpwi       r7, 0x0
    beq         lbl_80011640
    lis         r3, lbl_80123B20@ha
    addi        r6, r3, lbl_80123B20@l
    b           lbl_80011648
lbl_80011640:
    lis         r3, lbl_80123AF0@ha
    addi        r6, r3, lbl_80123AF0@l
lbl_80011648:
    li          r7, 0xc
    li          r3, 0x30
    b           lbl_80011654
lbl_80011654:
    b           lbl_80011658
lbl_80011658:
    subi        r3, r3, 0x4
    lwzx        r5, r6, r3
    subi        r7, r7, 0x1
    cmpw        r0, r5
    blt         lbl_80011658
    stw         r7, 0x10(td)
    lwzx        r3, r6, r3
    subf        r3, r3, r0
    addi        r0, r3, 0x1
    stw         r0, 0xc(td)
    blr
}
#pragma pop

#pragma push
#pragma force_active on
asm void OSTicksToCalendarTime(register s64 ticks, register OSCalendarTime* td)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x38(r1)
    stmw        r25, 0x1c(r1)
    mr          r29, r3
    mr          r30, r4
    mr          r31, r5
    lis         r27, 0x8000
    lwz         r0, 0xf8(r27)
    mr          r3, r29
    mr          r4, r30
    srwi        r6, r0, 2
    li          r5, 0x0
    bl          fn_80079BF8
    mr          r26, r3
    li          r5, 0x0
    mr          r25, r4
    xoris       r4, r26, 0x8000
    xoris       r3, r5, 0x8000
    subfc       r0, r5, r25
    subfe       r3, r3, r4
    subfe       r3, r4, r4
    neg         r3, r3
    cmpwi       r3, 0x0
    beq         lbl_800116F8
    lwz         r0, 0xf8(r27)
    srwi        r0, r0, 2
    addc        r25, r25, r0
    adde        r26, r26, r5
lbl_800116F8:
    li          r4, 0x8
    mullw       r3, r26, r4
    mulhwu      r0, r25, r4
    lis         r27, 0x8000
    lwz         r6, 0xf8(r27)
    lis         r5, 0x431c
    subi        r5, r5, 0x217d
    srwi        r6, r6, 2
    mulhwu      r5, r5, r6
    srwi        r6, r5, 15
    li          r28, 0x0
    add         r3, r3, r0
    mullw       r0, r25, r28
    mullw       r4, r25, r4
    add         r3, r3, r0
    li          r5, 0x0
    bl          fn_800799DC
    li          r5, 0x0
    li          r6, 0x3e8
    bl          fn_80079BF8
    stw         r4, 0x24(r31)
    lis         r3, 0x1062
    addi        r5, r3, 0x4dd3
    lwz         r0, 0xf8(r27)
    mr          r3, r26
    mr          r4, r25
    srwi        r0, r0, 2
    mulhwu      r0, r5, r0
    srwi        r6, r0, 6
    li          r5, 0x0
    bl          fn_800799DC
    li          r5, 0x0
    li          r6, 0x3e8
    bl          fn_80079BF8
    stw         r4, 0x20(r31)
    subfc       r30, r25, r30
    subfe       r29, r26, r29
    lwz         r0, 0xf8(r27)
    lis         r5, 0x1
    addi        r25, r5, 0x5180
    mr          r3, r29
    srwi        r6, r0, 2
    mr          r4, r30
    li          r5, 0x0
    bl          fn_800799DC
    mr          r6, r25
    li          r5, 0x0
    bl          fn_800799DC
    lis         r5, 0xb
    lwz         r0, 0xf8(r27)
    addi        r5, r5, 0x2575
    addc        r26, r4, r5
    srwi        r6, r0, 2
    adde        r0, r3, r28
    mr          r3, r29
    mr          r4, r30
    li          r5, 0x0
    bl          fn_800799DC
    mr          r6, r25
    li          r5, 0x0
    bl          fn_80079BF8
    mr          r27, r4
    cmpwi       r27, 0x0
    bge         lbl_80011804
    addis       r27, r27, 0x1
    subi        r26, r26, 0x1
    addi        r27, r27, 0x5180
lbl_80011804:
    mr          r3, r26
    mr          r4, r31
    bl          GetDates
    lis         r3, 0x8889
    subi        r5, r3, 0x7777
    mulhw       r0, r5, r27
    add         r4, r0, r27
    srawi       r0, r4, 5
    srwi        r3, r0, 31
    add         r7, r0, r3
    mulhw       r0, r5, r7
    add         r0, r0, r7
    srawi       r5, r0, 5
    srawi       r0, r0, 5
    srwi        r3, r0, 31
    add         r3, r0, r3
    srawi       r0, r4, 5
    srwi        r6, r5, 31
    mulli       r4, r3, 0x3c
    srwi        r3, r0, 31
    add         r5, r5, r6
    add         r0, r0, r3
    stw         r5, 0x8(r31)
    mulli       r0, r0, 0x3c
    subf        r3, r4, r7
    stw         r3, 0x4(r31)
    subf        r0, r0, r27
    stw         r0, 0x0(r31)
    lmw         r25, 0x1c(r1)
    lwz         r0, 0x3c(r1)
    addi        r1, r1, 0x38
    mtlr        r0
    blr
}
#pragma pop
