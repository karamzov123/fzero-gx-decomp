/* Non-matching: best partial attempt (76.19% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#include "rel/main_rel/live_camera.h"

typedef struct { f32 x, y, z; } CameraVec;
typedef struct {
    u8 mode;
    u8 pad1[3];
    s8 preset;
    s16 id;
    u8 pad8[12];
    s16 selection;
    u8 pad16[6];
    CameraVec eye;
    u8 pad28[12];
    CameraVec offset;
    u8 pad40[12];
    CameraVec target;
    u8 pad58[24];
    CameraVec rotation;
} CameraState;
typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    f32 x;
    f32 y;
    f32 z;
    f32 speed;
    u32 unk1c;
} CameraPreset;
typedef struct { u32 a, b, c; } CameraPair;
extern int fn_1_40BB4(void);
extern void fn_1_8636C(int, void *);
extern void fn_1_862D4(int, CameraVec *);
extern void fn_1_862A8(int, CameraVec *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(CameraVec *, CameraVec *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void *fn_1_20A5C(void *, void *);
extern void fn_1_15578(void *, CameraVec *, void *, void *, u32, void *, int, int, int, int);
extern const f32 lbl_1_rodata_604;

static inline void set_matrix_translation(f32 z, f32 y, f32 x)
{
    *(f32 *)(0xE0000000 + 0xC) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

static inline f32 fn_1_11C08_read_pointer(CameraState * owner) { return owner->offset.x; }
#pragma opt_dead_assignments off
static inline f32 fn_1_11C08_read_pointer_(CameraPreset * owner) { return owner->speed; }
#pragma opt_propagation off
static inline f32 fn_1_11C08_read_pointer__(CameraVec * owner) { return owner->x; }
void fn_1_11C08(CameraState *camera)
{
    f32 fzgx_live;
    f32 matrix[3][4];
    CameraVec position;
    CameraVec angles;
    CameraVec target;
    void *result;
    u32 handle;
    CameraPreset *preset;
    f32 speed;
    f32 frames;
    s32 tmp_ra3;

    if (camera->mode == 3 && fn_1_40BB4() == 0) {
        if ((lbl_1_bss_9F8.unk_A >> 1) & 1) camera->selection++;
        tmp_ra3 = lbl_1_bss_9F8.unk_A;
        if (tmp_ra3 & 1) camera->selection--;
        if (camera->selection > 8) camera->selection = 0;
        if (camera->selection < 0) camera->selection = 8;
    }
    fn_1_8636C(camera->id, matrix);
    preset = (CameraPreset *)((u8 *)&lbl_1_data_4AA0 + camera->preset * 32);
    speed = fn_1_11C08_read_pointer_(preset);
    frames = (f32)lbl_1_data_4484.unk_0;
    camera->offset.x += (f32)(frames * (speed * (preset->x - fn_1_11C08_read_pointer(camera))));
    camera->offset.y += (f32)(frames * (speed * (preset->y - camera->offset.y)));
    camera->offset.z += (f32)((((speed) * (frames)) * ((preset->z - camera->offset.z))));
    fn_1_862D4(camera->id, &position);
    lbl_8006DC6C(matrix);
    set_matrix_translation(position.z, position.y, fn_1_11C08_read_pointer__(&position));
    lbl_8006E1B0(&camera->offset, &camera->eye);
    camera->target = position;
    fn_1_862A8(camera->id, &angles);
    frames = (f32)lbl_1_data_4484.unk_0;
    speed = lbl_1_rodata_604;
    fzgx_live = camera->rotation.x;
    camera->rotation.x += (f32)(frames * (speed * (angles.x - fzgx_live)));
    camera->rotation.y += (f32)(frames * (speed * (angles.y - camera->rotation.y)));
    camera->rotation.z += (f32)(frames * (speed * (angles.z - camera->rotation.z)));
    lbl_8006DAEC();
    result = fn_1_20A5C(&camera->eye, &handle);
    target = camera->target;
{
    CameraPair pair;
    fn_1_15578(&camera->eye, &target, &handle, &pair, 0x40005, &result, 1, 0, 0, 0);
}
    lbl_8006DB30();
}
#pragma opt_propagation reset

#pragma opt_dead_assignments reset

