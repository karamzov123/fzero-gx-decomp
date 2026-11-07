/* Non-matching: best partial attempt (97.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct {
u8 pad_0[0x19];
u8 unk_19;
} Obj_1_bss_8B3A0_AtA4;
typedef struct {
s16 unk_0;
u8 pad_2[0x2];
s16 unk_4;
u8 pad_6[0x2];
s16 unk_8;
u8 pad_A[0x4];
s16 unk_E;
u8 pad_10[0x4];
u8 unk_14;
u8 pad_15[0x19];
s16 unk_2E;
u8 pad_30[0x5C];
s16 unk_8C;
u8 pad_8E[0x2];
s16 unk_90;
s16 unk_92;
u32 unk_94;
u8 pad_98[0x6];
u8 unk_9E;
u8 unk_9F;
u8 pad_A0[0x4];
Obj_1_bss_8B3A0_AtA4 *unk_A4;
u8 pad_A8[0x8];
s16 unk_B0;
s16 unk_B2;
u8 pad_B4[0xC];
s16 unk_C0;
s16 unk_C2;
u8 pad_C4[0xC];
s16 unk_D0;
s16 unk_D2;
u8 pad_D4[0xC];
u32 unk_E0;
u32 unk_E4;
u32 unk_E8;
u32 unk_EC;
u32 unk_F0;
u32 unk_F4;
u32 unk_F8;
u32 unk_FC;
u32 unk_100;
u32 unk_104;
u32 unk_108;
u32 unk_10C;
u32 unk_110;
u32 unk_114;
u32 unk_118;
u32 unk_11C;
u32 unk_120;
u32 unk_124;
u8 unk_128;
u8 unk_129;
u8 pad_12A[0x2];
s16 unk_12C;
s16 unk_12E;
s16 unk_130;
s16 unk_132;
s16 unk_134;
s16 unk_136;
s16 unk_138;
s16 unk_13A;
s16 unk_13C;
u8 pad_13E[0x2];
u32 unk_140;
u8 pad_144[0x2];
s16 unk_146;
s16 unk_148;
u8 pad_14A[0x2];
} Obj_1_bss_8B3A0;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;


extern u8 lbl_10_data_2B4[0x1A0];


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


typedef struct fn_10_AB98_SelCursor {
u8 pad_0[0x8C];
s16 unk_8C;
s16 unk_8E;
s16 unk_90;
u8 pad_92[2];
u32 unk_94;
} fn_10_AB98_SelCursor;


extern void fn_10_C594(void);


extern void fn_10_AE14(fn_10_AB98_SelCursor *cursor);


extern void fn_1_7B2E8(u32);


extern s16 fn_1_12EF24(s16 row, s16 column);
extern s32 fn_1_F89E4(u8);


struct fn_10_AB98_SelState {
s16 value;
};
static inline s16 sel_sign(s16 x) {
return x < 0 ? -1 : (x > 0);
}
static inline void sel_move_cursor(fn_10_AB98_SelCursor *cursor, s32 step, s16 opos) {
s8 i;
s32 blocked;
s32 pos;
s32 next;
struct { s16 value; } count;
s16 dir;
s32 tmp_ra6;
if (cursor->unk_8C == 0) {
s16 st = step;
pos = opos;
pos = pos < 0 ? 0 : (pos > 110 ? 110 : pos);
if ((cursor->unk_94 & 2) != 0 && st == 0 && (s8)lbl_10_data_2B4[pos] == 0) {
st = 1;
}
count.value = __abs(st);
dir = sel_sign(st);
while (count.value-- > 0) {
next = pos + dir;
pos = next > 110 ? 0 : (next < 0 ? 110 : next);
if ((cursor->unk_94 & 2) != 0) {
while ((s8)lbl_10_data_2B4[pos] == 0) {
next = pos + dir;
pos = next > 110 ? 0 : (next < 0 ? 110 : next);
}
}
}
cursor->unk_8E = pos;
cursor->unk_90 = cursor->unk_8E;
} else {
i = 0;
do {
blocked = 0;
next = cursor->unk_8E + step;
cursor->unk_8E = next > 5 ? blocked : (next < 0 ? 5 : next);
cursor->unk_90 = fn_1_12EF24(cursor->unk_8C, cursor->unk_8E);
if (cursor->unk_90 == -1 && step == 0) {
step = 1;
}
if (cursor->unk_8C == 5) {
tmp_ra6 = cursor->unk_8E;
if ((tmp_ra6 == 5 && fn_1_F89E4(0) == 0) ||
(cursor->unk_8E != 5 && fn_1_F89E4(cursor->unk_8E + 1) == 0)) {
blocked = 1;
if (step == 0) {
step = blocked;
}
}
}
i++;
if (cursor->unk_90 != -1 && (s8)lbl_10_data_2B4[cursor->unk_90] != 0 && blocked == 0) {
break;
}
} while (i < 6);
}
}
typedef struct fn_10_AE14_Pad {
    u8 pad_0[0x10];
    u16 unk_10;
    u16 unk_12;
} fn_10_AE14_Pad;

typedef struct fn_10_AE14_Player {
    u8 pad_0[0xA];
    s8 unk_A;
    u8 pad_B[1];
} fn_10_AE14_Player;

extern fn_10_AE14_Player lbl_1_bss_9C8[];
extern fn_10_AE14_Pad lbl_1_bss_9F8[];
extern void fn_1_12F128(s16 index);

typedef struct fn_10_AE14_State {
    s16 unk_0;
    u8 pad_2[0x9A];
    s16 unk_9C;
} fn_10_AE14_State;

typedef struct fn_10_AE14_D58 {
    u16 unk_0;
    u16 unk_2;
} fn_10_AE14_D58;

extern fn_10_AE14_D58 lbl_1_bss_D58;
extern void fn_1_A2D84(u32);
extern void fn_1_12F358(s16);

#pragma opt_common_subs off
static inline s16 fn_10_AE14_loop1(fn_10_AE14_Pad *pads, fn_10_AE14_Player *players) {
    s16 d;
    s16 i;
        d = 0;
        for (i = 0; i < 4; i++) {
            if (players[i].unk_A == -1) {
                continue;
            }
            if (!__rlwnm(*(u32 *)((u8 *)&lbl_1_bss_8B3A0 + 0x98), (i + 1) & 31, 31, 31)) {
                continue;
            }
            if ((pads[i].unk_12 >> 8) & 1) {
                d--;
            }
            if ((pads[i].unk_12 >> 9) & 1) {
                d++;
            }
            if ((pads[i].unk_12 >> 9) & 1) {
                fn_1_12F128(i);
            } else if ((pads[i].unk_12 >> 8) & 1) {
                fn_1_12F128(i);
            }
        }
    return d;
}

void fn_10_AE14(fn_10_AB98_SelCursor *cursor) {
    s16 i;
    s16 old;
    struct { fn_10_AE14_Player *value; } players;
    s16 d;
    struct { fn_10_AE14_Pad *value; } pads;
    s32 step;

    players.value = lbl_1_bss_9C8;
    pads.value = lbl_1_bss_9F8;
    step = 0;
    for (i = 0; i < 4; i++) {
        if (players.value[i].unk_A == -1) {
            continue;
        }
        if (!__rlwnm(*(u32 *)((u8 *)&lbl_1_bss_8B3A0 + 0x98), (i + 1) & 31, 31, 31)) {
            continue;
        }
        if ((pads.value[i].unk_10 & 1) || (pads.value[i].unk_12 & 1)) {
            step--;
        }
        if (((pads.value[i].unk_10 >> 1) & 1) || ((pads.value[i].unk_12 >> 1) & 1)) {
            step++;
        }
        if (((pads.value[i].unk_10 >> 1) & 1) || ((pads.value[i].unk_12 >> 1) & 1)) {
            fn_1_12F128(i);
        } else if ((pads.value[i].unk_10 & 1) || (pads.value[i].unk_12 & 1)) {
            fn_1_12F128(i);
        }
    }
    if (((fn_10_AE14_State *)&lbl_1_bss_8B3A0)->unk_0 == 1) {
        step = 0;
    }
    old = cursor->unk_90;
    sel_move_cursor(cursor, step, old);
    if (old != cursor->unk_90) {
        fn_1_A2D84(0xA9010000);
    }
    fn_1_12F358(cursor->unk_90);
    if (((fn_10_AE14_State *)&lbl_1_bss_8B3A0)->unk_0 == 10) {
        d = fn_10_AE14_loop1(pads.value, players.value);
        if (d != 0) {
            s32 v = ((fn_10_AE14_State *)&lbl_1_bss_8B3A0)->unk_9C + d;
            ((fn_10_AE14_State *)&lbl_1_bss_8B3A0)->unk_9C = v > 3 ? 0 : (v < 0 ? 3 : v);
            fn_1_A2D84(0xA9010000);
        }
        if (((fn_10_AE14_State *)&lbl_1_bss_8B3A0)->unk_9C == 3 && ((lbl_1_bss_D58.unk_2 >> 8) & 1)) {
            ((fn_10_AE14_State *)&lbl_1_bss_8B3A0)->unk_9C = 5;
        }
        if (((fn_10_AE14_State *)&lbl_1_bss_8B3A0)->unk_9C == 5 && !((lbl_1_bss_D58.unk_2 >> 8) & 1)) {
            ((fn_10_AE14_State *)&lbl_1_bss_8B3A0)->unk_9C = 3;
        }
    }
    if (step != 0 && (cursor->unk_94 & 0x80000000) == 0) {
        fn_1_7B2E8(cursor->unk_90);
    }
}
#pragma opt_common_subs reset
