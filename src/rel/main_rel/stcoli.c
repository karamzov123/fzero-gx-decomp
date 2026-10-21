#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/stcoli.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"


typedef struct Node {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node *children;
    u8 pad_14[0x50 - 0x14];
} Node;

typedef struct StcoliNode StcoliNode;

struct StcoliNode {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode *items;
    u8 rest[0x3c];
};

typedef struct StcoliVec {
    u32 x;
    u32 y;
    u32 z;
} StcoliVec;

typedef struct {
    unsigned char pad0[0x0c];
    int count;
    void *entries;
} Fn118F28Object;

typedef struct Fn_1_20258Constants {
    unsigned char pad08[8];
    f32 value08;
    f32 value0c;
    unsigned char pad10[0xb0];
    f64 valuec0;
    f32 valuec8;
    unsigned char padcc[4];
    f64 valued0;
} Fn_1_20258Constants;

typedef struct {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
    u32 f28, f2c, f30, f34, f38, f3c, f40, f44;
} Cfg;

typedef struct {
    u8 pad_0[0x4];
    Cfg *cfg;
    u8 pad_8[0xc];
    f32 fx;
    f32 fy;
    f32 fz;
    f32 rxv;
    f32 ryv;
    f32 rzv;
    f32 sxv;
    f32 syv;
    f32 szv;
} Entity;

typedef struct {
    u32 count;
    u32 entries[1];
} Stack;

struct fn_1_2B478_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 m[10];
    f64 d;
} Mtx;

struct Pool {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

struct fn_1_207DC_pool {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

struct fn_1_21950_lbl_1_rodata_6C8 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

typedef struct {
    u8 pad_0[0x30];
    Vec3 pos;
    f32 ax;
    f32 ay;
    Vec3 v0;
    Vec3 e;
    Vec3 m;
    f32 d0;
    f32 d1;
    Vec3 o;
    u32 f7c;
    u8 pad_80[0x7c];
    u32 fffc;
} Rec;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
} fn_1_18784_Cfg;

typedef struct {
    u32 f00;
    fn_1_18784_Cfg *cfg;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    f32 f18;
} Src;

typedef struct {
    u32 f00;
    fn_1_18784_Cfg *cfg;
    u32 f08;
    s32 f0c;
    Src *f10;
    u32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Motion;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_21CFC_Vec;

struct fn_1_2D524_Copy200 { char *a[10][5]; };

struct fn_1_2D524_Copy8 { char *a[2]; };

struct fn_1_2D524_lbl_1_rodata_BD8 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200 unk_58;
    struct fn_1_2D524_Copy8 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};
extern void fn_1_9E14C();
extern void fn_1_9E170(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern const f32 lbl_1_rodata_6D0;
extern f32 lbl_1_rodata_6F8;
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void lbl_8006E0B4(f32, f32, f32);
extern Fn_1_20258Constants lbl_1_rodata_6C8;
extern u8 *lbl_801A66CC;
extern struct fn_1_2B478_lbl_801A6D00 lbl_801A6D00;
extern f64 __fabs(f64);
extern void lbl_8006DB74(void *);
extern void fn_1_18214();
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DBE4();
extern void fn_1_1902C(StcoliNode *root, StcoliVec *vec, void *arg3, f32 value);
extern void fn_1_18784();
extern void fn_1_18F28(Fn118F28Object *obj, int *args, int arg2, float value);
extern u32 fn_1_203E4(void *, u32, void *, f32, f32, f32);
extern void OSReport(const char *format, ...);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E1B0(void *, void *);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80072558(void);
extern f32 lbl_1_rodata_6B0[6];
extern void fn_1_17D5C(Node *node, u32 *acc);
extern int fn_1_210A8(void *, f32 *, int, int, int);
extern int fn_1_16BA0(void *, void *, void *, int *, int);
extern f32 fn_1_16E68(void *, void *, int);
extern unsigned char lbl_1_rodata_840[];
extern void fn_1_22F90(void *self, int value);
extern void lbl_8006E1F0(void *, f32, f32, f32);
extern void fn_1_8A190(void *arg0, void *arg1);
extern int fn_1_15578();
extern void *memset(void *, int, unsigned int);
extern int fn_1_4C10(void);
extern u32 fn_1_4060(void);
extern void fn_1_EB080(int mode);
extern void fn_1_9D77C(u32, u32);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 lbl_801A6410;
extern int fn_1_180F4(int first, int second, int count, int ascending);
extern void fn_1_21950(u32 arg0, f32 arg1, f32 arg2);
extern f32 lbl_1_rodata_6D4;
extern char lbl_1_bss_9C;
extern void fn_1_A2D84(u32 arg0);
extern u32 fn_1_8C66C(u32 index);
extern int fn_1_163BC(void *arg0, void *arg1, int mask, int value);
extern void lbl_8006E1D8(void *arg0, f32 arg1, f32 arg2, f32 arg3);
extern double lbl_1_rodata_910;
extern const f32 lbl_1_rodata_84C;
extern const f32 lbl_1_rodata_854;
extern s16 fn_1_7B054();
extern void *fn_1_868C0(s8 index);
extern void fn_1_F7338(int arg0, void *arg1, void *arg2);
extern const f32 lbl_1_rodata_85C;
extern void fn_8006E978(f32 *arg0, Vec3 *arg1, Vec3 *arg2);
extern void mathutil_mtxA_from_quat(void *);
extern void lbl_8006DFC4(void *);
extern f64 lbl_1_rodata_860[22];
extern f32 lbl_1_rodata_B74[25];
extern f32 lbl_8006D6FC(void *, void *);
extern s16 lbl_1_bss_3C2A[3];
extern f32 lbl_8006D188(s16 angle);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006E7E4(void *, void *, s32);
extern u32 fn_1_8627C(s32 index);
extern u8 * fn_1_14F04(void);
extern u32 fn_1_2B684(u32);
extern u32 lbl_801A66C8[2];
extern f32 lbl_1_rodata_92C[10];
extern void lbl_8006DBAC(void *arg0);
extern void fn_8006E250(void *arg0, void *arg1);
extern void lbl_8006D668(void *arg0);
extern char *fn_1_14EA74(s16 arg0, char *arg1, s16 arg2);
extern char *fn_1_15BA78(char *name);
extern f32 fn_1_4B068(char *);
extern f32 fn_1_4B090(s32 value);
extern int sprintf(char *s, const char *format, ...);
extern s16 fn_1_12EF24(s16 row, s16 column);
extern struct fn_1_2D524_lbl_1_rodata_BD8 lbl_1_rodata_BD8;
extern u32 lbl_801A66B4;
extern u32 fn_1_4AEC0(u32 value);
extern void fn_1_F83F0(s16 arg0);
extern u32 fn_1_F8D10(void);
extern char *lbl_1_data_2BD54[][6];
extern void *fn_1_7F49C(s16 arg0, s16 arg1, void *arg2);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49590(f32 value);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_A2DC4(u32 arg0);
extern void fn_1_F2008(s32 arg);
extern void fn_1_F7F48(s16 value);
extern void fn_1_F8A58(u32 value);
extern void fn_1_F8C00(s32 value);
extern void fn_1_F8D38(u32 value);
extern void fn_1_F9D68(u32 arg);
extern void fn_1_F9DE8(u32 param);
extern u8 lbl_1_bss_6F316;
extern u32 fn_1_A1588(void *, u32);
extern void ADXT_Stop(void *);
extern u32 fn_1_435C(u32 value);
extern void fn_1_40E08(u32 arg0);
extern u32 lbl_1_rodata_D18;
extern u32 lbl_1_rodata_D1C[11];
extern void fn_1_49F0(u32 *value);
extern void fn_1_4A00(s32 enabled, u8 mode, void *value);
extern u32 lbl_1_bss_25B9C;
extern u32 fn_1_304A8(void);
extern void fn_1_3F2A0(void);

/* fzgx:begin fn_1_14CB4 */
void fn_1_14CB4(void) {
    if (lbl_1_bss_3BE0 != 0) {
        if (lbl_1_bss_3BE0->unk_54 != 0) {
            fn_1_9D77C(lbl_1_bss_3BE0->unk_54, lbl_1_bss_3BE0->unk_48);
        }

        fn_1_46B4(lbl_801A6410, lbl_1_bss_3BE4.unk_0, (const char *)(u8 *)(lbl_1_data_51C8), 0x2c9);
        lbl_1_bss_3BE4.unk_0 = 0;
        fn_1_46B4(lbl_801A6410, (u32)lbl_1_bss_3BE0, (const char *)(u8 *)(lbl_1_data_51C8), 0x2cb);
        lbl_1_bss_3BE0 = 0;
    }
}
/* fzgx:end fn_1_14CB4 */

/* fzgx:begin fn_1_14DC4 */
u32 fn_1_14DC4(void) {
    if (lbl_1_bss_3BE0 != 0) {
        return lbl_1_bss_3BE0->unk_14;
    }
    return 0;
}
/* fzgx:end fn_1_14DC4 */

/* fzgx:begin fn_1_14DE8 */
typedef struct {
    s32 unk_0;
    s32 unk_4;
    s8 unk_8;
    s8 unk_9;
} fn_1_14DE8_StcoliEntry;

typedef struct {
    s32 count;
    u8 *base;
    u8 pad_8[4];
} StcoliRecord;


#pragma opt_loop_invariants off
void fn_1_14DE8(u32 index) {
    Obj_1_bss_3BE0_Target **manager;
    f32 *constants;
    fn_1_14DE8_StcoliEntry *entry;
    StcoliRecord *record;
    u8 *object;
    s32 slot;
    f32 zero;
    f32 value;

    constants = lbl_1_rodata_6B0;
    manager = &lbl_1_bss_3BE0;
    if (*manager == 0) {
        return;
    }
    if (index >= 0x24) {
        return;
    }

    entry = ((fn_1_14DE8_StcoliEntry **)(((u8 *)&lbl_1_data_54B4)))[index];
    if (entry == 0) {
        return;
    }

    while (entry->unk_0 >= 0) {
        record = (StcoliRecord *)(*manager)->unk_C + entry->unk_0;
        if (entry->unk_4 >= record->count) {
            return;
        }

        slot = entry->unk_4;
        object = record->base + slot * 0x50;
        if (entry->unk_8) {
            if ((s32)index == 7) {
                zero = constants[0];
                value = constants[3];
                *(f32 *)(object + 0x0C) = zero;
                *(f32 *)(object + 0x10) = zero;
                *(f32 *)(object + 0x14) = value;
                *(f32 *)(object + 0x08) = -*(f32 *)(object + 0x20);
            } else if (!*(s8 *)(object + 0x4C)) {
                *(s8 *)(object + 0x4C) = 1;
            }
        }

        if (entry->unk_9) {
            if ((s32)index == 7) {
                zero = constants[0];
                value = constants[4];
                *(f32 *)(object + 0x28) = zero;
                *(f32 *)(object + 0x2C) = zero;
                *(f32 *)(object + 0x30) = value;
                *(f32 *)(object + 0x24) = *(f32 *)(object + 0x3C);
            } else if (!*(s8 *)(object + 0x4D)) {
                *(s8 *)(object + 0x4D) = 1;
            }
        }

        entry++;
    }
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_14DE8 */

/* fzgx:begin fn_1_14F04 */
u8 * fn_1_14F04(void) {
    return lbl_801A66CC + 0x1b0;
}
/* fzgx:end fn_1_14F04 */

/* fzgx:begin fn_1_17B5C */
typedef struct {
    u8 pad_0[0x40];
    f32 unk_40;
    f32 unk_44;
    u8 pad_48[0x5];
    s8 unk_4D;
} Fn17B5C_Record;

typedef struct {
    u32 unk_0;
    Fn17B5C_Record *unk_4;
    u32 unk_8;
} Fn17B5C_Slot;

int fn_1_17B5C(int a, int b, int count, f32 threshold) {
    int end;
    int span;
    int j;
    int found;
    int result;
    Fn17B5C_Slot *left;
    Fn17B5C_Slot *right;
    f32 delta;

    if (a == b) {
        return 1;
    }
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    span = b - a;
    {
        int diff = count - span;
        if (diff < span) {
            int temp = a;
            a = b;
            b = temp;
            span = diff;
        }
    }

    left = &((Fn17B5C_Slot *)lbl_1_bss_3BE0->unk_C)[a];
    right = &((Fn17B5C_Slot *)lbl_1_bss_3BE0->unk_C)[b];
    if (threshold > (*((f32 *)&lbl_1_rodata_6D0))) {
        delta = right->unk_4->unk_40 - left->unk_4->unk_44;
        if (delta < (*((f32 *)&lbl_1_rodata_6D0))) {
            delta += *(f32 *)lbl_1_bss_3BE0->unk_90;
        }
        if (delta > threshold) {
            return 0;
        }
    }

    b = a + 1;
    end = count - 1;
    found = 0;
    for (j = 0; j < span; j++) {
        if (b > end) {
            b = 0;
        }
        if (!((Fn17B5C_Slot *)lbl_1_bss_3BE0->unk_C)[a].unk_4->unk_4D) {
            break;
        }
        a = b;
        found++;
        b++;
    }

    result = 0;
    if (span == 0 || found >= span) {
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_17B5C */

/* fzgx:begin fn_1_17C6C */
typedef struct Entry {
    char pad[0x4d];
    s8 active;
} Entry;

typedef struct Slot {
    int pad;
    Entry *entry;
    int tail;
} Slot;

typedef struct Root {
    char pad[0xc];
    Slot *slots;
} Root;

int fn_1_17C6C(int current, int next, int limit) {
    int end;
    int count;
    int span;
    int result;

    if (current == next) {
        return 1;
    }

    if (current > next) {
        int temp = current;
        current = next;
        next = temp;
    }

    span = next - current;
    {
        int diff = limit - span;
        if (diff < span) {
            current = next;
            span = diff;
        }
    }

    next = current + 1;
    count = 0;
    end = limit - 1;

    while (count < span) {
        if (next > end) {
            next = 0;
        }

        if (!(*(Root **)&(*(u32 *)&lbl_1_bss_3BE0))->slots[current].entry->active) {
            break;
        }
        if (current == 0x8b && fn_1_7B054(current) == 3) {
            break;
        }
        current = next;
        count++;
        next++;
    }

    result = 0;
    if (span == 0 || count >= span) {
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_17C6C */

/* fzgx:begin fn_1_17D5C */
void fn_1_17D5C(Node *node, u32 *acc) {
    Node *root;
    s32 i1;
    Node *p1;
    Node *p2;
    s32 i2;
    Node *p3;
    s32 i3;
    Node *p4;
    s32 i4;
    Node *p5;
    s32 i5;
    Node *p6;
    s32 i6;
    Node *p7;
    s32 i7;
    Node *p8;
    s32 i8;
    Node *p9;
    s32 i9;

    root = node;
    *acc |= root->unk_0;
    if (root->count > 0) {
        i1 = 0;
        p1 = root->children;
        while (i1 < root->count) {
            *acc |= p1->unk_0;
            if (p1->count > 0) {
                p2 = p1->children;
                i2 = 0;
                while (i2 < p1->count) {
                    *acc |= p2->unk_0;
                    if (p2->count > 0) {
                        p3 = p2->children;
                        i3 = 0;
                        while (i3 < p2->count) {
                            *acc |= p3->unk_0;
                            if (p3->count > 0) {
                                p4 = p3->children;
                                i4 = 0;
                                while (i4 < p3->count) {
                                    *acc |= p4->unk_0;
                                    if (p4->count > 0) {
                                        p5 = p4->children;
                                        i5 = 0;
                                        while (i5 < p4->count) {
                                            *acc |= p5->unk_0;
                                            if (p5->count > 0) {
                                                p6 = p5->children;
                                                i6 = 0;
                                                while (i6 < p5->count) {
                                                    *acc |= p6->unk_0;
                                                    if (p6->count > 0) {
                                                        p7 = p6->children;
                                                        i7 = 0;
                                                        while (i7 < p6->count) {
                                                            *acc |= p7->unk_0;
                                                            if (p7->count > 0) {
                                                                p8 = p7->children;
                                                                i8 = 0;
                                                                while (i8 < p7->count) {
                                                                    *acc |= p8->unk_0;
                                                                    if (p8->count > 0) {
                                                                        p9 = p8->children;
                                                                        i9 = 0;
                                                                        while (i9 < p8->count) {
                                                                            fn_1_17D5C(p9, acc);
                                                                            i9++;
                                                                            p9++;
                                                                        }
                                                                    }
                                                                    i8++;
                                                                    p8++;
                                                                }
                                                            }
                                                            i7++;
                                                            p7++;
                                                        }
                                                    }
                                                    i6++;
                                                    p6++;
                                                }
                                            }
                                            i5++;
                                            p5++;
                                        }
                                    }
                                    i4++;
                                    p4++;
                                }
                            }
                            i3++;
                            p3++;
                        }
                    }
                    i2++;
                    p2++;
                }
            }
            i1++;
            p1++;
        }
    }
}
/* fzgx:end fn_1_17D5C */

/* fzgx:begin fn_1_17FCC */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
} fn_1_17FCC_StcoliEntry;


int fn_1_17FCC(int a, int b, int c) {
    int count;
    int i;
    int end;
    fn_1_17FCC_StcoliEntry *last;
    fn_1_17FCC_StcoliEntry *entry;
    u32 fa;
    u32 fb;
    int result;

    if (a == b) {
        return 1;
    }
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    count = b - a;
    i = c - count;
    if (i < count) {
        a = b;
        count = i;
    }
    b = a + 1;
    end = c;
    end = end - 1;
    last = (fn_1_17FCC_StcoliEntry *)lbl_1_bss_3BE0->unk_C + a;
    i = 0;
    while (i < count) {
        if (b > end) {
            b = 0;
        }
        entry = (fn_1_17FCC_StcoliEntry *)lbl_1_bss_3BE0->unk_C + b;
        fb = 0;
        fa = 0;
        fn_1_17D5C( (Node *)(u32)(last->unk_8), &fa);
        fn_1_17D5C( (Node *)(u32)(entry->unk_8), &fb);
        if ((fa & 0x01000000) != 0 && (fb & 0x00800000) != 0) {
            break;
        }
        if ((fb & 0x01000000) != 0 && (fa & 0x00800000) != 0) {
            break;
        }
        last = entry;
        i++;
        b++;
    }
    result = 0;
    if (count == 0 || i >= count) {
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_17FCC */

/* fzgx:begin fn_1_180F4 */
typedef struct {
    int unk_0;
    int unk_4;
    int unk_8;
} Entry_180F4;

int fn_1_180F4(int first, int second, int count, int ascending) {
    int wins;
    int current;
    int limit;
    int j;
    int tmp;
    Entry_180F4 *current_entry;
    Entry_180F4 *candidate;
    int result;

    if (first == second) {
        return 1;
    }

    if (first > second) {
        tmp = first;
        first = second;
        second = tmp;
    }

    current = second - first;
    limit = count - current;
    if (limit < current) {
        first = second;
        current = limit;
    }

    current_entry = &((Entry_180F4 *)lbl_1_bss_3BE0->unk_C)[first];
    wins = 0;
    second = first + 1;
    limit = count;
    limit -= 1;
    j = current;

    while (j > 0) {
        if (second > limit) {
            second = 0;
        }

        candidate = &((Entry_180F4 *)lbl_1_bss_3BE0->unk_C)[second];
        if (ascending) {
            if (current_entry->unk_0 < candidate->unk_0) {
                break;
            }
        } else if (current_entry->unk_0 > candidate->unk_0) {
            break;
        }

        current_entry = candidate;
        wins++;
        second++;
        j--;
    }

    result = 0;
    if (current == 0 || wins >= current) {
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_180F4 */

/* fzgx:begin fn_1_181CC */
// fn_1_181CC: main_rel .text:0x000181CC size 0x24
// Wrapper function that passes first three arguments through and sets fourth to 1

void fn_1_181CC(int a, int b, int c) {
    fn_1_180F4(a, b, c, 1);
}
/* fzgx:end fn_1_181CC */

/* fzgx:begin fn_1_181F0 */
void fn_1_181F0(int a, int b, int c) {
    fn_1_180F4(a, b, c, 0);
}
/* fzgx:end fn_1_181F0 */

/* fzgx:begin fn_1_18214 noprologue */
#include "types.h"

typedef struct {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
    u32 f28, f2c, f30, f34, f38, f3c, f40, f44;
} Cfg;

typedef struct {
    u8 pad_0[0x4];
    Cfg *cfg;
    u8 pad_8[0xc];
    f32 fx;
    f32 fy;
    f32 fz;
    f32 rxv;
    f32 ryv;
    f32 rzv;
    f32 sxv;
    f32 syv;
    f32 szv;
} Entity;

typedef struct {
    u32 count;
    u32 entries[1];
} Stack;

extern f32 fn_1_9E14C(u32, u32, f32);
extern f32 fn_1_9E170(u32, u32, void *, f32);
extern const f32 lbl_1_rodata_6D0;
extern f32 lbl_1_rodata_6F8;
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_80008BEC(void *, int, void *);
extern void lbl_8006E0B4(f32, f32, f32);

void fn_1_18214(Entity *arg0, f32 *arg1, Stack *arg2, f32 t) {
    Cfg *v0 = arg0->cfg;
    u8 *slot;
    s32 ang;
    f32 a;
    f32 b;
    f32 c;
    f32 r;

    if (arg2 != 0) {
        slot = (u8 *)arg2 + arg2->count * 36 + 44;
        if (arg2->entries[arg2->count] != (u32)arg0) {
            fn_80008BEC((u8 *)arg2 + arg2->count * 36 + 44, 0, (void *)36);
        }
        if (v0->f3c != 0) {
            a = fn_1_9E170(v0->f18, v0->f3c, slot, t);
        } else {
            a = arg0->sxv;
        }
        if (v0->f40 != 0) {
            b = fn_1_9E170(v0->f1c, v0->f40, slot + 4, t);
        } else {
            b = arg0->syv;
        }
        if (v0->f44 != 0) {
            c = fn_1_9E170(v0->f20, v0->f44, slot + 8, t);
        } else {
            c = arg0->szv;
        }
        if (lbl_1_rodata_6D0 != a || lbl_1_rodata_6D0 != b || lbl_1_rodata_6D0 != c) {
            lbl_8006E0B4(arg1[0] * a, arg1[1] * b, arg1[2] * c);
        }
        if (v0->f30 != 0) {
            a = fn_1_9E170(v0->f0c, v0->f30, slot + 12, t);
        } else {
            a = arg0->rxv;
        }
        if (v0->f34 != 0) {
            b = fn_1_9E170(v0->f10, v0->f34, slot + 16, t);
        } else {
            b = arg0->ryv;
        }
        if (v0->f38 != 0) {
            c = fn_1_9E170(v0->f14, v0->f38, slot + 20, t);
        } else {
            c = arg0->rzv;
        }
        if (lbl_1_rodata_6D0 != c) {
            if (((s32)(lbl_1_rodata_6F8 * c) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_z((s16)(u16)(s32)(lbl_1_rodata_6F8 * c));
            }
        }
        if (lbl_1_rodata_6D0 != b) {
            if (((s32)(lbl_1_rodata_6F8 * b) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_y((s16)(u16)(s32)(lbl_1_rodata_6F8 * b));
            }
        }
        if (lbl_1_rodata_6D0 != a) {
            if (((s32)(lbl_1_rodata_6F8 * a) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_x((s16)(u16)(s32)(lbl_1_rodata_6F8 * a));
            }
        }
        if (v0->f24 != 0) {
            r = fn_1_9E170(v0->f00, v0->f24, slot + 24, t);
        } else {
            r = arg0->fx;
        }
        arg1[0] = arg1[0] * r;
        if (v0->f28 != 0) {
            r = fn_1_9E170(v0->f04, v0->f28, slot + 28, t);
        } else {
            r = arg0->fy;
        }
        arg1[1] = arg1[1] * r;
        if (v0->f2c != 0) {
            r = fn_1_9E170(v0->f08, v0->f2c, slot + 32, t);
        } else {
            r = arg0->fz;
        }
        arg1[2] = arg1[2] * r;
    } else {
        if (v0->f3c != 0) {
            a = fn_1_9E14C(v0->f18, v0->f3c, t);
        } else {
            a = arg0->sxv;
        }
        if (v0->f40 != 0) {
            b = fn_1_9E14C(v0->f1c, v0->f40, t);
        } else {
            b = arg0->syv;
        }
        if (v0->f44 != 0) {
            c = fn_1_9E14C(v0->f20, v0->f44, t);
        } else {
            c = arg0->szv;
        }
        if (lbl_1_rodata_6D0 != a || lbl_1_rodata_6D0 != b || lbl_1_rodata_6D0 != c) {
            lbl_8006E0B4(arg1[0] * a, arg1[1] * b, arg1[2] * c);
        }
        if (v0->f30 != 0) {
            b = fn_1_9E14C(v0->f0c, v0->f30, t);
        } else {
            b = arg0->rxv;
        }
        if (v0->f34 != 0) {
            a = fn_1_9E14C(v0->f10, v0->f34, t);
        } else {
            a = arg0->ryv;
        }
        if (v0->f38 != 0) {
            c = fn_1_9E14C(v0->f14, v0->f38, t);
        } else {
            c = arg0->rzv;
        }
        if (lbl_1_rodata_6D0 != c) {
            if (((s32)(lbl_1_rodata_6F8 * c) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_z((s16)(u16)(s32)(lbl_1_rodata_6F8 * c));
            }
        }
        if (lbl_1_rodata_6D0 != a) {
            if (((s32)(lbl_1_rodata_6F8 * a) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_y((s16)(u16)(s32)(lbl_1_rodata_6F8 * a));
            }
        }
        if (lbl_1_rodata_6D0 != b) {
            if (((s32)(lbl_1_rodata_6F8 * b) & 0xFFFF) != 0) {
                mathutil_mtxA_rotate_x((s16)(u16)(s32)(lbl_1_rodata_6F8 * b));
            }
        }
        if (v0->f24 != 0) {
            r = fn_1_9E14C(v0->f00, v0->f24, t);
        } else {
            r = arg0->fx;
        }
        arg1[0] = arg1[0] * r;
        if (v0->f28 != 0) {
            r = fn_1_9E14C(v0->f04, v0->f28, t);
        } else {
            r = arg0->fy;
        }
        arg1[1] = arg1[1] * r;
        if (v0->f2c != 0) {
            r = fn_1_9E14C(v0->f08, v0->f2c, t);
        } else {
            r = arg0->fz;
        }
        arg1[2] = arg1[2] * r;
    }
    if (arg2 != 0) {
        arg2->entries[arg2->count] = (u32)arg0;
        if ((s32)arg2->count < 9) {
            arg2->count = arg2->count + 1;
        }
    }
}
/* fzgx:end fn_1_18214 */

/* fzgx:begin fn_1_18784 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
} Cfg;

typedef struct {
    f32 f00;
    f32 f04;
    f32 f08;
    f32 f0c;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Mat;

typedef struct {
    u8 pad_0[0x1bc];
    s32 f1bc;
    u8 pad_1c0[8];
    u32 f1c8;
    s32 f1cc;
    u8 pad_1d0[0xc];
    f32 f1dc;
    f32 f1e0;
} Mgr;

typedef struct {
    u32 f00;
    Cfg *cfg;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    f32 f18;
} Src;

typedef struct {
    u32 f00;
    Cfg *cfg;
    u32 f08;
    s32 f0c;
    Src *f10;
    u32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Motion;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 pad_0[0x30];
    Vec3 pos;
    f32 ax;
    f32 ay;
    Vec3 v0;
    Vec3 e;
    Vec3 m;
    f32 d0;
    f32 d1;
    Vec3 o;
    u32 f7c;
    u8 pad_80[0x7c];
    u32 fffc;
} Rec;

struct Pool {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

extern struct Pool lbl_1_rodata_6C8;
extern u32 lbl_801A66CC;
extern u32 lbl_801A6D00;
extern f64 __fabs(f64);
extern f32 fn_1_9E14C(u32, u32, f32);
extern Rec *lbl_8006DB74(Rec *);
extern void fn_1_18214(Motion *, Vec3 *, void *, f32);

#pragma opt_propagation off
void fn_1_18784(u32 arg0, Motion *a, Vec3 *b, void *c, f32 d)
{
    struct Pool *pl;
    Rec *p;
    Rec *q;
    u32 mask;
    Cfg *cf;
    f64 tmp___fabs;
    f32 scx;
    f32 s2;
    f32 ax;
    f32 ay;
    f32 sm;
    f32 px;

    pl = &lbl_1_rodata_6C8;
    if ((arg0 & 0x800000) != 0) {
        q = (Rec *)((u8 *)((Mgr *)lbl_801A66CC) + ((((Mgr *)lbl_801A66CC)->f1cc) << 7) + 0x5B0);
    } else {
        q = (Rec *)0;
    }
    p = q;
    mask = a->f00 & 0x07E00C01;
    ((Mgr *)lbl_801A66CC)->f1c8 |= mask;
    if ((a->f00 & 0x4000000) != 0) {
        Mgr *m = (Mgr *)lbl_801A66CC;
        if (m->f1bc == 1 || (m->f1bc > 1 && m->f1cc == 0)) {
            if (m->f1cc < 3) {
                m->f1cc = m->f1cc + 1;
                if (p != 0) {
                    p->fffc = 0;
                    p = (Rec *)((u8 *)p + 0x80);
                }
            }
        }
    }
    if ((a->f00 & 0x600000) == 0) {
        fn_1_18214(a, b, c, d);
        if (p != 0) {
            f32 *mtx;
            lbl_8006DB74(p);
            /* Locked cache: the current matrix at 0xE0000000 is not a data symbol. */
            mtx = (f32 *)(0xE0000000 + 0);
            p->pos = *b;
            psvec_set(&p->v0.x, mtx[11], mtx[7], mtx[3]);
            p->e.x = -((Mat *)lbl_801A6D00)->f08;
            p->e.y = -((Mat *)lbl_801A6D00)->f18;
            p->e.z = -((Mat *)lbl_801A6D00)->f28;
            p->m.x = ((Mat *)lbl_801A6D00)->f04;
            p->m.y = ((Mat *)lbl_801A6D00)->f14;
            p->m.z = ((Mat *)lbl_801A6D00)->f24;
        }
    }
    if ((a->f00 & 0x400000) != 0) {
        cf = a->cfg;
        scx = (cf->f3c != 0) ? fn_1_9E14C(cf->f18, cf->f3c, d) : a->f2c;
        scx = pl->two * scx;
        s2 = (cf->f28 != 0) ? fn_1_9E14C(cf->f04, cf->f28, d) : a->f18;
{
    f32 bx;
        bx = (*(f32 volatile *)&(b->x)) /* Retail reloads this field. */;
        sm = scx + s2;
        scx = scx * bx;
        tmp___fabs = __fabs(scx);
        ax = (f32)tmp___fabs;
        tmp___fabs = __fabs(s2 * b->y);
        ay = (f32)tmp___fabs;
        px = bx * sm;
}
        ((Mgr *)lbl_801A66CC)->f1dc = ax;
        ((Mgr *)lbl_801A66CC)->f1e0 = ay;
        if (p != 0) {
            p->ax = ax;
            p->ay = ay;
        }
    }
    if (p != 0) {
        p->f7c |= mask;
        if ((a->f00 & 0x800000) != 0 && a->f0c == 1) {
            Cfg *c2 = (*(Src *volatile *)&(a->f10))->cfg; /* Retail reloads this field. */
            p->d0 = (*(f32 volatile *)&(b->x)) /* Retail reloads this field. */;
            p->d1 = (c2->f28 != 0) ? fn_1_9E14C(c2->f04, c2->f28, d) : (*(Src *volatile *)&(a->f10))->f18 /* Retail reloads this field. */;
        } else if ((a->f00 & 0x200000) == 0) {
            p->d0 = (a->f00 & 0x400000) ? px : (*(f32 volatile *)&(b->x)) /* Retail reloads this field. */;
            p->d1 = pl->one;
        }
        if ((a->f00 & 0x400000) != 0) {
            psvec_scale_add(&p->v0.x, &p->m.x, pl->half * p->ay, &p->o.x);
        } else if ((a->f00 & 0x1800000) != 0) {
            psvec_scale_add(&p->v0.x, &p->m.x, pl->half * b->y, &p->o.x);
        } else {
            p->o = p->v0;
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_18784 */

/* fzgx:begin fn_1_18B40 */
typedef u32 (*fn_1_18B40_Fn)(u32, u32, u32, u32, u32, u32, u32, u32, f32);

struct fn_1_18B40_Obj {
    u32 flags;
    u8 pad_4[0x8];
    s32 count;
    struct fn_1_18B40_Obj *entries;
    u8 pad_14[0x38];
    s32 unk_4C;
};

struct fn_1_18B40_Vec {
    u32 x;
    u32 y;
    u32 z;
};


#pragma opt_loop_invariants off
#pragma opt_common_subs off
void fn_1_18B40(void * arg0, void * arg1, u32 arg2, struct fn_1_18B40_Obj *arg3, struct fn_1_18B40_Vec *arg4, int arg5, void * arg6, void * arg7, f32 arg8, u32 arg9) {
    struct fn_1_18B40_Obj * fzgx_live_;
    struct fn_1_18B40_Obj * fzgx_live;
    struct fn_1_18B40_Vec saved;
    int i;

    if (arg3->count > 0) {
        lbl_8006DAEC();
        fzgx_live_ = arg3->entries;
{
    struct fn_1_18B40_Obj *entry;
        entry = (fzgx_live_);
        i = 0;
        while (i < arg3->count) {
            if (arg5 == 0 || entry->unk_4C == 0 || entry->unk_4C == arg5) {
                if ((entry->flags & 0x2) == 0) {
                    saved = *arg4;
                    lbl_8006DBE4();
                    ((fn_1_18B40_Fn)*(fn_1_18B40_Fn *)(lbl_1_data_5548 + (__cntlzw(entry->flags & 0x3FE0000) << 2)))( (u32)arg0,(u32)arg1, arg2, (u32)entry, (u32)arg4, (u32)arg6, (u32)arg7, arg9, arg8);
                    fn_1_18B40(arg0, arg1, arg2, entry, arg4, arg5, arg6, arg7, arg8, arg9);
                    *arg4 = saved;
                }
            }
            i++;
            entry = (struct fn_1_18B40_Obj *)((u8 *)entry + 0x50);
}
        }
        lbl_8006DB30();
    }
}
#pragma opt_common_subs reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_18B40 */

/* fzgx:begin fn_1_18F28 noprologue */
#include "types.h"

typedef struct {
    unsigned char pad0[0x0c];
    int count;
    void *entries;
} Fn118F28Object;

typedef struct {
    unsigned int flags;
} Fn118F28Entry;

typedef struct {
    int x;
    int y;
    int z;
} Fn118F28Vector;

extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DBE4(int, int);
extern void fn_1_1902C(Fn118F28Entry *, int *, int, float);

void fn_1_18F28(Fn118F28Object *obj, int *args, int arg2, float value) {
    Fn118F28Vector vector;
    int i;
    Fn118F28Entry *entry;

    if (obj->count > 0) {
        lbl_8006DAEC();
        entry = (Fn118F28Entry *)obj->entries;
        i = 0;
        while (i < obj->count) {
            if ((entry->flags & 0x1e0002) == 0) {
                vector = *(Fn118F28Vector *)args;
                lbl_8006DBE4(vector.y, vector.x);
                fn_1_1902C(entry, args, arg2, value);
                *(Fn118F28Vector *)args = vector;
            }
            i++;
            entry = (Fn118F28Entry *)((char *)entry + 0x50);
        }
        lbl_8006DB30();
    }
}
/* fzgx:end fn_1_18F28 */

/* fzgx:begin fn_1_18FFC */
void fn_1_18FFC(int a, int b, int c, int d, int e, int f, int g) {
    fn_1_18784(c, d, e, g);
}
/* fzgx:end fn_1_18FFC */

/* fzgx:begin fn_1_1902C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/stcoli.h"

extern void fn_1_18784(int, int, int, int);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void fn_1_18784();
extern void lbl_8006DBE4(void);

typedef struct StcoliNode StcoliNode;
typedef struct StcoliVec {
    u32 x;
    u32 y;
    u32 z;
} StcoliVec;

struct StcoliNode {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode *items;
    u8 rest[0x3c];
};

extern void fn_1_18F28(StcoliNode *, StcoliVec *, void *, f32);

// Traverse the four-level collision hierarchy, preserving the input vector at each level.
void fn_1_1902C(StcoliNode *root, StcoliVec *vec, void *arg3, f32 value) {
    StcoliNode *level1;
    s32 i1;

    fn_1_18784(0x800000, root, vec, 0, value);
    if (root->count > 0) {
        lbl_8006DAEC();
        level1 = root->items;
        i1 = 0;
        while (i1 < root->count) {
            if ((level1->flags & 0x001e0002) == 0) {
                StcoliVec saved1 = *vec;
                StcoliNode *level2;
                s32 i2;

                lbl_8006DBE4();
                fn_1_18784(0x800000, level1, vec, 0, value);
                if (level1->count > 0) {
                    lbl_8006DAEC();
                    level2 = level1->items;
                    i2 = 0;
                    while (i2 < level1->count) {
                        if ((level2->flags & 0x001e0002) == 0) {
                            StcoliVec saved2 = *vec;
                            StcoliNode *level3;
                            s32 i3;

                            lbl_8006DBE4();
                            fn_1_18784(0x800000, level2, vec, 0, value);
                            if (level2->count > 0) {
                                lbl_8006DAEC();
                                level3 = level2->items;
                                i3 = 0;
                                while (i3 < level2->count) {
                                    if ((level3->flags & 0x001e0002) == 0) {
                                        StcoliVec saved3 = *vec;
                                        StcoliNode *level4;
                                        s32 i4;

                                        lbl_8006DBE4();
                                        fn_1_18784(0x800000, level3, vec, 0, value);
                                        if (level3->count > 0) {
                                            lbl_8006DAEC();
                                            level4 = level3->items;
                                            i4 = 0;
                                            while (i4 < level3->count) {
                                                if ((level4->flags & 0x001e0002) == 0) {
                                                    StcoliVec saved4 = *vec;

                                                    lbl_8006DBE4();
                                                    fn_1_18784(0x800000, level4, vec, 0, value);
                                                    fn_1_18F28(level4, vec, arg3, value);
                                                    *vec = saved4;
                                                }
                                                i4 += 1;
                                                level4 += 1;
                                            }
                                            lbl_8006DB30();
                                        }
                                        *vec = saved3;
                                    }
                                    i3 += 1;
                                    level3 += 1;
                                }
                                lbl_8006DB30();
                            }
                            *vec = saved2;
                        }
                        i2 += 1;
                        level2 += 1;
                    }
                    lbl_8006DB30();
                }
                *vec = saved1;
            }
            i1 += 1;
            level1 += 1;
        }
        lbl_8006DB30();
    }
}
/* fzgx:end fn_1_1902C */

/* fzgx:begin fn_1_1FB80 noprologue */
#include "types.h"
#include "rel/main_rel/stcoli.h"

extern const struct fn_1_1FB80_lbl_1_rodata_708_pool {
    f32 unk_0;
} lbl_1_rodata_708;

typedef struct { f32 x; f32 y; f32 z; } Vec_fn_1_1FB80;

/* 0x24-byte trigger volume entry */
typedef struct {
    u8 pad_0[0xC];
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 pad_12[2];
    f32 size_x;
    f32 size_y;
    f32 size_z;
    u32 flags;
} ColiVolume_fn_1_1FB80;


extern f64 __fabs(f64);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_8006E250(void *, Vec_fn_1_1FB80 *);
extern void lbl_8006D7DC(void *);

#pragma opt_loop_invariants off
#pragma opt_propagation off
u32 fn_1_1FB80(void *pos, u32 mask) {
    struct { u32 value; } result;
    struct { s32 value; } i;
    struct { s32 value; } count;
    struct { ColiVolume_fn_1_1FB80 *value; } vol;
    Vec_fn_1_1FB80 local;

    result.value = 0;
    i.value = 0;
    vol.value = 0;
    count.value = (s32)lbl_1_bss_3BE0->unk_9C;
    vol.value = (ColiVolume_fn_1_1FB80 *)lbl_1_bss_3BE0->unk_A0;
    for (; i.value < count.value; i.value++, vol.value++) {
        if (vol.value->flags & mask) {
            lbl_8006D7DC(vol.value);
            if (vol.value->rot_z) {
                mathutil_mtxA_rotate_z(vol.value->rot_z);
            }
            if (vol.value->rot_y) {
                mathutil_mtxA_rotate_y(vol.value->rot_y);
            }
            if (vol.value->rot_x) {
                mathutil_mtxA_rotate_x(vol.value->rot_x);
            }
            fn_8006E250(pos, &local);
            if (__fabs(local.x) <= lbl_1_rodata_708.unk_0 * vol.value->size_x
             && __fabs(local.y) <= lbl_1_rodata_708.unk_0 * vol.value->size_y
             && __fabs(local.z) <= lbl_1_rodata_708.unk_0 * vol.value->size_z) {
                result.value |= vol.value->flags;
            }
        }
    }
    return result.value;
}
#pragma opt_propagation reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_1FB80 */

/* fzgx:begin fn_1_20258 */
typedef struct Fn_1_20258 {
    unsigned char pad00[0x30];
    f32 field30;
    f32 field34;
    unsigned char pad38[4];
    f32 field3c;
    unsigned char pad40[0x28];
    f32 field68;
    f32 field6c;
    unsigned char pad70[0xc];
    u32 flags;
} Fn_1_20258;

#pragma opt_strength_reduction on
f32 fn_1_20258(Fn_1_20258 *self, f32 *out_ratio) {
    u32 flags = self->flags;
    u8 *data = (*(u8 (*)[400])&lbl_1_data_5548);
    Fn_1_20258Constants *constants = &lbl_1_rodata_6C8;
    f32 ratio;
    f32 scale;

    if ((flags & 0x01c00000) != 0) {
        ratio = self->field34 / self->field30;
        if (ratio < constants->valuec0) {
            ratio = constants->value08;
        }
    } else if ((flags & 0x02200000) != 0) {
        ratio = constants->value0c;
    } else {
        OSReport((const char *)(data + 0x108), flags);
        OSPanic((const char *)(data + 0x12c), 0x1650,
                    (const char *)(data + 0x134));
    }

    if ((self->flags & 0x02200000) != 0 ||
        constants->value08 == ratio) {
        scale = self->field68;
    } else if ((self->flags & 0x01800000) != 0) {
        f32 t;

        t = constants->valuec8 * ratio;
        scale = (constants->value0c + t) * (self->field6c * self->field68);
    } else if ((self->flags & 0x00400000) != 0) {
        f32 t;
        f64 prod;

        t = constants->valuec8 * ratio;
        prod = constants->valued0 * self->field3c;
        scale = prod + (constants->value0c + t) * (self->field68 - self->field3c);
    } else {
        OSReport((const char *)(data + 0x138), self->flags);
        OSPanic((const char *)(data + 0x12c), 0x1661,
                    (const char *)(data + 0x15c));
    }

    if (out_ratio != 0) {
        *out_ratio = ratio;
    }
    return scale;
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_20258 */

/* fzgx:begin fn_1_207DC */
struct fn_1_207DC_obj {
    u8 pad_0[0x30];
    f32 unk_30;
    f32 unk_34;
    u8 pad_38[4];
    f32 unk_3C;
    u8 pad_40[0x28];
    f32 unk_68;
    f32 unk_6C;
    u8 pad_70[0xC];
    u32 unk_7C;
};



static inline void set_f32(f32 *dst, f32 v) {
    if (dst) {
        *dst = v;
    }
}

void fn_1_207DC(struct fn_1_207DC_obj *obj, void *out, f32 x) {
    u8 *data = (u8 *)&lbl_1_data_5548;
    struct fn_1_207DC_pool *pool = &(*((struct fn_1_207DC_pool *)&lbl_1_rodata_6C8));
    u32 flags = obj->unk_7C;
    u32 flags2;
    f32 t;
    f32 val;
    f32 prod;
    f64 d2;
    f32 arg6;

    if (flags & 0x1C00000) {
        t = obj->unk_34 / obj->unk_30;
        if (t < pool->eps) {
            t = pool->zero;
        }
    } else if (flags & 0x2200000) {
        t = pool->one;
    } else {
        OSReport((const char *)(data + 0x108), flags);
        OSPanic((const char *)(data + 0x12c), 0x1650, (const char *)(data + 0x134));
    }

    flags2 = obj->unk_7C;
    if ((flags2 & 0x2200000) || pool->zero == t) {
        val = obj->unk_68;
    } else if (flags2 & 0x1800000) {
        prod = pool->pi * t;
        val = (pool->one + prod) * (obj->unk_6C * obj->unk_68);
    } else if (flags2 & 0x400000) {
        prod = pool->pi * t;
        d2 = pool->two * obj->unk_3C;
        val = d2 + (pool->one + prod) * (obj->unk_68 - obj->unk_3C);
    } else {
        OSReport((const char *)(data + 0x138), flags2);
        OSPanic((const char *)(data + 0x12c), 0x1661, (const char *)(data + 0x15c));
    }

    set_f32(&arg6, t);
    fn_1_203E4(obj, 1, out, x, val, arg6);
}
/* fzgx:end fn_1_207DC */

/* fzgx:begin fn_1_20994 */
typedef struct Fn_1_20994_Object {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_0C[0x71];
    u8 unk_7D;
} Fn_1_20994_Object;


int fn_1_20994(void *arg, f32 *out) {
    f32 value;
    int result;
    int index;
    Fn_1_20994_Object *object;

    value = lbl_1_rodata_6D0;
    result = 0;
    object = ((Fn_1_20994_Object *)lbl_1_bss_3BE0);
    if (object != 0) {
        if (object->unk_7D != 0) {
            index = 0;
        } else {
            index = object->unk_8 - 1;
        }
        do {
            result = fn_1_210A8(arg, &value, index--, 0, 0);
        } while (result < 0 && index >= 0);
        if (result < 0) {
            result = 0;
            value = lbl_1_rodata_6D0;
        }
    }
    *out = value;
    return result;
}
/* fzgx:end fn_1_20994 */

/* fzgx:begin fn_1_21644 */
void *fn_1_21644(void *arg0, f32 *arg1, void *arg2) {
    int local;

    int status;

    local = 0;
    status = fn_1_16BA0(arg0, arg1, arg2, &local, 0);
    if (status < 0) {
        local = 0;
        *arg1 = fn_1_16E68(arg0, arg2, 0);
        return arg2;
    }
    return (void *)status;
}
/* fzgx:end fn_1_21644 */

/* fzgx:begin fn_1_216C0 */
void fn_1_216C0(void *arg0, void *arg1, void *arg2) {
    int local;

    local = 0;
    fn_1_16BA0(arg0, arg1, arg2, (int *)(void *)(&local), 0);
}
/* fzgx:end fn_1_216C0 */

/* fzgx:begin fn_1_2192C */
void fn_1_2192C(void *self, void *arg) {
    fn_1_18214(self, arg, 0);
}
/* fzgx:end fn_1_2192C */

/* fzgx:begin fn_1_21950 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 0.0f;
    s = 1.0f;
    s = -5.0f;
    s = 10.0f;
    s = -1.0f;
    s = 2.0f;
    s = 0.5f;
    s = 2.5f;
    s = 1.7000000476837158f;
    s = 0.0010000000474974513f;
    s = 182.04444885253906f;
    s = -0.5f;
}
#pragma section code_type ".text"



#define GX_FIFO (*(volatile f32 *)((u8 *)0xCC010000 - 0x8000))  /* fzgx-allow: A1,A2 GX write-gather FIFO pipe */

static inline void gx_pos3(f32 x, f32 y, f32 z) {
    GX_FIFO = x;
    GX_FIFO = y;
    GX_FIFO = z;
}

#pragma opt_propagation off
void fn_1_21950(u32 arg0, f32 arg1, f32 arg2) {
    struct fn_1_21950_lbl_1_rodata_6C8 *p_lbl_1_rodata_6C8;
    f32 v0;
    f32 v11_2;
    u32 v2;
    u32 v5;
    f32 v4;
    f32 v6;
    f32 v7;
    f32 v8;
    f32 v9;
    f32 v10;
    f32 v11;
    f32 v12;
    f32 v13;
    f32 v14;
    struct { f32 a[3]; } loc_44;
    f32 loc_38[3];
    f32 loc_2C[3];
    f32 loc_20[3];
    f32 loc_14[3];
    f32 loc_8[3];
    void * lab_t0;
    /* frame */

    p_lbl_1_rodata_6C8 = (struct fn_1_21950_lbl_1_rodata_6C8 *)&(*((struct fn_1_21950_lbl_1_rodata_6C8 *)&lbl_1_rodata_6C8));
    v2 = (((0.0f)) != arg1);
    v5 = (((0.0f)) != arg2);
    v4 = ((-0.5f));
    loc_8[0] = v4;
    loc_8[1] = ((0.0f));
    loc_8[2] = ((0.0f));
    loc_8[0] = (v4 * *(f32 *)((u8 *)arg0 + 0));
    lab_t0 = loc_8;
    lbl_8006E1B0(lab_t0, loc_8);
    v6 = ((0.0f));
    v7 = ((0.5f));
    loc_14[1] = v6;
    loc_14[0] = v7;
    loc_14[2] = v6;
    loc_14[0] = (v7 * *(f32 *)((u8 *)arg0 + 0));
    lbl_8006E1B0(loc_14, loc_14);
    if ((s32)v2 != 0) {
    v8 = ((0.0f));
    v9 = ((-0.5f));
    loc_20[1] = v8;
    loc_20[0] = v9;
    loc_20[2] = v8;
    loc_20[0] = (v9 * *(f32 *)((u8 *)arg0 + 0));
    lbl_8006E1B0(loc_20, loc_20);
    v11 = ((0.0f));
    v10 = ((-0.5f));
    loc_2C[1] = arg1;
    loc_2C[0] = v10;
    loc_2C[2] = v11;
    loc_2C[0] = (v10 * *(f32 *)((u8 *)arg0 + 0));
    lbl_8006E1B0(loc_2C, loc_2C);
    }
    if ((s32)v5 != 0) {
    v11_2 = ((0.0f));
    v12 = ((0.5f));
    loc_38[1] = v11_2;
    loc_38[0] = v12;
    loc_38[2] = v11_2;
    loc_38[0] = (v12 * *(f32 *)((u8 *)arg0 + 0));
    lbl_8006E1B0(loc_38, loc_38);
    v14 = ((0.0f));
    v13 = ((0.5f));
    loc_44.a[1] = arg2;
    loc_44.a[0] = v13;
    loc_44.a[2] = v14;
    loc_44.a[0] = (v13 * *(f32 *)((u8 *)arg0 + 0));
    lbl_8006E1B0(&loc_44, &loc_44);
    }
    lbl_8006DAEC();
    lbl_8006DCA4();
    fn_80072558();
    fn_8003462C(0xb0, 0, 2);
    GX_FIFO = loc_8[0];
    GX_FIFO = loc_8[1];
    GX_FIFO = loc_8[2];
    GX_FIFO = loc_14[0];
    GX_FIFO = loc_14[1];
    GX_FIFO = loc_14[2];
    if ((s32)v2 != 0) {
    fn_8003462C(0xb0, 0, 2);
    gx_pos3(loc_20[0], loc_20[1], loc_20[2]);
    gx_pos3(loc_2C[0], loc_2C[1], loc_2C[2]);
    }
    if ((s32)v5 != 0) {
    fn_8003462C(0xb0, 0, 2);
    gx_pos3(loc_38[0], loc_38[1], loc_38[2]);
    gx_pos3(loc_44.a[0], loc_44.a[1], loc_44.a[2]);
    }
    lbl_8006DB30();
}
#pragma opt_propagation reset
/* fzgx:end fn_1_21950 */

/* fzgx:begin fn_1_21BE4 */
typedef struct Fn_1_21BE4 {
    u32 flags;
    unsigned char pad04[0x38];
    f32 field3c;
    f32 field40;
} Fn_1_21BE4;

void fn_1_21BE4(Fn_1_21BE4 *self, void *arg) {
    f32 value2;
    f32 value1;

    fn_1_18214(self, arg, 0);
    if ((self->flags & 0x800) != 0) {
        value2 = self->field3c;
    } else {
        value2 = (*((f32 *)&lbl_1_rodata_6D0));
    }
    if ((self->flags & 0x400) != 0) {
        value1 = self->field40;
    } else {
        value1 = (*((f32 *)&lbl_1_rodata_6D0));
    }
    fn_1_21950( (u32)(void *)(arg), value1, value2);
}
/* fzgx:end fn_1_21BE4 */

/* fzgx:begin fn_1_21C5C */
void fn_1_21C5C(void *self, void *arg) {
    fn_1_18214(self, arg, 0);
    fn_1_21950( (u32)(void *)(arg), lbl_1_rodata_6D4, lbl_1_rodata_6D4);
}
/* fzgx:end fn_1_21C5C */

/* fzgx:begin fn_1_21CA0 */
typedef struct Fn_1_21CA0 {
    u32 flags;
    unsigned char pad04[0x38];
    f32 field3c;
    f32 field40;
} Fn_1_21CA0;

void fn_1_21CA0(Fn_1_21CA0 *self, void *arg) {
    f32 value2;
    f32 value1;

    if ((self->flags & 0x800) != 0) {
        value2 = self->field3c;
    } else {
        value2 = (*((f32 *)&lbl_1_rodata_6D0));
    }
    if ((self->flags & 0x400) != 0) {
        value1 = self->field40;
    } else {
        value1 = (*((f32 *)&lbl_1_rodata_6D0));
    }
    fn_1_21950( (u32)(void *)(arg), value1, value2);
}
/* fzgx:end fn_1_21CA0 */

/* fzgx:begin fn_1_21CFC */
typedef struct StcoliNode StcoliNode;











extern const f32 lbl_1_rodata_6D0; /* 0.0f */
extern const f32 lbl_1_rodata_6E8; /* 0.5f */

/* fzgx-allow: A1 GX FIFO write port; retail materialises it as lis 0xcc01/stfs -0x8000 */
#define STCOLI_GX_WRITE_F32(v) (*(volatile f32 *)(GX_FIFO_BASE + 0x0) = (v)) /* Hardware access must remain ordered. */

static inline void fn_1_21CFC_Position3f32(f32 x, f32 y, f32 z) {
    STCOLI_GX_WRITE_F32(x);
    STCOLI_GX_WRITE_F32(y);
    STCOLI_GX_WRITE_F32(z);
}

void fn_1_21CFC(void *entity, fn_1_21CFC_Vec *scale, f32 t) {
    f32 y;
    f32 z;
    fn_1_21CFC_Vec points[16];
    fn_1_21CFC_Vec *point;
    s32 i;
    s32 angle;

    fn_1_18214(entity, scale, NULL, t);
    z = lbl_1_rodata_6D0;
    point = points;
    for (i = 0, angle = 0; i < 16; i++, angle += 0x1000) {
        y = lbl_1_rodata_6E8 * lbl_8006D188(angle + 0x4000);
        point->x = lbl_1_rodata_6E8 * lbl_8006D188(angle);
        point->y = y;
        point->z = z;
        point->x *= scale->x;
        point->y *= scale->y;
        lbl_8006E1B0( (void *)(fn_1_21CFC_Vec *)(point), (void *)(fn_1_21CFC_Vec *)(point));
        point++;
    }
    lbl_8006DAEC();
    lbl_8006DCA4();
    fn_80072558();
    point = points;
    fn_8003462C(0xB0, 0, 17);
    for (i = 0; i < 16; i++) {
        fn_1_21CFC_Position3f32(point->x, point->y, point->z);
        point++;
    }
    STCOLI_GX_WRITE_F32(points[0].x);
    STCOLI_GX_WRITE_F32(points[0].y);
    STCOLI_GX_WRITE_F32(points[0].z);
    lbl_8006DB30();
}
/* fzgx:end fn_1_21CFC */

/* fzgx:begin fn_1_229EC */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
}
#pragma section code_type ".text"

typedef struct {
    f32 field_0;
    f32 divisor;
    f32 x;
    f32 y;
    u8  pad_10[0x30];
    f32 limit;
} fn_1_229EC_ctrl;

static inline f32 fn_1_229EC_operand(f32 left, f32 right) { return left * right; }
#pragma peephole on
#pragma opt_dead_assignments off
static inline f32 fn_1_229EC_operand_(f32 right, f32 left) { return ((((left)) * ((right)))); }
#pragma opt_dead_assignments reset

#pragma opt_lifetimes off
static inline f32 fn_1_229EC_operand__(f32 left, f32 right) { left *= right; return left; }
static inline f32 fn_1_229EC_operand___(f32 left, f32 right) { left *= right; return left; }
#pragma opt_loop_invariants off
void fn_1_229EC(fn_1_229EC_ctrl *ctrl, f32 *out_pos, f32 *out_mag)
{
    f32 fzgx_live;
    f32 y;
    f32 x;
    f32 delta;
    f32 mag;
    f32 falloff;
    f32 lab_t1;
    fzgx_live = ctrl->x;
    x = fzgx_live;
    y = ctrl->y;
    mag = *out_mag;
{
    f32 total;
    total = 40.0f * x / 348.0f + *out_pos;
    falloff = total / (36.0f + (f32)(40.0f * y));
    delta = total - mag;

    if (falloff < 0.0f) {
        falloff = 0.0f;
    }
    falloff = falloff * (x * (0.6f + x) * 4.0f);
    if (mag < 0.0f) {
        falloff = fn_1_229EC_operand_((5.0f), (falloff));
    }

    *out_pos = total - (f32)(fn_1_229EC_operand__((delta), (falloff)));
}
    {
        f32 lim;
        if (*out_pos > (lim = ctrl->limit)) {
            *out_pos = *out_pos - lim;
        } else {
            *out_pos = 0.0f;
        }
    }

    if (mag < 0.0f) {
        lab_t1 = (0.05f);
        delta = fn_1_229EC_operand((delta), lab_t1);
    }

    *out_mag = *out_mag + (f32)(fn_1_229EC_operand___((1000.0f), (delta))) / ctrl->divisor;
    *out_mag = *out_mag - (f32)((*out_mag * *out_mag) * 8.0f) / ctrl->divisor;
    if (216.0 * *out_mag < 2.0) {
        *out_mag = 0.0f;
    }
}
#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset

#pragma peephole reset
/* fzgx:end fn_1_229EC */

/* fzgx:begin fn_1_22E8C */
typedef struct Fn_1_22E8CInput {
    unsigned char pad00[0x04];
    float field04;
    float field08;
    float field0c;
    float field10;
    float field14;
    float field18;
    float field1c;
    float field20;
    float field24;
    float field28;
    float field2c;
    float field30;
    float field34;
    float field38;
    float field3c;
    float field40;
    float field44;
    unsigned char field48;
    unsigned char field49;
    unsigned char pad4a[0x02];
    float field4c;
    float field50;
} Fn_1_22E8CInput;

typedef struct Fn_1_22E8COutput {
    unsigned int flags;
    unsigned char pad04[0x04];
    float field08;
    float field0c;
    float field10;
    float field14;
    float field18;
    float field1c;
    float field20;
    float field24;
    float field28;
    float field2c;
    float field30;
    float field34;
    float field38;
    unsigned char pad3c[0x1e4];
    float field220;
    unsigned char pad224[0x08];
    float field22c;
    float field230;
    float field234;
    float field238;
    float field23c;
    unsigned char pad240[0x237];
    unsigned char field477;
} Fn_1_22E8COutput;

void fn_1_22E8C(Fn_1_22E8COutput *self, Fn_1_22E8CInput *source) {
    float first = source->field04;
    double scale = lbl_1_rodata_910;

    self->field08 = first;
    self->field0c = source->field10;
    self->field28 = source->field14;
    self->field14 = source->field20;
    self->field1c = source->field28;
    self->field20 = source->field2c;
    self->field24 = source->field30;
    self->field30 = source->field44;
    self->field10 = source->field18;
    self->field2c = source->field1c;
    self->field477 = source->field48;
    self->field34 = source->field4c;
    self->field38 = source->field50;
    self->field18 = source->field24;
    self->field220 = source->field08;
    self->field22c = source->field0c;
    self->field230 = (float)(scale * source->field34);
    self->field234 = source->field38;
    self->field238 = source->field3c;
    self->field23c = source->field40;
    if (source->field49 & 1) {
        self->flags |= 0x100;
    } else {
        self->flags &= ~0x100;
    }
    if (source->field49 & 2) {
        self->flags |= (1u << 31);
    } else {
        self->flags &= 0x7fffffff;
    }
}
/* fzgx:end fn_1_22E8C */

/* fzgx:begin fn_1_23500 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
}
#pragma section code_type ".text"

typedef struct Fn_1_23500_Rodata {
    unsigned char pad00[0xc];
    f32 value0c;
    unsigned char pad10[0x4];
    f32 value14;
    unsigned char pad18[0x38];
    f64 value50;
    unsigned char pad58[0x98];
    f32 valuef0;
} Fn_1_23500_Rodata;


typedef struct Fn_1_23500 {
    int flags;
    unsigned char pad04[4];
    f32 field08;
    unsigned char pad0c[0x88];
    f32 field94;
    unsigned char pad98[0x168];
    f32 field200;
    unsigned char pad204[0x20];
    f32 field224;
    unsigned char pad228[0x259];
    unsigned char field481;
} Fn_1_23500;

void fn_1_23500(Fn_1_23500 *self, f32 value) {
    Fn_1_23500_Rodata *table;
    f64 factor;
    f32 amount;
    f32 one;

    table = (Fn_1_23500_Rodata *)lbl_1_rodata_840;
    factor = value / (216.0);
    amount = factor * self->field08;
    fn_1_22F90(self, 1);
    if ((0.0f) != value) {
        lbl_8006E1F0(&self->field94, (0.0f), (0.0f), -amount);
        one = (1.0f);
        self->field224 = value / (200.0f);
        self->flags |= 0x400;
        self->field200 = one;
        self->field481 = 0x5a;
    }
    fn_1_8A190(self, (void *)(int)(1));
}
/* fzgx:end fn_1_23500 */

/* fzgx:begin fn_1_235C8 */
typedef struct Fn_1_235C8 {
    unsigned char *field00;
    unsigned char *field04;
    unsigned char data[0xb8];
} Fn_1_235C8;

void fn_1_235C8(Fn_1_235C8 *self) {
    if (self != 0) {
        memset(self, 0, 0xc0);
        self->field00 = &self->data[0];
        self->field04 = &self->data[0x5c];
    }
}
/* fzgx:end fn_1_235C8 */

/* fzgx:begin fn_1_23610 */
void fn_1_23610(void *self) {
    if (self != 0) {
        memset(self, 0, 0x194);
    }
}
/* fzgx:end fn_1_23610 */

/* fzgx:begin fn_1_23640 */
typedef struct Fn_1_23640 {
    unsigned char pad00[0x80];
    int field80;
    unsigned char pad84[0x0c];
    int *field90;
    int *field94;
    unsigned char pad98[0x04];
    int field9c;
    unsigned char padA0[0x18];
    int fieldb8;
    unsigned char padbc[0x0c];
    int fieldc8;
    unsigned char padcc[0x0c];
    int fieldd8;
    unsigned char pade0[0x40];
    int field11c;
    unsigned char pad120[0x3c];
    int field15c;
    unsigned char tail160[0x9c];
} Fn_1_23640;

void fn_1_23640(Fn_1_23640 *self, int value) {
    if (self != 0) {
        if (value != 0) {
            memset(self, 0, 0x1fc);
            self->field11c = -1;
            self->field15c = -1;
        } else {
            memset(self, 0, 0x117);
        }
        self->field80 = value;
        self->field90 = &self->fieldb8;
        self->field94 = &self->fieldc8;
        self->field9c = -1;
        self->fieldb8 = -1;
        self->fieldd8 = -1;
    }
}
/* fzgx:end fn_1_23640 */

/* fzgx:begin fn_1_248C0 */
typedef struct Fn_1_248C0 {
    u32 unk_00;
    unsigned char pad04[0x471];
    signed char unk_475;
    unsigned char pad476[0x3d];
    unsigned char unk_4b3;
} Fn_1_248C0;

// Updates the collision state and reports whether the current flags trigger a response.
int fn_1_248C0(Fn_1_248C0 *self, int arg) {
    int result;
    int test;

    result = 0;
    if (self->unk_00 & 0x800) {
        if (self->unk_00 & 1) {
            result = 1;
        } else if (self->unk_00 & 0x10000) {
            result = 1;
        }
        if (!(self->unk_00 & 0x10000) && self->unk_4b3 == 0) {
            if (*(s16 *)&lbl_1_bss_960 == 9 && lbl_1_bss_9C == 5) {
            } else if (lbl_1_bss_9C == 6) {
            } else if (self->unk_475 != -1 && !(self->unk_00 & 0x04000200)) {
                fn_1_A2D84(0xA9072100);
            }
            self->unk_4b3 = 1;
        }
    } else {
        test = self->unk_00 & 0x80;
        if (test && self->unk_4b3 == 0 && !(self->unk_00 & 0x10000)) {
            if (self->unk_475 != -1 && !(self->unk_00 & 0x04000200)) {
                fn_1_A2D84(0xA9072200);
            }
            self->unk_4b3 = 1;
        }
        if ((self->unk_00 & 1) && test) {
            if ((self->unk_00 & 0x02810000) || arg) {
                result = 1;
            }
        }
    }
    if ((self->unk_00 & 0x40000000) && (self->unk_00 & 1)) {
        result = 1;
    }
    if (self->unk_00 & 0x10000000) {
        result = 0;
    }
    return result;
}
/* fzgx:end fn_1_248C0 */

/* fzgx:begin fn_1_24F10 */
typedef struct Fn_1_24F10 {
    int flags;
    unsigned char pad04[0x2c];
    f32 field30;
    unsigned char pad34[0x150];
    f32 field184;
    unsigned char pad188[0x8c];
    u16 field214;
    unsigned char pad216[0x0e];
    f32 field224;
    unsigned char pad228[0x284];
    f32 field4ac;
    unsigned char pad4b0[0xe3];
    u8 field593;
    unsigned char pad594[0x46];
    u16 field5da;
} Fn_1_24F10;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
}
static const u32 fzgx_pool_table14[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
}
#pragma section code_type ".text"
int fn_1_24F10(Fn_1_24F10 *self, f32 value) {
    f32 amount;
    f32 dist;
    int result;

    if (self->field214 != 0 || self->field593 != 0) {
        return 0;
    }

    amount = value * self->field30;
    if ((self->flags & 0x200) == 0 && amount > 20.0f) {
        amount = 20.0f;
    }

    if (amount > 1.01f * (f32)self->field5da) {
        amount = 1.01f * (f32)self->field5da;
    }

    self->field4ac = amount;
    dist = self->field184 - self->field4ac;
    self->field184 = dist;
    if (dist < 0.0f) {
        if ((self->flags & 0x10080) != 0) {
            result = 0;
        } else {
            result = 1;
            self->field593 = 0x3c;
        }
        self->flags |= 0x80;
        self->field184 = 0.0f;
        self->field224 = 0.0f;
        return result;
    }

    return 0;
}
/* fzgx:end fn_1_24F10 */

/* fzgx:begin fn_1_25004 */
typedef struct Fn_1_25004_Obj {
    u32 flags00;
    s16 field04;
    u8 pad06[0x8e];
    f32 field94;
    f32 field98;
    f32 field9c;
    f32 fielda0;
    f32 fielda4;
    f32 fielda8;
    u8 padac[0xd0];
    f32 field17c;
    u8 pad180[0x4];
    f32 field184;
    u8 pad188[0x9c];
    f32 field224;
    u8 pad228[0x24c];
    u8 field474;
    u8 pad475[0x117];
    u32 flags58c;
} Fn_1_25004_Obj;

typedef struct Fn_1_25004_Result {
    u8 pad390[0x390];
    u32 flags390;
} Fn_1_25004_Result;

#pragma opt_strength_reduction off
void fn_1_25004(Fn_1_25004_Obj *self) {
    Fn_1_25004_Result *result;
    f32 zero;

    result = (Fn_1_25004_Result *)fn_1_868C0((s8)self->field04);
    if ((self->flags58c & 0x10) == 0) {
        if ((s8)self->field474 != -1) {
            fn_1_F7338((s8)self->field474, (void *)(int)(2), (void *)(int)(0x1e));
        }
        zero = (0.0f);
        self->flags00 |= 0x800;
        self->flags00 |= 0x80;
        self->flags00 |= 0x800000;
        self->flags00 |= 0x40000000;
        self->flags58c |= 0x10;
        self->field184 = zero;
        self->field224 = zero;
        self->field94 = zero;
        self->field98 = zero;
        self->field9c = zero;
        self->fielda0 = zero;
        self->fielda4 = zero;
        self->fielda8 = zero;
        self->field17c = zero;
        self->flags58c &= ~0x80;
        result->flags390 &= ~0x200000;
        result->flags390 |= 0x1000000;
    }
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_25004 */

/* fzgx:begin fn_1_250F8 */
typedef struct Fn_1_250F8 {
    u32 flags;
    u8 pad04[0x180];
    f32 field184;
    u8 pad188[0x88];
    u16 field210;
    u8 pad212[0x01];
    u8 field213;
    u8 pad214[0x03];
    u8 field217;
    u8 pad218[0x29A];
    u8 field4b2;
    u8 pad4b3[0xD9];
    u32 field58c;
} Fn_1_250F8;

void fn_1_250F8(Fn_1_250F8 *self) {
    u16 value;
    f32 add;
    f32 elapsed;
    u32 delta;

    if ((self->flags & 0x10000) == 0) {
        value = self->field210;
        add = lbl_1_rodata_85C * self->field184;
        elapsed = (f32)value + add;
        delta = ((u32)self->field213 * 60) / 60;
        self->field210 = (s32)elapsed;
        if (self->field217 == 0) {
            self->field210 += 25;
        }
        if (self->field4b2 == 0) {
            self->field210 += 25;
        }
        if ((self->field58c & 1) == 0) {
            self->field210 += 40;
        }
        if (self->flags & 0x80) {
            self->field210 += 25;
        }
        if (self->field210 > delta) {
            self->field210 -= delta;
        } else {
            self->field210 = 0;
        }
    }
    self->flags |= 0x10000;
}
/* fzgx:end fn_1_250F8 */

/* fzgx:begin fn_1_251F8 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
}
#pragma section code_type ".text"
#pragma fp_contract off



s32 fn_1_251F8(Vec3 *a, Vec3 *b, Vec3 *c, Vec3 *d, f32 *out, s32 *flag, f32 p, f32 q) {
    f32 ux;
    f32 uy;
    f32 uz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 len2;
    f32 cterm;
    f32 dt;
    f32 disc;

    *out = 100.0f;
    *flag = 0;

    ux = a->x - c->x;
    uy = a->y - c->y;
    uz = a->z - c->z;
    dx = b->x - d->x - ux;
    dy = b->y - d->y - uy;
    dz = b->z - d->z - uz;
    len2 = dx * dx + dy * dy + dz * dz;

    if (1.1920929e-07f > len2) {
        *flag = 1;
        return 0;
    }

    dt = ux * dx + uy * dy + uz * dz;
    cterm = ux * ux + uy * uy + uz * uz - (p + q) * (p + q);
    disc = dt * dt - len2 * cterm;

    if (0.0f > disc) {
        return 0;
    }
    if (0.0f >= cterm) {
        *out = 0.0f;
        return 1;
    }
    if (0.0f >= (cterm + (dt + (len2 + dt)))) {
        goto compute; /* Keep the verified branch to compute. */
    }
    if (0.0f <= dt) {
        return 0;
    }
    if (-dt >= len2) {
        return 0;
    }
compute:
    *out = -(dt + lbl_8006D0B4(disc)) / len2;
    return 1;
}
/* fzgx:end fn_1_251F8 */

/* fzgx:begin fn_1_25870 */
typedef struct Fn_1_25870 {
    u32 flags;
    unsigned char pad04[0x1f4];
    f32 field1f8;
    f32 field1fc;
    unsigned char pad200[0x24];
    f32 field224;
    unsigned char pad228[0x1c];
    u32 field244;
    unsigned char pad248[0x58];
    u32 field2a0;
    unsigned char pad2a4[0x58];
    u32 field2fc;
    unsigned char pad300[0x58];
    u32 field358;
    unsigned char pad35c[0x11a];
    u8 field476;
    u8 field477;
} Fn_1_25870;

void fn_1_25870(Fn_1_25870 *self) {
    unsigned char *data = lbl_1_rodata_840;
    u32 flags;
    int trigger;

    if (self->field476 != 0) {
        self->field476--;
    }
    flags = self->flags;
    if ((flags & 0x2) == 0) {
        if (self->field224 > *(f32 *)(data + 0x18)) {
            if ((flags & 0x2000) != 0) {
                self->field244 &= ~4;
                self->field2a0 &= ~4;
                self->field2fc &= ~4;
                self->field358 &= ~4;
                self->field476 = self->field477;
            } else {
                trigger = 0;
                if ((flags & 0x1000) != 0 &&
                    __fabs(self->field1fc) > *(f64 *)(data + 0x1b8)) {
                    trigger = 1;
                }
                if ((self->flags & 0x8) != 0) {
                    trigger = 1;
                }
                if (trigger != 0) {
                    self->field244 |= 4;
                    self->field2a0 |= 4;
                    self->field2fc |= 4;
                    self->field358 |= 4;
                }
            }
        }
    } else {
        self->field244 &= ~4;
        self->field2a0 &= ~4;
        self->field2fc &= ~4;
        self->field358 &= ~4;
    }
    flags = self->flags;
    if ((flags & 0x4000) != 0 &&
        __fabs(self->field1fc) < *(f64 *)(data + 0x1b8)) {
        self->flags = flags & ~0x4000;
    }
    if (__fabs(self->field1f8) > *(f64 *)(data + 0x1c0)) {
        self->flags |= 0x4000;
    }
    if ((self->flags & 0x4000) == 0) {
        return;
    }
    self->field244 |= 0x10;
    self->field2a0 |= 0x10;
    self->field2fc |= 0x10;
    self->field358 |= 0x10;
}
/* fzgx:end fn_1_25870 */

/* fzgx:begin fn_1_27DE4 */
typedef struct {
    u32 flags;
    u8 pad_4[0x78];
    Vec3 position;
    Vec3 previous;
    u8 pad_94[0x140];
    Vec3 displacement;
} CollisionObject;

void fn_1_27DE4(CollisionObject *obj)
{
    Vec3 delta;
    if (!(obj->flags & 0x8000)) {
        psvec_sub(&obj->position, &obj->previous, &delta);
        psvec_add(&obj->displacement, &delta, &obj->displacement);
    }
}
/* fzgx:end fn_1_27DE4 */

/* fzgx:begin fn_1_28660 */
typedef struct Fn_1_28660 {
    int field00;
    short field04;
    unsigned char pad06[0x212];
    int field218;
    unsigned char pad21c[0x2e0];
    int field4fc;
    unsigned char pad500[0x8c];
    int field58c;
} Fn_1_28660;

void fn_1_28660(Fn_1_28660 *self) {
    int result;
    int mask;

    lbl_8006DAEC();

    mask = 0x88;
    if ((self->field58c & 0x2) == 0) {
        mask |= 0x10;
    }
    if ((self->field4fc & 0x00100000) == 0) {
        mask |= 0x2;
    }
    if ((self->field4fc & 0x00080000) == 0) {
        mask |= 0x20;
    }
    if ((self->field4fc & 0x00040000) == 0) {
        mask |= 0x40;
    }
    if ((self->field4fc & 0x00020000) == 0) {
        mask |= 0x80;
    }

    if ((self->field00 & 0x2) != 0) {
        result = 0;
    } else {
        result = fn_1_163BC((char *)self + 0x7c, (char *)self + 0x88,
            mask, (int)fn_1_8C66C(self->field04));
    }

    if ((result & 0x8) != 0) {
        self->field00 |= 0x00600000;
        self->field218 |= 0x10000000;
    }
    if ((self->field4fc & 0x00100000) != 0 ||
        (result & 0x2) != 0) {
        if ((self->field00 & 0x80) == 0) {
            self->field58c |= 1;
            self->field218 |= 0x08000000;
        }
    }
    if ((self->field00 & 0x20) == 0) {
        if ((self->field4fc & 0x00040000) != 0 ||
            (result & 0x40) != 0) {
            self->field218 |= 0x20000000;
        }
    }
    if ((self->field4fc & 0x00080000) != 0 ||
        (result & 0x20) != 0) {
        self->field218 |= 0x80000000u;
    }
    if ((result & 0x10) != 0) {
        self->field218 |= 0x04000000;
    }
    if ((self->field4fc & 0x00020000) != 0 ||
        (result & 0x80) != 0) {
        self->field218 |= 0x02000000;
    }

    lbl_8006DB30();
}
/* fzgx:end fn_1_28660 */

/* fzgx:begin fn_1_287E8 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
    s = 6.0f;
    s = 300.0f;
}
#pragma section code_type ".text"


typedef struct Fn_1_287E8 {
    unsigned int flags;
    unsigned char pad04[0x178];
    f32 field17c;
    unsigned char pad180[0x10];
    unsigned int field190;
    unsigned short field194;
    unsigned char field196;
    unsigned char pad197[0x65];
    f32 field1fc;
    f32 field200;
    unsigned char pad204[0x0e];
    s8 field212;
    unsigned char pad213[0x26d];
    unsigned char field480;
    unsigned char pad481[0x43];
    unsigned char field4c4;
} Fn_1_287E8;

#pragma opt_common_subs off
#pragma opt_dead_assignments on
void fn_1_287E8(Fn_1_287E8 *self) {
    f32 * table;
    table = (((f32 *)&lbl_1_rodata_840));

    if (self->field17c < (300.0f)) {
        if (!self->field190) {
            self->flags = ((~8) & (self->flags));
        }
        self->flags = self->flags & ~0x20000;
    }

    if (self->field480 != 0) {
        self->flags = self->flags & ~8;
    }

    if ((self->flags & 8) != 0) {
        u32 total = self->field190;

        if (total == 0) {
            self->field190 = 0x40000;
            self->field194 = 0x1000;
            if (self->field1fc > (0.0f)) {
                self->field196 = 0;
            } else {
                self->field196 = 1;
            }
        } else {
            u16 step = self->field194;

            if (total > step) {
                self->field190 = total - step;
                if (self->field190 < 0x20000) {
                    self->field194 = self->field194 - 0x41;
                    if (self->field194 < 0x50) {
                        self->field194 = 0x50;
                    }
                }
            } else {
                self->field190 = 0;
                self->field194 = 0;
                self->flags = self->flags & ~8;
            }
        }
        self->flags = self->flags & ~0x20000;
    } else {
        self->field190 = 0;
    }

    if (self->flags & 0x20000) {
        u8 counter;

        counter = self->field480;
        if (counter == 0) {
            self->field480 = 6;
        } else if (counter == 1) {
            self->flags = self->flags & ~0x20000;
        } else {
            self->field480 = counter - 1;
        }

        if ((self->flags & 0x02800000) != 0 ||
            self->field200 < (0.5f)) {
            self->flags = self->flags & ~0x20000;
            self->field480 = 1;
        }
    } else {
        self->field480 = 0;
    }

    if (self->field4c4 != 0) {
        self->field4c4 -= 1;
    }

    if ((self->flags & 0x20008) != 0) {
        return;
    }
    self->field212 = 0;
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_287E8 */

/* fzgx:begin fn_1_28F08 noprologue */
#include "dolphin/types.h"

extern const struct fn_1_28F08_lbl_1_rodata_840_pool {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x24C];
    f32 unk_25C;
    u8 pad_260[0x48];
    f32 unk_2A8;
    f32 unk_2AC;
} lbl_1_rodata_840;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 m[10];
    f64 d;
} Mtx;

typedef struct {
    f32 pad[43];
    f32 inv_x;
    f32 inv_y;
    f32 inv_z;
} ScaleInfo;

extern f32 lbl_8006D0B4(f32);
extern void fn_8006E7E4(void *, void *, s32);
extern void lbl_8006DAEC(void);
extern void mathutil_mtxA_from_quat(void *);
extern void lbl_8006DB74(Mtx *);
extern void lbl_8006DB30(void);
extern void lbl_8006DFC4(Mtx *);

static inline f32 fn_1_28F08_operand(f32 left, f32 right) { return left + right; }
#pragma opt_common_subs off
#pragma opt_propagation off
static inline f32 fn_1_28F08_read_pointer(Vec3 * owner) { return owner->z; }
void fn_1_28F08(ScaleInfo *scale, Vec3 *src, f32 bias)
{
    f32 fzgx_live;
    struct fn_1_28F08_lbl_1_rodata_840_pool *pool_lbl_1_rodata_840 = (struct fn_1_28F08_lbl_1_rodata_840_pool *)&lbl_1_rodata_840;
    Vec3 v;
    Mtx mtx;
    f32 sum;
    f32 len;

    v.x = src->x;
    v.y = src->y + bias;
    v.z = src->z;

    if (v.x > pool_lbl_1_rodata_840->unk_25C) {
        v.x -= pool_lbl_1_rodata_840->unk_25C;
    } else if (v.x < pool_lbl_1_rodata_840->unk_2A8) {
        v.x += pool_lbl_1_rodata_840->unk_25C;
    } else {
        v.x = pool_lbl_1_rodata_840->unk_C;
    }

    if (fn_1_28F08_read_pointer(&v) > pool_lbl_1_rodata_840->unk_25C) {
        v.z -= pool_lbl_1_rodata_840->unk_25C;
    } else if (fn_1_28F08_read_pointer(&v) < pool_lbl_1_rodata_840->unk_2A8) {
        v.z += pool_lbl_1_rodata_840->unk_25C;
    } else {
        v.z = pool_lbl_1_rodata_840->unk_C;
    }

    v.x = v.x / scale->inv_x;
    fzgx_live = v.y;
    v.y = fzgx_live / scale->inv_y;
    v.z = fn_1_28F08_read_pointer(&v) / scale->inv_z;

    fzgx_live = v.y;
    len = lbl_8006D0B4(fn_1_28F08_operand((v.x * v.x), (fzgx_live * fzgx_live)) + fn_1_28F08_read_pointer(&v) * fn_1_28F08_read_pointer(&v));

    fn_8006E7E4(&v, &v, (s32)(pool_lbl_1_rodata_840->unk_2AC * len));
    lbl_8006DAEC();
    mathutil_mtxA_from_quat(&v);
    lbl_8006DB74(&mtx);
    lbl_8006DB30();
    lbl_8006DFC4(&mtx);
}
#pragma opt_propagation reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_28F08 */

/* fzgx:begin fn_1_29968 noprologue */
#include "dolphin/types.h"

extern const struct fn_1_29968_lbl_1_rodata_840_pool {
    u8 pad_0[0x14];
    f32 unk_14;
    u8 pad_18[0x50];
    f32 unk_68;
    u8 pad_6C[0x12C];
    f32 unk_198;
    u8 pad_19C[0x164];
    f32 unk_300;
    f32 unk_304;
} lbl_1_rodata_840;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 m[10];
    f64 d;
} Mtx;

typedef struct {
    u8 pad_0[0x254];
    f32 unk_254;
    u8 pad_258[0xB4];
    f32 unk_30C;
    u8 pad_310[0x2D0];
    Mtx unk_5E0;
} Owner;

extern void lbl_8006DAEC(void);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void lbl_8006DB74(Mtx *);
extern void lbl_8006DB30(void);

#pragma opt_common_subs off
#pragma opt_loop_invariants off
void fn_1_29968(Owner *self)
{
    f32 fzgx_live;
    f32 num;
    f32 v;
    f32 scale;
    struct fn_1_29968_lbl_1_rodata_840_pool *pool_lbl_1_rodata_840 = (struct fn_1_29968_lbl_1_rodata_840_pool *)&lbl_1_rodata_840;
    f32 step;
    f32 t;

    lbl_8006DAEC();
    fzgx_live = -self->unk_254;
    num = self->unk_30C;
    t = num;
    t = t / fzgx_live;
    v = t - pool_lbl_1_rodata_840->unk_14;
    scale = pool_lbl_1_rodata_840->unk_198;
    step = pool_lbl_1_rodata_840->unk_300;
    v = (v < pool_lbl_1_rodata_840->unk_304) ? pool_lbl_1_rodata_840->unk_304 : ((v > pool_lbl_1_rodata_840->unk_68) ? pool_lbl_1_rodata_840->unk_68 : v);
    mathutil_mtxA_rotate_x((s32)(scale * (step * v)));
    lbl_8006DB74(&self->unk_5E0);
    lbl_8006DB30();
}
#pragma opt_loop_invariants reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_29968 */

/* fzgx:begin fn_1_2A214 noprologue */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const unsigned long fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const unsigned long fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const unsigned long fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
    s = 1.1920928955078125e-07f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const unsigned long fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
}
#pragma section code_type ".text"
typedef struct {
    unsigned int flags;
    unsigned char pad4[0x9c];
    float a0;
    float a4;
    float a8;
    float pad_ac;
    float b0;
} StColiObj;

extern float lbl_1_rodata_840[];
extern double __fabs(double);

#pragma opt_strength_reduction off
void fn_1_2A214(StColiObj *obj)
{
    float limit;
    struct { float *value; } c;
    c.value = lbl_1_rodata_840;

    if (obj->flags & 2) {
        float k0 = (0.899999976f);
        float k1 = (0.99000001f);
        obj->a0 = obj->a0 * k0;
        obj->a8 = obj->a8 * k1;
        limit = obj->b0;
    } else if (obj->flags & 0x10) {
        limit = (0.200000003f) * obj->b0;
    } else {
        limit = (0.0500000007f) * obj->b0;
    }
    if (__fabs(obj->a4) > limit) {
        if (obj->a4 < (0.0f)) {
            obj->a4 = -limit;
        } else {
            obj->a4 = limit;
        }
    }
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_2A214 */

/* fzgx:begin fn_1_2A2A4 */
typedef struct {
    u8 pad00[0xec];
    u8 field_ec[0xd0];
    u8 pad_1bc[0x1bc];
} Fn1_2A2A4Object;


void fn_1_2A2A4(Fn1_2A2A4Object *self) {
    u8 local_14[12];
    u8 local_8[12];
    f32 value_1;
    f32 value_2;

    value_1 = lbl_1_rodata_84C;
    value_2 = lbl_1_rodata_854;
    lbl_8006E1F0(local_8, value_1, value_2, value_1);
    lbl_8006DAEC();
    fn_8006E978( (f32 *)(void *)(local_14), (Vec3 *)(void *)(local_8), (Vec3 *)(void *)(self->pad_1bc));
    mathutil_mtxA_from_quat(local_14);
    lbl_8006DFC4(self->field_ec);
    lbl_8006DB74(self->field_ec);
    lbl_8006DB30();
}
/* fzgx:end fn_1_2A2A4 */

/* fzgx:begin fn_1_2A318 */
typedef struct Fn_1_2A318 {
    unsigned char pad000[0x184];
    f32 field184;
    unsigned char pad188[0x02];
    unsigned char field18a;
    unsigned char pad18b[0x85];
    u16 field210;
    unsigned char field212;
    unsigned char pad213[0x26f];
    unsigned char field482;
    unsigned char pad483[0x10f];
    unsigned char field592;
    unsigned char pad593[0x47];
    u16 field5da;
} Fn_1_2A318;

void fn_1_2A318(Fn_1_2A318 *self) {
    u16 value;
    f32 progress;

    self->field482++;
    self->field212++;
    self->field210 += self->field212 * (self->field18a ? 15 : 10);
    if (self->field592 == 0) {
        self->field592 = 1;
    }
    value = self->field5da;
    progress = self->field184;
    if (progress < value) {
        progress += lbl_1_rodata_B74[0];
        self->field184 = progress;
        if (progress > value) {
            self->field184 = self->field5da;
        }
    }
}
/* fzgx:end fn_1_2A318 */

/* fzgx:begin fn_1_2A3E4 */
typedef struct Fn_1_2A3E4 {
    u32 flags;
    unsigned char pad04[0x186];
    u8 active;
    unsigned char pad18b[0x85];
    u16 value210;
} Fn_1_2A3E4;

void fn_1_2A3E4(Fn_1_2A3E4 *self) {
    if (self->active != 0) {
        if (self->flags & 0x00200000) {
            self->value210 += 0x14;
        } else {
            self->value210 += 0xA;
        }
    }
}
/* fzgx:end fn_1_2A3E4 */

/* fzgx:begin fn_1_2A41C */
typedef struct Fn_1_2A41C {
    u32 flags;
    unsigned char pad04[0x190];
    u16 value194;
} Fn_1_2A41C;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
    d = 13.88888888888889;
    s = 13.88888931274414f;
}
static const u32 fzgx_pool_table14[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 0.949999988079071f;
    s = 2.200000047683716f;
    s = -0.5f;
    s = 0.0020000000949949026f;
    s = 0.0010000000474974513f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    d = 0.1;
    s = 80.0f;
    s = 1700.0f;
    d = 90.0;
    s = 0.3333333432674408f;
    s = -5000.0f;
    s = 900.0f;
    s = -10000.0f;
    s = 10.0f;
    s = 100.0f;
    s = 400.0f;
    s = 0.9900000095367432f;
    s = 20.0f;
    s = 1.0099999904632568f;
    d = 1.0;
    d = 0.550000011920929;
    s = 3.4000000953674316f;
    s = 0.75f;
    s = 182.04444885253906f;
    s = -45.0f;
    d = 0.9259259259259259;
    d = 5.555555555555555;
    s = 1.1299999952316284f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.10000000149011612;
    d = 0.30000001192092896;
    d = 0.046296296296296294;
    s = 0.8999999761581421f;
    s = 1.1100000143051147f;
    d = 0.0023148148148148147;
    d = 0.5;
    d = 0.004629629629629629;
    d = 0.023148148148148147;
    s = 2000.0f;
    s = 500.0f;
    d = 0.2;
    s = 0.6399999856948853f;
    s = 0.3499999940395355f;
    d = 1.8518518518518519;
    d = 3.4000000953674316;
    d = 1.7000000476837158;
    d = 3.0;
    d = 1.5;
    s = -0.4000000059604645f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.240740740740741;
    s = -1.0f;
    s = 9.999999747378752e-05f;
    s = 0.014000000432133675f;
    s = 9.0f;
    s = 60.0f;
    s = 3.0f;
    s = 0.1666666716337204f;
    s = 1200.0f;
    s = 1600.0f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1000.0;
    d = 0.699999988079071;
    d = 1.1920928955078125e-07;
    s = 0.003000000026077032f;
    s = 0.125f;
    s = -2000.0f;
    s = 600.0f;
    s = 6.0f;
    s = 300.0f;
    s = 1.1111111640930176f;
    s = 10000.0f;
    s = -3.0f;
    s = 10430.3779296875f;
    d = 0.0;
    s = 0.9919999837875366f;
    s = 0.00800000037997961f;
    s = 50.0f;
    s = 15.0f;
    s = 4000.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 3.6;
    s = 1.2999999523162842f;
    s = 0.009000000543892384f;
    d = 9990.0;
    s = 46.25f;
    s = 1100.0f;
    s = 120.0f;
    s = -50.0f;
    d = 4503601774854144.0;
    s = 30.0f;
    s = -0.20000000298023224f;
    s = 90.0f;
    s = 0.006000000052154064f;
    d = 4.62962962962963;
    s = -5.0f;
    s = 4.5f;
    s = 3640.0f;
    s = 2.5f;
    s = -0.30000001192092896f;
    s = 5.999999848427251e-05f;
    s = 65536.0f;
    s = 6.666666507720947f;
    s = 3.5f;
    s = 0.000244140625f;
}
#pragma section code_type ".text"
f32 fn_1_2A41C(Fn_1_2A41C *self, int arg) {
    f32 result;
    u32 flags;
    f32 delta;
    f32 half;
    f32 scaled;
    f32 t;

    flags = self->flags;
    result = 1.0f;
    if ((flags & 0x20008) != 0) {
        if ((flags & 0x200) != 0) {
            if ((flags & 8) != 0) {
                result *= 3.5f;
            } else {
                result *= 4.0f;
            }
        } else {
            delta = (f32)self->value194;
            delta *= 0.000244140625f;
            half = 0.5f;
            scaled = half * delta;
            t = half + scaled;
            if (arg != 0) {
                if ((flags & 8) != 0) {
                    result *= 5.0f * t;
                } else {
                    result *= 6.0f;
                }
            } else {
                if ((flags & 8) != 0) {
                    result *= 3.0f * t;
                } else {
                    result *= 2.0f;
                }
            }
        }
    } else {
        if ((flags & 0x200) != 0) {
            result *= 0.8f;
        }
    }
    return result;
}
/* fzgx:end fn_1_2A41C */

/* fzgx:begin fn_1_2A500 */
/* result block passed to the helper; the helper fills scale and vec */
struct CalcOut {
    u32 flags;
    void *self;
    f32 scale;
    Vec3 v;
};


static inline f32 fn_1_2A500_read_pointer(Vec3 * owner) { return owner->x; }
static inline f32 fn_1_2A500_read_y(Vec3 * owner) { return owner->y; }
static inline f32 fn_1_2A500_read_z(Vec3 * owner) { return owner->z; }
#pragma opt_common_subs off
s32 fn_1_2A500(void *self, Vec3 *out, Vec3 *pos, void *a, void *b, f32 *outF)
{
    u32 *fzgx_value;
    void *mgr = (void *)fn_1_8627C(*(s16 *)((u8 *)self + 4));
    struct CalcOut res;
    s32 found_2;
    s32 found;
    f32 f;

    lbl_8006DAEC();

    res.v = *out;
    fzgx_value = &(res.flags);
    *fzgx_value = *(u32 *)((u8 *)self + 0x498);
    res.self = self;

    found = fn_1_15578(&res.v, pos, &res.scale, a, b,
                       (u8 *)mgr + 0x9C, *(u32 *)((u8 *)mgr + 0x98), 0);

    if (found != 0) {
        f32 dz = fn_1_2A500_read_z(out);
        f32 dy = fn_1_2A500_read_y(out);
        f32 dx = fn_1_2A500_read_pointer(out);
        f32 d;

        dz = dz - pos->z;
        dy = dy - pos->y;
        dx = dx - pos->x;
        d = (f32)(dx * dx);
        d = d + dy * dy;
        d = d + dz * dz;

        f = ((((const f32 *)&lbl_1_rodata_854))[0] - res.scale) * lbl_8006D0B4(d);

        *out = res.v;
        found_2 = 1;
    } else {
        f = (((const f32 *)&lbl_1_rodata_84C))[0];
        found_2 = 0;
    }

    lbl_8006DB30();
    *outF = f;
    return found_2;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_2A500 */

/* fzgx:begin fn_1_2A638 */
typedef struct Fn_1_2A638 {
    unsigned char pad00[0x08];
    f32 field08;
    f32 field0c;
    f32 field10;
    unsigned char pad14[0x30];
    f32 field44;
    f32 field48;
} Fn_1_2A638;

void fn_1_2A638(void *arg0, Fn_1_2A638 *self) {
    lbl_8006E1D8((char *)self + 0x14, self->field08,
        self->field0c + self->field44 - self->field48, self->field10);
}
/* fzgx:end fn_1_2A638 */

/* fzgx:begin fn_1_2A678 */
typedef struct Fn_1_2A678_Values {
    int x;
    int y;
    int z;
} Fn_1_2A678_Values;

typedef struct Fn_1_2A678_Source {
    unsigned char pad00[0x7c];
    Fn_1_2A678_Values values;
} Fn_1_2A678_Source;

typedef struct Fn_1_2A678_Dest {
    unsigned char pad00[0xc];
    Fn_1_2A678_Values values;
} Fn_1_2A678_Dest;

void fn_1_2A678(Fn_1_2A678_Source *self, Fn_1_2A678_Dest *dest) {
    dest->values = self->values;
}
/* fzgx:end fn_1_2A678 */

/* fzgx:begin fn_1_2A694 noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/stcoli.h"

extern int fn_1_15578(void *, void *, void *, void *, u32, void *, void *, void *, u32, void *);
extern void *fn_1_14F04(void); extern int fn_1_868C0(s8); extern void fn_1_F7338(int,int,int);
extern const f64 lbl_1_rodata_84C; extern void lbl_8006DAEC(void); extern void lbl_8006DB30(void);
typedef struct N { u8 p[0x98]; u32 v98; u32 v9c; } N;
typedef struct O { u32 flags; s16 id; u8 p[0x46e]; u8 v474; u8 p2[0x23]; u32 field498; N *field49c; u8 p3[0xec]; u32 field58c; } O;
typedef struct R { u8 p[0x160]; u32 flags160; u8 p2[0x1c]; u32 v180; u32 v184; u32 v188; } R;
typedef struct V { f32 x; f32 y; f32 z; } V; typedef struct F { f32 x; f32 y; f32 z; } F; typedef struct P { u32 x; u32 y; } P;
#pragma opt_propagation off
int fn_1_2A694(O *self, void *arg1, V *swap, u32 mask, V *out0, V *out1) {
 F local; f32 work[4]; R *result; int status; int actor;
 if ((self->flags&2)==0) mask&=0xfffff8ff;
 { psvec_set(&local.x, *(const f32 *)(LC_BASE + 0x2C), *(const f32 *)(LC_BASE + 0x1C), *(const f32 *)(LC_BASE + 0xC)); } lbl_8006DAEC();
 status=fn_1_15578(&local,arg1,&work[0],&work[1],mask,&self->field49c->v9c,(void *)self->field49c->v98,swap,self->field498,self); lbl_8006DB30();
 if(((0) != (swap))){u32 t=*(u32 *)swap;*(u32 *)swap=*(((1) + ((u32 *)swap)));*(((1) + ((u32 *)swap)))=t;}
 if(status!=0){result=(R *)fn_1_14F04(); if(result->flags160==0x100){self->flags|=0x800;status=0;}else{
  *(P *)out0=*(P *)&result->v180;*(u32 *)((u8 *)out0+8)=result->v188; *(P *)out1=*(P *)&local;*(u32 *)((u8 *)out1+8)=*(u32 *)&local.z;
  if((result->flags160&0x600)!=0){actor=fn_1_868C0((s8)self->id);if((self->field58c&0x10)==0){if((s8)self->v474!=-1)fn_1_F7338((s8)self->v474,2,30);
   self->flags|=0x800;self->flags|=0x80;self->flags|=0x00800000;self->flags|=0x40000000;self->field58c|=0x10;
   *(f32 *)((u8 *)self+0x184)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0x224)=*(const f32 *)(const void *)&lbl_1_rodata_84C;
   *(f32 *)((u8 *)self+0x94)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0x98)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0x9c)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0xa0)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0xa4)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0xa8)=*(const f32 *)(const void *)&lbl_1_rodata_84C;*(f32 *)((u8 *)self+0x17c)=*(const f32 *)(const void *)&lbl_1_rodata_84C;
   self->field58c&=~0x80;*(u32 *)((u8 *)actor+0x390)&=~0x200000;*(u32 *)((u8 *)actor+0x390)|=0x01000000;}} if((result->flags160&0x100)!=0)self->flags|=0x800;}}
 if(status==0){f32 z=*(const f32 *)(const void *)&lbl_1_rodata_84C;out0->x=z;out0->y=z;out0->z=z;out1->x=z;out1->y=z;out1->z=z;} return status;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_2A694 */

/* fzgx:begin fn_1_2A8D0 */
typedef struct Sig_fn_1_2A694_N { u8 p[0x98]; u32 v98; u32 v9c; } Sig_fn_1_2A694_N;
typedef struct Sig_fn_1_2A694_O { u32 flags; s16 id; u8 p[0x46e]; s8 v474; u8 p2[0x23]; u32 field498; Sig_fn_1_2A694_N *field49c; u8 p3[0xec]; u32 field58c; } Sig_fn_1_2A694_O;
typedef struct Sig_fn_1_2A694_V { f32 x; f32 y; f32 z; } Sig_fn_1_2A694_V;

struct fn_1_2A8D0_Copy12 { u32 a[3]; };


int fn_1_2A8D0(Sig_fn_1_2A694_O * arg0, u8 * arg1, u32 * arg2, u32 arg3, Sig_fn_1_2A694_V * arg4, u32 * arg5, u32 * arg6, u32 arg7) {
    struct { u32 a[3]; } loc_20;
    struct fn_1_2A8D0_Copy12 loc_14;
    u32 loc_10;
    u32 v1;
    u32 v3;
    int v2;
    u8 * t4;
    u8 * t5;
    Sig_fn_1_2A694_N *v0;

    lbl_8006E1B0(arg1, arg1 + 24);
    lbl_8006DAEC();
    loc_14 = *(struct fn_1_2A8D0_Copy12 *)(arg1 + 24);
    v0 = arg0->field49c;
    v2 = fn_1_15578(&loc_14, arg1 + 12, &loc_10, &loc_20, arg3, &v0->v9c, (void *)(u32)(v0->v98), (void *)(u32 *)(arg2), arg0->field498, arg0);
    lbl_8006DB30();
    if (arg2 != 0) {
        v1 = arg2[0];
        arg2[0] = arg2[1];
        arg2[1] = v1;
    }
    arg4[0].x = 0.0f;
    arg4[0].y = 0.0f;
    arg4[0].z = 0.0f;
    arg4[1].x = 0.0f;
    arg4[1].y = 0.0f;
    arg4[1].z = 0.0f;
    arg4[2].x = 0.0f;
    arg4[2].y = 0.0f;
    arg4[2].z = 0.0f;
    arg4[3].x = 0.0f;
    arg4[3].y = 0.0f;
    arg4[3].z = 0.0f;
    arg5[3] = 0;
    arg5[2] = 0;
    arg5[1] = 0;
    arg5[0] = 0;
    if (v2 != 0) {
        t4 = fn_1_14F04();
        if (*(u32 *)(t4 + 208) != 0) {
            *(struct fn_1_2A8D0_Copy12 *)&arg4[0] = *(struct fn_1_2A8D0_Copy12 *)(t4 + 240);
            arg5[0] = *(u32 *)(t4 + 264);
            arg6[0] |= arg7;
        }
        if (*(u32 *)(t4 + 136) != 0) {
            *(struct fn_1_2A8D0_Copy12 *)&arg4[1] = *(struct fn_1_2A8D0_Copy12 *)(t4 + 168);
            arg5[1] = *(u32 *)(t4 + 192);
            arg6[1] |= arg7;
        }
        v3 = *(u32 *)(t4 + 352);
        if (v3 != 0) {
            if (v3 & 0x100) {
                arg0->flags |= 0x800;
                v2 = 0;
            } else if (v3 & 0x600) {
                *(struct fn_1_2A8D0_Copy12 *)&arg4[2] = *(struct fn_1_2A8D0_Copy12 *)(t4 + 384);
                t5 = fn_1_868C0((s8)arg0->id);
                if (!(arg0->field58c & 0x10)) {
                    if (arg0->v474 != -1) {
                        fn_1_F7338(arg0->v474, (void *)(int)(2), (void *)(int)(30));
                    }
                    arg0->flags |= 0x800;
                    arg0->flags |= 0x80;
                    arg0->flags |= 0x800000;
                    arg0->flags |= 0x40000000;
                    arg0->field58c |= 0x10;
                    *(f32 *)((u8 *)arg0 + 388) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 548) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 148) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 152) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 156) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 160) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 164) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 168) = 0.0f;
                    *(f32 *)((u8 *)arg0 + 380) = 0.0f;
                    arg0->field58c &= ~0x80;
                    *(u32 *)(t5 + 912) &= ~0x200000;
                    *(u32 *)(t5 + 912) |= 0x1000000;
                }
            } else {
                *(struct fn_1_2A8D0_Copy12 *)&arg4[2] = *(struct fn_1_2A8D0_Copy12 *)(t4 + 384);
            }
            arg6[2] |= arg7;
        }
        if (*(u32 *)(t4 + 64) != 0) {
            *(struct fn_1_2A8D0_Copy12 *)&arg4[3] = *(struct fn_1_2A8D0_Copy12 *)(t4 + 96);
            arg5[3] = *(u32 *)(t4 + 120);
            arg6[3] |= arg7;
        }
    }
    return v2;
}
/* fzgx:end fn_1_2A8D0 */

/* fzgx:begin fn_1_2B478 */
struct fn_1_2B478_Arg0 {
    u8 pad_0[0x1C8];
    f32 unk_1C8;
    u8 pad_1CC[0x2D0];
    u32 unk_49C;
};
struct fn_1_2B478_lbl_801A66CC {
    u32 unk_0;
};

f32 fn_1_2B478(void *arg0) {
    void *temp_r5;

    temp_r5 = (void *)(*(void **)((u8 *)(arg0) + 1180));
    if (!((*(s32 *)((u8 *)(temp_r5) + 124)) & 0x01800000) || ((*(f32 *)((u8 *)(arg0) + 456)) <= (*(f32 *)((u8 *)(&(*(f32 *)&lbl_1_rodata_84C)) + 0)))) {
        return *(f32 *)((u8 *)(&(*(f32 *)&lbl_1_rodata_854)) + 0);
    }
    (*(f32 *)((u8 *)((*(struct fn_1_2B478_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 212)) = (f32) -(*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 8));
    (*(f32 *)((u8 *)((*(struct fn_1_2B478_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 216)) = (f32) -(*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 24));
    (*(f32 *)((u8 *)((*(struct fn_1_2B478_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 220)) = (f32) -(*(f32 *)((u8 *)(lbl_801A6D00.unk_0) + 40));
    return lbl_8006D6FC((void *)((*(struct fn_1_2B478_lbl_801A66CC *)&lbl_801A66CC).unk_0 + 0xD4), (void *)((u8 *)(temp_r5) + 0x50));
}
/* fzgx:end fn_1_2B478 */

/* fzgx:begin fn_1_2BA48 */
typedef struct {
	u32 a;
	u32 b;
	u32 c;
} U24;

typedef struct {
	u32 unk_0;
	s16 unk_4;
	u8 pad_6[0x76];
	U24 unk_7c;
	U24 unk_88;
	f32 unk_94;
	f32 unk_98;
	f32 unk_9c;
	u8 pad_a0[0x3d4];
	u8 unk_474;
	u8 unk_475;
	u8 pad_476[0x6a];
	u16 unk_4e0;
	Vec3 unk_4e4;
	Vec3 unk_4f0;
	u8 pad_4fc[0x11];
	u8 unk_50d;
	u8 pad_50e[0x7e];
	u32 unk_58c;
} St;

typedef struct {
	u8 pad_0[0x390];
	u32 unk_390;
} Obj;

void fn_1_2BA48(St *p) {
	s32 v = 0x3c;
	Obj *g;
	f32 z;
	u32 n;
	U24 c;

	if (*(s16 *)&lbl_1_bss_960 != 9) {
		v = 0xf0;
	}
	if (!(p->unk_0 & 0x2)) {
		fn_1_2B684((u32)p);
	}
	if (p->unk_4e0 < 0x3c) {
		psvec_add(&p->unk_4f0, &p->unk_4e4, &p->unk_4e4);
	}
	n = p->unk_50d + 1;
	p->unk_50d = n;
	if ((u8)n >= (u16)v) {
		if (!(p->unk_0 & 0x2)) {
			z = (((f32 *)&lbl_1_rodata_84C))[0];
			p->unk_94 = z;
			p->unk_98 = z;
			p->unk_9c = z;
			c = p->unk_88;
			p->unk_7c = c;
			g = (Obj *)fn_1_868C0((s8)p->unk_4);
			if (!(p->unk_58c & 0x90)) {
				p->unk_58c = p->unk_58c | 0x80;
				p->unk_58c = p->unk_58c | 0x100;
				g->unk_390 = g->unk_390 | 0x200000;
				if ((s8)p->unk_474 != -1) {
					fn_1_F7338((s32)(s8)p->unk_474, (void *)(s32)(2), (void *)(s32)(0x1e));
				}
			}
			if (*lbl_801A66C8 + p->unk_4 == 0) {
				fn_1_A2D84(0xa9092e00);
				if ((s8)p->unk_475 != -1 && !(p->unk_0 & 0x4000200)) {
					fn_1_A2D84(0xa9091200);
				}
			}
		}
		p->unk_50d = v;
	}
}
/* fzgx:end fn_1_2BA48 */

/* fzgx:begin fn_1_2BBD0 */
typedef struct Fn_1_2BBD0Vec {
    f32 x;
    f32 y;
    f32 z;
} Fn_1_2BBD0Vec;

typedef struct Fn_1_2BBD0 {
    unsigned char pad00[0x7c];
    f32 field7c;
    f32 field80;
    f32 field84;
    unsigned char pad88[0x42c];
    Fn_1_2BBD0Vec position;
    u8 active;
    u8 value4c1;
} Fn_1_2BBD0;

typedef struct Fn_1_2BBD0Arg {
    unsigned char pad00[0x04];
    s16 value04;
    unsigned char pad06[0x76];
    f32 field7c;
    f32 field80;
    f32 field84;
} Fn_1_2BBD0Arg;

#pragma opt_common_subs off
#pragma opt_lifetimes off
static inline f32 fn_1_2BBD0_read_pointer(Fn_1_2BBD0Vec * owner) { return owner->z; }
#pragma opt_propagation off
void fn_1_2BBD0(Fn_1_2BBD0 *self, Fn_1_2BBD0Arg *other, f32 threshold) {
    if (self->active == 0) {
        Fn_1_2BBD0Vec vec;
        f32 sum;
        f32 vc;
        f32 vb;
        f32 va;

        sum = self->position.x * self->position.x;
        sum += self->position.y * self->position.y;
        sum += self->position.z * self->position.z;
        if (threshold < lbl_8006D0B4(sum)) {
            lbl_8006DAEC();
            lbl_8006DBAC(((0xec) + ((char *)self)));
            va = self->field7c;
            vb = self->field80;
            vc = self->field84;
            *(volatile f32 *)(LC_BASE + 0xC) = va; /* hardware DI regs */
            *(volatile f32 *)(LC_BASE + 0x1C) = vb; /* Hardware access must remain ordered. */
            *(volatile f32 *)(LC_BASE + 0x2C) = vc; /* Hardware access must remain ordered. */
            fn_8006E250(&other->field7c, &vec);
            lbl_8006D668(&vec);
            if (fn_1_2BBD0_read_pointer(&vec) < (*((lbl_1_rodata_92C) + (0)))) {
                self->position = vec;
                self->value4c1 = other->value04;
                lbl_8006D668(&self->position);
            }
            lbl_8006DB30();
        }
    } else if (self->value4c1 == other->value04) {
        f32 wc;
        f32 wb;
        f32 wa;

        lbl_8006DAEC();
        lbl_8006DBAC((char *)self + 0xec);
        wa = self->field7c;
        wb = self->field80;
        wc = self->field84;
        *(volatile f32 *)(LC_BASE + 0xC) = wa; /* hardware DI regs */
        *(volatile f32 *)(LC_BASE + 0x1C) = wb; /* Hardware access must remain ordered. */
        *(volatile f32 *)(LC_BASE + 0x2C) = wc; /* Hardware access must remain ordered. */
        fn_8006E250(&other->field7c, &self->position);
        lbl_8006D668(&self->position);
        if (self->position.z > (*((lbl_1_rodata_92C) + (0)))) {
            self->position.z = (*((lbl_1_rodata_92C) + (0)));
        }
        lbl_8006DB30();
    }
}
#pragma opt_propagation reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_2BBD0 */

/* fzgx:begin fn_1_2C688 */
u32 fn_1_2C688(u32 arg0, u32 arg1, u32 arg2) {
    u32 v1;
    s32 v0;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 t0;
    u32 t1;
    u32 t2;
    v0 = 0;
    v1 = arg0;
    do {
    v2 = *(u32 *)((u8 *)v1 + 1160);
    v3 = arg0;
    v4 = arg1;
    v5 = arg2;
    if (v2 != 0) {
    v3 = v2;
    v4 = 0;
    v5 = 192;
    t0 = (u32)memset( (void *)(u32)(v3), v4, v5);
    v3 = t0;
    v3 = (v2 + 8);
    *(u32 *)((u8 *)v2 + 0) = v3;
    *(u32 *)((u8 *)v2 + 4) = (v2 + 100);
    }
    v0++;
    v1 += 4;
    } while ((s32)v0 < 4);
    v3 = *(u32 *)((u8 *)arg0 + 1176);
    if (v3 != 0) {
    v4 = 0;
    v5 = 404;
    t1 = (u32)memset( (void *)(u32)(v3), v4, v5);
    v3 = t1;
    }
    v6 = *(u32 *)((u8 *)arg0 + 1180);
    if (v6 != 0) {
    v3 = v6;
    v4 = 0;
    v5 = 279;
    t2 = (u32)memset( (void *)(u32)(v3), v4, v5);
    v3 = t2;
    v4 = (v6 + 184);
    *(u32 *)((u8 *)v6 + 128) = 0;
    v3 = (v6 + 200);
    *(u32 *)((u8 *)v6 + 144) = v4;
    *(u32 *)((u8 *)v6 + 148) = v3;
    *(u32 *)((u8 *)v6 + 156) = -1;
    *(u32 *)((u8 *)v6 + 184) = -1;
    *(u32 *)((u8 *)v6 + 216) = -1;
    }
    return v3;
}
/* fzgx:end fn_1_2C688 */

/* fzgx:begin fn_1_2C768 */
void fn_1_2C768(u32 *arg0) {
    if (lbl_1_bss_3C2A[0] != 0x29 || (lbl_1_bss_3C30.unk_0 & 0x800)) {
        return;
    }
    if (lbl_1_bss_3C30.unk_5 == 2 && *arg0 != lbl_1_bss_3C30.unk_1474) {
        lbl_1_bss_3C30.unk_5 = 6;
    }
    *arg0 += 1;
}
/* fzgx:end fn_1_2C768 */

/* fzgx:begin fn_1_2C7C4 */
void fn_1_2C7C4(u8 *value, const u8 *target, int step) {
    if (value[0] != target[0]) {
        if (value[0] > target[0]) {
            if (value[0] > target[0] + step) {
                value[0] -= step;
            } else {
                value[0] = target[0];
            }
        } else {
            if (value[0] < target[0] - step) {
                value[0] += step;
            } else {
                value[0] = target[0];
            }
        }
    }
    if (value[1] != target[1]) {
        if (value[1] > target[1]) {
            if (value[1] > target[1] + step) {
                value[1] -= step;
            } else {
                value[1] = target[1];
            }
        } else {
            if (value[1] < target[1] - step) {
                value[1] += step;
            } else {
                value[1] = target[1];
            }
        }
    }
    if (value[2] != target[2]) {
        if (value[2] > target[2]) {
            if (value[2] > target[2] + step) {
                value[2] -= step;
            } else {
                value[2] = target[2];
            }
        } else {
            if (value[2] < target[2] - step) {
                value[2] += step;
            } else {
                value[2] = target[2];
            }
        }
    }
    if (value[3] != target[3]) {
        if (value[3] > target[3]) {
            if (value[3] > target[3] + step) {
                value[3] -= step;
            } else {
                value[3] = target[3];
            }
        } else {
            if (value[3] < target[3] - step) {
                value[3] += step;
            } else {
                value[3] = target[3];
            }
        }
    }
}
/* fzgx:end fn_1_2C7C4 */

/* fzgx:begin fn_1_2C908 noprologue */
#include "types.h"

struct fn_1_2C908_lbl_1_bss_3C00 {
    u8 pad_0[0x30];
    u32 unk_30;
    u8 pad_34[0x14B4];
    u16 unk_14E8;
    u8 pad_14EA[0x2];
    u16 unk_14EC;
    u8 pad_14EE[0x6];
    u8 unk_14F4;
    u8 pad_14F5[0x3];
    u32 unk_14F8;
    u16 unk_14FC;
};

extern int fn_1_4C10(void);
extern struct fn_1_2C908_lbl_1_bss_3C00 lbl_1_bss_3C00;
extern u32 fn_1_4060(void);
extern void fn_1_EB080(int);

#pragma opt_lifetimes off
u32 fn_1_2C908(void) {
    struct fn_1_2C908_lbl_1_bss_3C00 *p_lbl_1_bss_3C00;
    u32 v0;
    u32 v1;
    p_lbl_1_bss_3C00 = (struct fn_1_2C908_lbl_1_bss_3C00 *)&lbl_1_bss_3C00;
    v0 = fn_1_4C10();
    if ((s32)v0 == 0) {
    v0 = p_lbl_1_bss_3C00->unk_30;
    v1 = (v0 | 4096);
    p_lbl_1_bss_3C00->unk_14E8 = 42;
    p_lbl_1_bss_3C00->unk_30 = v1;
    p_lbl_1_bss_3C00->unk_14EC = 0;
    p_lbl_1_bss_3C00->unk_14F4 = (p_lbl_1_bss_3C00->unk_14F4 | 1);
    p_lbl_1_bss_3C00->unk_14F8 = 0;
    p_lbl_1_bss_3C00->unk_14FC = 0;
    fn_1_EB080(4);
    v0 = fn_1_4060();
    }
    return v0;
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_2C908 */

/* fzgx:begin fn_1_2D038 noprologue */
#include "types.h"

struct fn_1_2D038_hdr { u32 unk_0; u8 pad_4[1]; u8 unk_5; u8 pad_6[2]; };
struct fn_1_2D038_lbl_1_bss_3C00 {
u8 pad_0[0x2A]; s16 unk_2A; u8 pad_2C[4]; struct fn_1_2D038_hdr unk_30; u8 pad_38[0x15EC];
u8 unk_1624; u8 pad_1625[3]; u32 unk_1628; u32 unk_162C; u32 unk_1630; u8 unk_1634; u8 pad_1635[3]; u32 unk_1638;
};
struct fn_1_2D038_lbl_1_rodata_BD8 { u8 pad_0[4]; f32 unk_4,unk_8,unk_C,unk_10,unk_14,unk_18,unk_1C,unk_20,unk_24,unk_28,unk_2C,unk_30,unk_34,unk_38,unk_3C,unk_40,unk_44,unk_48; u8 pad_4C[4]; f64 unk_50; };
struct fn_1_2D038_obj_3C30 { struct fn_1_2D038_hdr hdr; u8 pad_8[0x14BC - 8]; };
struct fn_1_2D038_obj_5138 { u8 pad_0[0xEC]; u8 unk_EC; u8 pad_ED[3]; u32 unk_F0; u32 unk_F4; u32 unk_F8; u8 unk_FC; u8 pad_FD[3]; u32 unk_100; };
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u8 lbl_1_bss_3C08[8];
u8 lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
s16 fzgx_obj_lbl_1_bss_3C12;
s16 lbl_1_bss_3C12__fzgx_offset_2;
s16 lbl_1_bss_3C12__fzgx_offset_4;
s16 lbl_1_bss_3C12__fzgx_offset_6;
s16 lbl_1_bss_3C12__fzgx_offset_8;
u8 fzgx_obj_lbl_1_bss_3C1C[0xE];
s16 fzgx_obj_lbl_1_bss_3C2A;
s16 lbl_1_bss_3C2A__fzgx_offset_2;
s16 lbl_1_bss_3C2A__fzgx_offset_4;
struct fn_1_2D038_obj_3C30 fzgx_obj_lbl_1_bss_3C30;
u8 fzgx_obj_lbl_1_bss_50EC[0x14];
u32 fzgx_obj_lbl_1_bss_5100;
u8 fzgx_obj_lbl_1_bss_5104[0x34];
u8 fzgx_obj_lbl_1_bss_5138[0xEC];
u8 lbl_1_bss_5138__fzgx_offset_EC;
u32 lbl_1_bss_5138__fzgx_offset_F0;
u32 lbl_1_bss_5138__fzgx_offset_F4;
u32 lbl_1_bss_5138__fzgx_offset_F8;
u8 lbl_1_bss_5138__fzgx_offset_FC;
u32 lbl_1_bss_5138__fzgx_offset_100;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; /* fzgx-allow: S2 BSS primer ordering */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C00;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C04;
    s = *(u8 *)&lbl_1_bss_3C08;
    s = *(u8 *)&lbl_1_bss_3C10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C12;
    s = *(u8 *)&lbl_1_bss_3C12__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_3C12__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_3C12__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_3C12__fzgx_offset_8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C1C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C2A;
    s = *(u8 *)&lbl_1_bss_3C2A__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_3C2A__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5104;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5138;
    s = *(u8 *)&lbl_1_bss_5138__fzgx_offset_EC;
    s = *(u8 *)&lbl_1_bss_5138__fzgx_offset_F0;
    s = *(u8 *)&lbl_1_bss_5138__fzgx_offset_F4;
    s = *(u8 *)&lbl_1_bss_5138__fzgx_offset_F8;
    s = *(u8 *)&lbl_1_bss_5138__fzgx_offset_FC;
    s = *(u8 *)&lbl_1_bss_5138__fzgx_offset_100;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFF00};
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; } /* fzgx-allow: S2 pool primer sink keeps the literal pool order */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) { volatile f32 s; s=0.0f; s=15.0f; s=1.0f; s=10.0f; s=1.25f; s=0.100000001f; s=0.899999976f; s=0.000600000028f; s=0.400000006f; s=0.75f; s=70.0f; s=0.5f; s=36.0f; s=16.0f; s=45.0f; s=0.00079999998f; s=18.0f; s=50.0f; } /* fzgx-allow: S2 pool primer sink keeps the literal pool order */
static const u32 fzgx_pool_table3[1]={0};
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp=fzgx_pool_table3; } /* fzgx-allow: S2 pool primer sink keeps the literal pool order */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) { volatile f64 d; d=4503599627370496.0; } /* fzgx-allow: S2 pool primer sink keeps the literal pool order */
#pragma section code_type ".text"
extern struct fn_1_2D038_lbl_1_rodata_BD8 lbl_1_rodata_BD8;
extern u32 lbl_1_data_5BF8;
extern u32 lbl_1_rodata_26F8;
extern u8 lbl_1_bss_8E51D;
extern u32 fn_1_F45B4(void);
extern s32 fn_1_F22D4(void *);
extern int fn_1_EB248(void);
extern s32 fn_1_154C84(void);
extern u32 fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_4954C(f32);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32,f32);
extern void fn_1_495C8(u8);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern const char *fn_1_15BA78(u32);
extern f32 fn_1_4B068(const char *);
extern f32 fn_1_4B090(const char *);
extern void fn_1_496FC(f32,f32);
extern void fn_1_4A0D8(const char *);
extern u32 fn_1_50A90(void *,u32,u32,u32,u32);
struct FzgxCopy_88 { u32 words[22]; };
static inline f32 fn_1_2D038_operand(f32 right,f32 left) { left+=right; return left; }
static inline u32 *fn_1_2D038_read_pointer(struct FzgxCopy_88 *owner) { return owner->words; }
#pragma opt_dead_assignments off
#pragma opt_propagation off
void fn_1_2D038(void) {
struct FzgxCopy_88 loc_8;
struct { struct fn_1_2D038_hdr *value; } hdr;
s32 var_r29;
f32 var_f31;
f32 var_f30;
f32 var_f29;
f32 temp_f28;
f32 temp_f27;
f32 var_f26;
f32 temp_f26;
f32 temp_f7;
s32 var_r28;
f32 lab_t1;
const char *lab_t0;
var_r29=0; var_r28=-1;
if (!(fzgx_obj_lbl_1_bss_3C30.hdr.unk_0 & 0x800000) || (((u8)fn_1_F45B4()!=0) && ((u8)lbl_1_bss_5138__fzgx_offset_EC==0))) {
lbl_1_bss_5138__fzgx_offset_F0=0;
} else {
if ((u32)lbl_1_bss_5138__fzgx_offset_F4==0) { var_r29=1; lbl_1_bss_5138__fzgx_offset_F0=1; }
else if (((s32)lbl_1_bss_5138__fzgx_offset_F0==0) && ((u32)lbl_1_bss_5138__fzgx_offset_F4>=0xB4U)) { lbl_1_bss_5138__fzgx_offset_F0=1; lbl_1_bss_5138__fzgx_offset_F4=0; lbl_1_bss_5138__fzgx_offset_F8=0; }
if (((u32)lbl_1_bss_5138__fzgx_offset_F4==0) && ((s32)lbl_1_bss_5138__fzgx_offset_F0!=0)) var_r28=1;
}
if (((u8)lbl_1_bss_5138__fzgx_offset_FC!=0) || ((hdr.value = &fzgx_obj_lbl_1_bss_3C30.hdr, hdr.value->unk_5 == 2) && fn_1_F22D4(hdr.value)!=0)) {
if ((u32)lbl_1_bss_5138__fzgx_offset_F4==0) { var_r29+=1; lbl_1_bss_5138__fzgx_offset_100=1; }
else if (((s32)lbl_1_bss_5138__fzgx_offset_100==0) && ((u32)lbl_1_bss_5138__fzgx_offset_F4>=0xB4U)) { lbl_1_bss_5138__fzgx_offset_100=1; lbl_1_bss_5138__fzgx_offset_F4=0; lbl_1_bss_5138__fzgx_offset_F8=0; }
if (var_r29==2) { var_r28=0; lbl_1_bss_5138__fzgx_offset_F8=0; }
else if (((u32)lbl_1_bss_5138__fzgx_offset_F4==0) && ((s32)lbl_1_bss_5138__fzgx_offset_100!=0) && var_r28==-1) var_r28=2;
} else lbl_1_bss_5138__fzgx_offset_100=0;
if (((s32)lbl_1_bss_5138__fzgx_offset_F0==0) && ((s32)lbl_1_bss_5138__fzgx_offset_100==0)) { lbl_1_bss_5138__fzgx_offset_F4=0; lbl_1_bss_5138__fzgx_offset_F8=0; return; }
if (fn_1_EB248()!=0 || fn_1_154C84()!=0) {
if ((u32)lbl_1_bss_5138__fzgx_offset_F4==0) return;
if ((u32)lbl_1_bss_5138__fzgx_offset_F4>0xFU) lbl_1_bss_5138__fzgx_offset_F4=0xF;
else lbl_1_bss_5138__fzgx_offset_F4=(u32)((s32)lbl_1_bss_5138__fzgx_offset_F4-1);
goto block_43; /* fzgx-allow: S1 retail shares this tail block between both branches */
} else {
if ((s16)fzgx_obj_lbl_1_bss_3C2A>=0x2A) {
if ((u8)lbl_1_bss_8E51D==0xA) {
if ((u32)lbl_1_bss_5138__fzgx_offset_F4==0) var_r28+=3;
lbl_1_bss_5138__fzgx_offset_F4+=(u32)lbl_1_bss_5138__fzgx_offset_F4<0x3CU;
goto block_43; /* fzgx-allow: S1 retail shares this tail block between both branches */
}
lbl_1_bss_5138__fzgx_offset_F4=0; return;
}
lbl_1_bss_5138__fzgx_offset_F4=0; lbl_1_bss_5138__fzgx_offset_F8=0; return;
}
block_43:;
if ((u32)lbl_1_bss_5138__fzgx_offset_F4<0xFU) var_f31=(f32)lbl_1_bss_5138__fzgx_offset_F4/15.0f;
else if ((u32)lbl_1_bss_5138__fzgx_offset_F4>0xA5U) var_f31=1.0f-((f32)(lbl_1_bss_5138__fzgx_offset_F4-0xA5)/15.0f);
else var_f31=1.0f;
var_f30=10.0f*var_f31; if (var_f30>1.0f) var_f30=1.0f;
var_f29=1.25f*(var_f31-0.100000001f); if (var_f29<0.0f) var_f29=0.0f;
var_f26=10.0f*(var_f31-0.899999976f); if (var_f26<0.0f) var_f26=0.0f;
fn_1_49410(); fn_1_495FC(); fn_1_4954C(0.000600000028f); fn_1_49590(0.400000006f); fn_1_4955C(0.75f,0.75f); fn_1_495C8(1); fn_1_495A0(var_f26); fn_1_495B0(0x80000000U);
if ((u32)lbl_1_bss_5138__fzgx_offset_F8==0) lbl_1_bss_5138__fzgx_offset_F8=(u32)fn_1_15BA78((&lbl_1_data_5BF8)[var_r28]);
lab_t0=(const char *)lbl_1_bss_5138__fzgx_offset_F8;
temp_f27=fn_1_4B068(lab_t0); temp_f28=fn_1_4B090((const char *)lbl_1_bss_5138__fzgx_offset_F8);
temp_f26=temp_f27; temp_f26*=0.5f; lab_t1=70.0f; temp_f26=fn_1_2D038_operand(temp_f26,lab_t1);
fn_1_496FC(temp_f26,36.0f); fn_1_4A0D8((const char *)lbl_1_bss_5138__fzgx_offset_F8);
loc_8=*(const struct FzgxCopy_88 *)((((s32)(((u8 *)(&lbl_1_rodata_26F8)+-4)))+4));
temp_f7=45.0f+temp_f28;
(*(f32 *)((u8 *)&loc_8+4))=temp_f26;
(*(f32 *)((u8 *)&loc_8+8))=16.0f+(f32)(0.5f*temp_f7);
(*(f32 *)((u8 *)&loc_8+12))=0.00079999998f;
fn_1_2D038_read_pointer(&loc_8)[0xC]=0xA;
(*(f32 *)((u8 *)&loc_8+44))=var_f31;
fn_1_2D038_read_pointer(&loc_8)[0]=2;
fn_1_50A90(&loc_8,(u32)(s32)(18.0f*var_f30),(u32)(s32)(45.0f*var_f30),(u32)(s32)((50.0f+temp_f27)*var_f29),(u32)(s32)(temp_f7*var_f29));
}
#pragma opt_propagation reset
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_2D038 */

/* fzgx:begin fn_1_2D524 */
struct fn_1_2D524_Arg0 {
    u16 unk_0;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4[4];
    u16 unk_8[6];
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[4];
    char unk_20[0xC1];
    u8 unk_E1;
    u8 unk_E2;
    u8 unk_E3;
    u8 unk_E4;
    u8 unk_E5;
    u8 unk_E6[5];
    u8 unk_EB;
};
struct fn_1_2D524_lbl_1_data_5730 {
    u8 pad_0[0x538];
    char *unk_538;
    u8 pad_53C[0x50];
    char *unk_58C;
    u8 pad_590[0x58];
    char *unk_5E8;
    u8 pad_5EC[0x58];
    char *unk_644;
    u8 pad_648[0x4C];
    char *unk_694;
    u8 pad_698[0x50];
    char *unk_6E8;
    u8 pad_6EC[0x1C];
    char *unk_708;
};
struct fn_1_2D524_lbl_1_bss_3C30 {
    u8 pad_0[0x6];
    u8 unk_6;
};


void fn_1_2D524(struct fn_1_2D524_Arg0 *arg0) {
    struct fn_1_2D524_lbl_1_rodata_BD8 *pool;
    struct fn_1_2D524_lbl_1_data_5730 *data;
    u8 v0;
    u16 v8;
    u32 t0;
    char *s;
    u32 t32;
    f32 v14;
    char buf30[0x40];
    char buf10[0x20];

    pool = (struct fn_1_2D524_lbl_1_rodata_BD8 *)&lbl_1_rodata_BD8;
    v0 = arg0->unk_E1;
    data = (struct fn_1_2D524_lbl_1_data_5730 *)&(*((struct fn_1_2D524_lbl_1_data_5730 *)&lbl_1_data_5730));
    if (v0 == 0) {
        t0 = fn_1_F8D10();
        sprintf(arg0->unk_20, fn_1_15BA78(data->unk_708), arg0->unk_0);
        fn_1_F8D38(t0 + arg0->unk_0);
        arg0->unk_0 = 0;
    } else if (v0 == 1) {
        s = lbl_1_data_2BD54[arg0->unk_E3][lbl_801A66B4];
        sprintf(arg0->unk_20, fn_1_15BA78(data->unk_5E8), s);
        fn_1_F2008((*((struct fn_1_2D524_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_6);
    } else if (v0 == 2) {
        struct fn_1_2D524_Copy200 tbl = pool->unk_58;
        sprintf(arg0->unk_20, fn_1_15BA78(data->unk_694), tbl.a[arg0->unk_E5 & 0xF][lbl_801A66B4]);
        fn_1_F9D68(arg0->unk_E5 & 0xF);
        fn_1_F9DE8(arg0->unk_E5 & 0xF);
    } else if (v0 == 3) {
        struct fn_1_2D524_Copy8 t2 = pool->unk_120;
        s = fn_1_15BA78(t2.a[arg0->unk_EB]);
        sprintf(arg0->unk_20, fn_1_15BA78(data->unk_6E8), s);
        fn_1_F8C00(arg0->unk_EB);
    } else {
        v8 = v0 - 4;
        if (v8 < arg0->unk_3) {
            fn_1_7F49C(arg0->unk_4[v8], lbl_801A66B4, buf10);
            sprintf(arg0->unk_20, fn_1_15BA78(data->unk_58C), buf10);
            fn_1_F7F48(arg0->unk_4[v8]);
        } else if (v8 < arg0->unk_3 + arg0->unk_2) {
            v8 -= arg0->unk_3;
            fn_1_14EA74(arg0->unk_8[v8], buf30, lbl_801A66B4);
            sprintf(arg0->unk_20, fn_1_15BA78(data->unk_538), buf30);
            fn_1_F83F0(arg0->unk_8[v8]);
        } else {
            v8 -= arg0->unk_3 + arg0->unk_2;
            s = lbl_1_data_2BD54[fn_1_12EF24(6, arg0->unk_E6[v8])][lbl_801A66B4];
            sprintf(arg0->unk_20, fn_1_15BA78(data->unk_644), s);
            fn_1_F8A58(arg0->unk_E6[v8]);
        }
    }
    fn_1_49410();
    v14 = pool->unk_128;
    fn_1_4955C(v14, v14);
    fn_1_49590(pool->unk_24);
    fn_1_495B0(0x80000000);
    fn_1_495C8(1);
    t32 = fn_1_4AEC0(1);
    arg0->unk_14 = pool->unk_12C + fn_1_4B068(arg0->unk_20);
    arg0->unk_18 = pool->unk_130 + fn_1_4B090( (s32)(char *)(arg0->unk_20));
    fn_1_4AEC0(t32);
    fn_1_A2DC4(0xA9011700);
}
/* fzgx:end fn_1_2D524 */

/* fzgx:begin fn_1_2DF98 pool */
typedef struct GameStateB {
    u32 f_00;
    u8 pad_04;
    u8 f_05;
    u8 pad_06[2];
    u8 f_08;
    u8 pad_09[0xC4 - 0x09];
    u32 f_C4;
    u8 pad_C8[0x14BC - 0xC8];
} GameStateB;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_obj_lbl_1_bss_3C12__b9;
u32 fzgx_obj_lbl_1_bss_3C1C;
u8 lbl_1_bss_3C1C__fzgx_offset_4[10];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_obj_lbl_1_bss_3C2A__b5;
GameStateB fzgx_obj_lbl_1_bss_3C30;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
s8 fzgx_obj_lbl_1_bss_5104;
u8 lbl_1_bss_5104__fzgx_offset_4[0x30];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
s32 fzgx_obj_lbl_1_bss_25B84;
void *fzgx_obj_lbl_1_bss_25B88;
u16 *lbl_1_bss_25B88__fzgx_offset_4;
s32 lbl_1_bss_25B88__fzgx_offset_8;
u32 lbl_1_bss_25B88__fzgx_offset_C;
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4[11];
u32 fzgx_obj_lbl_1_bss_25CD0[105];
u32 fzgx_obj_lbl_1_bss_25E74[7];
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98[1];
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pad_26B1B;
u8 fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
u32 fzgx_obj_lbl_1_bss_26C28;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C;
    s = lbl_1_bss_3C1C__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_obj_lbl_1_bss_3C2A__b5;
    s = *(u32 *)&fzgx_obj_lbl_1_bss_3C30;
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104;
    s = lbl_1_bss_5104__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = *(u32 *)&fzgx_obj_lbl_1_bss_25B88;
    s = *(u32 *)&lbl_1_bss_25B88__fzgx_offset_4;
    s = lbl_1_bss_25B88__fzgx_offset_8;
    s = lbl_1_bss_25B88__fzgx_offset_C;
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4[0];
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98[0];
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pad_26B1B;
    s = fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
}
#pragma section code_type ".text"

#pragma opt_common_subs on
#pragma opt_propagation off
s32 fn_1_2DF98(void)
{
    u32 ready;
    void *saved;
    s32 count;
    s32 ch;

    fzgx_obj_lbl_1_bss_5104 = -1;
    if ((fzgx_obj_lbl_1_bss_3C30.f_00 & 0x800800) == 0x800800) {
        fzgx_obj_lbl_1_bss_3C30.f_C4 = 0;
        lbl_1_bss_5104__fzgx_offset_4[3] &= 0xFE;
    }

    if (lbl_1_bss_6F316 != 0 && fzgx_obj_lbl_1_bss_25B84 != 0) {
        if (lbl_1_data_5B7C == 5) {
            fn_1_A1588((void *)lbl_1_bss_6EAD0.unk_0->unk_0, 0x18);
        } else {
            fn_1_A1588((void *)lbl_1_bss_6EAD0.unk_0->unk_0, 0x10);
        }
        ADXT_Stop((void *)lbl_1_bss_6EAD0.unk_0->unk_4);
        lbl_1_bss_6F316 = 0;
        if (lbl_1_data_5B7C == 1) {
            saved = (void *)fn_1_435C( (u32)(void *)(fzgx_obj_lbl_1_bss_25B88));
            fn_1_40E08(0x12C);
            fn_1_435C( (u32)(void *)(saved));
        }
    }

    ch = fzgx_obj_lbl_1_bss_3C30.f_08;
    if (ch < 1) ch = 1;
    if (lbl_1_bss_25B88__fzgx_offset_4 == 0) return 1;
    ready = fzgx_obj_lbl_1_bss_3C30.f_05;
    if (ready == 0) ch -= 1;
    count = lbl_1_bss_25B88__fzgx_offset_8;
    if (count >= ch) {
        if (*lbl_1_bss_25B88__fzgx_offset_4 == 0x10) {
            if (fzgx_obj_lbl_1_bss_25B84 != 0) {
                if (lbl_1_data_5B7C == 5) {
                    u32 msg = lbl_1_rodata_D18;
                    fn_1_49F0(&msg);
                } else {
                    u32 msg2 = lbl_1_rodata_D1C[0];
                    fn_1_49F0(&msg2);
                }
            }
            fn_1_4A00(0, 0xF, (void *)fzgx_obj_lbl_1_bss_5100);
        } else if (*lbl_1_bss_25B88__fzgx_offset_4 == 0) {
            if (ready == 0) return count > ch;
            return 1;
        }
        lbl_1_bss_25B88__fzgx_offset_C = *lbl_1_bss_25B88__fzgx_offset_4;
    }
    return 0;
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
/* fzgx:end fn_1_2DF98 */

/* fzgx:begin fn_1_2E1B8 pool */
struct CallbackObject {
    u8 pad_0[0xC0];
    u32 (*unk_C0)(void *);
};

struct CallbackState {
    u8 pad_0[0xC];
    s32 unk_C;
    u8 pad_10[0x20];
    struct CallbackObject unk_30;
    u8 pad_F4[0x13F4];
    u16 unk_14E8;
};


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 lbl_1_bss_3C08_fill_3C08;
s32 lbl_1_bss_3C08_4;
u8 lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u16 fzgx_obj_lbl_1_bss_3C12;
u32 lbl_1_bss_3C12_fill_3C14[2];
u32 fzgx_obj_lbl_1_bss_3C1C[3];
u16 lbl_1_bss_3C1C_fill_3C28;
u16 fzgx_obj_lbl_1_bss_3C2A;
u32 lbl_1_bss_3C2A_fill_3C2C;
struct CallbackObject fzgx_obj_lbl_1_bss_3C30;
u32 lbl_1_bss_3C30_fill_3CF4[1277];
u16 lbl_1_bss_3C30_14B8;
u16 lbl_1_bss_3C30_fill_50EA;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C00;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C04;
    s = *(u8 *)&lbl_1_bss_3C08_fill_3C08;
    s = *(u8 *)&lbl_1_bss_3C08_4;
    s = *(u8 *)&lbl_1_bss_3C10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C12;
    s = *(u8 *)&lbl_1_bss_3C12_fill_3C14;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C1C;
    s = *(u8 *)&lbl_1_bss_3C1C_fill_3C28;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C2A;
    s = *(u8 *)&lbl_1_bss_3C2A_fill_3C2C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&lbl_1_bss_3C30_fill_3CF4;
    s = *(u8 *)&lbl_1_bss_3C30_14B8;
    s = *(u8 *)&lbl_1_bss_3C30_fill_50EA;
}
#pragma section code_type ".text"

void fn_1_2E1B8(void) {
    
    if (fn_1_4C10() == 0) {
        s32 active = lbl_1_bss_3C08_4;
        lbl_1_bss_3C30_14B8 = 45;
        if (active) {
            struct CallbackObject *object = &fzgx_obj_lbl_1_bss_3C30;
            u32 result;
            lbl_1_bss_25B9C = 0;
            if (object->unk_C0 != 0) {
                result = object->unk_C0(object);
                if (result & 4) lbl_1_bss_25B9C = 1;
                if (result & 2) fn_1_304A8();
                if (result & 1) return;
            }
            lbl_1_bss_3C08_4 = 0;
        }
        fn_1_4060();
    }
}
/* fzgx:end fn_1_2E1B8 */

/* fzgx:begin fn_1_2E268 */
#pragma opt_lifetimes off
static inline u8 fn_1_2E268_array_read(u8 *array, s32 index) { u8 *p = array + index; return *p; }
#pragma opt_lifetimes reset

#pragma opt_common_subs off
void fn_1_2E268(void) {
    Obj_1_bss_3C30 *state = &lbl_1_bss_3C30;
    u8 *values;
    int i;
    int j;
    for (i = 0; lbl_1_bss_3C30.unk_9 > i; i++) {
        Obj_1_bss_3C30 *row = (Obj_1_bss_3C30 *)((u8 *)&lbl_1_bss_3C30 + i * 0xA0);
        u8 *record = (u8 *)&row->unk_D4;
        *(u16 *)(4 + record) = 0;
        *(u32 *)(0x78 + record) = 0;
        *(u16 *)(6 + record) = 0;
        if (0 == lbl_1_bss_3C30.unk_5) {
            *(u16 *)(4 + record) = (&lbl_1_bss_3C30.unk_1480)[i];
            *(u16 *)(0x9E + record) = (&lbl_1_bss_3C30.unk_1478)[i];
            record[0x83] = fn_1_2E268_array_read(record, 8);
        } else {
            for (j = 0; j < lbl_1_bss_3C30.unk_A7; j++) {
                values = record + j;
                *(u16 *)(4 + record) += values[9];
                *(u16 *)(6 + record) += values[0x13];
                *(u32 *)(0x78 + record) += ((u16 *)record)[j + 0x26];
            }
        }
        record[lbl_1_bss_3C30.unk_A7 + 0xE] = 0xFF;
    }
    if (0 != state->unk_A7) {
        fn_1_3F2A0();
    } else {
        for (i = 0; i < state->unk_9; i++) {
            u8 id = ((u8 *)(&state->unk_2C)[i])[0x115];
            (&lbl_1_bss_3C30.unk_1394)[id] = i;
            ((Obj_1_bss_3C30 *)((u8 *)state + i * 0xA0))->unk_DC = id;
        }
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_2E268 */

/* fzgx:begin fn_1_2E3B4 noprologue */
#include "types.h"
#include "rel/main_rel/stcoli.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table5[52] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 80.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table9[2] = {0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 470.0f;
    s = 0.0625f;
    s = 14.0f;
    s = 127.0f;
    s = 0.25f;
}

#pragma section code_type ".text"

typedef struct {
    u8 pad_0[0xE];
    u8 unk_E[1];
    u8 pad_F[4];
    u8 unk_13[1];
    u8 pad_14[0x10];
    u32 unk_24[1];
    u8 pad_28[0x5C];
    u16 unk_84;
    s16 unk_86;
    u16 unk_88;
    u16 unk_8A;
    s16 unk_8C;
    s16 unk_8E;
    u32 unk_90;
    u32 unk_94;
    s16 unk_98;
    u16 unk_9A;
    s16 unk_9C;
} Arg0;

typedef struct {
    u32 unk_0;
    u8 pad_4[2];
    s16 unk_6;
    u8 pad_8[0xD0];
    f32 unk_D8;
    u8 pad_DC[0x137];
    u8 unk_213;
    u8 pad_214[3];
    u8 unk_217;
    u8 pad_218[0x2AA];
    u8 unk_4C2;
    u8 pad_4C3[0xC9];
    u32 unk_58C;
} Arg1;

extern const u16 lbl_1_rodata_DB94[];
extern const u16 lbl_1_rodata_DB58[];
extern const u16 lbl_1_rodata_DB9C[];

static inline s32 packed_time_difference(u32 t1, u32 t2) {
    u32 max;
    s32 ms;
    s32 min_part;
    s32 sec;

    if (t1 > t2) {
        max = t1;
        t1 = t2;
    } else {
        max = t2;
    }

    ms = (max & 0xFFF) - (t1 & 0xFFF);
    min_part = ((max >> 20) & 0xFF) - ((t1 >> 20) & 0xFF);
    sec = ((max >> 12) & 0xFF) - ((t1 >> 12) & 0xFF);

    if (ms < 0) {
        sec--;
        ms += 1000;
    }
    if (sec < 0) {
        min_part--;
        sec += 60;
    }

    return (min_part * 60 + sec) * 1000 + ms;
}

#pragma opt_dead_assignments off
#pragma opt_loop_invariants off
void fn_1_2E3B4(Arg0 *arg0, Arg1 *arg1) {
    f32 distance;
    s32 val_e;
    f32 rate;
    s32 flag;

    val_e = arg0->unk_E[lbl_1_bss_3C30.unk_A7];
    flag = arg1->unk_0 & 0x10000;
    rate = 1.0f + (f32)(0.25f * (f32)lbl_1_bss_3C30.unk_1470);
    arg0->unk_88 = 0;

    if (val_e == 0xFE || val_e == 0xFF) {
        if (lbl_1_bss_3C30.unk_5 == 2) {
            arg0->unk_88 = 100;
            arg0->unk_84 = 0;
        } else {
            arg0->unk_84 = 100;
        }
    } else {
        switch (lbl_1_bss_3C30.unk_5) {
        case 0:
            if (lbl_1_bss_3C30.unk_9 <= 4) {
                s32 unk_8 = lbl_1_bss_3C30.unk_8;
                s32 offset = 4 - unk_8;

                if (val_e == 0 && unk_8 == 2) {
                    arg0->unk_84 = 500;
                } else {
                    arg0->unk_84 = lbl_1_rodata_DB94[offset + val_e];
                }
                break;
            }
            /* fallthrough */
        case 1:
        case 6:
            arg0->unk_84 = lbl_1_rodata_DB58[val_e] * rate;
            break;
        case 2:
            if (lbl_1_bss_3C30.unk_1464 >= arg0->unk_24[lbl_1_bss_3C30.unk_A7]) {
                u32 diff = (u32)packed_time_difference(lbl_1_bss_3C30.unk_1464, arg0->unk_24[lbl_1_bss_3C30.unk_A7]) >> 1;
                diff += 1000;
                if (diff > 30000) {
                    diff = 30000;
                }
                arg0->unk_88 = diff;
            } else {
                s32 val = 850 - packed_time_difference(lbl_1_bss_3C30.unk_1464, arg0->unk_24[lbl_1_bss_3C30.unk_A7]) / 50;
                if (val < 100) {
                    val = 100;
                }
                arg0->unk_88 = val;
            }
            arg0->unk_84 = 0;
            break;
        default:
            arg0->unk_84 = 100;
            break;
        }
    }

    arg0->unk_86 = lbl_1_rodata_DB9C[arg0->unk_13[lbl_1_bss_3C30.unk_A7]];

    if (flag != 0) {
        if (arg1->unk_217 >= lbl_1_bss_3C30.unk_146C) {
            arg0->unk_8E = arg1->unk_217 - lbl_1_bss_3C30.unk_146C;
            arg0->unk_8E *= lbl_1_bss_3C30.unk_146D * 10;
            arg0->unk_8E += 500;
        } else {
            arg0->unk_8E = 0;
        }

        if (arg1->unk_D8 >= (f32)lbl_1_bss_3C30.unk_146E) {
            distance = arg1->unk_D8;
            arg0->unk_98 = (s32)(distance - (f32)lbl_1_bss_3C30.unk_146E);
            if (arg0->unk_98 > 1000) {
                arg0->unk_98 = 1000;
            }
            arg0->unk_98 *= 2;
            arg0->unk_98 += 200;
        } else {
            arg0->unk_98 = 0;
        }
        if (lbl_1_bss_3C30.unk_5 != 2) {
            arg0->unk_98 = 0;
        }

        arg0->unk_90 = 0;
        if (arg0->unk_E[lbl_1_bss_3C30.unk_A7] == 0) {
            arg0->unk_90 = (s32)(10000.0f * rate);
        }

        arg0->unk_9C = 0;
        if ((arg1->unk_58C & 1) == 0) {
            arg0->unk_9C += 1000;
        }
        if ((arg1->unk_0 & 0x80) != 0) {
            arg0->unk_9C += 500;
        }
        if (arg1->unk_6 >= 41) {
            arg0->unk_9C += 1000;
        }
        if ((arg0->unk_24[lbl_1_bss_3C30.unk_A7] & 0xFFF) == 0) {
            arg0->unk_9C += 5000;
        }
        if ((arg0->unk_24[lbl_1_bss_3C30.unk_A7] & 0xFFF) == 777) {
            arg0->unk_9C += 7777;
        }

        if (lbl_1_bss_3C30.unk_5 == 2 && arg0->unk_24[lbl_1_bss_3C30.unk_A7] <= lbl_1_bss_3C30.unk_1464) {
            arg0->unk_94 = (s32)(15000.0f * rate);
        }

        if (arg1->unk_4C2 >= 6) {
            arg0->unk_8C = -1000;
        } else {
            const s16 table[6] = { 1000, -300, -400, -500, -500, -500 };
            arg0->unk_8C = table[arg1->unk_4C2];
        }
        if (arg0->unk_8C > arg1->unk_213 * 5) {
            arg0->unk_8C -= arg1->unk_213 * 5;
        } else {
            arg0->unk_8C = 0;
        }
    } else {
        arg0->unk_8E = 0;
        arg0->unk_98 = 0;
        arg0->unk_90 = 0;
        arg0->unk_9C = 0;
        arg0->unk_8C = 0;
        arg0->unk_94 = 0;
    }
    arg0->unk_9A = 0;
    arg0->unk_8A = 0;
}
#pragma opt_loop_invariants reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_2E3B4 */

/* fzgx:begin fn_1_3FCD4 */
void fn_1_3FCD4(u32 mask) {
    if (mask == 0) {
        lbl_1_data_5B80 = 0xffffffff;
    } else {
        lbl_1_data_5B80 &= ~mask;
    }
}
/* fzgx:end fn_1_3FCD4 */
