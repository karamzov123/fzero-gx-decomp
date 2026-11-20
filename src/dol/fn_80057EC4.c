#include "types.h"


/* --- dol/fn_80057EC4.c --- */
struct fn_80057EC4_Arg2 {
    u8 pad_0[0x4];
    u32 unk_4;
};

extern u32 fn_800576DC(void);
extern u32 fn_80057728(void);

u32 fn_80057EC4(u8 *arg0, s32 arg1, struct fn_80057EC4_Arg2 *arg2) {
    s32 (*temp_r12)(s32, s32);
    s32 t;
    s32 a;
    s32 b;

    if ((s32)arg2->unk_4 > 0) {
        if (*(u32 *)(arg2) == 0) {
            return (u32)arg0;
        }
        fn_80057728();
        if (arg1 == 0) {
            t = *(s32 *)(arg0 + 0x20);
            a = *(s32 *)(arg0 + 0x14) + t - arg2->unk_4;
            b = (s32)*(u32 *)(arg2) - *(s32 *)(arg0 + 0x1c);
            if (a % t == b % t) {
                *(s32 *)(arg0 + 0x14) = a % t;
                *(u32 *)(arg0 + 0x10) += arg2->unk_4;
            } else {
                temp_r12 = (s32 (*)(s32, s32))(*(s32 (**)(s32, s32))(arg0 + 0x38));
                if (temp_r12 != NULL) {
                    temp_r12(*(s32 *)(arg0 + 0x3c), -3);
                }
            }
            *(u32 *)(arg0 + 0x28) -= arg2->unk_4;
        } else if (arg1 == 1) {
            t = *(s32 *)(arg0 + 0x20);
            a = *(s32 *)(arg0 + 0x18) + t - arg2->unk_4;
            b = (s32)*(u32 *)(arg2) - *(s32 *)(arg0 + 0x1c);
            if (a % t == b % t) {
                *(s32 *)(arg0 + 0x18) = a % t;
                *(u32 *)(arg0 + 0xc) += arg2->unk_4;
            } else {
                temp_r12 = (s32 (*)(s32, s32))(*(s32 (**)(s32, s32))(arg0 + 0x38));
                if (temp_r12 != NULL) {
                    temp_r12(*(s32 *)(arg0 + 0x3c), -3);
                }
            }
            *(u32 *)(arg0 + 0x30) -= arg2->unk_4;
        } else {
            arg2->unk_4 = 0;
            *(u32 *)((u8 *)arg2 + 0) = 0;
            temp_r12 = (s32 (*)(s32, s32))(*(s32 (**)(s32, s32))(arg0 + 0x38));
            if (temp_r12 != NULL) {
                temp_r12(*(s32 *)(arg0 + 0x3c), -3);
            }
        }
        return fn_800576DC();
    }
    return (u32)arg0;
}

/* --- dol/fn_80058070.c --- */
/* --- dol/fn_80058070.c --- */
typedef struct SjRing {
    u8 pad_0[0xC];
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    char *unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    void (*unk38)(int, int);
    int unk3C;
} SjRing;

typedef struct SjSpan {
    char *ptr;
    int len;
} SjSpan;

extern void *memcpy(void *, const void *, u32);

void fn_80058070(SjRing* p, int mode, SjSpan* span)
{
    if (span->len <= 0 || span->ptr == 0) {
        return;
    }

    fn_80057728();

    if (mode == 1) {
        p->unkC += span->len;

        {
            int offset = (int)span->ptr - (int)p->unk1C;
            if (offset < p->unk24) {
                int n = p->unk24 - offset;
                if (span->len < n) {
                    n = span->len;
                }
                {
                    char* d = (char*)offset + (int)p->unk1C;
                    d = (char*)p->unk20 + (int)d;
                    memcpy(d, span->ptr, n);
                }
            }
        }

        {
            int end_offset = span->ptr - p->unk1C + span->len;
            if (end_offset > p->unk20) {
                int n = end_offset - p->unk20;
                if (span->len < n) {
                    n = span->len;
                }
                memcpy(p->unk1C, p->unk1C + (end_offset - n), n);
            }
        }

        p->unk34 += span->len;
    } else if (mode == 0) {
        p->unk10 += span->len;
        p->unk2C += span->len;
    } else {
        span->len = 0;
        span->ptr = 0;
        if (p->unk38 != 0) {
            p->unk38(p->unk3C, -3);
        }
    }

    fn_800576DC();
}

/* --- dol/fn_800581CC.c --- */
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
