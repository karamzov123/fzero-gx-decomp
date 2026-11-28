#include "types.h"

typedef struct MwsSupply MwsSupply;

typedef struct MwsSupplyInterface {
    void *reserved[5];
    void (*start)(MwsSupply *supply);
} MwsSupplyInterface;

struct MwsSupply {
    const MwsSupplyInterface *interface;
};

typedef void (*SJErrorCallback)(void *object, int error);

typedef void (*MwsServerBorderCallback)(void *object);

typedef struct SfdHandle SfdHandle;

typedef struct ADXStream ADXStream;

typedef struct LSC LSC;

typedef struct fn_12_3A888_SJ fn_12_3A888_SJ;

typedef struct fn_12_3A888_SJCK {
    unsigned char *data;
    long len;
} fn_12_3A888_SJCK;

typedef struct fn_12_3A888_SJInterface fn_12_3A888_SJInterface;

struct fn_12_3A888_SJInterface {
    void *reserved[3];
    void (*destroy)(fn_12_3A888_SJ *sj);
    const void *(*get_uuid)(fn_12_3A888_SJ *sj);
    void (*reset)(fn_12_3A888_SJ *sj);
    void (*get_chunk)(fn_12_3A888_SJ *sj, long channel, long max_size, fn_12_3A888_SJCK *chunk);
    void (*unget_chunk)(fn_12_3A888_SJ *sj, int channel, fn_12_3A888_SJCK *chunk);
    void (*put_chunk)(fn_12_3A888_SJ *sj, int channel, fn_12_3A888_SJCK *chunk);
    int (*get_num_data)(fn_12_3A888_SJ *sj, int channel);
    int (*is_get_chunk)(fn_12_3A888_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(fn_12_3A888_SJ *sj, SJErrorCallback callback, void *object);
};

struct fn_12_3A888_SJ {
    const fn_12_3A888_SJInterface *interface;
};

typedef struct fn_12_3A888_MwsStHandle {
    int active;
    unsigned char reserved_004[8];
    fn_12_3A888_SJ *stream;
    int element_id;
    void *backend;
} fn_12_3A888_MwsStHandle;

typedef struct fn_12_3A888_MwsPlayer fn_12_3A888_MwsPlayer;

struct fn_12_3A888_MwsPlayer {
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
    fn_12_3A888_MwsStHandle sound;
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
    fn_12_3A888_MwsPlayer players[8];
} MwsLibraryWork;

typedef struct fn_12_3A92C_MovieObject {
    u8 pad[0x54];
    u32 value;
} fn_12_3A92C_MovieObject;

typedef struct fn_12_3ABE0_MovieObject {
    u8 pad[0x58];
    s32 state;
} fn_12_3ABE0_MovieObject;

typedef struct fn_12_3AC70_MovieObject {
    u8 _pad[0x10];
    s32 value;
} fn_12_3AC70_MovieObject;

typedef struct fn_12_3ACD0_MovieObject {
    u8 _pad[0x10];
    s32 value;
    u8 _pad2[0x44];
    s32 state;
} fn_12_3ACD0_MovieObject;

typedef struct fn_12_3ADC4_MovieObject {
    u8 pad[0x58];
    s32 state;
} fn_12_3ADC4_MovieObject;

typedef struct fn_12_3AA58_MovieManager {
    u8 pad24[0x24];
    s32 value;
} fn_12_3AA58_MovieManager;

typedef struct fn_12_3AB00_MovieManager {
    u8 pad40[0x40];
    void (*callback0)(void *);
    void *callback0_arg;
    void (*callback1)(void *);
    void *callback1_arg;
    u8 pad50[0x4];
    s32 state;
} fn_12_3AB00_MovieManager;

typedef struct Sig_fn_12_2CC24_MovieModuleState {
    u8 _pad_0[0x44];
    u32 field_44;
} Sig_fn_12_2CC24_MovieModuleState;

typedef struct Sig_fn_12_2CD44_MovieModuleState {
    u8 _pad_0[0x44];
    u32 field_44;
    u32 field_48;
} Sig_fn_12_2CD44_MovieModuleState;

typedef struct fn_12_3AE84_SJ fn_12_3AE84_SJ;

typedef struct fn_12_3AE84_SJCK {
    unsigned char *data;
    int len;
} fn_12_3AE84_SJCK;

typedef struct fn_12_3AE84_SJInterface fn_12_3AE84_SJInterface;

struct fn_12_3AE84_SJInterface {
    void *reserved[3];
    void (*destroy)(fn_12_3AE84_SJ *sj);
    const void *(*get_uuid)(fn_12_3AE84_SJ *sj);
    void (*reset)(fn_12_3AE84_SJ *sj);
    void (*get_chunk)(fn_12_3AE84_SJ *sj, int channel, int max_size, fn_12_3AE84_SJCK *chunk);
    void (*unget_chunk)(fn_12_3AE84_SJ *sj, int channel, fn_12_3AE84_SJCK *chunk);
    void (*put_chunk)(fn_12_3AE84_SJ *sj, int channel, fn_12_3AE84_SJCK *chunk);
    int (*get_num_data)(fn_12_3AE84_SJ *sj, int channel);
    int (*is_get_chunk)(fn_12_3AE84_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(fn_12_3AE84_SJ *sj, SJErrorCallback callback, void *object);
};

struct fn_12_3AE84_SJ {
    const fn_12_3AE84_SJInterface *interface;
};

typedef struct fn_12_3AE84_MwsStHandle fn_12_3AE84_MwsStHandle;

struct fn_12_3AE84_MwsStHandle {
    int active;
    unsigned char reserved_004[0x08];
    fn_12_3AE84_SJ *stream;
    int element_id;
    void *backend;
};

typedef struct fn_12_3AE84_MwsPlayer fn_12_3AE84_MwsPlayer;

struct fn_12_3AE84_MwsPlayer {
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
    fn_12_3AE84_MwsStHandle sound;
    unsigned char reserved_2AC[0x0C];
};

typedef struct Sig_fn_12_3A9A0_MovieObject {
    u8 pad04[0x4];
    s32 state;
    u8 pad08[0x58];
    s32 value;
} Sig_fn_12_3A9A0_MovieObject;

typedef struct fn_12_3AA58_MovieObject {
    u8 pad04[0x4];
    s32 state;
    u8 pad08[0x58];
    s32 value;
} fn_12_3AA58_MovieObject;

struct mwsfdsvr____rodata_0 {
    unsigned char padding_0[92];
    const char start_failed[41];
    unsigned char padding_133[3];
    const char link_failed[42];
    unsigned char padding_178[2];
    const char terminate_failed[46];
};
extern void fn_8004EC14(void);
extern u32 * fn_12_38DBC();
extern void fn_12_34B64(void);
extern void fn_12_341BC(void);
extern void fn_12_341C0(void);
extern int fn_12_2CC24(Sig_fn_12_2CC24_MovieModuleState *);
extern u32 fn_12_2CD44(Sig_fn_12_2CD44_MovieModuleState *);
extern int fn_12_3AE84(fn_12_3AE84_MwsPlayer *player);
extern u32 lbl_12_bss_1CC60;
extern s32 lbl_12_bss_1B9DC[52];
extern u8 lbl_12_rodata_2D5C[180];
extern void MWSFSVM_Error(const u8 *message, ...);
extern u32 fn_12_3A9A0(Sig_fn_12_3A9A0_MovieObject * arg0);
extern void fn_12_34C44();
extern u32 fn_12_3AA58(fn_12_3AA58_MovieObject *self);
extern int SFD_IsSvrWait(void);
extern u32 lbl_12_bss_1CC58;
extern u32 lbl_12_bss_1CC5C;
extern void fn_12_2CD6C(void);
extern u32 fn_8004E580();
extern u32 fn_12_3AB00();
extern int fn_12_34CC8(void);
extern void fn_12_34CA8();
extern struct mwsfdsvr____rodata_0 lbl_12_rodata_2D28;
extern int fn_12_34C84(void);
extern void fn_12_34C64();
extern u32 fn_80056BE0(u32 arg0);
extern s32 fn_12_38A0C(s32 arg);
extern void fn_12_3858C(fn_12_3AE84_MwsPlayer *player);
extern void fn_12_3500C();
extern u32 fn_12_342B8();
extern int MWSST_GetStat(fn_12_3AE84_MwsStHandle *sound);
extern void MWSST_Pause(fn_12_3AE84_MwsStHandle *sound, int paused);
extern void fn_12_34E90();
extern u32 fn_12_34FD0();
extern void fn_12_34EE4();
extern void fn_12_34F04(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
extern int fn_12_23280(void *arg0);
extern void fn_12_39A18(fn_12_3AE84_MwsPlayer *player);
extern void mwSfdPause(fn_12_3AE84_MwsPlayer *player, int paused);

/* fzgx:begin fn_12_3A888 */
/* --- rel/movie_module/fn_12_3A888.c --- */









static inline void mwsfd_SetSleepBdr(fn_12_3A888_MwsPlayer *player, int value) {
    MwsLibraryWork *work = ((MwsLibraryWork *)fn_12_38DBC());
    player->sleeping_server = value;
    work->sleeping_server = value;
}

static inline void mwsfd_ClrSleepBdr(fn_12_3A888_MwsPlayer *player) { mwsfd_SetSleepBdr(player, 0); }

static inline void mwsfd_SleepLoop(fn_12_3A888_MwsPlayer *player) {
    int i;
    for (i = 0; i < 10; i++) {
        mwsfd_SetSleepBdr(player, 1);
        fn_8004EC14();
        mwsfd_ClrSleepBdr(player);
        if (player->in_mwply_server == 0)
            break;
    }
}

void fn_12_3A888(fn_12_3A888_MwsPlayer *player) {
    fn_12_341C0();
    mwsfd_SetSleepBdr(player, 1);
    fn_12_34B64();
    mwsfd_ClrSleepBdr(player);
    fn_12_341BC();
    if (player->in_mwply_server == 1)
        mwsfd_SleepLoop(player);
}
/* fzgx:end fn_12_3A888 */

/* fzgx:begin fn_12_3A92C */
/* --- rel/movie_module/fn_12_3A92C.c --- */


s32 fn_12_3A92C(void) {
    fn_12_3A92C_MovieObject *object = ((fn_12_3A92C_MovieObject *)fn_12_38DBC());
    return object->value != 1;
}
/* fzgx:end fn_12_3A92C */

/* fzgx:begin fn_12_3A960 */
/* --- rel/movie_module/fn_12_3A960.c --- */
typedef struct Fn12_3A960_Object {
    u8 _pad[0x64];
    u32 value;
} Fn12_3A960_Object;

void fn_12_3A960(Fn12_3A960_Object *object, u32 value) {
    object->value = value;
}
/* fzgx:end fn_12_3A960 */

/* fzgx:begin fn_12_3A968 */
/* --- rel/movie_module/fn_12_3A968.c --- */
/* --- rel/movie_module/fn_12_3A968.c --- */
typedef struct fn_12_3A968_MovieObject {
    u8 pad[0x60];
    s32 value;
} fn_12_3A968_MovieObject;

void fn_12_3A968(fn_12_3A968_MovieObject *self, s32 value) {
    self->value = value;
}
/* fzgx:end fn_12_3A968 */

/* fzgx:begin fn_12_3A970 */
/* --- rel/movie_module/fn_12_3A970.c --- */

void fn_12_3A970(u32 arg0) {
    u32 t0;
    t0 = ((u32)fn_12_38DBC(arg0));
    *(u32 *)((u8 *)t0 + 84) = arg0;
}
/* fzgx:end fn_12_3A970 */

/* fzgx:begin fn_12_3A9A0 */
/* --- rel/movie_module/fn_12_3A9A0.c --- */


#pragma opt_dead_assignments off
#pragma opt_lifetimes off
u32 fn_12_3A9A0(Sig_fn_12_3A9A0_MovieObject * arg0) {
    u32 v0;
    u32 v1;
    int t0;
    u32 t1;
    u32 t2;
    v0 = *(u32 *)((u8 *)arg0 + 64);
    ((Sig_fn_12_3A9A0_MovieObject *)(arg0))->value = 1;
    v1 = (u32)(arg0);
    if (((Sig_fn_12_3A9A0_MovieObject *)(arg0))->state != 1) {
    v1 = 0;
    ((Sig_fn_12_3A9A0_MovieObject *)(arg0))->value = 0;
    } else {
    v1 = v0;
    lbl_12_bss_1CC60 = (u32)(arg0);
    *(u32 *)((u8 *)arg0 + 100) = 1;
    t0 = fn_12_2CC24((Sig_fn_12_2CC24_MovieModuleState *)v1);
    v1 = t0;
    v1 = 0;
    *(u32 *)((u8 *)arg0 + 100) = v1;
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    *(u32 *)((u8 *)arg0 + 104) = v1;
    } else {
    v1 = (u32)(arg0);
    *(u32 *)((u8 *)arg0 + 104) = 1;
    t1 = ((u32)fn_12_3AE84( (fn_12_3AE84_MwsPlayer *)(u32)(v1)));
    v1 = t1;
    }
    v1 = v0;
    ((Sig_fn_12_3A9A0_MovieObject *)(arg0))->value = 0;
    t2 = fn_12_2CD44((Sig_fn_12_2CD44_MovieModuleState *)v1);
    v1 = t2;
    v1 = ((u32)((1 - v1) | (v1 - 1)) >> 31);
    }
    return v1;
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_12_3A9A0 */

/* fzgx:begin fn_12_3AA58 */



u32 fn_12_3AA58(fn_12_3AA58_MovieObject *self) {
    if (lbl_12_bss_1B9DC[0] != 1) {
        return 0;
    }
    if (self == 0) {
        MWSFSVM_Error(lbl_12_rodata_2D5C);
        return 0;
    }
    if (self->state != 1) {
        return 0;
    }
    if (self->value == 1) {
        return 0;
    }
    if (((fn_12_3AA58_MovieManager *)fn_12_38DBC())->value == 1) {
        return 0;
    }
    return fn_12_3A9A0( (Sig_fn_12_3A9A0_MovieObject *)(fn_12_3AA58_MovieObject *)(self));
}
/* fzgx:end fn_12_3AA58 */

/* fzgx:begin fn_12_3AB00 noprologue */
#include "types.h"

typedef struct MovieObject {
    u8 pad[0x68];
} MovieObject;

typedef struct MovieManager {
    u8 pad40[0x40];
    void (*callback0)(void *);
    void *callback0_arg;
    void (*callback1)(void *);
    void *callback1_arg;
    u8 pad50[0x4];
    s32 state;
} MovieManager;

extern s32 lbl_12_bss_1B9DC[52];
extern MovieManager *fn_12_38DBC(void);
extern s32 fn_12_34C44(s32 *state);
extern u32 fn_12_3AA58(MovieObject *self);
extern s32 SFD_IsSvrWait(void);

#pragma opt_lifetimes off
u32 fn_12_3AB00(void) {
    MovieManager *manager;
    MovieManager *manager2;
    MovieObject *movie;
    register s32 result;
    void (*callback)(void *);
    void *arg;

    if (lbl_12_bss_1B9DC[0] != 1) {
        return 0;
    }

    manager = fn_12_38DBC();
    if (fn_12_34C44(&manager->state) == 0) {
        return 0;
    }

    manager2 = fn_12_38DBC();
    callback = manager2->callback0;
    arg = manager2->callback0_arg;
    if (callback != 0) {
        callback(arg);
    }

    result = 0;
    movie = (MovieObject *)manager;
    do {
        if ((u8 *)movie + 0x68 != 0) {
            fn_12_3AA58((MovieObject *)((u8 *)movie + 0x68));
        }
        result++;
        movie = (MovieObject *)((u8 *)movie + 0x228);
    } while (result < 8);

    manager2 = fn_12_38DBC();
    manager2->state = 0;
    {
        u32 raw = SFD_IsSvrWait();
        result = ((1 - raw) | (raw - 1)) >> 31;
    }
    manager2 = fn_12_38DBC();
    callback = manager2->callback1;
    arg = manager2->callback1_arg;
    if (callback != 0) {
        callback(arg);
    }
    return result;
}
#pragma opt_lifetimes reset
/* fzgx:end fn_12_3AB00 */

/* fzgx:begin fn_12_3ABE0 noprologue */
#include "types.h"

typedef struct MovieObject {
    u8 pad[0x58];
    s32 state;
} MovieObject;

extern u32 lbl_12_bss_1CC58;
extern u32 lbl_12_bss_1CC5C;
extern s32 lbl_12_bss_1B9DC[52];
extern MovieObject *fn_12_38DBC(void);
extern s32 fn_12_34C44(s32 *state);
extern void fn_12_2CD6C(void);

void fn_12_3ABE0(void) {
    MovieObject *movie;

    lbl_12_bss_1CC58++;
    lbl_12_bss_1CC5C++;

    if (lbl_12_bss_1B9DC[0] == 1) {
        movie = fn_12_38DBC();
        if (fn_12_34C44(&movie->state)) {
            if (lbl_12_bss_1B9DC[0] == 1) {
                fn_12_2CD6C();
            }
            movie->state = 0;
        }
    }
}
/* fzgx:end fn_12_3ABE0 */

/* fzgx:begin fn_12_3AC70 */


s32 fn_12_3AC70(fn_12_3AC70_MovieObject *self) {
    s32 result = 0;

    if (((s32)fn_8004E580(self)) == 1) {
        if (((fn_12_3AC70_MovieObject *)fn_12_38DBC())->value != 1) {
            result = ((s32)fn_12_3AB00(self));
        }
    }

    return result;
}
/* fzgx:end fn_12_3AC70 */

/* fzgx:begin fn_12_3ACD0 noprologue */
#include "types.h"

typedef struct MovieObject {
    u8 _pad[0x10];
    s32 value;
    u8 _pad2[0x44];
    s32 state;
} MovieObject;

extern s32 fn_8004E580(MovieObject *self);
extern MovieObject *fn_12_38DBC(void);
extern s32 fn_12_3AB00(MovieObject *self);
extern s32 fn_12_34CC8(void);
extern u32 lbl_12_bss_1CC58;
extern u32 lbl_12_bss_1CC5C;
extern s32 lbl_12_bss_1B9DC[52];
extern s32 fn_12_34C44(s32 *state);
extern void fn_12_2CD6C(void);
extern void fn_12_34CA8(s32 result);

#pragma opt_lifetimes off
s32 fn_12_3ACD0(MovieObject *self) {
    register s32 result;

    result = 0;
    if (fn_8004E580(self) == 1) {
        if (fn_12_38DBC()->value == 1) {
            result = fn_12_3AB00(self);
        }
    } else {
        MovieObject *movie;
        result = fn_12_34CC8();
        lbl_12_bss_1CC58++;
        lbl_12_bss_1CC5C++;

        if (lbl_12_bss_1B9DC[0] == 1) {
            MovieObject *movie;
            movie = fn_12_38DBC();
            if (fn_12_34C44(&movie->state)) {
                if (lbl_12_bss_1B9DC[0] == 1) {
                    fn_12_2CD6C();
                }
                movie->state = 0;
            }
        }

        fn_12_34CA8(result);
        result = fn_12_3AB00(self);
    }

    return result;
}
#pragma opt_lifetimes reset
/* fzgx:end fn_12_3ACD0 */

/* fzgx:begin fn_12_3ADC4 noprologue */
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
/* fzgx:end fn_12_3ADC4 */

/* fzgx:begin fn_12_3AE84 noprologue */
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

extern void *fn_12_34C84(void);
extern void fn_12_34C64(void *value);

extern int fn_80056BE0(LSC *loader);

extern int fn_12_38A0C(int error);

extern void fn_12_3858C(MwsPlayer *player);

extern void fn_12_3500C(MwsPlayer *player);

extern int fn_12_342B8(LSC *loader);

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
/* fzgx:end fn_12_3AE84 */
