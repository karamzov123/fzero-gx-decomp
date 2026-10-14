/* Non-matching: best partial attempt (82.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/customize/editor.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 192.0f;
    s = 105.0f;
    s = 90.0f;
    s = 32.0f;
    s = 0.0f;
    s = 184.0f;
    s = 86.0f;
    s = 100.0f;
    s = 175.0f;
    s = 88.0f;
    s = 0.5f;
    s = 10.0f;
    s = 420.0f;
    s = 334.0f;
    s = 29.0f;
    s = 320.0f;
    s = 232.0f;
    s = 50.0f;
    s = 4.0f;
    s = 480.0f;
    s = 92.0f;
    s = 1.0f;
    s = 1.0714285373687744f;
    s = 64.0f;
    s = 65535.0f;
    s = 119.0f;
    s = 30.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"
typedef struct { u32 unk_0; } Sig_fn_1_4FC50_InputObject;
struct fn_3_15F44_Copy88 { u32 a[22]; };
struct fn_3_15F44_lbl_3_rodata_538 {
 u8 pad_0[4]; f32 unk_4,unk_8,unk_C,unk_10,unk_14,unk_18,unk_1C,unk_20,unk_24,unk_28,unk_2C,unk_30,unk_34,unk_38,unk_3C,unk_40,unk_44,unk_48,unk_4C,unk_50,unk_54,unk_58,unk_5C,unk_60,unk_64,unk_68,unk_6C; f64 unk_70,unk_78;
};
struct fn_3_15F44_lbl_801A66A0 { u32 unk_0; };
extern f32 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_4FC50(Sig_fn_1_4FC50_InputObject *, u32,u16,u16,u32);
extern struct fn_3_15F44_lbl_3_rodata_538 lbl_3_rodata_538;
extern struct fn_3_15F44_lbl_801A66A0 lbl_801A66A0;
extern u16 fn_1_48690(u32);
extern u32 fn_1_52690();
extern u32 fn_3_1683C(void *);
extern u32 fn_3_17820(void);
extern u32 lbl_1_rodata_26F8;
extern u8 *fn_3_14074(void);
extern void GXInvalidateTexAll(void);
extern void fn_1_517EC(FontDrawPacket *,s16,s16,s16,s16,s16,s16);
extern void fn_3_16E14(s32,s32);
#define F(off) (*(f32 *)((u8 *)&loc_C + (off)))
#define B(off) (*(u8 *)((u8 *)&loc_C + (off)))
#define DRAW() fn_1_4F734((FontDrawPacket *)&loc_C)
#define COPY() loc_C = *(struct fn_3_15F44_Copy88 *)&lbl_1_rodata_26F8
#pragma opt_lifetimes off
void fn_3_15F44(void) {
 s32 tmp_cse1;
 struct fn_3_15F44_lbl_3_rodata_538 *p_lbl_3_rodata_538;
 Obj_3_bss_A23EC *p_lbl_3_bss_A23EC;
 u32 * buffers;
 s32 v0,v1,v2;
 s16 v3,v4,v5,v6;
 s16 v30,v33;
 u8 v29,v36;
 u32 v31,v35,v46,v52,v54;
 s32 v56;
 struct fn_3_15F44_Copy88 loc_C;
 u32 loc_8;
 u8 *t0;
 u16 t3;
 f32 t16,v41,v53;
 p_lbl_3_rodata_538 = &lbl_3_rodata_538;
 t0 = fn_3_14074();
 p_lbl_3_bss_A23EC = &lbl_3_bss_A23EC;
 if (p_lbl_3_bss_A23EC->unk_C & 0x20000000) {
 v0 = p_lbl_3_bss_A23EC->unk_14 - 1;
 p_lbl_3_bss_A23EC->unk_14 = v0 < 0 ? 0 : v0 > 5 ? 5 : v0;
 } else {
 v1 = p_lbl_3_bss_A23EC->unk_14 + 1;
 p_lbl_3_bss_A23EC->unk_14 = v1 < 0 ? 0 : v1 > 5 ? 5 : v1;
 }
 p_lbl_3_bss_A23EC = &lbl_3_bss_A23EC;
 v2 = 64 / (s32)p_lbl_3_bss_A23EC->unk_11;
 v3 = v2 / 2;
 v4 = *(s16 *)(t0+16);
 v6 = *(s16 *)(t0+18);
 if (v4-v3 < 0) v4=v3;
 else if (v4+v3 >= 64) v4=64-v3;
 v5=v3;
 if (v6-v5 < 0) v6=v3;
 else if (v6+v5 >= 64) v6=64-v5;
 COPY();
 loc_C.a[0]=0x863a;
 F(4)=(192.0f);
 F(8)=(105.0f);
 F(12)=(90.0f);
 F(16)=F(20)=(32.0f);
 loc_C.a[12]=0x400000a;
 F(44)=(0.0f);
 loc_C.a[20]=(u32)fn_3_1683C;
 DRAW();
 COPY();
 loc_C.a[0]=0x8607;
 F(4)=(184.0f);
 F(8)=(86.0f);
 F(12)=(100.0f);
 loc_C.a[12]=5;
 DRAW();
 t3=fn_1_48690(loc_C.a[0]);
 F(4)=(f32)((s32)t3+184);
 loc_C.a[12]|=0x80000;
 DRAW();
 if (*(u32 *)t0 & 0x80000000) fn_3_16E14(192,105);
 COPY();
 loc_C.a[0]=0x8605;
 F(4)=(175.0f);
 F(8)=(88.0f);
 F(12)=(90.0f);
 F(44)=(0.5f) + (f32)lbl_3_bss_A23EC.unk_14 / (10.0f);
 loc_C.a[12]=5;
 DRAW();
 F(4)=(420.0f);
 F(8)=(88.0f);
 F(12)=(90.0f);
 loc_C.a[12]=0x80005;
 DRAW();
 F(4)=(175.0f);
 F(8)=(334.0f);
 F(12)=(90.0f);
 loc_C.a[12]=0x100005;
 DRAW();
 F(4)=(420.0f);
 F(8)=(334.0f);
 F(12)=(90.0f);
 loc_C.a[12]|=0x80000;
 DRAW();
 COPY();
 loc_C.a[0]=0x8603;
 v29=p_lbl_3_bss_A23EC->unk_11;
 v30=v4; v33=v6;
 v31=v29<<1;
 F(4)=(f32)(s32)((v29*(v3+(*(s16 *)(t0+16)-v30))*4)+v31+202);
 F(12)=(29.0f);
 v35=v29*(v5+(*(s16 *)(t0+18)-v33))*4+v31;
 loc_C.a[12]=10;
 F(8)=(f32)(s32)(v35+94);
 DRAW();
 GXInvalidateTexAll();
 COPY();
 v36=p_lbl_3_bss_A23EC->unk_11;
 F(4)=(320.0f);
 F(8)=(232.0f);
 F(12)=(50.0f);
 v41=(4.0f)*(f32)(u32)v36;
 loc_C.a[12]=0x400000a;
 F(20)=F(16)=v41;
 loc_C.a[20]=(u32)fn_1_52690;
 tmp_cse1 = v3 << 1;
 if (v36>1) fn_1_517EC((FontDrawPacket *)&loc_C,v30-v3,v33-v5,tmp_cse1,v5<<1,64,64);
 fn_1_4FC50((Sig_fn_1_4FC50_InputObject *)&loc_C,5,64,64,*(u32 *)(t0+32));
 COPY();
 F(4)=(480.0f);
 F(8)=(92.0f);
 F(12)=(50.0f);
 F(16)=(1.0f);
 F(20)=(1.07142854f);
 loc_C.a[12]=5;
 fn_1_4FC50((Sig_fn_1_4FC50_InputObject *)&loc_C,5,64,64,*(u32 *)(t0+32));
 loc_8=fn_3_17820();
 v46=lbl_801A66A0.unk_0;
 v52=(lbl_3_bss_A23EC.unk_17*p_lbl_3_bss_A23EC->unk_11)&255;
 v54=(lbl_3_bss_A23EC.unk_18*p_lbl_3_bss_A23EC->unk_11)&255;
 v53=(65535.0f)*(f32)(u32)(v46%120);
 t16=lbl_8006D188((s32)(v53/(119.0f)));
 v56=(s32)((64.0f)*((1.0f)+t16));
 COPY();
 F(4)=(320.0f);
 F(8)=(232.0f);
 F(12)=(30.0f);
 loc_C.a[12]=10;
 v41=(4.0f)*(f32)(u32)p_lbl_3_bss_A23EC->unk_11;
 F(20)=F(16)=v41;
 loc_C.a[20]=(u32)fn_1_52690;
 if (!(p_lbl_3_bss_A23EC->unk_C & 0x20000000)) {
 if (((u8 *)&loc_8)[0]>=8 || ((u8 *)&loc_8)[1]>=8 || ((u8 *)&loc_8)[2]>=8)
 B(56)=B(57)=B(58)=255-v56;
 if (((u8 *)&loc_8)[0]<248 || ((u8 *)&loc_8)[1]<248 || ((u8 *)&loc_8)[2]<248)
 B(60)=B(61)=B(62)=v56;
 } else { B(56)=B(57)=B(58)=255; B(60)=B(61)=B(62)=0; }
 if (p_lbl_3_bss_A23EC->unk_11>1) fn_1_517EC((FontDrawPacket *)&loc_C,v52+(v30-v3),v54+(v33-v5),tmp_cse1,v5<<1,64,64);
 buffers=&lbl_3_bss_A23EC.unk_4;
 fn_1_4FC50((Sig_fn_1_4FC50_InputObject *)&loc_C,5,64,64,buffers[(lbl_3_bss_A23EC.unk_0+1)%2]);
 COPY();
 F(4)=(480.0f);
 F(8)=(92.0f);
 F(12)=(30.0f);
 F(16)=(1.0f);
 F(20)=(1.07142854f);
 loc_C.a[12]=5;
 if (!(p_lbl_3_bss_A23EC->unk_C&0x20000000)) {
 B(56)=B(57)=B(58)=255-((u8)v56*2);
 B(60)=B(61)=B(62)=((v56&127)*2);
 } else { B(56)=B(57)=B(58)=255; B(60)=B(61)=B(58)=0; }
 fn_1_4FC50((Sig_fn_1_4FC50_InputObject *)&loc_C,5,64,64,buffers[(lbl_3_bss_A23EC.unk_0+1)%2]);
 lbl_3_bss_A23EC.unk_0=(lbl_3_bss_A23EC.unk_0+1)%2;
}
#pragma opt_lifetimes reset

