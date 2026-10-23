#include "types.h"
#include "rel/car_colchg/globals.h"
#include "rel/car_colchg/car_colchg.h"


extern void colchg_menu_disp(void);
void fn_1_426C(s16);
extern void colchg_ezsel_disp(void);
extern void colchg_save_disp(void);
extern u16 lbl_1_bss_968;
extern struct Struct_lbl_1_bss_D58 lbl_1_bss_D58;
s32 fn_1_4C10(void);
void fn_1_A8EB0(s32, s32);
s32 fn_1_7F49C(s16, s32, void *);
void fn_1_A8DD4(const char *, ...);
void fn_1_80058(s8, struct CarColchgEntry *);
void fn_1_80C18(u32, struct CarColchgEntry *, s32);
void fn_1_426C(s16);
s32 fn_1_4C10(void);
void fn_1_A8EB0(s32, s32);
s32 fn_1_7F49C(s16, s32, void *);
void fn_1_A8DD4(const char *, ...);
void fn_1_80058(s8, struct CarColchgEntry *);
void fn_1_80C18(u32, struct CarColchgEntry *, s32);
extern s16 lbl_1_bss_962;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern struct Struct_lbl_1_bss_970 lbl_1_bss_970;
extern u16 lbl_1_bss_96A;
extern struct Entry *lbl_1_data_1FB6C[];
extern u32 lbl_801A6410;
void fn_1_7FA04(u32);
void fn_1_8D168(u32);
void fn_1_435C(u32);
void fn_1_41A8(void);
void fn_1_46B4(u32, u32, void *, s32);
void fn_1_6400(void);
u16 fn_1_3F8C(char *, void (*)(void), s32, s32);
void fn_1_4A00(s32, s32, u32);
extern void fn_9_1BCC(void);
extern void fn_9_1AC4(void);
extern u32 lbl_801A66A0;

/* fzgx:begin _epilog */
struct CarColchgState {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u8 entries[200];
};

/* Tear down the color-change state and release its two menu entries. */
void _epilog(void) {
    struct CarColchgState *state = (struct CarColchgState *)&lbl_9_bss_0;
    u8 *entry;
    s16 i;

    fn_1_7FA04(state->unk4);
    entry = state->entries;
    for (i = 0; i < 2; i++) {
        fn_1_8D168((u32)entry);
        entry += 100;
    }
    fn_1_435C(state->unkC);
    fn_1_41A8();
    fn_1_435C(state->unk10);
    fn_1_41A8();
    fn_1_46B4(lbl_801A6410, state->unk0, lbl_9_data_4, 0xDA);
    fn_1_6400();
    fn_1_46B4(lbl_801A6410, state->unk8, lbl_9_data_4, 0xDC);
}
/* fzgx:end _epilog */

/* fzgx:begin colchg_menu_init */
void colchg_menu_init(void) {
    // Set up the menu callback and activate the initial collision-color selection.
    fn_1_435C(lbl_9_bss_10);
    lbl_9_bss_DC = fn_1_3F8C(lbl_9_data_2C, colchg_menu_disp, 0, 8);
    fn_1_4A00(1, 15, lbl_9_bss_10);
}
/* fzgx:end colchg_menu_init */

/* fzgx:begin fn_9_454 */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
typedef unsigned long size_t;
struct Struct_lbl_1_bss_D58
{
  u8 pad0[8];
  volatile u16 unk8;  // volatile: decomp-permuter found retail keeps this access order; a revise pass should express it without volatile
  u8 padA[6];
  volatile u16 unk10;  // volatile: decomp-permuter found retail keeps this access order; a revise pass should express it without volatile
  volatile u16 unk12;  // volatile: decomp-permuter found retail keeps this access order; a revise pass should express it without volatile
};
struct Struct_lbl_1_bss_970
{
  u8 pad0[4];
  u8 unk4;
};
void fn_9_454(void)
{
  s32 value;
  s8 delta;
  if (fn_1_4C10() == 0)
  {
    delta = 0;
    if (((lbl_1_bss_D58.unk10 >> 3) & 1) || ((long) ((lbl_1_bss_D58.unk12 >> 3) & 1)))
    {
      delta = -1;
    }
    if (((lbl_1_bss_D58.unk10 >> 2) & 1) || ((lbl_1_bss_D58.unk12 >> 2) & 1))
    {
      delta++;
    }
    if (1)
    {
      value = lbl_1_bss_970.unk4 + delta;
      value = (lbl_1_bss_970.unk4 = (value > 0x73) ? (0x73) : ((value < 0x73) ? (0x73) : (value)));
      if ((lbl_1_bss_D58.unk8 >> 8) & 1)
      {
        lbl_1_bss_96A = value;
      }
      if ((lbl_1_bss_D58.unk8 >> 9) & 1)
      {
        lbl_1_bss_96A = 0x75;
      }
    }
  }
}
/* fzgx:end fn_9_454 */

/* fzgx:begin fn_9_534 */
// Initialize the car color-change state and apply the current selection.
void fn_9_534(void) {
    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
}
/* fzgx:end fn_9_534 */

/* fzgx:begin colchg_selcar_init noprologue */
#include "types.h"

extern struct colchg_selcar_init_lbl_9_bss_0 lbl_9_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_9_1BCC(void);
extern u32 lbl_9_data_40;
extern void colchg_selcar_disp(void);

struct colchg_selcar_init_lbl_9_bss_0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x8];
    u32 unk_10;
    u8 pad_14[0xC8];
    u16 unk_DC;
};

void colchg_selcar_init(void) {
    struct colchg_selcar_init_lbl_9_bss_0 *p_lbl_9_bss_0;
    u32 t2;
    p_lbl_9_bss_0 = (struct colchg_selcar_init_lbl_9_bss_0 *)&lbl_9_bss_0;
    fn_9_1BCC();
    fn_1_435C(p_lbl_9_bss_0->unk_10);
    t2 = fn_1_3F8C((u32)&lbl_9_data_40, (u32)colchg_selcar_disp, p_lbl_9_bss_0->unk_4, 8);
    p_lbl_9_bss_0->unk_DC = t2;
    fn_1_4A00(1, 15, p_lbl_9_bss_0->unk_10);
}
/* fzgx:end colchg_selcar_init */

/* fzgx:begin fn_9_5D8 */
#include "types.h"
#include "rel/car_colchg/globals.h"






s32 fn_1_4C10(void);

struct ColchgState {
    u8 unk_0[8];
    u16 flags_8;
    u8 unk_A[6];
    u16 flags_10;
    u16 flags_12;
};

struct ColchgVolFlags {
    u8 unk_0[8];
    u16 flags_8;
    u8 unk_A[6];
    volatile u16 flags_10;  /* retail re-reads it for the second test: keep the loads distinct */
    volatile u16 flags_12;  /* retail re-reads it for the second test: keep the loads distinct */
};

void fn_9_5D8(void) {
    s8 delta;
    struct ColchgState *state;
    s16 *selection;
    s16 *entry;
    s32 value;

    if (fn_1_4C10() == 0) {
        state = (struct ColchgState *)&lbl_1_bss_D58;
        if ((state->flags_8 >> 9) & 1) {
            (*(s16 *)&lbl_1_bss_96A) = 0x72;
        }
        delta = 0;
        if ((((struct ColchgVolFlags *)&lbl_1_bss_D58)->flags_10 & 1) ||
            (((struct ColchgVolFlags *)&lbl_1_bss_D58)->flags_12 & 1)) {
            delta = -1;
        }
        if ((((struct ColchgVolFlags *)&lbl_1_bss_D58)->flags_10 >> 1 & 1) ||
            (((struct ColchgVolFlags *)&lbl_1_bss_D58)->flags_12 >> 1 & 1)) {
            delta++;
        }
        if (delta != 0) {
            selection = &lbl_9_bss_8->unk_0;
            value = *selection + delta;
            *selection = value > 40 ? 0 : value < 0 ? 40 : value;
        }
        selection = &lbl_9_bss_8->unk_0;
        entry = (*(s16 * (*)[])&lbl_1_data_1FB6C)[*selection];
        if (((state->flags_8 >> 8) & 1) && *entry != -1) {
            (*(s16 *)&lbl_1_bss_96A) = 0x76;
        }
    }
}
/* fzgx:end fn_9_5D8 */

/* fzgx:begin fn_9_6F0 */
// Apply the current car color-change configuration.
void fn_9_6F0(void) {
    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
}
/* fzgx:end fn_9_6F0 */

/* fzgx:begin colchg_selmate_init noprologue */
#include "types.h"
#include "rel/car_colchg/globals.h"

extern u32 lbl_1_data_1FB6C[];
extern void colchg_selmate_disp(void);
void fn_1_435C(u32);
s16 fn_1_3F8C(char *, void (*)(void), u32, s32);
void fn_1_4A00(s32, s32, u32);

struct ColchgSelmateState {
    u32 unk0;
    u32 unk4;
    struct ColchgSelmateCurrent *current;
    u32 unkC;
    u32 unk10;
    u8 pad14[0xC8];
    s16 unkDC;
    u16 padDE;
    u32 unkE0;
};

struct ColchgSelmateCurrent {
    s16 unk0;
    s16 unk2;
    s16 unk4;
};

struct ColchgSelmateEntry {
    s16 unk0;
    u8 pad2[6];
    u32 unk8;
};

typedef struct lbl_9_bss_E0_t {
    u32 unkE0;
    u8 pad_4[0x4];
} lbl_9_bss_E0_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_9_bss_0;
u32 fzgx_obj_lbl_9_bss_4;
struct ColchgSelmateCurrent *fzgx_obj_lbl_9_bss_8;
u32 fzgx_obj_lbl_9_bss_C;
u32 fzgx_obj_lbl_9_bss_10;
u32 fzgx_obj_lbl_9_bss_14[50];
s16 fzgx_obj_lbl_9_bss_DC;
u16 fzgx_pool_lbl_9_bss_0_gap_DE;
lbl_9_bss_E0_t fzgx_obj_lbl_9_bss_E0;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_9_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_4;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_8;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_C;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_10;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_14;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_DC;
    s = *(u8 *)&fzgx_pool_lbl_9_bss_0_gap_DE;
    s = *(u8 *)&fzgx_obj_lbl_9_bss_E0;
}
#pragma section code_type ".text"

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("colchg_selmate_disp");
}
#pragma section code_type ".text"

void colchg_selmate_init(void) {
    
    struct ColchgSelmateEntry *entry = ((struct ColchgSelmateEntry **)lbl_1_data_1FB6C)[fzgx_obj_lbl_9_bss_8->unk0];

    fn_1_435C(fzgx_obj_lbl_9_bss_10);
    fzgx_obj_lbl_9_bss_DC = fn_1_3F8C("colchg_selmate_disp", colchg_selmate_disp, fzgx_obj_lbl_9_bss_4, 8);
    {
        u32 value = fzgx_obj_lbl_9_bss_10;
        fn_1_4A00(1, 15, value);
    }
    fzgx_obj_lbl_9_bss_8->unk2 = entry[fzgx_obj_lbl_9_bss_8->unk4].unk0;
    fzgx_obj_lbl_9_bss_E0.unkE0 = entry[fzgx_obj_lbl_9_bss_8->unk4].unk8;
}
/* fzgx:end colchg_selmate_init */

/* fzgx:begin fn_9_7DC */
#include "types.h"
#include "rel/car_colchg/globals.h"

struct InputState {
    u8 pad[8];
    u16 buttons;
    u8 pad2[6];
    u16 buttons2;
    u16 buttons3;
};

struct Entry {
    s16 id;
    s16 pad;
    s32 unk;
    void *data;
};

struct ColorState {
    s16 unk0;
    s16 selected_id;
    s16 selected;
};

void fn_9_7DC(void) {
    struct Entry *entries;
    s8 change;
    s16 count;
    s32 index;

    entries = lbl_1_data_1FB6C[((struct ColorState *)lbl_9_bss_8)->unk0];
    if (fn_1_4C10() == 0) {
        if ((((struct InputState *)&lbl_1_bss_D58)->buttons >> 8) & 1) {
            lbl_1_bss_96A = 0x77;
        }
        if ((((struct InputState *)&lbl_1_bss_D58)->buttons >> 9) & 1) {
            lbl_1_bss_96A = 0x73;
        }

        change = 0;
        // Direct polling preserves the button-edge reads.
        if ((((volatile struct InputState *)&lbl_1_bss_D58)->buttons2 & 1) ||
            // Direct polling preserves the second button-edge source.
            (((volatile struct InputState *)&lbl_1_bss_D58)->buttons3 & 1)) {
            change = -1;
        }
        // Direct polling preserves the button-edge reads.
        if (((((volatile struct InputState *)&lbl_1_bss_D58)->buttons2 >> 1) & 1) ||
            // Direct polling preserves the second button-edge source.
            ((((volatile struct InputState *)&lbl_1_bss_D58)->buttons3 >> 1) & 1)) {
            change++;
        }

        if (change != 0) {
            count = 0;
            while (lbl_1_data_1FB6C[((struct ColorState *)lbl_9_bss_8)->unk0][count].id != -1) {
                count++;
            }

            entries[((struct ColorState *)lbl_9_bss_8)->selected].data =
                (void *)lbl_9_bss_E0;
            index = ((struct ColorState *)lbl_9_bss_8)->selected + change;
            if (index > count - 1) {
                index = 0;
            } else if (index < 0) {
                index = count - 1;
            }
            ((struct ColorState *)lbl_9_bss_8)->selected = index;
            if (entries[((struct ColorState *)lbl_9_bss_8)->selected].id == -1) {
                index = ((struct ColorState *)lbl_9_bss_8)->selected - change;
                if (index > count - 1) {
                    index = 0;
                } else if (index < 0) {
                    index = count - 1;
                }
                ((struct ColorState *)lbl_9_bss_8)->selected = index;
            }
            ((struct ColorState *)lbl_9_bss_8)->selected_id =
                entries[((struct ColorState *)lbl_9_bss_8)->selected].id;
            lbl_9_bss_E0 =
                (u32)entries[((struct ColorState *)lbl_9_bss_8)->selected].data;
        }

        if (lbl_801A66A0 & 1) {
            entries[((struct ColorState *)lbl_9_bss_8)->selected].data = 0;
        } else {
            entries[((struct ColorState *)lbl_9_bss_8)->selected].data = (void *)-1;
        }
    }
}
/* fzgx:end fn_9_7DC */

/* fzgx:begin fn_9_A18 */
struct Entry {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

struct CarColchgState {
    u8 pad0[8];
    s16 *selection;
    u32 padC;
    u32 value10;
    u8 pad14[0xC8];
    s16 valueDC;
    u32 valueE0;
};

void fn_9_A18(void) {
    struct CarColchgState *state = (struct CarColchgState *)&lbl_9_bss_0;
    struct Entry *entry;

    entry = lbl_1_data_1FB6C[*state->selection];
    fn_1_435C(state->value10);
    fn_1_426C(state->valueDC);
    entry[state->selection[2]].unk8 = state->valueE0;
}
/* fzgx:end fn_9_A18 */

/* fzgx:begin colchg_chgcol_init noprologue */
#include "types.h"

extern struct colchg_chgcol_init_lbl_9_bss_0 lbl_9_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 lbl_9_data_68;
extern void colchg_chgcol_disp(void);

struct colchg_chgcol_init_lbl_9_bss_0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x8];
    u32 unk_10;
    u8 pad_14[0xC8];
    u16 unk_DC;
};

void colchg_chgcol_init(void) {
    struct colchg_chgcol_init_lbl_9_bss_0 *p_lbl_9_bss_0;
    u32 t1;
    p_lbl_9_bss_0 = (struct colchg_chgcol_init_lbl_9_bss_0 *)&lbl_9_bss_0;
    fn_1_435C(p_lbl_9_bss_0->unk_10);
    t1 = fn_1_3F8C((u32)&lbl_9_data_68, (u32)colchg_chgcol_disp, p_lbl_9_bss_0->unk_4, 8);
    p_lbl_9_bss_0->unk_DC = t1;
    fn_1_4A00(1, 15, p_lbl_9_bss_0->unk_10);
}
/* fzgx:end colchg_chgcol_init */

/* fzgx:begin fn_9_DC0 */
// Refresh the collision-change state from the current global settings.
void fn_9_DC0(void) {
    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
}
/* fzgx:end fn_9_DC0 */

/* fzgx:begin colchg_ezsel_init */
// Register the easy-selection display callback and retain its menu handle.
void colchg_ezsel_init(void) {
    fn_1_435C(lbl_9_bss_10);
    lbl_9_bss_DC = fn_1_3F8C(lbl_9_data_9C, colchg_ezsel_disp, 0, 8);
}
/* fzgx:end colchg_ezsel_init */

/* fzgx:begin fn_9_E4C */
#include "types.h"
#include "rel/car_colchg/globals.h"

struct ColchgState {
    u8 pad[8];
    u16 flags;
    u8 pad_a[6];
    volatile u16 input_a; // Input state may be updated between reads.
    volatile u16 input_b; // Input state may be updated between reads.
};




s32 fn_1_4C10(void);

void fn_9_E4C(void) {
    struct ColchgState *state;
    s8 change;

    if (fn_1_4C10() == 0) {
        state = &(*(struct ColchgState *)&lbl_1_bss_D58);
        if ((state->flags >> 9) & 1) {
            lbl_1_bss_96A = 0x72;
        }
        change = 0;
        if (((*(struct ColchgState *)&lbl_1_bss_D58).input_a & 1) || ((*(struct ColchgState *)&lbl_1_bss_D58).input_b & 1)) {
            change = -1;
        }
        if ((((*(struct ColchgState *)&lbl_1_bss_D58).input_a >> 1) & 1) ||
            (((*(struct ColchgState *)&lbl_1_bss_D58).input_b >> 1) & 1)) {
            change++;
        }
        if (change != 0) {
            s32 result;
            s32 value;
            value = *(s16 *)lbl_9_bss_8 + change;
            if (value > 40) {
                value = 0;
            } else {
                value = value < 0 ? 40 : value;
            }
            *(s16 *)lbl_9_bss_8 = value;
        }
        if ((state->flags >> 8) & 1) {
            lbl_1_bss_96A = 0x76;
        }
    }
}
/* fzgx:end fn_9_E4C */

/* fzgx:begin fn_9_F38 */
// Initialize the color-change subsystem and apply its current configuration.
void fn_9_F38(void) {
    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
}
/* fzgx:end fn_9_F38 */

/* fzgx:begin colchg_save_init */
// Register the save-screen callback and reset the color-change save state.
void colchg_save_init(void) {
    fn_1_435C(lbl_9_bss_10);
    lbl_9_bss_DC = fn_1_3F8C(lbl_9_data_B0, colchg_save_disp, 0, 8);
    lbl_1_bss_968 = 10;
}
/* fzgx:end colchg_save_init */

/* fzgx:begin fn_9_FD0 */
struct Struct_lbl_1_bss_D58 {
    u8 pad[8];
    u16 unk8;
};

void fn_9_FD0(void) {
    if (fn_1_4C10() == 0) {
        if ((lbl_1_bss_D58.unk8 >> 9) & 1) {
            lbl_1_bss_968 = 0xA;
        }
    }
}
/* fzgx:end fn_9_FD0 */

/* fzgx:begin fn_9_1018 */
// Initializes the color-change subsystem from its configured state.
void fn_9_1018(void) {
    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
}
/* fzgx:end fn_9_1018 */

/* fzgx:begin fn_9_1054 */
// Sets up the color-change display callback and selects the default palette.
void fn_9_1054(void) {
    u16 display_mode;

    fn_9_1BCC();
    fn_1_435C(lbl_9_bss_10);
    display_mode = fn_1_3F8C((char *)lbl_9_data_C4, fn_9_1AC4, 0, 8);
    lbl_9_bss_DC = display_mode;
    fn_1_4A00(1, 15, lbl_9_bss_10);
}
/* fzgx:end fn_9_1054 */

/* fzgx:begin fn_9_10BC */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
typedef unsigned long size_t;
struct Struct_lbl_1_bss_D58
{
  u8 pad[8];
  u16 unk8;
};
inline u16 *inline_fn(u16 *arg0)
{
  return arg0;
}

void fn_9_10BC(void)
{
  u16 value;
  u16 *new_var;
  u16 *p;
  if (fn_1_4C10() == 0)
  {
    p = &lbl_1_bss_96A;
    value = 0x73;
    *p = value;
    new_var = inline_fn(p);
    if ((lbl_1_bss_D58.unk8 >> 9) & 1)
    {
      *new_var = 0x72;
    }
    if (((lbl_1_bss_D58.unk8 >> 8) & 1) != 0U)
    {
      lbl_1_bss_96A = 0x76;
    }
  }
}
/* fzgx:end fn_9_10BC */

/* fzgx:begin fn_9_1124 */
void fn_9_1124(void)
{
    // Apply the active color-change state before refreshing the selection display.
    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
}
/* fzgx:end fn_9_1124 */

/* fzgx:begin colchg_menu_disp */
extern const f32 lbl_9_rodata_14;
extern const f32 lbl_9_rodata_18;
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern struct Struct_lbl_1_bss_970 lbl_1_bss_970;

void colchg_menu_disp(void)
{
    u32 base = (u32)&lbl_9_data_0;
    u8 *sel;
    s8 i;

    fn_1_496FC(lbl_9_rodata_14, lbl_9_rodata_18);
    fn_1_4AE0C((const char *)(base + 0xd8));
    sel = (u8 *)&lbl_1_bss_970;
    for (i = 0x72; i < 0x79; i++) {
        switch (i) {
        case 0x73:
            fn_1_4AE0C((const char *)(base + 0xe8), (const char *)(sel[4] == i ? base + 0xfc : base + 0x98));
            break;
        }
    }
}
/* fzgx:end colchg_menu_disp */

/* fzgx:begin fn_9_120C */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table2[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 160.0f;
    s = 50.0f;
    s = -10.0f;
    s = 182.04444885253906f;
    s = 2.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

struct Car {
    u8 pad_0[0x3b8];
    s16 unk_3b8;
};

extern u32 lbl_801A66A0;
extern void lbl_8006D7F4(void *, f32, f32, f32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E14C(f32);
extern void fn_80072558(void);
extern void fn_1_870BC(struct Car *, s8, struct Car *, s32, u8, f32);

s32 fn_9_120C(struct Car *car) {
    s16 state_value;
    struct Car *self;
    Obj_9_bss_8_Target *state;

    state = lbl_9_bss_8;
    state_value = state->unk_C;
    self = car;
    lbl_8006D7F4(state, 0.0f, 0.0f, -10.0f);
    mathutil_mtxA_rotate_y(-0x8000);
    mathutil_mtxA_rotate_x(0x10000 - 0x2000);
    mathutil_mtxA_rotate_y((s32)((f32)(lbl_801A66A0 % 360) * 182.04444885253906f));
    lbl_8006E14C(2.0f);
    fn_80072558();
    fn_1_870BC(self, (s8)state_value, self, 0, (u8)self->unk_3b8, 1.0f);
    return 0;
}
/* fzgx:end fn_9_120C */

/* fzgx:begin fn_9_1310 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d; /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table2[3] = {0, 0, 0}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static inline void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d; /* fzgx-allow: S2 pool primer sinks */
    s = 160.0f;
    s = 50.0f;
    s = -10.0f;
    s = 182.04444885253906f;
    s = 2.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static inline void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d; /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
#pragma section code_type ".text"
struct Car_9_1310 {
    u8 pad_0[0x3b8];
    s16 unk_3b8;
};
extern u32 lbl_801A66A0;
void lbl_8006D7F4(f32, f32, f32);
void mathutil_mtxA_rotate_y(s32);
void mathutil_mtxA_rotate_x(s32);
void lbl_8006E14C(f32);
extern void fn_80072558(void);
void fn_1_870BC(struct Car_9_1310 *, s8, struct Car_9_1310 *, s32, u8, f32);
#pragma opt_propagation on
s32 fn_9_1310(struct Car_9_1310 *car) {
    u32 *rng;
    f32 angle;
    struct { s32 value; } color;
    struct { struct Car_9_1310 *value; } held_car;
    held_car.value = car;
    color.value = lbl_9_bss_8->unk_C;
    lbl_8006D7F4(0.0f, 0.0f, -10.0f);
    mathutil_mtxA_rotate_y(-0x8000);
    rng = &lbl_801A66A0;
    mathutil_mtxA_rotate_x(0x2000);
    angle = 182.04444885253906f * (f32)(*rng % 0x168);
    mathutil_mtxA_rotate_y((s32)angle);
    lbl_8006E14C(2.0f);
    fn_80072558();
    fn_1_870BC(held_car.value, (s8)color.value, held_car.value, 0, (u8)held_car.value->unk_3b8, 1.0f);
    return 0;
}
/* fzgx:end fn_9_1310 */

/* fzgx:begin colchg_selcar_disp noprologue */
#include "rel/car_colchg/car_colchg.h"
#include "dolphin/types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table2[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 160.0f;
    s = 50.0f;
    s = -10.0f;
    s = 182.04444885253906f;
    s = 2.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 250.0f;
    s = 255.0f;
    s = 0.5f;
    s = 480.0f;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

typedef struct { u32 words[2]; f32 x; f32 y; u32 rest[18]; } SelectionPanel;
extern const SelectionPanel lbl_1_rodata_26F8;
extern s16 *lbl_1_data_1FB6C[];
extern u16 lbl_1_bss_D58;
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern char *fn_1_7F49C(s16, s16, char *);
extern unsigned long strlen(const char *);
extern char *fn_80083DB0(char *, const char *);
extern void fn_1_4B83C(char *, const char *, const char *, const char *);
extern int sprintf(char *, const char *, ...);
extern f32 fn_1_4B040(const char *);
extern void fn_1_4955C(f32, f32);
extern s32 fn_9_120C(void *);
extern void fn_9_1310(u32);
extern u32 fn_1_8D3F8(void *, const SelectionPanel *, void *, void *);

void colchg_selcar_disp(void *cars)
{
    char format[32];
    char longest[32];
    char text[32];
    char name[32];
    SelectionPanel panel;
    s16 *data = (s16 *)&lbl_9_data_0;
    s16 car_id = lbl_9_bss_8->unk_0;
    s16 i;
    s32 max_length;
    s16 *car = lbl_1_data_1FB6C[car_id];
    fn_1_496FC(160.0f, 50.0f);
    fn_1_4AE0C((char *)data + 0x100);
    max_length = 0;
    fn_1_7F49C(lbl_9_bss_8->unk_0, *data, name);
    for (i = 0; i < 41; i++) {
        s32 length = strlen(name);
        if (length > max_length) {
            max_length = length;
            fn_80083DB0(longest, name);
        }
    }
    fn_1_4B83C(format, (char *)data + 0x118, longest, name);
    sprintf(text, format, name);
    fn_1_4955C(250.0f / fn_1_4B040(text), 1.0f);
    fn_1_4AE0C(text);
    fn_1_4955C(1.0f, 1.0f);
    fn_1_4955C(1.0f, 1.0f);
    fn_1_4AE0C((char *)data + 0x120, lbl_9_bss_8->unk_0);
    if (((lbl_1_bss_D58 >> 8) & 1) && *car == -1) {
        fn_1_4AE0C((char *)data + 0x128);
    }
    {
    s16 fzgx_loop_i_1785;
for (fzgx_loop_i_1785 = 0; fzgx_loop_i_1785 < 2; fzgx_loop_i_1785++) {
        panel = lbl_1_rodata_26F8;
        panel.y = 255.0f;
        panel.x = 0.5f * (480.0f * (fzgx_loop_i_1785 % 2));
        switch (fzgx_loop_i_1785) {
        case 0:
            fn_1_8D3F8(lbl_9_bss_14 + fzgx_loop_i_1785 * 100, &panel, fn_9_120C, (u8 *)cars + car_id * 0x440);
            break;
        case 1:
            fn_1_8D3F8(lbl_9_bss_14 + fzgx_loop_i_1785 * 100, &panel, fn_9_1310, (u8 *)cars + car_id * 0x440);
            break;
        }
    }
    i = fzgx_loop_i_1785;
}
}
/* fzgx:end colchg_selcar_disp */

/* fzgx:begin colchg_selmate_disp */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table2[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 160.0f;
    s = 50.0f;
    s = -10.0f;
    s = 182.04444885253906f;
    s = 2.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 250.0f;
    s = 255.0f;
    s = 0.5f;
    s = 480.0f;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

typedef struct {
    u8 pad_00[0x14];
    f32 unk_14;
    u8 pad_1c[0x20];
    f32 unk_18;
    f32 unk_3c;
    f32 unk_40;
    f32 unk_44;
    f64 unk_48;
} PoolRow;
extern const PoolRow lbl_9_rodata_0;

typedef struct {
    u8 pad_00[8];
    f32 unk_08;
    f32 unk_0c;
    u8 pad_10[0x48];
} SelmateBlk;
extern const SelmateBlk lbl_1_rodata_26F8;

extern u8 lbl_9_data_150[0x28];
extern u8 lbl_9_bss_14[0xC8];
extern struct Entry *lbl_1_data_1FB6C[];

void fn_9_120C(void);
void fn_9_1310(void);
void fn_1_496FC(void *, f32, f32);
void fn_1_4AE0C(const char *, ...);
void fn_1_8D3F8(void *, void *, void (*)(void), void *);

typedef struct Entry Entry;

void colchg_selmate_disp(u8 *car) {
    u8 *widget;
    f32 f30;
    f32 f29;
    f32 f28;
    SelmateBlk local;
    struct { s16 value; } i;
    struct Entry *entry;
    const PoolRow *pool;
    s16 index;
    f32 lab_t1;

    pool = &lbl_9_rodata_0;
    index = lbl_9_bss_8->unk_0;
    lab_t1 = (160.0f);
    fn_1_496FC(lbl_9_bss_8, lab_t1, (50.0f));
    entry = lbl_1_data_1FB6C[lbl_9_bss_8->unk_0];
    i.value = 0;
    while (*(s16 *)entry != -1) {
        entry = (struct Entry *)((u8 *)entry + 12);
        i.value++;
    }
    fn_1_4AE0C((const char *)lbl_9_data_150, lbl_9_bss_8->unk_2, lbl_9_bss_8->unk_4, i.value - 1);
    f28 = (255.0f);
    f29 = (0.5f);
    f30 = (480.0f);
    for (i.value = 0; i.value < 2; i.value++) {
        local = lbl_1_rodata_26F8;
        local.unk_0c = f28;
        local.unk_08 = (((((f30)) * (((f32)(i.value % 2)))) * ((f29))));
        switch (i.value) {
        case 0:
            fn_1_8D3F8(&lbl_9_bss_14[i.value * 0x64], &local, fn_9_120C, car + index * 0x440);
            break;
        case 1:
            fn_1_8D3F8(&lbl_9_bss_14[i.value * 0x64], &local, fn_9_1310, car + index * 0x440);
            break;
        }
    }
}
/* fzgx:end colchg_selmate_disp */

/* fzgx:begin colchg_chgcol_disp */
extern u8 lbl_9_data_178[20];
extern u8 lbl_9_bss_14[200];
extern u8 lbl_1_rodata_26F8[88];
extern void fn_9_120C(void);
extern void fn_9_1310(void);

void fn_1_496FC(void *, f32, f32);
void fn_1_4AE0C(const char *, ...);
void fn_1_8D3F8(void *, void *, void (*)(void), void *);

typedef struct {
    u8 pad_0[0x8];
    f32 value_8;
    f32 value_c;
    u8 pad_10[0x48];
} ChgColDispData;

#pragma opt_lifetimes off
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table2[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 160.0f;
    s = 50.0f;
    s = -10.0f;
    s = 182.04444885253906f;
    s = 2.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 250.0f;
    s = 255.0f;
    s = 0.5f;
    s = 480.0f;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"
void colchg_chgcol_disp(void *car) {
    ChgColDispData data;
    u8 *entry;
    f32 value_a;
    f32 value_b;
    f32 value_c;
    s16 i;

    i = lbl_9_bss_8->unk_0;
    fn_1_496FC(lbl_9_bss_8, 160.0f, 50.0f);
    fn_1_4AE0C((const char *)lbl_9_data_178);
    value_a = 255.0f;
    value_b = 0.5f;
    value_c = 480.0f;
    entry = ((i * 0x440) + ((u8 *)car));
    i = 0;
    for (; i < 2; i++) {
        data = *(ChgColDispData *)lbl_1_rodata_26F8;
        data.value_c = value_a;
        data.value_8 = value_c * (i % 2) * value_b;
        switch (i) {
        case 0:
            fn_1_8D3F8(lbl_9_bss_14 + i * 100, &data, fn_9_120C, entry);
            break;
        case 1:
            fn_1_8D3F8(lbl_9_bss_14 + i * 100, &data, fn_9_1310, entry);
            break;
        }
    }
}
#pragma opt_lifetimes reset
/* fzgx:end colchg_chgcol_disp */

/* fzgx:begin colchg_ezsel_disp */
void colchg_ezsel_disp(void) {
    u8 buffer[0x20];
    s32 value;

    fn_1_A8EB0(0x14, 0x14);
    value = fn_1_7F49C(*(s16 *)lbl_9_bss_8, 0, buffer);
    fn_1_A8DD4(lbl_9_data_18C, *(s16 *)lbl_9_bss_8, 0x29, value);
}
/* fzgx:end colchg_ezsel_disp */

/* fzgx:begin colchg_save_disp */
void colchg_save_disp(void) {
    fn_1_A8EB0(0x14, 0x14);
    fn_1_A8DD4(lbl_9_data_19C);
}
/* fzgx:end colchg_save_disp */

/* fzgx:begin fn_9_1AC4 */
void fn_9_1AC4(void) {
    fn_1_A8EB0(0x14, 0xa);
    fn_1_A8DD4(lbl_9_data_1A4);
}
/* fzgx:end fn_9_1AC4 */

/* fzgx:begin fn_9_1AFC */
extern const f32 lbl_9_rodata_0;

extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(void *, f32, f32, f32);
extern void fn_1_7BCCC(void *);
extern void fn_80035680(void *, f32, f32, f32);
extern void fn_80035690(void *, f32, f32, f32);
extern void fn_80035420(void *, f32, s32);
extern void fn_800356AC(void *, void *);
extern void GXInitLightDistAttn(void *, s32, f32, f32);
extern void fn_1_7BB80(void *, s32);
extern void fn_1_7BD6C(s32);
extern void fn_80074CF4(f32, f32, f32);

struct Fn_9_1AFCVec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct Fn_9_1AFCBigVec3 {
    f32 x;
    f32 y;
    f32 z;
    u8 pad[0x34];
};

void fn_9_1AFC(void) {
    u32 value;
    struct Fn_9_1AFCBigVec3 b;
    struct Fn_9_1AFCVec3 a;
    const u8 *pool;
    u8 pad[0x30];

    pool = (const u8 *)&lbl_9_rodata_0;
    lbl_8006DCA4();
    lbl_8006E1D8(&a, *(const f32 *)(pool + 0x54), *(const f32 *)(pool + 0x54), *(const f32 *)(pool + 0x54));
    fn_1_7BCCC(&a);
    fn_80035680(&b, a.x, a.y, a.z);
    fn_80035690(&b, a.x, a.y, a.z);
    fn_80035420(&b, *(const f32 *)pool, 0);
    value = *(const u32 *)(pool + 0x50);
    fn_800356AC(&b, &value);
    GXInitLightDistAttn(&b, 0, *(const f32 *)pool, *(const f32 *)pool);
    fn_1_7BB80(&b, 1);
    fn_1_7BD6C(1);
    fn_80074CF4(*(const f32 *)(pool + 0x58), *(const f32 *)(pool + 0x58), *(const f32 *)(pool + 0x58));
}
/* fzgx:end fn_9_1AFC */

/* fzgx:begin fn_9_1BCC */
struct CarColchgEntry {
    s16 unk0;
    u16 unk2;
    u32 unk4;
    u8 pad8[24];
};

void fn_9_1BCC(void) {
    struct CarColchgEntry entries[0x29];
    s8 i;

    for (i = 0; i < 0x29; i++) {
        fn_1_80058(i, &entries[i]);
        entries[i].unk4 = 1;
        entries[i].unk0 = i;
    }
    fn_1_80C18(lbl_9_bss_4, entries, 0x29);
}
/* fzgx:end fn_9_1BCC */

/* fzgx:begin fn_9_1C54 */
struct CarColchgEntry {
    u8 pad[0x20];
    void (*func)(void);
    u32 value24;
    u32 value28;
};

// Select the color-change entry for the current car and invoke its handler.
void fn_9_1C54(void) {
    struct CarColchgEntry *entry;
    s16 index;

    entry = (struct CarColchgEntry *)&lbl_9_data_1B8;
    index = lbl_1_bss_962;
    entry += index - 0x71;

    lbl_1_bss_71688 = entry->value24;
    lbl_1_bss_7168C = entry->value28;
    entry->func();
}
/* fzgx:end fn_9_1C54 */
