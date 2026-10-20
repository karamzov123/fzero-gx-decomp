#include "types.h"

extern char lbl_12_rodata_1D88[];
extern void MWSFSVM_Error(const char *, ...);

typedef u32 (*FnAlloc)(void *, s32);
typedef void (*FnFree)(void *, u32);

typedef struct AllocCtx {
    u8 pad_0[0x28];
    FnAlloc alloc;
    FnFree free_fn;
    void *data;
} AllocCtx;

typedef struct MovieState {
    u8 pad_20[0x20];
    s32 state;
} MovieState;

typedef struct MovieModule {
    u8 pad_0[0x14];
    u32 field_14;
    u32 field_18;
    u8 pad_1c[0x90];
    u32 field_ac;
    u32 field_b0;
    u8 pad_b4[0x38];
    u32 field_ec;
    u32 field_f0;
    u8 pad_f4[0x64];
    u32 field_158;
    u32 field_15c;
    u32 field_160;
    u32 field_164;
    s32 count;
    u32 arr[32];
} MovieModule;

typedef struct { MovieModule *value; } ModRef;
typedef struct { const char *value; } MsgRef;

extern s32 fn_12_35DB4(u32, u32);
extern AllocCtx *fn_12_38DBC(void);
extern s32 fn_12_35548(MovieState *);

static inline FnFree fn_12_36208_read_pointer(AllocCtx * owner) { return owner->free_fn; }
static inline void * fn_12_36208_read_pointer_(AllocCtx * owner) { return owner->data; }
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_dead_assignments off
s32 fn_12_36208(MovieModule *m) {
    FnAlloc fzgx_live_;
    void * fzgx_live;
    MovieState *st;
    u32 p = 0;
    AllocCtx *ctx;
    u32 *slot_2;
    u32 *slot;
    u32 ptr2;
    u32 ptr;
    s32 off;
    s32 i = 0;
    const char *base = lbl_12_rodata_1D88;
    MsgRef msg;
    ModRef mm;
    const char * lab_t0;

    msg.value = base;
    mm.value = m;
    st = (MovieState *)((u8 *)mm.value + 0xc);

    off = fn_12_35DB4(mm.value->field_14, mm.value->field_18);

    if (mm.value->count >= 32) {
        lab_t0 = msg.value + 0x6c;
        MWSFSVM_Error(lab_t0);
        ptr = 0;
    } else if (off < 0) {
        ptr = 0;
    } else {
        if (mm.value->field_158 != 0) {
            if (mm.value->field_164 + off > mm.value->field_15c) {
                ptr = 0;
            } else {
                ptr = mm.value->field_160;
                mm.value->field_160 = ptr + off;
                mm.value->field_164 = mm.value->field_164 + off;
            }
        } else {
            ctx = fn_12_38DBC();
            fzgx_live_ = ctx->alloc;
            ptr = fzgx_live_(fn_12_36208_read_pointer_(ctx), off);
        }
        if (ptr != 0) {
            mm.value->arr[mm.value->count] = ptr;
            mm.value->count++;
        }
    }

    if (ptr == 0) {
        lab_t0 = msg.value + 0x11c;
        MWSFSVM_Error(lab_t0);
        for (i = 0; i < 32; i++) {
            slot = &mm.value->arr[31 - i];
            p = *slot;
            if (((0) != (p))) {
                if (mm.value->field_158 == 0) {
                    ctx = fn_12_38DBC();
                    fzgx_live = ctx->data;
                    fn_12_36208_read_pointer(ctx)(fzgx_live, p);
                }
                mm.value->count--;
                *slot = 0;
            }
        }
        return -1;
    }

    mm.value->field_ac = ptr;
    mm.value->field_b0 = off;

    if (fn_12_35548(st) == 1) {
        if (mm.value->count >= 32) {
            lab_t0 = msg.value + 0x6c;
            MWSFSVM_Error(lab_t0);
            ptr2 = 0;
        } else {
            if (mm.value->field_158 != 0) {
                if (mm.value->field_164 + 0x20000 > mm.value->field_15c) {
                    ptr2 = 0;
                } else {
                    ptr2 = mm.value->field_160;
                    mm.value->field_160 = ptr2 + 0x20000;
                    mm.value->field_164 = mm.value->field_164 + 0x20000;
                }
            } else {
                ctx = fn_12_38DBC();
                fzgx_live = ctx->data;
                fzgx_live_ = ctx->alloc;
                ptr2 = fzgx_live_(fzgx_live, 0x20000);
            }
            if (ptr2 != 0) {
                mm.value->arr[mm.value->count] = ptr2;
                mm.value->count++;
            }
        }

        if (ptr2 == 0) {
            lab_t0 = msg.value + 0x140;
            MWSFSVM_Error(lab_t0);
            for (i = 0; i < 32; i++) {
                slot_2 = &mm.value->arr[31 - i];
                p = *slot_2;
                if (((0) != (p))) {
                    if (mm.value->field_158 == 0) {
                        ctx = fn_12_38DBC();
                        fzgx_live = ctx->data;
                        fn_12_36208_read_pointer(ctx)(fzgx_live, p);
                    }
                    mm.value->count--;
                    *slot_2 = 0;
                }
            }
            return -1;
        }

        mm.value->field_ec = ptr2;
        mm.value->field_f0 = 0x20000;
    } else {
        mm.value->field_ec = 0;
        mm.value->field_f0 = 0;
    }

    return 0;
}
#pragma opt_dead_assignments reset

#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset
