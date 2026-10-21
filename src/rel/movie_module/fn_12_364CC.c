#include "types.h"
#pragma readonly_strings on

typedef struct SJ SJ;
typedef struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
} SJInterface;
struct SJ {
    const SJInterface *interface;
};

typedef struct SfdHandle SfdHandle;
typedef struct LSC LSC;
typedef struct SFXHandle SFXHandle;
typedef struct ADXStream ADXStream;
typedef struct SfdTransportInterface SfdTransportInterface;

typedef struct SfdTransportSetup {
    const SfdTransportInterface *entries[9];
} SfdTransportSetup;

typedef struct MwsCreateParams {
    int file_type;
    int maximum_bps;
    int width;
    int height;
    int frame_count;
    int decoder_count;
    void *work;
    int work_size;
    int composition_mode;
    int buffer_format;
    int field_28;
    int field_2C;
} MwsCreateParams;

typedef struct MwsPictureUserConfig {
    void *buffer;
    int buffer_size;
    int element_size;
} MwsPictureUserConfig;

typedef struct MwsStHandle {
    int active;
    unsigned char reserved_004[8];
    SJ *stream;
    int element_id;
    void *backend;
} MwsStHandle;

typedef struct MwsPlayer {
    const void *interface;
    int active;
    int status;
    MwsCreateParams create;
    int playback_mode;
    SfdHandle *sfd;
    ADXStream *stream;
    void *transport;
    LSC *loader;
    int field_050;
    int field_054;
    int flow_limit;
    int field_05C;
    unsigned char reserved_060[8];
    int field_068;
    int field_06C;
    signed char concat_play;
    signed char concat_stopped;
    signed char paused;
    unsigned char field_073;
    int entry_count;
    unsigned char reserved_078[12];
    int field_084;
    unsigned char reserved_088[0x20];
    SFXHandle *sfx;
    void *composition_work;
    int composition_work_size;
    unsigned char reserved_0B4[0x20];
    MwsPictureUserConfig *picture_user;
    unsigned char reserved_0D8[0x10];
    SJ *additional_info_sj;
    unsigned char reserved_0EC[0x40];
    SJ *input_sj;
    void *input_buffer;
    int input_buffer_size;
    int input_buffer_extra_size;
    unsigned char reserved_13C[0x10];
    SJ *memory_sj;
    unsigned char reserved_150[8];
    void *arena;
    unsigned int arena_size;
    unsigned char *arena_cursor;
    unsigned int arena_used;
    int allocation_count;
    void *allocations[32];
    MwsStHandle sound;
    unsigned char reserved_204[0x24];
} MwsPlayer;

typedef void *(*MwsMallocFn)(void *object, long size);
typedef void (*MwsFreeFn)(void *object, void *memory);

typedef struct MwsLibraryWork {
    int field_00;
    float frame_rate;
    int video_frequency;
    int frame_pool;
    int field_10;
    unsigned char reserved_014[0x14];
    MwsMallocFn malloc_fn;
    MwsFreeFn free_fn;
    void *allocator_object;
    unsigned char reserved_034[0x34];
    MwsPlayer players[8];
} MwsLibraryWork;

typedef struct MW_PLY_OBJ {
    struct MwsPlayerInterface *interface;
} MW_PLY_OBJ;
typedef MW_PLY_OBJ *MWPLY;

typedef struct MwsPlayerInterface {
    void *reserved[3];
} MwsPlayerInterface;

extern void MWSFSVM_Error(const char *, ...);
extern MwsLibraryWork *fn_12_38DBC(void);
extern int fn_12_38A0C(int);
extern SfdHandle *fn_12_3763C(MwsPlayer *, MwsCreateParams *);
extern void fn_12_390E4(MwsPlayer *);
extern void fn_12_35484(MwsPlayer *);
extern void fn_12_35D74(SFXHandle *);
extern void fn_80057114(LSC *);
extern void fn_12_34F64(ADXStream *);
extern int fn_12_2B6B0(SfdHandle *);
extern void fn_12_3B15C(MwsStHandle *);
extern void *memset(void *, int, unsigned long);
extern int fn_12_38AE0(void);
extern int fn_12_2A434(SfdHandle *, void *, int, int);
extern int fn_12_2D888(SfdHandle *, int, int);
extern int fn_12_2A5C8(SfdHandle *, int, int);
extern SJ *fn_80058498(void *, int, int);
extern SJ *fn_80057B9C(void *, int);
extern int fn_12_2D500(SfdHandle *, int, void **);
extern void fn_12_3A968(MwsPlayer *, int);
extern void fn_12_3A960(MwsPlayer *, int);
extern ADXStream *fn_12_34F84(SJ *);
extern void fn_12_38DC8(MwsPlayer *);
extern LSC *fn_800571EC(SJ *);
extern void fn_8005710C(LSC *, ADXStream *);
extern int fn_12_36208(MwsPlayer *);
extern SFXHandle *fn_12_35D94(void *, int, int, int);
extern void fn_12_356E8(MwsPlayer *, int);
extern SJ *fn_12_354BC(MwsPlayer *);
extern int fn_12_35418(MwsPlayer *);
extern void fn_12_353FC(MwsPlayer *);

extern MwsPlayerInterface lbl_12_data_D38;
extern const SfdTransportInterface lbl_12_rodata_A18;
extern const SfdTransportInterface lbl_12_rodata_A80;
extern const SfdTransportInterface lbl_12_rodata_B58;
extern const SfdTransportInterface lbl_12_rodata_B90;
extern const SfdTransportInterface lbl_12_rodata_BD8;
extern const SfdTransportInterface lbl_12_rodata_E90;
extern const SfdTransportInterface lbl_12_rodata_EC8;

static const SfdTransportSetup lbl_12_rodata_1D88 = {{
    &lbl_12_rodata_B58, &lbl_12_rodata_B90, &lbl_12_rodata_BD8, &lbl_12_rodata_A18,
    0, 0, &lbl_12_rodata_EC8, &lbl_12_rodata_A80, &lbl_12_rodata_E90}};
static const SfdTransportSetup lbl_12_rodata_1DAC = {{
    &lbl_12_rodata_B58, 0, &lbl_12_rodata_BD8, 0, 0, 0, &lbl_12_rodata_EC8, 0, 0}};
static const SfdTransportSetup lbl_12_rodata_1DD0 = {{
    &lbl_12_rodata_B58, &lbl_12_rodata_B90, &lbl_12_rodata_BD8, 0, 0, 0,
    &lbl_12_rodata_EC8, 0, &lbl_12_rodata_E90}};
static const char lbl_12_rodata_1DF4[] = "E2053001 MWSFD_Malloc: cnt over.";
static const char lbl_12_rodata_1E18[0x28] = "E204161: mwPlyGetHdrInf(): NULL pointer";
static const char lbl_12_rodata_1E40[] = "E204162: mwPlyGetHdrInf(): bufsize error";
static const char lbl_12_rodata_1E6C[0x20] = "E20010703E MWSFCRE_DestroySfd: ";
static const char lbl_12_rodata_1E8C[] = "E2053005: forgot free.";
static const char lbl_12_rodata_1E8C__fzgx_offset_18[0x24] = "E2053003: not enough work: sfx_wk";
static const char lbl_12_rodata_1E8C__fzgx_offset_3C[0x28] = "E2053004: not enough work: ainfsj_buf";
static const char lbl_12_rodata_1E8C__fzgx_offset_64[0x24] = "E3012102: Buffer format is invalid.";
static const char lbl_12_rodata_1E8C__fzgx_offset_88[] = "E1122612 mwPlyCreateSofdec : cprm is NULL.";
static const char lbl_12_rodata_1E8C__fzgx_offset_B4[] = "W2000 mwPlyCreateSofdec:can't create handle";
static const char lbl_12_rodata_1E8C__fzgx_offset_E0[] = "E2053006 mwPlyCreateSofdec: Didn't set malloc/free func.";
static const char lbl_12_rodata_1E8C__fzgx_offset_11C[] = "E2012 mwPlyCreate:can't create SFD";
static const char lbl_12_rodata_1E8C__fzgx_offset_140[] = "E02120501: Internal Error: mwsfcre_AttachPicUsrBuf().";
static const char lbl_12_rodata_1E8C__fzgx_offset_178[] = "E02120502: mwsfcre_AttachPicUsrBuf(): usrdatbuf is short.";

#pragma section code_type ".fzgxpool"
static void mwsfdcre_layout(void) {
    const void *volatile object; /* fzgx-allow: S2 readonly object first-access order */
    object = &lbl_12_rodata_1D88;
    object = &lbl_12_rodata_1DAC;
    object = &lbl_12_rodata_1DD0;
    object = lbl_12_rodata_1DF4;
    object = lbl_12_rodata_1E18;
    object = lbl_12_rodata_1E40;
    object = lbl_12_rodata_1E6C;
    object = lbl_12_rodata_1E8C;
    object = lbl_12_rodata_1E8C__fzgx_offset_18;
    object = lbl_12_rodata_1E8C__fzgx_offset_3C;
    object = lbl_12_rodata_1E8C__fzgx_offset_64;
    object = lbl_12_rodata_1E8C__fzgx_offset_88;
    object = lbl_12_rodata_1E8C__fzgx_offset_B4;
    object = lbl_12_rodata_1E8C__fzgx_offset_E0;
    object = lbl_12_rodata_1E8C__fzgx_offset_11C;
    object = lbl_12_rodata_1E8C__fzgx_offset_140;
    object = lbl_12_rodata_1E8C__fzgx_offset_178;
}
#pragma section code_type ".text"

static inline void mwsfcre_FreeAll(MwsPlayer *player) {
    MwsLibraryWork *work;
    int index;
    void *memory;
    for (index = 0; index < 32; index++) {
        int reverse_index = 31 - index;
        memory = player->allocations[reverse_index];
        if (memory != 0) {
            if (player->arena == 0) {
                work = fn_12_38DBC();
                work->free_fn(work->allocator_object, memory);
            }
            player->allocation_count--;
            player->allocations[reverse_index] = 0;
        }
    }
}

static inline void MWSFCRE_DestroySfd(MwsPlayer *player) {
    if (player->loader != 0) fn_80057114(player->loader);
    if (player->stream != 0) fn_12_34F64(player->stream);
    if (player->input_sj != 0)
        player->input_sj->interface->destroy(player->input_sj);
    if (player->memory_sj != 0)
        player->memory_sj->interface->destroy(player->memory_sj);
    if (player->sfd != 0) {
        if (fn_12_2B6B0(player->sfd) != 0) {
            fn_12_38A0C(-0x132);
            MWSFSVM_Error(lbl_12_rodata_1E6C);
        }
    }
    fn_12_3B15C(&player->sound);
    mwsfcre_FreeAll(player);
    if (player->allocation_count != 0) MWSFSVM_Error(lbl_12_rodata_1E8C);
    memset(player, 0, sizeof(*player));
    player->active = 0;
    player->interface = &lbl_12_data_D38;
}

static inline void mwSfdDestroy(MWPLY handle) {
    MwsPlayer *player = (MwsPlayer *)handle;
    if (player == 0) {
        return;
    }
    fn_12_390E4(player);
    player->active = 0;
    fn_12_35484(player);
    if (player->sfx != 0) fn_12_35D74(player->sfx);
    MWSFCRE_DestroySfd(player);
}

static inline int mwsfcre_IsValidBufFmt(const MwsCreateParams *params) {
    int valid = 1;
    if (params->buffer_format != 0 && params->buffer_format != 3) {
        MWSFSVM_Error(lbl_12_rodata_1E8C__fzgx_offset_64);
        valid = 0;
    }
    return valid;
}

static inline int mwsfcre_ChkMallocFn(const MwsCreateParams *params) {
    MwsLibraryWork *work = fn_12_38DBC();
    int result = 0;
    if (params->work == 0) {
        if (work->malloc_fn == 0) result = -1;
        if (work->free_fn == 0) result = -1;
    }
    return result;
}

static inline void mwsfcre_InitCompoWork(MwsPlayer *player, const MwsCreateParams *params) {
    long index;
    player->arena = params->work;
    player->arena_size = params->work_size;
    player->arena_cursor = params->work;
    player->arena_used = 0;
    player->allocation_count = 0;
    for (index = 0; index < 32; index++) {
        player->allocations[index] = 0;
    }
}

static inline void mwsfcre_AttachPictureUser(MwsPlayer *player, const char *short_error) {
    MwsPictureUserConfig *config = player->picture_user;
    void *buffer;
    int element_size;
    int skip_count;
    if (config == 0) {
        MWSFSVM_Error(lbl_12_rodata_1E8C__fzgx_offset_140);
    } else {
        skip_count = player->create.frame_count;
        element_size = config->element_size;
        buffer = config->buffer;
        if (config->buffer_size < (skip_count + 3) * element_size) {
            MWSFSVM_Error(short_error);
        } else if (fn_12_38AE0() == 1) {
            fn_12_2A434(player->sfd, buffer, skip_count + 3, element_size);
        }
    }
}

static inline void mwsfcre_SetSfdCond(MwsPlayer *player, MwsLibraryWork *work) {
    double frame_time;
    int frames;
    int pool;
    int frequency;
    SfdHandle *sfd;

    sfd = player->sfd;
    pool = work->frame_pool;
    frequency = work->video_frequency;
    fn_12_2D888(sfd, 8, 0);
    fn_12_2D888(sfd, 1, 1);
    fn_12_2D888(sfd, 0, 0);
    fn_12_2D888(sfd, 0x17, 4);
    frame_time = 0.5 + (double)(frequency * pool * 1000);
    if ((double)(int)frame_time > frame_time) frames = (int)frame_time - 1;
    else frames = (int)frame_time;
    fn_12_2D888(sfd, 0x2D, frames);
    fn_12_2D888(sfd, 0x2C, frames);
    fn_12_2D888(sfd, 0x2A, frames);
    fn_12_2D888(sfd, 0xF, 2);
    fn_12_2D888(sfd, 0x33, 0);
    fn_12_2D888(sfd, 0xE, 0);
    fn_12_2D888(sfd, 0x1C, 0);
    fn_12_2A5C8(sfd, 5, 0);
}

MwsPlayer *fn_12_364CC(MwsCreateParams *params) {
    MwsLibraryWork *work;
    MwsPlayer *player;
    SfdHandle *sfd;
    SFXHandle *sfx;
    int flow_limit;
    int index;
    int sector_count;
    int maximum_bps;
    int file_type;

    if (params == 0) {
        MWSFSVM_Error(lbl_12_rodata_1E8C__fzgx_offset_88);
        return 0;
    }
    if (mwsfcre_IsValidBufFmt(params) != 1) {
        return 0;
    }
    work = fn_12_38DBC();
    for (index = 0; index < 8; index++) {
        player = &work->players[index];
        if (player->active == 0) break;
    }
    if (index == 8) {
        fn_12_38A0C(-0xB);
        MWSFSVM_Error(lbl_12_rodata_1E8C__fzgx_offset_B4);
        return 0;
    }
    if (mwsfcre_ChkMallocFn(params) == -1) {
        MWSFSVM_Error(lbl_12_rodata_1E8C__fzgx_offset_E0);
        return 0;
    }

    if (player != 0) memset(player, 0, sizeof(*player));
    mwsfcre_InitCompoWork(player, params);

    sfd = fn_12_3763C(player, params);
    player->sfd = sfd;
    if (player->sfd == 0) {
        MWSFSVM_Error(lbl_12_rodata_1E8C__fzgx_offset_11C);
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    mwsfcre_AttachPictureUser(player, lbl_12_rodata_1E8C__fzgx_offset_178);

    sector_count = params->decoder_count;
    file_type = params->file_type;
    maximum_bps = params->maximum_bps;
    if (sector_count <= 0) {
        sector_count = 1;
    }
    if (file_type == 2) {
        flow_limit = sector_count * (maximum_bps / 8 / 0x800 * 0x800);
    } else if (file_type == 3) {
        flow_limit = sector_count * (maximum_bps / 8 / 0x800 * 0x800);
    } else {
        flow_limit = sector_count * (maximum_bps / 8 / 0x800 * 0x800);
    }
    mwsfcre_SetSfdCond(player, work);

    player->input_sj = fn_80058498(player->input_buffer, player->input_buffer_size,
                                   player->input_buffer_extra_size);
    if (player->input_sj == 0) {
        MWSFSVM_Error("E2013 mwPlyCreate:can't create SJ");
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    player->memory_sj = fn_80057B9C(0, 0);
    if (player->memory_sj == 0) {
        MWSFSVM_Error("E2020 mwPlyCreate:can't create SJ");
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    player->interface = &lbl_12_data_D38;
    player->flow_limit = flow_limit;
    player->create = *params;
    player->playback_mode = 1;
    player->field_068 = 0;
    player->status = 0;
    player->field_050 = params->composition_mode;
    if (fn_12_2D500(sfd, 3, &player->transport) != 0) player->transport = 0;
    player->field_06C = 1;
    player->concat_play = 0;
    player->concat_stopped = 0;
    player->paused = 0;
    player->field_073 = 0;
    player->field_05C = 0;
    fn_12_3A968(player, 0);
    fn_12_3A960(player, 0);
    player->field_054 = 0;
    player->field_084 = 0;

    player->stream = fn_12_34F84(player->input_sj);
    if (player->stream == 0) {
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    fn_12_38DC8(player);
    player->loader = fn_800571EC(player->input_sj);
    player->entry_count = 0;
    fn_8005710C(player->loader, player->stream);
    if (fn_12_36208(player) == -1) {
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    sfx = fn_12_35D94(player->composition_work, player->composition_work_size,
                      params->width, params->height);
    if (sfx == 0) {
        MWSFSVM_Error("E201185: can't create SfxHn");
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    player->sfx = sfx;
    fn_12_356E8(player, player->create.composition_mode);
    player->additional_info_sj = fn_12_354BC(player);
    if (fn_12_35418(player) != 0) {
        MWSFSVM_Error("E201212 mwPlyCreate: can't set AddInfSJ");
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    fn_12_353FC(player);
    player->active = 1;
    return player;
}
