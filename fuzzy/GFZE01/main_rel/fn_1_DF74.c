/* Non-matching: best partial attempt (72.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
} F2;

typedef struct {
    u8 pad_0[8];
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    F2 unk_24;
    s16 unk_2C;
    s16 unk_2E;
    char unk_30[0x5D8];
    s16 unk_608;
    u8 pad_60A[2];
    s16 unk_60C[45];
} Obj1148;

typedef struct {
    u8 pad_0[4];
    F2 unk_4;
    F2 unk_C;
    f32 unk_14;
    f32 unk_18;
} Rodata4E0;

extern Obj1148 lbl_1_bss_1148;
extern Rodata4E0 lbl_1_rodata_4E0;
extern u8 lbl_1_data_43B8[];
extern u32 lbl_1_data_212A8[45];
extern s8 fn_1_A5DC4(void);
extern s32 fn_1_F7BE4(s16);
extern u8 fn_1_F8CF0(s32);
extern void *memset(void *, int, u32);
extern int sprintf(char *, const char *, ...);

void fn_1_DF74(void) {
    const char *strs = (const char *)lbl_1_data_43B8;
    Obj1148 *st = &lbl_1_bss_1148;
    Rodata4E0 *ro = &lbl_1_rodata_4E0;
    s16 *ids = st->unk_60C;
    s16 i;
    f32 z;

    if (fn_1_A5DC4()) {
        st->unk_24 = ro->unk_4;
    } else {
        st->unk_24 = ro->unk_C;
    }
    st->unk_C = ro->unk_14;
    st->unk_10 = st->unk_24.x * ro->unk_18;
    st->unk_2C = 0;
    st->unk_2E = 0;
    memset(st->unk_30, 0, 0x5D8);
    st->unk_608 = 0;

    for (i = 0; i < 0x29; i++) {
        if (fn_1_F7BE4(i) != 0) {
            ids[st->unk_608] = i;
            sprintf(&st->unk_30[st->unk_608 * 34], strs + 0x1D8, lbl_1_data_212A8[i]);
            st->unk_608++;
        }
    }

    ids[st->unk_608] = 0x29;
    sprintf(&st->unk_30[st->unk_608 * 34], strs + 0x1E0, st->unk_608 * 2);
    st->unk_2E = st->unk_608;
    st->unk_608++;

    if (fn_1_F8CF0(0) != 0) {
        ids[st->unk_608] = 0x2A;
        sprintf(&st->unk_30[st->unk_608 * 34], strs + 0x1F0, st->unk_608 * 2);
        st->unk_608++;
    }

    if (fn_1_F8CF0(1) != 0) {
        ids[st->unk_608] = 0x2B;
        sprintf(&st->unk_30[st->unk_608 * 34], strs + 0x210, st->unk_608 * 2);
        st->unk_608++;
    }

    z = ro->unk_14;
    st->unk_8 = z;
    st->unk_18 = z;
    st->unk_1C = z;
    st->unk_20 = z;
}
