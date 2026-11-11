/* RESEARCH ONLY: fn_1_82C70
 * Objdiff 77.0%; 45 differing aligned rows. Not an exact match.
 * Excluded from the canonical build. Do not mark matching or submit without a fresh object check and linked checksum gate.
 */
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
typedef struct { u8 pad[0x420]; u32 state; u32 query; u32 initialize; u32 destroy; u8 tail[0x10010]; } ClosureCarCallbacks;
typedef struct { u32 owner; u8 type; u8 pad5[3]; f32 scale; u32 flags; u8 tail[0x10430]; } ClosureCarEntry;
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
        ClosureCarCallbacks *base=&((ClosureCarCallbacks *)((u8 *)arg3+0x10000))[carId];
        ClosureCarEntry *entry=&((ClosureCarEntry *)arg3)[carId];
        s32 mode_argument;
        base->state=0;
        base->initialize=(u32)fn_1_FDC00;
        base->destroy=(u32)fn_1_FDD7C;
        base->query=(u32)fn_1_FDB40;
        entry->type=4;
        entry->owner=(u32)arg2;
        entry->scale=lbl_1_rodata_3530[0];
        entry->flags=0x4000u << 16;
        if((*(s16 *)&lbl_1_bss_960)==14) {
            *(s16 *)((u8 *)arg2+0x3ba)=1;
            entry->flags=0x2000u << 16;
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
            arg1=fn_1_FD844(result,entry);
            if((u8)arg1) {
                fn_1_435C(arg0);
                fn_1_FE004();
                fn_1_3F8C((u32)lbl_1_data_206D8,(u32)fn_1_FCFA4,(u32)entry,18);
            }
            lbl_1_bss_6D854[0]=(u8)arg1;
        }
    }
}
