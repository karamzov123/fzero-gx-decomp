#include "types.h"

/* fzgx:begin fn_12_24E94 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_24E94.c --- */
typedef struct MovieModule MovieModule;
typedef struct MovieState MovieState;

struct MovieModule {
    u8 pad_0000[0x1aec];
    MovieState *state;
};

struct MovieState {
    u8 pad_0000[0x14];
    u32 value;
};

u32 fn_12_24E94(MovieModule *module) {
    return module->state->value;
}
/* fzgx:end fn_12_24E94 */

/* fzgx:begin fn_12_24EA0 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_24EA0.c --- */
typedef struct MovieModule MovieModule;
typedef struct MovieState MovieState;
typedef struct MovieEntry MovieEntry;
typedef struct MovieData MovieData;

struct MovieState {
    u32 base;
    u8 pad_0004[0x08];
    u32 field_000c;
    u8 pad_0010[0x04];
    s32 value;
    u8 pad_0018[0x08];
    u32 field_0020;
    u32 field_0024;
};

struct MovieData {
    u8 pad_0000[0x160];
    void *arg_0160;
    void *arg_0164;
};

struct MovieEntry {
    s32 valid;
    u8 pad_0004[0x10];
    u32 field_0014;
    u32 field_0018;
    u32 field_001c;
    u32 field_0020;
    MovieData data;
};

struct MovieModule {
    u8 pad_0000[0xdd4];
    u32 field_0dd4;
    u8 pad_0dd8[0xd14];
    MovieState *state;
    u8 pad_0x1af0[0xe18];
    MovieEntry *entry;
};

extern void fn_12_245C4(MovieModule *module);
extern s32 fn_12_654C(void *arg0, MovieData *arg1, void *arg2, u32 *arg3, u32 *arg4);
extern s32 fn_12_24A88(MovieModule *module, u32 code);

s32 fn_12_24EA0(MovieModule *module) {
    MovieEntry *movie;
    MovieData *data;
    void *base;
    MovieState *state;
    s32 first;
    s32 second;
    s32 result;
    u32 local_c;
    u32 local_8;

    movie = module->entry;
    if (movie == 0) {
        movie = 0;
    } else {
        state = module->state;
        if (state->value > 0) {
            movie = 0;
        } else {
            movie = (MovieEntry *)((u8 *)movie + 0x8a0);
        }
    }
    if (movie == 0) {
        return 0;
    }
    if (movie->valid == 0) {
        return 0;
    }

    state = module->state;
    fn_12_245C4(module);
    base = (void *)state->base;
    data = (MovieData *)((u8 *)movie + 0x24);
    first = fn_12_654C(base, data, data->arg_0160, &local_c, &local_8);
    second = fn_12_654C(base, (MovieData *)((u8 *)data + 0xb0),
                        data->arg_0164, &local_c, &local_8);
    if (first != 0 || second != 0) {
        result = fn_12_24A88(module, 0xff000d0d);
    } else {
        result = 0;
    }
    if (result != 0) {
        return result;
    }
    state->field_0020 = movie->field_001c;
    state->field_0024 = movie->field_0020;
    module->field_0dd4 = movie->field_0014;
    state->field_000c = movie->field_0018;
    return 0;
}
/* fzgx:end fn_12_24EA0 */

/* fzgx:begin fn_12_24FBC noprologue */

/* --- rel/movie_module/fn_12_24FBC.c --- */
/* --- rel/movie_module/fn_12_24FBC.c --- */
/* --- rel/movie_module/fn_12_24FBC.c --- */

void fn_12_24FBC(void *arg0) {
    fn_12_24A88(arg0, 0xff000d0b);
}
/* fzgx:end fn_12_24FBC */

/* fzgx:begin fn_12_24FE4 noprologue */

/* --- rel/movie_module/fn_12_24FE4.c --- */
void fn_12_24FE4(void *arg0) {
    fn_12_24A88(arg0, (int)0xff000d0b);
}
/* fzgx:end fn_12_24FE4 */

/* fzgx:begin fn_12_2500C noprologue */

/* --- rel/movie_module/fn_12_2500C.c --- */
void fn_12_2500C(void *arg0) {
    fn_12_24A88(arg0, (int)0xff000d0b);
}
/* fzgx:end fn_12_2500C */

/* fzgx:begin fn_12_25034 noprologue */

/* --- rel/movie_module/fn_12_25034.c --- */
/* --- rel/movie_module/fn_12_25034.c --- */

void fn_12_25034(void *arg0) {
    fn_12_24A88(arg0, 0xFF000D0B);
}
/* fzgx:end fn_12_25034 */

/* fzgx:begin fn_12_2505C noprologue */

/* --- rel/movie_module/fn_12_2505C.c --- */
// fn_12_2505C: returns a constant.
int fn_12_2505C(void) {
    return 0;
}
/* fzgx:end fn_12_2505C */

/* fzgx:begin fn_12_25064 noprologue */

/* --- rel/movie_module/fn_12_25064.c --- */
// fn_12_25064: returns a constant.
int fn_12_25064(void) {
    return 0;
}
/* fzgx:end fn_12_25064 */

/* fzgx:begin fn_12_2506C noprologue */

/* --- rel/movie_module/fn_12_2506C.c --- */
// fn_12_2506C: returns a constant.
int fn_12_2506C(void) {
    return 0;
}
/* fzgx:end fn_12_2506C */

/* fzgx:begin fn_12_25074 noprologue */

/* --- rel/movie_module/fn_12_25074.c --- */
// fn_12_25074: returns a constant.
int fn_12_25074(void) {
    return 0;
}
/* fzgx:end fn_12_25074 */

/* fzgx:begin fn_12_2507C noprologue */
#include "types.h"

extern u32 fn_12_24A88(u32, u32);
extern u32 fn_12_6A90(u32);

struct fn_12_2507C_Arg0 {
    u8 pad_0[0x1AEC];
    u32 unk_1AEC;
};

s32 fn_12_2507C(struct fn_12_2507C_Arg0 *arg0) {
    u32 v0;
    u32 t0, t1;
    t0 = fn_12_6A90(*(u32 *)((u8 *)arg0->unk_1AEC + 0));
    v0 = t0;
    if ((s32)t0 != 0) {
    v0 = (u32)arg0;
    t1 = fn_12_24A88(v0, (0xFF000000 + 3338));
    v0 = t1;
    } else {
    v0 = 0;
    }
    return v0;
}
/* fzgx:end fn_12_2507C */

/* fzgx:begin fn_12_250D0 noprologue */
#include "types.h"

extern void fn_12_24A88(void);

void fn_12_250D0(void) {
    fn_12_24A88();
}
/* fzgx:end fn_12_250D0 */

/* fzgx:begin fn_12_250F0 noprologue */
#include "types.h"
#pragma inline_max_size(10000)
#pragma inline_max_total_size(10000)

/* --- rel/movie_module/fn_12_250F0.c --- */
typedef struct MpsHandle MpsHandle;

typedef struct SfmpsWork {
    MpsHandle *decoder;
    s32 max_video_bound;
    s32 max_audio_bound;
    s32 video_pts_baseline;
    s32 audio_pts_baseline;
    s32 concat_count;
    s32 previous_video_stream;
    s32 previous_audio_stream;
    s32 first_video_stream;
    s32 first_audio_stream;
    s32 selected_video_id;
    s32 selected_audio_id;
    s32 delimiter_state;
    void *element_outputs[0x44];
    void *element_callback;
    void *element_callback_argument;
} SfmpsWork;

typedef struct SfdHandle {
    u8 pad_0000[0x1AEC];
    SfmpsWork *work;
    u8 pad_1AF0[0x214];
    SfmpsWork mps_work_storage;
} SfdHandle;

typedef void (*MpsErrorCallback)(void *object, s32 error);

extern MpsHandle *fn_12_6B28(void);
extern int fn_12_6A90(MpsHandle *handle);
extern int fn_12_6CA8(MpsHandle *handle, MpsErrorCallback callback, void *object);
extern int fn_12_24A88(SfdHandle *handle, s32 error);
extern void fn_12_250D0(void *object, s32 error);

s32 fn_12_250F0(SfdHandle *handle) {
    SfmpsWork *work;
    MpsHandle *decoder;
    struct { int value; } i;

    work = &handle->mps_work_storage;
    handle->work = work;
    work->decoder = 0;
    work->max_video_bound = 0;
    work->max_audio_bound = 0;
    work->video_pts_baseline = 0x7FFFFFFF;
    work->audio_pts_baseline = 0x7FFFFFFF;
    work->concat_count = 0;
    work->previous_video_stream = 0x7FFFFFFF;
    work->previous_audio_stream = 0x7FFFFFFF;
    work->first_video_stream = -1;
    work->first_audio_stream = -1;
    work->selected_video_id = -1;
    work->selected_audio_id = -1;
    work->delimiter_state = 0;
    for (i.value = 0; i.value < 0x44; i.value++) {
        work->element_outputs[i.value] = 0;
    }
    work->element_callback = 0;
    work->element_callback_argument = 0;
    decoder = fn_12_6B28();
    if (decoder == 0) {
        return fn_12_24A88(handle, 0xFF000D08);
    }
    if (fn_12_6CA8(decoder, fn_12_250D0, handle) != 0) {
        fn_12_6A90(decoder);
        return fn_12_24A88(handle, 0xFF000D09);
    }
    work->decoder = decoder;
    return 0;
}
/* fzgx:end fn_12_250F0 */

/* fzgx:begin fn_12_252A0 noprologue */

/* --- rel/movie_module/fn_12_252A0.c --- */
/* --- rel/movie_module/fn_12_252A0.c --- */
struct Sig_fn_12_252A0_Movie {
    u8 pad0[0x48];
    int state;
    u8 pad4C[0x1AF4-0x4C];
    int stream;
    int field1AF8;
    int field1AFC;
    int field1B00;
};
typedef struct Sig_fn_12_696C_MovieValues {
    u32 value_00, value_04, value_08, value_0c;
    u32 value_10, value_14, value_18, value_1c;
} Sig_fn_12_696C_MovieValues;
typedef struct Sig_fn_12_696C_MovieModule {
    u8 _pad00[0x40];
    Sig_fn_12_696C_MovieValues values[1];
} Sig_fn_12_696C_MovieModule;
typedef struct Sig_fn_12_6A18_MovieValues {
    u32 value_14, value_18, value_1c;
} Sig_fn_12_6A18_MovieValues;
struct fn_12_252A0_arg0_1138_E116 {
    u8 pad_0[0x24];
    u32 unk_24;
    u8 pad_28[0x4C];
};
struct fn_12_252A0_Arg0 {
    u8 pad_0[0x1138];
    struct fn_12_252A0_arg0_1138_E116 unk_1138[1];
};
extern int fn_12_21D50(void *, int);
extern int fn_12_21E94(void *, int);
extern int fn_12_696C(Sig_fn_12_696C_MovieModule *, Sig_fn_12_696C_MovieValues *, int);
extern int fn_12_6A18(void *, Sig_fn_12_6A18_MovieValues *);
extern s32 fn_12_2D73C(void *, int);
extern s32 fn_12_2F1F0(void *, u32);
extern void fn_12_21D60(void *, int, int);
extern void fn_12_2D7DC(void *, int, int);
#define FIELD(p,n) (*(s32 *)((u8 *)(p)+(n)))
#define WORK(p) (*(s32 **)((u8 *)(p)+0x1aec))
static inline void update(struct fn_12_252A0_Arg0 *arg0, s32 zero) {
    s32 v5;
    s32 *v9;
    void *v10;
    s32 *v11;
    s32 *v0;
    void *decoder;
    u32 v1;
    s32 v3;
    s32 v2;
    s32 v4;
    s32 v6;
    s32 *v13;
    s32 *v14;
    s32 *v17;
    int a,b,c;
    Sig_fn_12_696C_MovieValues loc_14;
    Sig_fn_12_696C_MovieValues loc_34;
    Sig_fn_12_6A18_MovieValues loc_8;
    v0 = WORK(arg0);
    v1 = zero;
    v3 = zero;
    v2 = zero;
    decoder = (void *)v0[0];
    do {
        fn_12_696C(decoder, &loc_34, v2);
        { s32 t = loc_34.value_08;
          if ((s32)v1 > t) t = v1;
          v1 = t;
        }
        v4 = loc_34.value_0c;
        if (v3 > v4) v4 = v3;
        v2++;
        v3 = v4;
    } while (v2 < 3);
    v0[2] = v1;
    v0[1] = v4;
    a = fn_12_21D50(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1AFC);
    b = fn_12_21D50(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1AF8);
    c = fn_12_21D50(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1B00);
    if ((c | (a | b)) != 1 && fn_12_21D50(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->stream) == 1) {
        struct fn_12_252A0_Arg0 *entry = (struct fn_12_252A0_Arg0 *)((u8 *)arg0 + ((struct Sig_fn_12_252A0_Movie *)arg0)->stream * 0x74);
        v5 = FIELD(arg0,0x9f8);
        v6 = FIELD(arg0,8);
        if (v6 <= 0) v6 = entry->unk_1138[0].unk_24;
        if (v6 <= 0) v6 = v5;
        if (v6 < v5) v5 = v6;
        if (fn_12_21E94(arg0,0) >= v5) {
            fn_12_21D60(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1AFC,1);
            fn_12_21D60(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1AF8,1);
            fn_12_21D60(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1B00,1);
        }
    }
    v9 = WORK(arg0);
    v10 = (void *)v9[0];
    fn_12_6A18(v10,&loc_8);
    if ((s32)loc_8.value_1c != -1 && (s32)loc_8.value_1c > 0) FIELD(arg0,0x924) = loc_8.value_1c;
    fn_12_696C(v10,&loc_14,1);
    if ((s32)loc_14.value_10 != -1) FIELD(arg0,0x928) = loc_14.value_10;
    if (FIELD(arg0,0x930) == -1) FIELD(arg0,0x930) = v9[2];
    if (FIELD(arg0,0x934) == -1) FIELD(arg0,0x934) = v9[1];
    v11 = WORK(arg0);
    if (fn_12_2D73C(arg0,6) == 1 && v11[2] == 0 && fn_12_2F1F0(arg0,6) != 0) fn_12_2D7DC(arg0,6,0);
    if (fn_12_2D73C(arg0,5) == 1 && v11[1] == 0 && fn_12_2F1F0(arg0,7) != 0) fn_12_2D7DC(arg0,5,0);
    v13 = *(s32 **)((u8 *)arg0+0x2908);
    if (v13 == 0) v14 = 0;
    else {
        if ((s32)WORK(arg0)[5] > 0) v14 = 0;
        else v14 = (s32 *)((u8 *)v13+0x8a0);
    }
    if (v14 != 0) {
        v17 = WORK(arg0);
        if (v17[4] != 0x7fffffff) {
            FIELD(arg0,0xdd8) = v17[4] - v14[6];
            if (v14[0] == 0) {
                v14[1] = FIELD(arg0,0x924)*50;
                v14[2] = FIELD(arg0,0x928);
                v14[3] = v17[1];
                v14[4] = v17[2];
                v14[5] = FIELD(arg0,0xdd4);
                v14[6] = v17[3];
                v14[7] = v17[8];
                v14[8] = v17[9];
            }
        }
    }
}
void fn_12_252A0(struct fn_12_252A0_Arg0 *arg0) {
    update(arg0, 0);
}
/* fzgx:end fn_12_252A0 */

/* fzgx:begin fn_12_2559C noprologue */

/* --- rel/movie_module/fn_12_2559C.c --- */
struct Sig_fn_12_21F28_MovieEntry {
    int value;
    char padding[0x70];
};
struct Sig_fn_12_21F28_MovieModule {
    char padding[0x1174];
    struct Sig_fn_12_21F28_MovieEntry entries[1];
};
struct Sig_fn_12_21D30_fn_12_21D30_E116_u32 { u32 unk_0; u8 pad_4[0x70]; };
struct Sig_fn_12_21D30_fn_12_21D30_Arg0 {
    u8 pad_0[0x114C];
    struct Sig_fn_12_21D30_fn_12_21D30_E116_u32 unk_114C[1];
};
struct fn_12_2559C_Arg0 {
    u8 pad_0[0x28];
    u32 unk_28;
    u8 pad_2C[0x1AC0];
    u32 unk_1AEC;
    u8 pad_1AF0[0x4];
    u32 unk_1AF4;
};
extern int fn_12_21F28(struct Sig_fn_12_21F28_MovieModule *, int);
extern s32 fn_12_231F8(u32);
extern u32 fn_12_21D30(struct Sig_fn_12_21D30_fn_12_21D30_Arg0 *, u32);
extern u32 fn_12_23250(u32);
extern u32 fn_12_67A4(const u8 *);
extern void fn_12_21D40(void *, int, int);
s32 fn_12_2559C(struct fn_12_2559C_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v2;
    u32 v0;
    u32 v1;
    s32 v4;
    u32 v3;
    u32 t0;
    int t1;
    u32 t7;
    v0 = arg0->unk_1AEC;
    v1 = arg0->unk_1AF4;
    v2 = arg0->unk_28;
    if ((s32)arg2 >= 4) {
        v3 = fn_12_67A4((const u8 *)arg1);
        if (v3 == 0x80000) {
            if ((s32)*(u32 *)((u8 *)arg0 + 6916) < 0) {
                t1 = fn_12_21F28((struct Sig_fn_12_21F28_MovieModule *)arg0, v1);
                *(u32 *)((u8 *)arg0 + 6916) = t1 + 4;
            }
            *(u32 *)((u8 *)v0 + 48) = 1;
        } else if ((s32)v3 != 0) {
            *(u32 *)((u8 *)v0 + 48) = 0;
        }
    } else {
        v3 = 0;
    }
    if (v3 != 0x80000) {
        v4 = 0;
    } else if ((s32)fn_12_23250((u32)arg0) != 0 || fn_12_231F8((u32)arg0) != 0) {
        v4 = 0;
    } else {
        v4 = 1;
    }
    if (v4 != 0) {
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6908), 1);
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6904), 1);
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6912), 1);
        return 0;
    }
    if ((s32)arg3 < 4 && (s32)fn_12_21D30((struct Sig_fn_12_21D30_fn_12_21D30_Arg0 *)arg0, v1) == 1) {
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6908), 1);
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6904), 1);
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6912), 1);
        return 0;
    }
    if ((s32)arg2 < (s32)v2) {
        if ((v3 - 0x10000) == 0) {
            v4 = 0;
        } else {
            v4 = 1;
            if ((v3 - 0x40000) == 0) {
                v4 = 1;
            }
            return v4;
        }
    } else {
        v4 = 1;
    }
done:
    return v4;
}
/* fzgx:end fn_12_2559C */

/* fzgx:begin fn_12_25740 noprologue */

/* --- rel/movie_module/fn_12_25740.c --- */
// fn_12_25740: returns a constant.
int fn_12_25740(void) {
    return 1;
}
/* fzgx:end fn_12_25740 */

/* fzgx:begin fn_12_25748 noprologue */

/* --- rel/movie_module/fn_12_25748.c --- */
typedef void *SfdCallbackObject;

typedef int SfdTransportValue;

typedef struct SfdHandle_u3 SfdHandle_u3;

typedef struct SJCK {
    union {
        unsigned char padding_extent[8];
        struct {
            unsigned char *data;
        } view_data;
        struct {
            unsigned char padding_len[4];
            long len;
        } view_len;
    } fields;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

struct SJInterface {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_get_chunk[24];
            void (*get_chunk)(SJ *sj, long channel, long max_size, SJCK *chunk);
        } view_get_chunk;
        struct {
            unsigned char padding_put_chunk[32];
            void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
        } view_put_chunk;
        struct {
            unsigned char padding_get_num_data[36];
            int (*get_num_data)(SJ *sj, int channel);
        } view_get_num_data;
    } fields;
};

struct SJ {
    union {
        unsigned char padding_extent[4];
        struct {
            const SJInterface *interface;
        } view_interface;
    } fields;
};

typedef struct SfdTransportInterface SfdTransportInterface;

typedef void (*SfdBufferHandleCallback)(SfdHandle_u3 *handle, int stream_index);

typedef void (*SfdBufferObjectCallback)(SfdCallbackObject object, int stream_index);

typedef struct SfdBufferChannel {
    union {
        unsigned char padding_extent[16];
        struct {
            SJ *stream_joint;
        } view_stream_joint;
        struct {
            unsigned char padding_handle_callback[4];
            SfdBufferHandleCallback handle_callback;
        } view_handle_callback;
        struct {
            unsigned char padding_object_callback[8];
            SfdBufferObjectCallback object_callback;
        } view_object_callback;
        struct {
            unsigned char padding_object[12];
            SfdCallbackObject object;
        } view_object;
    } fields;
} SfdBufferChannel;

typedef int (*SfdTransportLifecycleFn)(SfdHandle_u3 *handle);

typedef int (*SfdTransportPauseFn)(SfdHandle_u3 *handle, int state);

typedef int (*SfdTransportTransferFn)(SfdHandle_u3 *handle, SfdTransportValue parameter, int value);

typedef int (*SfdTransportBufferFn)(SfdHandle_u3 *handle, void *buffer);

struct SfdTransportInterface {
    SfdTransportLifecycleFn init;
    SfdTransportLifecycleFn finish;
    SfdTransportLifecycleFn exec_server;
    SfdTransportLifecycleFn create;
    SfdTransportLifecycleFn destroy;
    SfdTransportLifecycleFn standby;
    SfdTransportLifecycleFn start;
    SfdTransportLifecycleFn stop;
    SfdTransportPauseFn pause;
    SfdTransportBufferFn get_write;
    SfdTransportTransferFn add_write;
    SfdTransportBufferFn get_read;
    SfdTransportTransferFn add_read;
    SfdTransportTransferFn seek;
};

typedef struct SfdTransportState {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_interface[12];
            const SfdTransportInterface *interface;
        } view_interface;
        struct {
            unsigned char padding_buffer_output3[28];
            int buffer_output3;
        } view_buffer_output3;
    } fields;
} SfdTransportState;

struct SfdHandle_u3 {
    union {
        unsigned char padding_extent[13720];
        struct {
            unsigned char padding_transports[6816];
            SfdTransportState transports[9];
        } view_transports;
    } fields;
};

int fn_12_247BC(SfdHandle_u3 *handle, int stream_index, const unsigned char *data, int size,
                int *header_flag);

void fn_12_22668(SfdHandle_u3 *handle, int buffer_index, int channel, SfdBufferChannel *output);

void *fn_12_57F0(void *destination, const void *source, unsigned long size);

extern int lbl_12_bss_7E88;

static inline int sfmps_CopyToSj(SJ *sj, const unsigned char *data, int size) {
    SJCK second_chunk;
    SJCK first_chunk;
    if (sj->fields.view_interface.interface->fields.view_get_num_data.get_num_data(sj, 0) < size) {
        return 0;
    }
    sj->fields.view_interface.interface->fields.view_get_chunk.get_chunk(sj, 0, size, &first_chunk);
    fn_12_57F0(first_chunk.fields.view_data.data, data, first_chunk.fields.view_len.len);
    sj->fields.view_interface.interface->fields.view_put_chunk.put_chunk(sj, 1, &first_chunk);
    if (first_chunk.fields.view_len.len == 0) {
        return 0;
    }
    size -= first_chunk.fields.view_len.len;
    data += first_chunk.fields.view_len.len;
    if (size > 0) {
        sj->fields.view_interface.interface->fields.view_get_chunk.get_chunk(sj, 0, size,
                                                                             &second_chunk);
        fn_12_57F0(second_chunk.fields.view_data.data, data, second_chunk.fields.view_len.len);
        sj->fields.view_interface.interface->fields.view_put_chunk.put_chunk(sj, 1, &second_chunk);
        if (second_chunk.fields.view_len.len != size) {
            lbl_12_bss_7E88++;
        }
    }
    return 1;
}

static inline int sfmps_CopyUoch(SfdHandle_u3 *handle, int stream_index, const unsigned char *data,
                                 int size) {
    SfdBufferChannel channel;
    SfdBufferHandleCallback handle_callback;
    SfdBufferObjectCallback object_callback;
    SfdCallbackObject object;
    SJ *stream_joint;
    int result;
    fn_12_22668(
        handle,
        handle->fields.view_transports.transports[1].fields.view_buffer_output3.buffer_output3,
        stream_index, &channel);
    stream_joint = channel.fields.view_stream_joint.stream_joint;
    handle_callback = channel.fields.view_handle_callback.handle_callback;
    object_callback = channel.fields.view_object_callback.object_callback;
    object = channel.fields.view_object.object;
    if (stream_joint == 0) {
        return 1;
    }
    result = sfmps_CopyToSj(stream_joint, data, size);
    if (result == 1) {
        if (handle_callback != 0) {
            handle_callback(handle, stream_index);
        }
        if (object_callback != 0) {
            object_callback(object, stream_index);
        }
    }
    return result;
}

static inline int sfmps_CopyUo(SfdHandle_u3 *handle, int stream_index, const unsigned char *data,
                               int size) {
    if (handle->fields.view_transports.transports[1].fields.view_buffer_output3.buffer_output3 ==
        8) {
        return 1;
    }
    return sfmps_CopyUoch(handle, stream_index, data, size);
}

int fn_12_25748(SfdHandle_u3 *handle, int stream_index, const unsigned char *data, int size,
                long long pts) {
    int header_flag;
    if (fn_12_247BC(handle, stream_index, data, size, &header_flag) != 0) {
        if (header_flag != 0) {
            data -= 0x12;
            size += 0x12;
            sfmps_CopyUo(handle, 0, data, size);
        }
        return 1;
    }
    return sfmps_CopyUo(handle, stream_index, data, size);
}
/* fzgx:end fn_12_25748 */

/* fzgx:begin fn_12_25AAC noprologue */
#pragma use_lmw_stmw on
#include "types.h"

typedef struct MpsHandle MpsHandle;

typedef struct MpsValues {
    s32 value_00;
    s32 value_04;
    s32 value_08;
    s32 value_0c;
    s32 value_10;
    s32 value_14;
    s32 value_18;
    s32 value_1c;
} MpsValues;

typedef struct SfmpsWork {
    MpsHandle *decoder;
    s32 max_video_bound;
    s32 max_audio_bound;
    s32 video_pts_baseline;
    s32 audio_pts_baseline;
    s32 concat_count;
    s32 previous_video_stream;
    s32 previous_audio_stream;
    s32 first_video_stream;
    s32 first_audio_stream;
    s32 selected_video_id;
    s32 selected_audio_id;
} SfmpsWork;

typedef struct SfdHandle {
    u8 pad_0000[0x1AEC];
    SfmpsWork *work;
    u8 pad_1AF0[0x8];
    void *stream;
} SfdHandle;

typedef struct RingInfo {
    u8 *ptr0;
    s32 len0;
    u8 *ptr1;
    s32 len1;
    s32 unk10;
    s32 unk14;
} RingInfo;

typedef struct PtsInfo {
    s32 pts;
    u8 *ptr;
    s32 len;
} PtsInfo;

extern s32 fn_12_2D73C(SfdHandle *, int);
extern int fn_12_696C(MpsHandle *, MpsValues *, int);
extern s32 fn_12_224FC(SfdHandle *, void *, RingInfo *);
extern void *fn_12_57F0(void *, const void *, u32);
extern s32 fn_12_22254(SfdHandle *, void *, s32, s32);
extern s32 fn_12_2CF20(SfdHandle *, void *, PtsInfo *);

static inline SfmpsWork *compute_bounds(SfdHandle *handle) {
    SfmpsWork *work = handle->work;
    MpsHandle *dec;
    s32 maxA = 0;
    s32 maxV = 0;
    s32 i;
    MpsValues vals;

    dec = work->decoder;
    for (i = 0; i < 3; i++) {
        fn_12_696C(dec, &vals, i);
        maxA = (maxA > vals.value_08) ? maxA : vals.value_08;
        maxV = (maxV > vals.value_0c) ? maxV : vals.value_0c;
    }
    work->max_audio_bound = maxA;
    work->max_video_bound = maxV;
    return work;
}

static inline s32 choose_stream(SfdHandle *handle, s32 id) {
    SfmpsWork *work;
    switch (fn_12_2D73C(handle, 0x3B)) {
    case 1:
        return id;
    case 2:
        work = compute_bounds(handle);
        if (work->max_video_bound >= 2) {
            return 2;
        }
        return id;
    case 0:
    default:
        return id;
    }
    return id;
}

static inline s32 is_seq_start(u8 *buf, s32 len) {
    char c;

    if (len < 4) {
        return 0;
    }
    if (buf[0] != 0) {
        return 0;
    }
    if (buf[1] != 0) {
        return 0;
    }
    if (buf[2] != 1) {
        return 0;
    }
    if (buf[3] == 0xB3) {
        return 1;
    }
    c = buf[3];
    return (u8)c == 0xB8;
}

static inline s32 is_changed(SfdHandle *handle, SfmpsWork *work, s32 id) {
    if (fn_12_2D73C(handle, 0x37) != 0) {
        return id < work->previous_video_stream;
    }
    return id == work->first_video_stream;
}

static inline s32 write_data(SfdHandle *handle, u8 *buf, s32 len, s32 pts) {
    PtsInfo pi;
    void *stream;
    s32 err;
    RingInfo info;
    u8 *ptr0;
    s32 len0;
    u8 *ptr1;
    s32 extra;

    stream = handle->stream;
    err = fn_12_224FC(handle, stream, &info);
    if (err != 0) {
        return err;
    }
    len0 = info.len0;
    ptr0 = info.ptr0;
    ptr1 = info.ptr1;
    extra = info.unk14;
    if (len > len0 + info.len1) {
        return 0;
    }
    if (len <= len0) {
        fn_12_57F0(ptr0, buf, len);
    } else {
        fn_12_57F0(ptr0, buf, len0);
        fn_12_57F0(ptr1, buf + len0, len - len0);
    }
    err = fn_12_22254(handle, stream, len, extra);
    if (err != 0) {
        return err;
    }
    if (pts >= 0) {
        pi.pts = pts;
        pi.ptr = ptr0;
        pi.len = len;
        err = fn_12_2CF20(handle, stream, &pi);
        if (err != 0) {
            return err;
        }
    }
    return 1;
}

s32 fn_12_25AAC(SfdHandle *handle, s32 id, u8 *buf, s32 len, s32 pts) {
    SfmpsWork *work;
    s32 next;

    if (fn_12_2D73C(handle, 5) == 0) {
        return 1;
    }
    work = handle->work;
    if (work->selected_video_id == -1) {
        work->selected_video_id = choose_stream(handle, id);
    }
    if (work->first_video_stream == -1) {
        work->first_video_stream = id;
    }
    next = fn_12_2D73C(handle, 0x1D);
    if (next != -1) {
        if (is_changed(handle, work, id) && work->selected_video_id != next) {
            if (is_seq_start(buf, len)) {
                work->selected_video_id = next;
            }
        }
    }
    work->previous_video_stream = id;
    if (work->selected_video_id != id) {
        return 1;
    }
    return write_data(handle, buf, len, pts);
}
/* fzgx:end fn_12_25AAC */

/* fzgx:begin fn_12_25DA8 noprologue */
#include "types.h"

typedef struct MovieState {
    u8 pad_0000[0x0c];
    int start;
    int high;
    u8 pad_0014[0x08];
    int low;
    u8 pad_0020[0x04];
    int selected;
    u8 pad_0028[0x04];
    int current;
} MovieState;

typedef struct MovieModule {
    u8 pad_0000[0x1aec];
    MovieState *state;
    u8 pad_1af0[0x0c];
    void *stream;
} MovieModule;

typedef struct MovieResult {
    void *buffer;
    int start;
    void *second;
    int end;
    u32 unk10;
    int index;
    u8 pad_0018[0x08];
} MovieResult;

extern int fn_12_2D73C(MovieModule *, int);
extern int fn_12_224FC(MovieModule *, void *, MovieResult *);
extern void fn_12_57F0(void *, int, int);
extern int fn_12_22254(MovieModule *, void *, int, int);
extern int fn_12_2CF20(MovieModule *, void *, int *);

#pragma opt_dead_assignments off
static inline u32 fn_12_25DA8_operand(u32 right, u32 left) { return left & right; }
int fn_12_25DA8(MovieModule *module, int track, int offset, int length, int limit) {
    void * fzgx_live;
    MovieState *state;
    int delta;
    int index;
    MovieResult result;
    int status;
    void *result_second;
    int result_start;
    void *result_buffer;
    void *stream;
    int args[3];

    if (fn_12_2D73C(module, 6) == 0) {
        return 1;
    }

    state = module->state;
    if (state->current == -1) {
        state->current = track;
    }
    if (state->selected == -1) {
        state->selected = track;
    }

    index = fn_12_2D73C(module, 0x1e);
    if (index != -1) {
        if (fn_12_2D73C(module, 0x37) != 0) {
            { int __reg_value_delta = (state->low ^ track) >> 1; delta = __reg_value_delta; }
            delta -= fn_12_25DA8_operand((state->low), ((state->low ^ track)));
            delta = (int)((u32)delta >> 31);
        } else {
            delta = (int)((state->selected - track) == 0);
        }
        if (delta != 0) {
            state->current = index;
        }
    }

    state->low = track;
    if (state->current != track) {
        return 1;
    }

    if (limit >= 0) {
        int tmp = state->start;
        if (limit < tmp) {
            tmp = limit;
        }
        state->start = tmp;
        tmp = state->high;
        if (limit < tmp) {
            tmp = limit;
        }
        state->high = tmp;
        limit -= state->start;
    }

    stream = module->stream;
    status = fn_12_224FC(module, stream, &result);
    if (status != 0) {
        return status;
    }
    result_start = result.start;
    result_buffer = result.buffer;
    fzgx_live = result.second;
    result_second = fzgx_live;
    index = result.index;
    if (length > result_start + result.end) {
        return 0;
    }

    if (length <= result_start) {
        fn_12_57F0(result_buffer, offset, length);
    } else {
        fn_12_57F0(result_buffer, offset, result_start);
        fn_12_57F0(result_second, offset + result_start,
                   length - result_start);
    }

    status = fn_12_22254(module, stream, length, index);
    if (status != 0) {
        return status;
    }

    if (limit >= 0) {
        args[0] = limit;
        args[1] = (int)result_buffer;
        args[2] = length;
        status = fn_12_2CF20(module, stream, args);
        if (status != 0) {
            return status;
        }
    }
    return 1;
}
#pragma opt_dead_assignments reset

/* fzgx:end fn_12_25DA8 */

/* fzgx:begin fn_12_25FA8 noprologue */
#include "types.h"

typedef struct MovieOut {
    void *dest;
    s32 size;
} MovieOut;

typedef struct MovieHandlerVtbl {
    void *unk00;
    void *unk04;
    void *unk08;
    void *unk0c;
    void *unk10;
    void *unk14;
    void (*fn18)(void *, s32, s32, MovieOut *);
    void (*unk1c)(void *, s32, MovieOut *);
    void (*fn20)(void *, s32, MovieOut *);
    s32 (*fn24)(void *, s32);
} MovieHandlerVtbl;

typedef struct MovieHandler {
    MovieHandlerVtbl *vtable;
} MovieHandler;

typedef struct MovieSlots {
    MovieHandler *slot[175];
} MovieSlots;

typedef struct MovieRoot {
    void *field_000;
    u8 pad_004[0x140];
    void (*cb144)(void *, u32);
    void *cb148;
} MovieRoot;

typedef struct MovieValues {
    u32 value_00;
    u32 value_04;
    u32 value_08;
    u32 value_0c;
    u32 value_10;
    u32 value_14;
    u32 value_18;
    u32 value_1c;
} MovieValues;

typedef struct MovieModule {
    u8 pad_000[0x1aec];
    MovieRoot *root;
} MovieModule;

typedef s32 (*MovieTableFn)(MovieModule *, u32, s32, s32, u32);

extern int fn_12_24A88(void *arg0, int code);
extern int fn_12_683C(void *arg0, MovieValues *arg1);
extern void *fn_12_57F0(void *arg0, void *arg1, u32 arg2);
extern u32 lbl_12_bss_7E88;
extern void *lbl_12_rodata_BC8[4];

s32 fn_12_25FA8(MovieModule *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 *arg4) {
    void * fzgx_live;
    s32 rem;
    s32 tmp_call2;
    void (*cb)(void *, u32);
    void *cb_this;
    MovieRoot *root;
    s32 ret;
    s32 idx;
    s32 count;
    s32 sel;
    u32 pb;
    u32 pa;
    MovieHandler *handler;
    MovieValues values;
    MovieOut out1;
    MovieOut out2;

    ret = 0;
    *arg3 = 0;
    *arg4 = 0;
    root = arg0->root;
    tmp_call2 = fn_12_683C(root->field_000, &values);
    if (tmp_call2 != 0) {
        ret = fn_12_24A88(arg0, 0xff000d06);
    }
    count = values.value_1c;
    idx = values.value_00;
    sel = values.value_04;
    pa = values.value_08;
    pb = values.value_14;
    if (count < 0) {
        return fn_12_24A88(arg0, 0xff000d0e);
    }
    if (count == 0) {
        *arg3 = 0;
        *arg4 = 1;
        return 0;
    }
    if (arg2 < count) {
        return 0;
    }
    handler = ((MovieSlots *)((u8 *)root - 0x2bc))->slot[idx];
    if (handler != 0) {
        cb_this = root->cb148;
        cb = root->cb144;
        if (handler->vtable->fn24(handler, 0) < count) {
            arg1 = 0;
        } else {
            handler->vtable->fn18(handler, 0, count, &out1);
            fn_12_57F0(out1.dest, (void *)arg1, out1.size);
            handler->vtable->fn20(handler, 1, &out1);
            if (out1.size == 0) {
                arg1 = 0;
            } else {
                rem = count - out1.size;
                arg1 += out1.size;
                if (rem > 0) {
                    handler->vtable->fn18(handler, 0, rem, &out2);
                    fzgx_live = out2.dest;
                    fn_12_57F0(fzgx_live, (void *)arg1, out2.size);
                    handler->vtable->fn20(handler, 1, &out2);
                    if (out2.size != rem) {
                        lbl_12_bss_7E88++;
                    }
                }
                arg1 = 1;
            }
        }
        if (arg1 == 1 && cb != 0) {
            cb(cb_this, idx);
        }
        *arg4 = arg1;
    } else {
        *arg4 = ((MovieTableFn)lbl_12_rodata_BC8[sel])(arg0, pa, arg1, count, pb);
    }

    switch (*arg4) {
    case 1:
        *arg3 = count;
        break;
    case 0:
        break;
    default:
        ret = *arg4;
        break;
    }
    return ret;
}

/* fzgx:end fn_12_25FA8 */

/* fzgx:begin fn_12_26218 noprologue */
#include "types.h"
typedef struct Sig_fn_12_654C_MovieValues {
    s32 value_00; s32 value_04; s32 value_08; s32 value_0c;
    s32 value_10; s32 value_14; s32 value_18; s32 value_1c;
} Sig_fn_12_654C_MovieValues;
typedef struct Sig_fn_12_654C_MovieModule {
    u8 pad00[0x10]; int field10; u8 field14[0x0c];
    Sig_fn_12_654C_MovieValues values;
    Sig_fn_12_654C_MovieValues slots[3];
    u8 fielda0[0x20];
} Sig_fn_12_654C_MovieModule;
typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);
typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48]; s32 state; u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context; s32 callback_data;
} Sig_fn_12_24A88_MovieObject;
typedef struct Sig_fn_12_68D4_MovieValues {
    u32 value_00; u32 value_04; u32 value_08; u32 value_0c;
    u32 value_10; u32 value_14; u32 value_18; u32 value_1c;
} Sig_fn_12_68D4_MovieValues;
typedef struct Sig_fn_12_68D4_MovieModule {
    u8 _pad00[0x20]; Sig_fn_12_68D4_MovieValues values;
} Sig_fn_12_68D4_MovieModule;
struct fn_12_26218_Arg0 { u8 pad_0[0x1AEC]; u32 unk_1AEC; };
struct fn_12_26218_Arg3 { u32 unk_0; };
extern int fn_12_654C(Sig_fn_12_654C_MovieModule *, const u8 *, int, int *, int *);
extern int fn_12_68D4(Sig_fn_12_68D4_MovieModule *, Sig_fn_12_68D4_MovieValues *);
extern s32 fn_12_231F8(u32);
extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *, s32);
extern s32 fn_12_23250(u32);
extern s32 fn_12_2559C(struct fn_12_26218_Arg0 *, const u8 *, s32, u32);
extern u32 fn_12_25FA8(struct fn_12_26218_Arg0 *, const u8 *, s32, void *, void *);
extern u32 fn_12_67A4(const u8 *);
extern void *fn_12_57F0(void *, const void *, u32);
u32 fn_12_26218(struct fn_12_26218_Arg0 *arg0, const u8 *arg1, u32 arg2, struct fn_12_26218_Arg3 *arg3, u32 arg4) {
    s32 arg2_local = arg2;
    u32 base;
    s32 result = 0;
    u32 entry;
    u32 data;
    s32 amount;
    s32 count;
    s32 zero;
    s32 i;
    const s8 *p;
    u8 *slot;
    s32 tail;
    Sig_fn_12_68D4_MovieValues loc_18;
    u32 loc_14;
    u32 loc_10;
    u32 loc_C;
    u32 loc_8;
    arg3->unk_0 = 0;
    base = *(u32 *)arg0->unk_1AEC;
    if (fn_12_2559C(arg0, arg1, arg2_local, arg4) == 0) return 0;
    if (fn_12_654C((Sig_fn_12_654C_MovieModule *)base, arg1, arg2_local, (int *)&loc_10, (int *)&loc_14) != 0)
        result = fn_12_24A88((Sig_fn_12_24A88_MovieObject *)arg0, 0xff000d03);
    if (loc_14 & 0x20000) {
        entry = *(u32 *)((u8 *)arg0 + 0x2908);
        if (entry == 0) entry = 0;
        else if (*(s32 *)(arg0->unk_1AEC + 0x14) > 0) entry = 0;
        else entry += 0x8a0;
        if (entry != 0 && *(s32 *)entry == 0) {
            data = entry + 0x24;
            fn_12_68D4((Sig_fn_12_68D4_MovieModule *)base, &loc_18);
            amount = 0xb0;
            if (arg2_local < 0xb0) amount = arg2_local;
            if ((s32)loc_18.value_0c > 0) {
                *(s32 *)(data + 0x160) = amount;
            } else if ((s32)loc_18.value_08 > 0) {
                *(s32 *)(data + 0x164) = amount;
                data += 0xb0;
            } else goto copy_done; /* Keep the verified branch to copy_done. */
            fn_12_57F0((void *)data, arg1, amount);
        }
    }
copy_done:
    if (loc_14 == 0x80000 && fn_12_23250((u32)arg0) != 0) {
        (*(s32 *)(arg0->unk_1AEC + 0x14))++;
        arg3->unk_0 = 4;
    } else if (loc_14 == 0x80000 && fn_12_231F8((u32)arg0) != 0) {
        arg3->unk_0 = 4;
    } else if ((s32)loc_14 == 0) {
        count = *(s32 *)((u8 *)arg0 + 0x28);
        if (arg2_local >= count + 3) {
            p = (const s8 *)arg1;
            for (i = 0; i < count; i++) {
                if (*p++ != 0) { zero = 0; goto zero_done; /* Keep the verified branch to zero_done. */ }
            }
            zero = 1;
zero_done:
            if (zero) { tail = count; goto scan_done; /* Keep the verified branch to scan_done. */ }
        }
        count = 0;
        while (arg2_local >= 4) {
            if (fn_12_67A4(arg1) & 0xd0000) { tail = count; goto scan_done; /* Keep the verified branch to scan_done. */ }
            count++; arg1++; arg2_local--;
        }
        if (arg2_local > 0 && arg2_local < 4) {
            slot = (u8 *)arg0 + *(s32 *)((u8 *)arg0 + 0x1af4) * 0x74;
            if (*(s32 *)(slot + 0x1150) == 0 &&
                (*(s32 *)(slot + 0x1160) != 0 || *(s32 *)(slot + 0x1164) != 0)) {
                zero = 0;
            } else if (arg1 + arg2_local == (const u8 *)(*(u32 *)(slot + 0x1158) + *(u32 *)(slot + 0x115c))) {
                zero = 1;
            } else zero = 0;
            if (zero) count += arg2_local;
        }
        tail = count;
scan_done:
        arg3->unk_0 = tail;
    } else if (!(loc_14 & 0x40000)) {
        result = fn_12_24A88((Sig_fn_12_24A88_MovieObject *)arg0, 0xff000d05);
    } else {
        arg1 += loc_10; arg2_local -= loc_10;
        result = fn_12_25FA8(arg0, arg1, arg2_local, &loc_C, &loc_8);
        if ((s32)loc_8 == 1) arg3->unk_0 = loc_10 + loc_C;
    }
    return result;
}
/* fzgx:end fn_12_26218 */

/* fzgx:begin fn_12_26534 noprologue */
#include "types.h"

struct Movie {
    u8 pad0[0x48];
    int state;
    u8 pad4C[0x1AF4-0x4C];
    int stream;
    int field1AF8;
    int field1AFC;
    int field1B00;
};
struct Block { u32 address; int size; u32 unused; int extra; u32 reserved[4]; };
extern int fn_12_21D30(struct Movie *, int);
extern int fn_12_22390(struct Movie *, int, struct Block *);
extern int fn_12_26218(struct Movie *, u32, int, int *, int);
extern int fn_12_22008(struct Movie *, int, int);
extern void fn_12_252A0(struct Movie *);

static inline int get_block(struct Movie *movie, u32 *address, int *size, int *end) {
    struct Block block;
    int result = fn_12_22390(movie, movie->stream, &block);
    if (result != 0) return result;
    *size = block.size;
    *address = block.address;
    *end = *size + block.extra;
    return 0;
}
#pragma use_lmw_stmw on
static inline int process_blocks(struct Movie *arg0, int limit) {
    int size;
    u32 address;
    int total;
    int end;
    struct Movie *movie = arg0;
    int status;
    int consumed;
    struct Block block;
    status = 0;
    total = status;
    while (total < limit) {
        int result = get_block(movie, &address, &size, &end);
        status = result;
        if (status != 0) break;
        status = fn_12_26218(movie, address, size, &consumed, end);
        if (status != 0) break;
        if (consumed == 0) break;
        result = fn_12_22008(movie, movie->stream, consumed);
        status = 0;
        if (result != 0) status = result;
        if (status != 0) break;
        total += consumed;
    }
    if (movie->state == 2) fn_12_252A0(movie);
    return status;
}

int fn_12_26534(struct Movie *movie) {
    int a = fn_12_21D30(movie, movie->field1AFC);
    int b = fn_12_21D30(movie, movie->field1AF8);
    int c = fn_12_21D30(movie, movie->field1B00);
    if ((a & b & c) == 1) return 0;
    return process_blocks(movie, 0x7FFFFFFF);
}
/* fzgx:end fn_12_26534 */

/* fzgx:begin fn_12_26664 noprologue */
#include "types.h"
#pragma opt_propagation off

/* --- rel/movie_module/fn_12_26664.c --- */
extern void fn_12_26534(void);

void fn_12_26664(void) {
    fn_12_26534();
}
/* fzgx:end fn_12_26664 */

/* fzgx:begin fn_12_26684 noprologue */

/* --- rel/movie_module/fn_12_26684.c --- */
extern void fn_12_6DE8(void);

int fn_12_26684(void) {
    fn_12_6DE8();
    return 0;
}
/* fzgx:end fn_12_26684 */

/* fzgx:begin fn_12_266A8 noprologue */

/* --- rel/movie_module/fn_12_266A8.c --- */
extern int fn_12_24A88(void *arg0, int code);
extern int fn_12_6ECC(int arg0, void *arg1);
extern u8 lbl_12_bss_7E8C[6164];
extern u32 lbl_12_bss_7E88;

int fn_12_266A8(void) {
    int size = 0x168;
    int result;

    if (size > 0x200) {
        result = fn_12_24A88(0, 0xff000d0c);
    } else {
        result = 0;
    }
    if (result != 0) {
        for (;;) {
        }
    }
    if (fn_12_6ECC(0x20, lbl_12_bss_7E8C) != 0) {
        return fn_12_24A88(0, 0xff000d01);
    }
    lbl_12_bss_7E88 = 0;
    return 0;
}
/* fzgx:end fn_12_266A8 */

/* fzgx:begin fn_12_26734 noprologue */
#include "types.h"

typedef struct MovieTable {
    u8 pad_0000[0x144];
    int arg3;
    int arg4;
} MovieTable;

typedef struct MovieModule {
    u8 pad_0000[0x1aec];
    MovieTable *movie_table;
} MovieModule;

extern int fn_12_24990(void *module);
extern int fn_12_24A88(int arg0, u32 arg1);

#pragma opt_dead_assignments off
int fn_12_26734(MovieModule *module, int index, int value, int arg3, int arg4) {
    MovieTable *table;
    int *entry;

    if (fn_12_24990(module) != 0) {
        return fn_12_24A88(0, 0xff000171);
    }

    if (index < 0xbc || index > 0xff) {
        return 0;
    }

    table = module->movie_table;
    table->arg3 = arg3;
    table->arg4 = arg4;
    entry = (int *)table + index;
    entry[-0xaf] = value;
    return 0;
}
#pragma opt_dead_assignments reset

/* fzgx:end fn_12_26734 */
