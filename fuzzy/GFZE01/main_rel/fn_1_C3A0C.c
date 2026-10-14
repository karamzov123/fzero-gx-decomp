/* Non-matching: best partial attempt (52.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/memcard.h"
extern u8 lbl_1_rodata_5168[0x700];

extern void *lbl_801A6410;
extern void *fn_1_45D0(u32, u32, void *, u32);
extern u8 fn_1_3F1F8(void);
extern s32 fn_1_45730(void *, void *);
extern void fn_1_458A0(void *, void *, u32, u32);
extern void fn_1_45850(void *);
extern void *fn_1_14F04(void);
extern void fn_1_214C4(void *, u32, f32);
extern void fn_1_17920(f32, u32);
extern void fn_1_207DC(void *, void *, f32);
extern u32 fn_1_14DC4(void);
extern void fn_1_C40A0(u32);
extern int sprintf(char *, const char *, ...);
extern void *fopen(const char *, const char *);
extern int fn_8007F48C(void *, int, int, void *);
extern int fflush(void *);
extern int fclose(void *);
extern void fn_80006E10(void *);
extern u16 lbl_1_bss_960;

struct StateOverlay {
    u32 ptr;
    u16 count;
    u8 pad_6[2];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[4];
    u32 unk_18;
    u8 unk_1C;
    u8 pad_1D[0x23];
    f32 unk_40;
    u32 unk_44;
};
void fn_1_C3A0C(u32 arg0) {
    struct StateOverlay *state = (struct StateOverlay *)&lbl_1_bss_7AC48;
    u8 *data = (u8 *)lbl_1_data_3D138;
    u8 *rom = (u8 *)lbl_1_rodata_5168;
    u8 path[32];
    u8 info[0x60];
    void *file;
    s32 i, j, count;
    void *ctx;
    u8 mode;

    state->unk_8 = (u32)fn_1_45D0((u32)lbl_801A6410, 0x21c, data + 0xfc, 0x297);
    state->unk_C = (u32)fn_1_45D0((u32)lbl_801A6410, 0x800, data + 0xfc, 0x298);
    state->unk_10 = (u32)fn_1_45D0((u32)lbl_801A6410, 0x6000, data + 0xfc, 0x299);
    sprintf((char *)path, (char *)(data + 0x10c), (u32)fn_1_3F1F8());
    file = fopen((char *)path, (char *)(data + 0x11c));
    count = 0;
    if (file != 0) {
        fn_8007F48C((void *)state->unk_C, 0x800, 1, file);
        fflush(file);
        fclose(file);
        count = 1;
    }
    if (count == 0) {
        fn_80006E10(data + 0x120);
        if (fn_1_45730(path, info) != 0) {
            fn_1_458A0(info, (void *)state->unk_C, 0x800, 0);
            fn_1_45850(info);
        } else {
            u8 *p = (u8 *)state->unk_C;
            s32 val = -75;
            for (i = 0; i < 4; ++i) {
                for (j = 0; j < 16; ++j) {
                    p[0] = val; p[1] = val; p[2] = val; p[3] = val;
                    p[4] = val; p[5] = val; p[6] = val; p[7] = val;
                    p[8] = val; p[9] = val; p[10] = val; p[11] = val;
                    p[12] = val; p[13] = val; p[14] = val; p[15] = val;
                    p[16] = val; p[17] = val; p[18] = val; p[19] = val;
                    p[20] = val; p[21] = val; p[22] = val; p[23] = val;
                    p[24] = val; p[25] = val; p[26] = val; p[27] = val;
                    p[28] = val; p[29] = val; p[30] = val; p[31] = val;
                    p += 32;
                }
                val += 50;
            }
        }
        fn_80006E10(data + 0x12c);
    }

    ctx = fn_1_14F04();
    for (i = 0; i < 512; ++i) {
        f32 time;
        fn_1_214C4(&time, 0, (f32)((f64)i * *(f32 *)&state->unk_40));
        fn_1_17920(time, 0);
        for (j = 0; j < 4; ++j) {
            s32 index = (j + 1) % (((s32 *)ctx)[7] - 1);
            s8 val = *((s8 *)state->unk_C + i + j * 512);
            fn_1_207DC((u8 *)ctx + 0x400 + (index << 7), (u8 *)state->unk_10 + i * 12 + j * 0x1800, (f32)((f64)val * 0.00390625));
        }
    }
    state->unk_44 = fn_1_14DC4();
    if (lbl_1_bss_960 == 9) {
        if (lbl_1_bss_8B3A0.unk_8 < 5 || lbl_1_bss_8B3A0.unk_8 > 7) lbl_1_bss_8B3A0.unk_8 = 5;
        state->unk_1C = lbl_1_bss_8B3A0.unk_8;
    } else {
        if (lbl_1_bss_8B3A0.unk_8 < 0 || lbl_1_bss_8B3A0.unk_8 > 3) lbl_1_bss_8B3A0.unk_8 = 1;
        state->unk_1C = lbl_1_bss_8B3A0.unk_8;
        if (lbl_1_bss_960 == 10) state->unk_1C = 2;
    }
    mode = state->unk_1C;
    for (i = 0; i < 8; ++i) state->unk_1C /*dummy*/;
    {
        u8 *c = rom + mode * 8;
        f64 base = *(f64 *)(rom + 0x698);
        f64 scale = *(f64 *)(rom + 0x690);
        for (i = 0; i < 8; ++i) ((f32 *)((u8 *)state + 0x20))[i] = (f32)((f64)(s32)c[i] * scale - base * scale);
    }
    mode = fn_1_3F1F8();
    state->unk_1C = mode;
    state->unk_18 = mode <= 0x23 ? ((u32 *)(data + 0x68))[mode] : 0;
    ((u8 *)state)[0x1e] = 0;
    ((u8 *)state)[0x1f] = 0;
    if (mode >= 0x21) {
        if (mode == 0x21) ((u8 *)state)[0x1e] = 1;
    } else if (mode >= 0x19) {
        ((u8 *)state)[0x1f] = 1;
    }
    ctx = (void *)state->unk_44;
    count = 0;
    while (*(f32 *)((u8 *)ctx + 4) > -1.0f) {
        if (*((u8 *)ctx + 0x10) != 1) ++count;
        ctx = (u8 *)ctx + 0x14;
    }
    state->count = count;
    if (count != 0) {
        state->ptr = (u32)fn_1_45D0((u32)lbl_801A6410, count * 0x14, data + 0xfc, 0x369);
        ctx = (void *)state->unk_44;
        j = 0;
        i = 0;
        while (*(f32 *)((u8 *)ctx + 4) > -1.0f) {
            if (*((u8 *)ctx + 0x10) != 1) {
                u8 type = *((u8 *)ctx + 0x11);
                f32 angle;
                if (*(f32 *)((u8 *)ctx + 8) > *(f32 *)((u8 *)ctx + 0xc))
                    angle = 0.5f * (*(f32 *)((u8 *)ctx + 8) + *(f32 *)((u8 *)ctx + 0xc) + 1.0f);
                else
                    angle = 0.5f * (*(f32 *)((u8 *)ctx + 8) + *(f32 *)((u8 *)ctx + 0xc));
                fn_1_214C4(&angle, 0, *(f32 *)ctx);
                fn_1_17920(angle, 0);
                ctx = fn_1_14F04();
                if (type == 0 && ((s32 *)ctx)[7] > 1) type = 1;
                fn_1_207DC((u8 *)ctx + 0x400 + (type << 7), (u8 *)state->ptr + j + 4, angle);
                ((u32 *)state->ptr)[j / 4] = i;
                ((u32 *)((u8 *)state->ptr + j + 0x10))[0] = 0;
                j += 0x14;
            }
            ++i;
            ctx = (u8 *)ctx + 0x14;
        }
    }
    fn_1_C40A0(arg0);
}
