
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

extern int lbl_80132558;
extern int lbl_8013255C[31];
extern int lbl_80190C80;
extern AXRNAHandle lbl_80191D4C[16];

void fn_8005A648(void);
void fn_8005A628(void);
void fn_8005A5BC(const char *message);
RNAResource *RNARES_Create(void);
void fn_8005BE98(RNAResource *resource);
u32 fn_8005BE80(RNAResource *resource);
u32 fn_8005BE68(RNAResource *resource);
SJ *fn_80058498(void *buffer, long size, long extra);
AXVPB *fn_80020B3C(unsigned long priority, void (*callback)(void *), unsigned long user_context);
void fn_80020ABC(AXVPB *voice);
void fn_800230A4(AXVPB *voice, unsigned long type);
void fn_80023438(AXVPB *voice, AXPBSRC *src);
void fn_80025EF4(AXVPB *voice, int mode, int input, int auxA, int auxB, int pan, int span, int fader);
void fn_80026D70(AXVPB *voice);
void fn_80026EE0(AXVPB *voice, int pan);
void fn_8005B0C4(AXRNAHandle *handle, int enabled);
void fn_8005B264(AXRNAHandle *handle, int enabled);
void axrna_voice_drop(void *voice);
void *memset(void *dst, int c, unsigned long n);

#pragma section code_type ".fzgxpool"
static const void *fzgx_rodata_layout(int x) {
    if (x == 0) return lbl_800927BC;
    if (x == 1) return lbl_800927C4__fzgx_offset_4;
    if (x == 2) return "E1070309:Illigal parameter(sw).\n";
    if (x == 3) return "E2071701:DMA transfer(data) to A-RAM did not finish.\n";
    if (x == 4) return "E2071701:DMA transfer(flash) to A-RAM did not finish.\n";
    if (x == 5) return "E1070308:Illigal parameter(sw).\n";
    return 0;
}
#pragma section code_type ".text"

static inline void axrna_set_source_type(AXRNAHandle *handle, int source_type) {
    if (handle != 0) {
        handle->source_type = source_type;
        handle->sample_rate_state = 1;
    }
}

static inline void AXRNA_SetAdjsfreqFlg(AXRNAHandle *handle, int enabled) {
    if (handle != 0) {
        handle->adjust_sample_rate = enabled;
    }
}

static inline void AXRNA_SetBitPerSmpl(AXRNAHandle *handle, int bits) {
    if (handle != 0) {
        handle->bits_per_sample = bits;
    }
}

static inline void AXRNA_SetOutPan(AXRNAHandle *handle, long channel, long pan) {
    AXVPB *voice;
    long clamped_pan;

    if (handle != 0) {
        if (channel < handle->allocated_channels) {
            clamped_pan = pan < 15 ? pan : 15;
            clamped_pan = clamped_pan > -15 ? clamped_pan : -15;
            if (clamped_pan != handle->output_pan[channel]) {
                handle->output_pan[channel] = clamped_pan;
                fn_8005A648();
                voice = handle->voices[channel];
                if (voice != 0) {
                    fn_80026EE0(voice, lbl_8013255C[clamped_pan + 15]);
                }
                fn_8005A628();
            }
        }
    }
}

static inline void AXRNA_SetSfreq(AXRNAHandle *handle, int sample_rate) {
    AXPBSRC source;
    int channel;
    int adjusted_rate;

    if (handle == 0) {
        return;
    }
    handle->sample_rate = sample_rate;
    adjusted_rate = (sample_rate * 1124 + 1124) / 1125;
    for (channel = 0; channel < handle->allocated_channels; channel++) {
        fn_8005A648();
        if (handle->voices[channel] != 0) {
            if (handle->adjust_sample_rate == 1) {
                unsigned int rate = adjusted_rate;

                if (sample_rate == 32000 && handle->sample_rate_state == 0) {
                    axrna_set_source_type(handle, 0);
                }
                source.ratioHi = rate / 32000;
                source.ratioLo = (rate << 8) / 125;
            } else {
                source.ratioHi = sample_rate / 32000;
                source.ratioLo = ((sample_rate << 8) / 125) & 0xFFFF;
            }
            source.currentAddressFrac = 0;
            source.last_samples[0] = 0;
            source.last_samples[1] = 0;
            source.last_samples[2] = 0;
            source.last_samples[3] = 0;
            fn_800230A4(handle->voices[channel], handle->source_type);
            fn_80023438(handle->voices[channel], &source);
        }
        fn_8005A628();
    }
}

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

AXRNAHandle *fn_8005B534(SJ **inputs, long max_channels) {
    AXRNAHandle *handle;
    unsigned int handle_index;
    unsigned int channel;

    if (max_channels <= 0) {
        fn_8005A5BC("E1070301:Illigal parameter(maxnch<=0).\n");
        return 0;
    }
    if (inputs == 0) {
        fn_8005A5BC("E1070302:Illigal parameter(sj=null).\n");
        return 0;
    }
    for (channel = 0; channel < max_channels; channel++) {
        if (inputs[channel] == 0) {
            fn_8005A5BC("E1070303:Illigal parameter(sj[]=null).\n");
            return 0;
        }
    }
    for (handle_index = 0; handle_index < 16; handle_index++) {
        if (lbl_80191D4C[handle_index].used == 0) {
            break;
        }
    }
    if (handle_index == 16) {
        fn_8005A5BC("E1070304:Not enough RNA handle.\n");
        return 0;
    }

    handle = &lbl_80191D4C[handle_index];
    handle->num_channels = max_channels;
    handle->allocated_channels = max_channels;
    for (channel = 0; channel < handle->allocated_channels; channel++) {
        handle->inputs[channel] = inputs[channel];
    }
    handle->output_volume = 0;
    handle->surround_pan = 127;
    handle->aux_a = -999;
    handle->aux_b = -999;
    handle->fader = 0;
    for (channel = 0; channel < handle->allocated_channels; channel++) {
        handle->request_owners[channel] =
            0x80000000 | (handle_index * 2 + channel);
        if ((handle->resources[channel] = RNARES_Create()) == 0) {
            fn_8005A5BC("E1070305:Can\x27t create RNARES.\n");
            AXRNA_Destroy(handle);
            return 0;
        }
        handle->aram_addresses[channel] =
            fn_8005BE80(handle->resources[channel]);
        handle->buffer_size = fn_8005BE68(handle->resources[channel]);
        handle->buffers[channel] = fn_80058498(
            (void *)(handle->aram_addresses[channel] * 2),
            handle->buffer_size * 2, 0);
        if (handle->buffers[channel] == 0) {
            fn_8005A5BC("E1070306:Can\x27t create SJ.\n");
            AXRNA_Destroy(handle);
            return 0;
        }
        if ((handle->voices[channel] = fn_80020B3C(31, axrna_voice_drop, 0)) == 0) {
            fn_8005A5BC("E1070307:Can\x27t acquire voice(AX).\n");
            AXRNA_Destroy(handle);
            return 0;
        }
        fn_8005A648();
        if (handle->voices[channel] != 0) {
            fn_80025EF4(
                handle->voices[channel], 3, handle->output_volume,
                handle->aux_a, handle->aux_b, 64, handle->surround_pan,
                handle->fader);
        }
        fn_8005A628();
    }

    AXRNA_SetAdjsfreqFlg(handle, lbl_80190C80);
    axrna_set_source_type(handle, lbl_80132558);
    handle->sample_rate_state = 0;
    AXRNA_SetSfreq(handle, 48000);
    AXRNA_SetBitPerSmpl(handle, 16);
    if (handle->allocated_channels == 2) {
        AXRNA_SetOutPan(handle, 0, -15);
        AXRNA_SetOutPan(handle, 1, 15);
    } else {
        AXRNA_SetOutPan(handle, 0, 0);
    }
    handle->switches = 0;
    handle->used = 1;
    return handle;
}
