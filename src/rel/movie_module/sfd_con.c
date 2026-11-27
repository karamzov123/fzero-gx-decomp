#include "types.h"

/* fzgx:begin fn_12_22FBC noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_22FBC.c --- */
typedef struct MovieState {
    u8 pad_0[0x1a8];
    s32 value_1a8;
    u8 pad_1ac[4];
    s32 count_1b0;
    s32 index_1b4;
    s32 entries_1b8[1];
} MovieState;

typedef struct MovieModule {
    u8 pad_cc0[0xcc0];
    MovieState state;
} MovieModule;

extern void fn_12_24970(void *arg);
extern void fn_12_24950(void *arg);

s32 fn_12_22FBC(MovieModule *module, s32 *out_entry, s32 *out_value) {
    u8 local[8];
    MovieState *state = &module->state;
    s32 result;

    fn_12_24970(local);
    if (state->count_1b0 - state->index_1b4 <= 0) {
        result = 0;
        *out_entry = -1;
    } else {
        result = 1;
        *out_value = state->value_1a8;
        *out_entry = state->entries_1b8[state->index_1b4 % 32];
        state->index_1b4++;
    }
    fn_12_24950(local);
    return result;
}
/* fzgx:end fn_12_22FBC */

/* fzgx:begin fn_12_23078 noprologue */

/* --- rel/movie_module/fn_12_23078.c --- */
typedef struct MovieState_u1 {
    u8 unk_000[0x1a8];
    int pending;
    u8 unk_1ac[4];
    s32 head;
    s32 tail;
    void *entries[0x20];
} MovieState_u1;

typedef struct MovieModule_u1 {
    u8 unk_000[0xcc0];
    MovieState_u1 state;
} MovieModule_u1;

int fn_12_23078(MovieModule_u1 *module, void *entry, int value) {
    u8 local[8];
    MovieState_u1 *state = &module->state;
    int pending = value;

    fn_12_24970(local);
    if (state->head - state->tail >= 0x20) {
        pending = 0;
    } else {
        state->pending = pending;
        state->entries[state->head % 0x20] = entry;
        pending = 1;
        state->head++;
    }
    fn_12_24950(local);
    return pending;
}
/* fzgx:end fn_12_23078 */

/* fzgx:begin fn_12_23120 noprologue */

/* --- rel/movie_module/fn_12_23120.c --- */
/* --- rel/movie_module/fn_12_23120.c --- */

typedef struct MovieModuleState {
    u8 pad_000[0x120];
    int field_120;
    int field_124;
    int field_128[32];
} MovieModuleState;

void fn_12_23120(void *arg0, int arg1) {
    MovieModuleState *state = (MovieModuleState *)((u8 *)arg0 + 0xcc0);
    int local;
    int next;
    int total;

    fn_12_24970(&local);
    state->field_120 += arg1;
    next = state->field_124;
    next = next + 1;
    total = state->field_120;
    state->field_128[next % 32] = total;
    state->field_124 = next;
    fn_12_24950(&local);
}
/* fzgx:end fn_12_23120 */

/* fzgx:begin fn_12_231A0 noprologue */

/* --- rel/movie_module/fn_12_231A0.c --- */
extern u32 fn_12_2D73C(u32, u32);

s32 fn_12_231A0(u32 arg0) {
    u32 v0;
    if ((s32)fn_12_2D73C(arg0, 49) != 0 || (s32)fn_12_2D73C(arg0, 57) != 0) {
    v0 = 1;
    } else {
    v0 = 0;
    }
    return v0;
}
/* fzgx:end fn_12_231A0 */

/* fzgx:begin fn_12_231F8 noprologue */

/* --- rel/movie_module/fn_12_231F8.c --- */
s32 fn_12_231F8(u32 arg0) {
    u32 v0;
    if ((s32)fn_12_2D73C(arg0, 49) != 0 || (s32)fn_12_2D73C(arg0, 56) != 0) {
    v0 = 1;
    } else {
    v0 = 0;
    }
    return v0;
}
/* fzgx:end fn_12_231F8 */

/* fzgx:begin fn_12_23250 noprologue */

/* --- rel/movie_module/fn_12_23250.c --- */
u32 fn_12_23250(u32 arg0) {
    u32 t0;
    t0 = fn_12_2D73C(arg0, 49);
    return ((u32)((-t0) | t0) >> 31);
}
/* fzgx:end fn_12_23250 */

/* fzgx:begin fn_12_23280 noprologue */

/* --- rel/movie_module/fn_12_23280.c --- */
extern int fn_12_24990(void);
extern int fn_12_24A88(int arg0, int arg1);
extern void fn_12_2D7DC(void *arg0, int arg1, int arg2);

int fn_12_23280(void *arg0) {
    if (fn_12_24990()) {
        return fn_12_24A88(0, 0xff000161);
    }
    fn_12_2D7DC(arg0, 0x31, 1);
    return 0;
}
/* fzgx:end fn_12_23280 */

/* fzgx:begin fn_12_232DC noprologue */

/* --- rel/movie_module/fn_12_232DC.c --- */
extern u8 *fn_12_A0D8(u8 *data, int size, int mode);
extern u8 lbl_12_rodata_AB8[36];
extern u8 lbl_12_rodata_BD8[56];

typedef struct MovieInfo {
    u8 unk_000[8];
    u8 *field_008;
    u8 unk_00c[8];
    u32 field_014;
    u32 field_018;
    s32 field_01c;
    u32 field_020;
    u32 field_024;
} MovieInfo;

int fn_12_232DC(u8 *data, int size, MovieInfo *info) {
    u8 *entry;
    u8 b4;
    u8 b7;
    u8 b5;
    u8 b6;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 b11;
    u8 raw[12];

    while (size > 0) {
        entry = fn_12_A0D8(data, size, 0x40);
        if (entry == NULL) {
            return 0;
        }
        b7 = entry[7];
{
    int offset;
        offset = entry - data;
        data = (u8 *)(offset + (u32)data);
        b4 = entry[4];
        b6 = entry[6];
        offset++;
        b5 = entry[5];
        b8 = entry[8];
        data++;
        b9 = entry[9];
        size -= offset;
}
        b10 = entry[10];
        b11 = entry[11];
        if (((0) == ((b7 >> 4)))) {
            continue;
        }
        b7 &= 0xf;
        if (b7 < 1 || b7 > 8) {
            continue;
        }
        if (((b10 >> 5) & 1) == 0) {
            continue;
        }
        info->field_014 = (b4 << 4) | (b5 >> 4);
        info->field_018 = ((b5 & 0xf) << 8) | b6;
        if (info->field_01c == 0) {
            info->field_01c = (((u32)b10 >> 6) | ((b8 << 10) | (b9 << 2))) * 50;
        }
        info->field_020 = *(u32 *)(lbl_12_rodata_AB8 + b7 * 4);
        info->field_024 = (((u32)b10 & 0x1f) << 5 | (b11 >> 3)) << 11;
        info->field_008 = lbl_12_rodata_BD8;
        break;
    }
    return 1;
}
/* fzgx:end fn_12_232DC */

/* fzgx:begin fn_12_23410 noprologue */
#include "types.h"

extern u8 lbl_12_bss_7250[2048];
extern u8 lbl_12_rodata_A18[56];
extern void * memcpy(void *, const void *, u32);

typedef struct MovieState {
    u8 unk_00[0x0c];
    u8 *unk_0c;
    u8 unk_10[0x18];
    u8 unk_28;
    u8 unk_29[3];
    u32 unk_2c;
} MovieState;

struct Sig_fn_12_215F4_Arg2 {
    u32 unk_0;
};

extern s32 fn_12_215F4(u32, u32, struct Sig_fn_12_215F4_Arg2 *);

static inline int find_entry(u8 *data, s32 size, MovieState *st) {
    s32 n;
    u8 *p;
    struct Sig_fn_12_215F4_Arg2 arg;

    n = (size < 0x800) ? size : 0x800;
    memcpy(lbl_12_bss_7250, data, (u32)n);
    p = lbl_12_bss_7250;
    while (n > 0) {
        if (fn_12_215F4((u32)p, (u32)n, &arg)) {
            st->unk_0c = lbl_12_rodata_A18;
            st->unk_28 = p[7];
            st->unk_2c = (p[8] << 24) | (p[9] << 16) | (p[10] << 8) | p[11];
            return 1;
        }
        p += 4;
        n -= 4;
    }
    return 0;
}

int fn_12_23410(u8 *data, s32 size, MovieState *st) {
    if (find_entry(data, size, st)) {
        return 1;
    }
    if (find_entry(data + 2, size - 2, st)) {
        return 1;
    }
    if (find_entry(data + 1, size - 1, st)) {
        return 1;
    }
    if (find_entry(data + 3, size - 3, st)) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_12_23410 */

/* fzgx:begin fn_12_23700 noprologue */
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
/* fzgx:end fn_12_23700 */

/* fzgx:begin fn_12_2396C noprologue */
#include "types.h"
typedef struct Sig_fn_12_6B28_MpsHandle Sig_fn_12_6B28_MpsHandle;
typedef struct Sig_fn_12_2396C_MovieState {
    u8 unk_00;
    u8 unk_01;
    s32 unk_04;
    void *unk_08;
    void *unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u8 unk_28;
    s32 unk_2c;
    u8 pad_30[0x10];
} Sig_fn_12_2396C_MovieState;
typedef struct Sig_fn_12_654C_MovieValues {
    s32 value_00;
    s32 value_04;
    s32 value_08;
    s32 value_0c;
    s32 value_10;
    s32 value_14;
    s32 value_18;
    s32 value_1c;
} Sig_fn_12_654C_MovieValues;
typedef struct Sig_fn_12_654C_MovieModule {
    u8 pad00[0x10]; int field10; u8 field14[0x0c];
    Sig_fn_12_654C_MovieValues values;
    Sig_fn_12_654C_MovieValues slots[3]; u8 fielda0[0x20];
} Sig_fn_12_654C_MovieModule;
typedef struct Sig_fn_12_6A18_MovieValues { u32 value_14, value_18, value_1c; } Sig_fn_12_6A18_MovieValues;
typedef struct Sig_fn_12_6A18_MovieModule { u8 pad[0x14]; Sig_fn_12_6A18_MovieValues values; } Sig_fn_12_6A18_MovieModule;
typedef struct Sig_fn_12_6A90_MovieModule { s32 state; } Sig_fn_12_6A90_MovieModule;
extern Sig_fn_12_6B28_MpsHandle *fn_12_6B28(void);
extern int fn_12_654C(Sig_fn_12_654C_MovieModule *, const u8 *, int, int *, int *);
extern int fn_12_6A18(Sig_fn_12_6A18_MovieModule *, Sig_fn_12_6A18_MovieValues *);
extern s32 fn_12_6A90(Sig_fn_12_6A90_MovieModule *);
extern int fn_12_24760(u8 *, int);
extern u32 fn_12_67A4(const u8 *);
extern u8 lbl_12_rodata_B90[56];
extern u32 lbl_12_bss_69BC[549];
extern void fn_12_57F0();
extern void fn_12_24570(void *);
extern int fn_12_23700(u8 *, int, Sig_fn_12_2396C_MovieState *);
extern int fn_12_232DC(u8 *, int, Sig_fn_12_2396C_MovieState *);

static inline u8 *find_start(u8 *p, int size) {
    while (size >= 4) {
        if (fn_12_67A4(p) == 0x10000) return p;
        p++;
        size--;
    }
    return 0;
}

static inline void probe_buffer(u8 *data, int length, Sig_fn_12_2396C_MovieState *state) {
    u32 *buffer;
    int copy_size;
    int size;
    u8 *cursor;
    int step;
    int tries;
    state->unk_04 = (s32)lbl_12_rodata_B90;
    size = length;
    cursor = data;
    tries = 0;
    step = state->unk_10;
    for (;;) {
        if (fn_12_24760(cursor, size) != 0) goto found; /* Keep the verified branch to found. */
        cursor += step;
        size -= step;
        if (tries >= 3 || size <= 0) return;
        tries++;
    }
found:
    buffer = (u32 *)&lbl_12_bss_69BC;
    copy_size = 0x800;
    if (size < 0x800) copy_size = size;
    fn_12_57F0((u8 *)buffer + 0x94, cursor, copy_size);
    buffer[0x90 / 4] = copy_size;
    fn_12_24570(buffer);
    if ((s32)buffer[0] != 0 && (s32)buffer[3] > 0) state->unk_1c = (*((3) + (buffer)));
}
static inline int detect_stride(u8 *data, int length, int *duration) {
    u8 * first = find_start(data, length);
    struct { int value; } offset;
    struct { int value; } remaining;
    u8 *second;
    u8 *third;
    int stride;
    Sig_fn_12_6B28_MpsHandle *handle;
    Sig_fn_12_6A18_MovieValues loc_10;
    int loc_8;
    int loc_C;
    if (first == 0) return 0;
    offset.value = first - data;
    remaining.value = length - offset.value;
    second = find_start(first + 1, remaining.value - 1);
    if (second == 0) return 0;
    third = find_start(second + 1, length - (second - data) - 1);
    if (third == 0) return 0;
    stride = second - first;
    if (stride != third - second) return -1;
    if (offset.value % stride != 0) return -1;
    third = (u8 *)fn_12_6B28();
    handle = (Sig_fn_12_6B28_MpsHandle *)third;
    if (handle != 0) {
        fn_12_654C((Sig_fn_12_654C_MovieModule *)handle, first, remaining.value, &loc_8, &loc_C);
        if (loc_C & 0x10000) {
            fn_12_6A18((Sig_fn_12_6A18_MovieModule *)handle, &loc_10);
            fn_12_6A90((Sig_fn_12_6A90_MovieModule *)handle);
            *duration = loc_10.value_1c;
        }
    }
    return stride;
}
#pragma opt_common_subs off
#pragma opt_propagation off
int fn_12_2396C(u8 *arg0, s32 arg1, Sig_fn_12_2396C_MovieState *arg2) {
    int stride;
    int duration;
    duration = 0;
    stride = detect_stride(arg0, arg1, &duration);
    if (stride == 0) return 0;
    arg2->unk_10 = stride;
    if (stride == -1) return 1;
    if (duration != -1 && duration > 0) arg2->unk_1c = duration * 50;
    probe_buffer(arg0, arg1, arg2);
    fn_12_23700(arg0, arg1, arg2);
    fn_12_232DC(arg0, arg1, arg2);
    return 1;
}

#pragma opt_propagation reset

#pragma opt_common_subs reset


/* fzgx:end fn_12_2396C */

/* fzgx:begin fn_12_23BFC noprologue */
#include "types.h"

typedef struct MovieState {
    u8 unk_00;
    u8 unk_01;
    s32 unk_04;
    void *unk_08;
    void *unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u8 unk_28;
    s32 unk_2c;
    u8 pad_30[0x10];
} MovieState;

typedef struct FrameHeader {
    u8 layer;
    u8 prot;
    u8 bitrate;
    u8 rate;
    u8 padding;
    u8 priv;
    u8 mode;
    u8 modeExt;
    u8 copyright;
    u8 original;
    u8 emphasis;
} FrameHeader;

extern void *memset(void *, int, u32);
extern s32 fn_12_2396C(u8 *data, s32 size, MovieState *movie);
extern s32 fn_12_232DC(u8 *data, s32 size, MovieState *movie);
extern s32 fn_12_23410(u8 *data, s32 size, MovieState *movie);
extern const s32 lbl_12_rodata_ADC[4];
extern const s32 lbl_12_rodata_AEC[5];
extern FrameHeader lbl_12_bss_69B0;


static inline u8 *findHeader(u8 *p, s32 size, FrameHeader *h) {
    for (; size >= 4; size--, p++) {
        if (p[0] != 0xff) {
            continue;
        }
        if ((p[1] & 0xf8) != 0xf8) {
            continue;
        }
        h->layer = (u32)(p[1] >> 1) & 3;
        h->prot = p[1] & 1;
        h->bitrate = ((u32)p[2] >> 4) & 0xf;
        h->rate = ((u32)p[2] >> 2) & 3;
        h->padding = ((u32)p[2] >> 1) & 1;
        h->priv = p[2] & 1;
        h->mode = ((u32)p[3] >> 6) & 3;
        h->modeExt = ((u32)p[3] >> 4) & 3;
        h->copyright = ((u32)p[3] >> 3) & 1;
        h->original = ((u32)p[3] >> 2) & 1;
        h->emphasis = p[3] & 3;
        if (h->layer == 0) {
            continue;
        }
        if (h->bitrate == 0xf) {
            continue;
        }
        if (h->rate == 3) {
            continue;
        }
        return p;
    }
    return 0;
}

static inline s32 detectAudio(u8 *data, s32 size, MovieState *movie) {
    FrameHeader h;

    data = findHeader(data, size, &h);
    if (data != 0) {
        if (h.layer == 2 && h.bitrate != 0 && h.rate == 0) {
            movie->unk_28 = lbl_12_rodata_ADC[h.mode];
            movie->unk_2c = lbl_12_rodata_AEC[h.rate];
        }
        lbl_12_bss_69B0 = h;
        return 1;
    }
    return 0;
}

void fn_12_23BFC(u8 *data, s32 size, MovieState *movie) {
    memset(movie, 0, 0x40);
    movie->unk_00 = 0;
    movie->unk_01 = 0;
    movie->unk_04 = 0;
    movie->unk_08 = 0;
    movie->unk_0c = 0;
    movie->unk_10 = 0;
    movie->unk_14 = 0;
    movie->unk_18 = 0;
    movie->unk_1c = 0;
    movie->unk_20 = 0;
    movie->unk_24 = 0;
    movie->unk_28 = 0;
    movie->unk_2c = 0;
    if (fn_12_2396C(data, size, movie)) {
        return;
    }
    if (fn_12_232DC(data, size, movie)) {
        return;
    }
    if (fn_12_23410(data, size, movie)) {
        return;
    }
    if (detectAudio(data, size, movie)) {
        return;
    }
}
/* fzgx:end fn_12_23BFC */

/* fzgx:begin fn_12_23E0C noprologue */
#include "types.h"

typedef struct MovieState {
    u8 unk_00;
    u8 unk_01;
    u8 pad_02[0x06];
    void *unk_08;
    void *unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} MovieState;

extern void fn_12_24970(void *state);
extern void fn_12_23BFC(void *arg0, void *arg1, MovieState *movie);
extern u8 lbl_12_rodata_BD8[56];
extern void fn_12_24950(void *state);

void fn_12_23E0C(void *arg0, void *arg1, MovieState *movie) {
    u8 state[8];

    fn_12_24970(state);
    fn_12_23BFC(arg0, arg1, movie);
    if (movie->unk_08 != 0 || movie->unk_0c != 0 || movie->unk_10 == -1) {
        movie->unk_00 = 1;
    }
    if (movie->unk_08 == lbl_12_rodata_BD8) {
        s32 width;
        s32 height;

        width = (movie->unk_14 + 15) / 16;
        height = (movie->unk_18 + 15) / 16;
        if (width * height > 0x654) {
            movie->unk_08 = 0;
        }
    }
    if (movie->unk_08 != 0 || movie->unk_0c != 0) {
        movie->unk_01 = 1;
    }
    fn_12_24950(state);
}
/* fzgx:end fn_12_23E0C */
