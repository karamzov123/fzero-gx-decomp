#include "types.h"

typedef struct {
    int state;
    u32 b;
    u32 c;
} Fn8005C120Entry;

typedef struct {
    u32 count;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    Fn8005C120Entry entries[32];
} Fn8005C120State;

extern Fn8005C120State lbl_80192BD0;
extern u32 ARAlloc(u32);
extern void *memset(void *, int, u32);

#pragma opt_propagation off
void fn_8005C120(void) {
    u32 off;
    u32 fzgx_value;
    u32 addr;
    Fn8005C120State *s = (Fn8005C120State *)&lbl_80192BD0;
    if (s->count == 0) {
        u32 i;
        u32 n;
        u32 base;
        Fn8005C120Entry *e;
        if (s->unk04 == 0) {
            s->unk08 = 32;
            s->unk0C = 0x40000;
            s->unk10 = ARAlloc(0x40000);
        }
        memset(s->entries, 0, 0x180);
        n = s->unk08;
        base = s->unk10;
        off = 0;
        e = s->entries;
        i = 0;
        for (; n > i; n--) {
            addr = base + off;
            e->b = addr >> 1;
            fzgx_value = 0x1000;
            e->c = fzgx_value;
            off += 0x2000;
            e++;
        }
    }
    s->count++;
}
#pragma opt_propagation reset

