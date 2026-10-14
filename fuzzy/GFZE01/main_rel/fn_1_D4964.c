/* Non-matching: best partial attempt (5.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/mdlload.h"

extern f32 lbl_1_rodata_6168;
extern u32 lbl_801A63C0;
extern u32 fn_1_D523C(void *);
extern void fn_80008BEC(void *, int, u32);
extern void DCFlushRange(void *, u32);
typedef struct { u32 dummy[8]; } TexObj;
extern void GXInitTexObj(TexObj *, void *, u16, u16, int, int, int, u8);
extern void GXInitTexObjLOD(TexObj *, int, int, f32, f32, f32, u8, u8, int);
extern void GXInvalidateTexAll(void);

void fn_1_D4964(u32 arg0) {
    u8 *base = (u8 *)(arg0 + 0xC140);
    s32 y, x, i, j;
    u32 seed, mult = 0x676A4B6B;

    fn_80008BEC(base + 0x20, 0, 0x200);
    for (y = 0; y < 16; y++) {
        for (x = 0; x < 8; x++) {
            for (i = 0; i < 8; i++) {
                s32 bit = (x * 8 + i) / 2 + y * 32;
                s32 value = 0;
                if (bit < 512) {
                    seed = lbl_801A63C0 = lbl_801A63C0 * mult + 0x33CB;
                    if ((s32)((seed >> 16) & 0x7FFF) < 0)
                        value = 0;
                    if (i & 1)
                        base[0x20 + bit] |= value;
                    else
                        base[0x20 + bit] |= value << 4;
                }
            }
        }
    }
    DCFlushRange(base + 0x20, 0x200);
    fn_80008BEC(base + 0x220, 0, 0x2400);
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 8; x++) {
            s16 count = (s16)(1 + y * 3);
            s32 row = 0;
            while (row < count) {
                s32 r0 = (row * 0x10) + 0x220;
                seed = lbl_801A63C0 = lbl_801A63C0 * mult + 0x33CB;
                seed = lbl_801A63C0 = seed * mult + 0x33CB;
                base[(y * 0x900) + row * 0x120 + r0] = 16;
                base[(y * 0x900) + row * 0x120 + r0] = 1;
                base[(y * 0x900) + row * 0x120 + r0] = 17;
                row++;
            }
        }
    }
    DCFlushRange(base + 0x220, 0x2400);
    GXInitTexObj((TexObj *)base, base + 0x20, 32, 32, 0, 1, 1, 0);
    GXInitTexObjLOD((TexObj *)base, 1, 1, lbl_1_rodata_6168, lbl_1_rodata_6168, lbl_1_rodata_6168, 0, 0, 0);
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 8; x++) {
            u8 *p = base + y * 0x900 + x * 0x120;
            GXInitTexObj((TexObj *)(p + 0x320), p + 0x220, 16, 16, 2, 1, 1, 0);
            GXInitTexObjLOD((TexObj *)(p + 0x320), 0, 0, lbl_1_rodata_6168, lbl_1_rodata_6168, lbl_1_rodata_6168, 0, 0, 0);
        }
    }
    GXInvalidateTexAll();
    lbl_1_data_2A7E0.unk_2C = (u32)fn_1_D523C;
}
