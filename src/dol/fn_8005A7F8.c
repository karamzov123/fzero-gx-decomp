#include "types.h"

extern void fn_8005A648(void);
extern void fn_8005A628(void);
extern void fn_800230A4(void *, s32);
extern void fn_80023438(void *, void *);

typedef struct AdxtSlot {
    u8 _pad0[2];
    s8 count;
    u8 _pad3[5];
    void *voice[7];
    s32 rate;
    u8 _pad28[0x78];
    s16 flagA0;
    s16 flagA2;
    u32 flagA4;
} AdxtSlot;

#pragma opt_loop_invariants off
void fn_8005A7F8(AdxtSlot *p, s32 rate) {
    s16 sync[7];
    s32 i;
    s32 adj;
    s32 v0;
    u16 v1;

    if (p != 0) {
        p->rate = rate;
        adj = (rate * 1124 + 1124) / 1125;
        v0 = rate / 32000;
        v1 = ((rate << 8) / 125);
        {
    s32 fzgx_loop_i_651;
for (fzgx_loop_i_651 = 0; fzgx_loop_i_651 < p->count; fzgx_loop_i_651++) {
            fn_8005A648();
            if (p->voice[fzgx_loop_i_651] != 0) {
                if (p->flagA0 == 1) {
                    if (rate == 32000 && p->flagA2 == 0 && p != 0) {
                        p->flagA4 = 0;
                        p->flagA2 = 1;
                    }
                    sync[0] = (u16)((u32)adj / 32000);
                    sync[1] = (u16)((u32)(adj << 8) / 125);
                } else {
                    sync[0] = v0;
                    sync[1] = v1;
                }
                sync[2] = 0;
                sync[3] = 0;
                sync[4] = 0;
                sync[5] = 0;
                sync[6] = 0;
                fn_800230A4(p->voice[fzgx_loop_i_651], p->flagA4);
                fn_80023438(p->voice[fzgx_loop_i_651], sync);
            }
            fn_8005A628();
        }
    i = fzgx_loop_i_651;
}
    }
}
#pragma opt_loop_invariants reset

void fn_8005A94C(u8 *ptr, u8 value) {
    if (ptr != 0) {
        ptr[3] = value;
    }
}

typedef struct SJCK {
    unsigned char *data;
    int len;
} SJCK;

typedef struct SJ_u1 SJ_u1;

typedef struct SJInterface_u1 SJInterface_u1;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface_u1 {
    void *reserved[3];
    void (*destroy)(SJ_u1 *sj);
    const void *(*get_uuid)(SJ_u1 *sj);
    void (*reset)(SJ_u1 *sj);
    void (*get_chunk)(SJ_u1 *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ_u1 *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ_u1 *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ_u1 *sj, int channel);
    int (*is_get_chunk)(SJ_u1 *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ_u1 *sj, SJErrorCallback callback, void *object);
};

struct SJ_u1 {
    const SJInterface_u1 *interface;
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
    SJ_u1 *inputs[2];
    SJ_u1 *buffers[2];
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

void fn_8005A9B8(AXRNAHandle *handle);

extern AXRNAHandle lbl_80191D4C[16];

void AXRNA_ExecServer(void) {
    unsigned int i;
    for (i = 0; i < 16; i++) {
        if (lbl_80191D4C[i].used == 1) {
            fn_8005A9B8(&lbl_80191D4C[i]);
        }
    }
}
