/* Non-matching: best partial attempt (94.84% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
typedef struct { f32 m[10]; f64 d; } Sig_fn_1_29968_Mtx;
typedef struct { u8 pad_0[0x254]; f32 unk_254; u8 pad_258[0xB4]; f32 unk_30C; u8 pad_310[0x2D0]; Sig_fn_1_29968_Mtx unk_5E0; } Sig_fn_1_29968_Owner;
typedef struct { unsigned char *field00; unsigned char *field04; unsigned char data[0xb8]; } Sig_fn_1_235C8_Fn_1_235C8;
typedef struct { unsigned char pad00[0x80]; int field80; unsigned char pad84[0x0c]; int *field90; int *field94; unsigned char pad98[0x04]; int field9c; unsigned char padA0[0x18]; int fieldb8; unsigned char padbc[0x0c]; int fieldc8; unsigned char padcc[0x0c]; int fieldd8; unsigned char pade0[0x40]; int field11c; unsigned char pad120[0x3c]; int field15c; unsigned char tail160[0x9c]; } Sig_fn_1_23640_Fn_1_23640;
struct fn_1_22F90_Copy16 { u32 a[4]; };
struct fn_1_22F90_lbl_1_rodata_840 { u8 pad_0[0xC]; f32 unk_C; u8 pad_10[4]; f32 unk_14; f32 unk_18; f32 unk_1C; f64 unk_20; u8 pad_28[0x50]; f32 unk_78; u8 pad_7C[0x70]; f32 unk_EC; f32 unk_F0; };
extern struct fn_1_22F90_lbl_1_rodata_840 lbl_1_rodata_840;
extern u32 lbl_8006DB74(u32);
extern u32 lbl_8006DD14(u32, void *);
extern void lbl_8006E1B0(void *, void *);
extern void * lbl_8006DC34(void *);
extern void fn_1_235C8(Sig_fn_1_235C8_Fn_1_235C8 *);
extern void fn_1_23610(void *);
extern void fn_1_23640(Sig_fn_1_23640_Fn_1_23640 *, int);
extern void fn_1_29968(Sig_fn_1_29968_Owner *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E1D8(u32, f32, f32, f32);
extern void lbl_8006E1F0(void *, f32, f32, f32);

#pragma opt_propagation off
static inline f32 fn_1_22F90_read_pointer(struct fn_1_22F90_lbl_1_rodata_840 * owner) { return owner->unk_14; }
void fn_1_22F90(u8 *arg0, int arg1) {
    f32 fzgx_live_;
    f32 fzgx_live;
    struct fn_1_22F90_lbl_1_rodata_840 *p;
    f32 v0;
    f32 v1;
    f32 v2;
    f32 v5;
    f32 v6;
    f32 v7;
    f32 v10;
    f32 v11;
    f32 v12;
    f32 v13;
    f32 v15;
    f64 v4;
    u16 v8;
    u32 v14;
    s32 i;
    f32 lab_t2;
    p = &lbl_1_rodata_840;
    fzgx_live = p->unk_14;
    v0 = p->unk_C; v1 = fzgx_live;
    *(f32 *)((u8 *)arg0+148)=v0; *(f32 *)((u8 *)arg0+152)=v0; *(f32 *)((u8 *)arg0+156)=v0;
    *(f32 *)((u8 *)arg0+204)=v0; *(f32 *)((u8 *)arg0+208)=v0; *(f32 *)((u8 *)arg0+212)=v0;
    *(f32 *)((u8 *)arg0+184)=v0; *(f32 *)((u8 *)arg0+188)=v0; *(f32 *)((u8 *)arg0+192)=v0;
    *(f32 *)((u8 *)arg0+160)=v0; *(f32 *)((u8 *)arg0+164)=v0; *(f32 *)((u8 *)arg0+168)=v0;
    *(f32 *)((u8 *)arg0+432)=v0; *(f32 *)((u8 *)arg0+436)=v0; *(f32 *)((u8 *)arg0+440)=v0;
    *(f32 *)((u8 *)arg0+420)=v0; *(f32 *)((u8 *)arg0+424)=v0; *(f32 *)((u8 *)arg0+428)=v0;
    *(f32 *)((u8 *)arg0+408)=v0; *(f32 *)((u8 *)arg0+412)=v0; *(f32 *)((u8 *)arg0+416)=v0;
    *(f32 *)((u8 *)arg0+224)=v0; *(f32 *)((u8 *)arg0+228)=v0; *(f32 *)((u8 *)arg0+232)=v0;
    *(f32 *)((u8 *)arg0+1252)=v0; *(f32 *)((u8 *)arg0+1256)=v0; *(f32 *)((u8 *)arg0+1260)=v0;
    *(f32 *)((u8 *)arg0+1264)=v0; *(f32 *)((u8 *)arg0+1268)=v0; *(f32 *)((u8 *)arg0+1272)=v0;
    lbl_8006E1F0((u8 *)arg0+444,v0,v1,v0);
    psvec_set((u8 *)arg0+124,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));
    psvec_set((u8 *)arg0+136,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));
    psvec_set((u8 *)arg0+1224,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));
    lbl_8006DAEC();
    v2=p->unk_C; lbl_8006E0B4(v2,p->unk_EC,v2);
    psvec_set((u8 *)arg0+468,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));
    lbl_8006DB30();
{
    f32 v3;
    psvec_set((u8 *)arg0+480,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));

    v3=p->unk_C;
    fzgx_live_ = p->unk_F0; v4=p->unk_20; v5=fzgx_live_;
    fzgx_live = p->unk_14;
    v6=fzgx_live; v7=p->unk_78;
    *(f32 *)((u8 *)arg0+508)=v3; *(f32 *)((u8 *)arg0+524)=v3; *(f32 *)((u8 *)arg0+1144)=v3;
    *(f32 *)((u8 *)arg0+512)=v3; *(f32 *)((u8 *)arg0+516)=v3; *(f32 *)((u8 *)arg0+504)=v3; *(f32 *)((u8 *)arg0+500)=v3;
    *(f32 *)((u8 *)arg0+456)=v3; *(u32 *)((u8 *)arg0+460)=0; *(f32 *)((u8 *)arg0+464)=v3;
    *(f32 *)((u8 *)arg0+196)=v3; *(u16 *)((u8 *)arg0+392)=0; *(f32 *)((u8 *)arg0+200)=v3;
    v8=*(u16 *)((u8 *)arg0+1498);
    { union { struct { u32 hi, lo; } words; f64 value; } cvt;
      cvt.words.hi = 0x43300000;
      cvt.words.lo = *(u16 *)((u8 *)arg0+1498);
      *(f32 *)((u8 *)arg0+388) = (f32)(cvt.value - v4);
    }
    *(u8 *)((u8 *)arg0+395)=0; *(f32 *)((u8 *)arg0+384)=v3; *(u8 *)((u8 *)arg0+394)=0;
    *(f32 *)((u8 *)arg0+492)=v3; *(f32 *)((u8 *)arg0+496)=v3; *(u8 *)((u8 *)arg0+1153)=0;
    *(f32 *)((u8 *)arg0+380)=v3; *(f32 *)((u8 *)arg0+220)=v3; *(u8 *)((u8 *)arg0+1424)=0;
    *(f32 *)((u8 *)arg0+396)=v3; *(u8 *)((u8 *)arg0+1142)=0; *(u8 *)((u8 *)arg0+1155)=0;
    *(u32 *)((u8 *)arg0+400)=0; *(u16 *)((u8 *)arg0+404)=0; *(u8 *)((u8 *)arg0+406)=0;
    *(f32 *)((u8 *)arg0+520)=v5; *(f32 *)((u8 *)arg0+1196)=v3; *(u32 *)((u8 *)arg0+1148)=0;
    *(u8 *)((u8 *)arg0+1152)=0; *(u8 *)((u8 *)arg0+407)=0; *(u8 *)((u8 *)arg0+530)=0;
    *(u16 *)((u8 *)arg0+528)=0; *(u16 *)((u8 *)arg0+532)=0; *(u8 *)((u8 *)arg0+534)=0;
    *(u32 *)((u8 *)arg0+536)=0; *(u32 *)((u8 *)arg0+540)=0; *(u32 *)((u8 *)arg0+1564)=0;
    *(u8 *)((u8 *)arg0+1202)=0; *(u8 *)((u8 *)arg0+1216)=0; *(u8 *)((u8 *)arg0+1217)=255;
    *(u8 *)((u8 *)arg0+1220)=0; *(u16 *)((u8 *)arg0+1248)=0; *(f32 *)((u8 *)arg0+1408)=v3;
    *(u8 *)((u8 *)arg0+1203)=0; *(u16 *)((u8 *)arg0+1222)=0; *(u8 *)((u8 *)arg0+1221)=0;
    *(u8 *)((u8 *)arg0+1497)=0; *(u8 *)((u8 *)arg0+1219)=0; *(u32 *)((u8 *)arg0+1276)=0;
    *(u8 *)((u8 *)arg0+1292)=4; *(f32 *)((u8 *)arg0+1308)=v3; *(f32 *)((u8 *)arg0+1304)=v3;
    *(f32 *)((u8 *)arg0+1236)=v3; *(f32 *)((u8 *)arg0+1240)=v3; *(f32 *)((u8 *)arg0+1492)=v3;
}
    *(u8 *)((u8 *)arg0+1293)=0; *(f32 *)((u8 *)arg0+1244)=v6; *(u8 *)((u8 *)arg0+1425)=0;
    *(u8 *)((u8 *)arg0+1426)=0; *(u8 *)((u8 *)arg0+1427)=0; *(u8 *)((u8 *)arg0+1295)=0;
    *(f32 *)((u8 *)arg0+1296)=v7;
    *(struct fn_1_22F90_Copy16 *)((u8 *)arg0+1476)=*(struct fn_1_22F90_Copy16 *)((u8 *)p+220);
    *(u32 *)((u8 *)arg0+1300)=-1; *(u8 *)((u8 *)arg0+1496)=0;
    lbl_8006DAEC(); v10=p->unk_C;
    *(f32 *)(0xE0000000+0x0C)=v10; *(f32 *)(0xE0000000+0x1C)=v10; *(f32 *)(0xE0000000+0x2C)=v10;
    lbl_8006DB74((u32)(arg0+236)); lbl_8006DB74((u32)(arg0+284)); fn_1_29968((Sig_fn_1_29968_Owner *)arg0);
    lbl_8006DC34((void *)(arg0+1312));
    *(f32 *)((u8 *)arg0+1324)=*(f32 *)((u8 *)arg0+124);
    *(f32 *)((u8 *)arg0+1340)=*(f32 *)((u8 *)arg0+128);
    *(f32 *)((u8 *)arg0+1356)=*(f32 *)((u8 *)arg0+132);
    lbl_8006DD14((u32)(arg0+1312),(void *)(arg0+1428)); lbl_8006DB30(); lbl_8006DAEC();
    if (*(s16 *)((u8 *)arg0+6)>40) { v11=p->unk_C; lbl_8006E0B4(v11,p->unk_1C,v11); }
    lbl_8006DB74((u32)(arg0+332)); lbl_8006DB74((u32)(arg0+1360)); lbl_8006DB30();
    v12=p->unk_C; *(f32 *)((u8 *)arg0+548)=v12; *(f32 *)((u8 *)arg0+552)=v12;
    *(u8 *)((u8 *)arg0+576)=0; *(u8 *)((u8 *)arg0+577)=0;
    *(f32 *)((u8 *)arg0+1184)=v12; *(f32 *)((u8 *)arg0+1188)=v12; *(f32 *)((u8 *)arg0+1192)=v12;
    if (arg1) { *(u32 *)arg0 &= 0x24000300; *(u8 *)((u8 *)arg0+1218)=0; *(f32 *)((u8 *)arg0+216)=v12;
      *(u8 *)((u8 *)arg0+1154)=0; *(u8 *)((u8 *)arg0+531)=0; *(u8 *)((u8 *)arg0+535)=0;
    } else { *(u32 *)arg0 &= 0x24010300; *(u32 *)((u8 *)arg0+1420) &= 1; }
    v13=p->unk_C; *(u32 *)((u8 *)arg0+1420) &= -945;
    { u8 *a=arg0, *b=arg0;
    for (i=0;i<4;i++,a+=0x5c,b+=0x30) {
      u8 *c=b+0x3b4;
      *(u32 *)(a+0x244)=0; *(f32 *)(a+0x288)=v13; *(f32 *)(a+0x29c)=v13;
      lbl_8006E1B0(a+0x24c,a+0x258); lbl_8006E1B0(a+0x24c,a+0x264);
      fzgx_live = p->unk_14;
      *(f32 *)(a+0x290)=v13; *(f32 *)(a+0x294)=v13; *(f32 *)(a+0x298)=v13;
      lbl_8006E1F0(a+0x27c,v13,fzgx_live,v13);
      fzgx_live = fn_1_22F90_read_pointer(p);
      lbl_8006E1F0(a+0x270,p->unk_C,fzgx_live,p->unk_C);
      lbl_8006E1D8((u32)(c+0xc), p->unk_C, (lab_t2 = p->unk_18), p->unk_C);
      lbl_8006E1B0(c,c+0x18);
      *(f32 *)(c+0x24)=v13; *(f32 *)(c+0x28)=v13; *(f32 *)(c+0x2c)=v13;
    } }
    for(i=0;i<4;i++) fn_1_235C8((Sig_fn_1_235C8_Fn_1_235C8 *)*(u32 *)(((1160) + (((u8 *)arg0) + (i*4)))));
    fn_1_23610((void *)*(u32 *)((u8 *)arg0+1176));
    fn_1_23640((Sig_fn_1_23640_Fn_1_23640 *)*(u32 *)((u8 *)arg0+1180),arg1);
}
#pragma opt_propagation reset

