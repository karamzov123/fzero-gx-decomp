/* Non-matching: best partial attempt (4.48% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D118(f32);
extern s32 fn_80077B14(void *);
extern void fn_8006E250(void *, void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006E1B0(void *, void *);

typedef struct {
    u8 flags;
    u8 pad1[1];
    u8 count;
    u8 pad3[1];
    u16 indices[16];
    f32 radius;
    u8 padA[2];
    f32 x, y, z;
    f32 px, py, pz;
    f32 qx, qy, qz;
    f32 dx, dy, dz;
    u8 pad40[4];
    f32 mass;
} Node;

typedef struct { Node *a; Node *b; f32 dist; } Pair;

void fn_1_10AD18(void *arg) {
    u8 *m = (u8 *)arg;
    Node *nodes;
    Pair *pairs;
    u8 *base;
    u32 i, j;
    f32 dx, dy, dz, d2, scale, t, a, b, c;
    if (arg == 0 || *(u32 *)(m + 16) == 0) return;
    fn_80077B14(*(void **)(m + 16));
    if ((m[0] & 2) != 0) {
        u32 idx;
        m[0] &= ~2;
        idx = *(u32 *)&lbl_1_data_3FFBC.unk_0; /* replaced below */
    }
}
