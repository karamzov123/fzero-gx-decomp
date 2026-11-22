#include "types.h"

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

typedef int (*SVMServerFunction)(void *object);
typedef void (*AdxErrorCallback)(void *object, const char *message);

struct adx_inisBss {
    union {
        unsigned char padding_extent[3096];
        struct {
            int adxt_init_cnt;
        } view_sdk_adxt_init_cnt;
        struct {
            unsigned char padding_sdk_adxt_svr_main_id[8];
            int adxt_svr_main_id;
        } view_sdk_adxt_svr_main_id;
        struct {
            unsigned char padding_sdk_adxt_svr_fs_id[12];
            int adxt_svr_fs_id;
        } view_sdk_adxt_svr_fs_id;
        struct {
            unsigned char padding_sdk_adxt_vsync_cnt[16];
            int adxt_vsync_cnt;
        } view_sdk_adxt_vsync_cnt;
        struct {
            unsigned char padding_sdk_cri_verstr_ptr[20];
            const char *cri_verstr_ptr;
        } view_sdk_cri_verstr_ptr;
        struct {
            unsigned char padding_sdk_adxt_obj[20];
            ADXTHandle adxt_obj[16];
        } view_sdk_adxt_obj;
    } fields;
};
extern struct adx_inisBss lbl_80178CA8;

extern void fn_80058630(void);
extern void fn_80058B54(void);
extern void fn_800592E0(int server_type, int id);
extern void ADXT_DestroyAll(void);
extern void fn_8004EF68(void);
extern void fn_8004F6B0(void);
extern void fn_8004B79C(void);
extern void fn_80057378(void);
extern void fn_80046738(void);
extern void fn_80046718(void);
extern void fn_800424B8(void);
extern void fn_80047578(void);
extern void fn_80057CC4(void);
extern void fn_8005870C(void);

extern void fn_80058680(void);
extern void fn_80058BFC(void);
extern int fn_80059428(int server_type, SVMServerFunction function, void *object);
extern void fn_8005912C(int server_type, int id, SVMServerFunction function, void *object);
extern void *memset(void *destination, int value, unsigned long size);
extern void fn_80046758(void);
extern void fn_80058754(void);
extern void fn_80057D0C(void);
extern void fn_800475C0(void);
extern void fn_8004B7A0(void);
extern void fn_800424E8(void);
extern void fn_8004F74C(void);
extern void fn_8004EF88(void);
extern void fn_8005741C(void);
extern void fn_8004EF48(AdxErrorCallback callback, void *object);
extern void fn_800566BC(AdxErrorCallback callback, void *object);
extern int fn_8004E580(void);
extern int lbl_8012B6E8;
extern const f64 lbl_80090010;
extern u32 fn_80047608(void);
extern u32 fn_8004BDD8(void);
extern u32 fn_80056C64(void);
extern u32 fn_800474E4(const char *, const char *);

int fn_80041330(void *object);
int fn_80041354(void *object);
int fn_80041378(void *object);
int fn_800413A4(void *object);
void fn_800413C8(void *object, const char *message);
void fn_800413EC(void *object, const char *message);

void ADXT_Finish(void) {
    struct adx_inisBss *bss = &lbl_80178CA8;

    (bss->fields.view_sdk_adxt_init_cnt.adxt_init_cnt)--;
    if (bss->fields.view_sdk_adxt_init_cnt.adxt_init_cnt == 0) {
        fn_8004EF68();
        fn_8004F6B0();
        fn_8004B79C();
        fn_80057378();
        fn_80046738();
        fn_800592E0(2, 1);
        fn_800592E0(4, bss->fields.view_sdk_adxt_svr_fs_id.adxt_svr_fs_id);
        fn_800592E0(5, bss->fields.view_sdk_adxt_svr_main_id.adxt_svr_main_id);
        fn_80058B54();
        fn_800424B8();
        fn_80047578();
        fn_80057CC4();
        fn_80058630();
        fn_8005870C();
        fn_80046718();
    }
}

void fn_800411F4(void) {
    struct adx_inisBss *bss = &lbl_80178CA8;

    *(volatile u32 *)&lbl_80090010; /* The SDK probes the pooled version word. */
    if (bss->fields.view_sdk_adxt_init_cnt.adxt_init_cnt == 0) {
        fn_80046758();
        fn_80046738();
        fn_80058754();
        fn_80058680();
        fn_80057D0C();
        fn_800475C0();
        fn_8004B7A0();
        fn_800424E8();
        fn_8004F74C();
        fn_8004EF88();
        fn_8005741C();
        fn_80058BFC();
        fn_8004EF48(fn_800413EC, 0);
        fn_800566BC(fn_800413C8, 0);
        memset(bss->fields.view_sdk_adxt_obj.adxt_obj, 0,
               sizeof(bss->fields.view_sdk_adxt_obj.adxt_obj));
        if (fn_8004E580() == 1 && lbl_8012B6E8 == 1) {
            fn_8005912C(2, 1, fn_80041354, 0);
            bss->fields.view_sdk_adxt_svr_fs_id.adxt_svr_fs_id = fn_80059428(4, fn_80041330, 0);
            bss->fields.view_sdk_adxt_svr_main_id.adxt_svr_main_id =
                fn_80059428(5, fn_800413A4, 0);
        } else {
            bss->fields.view_sdk_adxt_svr_main_id.adxt_svr_main_id =
                fn_80059428(5, fn_80041378, 0);
        }
        bss->fields.view_sdk_adxt_vsync_cnt.adxt_vsync_cnt = 0;

        fn_80046718();
    }
    (bss->fields.view_sdk_adxt_init_cnt.adxt_init_cnt)++;
}

int fn_80041330(void *object) {
    fn_80047608();
    return 0;
}

int fn_80041354(void *object) {
    fn_8004BDD8();
    return 0;
}

int fn_80041378(void *object) {
    fn_8004BDD8();
    fn_80047608();
    fn_80056C64();
    return 0;
}

int fn_800413A4(void *object) {
    fn_80056C64();
    return 0;
}

void fn_800413C8(void *object, const char *message) {
    fn_800474E4(message, message);
}

void fn_800413EC(void *object, const char *message) {
    fn_800474E4(message, message);
}
