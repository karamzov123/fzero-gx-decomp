#include "types.h"
extern s32 lbl_3_bss_120;
extern u32 lbl_3_bss_F0[12];
extern s32 fn_1_4C10(void);
extern s16 fn_3_B270(void);
extern u16 lbl_1_bss_96A;
extern u32 lbl_3_bss_20850;
extern u32 lbl_3_bss_243A8[6];
extern void fn_1_4A00(s32, s32, u32);
extern u16 lbl_3_bss_20[104];
extern u32 lbl_3_bss_2C7C0[66624];
extern void fn_80008BEC(void *, s32, s32);
extern void fn_1_FDFF4(void);
extern void fn_1_FC4E0(void *, s32);
extern u32 lbl_3_bss_7EBA4;
extern u32 lbl_3_bss_7EBA8;
extern u8 lbl_3_data_11DC[84];
extern u32 lbl_801A6410;
extern void fn_1_7F3AC(u32);
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern void fn_1_BC29C(u32 *arg0);
extern void fn_1_B9C0C(void);
extern char lbl_3_data_1A1C[17];
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char *, ...);
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A14;

/* fzgx:begin fn_3_ACF4 noprologue */
#include "types.h"

typedef struct {
    u8 pad[0x324];
    s32 value;
    u8 tail[0x118];
} CustomizeEntry;

extern u32 lbl_3_bss_F0[12];
extern CustomizeEntry lbl_3_bss_20860[4];
extern u8 lbl_3_bss_21960[10368];
extern s32 lbl_3_data_B8;
extern u32 lbl_3_bss_20850;
extern u32 lbl_1_bss_6D82C;
typedef struct {
    u8 pad[0x3a4];
    u32 field_3a4;
} CustomizeObject;

extern CustomizeObject *lbl_3_bss_7EBA4;
extern u8 lbl_3_data_11DC[84];
extern u32 lbl_3_bss_7EBA8;
extern u32 lbl_801A6410;

extern void fn_1_80F1C(s32, CustomizeEntry *);
extern void fn_1_14DBCC(void *);
extern void fn_80071718(u32);
extern void fn_1_151BDC(s32);
extern void fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern void fn_1_7F3AC(CustomizeObject *);

void fn_3_ACF4(void) {
    s16 index;

    if ((lbl_3_bss_F0[0] & 0x20000000) == 0) {
        index = *(s16 *)((u8 *)lbl_3_bss_F0 + 8);
        if (lbl_3_bss_20860[index].value != -1) {
            fn_1_80F1C((s16)lbl_3_bss_20860[index].value, &lbl_3_bss_20860[index]);
            lbl_3_bss_20860[index].value = -1;
        }
        fn_1_14DBCC((u8 *)lbl_3_bss_21960 + index * 0xa20);
        if (lbl_1_bss_6D82C != 0) {
            fn_80071718(lbl_1_bss_6D82C);
            lbl_1_bss_6D82C = 0;
        }
        fn_1_151BDC(0);
        if (lbl_3_data_B8 != -1) {
            fn_1_435C(lbl_3_bss_20850);
            fn_1_426C(lbl_3_data_B8);
            lbl_3_data_B8 = -1;
        }
    }
    if (lbl_3_bss_7EBA4->field_3a4 != 0) {
        fn_1_7F3AC(lbl_3_bss_7EBA4);
    }
    if (lbl_3_bss_7EBA4 != 0) {
        fn_1_46B4(lbl_801A6410, (u32)lbl_3_bss_7EBA4, lbl_3_data_11DC, 0x11b3);
    }
    if (lbl_3_bss_7EBA8 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_3_bss_7EBA8, lbl_3_data_11DC, 0x11b5);
    }
    lbl_3_bss_7EBA4 = 0;
    lbl_3_bss_7EBA8 = 0;
}
/* fzgx:end fn_3_ACF4 */

/* fzgx:begin fn_3_B5FC */
void fn_3_B5FC(void) {
    u32 flags;
    s32 ready;

    if (lbl_3_bss_120 == -1) {
        fn_1_4C10();
    }

    flags = lbl_3_bss_F0[9];
    if ((flags & (~((u32)-1 >> 1))) != 0 &&
        (flags & 1) == 0 &&
        (lbl_3_bss_F0[0] & 2) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready == 0) {
        if (lbl_3_bss_120 != -1) {
            s32 value = lbl_3_bss_120;
            lbl_3_bss_120 = -1;
            lbl_1_bss_96A = (u16)value;
        } else if (fn_3_B270() == (s16)-1) {
            fn_1_4A00(0, 15, lbl_3_bss_20850);
            lbl_3_bss_243A8[0] = 0;
            lbl_3_bss_120 = 110;
        }
    }
}
/* fzgx:end fn_3_B5FC */

/* fzgx:begin fn_3_B6E4 noprologue */
#include "types.h"

typedef struct Sig_fn_1_A7728_FnA7728Resource {
    u8 pad_104[0x104];
    void *field_104;
    void *field_108;
} Sig_fn_1_A7728_FnA7728Resource;
typedef struct Sig_fn_1_A7728_FnA7728Object {
    u8 pad_394[0x394];
    Sig_fn_1_A7728_FnA7728Resource *field_394;
} Sig_fn_1_A7728_FnA7728Object;
struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct fn_3_B6E4_lbl_3_data_11D4 {
    u32 unk_0;
};
struct fn_3_B6E4_lbl_3_bss_20854 {
    u32 unk_0;
};
struct fn_3_B6E4_lbl_1_bss_6D82C {
    u32 unk_0;
};
struct fn_3_B6E4_lbl_3_data_B8 {
    u32 unk_0;
};
struct fn_3_B6E4_lbl_3_bss_20850 {
    u32 unk_0;
};

extern struct fn_3_B6E4_lbl_1_bss_6D82C lbl_1_bss_6D82C;
extern struct fn_3_B6E4_lbl_3_bss_20850 lbl_3_bss_20850;
extern struct fn_3_B6E4_lbl_3_bss_20854 lbl_3_bss_20854;
extern struct fn_3_B6E4_lbl_3_data_11D4 lbl_3_data_11D4;
extern struct fn_3_B6E4_lbl_3_data_B8 lbl_3_data_B8;
extern u32 fn_1_12A734(u32);
extern u32 lbl_3_bss_8;
extern u32 lbl_3_bss_C;
extern void * fn_1_435C(void *);
extern void fn_1_12A2B8(u32);
extern void fn_1_12A2D0(s32);
extern void fn_1_426C(u32);
extern void fn_1_48140(int);
extern void fn_1_7F934(Sig_fn_1_A7728_FnA7728Object *);
extern void fn_1_F8030(void);
extern void fn_80071718(struct Sig_fn_80071718_fn_80071718_Arg0 *);

#pragma opt_propagation on

void fn_3_B6E4(void) {
    struct { s32 value; } v1;
    u32 v2;
    u32 v3;
    if ((s32)lbl_3_bss_8 != 0 && (s32)lbl_3_bss_C != 0) {
    fn_1_F8030();
    }
    if ((s32)lbl_3_data_11D4.unk_0 != -1) {
    fn_1_12A2B8(1);
    fn_1_12A2D0(lbl_3_data_11D4.unk_0);
    } else {
    fn_1_12A2B8(0);
    }
    for (v1.value = 0; (s16)v1.value < 41; v1.value++) {
    fn_1_7F934((Sig_fn_1_A7728_FnA7728Object *)(((struct fn_3_B6E4_lbl_3_bss_20854 *)&lbl_3_bss_20854)->unk_0 + v1.value * 1088));
    }
    v2 = lbl_1_bss_6D82C.unk_0;
    if (v2 != 0) {
    fn_80071718((struct Sig_fn_80071718_fn_80071718_Arg0 *)v2);
    lbl_1_bss_6D82C.unk_0 = 0;
    }
    v3 = lbl_3_data_11D4.unk_0;
    if ((s32)v3 != -1) {
    fn_1_12A734(v3);
    }
    lbl_3_data_11D4.unk_0 = -1;
    fn_1_12A2B8(0);
    if ((s32)lbl_3_data_B8.unk_0 != -1) {
    fn_1_435C((void *)lbl_3_bss_20850.unk_0);
    fn_1_426C(lbl_3_data_B8.unk_0);
    lbl_3_data_B8.unk_0 = -1;
    }
    fn_1_48140(74);
    fn_1_48140(84);
    fn_1_48140(56);
    fn_1_48140(62);
    fn_1_48140(55);
    fn_1_48140(85);
    fn_1_48140(48);
    fn_1_48140(53);
    fn_1_48140(58);
    fn_1_48140(64);
    fn_1_48140(68);
    fn_1_48140(80);
    fn_1_48140(51);
    fn_1_48140(46);
    fn_1_48140(49);
    fn_1_48140(79);
    fn_1_48140(57);
    fn_1_48140(61);
    fn_1_48140(76);
    fn_1_48140(63);
    fn_1_48140(72);
    fn_1_48140(82);
    fn_1_48140(69);
    fn_1_48140(83);
    fn_1_48140(60);
    fn_1_48140(86);
    fn_1_48140(67);
    fn_1_48140(66);
    fn_1_48140(50);
    fn_1_48140(47);
    fn_1_48140(52);
    fn_1_48140(54);
    fn_1_48140(77);
    fn_1_48140(70);
    fn_1_48140(65);
    fn_1_48140(81);
    fn_1_48140(78);
    fn_1_48140(71);
    fn_1_48140(59);
    fn_1_48140(75);
    fn_1_48140(73);
    fn_1_48140(163);
}
/* fzgx:end fn_3_B6E4 */

/* fzgx:begin fn_3_B984 */
void fn_3_B984(void *entries, u8 *table) {
    u8 i;
    u8 j;
    u32 offset;

    for (i = 0; i < 3; i++) {
        offset = ((u32)i) << 3;
        if (table[offset + 0x81a4] != ((u8 *)lbl_3_bss_20)[offset]) {
            for (j = 0; j < 4; j++) {
                u8 *entry = (u8 *)entries + (u32)j * 0x2060;
                if ((*(u32 *)(entry + 0x24) & ((u32)1 << 31)) != 0) {
                    s16 *field = (s16 *)(entry + 0x20);
                    if (*field == i) {
                        fn_80008BEC(field, 0, 0x2060);
                    }
                }
            }
            fn_1_FDFF4();
            fn_1_FC4E0((u8 *)lbl_3_bss_2C7C0 +
                (s32)((s16 *)lbl_3_bss_F0)[4] * 0x10440, 1);
        }
    }
}
/* fzgx:end fn_3_B984 */

/* fzgx:begin fn_3_BC60 */
void fn_3_BC60(void) {
    u32 *value;

    value = &lbl_3_bss_7EBA4;
    if (*value != 0) {
        fn_1_7F3AC(*value);
    }
    if (lbl_3_bss_7EBA8 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_3_bss_7EBA8, lbl_3_data_11DC, 0x12ad);
    }
    if (lbl_3_bss_7EBA4 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_3_bss_7EBA4, lbl_3_data_11DC, 0x12af);
    }
    lbl_3_bss_7EBA4 = 0;
    lbl_3_bss_7EBA8 = 0;
}
/* fzgx:end fn_3_BC60 */

/* fzgx:begin fn_3_BD00 noprologue */
#include "types.h"

extern u16 lbl_3_bss_F0[24];

void fn_3_BD00(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    *(u32 *)&lbl_3_bss_F0[18] = 0;
    *(u32 *)&lbl_3_bss_F0[18] |= 0x80000000;
    *(u32 *)&lbl_3_bss_F0[18] |= arg3;
    *(s16 *)&lbl_3_bss_F0[20] = arg0;
    *(s16 *)&lbl_3_bss_F0[21] = arg1;
    *(s16 *)&lbl_3_bss_F0[22] = arg2;
}
/* fzgx:end fn_3_BD00 */

/* fzgx:begin fn_3_BD30 noprologue */
#include "types.h"

extern u16 lbl_3_bss_F0[24];

void fn_3_BD30(void) {
    s16 current;
    s16 value;

    if ((*(u32 *)&lbl_3_bss_F0[18] & 0x80000000) == 0) {
        return;
    }
    value = *(s16 *)&lbl_3_bss_F0[20];
    current = *(s16 *)&lbl_3_bss_F0[21];
    current += value;
    *(s16 *)&lbl_3_bss_F0[21] = current;
    if (value <= 0 || current < *(s16 *)&lbl_3_bss_F0[22]) {
        if (value >= 0) {
            return;
        }
        if (*(s16 *)&lbl_3_bss_F0[21] > *(s16 *)&lbl_3_bss_F0[22]) {
            return;
        }
    }
    *(u32 *)&lbl_3_bss_F0[18] = 0;
}
/* fzgx:end fn_3_BD30 */

/* fzgx:begin fn_3_BD98 */
struct CustomizeState {
    u32 flags;
    u8 unk4;
};

extern struct CustomizeState lbl_3_bss_7ED58;
extern u32 lbl_3_data_1A18;
extern void fn_1_B9BE0(void);
extern void fn_1_B9DE8(struct CustomizeState *);

extern u32 fn_3_1307C(void);
extern u32 lbl_3_bss_A1784[5];
extern u32 lbl_3_data_1A10;
extern u32 lbl_3_bss_7EDA0[8];

void fn_3_BD98(void) {
    fn_1_B9BE0();
    fn_1_B9DE8(&lbl_3_bss_7ED58);
    lbl_3_bss_7ED58.flags |= 0x10;
    lbl_3_bss_7ED58.unk4 = 9;
    lbl_3_data_1A18 = 0;
    lbl_3_data_1A10 = fn_3_1307C() & 0xff;
    lbl_3_bss_7EDA0[0] = lbl_3_bss_A1784[0];
}
/* fzgx:end fn_3_BD98 */

/* fzgx:begin fn_3_BE10 */
extern struct fn_3_BE10_lbl_3_bss_7ED58 lbl_3_bss_7ED58;
extern struct fn_3_BE10_lbl_3_bss_A1784 lbl_3_bss_A1784;
extern u32 fn_1_B9BE0(void);
extern u32 fn_1_B9DE8(u32);
extern u32 fn_3_1307C(void);
extern u32 lbl_3_bss_7EDA0;
extern u32 lbl_3_data_1A10;
extern u32 lbl_3_data_1A18;

struct fn_3_BE10_lbl_3_bss_7ED58 {
    u32 unk_0;
    u8 unk_4;
};
struct fn_3_BE10_lbl_3_bss_A1784 {
    u32 unk_0;
};

void fn_3_BE10(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t2;
    fn_1_B9BE0();
    fn_1_B9DE8((u32)&lbl_3_bss_7ED58);
    v0 = lbl_3_bss_7ED58.unk_0;
    v1 = (v0 | 16);
    lbl_3_bss_7ED58.unk_4 = 10;
    lbl_3_bss_7ED58.unk_0 = v1;
    lbl_3_data_1A18 = 0;
    t2 = fn_3_1307C();
    v2 = lbl_3_bss_A1784.unk_0;
    lbl_3_data_1A10 = (t2 & 0xFF);
    lbl_3_bss_7EDA0 = v2;
}
/* fzgx:end fn_3_BE10 */

/* fzgx:begin fn_3_BE88 pool noprologue */
#include "types.h"

extern int fn_1_4C10(void);
extern void fn_3_C128(void);
extern void fn_3_C188(void);
extern void fn_3_C234(void);
extern void fn_3_C28C(void);
extern void fn_3_C328(void);
extern void fn_3_C3B4(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
void (*fzgx_obj_lbl_3_data_1958[6])(void) = {
    fn_3_C128, fn_3_C188, fn_3_C234, fn_3_C28C, fn_3_C328, fn_3_C3B4,
};
char fzgx_obj_lbl_3_data_1970[] = "EMB_MEMCARD_WAIT";
char fzgx_obj_lbl_3_data_1984[] = "EMB_MEMCARD_ACTION_INIT";
char fzgx_obj_lbl_3_data_199C[] = "EMB_MEMCARD_SAVE_PROC";
char fzgx_obj_lbl_3_data_19B4[] = "EMB_MEMCARD_LOAD_PROC";
char fzgx_obj_lbl_3_data_19CC[] = "EMB_MEMCARD_DEL_PROC";
char fzgx_obj_lbl_3_data_19E4[] = "EMB_MEMCARD_FINISH";
char *gap_04_000019F7_data__fzgx_offset_1[6] = {
    fzgx_obj_lbl_3_data_1970,
    fzgx_obj_lbl_3_data_1984,
    fzgx_obj_lbl_3_data_199C,
    fzgx_obj_lbl_3_data_19B4,
    fzgx_obj_lbl_3_data_19CC,
    fzgx_obj_lbl_3_data_19E4,
};
s32 fzgx_obj_lbl_3_data_1A10 = -1;
s32 fzgx_obj_lbl_3_data_1A14 = -1;
s32 fzgx_obj_lbl_3_data_1A18 = -1;

void fn_3_BE88(void) {
    s32 v0;

    if (fn_1_4C10() == 0) {
        v0 = fzgx_obj_lbl_3_data_1A18;
        if (v0 >= 0) {
            fzgx_obj_lbl_3_data_1A14 = v0;
            fzgx_obj_lbl_3_data_1A18 = -1;
        }
        fzgx_obj_lbl_3_data_1958[fzgx_obj_lbl_3_data_1A14]();
    }
}
/* fzgx:end fn_3_BE88 */

/* fzgx:begin fn_3_BEF0 */
extern u32 lbl_3_bss_7ED58[18];
extern void fn_1_BC29C(u32 *);
extern void fn_1_B9C0C(void);

void fn_3_BEF0(void) {
    fn_1_BC29C(lbl_3_bss_7ED58);
    fn_1_B9C0C();
}
/* fzgx:end fn_3_BEF0 */

/* fzgx:begin fn_3_BF1C */
#include "sdk_addresses.h"

extern s32 lbl_3_bss_120;
extern u32 lbl_3_bss_F0[12];
extern s32 fn_1_4C10(void);
extern s16 fn_3_B270(void);
extern u16 lbl_1_bss_96A;
extern u32 lbl_3_bss_20850;
extern u32 lbl_3_bss_243A8[6];
extern void fn_1_4A00(s32, s32, u32);
extern u16 lbl_3_bss_20[104];
extern u32 lbl_3_bss_2C7C0[66624];
extern void fn_80008BEC(void *, s32, s32);
extern void fn_1_FDFF4(void);
extern void fn_1_FC4E0(void *, s32);
extern u32 lbl_3_bss_7EBA4;
extern u32 lbl_3_bss_7EBA8;
extern u8 lbl_3_data_11DC[84];
extern u32 lbl_801A6410;
extern void fn_1_7F3AC(u32);
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern void fn_1_BC29C(u32 *arg0);
extern void fn_1_B9C0C(void);
extern char lbl_3_data_1A1C[17];
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char *, ...);
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A14;


typedef struct Fn3_BF1C_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Fn3_BF1C_Color;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    u64 u64;
    s8 s8;
    s16 s16;
    s32 s32;
    s64 s64;
    f32 f32;
    f64 f64;
} PPCWGPipe;

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

extern s32 lbl_3_bss_A1798;

extern u8 lbl_3_bss_7ED58[];
extern void fn_1_4FD64(void);
extern void fn_80074918(s32, s32, s32);
extern void fn_80074788(s32);
extern void fn_80074660(s32);
extern void fn_80073678(s32);
extern void fn_80073C6C(s32);
extern void fn_800747D0(s32, s32, s32, s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800734A8(s32, s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, s32, s32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072864(s32);
extern void fn_8007245C(s32);
extern void fn_800371F8(s32, Fn3_BF1C_Color);
extern void fn_8003462C(s32, s32, s32);
extern u8 fn_1_B7C00(void);
extern void fn_1_BC310(void *);

void fn_3_BF1C(void) {
    s32 mode;

    if (lbl_3_bss_A1798 == 0) {
        return;
    }
    fn_1_4FD64();
    fn_80074918(0, 7, 0);
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 0xFF, 0xFF, 4);
    fn_80072C24(0, 0xF, 0xF, 0xF, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 1);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80072864(2);
    fn_8007245C(0x200);
    {
        Fn3_BF1C_Color color = {0x00, 0x00, 0x00, 0xA0};

        fn_800371F8(1, color);
    }
    fn_8003462C(0x80, 7, 4);
    GXFIFO.f32 = 0.0f;
    GXFIFO.f32 = 0.0f;
    GXFIFO.f32 = -1.0f;
    GXFIFO.f32 = 640.0f;
    GXFIFO.f32 = 0.0f;
    GXFIFO.f32 = -1.0f;
    GXFIFO.f32 = 640.0f;
    GXFIFO.f32 = 480.0f;
    GXFIFO.f32 = -1.0f;
    GXFIFO.f32 = 0.0f;
    GXFIFO.f32 = 480.0f;
    GXFIFO.f32 = -1.0f;
    if (fn_1_B7C00() != 0) {
        return;
    }
    mode = (s32)lbl_3_data_1A14;
    if (mode == 5 || (u32)(mode - 2) <= 1 || mode == 4) {
        return;
    }
    fn_1_BC310(lbl_3_bss_7ED58);
}
/* fzgx:end fn_3_BF1C */

/* fzgx:begin fn_3_C128 */
extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A18;

extern s8 fn_1_BA144(u32 *);

void fn_3_C128(void) {
    s16 result;

    lbl_3_bss_A179C = 0;
    result = fn_1_BA144(lbl_3_bss_7ED58);
    if (result == 0) {
        lbl_3_data_1A18 = 1;
    } else if (result == 1) {
        lbl_3_bss_A179C = 1;
    }
}
/* fzgx:end fn_3_C128 */

/* fzgx:begin fn_3_C188 */
extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_3_data_1A10;
extern u32 *lbl_3_bss_7EDA0;
extern u32 lbl_3_data_1A18;

extern void fn_1_C0510(u32 *arg0);

void fn_3_C188(void) {
    s8 status;

    status = ((s8 *)lbl_3_bss_7ED58)[0x14];
    if (status == 1) {
        lbl_3_bss_7ED58[2] = lbl_3_bss_7EDA0[lbl_3_data_1A10];
        lbl_3_bss_7ED58[3] = 0x2000;
        lbl_3_bss_7ED58[4] = 4;
        lbl_3_data_1A18 = 2;
    } else if (status == 2) {
        lbl_3_data_1A18 = 3;
    } else if (status == 8) {
        lbl_3_data_1A18 = 4;
    }
    fn_1_C0510(lbl_3_bss_7ED58);
}
/* fzgx:end fn_3_C188 */

/* fzgx:begin fn_3_C234 */
extern char lbl_3_data_1A1C[17];
extern u32 lbl_3_data_1A18;

extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char *, ...);

void fn_3_C234(void) {
    if (!fn_1_B7C00()) {
        if (fn_1_B7CD4() == 0) {
            OSReport(lbl_3_data_1A1C, fn_1_B7C5C());
        }
        lbl_3_data_1A18 = 5;
    }
}
/* fzgx:end fn_3_C234 */

/* fzgx:begin fn_3_C28C noprologue */
#include "types.h"

extern u32 lbl_3_bss_7EDA0[8];
extern u32 lbl_3_data_1958[6];
extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410[1];

extern void fn_80008BA8(u32, u32, u32);
extern void fn_1_46B4(u32, u32, void *, u32);

typedef struct CustomizeData {
    u8 pad0[0xb8];
    u32 index;
    u8 padbc[4];
    u32 state;
    u8 padc4[0x14];
    u8 tail[0xd8 - 0xd8];
} CustomizeData;

void fn_3_C28C(void) {
    CustomizeData *data = (CustomizeData *)lbl_3_data_1958;
    u32 *table = (u32 *)lbl_3_bss_7EDA0[0];
    u32 *work = lbl_3_bss_7ED58;
    fn_80008BA8(table[data->index], work[2], work[3]);
    if (work[2] != 0) {
        fn_1_46B4(lbl_801A6410[0], work[2], &data->tail[0], 0x13c);
        work[2] = 0;
        work[3] = 0;
    }
    data->state = 5;
}
/* fzgx:end fn_3_C28C */

/* fzgx:begin fn_3_C3B4 */
extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A14;
extern u32 lbl_3_data_1A18;

extern void fn_1_BC29C(u32 *arg0);
extern void fn_1_B9C0C(void);

void fn_3_C3B4(void) {
    fn_1_BC29C(lbl_3_bss_7ED58);
    fn_1_B9C0C();
    lbl_3_bss_A179C = 1;
    lbl_3_data_1A14 = -1;
    lbl_3_data_1A18 = -1;
}
/* fzgx:end fn_3_C3B4 */
