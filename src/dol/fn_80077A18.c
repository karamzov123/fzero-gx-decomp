#include "types.h"


/* --- dol/fn_80077A18.c --- */
extern u32 lbl_801A6DA4;

u32 fn_80077A18(void) {
    return lbl_801A6DA4;
}

/* --- dol/fn_80077A20.c --- */
/* --- dol/fn_80077A20.c --- */
extern void _savegpr_27(void);
extern void lbl_8006DD14(void *arg0, void *arg1);
extern void _restgpr_27(void);

struct fn_80077A20_Arg0 {
    u16 unk_0;
    u8 pad_2[0x16];
    u16 index;
    u8 pad_1a[4];
    u8 count;
    u8 pad_1f[0x21];
    u8 data[1];
};

void *fn_80077A20(struct fn_80077A20_Arg0 *arg0, void **table) {
    u8 *entry;
    u8 *data;
    u8 i;

    entry = (u8 *)arg0 + (arg0->index << 5);
    entry += 0x40;
    data = entry;
    if (table == 0) {
        table = (void **)lbl_801A6DA4;
        i = 0;
        while (i < arg0->count) {
            *table = entry;
            entry += 0x30;
            table += 1;
            i += 1;
        }
    } else {
        i = 0;
        while (i < arg0->count) {
            lbl_8006DD14(entry, *table);
            entry += 0x30;
            table += 1;
            i += 1;
        }
    }
    return data;
}

/* --- dol/fn_80077AD0.c --- */
struct fn_80077AD0_Arg0 {
    u8 pad_0[0x1E];
    u8 unk_1E;
};


u32 fn_80077AD0(struct fn_80077AD0_Arg0 *arg0, u32 arg1) {
    u32 v0;
    s32 v1;
    s32 v2;

    v0 = arg1;
    v2 = 0;
    v1 = 0;
    while (v2 < (s32)arg0->unk_1E) {
        v2++;
        *(u32 *)((u8 *)lbl_801A6DA4 + v1) = v0;
        v0 += 48;
        v1 += 4;
    }
    return arg0->unk_1E;
}

/* --- dol/fn_80077B04.c --- */
extern f32 lbl_8019F130[7];

void fn_80077B04(f32 value) {
    lbl_8019F130[3] = value;
}

/* --- dol/fn_80077B14.c --- */
/* --- dol/fn_80077B14.c --- */
struct fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

extern u32 OSReport(u32, ...);
extern u32 lbl_8015AD48[];

s32 fn_80077B14(struct fn_80077B14_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0;
    v0 = arg0->unk_20;
    v1 = ((u32)arg0 + v0);
    v2 = v1;
    if ((arg0->unk_4 & 0x18) != 0) {
    v2 = (v2 + *(u32 *)((u8 *)v2 + 8));
    } else {
    v2 = (u32)&lbl_8015AD48;
    t0 = OSReport((u32)v2);
    v2 = t0;
    v2 = 0;
    }
    return v2;
}

/* --- dol/fn_80077B64.c --- */
struct fn_80077B64_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};


s32 fn_80077B64(struct fn_80077B64_Arg0 *arg0) {
    u32 v0;
    u32 t0;
    v0 = (u32)arg0;
    if ((arg0->unk_4 & 0x18) != 0) {
    v0 = (v0 + *(u32 *)((u8 *)v0 + 32));
    } else {
    v0 = (u32)&lbl_8015AD48;
    t0 = OSReport((u32)v0);
    v0 = t0;
    v0 = 0;
    }
    return v0;
}

/* --- dol/fn_80077BAC.c --- */
extern u32 lbl_801A6D90;

u32 fn_80077BAC(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D90;
    lbl_801A6D90 = arg0;
    return v0;
}

/* --- dol/fn_80077BBC.c --- */
/* --- dol/fn_80077BBC.c --- */
extern u32 lbl_801A6D98;

void fn_80077BBC(s32 arg0) {
    u32 v0;
    v0 = 0;
    if (arg0) {
        v0 = 3;
    }
    lbl_801A6D98 = v0;
}

/* --- dol/fn_80077BD4.c --- */
extern u32 fn_80072404(u32, s32);

static inline u32 fn_80077BD4_entry(u32 entry) {
    u32 node;
    u32 j;
    u32 sum;
    node = entry + *(u32 *)(entry + 32);
    sum = 0;
    j = 0;
    while (j < (u32)(*(u16 *)(entry + 26) + *(u16 *)(entry + 28))) {
        u32 n;
        n = fn_80072404(*(u32 *)(node + 28), 0);
        if ((*(u32 *)(entry + 4) & 0x18) != 0) {
            if (*(u32 *)(node + 40) != 0) {
                sum += n * *(u32 *)(node + 40);
            }
            if (*(u32 *)(node + 44) != 0) {
                sum += n * *(u32 *)(node + 44);
            }
            node += 96;
        } else {
            u32 p;
            u32 k;
            u32 a;
            u32 b;
            if (*(u32 *)(node + 40) != 0) {
                sum += *(u32 *)(node + 40) / n;
            }
            if (*(u32 *)(node + 44) != 0) {
                sum += *(u32 *)(node + 44) / n;
            }
            p = node;
            p += 96;
            for (k = 0; k < 2; k++) {
                if (*(u8 *)(node + 19) & (1 << k)) {
                    p += ((u32 *)(node + 40))[k];
                }
            }
            if (*(u8 *)(node + 19) & 0xC) {
                b = *(u32 *)(p + 12);
                a = *(u32 *)(p + 8);
                p += 32;
                p += a;
                p += b;
            }
            node = p;
        }
        j++;
    }
    return sum;
}

u32 fn_80077BD4(u32 arg0, u32 arg1, u32 arg2) {
    u32 off;
    u32 i;
    u32 total;
    u32 entry;

    total = 0;
    i = 0;
    off = 0;
    while (i < *(u32 *)(arg0 + 0)) {
        entry = *(u32 *)(*(u32 *)(arg0 + 8) + off);
        if (entry != 0) {
            total += fn_80077BD4_entry(entry);
        }
        off += 8;
        i++;
    }
    return total;
}

/* --- dol/fn_80077D40.c --- */
struct Item {
    u32 flags;
    u32 unk_4;
    u16 width;
    u16 height;
    u16 max_lod;
    u16 pad_e;
};

struct TextureList {
    u32 count;
    struct Item *items;
};

typedef u8 Sig_GXGetTexBufferSize_GXBool;

extern u32 fn_800717BC(u32, u32);
extern u32 GXGetTexBufferSize(u16, u16, u32, Sig_GXGetTexBufferSize_GXBool, u8);

u32 fn_80077D40(struct TextureList *arg0) {
    u32 i;
    u32 total;
    u32 max_lod;
    struct Item *item;

    total = 0;

    for (i = 0; i < arg0->count; i++) {
        item = &arg0->items[i];
        if ((item->flags & 0x100) == 0) {
            max_lod = fn_800717BC(item->width, item->height);
            if (max_lod == 0xFFFFFFFF) {
                max_lod = 0;
            }
            if (item->max_lod != -1 && item->max_lod < max_lod) {
                max_lod = item->max_lod;
            }
            total += GXGetTexBufferSize(item->width, item->height, item->flags & 0x1F, max_lod != 0, max_lod);
        }
    }

    return total;
}

/* --- dol/fn_80077E0C.c --- */
struct fn_80077E0C_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};
struct fn_80077E0C_lbl_801A6D38_T {
    u8 pad_0[0x18];
    u32 unk_18;
};

extern struct fn_80077E0C_lbl_801A6D38_T *lbl_801A6D38;
extern u32 fn_800756B0(u32, u32);
extern u32 fn_80075908(u32, u32);
extern u32 lbl_801A6D9C;

void fn_80077E0C(struct fn_80077E0C_Arg0 *arg0) {
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v0;
    u32 v4;
    v0 = ((u32)arg0 + 64);
    v1 = arg0->unk_20;
    v2 = lbl_801A6D38->unk_18;
    v3 = ((u32)arg0 + v1);
    v4 = v2;
    if ((s32)v2 != 0) {
    v4 = (v4 ^ 3);
    }
    lbl_801A6D9C = v4;
    if (lbl_801A6D90 == 0) {
    v4 = v3;
    fn_800756B0((u32)arg0, v4);
    }
    v4 = v0;
    fn_80075908(v3, v4);
}
