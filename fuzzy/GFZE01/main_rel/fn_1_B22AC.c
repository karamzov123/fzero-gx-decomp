/* Non-matching: best partial attempt (69.68% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/memcard.h"

extern const char *fn_80019C48(void);
extern size_t strlen(const char *);
extern u8 *fn_80083970(u8 *, const u8 *);
extern s32 strncmp(const char *, const char *, size_t);
extern char *strncpy(char *, const char *, size_t);
extern int sprintf(char *, const char *, ...);
extern f32 lbl_1_rodata_4AE0[114];
extern u32 lbl_1_data_35AC8;
extern void *lbl_801A6410;
extern void fn_1_46B4(u32, u32, const char *, int);
extern u32 fn_1_4630(u32, u32, const char *, int);

typedef struct FnB22AC_Work {
    u8 pad_00[0x08];
    u32 unk_08;
    u32 unk_0C;
    u8 pad_10[0x14];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u8 pad_30[0x10];
    u32 unk_40;
    u32 unk_44;
    u8 pad_48[0x4C];
    u8 *unk_94;
    u8 pad_98[0x20];
    u32 unk_B8;
    u8 pad_BC[0x20];
    u8 *unk_DC;
    u8 pad_E0[0x08];
    u32 unk_E8;
} FnB22AC_Work;
typedef struct FnB22AC_Ctx {
    u8 unk_00;
    s8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    s16 unk_08;
    s16 unk_0A;
    u32 unk_0C;
    u8 pad_10[0x14];
    FnB22AC_Work *unk_24;
    s8 unk_28;
    u8 pad_29;
    u8 unk_2A;
    u8 pad_2B;
    u8 unk_2C;
    u8 unk_2D;
    u8 pad_2E[0x02];
    u32 unk_30;
    f32 unk_34;
    f32 unk_38;
} FnB22AC_Ctx;

void fn_1_B22AC(FnB22AC_Ctx *ctx, u32 index) {
    u8 *data = (u8 *)&lbl_1_data_35AC8;
    const char *name = fn_80019C48();
    char *record = (char *)&lbl_1_rodata_4AE0 + index * 76;
    size_t name_len = strlen(record);
    FnB22AC_Work *work = ctx->unk_24;
    
    u8 *found1 = fn_80083970((u8 *)ctx->unk_24 + 0x20, data + 0x6cfc);
    u8 *found2 = fn_80083970((u8 *)ctx->unk_24 + 0x20, data + 0x6dd4);

    if (strncmp((char *)work + 0x48, name, 4) == 0 &&
        strncmp((char *)work + 0x4c, (char *)data + 0x7088, 2) == 0 &&
        strncmp((char *)work + 0x20, record, name_len) == 0 &&
        (found1 != 0 || found2 != 0)) {
        FnB22AC_Work *entry = (FnB22AC_Work *)((u8 *)work->unk_94 + ctx->unk_2D * 0x30);
        size_t copy_len;
        char *src = (char *)work + name_len + 0x20;
        if (found1 != 0) {
            copy_len = (u8 *)found1 - (u8 *)src;
            strncpy((char *)entry + 2, src, copy_len);
        } else {
            copy_len = (u8 *)found2 - (u8 *)src;
            strncpy((char *)entry + 2, src, copy_len);
        }
        *((char *)entry + copy_len + 2) = 0;
        *((u8 *)entry + 1) = (u8)index;
        entry->unk_24 = work->unk_40;
        entry->unk_28 = work->unk_44;
        ctx->unk_2D++;
        work->unk_08 |= 0x20;
        work->unk_08 |= 0x4;

        if (record[0x40] == 0 && index == 4) {
            u32 value = 0;
            int i;
            for (i = 0; i < 6; i++) {
                u32 ch = *((u8 *)entry + 2 + i);
                if (ch >= 0x41 && ch <= 0x46) ch -= 0x37;
                else ch -= 0x30;
                value += ch << ((4 - i) * 4);
            }
            work->unk_B8 = value;
        } else if (record[0x40] == 0 && index == 5) {
            u32 value = 0;
            int i;
            for (i = 0; i < 8; i++) {
                u32 ch = *((u8 *)entry + 2 + i);
                if (ch >= 0x41 && ch <= 0x46) ch -= 0x37;
                else ch -= 0x30;
                value += ch << ((7 - i) * 4);
            }
            work->unk_B8 = value;
        } else if (record[0x40] == 0 && index == 2) {
            work->unk_B8 = 0x3ea8;
        } else {
            work->unk_B8 = record[0x40];
        }

        work->unk_0C = entry->unk_24;
        sprintf((char *)work + 0x98, (char *)data + 0x713c, record, (char *)entry + 2);
        if (entry->unk_2C != 0) {
            fn_1_46B4(*(u32 *)lbl_801A6410, entry->unk_2C, (char *)data + 0x6cf0, 0x16f4);
            entry->unk_2C = 0;
        }
        entry->unk_2C = fn_1_4630(*(u32 *)lbl_801A6410, work->unk_B8, (char *)data + 0x6cf0, 0x16f7);
        if (work->unk_DC != 0) {
            fn_1_46B4(*(u32 *)lbl_801A6410, (u32)work->unk_DC, (char *)data + 0x6cf0, 0x16f9);
            work->unk_DC = 0;
        }
        work->unk_DC = (u8 *)fn_1_4630(*(u32 *)lbl_801A6410, work->unk_0C, (char *)data + 0x6cf0, 0x16fc);
    }
}
