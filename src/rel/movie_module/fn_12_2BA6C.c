#include "types.h"


/* --- rel/movie_module/fn_12_2BA6C.c --- */
struct MovieModule {
    char pad_94c[0x94c];
    int value_94c;
};

typedef void (*MovieCallback)(struct MovieModule *, void *, int *);

extern MovieCallback fn_12_2D73C(struct MovieModule *, int);

void fn_12_2BA6C(struct MovieModule *module, int delta, void *arg) {
    int *value = &module->value_94c;
    MovieCallback callback;

    *value += delta;
    callback = fn_12_2D73C(module, 0x24);
    if (callback != 0) {
        callback(module, arg, value);
    }
}

/* --- rel/movie_module/fn_12_2BAE0.c --- */
typedef struct Sig_fn_12_248E8_MovieModule {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u8 pad_10[0x80];
    u32 unk_90;
} Sig_fn_12_248E8_MovieModule;

struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

typedef struct Sig_fn_12_2D450_MovieModuleState {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
} Sig_fn_12_2D450_MovieModuleState;

typedef int (*Sig_fn_12_2F264_MovieHandler)(struct Sig_fn_12_2F264_Movie *, int, int, int);

struct Sig_fn_12_2F264_MovieItem {
    char pad0[0xc];
    Sig_fn_12_2F264_MovieHandler *handlers;
    char pad1[0x30];
    char pad2[4];
};

struct Sig_fn_12_2F264_Movie;
struct Sig_fn_12_2F264_Movie {
    char pad0[0x1aa0];
    struct Sig_fn_12_2F264_MovieItem items[1];
};

struct fn_12_2BAE0_Arg0 {
    u8 pad_0[0x3C];
    u32 unk_3C;
    u32 unk_40;
};
extern u32 lbl_12_bss_7C64;
extern void fn_12_33428(u32 *, u32, u32);
extern void fn_12_248E8(Sig_fn_12_248E8_MovieModule *);
extern void fn_12_2FE30(struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 *);
extern void fn_12_24B64(int *);
extern void * fn_12_57F0(void *, const void *, u32);
extern void fn_12_2D450(Sig_fn_12_2D450_MovieModuleState *);
extern int fn_12_2F264(struct Sig_fn_12_2F264_Movie *, int);

struct FzgxCopy_68 { u32 words[17]; };
s32 fn_12_22954(s32, s32, void *);                  /* extern */
s32 fn_12_2EE7C(s32, s32);                      /* extern */
s32 fn_12_2F63C(s32, s32, void *, s32);         /* extern */

s32 fn_12_2BAE0(void *arg0, s32 arg1) {
    s32 temp_r31;
    s32 var_r28;
    struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 *var_r27;
    u32 *temp_r27;

    temp_r27 = (u32 *)(*(u32 **)((u8 *)(arg0) + 60));
    fn_12_33428((u32 *)(temp_r27), (u32)(0U), (u32)((u32) (*(u32 *)((u8 *)(arg0) + 64)) >> 2U));
    temp_r31 = ((s32)(((u8 *)(temp_r27) + 0x1F))) & 0xFFFFFFE0;
    (*(s32 *)((u8 *)(temp_r31) + 76)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 72)) = 0;
    (*(s32 *)((u8 *)(arg0) + 4)) = (s32) (((*(s32 *)((u8 *)(arg0) + 4)) + 0x1F) & 0xFFFFFFE0);
    *(struct FzgxCopy_68 *)(temp_r31) = *(const struct FzgxCopy_68 *)(arg0);
    (*(s32 *)((u8 *)(temp_r31) + 68)) = 1;
    (*(s32 *)((u8 *)(temp_r31) + 80)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 84)) = 0;
    fn_12_248E8((Sig_fn_12_248E8_MovieModule *)(temp_r31 + 0x78));
    fn_12_33428((u32 *)(temp_r31 + 0x90C), (u32)(0U), (u32)(0x10U));
    (*(s32 *)((u8 *)(temp_r31) + 2316)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2320)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2324)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2328)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2332)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2336)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2340)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2344)) = 1;
    (*(s32 *)((u8 *)(temp_r31) + 2348)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2352)) = -1;
    (*(s32 *)((u8 *)(temp_r31) + 2356)) = -1;
    (*(s32 *)((u8 *)(temp_r31) + 2360)) = -1;
    fn_12_33428((u32 *)(temp_r31 + 0x94C), (u32)(0U), (u32)(0x10U));
    (*(s32 *)((u8 *)(temp_r31) + 2380)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2384)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2388)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2392)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2396)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2400)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2404)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2408)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2412)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2416)) = 0;
    fn_12_33428((u32 *)(temp_r31 + 0x2918), (u32)(0U), (u32)(0x30U));
    var_r28 = 0;
    var_r27 = (struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 *)(temp_r31 + 0x2918);
    do {
        fn_12_2FE30((struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 *)(var_r27));
        var_r28 += 1;
        var_r27 = (struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 *)((u8 *)(var_r27) + 0x20);
    } while (var_r28 < 5);
    fn_12_2FE30((struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 *)(temp_r31 + 0x29B8));
    fn_12_24B64((int *)(temp_r31 + 0x98C));
    fn_12_57F0((void *)(temp_r31 + 0x9A0), (const void *)(&lbl_12_bss_7C64), (u32)(0x190U));
    fn_12_57F0((void *)(temp_r31 + 0xB30), (const void *)(&lbl_12_bss_7C64), (u32)(0x190U));
    fn_12_2EE7C((s32)(temp_r31), (s32)(temp_r31 + 0xCC0));
    if (fn_12_22954((s32)(temp_r31), (s32)(temp_r31 + 0x1140), (void *)(arg0)) != 0) {
        return 0;
    }
    fn_12_2F63C((s32)(temp_r31), (s32)(temp_r31 + 0x1AA0), (void *)(arg0), (s32)(arg1));
    fn_12_2D450((Sig_fn_12_2D450_MovieModuleState *)(temp_r31 + 0x2908));
    if (fn_12_2F264((struct Sig_fn_12_2F264_Movie *)((struct Sig_fn_12_2F264_Movie *)(temp_r31)), (s32)(3)) != 0) {
        return 0;
    }
    (*(s32 *)((u8 *)(temp_r31) + 76)) = 1;
    (*(s32 *)((u8 *)(temp_r31) + 72)) = 1;
    return temp_r31;
}
