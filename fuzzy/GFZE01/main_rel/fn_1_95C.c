/* Non-matching: best partial attempt (60.59% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern s32 fn_1_15C35C(s32, s32, s32, s32);
extern size_t strlen(const char *);
extern u32 OSGetArenaHi(void);
extern u32 fn_1_12B88(void *, u32, u32);
extern u32 fn_800075AC(u32, u32, u32);
extern char lbl_1_data_45C[3];
extern void DCFlushRange(void *, u32);
extern void OSSetArenaHi(u32);
extern void fn_80006E10(u32);
extern void fn_800074C4(u32, u32, u32, u32, u32, u32);
extern void fn_80008BEC(void *, int, u32);

static u32 rev(u32 x) {
    return (x << 24) | ((x & 0x0000FF00) << 8) |
           ((x & 0x00FF0000) >> 8) | (x >> 24);
}

static void copy_words(u32 *dst, u32 *src) {
    s32 i;
    for (i = 0; i < 18; i++) dst[i] = rev(src[i]);
}

void fn_1_95C(void) {
    struct { u8 a[55]; } loc_9;
    u8 loc_8;
    u32 heap_size, arena_hi, arena;
    u32 *text;
    u32 *matrix;
    u32 *src;
    u32 *dst;
    u32 count, i, j;
    u32 p, q;
    s32 n;

    loc_8 = 103;
    fn_80008BEC(&loc_9, 97, 10);
    loc_9.a[3] = 0;
    loc_9.a[1] += 12;
    loc_9.a[2] += 4;
    fn_80006E10((u32)&loc_8);

    loc_8 -= 4;
    loc_9.a[1] += 5;
    loc_9.a[2] -= 1;
    loc_9.a[3] += 97;
    loc_9.a[4] += 19;
    loc_9.a[6] -= 51;
    loc_9.a[7] += 11;
    loc_9.a[8] += 25;
    loc_9.a[9] = 0;

    heap_size = fn_1_15C35C(60, 400, 0, 576);
    arena_hi = OSGetArenaHi();
    arena = (arena_hi - heap_size) & ~0xFFF;
    if (fn_1_12B88(&loc_8, arena, arena - 8192) != 0) {
        OSSetArenaHi(arena);
        fn_80008BEC(&loc_8, 0, 12);

        text = (u32 *)fn_1_15C35C(60, 400, 0, 576);
        matrix = (u32 *)fn_1_15C35C(224, 0x280000, (s32)0xFF953892,
                                  (s32)0x00153892);
        fn_800074C4((u32)matrix, arena, (u32)text, 0, 0, 3);
        text = (u32 *)fn_1_15C35C(458, 0x140000, 0x645892, 0x1C5892);

        p = (u32)text + 0x1CE0;
        q = 0;
        n = 0;
        do {
            s32 size = fn_1_15C35C(3, 8, 4, 20);
            dst = (u32 *)(arena + n);
            src = (u32 *)((u32)dst + (u32)(size * 180) - n);
            copy_words(dst, src);
            *(u32 *)dst = p;
            p += (u32)strlen((char *)p) + 1;
            n += 180;
            q++;
        } while (q < (u32)fn_1_15C35C(10, 8, 54, 15));

        text = (u32 *)fn_1_15C35C(458, 0x140000, 0x645892, 0x1C5892);
        matrix = (u32 *)((u32)text + 0x53C0);
        for (i = 0; i < 3; i++) {
            u32 num = fn_1_15C35C(6, 2, i + 7, i + 20);
            u32 base = arena + 0x1F04 + i * num * 180;
            for (j = 0; j < (u32)fn_1_15C35C(2, 6, 7, 20); j++) {
                s32 k = fn_1_15C35C(10, 3, 8, 2);
                dst = (u32 *)(base + k * 180);
                src = (u32 *)((u32)dst - j * 180);
                copy_words(dst, src);
                *dst = (u32)matrix;
                j += 0;
            }
        }
        p = fn_1_15C35C(60, 400, 0, 576);
        DCFlushRange((void *)arena, p);
        p = fn_1_15C35C(60, 400, 0, 576);
        fn_800075AC(arena, p, 1);
    }
    fn_80006E10((u32)lbl_1_data_45C);
}
