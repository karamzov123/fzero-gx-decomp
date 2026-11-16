#include "types.h"

typedef struct SoundChan {
    u8 pad_00[0x1C];
    u32 unk_1C;
    u8 pad_20[0x124];
    u16 unk_144;
    u8 pad_146[4];
    u16 unk_14A[18];
    u8 pad_16E[0x2E];
    u16 unk_19C;
    s16 unk_19E;
} SoundChan;

typedef struct SoundEntry {
    SoundChan *chan;
    u32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u8 pad_14[8];
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    u16 unk_38;
    u16 unk_3A;
    u16 unk_3C;
    u16 unk_3E;
    u16 unk_40;
    u16 unk_42;
    u16 unk_44;
    u16 unk_46;
    u16 unk_48;
    u16 unk_4A;
    u16 unk_4C;
    u16 unk_4E;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
    u16 unk_56;
    u16 unk_58;
    u16 unk_5A;
    u16 unk_5C;
    u16 unk_5E;
} SoundEntry;

extern SoundEntry lbl_80176160[64];
extern u8 lbl_80128990[3008];
extern s32 lbl_801A6B80;
extern s32 lbl_801A6B84;
extern s32 lbl_801A6B88;

void AISetStreamVolLeft(u8 vol);
void AISetStreamVolRight(u8 vol);

static inline s32 get_curve(u8 *base, s32 idx) {
    s32 r;
    if (idx <= -904) {
        r = 0;
    } else if (idx >= 60) {
        r = 0xFF64;
    } else {
        r = *(u16 *)(base + (idx << 1) + 0x710);
    }
    return r;
}

void fn_80026FE0(void) {
    SoundEntry *e;
    s32 f6;
    SoundChan *c;
    s32 f7;
    u32 flags;
    u8 *base;
    u16 *p;
    s32 d;
    s32 i;

    base = lbl_80128990;
    for (i = 0; i < 64; i++) {
        e = &lbl_80176160[i];
        c = e->chan;
        f7 = 0;
        f6 = 0;
        if (c == NULL) {
            continue;
        }
        flags = 0;
        if (e->unk_04 & 0x20000000) {
            e->unk_38 = e->unk_3A;
            f7 = 1;
            e->unk_04 &= ~0x20000000;
        }
        if (e->unk_04 & 0x10000000) {
            if (e->unk_04 & 0x4) {
                e->unk_3A = 0;
            } else {
                e->unk_3A = get_curve(base, e->unk_08);
            }
            e->unk_04 &= ~0x10000000;
            e->unk_04 |= 0x20000000;
            f7 = 1;
        }
        if (e->unk_04 & 0x80000000) {
            e->unk_3C = e->unk_3E;
            e->unk_40 = e->unk_42;
            e->unk_44 = e->unk_46;
            e->unk_48 = e->unk_4A;
            e->unk_4C = e->unk_4E;
            e->unk_50 = e->unk_52;
            e->unk_54 = e->unk_56;
            e->unk_58 = e->unk_5A;
            e->unk_5C = e->unk_5E;
            e->unk_04 &= ~0x80000000;
            f6 = 1;
        }
        if (e->unk_04 & 0x40000000) {
            switch (lbl_801A6B88) {
            case 0:
                e->unk_3E = get_curve(base, e->unk_1C + e->unk_28);
                e->unk_42 = get_curve(base, e->unk_1C + e->unk_28);
                e->unk_46 = get_curve(base, (((((e->unk_1C)) + ((e->unk_2C))) + ((-30)))));
                if (e->unk_04 & 0x1) {
                    e->unk_4A = get_curve(base, e->unk_0C + e->unk_28);
                    e->unk_4E = get_curve(base, e->unk_0C + e->unk_28);
                    e->unk_52 = get_curve(base, (((((e->unk_0C)) + ((e->unk_2C))) + ((-30)))));
                } else {
                    e->unk_4A = get_curve(base, e->unk_1C + e->unk_0C + e->unk_28);
                    e->unk_4E = get_curve(base, e->unk_1C + e->unk_0C + e->unk_28);
                    e->unk_52 = get_curve(base, e->unk_1C + e->unk_0C + e->unk_2C - 30);
                }
                if (e->unk_04 & 0x2) {
                    e->unk_56 = get_curve(base, e->unk_10 + e->unk_28);
                    e->unk_5A = get_curve(base, e->unk_10 + e->unk_28);
                    e->unk_5E = get_curve(base, e->unk_10 + e->unk_2C - 30);
                } else {
                    e->unk_56 = get_curve(base, e->unk_1C + e->unk_10 + e->unk_28);
                    e->unk_5A = get_curve(base, e->unk_1C + e->unk_10 + e->unk_28);
                    e->unk_5E = get_curve(base, e->unk_1C + e->unk_10 + e->unk_2C - 30);
                }
                break;
            case 1:
            case 2:
                e->unk_3E = get_curve(base, e->unk_1C + e->unk_20 + e->unk_28);
                e->unk_42 = get_curve(base, e->unk_1C + e->unk_24 + e->unk_28);
                e->unk_46 = get_curve(base, e->unk_1C + e->unk_2C - 30);
                if (e->unk_04 & 0x1) {
                    e->unk_4A = get_curve(base, e->unk_0C + e->unk_20 + e->unk_28);
                    e->unk_4E = get_curve(base, e->unk_0C + e->unk_24 + e->unk_28);
                    e->unk_52 = get_curve(base, e->unk_0C + e->unk_2C - 30);
                } else {
                    e->unk_4A = get_curve(base, e->unk_1C + e->unk_0C + e->unk_20 + e->unk_28);
                    e->unk_4E = get_curve(base, e->unk_1C + e->unk_0C + e->unk_24 + e->unk_28);
                    e->unk_52 = get_curve(base, e->unk_1C + e->unk_0C + e->unk_2C - 30);
                }
                if (e->unk_04 & 0x2) {
                    e->unk_56 = get_curve(base, e->unk_10 + e->unk_20 + e->unk_28);
                    e->unk_5A = get_curve(base, e->unk_10 + e->unk_24 + e->unk_28);
                    e->unk_5E = get_curve(base, e->unk_10 + e->unk_2C - 30);
                } else {
                    e->unk_56 = get_curve(base, e->unk_1C + e->unk_10 + e->unk_20 + e->unk_28);
                    e->unk_5A = get_curve(base, e->unk_1C + e->unk_10 + e->unk_24 + e->unk_28);
                    e->unk_5E = get_curve(base, e->unk_1C + e->unk_10 + e->unk_2C - 30);
                }
                break;
            case 3:
                e->unk_3E = get_curve(base, e->unk_1C + e->unk_20 + e->unk_28);
                e->unk_42 = get_curve(base, e->unk_1C + e->unk_24 + e->unk_28);
                e->unk_56 = get_curve(base, e->unk_1C + e->unk_30 + e->unk_2C);
                e->unk_5A = get_curve(base, e->unk_1C + e->unk_34 + e->unk_2C);
                if (e->unk_04 & 0x1) {
                    e->unk_4A = get_curve(base, e->unk_0C + e->unk_20 + e->unk_28);
                    e->unk_4E = get_curve(base, e->unk_0C + e->unk_24 + e->unk_28);
                    e->unk_52 = get_curve(base, e->unk_0C + e->unk_30 + e->unk_2C);
                    e->unk_5E = get_curve(base, e->unk_0C + e->unk_34 + e->unk_2C);
                } else {
                    e->unk_4A = get_curve(base, e->unk_1C + e->unk_0C + e->unk_20 + e->unk_28);
                    e->unk_4E = get_curve(base, e->unk_1C + e->unk_0C + e->unk_24 + e->unk_28);
                    e->unk_52 = get_curve(base, e->unk_1C + e->unk_0C + e->unk_30 + e->unk_2C);
                    e->unk_5E = get_curve(base, e->unk_1C + e->unk_0C + e->unk_34 + e->unk_2C);
                }
                flags |= 0x4000;
                break;
            }
            e->unk_04 &= ~0x40000000;
            e->unk_04 |= 0x80000000;
            f6 = 1;
        }
        if (f7 != 0) {
            c->unk_19C = e->unk_38;
            c->unk_19E = (s16)((e->unk_3A - e->unk_38) / 160);
            c->unk_1C |= 0x200;
        }
        if (f6 != 0) {
            u16 v;

            p = c->unk_14A;
            v = e->unk_3C;
            *p++ = v;
            if (v != 0) {
                flags |= 0x1;
            }
            d = (e->unk_3E - e->unk_3C) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x8;
            }
            v = e->unk_40;
            *p++ = v;
            if (v != 0) {
                flags |= 0x2;
            }
            d = (e->unk_42 - e->unk_40) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x8;
            }
            v = e->unk_48;
            *p++ = v;
            if (v != 0) {
                flags |= 0x10;
            }
            d = (e->unk_4A - e->unk_48) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x40;
            }
            v = e->unk_4C;
            *p++ = v;
            if (v != 0) {
                flags |= 0x20;
            }
            d = (e->unk_4E - e->unk_4C) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x40;
            }
            v = e->unk_54;
            *p++ = v;
            if (v != 0) {
                flags |= 0x200;
            }
            d = (e->unk_56 - e->unk_54) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x800;
            }
            v = e->unk_58;
            *p++ = v;
            if (v != 0) {
                flags |= 0x400;
            }
            d = (e->unk_5A - e->unk_58) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x800;
            }
            v = e->unk_5C;
            *p++ = v;
            if (v != 0) {
                flags |= 0x1000;
            }
            d = (e->unk_5E - e->unk_5C) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x2000;
            }
            v = e->unk_44;
            *p++ = v;
            if (v != 0) {
                flags |= 0x4;
            }
            d = (e->unk_46 - e->unk_44) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x8;
            }
            v = e->unk_50;
            *p++ = v;
            if (v != 0) {
                flags |= 0x80;
            }
            d = (e->unk_52 - e->unk_50) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x100;
            }
            c->unk_144 = flags;
            c->unk_1C |= 0x12;
        }
    }
    if (lbl_801A6B84 > lbl_801A6B80) {
        lbl_801A6B80++;
        AISetStreamVolLeft(base[0xB8C + lbl_801A6B80]);
        AISetStreamVolRight(base[0xB8C + lbl_801A6B80]);
    } else if (lbl_801A6B84 < lbl_801A6B80) {
        lbl_801A6B80--;
        AISetStreamVolLeft(base[0xB8C + lbl_801A6B80]);
        AISetStreamVolRight(base[0xB8C + lbl_801A6B80]);
    }
}

