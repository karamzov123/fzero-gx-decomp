#include "types.h"
#include "sofdec/sfx.h"
#include "sofdec/sj.h"
#pragma use_lmw_stmw on
#pragma readonly_strings on

/* --- rel/movie_module/fn_12_35EC.c --- */
/* --- rel/movie_module/fn_12_35EC.c --- */
// fn_12_35EC: empty in retail (single blr).
void fn_12_35EC(void) {
}

/* --- rel/movie_module/fn_12_35F0.c --- */
extern u32 lbl_12_bss_4C0[42];
extern void *memset(void *dest, int value, u32 size);

void fn_12_35F0(void) {
    memset(lbl_12_bss_4C0, 0, 0xa8);
    lbl_12_bss_4C0[1] = 8;
}

/* --- rel/movie_module/fn_12_3630.c --- */
typedef struct MovieData {
    u8 _pad0[0x3c];
    f32 value0;
    f32 value1;
} MovieData;

extern const f32 lbl_12_rodata_4E8;

s32 fn_12_3630(const MovieData *movie) {
    f32 value0 = movie->value0;
    f32 value1 = movie->value1;
    s32 result = 1;

    if (lbl_12_rodata_4E8 == value0 && lbl_12_rodata_4E8 == value1) {
        result = 0;
    }
    return result;
}

/* --- rel/movie_module/fn_12_365C.c --- */
void fn_12_365C(const MovieData *movie, f32 *out0, f32 *out1) {
    *out0 = movie->value0;
    *out1 = movie->value1;
}

/* --- rel/movie_module/fn_12_3670.c --- */
extern f32 lbl_12_rodata_4EC;
extern u32 lbl_12_rodata_4F0;
extern void fn_12_309C(u32, u32, u32);


void fn_12_3670(void *arg0, f32 farg0, f32 farg1) {
    s32 var_r0;

    var_r0 = 1;
    if (farg1 <= farg0) {
        var_r0 = 0;
    }
    if ((farg1 - farg0) < (*(f32 *)((u8 *)(&lbl_12_rodata_4EC) + 0))) {
        var_r0 = 0;
    }
    if (var_r0 != 1) {
        fn_12_309C(0U, 0U, (u32)(&lbl_12_rodata_4F0));
    }
    (*(f32 *)((u8 *)(arg0) + 60)) = farg0;
    (*(f32 *)((u8 *)(arg0) + 64)) = farg1;
}

/* --- rel/movie_module/fn_12_3710.c --- */
extern void *memset(void *destination, int value, u32 size);
extern unsigned char *SJ_SearchTag(const SJCK *source, const char *tag, const char *terminator, SJCK *result);
extern s32 sscanf(char *dst, const char *fmt, ...);
extern s32 fn_12_308C(void);
extern void fn_12_3DB8(SFXZObject *object, u32 near_z, u32 far_z, u32 *table);
extern void sfxzmv_MakeOrgZ32TblByDirect(SFXZObject *object, u32 near_z, u32 far_z, u32 *table);
extern u32 lbl_12_bss_568[];

/* retail .rodata 0x4E8-0x51F (SFXZ_SetZclip's literals and error string), then this function's doubles, which
 * retail pools ahead of its strings */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_rodata_4E8[14] = {0x00000000, 0xC1600000, 0x45323031, 0x3331343A, 0x20534658, 0x5A5F5365, 0x745A636C, 0x6970203A, 0x207A636C, 0x69702069, 0x7320696E, 0x76616C69, 0x642E0000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_4E8(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_4E8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_520(void) {
    volatile f64 d;  /* fzgx-allow: S2 pool primer sink */
    d = 1.0;
    d = 16777215.0;
    d = 2147483647.0;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

static inline unsigned char *fn_12_3710_search(SFXZObject *object, const char *tag) {
    SJCK source;
    SJCK found;

    if (object->frame_info_set != 1 || object->frame_data == NULL) {
        return NULL;
    }
    source.data = object->frame_data;
    source.len = object->frame_size;
    SJ_SearchTag(&source, tag, "SFXINFE", &found);
    return found.data;
}

static inline void fn_12_3710_make(SFXZObject *object, u32 near_z, u32 far_z, u32 *table) {
    u32 *z_table;
    f64 near_clip;
    f64 far_clip;
    f64 scale;
    f64 base;
    f64 range;
    s32 i;

    z_table = table + 0x100;
    if (fn_12_308C() == 1) {
        fn_12_3DB8(object, near_z, far_z, z_table);
    } else {
        sfxzmv_MakeOrgZ32TblByDirect(object, near_z, far_z, z_table);
    }
    near_clip = object->near_clip;
    far_clip = object->far_clip;
    if ((s32)lbl_12_bss_568[1] == 1) {
        for (i = 0; i < 0x100; i++) {
            table[i] = z_table[i] & 0x7FFFFF80;
            table[i] <<= 1;
        }
    } else {
        scale = 1.0 / (far_clip - near_clip);
        base = 16777215.0 * far_clip * scale;
        range = far_clip * (16777215.0 * scale * near_clip);
        for (i = 0; i < 0x100; i++) {
            if (z_table[i] == 0) {
                z_table[i] = 1;
            }
            table[i] = (u32)(base - range / (far_clip * z_table[i] / 2147483647.0));
        }
    }
}

void fn_12_3710(SFXZObject *object, s32 index, u32 *table) {
    u32 z_max;
    u32 z_min;
    u32 first;
    u32 record_size;
    u32 near_z;
    u32 far_z;
    unsigned char *text;

    memset(table, 0, 4);
    text = fn_12_3710_search(object, "ZMFSIZE");
    if (text == NULL) {
        near_z = 0;
        far_z = 0x7FFFFFFF;
    } else {
        sscanf((char *)text, "%x", &record_size);
        text = fn_12_3710_search(object, "ZMFDATA");
        if (text == NULL) {
            /* retail sets only near_z on this path */
            near_z = 0x7FFFFFFF;
        } else {
            sscanf((char *)(text + record_size * index), "%x %x %x", &first, &z_min, &z_max);
            near_z = z_min;
            far_z = z_max;
        }
    }
    fn_12_3710_make(object, near_z, far_z, table);
}

/* --- rel/movie_module/fn_12_3A64.c --- */
/* retail .rodata 0x4E8-0x567 ahead of this function's 65535.0: SFXZ_SetZclip's literals and error string, then
 * fn_12_3A64's doubles and strings, which this function shares */

static inline unsigned char *fn_12_3A64_search(SFXZObject *object, const char *tag) {
    SJCK source;
    SJCK found;

    if (object->frame_info_set != 1 || object->frame_data == NULL) {
        return NULL;
    }
    source.data = object->frame_data;
    source.len = object->frame_size;
    SJ_SearchTag(&source, tag, "SFXINFE", &found);
    return found.data;
}

static inline void fn_12_3A64_make(SFXZObject *object, u32 near_z, u32 far_z, u16 *table) {
    u32 *z_table;
    f64 near_clip;
    f64 far_clip;
    f64 scale;
    f64 base;
    f64 range;
    s32 i;

    z_table = (u32 *)(table + 0x100);
    if (fn_12_308C() == 1) {
        fn_12_3DB8(object, near_z, far_z, z_table);
    } else {
        sfxzmv_MakeOrgZ32TblByDirect(object, near_z, far_z, z_table);
    }
    near_clip = object->near_clip;
    far_clip = object->far_clip;
    if ((s32)lbl_12_bss_568[1] == 1) {
        for (i = 0; i < 0x100; i++) {
            table[i] = z_table[i] >> 15;
        }
    } else {
        scale = 1.0 / (far_clip - near_clip);
        base = 65535.0 * far_clip * scale;
        range = far_clip * (65535.0 * scale * near_clip);
        for (i = 0; i < 0x100; i++) {
            if (z_table[i] == 0) {
                z_table[i] = 1;
            }
            table[i] = (u16)(base - range / (far_clip * z_table[i] / 2147483647.0));
        }
    }
}

void fn_12_3A64(SFXZObject *object, s32 index, u16 *table) {
    u32 z_max;
    u32 z_min;
    u32 first;
    u32 record_size;
    u32 near_z;
    u32 far_z;
    unsigned char *text;

    memset(table, 0, 2);
    text = fn_12_3A64_search(object, "ZMFSIZE");
    if (text == NULL) {
        near_z = 0;
        far_z = 0x7FFFFFFF;
    } else {
        sscanf((char *)text, "%x", &record_size);
        text = fn_12_3A64_search(object, "ZMFDATA");
        if (text == NULL) {
            /* retail sets only near_z on this path */
            near_z = 0x7FFFFFFF;
        } else {
            sscanf((char *)(text + record_size * index), "%x %x %x", &first, &z_min, &z_max);
            near_z = z_min;
            far_z = z_max;
        }
    }
    fn_12_3A64_make(object, near_z, far_z, table);
}
