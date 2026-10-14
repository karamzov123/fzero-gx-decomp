/* Non-matching: best partial attempt (54.01% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern f32 fn_1_A6FE8(void);
extern const f64 lbl_1_rodata_178;
extern const f64 lbl_1_rodata_180;
extern void fn_1_8D08(void *, f32);
extern void fn_1_8A0C(s16);
extern u32 fn_1_EBE4(void *, s32, s32);
extern void fn_1_EE04(void *);

struct Cfg_56B8 {
    u8 f00;
    u8 f01;
    s16 f02;
    u8 pad03;
    s16 f04;
    s16 f06;
    s16 f08;
    u8 pad0A[8];
    s16 f12;
    s16 f14;
    u8 pad16[0x1CA];
};

#define CAM_CFG (*(struct Cfg_56B8 *)(*(u32 *)((u8 *)self + 8)))

#define CP (&CAM_CFG)

void fn_1_56B8(void) {
    Obj_1_bss_F68_Target *self = (Obj_1_bss_F68_Target *)&lbl_1_bss_F68;
    void *ent;
    u32 n = 0;
    u32 flag = 0;
    u32 t;
    struct Cfg_56B8 tmp;

    switch ((s8)((Obj_1_bss_F68_Target *)self->unk_0)->unk_48) {
    case 0:
        n = 1;
        break;
    case 1:
    case 2:
        n = 2;
        break;
    case 3:
    case 4:
    case 5:
    case 7:
        n = 3;
        break;
    case 6:
        n = 3;
        flag = 1;
        break;
    case 8:
        n = 4;
        break;
    case 9:
        flag = 1;
        break;
    case 10:
        n = 1;
        flag = 1;
        break;
    case 11:
        n = 0;
        flag = 0;
        break;
    }

    ent = *(void **)&self->unk_4;
    for (t = 0; t / 0x100 < n; t++) {
        s8 m;
        f32 f;

        f = fn_1_A6FE8();
        m = (s8)((Obj_1_bss_F68_Target *)self->unk_0)->unk_48;
        if (m == 1 || (t / 0x100 == 0 && m == 3) || (t / 0x100 == 1 && m == 4)
            || (t / 0x100 == 2 && m == 5)) {
            f = (f32)(f * lbl_1_rodata_178);
        }
        if (m == 2) {
            f = (f32)(f * lbl_1_rodata_180);
        }
        fn_1_8D08(ent, f);
        fn_1_8A0C((s16)(t / 0x100));
        ent = (void *)((u8 *)ent + 0x1FC);
    }

    if (flag) {
        fn_1_A6FE8();
        tmp = CAM_CFG;
        fn_1_EBE4(CP, 0, 0);
        CAM_CFG.f00 = tmp.f00;
        CAM_CFG.f01 = tmp.f01;
        CAM_CFG.f02 = tmp.f02;
        CAM_CFG.f04 = tmp.f04;
        CAM_CFG.f06 = tmp.f06;
        CAM_CFG.f08 = tmp.f08;
        CAM_CFG.f12 = tmp.f12;
        CAM_CFG.f14 = tmp.f14;
        fn_1_EE04(CP);
    }
}
