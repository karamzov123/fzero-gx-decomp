/* Non-matching: best partial attempt (78.17% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/sel.h"

extern u8 lbl_1_bss_8B3A0[];
extern s16 lbl_1_bss_966;
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_8CA26;
extern const u32 lbl_10_rodata_30[6];
extern void fn_1_48140(int);
extern void fn_10_924C(void *);
extern u8 *fn_1_36AD0(void);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_12C0EC(void *);
extern void fn_1_151EF8(void *, s16, void *, s16, s16);
extern void fn_10_3954(void);
extern void fn_10_3A98(void);
extern void fn_10_3B44(void);
extern void fn_10_3C14(void);
extern void fn_1_12F10C(void *);
extern void fn_10_4D78(void);
extern u16 fn_1_A5D88(void);
extern void fn_1_12BF7C(void *, s16, u32, u32);
extern void fn_1_47F74(s32);
extern void fn_10_948C(void *, void *);
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, void (*)(void), u32, u32);
extern void fn_10_FF08(void);
extern void fn_1_4A00(u32, u32, u32);
extern void fn_1_12F1E8(s32);
extern int fn_1_B7F58(void *);
extern void fn_1_A2D84(u32);
extern void fn_1_13F81C(void);
extern void fn_1_13F948(void);
extern void fn_10_3DE0(u32, void *, s16);
extern void fn_1_FE004(void);
extern void fn_10_2324C(void);

#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define S16(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define U8(p,o) (*(u8 *)((u8 *)(p)+(o)))

void fn_10_3350(void) {
    u8 *data = (u8 *)&lbl_10_data_0;
    u8 *global;
    u8 *high;
    u8 *sel = (u8 *)&lbl_10_bss_0;
    s16 count = 4;
    s16 i;
    u32 table[5] = {0x80000000,0x80000000,0x40000000,0x20000000,0x20000000};
    u32 result[2];
    high = sel + 0x50000;
    fn_1_48140(159);
    global = (u8 *)&lbl_1_bss_8B3A0;
    if (!(U32(global,0x94) & 0x80000000) && lbl_1_bss_966 != 20)
        fn_10_924C((void *)U32(high,-0x6c80));
    if (lbl_1_bss_966 != 20 && lbl_1_bss_966 != 16) {
        for (i=0;i<4;i++) {
            fn_80008BEC(fn_1_36AD0() + i * 0x81c0,0,0x81c0);
            fn_1_12C0EC((u8 *)U32(lbl_1_bss_8B3A0,0xa4) + (lbl_1_bss_962-14)*0x94+i*0x1c+0x24);
        }
        for (i=0;i<9;i++)
            fn_80008BEC((u8 *)((u8 *)&lbl_10_bss_3C0)+i*0x81c0,0,0x81c0);
        U8(high,-0x6c70)=0;
        U8(high,-0x6c71)=0;
    }
    if (!U8(high,-0x6c71))
        for(i=41;i<=44;i++)
            fn_80008BEC((u8 *)((u8 *)&lbl_10_bss_3C0)+(i-41)*0x81c0,0,0x81c0);
    if (!U8(high,-0x6c70))
        for(i=45;i<=48;i++)
            fn_80008BEC((u8 *)((u8 *)&lbl_10_bss_3C0)+(i-41)*0x81c0,0,0x81c0);
    S16(sel,0x18)=19;
    S16(sel,0x1a)=6;
    if (U32(global,0x94)&0x40000000) {
        if (lbl_1_bss_8CA26==0) {
            S16(sel,0x18)=19;
            S16(sel,0x1a)=2;
            fn_1_151EF8(data+0x408,38,sel+0x1c,2,19);
        } else
            fn_1_151EF8(data+0x324,114,sel+0x1c,6,19);
    } else
        fn_1_151EF8(data+0x324,114,sel+0x1c,6,19);
    fn_10_3954();
    fn_10_3A98();
    fn_10_3B44();
    fn_10_3C14();
    fn_1_12F10C(((u8 *)&lbl_10_bss_3C0));
    for(i=0;i<4;i++) {
        U32(high,0x1768+i*8)=-1;
        U32(high,0x1758+i*4)=-1;
        U32(high,0x176c+i*8)=-1;
    }
    U32(data,0x45c)=table[S16(lbl_1_bss_8B3A0,4)];
    if (S16(lbl_1_bss_8B3A0,4)==0) {
        U32(global,0x94)|=0x08000000;
        S16(lbl_1_bss_8B3A0,0xe)=-1;
        S16(lbl_1_bss_8B3A0,0x2e)=-1;
        S16(lbl_1_bss_8B3A0,0x4e)=-1;
        S16(lbl_1_bss_8B3A0,0x6e)=-1;
        S16(lbl_1_bss_8B3A0,0xe+U8(lbl_1_bss_8B3A0,0x9e)*32)=6;
    } else fn_10_4D78();
    if (U32(global,0x94)&0x20000000) count=1;
    if (!(U32(global,0x94)&0x80000000)) {
        if(lbl_1_bss_966!=20) {
            fn_1_12BF7C(high+0x1788,1,fn_1_A5D88(),480);
            if ((U32(global,0x94)&0x40000000) && lbl_1_bss_8CA26==0) {
                fn_1_12BF7C(high+0x17ec,count,fn_1_A5D88(),480);
                if(U32(global,0x94)&0x1000)
                    fn_1_12BF7C(high+0x197c,count,fn_1_A5D88(),480);
                else
                    fn_1_12BF7C(high+0x197c,count,fn_1_A5D88()>>1,240);
            } else {
                fn_1_12BF7C(high+0x17ec,count,fn_1_A5D88()>>1,240);
                if(!(U32(global,0x94)&0x100))
                    fn_1_12BF7C(high+0x197c,count,fn_1_A5D88()>>1,240);
            }
            if(U32(global,0x94)&0x100) fn_1_47F74(160);
        }
        fn_10_948C(high-0x6c60,high-0x1140);
    }
    fn_1_435C(U32(high,-0x6c78));
    if(U32(high,0x1740)==-1)
        U32(high,0x1740)=fn_1_3F8C(data+0x66c,fn_10_FF08,0,8);
    fn_1_4A00(1,(u8)S16(high,-0x6c74),U32(high,-0x6c78));
    U32(high,0x1744)=0;
    U32(sel,0x14)=-1;
    U32(high,0x1b0c)=-1;
    U32(high,0x1b10)=90;
    if(lbl_1_bss_966!=16) fn_1_12F1E8(720);
    U8((void *)U32(lbl_1_bss_8B3A0,0xa4),0x19)=0;
    if(fn_1_B7F58(result)==1) fn_1_A2D84(0xa9122600);
    U8(lbl_1_bss_8B3A0,0x129)=1;
    if(U32(global,0x94)&0x40000000) {
        fn_1_13F81C();
        fn_1_13F948();
        for(i=4;i<8;i++)
            if(U8(((u8 *)&lbl_10_bss_3C0),i*0x81c0+7))
                fn_10_3DE0((u8)i,((u8 *)&lbl_10_bss_3C0),S16(data,0x456));
    }
    fn_1_13F81C();
    fn_1_13F948();
    for(i=0;i<8;i++) {
        if(U8(((u8 *)&lbl_10_bss_3C0),i*0x81c0+7)) {
            if(__rlwnm(U32(((u8 *)&lbl_10_bss_3C0),i*0x81c0),2,31,31))
                fn_10_3DE0((u8)i,((u8 *)&lbl_10_bss_3C0),S16(data,0x456));
            else
                fn_10_3DE0((u8)i,((u8 *)&lbl_10_bss_3C0),1);
        }
    }
    fn_1_FE004();
    fn_10_2324C();
}
