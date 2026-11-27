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

void fn_12_3DB8(SFXZObject_u0 *object, u32 near_z, u32 far_z, u32 *table);

/* --- rel/movie_module/sfxzmv_MakeOrgZ32TblByDirect.c --- */
/* --- rel/movie_module/sfxzmv_MakeOrgZ32TblByDirect.c --- */
/* --- rel/movie_module/sfxzmv_MakeOrgZ32TblByDirect.c --- */
void sfxzmv_MakeOrgZ32TblByDirect(SFXZObject *object, u32 near_z, u32 far_z, u32 *table);

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

void fn_12_47C8(MovieData *movie, u32 source, u32 size);

/* --- rel/movie_module/fn_12_48A0.c --- */
extern u32 lbl_12_bss_568[140];

void fn_12_48A0(u32 *value);

/* --- rel/movie_module/fn_12_48C4.c --- */
typedef struct MovieEntry {
    s32 active;
    u8 unk04[0x38];
    f32 unk3c;
    f32 unk40;
} MovieEntry;

MovieEntry *fn_12_48C4(void);

/* --- rel/movie_module/fn_12_4934.c --- */
// fn_12_4934: empty in retail (single blr).
void fn_12_4934(void);

/* --- rel/movie_module/fn_12_4938.c --- */
extern void *memset(void *dest, int value, u32 size);

void fn_12_4938(void);

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
void fn_12_4A38(f64 *arg0, f64 *arg1, f64 (*arg2)[8]) {
    f64 tmp[64];
    s32 i;
    s32 j;
    s32 k;
    f64 s;

    {
    s32 fzgx_loop_i_142;
for (fzgx_loop_i_142 = 0; fzgx_loop_i_142 < 8; fzgx_loop_i_142++) {
        for (j = 0; j < 8; j++) {
            s = 0.0;
            for (k = 0; k < 8; k++) {
                s += arg2[k][j] * arg0[fzgx_loop_i_142 * 8 + k];
            }
            tmp[fzgx_loop_i_142 * 8 + j] = s;
        }
    }
    i = fzgx_loop_i_142;
}

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            s = 0.0;
            for (k = 0; k < 8; k++) {
                s += arg2[k][j] * tmp[i + k * 8];
            }
            arg1[j * 8 + i] = s;
        }
    }
}
