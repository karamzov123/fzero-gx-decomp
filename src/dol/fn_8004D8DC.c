#include "types.h"

typedef struct SJCK {
    u8 *data;
    u32 len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface {
    u8 pad_0[0x18];
    void (*get_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
} SJInterface;

struct SJ {
    const SJInterface *interface;
};

typedef struct AdxSjdHandle AdxSjdHandle;

typedef struct ADXTHandle {
    u8 pad_0[4];
    AdxSjdHandle *decoder;
    u8 pad_8[0xC];
    SJ *input_sj;
    u8 pad_18[0x30];
    s32 maximum_decode_samples;
    u8 pad_4C[0x4C];
    s8 link_enabled;
    u8 pad_99[0xB];
    s32 linked_decoded_samples;
} ADXTHandle;

extern s32 fn_80046804(void *data, u32 len, s16 *out_len);
extern s32 ADX_ScanInfoCode(signed char *buffer, int buffer_len, short *data_len);
extern void fn_800589BC(const SJCK *source, s32 nbyte, SJCK *first, SJCK *remainder);
extern u32 fn_800416F8(AdxSjdHandle *decoder);
extern void fn_800420F4(AdxSjdHandle *decoder);
extern void fn_8004212C(AdxSjdHandle *decoder);
extern void fn_80041990(AdxSjdHandle *decoder);
extern s32 fn_800421C0(AdxSjdHandle *decoder);
extern void fn_80042170(AdxSjdHandle *decoder, s32 samples);
extern s32 fn_800415F4(AdxSjdHandle *decoder);
extern void fn_800416DC(AdxSjdHandle *decoder, s32 samples);
extern void fn_800416CC(AdxSjdHandle *decoder, s32 enabled);
extern void fn_800416D4(AdxSjdHandle *decoder, s32 length);

static inline const SJInterface * fn_8004D8DC_read_pointer(SJ * owner) { return owner->interface; }
static inline const SJInterface * fn_8004D8DC_read_pointer_(SJ * owner) { return owner->interface; }
void fn_8004D8DC(ADXTHandle *handle) {
    void (* fzgx_live_)(SJ *sj, int channel, int max_size, SJCK *chunk);
    const SJInterface * fzgx_live;
    AdxSjdHandle *decoder = handle->decoder;
    SJ *input = handle->input_sj;
    SJCK chunk1;
    SJCK remainder1;
    SJCK chunk2;
    SJCK remainder2;
    s16 info1;
    s16 info2;
    s32 nbyte;
    s32 scan1;
    s32 scan2;
    s32 link_off;

    if (handle->link_enabled == 0) {
        return;
    }
    info2 = 0;
    fzgx_live = fn_8004D8DC_read_pointer(input);
    fzgx_live_ = fzgx_live->get_chunk;
    fzgx_live_(input, 1, 0x7FFFFFFF, &chunk1);
    fzgx_live = fn_8004D8DC_read_pointer_(input);
    fzgx_live_ = fzgx_live->get_chunk;
    fzgx_live_(input, 1, 0x7FFFFFFF, &chunk2);
    if (fn_80046804(chunk1.data, chunk1.len, &info1) != 0) {
        handle->link_enabled = 0;
        fzgx_live = fn_8004D8DC_read_pointer_(input);
        fzgx_live->unget_chunk(input, 1, &chunk2);
        fzgx_live = fn_8004D8DC_read_pointer_(input);
        fzgx_live->unget_chunk(input, 1, &chunk1);
        return;
    }
    nbyte = info1;
    scan1 = ADX_ScanInfoCode((signed char *)chunk1.data + nbyte, chunk1.len - nbyte, &info1);
    if (scan1 == 0) {
        scan2 = -1;
    } else {
        scan2 = ADX_ScanInfoCode((signed char *)chunk2.data, chunk2.len, &info2);
    }
    nbyte = nbyte + info1;
    link_off = (s16)(info2);
    if (scan1 != 0 && scan2 != 0) {
        fzgx_live = fn_8004D8DC_read_pointer_(input);
        fzgx_live->unget_chunk(input, 1, &chunk2);
        fzgx_live = fn_8004D8DC_read_pointer_(input);
        fzgx_live->unget_chunk(input, 1, &chunk1);
        handle->link_enabled = 0;
        return;
    }
    if (scan1 == 0) {
        fzgx_live = fn_8004D8DC_read_pointer_(input);
        fzgx_live->unget_chunk(input, 1, &chunk2);
        fn_800589BC(&chunk1, nbyte, &chunk1, &remainder1);
        fzgx_live = fn_8004D8DC_read_pointer_(input);
        fzgx_live->put_chunk(input, 0, &chunk1);
        fzgx_live = fn_8004D8DC_read_pointer_(input);
        fzgx_live->unget_chunk(input, 1, &remainder1);
    } else {
        fzgx_live = fn_8004D8DC_read_pointer_(input);
        fzgx_live->put_chunk(input, 0, &chunk1);
        fn_800589BC(&chunk2, link_off, &chunk2, &remainder2);
        fzgx_live = fn_8004D8DC_read_pointer_(input);
        fzgx_live->put_chunk(input, 0, &chunk2);
        fzgx_live = fn_8004D8DC_read_pointer_(input);
        fzgx_live->unget_chunk(input, 1, &remainder2);
    }
    handle->linked_decoded_samples += fn_800416F8(decoder);
    fn_800420F4(decoder);
    fn_8004212C(decoder);
    fn_80041990(decoder);
    if (fn_800421C0(decoder) != 2) {
        handle->link_enabled = 0;
        return;
    }
    fn_80042170(decoder, handle->maximum_decode_samples);
    fn_800416DC(decoder, fn_800415F4(decoder));
    fn_800416CC(decoder, 0);
    fn_800416D4(decoder, 0);
}



