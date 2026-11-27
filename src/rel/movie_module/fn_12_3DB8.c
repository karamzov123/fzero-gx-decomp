#include "types.h"
#include "sofdec/sfx.h"


/* --- rel/movie_module/fn_12_3DB8.c --- */
typedef struct SFXZObject_u0 SFXZObject_u0;

extern const f32 lbl_12_rodata_570;
extern f64 lbl_12_rodata_578[3];

typedef void (*SFXZConvertCallback)(u32 *source, void *destination, f32 near_clip, f32 far_clip);

struct SFXZObject_u0 {
    s32 active;
    s32 z_bit;
    s32 tag_info_set;
    u8 *tag_data;
    s32 tag_size;
    u8 reserved_14[4];
    s32 header_info_set;
    u8 *header_data;
    s32 header_size;
    u8 reserved_24[4];
    s32 frame_info_set;
    u8 *frame_data;
    s32 frame_size;
    u8 reserved_34[8];
    f32 near_clip;
    f32 far_clip;
    SFXZConvertCallback convert_callback;
    void *field_48;
};

void fn_12_3DB8(SFXZObject_u0 *object, u32 near_z, u32 far_z, u32 *table);

void fn_12_3DB8(SFXZObject_u0 *object, u32 near_z, u32 far_z, u32 *table) {
    s32 i;
    s32 j;
    u8 *ccir_table;
    u32 *z_table;
    z_table = table + 0x100;
    ccir_table = (u8 *)(z_table + 0x100);
    { s32 index_0;
for (index_0 = 0; index_0 <= 15; index_0++) {
        ccir_table[index_0] = 0;
    }
i = index_0;
}
    for (j = 16; j <= 235; j++) {
        ccir_table[j] = (u8)(lbl_12_rodata_570 * (f32)(j - 16));
    }
    { s32 index_1;
for (index_1 = 236; index_1 <= 255; index_1++) {
        ccir_table[index_1] = 255;
    }
i = index_1;
}
    if (far_z == 0x80000000U) {
        far_z = 0x7FFFFFFF;
    }
    if (near_z == 0x80000000U) {
        near_z = 0x7FFFFFFF;
    }
    { s32 index_2;
for (index_2 = 0; index_2 < 9; index_2++) {
        z_table[index_2] = 0;
    }
i = index_2;
}
    for (i = 9; i < 17; i++) {
        z_table[i] = near_z;
    }
    if (near_z == far_z) {
        for (i = 17; i < 224; i++) {
            z_table[i] = near_z;
        }
    } else {
        for (i = 17; i < 224; i++) {
            z_table[i] = near_z + (i - 17) * ((far_z - near_z) / 207);
        }
    }
    { s32 index_6;
for (index_6 = 224; index_6 < 240; index_6++) {
        z_table[index_6] = far_z;
    }
i = index_6;
}
    { s32 index_7;
for (index_7 = 240; index_7 < 256; index_7++) {
        z_table[index_7] = 0x7FFFFFFF;
    }
i = index_7;
}
    { s32 index_8;
for (index_8 = 0; index_8 <= 255; index_8++) {
        table[index_8] = z_table[((ccir_table)[index_8])];
    }
i = index_8;
}
}

/* --- rel/movie_module/sfxzmv_MakeOrgZ32TblByDirect.c --- */
/* --- rel/movie_module/sfxzmv_MakeOrgZ32TblByDirect.c --- */
/* --- rel/movie_module/sfxzmv_MakeOrgZ32TblByDirect.c --- */
void sfxzmv_MakeOrgZ32TblByDirect(SFXZObject *object, u32 near_z, u32 far_z, u32 *table) {
    s32 i;
    if (far_z == 0x80000000U) {
        far_z = 0x7FFFFFFF;
    }
    if (near_z == 0x80000000U) {
        near_z = 0x7FFFFFFF;
    }
    for (i = 0; i < 9; i++) {
        table[i] = 0;
    }
    for (i = 9; i < 17; i++) {
        table[i] = near_z;
    }
    if (near_z == far_z) {
        for (i = 17; i < 224; i++) {
            table[i] = near_z;
        }
    } else {
        for (i = 17; i < 224; i++) {
            table[i] = near_z + (i - 17) * ((far_z - near_z) / 207);
        }
    }
    for (i = 224; i < 240; i++) {
        table[i] = far_z;
    }
    for (i = 240; i < 256; i++) {
        table[i] = 0x7FFFFFFF;
    }
}

/* --- rel/movie_module/fn_12_47C8.c --- */
extern const f32 lbl_12_rodata_4E8;
extern void SJ_SearchTag(u32 *, const char *, const char *, u32 *);

typedef struct MovieData {
    u8 unk0[8];
    u32 state;
    u32 source;
    u32 size;
    u8 unk14[4];
    u32 width;
    u32 unk1c;
    u32 unk20;
    u8 unk24[4];
    u32 height;
    u32 unk2c;
    u32 unk30;
} MovieData;

void fn_12_47C8(MovieData *movie, u32 source, u32 size) {
    const char *base = (const char *)&lbl_12_rodata_4E8;
    u32 output[2];
    u32 input[2];

    movie->state = 1;
    movie->source = source;
    movie->size = size;
    if (movie->source == 0) {
        movie->width = 1;
        movie->unk1c = 0;
        movie->unk20 = 0;
        movie->height = 1;
        movie->unk2c = 0;
        movie->unk30 = 0;
    } else {
        input[0] = movie->source;
        input[1] = movie->size;
        SJ_SearchTag(input, base + 0x98, base + 0x60, output);
        movie->width = 1;
        movie->unk1c = output[0];
        movie->unk20 = output[1];
        SJ_SearchTag(input, base + 0xa0, base + 0x60, output);
        movie->height = 1;
        movie->unk2c = output[0];
        movie->unk30 = output[1];
    }
}

/* --- rel/movie_module/fn_12_48A0.c --- */
extern u32 lbl_12_bss_568[140];

void fn_12_48A0(u32 *value) {
    if (value != 0) {
        *value = 0;
        lbl_12_bss_568[0]--;
    }
}

/* --- rel/movie_module/fn_12_48C4.c --- */
typedef struct MovieEntry {
    s32 active;
    u8 unk04[0x38];
    f32 unk3c;
    f32 unk40;
} MovieEntry;

MovieEntry *fn_12_48C4(void) {
    s32 count;
    MovieEntry *entry;
    MovieEntry *result;

    count = lbl_12_bss_568[2];
    entry = (MovieEntry *)&lbl_12_bss_568[3];
    for (; count > 0; count--) {
        if (entry->active == 0) {
            result = entry;
            goto found; // early hit on a free slot; must skip the clear below
        }
        entry++;
    }
    result = 0;
found:
    if (result != 0) {
        result->unk3c = lbl_12_rodata_4E8;
        result->unk40 = lbl_12_rodata_4E8;
        lbl_12_bss_568[0]++;
        result->active = 1;
    }
    return result;
}

/* --- rel/movie_module/fn_12_4934.c --- */
// fn_12_4934: empty in retail (single blr).
void fn_12_4934(void) {
}

/* --- rel/movie_module/fn_12_4938.c --- */
extern void *memset(void *dest, int value, u32 size);

void fn_12_4938(void) {
    memset(lbl_12_bss_568, 0, 0x22c);
    lbl_12_bss_568[2] = 8;
    lbl_12_bss_568[1] = 0;
}

/* --- rel/movie_module/fn_12_4980.c --- */
extern u32 fn_12_59C(u32, u32);

struct fn_12_4980_Arg0 {
    u8 pad_0[0x58];
    u32 unk_58;
};

void fn_12_4980(struct fn_12_4980_Arg0 *arg0);

/* --- rel/movie_module/fn_12_49AC.c --- */
extern u32 fn_12_5EC(u32, u32);

struct fn_12_49AC_Arg0 {
    u8 pad_0[0x58];
    u32 unk_58;
};

void fn_12_49AC(struct fn_12_49AC_Arg0 *arg0);

/* --- rel/movie_module/fn_12_49D8.c --- */
typedef struct MovieState {
    u8 pad[0x58];
    s32 value;
} MovieState;

int fn_12_49D8(MovieState *state);

/* --- rel/movie_module/fn_12_49EC.c --- */
typedef struct Fn1249EC {
    u8 _pad58[0x58];
    u32 field_58;
    u32 field_5c;
} Fn1249EC;

void fn_12_49EC(Fn1249EC *self, u32 value_58, u32 value_5c);

/* --- rel/movie_module/fn_12_49F8.c --- */
extern void fn_12_63C(void);

void fn_12_49F8(void);

/* --- rel/movie_module/fn_12_4A18.c --- */
extern void fn_12_65C(void);

void fn_12_4A18(void);

/* --- rel/movie_module/fn_12_4A38.c --- */
void fn_12_4A38(f64 *arg0, f64 *arg1, f64 (*arg2)[8]);
