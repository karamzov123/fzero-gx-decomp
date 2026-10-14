/* Non-matching: best partial attempt (66.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"

struct fn_1_82724_lbl_1_bss_960 { s16 unk_0; };
struct fn_1_82724_lbl_1_bss_6D820 {
    u8 pad_0[8]; void *unk_8;
    u8 pad_C[4]; void *unk_10; void *unk_14; void *unk_18; void *unk_1C; void *unk_20; void *unk_24;
    s16 unk_28; s8 unk_2A; u8 pad_2B[9]; u8 unk_34;
    u8 pad_35[3]; u32 unk_38; void *unk_3C; void *unk_40;
};
extern u8 lbl_1_bss_9C;
extern u32 lbl_1_data_1F1D8;
extern u32 lbl_801A6410;
extern void fn_1_8E188(void);
extern u32 fn_1_12AC00(void *);
extern u32 fn_1_12ADA0(void *, void *);
extern void *fn_1_4630(u32, u32, void *, u32);
extern void fn_1_818BC(void *, u32, u32);
typedef struct { u8 pad[0x324]; s32 unk_324; u8 pad328[0x68]; u32 unk_390; u32 unk_394[3]; u32 unk_3A0; } Entry;
extern s32 fn_1_818AC(const void *, const void *);
extern void fn_1_983CC(void *, void *);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_58E3C(void *);
extern void fn_1_5672C(void *, int);
extern void fn_1_A7294(void *, u32);
extern void fn_1_A744C(void *, u32);
extern void *fn_1_45D0(u32, u32, void *, u32);
extern void fn_1_FC414(void *, u32);
extern void fn_1_FCF74(void);
extern void *fn_1_435C(void *);
extern u32 fn_1_3F8C(void *, void *, void *, u32);
extern void fn_1_568EC(void *, void *, void *);
extern void fn_1_568F8(void *);
extern void fn_1_56D4C(void);
extern void *fn_1_84860(void);
extern void fn_1_82C70(void *, u32, void *, u32, u32);
extern int qsort(void *, size_t, size_t, s32 (*)(const void *, const void *));

void fn_1_82724(void *arg0, void *arg1, void *arg2, u32 arg3, u32 arg4) {
    struct fn_1_82724_lbl_1_bss_6D820 *m = (struct fn_1_82724_lbl_1_bss_6D820 *)&lbl_1_bss_6D820;
    u8 *data = (u8 *)&lbl_1_data_1F1D8;
    u32 count;
    u32 i;
    u32 active = 0;
    void *records;
    void *objects;
    void *shadow;
    void *text;
    void *p;
    void *q;

    m->unk_34 = 0;
    if (*(s16 *)&lbl_1_bss_960 == 9 && lbl_1_bss_9C == 6) {
        m->unk_38 = 1;
        fn_1_8E188();
    } else {
        m->unk_38 = 0;
    }
    if (m->unk_40 == 0) {
        m->unk_40 = (void *)fn_1_12AC00(data + 0x13bc);
        m->unk_3C = (void *)fn_1_12ADA0(data + 0x13d0, m->unk_40);
    }
    if (arg3 > 30) arg3 = 30;
    count = arg3;
    if (m->unk_1C == 0 && m->unk_24 == 0) {
        m->unk_14 = 0;
        m->unk_10 = 0;
        m->unk_1C = fn_1_4630(lbl_801A6410, count * 0x440, data + 0xe18, 0x7a1);
        records = m->unk_1C;
        for (i = 0; i < count; i++) *(s32 *)((u8 *)records + i * 0x440 + 0x324) = -1;
        m->unk_28 = 0;
        for (i = 0; i < count; i++) {
            if (((u32 *)((u8 *)arg2 + i * 0x20))[3] & 0x400) m->unk_28++;
        }
        if (m->unk_28 != 0) {
            m->unk_20 = fn_1_4630(lbl_801A6410, m->unk_28 * 0xa20, data + 0xe18, 0x7aa);
        }
        fn_1_818BC(arg2, count, arg4);
        qsort(records, count, 0x440, fn_1_818AC);
        objects = m->unk_18;
        for (i = 0; i < count; i++) {
            Entry *e = (Entry *)((u8 *)records + i * 0x440);
            *(void **)((u8 *)e + 0x32c) = (u8 *)objects + i * 0x620;
            if (e->unk_390 & 0x400) fn_1_983CC((u8 *)objects + i * 0x620, (u8 *)e->unk_3A0 + 0x6e0);
            else fn_1_983CC((u8 *)objects + i * 0x620, e);
            {
                u8 buf[0xe8];
                fn_80008BEC(buf, 0, 0xe8);
                *(s16 *)(buf + 0x18) = i;
                *(s16 *)(buf + 0x0c) = 1;
                *(void **)(buf + 0x38) = (u8 *)objects + i * 0x620;
                fn_1_58E3C(buf);
            }
        }
        m->unk_24 = fn_1_4630(lbl_801A6410, count * 0x4c, data + 0xe18, 0x7cc);
        fn_1_5672C((u8 *)m + 0x2a, *(s8 *)((u8 *)m + 0x2a));
        fn_1_A7294(records, count);
        fn_1_A744C(records, count);
        for (i = 0; i < count; i++) if (*(s8 *)((u8 *)objects + i * 0x620 + 0x474) != -1) active++;
        if (*(s16 *)&lbl_1_bss_960 == 2 || *(s16 *)&lbl_1_bss_960 == 14) {
            if (lbl_1_bss_8B3A0.unk_0 == 1 || lbl_1_bss_8B3A0.unk_0 == 3 || lbl_1_bss_8B3A0.unk_0 == 2) {
                m->unk_8 = fn_1_45D0(lbl_801A6410, 0x1440, data + 0xe18, 0x7e2);
                fn_1_FC414(m->unk_8, 1);
            } else {
                m->unk_8 = fn_1_45D0(lbl_801A6410, 0x41100, data + 0xe18, 0x7e7);
                fn_1_FC414(m->unk_8, 4);
            }
            fn_1_FCF74();
        } else if (*(s16 *)&lbl_1_bss_960 == 12) {
            m->unk_8 = fn_1_45D0(lbl_801A6410, 0x1440, data + 0xe18, 0x7ee);
            fn_1_FC414(m->unk_8, 1);
            fn_1_FCF74();
        }
        for (i = 0; i < count; i++) {
            fn_1_435C(arg0);
            fn_1_3F8C(data + 0x14d4, fn_1_56D4C, m->unk_24, 0x16);
            fn_1_435C(arg1);
            fn_1_568EC((u8 *)m->unk_18 + i * 0x620, (u8 *)m->unk_24 + i * 0x4c, (u8 *)m->unk_1C + i * 0x440);
            fn_1_3F8C(data + 0x14e4, fn_1_568F8, m->unk_24, 0);
            fn_1_3F8C(data + 0x14f8, fn_1_84860, m->unk_1C, 0x11);
            if (*(s16 *)&lbl_1_bss_960 == 2 || *(s16 *)&lbl_1_bss_960 == 14 || *(s16 *)&lbl_1_bss_960 == 12) {
                fn_1_82C70(arg1, i, (u8 *)m->unk_1C + i * 0x440, (u32)m->unk_8, active);
            } else if (*(s16 *)&lbl_1_bss_960 == 10) {
            }
        }
    }
}
