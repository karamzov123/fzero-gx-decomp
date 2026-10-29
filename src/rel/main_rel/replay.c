#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/replay.h"

extern u32 OSGetTick(void);

/* fzgx:begin fn_1_F2780 noprologue */
#include "types.h"

typedef struct State {
    u8 pad0[0x19];
    u8 byte19;
    u8 byte1a;
    u8 byte1b;
    u8 byte1c;
    u8 byte1d;
    u8 byte1e;
    u8 byte1f;
    u8 byte20;
    u8 byte21;
    u8 byte22;
    u8 byte23;
    u8 pad24[0x1c];
    void *object;
} State;

typedef struct Global {
    u8 pad0[4];
    u8 byte4;
    u8 pad5[3];
    State state;
} Global;

typedef struct Object {
    u8 pad0[0xa0];
    u16 halfa0;
} Object;

extern u32 lbl_801A6410;
extern char lbl_1_data_3E8C8[9];
extern Object *fn_1_4630(u32 arg0, u32 arg1, char *arg2, u32 arg3);

typedef struct lbl_1_bss_7F01C_t {
    u8 fzgx_byte_4C;
    u8 pad_1[0x1];
} lbl_1_bss_7F01C_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u16 fzgx_obj_lbl_1_bss_7EFD0;
u16 fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD2;
u8 fzgx_obj_lbl_1_bss_7EFD4;
u8 fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5;
u16 fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5_fill_7EFD6;
State fzgx_obj_lbl_1_bss_7EFD8;
lbl_1_bss_7F01C_t fzgx_obj_lbl_1_bss_7F01C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7EFD0;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7EFD4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5_fill_7EFD6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7EFD8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7F01C;
}
#pragma section code_type ".text"

void fn_1_F2780(void) {
    Object *object;
    State *state;

    
    state = &fzgx_obj_lbl_1_bss_7EFD8;
    object = fn_1_4630(lbl_801A6410, (1 << 16) + 0x14c, lbl_1_data_3E8C8, 0x75);
    state->object = object;
    *(u16 *)((u8 *)&fzgx_obj_lbl_1_bss_7F01C.fzgx_byte_4C) = 0;
    object->halfa0 = 0;
    fzgx_obj_lbl_1_bss_7EFD4 = 0x29;
    state->byte19 = 0;
    state->byte1a = 1;
    state->byte1c = 0;
    state->byte20 = 0;
    state->byte1d = 0;
    state->byte21 = 0;
    state->byte1e = 0;
    state->byte22 = 0;
    state->byte1f = 0;
    state->byte23 = 0;
    *(u32 *)((u8 *)state + 0xc) = 0;
    state->byte1b = 0;
}
/* fzgx:end fn_1_F2780 */

/* fzgx:begin fn_1_F2820 */
extern u32 OSGetTick(void);

/* One recorded input run: a pad sample plus how many frames it repeats. */
typedef struct ReplayEntry {
    u8 buttons;
    s8 stickX;
    s8 stickY;
    s8 substickX;
    u8 triggerL;
    u8 triggerR;
    u8 count;
} ReplayEntry;

typedef struct ReplayInput {
    u8 buttons;
    s8 stickX;
    s8 stickY;
    s8 substickX;
    u8 triggerL;
    u8 triggerR;
} ReplayInput;

typedef struct ReplayBuffer {
    u8 pad_0[0xA0];
    u16 index;
    u16 end;
    ReplayEntry entries[1];
} ReplayBuffer;

typedef struct ReplayControl {
    u8 pad_0[0x8];
    u32 missed;
    u8 pad_C[0x4];
    u32 capacity;
    u8 pad_14[0x5];
    u8 playing;
    u8 recordAll;
    u8 pad_1B;
    u8 repeat[4];
    u8 pad_20[0x8];
    s32 active[4];
    u8 pad_38[0x8];
    ReplayBuffer *buffer;
} ReplayControl;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u16 fzgx_obj_lbl_1_bss_7EFD0;
u16 fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD2;
u8 fzgx_obj_lbl_1_bss_7EFD4;
u8 fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5;
u16 fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5_fill_7EFD6;
ReplayControl fzgx_obj_lbl_1_bss_7EFD8;
u16 fzgx_obj_lbl_1_bss_7F01C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7EFD0;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7EFD4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5_fill_7EFD6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7EFD8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7F01C;
}
#pragma section code_type ".text"

extern u32 fn_1_864E8(int);
extern u8 fn_1_86624(void);
extern u8 fn_1_86678(int);
extern u8 fn_1_F2D30(ReplayEntry *, ReplayEntry **, u8);
extern void fn_1_F2CD8(ReplayEntry *, ReplayEntry **, u8);

#define g_flags fzgx_obj_lbl_1_bss_7EFD4
#define g_ctrl fzgx_obj_lbl_1_bss_7EFD8
#define g_end fzgx_obj_lbl_1_bss_7F01C

void fn_1_F2820(ReplayInput *inputs, u8 *out, u8 *mask) {
    ReplayEntry *entry;
    s32 n;
    u16 flags;
    u8 i;
    u32 port;
    u8 buttons;
    u8 missed;
    ReplayEntry *base;

    entry = NULL;
    flags = g_flags;
    base = g_ctrl.buffer->entries;

    if (((flags >> 0) & 1) && !((flags >> 3) & 1) && !((flags >> 4) & 1)) {
        if ((flags >> 1) & 1) {
            missed = 0;
            for (i = 0; i < 4; i++) {
                if (i >= (s8)fn_1_86624()) {
                    break;
                }
                port = fn_1_86678(i);
                if (port == 0xFF) {
                    continue;
                }
                fn_1_F2CD8(&base[g_ctrl.buffer->index], &entry, i);
                if (g_ctrl.playing) {
                    if (entry->count == 0) {
                        if (&base[g_ctrl.buffer->index] == entry) {
                            g_ctrl.buffer->index--;
                        }
                        fn_1_F2CD8(entry - 1, &entry, i);
                    } else {
                        entry->count--;
                    }
                } else {
                    missed = 1;
                }
                buttons = (i & 3) | 4 | (inputs[port].buttons & 0xF8);
                if (!g_ctrl.recordAll && entry->buttons == buttons && entry->stickX == inputs[port].stickX &&
                    entry->stickY == inputs[port].stickY && entry->substickX == inputs[port].substickX &&
                    entry->triggerL == inputs[port].triggerL && entry->triggerR == inputs[port].triggerR &&
                    entry->count < 0xFF) {
                    entry->count++;
                } else {
                    fn_1_F2D30(entry, &entry, i);
                    if (entry - base >= g_ctrl.capacity) {
                        g_flags |= 0x10;
                    } else {
                        entry->count = 0;
                        entry->buttons = buttons;
                        entry->stickX = inputs[port].stickX;
                        entry->stickY = inputs[port].stickY;
                        entry->substickX = inputs[port].substickX;
                        entry->triggerL = inputs[port].triggerL;
                        entry->triggerR = inputs[port].triggerR;
                        g_ctrl.buffer->index = entry - base;
                    }
                }
            }
            if (missed) {
                g_ctrl.missed++;
            }
            g_end = g_ctrl.buffer->end = g_ctrl.buffer->index;
        } else if ((flags >> 2) & 1) {
            for (i = 0; i < 4; i++) {
                if (g_ctrl.active[i] == 0 || (fn_1_864E8(i) & 0x04000000)) {
                    continue;
                }
                fn_1_F2CD8(&base[g_ctrl.buffer->index], &entry, i);
                if (g_ctrl.playing) {
                    if (g_ctrl.repeat[i] == 0) {
                        if (&base[g_ctrl.buffer->index] == entry) {
                            g_ctrl.buffer->index--;
                        }
                        fn_1_F2CD8(entry - 1, &entry, i);
                        g_ctrl.repeat[i] = entry->count;
                    } else {
                        g_ctrl.repeat[i]--;
                    }
                }
                inputs[i].buttons = entry->buttons & 0xF8;
                inputs[i].stickX = entry->stickX;
                inputs[i].stickY = entry->stickY;
                inputs[i].substickX = entry->substickX;
                inputs[i].triggerL = entry->triggerL;
                inputs[i].triggerR = entry->triggerR;
                if (g_ctrl.repeat[i] >= entry->count) {
                    fn_1_F2D30(&base[g_ctrl.buffer->index], &entry, i);
                    n = entry - base;
                    if (n <= g_end) {
                        g_ctrl.buffer->index = n;
                        g_ctrl.repeat[i] = 0;
                    }
                } else {
                    g_ctrl.repeat[i]++;
                }
                out[i] = inputs[i].buttons & ~mask[i];
            }
            if (g_ctrl.buffer->index > g_end) {
                g_flags |= 0x10;
            }
        }
    }
}
/* fzgx:end fn_1_F2820 */

/* fzgx:begin fn_1_F2CD8 */
void fn_1_F2CD8(u8 *value, u8 **cursor, u32 index) {
    s32 target;
    Obj_1_bss_7EFD8_At40 *entries_end;
    u8 *entry;

    // Move backward through replay entries until the requested flag or boundary is found.
    target = (index | 4) & 0xff;
    entries_end = lbl_1_bss_7EFD8.unk_40 + 1;
    *cursor = value;

    while (*cursor >= (u8 *)entries_end) {
        entry = *cursor;
        if ((entry[0] & 7) == target) {
            break;
        }
        *cursor -= 7;
    }

    if (*cursor < (u8 *)entries_end) {
        *cursor = value;
    }
}
/* fzgx:end fn_1_F2CD8 */

/* fzgx:begin fn_1_F2D30 */
u8 fn_1_F2D30(u8 *value, u8 **cursor, u32 index) {
    u8 target;
    u32 step;
    Obj_1_bss_7EFD8_At40 *entries_end;
    u8 raw;
    u8 flags;

    target = (index | 4) & 0xff;
    entries_end = lbl_1_bss_7EFD8.unk_40 + 1;

    if (lbl_1_bss_7EFD8.unk_1A != 0) {
        lbl_1_bss_7EFD8.unk_1A = 0;
        step = 0;
    } else {
        step = 1;
    }
    *cursor = value + step * 7;

    while (*cursor < (u8 *)entries_end + lbl_1_bss_7EFD8.unk_14 * 7) {
        raw = (*cursor)[0];
        flags = raw & 7;
        if ((raw & 4) == 0 || flags == target) {
            break;
        }
        *cursor += 7;
    }

    return *cursor != (u8 *)entries_end + lbl_1_bss_7EFD8.unk_14 * 7;
}
/* fzgx:end fn_1_F2D30 */

/* fzgx:begin fn_1_F2DDC */
extern u32 OSGetTick(void);

extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, s32);

typedef struct lbl_1_bss_7EFD8_t {
    u8 pad_0[0x40];
    u32 fzgx_u32_48;
} lbl_1_bss_7EFD8_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u16 fzgx_obj_lbl_1_bss_7EFD0;
u16 fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD2;
u8 fzgx_obj_lbl_1_bss_7EFD4;
u8 fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5;
u16 fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5_fill_7EFD6;
lbl_1_bss_7EFD8_t fzgx_obj_lbl_1_bss_7EFD8;
u16 fzgx_obj_lbl_1_bss_7F01C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7EFD0;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7EFD4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5_fill_7EFD6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7EFD8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7F01C;
}
#pragma section code_type ".text"

void fn_1_F2DDC(void) {
    

    if ((fzgx_obj_lbl_1_bss_7EFD4 & 1) != 0) {
        fn_1_46B4(lbl_801A6410, fzgx_obj_lbl_1_bss_7EFD8.fzgx_u32_48,
                   lbl_1_data_3E8C8, 0x19d);
        fzgx_obj_lbl_1_bss_7EFD8.fzgx_u32_48 = 0;
        fzgx_obj_lbl_1_bss_7F01C = 0;
        fzgx_obj_lbl_1_bss_7EFD4 = 0;
    }
}
/* fzgx:end fn_1_F2DDC */

/* fzgx:begin fn_1_F2E50 */
extern u32 OSGetTick(void);

struct fn_1_F2E50_rec {
    u8 pad_0[0x40];
    u32 unk_40;
};

struct fn_1_F2E50_lbl_1_bss_7EFD0 {
    u8 pad_0[0x4];
    u8 unk_4;
    u8 pad_5[0x47];
    u16 unk_4C;
};

typedef struct lbl_1_bss_7EFD8_t {
    u8 fzgx_byte_8;
    u8 pad_1[0x43];
} lbl_1_bss_7EFD8_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u16 fzgx_obj_lbl_1_bss_7EFD0;
u16 fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD2;
u8 fzgx_obj_lbl_1_bss_7EFD4;
u8 fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5;
u16 fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5_fill_7EFD6;
lbl_1_bss_7EFD8_t fzgx_obj_lbl_1_bss_7EFD8;
u16 fzgx_obj_lbl_1_bss_7F01C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7EFD0;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7EFD4;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_7EFD0_gap_7EFD5_fill_7EFD6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7EFD8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7F01C;
}
#pragma section code_type ".text"

void fn_1_F2E50(u32 arg0) {
#pragma opt_propagation off
    
    struct fn_1_F2E50_rec *rec;
    u32 v0;
    u8 v1;

    if ((fzgx_obj_lbl_1_bss_7EFD4 & 1) == 0) { return; }
    v1 = 1;
    fzgx_obj_lbl_1_bss_7EFD4 = v1;
    if (arg0 == 0) {
        v1 |= 42;
        rec = (struct fn_1_F2E50_rec *)((u8 *)&fzgx_obj_lbl_1_bss_7EFD8.fzgx_byte_8);
        fzgx_obj_lbl_1_bss_7EFD4 = v1;
        v0 = rec->unk_40;
        *(u16 *)((u8 *)v0 + 160) = 0;
        fzgx_obj_lbl_1_bss_7F01C = 0;
        return;
    }
    if (arg0 == 1) {
        v1 |= 44;
        rec = (struct fn_1_F2E50_rec *)((u8 *)&fzgx_obj_lbl_1_bss_7EFD8.fzgx_byte_8);
        fzgx_obj_lbl_1_bss_7EFD4 = v1;
        v0 = rec->unk_40;
        *(u16 *)((u8 *)v0 + 160) = 0;
    }
}
/* fzgx:end fn_1_F2E50 */

/* fzgx:begin fn_1_F2EB8 */
#include "types.h"

struct fn_1_F2EB8_lbl_1_bss_7EFD4 {
    s8 unk_0;
};



void fn_1_F2EB8(void) {
    u8 v0;
    v0 = (*(struct fn_1_F2EB8_lbl_1_bss_7EFD4 *)&lbl_1_bss_7EFD4).unk_0;
    if ((v0 & 0x1) == 0) { return; }
    (*(struct fn_1_F2EB8_lbl_1_bss_7EFD4 *)&lbl_1_bss_7EFD4).unk_0 = (v0 & -41);
}
/* fzgx:end fn_1_F2EB8 */

/* fzgx:begin fn_1_F2EDC */
#include "types.h"

struct fn_1_F2EDC_lbl_1_bss_7EFD4 {
    s8 unk_0;
};



void fn_1_F2EDC(void) {
    u8 v0;
    v0 = (*(struct fn_1_F2EDC_lbl_1_bss_7EFD4 *)&lbl_1_bss_7EFD4).unk_0;
    if ((v0 & 0x1) == 0) { return; }
    (*(struct fn_1_F2EDC_lbl_1_bss_7EFD4 *)&lbl_1_bss_7EFD4).unk_0 = (v0 | 8);
}
/* fzgx:end fn_1_F2EDC */

/* fzgx:begin fn_1_F2EFC */
// Clears the active replay flag and marks the replay entry as ready.
void fn_1_F2EFC(void) {
    u8 flags = lbl_1_bss_7EFD4;

    if ((flags & 1) == 0) {
        return;
    }
    if (((flags >> 5) & 1) != 0) {
        return;
    }

    lbl_1_bss_7EFD4 = flags & ~8;
    lbl_1_bss_7EFD8.unk_19 = 1;
}
/* fzgx:end fn_1_F2EFC */

/* fzgx:begin fn_1_F2F34 */
#include "types.h"



struct fn_1_F2F34_lbl_1_bss_7EFD4 {
    u8 unk_0;
};

u32 fn_1_F2F34(void) {
    u8 v0;
    v0 = (*(struct fn_1_F2F34_lbl_1_bss_7EFD4 *)&lbl_1_bss_7EFD4).unk_0;
    if (((*(struct fn_1_F2F34_lbl_1_bss_7EFD4 *)&lbl_1_bss_7EFD4).unk_0 & 0x1) == 0) {
    v0 = 0;
    return v0;
    }
    v0 = ((v0 >> 2) & 0x1);
    return v0;
}
/* fzgx:end fn_1_F2F34 */

/* fzgx:begin fn_1_F2F58 */
u32 fn_1_F2F58(void) {
    u8 flags = lbl_1_bss_7EFD4;

    if ((flags & 1) == 0) {
        return 0;
    }
    return (u32)__cntlzw((u32)((flags >> 2) & 1)) >> 5;
}
/* fzgx:end fn_1_F2F58 */

/* fzgx:begin fn_1_F2F84 */
extern u32 fn_1_C39FC(void);
extern u32 lbl_801A63C0;
extern u8 fn_1_3F23C(u8);
extern u8 fn_1_3F250(u8);
extern u8 fn_1_3F264(u8);
extern s8 fn_1_86624(void);
extern u32 fn_1_86810(s32);
extern void fn_1_3EF14(u32 *);
extern void fn_80008BEC(u8 *, int, u32);

#pragma opt_dead_assignments off
void fn_1_F2F84(void) {
    Obj_1_bss_7EFD8 *p_lbl_1_bss_7EFD8;
    u8 *v1;
    s32 v3;
    s32 v4;
    s32 v5;
    u8 *v6;
    s32 v16;
    struct { s32 value; } v17;
    u8 *v18;
    s32 bit;
    struct { u8 a[0x14ac]; } loc_8;

    p_lbl_1_bss_7EFD8 = (Obj_1_bss_7EFD8 *)&lbl_1_bss_7EFD8;
    v1 = (u8 *)p_lbl_1_bss_7EFD8->unk_40 + 164;
    fn_1_3EF14((u32 *)&loc_8);
    *(u16 *)((u8 *)p_lbl_1_bss_7EFD8->unk_40 + 0xfef0) = 0;
    v3 = 0;
    while (v3 < fn_1_86624()) {
        u32 result;
        *((u8 *)p_lbl_1_bss_7EFD8->unk_40 + v3 * 5 + 4) = loc_8.a[v3 + 14];
        result = fn_1_86810(v3);
        {
            u32 v10 = (u32)p_lbl_1_bss_7EFD8->unk_40;
            u32 v11 = (v3 + 0x10000) - 270;
            *(u8 *)(v10 + v11) = result;
        }
        *(u16 *)((u8 *)p_lbl_1_bss_7EFD8->unk_40 + v3 * 2 + 0xff10) = 0xffff;
        v3++;
    }
    lbl_1_bss_7EFD8.unk_18 = loc_8.a[8];
    lbl_1_bss_7EFD8.unk_10 = 9300;
    lbl_1_bss_7EFD8.unk_14 = 0xd9f8;
    fn_80008BEC(v1, 0, 0xd9f8);
    lbl_1_bss_7F01C = 0;
    p_lbl_1_bss_7EFD8->unk_40->unk_A0 = 0;
    lbl_1_bss_7EFD8.unk_8 = 0;
    lbl_1_bss_7EFD8.unk_4 = 0;
    lbl_1_bss_7EFD8.unk_19 = 0;
    lbl_1_bss_7EFD8.unk_1A = 1;
    lbl_1_bss_7EFD8.unk_1C = 0;
    lbl_1_bss_7EFD8.unk_20 = 0;
    lbl_1_bss_7EFD8.unk_24 = 0;
    lbl_1_bss_7EFD8.unk_1D = 0;
    lbl_1_bss_7EFD8.unk_21 = 0;
    lbl_1_bss_7EFD8.unk_25 = 0;
    lbl_1_bss_7EFD8.unk_1E = 0;
    lbl_1_bss_7EFD8.unk_22 = 0;
    lbl_1_bss_7EFD8.unk_26 = 0;
    lbl_1_bss_7EFD8.unk_1F = 0;
    lbl_1_bss_7EFD8.unk_23 = 0;
    lbl_1_bss_7EFD8.unk_27 = 0;
    p_lbl_1_bss_7EFD8->unk_40->unk_98 = fn_1_C39FC();
    p_lbl_1_bss_7EFD8->unk_40->unk_9C = lbl_801A63C0;
    v17.value = 0;
    while (v17.value < loc_8.a[9]) {
        v18 = (u8 *)p_lbl_1_bss_7EFD8->unk_40 + v17.value * 5;
        if (v17.value < loc_8.a[8]) v18[0] = 1;
        else v18[0] = 0;
        v18[1] = fn_1_3F23C((u8)v17.value);
        if (v18[0] != 0) {
            v18[2] = fn_1_3F250((u8)v17.value);
            for (bit = 0; bit < 8; bit++) {
                if ((u8)(1 << bit) == v18[2]) {
                    v18[2] = bit;
                    break;
                }
            }
            v18[3] = fn_1_3F264((u8)v17.value);
        } else v18[3] = 50;
        v16 += 5;
        v17.value++;
    }
    lbl_1_bss_7EFD8.unk_1B = 0;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_F2F84 */

/* fzgx:begin fn_1_F326C */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


extern u8 lbl_1_bss_7EFD4;


typedef struct {
u32 x;
u32 y;
u32 z;
} ReplayTriple_F3574;
typedef struct {
u32 start0 : 15;
u32 kind : 3;
u32 index : 5;
u32 value : 5;
u32 pad0 : 4;
u32 start : 15;
u32 count : 5;
u32 result : 5;
u32 stage : 5;
u32 pad1 : 2;
ReplayTriple_F3574 begin[4];
ReplayTriple_F3574 end[4];
ReplayTriple_F3574 begin1;
ReplayTriple_F3574 end1;
} ReplayEvent_F3574;
typedef struct {
u8 pad0[0xFEF0];
u16 eventCount;
u8 pad1[0x1E];
u16 slots[30];
ReplayEvent_F3574 events[1];
} ReplayBuffer_F3574;
typedef struct {
u32 unk_0;
u32 frame;
u8 pad0[0x10];
u8 playerCount;
u8 pad1[0x27];
ReplayBuffer_F3574 *buffer;
} ReplayState_F3574;


extern void fn_1_F3574(ReplayState_F3574 *state, u8 index, u8 value, u8 kind, u8 result);


typedef struct {
f32 x;
f32 y;
f32 z;
} ReplayPos_F326C;
typedef struct {
u16 count;
u8 last[4];
} ReplayTrack_F326C;
typedef struct {
u8 pad0[0x24];
u8 done[4];
} ReplayStateView_F326C;
typedef struct {
u8 b7 : 1;
u8 b6 : 1;
u8 b5 : 1;
u8 b4 : 1;
u8 paused : 1;
u8 stopped : 1;
u8 b1 : 1;
u8 active : 1;
} ReplayFlags_F326C;
extern u8 fn_1_86624(void);
extern u8 fn_1_86810(int);
extern u32 fn_1_864E8(int);
extern u8 fn_1_86678(int);
extern s16 fn_1_3F0C8(void);
extern void fn_1_862D4(int, ReplayPos_F326C *);
extern f32 fn_1_8CAF4(u32, s32);
static inline int replay_is_recording(void) {
if (!(*(ReplayFlags_F326C *)&lbl_1_bss_7EFD4) .active) {
return 0;
}
if ((*(ReplayFlags_F326C *)&lbl_1_bss_7EFD4) .stopped) {
return 0;
}
return 1;
}
static inline int replay_is_paused(void) {
return (*(ReplayFlags_F326C *)&lbl_1_bss_7EFD4) .paused;
}
static inline void replay_update_last(ReplayState_F3574 *state, ReplayTrack_F326C *track, s8 count, s32 i, u8 value) {
s32 j;
u32 offset = (u32)i + 2;
if (value != ((u8 *)track)[offset]) {
for (j = 0; j < count; j++) {
if (((u8 *)track)[offset] == fn_1_86810(j)) {
break;
}
}
if (j != count && j != i) {
fn_1_F3574(state, i, j, 0, value);
}
((u8 *)track)[offset] = value;
}
}

#pragma opt_strength_reduction off

void fn_1_F326C(ReplayState_F3574 *state) {
ReplayTrack_F326C *track;
s8 count;
u32 k;
s32 j;
s32 i;
u32 buttons;
u8 value;
u8 valid;
u8 idle;
u8 active;
s8 slot;
ReplayPos_F326C pos;
ReplayPos_F326C other;
f32 dz;
f32 dy;
f32 dx;
track = (ReplayTrack_F326C *)&state->buffer->eventCount;
if (!replay_is_recording() || replay_is_paused()) {
return;
}
state->frame++;
if (track->count >= 4) {
return;
}
count = (s8)fn_1_86624();
for (i = 0; i < count; i++) {
value = fn_1_86810(i);
if (((ReplayStateView_F326C *)state)->done[i] != 0) {
continue;
}
buttons = fn_1_864E8(i);
idle = value == 0;
slot = fn_1_86678(i);
valid = slot != -1;
active = idle | valid;
if (idle && fn_1_3F0C8() == 0x29 && track->count == 0) {
fn_1_F3574(state, i, i, 5, value);
continue;
}
if (!active) {
continue;
}
if (buttons & 0x10000) {
((ReplayStateView_F326C *)state)->done[i] = 1;
fn_1_F3574(state, i, i, 6, value);
} else if (buttons & 0x40000) {
fn_1_F3574(state, i, i, 7, value);
} else if (valid) {
if (buttons & 0x2000000) {
fn_1_862D4(i, &pos);
k = i;
for (j = i + 1; j < count; j++) {
fn_1_862D4(j, &other);
dx = other.x;
dx = dx - pos.x;
dy = other.y;
dy = dy - pos.y;
dz = other.z;
dz = dz - pos.z;
dx = dx * dx;
dx = dy * dy + dx;
dx = dz * dz + dx;
if (dx < 25.0f) {
if (fn_1_8CAF4(k, j) < 5.0f) {
fn_1_F3574(state, i, j, 2, value);
break;
}
}
}
} else if (buttons & 0x800000) {
fn_1_F3574(state, i, i, 3, value);
} else {
replay_update_last(state, track, count, i, value);
}
}
}
}
/* fzgx:end fn_1_F326C */

/* fzgx:begin fn_1_F3574 */
typedef signed char s8;


typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct {
u32 x;
u32 y;
u32 z;
} ReplayTriple_F3574;
typedef struct {
u32 start0 : 15;
u32 kind : 3;
u32 index : 5;
u32 value : 5;
u32 pad0 : 4;
u32 start : 15;
u32 count : 5;
u32 result : 5;
u32 stage : 5;
u32 pad1 : 2;
ReplayTriple_F3574 begin[4];
ReplayTriple_F3574 end[4];
ReplayTriple_F3574 begin1;
ReplayTriple_F3574 end1;
} ReplayEvent_F3574;
typedef struct {
u8 pad0[0xFEF0];
u16 eventCount;
u8 pad1[0x1E];
u16 slots[30];
ReplayEvent_F3574 events[1];
} ReplayBuffer_F3574;
typedef struct {
u32 unk_0;
u32 frame;
u8 pad0[0x10];
u8 playerCount;
u8 pad1[0x27];
ReplayBuffer_F3574 *buffer;
} ReplayState_F3574;


extern void fn_1_F3574(ReplayState_F3574 *state, u8 index, u8 value, u8 kind, u8 result);


extern void fn_1_862D4(s32 value, f32 *out);
extern u8 fn_1_8682C(int index);


void fn_1_F3574(ReplayState_F3574 *state, u8 index, u8 value, u8 kind, u8 result) {
ReplayEvent_F3574 *event;
s32 i;
s8 hit;
u16 slot;
if (state->buffer->eventCount >= 4) {
return;
}
if (state->frame > 0x7fff) {
return;
}
slot = state->buffer->slots[index];
if (slot != 0xffff) {
event = &state->buffer->events[slot];
if (state->frame - event->start < 60 && event->kind == kind) {
hit = 0;
switch (event->kind) {
case 0:
if ((s32)event->value == value) {
hit = 1;
} else {
event->value = value;
hit = 1;
event->result = result;
}
break;
case 7:
break;
default:
hit = 1;
break;
}
if (hit) {
event->start = state->frame;
fn_1_862D4(event->stage, (f32 *)(ReplayTriple_F3574 *)(&event->end1));
for (i = 0; i < state->playerCount; i++) {
fn_1_862D4(i, (f32 *)(ReplayTriple_F3574 *)(&event->end[i]));
}
return;
}
}
}
event = &state->buffer->events[state->buffer->eventCount];
state->buffer->slots[index] = state->buffer->eventCount;
state->buffer->eventCount++;
event->start0 = event->start = state->frame;
event->index = index;
event->value = value;
event->kind = kind;
if (kind == 0) {
event->count = result - 1;
} else {
event->count = result;
}
event->result = result;
event->stage = fn_1_8682C(0);
fn_1_862D4(event->stage, (f32 *)(ReplayTriple_F3574 *)(&event->begin1));
event->end1 = event->begin1;
for (i = 0; i < state->playerCount; i++) {
fn_1_862D4(i, (f32 *)(ReplayTriple_F3574 *)(&event->begin[i]));
event->end[i] = event->begin[i];
}
}
/* fzgx:end fn_1_F3574 */

/* fzgx:begin fn_1_F37F4 */
#include "types.h"





extern s8 fn_1_86678(s32 index);
extern u32 fn_1_864E8(s32 index);
extern u32 fn_1_86810(s32 index);
extern void fn_1_F3574(void *state, u8 index, u8 value, s32 kind, u32 result);

void fn_1_F37F4(void) {
    s32 index;

    if (*(u16 *)((u8 *)(*(u32 (*)[17])&lbl_1_bss_7EFD8)[16] + 0xfef0) == 0) {
        return;
    }

    for (index = 0; index < 4; index++) {
        if (index < (*(u8 (*)[5308])&lbl_1_bss_3C30)[9] &&
            fn_1_86678(index) != -1 &&
            ((u8 *)(*(u32 (*)[17])&lbl_1_bss_7EFD8))[index + 0x24] == 0 &&
            (fn_1_864E8(index) & 0x10000) != 0) {
            fn_1_F3574((*(u32 (*)[17])&lbl_1_bss_7EFD8), (u8)index, (u8)index, 6, fn_1_86810(index));
        }
    }
}
/* fzgx:end fn_1_F37F4 */

/* fzgx:begin fn_1_F38C0 */
extern u32 OSGetTick(void);

extern s8 fn_1_86624(void);
extern void *fn_1_86254(int);
extern void fn_80008BEC(u8 *, int, u32);

static inline void fn_1_F38C0_finish(Obj_1_bss_7EFD8 *state, u8 z0, u8 z1) {
    s32 i;
    u8 *bytes;
    u8 *flags;
    flags = (u8 *)&lbl_1_bss_7EFD8;
    bytes = flags;
    for (i = 0; i < 4; i++) {
        if (*(s32 *)(flags + 0x28) != 0) {
            s8 v = state->unk_40->unk_A0;
            *(s8 *)((u8 *)fn_1_86254(i) + 0x474) = v;
            state->unk_40->unk_A0++;
        }
        bytes[0x1c] = z0;
        bytes[0x20] = z1;
        flags += 4;
        bytes++;
    }
    state->unk_40->unk_A0--;
    lbl_1_bss_7EFD8.unk_1A = 0;
    lbl_1_bss_7EFD8.unk_1B = 0;
}

void fn_1_F38C0(void) {
    struct { Obj_1_bss_7EFD8 *value; } w;
    #define p (w.value)
    struct { u8 *value; } first;
    #define start (first.value)
    u8 *end;
    u8 *q;
    struct { s32 value; } count;
    #define n (count.value)

    p = (Obj_1_bss_7EFD8 *)&lbl_1_bss_7EFD8;
    start = (u8 *)p->unk_40 + 0xa4;
    p->unk_10 = 9300;
    p->unk_14 = 0x10000 - 9736;
    fn_80008BEC((u8 *)p + 0x28, 0, 16);
    n = (s8)fn_1_86624();
    if ((s8)fn_1_86624() > 4) {
        n = 4;
    }
    end = start + n * 7;
    for (q = start; q < end; q += 7) {
        *(u32 *)((u8 *)&lbl_1_bss_7EFD8 + 0x28 + ((*q & 3) << 2)) = 1;
    }
    fn_1_F38C0_finish(p, 0, 0);
}
/* fzgx:end fn_1_F38C0 */

/* fzgx:begin fn_1_F3AB0 */
extern s32 fn_1_F45CC(u16 value, void *out);
extern void fn_1_862D4(s32 value, f32 *out);

typedef struct {
    u16 unk_0;
    u8 pad_2[0xA];
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
} ReplayEntry_F3AB0;

void fn_1_F3AB0(Obj_1_bss_7EFD8 *obj) {
    f32 values[3];
    // The retail routine reserves this volatile scratch area for replay records.
    volatile u8 data[0xf80];
    ReplayEntry_F3AB0 *entry;
    s32 count;
    s32 i;
    u8 flags;
    s32 ok;

    flags = lbl_1_bss_7EFD4;
    if ((flags & 1) == 0) {
        ok = 0;
    } else if (((flags >> 2) & 1) == 0) {
        ok = 0;
    } else if (((flags >> 3) & 1) != 0) {
        ok = 0;
    } else {
        ok = 1;
    }
    if (ok == 0) {
        return;
    }

    obj->unk_4++;
    count = fn_1_F45CC((u16)obj->unk_4, (void *)data);
    if (count <= 0) {
        return;
    }

    fn_1_862D4(0, values);
    entry = (ReplayEntry_F3AB0 *)data;
    for (i = 0; i < count; i++) {
        if (obj->unk_4 == entry->unk_0 &&
            (values[0] != entry->unk_C ||
             values[1] != entry->unk_10 ||
             values[2] != entry->unk_14)) {
            lbl_1_bss_7EFD8.unk_1B = 1;
        }
        entry = (ReplayEntry_F3AB0 *)((u8 *)entry + 0x84);
    }
}
/* fzgx:end fn_1_F3AB0 */

/* fzgx:begin fn_1_F43F0 */
void fn_1_F43F0(u8 *bits, u32 *position, u32 mask, u32 count, u32 limit) {
    u32 value;
    u32 index;
    u32 bit;

    while (count != 0) {
        value = *position;
        index = value >> 3;
        if (index >= limit) {
            return;
        }
        bit = value & 7;
        if ((mask & (1 << (count - 1))) != 0) {
            bits[index] |= 1 << bit;
        }
        value = *position;
        count--;
        *position = value + 1;
    }
}
/* fzgx:end fn_1_F43F0 */

/* fzgx:begin fn_1_F444C */
extern void fn_80008BA8(u32 *, f32 *, int, f32);

void fn_1_F444C(u8 *out, u32 *pos, u32 limit, f32 value) {
    u32 mask;
    f32 input;
    u32 v;
    u32 bit;
    u32 index;
    u32 m;
    u32 count;

    input = value;
    fn_80008BA8(&mask, &input, 4, value);
    m = mask;
    count = 32;
    while (count != 0) {
        v = *pos;
        index = v >> 3;
        if (index >= limit) {
            return;
        }
        bit = v & 7;
        if ((m & (1u << (count - 1))) != 0) {
            out[index] |= 1u << bit;
        }
        v = *pos;
        count--;
        *pos = v + 1;
    }
}
/* fzgx:end fn_1_F444C */

/* fzgx:begin fn_1_F453C */
struct fn_1_F453C_Arg0 {
    u8 unk_0[1];
};
struct fn_1_F453C_Arg1 {
    u32 unk_0;
};

u32 fn_1_F453C(struct fn_1_F453C_Arg0 *arg0, struct fn_1_F453C_Arg1 *arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    s32 v2;
    u32 v3;

    v1 = arg2;
    v2 = 0;
    while (v1 != 0) {
        v3 = arg1->unk_0;
        if (((1 << (v3 & 0x7)) & arg0->unk_0[((u32)v3 >> 3)]) != 0) {
            v2 = v2 | (1 << (v1 - 1));
        }
        v1--;
        arg1->unk_0++;
    }
    return v2;
}
/* fzgx:end fn_1_F453C */

/* fzgx:begin fn_1_F4594 */
u32 fn_1_F4594(void) {
    return lbl_1_bss_7EFD8.unk_4;
}
/* fzgx:end fn_1_F4594 */

/* fzgx:begin fn_1_F45A4 */
u32 fn_1_F45A4(void) {
    return lbl_1_bss_7EFD8.unk_8;
}
/* fzgx:end fn_1_F45A4 */

/* fzgx:begin fn_1_F45B4 */
u32 fn_1_F45B4(void) {
    return ((__cntlzw(((lbl_1_bss_7EFD4 >> 4) & 0x1)) >> 5) & 0xFF);
}
/* fzgx:end fn_1_F45B4 */

/* fzgx:begin fn_1_F45CC */
typedef struct { u8 raw[0x80]; } ReplayEntry;
typedef struct { u8 raw[0x84]; } ReplayOutput;
typedef struct { u32 w[3]; } CopyChunk;

s32 fn_1_F45CC(u32 key, ReplayOutput *out) {
    s32 out_count;
    Obj_1_bss_7EFD8 *global;
    ReplayOutput *dst;
    s32 i;
    ReplayEntry *entry;

    key &= 0xffff;
    if (key > 0x7fff) {
        return 0;
    }
    out_count = 0;
    global = &lbl_1_bss_7EFD8;
    i = 0;
    entry = (ReplayEntry *)((u8 *)global->unk_40 + 0xff4c);
    while (i < (s32)*(u16 *)((u8 *)global->unk_40 + 0xfef0)) {
        u16 first;
        u16 last;

        first = (*(u16 *)(entry->raw + 0) >> 1) & 0x7fff;
        if (key >= first) {
            last = (*(u16 *)(entry->raw + 4) >> 1) & 0x7fff;
            if (key <= last) {
                if (out_count < 0x1e) {
                } else {
                    out_count = 0x1d;
                }
                dst = (ReplayOutput *)((u8 *)out + out_count * 0x84);
                out_count++;
                *(u16 *)(dst->raw + 0) = first;
                *(u16 *)(dst->raw + 2) = (*(u16 *)(entry->raw + 4) >> 1) & 0x7fff;
                dst->raw[4] = (*(u32 *)(entry->raw + 0) >> 14) & 7;
                dst->raw[5] = (entry->raw[2] >> 1) & 0x1f;
                dst->raw[6] = (*(u32 *)(entry->raw + 4) >> 12) & 0x1f;
                dst->raw[7] = (*(u16 *)(entry->raw + 6) >> 7) & 0x1f;
                dst->raw[8] = (entry->raw[7] >> 2) & 0x1f;
                *(CopyChunk *)(dst->raw + 0x0c) = *(CopyChunk *)(entry->raw + 0x08);
                *(CopyChunk *)(dst->raw + 0x3c) = *(CopyChunk *)(entry->raw + 0x38);
                *(CopyChunk *)(dst->raw + 0x18) = *(CopyChunk *)(entry->raw + 0x14);
                *(CopyChunk *)(dst->raw + 0x48) = *(CopyChunk *)(entry->raw + 0x44);
                *(CopyChunk *)(dst->raw + 0x24) = *(CopyChunk *)(entry->raw + 0x20);
                *(CopyChunk *)(dst->raw + 0x54) = *(CopyChunk *)(entry->raw + 0x50);
                *(CopyChunk *)(dst->raw + 0x30) = *(CopyChunk *)(entry->raw + 0x2c);
                *(CopyChunk *)(dst->raw + 0x60) = *(CopyChunk *)(entry->raw + 0x5c);
                *(CopyChunk *)(dst->raw + 0x6c) = *(CopyChunk *)(entry->raw + 0x68);
                *(CopyChunk *)(dst->raw + 0x78) = *(CopyChunk *)(entry->raw + 0x74);
            }
        }
        i++;
        entry++;
    }
    return out_count;
}
/* fzgx:end fn_1_F45CC */

/* fzgx:begin fn_1_F4794 */
void fn_1_F4794(u16 value) {
    lbl_1_bss_7F01C = value;
}
/* fzgx:end fn_1_F4794 */

/* fzgx:begin fn_1_F47A0 */
void fn_1_F47A0(u32 value) {
    lbl_1_bss_7F020 = value;
}
/* fzgx:end fn_1_F47A0 */

/* fzgx:begin fn_1_F47AC */
u32 fn_1_F47AC(void) {
    u32 tick;
    u8 flags;

    tick = OSGetTick();
    flags = lbl_1_bss_7EFD4;
    if ((flags & 1) == 0) {
        return tick;
    }
    if (((flags >> 1) & 1) != 0) {
        lbl_1_bss_7F020 = tick;
    } else if (((flags >> 2) & 1) != 0) {
        tick = lbl_1_bss_7F020;
    }
    return tick;
}
/* fzgx:end fn_1_F47AC */

/* fzgx:begin fn_1_F4810 */
struct fn_1_F4810_Arg0 { u8 unk_0[1]; };
struct fn_1_F4810_Arg1 { u8 unk_0; };
struct fn_1_F4810_Arg3 { u8 unk_0; };
struct fn_1_F4810_Arg4 { u8 unk_0; };
struct fn_1_F4810_Arg5 { u8 unk_0; };
struct fn_1_F4810_Arg6 { u8 unk_0; };

#pragma opt_propagation off
#pragma opt_lifetimes off
static inline s32 read_bits(struct fn_1_F4810_Arg0 *src, u32 *pos, s32 count) {
    s32 value = 0;
    while (count > 0) {
        if (src->unk_0[*pos >> 3] & (1 << (*pos & 7)))
            value |= 1 << (count - 1);
        count--;
        (*pos)++;
    }
    return value;
}

static inline s32 read_version_bits(struct fn_1_F4810_Arg0 *src, u32 *pos, s32 count) {
    s32 i;
    s32 n = count;
    s32 value = 0;
    count = count;
    for (i = 0; i < 7; i++) {
        if (src->unk_0[*pos >> 3] & (1 << (*pos & 7)))
            value |= 1 << (n - 1);
        n--;
        (*pos)++;
    }
    return value;
}

/* retail recomputes the buffer address inside the loop instead of hoisting it */
#pragma opt_loop_invariants off
void fn_1_F4810(struct fn_1_F4810_Arg0 *arg0, struct fn_1_F4810_Arg1 *arg1, u8 *arg2, struct fn_1_F4810_Arg3 *arg3, struct fn_1_F4810_Arg4 *arg4, struct fn_1_F4810_Arg5 *arg5, struct fn_1_F4810_Arg6 *arg6, u8 *arg7, u8 *arg8) {
    u32 pos = 8;
    u8 version;
    u8 id;
    u8 *out;
    s32 total;
    s32 index;
    u32 j;
    u8 present;
    version = read_version_bits(arg0, &pos, 7);
    arg1->unk_0 = read_bits(arg0, &pos, 6);
    read_bits(arg0, &pos, 32);
    read_bits(arg0, &pos, 32);
    arg6->unk_0 = read_bits(arg0, &pos, 5);
    arg5->unk_0 = read_bits(arg0, &pos, 3);
    arg4->unk_0 = read_bits(arg0, &pos, 2);
    pos += 8;
    out = arg8;
    total = 0;
    for (index = 0; index < arg6->unk_0; index++) {
        present = read_bits(arg0, &pos, 1);
        id = read_bits(arg0, &pos, 6);
        if (version >= 3) pos += 5;
        if (version >= 2) pos += 7;
        if (present) {
            *arg2 = id;
            pos += 2;
            if (version < 2) pos += 7;
            *arg7 = read_bits(arg0, &pos, 1);
            if (*arg7) {
                u8 buffer[0x81c0];
                for (j = 0; j < 0x81c0; j++) {
                    buffer[j] = read_bits(arg0, &pos, 8);
                }
                out[0] = buffer[0x81a4];
                out[1] = buffer[0x81ac];
                out[2] = buffer[0x81b4];
            }
            out += 3;
            total++;
            arg7++;
            arg2++;
        }
    }
    arg3->unk_0 = total;
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_F4810 */

/* fzgx:begin fn_1_F4E3C */
extern const f32 lbl_1_rodata_6D6C;
extern const f32 lbl_1_rodata_6D68;

f32 fn_1_F4E3C(s32 count, f32 *x, f32 *z, f32 *y, f32 value) {
    s32 lo;
    s32 hi;
    s32 mid;
    f32 x0;
    f32 y0;
    f32 y1;
    f32 x1;
    f32 z0;
    f32 z1;
    f32 t;
    f32 two;
    f32 dy;
    f32 dx;
    f32 thr;
    f32 tdy;
    f32 dz;
    f32 u;
    f32 s;
    f32 v;
    f32 w;
    f32 s2;
    f32 w2;
    f32 r;
    f32 sum;

    hi = count - 1;
    lo = 0;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (x[mid] < value) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    if (lo > 0) {
        lo--;
    }

    x0 = x[lo];
    y0 = y[lo];
    y1 = y[lo + 1];
    x1 = x[lo + 1];
    z0 = z[lo];
    z1 = z[lo + 1];

    t = value - x0;
    two = lbl_1_rodata_6D6C * y0;
    dy = y1 - y0;
    dx = x1 - x0;
    tdy = t * dy;
    thr = lbl_1_rodata_6D68 * y0;
    dz = z1 - z0;
    u = tdy / dx;
    s = two + y1;
    v = dz / dx;
    w = thr + u;
    s2 = dx * s;
    w2 = t * w;
    r = v - s2;
    sum = w2 + r;
    sum = t * sum;
    return z0 + sum;
}
/* fzgx:end fn_1_F4E3C */
