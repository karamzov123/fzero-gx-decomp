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

/* fzgx:begin fn_1_6400 */
struct fn_1_6400_lbl_801A6410 {
    u32 unk_0;
};
extern struct fn_1_6400_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_46B4(u32, u32, void *, u32);



typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} F68State;

// Report and clear the three pending camera state values.
void fn_1_6400(void) {
    F68State *state;

    state = (F68State *)&lbl_1_bss_F68;
    fn_1_46B4(lbl_801A6410.unk_0, state->unk_8, (*(u8 (*)[180])&lbl_1_data_3318), 0x396);
    fn_1_46B4(lbl_801A6410.unk_0, state->unk_4, (*(u8 (*)[180])&lbl_1_data_3318), 0x397);
    fn_1_46B4(lbl_801A6410.unk_0, state->unk_0, (*(u8 (*)[180])&lbl_1_data_3318), 0x398);
    state->unk_8 = 0;
    state->unk_4 = 0;
    state->unk_0 = 0;
}
/* fzgx:end fn_1_6400 */

/* fzgx:begin camera_get_state */
// Return the camera state byte, or -1 when no camera state is active.
s32 camera_get_state(void) {
    Obj_1_bss_F68_Target *camera = lbl_1_bss_F68;

    if (camera == 0) {
        return -1;
    }

    return camera->unk_48;
}
/* fzgx:end camera_get_state */

/* fzgx:begin camera_get_status */
// Return the camera status when a camera exists and is not marked inactive.
u32 camera_get_status(void) {
    Obj_1_bss_F68_Target *camera = lbl_1_bss_F68;
    u32 status;

    if (camera == 0) {
        status = 0;
    } else if ((camera->unk_0 & ((u32)1 << 31)) != 0) {
        status = 0;
    } else {
        status = camera->unk_4A;
    }

    return fn_1_6514(status);
}
/* fzgx:end camera_get_status */

/* fzgx:begin fn_1_6514 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

s32 fn_1_6514(s32 value) {
    Obj_1_bss_F68_Target *camera = lbl_1_bss_F68;
    s8 mode;

    if (camera == 0) {
        return -1;
    }
    if ((camera->unk_0 & ((u32)1 << 31)) != 0) {
        return 0;
    }

    mode = camera->unk_48;
    switch (mode) {
    case 9:
        return 2;
    case 10:
        return (value == 0) + 1;
    case 6:
        return (value == 3) + 1;
    }

    switch (game_camera_entries[value].unk_A8) {
    case 0:
        return 1;
    case 1:
    case 2:
        return 3;
    case 3:
        return 4;
    case 4:
        return 5;
    case 5:
        return 6;
    default:
        return -1;
    }
}
/* fzgx:end fn_1_6514 */

/* fzgx:begin camera_get_flags */
u32 camera_get_flags(void) {
    // Reports the active camera object's top-bit flag, or zero when no object is active.
    if (lbl_1_bss_F68 != 0) {
        return lbl_1_bss_F68->unk_0 & (1u << 31);
    }

    return 0;
}
/* fzgx:end camera_get_flags */

/* fzgx:begin camera_update */
__typeof__(lbl_1_bss_F68) camera_get_state_object(void);

// Dispatches to the camera update routine selected by the returned camera state.
void camera_update(void) {
    __typeof__(lbl_1_bss_F68) state = camera_get_state_object();

    if (((state->unk_0 >> 30) & 1) != 0) {
        fn_1_BD54();
    } else {
        fn_1_B870();
    }
}
/* fzgx:end camera_update */

/* fzgx:begin camera_update_state */
// Updates the camera state through the active or standard camera path.
void camera_update_state(__typeof__(lbl_1_bss_F68) state) {
    if ((state->unk_0 >> 30) & 1) {
        camera_get_extended_state_storage(state);
        lbl_8006DBAC();
    } else {
        fn_8006F038(&state->unk_4, &state->unk_4 + 6,
                     *((s16 *)&state->unk_4 + 14));
    }

    lbl_8006DCDC();
}
/* fzgx:end camera_update_state */

/* fzgx:begin fn_1_66B8 noprologue */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/camera.h"

extern void fn_1_550A8(void);
extern void fn_1_550E0(void);
extern void fn_1_54E00(void *);
extern s32 fn_1_54E34(void *, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DB30(void);

typedef Obj_1_bss_F68_Target fn_1_66B8_Obj;

struct fn_1_66B8_Global {
	u8 *unk_0;
	u8 *unk_4;
	u8 *unk_8;
};

struct fn_1_66B8_Vec {
	f32 x;
	f32 y;
	f32 z;
};

s32 fn_1_66B8(void *arg0, f32 arg1) {
	struct fn_1_66B8_Vec v;
	u8 *a;
	struct fn_1_66B8_Global *g = (struct fn_1_66B8_Global *)&lbl_1_bss_F68;
	u32 off;
	u32 i;
	u8 *sel;
	s32 ret = 0;

	if (g->unk_0 == 0) {
		return 0;
	}
	if (arg0 == 0) {
		arg0 = &v;
		psvec_set(&v, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C),
				 *(f32 *)(0xE0000000 + 0xC));
	}
	fn_1_550A8();
	lbl_8006DAEC();
	for (i = 0, off = 0; i < ((fn_1_66B8_Obj *)g->unk_0)->unk_49; i++) {
		if ((i == 0 && ((s8)((fn_1_66B8_Obj *)g->unk_0)->unk_48 == 9
					  || (s8)((fn_1_66B8_Obj *)g->unk_0)->unk_48 == 10))
			|| (i == 3 && (s32)((fn_1_66B8_Obj *)g->unk_0)->unk_48 == 6)) {
			sel = g->unk_8 + 0x12C;
			a = g->unk_8 + 0x15C;
		} else if (i == 1 && (s32)((fn_1_66B8_Obj *)g->unk_0)->unk_48 == 10) {
			sel = g->unk_4 + 0xDC;
			a = g->unk_4 + 0x15C;
		} else {
			sel = g->unk_4 + off + 0xDC;
			a = g->unk_4 + off + 0x15C;
		}
		fn_1_54E00(a);
		lbl_8006DBAC(sel);
		if (fn_1_54E34(arg0, arg1) != 0) {
			ret = 1;
			break;
		}
		off += 0x1FC;
	}
	lbl_8006DB30();
	fn_1_550E0();
	return ret;
}
/* fzgx:end fn_1_66B8 */

/* fzgx:begin fn_1_681C */
#include "types.h"

struct fn_1_681C_Copy12 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_681C_Entry {
    u8 pad_0[0x10];
    struct fn_1_681C_Copy12 unk_10;
    u8 pad_1C[0x1FC - 0x1C];
};

struct fn_1_681C_Other {
    u8 pad_0[0x1C];
    struct fn_1_681C_Copy12 unk_1C;
};

struct fn_1_681C_Globals {
    u32 state;
    struct fn_1_681C_Entry *entries;
    struct fn_1_681C_Other *other;
};



#pragma peephole off
void fn_1_681C(u32 index, u32 *output) {
    struct fn_1_681C_Globals *globals = &(*(struct fn_1_681C_Globals *)&lbl_1_bss_F68);
    u32 state = globals->state;
    s8 mode;

    if (state == 0) {
        return;
    }

    mode = *(s8 *)(state + 0x48);

    switch (mode) {
    case 9:
    case 10:
        *(struct fn_1_681C_Copy12 *)output = globals->other->unk_1C;
        return;
    default:
        *(struct fn_1_681C_Copy12 *)output = globals->entries[index & 0xff].unk_10;
        return;
    }
}
#pragma peephole reset
/* fzgx:end fn_1_681C */

/* fzgx:begin fn_1_6898 */
#include "types.h"

struct fn_1_6898_Copy12 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_6898_Entry {
    u8 pad_0[0x1C];
    struct fn_1_6898_Copy12 unk_1C;
    u8 pad_28[0x1FC - 0x28];
};

struct fn_1_6898_Other {
    u8 pad_0[0x28];
    struct fn_1_6898_Copy12 unk_28;
};

struct fn_1_6898_Globals {
    u32 state;
    struct fn_1_6898_Entry *entries;
    struct fn_1_6898_Other *other;
};



#pragma peephole off
void fn_1_6898(u32 index, u32 *output) {
    struct fn_1_6898_Globals *globals = &(*(struct fn_1_6898_Globals *)&lbl_1_bss_F68);
    u32 state = globals->state;
    s8 mode;

    if (state == 0) {
        return;
    }

    mode = *(s8 *)(state + 0x48);

    switch (mode) {
    case 9:
    case 10:
        *(struct fn_1_6898_Copy12 *)output = globals->other->unk_28;
        return;
    default:
        *(struct fn_1_6898_Copy12 *)output = globals->entries[index & 0xff].unk_1C;
        return;
    }
}
#pragma peephole reset
/* fzgx:end fn_1_6898 */

/* fzgx:begin fn_1_6914 */
#include "types.h"

struct fn_1_6914_Copy12 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_6914_Entry {
    u8 pad_0[0x28];
    struct fn_1_6914_Copy12 unk_28;
    u8 pad_34[0x1FC - 0x34];
};

struct fn_1_6914_Other {
    u8 pad_0[0x4C];
    struct fn_1_6914_Copy12 unk_4C;
};

struct fn_1_6914_Globals {
    u32 state;
    struct fn_1_6914_Entry *entries;
    struct fn_1_6914_Other *other;
};



#pragma peephole off
void fn_1_6914(u32 index, u32 *output) {
    struct fn_1_6914_Globals *globals = &(*(struct fn_1_6914_Globals *)&lbl_1_bss_F68);
    u32 state = globals->state;
    s8 mode;

    if (state == 0) {
        return;
    }

    mode = *(s8 *)(state + 0x48);

    switch (mode) {
    case 9:
    case 10:
        *(struct fn_1_6914_Copy12 *)output = globals->other->unk_4C;
        return;
    default:
        *(struct fn_1_6914_Copy12 *)output = globals->entries[index & 0xff].unk_28;
        return;
    }
}
#pragma peephole reset
/* fzgx:end fn_1_6914 */

/* fzgx:begin fn_1_6990 */
#include "types.h"

struct fn_1_6990_Copy12 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_6990_Entry {
    u8 pad_0[0x64];
    struct fn_1_6990_Copy12 unk_64;
    u8 pad_70[0x1FC - 0x70];
};

struct fn_1_6990_Other {
    u8 pad_0[0x70];
    struct fn_1_6990_Copy12 unk_70;
};

struct fn_1_6990_Globals {
    u32 state;
    struct fn_1_6990_Entry *entries;
    struct fn_1_6990_Other *other;
};



#pragma peephole off
void fn_1_6990(u32 index, u32 *output) {
    struct fn_1_6990_Globals *globals = &(*(struct fn_1_6990_Globals *)&lbl_1_bss_F68);
    u32 state = globals->state;
    s8 mode;

    if (state == 0) {
        return;
    }

    mode = *(s8 *)(state + 0x48);

    switch (mode) {
    case 9:
    case 10:
        *(struct fn_1_6990_Copy12 *)output = globals->other->unk_70;
        return;
    default:
        *(struct fn_1_6990_Copy12 *)output = globals->entries[index & 0xff].unk_64;
        return;
    }
}
#pragma peephole reset
/* fzgx:end fn_1_6990 */

/* fzgx:begin fn_1_6A0C */
typedef struct {
    Obj_1_bss_F68_Target *state;
    u8 *table;
    u8 *result;
} Globals;

extern u32 lbl_8006DD14(u32, void *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1_bss_F68_Target *fzgx_obj_lbl_1_bss_F68;
u8 *fzgx_obj_game_camera_entries;
u8 *fzgx_obj_live_camera;
u8 lbl_1_bss_F74;
u8 lbl_1_bss_F75;
u8 lbl_1_bss_F76;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_F68;
    s = *(u8 *)&fzgx_obj_game_camera_entries;
    s = *(u8 *)&fzgx_obj_live_camera;
    s = lbl_1_bss_F74;
    s = lbl_1_bss_F75;
    s = lbl_1_bss_F76;
}
#pragma section code_type ".text"

void fn_1_6A0C(u32 value, void *output) {
    
    u8 *ptr;

    if (fzgx_obj_lbl_1_bss_F68 != 0) {
        switch ((s8)fzgx_obj_lbl_1_bss_F68->unk_48) {
        case 9:
        case 10:
            ptr = fzgx_obj_live_camera + 0x7c;
            lbl_8006DD14((u32)ptr, output);
            break;
        default:
            ptr = fzgx_obj_game_camera_entries + (value & 0xff) * 0x1fc + 0x34;
            lbl_8006DD14((u32)ptr, output);
            break;
        }
    }
}
/* fzgx:end fn_1_6A0C */

/* fzgx:begin camera_get_mode */
// Return the normalized camera status, treating inactive states as zero.
s16 camera_get_mode(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;
    s16 value;

    if (state == 0) {
        value = 0;
    } else if ((state->unk_0 & ((s32)1 << 31)) != 0) {
        value = 0;
    } else {
        value = state->unk_4A;
    }

    value = fn_1_6B48(value);
    if (value == 0xff) {
        value = -1;
    }

    return value;
}
/* fzgx:end camera_get_mode */

/* fzgx:begin camera_get_output */
s16 camera_get_output(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;
    u32 result;

    // Return the camera output only when the state is active and ready.
    if ((s8)state->unk_48 == 6) {
        if (state == 0) {
            result = 0;
        } else if ((state->unk_0 & ((s32)1 << 31)) != 0) {
            result = 0;
        } else {
            result = state->unk_4A;
        }

        if (result == 3) {
            return live_camera->unk_6;
        }
    }

    return -1;
}
/* fzgx:end camera_get_output */

/* fzgx:begin fn_1_6B48 noprologue */
#include "types.h"

typedef struct {
    u32 unk_0;
    u8 pad_4[0x44];
    u8 unk_48;
} CameraState;

typedef struct {
    u8 pad_0[0x6];
    s16 value;
} CameraValue;

typedef struct {
    u8 pad_0[0x2];
    s16 value;
    u8 pad_4[0x1f8];
} CameraEntry;

typedef struct {
    CameraState *state;
    CameraEntry *entries;
    CameraValue *value;
} CameraGlobals;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
CameraState *fzgx_obj_lbl_1_bss_F68;
CameraEntry *fzgx_obj_game_camera_entries;
CameraValue *fzgx_obj_live_camera;
u8 lbl_1_bss_F74;
u8 lbl_1_bss_F75;
u8 lbl_1_bss_F76;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_F68;
    s = *(u8 *)&fzgx_obj_game_camera_entries;
    s = *(u8 *)&fzgx_obj_live_camera;
    s = lbl_1_bss_F74;
    s = lbl_1_bss_F75;
    s = lbl_1_bss_F76;
}
#pragma section code_type ".text"

s16 fn_1_6B48(s32 index) {
    CameraState * state;
{
    
    state = fzgx_obj_lbl_1_bss_F68;

    if (state == 0) {
        return -1;
    }

    if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        return -1;
    }

    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        return fzgx_obj_live_camera->value;
    case 11:
        return -1;
    default:
        return (fzgx_obj_game_camera_entries)[index].value;
}
    }
}
/* fzgx:end fn_1_6B48 */

/* fzgx:begin fn_1_6BC0 */
typedef struct {
    u8 pad_0[0x475];
    s8 active;
} CameraObject;

extern s8 fn_1_86624(void);
extern CameraObject *fn_1_86254(s32 index);

static inline void change_camera(u32 flags, GameCameraEntry *entries) {
    s16 *fzgx_value;
    s16 old_index;
    u32 new_index;

    old_index = entries->unk_2;
    new_index = old_index;
    if (((flags >> 1) & 1) != 0) {
        new_index = old_index + 1;
        if ((s16)new_index == fn_1_86624()) {
            new_index = 0;
        }
    } else if ((flags & 1) != 0) {
        new_index = old_index - 1;
        if ((s16)new_index < 0) {
            new_index = (s16)(fn_1_86624() - 1);
        }
    }
    if ((s16)new_index == old_index) {
        return;
    }
    fzgx_value = &game_camera_entries->unk_2;
    *fzgx_value = (s16)new_index;
    fn_1_86254(old_index)->active = -1;
    fn_1_86254((s16)new_index)->active = 0;
}
#pragma opt_propagation off
void fn_1_6BC0(u32 lab_unused0, u32 lab_unused1, u32 lab_unused2) {
    Obj_1_bss_F68_Target *state;
    state = lbl_1_bss_F68;
    if (state == 0) {
        return;
    }
    if ((s8)state->unk_48 != 0) {
        return;
    }
    change_camera(lbl_1_bss_9F8.unk_8, game_camera_entries);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_6BC0 */

/* fzgx:begin camera_set_result */
void camera_set_result(s16 value) {
    // Update the camera result only while the camera state is active.
    if (lbl_1_bss_F68 != 0) {
        game_camera_entries->unk_2 = value;
    }
}
/* fzgx:end camera_set_result */

/* fzgx:begin camera_forward_status */
// Forward the camera state's status to the next update stage.
void camera_forward_status(void) {
    Obj_1_bss_F68_Target *state = lbl_1_bss_F68;
    u32 value;

    if (state == 0) {
        value = 0;
    } else if ((state->unk_0 & ((u32)1 << 31)) != 0) {
        value = 0;
    } else {
        value = state->unk_4A;
    }

    fn_1_6D2C(value);
}
/* fzgx:end camera_forward_status */

/* fzgx:begin fn_1_6D2C noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

extern CameraState *camera_get_state_object(void);
extern void OSPanic(u8 *file, int line, u8 *message, ...);

typedef struct {
    Obj_1_bss_F68_Target *unk_0;
    u32 unk_4;
    u32 unk_8;
} F68State;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1_bss_F68_Target *fzgx_obj_lbl_1_bss_F68;
u32 fzgx_obj_game_camera_entries;
u32 fzgx_obj_live_camera;
u8 lbl_1_bss_F74;
u8 lbl_1_bss_F75;
u8 lbl_1_bss_F76;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_F68;
    s = *(u8 *)&fzgx_obj_game_camera_entries;
    s = *(u8 *)&fzgx_obj_live_camera;
    s = lbl_1_bss_F74;
    s = lbl_1_bss_F75;
    s = lbl_1_bss_F76;
}
#pragma section code_type ".text"

#pragma opt_dead_assignments off
u32 fn_1_6D2C(u32 index) {
    
    Obj_1_bss_F68_Target *obj;
    u8 *row;
    s8 mode;

    obj = fzgx_obj_lbl_1_bss_F68;

    if (obj == 0) {
        OSPanic(lbl_1_data_3318, 0x546, (u8 *)&lbl_1_data_35B0);
        return 0;
    }

    if (obj->unk_0 & 0x80000000) {
        return *(u32 *)camera_get_state_object();
    }

    mode = obj->unk_48;

    switch (mode) {
case 9: case 10: {

        return *(u32 *)(fzgx_obj_live_camera + 0xC);
    
} break;
default: {

        row = (u8 *)fzgx_obj_game_camera_entries + index * 0x1FC;
        return ((row)[4]);
    
} break;
}
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_6D2C */

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

/* fzgx:begin fn_1_727C */
typedef struct {
    Obj_1_bss_F68_Target *state;
    u8 *table_1;
    u8 *table_2;
} Fn1_727C_Globals;

extern u8 lbl_1_bss_6F244[128];
extern u8 lbl_1_bss_6EAB4__fzgx_offset_12[10];

extern s32 fn_1_3F864(void);
extern s32 fn_1_4C10(void);
extern s16 fn_1_3F0C8(void);
extern void fn_1_739C(void *, u32, s32);

void fn_1_727C(void) {
    u32 camera_index;
    Fn1_727C_Globals *globals;
    u32 lab_t1;
    s8 status;
    u8 index;

    globals = (Fn1_727C_Globals *)&lbl_1_bss_F68;
    index = fn_1_86624();
    camera_index = globals->state->unk_4A;
    if (!(globals->state != 0 && index != 0 && (lbl_1_bss_6EAB4.unk_0 & 0x20) == 0
        && fn_1_3F864() != 0 && fn_1_4C10() == 0 && lbl_1_bss_6F244[0] != 0
        && lbl_1_bss_6EAB4__fzgx_offset_12[0] != 0)) {
        return;
    } else {
        switch (fn_1_3F0C8()) {
            case 0x25:
                return;
            default:
                goto ok; /* Keep the verified branch to ok. */
        }
        return;
    ok:
        status = globals->state->unk_48;
        switch (status) {
        case 0: case 1: case 2: case 3: case 4:
        case 5: case 6: case 7: case 8: case 10:
            lab_t1 = index;
            fn_1_739C(globals->table_1 + camera_index * 0x1fc + 0x10, lab_t1, 4);
            break;
        case 9:
            lab_t1 = index;
            fn_1_739C(globals->table_2 + 0x1c, lab_t1, 4);
            break;
        }
    }
}
/* fzgx:end fn_1_727C */

/* fzgx:begin fn_1_739C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "dolphin/os/OSFastCast.h"

typedef struct {
    f32 x, y, z;
} Vec;

typedef struct {
    u8 pad_0[0x2];
    s16 unk_2;
    u8 pad_4[0x1f8];
} CameraEntry;

typedef struct {
    u8 pad_0[0x6];
    s16 unk_6;
} CameraValue;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 pad_7;
    u16 unk_8;
    u8 unk_A;
    u8 pad_B;
    f32 unk_C;
    f32 unk_10;
} SoundSlot;

typedef struct {
    u8 pad_0[0x68];
    f32 unk_68;
    u8 pad_6C[0x10];
    u32 unk_7C;
    u8 pad_80[0x98];
    u32 unk_118;
} SoundTarget;

typedef struct {
    u8 pad_0[0x49c];
    SoundTarget *unk_49C;
} SoundCar;

typedef struct {
    u8 pad_0[0x6];
    u8 unk_6;
    u8 pad_7[0x14b1];
} RaceInfo;

extern s16 fn_1_3F0C8(void);
extern void fn_1_862D4(s32, Vec *);
extern int camera_compare_values(const void *, const void *);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern u32 fn_1_864E8(s32);
extern u8 fn_1_A3D5C(u32, s8 *, s8 *, u8 *);
extern f32 fn_1_86544(s32);
extern s32 fn_1_3FC48(void);
extern void fn_1_A47F4(s32, u8, u8, s8 *, s8 *);
extern void fn_1_A4268(u32, u32, u8, u8);
extern void fn_1_A3654(u32, u32);
extern void fn_1_A358C(s32);
extern void fn_1_A2DF4(s32, u32, s32);
extern u32 fn_1_86514(s32);
extern f32 fn_1_8652C(s32);
extern void fn_1_A2D84(u32);
extern SoundCar *fn_1_86254(s32);
extern void fn_1_A4BC8(u32, u8, SoundTarget *);
extern void fn_1_3EF14(RaceInfo *);
extern void fn_80067344(u32, u32, u32, u32);

extern u32 lbl_801A66C8[2];
extern SoundSlot lbl_1_bss_6F1E4[4];
extern s8 lbl_1_bss_6F2C4;
extern u32 lbl_1_bss_6F2C8[4];
extern u8 lbl_1_bss_6F520[4];
extern f32 lbl_1_bss_6F524[];
extern u8 lbl_1_bss_6F59C[];
extern f32 lbl_1_data_35C8[];

extern const f32 lbl_1_rodata_194;
extern const f32 lbl_1_rodata_1AC;
extern const f32 lbl_1_rodata_1E8;
extern const f32 lbl_1_rodata_1EC;
extern const f32 lbl_1_rodata_1F0;
extern const f32 lbl_1_rodata_1F4;
extern const f32 lbl_1_rodata_1F8;
extern const f32 lbl_1_rodata_1FC;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1_bss_F68_Target *fzgx_obj_lbl_1_bss_F68;
CameraEntry *fzgx_obj_game_camera_entries;
CameraValue *fzgx_obj_live_camera;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_F68;
    s = *(u8 *)&fzgx_obj_game_camera_entries;
    s = *(u8 *)&fzgx_obj_live_camera;
}
#pragma section code_type ".text"


static inline s16 camera_get_id(s32 index) {
    Obj_1_bss_F68_Target *state = fzgx_obj_lbl_1_bss_F68;

    if (state == 0) {
        return -1;
    }
    if ((state->unk_0 & 0x80000000) != 0) {
        return -1;
    }
    switch ((s8)state->unk_48) {
    case 9:
    case 10:
        return fzgx_obj_live_camera->unk_6;
    case 11:
        return -1;
    default:
        return fzgx_obj_game_camera_entries[index].unk_2;
    }
}

static inline u32 camera_get_index(void) {
    Obj_1_bss_F68_Target *state = fzgx_obj_lbl_1_bss_F68;
    u32 status;

    if (state == 0) {
        status = 0;
    } else if ((state->unk_0 & 0x80000000) != 0) {
        status = 0;
    } else {
        status = state->unk_4A;
    }
    return status;
}

static inline s16 camera_get_mode(void) {
    s16 value = camera_get_id(camera_get_index());

    if (value == 0xff) {
        value = -1;
    }
    return value;
}

static inline u32 camera_get_count(void) {
    Obj_1_bss_F68_Target *state = fzgx_obj_lbl_1_bss_F68;
    s32 kind;

    if (state == 0) {
        return 0;
    }
    kind = state->unk_48;
    if (kind == 11) {
        return 1;
    }
    if ((state->unk_0 & 0x80000000) != 0) {
        return 1;
    }
    return state->unk_49;
}

static inline f32 dist_sq(Vec *a, Vec *b) {
    f32 dx;
    f32 dy;
    f32 dz;

    dx = a->x;
    dx -= b->x;
    dy = a->y;
    dy -= b->y;
    dz = a->z;
    dz -= b->z;
    dx *= dx;
    dx += dy * dy;
    dx += dz * dz;
    return dx;
}

static inline f32 CLAMP(f32 x, f32 lo, f32 hi) {
    if (x < lo) {
        return lo;
    }
    if (x > hi) {
        return hi;
    }
    return x;
}

void fn_1_739C(Vec *pos, u8 count, u8 max) {
    s8 first;
    s32 id;
    u32 me;
    u8 level;
    u32 flags;
    u8 prev[4];
    u32 numCams;
    u8 vol;
    s16 mode;
    s8 i;
    s8 j;
    s8 others;
    u8 k;
    u8 slotA;
    u8 slotB;
    f32 speed;
    s8 m;
    s8 done;
    u8 gain;
    u32 n;
    s32 found;
    s32 kk;

    SoundTarget *target;
    s8 pan;
    s8 span;
    s8 echoA;
    s8 echoB;
    u8 fade;

    Vec p;
    RaceInfo info;

    mode = fn_1_3F0C8();
    if (mode == 0x27) {
        return;
    }

    id = camera_get_mode();
    for (kk = 0; kk < 4; kk++) {
        prev[kk] = lbl_1_bss_6F1E4[kk].unk_1;
    }
    numCams = camera_get_count();
    me = fzgx_obj_lbl_1_bss_F68->unk_4A;
    if (max > count) {
        max = count;
    }

    for (i = 0; i < count; i++) {
        lbl_1_bss_6F59C[i] = i;
        fn_1_862D4(i, &p);
        lbl_1_bss_6F524[i] = dist_sq(&p, pos);
    }
    qsort(lbl_1_bss_6F59C, count, 1, camera_compare_values);

    if (max > 4) {
        lbl_1_bss_6F2C4 = 4;
    } else {
        lbl_1_bss_6F2C4 = max;
    }

    switch (numCams) {
    case 1:
        if (lbl_1_bss_6F2C4 == 1) {
            others = 0;
            first = 0;
        } else if (lbl_1_bss_6F2C4 < 4) {
            others = lbl_1_bss_6F2C4 - 1;
            first = 1;
        } else {
            others = 3;
            first = 1;
        }
        break;
    case 2:
        if (lbl_1_bss_6F2C4 == 2) {
            others = 0;
            first = 0;
        } else if (lbl_1_bss_6F2C4 < 4) {
            if (me == 1) {
                others = 1;
                first = 3;
            } else {
                others = 0;
                first = 0;
            }
        } else {
            others = 1;
            first = me + 2;
        }
        break;
    case 3:
        others = 0;
        first = 0;
        break;
    case 4:
    default:
        others = 0;
        first = 0;
        break;
    }

    for (j = 0; j < count; j++) {
        if (id == lbl_1_bss_6F59C[j]) {
            flags = fn_1_864E8(id);
            level = fn_1_A3D5C(id, &pan, &span, &fade);
            speed = fn_1_86544(id);
            if (mode == 0x28 && fn_1_3FC48() == 0) {
                if (numCams == 1) {
                    speed *= lbl_1_rodata_1AC;
                } else if (numCams == 2) {
                    speed *= lbl_1_rodata_1E8;
                } else if (numCams == 3) {
                    speed *= lbl_1_rodata_1EC;
                }
            }
            speed *= lbl_1_rodata_1F0;
            vol = __OSf32tou8(CLAMP(speed, 1.0f, 127.0f));

            if (lbl_1_bss_6F59C[j] != lbl_1_bss_6F1E4[me].unk_1) {
                lbl_1_bss_6F1E4[me].unk_1 = lbl_1_bss_6F59C[j];
                lbl_1_bss_6F1E4[me].unk_0 |= 3;
            } else {
                lbl_1_bss_6F1E4[me].unk_0 &= ~1;
            }
            lbl_1_bss_6F1E4[me].unk_C = lbl_1_bss_6F524[lbl_1_bss_6F59C[j]];
            lbl_1_bss_6F1E4[me].unk_2 = fade;
            lbl_1_bss_6F1E4[me].unk_4 = pan;
            lbl_1_bss_6F1E4[me].unk_5 = span;
            lbl_1_bss_6F1E4[me].unk_A = level;
            if (lbl_1_bss_6F1E4[me].unk_0 & 2) {
                u8 now = lbl_1_bss_6F1E4[me].unk_6;
                u8 d = now - vol;
                if (__abs(d) > 4) {
                    if (d > 0) {
                        lbl_1_bss_6F1E4[me].unk_6 = now + 4;
                    } else {
                        lbl_1_bss_6F1E4[me].unk_6 = now - 4;
                    }
                }
            } else {
                lbl_1_bss_6F1E4[me].unk_0 &= ~2;
                lbl_1_bss_6F1E4[me].unk_6 = vol;
            }

            fn_1_A47F4(me, vol, me, &echoA, &echoB);
            if (fade != 0) {
                fn_80067344(1, 0x10, 0xb0270000, fade);
                fn_80067344(1, 0x10, 0xb02a0000, pan);
            }
            fn_1_A4268(id, flags, me, level);
            fn_1_A3654(id, me);
            fn_1_A358C(id);

            if (level != 0) {
                slotA = 0;
                slotB = 0;
                if (flags & 0x880) {
                    fn_1_A2DF4(me, 0xa5100000, 0);
                    fn_1_A2DF4(me, 0xa6000000, 0);
                } else {
                    fn_1_A2DF4(me, 0xa5100000, level);
                    fn_1_A2DF4(me, 0xa5200000, pan);
                    fn_1_A2DF4(me, 0xa6000000, vol);
                }
                for (k = 0; k < numCams; k++) {
                    if (lbl_1_bss_6F1E4[k].unk_1 != 0xff && !(fn_1_864E8(lbl_1_bss_6F1E4[k].unk_1) & 0x80) &&
                        ((fn_1_86514(lbl_1_bss_6F1E4[k].unk_1) >> 29) & 1)) {
                        slotA = k;
                        break;
                    }
                }
                for (k = 0; k < numCams; k++) {
                    if (lbl_1_bss_6F1E4[k].unk_1 != 0xff && !(fn_1_864E8(lbl_1_bss_6F1E4[k].unk_1) & 0x80) &&
                        ((fn_1_86514(lbl_1_bss_6F1E4[k].unk_1) >> 25) & 1)) {
                        slotB = k;
                        break;
                    }
                }
                if (slotA == me) {
                    if (((fn_1_86514(id) >> 29) & 1) && !(flags & 0x80)) {
                        fn_1_A2DF4(4, 0xa5100000, level);
                        fn_1_A2DF4(4, 0xa6000000, vol);
                    } else if (((lbl_801A66C8[0] + 1) & 7) == 0) {
                        fn_1_A2DF4(4, 0xa6000000, 0);
                    }
                }
                if (slotB == me) {
                    if (((fn_1_86514(id) >> 25) & 1) && !(flags & 0x80)) {
                        fn_1_A2DF4(5, 0xa5100000, level);
                        fn_1_A2DF4(5, 0xa6000000, vol);
                    } else if (((lbl_801A66C8[0] + 2) & 7) == 0) {
                        fn_1_A2DF4(5, 0xa6000000, 0);
                    }
                }
                if (((fn_1_86514(id) >> 26) & 1) && fn_1_8652C(id) > lbl_1_rodata_1F8 &&
                    !(lbl_1_bss_6F1E4[me].unk_0 & 4)) {
                    fn_1_A2D84(0xa90a0700);
                    lbl_1_bss_6F1E4[me].unk_0 |= 4;
                } else {
                    lbl_1_bss_6F1E4[me].unk_0 &= ~4;
                }
                switch (fzgx_obj_lbl_1_bss_F68->unk_48) {
                case 9:
                    fn_1_A2DF4(me, 0xa7000000, echoA);
                    fn_1_A2DF4(me, 0xa7100000, echoB);
                    break;
                default:
                    if (((lbl_801A66C8[0] + 3) & 7) == 0) {
                        fn_1_A2DF4(me, 0xa7000000, 0);
                    }
                    if (((lbl_801A66C8[0] + 4) & 7) == 0) {
                        fn_1_A2DF4(me, 0xa7100000, 0);
                    }
                    break;
                }
            }

            target = fn_1_86254(id)->unk_49C;
            if (target != 0) {
                fn_1_A4BC8(id, me, target);
                if (numCams < 2 && target != 0 && target != (SoundTarget *)-1) {
                    if ((target->unk_7C & 0x1400000) && !(target->unk_7C & 1)) {
                        f32 rate = target->unk_68;
                        u8 tone;
                        u8 pitch;

                        fn_1_3EF14(&info);
                        rate *= lbl_1_rodata_1FC;
                        tone = __OSf32tou8(rate);

                        pitch = tone + 0x39;
                        if (info.unk_6 == 13) {
                            pitch = tone + 0x32;
                        }
                        fn_80067344(1, 0x10, 0xb02d0000, 0x3d);
                        fn_1_A2DF4(0, 0xa5400000, pitch);
                    } else {
                        if (((lbl_801A66C8[0] + 5) & 7) == 0) {
                            fn_80067344(1, 0x10, 0xb02d0000, 0);
                        }
                        if (((lbl_801A66C8[0] + 6) & 7) == 0) {
                            fn_1_A2DF4(0, 0xa5400000, 0);
                        }
                    }
                }
                lbl_1_bss_6F520[me] = target->unk_118;
            }
            lbl_1_bss_6F2C8[me] = flags;
        }
    }

    for (done = 0, m = 0, n = 0; done < others; n++, m++) {
        if (id == lbl_1_bss_6F59C[n]) {
            continue;
        }
        gain = lbl_1_data_35C8[first] * fn_1_A3D5C(lbl_1_bss_6F59C[n], &pan, &span, &fade);
        speed = fn_1_86544(lbl_1_bss_6F59C[n]);
        if (mode == 0x28 && fn_1_3FC48() == 0) {
            if (numCams == 1) {
                speed *= lbl_1_rodata_1AC;
            } else if (numCams == 2) {
                speed *= lbl_1_rodata_1E8;
            } else if (numCams == 3) {
                speed *= lbl_1_rodata_1EC;
            }
        }
        speed *= lbl_1_rodata_1F0;
        vol = __OSf32tou8(CLAMP(speed, 1.0f, 127.0f));

        if (lbl_1_bss_6F59C[n] != lbl_1_bss_6F1E4[me].unk_1) {
            found = 0;
            for (kk = 0; kk < 4; kk++) {
                if (prev[kk] == lbl_1_bss_6F59C[n]) {
                    found = 1;
                }
            }
            lbl_1_bss_6F1E4[first].unk_1 = lbl_1_bss_6F59C[n];
            if (!found) {
                lbl_1_bss_6F1E4[first].unk_0 |= 3;
                lbl_1_bss_6F1E4[first].unk_8 = lbl_801A66C8[0] % 3 + 1;
                fn_1_A2DF4(first, 0xa5000000, lbl_1_bss_6F1E4[first].unk_8);
            } else {
                lbl_1_bss_6F1E4[first].unk_0 &= ~1;
            }
        }
        lbl_1_bss_6F1E4[first].unk_C = lbl_1_bss_6F524[lbl_1_bss_6F59C[n]];
        lbl_1_bss_6F1E4[first].unk_2 = fade;
        lbl_1_bss_6F1E4[first].unk_4 = pan;
        lbl_1_bss_6F1E4[first].unk_5 = span;
        lbl_1_bss_6F1E4[first].unk_A = gain;
        if (lbl_1_bss_6F1E4[first].unk_0 & 2) {
            u8 now = lbl_1_bss_6F1E4[first].unk_6;
            u8 d = now - vol;
            if (__abs(d) > 4) {
                if (d > 0) {
                    lbl_1_bss_6F1E4[first].unk_6 = now + 4;
                } else {
                    lbl_1_bss_6F1E4[first].unk_6 = now - 4;
                }
            } else {
                lbl_1_bss_6F1E4[first].unk_0 &= ~2;
            }
        } else {
            lbl_1_bss_6F1E4[first].unk_6 = vol;
        }

        fn_1_A47F4(first, vol, me, &echoA, &echoB);
        if (fade != 0) {
            fn_80067344(1, 0x10, 0xb0270000, fade);
            fn_80067344(1, 0x10, 0xb02a0000, pan);
        }
        fn_1_A3654(lbl_1_bss_6F59C[n], first);
        fn_1_A358C(lbl_1_bss_6F59C[n]);
        flags = fn_1_864E8(lbl_1_bss_6F59C[n]);
        if (gain != 0 && !(flags & 0x880)) {
            if (((lbl_801A66C8[0] + m) & 3) == 0) {
                fn_1_A2DF4(first, 0xa5100000, gain);
                fn_1_A2DF4(first, 0xa5200000, pan);
                fn_1_A2DF4(first, 0xa7000000, echoA);
                fn_1_A2DF4(first, 0xa7100000, echoB);
                fn_1_A2DF4(first, 0xa6000000, vol);
            }
            if (((fn_1_86514(lbl_1_bss_6F59C[n]) >> 26) & 1) && fn_1_8652C(lbl_1_bss_6F59C[n]) > lbl_1_rodata_1F8 &&
                !(lbl_1_bss_6F1E4[first].unk_0 & 4)) {
                fn_1_A2D84(0xa90a0700);
                lbl_1_bss_6F1E4[first].unk_0 |= 4;
            } else {
                lbl_1_bss_6F1E4[first].unk_0 &= ~4;
            }
        } else if (lbl_1_bss_6F1E4[first].unk_1 != 0xff) {
            fn_1_A2DF4(first, 0xa6000000, 0);
            fn_1_A2DF4(first, 0xa5100000, 0);
            lbl_1_bss_6F1E4[first].unk_1 = 0xff;
        }
        lbl_1_bss_6F2C8[first] = flags;
        done++;
        first++;
    }
}
/* fzgx:end fn_1_739C */

/* fzgx:begin camera_compare_values */
s32 camera_compare_values(const u8 *lhs_index, const u8 *rhs_index) {
    f32 *camera_values = &lbl_1_bss_6F524.unk_0;
    f32 lhs_value = camera_values[*lhs_index];
    f32 rhs_value = camera_values[*rhs_index];

    // Orders two camera indices by their associated values.
    if (lhs_value < rhs_value) {
        return -1;
    }
    if (lhs_value == rhs_value) {
        return 0;
    }
    return 1;
}
/* fzgx:end camera_compare_values */

/* fzgx:begin fn_1_8298 */
extern GameCameraEntry *game_camera_entries;  // array of 0x1FC-byte records

// Initializes camera entry selections and updates the camera mode from the available entries.
void fn_1_8298(void) {
    s8 found;
    s8 count;
    s32 i;

    found = 0;
    count = fn_1_86624();

    for (i = 0; i < 4; i++) {
        game_camera_entries[i].unk_2 = -1;
    }

    for (i = 0; i < count; i++) {
        s8 index = fn_1_86634(i);

        if (index != -1) {
            found++;
            game_camera_entries[index].unk_2 = i;
        }
    }

    switch (found) {
    case 0:
        OSPanic(lbl_1_data_3318, 0x7d2, lbl_1_data_35E8);
        break;
    case 1:
        lbl_1_bss_F68->unk_48 = 0;
        break;
    case 2:
        switch (lbl_1_bss_F68->unk_4B) {
        case 0:
            lbl_1_bss_F68->unk_48 = 1;
            break;
        case 1:
            lbl_1_bss_F68->unk_48 = 2;
            break;
        }
        break;
    case 3:
        switch (lbl_1_bss_F68->unk_4C) {
        case 0:
            lbl_1_bss_F68->unk_48 = 3;
            break;
        case 1:
            lbl_1_bss_F68->unk_48 = 4;
            break;
        case 2:
            lbl_1_bss_F68->unk_48 = 5;
            break;
        case 3:
            lbl_1_bss_F68->unk_48 = 6;
            break;
        case 4:
            lbl_1_bss_F68->unk_48 = 6;
            break;
        }
        break;
    case 4:
        lbl_1_bss_F68->unk_48 = 8;
        break;
    }
}
/* fzgx:end fn_1_8298 */

/* fzgx:begin fn_1_847C noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x48];
    u8 unk_48;
} CameraObject;

typedef struct {
    u8 pad_0[0x6];
    s16 unk_6;
    u8 pad_8[0x4];
    u32 unk_C;
    u8 pad_10[0x8];
    s32 unk_18;
} CameraTable;

typedef struct {
    u8 pad_0[0x2];
    s16 unk_2;
} CameraEntry;

typedef struct {
    CameraObject *unk_0;
    CameraEntry *unk_4;
    CameraTable *unk_8;
    u8 pad_C[0x8];
    s8 unk_14;
} CameraState;

extern CameraState lbl_1_bss_F68;
extern s8 fn_1_86624(s8 mode);
extern s8 fn_1_86634(s32 index);

#pragma opt_propagation off
void fn_1_847C(s8 mode) {
    CameraState *state;
    s32 i;

    state = &lbl_1_bss_F68;
    state->unk_14 = fn_1_86624(mode);
    state->unk_8->unk_6 = -1;
    i = 0;
    while (i < state->unk_14) {
        if (fn_1_86634(i) == 0) {
            state->unk_8->unk_6 = i;
            break;
        }
        i++;
    }
    if (state->unk_8->unk_18 != 0) {
        state->unk_8->unk_C |= 0x100000;
    }
    if (mode == 1) {
        state->unk_0->unk_48 = 9;
    } else if (mode == 2) {
        state->unk_0->unk_48 = 10;
        state->unk_4->unk_2 = state->unk_8->unk_6;
    } else if (mode == 4) {
        state->unk_0->unk_48 = 9;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_847C */

/* fzgx:begin fn_1_857C */
#include "types.h"

typedef struct {
    u32 unk_0;
    u16 entries[15];
    s16 unk_22;
    u16 unk_24;
    u8 pad_26[0x1E];
    s16 unk_44;
    u16 unk_46;
    u8 unk_48;
    u8 unk_49;
    u8 unk_4A;
    u8 unk_4B;
    u8 unk_4C;
    u8 unk_4D;
    u8 pad_4E[2];
    u32 unk_50;
} fn_1_857C_CameraState;

extern u32 lbl_1_bss_7ADE8[40];
extern void *lbl_1_data_3310;





extern void fn_1_A6FE8(void);
extern void fn_1_DCE60(void *);
extern void fn_1_435C(u32);
extern s16 fn_1_3F8C(char *, void *, void *, int);
extern void fn_1_DCED0(void);

void fn_1_857C(void) {
    s16 index;
    s16 result;

    (*(fn_1_857C_CameraState * *)&lbl_1_bss_F68)->unk_48 = 0xb;
    lbl_1_data_3310 = lbl_1_bss_7ADE8;
    fn_1_A6FE8();
    fn_1_DCE60(lbl_1_data_3310);
    fn_1_435C((*(fn_1_857C_CameraState * *)&lbl_1_bss_F68)->unk_50);
    result = fn_1_3F8C((*(char (*)[14])&lbl_1_data_35FC), fn_1_DCED0, lbl_1_data_3310, 0x14);
    {
        fn_1_857C_CameraState *camera = (*(fn_1_857C_CameraState * *)&lbl_1_bss_F68);
        index = camera->unk_22;
        camera->unk_22 = index + 1;
        camera->entries[index] = result;
    }
}
/* fzgx:end fn_1_857C */

/* fzgx:begin camera_get_entry_field_0x2 */
// Returns the selected camera entry value for an 8-bit camera index.
s16 camera_get_entry_field_0x2(u32 index) {
    return game_camera_entries[(u8)index].unk_2;
}
/* fzgx:end camera_get_entry_field_0x2 */

/* fzgx:begin camera_set_selected_value */
// Cache the selected camera value for subsequent camera processing.
void camera_set_selected_value(u8 value) {
    lbl_1_bss_F74 = value;
}
/* fzgx:end camera_set_selected_value */

/* fzgx:begin camera_set_state_flag */
// Store the camera state flag used by subsequent camera updates.
void camera_set_state_flag(u8 value) {
    lbl_1_bss_F75 = value;
}
/* fzgx:end camera_set_state_flag */

/* fzgx:begin camera_get_values */
// Reads the camera values, falling back when the camera state cannot provide them.
s32 camera_get_values(f32 *value0, f32 *value1) {
    f32 result0;
    f32 result1;
    u8 mode;
    Obj_1_bss_F68_Target *obj;
    f32 fallback;

    obj = lbl_1_bss_F68;
    if (obj == 0) {
        mode = 0;
    } else if ((obj->unk_0 & ((u32)1 << 31)) != 0) {
        mode = 0;
    } else {
        mode = obj->unk_4A;
    }

    if (fn_1_8708(mode, &result0, &result1) != 0) {
        *value0 = result0;
        *value1 = result1;
        return 1;
    }

    fallback = lbl_1_rodata_188;
    *value0 = fallback;
    *value1 = fallback;
    return -1;
}
/* fzgx:end camera_get_values */

/* fzgx:begin fn_1_8708 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern const f32 lbl_1_rodata_194;

s32 fn_1_8708(s32 mode, f32 *value0, f32 *value1) {
    Obj_1_bss_F68_Target **pp;
    Obj_1_bss_F68_Target *obj;

    pp = &lbl_1_bss_F68;
    if (*pp == 0) {
        return -1;
    }
    obj = *pp;
    if ((obj->unk_0 & 0x80000000) != 0) {
        *value0 = lbl_1_rodata_194;
        *value1 = lbl_1_rodata_194;
        return 1;
    }
    *value0 = ((f32 (*)[2])((u8 *)obj + 0x58))[mode][0];
    *value1 = ((f32 (*)[2])((u8 *)*pp + 0x58))[mode][1];
    return 1;
}
/* fzgx:end fn_1_8708 */

/* fzgx:begin live_camera_set_shake */
// Marks the camera state active, accumulates a position delta, and tracks the highest value.
void live_camera_set_shake(s32 value, const f32 *delta) {
    LiveCamera *state;

    if (live_camera == 0) {
        OSPanic(lbl_1_data_3318, 0x89a, lbl_1_data_360C);
    }

    state = live_camera;
    state->unk_AC = 1;
    state->unk_CC += delta[0];
    state->unk_D0 += delta[1];
    state->unk_D4 += delta[2];

    if (value < 0 || (s32)state->unk_B0 < 0) {
        state->unk_B0 = -1;
    } else if ((s32)state->unk_B0 < value) {
        state->unk_B0 = value;
    }
}
/* fzgx:end live_camera_set_shake */

/* fzgx:begin fn_1_8840 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern const f32 lbl_1_rodata_188;
extern void OSPanic(u8 *file, ...);

void fn_1_8840(void) {
    LiveCamera *state;
    f32 value;

    if (live_camera == 0) {
        OSPanic(lbl_1_data_3318, 0x8b6, lbl_1_data_3630);
    }

    state = live_camera;
    value = lbl_1_rodata_188;
    state->unk_AC = 0;
    state->unk_B0 = 0;
    state->unk_C0 = value;
    state->unk_C4 = value;
    state->unk_C8 = value;
    state->unk_CC = value;
    state->unk_D0 = value;
    state->unk_D4 = value;
    state->unk_E4 = value;
    state->unk_E8 = value;
    state->unk_EC = value;
    state->unk_E4 = value;
    state->unk_E8 = value;
    state->unk_EC = value;
}
/* fzgx:end fn_1_8840 */

/* fzgx:begin game_camera_set_shake */
extern GameCameraEntry *game_camera_entries;  // array of 0x1FC-byte records

// Updates the selected camera state with a movement delta and tracks its highest value.
void game_camera_set_shake(s16 index, s16 mode, s32 value, const f32 *delta) {
    GameCameraEntry *camera;

    if (index < 0) {
        return;
    }

    if (game_camera_entries + index == 0) {
        OSPanic(lbl_1_data_3318, 0x8d1, lbl_1_data_3654);
    }

    camera = game_camera_entries + index;
    if (mode != camera->unk_2) {
        fn_1_8A0C(index);
        return;
    }

    camera->unk_10C = 1;
    camera->unk_12C += delta[0];
    camera->unk_130 += delta[1];
    camera->unk_134 += delta[2];
    camera->unk_150 += delta[2];
    camera->unk_154 += delta[1];
    camera->unk_158 += delta[0];

    if (value < 0 || (s32)camera->unk_110 < 0) {
        camera->unk_110 = -1;
    } else if ((s32)camera->unk_110 < value) {
        camera->unk_110 = value;
    }
}
/* fzgx:end game_camera_set_shake */

/* fzgx:begin fn_1_8A0C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern const f32 lbl_1_rodata_188;

void fn_1_8A0C(s16 index) {
    GameCameraEntry *entry;
    f32 value;

    if (index >= 0) {
        if (game_camera_entries + index == 0) {
            OSPanic(lbl_1_data_3318, 0x8f8, lbl_1_data_3654);
        }
        entry = game_camera_entries + index;
        value = lbl_1_rodata_188;
        entry->unk_10C = 0;
        entry->unk_110 = 0;
        entry->unk_120 = value;
        entry->unk_124 = value;
        entry->unk_128 = value;
        entry->unk_12C = value;
        entry->unk_130 = value;
        entry->unk_134 = value;
        entry->unk_144 = value;
        entry->unk_148 = value;
        entry->unk_14C = value;
        entry->unk_144 = value;
        entry->unk_148 = value;
        entry->unk_14C = value;
    }
}
/* fzgx:end fn_1_8A0C */

/* fzgx:begin camera_init */
// Initialize camera state before passing the shared camera object onward.
void camera_init(void) {
    fn_1_A6FE8();
    fn_1_8D08(game_camera_entries);
}
/* fzgx:end camera_init */

/* fzgx:begin live_camera_get */
// Return the shared camera object used by the camera system.
LiveCamera *live_camera_get(void) {
    return live_camera;
}
/* fzgx:end live_camera_get */

/* fzgx:begin game_camera_get */
// Return the current camera target object.
GameCameraEntry *game_camera_get(void) {
    return game_camera_entries;
}
/* fzgx:end game_camera_get */
