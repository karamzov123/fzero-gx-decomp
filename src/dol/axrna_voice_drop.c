#include "types.h"


/* --- dol/axrna_voice_drop.c --- */
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

void fn_80026D70(AXVPB *voice);

extern AXRNAHandle lbl_80191D4C[16];

void axrna_voice_drop(void *voice_data) {
    AXVPB *voice = (AXVPB *)voice_data;
    int handle_index;
    int channel;
    for (handle_index = 0; handle_index < 16; handle_index++) {
        for (channel = 0; channel < 2; channel++) {
            if (voice == lbl_80191D4C[handle_index].voices[channel]) {
                fn_80026D70(lbl_80191D4C[handle_index].voices[channel]);
                lbl_80191D4C[handle_index].voices[channel] = 0;
                return;
            }
        }
    }
}

/* --- dol/AXRNA_Finish.c --- */
void fn_80020ABC(AXVPB *voice);

void fn_80026D70(AXVPB *voice);

void *memset(void *destination, int value, unsigned long size);

void fn_8005A648(void);

void fn_8005A628(void);

void fn_8005BE98(RNAResource *resource);

void fn_8005BFB4(void);

void fn_8005B0C4(AXRNAHandle *handle, int enabled);

void fn_8005B264(AXRNAHandle *handle, int enabled);

void AXRNA_Destroy(AXRNAHandle *handle);

extern u32 lbl_80190C78;


static inline void AXRNA_Destroy(AXRNAHandle *handle) {
    int channel;
    if (handle == 0) {
        return;
    }
    fn_8005B0C4(handle, 0);
    fn_8005B264(handle, 0);
    for (channel = 0; channel < handle->allocated_channels; channel++) {
        if (handle->buffers[channel] != 0) {
            handle->buffers[channel]->interface->destroy(handle->buffers[channel]);
        }
        if (handle->resources[channel] != 0) {
            fn_8005BE98(handle->resources[channel]);
        }
        fn_8005A648();
        if (handle->voices[channel] != 0) {
            fn_80026D70(handle->voices[channel]);
            fn_80020ABC(handle->voices[channel]);
        }
        fn_8005A628();
    }
    memset(handle, 0, sizeof(AXRNAHandle));
}

void AXRNA_Finish(void) {
    int i;
    lbl_80190C78--;
    if (lbl_80190C78 == 0) {
        for (i = 0; i < 16; i++) {
            if (lbl_80191D4C[i].used == 1) {
                AXRNA_Destroy(&lbl_80191D4C[i]);
            }
        }
        memset(lbl_80191D4C, 0, sizeof(lbl_80191D4C));
        fn_8005BFB4();
    }
}
