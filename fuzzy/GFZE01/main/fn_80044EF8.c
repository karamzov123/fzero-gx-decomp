/* Non-matching: best partial attempt (90.87% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern s32 fn_8004E270(u32);
extern s32 fn_8004E204(u32, u32, u32, u32, u32);
extern void fn_8004E1E4(u32);
extern s32 fn_8004E238(u32, u32, u32, u32);
extern void ADXPD_ExecHndl(u32);
extern u32 fn_8004E190(u32);
extern void fn_8004E198(u32);

struct fn_80044EF8_Arg0 {
    u8 pad_0[0x4];
    s32 unk_4;
    u32 unk_8;
    u8 pad_c[0x34];
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s16 *unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    s32 unk_70;
    u32 unk_74;
    u32 (*unk_78)(u32, s32 *, s32 *, s32 *);
    u32 unk_7c;
    u32 (*unk_80)(u32, u32, u32);
    u32 unk_84;
    u8 pad_88[0x8];
    s32 unk_90;
    s32 unk_94;
};

#define COPYSHORTS(d, s, cnt)                                                     \
    do {                                                                          \
        s16 *p_ = (d);                                                            \
        s16 *q_ = (s);                                                            \
        s32 m_ = (cnt);                                                           \
        while (m_ > 0) {                                                          \
            *p_++ = *q_++;                                                        \
            m_--;                                                                 \
        }                                                                         \
    } while (0)

#pragma opt_common_subs on
static inline u32 (* fn_80044EF8_read_pointer(struct fn_80044EF8_Arg0 * owner))(u32, u32, u32) { return owner->unk_80; }
static inline s32 fn_80044EF8_operand(u32 right, u32 left) { left *= right; return left; }
#pragma opt_dead_assignments on
#pragma opt_loop_invariants off
#pragma opt_lifetimes off
#pragma opt_propagation on
static inline s32 fn_80044EF8_operand_(s32 left, s32 right) { left *= right; return left; }
static inline s32 fn_80044EF8_operand__(s32 right, s32 left) { left *= right; return left; }
#pragma opt_strength_reduction off
void fn_80044EF8(struct fn_80044EF8_Arg0 *a) {
    u32 (* fzgx_live)(u32, s32 *, s32 *, s32 *);
    s32 lab_v;
    s32 f40;
    s32 lab_v_2;
    if (a->unk_4 == 1) {
        if (fn_8004E270(a->unk_8) == 0) {
            s32 f58;
            s32 t58;
            s32 f60;
            s32 sum;
            s32 r1;
            s32 c1;
            s32 c2;
            s32 v;
            s32 q2;
            fzgx_live = a->unk_78;
            fzgx_live(a->unk_7c, &a->unk_68, &a->unk_6c, &a->unk_70);
    lab_v = a->unk_58;
            f58 = lab_v;
            t58 = f58 - 1;
            f60 = a->unk_60;
            sum = a->unk_70 + t58;
            r1 = t58 - (sum % f58);
            c1 = (f60 - (*(s32 volatile *)&(a->unk_68)) /* Retail reloads this field. */ - 1 + f58) / f58;
            c2 = a->unk_6c;
            v = a->unk_4c / a->unk_50;
            if (sum / f58 < c1 && ((*(s32 volatile *)&(a->unk_68)) /* Retail reloads this field. */ + fn_80044EF8_operand((f58), (c1))) - r1 < f60) {
                c1++;
            }
            if (a->unk_70 < a->unk_6c) {
                c2 += r1;
            }
            q2 = c2 / f58;
            if (v > q2) {
                v = q2;
            }
            if (v > sum / f58) {
                v = sum / f58;
            }
            if (v > c1) {
                v = c1;
            }
            if (a->unk_50 == 2) {
                u32 p = a->unk_8;
                v <<= 1;
                fn_8004E204(p, a->unk_48, v, (u32)(a->unk_5c + (a->unk_68)),
                            (u32)(a->unk_5c + (a->unk_68) + a->unk_64));
                fn_8004E1E4(p);
            } else {
                u32 p = a->unk_8;
                fn_8004E238(p, a->unk_48, v, (u32)(a->unk_5c + (*(s32 volatile *)&(a->unk_68)) /* Retail reloads this field. */));
                fn_8004E1E4(p);
            }
            a->unk_4 = 2;
        }
    }
    if (a->unk_4 == 2) {
        ADXPD_ExecHndl(a->unk_8);
        if (fn_8004E270(a->unk_8) == 3) {
            s32 f44;
            s32 pos;
            s16 *buf;
            s32 r2;
            s32 f54;
            s32 f58;
            s32 t58;
            s32 sum;
            s32 res;
            s32 out;
            s32 n;
            f58 = lab_v;
            t58 = f58;
            t58 = t58 - 1;
            f54 = ((*(s32 volatile *)&(a->unk_54)) /* Retail reloads this field. */);
            lab_v_2 = (*(s32 volatile *)&(a->unk_68))                                 ;
            pos = lab_v_2;
            sum = a->unk_70 + t58;
            buf = a->unk_5c;
            r2 = t58 - (sum % f58);
            f40 = a->unk_40;
            lab_v = a->unk_44;
            f44 = lab_v;
            res = fn_8004E190(a->unk_8);
            out = fn_80044EF8_operand_((res), (f58)) / a->unk_50;
            if (fn_80044EF8_operand__(((sum / f58)), (a->unk_50)) <= res) {
                out -= r2;
            }
            a->unk_90 = out;
            a->unk_94 = res * f54;
            pos += out;
            if (pos >= f40) {
                lab_v_2 = f40 - pos;
                n = lab_v_2;
                if (a->unk_50 == 2) {
                    COPYSHORTS(buf, buf + f40, n);
                    COPYSHORTS(buf + f44, (((f44) + (f40)) + (buf)), n);
                } else {
                    COPYSHORTS(buf, buf + f40, n);
                }
            }
            fn_8004E198(a->unk_8);
            fn_80044EF8_read_pointer(a)(a->unk_84, a->unk_94, a->unk_90);
            a->unk_4 = 3;
        }
    }
}
#pragma opt_strength_reduction reset

#pragma opt_propagation reset

#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

