#include "types.h"

#pragma opt_propagation off

extern u32 lbl_80190178[];
extern u32 lbl_8019017C[];

void fn_8005A588(u32 arg0, u32 arg1);

void fn_8005A59C(void);

// The retail code performs this read even though its value is discarded.
extern volatile u32 lbl_80092528[36];
extern u8 lbl_801324F0[104];

u8 *fn_8005A5A8(void);

typedef void (*fn_8005A5BC_Fn0)(u32, u32);
struct fn_8005A5BC_lbl_80190B70 {
    u32 unk_0;
    u32 unk_4;
    char buffer[1];
};

extern u32 lbl_80190B70[];
extern void strncpy(void *, void *, int);

void fn_8005A5BC(u32 arg0);

extern u32 lbl_80190B74[];

void fn_8005A614(u32 arg0, u32 arg1);

extern void fn_800576DC(void);

void fn_8005A628(void) {
    fn_800576DC();
}

extern u32 fn_80057728(void);

void fn_8005A648(void) {
    fn_80057728();
}

#pragma opt_propagation off

// The retail code performs this read even though its value is discarded.

struct fn_8005A668_Arg0 {
    u8 pad_0[0xA0];
    u16 unk_A0;
};

void fn_8005A668(struct fn_8005A668_Arg0 *arg0, u32 arg1) {
    if (arg0 == 0) { return; }
    arg0->unk_A0 = arg1;
}

// fn_8005A678: returns a constant.
int fn_8005A678(void) {
    return 0;
}

// fn_8005A680: returns a constant.
int fn_8005A680(void) {
    return 0;
}

struct fn_8005A688_Arg0 {
    u8 pad_0[0x80];
    u32 unk_80;
};

void fn_8005A688(struct fn_8005A688_Arg0 *arg0, u32 arg1) {
    if (arg0 == 0) { return; }
    arg0->unk_80 = arg1;
}

typedef struct SJCK {
    unsigned char *data;
    int len;
} SJCK;

typedef struct SJ_u1_u0_u1 SJ_u1_u0_u1;

typedef struct SJInterface_u1_u0_u1 SJInterface_u1_u0_u1;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface_u1_u0_u1 {
    void *reserved[3];
    void (*destroy)(SJ_u1_u0_u1 *sj);
    const void *(*get_uuid)(SJ_u1_u0_u1 *sj);
    void (*reset)(SJ_u1_u0_u1 *sj);
    void (*get_chunk)(SJ_u1_u0_u1 *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ_u1_u0_u1 *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ_u1_u0_u1 *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ_u1_u0_u1 *sj, int channel);
    int (*is_get_chunk)(SJ_u1_u0_u1 *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ_u1_u0_u1 *sj, SJErrorCallback callback, void *object);
};

struct SJ_u1_u0_u1 {
    const SJInterface_u1_u0_u1 *interface;
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
    SJ_u1_u0_u1 *inputs[2];
    SJ_u1_u0_u1 *buffers[2];
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

void fn_80026EE0(AXVPB *voice, int pan);

extern int lbl_8013255C[31];

void AXRNA_SetOutPan(AXRNAHandle *handle, int channel, int pan) {
    AXVPB *voice;
    if (handle != 0) {
        if (channel < handle->allocated_channels) {
            pan = pan < 15 ? pan : 15;
            pan = pan > -15 ? pan : -15;
            if (pan != handle->output_pan[channel]) {
                handle->output_pan[channel] = pan;
                fn_8005A648();
                voice = handle->voices[channel];
                if (voice != 0) {
                    fn_80026EE0(voice, lbl_8013255C[pan + 15]);
                }
                fn_8005A628();
            }
        }
    }
}

struct fn_80026D90_Arg0;
extern u32 fn_80026D90(struct fn_80026D90_Arg0 *, u32);

struct AXRNAHandle;

void fn_8005A74C(struct AXRNAHandle *handle, s32 value) {
    u8 *slot;
    u32 volume;
    s32 i;
    u32 nonpositive;
    u32 channel_volume;
    struct fn_80026D90_Arg0 *voice;

    channel_volume = value;
    if (handle != 0) {
        nonpositive = channel_volume & ((s32)channel_volume >> 31);
        volume = -999;
        if ((s32)nonpositive > -999) {
            volume = nonpositive;
        }
        if ((s32)volume != (s32)*(u32 *)((u8 *)handle + 132)) {
            *(u32 *)((u8 *)handle + 132) = volume;
            i = 0;
            slot = (u8 *)handle;
            while (i < (s8)*(u8 *)((u8 *)handle + 2)) {
                fn_8005A648();
                voice = *(struct fn_80026D90_Arg0 **)(slot + 8);
                if (voice != 0) {
                    channel_volume = volume;
                    fn_80026D90(voice, channel_volume);
                }
                fn_8005A628();
                slot += 4;
                i++;
            }
        }
    }
}
