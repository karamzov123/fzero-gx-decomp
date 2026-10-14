/* Non-matching: best partial attempt (15.74% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct fn_1_14328C_Copy88 { u32 a[22]; };
struct fn_1_14328C_lbl_1_bss_26B04 { u8 unk_0[1]; };

extern struct fn_1_14328C_lbl_1_bss_26B04 lbl_1_bss_26B04;
extern f32 lbl_1_rodata_26F8[22];
extern const f64 lbl_1_rodata_93E8;
extern const f32 lbl_1_rodata_9474;
extern const f32 lbl_1_rodata_9478;
extern f64 lbl_1_rodata_9480[80];
extern u16 fn_1_48690(u32);
extern int fn_1_4F734(FontDrawPacket *);

void fn_1_14328C(u32 arg0, u32 arg1, u32 arg2) {
    u8 v0;
    s32 v1;
    u32 v2;
    s32 v3;
    s32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    u32 loc_4[47];
    s32 i;
    s32 j;
    s32 k;
    s32 rem;
    s32 count;
    f32 f0, f1, f2, scale;
    u32 seed;
    struct fn_1_14328C_Copy88 *src;
    v0 = lbl_1_bss_26B04.unk_0[arg2];
    v1 = (u32)(((s64)(0x66660000 + 26215) * (s64)v0) >> 32);
    v2 = (u32)((u8 *)lbl_1_rodata_26F8 - 4);
    v3 = ((s32)v1 >> 2);
    v4 = ((s32)v1 >> 2);
    v5 = (v4 + ((u32)v4 >> 31));
    v6 = (v0 - ((v3 + ((u32)v3 >> 31)) * 10));
    src = (struct fn_1_14328C_Copy88 *)((u8 *)&lbl_1_rodata_26F8 - 4);
    *(struct fn_1_14328C_Copy88 *)loc_4 = *src;
    seed = 0x19713;
    rem = v6;
    count = v5;
    if (rem >= 6) {
        for (i = 6; i <= rem; i++) {
            s32 n = i - 1;
            s32 q = n / 5;
            s32 r = n - q * 5;
            *(f32 *)&loc_4[2] = (f32)(s32)arg1;
            *(f32 *)&loc_4[1] = (f32)(s32)arg0 - (f32)r * lbl_1_rodata_9474;
            *(f32 *)&loc_4[5] = (f32)(s32)fn_1_48690(seed) / lbl_1_rodata_9474;
            *(f32 *)&loc_4[6] = (f32)(s32)fn_1_48690(seed) / lbl_1_rodata_9474;
            fn_1_4F734((FontDrawPacket *)&loc_4[1]);
        }
        arg1 = (s32)((f32)(s32)arg1 - lbl_1_rodata_9478);
    }
    if (rem >= 1) {
        for (i = 1; i <= rem; i++) {
            s32 n = i - 1;
            s32 q = n / 5;
            s32 r = n - q * 5;
            *(f32 *)&loc_4[2] = (f32)(s32)arg1;
            *(f32 *)&loc_4[1] = (f32)(s32)arg0 - (f32)r * lbl_1_rodata_9474;
            *(f32 *)&loc_4[5] = (f32)(s32)fn_1_48690(seed) / lbl_1_rodata_9474;
            *(f32 *)&loc_4[6] = (f32)(s32)fn_1_48690(seed) / lbl_1_rodata_9474;
            fn_1_4F734((FontDrawPacket *)&loc_4[1]);
        }
        arg1 = (s32)((f32)(s32)arg1 - lbl_1_rodata_9478);
    }
    if (count >= 1) {
        for (i = 0, j = 0; i < count; i++, j += 12) {
            *(f32 *)&loc_4[1] = (f32)(s32)arg0 - (f32)i;
            *(f32 *)&loc_4[2] = (f32)(s32)arg1;
            *(f32 *)&loc_4[5] = (f32)(s32)fn_1_48690(seed) / lbl_1_rodata_9480[0];
            *(f32 *)&loc_4[6] = (f32)(s32)fn_1_48690(seed) / lbl_1_rodata_9480[0];
            fn_1_4F734((FontDrawPacket *)&loc_4[1]);
        }
    }
}
