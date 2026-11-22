#include "types.h"

extern u32 fn_800576DC(void);
extern u32 fn_80057728(void);
extern void *memset(void *dst, int val, u32 n);
extern u32 lbl_8018B2A0[];
extern u32 lbl_8018B2A4[];
extern u8 lbl_80132300[];
extern u8 lbl_80092330[];
extern const f32 lbl_8009232C[];


u32 fn_80057D88(u32 arg0, u32 arg1, u32 arg2) {
    u8 *ptr = (u8 *)arg0 + (arg1 << 3);
    ptr += arg2 << 2;
    return *(u32 *)(ptr + 0x28);
}

struct fn_80057DA0_Arg0 {
    u8 pad_0[0x24];
    u32 unk_24;
};

u32 fn_80057DA0(struct fn_80057DA0_Arg0 *arg0) {
    return arg0->unk_24;
}

struct fn_80057DA8_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};

u32 fn_80057DA8(struct fn_80057DA8_Arg0 *arg0) {
    return arg0->unk_20;
}

struct fn_80057DB0_Arg0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};

u32 fn_80057DB0(struct fn_80057DB0_Arg0 *arg0) {
    return arg0->unk_1C;
}

typedef struct Fn80057DB8Object Fn80057DB8Object;
typedef void (*Fn80057DB8Callback)(void *, int);

struct Fn80057DB8Object {
    u8 pad_0x00[0x0c];
    int value_0c;
    int value_10;
    int value_14;
    int value_18;
    u8 pad_0x1c[0x04];
    int value_20;
    int value_24;
    u8 pad_0x28[0x10];
    Fn80057DB8Callback callback_38;
    void *callback_arg_3c;
};


int fn_80057DB8(Fn80057DB8Object *object, int mode, int limit, int *result) {
    int value;
    int clamped;

    fn_80057728();
    if (mode == 0) {
        value = object->value_24;
        value += object->value_20 - object->value_14;
        if (object->value_10 < value) {
            value = object->value_10;
        }
        clamped = limit;
        if (value < limit) {
            clamped = value;
        }
        mode = clamped;
    } else if (mode == 1) {
        value = object->value_24;
        value += object->value_20 - object->value_18;
        if (object->value_0c < value) {
            value = object->value_0c;
        }
        clamped = limit;
        if (value < limit) {
            clamped = value;
        }
        mode = clamped;
    } else {
        mode = 0;
        if (object->callback_38 != 0) {
            object->callback_38(object->callback_arg_3c, -3);
        }
    }
    *result = mode;
    fn_800576DC();
    return !(limit - mode);
}

struct fn_80057EC4_Arg2 {
    u8 pad_0[0x4];
    u32 unk_4;
};


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

void fn_800583DC(u32 arg0) {
    fn_80057728();
    *(u32 *)((u8 *)arg0 + 12) = 0;
    *(u32 *)((u8 *)arg0 + 16) = *(u32 *)((u8 *)arg0 + 32);
    *(u32 *)((u8 *)arg0 + 20) = 0;
    *(u32 *)((u8 *)arg0 + 24) = 0;
    *(u32 *)((u8 *)arg0 + 40) = 0;
    *(u32 *)((u8 *)arg0 + 44) = 0;
    *(u32 *)((u8 *)arg0 + 48) = 0;
    *(u32 *)((u8 *)arg0 + 52) = 0;
    fn_800576DC();
}

struct fn_80058434_Arg0 {
    u8 pad_0[0x38];
    u32 unk_38;
    u32 unk_3C;
};

void fn_80058434(struct fn_80058434_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_38 = arg1;
    arg0->unk_3C = arg2;
}

struct fn_80058440_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

u32 fn_80058440(struct fn_80058440_Arg0 *arg0) {
    return arg0->unk_8;
}

u32 fn_80058448(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0, t1, t2;
    t0 = fn_80057728();
    v0 = t0;
    v1 = arg1;
    v2 = arg2;
    if (arg0 != 0) {
    v0 = arg0;
    v1 = 0;
    v2 = 64;
    t1 = (u32)memset((void *)v0, v1, v2);
    v0 = t1;
    *(u32 *)((u8 *)arg0 + 4) = 0;
    }
    t2 = fn_800576DC();
    v0 = t2;
    return v0;
}

struct SjRingObj {
    u32 unk0;
    s32 used;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
};

void fn_800586E4(void);
struct SjRingObj *fn_80058498(void *a0, u32 a1, u32 a2) {
    s32 i;
    struct SjRingObj *entry;

    fn_80057728();

    for (i = 0; i < 0x100; i++) {
        if (((struct SjRingObj *)lbl_8018B2A4)[i].used == 0) {
            break;
        }
    }

    if (i == 0x100) {
        entry = 0;
    } else {
        entry = &((struct SjRingObj *)lbl_8018B2A4)[i];
        entry->used = 1;
        entry->unk0 = (u32)lbl_80132300;
        entry->unk1C = (u32)a0;
        entry->unk20 = a1;
        entry->unk24 = a2;
        entry->unk8 = (u32)lbl_80092330;
        entry->unk38 = (u32)fn_800586E4;
        entry->unk3C = (u32)entry;

        fn_80057728();
        entry->unkC = 0;
        entry->unk10 = entry->unk20;
        entry->unk14 = 0;
        entry->unk18 = 0;
        entry->unk28 = 0;
        entry->unk2C = 0;
        entry->unk30 = 0;
        entry->unk34 = 0;
        fn_800576DC();
    }

    fn_800576DC();
    return entry;
}

struct Counter {
    u32 value;
};

void fn_80058630(void) {
    struct Counter *counter;
    fn_80057728();
    counter = (struct Counter *)&lbl_8018B2A0;
    if (--counter->value == 0) {
        memset((void *)&lbl_8018B2A4, 0, 0x4000);
    }
    fn_800576DC();
}

void fn_80058680(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t1;
    /* Preserve the retail literal-pool read before initialization. */
    (void)*(volatile u32 *)&lbl_8009232C;
    fn_80057728();
    v1 = 0;
    v2 = 0;
    if ((s32)lbl_8018B2A0[0] == 0) {
        v1 = 0;
        v0 = (u32)&lbl_8018B2A4;
        v2 = 16384;
        t1 = (u32)memset((void *)v0, v1, v2);
        v0 = t1;
    }
    v3 = lbl_8018B2A0[0];
    lbl_8018B2A0[0] = (v3 + 1);
    fn_800576DC();
}

extern u32 fn_80058A20(u32);
extern u32 lbl_80092340[];

void fn_800586E4(void) {
    fn_80058A20((u32)&lbl_80092340);
}
