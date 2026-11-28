/* Previously matched Japan/PAL units of ghost.c, retained until that TU matches those releases as one unit. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ghost.h"

extern void fn_1_F23E8(void);
extern void fn_1_EE530(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_B9BE0(void);
extern void fn_1_B9DE8(Obj_1_bss_7ECB4 *obj);
extern u8 lbl_1_bss_7EA00[56];
extern int fn_1_B7CD4(void);
extern int fn_1_B7C5C(void);
extern u32 lbl_1_bss_7B19C[2];
extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, u32, void *, u32);
extern void fn_1_C1394(void);
extern void OSReport(const char *, ...);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern const f32 lbl_1_rodata_6D20;
extern const f32 lbl_1_rodata_6D24;
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(s32);
extern s32 lbl_1_bss_7B198;
extern void fn_1_4AE0C(void *, ...);
extern u8 lbl_1_bss_7C85C__fzgx_offset_72[70];
extern void fn_1_F1D70(void);
extern u32 lbl_1_bss_7EA38[159];
extern const f64 lbl_1_rodata_6B68;
extern const f32 lbl_1_rodata_6D10;
extern const f32 lbl_1_rodata_6D44;
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_F1950(void);
extern u32 fn_8002071C(void *arg);
extern void fn_800206FC(u32 arg);
extern u32 ARGetDMAStatus(void);
extern void DCFlushRange(void *addr, u32 size);
extern u32 lbl_1_bss_7C848[2];
extern u8 lbl_1_bss_7C85C__fzgx_offset_71;
extern u32 lbl_1_bss_7C948;
extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);
extern u32 lbl_1_bss_7B190[2];
extern u32 lbl_1_bss_7ED58[158];

extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);

extern void OSReport(const char *, ...);
extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);

extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);

extern void fn_1_12EF80(s16 arg, s16 *out_a, s16 *out_b);
extern f64 lbl_1_rodata_6C88;
extern void fn_80008BA8(u32 *out, const void *value, s32 size);
extern s32 fn_1_F21B8(s32 arg);
extern void fn_1_F0D10(s32, void *);
extern void fn_1_F0B5C(s32, void *);
extern void fn_1_F0E00(s32, void *);
extern s32 fn_1_3F164(void);
extern void fn_1_B9C0C(void);
extern void fn_1_1596DC(s32);
extern void fn_1_484CC(s32);
extern u32 lbl_1_bss_7C914[13];
extern const f32 lbl_1_rodata_6D38;
extern const f32 lbl_1_rodata_6D3C;
extern const f32 lbl_1_rodata_6D40;
extern void lbl_8006DD14(void *a, void *b);
extern f32 lbl_8006D0B4(f32 x);
extern void lbl_8006D7DC(void *a);
extern void lbl_8006DFC4(void *a);
extern void lbl_8006DB74(void *a);
extern const f32 lbl_1_rodata_6BBC;
extern const f32 lbl_1_rodata_6BD0;
extern const f64 lbl_1_rodata_6D48;
extern const f32 lbl_1_rodata_6D50;
extern f64 fn_80088598(f64, f64);

/* fzgx:begin fn_1_F1B78 */
void fn_1_F1B78(u32 value) {
    lbl_1_bss_7C848[0] = value;
}
/* fzgx:end fn_1_F1B78 */

/* fzgx:begin fn_1_F1B94 */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;




typedef struct {
u32 unk_0;
u32 unk_4;
u32 unk_8;
u32 unk_C;
u32 unk_10;
u32 unk_14;
u32 unk_18;
u32 unk_1C;
u32 unk_20;
u32 unk_24;
u8 pad_28[0x4];
u8 arr_2C[0x1];
u8 unk_2D;
u8 unk_2E;
u8 unk_2F;
u8 arr_30[0x1];
u8 unk_31;
u8 unk_32;
u8 unk_33;
u8 arr_34[0x1];
u8 unk_35;
u8 unk_36;
u8 pad_37[0x1];
u32 unk_38;
u32 unk_3C;
u32 unk_40;
u8 arr_44[0x4];
u32 unk_48;
u32 unk_4C;
u8 arr_50[0x1];
u8 unk_51;
u16 unk_52;
u8 arr_54[0x13B0];
u32 unk_1404;
u8 arr_1408[0x1F8];
u32 unk_1600;
u8 arr_1604[0x10];
u32 unk_1614;
u8 arr_1618[0x10];
u32 unk_1628;
u8 arr_162C[0x10];
u32 unk_163C;
u8 arr_1640[0x10];
u32 unk_1650;
u8 arr_1654[0x10];
u32 unk_1664;
u8 arr_1668[0x10];
u32 unk_1678;
u8 arr_167C[0x10];
u32 unk_168C;
u8 arr_1690[0x10];
u32 unk_16A0;
u8 arr_16A4[0x10];
u32 unk_16B4;
u8 arr_16B8[0x10];
u32 unk_16C8;
u8 unk_16CC;
u8 pad_16CD[0x3];
u32 unk_16D0;
u32 unk_16D4;
u32 unk_16D8;
u32 unk_16DC;
u8 unk_16E0;
u8 pad_16E1[0x3];
u32 unk_16E4;
u32 unk_16E8;
u32 unk_16EC;
u32 unk_16F0;
u32 unk_16F4;
u32 unk_16F8;
u32 unk_16FC;
u32 unk_1700;
u32 unk_1704;
u32 unk_1708;
u32 unk_170C;
u32 unk_1710;
u32 unk_1714;
u32 unk_1718;
u32 unk_171C;
u32 unk_1720;
u32 unk_1724;
u32 unk_1728;
u32 unk_172C;
u32 unk_1730;
u32 unk_1734;
u32 unk_1738;
u32 unk_173C;
u32 unk_1740;
u32 unk_1744;
u32 unk_1748;
u8 unk_174C;
u8 unk_174D;
u8 unk_174E;
u8 pad_174F[0x1];
u32 unk_1750;
u8 unk_1754;
u8 pad_1755[0x3];
f32 unk_1758;
f32 unk_175C;
f32 unk_1760;
u8 pad_1764[0x30];
u32 unk_1794;
u8 arr_1798[0x10];
u32 unk_17A8;
u8 arr_17AC[0x10];
u32 unk_17BC;
u32 unk_17C0;
u32 unk_17C4;
u32 unk_17C8;
u32 unk_17CC;
u16 unk_17D0;
u16 unk_17D2;
u16 unk_17D4;
u16 unk_17D6;
u16 unk_17D8;
u8 pad_17DA[0x2];
u32 unk_17DC;
u32 unk_17E0;
u32 unk_17E4;
u32 unk_17E8;
u32 unk_17EC;
u8 unk_17F0;
u8 unk_17F1;
u8 unk_17F2;
u8 unk_17F3;
u8 unk_17F4;
u8 unk_17F5;
u8 unk_17F6;
u8 unk_17F7;
u8 unk_17F8;
u8 unk_17F9;
u8 unk_17FA;
u8 unk_17FB;
u8 unk_17FC;
u8 unk_17FD;
u8 unk_17FE;
u8 pad_17FF[0x1];
u16 unk_1800;
u8 arr_1802[0xA];
u8 arr_180C[0x14];
u32 unk_1820;
u32 unk_1824;
u8 arr_1828[0x10];
u16 unk_1838;
s16 unk_183A;
u32 unk_183C;
u8 pad_1840[0x18];
u8 arr_1858[0x80];
u8 arr_18D8[0x30];
u8 arr_1908[0xC0];
u8 arr_19C8[0x620];
u32 unk_1FE8;
u16 unk_1FEC;
u8 pad_1FEE[0x76];
u32 unk_2064;
u32 unk_2068;
u32 unk_206C;
u8 pad_2070[0x64];
u8 arr_20D4[0x60];
u8 arr_2134[0xB4];
f32 unk_21E8;
u8 pad_21EC[0x20];
f32 unk_220C;
u8 pad_2210[0x24D];
u8 unk_245D;
u8 pad_245E[0x141A];
u32 unk_3878;
u32 unk_387C;
u8 unk_3880;
u8 pad_3881[0x3];
u32 unk_3884;
u32 unk_3888;
u8 unk_388C;
u8 pad_388D[0x3];
u32 unk_3890;
u32 unk_3894;
u32 unk_3898;
f32 unk_389C;
f32 unk_38A0;
u8 unk_38A4;
u8 unk_38A5;
u8 unk_38A6;
u8 pad_38A7[0x1];
u32 unk_38A8;
u32 unk_38AC;
u32 unk_38B0;
u32 unk_38B4;
u32 unk_38B8;
f32 unk_38BC;
u32 unk_38C0;
u8 arr_38C4[0x30];
u8 arr_38F4[0xC0];
u32 unk_39B4;
u32 unk_39B8;
u32 unk_39BC;
u8 arr_39C0[0x30];
u32 unk_39F0;
u8 arr_39F4[0x10];
u8 arr_3A04[0x30];
u8 arr_3A34[0xC0];
u8 arr_3AF4[0xC];
u8 arr_3B00[0x30];
u32 unk_3B30;
u8 arr_3B34[0x8];
u32 unk_3B3C;
u32 unk_3B40;
u32 unk_3B44;
u8 pad_3B48[0x2];
u16 unk_3B4A;
u8 pad_3B4C[0x30];
u32 unk_3B7C;
u8 arr_3B80[0x58];
u32 unk_3BD8;
} Obj_1_bss_7B180_fn_1_F1B94;


extern u8 *fn_1_3F0D8(u32 index, f32 *value, u8 *flag);
u32 fn_1_F1B94(void) {
f32 a;
u8 b;
u8 *base = (u8 *)&lbl_1_bss_7B180;
u8 *rec;
u32 result;
u8 *cur;
u32 t0;
u32 t1;
if (lbl_1_bss_960 == 9) {
if (*(s32 *)(base + 0x16c8) >= 0) {
rec = fn_1_3F0D8(0, &a, &b);
cur = *(u8 **)(base + 0x16b4);
result = 1;
t0 = rec[0x1e0] * 60000 + rec[0x1e1] * 1000 + *(u16 *)(rec + 0x1e2);
t1 = cur[0x24] * 60000 + cur[0x25] * 1000 + *(u16 *)(cur + 0x26);
if (t0 >= t1) {
result = 3;
}
return result;
}
return 0;
}
return *(base + 0x174c);
}
/* fzgx:end fn_1_F1B94 */
