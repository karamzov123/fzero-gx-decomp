/* Non-matching: best partial attempt (84.85% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct Sig_fn_12_26D68_MovieObject {
    u8 pad_0038[0x38]; int field_0038;
    u8 pad_003c[0x1af4]; void *field_1b30;
    u8 pad_1b34[0x38c]; void *field_1ec0;
} Sig_fn_12_26D68_MovieObject;
typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);
typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48]; s32 state; u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context; s32 callback_data;
} Sig_fn_12_24A88_MovieObject;
struct fn_12_26D68_Copy28 { u32 a[7]; };
struct Copy8 { u32 a[2]; };
extern u32 lbl_12_bss_96A0[28];
extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *, s32);
extern void *memcpy(void *, const void *, u32);
extern void fn_12_33428(u32 *, u32, u32);
static inline s32 validate(u32 *globals) {
    u32 *v0 = globals + 19;
    u32 *v1;
    s32 i;
    if ((s32)v0[7] <= 0 || (s32)v0[7] > 16) return -1;
    if (v0[4] == 0 || v0[8] == 0) {
        v1 = globals + 17;
        if (v1[0] == 0) return -1;
        if (v1[1] == 0) return -1;
        v1 = globals + 1;
        for (i = 0; i < (s32)v0[7]; i++) {
            if (*v1 == 0) return -1;
            v1++;
        }
    }
    return 0;
}
#pragma opt_common_subs off
#pragma peephole off
s32 fn_12_26D68(Sig_fn_12_26D68_MovieObject *arg0, void *arg1) {
    u32 * lab_t0;
    u8 *dst = arg1;
    s32 v8;
    u8 *v7;
    u8 *v6;
    u32 *globals = lbl_12_bss_96A0;
    if (validate(globals) != 0) return fn_12_24A88((Sig_fn_12_24A88_MovieObject *)arg0, 0xff000f15);
    *(struct Copy8 *)(dst+4) = *(struct Copy8 *)&globals[19];
    *(struct fn_12_26D68_Copy28 *)(dst+12) = *(struct fn_12_26D68_Copy28 *)&globals[21];
    memcpy(dst+40, &globals[17], 8);
    memcpy(((48) + (dst)), &globals[1], 64);
    *(u32 *)(dst+0) = 0;
    *(u32 *)(dst+112) = 0;
    *(u32 *)(dst+116) = 5;
    *(u32 *)(dst+120) = 192;
    *(u32 *)(dst+256) = 0;
    *(u32 *)(dst+260) = 1;
    *(u32 *)(dst+124) = 0;
    *(u32 *)(dst+128) = 0;
    *(u32 *)(dst+296) = 0;
    *(u32 *)(dst+300) = 0;
    *(u32 *)(dst+304) = 0;
    v6 = dst;
    v7 = dst + 312;
    v8 = 0;
    do {
        *(u32 *)(v7+0) = 0;
        *(u32 *)(v7+4) = *(u32 *)(v6+48);
        *(u32 *)(v7+8) = 0;
        *(u32 *)(v7+12) = 1;
        *(u32 *)(v7+16) = 0;
        *(u32 *)(v7+20) = 0;
        *(u32 *)(v7+24) = 0;
        *(u32 *)(v7+28) = 0;
        *(u32 *)(v7+32) = 0;
        lab_t0 = (u32 *)(v7+40);
        fn_12_33428(lab_t0, -1, 20);
        v8++;
        v7 += 120;
        v6 += 4;
    } while (v8 < 16);
    *(u32 *)(dst+132) = 0;
    *(u32 *)(dst+136) = 0;
    lab_t0 = (u32 *)(dst+140);
    fn_12_33428(lab_t0, -1, 20);
    *(u32 *)(dst+220) = -1;
    *(u32 *)(dst+224) = 0;
    *(u32 *)(dst+228) = 0x7fffffff;
    *(u32 *)(dst+232) = 0;
    *(u32 *)(dst+236) = 0;
    *(u32 *)(dst+240) = 0;
    *(u32 *)(dst+244) = -1;
    *(u32 *)(dst+248) = 0;
    *(u32 *)(dst+252) = -1;
    *(u32 *)(dst+2232) = 0;
    *(u32 *)(dst+2236) = 0;
    *(u32 *)(dst+2240) = 0;
    *(u32 *)(dst+2244) = 0;
    *(u32 *)(dst+2248) = 0;
    *(u32 *)(dst+2252) = 0;
    *(u32 *)(dst+2256) = 0;
    *(u32 *)(dst+2260) = 0;
    *(u32 *)(dst+2264) = 0;
    *(u32 *)(dst+2268) = 0;
    *(u32 *)(dst+2272) = 0;
    *(u32 *)(dst+2276) = 0;
    *(u32 *)(dst+2280) = 0;
    *(u32 *)(dst+2284) = 0;
    *(u32 *)(dst+2288) = 0;
    *(u32 *)(dst+2292) = 0;
    *(u32 *)(dst+2296) = 0;
    *(u32 *)(dst+2300) = 0;
    *(u32 *)(dst+2304) = 0;
    *(u32 *)(dst+2308) = 0;
    *(u32 *)(dst+2312) = 0;
    *(u32 *)(dst+2316) = 0;
    *(u32 *)(dst+2320) = 0;
    *(u32 *)(dst+2332) = 0;
    *(u32 *)(dst+2328) = 0;
    *(u32 *)(dst+2332) = 0;
    *(u32 *)(dst+2336) = 0;
    *(u32 *)(dst+2340) = 0;
    *(u32 *)(dst+2344) = 0;
    *(u32 *)(dst+2340) = 0;
    *(u32 *)(dst+2352) = 0;
    *(u32 *)(dst+2356) = 0;
    *(u32 *)(dst+2360) = 0;
    *(u32 *)(dst+2340) = 0;
    *(u32 *)(dst+2368) = 0;
    *(u32 *)(dst+2364) = 0;
    *(u32 *)(dst+2376) = 0;
    *(u32 *)(dst+348) = (u32)(dst+2252);
    *(u32 *)(dst+468) = (u32)(dst+2260);
    *(u32 *)(dst+588) = (u32)(dst+2268);
    *(u32 *)(dst+708) = (u32)(dst+2276);
    *(u32 *)(dst+828) = (u32)(dst+2284);
    *(u32 *)(dst+948) = (u32)(dst+2292);
    *(u32 *)(dst+1068) = (u32)(dst+2300);
    *(u32 *)(dst+1188) = (u32)(dst+2308);
    *(u32 *)(dst+1308) = (u32)(dst+2316);
    *(u32 *)(dst+1428) = (u32)(dst+2324);
    *(u32 *)(dst+1548) = (u32)(dst+2332);
    *(u32 *)(dst+1668) = (u32)(dst+2340);
    *(u32 *)(dst+1788) = (u32)(dst+2348);
    *(u32 *)(dst+1908) = (u32)(dst+2356);
    *(u32 *)(dst+2028) = (u32)(dst+2364);
    *(u32 *)(dst+2148) = (u32)(dst+2372);
    return 0;
}
#pragma peephole reset

#pragma opt_common_subs reset

