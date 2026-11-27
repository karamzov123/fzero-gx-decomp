/* Retained Japan/PAL compiler inputs pending a verified whole-TU regional build. */
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
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_5489C(void **arg0, void **arg1);
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);

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
