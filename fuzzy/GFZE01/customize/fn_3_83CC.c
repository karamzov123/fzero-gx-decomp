/* Non-matching: best partial attempt (56.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"

extern u32 lbl_1_bss_9F8[];
extern u32 lbl_801A66A8;
extern s16 lbl_3_bss_7EBB0[41];
extern s16 lbl_3_bss_7EC02;
extern u32 lbl_3_bss_243C0[8304];
extern void fn_3_BD00(u32, u32, u32, u32);
extern void fn_1_A2D84(u32);
extern s16 fn_1_14F118(s16, void *);
extern u32 fn_1_151BE8(s16, s16);
extern void fn_80008BA8(void *, void *, s32);
extern s32 fn_1_F7BE4(s16);
extern s32 fn_8008023C(void *, void *, u32);

s32 fn_3_83CC(void) {
    u8 *g = (u8 *)&lbl_3_bss_0;
    u8 *state = g + 0x20;
    s16 *arr = (s16 *)lbl_1_bss_9F8;
    s16 idx = *(s16 *)(g + 0xF6);
    s16 cnt = *(s16 *)(g + 0xF8);
    s32 off = idx * 0x14;
    s16 *rec = (s16 *)((u8 *)arr + off);
    s16 change = 0, mode = 0;
    s16 selected = *(s16 *)(state + 0x18);
    s32 i, j, n, found, value;
    u8 *item;
    s16 old;
    s32 result = 0;
    s32 code = 0;

    if ((*((u16 *)rec + 9) >> 8) & 1) change = -1;
    if ((*(u16 *)rec >> 9) & 1) change = (s16)(change + 1);
    if (change) {
        lbl_801A66A8 = 0;
        fn_1_A2D84(0xA9010000);
        value = *(s16 *)(state + 0x18) + change;
        if (value > 3) value = 0;
        else if (value < 0) value = 3;
        *(s16 *)(state + 0x18) = value;
    }
    selected = *(s16 *)(state + 0x18);
    if (selected == 3) goto done_selection;
    {
        s16 *r = (s16 *)((u8 *)arr + off);
        s16 *r2 = (s16 *)((u8 *)arr + off);
        if (((*(u16 *)(r+8) >> 3) & 1) || ((*(u16 *)r2 >> 3) & 1)) mode = -1;
        if (((*(u16 *)(r+8) >> 2) & 1) || ((*(u16 *)r2 >> 2) & 1)) mode++;
    }
    item = state + selected * 8;
    n = *(s16 *)(item + 0x20);
    found = 0;
    i = 0;
    while (i < n && *(s16 *)(item + 0x22 + i*2) != state[selected*8]) i++;
    found = i;
    value = found + mode;
    if (value < 0) value = 0;
    else if (value >= n) value = n - 1;
    old = value;
    state[selected*8] = *(u8 *)(item + 0x22 + old*2);
    {
        s16 v = fn_1_14F118(*(u8 *)(state + selected*8), 0);
        *(s16 *)(state + selected*8 + 0x1A) = v;
    }
    i = *(s16 *)(g + 0x18) + 1;
    *(s16 *)(g + 0x18) = i < 10 ? i : 10;
    if (found != old && !change) goto post_change;
    *(s16 *)(g + 0x18) = 0;
    fn_1_A2D84(0xA9010000);
    lbl_801A66A8 = 0;
    if (change) {
        i = 0;
        n = *(s16 *)(item + 0x20);
        while (i < n && *(s16 *)(item + 0x22 + i*2) != state[selected*8]) i++;
        *(s16 *)(state + 0xC2) = i;
        *(s16 *)(state + 0xC4) = 0;
        j = 0;
        while (j < i) {
            s16 v = *(s16 *)(state + 0xC4);
            if (i > -v + 5) *(s16 *)(state + 0xC4) = v - 1;
            j++;
        }
    }
    if (found != old) {
        i = 0;
        n = *(s16 *)(item + 0x20);
        while (i < n && *(s16 *)(item + 0x22 + i*2) != state[selected*8]) i++;
        *(s16 *)(state + 0xC2) = i;
        j = i;
        value = -*(s16 *)(state + 0xC4);
        if (j < value || j > value + 5) {
            fn_3_BD00(mode, 0, mode * 10, 0x80000001);
            *(s16 *)(state + 0xC4) -= mode;
        }
    }
post_change:
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            *(u32 *)(state + i*8 + 4 + j*4) =
                fn_1_151BE8(state[i*8], j);
        }
    }
    {
        u32 *flags = lbl_3_bss_243C0;
        if ((*flags & 1) && (*flags & 2)) {
            for (i = 0; i < 3; i++) {
                u8 *recp = (u8 *)((u8 *)lbl_3_bss_243C0 + 0x10000) + i*8;
                u8 *sp = state + i*8;
                if (*recp == *sp) fn_80008BA8(sp + 4, recp + 4, 4);
            }
        }
    }
done_selection:
    if (selected == 3) {
        if (change) {
            fn_3_BD00(1, 0, 10, 0x00100001);
            return 0;
        }
        {
            s16 *r = (s16 *)((u8 *)arr + off);
            if (((*(u16 *)(r+8) & 1) || (*(u16 *)r & 1))) mode = -1;
            if (((*(u16 *)(r+8) >> 1) & 1) || ((*(u16 *)r >> 1) & 1)) mode++;
        }
        if (mode) {
            fn_1_A2D84(0xA9010000);
            if (mode < 0) fn_3_BD00(mode, 0, mode*5, 0x00200001);
            else fn_3_BD00(mode, 0, mode*5, 0x00400001);
        }
        item = state;
        i = 0;
        while (i < 41 && lbl_3_bss_7EBB0[i] != *(s16 *)(state+0xCE)) i++;
        found = i;
        for (;;) {
            s16 lim = lbl_3_bss_7EC02;
            value = found + mode;
            value = value >= lim ? 0 : (value < 0 ? lim-1 : value);
            found = value;
            if (fn_1_F7BE4(lbl_3_bss_7EBB0[found])) break;
        }
        *(s16 *)(state + 0xCE) = lbl_3_bss_7EBB0[found];
    }
    {
        u8 *base = (u8 *)&lbl_3_bss_140 + *(s16 *)(g + 0xF8) * 0x81C0;
        fn_80008BA8(base + 0x81A4, state, 0x18);
        {
            s16 *r = (s16 *)((u8 *)arr + off);
            *(u8 *)(base + 0x81A0) = *(u8 *)(state + 0xCE);
            if ((*(u16 *)(r+4) >> 11) & 1) {
                result = fn_8008023C(lbl_3_bss_243C0, base, 0x81C0);
                if (result) { fn_1_A2D84(0xA9010100); *(s16 *)(g+0x18)=10; }
                code = 12;
            }
            if (((*(u16 *)r >> 3) & 1) || ((*(u16 *)r >> 7) & 1)) {
                result = fn_8008023C(lbl_3_bss_243C0, base, 0x81C0);
                if (result) fn_1_A2D84(0xA9010100);
                else fn_1_A2D84(0xA9010200);
                *(s16 *)(g+0x18)=10; code=11;
            }
            if ((*(u16 *)r >> 9) & 1) {
                fn_1_A2D84(0xA9010200); code=13; *(s16 *)(g+0x18)=10;
            }
        }
    }
    return code;
}
