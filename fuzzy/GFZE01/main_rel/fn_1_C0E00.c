/* Non-matching: best partial attempt (89.50% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/os/OSTime.h"
#include "rel/main_rel/memcard.h"

typedef struct {
    u8 pad_0[0x14];
    s8 type;
    s16 first;
    s16 second;
    s16 third;
    s16 fourth;
} Sig_fn_1_C0E00_Fn1C0510Obj;

struct fn_1_C0E00_Arg2 {
    u8 pad_00;
    u8 type;
    u8 code[5];
    u8 pad_08[0x1c];
    u32 unk_24;
    u8 pad_28[4];
    u32 unk_2C;
};

struct fn_1_C0E00_lbl_801A6410 {
    u32 unk_0;
};

typedef struct {
    u32 pad_00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    u32 pad_24[1];
    struct {
        u8 type;
        u8 pad[7];
        char *name0;
        u32 unk_C;
        u8 code;
        char *name1;
        u8 pad_18[0xc];
    } desc;
    char path[0x5c];
    char buf1[0x100];
    char buf2[0x100];
} C0E00_Frame;

extern struct fn_1_C0E00_lbl_801A6410 lbl_801A6410;
extern u32 lbl_801A66B4;
extern u32 fn_1_4630(u32, u32, u32, u32);
extern int fn_1_45730(void *, void *);
extern int fn_1_458A0(void *, void *, u32, u32);
extern int fn_1_45850(void *);
extern f32 lbl_1_rodata_4D1C[217];
extern u32 fn_1_C1CFC(u32, u32, u32, f32);
extern void fn_1_C23CC(void *, u32, u32, u32, u32, u32, u32, u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern void fn_1_AA6D8(u32, u32, void *);
extern u32 fn_80008BA8(void *, u32, u32);
extern void fn_80008BEC(void *, int, u32);
extern void OSTicksToCalendarTime(OSTime, void *);
extern int sprintf(char *, const char *, ...);
extern char *strncpy(char *, const char *, u32);
extern void OSReport(const char *, ...);

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction on
static inline char * fn_1_C0E00_read_pointer(C0E00_Frame * owner) { return owner->path; }
#pragma opt_dead_assignments off
u32 fn_1_C0E00(Sig_fn_1_C0E00_Fn1C0510Obj *arg0, u32 unused, struct fn_1_C0E00_Arg2 *arg2) {
    s32 tmp_OSGetTime_2;
    char * fzgx_live;
    u32 fzgx_value;
    s32 tmp_OSGetTime;
    C0E00_Frame w;
    u8 *base;
    u32 c;
    u8 *buf;
    u32 code;
    u32 tick_2_2;
    u32 i;
    u8 *data;
    u32 *ip;
    u32 *tbl;
    u32 tmp_OSGetTime_2_2;
    OSTime t;
    OSTime tb;
    u32 res;
    u32 lab_t2;
    const char * lab_t1;

    base = (u8 *)&lbl_1_bss_716C0 + 0x10000;
    data = (u8 *)&lbl_1_data_35AC8;
    code = 0x6000;
    if (arg2->unk_24 >= 0x6000) {
        code = arg2->unk_24;
    }
    buf = (u8 *)fn_1_4630(lbl_801A6410.unk_0, code, (u32)(data + 0x6cf0), 0x320c);
    *(u32 *)(base - 0x7340) = (u32)buf;
    OSTicksToCalendarTime(OSGetTime(), &w);

    if (arg2->type == 2) {
        sprintf(w.buf1, (char *)(data + 0x75e0), w.f14 % 100, w.f10 + 1, w.f0C, w.f08, w.f04);
        tmp_OSGetTime = OSGetTime();
        t = tmp_OSGetTime;
        tmp_OSGetTime_2 = OSGetTime();
        tb = tmp_OSGetTime_2;
        sprintf(w.buf2, (char *)(data + 0x75fc), (u32)tb, (u32)t);
        ip = &lbl_801A66B4;
        code = 0x3ea8;
        tbl = (u32 *)(data + 0xd4);
        if (fn_1_45730((void *)((*ip)[tbl]), fn_1_C0E00_read_pointer(&w)) != 0) {
            fn_1_458A0(fn_1_C0E00_read_pointer(&w), buf + 0x60, 0x2000, 0);
            fn_1_45850(fn_1_C0E00_read_pointer(&w));
        }
    } else if (arg2->type == 4) {
        sprintf(w.buf1, (char *)(data + 0x75e0), w.f14 % 100, w.f10 + 1, w.f0C, w.f08, w.f04);
        code = 0;
        for (i = 0; i < 5; i++) {
            c = ((i)[arg2->code]);
            if (c >= 0x41 && c <= 0x46) {
                c -= 0x37;
            } else {
                c -= 0x30;
            }
            code += c << ((4 - i) * 4);
        }
        i = OSGetTime();
        tmp_OSGetTime = i;
        tmp_OSGetTime_2_2 = tmp_OSGetTime;
        t = tmp_OSGetTime_2_2;
        sprintf(w.buf2, (char *)(data + 0x7608), code, code, (u32)(t >> 2), (OSGetTick()));
        ip = &lbl_801A66B4;
        tbl = (u32 *)(data + 0x94);
        if (fn_1_45730((void *)((*ip)[tbl]), fn_1_C0E00_read_pointer(&w)) != 0) {
            fn_1_458A0(fn_1_C0E00_read_pointer(&w), buf + 0x60, 0x2000, 0);
            fn_1_45850(fn_1_C0E00_read_pointer(&w));
        }
        res = fn_1_C1CFC(arg2->unk_2C, 0x40, 0x40, ((0)[lbl_1_rodata_4D1C]));
        fn_1_C23CC(buf + 0x60, 0x60, 0x20, res, 0x20, 0x20, 0x40, 0);
        fn_80008BA8(buf + 0x1860, res, 0x800);
        return fn_1_46B4(lbl_801A6410.unk_0, res, (u32)(data + 0x6cf0), 0x322e);
    } else {
        sprintf(w.buf1, (char *)(data + 0x75e0), w.f14 % 100, w.f10 + 1, w.f0C, w.f08, w.f04);
        lab_t2 = 8;
        strncpy(w.buf2, (char *)arg2->code, lab_t2);
        w.buf2[8] = 0;
        code -= 0x2060;
        tick_2_2 = OSGetTick();
        tmp_OSGetTime_2_2 = OSGetTime();
        t = tmp_OSGetTime_2_2;
        lab_t1 = (char *)(data + 0x7624);
        fzgx_live = w.buf2;
        sprintf(fzgx_live, lab_t1, fzgx_live, (u32)(t >> 12), tick_2_2);
        ip = &lbl_801A66B4;
        tbl = (u32 *)(data + 0x114);
        if (fn_1_45730((void *)((*ip)[tbl]), fn_1_C0E00_read_pointer(&w)) != 0) {
            fn_1_458A0(fn_1_C0E00_read_pointer(&w), buf + 0x60, 0x2000, 0);
            fn_1_45850(fn_1_C0E00_read_pointer(&w));
        }
    }

    lab_t2 = 0x20;
    strncpy((char *)(buf + 0x24), w.buf1, lab_t2);
    sprintf((char *)(base - 0x6b2c), (char *)(data + 0x7318), w.buf2);
    *(u32 *)(base - 0x6b0c) = arg2->type;
    *(u32 *)(base - 0x6b08) = (code + 0x405f) & 0x1fff;
    if (arg2->unk_2C != 0) {
        OSReport((char *)(data + 0x7630), code);
        return fn_80008BA8(buf + 0x2060, arg2->unk_2C, code);
    }
    fn_80008BEC(&w.desc, 0, 0x24);
    w.desc.type = arg2->type;
    w.desc.name0 = w.buf1;
    fzgx_value = *(u32 *)(base - 0x7340);
    w.desc.unk_C = fzgx_value;
    w.desc.code = code;
    w.desc.name1 = (w.buf2);
    fn_1_AA6D8(0, (u32)(u8)arg0->first, &w.desc);
    return (u32)data;
}
#pragma opt_dead_assignments reset

#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

#pragma opt_propagation reset
