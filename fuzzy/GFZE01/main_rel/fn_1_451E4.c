/* Non-matching: best partial attempt (40.85% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Entry {
    u32 state;
    u32 arg;
    u32 arg2;
};
struct Manager {
    s32 count;
    s32 index;
    s32 busy;
    u8 pad_C[0x400C];
    struct Entry entries[1];
    u8 pad_4024[0x17F4];
    u32 kind;
    u8 pad_581C[0x48];
    u32 mode;
    u8 pad_5868[4];
    u32 source;
    u32 length;
    struct {
        u32 unk0;
        u8 pad4[0x48];
        void *buffer;
        u32 used;
        u32 cap;
        u32 avail;
        u32 size;
        u32 reserved[5];
    } file;
    u32 request[8];
};
extern struct Manager lbl_1_bss_384C0;
extern u8 lbl_1_data_6730[];
extern s32 fn_1_45E84(s32);
extern void *fn_1_45BF0(u32);
extern void fn_1_45BE0(void);
extern void fn_1_45BA4(void *);
extern void fn_1_451D4(void);
extern u32 fn_1_46144(void *, u32, u32);
extern void *memset(void *, int, u32);
extern s32 fn_80006C2C(s32, void *);
extern void OSPanic(const char *, int, const char *, ...);
extern void *fn_80006DE8(void *);
extern u32 fn_80006CE4(void *);
extern s32 fn_80006DAC(void *, void *, u32, u32, void (*)(void *), void (*)(void), u32);
extern void ARQPostRequest(void *, u32, u32, u32, u32, void *, u32, void (*)(void));

void fn_1_451E4(void) {
    struct Manager *m = (struct Manager *)&lbl_1_bss_384C0;
    u8 *text = lbl_1_data_6730;
    struct Entry *e;
    u32 state;
    u32 size;
    u32 limit;
    void *desc;
    void *buffer;
    u32 i;
    if (m->index == m->count) return;
    e = (struct Entry *)((u8 *)m + 0x4018 + m->index * 12);
    state = e->state;
    if (state > 14) return;
    switch (state) {
    case 14:
        e->state = 0;
        m->index = fn_1_45E84(m->index);
        return;
    case 12:
        if (m->busy > 0) return;
        m->source = e->arg;
        m->length = e->arg2;
        m->index = fn_1_45E84(m->index);
        return;
    case 11:
        if (m->busy > 0) return;
        m->kind = e->arg;
        m->index = fn_1_45E84(m->index);
        return;
    case 13:
        if (m->busy > 0) return;
        ((void (*)(u32))e->arg)(e->arg2);
        m->index = fn_1_45E84(m->index);
        return;
    case 1: case 2: case 3: case 4: case 5: case 6:
        switch (state) {
        case 1: m->mode = 0; break;
        case 2: m->mode = 1; break;
        case 3: m->mode = 2; break;
        case 4: m->mode = 3; break;
        case 5: m->mode = 4; break;
        case 6: m->mode = 5; break;
        }
        if (m->busy > 0) return;
        memset(&m->file, 0, 0x60);
        desc = (u8 *)&m->file + 4;
        if (!fn_80006C2C(e->arg, desc)) OSPanic((char *)lbl_1_data_6730, 0x138, (char *)lbl_1_data_6730 + 8);
        m->file.unk0 |= 1;
        size = (u32)fn_80006DE8(desc);
        m->file.size = size;
        m->file.used = 0;
        limit = (m->length >> 1) & 0x7fffffe0;
        m->file.avail = (size + 31) & ~31;
        m->file.cap = m->file.avail < limit ? m->file.avail : limit;
        buffer = fn_1_45BF0(size);
        m->file.buffer = buffer;
        if (!buffer) {
            fn_80006CE4(desc);
            m->file.unk0 &= ~1;
            m->index = fn_1_45E84(m->index);
            return;
        }
        *(u32 *)((u8 *)buffer + 4) = e->arg;
        m->busy = 1;
        if (!fn_80006DAC(desc, (void *)m->source, m->file.cap,
                         m->file.used * limit, fn_1_45BA4, fn_1_45BE0, 0))
            OSPanic((char *)lbl_1_data_6730, 0x150, (char *)lbl_1_data_6730 + 0x1c);
        e->state = 7;
        return;
    case 7:
        if (m->busy < 0) {
            e->state = 14;
            m->busy = 0;
            return;
        }
        if (m->busy != 0) return;
        /* fall through */
    case 8:
        m->busy = 1;
        ARQPostRequest(m->request, 1, 0, 1,
                       m->source + m->file.used * (m->length >> 1),
                       (void *)((u8 *)m->file.buffer + m->file.used * ((m->length >> 1) & 0x7fffffe0)),
                       0, fn_1_451D4);
        m->file.used++;
        m->file.avail -= m->file.cap;
        if (m->file.avail == 0) {
            e->state = 10;
            return;
        }
        limit = (m->length >> 1) & 0x7fffffe0;
        size = m->file.avail < limit ? m->file.avail : limit;
        m->file.cap = size;
        m->busy = 1;
        if (!fn_80006DAC((u8 *)&m->file + 4,
                         (void *)(m->source + m->file.used * (m->length >> 1)),
                         size, m->file.used * limit, fn_1_45BA4, fn_1_45BE0, 0))
            OSPanic((char *)lbl_1_data_6730, 0x195, (char *)lbl_1_data_6730 + 0x1c);
        e->state = 9;
        if (m->mode != 0 || m->busy < 0) return;
        if (m->busy < 0) {
            e->state = 14;
            m->busy = 0;
            return;
        }
        if (m->busy != 0) return;
        goto case8;
    case 10:
        if (m->mode != 0) return;
        switch (m->kind) {
        case 0: ((u32 *)((u8 *)m->file.buffer))[0] = 0x40000000; break;
        case 1: ((u32 *)((u8 *)m->file.buffer))[0] = 0x50000000; break;
        case 2: case 3: case 4:
            if (!fn_1_46144(m->file.buffer, 0, m->kind == 4))
                OSPanic((char *)lbl_1_data_6730, 0x1c7, (char *)lbl_1_data_6730 + 0x30);
            ((u32 *)m->file.buffer)[0] = (m->kind == 4) ? 0x400000 : 0;
            break;
        case 5:
            if (!fn_1_46144(m->file.buffer, 1, 1))
                OSPanic((char *)lbl_1_data_6730, 0x1d1, (char *)lbl_1_data_6730 + 0x30);
            ((u32 *)m->file.buffer)[0] = 0x14000000;
            break;
        }
        fn_80006CE4((u8 *)&m->file + 4);
        m->mode = 0;
        m->file.unk0 &= ~1;
        m->index = fn_1_45E84(m->index);
        return;
    }
case8:
    ;
}
