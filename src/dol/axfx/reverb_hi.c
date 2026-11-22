#include "types.h"

typedef void (*AXFXFreeFn)(u32);

struct ReverbHiParam {
    u8 pad_0[0x1A8];
    f32 crosstalk;
    u8 pad_1AC[0x18];
    u8 active;
    f32 coloration;
    f32 mix;
    f32 time;
    f32 damping;
    f32 predelay;
    f32 crosstalk_param;
};

struct ReverbHiBuf {
    u32 left;
    s32 right;
    u32 surround;
};

extern u32 lbl_801A64FC;
extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);
extern u32 fn_80023684(struct ReverbHiParam *, f32, f32, f32, f32, f32, f32);
extern void fn_80023B70(u32, u32, f32, f32);
extern void fn_80023D00(u32, u32, u32);

#pragma peephole off
void fn_8002420C(u8 *arg0) {
    u8 i;

    for (i = 0; i < 9; i++) {
        ((AXFXFreeFn)lbl_801A64FC)(*(u32 *)(arg0 + i * 0x14 + 0xc));
    }

    for (i = 0; i < 9; i++) {
        ((AXFXFreeFn)lbl_801A64FC)(*(u32 *)(arg0 + i * 0x14 + 0xc0));
    }

    if (*(s32 *)(arg0 + 0x1a4) != 0) {
        for (i = 0; i < 3; i++) {
            ((AXFXFreeFn)lbl_801A64FC)(*(u32 *)(arg0 + i * 4 + 0x1ac));
        }
    }
}

u32 fn_80024308(struct ReverbHiParam *arg0) {
    u32 v1;
    u32 v0;

    v0 = OSDisableInterrupts();
    arg0->active = 0;
    v1 = fn_80023684(arg0, arg0->coloration, arg0->time, arg0->mix, arg0->damping, arg0->predelay, arg0->crosstalk_param);
    OSRestoreInterrupts(v0);
    return v1;
}

u32 fn_80024378(u32 arg0) {
    u32 t0;
    t0 = OSDisableInterrupts();
    fn_8002420C((u8 *)arg0);
    OSRestoreInterrupts(t0);
    return 1;
}

#pragma opt_common_subs off
#pragma opt_dead_assignments off
void fn_800243C4(struct ReverbHiBuf *arg0, struct ReverbHiParam *arg1) {
    u32 i;
    s32 v5;
    s32 v4;
    s32 v3;
    f64 v1;
    f64 v0;
    f64 v2;

    if (!arg1->active) {
        v3 = arg0->surround;
        v4 = arg0->right;
        v5 = arg0->left;

        v1 = (1.0f);
        v0 = (0.5f);
        v2 = (0.0f);
        i = 0;
        while ((((0xFF) & i)) < 3) {
            switch ((((0xFF) & i))) {
            case 0:
                if ((0.0f) != arg1->crosstalk) {
                    f32 t = (0.5f) * arg1->crosstalk;
                    fn_80023B70(v5, v4, t, (1.0f) - t);
                }
                fn_80023D00(v5, (u32)arg1, 0);
                break;
            case 1:
                fn_80023D00(v4, (u32)arg1, 1);
                break;
            case 2:
                fn_80023D00(v3, (u32)arg1, 2);
                break;
            }
            i++;
        }
    }
}
#pragma opt_dead_assignments reset
#pragma opt_common_subs reset
#pragma peephole reset
