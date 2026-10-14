/* Non-matching: best partial attempt (93.89% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/burner.h"
extern void *fn_1_435C(void *);
extern u8 lbl_1_data_1EA28[12];
extern void fn_1_F78AC(void *);
extern void fn_1_F78D8(void *);
extern void fn_1_789E8(void);
extern void fn_1_9A5CC(void);
extern void fn_1_7E9C4(void);
extern void fn_1_78EBC(void);
extern void fn_1_9A7BC(void);
extern void fn_1_3F8EC(void);
extern void fn_1_E38D4(void);
extern void fn_1_E39F0(void);
extern void fn_1_E95B4(void);
extern void fn_1_E49D4(void);
extern void fn_1_C42F4(void);
extern void *fn_1_3F8C(void *, void *, void *, u32);
extern u32 lbl_1_bss_8B5F4[8];
extern u32 fn_1_46A8C(u32);
extern void fn_1_3F75C(void);
extern void fn_1_D19B8(u8 *);
extern void fn_1_3F7A0(u32 *);
extern u32 fn_1_46B44(void *, void *);
extern void fn_1_411A4(u32);
extern u32 fn_80008E84(u32);
extern u32 fn_1_7ACDC(u32);
extern u32 fn_1_12EF80(u32, void *, void *);
extern void fn_1_3F8D0(void);
extern u32 fn_1_E3324(void);
extern void fn_1_154708(void *);
extern void *fn_1_86254(int);
extern u32 fn_1_C3A0C(void);
extern void fn_1_43E8(u32);
extern void fn_1_43F4(void);
extern volatile u32 lbl_801A6410;
extern u32 lbl_801A63C0;
#define PTR(b,o) (*(void **)((b)+(o)))
#define WORD(b,o) (*(u32 *)((b)+(o)))
static inline void *course_data(u8 id) {
    int special = 0;
    if (id == 5 || id == 21) special = 1;
    if (special) return lbl_1_data_1EA28;
    return ((void **)lbl_1_data_2A8D8)[((u8 *)&lbl_1_data_2B0D4)[id]];
}
#pragma opt_common_subs off
#pragma opt_propagation off
static inline void fn_1_30054_call_fn_1_154708(void * a0) { fn_1_154708(a0); }
void fn_1_30054(void) {
    s32 tmp_call35;
    u8 *base = &lbl_1_bss_3C00;
    u8 *data = (u8 *)&lbl_1_data_5730;
    u8 *hi = base + 0x20000;
    u8 *state;
    u32 saved;
    s16 a;
    s16 b;
    u32 rand;
    s32 tmp_call13;
    void * lab_t0;
    fn_1_435C(PTR(hi,0x20A4));
    state = base + 0x30;
    {
        void *course;
        void *task;
        course = course_data(state[6]);
        task = fn_1_3F8C(data+0xBE0, fn_1_F78AC, course,5);
        PTR(hi,0x20A8) = task;
        course = course_data(state[6]);
        task = fn_1_3F8C(data+0xBE0, fn_1_F78AC, course,24);
        course = ((void **)lbl_1_data_2A92C)[((u8 *)&lbl_1_data_2B0D4)[state[6]]];
        PTR(hi,0x20AC) = task;
        PTR(hi,0x20B0) = fn_1_3F8C(data+0xBF0, fn_1_F78D8, course,16);
    }
    fn_1_435C(PTR(hi,0x1F88));
    PTR(hi,0x20B4) = fn_1_3F8C(data+0xC00,fn_1_789E8,0,21);
    PTR(hi,0x20B8) = fn_1_3F8C(data+0xC0C,fn_1_9A5CC,0,23);
    fn_1_435C(PTR(hi,0x20A4));
    PTR(hi,0x20BC) = fn_1_3F8C(data+0xC1C,fn_1_7E9C4,0,4);
    PTR(hi,0x20C0) = fn_1_3F8C(data+0xC24,fn_1_78EBC,0,7);
    PTR(hi,0x20C4) = fn_1_3F8C(data+0xC30,fn_1_9A7BC,0,10);
    if (*(s16 *)&lbl_1_bss_960 != 10 && *(s16 *)&lbl_1_bss_960 != 12) {
        fn_1_46A8C(lbl_1_bss_8B5F4[1]);
        lbl_1_bss_8B5F4[4] = lbl_1_bss_8B5F4[1];
        fn_1_3F75C();
        tmp_call13 = WORD(hi,0x20C8);
        if (tmp_call13 != 0 && data[0x44C] != 2) fn_1_D19B8(base+0x163C);
        fn_1_46B44(fn_1_3F7A0, &lbl_1_bss_8B5F4[5]);
    }
    fn_1_411A4(2);
    (void)lbl_801A6410;
    saved = fn_80008E84(WORD(hi,0x20CC));
    fn_1_7ACDC(state[6]);
    (void)lbl_801A6410;
    fn_80008E84(saved);
    fn_1_12EF80(state[6],&a,&b);
    if (a != -1) {
        PTR(hi,0x20D0) = (u8 *)&lbl_1_bss_7F0C0 + a*0x900 + b*0x180 + 0xF8;
    } else {
        u8 *fallback = hi+0x20D4;
        PTR(hi,0x20D0) = fallback;
        fallback[0x163] = 0;
    }
    fn_1_3F8D0();
    fn_1_435C(PTR(hi,0x20A4));
    PTR(hi,0x2254) = fn_1_3F8C(data+0xC40,fn_1_3F8EC,0,28);
    fn_1_E3324();
    fn_1_435C(PTR(hi,0x20A4));
    PTR(hi,0x2258) = fn_1_3F8C(data+0xC50,fn_1_E38D4,0,9);
    PTR(hi,0x225C) = fn_1_3F8C(data+0xC5C,fn_1_E39F0,0,11);
    PTR(hi,0x2260) = fn_1_3F8C(data+0xC6C,fn_1_E95B4,0,0);
    lab_t0 = PTR(hi,0x1F88);
    fn_1_435C(lab_t0);
    PTR(hi,0x2264) = fn_1_3F8C(data+0xC80,fn_1_E49D4,0,8);
    (void)lbl_801A6410;
    fn_1_30054_call_fn_1_154708(PTR(hi,0x20A4));
    (void)lbl_801A6410;
    fn_1_86254(0);
    fn_1_C3A0C();
    fn_1_435C(PTR(hi,0x1F88));
    fn_1_43E8(0x101);
    PTR(base,0x14) = fn_1_3F8C(data+0xC8C,fn_1_C42F4,fn_1_86254(0),2);
    fn_1_43F4();
    {
        u32 flags = WORD(base,0x30);
        void (*callback)(void *) = (void (*)(void *))PTR(hi,0x2274);
        WORD(hi,0x226C) = 0;
        saved = lbl_801A63C0;
        rand = saved;
        (void)lbl_801A6410;
        rand = rand * 0x676A4B6B + 0x33CB;
        lbl_801A63C0 = rand;
        WORD(hi,0x2268) = (rand >> 16) & 0x7FFF;
        WORD(hi,0x2270) = 0;
        WORD(base,0x30) = flags & ~0x4000;
        if (callback) callback(base+0x30);
    }
}
