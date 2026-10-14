/* Non-matching: best partial attempt (57.28% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"

typedef struct Sig_PADClamp_PADStatus {
    u16 button;
    s8 stickX;
    s8 stickY;
    s8 substickX;
    s8 substickY;
    u8 triggerLeft;
    u8 triggerRight;
    u8 analogA;
    u8 analogB;
    s8 err;
} Sig_PADClamp_PADStatus;

extern u8 lbl_1_bss_978[];
extern void fn_1_1304(u32);
extern void fn_1_1C00(const u8 *, u32, u16 *);
extern u32 fn_1_3FC28(void);
extern s32 fn_1_3EFA8(void);
extern void fn_1_21E4(u8 *, u8 *);
extern void fn_1_F2820(void *, void *, void *);
extern void fn_1_2F04(void);
extern void fn_80008BA8(u32, u32, u32);
extern void PADClamp(Sig_PADClamp_PADStatus *);
extern void fn_80008BEC(void *, int, u32);
extern const f64 lbl_1_rodata_B8;
extern const f32 lbl_1_rodata_C0;
extern f64 lbl_1_rodata_A0[3];
extern const f64 lbl_1_rodata_100;

void fn_1_3308(void) {
    u8 *base = (u8 *)&lbl_1_bss_978;
    u8 *pad;
    u8 *out;
    u8 *rec;
    u32 i;
    u8 tmp[8];
    u8 *state;
    u8 *raw;
    u8 *floats;
    u8 *small;

    fn_1_1304((u32)(base + 0x20));
    fn_80008BA8((u32)(base + 0x50), (u32)(base + 0x20), 0x30);
    PADClamp((Sig_PADClamp_PADStatus *)(base + 0x20));
    pad = base + 0x20;
    out = base + 0x80;
    rec = base + 0xD0;
    state = base + 0x110;
    raw = base + 0x50;
    floats = base + 0x278;
    small = base + 0x2F8;

    for (i = 0; i < 4; i++) {
        *(u32 *)(out + 4) = *(u32 *)out;
        *(u16 *)out = *(u16 *)pad;
        *(u16 *)(out + 8) = *(u16 *)out & ~*(u16 *)(out + 4);
        *(u16 *)(out + 12) = *(u16 *)(out + 4) & ~*(u16 *)out;
        fn_1_1C00(pad, *(u16 *)(out + 6), (u16 *)(out + 2));
        *(u32 *)(rec + 8) = *(u32 *)rec;
        *(u32 *)(rec + 12) = *(u32 *)(rec + 4);
        rec[0] = pad[2]; rec[1] = pad[3]; rec[2] = pad[4]; rec[3] = pad[5];
        *(u16 *)(out + 10) = *(u16 *)(out + 2) & ~*(u16 *)(out + 6);
        rec[4] = pad[6]; rec[5] = pad[7]; rec[6] = pad[8]; rec[7] = pad[9];
        *(u16 *)(out + 14) = *(u16 *)(out + 6) & ~*(u16 *)(out + 2);
        pad += 12; out += 20; rec += 16;
    }

    if (fn_1_3FC28() == 0 && fn_1_3EFA8() == 0) {
        lbl_1_bss_7EFD8.unk_20 = state[0];
        lbl_1_bss_7EFD8.unk_21 = state[6];
        lbl_1_bss_7EFD8.unk_22 = state[12];
        lbl_1_bss_7EFD8.unk_23 = state[18];
    }

    tmp[0] = state[0]; tmp[1] = state[6]; tmp[2] = state[12]; tmp[3] = state[18];
    fn_1_21E4(tmp + 4, tmp);
    if (fn_1_3FC28() != 0)
        fn_1_F2820(state, base + 0x348, (u8 *)&lbl_1_bss_7EFD8 + 0x20);

    for (i = 0; i < 4; i++) {
        s32 a = (s8)state[1];
        s32 b = (s8)state[2];
        s32 c = (s8)state[3];
        s32 d = (s8)state[4];
        s32 e = (s8)state[5];
        small[0] = 0;
        *(f32 *)(small + 0) = (f32)((a + 128) / 100.0f);
        *(f32 *)(small + 4) = (f32)((b + 128) / 100.0f);
        *(f32 *)(small + 8) = (f32)((c + 128) / 100.0f);
        *(f32 *)(small + 12) = (f32)((d - 0) / 100.0f);
        *(f32 *)(small + 16) = (f32)((e - 0) / 100.0f);
        if ((s8)raw[10] == -1) {
            fn_80008BEC(floats, 0, 0x20);
        } else {
            s32 j;
            for (j = 0; j < 8; j++)
                *(f32 *)(floats + j * 4) = (f32)((s8)tmp[j] / 100.0f);
        }
        state += 6; raw += 12; floats += 0x20; small += 0x14;
    }

    for (i = 0; i < 2; i++) {
        if (*(f32 *)(base + 0x2F8 + i * 0x14 + 0xC) > 0.97f)
            base[0x110 + i * 6] |= 4;
        else
            base[0x110 + i * 6] &= ~4;
        if (*(f32 *)(base + 0x2F8 + i * 0x14 + 0x10) > 0.97f)
            base[0x110 + i * 6] |= 8;
        else
            base[0x110 + i * 6] &= ~8;
        base[0x348 + i] = base[0x110 + i * 6] & ~tmp[i * 2];
        if (*(f32 *)(base + 0x2F8 + (i * 2 + 1) * 0x14 + 0xC) > 0.97f)
            base[0x110 + (i * 2 + 1) * 6] |= 4;
        else
            base[0x110 + (i * 2 + 1) * 6] &= ~4;
        if (*(f32 *)(base + 0x2F8 + (i * 2 + 1) * 0x14 + 0x10) > 0.97f)
            base[0x110 + (i * 2 + 1) * 6] |= 8;
        else
            base[0x110 + (i * 2 + 1) * 6] &= ~8;
        base[0x349 + i] = base[0x110 + (i * 2 + 1) * 6] & ~tmp[i * 2 + 1];
    }
    fn_1_2F04();
    fn_80008BEC(base + 0x3E0, 0, 0x14);
    for (i = 0; i < 4; i++) {
        if ((s8)raw[10] != -1) {
            u32 j;
            for (j = 0; j < 10; j++)
                *(u16 *)(base + 0x3E0 + j * 2) |= *(u16 *)(base + 0x80 + i * 0x14 + j * 2);
        }
        raw += 12;
    }
}
