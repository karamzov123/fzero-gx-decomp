#include "types.h"
#pragma use_lmw_stmw on

/* --- rel/movie_module/fn_12_6ECC.c --- */
typedef struct MovieEntry {
    u32 flag;
    u8 pad[0xbc];
} MovieEntry;

typedef struct MovieWorkspace {
    u32 callback_words[3];
    s32 count;
    MovieEntry entries[];
} MovieWorkspace;

extern MovieWorkspace *lbl_12_bss_4DB8;
extern const char *lbl_12_bss_4DB4;
extern const char lbl_12_rodata_668[50];
extern void fn_12_33428(u32 *, u32, u32);
extern void fn_12_6708(void);
extern void fn_12_6A8C(void);

static inline void initialize_entry_range(MovieEntry *entries, s32 count, s32 first) {
    for (; first < count; first++) {
        entries[first].flag = 1;
    }
}

static inline s32 initialize_entries(s32 count, void *memory) {
    MovieWorkspace *workspace;
    u32 word_count;

    lbl_12_bss_4DB4 = lbl_12_rodata_668;
    lbl_12_bss_4DB8 = memory;
    word_count = (u32)((count - 1) * 0xc0 + 0xd0) >> 2;
    fn_12_33428((u32 *)memory, 0, word_count);
    workspace = lbl_12_bss_4DB8;
    workspace->callback_words[0] = 0;
    workspace->callback_words[1] = 0;
    workspace->callback_words[2] = 0;
    lbl_12_bss_4DB8->count = count;
    initialize_entry_range(lbl_12_bss_4DB8->entries, count, 0);
    return 0;
}

s32 fn_12_6ECC(s32 count, void *memory) {
    s32 result = initialize_entries(count, memory);
    if (result != 0) {
        return result;
    }
    fn_12_6708();
    fn_12_6A8C();
    return 0;
}

/* --- rel/movie_module/fn_12_6FEC.c --- */
/* --- rel/movie_module/fn_12_6FEC.c --- */
struct fn_12_6FEC_lbl_12_bss_68F8 {
    u32 unk_0;
};
struct fn_12_6FEC_lbl_12_bss_68FC {
    u32 unk_0;
};
struct fn_12_6FEC_lbl_12_bss_6900 {
    u32 unk_0;
};
struct fn_12_6FEC_lbl_12_bss_6904 {
    u32 unk_0;
};
struct fn_12_6FEC_lbl_12_bss_6908 {
    u32 unk_0;
};

extern struct fn_12_6FEC_lbl_12_bss_68F8 lbl_12_bss_68F8;
extern struct fn_12_6FEC_lbl_12_bss_68FC lbl_12_bss_68FC;
extern struct fn_12_6FEC_lbl_12_bss_6900 lbl_12_bss_6900;
extern struct fn_12_6FEC_lbl_12_bss_6904 lbl_12_bss_6904;
extern struct fn_12_6FEC_lbl_12_bss_6908 lbl_12_bss_6908;
extern u8 lbl_12_bss_4DC0[64];
extern u32 lbl_12_bss_68F4;
extern u8 lbl_12_bss_4E00[64];
extern void * memcpy(void *, const void *, u32);
extern void DCT_FsriInitScanTbl(const signed char *, signed char *);
extern void fn_12_33364(u32 *, u32 *, u32);

/* lbl_12_rodata_6A0: the MPEG tables of this TU, one .rodata section */
static const u16 fzgx_pool_bit_masks[16] = {
    0xFFFF, 0x7FFF, 0x3FFF, 0x1FFF, 0x0FFF, 0x07FF, 0x03FF, 0x01FF,
    0x00FF, 0x007F, 0x003F, 0x001F, 0x000F, 0x0007, 0x0003, 0x0001,
};
static const s8 fzgx_pool_zigzag[64] = {
    0x00, 0x01, 0x08, 0x10, 0x09, 0x02, 0x03, 0x0A, 0x11, 0x18, 0x20, 0x19, 0x12, 0x0B, 0x04, 0x05,
    0x0C, 0x13, 0x1A, 0x21, 0x28, 0x30, 0x29, 0x22, 0x1B, 0x14, 0x0D, 0x06, 0x07, 0x0E, 0x15, 0x1C,
    0x23, 0x2A, 0x31, 0x38, 0x39, 0x32, 0x2B, 0x24, 0x1D, 0x16, 0x0F, 0x17, 0x1E, 0x25, 0x2C, 0x33,
    0x3A, 0x3B, 0x34, 0x2D, 0x26, 0x1F, 0x27, 0x2E, 0x35, 0x3C, 0x3D, 0x36, 0x2F, 0x37, 0x3E, 0x3F,
};
static const u8 fzgx_pool_intra_quant[64] = {
    0x08, 0x10, 0x13, 0x16, 0x1A, 0x1B, 0x1D, 0x22, 0x10, 0x10, 0x16, 0x18, 0x1B, 0x1D, 0x22, 0x25,
    0x13, 0x16, 0x1A, 0x1B, 0x1D, 0x22, 0x22, 0x26, 0x16, 0x16, 0x1A, 0x1B, 0x1D, 0x22, 0x25, 0x28,
    0x16, 0x1A, 0x1B, 0x1D, 0x20, 0x23, 0x28, 0x30, 0x1A, 0x1B, 0x1D, 0x20, 0x23, 0x28, 0x30, 0x3A,
    0x1A, 0x1B, 0x1D, 0x22, 0x26, 0x2E, 0x38, 0x45, 0x1B, 0x1D, 0x23, 0x26, 0x2E, 0x38, 0x45, 0x53,
};
static const u8 fzgx_pool_defaults[32] = {
    5, 4, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
};

void fn_12_6FEC(u8 *arg0) {
    signed char tbl[64];
    signed char scan[64];
    s32 i;
    u32 *q;

    for (i = 0; i < 64; i++) {
        tbl[i] = i;
    }
    DCT_FsriInitScanTbl(tbl, scan);
    for (i = 0; i < 64; i++) {
        lbl_12_bss_4E00[i] = scan[fzgx_pool_zigzag[i]];
        lbl_12_bss_4DC0[scan[i]] = fzgx_pool_intra_quant[i];
    }
    q = (u32 *)(arg0 + 32);
    if (q != 0) {
        fn_12_33364(q, (u32 *)lbl_12_bss_4E00, 16);
    }
    if (arg0 != 0) {
        fn_12_33364((u32 *)arg0, (u32 *)fzgx_pool_bit_masks, 8);
    }
    memcpy(arg0 + 0x160, fzgx_pool_defaults, 32);
    *(u32 *)(arg0 + 0x180) = lbl_12_bss_68F4 - 16;
    *(u32 *)(arg0 + 0x184) = 21;
    *(u32 *)(arg0 + 0x188) = lbl_12_bss_68F8.unk_0 - 32;
    *(u32 *)(arg0 + 0x18c) = 19;
    *(u32 *)(arg0 + 0x190) = lbl_12_bss_68FC.unk_0 - 32;
    *(u32 *)(arg0 + 0x194) = 18;
    *(u32 *)(arg0 + 0x198) = lbl_12_bss_6900.unk_0 - 32;
    *(u32 *)(arg0 + 0x19c) = 17;
    *(u32 *)(arg0 + 0x1a0) = lbl_12_bss_6904.unk_0 - 32;
    *(u32 *)(arg0 + 0x1a4) = 16;
    *(u32 *)(arg0 + 0x1a8) = lbl_12_bss_6908.unk_0 - 32;
    *(u32 *)(arg0 + 0x1ac) = 15;
}

/* --- rel/movie_module/fn_12_72F4.c --- */
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
    Obj * base;

    flags = (u8 *)((u32)o + 0x78);
    req = &o->req;
    base = o;
    i = 0;
    o->f68 = o->f2bc;
    *(void **)((u8 *)req + 0x20) = (u8 *)o + 0xc80;
    o->f74 = 1;
    mask = o->f314 << 2;
    o->fa0 = mask;
    for (i = 0; i < 6; i++) {
        if ((s32)mask < 0) {
            req->buf = base->bufs[i];
            flags[i] = o->cb(o, req);
        }
        mask <<= 1;
    }
    fn_12_4F18((Sig_fn_12_4F18_MovieModule *)flags);
    return 0;
}
