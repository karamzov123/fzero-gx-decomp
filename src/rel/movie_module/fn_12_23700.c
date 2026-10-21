#include "types.h"
typedef struct MpsHandle MpsHandle;
typedef struct MovieState {
    u8 unk_00; u8 unk_01; u8 pad_02[2];
    u32 unk_04; void *unk_08; void *unk_0c;
    s32 unk_10; s32 unk_14; s32 unk_18;
    u32 unk_1c; u32 unk_20; u32 unk_24;
    u8 unk_28; u8 pad_29[3]; u32 unk_2c; u8 pad_30[16];
} MovieState;
typedef struct AudioHeader {
    u8 layer, protection, bitrate, frequency, padding, private_bit;
    u8 mode, mode_extension, copyright_bit, original, emphasis;
} AudioHeader;
extern u32 fn_12_67A4(const u8 *);
extern MpsHandle *fn_12_6B28(void);
extern int fn_12_6A90(MpsHandle *);
extern int fn_12_654C(MpsHandle *, const u8 *, int, int *, int *);
extern s32 fn_12_23410(u8 *, s32, MovieState *);
extern const u8 lbl_12_rodata_ADC[16];
extern const u8 lbl_12_rodata_AEC[20];
extern u8 lbl_12_bss_69B0[12];

static inline u8 *find_packet(u8 *p, s32 n) {
    while (n >= 4) {
        if (fn_12_67A4(p) == 0x40000) return p;
        p++; n--;
    }
    return 0;
}
static inline u8 *find_audio(u8 *p, s32 n, AudioHeader *h) {
    while (n >= 4) {
        if (p[0] == 0xff && (p[1] & 0xf8) == 0xf8) {
            h->layer = (p[1] >> 1) & 3;
            h->protection = p[1] & 1;
            h->bitrate = (p[2] >> 4) & 15;
            h->frequency = (p[2] >> 2) & 3;
            h->padding = (p[2] >> 1) & 1;
            h->private_bit = p[2] & 1;
            h->mode = (p[3] >> 6) & 3;
            h->mode_extension = (p[3] >> 4) & 3;
            h->copyright_bit = (p[3] >> 3) & 1;
            h->original = (p[3] >> 2) & 1;
            h->emphasis = p[3] & 3;
            if (h->layer != 0 && h->bitrate != 15 && h->frequency != 3) return p;
        }
        p++; n--;
    }
    return 0;
}
static inline u8 *prepare_packet(u8 *packet, u8 *end) {
    MpsHandle *decoder;
    u8 *audio;
    int used, unused;
    decoder = fn_12_6B28();
    if (!decoder) {
        s32 remain = end - packet;
        audio = packet + (remain > 6 ? 6 : remain);
    } else {
        fn_12_654C(decoder, packet, end - packet, &used, &unused);
        fn_12_6A90(decoder);
        audio = packet + used;
    }
    return audio;
}
static inline int inspect_audio(u8 *audio, s32 amount, MovieState *state) {
    AudioHeader header;
    audio = find_audio(audio, amount, &header);
    if (audio) {
        if (header.layer == 2 && header.bitrate != 0 && header.frequency == 0) {
            state->unk_28 = ((const s32 *)lbl_12_rodata_ADC)[header.mode];
            state->unk_2c = ((const s32 *)lbl_12_rodata_AEC)[header.frequency];
        }
        *(AudioHeader *)lbl_12_bss_69B0 = header;
        return 1;
    }
    return 0;
}
static inline s32 minimum(s32 a, s32 b) { return a < b ? a : b; }
void fn_12_23700(u8 *data, s32 size, MovieState *state) {
    u8 *end = data + size;
    s32 max = state->unk_10;
    u8 *packet;
    int unused, used;
    AudioHeader header;
    while (size > 0) {
        packet = find_packet(data, size);
        if (!packet) break;
        if (packet[3] >= 0xc0 && packet[3] <= 0xdf) {
            u8 *audio = prepare_packet(packet, end);
            s32 amount = minimum(end - audio, max);
            if (fn_12_23410(audio, amount, state) != 0) break;
            if (inspect_audio(audio, amount, state)) break;
        }
        {
            s32 skipped = packet - data;
            data = (u8 *)(skipped + (u32)data);
            size -= skipped + 1;
            data++;
        }
    }
}
