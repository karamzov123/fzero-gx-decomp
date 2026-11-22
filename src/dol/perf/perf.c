#include "types.h"

typedef struct PerfColor {
    u8 r, g, b, a;
} PerfColor;

typedef struct PerfEvent {
    u32 unk00;
    s32 unk04;
    s32 unk08;
    PerfColor unk0C;
} PerfEvent;

typedef struct PerfEntry {
    u8 unk00;
    u8 pad01[3];
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u8 pad40[0x70];
} PerfEntry;

typedef struct PerfFrame {
    PerfEntry *entries;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
} PerfFrame;

typedef struct PerfMemReg {
    u8 pad_0[0x32];
    u16 unk_32;
    u16 unk_34;
    u16 unk_36;
    u16 unk_38;
    u16 unk_3A;
    u16 unk_3C;
    u16 unk_3E;
    u16 unk_40;
    u16 unk_42;
    u16 unk_44;
    u16 unk_46;
    u16 unk_48;
    u16 unk_4A;
    u16 unk_4C;
    u16 unk_4E;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
    u16 unk_56;
    u16 unk_58;
} PerfMemReg;

typedef u32 (*PerfAllocFn)(u32);

extern PerfMemReg *__memReg;
extern const char *lbl_801A6580;
/* Shared with token/timer interrupt handlers; written then re-read. */
extern volatile s32 lbl_801A6584;
/* Pending token is sampled separately for its index and generation. */
extern volatile u32 lbl_801A6588;
/* Frame counter shared with the timer handler. */
extern volatile u8 lbl_801A6C30;
extern PerfAllocFn lbl_801A6C34;
extern u32 lbl_801A6C38;
extern void (*lbl_801A6C3C)(u32);
/* Shared with token/timer handlers; counter rereads are observable. */
extern volatile u32 lbl_801A6C40;
extern u32 lbl_801A6C44;
extern PerfEvent *lbl_801A6C48;
extern PerfFrame *lbl_801A6C4C;
extern u32 lbl_801A6C50;
extern u32 lbl_801A6C54;
extern u32 lbl_801A6C58[2];
extern const PerfColor lbl_801A71B8;
extern char lbl_8012B5F8[];
extern char lbl_8012B624[];
extern u8 lbl_80178BF0[40];

extern void GXReadXfRasMetric(u32 *, u32 *, u32 *, u32 *);
extern void GXClearGPMetric(void);
extern void PPCMtpmc1(u32 value);
extern void PPCMtpmc2(u32 value);
extern void PPCMtpmc3(u32 value);
extern void PPCMtpmc4(u32 value);
extern void PPCMtmmcr0(u32 value);
extern void PPCMtmmcr1(u32 value);
extern u32 fn_8000A020(void);
extern u32 fn_8000A040(void);
extern u32 fn_8000A050(void);
extern void OSRegisterVersion(const char *);
extern void fn_80034378(void (*func)(u32));
extern s32 fn_8003401C(u32);
extern void fn_80039B38(void);
extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 level);
extern void OSReport(const char *, ...);
extern void *memcpy(void *, const void *, u32);
extern u64 OSGetTime(void);
extern void OSSetPeriodicAlarm(void *, u64, u32, u32, void (*)(void));
extern void OSCancelAlarm(void *);
extern void fn_8003E9EC(u32 arg0);

void fn_8003D588(void *arg0, u32 arg1);
void fn_8003D698(u32 arg0);
void fn_8003E13C(void);
void fn_8003E284(void);

#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("PERF : Unknown event type for ID %d - possibly out of memory\n");
    OSReport("PERF : event is still open for CPU!\n");
}
#pragma section code_type ".text"

void fn_8003D4E0(void) {
    __memReg->unk_32 = 0;
    __memReg->unk_34 = 0;
    __memReg->unk_36 = 0;
    __memReg->unk_38 = 0;
    __memReg->unk_3C = 0;
    __memReg->unk_3A = 0;
    __memReg->unk_40 = 0;
    __memReg->unk_3E = 0;
    __memReg->unk_44 = 0;
    __memReg->unk_42 = 0;
    __memReg->unk_48 = 0;
    __memReg->unk_46 = 0;
    __memReg->unk_4C = 0;
    __memReg->unk_4A = 0;
    __memReg->unk_50 = 0;
    __memReg->unk_4E = 0;
    __memReg->unk_54 = 0;
    __memReg->unk_52 = 0;
    __memReg->unk_58 = 0;
    __memReg->unk_56 = 0;
}

#pragma opt_propagation off
void fn_8003D588(void *arg0, u32 arg1) {
    u32 v0 = (u32)arg0 + (arg1 << 2);
    u16 *s;

    GXReadXfRasMetric((u32 *)(v0 + 0x90), (u32 *)(v0 + 0x98), (u32 *)(v0 + 0xA0), (u32 *)(v0 + 0xA8));
    s = (u16 *)__memReg;
    {
        u16 hi = (*((25) + s));
        u16 lo = (*((26) + s));
        *(u32 *)(v0 + 0x40) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((27) + s));
        u16 lo = (*((28) + s));
        *(u32 *)(v0 + 0x48) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((29) + s));
        u16 lo = (*((30) + s));
        *(u32 *)(v0 + 0x50) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((31) + s));
        u16 lo = (*((32) + s));
        *(u32 *)(v0 + 0x58) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((33) + s));
        u16 lo = (*((34) + s));
        *(u32 *)(v0 + 0x60) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((35) + s));
        u16 lo = (*((36) + s));
        *(u32 *)(v0 + 0x68) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((37) + s));
        u16 lo = (*((38) + s));
        *(u32 *)(v0 + 0x70) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((39) + s));
        u16 lo = (*((40) + s));
        *(u32 *)(v0 + 0x78) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    *(u32 *)(v0 + 0x80) = (u32)(*((42) + (s))) | ((u32)(*((41) + (s))) << 16);
    s = (u16 *)__memReg;
    *(u32 *)(v0 + 0x88) = ((u32)(*((43) + (s))) << 16) | (u32)(*((44) + (s)));
}
#pragma opt_propagation reset

void fn_8003D690(void (*arg0)(u32)) {
    lbl_801A6C3C = arg0;
}

void fn_8003D698(u32 arg0) {
    s32 idx;
    s32 cur;

    if (((arg0 & 0xFFFF) < 0xe000) ||
        (((s32)((arg0 & 0xFFFF) >> 8) & 0xf) != lbl_801A6C30) || (s32)lbl_801A6C40 == 0) {
        if (lbl_801A6C3C != 0) {
            lbl_801A6C3C(arg0);
        }
        return;
    }
    if ((arg0 & 0xFFFF) >= 0xf000) {
        if (lbl_801A6588 == 0xffff) {
            fn_8003E284();
            fn_8003E13C();
            return;
        }
        idx = (u8)(arg0 & 0xFFFF);
        if ((u8)lbl_801A6588 != idx) {
            idx = (u8)lbl_801A6588;
        }
        lbl_801A6C4C[lbl_801A6C44].entries[idx].unk10 = fn_8000A050();
        lbl_801A6C4C[lbl_801A6C44].entries[idx].unk24 = fn_8000A040();
        lbl_801A6C4C[lbl_801A6C44].entries[idx].unk34 = fn_8000A020();
        fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[idx], 1);
        if (lbl_801A6584 >= 0) {
            fn_8003E284();
        }
        lbl_801A6588 = 0xffff;
        fn_8003E13C();
    } else {
        if (lbl_801A6588 < 0xffff) {
            cur = (u8)lbl_801A6588;
            lbl_801A6C4C[lbl_801A6C44].entries[cur].unk10 = fn_8000A050();
            lbl_801A6C4C[lbl_801A6C44].entries[cur].unk24 = fn_8000A040();
            lbl_801A6C4C[lbl_801A6C44].entries[cur].unk34 = fn_8000A020();
            fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[cur], 1);
        } else {
            fn_8003E284();
        }
        cur = (u8)(arg0 & 0xFFFF);
        lbl_801A6C4C[lbl_801A6C44].entries[cur].unk20 = fn_8000A040();
        lbl_801A6C4C[lbl_801A6C44].entries[cur].unk30 = fn_8000A020();
        lbl_801A6C4C[lbl_801A6C44].entries[cur].unk0C =
            lbl_801A6C4C[lbl_801A6C44].entries[cur].unk1C = fn_8000A050();
        fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[cur], 0);
        lbl_801A6588 = (u16)arg0;
    }
}

u32 fn_8003D918(u32 arg0, u32 arg1, u32 arg2, PerfAllocFn arg3, u32 arg4, u32 arg5) {
    u32 size;
    u32 i;

    OSRegisterVersion(lbl_801A6580);
    lbl_801A6C34 = arg3;
    lbl_801A6C38 = arg4;
    lbl_801A6C58[0] = arg1;
    lbl_801A6C54 = arg2;
    lbl_801A6C50 = arg0;
    size = arg1 * 16 + arg1 * (arg0 * 0xb0);
    size += arg2 * 16;
    lbl_801A6C4C = (PerfFrame *)arg3(arg1 * 16);
    for (i = 0; i < lbl_801A6C58[0]; i++) {
        lbl_801A6C4C[i].entries = (PerfEntry *)lbl_801A6C34(arg0 * 0xb0);
        lbl_801A6C4C[i].unk04 = 0;
    }
    lbl_801A6C48 = (PerfEvent *)lbl_801A6C34(arg2 * 16);
    for (i = 0; i < arg2; i++) {
        lbl_801A6C48[i].unk00 = 0;
        lbl_801A6C48[i].unk08 = -1;
    }
    fn_8003E9EC(arg5);
    fn_80034378(fn_8003D698);
    fn_80039B38();
    return size;
}

void fn_8003DB54(u8 arg0, u32 arg1, s32 arg2) {
    PerfColor c = lbl_801A71B8;

    lbl_801A6C48[arg0].unk00 = arg1;
    lbl_801A6C48[arg0].unk04 = arg2;
    lbl_801A6C48[arg0].unk08 = -1;
    lbl_801A6C48[arg0].unk0C = c;
}

void fn_8003DBA0(void) {
    u32 level;

    level = OSDisableInterrupts();
    lbl_801A6C40 = 0;
    lbl_801A6588 = 0xffff;
    fn_80034378(fn_8003D698);
    lbl_801A6C4C[lbl_801A6C44].unk04 = 0;
    fn_8003D4E0();
    GXClearGPMetric();
    PPCMtpmc1(0);
    PPCMtpmc2(0);
    PPCMtpmc3(0);
    PPCMtpmc4(0);
    PPCMtmmcr0(0x8b);
    PPCMtmmcr1(0x78400000);
    fn_8003E13C();
    OSRestoreInterrupts(level);
}

void fn_8003DC50(void) {
    u32 interrupts;
    u32 offset;
    u32 count;

    interrupts = OSDisableInterrupts();
    fn_8003E284();
    fn_80034378(lbl_801A6C3C);
    lbl_801A6C4C[lbl_801A6C44].unk08 = fn_8000A050();
    lbl_801A6C4C[lbl_801A6C44].unk04 = lbl_801A6C40;
    lbl_801A6C4C[lbl_801A6C44].unk0C = fn_8000A040();
    lbl_801A6C40 = offset = 0;
    count = 0;
    lbl_801A6C44 = (lbl_801A6C44 + 1) % lbl_801A6C58[0];
    while (count < lbl_801A6C54) {
        *(u32 *)((u8 *)lbl_801A6C48 + offset + 8) = -1;
        offset += 16;
        count++;
    }
    lbl_801A6C30++;
    if (lbl_801A6C30 >= 16) {
        lbl_801A6C30 = 0;
    }
    OSRestoreInterrupts(interrupts);
}

#pragma opt_propagation off
void fn_8003DD48(u8 arg0) {
    u32 t7;
    u32 v1;
    u32 v0;
    s32 *v2;
    struct { u32 value; } v6;
    v1 = OSDisableInterrupts();
    v0 = (arg0 * 16) & 0xFF0;
    v2 = (s32 *)((u8 *)lbl_801A6C48 + v0);
    if (*(v2 += 2) < 0) {
        if (lbl_801A6C40 >= lbl_801A6C50 - 1) {
            lbl_801A6C40 = lbl_801A6C50 - 1;
            v6.value = lbl_801A6C40;
        } else {
            v6.value = lbl_801A6C40;
            lbl_801A6C40 = v6.value + 1;
        }
        *v2 = v6.value;
        lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk00 = arg0;
        lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk14 = 0;
        {
            PerfEvent *entry;
            entry = (PerfEvent *)((u8 *)lbl_801A6C48 + v0);
            switch (entry->unk04) {
            case 2:
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk20 = 0;
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk30 = 0;
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk0C = 0;
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk10 = 0;
                fn_8003401C((u16)v6.value + 0x10000 + ((lbl_801A6C30 << 8) & 0xFF00) - 0x2000);
                break;
            case 1:
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk0C = 0;
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk10 = 0;
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk20 = fn_8000A040();
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk30 = fn_8000A020();
                fn_8003401C((u16)v6.value + 0x10000 + ((lbl_801A6C30 << 8) & 0xFF00) - 0x2000);
            case 0:
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk28 = fn_8000A040();
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk38 = fn_8000A020();
                t7 = fn_8000A050();
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk04 = t7;
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk18 = t7;
                lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk08 = 0;
                break;
            default:
                OSReport("PERF : Unknown event type for ID %d - possibly out of memory\n", (u8)arg0);
            }
        }
    } else {
        OSReport("PERF : event is still open for CPU!\n");
    }
    OSRestoreInterrupts(v1);
}

void fn_8003DFF8(s32 arg0) {
    s32 offset;
    u32 level;
    s32 id;
    PerfEvent *entry;

    level = OSDisableInterrupts();
    offset = (arg0 * 0x10) & 0xFF0;
    entry = (PerfEvent *)(((offset) + ((u8 *)lbl_801A6C48)));
    id = entry->unk08;
    if (id < 0) {
        OSReport(lbl_8012B5F8);
        OSRestoreInterrupts(level);
        return;
    }
    switch (entry->unk04) {
    case 2:
        fn_8003401C((((u16)id + 0x10000 + (((lbl_801A6C30 << 8) & 0xFF00))) - 0x1000));
        break;
    case 1:
        fn_8003401C((((u16)id + 0x10000 + (((lbl_801A6C30 << 8) & 0xFF00))) - 0x1000));
        /* fallthrough */
    case 0:
        lbl_801A6C4C[lbl_801A6C44].entries[id].unk08 = fn_8000A050();
        lbl_801A6C4C[lbl_801A6C44].entries[id].unk2C = fn_8000A040();
        lbl_801A6C4C[lbl_801A6C44].entries[id].unk3C = fn_8000A020();
        break;
    }
    {
        s32 v = -1;
        entry = (PerfEvent *)((u8 *)lbl_801A6C48 + offset);
        entry->unk08 = v;
    }
    OSRestoreInterrupts(level);
}
#pragma opt_propagation reset

void fn_8003E13C(void) {
    u32 max = lbl_801A6C50 - 1;
    u32 idx;

    if (lbl_801A6C40 >= max) {
        lbl_801A6C40 = max;
        idx = lbl_801A6C40;
    } else {
        idx = lbl_801A6C40;
        lbl_801A6C40 = idx + 1;
    }
    lbl_801A6584 = idx;

    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk00 = 0xff;
    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk14 = 0;
    fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584], 0);
    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk0C = fn_8000A050();
    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk10 = 0;
    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk20 = fn_8000A040();
    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk30 = fn_8000A020();
}

void fn_8003E284(void) {
    if (lbl_801A6584 >= 0) {
        lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk10 = fn_8000A050();
        fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584], 1);
        lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk24 = fn_8000A040();
        lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk34 = fn_8000A020();
    }
    lbl_801A6584 = -1;
}

void fn_8003E344(void) {
    u32 v0;
    u32 v16;
    struct { u32 source; } v18;
    if ((s32)lbl_801A6C40 != 0) {
        if (lbl_801A6588 < 65535) {
            v18.source = (u8)lbl_801A6588;
            v0 = lbl_801A6588;
            if ((s32)((v0 >> 8) & 0xF) != lbl_801A6C30) {
                if (lbl_801A6584 >= 0) {
                    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk10 = fn_8000A050();
                    fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584], 1);
                    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk24 = fn_8000A040();
                    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk34 = fn_8000A020();
                }
                lbl_801A6584 = -1;
                v0 = lbl_801A6C50 - 1;
                if (lbl_801A6C40 >= v0) {
                    lbl_801A6C40 = v0;
                    v0 = lbl_801A6C40;
                } else {
                    v0 = lbl_801A6C40;
                    lbl_801A6C40 = v0 + 1;
                }
                lbl_801A6584 = v0;
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk00 = 255;
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk14 = 0;
                fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584], 0);
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk0C = fn_8000A050();
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk10 = 0;
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk20 = fn_8000A040();
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk30 = fn_8000A020();
            } else {
                v0 = lbl_801A6C50 - 1;
                if (lbl_801A6C40 >= v0) {
                    lbl_801A6C40 = v0;
                    v16 = lbl_801A6C40;
                } else {
                    v16 = lbl_801A6C40;
                    lbl_801A6C40 = v16 + 1;
                }
                memcpy(&lbl_801A6C4C[lbl_801A6C44].entries[v16],
                       &lbl_801A6C4C[lbl_801A6C44].entries[v18.source], 176);
                lbl_801A6C4C[lbl_801A6C44].entries[v16].unk10 = fn_8000A050();
                lbl_801A6C4C[lbl_801A6C44].entries[v16].unk24 = fn_8000A040();
                lbl_801A6C4C[lbl_801A6C44].entries[v16].unk34 = fn_8000A020();
                fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[v16], 1);
                lbl_801A6C4C[lbl_801A6C44].entries[v16].unk00 = 255;
                lbl_801A6C4C[lbl_801A6C44].entries[v18.source].unk0C = fn_8000A050();
                lbl_801A6C4C[lbl_801A6C44].entries[v18.source].unk20 = fn_8000A040();
                lbl_801A6C4C[lbl_801A6C44].entries[v18.source].unk30 = fn_8000A020();
                fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[v18.source], 0);
                lbl_801A6C4C[lbl_801A6C44].entries[v18.source].unk14 = 1;
                lbl_801A6584 = -1;
            }
        } else {
            if (lbl_801A6584 < 0) {
                OSReport(lbl_8012B624);
            } else {
                if (lbl_801A6584 >= 0) {
                    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk10 = fn_8000A050();
                    fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584], 1);
                    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk24 = fn_8000A040();
                    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk34 = fn_8000A020();
                }
                lbl_801A6584 = -1;
                v0 = lbl_801A6C50 - 1;
                if (lbl_801A6C40 >= v0) {
                    lbl_801A6C40 = v0;
                    v0 = lbl_801A6C40;
                } else {
                    v0 = lbl_801A6C40;
                    lbl_801A6C40 = v0 + 1;
                }
                lbl_801A6584 = v0;
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk00 = 255;
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk14 = 0;
                fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584], 0);
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk0C = fn_8000A050();
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk10 = 0;
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk20 = fn_8000A040();
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk30 = fn_8000A020();
            }
        }
    }
}

void fn_8003E8CC(f32 arg0) {
    u32 v0;
    u32 period;

    v0 = *(u32 *)0x800000F8;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    period = (arg0 * ((v0 >> 2) / 1000));
    OSSetPeriodicAlarm(lbl_80178BF0, OSGetTime(), 0, period, fn_8003E344);
}

void fn_8003E958(void) {
    u32 level;

    level = OSDisableInterrupts();
    if (lbl_801A6584 >= 0) {
        lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk10 = fn_8000A050();
        fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584], 1);
    }
    OSCancelAlarm(lbl_80178BF0);
    OSRestoreInterrupts(level);
}
