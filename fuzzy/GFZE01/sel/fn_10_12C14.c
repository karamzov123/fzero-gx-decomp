/* Non-matching: best partial attempt (97.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/sel.h"
struct State { u8 pad[0x94]; u32 flags; };
extern struct State lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_8CA26;
extern u8 lbl_1_bss_8CA28;
extern const f32 lbl_10_rodata_158[70];
extern u32 lbl_10_bss_51788[25];
typedef struct { f32 x,y,z; } Position;
typedef struct { u32 a,b; } Result;
typedef struct { u32 a; f32 x,y,z,sx,sy; u8 pad[0x18]; u32 mode; u8 tail[0x24]; } Draw;
extern const Draw lbl_1_rodata_26F8;
extern int fn_1_B7F58(Result *);
extern u32 fn_10_13128(void *);
extern void fn_1_8D1C8(void *, u32 (*)(void *), Position *);
extern s32 fn_1_4FC50(Draw *,u32,u16,u16,u32);
#define F(off) (*(const f32 *)((const u8 *)pool + (off)))
static inline u32 fn_10_12C14_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_common_subs off
void fn_10_12C14(void) {
    f32 *fzgx_value_;
    u32 *fzgx_value;
    const f32 *pool = lbl_10_rodata_158;
    struct State *state = &lbl_1_bss_8B3A0;
    Draw draw;
    Position pos;
    Result result;
    f32 offset;
    u32 flags = state->flags & 0x40000000;
    {
        u32 x = *(const u32 *)((const u8 *)pool + 0x444);
        u32 y = *(const u32 *)((const u8 *)pool + 0x448);
        u32 z = *(const u32 *)((const u8 *)pool + 0x44c);
        ((u32 *)&pos)[0] = x;
        ((u32 *)&pos)[1] = y;
        ((u32 *)&pos)[2] = z;
    }
    if (flags && lbl_1_bss_8CA26 == 0) {
        pos.y -= F(0x254);
        offset = fn_1_B7F58(&result) == 1 ? F(0x4c) : F(0x5c);
        fzgx_value_ = &(pos.x);
        *fzgx_value_ = offset;
        pos.z -= F(0x44);
    } else {
        pos.y -= F(0x254);
    }
    fn_1_8D1C8(lbl_10_bss_51788, fn_10_13128, &pos);
    draw = lbl_1_rodata_26F8;
    if ((state->flags & 0x40000000) && lbl_1_bss_8CA26 == 0) {
        offset = fn_1_B7F58(&result) == 1 ? F(0x4c) : F(0x6c);
        (void) offset;  /* fzgx: keeps the web at its definition */
        {
            f32 x = (f32)(F(0x58) * lbl_10_bss_55690.unk_0) + lbl_10_bss_55698.unk_0;
            f32 y = (f32)(F(0x450) * lbl_10_bss_55690.unk_4) + lbl_10_bss_55698.unk_4;
            x = offset + x;
            draw.y = y;
            draw.x = x;
        }
    } else {
        f32 x = F(0x58) * lbl_10_bss_55690.unk_0;
        f32 y = F(0x2c0) * lbl_10_bss_55690.unk_4;
        x = ((x) + (lbl_10_bss_55698.unk_0));
        y = lbl_10_bss_55698.unk_4 + y;
        draw.x = x;
        draw.y = y;
    }
    draw.z = F(0x54);
    draw.sx = lbl_10_bss_55690.unk_0;
    draw.sy = lbl_10_bss_55690.unk_4;
    if (lbl_1_bss_8CA28 != 0) {
        draw.sx *= F(0x254);
        draw.sy *= F(0x254);
    }
    fzgx_value = &(draw.mode);
    *fzgx_value = 10;
    fn_1_4FC50(&draw,fn_10_12C14_array_read(lbl_10_bss_51788, 13),((u16 *)lbl_10_bss_51788)[24],((u16 *)lbl_10_bss_51788)[25],fn_10_12C14_array_read(lbl_10_bss_51788, 24));
}
#pragma opt_common_subs reset

