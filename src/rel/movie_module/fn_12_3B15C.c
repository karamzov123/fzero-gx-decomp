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

typedef struct MwsStHandle MwsStHandle;

typedef struct MwsStManagerInterface {
    void *reserved_00;
    void (*finish)(void);
    void *reserved_08[2];
    void (*destroy)(MwsStHandle *handle);
    void (*start_sj)(void *backend, SJ *stream);
    void (*stop)(void *backend);
    int (*get_status)(void *backend);
    void *reserved_20;
    void (*pause)(void *backend, int paused);
    void (*set_volume)(void *backend, int volume);
    int (*get_volume)(void *backend);
} MwsStManagerInterface;

struct MwsStHandle {
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

void fn_12_3B15C(MwsStHandle *handle);

extern void MWSFSVM_GotoIdleBorder(void);

extern MwsStManager lbl_12_data_E90;

static inline int mwsst_IsValid(const MwsStHandle *handle) {
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

void fn_12_3B15C(MwsStHandle *handle) {
    void (* fzgx_live_)(SJ *sj);
    void (* fzgx_live)(MwsStHandle *handle);
    MwsStHandle *sound;
    SJ *stream;
    if (mwsst_IsValid(handle) != 1) {
        return;
    }
    sound = handle->backend;
    stream = handle->stream;
    if (sound == 0) {
        return;
    }

    if (mwsst_IsValid(sound) == 1) {
        void *backend = sound->backend;
        if (lbl_12_data_E90.interface != 0 && lbl_12_data_E90.interface->stop != 0) {
            lbl_12_data_E90.interface->stop(backend);
        }
    }
    handle->active = 0;
    {
        MwsStManagerInterface *iface;
        iface = lbl_12_data_E90.interface;
        if (sound != 0 && iface != 0 && iface->destroy != 0) {
            fzgx_live = iface->destroy;
            fzgx_live(sound);
        }
    }
    fzgx_live_ = stream->interface->destroy;
    fzgx_live_(stream);
    handle->backend = 0;
    {
        MwsStManager *manager = &lbl_12_data_E90;
        MwsStManagerInterface *interface = manager->interface;
        if (interface != 0 && manager->active_count != 0) {
            manager->active_count--;
            if (manager->active_count == 0 && interface->finish != 0) {
                interface->finish();
            }
        }
    }
}


