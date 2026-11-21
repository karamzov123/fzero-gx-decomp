#include "types.h"


/* --- dol/fn_8004A53C.c --- */
/* --- dol/fn_8004A53C.c --- */
struct fn_8004A53C_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};

u32 fn_8004A53C(struct fn_8004A53C_Arg0 *arg0);

/* --- dol/fn_8004A544.c --- */
struct fn_8004A544_Arg0 {
    u8 pad_0[0x28];
    u32 unk_28;
};

s32 fn_8004A544(struct fn_8004A544_Arg0 *arg0, u32 arg1);

/* --- dol/fn_8004A550.c --- */
typedef struct Fn8004A550Data {
    u8 _pad14[0x14];
    s32 field14;
    s32 field18;
} Fn8004A550Data;

s32 fn_8004A550(Fn8004A550Data *data, s32 value4, s32 value5);

/* --- dol/fn_8004A560.c --- */
struct fn_8004A560_Arg0 {
    u8 pad_0[0x14];
    u32 unk_14;
    u32 unk_18;
};
struct fn_8004A560_Arg1 {
    u32 unk_0;
};
struct fn_8004A560_Arg2 {
    u32 unk_0;
};

s32 fn_8004A560(struct fn_8004A560_Arg0 *arg0, struct fn_8004A560_Arg1 *arg1, struct fn_8004A560_Arg2 *arg2);

/* --- dol/ADXSTM_ExecServer.c --- */
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

enum {
    ADXSTM_STATUS_STOP = 1,
    ADXSTM_STATUS_READING = 2,
    ADXSTM_STATUS_END = 3,
    ADXSTM_STATUS_ERROR = 4,
    ADXSTM_MAX_SECTORS = 0xFFFFF,
    ADXSTM_SECTOR_SIZE = 0x800,
    ADXSTM_NUM_OBJECTS = 40
};

typedef struct CvFsObject CvFsObject;

typedef struct ADXStream ADXStream;

typedef void (*ADXStreamEosCallback)(void *object);

struct ADXStream {
    s8 used;
    s8 status;
    s8 read_active;
    s8 retry_count;
    SJ *sj;
    CvFsObject *file;
    s32 file_offset;
    s32 file_size;
    s32 file_sectors;
    s32 maximum_buffer_size;
    s32 minimum_buffer_size;
    s32 request_sectors;
    SJCK request_chunk;
    s32 maximum_request_sectors;
    s32 eos_sector;
    s32 transferred_bytes;
    ADXStreamEosCallback eos_callback;
    void *eos_object;
    s32 sj_buffer_size;
    s8 stop_requested;
    s8 bind_requested;
    s8 release_requested;
    s8 start_requested;
    s8 stop_pending;
    s8 file_open;
    s8 realtime;
    u8 reserved_4B[1];
    const char *filename;
    void *directory;
    s32 position;
    s32 transfer_limit;
};

extern s32 fn_80058A40(s32 *value);

extern s32 lbl_8017D6FC;

extern ADXStream lbl_8017D708[ADXSTM_NUM_OBJECTS];

void fn_8004A5F4(ADXStream *stream);

void ADXSTM_ExecServer(void) {
    s32 index;
    if (fn_80058A40(&lbl_8017D6FC) != 0) {
        for (index = 0; index < ADXSTM_NUM_OBJECTS; index++) {
            if (lbl_8017D708[index].used == 1) {
                fn_8004A5F4(&lbl_8017D708[index]);
            }
        }
        lbl_8017D6FC = 0;
    }
}
