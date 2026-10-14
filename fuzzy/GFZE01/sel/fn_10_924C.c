/* Non-matching: best partial attempt (97.74% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_1_bss_8B3A0[];
extern u32 lbl_10_data_0[];
extern void *lbl_1_bss_6D82C;

extern void fn_80008BEC(void *dst, int c, u32 n);
extern void *fn_1_7F518(s16 a, void *b, s32 c);
extern int sprintf(char *buf, const char *fmt, ...);
extern s32 fn_1_12A32C(void *s);
extern void fn_1_12AB38(void *p);
extern void *fn_1_D3884(void *p);
extern void fn_1_12A2B8(u32 flag);
extern void fn_1_80270(void *src, void *dst);
extern void fn_1_80058(s8 idx, u8 *p);
extern void fn_1_80C18(u8 *a, u8 *b, s8 n);

typedef struct {
    u8 pad0[0x458];
    s16 f458;
    s16 f45a;
    u8 pad1[0x108];
    s32 f564;
    u8 pad2[0x34];
    u8 str59c[0x174];
    u8 obj710[0xc];
    u8 obj71c[0x10];
    u8 obj72c[0xac];
    char fmt[0x20];
} SelData;

typedef struct {
    s16 f0;
    u16 f2;
    u32 f4;
    u8 f8;
    u8 pad[0x17];
} SelEnt;

typedef struct {
    u8 pad324[0x324];
    u32 f324;
    u8 pad[0x118];
} SelCell;

#pragma opt_loop_invariants off
void fn_10_924C(u8 *arg0) {
    u8 * fzgx_live;
    SelData *d = (SelData *)&lbl_10_data_0;

    if (*(u32 *)((u8 *)lbl_1_bss_8B3A0 + 0x94) & 0x2000000u) {
        if (d->f564 == -1) {
            char out[0x20];
            u8 str[0x20];
            u32 buf[8];
            u32 one = 1;
            s16 a;

            fn_80008BEC(buf, 0, 0x20);
            a = d->f45a;
            ((s16 *)buf)[1] = 6;
            ((u8 *)buf)[8] = (u8)(one << a);
            ((u32 *)buf)[1] = one << (d->f458);
            sprintf(out, d->fmt, fn_1_7F518(6, str, 0));
            d->f564 = fn_1_12A32C(out);
            if (lbl_1_bss_6D82C == 0) {
                fn_1_12AB38(d->obj710);
                lbl_1_bss_6D82C = fn_1_D3884(d->obj71c);
                fzgx_live = d->obj72c;
                fn_1_12AB38(fzgx_live);
            }
            fn_1_12A2B8(1);
            fn_1_12AB38(d->obj710);
            fn_1_80270(buf, arg0 + 0x1980);
            fzgx_live = d->obj72c;
            fn_1_12AB38(fzgx_live);
            fn_1_12A2B8(0);
            *(u32 *)(((0x1ca4) + (arg0))) = d->f564;
        }
    } else if (d->f564 == -1) {
        SelEnt entries[41];
        s16 i = 0;
        u32 zero = 0;
        u32 one = 1;
        SelEnt *p = entries;

        while (i < 41) {
            fn_1_80058((s8)i, (u8 *)p);
            p->f0 = i;
            i++;
            p->f8 = zero;
            p->f8 = p->f8 | (one << d->f45a);
            p->f4 = one << d->f458;
            p++;
        }
        d->f564 = fn_1_12A32C(d->str59c);
        fn_1_12A2B8(1);
        fn_1_80C18(arg0, (u8 *)entries, 41);
        fn_1_12A2B8(0);
        for (i = 0; i < 33; i += 8) {
            ((SelCell *)arg0 + i)->f324 = d->f564;
            ((SelCell *)arg0 + i + 1)->f324 = d->f564;
            ((SelCell *)arg0 + i + 2)->f324 = d->f564;
            ((SelCell *)arg0 + i + 3)->f324 = d->f564;
            ((SelCell *)arg0 + i + 4)->f324 = d->f564;
            ((SelCell *)arg0 + i + 5)->f324 = d->f564;
            ((SelCell *)arg0 + i + 6)->f324 = d->f564;
            ((SelCell *)arg0 + i + 7)->f324 = d->f564;
        }
        for (; i < 41; i++) {
            ((SelCell *)arg0 + i)->f324 = d->f564;
        }
    }
}
#pragma opt_loop_invariants reset
