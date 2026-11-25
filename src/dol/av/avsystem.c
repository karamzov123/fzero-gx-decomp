#include "types.h"
#include "dolphin/os/OSTime.h"
#include "dol/globals.h"

typedef struct AvSysFifo {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    void *unk_14;
    void *unk_18;
} AvSysFifo;

typedef struct AvSysRenderMode {
    u32 unk_0;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u8 pad_A[0xF];
    u8 unk_19;
    u8 unk_1A[0x18];
    u8 unk_32[0];
} AvSysRenderMode;

typedef struct AvSysState {
    u8 unk_0[0x90];
    u32 unk_90;
    u32 unk_94;
    u8 unk_98[0x100];
    f32 unk_198;
    f32 unk_19c;
    f32 unk_1a0;
    f32 unk_1a4;
    s32 unk_1a8;
    u8 unk_1ac;
    u8 unk_1ad;
    u8 unk_1ae;
    u8 unk_1af;
} AvSysState;

struct Sig_fn_800726C0_fn_800726C0_Entry {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    u8 unk_c;
};

struct fn_80070D60_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
};

typedef enum AvSysPixelFmt {
    AVSYS_GX_PF_RGB8_Z24,
    AVSYS_GX_PF_RGBA6_Z24,
    AVSYS_GX_PF_RGB565_Z16,
    AVSYS_GX_PF_Z24,
    AVSYS_GX_PF_Y8,
    AVSYS_GX_PF_U8,
    AVSYS_GX_PF_V8,
    AVSYS_GX_PF_YUV420,
} AvSysPixelFmt;

typedef enum AvSysZFmt16 {
    AVSYS_GX_ZC_LINEAR,
    AVSYS_GX_ZC_NEAR,
    AVSYS_GX_ZC_MID,
    AVSYS_GX_ZC_FAR,
} AvSysZFmt16;

extern u32 __OSBusClock : 0x800000F8; /* fzgx-allow: A1 fixed cached-RAM bus-clock word; retail carries no reloc */

extern u8 lbl_8012AFB8[60];
extern u8 lbl_8012AFF4[60];
extern u32 lbl_8012B030[];
extern u32 lbl_8012B06C[];
extern u32 lbl_8012B0A8[];
extern char lbl_8015AA10[];
extern char lbl_8015AA78[11];
extern u8 lbl_8015AA84[160];
extern u32 lbl_8015AB24[];
extern u8 lbl_8019E140[16];
extern u32 lbl_8019E150[];
extern u8 lbl_8019E18C[];
extern u8 lbl_801A6620;
extern u8 lbl_801A6621;
extern u32 lbl_801A6CB0;
extern u8 lbl_801A6CB4;
extern u32 lbl_801A6CB8;
extern u16 lbl_801A6CBC;
extern u32 lbl_801A6CC0;
extern u16 lbl_801A6CC4;
extern u16 lbl_801A6CC6;
extern u32 lbl_801A6CC8;
extern u32 lbl_801A6CCC;
extern u32 lbl_801A6CD0;
extern u32 lbl_801A6CD4;
extern u32 lbl_801A6CD8;
extern u32 lbl_801A6CE0;
extern u32 lbl_801A6CE4;
extern u8 lbl_801A6CE8;
extern u8 lbl_801A6CE9;
extern u8 lbl_801A6CEA;
extern u32 lbl_801A6CEC;
extern u32 lbl_801A6CF0;
extern AvSysRenderMode *lbl_801A6CF4;
extern u32 lbl_801A6CF8;
extern u32 lbl_801A6CFC;
extern AvSysState *lbl_801A6D00;
extern u32 lbl_801A6D08;
extern u32 lbl_801A6D0C;
extern u32 lbl_801A6D10;
extern u32 lbl_801A6D14;
extern u32 lbl_801A6D18;
extern u32 lbl_801A6D1C;
extern u32 lbl_801A6D20;
extern u32 lbl_801A6D24;
extern u32 *lbl_801A6D30;
extern const f32 lbl_801A7410;
extern const f32 lbl_801A7414;
extern const f64 lbl_801A7418;
extern const f32 lbl_801A7420;
extern const f32 lbl_801A7424;
extern u32 lbl_801A7918;

extern u32 VISetBlack(u32);
extern void VISetNextFrameBuffer(u32);
extern void VIFlush(void);
extern void VIWaitForRetrace(void);
extern s32 VIGetTvFormat(void);
extern s32 VIConfigure(void *);
extern u32 GXDrawDone(void);
extern void GXSetDrawDone(void);
extern u32 GXGetFifoPtrs(u32, u32 *, u32 *);
extern void GXSetGPFifo(void *);
extern u32 GXSetCPUFifo(void *);
extern void GXGetGPStatus(u8 *, u8 *, u8 *, u8 *, u8 *);
extern void GXClearVtxDesc(void);
extern u32 GXSetAlphaCompare(u32, u32, u32, u32, u32);
extern s32 GXAdjustForOverscan(void *, u32 *, s32, s32);
extern void *GXInit(u32, u32);
extern u32 GXSetDispCopyYScale(f32);
extern void GXInitFifoBase(void *, u32, u32);
extern void GXInitFifoPtrs(void *, u32, u32);
extern void GXSetDispCopyGamma(u32);
extern u32 fn_80034444(u32);
extern u32 fn_80032368(void);
extern u32 fn_80032360(void);
extern void fn_80031FF4(void);
extern void fn_80072B28(u32);
extern void fn_80035110(void *, u8);
extern u32 fn_8001BE6C(void);
extern u32 OSGetTick(void);
extern OSTime OSGetTime(void);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern void *OSGetArenaLo(void);
extern u32 OSGetArenaHi(void);
extern void OSSetArenaLo(u32);
extern void OSSetArenaHi(u32);
extern u32 LCEnable(void);
extern void DCFlushRange(void *, u32);
extern s32 fn_8003401C(u16);
extern u32 fn_80072BD0(u32);
extern u32 fn_80074918(u32, u32, u32);
extern void fn_800723F8(void);
extern void fn_800726C0(u32, struct Sig_fn_800726C0_fn_800726C0_Entry *);
extern u32 OSGetConsoleSimulatedMemSize(void);
extern u32 OSGetPhysicalMemSize(void);
extern void fn_80034ECC(u8, u8 *, u32, u8 *);
extern u32 fn_80037D40(u32, u32);
extern u32 fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_80071D30(void);
extern void fn_80074188(u32, u32, u32, u32);
extern void fn_8007423C(u32, u32, u32, u32);
extern void fn_800743C4(s32, u32);
extern void fn_800744F8(void *, u32);
extern void fn_80037C2C(AvSysPixelFmt, AvSysZFmt16);
extern void fn_80037D14(u8);
extern void lbl_8006D758(void);
extern void lbl_8006DCDC(void);
extern void fn_80071CB4(void);
extern void fn_80071CC0(void);
extern void fn_80071CE0(void);
extern void fn_80071CE8(void);
extern void fn_80071D0C(void);
extern void fn_80071D2C(void);
extern void fn_80071C64(void);
extern void fn_80071C8C(void);

void fn_8007001C(void);
s32 fn_80070068(void);
void fn_800700B4(void);
void fn_800700F4(void);
void fn_80070100(void);
void fn_80070A58(void);
u32 fn_80070CF8(u32 arg0);

/* avsystem.c's .data layout (lbl_8015A860..): vertex-descriptor tables + strings */
struct Sig_fn_800726C0_fn_800726C0_Entry lbl_8015A860[12] = {
    { 0x09, 1, 4, 0 }, { 0x0A, 0, 4, 0 }, { 0x0B, 1, 5, 0 }, { 0x0D, 1, 4, 0 },
    { 0x0E, 1, 4, 0 }, { 0x0F, 1, 4, 0 }, { 0x10, 1, 4, 0 }, { 0x11, 1, 4, 0 },
    { 0x12, 1, 4, 0 }, { 0x13, 1, 4, 0 }, { 0x14, 1, 4, 0 }, { 0xFF, 1, 4, 0 },
};
struct Sig_fn_800726C0_fn_800726C0_Entry fzgx_pool_fzgx_obj_lbl_8015A920[12] = {
    { 0x09, 1, 3, 13 }, { 0x0A, 0, 3, 14 }, { 0x0B, 1, 5, 0 }, { 0x0D, 1, 3, 13 },
    { 0x0E, 1, 3, 13 }, { 0x0F, 1, 3, 13 }, { 0x10, 1, 4, 0 }, { 0x11, 1, 4, 0 },
    { 0x12, 1, 4, 0 }, { 0x13, 1, 4, 0 }, { 0x14, 1, 4, 0 }, { 0xFF, 1, 4, 0 },
};
struct Sig_fn_800726C0_fn_800726C0_Entry fzgx_pool_fzgx_obj_lbl_8015A9E0[3] = {
    { 0x09, 1, 4, 0 }, { 0x0D, 1, 4, 0 }, { 0xFF, 1, 4, 0 },
};

void fn_8006FCB4(void) {
    VISetBlack(0);
    fn_80034444((u32)fn_800700F4);
    lbl_801A6CB4 = 0;
    GXDrawDone();
    lbl_801A6CD0 = 1;
    lbl_801A6CCC = -1;
    lbl_801A6CC6 = 0;
    lbl_801A6CC4 = 0;
    fn_80070100();
    fn_8007001C();
    lbl_801A6CD4 = 0;
}

void fn_8006FD1C(void) {
    u32 value_c;
    u32 value_8;

    lbl_801A6CB4 = 0;
    GXSetDrawDone();

    if ((lbl_801A6CE0 & 0x04) != 0) {
        GXGetFifoPtrs(fn_80032368(), &value_c, &value_8);
        fn_80032360();
        fn_80031FF4();
        fn_800700B4();
        GXSetGPFifo((void *)lbl_801A6D30[(u32)fn_80070068() + 5]);
    }

    GXGetFifoPtrs(fn_80032360(), &value_c, &value_8);
    lbl_801A6CD8 = value_8;
    fn_80072B28(1);
    fn_8007001C();
    fn_80035110((void *)lbl_801A6D30[0], 1);
    fn_80070100();
    lbl_801A6CCC = fn_8001BE6C();
    lbl_801A6CC8 = OSGetTick();
    lbl_801A6CC6 = 0;
    lbl_801A6CC4 = 0;
    lbl_801A6CB8 = OSGetTick();
    lbl_801A6CC0 = 0;
    lbl_801A6CBC = 0;
}

s32 fn_8006FDEC(void) {
    u32 value_c;
    u32 value_8;
    s32 ret;
    OSTime t0;

    ret = 0;
    t0 = OSGetTime();

    while (lbl_801A6CB4 == 0) {
        if (OSGetTime() - t0 > (OSTime)(__OSBusClock >> 2)) {
            OSReport(lbl_8015AA10, lbl_801A6CC6, lbl_801A6CC4, lbl_801A6CBC,
                     (lbl_801A6CC0 << 3) / ((__OSBusClock >> 2) / 125000));
            if (lbl_801A6CB0 != 0) {
                ((void (*)(void))lbl_801A6CB0)();
            }
            ret = 1;
            break;
        }
    }

    GXGetFifoPtrs(fn_80032360(), &value_c, &value_8);

    if (lbl_801A6CD8 > value_8) {
        lbl_801A6CD4 = lbl_801A6CE4 + value_8 - lbl_801A6CD8;
    } else {
        lbl_801A6CD4 = value_8 - lbl_801A6CD8;
    }

    return ret;
}

void fn_8006FEFC(void) {
    while (fn_8001BE6C() - lbl_801A6CCC < lbl_801A6CD0 - 1) {
    }

    VISetNextFrameBuffer(*lbl_801A6D30);
    VIFlush();
    VIWaitForRetrace();

    if ((lbl_801A6CE0 & 0x20) == 0) {
        lbl_801A6D30[0] = lbl_801A6D30[1 + lbl_801A6D30[4]];
        lbl_801A6D30[4] ^= 1;
    }

    lbl_801A6D30[3]++;
}

void fn_8006FF8C(s32 value) {
    if (value != 0 || ((value = lbl_801A6CE0) & 0x10) != 0) {
        lbl_801A6CE0 |= 0x20;
    } else {
        lbl_801A6CE0 = value & ~0x20;
    }
}

u32 fn_8006FFBC(void) {
    return lbl_801A6CD4;
}

void fn_8006FFC4(u32 arg0) {
    lbl_801A6CD0 = arg0;
}

u32 fn_8006FFCC(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6CB0;
    lbl_801A6CB0 = arg0;
    return v0;
}

u16 fn_8006FFDC(void) {
    u16 temp_r31;

    temp_r31 = lbl_801A6CC4;
    fn_8003401C(lbl_801A6CC4);
    (lbl_801A6CC4) += 1;
    return temp_r31;
}

void fn_8007001C(void) {
    fn_80074918(1, 3, 1);
    GXSetAlphaCompare(7, 0, 0, 7, 0);
    fn_80072BD0(1);
}

s32 fn_80070068(void) {
    void *v0;
    void *t0;
    t0 = (void *)fn_80032360();
    v0 = (void *)lbl_801A6D30[5];
    if (t0 != v0) {
        GXSetCPUFifo(v0);
        return 1;
    } else {
        GXSetCPUFifo((void *)lbl_801A6D30[6]);
        return 0;
    }
}

void fn_800700B4(void) {
    u8 v3;
    u8 v2;
    u8 v1;
    u8 v0;

    do {
        GXGetGPStatus(&v3, &v3, &v2, &v1, &v0);
    } while (v2 != 1);
}

void fn_800700F4(void) {
    lbl_801A6CB4 = 1;
}

void fn_80070100(void) {
    GXClearVtxDesc();
    fn_800723F8();
    fn_800726C0(0, lbl_8015A860);
    fn_800726C0(1, fzgx_pool_fzgx_obj_lbl_8015A920);
    fn_800726C0(7, fzgx_pool_fzgx_obj_lbl_8015A9E0);
}

void fn_80070158(s32 useLC) {
    struct { u32 value; } offset;
    struct { u32 value; } first;
    u32 base;
    u32 second;
    s32 i;
    if (useLC) {
        LCEnable();
        lbl_801A6CF0 = 0xE0000000;
        lbl_801A6CE0 |= 2;
    } else {
        lbl_801A6CF0 = fn_80070CF8(0x4000);
    }
    base = lbl_801A6CF0;
    first.value = base + 0x1C0;
    offset.value = 0;
    lbl_801A6CEC = offset.value;
    lbl_801A6D00 = (AvSysState *)(base + lbl_801A6CEC);
    lbl_801A6CEC += 0x1C0;
    first.value = base + lbl_801A6CEC;
    lbl_801A6CEC += 0x1C;
    lbl_801A6CEC = (((lbl_801A6CEC - 1) >> 5) + 1) << 5;
    second = base + lbl_801A6CEC;
    lbl_801A6CEC += 0xCA0;
    lbl_801A6D30 = (u32 *)first.value;
    lbl_801A6D38 = second;
    lbl_801A6CEC = (lbl_801A6CEC + 0x3FF) & ~0x3FF;
    for (i = 0; i < 16; i++) {
        u8 value;
        if (i < 14) {
            if (offset.value <= lbl_801A6CEC) value = 0xFF;
            else value = 0;
        } else value = 1;
        lbl_8019E140[i] = value;
        offset.value += 0x400;
    }
}

s32 fn_800702E4(u32 arg0) {
    s32 k;
    s32 i;
    s32 j;
    u32 n;
    u32 result;

    result = 0;
    for (i = 0; i < 16; i++) {
        if (lbl_8019E140[i] == 0) {
            n = arg0 - 1;
            j = i + 1;
            while (n != 0 && j < 16) {
                if (lbl_8019E140[j] != 0) {
                    break;
                }
                n--;
                j++;
            }
            if (n == 0) {
                result = lbl_801A6CF0 + (i << 10);
                for (k = 0; k < arg0; k++) {
                    lbl_8019E140[i + k] = arg0 - k;
                }
                break;
            }
        }
    }
    if (result == 0) {
        OSPanic(lbl_8015AA78, 158, (const char *)lbl_8015AA84);
    }
    return result;
}

s32 fn_8007048C(void) {
    s32 i;
    s32 count;

    count = 0;
    for (i = 0; i < 16; i++) {
        if (lbl_8019E140[i] != 0) {
            count++;
        }
    }
    return 16 - count;
}

void fn_80070538(void) {
    u32 temp_r4;
    u32 var_r3;
    u32 temp_r31;
    void *temp_r30;
    u32 var_r29;

    temp_r30 = OSGetArenaLo();
    var_r29 = OSGetArenaHi();
    lbl_801A6CF8 = 0;
    lbl_801A6CFC = 0;
    temp_r31 = OSGetConsoleSimulatedMemSize();
    if (((lbl_801A6CE9) != 0) || (temp_r31 <= 0x01800000U)) {
        var_r3 = 0x01800000;
    } else {
        var_r3 = OSGetPhysicalMemSize();
    }
    if (var_r3 > 0x01800000U) {
        temp_r4 = lbl_801A6CE0 | 8;
        lbl_801A6CE0 = temp_r4;
        if (lbl_801A6CE8 == 0) {
            lbl_801A6CF8 = var_r29;
            lbl_801A6CE0 = temp_r4 | 1;
            var_r29 -= temp_r31 + 0xFE800000;
            lbl_801A6CFC = var_r29;
        } else {
            lbl_801A6CFC = var_r29;
            lbl_801A6CF8 = var_r29 + (var_r3 - temp_r31);
        }
    }
    lbl_801A6621 = 0;
    OSSetArenaLo((u32)temp_r30);
    OSSetArenaHi(var_r29);
    fn_80070A58();
}

void fn_80070620(s32 arg0) {
    s32 temp_r3;

    temp_r3 = VIGetTvFormat();
    switch (temp_r3) {
    case 0:
        if (arg0 != 0) {
            lbl_801A6CF4 = (AvSysRenderMode *)lbl_8012B030;
        } else {
            lbl_801A6CF4 = (AvSysRenderMode *)lbl_8012AFB8;
        }
        break;
    case 1:
        lbl_801A6CF4 = (AvSysRenderMode *)lbl_8012B0A8;
        break;
    case 2:
        lbl_801A6CF4 = (AvSysRenderMode *)lbl_8012B06C;
        break;
    default:
        OSPanic(lbl_8015AA78, 0x157, (const char *)lbl_8015AB24);
        break;
    }
    GXAdjustForOverscan(lbl_801A6CF4, lbl_8019E150, 0, 0x10);
    lbl_801A6CF4 = (AvSysRenderMode *)lbl_8019E150;
    VIConfigure(lbl_8019E150);
    lbl_801A6CEA = 1;
}

void fn_80070704(s32 arg0) {
    struct { u8 *value; } table;

    if (arg0 == lbl_801A6CEA) {
        return;
    }
    lbl_801A6CEA = arg0;
    table.value = lbl_8012AFF4;
    if ((arg0 & 0xff) != 0) {
        table.value = lbl_8012AFB8;
    }
    fn_80034ECC(table.value[0x19], table.value + 0x1a, 1, table.value + 0x32);
}

void fn_8007075C(u32 arg0) {
    if ((s32)arg0 == 0) {
        return;
    }
    lbl_801A6CE0 = (lbl_801A6CE0 | 48);
}

#pragma opt_common_subs off
void fn_80070774(u32 arg0, u32 arg1, u32 arg2) {
    void *t5;
    u32 t4;
    struct { u32 value; } t2;
    struct { u32 value; } t0;
    struct { u32 value; } v2;
    struct { u32 value; } v1;
    u32 v0;
    u32 loc_8;

    v0 = (((((lbl_801A6CF4->unk_4 + 15) & 0xFFF0) * 528) << 1));
    t0.value = fn_80070CF8(v0);
    v1.value = ((v0 + 31) & ~0x1F);
    DCFlushRange((void *)t0.value, v1.value);
    if ((lbl_801A6CE0 & 0x10) == 0) {
        t2.value = fn_80070CF8(v0);
        v2.value = t2.value;
        DCFlushRange((void *)t2.value, v1.value);
    }
    t4 = fn_80070CF8(arg1);
    lbl_801A6CE4 = arg1;
    t5 = GXInit(t4, arg1);
    lbl_801A6D30[5] = (u32)t5;
    if ((s32)arg0 != 0) {
        lbl_801A6CE0 = (lbl_801A6CE0 | 4);
        lbl_801A6D30[6] = (u32)lbl_8019E18C;
        {
            u32 t6;
            t4 = fn_80070CF8(arg1);
            t6 = t4;
            GXInitFifoBase(lbl_8019E18C, t6, arg1);
            GXInitFifoPtrs(lbl_8019E18C, t6, t6);
        }
    }
    lbl_801A6D30[1] = t0.value;
    if ((lbl_801A6CE0 & 0x10) != 0) {
        lbl_801A6D30[2] = t0.value;
    } else {
        lbl_801A6D30[2] = v2.value;
    }
    lbl_801A6D30[0] = lbl_801A6D30[2];
    lbl_801A6D30[3] = 0;
    lbl_801A6D30[4] = 0;
    fn_80071D30();
    fn_80038EEC(0.0f, 0.0f, lbl_801A6CF4->unk_4, lbl_801A6CF4->unk_6, 0.0f, 1.0f);
    fn_80074188(0, 0, lbl_801A6CF4->unk_4, lbl_801A6CF4->unk_6);
    fn_8007423C(0, 0, lbl_801A6CF4->unk_4, lbl_801A6CF4->unk_6);
    fn_800743C4(lbl_801A6CF4->unk_4, lbl_801A6CF4->unk_8);
    GXSetDispCopyYScale((f32)lbl_801A6CF4->unk_8 / lbl_801A6CF4->unk_6);
    fn_80034ECC(lbl_801A6CF4->unk_19, lbl_801A6CF4->unk_1A, 1, lbl_801A6CF4->unk_32);
    if ((s32)arg2 != 0) {
        fn_80037C2C(AVSYS_GX_PF_RGBA6_Z24, AVSYS_GX_ZC_LINEAR);
        fn_80037D14(1);
        fn_80037D40(1, 0);
    } else {
        fn_80037C2C(AVSYS_GX_PF_RGB8_Z24, AVSYS_GX_ZC_LINEAR);
        fn_80037D14(0);
    }
    loc_8 = lbl_801A7918;
    fn_800744F8(&loc_8, 0xFFFFFF);
    fn_80035110((void *)lbl_801A6D30[1], 1);
    fn_80035110((void *)lbl_801A6D30[2], 0);
    fn_80035110((void *)lbl_801A6D30[1], 0);
    GXSetDispCopyGamma(0);
    VIConfigure(lbl_801A6CF4);
    VISetNextFrameBuffer(t0.value);
    VIFlush();
    VIWaitForRetrace();
    if ((lbl_801A6CF4->unk_0 & 0x1) != 0) {
        VIWaitForRetrace();
    }
}
#pragma opt_common_subs reset

void fn_80070A58(void) {
    lbl_801A6D00->unk_198 = lbl_801A7410;
    lbl_801A6D00->unk_19c = lbl_801A7414;
    lbl_801A6D00->unk_1a0 = lbl_801A7420;
    lbl_801A6D00->unk_1a4 = lbl_801A7424;
    lbl_801A6D00->unk_1a8 = -1;
    lbl_801A6D00->unk_1ac = 0;
    lbl_801A6D00->unk_1ad = 1;
    lbl_801A6D00->unk_1ae = 1;
    lbl_801A6D00->unk_1af = 0;
}

