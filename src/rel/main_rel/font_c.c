#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"

typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

typedef struct fn_1_54668_node {
    struct fn_1_54668_node *next;
    void *data;
} fn_1_54668_node;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

typedef struct fn_1_563E4_FontState {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState;

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;

typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;

typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;

typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;

typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;

struct fn_1_530C8_lbl_1_rodata_282C {
    f32 unk_0;
};

struct FzgxCopy_88 { u32 words[22]; };
extern void fn_80072558(void);
extern void fn_800720B0(int);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);

/* fzgx:begin fn_1_5415C */
void fn_1_5415C(void *arg, s32 value) {
    fn_1_541A8(arg, value);
}
/* fzgx:end fn_1_5415C */

/* fzgx:begin fn_1_5417C */
void fn_1_5417C(void *arg) {
    fn_1_541A8(arg, lbl_801A66B4);
}
/* fzgx:end fn_1_5417C */

/* fzgx:begin fn_1_541A8 */
// Select the localized form for a number and column, including the special 10–20 range.
void *fn_1_541A8(void *arg, s32 column) {
    s32 is_special;
    u32 remainder;
    s32 row_index;
    u32 *row;
    u32 number = (u32)arg;

    if (number == 0) {
        return &lbl_1_data_1C5DC;
    }

    remainder = number - (number / 100) * 100;
    is_special = 0;
    if (remainder >= 10 && remainder <= 20) {
        is_special = 1;
    }

    if (is_special != 0) {
        row_index = 3;
    } else {
        number = remainder - (remainder / 10) * 10;
        is_special = 0;
        if (number >= 4 || number == 0) {
            is_special = 1;
        }
        row_index = 3;
        if (is_special == 0) {
            row_index = number - 1;
        }
    }

    row = (u32 *)(lbl_1_data_1C5EC + row_index * 24);
    return (void *)row[column < 0 ? 0 : (column > 5 ? 5 : column)];
}
/* fzgx:end fn_1_541A8 */

/* fzgx:begin fn_1_54278 */
void fn_1_54278(u32 arg0, u32 arg1) {
    lbl_1_bss_4C680 = arg0;
    lbl_1_bss_4C684 = arg1;
}
/* fzgx:end fn_1_54278 */

/* fzgx:begin fn_1_5428C */
void fn_1_5428C(f32 value) {
    lbl_1_data_1C508.unk_0 = value;
}
/* fzgx:end fn_1_5428C */

/* fzgx:begin fn_1_54298 */
u32 fn_1_54298(void) {
    return lbl_1_bss_4C680;
}
/* fzgx:end fn_1_54298 */

/* fzgx:begin fn_1_542A8 */
u32 fn_1_542A8(void) {
    return lbl_1_bss_4C684;
}
/* fzgx:end fn_1_542A8 */

/* fzgx:begin fn_1_542B8 */
f32 fn_1_542B8(void) {
    return lbl_1_data_1C508.unk_0;
}
/* fzgx:end fn_1_542B8 */

/* fzgx:begin fn_1_542C4 */
typedef struct fn_1_542C4_FontState {
    u8 pad30[0x30];
    void *unk_30;
    void *unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    u8 pad44[8];
    f32 unk_4C;
} fn_1_542C4_FontState;

// Volatile preserves the repeated loads of the shared font state.
#define FONT_STATE ((fn_1_542C4_FontState *)lbl_801A66CC)

// Store the current font parameters and notify the font system.
void fn_1_542C4(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4) {
    FONT_STATE->unk_30 = arg0;
    FONT_STATE->unk_34 = arg1;
    FONT_STATE->unk_38 = arg2;
    FONT_STATE->unk_3C = arg3;
    FONT_STATE->unk_40 = arg4;
    FONT_STATE->unk_4C = arg4 - arg3;
    fn_1_54320();
}
/* fzgx:end fn_1_542C4 */

/* fzgx:begin fn_1_54320 */
struct fn_1_54320_lbl_801A66CC {
    u32 unk_0;
};

u32 fn_1_54320(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    v0 = (*(struct fn_1_54320_lbl_801A66CC *)&lbl_801A66CC).unk_0;
    fn_1_54668( (fn_1_54668_node *)(*(u32 *)(v0 + 48)), *(u32 *)(v0 + 52), 1);
    v1 = (*(struct fn_1_54320_lbl_801A66CC *)&lbl_801A66CC).unk_0;
    *(u32 *)((u8 *)v1 + 68) = (*(u32 *)((u8 *)v1 + 48) + ((*(u32 *)((u8 *)v1 + 52) - 1) << 3));
    v2 = (*(struct fn_1_54320_lbl_801A66CC *)&lbl_801A66CC).unk_0;
    *(u32 *)((u8 *)v2 + 72) = *(u32 *)((u8 *)v2 + 48);
    return v2;
}
/* fzgx:end fn_1_54320 */

/* fzgx:begin fn_1_54384 */
typedef struct fn_1_54384_FontState {
    u8 pad_00[0x30];
    u8 *glyphs;
    s32 glyph_count;
    f32 start;
    f32 end;
    u8 pad_40[4];
    u8 *lower;
    u8 *upper;
    f32 step;
} fn_1_54384_FontState;



u8 *fn_1_54384(f32 value) {
    fn_1_54384_FontState *state = (*(fn_1_54384_FontState * *)&lbl_801A66CC);
    f32 pos = -value + state->start;
    f32 adjusted = pos - state->end;
    s32 index;
    s32 count;
    u8 *entry;

    if (adjusted < lbl_1_rodata_2870) {
        index = 0;
    } else {
        count = state->glyph_count;
        index = (count * adjusted /
                      (adjusted + state->step));
        if (index >= count) {
            index = count - 1;
        }
    }

    entry = state->glyphs + index * 8;
    if (state->lower > entry) {
        state->lower = entry;
    }
    if ((*(fn_1_54384_FontState * *)&lbl_801A66CC)->upper < entry) {
        (*(fn_1_54384_FontState * *)&lbl_801A66CC)->upper = entry;
    }
    return entry;
}
/* fzgx:end fn_1_54384 */

/* fzgx:begin fn_1_54448 */
struct fn_1_54448_lbl_801A66CC {
    u32 unk_0;
};

void **fn_1_54448(s32 arg0) {
    void **temp_r3;

    temp_r3 = (void **)((*(s32 *)(((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 48)) + (arg0 * 8));
    if ((void **) (*(void ***)((u8 *)((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 68)) > temp_r3) {
        (*(void ***)((u8 *)((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 68)) = (void **)(temp_r3);
    }
    if ((void **) (*(void ***)(((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 72)) < temp_r3) {
        (*(void ***)(((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 72)) = (void **)(temp_r3);
        return temp_r3;
    }
    return temp_r3;
}
/* fzgx:end fn_1_54448 */

/* fzgx:begin fn_1_5448C */
typedef struct {
    u8 pad_0[0x30];
    u8 *table;
    s32 count;
    f32 value_38;
    f32 clamp_3c;
    u8 pad_40[4];
    u8 *current;
    u8 *maximum;
    f32 value_4c;
} FontGlobals;



static inline f32 fn_1_5448C_read_pointer(FontGlobals * owner) { return owner->value_4c; }
u32 fn_1_5448C(arg, lab_unused0, lab_unused1, lab_unused2)
void *arg;
u32 lab_unused0;
u32 lab_unused1;
u32 lab_unused2;
{
    f32 fzgx_live_;
    f32 fzgx_live;
    Vec3 vec;
    f32 clamp;
    f32 sum;
    f32 distance;
    s32 index;
    u8 *entry;
    u8 *state;

    lbl_8006E1B0(arg, &vec);
    state = lbl_801A66CC;
    clamp = ((FontGlobals *)state)->clamp_3c;
    fzgx_live = vec.z;
    vec.z = -fzgx_live;
    if (vec.z < clamp) {
        vec.z = clamp;
    }

    sum = vec.x * vec.x;
    fzgx_live_ = vec.y;
    sum += fzgx_live_ * fzgx_live_;
    fzgx_live = vec.z;
    sum += fzgx_live * fzgx_live;
    distance = lbl_8006D0B4(sum);
    state = lbl_801A66CC;
    distance = ((FontGlobals *)state)->value_38 + distance - clamp;

    if (distance < (0.0f)) {
        index = 0;
    } else {
        index = (((FontGlobals *)state)->count * distance / (distance + fn_1_5448C_read_pointer((FontGlobals *)state)));
        if (index >= ((FontGlobals *)state)->count) {
            index = ((FontGlobals *)state)->count - 1;
        }
    }

    entry = ((FontGlobals *)state)->table + (index << 3);
    if (((FontGlobals *)state)->current > entry) {
        ((FontGlobals *)state)->current = entry;
    }
    if (((FontGlobals *)lbl_801A66CC)->maximum < entry) {
        ((FontGlobals *)lbl_801A66CC)->maximum = entry;
    }
    return (u32)entry;
}
/* fzgx:end fn_1_5448C */

/* fzgx:begin fn_1_545B8 */
typedef struct fn_1_545B8_manager {
    u8 unk_00[0x30];
    void *unk_30;
    u32 unk_34;
    u8 unk_38[0x0C];
    u32 *unk_44;
    u32 *unk_48;
} fn_1_545B8_manager;


// Reset the font manager's node list and process any completed nodes.
void fn_1_545B8(void) {
    if (((fn_1_545B8_manager *)lbl_801A66CC)->unk_48 >=
        ((fn_1_545B8_manager *)lbl_801A66CC)->unk_44) {
        if (((fn_1_545B8_manager *)lbl_801A66CC)->unk_44 >
            ((fn_1_545B8_manager *)lbl_801A66CC)->unk_30) {
            *(((fn_1_545B8_manager *)lbl_801A66CC)->unk_44 - 2) = 0;
        }
        fn_1_547F8( (fn_1_547F8_node *)(((fn_1_545B8_manager *)lbl_801A66CC)->unk_48));
    }

    fn_1_54668( (fn_1_54668_node *)(((fn_1_545B8_manager *)lbl_801A66CC)->unk_30),
                ((fn_1_545B8_manager *)lbl_801A66CC)->unk_34, 1);
    ((fn_1_545B8_manager *)lbl_801A66CC)->unk_44 =
        (u32 *)((u8 *)((fn_1_545B8_manager *)lbl_801A66CC)->unk_30 +
                (((fn_1_545B8_manager *)lbl_801A66CC)->unk_34 - 1) * 8);
    ((fn_1_545B8_manager *)lbl_801A66CC)->unk_48 =
        ((fn_1_545B8_manager *)lbl_801A66CC)->unk_30;
    fn_1_9FA18();
    fn_1_58248();
}
/* fzgx:end fn_1_545B8 */

/* fzgx:begin fn_1_54668 */
// Initialize a forward- or reverse-linked list and notify the allocator.
void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse) {
    s32 i;

    if (reverse == 0) {
        i = count - 1;
        for (; i > 0; i--) {
            node->next = node + 1;
            node->data = 0;
            node++;
        }
        node->next = 0;
        node->data = 0;
    } else {
        i = count - 1;
        node += i;
        for (; i > 0; i--) {
            node->next = node - 1;
            node->data = 0;
            node--;
        }
        node->next = 0;
        node->data = 0;
    }
    fn_1_54848();
}
/* fzgx:end fn_1_54668 */

/* fzgx:begin fn_1_547F8 */
// Invoke each node callback while walking the linked list.
void fn_1_547F8(fn_1_547F8_node *node) {
    while (node != 0) {
        if (node->callback != 0) {
            node->callback(node);
        }
        node = node->next;
    }
}
/* fzgx:end fn_1_547F8 */

/* fzgx:begin fn_1_54848 */
typedef struct fn_1_54848_FontState {
    u8 pad_1a0[0x1a0];
    u32 unk_1a0;
    u32 unk_1a4;
    u32 unk_1a8;
    u32 unk_1ac;
} fn_1_54848_FontState;

// Volatile forces each global-state access to retain the retail load ordering.
typedef fn_1_54848_FontState fn_1_54848_VolatileFontState;

// Synchronize the current and previous font-state values for the next update.
void fn_1_54848(void) {
    ((fn_1_54848_VolatileFontState *)lbl_801A66CC)->unk_1a0 =
        ((fn_1_54848_VolatileFontState *)lbl_801A66CC)->unk_1a4;
    ((fn_1_54848_VolatileFontState *)lbl_801A66CC)->unk_1ac =
        ((fn_1_54848_VolatileFontState *)lbl_801A66CC)->unk_1a8;
}
/* fzgx:end fn_1_54848 */

/* fzgx:begin fn_1_54868 */
typedef struct fn_1_54868_FontState {
    u8 pad_1a0[0x1a0];
    u32 unk_1a0;
    u32 unk_1a4;
    u32 unk_1a8;
    u32 unk_1ac;
} fn_1_54868_FontState;



// Copies the current font state's two counter values into its active fields.
void fn_1_54868(u32 arg0, u32 arg1) {
    // Volatile access preserves the first retail global-pointer load.
    ((fn_1_54868_FontState *)lbl_801A66CC)->unk_1a4 = arg0;
    // Volatile access preserves the second retail global-pointer load.
    ((fn_1_54868_FontState *)lbl_801A66CC)->unk_1a8 = arg1;
    // Volatile access preserves the third retail global-pointer load.
    ((fn_1_54868_FontState *)lbl_801A66CC)->unk_1a0 = ((fn_1_54868_FontState *)lbl_801A66CC)->unk_1a4;
    // Volatile access preserves the fourth retail global-pointer load.
    ((fn_1_54868_FontState *)lbl_801A66CC)->unk_1ac = ((fn_1_54868_FontState *)lbl_801A66CC)->unk_1a8;
}
/* fzgx:end fn_1_54868 */

/* fzgx:begin fn_1_5489C */
void fn_1_5489C(void **arg0, void **arg1) {
    void *value = *arg0;
    *arg1 = value;
    *arg0 = (void *)arg1;
}
/* fzgx:end fn_1_5489C */

/* fzgx:begin fn_1_548AC */
typedef struct FontCounterState {
    u8 pad_1a0[0x1a0];
    u32 unk_1a0;
    u8 pad_1a4[8];
    u32 unk_1ac;
} FontCounterState;

/* The shared declaration is opaque; this union gives it the recovered layout. */
typedef union FontCounterStateView {
    u8 *raw;
    FontCounterState *typed;
} FontCounterStateView;

// Advances the font counter when enough capacity remains and returns its prior value.
void * fn_1_548AC(u32 amount) {
    FontCounterStateView view;
    FontCounterState *state;
    u32 previous;

    view.raw = lbl_801A66CC;
    state = view.typed;
    if (state->unk_1ac < amount) {
        return (0);
    }

    previous = state->unk_1a0;
    state->unk_1a0 = previous + amount;
    view.raw = lbl_801A66CC;
    state = view.typed;
    state->unk_1ac -= amount;
    return (void *)(previous);
}
/* fzgx:end fn_1_548AC */

/* fzgx:begin fn_1_548EC */
typedef struct fn_1_548EC_FontState {
    u8 pad30[0x30];
    u8 *field_30;
} fn_1_548EC_FontState;



s32 fn_1_548EC(void *arg0) {
    u8 *base;
    fn_1_548EC_FontState *fs;
    s32 offset;
    s32 i;

    i = 0;
    offset = 0;
    fs = (*(fn_1_548EC_FontState * *)&lbl_801A66CC);
    while (i < 0x1000) {
        base = fs->field_30;
        if (arg0 == base + offset) {
            return i;
        }
        offset += 8;
        i++;
    }
    return -1;
}
/* fzgx:end fn_1_548EC */

/* fzgx:begin fn_1_549F4 noprologue */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Angles;

typedef struct {
    f32 s;
    f32 c;
} Vec2;

typedef struct {
    u8 pad_0[0x50];
    Vec3 v50;
    Vec3 aim[4];
    Vec3 dir[4];
    Angles rot;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
} State;

typedef struct {
    f32 zero;
    f32 deg;
    f32 half;
    f32 pad_c;
    f64 one;
    f64 degd;
    f64 halfd;
} K;

extern State *lbl_801A66CC;
extern K lbl_1_rodata_2880;
extern f32 lbl_8006D21C(s32);
extern s16 lbl_8006D2AC(f32);
extern void lbl_8006D7DC(Vec3 *);
extern u32 mathutil_mtxA_rotate_x(s32);
extern u32 mathutil_mtxA_rotate_y(s32);
extern u32 mathutil_mtxA_rotate_z(s32);
extern void lbl_8006D1B8(s16, Vec2 *);
extern void lbl_8006E1C0(Vec3 *, Vec3 *);

void fn_1_549F4(Vec3 *arg0, Angles *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 fzgx_live_;
    f32 h;
    K *p = (K *)&lbl_1_rodata_2880;
    s16 t1, t2;
    Angles *a1 = arg1;
    Vec3 *a0 = arg0;
    s16 t3, t4;
    Vec2 v;

    lbl_801A66CC->v50 = *a0;
    lbl_801A66CC->rot = *a1;
    lbl_801A66CC->f1 = arg2;
    lbl_801A66CC->f2 = arg3;
    lbl_801A66CC->f3 = arg4;
    lbl_801A66CC->f4 = arg5;

    if ((0.0f) == arg5) {
        s32 t = (s16)((182.044449f) * arg2);
        t1 = -t / 2;
        t2 = t / 2;
    } else {
        h = lbl_8006D21C(((182.044449f) * ((0.5f) * arg2)));
        t1 = -lbl_8006D2AC(h * ((1.0) - arg5));
        t2 = lbl_8006D2AC(h * ((1.0) + arg5));
    }

    if ((0.0f) == arg4) {
        s16 x = lbl_8006D2AC(arg3 * lbl_8006D21C(((182.04444885253906) * ((0.5) * arg2))));
        s32 t = (s16)(x * 2);
        t3 = t / 2;
        t4 = -t / 2;
    } else {
        f32 s;
        if ((0.0f) == arg5) {
            s = arg3 * lbl_8006D21C(((182.044449f) * ((0.5f) * arg2)));
        } else {
            s = h * arg3;
        }
        t3 = lbl_8006D2AC(s * ((1.0) + arg4));
        t4 = -lbl_8006D2AC(s * ((1.0) - arg4));
    }

    lbl_8006D7DC(a0);
    mathutil_mtxA_rotate_y(a1->y);
    mathutil_mtxA_rotate_x(a1->x);
    mathutil_mtxA_rotate_z(a1->z);

    lbl_8006D1B8((t3 - 0x4000), &v);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[0].x = -fzgx_live_;
    lbl_801A66CC->dir[0].y = (0.0f);
    lbl_801A66CC->dir[0].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[0], &lbl_801A66CC->aim[0]);

    lbl_8006D1B8((t4 + 0x4000), &v);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[1].x = -fzgx_live_;
    lbl_801A66CC->dir[1].y = (0.0f);
    lbl_801A66CC->dir[1].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[1], &lbl_801A66CC->aim[1]);

    lbl_8006D1B8((t1 + 0x4000), &v);
    lbl_801A66CC->dir[2].x = (0.0f);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[2].y = -fzgx_live_;
    lbl_801A66CC->dir[2].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[2], &lbl_801A66CC->aim[2]);

    lbl_8006D1B8((t2 - 0x4000), &v);
    lbl_801A66CC->dir[3].x = (0.0f);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[3].y = -fzgx_live_;
    lbl_801A66CC->dir[3].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[3], &lbl_801A66CC->aim[3]);
}
/* fzgx:end fn_1_549F4 */

/* fzgx:begin fn_1_54DCC */
void fn_1_54DCC(u8 *data) {
    fn_800794F0(data, lbl_801A66CC + 0x50, 0x84);
}
/* fzgx:end fn_1_54DCC */

/* fzgx:begin fn_1_54E00 */
void fn_1_54E00(void *value) {
    fn_800794F0(lbl_801A66CC + 0x50, value, 0x84);
}
/* fzgx:end fn_1_54E00 */

/* fzgx:begin fn_1_54E34 */
typedef struct {
    u8 pad0[0x8c];
    f32 plane0[3];
    f32 plane1[3];
    f32 plane2[3];
    f32 plane3[3];
} Fn154E34Data;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vector;



s32 fn_1_54E34(void *arg0, f32 arg1) {
    Vector vector;
    Fn154E34Data *data;
    f32 *p;
    f32 x;
    f32 y;
    f32 z;
    f32 m0;
    f32 m1;
    f32 m2;
    s32 i;

    lbl_8006E1B0(arg0, &vector, arg1);
    z = vector.z;
    x = vector.x;
    y = vector.y;
    if (z > arg1) {
        return 0;
    }
    arg1 = -arg1;
    data = (Fn154E34Data *)(*(void * *)&lbl_801A66CC);
    p = data->plane0;
    for (i = 0; i < 4; i++) {
        m0 = x * p[0];
        m1 = y * p[1];
        m2 = z * p[2];
        if (m0 + m1 + m2 < arg1) {
            return 0;
        }
        p += 3;
    }
    return 1;
}
/* fzgx:end fn_1_54E34 */

/* fzgx:begin fn_1_54F5C */
typedef struct {
    u8 pad0[0x8c];
    f32 plane0[3];
    f32 plane1[3];
    f32 plane2[3];
    f32 plane3[3];
    u8 pad_bc[0x18];
    f32 value_d4;
    f32 value_d8;
    f32 value_dc;
} Fn154F5CData;



s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2) {
    Fn154F5CData *data;
    f32 *p;
    f32 d4;
    f32 d8;
    f32 dc;
    f32 m0;
    f32 m1;
    f32 m2;
    s32 i;

    data = (Fn154F5CData *)(*(void * *)&lbl_801A66CC);
    lbl_8006E1B0(arg0, (Vec3 *)(&data->value_d4));
    data = (Fn154F5CData *)(*(void * *)&lbl_801A66CC);
    arg1 = arg1 * arg2;
    dc = data->value_dc;
    if (dc > arg1) {
        return 0;
    }
    d4 = data->value_d4;
    d8 = data->value_d8;
    arg1 = -arg1;
    p = data->plane0;
    for (i = 0; i < 4; i++) {
        m0 = d4 * p[0];
        m1 = d8 * p[1];
        m2 = dc * p[2];
        if (m0 + m1 + m2 < arg1) {
            return 0;
        }
        p += 3;
    }
    return 1;
}
/* fzgx:end fn_1_54F5C */

/* fzgx:begin fn_1_550A8 */
void fn_1_550A8(void) {
    fn_800794F0(lbl_1_bss_6C710, lbl_801A66CC + 0x50, 0x84);
}
/* fzgx:end fn_1_550A8 */

/* fzgx:begin fn_1_550E0 */
void fn_1_550E0(void) {
    fn_800794F0(lbl_801A66CC + 0x50, lbl_1_bss_6C710, 0x84);
}
/* fzgx:end fn_1_550E0 */

/* fzgx:begin fn_1_55118 */
extern u32 lbl_801A6410;
extern const f32 lbl_1_rodata_28A8;
extern void fn_800777D4(void);
extern void fn_1_565F8(void);
extern void fn_80072808(void);
extern void fn_1_56664(void *);
extern void fn_1_566A0(void *);
extern u32 fn_80070DE0(u32);
extern u32 fn_80070DF0(u32);
extern void *memset(void *, int, u32);
extern void fn_1_566EC(int, int);
extern void fn_800749B0(s32, void *);

typedef struct {
    u8 color[4];
    u8 shadow[4];
    f32 scale;
    u8 flags[6];
    u8 pad[0x16];
} InitSettings;
typedef struct {
    u32 initial;
    u32 count;
    f32 scale;
    InitSettings settings;
    u32 last;
} InitState;

static inline void init_settings(InitSettings *settings) {
    memset(settings, 0, 0x28);
    settings->color[0] = 255;
    settings->color[1] = 255;
    settings->color[2] = 255;
    settings->color[3] = 255;
    settings->shadow[0] = 0;
    settings->shadow[1] = 0;
    settings->shadow[2] = 0;
    settings->shadow[3] = 0;
    settings->scale = lbl_1_rodata_28A8;
    settings->flags[0] = 1;
    settings->flags[1] = 3;
    settings->flags[2] = 1;
    settings->flags[3] = 0;
    settings->flags[4] = 0;
    settings->flags[5] = 0;
}

typedef struct lbl_1_bss_6C7CC_t {
    u32 last;
    u8 pad_4[0xc];
} lbl_1_bss_6C7CC_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_6C798;
u32 lbl_1_bss_6C79C;
f32 fzgx_obj_lbl_1_bss_6C7A0;
InitSettings fzgx_obj_lbl_1_bss_6C7A4;
lbl_1_bss_6C7CC_t fzgx_obj_lbl_1_bss_6C7CC;
u8 lbl_1_bss_6C7DC[100];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_6C798;
    s = *(u8 *)&lbl_1_bss_6C79C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6C7A0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6C7A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6C7CC;
    s = *(u8 *)&lbl_1_bss_6C7DC;
}
#pragma section code_type ".text"

void fn_1_55118(void) {
    
    InitSettings *settings;
    lbl_1_bss_6C798 = lbl_801A6410;
    fn_800777D4();
    fn_1_565F8();
    fn_80072808();
    fn_80070DE0((u32)fn_1_56664);
    fn_80070DF0((u32)fn_1_566A0);
    lbl_1_bss_6C79C = 0x60;
    fzgx_obj_lbl_1_bss_6C7A0 = lbl_1_rodata_28A8;
    init_settings(&fzgx_obj_lbl_1_bss_6C7A4);
    fn_1_566EC(0, 0);
    fn_800749B0(0, 0);
    fzgx_obj_lbl_1_bss_6C7CC.last = 0;
}
/* fzgx:end fn_1_55118 */

/* fzgx:begin fn_1_55210 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern const f32 lbl_1_rodata_28A8;
extern void *lbl_801A66CC;

extern void fn_1_556B8(void *value);
extern void fn_1_563E4(Obj_1_bss_6C7A4 *settings);
extern void fn_800780A4(void *value);
extern void *fn_1_5448C(void *value);
extern void *fn_1_548AC(s32 size);
extern void fn_1_55EA0(void);
extern void lbl_8006DB74(void *value);
extern u16 fn_1_7BE94(void);
extern void lbl_8006DD14(void *value, void *data);
extern void fn_1_5489C(void *value, void *data);
extern void fn_1_56530(void);
extern void fn_1_557C4(void *value);

typedef struct {
    u8 pad_0[4];
    void (*callback)(void);
    void *context;
    u8 pad_c[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *entry[4];
} Fn1_55210_Object;

void fn_1_55210(void *value) {
    s32 offset;
    Fn1_55210_Object *obj;
    void *result;
    s32 ok;
    s32 i;

    if (lbl_1_rodata_28A8 == lbl_1_bss_6C7A4.unk_8) {
        if (*(u16 *)((u8 *)value + 0x1c) == 0) {
            fn_1_556B8(value);
            return;
        }
        if ((0) != (*(u16 *)((u8 *)value + 0x1a))) {
            fn_1_563E4(&lbl_1_bss_6C7A4);
            fn_800780A4(value);
        }
        result = fn_1_5448C((u8 *)value + 8);
        obj = fn_1_548AC(0x78);
        if (obj != 0) {
            obj->callback = fn_1_55EA0;
            obj->context = value;
            ok = 1;
            lbl_8006DB74((u8 *)obj + 0xc);
            obj->unk_3C = fn_1_7BE94();
            obj->unk_40 = lbl_1_bss_6C7A4;
            for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
                if ((__rlwnm(lbl_1_bss_6C7CC.unk_0, ((i + 1) & 31), 31, 31) != 0)) {
                    obj->entry[i] = fn_1_548AC(0x30);
                    if (((obj->entry)[i]) != 0) {
                        lbl_8006DD14(((((((((u8 *)lbl_801A66CC))) + offset) + (((0xe0)))))), ((obj->entry)[i]));
                    } else {
                        ok = 0;
                    }
                } else {
                    obj->entry[i] = 0;
                }
            }
            if (ok != 0) {
                fn_1_5489C(result, obj);
            }
        }
        fn_1_56530();
    } else {
        fn_1_557C4(value);
    }
}
/* fzgx:end fn_1_55210 */

/* fzgx:begin fn_1_553C4 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern const f32 lbl_1_rodata_28A8;
extern void *lbl_801A66CC;

extern void fn_1_556B8(void *value);
extern void fn_1_563E4(Obj_1_bss_6C7A4 *settings);
extern void fn_800780A4(void *value);
extern void *fn_1_54448(void *value);
extern void *fn_1_548AC(s32 size);
extern void fn_1_55EA0(void);
extern void lbl_8006DB74(void *value);
extern u16 fn_1_7BE94(void);
extern void lbl_8006DD14(void *value, void *data);
extern void fn_1_5489C(void *value, void *data);
extern void fn_1_56530(void);
extern void fn_1_55924(void *value, void *arg);

typedef struct {
    u8 pad_0[4];
    void (*callback)(void);
    void *context;
    u8 pad_c[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *entry[4];
} Fn1_553C4_Object;

void fn_1_553C4(void *value, void *arg) {
    s32 offset;
    Fn1_553C4_Object *obj;
    void *result;
    s32 ok;
    s32 i;

    if (lbl_1_rodata_28A8 == lbl_1_bss_6C7A4.unk_8) {
        if (*(u16 *)((u8 *)value + 0x1c) == 0) {
            fn_1_556B8(value);
            return;
        }
        if (((0) != (*(u16 *)((u8 *)value + 0x1a)))) {
            fn_1_563E4(&lbl_1_bss_6C7A4);
            fn_800780A4(value);
        }
        result = fn_1_54448(arg);
        obj = fn_1_548AC(0x78);
        if (obj != 0) {
            obj->callback = fn_1_55EA0;
            obj->context = value;
            ok = 1;
            lbl_8006DB74((u8 *)obj + 0xc);
            obj->unk_3C = fn_1_7BE94();
            obj->unk_40 = lbl_1_bss_6C7A4;
            for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
                if ((__rlwnm(lbl_1_bss_6C7CC.unk_0, ((i + 1) & 31), 31, 31) != 0)) {
                    obj->entry[i] = fn_1_548AC(0x30);
                    if (((obj->entry)[i]) != 0) {
                        lbl_8006DD14(((((((((u8 *)lbl_801A66CC))) + offset) + (((0xe0)))))), ((obj->entry)[i]));
                    } else {
                        ok = 0;
                    }
                } else {
                    obj->entry[i] = 0;
                }
            }
            if (ok != 0) {
                fn_1_5489C(result, obj);
            }
        }
        fn_1_56530();
    } else {
        fn_1_55924(value, arg);
    }
}
/* fzgx:end fn_1_553C4 */

/* fzgx:begin fn_1_5557C */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_5557CObject;

void fn_1_5557C(Fn1_5557CObject *value) {
    if (fn_1_54F5C( &value->unk_08, value->unk_14, lbl_1_bss_6C7A0)) {
        fn_1_55210(value);
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_5557C */

/* fzgx:begin fn_1_555D0 */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_555D0Object;

void fn_1_555D0(Fn1_555D0Object *value) {
    if (fn_1_54F5C( &value->unk_08, value->unk_14, lbl_1_bss_6C7A0)) {
        fn_80072558();
        fn_1_55210(value);
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_555D0 */

/* fzgx:begin fn_1_55628 */
typedef struct {
    u8 pad_00[0x1C];
    u16 unk_1C;
} Fn1_55628Object;

void fn_1_55628(Fn1_55628Object *value) {
    if (value->unk_1C != 0 || lbl_1_rodata_28A8 != lbl_1_bss_6C7A4.unk_8) {
        fn_1_557C4(value);
    } else {
        fn_1_556B8(value);
    }
}
/* fzgx:end fn_1_55628 */

/* fzgx:begin fn_1_55678 */
void fn_1_55678(void *value) {
    fn_1_563E4( (fn_1_563E4_FontState *)(&lbl_1_bss_6C7A4));
    fn_80077E7C(value);
    fn_1_56530();
}
/* fzgx:end fn_1_55678 */

/* fzgx:begin fn_1_556B8 */
/* Completes the font operation for the supplied value. */
void fn_1_556B8(void *value) {
    fn_1_563E4( (fn_1_563E4_FontState *)(&lbl_1_bss_6C7A4));
    fn_80077F8C(value);
    fn_1_56530();
}
/* fzgx:end fn_1_556B8 */

/* fzgx:begin fn_1_556F8 */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_556F8Object;

/* Finishes the current font operation after testing its scale threshold. */
void fn_1_556F8(Fn1_556F8Object *value) {
    if (fn_1_54F5C( &value->unk_08, value->unk_14, lbl_1_bss_6C7A0)) {
        fn_1_563E4( (fn_1_563E4_FontState *)(&lbl_1_bss_6C7A4));
        fn_80077F8C(value);
        fn_1_56530();
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_556F8 */

/* fzgx:begin fn_1_5575C */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_5575CObject;

void fn_1_5575C(Fn1_5575CObject *value) {
    if (fn_1_54F5C( &value->unk_08, value->unk_14, lbl_1_bss_6C7A0)) {
        fn_80072558();
        fn_1_563E4( (fn_1_563E4_FontState *)(&lbl_1_bss_6C7A4));
        fn_80077F8C(value);
        fn_1_56530();
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_5575C */

/* fzgx:begin fn_1_557C4 */
typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wC;
    u32 w10;
    u32 w14;
    u32 w18;
    u32 w1C;
    u32 w20;
    u32 w24;
} Words28;

typedef struct {
    u8 pad_00[4];
    u32 unk_04;
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *unk_68[4];
} Fn1_557C4Object;

void fn_1_557C4(void *value) {
    s32 offset;
    Fn1_557C4Object *object;
    void *resource;
    s32 valid;
    s32 i;
    Obj_1_bss_6C7CC *bits;

    resource = (void *)fn_1_5448C((u8 *)value + 8);
    object = fn_1_548AC(0x78);
    if (object != 0) {
        valid = 1;
        object->unk_04 = (u32)fn_1_55C48;
        object->unk_08 = value;
        lbl_8006DB74(((0xC) + ((u8 *)object)));
        object->unk_3C = fn_1_7BE94();
        object->unk_40 = lbl_1_bss_6C7A4;
        bits = &lbl_1_bss_6C7CC;
        for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
            if ((__rlwnm(bits->unk_0, ((i + 1) & 0x1f), 31, 31) != 0)) {
                object->unk_68[i] = fn_1_548AC(0x30);
                if ((*((object->unk_68) + i)) != 0) {
                    lbl_8006DD14(lbl_801A66CC + offset + 0xE0, (*((object->unk_68) + i)));
                } else {
                    valid = 0;
                }
            } else {
                object->unk_68[i] = 0;
            }
        }
        if (valid != 0) {
            fn_1_5489C( (void **)(resource), (void **)(object));
        }
    }
    fn_1_56530();
}
/* fzgx:end fn_1_557C4 */

/* fzgx:begin fn_1_55924 */
typedef struct {
    u8 pad_00[0x4];
    void *vtable;
    void *owner;
    u8 pad_0C[0x30];
    u16 unk_3C;
    u8 pad_3E[0x2];
    Obj_1_bss_6C7A4 settings;
    void *items[4];
} Fn1_55924Object;

void fn_1_55924(void *value, void *arg) {
    Fn1_55924Object *object;
    void *handle;
    s32 ok;
    s32 i;
    Obj_1_bss_6C7CC *flags;

    handle = fn_1_54448( (s32)(arg));
    object = (Fn1_55924Object *)fn_1_548AC(0x78);
    if (object != 0) {
        object->vtable = fn_1_55C48;
        object->owner = value;
        ok = 1;
        lbl_8006DB74((u8 *)object + 0xC);
        object->unk_3C = fn_1_7BE94();
        object->settings = lbl_1_bss_6C7A4;
        flags = &lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (__rlwnm(flags->unk_0, (i + 1) & 31, 31, 31)) {
                object->items[i] = fn_1_548AC(0x30);
                if (object->items[i] != 0) {
                    lbl_8006DD14((((i * 0x30) + lbl_801A66CC) + (0xE0)), object->items[i]);
                } else {
                    ok = 0;
                }
            } else {
                object->items[i] = 0;
            }
        }
        if (ok != 0) {
            fn_1_5489C( (void **)(handle), (void **)(object));
        }
    }
    fn_1_56530();
}
/* fzgx:end fn_1_55924 */

/* fzgx:begin fn_1_55A84 */
typedef struct {
    u8 pad_00[0x1c];
    u16 unk_1c;
} FontInput;

typedef struct {
    u8 pad_00[0x4];
    void (*destroy)(void);
    void *owner;
    u8 pad_0c[0x30];
    u16 unk_3c;
    u8 pad_3e[0x2];
    Obj_1_bss_6C7A4 settings;
    void *unk_68;
    u8 pad_6c[0xc];
    void *unk_78;
    void *unk_7c;
    void *unk_80;
} FontObject;

typedef void (*FontCallback)(void *, void *, void *);

void fn_1_55A84(FontCallback callback, FontInput *value, void *arg2, void *arg3) {
    u16 fzgx_value;
    FontObject *cursor;
    int offset;
    FontObject *object;
    void *data;
    int ok;
    int i;
    u32 shift;
    u32 *flags;

    if (value->unk_1c != 0 || lbl_1_rodata_28A8 != lbl_1_bss_6C7A4.unk_8) {
        data = (void *)fn_1_5448C((u8 *)value + 8);
        object = (FontObject *)fn_1_548AC(0x84);
        if (object != 0) {
            ok = 1;
            object->destroy = fn_1_55D6C;
            object->owner = value;
            lbl_8006DB74((u8 *)object + 0xc);
            fzgx_value = fn_1_7BE94();
            object->unk_3c = fzgx_value;
            object->settings = lbl_1_bss_6C7A4;
            i = 0;
            offset = 0;
            cursor = object;
            flags = (u32 *)&lbl_1_bss_6C7CC;
            while (i < 4) {
                shift = (i + 1) & 31;
                if ((__rlwnm(*flags, shift, 31, 31) != 0)) {
                    cursor->unk_68 = fn_1_548AC(0x30);
                    if (cursor->unk_68 != 0) {
                        lbl_8006DD14(lbl_801A66CC + offset + 0xe0, cursor->unk_68);
                    } else {
                        ok = 0;
                    }
                } else {
                    cursor->unk_68 = 0;
                }
                i++;
                cursor = (FontObject *)((u8 *)cursor + 4);
                offset += 0x30;
            }
            object->unk_78 = arg2;
            object->unk_7c = arg3;
            object->unk_80 = callback;
            if (ok != 0) {
                fn_1_5489C( (void **)(data), (void **)(object));
            }
        }
        fn_1_56530();
    } else {
        fn_1_563E4( (fn_1_563E4_FontState *)(&lbl_1_bss_6C7A4));
        callback(value, arg2, arg3);
        fn_1_56530();
    }
}
/* fzgx:end fn_1_55A84 */

/* fzgx:begin fn_1_55C48 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern void lbl_8006DBAC(void *value);
extern void fn_80072558(void);
extern void fn_800749B0(s32 index, void *value);
extern void fn_80077F8C(void *value);
extern u8 lbl_801A66CC[];

typedef struct {
    u8 unk_00[8];
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 unk_3E[2];
    u8 unk_40[0x28];
    void *unk_68;
} Fn1_55C48Object;


void fn_1_55C48(Fn1_55C48Object *value) {
    Fn1_55C48Object * entry;
    s32 lab_t0__2;
    s32 lab_t0_;
    u32 lab_t0;
    s32 offset;
    Fn1_55C48Object * entry_2;
    lbl_8006DBAC((u8 *)value + 0xc);
    fn_80072558();
    fn_1_56470((u8 *)value + 0x40);
    fn_1_7BEAC(value->unk_3C);

    {

        s32 i;
        Obj_1_bss_6C7CC *state;

        entry = value;
        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (((0) != entry->unk_68)) {
                lab_t0 = i;
                lab_t0_ = lab_t0;
                fn_800749B0(lab_t0_, entry->unk_68);
            } else if ((__rlwnm(state->unk_0, ((u32)(i + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = i;
                fn_800749B0(lab_t0__2, 0);
            }
            entry = (Fn1_55C48Object *)((u8 *)entry + 4);
        }
    }

    fn_80077F8C(value->unk_08);
    fn_1_56554();

    {
        u32 *table;
        Obj_1_bss_6C7CC *state;

        s32 j;

        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        table = (u32 *)&lbl_801A66CC;
        entry_2 = value;
        for (j = 0, offset = 0; j < 4; j++, offset += 0x30, entry_2 = (Fn1_55C48Object *)((u8 *)entry_2 + 4)) {
            if ((__rlwnm(state->unk_0, ((u32)(j + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, (((0xe0) + ((u8 *)*table)) + offset));
            } else if ((entry_2->unk_68) != 0) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, 0);
            }
        }
    }
}
/* fzgx:end fn_1_55C48 */

/* fzgx:begin fn_1_55D6C noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern void lbl_8006DBAC(void *value);
extern void fn_80072558(void);
extern void fn_800749B0(s32 index, void *value);
extern u8 lbl_801A66CC[];

typedef struct {
    u8 unk_00[8];
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 unk_3E[2];
    u8 unk_40[0x28];
    void *unk_68;
    u8 unk_70[0xC];
    u32 unk_78;
    u32 unk_7C;
    void (*unk_80)(void *, u32, u32);
} Fn1_55D6CObject;


void fn_1_55D6C(Fn1_55D6CObject *value) {
    Fn1_55D6CObject * entry;
    s32 lab_t0__2;
    s32 lab_t0_;
    u32 lab_t0;
    s32 offset;
    Fn1_55D6CObject * entry_2;
    lbl_8006DBAC((u8 *)value + 0xc);
    fn_80072558();
    fn_1_56470((u8 *)value + 0x40);
    fn_1_7BEAC(value->unk_3C);

    {

        s32 i;
        Obj_1_bss_6C7CC *state;

        entry = value;
        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (((0) != entry->unk_68)) {
                lab_t0 = i;
                lab_t0_ = lab_t0;
                fn_800749B0(lab_t0_, entry->unk_68);
            } else if ((__rlwnm(state->unk_0, ((u32)(i + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = i;
                fn_800749B0(lab_t0__2, 0);
            }
            entry = (Fn1_55D6CObject *)((u8 *)entry + 4);
        }
    }

    value->unk_80(value->unk_08, value->unk_78, value->unk_7C);
    fn_1_56554();

    {
        u32 *table;
        Obj_1_bss_6C7CC *state;

        s32 j;

        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        table = (u32 *)&lbl_801A66CC;
        entry_2 = value;
        for (j = 0, offset = 0; j < 4; j++, offset += 0x30, entry_2 = (Fn1_55D6CObject *)((u8 *)entry_2 + 4)) {
            if ((__rlwnm(state->unk_0, ((u32)(j + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, (((0xe0) + ((u8 *)*table)) + offset));
            } else if ((entry_2->unk_68) != 0) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, 0);
            }
        }
    }
}
/* fzgx:end fn_1_55D6C */

/* fzgx:begin fn_1_55EA0 */
extern void lbl_8006DBAC(void *value);
extern void fn_800781B8(void *value);

typedef struct {
    u8 unk_00[8];
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 unk_3E[2];
    u8 unk_40[0x28];
    void *unk_68;
} Fn1_55EA0Object;


void fn_1_55EA0(Fn1_55EA0Object *value) {
    Fn1_55EA0Object * entry;
    s32 lab_t0__2;
    s32 lab_t0_;
    u32 lab_t0;
    s32 offset;
    Fn1_55EA0Object * entry_2;
    lbl_8006DBAC((u8 *)value + 0xc);
    fn_80072558();
    fn_1_56470((u8 *)value + 0x40);
    fn_1_7BEAC(value->unk_3C);

    {

        s32 i;
        Obj_1_bss_6C7CC *state;

        entry = value;
        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (((0) != entry->unk_68)) {
                lab_t0 = i;
                lab_t0_ = lab_t0;
                fn_800749B0(lab_t0_, entry->unk_68);
            } else if ((__rlwnm(state->unk_0, ((u32)(i + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = i;
                fn_800749B0(lab_t0__2, 0);
            }
            entry = (Fn1_55EA0Object *)((u8 *)entry + 4);
        }
    }

    fn_800781B8(value->unk_08);
    fn_1_56554();

    {
        u32 *table;
        Obj_1_bss_6C7CC *state;

        s32 j;

        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        table = (u32 *)&lbl_801A66CC;
        entry_2 = value;
        for (j = 0, offset = 0; j < 4; j++, offset += 0x30, entry_2 = (Fn1_55EA0Object *)((u8 *)entry_2 + 4)) {
            if ((__rlwnm(state->unk_0, ((u32)(j + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, (((0xe0) + ((u8 *)*table)) + offset));
            } else if ((entry_2->unk_68) != 0) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, 0);
            }
        }
    }
}
/* fzgx:end fn_1_55EA0 */

/* fzgx:begin fn_1_55FC4 */
void fn_1_55FC4(f32 value) {
    lbl_1_bss_6C7A0 = value;
}
/* fzgx:end fn_1_55FC4 */

/* fzgx:begin fn_1_55FD0 */
void fn_1_55FD0(void) {
    fn_80074CF4();
}
/* fzgx:end fn_1_55FD0 */

/* fzgx:begin fn_1_55FF0 */
void fn_1_55FF0(f32 value) {
    lbl_1_bss_6C7A4.unk_8 = value;
}
/* fzgx:end fn_1_55FF0 */

/* fzgx:begin fn_1_56000 */
void fn_1_56000(u8 value0, u8 value1, u8 value2) {
    lbl_1_bss_6C7A4.unk_C = value0;
    lbl_1_bss_6C7A4.unk_D = value1;
    lbl_1_bss_6C7A4.unk_E = value2;
}
/* fzgx:end fn_1_56000 */

/* fzgx:begin fn_1_56018 */
u32 fn_1_56018(s32 value) {
    s32 i;
    u32 result;

    result = ((-lbl_1_bss_6C7CC.unk_0 | lbl_1_bss_6C7CC.unk_0) >> 31);
    if (value == 0) {
        for (i = 0; i < 4; i++) {
            if (__rlwnm(lbl_1_bss_6C7CC.unk_0, (i + 1) & 31, 31, 31)) {
                fn_800749B0(0, (void *)0);
            }
        }
        lbl_1_bss_6C7CC.unk_0 = 0;
    } else {
        for (i = 0; i < 4; i++) {
            if (__rlwnm(lbl_1_bss_6C7CC.unk_0, (i + 1) & 31, 31, 31)) {
                fn_800749B0(i, ((u8 *)*(void **)&(*(void * *)&lbl_801A66CC) + i * 0x30 + 0xe0));
            }
        }
    }
    return result;
}
/* fzgx:end fn_1_56018 */

/* fzgx:begin fn_1_560F0 */
// Marks the selected font resource as active before handing it to the loader.
void fn_1_560F0(s32 index, void *arg) {
    if (arg != NULL) {
        lbl_1_bss_6C7CC.unk_0 |= (1u << 31) >> index;
        lbl_8006DD14(arg, lbl_801A66CC + index * 0x30 + 0xe0);
    }
    fn_800749B0(index, arg);
}
/* fzgx:end fn_1_560F0 */

/* fzgx:begin fn_1_5616C */
/* 0x30-byte slot in the table lbl_801A66CC points at */
typedef struct {
    f32 unk_0[12];
} FontSlot;

void fn_1_5616C(s32 value, f32 value1, f32 value2) {
    lbl_1_bss_6C7CC.unk_0 |= ((u32)1 << 31) >> value;

    lbl_8006D784(&(*(FontSlot * *)&lbl_801A66CC)[value].unk_0[0x38]);

    (*(FontSlot * *)&lbl_801A66CC)[value].unk_0[0x3b] = value1;
    (*(FontSlot * *)&lbl_801A66CC)[value].unk_0[0x3f] = value2;

    fn_800749B0(value, &(*(FontSlot * *)&lbl_801A66CC)[value].unk_0[0x38]);
}
/* fzgx:end fn_1_5616C */

/* fzgx:begin fn_1_5621C */
void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3) {
    ((u8 *)&lbl_1_bss_6C7A4)[0] = (lbl_1_rodata_28AC * value0);
    ((u8 *)&lbl_1_bss_6C7A4)[1] = (lbl_1_rodata_28AC * value1);
    ((u8 *)&lbl_1_bss_6C7A4)[2] = (lbl_1_rodata_28AC * value2);
    ((u8 *)&lbl_1_bss_6C7A4)[3] = (lbl_1_rodata_28AC * value3);
    fn_80074B40((u8 *)&lbl_1_bss_6C7A4);
}
/* fzgx:end fn_1_5621C */

/* fzgx:begin fn_1_56298 */
void fn_1_56298(f32 value0, f32 value1, f32 value2, f32 value3) {
    f32 scale = lbl_1_rodata_28AC;

    lbl_1_bss_6C7A4.unk_4 = (scale * value0);
    lbl_1_bss_6C7A4.unk_5 = (scale * value1);
    lbl_1_bss_6C7A4.unk_6 = (scale * value2);
    lbl_1_bss_6C7A4.unk_7 = (scale * value3);
    fn_80074C74(&lbl_1_bss_6C7A4.unk_4);
}
/* fzgx:end fn_1_56298 */

/* fzgx:begin fn_1_5631C */
void fn_1_5631C(const u32 *value) {
    Obj_1_bss_6C7A4 *state = &lbl_1_bss_6C7A4;

    // Store the incoming value in the shared font state before notifying the subsystem.
    *(volatile u32 *)&state->unk_4 = *value;
    fn_80074C74((u8 *)value);
}
/* fzgx:end fn_1_5631C */

/* fzgx:begin fn_1_5634C */
void fn_1_5634C(u8 value) {
    lbl_1_bss_6C7A4.unk_12 = value;
}
/* fzgx:end fn_1_5634C */

/* fzgx:begin fn_1_5635C */
void fn_1_5635C(u8 value, f32 value2, f32 value3) {
    lbl_1_bss_6C7A4.unk_13 = value;
    *(f32 *)&lbl_1_bss_6C7A4.unk_18 = value2;
    *(f32 *)&lbl_1_bss_6C7A4.unk_1C = value3;
}
/* fzgx:end fn_1_5635C */

/* fzgx:begin fn_1_56374 */
void fn_1_56374(u8 value1, u8 value2, u8 value3) {
    lbl_1_bss_6C7A4.unk_14 = value1;
    lbl_1_bss_6C7A4.unk_15 = value2;
    lbl_1_bss_6C7A4.unk_16 = value3;
}
/* fzgx:end fn_1_56374 */

/* fzgx:begin fn_1_5638C */
// Stores the current value for the font subsystem and refreshes its state.
void fn_1_5638C(u32 value) {
    lbl_1_bss_6C7A4.unk_20 = value;
    fn_80074A7C();
}
/* fzgx:end fn_1_5638C */

/* fzgx:begin fn_1_563B8 */
void fn_1_563B8(u32 value) {
    lbl_1_bss_6C7A4.unk_24 = value;
    fn_80077BAC();
}
/* fzgx:end fn_1_563B8 */

/* fzgx:begin fn_1_563E4 */
void fn_1_563E4(fn_1_563E4_FontState *font) {
    u32 value;
    u32 lab_t0;
    u32 lab_t2;

    fn_80077B04(font->scale);
    lab_t0 = font->pad_0C[0];
    lab_t2 = font->pad_0C[2];
    fn_80074918(lab_t0, font->pad_0C[1], lab_t2);
    if (font->state == 0) {
        if (font->enabled != 0) {
            fn_80071ED4(font->color, font->x, font->y);
            value = font->value;
            fn_80072014(&value);
            fn_800720B0(1);
        } else {
            fn_800720B0(0);
        }
    }
}
/* fzgx:end fn_1_563E4 */

/* fzgx:begin fn_1_56470 */
typedef struct fn_1_56470_FontState {
    u8 unk_00[4];
    void *unk_04;
    f32 unk_08;
    s8 unk_0C;
    u8 unk_0D;
    s8 unk_0E;
    u8 unk_0F;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u32 unk_20;
    u32 unk_24;
} fn_1_56470_FontState;


void fn_1_56470(fn_1_56470_FontState *state) {
    u32 value;

    fn_80077B04( state->unk_08);
    fn_80074B40( (u8 *)(fn_1_56470_FontState *)(state));
    fn_80074C74( (u8 *)(&state->unk_04));
    fn_80074918(state->unk_0C, state->unk_0D, state->unk_0E);
    fn_80077BBC(state->unk_0F);
    fn_80037D40(state->unk_10, state->unk_11);
    fn_80074A7C(state->unk_20);
    fn_80077BAC(state->unk_24);
    if (state->unk_24 == 0) {
        if (state->unk_12 != 0) {
            fn_80071ED4(state->unk_13, state->unk_18, state->unk_1C);
            value = state->unk_14;
            fn_80072014( &value);
            fn_800720B0(1);
        } else {
            fn_800720B0(0);
        }
    }
}
/* fzgx:end fn_1_56470 */

/* fzgx:begin fn_1_56530 */
void fn_1_56530(void) {
    lbl_1_bss_6C7A0 = lbl_1_rodata_28A8;
    lbl_1_bss_6C7A4.unk_8 = lbl_1_rodata_28A8;
}
/* fzgx:end fn_1_56530 */

/* fzgx:begin fn_1_56554 */
void fn_1_56554(void) {
    u32 lab_t0;
    u32 lab_t2;
    Obj_1_bss_6C7A4 *font = &lbl_1_bss_6C7A4;

    fn_80074B40( (u8 *)(font));
    fn_80074C74( &font->unk_4);
    lab_t0 = font->unk_C;
    lab_t2 = font->unk_E;
    fn_80074918(lab_t0, font->unk_D, lab_t2);
    fn_80077BBC(font->unk_F);
    fn_80037D40(font->unk_10, font->unk_11);
    fn_80074A7C(font->unk_20);
    fn_80077BAC(font->unk_24);
}
/* fzgx:end fn_1_56554 */

/* fzgx:begin fn_1_565E8 */
// Return the font data buffer used by the font subsystem.
u8 *fn_1_565E8(void) {
    return lbl_1_bss_6C7DC;
}
/* fzgx:end fn_1_565E8 */

/* fzgx:begin fn_1_565F4 */
// fn_1_565F4: empty in retail (single blr).
void fn_1_565F4(void) {
}
/* fzgx:end fn_1_565F4 */

/* fzgx:begin fn_1_565F8 */
// Registers the font initialization callbacks with the shared dispatcher.
void fn_1_565F8(void) {
    void (*callbacks[6])(void);

    callbacks[0] = (void (*)(void))fn_1_565E8;
    callbacks[1] = fn_1_45730;
    callbacks[2] = fn_1_45B2C;
    callbacks[3] = fn_1_458A0;
    callbacks[4] = fn_1_45850;
    callbacks[5] = fn_1_565F4;
    fn_80070D60(callbacks);
}
/* fzgx:end fn_1_565F8 */
