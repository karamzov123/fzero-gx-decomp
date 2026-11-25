#include "types.h"
#include "sofdec/sj.h"

typedef struct AdxSjdHandle AdxSjdHandle;
typedef struct ADXStream ADXStream;
typedef struct AXRNAHandle AXRNAHandle;
typedef struct LSCObject LSCObject;
typedef struct ADX_AMP ADX_AMP;

typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 minimum_buffer_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 field_46;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 link_data_length;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle;

enum {
    ADXT_MAX_HANDLES = 16,
    ADXT_STATUS_STOP = 0,
    ADXT_STATUS_DECODING_HEADER = 1,
    ADXT_STATUS_BUFFERING = 2,
    ADXT_STATUS_PLAYING = 3,
    ADXT_STATUS_DRAINING = 4,
    ADXT_STATUS_PLAY_END = 5,
    ADXT_STREAM_TYPE_MEMORY = 2,
    ADXT_STREAM_TYPE_SJ = 3,
    ADXT_STREAM_TYPE_LINKED = 4,
    ADXT_SECTOR_SIZE = 0x800,
    ADXT_INPUT_EXTRA_SIZE = 0x24,
    ADXT_OUTPUT_SIZE = 0x2000,
    ADXT_OUTPUT_DISTANCE = 0x2060,
    ADXT_DEFAULT_PAN = -128
};

struct adx_tlkBss {
    s32 adxt_time_mode;
    s32 adxt_tsvr_enter_cnt;
    s32 adxt_resync_cnt;
    u8 padding_C[0x1C];
    f32 adxt_time_diff;
    s32 adxt_time_unit;
};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") s32 lbl_8017E568;
__declspec(section ".data") s32 lbl_8017E56C;
__declspec(section ".data") s32 lbl_8017E56C__fzgx_offset_4;
__declspec(section ".data") u32 lbl_8017E56C__fzgx_offset_8[6];
__declspec(section ".data") u32 lbl_8017E58C;
__declspec(section ".data") f32 lbl_8017E58C__fzgx_offset_4;
__declspec(section ".data") s32 lbl_8017E594;
__declspec(section ".data") u32 lbl_8017E594__fzgx_offset_4[4];
__declspec(section ".data") u32 lbl_8017E5A8[4];
__declspec(section ".data") u32 lbl_8017E5B8;

extern ADXTHandle lbl_80178CBC[16];
extern s32 lbl_80178CB8[];
extern u32 lbl_8012B910[];
extern const char lbl_80090A28[];
extern const char lbl_80090A58[];
extern const char lbl_80090A80[];
extern const char lbl_80090B9C[];
extern const char lbl_80090C60[];
extern const char lbl_80090C88[];
extern const char lbl_80090CB4[];
extern const char lbl_80090DA0[];
extern const char lbl_80090DCC[];
extern const char lbl_80090DF8[];
extern const char lbl_80090E84[];
extern const char lbl_80090EB0[];
extern const char lbl_80090EDC[];
extern const char lbl_80090F60[];
extern const char lbl_80090FC4[];
extern const char lbl_80090FEC[];
extern const char lbl_80091014[];
extern const char lbl_8009103C[];
extern const f32 lbl_80091064[];
extern const char lbl_80091068[];

extern void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);
extern void *memset(void *destination, int value, unsigned long size);
extern s32 fn_80046C28(u32 arg0, u32 arg1, s16 *arg2, u8 *arg3, u8 *arg4, u8 *arg5, u8 *arg6, u32 *arg7, u32 *arg8, u32 *arg9);
extern void fn_80046738(void);
extern void fn_80046718(void);
extern void fn_80041700(void);
extern void fn_8004EE44(void);
extern s32 fn_8004ED84(AXRNAHandle *rna, s32 samples);
extern void fn_8004D220(ADXTHandle *handle);
extern u32 fn_80047548(void);
extern void fn_800474E4(const char *message);
extern void fn_8004EEA4(AXRNAHandle *rna, s32 enabled);
extern void fn_8004EEC4(AXRNAHandle *rna, s32 enabled);
extern void fn_8004EEE4(AXRNAHandle *rna);
extern s32 fn_8004EE84(AXRNAHandle *rna);
extern AXRNAHandle *fn_8004EF28(SJ **, s32, void *);
extern s32 fn_800414D0(AdxSjdHandle *decoder);
extern void fn_8004EDE4(AXRNAHandle *rna, s32 vol);
extern s16 fn_80041460(AdxSjdHandle *decoder, s32 channel);
extern void fn_8004EDC4(AXRNAHandle *rna, s32 channel, s32 pan);
extern s32 fn_80041660(AdxSjdHandle *decoder);
extern s32 fn_80041684(AdxSjdHandle *decoder);
extern s32 fn_800415F4(AdxSjdHandle *decoder);
extern s32 fn_8004163C(AdxSjdHandle *decoder);
extern s32 fn_800416F8(AdxSjdHandle *decoder);
extern void fn_800420F4(AdxSjdHandle *decoder);
extern void fn_8004212C(AdxSjdHandle *decoder);
extern void fn_80042198(AdxSjdHandle *decoder, SJ *input);
extern void fn_800421CC(AdxSjdHandle *decoder);
extern AdxSjdHandle *fn_80042228(SJ *, s32, SJ **);
extern void fn_8004B0EC(ADXStream *stream);
extern void fn_8004B1DC(ADXStream *stream);
extern ADXStream *fn_8004B4E0(SJ *, s32);
extern void fn_8004A550(ADXStream *, s32, s32);
extern u32 fn_8004AC04(ADXStream *, u32);
extern u32 fn_8004AC4C(ADXStream *, u32, u32);
extern u32 fn_8004AE94(ADXStream *, u32);
extern void fn_8004AD84(ADXStream *);
extern void fn_8004B180(ADXStream *, u32, u32, u32, u32);
extern s32 fn_8004ADF4(ADXStream *);
extern void fn_80056CD0(LSCObject *controller);
extern void fn_8005710C(LSCObject *, ADXStream *);
extern u32 fn_80057114(LSCObject *);
extern LSCObject *fn_800571EC(SJ *);
extern void fn_80046510(ADX_AMP *amplifier);
extern void ADXAMP_Start(ADX_AMP *amplifier);
extern u32 fn_800466D4(ADX_AMP *);
extern SJ *fn_80058498(void *, s32, s32);
extern void strcpy(void *, void *);

extern void fzgx_sink(const char *s);
extern void fzgx_sinkf(f32 f);
extern s32 fzgx_int;

void fn_8004C164(ADXTHandle *handle, s32 *count, s32 *scale);
void ADXT_Stop(ADXTHandle *handle);
void fn_8004CAC8(ADXTHandle *arg0);

#pragma readonly_strings on
#pragma section sconst_type ".rodata" ".rodata" data_mode=far_abs

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_8017E568;
    s = *(u8 *)&lbl_8017E56C;
    s = *(u8 *)&lbl_8017E56C__fzgx_offset_4;
    s = *(u8 *)&lbl_8017E56C__fzgx_offset_8;
    s = *(u8 *)&lbl_8017E58C;
    s = *(u8 *)&lbl_8017E58C__fzgx_offset_4;
    s = *(u8 *)&lbl_8017E594;
    s = *(u8 *)&lbl_8017E594__fzgx_offset_4;
    s = *(u8 *)&lbl_8017E5A8;
    s = *(u8 *)&lbl_8017E5B8;
}
#pragma section code_type ".text"

#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(void) {
    fzgx_sink("E02080860 ADXT_SetKeyString: parameter error");
    fzgx_sink("E02080818 ADXT_GetDecNumSmpl: parameter error");
    fzgx_sinkf(fzgx_int);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer2(void) {
    fzgx_sink("E02080847 ADXT_GetStatPause: parameter error");
    fzgx_sink("E02080846 ADXT_Pause: parameter error");
    fzgx_sink("E02080831 ADXT_IsReadyPlayStart: parameter error");
    fzgx_sink("E02080830 ADXT_SetWaitPlayStart: parameter error");
    fzgx_sink("E02080833 ADXT_GetInputSj: parameter error");
    fzgx_sink("E02080828 ADXT_SetLpFlg: parameter error");
    fzgx_sink("E02080829 ADXT_GetLpCnt: parameter error");
    fzgx_sink("E02080844 ADXT_ClearErrCode: parameter error");
    fzgx_sink("E02080843 ADXT_GetErrCode: parameter error");
    fzgx_sink("E02080802 ADXT_IsCompleted: parameter error");
    fzgx_sink("E02080836 ADXT_IsIbufSafety: parameter error");
    fzgx_sinkf(0.0f);
    fzgx_sink("E02080835 ADXT_GetIbufRemainTime: parameter error");
    fzgx_sinkf(-1.0f);
    fzgx_sink("E02080814 ADXT_GetStat: parameter error");
    fzgx_sink("E02080820 ADXT_GetNumChan: parameter error");
    fzgx_sink("E02080819 ADXT_GetSfreq: parameter error");
    fzgx_sink("E02080837 ADXT_GetNumSmplObuf: parameter error");
    fzgx_sink("E02080834 ADXT_GetNumSctIbuf: parameter error");
    fzgx_sink("E02080839 ADXT_SetReloadSct: parameter error");
    fzgx_sink("E02080838 ADXT_SetReloadTime: parameter error");
    fzgx_sink("E02080840 ADXT_SetSvrFreq: parameter error");
    fzgx_sink("E02080824 ADXT_GetOutVol: parameter error");
    fzgx_sink("E02080823 ADXT_SetOutVol: parameter error");
    fzgx_sink("E02080871 ADXT_GetOutBalance: parameter error");
    fzgx_sink("E02080870 ADXT_SetOutBalance: parameter error");
    fzgx_sink("E02080826 ADXT_GetOutPan: parameter error");
    fzgx_sink("E02080825 ADXT_SetOutPan: parameter error");
    fzgx_sink("E8101208 ADXT_SetOutPan: parameter error");
    fzgx_sink("E02080821 ADXT_GetFmtBps: parameter error");
    fzgx_sink("E02080822 ADXT_GetHdrLen: parameter error");
    fzgx_sink("E02080817 ADXT_GetNumSmpl: parameter error");
    fzgx_sinkf(100.0f);
    fzgx_sink("E02080815 ADXT_GetTime: parameter error");
    fzgx_sinkf(1000.0f);
    fzgx_sinkf(60.0f);
    fzgx_sinkf(-60.0f);
}

s32 ADXT_InsertSilence(ADXTHandle *handle, s32 channels, s32 samples) {
    s32 requested_bytes;
    SJ *sj;
    s32 block_bytes;
    s32 usable_bytes;
    s32 written_bytes;
    SJCK chunk;
    SJCK remainder;
    sj = handle->input_sj;
    if (handle->input_sj == 0) {
        return 0;
    }
    block_bytes = channels * 18;
    requested_bytes = (samples / 32) * block_bytes;
    sj->interface->get_chunk(sj, 0, requested_bytes, &chunk);
    usable_bytes = (chunk.len / block_bytes) * block_bytes;
    memset(chunk.data, 0, usable_bytes);
    fn_800589BC(&chunk, usable_bytes, &chunk, &remainder);
    written_bytes = usable_bytes;
    sj->interface->put_chunk(sj, 1, &chunk);
    sj->interface->unget_chunk(sj, 0, &remainder);
    requested_bytes -= written_bytes;
    sj->interface->get_chunk(sj, 0, requested_bytes, &chunk);
    usable_bytes = (chunk.len / block_bytes) * block_bytes;
    memset(chunk.data, 0, usable_bytes);
    fn_800589BC(&chunk, usable_bytes, &chunk, &remainder);
    sj->interface->put_chunk(sj, 1, &chunk);
    sj->interface->unget_chunk(sj, 0, &remainder);
    return ((written_bytes + usable_bytes) / block_bytes) * 32;
}

s32 ADXT_IsEndcode(u32 arg0, u32 arg1, u32 *arg2) {
    u32 v0;
    v0 = arg0;
    if ((s32)arg1 < 2) {
        v0 = 0;
        return v0;
    }
    if (*(u16 *)(v0) != 32769) {
        v0 = 0;
        return v0;
    }
    *arg2 = arg1;
    v0 = 1;
    return v0;
}

s32 ADXT_IsHeader(u32 arg0, s32 arg1, s32 *arg2) {
    u32 local_20;
    u32 local_1c;
    u32 local_18;
    s16 local_14;
    u8 local_13;
    u8 local_12;
    u8 local_11;
    u8 local_10;

    if (arg1 < 2) {
        return 0;
    }
    if (*(u16 *)arg0 != 32768) {
        return 0;
    }
    if (fn_80046C28(arg0, arg1, &local_14, &local_13, &local_12, &local_11, &local_10, &local_20, &local_1c, &local_18) < 0) {
        return 0;
    }
    *arg2 = local_14;
    return 1;
}

void ADXT_SetTimeOfst(ADXTHandle *arg0, s32 arg1) {
    arg0->time_offset = arg1;
}

static inline void adxt_ExecServers(void) {
    ADXTHandle *entry;
    s32 index;

    fn_80046738();
    if (lbl_8017E56C != 0) {
        fn_80046718();
        return;
    }
    lbl_8017E56C = 1;
    fn_80046718();
    fn_80046738();
    fn_80041700();
    lbl_8017E56C = 2;
    entry = lbl_80178CBC;
    for (index = 0; index < ADXT_MAX_HANDLES; index++, entry++) {
        if (entry->used == 1) {
            fn_8004D220(entry);
        }
    }
    lbl_8017E56C = 3;
    fn_8004EE44();
    lbl_8017E56C = 0;
    fn_80046718();
}

s32 fn_8004BA40(ADXTHandle *handle, s32 samples) {
    s32 discarded;
    s32 count;
    s32 scale;
    s32 saved_time_mode;
    if (handle->paused == 0) {
        return 0;
    }
    discarded = fn_8004ED84(handle->rna, samples);
    adxt_ExecServers();
    saved_time_mode = lbl_8017E568;
    lbl_8017E568 = 0;
    fn_8004C164(handle, &count, &scale);
    lbl_8017E568 = saved_time_mode;
    handle->playback_time = (lbl_8017E594 * ((f32)count / scale));
    handle->playback_start_vsync = lbl_80178CB8[0];
    return discarded;
}

void fn_8004BBA4(void) {
    fn_80047548();
}

void fn_8004BBC4(void) {
}

void fn_8004BBC8(void) {
}

s32 fn_8004BBCC(ADXTHandle *object) {
    if (object == 0) {
        fn_800474E4(lbl_80090A28);
        return 0;
    }
    return object->paused;
}

#pragma use_lmw_stmw off
void ADXT_Pause(ADXTHandle *handle, s32 paused) {
    s32 status;
    s32 count;
    s32 scale;
    s32 saved_time_mode;
    if (handle == 0) {
        fn_800474E4(lbl_80090A58);
        return;
    }
    status = handle->status;
    if (paused == handle->paused) {
        return;
    }
    fn_80046738();
    handle->paused = paused;
    if (status == ADXT_STATUS_PLAYING || status == ADXT_STATUS_DRAINING) {
        if (paused == 1) {
            fn_8004EEA4(handle->rna, 0);
        } else {
            fn_8004EEA4(handle->rna, 1);
            handle->playback_start_vsync = lbl_80178CB8[0];
        }
        saved_time_mode = lbl_8017E568;
        lbl_8017E568 = 0;
        fn_8004C164(handle, &count, &scale);
        lbl_8017E568 = saved_time_mode;
        handle->playback_time = (u32)((f32)lbl_8017E594 * ((f32)count / (f32)scale));
    }
    fn_80046718();
}
#pragma use_lmw_stmw reset

s32 fn_8004BD5C(ADXTHandle *arg0) {
    if (arg0 == 0) {
        fn_800474E4(lbl_80090A80);
        return -1;
    }
    return arg0->decoder_ready;
}

s32 fn_8004BD9C(ADXTHandle *arg0) {
    if (arg0 == 0) {
        fn_800474E4(lbl_80090B9C);
        return -1;
    }
    return arg0->error_code;
}

void fn_8004BDD8(void) {
    s32 index;

    fn_80046738();
    if (lbl_8017E56C != 0) {
        fn_80046718();
    } else {
        lbl_8017E56C = 1;
        fn_80046718();
        fn_80046738();
        fn_80041700();
        lbl_8017E56C = 2;
        for (index = 0; index < 16; index++) {
            if (lbl_80178CBC[index].used == 1) {
                fn_8004D220(&lbl_80178CBC[index]);
            }
        }
        lbl_8017E56C = 3;
        fn_8004EE44();
        lbl_8017E56C = 0;
        fn_80046718();
    }
}

void fn_8004BE90(ADXTHandle *arg0, u32 arg1) {
    arg0->auto_receiver = arg1;
}

void fn_8004BE98(ADXTHandle *arg0, s32 arg1) {
    if (arg0 == 0) {
        fn_800474E4(lbl_80090DA0);
    } else {
        arg0->server_frequency = arg1;
    }
}

s32 fn_8004BED0(ADXTHandle *arg0) {
    if (arg0 == 0) {
        fn_800474E4(lbl_80090DCC);
        return 0;
    }
    return arg0->output_volume;
}

void fn_8004BF0C(ADXTHandle *arg0, s32 arg1) {
    if (arg0 == 0) {
        fn_800474E4(lbl_80090DF8);
    } else {
        s16 def_vol;
        arg0->output_volume = arg1;
        def_vol = fn_800414D0(arg0->decoder);
        fn_8004EDE4(arg0->rna, arg0->output_volume + def_vol);
    }
}

s16 fn_8004BF68(ADXTHandle *arg0, s32 arg1) {
    if (arg0 == 0) {
        fn_800474E4(lbl_80090E84);
        return 0;
    }
    return arg0->output_pan[arg1];
}

void ADXT_SetOutPan(ADXTHandle *handle, s32 channel, s32 pan) {
    s16 default_pan;
    if (handle == 0) {
        fn_800474E4(lbl_80090EB0);
        return;
    }
    default_pan = fn_80041460(handle->decoder, channel);
    if (default_pan == ADXT_DEFAULT_PAN) {
        default_pan = 0;
    }
    handle->output_pan[channel] = pan + default_pan;
    if (channel < handle->maximum_channels) {
        fn_8004EDC4(handle->rna, channel, pan);
    } else {
        fn_800474E4(lbl_80090EDC);
    }
}

s32 fn_8004C05C(ADXTHandle *arg0) {
    if (arg0 == 0) {
        fn_800474E4(lbl_80090C88);
        return -1;
    }
    if (arg0->status >= 2) {
        return fn_80041660(arg0->decoder);
    }
    return 0;
}

s32 fn_8004C0B4(ADXTHandle *arg0) {
    if (arg0 == 0) {
        fn_800474E4(lbl_80090CB4);
        return -1;
    }
    if (arg0->status >= 2) {
        return fn_80041684(arg0->decoder);
    }
    return 0;
}

s32 fn_8004C10C(ADXTHandle *arg0) {
    if (arg0 == 0) {
        fn_800474E4(lbl_80090F60);
        return -1;
    }
    if (arg0->status >= 2) {
        return fn_800415F4(arg0->decoder);
    }
    return 0;
}

static inline s32 adxt_GetNumSmplObuf(ADXTHandle *handle) {
    SJ *sj;
    if (handle == 0) {
        fn_800474E4("E02080837 ADXT_GetNumSmplObuf: parameter error");
        return -1;
    }
    sj = handle->output_sj[0];
    if (sj != 0) {
        return sj->interface->get_num_data(sj, 1) / 2;
    }
    return 0;
}

static inline void adxt_GetTimeSub(ADXTHandle *handle, s32 *count, s32 *scale) {
    s32 status = handle->status;
    if (status == 3 || status == 4) {
        s32 decoded;
        *scale = fn_80041684(handle->decoder);
        decoded = fn_800416F8(handle->decoder);
        *count = handle->linked_decoded_samples + (decoded - (fn_8004EE84(handle->rna) + adxt_GetNumSmplObuf(handle)));
    } else if (status == 5) {
        *count = fn_800415F4(handle->decoder);
        *scale = fn_80041684(handle->decoder);
        *count = *count * (16 / fn_8004163C(handle->decoder));
        *count = *count + handle->linked_decoded_samples;
    } else {
        *count = 0;
        *scale = 1;
    }
    *count += handle->time_offset;
}

void fn_8004C164(ADXTHandle *handle, s32 *count, s32 *scale) {
    s32 count2;
    s32 scale2;
    s32 status;
    f32 diff;

    if (handle == 0 || count == 0 || scale == 0) {
        fn_800474E4("E02080815 ADXT_GetTime: parameter error");
        return;
    }
    if (lbl_8017E568 == 0) {
        adxt_GetTimeSub(handle, count, scale);
        return;
    }
    lbl_8017E58C__fzgx_offset_4 = 0.0f;
    status = handle->status;
    if (status == 3 || status == 4) {
        if (handle->paused == 0) {
            *count = handle->playback_time + (lbl_80178CB8[0] - handle->playback_start_vsync) * 100;
        } else {
            *count = handle->playback_time;
        }
        adxt_GetTimeSub(handle, &count2, &scale2);
        diff = 1000.0f * ((f32)count2 / scale2 - (f32)*count / lbl_8017E594);
        lbl_8017E58C__fzgx_offset_4 = diff;
        if (diff > 60.0f || diff < -60.0f) {
            if (lbl_8012B910[0] == 1) {
                s32 saved = lbl_8017E568;
                lbl_8017E568 = 0;
                fn_8004C164(handle, &count2, &scale2);
                lbl_8017E568 = saved;
                lbl_8017E56C__fzgx_offset_4++;
            }
            handle->playback_time = (lbl_8017E594 * ((f32)count2 / scale2));
            handle->playback_start_vsync = lbl_80178CB8[0];
        }
    } else if (status == 5) {
        count2 = fn_800415F4(handle->decoder);
        scale2 = fn_80041684(handle->decoder);
        count2 = count2 * (16 / fn_8004163C(handle->decoder));
        *count = (s32)((f32)lbl_8017E594 * ((f32)count2 / (f32)scale2));
        *count = ((*count) + ((handle->playback_time) + (1)));
    } else {
        *count = 0;
    }
    *count += handle->time_offset;
    *scale = lbl_8017E594;
}

s32 fn_8004C658(ADXTHandle *arg0) {
    if (!arg0) {
        fn_800474E4(lbl_80090C60);
        return -1;
    }
    return arg0->status;
}

static inline void ADXT_Stop_inline(ADXTHandle *handle) {
    SJ *input;
    if (handle == 0) {
        fn_800474E4(lbl_80090FC4);
        return;
    }
    if (handle->stream != 0) {
        fn_8004B0EC(handle->stream);
    }
    fn_80046738();
    if (handle->stream_type == ADXT_STREAM_TYPE_LINKED) {
        fn_80056CD0(handle->linked_stream_controller);
        if (handle->input_sj != 0) {
            handle->input_sj->interface->reset(handle->input_sj);
        }
    }
    fn_80046738();
    fn_8004EEC4(handle->rna, 0);
    fn_8004EEA4(handle->rna, 0);
    fn_800420F4(handle->decoder);
    if (handle->stream_type == ADXT_STREAM_TYPE_MEMORY && handle->input_sj != 0) {
        input = handle->input_sj;
        handle->input_sj = 0;
        input->interface->destroy(input);
    }
    if (handle->amplifier != 0) {
        fn_80046510(handle->amplifier);
    }
    handle->input_sj = 0;
    handle->status = ADXT_STATUS_STOP;
    handle->pending_stream_start = 0;
    fn_80046718();
    fn_80046718();
}

void ADXT_Stop(ADXTHandle *handle) {
    ADXT_Stop_inline(handle);
}

#pragma use_lmw_stmw off
void fn_8004C794(ADXTHandle *handle, SJ *input) {
    s32 channel;
    ADXTHandle *cursor;
    if (handle == 0 || input == 0) {
        fn_800474E4(lbl_80090FEC);
        return;
    }
    ADXT_Stop_inline(handle);
    fn_80046738();
    cursor = handle;
    for (channel = 0; channel < handle->maximum_channels; channel++) {
        cursor->output_sj[0]->interface->reset(cursor->output_sj[0]);
        cursor = (ADXTHandle *)((u8 *)cursor + 4);
    }
    fn_80042198(handle->decoder, input);
    handle->input_sj = input;
    fn_8004212C(handle->decoder);
    handle->status = ADXT_STATUS_DECODING_HEADER;
    handle->loop_count = 0;
    handle->decoder_ready = 0;
    handle->eos_sector = 0x7FFFFFFF;
    handle->loop_sample_count = -1;
    handle->playback_time = 0;
    handle->linked_decoded_samples = 0;
    handle->playback_start_vsync = lbl_80178CB8[0];
    if (handle->amplifier != 0) {
        ADXAMP_Start(handle->amplifier);
    }
    handle->stream_type = ADXT_STREAM_TYPE_SJ;
    handle->link_enabled = 1;
    if (handle->decoder != 0) {
    }
    fn_80046718();
}
#pragma use_lmw_stmw reset

void fn_8004C980(ADXTHandle *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    s32 v2;
    SJ *v0;
    ADXTHandle *v1;
    u32 v3;
    ADX_AMP *v4;

    fn_8004A550(arg0->stream, arg0->minimum_buffer_sectors << 11, arg0->stream_buffer_sectors << 11);
    fn_8004AC04(arg0->stream, 25);
    fn_8004AC4C(arg0->stream, 0, 0);
    fn_8004AE94(arg0->stream, 0);
    fn_8004AD84(arg0->stream);
    fn_8004B0EC(arg0->stream);
    fn_8004B180(arg0->stream, arg1, arg2, arg3, arg4);
    fn_8004ADF4(arg0->stream);
    v0 = arg0->stream_sj;
    v1 = arg0;
    v2 = 0;
    while (v2 < arg0->maximum_channels) {
        v1->output_sj[0]->interface->reset(v1->output_sj[0]);
        v1 = (ADXTHandle *)((u8 *)v1 + 4);
        v2++;
    }
    fn_80042198(arg0->decoder, v0);
    arg0->input_sj = v0;
    fn_8004212C(arg0->decoder);
    arg0->status = 1;
    v3 = (0x80000000 - 1);
    arg0->loop_count = 0;
    arg0->decoder_ready = 0;
    arg0->eos_sector = v3;
    arg0->loop_sample_count = -1;
    arg0->playback_time = 0;
    arg0->linked_decoded_samples = 0;
    arg0->playback_start_vsync = lbl_80178CB8[0];
    v4 = arg0->amplifier;
    if (v4 != 0) {
        ADXAMP_Start(v4);
    }
}

void fn_8004CAC8(ADXTHandle *arg0) {
    ADXTHandle *v7;
    ADXStream *v4;
    s32 v6;
    if (arg0 == 0) {
        fn_800474E4(lbl_80091014);
    } else {
        u32 v1 = lbl_8017E58C;
        if (v1) {
            ((u32 (*)(ADXTHandle *))v1)(arg0);
        }
        if (arg0->used == 1) {
            ADXT_Stop_inline(arg0);
        }
        if (arg0->rna != 0) {
            AXRNAHandle *rna = arg0->rna;
            arg0->rna = 0;
            fn_8004EEE4(rna);
        }
        if (arg0->decoder != 0) {
            AdxSjdHandle *dec = arg0->decoder;
            arg0->decoder = 0;
            fn_800421CC(dec);
        }
        v4 = arg0->stream;
        if (v4 != 0) {
            arg0->stream = 0;
            fn_8004AC4C(v4, 0, 0);
            fn_8004B1DC(v4);
        }
        if (arg0->linked_stream_controller != 0) {
            LSCObject *lsc = arg0->linked_stream_controller;
            arg0->linked_stream_controller = 0;
            fn_80057114(lsc);
        }
        fn_80046738();
        if (arg0->stream_sj != 0) {
            SJ *sj = arg0->stream_sj;
            arg0->stream_sj = 0;
            sj->interface->destroy(sj);
        }
        v6 = 0;
        v7 = arg0;
        while (v6 < arg0->maximum_channels) {
            if (v7->output_sj[0] != 0) {
                SJ *sj = v7->output_sj[0];
                v7->output_sj[0] = 0;
                sj->interface->destroy(sj);
            }
            if (v7->amplifier_input[0] != 0) {
                SJ *sj = v7->amplifier_input[0];
                v7->amplifier_input[0] = 0;
                sj->interface->destroy(sj);
            }
            if (v7->amplifier_output[0] != 0) {
                SJ *sj = v7->amplifier_output[0];
                v7->amplifier_output[0] = 0;
                sj->interface->destroy(sj);
            }
            v7 = (ADXTHandle *)((u8 *)v7 + 4);
            v6++;
        }
        if (arg0->amplifier != 0) {
            ADX_AMP *amp = arg0->amplifier;
            arg0->amplifier = 0;
            fn_800466D4(amp);
        }
        memset(arg0, 0, 192);
        arg0->used = 0;
        fn_80046718();
    }
}

ADXTHandle *fn_8004CD70(s32 arg0, void *arg1, s32 arg2) {
    ADXTHandle *v2;
    u8 *v0 = (u8 *)(((u32)arg1 + 63) & ~0x3F);
    s32 v1 = arg2 - (v0 - (u8 *)arg1);
    s32 channels = arg0;
    s32 v5;
    s32 v17;
    if (channels < 0 || arg1 == 0 || arg2 < 0) {
        fn_800474E4(lbl_8009103C);
        return 0;
    }
    for (v5 = 0; v5 < 16; v5++) {
        if (lbl_80178CBC[v5].used == 0) break;
    }
    if (v5 == 16) return 0;
    v2 = &lbl_80178CBC[v5];
    memset(v2, 0, 192);
    v2->maximum_channels = channels;
    v2->input_buffer = v0 + ((channels * 12384) << 1);
    v2->input_buffer_size = ((v1 - ((channels * 12384) << 1) - 292) / 2048) << 11;
    v2->input_extra_size = 36;
    {
        u8 *base = v2->input_buffer;
        s32 extra = v2->input_extra_size;
        s32 size = v2->input_buffer_size;
        v2->work_end = (size + extra + base);
    }
    v2->output_buffer = v0;
    v2->output_buffer_size = 8192;
    v2->output_buffer_distance = 8288;
    v2->input_sj = 0;
    v2->stream_sj = fn_80058498(v2->input_buffer, v2->input_buffer_size, v2->input_extra_size);
    if (v2->stream_sj == 0) { fn_8004CAC8(v2); return 0; }
    if ((v2->stream = fn_8004B4E0(v2->stream_sj, 0)) == 0) { fn_8004CAC8(v2); return 0; }
    for (v17 = 0; v17 < channels; v17++) {
        v2->output_sj[v17] = fn_80058498(v2->output_buffer + ((v2->output_buffer_distance * v17) << 1),
                                         v2->output_buffer_size << 1, (v2->output_buffer_distance - v2->output_buffer_size) << 1);
        if (v2->output_sj[v17] == 0) { fn_8004CAC8(v2); return 0; }
    }
    if ((v2->decoder = fn_80042228(v2->stream_sj, channels, v2->output_sj)) == 0) { fn_8004CAC8(v2); return 0; }
    if ((v2->rna = fn_8004EF28(v2->output_sj, channels, v0 + channels * 16576)) == 0) { fn_8004CAC8(v2); return 0; }
    if ((v2->linked_stream_controller = fn_800571EC(v2->stream_sj)) == 0) { fn_8004CAC8(v2); return 0; }
    fn_8005710C(v2->linked_stream_controller, v2->stream);
    v2->server_frequency = 60;
    v2->stream_buffer_sectors = v2->input_buffer_size / 2048;
    v2->minimum_buffer_sectors = (lbl_80091064[0] * v2->stream_buffer_sectors);
    v2->output_volume = 0;
    for (v17 = 0; v17 < channels; v17++) v2->output_pan[v17] = -128;
    v2->field_46 = 0;
    v2->stream_loop_enabled = 1;
    v2->field_54 = 0;
    v2->field_58 = 0;
    v2->field_5C = 0;
    v2->error_code = 0;
    v2->field_64 = 0;
    v2->field_68 = 0;
    v2->field_6A = 0;
    v2->auto_receiver = 1;
    v2->paused = 0;
    v2->time_offset = 0;
    v2->link_enabled = 0;
    v2->used = 1;
    return v2;
}

void fn_8004D18C(ADXTHandle *arg0, char *arg1) {
    if (arg0 == 0 || arg1 == 0) {
        fn_800474E4(lbl_80091068);
    } else {
        ADXT_Stop(arg0);
        strcpy(arg0->work_end, arg1);
        arg0->pending_filename = (const char *)arg0->work_end;
        arg0->pending_directory = 0;
        arg0->pending_file_offset = 0;
        arg0->pending_file_sectors = 0xFFFFF;
        arg0->status = 1;
        arg0->pending_stream_start = 1;
        arg0->stream_type = 0;
        arg0->link_enabled = 0;
    }
}
