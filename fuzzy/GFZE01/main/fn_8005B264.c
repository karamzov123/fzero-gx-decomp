/* Non-matching: best partial attempt (91.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef void (*fn_8005B264_Fn)(void *);

typedef struct fn_8005B264_Vtbl {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    fn_8005B264_Fn fn14;
} fn_8005B264_Vtbl;

typedef struct fn_8005B264_Node {
    fn_8005B264_Vtbl *vtable;
} fn_8005B264_Node;

typedef struct fn_8005B264_Obj {
    u8 unk0;
    u8 flag;
    u8 unk2;
    s8 count;
    s32 unk4;
    u32 unk8[12];
    fn_8005B264_Node *nodes[2];
    u32 a[2][2];
    u32 b[2][2];
    s32 d[2];
    u32 e;
    u32 f;
    s32 arr70[2];
    u32 g;
    u32 h;
    u32 pad80[10];
    u32 padA8[8][8];
} fn_8005B264_Obj;

extern char lbl_80092790[44];
extern void fn_8005A648(void);
extern void fn_8005A628(void);
extern void fn_8005A5BC(char *);
extern void *memset(void *, int, u32);

static inline s32 fn_8005B264_array_read(s32 index, s32 *array) { return array[index]; }
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
void fn_8005B264(fn_8005B264_Obj *arg0, s32 arg1) {
    fn_8005B264_Obj *p;
    s32 i;
    s32 v0;
    char *tbl;

    p = arg0;
    tbl = lbl_80092790;
    if (p == 0) {
        return;
    }
    v0 = (p != 0) ? (p->flag & 1) : -1;
    if (arg1 == v0) {
        return;
    }
    if (arg1 == 1) {
        fn_8005A648();
        for (i = 0; i < p->count; i++) {
            p->nodes[i]->vtable->fn14(p->nodes[i]);
            memset(&p->a[i], 0, 8);
            memset(&p->b[i], 0, 8);
            memset(p->padA8[i], 0, 0x20);
            p->d[i] = 0;
        }
        p->e = 0;
        p->f = 0;
        p->g = 0;
        p->h = 0;
        p->unk4 = -1;
        p->flag |= 1;
        fn_8005A628();
    } else if (arg1 == 0) {
        s32 k;
        s32 n;
        s32 j;
        s32 t = 100000;

        for (k = 0; k < p->count; k++) {
            for (n = 0; n < 200; n++) {
                if (fn_8005B264_array_read(k, p->d) != 0) {
                    break;
                }
                for (j = 0; j < t; j += 8) ;
            }
            if (n == 200) {
                fn_8005A5BC(tbl + 0x64);
                return;
            }
            for (n = 0; n < 200; n++) {
                if (fn_8005B264_array_read(k, p->arr70) == 0) {
                    break;
                }
                for (j = 0; j < t; j += 8) ;
            }
            if (n == 200) {
                fn_8005A5BC(tbl + 0x9c);
                return;
            }
        }
        p->flag &= 2;
    } else {
        fn_8005A5BC(tbl + 0xd4);
    }
}
#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset

