
#include "types.h"

typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
    const void *(*get_uuid)(SJ *sj);
    void (*reset)(SJ *sj);
    void (*get_chunk)(SJ *sj, long channel, long max_size, SJCK *chunk);
    void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ *sj, int channel);
    int (*is_get_chunk)(SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ *sj, SJErrorCallback callback, void *object);
};

struct SJ {
    const SJInterface *interface;
};

typedef struct MwsStHandle {
    int active;
    unsigned char reserved_004[8];
    SJ *stream;
    int element_id;
    void *backend;
} MwsStHandle;

typedef struct ADXStream ADXStream;

typedef struct LSC LSC;

typedef struct SfdHandle SfdHandle;

typedef struct MwsPlayer MwsPlayer;

typedef struct MwsSupply MwsSupply;

typedef void (*MwsServerBorderCallback)(void *object);

typedef struct MwsSupplyInterface {
    void *reserved[5];
    void (*start)(MwsSupply *supply);
} MwsSupplyInterface;

struct MwsSupply {
    const MwsSupplyInterface *interface;
};

struct MwsPlayer {
    int reserved_000;
    int active;
    int status;
    unsigned char reserved_00C[48];
    SfdHandle *sfd;
    ADXStream *stream;
    unsigned char reserved_048[0x04];
    LSC *loader;
    unsigned char reserved_050[0x10];
    int sleeping_server;
    int in_mwply_server;
    int in_sfd_server;
    int decoder_server_active;
    unsigned char reserved_070[0x04];
    signed char concat_play;
    signed char terminating_supply;
    signed char paused;
    unsigned char reserved_077[0x141];
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

typedef struct MwsLibraryWork {
    int reserved_000;
    float frame_rate;
    int max_width;
    int decoder_count;
    int server_mode;
    unsigned char reserved_014[0x10];
    int sleeping_server;
    unsigned char reserved_028[0x10];
    int use_picture_user_data;
    int pause_border;
    MwsServerBorderCallback enter_server;
    void *enter_server_object;
    MwsServerBorderCallback leave_server;
    void *leave_server_object;
    MwsServerBorderCallback idle_server;
    void *idle_server_object;
    int server_lock;
    int vsync_lock;
    unsigned char reserved_060[0x08];
    int error_code;
    MwsPlayer players[8];
} MwsLibraryWork;

void fn_12_3A888(MwsPlayer *player);

extern void fn_8004EC14(void);

extern MwsLibraryWork *fn_12_38DBC(void);

extern void fn_12_34B64(void);

extern void fn_12_341BC(void);

extern void fn_12_341C0(void);

static inline void mwsfd_SetSleepBdr(MwsPlayer *player, int value) {
    MwsLibraryWork *work = fn_12_38DBC();
    player->sleeping_server = value;
    work->sleeping_server = value;
}

static inline void mwsfd_ClrSleepBdr(MwsPlayer *player) { mwsfd_SetSleepBdr(player, 0); }

static inline void mwsfd_SleepLoop(MwsPlayer *player) {
    int i;
    for (i = 0; i < 10; i++) {
        mwsfd_SetSleepBdr(player, 1);
        fn_8004EC14();
        mwsfd_ClrSleepBdr(player);
        if (player->in_mwply_server == 0)
            break;
    }
}

void fn_12_3A888(MwsPlayer *player) {
    fn_12_341C0();
    mwsfd_SetSleepBdr(player, 1);
    fn_12_34B64();
    mwsfd_ClrSleepBdr(player);
    fn_12_341BC();
    if (player->in_mwply_server == 1)
        mwsfd_SleepLoop(player);
}
