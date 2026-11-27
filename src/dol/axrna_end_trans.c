#include "types.h"

/* --- dol/axrna_end_trans.c --- */
/* --- dol/axrna_end_trans.c --- */
typedef void (*fn_8005ADBC_Fn)(void *obj, u32 slot, void *ptr);

struct fn_8005ADBC_ObjectVtable {
    u8 pad_0[0x20];
    fn_8005ADBC_Fn fn;
};

struct fn_8005ADBC_Object {
    struct fn_8005ADBC_ObjectVtable *vtable;
};

struct fn_8005ADBC_Entry {
    u8 pad_0[0x3];
    s8 unk_3;
    u8 pad_4[0x2C];
    struct fn_8005ADBC_Object *obj_30[2];
    struct fn_8005ADBC_Object *obj_38[2];
    u8 item_40[2][8];
    u8 item_50[2][8];
    s32 unk_60[2];
    u32 unk_68;
    u32 unk_6C;
    u8 pad_70[0x78];
};

struct fn_8005ADBC_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

extern struct fn_8005ADBC_Entry axrna_obj[];

#pragma opt_propagation off
void axrna_end_trans(struct fn_8005ADBC_Arg0 *arg0) {
    u32 value;
    u32 index_bits;
    u32 sign;
    struct fn_8005ADBC_Entry *entry;
    s32 slot;
    u32 slot4;
    u8 *pair;
    s32 *state;

    value = arg0->unk_4;
    index_bits = value & 0x7FFFFFFF;
    sign = index_bits >> 31;
    entry = &axrna_obj[(s32)(sign + index_bits) >> 1];
    slot = (((value & 1) ^ sign) - sign);
    slot4 = slot << 2;
    state = (s32 *)(slot4 + (u32)((u8 *)entry + 0x60));
    if (*state == 1) {
        pair = (u8 *)entry + (slot << 3);
        entry->obj_30[slot]->vtable->fn(entry->obj_30[slot], 0, pair + 0x40);
        entry->obj_38[slot]->vtable->fn(entry->obj_38[slot], 1, pair + 0x50);
        *state = 0;
        if (slot == entry->unk_3 - 1) {
            entry->unk_6C = entry->unk_6C + entry->unk_68;
        }
    }
}
#pragma opt_propagation reset

/* --- dol/axrna_update_play.c --- */
/* --- dol/axrna_update_play.c --- */
typedef struct SJCK {
    unsigned char *data;
    int len;
} SJCK;

typedef struct SJ_u1_u0 SJ_u1_u0;

typedef struct SJInterface_u1_u0 SJInterface_u1_u0;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface_u1_u0 {
    void *reserved[3];
    void (*destroy)(SJ_u1_u0 *sj);
    const void *(*get_uuid)(SJ_u1_u0 *sj);
    void (*reset)(SJ_u1_u0 *sj);
    void (*get_chunk)(SJ_u1_u0 *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ_u1_u0 *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ_u1_u0 *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ_u1_u0 *sj, int channel);
    int (*is_get_chunk)(SJ_u1_u0 *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ_u1_u0 *sj, SJErrorCallback callback, void *object);
};

struct SJ_u1_u0 {
    const SJInterface_u1_u0 *interface;
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
    SJ_u1_u0 *inputs[2];
    SJ_u1_u0 *buffers[2];
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

extern int axrna_update_pos;

extern int axrna_update_hist[32];

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
    axrna_update_hist[axrna_update_pos++] = current_position;
    if (axrna_update_pos == 32) {
        axrna_update_pos = 0;
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

/* --- dol/AXRNA_GetNumRoom.c --- */
/* --- dol/AXRNA_GetNumRoom.c --- */
typedef u32 (*fn_8005B010_Fn0)(u32, u32);

u32 AXRNA_GetNumRoom(u32 arg0) {
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

/* --- dol/AXRNA_GetNumData.c --- */
typedef u32 (*fn_8005B068_Fn0)(u32, u32);

s32 AXRNA_GetNumData(u32 arg0) {
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

/* --- dol/AXRNA_SetPlaySw.c --- */
typedef struct SJCK_u1 {
    unsigned char *data;
    long len;
} SJCK_u1;

typedef struct SJ_u1 SJ_u1;

typedef struct SJInterface_u1 SJInterface_u1;


struct SJInterface_u1 {
    void *reserved[3];
    void (*destroy)(SJ_u1 *sj);
    const void *(*get_uuid)(SJ_u1 *sj);
    void (*reset)(SJ_u1 *sj);
    void (*get_chunk)(SJ_u1 *sj, long channel, long max_size, SJCK_u1 *chunk);
    void (*unget_chunk)(SJ_u1 *sj, int channel, SJCK_u1 *chunk);
    void (*put_chunk)(SJ_u1 *sj, int channel, SJCK_u1 *chunk);
    int (*get_num_data)(SJ_u1 *sj, int channel);
    int (*is_get_chunk)(SJ_u1 *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ_u1 *sj, SJErrorCallback callback, void *object);
};

struct SJ_u1 {
    const SJInterface_u1 *interface;
};

















typedef struct AXRNAHandle_u1 {
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
    SJCK_u1 input_chunks[2];
    SJCK_u1 buffer_chunks[2];
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
} AXRNAHandle_u1;

void AXRNA_SetPlaySw(AXRNAHandle_u1 *handle, int enabled);

void fn_80023168(AXVPB *voice, unsigned short state);

void fn_80023284(AXVPB *voice, AXPBADDR *address);

void fn_8005A648(void);

void fn_8005A628(void);

void fn_8005A5BC(const char *message);

static inline int axrna_get_play_switch(const AXRNAHandle_u1 *handle) {
    if (handle == 0) {
        return -1;
    }
    return (handle->switches >> 1) & 1;
}

void AXRNA_SetPlaySw(AXRNAHandle_u1 *handle, int enabled) {
    AXPBADDR address;
    s32 last;
    s32 loop;
    s32 current;
    int channel;
    if (handle == 0) {
        return;
    }
    if (enabled == axrna_get_play_switch(handle)) {
        return;
    }
    fn_8005A648();
    if (enabled == 1) {
        handle->play_position = -1;
        for (channel = 0; channel < handle->num_channels; channel++) {
            if (handle->voices[channel] != 0) {
                last = handle->buffer_size - 1;
                loop = handle->aram_addresses[channel];
                current = handle->aram_addresses[channel];
                address.loopFlag = 1;
                address.format = 10;
                address.loopAddressHi = loop >> 16;
                address.loopAddressLo = loop;
                address.endAddressHi = (loop + last) >> 16;
                address.endAddressLo = loop + last;
                address.currentAddressHi = current >> 16;
                address.currentAddressLo = current;
                fn_80023284(handle->voices[channel], &address);
                fn_80023168(handle->voices[channel], 1);
            }
        }
        handle->switches |= 2;
    } else if (enabled == 0) {
        for (channel = 0; channel < handle->num_channels; channel++) {
            if (handle->voices[channel] != 0) {
                fn_80023168(handle->voices[channel], 0);
            }
        }
        for (channel = 0; channel < handle->allocated_channels; channel++) {
            handle->buffers[channel]->interface->reset(handle->buffers[channel]);
        }
        handle->switches &= 1;
    } else {
        fn_8005A5BC("E1070309:Illigal parameter(sw).\n");
    }
    fn_8005A628();
}

/* --- dol/AXRNA_SetTransSw.c --- */
typedef struct SJCK_u2 {
    unsigned char *data;
    long len;
} SJCK_u2;

typedef struct SJ_u2 SJ_u2;

typedef struct SJInterface_u2 SJInterface_u2;


struct SJInterface_u2 {
    void *reserved[3];
    void (*destroy)(SJ_u2 *sj);
    const void *(*get_uuid)(SJ_u2 *sj);
    void (*reset)(SJ_u2 *sj);
    void (*get_chunk)(SJ_u2 *sj, long channel, long max_size, SJCK_u2 *chunk);
    void (*unget_chunk)(SJ_u2 *sj, int channel, SJCK_u2 *chunk);
    void (*put_chunk)(SJ_u2 *sj, int channel, SJCK_u2 *chunk);
    int (*get_num_data)(SJ_u2 *sj, int channel);
    int (*is_get_chunk)(SJ_u2 *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ_u2 *sj, SJErrorCallback callback, void *object);
};

struct SJ_u2 {
    const SJInterface_u2 *interface;
};

















typedef struct AXRNAHandle_u2 {
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
    SJ_u2 *inputs[2];
    SJ_u2 *buffers[2];
    SJCK_u2 input_chunks[2];
    SJCK_u2 buffer_chunks[2];
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
} AXRNAHandle_u2;


// Hardware or OS state can change asynchronously.
const char *const volatile lbl_800927BC = "\nAXRNA Ver.1.02 Build:May  9 2003 17:10:58\n";
static const char *const lbl_800927C4__fzgx_offset_4[] = {
    "OFF",
    "ON ",
};

void *memset(void *dst, int c, unsigned long n);

#pragma section code_type ".fzgxpool"
static const void *fzgx_rodata_layout(int x) {
    if (x == 0) return lbl_800927BC;
    if (x == 1) return lbl_800927C4__fzgx_offset_4;
    if (x == 2) return "E1070309:Illigal parameter(sw).\n";
    return 0;
}
#pragma section code_type ".text"

static inline int axrna_get_transfer_switch(AXRNAHandle_u2 *handle) {
    if (handle == 0) {
        return -1;
    }
    return handle->switches & 1;
}

void AXRNA_SetTransSw(AXRNAHandle_u2 *handle, int enabled) {
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
            memset(&handle->input_chunks[channel], 0, sizeof(SJCK_u2));
            memset(&handle->buffer_chunks[channel], 0, sizeof(SJCK_u2));
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
