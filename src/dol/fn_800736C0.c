#include "types.h"

typedef struct {
    u8 r, g, b, a;
} fn_800736C0_Color;

struct fn_800736C0_entry {
    u8 pad_0[0x6F4];
    s32 unk_6F4[4];
    fn_800736C0_Color unk_704[4];
};

extern struct fn_800736C0_entry *lbl_801A6D38;
extern void fn_800372E0(s32, fn_800736C0_Color);

/* Set TEV constant color INDEX through the per-slot cache, skipping redundant GX calls. */
void fn_800736C0(s32 index, fn_800736C0_Color color) {
    if (lbl_801A6D38->unk_704[index].r != color.r || lbl_801A6D38->unk_704[index].g != color.g ||
        lbl_801A6D38->unk_704[index].b != color.b || lbl_801A6D38->unk_704[index].a != color.a ||
        lbl_801A6D38->unk_6F4[index] != 0) {
        fn_800372E0(index, color);
        lbl_801A6D38->unk_6F4[index] = 0;
        lbl_801A6D38->unk_704[index] = color;
    }
}
