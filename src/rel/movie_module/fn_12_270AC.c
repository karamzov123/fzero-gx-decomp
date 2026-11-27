#include "types.h"

/* --- rel/movie_module/fn_12_270AC.c --- */
typedef struct MovieObject {
    u8 pad_0038[0x38];
    int field_0038;
    u8 pad_003c[0x1af4];
    void *field_1b30;
    u8 pad_1b34[0x38c];
    void *field_1ec0;
} MovieObject;

extern int fn_12_2D73C(MovieObject *, int);
extern int fn_12_26D68(MovieObject *, void *);
extern void *fn_12_CF2C(void);
extern int fn_12_24A88(MovieObject *, int);
extern void fn_12_26D24(void);
extern int fn_12_A6E8(void *, void (*)(void), MovieObject *);
extern void fn_12_CBC8(void *);
extern void fn_12_CAE4(void *, int, int);

int fn_12_270AC(MovieObject *movie) {
    void *movie_data;
    void *movie_slot;
    int result;

    if (fn_12_2D73C(movie, 5) == 0) {
        return 0;
    }

    movie_data = &movie->field_1ec0;
    movie->field_1b30 = movie_data;
    result = fn_12_26D68(movie, movie_data);
    if (result != 0) {
        return result;
    }

    movie_slot = fn_12_CF2C();
    if (movie_slot == 0) {
        return fn_12_24A88(movie, (int)0xff000f0a);
    }

    if (fn_12_A6E8(movie_slot, fn_12_26D24, movie) != 0) {
        fn_12_CBC8(movie_slot);
        return fn_12_24A88(movie, (int)0xff000f0b);
    }

    fn_12_CAE4(movie_slot, 1, fn_12_2D73C(movie, 0));
    fn_12_CAE4(movie_slot, 2, fn_12_2D73C(movie, 1));
    fn_12_CAE4(movie_slot, 3, 0);
    fn_12_CAE4(movie_slot, 4, 0);
    fn_12_CAE4(movie_slot, 5, 0);
    fn_12_CAE4(movie_slot, 6, movie->field_0038);
    fn_12_CAE4(movie_slot, 7, 0x7fffffff);
    fn_12_CAE4(movie_slot, 8, 0);
    fn_12_CAE4(movie_slot, 9, 0);
    *(void **)movie_data = movie_slot;
    return 0;
}

/* --- rel/movie_module/fn_12_27224.c --- */
typedef struct Sig_fn_12_2AB68_MovieEntry {
    int used;
    u8 pad[0x74];
} Sig_fn_12_2AB68_MovieEntry;

typedef struct Sig_fn_12_2AB68_MovieList {
    u8 pad[0x134];
    int count;
    Sig_fn_12_2AB68_MovieEntry entries[1];
} Sig_fn_12_2AB68_MovieList;

typedef struct Sig_fn_12_2AB68_MovieObject {
    u8 pad[0x1b30];
    Sig_fn_12_2AB68_MovieList *list;
} Sig_fn_12_2AB68_MovieObject;

struct Sig_fn_12_2AAD4_fn_12_2AAD4_Arg0 {
    u32 unk_0;
};

struct fn_12_27224_Arg0 {
    u8 pad_0[0x1B30];
    u32 list_1b30;
};

struct fn_12_27224_Copy16 { u32 a[4]; };
struct fn_12_27224_Copy80 { u32 a[20]; };

extern Sig_fn_12_2AB68_MovieEntry * fn_12_2AB68(Sig_fn_12_2AB68_MovieObject *);
extern u32 fn_12_2AAD4(struct Sig_fn_12_2AAD4_fn_12_2AAD4_Arg0 *);

#pragma opt_common_subs off
static inline u32 fn_12_27224_operand(u32 right, u32 left) { return left * right; }
s32 fn_12_27224(struct fn_12_27224_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 list_bits;
    u32 entry_130;
    u32 self_bits;
    void *copy_dst;
    u32 row_half;
    s32 w_in;
    s32 h_in;
    s32 w_tiles;
    s32 w_align16;
    s32 h_align32;
    s32 h_tiles;
    s32 h_align16;
    s32 offset_cur;
    s32 offset_half;
    u32 table;
    u32 row_cur;
    Sig_fn_12_2AB68_MovieEntry * t0;

    list_bits = arg0->list_1b30;
    entry_130 = *(u32 *)((u8 *)list_bits + 304);
    self_bits = (u32)arg0;

    if (0 != entry_130) {
        *(u32 *)((u8 *)arg3 + 0) = entry_130;
    } else {
        t0 = (Sig_fn_12_2AB68_MovieEntry *)(fn_12_2AB68((Sig_fn_12_2AB68_MovieObject *)self_bits));
        self_bits = (u32)(t0);
        *(u32 *)((u8 *)arg3 + 0) = (u32)(self_bits);

        if (*(u32 *)((u8 *)arg3 + 0) == 0) {
            *(u32 *)((u8 *)(u32)arg0 + 2416) = 1;
            return -1;
        }
    }

    copy_dst = (void *)(((u8 *)*(u32 *)((u8 *)arg3 + 0) + 40));
    *(struct fn_12_27224_Copy80 *)copy_dst = *(struct fn_12_27224_Copy80 *)arg1;

    if (*(s32 *)((u8 *)(u32)arg0 + 56) == 3) {
        if ((s32)*(u32 *)((u8 *)arg1 + 24) == 1 || (s32)*(u32 *)((u8 *)arg1 + 24) == 2) {
            if (*(u32 *)((u8 *)list_bits + 304) == 0) {
                fn_12_2AAD4((struct Sig_fn_12_2AAD4_fn_12_2AAD4_Arg0 *)*(u32 *)((u8 *)list_bits + 296));
                *(u32 *)((u8 *)list_bits + 296) = *(u32 *)((u8 *)list_bits + 300);
                *(u32 *)((u8 *)list_bits + 300) = *(u32 *)((u8 *)arg3 + 0);
            }
        }

        w_in = (s32)*(u32 *)((u8 *)arg1 + 0);
        h_in = (s32)*(u32 *)((u8 *)arg1 + 4);
        w_tiles = (w_in + 15) / 16;
        w_align16 = w_tiles << 4;
{
        u32 w_align32;
        self_bits = ((w_align16 + 31) / 32) << 5;
        w_align32 = self_bits;
        *(s16 *)((u8 *)arg2 + 14) = w_align32;
        h_align32 = (((((w_tiles >> 27) & 0x1) + w_align16) >> 1) + 31) / 32 << 5;
        h_tiles = (h_in + 15) / 16;
        *(s16 *)((u8 *)arg2 + 12) = h_align32;
        h_align16 = h_tiles << 4;
        offset_cur = (h_align16 * w_align32);
        *(u32 *)(((8) + ((u8 *)arg2))) = *(u32 *)((u8 *)*(u32 *)((u8 *)list_bits + 296) + 4);
        *(u32 *)((u8 *)arg2 + 0) = (*(u32 *)(((8) + ((u8 *)arg2))) + offset_cur);
        offset_half = fn_12_27224_operand(h_align32, ((((h_tiles >> 27) & 0x1) + h_align16) >> 1));
        *(u32 *)((u8 *)arg2 + 4) = (*(u32 *)((u8 *)arg2 + 0) + offset_half);
        *(s16 *)((u8 *)arg2 + 30) = w_align32;
        *(s16 *)((u8 *)arg2 + 28) = h_align32;
        *(u32 *)((u8 *)arg2 + 24) = *(u32 *)((u8 *)*(u32 *)((u8 *)list_bits + 300) + 4);
        *(u32 *)((u8 *)arg2 + 16) = (*(u32 *)((u8 *)arg2 + 24) + offset_cur);
        *(u32 *)((u8 *)arg2 + 20) = (*(u32 *)((u8 *)arg2 + 16) + offset_half);
}
    } else {
        if ((s32)*(u32 *)((u8 *)arg1 + 24) == 1 || (s32)*(u32 *)((u8 *)arg1 + 24) == 2) {
            *(u32 *)((u8 *)list_bits + 256) = (*(u32 *)((u8 *)list_bits + 256) ^ 1);
            *(u32 *)((u8 *)list_bits + 260) = (*(u32 *)((u8 *)list_bits + 260) ^ 1);
        }

        table = (264 + list_bits);
        row_cur = (table + (*(u32 *)((u8 *)list_bits + 256) << 4));
        *(struct fn_12_27224_Copy16 *)arg2 = *(struct fn_12_27224_Copy16 *)row_cur;
        row_half = (table + (*(u32 *)((u8 *)list_bits + 260) << 4));
        *(struct fn_12_27224_Copy16 *)((u8 *)arg2 + 16) = *(struct fn_12_27224_Copy16 *)row_half;
    }

    *(u32 *)((u8 *)arg2 + 32) = *(u32 *)((u8 *)*(u32 *)((u8 *)arg3 + 0) + 4);
    *(u32 *)((u8 *)arg2 + 36) = (*(u32 *)((u8 *)arg3 + 0) + 40);
    *(u32 *)((u8 *)arg2 + 40) = 0;
    *(u32 *)((u8 *)arg2 + 44) = 0;
    *(u32 *)((u8 *)(u32)arg0 + 2416) = 0;
    return 0;
}

#pragma opt_common_subs reset
