#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ptclput.h"

extern u16 lbl_1_bss_6EA94;
extern struct fn_1_9F870_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern void fn_80008BA8(void *, const void *, u32);
extern u32 lbl_1_bss_6EA90;

/* fzgx:begin fn_1_9F7DC */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ptclput.h"

struct fn_1_9F7DC_lbl_1_bss_6EA88 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};
struct fn_1_9F7DC_lbl_801A6410 {
    u32 unk_0;
};

void fn_1_9F7DC(void) {
    struct fn_1_9F7DC_lbl_1_bss_6EA88 *p_lbl_1_bss_6EA88;
    p_lbl_1_bss_6EA88 = (struct fn_1_9F7DC_lbl_1_bss_6EA88 *)&lbl_1_bss_6EA88;

    p_lbl_1_bss_6EA88->unk_0 =
        fn_1_45D0((*(struct fn_1_9F7DC_lbl_801A6410 *)&lbl_801A6410).unk_0, 0x4000, &lbl_1_data_2CD20, 0x4c1);
    p_lbl_1_bss_6EA88->unk_4 =
        fn_1_45D0((*(struct fn_1_9F7DC_lbl_801A6410 *)&lbl_801A6410).unk_0, 0x4000, &lbl_1_data_2CD20, 0x4c2);
    p_lbl_1_bss_6EA88->unk_8 =
        fn_1_45D0((*(struct fn_1_9F7DC_lbl_801A6410 *)&lbl_801A6410).unk_0, 0x1800, &lbl_1_data_2CD20, 0x4c3);
}
/* fzgx:end fn_1_9F7DC */

/* fzgx:begin fn_1_9F870 */
#include "types.h"

struct fn_1_9F870_lbl_1_bss_6EA88 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};
struct fn_1_9F870_lbl_801A6410 {
    u32 unk_0;
};

void fn_1_9F870(void) {
    struct fn_1_9F870_lbl_1_bss_6EA88 *p_lbl_1_bss_6EA88;
    p_lbl_1_bss_6EA88 = (struct fn_1_9F870_lbl_1_bss_6EA88 *)&lbl_1_bss_6EA88;
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_1_bss_6EA88->unk_0, &lbl_1_data_2CD20, 1226);
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_1_bss_6EA88->unk_4, &lbl_1_data_2CD20, 1227);
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_1_bss_6EA88->unk_8, &lbl_1_data_2CD20, 1228);
}
/* fzgx:end fn_1_9F870 */

/* fzgx:begin fn_1_9F8FC */
void fn_1_9F8FC(void) {
    lbl_1_bss_6EA94 = 0;
    lbl_1_bss_6EA96 = 0;
}
/* fzgx:end fn_1_9F8FC */

/* fzgx:begin fn_1_9F914 */
int fn_1_9F914(const void *src0, const void *src1) {
    Obj_1_bss_6EA88 *obj = &lbl_1_bss_6EA88;

    if (*(u16 *)((u8 *)obj + 0xc) == 0x100) {
        return 0;
    }
    fn_80008BA8((u8 *)obj->unk_0 +
                    ((*(u16 *)((u8 *)obj + 0xc) & 0xffff) << 6),
                src0, 0x40);
    fn_80008BA8((u8 *)obj->unk_4 +
                    (*(u16 *)((u8 *)obj + 0xc) << 6),
                src1, 0x40);
    *(u16 *)((u8 *)obj + 0xc) = *(u16 *)((u8 *)obj + 0xc) + 1;
    return 1;
}
/* fzgx:end fn_1_9F914 */

/* fzgx:begin fn_1_9F9A4 */
struct fn_1_9F9A4_Blk {
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
    u32 w4;
    u32 w5;
};

s32 fn_1_9F9A4(u32 arg0) {
    u16 v0;
    u32 v1;
    u32 v2;

    v0 = lbl_1_bss_6EA96;
    v1 = arg0;
    if (v0 == 256) {
        v1 = 0;
        return v1;
    }
    v2 = (lbl_1_bss_6EA90 + (v0 * 24));
    *(struct fn_1_9F9A4_Blk *)v2 = *(struct fn_1_9F9A4_Blk *)v1;
    lbl_1_bss_6EA96++;
    return 1;
}
/* fzgx:end fn_1_9F9A4 */

/* fzgx:begin fn_1_A0D7C noprologue */
#include "types.h"
#include "dolphin/dvd.h"
#include "rel/main_rel/ptclput.h"

typedef struct Sig_DVDOpen_DVDFileInfo Sig_DVDOpen_DVDFileInfo;
typedef void (*Sig_DVDOpen_DVDCallback)(s32 result, Sig_DVDOpen_DVDFileInfo *fileInfo);
struct Sig_DVDOpen_DVDFileInfo {
    DVDCommandBlock cb;
    u32 startAddr;
    u32 length;
    Sig_DVDOpen_DVDCallback callback;
};
typedef struct Sig_fn_800174D0_Fn800174D0Object {
    u8 pad30[0x30];
    u32 field30;
    u32 field34;
    void *field38;
} Sig_fn_800174D0_Fn800174D0Object;
struct fn_1_A0D7C_lbl_801A6410 { u32 unk_0; };
extern BOOL DVDOpen(const char *, Sig_DVDOpen_DVDFileInfo *);
extern s16 lbl_1_bss_962;
extern s32 DVDClose(DVDCommandBlock *);
extern s32 fn_800658B4(s32, u32);
extern struct fn_1_A0D7C_lbl_801A6410 lbl_801A6410;
extern u32 fn_80006354(Sig_fn_800174D0_Fn800174D0Object *, void *, u32, u32);
extern u32 fn_80066C14(void *, u32);
extern char lbl_1_data_33F1C[8];
extern void *fn_1_45D0(u32, u32, const char *, int);
extern void fn_1_46B4(u32, void *, const char *, int);
void fn_1_A0D7C(void) {
    Sig_DVDOpen_DVDFileInfo loc_134;
    Sig_DVDOpen_DVDFileInfo loc_F8;
    Sig_DVDOpen_DVDFileInfo loc_BC;
    Sig_DVDOpen_DVDFileInfo loc_80;
    Sig_DVDOpen_DVDFileInfo loc_44;
    Sig_DVDOpen_DVDFileInfo loc_8;
    void *buffer_134;
    u32 length_134;
    u32 length_F8;
    void *buffer_F8;
    u32 length_BC;
    void *buffer_BC;
    u32 length_80;
    void *buffer_80;
    u32 length_44;
    void *buffer_44;
    u32 length_8;
    void *buffer_8;
    switch (*(s16 *)&lbl_1_bss_960) {
    case 7:
        DVDOpen((const char *)lbl_1_data_33F0C.unk_0, &loc_134);
        length_134 = loc_134.length;
        buffer_134 = fn_1_45D0(lbl_801A6410.unk_0, length_134 = (length_134 + 31) & ~31, lbl_1_data_33F1C, 766);
        if (buffer_134) {
            fn_80006354((Sig_fn_800174D0_Fn800174D0Object *)&loc_134, buffer_134, length_134, 0);
            DVDClose((DVDCommandBlock *)&loc_134);
            fn_80066C14(buffer_134, 0);
            fn_1_46B4(lbl_801A6410.unk_0, buffer_134, lbl_1_data_33F1C, 791);
        }
        fn_800658B4(0xA4000000, 0);
        break;
    case 10:
        DVDOpen((const char *)lbl_1_data_33F0C.unk_0, &loc_F8);
        length_F8 = loc_F8.length;
        buffer_F8 = fn_1_45D0(lbl_801A6410.unk_0, length_F8 = (length_F8 + 31) & ~31, lbl_1_data_33F1C, 766);
        if (buffer_F8) {
            fn_80006354((Sig_fn_800174D0_Fn800174D0Object *)&loc_F8, buffer_F8, length_F8, 0);
            DVDClose((DVDCommandBlock *)&loc_F8);
            fn_80066C14(buffer_F8, 0);
            fn_1_46B4(lbl_801A6410.unk_0, buffer_F8, lbl_1_data_33F1C, 791);
        }
        fn_800658B4(0xA4000000, 0);
        break;
    case 2: case 8: case 9: case 12:
        DVDOpen((const char *)lbl_1_data_33F0C.unk_4, &loc_BC);
        length_BC = loc_BC.length;
        buffer_BC = fn_1_45D0(lbl_801A6410.unk_0, length_BC = (length_BC + 31) & ~31, lbl_1_data_33F1C, 766);
        if (buffer_BC) {
            fn_80006354((Sig_fn_800174D0_Fn800174D0Object *)&loc_BC, buffer_BC, length_BC, 0);
            DVDClose((DVDCommandBlock *)&loc_BC);
            fn_80066C14(buffer_BC, 1);
            fn_1_46B4(lbl_801A6410.unk_0, buffer_BC, lbl_1_data_33F1C, 791);
        }
        break;
    case 1: case 5: case 13:
        DVDOpen((const char *)lbl_1_data_33F0C.unk_8, &loc_80);
        length_80 = loc_80.length;
        buffer_80 = fn_1_45D0(lbl_801A6410.unk_0, length_80 = (length_80 + 31) & ~31, lbl_1_data_33F1C, 766);
        if (buffer_80) {
            fn_80006354((Sig_fn_800174D0_Fn800174D0Object *)&loc_80, buffer_80, length_80, 0);
            DVDClose((DVDCommandBlock *)&loc_80);
            fn_80066C14(buffer_80, 2);
            fn_1_46B4(lbl_801A6410.unk_0, buffer_80, lbl_1_data_33F1C, 791);
        }
        break;
    case 4:
        if ((s16)lbl_1_bss_962 == 61) break;
        DVDOpen((const char *)lbl_1_data_33F0C.unk_C, &loc_44);
        length_44 = loc_44.length;
        buffer_44 = fn_1_45D0(lbl_801A6410.unk_0, length_44 = (length_44 + 31) & ~31, lbl_1_data_33F1C, 766);
        if (buffer_44) {
            fn_80006354((Sig_fn_800174D0_Fn800174D0Object *)&loc_44, buffer_44, length_44, 0);
            DVDClose((DVDCommandBlock *)&loc_44);
            fn_80066C14(buffer_44, 3);
            fn_1_46B4(lbl_801A6410.unk_0, buffer_44, lbl_1_data_33F1C, 791);
        }
        break;
    case 14: case 16:
        DVDOpen((const char *)lbl_1_data_33F0C.unk_C, &loc_8);
        length_8 = loc_8.length;
        buffer_8 = fn_1_45D0(lbl_801A6410.unk_0, length_8 = (length_8 + 31) & ~31, lbl_1_data_33F1C, 766);
        if (buffer_8) {
            fn_80006354((Sig_fn_800174D0_Fn800174D0Object *)&loc_8, buffer_8, length_8, 0);
            DVDClose((DVDCommandBlock *)&loc_8);
            fn_80066C14(buffer_8, 3);
            fn_1_46B4(lbl_801A6410.unk_0, buffer_8, lbl_1_data_33F1C, 791);
        }
        break;
    }
}
/* fzgx:end fn_1_A0D7C */
