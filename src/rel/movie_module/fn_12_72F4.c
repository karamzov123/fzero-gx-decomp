#include "types.h"

#pragma use_lmw_stmw on

typedef struct Sig_fn_12_4F18_MovieModule {
    u8 pad_28[0x28];
    void *field_28;
} Sig_fn_12_4F18_MovieModule;
extern void fn_12_4F18(Sig_fn_12_4F18_MovieModule *);

typedef struct Req {
    u8 pad[0x1c];
    void *buf;
} Req;

typedef struct Obj Obj;
struct Obj {
    u8 pad0[0x44];
    Req req;
    void *f64;
    s32 f68;
    u8 pad2[0x74 - 0x6c];
    s32 f74;
    u8 flags[8];
    u8 pad3[0xa0 - 0x80];
    s32 fa0;
    u8 pad4[0x2bc - 0xa4];
    s32 f2bc;
    u8 pad5[0x314 - 0x2c0];
    s32 f314;
    u8 pad6[0x640 - 0x318];
    s8 bufs[6][0x100];
    u8 pad7[0x12ec - 0xc40];
    u8 (*cb)(Obj *, Req *);
};

s32 fn_12_72F4(Obj *o) {
    u32 mask;
    s32 i;
    Req *req;
    u8 *flags;
    struct { Obj *value; } base;

    flags = (u8 *)((u32)o + 0x78);
    req = &o->req;
    base.value = o;
    i = 0;
    o->f68 = o->f2bc;
    *(void **)((u8 *)req + 0x20) = (u8 *)o + 0xc80;
    o->f74 = 1;
    mask = o->f314 << 2;
    o->fa0 = mask;
    for (i = 0; i < 6; i++) {
        if ((s32)mask < 0) {
            req->buf = base.value->bufs[i];
            flags[i] = o->cb(o, req);
        }
        mask <<= 1;
    }
    fn_12_4F18((Sig_fn_12_4F18_MovieModule *)flags);
    return 0;
}
