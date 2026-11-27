#include "types.h"

/* fzgx:begin fn_12_388C4 noprologue */
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
/* fzgx:end fn_12_388C4 */

/* fzgx:begin fn_12_38A0C noprologue */

/* --- rel/movie_module/fn_12_38A0C.c --- */
extern u32 lbl_12_bss_1BAAC[1131];

s32 fn_12_38A0C(s32 arg) {
    lbl_12_bss_1BAAC[25] = arg;
    return arg & ~(-(s32)(arg == 0));
}
/* fzgx:end fn_12_38A0C */

/* fzgx:begin fn_12_38A2C noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_38A2C.c --- */
typedef struct MoviePlayer {
    void *interface;
    s32 active;
} MoviePlayer;

typedef struct Movie {
    u8 pad[0x68];
    MoviePlayer player;
    u8 tail[0x228 - 0x70];
} Movie;

extern u32 lbl_12_bss_1B9D8;
extern u32 lbl_12_bss_1BAAC[1131];

extern void mwSfdDestroy(void *);
extern void fn_12_34DB4(void);
extern void fn_12_34CEC(void);
extern void fn_12_34D50(void);
extern void fn_12_35DBC(void);
extern void fn_80057378(void);
extern void fn_12_24B80(void);
extern void ADXT_Finish(void);
extern void fn_12_34FFC(void);
extern void fn_8005870C(void);
extern void fn_80057CC4(void);
extern void fn_80058630(void);
extern void fn_12_34E2C(void);

void fn_12_38A2C(void) {
    Movie *movie = (Movie *)lbl_12_bss_1BAAC;
    int i;

    if (--lbl_12_bss_1B9D8 == 0) {
        for (i = 0; i < 8; i++) {
            MoviePlayer *player = &movie[i].player;
            if (player->active == 1) {
                mwSfdDestroy(player);
            }
        }
        fn_12_34DB4();
        fn_12_34CEC();
        fn_12_34D50();
        fn_12_35DBC();
        fn_80057378();
        fn_12_24B80();
        ADXT_Finish();
        fn_12_34FFC();
        fn_8005870C();
        fn_80057CC4();
        fn_80058630();
        fn_12_34E2C();
    }
}
/* fzgx:end fn_12_38A2C */

/* fzgx:begin fn_12_38AD0 noprologue */

/* --- rel/movie_module/fn_12_38AD0.c --- */
u32 fn_12_38AD0(void) {
    return lbl_12_bss_1BAAC[15];
}
/* fzgx:end fn_12_38AD0 */

/* fzgx:begin fn_12_38AE0 noprologue */

/* --- rel/movie_module/fn_12_38AE0.c --- */
u32 fn_12_38AE0(void) {
    return lbl_12_bss_1BAAC[14];
}
/* fzgx:end fn_12_38AE0 */

/* fzgx:begin fn_12_38AF0 noprologue */
#include "types.h"
#pragma readonly_strings on

/* mwPlyInitSfdFx (mwsfdlib.c, CRI Sofdec middleware), GX version. The TU's objects
 * are defined under their retail names; donor names are in the comments. */

typedef struct SfdTransportInterface SfdTransportInterface;

typedef struct SfdTransportRegistry {
    const SfdTransportInterface *entries[15];
} SfdTransportRegistry;

typedef struct SfdLibraryConfig {
    const SfdTransportRegistry *transport_registry;
    int timer_source;
} SfdLibraryConfig;

typedef struct MwsInitParam {
    float frame_rate;
    int max_width;
    int decoder_count;
    int field_0C;
} MwsInitParam;

typedef struct MwsLibraryWork {
    int field_00;
    float frame_rate;
    int max_width;
    int decoder_count;
    int field_10;
    unsigned char reserved_014[0x24];
    int use_picture_user_data;
    int pause_border;
    unsigned char reserved_040[0x18];
    int field_58;
    unsigned char reserved_05C[0x08];
    int error_code;
    unsigned char players[8][0x228];
} MwsLibraryWork;

extern const SfdTransportInterface lbl_12_rodata_B58; /* SFD_tr_in_mem */
extern const SfdTransportInterface lbl_12_rodata_B90; /* SFD_tr_sd_mps */
extern const SfdTransportInterface lbl_12_rodata_BD8; /* SFD_tr_vd_mpv */
extern const SfdTransportInterface lbl_12_rodata_EC8; /* SFD_tr_vo_manu */
extern const SfdTransportInterface lbl_12_rodata_A18; /* SFD_tr_ad_adxt */
extern const SfdTransportInterface lbl_12_rodata_A80; /* SFD_tr_ao_auto_p */
extern const SfdTransportInterface lbl_12_rodata_E90; /* SFD_tr_uo */

/* mwsfd_ver_str */
static const char lbl_12_rodata_2270[0x54] =
    "\nMWSFD/GC Ver.2.73 Build:May  9 2003 15:17:37\n\0"
    "Append: MW2407 GC05Sep2002Patch3\n";
/* mwsfd_trentry */
static const SfdTransportRegistry lbl_12_rodata_22C4 = {{
    &lbl_12_rodata_B58, &lbl_12_rodata_B90, &lbl_12_rodata_BD8, &lbl_12_rodata_EC8,
    &lbl_12_rodata_A18, &lbl_12_rodata_A80, &lbl_12_rodata_E90,
    0, 0, 0, 0, 0, 0, 0, 0
}};
/* mwsfd_initsfdpara */
static const SfdLibraryConfig lbl_12_rodata_22C4__fzgx_offset_3C = {&lbl_12_rodata_22C4, 0xEA24};
/* mwsfd_siz_mwplyhn */
static const int lbl_12_rodata_22C4__fzgx_offset_44[1] = {0x228};
static const char lbl_12_rodata_22C4__fzgx_offset_48[] = "DATA ERROR(%08X)";
static const char lbl_12_rodata_22C4__fzgx_offset_5C[] = "SFD ERROR(%08X): width, height of cprm is short.";
static const char lbl_12_rodata_22C4__fzgx_offset_90[] =
    "SFD ERROR(%08X): Picture data size is large. Please increase MAXBPS of creation parameter.";
static const char lbl_12_rodata_22C4__fzgx_offset_EC[] = "SFD ERROR(%08X)";
/* compatible_version */
static const char lbl_12_rodata_22C4__fzgx_offset_FC[] = "1.852";
/* incompatible_version */
static const char lbl_12_rodata_22C4__fzgx_offset_104[] = "E011081 mwPlySfdInit: Not compatible SFD Version.";

static int lbl_12_bss_1B9D8;                       /* mwsfd_init_cnt */
static int lbl_12_bss_1B9DC;                       /* mwsfd_init_flag */
static unsigned char lbl_12_bss_1B9DC__fzgx_offset_4[0xCC];
static MwsLibraryWork lbl_12_bss_1BAAC;            /* mwsfd_libwork */
static const char *lbl_12_bss_1BAAC__fzgx_offset_11A8; /* cri_verstr_ptr */

extern int lbl_12_bss_1CC5C; /* mwg_vcnt */

#pragma section code_type ".fzgxpool"
static void mwsfdlib_layout(void) {
    const void *volatile object; /* fzgx-allow: S2 TU object first-access order */
    volatile float f; /* fzgx-allow: S2 TU literal first-use order */
    volatile double d; /* fzgx-allow: S2 TU literal first-use order */
    object = &lbl_12_bss_1B9D8;
    object = &lbl_12_bss_1B9DC;
    object = lbl_12_bss_1B9DC__fzgx_offset_4;
    object = &lbl_12_bss_1BAAC;
    object = &lbl_12_bss_1BAAC__fzgx_offset_11A8;
    object = lbl_12_rodata_2270;
    object = &lbl_12_rodata_22C4;
    object = &lbl_12_rodata_22C4__fzgx_offset_3C;
    object = lbl_12_rodata_22C4__fzgx_offset_44;
    object = lbl_12_rodata_22C4__fzgx_offset_48;
    object = lbl_12_rodata_22C4__fzgx_offset_5C;
    object = lbl_12_rodata_22C4__fzgx_offset_90;
    object = lbl_12_rodata_22C4__fzgx_offset_EC;
    object = lbl_12_rodata_22C4__fzgx_offset_FC;
    object = lbl_12_rodata_22C4__fzgx_offset_104;
    f = 59.94f;
    object = "E1122611 mwPlyInitSfdFx: iprm is NULL.";
    object = "E2005 mwPlyInitSfdFx: can't init GSC";
    d = 0.5;
    f = 1000.0f;
    object = "ERR20010421A : mwPlyInitSfdFx";
}
#pragma section code_type ".text"

extern void MWSFSVM_Error(const char *message, ...);
extern void fn_12_34E4C(void);               /* MWSFSVM_Init */
extern void fn_800411F4(void);               /* ADXT_Init */
extern void fn_80058680(void);               /* SJRBF_Init */
extern void fn_80057D0C(void);               /* SJMEM_Init */
extern void fn_80058754(void);               /* SJUNI_Init */
extern int fn_12_35004(void);                /* MWSTM_InitStatic */
extern void *memset(void *, int, unsigned long);
extern void fn_12_3A970(int enabled);        /* MWSFSVR_SetMwsfdSvrFlg */
extern int fn_12_24D68(const char *version, int handle_size); /* SFD_IsVersionCompatible */
extern int fn_12_24C48(SfdLibraryConfig *config);            /* SFD_Init */
extern void fn_12_388C4(int object, int error);              /* MWSFLIB_SfdErrFunc */
extern int fn_12_249BC(void *handle, void (*callback)(int, int), void *object); /* SFD_SetErrFn */
extern void fn_12_3A3CC(void *player, int condition, int value); /* MWSFD_SetCond */
extern void fn_8005741C(void);               /* LSC_Init */
extern void fn_12_38D94(void);               /* mwsflib_LscErrFunc */
extern void fn_800566BC(void (*callback)(void), void *object); /* LSC_EntryErrFunc */
extern void fn_12_35E04(void);               /* MWSFSFX_Init */
extern int fn_12_3ADC4(void *object);        /* MWSFSVR_VsyncThrdProc */
extern int fn_12_3ACD0(void *object);        /* MWSFSVR_MainThrdProc */
extern int fn_12_3AC70(void *object);        /* MWSFSVR_IdleThrdProc */
extern void fn_12_34DE4(int id, int (*function)(void *), void *object); /* MWSFSVM_EntryIdVfunc */
extern void fn_12_34D1C(int (*function)(void *), void *object);          /* MWSFSVM_EntryMainFunc */
extern void fn_12_34D80(int (*function)(void *), void *object);          /* MWSFSVM_EntryIdleFunc */

static inline int MWSFLIB_SetErrCode(int error) {
    lbl_12_bss_1BAAC.error_code = error;
    if (error == 0) {
        return 0;
    }
    return error;
}

static inline void mwsflib_SetLibPrm(void *library, MwsInitParam *parameter) {
    MwsLibraryWork *work = (MwsLibraryWork *)library;
    if (parameter != 0) {
        work->frame_rate = parameter->frame_rate;
        work->max_width = parameter->max_width;
        work->decoder_count = parameter->decoder_count;
        work->field_10 = parameter->field_0C;
    } else {
        work->frame_rate = 59.94f;
        work->max_width = 1;
        work->decoder_count = 1;
        work->field_10 = 0;
    }
}

static inline void mwsflib_InitLibWork(MwsInitParam *parameter) {
    MwsLibraryWork *work;

    work = &lbl_12_bss_1BAAC;
    memset(work, 0, sizeof(lbl_12_bss_1BAAC));
    fn_12_3A970(0);
    work->field_58 = 0;
    mwsflib_SetLibPrm(work, parameter);
    work->use_picture_user_data = 1;
    work->pause_border = 1;
}

static inline int mwPlySfdInit(int timer_source) {
    SfdLibraryConfig sfd_parameters;
    int result;

    sfd_parameters = lbl_12_rodata_22C4__fzgx_offset_3C;
    sfd_parameters.timer_source = timer_source;
    if (fn_12_24D68(lbl_12_rodata_22C4__fzgx_offset_FC, 0x29D8) != 1) {
        MWSFSVM_Error(lbl_12_rodata_22C4__fzgx_offset_104);
        result = -1;
    } else if (fn_12_24C48(&sfd_parameters) != 0) {
        result = MWSFLIB_SetErrCode(-0x12D);
    } else if (fn_12_249BC(0, fn_12_388C4, 0) != 0) {
        result = MWSFLIB_SetErrCode(-0x12F);
    } else {
        result = 0;
    }
    return result;
}

void fn_12_38AF0(MwsInitParam *parameter) {
    if (parameter == 0) {
        MWSFSVM_Error("E1122611 mwPlyInitSfdFx: iprm is NULL.");
        return;
    }
    lbl_12_bss_1BAAC__fzgx_offset_11A8 = lbl_12_rodata_2270;
    fn_12_34E4C();
    parameter->decoder_count -= 2;
    if (parameter->decoder_count < 0) {
        parameter->decoder_count = 0;
    }
    if (lbl_12_bss_1B9D8 == 0) {
        fn_800411F4();
        fn_80058680();
        fn_80057D0C();
        fn_80058754();
        if (fn_12_35004() != 0) {
            MWSFLIB_SetErrCode(-0x65);
            MWSFSVM_Error("E2005 mwPlyInitSfdFx: can't init GSC");
        }
        mwsflib_InitLibWork(parameter);
        lbl_12_bss_1CC5C = 0;
        if (mwPlySfdInit((int)(0.5 + parameter->frame_rate * 1000.0f)) != 0) {
            MWSFSVM_Error("ERR20010421A : mwPlyInitSfdFx");
        }
        lbl_12_bss_1B9DC = 1;
        fn_12_3A3CC(0, 0x1B, parameter->frame_rate);
        fn_12_3A3CC(0, 7, 1);
        fn_8005741C();
        fn_800566BC(fn_12_38D94, 0);
        fn_12_35E04();
        fn_12_34DE4(2, fn_12_3ADC4, 0);
        fn_12_34D1C(fn_12_3ACD0, 0);
        fn_12_34D80(fn_12_3AC70, 0);
    }
    lbl_12_bss_1B9D8++;
}
/* fzgx:end fn_12_38AF0 */

/* fzgx:begin fn_12_38D94 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_38D94.c --- */
/* --- rel/movie_module/fn_12_38D94.c --- */
extern void MWSFSVM_Error(void *, ...);

void fn_12_38D94(void *arg0, void *arg1) {
    MWSFSVM_Error(arg1);
}
/* fzgx:end fn_12_38D94 */

/* fzgx:begin fn_12_38DBC noprologue */

/* --- rel/movie_module/fn_12_38DBC.c --- */
extern u32 lbl_12_bss_1BAAC[1131];

u32 *fn_12_38DBC(void) {
    return lbl_12_bss_1BAAC;
}
/* fzgx:end fn_12_38DBC */
