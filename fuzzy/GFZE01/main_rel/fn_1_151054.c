/* Non-matching: best partial attempt (82.65% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"

extern f32 lbl_1_rodata_CF40[];
extern u8 fn_1_58C4(void);
extern void fn_1_5948(int);
extern s16 camera_get_mode(void);
extern void *fn_1_8627C(s32);
extern void fn_1_627C(int);

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))

void fn_1_151054(Obj_1_data_2A7E0_At3C *obj) {
    int n, i;
    f32 value, f3, f4;
    s16 mode;
    void *camera;
    u32 *entry;
    Obj_1_data_2A7E0_At3C *p;
    if (W(obj, 0x2728) == 0 && W(obj, 0x272c) == -1) {
        n = fn_1_58C4();
        if (n == 1) {
            for (i = 0; i < n; i++) {
                fn_1_5948(i);
                mode = camera_get_mode();
                if (mode >= 0) {
                    camera = fn_1_8627C(mode);
                    if (camera != 0 && W(camera, 0x118) + 1 == 3) {
                        W(obj, 0x272c) = 0;
                        break;
                    }
                }
                fn_1_627C(i);
            }
        }
    }
    if (W(obj, 0x2728) == 0 && W(obj, 0x272c) != -1) {
        W(obj, 0x272c)++;
        if (W(obj, 0x272c) > 1000) {
            W(obj, 0x2728) = 1;
            W(obj, 0x272c) = -1;
        }
    }
    if (W(obj, 0x2728) != 0) {
        F(obj, 0x2740) = F(lbl_1_rodata_CF40, 0x54) + F(obj, 0x2740);
        if (F(obj, 0x2740) < F(lbl_1_rodata_CF40, 0x5c))
            F(obj, 0x2740) = F(lbl_1_rodata_CF40, 0x5c);
        else if (F(obj, 0x2740) > 1000.0f)
            F(obj, 0x2740) = F(lbl_1_rodata_CF40, 0x5c);
    }
    if (W(obj, 0x2728) != 0) {
        for (i = 0, p = obj; i < (s32)W(obj, 0x2724); i++, p = (Obj_1_data_2A7E0_At3C *)((u8 *)p + 0x3c)) {
            entry = (u32 *)W(p, 0x1858);
            if (B(p, 0x185c) || B(p, 0x185d)) {
                f32 t = F(obj, 0x2740), duration = F(obj, 0x2744), value;
                if (t < duration) {
                    F(p, 0x1828) = -30.0f * t / duration;
                } else {
                    f3 = (-30.0f * t / duration) + (15.0f * (t - duration) / duration);
                    f4 = 0.0f;
                    if (B(p, 0x185c))
                        f4 = (F(obj, 0x2734) - F(p, 0x1824)) * 0.01f;
                    else if (B(p, 0x185d))
                        f4 = (F(obj, 0x273c) - F(p, 0x1824)) * 0.01f;
                    if (f3 > f4) F(p, 0x1828) = f3;
                    else F(p, 0x1828) = f4;
                }
                if (F(p, 0x1828) > 0.0f || (F(p, 0x1828) == 0.0f && F(p, 0x182c) != 0.0f))
                    F(p, 0x1828) = 0.0f;
                if (B(p, 0x185c)) {
                    value = F(p, 0x1828) + F(p, 0x1824);
                    if (value < F(obj, 0x2734)) F(p, 0x1824) = F(obj, 0x2734);
                    else if (value > F(obj, 0x2730)) F(p, 0x1824) = F(obj, 0x2730);
                    else F(p, 0x1824) = value;
                    if (F(p, 0x1824) == F(obj, 0x2734)) F(p, 0x182c) = 1.0f;
                } else if (B(p, 0x185d)) {
                    value = F(p, 0x1828) + F(p, 0x1824);
                    if (value < F(obj, 0x273c)) F(p, 0x1824) = F(obj, 0x273c);
                    else if (value > F(obj, 0x2738)) F(p, 0x1824) = F(obj, 0x2738);
                    else F(p, 0x1824) = value;
                    if (F(p, 0x1824) == F(obj, 0x273c)) F(p, 0x182c) = 1.0f;
                }
            }
            if (B(p, 0x185d) || B(p, 0x185e)) {
                if (B(p, 0x185d)) {
                    if (F(obj, 0x2740) < F(obj, 0x2744)) {
                        F(p, 0x1840) = F(p, 0x184c) - F(p, 0x184c) * F(obj, 0x2740) / F(obj, 0x2744);
                        F(p, 0x1844) = F(p, 0x1850) - F(p, 0x1850) * F(obj, 0x2740) / F(obj, 0x2744);
                        F(p, 0x1848) = F(p, 0x1854) - F(p, 0x1854) * F(obj, 0x2740) / F(obj, 0x2744);
                    } else {
                        F(p, 0x1840) = 0.0f; F(p, 0x1844) = 0.0f; F(p, 0x1848) = 0.0f;
                    }
                }
                if (B(p, 0x185e)) {
                    f32 t = 0.9f * F(obj, 0x2740), d = F(obj, 0x2744);
                    if (t < d) F(p, 0x1840) = F(p, 0x184c);
                    else { value = F(p,0x184c) - F(p,0x184c)*(t-d)/d; if (value < 0.0f) value = 0.0f; F(p,0x1840)=value; }
                    if (t < d) F(p, 0x1844) = F(p, 0x1850);
                    else { value = F(p,0x1850) - F(p,0x1850)*(t-d)/d; if (value < 0.0f) value = 0.0f; F(p,0x1844)=value; }
                    if (t < d) F(p, 0x1848) = F(p, 0x1854);
                    else { value = F(p,0x1854) - F(p,0x1854)*(t-d)/d; if (value < 0.0f) value = 0.0f; F(p,0x1848)=value; }
                }
                F(p,0x1834) += F(p,0x1840);
                F(p,0x1838) += F(p,0x1844);
                F(p,0x183c) += F(p,0x1848);
                if (entry[0] && *(u32 *)(entry[0]+0x34)) *(f32 *)(*(u32 *)(entry[0]+0x34)+4)=60.0f*F(p,0x1834)/0.0f;
                if (entry[1] && *(u32 *)(entry[1]+0x34)) *(f32 *)(*(u32 *)(entry[1]+0x34)+4)=60.0f*F(p,0x1838)/0.0f;
                if (entry[2] && *(u32 *)(entry[2]+0x34)) *(f32 *)(*(u32 *)(entry[2]+0x34)+4)=60.0f*F(p,0x183c)/0.0f;
            }
            if (B(p,0x185c)) W(p,0x1858) &= 0x7fffffff;
            if (B(p,0x185f)) W(p,0x1858) |= 0x80000000;
        }
    }
    for (i = 0; i < (s32)W(obj, 0x2724); i++) {}
    for (p = obj, i = 0; i < (s32)W(obj,0x2724); i++, p=(Obj_1_data_2A7E0_At3C *)((u8 *)p+0x3c))
        if (B(p,0x185c) || B(p,0x185d)) *(f32 *)(W(p,0x1858)+0x10)=F(p,0x1830)+F(p,0x1824);
}
