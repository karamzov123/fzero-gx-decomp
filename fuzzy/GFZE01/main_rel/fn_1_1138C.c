/* Non-matching: best partial attempt (94.59% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#include "rel/main_rel/live_camera.h"

typedef struct { f32 x, y, z; } Position;
typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[12];
    s16 unk_14;
    u8 pad_16[6];
    u8 unk_1C[0x30];
    Position unk_4C;
    f32 unk_58;
    s16 unk_5C;
    u8 pad_5E[0x12];
    Position unk_70;
    u8 unk_7C[0x30];
} Camera;
extern u32 lbl_801A63C0;
extern void fn_1_8636C(int, void *);
extern void fn_1_862D4(int, Position *);
extern u32 fn_1_862A8(u32, Position *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern const f32 lbl_1_rodata_604;
extern const f32 lbl_1_rodata_608[13];

static inline void set_translation(f32 z, f32 y, f32 x)
{
    *(f32 *)(0xE0000000 + 0xC) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

static inline f32 fn_1_1138C_read_pointer(Camera * owner) { return owner->unk_70.z; }
#pragma opt_propagation off
static inline f32 fn_1_1138C_read_pointer_(Camera * owner) { return owner->unk_70.x; }
static inline f32 fn_1_1138C_read_pointer__(Camera * owner) { return owner->unk_70.y; }
#pragma opt_common_subs off
#pragma opt_strength_reduction off
static inline f32 fn_1_1138C_read_pointer___(Position * owner) { return owner->x; }
#pragma opt_strength_reduction reset

#pragma opt_propagation on
static inline f32 camera_rate(void) { return (f32)lbl_1_data_4484.unk_0; }
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_1_1138C(Camera *camera)
{
    f32 rate;
    Position target;
    Position position;
    if (camera->unk_0 == 5 || camera->unk_0 <= 1 || camera->unk_0 == 2) {
        u32 random;
        lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        random = ((lbl_801A63C0 >> 16) & 0x7FFF) % 6;
        camera->unk_14 = random;
        camera->unk_4 = random;
    }
    fn_1_8636C(camera->unk_6, camera->unk_7C);
    fn_1_862D4(camera->unk_6, &position);
    lbl_8006DC6C(camera->unk_7C);
    set_translation(position.z, position.y, position.x);
    lbl_8006E1B0((u8 *)&lbl_1_data_4754 + camera->unk_4 * 16, camera->unk_1C);
    camera->unk_4C = position;
    fn_1_862A8(camera->unk_6, &target);
    rate = camera_rate();
    camera->unk_70.x += (f32)(rate * (lbl_1_rodata_604 * (fn_1_1138C_read_pointer___(&target) - fn_1_1138C_read_pointer_(camera))));
    camera->unk_70.y += (f32)(rate * (lbl_1_rodata_604 * (target.y - fn_1_1138C_read_pointer__(camera))));
    camera->unk_70.z += (f32)(rate * (lbl_1_rodata_604 * (target.z - fn_1_1138C_read_pointer(camera))));
    camera->unk_5C = ((Obj_1_data_4754 *)((u8 *)&lbl_1_data_4754 + camera->unk_4 * 16))->unk_C;
    camera->unk_58 = lbl_1_rodata_608[0];
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

#pragma opt_propagation reset

