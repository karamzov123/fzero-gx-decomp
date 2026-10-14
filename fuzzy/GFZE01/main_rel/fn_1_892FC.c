/* Non-matching: best partial attempt (49.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"
#include "psvec.h"

extern const f32 lbl_1_rodata_3508[];
extern int fn_1_17C6C(int, int, int);
extern int fn_1_17FCC(int, int, int);
extern s16 fn_1_7B054(void);
extern u32 fn_1_15578(void *, void *, void *, void *, void *, u32, u32, u32, u32, u32);
extern u32 fn_1_17A9C(void *);
extern u32 fn_1_181CC(int, int, int);
extern u32 fn_1_181F0(int, int, int);
extern u32 fn_1_214C4(void *, u32, f32);
extern void *fn_1_14F04(void);
extern void fn_1_17920(int, int, f32);
extern void lbl_8006D7F4(f32, f32, f32);
extern void *lbl_8006DBAC(void *);
extern void lbl_8006E1D8(void *, f32, f32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DC6C(void *);
extern f32 lbl_8006D668(void *);

typedef struct { u8 pad[0x118]; u32 unk_118; u32 unk_11c; u8 pad2[0x20]; u32 unk_140; f32 unk_144; f32 unk_148; f32 unk_14c; f32 unk_150; u32 unk_154; u32 unk_158; } Child;
typedef struct { f32 x,y,z; } Vec;
typedef struct { f32 a,b; } Pair;
extern struct { u32 unk_0; u32 unk_4; u32 unk_8; u32 unk_C; } *lbl_801A6D00;
extern u32 lbl_801A66CC;

static f32 interp(int i, f32 t) {
    u32 *arr = (u32 *)lbl_1_bss_3BE0->unk_C;
    f32 *p = (f32 *)arr[i * 3 + 1];
    f32 d = p[17] - p[16];
    f32 m = t * d;
    return p[16] + m;
}

void fn_1_892FC(void *obj, f32 *arg1, f32 *arg2) {
    Child *child = *(Child **)((u8 *)obj + 0x49c);
    const f32 *k = lbl_1_rodata_3508;
    u32 count, idx, cur, next, j;
    f32 t, val, lo, hi;
    void *result;
    Vec a,b,n;
    f32 x,y,z;
    int mode;
    u32 mask, ok;
    f32 *raw;
    if (!lbl_1_bss_3BE0 || !child || (s32)child->unk_140 < 0) {
        lbl_8006D7F4(k[4], k[10], k[348]);
        return;
    }
    count = lbl_1_bss_3BE0->unk_8;
    idx = child->unk_140;
    t = child->unk_144;
    val = interp(idx,t);
    if ((s32)child->unk_118 > (s32)child->unk_154 || (s32)child->unk_11c > (s32)child->unk_158) {
        val = k[490];
        idx = fn_1_214C4(&t, idx, val);
    } else {
        child->unk_118 = child->unk_154;
        child->unk_11c = child->unk_158;
    }
    if (lbl_1_bss_3BE0->unk_7D) {
        if (k[490] > val) { val=k[490]; idx=fn_1_214C4(&t,idx,val); }
        else if (k[490] > * (f32 *)*(u32 *)(lbl_1_bss_3BE0->unk_0 + 0x90) - val) {
            val = *(f32 *)*(u32 *)(lbl_1_bss_3BE0->unk_0 + 0x90) - k[490];
            idx=fn_1_214C4(&t,idx,val);
        }
    } else {
        if (k[490] <= val && k[490] > *(f32 *)*(u32 *)(lbl_1_bss_3BE0->unk_0 + 0x90)-val) {
            val = *(f32 *)*(u32 *)(lbl_1_bss_3BE0->unk_0 + 0x90)-k[490];
            idx=fn_1_214C4(&t,idx,val);
        }
        if (child->unk_150 < k[4]) { val=k[490]; idx=fn_1_214C4(&t,idx,val); }
        else { val=*(f32 *)*(u32 *)(lbl_1_bss_3BE0->unk_0 + 0x90)-k[490]; idx=fn_1_214C4(&t,idx,val); }
    }
    next=fn_1_214C4(&t,idx,k[491]+val);
    if (next != idx && !fn_1_17FCC(next,idx,count)) idx=fn_1_214C4(&t,idx,val-k[491]);
    next=fn_1_214C4(&t,idx,val-k[491]);
    if (next != idx && !fn_1_17FCC(next,idx,count)) idx=fn_1_214C4(&t,idx,val+k[491]);
    mode=fn_1_7B054();
    if (mode==16 || fn_1_7B054()==28) {
        next=fn_1_214C4(&t,idx,k[492]+val);
        if (next!=idx && !fn_1_181CC(next,idx,count)) idx=fn_1_214C4(&t,idx,val-k[492]);
        next=fn_1_214C4(&t,idx,val-k[491]);
        if (next!=idx && !fn_1_181F0(next,idx,count)) idx=fn_1_214C4(&t,idx,val+k[491]);
    }
    next=fn_1_214C4(&t,idx,k[338]+val);
    if (next!=idx && !fn_1_17C6C(next,idx,count)) {
        for (j=0;j<count;j++) {
            cur=(idx+j+count)%count;
            cur=(cur+1)%count;
            if ((s32)cur==0) break;
            if (*(s8 *)((u8 *)*(u32 *)(((u8 *)lbl_1_bss_3BE0->unk_C)+(cur*12+4))+0x4d)==0 || (cur==0x8c && fn_1_7B054()==3)) {
                idx=cur; t=k[4]; val=interp(idx,t); break;
            }
        }
    }
    next=fn_1_214C4(&t,idx,val-k[490]);
    if (next!=idx && !fn_1_17C6C(next,idx,count)) idx=fn_1_214C4(&t,idx,val+k[490]);
    if (fn_1_7B054()==3 && (idx==63 || idx==62)) { idx=64;t=k[4];val=interp(idx,t); }
    if (fn_1_7B054()==35 && (idx==144 || (idx==145 && t<k[346]))) { idx=145;t=k[346];val=interp(idx,t); }
    mode=fn_1_7B054();
    if (mode==9) {
        for(j=0;j<4;j++) if(((f32 *)((u8 *)k+0x734))[j*2]-k[450]<val && ((f32 *)((u8 *)k+0x734))[j*2+1]+k[450]>val) { idx=fn_1_214C4(&t,idx,val); val=interp(idx,t); }
    }
    if (fn_1_7B054()==13) {
        for(j=0;j<7;j++) if(((f32 *)((u8 *)k+0x754))[j*2]-k[450]<val && ((f32 *)((u8 *)k+0x754))[j*2+1]+k[450]>val) { idx=fn_1_214C4(&t,idx,val); val=interp(idx,t); }
    }
    if (fn_1_7B054()==15) {
        Pair *p=(Pair *)&k[495];
        if(p->a-k[450]<val && p->b+k[450]>val) idx=fn_1_214C4(&t,idx,val);
    }
    result=fn_1_14F04();
    fn_1_17920(idx,0,t);
    mode=fn_1_17A9C((u8 *)child+0x148);
    if(fn_1_7B054()==27 && mode==2) mode=1;
    lbl_8006DBAC((u8 *)result+(mode<<7)+0x400);
    if(arg1) lbl_801A6D00->unk_4=*(u32 *)arg1;
    if(arg2) lbl_801A6D00->unk_8=*(u32 *)arg2;
    for(j=0;j<*(u32 *)((u8 *)result+0x1c);j++){ *(u32 *)((u8 *)child+j*4+0x120)=idx; *(f32 *)((u8 *)child+j*4+0x130)=t; }
    raw=(f32 *)&a;
    lbl_8006E1D8(&a,k[4],k[363],k[4]);
    lbl_8006E1D8(&b,k[4],k[493],k[4]);
    lbl_8006DAEC();
    mask=0x880001;
    if(mode<4) mask |= 0x80000000u>>mode;
    ok=fn_1_15578(&b,&a,&x,&y,obj,mask,*(u32 *)((u8 *)result+0x1c),0,0,0);
    lbl_8006DBE4();
    if(!ok) ok=fn_1_15578(&b,&a,&x,&y,obj,mask&0x7ffffff,*(u32 *)((u8 *)result+0x1c),0,0,0);
    lbl_8006DB30();
    if(!ok) { child->unk_140=idx; child->unk_144=t; return; }
    lbl_8006DC6C((u8 *)result+(*(u32 *)((u8 *)result+0x10c)<<7)+0x400);
    lbl_8006E0B4(k[4],k[343],k[4]);
}
