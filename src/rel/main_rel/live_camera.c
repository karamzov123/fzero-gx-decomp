#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/live_camera.h"

extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern u32 fn_80008E30(u32);
extern u8 lbl_1_bss_17B4[12];
extern void fn_80083DB0(Obj_1_bss_3B30 *, void *);
extern u32 *fn_1_1304C(Obj_1_bss_3B30 *, u32);
extern u8 lbl_1_bss_1810[8984];
extern void fn_8000659C(void);
extern u32 OSIsThreadTerminated(u8 *);

extern void fn_1_6DD0(void *);
extern u32 *fn_1_1289C(u32 *);
extern s32 fn_1_4C10(void);
extern s32 fn_1_40BB4(void);
extern s32 fn_1_F2F34(void);
extern u32 fn_1_F45A4(void);
extern u32 fn_1_F4594(void);
extern f32 lbl_1_rodata_4E0[5];
extern f32 lbl_1_bss_1160[403];
extern void fn_1_5370(s32, s16);
extern f32 lbl_1_rodata_4F4[19];
extern const f64 lbl_1_rodata_548[2];
extern u32 lbl_801A63C0;
extern void fn_1_8636C(s16, void *);
extern void fn_1_862A8(s16, void *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern s32 lbl_8006D24C(f32, f32);
extern int sprintf(char *, const char *, ...);

/* fzgx:begin fn_1_DA34 */
// Reports the camera source location and message used by this routine.
void fn_1_DA34(void) {
    OSPanic(lbl_1_data_4420, 0x34, lbl_1_data_4430);
}
/* fzgx:end fn_1_DA34 */

/* fzgx:begin fn_1_DA6C noprologue */
#include "types.h"
#include "rel/main_rel/live_camera.h"

extern s32 fn_1_4C10(void);
extern s32 fn_1_40BB4(void);
extern s32 fn_1_F2F34(void);
extern u32 fn_1_F45A4(void);
extern u32 fn_1_F4594(void);
extern void * fn_1_86254(int);
extern s8 fn_1_86624(void);
extern void fn_1_6DD0(u32);
extern void fn_1_8A0C(u32);
extern u32 fn_1_56B8(void);
extern u32 fn_1_864E8(int);
extern void camera_set_selected_value(u8);
extern void camera_set_result(s16);
extern void fn_1_5370(u32, u32);

typedef struct {
    u8 pad_0[6];
    s16 unk_6;
    s16 unk_8;
} DA6CArg;

void fn_1_DA6C(DA6CArg *arg0) {
    s16 temp_r31;
    s32 var_r30;
    s32 var_r3;
    s32 cnt;
    u32 flags;
    s32 n;

    if (lbl_1_bss_115C == 0) {
        return;
    }
    if (fn_1_4C10() != 0) {
        return;
    }
    if (fn_1_40BB4() != 0) {
        return;
    }
    if (fn_1_F2F34() == 0) {
        return;
    }
    if (fn_1_F4594() >= fn_1_F45A4() - 0x1e) {
        return;
    }

    var_r30 = 1;
    if (((u16) lbl_1_bss_9F8.unk_A >> 6) & 1) {
        var_r30 = 1;
        (*(s8 *)((u8 *)(fn_1_86254((s32) arg0->unk_6)) + 1141)) = -1;
        arg0->unk_6++;
        n = fn_1_86624();
        if (arg0->unk_6 > n - 1) {
            var_r3 = 0;
        } else if (arg0->unk_6 < 0) {
            var_r3 = (s32) fn_1_86624() - 1;
        } else {
            var_r3 = arg0->unk_6;
        }
        (*(s8 *)((u8 *)(fn_1_86254((s32) var_r3)) + 1141)) = 0;
        fn_1_6DD0(0);
        fn_1_8A0C(0);
        fn_1_56B8();
    }
    if (arg0->unk_6 >= fn_1_86624()) {
        arg0->unk_6 = 0;
    }
    if (arg0->unk_6 < 0) {
        arg0->unk_6 = fn_1_86624() - 1;
    }
    arg0->unk_8 = arg0->unk_6;

    if (((u16) lbl_1_bss_9F8.unk_A >> 7) & 1) {
        var_r30 = -1;
        (*(s8 *)((u8 *)(fn_1_86254((s32) arg0->unk_6)) + 1141)) = -1;
        arg0->unk_6--;
        n = fn_1_86624();
        if (arg0->unk_6 > n - 1) {
            var_r3 = 0;
        } else if (arg0->unk_6 < 0) {
            var_r3 = (s32) fn_1_86624() - 1;
        } else {
            var_r3 = arg0->unk_6;
        }
        (*(s8 *)((u8 *)(fn_1_86254((s32) var_r3)) + 1141)) = 0;
        fn_1_6DD0(0);
        fn_1_8A0C(0);
        fn_1_56B8();
    }
    if (arg0->unk_6 >= fn_1_86624()) {
        arg0->unk_6 = 0;
    }
    if (arg0->unk_6 < 0) {
        arg0->unk_6 = fn_1_86624() - 1;
    }
    arg0->unk_8 = arg0->unk_6;

    flags = fn_1_864E8(arg0->unk_6);
    if ((flags & 0x800) && !(flags & 1)) {
        temp_r31 = arg0->unk_6;
        do {
            (*(s8 *)((u8 *)(fn_1_86254((s32) arg0->unk_6)) + 1141)) = -1;
            arg0->unk_6 += var_r30;
            if (arg0->unk_6 > (s32) fn_1_86624() - 1) {
                var_r3 = 0;
            } else if (arg0->unk_6 < 0) {
                var_r3 = (s32) fn_1_86624() - 1;
            } else {
                var_r3 = arg0->unk_6;
            }
            (*(s8 *)((u8 *)(fn_1_86254((s32) var_r3)) + 1141)) = 0;
            if (arg0->unk_6 >= fn_1_86624()) {
                arg0->unk_6 = 0;
            }
            if (arg0->unk_6 < 0) {
                arg0->unk_6 = fn_1_86624() - 1;
            }
        } while ((fn_1_864E8(arg0->unk_6) & 0x800) && temp_r31 != arg0->unk_6);

        if (arg0->unk_6 >= fn_1_86624()) {
            arg0->unk_6 = 0;
        }
        if (arg0->unk_6 < 0) {
            arg0->unk_6 = fn_1_86624() - 1;
        }
        arg0->unk_8 = arg0->unk_6;
        if (temp_r31 == arg0->unk_6) {
            camera_set_selected_value(1);
            camera_set_result(arg0->unk_6);
            fn_1_5370(0, 0);
            camera_set_result(arg0->unk_6);
            camera_set_selected_value(0);
            return;
        }
        fn_1_56B8();
    }

    if (arg0->unk_6 >= fn_1_86624()) {
        arg0->unk_6 = 0;
    }
    if (arg0->unk_6 < 0) {
        arg0->unk_6 = fn_1_86624() - 1;
    }
    arg0->unk_8 = arg0->unk_6;
    camera_set_result(arg0->unk_6);
}
/* fzgx:end fn_1_DA6C */

/* fzgx:begin fn_1_DE14 noprologue */
#include "types.h"
#include "rel/main_rel/live_camera.h"

extern s32 fn_1_4C10(void);
extern s32 fn_1_40BB4(void);
extern s32 fn_1_F2F34(void);
extern u32 fn_1_F45A4(void);
extern u32 fn_1_F4594(void);
extern f32 lbl_1_rodata_4E0[5];
extern f32 lbl_1_bss_1160[403];
extern void fn_1_5370(s32, s16);
extern void fn_1_6DD0(u32);

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[4];
    s16 unk_6;
    u8 pad_8[4];
    u32 unk_C;
    u8 pad_10[0x54];
    u16 unk_64;
} Fn1DE14State;

void fn_1_DE14(Fn1DE14State *state) {
    u8 enabled;

    if (lbl_1_bss_115C == 0) {
        return;
    }
    if (fn_1_4C10() != 0) {
        return;
    }
    if (fn_1_40BB4() != 0) {
        return;
    }
    if (fn_1_F2F34() == 0) {
        return;
    }
    if (fn_1_F4594() >= fn_1_F45A4() - 0x1e) {
        return;
    }

    enabled = 0;
    if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
        enabled = 1;
    }
    if (enabled == 0) {
        return;
    }

    lbl_1_bss_1160[0] = lbl_1_rodata_4E0[0];
    if (state->unk_1 == 0) {
        state->unk_0++;
    } else {
        state->unk_1++;
    }
    if (state->unk_0 >= 4) {
        state->unk_0 = 0;
        state->unk_1 = 1;
    }

    switch (state->unk_1) {
    case 1:
        fn_1_5370(0, state->unk_6);
        break;
    case 2:
        fn_1_5370(1, state->unk_6);
        state->unk_1 = 0;
    default:
        fn_1_5370(1, state->unk_6);
    case 0:
        break;
    }

    state->unk_64 = 0;
    state->unk_C &= ~0x00200000;
    fn_1_6DD0(0);
}
/* fzgx:end fn_1_DE14 */

/* fzgx:begin fn_1_E174 noprologue */
#include "types.h"

typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;
typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;
typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;
typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;
typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;
typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;
typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;
typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;
typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);
struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};
struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};
typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;

struct fn_1_E174_lbl_1_bss_1148 {
    u8 pad_0[0x8];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x4];
    u8 unk_14;
    u8 pad_15[0xF];
    f32 unk_24;
    u8 pad_28[0x4];
    s16 unk_2C;
    s16 unk_2E;
    u8 pad_30[0x5D8];
    s16 unk_608;
    u8 pad_60A[0x5A];
    u8 unk_664;
};
struct fn_1_E174_lbl_1_data_43B8 {
    u8 pad_0[0x148];
    s16 unk_148;
    s16 unk_14A;
    s16 unk_14C;
};
struct fn_1_E174_lbl_1_rodata_4E0 {
    f32 unk_0;
    u8 pad_4[0x10];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
};
struct fn_1_E174_lbl_1_bss_9F8 {
    u8 pad_0[0x12];
    u16 unk_12;
};

extern s16 lbl_1_bss_960;
extern struct fn_1_E174_lbl_1_bss_1148 lbl_1_bss_1148;
extern struct fn_1_E174_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern struct fn_1_E174_lbl_1_data_43B8 lbl_1_data_43B8;
extern struct fn_1_E174_lbl_1_rodata_4E0 lbl_1_rodata_4E0;
extern u32 fn_1_A1588(Sig_ADXT_Stop_ADXTHandle *, u32);
extern u32 fn_1_A1964(u32);
extern u32 fn_1_A1CE8(u32);
extern u32 fn_1_F2F34(void);
extern u32 lbl_1_bss_6EAD0;
extern s32 fn_1_40BB4(void);
extern u8 lbl_1_bss_6F243;
extern void fn_1_A2D84(u32);

#pragma opt_lifetimes off
#pragma opt_propagation off
#pragma opt_strength_reduction off
static inline void fn_1_E174_store(s16 value, s16 *destination) { *destination = value; }
void fn_1_E174(f32 arg0) {
    f32 fzgx_live;
    s16 fzgx_value;
    struct fn_1_E174_lbl_1_bss_1148 *p_lbl_1_bss_1148;
    struct fn_1_E174_lbl_1_data_43B8 *p_lbl_1_data_43B8;
    struct fn_1_E174_lbl_1_rodata_4E0 *p_lbl_1_rodata_4E0;
    struct fn_1_E174_lbl_1_bss_9F8 *p_lbl_1_bss_9F8;
    s16 v0;
    u32 v1;
    s32 v2;
    f32 v3;
    u32 v5;
    s16 v4;
    u32 v6;
    f32 v7;
    u32 v8;
    f32 v9;
    s32 v10;
    s16 v11;
    u32 v12;
    u32 v13;
    f32 v14;
    f32 v15;
    f32 v16;
    s32 v17;
    u32 t7;
    u32 t8;
    u32 t9;
    u32 t10;
    u32 t11;
    u32 t12;
    u32 t13;
    u32 t14;
    u32 t15;
    u32 t16;
    u32 t19;
    u32 t20;
    u32 t21;
    u32 t22;
    u32 t23;
    u32 t24;
    u32 t25;
    u32 t26;
    p_lbl_1_data_43B8 = (struct fn_1_E174_lbl_1_data_43B8 *)&lbl_1_data_43B8;
    p_lbl_1_bss_1148 = (struct fn_1_E174_lbl_1_bss_1148 *)&lbl_1_bss_1148;
    p_lbl_1_rodata_4E0 = (struct fn_1_E174_lbl_1_rodata_4E0 *)&lbl_1_rodata_4E0;
    if (((10) == (lbl_1_bss_960))) {
    fn_1_A1CE8((p_lbl_1_data_43B8->unk_148 & 0xFF));
    } else {
    if (((12) == (lbl_1_bss_960)) || (s32)fn_1_F2F34() != 0) {
    v0 = p_lbl_1_data_43B8->unk_148;
    v1 = (v0 - 41);
    switch ((s32)v1) {
    case 1:
    fn_1_A1CE8(((((1) + (v0))) & 0xFF));
    break;
    case 2:
    fn_1_A1CE8(((((1) + (v0))) & 0xFF));
    break;
    default:
    fn_1_A1CE8((v0 & 0xFF));
    }
    }
    }
    v3 = arg0;
    if (p_lbl_1_bss_1148->unk_14 != 0 && (s32)fn_1_40BB4() == 0 && (s32)fn_1_F2F34() != 0) {
    if (p_lbl_1_bss_1148->unk_664 != 0) {
    p_lbl_1_data_43B8->unk_14A = 41;
    p_lbl_1_bss_1148->unk_664 = 0;
    if (p_lbl_1_data_43B8->unk_148 != 41) {
    p_lbl_1_data_43B8->unk_148 = 41;
    lbl_1_bss_6F243 = 0;
    }
    v2 = p_lbl_1_data_43B8->unk_148;
    if (v2 < 41) {
    v2 = (v2 & 0xFF);
    t7 = fn_1_A1964(v2);
    v2 = t7;
    v2 = (p_lbl_1_data_43B8->unk_148 & 0xFF);
    t8 = fn_1_A1CE8(v2);
    v2 = t8;
    } else {
    v5 = (v2 - 41);
    switch ((s32)v5) {
    case 0:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t9 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 38);
    v2 = t9;
    v2 = (p_lbl_1_data_43B8->unk_148 & 0xFF);
    t10 = fn_1_A1CE8(v2);
    v2 = t10;
    break;
    case 1:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t11 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 44);
    v2 = t11;
    v2 = p_lbl_1_data_43B8->unk_148;
    v2 = ((v2 + 1) & 0xFF);
    t12 = fn_1_A1CE8(v2);
    v2 = t12;
    break;
    case 2:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t13 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 43);
    v2 = t13;
    v2 = p_lbl_1_data_43B8->unk_148;
    v2 = ((v2 + 1) & 0xFF);
    t14 = fn_1_A1CE8(v2);
    v2 = t14;
    break;
    default:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t15 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 38);
    v2 = t15;
    v2 = (p_lbl_1_data_43B8->unk_148 & 0xFF);
    t16 = fn_1_A1CE8(v2);
    v2 = t16;
    }
    }
    }
    if (((12) == (lbl_1_bss_960))) {
    p_lbl_1_bss_9F8 = (struct fn_1_E174_lbl_1_bss_9F8 *)&lbl_1_bss_9F8;
    if (((p_lbl_1_bss_9F8->unk_12 >> 9) & 0x1) != 0) {
    v3 = (p_lbl_1_rodata_4E0->unk_1C);
    v2 = 0xA9010000;
    v6 = (p_lbl_1_bss_1148->unk_2E + 1);
    v7 = p_lbl_1_bss_1148->unk_24;
    p_lbl_1_bss_1148->unk_2E = v6;
    v2 += 1536;
    p_lbl_1_data_43B8->unk_14C = 60;
    p_lbl_1_bss_1148->unk_8 = v3;
    p_lbl_1_bss_1148->unk_C = v7;
    fn_1_A2D84(v2);
    }
    if (((p_lbl_1_bss_9F8->unk_12 >> 8) & 0x1) != 0) {
    v2 = 0xA9010000;
    v3 = (p_lbl_1_rodata_4E0->unk_1C);
    v8 = (p_lbl_1_bss_1148->unk_2E - 1);
    v9 = (-p_lbl_1_bss_1148->unk_24);
    fn_1_E174_store(60, &(p_lbl_1_data_43B8->unk_14C));
    v2 += 1536;
    fzgx_value = v8;
    p_lbl_1_bss_1148->unk_2E = fzgx_value;
    p_lbl_1_bss_1148->unk_8 = v3;
    p_lbl_1_bss_1148->unk_C = v9;
    fn_1_A2D84(v2);
    }
    }
    v2 = p_lbl_1_data_43B8->unk_14C;
    if (v2 != 0) {
    p_lbl_1_data_43B8->unk_14C = (v2 - 1);
    } else {
    v3 = p_lbl_1_bss_1148->unk_8;
    if (v3 != (p_lbl_1_rodata_4E0->unk_14)) {
    p_lbl_1_bss_1148->unk_8 = (v3 - (p_lbl_1_rodata_4E0->unk_20));
    }
    }
    if (p_lbl_1_bss_1148->unk_2E < 0) {
    v2 = p_lbl_1_bss_1148->unk_608;
    p_lbl_1_bss_1148->unk_2E = (v2 - 1);
    }
    v2 = p_lbl_1_bss_1148->unk_608;
    if (p_lbl_1_bss_1148->unk_2E > (s32)(v2 - 1)) {
    p_lbl_1_bss_1148->unk_2E = 0;
    }
    v2 = (u32)((u8 *)(u32)p_lbl_1_bss_1148 + 1548);
    v10 = (s16)(*(s16 *)((u8 *)v2 + (p_lbl_1_bss_1148->unk_2E << 1)));
    p_lbl_1_data_43B8->unk_14A = v10;
    if (v10 < 0) {
    p_lbl_1_data_43B8->unk_14A = 43;
    }
    if (p_lbl_1_data_43B8->unk_14A >= 44) {
    p_lbl_1_data_43B8->unk_14A = 0;
    }
    if (p_lbl_1_data_43B8->unk_148 != (v11 = p_lbl_1_data_43B8->unk_14A) && ((0) == (p_lbl_1_data_43B8->unk_14C))) {
    p_lbl_1_data_43B8->unk_148 = v11;
    lbl_1_bss_6F243 = 0;
    if (v11 < 41) {
    v2 = (v11 & 0xFF);
    t19 = fn_1_A1964(v2);
    v2 = t19;
    } else {
    v12 = (v11 - 41);
    switch ((s32)v12) {
    case 0:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t20 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 38);
    v2 = t20;
    break;
    case 1:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t21 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 44);
    v2 = t21;
    break;
    case 2:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t22 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 43);
    v2 = t22;
    break;
    default:
    v2 = (u32)&lbl_1_bss_6EAD0;
    v2 = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)v2 + 0);
    t23 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v2, 38);
    v2 = t23;
    }
    }
    }
    v2 = p_lbl_1_data_43B8->unk_148;
    v13 = (v2 - 41);
    switch ((s32)v13) {
    case 1:
    v2 = ((v2 + 1) & 0xFF);
    t24 = fn_1_A1CE8(v2);
    v2 = t24;
    break;
    case 2:
    v2 = ((v2 + 1) & 0xFF);
    t25 = fn_1_A1CE8(v2);
    v2 = t25;
    break;
    default:
    v2 = (v2 & 0xFF);
    t26 = fn_1_A1CE8(v2);
    v2 = t26;
    }
    v2 = (u32)&lbl_1_bss_9F8;
    if (((*(u16 *)((u8 *)v2 + 16) >> 4) & 0x1) != 0) {
    v2 = p_lbl_1_bss_1148->unk_2C;
    p_lbl_1_bss_1148->unk_2C = (v2 + 1);
    }
    if (p_lbl_1_bss_1148->unk_2C >= 4) {
    p_lbl_1_bss_1148->unk_2C = 0;
    }
    v4 = p_lbl_1_bss_1148->unk_2C;
    v2 = (u32)((u8 *)(u32)p_lbl_1_bss_1148 + 24);
    v14 = (p_lbl_1_rodata_4E0->unk_14);
    fzgx_live = p_lbl_1_rodata_4E0->unk_0;
    v15 = (fzgx_live);
    v16 = (p_lbl_1_rodata_4E0->unk_24);
    v17 = 0;
    while ((s16)v17 < 3) {
    if (((s16)v17) == v4) {
    v3 = *(f32 *)((u8 *)v2 + 0);
    v3 = (v3 + v16);
    *(f32 *)((u8 *)v2 + 0) = v3;
    } else {
    v3 = *(f32 *)((u8 *)v2 + 0);
    v3 = (v3 - v16);
    *(f32 *)((u8 *)v2 + 0) = v3;
    }
    v3 = *(f32 *)((u8 *)v2 + 0);
    if (v3 < v14) {
    *(f32 *)((u8 *)v2 + 0) = v14;
    }
    v3 = *(f32 *)((u8 *)v2 + 0);
    if (v3 > v15) {
    *(f32 *)((u8 *)v2 + 0) = v15;
    }
    v2 = (u32)((u8 *)v2 + 4);
    v17++;
    }
    }
}
#pragma opt_strength_reduction reset

#pragma opt_propagation reset

#pragma opt_lifetimes reset
/* fzgx:end fn_1_E174 */

/* fzgx:begin fn_1_EBE4 noprologue */
#include "types.h"

typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;
typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;
typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;
typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;
typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;
typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;
typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;
typedef struct {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;
typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);
struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};
struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};
typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;

struct fn_1_EBE4_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};
struct fn_1_EBE4_lbl_1_bss_1148 {
    u8 unk_0;
    u8 pad_1[0xB];
    f32 unk_C;
    u8 pad_10[0x4];
    u8 unk_14;
    u8 pad_15[0x64F];
    u8 unk_664;
    u8 pad_665[0x1];
    u16 unk_666;
    u32 unk_668;
    u8 unk_66C;
    u8 pad_66D[0x3];
    u32 unk_670;
    u32 unk_674;
    u8 unk_678;
};
struct fn_1_EBE4_lbl_1_data_43B8 {
    u8 pad_0[0x148];
    s16 unk_148;
    u16 unk_14A;
    u16 unk_14C;
};

typedef struct {
    u32 w0;
    u32 w1;
} EBE4Pair;

extern f32 lbl_1_rodata_4F4;
extern s16 fn_1_7B054(void);
extern s16 lbl_1_bss_960;
extern struct fn_1_EBE4_lbl_1_bss_1148 lbl_1_bss_1148;
extern struct fn_1_EBE4_lbl_1_data_43B8 lbl_1_data_43B8;
extern u32 fn_1_A1588(Sig_ADXT_Stop_ADXTHandle *, u32);
extern u32 fn_1_A1CE8(u32);
extern u32 fn_1_F2F34(void);
extern u32 lbl_1_bss_6EAD0;
extern u8 lbl_1_bss_6F243;
extern void fn_1_10138(void *);
extern void fn_1_8840(void);

u32 fn_1_EBE4(struct fn_1_EBE4_Arg0 *arg0, s32 arg1, u32 arg2, f32 arg3) {
    void * v2;
    struct fn_1_EBE4_lbl_1_bss_1148 *p_lbl_1_bss_1148;
    void * v0;
    u32 v4;
    u32 v5;
    struct fn_1_EBE4_lbl_1_data_43B8 *p_lbl_1_data_43B8;
    u32 v3;
    u32 v1;
    u32 v6;
    s16 t0;
    u32 t3;
    u32 t4;
    u32 t5;
    p_lbl_1_data_43B8 = (struct fn_1_EBE4_lbl_1_data_43B8 *)&lbl_1_data_43B8;
    p_lbl_1_bss_1148 = (struct fn_1_EBE4_lbl_1_bss_1148 *)&lbl_1_bss_1148;
    p_lbl_1_bss_1148->unk_666 = 0;
    p_lbl_1_bss_1148->unk_668 = -1;
    v0 = (void *)(((u8 *)(u32)p_lbl_1_data_43B8 + 208));
    p_lbl_1_data_43B8->unk_14C = 60;
    p_lbl_1_bss_1148->unk_C = lbl_1_rodata_4F4;
    p_lbl_1_bss_1148->unk_14 = 0;
    p_lbl_1_bss_1148->unk_0 = 0;
    p_lbl_1_bss_1148->unk_66C = 0;
    arg0->unk_C = (arg0->unk_C & 0xFFF7FFFF);
    v1 = 0;
    v2 = v0;
    v3 = (u32)arg0;
    do {
    t0 = fn_1_7B054();
    v3 = t0;
    v3 = (s16)v3;
    if (*(s32 *)((u8 *)v2 + 0) == (s32)v3) {
    *(u32 *)((u8 *)(u32)arg0 + 12) = (*(u32 *)((u8 *)(u32)arg0 + 12) | 0x80000);
    }
    v1++;
    v2 = (void *)(((u8 *)v2 + 4));
    } while (v1 < 26);
    if ((s32)arg2 != 0) {
    *(u8 *)((u8 *)arg0 + 0) = 6;
    *(u16 *)((u8 *)arg0 + 18) = 5;
    *(u16 *)((u8 *)arg0 + 20) = 0;
    *(u32 *)((u8 *)arg0 + 24) = 0;
    *(u16 *)((u8 *)arg0 + 16) = 0;
    fn_1_10138(arg0);
    } else {
    *(u8 *)((u8 *)arg0 + 0) = 5;
    *(u16 *)((u8 *)arg0 + 18) = 2;
    *(u16 *)((u8 *)arg0 + 20) = 9;
    *(u32 *)((u8 *)arg0 + 24) = 0;
    *(u16 *)((u8 *)arg0 + 16) = 0;
    }
    *(u8 *)((u8 *)arg0 + 1) = 0;
    *(u16 *)((u8 *)arg0 + 100) = 210;
    *(u16 *)((u8 *)arg0 + 106) = 0;
    *(u32 *)((u8 *)arg0 + 12) = (*(u32 *)((u8 *)arg0 + 12) & 0xFFDFFFFF);
    *(f32 *)((u8 *)arg0 + 96) = arg3;
    *(u16 *)((u8 *)arg0 + 92) = 0;
    *(EBE4Pair *)((u8 *)arg0 + 0x28) = *(EBE4Pair *)((u8 *)arg0 + 0x1C);
    *(u32 *)((u8 *)arg0 + 48) = *(u32 *)((u8 *)arg0 + 36);
    *(u16 *)((u8 *)arg0 + 8) = arg1;
    *(u16 *)((u8 *)arg0 + 6) = arg1;
    p_lbl_1_bss_1148->unk_670 = 0;
    p_lbl_1_bss_1148->unk_674 = 0;
    fn_1_8840();
    if (lbl_1_bss_960 == 10 && (s32)arg2 == 0) {
    p_lbl_1_bss_1148->unk_664 = 0;
    p_lbl_1_bss_1148->unk_678 = 2;
    *(u8 *)((u8 *)arg0 + 0) = 0;
    p_lbl_1_data_43B8->unk_14A = 42;
    lbl_1_bss_6F243 = 0;
    if (((s16)(p_lbl_1_data_43B8->unk_148)) != 42) {
    p_lbl_1_data_43B8->unk_148 = 42;
    }
    v6 = (u32)&lbl_1_bss_6EAD0;
    v6 = *(u32 *)((u8 *)v6 + 0);
    v6 = *(u32 *)((u8 *)v6 + 0);
    t3 = fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)v6, 1);
    v6 = t3;
    v6 = (p_lbl_1_data_43B8->unk_148 & 0xFF);
    t4 = fn_1_A1CE8(v6);
    v6 = t4;
    } else {
    t5 = fn_1_F2F34();
    v6 = t5;
    if ((s32)v6 != 0 && (s32)arg2 == 0) {
    *(u8 *)((u8 *)arg0 + 0) = 0;
    }
    }
    if (p_lbl_1_bss_1148->unk_664 != 0) {
    p_lbl_1_bss_1148->unk_678 = 2;
    }
    return v6;
}
/* fzgx:end fn_1_EBE4 */

/* fzgx:begin fn_1_EE04 */
typedef struct {
    u8 pad[2];
    s16 state;
} Fn1EE04Context;

typedef void (*Fn1EE04Handler)(Fn1EE04Context *, void *);

// Dispatch the active live-camera handler, then advance camera processing.
void fn_1_EE04(Fn1EE04Context *context) {
    ((Fn1EE04Handler *)&lbl_1_data_4440)[context->state](
        context, &lbl_1_data_4440);
    fn_1_6DD0(0);
}
/* fzgx:end fn_1_EE04 */

/* fzgx:begin fn_1_FA84 noprologue */
#include "types.h"

struct fn_1_FA84_lbl_1_bss_1148 {
    u8 pad_0[0x67C];
    u32 unk_67C;
    u32 unk_680;
    u32 unk_684;
};
struct fn_1_FA84_lbl_1_data_43B8 {
    u8 pad_0[0x13C];
    u32 unk_13C;
    u32 unk_140;
    u32 unk_144;
};

extern struct fn_1_FA84_lbl_1_bss_1148 lbl_1_bss_1148;
extern struct fn_1_FA84_lbl_1_data_43B8 lbl_1_data_43B8;
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 lbl_801A6410;

void fn_1_FA84(void) {
    struct fn_1_FA84_lbl_1_data_43B8 *p_lbl_1_data_43B8;
    struct fn_1_FA84_lbl_1_bss_1148 *p_lbl_1_bss_1148;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    s32 v7;
    u32 v8;
    u32 t0, t1, t2;
    p_lbl_1_data_43B8 = (struct fn_1_FA84_lbl_1_data_43B8 *)&lbl_1_data_43B8;
    p_lbl_1_bss_1148 = (struct fn_1_FA84_lbl_1_bss_1148 *)&lbl_1_bss_1148;
    v1 = 0;
    v3 = 0;
    if ((s32)p_lbl_1_data_43B8->unk_13C > 0) {
    v0 = (u32)&lbl_801A6410;
    p_lbl_1_data_43B8->unk_13C = -1;
    v0 = *(u32 *)((u8 *)v0 + 0);
    v1 = (u32)((u8 *)(u32)p_lbl_1_data_43B8 + 104);
    v2 = p_lbl_1_bss_1148->unk_67C;
    v3 = 1472;
    t0 = fn_1_46B4(v0, v2, (u32)v1, v3);
    v0 = t0;
    }
    v4 = v0;
    v5 = v1;
    v6 = v2;
    v7 = v3;
    if ((s32)p_lbl_1_data_43B8->unk_140 > 0) {
    v4 = (u32)&lbl_801A6410;
    p_lbl_1_data_43B8->unk_140 = -1;
    v4 = *(u32 *)((u8 *)v4 + 0);
    v5 = (u32)((u8 *)(u32)p_lbl_1_data_43B8 + 104);
    v6 = p_lbl_1_bss_1148->unk_680;
    v7 = 1473;
    t1 = fn_1_46B4(v4, v6, (u32)v5, v7);
    v4 = t1;
    }
    v8 = v4;
    if ((s32)p_lbl_1_data_43B8->unk_144 > 0) {
    v8 = (u32)&lbl_801A6410;
    p_lbl_1_data_43B8->unk_144 = -1;
    v8 = *(u32 *)((u8 *)v8 + 0);
    t2 = fn_1_46B4(v8, p_lbl_1_bss_1148->unk_684, (u32)((u8 *)(u32)p_lbl_1_data_43B8 + 104), 1474);
    v8 = t2;
    }
}
/* fzgx:end fn_1_FA84 */

/* fzgx:begin fn_1_FB50 noprologue */
#include "types.h"
#include "psvec.h"

extern u32 lbl_1_bss_F5C;
extern const f64 lbl_1_rodata_580;
extern const f64 lbl_1_rodata_588;
extern void fn_1_8840(void);

typedef struct LiveCameraVec {
    f32 values[3];
} LiveCameraVec;

typedef struct LiveCamera {
    u8 pad_00[0x1c];
    LiveCameraVec position;
    u8 pad_28[0x84];
    s32 mode;
    s32 timer;
    LiveCameraVec saved;
    LiveCameraVec offset;
    LiveCameraVec velocity;
} LiveCamera;

void fn_1_FB50(LiveCamera *camera) {
    f64 product;
    f64 damping;
    u32 i;

    if (camera->mode == 0) {
        camera->saved = camera->position;
    } else {
        if ((lbl_1_bss_F5C & 0x50000000) == 0) {
            damping = lbl_1_rodata_580;
            for (i = 0; i < 3; i++) {
                product = damping * (f64)camera->offset.values[i];
                camera->velocity.values[i] =
                    (f32)((f64)camera->velocity.values[i] - product);
            }
            for (i = 0; i < 3; i++) {
                camera->velocity.values[i] =
                    (f32)((f64)camera->velocity.values[i] * lbl_1_rodata_588);
            }
            for (i = 0; i < 3; i++) {
                camera->offset.values[i] =
                    camera->offset.values[i] + camera->velocity.values[i];
            }
        }
        psvec_add(&camera->saved.values[0], &camera->offset.values[0], &camera->position.values[0]);
        if ((lbl_1_bss_F5C & 0x50000000) == 0 && camera->timer > 0) {
            camera->timer--;
            if (camera->timer == 0) {
                fn_1_8840();
            }
        }
    }
}
/* fzgx:end fn_1_FB50 */

/* fzgx:begin fn_1_FCB0 noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x6];
    s16 unk_6;
    u8 pad_8[0x8];
    u16 unk_10;
    s16 unk_12;
    s16 unk_14;
    u8 pad_16[0x2];
    u32 unk_18;
    u8 pad_1C[0x48];
    u16 unk_64;
} Sig_fn_1_101D0_Fn_1_101D0_State;

extern const f64 lbl_1_rodata_558[5];
extern s32 camera_get_state(void);
extern const f64 lbl_1_rodata_548[2];
extern u32 lbl_801A63C0;
extern u32 fn_1_107B8(Sig_fn_1_101D0_Fn_1_101D0_State *);
extern u32 fn_1_864E8(int);
extern u8 fn_1_86624(void);
extern void camera_set_result(s16);
extern void camera_set_selected_value(u8);
extern void fn_1_5370(s8, u32);

#pragma opt_strength_reduction off
static inline u8 * fn_1_FCB0_read_pointer(Sig_fn_1_101D0_Fn_1_101D0_State * owner) { return owner->pad_0; }
#pragma opt_loop_invariants on
#pragma opt_schedule off
void fn_1_FCB0(Sig_fn_1_101D0_Fn_1_101D0_State * arg0, f32 arg1) {
    s16 *fzgx_value__;
    u32 fzgx_value_;
    s16 fzgx_value;
    u8 v0;
    f64 v1;
    u32 v3;
    u16 v8;
    s16 v9;
    s16 v21;
    s16 v29;
    s16 v30;
    u32 v28;
    s32 v32;
    s32 v_div;
    s32 v_n;
    v0 = fn_1_FCB0_read_pointer(arg0)[0];
    if (v0 == 1 && (*(u32 *)((u8 *)arg0 + 12) & 0x80000) != 0) {
        v0 = 4;
        arg0->unk_12 = v0;
        v1 = (f64)(u32)arg0->unk_64;
        if (v1 > (210.0)) {
            arg0->unk_64 = 0;
        } else {
            arg0->unk_64 = 210;
        }
        return;
    } else {
        if (v0 == 0) {
            if ((*(u32 *)((u8 *)arg0 + 12) & 0x80000) == 0) {
                v3 = lbl_801A63C0 * 0x676A4B6B + 13259;
                fzgx_value_ = v3;
                lbl_801A63C0 = fzgx_value_;
                arg0->unk_12 = (s16)((s32)((v3 >> 16) & 0x7FFF) % 4);
                v9 = *(s16 *)((u8 *)arg0 + 2);
                if ((s32)arg0->unk_12 == v9) {
                    fzgx_value__ = &(arg0->unk_12);
                    *fzgx_value__ = (s16)((v9 + 1) % 4);
                }
            } else {
                v3 = ((0x676A4B6B) * (lbl_801A63C0)) + 13259;
                lbl_801A63C0 = v3;
                arg0->unk_12 = (s16)((s32)((v3 >> 16) & 0x7FFF) % 6);
                if ((s32)arg0->unk_12 >= 5) {
                    arg0->unk_12 = 4;
                }
                if ((s32)arg0->unk_12 == *(s16 *)((u8 *)arg0 + 2)) {
                    if ((s32)arg0->unk_12 == 4) {
                        s32 v10 = (s16)(*(s16 *)((u8 *)arg0 + 4));
                        fn_1_107B8(arg0);
                        if (v10 == (s32)arg0->unk_14) {
                            arg0->unk_12 = (s16)((*(s16 *)((u8 *)arg0 + 2) + 1) % 5);
                        }
                    } else {
                        arg0->unk_12 = (s16)((*(s16 *)((u8 *)arg0 + 2) + 1) % 5);
                    }
                }
            }
        } else {
            v3 = lbl_801A63C0 * 0x676A4B6B + 13259;
            lbl_801A63C0 = v3;
            arg0->unk_12 = (s16)((s32)(((0x7FFF) & ((v3 >> 16)))) % 6);
            if ((s32)arg0->unk_12 == *(s16 *)((u8 *)arg0 + 2)) {
                arg0->unk_12 = (s16)((*(s16 *)((u8 *)arg0 + 2) + 1) % 6);
            }
            if ((s32)arg0->unk_12 == 5) {
                arg0->unk_12 = 4;
            }
            if ((s32)arg0->unk_12 == 4) {
                if ((*(u32 *)((u8 *)arg0 + 12) & 0x80000) == 0) {
                    arg0->unk_12 = 3;
                }
                if (fn_1_FCB0_read_pointer(arg0)[0] == 2) {
                    arg0->unk_12 = (s16)((*(s16 *)((u8 *)arg0 + 2) + 1) % 3);
                }
            }
            if ((s8)camera_get_state() == 6) {
                if ((s32)arg0->unk_12 == 2) {
                    arg0->unk_12 = (s16)(((s32)arg0->unk_12 + 1) % 3);
                }
            }
        }
    }
    v1 = (f64)(u32)arg0->unk_64;
    if (v1 > (210.0)) {
        arg0->unk_64 = 0;
    } else {
        arg0->unk_64 = 210;
    }
    if ((s8)camera_get_state() == 6) {
        lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 13259;
        v3 = (s32)((lbl_801A63C0 >> 16) & 0x7FFF);
        v_div = v3;
        arg0->unk_6 = (s16)(v_div % (s32)(s8)fn_1_86624());
        if ((fn_1_864E8(arg0->unk_6) & 0x1) == 0) {
            v28 = 0x8000880;
            if ((fn_1_864E8(arg0->unk_6) & v28) != 0) {
                v29 = arg0->unk_6;
                do {
                    v30 = arg0->unk_6;
                    fzgx_value = v30;
                    fzgx_value += 1;
                    arg0->unk_6 = fzgx_value;
                    if ((s32)arg0->unk_6 >= (s32)(s8)fn_1_86624()) {
                        arg0->unk_6 = 0;
                    }
                    if ((s32)arg0->unk_6 < 0) {
                        arg0->unk_6 = (s8)fn_1_86624() - 1;
                    }
                } while ((fn_1_864E8(arg0->unk_6) & v28) != 0 && (s32)v29 != (s32)arg0->unk_6);
                if ((s32)v29 == (s32)arg0->unk_6) {
                    camera_set_selected_value(1);
                    camera_set_result(arg0->unk_6);
                    fn_1_5370(0, 0);
                    camera_set_result(arg0->unk_6);
                    camera_set_selected_value(0);
                    return;
                }
            }
        }
        *(u16 *)((u8 *)arg0 + 8) = arg0->unk_6;
    }
}

#pragma opt_loop_invariants reset

#pragma opt_strength_reduction reset
/* fzgx:end fn_1_FCB0 */

/* fzgx:begin fn_1_10138 */
void fn_1_10138(void) {
    Obj_1_bss_17C4_At0 *obj;
    u32 i;
    u32 count;

    lbl_1_bss_17B0 = 0;
    count = lbl_1_data_44F4.unk_0;
    obj = lbl_1_bss_17C4.unk_0;
    i = 0;
    while (i < count) {
        lbl_1_bss_17B0 += fn_80008E30(obj->unk_0);
        i++;
        obj++;
    }
}
/* fzgx:end fn_1_10138 */

/* fzgx:begin fn_1_101C0 */
u32 fn_1_101C0(void) {
    return lbl_1_bss_17B0;
}
/* fzgx:end fn_1_101C0 */

/* fzgx:begin fn_1_101D0 */
typedef struct {
    u8 pad_0[0x6];
    u16 unk_6;
    u8 pad_8[0x8];
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u8 pad_16[0x2];
    u32 unk_18;
    u8 pad_1C[0x48];
    u16 unk_64;
} Fn_1_101D0_State;

extern u32 fn_80008E30(u32);

void fn_1_101D0(Fn_1_101D0_State *self) {
    Obj_1_bss_17C4_At0 *base;
    u32 count;
    u32 off;

    count = lbl_1_data_44F4.unk_0;
    base = lbl_1_bss_17C4.unk_0;

    if (self->unk_64 == 0) {
        self->unk_10++;
        off = self->unk_10 * 0x54;
        if (self->unk_10 < count) {
            self->unk_64 = fn_80008E30(*(u32 *)((u8 *)base + off));
            self->unk_12 = 5;
            self->unk_14 = self->unk_10;
            self->unk_6 = 0;
            self->unk_18 = 1;
        }
        return;
    }
    self->unk_18 = 0;
}
/* fzgx:end fn_1_101D0 */

/* fzgx:begin fn_1_10268 */
extern u32 fn_80008E30(u32);

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
} Bss_1_17D0;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    f32 unk_1C;
    s16 unk_20;
} Copy_1_10268;

typedef struct {
    u8 pad_0[4];
    s16 unk_4;
    u8 pad_6[0x16];
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u8 pad_28[0x24];
    u32 unk_4C;
    u32 unk_50;
    u32 unk_54;
    f32 unk_58;
    s16 unk_5C;
    u8 pad_5E[0x6];
    s16 unk_64;
} Camera_1_10268;

void fn_1_10268(Camera_1_10268 *arg) {
    Obj_1_bss_17C4_At0 *e;
    Copy_1_10268 t;
    u32 n;
    u32 m;
    f32 a;
    f32 b;

    e = &lbl_1_bss_17C4.unk_0[arg->unk_4];
    t = *(Copy_1_10268 *)((u8 *)e + 8);

    n = fn_80008E30(e->unk_0);

    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_0 = lbl_1_rodata_4F4[0];
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_4 = lbl_1_rodata_4E0[0];
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_10 = lbl_1_rodata_4F4[0];
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_14 = lbl_1_rodata_4E0[0] / (f32)((n * n) >> 2);
    a = (f32)n;
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_C = a;
    ((Bss_1_17D0 *)&lbl_1_bss_17D0)->unk_8 = a;

    arg->unk_64 = fn_80008E30(e->unk_0);

    arg->unk_1C = t.unk_4;
    arg->unk_20 = t.unk_8;
    arg->unk_24 = t.unk_C;
    arg->unk_4C = t.unk_10;
    arg->unk_50 = t.unk_14;
    arg->unk_54 = t.unk_18;
    arg->unk_5C = t.unk_20;
    arg->unk_58 = t.unk_1C;
}
/* fzgx:end fn_1_10268 */

/* fzgx:begin fn_1_11544 */
#pragma fp_contract off


extern s32 fn_1_40BB4(void);
extern void fn_1_862D4(s16, void *);
extern void fn_1_8636C(s16, void *);
extern void fn_1_862A8(s16, void *);
extern const f64 lbl_1_rodata_540;
extern const f32 lbl_1_rodata_604;
extern void *fn_1_20A5C(void *, void *);
extern void fn_1_15578(void *, void *, void *, void *, s32, void *, s32, s32, s32, s32);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct LiveCam {
    u8 unk_0;
    u8 pad_1[3];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0xC];
    s16 unk_14;
    u8 pad_16[6];
    u8 unk_1c[0x30];
    Vec3f unk_4c;
    u8 pad_58[0x18];
    Vec3f unk_70;
} LiveCam;

#pragma opt_propagation off
#pragma opt_dead_assignments on
#pragma opt_strength_reduction off
void fn_1_11544(LiveCam *cam) {
    f32 fzgx_live_;
    f32 fzgx_live;
    Vec3f sp_3c;
    s16 *fzgx_value;
    f32 sp_48[3][4];
    Vec3f sp_30;
    Vec3f sp_24;
    Vec3f sp_18;
    void *sp_14;
    u32 sp_10;
    f32 rate;
    f32 factor;
    f32 fzgx_y_;
    f32 fzgx_y;
    f32 fzgx_z_;
    f32 fzgx_z;
    f32 z;
    f32 y;
    f32 x;
    f32 *const lc = (f32 *)0xE0000000; // fzgx-allow: A2 locked cache address

    if (cam->unk_0 == 3 && fn_1_40BB4() == 0) {
        if ((lbl_1_bss_9F8.unk_A >> 1) & 1) {
            cam->unk_14++;
        }
        if (lbl_1_bss_9F8.unk_A & 1) {
            cam->unk_14--;
        }
        if (cam->unk_14 > 5) {
            cam->unk_14 = 0;
        }
        if (cam->unk_14 < 0) {
            fzgx_value = &(cam->unk_14);
            *fzgx_value = 5;
        }
    }

    fn_1_862D4(cam->unk_6, &sp_3c);
    fn_1_8636C(cam->unk_6, sp_48);
    fn_1_862A8(cam->unk_6, &sp_30);
    lbl_8006DC6C(sp_48);

    x = sp_3c.x;
    y = sp_3c.y;
    z = sp_3c.z;
    lc[3] = x;
    lc[7] = y;
    lc[11] = z;
    lbl_8006E1B0((u8 *)&lbl_1_data_4754 + cam->unk_4 * 16, cam->unk_1c);

    cam->unk_4c = sp_3c;


    factor = lbl_1_data_4484.unk_0;
    rate = (0.0500000007f);

    fzgx_live_ = cam->unk_70.x;
    fzgx_live = fzgx_live_;
    cam->unk_70.x += ((((sp_30.x - fzgx_live)) * ((0.0500000007f))) * (factor));

    fzgx_y_ = cam->unk_70.y;
    fzgx_y = fzgx_y_;
    cam->unk_70.y += ((sp_30.y - fzgx_y) * (0.0500000007f)) * factor;

    fzgx_z_ = cam->unk_70.z;
    fzgx_z = fzgx_z_;
    cam->unk_70.z += ((sp_30.z - fzgx_z) * (0.0500000007f)) * factor;

    lbl_8006DAEC();
    sp_14 = fn_1_20A5C(cam->unk_1c, &sp_10);
    sp_24 = cam->unk_4c;
    fn_1_15578(cam->unk_1c, &sp_24, &sp_10, &sp_18, 0x40005, &sp_14, 1, 0, 0, 0);
    lbl_8006DB30();
}
#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset

#pragma opt_propagation reset
/* fzgx:end fn_1_11544 */

/* fzgx:begin fn_1_11ABC */
#include "dolphin/hw_regs.h"
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    Vec3 v;              /* 0x00 */
    u8 pad_C[0x14];
} CameraData;            /* 32 bytes */

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[2];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0xC];
    s16 unk_14;
    u8 pad_16[6];
    f32 unk_1C;
    u8 pad_20[0x14];
    Vec3 unk_34;
    u8 pad_40[0xC];
    Vec3 unk_4C;
    f32 unk_58;
    s16 unk_5C;
    u8 pad_5E[0x12];
    f32 unk_70;
    u8 pad_74[8];
    f32 unk_7C;
} LiveCamera;

extern void fn_1_862D4(s16, Vec3 *);
extern void fn_8006E2B0(void *, Vec3 *);

#pragma opt_propagation off
void fn_1_11ABC(LiveCamera *camera) {
    Vec3 first;
    Vec3 second;
    u8 mode = camera->unk_0;

    if (mode == 5 || mode <= 1 || mode == 2) {
        u32 value;
        u32 next = lbl_801A63C0 * 0x676A4B6Bu + 0x33CB;
        s16 result;

        value = (next << 1) >> 17;
        result = (s16)(value % 9);
        lbl_801A63C0 = next;
        camera->unk_14 = result;
        camera->unk_4 = result;
    }

    fn_1_862D4(camera->unk_6, &first);
    fn_1_8636C(camera->unk_6, &camera->unk_7C);
    fn_1_862A8(camera->unk_6, &camera->unk_70);

    camera->unk_34 = (*(CameraData (*)[])&lbl_1_data_4AA0)[camera->unk_4].v;

    {
        f32 m2, m1, m0;
        f32 *mtx = (f32 *)(LC_BASE + 0x0);
        m0 = first.x;
        m1 = first.y;
        m2 = first.z;
        mtx[3] = m0;
        mtx[7] = m1;
        mtx[11] = m2;
    }

    lbl_8006DC6C(&camera->unk_7C);
    lbl_8006E1B0(&camera->unk_34, &camera->unk_1C);
    fn_8006E2B0(&camera->unk_70, &second);

    camera->unk_4C = first;
    camera->unk_5C = (s16)-lbl_8006D24C(second.x, second.y);
    camera->unk_58 = 55.0f;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_11ABC */

/* fzgx:begin fn_1_12620 */
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern u32 fn_80008E30(u32);
extern u8 lbl_1_bss_17B4[12];
extern void fn_80083DB0(Obj_1_bss_3B30 *, void *);
extern u32 *fn_1_1304C(Obj_1_bss_3B30 *, u32);
extern u8 lbl_1_bss_1810[8984];
extern void fn_8000659C(void);
extern u32 OSIsThreadTerminated(u8 *);

extern void fn_1_6DD0(void *);
extern u32 *fn_1_1289C(u32 *);

// Prints the live-camera status text for the current camera event.
#pragma opt_common_subs off
void fn_1_12620(s32 arg0) {
    u8 *base = lbl_1_data_43B8;
    char buf[0x74];

    fn_80006E10((u32)(base + 0x280));
    if (*(s16 *)&lbl_1_bss_960 == 0xA) {
        sprintf(buf, (const char *)(base + 0x284), arg0);
        if (fn_1_465D0((s32)buf, 1) == -1) {
            sprintf(buf, (const char *)(base + 0x2A0));
            fn_1_465D0((s32)buf, 1);
        }
    } else if (*(s16 *)&lbl_1_bss_960 == 0xE) {
        if (lbl_1_bss_525C.unk_191 & 2) {
            switch (lbl_1_bss_525C.unk_192) {
            case 4:
                sprintf(buf, (const char *)(base + 0x2BC));
                break;
            case 3:
                sprintf(buf, (const char *)(base + 0x2D4));
                break;
            case 2:
                sprintf(buf, (const char *)(base + 0x2EC));
                break;
            default:
                sprintf(buf, (const char *)(base + 0x2EC));
                break;
            }
        } else {
            sprintf(buf, (const char *)(base + 0x304));
        }
        fn_1_465D0((s32)buf, 1);
    } else {
        sprintf(buf, (const char *)(base + 0x324), arg0);
        if (fn_1_465D0((s32)buf, 1) == -1) {
            sprintf(buf, (const char *)(base + 0x33C));
            fn_1_465D0((s32)buf, 1);
        }
    }
    if (arg0 == 0x32) {
        fn_80006E10((u32)(base + 0x350));
        return;
    }
    sprintf(buf, (const char *)(base + 0x354), arg0);
    if (fn_1_465D0((s32)buf, 1) == -1) {
        sprintf(buf, (const char *)(base + 0x364));
        fn_1_465D0((s32)buf, 1);
    }
    sprintf(buf, (const char *)(base + 0x374), arg0);
    if (fn_1_465D0((s32)buf, 1) == -1) {
        sprintf(buf, (const char *)(base + 0x388));
        fn_1_465D0((s32)buf, 1);
    }
    fn_80006E10((u32)(base + 0x350));
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_12620 */

/* fzgx:begin fn_1_12850 */
u8 fn_1_12850(void) {
    return lbl_1_bss_17B4[0];
}
/* fzgx:end fn_1_12850 */

/* fzgx:begin fn_1_12860 */
// Initializes the live-camera state before returning the active camera result.
u32 fn_1_12860(u32 arg0, u32 arg1) {
    u32 *state = (u32 *)lbl_1_bss_1800;

    state[0] = arg0;
    state[1] = arg1;
    state[2] = 0;
    return fn_1_1289C(state)[0];
}
/* fzgx:end fn_1_12860 */

/* fzgx:begin fn_1_1289C */
typedef struct LiveCameraLzssArgs {
    u8 *src;
    u8 *dst;
    void (*callback)(u32 size);
} LiveCameraLzssArgs;

u32 *fn_1_1289C(u32 *raw_args) {
    u8 c;
    s32 k;
    u32 size;
    s32 r;
    void (*callback)(u32 size);
    u8 *p;
    u8 *dst;
    u8 *out;
    s32 j;
    u8 text_buf[4096 + 18 - 1];
    s32 i;
    u32 flags;
    u32 end;
    u8 *src;
    LiveCameraLzssArgs *args = (LiveCameraLzssArgs *)raw_args;

    src = args->src;
    callback = args->callback;
    out = args->dst;
    end = __lwbrx(src, 0) + 8;
    size = __lwbrx(src, 4);
    if (end == 0 || size == 0) {
        return NULL;
    }
    p = src + 8;
    dst = out;
    for (i = 0; i < 4096 - 18; i++) {
        text_buf[i] = 0;
    }
    r = 4096 - 18;
    flags = 0;
    for (;;) {
        if (((flags >>= 1) & 0x100) == 0) {
            if (p - src >= end) {
                break;
            }
            flags = *p++ | 0xFF00;
        }
        if (flags & 1) {
            if (p - src >= end) {
                break;
            }
            c = *p++;
            *dst++ = c;
            text_buf[r++] = c;
            r &= 4096 - 1;
        } else {
            if (p - src >= end) {
                break;
            }
            i = p[0];
            if (p + 1 - src >= end) {
                break;
            }
            j = p[1];
            p += 2;
            i |= (j & 0xF0) << 4;
            j = (j & 0x0F) + 2;
            for (k = 0; k <= j; k++) {
                c = text_buf[(i + k) & (4096 - 1)];
                *dst++ = c;
                text_buf[r++] = c;
                r &= 4096 - 1;
            }
        }
    }
    if (callback != NULL) {
        callback(size);
    }
    /* Retail returns this stack-slot address; fn_1_12860 immediately reads it.
     * Preserve the original lifetime bug rather than inventing static storage. */
    return &size;
}
/* fzgx:end fn_1_1289C */

/* fzgx:begin fn_1_12F78 */
u32 fn_1_12F78(void *arg0, u32 arg1) {
    fn_80083DB0(&lbl_1_bss_3B30, arg0);
    lbl_1_bss_3B30.unk_80 = arg1;
    lbl_1_bss_3B30.unk_84 = 0;
    return *fn_1_1304C(&lbl_1_bss_3B30, 0);
}
/* fzgx:end fn_1_12F78 */

/* fzgx:begin fn_1_13018 */
u32 fn_1_13018(void) {
    fn_8000659C();
    return OSIsThreadTerminated(lbl_1_bss_1810) == 0;
}
/* fzgx:end fn_1_13018 */

/* fzgx:begin fn_1_1350C */
extern s32 fn_1_45B2C(void *arg0);
extern void fn_1_458A0(void *arg0, void *arg1, u32 arg2, u32 arg3);

#pragma opt_propagation off
u8 fn_1_1350C(void *arg0, u8 *arg1) {
    s32 size;
    u8 result;
    if (lbl_1_bss_3B28 == 0) {
        size = lbl_1_data_5180;
        /* volatile: the shared streaming state is read in program order, not CSEd or hoisted */
        if (*(volatile u32 *)&lbl_1_bss_3B2C + *(volatile u32 *)&lbl_1_data_5180 > (u32)fn_1_45B2C(arg0)) {
            size = (fn_1_45B2C(arg0) - lbl_1_bss_3B2C + 0x1F) & ~0x1F;
        }
        if (size > 0) {
            fn_1_458A0(arg0, arg1, size, lbl_1_bss_3B2C);
        }
        /* volatile: the two global words are accumulated in the order retail loads them */
        *(volatile u32 *)&lbl_1_bss_3B2C += *(volatile u32 *)&lbl_1_data_5180;
    }
    /* volatile: the index counter is a live shared object, read and advanced as written */
    result = arg1[*(volatile u32 *)&lbl_1_bss_3B28];
    /* volatile: the index counter is a live shared object, read and advanced as written */
    (*(volatile u32 *)&lbl_1_bss_3B28)++;
    /* volatile: the index counter is a live shared object, read and advanced as written */
    if (*(volatile u32 *)&lbl_1_bss_3B28 >= *(volatile u32 *)&lbl_1_data_5180) {
        lbl_1_bss_3B28 = 0;
    }
    return result;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_1350C */
