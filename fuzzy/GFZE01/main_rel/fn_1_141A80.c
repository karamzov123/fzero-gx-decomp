/* Non-matching: best partial attempt (91.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"

#pragma pack(1)
struct fn_1_141A80_Copy104 { u32 words[27]; u16 half; u8 byte; };
#pragma pack()

struct fn_1_141A80_lbl_1_data_414D8 {
    u8 pad_0[0x1B0];
    Obj_1_bss_4B9CC *unk_1B0[1];
};
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_85F4;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_88B8;
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8600;
extern struct fn_1_141A80_lbl_1_data_414D8 lbl_1_data_414D8;
extern u32 fn_1_5233C(void *, void *);
extern u8 lbl_1_rodata_9248[112];
extern u32 lbl_801A66B4;
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4CE48(Obj_1_bss_4B9CC *);

#pragma opt_loop_invariants off
void fn_1_141A80(u32 arg0) {
    s16 v3;
    struct { u8 value; } v4;
    s16 v7;
    struct fn_1_141A80_Copy104 loc_8;
    loc_8 = *(struct fn_1_141A80_Copy104 *)lbl_1_rodata_9248;
    fn_1_49410();
    fn_1_49738((void *)fn_1_5233C);
    fn_1_49748(lbl_1_rodata_861C);
    fn_1_4955C(lbl_1_rodata_85EC, lbl_1_rodata_85EC);
    fn_1_496FC(lbl_1_rodata_88B8, lbl_1_rodata_8840);
    fn_1_495B0(0x80000000);
    fn_1_4CE48(lbl_1_data_414D8.unk_1B0[(s16)lbl_801A66B4]);
    v3 = (s16)arg0;
    v4.value = 1;
    while (v4.value <= ((u8 *)&loc_8)[(s16)arg0 < 0 ? 0 : (s16)arg0 > 110 ? 110 : v3]) {
        fn_1_496FC((f32)(s32)(v4.value * 18 + 300), *(&lbl_1_rodata_8840));
        fn_1_4A0D8(((const char *)&lbl_1_data_42194));
        v4.value++;
    }
}
#pragma opt_loop_invariants reset

