/* Non-matching: best partial attempt (77.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/customize/toolkit.h"

extern f32 lbl_3_rodata_768[];
extern u32 lbl_1_rodata_26F8;
extern void fn_3_1C8D0(s16, void *, f32);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_49738(void *);
extern void fn_1_495A0(f32);
extern u32 fn_1_14FEAC(s16, s16, s16, void *, s32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_494DC(s16);
extern void fn_1_4962C(void);
extern void fn_1_49514(u32 *);
extern int fn_1_14EE00(s16, void *, s16);
extern s16 fn_1_14EF40(s16, s16, s16);
extern void *fn_1_14F6F8(s16, s16, s16, void *);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_51914(const u32 *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_51990(void *);
extern u32 fn_1_13EF64(u32,u32,u32,void *,u32,void *,void *,f32);
extern void fn_1_136714(f32,f32,f32,s32,s32,s32,s32,void *);
extern u32 fn_3_2B750(s16,s16);

void fn_3_1C278(s16 arg0, s16 arg1, s16 arg2, s16 arg3, void *arg4, f32 arg5) {
    f32 *pool = lbl_3_rodata_768;
    s32 mode;
    s16 textid;
    FontDrawPacket p;
    u8 q[0x100];
    u32 word;
    s32 idx, rem;
    f32 x, y;
    if (arg1 == -1 || arg2 == -1 || arg3 == -1) {
        fn_3_1C8D0(arg0, arg4, arg5);
        return;
    }
    mode = lbl_3_bss_F0.unk_A;
    if (mode == 5) {
        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_4965C(2);
        fn_1_495C8(1);
        fn_1_4955C(pool[7], pool[7]);
        fn_1_496FC(pool[8], pool[9]);
        fn_1_4954C(pool[10]);
        if (arg4) fn_1_49738(arg4);
        fn_1_495A0(arg5);
        fn_1_14FEAC(arg1,arg2,arg3,&p,mode);
        fn_1_4AE0C((const char *)&lbl_3_data_4B70, (char *)&p);
    }
    fn_1_49410();
    fn_1_495C8(9);
    fn_1_494DC(0x23);
    fn_1_4962C();
    fn_1_4955C(pool[11], pool[11]);
    fn_1_496FC(pool[8], pool[12]);
    fn_1_4954C(pool[10]);
    if (arg4) fn_1_49738(arg4);
    fn_1_495A0(arg5);
    fn_1_14FEAC(arg1,arg2,arg3,&p,0);
    fn_1_4AE0C((const char *)&lbl_3_data_4B70, (char *)&p);
    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4954C(pool[10]);
    fn_1_4955C(pool[13],pool[13]);
    word = *(u32 *)((u8 *)pool + 0x14);
    fn_1_49514(&word);
    if (arg4) fn_1_49738(arg4);
    fn_1_495A0(arg5);
    fn_1_496FC(pool[14],pool[15]);
    fn_1_14EE00(*(s16 *)((u8 *)&lbl_3_bss_6D8C0 + 8 + (s16)arg1 * 16), &p, mode);
    fn_1_4AE0C((const char *)&lbl_3_data_4B70, (char *)&p);
    fn_1_496FC(pool[14],pool[16]);
    fn_1_14EE00(*(s16 *)((u8 *)&lbl_3_bss_6D8C0 + 8 + (s16)arg3 * 16), &p, mode);
    fn_1_4AE0C((const char *)&lbl_3_data_4B70, (char *)&p);
    fn_1_496FC(pool[14],pool[17]);
    fn_1_14EE00(*(s16 *)((u8 *)&lbl_3_bss_6D8C0 + 8 + (s16)arg2 * 16), &p, mode);
    fn_1_4AE0C((const char *)&lbl_3_data_4B70, (char *)&p);
    textid = fn_1_14EF40(arg1,arg2,arg3);
    fn_1_14F6F8(arg1,arg2,arg3,&q);
    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4954C(pool[10]);
    fn_1_4955C(pool[18],pool[13]);
    if (arg4) fn_1_49738(arg4);
    fn_1_495A0(arg5);
    fn_1_496FC(pool[19],pool[20]);
    fn_3_2B750(0x1a,0);
    fn_1_4AE0C((const char *)&lbl_3_data_4B70);
    fn_1_496FC(pool[19],pool[15]);
    fn_3_2B750(0x1d,0);
    fn_1_4AE0C((const char *)&lbl_3_data_4B70);
    fn_1_496FC(pool[19],pool[21]);
    fn_3_2B750(0x1b,0);
    fn_1_4AE0C((const char *)&lbl_3_data_4B70);
    p = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    p.image = (0x10000 - 31485);
    p.x = pool[22]; p.y = pool[23]; p.z = pool[24];
    p.flags = 10;
    if (arg4) { p.flags |= 0x400; *(u32 *)((u8 *)&p + 0x50) = (u32)arg4; }
    p.alpha = arg5;
    fn_1_4F734(&p);
    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_496FC(pool[25],pool[26]);
    fn_1_4954C(pool[10]);
    fn_1_4955C(pool[13],pool[13]);
    if (arg4) fn_1_49738(arg4);
    fn_1_495A0(arg5);
    fn_1_4AE0C((const char *)&lbl_3_data_4B74, (s16)textid);
    fn_1_136714(pool[10],pool[27],arg5, (s16)textid,300,381,2,arg4);
    p = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    p.image = (0x10000 - 31485);
    p.x = pool[28]; p.y = pool[29]; p.z = pool[30];
    p.flags = 10;
    fn_1_51914((const u32 *)&p);
    p = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    p.flags = 10;
    fn_1_51564(0,0,120,120,6,7);
    fn_1_5158C(&p, *(u32 *)&p, 0, 0);
    p.x *= pool[35];
    p.y *= pool[35];
    p.z = pool[33];
    p.alpha = pool[34];
    fn_1_51990(&p);
    if (arg4) { p.flags |= 0x400; *(u32 *)((u8 *)&p + 0x50) = (u32)arg4; }
    p.alpha = arg5;
    fn_1_4F734(&p);
    fn_1_13EF64(0x1fb,0x16a,0x64,&q,(u32)(0x10000-30458),&p, &word, pool[36]*arg5);
}
