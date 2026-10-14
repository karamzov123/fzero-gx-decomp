/* Non-matching: best partial attempt (93.26% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/cloth.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[10] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFF0000FF, 0x00FF00FF, 0xFF0000FF, 0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
    s = 50.0f;
    s = 0.5f;
    s = 0.9998999834060669f;
}
static const u32 fzgx_pool_table3[4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1e-07;
    s = -1.0f;
    s = 0.0f;
    s = 16.950000762939453f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.95;
    d = -1.95;
    s = 1.5f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 0.6;
    d = 9.999999747378752e-05;
    s = 1.0f;
    s = 1.100000023841858f;
    s = 0.949999988079071f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    d = 0.0013611111376020642;
    s = 0.009999999776482582f;
    s = 0.0027222223579883575f;
    s = 9.999999747378752e-05f;
    s = 0.550000011920929f;
    s = 16.399999618530273f;
    s = 0.75f;
    s = 32768.0f;
    s = -16.399999618530273f;
    s = -0.75f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
extern void lbl_8006D758(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern u32 mathutil_mtxA_rotate_y(s32);
extern u32 mathutil_mtxA_rotate_z(s32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_8006D118(void *);
extern f32 lbl_8006D0B4(f32);
extern u32 fn_80077B14(void *);
extern f32 lbl_1_bss_BF0[32];
typedef struct { u32 x,y,z; } Words;
typedef struct { f32 x,y,z; } Vector;
#pragma opt_common_subs on
static inline f32 fn_1_102C08_operand(f32 right, f32 left) { return ((right) * (left)); }
#pragma opt_lifetimes on
static inline f32 fn_1_102C08_operand_(f32 right, f32 left) { left *= right; return left; }
static inline f32 fn_1_102C08_operand__(f32 left, f32 right) { left *= right; return left; }
void fn_1_102C08(void) {
    Obj_1_bss_85250_At18 *p2;
    u32 n;
    u32 j;
    struct { u32 value; } i;
    Obj_1_bss_85250_At20 *lp;
    Obj_1_bss_85250_At18 *a;
    Obj_1_bss_85250_At18 *b;
    Obj_1_bss_85250_At18 *p5;
    Obj_1_bss_85250_At18 *p4;
    u32 m;
    Obj_1_bss_85250_At18 *p1;
    u32 *points;
    f32 k;
    Obj_1_bss_85250 *B = &lbl_1_bss_85250;
    f32 ma;
    f32 sy;
    struct { f32 value; } sx;
    f32 scale;
    f32 root;
    f32 dz;
    f32 dy;
    f32 eps;
    f32 v[12];
    f32 d[4];
    f32 mb;
    f32 fzgx_live;
    lbl_8006D758();
    lbl_8006E0B4(16.3999996f,0.75f,0.0f);
    mathutil_mtxA_rotate_y((s32)(32768.0f*lbl_1_bss_BF0[10]));
    mathutil_mtxA_rotate_z((s32)(32768.0f*lbl_1_bss_BF0[11]));
    lbl_8006E0B4(-16.3999996f,-0.75f,0.0f);
    lbl_8006DB74(v);
    {
    void *obj = (void *)((u32 *)B->unk_10->unk_8)[B->unk_4*2];
    if (obj != 0) {
        points = (u32 *)fn_80077B14(obj);
        p1 = B->unk_18;
        for (n=0; n<B->unk_1C; n++,p1=(void *)((u8 *)p1+0x44)) {
            if (p1->unk_1 == 1 && !(p1->unk_0 & 1)) {
                *(Words *)&p1->unk_1C = *(Words *)&p1->unk_10;
                p1->unk_14 = p1->unk_14 + (p1->unk_38 - 0.0013611111376020642);
                if (p1->unk_14 < 0.00999999978f) p1->unk_14=0.00999999978f;
                p1->unk_38 -= 0.00272222236f;
            }
        }
        p2=B->unk_18;
        for (i.value=0; i.value<B->unk_1C; i.value++,p2=(void *)((u8 *)p2+0x44)) {
            if (p2->unk_1 != 1 || (p2->unk_0&1)) {
                lbl_8006D758();
                lbl_8006DFC4(v);
                lbl_8006E1B0(&p2->unk_28,&p2->unk_10);
            }
        }
        eps=9.99999975e-05f;
        lp=B->unk_20;
        for (i.value=0; i.value<B->unk_24; i.value++,lp=(void *)((u8 *)lp+0x18)) {
            a=(void *)lp->unk_0;
            b=(void *)lp->unk_4;
            {
                f32 dx;
                dx=*(f32 *)&a->unk_10-*(f32 *)&b->unk_10;
                dy=a->unk_14-b->unk_14;
                dz=a->unk_18;
                dz=dz-b->unk_18;
                d[1]=dx; d[2]=dy; d[3]=dz;
                d[0]=(f32)fn_1_102C08_operand_(dx,dx)+dy*dy+dz*dz;
            }
            if (d[0]-eps>lp->unk_8) {
                root=lbl_8006D118(d);
                scale=root*(d[0]-lbl_8006D0B4(lp->unk_8));
                sx.value=(*((d) + (1)))*scale;
                sy=d[2]*scale;
                {
                    f32 sz;
                    sz=fn_1_102C08_operand(scale,d[3]);
                    d[0]=scale; d[1]=sx.value; d[2]=sy; d[3]=sz;
                    ma=a->unk_40; mb=b->unk_40;
                    k=1.0f/(ma+mb);
                    fzgx_live=*(f32 *)&a->unk_10;
                    *(f32 *)&a->unk_10=fzgx_live-(f32)(sx.value*(ma*k));
                    a->unk_14=a->unk_14-(f32)(sy*(ma*k));
                    a->unk_18=a->unk_18-(f32)(sz*(ma*k));
                    *(f32 *)&b->unk_10=*(f32 *)&b->unk_10+(f32)(sx.value*fn_1_102C08_operand__(mb,k));
                    b->unk_14=b->unk_14+(f32)(sy*(mb*k));
                    b->unk_18=b->unk_18+(f32)(sz*(mb*k));
                }
            }
        }
        p4=B->unk_18;
        for (n=0; n<B->unk_1C; n++,p4=(void *)((u8 *)p4+0x44)) {
            p4->unk_34=*(f32 *)&p4->unk_10-*(f32 *)&p4->unk_1C;
            p4->unk_38=p4->unk_14-*(f32 *)&p4->unk_20;
            p4->unk_3C=p4->unk_18-*(f32 *)&p4->unk_24;
        }
        p5=B->unk_18;
        for (n=0; n<B->unk_1C; n++,p5=(void *)((u8 *)p5+0x44)) {
            u16 *idxs=(u16 *)&p5->unk_0;
            for (m=0; m<p5->unk_2; m++) {
                u32 *dst=&points[idxs[m+2]*16];
                *(Words *)dst=*(Words *)&p5->unk_10;
            }
        }
    }
}
}
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
