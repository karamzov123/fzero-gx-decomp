/* Non-matching: best partial attempt (63.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_common.h"

struct Pool { u8 pad0[8]; f64 two52; u8 pad10[0xA4]; f32 neg20; u8 padB8[0x3C]; u32 lim0, lim1, lim2, lim3, lim4; f32 fifteen; };
extern struct Pool lbl_1_rodata_78D0;
extern s32 fn_1_58C4(void);
extern s16 fn_1_6514(s32);
extern void fn_1_104730(s32, s32);
extern s16 fn_1_5948(s32);
extern void fn_1_627C(s32);
extern u32 lbl_801A63C0;
extern u32 fn_1_F2F34(void);
extern s16 camera_get_mode(void);
extern u32 fn_1_864E8(void *);
extern s16 fn_1_3F0C8(void);
extern u8 lbl_1_bss_6F239;
extern void fn_1_A2D84(u32);
extern s32 fn_1_54E34(void *, f32);
extern void lbl_8006DCA4(void);
extern void DCInvalidateRange(void *, u32);
extern void fn_1_106D30(void);
typedef void (*Sig_ARQCallback)(u32);
typedef struct { void *next; u32 owner, type, priority, source, dest, length; Sig_ARQCallback callback; } Sig_ARQRequest;
extern void ARQPostRequest(Sig_ARQRequest *, u32, u32, u32, u32, u32, u32, Sig_ARQCallback);

struct Manager {
    u8 pad0[0x14]; u32 seed;
    u8 pad18[0x22C];
    s16 current;
    u8 pad246[2];
    u32 state;
    u8 pad24c[0x348];
};

void fn_1_1049E0(void *arg0) {
    struct Manager *m = (struct Manager *)&lbl_1_bss_85280;
    u8 *pool = (u8 *)&lbl_1_rodata_78D0;
    u8 *entry = (u8 *)m + 0x18;
    s32 count, i;
    m->current = *(u16 *)arg0;
    if (*(u16 *)arg0 == 420) {
        lbl_801A63C0 = lbl_801A63C0 * (s32)0x676A4B6B + 0x33CB;
        m->seed = (lbl_801A63C0 >> 1) & 0x7FFF;
        count = fn_1_58C4();
        for (i = 0; i < count; i++, entry += 0x88) {
            if (fn_1_6514(i) == 1) {
                fn_1_104730(i, 1);
                fn_1_5948(i);
                if ((s32)(((m->seed >> 31) ^ (m->seed & 1)) - (m->seed >> 31)) != 1 &&
                    (s32)(((m->seed >> 31) ^ (m->seed & 1)) - (m->seed >> 31)) < 1 &&
                    (s32)(((m->seed >> 31) ^ (m->seed & 1)) - (m->seed >> 31)) >= 0) {
                    *(s16 *)(entry + 0x82) = 600;
                } else {
                    *(s16 *)(entry + 0x82) = 0;
                }
                *(s16 *)(entry + 0x84) = 0;
                *(s16 *)(entry + 0x86) = 0;
                *(f32 *)(entry + 0x78) = -20.0f;
                *(u32 *)(entry + 0) = *(u32 *)(entry + 0xC);
                *(u32 *)(entry + 4) = *(u32 *)(entry + 0x10);
                *(u32 *)(entry + 8) = *(u32 *)(entry + 0x14);
                entry[0x7F] = 0;
                fn_1_627C(i);
            }
        }
    }
    count = fn_1_58C4();
    entry = (u8 *)m + 0x18;
    for (i = 0; i < count; i++, entry += 0x88) {
        u32 limits[5];
        s32 slot = 0;
        limits[0] = *(u32 *)(pool+0xF4); limits[1] = *(u32 *)(pool+0xF8); limits[2] = *(u32 *)(pool+0xFC); limits[3] = *(u32 *)(pool+0x100); limits[4] = *(u32 *)(pool+0x104);
        if (entry[0x7F] == 0 && fn_1_6514(i) == 1 && fn_1_F2F34() == 0) {
            while (slot < 5 && *(u16 *)arg0 > limits[slot]) slot++;
            fn_1_5948(i);
            if (!(fn_1_864E8((void *)(s32)camera_get_mode()) & 0x8000)) {
                if ((lbl_1_bss_3C30.unk_0 & 0x100) && fn_1_3F0C8() == 40) fn_1_104730(i,1);
                else fn_1_104730(i,0);
            }
            fn_1_627C(i);
            {
                s32 hi = limits[slot];
                s32 lo = limits[slot-1];
                s32 d = hi - *(u16 *)arg0;
                s32 rem = (lo - hi) - (*(u16 *)arg0 - hi);
                if (slot == 3) {
                    *(f32 *)(entry+0) = *(f32 *)(entry+0x18);
                    *(f32 *)(entry+4) = *(f32 *)(entry+0x1C);
                    *(f32 *)(entry+8) = *(f32 *)(entry+0x20);
                } else if (slot == 1) {
                    *(f32 *)(entry+0) = (*(f32 *)(entry+0xC) * (f32)rem + *(f32 *)(entry+0x18) * (f32)d) / (f32)(lo-hi);
                    *(f32 *)(entry+4) = (*(f32 *)(entry+0x10) * (f32)rem + *(f32 *)(entry+0x1C) * (f32)d) / (f32)(lo-hi);
                    *(f32 *)(entry+8) = (*(f32 *)(entry+0x14) * (f32)rem + *(f32 *)(entry+0x20) * (f32)d) / (f32)(lo-hi);
                    *(s16 *)(entry+0x80) = *(s16 *)(entry+0x82)*rem + ((*(s16 *)(entry+0x84)*rem*rem)/2) + (((*(s16 *)(entry+0x86)*rem*rem*rem)*0x2AAB) >> 32);
                } else if (slot == 2) {
                    extern u8 lbl_1_bss_6F239;
                    *(f32 *)(entry+0) = *(f32 *)(entry+0x18);
                    *(f32 *)(entry+4) = *(f32 *)(entry+0x1C);
                    *(f32 *)(entry+8) = *(f32 *)(entry+0x20);
                    *(f32 *)(entry+0x78) = (-20.0f * (f32)d + 15.0f * (f32)rem) / (f32)(lo-hi);
                    if (!lbl_1_bss_6F239) { fn_1_A2D84(0xA9091800); lbl_1_bss_6F239 = 1; }
                } else if (slot == 4) {
                    *(f32 *)(entry+0) = (*(f32 *)(entry+0x18) * (f32)rem + *(f32 *)(entry+0x24) * (f32)d) / (f32)(lo-hi);
                    *(f32 *)(entry+4) = (*(f32 *)(entry+0x1C) * (f32)rem + *(f32 *)(entry+0x28) * (f32)d) / (f32)(lo-hi);
                    *(f32 *)(entry+8) = (*(f32 *)(entry+0x20) * (f32)rem + *(f32 *)(entry+0x2C) * (f32)d) / (f32)(lo-hi);
                    *(s16 *)(entry+0x80) = *(s16 *)(entry+0x82)*rem + ((*(s16 *)(entry+0x84)*rem*rem)/2) + (((*(s16 *)(entry+0x86)*rem*rem*rem)*0x2AAB) >> 32);
                    fn_1_A2D84(0xA9091900);
                }
            }
            *(u8 *)(entry+0x7E) = *(u16 *)arg0 / 60;
            *(u16 *)(entry+0x7C) = *(u16 *)arg0;
            if (slot == 4) {
                fn_1_5948(i); lbl_8006DCA4();
                if (fn_1_54E34(entry,5.0f) == 0) entry[0x7F] = 1;
                fn_1_627C(i);
            }
        }
    }
    if (m->state == 1) {
        s32 idx = (s16)((m->current - 60) / 2);
        if (idx < 0) idx=0; if (idx > 209) idx=209;
        {
            s32 *table = (s32 *)((u8 *)m + 0x24C);
            s32 *sources = (s32 *)((u8 *)m + 0x5B4);
            s32 size = *(s32 *)((u8 *)m + 4);
            void *data = (void *)table[idx];
            DCInvalidateRange((void *)size, (u32)data);
            ARQPostRequest((Sig_ARQRequest *)((u8 *)m + 0x594), 0, 1, 1,
                sources[idx], size, table[idx], (Sig_ARQCallback)fn_1_106D30);
        }
    }
}
