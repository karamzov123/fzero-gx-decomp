#include "types.h"

typedef struct SJCK {
    unsigned char *data;
    int len;
} SJCK;

typedef struct SJ SJ;
typedef struct SJInterface SJInterface;
typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
    const void *(*get_uuid)(SJ *sj);
    void (*reset)(SJ *sj);
    void (*get_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ *sj, int channel);
    int (*is_get_chunk)(SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ *sj, SJErrorCallback callback, void *object);
};

struct SJ {
    const SJInterface *interface;
};

typedef struct AdxSjdHandle AdxSjdHandle;
typedef struct ADXStream ADXStream;
typedef struct AXRNAHandle AXRNAHandle;
typedef struct LSCObject LSCObject;
typedef struct ADX_AMP ADX_AMP;

typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 minimum_buffer_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 field_46;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 link_data_length;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    s32 pending_filename;
    s32 pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle;

enum {
    ADXT_STATUS_DECODING_HEADER = 1,
    ADXT_STATUS_BUFFERING = 2,
    ADXT_STATUS_PLAYING = 3,
    ADXT_STATUS_DRAINING = 4,
    ADXT_STATUS_ERROR = 6,
    ADXT_STREAM_TYPE_FILE = 0,
    ADXT_STREAM_TYPE_RANGE = 1,
    ADXT_STREAM_TYPE_MEMORY = 2,
    ADXT_STREAM_TYPE_LINKED = 3,
    ADXSJD_STATUS_HEADER_READY = 2,
    ADXSJD_STATUS_INPUT_END = 3,
    ADXSTM_STATUS_READING = 2,
    ADXSTM_STATUS_END = 3,
    ADXSTM_STATUS_ERROR = 4,
    ADXT_SECTOR_SIZE = 0x800,
    ADXT_MIN_PLAY_DATA = 0x40
};

typedef s32 (*Fn1)(u32, s32);
typedef s32 (*Fn2)(u32, s32, u32, void *);
typedef s32 (*Fn3)(u32, s32, void *);

struct Vec {
    u32 *a;
    u32 b;
};

extern u32 lbl_8017E5A8[];
extern const char lbl_80091098[];
extern char lbl_800910C4[];
extern const char lbl_80091104[];
extern u32 lbl_80178CB8[];

extern void fn_800474E4(const char *);
extern void fn_80047464(const char *, char *);
extern void ADXT_Stop(ADXTHandle *);
extern void *memset(void *, int, u32);
extern s32 fn_800421C0(void *);
extern s32 fn_80041660(void *);
extern s32 fn_80041618(void *);
extern s32 fn_80041684(void *);
extern s32 fn_800415D0(void *);
extern s32 fn_80041530(void *);
extern s32 fn_80041554(void *);
extern s32 fn_80041578(void *);
extern s32 fn_800415AC(void *);
extern s32 fn_800415F4(void *);
extern s32 fn_8004163C(void *);
extern s32 fn_800416A8(void *);
extern s32 fn_80041458(void *);
extern s16 fn_80041460(void *, s32);
extern s16 fn_800414D0(void *);
extern void fn_80041410(void *);
extern u32 fn_80041434(void *);
extern void fn_800416DC(void *, s32);
extern void fn_800416CC(void *, s32);
extern void fn_800416D4(void *, s32);
extern void fn_800416E4(void *, void (*)(void *), void *);
extern void fn_800416F0(void *, s32);
extern u32 fn_800416F8(void *);
extern void fn_800420F4(void *);
extern void fn_8004212C(void *);
extern void fn_80041990(void *);
extern void fn_8004216C(void *);
extern void fn_80042170(void *, s32);
extern void fn_8004EEC4(void *, s32);
extern s32 fn_8004EE84(void *);
extern s32 fn_8004EE64(void *);
extern void fn_8004EEA4(void *, s32);
extern void fn_8004EDA4(void *, s32);
extern void fn_8004EE04(void *, s32);
extern void fn_8004EE24(void *, s32);
extern void fn_8004ED80(void *, s32);
extern void fn_8004EDE4(void *, s32);
extern void fn_8004ED5C(void *, s32);
extern void fn_8004EDC4(void *, s32, s32);
extern s32 fn_8004C05C(void *);
extern s32 fn_8004C658(char *);
extern void fn_8004C980(ADXTHandle *, s32, s32, s32, s32);
extern s32 fn_8004AEE4(void *);
extern void fn_8004AC04(void *, s32);
extern void fn_8004AC4C(void *, void (*)(void *), void *);
extern s32 fn_8004AE94(void *, s32);
extern s32 fn_80056C20(void *);
extern void fn_80046F88(s32, s32, char *, s32);
extern void fn_8004BBC4(ADXTHandle *, s32 *, s32 *);
extern void fn_8004BBC8(ADXTHandle *, s32, s32);
extern void fn_80046508(void *, s32);
extern s32 fn_80046804(void *, u32, s16 *);
extern s32 ADX_ScanInfoCode(signed char *, int, short *);
extern void fn_800589BC(const SJCK *, s32, SJCK *, SJCK *);

void fn_8004D528(ADXTHandle *adxt);
void fn_8004D8DC(void *object);
void adxt_set_outpan(ADXTHandle *handle);
void adxt_eos_entry(void *object);
void fn_8004DE70(void *object);
void fn_8004DFF0(void *object);

void fn_8004D220(u32 arg0) {
    struct Vec loc;
    u32 g = (u32)&lbl_8017E5A8;

    if (arg0 == 0) {
        fn_800474E4(lbl_80091098);
    } else {
        if (*(s8 *)(arg0 + 1) == 3) {
            if (fn_800421C0((void *)*(u32 *)(arg0 + 4)) == 3) {
                s32 n = fn_80041660((void *)*(u32 *)(arg0 + 4));
                s32 i;
                u32 q = arg0;

                *(u32 *)(g + 8) = n;
                for (i = 0; i < n; i++) {
                    u32 v = *(u32 *)(q + 0x18);
                    s32 res = ((Fn1)*(u32 *)((u8 *)*(u32 *)v + 0x24))(v, 1);

                    *(u32 *)(g + 4) = res;
                    if (res >= 0x40) {
                        break;
                    }
                    q += 4;
                }
                if (i == n) {
                    fn_8004EEC4((void *)*(u32 *)(arg0 + 0xc), 0);
                    *(u8 *)((u8 *)arg0 + 1) = 4;
                }
            }
        } else if (*(s8 *)(arg0 + 1) == 1) {
            fn_8004D528((ADXTHandle *)arg0);
        } else if (*(s8 *)(arg0 + 1) == 2) {
            u32 b;
            u32 a = *(u32 *)(arg0 + 0xc);
            s32 n1;
            s32 n2;

            b = *(u32 *)(arg0 + 4);
            n1 = fn_8004EE84((void *)a);
            n2 = fn_8004EE64((void *)a);
            if (n1 < (*(s32 *)(arg0 + 0x48) << 1) &&
                n2 > fn_80041618((void *)b) &&
                fn_800421C0((void *)*(u32 *)(arg0 + 4)) != 3) {
                goto L390; /* Keep the verified branch to L390. */
            }
            if (*(s8 *)(arg0 + 0x70) == 0) {
                if (*(s8 *)(arg0 + 0x72) == 0) {
                    fn_8004EEA4((void *)a, 1);
                    *(u32 *)((u8 *)arg0 + 0x9c) = 0;
                    *(u32 *)((u8 *)arg0 + 0xa0) = lbl_80178CB8[0];
                }
                *(u8 *)((u8 *)arg0 + 1) = 3;
            }
            *(u8 *)((u8 *)arg0 + 0x71) = 1;
        L390:
            if (fn_800421C0((void *)*(u32 *)(arg0 + 4)) == 3) {
                s32 cnt = fn_8004C05C((void *)arg0);
                s32 i;
                u32 v;
                u32 sz;
                u32 q;

                q = arg0;
                i = 0;
                sz = (*(s32 *)(arg0 + 0x48) * cnt) << 1;
                while (i < cnt) {
                    v = *(u32 *)(q + 0x18);
                    ((Fn2)*(u32 *)((u8 *)*(u32 *)v + 0x18))(v, 0, sz, &loc);
                    memset(loc.a, 0, loc.b);
                    ((Fn3)*(u32 *)((u8 *)*(u32 *)v + 0x20))(v, 1, &loc);
                    q += 4;
                    i++;
                }
            }
        } else if (*(s8 *)(arg0 + 1) == 4) {
            *(u32 *)(g + 0) = fn_8004EE84((void *)*(u32 *)((u8 *)arg0 + 0xc));
            if (fn_8004EE84((void *)*(u32 *)(arg0 + 0xc)) <= 0) {
                fn_8004EEA4((void *)*(u32 *)(arg0 + 0xc), 0);
                *(u8 *)((u8 *)arg0 + 1) = 5;
            }
        }

        if (*(u32 *)(arg0 + 8) != 0) {
            if (fn_8004C658((char *)arg0) != 0) {
                switch (*(s8 *)(arg0 + 2)) {
                case 0:
                case 1:
                    if (fn_8004AEE4((void *)*(u32 *)(arg0 + 8)) == 3) {
                        fn_8004216C((void *)*(u32 *)(arg0 + 4));
                    }
                    break;
                case 2:
                    fn_8004216C((void *)*(u32 *)(arg0 + 4));
                    break;
                case 3:
                    break;
                }
            }
        }
        if (*(u32 *)(arg0 + 8) != 0) {
            if (fn_8004AEE4((void *)*(u32 *)(arg0 + 8)) == 4) {
                *(s16 *)((u8 *)arg0 + 0x60) = -1;
                *(u8 *)((u8 *)arg0 + 1) = 6;
            }
        }
        if (*(u32 *)(arg0 + 0x94) != 0) {
            if (fn_80056C20((void *)*(u32 *)(arg0 + 0x94)) == 3) {
                *(s16 *)((u8 *)arg0 + 0x60) = -1;
                *(u8 *)((u8 *)arg0 + 1) = 6;
            }
        }
    }
}

void fn_8004D528(ADXTHandle *adxt) {
    void *sjd;
    s32 nch;
    s32 sfreq;
    s32 total;
    s32 block;
    s32 offset;
    s32 nsmpl;
    s32 nsct;
    s32 format;
    s32 loop;
    s32 lvol;
    s32 rvol;
    char buf[32];

    sjd = adxt->decoder;
    lvol = 0;
    rvol = 0;
    if ((adxt->stream_type == 0 || adxt->stream_type == 1) && adxt->pending_stream_start == 1) {
        if (fn_8004AEE4(adxt->stream) == 2) {
            return;
        }
        if (adxt->stream_sj != NULL) {
            adxt->stream_sj->interface->reset(adxt->stream_sj);
        }
        fn_8004C980(adxt, adxt->pending_filename, adxt->pending_directory,
                    adxt->pending_file_offset, adxt->pending_file_sectors);
        adxt->pending_stream_start = 0;
    }
    if (fn_800421C0(sjd) != 2) {
        return;
    }
    nch = fn_80041660(sjd);
    if (nch > adxt->maximum_channels) {
        fn_80046F88(nch, adxt->maximum_channels, buf, 16);
        fn_80047464(lbl_800910C4, buf);
        ADXT_Stop(adxt);
        return;
    }

    sfreq = fn_80041684(sjd);
    total = fn_800415D0(sjd);
    if (total > 0) {
        adxt->maximum_decode_samples = sfreq / adxt->server_frequency * 3;
    } else {
        adxt->maximum_decode_samples = sfreq / adxt->server_frequency * 3 / 2;
    }
    block = fn_80041618(sjd) * 2;
    adxt->maximum_decode_samples = (adxt->maximum_decode_samples + block) / block * block;
    fn_80042170(sjd, adxt->maximum_decode_samples);

    if (total > 0) {
        if (adxt->stream_type == 2) {
            adxt->link_data_length = 0;
        } else {
            offset = fn_80041530(sjd);
            adxt->link_data_length = 0x800 - offset % 0x800;
            adxt->link_data_length = adxt->link_data_length % 0x800;
            nsct = (offset + 0x7FF) / 0x800;
            adxt->eos_sector = nsct;
            fn_8004AC04(adxt->stream, nsct);
            fn_8004AC4C(adxt->stream, adxt_eos_entry, adxt);
        }
        fn_80041554(sjd);
        adxt->loop_sample_count = fn_800415AC(sjd);
        fn_800416DC(sjd, adxt->loop_sample_count);
        fn_800416CC(sjd, 0);
        fn_800416D4(sjd, 0);
        fn_800416E4(sjd, fn_8004DFF0, adxt);
    } else {
        if (adxt->stream != NULL) {
            fn_8004AC04(adxt->stream, 0x7FFFFFFF);
        }
        fn_800416DC(sjd, fn_800415F4(sjd));
        fn_800416CC(sjd, 0);
        fn_800416D4(sjd, 0);
        fn_800416E4(sjd, fn_8004D8DC, adxt);
    }

    sfreq = fn_80041684(sjd);
    nch = fn_80041660(sjd);
    nsmpl = fn_800415F4(sjd);
    format = fn_8004163C(sjd);
    fn_8004EDA4(adxt->rna, format);
    fn_8004EE04(adxt->rna, sfreq);
    fn_8004EE24(adxt->rna, nch);
    fn_8004ED80(adxt->rna, nsmpl);
    fn_8004EDE4(adxt->rna, adxt->output_volume + fn_800414D0(adxt->decoder));
    fn_8004BBC4(adxt, &lvol, &rvol);
    if (lvol != 0 || rvol != 0) {
        fn_8004BBC8(adxt, lvol, rvol);
    }
    adxt_set_outpan(adxt);
    if (adxt->amplifier != NULL) {
        fn_80046508(adxt->amplifier, sfreq);
    }
    if (fn_800416A8(sjd) == 2) {
        loop = fn_80041458(sjd);
        fn_8004ED5C(adxt->rna, loop);
    }
    fn_8004EEC4(adxt->rna, 1);
    adxt->status = 2;
}

void fn_8004D8DC(void *object) {
    ADXTHandle *handle = (ADXTHandle *)object;
    void (*fzgx_live_)(SJ *sj, int channel, int max_size, SJCK *chunk);
    const SJInterface *fzgx_live;
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
    fzgx_live = input->interface;
    fzgx_live_ = fzgx_live->get_chunk;
    fzgx_live_(input, 1, 0x7FFFFFFF, &chunk1);
    fzgx_live = input->interface;
    fzgx_live_ = fzgx_live->get_chunk;
    fzgx_live_(input, 1, 0x7FFFFFFF, &chunk2);
    if (fn_80046804(chunk1.data, chunk1.len, &info1) != 0) {
        handle->link_enabled = 0;
        fzgx_live = input->interface;
        fzgx_live->unget_chunk(input, 1, &chunk2);
        fzgx_live = input->interface;
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
        fzgx_live = input->interface;
        fzgx_live->unget_chunk(input, 1, &chunk2);
        fzgx_live = input->interface;
        fzgx_live->unget_chunk(input, 1, &chunk1);
        handle->link_enabled = 0;
        return;
    }
    if (scan1 == 0) {
        fzgx_live = input->interface;
        fzgx_live->unget_chunk(input, 1, &chunk2);
        fn_800589BC(&chunk1, nbyte, &chunk1, &remainder1);
        fzgx_live = input->interface;
        fzgx_live->put_chunk(input, 0, &chunk1);
        fzgx_live = input->interface;
        fzgx_live->unget_chunk(input, 1, &remainder1);
    } else {
        fzgx_live = input->interface;
        fzgx_live->put_chunk(input, 0, &chunk1);
        fn_800589BC(&chunk2, link_off, &chunk2, &remainder2);
        fzgx_live = input->interface;
        fzgx_live->put_chunk(input, 0, &chunk2);
        fzgx_live = input->interface;
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

void adxt_set_outpan(ADXTHandle *handle) {
    s32 default_pan[2];
    s32 channel_count;
    s32 channel;
    s32 pan;
    channel_count = fn_80041660(handle->decoder);
    for (channel = 0; channel < 2; channel++) {
        default_pan[channel] = fn_80041460(handle->decoder, channel);
    }
    if (channel_count == 1) {
        pan = handle->output_pan[0];
        if (pan == -128 && default_pan[0] == -128) {
            fn_8004EDC4(handle->rna, 0, 0);
        } else if (pan != -128 && default_pan[0] == -128) {
            fn_8004EDC4(handle->rna, 0, pan);
        } else if (pan == -128 && default_pan[0] != -128) {
            fn_8004EDC4(handle->rna, 0, default_pan[0]);
        } else {
            fn_8004EDC4(handle->rna, 0, pan + default_pan[0]);
        }
        return;
    }
    pan = handle->output_pan[0];
    if (pan == -128 && default_pan[0] == -128) {
        fn_8004EDC4(handle->rna, 0, -15);
    } else if (pan != -128 && default_pan[0] == -128) {
        fn_8004EDC4(handle->rna, 0, pan);
    } else if (pan == -128 && default_pan[0] != -128) {
        fn_8004EDC4(handle->rna, 0, default_pan[0]);
    } else {
        fn_8004EDC4(handle->rna, 0, pan + default_pan[0]);
    }
    pan = handle->output_pan[1];
    if (pan == -128 && default_pan[1] == -128) {
        fn_8004EDC4(handle->rna, 1, 15);
    } else if (pan != -128 && default_pan[1] == -128) {
        fn_8004EDC4(handle->rna, 1, pan);
    } else if (pan == -128 && default_pan[1] != -128) {
        fn_8004EDC4(handle->rna, 1, default_pan[1]);
    } else {
        fn_8004EDC4(handle->rna, 1, pan + default_pan[1]);
    }
}

void adxt_eos_entry(void *object) {
    ADXTHandle *handle = (ADXTHandle *)object;
    ADXStream *stream = handle->stream;
    AdxSjdHandle *decoder = handle->decoder;
    s32 loop_start_offset;
    if (stream == 0 || decoder == 0) {
        return;
    }
    loop_start_offset = fn_80041578(decoder);
    if (handle->stream_loop_enabled == 0) {
        fn_800416DC(handle->decoder, -1);
        fn_8004AC04(handle->stream, 0x7FFFFFFF);
    } else {
        fn_8004AE94(stream, loop_start_offset / ADXT_SECTOR_SIZE);
    }
}

void fn_8004DE70(void *object) {
    ADXTHandle *handle = (ADXTHandle *)object;
    AdxSjdHandle *decoder = handle->decoder;
    SJ *input = handle->input_sj;
    SJCK chunk;
    s32 loop_start_position;
    s32 loop_start_offset;
    s32 loop_end_position;
    s32 loop_sample_count;

    loop_start_position = fn_800415AC(decoder);
    loop_start_offset = fn_80041578(decoder);
    loop_end_position = fn_80041554(decoder);
    if (handle->stream == 0 && handle->stream_loop_enabled == 0) {
        fn_800416DC(handle->decoder, -1);
        return;
    }
    input->interface->get_chunk(input, 1, handle->link_data_length, &chunk);
    if (chunk.len < handle->link_data_length) {
        fn_800474E4(lbl_80091104);
    }
    input->interface->put_chunk(input, 0, &chunk);
    fn_800416D4(decoder, 0);
    loop_sample_count = loop_end_position - loop_start_position;
    handle->loop_sample_count = loop_sample_count;
    fn_800416DC(decoder, loop_sample_count);
    fn_800416CC(decoder, loop_start_offset);
    fn_800416F0(decoder, loop_start_position);
    if (handle->stream_type == ADXT_STREAM_TYPE_MEMORY) {
        input->interface->reset(input);
        input->interface->get_chunk(input, 1, loop_start_offset, &chunk);
        input->interface->put_chunk(input, 0, &chunk);
    }
    fn_80041410(decoder);
    handle->loop_count++;
}

void fn_8004DFF0(void *object) {
    ADXTHandle *p = (ADXTHandle *)object;
    void *obj;
    u32 value_1;
    u32 value_2;
    u32 value_3;
    u32 diff;

    obj = p->decoder;
    value_1 = fn_800415AC(obj);
    value_2 = fn_80041578(obj);
    value_3 = fn_80041554(obj);
    fn_80041434(obj);
    fn_800416D4(obj, 0);
    diff = value_3 - value_1;
    p->loop_sample_count = diff;
    fn_800416DC(obj, diff);
    fn_800416CC(obj, value_2);
    fn_800416F0(obj, value_1);
    fn_800416E4(obj, fn_8004DE70, p);
}
