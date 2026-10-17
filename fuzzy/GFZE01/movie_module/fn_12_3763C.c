/* Non-matching: best partial attempt (97.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 prefix[0xbc];
    u32 tail;
    u32 tail_size;
    u32 tail_alignment;
    u8 pad_c8[0xc];
    u32 tail_header;
    u32 scratch;
    u32 scratch_size;
    u32 scratch_used;
    u32 scratch_flags;
    u8 pad_e8[0x28];
    u32 auxiliary;
    u32 auxiliary_size;
    u8 pad_118[0x18];
    u32 stream;
    u32 stream_size;
    u32 stream_block_size;
    u8 pad_13c[0x1c];
    u32 arena;
    u32 capacity;
    u32 current;
    u32 used;
    s32 count;
    u32 allocations[32];
} MovieBuilder;

typedef struct {
    s32 format;
    s32 bitrate;
    s32 width;
    s32 height;
    s32 frames;
    s32 segments;
    u32 reserved[3];
    s32 pixel_mode;
} MovieRequest;

typedef struct {
    const char *name;
    u32 work;
    u32 extra;
    u32 index_bytes;
    u32 decoder_bytes;
    u32 reserved[5];
    u32 quantum;
    u32 frame_count;
    u32 width;
    u32 height;
    u32 mode;
    u32 buffer;
    u32 buffer_size;
} MovieParameters;

typedef struct {
    u32 stride;
    u32 half_height;
    u32 width;
    u32 height;
    u32 flags;
    u32 copy_width;
    u32 copy_height;
    u32 frame_count;
    u32 reserved;
} FrameDescriptor;

typedef struct {
    /* The first 0x44 bytes are a relocated interface, not a parameter template. */
    u8 interface[0x44];
    MovieParameters presets[3];
    FrameDescriptor frame;
    u32 work[7];
    s32 quantum;
    u32 reserved;
} MovieDefaults;

typedef struct {
    s32 stream_a;
    s32 stream_b;
    s32 all_frames_bytes;
    s32 double_frame_bytes;
    s32 decoder_bytes;
    s32 index_bytes;
    s32 extra;
    s32 audio_bytes;
    u32 aligned_audio;
    u32 reserved;
} MovieSizes;

typedef u32 (*MovieAllocate)(u32, u32);
typedef void (*MovieFree)(u32, u32);
extern u32 *fn_12_38DBC(void);
extern s32 fn_12_38340(MovieBuilder *, MovieRequest *, u32 *);
extern void fn_12_2A6FC(FrameDescriptor *, u32 *, u32 *);
extern void fn_12_2145C(void *);
extern void *fn_12_2BCF4(MovieParameters *, s32);
extern s32 fn_12_249BC(void *, void *, void *);
extern void fn_12_388C4(s32, s32);
extern void fn_12_38A0C(s32);
extern void MWSFSVM_Error(const char *, ...);
extern MovieDefaults lbl_12_data_D38;
extern MovieSizes lbl_12_bss_1B9B0;
extern char lbl_12_rodata_1D88[];

/* Same inline allocator as the verified fn_12_38340, including failure ownership. */
static inline u32 allocate(MovieBuilder *builder, s32 size, const char *errors) {
    u32 result;
    u32 *manager;
    if (builder->count >= 32) {
        MWSFSVM_Error(errors + 0x6c);
        return 0;
    }
    if (size < 0) {
        return 0;
    }
    if (builder->arena != 0) {
        if (builder->used + size > builder->capacity) {
            result = 0;
        } else {
            result = builder->current;
            builder->current = result + size;
            builder->used = builder->used + size;
        }
    } else {
        manager = fn_12_38DBC();
        result = ((MovieAllocate)manager[10])(manager[12], size);
    }
    if (result != 0) {
        builder->allocations[builder->count] = result;
        builder->count++;
    }
    return result;
}

static inline s32 frame_bytes(MovieRequest *request, const char *errors) {
    s32 width = request->width;
    s32 height = request->height;
    s32 width_tiles;
    s32 height_tiles;
    s32 padded_width;
    s32 padded_height;
    s32 luma_stride;
    s32 chroma_stride;
    s32 chroma_height;
    if (request->pixel_mode >= 4 || request->pixel_mode < 0) {
        MWSFSVM_Error(errors + 0x3fc);
    }
    width_tiles = (width + 15) / 16;
    height_tiles = (height + 15) / 16;
    padded_width = width_tiles << 4;
    padded_height = height_tiles << 4;
    luma_stride = ((padded_width + 31) / 32) << 5;
    chroma_height = padded_height / 2;
    chroma_stride = (((padded_width / 2) + 31) / 32) << 5;
    return padded_height * luma_stride + ((chroma_height * chroma_stride) << 1) + 32;
}

static inline void initialize_frame(FrameDescriptor *frame, u32 *work,
                                    MovieRequest *request, s32 count,
                                    u32 stream_a, u32 stream_b) {
    s32 width = request->width;
    s32 height = request->height;
    frame->width = width;
    frame->height = height;
    frame->stride = (((width / 2) + 31) / 32) << 5;
    frame->half_height = height / 2;
    frame->flags = 0;
    frame->copy_width = width;
    frame->copy_height = height;
    frame->frame_count = count;
    frame->reserved = 0;
    work[2] = stream_a;
    work[6] = stream_b;
}

#pragma use_lmw_stmw on
#pragma opt_loop_invariants off
void *fn_12_3763C(MovieBuilder *builder, MovieRequest *request) {
    MovieDefaults *defaults = &lbl_12_data_D38;
    MovieSizes *sizes = &lbl_12_bss_1B9B0;
    char *errors = lbl_12_rodata_1D88;
    s32 saved_width;
    MovieParameters parameters;
    u32 frames[16];
    u32 planes[2];
    s32 format;
    s32 frame_count;
    s32 saved_frame_count;
    s32 height;
    s32 segments;
    s32 bitrate;
    s32 block;
    s32 bytes;
    s32 allocation_bytes;
    s32 planes_error;
    s32 frames_error;
    s32 i;
    u32 buffer_bytes;
    u32 work_bytes;
    u32 header;
    u32 audio;
    u32 stream_a;
    u32 stream_b;
    u32 scratch;
    u32 buffer;
    u32 work;
    u32 auxiliary;
    u32 *cursor;
    u32 *decoder_work;
    u32 memory;
    u32 *manager;
    u32 mode;
    void *movie;

    segments = request->segments;
    format = request->format;
    saved_frame_count = request->frames;
    saved_width = request->width;
    height = request->height;
    bitrate = request->bitrate;
    if (segments <= 0) {
        segments = 1;
    }
    if (format == 2) {
        block = ((bitrate / 8) / 2048) << 11;
        sizes->extra = 0;
        sizes->index_bytes = 0;
        sizes->decoder_bytes = 0;
        sizes->stream_a = 0;
        sizes->stream_b = 0;
        sizes->audio_bytes = segments * block;
    } else if (format == 3) {
        block = ((bitrate / 8) / 2048) << 11;
        sizes->extra = 0;
        sizes->decoder_bytes = 0;
        sizes->stream_a = 0;
        sizes->stream_b = 0;
        sizes->audio_bytes = segments * block;
        sizes->index_bytes = block / 2 + 2048;
    } else {
        block = ((bitrate / 8) / 2048) << 11;
        sizes->extra = 0;
        sizes->decoder_bytes = 24012;
        sizes->audio_bytes = segments * block;
        sizes->index_bytes = block / 2 + 2048;
        sizes->stream_a = 24332;
        sizes->stream_b = 49600;
    }

    frame_count = request->frames;
    bytes = frame_bytes(request, errors);
    allocation_bytes = sizes->extra + sizes->index_bytes + sizes->decoder_bytes + 32;
    sizes->double_frame_bytes = bytes << 1;
    sizes->all_frames_bytes = frame_count * bytes;
    header = allocate(builder, allocation_bytes, errors);
    audio = allocate(builder, sizes->audio_bytes + 64, errors);
    planes_error = fn_12_38340(builder, request, planes);
    frame_count = request->frames;
    frames_error = 0;
    bytes = frame_bytes(request, errors);
    cursor = frames;
    for (i = 0; i < frame_count; i++) {
        *cursor = allocate(builder, bytes, errors);
        if (*cursor == 0) {
            frames_error = -1;
        }
        cursor++;
    }
    stream_a = allocate(builder, sizes->stream_a, errors);
    stream_b = allocate(builder, sizes->stream_b, errors);
    scratch = allocate(builder, 2048, errors);
    buffer = allocate(builder, (buffer_bytes = 16384), errors);
    work = allocate(builder, (work_bytes = 1792), errors);
    auxiliary = allocate(builder, 256, errors);
    if (header == 0 || audio == 0 || planes_error != 0 || frames_error != 0 ||
        stream_a == 0 || stream_b == 0 || scratch == 0 || buffer == 0 ||
        auxiliary == 0 || work == 0) {
        MWSFSVM_Error(errors + 0x424);
        for (i = 0; i < 32; i++) {
            memory = builder->allocations[31 - i];
            if (memory != 0) {
                if (builder->arena == 0) {
                    manager = fn_12_38DBC();
                    ((MovieFree)manager[11])(manager[12], memory);
                }
                builder->count--;
                builder->allocations[31 - i] = 0;
            }
        }
        return 0;
    }

    sizes->aligned_audio = (audio + 63) & ~63u;
    decoder_work = defaults->work;
    initialize_frame(&defaults->frame, decoder_work, request, saved_frame_count, stream_a, stream_b);
    switch (format) {
    case 1:
        parameters = defaults->presets[0];
        builder->stream = sizes->aligned_audio;
        builder->stream_size = sizes->audio_bytes - 2048;
        builder->stream_block_size = 2048;
        break;
    case 2:
        parameters = defaults->presets[1];
        builder->stream = sizes->aligned_audio;
        builder->stream_size = sizes->audio_bytes - 2048;
        builder->stream_block_size = 2048;
        break;
    case 3:
        parameters = defaults->presets[2];
        builder->stream = sizes->aligned_audio;
        builder->stream_size = sizes->audio_bytes - 2048;
        builder->stream_block_size = 2048;
        break;
    }
    parameters.quantum = defaults->quantum;
    if (sizes->extra != 0) {
        sizes->extra -= sizes->extra % defaults->quantum;
    }
    switch (request->pixel_mode) {
    case 0: mode = 3; break;
    case 1: mode = 1; break;
    case 2: mode = 2; break;
    case 3: mode = 3; break;
    default:
        MWSFSVM_Error(errors + 0x3fc);
        mode = 3;
        break;
    }
    parameters.decoder_bytes = sizes->decoder_bytes;
    parameters.work = header;
    parameters.extra = sizes->extra;
    parameters.index_bytes = sizes->index_bytes;
    parameters.frame_count = saved_frame_count;
    parameters.width = saved_width;
    parameters.height = height;
    parameters.mode = mode;
    parameters.buffer = buffer;
    parameters.buffer_size = 16384;
    fn_12_2A6FC(&defaults->frame, planes, frames);
    switch (format) {
    case 0:
        break;
    case 1:
        fn_12_2145C(defaults->work);
        break;
    default:
        break;
    }
    movie = fn_12_2BCF4(&parameters, 0);
    if (movie == 0) {
        fn_12_38A0C(-305);
        MWSFSVM_Error(errors + 0x440);
        return 0;
    }
    if (fn_12_249BC(movie, (void *)fn_12_388C4, builder) != 0) {
        fn_12_38A0C(-303);
        MWSFSVM_Error(errors + 0x46c);
        return 0;
    }
    builder->auxiliary = auxiliary;
    builder->auxiliary_size = 256;
    builder->scratch = scratch;
    builder->scratch_size = 64;
    builder->scratch_used = 0;
    builder->scratch_flags = 0;
    builder->tail = scratch + 64;
    builder->tail_size = 1984;
    builder->tail_alignment = 64;
    builder->tail_header = (u32)&builder->tail;
    return movie;
}

#pragma opt_loop_invariants reset
#pragma use_lmw_stmw reset
