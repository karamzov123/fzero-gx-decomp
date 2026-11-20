#include "types.h"
#include "sofdec/sfd.h"


/* --- rel/movie_module/fn_12_2CC24.c --- */
typedef struct MovieModuleState {
    u8 _pad_0[0x44];
    u32 field_44;
} MovieModuleState;

extern int fn_12_24990(MovieModuleState *state);
extern int fn_12_24A88(int arg0, u32 arg1);
extern void fn_12_2C9C4(MovieModuleState *state);

int fn_12_2CC24(MovieModuleState *state) {
    if (fn_12_24990(state)) {
        return fn_12_24A88(0, 0xFF000138);
    }
    state->field_44 = 1;
    fn_12_2C9C4(state);
    return 0;
}

/* --- rel/movie_module/SFD_IsSvrWait.c --- */
extern SfdLibraryWork lbl_12_bss_7C64;



int SFD_IsSvrWait(void) {
    SfdHandle **handles = lbl_12_bss_7C64.handles;
    int i;
    int waiting;
    SfdHandle *handle;
    for (i = 0; i < 8; i++) {
        handle = *handles;
        if (handle != 0) {
            if ((unsigned int)(handle->playback_state - 1) > 3) {
                waiting = 1;
            } else if (handle->field_0044 != 0) {
                waiting = 0;
            } else {
                waiting = 1;
            }
            if (waiting == 0) {
                return 0;
            }
        }
        handles++;
    }
    return 1;
}
