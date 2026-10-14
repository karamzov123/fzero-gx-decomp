/* Non-matching: best partial attempt (32.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"

extern u8 lbl_1_rodata_3E48[];
extern void fn_1_12A2B8(u32);
extern void fn_1_12A2D0(s32);
extern void fn_1_96630(void *, void *, void *);
extern void fn_1_95950(void *);
extern void fn_1_9617C(void *, const char *);
extern void fn_1_426E4(void *, void *);
extern void fn_1_967A8(void *, const char *);
extern void fn_1_933D8(void *, void *, u32);
extern void fn_1_934CC(void *, void *, const char *);
extern void fn_1_107930(void *);
extern int sprintf(char *, const char *, ...);
extern int fn_80083BCC(const char *, const char *);
extern void fn_80008BEC(void *, int, u32);

typedef struct {
    u8 pad0[0x1c];
    u32 state[3];
    u8 pad_28[0x60];
    u32 id;
    u32 mode;
    u32 flags;
    u8 pad_98[4];
    u32 submode;
    u32 modecopy;
    u16 shorts[3];
    u8 pad_aa[2];
    u32 defaults[3];
    f32 f0, f1;
    u32 pad_bc[5];
    u32 pad_d0[5];
    u32 pad_e4[5];
    u32 pad_f8[20];
    u8 pad_148[0xC0];
    u32 resources[0x40];
    u8 pad_2c8[0x1c0];
} CarInitObject;

void fn_1_8E7D0(CarInitObject *p, u32 id, u32 flags, u32 flags2) {
    u8 *data = (u8 *)&lbl_1_data_209C0;
    u8 *pool = lbl_1_rodata_3E48;
    u32 idx = id * 4;
    u32 model = *(u32 *)(data + 0x35c + idx);
    s32 old = -1;
    s32 i;
    u32 f, g;
    char path[0x80];
    p->state[0] = 1;
    for (i = 0; i < 5; ++i) {
        if (((s32 *)p)[i + 1] != -1) {
            old = ((s32 *)p)[i + 1];
            break;
        }
    }
    if (old != -1) {
        fn_1_12A2B8(1);
        fn_1_12A2D0(old);
    } else fn_1_12A2B8(0);
    if (!flags) flags = 0x80000000;
    p->id = id;
    p->mode = (flags & 0x80000000) ? 0 : (flags & 0x40000000) ? 1 : (flags & 0x20000000) ? 2 : (flags & 0x10000000) ? 3 : (flags & 0x08000000) ? 4 : 0;
    if (!(flags & 0xF8000000)) flags = 0x80000000;
    p->flags = flags;
    if (!flags2) flags2 = 0x80000000;
    p->submode = (flags2 & 0x80000000) ? 0 : (flags2 & 0x40000000) ? 1 : (flags2 & 0x20000000) ? 2 : (flags2 & 0x10000000) ? 3 : 0;
    if (!(flags2 & 0xF0000000)) flags2 = 0x80000000;
    *(u32 *)((u8 *)p + 0x9c) = flags2;
    p->modecopy = p->mode;
    p->shorts[0] = p->shorts[1] = p->shorts[2] = 0;
    p->defaults[0] = *(u32 *)(pool + 0x38);
    p->defaults[1] = *(u32 *)(pool + 0x3c);
    p->defaults[2] = *(u32 *)(pool + 0x40);
    p->f0 = *(f32 *)(pool + 0x124);
    p->f1 = *(f32 *)(pool + 0x128);
    for (i = 0; i < 5; i++) {
        u32 *a = (u32 *)(data + 0x5d68 + idx);
        u32 *b = (u32 *)(data + 0x5e1c + idx);
        ((u32 *)((u8 *)p + 0xbc))[i] = a[i * 0x2b] ;
        ((u32 *)((u8 *)p + 0xd0))[i] = b[i * 0x2b];
        ((u32 *)((u8 *)p + 0xe4))[i] = 0;
        ((u32 *)((u8 *)p + 0xf8))[i * 4] = 0;
        ((u32 *)((u8 *)p + 0xf8))[i * 4 + 1] = 0;
        ((u32 *)((u8 *)p + 0xf8))[i * 4 + 2] = 0;
        ((u32 *)((u8 *)p + 0xf8))[i * 4 + 3] = 0;
    }
    fn_1_96630(p, (void *)flags, (void *)flags2);
    for (i = 0; i < 0x30; i++) ((u32 *)((u8 *)p + 0x148))[i] = *(u32 *)(pool + 0x44 + i * 4);
    for (i = 0; i < 4; i++) {
        u32 *dst = (u32 *)((u8 *)p + 0x208 + i * 0xa0);
        u32 *src = (u32 *)(pool + 0x104);
        for (f = 0; f < 40; ++f) dst[f] = src[f % 8];
    }
    fn_1_95950(p);
    if (*(s16 *)&lbl_1_bss_960 == 14 && flags == 0x10000000)
        sprintf(path, (const char *)(data + 0x6e34), model);
    else sprintf(path, (const char *)(data + 0x6e40), model);
    fn_1_9617C((u8 *)p + 0x148, path);
    if (id == 0x15 || id == 0x29 || id == 0x21 || id == 0x2a || id == 0x2b) g = 1;
    else g = 0;
    if ((flags & (g ? 0xe0000000 : 0xc0000000)) &&
        (*(u32 *)(data + 0x5cb4 + idx) & 0x40000000)) {
        sprintf(path, (const char *)(data + 0x6e4c), model);
        fn_1_9617C((u8 *)p + 0x168, path);
        *(u32 *)((u8 *)p + 0x194) = *(u32 *)((u8 *)p + 0x174);
        if (*(u32 *)((u8 *)p + 0x190) && *(u32 *)((u8 *)p + 0x194))
            fn_1_426E4((u8 *)p + 0x190, *(void **)((u8 *)p + 0x194));
    }
    if ((flags & 0xc0000000) && (*(u32 *)(data + 0x5cb4 + idx) & 0x20000000)) {
        sprintf(path, (const char *)(data + 0x6e58), model);
        fn_1_9617C((u8 *)p + 0x1a8, path);
    }
    if ((flags & 0xc0000000) && (*(u32 *)(data + 0x5cb4 + idx) & 0x10000000)) {
        sprintf(path, (const char *)(data + 0x6e64), model);
        fn_1_9617C((u8 *)p + 0x1c8, path);
    }
    if ((flags & 0xc0000000) && (*(u32 *)(data + 0x5cb4 + idx) & 0x08000000)) {
        sprintf(path, (const char *)(data + 0x6e70), model);
        fn_1_9617C((u8 *)p + 0x1e8, path);
    }
    if ((flags & 0xe0000000) && (*(u32 *)(data + 0x5cb4 + idx) & 0x04000000)) {
        for (i = 0; i < 20; ++i) {
            if (*(u32 *)((u8 *)p + 0x210 + i * 0x20)) {
                sprintf(path, (const char *)(data + 0x6e7c), 0);
                if (fn_80083BCC(path, (const char *)(data + 0x6e84)))
                    fn_1_9617C((u8 *)p + 0x208 + i * 0x20, path);
            }
        }
    }
    sprintf(path, (const char *)(data + 0x6e8c), model);
    fn_1_967A8(p, path);
    fn_1_107930(p);
    fn_80008BEC((u8 *)p + 0x488, 0, 0x30);
}
