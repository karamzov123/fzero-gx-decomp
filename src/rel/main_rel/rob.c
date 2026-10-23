#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/rob.h"

extern void fn_1_12ABB4(void *arg0);
extern void fn_1_96230(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_41850(void *arg0);
extern u32 lbl_1_bss_6E98C;
extern u16 fn_1_96B14(void *base, void *arg1, s32 index);
extern s32 fn_80083BCC(void *arg0, void *arg1);
extern void ADXT_Stop(u32 arg0);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern void fn_80008BEC(void *, u32, u32);

extern const char *lbl_1_data_20D1C[];
extern void sprintf(char *buffer, u8 *format, ...);
extern s32 fn_1_12A32C(char *buffer);
extern s16 fn_1_98104(void);

/* fzgx:begin fn_1_95EF0 noprologue */
#include "types.h"

struct fn_1_95EF0_Arg0 {
    u8 pad_0[0x14C];
    u32 unk_14C;
};
struct fn_1_95EF0_lbl_801A6410 {
    u32 unk_0;
};
extern struct fn_1_95EF0_lbl_801A6410 lbl_801A6410;
extern u8 lbl_1_data_27C00[];
extern void fn_1_12ABB4(void *);
extern void fn_1_46B4(u32, u32, const char *, int);

void fn_1_95EF0(void *arg0, s32 arg_sp0) {
    void *var_r28;
    void *temp_r3_7;
    void *temp_r3_6;
    void *temp_r3_5;
    void *temp_r3_4;
    void *temp_r3_3;
    void *temp_r3_2;
    void *temp_r3;
    u32 var_r27;
    u32 temp_r4_7;
    u32 temp_r4_6;
    u32 temp_r4_5;
    u32 temp_r4_4;
    u32 temp_r4_3;
    u32 temp_r4_2;
    u32 temp_r4;

    temp_r3 = (void *)(*(void **)((u8 *)(arg0) + 332));
    if (temp_r3 != NULL) {
        fn_1_12ABB4((void *)(temp_r3));
        (*(void **)((u8 *)(arg0) + 332)) = (void *)(NULL);
    }
    temp_r4 = *(u32 *)((u8 *)(arg0) + 336);
    if (temp_r4 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4, (const char *)((s8 *) lbl_1_data_27C00), 0xB44);
        (*(u32 *)((u8 *)(arg0) + 336)) = 0U;
    }
    temp_r3_2 = (void *)(*(void **)((u8 *)(arg0) + 364));
    if (temp_r3_2 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_2));
        (*(void **)((u8 *)(arg0) + 364)) = (void *)(NULL);
    }
    temp_r4_2 = *(u32 *)((u8 *)(arg0) + 368);
    if (temp_r4_2 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_2, (const char *)((s8 *) lbl_1_data_27C00), 0xB49);
        (*(u32 *)((u8 *)(arg0) + 368)) = 0U;
    }
    temp_r3_3 = (void *)(*(void **)((u8 *)(arg0) + 396));
    if (temp_r3_3 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_3));
        (*(void **)((u8 *)(arg0) + 396)) = (void *)(NULL);
    }
    temp_r4_3 = *(u32 *)((u8 *)(arg0) + 400);
    if (temp_r4_3 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_3, (const char *)((s8 *) lbl_1_data_27C00), 0xB4B);
        (*(u32 *)((u8 *)(arg0) + 400)) = 0U;
    }
    temp_r3_4 = (void *)(*(void **)((u8 *)(arg0) + 428));
    if (temp_r3_4 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_4));
        (*(void **)((u8 *)(arg0) + 428)) = (void *)(NULL);
    }
    temp_r4_4 = *(u32 *)((u8 *)(arg0) + 432);
    if (temp_r4_4 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_4, (const char *)((s8 *) lbl_1_data_27C00), 0xB4D);
        (*(u32 *)((u8 *)(arg0) + 432)) = 0U;
    }
    temp_r3_5 = (void *)(*(void **)((u8 *)(arg0) + 460));
    if (temp_r3_5 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_5));
        (*(void **)((u8 *)(arg0) + 460)) = (void *)(NULL);
    }
    temp_r4_5 = *(u32 *)((u8 *)(arg0) + 464);
    if (temp_r4_5 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_5, (const char *)((s8 *) lbl_1_data_27C00), 0xB4F);
        (*(u32 *)((u8 *)(arg0) + 464)) = 0U;
    }
    temp_r3_6 = (void *)(*(void **)((u8 *)(arg0) + 492));
    if (temp_r3_6 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_6));
        (*(void **)((u8 *)(arg0) + 492)) = (void *)(NULL);
    }
    temp_r4_6 = *(u32 *)((u8 *)(arg0) + 496);
    if (temp_r4_6 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_6, (const char *)((s8 *) lbl_1_data_27C00), 0xB51);
        (*(u32 *)((u8 *)(arg0) + 496)) = 0U;
    }
    var_r28 = (void *)(arg0);
    var_r27 = 0U;
    do {
        temp_r3_7 = (void *)(*(void **)((u8 *)(var_r28) + 524));
        if (temp_r3_7 != NULL) {
            fn_1_12ABB4((void *)(temp_r3_7));
            (*(void **)((u8 *)(var_r28) + 524)) = (void *)(NULL);
        }
        temp_r4_7 = *(u32 *)((u8 *)(var_r28) + 528);
        if (temp_r4_7 != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, temp_r4_7, (const char *)((s8 *) lbl_1_data_27C00), 0xB54);
            (*(u32 *)((u8 *)(var_r28) + 528)) = 0U;
        }
        var_r27 += 1;
        var_r28 = (void *)((u8 *)(var_r28) + 0x20);
    } while (var_r27 < 0x14U);
}
/* fzgx:end fn_1_95EF0 */

/* fzgx:begin fn_1_961F0 */
typedef struct Fn1961F0Owner Fn1961F0Owner;

struct Fn1961F0Owner {
    u8 unk_00[0x0C];
    void *resource;
};

void fn_1_961F0(Fn1961F0Owner *owner) {
    if (owner->resource != 0) {
        fn_1_12ABB4(owner->resource);
        owner->resource = 0;
    }
}
/* fzgx:end fn_1_961F0 */

/* fzgx:begin fn_1_96230 noprologue */
#include "types.h"

typedef struct Fn196230Obj {
    u8 unk_00[0x4];
    s32 ids[5];
    u8 unk_18[0xE4 - 0x18];
    u32 handles[5];
    void *files[5][4];
} Fn196230Obj;

typedef struct Fn196230Data {
    u8 pad_0[0x35C];
    const char *names[(0x6ED8 - 0x35C) / 4];
    u8 lock_6ED8[8];
    char fmt_6EE0[0xC];
    u8 unlock_6EEC[0x7278 - 0x6EEC];
    char fmt_7278[0xC];
    char fmt_7284[4];
} Fn196230Data;

extern Fn196230Data lbl_1_data_209C0;

static const char *const fzgx_pool_sDirs[5] = {0};
static const char *const fzgx_pool_sPacks[5] = {0};
static const char *const fzgx_pool_sExts[4] = {0};

extern void fn_1_12AB38(void *);
extern s32 fn_1_465D0(char *, s32);
extern void fn_1_12A2B8(u32);
extern void fn_1_12A2D0(s32);
extern void *fn_1_12AC00(char *);
extern u32 fn_1_12ADA0(char *, void *);
extern int sprintf(char *, const char *, ...);

/* bit n of a mask counted from the most significant bit */
#define MASK_BIT(mask, n) __rlwnm((mask), ((n) + 1) & 0x1F, 31, 31)

extern u8 fn_1_9012C__fzgx_offset_3D4[];
extern u8 fn_1_9012C__fzgx_offset_40C[];
extern u8 fn_1_9012C__fzgx_offset_440[];
extern u8 fn_1_9012C__fzgx_offset_468[];
extern u8 fn_1_9012C__fzgx_offset_488[];
extern u8 fn_1_9012C__fzgx_offset_4A8[];
extern u8 fn_1_9012C__fzgx_offset_4FC[];
extern u8 fn_1_9012C__fzgx_offset_53C[];
extern u8 fn_1_9012C__fzgx_offset_5B0[];
extern u8 fn_1_9012C__fzgx_offset_624[];
extern u8 fn_1_9012C__fzgx_offset_698[];
extern u8 fn_1_9012C__fzgx_offset_70C[];
extern u8 fn_1_9012C__fzgx_offset_780[];
extern u8 fn_1_9012C__fzgx_offset_7EC[];
extern u8 lbl_1_bss_6E990__fzgx_offset_0[];
extern u8 lbl_1_data_209C0__fzgx_offset_0[];
extern u8 lbl_1_data_209C8__fzgx_offset_0[];
extern u8 lbl_1_data_209D0__fzgx_offset_0[];
extern u8 lbl_1_data_209D8__fzgx_offset_0[];
extern u8 lbl_1_data_209E0__fzgx_offset_0[];
extern u8 lbl_1_data_209E8__fzgx_offset_0[];
extern u8 lbl_1_data_209F0__fzgx_offset_0[];
extern u8 lbl_1_data_209F8__fzgx_offset_0[];
extern u8 lbl_1_data_20A00__fzgx_offset_0[];
extern u8 lbl_1_data_20A04__fzgx_offset_0[];
extern u8 lbl_1_data_20A0C__fzgx_offset_0[];
extern u8 lbl_1_data_20A14__fzgx_offset_0[];
extern u8 lbl_1_data_20A1C__fzgx_offset_0[];
extern u8 lbl_1_data_20A24__fzgx_offset_0[];
extern u8 lbl_1_data_20A2C__fzgx_offset_0[];
extern u8 lbl_1_data_20A30__fzgx_offset_0[];
extern u8 lbl_1_data_20A38__fzgx_offset_0[];
extern u8 lbl_1_data_20A40__fzgx_offset_0[];
extern u8 lbl_1_data_20A4C__fzgx_offset_0[];
extern u8 lbl_1_data_20A54__fzgx_offset_0[];
extern u8 lbl_1_data_20A5C__fzgx_offset_0[];
extern u8 lbl_1_data_20A60__fzgx_offset_0[];
extern u8 lbl_1_data_20A68__fzgx_offset_0[];
extern u8 lbl_1_data_20A70__fzgx_offset_0[];
extern u8 lbl_1_data_20A78__fzgx_offset_0[];
extern u8 lbl_1_data_20A80__fzgx_offset_0[];
extern u8 lbl_1_data_20A88__fzgx_offset_0[];
extern u8 lbl_1_data_20A90__fzgx_offset_0[];
extern u8 lbl_1_data_20A98__fzgx_offset_0[];
extern u8 lbl_1_data_20AA0__fzgx_offset_0[];
extern u8 lbl_1_data_20AA8__fzgx_offset_0[];
extern u8 lbl_1_data_20AB0__fzgx_offset_0[];
extern u8 lbl_1_data_20AB4__fzgx_offset_0[];
extern u8 lbl_1_data_20ABC__fzgx_offset_0[];
extern u8 lbl_1_data_20AC0__fzgx_offset_0[];
extern u8 lbl_1_data_20AC8__fzgx_offset_0[];
extern u8 lbl_1_data_20AD4__fzgx_offset_0[];
extern u8 lbl_1_data_20ADC__fzgx_offset_0[];
extern u8 lbl_1_data_20AE4__fzgx_offset_0[];
extern u8 lbl_1_data_20AE8__fzgx_offset_0[];
extern u8 lbl_1_data_20AEC__fzgx_offset_0[];
extern u8 lbl_1_data_20AF8__fzgx_offset_0[];
extern u8 lbl_1_data_20B00__fzgx_offset_0[];
extern u8 lbl_1_data_20B04__fzgx_offset_0[];
extern u8 lbl_1_data_20B08__fzgx_offset_0[];
extern u8 lbl_1_data_20BC8__fzgx_offset_0[];
extern u8 lbl_1_data_20BD0__fzgx_offset_0[];
extern u8 lbl_1_data_20BD8__fzgx_offset_0[];
extern u8 lbl_1_data_20BE0__fzgx_offset_0[];
extern u8 lbl_1_data_20BE8__fzgx_offset_0[];
extern u8 lbl_1_data_20BF0__fzgx_offset_0[];
extern u8 lbl_1_data_20BF8__fzgx_offset_0[];
extern u8 lbl_1_data_20C00__fzgx_offset_0[];
extern u8 lbl_1_data_20C08__fzgx_offset_0[];
extern u8 lbl_1_data_20C0C__fzgx_offset_0[];
extern u8 lbl_1_data_20C14__fzgx_offset_0[];
extern u8 lbl_1_data_20C1C__fzgx_offset_0[];
extern u8 lbl_1_data_20C24__fzgx_offset_0[];
extern u8 lbl_1_data_20C2C__fzgx_offset_0[];
extern u8 lbl_1_data_20C34__fzgx_offset_0[];
extern u8 lbl_1_data_20C38__fzgx_offset_0[];
extern u8 lbl_1_data_20C40__fzgx_offset_0[];
extern u8 lbl_1_data_20C48__fzgx_offset_0[];
extern u8 lbl_1_data_20C54__fzgx_offset_0[];
extern u8 lbl_1_data_20C5C__fzgx_offset_0[];
extern u8 lbl_1_data_20C64__fzgx_offset_0[];
extern u8 lbl_1_data_20C68__fzgx_offset_0[];
extern u8 lbl_1_data_20C70__fzgx_offset_0[];
extern u8 lbl_1_data_20C78__fzgx_offset_0[];
extern u8 lbl_1_data_20C80__fzgx_offset_0[];
extern u8 lbl_1_data_20C88__fzgx_offset_0[];
extern u8 lbl_1_data_20C90__fzgx_offset_0[];
extern u8 lbl_1_data_20C98__fzgx_offset_0[];
extern u8 lbl_1_data_20CA0__fzgx_offset_0[];
extern u8 lbl_1_data_20CA8__fzgx_offset_0[];
extern u8 lbl_1_data_20CB0__fzgx_offset_0[];
extern u8 lbl_1_data_20CB8__fzgx_offset_0[];
extern u8 lbl_1_data_20CBC__fzgx_offset_0[];
extern u8 lbl_1_data_20CC4__fzgx_offset_0[];
extern u8 lbl_1_data_20CC8__fzgx_offset_0[];
extern u8 lbl_1_data_20CD0__fzgx_offset_0[];
extern u8 lbl_1_data_20CDC__fzgx_offset_0[];
extern u8 lbl_1_data_20CE4__fzgx_offset_0[];
extern u8 lbl_1_data_20CEC__fzgx_offset_0[];
extern u8 lbl_1_data_20CF0__fzgx_offset_0[];
extern u8 lbl_1_data_20CF4__fzgx_offset_0[];
extern u8 lbl_1_data_20D00__fzgx_offset_0[];
extern u8 lbl_1_data_20D08__fzgx_offset_0[];
extern u8 lbl_1_data_20D0C__fzgx_offset_0[];
extern u8 lbl_1_data_20D10__fzgx_offset_0[];
extern u8 lbl_1_data_20DD0__fzgx_offset_0[];
extern u8 lbl_1_data_20DE4__fzgx_offset_0[];
extern u8 lbl_1_data_20DF4__fzgx_offset_0[];
extern u8 lbl_1_data_20E0C__fzgx_offset_0[];
extern u8 lbl_1_data_20E14__fzgx_offset_0[];
extern u8 lbl_1_data_20E24__fzgx_offset_0[];
extern u8 lbl_1_data_20E2C__fzgx_offset_0[];
extern u8 lbl_1_data_20E44__fzgx_offset_0[];
extern u8 lbl_1_data_20E50__fzgx_offset_0[];
extern u8 lbl_1_data_20E6C__fzgx_offset_0[];
extern u8 lbl_1_data_20E84__fzgx_offset_0[];
extern u8 lbl_1_data_20E8C__fzgx_offset_0[];
extern u8 lbl_1_data_20E9C__fzgx_offset_0[];
extern u8 lbl_1_data_20EA4__fzgx_offset_0[];
extern u8 lbl_1_data_20EB4__fzgx_offset_0[];
extern u8 lbl_1_data_20EC4__fzgx_offset_0[];
extern u8 lbl_1_data_20ED0__fzgx_offset_0[];
extern u8 lbl_1_data_20EE4__fzgx_offset_0[];
extern u8 lbl_1_data_20EF4__fzgx_offset_0[];
extern u8 lbl_1_data_20EFC__fzgx_offset_0[];
extern u8 lbl_1_data_20F0C__fzgx_offset_0[];
extern u8 lbl_1_data_20F1C__fzgx_offset_0[];
extern u8 lbl_1_data_20F2C__fzgx_offset_0[];
extern u8 lbl_1_data_20F40__fzgx_offset_0[];
extern u8 lbl_1_data_20F54__fzgx_offset_0[];
extern u8 lbl_1_data_20F68__fzgx_offset_0[];
extern u8 lbl_1_data_20F78__fzgx_offset_0[];
extern u8 lbl_1_data_20F80__fzgx_offset_0[];
extern u8 lbl_1_data_20F94__fzgx_offset_0[];
extern u8 lbl_1_data_20FA8__fzgx_offset_0[];
extern u8 lbl_1_data_20FBC__fzgx_offset_0[];
extern u8 lbl_1_data_20FC8__fzgx_offset_0[];
extern u8 lbl_1_data_20FD8__fzgx_offset_0[];
extern u8 lbl_1_data_20FE4__fzgx_offset_0[];
extern u8 lbl_1_data_20FF8__fzgx_offset_0[];
extern u8 lbl_1_data_21004__fzgx_offset_0[];
extern u8 lbl_1_data_21010__fzgx_offset_0[];
extern u8 lbl_1_data_2101C__fzgx_offset_0[];
extern u8 lbl_1_data_21024__fzgx_offset_0[];
extern u8 lbl_1_data_21030__fzgx_offset_0[];
extern u8 lbl_1_data_21040__fzgx_offset_0[];
extern u8 lbl_1_data_21050__fzgx_offset_0[];
extern u8 lbl_1_data_21058__fzgx_offset_0[];
extern u8 lbl_1_data_21060__fzgx_offset_0[];
extern u8 lbl_1_data_21068__fzgx_offset_0[];
extern u8 lbl_1_data_2112C__fzgx_offset_0[];
extern u8 lbl_1_data_2113C__fzgx_offset_0[];
extern u8 lbl_1_data_21148__fzgx_offset_0[];
extern u8 lbl_1_data_21154__fzgx_offset_0[];
extern u8 lbl_1_data_21164__fzgx_offset_0[];
extern u8 lbl_1_data_21174__fzgx_offset_0[];
extern u8 lbl_1_data_2117C__fzgx_offset_0[];
extern u8 lbl_1_data_21184__fzgx_offset_0[];
extern u8 lbl_1_data_21194__fzgx_offset_0[];
extern u8 lbl_1_data_211A0__fzgx_offset_0[];
extern u8 lbl_1_data_211AC__fzgx_offset_0[];
extern u8 lbl_1_data_211B4__fzgx_offset_0[];
extern u8 lbl_1_data_211C0__fzgx_offset_0[];
extern u8 lbl_1_data_211D0__fzgx_offset_0[];
extern u8 lbl_1_data_211DC__fzgx_offset_0[];
extern u8 lbl_1_data_211E8__fzgx_offset_0[];
extern u8 lbl_1_data_211F8__fzgx_offset_0[];
extern u8 lbl_1_data_21208__fzgx_offset_0[];
extern u8 lbl_1_data_21218__fzgx_offset_0[];
extern u8 lbl_1_data_21228__fzgx_offset_0[];
extern u8 lbl_1_data_21234__fzgx_offset_0[];
extern u8 lbl_1_data_21244__fzgx_offset_0[];
extern u8 lbl_1_data_21250__fzgx_offset_0[];
extern u8 lbl_1_data_21260__fzgx_offset_0[];
extern u8 lbl_1_data_2126C__fzgx_offset_0[];
extern u8 lbl_1_data_21278__fzgx_offset_0[];
extern u8 lbl_1_data_21284__fzgx_offset_0[];
extern u8 lbl_1_data_21290__fzgx_offset_0[];
extern u8 lbl_1_data_21298__fzgx_offset_0[];
extern u8 lbl_1_data_212A0__fzgx_offset_0[];
extern u8 lbl_1_data_2135C__fzgx_offset_0[];
extern u8 lbl_1_data_21384__fzgx_offset_0[];
extern u8 lbl_1_data_213A0__fzgx_offset_0[];
extern u8 lbl_1_data_213B0__fzgx_offset_0[];
extern u8 lbl_1_data_213C4__fzgx_offset_0[];
extern u8 lbl_1_data_213D4__fzgx_offset_0[];
extern u8 lbl_1_data_213E4__fzgx_offset_0[];
extern u8 lbl_1_data_213EC__fzgx_offset_0[];
extern u8 lbl_1_data_21414__fzgx_offset_0[];
extern u8 lbl_1_data_21434__fzgx_offset_0[];
extern u8 lbl_1_data_21444__fzgx_offset_0[];
extern u8 lbl_1_data_21454__fzgx_offset_0[];
extern u8 lbl_1_data_21464__fzgx_offset_0[];
extern u8 lbl_1_data_2146C__fzgx_offset_0[];
extern u8 lbl_1_data_21494__fzgx_offset_0[];
extern u8 lbl_1_data_214B4__fzgx_offset_0[];
extern u8 lbl_1_data_214C4__fzgx_offset_0[];
extern u8 lbl_1_data_214D4__fzgx_offset_0[];
extern u8 lbl_1_data_214E4__fzgx_offset_0[];
extern u8 lbl_1_data_214EC__fzgx_offset_0[];
extern u8 lbl_1_data_21514__fzgx_offset_0[];
extern u8 lbl_1_data_2153C__fzgx_offset_0[];
extern u8 lbl_1_data_2154C__fzgx_offset_0[];
extern u8 lbl_1_data_2155C__fzgx_offset_0[];
extern u8 lbl_1_data_2156C__fzgx_offset_0[];
extern u8 lbl_1_data_21574__fzgx_offset_0[];
extern u8 lbl_1_data_2159C__fzgx_offset_0[];
extern u8 lbl_1_data_215B8__fzgx_offset_0[];
extern u8 lbl_1_data_215C8__fzgx_offset_0[];
extern u8 lbl_1_data_215D8__fzgx_offset_0[];
extern u8 lbl_1_data_215E8__fzgx_offset_0[];
extern u8 lbl_1_data_215F0__fzgx_offset_0[];
extern u8 lbl_1_data_21618__fzgx_offset_0[];
extern u8 lbl_1_data_21628__fzgx_offset_0[];
extern u8 lbl_1_data_21638__fzgx_offset_0[];
extern u8 lbl_1_data_21648__fzgx_offset_0[];
extern u8 lbl_1_data_21658__fzgx_offset_0[];
extern u8 lbl_1_data_21660__fzgx_offset_0[];
extern u8 lbl_1_data_216A8__fzgx_offset_0[];
extern u8 lbl_1_data_216C0__fzgx_offset_0[];
extern u8 lbl_1_data_216D0__fzgx_offset_0[];
extern u8 lbl_1_data_216E4__fzgx_offset_0[];
extern u8 lbl_1_data_216F8__fzgx_offset_0[];
extern u8 lbl_1_data_21700__fzgx_offset_0[];
extern u8 lbl_1_data_21728__fzgx_offset_0[];
extern u8 lbl_1_data_2174C__fzgx_offset_0[];
extern u8 lbl_1_data_2175C__fzgx_offset_0[];
extern u8 lbl_1_data_2176C__fzgx_offset_0[];
extern u8 lbl_1_data_2177C__fzgx_offset_0[];
extern u8 lbl_1_data_2178C__fzgx_offset_0[];
extern u8 lbl_1_data_21798__fzgx_offset_0[];
extern u8 lbl_1_data_217C0__fzgx_offset_0[];
extern u8 lbl_1_data_217E8__fzgx_offset_0[];
extern u8 lbl_1_data_217F8__fzgx_offset_0[];
extern u8 lbl_1_data_217FC__fzgx_offset_0[];
extern u8 lbl_1_data_21810__fzgx_offset_0[];
extern u8 lbl_1_data_21824__fzgx_offset_0[];
extern u8 lbl_1_data_21830__fzgx_offset_0[];
extern u8 lbl_1_data_21860__fzgx_offset_0[];
extern u8 lbl_1_data_21878__fzgx_offset_0[];
extern u8 lbl_1_data_21888__fzgx_offset_0[];
extern u8 lbl_1_data_2189C__fzgx_offset_0[];
extern u8 lbl_1_data_218B0__fzgx_offset_0[];
extern u8 lbl_1_data_218B8__fzgx_offset_0[];
extern u8 lbl_1_data_218D8__fzgx_offset_0[];
extern u8 lbl_1_data_21900__fzgx_offset_0[];
extern u8 lbl_1_data_21910__fzgx_offset_0[];
extern u8 lbl_1_data_21914__fzgx_offset_0[];
extern u8 lbl_1_data_21924__fzgx_offset_0[];
extern u8 lbl_1_data_21934__fzgx_offset_0[];
extern u8 lbl_1_data_2193C__fzgx_offset_0[];
extern u8 lbl_1_data_21964__fzgx_offset_0[];
extern u8 lbl_1_data_21980__fzgx_offset_0[];
extern u8 lbl_1_data_21990__fzgx_offset_0[];
extern u8 lbl_1_data_219A4__fzgx_offset_0[];
extern u8 lbl_1_data_219B8__fzgx_offset_0[];
extern u8 lbl_1_data_219C0__fzgx_offset_0[];
extern u8 lbl_1_data_219E8__fzgx_offset_0[];
extern u8 lbl_1_data_21A04__fzgx_offset_0[];
extern u8 lbl_1_data_21A14__fzgx_offset_0[];
extern u8 lbl_1_data_21A24__fzgx_offset_0[];
extern u8 lbl_1_data_21A34__fzgx_offset_0[];
extern u8 lbl_1_data_21A3C__fzgx_offset_0[];
extern u8 lbl_1_data_21A64__fzgx_offset_0[];
extern u8 lbl_1_data_21A80__fzgx_offset_0[];
extern u8 lbl_1_data_21A90__fzgx_offset_0[];
extern u8 lbl_1_data_21AA0__fzgx_offset_0[];
extern u8 lbl_1_data_21AB0__fzgx_offset_0[];
extern u8 lbl_1_data_21AB8__fzgx_offset_0[];
extern u8 lbl_1_data_21AD8__fzgx_offset_0[];
extern u8 lbl_1_data_21ADC__fzgx_offset_0[];
extern u8 lbl_1_data_21AEC__fzgx_offset_0[];
extern u8 lbl_1_data_21AFC__fzgx_offset_0[];
extern u8 lbl_1_data_21B0C__fzgx_offset_0[];
extern u8 lbl_1_data_21B14__fzgx_offset_0[];
extern u8 lbl_1_data_21B3C__fzgx_offset_0[];
extern u8 lbl_1_data_21B60__fzgx_offset_0[];
extern u8 lbl_1_data_21B70__fzgx_offset_0[];
extern u8 lbl_1_data_21B80__fzgx_offset_0[];
extern u8 lbl_1_data_21B90__fzgx_offset_0[];
extern u8 lbl_1_data_21BA0__fzgx_offset_0[];
extern u8 lbl_1_data_21BAC__fzgx_offset_0[];
extern u8 lbl_1_data_21BD4__fzgx_offset_0[];
extern u8 lbl_1_data_21BF0__fzgx_offset_0[];
extern u8 lbl_1_data_21C00__fzgx_offset_0[];
extern u8 lbl_1_data_21C10__fzgx_offset_0[];
extern u8 lbl_1_data_21C20__fzgx_offset_0[];
extern u8 lbl_1_data_21C30__fzgx_offset_0[];
extern u8 lbl_1_data_21C38__fzgx_offset_0[];
extern u8 lbl_1_data_21C60__fzgx_offset_0[];
extern u8 lbl_1_data_21C7C__fzgx_offset_0[];
extern u8 lbl_1_data_21C8C__fzgx_offset_0[];
extern u8 lbl_1_data_21C9C__fzgx_offset_0[];
extern u8 lbl_1_data_21CAC__fzgx_offset_0[];
extern u8 lbl_1_data_21CB4__fzgx_offset_0[];
extern u8 lbl_1_data_21CDC__fzgx_offset_0[];
extern u8 lbl_1_data_21CF4__fzgx_offset_0[];
extern u8 lbl_1_data_21D08__fzgx_offset_0[];
extern u8 lbl_1_data_21D18__fzgx_offset_0[];
extern u8 lbl_1_data_21D28__fzgx_offset_0[];
extern u8 lbl_1_data_21D30__fzgx_offset_0[];
extern u8 lbl_1_data_21D58__fzgx_offset_0[];
extern u8 lbl_1_data_21D70__fzgx_offset_0[];
extern u8 lbl_1_data_21D80__fzgx_offset_0[];
extern u8 lbl_1_data_21D90__fzgx_offset_0[];
extern u8 lbl_1_data_21DA0__fzgx_offset_0[];
extern u8 lbl_1_data_21DA8__fzgx_offset_0[];
extern u8 lbl_1_data_21DBC__fzgx_offset_0[];
extern u8 lbl_1_data_21DD0__fzgx_offset_0[];
extern u8 lbl_1_data_21DE0__fzgx_offset_0[];
extern u8 lbl_1_data_21DF0__fzgx_offset_0[];
extern u8 lbl_1_data_21E00__fzgx_offset_0[];
extern u8 lbl_1_data_21E08__fzgx_offset_0[];
extern u8 lbl_1_data_21E30__fzgx_offset_0[];
extern u8 lbl_1_data_21E54__fzgx_offset_0[];
extern u8 lbl_1_data_21E64__fzgx_offset_0[];
extern u8 lbl_1_data_21E74__fzgx_offset_0[];
extern u8 lbl_1_data_21E84__fzgx_offset_0[];
extern u8 lbl_1_data_21E8C__fzgx_offset_0[];
extern u8 lbl_1_data_21EB4__fzgx_offset_0[];
extern u8 lbl_1_data_21ECC__fzgx_offset_0[];
extern u8 lbl_1_data_21EDC__fzgx_offset_0[];
extern u8 lbl_1_data_21EEC__fzgx_offset_0[];
extern u8 lbl_1_data_21EFC__fzgx_offset_0[];
extern u8 lbl_1_data_21F04__fzgx_offset_0[];
extern u8 lbl_1_data_21F2C__fzgx_offset_0[];
extern u8 lbl_1_data_21F50__fzgx_offset_0[];
extern u8 lbl_1_data_21F60__fzgx_offset_0[];
extern u8 lbl_1_data_21F70__fzgx_offset_0[];
extern u8 lbl_1_data_21F80__fzgx_offset_0[];
extern u8 lbl_1_data_21F88__fzgx_offset_0[];
extern u8 lbl_1_data_21FB0__fzgx_offset_0[];
extern u8 lbl_1_data_21FD4__fzgx_offset_0[];
extern u8 lbl_1_data_21FE4__fzgx_offset_0[];
extern u8 lbl_1_data_21FF4__fzgx_offset_0[];
extern u8 lbl_1_data_22004__fzgx_offset_0[];
extern u8 lbl_1_data_2200C__fzgx_offset_0[];
extern u8 lbl_1_data_2203C__fzgx_offset_0[];
extern u8 lbl_1_data_22058__fzgx_offset_0[];
extern u8 lbl_1_data_22068__fzgx_offset_0[];
extern u8 lbl_1_data_2207C__fzgx_offset_0[];
extern u8 lbl_1_data_22090__fzgx_offset_0[];
extern u8 lbl_1_data_22098__fzgx_offset_0[];
extern u8 lbl_1_data_220C0__fzgx_offset_0[];
extern u8 lbl_1_data_220E8__fzgx_offset_0[];
extern u8 lbl_1_data_220F8__fzgx_offset_0[];
extern u8 lbl_1_data_22108__fzgx_offset_0[];
extern u8 lbl_1_data_22118__fzgx_offset_0[];
extern u8 lbl_1_data_22120__fzgx_offset_0[];
extern u8 lbl_1_data_22148__fzgx_offset_0[];
extern u8 lbl_1_data_22160__fzgx_offset_0[];
extern u8 lbl_1_data_22170__fzgx_offset_0[];
extern u8 lbl_1_data_22180__fzgx_offset_0[];
extern u8 lbl_1_data_22190__fzgx_offset_0[];
extern u8 lbl_1_data_22198__fzgx_offset_0[];
extern u8 lbl_1_data_221C0__fzgx_offset_0[];
extern u8 lbl_1_data_221E4__fzgx_offset_0[];
extern u8 lbl_1_data_221F4__fzgx_offset_0[];
extern u8 lbl_1_data_22204__fzgx_offset_0[];
extern u8 lbl_1_data_22214__fzgx_offset_0[];
extern u8 lbl_1_data_2221C__fzgx_offset_0[];
extern u8 lbl_1_data_22244__fzgx_offset_0[];
extern u8 lbl_1_data_22264__fzgx_offset_0[];
extern u8 lbl_1_data_22274__fzgx_offset_0[];
extern u8 lbl_1_data_22278__fzgx_offset_0[];
extern u8 lbl_1_data_22288__fzgx_offset_0[];
extern u8 lbl_1_data_22298__fzgx_offset_0[];
extern u8 lbl_1_data_222A0__fzgx_offset_0[];
extern u8 lbl_1_data_222D8__fzgx_offset_0[];
extern u8 lbl_1_data_222F4__fzgx_offset_0[];
extern u8 lbl_1_data_22310__fzgx_offset_0[];
extern u8 lbl_1_data_2232C__fzgx_offset_0[];
extern u8 lbl_1_data_22334__fzgx_offset_0[];
extern u8 lbl_1_data_2235C__fzgx_offset_0[];
extern u8 lbl_1_data_22360__fzgx_offset_0[];
extern u8 lbl_1_data_22374__fzgx_offset_0[];
extern u8 lbl_1_data_22384__fzgx_offset_0[];
extern u8 lbl_1_data_22394__fzgx_offset_0[];
extern u8 lbl_1_data_223A0__fzgx_offset_0[];
extern u8 lbl_1_data_223B4__fzgx_offset_0[];
extern u8 lbl_1_data_223CC__fzgx_offset_0[];
extern u8 lbl_1_data_223D0__fzgx_offset_0[];
extern u8 lbl_1_data_223DC__fzgx_offset_0[];
extern u8 lbl_1_data_223EC__fzgx_offset_0[];
extern u8 lbl_1_data_223FC__fzgx_offset_0[];
extern u8 lbl_1_data_22404__fzgx_offset_0[];
extern u8 lbl_1_data_2242C__fzgx_offset_0[];
extern u8 lbl_1_data_22454__fzgx_offset_0[];
extern u8 lbl_1_data_22464__fzgx_offset_0[];
extern u8 lbl_1_data_22474__fzgx_offset_0[];
extern u8 lbl_1_data_22484__fzgx_offset_0[];
extern u8 lbl_1_data_2248C__fzgx_offset_0[];
extern u8 lbl_1_data_224AC__fzgx_offset_0[];
extern u8 lbl_1_data_224B4__fzgx_offset_0[];
extern u8 lbl_1_data_224B8__fzgx_offset_0[];
extern u8 lbl_1_data_224C8__fzgx_offset_0[];
extern u8 lbl_1_data_224D8__fzgx_offset_0[];
extern u8 lbl_1_data_224E4__fzgx_offset_0[];
extern u8 lbl_1_data_22514__fzgx_offset_0[];
extern u8 lbl_1_data_22520__fzgx_offset_0[];
extern u8 lbl_1_data_22528__fzgx_offset_0[];
extern u8 lbl_1_data_2253C__fzgx_offset_0[];
extern u8 lbl_1_data_22550__fzgx_offset_0[];
extern u8 lbl_1_data_2255C__fzgx_offset_0[];
extern u8 lbl_1_data_22584__fzgx_offset_0[];
extern u8 lbl_1_data_225AC__fzgx_offset_0[];
extern u8 lbl_1_data_225BC__fzgx_offset_0[];
extern u8 lbl_1_data_225CC__fzgx_offset_0[];
extern u8 lbl_1_data_225DC__fzgx_offset_0[];
extern u8 lbl_1_data_225E4__fzgx_offset_0[];
extern u8 lbl_1_data_2260C__fzgx_offset_0[];
extern u8 lbl_1_data_22630__fzgx_offset_0[];
extern u8 lbl_1_data_22640__fzgx_offset_0[];
extern u8 lbl_1_data_22650__fzgx_offset_0[];
extern u8 lbl_1_data_22660__fzgx_offset_0[];
extern u8 lbl_1_data_22670__fzgx_offset_0[];
extern u8 lbl_1_data_2267C__fzgx_offset_0[];
extern u8 lbl_1_data_226A4__fzgx_offset_0[];
extern u8 lbl_1_data_226C0__fzgx_offset_0[];
extern u8 lbl_1_data_226D4__fzgx_offset_0[];
extern u8 lbl_1_data_226E4__fzgx_offset_0[];
extern u8 lbl_1_data_226F4__fzgx_offset_0[];
extern u8 lbl_1_data_226FC__fzgx_offset_0[];
extern u8 lbl_1_data_22724__fzgx_offset_0[];
extern u8 lbl_1_data_22744__fzgx_offset_0[];
extern u8 lbl_1_data_22754__fzgx_offset_0[];
extern u8 lbl_1_data_22764__fzgx_offset_0[];
extern u8 lbl_1_data_22774__fzgx_offset_0[];
extern u8 lbl_1_data_2277C__fzgx_offset_0[];
extern u8 lbl_1_data_227A4__fzgx_offset_0[];
extern u8 lbl_1_data_227C0__fzgx_offset_0[];
extern u8 lbl_1_data_227D0__fzgx_offset_0[];
extern u8 lbl_1_data_227E0__fzgx_offset_0[];
extern u8 lbl_1_data_227F0__fzgx_offset_0[];
extern u8 lbl_1_data_22800__fzgx_offset_0[];
extern u8 lbl_1_data_22808__fzgx_offset_0[];
extern u8 lbl_1_data_2281C__fzgx_offset_0[];
extern u8 lbl_1_data_22834__fzgx_offset_0[];
extern u8 lbl_1_data_2284C__fzgx_offset_0[];
extern u8 lbl_1_data_2285C__fzgx_offset_0[];
extern u8 lbl_1_data_2286C__fzgx_offset_0[];
extern u8 lbl_1_data_2287C__fzgx_offset_0[];
extern u8 lbl_1_data_22884__fzgx_offset_0[];
extern u8 lbl_1_data_228AC__fzgx_offset_0[];
extern u8 lbl_1_data_228CC__fzgx_offset_0[];
extern u8 lbl_1_data_228DC__fzgx_offset_0[];
extern u8 lbl_1_data_228EC__fzgx_offset_0[];
extern u8 lbl_1_data_228FC__fzgx_offset_0[];
extern u8 lbl_1_data_22904__fzgx_offset_0[];
extern u8 lbl_1_data_2292C__fzgx_offset_0[];
extern u8 lbl_1_data_2294C__fzgx_offset_0[];
extern u8 lbl_1_data_2295C__fzgx_offset_0[];
extern u8 lbl_1_data_22964__fzgx_offset_0[];
extern u8 lbl_1_data_22974__fzgx_offset_0[];
extern u8 lbl_1_data_22984__fzgx_offset_0[];
extern u8 lbl_1_data_2298C__fzgx_offset_0[];
extern u8 lbl_1_data_229B4__fzgx_offset_0[];
extern u8 lbl_1_data_229D8__fzgx_offset_0[];
extern u8 lbl_1_data_229E8__fzgx_offset_0[];
extern u8 lbl_1_data_229F8__fzgx_offset_0[];
extern u8 lbl_1_data_22A08__fzgx_offset_0[];
extern u8 lbl_1_data_22A10__fzgx_offset_0[];
extern u8 lbl_1_data_22A14__fzgx_offset_0[];
extern u8 lbl_1_data_22A18__fzgx_offset_0[];
extern u8 lbl_1_data_22A1C__fzgx_offset_0[];
extern u8 lbl_1_data_22A24__fzgx_offset_0[];
extern u8 lbl_1_data_22A2C__fzgx_offset_0[];
extern u8 lbl_1_data_22A34__fzgx_offset_0[];
extern u8 lbl_1_data_22A3C__fzgx_offset_0[];
extern u8 lbl_1_data_22A44__fzgx_offset_0[];
extern u8 lbl_1_data_22A4C__fzgx_offset_0[];
extern u8 lbl_1_data_22B24__fzgx_offset_0[];
extern u8 lbl_1_data_22BD8__fzgx_offset_0[];
extern u8 lbl_1_data_22C8C__fzgx_offset_0[];
extern u8 lbl_1_data_22D40__fzgx_offset_0[];
extern u8 lbl_1_data_22DF4__fzgx_offset_0[];
extern u8 lbl_1_data_22E00__fzgx_offset_0[];
extern u8 lbl_1_data_22E0C__fzgx_offset_0[];
extern u8 lbl_1_data_22F08__fzgx_offset_0[];
extern u8 lbl_1_data_22FBC__fzgx_offset_0[];
extern u8 lbl_1_data_23028__fzgx_offset_0[];
extern u8 lbl_1_data_230DC__fzgx_offset_0[];
extern u8 lbl_1_data_23190__fzgx_offset_0[];
extern u8 lbl_1_data_23198__fzgx_offset_0[];
extern u8 lbl_1_data_23270__fzgx_offset_0[];
extern u8 lbl_1_data_23324__fzgx_offset_0[];
extern u8 lbl_1_data_23420__fzgx_offset_0[];
extern u8 lbl_1_data_23428__fzgx_offset_0[];
extern u8 lbl_1_data_23500__fzgx_offset_0[];
extern u8 lbl_1_data_235FC__fzgx_offset_0[];
extern u8 lbl_1_data_236B0__fzgx_offset_0[];
extern u8 lbl_1_data_236B8__fzgx_offset_0[];
extern u8 lbl_1_data_23790__fzgx_offset_0[];
extern u8 lbl_1_data_23844__fzgx_offset_0[];
extern u8 lbl_1_data_238F8__fzgx_offset_0[];
extern u8 lbl_1_data_239AC__fzgx_offset_0[];
extern u8 lbl_1_data_23A60__fzgx_offset_0[];
extern u8 lbl_1_data_23B14__fzgx_offset_0[];
extern u8 lbl_1_data_23BC8__fzgx_offset_0[];
extern u8 lbl_1_data_23C7C__fzgx_offset_0[];
extern u8 lbl_1_data_23D30__fzgx_offset_0[];
extern u8 lbl_1_data_23DE4__fzgx_offset_0[];
extern u8 lbl_1_data_23E98__fzgx_offset_0[];
extern u8 lbl_1_data_23F4C__fzgx_offset_0[];
extern u8 lbl_1_data_24000__fzgx_offset_0[];
extern u8 lbl_1_data_240B4__fzgx_offset_0[];
extern u8 lbl_1_data_24168__fzgx_offset_0[];
extern u8 lbl_1_data_2421C__fzgx_offset_0[];
extern u8 lbl_1_data_24318__fzgx_offset_0[];
extern u8 lbl_1_data_24320__fzgx_offset_0[];
extern u8 lbl_1_data_243F8__fzgx_offset_0[];
extern u8 lbl_1_data_244AC__fzgx_offset_0[];
extern u8 lbl_1_data_24560__fzgx_offset_0[];
extern u8 lbl_1_data_24638__fzgx_offset_0[];
extern u8 lbl_1_data_2463C__fzgx_offset_0[];
extern u8 lbl_1_data_24714__fzgx_offset_0[];
extern u8 lbl_1_data_247C8__fzgx_offset_0[];
extern u8 lbl_1_data_2487C__fzgx_offset_0[];
extern u8 lbl_1_data_24930__fzgx_offset_0[];
extern u8 lbl_1_data_249E4__fzgx_offset_0[];
extern u8 lbl_1_data_249F4__fzgx_offset_0[];
extern u8 lbl_1_data_24A04__fzgx_offset_0[];
extern u8 lbl_1_data_24A14__fzgx_offset_0[];
extern u8 lbl_1_data_24A24__fzgx_offset_0[];
extern u8 lbl_1_data_24A30__fzgx_offset_0[];
extern u8 lbl_1_data_24A3C__fzgx_offset_0[];
extern u8 lbl_1_data_24A48__fzgx_offset_0[];
extern u8 lbl_1_data_24A54__fzgx_offset_0[];
extern u8 lbl_1_data_24A5C__fzgx_offset_0[];
extern u8 lbl_1_data_24A64__fzgx_offset_0[];
extern u8 lbl_1_data_24A6C__fzgx_offset_0[];
extern u8 lbl_1_data_24A74__fzgx_offset_0[];
extern u8 lbl_1_data_24A7C__fzgx_offset_0[];
extern u8 lbl_1_data_24A84__fzgx_offset_0[];
extern u8 lbl_1_data_24A8C__fzgx_offset_0[];
extern u8 lbl_1_data_24A94__fzgx_offset_0[];
extern u8 lbl_1_data_24D88__fzgx_offset_0[];
extern u8 lbl_1_data_24E3C__fzgx_offset_0[];
extern u8 lbl_1_data_24EF0__fzgx_offset_0[];
extern u8 lbl_1_data_24EF8__fzgx_offset_0[];
extern u8 lbl_1_data_24F1C__fzgx_offset_0[];
extern u8 lbl_1_data_24F40__fzgx_offset_0[];
extern u8 lbl_1_data_24F64__fzgx_offset_0[];
extern u8 lbl_1_data_24F88__fzgx_offset_0[];
extern u8 lbl_1_data_24FAC__fzgx_offset_0[];
extern u8 lbl_1_data_24FD0__fzgx_offset_0[];
extern u8 lbl_1_data_24FF4__fzgx_offset_0[];
extern u8 lbl_1_data_25018__fzgx_offset_0[];
extern u8 lbl_1_data_2503C__fzgx_offset_0[];
extern u8 lbl_1_data_25060__fzgx_offset_0[];
extern u8 lbl_1_data_250A8__fzgx_offset_0[];
extern u8 lbl_1_data_250CC__fzgx_offset_0[];
extern u8 lbl_1_data_250F0__fzgx_offset_0[];
extern u8 lbl_1_data_25138__fzgx_offset_0[];
extern u8 lbl_1_data_2515C__fzgx_offset_0[];
extern u8 lbl_1_data_25180__fzgx_offset_0[];
extern u8 lbl_1_data_251A4__fzgx_offset_0[];
extern u8 lbl_1_data_251EC__fzgx_offset_0[];
extern u8 lbl_1_data_25210__fzgx_offset_0[];
extern u8 lbl_1_data_25234__fzgx_offset_0[];
extern u8 lbl_1_data_25258__fzgx_offset_0[];
extern u8 lbl_1_data_2527C__fzgx_offset_0[];
extern u8 lbl_1_data_252A0__fzgx_offset_0[];
extern u8 lbl_1_data_252C4__fzgx_offset_0[];
extern u8 lbl_1_data_252E8__fzgx_offset_0[];
extern u8 lbl_1_data_25354__fzgx_offset_0[];
extern u8 lbl_1_data_253C0__fzgx_offset_0[];
extern u8 lbl_1_data_253E4__fzgx_offset_0[];
extern u8 lbl_1_data_25408__fzgx_offset_0[];
extern u8 lbl_1_data_2542C__fzgx_offset_0[];
extern u8 lbl_1_data_25450__fzgx_offset_0[];
extern u8 lbl_1_data_25474__fzgx_offset_0[];
extern u8 lbl_1_data_25498__fzgx_offset_0[];
extern u8 lbl_1_data_254E0__fzgx_offset_0[];
extern u8 lbl_1_data_25504__fzgx_offset_0[];
extern u8 lbl_1_data_25528__fzgx_offset_0[];
extern u8 lbl_1_data_25570__fzgx_offset_0[];
extern u8 lbl_1_data_255B8__fzgx_offset_0[];
extern u8 lbl_1_data_25624__fzgx_offset_0[];
extern u8 lbl_1_data_25690__fzgx_offset_0[];
extern u8 lbl_1_data_256FC__fzgx_offset_0[];
extern u8 lbl_1_data_25720__fzgx_offset_0[];
extern u8 lbl_1_data_25984__fzgx_offset_0[];
extern u8 lbl_1_data_259A8__fzgx_offset_0[];
extern u8 lbl_1_data_259CC__fzgx_offset_0[];
extern u8 lbl_1_data_259F0__fzgx_offset_0[];
extern u8 lbl_1_data_25A14__fzgx_offset_0[];
extern u8 lbl_1_data_25A38__fzgx_offset_0[];
extern u8 lbl_1_data_25A5C__fzgx_offset_0[];
extern u8 lbl_1_data_25A80__fzgx_offset_0[];
extern u8 lbl_1_data_25AA4__fzgx_offset_0[];
extern u8 lbl_1_data_25AC8__fzgx_offset_0[];
extern u8 lbl_1_data_25AEC__fzgx_offset_0[];
extern u8 lbl_1_data_25B10__fzgx_offset_0[];
extern u8 lbl_1_data_25B34__fzgx_offset_0[];
extern u8 lbl_1_data_25B58__fzgx_offset_0[];
extern u8 lbl_1_data_25B7C__fzgx_offset_0[];
extern u8 lbl_1_data_25BA0__fzgx_offset_0[];
extern u8 lbl_1_data_25BC4__fzgx_offset_0[];
extern u8 lbl_1_data_25BE8__fzgx_offset_0[];
extern u8 lbl_1_data_25C0C__fzgx_offset_0[];
extern u8 lbl_1_data_25C30__fzgx_offset_0[];
extern u8 lbl_1_data_25C54__fzgx_offset_0[];
extern u8 lbl_1_data_25C78__fzgx_offset_0[];
extern u8 lbl_1_data_25C9C__fzgx_offset_0[];
extern u8 lbl_1_data_25CC0__fzgx_offset_0[];
extern u8 lbl_1_data_25CE4__fzgx_offset_0[];
extern u8 lbl_1_data_25D08__fzgx_offset_0[];
extern u8 lbl_1_data_25D2C__fzgx_offset_0[];
extern u8 lbl_1_data_25D50__fzgx_offset_0[];
extern u8 lbl_1_data_25D74__fzgx_offset_0[];
extern u8 lbl_1_data_25D98__fzgx_offset_0[];
extern u8 lbl_1_data_25DBC__fzgx_offset_0[];
extern u8 lbl_1_data_25DE0__fzgx_offset_0[];
extern u8 lbl_1_data_25E04__fzgx_offset_0[];
extern u8 lbl_1_data_25E28__fzgx_offset_0[];
extern u8 lbl_1_data_25E4C__fzgx_offset_0[];
extern u8 lbl_1_data_25E70__fzgx_offset_0[];
extern u8 lbl_1_data_25E94__fzgx_offset_0[];
extern u8 lbl_1_data_25EB8__fzgx_offset_0[];
extern u8 lbl_1_data_25EDC__fzgx_offset_0[];
extern u8 lbl_1_data_25F00__fzgx_offset_0[];
extern u8 lbl_1_data_25F24__fzgx_offset_0[];
extern u8 lbl_1_data_25F48__fzgx_offset_0[];
extern u8 lbl_1_data_25F6C__fzgx_offset_0[];
extern u8 lbl_1_data_25F90__fzgx_offset_0[];
extern u8 lbl_1_data_25FB4__fzgx_offset_0[];
extern u8 lbl_1_data_25FD8__fzgx_offset_0[];
extern u8 lbl_1_data_25FFC__fzgx_offset_0[];
extern u8 lbl_1_data_26020__fzgx_offset_0[];
extern u8 lbl_1_data_26044__fzgx_offset_0[];
extern u8 lbl_1_data_26068__fzgx_offset_0[];
extern u8 lbl_1_data_2608C__fzgx_offset_0[];
extern u8 lbl_1_data_260B0__fzgx_offset_0[];
extern u8 lbl_1_data_260D4__fzgx_offset_0[];
extern u8 lbl_1_data_260F8__fzgx_offset_0[];
extern u8 lbl_1_data_2611C__fzgx_offset_0[];
extern u8 lbl_1_data_26140__fzgx_offset_0[];
extern u8 lbl_1_data_26164__fzgx_offset_0[];
extern u8 lbl_1_data_26188__fzgx_offset_0[];
extern u8 lbl_1_data_261AC__fzgx_offset_0[];
extern u8 lbl_1_data_261D0__fzgx_offset_0[];
extern u8 lbl_1_data_261F4__fzgx_offset_0[];
extern u8 lbl_1_data_26218__fzgx_offset_0[];
extern u8 lbl_1_data_2623C__fzgx_offset_0[];
extern u8 lbl_1_data_26260__fzgx_offset_0[];
extern u8 lbl_1_data_26284__fzgx_offset_0[];
extern u8 lbl_1_data_262A8__fzgx_offset_0[];
extern u8 lbl_1_data_262CC__fzgx_offset_0[];
extern u8 lbl_1_data_262F0__fzgx_offset_0[];
extern u8 lbl_1_data_26314__fzgx_offset_0[];
extern u8 lbl_1_data_26338__fzgx_offset_0[];
extern u8 lbl_1_data_2635C__fzgx_offset_0[];
extern u8 lbl_1_data_26380__fzgx_offset_0[];
extern u8 lbl_1_data_263A4__fzgx_offset_0[];
extern u8 lbl_1_data_263C8__fzgx_offset_0[];
extern u8 lbl_1_data_263EC__fzgx_offset_0[];
extern u8 lbl_1_data_26410__fzgx_offset_0[];
extern u8 lbl_1_data_26434__fzgx_offset_0[];
extern u8 lbl_1_data_26458__fzgx_offset_0[];
extern u8 lbl_1_data_2647C__fzgx_offset_0[];
extern u8 lbl_1_data_264A0__fzgx_offset_0[];
extern u8 lbl_1_data_264C4__fzgx_offset_0[];
extern u8 lbl_1_data_264E8__fzgx_offset_0[];
extern u8 lbl_1_data_2650C__fzgx_offset_0[];
extern u8 lbl_1_data_26530__fzgx_offset_0[];
extern u8 lbl_1_data_26554__fzgx_offset_0[];
extern u8 lbl_1_data_26578__fzgx_offset_0[];
extern u8 lbl_1_data_2659C__fzgx_offset_0[];
extern u8 lbl_1_data_265C0__fzgx_offset_0[];
extern u8 lbl_1_data_265E4__fzgx_offset_0[];
extern u8 lbl_1_data_26608__fzgx_offset_0[];
extern u8 lbl_1_data_2662C__fzgx_offset_0[];
extern u8 lbl_1_data_26650__fzgx_offset_0[];
extern u8 lbl_1_data_26D8C__fzgx_offset_0[];
extern u8 lbl_1_data_26D94__fzgx_offset_0[];
extern u8 lbl_1_data_26D9C__fzgx_offset_0[];
extern u8 lbl_1_data_26DA4__fzgx_offset_0[];
extern u8 lbl_1_data_26DAC__fzgx_offset_0[];
extern u8 lbl_1_data_26DB4__fzgx_offset_0[];
extern u8 lbl_1_data_26DDC__fzgx_offset_0[];
extern u8 lbl_1_data_26DE4__fzgx_offset_0[];
extern u8 lbl_1_data_26DEC__fzgx_offset_0[];
extern u8 lbl_1_data_26DF4__fzgx_offset_0[];
extern u8 lbl_1_data_26E00__fzgx_offset_0[];
extern u8 lbl_1_data_26E0C__fzgx_offset_0[];
extern u8 lbl_1_data_26E14__fzgx_offset_0[];
extern u8 lbl_1_data_26E1C__fzgx_offset_0[];
extern u8 lbl_1_data_26E24__fzgx_offset_0[];
extern u8 lbl_1_data_26E2C__fzgx_offset_0[];
extern u8 lbl_1_data_26E34__fzgx_offset_0[];
extern u8 lbl_1_data_26E3C__fzgx_offset_0[];
extern u8 lbl_1_data_26E44__fzgx_offset_0[];
extern u8 lbl_1_data_26E4C__fzgx_offset_0[];
extern u8 lbl_1_data_26E54__fzgx_offset_0[];
extern u8 lbl_1_data_26E5C__fzgx_offset_0[];
extern u8 lbl_1_data_26E64__fzgx_offset_0[];
extern u8 lbl_1_data_26E6C__fzgx_offset_0[];
extern u8 lbl_1_data_26E74__fzgx_offset_0[];
extern u8 lbl_1_data_26E7C__fzgx_offset_0[];
extern u8 lbl_1_data_26E84__fzgx_offset_0[];
extern u8 lbl_1_data_26E8C__fzgx_offset_0[];
extern u8 lbl_1_data_26E94__fzgx_offset_0[];
extern u8 lbl_1_data_26E9C__fzgx_offset_0[];
extern u8 lbl_1_data_26EA4__fzgx_offset_0[];
extern u8 lbl_1_data_26EB0__fzgx_offset_0[];
extern u8 lbl_1_data_26EBC__fzgx_offset_0[];
extern u8 lbl_1_data_26EC8__fzgx_offset_0[];
extern u8 lbl_1_data_26ED4__fzgx_offset_0[];
extern u8 lbl_1_data_26EE0__fzgx_offset_0[];
extern u8 lbl_1_data_26EEC__fzgx_offset_0[];
extern u8 lbl_1_data_26EF8__fzgx_offset_0[];
extern u8 lbl_1_data_26F04__fzgx_offset_0[];
extern u8 lbl_1_data_26F10__fzgx_offset_0[];
extern u8 lbl_1_data_26F1C__fzgx_offset_0[];
extern u8 lbl_1_data_26F28__fzgx_offset_0[];
extern u8 lbl_1_data_26F34__fzgx_offset_0[];
extern u8 lbl_1_data_26F40__fzgx_offset_0[];
extern u8 lbl_1_data_26F4C__fzgx_offset_0[];
extern u8 lbl_1_data_26F58__fzgx_offset_0[];
extern u8 lbl_1_data_26F64__fzgx_offset_0[];
extern u8 lbl_1_data_26F70__fzgx_offset_0[];
extern u8 lbl_1_data_26F7C__fzgx_offset_0[];
extern u8 lbl_1_data_26F88__fzgx_offset_0[];
extern u8 lbl_1_data_27048__fzgx_offset_0[];
extern u8 lbl_1_data_27058__fzgx_offset_0[];
extern u8 lbl_1_data_27060__fzgx_offset_0[];
extern u8 lbl_1_data_2706C__fzgx_offset_0[];
extern u8 lbl_1_data_2707C__fzgx_offset_0[];
extern u8 lbl_1_data_27088__fzgx_offset_0[];
extern u8 lbl_1_data_27094__fzgx_offset_0[];
extern u8 lbl_1_data_270A0__fzgx_offset_0[];
extern u8 lbl_1_data_270B0__fzgx_offset_0[];
extern u8 lbl_1_data_270C0__fzgx_offset_0[];
extern u8 lbl_1_data_270CC__fzgx_offset_0[];
extern u8 lbl_1_data_270D8__fzgx_offset_0[];
extern u8 lbl_1_data_270E4__fzgx_offset_0[];
extern u8 lbl_1_data_270F0__fzgx_offset_0[];
extern u8 lbl_1_data_270FC__fzgx_offset_0[];
extern u8 lbl_1_data_27108__fzgx_offset_0[];
extern u8 lbl_1_data_27114__fzgx_offset_0[];
extern u8 lbl_1_data_27124__fzgx_offset_0[];
extern u8 lbl_1_data_27134__fzgx_offset_0[];
extern u8 lbl_1_data_27144__fzgx_offset_0[];
extern u8 lbl_1_data_27150__fzgx_offset_0[];
extern u8 lbl_1_data_2715C__fzgx_offset_0[];
extern u8 lbl_1_data_27168__fzgx_offset_0[];
extern u8 lbl_1_data_27174__fzgx_offset_0[];
extern u8 lbl_1_data_27184__fzgx_offset_0[];
extern u8 lbl_1_data_27194__fzgx_offset_0[];
extern u8 lbl_1_data_271A0__fzgx_offset_0[];
extern u8 lbl_1_data_271B0__fzgx_offset_0[];
extern u8 lbl_1_data_271BC__fzgx_offset_0[];
extern u8 lbl_1_data_271C8__fzgx_offset_0[];
extern u8 lbl_1_data_271D4__fzgx_offset_0[];
extern u8 lbl_1_data_271E4__fzgx_offset_0[];
extern u8 lbl_1_data_271F0__fzgx_offset_0[];
extern u8 lbl_1_data_271FC__fzgx_offset_0[];
extern u8 lbl_1_data_2720C__fzgx_offset_0[];
extern u8 lbl_1_data_27218__fzgx_offset_0[];
extern u8 lbl_1_data_27224__fzgx_offset_0[];
extern u8 lbl_1_data_27234__fzgx_offset_0[];
extern u8 lbl_1_data_27244__fzgx_offset_0[];
extern u8 lbl_1_data_27250__fzgx_offset_0[];
extern u8 lbl_1_data_2725C__fzgx_offset_0[];
extern u8 lbl_1_data_27268__fzgx_offset_0[];
extern u8 lbl_1_data_27278__fzgx_offset_0[];
extern u8 lbl_1_data_27284__fzgx_offset_0[];
extern u8 lbl_1_data_27290__fzgx_offset_0[];
extern u8 lbl_1_data_2729C__fzgx_offset_0[];
extern u8 lbl_1_data_272A8__fzgx_offset_0[];
extern u8 lbl_1_data_272B0__fzgx_offset_0[];
extern u8 lbl_1_data_272BC__fzgx_offset_0[];
extern u8 lbl_1_data_272C0__fzgx_offset_0[];
extern u8 lbl_1_data_272D0__fzgx_offset_0[];
extern u8 lbl_1_data_272D4__fzgx_offset_0[];
extern u8 lbl_1_data_272E4__fzgx_offset_0[];
extern u8 lbl_1_data_272EC__fzgx_offset_0[];
extern u8 lbl_1_data_272F8__fzgx_offset_0[];
extern u8 lbl_1_data_27300__fzgx_offset_0[];
extern u8 lbl_1_data_27304__fzgx_offset_0[];
extern u8 lbl_1_data_27318__fzgx_offset_0[];
extern u8 lbl_1_data_27324__fzgx_offset_0[];
extern u8 lbl_1_data_27338__fzgx_offset_0[];
extern u8 lbl_1_data_27344__fzgx_offset_0[];
extern u8 lbl_1_data_27358__fzgx_offset_0[];
extern u8 lbl_1_data_27364__fzgx_offset_0[];
extern u8 lbl_1_data_27378__fzgx_offset_0[];
extern u8 lbl_1_data_27384__fzgx_offset_0[];
extern u8 lbl_1_data_27398__fzgx_offset_0[];
extern u8 lbl_1_data_273A8__fzgx_offset_0[];
extern u8 lbl_1_data_273BC__fzgx_offset_0[];
extern u8 lbl_1_data_273CC__fzgx_offset_0[];
extern u8 lbl_1_data_273E0__fzgx_offset_0[];
extern u8 lbl_1_data_273F0__fzgx_offset_0[];
extern u8 lbl_1_data_27404__fzgx_offset_0[];
extern u8 lbl_1_data_27414__fzgx_offset_0[];
extern u8 lbl_1_data_27424__fzgx_offset_0[];
extern u8 lbl_1_data_2742C__fzgx_offset_0[];
extern u8 lbl_1_data_2743C__fzgx_offset_0[];
extern u8 lbl_1_data_27444__fzgx_offset_0[];
extern u8 lbl_1_data_27454__fzgx_offset_0[];
extern u8 lbl_1_data_2745C__fzgx_offset_0[];
extern u8 lbl_1_data_2746C__fzgx_offset_0[];
extern u8 lbl_1_data_27474__fzgx_offset_0[];
extern u8 lbl_1_data_27484__fzgx_offset_0[];
extern u8 lbl_1_data_2748C__fzgx_offset_0[];
extern u8 lbl_1_data_2749C__fzgx_offset_0[];
extern u8 lbl_1_data_274A4__fzgx_offset_0[];
extern u8 lbl_1_data_274B4__fzgx_offset_0[];
extern u8 lbl_1_data_274BC__fzgx_offset_0[];
extern u8 lbl_1_data_274CC__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_1_data_209C0_gap_0[215] = {0x47415A45, 0x4C4C4500, 0x4A4F4459, 0x00000000, 0x53544557, 0x41525400, 0x42414241, 0x00000000, 0x474F524F, 0x48000000, 0x5049434F, 0x00000000, 0x46414C43, 0x4F4E0000, 0x4F43544D, 0x414E0000, 0x45414400, 0x4A414D45, 0x53000000, 0x42494C4C, 0x59000000, 0x4B415445, 0x00000000, 0x5A4F4441, 0x00000000, 0x4A41434B, 0x00000000, 0x52455800, 0x474F5244, 0x4F4E0000, 0x47555354, 0x45520000, 0x42454153, 0x544D414E, 0x00000000, 0x4C454F4E, 0x00000000, 0x4152524F, 0x57000000, 0x4D525300, 0x5348494F, 0x00000000, 0x4E45454C, 0x53454E00, 0x4D494348, 0x41454C00, 0x424C4F4F, 0x44000000, 0x54414E41, 0x4B410000, 0x44524151, 0x00000000, 0x524F4745, 0x52000000, 0x434C4153, 0x48000000, 0x53484144, 0x4F570000, 0x424F5353, 0x00000000, 0x444F4E00, 0x44494749, 0x424F5900, 0x44414900, 0x53504144, 0x45000000, 0x44414947, 0x4F524F48, 0x00000000, 0x50524953, 0x49410000, 0x4C494C59, 0x00000000, 0x504A0000, 0x51515100, 0x53484552, 0x4C4F434B, 0x00000000, 0x474F4D41, 0x00000000, 0x53414E00, 0x47454E00, 0x494E5445, 0x52564945, 0x57455200, (u32)lbl_1_data_209C0__fzgx_offset_0, (u32)lbl_1_data_209C8__fzgx_offset_0, (u32)lbl_1_data_209D0__fzgx_offset_0, (u32)lbl_1_data_209D8__fzgx_offset_0, (u32)lbl_1_data_209E0__fzgx_offset_0, (u32)lbl_1_data_209E8__fzgx_offset_0, (u32)lbl_1_data_209F0__fzgx_offset_0, (u32)lbl_1_data_209F8__fzgx_offset_0, (u32)lbl_1_data_20A00__fzgx_offset_0, (u32)lbl_1_data_20A04__fzgx_offset_0, (u32)lbl_1_data_20A0C__fzgx_offset_0, (u32)lbl_1_data_20A14__fzgx_offset_0, (u32)lbl_1_data_20A1C__fzgx_offset_0, (u32)lbl_1_data_20A24__fzgx_offset_0, (u32)lbl_1_data_20A2C__fzgx_offset_0, (u32)lbl_1_data_20A30__fzgx_offset_0, (u32)lbl_1_data_20A38__fzgx_offset_0, (u32)lbl_1_data_20A40__fzgx_offset_0, (u32)lbl_1_data_20A4C__fzgx_offset_0, (u32)lbl_1_data_20A54__fzgx_offset_0, (u32)lbl_1_data_20A5C__fzgx_offset_0, (u32)lbl_1_data_20A60__fzgx_offset_0, (u32)lbl_1_data_20A68__fzgx_offset_0, (u32)lbl_1_data_20A70__fzgx_offset_0, (u32)lbl_1_data_20A78__fzgx_offset_0, (u32)lbl_1_data_20A80__fzgx_offset_0, (u32)lbl_1_data_20A88__fzgx_offset_0, (u32)lbl_1_data_20A90__fzgx_offset_0, (u32)lbl_1_data_20A98__fzgx_offset_0, (u32)lbl_1_data_20AA0__fzgx_offset_0, (u32)lbl_1_data_20AA8__fzgx_offset_0, (u32)lbl_1_data_20AB0__fzgx_offset_0, (u32)lbl_1_data_20AB4__fzgx_offset_0, (u32)lbl_1_data_20ABC__fzgx_offset_0, (u32)lbl_1_data_20AC0__fzgx_offset_0, (u32)lbl_1_data_20AC8__fzgx_offset_0, (u32)lbl_1_data_20AD4__fzgx_offset_0, (u32)lbl_1_data_20ADC__fzgx_offset_0, (u32)lbl_1_data_20AE4__fzgx_offset_0, (u32)lbl_1_data_20AE8__fzgx_offset_0, (u32)lbl_1_data_20AEC__fzgx_offset_0, (u32)lbl_1_data_20AF8__fzgx_offset_0, (u32)lbl_1_data_20B00__fzgx_offset_0, (u32)lbl_1_data_20B04__fzgx_offset_0, (u32)lbl_1_data_20B08__fzgx_offset_0, 0x67617A65, 0x6C6C6500, 0x6A6F6479, 0x00000000, 0x73746577, 0x61727400, 0x62616261, 0x00000000, 0x676F726F, 0x68000000, 0x7069636F, 0x00000000, 0x66616C63, 0x6F6E0000, 0x6F63746D, 0x616E0000, 0x65616400, 0x6A616D65, 0x73000000, 0x62696C6C, 0x79000000, 0x6B617465, 0x00000000, 0x7A6F6461, 0x00000000, 0x6A61636B, 0x00000000, 0x72657800, 0x676F7264, 0x6F6E0000, 0x67757374, 0x65720000, 0x62656173, 0x746D616E, 0x00000000, 0x6C656F6E, 0x00000000, 0x6172726F, 0x77000000, 0x6D727300, 0x7368696F, 0x00000000, 0x6E65656C, 0x73656E00, 0x6D696368, 0x61656C00, 0x626C6F6F, 0x64000000, 0x74616E61, 0x6B610000, 0x64726171, 0x00000000, 0x726F6765, 0x72000000, 0x636C6173, 0x68000000, 0x73686164, 0x6F770000, 0x626F7373, 0x00000000, 0x646F6E00, 0x64696769, 0x626F7900, 0x64616900, 0x73706164, 0x65000000, 0x64616967, 0x6F726F68, 0x00000000, 0x70726973, 0x69610000, 0x6C696C79, 0x00000000, 0x706A0000, 0x71717100, 0x73686572, 0x6C6F636B, 0x00000000, 0x676F6D61, 0x00000000, 0x73616E00, 0x67656E00, 0x696E7465, 0x72766965, 0x77657200}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union {u32 words[6879]; const char *view[(0x6ED8 - 0x35C) / 4];} fzgx_pool_native_lbl_1_data_209C0_names = {{(u32)lbl_1_data_20BC8__fzgx_offset_0, (u32)lbl_1_data_20BD0__fzgx_offset_0, (u32)lbl_1_data_20BD8__fzgx_offset_0, (u32)lbl_1_data_20BE0__fzgx_offset_0, (u32)lbl_1_data_20BE8__fzgx_offset_0, (u32)lbl_1_data_20BF0__fzgx_offset_0, (u32)lbl_1_data_20BF8__fzgx_offset_0, (u32)lbl_1_data_20C00__fzgx_offset_0, (u32)lbl_1_data_20C08__fzgx_offset_0, (u32)lbl_1_data_20C0C__fzgx_offset_0, (u32)lbl_1_data_20C14__fzgx_offset_0, (u32)lbl_1_data_20C1C__fzgx_offset_0, (u32)lbl_1_data_20C24__fzgx_offset_0, (u32)lbl_1_data_20C2C__fzgx_offset_0, (u32)lbl_1_data_20C34__fzgx_offset_0, (u32)lbl_1_data_20C38__fzgx_offset_0, (u32)lbl_1_data_20C40__fzgx_offset_0, (u32)lbl_1_data_20C48__fzgx_offset_0, (u32)lbl_1_data_20C54__fzgx_offset_0, (u32)lbl_1_data_20C5C__fzgx_offset_0, (u32)lbl_1_data_20C64__fzgx_offset_0, (u32)lbl_1_data_20C68__fzgx_offset_0, (u32)lbl_1_data_20C70__fzgx_offset_0, (u32)lbl_1_data_20C78__fzgx_offset_0, (u32)lbl_1_data_20C80__fzgx_offset_0, (u32)lbl_1_data_20C88__fzgx_offset_0, (u32)lbl_1_data_20C90__fzgx_offset_0, (u32)lbl_1_data_20C98__fzgx_offset_0, (u32)lbl_1_data_20CA0__fzgx_offset_0, (u32)lbl_1_data_20CA8__fzgx_offset_0, (u32)lbl_1_data_20CB0__fzgx_offset_0, (u32)lbl_1_data_20CB8__fzgx_offset_0, (u32)lbl_1_data_20CBC__fzgx_offset_0, (u32)lbl_1_data_20CC4__fzgx_offset_0, (u32)lbl_1_data_20CC8__fzgx_offset_0, (u32)lbl_1_data_20CD0__fzgx_offset_0, (u32)lbl_1_data_20CDC__fzgx_offset_0, (u32)lbl_1_data_20CE4__fzgx_offset_0, (u32)lbl_1_data_20CEC__fzgx_offset_0, (u32)lbl_1_data_20CF0__fzgx_offset_0, (u32)lbl_1_data_20CF4__fzgx_offset_0, (u32)lbl_1_data_20D00__fzgx_offset_0, (u32)lbl_1_data_20D08__fzgx_offset_0, (u32)lbl_1_data_20D0C__fzgx_offset_0, (u32)lbl_1_data_20D10__fzgx_offset_0, 0x837D8343, 0x83658342, 0x815B2083, 0x4B835B83, 0x8B000000, 0x83578387, 0x83668342, 0x20835483, 0x7D815B00, 0x8368834E, 0x835E815B, 0x20835883, 0x60838583, 0x8F815B83, 0x67000000, 0x836F836F, 0x00000000, 0x83548380, 0x83898343, 0x20835383, 0x8D815B00, 0x83738352, 0x00000000, 0x834C8383, 0x83768365, 0x83932083, 0x74834083, 0x8B835283, 0x93000000, 0x8349834E, 0x8367837D, 0x83930000, 0x837E8358, 0x835E815B, 0x20834381, 0x5B814583, 0x47834381, 0x45836683, 0x42000000, 0x83578346, 0x815B8380, 0x83592083, 0x7D834E83, 0x89834583, 0x68000000, 0x8372838A, 0x815B0000, 0x83508343, 0x83672083, 0x41838C83, 0x93000000, 0x835D815B, 0x835F0000, 0x83578383, 0x8362834E, 0x20838C83, 0x72839300, 0x836F8343, 0x83492083, 0x8C836283, 0x4E835800, 0x83552083, 0x58834A83, 0x8B000000, 0x83418393, 0x8367836A, 0x83492083, 0x4B835883, 0x5E815B00, 0x8372815B, 0x83588367, 0x837D8393, 0x00000000, 0x838C8349, 0x83930000, 0x8358815B, 0x8370815B, 0x20834183, 0x8D815B00, 0x837E835A, 0x83582083, 0x41838D81, 0x5B000000, 0x8353837D, 0x815B8195, 0x83568349, 0x815B0000, 0x8356838B, 0x836F815B, 0x20836A81, 0x5B838B83, 0x5A839300, 0x837D8343, 0x8350838B, 0x20836083, 0x46815B83, 0x93000000, 0x83758389, 0x83628368, 0x20837483, 0x40838B83, 0x52839300, 0x83578387, 0x83932083, 0x5E836983, 0x4A000000, 0x83688389, 0x834E0000, 0x838D8357, 0x8383815B, 0x20836F83, 0x58835E81, 0x5B000000, 0x8368834E, 0x835E815B, 0x20834E83, 0x89836283, 0x56838500, 0x83758389, 0x8362834E, 0x20835683, 0x83836881, 0x5B000000, 0x83668358, 0x837B815B, 0x83930000, 0x83688393, 0x20835781, 0x5B836A81, 0x5B000000, 0x83668357, 0x20837B81, 0x5B834300, 0x835F8343, 0x81458354, 0x83938145, 0x83518393, 0x00000000, 0x83588379, 0x815B8368, 0x00000000, 0x835F8343, 0x8353838D, 0x815B0000, 0x8376838A, 0x83938356, 0x83410000, 0x838A838A, 0x815B0000, 0x8373815B, 0x83578346, 0x83430000, 0x834C8385, 0x815B8358, 0x838A815B, 0x00000000, 0x83748346, 0x836A8362, 0x834E8358, 0x00000000, 0x8353837D, 0x815B0000, 0x83548393, 0x00000000, 0x83518393, 0x00000000, 0x83438393, 0x835E8372, 0x8385838F, 0x815B0000, (u32)lbl_1_data_20DD0__fzgx_offset_0, (u32)lbl_1_data_20DE4__fzgx_offset_0, (u32)lbl_1_data_20DF4__fzgx_offset_0, (u32)lbl_1_data_20E0C__fzgx_offset_0, (u32)lbl_1_data_20E14__fzgx_offset_0, (u32)lbl_1_data_20E24__fzgx_offset_0, (u32)lbl_1_data_20E2C__fzgx_offset_0, (u32)lbl_1_data_20E44__fzgx_offset_0, (u32)lbl_1_data_20E50__fzgx_offset_0, (u32)lbl_1_data_20E6C__fzgx_offset_0, (u32)lbl_1_data_20E84__fzgx_offset_0, (u32)lbl_1_data_20E8C__fzgx_offset_0, (u32)lbl_1_data_20E9C__fzgx_offset_0, (u32)lbl_1_data_20EA4__fzgx_offset_0, (u32)lbl_1_data_20EB4__fzgx_offset_0, (u32)lbl_1_data_20EC4__fzgx_offset_0, (u32)lbl_1_data_20ED0__fzgx_offset_0, (u32)lbl_1_data_20EE4__fzgx_offset_0, (u32)lbl_1_data_20EF4__fzgx_offset_0, (u32)lbl_1_data_20EFC__fzgx_offset_0, (u32)lbl_1_data_20F0C__fzgx_offset_0, (u32)lbl_1_data_20F1C__fzgx_offset_0, (u32)lbl_1_data_20F2C__fzgx_offset_0, (u32)lbl_1_data_20F40__fzgx_offset_0, (u32)lbl_1_data_20F54__fzgx_offset_0, (u32)lbl_1_data_20F68__fzgx_offset_0, (u32)lbl_1_data_20F78__fzgx_offset_0, (u32)lbl_1_data_20F80__fzgx_offset_0, (u32)lbl_1_data_20F94__fzgx_offset_0, (u32)lbl_1_data_20FA8__fzgx_offset_0, (u32)lbl_1_data_20FBC__fzgx_offset_0, (u32)lbl_1_data_20FC8__fzgx_offset_0, (u32)lbl_1_data_20FD8__fzgx_offset_0, (u32)lbl_1_data_20FE4__fzgx_offset_0, (u32)lbl_1_data_20FF8__fzgx_offset_0, (u32)lbl_1_data_21004__fzgx_offset_0, (u32)lbl_1_data_21010__fzgx_offset_0, (u32)lbl_1_data_2101C__fzgx_offset_0, (u32)lbl_1_data_21024__fzgx_offset_0, (u32)lbl_1_data_21030__fzgx_offset_0, (u32)lbl_1_data_21040__fzgx_offset_0, (u32)lbl_1_data_21050__fzgx_offset_0, (u32)lbl_1_data_21058__fzgx_offset_0, (u32)lbl_1_data_21060__fzgx_offset_0, (u32)lbl_1_data_21068__fzgx_offset_0, 0x4D494748, 0x54592047, 0x415A454C, 0x4C450000, 0x4A4F4459, 0x2053554D, 0x4D455200, 0x44722E20, 0x53544557, 0x41525400, 0x53414D55, 0x52414920, 0x474F524F, 0x48000000, 0x43415054, 0x41494E20, 0x46414C43, 0x4F4E0000, 0x4F43544F, 0x4D414E00, 0x4D722E20, 0x45414400, 0x4A414D45, 0x53204D63, 0x434C4F55, 0x44000000, 0x4B415445, 0x20414C45, 0x4E000000, 0x4A41434B, 0x204C4556, 0x494E0000, 0x42494F20, 0x52455800, 0x54484520, 0x534B554C, 0x4C000000, 0x414E544F, 0x4E494F20, 0x47555354, 0x45520000, 0x53555045, 0x52204152, 0x524F5700, 0x4D72732E, 0x20415252, 0x4F570000, 0x474F4D41, 0x52202620, 0x5348494F, 0x48000000, 0x53494C56, 0x4552204E, 0x45454C53, 0x454E0000, 0x4D494348, 0x41454C20, 0x43484149, 0x4E000000, 0x424C4F4F, 0x44204641, 0x4C434F4E, 0x00000000, 0x4A4F484E, 0x2054414E, 0x414B4100, 0x524F4745, 0x52204255, 0x53544552, 0x00000000, 0x44722E20, 0x434C4153, 0x48000000, 0x424C4143, 0x4B205348, 0x41444F57, 0x00000000, 0x44454154, 0x48424F52, 0x4E000000, 0x444F4E20, 0x47454E49, 0x45000000, 0x44494749, 0x2D424F59, 0x00000000, 0x44414920, 0x53414E20, 0x47454E00, 0x5052494E, 0x43494100, 0x50484F45, 0x4E495800, 0x474F4D41, 0x52000000, (u32)lbl_1_data_2112C__fzgx_offset_0, (u32)lbl_1_data_2113C__fzgx_offset_0, (u32)lbl_1_data_21148__fzgx_offset_0, (u32)lbl_1_data_209D8__fzgx_offset_0, (u32)lbl_1_data_21154__fzgx_offset_0, (u32)lbl_1_data_209E8__fzgx_offset_0, (u32)lbl_1_data_21164__fzgx_offset_0, (u32)lbl_1_data_21174__fzgx_offset_0, (u32)lbl_1_data_2117C__fzgx_offset_0, (u32)lbl_1_data_21184__fzgx_offset_0, (u32)lbl_1_data_20A0C__fzgx_offset_0, (u32)lbl_1_data_21194__fzgx_offset_0, (u32)lbl_1_data_20A1C__fzgx_offset_0, (u32)lbl_1_data_211A0__fzgx_offset_0, (u32)lbl_1_data_211AC__fzgx_offset_0, (u32)lbl_1_data_211B4__fzgx_offset_0, (u32)lbl_1_data_211C0__fzgx_offset_0, (u32)lbl_1_data_20A40__fzgx_offset_0, (u32)lbl_1_data_20A4C__fzgx_offset_0, (u32)lbl_1_data_211D0__fzgx_offset_0, (u32)lbl_1_data_211DC__fzgx_offset_0, (u32)lbl_1_data_211E8__fzgx_offset_0, (u32)lbl_1_data_211F8__fzgx_offset_0, (u32)lbl_1_data_21208__fzgx_offset_0, (u32)lbl_1_data_21218__fzgx_offset_0, (u32)lbl_1_data_21228__fzgx_offset_0, (u32)lbl_1_data_20A88__fzgx_offset_0, (u32)lbl_1_data_21234__fzgx_offset_0, (u32)lbl_1_data_21244__fzgx_offset_0, (u32)lbl_1_data_21250__fzgx_offset_0, (u32)lbl_1_data_21260__fzgx_offset_0, (u32)lbl_1_data_2126C__fzgx_offset_0, (u32)lbl_1_data_21278__fzgx_offset_0, (u32)lbl_1_data_21284__fzgx_offset_0, (u32)lbl_1_data_20AC0__fzgx_offset_0, (u32)lbl_1_data_20AC8__fzgx_offset_0, (u32)lbl_1_data_21290__fzgx_offset_0, (u32)lbl_1_data_20ADC__fzgx_offset_0, (u32)lbl_1_data_20AE4__fzgx_offset_0, (u32)lbl_1_data_20AE8__fzgx_offset_0, (u32)lbl_1_data_21298__fzgx_offset_0, (u32)lbl_1_data_212A0__fzgx_offset_0, (u32)lbl_1_data_20B00__fzgx_offset_0, (u32)lbl_1_data_20B04__fzgx_offset_0, (u32)lbl_1_data_20B08__fzgx_offset_0, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E1D, 0x1E1F2021, 0x22232427, 0x282B2C00, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x0205080B, 0x0E0F1113, 0x14161B1E, 0x22232425, 0x292A2B2C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01030506, 0x07080B0C, 0x0D101718, 0x1A1B1213, 0x15160000, 0x01030506, 0x07080B0C, 0x0D101718, 0x1A1B1213, 0x15160000, 0x00010304, 0x05070809, 0x0A0C0D0E, 0x1011121D, 0x1E1F2021, 0x22232426, 0x2728292A, 0x2B2C2D00, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010304, 0x05070809, 0x0A101112, 0x0C0D0E1D, 0x1E1F2021, 0x22232426, 0x2728292A, 0x2B2C2D00, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x1011121D, 0x1E1F2021, 0x22232426, 0x2728292A, 0x2B2C2D19, 0x1A1B1516, 0x17000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01050708, 0x0A0C0D0F, 0x1017181A, 0x12131500, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x00010304, 0x05070809, 0x0A101112, 0x0C0D0E2B, 0x2C272822, 0x23241E1F, 0x20000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01030507, 0x080A0C0D, 0x0F101213, 0x1517181A, 0x10121315, 0x17181A01, 0x03050708, 0x0A0C0D0F, 0x01030507, 0x080C0D10, 0x010B0C0D, 0x06070805, 0x10121315, 0x1617181A, 0x1B000000, 0x010B0C0D, 0x06070805, 0x10121315, 0x1617181A, 0x1B000000, 0x001E1F20, 0x2223242C, 0x2813191A, 0x1B151617, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0305, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0305, 0x10010C0D, 0x07080305, 0x010B0C0D, 0x05060708, 0x1D1E2025, 0x26212223, 0x2428292B, 0x2E2F2C2D, 0x30311012, 0x13151617, 0x181A1B00, 0x010B0C0D, 0x05060708, 0x1D1E2025, 0x26212223, 0x2428292B, 0x2E2F2C2D, 0x30311012, 0x13151617, 0x181A1B00, 0x00010304, 0x05070809, 0x0A0C0D0E, 0x10111219, 0x1A1B1516, 0x17000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x0C0D0F05, 0x07080A1D, 0x1E282900, 0x10121315, 0x17181A01, 0x0C0D0F05, 0x07080A1D, 0x1E282900, 0x10010C0D, 0x05070800, 0x0103050B, 0x0C0D0607, 0x08101213, 0x15161718, 0x1A1B0000, 0x0103050B, 0x0C0D0607, 0x08101213, 0x15161718, 0x1A1B0000, 0x00010304, 0x05070809, 0x1011120C, 0x0D0E1319, 0x1A1B1516, 0x172B2C2D, 0x27282922, 0x23241E1F, 0x20000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x03050C0D, 0x07080000, 0x000F1001, 0x02030405, 0x06070809, 0x0A0B0C00, 0x0103050C, 0x0D0F0708, 0x0A101213, 0x1517181A, 0x01050C0D, 0x07081012, 0x17000000, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111219, 0x1A1B1516, 0x171D1E1F, 0x20212223, 0x24262728, 0x292A2B2C, 0x2D2F3000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01000000, 0x10121315, 0x1617181A, 0x1B01050C, 0x0D0F0708, 0x0A000000, 0x10121315, 0x1617181A, 0x1B01050C, 0x0D0E0708, 0x09000000, 0x10121701, 0x050C0D07, 0x08000000, 0x01060708, 0x0B0C0D03, 0x05101213, 0x15161D1E, 0x2017181A, 0x1B000000, 0x01060708, 0x0B0C0D03, 0x05101213, 0x15161D1E, 0x2017181A, 0x1B000000, 0x00010304, 0x05070809, 0x0A101112, 0x0C0D0E15, 0x1617191A, 0x1B000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x0107080A, 0x0C0D0F05, 0x10121315, 0x1D1E1F17, 0x181A0000, 0x0107080A, 0x0C0D0F05, 0x10121315, 0x1D1E1F17, 0x181A0000, 0x0107080C, 0x0D051000, 0x01060708, 0x0B0C0D10, 0x12131516, 0x17181A1B, 0x01060708, 0x0B0C0D10, 0x12131516, 0x17181A1B, 0x00010304, 0x05070809, 0x0A0C0D0E, 0x1011121D, 0x1E1F2021, 0x2223242A, 0x2B2C2D26, 0x27282919, 0x1A1B1516, 0x17000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01000000, 0x01050708, 0x0A0C0D0F, 0x10121315, 0x17181A00, 0x01050708, 0x0A0C0D0F, 0x10121315, 0x17181A00, 0x01050708, 0x0C0D1000, 0x01050708, 0x0C0D1017, 0x181A1B12, 0x1315161D, 0x20210000, 0x01050708, 0x0C0D1017, 0x181A1B12, 0x1315161D, 0x20210000, 0x00010304, 0x05070809, 0x0C0D0E10, 0x11121D1E, 0x1F202122, 0x23242728, 0x292B2C2D, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x1213151D, 0x20010305, 0x07080A0C, 0x0D0F0000, 0x1017181A, 0x1213151D, 0x20010305, 0x07080A0C, 0x0D0F0000, 0x10010507, 0x080A0C0D, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111215, 0x1617191A, 0x1B1E1F20, 0x22232400, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x03050708, 0x0A0C0D0F, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x00010304, 0x05070809, 0x0A101112, 0x0C0D0E2B, 0x2C2D2728, 0x29222324, 0x1E1F2000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x03050708, 0x0A0C0D0F, 0x10121315, 0x17181A01, 0x03050708, 0x0A0C0D0F, 0x10010507, 0x080C0D00, 0x01060708, 0x0B0C0D10, 0x17181A1B, 0x12131516, 0x01060708, 0x0B0C0D10, 0x17181A1B, 0x12131516, 0x002F3000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x0103050B, 0x0C0D0607, 0x08101213, 0x15161718, 0x1A1B0000, 0x0103050B, 0x0C0D0607, 0x08101213, 0x15161718, 0x1A1B0000, 0x00010304, 0x05070809, 0x1011120C, 0x0D0E1319, 0x1A1B1516, 0x172B2C2D, 0x27282922, 0x23241E1F, 0x20000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x03050C0D, 0x07080000, 0x000F1001, 0x02030405, 0x06070809, 0x0A0B0C00, 0x0103050C, 0x0D0F0708, 0x0A101213, 0x1517181A, 0x01050C0D, 0x07081012, 0x17000000, 0x01050B0C, 0x0D060708, 0x1017181A, 0x1B121315, 0x16000000, 0x01050B0C, 0x0D060708, 0x1017181A, 0x1B121315, 0x16000000, 0x00101112, 0x0C0D0E01, 0x03040507, 0x08092B2C, 0x2D272829, 0x2223241E, 0x1F200000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x0103050C, 0x0D070810, 0x17181A12, 0x13150000, 0x000F1001, 0x02030405, 0x06070809, 0x0A0B0C00, 0x0103050C, 0x0D0F0708, 0x0A101718, 0x1A121315, 0x01050C0D, 0x07081000, 0x01030507, 0x080A0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01030507, 0x080A0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0F1011, 0x120B0C0D, 0x0E13191A, 0x1B151617, 0x2F300000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x010B0C0D, 0x06070803, 0x05101213, 0x15161718, 0x1A1B0000, 0x010B0C0D, 0x06070803, 0x05101213, 0x15161718, 0x1A1B0000, 0x00010304, 0x05070809, 0x0A0C0D0E, 0x10111213, 0x15161719, 0x1A1B0000, 0x000D0E0F, 0x10010203, 0x04050607, 0x08090A0B, 0x0C000000, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0305, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0305, 0x10010C0D, 0x07080500, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010304, 0x05070809, 0x0A101112, 0x0C0D0E19, 0x1A1B1516, 0x17000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01030506, 0x07080B0C, 0x0D101213, 0x15161718, 0x1A1B0000, 0x00010708, 0x09030405, 0x0A0F1011, 0x120B0C0D, 0x0E000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111219, 0x1A1B1516, 0x172F3022, 0x23241E1F, 0x202B2C2D, 0x27282900, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x03050C0D, 0x0F07080A, 0x10121315, 0x17181A01, 0x03050C0D, 0x0F07080A, 0x10010305, 0x0C0D0708, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E15, 0x1617191A, 0x1B000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x03050708, 0x0A0C0D0F, 0x10121315, 0x17181A01, 0x03050708, 0x0A0C0D0F, 0x10010507, 0x080C0D00, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111219, 0x1A1B1516, 0x171E1F20, 0x22232427, 0x28292B2C, 0x2D302F00, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x050C0D0F, 0x07080A00, 0x10121315, 0x17181A01, 0x050C0D0F, 0x07080A00, 0x1001050C, 0x0D070800, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111213, 0x15161719, 0x1A1B2F30, 0x1E1F2022, 0x23242728, 0x292B2C2D, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x161D2023, 0x24000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x161D2023, 0x24000000, 0x00010809, 0x0304050A, 0x0C0D0E10, 0x11122F30, 0x2223241E, 0x1F202B2C, 0x2D272800, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x1D202324, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x1D202324, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01060708, 0x0B0C0D03, 0x05101213, 0x15161718, 0x1A1B0000, 0x01060708, 0x0B0C0D03, 0x05101213, 0x15161718, 0x1A1B0000, 0x00010708, 0x09030405, 0x2F302B2C, 0x2D272829, 0x15161719, 0x1A1B0A0F, 0x1011120B, 0x0C0D0E21, 0x2223241D, 0x1E1F2000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x07080A0C, 0x0D0F0500, 0x10121315, 0x17181A01, 0x07080A0C, 0x0D0F0500, 0x10010708, 0x0C0D0500, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111215, 0x1617191A, 0x1B000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x01050708, 0x0C0D1000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111215, 0x1617191A, 0x1B2F301E, 0x1F202223, 0x24272829, 0x2B2C2D00, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E13, 0x191A1B15, 0x16172122, 0x23241D1E, 0x1F200000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01000000, 0x10121315, 0x17181A01, 0x0507080A, 0x0C0D0F00, 0x10121315, 0x17181A01, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x1017181A, 0x1B121315, 0x162B2E2F, 0x26292A01, 0x0C0D0F07, 0x080A1C1F, 0x20212425, 0x1017181A, 0x1B121315, 0x162B2E2F, 0x26292A01, 0x0C0D0F07, 0x080A1C1F, 0x20212425, 0x00030405, 0x0708090C, 0x0D0E1011, 0x121E1F20, 0x2223242B, 0x2C2D2728, 0x29000000, 0x010C0D0F, 0x07080A05, 0x1C1F2021, 0x24251017, 0x181A1213, 0x152B2E2F, 0x26292A00, 0x010C0D0F, 0x07080A05, 0x1C1F2021, 0x24251017, 0x181A1213, 0x152B2E2F, 0x26292A00, 0x010C0D07, 0x08051000, 0x010B0C0D, 0x06070803, 0x05101213, 0x15161718, 0x1A1B0000, 0x010B0C0D, 0x06070803, 0x05101213, 0x15161718, 0x1A1B0000, 0x00010A00, 0x000D0E0F, 0x10010203, 0x04050607, 0x08090A0B, 0x0C000000, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0500, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0500, 0x10121701, 0x0C0D0708, 0x05000000, 0x01060708, 0x0B0C0D05, 0x10121315, 0x1617181A, 0x1B000000, 0x01000000, 0x01060708, 0x0B0C0D05, 0x10121315, 0x1617181A, 0x1B000000, 0x00010A00, 0x000E0F10, 0x0405060A, 0x0B0C0000, 0x0107080A, 0x0C0D0F05, 0x10121315, 0x17181A00, 0x0107080A, 0x0C0D0F05, 0x10121315, 0x17181A00, 0x0107080C, 0x0D051000, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x00010304, 0x05070809, 0x0A101112, 0x0C0D0E15, 0x1617191A, 0x1B222324, 0x1D1E1F20, 0x2A2B2C2D, 0x26272829, 0x302F0000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01050C0D, 0x0F07080A, 0x10121315, 0x17181A00, 0x01050C0D, 0x0F07080A, 0x10121315, 0x17181A00, 0x1001050C, 0x0D070800, 0x01030708, 0x0C0D1017, 0x181A1B12, 0x13151600, 0x01030708, 0x0C0D1017, 0x181A1B12, 0x13151600, 0x0001120E, 0x2E000000, 0x000E0A00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10171201, 0x05070809, 0x0C0D0E00, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x161D2023, 0x26000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x161D2023, 0x26000000, 0x00010A0C, 0x0D0E1011, 0x12000000, 0x000E0F04, 0x050A0B0C, 0x1017181A, 0x1213151D, 0x20232601, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x1213151D, 0x20232601, 0x0507080A, 0x0C0D0F00, 0x101D2023, 0x01050708, 0x0C0D0000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E2F, 0x301D1E1F, 0x20212223, 0x24262728, 0x292A2B2C, 0x2D191A1B, 0x15161700, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01050708, 0x0A0C0D0F, 0x1017181A, 0x12131500, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x0103050B, 0x0C0D0607, 0x08101213, 0x15161718, 0x1A1B0000, 0x0103050B, 0x0C0D0607, 0x08101213, 0x15161718, 0x1A1B0000, 0x00010304, 0x05070809, 0x1011120C, 0x0D0E1319, 0x1A1B1516, 0x172B2C2D, 0x27282922, 0x23241E1F, 0x20000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x03050C0D, 0x07080000, 0x000F1001, 0x02030405, 0x06070809, 0x0A0B0C00, 0x0103050C, 0x0D0F0708, 0x0A101213, 0x1517181A, 0x01050C0D, 0x07081012, 0x17000000, 0x010B0C0D, 0x06070805, 0x1017181A, 0x1B121315, 0x16000000, 0x010B0C0D, 0x06070805, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E22, 0x23241E1F, 0x20272829, 0x2B2C2D00, 0x000D0E0F, 0x10010203, 0x04050607, 0x08090A0B, 0x0C000000, 0x1017181A, 0x12131501, 0x0C0D0F07, 0x080A0500, 0x010C0D0F, 0x07080A05, 0x1017181A, 0x12131500, 0x010C0D07, 0x08051000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111226, 0x2728292A, 0x2B2C2D1D, 0x1E1F2021, 0x22232400, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01060708, 0x050B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01060708, 0x050B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x000F1011, 0x120B0C0D, 0x0E010304, 0x05070809, 0x2223241E, 0x1F202B2C, 0x2D272829, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01070803, 0x050C0D10, 0x17181A12, 0x13150000, 0x000F1001, 0x02030405, 0x06070809, 0x0A0B0C00, 0x0107080A, 0x03050C0D, 0x0F101718, 0x1A121315, 0x01070803, 0x050C0D10, 0x010B0C0D, 0x03050607, 0x08101213, 0x15161718, 0x1A1B0000, 0x01000000, 0x010B0C0D, 0x03050607, 0x08101213, 0x15161718, 0x1A1B0000, 0x00191A1B, 0x15161727, 0x28292B2C, 0x2D1E1F20, 0x2223242E, 0x302F0000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x0C0D0F03, 0x0507080A, 0x10121315, 0x17181A01, 0x0C0D0F03, 0x0507080A, 0x10010C0D, 0x05070800, 0x010B0C0D, 0x06070803, 0x05101213, 0x15161718, 0x1A1B0000, 0x010B0C0D, 0x06070803, 0x05101213, 0x15161718, 0x1A1B0000, 0x00010304, 0x05070809, 0x0A0C0D0E, 0x10111214, 0x15161718, 0x191A1B21, 0x2223241D, 0x1E1F2000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0500, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0500, 0x10010C0D, 0x07080500, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E13, 0x191A1B15, 0x16171D1E, 0x1F202122, 0x23240000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x020B0C06, 0x07000000, 0x1017181A, 0x12131501, 0x03050708, 0x0A0C0D0F, 0x1017181A, 0x12131501, 0x03050708, 0x0A0C0D0F, 0x10010507, 0x080C0D00, 0x010B0C0D, 0x06070805, 0x1017181A, 0x1B121315, 0x16000000, 0x010B0C0D, 0x06070805, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E13, 0x191A1B15, 0x16172B2C, 0x2D272829, 0x2223241E, 0x1F20302F, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0C0D0F07, 0x080A0305, 0x1017181A, 0x12131501, 0x0C0D0F07, 0x080A0305, 0x10010C0D, 0x07080500, 0x01000000, 0x0C000000, 0x07000000, 0x424F4459, 0x00000000, 0x46414345, 0x00000000, 0x48414E44, 0x4C000000, 0x48414E44, 0x52000000, 0x4B415441, 0x41544500, 0x5F424F41, 0x52440000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21A3C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21A64__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21A80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21A80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A3C__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_215F0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21618__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21628__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21628__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21CB4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21CDC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21CF4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21CF4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22334__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2235C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22360__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22360__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22884__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_228AC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_228CC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_228CC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x4B415441, 0x4154455F, 0x52000000, 0x4B415441, 0x4154455F, 0x4C000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21F04__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21F2C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21F50__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21F50__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22DF4__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22E00__fzgx_offset_0, (u32)lbl_1_data_22A18__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21E08__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21E30__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21E54__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21E54__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_222A0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_222D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21660__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_216A8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_216C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_216C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2193C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21964__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21980__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21980__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F535449, 0x434B0000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2221C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22244__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22264__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22264__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23190__fzgx_offset_0, (u32)lbl_1_data_22274__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2255C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22584__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_225AC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_225AC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2146C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21494__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_214B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_214B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22DF4__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22E00__fzgx_offset_0, (u32)lbl_1_data_22A18__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F4D454B, 0x41000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22904__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2292C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2294C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2294C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23420__fzgx_offset_0, (u32)lbl_1_data_2295C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_213EC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21414__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21434__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21434__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22DF4__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22E00__fzgx_offset_0, (u32)lbl_1_data_22A18__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21F88__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21FB0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21FD4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21FD4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F4F574C, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2135C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21384__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_213A0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_213A0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_236B0__fzgx_offset_0, (u32)lbl_1_data_213B0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2200C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2203C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22058__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22058__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21C38__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21C60__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21C7C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21C7C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22120__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22148__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22160__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22160__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21D30__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21D58__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21D70__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21D70__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21E8C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21EB4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21ECC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21ECC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21574__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2159C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_215B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_215B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2267C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_226A4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_226C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_226C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22198__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_221C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_221E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_221E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21BAC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21BD4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21BF0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21BF0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2277C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_227A4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_227C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_227C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_219C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_219E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21A04__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21A04__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2298C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_229B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_229D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_229D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_214EC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21514__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2153C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2153C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21AB8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21AD8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21ADC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21ADC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_224E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22514__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22520__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22520__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22404__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2242C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22454__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22454__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22DF4__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22E00__fzgx_offset_0, (u32)lbl_1_data_22A18__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F4B4154, 0x414E4100, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21798__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_217C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_217E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_217E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24318__fzgx_offset_0, (u32)lbl_1_data_217F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2248C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_224AC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_224B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_224B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21830__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21860__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21878__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21878__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_218B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_218D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21900__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21900__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23190__fzgx_offset_0, (u32)lbl_1_data_21910__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F4F5000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_223A0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_223CC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_223D0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_223D0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24638__fzgx_offset_0, (u32)lbl_1_data_223B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21700__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21728__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2174C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2174C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_225E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2260C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22630__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22630__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21B14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21B3C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21B60__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21B60__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22098__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_220C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_220E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_220E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F434152, 0x445F4A4F, 0x4B455230, 0x31000000, 0x5F434152, 0x445F4A4F, 0x4B455230, 0x32000000, 0x5F434152, 0x445F4A4F, 0x4B455230, 0x33000000, 0x5F434152, 0x445F4A4F, 0x4B455230, 0x34000000, 0x5F434152, 0x445F4143, 0x45303100, 0x5F434152, 0x445F4143, 0x45303200, 0x5F434152, 0x445F4143, 0x45303300, 0x5F434152, 0x445F4143, 0x45303400, 0x5F42414C, 0x4C303100, 0x5F42414C, 0x4C303200, 0x5F42414C, 0x4C303300, 0x5F42414C, 0x4C303400, 0x5F42414C, 0x4C303500, 0x5F42414C, 0x4C303600, 0x5F42414C, 0x4C303700, 0x5F42414C, 0x4C303800, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22808__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22834__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2284C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2284C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_249E4__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_249F4__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A04__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A14__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A24__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A30__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A3C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A48__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A54__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A5C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A64__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A6C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A74__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A7C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A84__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A8C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_226FC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22724__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22744__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22744__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21DA8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21DBC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21DD0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21DD0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x635F6861, 0x72610000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21A90__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21638__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D08__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22374__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_228DC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21F60__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_222F4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_216D0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21990__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21E64__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22278__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23190__fzgx_offset_0, (u32)lbl_1_data_22274__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_225BC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_214C4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22964__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23420__fzgx_offset_0, (u32)lbl_1_data_2295C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21444__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21FE4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22068__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_213C4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_236B0__fzgx_offset_0, (u32)lbl_1_data_213B0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C8C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22170__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21EDC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_215C8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_226D4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_221F4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C00__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21C10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21C10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_227D0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_227E0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_227E0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_229E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21AEC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2154C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22528__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22464__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_217FC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24318__fzgx_offset_0, (u32)lbl_1_data_217F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_224B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21888__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21914__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23190__fzgx_offset_0, (u32)lbl_1_data_21910__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_223DC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24638__fzgx_offset_0, (u32)lbl_1_data_223B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2175C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2176C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2176C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22640__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22650__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22650__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21B70__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21B80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21B80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_220F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2285C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_249E4__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_249F4__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A04__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A14__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A24__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A30__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A3C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A48__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A54__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A5C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A64__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A6C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A74__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A7C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A84__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A8C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22754__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21DE0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21AA0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21648__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D18__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22384__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_228EC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21F70__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22310__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_216E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_219A4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21E74__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22288__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_225CC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_214D4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22974__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21454__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21FF4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2207C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_213D4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C9C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22180__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D90__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21EEC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_215D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_226E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22204__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C20__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_227F0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21A24__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_229F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21AFC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2155C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2253C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22474__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21810__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_224C8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2189C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21924__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_223EC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2177C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22660__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21B90__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22108__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2286C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22764__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21DF0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21AB0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21658__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D28__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22394__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_228FC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21F80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2232C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_216F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_219B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21E84__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22298__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_225DC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_214E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22984__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21464__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22004__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22090__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_213E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21CAC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22190__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21DA0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21EFC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_215E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_226F4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22214__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C30__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22800__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21A34__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22A08__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21B0C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2156C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22550__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22484__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21824__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_224D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_218B0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21934__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_223FC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2178C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22670__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21BA0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22118__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2287C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22774__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21E00__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xB4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xFC000000, 0xFC000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF0000000, (u32)lbl_1_data_240B4__fzgx_offset_0, (u32)lbl_1_data_22E0C__fzgx_offset_0, (u32)lbl_1_data_22D40__fzgx_offset_0, (u32)lbl_1_data_23500__fzgx_offset_0, (u32)lbl_1_data_22BD8__fzgx_offset_0, (u32)lbl_1_data_22C8C__fzgx_offset_0, (u32)lbl_1_data_22A4C__fzgx_offset_0, (u32)lbl_1_data_22FBC__fzgx_offset_0, (u32)lbl_1_data_23E98__fzgx_offset_0, (u32)lbl_1_data_23A60__fzgx_offset_0, (u32)lbl_1_data_24000__fzgx_offset_0, (u32)lbl_1_data_235FC__fzgx_offset_0, (u32)lbl_1_data_23F4C__fzgx_offset_0, (u32)lbl_1_data_22F08__fzgx_offset_0, (u32)lbl_1_data_24168__fzgx_offset_0, (u32)lbl_1_data_23844__fzgx_offset_0, (u32)lbl_1_data_239AC__fzgx_offset_0, (u32)lbl_1_data_23324__fzgx_offset_0, (u32)lbl_1_data_23790__fzgx_offset_0, (u32)lbl_1_data_236B8__fzgx_offset_0, (u32)lbl_1_data_23C7C__fzgx_offset_0, (u32)lbl_1_data_23DE4__fzgx_offset_0, (u32)lbl_1_data_23198__fzgx_offset_0, (u32)lbl_1_data_238F8__fzgx_offset_0, (u32)lbl_1_data_23B14__fzgx_offset_0, (u32)lbl_1_data_23428__fzgx_offset_0, (u32)lbl_1_data_230DC__fzgx_offset_0, (u32)lbl_1_data_23270__fzgx_offset_0, (u32)lbl_1_data_23028__fzgx_offset_0, (u32)lbl_1_data_23BC8__fzgx_offset_0, (u32)lbl_1_data_22B24__fzgx_offset_0, (u32)lbl_1_data_24560__fzgx_offset_0, (u32)lbl_1_data_244AC__fzgx_offset_0, (u32)lbl_1_data_24714__fzgx_offset_0, (u32)lbl_1_data_24A94__fzgx_offset_0, (u32)lbl_1_data_24320__fzgx_offset_0, (u32)lbl_1_data_2421C__fzgx_offset_0, (u32)lbl_1_data_24930__fzgx_offset_0, (u32)lbl_1_data_2463C__fzgx_offset_0, (u32)lbl_1_data_243F8__fzgx_offset_0, (u32)lbl_1_data_24D88__fzgx_offset_0, (u32)lbl_1_data_23D30__fzgx_offset_0, (u32)lbl_1_data_247C8__fzgx_offset_0, (u32)lbl_1_data_2487C__fzgx_offset_0, (u32)lbl_1_data_24E3C__fzgx_offset_0, 0x00000005, 0x00000007, 0x00000005, 0x00000007, 0x00000005, 0x00000005, 0x00000006, 0x00000003, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000007, 0x00000005, 0x00000006, 0x00000005, 0x00000005, 0x00000006, 0x00000005, 0x00000005, 0x00000006, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000006, 0x00000005, 0x00000005, 0x00000015, 0x00000006, 0x00000007, 0x00000005, 0x00000006, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, (u32)lbl_1_data_25408__fzgx_offset_0, (u32)lbl_1_data_24FAC__fzgx_offset_0, (u32)lbl_1_data_24F88__fzgx_offset_0, (u32)lbl_1_data_25138__fzgx_offset_0, (u32)lbl_1_data_24F40__fzgx_offset_0, (u32)lbl_1_data_24F64__fzgx_offset_0, (u32)lbl_1_data_24EF8__fzgx_offset_0, (u32)lbl_1_data_24FD0__fzgx_offset_0, (u32)lbl_1_data_253C0__fzgx_offset_0, (u32)lbl_1_data_25258__fzgx_offset_0, (u32)lbl_1_data_2542C__fzgx_offset_0, (u32)lbl_1_data_2515C__fzgx_offset_0, (u32)lbl_1_data_253E4__fzgx_offset_0, (u32)lbl_1_data_2503C__fzgx_offset_0, (u32)lbl_1_data_25450__fzgx_offset_0, (u32)lbl_1_data_251EC__fzgx_offset_0, (u32)lbl_1_data_25234__fzgx_offset_0, (u32)lbl_1_data_250CC__fzgx_offset_0, (u32)lbl_1_data_25180__fzgx_offset_0, (u32)lbl_1_data_251A4__fzgx_offset_0, (u32)lbl_1_data_252C4__fzgx_offset_0, (u32)lbl_1_data_25354__fzgx_offset_0, (u32)lbl_1_data_25060__fzgx_offset_0, (u32)lbl_1_data_25210__fzgx_offset_0, (u32)lbl_1_data_2527C__fzgx_offset_0, (u32)lbl_1_data_250F0__fzgx_offset_0, (u32)lbl_1_data_25018__fzgx_offset_0, (u32)lbl_1_data_250A8__fzgx_offset_0, (u32)lbl_1_data_24FF4__fzgx_offset_0, (u32)lbl_1_data_252A0__fzgx_offset_0, (u32)lbl_1_data_24F1C__fzgx_offset_0, (u32)lbl_1_data_25528__fzgx_offset_0, (u32)lbl_1_data_25504__fzgx_offset_0, (u32)lbl_1_data_255B8__fzgx_offset_0, (u32)lbl_1_data_25720__fzgx_offset_0, (u32)lbl_1_data_25498__fzgx_offset_0, (u32)lbl_1_data_25474__fzgx_offset_0, (u32)lbl_1_data_256FC__fzgx_offset_0, (u32)lbl_1_data_25570__fzgx_offset_0, (u32)lbl_1_data_254E0__fzgx_offset_0, (u32)lbl_1_data_25984__fzgx_offset_0, (u32)lbl_1_data_252E8__fzgx_offset_0, (u32)lbl_1_data_25624__fzgx_offset_0, (u32)lbl_1_data_25690__fzgx_offset_0, (u32)lbl_1_data_259A8__fzgx_offset_0, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000002, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000011, 0x00000002, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000001, 0x00000003, 0x00000003, 0x00000003, 0x00000001, (u32)lbl_1_data_25DE0__fzgx_offset_0, (u32)lbl_1_data_25A80__fzgx_offset_0, (u32)lbl_1_data_25A5C__fzgx_offset_0, (u32)lbl_1_data_25BC4__fzgx_offset_0, (u32)lbl_1_data_25A14__fzgx_offset_0, (u32)lbl_1_data_25A38__fzgx_offset_0, (u32)lbl_1_data_259CC__fzgx_offset_0, (u32)lbl_1_data_25AA4__fzgx_offset_0, (u32)lbl_1_data_25D98__fzgx_offset_0, (u32)lbl_1_data_25CC0__fzgx_offset_0, (u32)lbl_1_data_25E04__fzgx_offset_0, (u32)lbl_1_data_25BE8__fzgx_offset_0, (u32)lbl_1_data_25DBC__fzgx_offset_0, (u32)lbl_1_data_25B10__fzgx_offset_0, (u32)lbl_1_data_25E28__fzgx_offset_0, (u32)lbl_1_data_25C54__fzgx_offset_0, (u32)lbl_1_data_25C9C__fzgx_offset_0, (u32)lbl_1_data_25B7C__fzgx_offset_0, (u32)lbl_1_data_25C0C__fzgx_offset_0, (u32)lbl_1_data_25C30__fzgx_offset_0, (u32)lbl_1_data_25D2C__fzgx_offset_0, (u32)lbl_1_data_25D74__fzgx_offset_0, (u32)lbl_1_data_25B34__fzgx_offset_0, (u32)lbl_1_data_25C78__fzgx_offset_0, (u32)lbl_1_data_25CE4__fzgx_offset_0, (u32)lbl_1_data_25BA0__fzgx_offset_0, (u32)lbl_1_data_25AEC__fzgx_offset_0, (u32)lbl_1_data_25B58__fzgx_offset_0, (u32)lbl_1_data_25AC8__fzgx_offset_0, (u32)lbl_1_data_25D08__fzgx_offset_0, (u32)lbl_1_data_259F0__fzgx_offset_0, (u32)lbl_1_data_25EDC__fzgx_offset_0, (u32)lbl_1_data_25EB8__fzgx_offset_0, (u32)lbl_1_data_25F24__fzgx_offset_0, (u32)lbl_1_data_25FB4__fzgx_offset_0, (u32)lbl_1_data_25E70__fzgx_offset_0, (u32)lbl_1_data_25E4C__fzgx_offset_0, (u32)lbl_1_data_25F90__fzgx_offset_0, (u32)lbl_1_data_25F00__fzgx_offset_0, (u32)lbl_1_data_25E94__fzgx_offset_0, (u32)lbl_1_data_25FD8__fzgx_offset_0, (u32)lbl_1_data_25D50__fzgx_offset_0, (u32)lbl_1_data_25F48__fzgx_offset_0, (u32)lbl_1_data_25F6C__fzgx_offset_0, (u32)lbl_1_data_25FFC__fzgx_offset_0, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, (u32)lbl_1_data_26434__fzgx_offset_0, (u32)lbl_1_data_260D4__fzgx_offset_0, (u32)lbl_1_data_260B0__fzgx_offset_0, (u32)lbl_1_data_26218__fzgx_offset_0, (u32)lbl_1_data_26068__fzgx_offset_0, (u32)lbl_1_data_2608C__fzgx_offset_0, (u32)lbl_1_data_26020__fzgx_offset_0, (u32)lbl_1_data_260F8__fzgx_offset_0, (u32)lbl_1_data_263EC__fzgx_offset_0, (u32)lbl_1_data_26314__fzgx_offset_0, (u32)lbl_1_data_26458__fzgx_offset_0, (u32)lbl_1_data_2623C__fzgx_offset_0, (u32)lbl_1_data_26410__fzgx_offset_0, (u32)lbl_1_data_26164__fzgx_offset_0, (u32)lbl_1_data_2647C__fzgx_offset_0, (u32)lbl_1_data_262A8__fzgx_offset_0, (u32)lbl_1_data_262F0__fzgx_offset_0, (u32)lbl_1_data_261D0__fzgx_offset_0, (u32)lbl_1_data_26260__fzgx_offset_0, (u32)lbl_1_data_26284__fzgx_offset_0, (u32)lbl_1_data_26380__fzgx_offset_0, (u32)lbl_1_data_263C8__fzgx_offset_0, (u32)lbl_1_data_26188__fzgx_offset_0, (u32)lbl_1_data_262CC__fzgx_offset_0, (u32)lbl_1_data_26338__fzgx_offset_0, (u32)lbl_1_data_261F4__fzgx_offset_0, (u32)lbl_1_data_26140__fzgx_offset_0, (u32)lbl_1_data_261AC__fzgx_offset_0, (u32)lbl_1_data_2611C__fzgx_offset_0, (u32)lbl_1_data_2635C__fzgx_offset_0, (u32)lbl_1_data_26044__fzgx_offset_0, (u32)lbl_1_data_26530__fzgx_offset_0, (u32)lbl_1_data_2650C__fzgx_offset_0, (u32)lbl_1_data_26578__fzgx_offset_0, (u32)lbl_1_data_26608__fzgx_offset_0, (u32)lbl_1_data_264C4__fzgx_offset_0, (u32)lbl_1_data_264A0__fzgx_offset_0, (u32)lbl_1_data_265E4__fzgx_offset_0, (u32)lbl_1_data_26554__fzgx_offset_0, (u32)lbl_1_data_264E8__fzgx_offset_0, (u32)lbl_1_data_2662C__fzgx_offset_0, (u32)lbl_1_data_263A4__fzgx_offset_0, (u32)lbl_1_data_2659C__fzgx_offset_0, (u32)lbl_1_data_265C0__fzgx_offset_0, (u32)lbl_1_data_26650__fzgx_offset_0, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x18000000, 0x00000000, 0x18000000, 0x00010000, 0x18000000, 0x00020000, 0x18000000, 0x00030000, 0x18000000, 0x00040000, 0x18000000, 0x00050000, 0x18000000, 0x00060000, 0x18000000, 0x00070000, 0x18000000, 0x00080000, 0x18000000, 0x00090000, 0x18000000, 0x000A0000, 0x18000000, 0x000B0000, 0x18000000, 0x000C0000, 0x18000000, 0x000D0000, 0x18000000, 0x000E0000, 0x18000000, 0x000F0000, 0x18000000, 0x00100000, 0x00000000, 0x5F313030, 0x30000000, 0x5F353030, 0x00000000, 0x5F313030, 0x00000000, 0x5F333030, 0x30000000, 0x5F637631, 0x00000000, 0x5F637632, 0x00000000, 0x5F637633, 0x00000000, 0x4C49505F, 0x41000000, 0x4C49505F, 0x49000000, 0x4C49505F, 0x55000000, 0x4C49505F, 0x45000000, 0x4C49505F, 0x4F000000, 0x46414345, 0x5F444546, 0x00000000, (u32)lbl_1_data_26D8C__fzgx_offset_0, (u32)lbl_1_data_26D94__fzgx_offset_0, (u32)lbl_1_data_26D9C__fzgx_offset_0, (u32)lbl_1_data_26DA4__fzgx_offset_0, (u32)lbl_1_data_26DAC__fzgx_offset_0, (u32)lbl_1_data_26DB4__fzgx_offset_0, 0x42480000, 0x696E745F, 0x30320000, 0x696E745F, 0x30330000, 0x696E745F, 0x30340000, 0x696E745F, 0x30345F66, 0x65617200, 0x696E745F, 0x30355F66, 0x65617200, 0x696E745F, 0x31340000, 0x696E745F, 0x31350000, 0x696E745F, 0x31360000, 0x696E745F, 0x31380000, 0x696E745F, 0x32300000, 0x696E745F, 0x32310000, 0x696E745F, 0x32330000, 0x696E745F, 0x32340000, 0x696E745F, 0x32370000, 0x696E745F, 0x32380000, 0x696E745F, 0x33310000, 0x696E745F, 0x33330000, 0x696E745F, 0x33340000, 0x696E745F, 0x33350000, 0x696E745F, 0x33360000, 0x696E745F, 0x33370000, 0x696E745F, 0x35300000, 0x696E745F, 0x35310000, 0x696E745F, 0x35320000, 0x696E745F, 0x636F6D5F, 0x31000000, 0x696E745F, 0x636F6D5F, 0x32000000, 0x696E745F, 0x636F6D5F, 0x33000000, 0x696E745F, 0x636F6D5F, 0x34000000, 0x696E745F, 0x636F6D5F, 0x35000000, 0x696E745F, 0x636F6D5F, 0x36000000, 0x696E745F, 0x636F6D5F, 0x37000000, 0x696E745F, 0x636F6D5F, 0x38000000, 0x696E745F, 0x636F6D5F, 0x39000000, 0x696E745F, 0x636F6D5F, 0x31300000, 0x696E745F, 0x636F6D32, 0x5F310000, 0x696E745F, 0x636F6D32, 0x5F320000, 0x696E745F, 0x636F6D32, 0x5F330000, 0x696E745F, 0x636F6D32, 0x5F340000, 0x696E745F, 0x636F6D32, 0x5F350000, 0x696E745F, 0x636F6D32, 0x5F360000, 0x696E745F, 0x636F6D32, 0x5F370000, 0x696E745F, 0x636F6D32, 0x5F380000, 0x696E745F, 0x636F6D32, 0x5F390000, 0x696E745F, 0x636F6D32, 0x5F313000, (u32)lbl_1_data_26DDC__fzgx_offset_0, (u32)lbl_1_data_26DE4__fzgx_offset_0, (u32)lbl_1_data_26DEC__fzgx_offset_0, (u32)lbl_1_data_26DF4__fzgx_offset_0, (u32)lbl_1_data_26E00__fzgx_offset_0, (u32)lbl_1_data_26E0C__fzgx_offset_0, (u32)lbl_1_data_26E14__fzgx_offset_0, (u32)lbl_1_data_26E1C__fzgx_offset_0, (u32)lbl_1_data_26E24__fzgx_offset_0, (u32)lbl_1_data_26E2C__fzgx_offset_0, (u32)lbl_1_data_26E34__fzgx_offset_0, (u32)lbl_1_data_26E3C__fzgx_offset_0, (u32)lbl_1_data_26E44__fzgx_offset_0, (u32)lbl_1_data_26E4C__fzgx_offset_0, (u32)lbl_1_data_26E54__fzgx_offset_0, (u32)lbl_1_data_26E5C__fzgx_offset_0, (u32)lbl_1_data_26E5C__fzgx_offset_0, (u32)lbl_1_data_26E64__fzgx_offset_0, (u32)lbl_1_data_26E6C__fzgx_offset_0, (u32)lbl_1_data_26E74__fzgx_offset_0, (u32)lbl_1_data_26E7C__fzgx_offset_0, (u32)lbl_1_data_26E84__fzgx_offset_0, (u32)lbl_1_data_26E8C__fzgx_offset_0, (u32)lbl_1_data_26E94__fzgx_offset_0, (u32)lbl_1_data_26E9C__fzgx_offset_0, (u32)lbl_1_data_26EA4__fzgx_offset_0, (u32)lbl_1_data_26EB0__fzgx_offset_0, (u32)lbl_1_data_26EBC__fzgx_offset_0, (u32)lbl_1_data_26EC8__fzgx_offset_0, (u32)lbl_1_data_26ED4__fzgx_offset_0, (u32)lbl_1_data_26EE0__fzgx_offset_0, (u32)lbl_1_data_26EEC__fzgx_offset_0, (u32)lbl_1_data_26EF8__fzgx_offset_0, (u32)lbl_1_data_26F04__fzgx_offset_0, (u32)lbl_1_data_26F10__fzgx_offset_0, (u32)lbl_1_data_26F1C__fzgx_offset_0, (u32)lbl_1_data_26F28__fzgx_offset_0, (u32)lbl_1_data_26F34__fzgx_offset_0, (u32)lbl_1_data_26F40__fzgx_offset_0, (u32)lbl_1_data_26F4C__fzgx_offset_0, (u32)lbl_1_data_26F58__fzgx_offset_0, (u32)lbl_1_data_26F64__fzgx_offset_0, (u32)lbl_1_data_26F70__fzgx_offset_0, (u32)lbl_1_data_26F7C__fzgx_offset_0, (u32)lbl_1_data_26F88__fzgx_offset_0, 0x67617A65, 0x6C6C655F, 0x626F6172, 0x64000000, 0x424F4152, 0x44000000, 0x6A6F6479, 0x5F626F61, 0x72640000, 0x73746577, 0x6172745F, 0x626F6172, 0x64000000, 0x62616261, 0x5F626F61, 0x72640000, 0x676F726F, 0x685F626F, 0x61726400, 0x7069636F, 0x5F626F61, 0x72640000, 0x66616C63, 0x6F6E5F62, 0x6F617264, 0x00000000, 0x6F63746D, 0x616E5F62, 0x6F617264, 0x00000000, 0x6561645F, 0x626F6172, 0x64000000, 0x6A616D65, 0x735F626F, 0x61726400, 0x62696C6C, 0x795F626F, 0x61726400, 0x6B617465, 0x5F626F61, 0x72640000, 0x7A6F6461, 0x5F626F61, 0x72640000, 0x6A61636B, 0x5F626F61, 0x72640000, 0x7265785F, 0x626F6172, 0x64000000, 0x676F7264, 0x6F6E5F62, 0x6F617264, 0x00000000, 0x67757374, 0x65725F62, 0x6F617264, 0x00000000, 0x62656173, 0x746D616E, 0x5F626F61, 0x72640000, 0x6C656F6E, 0x5F626F61, 0x72640000, 0x6172726F, 0x775F626F, 0x61726400, 0x6D72735F, 0x626F6172, 0x64000000, 0x7368696F, 0x5F626F61, 0x72640000, 0x6E65656C, 0x73656E5F, 0x626F6172, 0x64000000, 0x6D696368, 0x61656C5F, 0x626F6172, 0x64000000, 0x626C6F6F, 0x645F626F, 0x61726400, 0x74616E61, 0x6B615F62, 0x6F617264, 0x00000000, 0x64726171, 0x5F626F61, 0x72640000, 0x726F6765, 0x725F626F, 0x61726400, 0x636C6173, 0x685F626F, 0x61726400, 0x73686164, 0x6F775F62, 0x6F617264, 0x00000000, 0x626F7373, 0x5F626F61, 0x72640000, 0x646F6E5F, 0x626F6172, 0x64000000, 0x64696769, 0x626F795F, 0x626F6172, 0x64000000, 0x6461695F, 0x626F6172, 0x64000000, 0x73706164, 0x655F626F, 0x61726400, 0x64616967, 0x6F726F68, 0x5F626F61, 0x72640000, 0x70726973, 0x69615F62, 0x6F617264, 0x00000000, 0x6C696C79, 0x5F626F61, 0x72640000, 0x706A5F62, 0x6F617264, 0x00000000, 0x7171715F, 0x626F6172, 0x64000000, 0x73686572, 0x6C6F636B, 0x5F626F61, 0x72640000, 0x676F6D61, 0x5F626F61, 0x72640000, 0x73616E5F, 0x626F6172, 0x64000000, 0x67656E5F, 0x626F6172, 0x64000000, 0x74616E61, 0x6B615F6D, 0x656B6100, 0x4D454B41, 0x00000000, 0x6172726F, 0x775F6F77, 0x6C000000, 0x4F574C00, 0x6E65656C, 0x73656E5F, 0x73746963, 0x6B000000, 0x54554500, 0x64616967, 0x6F726F68, 0x5F6B6174, 0x616E6100, 0x4B415441, 0x4E410000, 0x646F6E5F, 0x73746963, 0x6B000000, 0x706A5F6F, 0x70000000, 0x4F500000, 0x73706164, 0x655F6361, 0x72645F61, 0x63653031, 0x00000000, 0x43415244, 0x5F414345, 0x30310000, 0x73706164, 0x655F6361, 0x72645F61, 0x63653032, 0x00000000, 0x43415244, 0x5F414345, 0x30320000, 0x73706164, 0x655F6361, 0x72645F61, 0x63653033, 0x00000000, 0x43415244, 0x5F414345, 0x30330000, 0x73706164, 0x655F6361, 0x72645F61, 0x63653034, 0x00000000, 0x43415244, 0x5F414345, 0x30340000, 0x73706164, 0x655F6361, 0x72645F6A, 0x6F6B6572, 0x30310000, 0x43415244, 0x5F4A4F4B, 0x45523031, 0x00000000, 0x73706164, 0x655F6361, 0x72645F6A, 0x6F6B6572, 0x30320000, 0x43415244, 0x5F4A4F4B, 0x45523032, 0x00000000, 0x73706164, 0x655F6361, 0x72645F6A, 0x6F6B6572, 0x30330000, 0x43415244, 0x5F4A4F4B, 0x45523033, 0x00000000, 0x73706164, 0x655F6361, 0x72645F6A, 0x6F6B6572, 0x30340000, 0x43415244, 0x5F4A4F4B, 0x45523034, 0x00000000, 0x73706164, 0x655F6261, 0x6C6C3031, 0x00000000, 0x42414C4C, 0x30310000, 0x73706164, 0x655F6261, 0x6C6C3032, 0x00000000, 0x42414C4C, 0x30320000, 0x73706164, 0x655F6261, 0x6C6C3033, 0x00000000, 0x42414C4C, 0x30330000, 0x73706164, 0x655F6261, 0x6C6C3034, 0x00000000, 0x42414C4C, 0x30340000, 0x73706164, 0x655F6261, 0x6C6C3035, 0x00000000, 0x42414C4C, 0x30350000, 0x73706164, 0x655F6261, 0x6C6C3036, 0x00000000, 0x42414C4C, 0x30360000, 0x73706164, 0x655F6261, 0x6C6C3037, 0x00000000, 0x42414C4C, 0x30370000, 0x73706164, 0x655F6261, 0x6C6C3038, 0x00000000, 0x42414C4C, 0x30380000, 0x00000000, (u32)lbl_1_data_27048__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00010000, (u32)lbl_1_data_27060__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00020000, (u32)lbl_1_data_2706C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00030000, (u32)lbl_1_data_2707C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00040000, (u32)lbl_1_data_27088__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00050000, (u32)lbl_1_data_27094__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00060000, (u32)lbl_1_data_270A0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00070000, (u32)lbl_1_data_270B0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00080000, (u32)lbl_1_data_270C0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00090000, (u32)lbl_1_data_270CC__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000A0000, (u32)lbl_1_data_270D8__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000B0000, (u32)lbl_1_data_270E4__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000C0000, (u32)lbl_1_data_270F0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000D0000, (u32)lbl_1_data_270FC__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000E0000, (u32)lbl_1_data_27108__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000F0000, (u32)lbl_1_data_27114__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00100000, (u32)lbl_1_data_27124__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00110000, (u32)lbl_1_data_27134__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00120000, (u32)lbl_1_data_27144__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00130000, (u32)lbl_1_data_27150__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00140000, (u32)lbl_1_data_2715C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00150000, (u32)lbl_1_data_27168__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00160000, (u32)lbl_1_data_27174__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00170000, (u32)lbl_1_data_27184__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00180000, (u32)lbl_1_data_27194__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00190000, (u32)lbl_1_data_271A0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001A0000, (u32)lbl_1_data_271B0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001B0000, (u32)lbl_1_data_271BC__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001C0000, (u32)lbl_1_data_271C8__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001D0000, (u32)lbl_1_data_271D4__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001E0000, (u32)lbl_1_data_271E4__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001F0000, (u32)lbl_1_data_271F0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00200000, (u32)lbl_1_data_271FC__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00210000, (u32)lbl_1_data_2720C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00220000, (u32)lbl_1_data_27218__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00230000, (u32)lbl_1_data_27224__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00240000, (u32)lbl_1_data_27234__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00250000, (u32)lbl_1_data_27244__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00260000, (u32)lbl_1_data_27250__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00270000, (u32)lbl_1_data_2725C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00280000, (u32)lbl_1_data_27268__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00290000, (u32)lbl_1_data_27278__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x002A0000, (u32)lbl_1_data_27284__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x002B0000, (u32)lbl_1_data_27290__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00190001, (u32)lbl_1_data_2729C__fzgx_offset_0, (u32)lbl_1_data_272A8__fzgx_offset_0, 0x00130001, (u32)lbl_1_data_272B0__fzgx_offset_0, (u32)lbl_1_data_272BC__fzgx_offset_0, 0x00160001, (u32)lbl_1_data_272C0__fzgx_offset_0, (u32)lbl_1_data_272D0__fzgx_offset_0, 0x00230001, (u32)lbl_1_data_272D4__fzgx_offset_0, (u32)lbl_1_data_272E4__fzgx_offset_0, 0x001F0001, (u32)lbl_1_data_272EC__fzgx_offset_0, (u32)lbl_1_data_272D0__fzgx_offset_0, 0x00260001, (u32)lbl_1_data_272F8__fzgx_offset_0, (u32)lbl_1_data_27300__fzgx_offset_0, 0x00220001, (u32)lbl_1_data_27304__fzgx_offset_0, (u32)lbl_1_data_27318__fzgx_offset_0, 0x00220002, (u32)lbl_1_data_27324__fzgx_offset_0, (u32)lbl_1_data_27338__fzgx_offset_0, 0x00220003, (u32)lbl_1_data_27344__fzgx_offset_0, (u32)lbl_1_data_27358__fzgx_offset_0, 0x00220004, (u32)lbl_1_data_27364__fzgx_offset_0, (u32)lbl_1_data_27378__fzgx_offset_0, 0x00220005, (u32)lbl_1_data_27384__fzgx_offset_0, (u32)lbl_1_data_27398__fzgx_offset_0, 0x00220006, (u32)lbl_1_data_273A8__fzgx_offset_0, (u32)lbl_1_data_273BC__fzgx_offset_0, 0x00220007, (u32)lbl_1_data_273CC__fzgx_offset_0, (u32)lbl_1_data_273E0__fzgx_offset_0, 0x00220008, (u32)lbl_1_data_273F0__fzgx_offset_0, (u32)lbl_1_data_27404__fzgx_offset_0, 0x00220009, (u32)lbl_1_data_27414__fzgx_offset_0, (u32)lbl_1_data_27424__fzgx_offset_0, 0x0022000A, (u32)lbl_1_data_2742C__fzgx_offset_0, (u32)lbl_1_data_2743C__fzgx_offset_0, 0x0022000B, (u32)lbl_1_data_27444__fzgx_offset_0, (u32)lbl_1_data_27454__fzgx_offset_0, 0x0022000C, (u32)lbl_1_data_2745C__fzgx_offset_0, (u32)lbl_1_data_2746C__fzgx_offset_0, 0x0022000D, (u32)lbl_1_data_27474__fzgx_offset_0, (u32)lbl_1_data_27484__fzgx_offset_0, 0x0022000E, (u32)lbl_1_data_2748C__fzgx_offset_0, (u32)lbl_1_data_2749C__fzgx_offset_0, 0x0022000F, (u32)lbl_1_data_274A4__fzgx_offset_0, (u32)lbl_1_data_274B4__fzgx_offset_0, 0x00220010, (u32)lbl_1_data_274BC__fzgx_offset_0, (u32)lbl_1_data_274CC__fzgx_offset_0, 0x00000042, 0xC7382A7E, 0x25735F77, 0x696E2E6D, 0x74610000, 0x25735F74, 0x6573742E, 0x6D746100, 0x25735F68, 0x616E642E, 0x6D746100, 0x25735F66, 0x6163652E, 0x6D746100, 0x25735F6C, 0x69702E6D, 0x74610000, 0x25735F65, 0x79652E6D, 0x74610000, 0x25732E6D, 0x74610000, 0x2E6D7461, 0x00000000, 0x25735F63, 0x6F6D6D6F, 0x6E2E6D61, 0x6C000000, 0x54455F52, 0x00000000, 0x54455F52, 0x4D000000, 0x4C495000, 0x45594500, 0x41434345, 0x00000000, 0x2F636861, 0x72612F61, 0x72632F00, 0x5F73656C, 0x00000000, 0x2E617263, 0x2E6C7A00}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_209C0_lock_6ED8[8] = {0x63, 0x68, 0x61, 0x72, 0x61, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_209C0_fmt_6EE0[0xC] = {0x25, 0x73, 0x25, 0x73, 0x25, 0x73, 0x2E, 0x74, 0x70, 0x6C, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union {u32 words[227]; u8 view[0x7278 - 0x6EEC];} fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC = {{0x2E2E0000, 0x46414345, 0x5F4C4155, 0x47480000, 0x626F6479, 0x20000000, 0x68616E64, 0x72000000, 0x68616E64, 0x6C000000, 0x66616365, 0x20000000, 0x6C697020, 0x20000000, 0x65796520, 0x20000000, 0x61636365, 0x20000000, 0x3E000000, 0x20000000, 0x25730000, 0x3A5B2530, 0x33645D00, 0x5B25352E, 0x31662F25, 0x352E3166, 0x5D000000, 0x2573200A, 0x00000000, (u32)lbl_1_bss_6E990__fzgx_offset_0, 0x00000001, 0x25735F25, 0x64000000, 0x3E5B2532, 0x645D2573, 0x200A0000, 0x205B2532, 0x645D2573, 0x200A0000, 0x2D3E204C, 0x69737420, 0x506C6179, 0x20202028, 0x4C522062, 0x7574746F, 0x6E290000, 0x2D3E204E, 0x6F726D61, 0x6C20506C, 0x61792028, 0x4C522062, 0x7574746F, 0x6E290000, 0x5B25735D, 0x200A0000, 0x48490000, 0x33303030, 0x00000000, 0x31303030, 0x00000000, 0x35303000, 0x31303000, 0x63686172, 0x615F636F, 0x6C203A20, 0x5B25645D, 0x0A000000, 0x63686172, 0x5F646973, 0x70203A20, 0x5B25735D, 0x0A000000, 0x4F4E0000, 0x4F464600, 0x62675F63, 0x6F6C6F72, 0x20203A20, 0x5B25735D, 0x0A000000, 0x47524159, 0x00000000, 0x424C4143, 0x4B000000, 0x70657273, 0x70656374, 0x20203A20, 0x5B25342E, 0x31665D0A, 0x00000000, 0x5B25735F, 0x25645D20, 0x0A000000, 0x564F4C20, 0x3A202534, 0x2E326620, 0x0A000000, (u32)fn_1_9012C__fzgx_offset_3D4, (u32)fn_1_9012C__fzgx_offset_40C, (u32)fn_1_9012C__fzgx_offset_440, (u32)fn_1_9012C__fzgx_offset_468, (u32)fn_1_9012C__fzgx_offset_488, (u32)fn_1_9012C__fzgx_offset_4A8, (u32)fn_1_9012C__fzgx_offset_4FC, (u32)fn_1_9012C__fzgx_offset_53C, (u32)fn_1_9012C__fzgx_offset_5B0, (u32)fn_1_9012C__fzgx_offset_624, (u32)fn_1_9012C__fzgx_offset_698, (u32)fn_1_9012C__fzgx_offset_70C, (u32)fn_1_9012C__fzgx_offset_780, (u32)fn_1_9012C__fzgx_offset_7EC, 0x5B25735D, 0x0A000000, 0x2020201F, 0x2025342E, 0x316C660A, 0x00000000, 0x5B454E44, 0x5D0A0000, 0x544F5441, 0x4C5B2535, 0x2E316C66, 0x2F25352E, 0x316C665D, 0x00000000, 0x544F5441, 0x4C5B2D2D, 0x2D2D2D2F, 0x2D2D2D2D, 0x2D5D0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F434152, 0x445F4A4F, 0x4B455200, 0x5F434152, 0x445F4143, 0x45000000, 0x5F42414C, 0x4C000000, 0x25735F54, 0x55450000, 0x25732573, 0x00000000, 0x494E545F, 0x00000000, 0x494E545F, 0x31340000, 0x47555354, 0x45525F48, 0x454C4D45, 0x54000000, 0x47555354, 0x45525F4D, 0x4F484900, 0x47555354, 0x45525F41, 0x46524F00, 0x47555354, 0x45525F4D, 0x4F48495F, 0x44000000, 0x494E545F, 0x31350000, 0x474F524F, 0x485F4649, 0x47555245, 0x00000000, 0x53594152, 0x494E5F52, 0x5F460000, 0x25735F54, 0x455F524D, 0x00000000, 0x25735F54, 0x455F5200, 0x25735F46, 0x41434500, 0x494E5400, 0x494E545F, 0x46414345, 0x5F544553, 0x54000000, 0x25735F4C, 0x49500000, 0x25735F45, 0x59450000, 0x25735F25, 0x73000000, 0x6D6F7469, 0x6F6E0000, 0x25732E73, 0x6B6C0000, 0x25735F68, 0x616E6472, 0x2E736B6C, 0x00000000, 0x25735F68, 0x616E646C, 0x2E736B6C, 0x00000000, 0x25735F66, 0x6163652E, 0x736B6C00, 0x25735F6C, 0x69702E73, 0x6B6C0000, 0x25735F65, 0x79652E73, 0x6B6C0000, 0x2E736B6C, 0x00000000, 0x726F622E, 0x63000000, 0x73616E5F, 0x626F6172, 0x642E736B, 0x6C000000, 0x67656E5F, 0x626F6172, 0x642E736B, 0x6C000000, 0x676F6D61, 0x5F626F61, 0x72642E73, 0x6B6C0000}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_209C0_fmt_7278[0xC] = {0x25, 0x73, 0x25, 0x73, 0x2E, 0x74, 0x70, 0x6C, 0x00, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_209C0_fmt_7284[4] = {0x25, 0x73, 0x25, 0x73}; /* fzgx-allow: A1 measured pool bytes and bindings */


#pragma section code_type ".fzgxpool"
static void fzgx_base_order_data(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references .data before its other sections */
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_209C0_gap_0;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_209C0_lock_6ED8;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_209C0_fmt_6EE0;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_209C0_fmt_7278;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_209C0_fmt_7284;
}
#pragma section code_type ".text"

void fn_1_96230(Fn196230Obj *obj, s32 idx, u32 mask1, u32 mask2, s32 flag) {
    char buf[0x40];
    s32 ok[5][4];
    const char *name;
    s32 i;
    s32 j;
    s32 id;

    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            ok[i][j] = 0;
        }
    }
    name = fzgx_pool_native_lbl_1_data_209C0_names.view[idx];
    for (i = 0; i < 5; i++) {
        if (!MASK_BIT(mask1, i)) {
            continue;
        }
        for (j = 0; j < 4; j++) {
            if (!MASK_BIT(mask2, j)) {
                continue;
            }
            if (flag == 0 && obj->ids[i] != -1 &&
                (mask2 == 0x80000000 || mask2 == 0x40000000 || mask2 == 0x20000000 ||
                 mask2 == 0x10000000)) {
                sprintf(buf, fzgx_pool_native_lbl_1_data_209C0_fmt_6EE0, name, fzgx_pool_sDirs[i], fzgx_pool_sExts[0]);
            } else {
                sprintf(buf, fzgx_pool_native_lbl_1_data_209C0_fmt_6EE0, name, fzgx_pool_sDirs[i], fzgx_pool_sExts[j]);
            }
            if (flag) {
                fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_lock_6ED8);
                ok[i][j] = fn_1_465D0(buf, 1) >= 0;
                fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC.view);
            } else {
                void *file;
                if (obj->ids[i] != -1) {
                    fn_1_12A2B8(1);
                    fn_1_12A2D0(obj->ids[i]);
                } else {
                    fn_1_12A2B8(0);
                }
                fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_lock_6ED8);
                file = fn_1_12AC00(buf);
                obj->files[i][j] = file;
                ok[i][j] = ((u32)file | -(u32)file) >> 31;
                fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC.view);
            }
            if (ok[i][j] == 0) {
                sprintf(buf, fzgx_pool_native_lbl_1_data_209C0_fmt_7278, name, fzgx_pool_sDirs[i]);
                if (flag) {
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_lock_6ED8);
                    ok[i][j] = fn_1_465D0(buf, 1) >= 0;
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC.view);
                } else {
                    void *file;
                    if (obj->ids[i] != -1) {
                        fn_1_12A2B8(1);
                        fn_1_12A2D0(obj->ids[i]);
                    } else {
                        fn_1_12A2B8(0);
                    }
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_lock_6ED8);
                    file = fn_1_12AC00(buf);
                    obj->files[i][j] = file;
                    ok[i][j] = ((u32)file | -(u32)file) >> 31;
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC.view);
                }
            }
        }
        for (j = 0; j < 4; j++) {
            if (ok[i][j]) {
                sprintf(buf, fzgx_pool_native_lbl_1_data_209C0_fmt_7284, name, fzgx_pool_sPacks[i]);
                if (flag) {
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_lock_6ED8);
                    fn_1_465D0(buf, 1);
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC.view);
                } else {
                    if (obj->ids[i] != -1) {
                        fn_1_12A2B8(1);
                        fn_1_12A2D0(obj->ids[i]);
                    } else {
                        fn_1_12A2B8(0);
                    }
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_lock_6ED8);
                    obj->handles[i] = fn_1_12ADA0(buf, obj->files[i][j]);
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC.view);
                }
                break;
            }
        }
    }
    if (flag == 0) {
        Fn196230Obj *scan;
        id = -1;
        for (j = 0, scan = obj; j < 5; scan = (Fn196230Obj *)((u8 *)scan + 4), j++) {
            if (scan->ids[0] != -1) {
                id = obj->ids[j];
                break;
            }
        }
        if (id != -1) {
            fn_1_12A2B8(1);
            fn_1_12A2D0(id);
        } else {
            fn_1_12A2B8(0);
        }
    }
}
/* fzgx:end fn_1_96230 */

/* fzgx:begin fn_1_96630 */
typedef struct Fn196630Object Fn196630Object;

struct Fn196630Object {
    u8 unk_00[0x88];
    void *value_88;
};

void fn_1_96630(Fn196630Object *object, void *arg1, void *arg2) {
    fn_1_96230(object, object->value_88, arg1, arg2, 0);
}
/* fzgx:end fn_1_96630 */

/* fzgx:begin fn_1_96664 */
void fn_1_96664(void *arg0, void *arg1, void *arg2) {
    fn_1_96230(0, arg0, arg1, arg2, 1);
}
/* fzgx:end fn_1_96664 */

/* fzgx:begin fn_1_966A0 */
typedef struct Fn1966A0Object Fn1966A0Object;
struct Fn1966A0Object {
    u32 entries[0x39];
    u32 resource_e4;
    u8 unk_E8[0x10];
    u32 resource_f8;
};

extern void fn_1_12A2D0(s32 arg0);
extern void fn_80071718(u32 arg0);
extern void fn_800711A8(u32 arg0);

void fn_1_966A0(Fn1966A0Object *object) {
    u8 *slot;
    u8 *group;
    u8 *outer;
    int i;
    int j;
    s32 value;
    u8 *walk;

    group = (u8 *)object;
    outer = (u8 *)object;
    for (i = 0; i < 5; i++) {
        slot = group;
        for (j = 0; j < 4; j++) {
            if (((Fn1966A0Object *)slot)->resource_f8 != 0) {
                if (*(s32 *)(outer + 4) != -1) {
                    fn_1_12A2D0(*(s32 *)(outer + 4));
                }
                fn_80071718(((Fn1966A0Object *)slot)->resource_f8);
                ((Fn1966A0Object *)slot)->resource_f8 = 0;
            }
            slot += 4;
        }
        if (((Fn1966A0Object *)outer)->resource_e4 != 0) {
            if (*(s32 *)(outer + 4) != -1) {
                fn_1_12A2D0(*(s32 *)(outer + 4));
            }
            fn_800711A8(((Fn1966A0Object *)outer)->resource_e4);
            ((Fn1966A0Object *)outer)->resource_e4 = 0;
        }
        group += 0x10;
        outer += 4;
    }

    value = -1;
    walk = (u8 *)object;
    for (i = 0; i < 5; i++) {
        if (*(s32 *)(walk + 4) != -1) {
            value = object->entries[i + 1];
            break;
        }
        walk += 4;
    }
    if (value != -1) {
        fn_1_12A2D0(value);
    }
}
/* fzgx:end fn_1_966A0 */

/* fzgx:begin fn_1_968FC */
typedef struct Fn1968FCChild Fn1968FCChild;
typedef struct Fn1968FCObject Fn1968FCObject;

struct Fn1968FCChild {
    u8 unk_00[0x08];
    u32 unk_08;
    u8 unk_0c[0x10];
    u32 unk_1c;
};

struct Fn1968FCObject {
    u8 unk_00[0x1c];
    Fn1968FCChild *unk_1c;
    void *unk_20;
};

void fn_1_968FC(Fn1968FCObject *object) {
    if (object->unk_20 != 0) {
        fn_1_12ABB4(object->unk_20);
        object->unk_20 = 0;
    }

    if (object->unk_1c != 0) {
        object->unk_1c->unk_1c = 0;
        object->unk_1c->unk_08 = 0;
        fn_1_41850(object->unk_1c);
        object->unk_1c = 0;
    }
}
/* fzgx:end fn_1_968FC */

/* fzgx:begin fn_1_96AE8 */
void fn_1_96AE8(void *base, void *arg1) {
    fn_1_96B14(base, arg1, lbl_1_bss_6E98C);
}
/* fzgx:end fn_1_96AE8 */

/* fzgx:begin fn_1_96C40 */
#include "dolphin/hw_regs.h"

extern void fn_1_12ABB4(void *arg0);
extern void fn_1_96230(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_41850(void *arg0);
extern u32 lbl_1_bss_6E98C;
extern u16 fn_1_96B14(void *base, void *arg1, s32 index);
extern s32 fn_80083BCC(void *arg0, void *arg1);
extern void ADXT_Stop(u32 arg0);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern void fn_80008BEC(void *, u32, u32);

extern const char *lbl_1_data_20D1C[];
extern void sprintf(char *buffer, u8 *format, ...);
extern s32 fn_1_12A32C(char *buffer);
extern s16 fn_1_98104(void);


typedef struct {
    u8 r, g, b, a;
} RobColor;

extern u32 lbl_801A6D00;
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 lbl_8006DCA4(void);
extern void fn_8003462C(u32, u32, u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_800725DC(RobColor *);
extern void fn_80072614(RobColor *);
extern void fn_80072864(u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);

/* Pool primer: reproduces the TU literal pool (lbl_1_rodata_3E48 .. +0x1D0) ahead of
   this function's own initializers and literals; .fzgxpool is dropped at integration. */
extern void fzgx_sink(const void *p);
extern void fzgx_sinkf(f32 f);
extern s32 fzgx_int;

#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(void) {
    /* lbl_1_rodata_3E48 / 3E70: string pointer tables (relocated words, zero in the file) */
    u32 names[0x49] = {0};

    fzgx_sink(names);
    fzgx_sinkf(0.0f);
    fzgx_sinkf(1.0f);
    fzgx_sinkf(100.0f);
    fzgx_sinkf(180.0f);
    fzgx_sinkf(32767.0f);
    fzgx_sinkf((f32)fzgx_int);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer2(void) {
    u32 words[36] = {
        0xFFFFFFFF, 0xBF800000, 0xFFFFFFFF, 0x425C0000, 0x41F00000, 0x447A0000,
        0x404040FF, 0x00000000, 0x00000000, 0x00000000,
        0x3B963DC5, 0xBD6DD053, 0xBD953A3F, 0x3B963DC5, 0xBD6DD053, 0x3CF0307F,
        0xBB963DC5, 0xBD6DD053, 0xBD953A3F, 0xBB963DC5, 0xBD6DD053, 0x3CF0307F,
        0x43360B61, 0x3E4F5C29, 0x3D851EB8, 0x3DAE147B, 0x3FA99999, 0x9999999A,
        0x3D4CCCCD, 0x3BA3D70A, 0xBC8F5C29, 0x477FFF00, 0x43300000, 0x00000000,
        0x42480000, 0xBF800000,
    };

    fzgx_sink(words);
}

/* GX write-gather FIFO: every store is a hardware write, hence volatile. */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)

#pragma defer_codegen on
static void fn_1_96C40_grid(s32 cx, s32 cz);

void fn_1_96C40(void *arg0) {
    RobColor colA = {0x40, 0x40, 0x60, 0x80};
    RobColor colB = {0x00, 0x00, 0x00, 0x00};
    s32 cx;
    s32 cz;
    RobColor c0;
    RobColor c1;

    lbl_8006DCA4();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    cx = (s32)*(f32 *)((u8 *)arg0 + 0xA8);
    cz = (s32)*(f32 *)((u8 *)arg0 + 0xB0);
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(1);
    c0 = colA;
    fn_800725DC(&c0);
    c1 = colB;
    fn_80072614(&c1);
    fn_800747D0(4, 0, 0, 0, 0, 0, 2);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072EDC(0, 4);
    fn_80072864(0);
    fn_1_96C40_grid(cx, cz);
}

/* Draws a 21x21 checkerboard of unit quads around (cx, cz), one colour per pass. */
static inline void fn_1_96C40_grid(s32 cx, s32 cz) {
    s32 j;
    s32 i;
    s32 pass;
    f32 z1;
    f32 z0;
    f32 x1;
    f32 x0;

    for (pass = 0; pass < 2; pass++) {
        for (i = -10; i <= 10; i++) {
            x0 = (f32)(cx + i) - 0.5f;
            x1 = 0.5f + (f32)(cx + i);
            for (j = -10; j <= 10; j++) {
                if ((u32)pass == ((i + j) & 1)) {
                    continue;
                }
                z0 = (f32)(cz + j) - 0.5f;
                z1 = 0.5f + (f32)(cz + j);
                fn_8003462C(0x80, 7, 4);
                GX_FIFO_F32 = x0;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z0;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = x1;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z0;
                GX_FIFO_F32 = 1.0f;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = x1;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z1;
                GX_FIFO_F32 = 1.0f;
                GX_FIFO_F32 = 1.0f;
                GX_FIFO_F32 = x0;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z1;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = 1.0f;
            }
        }
        {
            RobColor colC = {0x00, 0x20, 0x40, 0x80};

            fn_800725DC(&colC);
        }
    }
}
#pragma defer_codegen reset
/* fzgx:end fn_1_96C40 */

/* fzgx:begin fn_1_97174 */
typedef struct Fn197174Owner Fn197174Owner;
typedef struct Fn197174Root Fn197174Root;
typedef struct Fn197174Entry Fn197174Entry;

struct Fn197174Owner {
    u8 unk_00[0x14];
    u8 *base;
};

struct Fn197174Root {
    u8 unk_00[0x08];
    u16 count;
};

struct Fn197174Entry {
    u8 unk_00[0x1C];
    u32 offset;
};

extern Fn197174Root *fn_1_41BDC(void);
extern Fn197174Entry *fn_1_41B18(Fn197174Owner *owner, void *arg1, s32 index);

s32 fn_1_97174(Fn197174Owner *owner, void *arg1, void *arg2) {
    Fn197174Root *root = fn_1_41BDC();
    s32 index = 0;

    while (index < (s32)root->count) {
        Fn197174Entry *entry = fn_1_41B18(owner, arg1, index);
        if (fn_80083BCC(owner->base + entry->offset, arg2) == 0) {
            return index;
        }
        index++;
    }
    return -1;
}
/* fzgx:end fn_1_97174 */

/* fzgx:begin fn_1_97204 */
extern void fn_1_9724C(void *arg0, void *arg1);
extern u8 fn_1_97F80(void *arg0, void *arg1);

void fn_1_97204(void *arg0, void *arg1) {
    fn_1_9724C(arg0, arg1);
    if (fn_1_97F80(arg0, arg1)) {
        return;
    }
}
/* fzgx:end fn_1_97204 */

/* fzgx:begin fn_1_9724C */
// Loads the active resource value when the initialization check has not completed.
void fn_1_9724C(void) {
    if (fn_1_98104() == 0) {
        ADXT_Stop(lbl_1_bss_6EAD0.unk_0->unk_4);
    }
}
/* fzgx:end fn_1_9724C */

/* fzgx:begin fn_1_97F1C */
typedef struct {
    u8 unk_000[0x4A4];
    s32 unk_4A4;
} Fn197F1CObject;

/* Formats the indexed message and stores its parsed value in the object. */
s16 fn_1_97F1C(Fn197F1CObject *object, s16 index) {
    char buffer[0x80];

    sprintf(buffer, lbl_1_data_27D90, lbl_1_data_20D1C[index]);
    object->unk_4A4 = fn_1_12A32C(buffer);
    return (s16)object->unk_4A4;
}
/* fzgx:end fn_1_97F1C */

/* fzgx:begin fn_1_97F80 noprologue */
#include "types.h"

extern u32 lbl_801A6410;

typedef struct Fn197F80Object Fn197F80Object;
struct Fn197F80Object {
    u8 unk_000[0x488];
    u8 unk_488;
    u8 unk_489;
    u8 unk_48A[0x1A];
    void *unk_4A4;
    void *unk_4A8;
    void *unk_4AC;
    void *unk_4B0;
    void *unk_4B4;
};

extern u32 lbl_1_data_209C0;



extern void *fn_80083970(const char *, const char *);
extern void sprintf(char *, const char *, ...);
extern int fn_80083BCC(const char *, const char *);
extern void fn_1_12A2D0(void *);
extern void fn_1_12A2B8(int);
extern void fn_1_12AB38(const char *);
extern int fn_1_12A8A4(const char *, void **);
extern void *fn_1_4630(u32, u32, const char *, u32);
extern void fn_80083DB0(void *, const char *);
extern u32 strlen(const char *);

u32 fn_1_97F80(Fn197F80Object *rob, const char *name) {
    void *resource = 0;
    char path[0x40];
    u8 *data = (u8 *)&lbl_1_data_209C0;
    u32 length;

    if (name == 0 || fn_80083970(name, (const char *)(data + 0x6390)) == 0) {
        return 0;
    }

    sprintf(path, (const char *)(data + 0x73e0), name);
    if (fn_80083BCC(path, (const char *)(data + 0x73e8)) == 0 ||
        fn_80083BCC(path, (const char *)(data + 0x73f4)) == 0 ||
        fn_80083BCC(path, (const char *)(data + 0x7400)) == 0 ||
        fn_80083BCC(path, (const char *)(data + 0x740c)) == 0) {
        return 1;
    }

    fn_1_12A2D0(rob->unk_4A4);
    fn_1_12A2B8(1);
    fn_1_12AB38((const char *)(data + 0x7418));
    if (fn_1_12A8A4(path, &resource) == 0) {
        return 0;
    }

    fn_1_12AB38((const char *)(data + 0x6eec));
    fn_1_12A2B8(0);
    length = strlen(name);
    rob->unk_488 = 1;
    rob->unk_489 = 1;
    rob->unk_4A8 = resource;
    rob->unk_4AC = *(void **)resource;
    rob->unk_4B0 = (u8 *)resource + 4;
    rob->unk_4B4 = fn_1_4630(*(u32 *)&lbl_801A6410,
                            (length + 0x20) & ~0x1f,
                            (const char *)(data + 0x7240), 0xfa9);
    fn_80083DB0(rob->unk_4B4, name);
    return 1;
}
/* fzgx:end fn_1_97F80 */

/* fzgx:begin fn_1_98104 noprologue */
#include "types.h"

extern u8 lbl_1_data_27C00[0xE0];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern void fn_80008BEC(void *, u32, u32);

typedef struct Fn198104Obj {
    u8 unk_00[0x1C];
    u32 value_1C;
    u8 unk_20[0x0C];
    u32 value_2C;
} Fn198104Obj;

s32 fn_1_98104(Fn198104Obj *obj) {
    Fn198104Obj *ptr = (Fn198104Obj *)((u8 *)obj + 0x488);
    u32 saved;

    if (ptr == 0) {
        return 0;
    }

    saved = ptr->value_1C;
    if (ptr->value_2C != 0) {
        fn_1_46B4(lbl_801A6410, ptr->value_2C, lbl_1_data_27C00, 0xfc0);
        ptr->value_2C = 0;
    }

    fn_80008BEC(ptr, 0, 0x30);
    ptr->value_1C = saved;
    return 1;
}
/* fzgx:end fn_1_98104 */

/* fzgx:begin fn_1_9818C */
extern u32 fn_1_12A734(u32);

s32 fn_1_9818C(u32 arg0) {
    s16 v0;
    s32 v1;
    u32 t0;
    v0 = (s16)arg0;
    v1 = v0;
    if (v0 != -1) {
    t0 = fn_1_12A734(v1);
    v1 = t0;
    v1 = 1;
    } else {
    v1 = 0;
    }
    return v1;
}
/* fzgx:end fn_1_9818C */
