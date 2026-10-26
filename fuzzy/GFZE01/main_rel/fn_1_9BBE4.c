/* Non-matching: best partial attempt (32.09% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/burner.h"

typedef struct { u8 pad[0x60]; } Obj;
typedef struct { u8 pad[0xC]; f32 x; s16 a,b; u32 c; } Vec;
typedef struct { u32 flags; s32 count; void *entries; } EffectTable;
typedef struct { u32 flags; s32 count; void *nodes; } EffectManager;
typedef struct { u8 pad[0xC]; f32 zero; u8 pad2[0x30]; f64 one; u8 pad3[0xC]; f32 one32, frac, step, neg; } Floats;
extern Floats lbl_1_rodata_41F0;
extern u32 lbl_1_bss_38460[21];
extern u32 lbl_1_bss_6EA58[4], lbl_1_bss_6EA68[4];
extern Obj_1_bss_3BE0_Target *lbl_1_bss_3BE0;
extern u32 *lbl_801A66CC;
extern s16 fn_1_7B054(void);
extern s32 fn_1_6F84(void), fn_1_9D230(u32);
extern void GXInvalidateTexAll(void), fn_1_566EC(int,int), fn_800720B0(int);
extern void fn_1_9AF80(void *,int,int), fn_1_9CCE8(int), fn_1_9CD6C(Vec *,f32);
extern void fn_1_5638C(u32), fn_1_5631C(const u32 *), fn_1_5616C(int,f32,f32);
extern void fn_1_56000(u8,u8,u8), fn_1_56018(int), fn_1_55FC4(f32), fn_1_55FF0(f32);
extern void fn_1_556B8(void *), fn_1_553C4(void *,void *), fn_1_55210(void *), fn_1_55678(void *);
extern void fn_1_9D3E8(void *,void *,void *), fn_80077E0C(void *), fn_80076134(void), fn_80077E7C(void *);
extern void fn_80072558(void), lbl_8006DB30(void), lbl_8006DFC4(void *);
extern void lbl_8006DCA4(void), lbl_8006DAEC(void), lbl_8006E0A4(Vec *), lbl_8006E13C(void *);
extern void lbl_8006D1BC(int,void *,void *), lbl_8006D9E8(f32,f32,f32), lbl_8006DFE8(void *);
extern void mathutil_mtxA_rotate_z(int), mathutil_mtxA_rotate_y(int), mathutil_mtxA_rotate_x(int);
extern u32 fn_1_7A240(EffectTable *,void *,f32 *,void *,f32);
extern u32 fn_1_79E54(void *,void *,f32 *,u32,f32);
extern u32 fn_1_79C88(EffectManager *,u32 *,s32,f32);
extern s32 fn_1_54F5C(Vec *,f32,f32);
extern void fn_1_D7724(void *,s16), fn_1_D76F0(const f32 *,s16), fn_1_D7758(void *,f32);
extern u32 fn_1_20A5C(void *,void *);
extern u32 fn_1_15578(void *,void *,void *,void *,u32,void *,int,int);
extern void fn_8006E250(void *);

void fn_1_9BBE4(Obj *items, s32 first, s32 last, void *external)
{
    u8 *cfg=(u8 *)&lbl_1_data_2A0C0;
    u8 *base=(u8 *)&items[first];
    int special=0, saved=0, shadow=0;
    int i, n=first;
    u32 flags, bits;
    f32 scale, alpha;
    void *effect;
    u8 temp[0x80];
    u32 vec[3], pos[3], matrix[3], result;
    if (*(u32 *)(cfg+0x7b0+0x90) && fn_1_9D230(*(u32 *)items)) special=1;
    *(u32 *)(temp+0xc)=0;
    fn_1_566EC(1,255);
    fn_800720B0(0);
    if (!external) {
        GXInvalidateTexAll();
        if (fn_1_7B054()==17 && fn_1_6F84()) {
            u8 *obj=(u8 *)*(u32 *)((u8 *)lbl_1_bss_3BE0+0);
            u8 *p=(u8 *)*(u32 *)(obj+0x68);
            saved=1; *(u32 *)(temp+0xc)=1;
            lbl_1_bss_6EA58[0]=*(u32 *)(p+0x190); lbl_1_bss_6EA58[1]=*(u32 *)(p+0x194);
            lbl_1_bss_6EA58[2]=*(u32 *)(p+0x198); lbl_1_bss_6EA58[3]=*(u32 *)(p+0x19c);
            lbl_1_bss_6EA68[0]=*(u32 *)(p+0x2a0); lbl_1_bss_6EA68[1]=*(u32 *)(p+0x2a4);
            lbl_1_bss_6EA68[2]=*(u32 *)(p+0x2a8); lbl_1_bss_6EA68[3]=*(u32 *)(p+0x2ac);
            *(u32 *)(p+0x190)=*(u32 *)(cfg+0x2b0c);
            *(u32 *)(p+0x194)=*(u32 *)(cfg+0x2b10);
            *(u32 *)(p+0x198)=*(u32 *)(cfg+0x2b14);
            *(u32 *)(p+0x19c)=*(u32 *)(cfg+0x2b18);
        }
    }
    for (; n<=last; n++,base+=0x40) {
        flags=*(u32 *)base;
        if ((flags&0x40000) || *(u32 *)(base+0x38)) fn_1_9AF80(base,1,0);
        if (!(flags&0x800000) || !(*(u32 *)(base+4)&*(u32 *)(cfg+0x770+0x50))) continue;
        if ((flags&0xe0) && ! (flags&*(u32 *)(cfg+0x770+0x48))) continue;
        if (flags&1) continue;
        if (external) { lbl_8006DFE8(external); scale=lbl_1_rodata_41F0.one32; }
        else {
            if (flags&0x100000) {
                lbl_8006D1BC((n-first)<<12,&alpha,&scale);
                lbl_8006D9E8(alpha,lbl_1_rodata_41F0.zero,scale);
            } else lbl_8006DCA4();
            effect=*(void **)(base+0x3c);
            if (effect) lbl_8006DFC4(effect);
            else {
                lbl_8006E0A4((Vec *)(base+0xc));
                mathutil_mtxA_rotate_z(*(s16 *)(base+0x1c));
                mathutil_mtxA_rotate_y(*(s16 *)(base+0x1a));
                mathutil_mtxA_rotate_x(*(s16 *)(base+0x18));
                lbl_8006E13C(base+0x20);
            }
            scale=*(f32 *)(base+0x20);
            if (*(f32 *)(base+0x24)>scale) scale=*(f32 *)(base+0x24);
            if (*(f32 *)(base+0x28)>scale) scale=*(f32 *)(base+0x28);
            if (flags&0x300) fn_1_9CCE8((flags>>8)&3);
        }
        effect=*(void **)(base+8); bits=*(u32 *)effect;
        if (bits&0x100) result=fn_1_7A240(effect,&alpha,(f32 *)(temp+0x2c),cfg+0x27c0,scale);
        else if (*(u32 *)(cfg+0x7a8)>=3 && special && !(flags&0x200000) && !(bits&0x40))
            result=fn_1_7A240(effect,&alpha,(f32 *)(temp+0x2c),cfg+0x2830,scale);
        else if (bits&0x40) result=fn_1_79E54(effect,&alpha,(f32 *)(temp+0x2c),*(u32 *)(cfg+0x7a4),scale);
        else { result=fn_1_79C88(effect,(u32 *)&alpha,*(u32 *)(cfg+0x7a4),scale); alpha=1.0f; }
        if (!result) continue;
        if (flags&0x400) fn_1_9CD6C((Vec *)((u8 *)result+8),*(f32 *)(result+0x14)*scale);
        fn_80072558();
        if (flags&0x100000) fn_1_56000(1,3,0);
        fn_1_55FC4(scale); fn_1_55FF0(*(f32 *)(temp+0x2c));
        if (flags&0x200) { fn_1_56000(1,3,0); fn_1_556B8((void *)result); fn_1_56000(1,3,1); fn_1_55FC4(scale); fn_1_55FF0(*(f32 *)(temp+0x2c)); fn_1_55210((void *)result); shadow=0; }
        else if (flags&0x80010) { fn_1_566EC(1,128); fn_1_55210((void *)result); fn_1_566EC(1,255); shadow=0; }
        else { fn_1_55210((void *)result); shadow=0; }
    }
    if (shadow) fn_1_56018(0);
    fn_1_566EC(0,0);
    if (saved) {
        u8 *obj=(u8 *)*(u32 *)lbl_1_bss_3BE0, *p=(u8 *)*(u32 *)(obj+0x68);
        for(i=0;i<4;i++){ *(u32 *)(p+0x190+i*4)=lbl_1_bss_6EA58[i]; *(u32 *)(p+0x2a0+i*4)=lbl_1_bss_6EA68[i]; }
    }
}
