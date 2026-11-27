#include "types.h"

/* --- rel/movie_module/fn_12_3A968.c --- */
/* --- rel/movie_module/fn_12_3A968.c --- */
typedef struct MovieObject {
    u8 pad[0x60];
    s32 value;
} MovieObject;

void fn_12_3A968(MovieObject *self, s32 value) {
    self->value = value;
}

/* --- rel/movie_module/fn_12_3A970.c --- */
extern u32 fn_12_38DBC(u32);

void fn_12_3A970(u32 arg0) {
    u32 t0;
    t0 = fn_12_38DBC(arg0);
    *(u32 *)((u8 *)t0 + 84) = arg0;
}

/* --- rel/movie_module/fn_12_3A9A0.c --- */
typedef struct Sig_fn_12_3A9A0_MovieObject {
    u8 pad04[0x4];
    s32 state;
    u8 pad08[0x58];
    s32 value;
} Sig_fn_12_3A9A0_MovieObject;
typedef struct Sig_fn_12_2CC24_MovieModuleState {
    u8 _pad_0[0x44];
    u32 field_44;
} Sig_fn_12_2CC24_MovieModuleState;
typedef struct Sig_fn_12_2CD44_MovieModuleState {
    u8 _pad_0[0x44];
    u32 field_44;
    u32 field_48;
} Sig_fn_12_2CD44_MovieModuleState;

extern int fn_12_2CC24(Sig_fn_12_2CC24_MovieModuleState *);
extern u32 fn_12_2CD44(Sig_fn_12_2CD44_MovieModuleState *);
extern u32 fn_12_3AE84(u32);
extern u32 lbl_12_bss_1CC60;

#pragma opt_dead_assignments off
#pragma opt_lifetimes off
u32 fn_12_3A9A0(Sig_fn_12_3A9A0_MovieObject * arg0) {
    u32 v0;
    u32 v1;
    int t0;
    u32 t1;
    u32 t2;
    v0 = *(u32 *)((u8 *)arg0 + 64);
    ((Sig_fn_12_3A9A0_MovieObject *)(arg0))->value = 1;
    v1 = (u32)(arg0);
    if (((Sig_fn_12_3A9A0_MovieObject *)(arg0))->state != 1) {
    v1 = 0;
    ((Sig_fn_12_3A9A0_MovieObject *)(arg0))->value = 0;
    } else {
    v1 = v0;
    lbl_12_bss_1CC60 = (u32)(arg0);
    *(u32 *)((u8 *)arg0 + 100) = 1;
    t0 = fn_12_2CC24((Sig_fn_12_2CC24_MovieModuleState *)v1);
    v1 = t0;
    v1 = 0;
    *(u32 *)((u8 *)arg0 + 100) = v1;
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    *(u32 *)((u8 *)arg0 + 104) = v1;
    } else {
    v1 = (u32)(arg0);
    *(u32 *)((u8 *)arg0 + 104) = 1;
    t1 = fn_12_3AE84(v1);
    v1 = t1;
    }
    v1 = v0;
    ((Sig_fn_12_3A9A0_MovieObject *)(arg0))->value = 0;
    t2 = fn_12_2CD44((Sig_fn_12_2CD44_MovieModuleState *)v1);
    v1 = t2;
    v1 = ((u32)((1 - v1) | (v1 - 1)) >> 31);
    }
    return v1;
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset
