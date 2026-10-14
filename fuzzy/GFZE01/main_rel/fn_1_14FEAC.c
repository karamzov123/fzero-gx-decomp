/* Non-matching: best partial attempt (69.28% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

typedef s32 (*Sig_fn_8007E96C_fn_8007E96C_Compare)(s32 *, s32 *);

struct fn_1_14FEAC_slot {
    s16 count_0;
    s16 unk_4;
    u32 unk_8;
    char unk_C[0x3C];
};

struct fn_1_14FEAC_tbl {
    u32 unk_0;
    u32 unk_4[74];
};

extern u8 lbl_1_bss_8E6B0[0x134];
extern struct fn_1_14FEAC_slot lbl_1_bss_8E7E4[];
extern f32 lbl_1_rodata_99D8[75];
extern s32 fn_1_14FD6C(s32 *, s32 *);
extern u32 * fn_8007E96C(u32, u32, u32, u32, Sig_fn_8007E96C_fn_8007E96C_Compare);
extern char * fn_80083DB0(char *, const char *);
extern char * fn_800839D8(char *, const char *);
extern int sprintf(char *, const char *, ...);
extern u32 fn_1_14EBF8(void *, void *, s32);
extern char * fn_1_14EA74(void *, char *, s32);
extern s32 fn_1_14ED00(void *, void *, s32);

void * fn_1_14FEAC(s32 arg0, s32 arg1, s32 arg2, char *arg3, s32 arg4) {
    s32 key;
    char namebuf[0x80];
    char tmpbuf[0x40];
    char buf0[0x40];
    char buf1[0x40];
    char buf2[0x40];
    char outs[3][2][0x20];
    struct fn_1_14FEAC_tbl tbl;
    u8 *data;
    struct fn_1_14FEAC_slot *slots;
    struct fn_1_14FEAC_slot *sp;
    u32 v1;
    u32 v22;
    u32 extra;
    s16 idx;
    s16 i;
    s16 j;
    s16 k;
    s16 n;
    char *p;
    char *q;
    char *p0;
    char *p1;
    char *p2;
    char *s1;
    char *s2;
    u32 *t0;

    data = &lbl_1_data_43E78[0];
    slots = (struct fn_1_14FEAC_slot *)&lbl_1_bss_8E7E4;
    v1 = ((s32)(s16)arg0 << 10) | (((s32)(s16)arg1 - 0x19) << 5) | ((s32)(s16)arg2 - 0x32);
    key = (s16)v1;
    t0 = fn_8007E96C((u32)&key, (u32)lbl_1_bss_8E6B0, 0x4d, 4, fn_1_14FD6C);
    if (t0 == 0) {
        idx = -1;
    } else {
        idx = (s16)((s32)t0 - (s32)(u32)lbl_1_bss_8E6B0) / 4;
    }
    if (idx != -1) {
        fn_80083DB0(arg3, (const char *)(*(u32 *)(data + 0x9a0 + (idx * 0x18) + ((s16)arg4 * 4))));
        return arg3;
    }
    for (k = 0; (s16)k < 0x14; k++) {
        sp = slots + k;
        if (sp->unk_8 == v1 && (s16)arg4 == sp->unk_4) {
            fn_80083DB0(arg3, slots[k].unk_C);
            return arg3;
        }
    }
    tbl = *(struct fn_1_14FEAC_tbl *)&lbl_1_rodata_99D8;
    v22 = tbl.unk_4[(s16)arg2];
    if (v22 & 0x10000000) {
        fn_1_14EBF8((void *)arg0, buf0, arg4);
    } else {
        fn_1_14EA74((void *)arg0, buf0, arg4);
    }
    if (v22 & 0x20000000) {
        fn_1_14EBF8((void *)arg2, buf1, arg4);
    } else {
        fn_1_14EA74((void *)arg2, buf1, arg4);
    }
    if (v22 & 0x08000000) {
        fn_1_14EBF8((void *)arg1, buf2, arg4);
    } else {
        fn_1_14EA74((void *)arg1, buf2, arg4);
    }
    p0 = &outs[0][0][0];
    p1 = &outs[1][0][0];
    p2 = &outs[2][0][0];
    extra = 0;
    for (i = 0; (s16)i < 2; i++) {
        fn_80083DB0(tmpbuf, buf0);
        p = tmpbuf;
        j = 0;
        for (;;) {
            q = fn_800839D8(p, (const char *)(data + 0x2428));
            if (q == 0) {
                fn_80083DB0(p0, buf0);
                break;
            }
            if (j == i) {
                fn_80083DB0(p0, q);
                break;
            }
            p = 0;
            j++;
        }
        fn_80083DB0(tmpbuf, buf1);
        p = tmpbuf;
        j = 0;
        for (;;) {
            q = fn_800839D8(p, (const char *)(data + 0x2428));
            if (q == 0) {
                fn_80083DB0(p1, buf1);
                break;
            }
            if (j == i) {
                fn_80083DB0(p1, q);
                break;
            }
            p = 0;
            j++;
        }
        fn_80083DB0(tmpbuf, buf2);
        p = tmpbuf;
        j = 0;
        for (;;) {
            q = fn_800839D8(p, (const char *)(data + 0x2428));
            if (q == 0) {
                fn_80083DB0(p2, buf2);
                break;
            }
            if (j == i) {
                fn_80083DB0(p2, q);
                break;
            }
            p = 0;
            j++;
        }
        p0 += 0x20;
        p1 += 0x20;
        p2 += 0x20;
    }
    s1 = (v22 & 0x80000000) ? &outs[1][0][0] : &outs[0][0][0];
    s2 = (v22 & 0x80000000) ? &outs[0][1][0] : &outs[1][1][0];
    if (v22 & 0x40000000) {
        extra = (u32)fn_1_14ED00((void *)arg2, buf1, arg4);
    }
    sprintf(arg3, (const char *)(data + 0x24e0), s1, s2, extra);
    fn_80083DB0(arg3, slots[slots->count_0].unk_C);
    slots[slots->count_0].unk_8 = v1;
    slots[slots->count_0].unk_4 = (s16)arg4;
    n = slots->count_0 + 1;
    if (n > 0x13) {
        n = 0;
    } else if (n < 0) {
        n = 0x13;
    }
    slots->count_0 = n;
    return arg3;
}
