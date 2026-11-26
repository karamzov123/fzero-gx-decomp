#include "types.h"


/* --- dol/fn_80070AC0.c --- */
/* view of the structure lbl_801A6D00 points to */
typedef struct fn_80070AC0_State {
    u8 unk_0[0x90];
    u32 unk_90;
    u32 unk_94;
} fn_80070AC0_State;

extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006DCDC(void);
extern void *fn_80070CF8(u32 size);
extern u8 lbl_8019E140[16];
extern u32 lbl_801A6CE0;
extern u32 lbl_801A6CF0;
extern fn_80070AC0_State *lbl_801A6D00;

/* The AV system diagnostics share a retail data base with the file name. */
char lbl_8015AA78[11] = "avsystem.c";
char lbl_8015AA84[0xA0] = "\n\n... Not enough Locked Cache.\n\0"
    "ArenaAllocateDirection: no effect this call.\n\0\0\0"
    "SetSimulate24MB: no effect this call.\n\0\0"
    "SetAbsolute24MB: no effect this call.\n";
char lbl_8015AB24[0x20] = "init_system: invalid TV format\n";
char avSystemErrorTail[0x2C] = "Matrix Stack is 0.\nnot support system.\n";

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
        OSPanic(lbl_8015AA78, 158, lbl_8015AA84);
    }
    return result;
}

void fn_80070AC0(u32 count, s32 locked) {
    if (count == 0) {
#ifdef VERSION_GFZP01
        OSPanic(lbl_8015AA78, 520, avSystemErrorTail);
#else
        OSPanic(lbl_8015AA78, 514, avSystemErrorTail);
#endif
    }
    lbl_8006D758();
    lbl_8006DCDC();
    if (locked != 0 && !(lbl_801A6CE0 & 2)) {
        locked = 0;
    }
    if (locked != 0) {
        lbl_801A6D00->unk_90 = alloc_blocks(count * 0x30);
    } else {
        lbl_801A6D00->unk_90 = (u32)fn_80070CF8(count * 0x30);
    }
    lbl_801A6D00->unk_94 = lbl_801A6D00->unk_90 + count * 0x30;
}

extern void *OSGetArenaHi(void);
extern void *OSGetArenaLo(void);
extern void OSSetArenaHi(void *);
extern void OSSetArenaLo(void *);
extern u8 lbl_801A6620;

void *fn_80070CF8(u32 size) {
    u8 *memory;

    size = (size + 31) & ~31u;
    if (lbl_801A6620 != 0) {
        memory = OSGetArenaHi();
        memory -= size;
        OSSetArenaHi(memory);
    } else {
        memory = OSGetArenaLo();
        OSSetArenaLo(memory + size);
    }
    return memory;
}

/* --- dol/fn_80070D60.c --- */
extern u32 lbl_801A6D10;
extern u32 lbl_801A6D14;
extern u32 lbl_801A6D18;
extern u32 lbl_801A6D1C;
extern u32 lbl_801A6D20;
extern u32 lbl_801A6D24;

struct fn_80070D60_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
};

void fn_80070D60(struct fn_80070D60_Arg0 *arg0) {
    lbl_801A6D24 = arg0->unk_0;
    lbl_801A6D20 = arg0->unk_4;
    lbl_801A6D1C = arg0->unk_8;
    lbl_801A6D18 = arg0->unk_C;
    lbl_801A6D14 = arg0->unk_10;
    lbl_801A6D10 = arg0->unk_14;
}

/* --- dol/fn_80070D94.c --- */
extern void fn_80071CB4(void);
extern void fn_80071CC0(void);
extern void fn_80071CE0(void);
extern void fn_80071CE8(void);
extern void fn_80071D0C(void);
extern void fn_80071D2C(void);

void fn_80070D94(void) {
    lbl_801A6D24 = (u32)fn_80071CB4;
    lbl_801A6D20 = (u32)fn_80071CC0;
    lbl_801A6D1C = (u32)fn_80071CE0;
    lbl_801A6D18 = (u32)fn_80071CE8;
    lbl_801A6D14 = (u32)fn_80071D0C;
    lbl_801A6D10 = (u32)fn_80071D2C;
}

/* --- dol/fn_80070DE0.c --- */
/* --- dol/fn_80070DE0.c --- */
extern u32 lbl_801A6D0C;

u32 fn_80070DE0(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D0C;
    lbl_801A6D0C = arg0;
    return v0;
}

/* --- dol/fn_80070DF0.c --- */
extern u32 lbl_801A6D08;

u32 fn_80070DF0(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D08;
    lbl_801A6D08 = arg0;
    return v0;
}

/* --- dol/fn_80070E00.c --- */
extern void fn_80071C64(void);
extern void fn_80071C8C(void);

void fn_80070E00(void) {
    lbl_801A6D0C = (u32)fn_80071C64;
    lbl_801A6D08 = (u32)fn_80071C8C;
}
