
#include "types.h"

typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
    const void *(*get_uuid)(SJ *sj);
    void (*reset)(SJ *sj);
    void (*get_chunk)(SJ *sj, long channel, long max_size, SJCK *chunk);
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

typedef struct AXPBMIX {
    unsigned short vL, vDeltaL, vR, vDeltaR;
    unsigned short vAuxAL, vDeltaAuxAL, vAuxAR, vDeltaAuxAR;
    unsigned short vAuxBL, vDeltaAuxBL, vAuxBR, vDeltaAuxBR;
    unsigned short vAuxBS, vDeltaAuxBS, vS, vDeltaS;
    unsigned short vAuxAS, vDeltaAuxAS;
} AXPBMIX;

typedef struct AXPBITD {
    unsigned short flag, bufferHi, bufferLo, shiftL, shiftR;
    unsigned short targetShiftL, targetShiftR;
} AXPBITD;

typedef struct AXPBUPDATE {
    unsigned short updNum[5];
    unsigned short dataHi, dataLo;
} AXPBUPDATE;

typedef struct AXPBDPOP {
    short aL, aAuxAL, aAuxBL, aR, aAuxAR, aAuxBR, aS, aAuxAS, aAuxBS;
} AXPBDPOP;

typedef struct AXPBVE {
    unsigned short currentVolume;
    short currentDelta;
} AXPBVE;

typedef struct AXPBFIR {
    unsigned short numCoefs, coefsHi, coefsLo;
} AXPBFIR;

typedef struct AXPBADDR {
    unsigned short loopFlag, format;
    unsigned short loopAddressHi, loopAddressLo;
    unsigned short endAddressHi, endAddressLo;
    unsigned short currentAddressHi, currentAddressLo;
} AXPBADDR;

typedef struct AXPBADPCM {
    unsigned short a[8][2];
    unsigned short gain, pred_scale, yn1, yn2;
} AXPBADPCM;

typedef struct AXPBSRC {
    unsigned short ratioHi, ratioLo, currentAddressFrac;
    unsigned short last_samples[4];
} AXPBSRC;

typedef struct AXPBADPCMLOOP {
    unsigned short loop_pred_scale, loop_yn1, loop_yn2;
} AXPBADPCMLOOP;

typedef struct AXPBLPF {
    unsigned short on, yn1, a0, b0;
} AXPBLPF;

typedef struct AXPB {
    unsigned short nextHi, nextLo, currHi, currLo;
    unsigned short srcSelect, coefSelect, mixerCtrl, state, type;
    AXPBMIX mix;
    AXPBITD itd;
    AXPBUPDATE update;
    AXPBDPOP dpop;
    AXPBVE ve;
    AXPBFIR fir;
    AXPBADDR addr;
    AXPBADPCM adpcm;
    AXPBSRC src;
    AXPBADPCMLOOP adpcmLoop;
    AXPBLPF lpf;
    unsigned short pad[25];
} AXPB;

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
    AXPB pb;
} AXVPB;

typedef struct RNAResource RNAResource;

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


// Hardware or OS state can change asynchronously.
const char *const volatile lbl_800927BC = "\nAXRNA Ver.1.02 Build:May  9 2003 17:10:58\n";
static const char *const lbl_800927C4__fzgx_offset_4[] = {
    "OFF",
    "ON ",
};

void fn_8005A648(void);
void fn_8005A628(void);
void fn_8005A5BC(const char *message);
void *memset(void *dst, int c, unsigned long n);

#pragma section code_type ".fzgxpool"
static const void *fzgx_rodata_layout(int x) {
    if (x == 0) return lbl_800927BC;
    if (x == 1) return lbl_800927C4__fzgx_offset_4;
    if (x == 2) return "E1070309:Illigal parameter(sw).\n";
    return 0;
}
#pragma section code_type ".text"

static inline int axrna_get_transfer_switch(AXRNAHandle *handle) {
    if (handle == 0) {
        return -1;
    }
    return handle->switches & 1;
}

void fn_8005B264(AXRNAHandle *handle, int enabled) {
    long channel;
    long retry;
    long spin;

    if (handle == 0) {
        return;
    }
    if (enabled == axrna_get_transfer_switch(handle)) {
        return;
    }
    if (enabled == 1) {
        fn_8005A648();
        for (channel = 0; channel < handle->num_channels; channel++) {
            handle->buffers[channel]->interface->reset(handle->buffers[channel]);
            memset(&handle->input_chunks[channel], 0, sizeof(SJCK));
            memset(&handle->buffer_chunks[channel], 0, sizeof(SJCK));
            memset(&handle->requests[channel], 0, sizeof(ARQRequest));
            handle->transfer_pending[channel] = 0;
        }
        handle->transfer_samples = 0;
        handle->transfer_position = 0;
        handle->flash_samples = 0;
        handle->flash_position = 0;
        handle->play_position = -1;
        handle->switches |= 1;
        fn_8005A628();
    } else if (enabled == 0) {
        for (channel = 0; channel < handle->num_channels; channel++) {
            for (retry = 0; retry < 200; retry++) {
                if (handle->transfer_pending[channel] == 0) {
                    break;
                }
                for (spin = 0; spin < 100000; spin++) {
                }
            }
            if (retry == 200) {
                fn_8005A5BC("E2071701:DMA transfer(data) to A-RAM did not finish.\n");
                return;
            }
            for (retry = 0; retry < 200; retry++) {
                if (handle->flash_pending[channel] == 0) {
                    break;
                }
                for (spin = 0; spin < 100000; spin++) {
                }
            }
            if (retry == 200) {
                fn_8005A5BC("E2071701:DMA transfer(flash) to A-RAM did not finish.\n");
                return;
            }
        }
        handle->switches &= 2;
    } else {
        fn_8005A5BC("E1070308:Illigal parameter(sw).\n");
    }
}
