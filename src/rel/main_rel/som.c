#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/som.h"

extern u32 lbl_1_bss_3BBC;
extern void sprintf(char *, const char *, ...);
extern void fn_1_465D0(char *, int);

/* fzgx:begin fn_1_1304C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/som.h"

extern u32 lbl_1_bss_3BBC;
extern int sprintf(char *s, const char *format, ...);
extern s32 fn_1_465D0(s32 arg0, s32 arg1);

typedef void (*SomCallback)(u32);

typedef struct SomSource {
    u8 pad_0[0x80];
    u8 *dst;
    SomCallback callback;
} SomSource;

extern int fn_1_45730(void *source, void *file);
extern int fn_1_45850(void *file);
extern void *fn_1_45D0(void *heap, u32 size, void *file, u32 line);
extern void fn_1_46B4(void *heap, void *ptr, void *file, u32 line);
extern u8 fn_1_1361C(void *file, void *buffers);
extern void fn_80008BA8(void *dst, void *src, u32 size);
extern void *volatile lbl_801A6410[1];  /* fzgx-allow: S2 volatile keeps the verified access order */
extern volatile u32 lbl_1_data_5184;  /* fzgx-allow: S2 volatile keeps the verified access order */
extern u8 lbl_1_bss_1800[];

/* LZSS decoder: 4 KB ring buffer, 12-bit offsets, 4-bit lengths (threshold 2). */
u32 *fn_1_1304C(SomSource *source, void *image) {
    u32 size;
    void *buffers[2];
    u32 header[2];
    u8 file[0x5c];
    u8 window[0x1000 + 0x12 - 1];
    int offset;
    int r;
    u32 pos;
    u8 *out;
    u32 flags;
    u8 *dst;
    u32 end;
    SomCallback callback;
    int len;
    int k;
    long i;
    u8 c;

    dst = source->dst;
    callback = source->callback;
    *(u32 *)(lbl_1_bss_1800 + 0x2328) = 0;
    *(u32 *)(lbl_1_bss_1800 + 0x232c) = 0;
    lbl_1_bss_1800[0x23b8] = 0;
    if (image != 0) {
        fn_80008BA8(file, image, 0x5c);
    } else if (fn_1_45730(source, file) == 0) {
        return 0;
    }

    buffers[0] = fn_1_45D0(lbl_801A6410[0], lbl_1_data_5184, &lbl_1_data_5188, 0x243);
    buffers[1] = fn_1_45D0(lbl_801A6410[0], lbl_1_data_5184, &lbl_1_data_5188, 0x244);

    header[0] = fn_1_1361C(file, buffers) << 24;
    header[0] |= fn_1_1361C(file, buffers) << 16;
    header[0] |= fn_1_1361C(file, buffers) << 8;
    header[0] |= fn_1_1361C(file, buffers);
    header[1] = fn_1_1361C(file, buffers) << 24;
    header[1] |= fn_1_1361C(file, buffers) << 16;
    header[1] |= fn_1_1361C(file, buffers) << 8;
    header[1] |= fn_1_1361C(file, buffers);

    end = __lwbrx(header, 0) + 8;
    size = __lwbrx(header, 4);
    if (end == 0 || size == 0) {
        return 0;
    }

    out = dst;
    pos = 8;
    for (i = 0; i < 0xfee; i++) {
        window[i] = 0;
    }
    r = 0xfee;
    flags = 0;
    for (;;) {
        flags >>= 1;
        if ((flags & 0x100) == 0) {
            if (pos >= end) {
                break;
            }
            flags = fn_1_1361C(file, buffers) | 0xff00;
            pos++;
        }
        if (flags & 1) {
            if (pos >= end) {
                break;
            }
            c = fn_1_1361C(file, buffers);
            *out++ = c;
            pos++;
            window[r] = c;
            r++;
            r &= 0xfff;
        } else {
            if (pos >= end) {
                break;
            }
            offset = fn_1_1361C(file, buffers);
            if (pos + 1 >= end) {
                break;
            }
            len = fn_1_1361C(file, buffers);
            pos += 2;
            offset |= (len & 0xf0) << 4;
            len = (len & 0xf) + 2;
            for (k = 0; k <= len; k++) {
                c = window[(offset + k) & 0xfff];
                *out++ = c;
                window[r] = c;
                r++;
                r &= 0xfff;
            }
        }
    }

    fn_1_45850(file);
    fn_1_46B4(lbl_801A6410[0], buffers[1], &lbl_1_data_5188, 0x277);
    fn_1_46B4(lbl_801A6410[0], buffers[0], &lbl_1_data_5188, 0x278);
    if (callback != 0) {
        callback(size);
    }
    return &size;
}
/* fzgx:end fn_1_1304C */

/* fzgx:begin fn_1_1383C */
void fn_1_1383C(void) {
    lbl_1_bss_3BBC = 1;
}
/* fzgx:end fn_1_1383C */

/* fzgx:begin fn_1_1384C */
extern int fn_80083BCC(const u8 *, const u8 *);

typedef struct Fn1_1384C_Found Fn1_1384C_Found;

struct Fn1_1384C_Found {
    u8 pad_00[0x1A];
    u16 unk_1A;
    u16 unk_1C;
    u32 unk_20;
    u8 pad_24[0x1C];
};

typedef struct {
    u32 unk_0;
    u8 pad_4[0x1C];
} Fn1_1384C_Bit;

typedef struct {
    Fn1_1384C_Found *unk_0;
    u8 *unk_4;
} Fn1_1384C_Ent;

typedef struct {
    s32 unk_0;
    u32 unk_4;
    Fn1_1384C_Ent *unk_8;
} Fn1_1384C_Sub;

typedef struct {
    Fn1_1384C_Sub *unk_0;
    u32 unk_4;
} Fn1_1384C_List;

typedef struct {
    u32 unk_0;
    u8 *unk_4;
    Fn1_1384C_Found *unk_8;
    u32 unk_C;
} Fn1_1384C_Elem;

typedef struct {
    u32 unk_0;
    s32 unk_4;
    Fn1_1384C_Elem *unk_8;
    u32 unk_C;
} Fn1_1384C_Group;

static inline Fn1_1384C_Found *fn_1_1384C_find(Fn1_1384C_Elem *elem, Fn1_1384C_List **list) {
    u32 boff;
    u8 *str;
    Fn1_1384C_List **tab;
    u8 *name;
    s32 k;
    s32 isMV;
    str = elem->unk_4;
    for (tab = list; tab[0] != 0; tab++) {
        if (tab[0]->unk_0 == 0) {
            continue;
        }
        k = 0;
        boff = 0;
        for (; k < tab[0]->unk_0->unk_0; boff += 8, k++) {
            name = *(u8 **)((u8 *)tab[0]->unk_0->unk_8 + boff + 4);
            isMV = 0;
            if (name[0] == 'M' && name[1] == 'V' && name[2] == '_') {
                isMV = 1;
            }
            if ((isMV && fn_80083BCC(name + 3, str) == 0) || (!isMV && fn_80083BCC(name, str) == 0)) {
                return tab[0]->unk_0->unk_8[k].unk_0;
            }
        }
    }
    return 0;
}
void fn_1_1384C(Fn1_1384C_List **arg0) {
    Fn1_1384C_Bit *bits;
    u16 *idx;
    u8 *hdr;
    s32 n;
    s32 i;
    Fn1_1384C_Found *found;
    Fn1_1384C_Group *g;
    Fn1_1384C_Elem *e;
    s32 j;
    g = (Fn1_1384C_Group *)lbl_1_bss_3BE0->unk_68;
    for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_64; i++, g++) {
        e = g->unk_8;
        for (j = 0; j < g->unk_4; j++, e++) {
            e->unk_8 = found = fn_1_1384C_find(e, arg0);
            if (found != 0 && found->unk_1A == 1 && found->unk_1C == 0) {
                bits = (Fn1_1384C_Bit *)((u8 *)found + 0x40);
                hdr = (u8 *)found + found->unk_20;
                n = hdr[0x12];
                idx = (u16 *)(hdr + 0x16);
                for (; n > 0; n--) {
                    if (bits[*idx].unk_0 & 1) {
                        e->unk_0 |= 0x10;
                    } else {
                        e->unk_0 |= 8;
                    }
                    idx++;
                }
            }
        }
    }
}
/* fzgx:end fn_1_1384C */

/* fzgx:begin fn_1_13A28 */
typedef struct Fn1_13A28 Fn1_13A28;

struct Fn1_13A28 {
    u8 unk_00[4];
    Fn1_13A28 *unk_04;
    Fn1_13A28 *unk_08;
    s32 unk_0c;
    Fn1_13A28 *unk_10;
    u8 unk_14[0x10];
    Fn1_13A28 *unk_24;
    Fn1_13A28 *unk_28;
    Fn1_13A28 *unk_2c;
    Fn1_13A28 *unk_30;
    Fn1_13A28 *unk_34;
    Fn1_13A28 *unk_38;
    Fn1_13A28 *unk_3c;
    Fn1_13A28 *unk_40;
    Fn1_13A28 *unk_44;
    u8 unk_48[8];
};

void fn_1_13A28(Fn1_13A28 *arg0, s32 arg1) {
    Fn1_13A28 *child;

    if (arg0->unk_04 != 0) {
        arg0->unk_04 = (Fn1_13A28 *)((u8 *)arg0->unk_04 + arg1);
    }
    if (arg0->unk_08 != 0) {
        arg0->unk_08 = (Fn1_13A28 *)((u8 *)arg0->unk_08 + arg1);
    }
    if (arg0->unk_10 != 0) {
        arg0->unk_10 = (Fn1_13A28 *)((u8 *)arg0->unk_10 + arg1);
    }

    child = arg0->unk_04;
    if (child->unk_24 != 0) {
        child->unk_24 = (Fn1_13A28 *)((u8 *)child->unk_24 + arg1);
    }
    if (child->unk_28 != 0) {
        child->unk_28 = (Fn1_13A28 *)((u8 *)child->unk_28 + arg1);
    }
    if (child->unk_2c != 0) {
        child->unk_2c = (Fn1_13A28 *)((u8 *)child->unk_2c + arg1);
    }
    if (child->unk_30 != 0) {
        child->unk_30 = (Fn1_13A28 *)((u8 *)child->unk_30 + arg1);
    }
    if (child->unk_34 != 0) {
        child->unk_34 = (Fn1_13A28 *)((u8 *)child->unk_34 + arg1);
    }
    if (child->unk_38 != 0) {
        child->unk_38 = (Fn1_13A28 *)((u8 *)child->unk_38 + arg1);
    }
    if (child->unk_3c != 0) {
        child->unk_3c = (Fn1_13A28 *)((u8 *)child->unk_3c + arg1);
    }
    if (child->unk_40 != 0) {
        child->unk_40 = (Fn1_13A28 *)((u8 *)child->unk_40 + arg1);
    }
    if (child->unk_44 != 0) {
        child->unk_44 = (Fn1_13A28 *)((u8 *)child->unk_44 + arg1);
    }

    if (arg0->unk_0c > 0) {
        s32 i;
        Fn1_13A28 *entry = arg0->unk_10;
        for (i = 0; i < arg0->unk_0c; entry += 1) {
            fn_1_13A28(entry, arg1);
            i++;
        }
    }
}
/* fzgx:end fn_1_13A28 */

/* fzgx:begin fn_1_14D5C */
void fn_1_14D5C(char *arg0, int arg1) {
    char buffer[32];

    sprintf(buffer, (const char *)lbl_1_data_5194, arg0);
    if (arg1 != 0) {
        fn_1_465D0(buffer, 2);
    } else {
        fn_1_465D0(buffer, 1);
    }
}
/* fzgx:end fn_1_14D5C */
