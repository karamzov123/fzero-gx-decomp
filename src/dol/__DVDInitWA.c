#include "types.h"


/* --- dol/C_MTXFrustum.c --- */
/* --- dol/C_MTXFrustum.c --- */
extern const f32 lbl_801A6F60;
extern const f32 lbl_801A6F64;
extern const f32 lbl_801A6F68;
extern const f32 lbl_801A6F6C;

struct fn_80015D7C_Matrix {
    f32 m[16];
};

void C_MTXFrustum(struct fn_80015D7C_Matrix *out, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);

/* --- dol/C_MTXPerspective.c --- */
extern const f32 lbl_801A6F70;
extern const f32 lbl_801A6F74;
extern f32 fn_800885DC(f32);

void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);

/* --- dol/C_MTXOrtho.c --- */
typedef struct Fn80015EE8Out {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;
    f32 f6;
    f32 f7;
    f32 f8;
    f32 f9;
    f32 f10;
    f32 f11;
    f32 f12;
    f32 f13;
    f32 f14;
    f32 f15;
} Fn80015EE8Out;

void C_MTXOrtho(Fn80015EE8Out *out, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

/* --- dol/__DVDInitWA.c --- */
extern u32 CommandList[];
extern u32 NextCommandNumber;
extern u32 OSInitAlarm(u32);
extern u32 __DVDLowSetWAType(u32, u32);

u32 __DVDInitWA(void) {
    u32 t0;
    NextCommandNumber = 0;
    CommandList[0] = -1;
    t0 = __DVDLowSetWAType(0, 0);
    return OSInitAlarm(t0);
}
