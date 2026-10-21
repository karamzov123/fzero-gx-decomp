


typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


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


struct Sig_fn_80020CB0_fn_80020CB0_object {
struct Sig_fn_80020CB0_fn_80020CB0_object *next;
struct Sig_fn_80020CB0_fn_80020CB0_object *prev;
u8 pad_8[4];
u32 index;
};
extern void fn_80020CB0(struct Sig_fn_80020CB0_fn_80020CB0_object *, u32);
typedef struct Fn8005FBDCRecord {
u8 pad_0[0x12];
s16 unk_12;
} Fn8005FBDCRecord;
typedef struct Fn8005FBDCEntry {
u8 state;
u8 active;
u8 pad_2[6];
u8 count;
u8 pad_9[5];
u16 duration;
s32 step;
u8 pad_14[8];
Fn8005FBDCRecord *record;
u8 pad_20[0xc];
struct Sig_fn_80020CB0_fn_80020CB0_object *object;
u8 pad_30[0x84];
s32 velocity;
s32 target;
u8 pad_bc[0x5c];
} Fn8005FBDCEntry;
void fn_8005FBDC(u32 index) {
if ((((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .state != 0xff) {
(((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .active = 2;
if ((((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .state == 3) {
(((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .step = -960 / (((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .duration;
if ((((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .step == 0) {
(((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .step = -1;
}
} else {
s16 value = (((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .record->unk_12;
if (value != 0) {
(((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .velocity = value << 16;
} else {
(((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .velocity = -960 << 16;
}
(((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .target = -960 << 16;
(((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .duration = 2;
}
{
Fn8005FBDCEntry *entry = &(((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) ;
struct { u32 value; } count;
count.value = entry->count;
if (count.value >= 2 && !(count.value & 0x80)) {
entry->count = count.value - 1;
fn_80020CB0((((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .object, (((Fn8005FBDCEntry *)lbl_801A6C80->unk_1408)[index]) .count);
}
}
}
}
