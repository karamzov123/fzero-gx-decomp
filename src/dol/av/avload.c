#include "types.h"

typedef struct GXTexObj {
    u32 dummy[8];
} GXTexObj;

typedef struct Layer {
    u32 unk_0;
    u16 unk_4;
    s8 unk_6;
    u8 unk_7;
    GXTexObj *unk_8;
    u8 unk_C[8];
    void *unk_14;
} Layer;

typedef struct TexHeader {
    u32 unk_0;
    u32 unk_4;
    u16 unk_8;
    u16 unk_A;
    u16 unk_C;
} TexHeader;

typedef struct TexFile {
    u32 unk_0;
    u32 unk_4;
    u8 *unk_8;
} TexFile;

typedef void (*AvloadFreeFn)(void *);
typedef u32 (*fn_80071100_Fn0)(u32, u32, u32);
typedef u32 (*fn_800715A0_Fn0)(u32, u32);

extern char lbl_8015AB70[31];
extern char lbl_8015ABC0[10];
extern u32 lbl_8015ABCC[];
extern u32 lbl_8015ABD8[];
extern u32 lbl_8015ABFC[];
extern char lbl_8015AC08[];
extern char lbl_8015AC1C[];
extern AvloadFreeFn lbl_801A6D08;
extern u32 lbl_801A6D0C;
extern u32 lbl_801A6D10;
extern u32 lbl_801A6D14;
extern u32 lbl_801A6D18;
extern u32 lbl_801A6D1C;
extern u32 lbl_801A6D20;
extern u32 lbl_801A6D24;

extern void fn_80078DA8(void *, void *, u32);
extern void DCInvalidateRange(void *, u32);
extern u32 ARGetDMAStatus(void);
extern void ARStartDMA(u32, void *, u32, u32);
extern void *strstr(void *arg0, u32 arg1);
extern void fn_80071C04(void *, u32);
extern u32 OSPanic(u32, ...);
extern u32 sprintf(void *, ...);
extern void OSReport(const char *, ...);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, s32, s32, s32, u8);
extern void GXInitTexObjLOD(GXTexObj *, s32, s32, f32, f32, f32, u8, u8, s32);

void fn_8007174C(u32 arg0, u32 arg1);
void fn_800718BC(Layer *layer, TexHeader *tex, TexFile *file);

void *fn_80070F44(u32 arg0, u32 arg1, s32 arg_sp0) {
    void *temp_r31;
    s32 temp_r3_3;
    void *temp_r3;
    s32 temp_r3_2;

    temp_r3_2 = ((s32 (*)())(lbl_801A6D24))();
    if (((s32 (*)(u32, s32))(lbl_801A6D20))(arg0, temp_r3_2) == 0) {
        return NULL;
    }
    temp_r3_3 = ((s32 (*)(s32))(lbl_801A6D1C))(temp_r3_2);
    temp_r3 = (((void *(*)(s32))(lbl_801A6D0C))(((temp_r3_3 + 0x1F) & 0xFFFFFFE0) + 0x20));
    if (temp_r3 == NULL) {
        fn_8007174C((u32)(lbl_8015AB70), arg0);
    }
    temp_r31 = ((u8 *)(temp_r3) + 0x20);
    ((s32 (*)(s32, void *, s32, s32))(lbl_801A6D18))(temp_r3_2, temp_r31, temp_r3_3, 0);
    ((s32 (*)(s32))(lbl_801A6D14))(temp_r3_2);
    ((s32 (*)(s32))(lbl_801A6D10))(temp_r3_2);
    fn_80078DA8(temp_r3, temp_r31, arg1);
    return temp_r3;
}

void *fn_80071044(u32 arg0, u32 size, u32 arg2) {
    s32 rounded_size;
    void *buffer;
    void *data;

    rounded_size = (size + 0x1f) & ~0x1f;
    buffer = ((void *(*)(u32))lbl_801A6D0C)(rounded_size + 0x20);
    if (buffer == 0) {
        fn_8007174C((u32)lbl_8015AB70, (u32)lbl_8015ABC0);
    }
    data = (u8 *)buffer + 0x20;
    DCInvalidateRange(data, rounded_size);
    while (ARGetDMAStatus() != 0) {
    }
    ARStartDMA(1, data, arg0, size);
    while (ARGetDMAStatus() != 0) {
    }
    fn_80078DA8(buffer, data, arg2);
    return buffer;
}

u32 fn_80071100(u32 arg0, u32 arg1, u32 arg2) {
    s32 flag;
    u32 arg2_local;
    u32 arg0_local;

    flag = 0;
    arg2_local = arg2;
    arg0_local = arg0;
    if (arg1 == 0) {
        arg1 = ((fn_80071100_Fn0)lbl_801A6D0C)(32, arg1, arg2_local);
        if (arg1 == 0) {
            fn_8007174C((u32)&lbl_8015AB70, (u32)&lbl_8015ABCC);
        }
        flag = 1;
    }
    fn_80078DA8((void *)arg1, (void *)arg0_local, arg2_local);
    if (flag == 0) {
        *(u32 *)((u8 *)arg1 + 16) = (*(u32 *)((u8 *)arg1 + 16) | 1);
    }
    return arg1;
}

struct fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

void fn_800711A8(struct fn_800711A8_Arg0 *arg0) {
    struct fn_800711A8_Entry *entry;
    s32 offset;
    s32 i;

    offset = 0;
    i = 0;
    while (i < arg0->count) {
        entry = *(struct fn_800711A8_Entry **)((u8 *)arg0->entries + offset);
        if (arg0->field_14 == 0 && entry != 0) {
            void *p = entry->field_24;
            if (p != 0) {
                lbl_801A6D08(p);
            }
        }
        offset += 8;
        i += 1;
    }
    if (arg0->field_14 != 0) {
        lbl_801A6D08(arg0->field_14);
    }
    if (!(arg0->field_10 & 1)) {
        lbl_801A6D08(arg0);
    }
}

struct fn_80071268_Entry {
    void *unk_0;
    void *unk_4;
};

struct fn_80071268_Arg0 {
    s32 count;
    u8 pad_4[4];
    struct fn_80071268_Entry *entries;
};

void *fn_80071268(struct fn_80071268_Arg0 *arg0, u32 arg1) {
    u32 offset;
    s32 i;
    struct fn_80071268_Entry *entry;

    i = 0;
    offset = 0;
    while (i < arg0->count) {
        entry = (struct fn_80071268_Entry *)((u8 *)arg0->entries + offset);
        if (strstr(entry->unk_4, arg1) != 0) {
            return entry->unk_0;
        }
        offset += 8;
        i += 1;
    }
    return 0;
}

struct fn_800712E4_Tbl {
    u16 key;
    u16 value;
};

struct fn_800712E4_Child {
    u32 flags;
    u16 key;
    u16 pad_06;
    u32 field_08;
    u8 pad_0C[0x14];
};

struct fn_800712E4_Entry {
    u8 pad_00[0x18];
    u16 count;
    u8 pad_1A[0xA];
    u32 field_24;
};

struct fn_800712E4_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct fn_800712E4_Entry **entries;
};

struct fn_800712E4_Arg1 {
    u8 pad_00[4];
    u32 field_04;
};

void fn_800712E4(struct fn_800712E4_Arg0 *arg0, struct fn_800712E4_Arg1 *arg1,
                 struct fn_800712E4_Tbl *arg2) {
    struct fn_800712E4_Child *child;
    s32 inner;
    s32 offset;
    s32 i;
    s32 j;
    struct fn_800712E4_Entry *entry;
    struct fn_800712E4_Tbl *p;
    s32 idx;
    u16 v;

    i = 0;
    offset = 0;
    while (i < arg0->count) {
        entry = *(struct fn_800712E4_Entry **)((u8 *)arg0->entries + offset);
        if (entry != 0) {
            child = (struct fn_800712E4_Child *)((u8 *)entry + 0x40);
            j = 0;
            inner = 0;
            while (j < entry->count) {
                if (child->flags & 0x200000) {
                    v = child->key;
                    p = arg2;
                    idx = 0;
                    while (p->key != 0xFFFF) {
                        if (v == p->key) {
                            v = arg2[idx].value;
                            break;
                        }
                        p++;
                        idx++;
                    }
                    child->field_08 = entry->field_24 + inner;
                    fn_800718BC((Layer *)child, (TexHeader *)(arg1->field_04 + (v << 4)),
                                (TexFile *)arg1);
                }
                child++;
                inner += 0x20;
                j++;
            }
        }
        offset += 8;
        i++;
    }
}

struct fn_800713E0_Entry {
    u8 pad_0[0x18];
    u16 count;
};

struct fn_800713E0_Arg0 {
    s32 count;
    u8 pad_4[0x4];
    struct fn_800713E0_Entry **entries;
};

void fn_800713E0(struct fn_800713E0_Arg0 *arg0, u32 arg1) {
    u8 *child;
    s32 offset;
    s32 i;
    s32 j;
    struct fn_800713E0_Entry *entry;

    i = 0;
    offset = 0;
    while (i < arg0->count) {
        entry = *(struct fn_800713E0_Entry **)((u8 *)arg0->entries + offset);
        if (entry != 0) {
            child = (u8 *)entry + 0x40;
            j = 0;
            while (j < entry->count) {
                fn_80071C04(child, arg1);
                child += 0x20;
                j++;
            }
        }
        offset += 8;
        i++;
    }
}

struct fn_80071470_E16_u32 { u32 unk_0; u8 pad_4[0xC]; };
struct fn_80071470_Arg0 {
    u8 pad_0[0x8];
    struct fn_80071470_E16_u32 unk_8[1];
};

u32 fn_80071470(struct fn_80071470_Arg0 *arg0, u32 arg1) {
    return ((u32)arg0 + arg0->unk_8[arg1].unk_0);
}

void *fn_80071484(u32 arg0) {
    s32 temp_r31;
    void *temp_r30;
    void *temp_r29;
    s32 temp_r28;

    temp_r28 = ((s32 (*)())(lbl_801A6D24))();
    if (((s32 (*)(u32, s32))(lbl_801A6D20))(arg0, temp_r28) == 0) {
        return NULL;
    }
    temp_r31 = ((s32 (*)(s32))(lbl_801A6D1C))(temp_r28);
    temp_r30 = ((void *(*)(s32))(lbl_801A6D0C))(((temp_r31 + 0x1F) & 0xFFFFFFE0) + 0x20);
    if (temp_r30 == NULL) {
        fn_8007174C((u32)lbl_8015ABD8, arg0);
    }
    temp_r29 = (void *)(((u32)temp_r30 + 0x3F) & 0xFFFFFFE0);
    ((s32 (*)(s32, void *, s32, s32))(lbl_801A6D18))(temp_r28, temp_r29, temp_r31, 0);
    ((s32 (*)(s32))(lbl_801A6D14))(temp_r28);
    ((s32 (*)(s32))(lbl_801A6D10))(temp_r28);
    *(u32 *)temp_r30 = *(u32 *)temp_r29;
    *(u32 *)((u8 *)temp_r30 + 4) = (u32)temp_r29 + 4;
    *(u32 *)((u8 *)temp_r30 + 8) = (u32)temp_r29;
    *(u32 *)((u8 *)temp_r30 + 12) = 0;
    return temp_r30;
}

void *fn_800715A0(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 t0, t3, t5;
    v0 = (arg1 + 31);
    v1 = (v0 & ~0x1F);
    t0 = ((fn_800715A0_Fn0)lbl_801A6D0C)((v1 + 32), arg1);
    v2 = t0;
    if (t0 == 0) {
        v2 = (u32)&lbl_8015ABD8;
        v3 = (u32)&lbl_8015ABC0;
        fn_8007174C(v2, v3);
    }
    v4 = ((t0 + 63) & ~0x1F);
    DCInvalidateRange((void *)v4, v1);
    do {
        t3 = ARGetDMAStatus();
    } while (t3 != 0);
    ARStartDMA(1, (void *)v4, arg0, arg1);
    do {
        t5 = ARGetDMAStatus();
    } while (t5 != 0);
    *(u32 *)((u8 *)t0 + 0) = *(u32 *)((u8 *)v4 + 0);
    *(u32 *)((u8 *)t0 + 4) = (v4 + 4);
    *(u32 *)((u8 *)t0 + 8) = v4;
    *(u32 *)((u8 *)t0 + 12) = 0;
    return (void *)t0;
}

void *fn_80071678(s32 *arg0, void *arg1) {
    s32 var_r4;
    void *var_r31;

    var_r31 = (void *)(arg1);
    var_r4 = 0;
    if (var_r31 == NULL) {
        var_r31 = (((void *(*)(s32))(lbl_801A6D0C))(0x20));
        if (var_r31 == NULL) {
            fn_8007174C((u32)(lbl_8015ABD8), (u32)(lbl_8015ABCC));
        }
        var_r4 = 1;
    }
    (*(s32 *)((u8 *)(var_r31))) = (*arg0);
    (*(void **)((u8 *)(var_r31) + 4)) = (((u8 *)(arg0) + 4));
    (*(s32 **)((u8 *)(var_r31) + 8)) = arg0;
    if (var_r4 == 0) {
        (*(s32 *)((u8 *)(var_r31) + 12)) = 1;
    } else {
        (*(s32 *)((u8 *)(var_r31) + 12)) = 0;
    }
    return var_r31;
}

struct fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

void fn_80071718(struct fn_80071718_Arg0 *arg0) {
    if ((arg0->unk_C & 0x1) == 0) {
        lbl_801A6D08(arg0);
    }
}

void fn_8007174C(u32 arg0, u32 arg1) {
    struct { u32 a[258]; } loc_8;
    sprintf(&loc_8, arg0, arg1);
    OSPanic((u32)&lbl_8015ABFC, 498, &loc_8);
}

void fn_80071794(u32 lab_unused0) {
    ((void (*)(void))lbl_801A6D0C)();
}

u32 fn_800717BC(u32 arg0, u32 arg1) {
    s32 i;
    s32 c0;
    s32 c1;
    s32 v;
    s32 n;
    c1 = 0;
    c0 = 0;
    for (i = 0; i < 10; i++) {
        if ((arg0 & (1u << i)) != 0) {
            c0++;
        }
        if ((arg1 & (1u << i)) != 0) {
            c1++;
        }
    }
    v = arg0;
    if (c0 > 1 || c1 > 1) {
        return -1;
    }
    if (v > (s32)arg1) {
        v = arg1;
    }
    n = 0;
    while (v > 4) {
        v = (v >> 1);
        n++;
    }
    return n;
}

/* fn_800717BC: MWCC inlines it here; -1 when a side is not a power of two */
static inline u32 mip_count(int w, int h) {
    s32 i;
    s32 c0;
    s32 c1;
    s32 n;

    c0 = c1 = 0;
    for (i = 0; i < 10; i++) {
        if ((w & (1 << i)) != 0) {
            c0++;
        }
        if ((h & (1 << i)) != 0) {
            c1++;
        }
    }
    if (c0 > 1 || c1 > 1) {
        return -1;
    }
    if (w > h) {
        w = h;
    }
    n = 0;
    while (w > 4) {
        w >>= 1;
        n++;
    }
    return n;
}

void fn_800718BC(Layer *layer, TexHeader *tex, TexFile *file) {
    u8 max_lod;
    u8 *image;
    s32 wrap_s;
    s32 wrap_t;
    u8 lod;
    s32 format;
    s32 min_filter;
    s32 mag_filter;

    image = file->unk_8 + tex->unk_4;
    if (tex->unk_0 & 0x100) {
        OSReport(lbl_8015AC08);
        layer->unk_8 = NULL;
        return;
    }
    switch ((layer->unk_0 >> 2) & 3) {
    case 2:
        wrap_s = 2;
        break;
    case 1:
        wrap_s = 1;
        break;
    default:
        wrap_s = 0;
        break;
    }
    switch ((layer->unk_0 >> 4) & 3) {
    case 2:
        wrap_t = 2;
        break;
    case 1:
        wrap_t = 1;
        break;
    default:
        wrap_t = 0;
        break;
    }
    max_lod = (layer->unk_0 >> 7) & 0xF;
    lod = mip_count(tex->unk_8, tex->unk_A);
    if (lod == 0xFF) {
        if (wrap_t != 0 || wrap_s != 0) {
            OSReport(lbl_8015AC1C, tex->unk_8, tex->unk_A);
        }
        wrap_s = 0;
        wrap_t = 0;
        max_lod = 0;
    } else if (max_lod == 15 || lod < max_lod) {
        max_lod = lod;
    }
    /* retail compares the zero-extended u16 with -1 (lhz; cmpwi), as written here */
    if (tex->unk_C != -1 && tex->unk_C < max_lod) {
        max_lod = tex->unk_C;
    }
    format = tex->unk_0 & 0x1F;
    switch (format) {
    case 0:
    case 14:
        if (max_lod != 0) {
            max_lod--;
        }
        break;
    }
    GXInitTexObj(layer->unk_8, image, tex->unk_8, tex->unk_A, format, wrap_s, wrap_t, max_lod != 0);
    layer->unk_14 = image;
    if (layer->unk_0 & 0x800) {
        mag_filter = 0;
        if (max_lod != 0) {
            min_filter = 4;
        } else {
            min_filter = 2;
        }
    } else {
        mag_filter = 1;
        if (max_lod != 0) {
            min_filter = 5;
        } else {
            min_filter = 3;
        }
    }
    GXInitTexObjLOD(layer->unk_8, min_filter, mag_filter, 0.0f, max_lod, layer->unk_6 / 10.0f, 0,
                    (layer->unk_0 >> 6) & 1, layer->unk_7);
}
