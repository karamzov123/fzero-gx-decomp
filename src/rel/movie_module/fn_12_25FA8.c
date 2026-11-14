#include "types.h"

typedef struct MovieOut {
    void *dest;
    s32 size;
} MovieOut;

typedef struct MovieHandlerVtbl {
    void *unk00;
    void *unk04;
    void *unk08;
    void *unk0c;
    void *unk10;
    void *unk14;
    void (*fn18)(void *, s32, s32, MovieOut *);
    void (*unk1c)(void *, s32, MovieOut *);
    void (*fn20)(void *, s32, MovieOut *);
    s32 (*fn24)(void *, s32);
} MovieHandlerVtbl;

typedef struct MovieHandler {
    MovieHandlerVtbl *vtable;
} MovieHandler;

typedef struct MovieSlots {
    MovieHandler *slot[175];
} MovieSlots;

typedef struct MovieSlot {
    MovieHandler *handler;
} MovieSlot;

typedef struct MovieRoot {
    void *field_000;
    u8 pad_004[0x140];
    void (*cb144)(void *, u32);
    void *cb148;
} MovieRoot;

typedef struct MovieValues {
    u32 value_00;
    u32 value_04;
    u32 value_08;
    u32 value_0c;
    u32 value_10;
    u32 value_14;
    u32 value_18;
    u32 value_1c;
} MovieValues;

typedef struct MovieModule {
    u8 pad_000[0x1aec];
    MovieRoot *root;
} MovieModule;

typedef s32 (*MovieTableFn)(MovieModule *, u32, s32, s32, u32);

extern int fn_12_24A88(void *arg0, int code);
extern int fn_12_683C(void *arg0, MovieValues *arg1);
extern void *fn_12_57F0(void *arg0, void *arg1, u32 arg2);
extern u32 lbl_12_bss_7E88;
extern void *lbl_12_rodata_BC8[4];

s32 fn_12_25FA8(MovieModule *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 *arg4) {
    void * fzgx_live;
    s32 rem;
    s32 tmp_call2;
    void (*cb)(void *, u32);
    void *cb_this;
    MovieRoot *root;
    s32 ret;
    s32 idx;
    s32 count;
    s32 sel;
    u32 pb;
    u32 pa;
    MovieHandler *handler;
    MovieValues values;
    MovieOut out1;
    MovieOut out2;

    ret = 0;
    *arg3 = 0;
    *arg4 = 0;
    root = arg0->root;
    tmp_call2 = fn_12_683C(root->field_000, &values);
    if (tmp_call2 != 0) {
        ret = fn_12_24A88(arg0, 0xff000d06);
    }
    count = values.value_1c;
    idx = values.value_00;
    sel = values.value_04;
    pa = values.value_08;
    pb = values.value_14;
    if (count < 0) {
        return fn_12_24A88(arg0, 0xff000d0e);
    }
    if (count == 0) {
        *arg3 = 0;
        *arg4 = 1;
        return 0;
    }
    if (arg2 < count) {
        return 0;
    }
    handler = ((MovieSlots *)((u8 *)root - 0x2bc))->slot[idx];
    if (handler != 0) {
        cb_this = root->cb148;
        cb = root->cb144;
        if (handler->vtable->fn24(handler, 0) < count) {
            arg1 = 0;
        } else {
            handler->vtable->fn18(handler, 0, count, &out1);
            fn_12_57F0(out1.dest, (void *)arg1, out1.size);
            handler->vtable->fn20(handler, 1, &out1);
            if (out1.size == 0) {
                arg1 = 0;
            } else {
                rem = count - out1.size;
                arg1 += out1.size;
                if (rem > 0) {
                    handler->vtable->fn18(handler, 0, rem, &out2);
                    fzgx_live = out2.dest;
                    fn_12_57F0(fzgx_live, (void *)arg1, out2.size);
                    handler->vtable->fn20(handler, 1, &out2);
                    if (out2.size != rem) {
                        lbl_12_bss_7E88++;
                    }
                }
                arg1 = 1;
            }
        }
        if (arg1 == 1 && cb != 0) {
            cb(cb_this, idx);
        }
        *arg4 = arg1;
    } else {
        *arg4 = ((MovieTableFn)lbl_12_rodata_BC8[sel])(arg0, pa, arg1, count, pb);
    }

    switch (*arg4) {
    case 1:
        *arg3 = count;
        break;
    case 0:
        break;
    default:
        ret = *arg4;
        break;
    }
    return ret;
}

