#include "types.h"


/* --- dol/fn_8003A1CC.c --- */
typedef struct Fn8003A1CC_HuffTab {
    u8 *bits;
    u8 pad_4[0x8];
    u16 numVals;
    u8 pad_E[0x2];
    u8 *vals;
    u8 pad_14[0x94];
} Fn8003A1CC_HuffTab;

typedef struct Fn8003A1CC_Info {
    u8 pad_0[0x400];
    u8 *c;
    u8 pad_404[0x14];
    u8 validHuffmanTabs;
    u8 pad_419[0x7];
    Fn8003A1CC_HuffTab huffmanTabs[4];
} Fn8003A1CC_Info;

extern u8 fn_8003A4E8(Fn8003A1CC_Info *info, u8 tabIndex, u8 *bits);
extern u8 fn_8003A680(Fn8003A1CC_Info *info, u8 tabIndex);
extern void fn_8003A760(Fn8003A1CC_Info *info, u8 tabIndex);

u8 fn_8003A1CC(Fn8003A1CC_Info *info) {
    u8 tabClass;
    u8 id;
    u8 i;
    u8 tabIndex;
    u8 err;
    u8 byte;
    u8 *bits;
    u16 length;
    u16 numVals;

    length = ((info->c[0] << 8) | info->c[1]);
    info->c += 2;
    length -= 2;

    do {
        byte = *info->c++;
        bits = info->c;
        tabClass = byte >> 4;
        id = byte & 0xF;
        if (tabClass > 1 || id >= 2) {
            return 7;
        }
        tabIndex = (id << 1) + tabClass;

        numVals = 0;
        for (i = 0; i < 16; i++) {
            numVals += *info->c++;
        }
        info->huffmanTabs[tabIndex].bits = bits;
        info->huffmanTabs[tabIndex].vals = info->c;
        info->huffmanTabs[tabIndex].numVals = numVals;
        for (i = 0; i < numVals; i++) {
            info->c++;
        }

        if ((err = fn_8003A4E8(info, tabIndex, bits)) != 0) {
            return err;
        }
        if ((err = fn_8003A680(info, tabIndex)) != 0) {
            return err;
        }
        fn_8003A760(info, tabIndex);
        length -= numVals + 17;
        info->validHuffmanTabs |= 1 << tabIndex;
    } while (length);

    return 0;
}

/* --- dol/fn_8003A3D4.c --- */
s32 fn_8003A91C(void *arg0);

s32 fn_8003A3D4(u8 *arg0) {
    u8 count;
    u8 i;
    struct { u8 *value; } p;

    *(u8 **)(arg0 + 0x400) += 2;
    count = *(*(u8 **)(arg0 + 0x400))++;
    if (count != *(arg0 + 0x41C)) {
        return 6;
    }

    p.value = arg0;
    for (i = 0; i < count; i++, p.value += 0x30) {
        s32 hi;
        u16 val;
        s32 lo;
        u16 unk8;
        s16 shift;
        s32 diff;

        (*(u8 **)(arg0 + 0x400)) = (*(u8 **)(arg0 + 0x400)) + 1;
        val = (*(*(u8 **)(((0x400) + arg0)))++);
        hi = val >> 4;
        *(u8 *)(p.value + 0x6C4) = hi;
        lo = val & 0xF;
        *(u8 *)(p.value + 0x6C5) = lo;
        if (!(*(((0x418) + arg0)) & (1 << hi))) {
            return 9;
        }
        if (!(*(((0x418) + arg0)) & (1 << (lo + 1)))) {
            return 9;
        }

        diff = *(arg0 + 0x41B) - *(((0x6C2) + p.value));
        unk8 = (*(u32 *)(p.value + 0x6C8));
        shift = 16 >> diff;
        *(u32 *)(p.value + 0x6D0) = *(u32 *)(arg0 + 0x7B4);
        *(u32 *)(arg0 + 0x7B4) += ((u16)unk8) * ((u16)shift);
    }

    *(u8 **)(arg0 + 0x400) += 3;
    return fn_8003A91C(arg0);
}
