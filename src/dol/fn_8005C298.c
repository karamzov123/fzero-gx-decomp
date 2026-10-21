
typedef signed char s8;


typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef double f64;


typedef struct {
u8 unk_0[0x10][0x10];
u8 pad_100[0x344];
u32 unk_444;
u8 pad_448[0x44];
u8 unk_48C[0xF][0x10];
u8 pad_57C[0xC];
u8 unk_588[0x40][0x20];
u8 unk_D88[0x10][0x10][0x4];
u8 pad_1188[0x280];
u8 unk_1408[0x40][0x118];
u8 pad_5A08[0x114];
u32 unk_5B1C;
u8 pad_5B20[0x8];
} Obj_801A6C80_Target;
extern Obj_801A6C80_Target *lbl_801A6C80;


typedef struct {
u8 pad00[0x13];
u8 unk13;
u8 pad14[0x8];
u32 unk1C;
} Fn8005C298Slot;
typedef struct {
u8 pad00[0x28];
u16 unk28;
u16 unk2A;
} Fn8005C298Param;
typedef struct {
u8 pad00[0xd];
s8 unkD;
u8 pad0E;
s8 unkF;
} Fn8005C298Input;
typedef struct {
u8 pad00[0x2];
u8 slot;
u8 pad03[0x11];
s32 unk14;
u8 pad18[0x4];
Fn8005C298Param *param;
Fn8005C298Input *input;
u8 pad24[0x60];
s32 unk84;
u8 pad88[0x60];
s32 unkE8;
u8 padEC[0x28];
s32 unk114;
} Fn8005C298Entry;
void fn_8005C298(s32 id, u8 mode) {
Fn8005C298Param *param;
s8 v;
s32 t;
u8 s;
Fn8005C298Slot *slot;
Obj_801A6C80_Target *state;
struct { Fn8005C298Input *ptr; } in;
state = lbl_801A6C80 ;
slot = (&((Fn8005C298Slot *)(state)->unk_588)[(u8)((&((Fn8005C298Entry *)(state)->unk_1408)[id])->slot)]) ;
if (slot->unk1C == 0) {
return;
}
in.ptr = (&((Fn8005C298Entry *)(state)->unk_1408)[id]) ->input;
param = (&((Fn8005C298Entry *)(state)->unk_1408)[id]) ->param;
if (mode != 1) {
return;
}
v = in.ptr->unkD;
if (v > 0) {
t = (v + 1) * 1200;
t >>= 7;
t *= slot->unk13;
t >>= 7;
t += param->unk28;
if (t > 1200) {
t = 1200;
}
} else if (v < 0) {
t = (s32)__fabs((f64)v);
t *= 1200;
t >>= 7;
t *= slot->unk13;
t >>= 7;
t = param->unk28 - t;
if (t < 0) {
t = 0;
}
} else {
t = param->unk28;
}
(&((Fn8005C298Entry *)(lbl_801A6C80)->unk_1408)[id]) ->unkE8 = t << 16;
state = lbl_801A6C80 ;
s = (&((Fn8005C298Entry *)(state)->unk_1408)[id]) ->slot;
v = in.ptr->unkF;
if (v > 0) {
t = (v + 1) * 120;
t >>= 7;
t *= (&((Fn8005C298Slot *)(state)->unk_588)[(u8)(s)]) ->unk13;
t >>= 7;
t = param->unk2A + t;
if (t > 120) {
t = 120;
}
} else if (v < 0) {
t = (s32)__fabs((f64)v);
t *= 120;
t >>= 7;
t *= (&((Fn8005C298Slot *)(state)->unk_588)[(u8)(s)]) ->unk13;
t >>= 7;
t = param->unk2A - t;
if (t < 0) {
t = 0;
}
} else {
t = param->unk2A;
}
(&((Fn8005C298Entry *)(lbl_801A6C80)->unk_1408)[id]) ->unk114 = t << 16;
(&((Fn8005C298Entry *)(lbl_801A6C80)->unk_1408)[id]) ->unk84 = ((&((Fn8005C298Entry *)(lbl_801A6C80)->unk_1408)[id]) ->unk14 - t) << 16;
}
