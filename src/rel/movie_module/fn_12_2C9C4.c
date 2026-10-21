#include "types.h"
#include "sofdec/sfd.h"

/* sfply_ExecOne, from the CC0 MK Deception decomp (sfd_ply.c) */

typedef struct SfplyHandle {
    u8 unknown_0000[0x44];
    int field_0044;
    int playback_state;
    int requested_state;
    u8 unknown_0050[0x9A0 - 0x50];
    int conditions_primary[64];
    u8 unknown_0AA0[0xF2C - 0xAA0];
    int timer_field_02B0;
    u8 unknown_0F30[0xF48 - 0xF30];
    int timer_field_02CC;
    u8 unknown_0F4C[0x2918 - 0xF4C];
    SfdTimerSummary timer_summaries[8];
} SfplyHandle;

extern unsigned long long fn_12_335B8(void);
extern void fn_12_2F264(SfplyHandle *handle, int kind);
extern void fn_12_2D288(SfplyHandle *handle);
extern int fn_12_2C640(SfplyHandle *handle);
extern int fn_12_2C0F8(SfplyHandle *handle);
extern int fn_12_2F1D0(SfplyHandle *handle, int kind);
extern int fn_12_2D73C(SfplyHandle *handle, int id);
extern void fn_12_2F210(SfplyHandle *handle, int a, int b, int c, int d);

static inline int sfply_IsTermAll(SfplyHandle *handle)
{
    int video_terminated;
    int audio_terminated;
    int terminated;

    if (handle->conditions_primary[6] == 0 &&
        handle->conditions_primary[5] == 0) return 1;
    terminated = 0;
    video_terminated = fn_12_2F1D0(handle, 6);
    audio_terminated = fn_12_2F1D0(handle, 7);
    switch (fn_12_2D73C(handle, 0x19)) {
    case 1: terminated = audio_terminated; break;
    case 2: terminated = video_terminated; break;
    case 3: terminated = audio_terminated | video_terminated; break;
    case 0: terminated = audio_terminated & video_terminated; break;
    }
    return terminated;
}

static inline int sfply_IsStartable(SfplyHandle *handle)
{
    if (handle->conditions_primary[14] == 0) return 1;
    if (handle->conditions_primary[5] == 0) return 1;
    if (handle->timer_field_02B0 != 0) return 1;
    if (handle->timer_field_02CC >= handle->conditions_primary[45]) return 1;
    if (sfply_IsTermAll(handle) != 0) return 1;
    return 0;
}

static inline int sfply_StatStby(SfplyHandle *handle, int state)
{
    switch (handle->requested_state) {
    case 2:
        state = 2;
        break;
    case 3:
        state = 3;
        break;
    case 4:
    case 6:
        if (sfply_IsStartable(handle) != 0) {
            fn_12_2F210(handle, 7, 6, 0, 0);
            state = 4;
        }
        break;
    }
    return state;
}

void fn_12_2C9C4(SfplyHandle *handle)
{
    int state;
    unsigned long long start;

    state = handle->playback_state;
    if ((unsigned int)(state - 1) > 3) {
        return;
    }
    if (handle->field_0044 == 0) {
        return;
    }
    handle->field_0044 = 0;
    start = fn_12_335B8();
    if ((unsigned int)(state - 2) <= 1 || state == 4) {
        fn_12_2F264(handle, 2);
        fn_12_2D288(handle);
    }

    state = handle->playback_state;
    switch (state) {
    case 0:
        break;
    case 1:
        switch (handle->requested_state) {
        case 2:
        case 3:
        case 4:
        case 6:
            state = 2;
            break;
        }
        break;
    case 2:
        state = fn_12_2C640(handle);
        break;
    case 3:
        state = sfply_StatStby(handle, state);
        break;
    case 4:
        state = fn_12_2C0F8(handle);
        break;
    case 5:
        state = handle->playback_state;
        break;
    case 6:
        state = handle->playback_state;
        break;
    }
    handle->playback_state = state;
    SFTMR_AddTsum(&handle->timer_summaries[5], fn_12_335B8() - start);
}
