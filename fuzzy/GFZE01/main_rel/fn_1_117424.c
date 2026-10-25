/* Non-matching: best partial attempt (98.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_117424_Vec3;

typedef struct {
    u8 unk_0;
    u8 pad_1;
    u8 unk_2;
    u8 pad_3;
    u16 unk_4[6];
    fn_1_117424_Vec3 pos;
    fn_1_117424_Vec3 prev;
    u8 unk_28[0xC];
    fn_1_117424_Vec3 vel;
    f32 unk_40;
} fn_1_117424_Particle;

typedef struct {
    u8 pad_0[0x150];
    struct {
        u8 pad_0[8];
        u8 *unk_8;
    } *unk_150;
} fn_1_117424_AccessoryData;

typedef struct {
    u8 unk_0;
    u8 pad_1[7];
    u32 unk_8;
    fn_1_117424_AccessoryData *unk_C;
    void *unk_10;
    u8 pad_14[4];
    s32 unk_18;
    u8 pad_1C[8];
    fn_1_117424_Particle *unk_24;
} fn_1_117424_AccessoryObject;

extern f32 lbl_1_rodata_7AB8[];
extern u8 lbl_1_data_3F510[];
extern u8 *fn_80077B14(void *);
extern u8 *fn_80083970(u8 *, const u8 *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DC20(void);
extern void fn_8006E250(void *, void *);

#pragma opt_propagation on
static inline u32 *fn_1_117424_model_indices(u8 *base) {
    u32 *indices = (u32 *)(base + 0xaac);
    return indices;
}

static inline u8 **fn_1_117424_model_names(u8 *base) {
    u8 **names = (u8 **)(base + 0x79c);
    return names;
}

static inline fn_1_117424_AccessoryData * fn_1_117424_read_pointer(fn_1_117424_AccessoryObject * owner) { return owner->unk_C; }
static inline f32 fn_1_117424_array_read(s32 index, f32 *array) { return array[index]; }
#pragma opt_dead_assignments off
static inline f32 fn_1_117424_read_pointer_(fn_1_117424_Particle * owner) { return owner->pos.x; }
#pragma opt_common_subs off
#pragma opt_loop_invariants off
void fn_1_117424(fn_1_117424_AccessoryObject *self) {
    fn_1_117424_Particle * fzgx_live_2;
    f32 fzgx_live_;
    f32 *k = lbl_1_rodata_7AB8;
    fn_1_117424_Particle * fzgx_live;
    u8 *data = lbl_1_data_3F510;
#define table fn_1_117424_model_indices(data)

    if (self != 0 && self->unk_10 != 0) {
        fn_1_117424_Particle *item;
        u32 i;
        u8 *model;
        u8 *mtx;

        fn_80077B14(self->unk_10);
        fn_80083970(fn_1_117424_model_names(data)[self->unk_8], data + 0x4bc);
        if (self->unk_0 & 2) {
            self->unk_0 &= ~2;
            lbl_8006DBAC(fn_1_117424_read_pointer(self)->unk_150->unk_8 + ((self->unk_8)[table]) * 0x18c + 0x88);
            lbl_8006DAEC();
            fzgx_live = self->unk_24;
            item = fzgx_live;
            i = 0;
            while (i < self->unk_18) {
                lbl_8006DBE4();
                lbl_8006E1B0(item->unk_28, &item->pos);
                i++;
                item++;
            }
            lbl_8006DC20();
        }

        fzgx_live_2 = self->unk_24;
        item = fzgx_live_2;
        i = 0;
        while (i < self->unk_18) {
            if (!(item->unk_0 & 1)) {
                item->prev = item->pos;
                item->pos.x += item->vel.x;
                item->pos.y += item->vel.y;
                item->pos.z += item->vel.z;
                item->pos.y = (*(f32 volatile *)&(item->pos.y)) /* Retail reloads this field. */ - 0.0013611111376020642;
                item->vel.y -= 0.0027222223579883575f;
            }
            i++;
            item++;
        }

        model = fn_1_117424_read_pointer(self)->unk_150->unk_8 + ((self->unk_8)[table]) * 0x18c;
        fzgx_live_2 = self->unk_24;
        item = fzgx_live_2;
        i = 0;
        while (i < self->unk_18) {
            lbl_8006DBAC(model + 0x88);
            lbl_8006DAEC();
            if (item->unk_0 & 1) {
                lbl_8006DBE4();
                lbl_8006E1B0(item->unk_28, &item->pos);
            }
            lbl_8006DC20();
            i++;
            item++;
        }

        model = fn_1_117424_read_pointer(self)->unk_150->unk_8 + ((self->unk_8)[table]) * 0x18c;
        fzgx_live_2 = self->unk_24;
        item = fzgx_live_2;
        i = 0;
        while (i < self->unk_18) {
            if (!(item->unk_0 & 1)) {
                fn_1_117424_Vec3 target;
                f32 t;
                f32 x;

                lbl_8006DBAC(model + 0x88);
                lbl_8006E1B0(item->unk_28, &target);
                t = -0.12f / item->unk_40;
                {
                    f32 dy = target.y - item->pos.y;
                    f32 dz = target.z - item->pos.z;
                    f32 dx = target.x - item->pos.x;
                    f32 sy = 0.76 * dy;
                    f32 sx = ((dx) * (t));
                    f32 sz = t * dz;
                    item->pos.x += sx;
                    item->pos.y += sy;
                    item->pos.z += sz;
                }
            }
            i++;
            item++;
        }

        {
            f32 damp = 0.8f;
            fzgx_live_2 = self->unk_24;
            item = fzgx_live_2;
            i = 0;
            while (i < self->unk_18) {
                i++;
                item->vel.x = damp * (fn_1_117424_read_pointer_(item) - item->prev.x);
                item->vel.y = damp * ((*(f32 volatile *)&(item->pos.y)) /* Retail reloads this field. */ - item->prev.y);
                item->vel.z = damp * (item->pos.z - item->prev.z);
                item++;
            }
        }

        mtx = fn_80077B14(self->unk_10);
        lbl_8006DBAC(fn_1_117424_read_pointer(self)->unk_150->unk_8 + ((self->unk_8)[table]) * 0x18c + 0x88);
        fzgx_live_2 = self->unk_24;
        item = fzgx_live_2;
        i = 0;
        while (i < self->unk_18) {
            s32 j;
            for (j = 0; j < item->unk_2; j++) {
                fn_8006E250(&item->pos, mtx + ((j)[item->unk_4]) * 0x40);
            }
            i++;
            item++;
        }
    }
}
#pragma opt_loop_invariants reset

#pragma opt_common_subs reset

#pragma opt_dead_assignments reset

