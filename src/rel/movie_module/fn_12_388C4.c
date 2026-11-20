#include "types.h"


/* --- rel/movie_module/fn_12_388C4.c --- */
typedef int SfdCallbackObject;

typedef struct SfdHandle SfdHandle;

struct mwsfdlib____rodata_0 {
    union {
        unsigned char padding_extent[429];
        struct {
            unsigned char padding_sdk_data_error[156];
            const char data_error[17];
        } view_sdk_data_error;
        struct {
            unsigned char padding_sdk_creation_small[176];
            const char creation_small[94];
        } view_sdk_creation_small;
        struct {
            unsigned char padding_sdk_read_buffer_small[228];
            const char read_buffer_small[81];
        } view_sdk_read_buffer_small;
        struct {
            unsigned char padding_sdk_frame_pool_invalid[320];
            const char frame_pool_invalid[109];
        } view_sdk_frame_pool_invalid;
    } fields;
};
extern struct mwsfdlib____rodata_0 lbl_12_rodata_2270;

struct mwsfdlibBss {
    union {
        unsigned char padding_extent[212];
        struct {
            unsigned char padding_sdk_mwsfd_err_sfdhn[8];
            SfdHandle *mwsfd_err_sfdhn;
        } view_sdk_mwsfd_err_sfdhn;
        struct {
            unsigned char padding_sdk_mwsfd_err_mwsfdhn[12];
            void *mwsfd_err_mwsfdhn;
        } view_sdk_mwsfd_err_mwsfdhn;
        struct {
            unsigned char padding_sdk_mwg_sfd_errstr[16];
            char mwg_sfd_errstr[128];
        } view_sdk_mwg_sfd_errstr;
        struct {
            unsigned char padding_sdk_mwg_sfd_errcnt[144];
            int mwg_sfd_errcnt;
        } view_sdk_mwg_sfd_errcnt;
        struct {
            unsigned char padding_sdk_mwg_sfd_errcode[148];
            int mwg_sfd_errcode[16];
        } view_sdk_mwg_sfd_errcode;
    } fields;
};
extern struct mwsfdlibBss lbl_12_bss_1B9D8;

void fn_12_388C4(SfdCallbackObject object, int error);

int sprintf(char *output, const char *format, ...);

extern SfdHandle *fn_12_3A7D8(void *player);

extern void MWSFSVM_Error(const char *message, ...);

void fn_12_388C4(SfdCallbackObject object, int error) {
    struct mwsfdlib____rodata_0 *data = &lbl_12_rodata_2270;

    struct mwsfdlibBss *bss = &lbl_12_bss_1B9D8;

    void *player = (void *)object;
    if (player != 0) {
        SfdHandle *sfd = fn_12_3A7D8(player);
        (bss->fields.view_sdk_mwsfd_err_mwsfdhn.mwsfd_err_mwsfdhn) = player;
        (bss->fields.view_sdk_mwsfd_err_sfdhn.mwsfd_err_sfdhn) = sfd;
    } else {
        (bss->fields.view_sdk_mwsfd_err_mwsfdhn.mwsfd_err_mwsfdhn) = 0;
        (bss->fields.view_sdk_mwsfd_err_sfdhn.mwsfd_err_sfdhn) = 0;
    }
    if (error != 0) {
        int *errcode = bss->fields.view_sdk_mwg_sfd_errcode.mwg_sfd_errcode;
        int count = bss->fields.view_sdk_mwg_sfd_errcnt.mwg_sfd_errcnt;
        errcode += count;
        *errcode = error;
        if (count < 15) {
            bss->fields.view_sdk_mwg_sfd_errcnt.mwg_sfd_errcnt = count + 1;
        }
    }
    switch (error) {
    case 0xFFFFFFFD:
    case 0xFFFFFFFE:
        sprintf((bss->fields.view_sdk_mwg_sfd_errstr.mwg_sfd_errstr),
                (data->fields.view_sdk_data_error.data_error), error);
        break;
    case 0xFF000F17:
    case 0xFF000F18:
        sprintf((bss->fields.view_sdk_mwg_sfd_errstr.mwg_sfd_errstr),
                (data->fields.view_sdk_creation_small.creation_small), error);
        break;
    case 0xFF000F1C:
        sprintf((bss->fields.view_sdk_mwg_sfd_errstr.mwg_sfd_errstr),
                (data->fields.view_sdk_read_buffer_small.read_buffer_small), error);
        break;
    default:
        sprintf((bss->fields.view_sdk_mwg_sfd_errstr.mwg_sfd_errstr),
                (data->fields.view_sdk_frame_pool_invalid.frame_pool_invalid), error);
        break;
    }
    MWSFSVM_Error((bss->fields.view_sdk_mwg_sfd_errstr.mwg_sfd_errstr));
}

/* --- rel/movie_module/fn_12_38A0C.c --- */
extern u32 lbl_12_bss_1BAAC[1131];

s32 fn_12_38A0C(s32 arg) {
    lbl_12_bss_1BAAC[25] = arg;
    return arg & ~(-(s32)(arg == 0));
}
