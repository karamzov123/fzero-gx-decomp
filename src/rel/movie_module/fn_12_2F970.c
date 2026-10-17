#include "types.h"
struct Sig_fn_12_2269C_fn_12_2269C_Copy16 { u32 a[4]; };
extern void fn_12_2269C(u8 *, int, int, struct Sig_fn_12_2269C_fn_12_2269C_Copy16 *);
struct MovieSlot { u32 pre; struct Sig_fn_12_2269C_fn_12_2269C_Copy16 copy; };
struct MovieState { u8 pad[0x1cc8]; struct MovieSlot *slots; u8 pad2[4]; s32 value; };
typedef struct Fn122F970Loop { u32 zero; int index; } Fn122F970Loop;
#pragma opt_loop_invariants off
int fn_12_2F970(struct MovieState *arg0) {
    Fn122F970Loop s;
    struct MovieSlot *p;
    u32 *fzgx_live;
    u32 v;
    p = (struct MovieSlot *)((u8 *)arg0 + 0x28d4);
    arg0->slots = p;
    v = arg0->value;
    s.zero = 0;
    p->pre = s.zero;
    s.index = s.zero;
    do {
        fzgx_live = p->copy.a;
        fzgx_live[0] = s.zero;
        fzgx_live = p->copy.a;
        fzgx_live[1] = s.zero;
        fzgx_live = p->copy.a;
        fzgx_live[2] = s.zero;
        fzgx_live = p->copy.a;
        fzgx_live[3] = s.zero;
        fn_12_2269C((u8 *)arg0, v, s.index, &p->copy);
        s.index++;
        p = (struct MovieSlot *)((u8 *)p + 0x10);
    } while (s.index < 3);
    return 0;
}
#pragma opt_loop_invariants reset
