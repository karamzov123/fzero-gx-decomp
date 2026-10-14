/* Non-matching: best partial attempt (66.81% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ranking.h"

extern void fn_1_9AD54(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern s16 camera_get_mode(void);
extern void *fn_1_8627C(void);
extern void fn_1_681C(int, u32 *);
extern void fn_1_9A7A8(u32 *);
extern f32 lbl_8006D188(int);
extern u32 lbl_801A66A0;
extern u32 lbl_801A66CC;
extern u32 lbl_1_rodata_D958[];

typedef struct {
    u32 unk_0;
    u32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x18];
    void *unk_38;
} Entry;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} ManagerHead;

typedef struct {
    u8 pad_0[0x118];
    u32 unk_118;
} CameraObj;

void fn_1_158984(void) {
    Obj_1_data_2A7E0_At3C *manager;
    Entry *entries;
    Entry *entry;
    int count;
    int i;
    int j;
    int overlap;
    int inside;
    u32 *obj;
    u32 *otherObj;
    Entry *other;
    f32 x, y, z;
    f32 dx, dy, dz;
    f32 half;

    manager = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        if (camera_get_mode() >= 0 && (obj = fn_1_8627C()) != 0) {
            manager->unk_4 = ((CameraObj *)obj)->unk_118 + 1;
            break;
        }
        fn_1_627C(i);
    }

    entries = (Entry *)((u8 *)manager + 0x10000 - 0x5F4);
    for (i = 0; i < (int)*(u32 *)manager; i++) {
        entry = &entries[i];
        if ((int)*(u32 *)((u8 *)manager + 4) == 2) {
            u32 seed = lbl_801A66A0;
            entry->unk_14 = lbl_8006D188((int)(65536.0f * (seed % 300) / 300.0f));
            seed = lbl_801A66A0;
            entry->unk_18 = lbl_8006D188((int)(65536.0f * (seed % 600) / 600.0f));
            seed = lbl_801A66A0;
            entry->unk_1C = lbl_8006D188((int)(65536.0f * (seed % 900) / 900.0f));
            obj = (u32 *)entry->unk_38;
            *(s16 *)((u8 *)obj + 0x18) += (s32)(256.0f * entry->unk_14);
            *(s16 *)((u8 *)obj + 0x1A) += (s32)(768.0f * entry->unk_18);
            *(s16 *)((u8 *)obj + 0x1C) += (s32)(1280.0f * entry->unk_1C);
        } else {
            obj = (u32 *)entry->unk_38;
            *(s16 *)((u8 *)obj + 0x18) = (s16)(*(s16 *)((u8 *)obj + 0x18) +
                (s32)(0.01 * (-(s16)*(s16 *)((u8 *)obj + 0x18))));
            *(s16 *)((u8 *)obj + 0x1A) = (s16)(*(s16 *)((u8 *)obj + 0x1A) +
                (s32)(0.01 * (-(s16)*(s16 *)((u8 *)obj + 0x1A))));
            *(s16 *)((u8 *)obj + 0x1C) = (s16)(*(s16 *)((u8 *)obj + 0x1C) +
                (s32)(0.01 * (-(s16)*(s16 *)((u8 *)obj + 0x1C))));
        }
        obj = (u32 *)entry->unk_38;
        obj[0] &= 0xFEFFFFFF;
        if (entry->unk_0 != 0 &&
            ((int)*(u32 *)((u8 *)manager + 4) == 1 ||
             (int)*(u32 *)((u8 *)manager + 4) >= 3)) {
            if (entry->unk_4 != 0) entry->unk_4--;
            psvec_add((u8 *)entry->unk_38 + 0xC, (u8 *)entry + 8,
                      (u8 *)entry->unk_38 + 0xC);
            fn_1_681C(0, (u32 *)(lbl_801A66CC + 0xD4));

            obj = (u32 *)entry->unk_38;
            x = *(f32 *)((u8 *)obj + 0xC);
            y = *(f32 *)((u8 *)obj + 0x10);
            z = *(f32 *)((u8 *)obj + 0x14);
            half = 800.0f;
            inside = x <= *(f32 *)(lbl_801A66CC + 0xD4) + half &&
                     x >= *(f32 *)(lbl_801A66CC + 0xD4) - half &&
                     y <= *(f32 *)(lbl_801A66CC + 0xD8) + 500.0f &&
                     y >= *(f32 *)(lbl_801A66CC + 0xD8) - 500.0f &&
                     z <= *(f32 *)(lbl_801A66CC + 0xD4) + half &&
                     z >= *(f32 *)(lbl_801A66CC + 0xDC) - half;
            if (!inside) {
                if (x > *(f32 *)(lbl_801A66CC + 0xD4) + half)
                    *(f32 *)((u8 *)obj + 0xC) = *(f32 *)(lbl_801A66CC + 0xD4) - half;
                else if (x < *(f32 *)(lbl_801A66CC + 0xD4) - half)
                    *(f32 *)((u8 *)obj + 0xC) = *(f32 *)(lbl_801A66CC + 0xD4) + half;
                if (y > *(f32 *)(lbl_801A66CC + 0xD8) + 500.0f)
                    *(f32 *)((u8 *)obj + 0x10) = *(f32 *)(lbl_801A66CC + 0xD8) - 500.0f;
                else if (y < *(f32 *)(lbl_801A66CC + 0xD8) - 500.0f)
                    *(f32 *)((u8 *)obj + 0x10) = *(f32 *)(lbl_801A66CC + 0xD8) + 500.0f;
                if (z > *(f32 *)(lbl_801A66CC + 0xDC) + half)
                    *(f32 *)((u8 *)obj + 0x14) = *(f32 *)(lbl_801A66CC + 0xDC) - half;
                else if (z < *(f32 *)(lbl_801A66CC + 0xDC) - half)
                    *(f32 *)((u8 *)obj + 0x14) = *(f32 *)(lbl_801A66CC + 0xDC) + half;
            }
        }

        overlap = 0;
        for (j = 0; j < (int)*(u32 *)manager; j++) {
            if (i != j && entry->unk_4 == 0) {
                other = &entries[j];
                obj = (u32 *)entry->unk_38;
                otherObj = (u32 *)other->unk_38;
                dx = *(f32 *)((u8 *)obj + 0xC) - *(f32 *)((u8 *)otherObj + 0xC);
                dy = *(f32 *)((u8 *)obj + 0x10) - *(f32 *)((u8 *)otherObj + 0x10);
                dz = *(f32 *)((u8 *)obj + 0x14) - *(f32 *)((u8 *)otherObj + 0x14);
                if (dx * dx + dy * dy + dz * dz < 40000.0f) {
                    overlap = 1;
                    *(u32 *)(lbl_801A66CC + 0xD4) = entry->unk_8;
                    *(u32 *)(lbl_801A66CC + 0xD8) = entry->unk_C;
                    *(u32 *)(lbl_801A66CC + 0xDC) = entry->unk_10;
                    entry->unk_8 = other->unk_8;
                    entry->unk_C = other->unk_C;
                    entry->unk_10 = other->unk_10;
                    other->unk_8 = *(u32 *)(lbl_801A66CC + 0xD4);
                    other->unk_C = *(u32 *)(lbl_801A66CC + 0xD8);
                    other->unk_10 = *(u32 *)(lbl_801A66CC + 0xDC);
                }
            }
        }
        if (overlap) {
            entry->unk_0 = 0;
            entries[manager->unk_8].unk_0 = 1;
            entries[manager->unk_8].unk_4 = 0x3C;
            manager->unk_8++;
        }
        if (manager->unk_8 >= *(u32 *)manager) manager->unk_8 = 0;
    }
    fn_1_9A7A8((u32 *)((u8 *)&lbl_1_rodata_D958 + 0x38));
}
