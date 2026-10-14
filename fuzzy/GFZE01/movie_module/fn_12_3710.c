/* Non-matching: best partial attempt (91.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern s32 lbl_12_bss_568[140];
extern s32 fn_12_308C();
extern void *memset(void *, int, u32);

typedef struct Sig_SJ_SearchTag_SJCK {
    unsigned char *data;
    int len;
} Sig_SJ_SearchTag_SJCK;

extern unsigned char *SJ_SearchTag(const Sig_SJ_SearchTag_SJCK *, const char *, const char *, Sig_SJ_SearchTag_SJCK *);
extern s32 fn_80082928(char *, const char *, ...);

typedef struct MovieData {
    s32 active;
    s32 z_bit;
    s32 tag_info_set;
    u8 *tag_data;
    s32 tag_size;
    u8 unk14[4];
    s32 header_info_set;
    u8 *header_data;
    s32 header_size;
    u8 unk24[4];
    s32 frame_info_set;
    u8 *frame_data;
    s32 frame_size;
    u8 unk34[8];
    f32 near_clip;
    f32 far_clip;
    void *callback;
    void *unk48;
} MovieData;

extern void fn_12_3DB8(MovieData *, u32, u32, u32 *);
extern void sfxzmv_MakeOrgZ32TblByDirect(MovieData *, u32, u32, u32 *);

void fn_12_3710(MovieData *movie, u32 arg1, u32 *out) {
    u32 hi;
    u32 lo;
    u32 mid;
    u32 count;
    Sig_SJ_SearchTag_SJCK res;
    Sig_SJ_SearchTag_SJCK key;
    Sig_SJ_SearchTag_SJCK res2;
    Sig_SJ_SearchTag_SJCK key2;
    u32 a = arg1;
    u32 b;
    u32 *src;
    s32 i;
    unsigned char *tag;
    unsigned char *tag2;
    f64 near_clip;
    f64 far_clip;

    memset(out, 0, 4);
    tag = 0;
    if (movie->frame_info_set == 1 && movie->frame_data) {
        key.data = movie->frame_data;
        key.len = movie->frame_size;
        SJ_SearchTag(&key, "ztags1", "ztags2", &res);
        tag = res.data;
    }
    if (tag == 0) {
        a = 0;
        b = 0x7FFFFFFF;
    } else {
        fn_80082928((char *)tag, "%d", &count);
        tag2 = 0;
        if (movie->frame_info_set == 1 && movie->frame_data) {
            key2.data = movie->frame_data;
            key2.len = movie->frame_size;
            SJ_SearchTag(&key2, "ztags3", "ztags2", &res2);
            tag2 = res2.data;
        }
        if (tag2 == 0) {
            a = 0x7FFFFFFF;
        } else {
            fn_80082928((char *)(tag2 + count * a), "%d %d %d", &mid, &lo, &hi);
            a = lo;
            b = hi;
        }
    }
    src = out + 0x100;
    if (fn_12_308C() == 1) {
        fn_12_3DB8(movie, a, b, src);
    } else {
        sfxzmv_MakeOrgZ32TblByDirect(movie, a, b, src);
    }
    near_clip = movie->near_clip;
    far_clip = movie->far_clip;
    if (lbl_12_bss_568[1] == 1) {
        for (i = 0; i < 0x100; i++) {
            out[i] = src[i] & 0x1FFFFFE;
            out[i] <<= 1;
        }
    } else {
        f64 t = 1.0 / (far_clip - near_clip);
        f64 v = 16777215.0 * t;
        f64 s = 16777215.0 * far_clip;
        f64 q = v * near_clip;
        f64 A = s * t;
        f64 B = far_clip * q;
        for (i = 0; i < 0x100; i++) {
            if (src[i] == 0) {
                src[i] = 1;
            }
            out[i] = (u32)(A - B / (far_clip * ((f64)src[i] - 4503599627370496.0) / 2147483647.0));
        }
    }
}
