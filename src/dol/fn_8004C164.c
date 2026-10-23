#include "types.h"
/* begin sofdec/adxt.h (deltawave784/fzgx, CC0) */
#ifndef SOFDEC_ADXT_H
#define SOFDEC_ADXT_H

/* CRI ADX talker (ADXT) handle, shared by the ADXT_* / adxt_* units of the DOL. */

#include "sofdec/sj.h"
/* begin layout_check.h (deltawave784/fzgx, CC0) */
#ifndef LAYOUT_CHECK_H
#define LAYOUT_CHECK_H

/* Compile-time layout checks for owned types. They declare array typedefs
 * only, so they emit no code or data under MWCC: a wrong size or offset is
 * a negative array bound and fails the compile. */
#define LAYOUT_CHECK_JOIN2(a, b) a##b
#define LAYOUT_CHECK_JOIN(a, b) LAYOUT_CHECK_JOIN2(a, b)
#define CHECK_SIZE(T, size) \
    typedef char LAYOUT_CHECK_JOIN(layout_size_, T)[(sizeof(T) == (size)) ? 1 : -1]
#define CHECK_OFFSET(T, field, offset) \
    typedef char LAYOUT_CHECK_JOIN(LAYOUT_CHECK_JOIN(layout_offset_, T), __LINE__) \
        [((unsigned long)&((T *)0)->field == (offset)) ? 1 : -1]

#endif

/* end layout_check.h */

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

CHECK_OFFSET(ADXTHandle, decoder, 0x4);
CHECK_OFFSET(ADXTHandle, output_volume, 0x40);
CHECK_OFFSET(ADXTHandle, error_code, 0x60);
CHECK_OFFSET(ADXTHandle, stream_loop_enabled, 0x6C);
CHECK_OFFSET(ADXTHandle, amplifier, 0x74);
CHECK_OFFSET(ADXTHandle, linked_stream_controller, 0x94);
CHECK_OFFSET(ADXTHandle, playback_time, 0x9C);
CHECK_OFFSET(ADXTHandle, pending_file_sectors, 0xBC);
CHECK_SIZE(ADXTHandle, 0xC0);

#endif

/* end sofdec/adxt.h */

struct adx_tlkBss {
    s32 adxt_time_mode;
    s32 adxt_tsvr_enter_cnt;
    s32 adxt_resync_cnt;
    u8 padding_C[0x1C];
    f32 adxt_time_diff;
    s32 adxt_time_unit;
};
/* adx_tlk.c was built without small data: these are addressed absolutely. */
extern s32 lbl_80178CB8[];
extern u32 lbl_8012B910[];
extern u8 lbl_800909C0[];

extern void fn_800474E4(const char *message);
extern s32 fn_80041684(AdxSjdHandle *decoder);
extern s32 fn_800416F8(AdxSjdHandle *decoder);
extern s32 fn_8004EE84(AXRNAHandle *rna);
extern s32 fn_800415F4(AdxSjdHandle *decoder);
extern s32 fn_8004163C(AdxSjdHandle *decoder);

void fn_8004C164(ADXTHandle *handle, s32 *count, s32 *scale);

#pragma readonly_strings on
#pragma section sconst_type ".rodata" ".rodata" data_mode=far_abs

/* Primer: reproduces adx_tlk.c's literal pool (lbl_800909C0) in first-use order. */
extern void fzgx_sink(const char *s);
extern void fzgx_sinkf(f32 f);
extern s32 fzgx_int;

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
        s32 buffered;
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

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
__declspec(section ".data") s32 lbl_8017E568;
__declspec(section ".data") u32 lbl_8017E56C;
__declspec(section ".data") s32 lbl_8017E56C__fzgx_offset_4;
__declspec(section ".data") u32 lbl_8017E56C__fzgx_offset_8[6];
__declspec(section ".data") u32 lbl_8017E58C;
__declspec(section ".data") f32 lbl_8017E58C__fzgx_offset_4;
__declspec(section ".data") s32 lbl_8017E594;
__declspec(section ".data") u32 lbl_8017E594__fzgx_offset_4[4];
__declspec(section ".data") u32 lbl_8017E5A8[4];
__declspec(section ".data") u32 lbl_8017E5B8;

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
    fzgx_sinkf((f32)fzgx_int);
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
        diff = 1000.0f * ((f32)count2 / (f32)scale2 - (f32)*count / (f32)lbl_8017E594);
        lbl_8017E58C__fzgx_offset_4 = diff;
        if (diff > 60.0f || diff < -60.0f) {
            if (lbl_8012B910[0] == 1) {
                s32 saved = lbl_8017E568;
                lbl_8017E568 = 0;
                fn_8004C164(handle, &count2, &scale2);
                lbl_8017E568 = saved;
                lbl_8017E56C__fzgx_offset_4++;
            }
            handle->playback_time = (u32)((f32)lbl_8017E594 * ((f32)count2 / (f32)scale2));
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
