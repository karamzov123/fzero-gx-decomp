#include "types.h"
#include "game/vec3.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_san.h"

extern void fn_1_9AD54(void);
extern void fn_1_FBEA8(void);
extern void fn_1_103F58(void *arg);
extern void fn_1_9AD88(void);
extern void fn_1_9A508(void);
extern void fn_1_103D28(void *arg0, u32 arg1, f32 arg2);
extern void fn_1_FB87C(u32 *, u32);
extern u32 fn_1_FBFE4();
extern void fn_1_FB96C(int);

/* fzgx:begin fn_1_DA7B8 */
#include "rel/main_rel/bg_san.h"

extern void fn_1_DAAFC();

// Forwards the active background state to the next processing stage.
void fn_1_DA7B8(void) {
    fn_1_DAAFC(lbl_1_data_2A7E0.unk_3C);
}
/* fzgx:end fn_1_DA7B8 */

/* fzgx:begin fn_1_DA7E4 */
struct fn_1_DA7E4_Sub {
    u8 pad_0[0x9A0];
    u32 blk[141];
    u32 unk_BD4;
    u32 unk_BD8;
};

struct fn_1_DA7E4_lbl_1_data_2A7E0 {
    u8 pad_0[0x2C];
    u32 unk_2C;
    u8 pad_30[0xC];
    struct fn_1_DA7E4_Sub *unk_3C;
};

extern u32 fn_1_58C4();

void fn_1_DA7E4(void) {
    struct fn_1_DA7E4_Sub *obj;
    u32 tmp[4];
    s32 n;
    s32 i;

    obj = (struct fn_1_DA7E4_Sub *)lbl_1_data_2A7E0.unk_3C;
    n = fn_1_58C4();
    for (i = 0; i < n; i++) {
        tmp[i] = obj->blk[i];
    }
    fn_1_9A508();
    n = fn_1_58C4();
    for (i = 0; i < n; i++) {
        obj->blk[i] = tmp[i];
    }
    if (obj->unk_BD4 != 0) {
        fn_1_FB87C(&obj->unk_BD4, 1);
        fn_1_FB96C(0);
        fn_1_FB96C(1);
        fn_1_FB96C(2);
        fn_1_FB96C(4);
    }
    lbl_1_data_2A7E0.unk_2C = (u32)fn_1_FBFE4;
    fn_1_103D28(&obj->unk_BD8, 10, 0.6f);
}
/* fzgx:end fn_1_DA7E4 */

/* fzgx:begin fn_1_DA9F0 */
#include "rel/main_rel/bg_san.h"

extern u32 fn_1_58C4();
extern void fn_1_DAB1C();

// Applies the background transition after the scene reports readiness.
void fn_1_DA9F0(void) {
    Obj_1_data_2A7E0_At3C *background_state = lbl_1_data_2A7E0.unk_3C;

    if (fn_1_58C4() == 1) {
        fn_1_DAB1C(background_state);
    }
}
/* fzgx:end fn_1_DA9F0 */

/* fzgx:begin fn_1_DAA34 */
void fn_1_DAA34(void) {
    fn_1_9AD54();
    fn_1_FBEA8();
}
/* fzgx:end fn_1_DAA34 */

/* fzgx:begin fn_1_DAA58 */
#include "rel/main_rel/bg_san.h"

extern void fn_1_FB9C0(u32 value);
extern void fn_1_103F10(void *state);
extern void fn_1_DAB3C();

// Loads pending background resources before advancing the scene state.
void fn_1_DAA58(void) {
    Obj_1_data_2A7E0_At3C *state = lbl_1_data_2A7E0.unk_3C;

    if (state->unk_BD4 != 0) {
        fn_1_FB9C0(0);
        fn_1_FB9C0(1);
        fn_1_FB9C0(2);
        fn_1_FB9C0(4);
    }

    fn_1_103F10(&state->unk_BD8);
    fn_1_DAB3C(state);
}
/* fzgx:end fn_1_DAA58 */

/* fzgx:begin fn_1_DAAC4 */
#include "rel/main_rel/bg_san.h"

void fn_1_DAAC4(void) {
    fn_1_103F58(&lbl_1_data_2A7E0.unk_3C->unk_BD8);
    fn_1_9AD88();
}
/* fzgx:end fn_1_DAAC4 */

/* fzgx:begin fn_1_DAAF8 */
// fn_1_DAAF8: empty in retail (single blr).
void fn_1_DAAF8(void) {
}
/* fzgx:end fn_1_DAAF8 */

/* fzgx:begin fn_1_DAAFC */
// Initialize the background-san subsystem through its shared setup routine.
void fn_1_DAAFC(void) {
    fn_1_58C4();
}
/* fzgx:end fn_1_DAAFC */

/* fzgx:begin fn_1_DAB1C */
// Runs the background sanitation update.
void fn_1_DAB1C(void) {
    fn_1_58C4();
}
/* fzgx:end fn_1_DAB1C */

/* fzgx:begin fn_1_DAB3C */
// Perform the background sanitation step.
void fn_1_DAB3C(void) {
    fn_1_58C4();
}
/* fzgx:end fn_1_DAB3C */

/* fzgx:begin fn_1_DAB5C */
typedef struct {
    u8 pad_0[0x14];
    f32 unk_14;
    u8 pad_18[0xC];
    u32 unk_24;
} Fn1DAB5C_Obj;

s32 fn_1_DAB5C(s32 mode, Fn1DAB5C_Obj **arg) {
    Obj_1_data_2A7E0_At3C *dest;
    Fn1DAB5C_Obj *obj;
    u32 val;

    obj = *arg;
    dest = lbl_1_data_2A7E0.unk_3C;
    val = obj->unk_24;
    switch (mode) {
    case 1:
        dest->unk_BD4 = val;
        break;
    case 3:
        dest->unk_AF0 = obj->unk_14;
        break;
    case 4:
        dest->unk_18AC = (u32)obj;
        break;
    }
    return 1;
}
/* fzgx:end fn_1_DAB5C */

/* fzgx:begin fn_1_DABB4 */
typedef struct {
    f32 x, y, z;
} Fn1DABB4_Vec;


extern void lbl_8006D91C(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006E1C0(void *, void *);
extern void lbl_8006D7DC(void *);
extern void mathutil_mtxA_rotate_z(s16);
extern void lbl_8006E13C(void *);
extern void lbl_8006DB74(void *);

typedef struct {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0xC];
    u32 unk_1C;
    u8 pad_20[0x2C];
    f32 unk_4C;
} Fn1DABB4_Entry;

typedef struct {
    u8 pad[0x10];
    s32 count;
    Fn1DABB4_Entry e[30];
} Fn1DABB4_Mgr;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x8];
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    s16 unk_18;
    s16 unk_1A;
    s16 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
} Fn1DABB4_Obj;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

u32 fn_1_DABB4(s32 mode, Fn1DABB4_Obj *arg1) {
    Obj_1_data_2A7E0_At3C *manager;

    manager = lbl_1_data_2A7E0.unk_3C;
    switch (mode) {
    case 0:
        arg1->unk_0 |= 0x02000000;
        break;
    case 1:
        arg1->unk_0 |= 0x02000000;
        break;
    case 2:
    case 3:
        arg1->unk_0 |= 0x02000000;
        break;
    case 4:
        arg1->unk_0 |= 0x04000000;
        if ((s32)manager->unk_10 < 0x1e) {
            Fn1DABB4_Entry *entry = &((Fn1DABB4_Mgr *)manager)->e[((Fn1DABB4_Mgr *)manager)->count];
            Fn1DABB4_Vec values = {0.0f, 1.0f, 0.0f};
            entry->unk_0 = (u32)arg1;
            entry->unk_4 = arg1->unk_C;
            entry->unk_8 = arg1->unk_10;
            entry->unk_C = arg1->unk_14;
            lbl_8006D91C(arg1->unk_1C);
            mathutil_mtxA_rotate_y(arg1->unk_1A);
            mathutil_mtxA_rotate_x(arg1->unk_18);
            lbl_8006E1C0(&values, (u8 *)entry + 0x10);
            lbl_8006D7DC(&arg1->unk_C);
            mathutil_mtxA_rotate_z(arg1->unk_1C);
            mathutil_mtxA_rotate_y(arg1->unk_1A);
            mathutil_mtxA_rotate_x(arg1->unk_18);
            lbl_8006E13C(&arg1->unk_20);
            lbl_8006DB74((u8 *)entry + 0x1C);
            ((Fn1DABB4_Mgr *)manager)->count++;
            entry->unk_4C = MAX(arg1->unk_20, MAX(arg1->unk_24, arg1->unk_28));
        }
        break;
    case 8:
        manager->unk_BD8 = (u32)arg1;
        break;
    }
    return 1;
}
/* fzgx:end fn_1_DABB4 */
