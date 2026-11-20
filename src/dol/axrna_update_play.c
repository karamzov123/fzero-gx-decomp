#include "types.h"


/* --- dol/axrna_update_play.c --- */
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

extern int lbl_80190C88;

extern int lbl_80190C8C[32];

static inline u32 axrna_get_voice_address(const AXVPB *voice) {
    return *(const u32 *)&voice->pb.addr.currentAddressHi;
}

void axrna_update_play(AXRNAHandle *handle) {
    SJCK chunk;
    AXVPB *voice;
    int current_position;
    int previous_position;
    int channel;
    int release_bytes;
    int played;
    voice = handle->voices[handle->num_channels - 1];
    previous_position = handle->play_position;
    if (voice == 0) {
        return;
    }
    current_position =
        axrna_get_voice_address(voice) - handle->aram_addresses[handle->num_channels - 1];
    lbl_80190C8C[lbl_80190C88++] = current_position;
    if (lbl_80190C88 == 32) {
        lbl_80190C88 = 0;
    }
    if (current_position < 0 || current_position > handle->buffer_size) {
        while (1) {
        }
    }
    if (previous_position == -1) {
        if (current_position == 0) {
            played = 0;
        } else {
            previous_position = 0;
            handle->play_position = 0;
        }
    }
    if (previous_position != -1) {
        if (current_position > previous_position) {
            played = current_position - previous_position;
        } else {
            played = 0x1000 - (previous_position - current_position);
        }
    }
    played = (played / 2048) * 2048;
    if (played > 0) {
        release_bytes = played * 2;
        for (channel = 0; channel < handle->num_channels; channel++) {
            handle->buffers[channel]->interface->get_chunk(handle->buffers[channel], 1,
                                                           release_bytes, &chunk);
            handle->buffers[channel]->interface->put_chunk(handle->buffers[channel], 0, &chunk);
        }
        handle->play_position += played;
        if (handle->play_position >= 0x1000) {
            handle->play_position -= 0x1000;
        }
    }
}

/* --- dol/fn_8005B010.c --- */
/* --- dol/fn_8005B010.c --- */
typedef u32 (*fn_8005B010_Fn0)(u32, u32);

u32 fn_8005B010(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = -1;
    } else {
    v0 = (v0 + ((s8)*(u8 *)((u8 *)v0 + 3) << 2));
    v0 = *(u32 *)((u8 *)v0 + 52);
    t0 = ((fn_8005B010_Fn0)*(u32 *)((u8 *)*(u32 *)((u8 *)v0 + 0) + 36))(v0, 0);
    v0 = t0;
    v0 = ((u32)v0 >> 1);
    }
    return v0;
}

/* --- dol/fn_8005B068.c --- */
typedef u32 (*fn_8005B068_Fn0)(u32, u32);

s32 fn_8005B068(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
        v0 = -1;
    } else {
        v0 = (v0 + ((s8)*(u8 *)((u8 *)v0 + 3) << 2));
        v0 = *(u32 *)((u8 *)v0 + 52);
        t0 = ((fn_8005B068_Fn0)*(u32 *)((u8 *)*(u32 *)((u8 *)v0 + 0) + 36))(v0, 0);
        v0 = t0;
        v0 = (4096 - ((u32)v0 >> 1));
    }
    return v0;
}
