/* Non-matching: best partial attempt (97.01% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct Sig_fn_1_95158_Fn195158Object Sig_fn_1_95158_Fn195158Object;
typedef struct Sig_fn_1_95158_Fn195158Data Sig_fn_1_95158_Fn195158Data;
typedef struct Sig_fn_1_95158_Fn195158Car Sig_fn_1_95158_Fn195158Car;
struct Sig_fn_1_95158_Fn195158Object {
    u8 lab_pad[8];
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};
struct Sig_fn_1_95158_Fn195158Data {
    u8 unk_00[0x08];
    Sig_fn_1_95158_Fn195158Object *unk_08;
};
struct Sig_fn_1_95158_Fn195158Car {
    u8 unk_00[0xA0];
    s16 unk_A0;
    s16 unk_A2;
    s16 unk_A4;
    u8 unk_A6[0x02];
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    u8 unk_BC[0x94];
    Sig_fn_1_95158_Fn195158Data *unk_150;
};
typedef struct Sig_fn_1_41418_Fn41418Data {
    u32 count;
    char *strings;
} Sig_fn_1_41418_Fn41418Data;
typedef struct Sig_fn_8006E250_Vec3f {
    f32 x, y, z;
} Sig_fn_8006E250_Vec3f;
typedef struct Sig_fn_1_43120_Fn143120Entry {
    u8 pad0[0x88];
    u8 value0[8];
    f32 x;
    u8 pad94[0x0c];
    f32 y;
    u8 padA4[0x0c];
    f32 z;
} Sig_fn_1_43120_Fn143120Entry;
typedef struct Sig_fn_1_43120_Fn143120Object {
    u8 pad0[8];
    Sig_fn_1_43120_Fn143120Entry *entries;
} Sig_fn_1_43120_Fn143120Object;
typedef struct Sig_fn_1_42E74_Fn142E74Pair {
    u32 a;
    u32 b;
} Sig_fn_1_42E74_Fn142E74Pair;
typedef struct Sig_fn_1_42E74_Fn142E74Entry {
    u8 pad0[0xB8];
    Sig_fn_1_42E74_Fn142E74Pair sourceB8;
    u32 sourceC0;
    Sig_fn_1_42E74_Fn142E74Pair sourceC4;
    u32 sourceCC;
    u8 padD0[0xA4];
    Sig_fn_1_42E74_Fn142E74Pair value174;
    u32 value17C;
    Sig_fn_1_42E74_Fn142E74Pair value180;
    u32 value188;
} Sig_fn_1_42E74_Fn142E74Entry;
typedef struct Sig_fn_1_42E74_Fn142E74Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Sig_fn_1_42E74_Fn142E74Entry *entries;
    u8 padC[0x0C];
    f32 value0;
    f32 value1;
    f32 value2;
    u8 pad24[0x1C];
    u16 flags40;
} Sig_fn_1_42E74_Fn142E74Object;
typedef struct Sig_fn_1_41E34_MotasglistObject {
    u8 pad0[0x4c];
    f32 value;
} Sig_fn_1_41E34_MotasglistObject;
typedef struct Sig_fn_1_41E34_MotasglistEntry {
    u16 value;
    u16 frame;
    s16 offset;
    u8 pad6[2];
    u32 id;
    u8 padC[4];
} Sig_fn_1_41E34_MotasglistEntry;
typedef struct Sig_fn_1_41E34_fn_1_41E34_MotasglistData {
    u8 pad0[8];
    Sig_fn_1_41E34_MotasglistObject *object;
    u8 padC[0x20];
    Sig_fn_1_41E34_MotasglistEntry *entries_a;
    Sig_fn_1_41E34_MotasglistEntry *entries_b;
} Sig_fn_1_41E34_fn_1_41E34_MotasglistData;
typedef struct Sig_fn_1_41E34_MotasglistResult {
    u16 first;
    u16 second;
    f32 value;
    u16 third;
} Sig_fn_1_41E34_MotasglistResult;
typedef struct {
    u8 pad0[0x1c];
    void *field_1c;
} Sig_fn_1_933D8_CarObject;
typedef struct {
    u8 pad0[0x24];
    void *field_24;
} Sig_fn_1_933D8_EventData;
typedef struct {
    u8 pad0[0x8];
    Sig_fn_1_933D8_EventData *field_8;
    void *field_c;
} Sig_fn_1_933D8_EventObject;
typedef struct Sig_fn_1_43058_Fn143058Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    u8 *entries;
    u8 padC[0xC];
    f32 value0;
    f32 value1;
    f32 value2;
} Sig_fn_1_43058_Fn143058Object;

typedef struct {
    u32 w[3];
} fn_1_8F62C_Word3;

struct fn_1_8F62C_lbl_1_rodata_3E48 {
    u8 pad_0[0x124];
    f32 unk_124;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
    f32 unk_134;
    f64 unk_138;
    fn_1_8F62C_Word3 unk_140;
};

extern char * fn_1_41418(Sig_fn_1_41418_Fn41418Data *, u32);
extern int fn_80083BCC(const char *, const char *);
extern s16 lbl_1_bss_960;
extern struct fn_1_8F62C_lbl_1_rodata_3E48 lbl_1_rodata_3E48;
extern u32 fn_1_107C74(u32);
extern u32 fn_1_41CB8(void *);
extern u32 fn_1_97288(u32);
extern u8 lbl_1_data_278B0[];
extern u32 lbl_801A63C0;
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern u8 * fn_80083970(u8 *, const u8 *);
extern void fn_1_41E34(Sig_fn_1_41E34_fn_1_41E34_MotasglistData *, u32, Sig_fn_1_41E34_MotasglistResult *);
extern void fn_1_42E74(Sig_fn_1_42E74_Fn142E74Object *);
extern void fn_1_43058(Sig_fn_1_43058_Fn143058Object *, u32, u32, f32);
extern void fn_1_43120(Sig_fn_1_43120_Fn143120Object *, u32, f32 *);
extern void fn_1_933D8(Sig_fn_1_933D8_CarObject *, Sig_fn_1_933D8_EventObject *, u32);
extern void fn_1_95158(Sig_fn_1_95158_Fn195158Car *);
extern void fn_1_9724C(u32);
extern void fn_8006E250(void *, void *);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E14C(f32);
extern u32 mathutil_mtxA_rotate_x(u32);

static inline u32 fn_1_8F62C_operand(u32 left, u32 right) { return left & right; }
static inline s32 fn_1_8F62C_operand_(s32 right, s32 left) { left &= right; return left; }
static inline u32 fn_1_8F62C_operand__(u32 right, u32 left) { return left & right; }
static inline s32 fn_1_8F62C_operand____operand(s32 right, s32 left) { left &= right; return left; }
static inline u32 fn_1_8F62C_operand___(u32 left, u32 right) { return (fn_1_8F62C_operand____operand(((left)), ((right)))); }
#pragma opt_loop_invariants off
void fn_1_8F62C(u32 arg0) {
    f32 fzgx_live;
    struct fn_1_8F62C_lbl_1_rodata_3E48 *p_lbl_1_rodata_3E48;
    u8 flags[20];
    Sig_fn_8006E250_Vec3f vec;
    Sig_fn_1_41E34_MotasglistResult res_d;
    Sig_fn_1_41E34_MotasglistResult res_c;
    Sig_fn_1_41E34_MotasglistResult res_b;
    Sig_fn_1_41E34_MotasglistResult res_a;
    struct { u32 value; } i_2;
    u32 i;
    struct { char * value; } s1;
    struct { u32 value; } w;
    u32 base;
    u32 obj;
    char *s2;
    s8 on;
    u32 b8;
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    u32 fzgx_loop_i_14169;

    p_lbl_1_rodata_3E48 = (struct fn_1_8F62C_lbl_1_rodata_3E48 *)&lbl_1_rodata_3E48;
    if (arg0 != 0) {
        if ((fn_1_8F62C_operand__((~0x7FFFFFFF), (*(u32 *)((u8 *)arg0 + 0x18)))) == 0) {
            base = *(u32 *)((u8 *)arg0 + 0x150);
            if ((fn_1_8F62C_operand__((4), (*(u16 *)((u8 *)base + 0x40)))) != 0) {
                fn_1_95158((Sig_fn_1_95158_Fn195158Car *)arg0);
            }
            w.value = arg0;
            {
    u32 fzgx_loop_i_5855;
for (fzgx_loop_i_5855 = 0; fzgx_loop_i_5855 < 20; fzgx_loop_i_5855++) {
                if (*(u32 *)((u8 *)w.value + 0x210) != 0 && *(u32 *)((u8 *)w.value + 0x214) != 0) {
                    s1.value = fn_1_41418((Sig_fn_1_41418_Fn41418Data *)*(u32 *)((u8 *)arg0 + 0x154), *(u16 *)((u8 *)arg0 + 0x148));
                    s2 = fn_1_41418((Sig_fn_1_41418_Fn41418Data *)*(u32 *)((u8 *)w.value + 0x214), *(u16 *)((u8 *)w.value + 0x208));
                    flags[fzgx_loop_i_5855] = (fn_80083970((u8 *)s2, (const u8 *)s1.value) != 0);
                } else {
                    flags[fzgx_loop_i_5855] = 0;
                }
                w.value += 0x20;
            }
    i = fzgx_loop_i_5855;
}
            w.value = arg0;
            for (i = 0; i < 5; i++) {
                if (((i * 4 + 0)[flags]) != 0) {
                    obj = *(u32 *)((u8 *)w.value + 0x210);
                    if (obj != 0 && *(u32 *)((u8 *)w.value + 0x214) != 0) {
                        *(f32 *)((u8 *)obj + 0x4c) = *(f32 *)((u8 *)*(u32 *)((u8 *)arg0 + 0x150) + 0x4c);
                    }
                }
                if (flags[i * 3 + 1] != 0) {
                    obj = *(u32 *)((u8 *)w.value + 0x230);
                    if (obj != 0 && *(u32 *)((u8 *)w.value + 0x234) != 0) {
                        *(f32 *)((u8 *)obj + 0x4c) = *(f32 *)((u8 *)*(u32 *)((u8 *)arg0 + 0x150) + 0x4c);
                    }
                }
                if (flags[i * 4 + 2] != 0) {
                    obj = *(u32 *)((u8 *)w.value + 0x250);
                    if (obj != 0 && *(u32 *)((u8 *)w.value + 0x254) != 0) {
                        *(f32 *)((u8 *)obj + 0x4c) = *(f32 *)((u8 *)*(u32 *)((u8 *)arg0 + 0x150) + 0x4c);
                    }
                }
                if (flags[i * 4 + 3] != 0) {
                    obj = *(u32 *)((u8 *)w.value + 0x270);
                    if (obj != 0 && *(u32 *)((u8 *)w.value + 0x274) != 0) {
                        *(f32 *)((u8 *)obj + 0x4c) = *(f32 *)((u8 *)*(u32 *)((u8 *)arg0 + 0x150) + 0x4c);
                    }
                }
                w.value += 0x4;
            }
            if (*(u32 *)((u8 *)arg0 + 0x150) != 0 && *(u32 *)((u8 *)arg0 + 0x154) != 0) {
                fn_1_41CB8((void *)*(u32 *)((u8 *)arg0 + 0x1c));
                if ((fn_1_8F62C_operand__((0x10000000), (*(u32 *)((u8 *)arg0 + 0x18)))) != 0) {
                    i_2.value = *(u32 *)((u8 *)(*(u32 *)((u8 *)arg0 + 0x1c)) + 8);
                    lbl_8006DAEC();
                    lbl_8006D758();
                    f1 = *(f32 *)((u8 *)arg0 + 0xa8);
                    f2 = *(f32 *)((u8 *)arg0 + 0xac) + *(f32 *)((u8 *)arg0 + 0xb4);
                    f3 = *(f32 *)((u8 *)arg0 + 0xb0);
                    lbl_8006E0B4(f1, f2, f3);
                    mathutil_mtxA_rotate_z(*(s16 *)((u8 *)arg0 + 0xa4));
                    mathutil_mtxA_rotate_y(*(s16 *)((u8 *)arg0 + 0xa0));
                    mathutil_mtxA_rotate_x(*(s16 *)((u8 *)arg0 + 0xa2));
                    lbl_8006E14C(*(f32 *)((u8 *)arg0 + 0xb8));
                    fn_8006E250((void *)(arg0 + 0x4d4), (void *)&vec);
                    fn_1_43120((Sig_fn_1_43120_Fn143120Object *)i_2.value, 5, (f32 *)&vec);
                    lbl_8006DB30();
                }
            }
            if (*(u32 *)((u8 *)arg0 + 0x170) != 0 && *(u32 *)((u8 *)arg0 + 0x174) != 0) {
                base = *(u32 *)((u8 *)arg0 + 0x170);
                if ((s32)*(u32 *)((u8 *)arg0 + 0x184) != 0) {
                    fn_1_42E74((Sig_fn_1_42E74_Fn142E74Object *)base);
                    *(fn_1_8F62C_Word3 *)((u8 *)arg0 + 0x178) = p_lbl_1_rodata_3E48->unk_140;
                } else {
                    fn_1_41E34((Sig_fn_1_41E34_fn_1_41E34_MotasglistData *)*(u32 *)((u8 *)arg0 + 0x1c), 1, &res_d);
                    if (*(u16 *)((u8 *)arg0 + 0x17a) != res_d.second ||
                        *(u16 *)((u8 *)arg0 + 0x180) != res_d.third ||
                        *(f32 *)((u8 *)arg0 + 0x17c) != res_d.value) {
                        fn_1_933D8((Sig_fn_1_933D8_CarObject *)arg0, (Sig_fn_1_933D8_EventObject *)(arg0 + 0x168),
                                   (fn_1_8F62C_operand___(((u32)(u16)(res_d.second - 1)), ((u32)(((s32)(-res_d.second | res_d.second)) >> 31)))));
                        *(fn_1_8F62C_Word3 *)((u8 *)arg0 + 0x178) = *(fn_1_8F62C_Word3 *)&res_d;
                    }
                    if ((fn_1_8F62C_operand__((2), (*(u16 *)((u8 *)arg0 + 0x180)))) != 0) {
                        fn_1_42E74((Sig_fn_1_42E74_Fn142E74Object *)*(u32 *)((u8 *)arg0 + 0x170));
                    } else {
                        fn_1_43058((Sig_fn_1_43058_Fn143058Object *)*(u32 *)((u8 *)arg0 + 0x170), 0, 100, res_d.value);
                    }
                }
            }
            if (*(u32 *)((u8 *)arg0 + 0x190) != 0 && *(u32 *)((u8 *)arg0 + 0x194) != 0) {
                base = *(u32 *)((u8 *)arg0 + 0x190);
                if ((s32)*(u32 *)((u8 *)arg0 + 0x1a4) != 0) {
                    fn_1_42E74((Sig_fn_1_42E74_Fn142E74Object *)base);
                    *(fn_1_8F62C_Word3 *)((u8 *)arg0 + 0x198) = p_lbl_1_rodata_3E48->unk_140;
                } else {
                    fn_1_41E34((Sig_fn_1_41E34_fn_1_41E34_MotasglistData *)*(u32 *)((u8 *)arg0 + 0x1c), 0, &res_c);
                    if (*(u16 *)((u8 *)arg0 + 0x19a) != res_c.second ||
                        *(u16 *)((u8 *)arg0 + 0x1a0) != res_c.third ||
                        *(f32 *)((u8 *)arg0 + 0x19c) != res_c.value) {
                        fn_1_933D8((Sig_fn_1_933D8_CarObject *)arg0, (Sig_fn_1_933D8_EventObject *)(arg0 + 0x188),
                                   (fn_1_8F62C_operand___(((u32)(u16)(res_c.second - 1)), ((u32)(((s32)(-res_c.second | res_c.second)) >> 31)))));
                        *(fn_1_8F62C_Word3 *)((u8 *)arg0 + 0x198) = *(fn_1_8F62C_Word3 *)&res_c;
                    }
                    if ((fn_1_8F62C_operand__((2), (*(u16 *)((u8 *)arg0 + 0x1a0)))) != 0) {
                        fn_1_42E74((Sig_fn_1_42E74_Fn142E74Object *)*(u32 *)((u8 *)arg0 + 0x190));
                    } else {
                        fn_1_43058((Sig_fn_1_43058_Fn143058Object *)*(u32 *)((u8 *)arg0 + 0x190), 0, 100, res_c.value);
                    }
                }
            }
            if (*(u32 *)((u8 *)arg0 + 0x1b0) != 0 && *(u32 *)((u8 *)arg0 + 0x1b4) != 0) {
                s1.value = fn_1_41418((Sig_fn_1_41418_Fn41418Data *)*(u32 *)((u8 *)arg0 + 0x1b4), *(u16 *)((u8 *)arg0 + 0x1a8));
                if (fn_80083BCC(s1.value, (const char *)lbl_1_data_278B0) == 0) {
                    base = *(u32 *)((u8 *)arg0 + 0x1b0);
                    f0 = *(f32 *)((u8 *)base + 0x50) - p_lbl_1_rodata_3E48->unk_128;
                    f1 = *(f32 *)((u8 *)base + 0x4c);
                    if (f1 >= f0) {
                        *(f32 *)((u8 *)base + 0x4c) = f0;
                    }
                }
                    if ((s32)*(u32 *)((u8 *)arg0 + 0x1c4) != 0) {
                        fn_1_42E74((Sig_fn_1_42E74_Fn142E74Object *)*(u32 *)((u8 *)arg0 + 0x1b0));
                        *(fn_1_8F62C_Word3 *)((u8 *)arg0 + 0x1b8) = p_lbl_1_rodata_3E48->unk_140;
                    } else {
                    fn_1_41E34((Sig_fn_1_41E34_fn_1_41E34_MotasglistData *)*(u32 *)((u8 *)arg0 + 0x1c), 2, &res_b);
                    if (*(u16 *)((u8 *)arg0 + 0x1ba) != res_b.second ||
                        *(u16 *)((u8 *)arg0 + 0x1c0) != res_b.third ||
                        *(f32 *)((u8 *)arg0 + 0x1bc) != res_b.value) {
                        fn_1_933D8((Sig_fn_1_933D8_CarObject *)arg0, (Sig_fn_1_933D8_EventObject *)(arg0 + 0x1a8),
                                   (fn_1_8F62C_operand___(((u32)(u16)(res_b.second - 1)), ((u32)(((s32)(-res_b.second | res_b.second)) >> 31)))));
                        *(fn_1_8F62C_Word3 *)((u8 *)arg0 + 0x1b8) = *(fn_1_8F62C_Word3 *)&res_b;
                    }
                    if ((fn_1_8F62C_operand__((2), (*(u16 *)((u8 *)arg0 + 0x1c0)))) != 0) {
                        fn_1_42E74((Sig_fn_1_42E74_Fn142E74Object *)*(u32 *)((u8 *)arg0 + 0x1b0));
                    } else {
                        fn_1_43058((Sig_fn_1_43058_Fn143058Object *)*(u32 *)((u8 *)arg0 + 0x1b0), 0, 100, res_b.value);
                    }
                    }
            }
            w.value = arg0;
            {
for (fzgx_loop_i_14169 = 0; fzgx_loop_i_14169 < 20; fzgx_loop_i_14169++) {
                if (flags[fzgx_loop_i_14169] != 0) {
                    obj = *(u32 *)((u8 *)w.value + 0x210);
                    if (obj != 0 && *(u32 *)((u8 *)w.value + 0x214) != 0) {
                        fn_1_42E74((Sig_fn_1_42E74_Fn142E74Object *)obj);
                    }
                }
                w.value += 0x1;
            }
    i_2.value = fzgx_loop_i_14169;
}
            b8 = (u8)(*(u8 *)((u8 *)arg0 + 0x488));
            if ((s8)b8 != 0) {
                if (*(u32 *)((u8 *)arg0 + 0x1d0) != 0 && *(u32 *)((u8 *)arg0 + 0x1d4) != 0) {
                    if ((s8)b8 != 0) {
                        if (*(s32 *)((u8 *)arg0 + 0x4a0) >= *(s32 *)((u8 *)arg0 + 0x4ac) - 1) {
                            fn_1_9724C(arg0);
                        }
                    }
                }
            }
            if ((s8)*(u8 *)((u8 *)arg0 + 0x488) != 0) {
                fn_1_97288(arg0);
            }
            if (*(u32 *)((u8 *)arg0 + 0x1d0) != 0 && *(u32 *)((u8 *)arg0 + 0x1d4) != 0) {
                base = *(u32 *)((u8 *)arg0 + 0x1d0);
                if ((s8)*(u8 *)((u8 *)arg0 + 0x488) != 0) {
                    f2 = *(f32 *)((u8 *)arg0 + 0x494);
                    if (f2 > p_lbl_1_rodata_3E48->unk_124) {
                        f0 = p_lbl_1_rodata_3E48->unk_128 - f2;
                        fzgx_live = p_lbl_1_rodata_3E48->unk_12C;
                        f1 = fzgx_live;
                        f3 = *(f32 *)((u8 *)base + 0x28);
                        *(f32 *)((u8 *)base + 0x28) = f1 * f0;
                        fn_1_42E74((Sig_fn_1_42E74_Fn142E74Object *)*(u32 *)((u8 *)arg0 + 0x1d0));
                        *(f32 *)((u8 *)*(u32 *)((u8 *)arg0 + 0x1d0) + 0x28) = p_lbl_1_rodata_3E48->unk_128 + f3;
                    } else {
                        *(f32 *)((u8 *)base + 0x28) = *(f32 *)((u8 *)base + 0x2c);
                        fn_1_42E74((Sig_fn_1_42E74_Fn142E74Object *)*(u32 *)((u8 *)arg0 + 0x1d0));
                    }
                } else {
                    if ((s32)*(u32 *)((u8 *)arg0 + 0x1e4) != 0) {
                        fn_1_42E74((Sig_fn_1_42E74_Fn142E74Object *)base);
                        *(fn_1_8F62C_Word3 *)((u8 *)arg0 + 0x1d8) = p_lbl_1_rodata_3E48->unk_140;
                    } else {
                        fn_1_41E34((Sig_fn_1_41E34_fn_1_41E34_MotasglistData *)*(u32 *)((u8 *)arg0 + 0x1c), 3, &res_a);
                        if (*(u16 *)((u8 *)arg0 + 0x1da) != res_a.second ||
                            *(u16 *)((u8 *)arg0 + 0x1e0) != res_a.third ||
                            *(f32 *)((u8 *)arg0 + 0x1dc) != res_a.value) {
                            fn_1_933D8((Sig_fn_1_933D8_CarObject *)arg0, (Sig_fn_1_933D8_EventObject *)(arg0 + 0x1c8),
                                       (fn_1_8F62C_operand___(((u32)(u16)(res_a.second - 1)), ((u32)(((s32)(-res_a.second | res_a.second)) >> 31)))));
                            *(fn_1_8F62C_Word3 *)((u8 *)arg0 + 0x1d8) = *(fn_1_8F62C_Word3 *)&res_a;
                        }
                        if ((fn_1_8F62C_operand__((2), (*(u16 *)((u8 *)arg0 + 0x1e0)))) != 0) {
                            fn_1_42E74((Sig_fn_1_42E74_Fn142E74Object *)*(u32 *)((u8 *)arg0 + 0x1d0));
                        } else {
                            fn_1_43058((Sig_fn_1_43058_Fn143058Object *)*(u32 *)((u8 *)arg0 + 0x1d0), 0, 100, res_a.value);
                        }
                    }
                }
            }
            if (*(u32 *)((u8 *)arg0 + 0x1f0) != 0 && *(u32 *)((u8 *)arg0 + 0x1f4) != 0) {
                base = *(u32 *)((u8 *)arg0 + 0x1f0);
                w.value = *(u32 *)((u8 *)arg0 + 0x4b8);
                if (w.value != 0) {
                    *(u32 *)((u8 *)arg0 + 0x4b8) = w.value - 1;
                } else {
                    if ((s8)*(u8 *)((u8 *)arg0 + 0x488) != 0 || lbl_1_bss_960 == 1) {
                        fn_1_42E74((Sig_fn_1_42E74_Fn142E74Object *)base);
                    } else {
                        fn_1_43058((Sig_fn_1_43058_Fn143058Object *)base, *(u16 *)((u8 *)base + 0x42), *(u16 *)((u8 *)base + 0x44),
                                   p_lbl_1_rodata_3E48->unk_124);
                    }
                    base = *(u32 *)((u8 *)arg0 + 0x1f0);
                    if ((fn_1_8F62C_operand__((4), (*(u16 *)((u8 *)base + 0x40)))) != 0) {
                        w.value = lbl_801A63C0;
                        w.value *= 0x676A4B6B;
                        w.value += 0x33CB;
                        lbl_801A63C0 = w.value;
                        *(u32 *)((u8 *)arg0 + 0x4b8) =
                            (s32)(p_lbl_1_rodata_3E48->unk_130 * ((f32)(s32)(fn_1_8F62C_operand__((0x7FFF), ((w.value >> 16)))) / p_lbl_1_rodata_3E48->unk_134));
                    }
                }
            }
            if ((fn_1_8F62C_operand__((0x20000000), (*(u32 *)((u8 *)arg0 + 0x18)))) == 0) {
                fn_1_107C74(arg0);
            }
            *(u32 *)((u8 *)arg0 + 0x90) = *(u32 *)((u8 *)arg0 + 0x8c);
        }
    }
}
#pragma opt_loop_invariants reset
