#include "types.h"

typedef struct {
    u8 r, g, b, a;
} Color4;

typedef struct {
    s8 v[6];
    u8 pad[2];
} Entry8;

typedef struct {
    u8 flags[4];
    u8 pad_4[0x1C];
    Color4 unk_20;
    u8 pad_24[0x8];
    u32 unk_2C;
    Color4 unk_30;
    Color4 unk_34;
} State;

State fzgx_obj_lbl_8019E250;
Entry8 lbl_8019E250__fzgx_offset_38[16];
u8 fzgx_obj_lbl_8019E308[0xD00];
#pragma section code_type ".fzgxpool"
void fzgx_bss_primer(void) {
    volatile u8 s;  /* fzgx-allow: S2 volatile keeps the verified access order */
    s = *(u8 *)&fzgx_obj_lbl_8019E250;
    s = *(u8 *)lbl_8019E250__fzgx_offset_38;
    s = fzgx_obj_lbl_8019E308[0];
}
#pragma section code_type ".text"
extern Color4 lbl_801A7920;
extern Color4 lbl_801A7448;
extern Entry8 *lbl_801A6D2C;
extern u32 fn_800793D4(void *, u32, u32);
extern const f32 lbl_801A744C;
extern const f32 lbl_801A7450;
extern const f32 lbl_801A7454;
extern const f32 lbl_801A7458;
extern void fn_800721FC(f32, f32, f32, f32);
extern const f32 lbl_801A745C;
extern void fn_80071ED4(f32, f32, s32);
extern u32 fn_800720B0(u32);
extern void fn_800725DC(Color4);
extern void fn_80072614(Color4);

void fn_80071D30(void) {
    Color4 c1;
    Color4 c0;
    Entry8 *e;
    s32 i;

    c1 = lbl_801A7920;
    c0 = lbl_801A7448;
    fzgx_obj_lbl_8019E250.unk_2C = 0;
    fzgx_obj_lbl_8019E250.flags[0] = 0;
    fzgx_obj_lbl_8019E250.flags[1] = 0;
    fzgx_obj_lbl_8019E250.flags[2] = 0;
    fzgx_obj_lbl_8019E250.flags[3] = 0;
    e = lbl_8019E250__fzgx_offset_38;
    lbl_801A6D2C = e;
    for (i = 2; i != 0; i--, e += 8) {
        e[0].v[0] = -1;
        e[0].v[1] = -1;
        e[0].v[2] = -1;
        e[0].v[3] = -1;
        e[0].v[4] = -1;
        e[0].v[5] = -1;
        e[1].v[0] = -1;
        e[1].v[1] = -1;
        e[1].v[2] = -1;
        e[1].v[3] = -1;
        e[1].v[4] = -1;
        e[1].v[5] = -1;
        e[2].v[0] = -1;
        e[2].v[1] = -1;
        e[2].v[2] = -1;
        e[2].v[3] = -1;
        e[2].v[4] = -1;
        e[2].v[5] = -1;
        e[3].v[0] = -1;
        e[3].v[1] = -1;
        e[3].v[2] = -1;
        e[3].v[3] = -1;
        e[3].v[4] = -1;
        e[3].v[5] = -1;
        e[4].v[0] = -1;
        e[4].v[1] = -1;
        e[4].v[2] = -1;
        e[4].v[3] = -1;
        e[4].v[4] = -1;
        e[4].v[5] = -1;
        e[5].v[0] = -1;
        e[5].v[1] = -1;
        e[5].v[2] = -1;
        e[5].v[3] = -1;
        e[5].v[4] = -1;
        e[5].v[5] = -1;
        e[6].v[0] = -1;
        e[6].v[1] = -1;
        e[6].v[2] = -1;
        e[6].v[3] = -1;
        e[6].v[4] = -1;
        e[6].v[5] = -1;
        e[7].v[0] = -1;
        e[7].v[1] = -1;
        e[7].v[2] = -1;
        e[7].v[3] = -1;
        e[7].v[4] = -1;
        e[7].v[5] = -1;
    }
    fn_800793D4(fzgx_obj_lbl_8019E308, 0xFF, 0xD00);
    fzgx_obj_lbl_8019E250.unk_20 = c1;
    fzgx_obj_lbl_8019E250.unk_30 = c1;
    fzgx_obj_lbl_8019E250.unk_34 = c1;
    fn_800721FC(lbl_801A744C, lbl_801A7450, lbl_801A7454, lbl_801A7458);
    fn_80071ED4(lbl_801A745C, lbl_801A745C, 4);
    fn_800720B0(0);
    fn_800725DC(c0);
    fn_80072614(c0);
}
