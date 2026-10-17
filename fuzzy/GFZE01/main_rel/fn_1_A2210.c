/* Non-matching: best partial attempt (91.99% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sound.h"

typedef struct {
    void *primary;
    void *secondary;
} SoundHandles;

typedef struct {
    u8 pad_0[0x1c];
    u32 flags;
    u8 pad_20[4];
    f32 fade[2];
    u8 current_cue;
    u8 pad_2d[0xb];
    SoundHandles *handles;
    u8 pad_3c[0x768];
    u32 request_flags;
    u8 pad_7a8[2];
    u8 queued;
    u8 pad_7ab[0xd7];
    u8 busy;
    u8 pad_883;
    s16 volume[2];
    f32 target_volume[2];
} SoundControl;

typedef struct {
    s8 sound;
    u8 pad_1;
    s16 command;
} SoundCue;

extern u32 lbl_1_bss_6EA98;
extern u8 lbl_1_rodata_43B4[];
extern const f32 lbl_1_rodata_42E0;
extern const f32 lbl_1_rodata_42E4;
extern const f32 lbl_1_rodata_42E8;
extern s32 fn_1_F2F34(void);
extern s32 fn_8004C658(void *);
extern void fn_8004D18C(void *, const char *);
extern void fn_8004BF0C(void *, s32);
extern void ADXT_Pause(void *, s32);
extern void fn_80067898(u32);

static inline s32 lookup_volume(u32 index) {
    return ((const s16 *)&lbl_1_data_2D93C)[index];
}

static inline s16 *output_volumes(SoundControl *state) {
    return state->volume;
}

static inline void set_second_volume(s16 *output, s16 volume) {
    output[1] = volume;
}

static inline void queue_request(SoundControl *state) {
    u32 request = state->request_flags;
    state->queued = 1;
    state->request_flags = request | 0x20;
}

void fn_1_A2210(u32 cue) {
    SoundControl *state = (SoundControl *)&lbl_1_bss_6EA98;
    SoundHandles *handles;
    void *secondary;
    s8 sound;
    s16 command;
    u32 flags;
    const char *filename;

    if (state->handles == 0 || lbl_1_bss_8CA24 != 0 ||
        lbl_1_bss_8B5F0 != 0 || lbl_1_bss_8B5F1 != 0 || state->queued != 0) {
        return;
    }
    if (fn_1_F2F34() != 0) {
        return;
    }
    if (fn_8004C658(state->handles->primary) != 3) {
        return;
    }
    if ((u8)cue > 45) {
        sound = -1;
        command = -1;
    } else {
        sound = ((const s8 *)lbl_1_rodata_43B4)[(u8)cue * 4];
        command = ((const SoundCue *)lbl_1_rodata_43B4)[(u8)cue].command;
    }
    if (sound != -1) {
        handles = state->handles;
        secondary = handles->secondary;
        if (state->busy == 0 && secondary != 0 && secondary != (void *)-1) {
            if (secondary == handles->primary) {
                flags = state->flags;
                state->flags = flags & ~4u;
                if (flags & 1) {
                    state->volume[0] = ((const s16 *)&lbl_1_data_2D93C)[(u8)sound];
                } else {
                    f32 volume = (f32)lookup_volume((u8)sound);
                    state->fade[0] = lbl_1_rodata_42E0;
                    state->target_volume[0] = volume;
                }
            }
            if (secondary == handles->secondary) {
                flags = state->flags;
                state->flags = flags & ~8u;
                if (flags & 2) {
                    set_second_volume(state->volume, ((const s16 *)&lbl_1_data_2D93C)[(u8)sound]);
                } else {
                    f32 volume = (f32)lookup_volume((u8)sound);
                    state->fade[1] = lbl_1_rodata_42E4;
                    state->target_volume[1] = volume;
                }
            }
            filename = ((const char **)&lbl_1_data_2D7B8)[(u8)sound];
            cue = (u8)sound;
            fn_8004D18C(secondary, filename);
            flags = state->flags;
            if (flags & 3) {
                if (flags & 1) {
                    state->target_volume[0] = lbl_1_rodata_42E8;
                }
                if (flags & 2) {
                    state->target_volume[1] = lbl_1_rodata_42E8;
                }
                fn_8004BF0C(secondary, -400);
            } else {
                fn_8004BF0C(secondary, ((const s16 *)&lbl_1_data_2D93C)[cue]);
            }
            state->current_cue = cue;
        }
        ADXT_Pause(state->handles->secondary, 1);
        fn_80067898((u32)(s32)command | 0xa8000000);
    }
    queue_request(state);
}
