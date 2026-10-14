/* Non-matching: best partial attempt (94.37% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"
extern int fn_1_8623C(void);
extern u8 *fn_1_36AD0(void);
extern f32 lbl_1_rodata_3530[22];
extern void fn_1_FDC00(void *,void *,f32);
extern void fn_1_FDD7C(void *);
extern s32 fn_1_FDB40(void **);
extern void *fn_1_7F254(void *,s32);
extern u32 fn_1_FD844(u32,void *);
extern void *fn_1_435C(void *);
extern void fn_1_FE004(void);
extern void fn_1_FCFA4(void *);
extern s32 fn_1_3F8C(u32,u32,u32,u32);
extern u8 lbl_1_bss_6D854[16];
typedef struct { u8 pad[0x420]; u32 state; s32 (*query)(void **); void (*initialize)(void *,void *,f32); void (*destroy)(void *); u8 tail[0x10010]; } ClosureCarCallbacks;
typedef struct { void *owner; u8 type; u8 pad5[3]; f32 scale; u32 flags; u8 tail[0x10430]; } ClosureCarEntry;
#pragma opt_propagation off
void fn_1_82C70(void *arg0,u32 arg1,void *arg2,u32 arg3,u32 arg4) {
    u8 carId;
    u32 result=0;
    if(lbl_1_bss_8B3A0.unk_94 & (0x4000u << 16)) {
        carId=(u8)fn_1_8623C();
        if((u8)arg1 != carId) return;
    } else carId=(*(u8 **)((u8 *)arg2+0x32c))[0x474];
    if((*(s16 *)&lbl_1_bss_960)==2) {
        if(carId==0xff) return;
        result=(u32)(fn_1_36AD0()+(u32)carId*(0x10000-0x7e40));
    } else if((*(s16 *)&lbl_1_bss_960)==14) {
        u8 count=lbl_1_bss_525C.unk_F8;
        if(count>=3) result=*(u32 *)((u8 *)&lbl_1_bss_525C+(count<<3));
        else result=*(u32 *)((u8 *)&lbl_1_bss_525C+((u8)arg1<<3));
        if(!result) return;
        carId=0;
    } else if((*(s16 *)&lbl_1_bss_960)==12) {
        carId=0;
        arg4=1;
        result=(u32)fn_1_36AD0();
        if(*(u32 *)result & (0x8000u << 16)) {
            if(*(u32 *)result & (0x4000u << 16)) {
                if((s8)((u8 *)arg2)[0x328] != ((u8 *)result)[5]) return;
            } else if((s8)((u8 *)arg2)[0x328] != ((u8 *)result+0x10000-0x7e60)[0]) return;
        }
    }
    if(!((u8 *)result)[7]) return;

    {
        s32 mode_argument;
        ClosureCarCallbacks *cb = cb;
        f32 scale=lbl_1_rodata_3530[0];
        ((ClosureCarCallbacks *)((u8 *)arg3 + 0x10000u))[carId].query = fn_1_FDB40;
        ((ClosureCarCallbacks *)((u8 *)arg3 + 0x10000u))[carId].initialize = fn_1_FDC00;
        ((ClosureCarCallbacks *)((u8 *)arg3 + 0x10000u))[carId].destroy = fn_1_FDD7C;
        ((ClosureCarCallbacks *)((u8 *)arg3 + 0x10000u))[carId].state = 0;
        ((ClosureCarEntry *)arg3)[carId].type = 4;
        ((ClosureCarEntry *)arg3)[carId].owner = arg2;
        ((ClosureCarEntry *)arg3)[carId].scale = scale;
        ((ClosureCarEntry *)arg3)[carId].flags = 0x4000u << 16;
        if((*(s16 *)&lbl_1_bss_960)==14) {
            *(s16 *)((u8 *)arg2+0x3ba)=1;
            ((ClosureCarEntry *)arg3)[carId].flags=0x2000u << 16;
            mode_argument=2;
        } else if((u8)arg4==1) {
            *(s16 *)((u8 *)arg2+0x3ba)=0;
            mode_argument=5;
        } else {
            *(s16 *)((u8 *)arg2+0x3ba)=1;
            mode_argument=6;
        }
        *(u32 *)((u8 *)arg2+0x3a4)=(u32)fn_1_7F254((void *)result,mode_argument);
        if(*(u32 *)((u8 *)arg2+0x3a4)) {
            arg1=fn_1_FD844(result,&((ClosureCarEntry *)arg3)[carId]);
            if((u8)arg1) {
                fn_1_435C(arg0);
                fn_1_FE004();
                fn_1_3F8C((u32)lbl_1_data_206D8,(u32)fn_1_FCFA4,(u32)(&((ClosureCarEntry *)arg3)[carId]),18);
            }
            lbl_1_bss_6D854[0]=(u8)arg1;
        }
    }
}

#pragma opt_propagation reset
