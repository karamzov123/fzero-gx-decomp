#include "types.h"
#include "sofdec/sfx.h"
#include "sofdec/sj.h"

#pragma use_lmw_stmw on
#pragma readonly_strings on

extern void *memset(void *destination, int value, u32 size);
extern unsigned char *SJ_SearchTag(const SJCK *source, const char *tag, const char *terminator, SJCK *result);
extern s32 fn_80082928(char *dst, const char *fmt, ...);
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
        fn_80082928((char *)text, "%x", &record_size);
        text = fn_12_3710_search(object, "ZMFDATA");
        if (text == NULL) {
            /* retail sets only near_z on this path */
            near_z = 0x7FFFFFFF;
        } else {
            fn_80082928((char *)(text + record_size * index), "%x %x %x", &first, &z_min, &z_max);
            near_z = z_min;
            far_z = z_max;
        }
    }
    fn_12_3710_make(object, near_z, far_z, table);
}
