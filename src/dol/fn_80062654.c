#include "types.h"
#pragma use_lmw_stmw on

typedef struct {
    u8 size;
    u8 pad1[3];
    u8 lo;
    u8 hi;
} SndRegion;

typedef struct {
    u8 state;
    u8 active;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u8 f8;
    u8 f9;
    u8 fA;
    u8 program;
    u8 count;
    u8 padD[3];
    SndRegion *regions;
    u8 voices[16][4];
} SndTrack;

typedef struct {
    u8 pad0[0x444];
    u32 command;
    u8 pad448[0x5A74 - 0x448];
    s16 h5A74[16];
    u8 pad5A94[0x5AF4 - 0x5A94];
    s16 h5AF4[16];
    u8 pad5B14[8];
    void (*callback)(s32, u32);
} SndState;

extern SndState *lbl_801A6C80;
extern SndTrack lbl_80192D68[16];

extern void fn_80062360(u32, u32);
extern void fn_80060C54(u8, SndRegion *, u32, u8);
extern void fn_8005FBDC(u8);

static inline void set_program(u32 track, u32 program) {
    u8 i;
    SndRegion *r;

    if (lbl_80192D68[track].active != 0) {
        r = lbl_80192D68[track].regions;
        for (i = 0; i <= lbl_80192D68[track].count; i++) {
            if (r->lo <= program && r->hi >= program && program != 0) {
                fn_80060C54(program, r, track, i);
            } else if (lbl_80192D68[track].voices[i][0] == 1) {
                if (lbl_80192D68[track].voices[i][2] != 0xFF) {
                    fn_8005FBDC(lbl_80192D68[track].voices[i][2]);
                }
                if (lbl_80192D68[track].voices[i][3] != 0xFF) {
                    fn_8005FBDC(lbl_80192D68[track].voices[i][3]);
                }
                lbl_80192D68[track].voices[i][0] = 0;
            }
            r = (SndRegion *)((u8 *)r + r->size);
        }
        lbl_80192D68[track].program = program;
    } else if (lbl_801A6C80->callback != NULL) {
        lbl_801A6C80->callback(-5, lbl_801A6C80->command);
    }
}

static inline void refresh(u32 track) {
    if (lbl_80192D68[track].active != 0 && lbl_80192D68[track].program != 0) {
        set_program(track, lbl_80192D68[track].program);
    }
}

void fn_80062654(void) {
    u32 command = lbl_801A6C80->command;
    u32 track = (command >> 16) & 0xF;
    u32 value = (command >> 8) & 0x7F;

    switch (command & 0xFF700000) {
    case 0xA5000000:
        fn_80062360(track, value);
        break;
    case 0xA5100000:
        lbl_80192D68[track].f3 = value;
        refresh(track);
        break;
    case 0xA5200000:
        lbl_80192D68[track].f4 = value;
        refresh(track);
        break;
    case 0xA5300000:
        lbl_80192D68[track].f5 = value;
        refresh(track);
        break;
    case 0xA5400000:
        lbl_80192D68[track].f6 = value;
        refresh(track);
        break;
    case 0xA5500000:
        lbl_80192D68[track].f7 = value;
        refresh(track);
        break;
    case 0xA5700000:
        lbl_80192D68[track].f2 = value;
        break;
    case 0xA7000000:
        lbl_80192D68[track].f9 = value;
        refresh(track);
        break;
    case 0xA7100000:
        lbl_80192D68[track].fA = value;
        refresh(track);
        break;
    case 0xA6100000:
        value += 0x80;
    case 0xA6000000:
        set_program(track, value);
        break;
    case 0xA7200000:
        lbl_801A6C80->h5A74[track] = lbl_801A6C80->h5AF4[track];
        refresh(track);
        break;
    }
}
