#include "types.h"

typedef struct MovieValues {
    s32 value_00;
    s32 value_04;
    s32 value_08;
    s32 value_0c;
    s32 value_10;
    s32 value_14;
    s32 value_18;
    s32 value_1c;
} MovieValues;

typedef struct MovieModule {
    u8 pad00[0x10];
    int field10;
    u8 field14[0x0c];
    MovieValues values;
    MovieValues slots[3];
    u8 fielda0[0x20];
} MovieModule;

typedef struct {
    u32 flag;
    u32 packed;
    u32 value;
} movie_bitstream_out;

struct fn_12_5810_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0xC];
    u32 unk_1C;
};
extern s32 fn_12_670C(const u8 *data);
extern s32 fn_12_6C78(u32 arg0);
extern int fn_12_6D5C(int, int);
extern void fn_12_62F8(movie_bitstream_out *out, const u8 *data, u32 *kind);
extern void fn_12_5FA0(void *, const void *, int *);
extern void fn_12_5810();

/* fzgx:begin fn_12_5810 */
#pragma opt_loop_invariants off

/* --- rel/movie_module/fn_12_5810.c --- */

#define READ_BITS(n, dst) \
    if ((s32)v5 >= 32 - (n)) { \
        v5 -= 32 - (n); \
        if (v5 != 0) { \
            v10 |= v7 >> ((n) - v5); \
            (dst) = v10 >> (32 - (n)); \
            v10 = v7 << v5; \
        } else { \
            (dst) = v10 >> (32 - (n)); \
            v10 = v7; \
        } \
        v7 = *(u32 *)v8; \
        v8 += 4; \
    } else { \
        (dst) = v10 >> (32 - (n)); \
        v10 <<= (n); \
        v5 += (n); \
    }
#define SKIP_BITS(n) \
    v5 += (n); \
    if ((s32)v5 >= 32) { \
        v5 -= 32; \
        v10 = v7 << v5; \
        v7 = *(u32 *)v8; \
        v8 += 4; \
    } else { \
        v10 <<= (n); \
    }
#define PEEK_BITS(n, dst) \
    (dst) = v10 >> (32 - (n)); \
    if ((s32)v5 > 32 - (n)) { \
        (dst) |= v7 >> (64 - (n) - v5); \
    }

void fn_12_5810(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
struct fn_12_5810_Arg0 *arg0;
const void *arg1;
int *arg2;
int arg3;
u32 arg4;
u32 arg5;
u32 arg6;
u32 arg7;
{
    void *v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    s32 v5;
    u32 v10;
    u32 v7;
    u32 v8;
    u32 v6;
    u32 v12;
    u32 v11;
    u32 v9;
    u32 v13;
    u32 v14;
    u32 v15;
    u32 v16;
    u32 v17;
    u32 v18;
    u32 v19;
    u32 v20;
    u32 v21;
    u32 v22;
    u32 v23;
    u32 v24;
    v0 = (u8 *)arg1 + 3;
    v1 = (u32)v0 & ~3;
    v2 = ((u32)v0 - v1) << 3;
    v10 = *(u32 *)v1;
    v5 = v2;
    v7 = *(u32 *)(v1 + 4);
    v8 = v1 + 8;
    v10 <<= v5;
    READ_BITS(8, v6);
    arg0->unk_0 = v6;
    if ((s32)v6 >= 224 && (s32)v6 <= 239) {
        v11 = v6 - 224;
        v12 = 1;
    } else if ((s32)v6 >= 192 && (s32)v6 <= 223) {
        v11 = v6 - 192;
        v12 = 0;
    } else if ((s32)v6 == 189) {
        v12 = 2;
        v11 = 1;
    } else if ((s32)v6 == 191) {
        v12 = 2;
        v11 = 2;
    } else if ((s32)v6 == 190) {
        v12 = 3;
        v11 = 0;
    } else {
        v12 = 4;
        v11 = 0;
    }
    arg0->unk_4 = v12;
    arg0->unk_8 = v11;
    if (arg3 == 2) {
        READ_BITS(16, arg0->unk_C);
        v14 = 6;
    } else {
        if (v5 != 0) {
            arg0->unk_C = v10 | (v7 >> (32 - v5));
            v10 = v7 << v5;
        } else {
            arg0->unk_C = v10;
            v10 = v7;
        }
        v7 = *(u32 *)v8;
        v14 = 8;
        v8 += 4;
    }
    if ((s32)v6 == 191 || (s32)v6 == 190) {
        *arg2 = v14;
        arg0->unk_1C = arg0->unk_C;
    } else {
        for (;;) {
            PEEK_BITS(8, v12);
            if (v12 != 255) break;
            SKIP_BITS(8);
        }
        PEEK_BITS(2, v12);
        if (v12 == 1) {
            SKIP_BITS(2);
            v12 = v10 >> 31;
            if (v5 == 31) {
                v10 = v7;
                v7 = *(u32 *)v8;
                v5 = 0;
                v8 += 4;
            } else {
                v10 <<= 1;
                v5 += 1;
            }
            READ_BITS(13, v11);
            v11 <<= 7;
            if ((s32)v12 != 0) v11 <<= 3;
            *(u32 *)&arg0->pad_10[0] = v11;
        }
        PEEK_BITS(4, v12);
        if (v12 == 2) {
            SKIP_BITS(4);
            READ_BITS(3, v11);
            SKIP_BITS(1);
            READ_BITS(15, v12);
            SKIP_BITS(1);
            READ_BITS(15, v13);
            SKIP_BITS(1);
            *(u32 *)&arg0->pad_10[4] = (v11 << 28) | (v12 << 13) | (v13 >> 2);
            *(u32 *)&arg0->pad_10[8] = -1;
        } else if (v12 == 3) {
            SKIP_BITS(4);
            READ_BITS(3, v12);
            SKIP_BITS(1);
            READ_BITS(15, v11);
            SKIP_BITS(1);
            READ_BITS(15, v13);
            SKIP_BITS(1);
            *(u32 *)&arg0->pad_10[4] = (v12 << 28) | (v11 << 13) | (v13 >> 2);
            SKIP_BITS(4);
            READ_BITS(3, v11);
            SKIP_BITS(1);
            READ_BITS(15, v12);
            SKIP_BITS(1);
            READ_BITS(15, v13);
            SKIP_BITS(1);
            *(u32 *)&arg0->pad_10[8] = (v11 << 28) | (v12 << 13) | (v13 >> 2);
        } else {
            SKIP_BITS(8);
            *(u32 *)&arg0->pad_10[4] = -1;
            *(u32 *)&arg0->pad_10[8] = -1;
        }
        v5 = v8 + ((v5 + 7) >> 3);
        *arg2 = (v5 - 8) - (u32)arg1;
        arg0->unk_1C = arg0->unk_C + v14 - *arg2;
    }
}
/* fzgx:end fn_12_5810 */

/* fzgx:begin fn_12_5FA0 */

#define READ_BITS(value, n) \
    if (bits >= 32-(n)) { \
        bits -= 32-(n); \
        if (bits != 0) { \
            current |= next >> ((n)-bits); \
            value = current >> (32-(n)); \
            current = next << bits; \
        } else { \
            value = current >> (32-(n)); \
            current = next; \
        } \
        next = *words++; \
    } else { \
        value = current >> (32-(n)); \
        current <<= (n); \
        bits += (n); \
    }
#define READ_BIT(value) \
    value = current >> 31; \
    if (bits == 31) { \
        current = next; \
        next = *words++; \
        bits = 0; \
    } else { \
        current <<= 1; \
        bits += 1; \
    }
#define SKIP_BITS(n) \
    bits += (n); \
    if (bits >= 32) { \
        bits -= 32; \
        current = next << bits; \
        next = *words++; \
    } else { \
        current <<= (n); \
    }

void fn_12_5FA0(void *output, const void *data, int *count) {
    int bits;
    u32 current;
    u32 next;
    const u32 *words;
    const u8 *end;
    u32 *out;
    u32 address;

    out = (u32 *)output;
    address = (u32)data + 4;
    words = (const u32 *)(address & ~3);
    bits = (address - (u32)words) * 8;
    current = *words++;
    next = *words++;
    current <<= bits;
    READ_BITS(out[0], 16);
    SKIP_BITS(1);
    READ_BITS(out[1], 22);
    SKIP_BITS(1);
    READ_BITS(out[2], 6);
    READ_BIT(out[4]);
    READ_BIT(out[5]);
    READ_BIT(out[6]);
    READ_BIT(out[7]);
    SKIP_BITS(1);
    READ_BITS(out[3], 5);
    SKIP_BITS(8);
    /* marker bit: skip 24-bit extension blocks while set */
    for (;;) {
        if (!(current >> 31))
            break;
        SKIP_BITS(24);
    }
    end = (const u8 *)(words - 2) + ((bits + 7) >> 3);
    *count = end - (const u8 *)data;
    if (fn_12_670C( (const u8 *)(const void *)(end)) == 0 && fn_12_670C( (const u8 *)(const void *)(end + 1)) == 0x40000) {
        (*count)++;
    }
}
/* fzgx:end fn_12_5FA0 */

/* fzgx:begin fn_12_62F8 */

#define READ_BITS(n, result) \
    if (bits >= 32 - (n)) { \
        bits -= 32 - (n); \
        if (bits) { \
            word |= next >> ((n) - bits); \
            result = word >> (32 - (n)); \
            word = next << bits; \
        } else { \
            result = word >> (32 - (n)); \
            word = next; \
        } \
        next = *p++; \
    } else { \
        result = word >> (32 - (n)); \
        word <<= (n); \
        bits += (n); \
    }
#define SKIP_BITS(n) \
    bits += (n); \
    if (bits >= 32) { \
        bits -= 32; \
        word = next << bits; \
        next = *p++; \
    } else { \
        word <<= (n); \
    }

void fn_12_62F8(movie_bitstream_out *out, const u8 *data, u32 *kind)
{
    const u8 *start = data + 4;
    const u32 *p = (const u32 *)((u32)start & ~3);
    int bits = ((u32)start - (u32)p) * 8;
    u32 word = *p++;
    u32 next = *p++;
    u32 a, c, e, g, j;
    word <<= bits;
    if (bits >= 30) {
        bits -= 30;
        if (bits) {
            word |= next >> 1;
            a = word >> 30;
            word = next << 1;
        } else {
            a = word >> 30;
            word = next;
        }
        next = *p++;
    } else {
        a = word >> 30;
        word <<= 2;
        bits += 2;
    }
    SKIP_BITS(2);
    READ_BITS(3, c);
    SKIP_BITS(1);
    READ_BITS(15, e);
    SKIP_BITS(1);
    READ_BITS(15, g);
    SKIP_BITS(1);
    SKIP_BITS(1);
    READ_BITS(22, j);
    out->flag = (a == 0) ? 1 : 0;
    out->packed = (c << 28) | (e << 13) | (g >> 2);
    out->value = j;
    *kind = 12;
}
/* fzgx:end fn_12_62F8 */

/* fzgx:begin fn_12_654C */
/* --- rel/movie_module/fn_12_654C.c --- */



int fn_12_654C(MovieModule *movie, const u8 *data, int size, int *offset, int *flags) {
    int count;
    struct { int value; } processed;
    int kind;

    *offset = 0;
    *flags = 0;
    if (fn_12_6C78( (u32)(MovieModule *)(movie))) {
        return fn_12_6D5C(0, 0xff020301);
    }

    while (size >= 4) {
        processed.value = 0;
        count = 0;
        kind = fn_12_670C( (const u8 *)(const void *)(data));
        switch (kind) {
        case 0x10000:
            fn_12_62F8( (movie_bitstream_out *)(void *)(&movie->field14), (const u8 *)(const void *)(data), (u32 *)(int *)(&count));
            processed.value = 1;
            break;
        case 0x20000:
            fn_12_5FA0(&movie->values, data, &count);
            processed.value = 1;
            break;
        case 0x40000:
            fn_12_5810(&movie->fielda0, data, &count, movie->field10);
            break;
        case 0x80000:
            break;
        }
        *flags |= kind;
        data += count;
        size -= count;
        *offset += count;
        if (!processed.value)
            break;
    }

    if (*flags & 0x20000) {
        int index;
        if (movie->values.value_08 != 0)
            index = 0;
        else if (movie->values.value_0c != 0)
            index = 1;
        else
            index = 2;
        movie->slots[index] = movie->values;
    }
    return 0;
}
/* fzgx:end fn_12_654C */

/* fzgx:begin fn_12_6704 */
/* --- rel/movie_module/fn_12_6704.c --- */
/* --- rel/movie_module/fn_12_6704.c --- */
// fn_12_6704: empty in retail (single blr).
void fn_12_6704(void) {
}
/* fzgx:end fn_12_6704 */

/* fzgx:begin fn_12_6708 */
/* --- rel/movie_module/fn_12_6708.c --- */
// fn_12_6708: empty in retail (single blr).
void fn_12_6708(void) {
}
/* fzgx:end fn_12_6708 */
