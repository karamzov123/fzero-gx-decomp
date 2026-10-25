/* Non-matching: best partial attempt (96.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"
typedef struct Sig_fn_1_5158C_FontDrawPacket Sig_fn_1_5158C_FontDrawPacket;
extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_155F7C(void);
extern u32 fn_1_155F8C(void);
extern void fn_1_51564(u16,u16,u16,u16,u16,u16);
extern void fn_1_5158C(Sig_fn_1_5158C_FontDrawPacket *,u32,s16,s16);
typedef struct Packet { u32 id; f32 x,y,z; u32 rest[18]; } Packet;
typedef struct Arg { u8 pad[0x20]; s32 index; u8 pad24[0x28]; s32 number; u8 pad50[0x14]; s32 y; u32 pad68; s32 x; u8 pad70[0xbc]; Packet packet; } Arg;
typedef struct Pool { u8 pad[0xb0]; Packet packet; u8 pad108[0x20]; f64 bias; u8 pad130[0x304]; f32 z33; u8 pad438[0x44]; u32 color[2]; f32 z41; } Pool;
extern Pool lbl_1_rodata_92C0;
static f32 tofloat(s32 n, Pool *pool) {
    union { f64 d; struct { u32 hi, lo; } w; } v;
    v.w.hi = 0x43300000;
    v.w.lo = (u32)n ^ 0x80000000;
    return (f32)(v.d - pool->bias);
}
static s32 eligible(s32 mode) { return mode == 8 || mode == 2 || mode == 3; }
static s32 range8(s32 mode) { return mode == 8 || mode == 9; }
static s32 range4(s32 mode) { return mode == 4 || mode == 5; }
static s32 excluded(s32 mode) { s32 r = 1; if (!range8(mode) && mode != 10) r = 0; return r; }
static s32 special9(s32 mode) { s32 r = 1; if (!range4(mode) && mode != 9) r = 0; return r; }
static s32 special10(s32 mode) { s32 r = 1; if (!special9(mode) && mode != 10) r = 0; return r; }
static s32 special(s32 mode) { s32 r = 1; if (!special10(mode) && mode != 6) r = 0; return r; }
#pragma opt_propagation off
void fn_1_147188(s32 mode, Arg *arg) {
    Pool *pool = &lbl_1_rodata_92C0;
    Packet p;
    s32 selected;
    if (eligible(mode)) {
        if (!excluded(mode)) {
            p = arg->packet;
            {
                f32 x = tofloat(arg->x + 138, pool);
                f32 y = tofloat(arg->y + 3, pool);
                p.id = 39175;
                p.x = x;
                p.y = y;
                p.z = pool->z41;
            }
            fn_1_4F734((FontDrawPacket *)&p);
            p = pool->packet;
            if (mode == 10 || mode == 6) {
                selected = arg->index == 0;
            } else if (special(mode)) {
                selected = 0;
                if ((s32)fn_1_155F7C() != 0 && arg->index == (s32)fn_1_155F8C()) selected = 1;
            } else {
                selected = lbl_1_bss_3C30.unk_8 > arg->number;
            }
            if (selected) {
                p.id = 38686;
                fn_1_51564(0,0,24,20,2,2);
                fn_1_5158C((Sig_fn_1_5158C_FontDrawPacket *)&p,p.id,arg->number % 2,arg->number / 2);
            } else {
                p.id = 38687;
                fn_1_51564(0,0,24,20,2,2);
                fn_1_5158C((Sig_fn_1_5158C_FontDrawPacket *)&p,p.id,arg->index % 2,(arg->index / 2) % 2);
                if (lbl_1_bss_8E548 > 4) {
                    p.rest[10] = pool->color[0];
                    p.rest[11] = pool->color[1];
                }
            }
            {
                f32 x = tofloat(arg->x + 164, pool);
                f32 y = tofloat(21 + arg->y, pool);
                p.x = x;
                p.y = y;
                p.z = pool->z33;
            }
            fn_1_4F734((FontDrawPacket *)&p);
        }
    }
}
#pragma opt_propagation reset

