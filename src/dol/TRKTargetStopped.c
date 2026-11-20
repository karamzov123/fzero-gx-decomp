#include "types.h"


/* --- dol/TRKTargetStopped.c --- */
extern struct TRKTargetStopped_gTRKState gTRKState;

struct TRKTargetStopped_gTRKState {
    u8 pad_0[0x98];
    u32 unk_98;
};

u32 TRKTargetStopped(void) {
    return gTRKState.unk_98;
}

/* --- dol/TRKTargetSupportRequest.c --- */
struct TRKTargetSupportRequest_CPUState {
    u8 pad_0[0xC];
    s32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u8 pad_1C[0x64];
    u32 unk_80;
};
extern struct TRKTargetSupportRequest_CPUState gTRKCPUState;

extern void fn_80088764(void *, s32);
extern void TRKPostEvent(void *);
extern u32 fn_8008AA04(u32, u32, u32, s32 *);
extern s32 fn_8008A91C(u32, s32 *);
extern u32 fn_8008A80C(u32, s32 *, u32, s32 *);
extern u32 fn_8008AD00(u32, u32, u32 *, s32 *, u32, u32);
extern void fn_8008AFF0(u32, u32);

struct TRKTargetSupportRequest_Event {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

s32 TRKTargetSupportRequest(void) {
    s32 local_c;
    s32 local_8;
    struct TRKTargetSupportRequest_Event event;
    u32 *p14;
    s32 state;
    s32 result;

    state = gTRKCPUState.unk_C;
    if (state != 0xD1 && state != 0xD0 && state != 0xD2 && state != 0xD3 && state != 0xD4) {
        fn_80088764(&event, 4);
        TRKPostEvent(&event);
        return 0;
    }

    if (state == 0xD2) {
        result = fn_8008AA04(gTRKCPUState.unk_10, gTRKCPUState.unk_14 & 0xFF, gTRKCPUState.unk_18, &local_c);
        if (local_c == 0 && result != 0) {
            local_c = 1;
        }
        gTRKCPUState.unk_C = local_c;
    } else if (state == 0xD3) {
        result = fn_8008A91C(gTRKCPUState.unk_10, &local_c);
        if (local_c == 0 && result != 0) {
            local_c = 1;
        }
        gTRKCPUState.unk_C = local_c;
    } else if (state == 0xD4) {
        local_8 = *(s32 *)gTRKCPUState.unk_14;
        result = fn_8008A80C(gTRKCPUState.unk_10, &local_8, gTRKCPUState.unk_18 & 0xFF, &local_c);
        if (local_c == 0 && result != 0) {
            local_c = 1;
        }
        gTRKCPUState.unk_C = local_c;
        *(s32 *)gTRKCPUState.unk_14 = local_8;
    } else {
        p14 = (u32 *)gTRKCPUState.unk_14;
        result = fn_8008AD00(gTRKCPUState.unk_10, gTRKCPUState.unk_18, p14, &local_c, 1, state == 0xD1 ? 1 : 0);
        if (local_c == 0 && result != 0) {
            local_c = 1;
        }
        gTRKCPUState.unk_C = local_c;
        if (state == 0xD1) {
            fn_8008AFF0(gTRKCPUState.unk_18, *p14);
        }
    }

    gTRKCPUState.unk_80 += 4;
    return result;
}
