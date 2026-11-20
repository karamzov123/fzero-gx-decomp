#include "types.h"
#include "dol/globals.h"


/* --- dol/fn_80070158.c --- */
extern u32 LCEnable(void);
extern u32 lbl_801A6CE0;
extern u32 lbl_801A6CF0;
extern u32 fn_80070CF8(u32);
extern u32 lbl_801A6CEC;
extern u8 lbl_8019E140[16];
extern u32 lbl_801A6D00[2];
extern u32 lbl_801A6D30[2];

void fn_80070158(s32 useLC) {
    struct { u32 value; } offset;
    struct { u32 value; } first;
    u32 base;
    u32 second;
    s32 i;
    if (useLC) {
        LCEnable();
        lbl_801A6CF0 = 0xE0000000;
        lbl_801A6CE0 |= 2;
    } else {
        lbl_801A6CF0 = fn_80070CF8(0x4000);
    }
    base = lbl_801A6CF0;
    first.value = base + 0x1C0;
    offset.value = 0;
    lbl_801A6CEC = offset.value;
    lbl_801A6D00[0] = base + lbl_801A6CEC;
    lbl_801A6CEC += 0x1C0;
    first.value = base + lbl_801A6CEC;
    lbl_801A6CEC += 0x1C;
    lbl_801A6CEC = (((lbl_801A6CEC - 1) >> 5) + 1) << 5;
    second = base + lbl_801A6CEC;
    lbl_801A6CEC += 0xCA0;
    lbl_801A6D30[0] = first.value;
    lbl_801A6D38 = second;
    lbl_801A6CEC = (lbl_801A6CEC + 0x3FF) & ~0x3FF;
    for (i = 0; i < 16; i++) {
        u8 value;
        if (i < 14) {
            if (offset.value <= lbl_801A6CEC) value = 0xFF;
            else value = 0;
        } else value = 1;
        lbl_8019E140[i] = value;
        offset.value += 0x400;
    }
}

/* --- dol/fn_800702E4.c --- */
extern char lbl_8015AA78[11];
extern u8 lbl_8015AA84[160];
extern void OSPanic(const char *, int, const char *, ...);

s32 fn_800702E4(u32 arg0) {
    s32 k;
    s32 i;
    s32 j;
    u32 n;
    u32 result;

    result = 0;
    for (i = 0; i < 16; i++) {
        if (lbl_8019E140[i] == 0) {
            n = arg0 - 1;
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
                for (k = 0; k < arg0; k++) {
                    lbl_8019E140[i + k] = arg0 - k;
                }
                break;
            }
        }
    }
    if (result == 0) {
        OSPanic(lbl_8015AA78, 158, (const char *)lbl_8015AA84);
    }
    return result;
}

/* --- dol/fn_8007048C.c --- */
s32 fn_8007048C(void) {
    s32 i;
    s32 count;

    count = 0;
    for (i = 0; i < 16; i++) {
        if (lbl_8019E140[i] != 0) {
            count++;
        }
    }
    return 16 - count;
}

/* --- dol/fn_80070538.c --- */
extern u32 lbl_801A6CF8;
extern u32 lbl_801A6CFC;
extern u8 lbl_801A6621;
extern u8 lbl_801A6CE8;
extern u8 lbl_801A6CE9;
extern void * OSGetArenaLo(void);
extern u32 OSGetArenaHi(void);
extern u32 fn_8000E7A0(void);
extern u32 fn_8000E794(void);
extern void OSSetArenaLo(u32);
extern void OSSetArenaHi(u32);
extern void fn_80070A58(void);


void fn_80070538(void) {
    u32 temp_r4;
    u32 var_r3;
    u32 temp_r31;
    void *temp_r30;
    u32 var_r29;

    temp_r30 = (void *)(OSGetArenaLo());
    var_r29 = OSGetArenaHi();
    (*(u32 *)((u8 *)(&lbl_801A6CF8) + 0)) = 0;
    (*(u32 *)((u8 *)(&lbl_801A6CFC) + 0)) = 0;
    temp_r31 = fn_8000E7A0();
    if (((u8) (*(u8 *)((u8 *)(&lbl_801A6CE9) + 0)) != 0) || (temp_r31 <= 0x01800000U)) {
        var_r3 = 0x01800000;
    } else {
        var_r3 = fn_8000E794();
    }
    if (var_r3 > 0x01800000U) {
        temp_r4 = (*(u32 *)((u8 *)(&lbl_801A6CE0) + 0)) | 8;
        (*(u32 *)((u8 *)(&lbl_801A6CE0) + 0)) = temp_r4;
        if ((u8) (*(u8 *)((u8 *)(&lbl_801A6CE8) + 0)) == 0) {
            (*(u32 *)((u8 *)(&lbl_801A6CF8) + 0)) = var_r29;
            (*(u32 *)((u8 *)(&lbl_801A6CE0) + 0)) = temp_r4 | 1;
            var_r29 -= temp_r31 + 0xFE800000;
            (*(u32 *)((u8 *)(&lbl_801A6CFC) + 0)) = var_r29;
        } else {
            (*(u32 *)((u8 *)(&lbl_801A6CFC) + 0)) = var_r29;
            (*(u32 *)((u8 *)(&lbl_801A6CF8) + 0)) = var_r29 + (var_r3 - temp_r31);
        }
    }
    (*(u8 *)((u8 *)(&lbl_801A6621) + 0)) = 0;
    OSSetArenaLo((u32)(temp_r30));
    OSSetArenaHi(var_r29);
    fn_80070A58();
}
