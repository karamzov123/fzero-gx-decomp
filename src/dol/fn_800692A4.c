#include "types.h"

extern u32 lbl_801A6C80;

void fn_800692A4(u32 arg0) {
    u32 v0;
    u32 v2;
    u32 v1;
    u8 i;

    if ((arg0 & 0xFF00) > 0x1900) return;
    v0 = arg0 & ~0xFF;
    v1 = arg0 & 0xF;
    v2 = arg0 & 0x80;
    switch (v0) {
    case (s32)0xA0000100:
        for (i = 0; i < 16; i++) {
            if (v2 == 0) {
                *(u8 *)((u8 *)lbl_801A6C80 + i * 40 + 0x1188) = 0;
            } else {
                if (v1 == *((u8 *)lbl_801A6C80 + i * 40 + 0x118A)) {
                    if ((*((u8 *)lbl_801A6C80 + i * 40 + 0x1189) & 0x80) != 0) {
                        *(u8 *)((u8 *)lbl_801A6C80 + i * 40 + 0x1188) = 0;
                    }
                } else {
                    *(u8 *)((u8 *)lbl_801A6C80 + i * 40 + 0x1188) = 0;
                }
            }
        }
        break;
    case (s32)0xA0000200:
        for (i = 0; i < 16; i++) {
            if ((*((u8 *)lbl_801A6C80 + i * 40 + 0x1189) & 0x80) == 0) {
                if (v2 == 0) {
                    *(u8 *)((u8 *)lbl_801A6C80 + i * 40 + 0x1188) = 0;
                } else if (v1 != *((u8 *)lbl_801A6C80 + i * 40 + 0x118A)) {
                    *(u8 *)((u8 *)lbl_801A6C80 + i * 40 + 0x1188) = 0;
                }
            }
        }
        break;
    case (s32)0xA0000300:
        for (i = 0; i < 16; i++) {
            if ((*((u8 *)lbl_801A6C80 + i * 40 + 0x1189) & 0x80) != 0)
                *(u8 *)((u8 *)lbl_801A6C80 + i * 40 + 0x1188) = 0;
        }
        break;
    case (s32)0xA0001100:
        for (i = 0; i < 16; i++) {
            if (v1 == *((u8 *)lbl_801A6C80 + i * 40 + 0x118A)) {
                if (v2 == 0) {
                    *(u8 *)((u8 *)lbl_801A6C80 + i * 40 + 0x1188) = 0;
                } else if ((*((u8 *)lbl_801A6C80 + i * 40 + 0x1189) & 0x80) != 0) {
                    *(u8 *)((u8 *)lbl_801A6C80 + i * 40 + 0x1188) = 0;
                }
            }
        }
        break;
    case (s32)0xA0001200:
        if (v2 != 0) return;
        for (i = 0; i < 16; i++) {
            if (v1 == *((u8 *)lbl_801A6C80 + i * 40 + 0x118A) &&
                (*((u8 *)lbl_801A6C80 + i * 40 + 0x1189) & 0x80) == 0)
                *(u8 *)((u8 *)lbl_801A6C80 + i * 40 + 0x1188) = 0;
        }
        break;
    case (s32)0xA0001300:
        for (i = 0; i < 16; i++) {
            if (v1 == *((u8 *)lbl_801A6C80 + i * 40 + 0x118A) &&
                (*((u8 *)lbl_801A6C80 + i * 40 + 0x1189) & 0x80) != 0)
                *(u8 *)((u8 *)lbl_801A6C80 + i * 40 + 0x1188) = 0;
        }
        break;
    }
}
