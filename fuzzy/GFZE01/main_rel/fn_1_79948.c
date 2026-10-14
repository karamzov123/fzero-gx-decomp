/* Non-matching: best partial attempt (75.90% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad_0[0x70];
    f32 unk_70;
    u8 pad_74[0x34];
    f32 unk_A8;
} Rodata3278;

typedef struct {
    u8 pad_0[0x80];
    u32 unk_80;
    u8 *unk_84;
} Bss3BE0;

typedef struct {
    s8 unk_0;
    u8 unk_1;
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
} Entry;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
} Rec;

typedef struct {
    u8 pad_0[0x20];
    Rec rec[12];
    Entry ent0;
    u8 pad_150[8];
    Rec ent1;
} Bss6D600;

extern Bss3BE0 *lbl_1_bss_3BE0;
extern Bss6D600 lbl_1_bss_6D600;
extern Rodata3278 lbl_1_rodata_3278;
extern s16 lbl_1_data_2A7E0;
extern u32 fn_1_7AA50(f32);
extern u32 fn_1_7E8F4(void);

#define SRC (b->ent1)
#define E1B ((Entry *)&b->ent1)

#define CP(D) \
    (D).unk_0 = SRC.unk_0; \
    (D).unk_4 = SRC.unk_4; \
    (D).unk_8 = SRC.unk_8; \
    (D).unk_C = SRC.unk_C; \
    (D).unk_14 = (u32)&b->ent1; \
    (D).unk_10 = 0x20;

#define CE(D) \
    (D).unk_10 = SRC.unk_10; \
    (D).unk_14 = SRC.unk_14;

#define CV(D) \
    (D).unk_0 = SRC.unk_0; \
    (D).unk_4 = SRC.unk_4; \
    (D).unk_8 = SRC.unk_8; \
    (D).unk_C = SRC.unk_C; \
    (D).unk_10 = SRC.unk_10; \
    (D).unk_14 = SRC.unk_14;

void fn_1_79948(u32 arg0) {
    Bss6D600 *b = (Bss6D600 *)&lbl_1_bss_6D600;
    Rodata3278 *ro = (Rodata3278 *)&lbl_1_rodata_3278;
    Bss3BE0 *g = lbl_1_bss_3BE0;
    Entry *e0 = (Entry *)((u8 *)b + 0x140);
    Entry *e1 = (Entry *)((u8 *)b + 0x158);
    Rec *q = (Rec *)((u8 *)b + 0x20);
    Rec *r = (Rec *)((u8 *)b + 0x80);
    Rec *s = (Rec *)((u8 *)b + 0xe0);
    Entry *e;
    volatile Rec t4, t3, t2, t1, t0;

    if (g != 0 && g->unk_80 != 0) {
        e1->unk_F = 1;
        if (g->unk_84 != 0) {
            E1B->unk_0 = *g->unk_84;
        } else {
            E1B->unk_0 = 4;
        }
        fn_1_7AA50(ro->unk_70);
    } else {
        e1->unk_F = 0;
        E1B->unk_0 = 5;
        e1->unk_4 = ro->unk_70;
        e1->unk_8 = ro->unk_A8;
        e1->unk_C = 0;
        e1->unk_D = 0;
        e1->unk_E = 0;
    }

    e0->unk_F = 0;
    b->ent0.unk_0 = 5;
    e0->unk_4 = ro->unk_70;
    e0->unk_8 = ro->unk_A8;
    e0->unk_C = 0;
    e0->unk_D = 0;
    e0->unk_E = 0;

    e = (Entry *)ro;
    do {
        if (e->unk_0 == lbl_1_data_2A7E0) {
            e0->unk_F = 1;
            b->ent0.unk_0 = e->unk_1;
            e0->unk_4 = e->unk_4;
            e0->unk_8 = e->unk_8;
            e0->unk_C = e->unk_C;
            e0->unk_D = e->unk_D;
            e0->unk_E = e->unk_E;
        }
        e++;
    } while (e->unk_0 != -1);

    CE(q[0]);
    CE(q[1]);
    CV(t3);
    CP(q[0]);
    CP(t4);
    CP(b->rec[4]);
    CP(b->rec[8]);
    CP(q[1]);
    CP(t2);
    CP(r[1]);
    CE(q[2]);
    CE(q[3]);
    CP(s[1]);
    CP(q[2]);
    CP(t1);
    CP(r[2]);
    CP(s[2]);
    CP(q[3]);
    CP(t0);
    CP(r[3]);
    CP(s[3]);

    fn_1_7E8F4();
}
