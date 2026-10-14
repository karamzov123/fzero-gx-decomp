/* Non-matching: best partial attempt (77.43% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_12_bss_7C58;
extern u8 lbl_12_rodata_B00[88];
extern void fn_12_33428(void *, u32, u32);
extern u8 lbl_12_rodata_C78[102];
extern void *fn_12_57F0(void *, const void *, u32);
extern void fn_12_2F1A0(void *);
extern void fn_12_22FB8(void *);
extern int fn_12_2F7AC(void *, int);
extern void fn_12_2CD8C(void);
extern void fn_12_24924(void);
extern void fn_80058680(void);

typedef struct MovieStateSub {
    u8 pad0[0x190];
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    u8 pad1b0[0x4C];
    int f1fc;
    int f200;
    int f204;
    int f208;
    int f20c;
    int f210;
    int f214;
    int f218;
    int f21c;
    int f220;
} MovieStateSub;

typedef struct MovieState {
    int f0;
    int f4;
    void *f8;
    MovieStateSub sub;
} MovieState;

int fn_12_24C48(int *arg) {
    MovieState *state;
    int res;

    state = (MovieState *)&lbl_12_bss_7C58;
    state->f0 = 0x29d8;
    state->f8 = lbl_12_rodata_B00;
    fn_80058680();
    fn_12_33428(&state->sub, 0, 0x89);
    fn_12_57F0(&state->sub, lbl_12_rodata_C78, 0x190);
    state->sub.f190 = arg[0];
    state->sub.f194 = arg[1];
    state->sub.f198 = 0;
    state->sub.f19c = 0;
    state->sub.f1a0 = 0;
    state->sub.f1a4 = 0;
    state->sub.f1a8 = 0;
    state->sub.f1ac = 0;
    fn_12_2F1A0(&state->sub.pad1b0[0]);
    fn_12_22FB8(&state->sub.pad1b0[0xC]);
    state->sub.f1fc = 0;
    state->sub.f200 = 0;
    state->sub.f204 = 0;
    state->sub.f208 = 0;
    state->sub.f20c = 0;
    state->sub.f210 = 0;
    state->sub.f214 = 0;
    state->sub.f218 = 0;
    state->sub.f21c = 0;
    state->sub.f220 = 0;
    res = fn_12_2F7AC(&state->sub.pad1b0[0x10], arg[0]);
    if (res != 0) {
        return res;
    }
    fn_12_2CD8C();
    fn_12_24924();
    return 0;
}
