/* Non-matching: best partial attempt (92.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern void fn_1_49410(void);
extern const f64 lbl_1_rodata_8600;
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern u32 lbl_1_rodata_8A08;
extern void fn_1_49514(u32*);
extern void fn_1_5233C(void);
extern void fn_1_49738(void*);
extern const f32 lbl_1_rodata_863C;
extern void fn_1_49748(f32);
extern const f32 lbl_1_rodata_85E8;
extern void fn_1_4954C(f32);
extern void fn_1_495C8(void*);
extern f32 lbl_1_rodata_8850;
extern void fn_1_4CF3C(void*, f32, ...);
extern void* fn_1_12F118(void);
extern void* fn_1_36AD0(void);
extern void* fn_1_7F49C(s16, s16, void*);
extern void fn_1_4962C(void);
extern void* fn_1_14FEAC(u32, u32, u32, void*, s16);

typedef struct {
    s32 unk_0;
    u8 unk_4[0x819C];
    u8 unk_81A0;
    u8 unk_81A1[3];
    u8 unk_81A4;
    u8 unk_81A5[7];
    u8 unk_81AC;
    u8 unk_81AD[7];
    u8 unk_81B4;
    u8 unk_81B5[11];
} Rec;

#pragma opt_dead_assignments off
void fn_1_136174(f32 arg7, f32 arg8, s16 arg0, s16 arg1, void* arg2, s16 arg3,
                 s16 arg4, s16 arg5, int arg6) {
    Rec* p;
    f32 lab_t1;
    void* lab_t0;
    char buf[32];
    u32 local;

    if (arg4 == 0) return;
    if (arg3 < 0) return;

    fn_1_49410();
    fn_1_496FC((f32)arg0, (f32)arg1);
    fn_1_4955C(arg7, arg8);
    local = lbl_1_rodata_8A08;
    fn_1_49514(&local);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(lbl_1_rodata_863C);
    fn_1_4954C(lbl_1_rodata_85E8);
    fn_1_495C8(arg2);

    if (arg6 != 0) {
        lab_t1 = lbl_1_rodata_8850;
        lab_t0 = &lbl_1_data_41AB8;
        fn_1_4CF3C(lab_t0, lab_t1);
        return;
    }

    if (arg3 >= 41) {
        p = (Rec*)fn_1_12F118();
        if ((void*)p == fn_1_36AD0()) {
            p = &p[arg5];
        } else {
            p = &p[arg3 - 41];
        }
        if (!(p->unk_0 & 0x40000000)) {
            lab_t0 = &lbl_1_data_41A30;
            fn_1_4CF3C(lab_t0, lbl_1_rodata_8850, fn_1_7F49C(p->unk_81A0, arg4, buf));
        } else {
            fn_1_496FC((f32)arg0, (f32)arg1);
            fn_1_4962C();
            lab_t0 = &lbl_1_data_41A30;
            fn_1_4CF3C(lab_t0, lbl_1_rodata_8850, fn_1_14FEAC(p->unk_81A4, p->unk_81AC, p->unk_81B4, buf, arg4));
        }
    } else {
        lab_t0 = &"%s\n";
        fn_1_4CF3C(lab_t0, lbl_1_rodata_8850, fn_1_7F49C(arg3, arg4, buf));
    }
}
#pragma opt_dead_assignments reset

