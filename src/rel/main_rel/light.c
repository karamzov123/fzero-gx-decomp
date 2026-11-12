#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/light.h"

extern u16 lbl_1_bss_6D7C0[20];

extern void *lbl_801A6410;
extern u32 fn_1_4630(u32, int, void *, int);
extern void fn_800793D4(u32, int, int);
extern void fn_1_7C13C(void *);
extern void fn_1_7C1E8(u32);
extern u8 fn_1_816E8(void *, u8);
extern const f32 lbl_1_rodata_33A8;
extern void fn_1_495D8(int, int, f32);
extern void fn_1_495FC(void);
extern void OSPanic(const char *, int, const char *, ...);

/* fzgx:begin fn_1_7BCCC */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} Triple_80074D28;

typedef struct {
    u8 pad_0[0x2];
    u16 unk_2;
    u8 pad_4[0x12];
    u16 unk_16;
    u8 pad_18[0x8];
    u32 unk_20;
} Fn17BCCCState;

extern void fn_80074D28(Triple_80074D28 *);

void fn_1_7BCCC(Triple_80074D28 *arg0) {
    Fn17BCCCState *state;

    state = (Fn17BCCCState *)&lbl_1_bss_6D7A8;
    if (state->unk_16 >= state->unk_2) {
        OSPanic((const char *)lbl_1_data_1EE44, 143, (const char *)lbl_1_data_1EE70);
    }
    *(Triple_80074D28 *)((u8 *)state->unk_20 + state->unk_16 * 12) = *arg0;
    fn_80074D28(arg0);
    state->unk_16++;
    return;
}
/* fzgx:end fn_1_7BCCC */

/* fzgx:begin fn_1_7BD6C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

extern u32 lbl_1_bss_6C8DC[2];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_727BC(u32 arg0, u32 arg1, void *arg2);
extern void fn_1_76A94(void *arg0, u32 arg1);
extern void fn_1_76DBC(void);
extern void fn_1_4E500(void);
extern void fn_1_4E638(int);
extern void fn_1_4E6F4(void);
extern void fn_80073778(void *arg0, int arg1);
extern s32 fn_1_A5D9C(void);
extern const f32 lbl_1_rodata_31AC;
extern u32 fn_80008E84(u32 arg);
extern void fn_1_77238(void);
extern void fn_1_772E0(void);
extern void fn_1_77384(void *arg);
extern void fn_80072864(int arg0);
extern void fn_800745A4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void fn_80074660(int arg0);
extern void fn_80073678(int arg0);
extern void fn_80073898(int arg0);
extern void fn_80074788(int arg0);
extern void fn_800738E0(int arg0, int arg1, int arg2);
extern void fn_80073D60(int arg0, int arg1, int arg2, int arg3, int arg4);
extern void fn_800734A8(int arg0, int arg1, int arg2, int arg3);
extern void fn_80072EDC(int arg0, int arg1);
extern f32 lbl_1_rodata_31B0[10];
extern const f64 lbl_1_rodata_31A0;
extern void lbl_8006D784(f32 *arg);
extern void fn_80073A58(int arg0, f32 *arg1, int arg2);
extern void fn_800739E0(int arg0, int arg1, int arg2);
extern void GXLoadTexMtxImm(f32 *arg0, int arg1, int arg2);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);
extern void fn_1_79810(void);
extern void fn_1_79948(void);
extern void fn_1_791B0(void);
extern void fn_1_9A1E8(void);
extern void fn_1_9A864(void);
extern u8 fn_1_7B074(void);
extern void fn_80071718(void *arg);
extern void fn_800711A8(void *arg);
extern void fn_1_14CB4(void);
extern void fn_1_FA84(void);
extern const f32 lbl_1_rodata_32CC;
extern void fn_1_79C88(void *arg0, s32 arg1, f32 arg2, s32 arg3);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void sprintf(char *dst, const char *format, ...);
extern void fn_1_465D0(char *text, int arg);
extern void fn_1_14D5C(void *object, int arg);
extern void fn_1_46EA8(int value);
extern void fn_1_12620(void *object);
extern void fn_1_46DC4(void *obj);

extern void fn_1_727BC();
extern void fn_8006FDEC(void);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);
extern u32 fn_8003526C(u32, u32);
extern u32 fn_80074300(u32, u32, u32, u32);
extern u32 fn_80074438(u32, u32, u32, u32);

extern void OSPanic(const char *, int, const char *, ...);
extern s32 fn_80074D08(u32);

static inline s32 highest_bit(u32 value, u8 *data) {
    s32 highest = 31 - __cntlzw(value);
    if (highest > 7 || highest < 0) {
        OSPanic((const char *)(data + 0x8ec), 0x30, (const char *)(data + 0x904));
    }
    return highest;
}

u32 fn_1_7BD6C(s32 value) {
    s32 highest;
    struct { u16 *value; } map;
    s32 bit;
    u16 *entries;
    u32 result;
    u8 *data = lbl_1_data_1E558;
    u8 *state = (u8 *)&lbl_1_bss_6D7A8;

    if (*(u16 *)(state + 0x18) >= lbl_1_bss_6D7A8.unk_4) {
        OSPanic((const char *)(data + 0x8ec), 0xa5, (const char *)(data + 0x92c));
    }
    entries = (u16 *)(*(u32 *)(state + 0x24) + *(u16 *)(state + 0x18) * 0x14);
    entries[0] = (u16)value;
    entries[1] = ((Obj_1_bss_6D7A8 *)state)->unk_16 - 1;
    *(u32 *)(state + 0x38) = value;
    result = fn_80074D08(value);
    highest = highest_bit(value, data);
    bit = highest;
    map.value = (u16 *)(state + 0x28);
    highest = 1;
    while (bit >= 0) {
        if (map.value[bit] == 0xffff) {
            OSPanic((const char *)(data + 0x8ec), 0xb1, (const char *)(data + 0x940));
        }
        entries[bit + 2] = map.value[bit];
        value = value & ~(highest << bit);
        bit = 31 - __cntlzw(value);
    }
    *(u16 *)(state + 0x18) += 1;
    return result;
}
/* fzgx:end fn_1_7BD6C */

/* fzgx:begin fn_1_7BE94 */
u16 fn_1_7BE94(void) {
    return lbl_1_bss_6D7C0[0] - 1;
}
/* fzgx:end fn_1_7BE94 */

/* fzgx:begin fn_1_7BEAC */
typedef struct {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u8 pad_6[2];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u16 unk_14;
    u16 unk_16;
    u8 pad_18[4];
    s32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u16 states[8];
    s32 unk_38;
} LightStateView;

extern u32 fn_800356B8(void *, u32);
extern void fn_80074D28(void *);
extern u32 fn_80074D08(u32);

static inline void update_states(LightStateView *light, u8 *base, s32 *changed) {
    u32 i = 0;
    u8 *entry = base;
    u16 *states = light->states;
    for (; i < 8; i++, states++, entry += 2) {
        u16 value = *(u16 *)(4 + entry);
        if (value != *states) {
            fn_800356B8((u8 *)light->unk_1C + ((u32)value << 6), 1 << i);
            *changed = 1;
            *states = *(u16 *)(entry + 4);
        }
    }
}

void fn_1_7BEAC(u16 index) {
    LightStateView *light = (LightStateView *)&lbl_1_bss_6D7A8;
    u8 *entry_base = (u8 *)light->unk_24 + (u32)index * 0x14;
    s32 changed = 0;
    update_states(light, entry_base, &changed);

    if (light->unk_16 != *(u16 *)(entry_base + 2) &&
        ((0) != (light->unk_16))) {
        fn_80074D28((u8 *)light->unk_20 + (u32)*(u16 *)(entry_base + 2) * 0xc);
        light->unk_16 = *(u16 *)(entry_base + 2);
    }

    if (light->unk_38 != *(u16 *)entry_base || changed != 0) {
        fn_80074D08(*(u16 *)entry_base);
        light->unk_38 = *(u16 *)entry_base;
    }
}
/* fzgx:end fn_1_7BEAC */

/* fzgx:begin fn_1_7BF9C */
typedef struct {
    void *unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    s8 unk_7;
    u8 unk_8;
    u8 unk_9[3];
    void *unk_c;
    void *unk_10;
    void *unk_14;
    void *unk_18;
    void *unk_1c;
    u32 unk_20;
    u8 unk_24;
} LightState;

// Initialize the shared light state and its required resources.
void fn_1_7BF9C(void *arg, s8 flag) {
    u8 *resource_table;
    u32 resource_18;
    u32 resource_1c;
    u32 resource_c;

    resource_table = (u8 *)&lbl_1_data_1EEB0;
    lbl_1_bss_6D7E8 = fn_1_4630(
        (u32)lbl_801A6410, 0x2c, resource_table + 0xac, 0x33);
    resource_18 = fn_1_4630(
        (u32)lbl_801A6410, 4, resource_table + 0xac, 0x34);
    resource_1c = fn_1_4630(
        (u32)lbl_801A6410, 0x18, resource_table + 0xac, 0x35);
    resource_c = fn_1_4630(
        (u32)lbl_801A6410, 0xa4, resource_table + 0xac, 0x36);

    fn_800793D4(resource_c, 0xff, 0xa4);
    fn_1_7C13C(arg);
    fn_1_7C1E8(resource_1c);

    ((LightState *)lbl_1_bss_6D7E8)->unk_0 = arg;
    ((LightState *)lbl_1_bss_6D7E8)->unk_4 = 2;
    ((LightState *)lbl_1_bss_6D7E8)->unk_6 = 2;
    ((LightState *)lbl_1_bss_6D7E8)->unk_24 = 0;
    ((LightState *)lbl_1_bss_6D7E8)->unk_8 = fn_1_816E8(
        (u8 *)((LightState *)lbl_1_bss_6D7E8)->unk_0 +
            ((LightState *)lbl_1_bss_6D7E8)->unk_7 * 0x440,
        ((LightState *)lbl_1_bss_6D7E8)->unk_24);

    ((LightState *)lbl_1_bss_6D7E8)->unk_c = (void *)resource_c;
    ((LightState *)lbl_1_bss_6D7E8)->unk_10 = resource_table + 0x48;
    ((LightState *)lbl_1_bss_6D7E8)->unk_14 = resource_table + 0x94;
    ((LightState *)lbl_1_bss_6D7E8)->unk_18 = (void *)resource_18;
    ((LightState *)lbl_1_bss_6D7E8)->unk_1c = (void *)resource_1c;

    if (flag == 0) {
        ((LightState *)lbl_1_bss_6D7E8)->unk_20 |= 0x40000000;
    }

    fn_1_495D8(2, 2, lbl_1_rodata_33A8);
    fn_1_495FC();
}
/* fzgx:end fn_1_7BF9C */
