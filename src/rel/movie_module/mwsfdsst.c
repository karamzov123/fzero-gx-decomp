#include "types.h"
#include "sofdec/mwsst.h"

typedef struct fn_12_3B15C_SJCK {
    unsigned char *data;
    int len;
} fn_12_3B15C_SJCK;

typedef void (*SJErrorCallback)(void *object, int error);

typedef struct fn_12_3B15C_SJInterface fn_12_3B15C_SJInterface;

typedef struct fn_12_3B15C_SJ fn_12_3B15C_SJ;

struct fn_12_3B15C_SJInterface {
    void *reserved[3];
    void (*destroy)(fn_12_3B15C_SJ *sj);
    const void *(*get_uuid)(fn_12_3B15C_SJ *sj);
    void (*reset)(fn_12_3B15C_SJ *sj);
    void (*get_chunk)(fn_12_3B15C_SJ *sj, int channel, int max_size, fn_12_3B15C_SJCK *chunk);
    void (*unget_chunk)(fn_12_3B15C_SJ *sj, int channel, fn_12_3B15C_SJCK *chunk);
    void (*put_chunk)(fn_12_3B15C_SJ *sj, int channel, fn_12_3B15C_SJCK *chunk);
    int (*get_num_data)(fn_12_3B15C_SJ *sj, int channel);
    int (*is_get_chunk)(fn_12_3B15C_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(fn_12_3B15C_SJ *sj, SJErrorCallback callback, void *object);
};

struct fn_12_3B15C_SJ {
    const fn_12_3B15C_SJInterface *interface;
};

typedef struct MwsStHandle_u2 MwsStHandle_u2;

struct MwsStHandle_u2 {
    int active;
    unsigned char reserved_04[8];
    fn_12_3B15C_SJ *stream;
    int element_id;
    void *backend;
};

typedef struct fn_12_3B15C_MwsStManagerInterface {
    void *reserved_00;
    void (*finish)(void);
    void *reserved_08[2];
    void (*destroy)(MwsStHandle_u2 *handle);
    void (*start_sj)(void *backend, fn_12_3B15C_SJ *stream);
    void (*stop)(void *backend);
    int (*get_status)(void *backend);
    void *reserved_20;
    void (*pause)(void *backend, int paused);
    void (*set_volume)(void *backend, int volume);
    int (*get_volume)(void *backend);
} fn_12_3B15C_MwsStManagerInterface;

typedef struct fn_12_3B15C_MwsStManager {
    fn_12_3B15C_MwsStManagerInterface *interface;
    int active_count;
} fn_12_3B15C_MwsStManager;
extern u32 lbl_12_data_E90[2];

/* fzgx:begin fn_12_3B15C */
/* --- rel/movie_module/fn_12_3AE84.c --- */

typedef struct SfdHandle SfdHandle;

/* --- rel/movie_module/fn_12_3B15C.c --- */
/* --- rel/movie_module/fn_12_3B15C.c --- */





static inline int fn_12_3B15C_mwsst_IsValid(const MwsStHandle_u2 *handle) {
    if ((*((fn_12_3B15C_MwsStManager *)&lbl_12_data_E90)).interface == 0) {
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

void fn_12_3B15C(MwsStHandle_u2 *handle) {
    void (* fzgx_live_)(fn_12_3B15C_SJ *sj);
    void (* fzgx_live)(MwsStHandle_u2 *handle);
    MwsStHandle_u2 *sound;
    fn_12_3B15C_SJ *stream;
    if (fn_12_3B15C_mwsst_IsValid(handle) != 1) {
        return;
    }
    sound = handle->backend;
    stream = handle->stream;
    if (sound == 0) {
        return;
    }

    if (fn_12_3B15C_mwsst_IsValid(sound) == 1) {
        void *backend = sound->backend;
        if ((*((fn_12_3B15C_MwsStManager *)&lbl_12_data_E90)).interface != 0 && (*((fn_12_3B15C_MwsStManager *)&lbl_12_data_E90)).interface->stop != 0) {
            (*((fn_12_3B15C_MwsStManager *)&lbl_12_data_E90)).interface->stop(backend);
        }
    }
    handle->active = 0;
    {
        fn_12_3B15C_MwsStManagerInterface *iface;
        iface = (*((fn_12_3B15C_MwsStManager *)&lbl_12_data_E90)).interface;
        if (sound != 0 && iface != 0 && iface->destroy != 0) {
            fzgx_live = iface->destroy;
            fzgx_live(sound);
        }
    }
    fzgx_live_ = stream->interface->destroy;
    fzgx_live_(stream);
    handle->backend = 0;
    {
        fn_12_3B15C_MwsStManager *manager = &(*((fn_12_3B15C_MwsStManager *)&lbl_12_data_E90));
        fn_12_3B15C_MwsStManagerInterface *interface = manager->interface;
        if (interface != 0 && manager->active_count != 0) {
            manager->active_count--;
            if (manager->active_count == 0 && interface->finish != 0) {
                interface->finish();
            }
        }
    }
}
/* fzgx:end fn_12_3B15C */

/* fzgx:begin fn_12_3B2EC */
/* --- rel/movie_module/fn_12_3B2EC.c --- */

typedef struct MwsStPlayerPrefix {
    unsigned char reserved_000[0x40];
    SfdHandle *player;
    unsigned char reserved_044[424];
    MwsStHandle_u2 sound;
} MwsStPlayerPrefix;

extern int fn_12_26734(SfdHandle *handle, int element_id, fn_12_3B15C_SJ *stream, int channel, int flags);

void fn_12_3B2EC(MwsStPlayerPrefix *wrapper) {
    MwsStHandle_u2 *sound = &wrapper->sound;
    SfdHandle *player = wrapper->player;
    MwsStHandle_u2 *backend = sound->backend;
    fn_12_3B15C_SJ *stream = sound->stream;
    int element_id = sound->element_id;
    int valid;

    if ((*((fn_12_3B15C_MwsStManager *)&lbl_12_data_E90)).interface == 0) {
        valid = 0;
    } else if (sound->active != 1) {
        valid = 0;
    } else if (backend == 0) {
        valid = 0;
    } else {
        valid = 1;
    }

    if (valid != 1) {
        return;
    }
    if (backend != 0 && fn_12_3B15C_mwsst_IsValid(backend) == 1) {
        void *playback = backend->backend;
        if ((*((fn_12_3B15C_MwsStManager *)&lbl_12_data_E90)).interface != 0 && (*((fn_12_3B15C_MwsStManager *)&lbl_12_data_E90)).interface->stop != 0) {
            (*((fn_12_3B15C_MwsStManager *)&lbl_12_data_E90)).interface->stop(playback);
        }
    }
    stream->interface->reset(stream);
    fn_12_26734(player, element_id + 0xC0, stream, 0, 0);
}
/* fzgx:end fn_12_3B2EC */

/* fzgx:begin MWSST_Pause */
/* --- rel/movie_module/MWSST_Pause.c --- */

static inline int MWSST_Pause_mwsst_IsValid(const MwsStHandle *handle) {
    if ((*((MwsStManager *)&lbl_12_data_E90)).interface == 0) {
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

void MWSST_Pause(MwsStHandle *handle, int paused) {
    if (MWSST_Pause_mwsst_IsValid(handle) == 1) {
        void *backend = handle->backend;
        if ((*((MwsStManager *)&lbl_12_data_E90)).interface != 0 && (*((MwsStManager *)&lbl_12_data_E90)).interface->pause != 0) {
            (*((MwsStManager *)&lbl_12_data_E90)).interface->pause(backend, paused);
        }
    }
}
/* fzgx:end MWSST_Pause */

/* fzgx:begin MWSST_GetStat */
/* --- rel/movie_module/MWSST_GetStat.c --- */
int MWSST_GetStat(MwsStHandle *handle) {
    int status = 0;
    void *backend;
    if (MWSST_Pause_mwsst_IsValid(handle) != 1) {
        return 0;
    }
    backend = handle->backend;
    if ((*((MwsStManager *)&lbl_12_data_E90)).interface != 0 && (*((MwsStManager *)&lbl_12_data_E90)).interface->get_status != 0) {
        status = (*((MwsStManager *)&lbl_12_data_E90)).interface->get_status(backend);
    }
    return status;
}
/* fzgx:end MWSST_GetStat */

/* fzgx:begin fn_12_3B540 */
typedef struct MovieObject {
    s32 state;
    u8 pad[0x10];
    void *movie;
} MovieObject;

typedef struct MovieModule {
    u8 pad[0x18];
    void (*callback)(void *, void *);
} MovieModule;


void fn_12_3B540(MovieObject *self) {
    MovieModule *module = (MovieModule *)lbl_12_data_E90[0];
    s32 result;

    if (module == 0) {
        result = 0;
    } else if (self->state != 1) {
        result = 0;
    } else if (self->movie == 0) {
        result = 0;
    } else {
        result = 1;
    }

    if (result == 1) {
        void *movie = self->movie;

        if (module != 0 && module->callback != 0) {
            module->callback(movie, module);
        }
    }
}
/* fzgx:end fn_12_3B540 */
