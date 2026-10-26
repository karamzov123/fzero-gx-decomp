/* Non-matching: best partial attempt (87.58% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/screen_effect.h"

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    f64 x, y, z, w;
} Vec4;

typedef struct {
    u8 pad_0[8];
    Vec3 pos;
    f32 w;
} Node;

typedef struct {
    Node *node;
    u32 id;
} Entry;

typedef struct {
    s32 count;
    u32 pad_4;
    Entry *entries;
} List;

typedef struct {
    u8 pad_0[0x170];
    u32 handle;
    List *list;
    u8 pad_178[4];
    Vec4 out;
    f32 f1, f2, f3;
} EffectState;

typedef struct {
    u8 pad_0[0x7c8];
    char unk_7c8[0x18];
    char unk_7e0[0x4c];
    char unk_82c[0x14];
    char unk_840[0x20];
} EffectData;

typedef struct {
    u8 pad_0[8];
    s16 cached;
} EffectCache;

extern void fn_1_7B4C0(void);
extern s8 fn_1_D38C4(char *text);
extern List *fn_1_D35D4(char *text);
extern void sprintf(char *dst, const char *format, const char *text, ...);
extern u32 fn_80083970(s32 id, const char *name);

static const Vec3 zero_vec = {0.0, 0.0, 0.0};

#pragma opt_dead_assignments off
static inline Entry * fn_1_7B2E8_read_pointer(EffectState * owner) { return owner->list->entries; }
#pragma opt_strength_reduction off
static inline f32 fn_1_7B2E8_read_pointer_(Node * owner) { return owner->w; }
#pragma opt_lifetimes off
u16 fn_1_7B2E8(u32 index) {
    f64 fzgx_value;
    EffectData *data = (EffectData *)&lbl_1_data_1DCF0;
    EffectCache *cache = (EffectCache *)((u8 *)data + 0x2b4);
    struct { s32 value; } count;
    Vec3 acc;
    char text_82c[0x20];
    char text_840[0x20];
    struct { s32 value; } i;
    EffectState *state = (EffectState *)&lbl_1_bss_6D600;
    f32 max;
    f32 lab_t1;
    s32 tmp_call4;

    if (cache->cached != index) {
        fn_1_7B4C0();
        sprintf(text_82c, data->unk_82c, data->unk_7e0, index);
        sprintf(text_840, data->unk_840, data->unk_7e0, index);
        tmp_call4 = fn_1_D38C4(text_82c);
        state->handle = tmp_call4;
        state->list = fn_1_D35D4(text_840);
    }

    if (state->handle != 0 && state->list != 0) {
        acc = zero_vec;
        count.value = 0;
        for (i.value = 0; i.value < state->list->count; i.value++) {
            Node *node = ((i.value)[fn_1_7B2E8_read_pointer(state)]).node;

            if (fn_80083970(((i.value)[fn_1_7B2E8_read_pointer(state)]).id, data->unk_7c8) == 0) {
                max = (fn_1_7B2E8_read_pointer_(node) > max) ? fn_1_7B2E8_read_pointer_(node) : max;
                psvec_add(&acc, &node->pos, &acc);
                count.value++;
            }
        }
        lab_t1 = 1.0f / (f32)count.value;
        psvec_scale(&acc, lab_t1, &state->out);
        state->out.w = max;
        state->f1 = max;
        fzgx_value = 0.0f;
        state->f2 = fzgx_value;
        state->f3 = max;
    }

    cache->cached = index;
    return (u32)cache;
}
#pragma opt_lifetimes reset

#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset

