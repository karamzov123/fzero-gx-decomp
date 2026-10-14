/* Non-matching: best partial attempt (84.24% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
extern f32 lbl_3_rodata_768[384];
extern u32 lbl_1_rodata_26F8;
extern s32 fn_3_837C(s16);
extern u32 fn_3_1FF7C(void);
extern u32 fn_3_23A1C(u32, u32, u32, u32, u32);
extern u32 fn_3_2B750(s16, s16);
extern void fn_3_26A34(u32, u32, u32);
extern void fn_3_1C278(s16, void *, void *, void *, void *, f32);
extern void fn_1_133DBC(void *);
extern void fn_1_8D1EC(void *, void *, void *);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_138120(void *);
extern u32 fn_1_50190(void *, f32, f32, f32, f32, f32, f32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_49514(u32 *);
extern void *fn_1_14EEC4(s16, void *, s16);
extern char *fn_1_14EA74(void *, char *, s16);
extern int fn_1_14EE00(s16, void *, s16);
extern void fn_1_4AE0C(const char *, ...);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_5233C(void);

struct Copy88 { u32 x[22]; };
struct F0 { u8 pad[8]; s8 a; s16 b; };
struct B20 { u8 bytes[0x20]; };
struct B6 { u8 pad[4]; f32 val; s16 id; };
struct B241 {
 f32 a,b,c,d; u8 pad10[16]; f32 e,f; u8 pad28[16]; u8 x38; u8 pad39[31]; u32 x58;
};
extern struct F0 lbl_3_bss_F0;
extern struct B20 lbl_3_bss_20;
extern struct B6 lbl_3_bss_6D8C0[256];
extern struct B241 lbl_3_bss_241E0;
extern u8 lbl_3_data_4B84[0x14];
extern u32 lbl_3_data_4B98;

#pragma opt_common_subs off
#pragma opt_propagation off
#pragma peephole off
void fn_3_273F4(void) {
 struct F0 *p = (struct F0 *)&lbl_3_bss_F0;
 f32 *pool = lbl_3_rodata_768;
 s16 id = p->b;
 u32 loc_54[35];
 char textbuf[0x14];
 s16 selection;
 s16 car;
 s32 intx;
 char *str;
 u32 temp;
    u32 * lab_t0;
    f32 lab_t3;
    const char * lab_t0_;

 fn_1_133DBC((void *)1);
 lbl_3_bss_241E0.x38 = 0;
 lbl_3_bss_241E0.x58 = 0;
 lbl_3_bss_241E0.a = (*((pool) + (0x514/4)));
 lbl_3_bss_241E0.b = (*((pool) + (0x1d0/4)));
 lbl_3_bss_241E0.c = lbl_3_bss_241E0.e;
 lbl_3_bss_241E0.d = lbl_3_bss_241E0.f;
 fn_1_8D1EC(&lbl_3_bss_241E0, (void *)fn_3_1FF7C, 0);
 fn_1_134AD4();
 if (fn_3_837C(p->a) == 1) fn_1_13ABA8(0x28100000);
 else fn_1_13ABA8(0x28000000);
 fn_1_138120((void *)fn_3_2B750(45, id));
 fn_3_23A1C(90, 90, 10, 151, 1);

{
 struct B20 *menu = (struct B20 *)&lbl_3_bss_20;
 selection = *(s16 *)(menu->bytes + 0x18);
 car = (s16)(*((menu->bytes) + ((s32)selection * 20)));
}
 intx = (s32)(*((lbl_3_bss_6D8C0) + ((s16)car))).val;
 car = (*((lbl_3_bss_6D8C0) + ((s16)car))).id;
 *(struct Copy88 *)loc_54 = *(struct Copy88 *)((u8 *)&lbl_1_rodata_26F8 - 4);
 loc_54[1] = 0x8904;
 ((f32 *)loc_54)[23] = (*((pool) + (0x5ac/4)));
 ((f32 *)loc_54)[24] = (*((pool) + (0x51c/4)));
 ((f32 *)loc_54)[25] = (*((pool) + (0x60/4)));

 lab_t3 = (*((pool) + (0x180/4)));
 fn_1_50190((FontDrawPacket *)&loc_54[1], (*((pool) + (0x3f4/4))), (*((pool) + (0x5b0/4))), lab_t3, (*((pool) + (0x180/4))), (*((pool) + (0x564/4))), (*((pool) + (0x180/4))));
 fn_1_49410();
 fn_1_495B0(0x80000000);
 fn_1_4965C(2);
 fn_1_4955C((*((pool) + (0x1c/4))), (*((pool) + (0x1c/4))));
 fn_1_496FC((*((pool) + (0x418/4))), (*((pool) + (0x5b4/4))));
 fn_1_4954C((*((pool) + (0x5b8/4))));
 fn_1_49738((void *)fn_1_5233C);
 fn_1_49748((*((pool) + (0x188/4))));
 *(u32 *)textbuf = *(u32 *)((u8 *)pool + 0x59c);
 lab_t0 = (u32 *)textbuf;
 fn_1_49514(lab_t0);
 str = fn_1_14EEC4(selection, textbuf + 0, id);
 lab_t0_ = (const char *)lbl_3_data_4B84;
 fn_1_4AE0C(lab_t0_, str);
 fn_1_49410();
 fn_1_495B0(0x80000000);
 fn_1_4965C(2);
 fn_1_4955C((*((pool) + (0x1c/4))), (*((pool) + (0x1c/4))));
 if ((*(s16 volatile *)&(p->b)) /* Retail reloads this field. */ == 5 || p->b >= 0) fn_1_496FC((*((pool) + (0x5bc/4))), (*((pool) + (0x5b4/4))));
 else if (p->b == 0) fn_1_496FC((*((pool) + (0x5c0/4))), (*((pool) + (0x5b4/4))));
 fn_1_4954C((*((pool) + (0x5b8/4))));
 fn_1_49738((void *)fn_1_5233C);
 fn_1_49748((*((pool) + (0x188/4))));
 *(u32 *)textbuf = *(u32 *)((u8 *)pool + 0x5a0);
 lab_t0 = (u32 *)textbuf;
 fn_1_49514(lab_t0);
 lab_t0_ = (const char *)fn_3_2B750(0x20, id);
 fn_1_4AE0C(lab_t0_);
 fn_1_49410();
 fn_1_495B0(0x80000000);
 fn_1_4965C(2);
 fn_1_4955C((*((pool) + (0x1c/4))), (*((pool) + (0x1c/4))));
 if (id == 5 || id >= 5) fn_1_496FC((*((pool) + (0x404/4))), (*((pool) + (0x5b4/4))));
 else if (id == 0) fn_1_496FC((*((pool) + (0x5c4/4))), (*((pool) + (0x5b4/4))));
 fn_1_4954C((*((pool) + (0x5b8/4))));
 fn_1_49738((void *)fn_1_5233C);
 fn_1_49748((*((pool) + (0x188/4))));
 *(u32 *)textbuf = *(u32 *)((u8 *)pool + 0x5a4);
 lab_t0 = (u32 *)textbuf;
 fn_1_49514(lab_t0);
 lab_t0_ = (const char *)fn_3_2B750(0x21, id);
 fn_1_4AE0C(lab_t0_);
 fn_1_49410();
 fn_1_495B0(0x80000000);
 fn_1_4965C(2);
 fn_1_4955C((*((pool) + (0x1c/4))), (*((pool) + (0x1c/4))));
 fn_1_496FC((*((pool) + (0x418/4))), (*((pool) + (0x5c8/4))));
 fn_1_4954C((*((pool) + (0x5b8/4))));
 fn_1_49738((void *)fn_1_5233C);
 fn_1_49748((*((pool) + (0x188/4))));
 str = fn_1_14EA74((void *)car, textbuf, id);
 lab_t0_ = (const char *)lbl_3_data_4B84;
 fn_1_4AE0C(lab_t0_, str);
 fn_1_49410();
 fn_1_495B0(0x80000000);
 fn_1_4965C(2);
 fn_1_4955C((*((pool) + (0x1c/4))), (*((pool) + (0x1c/4))));
 fn_1_496FC((*((pool) + (0x5bc/4))), (*((pool) + (0x5c8/4))));
 fn_1_4954C((*((pool) + (0x5b8/4))));
 fn_1_49738((void *)fn_1_5233C);
 fn_1_49748((*((pool) + (0x188/4))));
 lab_t0_ = (const char *)&lbl_3_data_4B98;
 fn_1_4AE0C(lab_t0_, (s16)intx);
 fn_1_49410();
 fn_1_495B0(0x80000000);
 fn_1_4965C(2);
 fn_1_4955C((*((pool) + (0x1c/4))), (*((pool) + (0x1c/4))));
 fn_1_496FC((*((pool) + (0x5cc/4))), (*((pool) + (0x5c8/4))));
 fn_1_4954C((*((pool) + (0x5b8/4))));
 fn_1_49738((void *)fn_1_5233C);
 fn_1_49748((*((pool) + (0x188/4))));
 *(u32 *)textbuf = *(u32 *)((u8 *)pool + 0x5a8);
 lab_t0 = (u32 *)textbuf;
 fn_1_49514(lab_t0);
 str = (char *)fn_1_14EE00(car, textbuf, id);
 lab_t0_ = (const char *)lbl_3_data_4B84;
 fn_1_4AE0C(lab_t0_, str);
 fn_3_26A34(0xa6, 0xf8, 0xc8);
 *(struct Copy88 *)loc_54 = *(struct Copy88 *)((u8 *)&lbl_1_rodata_26F8 - 4);
 fn_1_4F734((FontDrawPacket *)&loc_54[1]);
 fn_3_1C278(*(s16 *)(lbl_3_bss_20.bytes + 0xce), (void *)(*((lbl_3_bss_20.bytes) + (0))), (void *)(*((lbl_3_bss_20.bytes) + (8))), (void *)(*((lbl_3_bss_20.bytes) + (0x10))), (void *)0, (*((pool) + (0x188/4))));
}
#pragma peephole reset

#pragma opt_propagation reset

#pragma opt_common_subs reset

