#include "types.h"

/* view of the structure lbl_801A6D00 points to */
typedef struct fn_80070AC0_State {
    u8 unk_0[0x90];
    u32 unk_90;
    u32 unk_94;
} fn_80070AC0_State;

extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006DCDC(void);
extern u32 fn_80070CF8(u32 size);
extern u8 lbl_8019E140[16];
extern u32 lbl_801A6CE0;
extern u32 lbl_801A6CF0;
extern fn_80070AC0_State *lbl_801A6D00;

/* avsystem.c's .data strings, defined so that retail's one base register reaches them */
char fzgx_obj_lbl_8015AA78[11] = "avsystem.c";
char fzgx_obj_lbl_8015AA84[0xA0] = "\n\n... Not enough Locked Cache.\n\0"
    "ArenaAllocateDirection: no effect this call.\n\0\0\0"
    "SetSimulate24MB: no effect this call.\n\0\0"
    "SetAbsolute24MB: no effect this call.\n";
char fzgx_obj_lbl_8015AB24[0x20] = "init_system: invalid TV format\n";
char lbl_8015AB24__fzgx_offset_20[0x2C] = "Matrix Stack is 0.\nnot support system.\n";

/* the body of fn_800702E4 (same TU), which retail inlines here with the block count computed from a byte size */
static inline u32 alloc_blocks(u32 size) {
    u32 count;
    s32 i;
    u32 n;
    u32 result;
    s32 j;

    result = 0;
    for (i = 0; i < 16; i++) {
        if (lbl_8019E140[i] == 0) {
            count = (size + 0x3FF) >> 10;
            n = count - 1;
            j = i + 1;
            while (n != 0 && j < 16) {
                if (lbl_8019E140[j] != 0) {
                    break;
                }
                n--;
                j++;
            }
            if (n == 0) {
                result = lbl_801A6CF0 + (i << 10);
                for (j = 0; j < count; j++) {
                    lbl_8019E140[i + j] = count - j;
                }
                break;
            }
        }
    }
    if (result == 0) {
        OSPanic(fzgx_obj_lbl_8015AA78, 158, fzgx_obj_lbl_8015AA84);
    }
    return result;
}

void fn_80070AC0(u32 count, s32 locked) {
    if (count == 0) {
        OSPanic(fzgx_obj_lbl_8015AA78, 514, lbl_8015AB24__fzgx_offset_20);
    }
    lbl_8006D758();
    lbl_8006DCDC();
    if (locked != 0 && !(lbl_801A6CE0 & 2)) {
        locked = 0;
    }
    if (locked != 0) {
        lbl_801A6D00->unk_90 = alloc_blocks(count * 0x30);
    } else {
        lbl_801A6D00->unk_90 = fn_80070CF8(count * 0x30);
    }
    lbl_801A6D00->unk_94 = lbl_801A6D00->unk_90 + count * 0x30;
}
