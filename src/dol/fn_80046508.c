#include "types.h"


/* --- dol/fn_80046508.c --- */
/* --- dol/fn_80046508.c --- */
struct fn_80046508_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};

void fn_80046508(struct fn_80046508_Arg0 *arg0, u32 arg1) {
    arg0->unk_20 = arg1;
}

/* --- dol/fn_80046510.c --- */
struct fn_80046510_Arg0 {
    u8 pad_0[0x1];
    u8 unk_1;
};

void fn_80046510(struct fn_80046510_Arg0 *arg0) {
    arg0->unk_1 = 0;
}

/* --- dol/ADXAMP_Start.c --- */
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

typedef struct ADX_AMP {
    s8 used;
    s8 stat;
    s8 maxnch;
    s8 reserved_03;
    SJ *sji[2];
    SJ *sjo[2];
    s32 total_exsmpl[2];
    s32 nch;
    s32 sfreq;
    f32 frm_len;
    f32 frm_prd;
    s32 frm_no;
} ADX_AMP;

typedef ADX_AMP *ADXAMP;

void *memset(void *destination, int value, unsigned long size);

void ADXAMP_Start(ADXAMP amp) {
    SJCK chunk;
    SJ *stream;
    s32 channel;
    for (channel = 0; channel < amp->maxnch; channel++) {
        amp->total_exsmpl[channel] = 0;
    }
    amp->frm_no = 0;
    for (channel = 0; channel < amp->maxnch; channel++) {
        stream = amp->sji[channel];
        stream->interface->reset(stream);
        stream->interface->get_chunk(stream, 0, stream->interface->get_num_data(stream, 0), &chunk);
        memset(chunk.data, 0, chunk.len);
        stream->interface->unget_chunk(stream, 0, &chunk);
    }
    for (channel = 0; channel < amp->maxnch; channel++) {
        stream = amp->sjo[channel];
        stream->interface->reset(stream);
        stream->interface->get_chunk(stream, 0, stream->interface->get_num_data(stream, 0), &chunk);
        memset(chunk.data, 0, chunk.len);
        stream->interface->unget_chunk(stream, 0, &chunk);
    }
    amp->stat = 2;
}
