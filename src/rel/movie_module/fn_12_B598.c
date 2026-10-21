#include "types.h"
typedef struct MovieObject MovieObject;
typedef struct MovieBits { u32 address; s32 limit; s32 bit; } MovieBits;
typedef struct MovieVTable {
    u8 pad[0x18];
    void (*method_0018)(MovieObject *, s32, s32, MovieBits *);
    void (*method_001c)(MovieObject *, s32, void *);
    void (*method_0020)(MovieObject *, s32, MovieBits *);
} MovieVTable;
struct MovieObject { MovieVTable *vtable; };

typedef void (*MovieFn)();

typedef struct MovieState {
    u8 pad0[0x1a0];
    s32 unk1a0;
    u32 pad1a4;
    s32 unk1a8;
    u8 pad1ac[0x38];
    u32 unk1e4;
    s32 unk1e8;
    u8 pad1ec[0xa0];
    u32 unk28c;
    u32 pad290;
    MovieFn unk294;
    MovieFn unk298;
    MovieFn unk29c;
    MovieFn unk2a0;
    MovieFn unk2a4;
    MovieFn unk2a8;
    MovieFn unk2ac;
    MovieFn unk2b0;
    MovieFn unk2b4;
    u8 pad2b8[8];
    u32 unk2c0;
    u32 unk2c4;
    u32 unk2c8;
    u32 unk2cc;
    u8 pad2d0[0x14];
    u32 unk2e4;
    u32 unk2e8;
    u32 unk2ec;
    u32 unk2f0;
    u8 pad2f4[0xfd4];
    MovieBits bits;
    u8 pad12d4[0x30];
    u32 state;
} MovieState;

extern void MPVCDEC_IntraBlocks();
extern void fn_12_72F4();
extern void fn_12_9D08();
extern void fn_12_975C();
extern void fn_12_8F80();
extern void fn_12_8BD8();
extern void fn_12_11860();
extern void fn_12_11254();
extern void fn_12_7940();
extern void fn_12_78C0();
extern void fn_12_11204();
extern void fn_12_7870();
extern void fn_12_11188();
extern void fn_12_77F4();
extern void fn_12_124A0();
extern void fn_12_8A10();
extern void fn_12_89D4();
extern void fn_12_12270();
extern void fn_12_87FC();
extern void fn_12_879C();
extern void fn_12_121BC();
extern void fn_12_873C();
extern void fn_12_120E4();
extern void fn_12_86B8();
extern u32 fn_800589BC(MovieBits *, s32, MovieBits *, void *);

/* picture-type dispatch tables, indexed [non-intra?][picture type]; the
 * whole cluster is addressed off one section base in retail */
extern u8 fn_12_11188__fzgx_offset_0[];
extern u8 fn_12_11204__fzgx_offset_0[];
extern u8 fn_12_11254__fzgx_offset_0[];
extern u8 fn_12_11860__fzgx_offset_0[];
extern u8 fn_12_120E4__fzgx_offset_0[];
extern u8 fn_12_121BC__fzgx_offset_0[];
extern u8 fn_12_12270__fzgx_offset_0[];
extern u8 fn_12_124A0__fzgx_offset_0[];
extern u8 fn_12_77F4__fzgx_offset_0[];
extern u8 fn_12_7870__fzgx_offset_0[];
extern u8 fn_12_78C0__fzgx_offset_0[];
extern u8 fn_12_7940__fzgx_offset_0[];
extern u8 fn_12_86B8__fzgx_offset_0[];
extern u8 fn_12_873C__fzgx_offset_0[];
extern u8 fn_12_879C__fzgx_offset_0[];
extern u8 fn_12_87FC__fzgx_offset_0[];
extern u8 fn_12_89D4__fzgx_offset_0[];
extern u8 fn_12_8A10__fzgx_offset_0[];
extern u8 fn_12_8BD8__fzgx_offset_0[];
extern u8 fn_12_8F80__fzgx_offset_0[];
extern u8 fn_12_975C__fzgx_offset_0[];
extern u8 fn_12_9D08__fzgx_offset_0[];
static const union { u32 w[5]; MovieFn const v[5]; } fzgx_pool_init_lbl_12_rodata_768 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)fn_12_9D08__fzgx_offset_0, (u32)fn_12_975C__fzgx_offset_0, (u32)fn_12_8F80__fzgx_offset_0, (u32)fn_12_8BD8__fzgx_offset_0
}};
static const union { u32 w[10]; MovieFn const v[2][5]; } fzgx_pool_init_fzgx_tbl_77C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, (u32)fn_12_11860__fzgx_offset_0, (u32)fn_12_11254__fzgx_offset_0, 0x0, 0x0, 0x0, (u32)fn_12_7940__fzgx_offset_0,
    (u32)fn_12_78C0__fzgx_offset_0, 0x0
}};
static const union { u32 w[2]; MovieFn const v[2]; } fzgx_pool_init_lbl_12_rodata_7A4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)fn_12_11204__fzgx_offset_0, (u32)fn_12_7870__fzgx_offset_0
}};
static const union { u32 w[2]; MovieFn const v[2]; } fzgx_pool_init_lbl_12_rodata_7AC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)fn_12_11188__fzgx_offset_0, (u32)fn_12_77F4__fzgx_offset_0
}};
static const union { u32 w[20]; MovieFn const v[2][2][5]; } fzgx_pool_init_fzgx_tbl_7B4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)fn_12_124A0__fzgx_offset_0, (u32)fn_12_124A0__fzgx_offset_0, (u32)fn_12_124A0__fzgx_offset_0, (u32)fn_12_124A0__fzgx_offset_0, 0x0, (u32)fn_12_8A10__fzgx_offset_0, (u32)fn_12_8A10__fzgx_offset_0,
    (u32)fn_12_89D4__fzgx_offset_0, (u32)fn_12_8A10__fzgx_offset_0, 0x0, (u32)fn_12_124A0__fzgx_offset_0, (u32)fn_12_124A0__fzgx_offset_0, (u32)fn_12_124A0__fzgx_offset_0, (u32)fn_12_124A0__fzgx_offset_0, 0x0,
    (u32)fn_12_89D4__fzgx_offset_0, (u32)fn_12_89D4__fzgx_offset_0, (u32)fn_12_89D4__fzgx_offset_0, (u32)fn_12_89D4__fzgx_offset_0
}};
static const union { u32 w[10]; MovieFn const v[2][5]; } fzgx_pool_init_fzgx_tbl_804 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, (u32)fn_12_12270__fzgx_offset_0, (u32)fn_12_12270__fzgx_offset_0, 0x0, 0x0, 0x0, (u32)fn_12_87FC__fzgx_offset_0,
    (u32)fn_12_879C__fzgx_offset_0, 0x0
}};
static const union { u32 w[10]; MovieFn const v[2][5]; } fzgx_pool_init_fzgx_tbl_82C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, (u32)fn_12_121BC__fzgx_offset_0, 0x0, 0x0, 0x0, 0x0,
    (u32)fn_12_873C__fzgx_offset_0, 0x0
}};
static const union { u32 w[10]; MovieFn const v[2][5]; } fzgx_pool_init_fzgx_tbl_854 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, (u32)fn_12_120E4__fzgx_offset_0, 0x0, 0x0, 0x0, 0x0,
    (u32)fn_12_86B8__fzgx_offset_0, 0x0
}};

/* read N bits (N < 32) from the cached big-endian bit window */
#define GET_BITS(n, dst)                                        \
    if (shift >= 32 - (n)) {                                    \
        shift -= 32 - (n);                                      \
        if (shift != 0) {                                       \
            current |= next >> ((n) - shift);                   \
            dst = current >> (32 - (n));                        \
            current = next << shift;                            \
        } else {                                                \
            dst = current >> (32 - (n));                        \
            current = next;                                     \
        }                                                       \
        next = *p++;                                            \
    } else {                                                    \
        dst = current >> (32 - (n));                            \
        current <<= (n);                                        \
        shift += (n);                                           \
    }

#define SKIP_BIT()                                              \
    if (shift == 31) {                                          \
        current = next;                                         \
        next = *p++;                                            \
        shift = 0;                                              \
    } else {                                                    \
        current <<= 1;                                          \
        shift++;                                                \
    }

#pragma opt_propagation off
s32 fn_12_B598(MovieState *ctx, MovieObject *movie) {
    u32 result[2];
    u32 word;
    s32 shift;
    u32 next;
    u32 current;
    u32 cur;
    u32 *p;
    u32 value;
    s32 type;
    s32 ne;
    s32 mode;
    u32 base;
    s32 whole;
    u8 *end;

    ctx->state = 3;
    movie->vtable->method_0018(movie, 1, 0x7fffffff, &ctx->bits);
    p = (u32 *)(ctx->bits.address & ~3);
    shift = (ctx->bits.address - (u32)p) * 8;
    word = p[1];
    p += 2;
    if (shift >= 32) { word = *p++; shift -= 32; }
    cur = word;
    if (shift != 0) cur = word << shift;
    next = *p++;
    current = cur;

    GET_BITS(10, ctx->unk1e4)
    GET_BITS(3, value)
    ctx->unk1e8 = value;
    GET_BITS(16, ctx->unk28c)

    type = ctx->unk1e8;
    if (type == 2 || type == 3) {
        ctx->unk2c0 = current >> 31;
        SKIP_BIT()
        GET_BITS(3, value)
        value -= 1;
        ctx->unk2c4 = value;
        ctx->unk2c8 = 27 - value;
        ctx->unk2cc = 1 << value;
    }
    if (type == 3) {
        ctx->unk2e4 = current >> 31;
        SKIP_BIT()
        GET_BITS(3, value)
        value -= 1;
        ctx->unk2e8 = value;
        ctx->unk2ec = 27 - value;
        ctx->unk2f0 = 1 << value;
    }

    ne = ctx->unk1a8 != 3;
    mode = ctx->unk1a0;
    ctx->unk294 = fzgx_pool_init_lbl_12_rodata_768.v[type];
    ctx->unk298 = fzgx_pool_init_fzgx_tbl_77C.v[ne][type];
    ctx->unk29c = MPVCDEC_IntraBlocks;
    ctx->unk2a0 = fn_12_72F4;
    ctx->unk2a4 = fzgx_pool_init_fzgx_tbl_7B4.v[mode][ne][type];
    ctx->unk2ac = fzgx_pool_init_fzgx_tbl_82C.v[ne][type];
    ctx->unk2b0 = fzgx_pool_init_fzgx_tbl_804.v[ne][type];
    ctx->unk2b4 = fzgx_pool_init_fzgx_tbl_854.v[ne][type];
    ctx->unk2a8 = ctx->unk2b0;

    /* skip extra information: 1-bit flag followed by an 8-bit byte */
    for (;;) {
        if ((current >> 31) == 0) {
            shift++;
            if (shift >= 32) {
                shift -= 32;
                p++;
            }
            break;
        }
        shift += 9;
        if (shift >= 32) {
            shift -= 32;
            current = next << shift;
            next = *p++;
        } else {
            current <<= 9;
        }
        end = (u8 *)p + ((shift + 7) >> 3);
        if (ctx->bits.limit <= (s32)(end - 8 - (u8 *)ctx->bits.address)) {
            return -3;
        }
    }

    ctx->bits.bit = shift & 7;
    base = ctx->bits.address;
    whole = shift - ctx->bits.bit;
    p = (u32 *)((u8 *)p + ((whole + 7) >> 3));
    p = (u32 *)((u8 *)p - 8 - (u8 *)base);
    fn_800589BC(&ctx->bits, (s32)p, &ctx->bits, &result);
    movie->vtable->method_0020(movie, 0, &ctx->bits);
    movie->vtable->method_001c(movie, 1, &result);
    return 0;
}
