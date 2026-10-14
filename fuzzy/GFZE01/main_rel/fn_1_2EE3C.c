/* Non-matching: best partial attempt (86.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/stcoli.h"
extern int fn_1_B7E98(int);
extern u32 fn_1_F45B4(void);
extern u32 fn_1_F22D4(void);
extern void fn_1_A2DC4(u32);
extern u32 lbl_1_rodata_D6C[35];
struct MenuState {
u8 pad0[0x20]; u8 unk_20; u8 pad21[9]; s16 unk_2A;
u8 pad2c[9]; u8 unk_35; u8 pad36[0x14ce]; u8 unk_1504;
u8 pad1505[0x11f]; u8 unk_1624; u8 pad1625[15]; u8 unk_1634;
};
struct Selection { u8 pad0[5]; u8 unk_5; };
#pragma opt_common_subs off
s32 fn_1_2EE3C(void) {
u8 *p_data = (u8 *)&lbl_1_data_5730;
struct MenuState *p = (struct MenuState *)&lbl_1_bss_3C00;
u8 *state = (u8 *)p + 0x20000;
s32 result = 0;
u16 e10, e12, e8, bits, flags;
s32 sel, i, n, rem;
flags = *(u16 *)(state + 0x1FE6);
*(u16 *)(state + 0x1FE8) &= ~0x300;
if (flags & 0x300) {
if (fn_1_B7E98(0) == 0 && fn_1_B7E98(1) == 0) {
*(u16 *)(state + 0x1FE8) |= 0x300;
} else {
if ((fn_1_F45B4() & 0xFF) == 0 || p->unk_1624 != 0)
*(u16 *)(state + 0x1FE8) |= 0x100;
if ((s32)fn_1_F22D4() != 0 || p->unk_1634 != 0) {
u16 temp = *(u16 *)(state + 0x1FE8);
p->unk_1634 = 1;
*(u16 *)(state + 0x1FE8) = temp | 0x200;
}
}
}
if (*(u16 *)(state + 0x1FE6) & 0x80) {
if ((fn_1_F45B4() & 0xFF) == 0 || p->unk_1624 != 0)
*(u16 *)(state + 0x1FE8) |= 0x80;
}
e10 = (&lbl_1_bss_9F8.unk_10)[p->unk_20 * 10];
if (((e10 >> 3) & 1) != 0 ||
(((e12 = (&lbl_1_bss_9F8.unk_12)[p->unk_20 * 10]) >> 3) & 1) != 0) {
bits = *(u16 *)(state + 0x1FE6);
n = (s8)p->unk_1504 + 13;
for (i = 0; i < 13; i++) {
rem = n % 14;
if (bits & (1 << rem)) { p->unk_1504 = rem; break; }
n--;
}
fn_1_A2DC4(0xA9011300);
} else if (((e10 >> 2) & 1) != 0 || ((e12 >> 2) & 1) != 0) {
bits = *(u16 *)(state + 0x1FE6);
n = (s8)p->unk_1504 + 1;
for (i = 0; i < 13; i++) {
rem = n % 14;
if (bits & (1 << rem)) { p->unk_1504 = rem; break; }
n++;
}
fn_1_A2DC4(0xA9011300);
}
e8 = (&lbl_1_bss_9F8.unk_8)[p->unk_20 * 10];
if (((e8 >> 8) & 1) != 0 && (*(u16 *)(state + 0x1FE8) & (sel = 1 << (s8)p->unk_1504)) == 0) {
*(s32 *)(state + 0x1FEC) = sel;
result = 1;
if (sel == 1) fn_1_A2DC4(0xA9011000);
else fn_1_A2DC4(0xA9011100);
switch (*(s32 *)(state + 0x1FEC)) {
case 0x2000: {
u8 mode = ((struct Selection *)((u8 *)p + 0x30))->unk_5;
*(u32 *)(state + 0x1FF4) = 1;
result = 0;
*(u32 *)(state + 0x2038) = 1;
*(s32 *)(state + 0x1FEC) = -2;
switch (mode) {
case 1: *(u32 *)(state + 0x203C) = (u32)(p_data + 0xAD4); break;
case 2: *(u32 *)(state + 0x203C) = (u32)(p_data + 0xAEC); break;
case 5: *(u32 *)(state + 0x203C) = (u32)(p_data + 0xB04); break;
default: *(u32 *)(state + 0x203C) = (u32)(p_data + 0xB1C); break;
}
break;
}
case 8:
if (p->unk_2A < 0x2A) {
*(u32 *)(state + 0x1FF4) = 1; result = 0;
*(s32 *)(state + 0x1FEC) = -2;
*(u32 *)(state + 0x2038) = 1;
*(u32 *)(state + 0x203C) = (u32)(p_data + 0xB30);
} break;
case 0x20:
if (p->unk_2A < 0x2A) {
*(u32 *)(state + 0x1FF4) = 1; result = 0;
*(s32 *)(state + 0x1FEC) = -2;
*(u32 *)(state + 0x2038) = 1;
*(u32 *)(state + 0x203C) = (u32)(p_data + 0xB44);
} break;
case 0x40:
*(u32 *)(state + 0x1FF4) = 1; result = 0;
*(s32 *)(state + 0x1FEC) = -2;
*(u32 *)(state + 0x2038) = 1;
*(u32 *)(state + 0x203C) = (u32)(p_data + 0xB60); break;
case 0x1000:
*(u32 *)(state + 0x1FF4) = 1; result = 0;
*(s32 *)(state + 0x1FEC) = -2;
*(u32 *)(state + 0x2038) = 1;
*(u32 *)(state + 0x203C) = (u32)(p_data + 0xB80); break;
}
} else {
e8 = (&lbl_1_bss_9F8.unk_8)[p->unk_20 * 10];
if (((e8 >> 9) & 1) != 0 || ((e8 >> 12) & 1) != 0) {
if (*(u16 *)(state + 0x1FE6) & 1) {
*(u32 *)(state + 0x1FEC) = 1; result = 1;
fn_1_A2DC4(0xA9011000);
}
}
}
if (*(u32 *)(state + 0x1FF4) != 0) {
u8 *pair = state + 0x2028;
*(u32 *)(pair + 4) = lbl_1_rodata_D6C[0];
*(u32 *)(state + 0x2028) = lbl_1_rodata_D6C[0];
}
return result;
}
