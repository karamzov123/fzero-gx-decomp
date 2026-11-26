#include "sdk_addresses.h"
#include "types.h"
#include "dol/globals.h"

typedef u32 (*fn_800789D8_Fn0)(void *);
struct fn_800789D8_Arg0 { u8 pad_0[4]; u32 unk_4; };
struct fn_800789D8_Arg1 { u32 unk_0; };

typedef struct {
    u8 pad_00[0x1e];
    u8 count;
    u8 pad_1f[0x9];
    u8 entries[8];
} Fn80078C28Arg0;

typedef struct {
    u8 pad_00[0x18];
    u32 unk_18;
} Fn80078CDCData;

typedef union {
    u8 u8;
    u32 u32;
} Func8008D6BCFifo;

struct fn_80078D60_gx_T {
    u8 pad_0[0x204];
    u32 unk_204;
};

struct fn_80078DA8_entry { u32 unk_0; u32 unk_4; };
struct fn_80078DA8_in { u32 unk_0; u32 unk_4; };
struct fn_80078DA8_out {
    u32 unk_0;
    u32 unk_4;
    struct fn_80078DA8_entry *unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
};

typedef struct Sig_fn_80071C04_Entry { u32 pad00; u32 data; } Sig_fn_80071C04_Entry;
typedef struct Sig_fn_80071C04_Object { u32 flags; u16 index; u16 pad06; u32 value; u8 pad0C[0x14]; } Sig_fn_80071C04_Object;

typedef struct Model {
    u32 unk0;
    u32 flags;
    u8 pad08[0x10];
    u16 count;
    u16 n1A;
    u16 n1C;
    u16 pad1E;
    u32 meshOfs;
    u32 buf;
} Model;

extern u32 lbl_801A6D90;
extern u32 lbl_801A6D94;
extern u32 lbl_801A6D98;
extern u32 lbl_801A6D9C;
extern u32 lbl_801A6D00;
extern u32 lbl_801A6DA4;
extern u32 lbl_801A6DA8;
extern f32 lbl_8019F130[7];
extern f32 lbl_801A74A8;
extern struct fn_80078D60_gx_T *gx;
extern u32 lbl_801A6628[2];
extern u8 lbl_8015AD38[];
extern u32 lbl_801A6DB0;
extern s32 lbl_801A6DB8;
extern u8 lbl_801A6DB4;

extern u32 fn_80075908(u32, u32);
extern u32 fn_80078344(u32, u32);
extern void fn_8003458C(void);
extern void fn_8007245C(u32);
extern void u_gxutil_upload_some_mtx(u32, s32);
extern void lbl_8006DFFC(u32, u32, u32);
extern void GXSetCurrentMtx(s32);
extern void fn_8007264C(s32, s32, s32, s32, s32);
extern u32 fn_80071794(u32);
extern void OSPanic(const char *, int, const char *, ...);
extern void OSReport(const char *, ...);
extern void fn_80071C04(Sig_fn_80071C04_Object *, Sig_fn_80071C04_Entry *);
extern u32 fn_800702E4(u32);
extern u32 fn_8007048C(void);
extern u32 LCStoreBlocks(void *, void *, u32);
extern u32 LCQueueWait(u32);
extern void DCFlushRange(void *, u32);
extern void DCFlushRangeNoSync(void *, u32);
extern void LCLoadBlocks(void *, void *, u32);
extern void *memset(void *, int, u32);

void fn_80078BC4(u8 *arg0);
void fn_80078D60(s32 arg0);
u32 fn_80078F0C(Model *arg0, Sig_fn_80071C04_Entry *arg1, u32 arg2, u32 arg3);
void fn_800794F0(u8 *dst, u8 *src, s32 len);

/* WARNING: compiler-diff device, not original code: without opt_common_subs off fn_800789D8 differs by 29 instructions (the pragma spans fn_800789D8..fn_80078CDC) */
#pragma opt_common_subs off
u32 fn_800789D8(struct fn_800789D8_Arg0 *arg0, struct fn_800789D8_Arg1 *entry, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u8 v3;
    u32 v9;
    s32 v10;
    s32 v5;
    s32 v4;
    u32 v7;
    struct fn_800789D8_Arg1 *arg1 = entry;
    u32 v8;
    u32 v13;
    u32 v12;
    u32 loc_8[16];
    v8 = arg2;
    arg2 = lbl_801A6D98 ^ 2;
    entry = (struct fn_800789D8_Arg1 *)entry->unk_0;
    v0 = (u32)entry;
    v1 = arg2;
    if (v0 & 2) v1 = 0;
    v4 = v1;
    if (arg0->unk_4 & 4) fn_80078BC4((u8 *)arg1 + 32);
    fn_8007245C(*(u32 *)((u8 *)arg1 + 28));
    v7 = (u32)arg1 + 96;
    if (lbl_801A6D90 != 0) {
        loc_8[1] = (u32)arg1;
        loc_8[2] = v8;
        v3 = ((fn_800789D8_Fn0)lbl_801A6D90)(&loc_8);
    } else {
        if ((s32)lbl_801A6D94 == 0) fn_80075908((u32)arg1, v8);
        v3 = 1;
    }
    if (v3) {
        fn_8003458C();
        for (v5 = 0; v5 < 2; v5++) {
            if (*((u8 *)arg1 + 19) & (1 << v5)) {
                fn_80078D60(v4);
                fn_80078344(v7, *(u32 *)((u8 *)arg1 + 40 + v5 * 4));
                v7 += *(u32 *)((u8 *)arg1 + 40 + v5 * 4);
            }
            if (v4 != 0) v4 = lbl_801A6D98 ^ 1;
        }
        if (*((u8 *)arg1 + 19) & 12) {
            fn_80078BC4((u8 *)v7);
            v9 = v7;
            v7 += 32;
            for (v10 = 0; v10 < 2; v10++) {
                if (v10 == 0) fn_80078D60(lbl_801A6D98 ^ 2);
                else fn_80078D60(lbl_801A6D98 ^ 1);
                fn_80078344(v7, *(u32 *)(v9 + 8));
                v7 += *(u32 *)(v9 + 8);
                v9 += 4;
            }
        }
    } else {
        v2 = (u32)arg1 + 96;
        for (v5 = 0; v5 < 2; v5++) {
            if (*((u8 *)arg1 + 19) & (1 << v5))
                v2 += *(u32 *)((u8 *)arg1 + 40 + v5 * 4);
        }
        if (*((u8 *)arg1 + 19) & 12) {
            v12 = *(u32 *)(v2 + 8);
            v13 = *(u32 *)(v2 + 12);
            v2 += 32;
            v2 += v12;
            v2 += v13;
        }
        return v2;
    }
    return v7;
}

void fn_80078BC4(u8 *arg0) {
    u8 *ptr;
    s32 i;

    ptr = arg0;
    i = 0;
    do {
        if ((s32)*ptr != 0xFF) {
            u_gxutil_upload_some_mtx(lbl_801A6DA8 + *ptr * 48, i + 1);
        }
        i++;
        ptr++;
    } while (i < 8);
}

static inline void fn_80078C28_upload(Fn80078C28Arg0 *arg0) {
    s32 i;

    i = 0;
    do {
        if ((s32)arg0->entries[i] != 0xFF) {
            u_gxutil_upload_some_mtx(lbl_801A6DA8 + arg0->entries[i] * 0x30, i + 1);
        }
        i++;
    } while (i < 8);
}

void fn_80078C28(Fn80078C28Arg0 *arg0) {
    u32 index;

    index = 0;
    while (index < arg0->count) {
        lbl_8006DFFC(lbl_801A6D00,
                     *(u32 *)((u8 *)(u32)lbl_801A6DA4 + index * 4),
                     lbl_801A6DA8 + index * 0x30);
        index++;
    }

    fn_80078C28_upload(arg0);
}

void fn_80078CDC(s32 arg0) {
    s32 value;
    Fn80078CDCData *data;

    if (arg0 != 0) {
        GXSetCurrentMtx(0);
    }

    value = lbl_801A6D9C;
    lbl_8019F130[3] = lbl_801A74A8;
    if (value != 0) {
        value ^= 3;
    }
    data = (Fn80078CDCData *)lbl_801A6D38;
    data->unk_18 = value;
    fn_8007264C(0, 10, 0, 4, 0);
}
#pragma opt_common_subs reset

/* WARNING: compiler-diff device, not original code: optimization_level 0 and K&R register parameters reproduce retail's unscheduled lis/li/ori FIFO write (5 instructions differ without it); dont_inline keeps it a call in fn_80078D60 (15 without); the shape suggests an original asm helper, owner decision */
#pragma optimization_level 0
#pragma dont_inline on
u32 func_8008D6BC(value, command, fifo)
    register u32 value;
    register u8 command;
    register u32 fifo;
{
    fifo = FZGX_ADDR___CPRegs;
    command = 0x61;
    fifo |= 0x8000;
    ((volatile Func8008D6BCFifo *)fifo)->u8 = command;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    ((volatile Func8008D6BCFifo *)fifo)->u32 = value;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    return value;
}
#pragma dont_inline reset
/* WARNING: compiler-diff device, not original code: restores the optimizer after func_8008D6BC; required by the level-0 block above */
#pragma optimization_level 4

void fn_80078D60(s32 arg0) {
    u32 temp_r3;

    if ((s32)(lbl_801A6D9C) != arg0) {
        lbl_801A6D9C = arg0;
        temp_r3 = ((*(struct fn_80078D60_gx_T **)(&gx))->unk_204 & 0xFFFF3FFF) | (arg0 << 0xE);
        (*(struct fn_80078D60_gx_T **)(&gx))->unk_204 = temp_r3;
        func_8008D6BC(temp_r3);
    }
}

static inline void fn_80078DA8_load(struct fn_80078DA8_out *out, void *p2, u32 total) {
    struct fn_80078DA8_entry *e;
    u8 *cur;
    u32 i;
    u32 off;
    cur = (u8 *)out->unk_14;
    for (i = 0, off = 0; i < out->unk_0; off += 8, i++) {
        e = (struct fn_80078DA8_entry *)((u8 *)out->unk_8 + off);
        if (e->unk_0 == 0) {
            continue;
        }
        fn_80078F0C((Model *)e->unk_0, (Sig_fn_80071C04_Entry *)p2, (u32)cur, e->unk_4);
        if (total != 0) {
            cur += *(u16 *)(e->unk_0 + 0x18) * 32;
        }
    }
}

void fn_80078DA8(struct fn_80078DA8_out *out, struct fn_80078DA8_in *in, void *arg2) {
    u32 total = 0;
    void *p2 = arg2;
    u32 i;
    u32 base;

    out->unk_0 = in->unk_0;
    out->unk_4 = (u32)in + in->unk_4;
    out->unk_8 = (struct fn_80078DA8_entry *)((u8 *)in + 8);
    out->unk_C = ((in->unk_0 * 8) + ((u32)out->unk_8));
    out->unk_10 = 0;
    out->unk_14 = 0;
    for (i = 0; i < out->unk_0; i++) {
        struct fn_80078DA8_entry *en = &out->unk_8[i];
        u32 v = en->unk_0;
        if (v + 0x10000 == 0xFFFF) {
            en->unk_0 = 0;
            en->unk_4 = lbl_801A6628[0];
        } else {
            base = out->unk_4 + v;
            en->unk_0 = base;
            en->unk_4 = out->unk_C + en->unk_4;
            total += *(u16 *)(base + 0x18);
        }
    }
    if (p2 != 0 && total != 0) {
        out->unk_14 = fn_80071794(total * 32);
    } else {
        total = 0;
    }
    fn_80078DA8_load(out, p2, total);
}

static inline void fn_80078F0C_bind(Model *m, Sig_fn_80071C04_Object *obj, Sig_fn_80071C04_Entry *entries, u32 id, u8 *str) {
    s32 i;
    Sig_fn_80071C04_Object *child;
    u32 off;
    child = obj;
    for (i = 0, off = 0; i < m->count; off += 32, child++, i++) {
        child->value = m->buf + off;
        fn_80071C04(child, entries);
        if ((child->flags & 0x200000) == 0 && child->value == 0)
            OSReport((const char *)(str + 216), id, child->index);
    }
}

u32 fn_80078F0C(Model *arg0, Sig_fn_80071C04_Entry *arg1, u32 arg2, u32 arg3) {
    Sig_fn_80071C04_Object *child;
    u8 *p_lbl_8015AD38;
    s32 reset;
    Sig_fn_80071C04_Object *v4;
    s32 v3;
    s32 v5;
    s32 v1;
    s32 v14;
    u32 v15;
    u32 v11;
    u32 v16;
    u32 v18;
    s32 j;
    child = (Sig_fn_80071C04_Object *)((u8 *)arg0 + 0x40);
    p_lbl_8015AD38 = (u8 *)&lbl_8015AD38;
    reset = 0;
    if (arg1 == 0) {
        v5 = arg0->count;
        v4 = child;
        v1 = 0;
        for (v3 = 0; v3 < v5; v3++) {
            if (v4->flags & 0x200000) v1++;
            v4++;
        }
        if (v1 != v5) {
            reset = 1;
            arg0->count = 0;
        }
    }
    if (arg0->count != 0) {
        if (arg2 != 0) {
            arg0->buf = arg2;
            arg2 += arg0->count << 5;
        } else {
            arg0->buf = fn_80071794(arg0->count * 0x20U);
        }
        if (arg0->buf == 0) {
            OSReport((const char *)(p_lbl_8015AD38 + 164), arg3);
            OSPanic((const char *)(p_lbl_8015AD38 + 176), 2411, (const char *)(p_lbl_8015AD38 + 188));
        }
    } else {
        arg0->buf = 0;
    }
    fn_80078F0C_bind(arg0, child, arg1, arg3, p_lbl_8015AD38);
    v11 = arg0->flags;
    v15 = (u32)arg0 + arg0->meshOfs;
    if (v11 & 0x18) {
        *(u32 *)(v15 + 28) = v11;
        v15 += 32;
    }
    v14 = 0;
    while (v14 < arg0->n1A + arg0->n1C) {
        if (reset) *(u8 *)(v15 + 18) = 0;
        if (arg0->flags & 0x18) {
            v16 = v15;
            v15 += 96;
            if (*(u32 *)(v16 + 28) & 0x800) *(u32 *)v16 |= 256;
            if (*(u8 *)(v16 + 18) == 0) *(u32 *)v16 |= 128;
        } else {
            if (*(u32 *)(v15 + 28) & 0x800) *(u32 *)v15 |= 256;
            if (*(u8 *)(v15 + 18) == 0) *(u32 *)v15 |= 128;
            v18 = v15 + 96;
            for (j = 0; j < 2; j++) {
                if (*(u8 *)(v15 + 19) & (1 << j))
                    v18 += *(u32 *)(v15 + 40 + j * 4);
            }
            if (*(u8 *)(v15 + 19) & 0xC) {
                u32 b;
                u32 a;
                a = *(u32 *)(v18 + 8);
                b = *(u32 *)(v18 + 12);
                v18 += 32;
                v18 += a;
                v18 += b;
            }
            v15 = v18;
        }
        v14++;
    }
    return arg2;
}

void fn_800791A4(void) {
    u32 t0, t1;
    t0 = fn_8007048C();
    lbl_801A6DB4 = t0;
    t1 = fn_800702E4((t0 & 0xFF));
    lbl_801A6DB0 = t1;
    if (lbl_801A6DB4 != 0) {
        lbl_801A6DB8 = 1;
    }
}

void fn_800791E8(u8 *dst, u8 *src, u32 nBytes) {
    u32 numBlocks;
    u32 i;
    u32 numBytes;
    u32 numBlockLoops;
    u32 j;
    u8 *q;
    u8 *p;
    u32 remBytes;

    if (lbl_801A6DB8 == 0) {
        fn_800794F0(dst, src, nBytes);
        return;
    }
    numBlocks = nBytes >> 10;
    remBytes = nBytes & 0x1F;
    numBlockLoops = numBlocks / lbl_801A6DB4;
    numBytes = ((nBytes - (numBlocks << 10)) - remBytes) >> 5;
    numBlocks = numBlocks % lbl_801A6DB4;
    DCFlushRange(src, nBytes);
    DCFlushRangeNoSync(dst, nBytes);
    for (i = 0; i < numBlockLoops; i++) {
        p = (u8 *)lbl_801A6DB0;
        q = p;
        for (j = 0; j < lbl_801A6DB4; j++) {
            LCQueueWait(14);
            LCLoadBlocks(p, src, 0x20);
            p += 0x400;
            src += 0x400;
        }
        for (j = 0; j < lbl_801A6DB4; j++) {
            LCQueueWait(14);
            LCStoreBlocks(dst, q, 0x20);
            dst += 0x400;
            q += 0x400;
        }
    }
    p = (u8 *)lbl_801A6DB0;
    q = p;
    for (j = 0; j < numBlocks; j++) {
        LCQueueWait(14);
        LCLoadBlocks(p, src, 0x20);
        p += 0x400;
        src += 0x400;
    }
    for (j = 0; j < numBlocks; j++) {
        LCQueueWait(14);
        LCStoreBlocks(dst, q, 0x20);
        dst += 0x400;
        q += 0x400;
    }
    if (numBytes != 0) {
        LCQueueWait(14);
        LCLoadBlocks(p, src, numBytes);
        src += numBytes << 5;
        LCQueueWait(14);
        LCStoreBlocks(dst, q, numBytes);
        dst += numBytes << 5;
    }
    if (remBytes != 0) {
        fn_800794F0(dst, src, remBytes);
    }
    LCQueueWait(0);
}

u32 fn_800793D4(u8 *arg0, u32 arg1, u32 arg2) {
    u32 i;
    u32 blocks;
    u32 tail;
    u32 chunks;
    s32 did;

    did = 0;
    if (lbl_801A6DB8 == 0) {
        return (u32)memset(arg0, arg1 & 0xFF, arg2);
    }
    tail = arg2 & 0x1F;
    blocks = arg2 >> 10;
    chunks = ((arg2 - (arg2 & ~0x3FF)) - tail) >> 5;
    DCFlushRangeNoSync(arg0, arg2);
    if (blocks != 0) {
        memset((void *)lbl_801A6DB0, arg1 & 0xFF, 0x400);
        did = 1;
        for (i = 0; i < blocks; i++) {
            LCQueueWait(0xE);
            LCStoreBlocks(arg0, (void *)lbl_801A6DB0, 0x20);
            arg0 += 0x400;
        }
    }
    if (chunks != 0) {
        if (did == 0) {
            memset((void *)lbl_801A6DB0, arg1 & 0xFF, chunks << 5);
        }
        LCQueueWait(0xE);
        LCStoreBlocks(arg0, (void *)lbl_801A6DB0, chunks);
        arg0 += chunks << 5;
    }
    if (tail != 0) {
        memset(arg0, arg1 & 0xFF, tail);
    }
    return LCQueueWait(0);
}

void fn_800794F0(u8 *dst, u8 *src, s32 len) {
    s32 n = len >> 4;
    s32 m;
    while (n > 0) {
        ((u32 *)dst)[0] = ((u32 *)src)[0];
        ((u32 *)dst)[1] = ((u32 *)src)[1];
        ((u32 *)dst)[2] = ((u32 *)src)[2];
        ((u32 *)dst)[3] = ((u32 *)src)[3];
        dst += 16;
        src += 16;
        n--;
    }
    m = len & 15;
    while (m > 0) {
        *dst++ = *src++;
        m--;
    }
}
