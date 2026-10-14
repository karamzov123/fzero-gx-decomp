/* Non-matching: best partial attempt (77.24% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"

typedef struct { u16 buttons; u8 pad2[6]; u16 pressed; u8 padA[6]; u16 repeat; u16 other; } Pad;
typedef struct { s16 id; u8 pad2[8]; s16 price; u8 padC[4]; } Item;
typedef struct { u8 pad0[0xC2]; s16 selected; s16 scroll; } Selection;
typedef struct { u8 pad0[0x18]; s16 timer; u8 pad1A[0xDC]; s16 controller; } State;
typedef struct { u8 pad0[0x6BA0]; s16 count; } High;
extern Pad lbl_1_bss_9F8[];
extern u8 lbl_1_bss_7F0C0[];
extern s32 lbl_801A66A8;
extern void fn_3_7A08(s16 *, s16 *, int);
extern void fn_3_BD00(u32, u32, u32, u32);
extern void fn_1_A2D84(u32);
extern s32 fn_1_F809C(s32);
extern void fn_1_F8214(s16);

s16 fn_3_7360(void) {
    State *state = (State *)&lbl_3_bss_0;
    High *high = (High *)&lbl_3_bss_0;
    Selection *selection;
    s32 offset;
    s32 old;
    s32 step = 0;
    s16 delta;
    s32 next;
    s32 timer;
    s16 low, upper;
    s16 id, price;
    offset = state->controller * 20;
    if ((lbl_1_bss_9F8[offset / 20].repeat & 8) || (lbl_1_bss_9F8[offset / 20].other & 8)) step = -1;
    if ((lbl_1_bss_9F8[offset / 20].repeat & 4) || (lbl_1_bss_9F8[offset / 20].other & 4)) step++;
    selection = (Selection *)((u8 *)state + 0x20);
    delta = step;
    old = selection->selected;
    next = old + delta;
    if (next < 0) next = 0;
    else if (next > high->count - 1) next = high->count - 1;
    selection->selected = next;
    timer = state->timer + 1;
    state->timer = timer < 10 ? timer : 10;
    if (old != selection->selected) {
        state->timer = 0;
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
        if (old != selection->selected) {
            fn_3_7A08(&low, &upper, 6);
            if (selection->selected < low || selection->selected > upper) {
                fn_3_BD00(step, 0, (s16)(delta * 10), 0x08000001);
                selection->scroll -= step;
            }
        }
    }
    if (lbl_1_bss_9F8[offset / 20].pressed & 0x100) {
        Item *item = (Item *)((u8 *)high + 0x6EF0) + selection->selected;
        id = item->id;
        price = item->price;
        if (fn_1_F809C(id) == 0 && *(u32 *)(lbl_1_bss_7F0C0 + 0x48F8) >= price) {
            *(u32 *)(lbl_1_bss_7F0C0 + 0x48F8) -= price;
            fn_1_F8214(id);
            *(s32 *)((u8 *)state + 8) = 1;
            fn_1_A2D84(0xA9010100);
            *(s32 *)((u8 *)state + 12) = 1;
        } else fn_1_A2D84(0xA9011400);
    }
    if (lbl_1_bss_9F8[offset / 20].buttons & 0x200) {
        fn_1_A2D84(0xA9010200);
        return -1;
    }
    return 0;
}
