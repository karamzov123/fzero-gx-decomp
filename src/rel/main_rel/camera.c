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

/* fzgx:begin fn_1_5370 noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

extern u16 fn_1_3F8C(u8 *, void (*)(void), void *, u32);
extern void fn_1_426C(s16);
extern u32 fn_1_435C(u32);
extern u32 fn_1_434C(void);
extern u8 fn_1_86624(void);
extern void fn_1_8298(s8);
extern void fn_1_847C(s8);
extern void fn_1_857C(s8);
extern void fn_1_90E0(void);
extern void fn_1_EE44(void);
extern f32 fn_1_A6FE8(void);
extern const f64 lbl_1_rodata_178;
extern const f64 lbl_1_rodata_180;
extern void fn_1_8D08(void *, f32);
extern void fn_1_EBE4(void *, s32, u32);
extern u8 lbl_1_data_33CC[0xF];
extern u8 lbl_1_data_33DC[0xF];

typedef struct {
    u8 pad_0[4];
    s16 list0[15];
    s16 num0;
    u16 unk_24;
    s16 list1[15];
    s16 num1;
    u16 unk_46;
    s8 unk_48;
    u8 unk_49;
    u8 unk_4A;
    u8 unk_4B;
    u8 unk_4C;
    u8 unk_4D;
    u8 pad_4E[2];
    u32 unk_50;
    u32 unk_54;
    f32 unk_58;
    f32 unk_5C;
} Target;

typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[0x1F8];
} Item;

typedef struct {
    Target *unk_0;
    Item *unk_4;
    Target *unk_8;
} State;

s8 fn_1_5370(s8 arg0, s32 arg1) {
    State *state = (State *)&lbl_1_bss_F68;
    u32 i;
    s8 old;
    u32 num = 0;
    u32 flag = 0;
    u32 t;
    Item *item;
    u32 kind;
    f32 f;

    if (state->unk_0 == 0) {
        return -1;
    }
    t = fn_1_434C();
    fn_1_86624();
    old = state->unk_0->unk_4D;
    state->unk_0->unk_4D = arg0;
    fn_1_435C(state->unk_0->unk_50);

    for (i = 0; i < state->unk_0->num0; i++) {
        fn_1_426C(state->unk_0->list0[i]);
    }
    state->unk_0->num0 = 0;
    fn_1_435C(state->unk_0->unk_54);

    for (i = 0; i < state->unk_0->num1; i++) {
        fn_1_426C(state->unk_0->list1[i]);
    }
    state->unk_0->num1 = 0;

    switch (arg0) {
    case 0:
        fn_1_8298(arg0);
        break;
    case 1:
    case 2:
    case 4:
        fn_1_847C(arg0);
        break;
    case 3:
        fn_1_857C(arg0);
        break;
    }

    switch ((s8)state->unk_0->unk_48) {
    case 0:
        num = 1;
        break;
    case 1:
    case 2:
        num = 2;
        break;
    case 3:
    case 4:
    case 5:
    case 7:
        num = 3;
        break;
    case 6:
        num = 3;
        flag = 1;
        break;
    case 8:
        num = 4;
        break;
    case 9:
        flag = 1;
        break;
    case 10:
        num = 1;
        flag = 1;
        break;
    case 11:
        num = 0;
        flag = 0;
        break;
    }
    state->unk_0->unk_49 = num + flag;

    for (i = 0, item = state->unk_4; i < num;
         i++, item = (Item *)((u8 *)item + 0x1FC)) {
        f = fn_1_A6FE8();
        kind = (u8)(state->unk_0->unk_48);
        if ((s8)kind == 1 || (i == 0 && (s8)kind == 3) ||
            (i == 1 && (s8)kind == 4) || (i == 2 && (s8)kind == 5)) {
            f = f * lbl_1_rodata_178;
        }
        if ((s8)kind == 2) {
            f = f * lbl_1_rodata_180;
        }
        if ((s8)kind == 0) {
            item->unk_2 = (u16)arg1;
        }
        fn_1_8D08(item, f);
        fn_1_435C(state->unk_0->unk_50);
        state->unk_0->list0[state->unk_0->num0++] =
            fn_1_3F8C(lbl_1_data_33CC, fn_1_90E0, item, 0x14);
    }

    if (flag) {
        fn_1_A6FE8();
        if (arg0 == 4) {
            fn_1_EBE4(state->unk_8, -1, 1);
        } else {
            fn_1_EBE4(state->unk_8, arg1, 0);
        }
        fn_1_435C(state->unk_0->unk_50);
        state->unk_0->list0[state->unk_0->num0++] =
            fn_1_3F8C(lbl_1_data_33DC, fn_1_EE44, state->unk_8, 0x14);
    }

    fn_1_435C(t);
    return old;
}
/* fzgx:end fn_1_5370 */

/* fzgx:begin fn_1_56B8 noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

typedef struct {
    u8 unk_0;
    u8 unk_1;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    u8 pad_A[0x8];
    s16 unk_12;
    s16 unk_14;
    u8 pad_16[0x1E0 - 0x16];
} fn_1_56B8_Camera;

/* lbl_1_bss_F68 heads a run of three camera pointers */
typedef struct {
    Obj_1_bss_F68_Target *target;
    GameCameraEntry *entries;
    fn_1_56B8_Camera *live;
} fn_1_56B8_Cluster;

extern f32 fn_1_A6FE8(void);
extern void fn_1_8D08(GameCameraEntry *, f32);
extern void fn_1_8A0C(s32);
extern void fn_1_EBE4(fn_1_56B8_Camera *, s16, s32, f32);
extern void fn_1_EE04(fn_1_56B8_Camera *);

#pragma opt_common_subs off
void fn_1_56B8(void) {
    GameCameraEntry *entry;
    fn_1_56B8_Cluster *c = (fn_1_56B8_Cluster *)&lbl_1_bss_F68;
    u32 count = 0;
    u32 reset;
    u8 i;
    u8 mode;
    f32 scale;
    reset = 0;

    switch ((s8)c->target->unk_48) {
    case 0:
        count = 1;
        break;
    case 1:
    case 2:
        count = 2;
        break;
    case 3:
    case 4:
    case 5:
    case 7:
        count = 3;
        break;
    case 6:
        count = 3;
        reset = 1;
        break;
    case 8:
        count = 4;
        break;
    case 9:
        reset = 1;
        break;
    case 10:
        count = 1;
        reset = 1;
        break;
    case 11:
        count = 0;
        reset = 0;
        break;
    }

    entry = c->entries;
    for (i = 0; i < count; i++, entry++) {
        scale = fn_1_A6FE8();
        mode = c->target->unk_48;
        if ((s8)mode == 1 || (i == 0 && (s8)mode == 3) ||
            (i == 1 && (s8)mode == 4) ||
            (i == 2 && (s8)mode == 5)) {
            scale *= 2.0;
        }
        if ((s8)mode == 2) {
            scale *= 0.5;
        }
        fn_1_8D08(entry, scale);
        fn_1_8A0C(i);
    }

    if (reset) {
        fn_1_56B8_Camera saved;
        fn_1_56B8_Camera *live;

        scale = fn_1_A6FE8();
        live = c->live;
        saved = *live;
        fn_1_EBE4(live, 0, 0, scale);
        c->live->unk_0 = saved.unk_0;
        c->live->unk_1 = saved.unk_1;
        c->live->unk_2 = saved.unk_2;
        c->live->unk_4 = saved.unk_4;
        c->live->unk_6 = saved.unk_6;
        c->live->unk_8 = saved.unk_8;
        c->live->unk_12 = saved.unk_12;
        c->live->unk_14 = saved.unk_14;
        fn_1_EE04(c->live);
    }
}
/* fzgx:end fn_1_56B8 */

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

    mode = (s8)camera->unk_48;
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

#pragma opt_propagation off
s32 fn_1_66B8(void *arg0, f32 arg1) {
	struct fn_1_66B8_Vec v;
	u8 *a;
	struct fn_1_66B8_Global *g = (struct fn_1_66B8_Global *)&lbl_1_bss_F68;
	u32 off;
	u32 i;
	u8 *sel;
	s32 ret = 0;
	void *p = arg0;

	if (g->unk_0 == 0) {
		return 0;
	}
	if (p == 0) {
		p = &v;
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
		if (fn_1_54E34(p, arg1) != 0) {
			ret = 1;
			break;
		}
		off += 0x1FC;
	}
	lbl_8006DB30();
	fn_1_550E0();
	return ret;
}
#pragma opt_propagation reset
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

    mode = *(s8 *)((u8 *)state + 0x48);

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

    mode = *(s8 *)((u8 *)state + 0x48);

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

    mode = *(s8 *)((u8 *)state + 0x48);

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

    mode = *(s8 *)((u8 *)state + 0x48);

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

#pragma peephole on
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
    s = *(u8 *)&lbl_1_bss_F74;
    s = *(u8 *)&lbl_1_bss_F75;
    s = *(u8 *)&lbl_1_bss_F76;
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


#pragma opt_common_subs off
#pragma peephole on
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
    s = *(u8 *)&lbl_1_bss_F74;
    s = *(u8 *)&lbl_1_bss_F75;
    s = *(u8 *)&lbl_1_bss_F76;
}
#pragma section code_type ".text"

static inline CameraEntry *fn_1_6B48_array_read(CameraEntry *array) { return array; }
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
        return fn_1_6B48_array_read(fzgx_obj_game_camera_entries)[index].value;
}
    }
}
#pragma peephole reset
#pragma opt_common_subs reset
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
    struct { u32 value; } new_index;

    old_index = entries->unk_2;
    { s32 __reg_value_new_index = old_index; new_index.value = __reg_value_new_index; }
    if (((flags >> 1) & 1) != 0) {
        { s32 __reg_value_new_index = old_index + 1; new_index.value = __reg_value_new_index; }
        if ((s16)new_index.value == fn_1_86624()) {
            { s32 __reg_value_new_index = 0; new_index.value = __reg_value_new_index; }
        }
    } else if ((flags & 1) != 0) {
        { s32 __reg_value_new_index = old_index - 1; new_index.value = __reg_value_new_index; }
        if ((s16)new_index.value < 0) {
            { s32 __reg_value_new_index = (s16)(fn_1_86624() - 1); new_index.value = __reg_value_new_index; }
        }
    }
    if ((s16)new_index.value == old_index) {
        return;
    }
    fzgx_value = &(game_camera_entries->unk_2);
    *fzgx_value = (s16)new_index.value;
    fn_1_86254(old_index)->active = -1;
    fn_1_86254((s16)new_index.value)->active = 0;
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
    s = *(u8 *)&lbl_1_bss_F74;
    s = *(u8 *)&lbl_1_bss_F75;
    s = *(u8 *)&lbl_1_bss_F76;
}
#pragma section code_type ".text"

static inline u8 fn_1_6D2C_array_read(s32 index, u8 *array) { return array[index]; }
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

        return *(u32 *)((u8 *)fzgx_obj_live_camera + 0xC);
    
} break;
default: {

        row = (u8 *)fzgx_obj_game_camera_entries + index * 0x1FC;
        return fn_1_6D2C_array_read(4, row);
    
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
        OSPanic((u8 *)lbl_1_data_3318, 0x564, (u8 *)&lbl_1_data_35B0);
    }
    if ((bss->state->unk_0 & ((u32)1 << 31)) != 0) {
        *(u32 *)camera_get_state_object() |= ((u32)1 << 31);
    }
    mode = (s8)bss->state->unk_48;
    switch (mode) {
    case 9:
    case 10:
        bss->other->unk_C |= ((u32)1 << 31);
        break;
    default: {
        /* volatile: retail preserves this byte read/modify/write for a zero mask. */
        F6DD0SetFlag((volatile F6DD0Entry *)(bss->entries + index * 0x1FC), 0);
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

#pragma peephole on
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

static inline fn_1_707C_Flag * fn_1_707C_read_pointer(void) { return (fn_1_707C_Flag *)(void *)fzgx_obj_live_camera; }
#pragma opt_dead_assignments off
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

    if ((obj = (Obj_1_bss_F68_Target *)(void *)fzgx_obj_lbl_1_bss_F68) == 0) {
        return 0;
    }

    fzgx_live = (fn_1_707C_Entry *)(void *)fzgx_obj_game_camera_entries;
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
        if ((u32)value == id) {
            return 1;
        }
        cur = (fn_1_707C_Entry *)((u8 *)cur + 0x1FC);
    }
    i = fzgx_loop_i_1063;
}
    return 0;
}
#pragma opt_dead_assignments reset

#pragma peephole reset
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
extern u8 lbl_1_bss_6EAC6[10];

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
        && lbl_1_bss_6EAC6[0] != 0)) {
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
            state->unk_8->unk_6 = (s16)i;
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

#pragma opt_propagation off
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
#pragma opt_propagation reset
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

/* fzgx:begin fn_1_8B10 */
#include "types.h"

typedef struct fn_1_8B10_CameraObject {
    s16 pad_00;
    s16 kind;
    u8 pad_04[0xA0];
    s16 index;
} fn_1_8B10_CameraObject;

typedef struct CameraTarget {
    u8 pad_000[0x394];
    void *data;
} CameraTarget;

typedef struct CameraData {
    u8 pad_000[0x118];
    f32 x;
    f32 y;
} CameraData;

typedef struct fn_1_8B10_CameraEntry {
    f32 x;
    f32 y;
    s16 flags0;
    u8 pad_0A[2];
    f32 x1;
    f32 y1;
    s16 flags1;
    u8 pad_16[2];
    f32 x2;
    f32 y2;
    s16 flags2;
    u8 pad_22[2];
} fn_1_8B10_CameraEntry;

typedef struct CameraOutput {
    f32 x0;
    f32 y0;
    s16 flags0;
    u8 pad_0A[2];
    f32 x1;
    f32 y1;
    s16 flags1;
    u8 pad_16[2];
    f32 x2;
    f32 y2;
    s16 flags2;
} CameraOutput;

extern CameraTarget *fn_1_868C0(s8 index);
extern s8 fn_1_A5DC4(void);
extern const f32 lbl_1_rodata_200;
extern const f32 lbl_1_rodata_204;



void fn_1_8B10(fn_1_8B10_CameraObject *camera, CameraOutput *output) {
    CameraTarget *target;
    CameraData *data;

    target = fn_1_868C0((s8)camera->kind);
    if (camera->index == 0 && target != 0 && (data = target->data) != 0) {
        output->x0 = lbl_1_rodata_200 + data->x;
        output->y0 = data->y;
        output->flags0 = 0;
        output->x1 = lbl_1_rodata_200 + data->x;
        output->y1 = data->y;
        output->flags1 = 0;
        output->x2 = lbl_1_rodata_200 + data->x;
        output->y2 = data->y;
        output->flags2 = 0x1AAA;
    } else {
        output->x0 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].x;
        output->y0 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].y;
        output->flags0 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].flags0;
        output->x1 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].x1;
        output->y1 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].y1;
        output->flags1 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].flags1;
        output->x2 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].x2;
        output->y2 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].y2;
        output->flags2 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].flags2;

        if (fn_1_A5DC4() != 0) {
            f32 adjust;
            switch (camera->index) {
            case 1:
                adjust = lbl_1_rodata_200;
                break;
            case 2:
                adjust = lbl_1_rodata_204;
                break;
            case 3:
                adjust = lbl_1_rodata_204;
                break;
            default:
                adjust = lbl_1_rodata_200;
                break;
            }
            output->x0 -= adjust;
            output->x1 -= adjust;
            output->x2 -= adjust;
        }
    }
}
/* fzgx:end fn_1_8B10 */

/* fzgx:begin fn_1_8D08 noprologue */
#include "types.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car_test.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "types.h"

/* begin game/main_rel/car_test_types.h (deltawave784/windows-and-types@cf9407c75) */
#ifndef GAME_MAIN_REL_CAR_TEST_TYPES_H
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn183D28Vec3;

extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);

#endif  // GAME_MAIN_REL_CAR_TEST_TYPES_H
#ifndef GAME_MAIN_REL_CAR_TYPES_H
#define GAME_MAIN_REL_CAR_TYPES_H

#ifndef GAME_VEC3_H
#define GAME_VEC3_H

#endif  // GAME_VEC3_H

#endif  // GAME_MAIN_REL_CAR_TYPES_H

/* end game/main_rel/car_types.h */

typedef struct Sig_fn_1_8B10_CameraOutput {
    f32 x0;
    f32 y0;
    s16 flags0;
    u8 pad_0A[2];
    f32 x1;
    f32 y1;
    s16 flags1;
    u8 pad_16[2];
    f32 x2;
    f32 y2;
    s16 flags2;
} Sig_fn_1_8B10_CameraOutput;
typedef struct Sig_fn_1_8B10_fn_1_8B10_CameraObject {
    s16 pad_00;
    s16 kind;
    u8 pad_04[0xA0];
    s16 index;
} Sig_fn_1_8B10_fn_1_8B10_CameraObject;

typedef struct fn_1_8D08_Vec { f32 x, y, z; } fn_1_8D08_Vec;

typedef struct fn_1_8D08_Camera {
    s16 unk_00;
    s16 index;            /* 0x02 */
    s16 unk_04;
    s16 angle;            /* 0x06 */
    f32 unk_08;
    f32 unk_0C;
    fn_1_8D08_Vec pos;    /* 0x10 */
    u8 pad_1C[0xC];
    fn_1_8D08_Vec look;   /* 0x28 */
    f32 mtx[3][4];        /* 0x34 */
    fn_1_8D08_Vec unk_64;
    f32 lerp;             /* 0x70 */
    u8 pad_74[4];
    s16 unk_78;
    u8 pad_7A[2];
    f32 unk_7C;
    f32 unk_80;
    f32 unk_84;
    s32 unk_88;
    fn_1_8D08_Vec target; /* 0x8C */
    fn_1_8D08_Vec unk_98;
    s16 mode;             /* 0xA4 */
    s16 prevMode;         /* 0xA6 */
    u16 unk_A8;
    u8 pad_AA[0x1E4 - 0xAA];
    fn_1_8D08_Vec unk_1E4;
    f32 unk_1F0;
    f32 unk_1F4;
    s16 unk_1F8;
    s16 unk_1FA;
} fn_1_8D08_Camera;

extern f32 fn_1_A888(fn_1_8D08_Camera *);
extern s32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern u32 fn_1_F2F34(void);
extern void lbl_8006E1C0(fn_1_8D08_Vec *, fn_1_8D08_Vec *);
extern void mathutil_mtxA_rotate_x(s16);
extern u8 fn_1_FA4C0(void);
extern void lbl_8006DC6C(void *);
extern void fn_1_862D4(s16, fn_1_8D08_Vec *);
extern void fn_1_8636C(s16, void *);
extern void fn_1_8A0C(s16);
extern void fn_1_8B10(Sig_fn_1_8B10_fn_1_8B10_CameraObject *, Sig_fn_1_8B10_CameraOutput *);

/* Native shared literal pool, including the preceding camera literals. */
const f32 fzgx_pool_fzgx_camera_literal_0 = 0.3f;
const f32 fzgx_pool_fzgx_camera_literal_1 = 1.1f;
const u32 fzgx_pool_fzgx_camera_up_x[1] = {0};
const u32 fzgx_pool_fzgx_camera_up_y[1] = {0x3F800000};
const u32 fzgx_pool_fzgx_camera_up_z[1] = {0};
const fn_1_8D08_Vec fzgx_pool_fzgx_camera_target = {0.0f, 0.0f, 0.0f};
const u32 fzgx_pool_fzgx_camera_fwd_x[1] = {0};
const u32 fzgx_pool_fzgx_camera_fwd_y[1] = {0};
const u32 fzgx_pool_fzgx_camera_fwd_z[1] = {0xBF800000};
const f32 fzgx_pool_fzgx_camera_height[1] = {55.0f};
const f32 fzgx_pool_fzgx_camera_zero[1] = {0.0f};
const f32 fzgx_pool_fzgx_camera_distance[1] = {-10.0f};
const f64 fzgx_pool_fzgx_camera_half[1] = {0.5};

/* translate the locked-cache matrix A */
static inline void mtxA_set_translate(fn_1_8D08_Vec *v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

/* look point: matrix A applied to (0, 0, -10) */
#define camera_update_look(cam) { \
    /* Read the scale before the locked-cache matrix column. */ \
    dist = *(volatile f32 *)fzgx_pool_fzgx_camera_distance; \
    /* Preserve locked-cache matrix access order. */ \
    x = *(volatile f32 *)(0xE0000000 + 0x08); \
    x = x * dist + *(f32 *)(0xE0000000 + 0x0C); \
    y = *(f32 *)(0xE0000000 + 0x18); \
    y = y * dist + *(f32 *)(0xE0000000 + 0x1C); \
    z = *(f32 *)(0xE0000000 + 0x28); \
    z = z * dist + *(f32 *)(0xE0000000 + 0x2C); \
    cam->look.x = x; \
    cam->look.y = y; \
    cam->look.z = z; \
}

static inline f32 fn_1_8D08_look_z(f32 distance) {
    f32 value = *(f32 *)(0xE0000000 + 0x28);
    value = value * distance + *(f32 *)(0xE0000000 + 0x2C);
    return value;
}
static inline f32 fn_1_8D08_read_pointer(fn_1_8D08_Camera * owner) { return owner->lerp; }
static inline f32 (* fn_1_8D08_read_pointer_(fn_1_8D08_Camera * owner))[4] { return owner->mtx; }
static inline f32 (* fn_1_8D08_read_pointer__(fn_1_8D08_Camera * owner))[4] { return owner->mtx; }
#pragma opt_lifetimes off
void fn_1_8D08(fn_1_8D08_Camera *cam, f32 arg1) {
    f32 z;
    f32 y;
    f32 x;
    f32 dist;
    Sig_fn_1_8B10_CameraOutput out;
    f32 mtx[3][4];
    fn_1_8D08_Vec pos;

    cam->unk_A8 = 0;
    cam->mode = 1;
    if ((u32)fn_1_58C4() == 1 && (s32)fn_1_F2F34() == 0) {
        cam->mode = fn_1_FA4C0();
    }
    cam->prevMode = cam->mode;
    fn_1_8B10((Sig_fn_1_8B10_fn_1_8B10_CameraObject *)cam, &out);
    fn_1_862D4(cam->index, &pos);
    fn_1_8636C(cam->index, fn_1_8D08_read_pointer__(cam));
    lbl_8006DC6C(fn_1_8D08_read_pointer_(cam));
    {
        f32 fzgx_lc0_z;
        f32 fzgx_lc0_y;
        f32 fzgx_lc0_x;
        /* Capture the first coordinate before the remaining matrix-translation loads. */
        fzgx_lc0_x = *(volatile f32 *)&((&pos)->x);
        fzgx_lc0_y = (&pos)->y;
        fzgx_lc0_z = (&pos)->z;
        /* Locked-cache stores must complete before copying the pool vector. */
        /* Preserve locked-cache matrix access order. */
        *(volatile f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
        /* Preserve locked-cache matrix access order. */
        *(volatile f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
        /* Preserve locked-cache matrix access order. */
        *(volatile f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
    }
    {
        fn_1_8D08_Vec up;
        u32 c, b, a;
        /* Ordered word copy following the locked-cache stores. */
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        a = *(volatile const u32 *)fzgx_pool_fzgx_camera_up_x;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        b = *(volatile const u32 *)fzgx_pool_fzgx_camera_up_y;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        c = *(volatile const u32 *)fzgx_pool_fzgx_camera_up_z;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((volatile u32 *)&up)[0] = a;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((volatile u32 *)&up)[1] = b;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((volatile u32 *)&up)[2] = c;
        lbl_8006E1C0(&up, &cam->unk_64);
    }
    {
        fn_1_8D08_Vec target = fzgx_pool_fzgx_camera_target;
        target.y = out.x0;
        target.z = out.y0;
        cam->target = target;
    }
    cam->angle = out.flags0;
    cam->unk_08 = fzgx_pool_fzgx_camera_height[0];
    cam->unk_0C = arg1;
    cam->unk_84 = fzgx_pool_fzgx_camera_zero[0];
    cam->unk_78 = 0;
    cam->unk_7C = fzgx_pool_fzgx_camera_zero[0];
    cam->unk_80 = fzgx_pool_fzgx_camera_zero[0];
    cam->unk_88 = 0;
    lbl_8006DC6C(fn_1_8D08_read_pointer__(cam));
    {
        f32 fzgx_lc1_z;
        f32 fzgx_lc1_y;
        f32 fzgx_lc1_x;
        /* Capture the first coordinate before the remaining matrix-translation loads. */
        fzgx_lc1_x = *(volatile f32 *)&((&pos)->x);
        fzgx_lc1_y = (&pos)->y;
        fzgx_lc1_z = (&pos)->z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc1_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc1_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc1_z;
    }
    lbl_8006E1B0((Fn183D28Vec3 *)&cam->target, (Fn183D28Vec3 *)&cam->pos);
    lbl_8006DC6C(fn_1_8D08_read_pointer__(cam));
    {
        f32 fzgx_lc2_z;
        f32 fzgx_lc2_y;
        f32 fzgx_lc2_x;
        /* Capture the first coordinate before the remaining matrix-translation loads. */
        fzgx_lc2_x = *(volatile f32 *)&((&cam->pos)->x);
        fzgx_lc2_y = (&cam->pos)->y;
        fzgx_lc2_z = (&cam->pos)->z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc2_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc2_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc2_z;
    }
    mathutil_mtxA_rotate_x(cam->angle);
    camera_update_look(cam);
    cam->unk_1E4 = cam->pos;
    cam->unk_1F0 = fzgx_pool_fzgx_camera_zero[0];
    cam->unk_1F4 = fzgx_pool_fzgx_camera_zero[0];
    cam->unk_1FA = 0;
    /* Complete initialization before the ordered forward-vector copy. */
    /* Preserve ordered vector initialization around the locked-cache accesses. */
    *(volatile s16 *)&cam->unk_1F8 = -1;
    {
        u32 b, a;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        a = *(volatile const u32 *)fzgx_pool_fzgx_camera_fwd_x;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        b = *(volatile const u32 *)fzgx_pool_fzgx_camera_fwd_y;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((volatile u32 *)&cam->unk_98)[0] = a;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((volatile u32 *)&cam->unk_98)[1] = b;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        b = *(volatile const u32 *)fzgx_pool_fzgx_camera_fwd_z;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((volatile u32 *)&cam->unk_98)[2] = b;
    }
    {
        fn_1_8D08_Vec pos2;
        fn_1_862D4(cam->index, &pos2);
        fn_1_8636C(cam->index, mtx);
        lbl_8006DC6C(mtx);
        {
            f32 fzgx_lc3_z;
            f32 fzgx_lc3_y;
            f32 fzgx_lc3_x;
            /* Capture the first coordinate before the remaining matrix-translation loads. */
            fzgx_lc3_x = *(volatile f32 *)&((&pos2)->x);
            fzgx_lc3_y = (&pos2)->y;
            fzgx_lc3_z = (&pos2)->z;
            *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc3_x;
            *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc3_y;
            *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc3_z;
        }
    }
    cam->lerp = fn_1_A888(cam);
    cam->unk_78 = 0;
    if (cam->mode < 5) {
        cam->target.y = cam->target.y + (f32)(cam->lerp * (out.x2 - cam->target.y));
        cam->target.z = cam->target.z + (f32)(cam->lerp * (out.y2 - cam->target.y));
        {
            f64 angle = cam->angle;
            f32 delta;
            f32 weight = fn_1_8D08_read_pointer(cam);
            f32 step;
            f64 half;
            delta = out.flags2 - cam->angle;
            step = weight * delta;
            half = step * fzgx_pool_fzgx_camera_half[0];
#pragma fp_contract off
            cam->angle = angle + half;
#pragma fp_contract on
        }
        lbl_8006DC6C(fn_1_8D08_read_pointer__(cam));
        {
            f32 fzgx_lc4_z;
            f32 fzgx_lc4_y;
            f32 fzgx_lc4_x;
            /* Capture the first coordinate before the remaining matrix-translation loads. */
            fzgx_lc4_x = *(volatile f32 *)&((&pos)->x);
            fzgx_lc4_y = (&pos)->y;
            fzgx_lc4_z = (&pos)->z;
            *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc4_x;
            *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc4_y;
            *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc4_z;
        }
        lbl_8006E1B0((Fn183D28Vec3 *)&cam->target, (Fn183D28Vec3 *)&cam->pos);
        lbl_8006DC6C(fn_1_8D08_read_pointer__(cam));
        {
            f32 fzgx_lc5_z;
            f32 fzgx_lc5_y;
            f32 fzgx_lc5_x;
            /* Capture the first coordinate before the remaining matrix-translation loads. */
            fzgx_lc5_x = *(volatile f32 *)&((&cam->pos)->x);
            fzgx_lc5_y = (&cam->pos)->y;
            fzgx_lc5_z = (&cam->pos)->z;
            *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc5_x;
            *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc5_y;
            *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc5_z;
        }
        mathutil_mtxA_rotate_x(cam->angle);
        {
            f32 look_z;
            /* Read the scale before the locked-cache matrix column. */
            dist = *(volatile f32 *)fzgx_pool_fzgx_camera_distance;
            /* Preserve locked-cache matrix access order. */
            x = *(volatile f32 *)(0xE0000000 + 0x08);
            x = x * dist + *(f32 *)(0xE0000000 + 0x0C);
            y = *(f32 *)(0xE0000000 + 0x18);
            /* Preserve matrix-column load order. */
            /* Preserve locked-cache matrix access order. */
            z = *(volatile f32 *)(0xE0000000 + 0x1C);
            y = y * dist + z;
            look_z = *(f32 *)(0xE0000000 + 0x28);
            look_z = look_z * dist + *(f32 *)(0xE0000000 + 0x2C);
            cam->look.x = x;
            cam->look.y = y;
            cam->look.z = look_z;
        }
    }
    fn_1_8A0C(fn_1_5910());
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_8D08 */

/* fzgx:begin fn_1_A888 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
    s = 1.100000023841858f;
}
static const u32 fzgx_pool_table2[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
    s = 0.0f;
    s = -10.0f;
    d = 0.5;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table4[18] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40400000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1500.0f;
    s = 53.0f;
    s = 3.0f;
    s = 0.009999999776482582f;
    d = 0.05;
    s = 3.9999998989515007e-05f;
    s = 80.0f;
    s = 108.0f;
    s = 1.350000023841858f;
    s = 90.0f;
    s = 1.2000000476837158f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 0.05000000074505806f;
    s = 0.10000000149011612f;
    d = 0.15;
    s = 1.0f;
    s = 182.04444885253906f;
    s = 0.4000000059604645f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.12;
    s = 5000.0f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.2;
    d = 1.4;
    d = 1.7;
    d = 0.08;
    d = 0.2;
    d = 0.04;
    s = 0.5f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    s = 1.5f;
    s = 2.299999952316284f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3;
    d = 55.0;
    d = 150.0;
    s = 65.0f;
    s = 0.00023668639187235385f;
    s = 60.0f;
    s = 0.00027777778450399637f;
    d = 7.19;
    s = 5.0f;
    s = 2.940000057220459f;
    d = 4503599627370496.0;
    s = -13.0f;
    s = -20.0f;
    s = 13.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 3.0;
}
#pragma section code_type ".text"

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct Self {
    u8 pad_0[0x2];
    s16 id;
    u8 pad_4[0x6C];
    f32 fov;
};

struct Ent {
    u8 pad_0[0x7C];
    u32 flags;
};

struct Pool {
    f32 a_000;
    u8 pad_004[0x2C];
    f32 a_030;
    u8 pad_034[0xCC];
    f64 b_100;
    u8 pad_108[0x10];
    f64 b_118;
    u8 pad_120[0x70];
    f32 a_190;
    f32 a_194;
    f32 a_198;
    u8 pad_19C[0x4];
    f64 b_1A0;
    f64 b_1A8;
};

struct Big {
    u8 pad_0[0x30];
};

const f32 fzgx_pool_lbl_1_rodata_200 = 0.300000012f;
const u8 fzgx_pool_lbl_1_rodata_204[44] = {0x3F,0x8C,0xCC,0xCD,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xBF,0x80,0x00,0x00,0x42,0x5C,0x00,0x00};
const f32 fzgx_pool_lbl_1_rodata_230 = 0.0f;
const u8 fzgx_pool_lbl_1_rodata_230__fzgx_offset_4[172] = {0xC1,0x20,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0x30,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0xBB,0x80,0x00,0x42,0x54,0x00,0x00,0x40,0x40,0x00,0x00,0x3C,0x23,0xD7,0x0A,0x3F,0xA9,0x99,0x99,0x99,0x99,0x99,0x9A,0x38,0x27,0xC5,0xAC,0x42,0xA0,0x00,0x00,0x42,0xD8,0x00,0x00,0x3F,0xAC,0xCC,0xCD,0x42,0xB4,0x00,0x00,0x3F,0x99,0x99,0x9A,0x3E,0x4C,0xCC,0xCD,0x00,0x00,0x00,0x00,0x3F,0x84,0x7A,0xE1,0x47,0xAE,0x14,0x7B,0x3D,0x4C,0xCC,0xCD,0x3D,0xCC,0xCC,0xCD,0x3F,0xC3,0x33,0x33,0x33,0x33,0x33,0x33};
const u8 fzgx_pool_lbl_1_rodata_2E0[32] = {0x3F,0x80,0x00,0x00,0x43,0x36,0x0B,0x61,0x3E,0xCC,0xCC,0xCD,0x00,0x00,0x00,0x00,0x3F,0xBE,0xB8,0x51,0xEB,0x85,0x1E,0xB8,0x45,0x9C,0x40,0x00,0x00,0x00,0x00,0x00};
const f64 fzgx_pool_lbl_1_rodata_2E0__fzgx_offset_20 = 1.2;
const u8 fzgx_pool_lbl_1_rodata_2E0__fzgx_offset_28[16] = {0x3F,0xF6,0x66,0x66,0x66,0x66,0x66,0x66,0x3F,0xFB,0x33,0x33,0x33,0x33,0x33,0x33};
const f64 fzgx_pool_lbl_1_rodata_2E0__fzgx_offset_38 = 0.080000000000000002;
const u8 fzgx_pool_lbl_1_rodata_2E0__fzgx_offset_40[64] = {0x3F,0xC9,0x99,0x99,0x99,0x99,0x99,0x9A,0x3F,0xA4,0x7A,0xE1,0x47,0xAE,0x14,0x7B,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xB9,0x99,0x99,0x99,0x99,0x99,0x9A,0x3F,0xC0,0x00,0x00,0x40,0x13,0x33,0x33,0x3F,0x33,0x33,0x33,0x00,0x00,0x00,0x00,0x3F,0xD3,0x33,0x33,0x33,0x33,0x33,0x33,0x40,0x4B,0x80,0x00,0x00,0x00,0x00,0x00};
const u8 fzgx_pool_lbl_1_rodata_360[40] = {0x40,0x62,0xC0,0x00,0x00,0x00,0x00,0x00,0x42,0x82,0x00,0x00,0x39,0x78,0x2F,0x05,0x42,0x70,0x00,0x00,0x39,0x91,0xA2,0xB4,0x40,0x1C,0xC2,0x8F,0x5C,0x28,0xF5,0xC3,0x40,0xA0,0x00,0x00,0x40,0x3C,0x28,0xF6};
const u8 fzgx_pool_lbl_1_rodata_388[8] = {0x43,0x30,0x00,0x00,0x00,0x00,0x00,0x00};
const f32 fzgx_pool_lbl_1_rodata_388__fzgx_offset_8 = -13.0f;
const f32 fzgx_pool_lbl_1_rodata_388__fzgx_offset_C = -20.0f;
const f32 fzgx_pool_lbl_1_rodata_388__fzgx_offset_10 = 13.0f;
const u8 fzgx_pool_lbl_1_rodata_388__fzgx_offset_14[4] = {0x00,0x00,0x00,0x00};
const f64 fzgx_pool_lbl_1_rodata_388__fzgx_offset_18 = 0.0;
const f64 fzgx_pool_lbl_1_rodata_388__fzgx_offset_20 = 3.0;
const u8 fzgx_pool_lbl_1_rodata_388__fzgx_offset_28[80] = {0x3F,0x94,0x7A,0xE1,0x47,0xAE,0x14,0x7B,0x42,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x60,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xE8,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xE9,0x99,0x99,0x99,0x99,0x99,0x9A,0x3F,0xE7,0x0A,0x3D,0x70,0xA3,0xD7,0x0A};
extern void lbl_8006DAEC(void *);
extern void *fn_1_8627C(s32);
extern void fn_1_862D4(void *, struct Vec3 *);
extern void fn_1_8636C(s32, void *);
extern void *lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern int fn_1_20A5C(void *, void *);
extern u32 fn_1_15578(void *, void *, void *, void *, u32, void *, u32, u32, u32, u32);
extern u32 fn_8006E250(void *, void *);
extern void lbl_8006DB30(void);

static inline void fn_1_A888_setpos(f32 z, f32 y, f32 x) {
    *(f32 *)(0xE0000000 + 0x0C) = x;  /* fzgx-allow: A2 locked matrix, retail lis 0xe000 base */
    *(f32 *)(0xE0000000 + 0x1C) = y;  /* fzgx-allow: A2 locked matrix, retail lis 0xe000 base */
    *(f32 *)(0xE0000000 + 0x2C) = z;  /* fzgx-allow: A2 locked matrix, retail lis 0xe000 base */
}

static inline void fn_1_A888_setpos2(f32 a, f32 b, f32 c) {
    *(f32 *)(0xE0000000 + 0x0C) = a;  /* fzgx-allow: A2 locked matrix, retail lis 0xe000 base */
    *(f32 *)(0xE0000000 + 0x1C) = b;  /* fzgx-allow: A2 locked matrix, retail lis 0xe000 base */
    *(f32 *)(0xE0000000 + 0x2C) = c;  /* fzgx-allow: A2 locked matrix, retail lis 0xe000 base */
}

#pragma opt_common_subs on
#pragma opt_propagation off
f32 fn_1_A888(void *arg0) {
    f32 fzgx_live_;
    f32 *fzgx_value;
    f64 fzgx_live;
    struct Pool *pool;
    struct Self *self = (struct Self *)arg0;
    struct Ent *ent;
    s32 flag;
    u32 w3;
    u32 w2;
    volatile u32 z1;  /* fzgx-allow: retail keeps these dead zero stores */
    struct Vec3 pos;
    volatile u32 z0;  /* fzgx-allow: retail keeps these dead zero stores */
    struct Vec3 v3c;
    struct Vec3 v30;
    struct Vec3 v24;
    struct Vec3 v18;
    struct Big big;
    f32 res;
    f64 t;
    struct { f64 value; } val;
    f32 cur;
    f64 delta;
    f64 scaled;

    lbl_8006DAEC(self);
    ent = fn_1_8627C((s32)self->id);
    if (ent == 0) {
        return (0.0f);
    }
    flag = (s32)(((*(u32 *)((u8 *)ent + 0x7C)) >> 24) & 1);
    fn_1_862D4((void *)(s32)self->id, &pos);
    fn_1_8636C((s32)self->id, &big);
    lbl_8006DC6C(&big);

    fzgx_live = pos.x;
    fzgx_live_ = pos.y;
    fn_1_A888_setpos(pos.z, fzgx_live_, fzgx_live);

    fzgx_value = &(v3c.x);
    *fzgx_value = (0.0f);
    v3c.y = (-13.0f);
    v3c.z = (-20.0f);
    lbl_8006E1B0(&v3c, &v30);

    v3c.y = (13.0f);
    lbl_8006E1B0(&v3c, &v24);

    w3 = (u32)fn_1_20A5C(&v24, &w2);
    fn_1_15578(&v30, &v24, &w2, &v18, 0x80000 + 1, &w3, 1, 0, 0, 0);
    lbl_8006DC6C(&big);

{
    f64 fzgx_live_2;
    fzgx_live_2 = pos.x;
    fzgx_live_ = pos.y;
    fn_1_A888_setpos2(fzgx_live_2, fzgx_live_, pos.z);
}
    fn_8006E250(&v30, &v30);

    t = (1.2) + v30.y;
    if (t < (0.0)) {
        val.value = (0.0);
    } else if (t > (3.0)) {
        val.value = (3.0);
    } else {
        val.value = t;
    }
    res = (f32)val.value / (3.0);
    if (flag) {
        res = (0.300000012f);
    }
    cur = self->fov;
    scaled = (0.080000000000000002) * (res - cur);
    self->fov = (f32)(cur + scaled);
    lbl_8006DB30();
    return res;
}
#pragma opt_propagation reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_A888 */

/* fzgx:begin fn_1_AA54 noprologue */
#include "types.h"

struct fn_1_AA54_Arg0 {
    u8 pad_0[0x2];
    s16 unk_2;
};
struct fn_1_AA54_lbl_1_rodata_388 {
    f64 unk_0;
};
extern f64 lbl_1_rodata_360;
extern s16 lbl_1_bss_960;
extern struct fn_1_AA54_lbl_1_rodata_388 lbl_1_rodata_388;
extern u8 fn_1_86678(int);
extern s8 fn_1_86634(int);
extern s16 camera_get_entry_field_0xa8(u32);
extern u32 fn_1_864E8(int);
extern void camera_set_entry_field_0xa8(u8, s16);
extern u16 fn_1_8664C(int);


void fn_1_AA54(void *arg0) {
    s16 temp_r28;
    u8 temp_r31;
    u8 temp_r3;

    temp_r31 = fn_1_86678((s32) (*(s16 *)((u8 *)(arg0) + 2)));
    temp_r3 = fn_1_86634((s32) (*(s16 *)((u8 *)(arg0) + 2)));
    temp_r28 = camera_get_entry_field_0xa8((u32) temp_r3);
    if (((s16) (*(s16 *)((u8 *)(&lbl_1_bss_960) + 0)) != 9) && (fn_1_864E8((s32) (*(s16 *)((u8 *)(arg0) + 2))) & 0x10000)) {
        camera_set_entry_field_0xa8(temp_r3, 2);
        return;
    }
    if (!(fn_1_864E8((s32) (*(s16 *)((u8 *)(arg0) + 2))) & 1)) {
        if (fn_1_864E8((s32) (*(s16 *)((u8 *)(arg0) + 2))) & 0x800) {
            camera_set_entry_field_0xa8(temp_r3, 5);
            return;
        }
        if (!(fn_1_864E8((s32) (*(s16 *)((u8 *)(arg0) + 2))) & 0x80)) {
            goto block_7; /* Preserves the retail branch. */
        }
    } else {
block_7:
        if ((f64) (*(f64 *)((u8 *)(&lbl_1_rodata_360) + 0)) == (f64) (f64) fn_1_8664C((s32) (*(s16 *)((u8 *)(arg0) + 2)))) {
            camera_set_entry_field_0xa8(temp_r3, 3);
            return;
        }
        if (fn_1_8664C((s32) (*(s16 *)((u8 *)(arg0) + 2))) == 0x14) {
            camera_set_entry_field_0xa8(temp_r3, 0);
            return;
        }
        if ((s8) temp_r31 >= 0) {
            camera_set_entry_field_0xa8(temp_r3, temp_r28);
        }
    }
}
/* fzgx:end fn_1_AA54 */

/* fzgx:begin fn_1_ABAC noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[0xA2];
    s16 unk_A6;
    s16 unk_A8;
} ABACObject;
typedef struct {
    u8 pad_0[0x214];
    u16 unk_214;
} ABACState;

extern ABACState *fn_1_86254(int);
extern s32 fn_1_F2F34(void);
extern s32 camera_get_entry_field_0xa4(u32);
extern u16 fn_1_86678(int);
extern s8 fn_1_86634(int);
extern void fn_1_715C(u8, s32);
extern u32 fn_1_864E8(int);
extern s32 fn_1_40BB4(void);
extern u8 lbl_1_bss_CC0[152];

typedef union {
    u16 raw;
    struct {
        u16 pad:12;
        u16 decrease:1;
        u16 increase:1;
        u16 rest:2;
    } bits;
} ABACFlags;
static inline u32 abac_increase(u16 raw) {
    return (raw >> 2) & 1;
}
static inline u32 abac_decrease(u16 raw) {
    return (raw >> 3) & 1;
}
typedef struct {
    u8 pad:6;
    u8 increase:1;
    u8 decrease:1;
} ABACByteFlags;

#pragma opt_strength_reduction off
void fn_1_ABAC(ABACObject *arg0) {
    u16 controller;
    ABACState *state;
    s8 camera;
    struct { s32 value; } value;

    state = fn_1_86254(arg0->unk_2);
    if (fn_1_F2F34()) {
        controller = 0;
        camera = 0;
        value.value = camera_get_entry_field_0xa4(0);
    } else {
        controller = fn_1_86678(arg0->unk_2);
        camera = fn_1_86634(arg0->unk_2);
        value.value = camera_get_entry_field_0xa4((u8)camera);
    }
    if (state->unk_214 > 1) {
        fn_1_715C(camera, 5);
    } else if (1 == state->unk_214) {
        fn_1_715C(camera, arg0->unk_A6);
    } else if (fn_1_864E8(arg0->unk_2) & 0x80) {
        fn_1_715C(camera, 5);
    } else {
        arg0->unk_A6 = value.value;
        if ((s8)controller != -1 && *(s16 *)&lbl_1_bss_960 != 10 && !fn_1_40BB4()) {
            if (fn_1_F2F34()) {
                /* Volatile input flags are sampled separately for each direction. */
                if (abac_increase(*(volatile u16 *)((u8 *)&lbl_1_bss_9F8.unk_10 + (s8)controller * 0x14)) ||
                    abac_increase(((Obj_1_bss_9F8 *)((u8 *)&lbl_1_bss_9F8 + (s8)controller * 0x14))->unk_12)) {
                    value.value = value.value + 1;
                }
                /* Volatile input flags are sampled separately for each direction. */
                if (abac_decrease(*(volatile u16 *)((u8 *)&lbl_1_bss_9F8.unk_10 + (s8)controller * 0x14)) ||
                    abac_decrease(((Obj_1_bss_9F8 *)((u8 *)&lbl_1_bss_9F8 + (s8)controller * 0x14))->unk_12)) {
                    value.value = value.value - 1;
                }
            } else {
                if (((ABACByteFlags *)&lbl_1_bss_CC0[(s8)controller])->increase) {
                    value.value = (s16)(((1) + (value.value)));
                }
                if (((ABACByteFlags *)&lbl_1_bss_CC0[(s8)controller])->decrease) {
                    value.value = value.value - 1;
                }
            }
            if ((s16)value.value <= 0) value.value = 0;
            if (arg0->unk_A8 == 1) {
                if ((u32)(s16)value.value >= 12) value.value = 11;
            } else {
                if ((u32)(s16)value.value >= 4) value.value = 3;
            }
            fn_1_715C(camera, value.value);
        }
    }
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_ABAC */

/* fzgx:begin camera_get_position_delta */
typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

extern void fn_1_862D4(u8 index, Vec3 *out);
extern void fn_1_8658C(u8 index, Vec3 *out);

// Computes the displacement between two camera positions.
void camera_get_position_delta(u32 index, Vec3 *out) {
    u8 idx = (u8)index;
    Vec3 first;
    Vec3 second;

    fn_1_862D4(idx, &first);
    fn_1_8658C(idx, &second);
    out->x = first.x - second.x;
    out->y = first.y - second.y;
    out->z = first.z - second.z;
}
/* fzgx:end camera_get_position_delta */

/* fzgx:begin camera_reset_transition */
typedef struct camera_reset_transition_Camera {
    u8 pad_00[0xA4];
    s16 unk_A4;
} camera_reset_transition_Camera;

extern void fn_1_AEB8(camera_reset_transition_Camera *);

// Resets the camera transition state before refreshing the camera.
void camera_reset_transition(camera_reset_transition_Camera *camera) {
    camera->unk_A4 = 0;
    fn_1_AEB8(camera);
}
/* fzgx:end camera_reset_transition */

/* fzgx:begin camera_update_transition */
typedef struct camera_update_transition_Camera {
    u8 pad_00[0x78];
    s16 unk_78;
    u8 pad_7A[0x2A];
    s16 unk_A4;
} camera_update_transition_Camera;

extern void fn_1_AEB8(camera_update_transition_Camera *);
extern void fn_1_AFC8(camera_update_transition_Camera *);

// Advances the camera's transition state and updates its active view.
void camera_update_transition(camera_update_transition_Camera *camera) {
    if (camera->unk_78 == 0) {
        camera->unk_A4++;
        if (camera->unk_A4 >= camera_transition_count) {
            camera->unk_A4 = 0;
        }
        fn_1_AEB8(camera);
    }

    fn_1_AFC8(camera);

    if (camera->unk_78 != 0) {
        camera->unk_78--;
    }
}
/* fzgx:end camera_update_transition */

/* fzgx:begin fn_1_AEB8 noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;


typedef unsigned long u32;


typedef float f32;


extern s16 lbl_1_bss_960;


extern s16 camera_transition_count;


extern u8 lbl_1_data_3BD0[0x498];
typedef struct {
u32 unk_0;
f32 unk_4;
u32 unk_8;
u32 unk_C;
u32 unk_10;
u32 unk_14;
u32 unk_18;
u32 unk_1C;
u32 unk_20;
u32 unk_24;
u32 unk_28;
u32 unk_2C;
u32 unk_30;
u32 unk_34;
u32 unk_38;
u32 unk_3C;
u32 unk_40;
u32 unk_44;
u32 unk_48;
u32 unk_4C;
s16 unk_50;
u8 pad_52[0x152];
} Obj_1_data_3A2C;
extern Obj_1_data_3A2C lbl_1_data_3A2C;


typedef struct { f32 x, y, z; } Vec;
typedef struct {
u8 pad_0[0x8];
f32 unk_8;
u8 pad_C[0x6C];
s16 unk_78;
u8 pad_7A[0x12];
Vec unk_8C;
Vec unk_98;
s16 unk_A4;
u8 pad_A6[0x13E];
Vec unk_1E4;
f32 unk_1F0;
f32 unk_1F4;
u8 pad_1F8[2];
s16 unk_1FA;
} Camera;
typedef struct {
u32 unk_0;
Vec position;
Vec target;
f32 value;
s16 count;
s16 pad;
} TransitionConfig;
typedef struct {
s32 mode;
f32 unk_4;
TransitionConfig config;
u8 pad_2C[0x28];
} TransitionPreset;
void fn_1_AEB8(Camera *camera) {
TransitionPreset *preset;
TransitionConfig config;
Vec position;
s32 index = camera->unk_A4;
if (lbl_1_bss_960 == 14) {
camera_transition_count = 14;
preset = &((TransitionPreset *)lbl_1_data_3BD0)[index];
} else {
camera_transition_count = 5;
preset = &((TransitionPreset *)&lbl_1_data_3A2C)[index];
}
config = preset->config;
position = config.position;
camera->unk_1E4 = position;
camera->unk_1F0 = 0.0f;
camera->unk_1F4 = 0.0f;
camera->unk_78 = preset->mode;
camera->unk_8C = config.position;
camera->unk_98 = config.target;
camera->unk_1FA = config.count;
camera->unk_8 = config.value;
camera->unk_1FA = config.count;
}
/* fzgx:end fn_1_AEB8 */

/* fzgx:begin camera_get_target_orientation */
typedef struct Transform {
    u8 pad_08[0x8];
    f32 unk_08;
    u8 pad_0c[0xc];
    f32 unk_18;
    u8 pad_1c[0xc];
    f32 unk_28;
    u8 pad_2c[0x24];
    u8 unk_50[0x2c];
    u32 unk_7C;
} Transform;

typedef struct CameraStateLocal {
    u8 pad_d4[0xd4];
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
} CameraStateLocal;

typedef struct camera_get_target_orientation_CameraObject {
    u8 pad_49c[0x49c];
    Transform *unk_49C;
} camera_get_target_orientation_CameraObject;

extern Transform *lbl_801A6D00;
extern CameraStateLocal *lbl_801A66CC;

// Updates the camera orientation from the active target transform.
f32 camera_get_target_orientation(camera_get_target_orientation_CameraObject *camera) {
    Transform *target = camera->unk_49C;

    if (target == 0) {
        return lbl_1_rodata_2E0[0];
    }
    if ((target->unk_7C & 0x01800000) == 0) {
        return lbl_1_rodata_2E0[0];
    }

    lbl_801A66CC->unk_D4 = -lbl_801A6D00->unk_08;
    lbl_801A66CC->unk_D8 = -lbl_801A6D00->unk_18;
    lbl_801A66CC->unk_DC = -lbl_801A6D00->unk_28;
    return lbl_8006D6FC(&lbl_801A66CC->unk_D4, &target->unk_50);
}
/* fzgx:end camera_get_target_orientation */

/* fzgx:begin fn_1_B4D4 noprologue */
#include "types.h"
#include "psvec.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
    s = 1.100000023841858f;
}
static const u32 fzgx_pool_table2[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
    s = 0.0f;
    s = -10.0f;
    d = 0.5;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table4[18] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40400000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1500.0f;
    s = 53.0f;
    s = 3.0f;
    s = 0.009999999776482582f;
    d = 0.05;
    s = 3.9999998989515007e-05f;
    s = 80.0f;
    s = 108.0f;
    s = 1.350000023841858f;
    s = 90.0f;
    s = 1.2000000476837158f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 0.05000000074505806f;
    s = 0.10000000149011612f;
    d = 0.15;
    s = 1.0f;
    s = 182.04444885253906f;
    s = 0.4000000059604645f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.12;
    s = 5000.0f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.2;
    d = 1.4;
    d = 1.7;
    d = 0.08;
    d = 0.2;
    d = 0.04;
    s = 0.5f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    s = 1.5f;
    s = 2.299999952316284f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3;
    d = 55.0;
    d = 150.0;
    s = 65.0f;
    s = 0.00023668639187235385f;
    s = 60.0f;
    s = 0.00027777778450399637f;
    d = 7.19;
    s = 5.0f;
    s = 2.940000057220459f;
    d = 4503599627370496.0;
    s = -13.0f;
    s = -20.0f;
    s = 13.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 3.0;
    s = 1.159999966621399f;
    s = 89128.9609375f;
    s = 64.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.513671875f;
}
static const u32 fzgx_pool_table20[7] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0;
    d = 0.75;
    d = 0.8;
    d = 0.72;
}
#pragma section code_type ".text"

typedef struct LiveCameraVec {
    f32 values[3];
} LiveCameraVec;

typedef struct LiveCamera {
    u8 pad_00[0x10];
    LiveCameraVec position;
    u8 pad_1C[0xC];
    LiveCameraVec position2;
    u8 pad_34[0x74];
    s16 unk_A8;
    u8 pad_AA[0x62];
    s32 unk_10C;
    s32 timer;
    LiveCameraVec saved;
    LiveCameraVec offset;
    LiveCameraVec velocity;
    LiveCameraVec saved2;
    LiveCameraVec offset2;
    LiveCameraVec velocity2;
} LiveCamera;

typedef struct LiveCameraPool {
    u8 pad_0[0x1E8];
    f64 damping;
    f64 scale;
    f64 scale2;
} LiveCameraPool;

extern const LiveCameraPool lbl_1_rodata_200;
extern u32 lbl_1_bss_F5C;
extern void fn_1_8840(void);

#pragma opt_loop_invariants off
#pragma opt_lifetimes off
void fn_1_B4D4(LiveCamera *camera) {
    const LiveCameraPool *pool = &lbl_1_rodata_200;
    f64 damping;
    f64 scale;
    f64 scale2;
    f64 product;
    u32 i;
    f64 product_2;
    u32 tmp_ra3;

    if (!(camera->unk_10C)) {
        camera->saved = camera->position;
        camera->saved2 = camera->position2;
    } else {
        if ((lbl_1_bss_F5C & 0x50000000) == 0) {
            damping = (0.75);
            scale = (0.80000000000000004);
            scale2 = (0.71999999999999997);
            for (i = 0; i < 3; i++) {
                product = damping * (f64)(*((camera->offset.values) + (i)));
                camera->velocity.values[i] =
                    (f32)((f64)(*((camera->velocity.values) + (i))) - product);
            }
            for (i = 0; i < 3; i++) {
                camera->velocity.values[i] =
                    (f32)((f64)(*((camera->velocity.values) + (i))) * scale);
            }
            for (i = 0; i < 3; i++) {
                camera->offset.values[i] =
                    (*((camera->offset.values) + (i))) + (*((camera->velocity.values) + (i)));
            }
            {
    u32 fzgx_loop_i_7616;
for (fzgx_loop_i_7616 = 0; fzgx_loop_i_7616 < 3; fzgx_loop_i_7616++) {
                product_2 = scale2 * (f64)(*((camera->offset2.values) + (fzgx_loop_i_7616)));
                camera->velocity2.values[fzgx_loop_i_7616] =
                    (f32)((f64)(*((camera->velocity2.values) + (fzgx_loop_i_7616))) - product_2);
            }
    i = fzgx_loop_i_7616;
}
            for (i = 0; i < 3; i++) {
                camera->velocity2.values[i] =
                    (f32)((f64)(*((camera->velocity2.values) + (i))) * damping);
            }
            for (i = 0; i < 3; i++) {
                camera->offset2.values[i] =
                    (*((camera->offset2.values) + (i))) + (*((camera->velocity2.values) + (i)));
            }
        }
        psvec_add(&camera->saved.values[0], &camera->offset.values[0],
                  &camera->position.values[0]);
        if (!(camera->unk_A8)) {
            psvec_add(&camera->saved2.values[0], &camera->offset2.values[0],
                      &camera->position2.values[0]);
        }
        if ((lbl_1_bss_F5C & 0x50000000) == 0 && camera->timer > 0) {
            camera->timer--;
            tmp_ra3 = camera->timer;
            if ((s32)tmp_ra3 == 0) {
                fn_1_8840();
            }
        }
    }
}
#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_B4D4 */

/* fzgx:begin fn_1_B81C */
struct fn_1_B81C_Copy12 { u32 a[3]; };

void fn_1_B81C(struct fn_1_B81C_Copy12 *first, struct fn_1_B81C_Copy12 *second, u32 value) {
    *(struct fn_1_B81C_Copy12 *)((u8 *)&camera_state + 4) = *first;
    *(struct fn_1_B81C_Copy12 *)((u8 *)&camera_state + 16) = *second;
    camera_state.unk_20 = value;
}
/* fzgx:end fn_1_B81C */

/* fzgx:begin camera_save_parameters */
// Saves the two current camera parameters for later processing.
void camera_save_parameters(f32 first_parameter, f32 second_parameter) {
    lbl_1_bss_1040 = first_parameter;
    lbl_1_bss_1044 = second_parameter;
}
/* fzgx:end camera_save_parameters */

/* fzgx:begin fn_1_B870 noprologue */
#include "types.h"
#include "types.h"

#ifndef GAME_VEC3_H
#define GAME_VEC3_H

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */

typedef struct B870Camera {
    u8 pad_0[0x4];
    Vec3f pos;    /* 0x04 */
    Vec3f lookAt; /* 0x10 */
    f32 fov;      /* 0x1C */
    s16 rotZ;     /* 0x20 */
} B870Camera;

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
} B870Bss_D58;

typedef struct {
    s8 stick[4];
    u8 unk_4;
} B870Bss_A48;

typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[0x4];
    u16 unk_8;
} B870Bss_9F8;

extern B870Bss_D58 lbl_1_bss_D58;
extern B870Bss_A48 lbl_1_bss_A48;
extern B870Bss_9F8 lbl_1_bss_9F8;

/* camera.c's .bss cluster at lbl_1_bss_1010, addressed off one section base. */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
B870Camera camera_state__fzgx_offset_0;
f32 fzgx_obj_lbl_1_bss_103C;
f32 lbl_1_bss_1040;
f32 lbl_1_bss_1044;
u8 camera_flag_0__fzgx_offset_0;
u8 camera_flag_1__fzgx_offset_0;

extern void fn_1_C770(void);
extern void fn_8006EDBC(Vec3f *, Vec3f *, s16 *, s16 *);
extern void lbl_8006D7DC(Vec3f *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_z(s16);
extern void lbl_8006E1B0(Vec3f *, Vec3f *);
extern void fn_8006E250(Vec3f *, Vec3f *);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D0B4(f32);

/* Primer: the .bss order and the literals of earlier camera.c functions, as in retail. */
extern void fzgx_touch_f(f32);
extern void fzgx_touch(void *);
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(void) {
    fzgx_touch(&fzgx_obj_lbl_1_bss_1010);
    fzgx_touch(&lbl_1_bss_1014);
    fzgx_touch(&camera_state__fzgx_offset_0);
    fzgx_touch(&fzgx_obj_lbl_1_bss_103C);
    fzgx_touch(&lbl_1_bss_1040);
    fzgx_touch(&lbl_1_bss_1044);
    fzgx_touch(&camera_flag_0__fzgx_offset_0);
    fzgx_touch(&camera_flag_1__fzgx_offset_0);
    fzgx_touch_f(1.0f);
    fzgx_touch_f(0.1f);
    fzgx_touch_f(0.01f);
    fzgx_touch_f(55.0f);
}

#pragma opt_lifetimes off
void fn_1_B870(void) {
    f32 speed;
    f32 clamped;
    f32 scale;
    s32 rot;
    s32 zoom;
    u32 buttons;
    s16 rotX;
    s16 rotY;

    if ((lbl_1_bss_D58.unk_8 >> 10) & 1) {
        camera_flag_0__fzgx_offset_0 ^= 1;
    }
    if (lbl_1_bss_1014 != 0) {
        fn_1_C770();
        return;
    }
    fn_8006EDBC(&camera_state__fzgx_offset_0.pos, &camera_state__fzgx_offset_0.lookAt, &rotX, &rotY);
    speed = fzgx_obj_lbl_1_bss_103C;
    speed = 0.040000000000000008 * speed;
    speed = speed * (1.0 + 4.0 * lbl_1_bss_A48.unk_4 / 140.0);
    clamped = (speed > 50.0) ? 50.0 : speed;
    {
        Vec3f offsetA = {0.0f, 0.0f, 0.0f};
        Vec3f offsetB = {0.0f, 0.0f, 0.0f};
        Vec3f tmp;

        if (camera_flag_1__fzgx_offset_0 != 0 && !((lbl_1_bss_9F8.unk_0 >> 6) & 1)) {
            offsetA.x = speed * (*((0) + (lbl_1_bss_A48.stick))) / 60.0;
            if ((lbl_1_bss_9F8.unk_2 >> 9) & 1) {
                offsetA.y = clamped * (*((1) + (lbl_1_bss_A48.stick))) / 60.0;
            } else {
                offsetA.z = -clamped * (*((1) + (lbl_1_bss_A48.stick))) / 60.0;
            }
            offsetB.x = speed * (*((2) + (lbl_1_bss_A48.stick))) / 60.0;
            if (((*(volatile u16 *)&lbl_1_bss_9F8.unk_2) >> 9) & 1) { /* Retail reloads the mode for the second stick. */
                offsetB.y = clamped * (*((3) + (lbl_1_bss_A48.stick))) / 60.0;
            } else {
                offsetB.z = -clamped * (*((3) + (lbl_1_bss_A48.stick))) / 60.0;
            }
        }
        lbl_8006D7DC(&camera_state__fzgx_offset_0.pos);
        mathutil_mtxA_rotate_y(rotY);
        mathutil_mtxA_rotate_x(rotX);
        mathutil_mtxA_rotate_z(camera_state__fzgx_offset_0.rotZ);
        lbl_8006E1B0(&offsetA, &camera_state__fzgx_offset_0.pos);
        fn_8006E250(&camera_state__fzgx_offset_0.lookAt, &tmp);
        tmp.x += offsetB.x;
        tmp.y += offsetB.y;
        tmp.z += offsetB.z;
        lbl_8006E1B0(&tmp, &camera_state__fzgx_offset_0.lookAt);
        tmp.x = camera_state__fzgx_offset_0.lookAt.x - camera_state__fzgx_offset_0.pos.x;
        tmp.y = camera_state__fzgx_offset_0.lookAt.y - camera_state__fzgx_offset_0.pos.y;
        tmp.z = camera_state__fzgx_offset_0.lookAt.z - camera_state__fzgx_offset_0.pos.z;
        if (__fmadds(tmp.z, tmp.z, __fmadds(tmp.y, tmp.y, tmp.x * tmp.x)) < 0.09) {
            scale = 0.3 * lbl_8006D0E8(__fmadds(tmp.z, tmp.z, __fmadds(tmp.y, tmp.y, tmp.x * tmp.x)));
            camera_state__fzgx_offset_0.lookAt.x = camera_state__fzgx_offset_0.pos.x + (f32)(tmp.x * scale);
            camera_state__fzgx_offset_0.lookAt.y = camera_state__fzgx_offset_0.pos.y + (f32)(tmp.y * scale);
            camera_state__fzgx_offset_0.lookAt.z = camera_state__fzgx_offset_0.pos.z + (f32)(tmp.z * scale);
        }
    }
    {
        Vec3f *pos = &camera_state__fzgx_offset_0.pos;
        Vec3f *lookAt = &camera_state__fzgx_offset_0.lookAt;
        f32 dx = pos->x;
        f32 dz = pos->z;
        f32 dy = pos->y;
        dx -= lookAt->x;
        dy -= lookAt->y;
        dz -= lookAt->z;
        dx = dx * dx;
        dx = dy * dy + dx;
        dx = dz * dz + dx;
        fzgx_obj_lbl_1_bss_103C = lbl_8006D0B4(dx);
    }
    if (((lbl_1_bss_9F8.unk_2 >> 9) & 1) && camera_flag_1__fzgx_offset_0 != 0) {
        buttons = (*(u16 volatile *)&(lbl_1_bss_9F8.unk_0)) /* Retail reloads this field. */;
        if (buttons & 1) {
            rot = 0x800;
        } else {
            rot = ((buttons >> 1) & 1) ? -0x800 : 0;
        }
{
    B870Camera *cam = &camera_state__fzgx_offset_0;
        cam->rotZ += rot;
}
        buttons = lbl_1_bss_9F8.unk_0;
        if ((buttons >> 2) & 1) {
            zoom = 1;
        } else {
            zoom = ((buttons >> 3) & 1) ? -1 : 0;
        }
        camera_state__fzgx_offset_0.fov += zoom;
        camera_state__fzgx_offset_0.fov = (camera_state__fzgx_offset_0.fov < 0.1) ? 0.1
                           : (camera_state__fzgx_offset_0.fov > 90000.0) ? 90000.0 : camera_state__fzgx_offset_0.fov;
        if ((lbl_1_bss_9F8.unk_8 >> 9) & 1) {
            camera_state__fzgx_offset_0.rotZ = 0;
            camera_state__fzgx_offset_0.fov = 55.0f;
        }
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_B870 */

/* fzgx:begin fn_1_BFA0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern u32 fn_1_CC5C(void);
extern void lbl_8006D9D8(void *);
extern void lbl_8006E14C(f32);
extern void fn_1_55FC4(f32);
extern void fn_80072558(void);
extern void fn_1_55FF0(f32);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_1_55210(u32);

typedef struct CameraUpdateState {
    u8 unk_00[4];
    u8 unk_04;
    u8 unk_05[3];
    u8 unk_08[40];
    f32 unk_30;
    f32 unk_34;
    u8 unk_38;
} CameraUpdateState;

#pragma opt_propagation off
static inline void update_camera_transform(u8 *value) {
    lbl_8006D9D8(value + 0x10);
}

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 fzgx_pool_lbl_1_bss_1010_gap_1015;
u16 fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
u8 fzgx_obj_camera_state;
u8 camera_state__fzgx_offset_1;
u16 camera_state__fzgx_offset_2;
u32 camera_state__fzgx_offset_4[8];
u32 lbl_1_bss_103C;
f32 lbl_1_bss_1040;
f32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&camera_state__fzgx_offset_1;
    s = *(u8 *)&camera_state__fzgx_offset_2;
    s = *(u8 *)&camera_state__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
}
#pragma section code_type ".text"

void fn_1_BFA0(void) {
    
    if (lbl_1_bss_1014 != 0) {
        fn_1_CC5C();
    }
    if (fzgx_obj_camera_flag_0 != 0) {
        update_camera_transform((*(u8 (*)[40])&fzgx_obj_camera_state));
        lbl_8006E14C(lbl_1_bss_1044);
        fn_1_55FC4(lbl_1_bss_1044);
        fn_80072558();
        fn_1_55FF0(lbl_1_bss_1040);
        if (lbl_801A6CE0 & 1) {
            fn_1_55210(*(u32 *)(*(u32 *)(lbl_1_bss_38454 + 8) + 0x20));
        }
    }
}
/* fzgx:end fn_1_BFA0 */

/* fzgx:begin fn_1_C038 */
void fn_1_C038(s32 value, f32 start, f32 end) {
    f32 difference;
    f32 ratio;
    f32 converted;

    difference = end - start;
    ratio = difference / (f32)(((u32)(value * value)) >> 2);

    lbl_1_bss_10C0[0] = start;
    lbl_1_bss_10C0[1] = end;
    lbl_1_bss_10C0[4] = lbl_1_rodata_49C;

    lbl_1_bss_10C0[5] = ratio;
    converted = (f32)(u32)value;
    lbl_1_bss_10C0[3] = converted;
    lbl_1_bss_10C0[2] = converted;
}
/* fzgx:end fn_1_C038 */

/* fzgx:begin camera_save_slot */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} CameraSlot;

// Copies the current camera parameters into the selected camera slot.
void camera_save_slot(u8 index) {
    CameraSlot *dst = (CameraSlot *)&lbl_1_bss_10D8 + index;

    dst->unk_0 = camera_state.unk_0;
    dst->unk_4 = camera_state.unk_4;
    dst->unk_8 = camera_state.unk_8;
    dst->unk_C = camera_state.unk_C;
    dst->unk_10 = camera_state.unk_10;
    dst->unk_14 = camera_state.unk_14;
    dst->unk_18 = camera_state.unk_18;
    dst->unk_1C = camera_state.unk_1C;
    dst->unk_20 = *(u32 *)&camera_state.unk_20;
}
/* fzgx:end camera_save_slot */

/* fzgx:begin fn_1_C10C noprologue */
#include "types.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} CameraPreset;

typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 pad_6[0x2];
    CameraPreset current;
    u8 pad_2C[0x9C];
    CameraPreset presets[1];
} CameraState;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 fzgx_pool_lbl_1_bss_1010_gap_1015;
u16 fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
CameraPreset fzgx_obj_camera_state;
u32 lbl_1_bss_103C;
u32 lbl_1_bss_1040;
u32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 fzgx_pool_lbl_1_bss_1010_gap_104A;
u32 lbl_1_bss_104C[16];
u32 lbl_1_bss_108C[13];
u32 lbl_1_bss_10C0[6];
CameraPreset fzgx_obj_lbl_1_bss_10D8[1];
u32 lbl_1_bss_10D8__fzgx_offset_24[19];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
    s = *(u8 *)&fzgx_obj_camera_flag_1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_24;
}
#pragma section code_type ".text"

void fn_1_C10C(u8 idx) {
    fzgx_pool_lbl_1_bss_1010_gap_1015 = 0;
    fzgx_obj_camera_state = fzgx_obj_lbl_1_bss_10D8[idx];
}
/* fzgx:end fn_1_C10C */

/* fzgx:begin fn_1_C178 noprologue */
#include "types.h"

typedef struct { u8 pad_0[0x4]; f32 unk_4; u32 unk_8; f32 unk_C; } Bss_104C;
typedef struct {
    u8 pad_0[0x4]; f32 unk_4; f32 unk_8; f32 unk_C; f32 unk_10; f32 unk_14; f32 unk_18; f32 unk_1C;
    s16 unk_20; u8 pad_22[0x6]; f32 unk_28; f32 unk_2C; f32 unk_30; f32 unk_34; f32 unk_38; f32 unk_3C; f32 unk_40;
    s16 unk_44; u8 pad_46[0x2A];
} Obj_1_bss_10D8;
extern Bss_104C lbl_1_bss_104C;
extern char lbl_1_data_406C[91];
extern char lbl_1_data_40C8[96];
extern Obj_1_bss_10D8 lbl_1_bss_10D8;
extern void OSReport(char *, ...);

void fn_1_C178(void *self) {
    OSReport(lbl_1_data_406C, lbl_1_bss_104C.unk_8, lbl_1_bss_104C.unk_C,
        lbl_1_bss_10D8.unk_4, lbl_1_bss_10D8.unk_8, lbl_1_bss_10D8.unk_C,
        lbl_1_bss_10D8.unk_10, lbl_1_bss_10D8.unk_14, lbl_1_bss_10D8.unk_18,
        lbl_1_bss_10D8.unk_1C, lbl_1_bss_10D8.unk_20);
    OSReport(lbl_1_data_40C8, lbl_1_bss_10D8.unk_28, lbl_1_bss_10D8.unk_2C,
        lbl_1_bss_10D8.unk_30, lbl_1_bss_10D8.unk_34, lbl_1_bss_10D8.unk_38,
        lbl_1_bss_10D8.unk_3C, lbl_1_bss_10D8.unk_40, lbl_1_bss_10D8.unk_44,
        self);
}
/* fzgx:end fn_1_C178 */

/* fzgx:begin camera_report_position */
// Reports the camera's current position values for debugging.
void camera_report_position(void) {
    OSReport(lbl_1_data_4128, lbl_1_bss_10D8.unk_10,
             lbl_1_bss_10D8.unk_14, lbl_1_bss_10D8.unk_18);
}
/* fzgx:end camera_report_position */

/* fzgx:begin fn_1_C268 noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

extern f64 lbl_1_rodata_4A8[7];
extern void OSReport(const char *format, ...);

#pragma opt_common_subs off
#pragma opt_strength_reduction off
void fn_1_C268(s32 arg) {
    if ((55.0) == lbl_1_bss_10D8.unk_1C) {
        OSReport((char *)lbl_1_data_4144, lbl_1_bss_10D8.unk_4,
                 lbl_1_bss_10D8.unk_8, lbl_1_bss_10D8.unk_C,
                 lbl_1_bss_10D8.unk_28, lbl_1_bss_10D8.unk_2C,
                 lbl_1_bss_10D8.unk_30, lbl_1_bss_10D8.unk_20, arg,
                 lbl_1_bss_10D8.unk_1C);
    } else {
        OSReport((char *)lbl_1_data_4198, lbl_1_bss_10D8.unk_4,
                 lbl_1_bss_10D8.unk_8, lbl_1_bss_10D8.unk_C,
                 lbl_1_bss_10D8.unk_28, lbl_1_bss_10D8.unk_2C,
                 lbl_1_bss_10D8.unk_30, lbl_1_bss_10D8.unk_20, arg,
                 lbl_1_bss_10D8.unk_1C);
    }
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_C268 */

/* fzgx:begin fn_1_C304 */
// Reports the camera parameters and caller-supplied value for debugging.
void fn_1_C304(s32 arg) {
    OSReport(lbl_1_data_4198,
             lbl_1_bss_10D8.unk_4, lbl_1_bss_10D8.unk_8,
             lbl_1_bss_10D8.unk_C, lbl_1_bss_10D8.unk_10,
             lbl_1_bss_10D8.unk_14, lbl_1_bss_10D8.unk_18,
             lbl_1_bss_10D8.unk_20, arg,
             lbl_1_bss_10D8.unk_1C);
}
/* fzgx:end fn_1_C304 */

/* fzgx:begin camera_snapshot noprologue */
#include "types.h"

typedef struct CameraGlobals {
    u8 pad_00[0x08];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u8 pad_2C[0x10];
    u32 unk_3C;
    u8 pad_40[0x88];
    u32 unk_C8;
    u32 unk_CC;
    u32 unk_D0;
    u32 unk_D4;
    u32 unk_D8;
    u32 unk_DC;
    u32 unk_E0;
    u32 unk_E4;
    u32 unk_E8;
} CameraGlobals;

extern CameraGlobals lbl_1_bss_1010;

// Copies the live camera state into its snapshot and resets the snapshot flag.
void camera_snapshot(void) {
    lbl_1_bss_1010.unk_08 = lbl_1_bss_1010.unk_C8;
    lbl_1_bss_1010.unk_0C = lbl_1_bss_1010.unk_CC;
    lbl_1_bss_1010.unk_10 = lbl_1_bss_1010.unk_D0;
    lbl_1_bss_1010.unk_14 = lbl_1_bss_1010.unk_D4;
    lbl_1_bss_1010.unk_18 = lbl_1_bss_1010.unk_D8;
    lbl_1_bss_1010.unk_1C = lbl_1_bss_1010.unk_DC;
    lbl_1_bss_1010.unk_20 = lbl_1_bss_1010.unk_E0;
    lbl_1_bss_1010.unk_24 = lbl_1_bss_1010.unk_E4;
    lbl_1_bss_1010.unk_28 = lbl_1_bss_1010.unk_E8;
    lbl_1_bss_1010.unk_3C = 0;
}
/* fzgx:end camera_snapshot */

/* fzgx:begin fn_1_C3B8 noprologue */
#include "types.h"

typedef struct {
    f32 x, y, z;
} CamVec;

typedef struct {
    u32 unk_0;
    CamVec pos;
    CamVec at;
    f32 unk_1C;
    s16 unk_20;
} CamKey;

typedef struct {
    s32 counter;
    s32 state;
    s32 total;
    f32 rate;
    u8 pad_10[0x30];
} CamCtl;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
} CamSway;

extern void lbl_8006D5A4(CamVec *a, CamVec *b, CamVec *out, f32 t);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 fzgx_pool_lbl_1_bss_1010_gap_1015;
u16 fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
CamKey fzgx_obj_camera_state;
u32 lbl_1_bss_103C;
u32 lbl_1_bss_1040;
u32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 fzgx_pool_lbl_1_bss_1010_gap_104A;
CamCtl lbl_1_bss_104C;
u32 lbl_1_bss_108C[13];
CamSway lbl_1_bss_10C0;
CamKey fzgx_obj_lbl_1_bss_10D8[2];
u32 lbl_1_bss_10D8__fzgx_offset_48[10];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
    s = *(u8 *)&fzgx_obj_camera_flag_1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_48;
}
#pragma section code_type ".text"

void fn_1_C3B8(void) {
    CamKey from = fzgx_obj_lbl_1_bss_10D8[0];
    CamKey to = fzgx_obj_lbl_1_bss_10D8[1];
    f32 t;

    switch (lbl_1_bss_104C.state) {
    case 0:
        t = (f32)lbl_1_bss_104C.counter / (f32)lbl_1_bss_104C.total;
        lbl_8006D5A4(&from.pos, &to.pos, &fzgx_obj_camera_state.pos, t);
        lbl_8006D5A4(&from.at, &to.at, &fzgx_obj_camera_state.at, t);
        fzgx_obj_camera_state.unk_1C = from.unk_1C + (f32)(t * (to.unk_1C - from.unk_1C));
        fzgx_obj_camera_state.unk_20 = from.unk_20 + (s16)(t * (to.unk_20 - from.unk_20));
        if (lbl_1_bss_104C.counter >= lbl_1_bss_104C.total) {
            fzgx_pool_lbl_1_bss_1010_gap_1015 = 0;
        }
        break;
    case 3:
        lbl_1_bss_10C0.unk_8 -= 1.0f;
        if (lbl_1_bss_10C0.unk_8 < lbl_1_bss_10C0.unk_C / 2.0f) {
            lbl_1_bss_10C0.unk_10 -= lbl_1_bss_10C0.unk_14;
        } else {
            lbl_1_bss_10C0.unk_10 += lbl_1_bss_10C0.unk_14;
        }
        t = lbl_1_bss_10C0.unk_0 + lbl_1_bss_10C0.unk_10;
        lbl_1_bss_10C0.unk_0 = t;
        lbl_8006D5A4(&from.pos, &to.pos, &fzgx_obj_camera_state.pos, t);
        lbl_8006D5A4(&from.at, &to.at, &fzgx_obj_camera_state.at, t);
        fzgx_obj_camera_state.unk_1C = from.unk_1C + (f32)(t * (to.unk_1C - from.unk_1C));
        fzgx_obj_camera_state.unk_20 = from.unk_20 + (s16)(t * (to.unk_20 - from.unk_20));
        if (lbl_1_bss_104C.counter >= lbl_1_bss_104C.total) {
            fzgx_pool_lbl_1_bss_1010_gap_1015 = 0;
        }
        break;
    case 2:
        lbl_8006D5A4(&fzgx_obj_camera_state.pos, &to.pos, &fzgx_obj_camera_state.pos, lbl_1_bss_104C.rate);
        lbl_8006D5A4(&fzgx_obj_camera_state.at, &to.at, &fzgx_obj_camera_state.at, lbl_1_bss_104C.rate);
        fzgx_obj_camera_state.unk_1C += (f32)(lbl_1_bss_104C.rate * (to.unk_1C - fzgx_obj_camera_state.unk_1C));
        fzgx_obj_camera_state.unk_20 += (s32)(lbl_1_bss_104C.rate * (to.unk_20 - fzgx_obj_camera_state.unk_20));
        break;
    }
    lbl_1_bss_104C.counter++;
}
/* fzgx:end fn_1_C3B8 */

/* fzgx:begin fn_1_C770 pool noprologue */
#include "types.h"

typedef struct {
    u16 unk_0;
    u8 pad_2[0x6];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
} PadState;

typedef struct {
    u32 w[9];
} CamKey;

typedef struct {
    s32 counter;
    s32 state;
    s32 total;
    f32 rate;
    u8 pad_10[0x30];
} CamCtl;

typedef struct {
    u8 pad_0[0x14];
    f32 unk_14;
} Obj_BF0;

extern PadState lbl_1_bss_D58;
extern f32 lbl_1_bss_BF0[32];
extern void OSReport(const char *, ...);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 lbl_1_bss_1010_gap_1015;
u16 lbl_1_bss_1010_gap_1015_fill_1016;
CamKey fzgx_obj_camera_state;
u32 lbl_1_bss_103C;
u32 lbl_1_bss_1040;
u32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 lbl_1_bss_1010_gap_104A;
CamCtl lbl_1_bss_104C;
u32 lbl_1_bss_108C[13];
u32 lbl_1_bss_10C0[6];
CamKey fzgx_obj_lbl_1_bss_10D8[2];
CamKey lbl_1_bss_1120;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
    s = *(u8 *)&fzgx_obj_camera_flag_1;
    s = *(u8 *)&lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_1120;
}

/* the camera TU's literal pool in retail order, ahead of this function's constants */
static void fzgx_pool_head(f32 *f) {
    f[0] = 1.0f;
    f[1] = 0.1f;
    f[2] = 0.01f;
    f[3] = 55.0f;
}

static const u32 fzgx_pool_table_10[6] = { 0, 0, 0, 0, 0, 0 };

static void fzgx_pool_tail(f64 *d, f32 *f) {
    d[0] = fzgx_pool_table_10[0];
    d[1] = 0.040000000000000008;
    d[2] = 1.0;
    d[3] = 4.0;
    d[4] = 140.0;
    d[5] = 50.0;
    d[6] = 60.0;
    d[7] = 0.09;
    d[8] = 0.3;
    d[9] = 0.1;
    d[10] = 90000.0;
    d[11] = 4503599627370496.0;
    d[12] = 4503601774854144.0;
    d[13] = 0.02;
    f[0] = 60.0f;
    f[1] = 15.0f;
    f[2] = 0.9f;
    f[3] = 0.0f;
    f[4] = 0.5f;
    d[14] = 55.0;
    f[5] = 10.0f;
    d[15] = 0.0;
    d[16] = 0.5;
    d[17] = 0.0001;
}
#pragma section code_type ".text"

u16 lbl_1_data_4068 = 0xF000;
u8 lbl_1_data_406A = 9;
u8 lbl_1_data_406B = 3;

#pragma section code_type ".fzgxpool"
/* this TU's .data in retail order: the menu bytes, then the report strings ahead of this function's */
static void fzgx_data_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink */
    s = lbl_1_data_4068;
    s = lbl_1_data_406A;
    s = lbl_1_data_406B;
    OSReport("\t{ %3d, %1.3f, {  0,{  %8.3f, %8.3f, %8.3f }, {  %8.3f, %8.3f, %8.3f },  %5.1f, %5d, 0,},\n");
    OSReport("\t              {  0,{  %8.3f, %8.3f, %8.3f }, {  %8.3f, %8.3f, %8.3f },  %5.1f, %5d, 0,}, %s},\n");
    OSReport("\t{  %8.3f, %8.3f, %8.3f },\n");
    OSReport("\t{ 00,{  %8.3f, %8.3f, %8.3f }, {  %8.3f, %8.3f, %8.3f }, %5d,  PERS_DEGREE, %s},\n");
    OSReport("\t{ 00,{  %8.3f, %8.3f, %8.3f }, {  %8.3f, %8.3f, %8.3f }, %5d,  %11.3f, %s},\n");
}
#pragma section code_type ".text"

extern void camera_save_slot(u8);
extern void camera_snapshot(void);
extern void fn_1_C038(f32, f32, s32);
extern void fn_1_C10C(u8);
extern void fn_1_C178(void *);
extern void camera_report_position(void);
extern void fn_1_C268(s32);
extern void fn_1_C304(s32);
extern void fn_1_C3B8(void);

/* step v past one end of [lo, hi] and it restarts from the other */
#define WRAP(v, lo, hi) ((v) > (hi) ? (lo) : ((v) < (lo) ? (hi) : (v)))

#pragma opt_common_subs off
static inline s32 menu_wrap(s32 value, s32 direction, s32 amount) {
    value += direction * amount;
    return WRAP(value, 0, 15);
}

static inline s32 menu_prev(s32 item) {
    if (item - 1 > 38) return 0;
    --item;
    return item < 0 ? 38 : item;
}
static inline s32 menu_next(s32 item) {
    if (item + 1 > 38) return 0;
    ++item;
    return item < 0 ? 38 : item;
}
#pragma opt_common_subs on

/* Debug camera menu: up/down picks an item, left/right edits or triggers it. */
void fn_1_C770(void) {
    PadState *pad = &lbl_1_bss_D58;
    s32 item;
    s32 dir;
    s32 step;
    s32 n;
    s32 v;
    f64 f;
    f64 d;

    dir = 0;
    step = 1;
    if ((pad->unk_10 >> 8) & 1) {
        dir = 1;
    } else if ((pad->unk_10 >> 9) & 1) {
        dir = -1;
    }
    if (lbl_1_bss_BF0[5]) {
        step = 10.0f * lbl_1_bss_BF0[5];
    }

    item = lbl_1_data_406B;
    if (item == 1) {
        n = lbl_1_data_406A;
        n += dir * step;
        if (n > 15) {
            v = 0;
        } else {
            v = n < 0 ? 15 : n;
        }
        lbl_1_data_406A = v;
    }
    if (item == 2 && dir != 0) {
        lbl_1_bss_1014 = 0;
    }
    if (item == 3 && dir != 0) {
        camera_save_slot(0);
    }
    if ((s32)lbl_1_data_406B == 4 && dir != 0) {
        camera_save_slot(1);
    }
    if ((s32)lbl_1_data_406B == 5) {
        d = 0.0001 * dir * step;
        f = WRAP(lbl_1_bss_104C.rate + d, 0.0, 0.5);
        lbl_1_bss_104C.rate = f;
    }
    if ((s32)lbl_1_data_406B == 6) {
        v = lbl_1_bss_104C.total + dir * step;
        lbl_1_bss_104C.total = WRAP(v, 0, 1000);
    }
    if ((s32)lbl_1_data_406B == 7 && dir != 0) {
        lbl_1_bss_1010_gap_1015 = 1;
        lbl_1_bss_1120 = fzgx_obj_camera_state;
        lbl_1_bss_104C.state = 0;
        camera_snapshot();
    }
    if ((s32)lbl_1_data_406B == 8 && dir != 0) {
        lbl_1_bss_1010_gap_1015 = 1;
        lbl_1_bss_1120 = fzgx_obj_camera_state;
        lbl_1_bss_104C.state = 3;
        fn_1_C038(0.0f, 1.0f, lbl_1_bss_104C.total);
        camera_snapshot();
    }
    if ((s32)lbl_1_data_406B == 9 && dir != 0) {
        lbl_1_bss_1010_gap_1015 = 1;
        lbl_1_bss_1120 = fzgx_obj_camera_state;
        lbl_1_bss_104C.state = 2;
        camera_snapshot();
    }
    if ((s32)lbl_1_data_406B == 10 && dir != 0) {
        fn_1_C10C(0);
    }
    if ((s32)lbl_1_data_406B == 11 && dir != 0) {
        fn_1_C10C(1);
    }
    if ((s32)lbl_1_data_406B == 12 && dir != 0) {
        lbl_1_bss_1014 = 0;
    }
    if ((s32)lbl_1_data_406B == 13 && dir != 0) {
        fn_1_C178("NORMAL");
    }
    if ((s32)lbl_1_data_406B == 14 && dir != 0) {
        fn_1_C178("EASE_OUT");
    }
    if ((s32)lbl_1_data_406B == 15 && dir != 0) {
        fn_1_C178("EASE_IN_OUT");
    }
    if ((s32)lbl_1_data_406B == 16 && dir != 0) {
        camera_report_position();
    }
    if ((s32)lbl_1_data_406B == 17 && dir != 0) {
        fn_1_C268((s32)"STATIC_MOVE_PERS");
    }
    if ((s32)lbl_1_data_406B == 18 && dir != 0) {
        fn_1_C304((s32)"STATIC_FIX");
    }

    if ((pad->unk_10 >> 3) & 1) {
        lbl_1_data_406B = menu_prev(lbl_1_data_406B);
    } else if ((pad->unk_10 >> 2) & 1) {
        lbl_1_data_406B = menu_next(lbl_1_data_406B);
    }

    if (lbl_1_bss_1010_gap_1015 != 0) {
        fn_1_C3B8();
    }
    if (((lbl_1_bss_D58.unk_0 >> 10) & 1) && ((lbl_1_bss_D58.unk_8 >> 11) & 1)) {
        lbl_1_bss_1010_gap_1015 = 0;
        lbl_1_bss_1014 = 0;
    }
}
/* fzgx:end fn_1_C770 */

/* fzgx:begin fn_1_CC5C noprologue */
#include "types.h"
#include "types.h"
#include "types.h"

#ifndef REL_MAIN_REL_CAMERA_H
#define REL_MAIN_REL_CAMERA_H
#ifndef REL_MAIN_REL_GLOBALS_H
#define REL_MAIN_REL_GLOBALS_H

#endif  // REL_MAIN_REL_GLOBALS_H

// fzgx_pool_lbl_1_data_4068: .data size 0x1, 3 refs from camera.c (own data block)
extern u16 fzgx_pool_lbl_1_data_4068;

// lbl_1_bss_D58: .bss size 0x18, 3 refs from camera.c
#ifndef FZGX_TYPES_LBL_1_BSS_D58
#define FZGX_TYPES_LBL_1_BSS_D58
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u16 unk_0;  // 5 loads, 0 stores
    u16 unk_2;  // 1 loads, 0 stores
    u8 pad_4[0x4];
    u16 unk_8;  // 24 loads, 0 stores
    u16 unk_A;  // 3 loads, 0 stores
    u8 pad_C[0x4];
    u16 unk_10;  // 18 loads, 0 stores
    u16 unk_12;  // 4 loads, 0 stores
    u8 pad_14[0x4];
} Obj_1_bss_D58;
#endif
extern Obj_1_bss_D58 lbl_1_bss_D58;

#endif  // REL_MAIN_REL_CAMERA_H

/* end rel/main_rel/camera.h */

/* RGBA colour, passed by value (MWCC copies it to the stack per call) */
typedef struct { u8 r, g, b, a; } fn_1_CC5C_Color;

u16 fzgx_pool_lbl_1_data_4068 = 0xF000;
u8 fzgx_pool_fn_1_CC5C_menu_cursor = 9;
u8 fzgx_pool_fn_1_CC5C_menu_selected = 3;
u8 fzgx_pool_fn_1_CC5C_menu_data_pad[0x1BC] = {
    0x09, 0x7B, 0x20, 0x25, 0x33, 0x64, 0x2C, 0x20, 0x25, 0x31, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x7B,
    0x20, 0x20, 0x30, 0x2C, 0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38,
    0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x7B, 0x20,
    0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25,
    0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x20, 0x25, 0x35, 0x2E, 0x31, 0x66, 0x2C, 0x20,
    0x25, 0x35, 0x64, 0x2C, 0x20, 0x30, 0x2C, 0x7D, 0x2C, 0x0A, 0x00, 0x00, 0x09, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7B, 0x20, 0x20, 0x30, 0x2C,
    0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C,
    0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E,
    0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66,
    0x20, 0x7D, 0x2C, 0x20, 0x20, 0x25, 0x35, 0x2E, 0x31, 0x66, 0x2C, 0x20, 0x25, 0x35, 0x64, 0x2C,
    0x20, 0x30, 0x2C, 0x7D, 0x2C, 0x20, 0x25, 0x73, 0x7D, 0x2C, 0x0A, 0x00, 0x09, 0x7B, 0x20, 0x20,
    0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38,
    0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x0A, 0x00, 0x09, 0x7B, 0x20, 0x30, 0x30, 0x2C, 0x7B, 0x20,
    0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25,
    0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66,
    0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D,
    0x2C, 0x20, 0x25, 0x35, 0x64, 0x2C, 0x20, 0x20, 0x50, 0x45, 0x52, 0x53, 0x5F, 0x44, 0x45, 0x47,
    0x52, 0x45, 0x45, 0x2C, 0x20, 0x25, 0x73, 0x7D, 0x2C, 0x0A, 0x00, 0x00, 0x09, 0x7B, 0x20, 0x30,
    0x30, 0x2C, 0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33,
    0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x7B, 0x20, 0x20, 0x25,
    0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E,
    0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x25, 0x35, 0x64, 0x2C, 0x20, 0x20, 0x25, 0x31, 0x31, 0x2E,
    0x33, 0x66, 0x2C, 0x20, 0x25, 0x73, 0x7D, 0x2C, 0x0A, 0x00, 0x00, 0x00, 0x4E, 0x4F, 0x52, 0x4D,
    0x41, 0x4C, 0x00, 0x00, 0x45, 0x41, 0x53, 0x45, 0x5F, 0x4F, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00,
    0x45, 0x41, 0x53, 0x45, 0x5F, 0x49, 0x4E, 0x5F, 0x4F, 0x55, 0x54, 0x00, 0x53, 0x54, 0x41, 0x54,
    0x49, 0x43, 0x5F, 0x4D, 0x4F, 0x56, 0x45, 0x5F, 0x50, 0x45, 0x52, 0x53, 0x00, 0x00, 0x00, 0x00,
    0x53, 0x54, 0x41, 0x54, 0x49, 0x43, 0x5F, 0x46, 0x49, 0x58, 0x00, 0x00,
};
char fzgx_pool_fn_1_CC5C_fmt_1C0[0x10] = { 0x43, 0x41, 0x4D, 0x83, 0x47, 0x83, 0x66, 0x83, 0x42, 0x83, 0x5E, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_1D0[0x8] = { 0x82, 0xA2, 0x82, 0xC7, 0x82, 0xA4, 0x20, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_1D8[0x8] = { 0x82, 0xC6, 0x82, 0xB6, 0x82, 0xE9, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_1E0[0x10] = { 0x83, 0x5A, 0x83, 0x62, 0x83, 0x67, 0x20, 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x41, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_1F0[0x10] = { 0x83, 0x5A, 0x83, 0x62, 0x83, 0x67, 0x20, 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x42, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_200[0xC] = { 0x91, 0xAC, 0x93, 0x78, 0x20, 0x25, 0x31, 0x2E, 0x33, 0x66, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_20C[0xC] = { 0x83, 0x52, 0x83, 0x7D, 0x20, 0x25, 0x33, 0x64, 0x0A, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_218[0x14] = { 0x4E, 0x4F, 0x52, 0x4D, 0x41, 0x4C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x50, 0x4C, 0x41, 0x59, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_22C[0x14] = { 0x45, 0x41, 0x53, 0x45, 0x5F, 0x49, 0x4E, 0x5F, 0x4F, 0x55, 0x54, 0x20, 0x3A, 0x20, 0x50, 0x4C, 0x41, 0x59, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_240[0x14] = { 0x45, 0x41, 0x53, 0x45, 0x5F, 0x4F, 0x55, 0x54, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x50, 0x4C, 0x41, 0x59, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_254[0x10] = { 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x41, 0x82, 0xC9, 0x88, 0xDA, 0x93, 0xAE, 0x0A, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_264[0x10] = { 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x42, 0x82, 0xC9, 0x88, 0xDA, 0x93, 0xAE, 0x0A, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_274[0xC] = { 0x82, 0xC6, 0x82, 0xB6, 0x82, 0xE9, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_280[0x8] = { 0x20, 0x4E, 0x4F, 0x52, 0x4D, 0x41, 0x4C, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_288[0x8] = { 0x20, 0x4F, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_290[0xC] = { 0x20, 0x49, 0x4E, 0x5F, 0x4F, 0x55, 0x54, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_29C[0x8] = { 0x20, 0x43, 0x41, 0x4D, 0x5F, 0x42, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2A4[0x8] = { 0x20, 0x53, 0x54, 0x41, 0x54, 0x49, 0x43, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2AC[0x10] = { 0x20, 0x53, 0x54, 0x41, 0x54, 0x49, 0x43, 0x5F, 0x46, 0x49, 0x58, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2BC[0x4] = { 0x0A, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2C0[0xC] = { 0x54, 0x49, 0x4D, 0x45, 0x52, 0x3A, 0x25, 0x64, 0x0A, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2CC[0xC] = { 0x20, 0x70, 0x65, 0x72, 0x73, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2D8[0x10] = { 0x20, 0x7A, 0x61, 0x6E, 0x67, 0x3A, 0x25, 0x30, 0x34, 0x68, 0x78, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2E8[0x10] = { 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x41, 0x20, 0x78, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2F8[0xC] = { 0x20, 0x79, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_304[0xC] = { 0x20, 0x7A, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x0A, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_310[0x10] = { 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x20, 0x20, 0x78, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_320[0x10] = { 0x20, 0x20, 0x70, 0x65, 0x72, 0x73, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x0A, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_330[0x10] = { 0x20, 0x20, 0x7A, 0x61, 0x6E, 0x67, 0x3A, 0x25, 0x30, 0x34, 0x68, 0x78, 0x0A, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_340[0x10] = { 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x42, 0x20, 0x78, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00 };
extern void fn_1_49410(void);
extern void fn_1_49514(fn_1_CC5C_Color);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495FC(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);

#pragma opt_common_subs off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 fzgx_pool_lbl_1_bss_1010_gap_1015;
u16 fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
u8 fzgx_obj_camera_state;
u8 camera_state__fzgx_offset_1;
u16 camera_state__fzgx_offset_2;
u32 camera_state__fzgx_offset_4[8];
u32 lbl_1_bss_103C;
u32 lbl_1_bss_1040;
u32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 fzgx_pool_lbl_1_bss_1010_gap_104A;
u32 fzgx_obj_lbl_1_bss_104C;
u32 lbl_1_bss_104C__fzgx_offset_4[15];
u32 lbl_1_bss_108C[13];
u32 lbl_1_bss_10C0[6];
u8 fzgx_obj_lbl_1_bss_10D8;
u8 lbl_1_bss_10D8__fzgx_offset_1;
u16 lbl_1_bss_10D8__fzgx_offset_2;
u32 lbl_1_bss_10D8__fzgx_offset_4[26];
u8 lbl_1_bss_10D8__fzgx_offset_6C;
u8 lbl_1_bss_10D8__fzgx_offset_6D;
u16 lbl_1_bss_10D8__fzgx_offset_6E;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&lbl_1_bss_1014;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&camera_state__fzgx_offset_1;
    s = *(u8 *)&camera_state__fzgx_offset_2;
    s = *(u8 *)&camera_state__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = *(u8 *)&fzgx_obj_camera_flag_0;
    s = *(u8 *)&fzgx_obj_camera_flag_1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_104C__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_6C;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_6D;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_6E;
}

/* literal pool of the retail TU in retail order; this function's own
 * colour table and 2.0f follow the 0.0001 double. */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.009999999776482582f;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table2[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04000000000000001;
    d = 1.0;
    d = 4.0;
    d = 140.0;
    d = 50.0;
    d = 60.0;
    d = 0.09;
    d = 0.3;
    d = 0.1;
    d = 90000.0;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
    d = 0.02;
    s = 60.0f;
    s = 15.0f;
    s = 0.8999999761581421f;
    s = 0.0f;
    s = 0.5f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 55.0;
    s = 10.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 0.5;
    d = 0.0001;
}
#pragma section code_type ".text"

/* one past the camera state block: a field address equal to it has no value to show */
#define END_ADDR ((u32)&lbl_1_bss_10D8__fzgx_offset_6C)

/* the field address is advanced through a pointer cast so the offset stays on the
 * address variable (retail: addi r3, r3, 0xc; lfs f1, 0x0(r3)) */
#define ADVANCE(off) p = (u32)((u8 *)p + (off))
#define FIELD(type) (*(type *)p)

#define SELECT_COLOR(n) \
    if ((s32)fzgx_pool_fn_1_CC5C_menu_selected == (n)) fn_1_49514(colors[0]); else fn_1_49514(colors[2])

#define PRINT_VALUE(fmt, val) \
    if (p != END_ADDR) fn_1_4AE0C(fmt, val); else fn_1_4A0D8(fmt)

#define PRINT_VALUE2(fmt, val) \
    if (p != END_ADDR) { \
        if (p == END_ADDR) fn_1_4AE0C(fmt, val); else fn_1_4AE0C(fmt, val); \
    } else fn_1_4A0D8(fmt)

void fn_1_CC5C(void) {
    fn_1_CC5C_Color colors[3] = { { 0x00, 0xFF, 0x00, 0xFF }, { 0x80, 0x80, 0x80, 0xFF }, { 0xFF, 0xFF, 0xFF, 0xFF } };
    u8 idx;
    u16 x;
    u16 y;
    u32 p;

    idx = fzgx_pool_fn_1_CC5C_menu_cursor;
    x = (idx % 4) * 150;
    y = ((idx >> 2) & 0x3F) * 60;
    if (((lbl_1_bss_D58.unk_2 >> 8) & 1) == 0) {
        fn_1_49410();
        fn_1_4954C(2.0f);
        fn_1_4955C(0.5f, 0.5f);
        fn_1_495FC();
        fn_1_496FC((f32)x, (f32)y);

        SELECT_COLOR(0);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_1C0);
        SELECT_COLOR(1);
        p = (u32)&fzgx_pool_fn_1_CC5C_menu_cursor;
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_1D0, fzgx_pool_fn_1_CC5C_menu_cursor);
        SELECT_COLOR(2);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_1D8);
        SELECT_COLOR(3);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_1E0);
        SELECT_COLOR(4);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_1F0);
        SELECT_COLOR(5);
        p = (u32)&fzgx_obj_lbl_1_bss_104C;
        ADVANCE(12);
        PRINT_VALUE2(fzgx_pool_fn_1_CC5C_fmt_200, FIELD(f32));
        SELECT_COLOR(6);
        p = (u32)&fzgx_obj_lbl_1_bss_104C;
        ADVANCE(8);
        PRINT_VALUE2(fzgx_pool_fn_1_CC5C_fmt_20C, FIELD(u32));
        SELECT_COLOR(7);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_218);
        SELECT_COLOR(8);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_22C);
        SELECT_COLOR(9);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_240);
        SELECT_COLOR(10);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_254);
        SELECT_COLOR(11);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_264);
        SELECT_COLOR(12);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_274);
        SELECT_COLOR(13);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_280);
        SELECT_COLOR(14);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_288);
        SELECT_COLOR(15);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_290);
        SELECT_COLOR(16);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_29C);
        SELECT_COLOR(17);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_2A4);
        SELECT_COLOR(18);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_2AC);
        SELECT_COLOR(19);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_2BC);
        SELECT_COLOR(20);
        p = (u32)&fzgx_obj_lbl_1_bss_104C;
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2C0, fzgx_obj_lbl_1_bss_104C);
        SELECT_COLOR(21);
        p = (u32)&fzgx_obj_camera_state;
        ADVANCE(28);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2CC, FIELD(f32));
        SELECT_COLOR(22);
        p = (u32)&fzgx_obj_camera_state;
        ADVANCE(32);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2D8, FIELD(s16));
        SELECT_COLOR(23);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(4);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2E8, FIELD(f32));
        SELECT_COLOR(24);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(8);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2F8, FIELD(f32));
        SELECT_COLOR(25);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(12);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_304, FIELD(f32));
        SELECT_COLOR(26);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(16);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_310, FIELD(f32));
        SELECT_COLOR(27);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(20);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2F8, FIELD(f32));
        SELECT_COLOR(28);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(24);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_304, FIELD(f32));
        SELECT_COLOR(29);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(28);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_320, FIELD(f32));
        SELECT_COLOR(30);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(32);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_330, FIELD(s16));
        SELECT_COLOR(31);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(40);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_340, FIELD(f32));
        SELECT_COLOR(32);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(44);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2F8, FIELD(f32));
        SELECT_COLOR(33);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(48);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_304, FIELD(f32));
        SELECT_COLOR(34);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(52);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_310, FIELD(f32));
        SELECT_COLOR(35);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(56);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2F8, FIELD(f32));
        SELECT_COLOR(36);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(60);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_304, FIELD(f32));
        SELECT_COLOR(37);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(64);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_320, FIELD(f32));
        SELECT_COLOR(38);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(68);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_330, FIELD(s16));
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_CC5C */

/* fzgx:begin camera_get_state_object */
// Returns the camera state object's base address.
CameraState* camera_get_state_object(void) {
    return &camera_state;
}
/* fzgx:end camera_get_state_object */

/* fzgx:begin camera_get_state_field_0x4 */
// Returns the address of the camera state field at offset 4.
u32* camera_get_state_field_0x4(void) {
    return &camera_state.unk_4;
}
/* fzgx:end camera_get_state_field_0x4 */

/* fzgx:begin camera_get_state_field_0x8 */
// Returns the address of the camera state field at offset 0x8.
u32* camera_get_state_field_0x8(void) {
    return &camera_state.unk_8;
}
/* fzgx:end camera_get_state_field_0x8 */

/* fzgx:begin camera_get_state_field_0xc */
// Returns a pointer to the camera object's field at offset 0xC.
u32* camera_get_state_field_0xc(void) {
    return &camera_state.unk_C;
}
/* fzgx:end camera_get_state_field_0xc */

/* fzgx:begin camera_get_state_field_0x10 */
// Returns a pointer to the camera object's state field.
u32* camera_get_state_field_0x10(void) {
    return &camera_state.unk_10;
}
/* fzgx:end camera_get_state_field_0x10 */

/* fzgx:begin camera_get_state_field_0x14 */
// Returns a pointer to the camera object's field at offset 0x14.
u32* camera_get_state_field_0x14(void) {
    return &camera_state.unk_14;
}
/* fzgx:end camera_get_state_field_0x14 */

/* fzgx:begin camera_get_state_field_0x18 */
// Returns a pointer to the camera object's state field at offset 0x18.
u32* camera_get_state_field_0x18(void) {
    return &camera_state.unk_18;
}
/* fzgx:end camera_get_state_field_0x18 */

/* fzgx:begin camera_get_state_storage */
// Returns the camera state storage used by the surrounding camera code.
u8* camera_get_state_storage(void) {
    return lbl_1_bss_103C;
}
/* fzgx:end camera_get_state_storage */

/* fzgx:begin camera_get_extended_state_storage noprologue */
#include "types.h"

extern u8 lbl_1_bss_108C[52];

// Returns the storage reserved for the camera's extended state.
u8* camera_get_extended_state_storage(void) {
    return lbl_1_bss_108C;
}
/* fzgx:end camera_get_extended_state_storage */

/* fzgx:begin camera_get_state_flag */
// Returns the current camera state flag.
u8 camera_get_state_flag(void) {
    return lbl_1_bss_1014;
}
/* fzgx:end camera_get_state_flag */

/* fzgx:begin camera_enable_flags */
// Enables the camera state flags.
void camera_enable_flags(void) {
    camera_flag_1 = 1;
    camera_flag_0 = 1;
}
/* fzgx:end camera_enable_flags */

/* fzgx:begin camera_disable_flags */
// Clears the camera state flags.
void camera_disable_flags(void) {
    camera_flag_1 = 0;
    camera_flag_0 = 0;
}
/* fzgx:end camera_disable_flags */

/* fzgx:begin camera_are_flags_enabled */
// Returns whether the camera state flag is set.
BOOL camera_are_flags_enabled(void) {
    return camera_flag_1;
}
/* fzgx:end camera_are_flags_enabled */
