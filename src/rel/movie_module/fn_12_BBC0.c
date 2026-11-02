#include "types.h"
#include "sofdec/sj.h"

#pragma use_lmw_stmw on

typedef void (*MPVFunc)();

typedef struct MPVContext {
    u8 pad_0[0x1a8];
    s32 unk_1a8;
    u8 pad_1ac[0x24];
    s32 unk_1d0;
    s32 unk_1d4;
    s32 unk_1d8;
    s32 unk_1dc;
    s32 unk_1e0;
    u8 pad_1e4[0x90];
    s32 unk_274;
    s32 unk_278;
    s32 unk_27c;
    s32 unk_280;
    u8 pad_284[0xc];
    MPVFunc unk_290;
    u8 pad_294[0x78];
    s32 unk_30c;
    u8 pad_310[0x930];
    u8 unk_c40[0x40];
    u8 unk_c80[0x40];
    u8 pad_cc0[0x608];
    SJCK unk_12c8;
    s32 unk_12d0;
    u8 pad_12d4[0x30];
    s32 unk_1304;
    u8 pad_1308[0x3c];
    u8 unk_1344[0x654][2];
} MPVContext;

extern void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);
extern void fn_12_33364(u32 *dst, u32 *src, u32 size);
extern void fn_12_33428(u32 *dst, u32 value, u32 count);
extern u32 lbl_12_bss_4DC0[];
extern s8 lbl_12_bss_4E00[];
extern MPVFunc const lbl_12_rodata_7A4[];
extern MPVFunc const lbl_12_rodata_7AC[];

/* read n bits (n < 32) from the cached big-endian bit window */
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
/* read one bit */
#define GET_BIT(dst)                                            \
    dst = current >> 31;                                        \
    if (shift == 31) {                                          \
        current = next;                                         \
        next = *p++;                                            \
        shift = 0;                                              \
    } else {                                                    \
        current <<= 1;                                          \
        shift++;                                                \
    }
#define SKIP_BITS(n)                                            \
    shift += (n);                                               \
    if (shift >= 32) {                                          \
        shift -= 32;                                            \
        current = next << shift;                                \
        next = *p++;                                            \
    } else {                                                    \
        current <<= (n);                                        \
    }

/* as in fn_12_B598, the end-of-header byte count needs the explicit temporaries kept */
#pragma opt_propagation off
int fn_12_BBC0(MPVContext *context, SJ *stream) {
    SJCK remainder;
    s32 width;
    s32 i;
    s32 j;
    u8 *data;
    s32 whole;
    u32 flag;
    u32 next;
    s32 shift;
    u32 current;
    u32 *p;
    u32 value;
    u32 word;

    context->unk_1304 = 1;
    stream->interface->get_chunk(stream, 1, 0x7FFFFFFF, &context->unk_12c8);
    p = (u32 *)((u32)context->unk_12c8.data & ~3);
    shift = ((u32)context->unk_12c8.data - (u32)p) * 8;
    word = p[1];
    p += 2;
    if (shift >= 32) {
        word = *p++;
        shift -= 32;
    }
    if (shift != 0) {
        word <<= shift;
    }
    next = *p++;
    current = word;

    GET_BITS(12, context->unk_1d0)
    GET_BITS(12, context->unk_1d4)
    GET_BITS(4, context->unk_274)
    GET_BITS(4, value)
    context->unk_1e0 = value;
    GET_BITS(18, context->unk_278)
    SKIP_BITS(1)
    GET_BITS(10, context->unk_27c)
    GET_BIT(context->unk_280)
    GET_BIT(flag)
    if (flag != 0) {
        for (i = 0; i < 64; i++) {
            GET_BITS(8, value)
            context->unk_c40[lbl_12_bss_4E00[i]] = value;
        }
    } else {
        fn_12_33364((u32 *)context->unk_c40, lbl_12_bss_4DC0, 16);
    }
    GET_BIT(flag)
    if (flag != 0) {
        for (j = 0; j < 64; j++) {
            GET_BITS(8, value)
            context->unk_c80[lbl_12_bss_4E00[j]] = value;
        }
    } else {
        fn_12_33428((u32 *)context->unk_c80, 0x10101010, 16);
    }

    context->unk_1d8 = (context->unk_1d0 + 15) >> 4;
    context->unk_1dc = (context->unk_1d4 + 15) >> 4;
    context->unk_30c = context->unk_1dc * context->unk_1d8 - 1;
    /* the bit-window words are dead here and are reused below: next as the table index, current/word as the
     * cursor and end of the 0x654 two-byte entries at 0x1344, j/i as the two counters (retail's register
     * assignment follows that reuse) */
    width = context->unk_1d8;
    next = context->unk_1a8 != 3;
    if (width * context->unk_1dc < 0x654) {
        current = (u32)context->unk_1344[0];
        word = current + 0xca8;
        j = 0;
        i = 0;
        while (current < word) {
            if (i >= width) {
                i = 0;
                j++;
            }
            ((u8 *)current)[0] = j;
            ((u8 *)current)[1] = i;
            current += 2;
            i++;
        }
        context->unk_290 = lbl_12_rodata_7A4[next];
    } else {
        context->unk_290 = lbl_12_rodata_7AC[next];
    }

    context->unk_12d0 = shift & 7;
    data = context->unk_12c8.data;
    whole = shift - context->unk_12d0;
    p = (u32 *)((u32)p + ((whole + 7) >> 3));
    fn_800589BC(&context->unk_12c8, ((u32)p - 8) - (u32)data, &context->unk_12c8, &remainder);
    stream->interface->put_chunk(stream, 0, &context->unk_12c8);
    stream->interface->unget_chunk(stream, 1, &remainder);
    return 0;
}
#pragma opt_propagation reset
