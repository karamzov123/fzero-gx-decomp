/* Non-matching: best partial attempt (48.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/camera.h"

extern f64 lbl_1_rodata_400[15];
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495FC(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);

#define COLOR(N,OFF) do { u32 tmp; if (lbl_1_data_4068 >> 16 == (N)) tmp=*(u32 *)((u8 *)&lbl_1_rodata_400+0xD0); else tmp=*(u32 *)((u8 *)&lbl_1_rodata_400+0xD8); fn_1_49514(&tmp); } while (0)
#define STR(OFF) fn_1_4A0D8((const char *)((u8 *)&lbl_1_data_4068+(OFF)))
#define FMTF(OFF,SRC) do { const char *p=(const char *)((u8 *)&lbl_1_data_4068+(OFF)); if ((u8 *)(SRC)!=(u8 *)&lbl_1_bss_1010+0x134) fn_1_4AE0C(p, *(f32 *)(SRC)); else fn_1_4A0D8(p); } while (0)
#define FMTU(OFF,SRC) do { const char *p=(const char *)((u8 *)&lbl_1_data_4068+(OFF)); if ((u8 *)(SRC)!=(u8 *)&lbl_1_bss_1010+0x134) fn_1_4AE0C(p, *(u32 *)(SRC)); else fn_1_4A0D8(p); } while (0)
#define FMTS(OFF,SRC) do { const char *p=(const char *)((u8 *)&lbl_1_data_4068+(OFF)); if ((u8 *)(SRC)!=(u8 *)&lbl_1_bss_1010+0x134) fn_1_4AE0C(p, *(s16 *)(SRC)); else fn_1_4A0D8(p); } while (0)
void fn_1_CC5C(void) {
 u8 *d=(u8 *)&lbl_1_data_4068;
 u8 *b=(u8 *)&lbl_1_bss_1010;
 u32 c0=*(u32 *)((u8 *)&lbl_1_rodata_400+0xD0);
 u32 c1=*(u32 *)((u8 *)&lbl_1_rodata_400+0xD4);
 u32 c2=*(u32 *)((u8 *)&lbl_1_rodata_400+0xD8);
 u32 color=(c0);
 u32 x=(u32)(u16)((((d[2] >> 2)&0x3f)*60));
 u32 y=(u32)(u16)(((((((d[2] << 30) - (d[2] >> 7)) << 2) | (((d[2] << 30) - (d[2] >> 7)) >> 30)) + (d[2] >> 7))*150));
 if (!(lbl_1_bss_D58.unk_2 & 0x100)) {
 fn_1_49410(); fn_1_4954C(*(f32 *)((u8 *)&lbl_1_rodata_400+0xdc));
 fn_1_4955C(*(f32 *)((u8 *)&lbl_1_rodata_400+0xa0),*(f32 *)((u8 *)&lbl_1_rodata_400+0xa0));
 fn_1_495FC();
 fn_1_496FC((f32)y,(f32)x);
 if (d[3]==0) color=c0; else color=c2; fn_1_49514(&color);
 STR(0x1c0);
 if (d[3]==1) color=c0; else color=c2; fn_1_49514(&color);
 if (d+2 != b+0x134) fn_1_4AE0C((const char *)(d+0x1d0),d[2]); else STR(0x1d0);
 if (d[3]==2) color=c0; else color=c2; fn_1_49514(&color); STR(0x1d8);
 if (d[3]==3) color=c0; else color=c2; fn_1_49514(&color); STR(0x1e0);
 if (d[3]==4) color=c0; else color=c2; fn_1_49514(&color); STR(0x1f0);
 if (d[3]==5) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x200,b+0x48);
 if (d[3]==6) color=c0; else color=c2; fn_1_49514(&color);
 FMTU(0x20c,b+0x44);
 if (d[3]==7) color=c0; else color=c2; fn_1_49514(&color); STR(0x218);
 if (d[3]==8) color=c0; else color=c2; fn_1_49514(&color); STR(0x22c);
 if (d[3]==9) color=c0; else color=c2; fn_1_49514(&color); STR(0x240);
 if (d[3]==10) color=c0; else color=c2; fn_1_49514(&color); STR(0x254);
 if (d[3]==11) color=c0; else color=c2; fn_1_49514(&color); STR(0x264);
 if (d[3]==12) color=c0; else color=c2; fn_1_49514(&color); STR(0x274);
 if (d[3]==13) color=c0; else color=c2; fn_1_49514(&color); STR(0x280);
 if (d[3]==14) color=c0; else color=c2; fn_1_49514(&color); STR(0x288);
 if (d[3]==15) color=c0; else color=c2; fn_1_49514(&color); STR(0x290);
 if (d[3]==16) color=c0; else color=c2; fn_1_49514(&color); STR(0x29c);
 if (d[3]==17) color=c0; else color=c2; fn_1_49514(&color); STR(0x2a4);
 if (d[3]==18) color=c0; else color=c2; fn_1_49514(&color); STR(0x2ac);
 if (d[3]==19) color=c0; else color=c2; fn_1_49514(&color); STR(0x2bc);
 if (d[3]==20) color=c0; else color=c2; fn_1_49514(&color);
 FMTU(0x2c0,b+0x3c);
 if (d[3]==21) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x2cc,b+0x24);
 if (d[3]==22) color=c0; else color=c2; fn_1_49514(&color);
 FMTS(0x2d8,b+0x28);
 if (d[3]==23) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x2e8,b+0xcc);
 if (d[3]==24) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x2f8,b+0xd0);
 if (d[3]==25) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x304,b+0xd4);
 if (d[3]==26) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x310,b+0xd8);
 if (d[3]==27) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x2f8,b+0xdc);
 if (d[3]==28) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x304,b+0xe0);
 if (d[3]==29) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x320,b+0xe4);
 if (d[3]==30) color=c0; else color=c2; fn_1_49514(&color);
 FMTS(0x330,b+0xe8);
 if (d[3]==31) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x340,b+0xf0);
 if (d[3]==32) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x2f8,b+0xf4);
 if (d[3]==33) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x304,b+0xf8);
 if (d[3]==34) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x310,b+0xfc);
 if (d[3]==35) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x2f8,b+0x100);
 if (d[3]==36) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x304,b+0x104);
 if (d[3]==37) color=c0; else color=c2; fn_1_49514(&color);
 FMTF(0x320,b+0x108);
 if (d[3]==38) color=c0; else color=c2; fn_1_49514(&color);
 FMTS(0x330,b+0x10c);
 }
}
