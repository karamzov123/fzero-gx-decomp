#include "types.h"


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

void fn_8005A628(void);

extern u32 fn_80057728(void);

void fn_8005A648(void);


// The retail code performs this read even though its value is discarded.

struct fn_8005A668_Arg0 {
    u8 pad_0[0xA0];
    u16 unk_A0;
};

void AXRNA_SetAdjsfreqFlg(struct fn_8005A668_Arg0 *arg0, u32 arg1) {
    if (arg0 == 0) { return; }
    arg0->unk_A0 = arg1;
}

// AXRNA_DiscardData: returns a constant.
int AXRNA_DiscardData(void) {
    return 0;
}

// AXRNA_SetStmHdInfo: returns a constant.
int AXRNA_SetStmHdInfo(void) {
    return 0;
}

struct fn_8005A688_Arg0 {
    u8 pad_0[0x80];
    u32 unk_80;
};

void AXRNA_SetBitPerSmpl(struct fn_8005A688_Arg0 *arg0, u32 arg1) {
    if (arg0 == 0) { return; }
    arg0->unk_80 = arg1;
}

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

void fn_80026EE0(AXVPB *voice, int pan);

extern int axrna_pan_tbl[31];

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
                    fn_80026EE0(voice, axrna_pan_tbl[pan + 15]);
                }
                fn_8005A628();
            }
        }
    }
}

struct fn_80026D90_Arg0;
extern u32 fn_80026D90(struct fn_80026D90_Arg0 *, u32);

struct AXRNAHandle;

void AXRNA_SetOutVol(struct AXRNAHandle *handle, s32 value) {
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
void AXRNA_SetSfreq(AdxtSlot *p, s32 rate) {
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

void AXRNA_SetNumChan(u8 *ptr, u8 value) {
    if (ptr != 0) {
        ptr[3] = value;
    }
}

void AXRNA_ExecHndl(AXRNAHandle *handle);

extern AXRNAHandle axrna_obj[16];

void AXRNA_ExecServer(void) {
    unsigned int i;
    for (i = 0; i < 16; i++) {
        if (axrna_obj[i].used == 1) {
            AXRNA_ExecHndl(&axrna_obj[i]);
        }
    }
}

void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);

void ARQPostRequest(void *request, unsigned long owner, unsigned long type, unsigned long priority,
                    unsigned long source, unsigned long destination, unsigned long length,
                    ARQCallback callback);

void DCFlushRange(void *address, unsigned long length);

void axrna_end_flash(unsigned long request_address);

void axrna_end_trans(unsigned long request_address);

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
                       transfer_size, axrna_end_trans);
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
                       transfer_size, axrna_end_flash);
    }
}

void AXRNA_ExecHndl(AXRNAHandle *handle) {
    if (!handle) {
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

void axrna_end_flash(unsigned long request_address) {
    u32 v;
    s32 a;
    AXRNAHandle *rec;
    s32 idx;
    s32 k;

    v = ((const ARQRequest *)request_address)->owner;
    a = v & 0x7FFFFFFF;
    k = a / 2;
    rec = &axrna_obj[k];
    idx = a % 2;
    if (rec->flash_pending[idx] == 1) {
        SJ *obj = rec->buffers[idx];
        obj->interface->put_chunk(obj, 1, &rec->buffer_chunks[idx]);
        rec->flash_pending[idx] = 0;
        if (idx == rec->num_channels - 1) {
            rec->flash_position += rec->flash_samples;
        }
    }
}
