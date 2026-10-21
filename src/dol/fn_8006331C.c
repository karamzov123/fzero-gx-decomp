


typedef signed long s32;


typedef unsigned char u8;


typedef unsigned long u32;


typedef float f32;


typedef struct {
u8 unk_0[0x10][0x10];
u8 pad_100[0x344];
u32 unk_444;
u8 pad_448[0x44];
u8 unk_48C[0xF][0x10];
u8 pad_57C[0xC];
u8 unk_588[0x40][0x20];
u8 unk_D88[0x10][0x10][0x4];
u8 pad_1188[0x280];
u8 unk_1408[0x40][0x118];
u8 pad_5A08[0x114];
u32 unk_5B1C;
u8 pad_5B20[0x8];
} Obj_801A6C80_Target;
extern Obj_801A6C80_Target *lbl_801A6C80;


struct Sig_fn_800253F0_fn_800253F0_Arg0 { u32 unk_0; };
struct Sig_fn_80024D84_fn_80024D84_Arg0 {
u8 pad_0[0x13C]; u8 unk_13C;
f32 unk_140, unk_144, unk_148, unk_14C, unk_150;
};
struct Sig_fn_80024308_fn_80024308_Arg0 {
u8 pad_0[0x1C4]; u8 unk_1C4;
f32 unk_1C8, unk_1CC, unk_1D0, unk_1D4, unk_1D8, unk_1DC;
};
struct Sig_fn_800251F0_Sig_fn_80025440_fn_80025440_Arg0;
typedef struct Sig_fn_80025C28_Fn80025C28State {
u8 _pad00[0x30]; u32 field30, field34, field38;
} Sig_fn_80025C28_Fn80025C28State;
struct Sig_fn_80024E3C_fn_80024E3C_Arg1;
struct Sig_fn_800243C4_fn_800243C4_Arg0;
struct Sig_fn_800243C4_fn_800243C4_Arg1;
typedef struct Sig_fn_80025854_Fn80025854Src Sig_fn_80025854_Fn80025854Src;
typedef struct Sig_fn_80025854_Fn80025854Args Sig_fn_80025854_Fn80025854Args;
extern u8 lbl_801939B4[340];
extern u8 lbl_80193680[480];
extern u8 lbl_80193404[156];
extern u8 lbl_80193308[96];
extern u8 lbl_80193860[340];
extern u8 lbl_801934A0[480];
extern u8 lbl_80193368[156];
extern u8 lbl_801932A8[96];
extern u32 fn_80024DF0(u32);
extern u32 fn_80024378(u32);
extern s32 fn_800253F0(struct Sig_fn_800253F0_fn_800253F0_Arg0 *);
extern s32 fn_80025C70(u32);
extern void fn_800211E0(u32, u32);
extern void fn_800211EC(u32, u32);
extern u32 lbl_801A6410;
extern u32 fn_800090A4(u32);


extern const f32 lbl_801A7318;
extern u32 fn_80024D84(struct Sig_fn_80024D84_fn_80024D84_Arg0 *);
extern u32 fn_80024E3C(u32, struct Sig_fn_80024E3C_fn_80024E3C_Arg1 *);
extern u32 fn_80024308(struct Sig_fn_80024308_fn_80024308_Arg0 *);
extern void fn_800243C4(struct Sig_fn_800243C4_fn_800243C4_Arg0 *, struct Sig_fn_800243C4_fn_800243C4_Arg1 *);
extern s32 fn_800251F0(struct Sig_fn_800251F0_Sig_fn_80025440_fn_80025440_Arg0 *);
extern void fn_80025504(u32, u32);
extern void fn_80025C28(Sig_fn_80025C28_Fn80025C28State *);
extern void fn_80025854(Sig_fn_80025854_Fn80025854Src *, Sig_fn_80025854_Fn80025854Args *);
void fn_8006331C(u8 arg0, u8 arg1, f32 arg2) {
u32 i;
u32 found = 255;
u32 *cursor;
u32 *table;
u32 *record;
u32 offset;
s32 available;
s32 required;
u8 *resource;
if (arg0 != 255 || (arg0 == 255 && arg1 == 127)) {
if (arg1 != 255) {
if (arg1 != 127) {
for (i = 0; i < 16; i++) {
if (*(u32 *)&lbl_801A6C80->unk_0[i][0] != 0xFFFFFFFF &&
arg0 == lbl_801A6C80->unk_0[i][14]) {
found = i;
break;
}
}
if (found == 255) return;
if ((lbl_801A6C80->pad_448[0x2A]) == arg0 && (lbl_801A6C80->pad_448[0x2B]) == arg1) return;
resource = (u8 *)((u32)lbl_801A6C80 + found * 16);
resource = *(u8 **)(resource + 8);
table = (u32 *)(resource + *(u32 *)(resource + 0x30));
cursor = table;
for (i = 0; i <= (u32)arg1; i++) cursor++;
record = (u32 *)((u8 *)table + *cursor);
switch ((lbl_801A6C80->pad_448[0x28])) { case 0: fn_80024DF0((u32)lbl_801939B4); break; case 1: fn_80024378((u32)lbl_80193680); break; case 2: fn_800253F0((struct Sig_fn_800253F0_fn_800253F0_Arg0 *)lbl_80193404); break; case 3: fn_80025C70((u32)lbl_80193308); break; } fn_800211E0(0, 0) ;
switch ((lbl_801A6C80->pad_448[0x29])) { case 0: fn_80024DF0((u32)lbl_80193860); break; case 1: fn_80024378((u32)lbl_801934A0); break; case 2: fn_800253F0((struct Sig_fn_800253F0_fn_800253F0_Arg0 *)lbl_80193368); break; case 3: fn_80025C70((u32)lbl_801932A8); break; } fn_800211EC(0, 0) ;
(lbl_801A6C80->pad_448[0x28]) = record[0] >> 24;
(lbl_801A6C80->pad_448[0x29]) = record[0] >> 16;
(lbl_801A6C80->pad_448[0x2A]) = arg0;
(lbl_801A6C80->pad_448[0x2B]) = arg1;
if ((*(s32 *)&lbl_801A6C80->pad_5B20[0]) == -1) available = fn_800090A4(lbl_801A6410);
else available = fn_800090A4((*(s32 *)&lbl_801A6C80->pad_5B20[0]) );
switch ((lbl_801A6C80->pad_448[0x28]) ) {
case 0:
(lbl_801939B4)[0x13C] = 0; (*(f32 *)((lbl_801939B4) + (0x148))) = (f32)(record)[1] / lbl_801A7318; (*(f32 *)((lbl_801939B4) + (0x150))) = (f32)(record)[2] / lbl_801A7318; (*(f32 *)((lbl_801939B4) + (0x14C))) = (f32)(record)[3] / lbl_801A7318; (*(f32 *)((lbl_801939B4) + (0x140))) = (f32)(record)[4] / lbl_801A7318; (*(f32 *)((lbl_801939B4) + (0x144))) = (f32)(record)[5] / lbl_801A7318 ;
required = record[2] * 384 + 52536;
if (required <= available) {
fn_80024D84((struct Sig_fn_80024D84_fn_80024D84_Arg0 *)lbl_801939B4);
fn_800211E0((u32)fn_80024E3C, (u32)lbl_801939B4);
} else { (lbl_801A6C80->pad_448[0x28]) = 255; if (lbl_801A6C80->unk_5B1C != 0) ((void (*)(s32, s32))lbl_801A6C80->unk_5B1C)(-1, required - available) ; }
offset = 20;
break;
case 1:
(lbl_80193680)[0x1C4] = 0; (*(f32 *)((lbl_80193680) + (0x1D0))) = (f32)(record)[1] / lbl_801A7318; (*(f32 *)((lbl_80193680) + (0x1D8))) = (f32)(record)[2] / lbl_801A7318; (*(f32 *)((lbl_80193680) + (0x1D4))) = (f32)(record)[3] / lbl_801A7318; (*(f32 *)((lbl_80193680) + (0x1C8))) = (f32)(record)[4] / lbl_801A7318; (*(f32 *)((lbl_80193680) + (0x1CC))) = (f32)(record)[5] / lbl_801A7318; (*(f32 *)((lbl_80193680) + (0x1DC))) = (f32)(record)[6] / lbl_801A7318 ;
required = record[2] * 384 + 81328;
if (required <= available) {
fn_80024308((struct Sig_fn_80024308_fn_80024308_Arg0 *)lbl_80193680);
fn_800211E0((u32)fn_800243C4, (u32)lbl_80193680);
} else { (lbl_801A6C80->pad_448[0x28]) = 255; if (lbl_801A6C80->unk_5B1C != 0) ((void (*)(s32, s32))lbl_801A6C80->unk_5B1C)(-1, required - available) ; }
offset = 24;
break;
case 2:
(*(u32 *)((lbl_80193404) + (0x90))) = (record)[1]; (*(u32 *)((lbl_80193404) + (0x94))) = (record)[2]; (*(u32 *)((lbl_80193404) + (0x98))) = (record)[3] ;
required = 5760;
if (available >= 5760) {
fn_800251F0((struct Sig_fn_800251F0_Sig_fn_80025440_fn_80025440_Arg0 *)lbl_80193404);
fn_800211E0((u32)fn_80025504, (u32)lbl_80193404);
} else { (lbl_801A6C80->pad_448[0x28]) = 255; if (lbl_801A6C80->unk_5B1C != 0) ((void (*)(s32, s32))lbl_801A6C80->unk_5B1C)(-1, required - available) ; }
offset = 12;
break;
case 3:
(*(u32 *)((lbl_80193308) + (0x3C))) = (record)[1]; (*(u32 *)((lbl_80193308) + (0x40))) = (record)[2]; (*(u32 *)((lbl_80193308) + (0x44))) = (record)[3]; (*(u32 *)((lbl_80193308) + (0x48))) = (record)[4]; (*(u32 *)((lbl_80193308) + (0x4C))) = (record)[5]; (*(u32 *)((lbl_80193308) + (0x50))) = (record)[6]; (*(u32 *)((lbl_80193308) + (0x54))) = (record)[7]; (*(u32 *)((lbl_80193308) + (0x58))) = (record)[8]; (*(u32 *)((lbl_80193308) + (0x5C))) = (record)[9] ;
required = (((record)[1] * 32 - 1) / 160 + ((record)[2] * 32 - 1) / 160 + ((record)[3] * 32 - 1) / 160) * 640 ;
if (required <= available) {
fn_80025C28((Sig_fn_80025C28_Fn80025C28State *)lbl_80193308);
fn_800211E0((u32)fn_80025854, (u32)lbl_80193308);
} else { (lbl_801A6C80->pad_448[0x28]) = 255; if (lbl_801A6C80->unk_5B1C != 0) ((void (*)(s32, s32))lbl_801A6C80->unk_5B1C)(-1, required - available) ; }
offset = 36;
break;
}
if ((*(s32 *)&lbl_801A6C80->pad_5B20[0]) == -1) available = fn_800090A4(lbl_801A6410);
else available = fn_800090A4((*(s32 *)&lbl_801A6C80->pad_5B20[0]) );
switch ((lbl_801A6C80->pad_448[0x29]) ) {
case 0: {
u32 *src = (u32 *)((u8 *)record + offset);
(lbl_80193860)[0x13C] = 0; (*(f32 *)((lbl_80193860) + (0x148))) = (f32)(src)[1] / lbl_801A7318; (*(f32 *)((lbl_80193860) + (0x150))) = (f32)(src)[2] / lbl_801A7318; (*(f32 *)((lbl_80193860) + (0x14C))) = (f32)(src)[3] / lbl_801A7318; (*(f32 *)((lbl_80193860) + (0x140))) = (f32)(src)[4] / lbl_801A7318; (*(f32 *)((lbl_80193860) + (0x144))) = (f32)(src)[5] / lbl_801A7318 ;
required = src[2] * 384 + 52536;
if (required <= available) {
fn_80024D84((struct Sig_fn_80024D84_fn_80024D84_Arg0 *)lbl_80193860);
fn_800211EC((u32)fn_80024E3C, (u32)lbl_80193860);
} else { (lbl_801A6C80->pad_448[0x29]) = 255; if (lbl_801A6C80->unk_5B1C != 0) ((void (*)(s32, s32))lbl_801A6C80->unk_5B1C)(-2, required - available) ; }
break;
}
case 1: {
u32 *src = (u32 *)((u8 *)record + offset);
(lbl_801934A0)[0x1C4] = 0; (*(f32 *)((lbl_801934A0) + (0x1D0))) = (f32)(src)[1] / lbl_801A7318; (*(f32 *)((lbl_801934A0) + (0x1D8))) = (f32)(src)[2] / lbl_801A7318; (*(f32 *)((lbl_801934A0) + (0x1D4))) = (f32)(src)[3] / lbl_801A7318; (*(f32 *)((lbl_801934A0) + (0x1C8))) = (f32)(src)[4] / lbl_801A7318; (*(f32 *)((lbl_801934A0) + (0x1CC))) = (f32)(src)[5] / lbl_801A7318; (*(f32 *)((lbl_801934A0) + (0x1DC))) = (f32)(src)[6] / lbl_801A7318 ;
required = src[2] * 384 + 81328;
if (required <= available) {
fn_80024308((struct Sig_fn_80024308_fn_80024308_Arg0 *)lbl_801934A0);
fn_800211EC((u32)fn_800243C4, (u32)lbl_801934A0);
} else { (lbl_801A6C80->pad_448[0x29]) = 255; if (lbl_801A6C80->unk_5B1C != 0) ((void (*)(s32, s32))lbl_801A6C80->unk_5B1C)(-2, required - available) ; }
break;
}
case 2: {
u32 *src = (u32 *)((u8 *)record + offset);
(*(u32 *)((lbl_80193368) + (0x90))) = (src)[1]; (*(u32 *)((lbl_80193368) + (0x94))) = (src)[2]; (*(u32 *)((lbl_80193368) + (0x98))) = (src)[3] ;
required = 5760;
if (available >= 5760) {
fn_800251F0((struct Sig_fn_800251F0_Sig_fn_80025440_fn_80025440_Arg0 *)lbl_80193368);
fn_800211EC((u32)fn_80025504, (u32)lbl_80193368);
} else { (lbl_801A6C80->pad_448[0x29]) = 255; if (lbl_801A6C80->unk_5B1C != 0) ((void (*)(s32, s32))lbl_801A6C80->unk_5B1C)(-2, required - available) ; }
break;
}
case 3: {
u32 *src = (u32 *)((u8 *)record + offset);
(*(u32 *)((lbl_801932A8) + (0x3C))) = (src)[1]; (*(u32 *)((lbl_801932A8) + (0x40))) = (src)[2]; (*(u32 *)((lbl_801932A8) + (0x44))) = (src)[3]; (*(u32 *)((lbl_801932A8) + (0x48))) = (src)[4]; (*(u32 *)((lbl_801932A8) + (0x4C))) = (src)[5]; (*(u32 *)((lbl_801932A8) + (0x50))) = (src)[6]; (*(u32 *)((lbl_801932A8) + (0x54))) = (src)[7]; (*(u32 *)((lbl_801932A8) + (0x58))) = (src)[8]; (*(u32 *)((lbl_801932A8) + (0x5C))) = (src)[9] ;
required = (((src)[1] * 32 - 1) / 160 + ((src)[2] * 32 - 1) / 160 + ((src)[3] * 32 - 1) / 160) * 640 ;
if (required <= available) {
fn_80025C28((Sig_fn_80025C28_Fn80025C28State *)lbl_801932A8);
fn_800211EC((u32)fn_80025854, (u32)lbl_801932A8);
} else { (lbl_801A6C80->pad_448[0x29]) = 255; if (lbl_801A6C80->unk_5B1C != 0) ((void (*)(s32, s32))lbl_801A6C80->unk_5B1C)(-2, required - available) ; }
break;
}
}
} else {
switch ((lbl_801A6C80->pad_448[0x28])) { case 0: fn_80024DF0((u32)lbl_801939B4); break; case 1: fn_80024378((u32)lbl_80193680); break; case 2: fn_800253F0((struct Sig_fn_800253F0_fn_800253F0_Arg0 *)lbl_80193404); break; case 3: fn_80025C70((u32)lbl_80193308); break; } fn_800211E0(0, 0) ;
switch ((lbl_801A6C80->pad_448[0x29])) { case 0: fn_80024DF0((u32)lbl_80193860); break; case 1: fn_80024378((u32)lbl_801934A0); break; case 2: fn_800253F0((struct Sig_fn_800253F0_fn_800253F0_Arg0 *)lbl_80193368); break; case 3: fn_80025C70((u32)lbl_801932A8); break; } fn_800211EC(0, 0) ;
(lbl_801A6C80->pad_448[0x28]) = 255;
(lbl_801A6C80->pad_448[0x29]) = 255;
(lbl_801A6C80->pad_448[0x2A]) = 255;
(lbl_801A6C80->pad_448[0x2B]) = 255;
}
}
}
}
