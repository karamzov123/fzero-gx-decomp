#include "sasnd/sasnd.h"

extern void fn_800211E0(u32, u32);
extern void fn_800211EC(u32, u32);
extern u32 fn_800090A4(u32);
extern u32 lbl_801A6410;
extern u32 fn_80024DF0(void *);
extern u32 fn_80024378(void *);
extern s32 fn_800253F0(void *);
extern s32 fn_80025C70(void *);
extern u32 fn_80024D84(void *);
extern u32 fn_80024E3C(u32, void *);
extern u32 fn_80024308(void *);
extern void fn_800243C4(void *, void *);
extern s32 fn_800251F0(void *);
extern void fn_80025504(u32, u32);
extern void fn_80025C28(void *);
extern void fn_80025854(void *, void *);

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
if (lbl_801A6C80->chan[i].unk_0 != 0xFFFFFFFF &&
arg0 == lbl_801A6C80->chan[i].unk_E) {
found = i;
break;
}
}
if (found == 255) return;
if (lbl_801A6C80->unk_472 == arg0 && lbl_801A6C80->unk_473 == arg1) return;
resource = (u8 *)((u32)lbl_801A6C80 + found * 16);
resource = *(u8 **)(resource + 8);
table = (u32 *)(resource + *(u32 *)(resource + 0x30));
cursor = table;
for (i = 0; i <= (u32)arg1; i++) cursor++;
record = (u32 *)((u8 *)table + *cursor);
switch (lbl_801A6C80->unk_470) { case 0: fn_80024DF0(&lbl_801939B4); break; case 1: fn_80024378(&lbl_80193680); break; case 2: fn_800253F0(&lbl_80193404); break; case 3: fn_80025C70(&lbl_80193308); break; } fn_800211E0(0, 0) ;
switch (lbl_801A6C80->unk_471) { case 0: fn_80024DF0(&lbl_80193860); break; case 1: fn_80024378(&lbl_801934A0); break; case 2: fn_800253F0(&lbl_80193368); break; case 3: fn_80025C70(&lbl_801932A8); break; } fn_800211EC(0, 0) ;
lbl_801A6C80->unk_470 = record[0] >> 24;
lbl_801A6C80->unk_471 = record[0] >> 16;
lbl_801A6C80->unk_472 = arg0;
lbl_801A6C80->unk_473 = arg1;
if (lbl_801A6C80->unk_5B20 == -1) available = fn_800090A4(lbl_801A6410);
else available = fn_800090A4(lbl_801A6C80->unk_5B20 );
switch (lbl_801A6C80->unk_470 ) {
case 0:
lbl_801939B4.unk_13C = 0; lbl_801939B4.unk_148 = (record)[1] / 1000.0f; lbl_801939B4.unk_150 = (record)[2] / 1000.0f; lbl_801939B4.unk_14C = (record)[3] / 1000.0f; lbl_801939B4.unk_140 = (record)[4] / 1000.0f; lbl_801939B4.unk_144 = (record)[5] / 1000.0f ;
required = record[2] * 384 + 52536;
if (required <= available) {
fn_80024D84(&lbl_801939B4);
fn_800211E0((u32)fn_80024E3C, (u32)&lbl_801939B4);
} else { lbl_801A6C80->unk_470 = 255; if (lbl_801A6C80->callback != NULL) lbl_801A6C80->callback(-1, required - available) ; }
offset = 20;
break;
case 1:
lbl_80193680.unk_1C4 = 0; lbl_80193680.unk_1D0 = (record)[1] / 1000.0f; lbl_80193680.unk_1D8 = (record)[2] / 1000.0f; lbl_80193680.unk_1D4 = (record)[3] / 1000.0f; lbl_80193680.unk_1C8 = (record)[4] / 1000.0f; lbl_80193680.unk_1CC = (record)[5] / 1000.0f; lbl_80193680.unk_1DC = (record)[6] / 1000.0f ;
required = record[2] * 384 + 81328;
if (required <= available) {
fn_80024308(&lbl_80193680);
fn_800211E0((u32)fn_800243C4, (u32)&lbl_80193680);
} else { lbl_801A6C80->unk_470 = 255; if (lbl_801A6C80->callback != NULL) lbl_801A6C80->callback(-1, required - available) ; }
offset = 24;
break;
case 2:
lbl_80193404.unk_90 = (record)[1]; lbl_80193404.unk_94 = (record)[2]; lbl_80193404.unk_98 = (record)[3] ;
required = 5760;
if (available >= 5760) {
fn_800251F0(&lbl_80193404);
fn_800211E0((u32)fn_80025504, (u32)&lbl_80193404);
} else { lbl_801A6C80->unk_470 = 255; if (lbl_801A6C80->callback != NULL) lbl_801A6C80->callback(-1, required - available) ; }
offset = 12;
break;
case 3:
lbl_80193308.unk_3C = (record)[1]; lbl_80193308.unk_40 = (record)[2]; lbl_80193308.unk_44 = (record)[3]; lbl_80193308.unk_48 = (record)[4]; lbl_80193308.unk_4C = (record)[5]; lbl_80193308.unk_50 = (record)[6]; lbl_80193308.unk_54 = (record)[7]; lbl_80193308.unk_58 = (record)[8]; lbl_80193308.unk_5C = (record)[9] ;
required = (((record)[1] * 32 - 1) / 160 + ((record)[2] * 32 - 1) / 160 + ((record)[3] * 32 - 1) / 160) * 640 ;
if (required <= available) {
fn_80025C28(&lbl_80193308);
fn_800211E0((u32)fn_80025854, (u32)&lbl_80193308);
} else { lbl_801A6C80->unk_470 = 255; if (lbl_801A6C80->callback != NULL) lbl_801A6C80->callback(-1, required - available) ; }
offset = 36;
break;
}
if (lbl_801A6C80->unk_5B20 == -1) available = fn_800090A4(lbl_801A6410);
else available = fn_800090A4(lbl_801A6C80->unk_5B20 );
switch (lbl_801A6C80->unk_471 ) {
case 0: {
u32 *src = (u32 *)((u8 *)record + offset);
lbl_80193860.unk_13C = 0; lbl_80193860.unk_148 = (src)[1] / 1000.0f; lbl_80193860.unk_150 = (src)[2] / 1000.0f; lbl_80193860.unk_14C = (src)[3] / 1000.0f; lbl_80193860.unk_140 = (src)[4] / 1000.0f; lbl_80193860.unk_144 = (src)[5] / 1000.0f ;
required = src[2] * 384 + 52536;
if (required <= available) {
fn_80024D84(&lbl_80193860);
fn_800211EC((u32)fn_80024E3C, (u32)&lbl_80193860);
} else { lbl_801A6C80->unk_471 = 255; if (lbl_801A6C80->callback != NULL) lbl_801A6C80->callback(-2, required - available) ; }
break;
}
case 1: {
u32 *src = (u32 *)((u8 *)record + offset);
lbl_801934A0.unk_1C4 = 0; lbl_801934A0.unk_1D0 = (src)[1] / 1000.0f; lbl_801934A0.unk_1D8 = (src)[2] / 1000.0f; lbl_801934A0.unk_1D4 = (src)[3] / 1000.0f; lbl_801934A0.unk_1C8 = (src)[4] / 1000.0f; lbl_801934A0.unk_1CC = (src)[5] / 1000.0f; lbl_801934A0.unk_1DC = (src)[6] / 1000.0f ;
required = src[2] * 384 + 81328;
if (required <= available) {
fn_80024308(&lbl_801934A0);
fn_800211EC((u32)fn_800243C4, (u32)&lbl_801934A0);
} else { lbl_801A6C80->unk_471 = 255; if (lbl_801A6C80->callback != NULL) lbl_801A6C80->callback(-2, required - available) ; }
break;
}
case 2: {
u32 *src = (u32 *)((u8 *)record + offset);
lbl_80193368.unk_90 = (src)[1]; lbl_80193368.unk_94 = (src)[2]; lbl_80193368.unk_98 = (src)[3] ;
required = 5760;
if (available >= 5760) {
fn_800251F0(&lbl_80193368);
fn_800211EC((u32)fn_80025504, (u32)&lbl_80193368);
} else { lbl_801A6C80->unk_471 = 255; if (lbl_801A6C80->callback != NULL) lbl_801A6C80->callback(-2, required - available) ; }
break;
}
case 3: {
u32 *src = (u32 *)((u8 *)record + offset);
lbl_801932A8.unk_3C = (src)[1]; lbl_801932A8.unk_40 = (src)[2]; lbl_801932A8.unk_44 = (src)[3]; lbl_801932A8.unk_48 = (src)[4]; lbl_801932A8.unk_4C = (src)[5]; lbl_801932A8.unk_50 = (src)[6]; lbl_801932A8.unk_54 = (src)[7]; lbl_801932A8.unk_58 = (src)[8]; lbl_801932A8.unk_5C = (src)[9] ;
required = (((src)[1] * 32 - 1) / 160 + ((src)[2] * 32 - 1) / 160 + ((src)[3] * 32 - 1) / 160) * 640 ;
if (required <= available) {
fn_80025C28(&lbl_801932A8);
fn_800211EC((u32)fn_80025854, (u32)&lbl_801932A8);
} else { lbl_801A6C80->unk_471 = 255; if (lbl_801A6C80->callback != NULL) lbl_801A6C80->callback(-2, required - available) ; }
break;
}
}
} else {
switch (lbl_801A6C80->unk_470) { case 0: fn_80024DF0(&lbl_801939B4); break; case 1: fn_80024378(&lbl_80193680); break; case 2: fn_800253F0(&lbl_80193404); break; case 3: fn_80025C70(&lbl_80193308); break; } fn_800211E0(0, 0) ;
switch (lbl_801A6C80->unk_471) { case 0: fn_80024DF0(&lbl_80193860); break; case 1: fn_80024378(&lbl_801934A0); break; case 2: fn_800253F0(&lbl_80193368); break; case 3: fn_80025C70(&lbl_801932A8); break; } fn_800211EC(0, 0) ;
lbl_801A6C80->unk_470 = 255;
lbl_801A6C80->unk_471 = 255;
lbl_801A6C80->unk_472 = 255;
lbl_801A6C80->unk_473 = 255;
}
}
}
}
