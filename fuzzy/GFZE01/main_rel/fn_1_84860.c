/* Non-matching: best partial attempt (74.68% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/burner.h"

extern const f32 lbl_1_rodata_3508[];
extern u8 lbl_1_data_20894[20];
extern s16 fn_1_7B054(void);
extern u32 fn_1_1FB80(void *, u32);
extern void OSReport(const char *, ...);
extern void fn_1_55FD0(f32, f32, f32);
extern f32 fn_1_86A2C(void *);
extern void fn_1_8E244(void *);
extern void lbl_8006DFE8(void *);
extern s32 fn_1_54E34(void *, f32);
extern void fn_1_566EC(int, int);
extern s32 fn_1_3EFA8(void);
extern void fn_1_A77DC(void *);
extern void fn_1_A7854(void *, void *);
extern u8 *fn_1_36AD0(void);
extern void fn_1_151BDC(u32);
extern void fn_1_86E08(void *);
extern void fn_1_5631C(const u32 *);
extern void fn_80072558(void);
extern s16 fn_1_847A8(s16, s16);
extern void fn_1_55210(void *);
extern int fn_1_A728C(int);
extern void fn_1_870BC(void *, s32, void *, s32, u32, f32);
extern u32 fn_1_5745C(void *, void *);

typedef struct {
    u8 pad[0x390];
    u32 flags;
    u8 pad394[0x34];
    u8 unk_3c8[0x10];
    u8 unk_3d8[0x30];
    s16 substate;
    u8 pad_3bc[2];
    u8 pad_3be[0x12];
    u8 pad_3d0[0x28];
} Obj;
typedef struct {
    u8 pad[4];
    s16 index;
    s16 sub;
} State;
typedef struct { u8 pad[0x18]; u32 color; } ColorEntry;
extern Obj_1_bss_3BE0_Target *lbl_1_bss_3BE0;
extern u8 lbl_1_bss_6D820;
extern Obj_1_data_2B0D4 lbl_1_data_2B0D4;

void fn_1_84860(Obj *obj) {
    u32 flags;
    State *state;
    s8 effect;
    void *entry;
    s32 ramp;
    f32 alpha;
    u32 i;
    u32 bit;
    s32 j;
    s32 k;
    s32 pick;
    s32 pick2;
    f32 r, g, b;
    u8 color[4];
    u32 value;
    u8 *mgr;

    flags = obj->flags;
    state = (State *)*(u32 *)((u8 *)obj + 0x32c);
    mgr = &lbl_1_bss_6D820;
    if (flags & 0x01000000)
        return;
    effect = (s8)*(s16 *)((u8 *)obj + 0x3ba);
    if (effect == 5)
        return;
    if (flags & 0x04000000) {
        entry = *(void **)((u8 *)*(void **)((u8 *)obj + 0x3a0) + effect * 4 + 0x344);
        entry = *(void **)((u8 *)entry + 8);
        entry = *(void **)entry;
    } else {
        entry = *(void **)((u8 *)obj + effect * 12 + 0x334);
        entry = *(void **)entry;
    }
    if (!entry) {
        OSReport((const char *)lbl_1_data_20894);
        return;
    }

    ramp = 0;
    if (lbl_1_bss_3BE0 && fn_1_1FB80((u8 *)state + 0x7c, 0x2000))
        ramp = 1;
    *(s32 *)(mgr + 0x1a0 + state->index * 4) = ramp;
    if (*(s32 *)(mgr + 0x1a0 + state->index * 4)) {
        s16 mode = fn_1_7B054();
        value = *(u32 *)((u8 *)&lbl_1_data_2A8D8 + ((u8 *)&lbl_1_data_2B0D4)[mode] * 4);
        value = *(u32 *)value;
        *(u32 *)color = *(u32 *)(value + 0x18);
        if (mode == 40) {
            i = *(u32 *)(mgr + 0x5c + state->index * 4);
            if ((s32)i < 15)
                *(u32 *)(mgr + 0x5c + state->index * 4) = ++i;
            alpha = (f32)i / 15.0f;
            if (alpha < 0.0f) alpha = 0.0f;
            else if (alpha > 1.0f) alpha = 1.0f;
            color[0] = (s32)((f32)color[0] * (1.0f - alpha));
            color[1] = (s32)((f32)color[1] * (1.0f - alpha));
            color[2] = (s32)((f32)color[2] * (1.0f - alpha));
        } else {
            color[0] = (s32)((f32)color[0] * 0.01f);
            color[1] = (s32)((f32)color[1] * 0.01f);
            color[2] = (s32)((f32)color[2] * 0.01f);
        }
        fn_1_55FD0((f32)color[0] / 255.0f, (f32)color[1] / 255.0f, (f32)color[2] / 255.0f);
    } else {
        s16 mode = fn_1_7B054();
        if (mode == 40 && *(s32 *)(mgr + 0x5c + state->index * 4) > 0) {
            i = --*(u32 *)(mgr + 0x5c + state->index * 4);
            alpha = (f32)i / 15.0f;
            if (alpha < 0.0f) alpha = 0.0f;
            else if (alpha > 1.0f) alpha = 1.0f;
            value = *(u32 *)((u8 *)&lbl_1_data_2A8D8 + ((u8 *)&lbl_1_data_2B0D4)[mode] * 4);
            value = *(u32 *)value;
            *(u32 *)color = *(u32 *)(value + 0x18);
            color[0] = (s32)((f32)color[0] * (1.0f - alpha));
            color[1] = (s32)((f32)color[1] * (1.0f - alpha));
            color[2] = (s32)((f32)color[2] * (1.0f - alpha));
            fn_1_55FD0((f32)color[0] / 255.0f, (f32)color[1] / 255.0f, (f32)color[2] / 255.0f);
        }
    }

    alpha = *(u8 *)(mgr + 0x218) ? 1.0f : fn_1_86A2C(state);
    if (*(s32 *)(mgr + 0x38) && state->index == 0 && !(*(u32 *)state & 0x01000000))
        fn_1_8E244((u8 *)state + 0x14c);
    if (lbl_1_rodata_3508[4] != alpha) {
        lbl_8006DFE8((u8 *)state + 0x14c);
        if (fn_1_54E34((u8 *)entry + 8, *(f32 *)((u8 *)entry + 0x14))) {
            fn_1_566EC(1, 255);
            if (!(obj->flags & 0x00200000) && lbl_1_rodata_3508[10] == alpha) {
                if (!fn_1_3EFA8())
                    fn_1_A77DC(obj);
                fn_1_A7854(obj, 0);
            }
            value = *(s16 *)((u8 *)state + 6);
            pick = -1;
            if ((s32)value >= 41) pick = (s16)(value - 50);
            if (pick == -1) value = 0;
            else value = (u32)(fn_1_36AD0() + pick * 0x81c0);
            fn_1_151BDC(value);
            fn_1_86E08(*(void **)((u8 *)obj + 0x32c));
            if (obj->flags & 0x00040000) {
                value = *(u32 *)((u8 *)lbl_1_rodata_3508 + 0x660);
                fn_1_5631C(&value);
            }
            if (obj->flags & 0x00200000) {
                fn_80072558();
                pick = fn_1_847A8((s8)*((u8 *)obj + 0x328), *(s16 *)*(u32 *)(mgr + 0x3c));
                fn_1_55210(*(void **)(*(u32 *)(mgr + 0x3c) + 8 + pick * 8));
            } else {
                if (fn_1_A728C((u8)state->index)) {
                    pick = -1;
                    pick2 = -1;
                    for (i = 2; i < 5; i++)
                        if (!(*(u8 *)((u8 *)obj + 0x38c) & (1 << i))) { pick = i; break; }
                    for (i = 2; i != 0xffffffff; i--)
                        if (!(*(u8 *)((u8 *)obj + 0x38c) & (1 << i))) { pick2 = i; break; }
                    if (pick == -1 && pick2 == -1) pick2 = 3;
                    else if (pick == -1) {}
                    else if (pick2 == -1) pick2 = pick;
                    else if (pick < 0) {}
                    else if (i > 0) pick2 = pick;
                    else if (i == 0 && *(u8 *)(mgr + 0x180 + *(s16 *)((u8 *)obj + 0x320)) == 1) pick2 = pick;
                    ramp = pick2;
                }
                fn_1_870BC(obj, ramp, obj, 1, (u8)*(s16 *)((u8 *)obj + 0x3b8), alpha);
            }
            value = *(u32 *)(lbl_1_rodata_3508 + 0x664);
            fn_1_5631C(&value);
            fn_1_566EC(0, 0);
        }
        if (!(obj->flags & 0x00200000)) {
            color[0] = color[1] = color[2] = 0;
            color[3] = (s32)(128.0f * alpha);
            fn_1_5745C((u8 *)*(u32 *)(mgr + 0x24) + state->index * 0x4c, color);
        }
    }
    if (*(s32 *)(mgr + 0x1a0 + state->index * 4)) {
        value = *(u32 *)((u8 *)&lbl_1_data_2A8D8 + ((u8 *)&lbl_1_data_2B0D4)[fn_1_7B054()] * 4);
        value = *(u32 *)value;
        *(u32 *)color = *(u32 *)(value + 0x18);
        fn_1_55FD0((f32)color[0] / 255.0f, (f32)color[1] / 255.0f, (f32)color[2] / 255.0f);
    }
}
