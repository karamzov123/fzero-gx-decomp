#include "types.h"
struct Source { u32 *unk_0; u32 *unk_4; u32 *unk_8; };
struct Args {
    u32 *buffers[9];
    u8 unk_24;
    u8 pad_25[3];
    u8 unk_28[16];
    u8 unk_38[16];
    u8 unk_48[16];
    u32 unk_58;
    u32 unk_5c;
    s32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 *unk_6c;
    u32 *unk_70;
    void *unk_74;
    u32 unk_78;
    u32 unk_7c;
    u32 unk_80;
    s32 unk_84;
};

extern void fn_80024E6C(void *);
extern void fn_80025004(void *);

#pragma peephole off
#pragma opt_dead_assignments off
void fn_80025504(struct Source *arg0, struct Args *arg1) {
    u32 v0;
    s32 v1;
    u8 v5;
    
    u32 *v12;
    u32 *v13;
    u32 *v14;
    u32 *v15;
    u32 *v16;
    u32 *v17;
    u32 v11;
    u32 v42;
    s32 v43;

    v1 = arg1->unk_24 + 1;
    v15 = arg0->unk_0;
    v16 = arg0->unk_4;
    v17 = arg0->unk_8;
    v5 = v1 % 3;
    v12 = (*((arg1->buffers) + v5));
    v13 = (*((arg1->buffers) + (v5 + 3)));
    v14 = (*((arg1->buffers) + (v5 + 6)));
    for (v11 = 0; v11 < 160; v11++) {
        *v12++ = *v15++;
        *v13++ = *v16++;
        *v14++ = *v17++;
    }
    arg1->unk_84 = ((arg1->unk_60 >> 16) + 1);
    arg1->unk_80 = ((arg1->unk_60 & 0xFFFF) << 16);
    v42 = (arg1->unk_64 - 1);
    arg1->unk_64 = v42;
    if (v42 == 0) {
        arg1->unk_64 = arg1->unk_68;
        arg1->unk_60 = (-arg1->unk_60);
    }
    for (v43 = 0; (u32)v43 < 3; v43++) {
        arg1->unk_7c = arg1->unk_5c;
        arg1->unk_78 = arg1->unk_58;
        switch (v43) {
        case 0:
            arg1->unk_70 = (*((arg1->buffers) + (0)));
            arg1->unk_6c = arg0->unk_0;
            arg1->unk_74 = arg1->unk_28;
            break;
        case 1:
            arg1->unk_70 = (*((arg1->buffers) + (3)));
            arg1->unk_6c = arg0->unk_4;
            arg1->unk_74 = arg1->unk_38;
            break;
        case 2:
            arg1->unk_70 = (*((arg1->buffers) + (6)));
            arg1->unk_6c = arg0->unk_8;
            arg1->unk_74 = arg1->unk_48;
            break;
        }
        switch (arg1->unk_84) {
        case 0: fn_80024E6C(&arg1->unk_6c); break;
        case 1: fn_80025004(&arg1->unk_6c); break;
        }
    }
    arg1->unk_5c = arg1->unk_7c % 480;
    arg1->unk_58 = arg1->unk_78;
    arg1->unk_24 = v5;
}
#pragma opt_dead_assignments reset

#pragma peephole reset
