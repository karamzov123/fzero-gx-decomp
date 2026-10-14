/* Non-matching: best partial attempt (96.26% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#include "dolphin/os/OSTime.h"

struct fn_80033EB0_gx_T {
    u8 pad_0[0x4F2];
    u8 unk_4F2;
};

struct fn_80033EB0_memReg_T {
    u8 pad_0[0x4E];
    u16 unk_4E;
    u16 unk_50;
};

extern OSTime OSGetTime(void);
extern struct fn_80033EB0_gx_T *gx;
extern struct fn_80033EB0_memReg_T *__memReg;
extern u32 fn_80032368(void);
extern vu32 __PIRegs[];

#pragma opt_lifetimes off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_80033EB0(void) {
    struct fn_80033EB0_memReg_T *m;
    u32 old;
    u32 cur;
    u32 t_2;
    u32 hi;
    u32 lo;
    u32 t;
    u16 *lp;
    u16 *hp;
    OSTime start;
    OSTime now;
    vu32 *pi;
    u32 fzgx_frame_pad[2];  /* fzgx: retail frame home */

    if (((0) != (gx->unk_4F2)) && fn_80032368() != 0) {
        m = __memReg;
        hp = (u16 *)((u8 *)m + 0x4E);
        hi = (*((hp) + (0)));
        lp = (u16 *)((u8 *)m + 0x50);
        do {
            t = hi;
            hi = (*((hp) + (0)));
            lo = (*((lp) + (0)));
        } while (((((hi)) != ((t)))));
        old = (hi << 16) | lo;

        for (;;) {
            start = (OSGetTime());
            do {
                now = OSGetTime();
            } while ((s64)(now - start) <= 8);

            m = __memReg;
            hp = (u16 *)((u8 *)m + 0x4E);
            hi = (*((hp) + (0)));
            lp = (u16 *)((u8 *)m + 0x50);
            do {
                t_2 = hi;
                hi = (*((hp) + (0)));
                lo = (*((lp) + (0)));
            } while (((((hi)) != ((t_2)))));
            cur = (hi << 16) | lo;
            if (((((cur)) != ((old))))) {
                old = cur;
                continue;
            }
            break;
        }
    }

    pi = (vu32 *)((u8 *)0xCC000000 + 0x3000);  /* fzgx-allow: A1 fixed PPC hardware address */
    *(volatile vu32 *)((u8 *)pi + 0x18) = 1;

    start = (OSGetTime());
    do {
        now = OSGetTime();
    } while ((s64)(now - start) <= 50);

    *(volatile vu32 *)((u8 *)pi + 0x0) = 0;

    start = OSGetTime();
    do {
        now = OSGetTime();
    } while ((s64)(now - start) <= 5);
}
#pragma opt_propagation reset

#pragma opt_common_subs reset

#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset
