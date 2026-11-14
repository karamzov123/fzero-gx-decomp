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

typedef void (*ARQCallback)(unsigned long request_address);

typedef struct ARQRequest {
    struct ARQRequest *next;
    unsigned long owner;
    unsigned long type;
    unsigned long priority;
    unsigned long source;
    unsigned long destination;
    unsigned long length;
    ARQCallback callback;
} ARQRequest;

typedef struct RNAResource RNAResource;

typedef struct _AXVPB {
    struct _AXVPB *next;
    struct _AXVPB *prev;
    struct _AXVPB *next1;
    unsigned long priority;
    void (*callback)(void *);
    unsigned long user_context;
    unsigned long index, sync, depop;
    unsigned long updateMS, updateCounter, updateTotal;
    unsigned short *updateWrite;
    unsigned short updateData[128];
    void *itdBuffer;
    unsigned char pb[0x140];
} AXVPB;

typedef struct AXRNAHandle {
    signed char used;
    unsigned char switches;
    signed char allocated_channels;
    signed char num_channels;
    int play_position;
    AXVPB *voices[2];
    RNAResource *resources[2];
    u32 aram_addresses[2];
    int buffer_size;
    int sample_rate;
    u32 request_owners[2];
    SJ *inputs[2];
    SJ *buffers[2];
    SJCK input_chunks[2];
    SJCK buffer_chunks[2];
// Hardware or OS state can change asynchronously.
    volatile int transfer_pending[2];
    int transfer_samples;
    int transfer_position;
// Hardware or OS state can change asynchronously.
    volatile int flash_pending[2];
    int flash_samples;
    int flash_position;
    int bits_per_sample;
    int output_volume;
    int output_pan[2];
    int surround_pan;
    int aux_a;
    int aux_b;
    int fader;
    short adjust_sample_rate;
    short sample_rate_state;
    int source_type;
    ARQRequest requests[2];
} AXRNAHandle;

void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);

void ARQPostRequest(void *request, unsigned long owner, unsigned long type, unsigned long priority,
                    unsigned long source, unsigned long destination, unsigned long length,
                    ARQCallback callback);

void DCFlushRange(void *address, unsigned long length);

void fn_8005ACF0(unsigned long request_address);

void fn_8005ADBC(unsigned long request_address);

void axrna_update_play(AXRNAHandle *handle);

extern unsigned char *lbl_80190C7C[];

static inline int axrna_get_play_switch(const AXRNAHandle *handle) {
    if (handle == 0) {
        return -1;
    }
    return (handle->switches >> 1) & 1;
}

static inline int axrna_get_transfer_switch(const AXRNAHandle *handle) {
    if (handle == 0) {
        return -1;
    }
    return handle->switches & 1;
}

static inline void axrna_transfer(AXRNAHandle *handle) {
    SJCK input_chunk;
    SJCK input_remainder;
    SJCK buffer_chunk;
    SJCK buffer_remainder;
    register int channel;
    register int transfer_size;

    for (channel = 0; channel < handle->num_channels; channel++) {
        if (handle->voices[channel] == 0 || handle->transfer_pending[channel] != 0) {
            continue;
        }
        handle->buffers[channel]->interface->get_chunk(handle->buffers[channel], 0, 0x2000,
                                                       &buffer_chunk);
        handle->inputs[channel]->interface->get_chunk(handle->inputs[channel], 1,
                                                      buffer_chunk.len, &input_chunk);
        transfer_size = input_chunk.len < buffer_chunk.len ? input_chunk.len : buffer_chunk.len;
        transfer_size = (transfer_size / 32) * 32;
        fn_800589BC(&buffer_chunk, transfer_size, &buffer_chunk, &buffer_remainder);
        handle->buffers[channel]->interface->unget_chunk(handle->buffers[channel], 0,
                                                         &buffer_remainder);
        fn_800589BC(&input_chunk, transfer_size, &input_chunk, &input_remainder);
        handle->inputs[channel]->interface->unget_chunk(handle->inputs[channel], 1,
                                                        &input_remainder);
        if (transfer_size == 0) {
            return;
        }
        if (input_chunk.len == buffer_chunk.len) {
        } else {
            for (;;) {
            }
        }
        handle->input_chunks[channel] = input_chunk;
        handle->buffer_chunks[channel] = buffer_chunk;
        handle->transfer_samples = (unsigned int)transfer_size >> 1;
        DCFlushRange(handle->input_chunks[channel].data, handle->input_chunks[channel].len);
        handle->transfer_pending[channel] = 1;
        ARQPostRequest(&handle->requests[channel], handle->request_owners[channel], 0, 1,
                       (unsigned long)input_chunk.data, (unsigned long)buffer_chunk.data,
                       transfer_size, fn_8005ADBC);
    }
}

static inline void axrna_flash(AXRNAHandle *handle) {
    SJCK flash_chunk;
    SJCK flash_remainder;
    register int channel;
    register int transfer_size;

    for (channel = 0; channel < handle->num_channels; channel++) {
        if (handle->flash_pending[channel] != 0) {
            continue;
        }
        handle->buffers[channel]->interface->get_chunk(handle->buffers[channel], 0, 0x2000,
                                                       &flash_chunk);
        transfer_size = (flash_chunk.len / 32) * 32;
        fn_800589BC(&flash_chunk, transfer_size, &flash_chunk, &flash_remainder);
        handle->buffers[channel]->interface->unget_chunk(handle->buffers[channel], 0,
                                                         &flash_remainder);
        if (transfer_size == 0) {
            return;
        }
        handle->buffer_chunks[channel] = flash_chunk;
        handle->flash_samples = (unsigned int)transfer_size >> 1;
        DCFlushRange(lbl_80190C7C[0], 0x1000);
        handle->flash_pending[channel] = 1;
        ARQPostRequest(&handle->requests[channel], handle->request_owners[channel], 0, 1,
                       (unsigned long)lbl_80190C7C[0], (unsigned long)flash_chunk.data,
                       transfer_size, fn_8005ACF0);
    }
}

void fn_8005A9B8(AXRNAHandle *handle) {
    if (!(handle)) {
        return;
    }
    if (axrna_get_play_switch(handle) == 1) {
        axrna_update_play(handle);
    }
    if (axrna_get_transfer_switch(handle) == 1) {
        axrna_transfer(handle);
        return;
    }
    if (axrna_get_play_switch(handle) == 1 && handle->flash_position < handle->buffer_size) {
        axrna_flash(handle);
    }
}


