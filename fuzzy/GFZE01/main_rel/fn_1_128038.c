/* Non-matching: best partial attempt (97.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

struct Sig80077B14Arg {
    u8 pad_00[0x4];
    u32 unk_04;
    u8 pad_08[0x18];
    u32 unk_20;
};

typedef struct AccSig {
    u16 id;
    u8 pad_02[6];
    void *unk_08;
} AccSig;

typedef struct AccItem {
    u8 pad_00[0x88];
    s32 kind;
    u8 pad_8C[0xBC];
    AccSig sig_148;
} AccItem;

typedef struct BoneSet {
    u8 pad_00[2];
    u8 count;
    u8 pad_03[1];
    u16 index[6];
    u8 pad_10[0x18];
    u8 unk_28[0x1C];
} BoneSet;

typedef struct Accessory {
    u8 flag_00;
    u8 pad_01[3];
    u32 pad_04;
    u32 index_08;
    AccItem *item_0C;
    struct Sig80077B14Arg *sig_10;
    u32 pad_14;
    u32 count_18;
    u32 pad_1C[2];
    BoneSet *bones_24;
} Accessory;

typedef struct Mat44 {
    f32 v[12];
} Mat44;

extern f32 lbl_1_rodata_7AB8[9];
extern const char *fn_1_950E8(AccSig *);
extern int fn_80083BCC(const char *, const char *);
extern s32 fn_80077B14(struct Sig80077B14Arg *);
extern u32 fn_1_108EEC(void *, u32, u32, f32, f32, f32, f32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_8006E250(void *, void *);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1B0(void *, void *);

#define SLOT(a) ((s32)tbl.value[(a)->index_08])
#define SLOTPTR(a) ((u8 *)*(u32 *)((u8 *)*(u32 *)((u8 *)(a)->item_0C + 0x150) + 8) + SLOT(a) * 0x18c)

void fn_1_128038(Accessory *a) {
    u32 tmp_call38;
    s32 i;
    u8 * base_2;
    const f32 *ro = lbl_1_rodata_7AB8;
    const u8 *d = lbl_1_data_3F510;
    Mat44 mat;
    u8 *base;
    u8 *entry;
    u32 p30;
    u32 f;
    struct { const u32 *value; } tbl;
    s32 j;

    tbl.value = (const u32 *)(d + 0xaac);
    if (a != 0 && a->sig_10 != 0) {
        fn_80077B14(a->sig_10);
        if (a->flag_00 & 2) {
            f = a->flag_00;
            f &= ~2;
            a->flag_00 = f;
            lbl_8006DBAC(SLOTPTR(a) + 0x88);
            lbl_8006DAEC();
            base = (u8 *)a->bones_24;
            for (i = 0; i < a->count_18; i++) {
                lbl_8006DBE4();
                lbl_8006E1B0(base + 0x28, base + 0x10);
                base += 0x44;
            }
            lbl_8006DC20();
        }
        entry = SLOTPTR(a);
        if (a->item_0C->kind == 0x18) {
            if (fn_80083BCC(fn_1_950E8(&a->item_0C->sig_148), (const char *)(d + 0x10a0)) == 0) {
                lbl_8006D758();
                mathutil_mtxA_rotate_z(0x4000);
                lbl_8006DB74(&mat);
            } else {
                lbl_8006D758();
                lbl_8006DB74(&mat);
            }
        } else if (a->item_0C->kind == 6) {
            if (fn_80083BCC(fn_1_950E8(&a->item_0C->sig_148), (const char *)(d + 0x1048)) == 0 &&
                *(s16 *)&lbl_1_bss_960 != 14) {
                lbl_8006D758();
                mathutil_mtxA_rotate_z(0x4000);
                lbl_8006DB74(&mat);
            } else if (fn_80083BCC(fn_1_950E8(&a->item_0C->sig_148), (const char *)(d + 0x10a8)) == 0) {
                lbl_8006D758();
                mathutil_mtxA_rotate_z(0x2000);
                lbl_8006DB74(&mat);
            } else {
                lbl_8006D758();
                lbl_8006DB74(&mat);
            }
        } else if (a->item_0C->kind == 1) {
            lbl_8006D758();
            lbl_8006DB74(&mat);
        }
        base_2 = (u8 *)a->bones_24;
        for (i = 0; i < a->count_18; i++) {
            lbl_8006DBAC(entry + 0x88);
            lbl_8006DFC4(&mat);
            lbl_8006E1B0(base_2 + 0x28, base_2 + 0x10);
            base_2 += 0x44;
        }
        if (a->item_0C->kind == 0x18) {
            fn_1_108EEC(a, 1, 12, ro[308], ro[193], ro[344], ro[345]);
            if (fn_80083BCC(fn_1_950E8(&a->item_0C->sig_148), (const char *)(d + 0x10a0)) != 0) {
                if (fn_80083BCC(fn_1_950E8(&a->item_0C->sig_148), (const char *)(d + 0x1040)) != 0) {
                    fn_1_108EEC(a, 12, 12, ro[170], ro[42], ro[137], ro[290]);
                    fn_1_108EEC(a, 12, 12, ro[175], ro[346], ro[105], ro[347]);
                    fn_1_108EEC(a, 12, 12, ro[87], ro[348], ro[349], ro[165]);
                    fn_1_108EEC(a, 13, 12, ro[350], ro[26], ro[105], ro[261]);
                    fn_1_108EEC(a, 13, 12, ro[350], ro[179], ro[214], ro[351]);
                    fn_1_108EEC(a, 13, 12, ro[345], ro[352], ro[214], ro[351]);
                }
            }
        } else if (a->item_0C->kind == 6) {
            fn_1_108EEC(a, 1, 12, ro[308], ro[193], ro[344], ro[345]);
            if (fn_80083BCC(fn_1_950E8(&a->item_0C->sig_148), (const char *)(d + 0x1048)) != 0) {
                fn_1_108EEC(a, 12, 12, ro[170], ro[42], ro[137], ro[290]);
                fn_1_108EEC(a, 12, 12, ro[175], ro[346], ro[105], ro[347]);
                fn_1_108EEC(a, 12, 12, ro[87], ro[348], ro[349], ro[165]);
                fn_1_108EEC(a, 13, 12, ro[350], ro[26], ro[105], ro[261]);
                fn_1_108EEC(a, 13, 12, ro[350], ro[179], ro[214], ro[351]);
                tmp_call38 = fn_1_108EEC(a, 13, 12, ro[345], ro[352], ro[214], ro[351]);
            }
        } else if (a->item_0C->kind == 1) {
            if (SLOT(a) == 11u) {
                fn_1_108EEC(a, 1, 12, ro[263], ro[193], ro[344], ro[345]);
                fn_1_108EEC(a, 12, 12, ro[353], ro[42], ro[137], ro[290]);
                fn_1_108EEC(a, 12, 12, ro[354], ro[346], ro[105], ro[347]);
                fn_1_108EEC(a, 12, 12, ro[104], ro[348], ro[349], ro[165]);
                fn_1_108EEC(a, 13, 12, ro[168], ro[26], ro[105], ro[261]);
                fn_1_108EEC(a, 13, 12, ro[168], ro[179], ro[214], ro[351]);
                fn_1_108EEC(a, 13, 12, ro[355], ro[352], ro[214], ro[351]);
            } else {
                fn_1_108EEC(a, 1, 7, ro[263], ro[193], ro[344], ro[345]);
                fn_1_108EEC(a, 7, 7, ro[353], ro[42], ro[137], ro[290]);
                fn_1_108EEC(a, 7, 7, ro[354], ro[346], ro[105], ro[347]);
                fn_1_108EEC(a, 7, 7, ro[104], ro[348], ro[349], ro[165]);
                fn_1_108EEC(a, 13, 7, ro[168], ro[26], ro[105], ro[261]);
                fn_1_108EEC(a, 13, 7, ro[168], ro[179], ro[214], ro[351]);
                fn_1_108EEC(a, 13, 7, ro[355], ro[352], ro[214], ro[351]);
            }
        }
        p30 = fn_80077B14(a->sig_10);
        lbl_8006DBAC(SLOTPTR(a) + 0x88);
        base_2 = (u8 *)a->bones_24;
        for (j = 0; j < a->count_18; j++) {
            for (i = 0; i < ((BoneSet *)base_2)->count; i++) {
                fn_8006E250(base_2 + 0x10, (u8 *)p30 + ((BoneSet *)base_2)->index[i] * 0x40);
            }
            base_2 += 0x44;
        }
    }
}
