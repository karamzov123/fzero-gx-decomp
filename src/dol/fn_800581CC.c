#include "types.h"


/* --- dol/fn_800581CC.c --- */
typedef struct Fn800581CC_Ring {
    u8 pad_0[0xC];
    s32 write_avail;
    s32 read_avail;
    s32 read_pos;
    s32 write_pos;
    u8 *base;
    s32 size;
    s32 mirror;
    s32 read_total;
    u8 pad_2C[0x4];
    s32 write_total;
    u8 pad_34[0x4];
    void (*callback)(s32, s32);
    s32 callback_arg;
} Fn800581CC_Ring;

typedef struct Fn800581CC_Chunk {
    u8 *ptr;
    s32 len;
} Fn800581CC_Chunk;

extern u32 fn_80057728(void);
extern void fn_800576DC(void);

void fn_800581CC(Fn800581CC_Ring *ring, s32 mode, s32 max, Fn800581CC_Chunk *chunk) {
    s32 space;

    fn_80057728();
    if (mode == 0) {
        space = ring->mirror + (ring->size - ring->read_pos);
        chunk->len = ring->read_avail < space ? ring->read_avail : space;
        chunk->len = chunk->len < max ? chunk->len : max;
        chunk->ptr = ring->base + ring->read_pos;
        ring->read_pos = (ring->read_pos + chunk->len) % ring->size;
        ring->read_avail -= chunk->len;
        ring->read_total += chunk->len;
    } else if (mode == 1) {
        space = ring->mirror + (ring->size - ring->write_pos);
        chunk->len = ring->write_avail < space ? ring->write_avail : space;
        chunk->len = chunk->len < max ? chunk->len : max;
        chunk->ptr = ring->base + ring->write_pos;
        ring->write_pos = (ring->write_pos + chunk->len) % ring->size;
        ring->write_avail -= chunk->len;
        ring->write_total += chunk->len;
    } else {
        chunk->len = 0;
        chunk->ptr = NULL;
        if (ring->callback != NULL) {
            ring->callback(ring->callback_arg, -3);
        }
    }
    fn_800576DC();
}

/* --- dol/fn_80058380.c --- */
typedef struct Fn80058380Object Fn80058380Object;
typedef void (*Fn80058380Callback)(void *, int);

struct Fn80058380Object {
    u8 pad_0x00[0x0C];
    int value_0x0C;
    int value_0x10;
    u8 pad_0x14[0x24];
    Fn80058380Callback callback;
    void *callback_context;
};

int fn_80058380(Fn80058380Object *object, int mode) {
    if (mode == 1) {
        return object->value_0x0C;
    }
    if (mode == 0) {
        return object->value_0x10;
    }
    if (object->callback) {
        object->callback(object->callback_context, -3);
    }
    return 0;
}
