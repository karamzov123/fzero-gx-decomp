/* Non-matching: best partial attempt (97.71% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
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
    void (*unget_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
    int (*get_num_data)(SJ *sj, int channel);
    int (*is_get_chunk)(SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ *sj, SJErrorCallback callback, void *object);
};

struct SJ {
    const SJInterface *interface;
};

typedef struct Track {
    s8 used;
    s8 unk_01;
    s8 unk_02;
    u8 pad_03;
    SJ *sj;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 pad_1c[12];
    s32 unk_28;
    s32 unk_2c;
    u8 pad_30[12];
    s32 unk_3c;
    s8 unk_40;
    u8 pad_41[19];
    s32 unk_54;
    s32 unk_58;
} Track;

extern s32 lbl_8012B900[];
extern s32 lbl_8017D6F8[];
extern Track lbl_8017D708[];
extern void fn_80046738(void);
extern void fn_80046718(void);

static inline Track *alloc_track(SJ *sj, s32 start, s32 count) {
    Track *track = NULL;
    s32 i;

    for (i = 0; i < count; i++) {
        track = &lbl_8017D708[start++];
        if (track->used == 0) {
            break;
        }
    }

    if (i == count) {
        track = NULL;
    } else {
        fn_80046738();
        track->unk_01 = 1;
        track->unk_02 = 0;
        track->sj = sj;
        track->unk_08 = 0;
        track->unk_0c = 0;
        track->unk_10 = 0;
        track->unk_28 = 512;
        track->unk_54 = 0;
        track->unk_58 = 0xFFFFF;

        track->unk_2c = track->unk_10 / 2048;
        if ((track->unk_10 % 2048) > 0) {
            track->unk_2c++;
        }

        if (track->sj != NULL) {
            {
                s32 pos;
                *(s32 *)((u8 *)track + 0x3c) = sj->interface->get_num_data(sj, 0) + sj->interface->get_num_data(sj, 1);
                pos = track->unk_3c;
                track->unk_14 = pos;
                track->unk_18 = pos;
            }
        }

        track->unk_40 = 0;
        track->used = 1;
        fn_80046718();
    }

    return track;
}

Track *fn_8004B4E0(SJ *sj, s32 type) {
    s32 *cfg = lbl_8012B900;

    if (type < 0x100) {
        return alloc_track(sj, lbl_8017D6F8[0], cfg[0]);
    } else {
        return alloc_track(sj, cfg[1], cfg[2]);
    }
}
