/* Non-matching: best partial attempt (76.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/cloth.h"

extern u32 lbl_801A6410;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x58];
} Info;

typedef struct {
    u8 pad_0[8];
    u32 unk_8;
    u8 pad_C[1];
    u8 unk_D;
    u8 pad_E[0x12];
} TexEntry;

typedef struct {
    u8 pad_0[0x18];
    u16 count;
    u8 pad_1A[0x26];
    TexEntry entry[1];
} TexList;

typedef struct {
    u8 pad_0[0x30];
    void *p[2];
} Holder;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x240];
    u32 unk_248;
    u32 ptr_a[218];
    u32 ptr_b[210];
    u32 unk_8FC;
    u32 unk_900;
    u32 unk_904;
    u8 unk_908;
    u8 unk_909;
    u8 pad_90A[2];
    u32 texptrs[210];
} ClothBs;

extern void fn_1_465D0(u8 *arg0, s32 arg1);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern s32 fn_1_467F4(void);
extern u32 fn_1_46C70(u8 *arg0);
extern s32 fn_1_45730(char *arg0, void *arg1);
extern s32 fn_1_45B2C(void *arg0);
extern s32 fn_1_45B68(void *arg0);
extern void fn_1_45850(void *arg0);
extern u32 fn_1_45D0(u32 arg0, u32 arg1, u8 *arg2, u32 arg3);
extern u32 fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, u32 arg3);
extern u32 GXGetTexBufferSize(u16 arg0, u16 arg1, u32 arg2, u32 arg3, u32 arg4);
extern void GXInitTexObj(void *arg0, void *arg1, u16 arg2, u16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
extern int sprintf(char *arg0, const char *arg1, ...);
extern void OSReport(u8 *arg0, ...);
extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);

void fn_1_10688C(void) {
    TexList *lists[2];
    Info info;
    char name[0xA4];
    ClothBs *bss;
    Holder *h;
    u8 *data;
    u32 *texbuf;
    s16 i;
    s16 j;
    s32 grp;

    bss = (ClothBs *)&lbl_1_bss_85280;
    data = lbl_1_data_3F188;

    fn_1_465D0(data + 0x1F4, 3);

    while (fn_1_467F4() != 0) {
        fn_1_451E4();
        fn_1_D3214();
    }

    bss->unk_8FC = fn_1_46C70(data + 0x1F4);
    bss->unk_900 = 0;

    for (i = 0; i < 0xD2; i++) {
        sprintf(name, (const char *)(data + 0x204), i + 1);

        if (fn_1_45730(name, &info) == 0) {
            OSReport(data + 0x220, name);
            OSPanic(data + 0x1C4, 0x83A, data + 0x22C);
        }

        bss->ptr_a[i] = fn_1_45B2C(&info);
        bss->ptr_b[i] = fn_1_45B68(&info);
        fn_1_45850(&info);

        if (bss->unk_900 < bss->ptr_a[i]) {
            bss->unk_900 = bss->ptr_a[i];
        }
    }

    if (bss->unk_4 != 0) {
        OSReport(data + 0x23C);
    } else {
        bss->unk_4 = fn_1_45D0(lbl_801A6410, bss->unk_900,
                               data + 0x1C4, 0x847);
    }

    bss->unk_904 = GXGetTexBufferSize(0x80, 0x80, 6, 0, 0);

    texbuf = (u32 *)(data + 0xFC);

    if (texbuf[0] != 0 || texbuf[1] != 0 || bss->unk_0 != 0) {
        OSReport(data + 0x260);
    } else {
        texbuf[0] = fn_1_4630(lbl_801A6410, bss->unk_0,
                              data + 0x1C4, 0x84F);
        texbuf[1] = fn_1_4630(lbl_801A6410, bss->unk_904,
                              data + 0x1C4, 0x850);
        bss->unk_0 = fn_1_4630(lbl_801A6410, 0x4000, data + 0x1C4, 0x851);
    }

    bss->unk_908 = 0;
    bss->unk_909 = 0;
    bss->unk_248 = 1;

    h = (Holder *)((Obj_1_bss_38460_At8 *)lbl_1_bss_38460.unk_8)->unk_8;
    lists[0] = (TexList *)h->p[0];
    lists[1] = (TexList *)h->p[1];

    for (grp = 0; grp < 2; grp++) {
        TexList *list = lists[grp];

        for (j = 0; j < (s32)list->count; j++) {
            if (list->entry[j].unk_D == 1) {
                bss->texptrs[bss->unk_909++] = list->entry[j].unk_8;
                GXInitTexObj((void *)list->entry[j].unk_8,
                             (void *)texbuf[bss->unk_908],
                             0x80, 0x80, 6, 0, 0, 0);
            }
        }
    }
}
