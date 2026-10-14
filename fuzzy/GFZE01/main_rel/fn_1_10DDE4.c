/* Non-matching: best partial attempt (17.76% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

typedef struct {
    u8 flag;
    u8 pad[15];
    f32 x;
    u8 pad2[4];
    f32 score;
    u8 pad3[36];
    f32 weight;
} Entry;
extern f32 fn_1_1289BC(const void *, const void *);
extern void fn_1_128884(void *, void *, int);
extern u32 fn_1_10846C(u32);
extern u32 fn_1_4630(u32, u32);
extern u32 lbl_801A6410;

void fn_1_10DDE4(u32 arg0, f32 arg1, f32 arg2) {
    u32 *obj = (u32 *)arg0;
    Entry *a;
    u32 n, lim, i, j, rounds, k, start, end;
    u32 *edges;
    if (!arg0) return;
    lim = (*(u32 *)(*(u32 *)(arg0 + 12) + 140) == 2) ? 7 : 13;
    fn_1_10846C(arg0);
    n = obj[6];
    a = (Entry *)obj[9];
    for (i=0;i<n;i++) {
        if (a[i].flag & 1) { a[i].flag=0; a[i].weight=-1.0f; }
        else { a[i].flag=1; a[i].weight=0.0f; }
    }
    for (i=0;i<n;i++) for (j=i+1;j<n;j++)
        if (a[i].flag==0 && a[j].flag!=0) fn_1_128884(&a[i],&a[j],68);
    for (i=0;i<n;i++) for (j=i+1;j<n;j++)
        if (a[i].flag==a[j].flag && a[i].x<a[j].x) fn_1_128884(&a[i],&a[j],68);
    for (i=0;i<lim;i++) for (j=i+1;j<lim;j++)
        if (a[i+3].score>a[j+3].score) fn_1_128884(&a[i+3],&a[j+3],68);
    start=0;
    for (i=0;i<n;i++) if (a[i].flag==0 || a[i+1].flag!=0) start+=68;
    end=start+68;
    rounds=(n-(u32)(((u64)0x78797879*(end-(u32)(u8 *)a))>>32)>>5)/lim;
    for (i=0;i<rounds;i++) {
        for (j=0;j<lim;j++) a[start/68+j].weight=-(f32)(i+1)/(f32)(rounds+1);
        for (j=0;j<lim;j++) for (k=j+1;k<lim;k++)
            if (a[start/68+j].score>a[start/68+k].score)
                fn_1_128884(&a[start/68+j],&a[start/68+k],68);
        start += lim*68;
    }
    obj[7]=((n-3)/lim*(lim-1))+((((n-3)/lim-1)*lim)+((lim-1)*2));
    obj[10]=fn_1_4630(lbl_801A6410,obj[7]*12);
    edges=(u32 *)obj[10];
    k=0;
    for (i=0;i<lim-1;i++) {
        Entry *p=&a[3+i];
        edges[k*3]= (u32)p; edges[k*3+1]=(u32)(p+1);
        edges[k*3+2]=fn_1_1289BC((void *)p,(void *)(p+1)); k++;
    }
    for (i=0;i<lim-1;i++) {
        Entry *p=&a[3+i];
        edges[k*3]=(u32)(p+1); edges[k*3+1]=(u32)(p+lim);
        edges[k*3+2]=fn_1_1289BC((void *)(p+1),(void *)(p+lim)); k++;
    }
    return;
}
