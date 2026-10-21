#include "types.h"

/* fzgx:begin _prolog */
struct _prolog_lbl_14_bss_0 {
    u8 pad_0[0x14];
    u32 unk_14;
    u8 pad_18[0x4];
    u32 unk_1C;
    u32 unk_20;
};

struct _prolog_lbl_801A6410 {
    u32 unk_0;
};

typedef struct Sig_ADXT_Stop_ADXTHandle Sig_ADXT_Stop_ADXTHandle;

extern struct _prolog_lbl_14_bss_0 lbl_14_bss_0;
extern struct _prolog_lbl_801A6410 lbl_801A6410;
extern u8 lbl_14_data_2FB0;
extern u8 lbl_14_data_2FC0;
extern const f32 lbl_14_rodata_0;
extern s16 lbl_1_bss_96A;
extern Sig_ADXT_Stop_ADXTHandle **lbl_1_bss_6EAD0;

extern void *lbl_1_bss_7167C[];
extern void *lbl_1_bss_71680;
extern void *lbl_1_bss_71684[];

extern void fn_14_220(void);
extern void fn_14_2A0(void);
extern u32 fn_14_268(void);
extern u32 fn_14_DC2C(void);
extern u32 fn_1_7BA08(u32, u32, u32);
extern s32 fn_1_45D0(u32, u32, const void *, s32);
extern void fn_1_7BA48(u32);
extern void fn_1_3CF0(u32, u32);
extern u32 fn_1_435C(u32);
extern s32 fn_1_3F8C(const void *, void *, u32, u32);
extern void fn_1_7BAF8(void);
extern void fn_1_411A4(u32);
extern void fn_1_48418(int);
extern void fn_1_479F0(s16);
extern void fn_1_159440(int, int);
extern void fn_8006CE1C(f32);
extern void fn_1_A8F78(void);
extern u32 fn_1_A0680(void);
extern u32 fn_1_A1588(Sig_ADXT_Stop_ADXTHandle *, u32);
extern void fn_1_3EF14(void *);

void _prolog(void) {
    struct _prolog_lbl_14_bss_0 *p_lbl_14_bss_0;
    u32 buffer[1328];

    p_lbl_14_bss_0 = (struct _prolog_lbl_14_bss_0 *)&lbl_14_bss_0;

    lbl_1_bss_7167C[0] = (void *)fn_14_220;
    lbl_1_bss_71680 = (void *)fn_14_268;
    lbl_1_bss_71684[0] = (void *)fn_14_2A0;

    p_lbl_14_bss_0->unk_14 = fn_1_45D0(lbl_801A6410.unk_0, fn_1_7BA08(0x20, 0x20, 0x40), (const char *)&lbl_14_data_2FB0, 0x313);
    fn_1_7BA48(p_lbl_14_bss_0->unk_14);

    p_lbl_14_bss_0->unk_1C = fn_1_45D0(lbl_801A6410.unk_0, 0x173C, (const char *)&lbl_14_data_2FB0, 0x314);
    fn_1_3CF0(p_lbl_14_bss_0->unk_1C, 0x80);

    p_lbl_14_bss_0->unk_20 = fn_1_45D0(lbl_801A6410.unk_0, 0x173C, (const char *)&lbl_14_data_2FB0, 0x315);
    fn_1_3CF0(p_lbl_14_bss_0->unk_20, 0x80);

    fn_1_435C(p_lbl_14_bss_0->unk_20);
    fn_1_3F8C(&lbl_14_data_2FC0, (void *)fn_1_7BAF8, p_lbl_14_bss_0->unk_14, 2);

    fn_1_411A4(1);
    fn_1_48418(2);
    fn_1_479F0(13);
    fn_1_479F0(1);
    fn_1_159440(2, 0);

    lbl_1_bss_96A = 0xAC;
    fn_8006CE1C(lbl_14_rodata_0);

    fn_1_A8F78();
    fn_1_A0680();

    fn_1_A1588(*lbl_1_bss_6EAD0, 0x1F);
    fn_14_DC2C();
    fn_1_3EF14(buffer);
}
/* fzgx:end _prolog */

/* fzgx:begin _epilog */
struct _epilog_lbl_14_bss_0 {
    u8 pad_0[0x14];
    u32 unk_14;
    u8 pad_18[0x4];
    u32 unk_1C;
    u32 unk_20;
};
struct _epilog_lbl_801A6410 {
    u32 unk_0;
};

extern struct _epilog_lbl_14_bss_0 lbl_14_bss_0;
extern struct _epilog_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_1596DC(u32);
extern u32 fn_1_412A0(u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_A0AA4(void);
extern u32 lbl_14_data_2FB0;
extern void fn_1_41A8(void);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_47A60(s16);
extern void fn_1_484CC(s32);

void _epilog(void) {
    struct _epilog_lbl_14_bss_0 *p_lbl_14_bss_0;
    p_lbl_14_bss_0 = (struct _epilog_lbl_14_bss_0 *)&lbl_14_bss_0;
    fn_1_435C(p_lbl_14_bss_0->unk_1C);
    fn_1_41A8();
    fn_1_435C(p_lbl_14_bss_0->unk_20);
    fn_1_41A8();
    fn_1_1596DC(2);
    fn_1_47A60(1);
    fn_1_47A60(13);
    fn_1_484CC(2);
    fn_1_412A0(1);
    fn_1_A0AA4();
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_14_bss_0->unk_14, (const char *)&lbl_14_data_2FB0, 860);
    p_lbl_14_bss_0->unk_14 = 0;
}
/* fzgx:end _epilog */

/* fzgx:begin fn_14_220 */
extern struct fn_14_220_lbl_14_bss_1C lbl_14_bss_1C;
extern struct fn_14_220_lbl_14_bss_20 lbl_14_bss_20;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_435C(u32);

struct fn_14_220_lbl_14_bss_1C {
    u32 unk_0;
};
struct fn_14_220_lbl_14_bss_20 {
    u32 unk_0;
};

void fn_14_220(void) {
    u32 t0, t1, t3;
    t0 = fn_1_435C(lbl_14_bss_1C.unk_0);
    t1 = fn_1_407C(t0);
    fn_1_3CC4(t1);
    t3 = fn_1_435C(lbl_14_bss_20.unk_0);
    fn_1_407C(t3);
}
/* fzgx:end fn_14_220 */

/* fzgx:begin fn_14_268 */
struct fn_14_268_lbl_1_bss_8B3A0 {
    u8 pad_0[0x124];
    u32 unk_124;
};

struct fn_14_268_lbl_14_bss_0 {
    u32 unk_0;
};

extern struct fn_14_268_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern struct fn_14_268_lbl_14_bss_0 lbl_14_bss_0;

u32 fn_14_268(void) {
    u32 v0;

    lbl_14_bss_0.unk_0--;
    v0 = lbl_1_bss_8B3A0.unk_124;
    if (v0 + 0x10000 != 0xffff) {
        lbl_1_bss_8B3A0.unk_124 = v0 - 1;
    }
    return (u32)v0;
}
/* fzgx:end fn_14_268 */

/* fzgx:begin fn_14_2A0 */
typedef u32 (*fn_14_2A0_Fn0)(void);
struct fn_14_2A0_Entry {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};

extern s16 lbl_1_bss_962;
extern u8 lbl_14_data_308[128];
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;

void fn_14_2A0(void) {
    struct fn_14_2A0_Entry *entry;
    s32 index;
    entry = (struct fn_14_2A0_Entry *)lbl_14_data_308;
    index = lbl_1_bss_962;
    entry += index - 172;
    lbl_1_bss_71688 = entry->unk_8;
    lbl_1_bss_7168C = entry->unk_C;
    ((fn_14_2A0_Fn0)entry->unk_4)();
}
/* fzgx:end fn_14_2A0 */

/* fzgx:begin fn_14_2FC */
struct fn_14_2FC_lbl_1_bss_8B3A0 {
    u8 pad_0[0x94];
    u32 unk_94;
};
struct fn_14_2FC_lbl_14_bss_0 {
    u32 unk_0;
    u8 pad_4[0x20];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
};

extern struct fn_14_2FC_lbl_14_bss_0 lbl_14_bss_0;
extern struct fn_14_2FC_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern u32 fn_1_12F1E8(u32);
extern u32 fn_1_A2D84(u32);

void fn_14_2FC(void) {
    u32 v0;
    struct fn_14_2FC_lbl_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    p_lbl_1_bss_8B3A0 = &lbl_1_bss_8B3A0;
    lbl_14_bss_0.unk_0 = 60;
    v0 = p_lbl_1_bss_8B3A0->unk_94;
    lbl_14_bss_0.unk_24 = 24;
    lbl_14_bss_0.unk_28 = 24;
    lbl_14_bss_0.unk_2C = 16;
    lbl_14_bss_0.unk_30 = 16;
    lbl_14_bss_0.unk_34 = 12;
    p_lbl_1_bss_8B3A0->unk_94 = (v0 | 0x40000000);
    fn_1_12F1E8(539);
    p_lbl_1_bss_8B3A0->unk_94 = v0;
    fn_1_A2D84(0xA9110000);
}
/* fzgx:end fn_14_2FC */

/* fzgx:begin fn_14_380 */
#include "font.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 167.0f;
    s = 38.0f;
    s = 90.0f;
    s = 320.0f;
    s = 216.0f;
    s = 8.0f;
    s = 96.0f;
    s = 336.0f;
    s = 380.0f;
    d = 12.0;
    s = 1.0f;
    s = 99.0f;
    s = 30.0f;
    s = 140.0f;
    s = 178.0f;
    s = 254.0f;
    s = 292.0f;
    s = 541.0f;
    s = 575.0f;
    s = 98.0f;
    s = 42.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

struct fn_14_380_Copy88 { u32 a[22]; };
struct fn_14_380_lbl_14_bss_0 {
    u32 unk_0;
    u8 pad_4[0x20];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
};
struct fn_14_380_lbl_14_rodata_0 {
    u8 pad_0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f64 unk_28;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    u8 pad_5C[0x4];
    f64 unk_60;
};
struct fn_14_380_lbl_14_data_D50 {
    u32 unk_0[1];
};

extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_14_380_lbl_14_bss_0 lbl_14_bss_0;
extern struct fn_14_380_lbl_14_data_D50 lbl_14_data_D50;
extern struct fn_14_380_lbl_14_rodata_0 lbl_14_rodata_0;
extern u16 lbl_1_bss_96A;
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13B328(u32, u32);
extern u32 fn_1_13DC54(void);
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66B4;
extern void fn_1_133DBC(void *);
extern void fn_1_138120(void *);
extern void fn_1_50164(f32, f32, f32, f32, FontDrawPacket *);

f32 fn_14_380(void) {
    struct fn_14_380_lbl_14_bss_0 *p_lbl_14_bss_0;
    struct fn_14_380_lbl_14_rodata_0 *p_lbl_14_rodata_0;
    f32 v1;
    f32 v0;
    f32 v18;
    u32 v2;
    u32 v3;
    u32 v4;
    f32 v5;
    f32 v6;
    f32 v7;
    f64 v8;
    f32 v9;
    f32 v10;
    f32 v11;
    f32 v12;
    f32 v13;
    f32 v14;
    f64 v16;
    f32 v17;
    f32 v19;
    f32 v20;
    f32 v21;
    f32 v22;
    f32 v23;
    f32 v24;
    f32 v25;
    f32 v26;
    f32 v27;
    f32 v28;
    f32 v29;
    f32 v30;
    f32 v31;
    f32 v32;
    f32 v33;
    f32 v34;
    f32 v35;
    f32 v36;
    f32 v37;
    f32 v38;
    f32 v39;
    f32 v40;
    f32 v41;
    f32 v42;
    f32 v43;
    f32 v44;
    f32 v45;
    f32 v46;
    f32 v47;
    f32 v48;
    f32 v49;
    u32 v50;
    FontDrawPacket loc_8;
    /* frame */
    p_lbl_14_rodata_0 = (struct fn_14_380_lbl_14_rodata_0 *)&lbl_14_rodata_0;
    p_lbl_14_bss_0 = (struct fn_14_380_lbl_14_bss_0 *)&lbl_14_bss_0;
    fn_1_133DBC((void *)0);
    fn_1_134AD4();
    fn_1_13DC54();
    fn_1_13B328(0x1000000, 1);
    fn_1_138120((void *)lbl_14_data_D50.unk_0[lbl_801A66B4]);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v0 = (167.0f);
    v1 = (38.0f);
    loc_8.image = (0x10000 - 28155);
    loc_8.x = v0;
    loc_8.y = v1;
    loc_8.z = (90.0f);
    loc_8.flags = 10;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_8.image = (0x10000 - 25045);
    loc_8.flags = 10;
    p_lbl_14_bss_0->unk_28 += p_lbl_14_bss_0->unk_30;
    if ((s32)p_lbl_14_bss_0->unk_28 > 190) {
    p_lbl_14_bss_0->unk_28 = 190;
    p_lbl_14_bss_0->unk_24 += p_lbl_14_bss_0->unk_2C;
    }
    if ((s32)p_lbl_14_bss_0->unk_24 > 396) {
    p_lbl_14_bss_0->unk_24 = 396;
    }
    loc_8.x = (320.0f);
    loc_8.y = (216.0f);
    v5 = (8.0f);
    fn_1_50164((f32)(s32)p_lbl_14_bss_0->unk_24, (f32)(s32)p_lbl_14_bss_0->unk_28, v5, v5, (FontDrawPacket *)&loc_8);
    loc_8.x = (320.0f);
    loc_8.y = (96.0f);
    v9 = (8.0f);
    fn_1_50164((f32)(s32)p_lbl_14_bss_0->unk_24, (38.0f), v9, v9, (FontDrawPacket *)&loc_8);
    loc_8.x = (320.0f);
    loc_8.y = (336.0f);
    v11 = (8.0f);
    fn_1_50164((f32)(s32)p_lbl_14_bss_0->unk_24, (38.0f), v11, v11, (FontDrawPacket *)&loc_8);
    loc_8.x = (320.0f);
    loc_8.y = (380.0f);
    v13 = (8.0f);
    fn_1_50164((f32)(s32)p_lbl_14_bss_0->unk_24, (38.0f), v13, v13, (FontDrawPacket *)&loc_8);
    if ((s32)p_lbl_14_bss_0->unk_24 == 396 && (s32)p_lbl_14_bss_0->unk_28 == 190) {
    v16 = (12.0);
    v17 = (1.0f);
    v18 = (f32)(v16 - (f64)(s32)p_lbl_14_bss_0->unk_34);
    v18 /= v16;
    if (v18 > v17) {
    v18 = v17;
    }
    loc_8.alpha = v18;
    loc_8.x = (99.0f);
    loc_8.y = (96.0f);
    v19 = (30.0f);
    fn_1_50164(v19, v19, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (99.0f);
    loc_8.y = (140.0f);
    v21 = (30.0f);
    fn_1_50164(v21, v21, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (99.0f);
    loc_8.y = (178.0f);
    v23 = (30.0f);
    fn_1_50164(v23, v23, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (99.0f);
    loc_8.y = (216.0f);
    v25 = (30.0f);
    fn_1_50164(v25, v25, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (99.0f);
    loc_8.y = (254.0f);
    v27 = (30.0f);
    fn_1_50164(v27, v27, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (99.0f);
    loc_8.y = (292.0f);
    v29 = (30.0f);
    fn_1_50164(v29, v29, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (99.0f);
    loc_8.y = (336.0f);
    v31 = (30.0f);
    fn_1_50164(v31, v31, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (99.0f);
    loc_8.y = (380.0f);
    v33 = (30.0f);
    fn_1_50164(v33, v33, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (541.0f);
    loc_8.y = (96.0f);
    v35 = (30.0f);
    fn_1_50164(v35, v35, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (541.0f);
    loc_8.y = (140.0f);
    v37 = (30.0f);
    fn_1_50164(v37, v37, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (541.0f);
    loc_8.y = (178.0f);
    v39 = (30.0f);
    fn_1_50164(v39, v39, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (541.0f);
    loc_8.y = (216.0f);
    v41 = (30.0f);
    fn_1_50164(v41, v41, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (541.0f);
    loc_8.y = (254.0f);
    v43 = (30.0f);
    fn_1_50164(v43, v43, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (541.0f);
    loc_8.y = (292.0f);
    v45 = (30.0f);
    fn_1_50164(v45, v45, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    loc_8.x = (575.0f);
    loc_8.y = (336.0f);
    v47 = (8.0f);
    fn_1_50164((98.0f), (42.0f), v47, v47, (FontDrawPacket *)&loc_8);
    loc_8.x = (541.0f);
    loc_8.y = (380.0f);
    v49 = (30.0f);
    fn_1_50164(v49, v49, (8.0f), (8.0f), (FontDrawPacket *)&loc_8);
    p_lbl_14_bss_0->unk_34--;
    }
    if ((s32)p_lbl_14_bss_0->unk_0 < 0) {
    lbl_1_bss_96A = 173;
    }
}
/* fzgx:end fn_14_380 */

/* fzgx:begin fn_14_900 */
// fn_14_900: empty in retail (single blr).
void fn_14_900(void) {
}
/* fzgx:end fn_14_900 */

/* fzgx:begin fn_14_258C */
// fn_14_258C: empty in retail (single blr).
void fn_14_258C(void) {
}
/* fzgx:end fn_14_258C */

/* fzgx:begin fn_14_2AFC */
struct PilotPoint {
    s16 unk0;
    u8 pad_2[0x35E];
    s16 unk360;
    u8 pad_362[0x35E];
    s16 unk6C0;
    u8 pad_6C2[0x35E];
};

extern s16 fn_14_32DC(s16 *);
extern s16 fn_14_3384(s16 *);
extern struct PilotPoint * lbl_14_bss_8340;
extern u32 fn_14_3334(s16 *);
extern u32 fn_14_33DC(s16 *);
extern u32 fn_14_342C(void);
extern u32 fn_14_34A8(void);
extern u32 fn_14_DC2C(void);
extern u8 * fn_1_36AD0(void);
extern void * fn_14_316C(void *, void *, void *);
extern void * fn_14_3230(void *, void *, void *);

void fn_14_2AFC(void) {
    struct PilotPoint *v0;
    s32 v5;
    s16 loc_10[6];
    s16 loc_C[2];
    s16 loc_A;
    s16 loc_8;
    u8 * t9;
    fn_14_316C((void *)loc_C, (void *)&loc_A, (void *)&loc_8);
    v0 = lbl_14_bss_8340;
    loc_C[0] = v0[loc_C[0]].unk0;
    loc_A = v0[loc_A].unk360;
    loc_8 = v0[loc_8].unk6C0;
    fn_14_342C();
    fn_14_3230((void *)loc_C, (void *)&loc_A, (void *)&loc_8);
    if (loc_C[0] != 15) {
        loc_C[0] = lbl_14_bss_8340[loc_C[0]].unk0;
    }
    if (loc_A != 15) {
        loc_A = lbl_14_bss_8340[loc_A].unk360;
    }
    if (loc_8 != 15) {
        loc_8 = lbl_14_bss_8340[loc_8].unk6C0;
    }
    fn_14_34A8();
    loc_10[0] = 75;
    loc_10[1] = 75;
    loc_10[2] = 75;
    fn_14_32DC(loc_10);
    loc_10[0] = 75;
    loc_10[1] = 75;
    loc_10[2] = 75;
    loc_10[3] = 75;
    loc_10[4] = 75;
    loc_10[5] = 75;
    fn_14_3334(loc_10);
    loc_10[0] = 41;
    fn_14_3384(loc_10);
    loc_10[0] = 41;
    fn_14_33DC(loc_10);
    v5 = (fn_14_DC2C() & 0xFF) * (0x10000 - 32320);
    t9 = (u8 *)(fn_1_36AD0());
    *(u32 *)((u8 *)t9 + v5) = (*(u32 *)((u8 *)t9 + v5) | 0xC0000000); /* fzgx-allow: A1 bit-set mask, not an address */
}
/* fzgx:end fn_14_2AFC */

/* fzgx:begin fn_14_315C */
extern struct fn_14_315C_lbl_14_bss_110 lbl_14_bss_110;

struct fn_14_315C_lbl_14_bss_110 {
    u8 pad_0[0x4C];
    u32 unk_4C;
};

void fn_14_315C(u32 arg0) {
    lbl_14_bss_110.unk_4C = arg0;
}
/* fzgx:end fn_14_315C */

/* fzgx:begin fn_14_316C */
struct fn_14_316C_Arg0 {
    u16 unk_0;
};
struct fn_14_316C_Arg1 {
    u16 unk_0;
};
struct fn_14_316C_Arg2 {
    u16 unk_0;
};
struct fn_14_316C_Ent {
    u32 raw[2];
};

extern struct fn_14_316C_Ent lbl_14_bss_110[10];
extern s16 lbl_14_bss_160[16];

#pragma opt_common_subs off
void fn_14_316C(struct fn_14_316C_Arg0 *arg0, struct fn_14_316C_Arg1 *arg1, struct fn_14_316C_Arg2 *arg2) {
    s16 v8;
    s16 v5;
    s32 v7;
    s16 t;
    u32 flags;
    s16 i;
    s32 v1;
    s16 v0;

    v1 = 0;
    v0 = ((s16 *)lbl_14_bss_110)[2];
    i = 0;
    arg2->unk_0 = 0;
    arg1->unk_0 = 0;
    arg0->unk_0 = 0;

    while ((u32)i < 8) {
        flags = ((u32 *)&lbl_14_bss_110[i])[3];
        if ((flags & 0x8) != 0) {
            if ((flags & 0x40) != 0 || i == v0) {
                t = v1;
                v7 = t / lbl_14_bss_160[0];
                v8 = v7;
                v5 = t % lbl_14_bss_160[0] + 1;
                switch (v8) {
                case 0:
                    arg0->unk_0 = v5;
                    break;
                case 1:
                    arg1->unk_0 = v5;
                    break;
                case 2:
                    arg2->unk_0 = v5;
                    break;
                }
            }
            v1++;
        }
        i++;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_14_316C */

/* fzgx:begin fn_14_3230 */
struct PilotPointEntry {
    u32 raw[2];
};

extern struct PilotPointEntry lbl_14_bss_110[10];
extern s16 lbl_14_bss_160[16];

void fn_14_3230(u16 *arg0, u16 *arg1, u16 *arg2) {
    s16 count;
    s16 index;

    index = 0;
    count = 0;

    *arg2 = 15;
    *arg1 = 15;
    *arg0 = 15;

    while ((u32)(s16)count < 8) {
        if ((((u32 *)&lbl_14_bss_110[count])[3] & 0x8) &&
            (((u32 *)&lbl_14_bss_110[count])[3] & 0x40)) {
            s16 quotient = index / lbl_14_bss_160[0];
            switch (quotient) {
            case 0:
                *arg0 = 0;
                break;
            case 1:
                *arg1 = 0;
                break;
            case 2:
                *arg2 = 0;
                break;
            }
        }
        index++, count++;
    }
}
/* fzgx:end fn_14_3230 */

/* fzgx:begin fn_14_32DC */
struct PilotPointEntry {
    u32 raw[2];
};

extern struct PilotPointEntry lbl_14_bss_110[10];

s16 fn_14_32DC(s16 *out) {
    s16 i;
    s16 count;

    count = 0;
    i = 0;
    while ((u32)(s16)i < 8) {
        if ((((u32 *)&lbl_14_bss_110[i])[3] & 0x8) &&
            (((u32 *)&lbl_14_bss_110[i])[3] & 0x40)) {
            out[(s16)count] = ((s16 *)&lbl_14_bss_110[i])[4];
            count++;
        }
        i++;
    }
    return count;
}
/* fzgx:end fn_14_32DC */

/* fzgx:begin fn_14_3334 */
extern u32 lbl_14_bss_110[20];

s16 fn_14_3334(s16 *out) {
    s16 i;
    s16 count;
    count = 0;
    i = 0;

    while ((u32)i < 8) {
        if (((u32 *)&lbl_14_bss_110[i * 2])[3] & 0x8) {
            out[count++] = ((s16 *)&lbl_14_bss_110[i * 2])[4];
        }
        i++;
    }

    return count;
}
/* fzgx:end fn_14_3334 */

/* fzgx:begin fn_14_3384 */
extern u32 lbl_14_bss_110[20];

s16 fn_14_3384(s16 *out) {
    s16 i;
    s16 count;
    u32 flags;
    count = 0;
    i = 0;

    while ((u32)i < 8) {
        flags = ((u32 *)&lbl_14_bss_110[i * 2])[3];
        if ((flags & 0x10) && (flags & 0x40)) {
            out[count++] = ((s16 *)&lbl_14_bss_110[i * 2])[4];
        }
        i++;
    }

    return count;
}
/* fzgx:end fn_14_3384 */

/* fzgx:begin fn_14_33DC */
extern u32 lbl_14_bss_110[20];

s16 fn_14_33DC(s16 *out) {
    s16 i;
    s16 count;
    count = 0;
    i = 0;

    while ((u32)i < 8) {
        if (((u32 *)&lbl_14_bss_110[i * 2])[3] & 0x10) {
            out[count++] = ((s16 *)&lbl_14_bss_110[i * 2])[4];
        }
        i++;
    }

    return count;
}
/* fzgx:end fn_14_33DC */

/* fzgx:begin fn_14_342C */
extern u32 lbl_14_bss_110[20];
extern u32 lbl_14_bss_8350;
extern f32 lbl_14_bss_8354[936];

u32 fn_14_342C(void) {
    u32 result;
    u32 flags;
    s16 i;
    s16 count;
    s16 target;

    target = ((s16 *)&lbl_14_bss_110)[2];
    result = (u32)&lbl_14_bss_8354;
    count = 0;

    for (i = 0; (u32)i < 8; i++) {
        flags = ((u32 *)&lbl_14_bss_110[i * 2])[3];
        if (flags & 0x10) {
            if ((flags & 0x40) || (i == target)) {
                result = lbl_14_bss_8350 + count * 0x4E0;
                break;
            }
            count++;
        }
    }

    return result;
}
/* fzgx:end fn_14_342C */

/* fzgx:begin fn_14_34A8 */
extern u32 lbl_14_bss_110[20];
extern u32 lbl_14_bss_8350;
extern f32 lbl_14_bss_8354[936];

u32 fn_14_34A8(void) {
    u32 result;
    u32 flags;
    s16 i;

    result = lbl_14_bss_8350;
    i = 0;
    while ((u32)i < 8) {
        flags = ((u32 *)&lbl_14_bss_110[i * 2])[3];
        if ((flags & 0x10) && (flags & 0x40)) {
            result = (u32)&lbl_14_bss_8354;
            break;
        }
        i++;
    }
    return result;
}
/* fzgx:end fn_14_34A8 */

/* fzgx:begin fn_14_3AE8 */
#include "rel/pilotpoint/pilotpoint.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 167.0f;
    s = 38.0f;
    s = 90.0f;
    s = 320.0f;
    s = 216.0f;
    s = 8.0f;
    s = 96.0f;
    s = 336.0f;
    s = 380.0f;
    d = 12.0;
    s = 1.0f;
    s = 99.0f;
    s = 30.0f;
    s = 140.0f;
    s = 178.0f;
    s = 254.0f;
    s = 292.0f;
    s = 541.0f;
    s = 575.0f;
    s = 98.0f;
    s = 42.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 60.0;
    d = 25.0;
    d = 29.0;
}
static const u32 fzgx_pool_table4[10] = {0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFF8080FF, 0xA0FF00FF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 396.0f;
    s = 190.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    d = 18.0;
    s = 136.0f;
    s = 0.550000011920929f;
    s = 108.0f;
    s = 300.0f;
    s = 80.0f;
    s = 400.0f;
    s = 388.0f;
    s = 97.0f;
    s = 0.05000000074505806f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 30.0;
    d = 2.0;
    d = 4503599627370496.0;
    s = 193.32176208496094f;
}
static const u32 fzgx_pool_table10[1] = {0x53454C00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 20.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table13[1] = {0x40AD2D2D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table14[1] = {0xC04FCFD0};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table15[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table16[1] = {0x40A00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table17[1] = {0xC0400000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table23[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
    s = 182.04444885253906f;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Rp_v3;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Rp_vec3;

typedef struct {
    u8 pad_0[0x30];
    f32 unk_30;
    u8 pad_34[0xDC];
    f64 unk_110;
    u8 pad_118[0x10];
    u32 unk_128;
    u32 unk_12C;
    u32 unk_130;
    u32 unk_134;
    u32 unk_138;
    u32 unk_13C;
    u32 unk_140;
    u32 unk_144;
    u32 unk_148;
    u32 unk_14C;
    u32 unk_150;
    u32 unk_154;
    f32 unk_158;
    f32 unk_15C;
} Rp_cfg;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
} Rp_data;

typedef struct {
    s16 unk_0;
} Rp_arg;

extern Rp_data lbl_1_data_1E5C0;
extern u32 lbl_801A66A0;
extern u32 lbl_14_bss_8344;

extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_8006F038(Rp_v3 *, Rp_v3 *, s16);
extern void lbl_8006DCDC(void);
extern void lbl_8006DCA4(void);
extern void fn_1_F7870(Rp_data *);
extern void fn_1_151BDC(u8 *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void fn_1_14DE80(void *, void *, void *, s16, f32);
extern void fn_1_14E054(void *, void *, s16, f32);
extern void fn_1_14E198(void *, void *, s16, f32);

s32 fn_14_3AE8(Rp_arg *arg0) {
    Rp_cfg *cfg;
    Rp_v3 *va;
    s16 idx;
    s16 qq;
    Rp_v3 *vb;
    Rp_data *dt;
    Rp_data loc;
    Rp_vec3 t34;
    Rp_vec3 t28;
    Rp_vec3 t1c;
    Rp_vec3 t10;
    u32 zc;
    u32 z8;
    s32 v;
    s32 q;
    s32 rem;
    f32 sc;
    f32 m0;
    f32 m1;
    u32 ang;

    v = arg0->unk_0;
    q = v / lbl_14_bss_160.unk_0;
    qq = (s16)q;
    rem = v - q * lbl_14_bss_160.unk_0;
    idx = (s16)(rem + 1);

    va = (Rp_v3 *)&lbl_14_bss_92C4.unk_4;
    fn_80008BEC(va, 0, 12);
    vb = (Rp_v3 *)&lbl_14_bss_92C4.unk_10;
    fn_80008BEC(vb, 0, 12);

    if (qq == 0) {
        t28.x = fzgx_pool_table12[0];
        t28.y = fzgx_pool_table13[0];
        t28.z = fzgx_pool_table14[0];
        fn_80008BA8(va, &t28, 12);
    } else {
        t1c.x = fzgx_pool_table15[0];
        t1c.y = fzgx_pool_table16[0];
        t1c.z = fzgx_pool_table17[0];
        fn_80008BA8(va, &t1c, 12);
    }

    t10.x = fzgx_pool_table18[0];
    t10.y = fzgx_pool_table19[0];
    t10.z = fzgx_pool_table20[0];
    fn_80008BA8(vb, &t10, 12);
    fn_8006F038(va, vb, 0);
    lbl_8006DCDC();

    dt = &lbl_1_data_1E5C0;
    sc = 0.699999988079071f;
    loc = *dt;
    m0 = dt->unk_C * sc;
    m1 = dt->unk_10 * sc;
    loc.unk_C = m0 - m1;
    loc.unk_10 = m0 + m1;
    loc.unk_14 = dt->unk_14;
    fn_1_F7870(&loc);
    fn_1_151BDC((u8 *)&lbl_14_bss_180);
    lbl_8006DCA4();
    mathutil_mtxA_rotate_x(0x2000);
    ang = lbl_801A66A0 % 360;
    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * (f32)ang));

    zc = 0;
    z8 = 0;
    t34.x = fzgx_pool_table21[0];
    t34.y = fzgx_pool_table22[0];
    t34.z = fzgx_pool_table23[0];

    switch (qq) {
    case 0:
        fn_1_14DE80((void *)(lbl_14_bss_8344 + idx * 0xA20), &zc, &z8, lbl_14_data_2F36.unk_0, 1.0f);
        break;
    case 1:
        fn_1_14E054((void *)(lbl_14_bss_8344 + idx * 0xA20), &t34, lbl_14_data_2F36.unk_0, 1.0f);
        break;
    case 2:
        fn_1_14E198((void *)(lbl_14_bss_8344 + idx * 0xA20), &t34, lbl_14_data_2F36.unk_0, 1.0f);
        break;
    }

    return 0;
}
/* fzgx:end fn_14_3AE8 */

/* fzgx:begin fn_14_3DF0 */
#include "rel/pilotpoint/pilotpoint.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 167.0f;
    s = 38.0f;
    s = 90.0f;
    s = 320.0f;
    s = 216.0f;
    s = 8.0f;
    s = 96.0f;
    s = 336.0f;
    s = 380.0f;
    d = 12.0;
    s = 1.0f;
    s = 99.0f;
    s = 30.0f;
    s = 140.0f;
    s = 178.0f;
    s = 254.0f;
    s = 292.0f;
    s = 541.0f;
    s = 575.0f;
    s = 98.0f;
    s = 42.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 60.0;
    d = 25.0;
    d = 29.0;
}
static const u32 fzgx_pool_table4[10] = {0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFF8080FF, 0xA0FF00FF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 396.0f;
    s = 190.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    d = 18.0;
    s = 136.0f;
    s = 0.550000011920929f;
    s = 108.0f;
    s = 300.0f;
    s = 80.0f;
    s = 400.0f;
    s = 388.0f;
    s = 97.0f;
    s = 0.05000000074505806f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 30.0;
    d = 2.0;
    d = 4503599627370496.0;
    s = 193.32176208496094f;
}
static const u32 fzgx_pool_table10[1] = {0x53454C00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 20.0f;
}
static const u32 fzgx_pool_table12[12] = {0x00000000, 0x40AD2D2D, 0xC04FCFD0, 0x00000000, 0x40A00000, 0xC0400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
    s = 182.04444885253906f;
    d = 0.55;
    s = 0.8299999833106995f;
    s = 0.06666667014360428f;
}
#pragma section code_type ".text"

typedef struct { s16 unk_0; } Arg_fn_14_3DF0;
typedef struct {
    f32 unk_0;
    u8 pad_4[0x154];
    f32 unk_158;
    u8 pad_15C[4];
    f64 unk_160;
    f32 unk_168;
    f32 unk_16C;
} Obj_14_3DF0_rodata;
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    f32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
} Obj_14_3DF0_data;
extern Obj_14_3DF0_rodata lbl_14_rodata_0;
extern Obj_14_3DF0_data lbl_1_data_1E5C0;
extern s16 fn_1_12C710(s32);
extern s16 fn_1_12CB04(s16);
extern f32 lbl_8006D188(u32);
extern void fn_8006F038(void *, void *, s16);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(void *);
extern u32 lbl_8006DCA4(void);
extern void fn_1_9250C(void *);

#pragma opt_loop_invariants off
typedef struct lbl_14_bss_92C4_t {
    u8 fzgx_byte_0;
    u8 pad_1[0x3];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x8];
} lbl_14_bss_92C4_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_14_bss_92C4_t fzgx_obj_lbl_14_bss_92C4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_14_bss_92C4;
}
#pragma section code_type ".text"

s32 fn_14_3DF0(Arg_fn_14_3DF0 *arg0) {
    const Obj_14_3DF0_rodata *R = &lbl_14_rodata_0;
    Obj_14_bss_8350_Target *obj;
    Obj_14_bss_8350_Target *o;
    Obj_14_3DF0_data loc;
    s16 t0;
    s32 i;
    f32 sc;
    f32 p;
    f32 q;
    f32 z;

    obj = (Obj_14_bss_8350_Target *)((u8 *)lbl_14_bss_8350 + arg0->unk_0 * 0xEA0);
    t0 = fn_1_12C710(obj->unk_88);
    fzgx_obj_lbl_14_bss_92C4.unk_4 = (f32)((0.55000000000000004) * -lbl_8006D188(0xEEE));
    fzgx_obj_lbl_14_bss_92C4.unk_8 = (0.829999983f);
    {
        f64 value = (0.55000000000000004) * -lbl_8006D188(0x4EEE);
        f32 *component = &fzgx_obj_lbl_14_bss_92C4.unk_10;
        *component = 0.0f;
        fzgx_obj_lbl_14_bss_92C4.unk_C = (f32)value;
        if (t0 == 10)
            *component = 0.0666666701f;
    }
    fzgx_obj_lbl_14_bss_92C4.unk_14 = (0.829999983f);
    fzgx_obj_lbl_14_bss_92C4.unk_18 = (0.0f);
    fn_8006F038(&fzgx_obj_lbl_14_bss_92C4.unk_4, &fzgx_obj_lbl_14_bss_92C4.unk_10, 0);
    lbl_8006DCDC();
    sc = (0.699999988f);
    loc = lbl_1_data_1E5C0;
    p = *(f32 *)&lbl_1_data_1E5C0.unk_C * sc;
    q = *(f32 *)&lbl_1_data_1E5C0.unk_10 * sc;
    *(f32 *)&loc.unk_C = p - q;
    *(f32 *)&loc.unk_10 = p + q;
    loc.unk_14 = lbl_1_data_1E5C0.unk_14;
    fn_1_F7870(&loc);
    lbl_8006DCA4();
    z = (0.0f);
    (void) z;  /* fzgx: keeps the web at its definition */
    obj->unk_A8 = z;
    obj->unk_AC = z;
    obj->unk_B0 = z;
    fn_1_9250C(obj);
    z = (0.0f);
    {
        s32 offset;
        {
    s32 fzgx_loop_i_6660;
    fzgx_loop_i_6660 = 0;
    offset = 0;
for (; (s16)fzgx_loop_i_6660 < (s16)fn_1_12CB04(t0); fzgx_loop_i_6660++) {
            obj = (Obj_14_bss_8350_Target *)((u8 *)obj + offset + 0x4E0);
            obj->unk_A8 = z;
            obj->unk_AC = z;
            obj->unk_B0 = z;
            fn_1_9250C(obj);
            offset += 0x4E0;
        }
    i = fzgx_loop_i_6660;
}
    }
    return 0;
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_14_3DF0 */

/* fzgx:begin fn_14_4008 */
#include "rel/pilotpoint/pilotpoint.h"

typedef struct fn_14_4008_Vec {
    f32 x;
    f32 y;
    f32 z;
} fn_14_4008_Vec;

typedef struct fn_14_4008_Pos {
    u32 unk_0;
    fn_14_4008_Vec a;
    fn_14_4008_Vec b;
} fn_14_4008_Pos;

typedef struct fn_14_4008_View {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u32 unk_18[7];
} fn_14_4008_View;

extern fn_14_4008_View lbl_1_data_1E5C0;
extern u32 lbl_801A66A0;

extern u32 fn_14_DC2C(void);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_8006F038(fn_14_4008_Vec *, fn_14_4008_Vec *, s16);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(fn_14_4008_View *);
extern void lbl_8006DCA4(void);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern s32 fn_1_128B00(s16);
extern s16 fn_1_14F270(s32, s32, u32);
extern u8 *fn_1_36AD0(void);
extern void fn_1_151BDC(void *);
extern void fn_1_14DE80(void *, s32 *, s32 *, s16, f32);
extern void lbl_8006DAEC(void);
extern void fn_1_14E054(void *, s32, s16, f32);
extern void lbl_8006DBE4(void);
extern void fn_1_14E198(void *, s32, s16, f32);
extern void lbl_8006DC20(void);

/* Literal-pool primer: lays out the TU's shared pool up to this function's entries. */
static const u32 fzgx_pool_table_0[12] = {
    0x00000000, 0x43270000, 0x42180000, 0x42B40000, 0x43A00000, 0x43580000,
    0x41000000, 0x42C00000, 0x43A80000, 0x43BE0000, 0x40280000, 0x00000000,
};
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") u32 fzgx_pool_0(void) { return fzgx_pool_table_0[0]; }
__declspec(section ".fzgxpool") f32 fzgx_pool_1(void) { return 1.0f; }
static const u32 fzgx_pool_table_34[55] = {
    0x42C60000, 0x41F00000, 0x430C0000,
    0x43320000, 0x437E0000, 0x43920000, 0x44074000,
    0x440FC000, 0x42C40000, 0x42280000, 0x00000000,
    0x43300000, 0x80000000, 0x404E0000, 0x00000000,
    0x40390000, 0x00000000, 0x403D0000, 0x00000000,
    0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00,
    0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFF8080FF,
    0xA0FF00FF, 0xFFFFFF00, 0x43C60000, 0x433E0000,
    0x3F000000, 0x00000000, 0x00000000, 0x00000000,
    0x3FF00000, 0x00000000, 0x40320000, 0x00000000,
    0x43080000, 0x3F0CCCCD, 0x42D80000, 0x43960000,
    0x42A00000, 0x43C80000, 0x43C20000, 0x42C20000,
    0x3D4CCCCD, 0x00000000, 0x40568000, 0x00000000,
    0x403E0000, 0x00000000, 0x40000000, 0x00000000,
};
__declspec(section ".fzgxpool") u32 fzgx_pool_2(void) { return fzgx_pool_table_34[0]; }
__declspec(section ".fzgxpool") f32 fzgx_pool_3(u32 x) { return (f32)x; }
static const u32 fzgx_pool_table_118[16] = {
    0x4341525F, 0x53454C00,
    0x41200000, 0x41A00000, 0x00000000, 0x40AD2D2D,
    0xC04FCFD0, 0x00000000, 0x40A00000, 0xC0400000, /* fzgx-allow: A1 float bits, not addresses */
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000,
};
__declspec(section ".fzgxpool") u32 fzgx_pool_4(void) { return fzgx_pool_table_118[0]; }
__declspec(section ".fzgxpool") f32 fzgx_pool_5(void) { return 0.7f; }
__declspec(section ".fzgxpool") f32 fzgx_pool_7(void) { return 182.04445f; }
static const u32 fzgx_pool_table_160[4] = {
    0x3FE19999, 0x9999999A, 0x3F547AE1, 0x3D888889,
};

__declspec(section ".fzgxpool") u32 fzgx_pool_6(void) { return fzgx_pool_table_160[0]; }
#pragma section code_type

Obj_14_bss_92C4 lbl_14_bss_92C4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; /* fzgx-allow: S2 layout primer sink: preserves owned BSS ordering */
    s = lbl_14_bss_92C4.pad_0[0];
}
#pragma section code_type ".text"

typedef struct fn_14_4008_Part {
    s16 id;
    u8 pad_2[0x35E];
} fn_14_4008_Part;

s32 fn_14_4008(void) {
    struct { fn_14_4008_View *value; } camera;
    fn_14_4008_View view;
    f32 y;
    f32 x;
    f32 scale;
    s32 sel0;
    s32 sel1;
    struct { s16 value; } selected;
    struct { s16 value; } i;
    struct { s16 value; } count;
    s16 a;
    s16 b;
    s16 c;
    s16 q;
    s16 r;
    struct { s32 value; } index;

    fn_80008BEC(&lbl_14_bss_92C4.unk_4, 0, sizeof(fn_14_4008_Vec));
    fn_80008BEC(&lbl_14_bss_92C4.unk_10, 0, sizeof(fn_14_4008_Vec));
    {
        fn_14_4008_Vec eye = { 0.0f, 10.0f, -5.0f };
        fn_80008BA8(&lbl_14_bss_92C4.unk_4, &eye, sizeof(fn_14_4008_Vec));
    }
    {
        fn_14_4008_Vec at = { 0.0f, 0.0f, 0.0f };
        fn_80008BA8(&lbl_14_bss_92C4.unk_10, &at, sizeof(fn_14_4008_Vec));
    }
    fn_8006F038((void *)&lbl_14_bss_92C4.unk_4, (void *)&lbl_14_bss_92C4.unk_10, 0);
    lbl_8006DCDC();

    camera.value = &lbl_1_data_1E5C0;
    scale = 0.7f;
    x = camera.value->unk_C * scale;
    y = camera.value->unk_10 * scale;
    view = *camera.value;
    view.unk_C = x - y;
    view.unk_10 = x + y;
    view.unk_14 = camera.value->unk_14;
    fn_1_F7870(&view);

    lbl_8006DCA4();
    mathutil_mtxA_rotate_x(0x2000);
    mathutil_mtxA_rotate_y((s16)(182.04445f * (f32)(lbl_801A66A0 % 360)));

    sel0 = 0;
    sel1 = 0;
    selected.value = lbl_14_bss_110.unk_4;
    count.value = 0;
    c = 0;
    b = 0;
    a = 0;
    for (i.value = count.value; i.value < 8U; i.value++) {
        if (((Obj_14_bss_110 *)((u8 *)&lbl_14_bss_110 + i.value * 8))->unk_C & 8) {
            if ((((Obj_14_bss_110 *)((u8 *)&lbl_14_bss_110 + i.value * 8))->unk_C & 0x40) || i.value == selected.value) {
                q = count.value / lbl_14_bss_160.unk_0;
                r = count.value % lbl_14_bss_160.unk_0 + 1;
                switch (q) {
                case 0:
                    a = r;
                    break;
                case 1:
                    b = r;
                    break;
                case 2:
                    c = r;
                    break;
                }
            }
            count.value++;
        }
    }

    if (*(s16 *)((u8 *)lbl_14_bss_8340 + (index.value = a * sizeof(*lbl_14_bss_8340))) ==
        fn_1_14F270(fn_1_128B00(0), 0, 0x80000000)) {
        fn_1_151BDC(fn_1_36AD0() + (fn_14_DC2C() & 0xFF) * 0x81C0);
    } else {
        fn_1_151BDC(lbl_14_bss_180);
    }
    fn_1_14DE80((u8 *)lbl_14_bss_8340 + index.value, &sel0, &sel1, lbl_14_data_2F36.unk_0, 1.0f);
    lbl_8006DAEC();

    if (((fn_14_4008_Part (*)[3])lbl_14_bss_8340)[b][1].id ==
        fn_1_14F270(fn_1_128B00(1), 1, 0x80000000)) {
        fn_1_151BDC(fn_1_36AD0() + (fn_14_DC2C() & 0xFF) * 0x81C0);
    } else {
        fn_1_151BDC(lbl_14_bss_180);
    }
    fn_1_14E054(&((fn_14_4008_Part (*)[3])lbl_14_bss_8340)[b], sel0, lbl_14_data_2F36.unk_0, 1.0f);
    lbl_8006DBE4();

    if (((fn_14_4008_Part (*)[3])lbl_14_bss_8340)[c][2].id ==
        fn_1_14F270(fn_1_128B00(2), 2, 0x80000000)) {
        fn_1_151BDC(fn_1_36AD0() + (fn_14_DC2C() & 0xFF) * 0x81C0);
    } else {
        fn_1_151BDC(lbl_14_bss_180);
    }
    fn_1_14E198(&((fn_14_4008_Part (*)[3])lbl_14_bss_8340)[c], sel1, lbl_14_data_2F36.unk_0, 1.0f);
    lbl_8006DC20();
    return 0;
}
/* fzgx:end fn_14_4008 */

/* fzgx:begin fn_14_600C */
extern struct fn_14_600C_lbl_14_bss_92E8 lbl_14_bss_92E8;
extern u32 fn_80074188(u32, u32, u32, u32);

struct fn_14_600C_lbl_14_bss_92E8 {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
};

void fn_14_600C(void) {
    fn_80074188(lbl_14_bss_92E8.unk_0, lbl_14_bss_92E8.unk_2, lbl_14_bss_92E8.unk_4, lbl_14_bss_92E8.unk_6);
}
/* fzgx:end fn_14_600C */

/* fzgx:begin fn_14_6044 */
#include "font.h"
#include "rel/pilotpoint/pilotpoint.h"

/* Shared literal pool primer: reproduces retail lbl_14_rodata_0 layout up to 0x1EC. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 167.0f;
    s = 38.0f;
    s = 90.0f;
    s = 320.0f;
    s = 216.0f;
    s = 8.0f;
    s = 96.0f;
    s = 336.0f;
    s = 380.0f;
    d = 12.0;
    s = 1.0f;
    s = 99.0f;
    s = 30.0f;
    s = 140.0f;
    s = 178.0f;
    s = 254.0f;
    s = 292.0f;
    s = 541.0f;
    s = 575.0f;
    s = 98.0f;
    s = 42.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 60.0;
    d = 25.0;
    d = 29.0;
}
static const unsigned long fzgx_pool_table4[10] = {0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFF8080FF, 0xA0FF00FF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 396.0f;
    s = 190.0f;
    s = 0.5f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    d = 18.0;
    s = 136.0f;
    s = 0.550000011920929f;
    s = 108.0f;
    s = 300.0f;
    s = 80.0f;
    s = 400.0f;
    s = 388.0f;
    s = 97.0f;
    s = 0.05000000074505806f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 30.0;
    d = 2.0;
    d = 4503599627370496.0;
    s = 193.32176208496094f;
}
static const unsigned long fzgx_pool_table10[1] = {0x53454C00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 20.0f;
}
static const unsigned long fzgx_pool_table12[12] = {0x00000000, 0x40AD2D2D, 0xC04FCFD0, 0x00000000, 0x40A00000, 0xC0400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
    s = 182.04444885253906f;
    d = 0.55;
    s = 0.8299999833106995f;
    s = 0.06666667014360428f;
}
static const unsigned long fzgx_pool_table14[8] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF00FFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.625f;
}
static const unsigned long fzgx_pool_table16[9] = {0x00FF0000, 0xFFFFFF00, 0xFFFFFF00, 0x00FF0000, 0x00060007, 0x00080000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4583333432674408f;
    s = 0.6666666865348816f;
    s = 0.6169934868812561f;
    s = 0.4166666567325592f;
    s = 0.8333333134651184f;
    s = 0.48627451062202454f;
}
#pragma section code_type ".text"

typedef struct {
    u8 r, g, b, a;
} PPColor;

extern const FontDrawPacket lbl_1_rodata_26F8;
extern u8 *lbl_14_bss_8348;
extern u8 *lbl_14_bss_834C;
extern void fn_14_600C(void);
extern s32 fn_14_3AE8(s16 *);
extern s32 fn_14_3DF0(s16 *);
extern void fn_14_46D4(s16, s16, s32, s32);
extern u16 fn_1_A5DB0(void);
extern s32 fn_1_14F344(s16);
extern void fn_1_8D3F8(void *, FontDrawPacket *, s32 (*)(s16 *), s16 *);

/* A pilot entry is highlighted unless its time limit (15000/20000 frames) is exceeded. */
static inline s32 fn_14_6044_visible(u32 flags) {
    s16 t;
    if (flags & 4) {
        return 1;
    }
    if (flags & 8) {
        t = 15000;
    } else if (flags & 0x10) {
        t = 20000;
    } else {
        t = -1;
    }
    if (t > 99900) {
        return 0;
    }
    return 1;
}

void fn_14_6044(s16 arg0, s16 arg1) {
    s16 cnt0;
    s16 cnt1;
    f32 scale;
    FontDrawPacket spr;
    s16 i;
    f32 savedY;
    u32 flags;

    cnt0 = 0;
    cnt1 = 0;
    scale = (f32)fn_1_A5DB0() / 480.0f;
    lbl_14_bss_92E8.unk_0 = arg0 + 0x202;
    lbl_14_bss_92E8.unk_2 = (f32)(arg1 + 16) * scale;
    lbl_14_bss_92E8.unk_4 = 62;
    lbl_14_bss_92E8.unk_6 = 62.0f * scale;
    spr = lbl_1_rodata_26F8;
    spr.flags = 10;
    spr.y = arg1 + 0x31;
    for (i = 0; (u32)i < 8; i++) {
        spr.x = arg0 + 0x2e + (s32)((u32)i - 1) * 0x4e + ((s32)((u32)i - 1) / 2) * 10;
        spr.z = 50.0f;
        spr.scale_y = 1.0f;
        spr.scale_x = 1.0f;
        if (i == lbl_14_bss_110.unk_4) {
            spr.z -= spr.scale_y;
        }
        flags = *(u32 *)((u8 *)&lbl_14_bss_110 + i * 8 + 0xc);
        {
            PPColor white = {255, 255, 255, 255};
            *(PPColor *)spr.color = white;
        }
        if ((flags & 1) || !fn_14_6044_visible(flags)) {
            PPColor gray = {63, 63, 63, 63};
            *(PPColor *)spr.color = gray;
        }
        if (*(u32 *)((u8 *)&lbl_14_bss_110 + i * 8 + 0xc) & 8) {
            savedY = spr.y;
            if ((s16)fn_1_14F344(*(s16 *)((u8 *)&lbl_14_bss_110 + i * 8 + 8)) == 0) {
                spr.y += 5.0f;
            }
            if ((s16)fn_1_14F344(*(s16 *)((u8 *)&lbl_14_bss_110 + i * 8 + 8)) == 1) {
                spr.y += 7.0f;
            }
            fn_1_8D3F8(lbl_14_bss_8348 + cnt0 * 100, &spr, fn_14_3AE8, &cnt0);
            spr.y = savedY;
            cnt0++;
        }
        if (*(u32 *)((u8 *)&lbl_14_bss_110 + i * 8 + 0xc) & 0x10) {
            spr.x = arg0 + 0x221;
            spr.flags |= 0x4000000;
            spr.vertex_callback = (void (*)(FontDrawPacket *, FontVertex *))fn_14_600C;
            fn_1_8D3F8(lbl_14_bss_834C + cnt1 * 100, &spr, fn_14_3DF0, &cnt1);
            cnt1++;
        }
        if (i == lbl_14_bss_110.unk_4) {
            if (*(u32 *)((u8 *)&lbl_14_bss_110 + i * 8 + 0xc) & 4) {
                fn_14_46D4(arg0 + 0xa7, arg1 + 0x79, 1.0f + spr.z, 1);
            } else {
                fn_14_46D4(spr.x, spr.y, 1.0f + spr.z, 0);
            }
        }
    }
}
/* fzgx:end fn_14_6044 */

/* fzgx:begin fn_14_645C */
extern struct fn_14_645C_lbl_14_bss_92F0 lbl_14_bss_92F0;
extern u32 fn_80074188(u32, u32, u32, u32);

struct fn_14_645C_lbl_14_bss_92F0 {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
};

void fn_14_645C(void) {
    fn_80074188(lbl_14_bss_92F0.unk_0, lbl_14_bss_92F0.unk_2, lbl_14_bss_92F0.unk_4, lbl_14_bss_92F0.unk_6);
}
/* fzgx:end fn_14_645C */

/* fzgx:begin fn_14_7E04 */
extern struct fn_14_7E04_lbl_14_bss_20 lbl_14_bss_20;
extern struct fn_14_7E04_lbl_14_bss_92C0 lbl_14_bss_92C0;
extern struct fn_14_7E04_lbl_1_bss_6EAD0_T *lbl_1_bss_6EAD0;
extern u32 fn_14_2590(void);
extern u32 fn_14_2C80(void);
extern u32 fn_1_12F1E8(u32);
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_A1588(u32, u32);
extern u32 fn_1_A2D84(u32);
extern u32 lbl_14_bss_92BC;
extern u32 lbl_14_bss_92F8;
extern u32 lbl_14_data_2F48;
extern u32 lbl_14_data_3048;
extern void fn_14_7584(void);

struct fn_14_7E04_lbl_14_bss_20 {
    u32 unk_0;
};
struct fn_14_7E04_lbl_14_bss_92C0 {
    u32 unk_0;
};
struct fn_14_7E04_lbl_1_bss_6EAD0_T {
    u32 unk_0;
};

void fn_14_7E04(void) {
    u32 t4;
    fn_14_2590();
    fn_14_2C80();
    fn_1_12F1E8(2400);
    fn_1_435C(lbl_14_bss_20.unk_0);
    t4 = fn_1_3F8C((u32)&lbl_14_data_3048, (u32)fn_14_7584, 0, 8);
    lbl_14_data_2F48 = t4;
    lbl_14_bss_92F8 = -1;
    fn_1_A1588(lbl_1_bss_6EAD0->unk_0, 15);
    lbl_14_bss_92C0.unk_0 = 1;
    lbl_14_bss_92BC = 0;
    fn_1_A2D84((0xA9070000 + 10752));
}
/* fzgx:end fn_14_7E04 */

/* fzgx:begin fn_14_7EAC */
typedef struct {
    u32 unk_0;
    u32 unk_4;
} Sig_fn_1_B7F58_Result;

struct fn_14_7EAC_lbl_1_bss_8B3A0 {
    u8 pad_0[0x9E];
    u8 unk_9E;
};
struct fn_14_7EAC_lbl_1_bss_9F8 {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[0x4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[0x4];
    u16 unk_10;
    u16 unk_12;
};
struct fn_14_7EAC_lbl_14_bss_110 {
    u32 unk_0;
    s16 unk_4;
    u8 pad_6[0x2];
    s16 unk_8;
    u8 pad_A[0x2];
    u32 unk_C[15];
    u32 unk_48;
    u32 unk_4C;
};

extern struct fn_14_7EAC_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern struct fn_14_7EAC_lbl_1_bss_9F8 lbl_1_bss_9F8[4];
extern u16 lbl_1_bss_96A;
extern u32 lbl_1_bss_6EAB4;
extern s32 lbl_1_bss_7180C;
extern u32 lbl_801A66A0;
extern u32 lbl_801A66C0;
extern s32 lbl_14_bss_10C;
extern struct fn_14_7EAC_lbl_14_bss_110 lbl_14_bss_110;
extern u32 lbl_14_bss_92BC;
extern s32 lbl_14_bss_92F8;
extern s32 fn_1_4C10(void);
extern s32 fn_1_B7F58(Sig_fn_1_B7F58_Result *);
extern s32 fn_1_12F228(void);
extern void fn_1_12F1E8(s32);
extern s32 fn_14_34FC(void);
extern s32 fn_14_DF70(void);

void fn_14_7EAC(void) {
    s32 result;
    s32 t;
    s16 i;
    Sig_fn_1_B7F58_Result local;

    lbl_14_bss_92BC++;
    if (lbl_801A66C0 < 30) {
        result = 1;
    } else if (fn_1_4C10() != 0) {
        if (lbl_14_bss_10C == 0) {
            u16 flags = lbl_1_bss_9F8[lbl_1_bss_8B3A0.unk_9E].unk_8;

            if ((flags >> 8) & 1) {
                lbl_14_bss_10C = 1;
            }
        }
        result = 1;
    } else {
        struct fn_14_7EAC_lbl_14_bss_110 *p = &lbl_14_bss_110;

        if (p->unk_48 == -1) {
            t = 1;
        } else if (lbl_801A66A0 - p->unk_48 > p->unk_4C) {
            p->unk_48 = -1;
            t = 1;
        } else {
            t = 0;
        }
        if (t == 0) {
            result = 0;
        } else {
            result = 0;
        }
    }
    if (result == 0) {
        if (lbl_14_bss_92F8 != -1) {
            lbl_1_bss_96A = lbl_14_bss_92F8;
            lbl_14_bss_92F8 = -1;
        } else if ((s16)fn_14_34FC() != 0 || fn_1_12F228() != 0) {
            local.unk_4 = 0;
            local.unk_0 = 0;
            for (i = 0; i < 8u; i++) {
                if (lbl_14_bss_110.unk_C[i * 2] & 4) {
                    lbl_14_bss_110.unk_4 = i;
                    break;
                }
            }
            if (lbl_1_bss_7180C != 0 && fn_1_B7F58(&local) != 0) {
                lbl_14_bss_92F8 = 0xB0;
                lbl_1_bss_6EAB4 |= 0x2C;
            } else if ((fn_14_DF70() & 0xFF) == 0) {
                lbl_1_bss_96A = 0xB2;
            } else {
                lbl_1_bss_96A = 0xAF;
            }
            fn_1_12F1E8(0);
        }
    }
}
/* fzgx:end fn_14_7EAC */

/* fzgx:begin fn_14_82E4 */
#include "rel/pilotpoint/pilotpoint.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 167.0f;
    s = 38.0f;
    s = 90.0f;
    s = 320.0f;
    s = 216.0f;
    s = 8.0f;
    s = 96.0f;
    s = 336.0f;
    s = 380.0f;
    d = 12.0;
    s = 1.0f;
    s = 99.0f;
    s = 30.0f;
    s = 140.0f;
    s = 178.0f;
    s = 254.0f;
    s = 292.0f;
    s = 541.0f;
    s = 575.0f;
    s = 98.0f;
    s = 42.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 60.0;
    d = 25.0;
    d = 29.0;
}
static const u32 fzgx_pool_table4[10] = {0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFF8080FF, 0xA0FF00FF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 396.0f;
    s = 190.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    d = 18.0;
    s = 136.0f;
    s = 0.550000011920929f;
    s = 108.0f;
    s = 300.0f;
    s = 80.0f;
    s = 400.0f;
    s = 388.0f;
    s = 97.0f;
    s = 0.05000000074505806f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 30.0;
    d = 2.0;
    d = 4503599627370496.0;
    s = 193.32176208496094f;
}
static const u32 fzgx_pool_table10[1] = {0x53454C00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 20.0f;
}
static const u32 fzgx_pool_table12[12] = {0x00000000, 0x40AD2D2D, 0xC04FCFD0, 0x00000000, 0x40A00000, 0xC0400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
    s = 182.04444885253906f;
    d = 0.55;
    s = 0.8299999833106995f;
    s = 0.06666667014360428f;
}
static const u32 fzgx_pool_table14[8] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF00FFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.625f;
}
static const u32 fzgx_pool_table16[9] = {0x00FF0000, 0xFFFFFF00, 0xFFFFFF00, 0x00FF0000, 0x00060007, 0x00080000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4583333432674408f;
    s = 0.6666666865348816f;
    s = 0.6169934868812561f;
    s = 0.4166666567325592f;
    s = 0.8333333134651184f;
    s = 0.48627451062202454f;
}
static const u32 fzgx_pool_table18[2] = {0xFFFFFFFF, 0x3F3F3F3F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 62.0f;
    s = 50.0f;
    s = 5.0f;
    s = 7.0f;
}
static const u32 fzgx_pool_table20[2] = {0x00FF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.480392187833786f;
}
static const u32 fzgx_pool_table22[2] = {0xFF00FFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 314.0f;
    s = 84.0f;
    s = 321.0f;
    s = 356.0f;
    s = 0.75f;
    s = 51.0f;
    s = 0.30000001192092896f;
    s = 88.0f;
    s = 2.0f;
}
static const u32 fzgx_pool_table24[13] = {0xFFFF0000, 0xFF000000, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9215686321258545f;
    s = 0.4588235318660736f;
}
static const u32 fzgx_pool_table26[2] = {0xFF00FFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 492.0f;
    s = 332.0f;
    s = 40.0f;
    s = 322.0f;
    s = 41.0f;
    s = 238.0f;
    s = 156.0f;
    s = 1.2901960611343384f;
    s = 0.8313725590705872f;
    s = 240.0f;
    s = 0.009999999776482582f;
    s = 8.00100040435791f;
    s = 100.0f;
    s = 0.019999999552965164f;
    s = 9.999999747378752e-05f;
    s = 16.0f;
    s = 24.0f;
    s = 73.0f;
    s = 368.0f;
    s = 193.0f;
    s = 248.0f;
    s = 36.0f;
    s = 376.0f;
    s = 211.0f;
    s = 608.0f;
    s = 257.0f;
    s = 176.0f;
    s = 239.0f;
}
static const u32 fzgx_pool_table28[1] = {0x0000FA00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table29[1] = {0xFAFAFAFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const u32 *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table30[1] = {0x0000FA00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 120.0f;
    s = 0.4000000059604645f;
    s = 9.0f;
    s = 402.0f;
}
#pragma section code_type ".text"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_14_82E4_Color;

extern s32 lbl_801A66A0;
extern f32 lbl_8006D188(s32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s32);
extern void fn_1_49514(fn_14_82E4_Color *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_495C8(s32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("%d");
}
#pragma section code_type ".text"

#pragma opt_strength_reduction off
void fn_14_82E4(s16 arg0, s16 arg1, s16 arg2) {
    f32 x;
    s32 n;
    struct { f32 value; } y;
    f32 t;
    struct { s32 value; } d;

    t = lbl_8006D188((s32)(65536.0f * (f32)((lbl_801A66A0 % 60) % 120) / 120.0f));
    n = arg2 / 60;
    fn_1_49410();
    x = 320.0f + (f32)arg0;
    y.value = 240.0f + (f32)arg1;
    fn_1_496FC(x, y.value);
    fn_1_494DC(0x17);
    fn_1_495C8(9);
    fn_1_4954C(5.0f);
    fn_1_4955C(0.7f, 0.7f);
    fn_1_4AE0C((const char *)"%d", d.value = n / 10);
    fn_1_496FC(x, y.value);
    {
        fn_14_82E4_Color c = *(const fn_14_82E4_Color *)fzgx_pool_table28;
        fn_1_49514(&c);
    }
    t = 0.3f + (f32)(0.4f * t);
    fn_1_495A0(t);
    fn_1_494DC(0x18);
    fn_1_495C8(9);
    fn_1_4955C(0.7f, 0.7f);
    fn_1_4954C(9.0f);
    fn_1_4AE0C((const char *)"%d", d.value);
    fn_1_49410();
    x = 20.0f + x;
    fn_1_496FC(x, y.value);
    {
        fn_14_82E4_Color c = *(const fn_14_82E4_Color *)fzgx_pool_table29;
        fn_1_49514(&c);
    }
    fn_1_494DC(0x17);
    fn_1_495C8(9);
    fn_1_4955C(0.7f, 0.7f);
    fn_1_4954C(5.0f);
    fn_1_4AE0C((const char *)"%d", d.value = n % 10);
    fn_1_496FC(x, y.value);
    {
        fn_14_82E4_Color c = *(const fn_14_82E4_Color *)fzgx_pool_table30;
        fn_1_49514(&c);
    }
    fn_1_495A0(t);
    fn_1_494DC(0x18);
    fn_1_495C8(9);
    fn_1_4955C(0.7f, 0.7f);
    fn_1_4954C(9.0f);
    fn_1_4AE0C((const char *)"%d", d.value);
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_14_82E4 */

/* fzgx:begin fn_14_A1F4 */
extern u32 fn_1_412A0(u32);
extern u32 fn_1_48140(u32);
extern u32 lbl_801A66B4;

void fn_14_A1F4(void) {
    fn_1_48140(151);
    fn_1_48140(141);
    if ((s32)lbl_801A66B4 == 5) {
    fn_1_412A0(4);
    } else {
    fn_1_412A0(5);
    }
}
/* fzgx:end fn_14_A1F4 */

/* fzgx:begin fn_14_A244 */
extern struct fn_14_A244_lbl_14_bss_20 lbl_14_bss_20;
extern u16 lbl_14_bss_9452;
extern u32 fn_1_12F1E8(u32);
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_47F74(u32);
extern u32 lbl_14_data_30D4;
extern void fn_14_A3DC(void);

struct fn_14_A244_lbl_14_bss_20 {
    u32 unk_0;
};

void fn_14_A244(void) {
    u32 t3;
    fn_1_47F74(151);
    fn_1_12F1E8(4800);
    fn_1_435C(lbl_14_bss_20.unk_0);
    t3 = fn_1_3F8C((u32)&lbl_14_data_30D4, (u32)fn_14_A3DC, 0, 8);
    lbl_14_bss_9452 = t3;
}
/* fzgx:end fn_14_A244 */

/* fzgx:begin fn_14_A2A4 */
extern void fn_1_133DBC(void *);
extern u8 fn_1_B7C00(void);
extern s32 fn_1_12F228(void);
extern u8 fn_14_DF70(void);
extern s32 fn_1_B7E98(u32);
extern s32 fn_1_B7C6C(u32);
extern void fn_1_F7954(void);
extern u32 fn_1_B7CE4(u32, void *);
extern u32 fn_1_AA6D8(u32, u32, void *);
extern u8 fn_1_B7CD4(void);
extern u16 lbl_1_bss_96A[];
extern struct fn_14_A2A4_bss_9454 lbl_14_bss_9454;
extern u8 lbl_1_bss_718E0;

struct fn_14_A2A4_bss_9454 {
    s32 unk_0;
};

struct fn_14_A2A4_cfg {
    u8 enabled;
    u8 pad[3];
    u32 fn;
    void *state_ptr;
    void *table;
    u32 extra[4];

    u8 fzgx_tail_padding[8];
};

void fn_14_A2A4(void) {
    struct fn_14_A2A4_cfg cfg;
    u8 state[64];

    fn_1_133DBC(0);
    if (fn_1_B7C00()) {
        return;
    }
    if (fn_1_12F228()) {
        lbl_1_bss_96A[0] = fn_14_DF70() ? 0xaf : 0xb2;
        return;
    }
    if (fn_1_B7E98(1)) {
        if (fn_1_B7C6C(1) == 0 && ((((lbl_14_bss_9454.unk_0)) == ((0))))) {
            fn_1_F7954();
            fn_1_B7CE4(1, state);
            cfg.enabled = 1;
            cfg.state_ptr = state;
            cfg.table = &lbl_1_bss_718E0;
            cfg.fn = 0xA004;
            fn_1_AA6D8(0, 1, &cfg);
            lbl_14_bss_9454.unk_0 = 1;
            return;
        }
    } else {
        lbl_14_bss_9454.unk_0 = 0;
    }
    fn_1_B7CD4();
}
/* fzgx:end fn_14_A2A4 */

/* fzgx:begin fn_14_A398 */
extern struct fn_14_A398_lbl_14_bss_20 lbl_14_bss_20;
extern struct fn_14_A398_lbl_14_bss_9452 lbl_14_bss_9452;
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_48140(u32);

struct fn_14_A398_lbl_14_bss_20 {
    u32 unk_0;
};
struct fn_14_A398_lbl_14_bss_9452 {
    s16 unk_0;
};

void fn_14_A398(void) {
    fn_1_48140(151);
    fn_1_435C(lbl_14_bss_20.unk_0);
    fn_1_426C(lbl_14_bss_9452.unk_0);
}
/* fzgx:end fn_14_A398 */

/* fzgx:begin fn_14_B398 */
extern struct fn_14_B398_lbl_14_bss_9460 lbl_14_bss_9460;
extern struct fn_14_B398_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern u32 fn_1_128DD8(u32);
extern u32 fn_1_128E8C(u32, u32);
extern u32 fn_1_159AE0(void);
extern u32 fn_1_A2D84(u32);
extern u32 lbl_14_bss_0;
extern u32 lbl_14_bss_9464;

struct fn_14_B398_lbl_1_bss_8B3A0 {
    u8 pad_0[0x90];
    s16 unk_90;
};
struct fn_14_B398_lbl_14_bss_9460 {
    u32 unk_0;
};

void fn_14_B398(void) {
    u32 t0;
    lbl_14_bss_9460.unk_0 = 0;
    lbl_14_bss_0 = 480;
    t0 = fn_1_128DD8((lbl_1_bss_8B3A0.unk_90 & 0xFF));
    fn_1_128E8C(t0, (u32)&lbl_14_bss_9464);
    fn_1_159AE0();
    fn_1_A2D84((0xA9120000 + 10240));
}
/* fzgx:end fn_14_B398 */

/* fzgx:begin fn_14_B400 */
struct fn_14_B400_lbl_1_bss_D58 {
    u8 pad_0[0x8];
    u16 unk_8;
};
struct fn_14_B400_lbl_1_bss_6EAB4 {
    u32 unk_0;
};

extern f32 lbl_14_rodata_30;
extern struct fn_14_B400_lbl_1_bss_6EAB4 lbl_1_bss_6EAB4;
extern struct fn_14_B400_lbl_1_bss_D58 lbl_1_bss_D58;
extern u16 lbl_1_bss_96A;
extern u32 fn_14_B484(void);
extern u32 fn_14_DC90(f32);
extern u32 fn_1_13DC54(void);
extern u32 lbl_14_bss_0;
extern void fn_1_133DBC(void *);

void fn_14_B400(void) {
    fn_1_133DBC((void *)0);
    fn_1_13DC54();
    fn_14_B484();
    fn_14_DC90(lbl_14_rodata_30);
    if ((s32)lbl_14_bss_0 < 420 && (((lbl_1_bss_D58.unk_8 >> 8) & 0x1) != 0 || (s32)lbl_14_bss_0 < 0)) {
    lbl_1_bss_96A = 178;
    lbl_1_bss_6EAB4.unk_0 = (lbl_1_bss_6EAB4.unk_0 | 44);
    }
}
/* fzgx:end fn_14_B400 */

/* fzgx:begin fn_14_B480 */
// fn_14_B480: empty in retail (single blr).
void fn_14_B480(void) {
}
/* fzgx:end fn_14_B480 */

/* fzgx:begin fn_14_BCDC */
extern u32 lbl_14_bss_0;
extern u32 lbl_14_bss_9460;

void fn_14_BCDC(void) {
    lbl_14_bss_9460 = 0;
    lbl_14_bss_0 = 366;
}
/* fzgx:end fn_14_BCDC */

/* fzgx:begin fn_14_C4F4 */
// fn_14_C4F4: empty in retail (single blr).
void fn_14_C4F4(void) {
}
/* fzgx:end fn_14_C4F4 */

/* fzgx:begin fn_14_C4F8 */
struct fn_14_C4F8_lbl_1_bss_6EAB4 {
    u32 unk_0;
};

extern struct fn_14_C4F8_lbl_1_bss_6EAB4 lbl_1_bss_6EAB4;
extern u32 lbl_14_bss_0;

u32 fn_14_C4F8(void) {
    lbl_14_bss_0 = 60;
    lbl_1_bss_6EAB4.unk_0 = (lbl_1_bss_6EAB4.unk_0 | 44);
    return (u32)&lbl_1_bss_6EAB4;
}
/* fzgx:end fn_14_C4F8 */

/* fzgx:begin fn_14_C518 */
#include "font.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 167.0f;
    s = 38.0f;
    s = 90.0f;
    s = 320.0f;
    s = 216.0f;
    s = 8.0f;
    s = 96.0f;
    s = 336.0f;
    s = 380.0f;
    d = 12.0;
    s = 1.0f;
    s = 99.0f;
    s = 30.0f;
    s = 140.0f;
    s = 178.0f;
    s = 254.0f;
    s = 292.0f;
    s = 541.0f;
    s = 575.0f;
    s = 98.0f;
    s = 42.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 60.0;
    d = 25.0;
    d = 29.0;
}
static const u32 fzgx_pool_table4[10] = {0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFF8080FF, 0xA0FF00FF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 396.0f;
    s = 190.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    d = 18.0;
    s = 136.0f;
    s = 0.550000011920929f;
    s = 108.0f;
    s = 300.0f;
    s = 80.0f;
    s = 400.0f;
    s = 388.0f;
    s = 97.0f;
    s = 0.05000000074505806f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 30.0;
    d = 2.0;
    d = 4503599627370496.0;
    s = 193.32176208496094f;
}
static const u32 fzgx_pool_table10[1] = {0x53454C00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 20.0f;
}
static const u32 fzgx_pool_table12[12] = {0x00000000, 0x40AD2D2D, 0xC04FCFD0, 0x00000000, 0x40A00000, 0xC0400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
    s = 182.04444885253906f;
    d = 0.55;
    s = 0.8299999833106995f;
    s = 0.06666667014360428f;
}
static const u32 fzgx_pool_table14[8] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF00FFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.625f;
}
static const u32 fzgx_pool_table16[9] = {0x00FF0000, 0xFFFFFF00, 0xFFFFFF00, 0x00FF0000, 0x00060007, 0x00080000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4583333432674408f;
    s = 0.6666666865348816f;
    s = 0.6169934868812561f;
    s = 0.4166666567325592f;
    s = 0.8333333134651184f;
    s = 0.48627451062202454f;
}
static const u32 fzgx_pool_table18[2] = {0xFFFFFFFF, 0x3F3F3F3F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 62.0f;
    s = 50.0f;
    s = 5.0f;
    s = 7.0f;
}
static const u32 fzgx_pool_table20[2] = {0x00FF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.480392187833786f;
}
static const u32 fzgx_pool_table22[2] = {0xFF00FFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 314.0f;
    s = 84.0f;
    s = 321.0f;
    s = 356.0f;
    s = 0.75f;
    s = 51.0f;
    s = 0.30000001192092896f;
    s = 88.0f;
    s = 2.0f;
}
static const u32 fzgx_pool_table24[13] = {0xFFFF0000, 0xFF000000, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9215686321258545f;
    s = 0.4588235318660736f;
}
static const u32 fzgx_pool_table26[2] = {0xFF00FFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 492.0f;
    s = 332.0f;
    s = 40.0f;
    s = 322.0f;
    s = 41.0f;
    s = 238.0f;
    s = 156.0f;
    s = 1.2901960611343384f;
    s = 0.8313725590705872f;
    s = 240.0f;
    s = 0.009999999776482582f;
    s = 8.00100040435791f;
    s = 100.0f;
    s = 0.019999999552965164f;
    s = 9.999999747378752e-05f;
    s = 16.0f;
    s = 24.0f;
    s = 73.0f;
    s = 368.0f;
    s = 193.0f;
    s = 248.0f;
    s = 36.0f;
    s = 376.0f;
    s = 211.0f;
    s = 608.0f;
    s = 257.0f;
    s = 176.0f;
    s = 239.0f;
}
static const u32 fzgx_pool_table28[3] = {0x0000FA00, 0xFAFAFAFF, 0x0000FA00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 120.0f;
    s = 0.4000000059604645f;
    s = 9.0f;
    s = 402.0f;
    s = 548.0f;
    s = 134.0f;
    s = 586.0f;
    s = 449.0f;
    s = 329.0f;
    s = 14.210000038146973f;
    s = 3.200000047683716f;
}
static const u32 fzgx_pool_table30[4] = {0x008080FF, 0x3CA3D70A, 0xC10CCCCD, 0xC2700000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05999999865889549f;
    s = 375.0f;
    s = 0.20000000298023224f;
    s = 0.800000011920929f;
    s = 370.0f;
    s = 358.0f;
    s = 360.0f;
    s = 0.10000000149011612f;
    s = 45.0f;
    s = 0.0010000000474974513f;
    s = 0.23000000417232513f;
    s = -8.800000190734863f;
    s = -60.0f;
    s = 0.029999999329447746f;
    s = 0.09000000357627869f;
    s = 383.0f;
    s = 0.6000000238418579f;
    s = 381.0f;
    s = 324.0f;
    s = 32768.0f;
    s = 0.07000000029802322f;
    s = 0.03999999910593033f;
    s = 340.0f;
    s = 12.75f;
}
static const u32 fzgx_pool_table32[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 215.0f;
    s = 226.0f;
    s = 220.0f;
    s = 227.0f;
    s = 328.0f;
    s = 234.0f;
    s = 317.0f;
    s = 310.0f;
    s = 315.0f;
}
static const u32 fzgx_pool_table34[3] = {0x00FF0000, 0xFF800000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03333333507180214f;
    s = 640.0f;
    s = 0.15000000596046448f;
    s = 48.0f;
    s = 87.0f;
    s = 0.10100000351667404f;
    s = 153.0f;
    s = 0.0989999994635582f;
    s = 346.0f;
    s = 217.0f;
    s = 228.0f;
    s = 105.0f;
    s = 466.0f;
    s = 286.0f;
    s = 52.0f;
    s = 0.5833333134651184f;
    s = 488.0f;
    s = 28.0f;
    s = 189.0f;
    s = 470.0f;
    s = 280.0f;
    s = 44.0f;
    s = 272.0f;
    s = 151.0f;
    s = 1.25f;
    s = 1.0833333730697632f;
    s = 500.0f;
    s = 422.0f;
    s = 166.0f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table36[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -5.0f;
    s = 32767.0f;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 336.0;
    d = 318.0;
    d = 306.0;
    d = 366.0;
    s = 224.0f;
    s = 448.0f;
    d = 17.0;
    s = 16384.0f;
    s = 204.0f;
    d = 66.0;
    d = 270.0;
    d = 6.0;
}
static const u32 fzgx_pool_table40[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
}
#pragma section code_type ".text"

struct fn_14_C518_lbl_14_rodata_0 {
    u8 pad_0[0x10];
    f32 unk_10;
    u8 pad_14[0x1C];
    f32 unk_30;
    u8 pad_34[0x2C];
    f64 unk_60;
    u8 pad_68[0x2F4];
    f32 unk_35C;
    u8 pad_360[0x100];
    f32 unk_460;
    u8 pad_464[0x2C];
    u32 unk_490;
    f32 unk_494;
};

extern struct fn_14_C518_lbl_14_rodata_0 lbl_14_rodata_0;
extern FontDrawPacket lbl_1_rodata_26F8;
extern u16 lbl_1_bss_968;
extern u32 lbl_14_bss_0;

extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_49410(void);
extern void fn_1_49514(u32 *);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_8006CE1C(f32);
extern u32 fn_14_DC90(f32);

void fn_14_C518(void) {
    struct fn_14_C518_lbl_14_rodata_0 *p;
    FontDrawPacket pkt;
    u32 val;

    p = (struct fn_14_C518_lbl_14_rodata_0 *)&lbl_14_rodata_0;
    pkt = lbl_1_rodata_26F8;
    pkt.x = (320.0f);
    pkt.y = (224.0f);
    pkt.flags = 14;
    pkt.image = 0x9208;
    fn_1_4F734(&pkt);
    pkt.flags = 6;
    pkt.image = 0x9207;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9201;
    pkt.x = (320.0f);
    pkt.y = (224.0f);
    pkt.flags = 10;
    pkt.z = (0.0900000036f);
    fn_1_4F734(&pkt);
    fn_1_49410();
    fn_1_495FC();
    fn_1_495C8(9);
    fn_1_495B0(1u << 31);
    val = fzgx_pool_table40[0];
    fn_1_49514(&val);
    fn_14_DC90((1.0f));
    if ((s32)lbl_14_bss_0 > 0) {
        fn_8006CE1C((1.0f) - ((f32)(s32)lbl_14_bss_0 / (60.0f)));
    } else {
        lbl_1_bss_968 = 10;
    }
}
/* fzgx:end fn_14_C518 */

/* fzgx:begin fn_14_C698 */
// fn_14_C698: empty in retail (single blr).
void fn_14_C698(void) {
}
/* fzgx:end fn_14_C698 */

/* fzgx:begin fn_14_C69C */
struct fn_14_C69C_Arg0 {
    char **unk_0;
    u32 unk_4;
    s32 unk_8;
};

extern char *strncpy(char *, const char *, size_t);
extern int sprintf(char *, const char *, ...);
extern size_t strlen(const char *);
extern u32 __cvt_fp2unsigned(f32);
extern void fn_1_4AE0C(const char *, ...);
extern f32 lbl_14_rodata_30;
extern f32 lbl_14_rodata_364;
extern const f64 lbl_14_rodata_110;
extern char lbl_14_data_300C[];
extern char lbl_14_data_3244[];
extern u32 lbl_801A66A0;
extern u32 lbl_801A66B4;

void fn_14_C69C(struct fn_14_C69C_Arg0 *arg0, f32 arg1) {
    char buf[256];

    if (arg0->unk_8 != 0 || lbl_14_rodata_30 == arg1) {
        sprintf(buf, lbl_14_data_300C, arg0->unk_0[lbl_801A66B4]);
        fn_1_4AE0C(buf);
        return;
    }
    if (arg1 < lbl_14_rodata_364) {
        f32 lenf = (f32)strlen(arg0->unk_0[lbl_801A66B4]);
        u32 n = __cvt_fp2unsigned(lenf * arg1);
        strncpy(buf, arg0->unk_0[lbl_801A66B4], n);
        if ((lbl_801A66A0 & 3) < 2) {
            buf[n] = '_';
            buf[n + 1] = 0;
        } else {
            buf[n] = 0;
        }
    } else if ((lbl_801A66A0 & 3) < 2) {
        sprintf(buf, lbl_14_data_3244, arg0->unk_0[lbl_801A66B4]);
    } else {
        sprintf(buf, lbl_14_data_300C, arg0->unk_0[lbl_801A66B4]);
    }
    fn_1_4AE0C(buf);
}
/* fzgx:end fn_14_C69C */

/* fzgx:begin fn_14_C850 noprologue */
#include "types.h"

struct fn_14_C850_Arg0 {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    f32 unk_14;
    f32 unk_18;
};

struct fn_14_C850_lbl_801A63C0 {
    u32 unk_0;
};

extern f32 lbl_14_rodata_0;
extern f32 lbl_14_rodata_30;
extern const f64 lbl_14_rodata_60;
extern const f64 lbl_14_rodata_110;
extern u32 lbl_14_bss_C;
extern struct fn_14_C850_lbl_801A63C0 lbl_801A63C0;
extern u8 lbl_14_data_3060[0x74];
extern u32 lbl_14_data_3248;
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern f32 fn_1_4B068(char *);
extern f64 __fabs(f64);

void fn_14_C850(struct fn_14_C850_Arg0 *arg0, f32 arg1) {
    char buf[2];
    u32 v31;
    f32 v30;
    u32 v29;
    u32 v28;
    u8 v27;
    s32 v26;
    s32 v25;
    s32 v24;
    s32 v4;

    if (arg0 != 0 && lbl_14_rodata_0 != arg1) {
        if (lbl_14_rodata_30 == arg1 || arg0->unk_0 == 0) {
            fn_1_4955C(arg0->unk_14, arg0->unk_18);
            fn_1_4AE0C((const char *)lbl_14_data_3060, arg0->unk_0);
            return;
        }
        v24 = arg0->unk_10 == 0 ? lbl_14_bss_C : arg0->unk_10;
        v30 = arg1 * arg1;
        for (v4 = 0, v28 = 10; v4 < 10; v4++) {
            if (__fabs((f64)(f32)(s32)arg0->unk_0) < v28) {
                v28 = v4 + 1;
                break;
            }
            v28 *= 10;
        }
        if (arg0->unk_0 < 0) {
            v28++;
        }
        v31 = v28;
        v31 += 1;
        v25 = 0;
        v29 = 0;
        v26 = (s32)__fabs((f64)(f32)(s32)arg0->unk_0);
        while (v29 < v28) {
            if (arg0->unk_0 < 0 && v29 == v28 - 1) {
                v27 = '-';
            } else {
                v27 = (u8)('0' + v26 % 10);
                v26 = v26 / 10;
            }
            if ((f32)(v29 + 2) / (f32)v31 < v30) {
                fn_1_496FC((f32)(s32)(arg0->unk_C - v25), (f32)(s32)v24);
                fn_1_4955C(arg0->unk_14, arg0->unk_18);
                fn_1_4AE0C((const char *)&lbl_14_data_3248, (u32)v27);
                buf[0] = v27;
                buf[1] = 0;
                v25 = (s32)((f32)(s32)v25 + fn_1_4B068(buf));
            } else if ((f32)v29 / (f32)v31 < v30) {
                fn_1_496FC((f32)(s32)(arg0->unk_C - v25), (f32)(s32)v24);
                fn_1_4955C(arg0->unk_14, arg0->unk_18);
                lbl_801A63C0.unk_0 = lbl_801A63C0.unk_0 * 1735019371 + 13259;
                v27 = (u8)('0' + ((s32)((lbl_801A63C0.unk_0 >> 16) & 0x7FFF)) % 10);
                fn_1_4AE0C((const char *)&lbl_14_data_3248, (u32)v27);
                buf[0] = v27;
                buf[1] = 0;
                v25 = (s32)((f32)(s32)v25 + fn_1_4B068(buf));
            }
            v29++;
        }
    }
}
/* fzgx:end fn_14_C850 */

/* fzgx:begin fn_14_D2EC */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 167.0f;
    s = 38.0f;
    s = 90.0f;
    s = 320.0f;
    s = 216.0f;
    s = 8.0f;
    s = 96.0f;
    s = 336.0f;
    s = 380.0f;
    d = 12.0;
    s = 1.0f;
    s = 99.0f;
    s = 30.0f;
    s = 140.0f;
    s = 178.0f;
    s = 254.0f;
    s = 292.0f;
    s = 541.0f;
    s = 575.0f;
    s = 98.0f;
    s = 42.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 60.0;
    d = 25.0;
    d = 29.0;
}
static const u32 fzgx_pool_table4[10] = {0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFF8080FF, 0xA0FF00FF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 396.0f;
    s = 190.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    d = 18.0;
    s = 136.0f;
    s = 0.550000011920929f;
    s = 108.0f;
    s = 300.0f;
    s = 80.0f;
    s = 400.0f;
    s = 388.0f;
    s = 97.0f;
    s = 0.05000000074505806f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 30.0;
    d = 2.0;
    d = 4503599627370496.0;
    s = 193.32176208496094f;
}
static const u32 fzgx_pool_table10[1] = {0x53454C00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 20.0f;
}
static const u32 fzgx_pool_table12[12] = {0x00000000, 0x40AD2D2D, 0xC04FCFD0, 0x00000000, 0x40A00000, 0xC0400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
    s = 182.04444885253906f;
    d = 0.55;
    s = 0.8299999833106995f;
    s = 0.06666667014360428f;
}
static const u32 fzgx_pool_table14[8] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF00FFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.625f;
}
static const u32 fzgx_pool_table16[9] = {0x00FF0000, 0xFFFFFF00, 0xFFFFFF00, 0x00FF0000, 0x00060007, 0x00080000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f32 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4583333432674408f;
    s = 0.6666666865348816f;
    s = 0.6169934868812561f;
    s = 0.4166666567325592f;
    s = 0.8333333134651184f;
    s = 0.48627451062202454f;
}
static const u32 fzgx_pool_table18[2] = {0xFFFFFFFF, 0x3F3F3F3F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 62.0f;
    s = 50.0f;
    s = 5.0f;
    s = 7.0f;
}
static const u32 fzgx_pool_table20[2] = {0x00FF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.480392187833786f;
}
static const u32 fzgx_pool_table22[2] = {0xFF00FFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 314.0f;
    s = 84.0f;
    s = 321.0f;
    s = 356.0f;
    s = 0.75f;
    s = 51.0f;
    s = 0.30000001192092896f;
    s = 88.0f;
    s = 2.0f;
}
static const u32 fzgx_pool_table24[13] = {0xFFFF0000, 0xFF000000, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9215686321258545f;
    s = 0.4588235318660736f;
}
static const u32 fzgx_pool_table26[2] = {0xFF00FFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 492.0f;
    s = 332.0f;
    s = 40.0f;
    s = 322.0f;
    s = 41.0f;
    s = 238.0f;
    s = 156.0f;
    s = 1.2901960611343384f;
    s = 0.8313725590705872f;
    s = 240.0f;
    s = 0.009999999776482582f;
    s = 8.00100040435791f;
    s = 100.0f;
    s = 0.019999999552965164f;
    s = 9.999999747378752e-05f;
    s = 16.0f;
    s = 24.0f;
    s = 73.0f;
    s = 368.0f;
    s = 193.0f;
    s = 248.0f;
    s = 36.0f;
    s = 376.0f;
    s = 211.0f;
    s = 608.0f;
    s = 257.0f;
    s = 176.0f;
    s = 239.0f;
}
static const u32 fzgx_pool_table28[3] = {0x0000FA00, 0xFAFAFAFF, 0x0000FA00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 120.0f;
    s = 0.4000000059604645f;
    s = 9.0f;
    s = 402.0f;
    s = 548.0f;
    s = 134.0f;
    s = 586.0f;
    s = 449.0f;
    s = 329.0f;
    s = 14.210000038146973f;
    s = 3.200000047683716f;
}
static const u32 fzgx_pool_table30[4] = {0x008080FF, 0x3CA3D70A, 0xC10CCCCD, 0xC2700000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05999999865889549f;
    s = 375.0f;
    s = 0.20000000298023224f;
    s = 0.800000011920929f;
    s = 370.0f;
    s = 358.0f;
    s = 360.0f;
    s = 0.10000000149011612f;
    s = 45.0f;
    s = 0.0010000000474974513f;
    s = 0.23000000417232513f;
    s = -8.800000190734863f;
    s = -60.0f;
    s = 0.029999999329447746f;
    s = 0.09000000357627869f;
    s = 383.0f;
    s = 0.6000000238418579f;
    s = 381.0f;
    s = 324.0f;
    s = 32768.0f;
    s = 0.07000000029802322f;
    s = 0.03999999910593033f;
    s = 340.0f;
    s = 12.75f;
}
static const u32 fzgx_pool_table32[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 215.0f;
    s = 226.0f;
    s = 220.0f;
    s = 227.0f;
    s = 328.0f;
    s = 234.0f;
    s = 317.0f;
    s = 310.0f;
    s = 315.0f;
}
static const u32 fzgx_pool_table34[3] = {0x00FF0000, 0xFF800000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03333333507180214f;
    s = 640.0f;
    s = 0.15000000596046448f;
    s = 48.0f;
    s = 87.0f;
    s = 0.10100000351667404f;
    s = 153.0f;
    s = 0.0989999994635582f;
    s = 346.0f;
    s = 217.0f;
    s = 228.0f;
    s = 105.0f;
    s = 466.0f;
    s = 286.0f;
    s = 52.0f;
    s = 0.5833333134651184f;
    s = 488.0f;
    s = 28.0f;
    s = 189.0f;
    s = 470.0f;
    s = 280.0f;
    s = 44.0f;
    s = 272.0f;
    s = 151.0f;
    s = 1.25f;
    s = 1.0833333730697632f;
    s = 500.0f;
    s = 422.0f;
    s = 166.0f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table36[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -5.0f;
    s = 32767.0f;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 336.0;
    d = 318.0;
    d = 306.0;
    d = 366.0;
    s = 224.0f;
    s = 448.0f;
    d = 17.0;
    s = 16384.0f;
    s = 204.0f;
    d = 66.0;
    d = 270.0;
    d = 6.0;
}
static const u32 fzgx_pool_table40[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
}
static const u32 fzgx_pool_table42[2] = {0xFFFF40FF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 222.0;
    s = 160.0f;
    s = 207.0f;
    d = 168.0;
    d = 138.0;
    d = 0.5;
    s = 264.0f;
    s = 0.04000000283122063f;
    d = 153.0;
    s = 230.0f;
    s = 410.0f;
    s = 179.0f;
}
static const u32 fzgx_pool_table44[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep44(void) { const u32 *volatile cp; cp = fzgx_pool_table44; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime45(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 204.0;
    s = 244.0f;
}
static const u32 fzgx_pool_table46[1] = {0x19FF19FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep46(void) { const u32 *volatile cp; cp = fzgx_pool_table46; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct FontDrawPacket {
    u32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkc;
    f32 unk10;
    f32 unk14;
    u8 pad18[0x14];
    f32 unk2c;
    u32 unk30;
    u8 pad34[0x24];
} FontDrawPacket;

extern const FontDrawPacket lbl_1_rodata_26F8;
extern s32 lbl_801A66B4;
extern const char *lbl_14_data_BD4[];

extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_5233C(void);
extern int fn_1_4F734(FontDrawPacket *);

static inline const char * *fn_14_D2EC_array_read(const char * *array) { return array; }
#pragma opt_lifetimes off
void fn_14_D2EC(s32 arg0) {
    FontDrawPacket packet;
    u32 lab_t0;

    packet = lbl_1_rodata_26F8;
    packet.unk0 = 0x9e2b;
    packet.unk30 = 10;
    packet.unkc = 0.09f;

    if ((f64)arg0 > 222.0) {
        f32 temp = (f32)(240 - arg0) / 18.0;
        packet.unk4 = 320.0f;
        packet.unk8 = 224.0f;
        packet.unk2c = temp;
        packet.unk2c *= temp;
        fn_1_50164(300.0f * packet.unk2c, 160.0f * packet.unk2c, 8.0f, 8.0f, &packet);
    } else if ((f64)arg0 > 18.0) {
        if (222.0 == (f64)arg0) {
            lab_t0 = 0xa9110300;
            fn_1_A2D84(lab_t0);
        }
        packet.unk4 = 320.0f;
        packet.unk8 = 224.0f;
        fn_1_50164(300.0f, 160.0f, 8.0f, 8.0f, &packet);
        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_495C8(9);
        fn_1_4955C(0.8f, 0.8f);
        fn_1_496FC(320.0f, 244.0f);
        fn_1_4AE0C(fn_14_D2EC_array_read(lbl_14_data_BD4)[lbl_801A66B4]);
        fn_1_49738((u32)fn_1_5233C);
        fn_1_49748(5.0f);

        packet = lbl_1_rodata_26F8;
        packet.unk0 = 0x9200;
        packet.unkc = 0.07f;
        packet.unk4 = 320.0f;
        packet.unk8 = 179.0f;
        {
            f32 f5 = 0.0f;
            f32 f1 = (f32)((f64)arg0 - 204.0);
            f1 /= 18.0;

            f5 = (f1 < 0.0f) ? 0.0f : ((f1 > 1.0f) ? 1.0f : f1);

            {
                f32 inv = 1.0f - f5;
                f32 scale;
                packet.unk30 = 10;
                inv *= inv;
                packet.unk2c = inv;
                scale = 1.0f + (f32)(2.0f * f5);
                packet.unk10 = scale;
                packet.unk14 = scale;
                fn_1_4F734(&packet);
            }
        }
    } else {
        f32 temp = (f32)arg0 / 18.0;
        packet.unk4 = 320.0f;
        packet.unk8 = 224.0f;
        packet.unk2c = temp;
        packet.unk2c *= temp;
        fn_1_50164(300.0f * packet.unk2c, 160.0f * packet.unk2c, 8.0f, 8.0f, &packet);
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_14_D2EC */

/* fzgx:begin fn_14_D600 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 167.0f;
    s = 38.0f;
    s = 90.0f;
    s = 320.0f;
    s = 216.0f;
    s = 8.0f;
    s = 96.0f;
    s = 336.0f;
    s = 380.0f;
    d = 12.0;
    s = 1.0f;
    s = 99.0f;
    s = 30.0f;
    s = 140.0f;
    s = 178.0f;
    s = 254.0f;
    s = 292.0f;
    s = 541.0f;
    s = 575.0f;
    s = 98.0f;
    s = 42.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 60.0;
    d = 25.0;
    d = 29.0;
}
static const u32 fzgx_pool_table4[10] = {0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFF8080FF, 0xA0FF00FF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 396.0f;
    s = 190.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    d = 18.0;
    s = 136.0f;
    s = 0.550000011920929f;
    s = 108.0f;
    s = 300.0f;
    s = 80.0f;
    s = 400.0f;
    s = 388.0f;
    s = 97.0f;
    s = 0.05000000074505806f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 30.0;
    d = 2.0;
    d = 4503599627370496.0;
    s = 193.32176208496094f;
}
static const u32 fzgx_pool_table10[1] = {0x53454C00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 20.0f;
}
static const u32 fzgx_pool_table12[12] = {0x00000000, 0x40AD2D2D, 0xC04FCFD0, 0x00000000, 0x40A00000, 0xC0400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
    s = 182.04444885253906f;
    d = 0.55;
    s = 0.8299999833106995f;
    s = 0.06666667014360428f;
}
static const u32 fzgx_pool_table14[8] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF00FFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.625f;
}
static const u32 fzgx_pool_table16[9] = {0x00FF0000, 0xFFFFFF00, 0xFFFFFF00, 0x00FF0000, 0x00060007, 0x00080000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f32 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4583333432674408f;
    s = 0.6666666865348816f;
    s = 0.6169934868812561f;
    s = 0.4166666567325592f;
    s = 0.8333333134651184f;
    s = 0.48627451062202454f;
}
static const u32 fzgx_pool_table18[2] = {0xFFFFFFFF, 0x3F3F3F3F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 62.0f;
    s = 50.0f;
    s = 5.0f;
    s = 7.0f;
}
static const u32 fzgx_pool_table20[2] = {0x00FF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.480392187833786f;
}
static const u32 fzgx_pool_table22[2] = {0xFF00FFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 314.0f;
    s = 84.0f;
    s = 321.0f;
    s = 356.0f;
    s = 0.75f;
    s = 51.0f;
    s = 0.30000001192092896f;
    s = 88.0f;
    s = 2.0f;
}
static const u32 fzgx_pool_table24[13] = {0xFFFF0000, 0xFF000000, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9215686321258545f;
    s = 0.4588235318660736f;
}
static const u32 fzgx_pool_table26[2] = {0xFF00FFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 492.0f;
    s = 332.0f;
    s = 40.0f;
    s = 322.0f;
    s = 41.0f;
    s = 238.0f;
    s = 156.0f;
    s = 1.2901960611343384f;
    s = 0.8313725590705872f;
    s = 240.0f;
    s = 0.009999999776482582f;
    s = 8.00100040435791f;
    s = 100.0f;
    s = 0.019999999552965164f;
    s = 9.999999747378752e-05f;
    s = 16.0f;
    s = 24.0f;
    s = 73.0f;
    s = 368.0f;
    s = 193.0f;
    s = 248.0f;
    s = 36.0f;
    s = 376.0f;
    s = 211.0f;
    s = 608.0f;
    s = 257.0f;
    s = 176.0f;
    s = 239.0f;
}
static const u32 fzgx_pool_table28[3] = {0x0000FA00, 0xFAFAFAFF, 0x0000FA00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 120.0f;
    s = 0.4000000059604645f;
    s = 9.0f;
    s = 402.0f;
    s = 548.0f;
    s = 134.0f;
    s = 586.0f;
    s = 449.0f;
    s = 329.0f;
    s = 14.210000038146973f;
    s = 3.200000047683716f;
}
static const u32 fzgx_pool_table30[4] = {0x008080FF, 0x3CA3D70A, 0xC10CCCCD, 0xC2700000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05999999865889549f;
    s = 375.0f;
    s = 0.20000000298023224f;
    s = 0.800000011920929f;
    s = 370.0f;
    s = 358.0f;
    s = 360.0f;
    s = 0.10000000149011612f;
    s = 45.0f;
    s = 0.0010000000474974513f;
    s = 0.23000000417232513f;
    s = -8.800000190734863f;
    s = -60.0f;
    s = 0.029999999329447746f;
    s = 0.09000000357627869f;
    s = 383.0f;
    s = 0.6000000238418579f;
    s = 381.0f;
    s = 324.0f;
    s = 32768.0f;
    s = 0.07000000029802322f;
    s = 0.03999999910593033f;
    s = 340.0f;
    s = 12.75f;
}
static const u32 fzgx_pool_table32[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 215.0f;
    s = 226.0f;
    s = 220.0f;
    s = 227.0f;
    s = 328.0f;
    s = 234.0f;
    s = 317.0f;
    s = 310.0f;
    s = 315.0f;
}
static const u32 fzgx_pool_table34[3] = {0x00FF0000, 0xFF800000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03333333507180214f;
    s = 640.0f;
    s = 0.15000000596046448f;
    s = 48.0f;
    s = 87.0f;
    s = 0.10100000351667404f;
    s = 153.0f;
    s = 0.0989999994635582f;
    s = 346.0f;
    s = 217.0f;
    s = 228.0f;
    s = 105.0f;
    s = 466.0f;
    s = 286.0f;
    s = 52.0f;
    s = 0.5833333134651184f;
    s = 488.0f;
    s = 28.0f;
    s = 189.0f;
    s = 470.0f;
    s = 280.0f;
    s = 44.0f;
    s = 272.0f;
    s = 151.0f;
    s = 1.25f;
    s = 1.0833333730697632f;
    s = 500.0f;
    s = 422.0f;
    s = 166.0f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table36[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -5.0f;
    s = 32767.0f;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 336.0;
    d = 318.0;
    d = 306.0;
    d = 366.0;
    s = 224.0f;
    s = 448.0f;
    d = 17.0;
    s = 16384.0f;
    s = 204.0f;
    d = 66.0;
    d = 270.0;
    d = 6.0;
}
static const u32 fzgx_pool_table40[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
}
static const u32 fzgx_pool_table42[2] = {0xFFFF40FF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 222.0;
    s = 160.0f;
    s = 207.0f;
    d = 168.0;
    d = 138.0;
    d = 0.5;
    s = 264.0f;
    s = 0.04000000283122063f;
    d = 153.0;
    s = 230.0f;
    s = 410.0f;
    s = 179.0f;
}
static const u32 fzgx_pool_table44[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep44(void) { const u32 *volatile cp; cp = fzgx_pool_table44; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime45(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 204.0;
    s = 244.0f;
}
static const u32 fzgx_pool_table46[1] = {0x19FF19FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep46(void) { const u32 *volatile cp; cp = fzgx_pool_table46; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct FontDrawPacket {
    u32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkc;
    f32 unk10;
    f32 unk14;
    u8 pad18[0x14];
    f32 unk2c;
    u32 unk30;
    u8 pad34[0x24];
} FontDrawPacket;

extern const FontDrawPacket lbl_1_rodata_26F8;
extern s32 lbl_801A66B4;
extern const char *lbl_14_data_C54[];

extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_5233C(void);
extern int fn_1_4F734(FontDrawPacket *);

static inline const char * *fn_14_D600_array_read(const char * *array) { return array; }
#pragma opt_lifetimes off
void fn_14_D600(s32 arg0) {
    FontDrawPacket packet;
    u32 lab_t0;

    packet = lbl_1_rodata_26F8;
    packet.unk0 = 0x9e2b;
    packet.unk30 = 10;
    packet.unkc = 0.09f;

    if ((f64)arg0 > 222.0) {
        f32 temp = (f32)(240 - arg0) / 18.0;
        packet.unk4 = 320.0f;
        packet.unk8 = 224.0f;
        packet.unk2c = temp;
        packet.unk2c *= temp;
        fn_1_50164(300.0f * packet.unk2c, 160.0f * packet.unk2c, 8.0f, 8.0f, &packet);
    } else if ((f64)arg0 > 18.0) {
        if (222.0 == (f64)arg0) {
            lab_t0 = 0xa9110200;
            fn_1_A2D84(lab_t0);
        }
        packet.unk4 = 320.0f;
        packet.unk8 = 224.0f;
        fn_1_50164(300.0f, 160.0f, 8.0f, 8.0f, &packet);
        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_495C8(9);
        fn_1_4955C(0.8f, 0.8f);
        fn_1_496FC(320.0f, 244.0f);
        fn_1_4AE0C(fn_14_D600_array_read(lbl_14_data_C54)[lbl_801A66B4]);
        fn_1_49738((u32)fn_1_5233C);
        fn_1_49748(5.0f);

        packet = lbl_1_rodata_26F8;
        packet.unk0 = 0x9206;
        packet.unk4 = 320.0f;
        packet.unk8 = 179.0f;
        {
            f32 f5 = 0.0f;
            f32 f1 = (f32)((f64)arg0 - 204.0);
            f1 /= 18.0;

            f5 = (f1 < 0.0f) ? 0.0f : ((f1 > 1.0f) ? 1.0f : f1);

            {
                f32 inv = 1.0f - f5;
                f32 scale;
                packet.unk30 = 10;
                inv *= inv;
                packet.unk2c = inv;
                scale = 1.0f + (f32)(2.0f * f5);
                packet.unkc = 0.07f;
                packet.unk10 = scale;
                packet.unk14 = scale;
                fn_1_4F734(&packet);
            }
        }
    } else {
        f32 temp = (f32)arg0 / 18.0;
        packet.unk4 = 320.0f;
        packet.unk8 = 224.0f;
        packet.unk2c = temp;
        packet.unk2c *= temp;
        fn_1_50164(300.0f * packet.unk2c, 160.0f * packet.unk2c, 8.0f, 8.0f, &packet);
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_14_D600 */

/* fzgx:begin fn_14_D914 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 167.0f;
    s = 38.0f;
    s = 90.0f;
    s = 320.0f;
    s = 216.0f;
    s = 8.0f;
    s = 96.0f;
    s = 336.0f;
    s = 380.0f;
    d = 12.0;
    s = 1.0f;
    s = 99.0f;
    s = 30.0f;
    s = 140.0f;
    s = 178.0f;
    s = 254.0f;
    s = 292.0f;
    s = 541.0f;
    s = 575.0f;
    s = 98.0f;
    s = 42.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 60.0;
    d = 25.0;
    d = 29.0;
}
static const u32 fzgx_pool_table4[10] = {0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFF8080FF, 0xA0FF00FF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 396.0f;
    s = 190.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    d = 18.0;
    s = 136.0f;
    s = 0.550000011920929f;
    s = 108.0f;
    s = 300.0f;
    s = 80.0f;
    s = 400.0f;
    s = 388.0f;
    s = 97.0f;
    s = 0.05000000074505806f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 30.0;
    d = 2.0;
    d = 4503599627370496.0;
    s = 193.32176208496094f;
}
static const u32 fzgx_pool_table10[1] = {0x53454C00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 20.0f;
}
static const u32 fzgx_pool_table12[12] = {0x00000000, 0x40AD2D2D, 0xC04FCFD0, 0x00000000, 0x40A00000, 0xC0400000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
    s = 182.04444885253906f;
    d = 0.55;
    s = 0.8299999833106995f;
    s = 0.06666667014360428f;
}
static const u32 fzgx_pool_table14[8] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF00FFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.625f;
}
static const u32 fzgx_pool_table16[9] = {0x00FF0000, 0xFFFFFF00, 0xFFFFFF00, 0x00FF0000, 0x00060007, 0x00080000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f32 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4583333432674408f;
    s = 0.6666666865348816f;
    s = 0.6169934868812561f;
    s = 0.4166666567325592f;
    s = 0.8333333134651184f;
    s = 0.48627451062202454f;
}
static const u32 fzgx_pool_table18[2] = {0xFFFFFFFF, 0x3F3F3F3F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 62.0f;
    s = 50.0f;
    s = 5.0f;
    s = 7.0f;
}
static const u32 fzgx_pool_table20[2] = {0x00FF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.480392187833786f;
}
static const u32 fzgx_pool_table22[2] = {0xFF00FFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 314.0f;
    s = 84.0f;
    s = 321.0f;
    s = 356.0f;
    s = 0.75f;
    s = 51.0f;
    s = 0.30000001192092896f;
    s = 88.0f;
    s = 2.0f;
}
static const u32 fzgx_pool_table24[13] = {0xFFFF0000, 0xFF000000, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFFFFFF00, 0xFFFF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9215686321258545f;
    s = 0.4588235318660736f;
}
static const u32 fzgx_pool_table26[2] = {0xFF00FFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 492.0f;
    s = 332.0f;
    s = 40.0f;
    s = 322.0f;
    s = 41.0f;
    s = 238.0f;
    s = 156.0f;
    s = 1.2901960611343384f;
    s = 0.8313725590705872f;
    s = 240.0f;
    s = 0.009999999776482582f;
    s = 8.00100040435791f;
    s = 100.0f;
    s = 0.019999999552965164f;
    s = 9.999999747378752e-05f;
    s = 16.0f;
    s = 24.0f;
    s = 73.0f;
    s = 368.0f;
    s = 193.0f;
    s = 248.0f;
    s = 36.0f;
    s = 376.0f;
    s = 211.0f;
    s = 608.0f;
    s = 257.0f;
    s = 176.0f;
    s = 239.0f;
}
static const u32 fzgx_pool_table28[3] = {0x0000FA00, 0xFAFAFAFF, 0x0000FA00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 120.0f;
    s = 0.4000000059604645f;
    s = 9.0f;
    s = 402.0f;
    s = 548.0f;
    s = 134.0f;
    s = 586.0f;
    s = 449.0f;
    s = 329.0f;
    s = 14.210000038146973f;
    s = 3.200000047683716f;
}
static const u32 fzgx_pool_table30[4] = {0x008080FF, 0x3CA3D70A, 0xC10CCCCD, 0xC2700000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05999999865889549f;
    s = 375.0f;
    s = 0.20000000298023224f;
    s = 0.800000011920929f;
    s = 370.0f;
    s = 358.0f;
    s = 360.0f;
    s = 0.10000000149011612f;
    s = 45.0f;
    s = 0.0010000000474974513f;
    s = 0.23000000417232513f;
    s = -8.800000190734863f;
    s = -60.0f;
    s = 0.029999999329447746f;
    s = 0.09000000357627869f;
    s = 383.0f;
    s = 0.6000000238418579f;
    s = 381.0f;
    s = 324.0f;
    s = 32768.0f;
    s = 0.07000000029802322f;
    s = 0.03999999910593033f;
    s = 340.0f;
    s = 12.75f;
}
static const u32 fzgx_pool_table32[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 215.0f;
    s = 226.0f;
    s = 220.0f;
    s = 227.0f;
    s = 328.0f;
    s = 234.0f;
    s = 317.0f;
    s = 310.0f;
    s = 315.0f;
}
static const u32 fzgx_pool_table34[3] = {0x00FF0000, 0xFF800000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03333333507180214f;
    s = 640.0f;
    s = 0.15000000596046448f;
    s = 48.0f;
    s = 87.0f;
    s = 0.10100000351667404f;
    s = 153.0f;
    s = 0.0989999994635582f;
    s = 346.0f;
    s = 217.0f;
    s = 228.0f;
    s = 105.0f;
    s = 466.0f;
    s = 286.0f;
    s = 52.0f;
    s = 0.5833333134651184f;
    s = 488.0f;
    s = 28.0f;
    s = 189.0f;
    s = 470.0f;
    s = 280.0f;
    s = 44.0f;
    s = 272.0f;
    s = 151.0f;
    s = 1.25f;
    s = 1.0833333730697632f;
    s = 500.0f;
    s = 422.0f;
    s = 166.0f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table36[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -5.0f;
    s = 32767.0f;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 336.0;
    d = 318.0;
    d = 306.0;
    d = 366.0;
    s = 224.0f;
    s = 448.0f;
    d = 17.0;
    s = 16384.0f;
    s = 204.0f;
    d = 66.0;
    d = 270.0;
    d = 6.0;
}
static const u32 fzgx_pool_table40[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
}
static const u32 fzgx_pool_table42[2] = {0xFFFF40FF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 222.0;
    s = 160.0f;
    s = 207.0f;
    d = 168.0;
    d = 138.0;
    d = 0.5;
    s = 264.0f;
    s = 0.04000000283122063f;
    d = 153.0;
    s = 230.0f;
    s = 410.0f;
    s = 179.0f;
}
static const u32 fzgx_pool_table44[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep44(void) { const u32 *volatile cp; cp = fzgx_pool_table44; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime45(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 204.0;
    s = 244.0f;
}
static const u32 fzgx_pool_table46[1] = {0x19FF19FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep46(void) { const u32 *volatile cp; cp = fzgx_pool_table46; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct FontDrawPacket {
    u32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkc;
    f32 unk10;
    f32 unk14;
    u8 pad18[0x14];
    f32 unk2c;
    u32 unk30;
    u8 pad34[0x24];
} FontDrawPacket;

extern const FontDrawPacket lbl_1_rodata_26F8;
extern s32 lbl_801A66B4;
extern const char *lbl_14_data_C9C[];

extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_5233C(void);
extern int fn_1_4F734(FontDrawPacket *);

static inline const char * *fn_14_D914_array_read(const char * *array) { return array; }
#pragma opt_lifetimes off
void fn_14_D914(s32 arg0) {
    FontDrawPacket packet;
    u32 lab_t0;

    packet = lbl_1_rodata_26F8;
    packet.unk0 = 0x9e2b;
    packet.unk30 = 10;
    packet.unkc = 0.09f;

    if ((f64)arg0 > 222.0) {
        f32 temp = (f32)(240 - arg0) / 18.0;
        packet.unk4 = 320.0f;
        packet.unk8 = 224.0f;
        packet.unk2c = temp;
        packet.unk2c *= temp;
        fn_1_50164(300.0f * packet.unk2c, 160.0f * packet.unk2c, 8.0f, 8.0f, &packet);
    } else if ((f64)arg0 > 18.0) {
        if (222.0 == (f64)arg0) {
            lab_t0 = 0xa9110200;
            fn_1_A2D84(lab_t0);
        }
        packet.unk4 = 320.0f;
        packet.unk8 = 224.0f;
        fn_1_50164(300.0f, 160.0f, 8.0f, 8.0f, &packet);
        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_495C8(9);
        fn_1_4955C(0.8f, 0.8f);
        fn_1_496FC(320.0f, 244.0f);
        fn_1_4AE0C(fn_14_D914_array_read(lbl_14_data_C9C)[lbl_801A66B4]);
        fn_1_49738((u32)fn_1_5233C);
        fn_1_49748(5.0f);

        packet = lbl_1_rodata_26F8;
        packet.unk0 = 0x9206;
        packet.unk4 = 320.0f;
        packet.unk8 = 179.0f;
        {
            f32 f5 = 0.0f;
            f32 f1 = (f32)((f64)arg0 - 204.0);
            f1 /= 18.0;

            f5 = (f1 < 0.0f) ? 0.0f : ((f1 > 1.0f) ? 1.0f : f1);

            {
                f32 inv = 1.0f - f5;
                f32 scale;
                packet.unk30 = 10;
                inv *= inv;
                packet.unk2c = inv;
                scale = 1.0f + (f32)(2.0f * f5);
                packet.unkc = 0.07f;
                packet.unk10 = scale;
                packet.unk14 = scale;
                fn_1_4F734(&packet);
            }
        }
    } else {
        f32 temp = (f32)arg0 / 18.0;
        packet.unk4 = 320.0f;
        packet.unk8 = 224.0f;
        packet.unk2c = temp;
        packet.unk2c *= temp;
        fn_1_50164(300.0f * packet.unk2c, 160.0f * packet.unk2c, 8.0f, 8.0f, &packet);
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_14_D914 */

/* fzgx:begin fn_14_DC28 */
// fn_14_DC28: empty in retail (single blr).
void fn_14_DC28(void) {
}
/* fzgx:end fn_14_DC28 */

/* fzgx:begin fn_14_DC2C */
typedef struct LocalData {
    u8 data[0x1471];
    u8 field_1479;
    u8 field_147a;
    u8 tail[0x38];
} LocalData;

extern void fn_1_3EF14(void *);

u32 fn_14_DC2C(void) {
    LocalData local;
    u8 result;
    fn_1_3EF14(&local);
    if (local.field_147a != 0) {
        result = 0;
    } else {
        result = local.field_1479;
    }
    return result;
}
/* fzgx:end fn_14_DC2C */

/* fzgx:begin fn_14_DC6C */
extern u32 lbl_14_data_6C8;

u32 fn_14_DC6C(u32 arg0, u32 arg1) {
    return *(u32 *)((u8 *)((u8 *)&lbl_14_data_6C8 + ((s16)arg0 * 24)) + ((s16)arg1 << 2));
}
/* fzgx:end fn_14_DC6C */

/* fzgx:begin fn_14_DC90 */
typedef struct RoData {
    u8 pad_0[0x10];
    f32 unk_10;
    u8 pad_14[0x4];
    f32 unk_18;
    u8 pad_1C[0x1C];
    f32 unk_38;
    u8 pad_3C[0x74];
    f32 unk_B0;
    u8 pad_B4[0x274];
    f32 unk_328;
    u8 pad_32C[0x48];
    f32 unk_374;
    u8 pad_378[0x1A0];
    u32 unk_518;
    u32 unk_51C;
    u8 pad_520[0xC];
    u32 unk_52C;
    u32 unk_530;
    f32 unk_534;
    f32 unk_538;
    f32 unk_53C;
    f32 unk_540;
    f32 unk_544;
    f32 unk_548;
} RoData;

typedef struct Cmd88 {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x1C];
    f32 unk_2C;
    u32 unk_30;
    u8 tail_34[0x24];
} Cmd88;

extern s16 lbl_1_bss_962;
extern f32 lbl_14_data_0;
extern RoData lbl_14_rodata_0;
extern u32 lbl_14_bss_9460;
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66B4;

extern void fn_1_4D0A0(void);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern u32 fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4954C(f32);
extern int fn_1_B7E98(int);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D10C(void *, f32, f32);

#pragma opt_lifetimes off
#pragma opt_propagation off
void fn_14_DC90(f32 farg0) {
    const char *dpp = (const char *)&lbl_14_data_0;
    RoData *rp = (RoData *)&lbl_14_rodata_0;
    const char **t;
    Cmd88 cmd;
    u32 sp18;
    u32 sp14;
    u32 sp10;
    u32 out;
    u8 bytes[4];

    if (lbl_1_bss_962 != 0xaf) {
        fn_1_4D0A0();
    } else {
        cmd = *(const Cmd88 *)&lbl_1_rodata_26F8;
        cmd.unk_0 = 0x9E2B;
        cmd.unk_4 = rp->unk_10;
        cmd.unk_8 = rp->unk_328;
        cmd.unk_C = rp->unk_534;
        cmd.unk_30 = 0xa;
        cmd.unk_2C = farg0;
        fn_1_50164(rp->unk_538, rp->unk_53C, rp->unk_18, rp->unk_18, &cmd);
        fn_1_49410();
        fn_1_495FC();
        fn_1_495C8(9);
        fn_1_495B0(0x80000000);
    }

    fn_1_49590(rp->unk_B0);
    fn_1_4954C(rp->unk_374);

    if (fn_1_B7E98(1) != 0) {
        if ((s32)lbl_14_bss_9460 != 0) {
            fn_1_496FC(rp->unk_10, rp->unk_540);
            fn_1_4955C(rp->unk_544, rp->unk_544);
            sp18 = rp->unk_518;
            fn_1_49514(&sp18);
            t = (const char **)(dpp + 0x32FC);
            fn_1_4AE0C(t[lbl_801A66B4]);
            t = (const char **)(dpp + 0x3370);
            fn_1_4AE0C(t[lbl_801A66B4]);
            t = (const char **)(dpp + 0x33F0);
            fn_1_4AE0C(t[lbl_801A66B4]);
        } else {
            fn_1_496FC(rp->unk_10, rp->unk_328);
        }
        fn_1_4955C(rp->unk_544, rp->unk_544);
        sp14 = rp->unk_51C;
        fn_1_49514(&sp14);
        t = (const char **)(dpp + 0x34AC);
        fn_1_4AE0C(t[lbl_801A66B4]);
    } else if ((s32)lbl_14_bss_9460 != 0) {
        fn_1_496FC(rp->unk_10, rp->unk_540);
        fn_1_4955C(rp->unk_544, rp->unk_544);
        sp10 = rp->unk_52C;
        fn_1_49514(&sp10);
        t = (const char **)(dpp + 0x32FC);
        fn_1_4AE0C(t[lbl_801A66B4]);
        t = (const char **)(dpp + 0x3370);
        fn_1_4AE0C(t[lbl_801A66B4]);
        t = (const char **)(dpp + 0x33F0);
        fn_1_4AE0C(t[lbl_801A66B4]);
    }

    if (((s32)lbl_14_bss_9460 != 0 || fn_1_B7E98(1) != 0) && lbl_1_bss_962 != 0xaf) {
        *(u32 *)bytes = rp->unk_530;
        bytes[3] = (u8)(rp->unk_548 * farg0);
        out = *(u32 *)bytes;
        fn_1_4D10C(&out, rp->unk_534, rp->unk_38);
    }
}
#pragma opt_propagation reset

#pragma opt_lifetimes reset
/* fzgx:end fn_14_DC90 */

/* fzgx:begin fn_14_DF70 */
extern s16 lbl_1_bss_8B3A0;
extern u8 fn_1_128DD8(u8);
extern void fn_1_128E8C(u8, void *);

s32 fn_14_DF70(void) {
    u8 buffer[40];
    s16 *p = &lbl_1_bss_8B3A0;

    if (*p++ == 9) {
        return 0;
    }

    fn_1_128E8C(fn_1_128DD8((u8)(p[0x47] & 0xFF)), buffer);

    if (buffer[0] == 8 && buffer[1] == 44 && *(u16 *)&buffer[2] == 287) {
        return 0;
    }

    return 1;
}
/* fzgx:end fn_14_DF70 */
