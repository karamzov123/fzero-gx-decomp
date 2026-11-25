#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ranking.h"

extern void fn_1_9AD88(void);
extern void OSReport(const char *format, ...);
extern void fn_1_9AD54(void);


extern void fn_1_9A508(void);

/* fzgx:begin fn_1_1586A8 */
// fn_1_1586A8: empty in retail (single blr).
void fn_1_1586A8(void) {
}
/* fzgx:end fn_1_1586A8 */

/* fzgx:begin fn_1_1586AC */
struct RankingResetVector { u32 a[3]; };
struct RankingResetRecord {
    u32 unk_0;
    u32 unk_4;
    struct RankingResetVector unk_8;
    struct RankingResetVector unk_14;
    u8 pad_20[0x1C];
};
extern u32 lbl_1_rodata_D978[3];
extern u32 lbl_1_rodata_D984[39];
extern void fn_1_9A508(void);

void fn_1_1586AC(void) {
    Obj_1_data_2A7E0_At3C *manager;
    s32 record_index;
    struct RankingResetRecord *record;
    s32 x;
    s32 y;
    s32 z;
    manager = lbl_1_data_2A7E0.unk_3C;
    manager->unk_0 = 0;
    /* The 400-record effect pool follows the 20-by-20-by-40 occupancy grid. */
    record = (struct RankingResetRecord *)((u8 *)manager + 0xFA0C);
    for (record_index = 0; record_index < 400; record_index++, record++) {
        record->unk_0 = 0;
        record->unk_8 = *(struct RankingResetVector *)lbl_1_rodata_D978;
        record->unk_14 = *(struct RankingResetVector *)lbl_1_rodata_D984;
    }
    /* Only the first 20 words of each 40-word grid row are reset by retail. */
    for (x = 0; x < 20; x++) {
        for (y = 0; y < 20; y++) {
            for (z = 0; z < 20; z++) {
                *(u32 *)((u8 *)manager + x * 3200 + y * 160 + z * 4 + 12) = 0;
            }
        }
    }
    fn_1_9A508();
}
/* fzgx:end fn_1_1586AC */

/* fzgx:begin fn_1_158980 */
// fn_1_158980: empty in retail (single blr).
void fn_1_158980(void) {
}
/* fzgx:end fn_1_158980 */

/* fzgx:begin fn_1_158984 */
#include "psvec.h"

extern void OSReport(const char *format, ...);




struct fn_1_158984_Arg0 {
    u8 pad_0[0x118];
    u32 unk_118;
};
struct fn_1_158984_lbl_1_rodata_D958 {
    u8 pad_0[0x18];
    f64 unk_18;
    u8 pad_20[0x18];
    u32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f64 unk_58;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    u8 pad_6C[0x4];
    f64 unk_70;
};
typedef struct { f32 x, y, z; } RankingVector;
typedef struct {
    u32 flags;
    u8 pad_4[8];
    RankingVector position;
    s16 angle_x, angle_y, angle_z;
} RankingModel;
typedef struct {
    s32 active;
    s32 cooldown;
    RankingVector velocity;
    RankingVector spin;
    u8 pad_20[0x18];
    RankingModel *model;
} RankingSlot;
struct fn_1_158984_lbl_801A66A0 { u32 unk_0; };
typedef struct {
    u8 pad_0[0xD4];
    RankingVector vector;
} RankingScratch;

extern f32 lbl_8006D188(u32);
extern s16 camera_get_mode(void);
extern s32 fn_1_58C4(void);
extern struct fn_1_158984_lbl_1_rodata_D958 lbl_1_rodata_D958;
extern struct fn_1_158984_lbl_801A66A0 lbl_801A66A0;
extern RankingScratch *lbl_801A66CC;
extern u32 fn_1_5948(u32);
extern u32 fn_1_627C(u32);
extern void *fn_1_8627C(s32);
extern void fn_1_681C(u32, u32 *);
extern void fn_1_9A7A8(u32 *);

#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_head(f32 *f, f64 *d) {
    f[0] = 10.0f;
    f[1] = 100.0f;
    f[2] = 20.0f;
    f[3] = 1000.0f;
    f[4] = 2000.0f;
    f[5] = 0.0f;
    d[0] = 4503601774854144.0;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_20[6] = { 0, 0, 0, 0, 0, 0 };
const u32 fzgx_pool_table_38[1] = { 0x64646400 };
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_tail(f32 *f, f64 *d) {
    f[0] = 65536.0f;
    f[1] = 300.0f;
    f[2] = 600.0f;
    f[3] = 900.0f;
    f[4] = 256.0f;
    f[5] = 768.0f;
    f[6] = 1280.0f;
    d[0] = 0.01;
    f[7] = 800.0f;
    f[8] = 500.0f;
    f[9] = 40000.0f;
    d[1] = 4503599627370496.0;
}
#pragma section code_type ".text"

void fn_1_158984(void) {
    Obj_1_data_2A7E0_At3C *data;
    s32 count;
    s32 i;
    RankingSlot *slot;
    s32 j;
    RankingSlot *other;
    s32 collided;
    struct fn_1_158984_Arg0 *camera;
    s32 mode;
    f32 width_x, center_x, x;
    f32 width_y, center_y, y, upper_x, z;
    f32 wrap_width_y, wrap_center_y, wrap_y, wrap_upper_y;
    f32 wrap_width_z, wrap_center_z, wrap_z, wrap_upper_z;
    s32 inside_x, inside_y, inside_z;
    f32 dx, dy, dz;
    f64 damp;
    f32 spin_y, spin_z;
    u32 color;

    data = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        mode = camera_get_mode();
        if (mode >= 0) {
            camera = fn_1_8627C(mode);
            if (camera != 0) {
                data->unk_4 = camera->unk_118 + 1;
                break;
            }
        }
        fn_1_627C(i);
    }
    slot = (RankingSlot *)((u8 *)data + 0xFA0C);
    for (i = 0; i < (s32)data->unk_0; i++, slot++) {
        if ((s32)data->unk_4 == 2) {
            slot->spin.x = lbl_8006D188((s32)(65536.0f * (lbl_801A66A0.unk_0 % 300) / 300.0f));
            slot->spin.y = lbl_8006D188((s32)(65536.0f * (lbl_801A66A0.unk_0 % 600) / 600.0f));
            slot->spin.z = lbl_8006D188((s32)(65536.0f * (lbl_801A66A0.unk_0 % 900) / 900.0f));
            spin_y = 768.0f;
            spin_z = 1280.0f;
            slot->model->angle_x += (s32)(256.0f * slot->spin.x);
            slot->model->angle_y += (s32)(spin_y * slot->spin.y);
            slot->model->angle_z += (s32)(spin_z * slot->spin.z);
        } else {
            damp = 0.01;
            slot->model->angle_x = (slot->model->angle_x + (f64)(damp * -slot->model->angle_x));
            slot->model->angle_y = (slot->model->angle_y + (f64)(damp * -slot->model->angle_y));
            slot->model->angle_z = (slot->model->angle_z + (f64)(damp * -slot->model->angle_z));
        }
        slot->model->flags &= 0xFEFFFFFF;
        if (slot->active != 0 && ((s32)data->unk_4 == 1 || (s32)data->unk_4 >= 3)) {
            if (slot->cooldown != 0) {
                slot->cooldown--;
            }
            psvec_add(&slot->model->position, &slot->velocity, &slot->model->position);
            fn_1_681C(0, (u32 *)&lbl_801A66CC->vector);
            width_x = 800.0f;
            x = slot->model->position.x;
            center_x = lbl_801A66CC->vector.x;
            upper_x = width_x + center_x;
            if (x > upper_x) inside_x = 0;
            else if (x < center_x - width_x) inside_x = 0;
            else inside_x = 1;
            if (inside_x) {
                width_y = 500.0f;
                y = slot->model->position.y;
                if (y > width_y + (center_y = lbl_801A66CC->vector.y)) inside_y = 0;
                else if (y < center_y - width_y) inside_y = 0;
                else inside_y = 1;
                if (inside_y) {
                    z = slot->model->position.z;
                    if (z > upper_x) inside_z = 0;
                    else if (z < lbl_801A66CC->vector.z - 800.0f) inside_z = 0;
                    else inside_z = 1;
                    /* All axes are inside the bounds; skip the wrapping block. */
                    if (inside_z) goto no_wrap;
                }
            }
            if (x > upper_x) slot->model->position.x = center_x - 800.0f;
            else if (x < center_x - 800.0f) slot->model->position.x = upper_x;
            wrap_width_y = 500.0f;
            wrap_y = slot->model->position.y;
            wrap_center_y = lbl_801A66CC->vector.y;
            wrap_upper_y = wrap_width_y + wrap_center_y;
            if (wrap_y > wrap_upper_y) slot->model->position.y = wrap_center_y - wrap_width_y;
            else if (wrap_y < wrap_center_y - wrap_width_y) slot->model->position.y = wrap_upper_y;
            wrap_width_z = 800.0f;
            wrap_z = slot->model->position.z;
            wrap_center_z = lbl_801A66CC->vector.z;
            wrap_upper_z = wrap_width_z + wrap_center_z;
            if (wrap_z > wrap_upper_z) slot->model->position.z = wrap_center_z - wrap_width_z;
            else if (wrap_z < wrap_center_z - wrap_width_z) slot->model->position.z = wrap_upper_z;
no_wrap:
            other = (RankingSlot *)(&data->unk_2724 + 0x34BA);
            collided = 0;
            for (j = 0; j < (s32)data->unk_0; j++, other++) {
                if (i != j && slot->cooldown == 0) {
                    RankingModel *model;
                    RankingModel *other_model;
                    f32 dz, dy, dx;
                    other_model = other->model;
                    model = slot->model;
                    dx = model->position.x;
                    dx -= other_model->position.x;
                    dy = model->position.y;
                    dy -= other_model->position.y;
                    dz = model->position.z;
                    dz -= other_model->position.z;
                    dx *= dx;
                    dx += dy * dy;
                    dx += dz * dz;
                    if (dx <= 40000.0f) {
                        lbl_801A66CC->vector = slot->velocity;
                        slot->velocity = other->velocity;
                        other->velocity = lbl_801A66CC->vector;
                        collided = 1;
                    }
                }
            }
            if (collided) {
                slot->active = 0;
                *(s32 *)((u8 *)data + data->unk_8 * 0x3C + 0xFA0C) = 1;
                *(s32 *)((u8 *)data + data->unk_8 * 0x3C + 0xFA10) = 60;
                data->unk_8++;
            }
        }
        if ((s32)data->unk_8 >= (s32)data->unk_0) data->unk_8 = 0;
    }
    color = fzgx_pool_table_38[0];
    fn_1_9A7A8(&color);
}
/* fzgx:end fn_1_158984 */

/* fzgx:begin fn_1_15903C */
// fn_1_15903C: empty in retail (single blr).
void fn_1_15903C(void) {
}
/* fzgx:end fn_1_15903C */

/* fzgx:begin fn_1_159040 */
void fn_1_159040(void) {
    fn_1_9AD88();
}
/* fzgx:end fn_1_159040 */

/* fzgx:begin fn_1_159060 */
// fn_1_159060: empty in retail (single blr).
void fn_1_159060(void) {
}
/* fzgx:end fn_1_159060 */

/* fzgx:begin fn_1_159064 */
// fn_1_159064: returns a constant.
int fn_1_159064(void) {
    return 0;
}
/* fzgx:end fn_1_159064 */

/* fzgx:begin fn_1_15906C */
struct RankingEffectObject {
    u8 pad_0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad_18[0x24];
    u32 unk_3C;
};
struct RankingVector_906C { f32 a[3]; };
struct RankingEffectRecord {
    s32 flag;
    s32 time;
    f32 x;
    f32 y;
    f32 z;
    u8 pad_14[12];
    struct RankingVector_906C copy;
    s32 ix;
    s32 iy;
    s32 iz;
    struct RankingEffectObject *obj;
};
/* Native initializer templates precede the random-magnitude literals in retail. */
static inline void clear_record_copy(struct RankingEffectRecord *record) {
    struct RankingVector_906C initial = {{0,0,0}};
    record->copy = initial;
}
static inline void set_direction_x(struct RankingEffectRecord *record, f32 magnitude) {
    struct RankingVector_906C vec = {{0,0,0}};
    vec.a[0] = magnitude;
    *(struct RankingVector_906C *)&record->x = vec;
}
static inline void set_direction_y(struct RankingEffectRecord *record, f32 magnitude) {
    struct RankingVector_906C vec = {{0,0,0}};
    vec.a[1] = magnitude;
    *(struct RankingVector_906C *)&record->x = vec;
}
static inline void set_direction_z(struct RankingEffectRecord *record, f32 magnitude) {
    struct RankingVector_906C vec = {{0,0,0}};
    vec.a[2] = magnitude;
    *(struct RankingVector_906C *)&record->x = vec;
}
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
    d = 0.8;
    d = 0.2;
    s = 32767.0f;
    s = -1.0f;
}
#pragma section code_type ".text"



struct RankingRandomState { u32 unk_0; };
extern struct RankingRandomState lbl_801A63C0;

static inline s32 random15(void) {
    u32 next_seed;
    next_seed = lbl_801A63C0.unk_0 * 0x676A4B6B + 0x33CB;
    lbl_801A63C0.unk_0 = next_seed;
    return (lbl_801A63C0.unk_0 >> 16) & 0x7FFF;
}
s8 fn_1_15906C(u32 arg0, struct RankingEffectObject *arg1, f32 arg2) {
    f32 *z_component;
    s32 *grid_x;
    Obj_1_data_2A7E0_At3C *effects;
    struct RankingEffectRecord *record;
    f32 magnitude;
    s32 axis;
    struct RankingEffectObject *obj;
    effects = lbl_1_data_2A7E0.unk_3C;
    switch (arg0) {
    case 0:
        if (arg1 == 0) break;
        arg1->unk_3C = 0;
        record = (struct RankingEffectRecord *)((u8 *)effects + effects->unk_0 * 60 + 0xFA0C);
        record->obj = arg1;
        clear_record_copy(record);
        if ((s32)effects->unk_0 < 50) {
            record->flag = 1;
            record->time = 60;
        } else record->flag = 0;
        #pragma fp_contract off
        magnitude = (10.0 * (0.8 + (random15() / 32767.0f) * 0.2));
        axis = random15() % 3;
        switch (axis) {
        case 0: {
            set_direction_x(record, magnitude);
            break;
        }
        case 1: {
            set_direction_y(record, magnitude);
            break;
        }
        case 2: {
            set_direction_z(record, magnitude);
            break;
        }
        }
        if (random15() % 2) {
            record->x *= -1.0f;
            record->y *= -1.0f;
            record->z *= -1.0f;
        }
        obj = record->obj;
        grid_x = &record->ix;
        *grid_x = (s32)(10.0f + obj->x / 100.0f) < 0 ? 0 : (s32)(10.0f + obj->x / 100.0f) > 19 ? 19 : (s32)(10.0f + obj->x / 100.0f);
        record->iy = (s32)(10.0f + obj->y / 100.0f) < 0 ? 0 : (s32)(10.0f + obj->y / 100.0f) > 19 ? 19 : (s32)(10.0f + obj->y / 100.0f);
        record->iz = (s32)(20.0f + obj->z / 100.0f) < 0 ? 0 : (s32)(20.0f + obj->z / 100.0f) > 39 ? 39 : (s32)(20.0f + obj->z / 100.0f);
        {
            s32 ix = record->ix;
            s32 iy = record->iy;
            s32 iz = record->iz;
            obj = record->obj;
            obj->x = (100.0f * ix) - 1000.0f;
            obj->y = (100.0f * iy) - 1000.0f;
            z_component = &obj->z;
            *z_component = (f32)(100.0f * (f32)iz) - 2000.0f;
        }
        /* The grid begins after the three-word effect-manager header. */
        {
            struct RankingGridRow { u32 cell[20][40]; };
            ((struct RankingGridRow *)((u8 *)effects + 12))[record->ix]
                .cell[record->iy][record->iz] = 1;
        }
        effects->unk_0++;
        effects->unk_8 = 50;
        break;
    default:
        break;
    }
    return 1;
}
#pragma fp_contract reset
/* fzgx:end fn_1_15906C */
