/* Non-matching: best partial attempt (91.05% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#include "rel/main_rel/screen_effect.h"

typedef struct {
    s32 a;
    u32 b;
    u32 c;
    u32 d;
} LoadArgs;
typedef struct {
    u8 lab_pad[4];
    u32 unk_4;
    s16 course;
} CourseState;
typedef struct MapEntry {
    s32 data;
    const u8 *name;
} MapEntry;
typedef struct {
    s32 count;
    u32 pad4;
    MapEntry *entries;
} MapList;
typedef struct {
    Obj_1_bss_6D600 header;
    u8 pad20[0x150];
    void *textures;
    MapList *maps;
    u32 map;
    u8 pad17C[0x1C];
    s32 texture_size;
    u32 map_size;
} LoadState;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    s16 rx;
    s16 ry;
    s16 rz;
    u8 pad12[6];
    f32 ox;
    f32 oy;
    f32 oz;
    u8 pad24[0xD0];
    struct { u8 pad0[12]; f32 value; } *extra;
    u8 padF8[12];
    u32 flags;
    u8 pad108[0x3A8];
} CourseItem;
extern LoadArgs lbl_1_rodata_3344;
extern u32 lbl_1_bss_38460[21];
extern u8 lbl_1_bss_384B4;
extern void fn_1_9A864(void);
extern u8 fn_1_7B074(void);
extern void fn_8006FDEC(void);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);
extern void fn_1_14CB4(void);
extern void fn_1_FA84(void);
extern int sprintf(char *, const char *, ...);
extern void *fn_1_D3A4C(void *);
extern MapList *fn_1_D3768(void *, void *);
extern u32 fn_80077D40(void);
extern u32 fn_80077BD4(void);
extern void fn_1_13B98(u32, u32);
extern void fn_1_F6A8(void);
extern void fn_1_9AABC(u32);
extern void fn_1_1384C(void *);
extern void fn_80008BEC(void *, int, u32);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006E0C8(void *);
extern void fn_1_79948(void);
extern void fn_1_9A1E8(void);

#pragma opt_common_subs off
#pragma opt_propagation off
u16 fn_1_7ACDC(u32 course)
{
    u8 * data = (u8 *)&lbl_1_data_1DCF0;
    CourseState *control = (CourseState *)((u8 *)&lbl_1_data_1DCF0 + 0x2B4);
    LoadState *state = (LoadState *)&lbl_1_bss_6D600;
    u32 previous_course = control->course;
    LoadArgs args;
    s32 i;
    char texture_file[32];
    Obj_1_bss_3BE0_Target **manager = &lbl_1_bss_3BE0;
    char file[32];
    Obj_1_bss_3BE4 *dest;
    u32 saved;
    MapList *maps;
    char * lab_t0;
    void * lab_t0_;
    MapList * tmp_call11;
    args = lbl_1_rodata_3344;

{
    u32 course_local = course;
    if (previous_course != course_local) {
        fn_1_9A864();
        if (!fn_1_7B074()) {
            if (state->textures || state->maps) {
                fn_8006FDEC();
            }
            if (state->textures) {
                lab_t0_ = state->textures;
                fn_80071718(lab_t0_);
                state->textures = 0;
            }
            if (state->maps) {
                fn_800711A8(state->maps);
                state->maps = 0;
            }
        }
        fn_1_14CB4();
        fn_1_FA84();
        control->course = -1;
        if (!fn_1_7B074()) {
            sprintf((lab_t0 = texture_file), (char *)data + 0x7D0, (char *)data + 0x7E0, course_local);
            sprintf((file), (char *)data + 0x7E8, (char *)data + 0x7E0, course_local);
            state->textures = fn_1_D3A4C(texture_file);
            state->texture_size = fn_80077D40();
            tmp_call11 = fn_1_D3768(file, state->textures);
            state->maps = tmp_call11;
            state->map_size = fn_80077BD4();
        }
        fn_1_13B98(course_local, 1);
        fn_1_F6A8();
    }
    if (!state->header.unk_1) {
        fn_1_9AABC(course_local);
    }
    args.a = (u32)&state->maps;
    args.b = (u32)&lbl_1_bss_38460[2];
    if (!state->header.unk_1) {
        args.c = (u32)&lbl_1_bss_384B4;
    }
    fn_1_1384C(&args);
    manager = &lbl_1_bss_3BE0;
    i = 0;
    control->course = course_local;
}
    state->header.unk_1 = i;
{
    CourseItem *source;
    source = (CourseItem *)(*manager)->unk_1C;
{
    Obj_1_bss_3BE4 **dest_base = (Obj_1_bss_3BE4 **)&lbl_1_bss_3BE4;
    dest = *dest_base;
}
    for (; i < (s32)(*manager)->unk_18; i++, source++, dest++) {
        saved = dest->unk_9C;
        fn_80008BEC(dest, 0, 0xA0);
        dest->unk_9C = saved;
        dest->unk_8 = source->x;
        dest->unk_C = source->y;
        dest->unk_10 = source->z;
        dest->unk_14 = source->x - source->ox;
        dest->unk_18 = source->y - source->oy;
        dest->unk_1C = source->z - source->oz;
        dest->unk_20 = source->rx;
        dest->unk_22 = source->ry;
        dest->unk_24 = source->rz;
        dest->unk_26 = source->rx;
        dest->unk_28 = source->ry;
        dest->unk_2A = source->rz;
        lbl_8006D758();
        lbl_8006DB74(dest->pad_2C);
        lbl_8006E0C8(&source->ox);
        lbl_8006DB74(dest->pad_2C + 0x30);
        if (source->extra) {
            dest->unk_98 = source->extra->value;
        }
        dest->unk_0 |= source->flags;
}
    }
    fn_1_79948();
    state->map = 0;
    if (control->course >= 0 && (maps = state->maps) != 0) {
        for (i = 0; i < maps->count; i++) {
            const u8 *name = maps->entries[i].name;
            if (name[0] == 'C' && name[3] == '_' && name[4] == 'M' &&
                name[5] == 'A' && name[6] == 'P' && name[7] == 0) {
                state->map = ((i)[maps->entries]).data;
                break;
            }
        }
    }
    fn_1_9A1E8();
    control->unk_4 = 0;

    return (u32)maps;
}
#pragma opt_common_subs reset
