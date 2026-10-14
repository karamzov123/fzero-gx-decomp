/* Non-matching: best partial attempt (96.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad_0[0x4C];
    u32 unk_4C;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    u32 unk_5C;
    union {
        u8 b[0x14];
        u16 w[10];
    } pad_60;
    s32 unk_74;
    s32 unk_78;
    u8 unk_7C;
} Obj_1_bss_8E518;

typedef struct {
    u8 pad_0[0x1AC];
    u16 unk_1AC;
} Obj_1_rodata_9828;

typedef struct {
    u8 _pad_pre[0x1C];
    u8 pad_0[1856];
    u32 tab5[4][1];
    u32 unk_76C;
    u32 tab[5][2];
    u8 pad_798[8];
} Obj_1_data_42878;

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} Obj_1_bss_9F8;

extern Obj_1_bss_8E518 lbl_1_bss_8E518;
extern Obj_1_rodata_9828 lbl_1_rodata_9828;
extern Obj_1_data_42878 lbl_1_data_42878;
extern Obj_1_bss_9F8 lbl_1_bss_9F8;
extern u32 lbl_1_bss_25CD0[105];
extern s32 lbl_801A66B4;
extern void fn_1_A2DC4(u32);
extern u32 fn_1_14CEB8(void *);
extern u32 fn_1_155FB4(const char *);
extern char *strncpy(char *, const char *, size_t);
extern s32 strncmp(const char *, const char *, size_t);
extern int sprintf(char *, const char *, ...);
extern void OSReport(const char *, ...);

static inline u8 *fn_1_14CAC8_array_read(u8 *array) { return array; }
static inline u8 *fn_1_14CAC8_array_read_(u8 *array) { return array; }
#pragma opt_propagation off
void fn_1_14CAC8(void) {
    Obj_1_rodata_9828 *ro = (Obj_1_rodata_9828 *)&lbl_1_rodata_9828;
    Obj_1_bss_8E518 *st = (Obj_1_bss_8E518 *)&lbl_1_bss_8E518;
    Obj_1_data_42878 *dat = (Obj_1_data_42878 *)&lbl_1_data_42878;
    char *b1;
    char *b2;
    u32 lab_t0;
    u32 (*row)[2];
    u16 sel;
    s32 off;
    s32 i;
    s32 v;
    s32 n;

    sel = ro->unk_1AC;
    if (((lbl_1_bss_9F8.unk_8 >> 12) & 1) != 0) {
        st->unk_5C = st->unk_54 - 1;
    }
    if (((lbl_1_bss_9F8.unk_8 >> 8) & 1) != 0) {
        lab_t0 = 0xA9011100u;
        fn_1_A2DC4(lab_t0);
        if ((s32)st->unk_5C == (s32)st->unk_54 - 1) {
            st->unk_74 = 0;
            b1 = (char *)st;
            b1 = b1 + 0x60;
            strncpy(b1 + st->unk_4C * 2, (const char *)&sel, 2);
            b2 = (char *)st + 0x60;
            b2[st->unk_4C * 2] = 0;
            if (fn_1_14CAC8_array_read_(st->pad_60.b)[0] == 0) {
                if (lbl_801A66B4 == 5) {
                    sprintf((char *)st->pad_60.b, (const char *)((u8 *)dat + 0x798),
                        (const char *)((u8 *)ro + 0x160));
                } else {
                    sprintf((char *)st->pad_60.b, (const char *)((u8 *)dat + 0x798),
                        (const char *)((u8 *)ro + 0x16C));
                }
            }
            fn_1_14CEB8(st->pad_60.b);
            OSReport((const char *)((u8 *)dat + 0x79C), (const char *)st->pad_60.b);
            strncpy((char *)(lbl_1_bss_25CD0[0] + (st->unk_78 << 5) + 8),
                (const char *)st->pad_60.b, 16);
            fn_1_155FB4((const char *)st->pad_60.b);
            return;
        }
        st->unk_4C = st->unk_4C + 1;
        if ((s32)st->unk_4C > 8) {
            st->unk_4C = 8;
        }
        b1 = (char *)st + 0x60;
        strncpy(b1 + st->unk_4C * 2, (const char *)st->unk_50, 2);
    } else if (((lbl_1_bss_9F8.unk_8 >> 9) & 1) != 0) {
        fn_1_A2DC4(0xA9011000u);
        if ((s32)st->unk_4C > 0) {
            b1 = (char *)st;
            (void) b1;  /* fzgx: keeps the web at its definition */
            b1 += 0x60;
            strncpy(b1 + st->unk_4C * 2, (const char *)&sel, 2);
            st->unk_5C = 0;
            st->unk_4C = st->unk_4C - 1;
            for (off = 0, i = 0; i < (s32)st->unk_54; i++, off += 2) {
                if (strncmp((((((0x60)) + ((st->unk_4C * 2))) + (((char *)st)))),
                        (const char *)st->unk_50 + off, 2) == 0) {
                    st->unk_5C = i;
                }
            }
        }
    } else if ((lbl_1_bss_9F8.unk_10 & 1) != 0 || (lbl_1_bss_9F8.unk_12 & 1) != 0 ||
               ((lbl_1_bss_9F8.unk_10 >> 1) & 1) != 0 || ((lbl_1_bss_9F8.unk_12 >> 1) & 1) != 0) {
        fn_1_A2DC4(0xA9011300u);
        if ((lbl_1_bss_9F8.unk_10 & 1) != 0 || (lbl_1_bss_9F8.unk_12 & 1) != 0) {
            st->unk_5C = st->unk_5C - 1;
        } else if (((lbl_1_bss_9F8.unk_10 >> 1) & 1) != 0 ||
                   ((lbl_1_bss_9F8.unk_12 >> 1) & 1) != 0) {
            st->unk_5C = st->unk_5C + 1;
        }
        n = st->unk_54;
        v = st->unk_5C + n;
        st->unk_5C = v % n;
    } else if (((lbl_1_bss_9F8.unk_8 >> 10) & 1) != 0) {
        fn_1_A2DC4(0xA9011300u);
        lab_t0 = st->unk_58 + 1;
        v = lab_t0;
        st->unk_58 = v;
        n = dat->unk_76C;
        st->unk_5C = 0;
        st->unk_58 = (((n) + (v))) % n;
        if (lbl_801A66B4 == 5) {
            row = (u32 (*)[2])((u8 *)dat + 0x74C);
            st->unk_50 = row[st->unk_58][0];
            st->unk_54 = row[st->unk_58][1];
        } else {
            row = (u32 (*)[2])((u8 *)dat + 0x770);
            st->unk_50 = row[st->unk_58][0];
            st->unk_54 = ((st->unk_58)[row])[1];
        }
    }
    if ((s32)st->unk_4C == 8) {
        st->unk_7C = 1;
        st->unk_5C = st->unk_54 - 1;
    } else {
        st->unk_7C = 0;
    }
    b1 = (char *)st + 0x60;
    strncpy(b1 + st->unk_4C * 2, (const char *)st->unk_50 + (st->unk_5C << 1), 2);
    strncpy((char *)(lbl_1_bss_25CD0[0] + (st->unk_78 << 5) + 8),
        (const char *)st->pad_60.b, 16);
    fn_1_155FB4((const char *)st->pad_60.b);
}
#pragma opt_propagation reset

