#include "types.h"

typedef struct RNAResEntry {
    s32 used;
    u32 unk_4;
    u32 unk_8;
} RNAResEntry;

typedef struct fn_8005BFB4_Globals {
    u32 count;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    RNAResEntry entries[32];
} fn_8005BFB4_Globals;

extern fn_8005BFB4_Globals lbl_80192BD0;
extern u32 ARFree(u32 *);
extern void fn_8005A5BC(const char *message);
extern char lbl_800929AC[43];
extern void *memset(void *, int, u32);

void fn_8005BFB4(void) {
    fn_8005BFB4_Globals *p;
    RNAResEntry *e;
    u32 stamp;
    u32 zero;
    u32 i;
    u32 k;
    u32 j;

    p = &lbl_80192BD0;
    if (--p->count == 0) {
        e = &p->entries[0];
        zero = 0;
        for (i = 0; i < 32; i++) {
            if (e->used == 1 && e != 0) {
                e->used = zero;
            }
            e++;
        }
        e = &p->entries[0];
        memset(e, 0, 0x180);
        if (((0) == (p->unk_4))) {
            ARFree(&stamp);
            if (stamp != p->unk_C) {
                fn_8005A5BC(lbl_800929AC);
            }
            p->unk_8 = 0;
            p->unk_C = 0;
            p->unk_10 = 0;
        }
    }
}
