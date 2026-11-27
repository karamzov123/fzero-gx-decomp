#include "types.h"


/* --- rel/movie_module/fn_12_3ADC4.c --- */
typedef struct MovieObject {
    u8 pad[0x58];
    s32 state;
} MovieObject;

extern s32 fn_8004E580(MovieObject *self);
extern MovieObject *fn_12_34CC8(void);
extern u32 lbl_12_bss_1CC58;
extern u32 lbl_12_bss_1CC5C;
extern s32 lbl_12_bss_1B9DC[52];
extern MovieObject *fn_12_38DBC(void);
extern s32 fn_12_34C44(s32 *state);
extern void fn_12_2CD6C(void);
extern void fn_12_34CA8(MovieObject *movie);

s32 fn_12_3ADC4(MovieObject *self) {
    MovieObject *movie;
    MovieObject *manager;

    if (fn_8004E580(self) == 1) {
        movie = fn_12_34CC8();
        lbl_12_bss_1CC58++;
        lbl_12_bss_1CC5C++;
        if (lbl_12_bss_1B9DC[0] == 1) {
            manager = fn_12_38DBC();
            if (fn_12_34C44(&manager->state)) {
                if (lbl_12_bss_1B9DC[0] == 1) {
                    fn_12_2CD6C();
                }
                manager->state = 0;
            }
        }
        fn_12_34CA8(movie);
        return 0;
    }

    return 0;
}

/* --- rel/movie_module/fn_12_3AE84.c --- */
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

typedef struct LSC LSC;

typedef struct SfdHandle SfdHandle;

typedef struct MwsPlayer MwsPlayer;

typedef struct MwsStHandle MwsStHandle;

typedef struct MwsSupply MwsSupply;

typedef struct MwsSupplyInterface {
    void *reserved[5];
    void (*start)(MwsSupply *supply);
} MwsSupplyInterface;

struct MwsSupply {
    const MwsSupplyInterface *interface;
};

struct MwsStHandle {
    int active;
    unsigned char reserved_004[0x08];
    SJ *stream;
    int element_id;
    void *backend;
};

struct MwsPlayer {
    int reserved_000;
    int active;
    int status;
    unsigned char reserved_00C[0x34];
    SfdHandle *sfd;
    void *stream;
    unsigned char reserved_048[0x04];
    LSC *loader;
    unsigned char reserved_050[12];
    int sleeping_server;
    int in_mwply_server;
    int in_sfd_server;
    int decoder_server_active;
    unsigned char reserved_070[0x04];
    signed char concat_play;
    signed char terminating_supply;
    signed char paused;
    unsigned char reserved_077[157];
    const char *filename;
    int filename_capacity;
    int start_requested;
    int file_offset;
    int file_length;
    int file_end_position;
    MwsSupply *supply;
    unsigned char reserved_1D4[0xC0];
    MwsStHandle sound;
    unsigned char reserved_2AC[0x0C];
};

struct mwsfdsvr____rodata_0 {
    unsigned char padding_0[92];
    const char start_failed[41];
    unsigned char padding_133[3];
    const char link_failed[42];
    unsigned char padding_178[2];
    const char terminate_failed[46];
};
extern struct mwsfdsvr____rodata_0 lbl_12_rodata_2D28;

int fn_12_3AE84(MwsPlayer *player);

extern void *fn_12_34C84(void);
extern void fn_12_34C64(void *value);

extern int fn_80056BE0(LSC *loader);

extern int fn_12_38A0C(int error);

extern void fn_12_3858C(MwsPlayer *player);

extern void fn_12_3500C(MwsPlayer *player);

extern int fn_12_342B8(LSC *loader);

extern void MWSFSFX_DecideCompoMode(MwsPlayer *player);

extern void MWSFSVM_Error(const char *message, ...);

extern int MWSST_GetStat(MwsStHandle *sound);

extern void MWSST_Pause(MwsStHandle *sound, int paused);

extern int fn_12_34E90(void *stream);

extern int fn_12_34FD0(void *stream);

extern int fn_12_34EE4(void *stream);

extern void fn_12_34F04(void *stream, const char *filename, int offset, int length,
                        int end_position);

extern int fn_12_2DA6C(SfdHandle *handle);

extern int fn_12_23280(SfdHandle *handle);

extern int fn_12_2B2E4(SfdHandle *handle);

extern void mwPlyChkSupply(MwsPlayer *player);

extern void fn_12_39A18(MwsPlayer *player);

extern void mwSfdPause(MwsPlayer *player, int paused);

int fn_12_3AE84(MwsPlayer *player) {
    const char * fzgx_live;
    struct mwsfdsvr____rodata_0 *data = &lbl_12_rodata_2D28;

    struct { void * value; } callback_result;
    SfdHandle *sfd;
    switch ((*(int volatile *)&(player->status)) /* Retail reloads this field. */) {
    case 1: {
        int stream_result;
        sfd = player->sfd;
        if (player->start_requested == 1) {
            callback_result.value = fn_12_34C84();
            if (fn_12_34E90(player->stream) == 2) {
                stream_result = -1;
            } else {
                if (player->supply != 0) {
                    player->supply->interface->start(player->supply);
                }
                fn_12_34F04(player->stream, player->filename, player->file_offset,
                            player->file_length, player->file_end_position);
                if (fn_12_34EE4(player->stream) == -1) {
                    player->status = 4;
                    fn_12_38A0C(-0x66);
                    MWSFSVM_Error((data->start_failed), player->filename);
                    player->start_requested = 0;
                    stream_result = -1;
                } else {
                    fn_12_3858C(player);
                    stream_result = 1;
                }
            }
            if (stream_result == 1)
                player->start_requested = 0;
            fn_12_34C64(callback_result.value);
        }
        if (player->sound.active == 1) {
            MwsStHandle *sound = &player->sound;
            int sfd_status = fn_12_2DA6C(player->sfd);
            int sound_status = MWSST_GetStat(sound);
            if (sfd_status == 3 && sound_status == 2) {
                fn_12_39A18(player);
                if (player->paused == 0)
                    mwSfdPause(player, 0);
                if (player->concat_play == 1 && fn_12_23280(player->sfd) != 0) {
                    fzgx_live = data->link_failed;
                    MWSFSVM_Error((fzgx_live));
                }
                if (player->paused == 0)
                    MWSST_Pause(sound, 0);
            }
        } else if (fn_12_2DA6C((player->sfd)) == 3) {
            fn_12_39A18(player);
            if (player->paused == 0)
                mwSfdPause(player, 0);
            if (player->concat_play == 1 && fn_12_23280(player->sfd) != 0) {
                fzgx_live = data->link_failed;
                MWSFSVM_Error((fzgx_live));
            }
        }
        {
            int sfd_status = fn_12_2DA6C(sfd);
            if (sfd_status == 4 || sfd_status == 6) {
                player->status = 2;
            }
        }
        break;
    }
    case 2:
        sfd = player->sfd;
        if (player->terminating_supply == 1) {
            if (fn_80056BE0(player->loader) == 0) {
                if (fn_12_2B2E4(sfd) != 0) {
                    MWSFSVM_Error((data->terminate_failed));
                }
                player->terminating_supply = 0;
            }
        }
        if (fn_12_2DA6C(sfd) == 6)
            player->status = 3;
        break;
    case 0:
    case 3:
        break;
    }
    if (player->stream != 0 && fn_12_34FD0(player->stream) != 0) {
        player->status = 4;
    }
    if (player->loader != 0 && fn_12_342B8(player->loader) == 1) {
        player->status = 4;
    }
    fn_12_3500C(player);
    return 0;
}

/* --- rel/movie_module/fn_12_3B15C.c --- */
/* --- rel/movie_module/fn_12_3B15C.c --- */






typedef struct MwsStHandle_u2 MwsStHandle_u2;

typedef struct MwsStManagerInterface {
    void *reserved_00;
    void (*finish)(void);
    void *reserved_08[2];
    void (*destroy)(MwsStHandle_u2 *handle);
    void (*start_sj)(void *backend, SJ *stream);
    void (*stop)(void *backend);
    int (*get_status)(void *backend);
    void *reserved_20;
    void (*pause)(void *backend, int paused);
    void (*set_volume)(void *backend, int volume);
    int (*get_volume)(void *backend);
} MwsStManagerInterface;

struct MwsStHandle_u2 {
    int active;
    unsigned char reserved_04[8];
    SJ *stream;
    int element_id;
    void *backend;
};

typedef struct MwsStManager {
    MwsStManagerInterface *interface;
    int active_count;
} MwsStManager;

void fn_12_3B15C(MwsStHandle_u2 *handle);

extern void MWSFSVM_GotoIdleBorder(void);

extern MwsStManager lbl_12_data_E90;

static inline int mwsst_IsValid(const MwsStHandle_u2 *handle) {
    if (lbl_12_data_E90.interface == 0) {
        return 0;
    }
    if (handle->active != 1) {
        return 0;
    }
    if (handle->backend == 0) {
        return 0;
    }
    return 1;
}

void fn_12_3B15C(MwsStHandle_u2 *handle);

/* --- rel/movie_module/fn_12_3B2EC.c --- */




typedef struct MwsStPlayerPrefix {
    unsigned char reserved_000[0x40];
    SfdHandle *player;
    unsigned char reserved_044[424];
    MwsStHandle_u2 sound;
} MwsStPlayerPrefix;


void fn_12_3B2EC(MwsStPlayerPrefix *wrapper);

extern int fn_12_26734(SfdHandle *handle, int element_id, SJ *stream, int channel, int flags);



void fn_12_3B2EC(MwsStPlayerPrefix *wrapper);
