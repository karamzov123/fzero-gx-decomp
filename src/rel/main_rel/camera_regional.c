/* Previously matched Japan/PAL units of camera.c, retained until that TU matches those releases as one unit. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern void fn_1_BD54(void);
extern void fn_1_B870(void);
extern void camera_get_extended_state_storage(__typeof__(lbl_1_bss_F68));
extern void lbl_8006DBAC(void);
extern void fn_8006F038(void *, void *, s16);
extern void lbl_8006DCDC(void);
extern s16 fn_1_6B48(s16 value);
extern void fn_1_6D2C(u32);
extern s32 lbl_1_bss_F78;
extern void fn_1_A2DF4(u32, u32, u32);
extern s8 fn_1_86624(void);
extern s8 fn_1_86634(s32 index);
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern u8 lbl_1_bss_F74;
extern u8 lbl_1_bss_F75;
extern f32 lbl_1_rodata_188;
extern s32 fn_1_8708(u8 mode, f32 *value0, f32 *value1);
extern void fn_1_8A0C(s16 index);
extern void fn_1_A6FE8(void);
extern void fn_1_8D08(GameCameraEntry *value);
extern f32 lbl_1_bss_1040;
extern f32 lbl_1_bss_1044;
extern void OSReport(const unsigned char *, ...);
extern u8 lbl_1_bss_103C[4];
extern u8 lbl_1_bss_108C[52];
extern u8 lbl_1_bss_1014;

extern s8 fn_1_86624(void);
extern s8 fn_1_86634(s32 index);
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern void fn_1_8A0C(s16 index);
extern void OSReport(const unsigned char *, ...);

extern f32 lbl_1_rodata_2E0[32];
extern f32 lbl_8006D6FC(f32 *value, void *target);
u32 fn_1_6514(u32);
extern struct fn_1_6400_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern f64 lbl_1_rodata_478;
extern f32 lbl_1_rodata_49C;
extern f32 lbl_1_bss_10C0[6];

/* fzgx:begin fn_1_6DD0 */
extern void fn_1_BD54(void);
extern void fn_1_B870(void);
extern void camera_get_extended_state_storage(__typeof__(lbl_1_bss_F68));
extern void lbl_8006DBAC(void);
extern void fn_8006F038(void *, void *, s16);
extern void lbl_8006DCDC(void);
extern s16 fn_1_6B48(s16 value);
extern void fn_1_6D2C(u32);
extern s32 lbl_1_bss_F78;
extern void fn_1_A2DF4(u32, u32, u32);
extern s8 fn_1_86624(void);
extern s8 fn_1_86634(s32 index);
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern u8 lbl_1_bss_F74;
extern u8 lbl_1_bss_F75;
extern f32 lbl_1_rodata_188;
extern s32 fn_1_8708(u8 mode, f32 *value0, f32 *value1);
extern void fn_1_8A0C(s16 index);
extern void fn_1_A6FE8(void);
extern void fn_1_8D08(GameCameraEntry *value);
extern f32 lbl_1_bss_1040;
extern f32 lbl_1_bss_1044;
extern void OSReport(const unsigned char *, ...);
extern u8 lbl_1_bss_103C[4];
extern u8 lbl_1_bss_108C[52];
extern u8 lbl_1_bss_1014;

extern s8 fn_1_86624(void);
extern s8 fn_1_86634(s32 index);
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern void fn_1_8A0C(s16 index);
extern void OSReport(const unsigned char *, ...);

extern f32 lbl_1_rodata_2E0[32];
extern f32 lbl_8006D6FC(f32 *value, void *target);
u32 fn_1_6514(u32);
extern struct fn_1_6400_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern f64 lbl_1_rodata_478;
extern f32 lbl_1_rodata_49C;
extern f32 lbl_1_bss_10C0[6];


extern void lbl_8006DD14(u32, void *);
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern u32 *lbl_801A6D00;
extern void *lbl_801A66CC;

typedef struct {
    u32 unk_0;
    u8 unk_4;
} F6DD0Entry;

typedef struct {
    u32 unk_0;
    u8 pad[8];
    u32 unk_C;
} F6DD0Other;

typedef struct {
    Obj_1_bss_F68_Target *state;
    u8 *entries;
    F6DD0Other *other;
} F6DD0Bss;

/* volatile: retail preserves the flag-byte read and write even with a zero mask. */
static inline void F6DD0SetFlag(volatile F6DD0Entry *e, u8 flag) {
    e->unk_4 = e->unk_4 | flag;
}

void fn_1_6DD0(u8 index) {
    F6DD0Bss *bss = (F6DD0Bss *)&lbl_1_bss_F68;
    s8 mode;

    lbl_8006DD14((u32)((u8 *)lbl_801A6D00 + 0x30), lbl_801A66CC);
    if (bss->state == 0) {
        OSPanic(lbl_1_data_3318, 0x564, (u8 *)&lbl_1_data_35B0);
    }
    if ((bss->state->unk_0 & ((u32)1 << 31)) != 0) {
        *(u32 *)camera_get_state_object() |= ((u32)1 << 31);
    }
    mode = bss->state->unk_48;
    switch (mode) {
    case 9:
    case 10:
        bss->other->unk_C |= ((u32)1 << 31);
        break;
    default: {
        /* volatile: retail preserves this byte read/modify/write for a zero mask. */
        F6DD0SetFlag((F6DD0Entry *)(bss->entries + index * 0x1FC), 0);
        break;
    }
    }
}
/* fzgx:end fn_1_6DD0 */

/* fzgx:begin fn_1_6EC0 */
u32 fn_1_6EC0(u8 index) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return 0;
    }
    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }

    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        return 0;
    }

    return game_camera_entries[index].unk_A8 == 0;
}
/* fzgx:end fn_1_6EC0 */

/* fzgx:begin camera_is_mode_0x0b */
// Return whether the camera state is active and has the expected mode.
u32 camera_is_mode_0x0b(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return 0;
    }
    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }
    return (s8)state->unk_48 == 0x0B;
}
/* fzgx:end camera_is_mode_0x0b */

/* fzgx:begin fn_1_6F84 */
s32 fn_1_6F84(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;
    if (state == 0) {
        return 0;
    }
    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }

    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        if (live_camera->unk_2 == 4) {
            return 1;
        }
        return 0;
    }

    return 0;
}
/* fzgx:end fn_1_6F84 */

/* fzgx:begin fn_1_7000 */
s32 fn_1_7000(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;

    if (state == 0) {
        return 0;
    }
    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }

    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        if (live_camera->unk_2 == 5) {
            return 1;
        }
        return 0;
    }

    return 0;
}
/* fzgx:end fn_1_7000 */

/* fzgx:begin fn_1_707C */
typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[0x1F8];
} fn_1_707C_Entry;

typedef struct {
    u8 pad_0[0x6];
    s16 unk_6;
} fn_1_707C_Flag;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1_bss_F68_Target *fzgx_obj_lbl_1_bss_F68;
u8 *fzgx_obj_game_camera_entries;
u8 *fzgx_obj_live_camera;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_F68;
    s = *(u8 *)&fzgx_obj_game_camera_entries;
    s = *(u8 *)&fzgx_obj_live_camera;
}
#pragma section code_type ".text"

static inline fn_1_707C_Flag * fn_1_707C_read_pointer(void) { return (fn_1_707C_Flag *)fzgx_obj_live_camera; }
s32 fn_1_707C(u8 arg0) {
    u32 i;
    s32 value;
    fn_1_707C_Entry *cur;
    u32 count;
    u32 id;
    fn_1_707C_Entry *entries;
    fn_1_707C_Flag *flags;
    Obj_1_bss_F68_Target *obj;
    fn_1_707C_Entry * fzgx_live;

    if ((obj = (Obj_1_bss_F68_Target *)fzgx_obj_lbl_1_bss_F68) == 0) {
        return 0;
    }

    fzgx_live = (fn_1_707C_Entry *)fzgx_obj_game_camera_entries;
    entries = fzgx_live;
    i = 0;
    id = arg0;
    count = obj->unk_49;
    flags = fn_1_707C_read_pointer();
    cur = entries;

    {
    u32 fzgx_loop_i_1063;
for (fzgx_loop_i_1063 = 0; fzgx_loop_i_1063 < count; fzgx_loop_i_1063++) {
        if ((fzgx_loop_i_1063 == 0 && ((s8)obj->unk_48 == 9 || (s8)obj->unk_48 == 10)) ||
            (fzgx_loop_i_1063 == 3 && (s8)obj->unk_48 == 6)) {
            value = flags->unk_6;
        } else if (fzgx_loop_i_1063 == 1 && (s8)obj->unk_48 == 10) {
            value = entries->unk_2;
        } else {
            value = cur->unk_2;
        }
        if (value == id) {
            return 1;
        }
        cur = (fn_1_707C_Entry *)((u8 *)cur + 0x1FC);
    }
    i = fzgx_loop_i_1063;
}
    return 0;
}
/* fzgx:end fn_1_707C */

/* fzgx:begin camera_set_entry_field_0xa8 */
void camera_set_entry_field_0xa8(u8 index, s16 value) {
    // Store the selected camera entry's parameter.
    game_camera_entries[index].unk_A8 = value;
}
/* fzgx:end camera_set_entry_field_0xa8 */

/* fzgx:begin fn_1_715C */
void fn_1_715C(u8 index, s16 value) {
    // Toggle the camera effect associated with this entry before storing its state.
    if (game_camera_entries[index].unk_A8 == 0 && index < 4) {
        if (value == 0) {
            if (lbl_1_bss_F78 == 0) {
                fn_1_A2DF4(index, 0xa5000000, 8);
                lbl_1_bss_F78 = 1;
            }
        } else if (game_camera_entries[index].unk_A4 == 0 &&
                   lbl_1_bss_F78 != 0) {
            fn_1_A2DF4(index, 0xa5000000,
                       (&lbl_1_bss_6F1E4.unk_8)[index * 10]);
            lbl_1_bss_F78 = 0;
        }
    }

    game_camera_entries[index].unk_A4 = value;
}
/* fzgx:end fn_1_715C */

/* fzgx:begin camera_get_entry_field_0xa8 */
s16 camera_get_entry_field_0xa8(u32 index) {
    // Return the selected camera entry's stored value.
    return game_camera_entries[(u8)index].unk_A8;
}
/* fzgx:end camera_get_entry_field_0xa8 */

/* fzgx:begin camera_get_entry_field_0xa4 */
s16 camera_get_entry_field_0xa4(u32 index) {
    // Return the selected camera entry's stored value.
    return game_camera_entries[(u8)index].unk_A4;
}
/* fzgx:end camera_get_entry_field_0xa4 */
