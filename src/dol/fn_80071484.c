#include "types.h"


/* --- dol/fn_80071484.c --- */
/* --- dol/fn_80071484.c --- */
extern u32 lbl_8015ABD8[];
extern u32 lbl_801A6D0C;
extern u32 lbl_801A6D10;
extern u32 lbl_801A6D14;
extern u32 lbl_801A6D18;
extern u32 lbl_801A6D1C;
extern u32 lbl_801A6D20;
extern u32 lbl_801A6D24;
extern void fn_8007174C(u32, u32);

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

/* --- dol/fn_800715A0.c --- */
typedef u32 (*fn_800715A0_Fn0)(u32, u32);

extern u32 ARGetDMAStatus(void);
extern u32 ARStartDMA(u32, u32, u32, u32);
extern u32 lbl_8015ABC0[];
extern void DCInvalidateRange(void *, u32);

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
    ARStartDMA(1, v4, arg0, arg1);
    do {
        t5 = ARGetDMAStatus();
    } while (t5 != 0);
    *(u32 *)((u8 *)t0 + 0) = *(u32 *)((u8 *)v4 + 0);
    *(u32 *)((u8 *)t0 + 4) = (v4 + 4);
    *(u32 *)((u8 *)t0 + 8) = v4;
    *(u32 *)((u8 *)t0 + 12) = 0;
    return (void *)t0;
}

/* --- dol/fn_80071678.c --- */
typedef u32 (*fn_80071678_Fn0)(u32, u32);
extern u32 lbl_8015ABCC[];


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

/* --- dol/fn_80071718.c --- */
typedef u32 (*fn_80071718_Fn0)(u32);
struct fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

extern u32 lbl_801A6D08;

void fn_80071718(struct fn_80071718_Arg0 *arg0) {
    if ((arg0->unk_C & 0x1) == 0) {
        ((fn_80071718_Fn0)lbl_801A6D08)((u32)arg0);
    }
}

/* --- dol/fn_8007174C.c --- */
extern u32 OSPanic(u32, ...);
extern u32 sprintf(void *, ...);
extern u32 lbl_8015ABFC[];

void fn_8007174C(u32 arg0, u32 arg1) {
    struct { u32 a[258]; } loc_8;
    /* frame */
    sprintf(&loc_8, arg0, arg1);
    OSPanic((u32)&lbl_8015ABFC, 498, &loc_8);
}

/* --- dol/fn_80071794.c --- */
void fn_80071794(u32 lab_unused0) {
    ((void (*)(void))lbl_801A6D0C)();
}

/* --- dol/fn_800717BC.c --- */
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

/* --- dol/fn_800718BC.c --- */
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

extern char lbl_8015AC08[];
extern char lbl_8015AC1C[];
extern void OSReport(const char *, ...);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, s32, s32, s32, u8);
extern void GXInitTexObjLOD(GXTexObj *, s32, s32, f32, f32, f32, u8, u8, s32);

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
