/* Non-matching: best partial attempt (81.88% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
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

typedef struct {
    u16 unk_0;
    u8 unk_2;
    u8 pad_3;
    u16 unk_4;
} Element_92FC;

struct fn_14_8600_lbl_14_data_0 {
    u8 pad_0[0x2F64];
    u32 unk_2F64[6];
    u32 unk_2F7C[3];
    u32 unk_2F88[10];
};

struct Struct_38460_GrandChild {
    u8 pad_0[0x50];
    u32 val_50;
};
struct Struct_38460_Child {
    u8 pad_0[0x8];
    struct Struct_38460_GrandChild *child;
};
struct Struct_38460 {
    u8 pad_0[0x10];
    struct Struct_38460_Child *ptr_10;
    struct Struct_38460_Child *ptr_14;
};

typedef struct {
    Sig_ADXT_Stop_ADXTHandle *handle;
    u32 unk_4;
} Obj_1_bss_6EAD0_At0;

typedef struct {
    Obj_1_bss_6EAD0_At0 *unk_0;
    u8 pad_4[0x704];
} Obj_1_bss_6EAD0;

extern Element_92FC lbl_14_bss_92FC[];
extern struct fn_14_8600_lbl_14_data_0 lbl_14_data_0;
extern Obj_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct Struct_38460 lbl_1_bss_38460;
extern s32 lbl_801A66B4;
extern u32 lbl_14_bss_18;

extern void fn_1_47F74(s32);
extern void fn_80008BEC(void *, int, u32);
extern u32 OSGetTick(void);
extern s16 fn_1_14F270(s16, void *, u32);
extern int fn_1_F8334(s16);
extern void fn_1_F83F0(s16);
extern void fn_1_F8B50(void);
extern u32 fn_1_A1588(Sig_ADXT_Stop_ADXTHandle *, u32);
extern void fn_1_411A4(u32);

void fn_14_8600(void) {
    struct fn_14_8600_lbl_14_data_0 *p_lbl_14_data_0;
    u32 tick;
    u32 val;
    s16 idx;
    s16 total_count;
    s16 next;
    Element_92FC *p;
    u8 count;
    u8 iter;
    u32 mask;
    s32 bit;

    p_lbl_14_data_0 = (struct fn_14_8600_lbl_14_data_0 *)&lbl_14_data_0;
    fn_1_47F74(141);
    fn_1_47F74(151);
    fn_80008BEC(lbl_14_bss_92FC, 0xFF, 0x144);
    tick = OSGetTick();
    lbl_14_bss_92FC[0].unk_0 = 0;
    lbl_14_bss_92FC[0].unk_2 = 0x20;
    val = p_lbl_14_data_0->unk_2F64[(u8)(tick % 6)];
    lbl_14_bss_92FC[0].unk_4 = val;
    idx = (u16)val != 0x8D00;
    lbl_14_bss_92FC[idx].unk_0 = 1;
    tick = OSGetTick();
    total_count = idx + 1;
    lbl_14_bss_92FC[idx].unk_2 = (tick % 10) + 31;
    lbl_14_bss_92FC[idx].unk_4 = p_lbl_14_data_0->unk_2F88[lbl_14_bss_92FC[idx].unk_2 - 31];
    lbl_14_bss_92FC[total_count].unk_0 = 2;
    lbl_14_bss_92FC[total_count].unk_2 = 0;
    lbl_14_bss_92FC[total_count].unk_4 = p_lbl_14_data_0->unk_2F7C[0];
    p = &lbl_14_bss_92FC[total_count];
    count = 0;
    iter = 0;
    mask = 1;
    while (mask != 0 && iter < 12) {
        bit = 31 - __cntlzw(mask);
        if ((u32)bit < 12) {
            p->unk_0 = 2;
            p->unk_2 = fn_1_14F270(bit, (void *)0, 0x80000000);
            p->unk_4 = p_lbl_14_data_0->unk_2F7C[0];
            if (fn_1_F8334(p->unk_2) == 0) {
                fn_1_F83F0(p->unk_2);
                p++;
                count++;
            }
        }
        iter++;
        mask &= ~(0x80000000 >> (31 - bit));
    }
    total_count += count;

    lbl_14_bss_92FC[total_count].unk_0 = 3;
    lbl_14_bss_92FC[total_count].unk_2 = 0;
    lbl_14_bss_92FC[total_count].unk_4 = p_lbl_14_data_0->unk_2F7C[1];
    p = &lbl_14_bss_92FC[total_count];
    count = 0;
    iter = 0;
    mask = 1;
    while (mask != 0 && iter < 12) {
        bit = 31 - __cntlzw(mask);
        if ((u32)bit < 12) {
            p->unk_0 = 3;
            p->unk_2 = fn_1_14F270(bit, (void *)1, 0x80000000);
            p->unk_4 = p_lbl_14_data_0->unk_2F7C[1];
            if (fn_1_F8334(p->unk_2) == 0) {
                fn_1_F83F0(p->unk_2);
                p++;
                count++;
            }
        }
        iter++;
        mask &= ~(0x80000000 >> (31 - bit));
    }
    total_count += count;

    lbl_14_bss_92FC[total_count].unk_0 = 4;
    lbl_14_bss_92FC[total_count].unk_2 = 0;
    lbl_14_bss_92FC[total_count].unk_4 = p_lbl_14_data_0->unk_2F7C[2];
    p = &lbl_14_bss_92FC[total_count];
    count = 0;
    iter = 0;
    mask = 1;
    while (mask != 0 && iter < 12) {
        bit = 31 - __cntlzw(mask);
        if ((u32)bit < 12) {
            p->unk_0 = 4;
            p->unk_2 = fn_1_14F270(bit, (void *)2, 0x80000000);
            p->unk_4 = p_lbl_14_data_0->unk_2F7C[2];
            if (fn_1_F8334(p->unk_2) == 0) {
                fn_1_F83F0(p->unk_2);
                p++;
                count++;
            }
        }
        iter++;
        mask &= ~(0x80000000 >> (31 - bit));
    }
    total_count += count;

    lbl_14_bss_92FC[total_count].unk_0 = 5;
    lbl_14_bss_92FC[total_count].unk_2 = 0;
    lbl_14_bss_92FC[total_count].unk_4 = 0x8D10;
    fn_1_F8B50();

    next = total_count + 1;
    lbl_14_bss_92FC[next].unk_0 = 6;
    lbl_14_bss_92FC[next].unk_2 = 0;
    lbl_14_bss_92FC[next].unk_4 = 0x8D15;
    lbl_14_bss_92FC[next + 1].unk_0 = -1;
    lbl_14_bss_92FC[next + 1].unk_2 = 0xFF;
    lbl_14_bss_92FC[next + 1].unk_4 = -1;

    fn_1_A1588(lbl_1_bss_6EAD0.unk_0->handle, 29);

    if (lbl_801A66B4 == 5) {
        fn_1_411A4(4);
        if (lbl_1_bss_38460.ptr_10 != 0) {
            lbl_14_bss_18 = lbl_1_bss_38460.ptr_10->child->val_50;
        }
    } else {
        fn_1_411A4(5);
        if (lbl_1_bss_38460.ptr_14 != 0) {
            lbl_14_bss_18 = lbl_1_bss_38460.ptr_14->child->val_50;
        }
    }
}
