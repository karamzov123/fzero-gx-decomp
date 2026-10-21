#include "types.h"

struct fn_12_5810_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0xC];
    u32 unk_1C;
};

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

void fn_12_5810(struct fn_12_5810_Arg0 *arg0, const void *arg1, int *arg2, int arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7) {
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
