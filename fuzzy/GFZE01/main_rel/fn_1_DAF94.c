/* Non-matching: best partial attempt (65.09% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_san.h"

extern u32 fn_1_58C4(void);
extern const f32 lbl_1_rodata_6638;
extern const f32 lbl_1_rodata_6640;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
    f32 w;
} V4_1_1020;

typedef struct {
    void *unk_0;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_10;
    f32 unk_14;
    u16 unk_18;
    f32 unk_1c;
    V4_1_1020 pts[128];
    V4_1_1020 pts2[128];
} Sec_1_1020;

void fn_1_DAF94(Obj_1_data_2A7E0_At3C *arg0) {
    Sec_1_1020 *sec;
    u8 *base;
    s32 n;
    s32 *pt;
    f32 zero;
    V4_1_1020 *p;
    V4_1_1020 *e;

    base = (u8 *)arg0;
    sec = (Sec_1_1020 *)(base + 0x14);
    if (fn_1_58C4() >= 2) {
        return;
    }

    n = *(s32 *)(base + 0x10);
    zero = lbl_1_rodata_6638;

    while (n > 0) {
        *(u16 *)(base + 0x2c) = 0;
        *(f32 *)(base + 0x30) = zero;

        pt = (s32 *)sec->unk_0;

        p = (V4_1_1020 *)(base + 0x34);
        e = (V4_1_1020 *)(base + 0x834);
        while (p != e) {
            p[0].x = pt[3]; p[0].y = pt[4]; p[0].z = pt[5]; p[0].w = zero;
            p[1].x = pt[3]; p[1].y = pt[4]; p[1].z = pt[5]; p[1].w = zero;
            p[2].x = pt[3]; p[2].y = pt[4]; p[2].z = pt[5]; p[2].w = zero;
            p[3].x = pt[3]; p[3].y = pt[4]; p[3].z = pt[5]; p[3].w = zero;
            p += 4;
        }

        p = (V4_1_1020 *)(base + 0x834);
        e = (V4_1_1020 *)(base + 0x1034);
        while (p != e) {
            p[0].x = pt[3]; p[0].y = pt[4]; p[0].z = pt[5]; p[0].w = zero;
            p[1].x = pt[3]; p[1].y = pt[4]; p[1].z = pt[5]; p[1].w = zero;
            p[2].x = pt[3]; p[2].y = pt[4]; p[2].z = pt[5]; p[2].w = zero;
            p[3].x = pt[3]; p[3].y = pt[4]; p[3].z = pt[5]; p[3].w = zero;
            p += 4;
        }

        sec->x = pt[3];
        sec->y = pt[4];
        sec->z = pt[5];
        sec->unk_10 = 0;
        sec->unk_14 = lbl_1_rodata_6640;
        sec++;
        n--;
    }
}
