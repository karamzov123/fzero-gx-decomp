/* Non-matching: best partial attempt (95.87% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct {
    u32 flags;
    s32 unk_4;
    u32 unk_8;
    u32 unk_C;
} Sig_fn_1_45730_LoadEntry;
typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
    Sig_fn_1_45730_LoadEntry entry;
} Sig_fn_1_45730_LoadResult;
typedef struct Sig_fn_1_45B2C_Fn145B2CData {
    s32 kind;
    u8 pad[0x54];
    void *value;
} Sig_fn_1_45B2C_Fn145B2CData;
struct Sig_fn_1_45850_fn_1_45850_Arg0 {
    u32 unk_0;
};

typedef struct SelPlayer {
    s16 kind;
    u8 pad_2[4];
    u8 flag;
    u8 pad_7[0x17];
    s16 tail;
} SelPlayer;

struct _prolog_lbl_1_bss_8B3A0 {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    s16 unk_A;
    s16 unk_C;
    SelPlayer players[4];
    s16 unk_8E;
    s16 unk_90;
    s16 unk_92;
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[2];
    u8 unk_9E;
    u8 unk_9F[4];
    u8 pad_A3;
    s16 *unk_A4;
    u8 pad_A8[0x81];
    u8 unk_129;
    u8 unk_12A;
    u8 unk_12B;
    u8 pad_12C[0x14];
    u8 unk_140[0xC];
};
struct _prolog_lbl_10_bss_0 {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x8];
    u32 unk_10;
};
struct _prolog_lbl_1_bss_8B5F4 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
};
struct _prolog_lbl_801A6410 {
    u32 unk_0;
};
struct _prolog_lbl_1_bss_960 {
    s16 unk_0;
};

extern int fn_1_45730(void *, Sig_fn_1_45730_LoadResult *);
extern s32 fn_1_45D0(u32, u32, const char *, int);
extern struct _prolog_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern struct _prolog_lbl_1_bss_8B5F4 lbl_1_bss_8B5F4;
extern struct _prolog_lbl_1_bss_960 lbl_1_bss_960;
extern struct _prolog_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_3CF0(u32, u32);
extern u32 fn_1_45850(struct Sig_fn_1_45850_fn_1_45850_Arg0 *);
extern u32 fn_1_4630(u32, u32, const char *, int);
extern u32 fn_1_4706C(void);
extern u32 fn_1_7BA08(u32, u32, u32);
extern u32 fn_1_7BA48(void);
extern u32 fn_1_A0680(void);
extern void * fn_1_45B2C(Sig_fn_1_45B2C_Fn145B2CData *);
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_1_159440(int, int);
extern void fn_1_411A4(u32);
extern u32 fn_1_4404(void);
extern void fn_1_469BC(void);
extern void fn_1_46A60(void);
extern void fn_1_479F0(s16);
extern void fn_1_47F74(s32);
extern void fn_1_48418(int);
extern void fn_1_5124(u32, u32);
extern void fn_1_52070(u32);
extern void fn_80008BEC(void *, int, u32);


#define W(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define B(p,o) (*(u8 *)((u8 *)(p)+(o)))
extern u32 fn_800090A4(u32);
extern void fn_1_46BA0(u32,u32);
extern u32 fn_1_46ED8(void);
extern u32 fn_1_46A8C(u32);
extern void fn_1_465D0(void *,int);
extern void fn_1_46B44(void (*)(void *), void *);
extern void fn_10_C654(void *);
extern void fn_10_C5E0(void *);
extern void fn_1_41104(u32);
extern u32 fn_1_47E54(u32);
extern void fn_1_46BFC(void);
extern u32 fn_80008E84(u32);
extern void fn_8006CE1C(f32);
extern u32 fn_1_435C(u32);
extern void fn_1_7BAF8(void);
extern void fn_1_3F8C(void *,void (*)(void),u32,u32);
extern void fn_1_A5330(s32, s32);
extern s16 fn_1_12EF24(s16,s16);
extern s16 fn_1_8D7C8(void);
extern void fn_10_5780(void *);
extern void fn_10_834(void);
extern void fn_10_AB8(void);
extern void fn_10_CF50(void);
extern void fn_1_12F17C(void);
extern void fn_1_36ADC(void);
extern u8 lbl_1_bss_970[];
extern s16 lbl_1_bss_96A;
extern s16 lbl_1_bss_8CA26;
extern void (*lbl_1_bss_7167C)(void);
extern void (*lbl_1_bss_71680)(void);
extern void (*lbl_1_bss_71684)(void);
extern const u32 lbl_10_rodata_0[12];

u32 fzgx_obj_lbl_10_bss_0;
u32 lbl_10_bss_0__fzgx_offset_4;
u32 lbl_10_bss_0__fzgx_offset_8;
u8 lbl_10_bss_0__fzgx_offset_C;
u32 lbl_10_bss_0__fzgx_offset_10;
u32 fzgx_obj_lbl_10_bss_14;
s16 fzgx_obj_lbl_10_bss_18;
s16 fzgx_obj_lbl_10_bss_1A;
u8 fzgx_obj_lbl_10_bss_1C[0x3A4];
u8 lbl_10_bss_3C0[0x48FC0];
u32 fzgx_obj_lbl_10_bss_49380;
u32 fzgx_obj_lbl_10_bss_49384;
u32 fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u8 fzgx_obj_lbl_10_bss_49390[0x10];
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_10_bss_0;
    s = *(u8 *)&lbl_10_bss_0__fzgx_offset_4;
    s = *(u8 *)&lbl_10_bss_0__fzgx_offset_8;
    s = *(u8 *)&lbl_10_bss_0__fzgx_offset_C;
    s = *(u8 *)&lbl_10_bss_0__fzgx_offset_10;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_14;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_1A;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_1C;
    s = *(u8 *)&lbl_10_bss_3C0;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_49380;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_49384;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_49388;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_4938C;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_4938E;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_4938F;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_49390;
}
#pragma section code_type ".text"
static u32 fzgx_pool_fzgx_data_lbl_10_data_0[0x117] = {  /* fzgx-allow: A1 retail data bytes: the TU's .data objects before its first stored word; dropped at integration */
    0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156,
    0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354,
    0x00000000, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000,
    0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000,
    0x554E4C49, 0x4E4B0000, 0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C,
    0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000,
    0x454E5452, 0x595F4F4B, 0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348,
    0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552,
    0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500,
    0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000,
    0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B,
    0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152,
    0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259,
    0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552,
    0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900,
    0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010001, 0x00010001, 0x01010101,
    0x00010101, 0x01010000, 0x00010000, 0x01010101, 0x01010001, 0x01010101, 0x01010101, 0x01010101,
    0x01010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x0029001F, 0x00200006, 0x00020005, 0x00040001, 0x00210022,
    0x002DFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF002A, 0x00030007, 0x00080009, 0x0000000A,
    0x000B000C, 0x000D002E, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x002B000E, 0x000F0010,
    0x00110012, 0x00130014, 0x00150016, 0x002FFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF002C,
    0x00230024, 0x00170018, 0x0019001A, 0x001B0025, 0x00260030, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFF0036, 0x00370027, 0x001C001D, 0x001E0028, 0x00380039, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0x0031FFFF, 0x0002FFFF, 0x0005FFFF, 0x0024FFFF, 0x0020FFFF, 0x0021FFFF,
    0x0022FFFF, 0x001FFFFF, 0x002EFFFF, 0x0030FFFF, 0x0006FFFF, 0x0004FFFF, 0x0028FFFF, 0x0027FFFF,
    0x0023FFFF, 0x0025FFFF, 0x0026FFFF, 0x002DFFFF, 0x002FFFFF, 0x00010001, 0x00010004,
};
u32 lbl_10_data_45A__fzgx_offset_2 = 0x40000000;
static u32 fzgx_pool_fzgx_data_lbl_10_data_460[0x46] = {  /* fzgx-allow: A1 retail data bytes: the TU's .data objects up to its next stored word; dropped at integration */
    0x02000401, 0x01000801, 0x01000201, 0x01000011, 0x01000201, 0x01001001, 0x01004001, 0x01000201,
    0x01002001, 0x01000801, 0x01000011, 0xFFFFFFFF, 0x02000011, 0x01000401, 0x01000201, 0x01000401,
    0x01000201, 0x01001001, 0x01000401, 0x01008001, 0x01000201, 0x01000801, 0x01001001, 0xFFFFFFFF,
    0x02000801, 0x01000011, 0x01000201, 0x01002001, 0x01000401, 0x01004001, 0x01000201, 0x01000011,
    0x01004001, 0x01000401, 0x01000201, 0xFFFFFFFF, 0x01001003, 0x01000203, 0x01000013, 0x01002003,
    0x01000803, 0x01000803, 0x01004003, 0x01004003, 0xFFFFFFFF, 0x01004003, 0x01000403, 0x01000803,
    0x01004003, 0x01000013, 0x01000203, 0x01008003, 0x01001003, 0xFFFFFFFF, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000005, 0x00000000, 0x00060002, 0x00050004, 0x00060002,
    0x00050004, 0xFFFFFFFF, 0xFFFFFFFF, 0x4341525F, 0x53454C00, 0x00000000,
};
s32 fzgx_obj_lbl_10_data_578 = -1;

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("sel.c");
    OSReport("Wrong CarMap col row\n");
    OSReport("vehicle/vehicle_sel.arc.lz");
    OSReport("vehicle archive file is nothing");
    OSReport("LightMain");
}
#pragma section code_type ".text"
static inline void sel_reset_players(void) {
    s32 i;

    lbl_1_bss_8B3A0.unk_4 = 1;
    lbl_1_bss_8B3A0.unk_6 = 30;
    lbl_1_bss_8B3A0.unk_8 = 1;
    for (i = 0; (s16)i < 4; i++) {
        lbl_1_bss_8B3A0.players[i].kind = -1;
        lbl_1_bss_8B3A0.unk_9F[i] = 50;
        fn_1_A5330(50, i);
    }
}

void _prolog(void) {
    u32 saved, amount;
    s32 i;
    s16 slot;
    u32 flags;
    struct _prolog_lbl_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    s16 v0;
    u32 v2;
    u32 v3;
    s32 v4;
    s16 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    u32 v9;
    u32 v10;
    s32 v11;
    u32 v12;
    s32 v13;
    u32 v14;
    u32 v15;
    struct { u32 a[23]; } loc_8;
    /* frame */
    int t0;
    void * t2;
    u32 t6;
    u32 t7;
    u32 t8;
    s32 t9;
    s32 t11;
    s32 t13;
    v0 = lbl_1_bss_8B3A0.unk_A;
    if (v0 != -1) {
    lbl_1_bss_8B3A0.unk_8 = v0;
    }
    p_lbl_1_bss_8B3A0 = (struct _prolog_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0;
    v2 = p_lbl_1_bss_8B3A0->unk_94;
    p_lbl_1_bss_8B3A0->unk_9E = 0;
    v3 = (v2 & 0xFFFFFDFF);
    p_lbl_1_bss_8B3A0->unk_94 = v3;
    if ((v2 & 0x40000000) == 0) {
    p_lbl_1_bss_8B3A0->unk_94 = (v3 | 256);
    }
    t0 = fn_1_45730("vehicle/vehicle_sel.arc.lz", (Sig_fn_1_45730_LoadResult *)&loc_8);
    if ((s32)t0 == 0) {
    OSPanic("sel.c", 664, "vehicle archive file is nothing");
    }
    t2 = (void *)(fn_1_45B2C((Sig_fn_1_45B2C_Fn145B2CData *)&loc_8));
    lbl_10_bss_0__fzgx_offset_10 = ((u32)((u8 *)t2 + 31) & ~0x1F);
    fn_1_45850((struct Sig_fn_1_45850_fn_1_45850_Arg0 *)&loc_8);
    lbl_1_bss_8B5F4.unk_0 = 0;
    lbl_1_bss_8B5F4.unk_4 = 0;
    lbl_1_bss_8B5F4.unk_8 = 0;
    lbl_1_bss_8B5F4.unk_C = 0;
    lbl_1_bss_8B5F4.unk_10 = 0;
    lbl_1_bss_8B5F4.unk_14 = 0;
    lbl_1_bss_8B5F4.unk_18 = 0;
    lbl_1_bss_8B5F4.unk_1C = 0;
    fn_80008BEC(lbl_10_bss_3C0, 0, sizeof(lbl_10_bss_3C0));
    fn_1_A0680();
    t6 = fn_1_4630(lbl_801A6410.unk_0, 3108, "sel.c", 0x2a9);
    lbl_10_bss_0__fzgx_offset_4 = t6;
    t7 = fn_1_4630(lbl_801A6410.unk_0, (0x10000 - 20928), "sel.c", 0x2aa);
    fzgx_obj_lbl_10_bss_49380 = t7;
    for (v5 = 0; v5 < 41; v5++) {
        *(s32 *)((u8 *)fzgx_obj_lbl_10_bss_49380 + v5 * 1088 + 804) = -1;
    }
    t9 = fn_1_45D0(lbl_801A6410.unk_0, fn_1_7BA08(32, 32, 64), "sel.c", 0x2ac);
    fzgx_obj_lbl_10_bss_0 = t9;
    fn_1_7BA48();
    t11 = fn_1_45D0(lbl_801A6410.unk_0, 5948, "sel.c", 0x2ad);
    fzgx_obj_lbl_10_bss_49384 = t11;
    fn_1_3CF0(t11, 128);
    t13 = fn_1_45D0(lbl_801A6410.unk_0, 5948, "sel.c", 0x2ae);
    fzgx_obj_lbl_10_bss_49388 = t13;
    fn_1_3CF0(t13, 128);
    fn_1_5124(fzgx_obj_lbl_10_bss_49384, fzgx_obj_lbl_10_bss_49388);
    fn_1_411A4(1);
    if ((p_lbl_1_bss_8B3A0->unk_94 & 0x40000000) != 0) {
    fn_1_48418(2);
    fn_1_479F0(lbl_1_bss_960.unk_0);
    fn_1_469BC();
    fn_1_4706C();
    fn_1_46A60();
    fn_1_159440(1, 0);
    fn_1_159440(2, 0);
    fn_1_159440(3, 0);
    } else {
    if ((p_lbl_1_bss_8B3A0->unk_94 & 0x2000000) != 0) {
    fn_1_47F74(154);
    fn_1_47F74(155);
    fn_1_47F74(48);
    } else {
    fn_1_48418(2);
    fn_1_47F74(154);
    fn_1_47F74(155);
    fn_1_47F74(157);
    fn_1_47F74(161);
    fn_1_47F74(156);
    fn_1_47F74(162);
    fn_1_469BC();
    fn_1_4706C();
    fn_1_46A60();
    fn_1_159440(2, 1);
    }
    }
    fn_1_52070(320);
    v15 = p_lbl_1_bss_8B3A0->unk_94;
    if ((v15 & 0x2000000) == 0) {
    if ((v15 & ~0x7FFFFFFF) == 0) {

    saved = fn_1_4404();
    amount = fn_800090A4(lbl_801A6410.unk_0) - 0x10000;
    fzgx_obj_lbl_10_data_578 = fn_1_45D0(lbl_801A6410.unk_0,amount,"sel.c",0x2ed);
    fn_1_46BA0(fzgx_obj_lbl_10_data_578,amount);
    fn_1_46A8C((fn_1_46ED8() & ~31) - lbl_10_bss_0__fzgx_offset_10);
    fn_1_465D0("vehicle/vehicle_sel.arc.lz",2);
    fn_1_46B44(fn_10_C654,&lbl_1_bss_8B5F4);
    if (!(p_lbl_1_bss_8B3A0->unk_94 & 0x20)) {
        fn_1_41104(1);
        fn_1_41104(6);
        fn_1_47E54(0x9a);
        fn_1_47E54(0x9b);
        fn_1_47E54(0xba);
        fn_1_47E54(0xa0);
    }
    fn_1_46BFC();
    lbl_10_bss_0__fzgx_offset_C=1;
    fn_1_46B44(fn_10_C5E0,&fzgx_obj_lbl_10_data_578);
    fn_80008E84(saved);
    }
    }
    W(lbl_1_bss_970,0)=0;
    B(lbl_1_bss_970,4)=13;
    fn_8006CE1C(*(const f32 *)lbl_10_rodata_0);
    fn_1_435C(fzgx_obj_lbl_10_bss_49388);
    fn_1_3F8C("LightMain",fn_1_7BAF8,fzgx_obj_lbl_10_bss_0,2);
    lbl_1_bss_8B3A0.unk_129=1;
    lbl_1_bss_8B3A0.unk_A4=(s16 *)lbl_10_bss_0__fzgx_offset_4;
    if (!(p_lbl_1_bss_8B3A0->unk_94 & 0x30)) {
        lbl_1_bss_8B3A0.unk_0=-1;
    }
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x08000000;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x0c000000;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x01000000;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x00200000;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x00300000;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x00380000;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x80;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0xc0;
    flags=p_lbl_1_bss_8B3A0->unk_94;
    if (flags & 0x40000000) {
        lbl_1_bss_96A = (flags & 0x2000) ? 22 : 26;
        for (i=0;(s16)i<4;i++) {
            lbl_1_bss_8B3A0.unk_9F[i]=50;
            fn_1_A5330(50,i);
        }
        lbl_1_bss_8B3A0.unk_0=9;
        sel_reset_players();
        lbl_1_bss_8B3A0.players[0].kind=6;
        lbl_1_bss_8B3A0.players[3].tail=6;
        lbl_1_bss_8B3A0.unk_8E=0;
        lbl_1_bss_8B3A0.unk_90=fn_1_12EF24(6,0);
        lbl_1_bss_8B3A0.unk_12A=1;
        lbl_1_bss_8B3A0.unk_12B=0;
        lbl_1_bss_8CA26=0;
        fzgx_obj_lbl_10_bss_18=19;
        fzgx_obj_lbl_10_bss_1A=2;
        fzgx_obj_lbl_10_bss_4938C=15;
    } else {
        lbl_1_bss_96A=14;
        fzgx_obj_lbl_10_bss_18=19;
        fzgx_obj_lbl_10_bss_1A=6;
        fzgx_obj_lbl_10_bss_4938C=15;
        if (flags & 0x20) {
            lbl_1_bss_96A=15;
        } else if (flags & 0x10) {
            lbl_1_bss_96A=16;
        } else {
            *lbl_1_bss_8B3A0.unk_A4=-1;
            fn_10_5780(&lbl_1_bss_8B3A0);
        }
    }
    if ((p_lbl_1_bss_8B3A0->unk_94 & 0x40000000) ||
        (p_lbl_1_bss_8B3A0->unk_94 & 0x02000000)) {
        p_lbl_1_bss_8B3A0->unk_94 |= 0x20000000;
    }
    lbl_1_bss_8B3A0.unk_98=0;
    lbl_1_bss_8B3A0.unk_98=0x80000000 >> p_lbl_1_bss_8B3A0->unk_9E;
    slot = fn_1_8D7C8() < 30 ? fn_1_8D7C8() : 30;
    fzgx_obj_lbl_10_bss_4938E=slot;
    lbl_1_bss_7167C=fn_10_834;
    lbl_1_bss_71680=fn_10_AB8;
    lbl_1_bss_71684=fn_10_CF50;
    if (p_lbl_1_bss_8B3A0->unk_94 & 0x02000000) {
        SelPlayer *players = lbl_1_bss_8B3A0.players;

        slot=p_lbl_1_bss_8B3A0->unk_9E;
        lbl_1_bss_8B3A0.unk_4=1;
        lbl_1_bss_8B3A0.unk_0=4;
        lbl_1_bss_8B3A0.unk_6=1;
        lbl_1_bss_8B3A0.players[0].kind=-1;
        players[1].kind=-1;
        players[2].kind=-1;
        players[3].kind=-1;
        players[slot].kind=6;
        lbl_1_bss_8B3A0.players[slot].flag=1;
        lbl_1_bss_8B3A0.unk_9F[slot]=50;
        lbl_1_bss_8B3A0.unk_90=1;
        lbl_1_bss_8B3A0.players[3].tail=1;
        lbl_1_bss_8B3A0.unk_8E=0;
        fn_1_A5330(50,slot);
        lbl_10_data_45A__fzgx_offset_2=0x80000000;
        lbl_1_bss_96A=18;
    }
    fn_1_12F17C();
    fn_1_36ADC();
    fn_80008BEC(lbl_1_bss_8B3A0.unk_140,0,12);
    fzgx_obj_lbl_10_bss_49390[0]=0;
    fzgx_obj_lbl_10_bss_4938F=0;
}
