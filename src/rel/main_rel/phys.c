#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/phys.h"

extern void lbl_8006DCA4(void *base, void *arg);
extern void fn_1_A71AC(void);
extern void fn_8006F828(void *base, f32 *out);
extern void fn_1_E4A38(void *base, s32 x, s32 y, void *arg);
extern void fn_80008BEC(void *dst, void *value, u32 size);
extern void fn_80008BA8(void *dst, void *value, u32 size);
extern f32 lbl_1_rodata_67A8;
extern u32 lbl_1_rodata_6A8C[3];
extern u32 strstr(const u8* left, const char* right);
extern u32 strlen(const char* string);
extern void fn_1_8CED0(void* object, s32 value0, s32 value1);
extern void fn_1_8D0A4(void* object);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80072EDC(u32, s32);
extern void fn_800745A4(u32, s32, s32, u32, s32, s32);
extern void fn_80073778(void *, u32);
extern void fn_80015C1C(void *, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void lbl_8006DFFC(void *, void *, void *);
extern void GXLoadTexMtxImm(void *, u32, s32);
extern f32 lbl_1_rodata_6780[236];
extern f32 fn_1_A6FE8(void);
extern void fn_1_E8938(void);
extern void fn_1_8D1C8(void *object, void (*callback)(void), int arg);
extern u32 fn_1_3F8C0(void);
extern u32 fn_80008E84(u32 value);
extern u32 lbl_1_bss_7C94C[67];
extern void fn_1_EE530(void);
extern u8 lbl_1_bss_7ECB4[72];
extern void fn_1_BC29C(u8 *);
extern void fn_1_B9C0C(void);
extern void fn_1_1596DC(s32);
extern void fn_1_484CC(s32);

extern void fn_80008BEC(void *dst, void *value, u32 size);
extern void fn_80008BA8(void *dst, void *value, u32 size);

extern f32 lbl_1_rodata_67A8;
extern u32 lbl_1_rodata_6A8C[3];
extern void fn_80008BA8(void *dst, void *value, u32 size);
extern void fn_1_12EF80(s16 arg, s16 *out_group, s16 *out_entry);
extern void fn_1_9C724(void);
extern void fn_1_DD890(void *);
extern void fn_1_9CC40(void);

/* fzgx:begin fn_1_E1C10 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

typedef struct {
    u8 pad_0[0x8];
    s16 unk_8;
    s16 unk_A;
    u8 pad_C[0x19C];
} Elem1A8;

typedef struct {
    u32 unk_0;
    s16 unk_4;
    u8 pad_6[0x2];
    u32 unk_8;
    s16 unk_C;
    u8 pad_E[0x2];
    u32 unk_10;
    s16 unk_14;
    u8 pad_16[0x2];
    u32 unk_18;
    s16 unk_1C;
    u8 pad_1E[0x2];
    u32 unk_20;
    s16 unk_24;
    u8 pad_26[0x2];
    u32 unk_28;
    s16 unk_2C;
    u8 pad_2E[0x2];
} State7AE88;

extern State7AE88 lbl_1_bss_7AE88;
extern u32 fn_1_4630(u32, u32, u8 *, u32);
extern u32 lbl_801A6410;
extern u8 lbl_1_data_3DDB4[];

void fn_1_E1C10(void) {
    s16 fzgx_value_;
    s16 kind;
    struct { s16 value; } i;
    s16 count;
    struct { Elem1A8 * value; } cursor;
    Elem1A8 *ptr;
    State7AE88 *base;
    s16 *fzgx_value;

    base = &lbl_1_bss_7AE88;

    count = base->unk_4;
    ptr = (Elem1A8 *)base->unk_0;
    if ((count != 0) && (ptr == 0)) {
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (count * 0x1A8),
                                   lbl_1_data_3DDB4, 0x7b7);
        cursor.value = ptr;
        i.value = 0;
        kind = 0;
        while (i.value < count) {
            cursor.value->unk_A = kind;
            cursor.value->unk_8 = i.value;
            i.value++;
            cursor.value++;
        }
    }
    base->unk_0 = (u32)ptr;

    count = base->unk_C;
    ptr = (Elem1A8 *)base->unk_8;
    if ((count != 0) && (ptr == 0)) {
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (count * 0x1A8),
                                   lbl_1_data_3DDB4, 0x7b7);
        cursor.value = ptr;
        i.value = 0;
        kind = 1;
        while (i.value < count) {
            cursor.value->unk_A = kind;
            fzgx_value_ = i.value;
            cursor.value->unk_8 = fzgx_value_;
            i.value++;
            cursor.value++;
        }
    }
    base->unk_8 = (u32)ptr;

    count = base->unk_14;
    ptr = (Elem1A8 *)base->unk_10;
    if ((count != 0) && (ptr == 0)) {
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (count * 0x1A8),
                                   lbl_1_data_3DDB4, 0x7b7);
        cursor.value = ptr;
        i.value = 0;
        kind = 2;
        while (i.value < count) {
            cursor.value->unk_A = kind;
            cursor.value->unk_8 = i.value;
            i.value++;
            cursor.value++;
        }
    }
    base->unk_10 = (u32)ptr;

    count = base->unk_1C;
    ptr = (Elem1A8 *)base->unk_18;
    if ((count != 0) && (ptr == 0)) {
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (count * 0x1A8),
                                   lbl_1_data_3DDB4, 0x7b7);
        cursor.value = ptr;
        i.value = 0;
        kind = 3;
        while (i.value < count) {
            fzgx_value = &(cursor.value->unk_A);
            *fzgx_value = kind;
            cursor.value->unk_8 = i.value;
            i.value++;
            cursor.value++;
        }
    }
    base->unk_18 = (u32)ptr;

    count = base->unk_24;
    ptr = (Elem1A8 *)base->unk_20;
    if ((count != 0) && (ptr == 0)) {
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (count * 0x1A8),
                                   lbl_1_data_3DDB4, 0x7b7);
        cursor.value = ptr;
        i.value = 0;
        kind = 4;
        while (i.value < count) {
            cursor.value->unk_A = kind;
            cursor.value->unk_8 = i.value;
            i.value++;
            cursor.value++;
        }
    }
    base->unk_20 = (u32)ptr;

    count = base->unk_2C;
    ptr = (Elem1A8 *)base->unk_28;
    if ((count != 0) && (ptr == 0)) {
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (count * 0x1A8),
                                   lbl_1_data_3DDB4, 0x7b7);
        cursor.value = ptr;
        i.value = 0;
        kind = 5;
        while (i.value < count) {
            cursor.value->unk_A = kind;
            cursor.value->unk_8 = i.value;
            i.value++;
            cursor.value++;
        }
    }
    base->unk_28 = (u32)ptr;
}
/* fzgx:end fn_1_E1C10 */

/* fzgx:begin fn_1_E1E9C noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef float f32;


typedef unsigned long size_t;


typedef struct {
u32 unk_0;
u32 unk_4;
u32 unk_8;
u32 unk_C;
u32 unk_10;
u32 unk_14;
u32 unk_18;
u32 unk_1C;
u32 unk_20;
u32 unk_24;
u32 unk_28;
u32 unk_2C;
u32 unk_30;
u32 unk_34;
u8 unk_38;
u8 unk_39;
u8 unk_3A;
u8 unk_3B;
u32 unk_3C;
u32 unk_40;
u32 unk_44;
u32 unk_48;
u32 unk_4C;
u32 unk_50;
u32 unk_54;
u16 unk_58;
u16 unk_5A;
u8 unk_5C;
u8 unk_5D;
u8 unk_5E;
u8 pad_5F[0x1];
u32 unk_60;
u8 pad_64[0x10];
u32 unk_74;
u8 pad_78[0xC];
u32 unk_84;
u32 unk_88;
u8 pad_8C[0x4];
u32 unk_90;
u8 pad_94[0x18];
u32 unk_AC;
u32 unk_B0;
u32 unk_B4;
u32 unk_B8;
u32 unk_BC;
u32 unk_C0;
u32 unk_C4;
u32 unk_C8;
u32 unk_CC;
u32 unk_D0;
u32 unk_D4;
u32 unk_D8;
u32 unk_DC;
u32 unk_E0;
u32 unk_E4;
u32 unk_E8;
u32 unk_EC;
u32 unk_F0;
u32 unk_F4;
u32 unk_F8;
u8 pad_FC[0x8];
u32 unk_104;
u8 pad_108[0xC];
u32 unk_114;
u32 unk_118;
u32 unk_11C;
u32 unk_120;
u32 unk_124;
u8 pad_128[0x24];
u32 unk_14C;
u32 unk_150;
u32 unk_154;
u32 unk_158;
u32 unk_15C;
u32 unk_160;
u32 unk_164;
u32 unk_168;
u32 unk_16C;
u32 unk_170;
u32 unk_174;
u32 unk_178;
u32 unk_17C;
u32 unk_180;
u32 unk_184;
u32 unk_188;
u32 unk_18C;
u32 unk_190;
u32 unk_194;
u32 unk_198;
u8 pad_19C[0x50];
u32 unk_1EC;
u32 unk_1F0;
u32 unk_1F4;
u32 unk_1F8;
u32 unk_1FC;
u32 unk_200;
u32 unk_204;
u32 unk_208;
u32 unk_20C;
u32 unk_210;
u32 unk_214;
u32 unk_218;
u32 unk_21C;
u32 unk_220;
u32 unk_224;
u32 unk_228;
u32 unk_22C;
u32 unk_230;
u32 unk_234;
u32 unk_238;
u8 pad_23C[0xC8];
f32 unk_304;
u8 pad_308[0xFC];
f32 unk_404;
u8 pad_408[0x1C];
u32 unk_424;
u32 unk_428;
u32 unk_42C;
f32 unk_430;
u8 pad_434[0x28C];
f32 unk_6C0;
u8 pad_6C4[0x8];
u32 unk_6CC;
u32 unk_6D0;
u32 unk_6D4;
u32 unk_6D8;
u8 pad_6DC[0x4];
u32 unk_6E0;
u8 pad_6E4[0x2BC];
u32 unk_9A0;
u32 unk_9A4;
u32 unk_9A8;
u32 unk_9AC;
u32 unk_9B0;
u32 unk_9B4;
u32 unk_9B8;
u32 unk_9BC;
u8 pad_9C0[0x130];
f32 unk_AF0;
u8 pad_AF4[0xE0];
u32 unk_BD4;
u32 unk_BD8;
u8 pad_BDC[0x528];
u32 unk_1104;
u32 unk_1108;
u8 pad_110C[0x4];
u32 unk_1110;
u8 pad_1114[0x470];
u32 unk_1584;
u32 unk_1588;
u8 pad_158C[0x320];
u32 unk_18AC;
u8 pad_18B0[0x3A8];
u32 unk_1C58;
u32 unk_1C5C;
u8 pad_1C60[0x5FC];
u32 unk_225C;
u32 unk_2260;
u8 pad_2264[0x4C0];
u32 unk_2724;
} Obj_1_data_2A7E0_At3C;
typedef struct {
s16 unk_0;
u8 unk_2;
u8 pad_3[0x11];
u32 unk_14;
u8 pad_18[0x4];
f32 unk_1C;
u8 pad_20[0xC];
u32 unk_2C;
u8 pad_30[0x4];
u32 unk_34;
u32 unk_38;
Obj_1_data_2A7E0_At3C *unk_3C;
u8 pad_40[0x8];
u32 unk_48;
u32 unk_4C;
u32 unk_50;
u32 unk_54;
u32 unk_58;
u32 unk_5C;
u32 unk_60;
u32 unk_64;
u32 unk_68;
u32 unk_6C;
u8 unk_70;
u8 pad_71[0x3];
u32 unk_74;
u32 unk_78;
u32 unk_7C;
u32 unk_80;
u8 pad_84[0x4];
u32 unk_88;
u32 unk_8C;
u8 pad_90[0xC];
f32 unk_9C;
u16 unk_A0;
u8 pad_A2[0x56];
} Obj_1_data_2A7E0;
extern Obj_1_data_2A7E0 lbl_1_data_2A7E0;


typedef struct {
u32 unk_0;
f32 unk_4;
u32 unk_8;
u32 unk_C;
u8 pad_10[0x4];
u32 unk_14;
u32 unk_18;
u32 unk_1C;
u8 pad_20[0x4];
u32 unk_24;
u8 pad_28[0x4];
u32 unk_2C;
u8 pad_30[0xC];
u32 unk_3C;
u8 pad_40[0x4];
u32 unk_44;
u32 unk_48;
u32 unk_4C;
u32 unk_50;
u32 unk_54;
u8 pad_58[0x4];
u32 unk_5C;
u32 unk_60;
u32 unk_64;
u32 unk_68;
u32 unk_6C;
u32 unk_70;
u32 unk_74;
u32 unk_78;
u8 pad_7C[0x1];
u8 unk_7D;
u8 pad_7E[0x2];
u32 unk_80;
u32 unk_84;
u32 unk_88;
u32 unk_8C;
u32 unk_90;
u32 unk_94;
u32 unk_98;
u32 unk_9C;
u32 unk_A0;
u32 unk_A4;
u32 unk_A8;
u32 unk_AC;
u32 unk_B0;
u32 unk_B4;
u32 unk_B8;
u32 unk_BC;
f32 unk_C0;
f32 unk_C4;
f32 unk_C8;
f32 unk_CC;
u32 unk_D0;
u32 unk_D4;
} Obj_1_bss_3BE0_Target;
extern Obj_1_bss_3BE0_Target *lbl_1_bss_3BE0;


extern u32 lbl_1_data_3DC98;


extern s16 fn_1_7B054(void);
extern u8 lbl_1_data_2B0D4[112];
extern u32 lbl_1_bss_85288[2];
extern char *strcpy(char *dst, const char *src);
extern size_t strlen(const char *str);
extern s32 fn_8006FC5C(void *, void *, size_t);


typedef struct {
u32 flags;
void *name;
} PhysEntryInfo;
typedef struct {
u32 flags;
u8 pad_4[0x4];
PhysEntryInfo *info;
} fn_1_E1E9C_PhysEntry;
typedef struct {
u8 pad_0[0xA];
s16 kind;
u8 pad_C[0x2];
s16 index;
s16 slots[4];
u8 pad_18[0x120];
u64 flags;
} fn_1_E1E9C_PhysObj;
void fn_1_E1E9C(fn_1_E1E9C_PhysObj *obj) {
char buf[0x20];
const char * strtab;
s16 result;
Obj_1_data_2A7E0_At3C *state;
s32 i;
fn_1_E1E9C_PhysEntry *entry;
s16 j;
state = lbl_1_data_2A7E0.unk_3C;
strtab = (const char *)&lbl_1_data_3DC98;
if ((obj->flags & 0x2000000ULL) != 0) {
switch (lbl_1_data_2B0D4[fn_1_7B054()]) {
case 1:
switch (obj->kind) {
case 1:
result = state->unk_0;
break;
default:
result = -1;
break;
}
break;
case 13:
switch (obj->kind) {
case 4:
result = state->unk_0;
break;
default:
result = -1;
break;
}
break;
case 6:
switch (obj->kind) {
case 5:
result = (s16)*(u32 *)((u8 *)state + 0xFD64);
break;
default:
result = -1;
break;
}
break;
default:
result = -1;
break;
}
if (result == -1) {
switch (obj->kind) {
case 1:
result = lbl_1_bss_85288[0];
break;
case 5:
result = lbl_1_bss_85288[1];
break;
default:
result = -1;
break;
}
}
if (result == -1) {
obj->slots[0] = -1;
obj->slots[1] = -1;
obj->slots[2] = -1;
obj->slots[3] = -1;
switch (obj->kind) {
case 5:
strcpy(buf, strtab + 0x124);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { result = i; break; } } ;
strcpy(buf, strtab + 0x134);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { obj->slots[0] = i; break; } } ;
strcpy(buf, strtab + 0x14C);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { obj->slots[1] = i; break; } } ;
strcpy(buf, strtab + 0x164);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { obj->slots[2] = i; break; } } ;
break;
case 1:
strcpy(buf, strtab + 0x17C);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { result = i; break; } } ;
strcpy(buf, strtab + 0x180);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { obj->slots[0] = i; break; } } ;
strcpy(buf, strtab + 0x18C);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { obj->slots[1] = i; break; } } ;
strcpy(buf, strtab + 0x198);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { obj->slots[2] = i; break; } } ;
break;
case 4:
strcpy(buf, strtab + 0x20);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { result = i; break; } } ;
break;
}
}
if (result == -1) {
obj->flags &= ~0x2000000ULL;
} else {
obj->index = result;
entry = (fn_1_E1E9C_PhysEntry *)(lbl_1_bss_3BE0->unk_54 + (obj->index << 6));
switch (obj->kind) {
case 4:
entry->info->flags |= 0x20;
break;
}
entry->flags |= 0x80000000;
for (j = 0; j < 4; j++) {
if (obj->slots[j] != -1) {
*(u32 *)(lbl_1_bss_3BE0->unk_54 + (obj->slots[j] << 6)) |= 0x80000000;
}
}
}
}
}
/* fzgx:end fn_1_E1E9C */

/* fzgx:begin fn_1_E252C */
#include "psvec.h"

#pragma force_active on
static const u32 fzgx_pool_table_0[10] = {0xbf800000, 0x3f7ffffe, 0x3f800001, 0xbf800001, 0xbf7ffffe, 0x0, 0x3e800000, 0x0, 0x0, 0x40a00000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_0(s32 value) {
    volatile f32 f; /* Intentional volatile: retain shared retail pool literals. */
    f64 d;
    f = 1.0000000000000000f;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_table_2C[1] = {0xff00ff};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_1(s32 value) {
    volatile f32 f; /* Intentional volatile: retain shared retail pool literals. */
    volatile f64 d; /* Intentional volatile: retain shared retail pool literals. */
    f = 0.10000000149011612f;
    f = 0.50000000000000000f;
    f = 10.000000000000000f;
    f = 182.04444885253906f;
    d = 4503599627370496.0;
    f = -0.0027222223579883575f;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_table_4C[9] = {0x0, 0x3f800000, 0x0, 0x0, 0x3f800000, 0x0, 0x3f800000, 0x0, 0x0};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_2(s32 value) {
    volatile f32 f; /* Intentional volatile: retain shared retail pool literals. */
    f64 d;
    f = 0.000095873801910784096f;
    f = 1.5000000000000000f;
    f = -1.1920928955078125e-7f;
    f = 1.1920928955078125e-7f;
    f = value;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_3(s32 value) {
    volatile f32 f; /* Intentional volatile: retain shared retail pool literals. */
    f64 d;
    f = 60.000000000000000f;
    f = 1000000.0000000000f;
    f = 250000.00000000000f;
    f = 20.000000000000000f;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_table_98[6] = {0x0, 0x3f800000, 0x0, 0x0, 0x3f800000, 0x0};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_4(s32 value) {
    volatile f32 f; /* Intentional volatile: retain shared retail pool literals. */
    f64 d;
    f = -0.0099999997764825821f;
    f = 0.0099999997764825821f;
    f = -1.0099999904632568f;
    f = 0.000099999997473787516f;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_table_C0[3] = {0x0, 0x3f800000, 0x0};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_5(s32 value) {
    volatile f32 f; /* Intentional volatile: retain shared retail pool literals. */
    volatile f64 d; /* Intentional volatile: retain shared retail pool literals. */
    f = 0.99000000953674316f;
    f = 2.0000000000000000f;
    f = -0.0f;
    d = 216.00000000000000;
    d = 3.1415927410125732;
    d = 4.0000000000000000;
    d = 60.000000000000000;
    f = 1.0099999904632568f;
    f = 0.050000000745058060f;
    f = 1.0010000467300415f;
    f = 0.89999997615814209f;
    f = 3.0000000000000000f;
}
#pragma section code_type ".text"
#pragma force_active off
typedef struct {
    u8 pad_0[0xA];
    s16 kind;
    u8 pad_C[0x2];
    s16 index;
    s16 slots[4];
    u8 pad_18[0x120];
    u64 flags;
} Sig_fn_1_E1E9C_fn_1_E1E9C_PhysObj;
typedef struct Sig_fn_1_E86FC_StringValueEntry {
    u32 value;
    const u8* string;
} Sig_fn_1_E86FC_StringValueEntry;
typedef struct Sig_fn_1_E86FC_StringValueTable {
    s32 count;
    u32 unused;
    Sig_fn_1_E86FC_StringValueEntry* entries;
} Sig_fn_1_E86FC_StringValueTable;

struct fn_1_E252C_lbl_1_rodata_6780 {
    u8 pad_0[0x28];
    f32 unk_28;
    u8 pad_2C[0x4];
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    u8 pad_3C[0x44];
    f64 unk_80;
    u8 pad_88[0x48];
    f32 unk_D0;
    u8 pad_D4[0x30];
    f32 unk_104;
    u8 pad_108[0x4];
    u32 unk_10C;
    u32 unk_110;
    u32 unk_114;
    u32 unk_118;
    u32 unk_11C;
    u32 unk_120;
    f32 unk_124;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
    f32 unk_134;
    f32 unk_138;
    f32 unk_13C;
};
struct fn_1_E252C_lbl_1_bss_384B4 {
    u32 unk_0;
};
struct fn_1_E252C_lbl_801A63C0 {
    u32 unk_0;
};

extern Sig_fn_1_E86FC_StringValueTable * fn_1_7B064(void);
extern struct fn_1_E252C_lbl_1_bss_384B4 lbl_1_bss_384B4;
extern struct fn_1_E252C_lbl_801A63C0 lbl_801A63C0;
extern u32 fn_1_E86FC(Sig_fn_1_E86FC_StringValueTable *, const char *);
extern void fn_1_E1E9C(Sig_fn_1_E1E9C_fn_1_E1E9C_PhysObj *);

void fn_1_E252C(u32 arg0, u32 arg1, Sig_fn_1_E1E9C_fn_1_E1E9C_PhysObj * arg2) {
    const struct fn_1_E252C_lbl_1_rodata_6780 *p_lbl_1_rodata_6780;
    s16 v0;
    f32 unk_1;
    f32 v21;
    f32 v22;
    f32 v23;
    f32 v24;
    f32 v25;
    f32 v29;
    f32 v30;
    f32 v31;
    f32 v32;
    f32 v33;
    u32 v36;
    u32 v38;
    s32 v40;
    f32 v42;
    f32 v48;
    f32 v49;
    f32 v50;
    f32 v51;
    struct { u32 a[6]; } loc_8 = {{0x3FE00000, 0x40F00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40A00000}};
    /* frame */
    Sig_fn_1_E86FC_StringValueTable * t0;
    u32 t1;
    u32 t2;
    Sig_fn_1_E86FC_StringValueTable * t3;
    u32 t4;
    u32 t5;
    /* 2 instruction(s) not lifted: see the ??? markers */
    p_lbl_1_rodata_6780 = (struct fn_1_E252C_lbl_1_rodata_6780 *)&lbl_1_rodata_6780;
    v0 = arg0;
    unk_1 = ((f32 *)loc_8.a)[arg2->kind];
    *(f32 *)((u8 *)arg2 + 132) = unk_1;
    *(u32 *)((u8 *)arg2 + 320) = (1 << ((Sig_fn_1_E1E9C_fn_1_E1E9C_PhysObj *)(arg2))->kind);
    switch (v0) {
    case 0: {
    *(u16 *)((u8 *)arg2 + 12) = 0;
    *(f32 *)((u8 *)arg2 + 416) = *(f32 *)((u8 *)arg2 + 132);
    *(f32 *)((u8 *)arg2 + 420) = 2.0f * *(f32 *)((u8 *)arg2 + 132);
    *(f32 *)((u8 *)arg2 + 24) = 0.5f;
    *(f32 *)((u8 *)arg2 + 28) = 1.0f;
    *(f32 *)((u8 *)arg2 + 32) = 0.9f;
    *(f32 *)((u8 *)arg2 + 36) = 0.8f;
    *(f32 *)((u8 *)arg2 + 40) = 0.0016666667f;
    *(u32 *)((u8 *)arg2 + 0) = 0;
    arg2->flags |= 0x10000;
    arg2->flags |= 0x80000;
    arg2->flags |= 64;
    arg2->flags |= 0x20000000000ULL;
    arg2->flags |= 0x10000000000ULL;
    *(u32 *)((u8 *)arg2 + 188) = 600;
    *(u32 *)((u8 *)arg2 + 192) = -1;
    break; }
    case 1: {
    *(u16 *)((u8 *)arg2 + 12) = 0;
    *(f32 *)((u8 *)arg2 + 24) = 0.3f;
    *(f32 *)((u8 *)arg2 + 28) = 1.0f;
    *(f32 *)((u8 *)arg2 + 32) = 0.5f;
    *(f32 *)((u8 *)arg2 + 36) = 0.5f;
    *(f32 *)((u8 *)arg2 + 40) = 0.016666668f;
    *(u32 *)((u8 *)arg2 + 0) = 0;
    arg2->flags |= 1024;
    arg2->flags |= 8;
    arg2->flags |= 64;
    arg2->flags |= 32;
    arg2->flags |= 16777216;
    arg2->flags |= 33554432;
    arg2->flags |= 256;
    break; }
    case 2: {
    v21 = 0.1f;
    *(u16 *)((u8 *)arg2 + 12) = 0;
    v22 = 10000000.0f;
    *(f32 *)((u8 *)arg2 + 24) = v21;
    v23 = 0.9f;
    *(f32 *)((u8 *)arg2 + 28) = v22;
    v24 = 0.8f;
    *(f32 *)((u8 *)arg2 + 32) = v23;
    v25 = 0.0016666667f;
    *(f32 *)((u8 *)arg2 + 36) = v24;
    *(f32 *)((u8 *)arg2 + 40) = v25;
    t0 = (Sig_fn_1_E86FC_StringValueTable *)(fn_1_7B064());
    t1 = fn_1_E86FC((Sig_fn_1_E86FC_StringValueTable *)t0, (const char *)&lbl_1_data_3DE3C);
    *(u32 *)((u8 *)arg2 + 0) = t1;
    if (t1 == 0) {
    t2 = fn_1_E86FC((Sig_fn_1_E86FC_StringValueTable *)lbl_1_bss_384B4.unk_0, (const char *)&lbl_1_data_3DE3C);
    *(u32 *)((u8 *)arg2 + 0) = t2;
    if (t2 == 0) {
    *(u32 *)((u8 *)arg2 + 0) = 0;
    }
    }
    psvec_scale(((u8 *)arg2 + 244), 1.0f, ((u8 *)arg2 + 244));
    arg2->flags |= 0x10000;
    arg2->flags |= 512;
    arg2->flags |= 0x40000;
    arg2->flags |= 8;
    arg2->flags |= 64;
    arg2->flags |= 32;
    arg2->flags |= 8192;
    arg2->flags |= 16ULL << 32;
    arg2->flags |= 64ULL << 32;
    arg2->flags |= 128ULL << 32;
    arg2->flags |= 2048ULL << 32;
    arg2->flags |= 32ULL << 32;
    break; }
    case 3: {
    v29 = 0.1f;
    *(u16 *)((u8 *)arg2 + 12) = 0;
    v30 = 5000000.0f;
    *(f32 *)((u8 *)arg2 + 24) = v29;
    v31 = 0.9f;
    *(f32 *)((u8 *)arg2 + 28) = v30;
    v32 = 0.8f;
    *(f32 *)((u8 *)arg2 + 32) = v31;
    v33 = 0.0016666667f;
    *(f32 *)((u8 *)arg2 + 36) = v32;
    *(f32 *)((u8 *)arg2 + 40) = v33;
    t3 = (Sig_fn_1_E86FC_StringValueTable *)(fn_1_7B064());
    t4 = fn_1_E86FC((Sig_fn_1_E86FC_StringValueTable *)t3, (const char *)&lbl_1_data_3DE3C);
    *(u32 *)((u8 *)arg2 + 0) = t4;
    if (t4 == 0) {
    t5 = fn_1_E86FC((Sig_fn_1_E86FC_StringValueTable *)lbl_1_bss_384B4.unk_0, (const char *)&lbl_1_data_3DE3C);
    *(u32 *)((u8 *)arg2 + 0) = t5;
    if (t5 == 0) {
    *(u32 *)((u8 *)arg2 + 0) = 0;
    }
    }
    psvec_scale(((u8 *)arg2 + 244), 1.0f, ((u8 *)arg2 + 244));
    arg2->flags |= 65536;
    arg2->flags |= 512;
    arg2->flags |= 262144;
    arg2->flags |= 8;
    arg2->flags |= 64;
    arg2->flags |= 32;
    arg2->flags |= 8192;
    arg2->flags |= 16ULL << 32;
    arg2->flags |= 2048ULL << 32;
    break; }
    case 4: {
    *(u16 *)((u8 *)arg2 + 12) = 0;

    v36 = lbl_801A63C0.unk_0 * 0x676A4B6B + 13259;
    v38 = (v36 >> 16) & 0x7FFF;
    lbl_801A63C0.unk_0 = v36;
    v40 = (s32)v38 % 6;
    v42 = v40;
    *(f32 *)((u8 *)arg2 + 24) = 0.5f + v42 / 10.0f;
    *(f32 *)((u8 *)arg2 + 28) = 100.0f;
    *(f32 *)((u8 *)arg2 + 32) = 0.9f;
    *(f32 *)((u8 *)arg2 + 36) = 0.8f;
    *(f32 *)((u8 *)arg2 + 40) = 0.0016666667f;
    *(u32 *)((u8 *)arg2 + 0) = 0;
    arg2->flags |= 524288;
    arg2->flags |= 64;
    arg2->flags |= 32;
    arg2->flags |= 33554432;
    arg2->flags |= 67108864;
    arg2->flags |= 2ULL << 32;
    break; }
    case 5: {
    v48 = 0.3f;
    *(u16 *)((u8 *)arg2 + 12) = 0;
    v49 = 1.0f;
    *(f32 *)((u8 *)arg2 + 24) = v48;
    v50 = 0.5f;
    *(f32 *)((u8 *)arg2 + 28) = v49;
    v51 = 0.016666668f;
    *(f32 *)((u8 *)arg2 + 32) = v50;
    *(f32 *)((u8 *)arg2 + 36) = v50;
    *(f32 *)((u8 *)arg2 + 40) = v51;
    *(u32 *)((u8 *)arg2 + 0) = 0;
    arg2->flags |= 1024;
    arg2->flags |= 8;
    arg2->flags |= 64;
    arg2->flags |= 32;
    arg2->flags |= 33554432;
    arg2->flags |= 256;
    }
    }
    fn_1_E1E9C((Sig_fn_1_E1E9C_fn_1_E1E9C_PhysObj *)arg2);
}
/* fzgx:end fn_1_E252C */

/* fzgx:begin fn_1_E2AE8 */
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 pad_00[0x54];
    Vec3 v_54;
    Vec3 v_60;
    u8 pad_6c[0x18];
    f32 f_84;
    u8 pad_88[0x18];
    Vec3 v_a0;
    u32 u_ac;
    u32 u_b0;
    u32 u_b4;
    u32 u_b8;
    u8 pad_bc[0x44];
    s32 s_100;
    s32 s_104;
    s32 s_108;
    s32 s_10c;
    u8 pad_110[0xC];
    Vec3 v_11c;
    Vec3 v_128;
    u8 pad_134[4];
    u64 flags;
    u32 u_140;
    u8 pad_144[0x64];
} Obj;

typedef struct {
    s16 a[80];
} Arr80;

typedef struct {
    f32 f0;
    u8 pad_04[0x30];
    f32 f34;
    u8 pad_38[0x108];
    Vec3 pv;
    Arr80 pa;
} PoolType;

extern s16 fn_1_E5430(s16);
extern Obj *fn_1_E54A8(s16, s16);
extern u8 *fn_1_14F04(void);
extern u32 fn_1_20A5C(void *, void *);
extern void fn_1_17920(u32, f32, u32);
extern s16 fn_1_7B054(void);
extern f32 lbl_8006D668(void *);

static inline f32 fn_1_E2AE8_read_pointer(PoolType * owner) { return owner->f0; }
#pragma opt_dead_assignments off
static inline void fn_1_E2AE8_call_fn_1_17920(u32 a0, u32 a1, f32 a2) { fn_1_17920(a0, a2, a1); }
void fn_1_E2AE8(void) {
    PoolType *pool;
    s16 n;
    Obj *obj;
    Arr80 arr;
    s16 j;
    u8 *str;
    Obj *list;
    s16 i;
    Vec3 lv;
    s16 *p;
    s16 k;
    Vec3 vtmp;
    f32 ftmp;
    s32 a;
    s32 b;
    s32 c;

    pool = (PoolType *)&lbl_1_rodata_6780;
    for (i = 0; i < 6; i++) {
        n = fn_1_E5430(i);
        list = (Obj *)fn_1_E54A8(i, 0);
        str = fn_1_14F04() + 0x45c;
        obj = list;
        for (j = 0; j < n; ) {
            a = fn_1_20A5C(&obj->v_54.x, &ftmp);
            obj->s_100 = a;
            obj->u_ac = a;
            b = obj->u_ac;
            obj->u_b8 = b;
            obj->u_b4 = b;
            obj->u_b0 = b;
            c = obj->s_100;
            obj->s_10c = c;
            obj->s_108 = c;
            obj->s_104 = c;
            if ((obj->flags & 0x10000ULL) != 0) {
                fn_1_E2AE8_call_fn_1_17920(obj->s_100, 0, ftmp);
                fn_80008BA8(&obj->v_128.x, str, 12);
                lbl_8006D668(&obj->v_128.x);
                fn_80008BA8(&obj->v_a0.x, &obj->v_128.x, 12);
            }
            j++;
            obj = (Obj *)((u8 *)obj + 0x1a8);
        }
        if (i == 0 && fn_1_7B054() == 6) {
            lv = pool->pv;
            arr = pool->pa;
            obj = list;
            p = arr.a;
            for (k = 0; k < n; k++) {
                obj->s_100 = *p;
                c = obj->s_100;
                obj->s_10c = c;
                obj->s_108 = c;
                obj->s_104 = c;
                if (obj->s_100 > 0x50 && obj->s_100 < 0xc8) {
                    psvec_scale(&lv.x, fn_1_E2AE8_read_pointer(pool), &obj->v_128.x);
                    obj->u_140 = 1;
                } else {
                    fn_80008BA8(&obj->v_128.x, &lv.x, 12);
                    obj->u_140 = 2;
                }
                obj = (Obj *)((u8 *)obj + 0x1a8);
                p++;
            }
        }
        obj = list;
        for (j = 0; j < n; j++) {
            if ((obj->flags & 8ULL) == 0) {
                psvec_scale(&obj->v_128.x, pool->f34 * obj->f_84, &vtmp.x);
                psvec_add(&obj->v_54.x, &vtmp.x, &obj->v_54.x);
                psvec_add(&obj->v_60.x, &vtmp.x, &obj->v_60.x);
            }
            fn_80008BA8(&obj->v_11c.x, &obj->v_128.x, 12);
            obj = (Obj *)((u8 *)obj + 0x1a8);
        }
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_E2AE8 */

/* fzgx:begin fn_1_E2DCC */
#include "psvec.h"

#pragma section code_type ".fzgxpool"
static const u32 fn_1_E2DCC_fzgx_pool_table1[6] = {0xBF800000, 0x3F7FFFFE, 0x3F800001, 0xBF800001, 0xBF7FFFFE, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fn_1_E2DCC_fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 0.0f;
    s = 5.0f;
    s = 1.0f;
}
static const u32 fn_1_E2DCC_fzgx_pool_table4[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fn_1_E2DCC_fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 10.0f;
    s = 182.04444885253906f;
    d = 4503599627370496.0;
    s = -0.0027222223579883575f;
}
static const u32 fn_1_E2DCC_fzgx_pool_table6[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fn_1_E2DCC_fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.58738019107841e-05f;
    s = 1.5f;
    s = -1.1920928955078125e-07f;
    s = 1.1920928955078125e-07f;
    d = 4503601774854144.0;
    s = 60.0f;
    s = 1000000.0f;
    s = 250000.0f;
    s = 20.0f;
}
static const u32 fn_1_E2DCC_fzgx_pool_table8[6] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fn_1_E2DCC_fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.009999999776482582f;
    s = 0.009999999776482582f;
    s = -1.0099999904632568f;
    s = 9.999999747378752e-05f;
}
static const u32 fn_1_E2DCC_fzgx_pool_table10[3] = {0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fn_1_E2DCC_fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9900000095367432f;
    s = 2.0f;
    s = -0.0f;
    d = 216.0;
    d = 3.1415927410125732;
    d = 4.0;
    d = 60.0;
    s = 1.0099999904632568f;
    s = 0.05000000074505806f;
    s = 1.0010000467300415f;
    s = 0.8999999761581421f;
    s = 3.0f;
}
static const u32 fn_1_E2DCC_fzgx_pool_table12[6] = {0x3FE00000, 0x40F00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40A00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fn_1_E2DCC_fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 0.0016666667070239782f;
    s = 0.30000001192092896f;
    s = 0.01666666753590107f;
    s = 10000000.0f;
    s = 5000000.0f;
    s = 100.0f;
}
static const u32 fn_1_E2DCC_fzgx_pool_table14[43] = {0x00000000, 0x3F800000, 0x00000000, 0x01060002, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x00FE0001, 0x005800A6, 0x005800A6, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005A00A8, 0x005C00A8, 0x01000002, 0x005F00A8, 0x005C00A8, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x01020002, 0x00020103, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fn_1_E2DCC_fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E2DCC_fzgx_pool_prime15(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 0.01745329238474369f;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

/* a 0x24-byte record of the course header's list at +0xA8 */
typedef struct {
    Vec3 unk_0;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    u8 pad_12[0x2];
    Vec3 unk_14;
    u32 unk_20;
} Record24;

/* a 0x38-byte record of the course header's list at +0xB8 */
typedef struct {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 unk_3;
    Vec3 unk_4;
    s32 *unk_10;
    Vec3 unk_14;
    Vec3 unk_20;
    Vec3 unk_2C;
} Record38;

typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x44];
    Vec3 unk_54;
    Vec3 unk_60;
    u8 pad_6C[0xC];
    f32 unk_78;
    f32 unk_7C;
    f32 unk_80;
    u8 pad_84[0x10];
    Vec3 unk_94;
    u8 pad_A0[0x54];
    Vec3 unk_F4;
    u8 pad_100[0x38];
    u64 unk_138;
    u8 pad_140[0x1C];
    s32 unk_15C;
    s32 *unk_160;
    Vec3 *unk_164;
    Vec3 *unk_168;
    Vec3 *unk_16C;
} PhysObj;

extern PhysObj *fn_1_E54A8(s16, s16);
extern s16 fn_1_7B054(void);
/* retail evaluates the float argument first; the definition passes it through unnamed */
extern f32 fn_1_9E14C(f32, u32, u32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006D7DC(Vec3 *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void fn_8006F6A8(s16 *);
extern u8 lbl_1_bss_9C;

/* opt_propagation off keeps cp and mtx as locals: retail colours &counts, group and 0xE0000000 below the pool base */
#pragma opt_propagation off
void fn_1_E2DCC(void) {
    f32 *mtx;
    s16 *cp;
    u8 group;
    s16 j;
    s16 angles[3];
    s16 k;
    s16 i;
    s16 type;
    Record24 *rec;
    Record38 *story;
    PhysObj *obj;
    s32 *curves;
    s16 n;
    s16 counts[6];

    n = lbl_1_bss_3BE0->unk_A4;
    fn_80008BEC(counts, 0, sizeof(counts));
    rec = (Record24 *)lbl_1_bss_3BE0->unk_A8;
    for (i = 0; i < n; i++, rec++) {
        if (rec->unk_20 & 0x40000000) {
            type = 1;
        } else if (rec->unk_20 & 0x80000000) {
            type = 5;
        } else {
            continue;
        }
        cp = counts;
        obj = fn_1_E54A8(type, cp[type]);
        fn_80008BA8(&obj->unk_54, &rec->unk_0, 12);
        fn_80008BA8(&obj->unk_60, &rec->unk_0, 12);
        fn_80008BA8(&obj->unk_F4, &rec->unk_14, 12);
        fn_80008BA8(&obj->unk_94, &rec->unk_0, 12);
        obj->unk_78 = 9.58738019107841e-05f * rec->unk_C;
        obj->unk_7C = 9.58738019107841e-05f * rec->unk_E;
        obj->unk_80 = 9.58738019107841e-05f * rec->unk_10;
        obj->unk_138 |= 0x800;
        cp[type]++;
    }

    if ((s32)lbl_1_bss_3BE0->unk_B4 > 0) {
        story = (Record38 *)lbl_1_bss_3BE0->unk_B8;
        if (fn_1_7B054() == 37) {
            group = (lbl_1_bss_960 == 9) ? (&lbl_1_bss_9C)[1] : 0;
            for (j = 0; j < (s32)lbl_1_bss_3BE0->unk_B4; j++, story++) {
                if ((story->unk_3 & 0xFU) == group) {
                    obj = fn_1_E54A8(1, counts[1]);
                    fn_80008BA8(&obj->unk_54, &story->unk_2C, 12);
                    fn_80008BA8(&obj->unk_60, &story->unk_2C, 12);
                    fn_80008BA8(&obj->unk_F4, &story->unk_14, 12);
                    obj->unk_78 = 0.01745329238474369f * story->unk_20.x;
                    obj->unk_7C = 0.01745329238474369f * story->unk_20.y;
                    obj->unk_80 = 0.01745329238474369f * story->unk_20.z;
                    obj->unk_138 |= 0x800;
                    counts[1]++;
                }
            }
        } else {
            lbl_8006DAEC();
            for (k = 0; k < (s32)lbl_1_bss_3BE0->unk_B4; k++, story++) {
                obj = fn_1_E54A8(2, k);
                curves = story->unk_10;
                obj->unk_E = story->unk_3;
                obj->unk_15C = -story->unk_2 * 20;
                obj->unk_160 = curves;
                obj->unk_164 = &story->unk_14;
                obj->unk_168 = &story->unk_20;
                obj->unk_16C = &story->unk_2C;
                lbl_8006D7DC(&story->unk_2C);
                mathutil_mtxA_rotate_z(182.04444885253906f * story->unk_20.z);
                mathutil_mtxA_rotate_y(182.04444885253906f * story->unk_20.y);
                mathutil_mtxA_rotate_x(182.04444885253906f * story->unk_20.x);
                lbl_8006E0B4(fn_1_9E14C(0.0f, curves[6], curves[7]), fn_1_9E14C(0.0f, curves[8], curves[9]),
                             fn_1_9E14C(0.0f, curves[10], curves[11]));
                mathutil_mtxA_rotate_z(182.04444885253906f * fn_1_9E14C(0.0f, curves[4], curves[5]));
                mathutil_mtxA_rotate_y(182.04444885253906f * fn_1_9E14C(0.0f, curves[2], curves[3]));
                mathutil_mtxA_rotate_x(182.04444885253906f * fn_1_9E14C(0.0f, curves[0], curves[1]));
                obj->unk_F4.x = story->unk_14.x * story->unk_4.x;
                obj->unk_F4.y = story->unk_14.y * story->unk_4.y;
                obj->unk_F4.z = story->unk_14.z * story->unk_4.z;
                /* Locked cache: the current matrix at 0xE0000000 is not a data symbol. */
                mtx = (f32 *)(0xE0000000 + 0);
                psvec_set(&obj->unk_54, mtx[11], mtx[7], mtx[3]);
                obj->unk_60 = obj->unk_54;
                fn_8006F6A8(angles);
                obj->unk_78 = 9.58738019107841e-05f * angles[0];
                obj->unk_7C = 9.58738019107841e-05f * angles[1];
                obj->unk_80 = 9.58738019107841e-05f * angles[2];
            }
            lbl_8006DB30();
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_E2DCC */

/* fzgx:begin fn_1_E3324 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"
extern void OSPanic(const char *, int, const char *, ...);
extern struct fn_1_DCE60_lbl_1_rodata_6750 lbl_1_rodata_6750;
extern void lbl_8006DAEC(void);
extern void lbl_8006DD14(void *, void *);
extern void fn_1_A7024(f32, f32, f32, f32);
extern void fn_8006F1F0(void *, void *, void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DCDC(void);
extern void lbl_8006DB30(void);
extern void fn_1_E1408(void *, void *);

#include "rel/main_rel/spline.h"

extern s16 fn_1_E5430(s16);
extern void *fn_1_E54A8(s16, s16);
extern void fn_1_E1A00(void *, void *);
extern void fn_1_E2DCC(void);
extern void fn_1_E252C(s16, s16, void *);
extern void fn_1_E2AE8(void);
extern s32 fn_1_7B054(void);
extern void fn_1_E5930(void *, s64);
extern Obj_1_bss_84428 *fn_1_FB0A8(void);
extern void fn_1_E1C10(void);
extern void fn_1_E87A4(f64, f64);
extern const f32 lbl_1_rodata_6994;
extern f32 lbl_1_rodata_6998[13];
extern u8 lbl_1_bss_9C;

/* the retail TU's .bss objects this function uses, at their retail offsets, so MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_7AE88[0xC];
s16 lbl_1_bss_7AE88__fzgx_offset_C;
u16 fzgx_pool_gap_7AE96;
u32 fzgx_pool_gap_7AE98;
s16 lbl_1_bss_7AE88__fzgx_offset_14;
u16 fzgx_pool_gap_7AE9E;
u32 fzgx_pool_gap_7AEA0[3];
s16 lbl_1_bss_7AE88__fzgx_offset_24;
u16 fzgx_pool_gap_7AEAE;
u32 fzgx_pool_gap_7AEB0;
s16 lbl_1_bss_7AE88__fzgx_offset_2C;
u16 fzgx_pool_gap_7AEB6;
u32 fzgx_obj_lbl_1_bss_7AEB8;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7AE88;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_C;
    s = *(u8 *)&fzgx_pool_gap_7AE96;
    s = *(u8 *)&fzgx_pool_gap_7AE98;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_14;
    s = *(u8 *)&fzgx_pool_gap_7AE9E;
    s = *(u8 *)&fzgx_pool_gap_7AEA0;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_24;
    s = *(u8 *)&fzgx_pool_gap_7AEAE;
    s = *(u8 *)&fzgx_pool_gap_7AEB0;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2C;
    s = *(u8 *)&fzgx_pool_gap_7AEB6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7AEB8;
}
#pragma section code_type ".text"

static inline void fn_1_E3324_loop2(void) {
    s16 j;
    s16 n;
    void *p;
    s16 i;
    for (i = 0; i < 6; i++) {
        n = fn_1_E5430(i);
        p = fn_1_E54A8(i, 0);
        for (j = 0; j < n; j++, p = ((u8 *)p + 0x1a8)) {
            fn_1_E252C(i, j, p);
        }
    }
}

/* course header +0xA4/+0xA8: the miscellaneous trigger list (0x24 each); counts the entries whose +0x20 top bit is set */
static inline void fn_1_E3324_count_flagged_misc_triggers(void) {
    s16 i;
    u8 *trigger;
    s16 n;

    n = lbl_1_bss_3BE0->unk_A4;
    lbl_1_bss_7AE88__fzgx_offset_2C = i = 0;
    trigger = (u8 *)lbl_1_bss_3BE0->unk_A8;
    for (; i < n; i++, trigger += 0x24) {
        if (*(u32 *)(trigger + 0x20) & 0x80000000) {
            lbl_1_bss_7AE88__fzgx_offset_2C++;
        }
    }
}

/* course header +0xB4/+0xB8: the story object triggers (0x38 each); counts those whose byte +3 low nibble is the
   story selector (.bss 0x9C+1 in story mode, else 0) */
static inline s32 fn_1_E3324_count_story_triggers(void) {
    u8 *trigger;
    struct { s32 value; } total;
    u8 sel;
    s32 count;
    struct { s16 value; } i;

    trigger = (u8 *)lbl_1_bss_3BE0->unk_B8;
    sel = lbl_1_bss_960 == 9 ? (&lbl_1_bss_9C)[1] : 0;
    count = 0;
    total.value = lbl_1_bss_3BE0->unk_B4;
    for (i.value = 0; i.value < total.value; i.value++, trigger += 0x38) {
        if ((u32)(trigger[3] & 0xF) == sel) {
            count++;
        }
    }
    return count;
}

void fn_1_E3324(void) {
    s16 n;
    struct { u8 *value; } name;
    void *p;
    s16 i;
    s16 j;

    switch (lbl_1_data_2B0D4.pad_0[(s16)fn_1_7B054()]) {
    case 13:
        lbl_1_bss_7AE88__fzgx_offset_24 = fn_1_FB0A8()->unk_A;
        break;
    }
    fn_1_E3324_count_flagged_misc_triggers();
    if ((s16)fn_1_7B054() == 37) {
        lbl_1_bss_7AE88__fzgx_offset_C = fn_1_E3324_count_story_triggers();
        lbl_1_bss_7AE88__fzgx_offset_14 = 0;
    } else {
        lbl_1_bss_7AE88__fzgx_offset_C = 0;
        lbl_1_bss_7AE88__fzgx_offset_14 = lbl_1_bss_3BE0->unk_B4;
    }
    fn_1_E1C10();
    name.value = lbl_1_data_3DDA8;
    for (i = 0; i < 6; i++) {
        n = fn_1_E5430(i);
        p = fn_1_E54A8(i, 0);
        for (j = 0; j < n; j++, p = ((u8 *)p + 0x1a8)) {
            fn_1_E1A00(p, name.value);
        }
    }
    fn_1_E2DCC();
    fn_1_E3324_loop2();
    fn_1_E2AE8();
    switch (lbl_1_data_2B0D4.pad_0[(s16)fn_1_7B054()]) {
    case 13:
        for (j = 0; j < fn_1_E5430(4); j++) {
            fn_1_E5930(fn_1_E54A8(4, j), 3);
        }
        break;
    }
    if (fn_1_E5430(2) != 0) {
        fn_1_E87A4(lbl_1_rodata_6994, lbl_1_rodata_6998[0]);
        fzgx_obj_lbl_1_bss_7AEB8 |= 0x80000000;
    } else {
        fzgx_obj_lbl_1_bss_7AEB8 &= ~0x80000000;
    }
}
/* fzgx:end fn_1_E3324 */

/* fzgx:begin fn_1_E35F0 noprologue */
#include "types.h"

typedef struct Sig_fn_1_8D168_Fn1_8D168State {
    u8 pad[0x60];
    u32 field_60;
} Sig_fn_1_8D168_Fn1_8D168State;

struct fn_1_E35F0_lbl_1_bss_7AE88 {
    u32 unk_0;
    u16 unk_4;
    u8 pad_6[0x2];
    u32 unk_8;
    u16 unk_C;
    u8 pad_E[0x2];
    u32 unk_10;
    u16 unk_14;
    u8 pad_16[0x2];
    u32 unk_18;
    u16 unk_1C;
    u8 pad_1E[0x2];
    u32 unk_20;
    u16 unk_24;
    u8 pad_26[0x2];
    u32 unk_28;
    u16 unk_2C;
    u8 pad_2E[0x2];
    u32 unk_30;
};
struct fn_1_E35F0_lbl_801A6410 {
    u32 unk_0;
};

extern struct fn_1_E35F0_lbl_801A6410 lbl_801A6410;
extern u32 lbl_1_data_3DDB4;
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_8D168(Sig_fn_1_8D168_Fn1_8D168State *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_7AE88;
u16 lbl_1_bss_7AE88__fzgx_offset_4;
u16 lbl_1_bss_7AE88__fzgx_offset_6;
u32 lbl_1_bss_7AE88__fzgx_offset_8;
u16 lbl_1_bss_7AE88__fzgx_offset_C;
u16 lbl_1_bss_7AE88__fzgx_offset_E;
u32 lbl_1_bss_7AE88__fzgx_offset_10;
u16 lbl_1_bss_7AE88__fzgx_offset_14;
u16 lbl_1_bss_7AE88__fzgx_offset_16;
u32 lbl_1_bss_7AE88__fzgx_offset_18;
u16 lbl_1_bss_7AE88__fzgx_offset_1C;
u16 lbl_1_bss_7AE88__fzgx_offset_1E;
u32 lbl_1_bss_7AE88__fzgx_offset_20;
u16 lbl_1_bss_7AE88__fzgx_offset_24;
u16 lbl_1_bss_7AE88__fzgx_offset_26;
u32 lbl_1_bss_7AE88__fzgx_offset_28;
u16 lbl_1_bss_7AE88__fzgx_offset_2C;
u16 lbl_1_bss_7AE88__fzgx_offset_2E;
u32 lbl_1_bss_7AEB8;
u32 lbl_1_bss_7AEB8__fzgx_offset_4[164];
u32 lbl_1_bss_7B14C[13];
u32 lbl_1_bss_7B180[2];
u32 lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_7AE88;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_16;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_18;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_1E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_24;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_26;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_28;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2C;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2E;
    s = *(u8 *)&lbl_1_bss_7AEB8;
    s = *(u8 *)&lbl_1_bss_7AEB8__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7B14C;
    s = *(u8 *)&lbl_1_bss_7B180;
    s = *(u8 *)&lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
}
#pragma section code_type ".text"

void fn_1_E35F0(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    
    if ((lbl_1_bss_7AEB8 & ~0x7FFFFFFF) != 0) {
    fn_1_8D168((Sig_fn_1_8D168_Fn1_8D168State *)(&lbl_1_bss_7AEB8 + 132));
    lbl_1_bss_7AEB8 = (lbl_1_bss_7AEB8 & 0x7FFFFFFF);
    }
    v0 = lbl_1_bss_7AE88;
    if (v0 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v0, (const char *)&lbl_1_data_3DDB4, 2647);
    lbl_1_bss_7AE88 = 0;
    lbl_1_bss_7AE88__fzgx_offset_4 = 0;
    }
    v1 = lbl_1_bss_7AE88__fzgx_offset_8;
    if (v1 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v1, (const char *)&lbl_1_data_3DDB4, 2648);
    lbl_1_bss_7AE88__fzgx_offset_8 = 0;
    lbl_1_bss_7AE88__fzgx_offset_C = 0;
    }
    v2 = lbl_1_bss_7AE88__fzgx_offset_10;
    if (v2 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v2, (const char *)&lbl_1_data_3DDB4, 2649);
    lbl_1_bss_7AE88__fzgx_offset_10 = 0;
    lbl_1_bss_7AE88__fzgx_offset_14 = 0;
    }
    v3 = lbl_1_bss_7AE88__fzgx_offset_18;
    if (v3 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v3, (const char *)&lbl_1_data_3DDB4, 2650);
    lbl_1_bss_7AE88__fzgx_offset_18 = 0;
    lbl_1_bss_7AE88__fzgx_offset_1C = 0;
    }
    v4 = lbl_1_bss_7AE88__fzgx_offset_20;
    if (v4 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v4, (const char *)&lbl_1_data_3DDB4, 2651);
    lbl_1_bss_7AE88__fzgx_offset_20 = 0;
    lbl_1_bss_7AE88__fzgx_offset_24 = 0;
    }
    v5 = lbl_1_bss_7AE88__fzgx_offset_28;
    if (v5 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v5, (const char *)&lbl_1_data_3DDB4, 2652);
    lbl_1_bss_7AE88__fzgx_offset_28 = 0;
    lbl_1_bss_7AE88__fzgx_offset_2C = 0;
    }
}
/* fzgx:end fn_1_E35F0 */

/* fzgx:begin fn_1_E3778 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"
extern void OSPanic(const char *, int, const char *, ...);
extern struct fn_1_DCE60_lbl_1_rodata_6750 lbl_1_rodata_6750;
extern void lbl_8006DAEC(void);
extern void lbl_8006DD14(void *, void *);
extern void fn_1_A7024(f32, f32, f32, f32);
extern void fn_8006F1F0(void *, void *, void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DCDC(void);
extern void lbl_8006DB30(void);
extern void fn_1_E1408(void *, void *);

extern s16 fn_1_E5430(s16);
extern void *fn_1_E54A8(s16, s16);
extern void fn_1_E1A00(void *, void *);
extern void fn_1_E2DCC(void);
extern void fn_1_E252C(s16, s16, void *);
extern void fn_1_E2AE8(void);
extern s32 fn_1_7B054(void);
extern void fn_1_E5930(void *, s64);


static inline void fn_1_E3778_loop2(void) {
    s16 j;
    s16 n;
    void *p;
    s16 i;
    for (i = 0; i < 6; i++) {
        n = fn_1_E5430(i);
        p = fn_1_E54A8(i, 0);
        for (j = 0; j < n; j++, p = ((u8 *)p + 0x1a8)) {
            fn_1_E252C(i, j, p);
        }
    }
}

void fn_1_E3778(void) {
    s16 n;
    struct { u8 *value; } name;
    void *p;
    s16 i;
    s16 j;

    name.value = lbl_1_data_3DDA8;
    for (i = 0; i < 6; i++) {
        n = fn_1_E5430(i);
        p = fn_1_E54A8(i, 0);
        for (j = 0; j < n; j++, p = ((u8 *)p + 0x1a8)) {
            fn_1_E1A00(p, name.value);
        }
    }
    fn_1_E2DCC();
    fn_1_E3778_loop2();
    fn_1_E2AE8();
    switch (lbl_1_data_2B0D4.pad_0[(s16)fn_1_7B054()]) {
    case 13:
        for (j = 0; j < fn_1_E5430(4); j++) {
            fn_1_E5930(fn_1_E54A8(4, j), 3);
        }
        break;
    }
}
/* fzgx:end fn_1_E3778 */

/* fzgx:begin fn_1_E38D4 */
extern s16 fn_1_E5430(s16);
extern void *fn_1_E54A8(s16, s16);

typedef struct {
    u8 pad_0[0xA];
    s16 unk_A;
    u8 pad_C[0x2];
    s16 unk_E;
    u8 pad_10[0x128];
    u64 flags_138;
    u8 pad_140[0x68];
} PhysEntry;

void fn_1_E38D4(void) {
    PhysEntry *entry;
    s16 group;
    s16 count;
    s16 i;

    fn_1_9C724();
    for (group = 0; group < 6; group++) {
        count = fn_1_E5430(group);
        entry = (PhysEntry *)fn_1_E54A8(group, 0);
        if (entry != 0 && entry->unk_A == 4 &&
            (entry->flags_138 & 0x80000000000ULL) == 0) {
            fn_80077E0C(*(void **)((u8 *)*(void **)((u8 *)*(void **)(lbl_1_bss_3BE0->unk_54 +
                (entry->unk_E << 6) + 8) + 8) + 8));
            fn_80076134();
        }
        for (i = 0; i < count; i++, entry++) {
            if ((entry->flags_138 & 0x80000000000ULL) == 0) {
                fn_1_DD890(entry);
            }
        }
    }
    fn_1_9CC40();
}
/* fzgx:end fn_1_E38D4 */

/* fzgx:begin fn_1_E39F0 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
    s = 0.9999998807907104f;
    s = 1.0000001192092896f;
    s = -1.0000001192092896f;
    s = -0.9999998807907104f;
    s = 0.0f;
    d = 1.1920928955078125e-07;
}
static const u32 fn_1_E39F0_fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fn_1_E39F0_fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    s = 1.0f;
}
static const u32 fn_1_E39F0_fzgx_pool_table4[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fn_1_E39F0_fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 10.0f;
    s = 182.04444885253906f;
    d = 4503599627370496.0;
    s = -0.0027222223579883575f;
}
static const u32 fn_1_E39F0_fzgx_pool_table6[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fn_1_E39F0_fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.58738019107841e-05f;
    s = 1.5f;
    s = -1.1920928955078125e-07f;
    s = 1.1920928955078125e-07f;
    d = 4503601774854144.0;
    s = 60.0f;
    s = 1000000.0f;
    s = 250000.0f;
    s = 20.0f;
}
static const u32 fn_1_E39F0_fzgx_pool_table8[6] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fn_1_E39F0_fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.009999999776482582f;
    s = 0.009999999776482582f;
    s = -1.0099999904632568f;
    s = 9.999999747378752e-05f;
}
static const u32 fn_1_E39F0_fzgx_pool_table10[3] = {0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fn_1_E39F0_fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9900000095367432f;
    s = 2.0f;
    s = -0.0f;
    d = 216.0;
    d = 3.1415927410125732;
    d = 4.0;
    d = 60.0;
    s = 1.0099999904632568f;
    s = 0.05000000074505806f;
    s = 1.0010000467300415f;
    s = 0.8999999761581421f;
    s = 3.0f;
}
static const u32 fn_1_E39F0_fzgx_pool_table12[6] = {0x3FE00000, 0x40F00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40A00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fn_1_E39F0_fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 0.0016666667070239782f;
    s = 0.30000001192092896f;
    s = 0.01666666753590107f;
    s = 10000000.0f;
    s = 5000000.0f;
    s = 100.0f;
}
static const u32 fn_1_E39F0_fzgx_pool_table14[43] = {0x00000000, 0x3F800000, 0x00000000, 0x01060002, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x00FE0001, 0x005800A6, 0x005800A6, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005A00A8, 0x005C00A8, 0x01000002, 0x005F00A8, 0x005C00A8, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x01020002, 0x00020103, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fn_1_E39F0_fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E39F0_fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.01745329238474369f;
    s = -3.0f;
}
static const u32 fzgx_pool_table16[8] = {0x40400000, 0xC0400000, 0x40400000, 0x41200000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 224.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 255.0f;
    s = 640.0f;
    s = 480.0f;
    s = 1.2705882787704468f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct LocalStruct {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x14];
    f32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u8 pad_3C[0x1C];
} LocalStruct;

typedef struct RoData_6780 {
    u8 pad_0[0x34];
    f32 unk_34;
    u8 pad_38[0x8];
    f64 unk_40;
    u8 pad_48[0x1CC];
    f32 unk_214;
    u8 pad_218[0x4];
    u32 unk_21C;
    f32 unk_220;
    f32 unk_224;
    f32 unk_228;
    f32 unk_22C;
    f32 unk_230;
} RoData_6780;

typedef struct Node_80077E0C {
    u8 pad[8];
    struct Node_80077E0C *child;
} Node_80077E0C;

typedef struct Elem_3BE0 {
    u8 pad[8];
    Node_80077E0C *node;
    u8 pad2[0x40 - 12];
} Elem_3BE0;

typedef struct Obj_1A8 {
    u8 pad_0[0xA];
    s16 unk_A;
    u8 pad_C[2];
    s16 unk_E;
    u8 pad_10[0x128];
    u64 unk_138;
    u8 pad_140[0x1A8 - 0x140];
} Obj_1A8;

extern const LocalStruct lbl_1_rodata_26F8;
extern s8 fn_1_A5DC4(void);
extern void fn_1_4E92C(LocalStruct *, u32, u16, u16, u32);
extern s16 fn_1_E5430(s16);

void fn_1_E39F0(void) {

    if (lbl_1_bss_7AEB8.unk_0 & (1U << 31)) {
        LocalStruct sp8 = lbl_1_rodata_26F8;
        sp8.unk_4 = (320.0f);
        sp8.unk_8 = (240.0f);
        sp8.unk_C = (255.0f);
        sp8.unk_10 *= ((640.0f) / lbl_1_bss_7AEB8.unk_240);
        sp8.unk_14 *= ((480.0f) / lbl_1_bss_7AEB8.unk_242);
        if (fn_1_A5DC4()) {
            sp8.unk_10 *= (1.27058828f);
            sp8.unk_14 *= (1.27058828f);
        }
        sp8.unk_38 = fzgx_pool_table18[0];
        sp8.unk_2C = (0.5f);
        sp8.unk_30 = 10;
        fn_1_4E92C(&sp8, lbl_1_bss_7AEB8.unk_244,
                   lbl_1_bss_7AEB8.unk_240, lbl_1_bss_7AEB8.unk_242,
                   lbl_1_bss_7AEB8.unk_270);
    }

    fn_1_9C724();
    {
        s16 i;
        for (i = 0; i < 6; i++) {
            s16 count = fn_1_E5430(i);
            Obj_1A8 *obj = fn_1_E54A8(i, 0);
            if (obj != NULL && obj->unk_A == 4 &&
                (obj->unk_138 & (0x800ULL << 32))) {
                Elem_3BE0 *arr = (Elem_3BE0 *)lbl_1_bss_3BE0->unk_54;
                fn_80077E0C(arr[obj->unk_E].node->child->child);
                fn_80076134();
            }
            obj = fn_1_E54A8(i, 0);
            {
                s16 j;
                for (j = 0; j < count; j++, obj++) {
                    if (obj->unk_138 & (0x800ULL << 32)) {
                        fn_1_DD890(obj);
                    }
                }
            }
        }
    }
    fn_1_9CC40();
}
/* fzgx:end fn_1_E39F0 */

/* fzgx:begin fn_1_E3C38 */
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} E3C38Vec;

/* local view of one physics object (0x1A8 bytes) */
typedef struct {
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x14];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    E3C38Vec unk_2C;
    E3C38Vec unk_38;
    E3C38Vec unk_44;
    f32 unk_50;
    E3C38Vec unk_54;
    E3C38Vec unk_60;
    E3C38Vec unk_6C;
    E3C38Vec unk_78;
    f32 unk_84;
    u8 pad_88[0xC];
    E3C38Vec unk_94;
    E3C38Vec unk_A0;
    u8 unk_AC[0x10];
    u32 unk_BC;
    u32 unk_C0;
    u8 unk_C4[0x30];
    u8 unk_F4[0xC];
    u8 unk_100[0x1C];
    E3C38Vec unk_11C;
    E3C38Vec unk_128;
    u8 pad_134[0x4];
    u64 unk_138;
    u8 pad_140[0x4];
    u32 unk_144;
    u32 unk_148;
    u32 unk_14C;
    u32 unk_150;
    u8 pad_154[0x4];
    u32 unk_158;
    u8 pad_15C[0x4C];
} E3C38Obj;

/* local view of a machine */
typedef struct {
    u8 pad_0[0x7C];
    E3C38Vec unk_7C;
    u8 pad_88[0x3EC];
    s8 unk_474;
} E3C38Car;

extern u32 lbl_801A66A0;
extern u8 lbl_1_data_3DE40[0x128];
extern void fn_80008BEC(void *dst, void *value, u32 size);
extern void fn_80008BA8(void *dst, void *value, u32 size);
extern void fn_1_DE9C4(E3C38Obj *obj);
extern void fn_1_DE4B0(E3C38Obj *obj, E3C38Vec *normal);
extern f32 lbl_8006D0B4(f32 value);
extern f32 lbl_8006D534(E3C38Vec *a, E3C38Vec *b);
extern void lbl_8006D5F0(E3C38Vec *a, E3C38Vec *out, f32 scale);
extern void lbl_8006D668(E3C38Vec *vector);
extern void fn_1_E1934(E3C38Obj *obj, E3C38Obj *base, s16 limit);
extern s8 fn_1_86624(void);
extern E3C38Car *fn_1_86254(s32 index);
extern void fn_1_DFBBC(E3C38Car *car, E3C38Obj *obj);
extern void fn_1_E07B8(E3C38Obj *obj);
extern void fn_1_E57FC(void *object, void *source);
extern void fn_1_E5988(void *base, void *value);
extern void fn_1_E58CC(void *base, const void *value);
extern void fn_1_E1A00(void *obj, void *str);
extern void lbl_8006D7DC(void *value);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E13C(void *);
extern void lbl_8006DB74(void *);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fn_1_E3C38_fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
}
static const u32 fn_1_E3C38_fzgx_pool_table1[5] = {0x3F7FFFFE, 0x3F800001, 0xBF800001, 0xBF7FFFFE, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E3C38_fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fn_1_E3C38_fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E3C38_fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 0.0f;
}
static const u32 fn_1_E3C38_fzgx_pool_table2[1] = {0x40A00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E3C38_fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fn_1_E3C38_fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E3C38_fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
}
static const u32 fn_1_E3C38_fzgx_pool_table3[2] = {0x00FF00FF, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fn_1_E3C38_fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E3C38_fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
}
static const u32 fn_1_E3C38_fzgx_pool_table4[4] = {0x41200000, 0x43360B61, 0x43300000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E3C38_fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fn_1_E3C38_fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E3C38_fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.0027222223579883575f;
}
static const u32 fzgx_pool_table5[44] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x38C90FDB, 0x3FC00000, 0xB4000000, 0x34000000, 0x43300000, 0x80000000, 0x42700000, 0x49742400, 0x48742400, 0x41A00000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0xBC23D70A, 0x3C23D70A, 0xBF8147AE, 0x38D1B717, 0x00000000, 0x3F800000, 0x00000000, 0x3F7D70A4, 0x40000000, 0x80000000, 0x406B0000, 0x00000000, 0x400921FB, 0x60000000, 0x40100000, 0x00000000, 0x404E0000, 0x00000000, 0x3F8147AE};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
}
static const u32 fn_1_E3C38_fzgx_pool_table6[77] = {0x3F8020C5, 0x3F666666, 0x40400000, 0x3FE00000, 0x40F00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40A00000, 0x3F4CCCCD, 0x3ADA740E, 0x3E99999A, 0x3C888889, 0x4B189680, 0x4A989680, 0x42C80000, 0x00000000, 0x3F800000, 0x00000000, 0x01060002, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x00FE0001, 0x005800A6, 0x005800A6, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005A00A8, 0x005C00A8, 0x01000002, 0x005F00A8, 0x005C00A8, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x01020002, 0x00020103, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x3C8EFA35, 0xC0400000, 0x40400000, 0xC0400000, 0x40400000, 0x41200000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3F000000, 0x43A00000, 0x43600000, 0x00000000, 0x43700000, 0x437F0000, 0x44200000, 0x43F00000, 0x3FA2A2A3};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E3C38_fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fn_1_E3C38_fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

static inline f32 fn_1_E3C38_len2(E3C38Vec *v) {
    f32 x = v->x;
    f32 sq = x * x;
    f32 y = v->y;
    f32 z = v->z;

    sq = y * y + sq;
    sq = z * z + sq;
    return sq;
}

/* as fn_1_DE180_dot (bg_for.c); the views keep the loads as real locals, as retail's allocation needs */
static inline f32 fn_1_E3C38_dot(E3C38Vec *a, E3C38Vec *b) {
    f32 result;
    f32 ax;
    f32 bx;
    f32 ay;
    f32 by;
    f32 az;
    f32 bz;

    ax = *(volatile f32 *)&a->x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    bx = *(volatile f32 *)&b->x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    ay = *(volatile f32 *)&a->y;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    by = *(volatile f32 *)&b->y;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    az = a->z;
    bz = b->z;
    result = ax * bx;
    result += ay * by;
    result += az * bz;
    return result;
}

/* out = a x b, all inputs read before the stores; read order as fn_1_DE180_cross (bg_for.c), b->y last */
static inline void fn_1_E3C38_cross(E3C38Vec *a, E3C38Vec *b, E3C38Vec *out) {
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = b->x;
    f32 by;
    f32 bz = b->z;
    f32 ax = a->x;
    f32 x;
    f32 y;
    f32 z;

    by = b->y;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    x = ay * bz;
    x -= az * by;
    out->x = x;
    out->y = y;
    out->z = z;
}

/* acc += v * s, through tmp */
static inline void fn_1_E3C38_scale_add(E3C38Vec *acc, E3C38Vec *v, f32 s, E3C38Vec *tmp) {
    psvec_scale(v, s, tmp);
    psvec_add(acc, tmp, acc);
}

static inline f32 fn_1_E3C38_min1(f32 x) {
    if (x < 1.0f) {
        return x;
    }
    return 1.0f;
}

static inline f32 fn_1_E3C38_max0(f32 x) {
    if (x > 0.0f) {
        return x;
    }
    return 0.0f;
}

/* fn_1_DFBBC for each machine against this object; in its own inline, retail's counter zero doubles as the
 * 64-bit mask zero (li r29,0) */
static inline void fn_1_E3C38_hit_cars(E3C38Obj *obj) {
    E3C38Car *car;
    s16 j;
    s16 n;

    n = fn_1_86624();
    if ((obj->unk_138 & 0x10) != 0) {
        return;
    }
    for (j = 0; j < n; j++) {
        car = fn_1_86254(j);
        if ((obj->unk_138 & 0x200000000ULL) == 0 || car->unk_474 != -1) {
            fn_1_DFBBC(car, obj);
        }
    }
}

/* out = (a x b) x b, normalised; the same steps as fn_1_DE180_perp (bg_for.c) */
static inline void fn_1_E3C38_perp(E3C38Vec *a, E3C38Vec *b, E3C38Vec *out) {
    E3C38Vec *n = out;

    fn_1_E3C38_cross(a, b, out);
    fn_1_E3C38_cross(out, b, out);
    if (fn_1_E3C38_len2(out) > 0.0f) {
        lbl_8006D668(n);
    }
}

static inline void fn_1_E3C38_flip(E3C38Vec *v) {
    psvec_scale(v, -1.0f, v);
}

static inline void fn_1_E3C38_bounce(E3C38Obj *obj, E3C38Vec *v, E3C38Vec *c, f32 len, f32 side) {
    fn_80008BA8(v, &obj->unk_2C, 12);
    fn_1_E3C38_perp(v, &obj->unk_11C, c);
    if (!(fn_1_E3C38_dot(v, c) > 0.0f)) {
        fn_1_E3C38_flip(c);
    }
    psvec_scale(c, len * side, c);
    fn_80008BA8(&obj->unk_2C, c, 12);
}

/* the second pass's per-object step; inlined below a raised size limit, as retail inlines it (its scale
 * factors expand after the respawn scale, which gives retail's saved-FPR order) */
#pragma inline_max_size(2000)
static inline void fn_1_E3C38_move(E3C38Obj *obj) {
    f32 len;
    f32 dot;
    f32 push;
    f32 side;
    f32 k;
    E3C38Vec v;
    E3C38Vec tmp;
    E3C38Vec c;
    E3C38Vec f;
    E3C38Vec s;
    E3C38Vec g;

    if ((obj->unk_138 & 0x1000000000ULL) != 0) {
        fn_1_DE9C4(obj);
    } else if (obj->unk_54.y < -10000.0f) {
        obj->unk_138 |= 3;
    } else {
        if ((obj->unk_138 & 8) == 0) {
            fn_1_E3C38_scale_add(&obj->unk_2C, &obj->unk_128, -0.0027222223579883575f * obj->unk_1C, &g);
        }
        if (0.0f != obj->unk_28 && (obj->unk_138 & 0x100) == 0) {
            fn_1_E3C38_scale_add(&obj->unk_2C, &obj->unk_44, -obj->unk_28, &f);
            fn_1_E3C38_scale_add(&obj->unk_6C, &obj->unk_6C, -fn_1_E3C38_min1(obj->unk_28 / obj->unk_1C), &s);
        }
        fn_1_DE4B0(obj, &obj->unk_11C);
        if ((obj->unk_138 & 0x8000) != 0) {
            len = lbl_8006D0B4(fn_1_E3C38_len2(&obj->unk_2C));
            if ((obj->unk_138 & 0x10000000) == 0 || 0.0f != len) {
                dot = lbl_8006D534(&obj->unk_2C, &obj->unk_11C);
                if (!(dot > 0.0f)) {
                    /* fzgx-allow: S2 volatile view keeps the verified load order */
                    k = -(((obj->unk_138 & 0x10000000) != 0) ? *(volatile f32 *)&obj->unk_20 : obj->unk_24);
                    push = dot * (k * len);
                    side = lbl_8006D0B4(1.0f - (f32)(dot * dot));
                    fn_1_E3C38_bounce(obj, &v, &c, len, side);
                    if ((obj->unk_138 & 0x10000000) != 0) {
                        lbl_8006D5F0(&obj->unk_2C, &tmp, -push);
                    } else {
                        lbl_8006D5F0(&obj->unk_44, &tmp, -push);
                    }
                    psvec_add(&tmp, &obj->unk_2C, &obj->unk_2C);
                }
            }
        }
        if ((obj->unk_138 & 0x2000) == 0) {
            fn_1_E3C38_scale_add(&obj->unk_44, &obj->unk_2C, 1.0f / obj->unk_1C, &obj->unk_38);
        }
    }
}

void fn_1_E3C38(E3C38Obj *objs, s16 count) {
    E3C38Obj *cur;
    E3C38Obj *p;
    E3C38Obj *obj;
    E3C38Car *car;
    s16 i2;
    s16 i;
    s16 j;
    s32 found;
    E3C38Vec d;
    E3C38Vec h;
    E3C38Vec up;

    if (count <= 0) {
        return;
    }

    for (cur = objs, i = 0; i < count; cur++, i++) {
        cur->unk_148 = 0;
        if ((cur->unk_138 & 2) == 0) {
            if ((cur->unk_138 & 0x40000000) != 0) {
                cur->unk_14C = lbl_801A66A0;
            }
            if (lbl_801A66A0 - cur->unk_14C > 4) {
                cur->unk_138 &= ~0x8000ULL;
                cur->unk_138 &= ~0x8000000ULL;
            }
            if ((cur->unk_138 & 0x8000) != 0) {
                cur->unk_150 = lbl_801A66A0;
            }
            if (lbl_801A66A0 - cur->unk_150 > 4) {
                cur->unk_138 &= ~0x100000000ULL;
            }
            if ((cur->unk_138 & 0x100000000ULL) == 0) {
                cur->unk_158 = 0;
            }
            cur->unk_138 &= ~0xE0000000ULL;
            cur->unk_144 = 0;
            fn_80008BEC(&cur->unk_2C, 0, 12);
        }
        if ((cur->unk_138 & 2) == 0) {
            cur->unk_138 &= ~0x80ULL;
            cur->unk_138 &= ~0x400000ULL;
            cur->unk_138 &= ~0x100000ULL;
        }
    }

    for (cur = objs, j = 0; j < count; cur++, j++) {
        if ((cur->unk_138 & 2) != 0) {
            continue;
        }
        fn_1_E3C38_move(cur);
    }

    for (cur = objs, i = 0; i < count; cur++, i++) {
        if ((cur->unk_138 & 2) == 0) {
            fn_1_E1934(cur, objs, count);
        }
    }

    for (p = objs, i2 = 0; i2 < count; p++, i2++) {
        if ((p->unk_138 & 2) != 0) {
            continue;
        }
        fn_1_E3C38_hit_cars(p);
    }

    for (cur = objs, i2 = 0; i2 < count; cur++, i2++) {
        if ((cur->unk_138 & 2) == 0) {
            fn_1_E07B8(cur);
        }
    }

    for (obj = objs, i2 = 0; i2 < count; obj++, i2++) {
        if ((obj->unk_138 & 2) != 0) {
            continue;
        }
        if ((obj->unk_138 & 0x2000) == 0) {
            fn_80008BA8(&obj->unk_60, &obj->unk_54, 12);
            obj->unk_50 = lbl_8006D0B4(fn_1_E3C38_len2(&obj->unk_44));
            if (__fabs(obj->unk_50) < 1.1920928955078125e-07) {
                obj->unk_138 |= 0x10000000;
                fn_1_E57FC(obj, 0);
            } else {
                obj->unk_138 &= ~0x10000000ULL;
                psvec_add(&obj->unk_54, &obj->unk_44, &obj->unk_54);
            }
            psvec_add(&obj->unk_78, &obj->unk_6C, &obj->unk_78);
        }
        if ((obj->unk_138 & 0x10000000000ULL) != 0) {
            if (obj->unk_C0 != -1) {
                if (lbl_801A66A0 - obj->unk_C0 > obj->unk_BC) {
                    obj->unk_4 = fn_1_E3C38_max0(obj->unk_4 - 0.05000000074505806f);
                }
                if (obj->unk_4 <= 0.0f) {
                    obj->unk_138 |= 0x10;
                    found = 1;
                    for (j = 0; j < fn_1_86624(); j++) {
                        car = fn_1_86254(j);
                        psvec_sub(&car->unk_7C, &obj->unk_94, &d);
                        if (fn_1_E3C38_len2(&d) < 22500.0f) {
                            found = 0;
                            break;
                        }
                    }
                    if ((obj->unk_138 & 0x20000000000ULL) != 0) {
                        if (found == 1) {
                            obj->unk_C0 = -1;
                            obj->unk_BC = 600;
                            if ((obj->unk_138 & 0x800) != 0) {
                                fn_1_E5988(obj, &obj->unk_94);
                                fn_1_E58CC(obj, &obj->unk_A0);
                            } else {
                                fn_1_E5988(obj, 0);
                                up = (E3C38Vec){0.0f, 1.0f, 0.0f};
                                fn_1_E58CC(obj, &up);
                            }
                            fn_80008BA8(obj->unk_100, obj->unk_AC, 16);
                            fn_1_E1A00(obj, lbl_1_data_3DE40);
                            if ((obj->unk_138 & 8) == 0) {
                                psvec_scale(&obj->unk_128, 0.5f * obj->unk_84, &h);
                                psvec_add(&obj->unk_54, &h, &obj->unk_54);
                                psvec_add(&obj->unk_60, &h, &obj->unk_60);
                            }
                        }
                    } else {
                        obj->unk_138 |= 3;
                    }
                }
            } else {
                obj->unk_4 = fn_1_E3C38_min1(0.05000000074505806f + obj->unk_4);
                if (obj->unk_4 >= 1.0f && (obj->unk_138 & 0x10) != 0) {
                    obj->unk_138 &= ~0x10ULL;
                }
            }
        }
        lbl_8006D7DC(&obj->unk_54);
        mathutil_mtxA_rotate_z((10430.3779296875f * obj->unk_78.z));
        mathutil_mtxA_rotate_y((10430.3779296875f * obj->unk_78.y));
        mathutil_mtxA_rotate_x((10430.3779296875f * obj->unk_78.x));
        lbl_8006E13C(obj->unk_F4);
        lbl_8006DB74(obj->unk_C4);
    }
}
#pragma inline_max_size reset
/* fzgx:end fn_1_E3C38 */

/* fzgx:begin fn_1_E49D4 */
extern u32 fn_1_E3C38(u32, u32);
extern u32 fn_1_E5430(u32);
extern u32 fn_1_E54A8(u32, u32);

void fn_1_E49D4(void) {
    s32 v0;
    u32 t0, t1;
    v0 = 0;
    while ((s16)v0 < 6) {
    fn_1_E3C38((fn_1_E54A8(v0, 0)), (fn_1_E5430(v0)));
    v0++;
    }
}
/* fzgx:end fn_1_E49D4 */

/* fzgx:begin fn_1_E4A38 noprologue */
#include "types.h"

typedef struct {
    u8 unk0[0x100];
    s32 value;
} Sig_fn_1_E573C_E573CObj;

struct D {
    u8 pad0[0x30];
    u32 unk_30[1];
    u8 pad1[0x1b0 - 0x34];
    u8 s1b0[8];
    u8 s1b8[8];
    u8 s1c0[4];
    u8 s1c4[0xc];
    u8 s1d0[0x10];
    u8 s1e0[0x10];
    u8 s1f0[0x10];
    u8 s200[0x10];
    u8 s210[0x10];
    u8 s220[8];
    u8 s228[8];
    u8 s230[8];
    u8 s238[8];
    u8 s240[8];
    u8 s248[0x10];
    u8 s258[8];
    u8 s260[8];
    u8 s268[8];
    u8 s270[0x10];
    u8 s280[8];
    u8 s288[0xc];
    u8 s294[8];
    u8 s29c[8];
    u8 s2a4[8];
    u8 s2ac[8];
    u8 s2b4[0xc];
    u8 s2c0[8];
    u8 s2c8[4];
    u8 s2cc[4];
};

typedef void (*Cb)(void *, ...);

extern char * strcat(char *, const char *);
extern f32 lbl_1_rodata_6808;
extern f32 lbl_1_rodata_69CC;
extern f64 lbl_1_rodata_6800;
extern s16 fn_1_E5724(void *);
extern s16 fn_1_E572C(void *);
extern s16 fn_1_E573C(Sig_fn_1_E573C_E573CObj *);
extern struct D lbl_1_data_3DC98;
extern u32 fn_1_E57C4(void *);
extern void * fn_1_E5748(void *);
extern void * fn_1_E5750(void *);
extern f32 fn_1_E5758(void *);
extern void * fn_1_E5760(void *);
extern void * fn_1_E5768(void *);
extern f32 fn_1_E57A4(void *);
extern f32 fn_1_E57AC(void *);
extern f32 fn_1_E57B4(void *);
extern f32 fn_1_E57BC(void *);
extern void * fn_1_E57CC(void *);
extern void * fn_1_E57D4(void *);
extern void * fn_1_E57DC(void *);
extern f32 fn_1_E57E4(void *);
extern f32 fn_1_E57EC(void *);
extern char * strcpy(char *, const char *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8EF8(u16, u16);

#pragma opt_propagation off
static inline u32 fn_1_E4A38_array_read_(u32 *array, s32 index) { return array[index]; }
static inline u32 * fn_1_E4A38_read_pointer(struct D * owner) { return owner->unk_30; }
void fn_1_E4A38(u32 arg0, u16 arg1, u16 arg2, Cb arg3) {
    struct D *p_lbl_1_data_3DC98;
    u32 v0;
    u32 v1;
    u32 v2;
    s32 v3;
    s16 v4;
    u32 t24;
    f32 *fv;
    char loc_8[0x20];

    p_lbl_1_data_3DC98 = (struct D *)&lbl_1_data_3DC98;
    if ((u32)arg3 == (u32)fn_1_4AE0C) {
        fn_1_496FC((s16)arg1, (s16)arg2);
        fn_1_4955C(lbl_1_rodata_69CC, lbl_1_rodata_69CC);
    } else {
        if ((u32)arg3 == (u32)fn_1_A8DD4) {
            fn_1_A8EF8(arg1, arg2);
        }
    }
    v0 = *(u32 *)(arg0 + 316);
    if ((*(u64 *)((u8 *)arg0 + 312) & 0x20000) != 0) {
        arg3(p_lbl_1_data_3DC98->s1b0, fn_1_E5724((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s1b0, fn_1_E573C((Sig_fn_1_E573C_E573CObj *)arg0));
    } else {
        arg3(p_lbl_1_data_3DC98->s1b8, fn_1_E5724((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s1c4, fn_1_E4A38_array_read_(fn_1_E4A38_read_pointer(p_lbl_1_data_3DC98), fn_1_E572C((void *)arg0)));
        arg3(p_lbl_1_data_3DC98->s1d0, fn_1_E57A4((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s1e0, fn_1_E57AC((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s1f0, fn_1_E57B4((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s200, fn_1_E57BC((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s210, lbl_1_rodata_6808 * fn_1_E57EC((void *)arg0));
        fv = fn_1_E57CC((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s220);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        fv = fn_1_E57D4((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s238);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        fv = fn_1_E5750((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s240);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        arg3(p_lbl_1_data_3DC98->s248, fn_1_E5758((void *)arg0));
        fv = fn_1_E5748((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s258);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        fv = fn_1_E57DC((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s260);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        fv = fn_1_E5760((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s268);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, ((1)[fv]));
        arg3(p_lbl_1_data_3DC98->s230, ((2)[fv]));
        arg3(p_lbl_1_data_3DC98->s270, fn_1_E57E4((void *)arg0));
        fv = fn_1_E5768((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s280);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        arg3(p_lbl_1_data_3DC98->s288, *(u32 *)(arg0 + 0x100));
        arg3(p_lbl_1_data_3DC98->s294);
        arg3(p_lbl_1_data_3DC98->s228, *(f32 *)(arg0 + 0x128));
        arg3(p_lbl_1_data_3DC98->s228, *(f32 *)(arg0 + 0x12c));
        arg3(p_lbl_1_data_3DC98->s230, *(f32 *)(arg0 + 0x130));
        loc_8[0] = 0;
        v1 = *(u32 *)(arg0 + 316);
        if ((*(u64 *)((u8 *)arg0 + 312) & 0x80000000) != 0) {
            strcpy(loc_8, (const char *)p_lbl_1_data_3DC98->s29c);
        }
        v2 = *(u32 *)(arg0 + 316);
        if ((*(u64 *)(arg0 + 312) & 0x40000000) != 0) {
            strcat(loc_8, (const char *)p_lbl_1_data_3DC98->s2a4);
        }
        v0 = *(u32 *)(arg0 + 316);
        if ((*(u64 *)(arg0 + 312) & 0x20000000) != 0) {
            strcat(loc_8, (const char *)(p_lbl_1_data_3DC98->s2ac));
        }
        arg3(p_lbl_1_data_3DC98->s2b4, loc_8);
        arg3(p_lbl_1_data_3DC98->s2c0);
        v3 = 0;
        while ((s16)v3 < 32) {
            t24 = fn_1_E57C4((void *)arg0);
            v4 = v3;
            if (((1 << v4) & t24) != 0) {
                arg3(p_lbl_1_data_3DC98->s2c8, v4);
            }
            v3++;
        }
        arg3(p_lbl_1_data_3DC98->s2cc);
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_1_E4A38 */

/* fzgx:begin fn_1_E50F0 */
void fn_1_E50F0(void *base, void *arg) {
    struct {
        f32 values[2];
        u32 pad[2];
    } locals;

    lbl_8006DCA4(base, arg);
    fn_1_A71AC();
    fn_8006F828((char *)base + 0x54, locals.values);
    fn_1_E4A38(base, locals.values[0], locals.values[1], arg);
}
/* fzgx:end fn_1_E50F0 */

/* fzgx:begin fn_1_E5164 */
typedef struct {
    f32 v0;
    f32 v1;
    f32 v2;
} Out;

typedef struct {
    u32 v[47];
} Tab;

typedef struct {
    u8 pad[0x138];
    u64 flags;
} Obj;

extern void lbl_8006DCA4(void *base, void *arg);
extern void fn_1_A71AC(void);
extern void fn_8006F828(void *base, f32 *out);
extern u8 lbl_1_rodata_69D0[188];
extern void fn_1_4AE0C(const char *, ...);
extern const f64 lbl_1_rodata_6800;
extern void fn_1_496FC(f32, f32);
extern const f32 lbl_1_rodata_69CC;
extern void fn_1_4955C(f32, f32);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8EF8(s32, s32);

void fn_1_E5164(void *arg0, void *arg1) {
    Out out;
    struct { s16 value; } i;
    Tab tab;
    s32 v1;
    s32 v0;

    lbl_8006DCA4(arg0, arg1);
    fn_1_A71AC();
    fn_8006F828((u8 *)arg0 + 0x54, &out.v0);
    v1 = out.v1;
    v0 = out.v0;
    tab = *(Tab *)&lbl_1_rodata_69D0;

    if (arg1 == fn_1_4AE0C) {
        fn_1_496FC((s16)v0, (s16)v1);
        fn_1_4955C(lbl_1_rodata_69CC, lbl_1_rodata_69CC);
    } else if (arg1 == fn_1_A8DD4) {
        fn_1_A8EF8(v0, v1);
    }

    for (i.value = 0; i.value < 0x40; i.value++) {
        if (((Obj *)arg0)->flags & (1 << i.value)) {
            ((void (*)(void *, u32, ...))arg1)(&lbl_1_data_3E150, tab.v[i.value]);
        }
    }
}
/* fzgx:end fn_1_E5164 */

/* fzgx:begin fn_1_E52F8 noprologue */
#include "types.h"
#include "rel/main_rel/phys.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
    s = 0.9999998807907104f;
    s = 1.0000001192092896f;
    s = -1.0000001192092896f;
    s = -0.9999998807907104f;
    s = 0.0f;
    d = 1.1920928955078125e-07;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 10.0f;
    s = 182.04444885253906f;
    d = 4503599627370496.0;
    s = -0.0027222223579883575f;
}
static const u32 fzgx_pool_table6[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.58738019107841e-05f;
    s = 1.5f;
    s = -1.1920928955078125e-07f;
    s = 1.1920928955078125e-07f;
    d = 4503601774854144.0;
    s = 60.0f;
    s = 1000000.0f;
    s = 250000.0f;
    s = 20.0f;
}
static const u32 fzgx_pool_table8[6] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.009999999776482582f;
    s = 0.009999999776482582f;
    s = -1.0099999904632568f;
    s = 9.999999747378752e-05f;
}
static const u32 fzgx_pool_table10[3] = {0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9900000095367432f;
    s = 2.0f;
    s = -0.0f;
    d = 216.0;
    d = 3.1415927410125732;
    d = 4.0;
    d = 60.0;
    s = 1.0099999904632568f;
    s = 0.05000000074505806f;
    s = 1.0010000467300415f;
    s = 0.8999999761581421f;
    s = 3.0f;
}
static const u32 fzgx_pool_table12[6] = {0x3FE00000, 0x40F00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40A00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 0.0016666667070239782f;
    s = 0.30000001192092896f;
    s = 0.01666666753590107f;
    s = 10000000.0f;
    s = 5000000.0f;
    s = 100.0f;
}
static const u32 fzgx_pool_table14[43] = {0x00000000, 0x3F800000, 0x00000000, 0x01060002, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x00FE0001, 0x005800A6, 0x005800A6, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005A00A8, 0x005C00A8, 0x01000002, 0x005F00A8, 0x005C00A8, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x01020002, 0x00020103, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.01745329238474369f;
    s = -3.0f;
}
static const u32 fzgx_pool_table16[8] = {0x40400000, 0xC0400000, 0x40400000, 0x41200000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 224.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 255.0f;
    s = 640.0f;
    s = 480.0f;
    s = 1.2705882787704468f;
}
static const u32 fzgx_pool_table20[3] = {0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f32 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -10000.0f;
    s = 22500.0f;
    s = 10430.3779296875f;
    s = 0.4000000059604645f;
}
#pragma section code_type ".text"

typedef struct {
    u8 unk_00[0x50];
    f32 unk_50;
    u8 unk_54[0x10];
} Sig_fn_1_E52F8_Arg;

typedef struct {
    f32 value0;
    f32 value1;
    f32 value2;
} Sig_fn_8006F828_Fn8006F828Data;

extern void lbl_8006DCA4(void *base, void *arg);
extern f32 fn_1_A71AC(void);
extern void fn_8006F828(void *base, Sig_fn_8006F828_Fn8006F828Data *out);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8EF8(s16 a, s16 b);
extern void fn_1_496FC(f32 a, f32 b);
extern void fn_1_4955C(f32 a, f32 b);
extern f32 __fabsf(f32);

void fn_1_E52F8(Sig_fn_1_E52F8_Arg *arg0, void (*fmt)(const char *, ...))
{
    Sig_fn_8006F828_Fn8006F828Data v;
    s16 b;
    s16 a;

    lbl_8006DCA4(arg0, fmt);
    fn_1_A71AC();
    fn_8006F828(arg0->unk_54, &v);
    b = v.value1;
    a = v.value0;
    if (fmt == fn_1_4AE0C) {
        fn_1_496FC(a, b);
        fn_1_4955C(0.4f, 0.4f);
    } else if (fmt == fn_1_A8DD4) {
        fn_1_A8EF8(a, b);
    }
    if (__fabsf(arg0->unk_50) < 1.1920928955078125e-07) {
        return;
    }
    fmt((const char *)lbl_1_data_3E154, 216.0 * arg0->unk_50);
    fmt((const char *)lbl_1_data_3E160, arg0->unk_50);
}
/* fzgx:end fn_1_E52F8 */

/* fzgx:begin fn_1_E5430 */
s16 fn_1_E5430(s16 index) {
    Obj_1_bss_7AE88 *obj = &lbl_1_bss_7AE88;

    switch (index) {
    case 0:
        return obj->unk_4;
    case 1:
        return obj->unk_C;
    case 2:
        return obj->unk_14;
    case 3:
        return obj->unk_1C;
    case 4:
        return obj->unk_24;
    case 5:
        return obj->unk_2C;
    default:
        return -1;
    }
}
/* fzgx:end fn_1_E5430 */

/* fzgx:begin fn_1_E54A8 */
void *fn_1_E54A8(s16 type, s16 index) {
    Obj_1_bss_7AE88 *base = &lbl_1_bss_7AE88;

    switch (type) {
    case 0:
        return (void *)(base->unk_0 + index * 0x1a8);
    case 1:
        return (void *)(base->unk_8 + index * 0x1a8);
    case 2:
        return ((char *)base->unk_10 + index * 0x1a8);
    case 3:
        return (void *)(base->unk_18 + index * 0x1a8);
    case 4:
        return (void *)(base->unk_20 + index * 0x1a8);
    case 5:
        return (void *)(base->unk_28 + index * 0x1a8);
    default:
        return (void *)0;
    }
}
/* fzgx:end fn_1_E54A8 */

/* fzgx:begin fn_1_E5568 */
extern void lbl_8006DCA4(void *base, void *arg);
extern void fn_1_A71AC(void);
extern void fn_8006F828(void *base, f32 *out);
extern void fn_1_E4A38(void *base, s32 x, s32 y, void *arg);
extern void fn_80008BEC(void *dst, void *value, u32 size);
extern void fn_80008BA8(void *dst, void *value, u32 size);
extern f32 lbl_1_rodata_67A8;
extern u32 lbl_1_rodata_6A8C[3];
extern u32 strstr(const u8* left, const char* right);
extern u32 strlen(const char* string);
extern void fn_1_8CED0(void* object, s32 value0, s32 value1);
extern void fn_1_8D0A4(void* object);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80072EDC(u32, s32);
extern void fn_800745A4(u32, s32, s32, u32, s32, s32);
extern void fn_80073778(void *, u32);
extern void fn_80015C1C(void *, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void lbl_8006DFFC(void *, void *, void *);
extern void GXLoadTexMtxImm(void *, u32, s32);
extern f32 lbl_1_rodata_6780[236];
extern f32 fn_1_A6FE8(void);
extern void fn_1_E8938(void);
extern void fn_1_8D1C8(void *object, void (*callback)(void), int arg);
extern u32 fn_1_3F8C0(void);
extern u32 fn_80008E84(u32 value);
extern u32 lbl_1_bss_7C94C[67];
extern void fn_1_EE530(void);
extern u8 lbl_1_bss_7ECB4[72];
extern void fn_1_BC29C(u8 *);
extern void fn_1_B9C0C(void);
extern void fn_1_1596DC(s32);
extern void fn_1_484CC(s32);

extern void fn_80008BEC(void *dst, void *value, u32 size);
extern void fn_80008BA8(void *dst, void *value, u32 size);

extern f32 lbl_1_rodata_67A8;
extern u32 lbl_1_rodata_6A8C[3];
extern void fn_80008BA8(void *dst, void *value, u32 size);
extern void fn_1_12EF80(s16 arg, s16 *out_group, s16 *out_entry);
extern void fn_1_9C724(void);
extern void fn_1_DD890(void *);
extern void fn_1_9CC40(void);

typedef struct { u8 pad[0x138]; u64 flags; u8 tail[0x68]; } E5568Entry;
static inline s16 E5568Count(s16 id, Obj_1_bss_7AE88 *p) {
 switch(id) {
 case 0: return p->unk_4;
 case 1: return p->unk_C;
 case 2: return p->unk_14;
 case 3: return p->unk_1C;
 case 4: return p->unk_24;
 case 5: return p->unk_2C;
 default: return -1;
 }
}
static inline E5568Entry *E5568Base(s16 id, Obj_1_bss_7AE88 *p) {
 switch(id) {
 case 0: return (E5568Entry *)p->unk_0;
 case 1: return (E5568Entry *)p->unk_8;
 case 2: return (E5568Entry *)p->unk_10;
 case 3: return (E5568Entry *)p->unk_18;
 case 4: return (E5568Entry *)p->unk_20;
 case 5: return (E5568Entry *)p->unk_28;
 default: return 0;
 }
}
static inline s16 E5568FlagCount(s16 id, Obj_1_bss_7AE88 *p, u64 mask, u64 zero) {
 s32 i;
 s16 count = 0;
 s16 n = E5568Count(id, p);
 E5568Entry *base = E5568Base(id, p);
 for(i = 0; (s16)i < n; i++, base++) {
  if((base->flags & mask) != zero) count++;
 }
 return count;
}
s16 fn_1_E5568(s16 id) {
 Obj_1_bss_7AE88 *p = &lbl_1_bss_7AE88;
 s16 total = E5568Count(id, p);
 s16 count = E5568FlagCount(id, p, 0x800000000ULL, 0);
 return count == -1 ? count : (s16)(total - count);
}
/* fzgx:end fn_1_E5568 */

/* fzgx:begin fn_1_E5724 */
s16 fn_1_E5724(void *base) {
    return *(s16 *)((char *)base + 0x8);
}
/* fzgx:end fn_1_E5724 */

/* fzgx:begin fn_1_E572C */
s16 fn_1_E572C(void *base) {
    return *(s16 *)((char *)base + 0xA);
}
/* fzgx:end fn_1_E572C */

/* fzgx:begin fn_1_E5734 */
typedef struct {
    u32 unk0;
    f32 value;
} E5734Obj;

// Returns the float at offset 4 of the object.
f32 fn_1_E5734(E5734Obj *self) {
    return self->value;
}
/* fzgx:end fn_1_E5734 */

/* fzgx:begin fn_1_E573C */
typedef struct {
    u8 unk0[0x100];
    s32 value;
} E573CObj;

s16 fn_1_E573C(E573CObj *self) {
    return self->value;
}
/* fzgx:end fn_1_E573C */

/* fzgx:begin fn_1_E5748 */
// Returns a pointer to the member at offset 0x54.
u8 *fn_1_E5748(u8 *self) {
    return self + 0x54;
}
/* fzgx:end fn_1_E5748 */

/* fzgx:begin fn_1_E5750 */
// Returns a pointer to the member at offset 0x44.
u8 *fn_1_E5750(u8 *self) {
    return self + 0x44;
}
/* fzgx:end fn_1_E5750 */

/* fzgx:begin fn_1_E5758 */
f32 fn_1_E5758(u8 *self) {
    return *(f32 *)(self + 0x50);
}
/* fzgx:end fn_1_E5758 */

/* fzgx:begin fn_1_E5760 */
u8 *fn_1_E5760(u8 *self) {
    return self + 0x78;
}
/* fzgx:end fn_1_E5760 */

/* fzgx:begin fn_1_E5768 */
u8 *fn_1_E5768(u8 *self) {
    return self + 0xF4;
}
/* fzgx:end fn_1_E5768 */

/* fzgx:begin fn_1_E5770 */
struct fn_1_E5770_Arg0 {
    u8 pad_0[0x138];
    u64 unk_138;
};

s32 fn_1_E5770(struct fn_1_E5770_Arg0 *arg0, u32 arg1, u64 mask) {
    return (arg0->unk_138 & mask) ? 1 : 0;
}
/* fzgx:end fn_1_E5770 */

/* fzgx:begin fn_1_E57A4 */
f32 fn_1_E57A4(void *base) {
    return *(f32 *)((char *)base + 0x18);
}
/* fzgx:end fn_1_E57A4 */

/* fzgx:begin fn_1_E57AC */
f32 fn_1_E57AC(void *base) {
    return *(f32 *)((char *)base + 0x1c);
}
/* fzgx:end fn_1_E57AC */

/* fzgx:begin fn_1_E57B4 */
f32 fn_1_E57B4(void *base) {
    return *(f32 *)((char *)base + 0x20);
}
/* fzgx:end fn_1_E57B4 */

/* fzgx:begin fn_1_E57BC */
f32 fn_1_E57BC(void *base) {
    return *(f32 *)((char *)base + 0x24);
}
/* fzgx:end fn_1_E57BC */

/* fzgx:begin fn_1_E57C4 */
u32 fn_1_E57C4(void *base) {
    return *(u32 *)((char *)base + 0x148);
}
/* fzgx:end fn_1_E57C4 */

/* fzgx:begin fn_1_E57CC */
void *fn_1_E57CC(void *base) {
    return (char *)base + 0x2c;
}
/* fzgx:end fn_1_E57CC */

/* fzgx:begin fn_1_E57D4 */
void *fn_1_E57D4(void *base) {
    return (char *)base + 0x38;
}
/* fzgx:end fn_1_E57D4 */

/* fzgx:begin fn_1_E57DC */
void *fn_1_E57DC(void *base) {
    return (char *)base + 0x6c;
}
/* fzgx:end fn_1_E57DC */

/* fzgx:begin fn_1_E57E4 */
f32 fn_1_E57E4(void *base) {
    return *(f32 *)((char *)base + 0x84);
}
/* fzgx:end fn_1_E57E4 */

/* fzgx:begin fn_1_E57EC */
f32 fn_1_E57EC(void *base) {
    return *(f32 *)((char *)base + 0x28);
}
/* fzgx:end fn_1_E57EC */

/* fzgx:begin fn_1_E57F4 */
void fn_1_E57F4(void *base, f32 value) {
    *(f32 *)((char *)base + 0x4) = value;
}
/* fzgx:end fn_1_E57F4 */

/* fzgx:begin fn_1_E57FC */
// Initializes the object's 12-byte value, clearing it or copying from the source.
void fn_1_E57FC(void *object, void *source) {
    if (source == 0) {
        fn_80008BEC((u8 *)object + 0x44, 0, 0xc);
    } else {
        fn_80008BA8((u8 *)object + 0x44, source, 0xc);
    }
}
/* fzgx:end fn_1_E57FC */

/* fzgx:begin fn_1_E5840 */
// Clears or copies the object's 12-byte value at offset 0x78.
void fn_1_E5840(void *base, const void *value) {
    if (value == 0) {
        fn_80008BEC((char *)base + 0x78, 0, 0xc);
    } else {
        fn_80008BA8((char *)base + 0x78, (void *)value, 0xc);
    }
}
/* fzgx:end fn_1_E5840 */

/* fzgx:begin fn_1_E5884 */
// Resets the object's three-component value or copies a replacement into it.
void fn_1_E5884(void *base, void *value) {
    if (value == 0) {
        f32 reset_value = lbl_1_rodata_67A8;

        *(f32 *)((char *)base + 0xfc) = reset_value;
        *(f32 *)((char *)base + 0xf8) = reset_value;
        *(f32 *)((char *)base + 0xf4) = reset_value;
    } else {
        fn_80008BA8((char *)base + 0xf4, value, 0xc);
    }
}
/* fzgx:end fn_1_E5884 */

/* fzgx:begin fn_1_E58CC */
// Copies the supplied three-word value, or the shared default when no value is provided.
void fn_1_E58CC(void *base, const void *value) {
    if (value == 0) {
        u32 default_value[3];

        default_value[0] = lbl_1_rodata_6A8C[0];
        default_value[1] = lbl_1_rodata_6A8C[1];
        default_value[2] = lbl_1_rodata_6A8C[2];
        fn_80008BA8((char *)base + 0x128, default_value, 0xc);
    } else {
        fn_80008BA8((char *)base + 0x128, (void *)value, 0xc);
    }
}
/* fzgx:end fn_1_E58CC */

/* fzgx:begin fn_1_E5930 */
void fn_1_E5930(void *base, u32 unused, u32 mask138, u32 mask13c) {
    u32 value13c = *(u32 *)((char *)base + 0x13c);
    u32 value138 = *(u32 *)((char *)base + 0x138);
    *(u32 *)((char *)base + 0x13c) = value13c | mask13c;
    *(u32 *)((char *)base + 0x138) = value138 | mask138;
}
/* fzgx:end fn_1_E5930 */

/* fzgx:begin fn_1_E594C */
struct fn_1_E594C_Arg0 {
    u8 pad_0[0x138];
    u32 unk_138;
    u32 unk_13C;
};

#pragma opt_propagation off
#pragma peephole off
void fn_1_E594C(struct fn_1_E594C_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    s32 inv2;
    u32 value138;
    s32 inv3;
    u32 value13c;

    value13c = arg0->unk_13C;
    inv3 = ~arg3;
    value138 = arg0->unk_138;
    inv2 = ~arg2;
    arg0->unk_13C = ((value13c) & inv3);
    arg0->unk_138 = ((value138) & inv2);
}
#pragma peephole reset

#pragma opt_propagation reset
/* fzgx:end fn_1_E594C */

/* fzgx:begin fn_1_E5970 */
void fn_1_E5970(void *base, f32 value) {
    *(f32 *)((char *)base + 0x18) = value;
}
/* fzgx:end fn_1_E5970 */

/* fzgx:begin fn_1_E5978 */
void fn_1_E5978(void *base, f32 value) {
    *(f32 *)((char *)base + 0x1c) = value;
}
/* fzgx:end fn_1_E5978 */

/* fzgx:begin fn_1_E5980 */
// fn_1_E5980: Store float value at offset 0x20 in base pointer
void fn_1_E5980(void *base, f32 value) {
    *(f32 *)((char *)base + 0x20) = value;
}
/* fzgx:end fn_1_E5980 */

/* fzgx:begin fn_1_E5988 */
void fn_1_E5988(void *base, void *value) {
    if (value == NULL) {
        fn_80008BEC(((char *)base + 0x54), NULL, 0xC);
    } else {
        fn_80008BA8(((char *)base + 0x54), value, 0xC);
    }

    if (value == NULL) {
        fn_80008BEC(((char *)base + 0x60), NULL, 0xC);
    } else {
        fn_80008BA8(((char *)base + 0x60), value, 0xC);
    }
}
/* fzgx:end fn_1_E5988 */

/* fzgx:begin fn_1_E5A0C */
void fn_1_E5A0C(void *base, void *value) {
    if (value == NULL) {
        fn_80008BEC(((char *)base + 0x2C), NULL, 0xC);
    } else {
        fn_80008BA8(((char *)base + 0x2C), value, 0xC);
    }
}
/* fzgx:end fn_1_E5A0C */

/* fzgx:begin fn_1_E5A50 */
void fn_1_E5A50(void *base, void *value) {
    if (value == NULL) {
        fn_80008BEC(((char *)base + 0x38), NULL, 0xC);
    } else {
        fn_80008BA8(((char *)base + 0x38), value, 0xC);
    }
}
/* fzgx:end fn_1_E5A50 */

/* fzgx:begin fn_1_E5A94 */
void fn_1_E5A94(void *base, void *value) {
    if (value == NULL) {
        fn_80008BEC(((char *)base + 0x6C), NULL, 0xC);
    } else {
        fn_80008BA8(((char *)base + 0x6C), value, 0xC);
    }
}
/* fzgx:end fn_1_E5A94 */

/* fzgx:begin fn_1_E5AD8 */
void fn_1_E5AD8(void *base, f32 value) {
    *(f32 *)((char *)base + 0x28) = value;
}
/* fzgx:end fn_1_E5AD8 */

/* fzgx:begin fn_1_E5AE0 */
extern u32 lbl_1_rodata_6A98[50];
extern void fn_1_57714(u8 arg);
extern f32 lbl_1_rodata_67B4[19];
extern const f64 lbl_1_rodata_6800;
typedef struct { f32 x; f32 y; f32 z; } E5AE0Vec;
extern void fn_1_5773C(E5AE0Vec *a, E5AE0Vec *b, u8 *c);

#pragma opt_common_subs off
void fn_1_E5AE0(s16 a, s16 b, f32 w, f32 h) {
    u32 flag = ((lbl_1_rodata_6A98)[0]);
    E5AE0Vec o1;
    E5AE0Vec o2;
    s16 i;
    f32 xpos;
    f32 zpos;
    f32 stepx;
    f32 stepz;
    f32 cur;

    fn_1_57714(6);
    stepx = w / a;
    stepz = h / b;
    xpos = lbl_1_rodata_67B4[0] * -w;
    zpos = lbl_1_rodata_67B4[0] * -h;
    cur = xpos;
    for (i = 0; i < a + 1; i++) {
        fn_80008BEC(&o1, 0, 0xC);
        fn_80008BEC(&o2, 0, 0xC);
        o2.x = cur;
        o1.x = cur;
        o1.z = zpos;
        o2.z = -zpos;
        fn_1_5773C(&o1, &o2, (u8 *)&flag);
        cur += stepx;
    }
    for (i = 0; i < b + 1; i++) {
        fn_80008BEC(&o1, 0, 0xC);
        fn_80008BEC(&o2, 0, 0xC);
        o2.z = zpos;
        o1.z = zpos;
        o1.x = xpos;
        o2.x = -xpos;
        fn_1_5773C(&o1, &o2, (u8 *)&flag);
        zpos += stepz;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_E5AE0 */

/* fzgx:begin fn_1_E5CC4 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} E5CC4Vec;

/* local view of one physics object (0x1A8 bytes) */
typedef struct {
    u8 pad_0[0x8];
    s16 unk_8;
    s16 unk_A;
    s16 unk_C;
    u8 pad_E[0xA];
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    E5CC4Vec unk_2C;
    E5CC4Vec unk_38;
    E5CC4Vec unk_44;
    f32 unk_50;
    E5CC4Vec unk_54;
    E5CC4Vec unk_60;
    E5CC4Vec unk_6C;
    E5CC4Vec unk_78;
    f32 unk_84;
    E5CC4Vec unk_88;
    u8 pad_94[0x30];
    u8 unk_C4[0x30];
    E5CC4Vec unk_F4;
    u8 pad_100[0x28];
    E5CC4Vec unk_128;
    u8 pad_134[0x4];
    u64 unk_138;
    u8 pad_140[0x4];
    u32 unk_144;
    u32 unk_148;
    u32 unk_14C;
    u32 unk_150;
    u8 pad_154[0x4];
    u32 unk_158;
    u8 pad_15C[0x44];
    f32 unk_1A0;
    f32 unk_1A4;
} E5CC4Obj;

/* local view of lbl_1_bss_9F8 (pad input) */
typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[0x10];
    u16 unk_14;
    u8 pad_16[0x3A];
} E5CC4Pad;

extern u32 lbl_801A66A0;
extern u32 lbl_801A63C0;
extern E5CC4Pad lbl_1_bss_9F8;
extern E5CC4Vec lbl_1_data_3E184;
extern char lbl_1_data_3E190[];
extern void fn_80008BEC(void *dst, int value, u32 size);
extern void fn_80008BA8(void *dst, void *src, u32 size);
extern void fn_1_E1A00(void *obj, void *str);
extern void fn_1_DE4B0(E5CC4Obj *obj, E5CC4Vec *normal);
extern f32 lbl_8006D0B4(f32 value);
extern f32 lbl_8006D534(E5CC4Vec *a, E5CC4Vec *b);
extern void lbl_8006D5F0(E5CC4Vec *a, E5CC4Vec *out, f32 scale);
extern void lbl_8006D668(E5CC4Vec *vector);
extern void fn_1_E1934(E5CC4Obj *obj, E5CC4Obj *base, s16 limit);
extern s16 fn_1_DF2A4(E5CC4Vec *pos, E5CC4Vec *prev, void *mtx, E5CC4Vec *point, E5CC4Vec *normal,
                      E5CC4Vec *hit, E5CC4Vec *out, f32 radius, f32 height);
extern void lbl_8006D7DC(void *value);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E13C(void *);
extern void lbl_8006DB74(void *);

/* the retail TU's .bss objects this function uses, at their retail offsets, so MWCC addresses them off one section
 * base; the fzgx_pool_gap_ objects span the retail data in between, which this function does not touch */
u8 *fzgx_obj_lbl_1_bss_7AE88;
s16 lbl_1_bss_7AE88__fzgx_offset_4;
s16 fzgx_pool_gap_7AE8E;
u8 *lbl_1_bss_7AE88__fzgx_offset_8;
s16 lbl_1_bss_7AE88__fzgx_offset_C;
s16 fzgx_pool_gap_7AE96;
u8 *lbl_1_bss_7AE88__fzgx_offset_10;
s16 lbl_1_bss_7AE88__fzgx_offset_14;
s16 fzgx_pool_gap_7AE9E;
u8 *lbl_1_bss_7AE88__fzgx_offset_18;
s16 lbl_1_bss_7AE88__fzgx_offset_1C;
s16 fzgx_pool_gap_7AEA6;
u8 *lbl_1_bss_7AE88__fzgx_offset_20;
s16 lbl_1_bss_7AE88__fzgx_offset_24;
s16 fzgx_pool_gap_7AEAE;
u8 *lbl_1_bss_7AE88__fzgx_offset_28;
s16 lbl_1_bss_7AE88__fzgx_offset_2C;
s16 fzgx_pool_gap_7AEB6;
u8 fzgx_pool_gap_7AEB8[0x294];
s16 fzgx_obj_lbl_1_bss_7B14C;
s16 lbl_1_bss_7B14C__fzgx_offset_2;
E5CC4Vec lbl_1_bss_7B14C__fzgx_offset_4;
E5CC4Vec lbl_1_bss_7B14C__fzgx_offset_10;
f32 lbl_1_bss_7B14C__fzgx_offset_1C;
E5CC4Vec lbl_1_bss_7B14C__fzgx_offset_20;
s16 lbl_1_bss_7B14C__fzgx_offset_2C;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
}
static const u32 fzgx_pool_table2[5] = {0x3F7FFFFE, 0x3F800001, 0xBF800001, 0xBF7FFFFE, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 0.0f;
    s = 5.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[2] = {0x00FF00FF, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
}
static const u32 fzgx_pool_table6[1] = {0x41200000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
}
static const u32 fzgx_pool_table8[2] = {0x43300000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.0027222223579883575f;
}
static const u32 fzgx_pool_table10[13] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x38C90FDB, 0x3FC00000, 0xB4000000, 0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table12[29] = {0x42700000, 0x49742400, 0x48742400, 0x41A00000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0xBC23D70A, 0x3C23D70A, 0xBF8147AE, 0x38D1B717, 0x00000000, 0x3F800000, 0x00000000, 0x3F7D70A4, 0x40000000, 0x80000000, 0x406B0000, 0x00000000, 0x400921FB, 0x60000000, 0x40100000, 0x00000000, 0x404E0000, 0x00000000, 0x3F8147AE};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
}
static const u32 fzgx_pool_table14[2] = {0x3F8020C5, 0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.0f;
}
static const u32 fzgx_pool_table16[56] = {0x3FE00000, 0x40F00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40A00000, 0x3F4CCCCD, 0x3ADA740E, 0x3E99999A, 0x3C888889, 0x4B189680, 0x4A989680, 0x42C80000, 0x00000000, 0x3F800000, 0x00000000, 0x01060002, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x00FE0001, 0x005800A6, 0x005800A6, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005A00A8, 0x005C00A8, 0x01000002, 0x005F00A8, 0x005C00A8, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x01020002, 0x00020103, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.01745329238474369f;
}
static const u32 fzgx_pool_table18[22] = {0xC0400000, 0x40400000, 0xC0400000, 0x40400000, 0x41200000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3F000000, 0x43A00000, 0x43600000, 0x00000000, 0x43700000, 0x437F0000, 0x44200000, 0x43F00000, 0x3FA2A2A3, 0x00000000, 0x3F800000, 0x00000000, 0xC61C4000, 0x46AFC800};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10430.3779296875f;
}
static const u32 fzgx_pool_table20[48] = {0x3ECCCCCD, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
/* the default-up image fn_1_E58CC copies, then fn_1_E5AE0's table head */
const E5CC4Vec lbl_1_rodata_6A8C = {0.0f, 1.0f, 0.0f};
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table90[4] = {0xFFFFFFFF, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep90(void) { const u32 *volatile cp; cp = fzgx_pool_table90; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7AE88;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_4;
    s = *(u8 *)&fzgx_pool_gap_7AE8E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_C;
    s = *(u8 *)&fzgx_pool_gap_7AE96;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_14;
    s = *(u8 *)&fzgx_pool_gap_7AE9E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_18;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_1C;
    s = *(u8 *)&fzgx_pool_gap_7AEA6;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_24;
    s = *(u8 *)&fzgx_pool_gap_7AEAE;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_28;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2C;
    s = *(u8 *)&fzgx_pool_gap_7AEB6;
    s = *(u8 *)&fzgx_pool_gap_7AEB8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B14C;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_2C;
}
#pragma section code_type ".text"
#pragma opt_propagation off

/* fn_1_E57FC, fn_1_E5988 and fn_1_E58CC, which retail inlines here */
static inline void E5CC4_set_vel(E5CC4Obj *obj, E5CC4Vec *value) {
    if (value == 0) {
        fn_80008BEC(&obj->unk_44, 0, 0xC);
    } else {
        fn_80008BA8(&obj->unk_44, value, 0xC);
    }
}

static inline void E5CC4_set_pos(E5CC4Obj *obj, E5CC4Vec *value) {
    if (value == 0) {
        fn_80008BEC(&obj->unk_54, 0, 0xC);
    } else {
        fn_80008BA8(&obj->unk_54, value, 0xC);
    }
    if (value == 0) {
        fn_80008BEC(&obj->unk_60, 0, 0xC);
    } else {
        fn_80008BA8(&obj->unk_60, value, 0xC);
    }
}

static inline void E5CC4_set_up(E5CC4Obj *obj, E5CC4Vec *value) {
    if (value == 0) {
        E5CC4Vec up = lbl_1_rodata_6A8C;
        fn_80008BA8(&obj->unk_128, &up, 0xC);
    } else {
        fn_80008BA8(&obj->unk_128, value, 0xC);
    }
}

static inline s32 E5CC4_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

static inline void E5CC4_place(E5CC4Obj *e, f32 scale, s32 n) {
    e->unk_54.x = (f32)(scale * (e->unk_8 % n)) - 0.5f * scale * n;
    e->unk_54.y = scale * (e->unk_8 / (n * n));
    e->unk_54.z = (f32)(scale * ((e->unk_8 % (n * n)) / n)) - 0.5f * scale * n;
    fn_80008BA8(&e->unk_60, &e->unk_54, 0xC);
}

static inline f32 E5CC4_len2(E5CC4Vec *v) {
    f32 x = v->x;
    f32 sq = x * x;
    f32 y = v->y;
    f32 z = v->z;

    sq = y * y + sq;
    sq = z * z + sq;
    return sq;
}

static inline f32 E5CC4_dot(E5CC4Vec *a, E5CC4Vec *b) {
    f32 result;
    f32 ax;
    f32 bx;
    f32 ay;
    f32 by;
    f32 az;
    f32 bz;

    ax = a->x;
    bx = b->x;
    ay = a->y;
    by = b->y;
    az = a->z;
    bz = b->z;
    result = ax * bx;
    result += ay * by;
    result += az * bz;
    return result;
}

/* out = a x b, all inputs read before the stores */
static inline void E5CC4_cross(E5CC4Vec *a, E5CC4Vec *b, E5CC4Vec *out) {
    E5CC4Vec *v = b;
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = v->x;
    f32 by;
    f32 bz = v->z;
    f32 ax = a->x;
    f32 x;
    f32 y;
    f32 z;

    by = v->y;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    x = ay * bz;
    x -= az * by;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline f32 E5CC4_min1(f32 x) {
    if (x < 1.0f) {
        return x;
    }
    return 1.0f;
}

/* out = (a x b) x b, normalised */
static inline void E5CC4_perp(E5CC4Vec *a, E5CC4Vec *b, E5CC4Vec *out) {
    E5CC4Vec *n = out;

    E5CC4_cross(a, b, out);
    E5CC4_cross(out, b, out);
    if (E5CC4_len2(out) > 0.0f) {
        lbl_8006D668(n);
    }
}

/* c = the part of src along the surface, pointing the way src goes, scaled to len */
static inline void E5CC4_flip(E5CC4Vec *v) {
    psvec_scale(v, -1.0f, v);
}

static inline void E5CC4_deflect(E5CC4Vec *src, E5CC4Vec *up, E5CC4Vec *c, f32 len, f32 side) {
    E5CC4Vec v;

    fn_80008BA8(&v, src, 12);
    E5CC4_perp(&v, up, c);
    if (!(E5CC4_dot(&v, c) > 0.0f)) {
        E5CC4_flip(c);
    }
    psvec_scale(c, len * side, c);
}

static inline s32 E5CC4_stop(E5CC4Vec *v, f32 lim) {
    E5CC4Vec *p;

    if (lim < 0.0f) {
        return 0;
    }
    p = v;
    if (E5CC4_len2(v) <= lim * lim) {
        fn_80008BEC(p, 0, 12);
        return 1;
    }
    return 0;
}

/* signed distance of p above the plane through o with normal n */
static inline void E5CC4_plane_dist(E5CC4Vec *p, E5CC4Vec *o, E5CC4Vec *n, f32 *dist) {
    E5CC4Vec d;

    psvec_sub(p, o, &d);
    *dist = E5CC4_dot(&d, n);
}

/* height of the object above the floor plane */
static inline void E5CC4_floor_dist(E5CC4Obj *e, E5CC4Vec *n, f32 *dist) {
    E5CC4_plane_dist(&e->unk_54, &lbl_1_data_3E184, n, dist);
}

#pragma inline_max_size(2000)
static inline void E5CC4_land(E5CC4Obj *e, E5CC4Vec *up, E5CC4Vec *push) {
    f32 lim;
    f32 dot;
    f32 side;
    f32 k;
    f32 len;
    E5CC4Vec n;
    E5CC4Vec c;

    psvec_add(&e->unk_54, push, &e->unk_54);
    lim = 0.05f * e->unk_18;
    if ((e->unk_138 & 0x8000) == 0) {
        dot = lbl_8006D534(&e->unk_44, up);
        if (!(dot > 0.0f)) {
            side = lbl_8006D0B4(1.0f - (f32)(dot * dot));
            len = e->unk_50;
            k = len * -e->unk_18;
            fn_80008BA8(&n, up, 12);
            lbl_8006D5F0(&n, &n, k * dot);
            E5CC4_deflect(&e->unk_44, up, &c, len, side);
            if (E5CC4_stop(&n, lim) == 1) {
                e->unk_138 |= 0x8000;
                if ((e->unk_138 & 0x8000000) == 0) {
                    e->unk_138 |= 0x100000000ULL;
                }
            }
            psvec_add(&n, &c, &e->unk_44);
            psvec_scale(&e->unk_6C, 1.0f - e->unk_20, &e->unk_6C);
        }
    }
}

#pragma inline_max_size(2000)
static inline void E5CC4_move(E5CC4Obj *e) {
    f32 len;
    f32 dot;
    f32 push;
    f32 side;
    f32 k;
    E5CC4Vec tmp;
    E5CC4Vec c;
    E5CC4Vec f;
    E5CC4Vec s;
    E5CC4Vec g;

    if ((e->unk_138 & 8) == 0) {
        psvec_scale(&e->unk_128, -0.0027222223579883575f * e->unk_1C, &g);
        psvec_add(&e->unk_2C, &g, &e->unk_2C);
    }
    if (0.0f != e->unk_28 && (e->unk_138 & 0x100) == 0) {
        psvec_scale(&e->unk_44, -e->unk_28, &f);
        psvec_add(&e->unk_2C, &f, &e->unk_2C);
        psvec_scale(&e->unk_6C, -E5CC4_min1(e->unk_28 / e->unk_1C), &s);
        psvec_add(&e->unk_6C, &s, &e->unk_6C);
    }
    fn_1_DE4B0(e, &lbl_1_bss_7B14C__fzgx_offset_4);
    if ((e->unk_138 & 0x8000) != 0) {
        len = lbl_8006D0B4(E5CC4_len2(&e->unk_2C));
        if ((e->unk_138 & 0x10000000) == 0 || 0.0f != len) {
            dot = lbl_8006D534(&e->unk_2C, &lbl_1_bss_7B14C__fzgx_offset_4);
            if (!(dot > 0.0f)) {
                k = -(((e->unk_138 & 0x10000000) != 0) ? e->unk_20 : e->unk_24);
                push = dot * (k * len);
                side = lbl_8006D0B4(1.0f - (f32)(dot * dot));
                E5CC4_deflect(&e->unk_2C, &lbl_1_bss_7B14C__fzgx_offset_4, &c, len, side);
                fn_80008BA8(&e->unk_2C, &c, 12);
                if ((e->unk_138 & 0x10000000) != 0) {
                    lbl_8006D5F0(&e->unk_2C, &tmp, -push);
                } else {
                    lbl_8006D5F0(&e->unk_44, &tmp, -push);
                }
                psvec_add(&tmp, &e->unk_2C, &e->unk_2C);
            }
        }
    }
    if ((e->unk_138 & 0x2000) == 0) {
        psvec_scale(&e->unk_2C, 1.0f / e->unk_1C, &e->unk_38);
        psvec_add(&e->unk_44, &e->unk_38, &e->unk_44);
    }
}

void fn_1_E5CC4(E5CC4Obj *objs, s16 count) {
    E5CC4Obj *p;
    E5CC4Obj *mover;
    E5CC4Obj *collider;
    E5CC4Obj *lander;
    E5CC4Obj *q;
    E5CC4Obj *e;
    s16 j;
    s16 i;
    E5CC4Vec hit2;
    E5CC4Vec hit;
    f32 mtx[3][4];
    s16 res;
    f32 dist;
    f32 r;
    E5CC4Vec *n;
    s32 touch;

    if (count <= 0) {
        return;
    }

    for (p = objs, i = 0; i < count; p++, i++) {
        p->unk_148 = 0;
        if ((p->unk_138 & 2) == 0) {
            if ((p->unk_138 & 0x40000000) != 0) {
                p->unk_14C = lbl_801A66A0;
            }
            if (lbl_801A66A0 - p->unk_14C > 4) {
                p->unk_138 &= ~0x8000ULL;
                p->unk_138 &= ~0x8000000ULL;
            }
            if ((p->unk_138 & 0x8000) != 0) {
                p->unk_150 = lbl_801A66A0;
            }
            if (lbl_801A66A0 - p->unk_150 > 4) {
                p->unk_138 &= ~0x100000000ULL;
            }
            if ((p->unk_138 & 0x100000000ULL) == 0) {
                p->unk_158 = 0;
            }
            p->unk_138 &= ~0xE0000000ULL;
            p->unk_144 = 0;
            fn_80008BEC(&p->unk_2C, 0, 12);
        }
        if ((p->unk_138 & 2) == 0) {
            p->unk_138 &= ~0x80ULL;
            p->unk_138 &= ~0x400000ULL;
            p->unk_138 &= ~0x100000ULL;
        }
    }

    for (e = objs, j = 0; j < count; e++, j++) {
        if ((e->unk_138 & 2) == 0) {
            if ((lbl_1_bss_9F8.unk_2 >> 8) & 1) {
                fn_1_E1A00(e, lbl_1_data_3E190);
                E5CC4_place(e, 3.0f * (e->unk_84 * e->unk_F4.x), 5);
                e->unk_44.z = (E5CC4_rand() % 10) / 50.0f;
                e->unk_44.y = (E5CC4_rand() % 10) / 50.0f;
                e->unk_44.x = (E5CC4_rand() % 10) / 50.0f;
                e->unk_138 &= ~8ULL;
                e->unk_6C.x = 0.01745329238474369f * (E5CC4_rand() % 20 + 1);
                e->unk_6C.y = 0.01745329238474369f * (E5CC4_rand() % 20 + 1);
                e->unk_6C.z = 0.01745329238474369f * (E5CC4_rand() % 20 + 1);
            } else if ((lbl_1_bss_9F8.unk_14 >> 11) & 1) {
                fn_1_E1A00(e, lbl_1_data_3E190);
                e->unk_138 |= 8;
                E5CC4_place(e, 3.0f * (e->unk_84 * e->unk_F4.x), 5);
                if (lbl_1_bss_7B14C__fzgx_offset_2 != 0) {
                    lbl_1_bss_7B14C__fzgx_offset_2 = 0;
                }
            }
        }
    }

    for (mover = objs, i = 0; i < count; mover++, i++) {
        if ((mover->unk_138 & 2) != 0) {
            continue;
        }
        E5CC4_move(mover);
    }

    if (lbl_1_bss_7B14C__fzgx_offset_2 == 0) {
        E5CC4_set_vel(objs, 0);
        E5CC4_set_pos(objs, &lbl_1_bss_7B14C__fzgx_offset_10);
    } else if (lbl_1_bss_7B14C__fzgx_offset_2 == 1) {
        lbl_8006D5F0(&lbl_1_bss_7B14C__fzgx_offset_10, &lbl_1_bss_7B14C__fzgx_offset_20,
                     -lbl_1_bss_7B14C__fzgx_offset_1C);
        E5CC4_set_vel(objs, &lbl_1_bss_7B14C__fzgx_offset_20);
        lbl_1_bss_7B14C__fzgx_offset_2 = 2;
    }

    for (collider = objs, i = 0; i < count; collider++, i++) {
        if ((collider->unk_138 & 2) == 0) {
            fn_1_E1934(collider, objs, count);
        }
    }

    for (lander = objs, i = 0; i < count; lander++, i++) {
        if ((lander->unk_138 & 2) != 0) {
            continue;
        }
        if ((lander->unk_138 & 0x10000) != 0) {
            E5CC4_set_up(lander, &lbl_1_bss_7B14C__fzgx_offset_4);
        }
        if (lander->unk_C != 1) {
            lbl_8006D7DC(&lbl_1_data_3E184);
            mathutil_mtxA_rotate_z(182.04444885253906f * lbl_1_bss_7B14C__fzgx_offset_2C);
            lbl_8006DB74(mtx);
            n = &lbl_1_bss_7B14C__fzgx_offset_4;
            r = lander->unk_84 * lander->unk_F4.x;
            E5CC4_floor_dist(lander, n, &dist);
            if (dist > r) {
                touch = 0;
            } else {
                psvec_scale(n, r - dist, &hit2);
                touch = 1;
            }
            if (touch == 1) {
                E5CC4_land(lander, &lbl_1_bss_7B14C__fzgx_offset_4, &hit2);
                lander->unk_138 |= 0x40000000;
            }
        } else {
            res = fn_1_DF2A4(&lander->unk_60, &lander->unk_54, lander->unk_C4, &lbl_1_data_3E184, &lbl_1_bss_7B14C__fzgx_offset_4,
                             &hit, &lander->unk_88, lander->unk_1A0 * lander->unk_F4.x, lander->unk_1A4 * lander->unk_F4.y);
            if (res != 0) {
                lander->unk_138 |= 0x40000000;
                if (res != 3) {
                    lander->unk_138 |= 0x8000000;
                }
                E5CC4_land(lander, &lbl_1_bss_7B14C__fzgx_offset_4, &hit);
            }
        }
    }

    for (q = objs, i = 0; i < count; q++, i++) {
        if ((q->unk_138 & 2) != 0) {
            continue;
        }
        if ((q->unk_138 & 0x2000) == 0) {
            fn_80008BA8(&q->unk_60, &q->unk_54, 12);
            q->unk_50 = lbl_8006D0B4(E5CC4_len2(&q->unk_44));
            if (__fabs(q->unk_50) < 1.1920928955078125e-07) {
                q->unk_138 |= 0x10000000;
                E5CC4_set_vel(q, 0);
            } else {
                q->unk_138 &= ~0x10000000ULL;
                psvec_add(&q->unk_54, &q->unk_44, &q->unk_54);
            }
            psvec_add(&q->unk_78, &q->unk_6C, &q->unk_78);
        }
        lbl_8006D7DC(&q->unk_54);
        mathutil_mtxA_rotate_z((10430.3779296875f * q->unk_78.z));
        mathutil_mtxA_rotate_y((10430.3779296875f * q->unk_78.y));
        mathutil_mtxA_rotate_x((10430.3779296875f * q->unk_78.x));
        lbl_8006E13C(&q->unk_F4);
        lbl_8006DB74(q->unk_C4);
    }
}
#pragma inline_max_size reset
#pragma opt_propagation reset
/* fzgx:end fn_1_E5CC4 */

/* fzgx:begin fn_1_E733C */
extern void lbl_8006DCA4(void *base, void *arg);
extern void fn_1_A71AC(void);
extern void fn_8006F828(void *base, f32 *out);
extern void fn_1_E4A38(void *base, s32 x, s32 y, void *arg);
extern void fn_80008BEC(void *dst, void *value, u32 size);
extern void fn_80008BA8(void *dst, void *value, u32 size);
extern f32 lbl_1_rodata_67A8;
extern u32 lbl_1_rodata_6A8C[3];
extern u32 strstr(const u8* left, const char* right);
extern u32 strlen(const char* string);
extern void fn_1_8CED0(void* object, s32 value0, s32 value1);
extern void fn_1_8D0A4(void* object);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80072EDC(u32, s32);
extern void fn_800745A4(u32, s32, s32, u32, s32, s32);
extern void fn_80073778(void *, u32);
extern void fn_80015C1C(void *, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void lbl_8006DFFC(void *, void *, void *);
extern void GXLoadTexMtxImm(void *, u32, s32);
extern f32 lbl_1_rodata_6780[236];
extern f32 fn_1_A6FE8(void);
extern void fn_1_E8938(void);
extern void fn_1_8D1C8(void *object, void (*callback)(void), int arg);
extern u32 fn_1_3F8C0(void);
extern u32 fn_80008E84(u32 value);
extern u32 lbl_1_bss_7C94C[67];
extern void fn_1_EE530(void);
extern u8 lbl_1_bss_7ECB4[72];
extern void fn_1_BC29C(u8 *);
extern void fn_1_B9C0C(void);
extern void fn_1_1596DC(s32);
extern void fn_1_484CC(s32);

extern void fn_80008BEC(void *dst, void *value, u32 size);
extern void fn_80008BA8(void *dst, void *value, u32 size);

extern f32 lbl_1_rodata_67A8;
extern u32 lbl_1_rodata_6A8C[3];
extern void fn_80008BA8(void *dst, void *value, u32 size);
extern void fn_1_12EF80(s16 arg, s16 *out_group, s16 *out_entry);
extern void fn_1_9C724(void);
extern void fn_1_DD890(void *);
extern void fn_1_9CC40(void);




extern f32 lbl_1_rodata_6780[];
extern u16 lbl_1_bss_7B14C[26];

static inline f32 fn_1_E733C_operand(f32 right, f32 left) { return left * right; }
typedef struct {
    u8 pad_0[0x20];
    f32 zero;       /* 0x020: 0.0f */
    u8 pad_24[0xC];
    f32 tenth;      /* 0x030: 0.1f */
    u8 pad_34[0x4];
    f32 ten;        /* 0x038: 10.0f */
    u8 pad_3C[0x4C];
    f32 sixty;      /* 0x088: 60.0f */
    u8 pad_8C[0x2A0];
    f32 neg_tenth;  /* 0x32C: -0.1f */
} PhysPoolE733C;

void fn_1_E733C(u8 *obj, s16 count) {
    const PhysPoolE733C *pool = (const PhysPoolE733C *)&lbl_1_rodata_6780;

    f32 f;
    s32 v;
    s32 t;
    s16 i;
    f = pool->zero;
    if (count == 0) {
        return;
    }
    if (PAD_BIT(lbl_1_bss_9F8.unk_10, 3) || PAD_BIT((&lbl_1_bss_9F8.unk_10)[10], 3)) {
        (lbl_1_bss_7B14C)[0] = ((s16 *)lbl_1_bss_7B14C)[0] - 1;
    }
    if (PAD_BIT(lbl_1_bss_9F8.unk_10, 2) || PAD_BIT((&lbl_1_bss_9F8.unk_10)[10], 2)) {
        (lbl_1_bss_7B14C)[0] = ((s16 *)lbl_1_bss_7B14C)[0] + 1;
    }
    if (PAD_BIT(lbl_1_bss_9F8.unk_10, 0) || PAD_BIT((&lbl_1_bss_9F8.unk_10)[10], 0)) {
        f = pool->neg_tenth;
    }
    if (PAD_BIT(lbl_1_bss_9F8.unk_10, 1) || PAD_BIT((&lbl_1_bss_9F8.unk_10)[10], 1)) {
        f = pool->tenth;
    }
    if (PAD_BIT(lbl_1_bss_9F8.unk_0, 8) || PAD_BIT((&lbl_1_bss_9F8.unk_0)[10], 8)) {
        f = fn_1_E733C_operand(pool->ten, f);
    }
    if (PAD_BIT(lbl_1_bss_9F8.unk_0, 9) || PAD_BIT((&lbl_1_bss_9F8.unk_0)[10], 9)) {
        f = f / pool->ten;
    }
    v = ((s16 *)lbl_1_bss_7B14C)[0];
    if (v > 4) {
        t = 0;
    } else {
        t = 4;
        if ((s16)v >= 0) {
            t = v;
        }
    }
    (lbl_1_bss_7B14C)[0] = t;
    for (i = 0; i < count;) {
        switch (((s16 *)lbl_1_bss_7B14C)[0]) {
        case 0:
            *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + f;
            break;
        case 1:
            *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) + f;
            break;
        case 2:
            *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) + f;
            break;
        case 3:
            *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) + f;
            break;
        case 4:
            *(f32 *)(obj + 0x28) = *(f32 *)(obj + 0x28) + f / (pool->sixty);
            break;
        }
        i++;
        obj += 0x1A8;
    }
}
/* fzgx:end fn_1_E733C */

/* fzgx:begin fn_1_E7524 */
#include "psvec.h"

#ifndef GAME_MAIN_REL_PHYS_TYPES_H
#define GAME_MAIN_REL_PHYS_TYPES_H

#endif  // GAME_MAIN_REL_PHYS_TYPES_H


extern void fn_1_4AE0C(const char* format, ...);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4955C(f32 value1, f32 value2);

extern void fn_1_49514(u32 *value);
extern u8 fn_1_E1A00__fzgx_offset_174[];
extern u8 fn_1_E1A00__fzgx_offset_184[];
extern u8 fn_1_E1A00__fzgx_offset_194[];
extern u8 fn_1_E1A00__fzgx_offset_1A4[];
extern u8 fn_1_E1A00__fzgx_offset_1B4[];
extern u8 fn_1_E1A00__fzgx_offset_1C4[];
extern u8 fn_1_E1A00__fzgx_offset_1D4[];
extern u8 fn_1_E1A00__fzgx_offset_1E4[];
extern u8 fn_1_E1A00__fzgx_offset_50[];
extern u8 fn_1_E1A00__fzgx_offset_60[];
extern u8 fn_1_E1A00__fzgx_offset_70[];
extern u8 fn_1_E1A00__fzgx_offset_80[];
extern u8 fn_1_E1A00__fzgx_offset_90[];
extern u8 fn_1_E1A00__fzgx_offset_A0[];
extern u8 fn_1_E1A00__fzgx_offset_B0[];
extern u8 fn_1_E1A00__fzgx_offset_C0[];
extern u8 lbl_1_data_3DC98__fzgx_offset_0[];
extern u8 lbl_1_data_3DCA0__fzgx_offset_0[];
extern u8 lbl_1_data_3DCA8__fzgx_offset_0[];
extern u8 lbl_1_data_3DCB0__fzgx_offset_0[];
extern u8 lbl_1_data_3DCB8__fzgx_offset_0[];
extern u8 lbl_1_data_3DCC0__fzgx_offset_0[];

typedef struct {
    u8 pad_0[0xA];
    s16 unk_A;
    u8 pad_C[0xC];
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
} PhysDebugObj;

typedef struct {
    u8 pad_0[0x2C4];
    s16 unk_2C4;
    u8 pad_2C6[0x1A];
    f32 unk_2E0;
    u8 pad_2E4[0xC];
    s16 unk_2F0;
} PhysDebugState;

typedef struct {
    u32 v[5];
} PhysDebugWords;

/* the TU literal pool, read through one base like the other section objects */
typedef struct {
    u8 pad_0[0x24];
    f32 five;
    u8 pad_28[0xC];
    f32 half;
    f32 ten;
    u8 pad_3C[0x4C];
    f32 sixty;
    u8 pad_8C[0x4C];
    f64 d216;
    u8 pad_E0[0x250];
    PhysDebugWords words;
    u32 color0;
    u32 color1;
    f32 f450;
} PhysDebugPool;

static u32 fzgx_pool_native_lbl_1_data_3DC98_gap_0[12] = {0x50594C4F, 0x4E000000, 0x464C4147, 0x30000000, 0x524F434B, 0x00000000, 0x53524F43, 0x4B000000, 0x434F494E, 0x00000000, 0x4554414E, 0x4B000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_3DC98_unk_30[0x80] = {(u32)lbl_1_data_3DC98__fzgx_offset_0, (u32)lbl_1_data_3DCA0__fzgx_offset_0, (u32)lbl_1_data_3DCA8__fzgx_offset_0, (u32)lbl_1_data_3DCB0__fzgx_offset_0, (u32)lbl_1_data_3DCB8__fzgx_offset_0, (u32)lbl_1_data_3DCC0__fzgx_offset_0, (u32)fn_1_E1A00__fzgx_offset_90, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1D4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_A0, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_50, (u32)fn_1_E1A00__fzgx_offset_1A4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_80, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_60, (u32)fn_1_E1A00__fzgx_offset_194, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_C0, (u32)fn_1_E1A00__fzgx_offset_1E4, (u32)fn_1_E1A00__fzgx_offset_184, (u32)fn_1_E1A00__fzgx_offset_1B4, (u32)fn_1_E1A00__fzgx_offset_1C4, (u32)fn_1_E1A00__fzgx_offset_70, (u32)fn_1_E1A00__fzgx_offset_B0, (u32)fn_1_E1A00__fzgx_offset_174, 0x46617670, 0x7772736E, 0x66745400, 0x70687973, 0x2E630000, 0x4C494753, 0x5F454E45, 0x42414C4C, 0x30310000, 0x4C494753, 0x5F454E45, 0x52494E47, 0x30315F41, 0x5F4C4F44, 0x00000000, 0x4C494753, 0x5F454E45, 0x52494E47, 0x30325F41, 0x5F4C4F44, 0x00000000, 0x4C494753, 0x5F454E45, 0x52494E47, 0x30335F41, 0x5F4C4F44, 0x00000000, 0x504F4400, 0x454E454C, 0x494E4730, 0x31000000, 0x454E454C, 0x494E4730, 0x32000000, 0x454E4546, 0x4C415348, 0x30310000, 0x49574100, 0x46617677, 0x72000000, 0x2532640A, 0x00000000, 0x69642020, 0x3A202532, 0x640A0000, 0x74797065, 0x3A202573, 0x0A000000, 0x65202020, 0x3A202535, 0x2E33660A, 0x00000000, 0x6D202020, 0x3A202535, 0x2E33660A, 0x00000000, 0x75202020, 0x3A202535, 0x2E33660A, 0x00000000, 0x6D752020, 0x3A202535, 0x2E33660A, 0x00000000, 0x6B202020, 0x3A202535, 0x2E33660A, 0x00000000, 0x46202020, 0x3A200000, 0x25352E33, 0x66200000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s230[0x9C] = {0x25, 0x35, 0x2E, 0x33, 0x66, 0x0A, 0x00, 0x00, 0x61, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x00, 0x00, 0x76, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x00, 0x00, 0x6D, 0x61, 0x67, 0x76, 0x3A, 0x20, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x70, 0x6F, 0x73, 0x20, 0x3A, 0x20, 0x00, 0x00, 0x77, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x00, 0x00, 0x72, 0x6F, 0x74, 0x20, 0x3A, 0x20, 0x00, 0x00, 0x72, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x73, 0x63, 0x6C, 0x20, 0x3A, 0x20, 0x00, 0x00, 0x73, 0x65, 0x63, 0x74, 0x3A, 0x20, 0x25, 0x33, 0x64, 0x0A, 0x00, 0x00, 0x6E, 0x6F, 0x72, 0x6D, 0x3A, 0x20, 0x00, 0x00, 0x43, 0x61, 0x72, 0x20, 0x00, 0x00, 0x00, 0x00, 0x53, 0x74, 0x67, 0x20, 0x00, 0x00, 0x00, 0x00, 0x50, 0x68, 0x79, 0x73, 0x20, 0x00, 0x00, 0x00, 0x48, 0x49, 0x54, 0x20, 0x3A, 0x20, 0x25, 0x73, 0x0A, 0x00, 0x00, 0x00, 0x63, 0x61, 0x72, 0x20, 0x3A, 0x00, 0x00, 0x00, 0x25, 0x64, 0x20, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s2cc[0x248] = {0x0A, 0x00, 0x00, 0x00, 0x4E, 0x4F, 0x44, 0x49, 0x53, 0x50, 0x00, 0x00, 0x4E, 0x4F, 0x43, 0x41, 0x4C, 0x43, 0x00, 0x00, 0x49, 0x4E, 0x46, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x4E, 0x4F, 0x47, 0x52, 0x41, 0x56, 0x49, 0x54, 0x59, 0x00, 0x00, 0x00, 0x4E, 0x4F, 0x43, 0x4F, 0x4C, 0x49, 0x5F, 0x43, 0x41, 0x52, 0x00, 0x00, 0x4E, 0x4F, 0x43, 0x4F, 0x4C, 0x49, 0x5F, 0x53, 0x54, 0x47, 0x00, 0x00, 0x4E, 0x4F, 0x43, 0x4F, 0x4C, 0x49, 0x5F, 0x50, 0x48, 0x59, 0x53, 0x00, 0x44, 0x49, 0x53, 0x50, 0x56, 0x45, 0x43, 0x00, 0x4E, 0x4F, 0x41, 0x49, 0x52, 0x00, 0x00, 0x00, 0x49, 0x4E, 0x46, 0x43, 0x41, 0x52, 0x00, 0x00, 0x43, 0x41, 0x52, 0x48, 0x49, 0x54, 0x5F, 0x56, 0x41, 0x4E, 0x49, 0x53, 0x48, 0x00, 0x00, 0x00, 0x42, 0x59, 0x5F, 0x43, 0x4F, 0x4C, 0x49, 0x44, 0x41, 0x54, 0x41, 0x00, 0x46, 0x4C, 0x47, 0x5F, 0x49, 0x4E, 0x46, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x53, 0x54, 0x4F, 0x50, 0x00, 0x00, 0x00, 0x00, 0x43, 0x48, 0x4B, 0x5F, 0x42, 0x59, 0x43, 0x4F, 0x4C, 0x00, 0x00, 0x00, 0x4C, 0x41, 0x4E, 0x44, 0x00, 0x00, 0x00, 0x00, 0x55, 0x50, 0x44, 0x5F, 0x4C, 0x4F, 0x41, 0x44, 0x5F, 0x4E, 0x52, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x49, 0x44, 0x5F, 0x53, 0x45, 0x43, 0x54, 0x5F, 0x44, 0x49, 0x53, 0x50, 0x00, 0x00, 0x00, 0x00, 0x4E, 0x4F, 0x53, 0x45, 0x4E, 0x54, 0x00, 0x00, 0x53, 0x45, 0x4E, 0x54, 0x00, 0x00, 0x00, 0x00, 0x43, 0x4F, 0x4C, 0x49, 0x5F, 0x44, 0x49, 0x53, 0x50, 0x00, 0x00, 0x00, 0x44, 0x49, 0x53, 0x50, 0x5F, 0x56, 0x45, 0x4C, 0x4F, 0x43, 0x49, 0x54, 0x59, 0x00, 0x00, 0x00, 0x44, 0x49, 0x53, 0x50, 0x5F, 0x4E, 0x4F, 0x52, 0x4D, 0x41, 0x4C, 0x00, 0x4E, 0x4F, 0x43, 0x4F, 0x4C, 0x49, 0x5F, 0x53, 0x45, 0x4E, 0x54, 0x00, 0x55, 0x53, 0x45, 0x5F, 0x54, 0x52, 0x4E, 0x53, 0x4C, 0x00, 0x00, 0x00, 0x4F, 0x42, 0x45, 0x59, 0x5F, 0x42, 0x47, 0x5F, 0x4F, 0x50, 0x00, 0x00, 0x44, 0x49, 0x46, 0x5F, 0x53, 0x45, 0x43, 0x54, 0x5F, 0x4F, 0x4B, 0x00, 0x53, 0x54, 0x41, 0x42, 0x4C, 0x45, 0x00, 0x00, 0x53, 0x54, 0x41, 0x59, 0x00, 0x00, 0x00, 0x00, 0x48, 0x49, 0x54, 0x5F, 0x50, 0x48, 0x59, 0x53, 0x00, 0x00, 0x00, 0x00, 0x48, 0x49, 0x54, 0x5F, 0x53, 0x54, 0x47, 0x00, 0x48, 0x49, 0x54, 0x5F, 0x43, 0x41, 0x52, 0x00, 0x4C, 0x41, 0x4E, 0x44, 0x32, 0x53, 0x54, 0x41, 0x4E, 0x44, 0x00, 0x00, 0x43, 0x4F, 0x4C, 0x49, 0x5F, 0x50, 0x5F, 0x43, 0x41, 0x52, 0x00, 0x00, 0x4F, 0x55, 0x54, 0x4F, 0x46, 0x5F, 0x43, 0x4C, 0x49, 0x50, 0x00, 0x00, 0x47, 0x45, 0x54, 0x00, 0x4F, 0x42, 0x45, 0x59, 0x5F, 0x53, 0x54, 0x43, 0x4F, 0x4C, 0x49, 0x00, 0x55, 0x53, 0x45, 0x5F, 0x53, 0x48, 0x41, 0x44, 0x4F, 0x57, 0x00, 0x00, 0x49, 0x47, 0x4E, 0x5F, 0x55, 0x50, 0x56, 0x45, 0x43, 0x00, 0x00, 0x00, 0x44, 0x4D, 0x47, 0x5F, 0x43, 0x41, 0x52, 0x00, 0x4C, 0x41, 0x54, 0x45, 0x5F, 0x56, 0x41, 0x4E, 0x49, 0x53, 0x48, 0x00, 0x52, 0x49, 0x56, 0x49, 0x56, 0x45, 0x00, 0x00, 0x45, 0x46, 0x46, 0x45, 0x43, 0x54, 0x00, 0x00, 0x50, 0x4F, 0x53, 0x54, 0x5F, 0x42, 0x47, 0x00, 0x46, 0x4C, 0x47, 0x32, 0x00, 0x00, 0x00, 0x00, 0x46, 0x4C, 0x47, 0x31, 0x00, 0x00, 0x00, 0x00, 0x46, 0x4C, 0x47, 0x30, 0x00, 0x00, 0x00, 0x00, 0x25, 0x73, 0x0A, 0x00, 0x25, 0x32, 0x2E, 0x32, 0x66, 0x20, 0x4B, 0x6D, 0x2F, 0x48, 0x0A, 0x00, 0x25, 0x32, 0x2E, 0x32, 0x66, 0x20, 0x6D, 0x2F, 0x66, 0x0A, 0x00, 0x00, 0x25, 0x73, 0x20, 0x3A, 0x20, 0x00, 0x00, 0x00, 0x25, 0x32, 0x2E, 0x32, 0x66, 0x20, 0x00, 0x00, 0x25, 0x32, 0x2E, 0x32, 0x66, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC1, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x61, 0x76, 0x70, 0x77, 0x72, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x6D, 0x00, 0x00, 0x00, 0x75, 0x00, 0x00, 0x00, 0x6D, 0x75, 0x00, 0x00, 0x6B, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s514[0x10] = {0x5B, 0x82, 0xD4, 0x82, 0xC2, 0x82, 0xE8, 0x82, 0xC4, 0x82, 0xB7, 0x82, 0xC6, 0x5D, 0x0A, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s524[0x24] = {0x4C, 0x28, 0x30, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x83, 0x49, 0x83, 0x75, 0x83, 0x57, 0x83, 0x46, 0x82, 0xE8, 0x82, 0xB9, 0x82, 0xC1, 0x82, 0xC6, 0x32, 0x82, 0xDE, 0x81, 0x5B, 0x82, 0xD4, 0x0A, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s548[0x30] = {0x59, 0x28, 0x31, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x83, 0x49, 0x83, 0x75, 0x83, 0x57, 0x83, 0x46, 0x82, 0xE8, 0x82, 0xB9, 0x82, 0xC1, 0x82, 0xC6, 0x28, 0x82, 0xCC, 0x81, 0x5B, 0x82, 0xAE, 0x82, 0xE7, 0x82, 0xD1, 0x82, 0xC4, 0x82, 0xA1, 0x29, 0x0A, 0x00, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s578[0x1C] = {0x59, 0x28, 0x30, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x82, 0xE8, 0x82, 0xB9, 0x82, 0xC1, 0x82, 0xC6, 0x0A, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s594[0x20] = {0x2B, 0x28, 0x30, 0x7C, 0x31, 0x29, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x83, 0x70, 0x83, 0x89, 0x83, 0x81, 0x81, 0x5B, 0x83, 0x5E, 0x82, 0xA2, 0x82, 0xC0, 0x82, 0xE8, 0x0A, 0x00, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s5b4[0x1C] = {0x53, 0x54, 0x49, 0x43, 0x4B, 0x28, 0x31, 0x29, 0x20, 0x3A, 0x20, 0x82, 0xE4, 0x82, 0xA9, 0x28, 0x41, 0x6E, 0x67, 0x20, 0x3A, 0x20, 0x25, 0x33, 0x64, 0x29, 0x0A, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s5d0[0x1C] = {0x5A, 0x28, 0x31, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x82, 0xE4, 0x82, 0xA9, 0x82, 0xE8, 0x82, 0xB9, 0x82, 0xC1, 0x82, 0xC6, 0x0A, 0x00, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s5ec[0x20] = {0x43, 0x28, 0x31, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x82, 0xD9, 0x82, 0xA4, 0x82, 0xBE, 0x82, 0xA2, 0x82, 0xD9, 0x82, 0xA4, 0x82, 0xB1, 0x82, 0xA4, 0x0A, 0x00, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s60c[0x28] = {0x4C, 0x52, 0x28, 0x31, 0x29, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x82, 0xCD, 0x82, 0xC1, 0x82, 0xB5, 0x82, 0xE1, 0x82, 0xBB, 0x82, 0xAD, 0x82, 0xC7, 0x28, 0x25, 0x32, 0x2E, 0x32, 0x66, 0x4B, 0x6D, 0x2F, 0x48, 0x29, 0x0A, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s634[0x28] = {0x41, 0x28, 0x31, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x82, 0xCD, 0x82, 0xC1, 0x82, 0xB5, 0x82, 0xE1, 0x2D, 0x21, 0x28, 0x42, 0x28, 0x31, 0x29, 0x82, 0xE8, 0x82, 0xB9, 0x82, 0xC1, 0x82, 0xC6, 0x29, 0x0A, 0x00, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s65c[0x10] = {0x5B, 0x25, 0x73, 0x83, 0x70, 0x83, 0x89, 0x83, 0x81, 0x81, 0x5B, 0x83, 0x5E, 0x5D, 0x0A, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_3DC98_s66c[0x10] = {0x25, 0x33, 0x73, 0x3A, 0x20, 0x00, 0x00, 0x00, 0x42, 0x49, 0x47, 0x52, 0x4F, 0x43, 0x4B, 0x30}; /* fzgx-allow: A1 measured pool bytes and bindings */

#pragma opt_common_subs off
void fn_1_E7524(PhysDebugObj *obj) {
    f32 fzgx_live;
    PhysDebugState *state = (PhysDebugState *)((PhysDebugState *)&lbl_1_bss_7AE88);
    PhysDebugPool *pool = (PhysDebugPool *)&lbl_1_rodata_6780;
    PhysDebugWords words;
    u32 color0;
    u32 color1;
    s16 i;

    words = pool->words;
    fn_1_4955C(pool->half, pool->half);
    fn_1_496FC(pool->ten, pool->ten);
    fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s514);
    fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s524);
    fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s548);
    fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s578);
    fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s594);
    fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s5b4, state->unk_2F0);
    fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s5d0);
    fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s5ec);
    fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s60c, pool->d216 * state->unk_2E0);
    fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s634);
    fn_1_496FC(pool->f450, pool->five);
    fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s65c, fzgx_pool_native_lbl_1_data_3DC98_unk_30[obj->unk_A]);

    for (i = 0; i < 5; i++) {
        if (i == state->unk_2C4) {
            color0 = pool->color0;
            fn_1_49514(&color0);
        }
        fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s66c, words.v[i]);
        switch (i) {
        case 0:
            fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s230, obj->unk_18);
            break;
        case 1:
            fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s230, obj->unk_1C);
            break;
        case 2:
            fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s230, obj->unk_20);
            break;
        case 3:
            fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s230, obj->unk_24);
            break;
        case 4:
            fzgx_live = pool->sixty;
            fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s230, fzgx_live * obj->unk_28);
            break;
        default:
            fn_1_4AE0C((const char *)fzgx_pool_native_lbl_1_data_3DC98_s2cc);
            break;
        }
        color1 = pool->color1;
        fn_1_49514(&color1);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_E7524 */

/* fzgx:begin fn_1_E7764 */
extern u32 strlen(const char* string);
extern void GXLoadTexMtxImm(void *, u32, s32);



extern u8 lbl_1_data_3DDA8[];
extern void fn_1_E1C10(void);
extern void fn_1_E1A00(void *, u8 *);
extern void fn_1_E252C(s16, s16, void *);

/* local view of one 0x1A8-byte entry of the six tables at lbl_1_bss_7AE88 */
typedef struct {
    u8 pad_0[0x8];
    s16 unk_8;
    u8 pad_A[0x2];
    s16 unk_C;
    u8 pad_E[0x46];
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
    f32 unk_60[3];
    u8 pad_6C[0x18];
    f32 unk_84;
    u8 pad_88[0x6C];
    f32 unk_F4;
    u8 pad_F8[0x40];
    u64 unk_138;
    u8 pad_140[0x68];
} E7764Entry;

/* the retail TU's .bss objects this function uses, at their retail offsets, so MWCC addresses them off one section
 * base; the fzgx_pool_gap_ objects span the retail data in between, which this function does not touch */
E7764Entry *fzgx_obj_lbl_1_bss_7AE88;
s16 lbl_1_bss_7AE88__fzgx_offset_4;
s16 fzgx_pool_gap_7AE8E;
E7764Entry *lbl_1_bss_7AE88__fzgx_offset_8;
s16 lbl_1_bss_7AE88__fzgx_offset_C;
s16 fzgx_pool_gap_7AE96;
E7764Entry *lbl_1_bss_7AE88__fzgx_offset_10;
s16 lbl_1_bss_7AE88__fzgx_offset_14;
s16 fzgx_pool_gap_7AE9E;
E7764Entry *lbl_1_bss_7AE88__fzgx_offset_18;
s16 lbl_1_bss_7AE88__fzgx_offset_1C;
s16 fzgx_pool_gap_7AEA6;
E7764Entry *lbl_1_bss_7AE88__fzgx_offset_20;
s16 lbl_1_bss_7AE88__fzgx_offset_24;
s16 fzgx_pool_gap_7AEAE;
E7764Entry *lbl_1_bss_7AE88__fzgx_offset_28;
s16 lbl_1_bss_7AE88__fzgx_offset_2C;
s16 fzgx_pool_gap_7AEB6;
u8 fzgx_pool_gap_7AEB8[0x294];
u8 fzgx_obj_lbl_1_bss_7B14C[0x2C];
s16 lbl_1_bss_7B14C__fzgx_offset_2C;
s16 lbl_1_bss_7B14C__fzgx_offset_2E;

#pragma section code_type ".fzgxpool"
static const u32 fn_1_E7764_fzgx_pool_table1[9] = {0xBF800000, 0x3F7FFFFE, 0x3F800001, 0xBF800001, 0xBF7FFFFE, 0x00000000, 0x3E800000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E7764_fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
}
static const u32 fn_1_E7764_fzgx_pool_table2[3] = {0x3F800000, 0x00FF00FF, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E7764_fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
}
static const u32 fn_1_E7764_fzgx_pool_table3[18] = {0x41200000, 0x43360B61, 0x43300000, 0x00000000, 0xBB326750, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x38C90FDB, 0x3FC00000, 0xB4000000, 0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E7764_fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fn_1_E7764_fzgx_pool_table4[32] = {0x42700000, 0x49742400, 0x48742400, 0x41A00000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0xBC23D70A, 0x3C23D70A, 0xBF8147AE, 0x38D1B717, 0x00000000, 0x3F800000, 0x00000000, 0x3F7D70A4, 0x40000000, 0x80000000, 0x406B0000, 0x00000000, 0x400921FB, 0x60000000, 0x40100000, 0x00000000, 0x404E0000, 0x00000000, 0x3F8147AE, 0x3D4CCCCD, 0x3F8020C5, 0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
/* MWCC sets up section bases in a function in reverse order of their first use in the file. Retail sets up
 * .bss before .rodata, so the .rodata base is first used here (the tables in one function) and the .bss
 * base only after it, by the layout primer below. */
__declspec(section ".fzgxpool") static void fn_1_E7764_fzgx_pool_keep(void) { const u32 *volatile cp; cp = fn_1_E7764_fzgx_pool_table1; cp = fn_1_E7764_fzgx_pool_table2; cp = fn_1_E7764_fzgx_pool_table3; cp = fn_1_E7764_fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E7764_fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7AE88;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_4;
    s = *(u8 *)&fzgx_pool_gap_7AE8E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_C;
    s = *(u8 *)&fzgx_pool_gap_7AE96;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_14;
    s = *(u8 *)&fzgx_pool_gap_7AE9E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_18;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_1C;
    s = *(u8 *)&fzgx_pool_gap_7AEA6;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_24;
    s = *(u8 *)&fzgx_pool_gap_7AEAE;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_28;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2C;
    s = *(u8 *)&fzgx_pool_gap_7AEB6;
    s = *(u8 *)&fzgx_pool_gap_7AEB8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B14C;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_2C;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_2E;
}
#pragma section code_type ".text"

static inline s16 E7764Count(s16 id) {
    switch (id) {
    case 0: return lbl_1_bss_7AE88__fzgx_offset_4;
    case 1: return lbl_1_bss_7AE88__fzgx_offset_C;
    case 2: return lbl_1_bss_7AE88__fzgx_offset_14;
    case 3: return lbl_1_bss_7AE88__fzgx_offset_1C;
    case 4: return lbl_1_bss_7AE88__fzgx_offset_24;
    case 5: return lbl_1_bss_7AE88__fzgx_offset_2C;
    default: return -1;
    }
}

static inline E7764Entry *E7764Base(s16 id) {
    switch (id) {
    case 0: return fzgx_obj_lbl_1_bss_7AE88;
    case 1: return lbl_1_bss_7AE88__fzgx_offset_8;
    case 2: return lbl_1_bss_7AE88__fzgx_offset_10;
    case 3: return lbl_1_bss_7AE88__fzgx_offset_18;
    case 4: return lbl_1_bss_7AE88__fzgx_offset_20;
    case 5: return lbl_1_bss_7AE88__fzgx_offset_28;
    default: return 0;
    }
}

static inline void E7764Place(E7764Entry *e, f32 scale) {
    f32 k = 5.0f;

    e->unk_54 = (f32)(scale * (e->unk_8 % 5)) - 0.5f * scale * k;
    e->unk_58 = scale * (e->unk_8 / 25);
    e->unk_5C = (f32)(scale * ((e->unk_8 % 25) / 5)) - 0.5f * scale * k;
    fn_80008BA8(e->unk_60, &e->unk_54, 0xC);
}

static inline void E7764Loop1(void) {
    s16 count;
    s16 j;
    u8 *name = lbl_1_data_3DDA8;
    s16 group;
    E7764Entry *e;

    for (group = 0; group < 6; group++) {
        count = E7764Count(group);
        e = E7764Base(group);
        for (j = 0; j < count; j++, e++) {
            fn_1_E1A00(e, name);
        }
    }
}

void fn_1_E7764(void) {
    s16 mode;
    s16 v;
    s16 i;
    s16 j;
    s16 n;
    E7764Entry *e;

    mode = 2;
    if (__rlwinm(lbl_1_bss_9F8.unk_2, 25, 31, 31)) {
        mode = 0;
    }
    if (__rlwinm(lbl_1_bss_9F8.unk_2, 27, 31, 31)) {
        mode = 1;
    }
    if (__rlwinm(lbl_1_bss_9F8.unk_2, 28, 31, 31)) {
        mode = 2;
    }
    if (__rlwinm(lbl_1_bss_9F8.unk_2, 26, 31, 31)) {
        mode = 4;
    }
    if (__rlwinm(lbl_1_bss_9F8.unk_0, 21, 31, 31)) {
        mode = 3;
        if (__rlwinm(lbl_1_bss_9F8.unk_2, 25, 31, 31)) {
            mode = 5;
        }
        if (__rlwinm(lbl_1_bss_9F8.unk_2, 28, 31, 31)) {
            mode = 3;
        }
    }
    lbl_1_bss_7B14C__fzgx_offset_2E = 5;
    if (__rlwinm((&lbl_1_bss_9F8.unk_2)[10], 25, 31, 31)) {
        lbl_1_bss_7B14C__fzgx_offset_2E = 100;
    }
    if (__rlwinm((&lbl_1_bss_9F8.unk_2)[10], 26, 31, 31)) {
        lbl_1_bss_7B14C__fzgx_offset_2E = 1;
    }
    if (__rlwinm((&lbl_1_bss_9F8.unk_2)[10], 28, 31, 31) || __rlwinm((&lbl_1_bss_9F8.unk_2)[10], 27, 31, 31)) {
        lbl_1_bss_7B14C__fzgx_offset_2E = 25;
    }
    lbl_1_bss_7B14C__fzgx_offset_2C = 0;
    v = lbl_1_bss_7B14C__fzgx_offset_2E;
    switch (mode) {
    case 0: lbl_1_bss_7AE88__fzgx_offset_4 = v; break;
    case 1: lbl_1_bss_7AE88__fzgx_offset_C = v; break;
    case 2: lbl_1_bss_7AE88__fzgx_offset_14 = v; break;
    case 3: lbl_1_bss_7AE88__fzgx_offset_1C = v; break;
    case 4: lbl_1_bss_7AE88__fzgx_offset_24 = v; break;
    case 5: lbl_1_bss_7AE88__fzgx_offset_2C = v; break;
    }
    fn_1_E1C10();
    E7764Loop1();
    for (i = 0; i < 6; i++) {
        n = E7764Count(i);
        switch (i) {
        case 0: e = fzgx_obj_lbl_1_bss_7AE88; break;
        case 1: e = lbl_1_bss_7AE88__fzgx_offset_8; break;
        case 2: e = lbl_1_bss_7AE88__fzgx_offset_10; break;
        case 3: e = lbl_1_bss_7AE88__fzgx_offset_18; break;
        case 4: e = lbl_1_bss_7AE88__fzgx_offset_20; break;
        case 5: e = lbl_1_bss_7AE88__fzgx_offset_28; break;
        default: e = 0; break;
        }
        for (j = 0; j < n; j++, e++) {
            fn_1_E252C(i, j, e);
        }
    }
    for (n = 0; n < 6; n++) {
        j = E7764Count(n);
        e = E7764Base(n);
        for (i = 0; i < j; i++, e++) {
            e->unk_138 |= 0x8;
            e->unk_138 &= ~0x40ULL;
            if (e->unk_C == 1) {
                e->unk_138 |= 0x40;
            }
            e->unk_138 &= ~0x10000ULL;
            e->unk_138 &= ~0x2000000ULL;
            E7764Place(e, 3.0f * (e->unk_84 * e->unk_F4));
        }
    }
}
/* fzgx:end fn_1_E7764 */

/* fzgx:begin fn_1_E7E00 noprologue */
#include "types.h"

typedef struct Sig_fn_1_8D168_Fn1_8D168State {
    u8 pad[0x60];
    u32 field_60;
} Sig_fn_1_8D168_Fn1_8D168State;

struct fn_1_E7E00_lbl_1_bss_7AE88 {
    u32 unk_0;
    u16 unk_4;
    u8 pad_6[0x2];
    u32 unk_8;
    u16 unk_C;
    u8 pad_E[0x2];
    u32 unk_10;
    u16 unk_14;
    u8 pad_16[0x2];
    u32 unk_18;
    u16 unk_1C;
    u8 pad_1E[0x2];
    u32 unk_20;
    u16 unk_24;
    u8 pad_26[0x2];
    u32 unk_28;
    u16 unk_2C;
    u8 pad_2E[0x2];
    u32 unk_30;
};
struct fn_1_E7E00_lbl_801A6410 {
    u32 unk_0;
};

extern struct fn_1_E7E00_lbl_801A6410 lbl_801A6410;
extern u32 lbl_1_data_3DDB4;
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_8D168(Sig_fn_1_8D168_Fn1_8D168State *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_7AE88;
u16 lbl_1_bss_7AE88__fzgx_offset_4;
u16 lbl_1_bss_7AE88__fzgx_offset_6;
u32 lbl_1_bss_7AE88__fzgx_offset_8;
u16 lbl_1_bss_7AE88__fzgx_offset_C;
u16 lbl_1_bss_7AE88__fzgx_offset_E;
u32 lbl_1_bss_7AE88__fzgx_offset_10;
u16 lbl_1_bss_7AE88__fzgx_offset_14;
u16 lbl_1_bss_7AE88__fzgx_offset_16;
u32 lbl_1_bss_7AE88__fzgx_offset_18;
u16 lbl_1_bss_7AE88__fzgx_offset_1C;
u16 lbl_1_bss_7AE88__fzgx_offset_1E;
u32 lbl_1_bss_7AE88__fzgx_offset_20;
u16 lbl_1_bss_7AE88__fzgx_offset_24;
u16 lbl_1_bss_7AE88__fzgx_offset_26;
u32 lbl_1_bss_7AE88__fzgx_offset_28;
u16 lbl_1_bss_7AE88__fzgx_offset_2C;
u16 lbl_1_bss_7AE88__fzgx_offset_2E;
u32 lbl_1_bss_7AEB8;
u32 lbl_1_bss_7AEB8__fzgx_offset_4[164];
u32 lbl_1_bss_7B14C[13];
u32 lbl_1_bss_7B180[2];
u32 lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_7AE88;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_16;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_18;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_1E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_24;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_26;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_28;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2C;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2E;
    s = *(u8 *)&lbl_1_bss_7AEB8;
    s = *(u8 *)&lbl_1_bss_7AEB8__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7B14C;
    s = *(u8 *)&lbl_1_bss_7B180;
    s = *(u8 *)&lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
}
#pragma section code_type ".text"

void fn_1_E7E00(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    
    if ((lbl_1_bss_7AEB8 & ~0x7FFFFFFF) != 0) {
    fn_1_8D168((Sig_fn_1_8D168_Fn1_8D168State *)((u8 *)(&lbl_1_bss_7AEB8) + 528));
    lbl_1_bss_7AEB8 = (lbl_1_bss_7AEB8 & 0x7FFFFFFF);
    }
    v0 = lbl_1_bss_7AE88;
    if (v0 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v0, (const char *)&lbl_1_data_3DDB4, 2647);
    lbl_1_bss_7AE88 = 0;
    lbl_1_bss_7AE88__fzgx_offset_4 = 0;
    }
    v1 = lbl_1_bss_7AE88__fzgx_offset_8;
    if (v1 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v1, (const char *)&lbl_1_data_3DDB4, 2648);
    lbl_1_bss_7AE88__fzgx_offset_8 = 0;
    lbl_1_bss_7AE88__fzgx_offset_C = 0;
    }
    v2 = lbl_1_bss_7AE88__fzgx_offset_10;
    if (v2 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v2, (const char *)&lbl_1_data_3DDB4, 2649);
    lbl_1_bss_7AE88__fzgx_offset_10 = 0;
    lbl_1_bss_7AE88__fzgx_offset_14 = 0;
    }
    v3 = lbl_1_bss_7AE88__fzgx_offset_18;
    if (v3 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v3, (const char *)&lbl_1_data_3DDB4, 2650);
    lbl_1_bss_7AE88__fzgx_offset_18 = 0;
    lbl_1_bss_7AE88__fzgx_offset_1C = 0;
    }
    v4 = lbl_1_bss_7AE88__fzgx_offset_20;
    if (v4 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v4, (const char *)&lbl_1_data_3DDB4, 2651);
    lbl_1_bss_7AE88__fzgx_offset_20 = 0;
    lbl_1_bss_7AE88__fzgx_offset_24 = 0;
    }
    v5 = lbl_1_bss_7AE88__fzgx_offset_28;
    if (v5 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, v5, (const char *)&lbl_1_data_3DDB4, 2652);
    lbl_1_bss_7AE88__fzgx_offset_28 = 0;
    lbl_1_bss_7AE88__fzgx_offset_2C = 0;
    }
}
/* fzgx:end fn_1_E7E00 */

/* fzgx:begin fn_1_E7F88 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/phys.h"

extern void lbl_8006DCA4(void);
extern void lbl_8006E0A4(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void fn_80072558(void);
extern void fn_1_E5AE0(s16 a, s16 b, f32 w, f32 h);
extern void fn_1_9C724(void);
extern void fn_1_DD890(void *);
extern void fn_80077E0C(void *);
extern void fn_80076134(void);
extern void fn_1_9CC40(void);

typedef struct { f32 x; f32 y; f32 z; } E7F88Vec;
typedef struct { u8 r; u8 g; u8 b; u8 a; } E7F88Color;
extern void fn_1_5773C(E7F88Vec *a, E7F88Vec *b, E7F88Color *c);
extern void fn_1_E7524(void *obj);

/* the retail TU's .bss words this function uses, at their retail offsets, so MWCC addresses them off one section
 * base; the fzgx_pool_gap_ objects span the retail data in between, which this function does not touch */
u32 fzgx_obj_lbl_1_bss_7AE88;
s16 lbl_1_bss_7AE88__fzgx_offset_4;
s16 fzgx_pool_gap_7AE8E;
u32 lbl_1_bss_7AE88__fzgx_offset_8;
s16 lbl_1_bss_7AE88__fzgx_offset_C;
s16 fzgx_pool_gap_7AE96;
u32 lbl_1_bss_7AE88__fzgx_offset_10;
s16 lbl_1_bss_7AE88__fzgx_offset_14;
s16 fzgx_pool_gap_7AE9E;
u32 lbl_1_bss_7AE88__fzgx_offset_18;
s16 lbl_1_bss_7AE88__fzgx_offset_1C;
s16 fzgx_pool_gap_7AEA6;
u32 lbl_1_bss_7AE88__fzgx_offset_20;
s16 lbl_1_bss_7AE88__fzgx_offset_24;
s16 fzgx_pool_gap_7AEAE;
u32 lbl_1_bss_7AE88__fzgx_offset_28;
s16 lbl_1_bss_7AE88__fzgx_offset_2C;
s16 fzgx_pool_gap_7AEB6;
u8 fzgx_pool_gap_7AEB8[0x294];
s16 fzgx_obj_lbl_1_bss_7B14C;
s16 lbl_1_bss_7B14C__fzgx_offset_2;
u8 fzgx_pool_gap_7B150[0xC];
E7F88Vec lbl_1_bss_7B14C__fzgx_offset_10;
u8 fzgx_pool_gap_7B168[0x10];
s16 lbl_1_bss_7B14C__fzgx_offset_2C;

typedef struct {
    u8 pad_0[0xA];
    s16 unk_A;
    u8 pad_C[0x2];
    s16 unk_E;
    u8 pad_10[0x128];
    u64 unk_138;
    u8 pad_140[0x68];
} E7F88Entry;
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[15] = {0xBF800000, 0x3F7FFFFE, 0x3F800001, 0xBF800001, 0xBF7FFFFE, 0x00000000, 0x3E800000, 0x00000000, 0x00000000, 0x40A00000, 0x3F800000, 0x00FF00FF, 0x3DCCCCCD, 0x3F000000, 0x41200000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
}
static const u32 fzgx_pool_table2[16] = {0x43300000, 0x00000000, 0xBB326750, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x38C90FDB, 0x3FC00000, 0xB4000000, 0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table3[179] = {0x42700000, 0x49742400, 0x48742400, 0x41A00000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0xBC23D70A, 0x3C23D70A, 0xBF8147AE, 0x38D1B717, 0x00000000, 0x3F800000, 0x00000000, 0x3F7D70A4, 0x40000000, 0x80000000, 0x406B0000, 0x00000000, 0x400921FB, 0x60000000, 0x40100000, 0x00000000, 0x404E0000, 0x00000000, 0x3F8147AE, 0x3D4CCCCD, 0x3F8020C5, 0x3F666666, 0x40400000, 0x3FE00000, 0x40F00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40A00000, 0x3F4CCCCD, 0x3ADA740E, 0x3E99999A, 0x3C888889, 0x4B189680, 0x4A989680, 0x42C80000, 0x00000000, 0x3F800000, 0x00000000, 0x01060002, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x00FE0001, 0x005800A6, 0x005800A6, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005A00A8, 0x005C00A8, 0x01000002, 0x005F00A8, 0x005C00A8, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x01020002, 0x00020103, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x3C8EFA35, 0xC0400000, 0x40400000, 0xC0400000, 0x40400000, 0x41200000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3F000000, 0x43A00000, 0x43600000, 0x00000000, 0x43700000, 0x437F0000, 0x44200000, 0x43F00000, 0x3FA2A2A3, 0x00000000, 0x3F800000, 0x00000000, 0xC61C4000, 0x46AFC800, 0x4622F983, 0x3ECCCCCD, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x3F800000, 0x00000000, 0x42480000, 0xBDCCCCCD, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00FF0000, 0xFFFFFF00, 0x43E10000, 0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
/* MWCC sets up section bases in a function in reverse order of their first use in the file. Retail sets up
 * .bss before .rodata, so the .rodata base is first used here (three tables in one function) and the .bss
 * base only after it, by the layout primer below. */
__declspec(section ".fzgxpool") static void fzgx_pool_keep(void) { const u32 *volatile cp; cp = fzgx_pool_table1; cp = fzgx_pool_table2; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7AE88;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_4;
    s = *(u8 *)&fzgx_pool_gap_7AE8E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_C;
    s = *(u8 *)&fzgx_pool_gap_7AE96;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_14;
    s = *(u8 *)&fzgx_pool_gap_7AE9E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_18;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_1C;
    s = *(u8 *)&fzgx_pool_gap_7AEA6;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_24;
    s = *(u8 *)&fzgx_pool_gap_7AEAE;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_28;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2C;
    s = *(u8 *)&fzgx_pool_gap_7AEB6;
    s = *(u8 *)&fzgx_pool_gap_7AEB8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B14C;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_2;
    s = *(u8 *)&fzgx_pool_gap_7B150;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_10;
    s = *(u8 *)&fzgx_pool_gap_7B168;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_2C;
}
#pragma section code_type ".text"
static inline s16 E7F88Count(s16 id) {
    switch (id) {
    case 0: return lbl_1_bss_7AE88__fzgx_offset_4;
    case 1: return lbl_1_bss_7AE88__fzgx_offset_C;
    case 2: return lbl_1_bss_7AE88__fzgx_offset_14;
    case 3: return lbl_1_bss_7AE88__fzgx_offset_1C;
    case 4: return lbl_1_bss_7AE88__fzgx_offset_24;
    case 5: return lbl_1_bss_7AE88__fzgx_offset_2C;
    default: return -1;
    }
}

static inline E7F88Entry *E7F88Base(s16 id) {
    switch (id) {
    case 0: return (E7F88Entry *)fzgx_obj_lbl_1_bss_7AE88;
    case 1: return (E7F88Entry *)lbl_1_bss_7AE88__fzgx_offset_8;
    case 2: return (E7F88Entry *)lbl_1_bss_7AE88__fzgx_offset_10;
    case 3: return (E7F88Entry *)lbl_1_bss_7AE88__fzgx_offset_18;
    case 4: return (E7F88Entry *)lbl_1_bss_7AE88__fzgx_offset_20;
    case 5: return (E7F88Entry *)lbl_1_bss_7AE88__fzgx_offset_28;
    default: return 0;
    }
}

static inline void E7F88Objects(void) {
    s16 i;
    s16 group;
    E7F88Entry *entry;
    s16 count;

    fn_1_9C724();
    for (group = 0; group < 6; group++) {
        count = E7F88Count(group);
        entry = E7F88Base(group);
        if (entry != 0 && entry->unk_A == 4 && (entry->unk_138 & 0x80000000000ULL) == 0) {
            fn_80077E0C(*(void **)((u8 *)*(void **)((u8 *)*(void **)(lbl_1_bss_3BE0->unk_54 +
                (entry->unk_E << 6) + 8) + 8) + 8));
            fn_80076134();
        }
        for (i = 0; i < count; i++, entry++) {
            if ((entry->unk_138 & 0x80000000000ULL) == 0) {
                fn_1_DD890(entry);
            }
        }
    }
    fn_1_9CC40();
}

void fn_1_E7F88(void) {
    void *obj;

    lbl_8006DCA4();
    lbl_8006E0A4(&lbl_1_data_3E184);
    mathutil_mtxA_rotate_z(182.04444885253906f * lbl_1_bss_7B14C__fzgx_offset_2C);
    fn_80072558();
    fn_1_E5AE0(100, 100, 1000.0f, 1000.0f);
    {
        E7F88Color c1 = {0x00, 0xFF, 0xFF, 0x00};
        E7F88Color c2 = {0xFF, 0x00, 0x00, 0x00};
        E7F88Color *color;
        lbl_8006DCA4();
        color = &c2;
        if (lbl_1_bss_7B14C__fzgx_offset_2 == 2) {
            color = &c1;
        }
        {
            E7F88Vec origin = {0.0f, 0.0f, 0.0f};
            fn_1_5773C(&origin, &lbl_1_bss_7B14C__fzgx_offset_10, color);
        }
    }
    E7F88Objects();
    if (lbl_1_bss_7AE88__fzgx_offset_4 != 0) {
        obj = (void *)fzgx_obj_lbl_1_bss_7AE88;
    }
    if (lbl_1_bss_7AE88__fzgx_offset_C != 0) {
        obj = (void *)lbl_1_bss_7AE88__fzgx_offset_8;
    }
    if (lbl_1_bss_7AE88__fzgx_offset_14 != 0) {
        obj = (void *)lbl_1_bss_7AE88__fzgx_offset_10;
    }
    if (lbl_1_bss_7AE88__fzgx_offset_1C != 0) {
        obj = (void *)lbl_1_bss_7AE88__fzgx_offset_18;
    }
    if (lbl_1_bss_7AE88__fzgx_offset_24 != 0) {
        obj = (void *)lbl_1_bss_7AE88__fzgx_offset_20;
    }
    if (lbl_1_bss_7AE88__fzgx_offset_2C != 0) {
        obj = (void *)lbl_1_bss_7AE88__fzgx_offset_28;
    }
    fn_1_E7524(obj);
}
/* fzgx:end fn_1_E7F88 */

/* fzgx:begin fn_1_E828C */
typedef struct { f32 x; f32 y; f32 z; } E828CVec;

extern void lbl_8006D7DC(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1C0(void *, void *);
extern void lbl_8006D758(void);
extern void lbl_8006E1B0(void *, void *);
extern void fn_1_E733C(u8 *obj, s16 count);
extern void fn_1_E5CC4(u8 *obj, s16 count);
extern f32 lbl_1_bss_BF0[32];

/* the retail TU's .bss words this function uses, at their retail offsets, so MWCC addresses them off one section
 * base; the fzgx_pool_gap_ objects span the retail data in between, which this function does not touch */
u8 * fzgx_obj_lbl_1_bss_7AE88;
s16 lbl_1_bss_7AE88__fzgx_offset_4;
s16 fzgx_pool_gap_7AE8E;
u8 * lbl_1_bss_7AE88__fzgx_offset_8;
s16 lbl_1_bss_7AE88__fzgx_offset_C;
s16 fzgx_pool_gap_7AE96;
u8 * lbl_1_bss_7AE88__fzgx_offset_10;
s16 lbl_1_bss_7AE88__fzgx_offset_14;
s16 fzgx_pool_gap_7AE9E;
u8 * lbl_1_bss_7AE88__fzgx_offset_18;
s16 lbl_1_bss_7AE88__fzgx_offset_1C;
s16 fzgx_pool_gap_7AEA6;
u8 * lbl_1_bss_7AE88__fzgx_offset_20;
s16 lbl_1_bss_7AE88__fzgx_offset_24;
s16 fzgx_pool_gap_7AEAE;
u8 * lbl_1_bss_7AE88__fzgx_offset_28;
s16 lbl_1_bss_7AE88__fzgx_offset_2C;
s16 fzgx_pool_gap_7AEB6;
u8 fzgx_pool_gap_7AEB8[0x294];
s16 fzgx_obj_lbl_1_bss_7B14C;
s16 lbl_1_bss_7B14C__fzgx_offset_2;
E828CVec lbl_1_bss_7B14C__fzgx_offset_4;
E828CVec lbl_1_bss_7B14C__fzgx_offset_10;
f32 lbl_1_bss_7B14C__fzgx_offset_1C;
u8 fzgx_pool_gap_7B16C[0xC];
s16 lbl_1_bss_7B14C__fzgx_offset_2C;
s16 fzgx_pool_gap_7B17E;
s16 lbl_1_bss_7B14C__fzgx_offset_30;
s16 lbl_1_bss_7B14C__fzgx_offset_32;


/* local view of lbl_1_bss_9F8 */
typedef struct {
    u8 pad_0[0x14];
    u16 unk_14;
    u16 unk_16;
    u8 pad_18[0x4];
    u16 unk_1C;
    u8 pad_1E[0x32];
} E828CButtons;
#pragma section code_type ".fzgxpool"
static const u32 fn_1_E828C_fzgx_pool_table1[9] = {0xBF800000, 0x3F7FFFFE, 0x3F800001, 0xBF800001, 0xBF7FFFFE, 0x00000000, 0x3E800000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E828C_fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
}
static const u32 fn_1_E828C_fzgx_pool_table2[2] = {0x3F800000, 0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E828C_fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
}
static const u32 fn_1_E828C_fzgx_pool_table3[2] = {0x3F000000, 0x41200000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E828C_fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
}
static const u32 fn_1_E828C_fzgx_pool_table4[16] = {0x43300000, 0x00000000, 0xBB326750, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x38C90FDB, 0x3FC00000, 0xB4000000, 0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_E828C_fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table9[185] = {0x42700000, 0x49742400, 0x48742400, 0x41A00000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0xBC23D70A, 0x3C23D70A, 0xBF8147AE, 0x38D1B717, 0x00000000, 0x3F800000, 0x00000000, 0x3F7D70A4, 0x40000000, 0x80000000, 0x406B0000, 0x00000000, 0x400921FB, 0x60000000, 0x40100000, 0x00000000, 0x404E0000, 0x00000000, 0x3F8147AE, 0x3D4CCCCD, 0x3F8020C5, 0x3F666666, 0x40400000, 0x3FE00000, 0x40F00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40A00000, 0x3F4CCCCD, 0x3ADA740E, 0x3E99999A, 0x3C888889, 0x4B189680, 0x4A989680, 0x42C80000, 0x00000000, 0x3F800000, 0x00000000, 0x01060002, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x005800A6, 0x00FE0001, 0x005800A6, 0x005800A6, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005800A7, 0x005A00A8, 0x005C00A8, 0x01000002, 0x005F00A8, 0x005C00A8, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x00FE0000, 0x01020002, 0x00020103, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x00FE0001, 0x3C8EFA35, 0xC0400000, 0x40400000, 0xC0400000, 0x40400000, 0x41200000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3F000000, 0x43A00000, 0x43600000, 0x00000000, 0x43700000, 0x437F0000, 0x44200000, 0x43F00000, 0x3FA2A2A3, 0x00000000, 0x3F800000, 0x00000000, 0xC61C4000, 0x46AFC800, 0x4622F983, 0x3ECCCCCD, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x3F800000, 0x00000000, 0x42480000, 0xBDCCCCCD, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00FF0000, 0xFFFFFF00, 0x43E10000, 0x00FF00FF, 0x00FFFF00, 0xFF000000, 0x00000000, 0x00000000, 0x00000000, 0x447A0000};  /* fzgx-allow: A1 retail pool bytes */
/* MWCC sets up section bases in a function in reverse order of their first use in the file: this primer
 * uses the .rodata base before the layout primer below uses the .bss base, as retail orders them. */
__declspec(section ".fzgxpool") static void fn_1_E828C_fzgx_pool_keep(void) { const u32 *volatile cp; cp = fn_1_E828C_fzgx_pool_table1; cp = fn_1_E828C_fzgx_pool_table2; cp = fn_1_E828C_fzgx_pool_table3; cp = fn_1_E828C_fzgx_pool_table4; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_E828C_fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7AE88;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_4;
    s = *(u8 *)&fzgx_pool_gap_7AE8E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_C;
    s = *(u8 *)&fzgx_pool_gap_7AE96;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_14;
    s = *(u8 *)&fzgx_pool_gap_7AE9E;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_18;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_1C;
    s = *(u8 *)&fzgx_pool_gap_7AEA6;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_24;
    s = *(u8 *)&fzgx_pool_gap_7AEAE;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_28;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2C;
    s = *(u8 *)&fzgx_pool_gap_7AEB6;
    s = *(u8 *)&fzgx_pool_gap_7AEB8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B14C;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_1C;
    s = *(u8 *)&fzgx_pool_gap_7B16C;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_2C;
    s = *(u8 *)&fzgx_pool_gap_7B17E;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_30;
    s = *(u8 *)&lbl_1_bss_7B14C__fzgx_offset_32;
}
#pragma section code_type ".text"
static inline s16 E828CCount(s16 id) {
    switch (id) {
    case 0: return lbl_1_bss_7AE88__fzgx_offset_4;
    case 1: return lbl_1_bss_7AE88__fzgx_offset_C;
    case 2: return lbl_1_bss_7AE88__fzgx_offset_14;
    case 3: return lbl_1_bss_7AE88__fzgx_offset_1C;
    case 4: return lbl_1_bss_7AE88__fzgx_offset_24;
    case 5: return lbl_1_bss_7AE88__fzgx_offset_2C;
    default: return -1;
    }
}

static inline u8 *E828CBase(s16 id) {
    switch (id) {
    case 0: return fzgx_obj_lbl_1_bss_7AE88;
    case 1: return lbl_1_bss_7AE88__fzgx_offset_8;
    case 2: return lbl_1_bss_7AE88__fzgx_offset_10;
    case 3: return lbl_1_bss_7AE88__fzgx_offset_18;
    case 4: return lbl_1_bss_7AE88__fzgx_offset_20;
    case 5: return lbl_1_bss_7AE88__fzgx_offset_28;
    default: return 0;
    }
}

#define BUTTONS ((E828CButtons *)&lbl_1_bss_9F8)

void fn_1_E828C(void) {
    E828CVec up = {0.0f, 1.0f, 0.0f};
    f32 mtx[3][4];
    s16 group;

    lbl_1_bss_7B14C__fzgx_offset_2C += (f32)(5.0f * lbl_1_bss_BF0[8]);
    lbl_1_bss_7B14C__fzgx_offset_2C = (lbl_1_bss_7B14C__fzgx_offset_2C + 360) % 360;
    lbl_8006D7DC(&lbl_1_data_3E184);
    mathutil_mtxA_rotate_z(182.04444885253906f * lbl_1_bss_7B14C__fzgx_offset_2C);
    lbl_8006DB74(mtx);
    lbl_8006DBAC(mtx);
    lbl_8006E1C0(&up, &lbl_1_bss_7B14C__fzgx_offset_4);
    if ((BUTTONS->unk_14 >> 4) & 1) {
        lbl_1_bss_7B14C__fzgx_offset_2C = 0;
    }
    for (group = 0; group < 6; group++) {
        fn_1_E733C(E828CBase(group), E828CCount(group));
    }
    {
        E828CVec offset = {50.0f, 0.0f, 0.0f};
        if ((BUTTONS->unk_16 >> 7) & 1) {
            lbl_1_bss_7B14C__fzgx_offset_30 += 0xB6;
        }
        if ((BUTTONS->unk_16 >> 6) & 1) {
            lbl_1_bss_7B14C__fzgx_offset_30 -= 0xB6;
        }
        lbl_1_bss_7B14C__fzgx_offset_30 %= 0x10000;
        if ((BUTTONS->unk_16 >> 5) & 1) {
            lbl_1_bss_7B14C__fzgx_offset_32 -= 0xB6;
        }
        if ((BUTTONS->unk_16 >> 4) & 1) {
            lbl_1_bss_7B14C__fzgx_offset_32 += 0xB6;
        }
        lbl_1_bss_7B14C__fzgx_offset_32 %= 0x10000;
        lbl_8006D758();
        mathutil_mtxA_rotate_y(lbl_1_bss_7B14C__fzgx_offset_32);
        mathutil_mtxA_rotate_z(lbl_1_bss_7B14C__fzgx_offset_30);
        lbl_8006E1B0(&offset, &lbl_1_bss_7B14C__fzgx_offset_10);
    }
    if ((BUTTONS->unk_1C >> 8) & 1) {
        lbl_1_bss_7B14C__fzgx_offset_2 = 1;
    }
    if ((BUTTONS->unk_1C >> 9) & 1) {
        lbl_1_bss_7B14C__fzgx_offset_2 = 0;
    }
    if ((BUTTONS->unk_16 >> 9) & 1) {
        lbl_1_bss_7B14C__fzgx_offset_1C += 0.1f;
    }
    if ((BUTTONS->unk_16 >> 8) & 1) {
        lbl_1_bss_7B14C__fzgx_offset_1C -= 0.1f;
    }
    for (group = 0; group < 6; group++) {
        fn_1_E5CC4(E828CBase(group), E828CCount(group));
    }
}
/* fzgx:end fn_1_E828C */

/* fzgx:begin fn_1_E86FC */
typedef struct StringValueEntry {
    u32 value;
    const u8* string;
} StringValueEntry;

typedef struct StringValueTable {
    s32 count;
    u32 unused;
    StringValueEntry* entries;
} StringValueTable;

u32 fn_1_E86FC(StringValueTable* table, const char* string) {
    StringValueEntry* entry;
    u32 best_value;
    s32 best_length;
    s32 count;

    if (table == 0) {
        return 0;
    }

    entry = table->entries;
    count = table->count;
    best_length = 0;
    best_value = 0;

    while (count > 0) {
        u32 length;

        if (strstr(entry->string, string) != 0) {
            length = strlen(string);
            if (entry->string[length] == 0) {
                length++;
            }
            if ((s32)length > best_length) {
                best_value = entry->value;
                best_length = length;
            }
        }

        count--;
        entry++;
    }

    return best_value;
}
/* fzgx:end fn_1_E86FC */

/* fzgx:begin fn_1_E87A4 */
void fn_1_E87A4(f64 value0, f64 value1) {
    s32 converted0;
    s32 converted1;
    void* object;

    converted0 = value0;
    converted1 = value1;
    object = (u8*)&lbl_1_bss_7AEB8 + 0x210;
    fn_1_8CED0(object, converted0, converted1);
    fn_1_8D0A4(object);
}
/* fzgx:end fn_1_E87A4 */

/* fzgx:begin fn_1_E87FC */
typedef struct {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
} PhysObj;

void fn_1_E87FC(PhysObj *obj) {
    u8 *entry;
    s16 i;
    Obj_1_bss_7AEB8 *global;
    u8 work[0x30];

    fn_800734A8(obj->unk_C, obj->unk_10, obj->unk_18, 4);
    fn_80072EDC(obj->unk_C, 1);
    fn_800745A4(obj->unk_10, 0, 0, obj->unk_14, 0, 0x7d);
    fn_80073778((u8 *)&lbl_1_bss_7AEB8 + 0x274, obj->unk_18);
    global = &lbl_1_bss_7AEB8;

    i = 0;
    entry = (u8 *)global;
    while (i < global->unk_1E4) {
        f32 value = global->unk_20C;
        fn_80015C1C(work, global->unk_1EC, global->unk_1F0,
                    global->unk_1F4, global->unk_1F8, global->unk_1FC,
                    global->unk_200, global->unk_204, global->unk_208, value);
        lbl_8006DFFC(work, entry + 4, work);
        GXLoadTexMtxImm(work, obj->unk_14, 0);
        entry += 0x30;
        i++;
    }

    obj->unk_C++;
    obj->unk_18++;
    obj->unk_14++;
    obj->unk_10++;
}
/* fzgx:end fn_1_E87FC */

/* fzgx:begin fn_1_E8938 noprologue */
#include "psvec.h"

typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef float f32;

/* lbl_1_bss_8B3A0: .bss size 0x14C, referenced by 87 functions, shape {'object': 253} */
/* object reached through lbl_1_bss_8B3A0.unk_A4 */
typedef struct {
u8 pad_0[0x19];
u8 unk_19; /* 1 loads, 0 stores */
} Obj_1_bss_8B3A0_AtA4;
typedef struct {
s16 unk_0; /* 12 loads, 2 stores */
u8 pad_2[0x2];
s16 unk_4; /* 13 loads, 0 stores */
u8 pad_6[0x2];
s16 unk_8; /* 7 loads, 2 stores */
u8 pad_A[0x4];
s16 unk_E; /* 24 loads, 0 stores */
u8 pad_10[0x4];
u8 unk_14; /* 7 loads, 2 stores */
u8 pad_15[0x19];
s16 unk_2E; /* 1 loads, 0 stores */
u8 pad_30[0x5C];
s16 unk_8C; /* 2 loads, 0 stores */
u8 pad_8E[0x2];
s16 unk_90; /* 15 loads, 0 stores */
s16 unk_92; /* 1 loads, 0 stores */
u32 unk_94; /* 60 loads, 3 stores */
u8 pad_98[0x6];
u8 unk_9E; /* 7 loads, 0 stores */
u8 unk_9F; /* 8 loads, 3 stores */
u8 pad_A0[0x4];
Obj_1_bss_8B3A0_AtA4 *unk_A4; /* 4 loads, 0 stores */
u8 pad_A8[0x8];
s16 unk_B0; /* 1 loads, 1 stores */
s16 unk_B2; /* 1 loads, 1 stores */
u8 pad_B4[0xC];
s16 unk_C0; /* 2 loads, 4 stores */
s16 unk_C2; /* 2 loads, 4 stores */
u8 pad_C4[0xC];
s16 unk_D0; /* 1 loads, 2 stores */
s16 unk_D2; /* 1 loads, 2 stores */
u8 pad_D4[0xC];
u32 unk_E0; /* 0 loads, 2 stores */
u32 unk_E4; /* 0 loads, 1 stores */
u32 unk_E8; /* 0 loads, 1 stores */
u32 unk_EC; /* 0 loads, 1 stores */
u32 unk_F0; /* 2 loads, 2 stores */
u32 unk_F4; /* 0 loads, 1 stores */
u32 unk_F8; /* 0 loads, 1 stores */
u32 unk_FC; /* 0 loads, 1 stores */
u32 unk_100; /* 2 loads, 2 stores */
u32 unk_104; /* 0 loads, 1 stores */
u32 unk_108; /* 0 loads, 1 stores */
u32 unk_10C; /* 0 loads, 1 stores */
u32 unk_110; /* 2 loads, 2 stores */
u32 unk_114; /* 0 loads, 1 stores */
u32 unk_118; /* 0 loads, 1 stores */
u32 unk_11C; /* 0 loads, 1 stores */
u32 unk_120; /* 0 loads, 2 stores */
u32 unk_124; /* 1 loads, 2 stores */
u8 unk_128; /* 0 loads, 1 stores */
u8 unk_129; /* 1 loads, 2 stores */
u8 pad_12A[0x2];
s16 unk_12C; /* 4 loads, 0 stores */
s16 unk_12E; /* 1 loads, 0 stores */
s16 unk_130; /* 1 loads, 0 stores */
s16 unk_132; /* 1 loads, 0 stores */
s16 unk_134; /* 1 loads, 0 stores */
s16 unk_136; /* 1 loads, 0 stores */
s16 unk_138; /* 1 loads, 0 stores */
s16 unk_13A; /* 1 loads, 0 stores */
s16 unk_13C; /* 1 loads, 0 stores */
u8 pad_13E[0x2];
u32 unk_140; /* 3 loads, 0 stores */
u8 pad_144[0x2];
s16 unk_146; /* 4 loads, 0 stores */
s16 unk_148; /* 2 loads, 0 stores */
u8 pad_14A[0x2];
} Obj_1_bss_8B3A0;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;
/* lbl_1_bss_3BE0: .bss size 0x4, referenced by 77 functions, shape {'object': 259, 'pointer': 61} */
typedef struct {
u32 unk_0; /* 7 loads, 0 stores */
f32 unk_4; /* 1 loads, 0 stores */
u32 unk_8; /* 28 loads, 0 stores */
u32 unk_C; /* 40 loads, 0 stores */
u8 pad_10[0x4];
u32 unk_14; /* 2 loads, 1 stores */
u32 unk_18; /* 9 loads, 0 stores */
u32 unk_1C; /* 11 loads, 1 stores */
u8 pad_20[0x4];
u32 unk_24; /* 2 loads, 1 stores */
u8 pad_28[0x4];
u32 unk_2C; /* 1 loads, 1 stores */
u8 pad_30[0xC];
u32 unk_3C; /* 1 loads, 1 stores */
u8 pad_40[0x4];
u32 unk_44; /* 1 loads, 1 stores */
u32 unk_48; /* 22 loads, 0 stores */
u32 unk_4C; /* 1 loads, 0 stores */
u32 unk_50; /* 1 loads, 0 stores */
u32 unk_54; /* 40 loads, 1 stores */
u8 pad_58[0x4];
u32 unk_5C; /* 1 loads, 0 stores */
u32 unk_60; /* 1 loads, 1 stores */
u32 unk_64; /* 3 loads, 0 stores */
u32 unk_68; /* 6 loads, 1 stores */
u32 unk_6C; /* 1 loads, 0 stores */
u32 unk_70; /* 2 loads, 1 stores */
u32 unk_74; /* 1 loads, 0 stores */
u32 unk_78; /* 1 loads, 1 stores */
u8 pad_7C[0x1];
u8 unk_7D; /* 11 loads, 0 stores */
u8 pad_7E[0x2];
u32 unk_80; /* 5 loads, 1 stores */
u32 unk_84; /* 2 loads, 1 stores */
u32 unk_88; /* 1 loads, 0 stores */
u32 unk_8C; /* 1 loads, 1 stores */
u32 unk_90; /* 10 loads, 1 stores */
u32 unk_94; /* 1 loads, 0 stores */
u32 unk_98; /* 2 loads, 1 stores */
u32 unk_9C; /* 1 loads, 0 stores */
u32 unk_A0; /* 2 loads, 1 stores */
u32 unk_A4; /* 7 loads, 0 stores */
u32 unk_A8; /* 7 loads, 1 stores */
u32 unk_AC; /* 1 loads, 0 stores */
u32 unk_B0; /* 2 loads, 1 stores */
u32 unk_B4; /* 6 loads, 0 stores */
u32 unk_B8; /* 4 loads, 1 stores */
u32 unk_BC; /* 5 loads, 1 stores */
f32 unk_C0; /* 1 loads, 0 stores */
f32 unk_C4; /* 1 loads, 0 stores */
f32 unk_C8; /* 1 loads, 0 stores */
f32 unk_CC; /* 1 loads, 0 stores */
u32 unk_D0; /* 3 loads, 0 stores */
u32 unk_D4; /* 2 loads, 0 stores */
} Obj_1_bss_3BE0_Target;
extern Obj_1_bss_3BE0_Target *lbl_1_bss_3BE0;

/* Generated by `fzgx headers --module main_rel --tu phys.c`: globals of phys.c (referenced by its */
/* functions or living in its .data block), layouts recovered from every access in the module. */
/* lbl_1_bss_7AE88: .bss size 0x30, 11 refs from phys.c */
/* one layout for every TU header that declares this symbol (librarian, typedefs.json) */
typedef struct {
u8 pad_0[0x554];
f32 unk_554; /* 1 loads, 0 stores */
u8 pad_558[0x24];
f32 unk_57C; /* 1 loads, 0 stores */
u8 pad_580[0x6C];
f32 unk_5EC; /* 1 loads, 0 stores */
u8 pad_5F0[0x14EC];
f32 unk_1ADC; /* 1 loads, 0 stores */
u8 pad_1AE0[0x24];
f32 unk_1B04; /* 1 loads, 0 stores */
u8 pad_1B08[0x6C];
f32 unk_1B74; /* 1 loads, 0 stores */
u8 pad_1B78[0xAFC];
f32 unk_2674; /* 1 loads, 0 stores */
u8 pad_2678[0x24];
f32 unk_269C; /* 1 loads, 0 stores */
u8 pad_26A0[0x6C];
f32 unk_270C; /* 1 loads, 0 stores */
u8 pad_2710[0x508C];
f32 unk_779C; /* 2 loads, 0 stores */
u8 pad_77A0[0x24];
f32 unk_77C4; /* 2 loads, 0 stores */
u8 pad_77C8[0x6C];
f32 unk_7834; /* 2 loads, 0 stores */
} Obj_1_bss_7AE88_At10;
typedef struct {
u32 unk_0; /* 13 loads, 3 stores */
s16 unk_4; /* 12 loads, 3 stores */
u8 pad_6[0x2];
u32 unk_8; /* 12 loads, 3 stores */
s16 unk_C; /* 11 loads, 5 stores */
u8 pad_E[0x2];
Obj_1_bss_7AE88_At10 *unk_10; /* 20 loads, 3 stores */
s16 unk_14; /* 11 loads, 5 stores */
u8 pad_16[0x2];
u32 unk_18; /* 12 loads, 3 stores */
s16 unk_1C; /* 11 loads, 3 stores */
u8 pad_1E[0x2];
u32 unk_20; /* 12 loads, 3 stores */
s16 unk_24; /* 11 loads, 4 stores */
u8 pad_26[0x2];
u32 unk_28; /* 12 loads, 3 stores */
s16 unk_2C; /* 12 loads, 5 stores */
u8 pad_2E[0x2];
} Obj_1_bss_7AE88;
extern Obj_1_bss_7AE88 lbl_1_bss_7AE88;

/* lbl_1_data_3DC98: .data size 0x6, 4 refs from phys.c */
extern u32 lbl_1_data_3DC98;

/* Paired-single vector kernels recovered from retail code (2026-09-15).
 *
 * Retail's x/y lanes are handled by psq_l/psq_st with a displacement and the
 * z lane by lfs/stfs. MWCC's __vec2x32float__ type only ever emits the indexed
 * psq_lx/psq_stx forms, so the displacement form can come only from inline
 * assembly inlined into the caller; the compiler then allocates the registers
 * and schedules these instructions together with the surrounding code, which
 * is what the retail streams show. Pointers are untyped so every per-block Vec
 * typedef can be passed without a cast. */
/* ab = a - b */
typedef struct E8938Vec { f32 x, y, z; } E8938Vec;
typedef struct E8938State { u8 pad0[0x90]; s32 *current; } E8938State;
typedef struct Sig_fn_1_24F10_Fn_1_24F10 {
int flags;
unsigned char pad04[0x2c];
f32 field30;
unsigned char pad34[0x150];
f32 field184;
unsigned char pad188[0x34];
E8938Vec field1bc;
unsigned char pad1c8[0x4c];
u16 field214;
unsigned char pad216[0x0e];
f32 field224;
unsigned char pad228[0x24d];
u8 field475;
unsigned char pad476[0x26];
E8938State *field49c;
unsigned char pad4a0[0xc];
f32 field4ac;
unsigned char pad4b0[0xe3];
u8 field593;
unsigned char pad594[0x46];
u16 field5da;
} Sig_fn_1_24F10_Fn_1_24F10;
typedef struct E8938Render {
u8 pad0[8]; E8938Vec center; f32 radius;
u8 pad18[0xc]; void *field24;
} E8938Render;
typedef struct E8938Frame { u32 field0; char *name; E8938Render *object; u32 fieldc; } E8938Frame;
typedef struct E8938Model { u32 field0; s32 count; E8938Frame *frames; } E8938Model;
typedef struct E8938Entry { u8 pad0[8]; E8938Model *model; u8 padc[0x34]; } E8938Entry;
typedef struct E8938Phys {
E8938Render *render; u32 field4; s16 id; u8 pada[0x4a];
E8938Vec pos; u8 pad60[0x24]; f32 scale;
u8 pad88[0x3c]; f32 matrix[12];
f32 sx, sy, sz; s32 sector;
u8 pad104[0x34]; u64 flags; u8 pad140[0x68];
} E8938Phys;
typedef struct E8938Angles { s16 x,y,z; } E8938Angles;
typedef struct E8938Mtx { f32 m[12]; } E8938Mtx;
extern Sig_fn_1_24F10_Fn_1_24F10 *fn_1_86254(int);
extern u32 strlen(const char *);
extern s32 fn_8006FC5C(void *, void *, u32);
extern void fn_80073778(void *, s32);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFE8(void *);
extern void fn_80072558(void);
extern void fn_1_5621C(f32,f32,f32,f32);
extern s32 fn_1_54E34(void *,f32);
extern void fn_1_556B8(void *);
extern s32 fn_1_54F5C(void *,f32,f32);
extern int sprintf(char *, const char *, ...);
extern void fn_80074918(u8,s32,u8);
extern void fn_1_681C(u32,void *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void fn_80008BA8(void *,void *,u32);
extern void fn_8006E978(void *,void *,void *);
extern void mathutil_mtxA_from_quat(void *);
extern void fn_8006F6A8(void *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E15C(f32,f32,f32);
extern void fn_800728A8(s32,s32,s32,s32);
extern void fn_80072864(u32);
extern u32 fn_80037E30(u8);
static inline E8938Entry *E8938_find(char *name) {
s16 i;
for (i=0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) {
if (fn_8006FC5C(((E8938Entry *)lbl_1_bss_3BE0->unk_54)[i].model->frames->name,
name,strlen(name)))
return &((E8938Entry *)lbl_1_bss_3BE0->unk_54)[i];
}
return 0;
}
static inline E8938Phys *E8938_get_impl(Obj_1_bss_7AE88 *groups,s16 group,s16 index) {
switch(group) {
case 0: return &((E8938Phys *)groups->unk_0)[index];
case 1: return &((E8938Phys *)groups->unk_8)[index];
case 2: return &((E8938Phys *)groups->unk_10)[index];
case 3: return &((E8938Phys *)groups->unk_18)[index];
case 4: return &((E8938Phys *)groups->unk_20)[index];
case 5: return &((E8938Phys *)groups->unk_28)[index];
}
return 0;
}
static inline s16 E8938_count_impl(Obj_1_bss_7AE88 *groups,s16 group) {
switch(group) {
case 0: return groups->unk_4;
case 1: return groups->unk_C;
case 2: return groups->unk_14;
case 3: return groups->unk_1C;
case 4: return groups->unk_24;
case 5: return groups->unk_2C;
}
return -1;
}
#if 0
extern u8 lbl_1_data_3DF68__fzgx_offset_0[];
extern u8 lbl_1_data_3DF70__fzgx_offset_0[];
extern u8 lbl_1_data_3DF78__fzgx_offset_0[];
extern u8 lbl_1_data_3DF80__fzgx_offset_0[];
extern u8 lbl_1_data_3DF8C__fzgx_offset_0[];
extern u8 lbl_1_data_3DF98__fzgx_offset_0[];
extern u8 lbl_1_data_3DFA4__fzgx_offset_0[];
extern u8 lbl_1_data_3DFB0__fzgx_offset_0[];
extern u8 lbl_1_data_3DFB8__fzgx_offset_0[];
extern u8 lbl_1_data_3DFC0__fzgx_offset_0[];
extern u8 lbl_1_data_3DFC8__fzgx_offset_0[];
extern u8 lbl_1_data_3DFD8__fzgx_offset_0[];
extern u8 lbl_1_data_3DFE4__fzgx_offset_0[];
extern u8 lbl_1_data_3DFF0__fzgx_offset_0[];
extern u8 lbl_1_data_3DFF8__fzgx_offset_0[];
extern u8 lbl_1_data_3E004__fzgx_offset_0[];
extern u8 lbl_1_data_3E00C__fzgx_offset_0[];
extern u8 lbl_1_data_3E01C__fzgx_offset_0[];
extern u8 lbl_1_data_3E02C__fzgx_offset_0[];
extern u8 lbl_1_data_3E034__fzgx_offset_0[];
extern u8 lbl_1_data_3E03C__fzgx_offset_0[];
extern u8 lbl_1_data_3E048__fzgx_offset_0[];
extern u8 lbl_1_data_3E058__fzgx_offset_0[];
extern u8 lbl_1_data_3E064__fzgx_offset_0[];
extern u8 lbl_1_data_3E070__fzgx_offset_0[];
extern u8 lbl_1_data_3E07C__fzgx_offset_0[];
extern u8 lbl_1_data_3E088__fzgx_offset_0[];
extern u8 lbl_1_data_3E094__fzgx_offset_0[];
extern u8 lbl_1_data_3E09C__fzgx_offset_0[];
extern u8 lbl_1_data_3E0A4__fzgx_offset_0[];
extern u8 lbl_1_data_3E0B0__fzgx_offset_0[];
extern u8 lbl_1_data_3E0B8__fzgx_offset_0[];
extern u8 lbl_1_data_3E0C0__fzgx_offset_0[];
extern u8 lbl_1_data_3E0CC__fzgx_offset_0[];
extern u8 lbl_1_data_3E0D8__fzgx_offset_0[];
extern u8 lbl_1_data_3E0E4__fzgx_offset_0[];
extern u8 lbl_1_data_3E0E8__fzgx_offset_0[];
extern u8 lbl_1_data_3E0F4__fzgx_offset_0[];
extern u8 lbl_1_data_3E100__fzgx_offset_0[];
extern u8 lbl_1_data_3E10C__fzgx_offset_0[];
extern u8 lbl_1_data_3E114__fzgx_offset_0[];
extern u8 lbl_1_data_3E120__fzgx_offset_0[];
extern u8 lbl_1_data_3E128__fzgx_offset_0[];
extern u8 lbl_1_data_3E130__fzgx_offset_0[];
extern u8 lbl_1_data_3E138__fzgx_offset_0[];
extern u8 lbl_1_data_3E140__fzgx_offset_0[];
extern u8 lbl_1_data_3E148__fzgx_offset_0[];
extern u8 lbl_1_data_3E198__fzgx_offset_0[];
extern u8 lbl_1_data_3E19C__fzgx_offset_0[];
extern u8 lbl_1_data_3E1A0__fzgx_offset_0[];
extern u8 lbl_1_data_3E1A4__fzgx_offset_0[];
extern u8 lbl_1_data_3E1A8__fzgx_offset_0[];
static const u32 fzgx_pool_rodata_lbl_1_rodata_6780[8] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xBF800000, 0x3F7FFFFE, 0x3F800001, 0xBF800001, 0xBF7FFFFE, 0x0, 0x3E800000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_6780_20[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x40A00000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_67A8[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F800000, 0xFF00FF, 0x3DCCCCCD
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_67B4[39] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F000000, 0x41200000, 0x43360B61, 0x43300000, 0x0, 0xBB326750, 0x0, 0x3F800000,
    0x0, 0x0, 0x3F800000, 0x0, 0x3F800000, 0x0, 0x0, 0x38C90FDB,
    0x3FC00000, 0xB4000000, 0x34000000, 0x43300000, 0x80000000, 0x42700000, 0x49742400, 0x48742400,  /* fzgx-allow: A1 retail data bytes */
    0x41A00000, 0x0, 0x3F800000, 0x0, 0x0, 0x3F800000, 0x0, 0xBC23D70A,
    0x3C23D70A, 0xBF8147AE, 0x38D1B717, 0x0, 0x3F800000, 0x0, 0x3F7D70A4
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_6780_D0[81] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40000000, 0x80000000, 0x406B0000, 0x0, 0x400921FB, 0x60000000, 0x40100000, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x404E0000, 0x0, 0x3F8147AE, 0x3D4CCCCD, 0x3F8020C5, 0x3F666666, 0x40400000, 0x3FE00000,
    0x40F00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40A00000, 0x3F4CCCCD, 0x3ADA740E, 0x3E99999A,
    0x3C888889, 0x4B189680, 0x4A989680, 0x42C80000, 0x0, 0x3F800000, 0x0, 0x1060002,
    0x5800A6, 0x5800A6, 0x5800A6, 0x5800A6, 0x5800A6, 0x5800A6, 0x5800A6, 0x5800A6,
    0xFE0001, 0x5800A6, 0x5800A6, 0x5800A7, 0x5800A7, 0x5800A7, 0x5800A7, 0x5800A7,
    0x5800A7, 0x5A00A8, 0x5C00A8, 0x1000002, 0x5F00A8, 0x5C00A8, 0xFE0000, 0xFE0000,
    0xFE0000, 0xFE0000, 0xFE0000, 0xFE0000, 0xFE0000, 0xFE0000, 0xFE0000, 0xFE0000,
    0x1020002, 0x20103, 0xFE0001, 0xFE0001, 0xFE0001, 0xFE0001, 0xFE0001, 0x3C8EFA35,
    0xC0400000, 0x40400000, 0xC0400000, 0x40400000, 0x41200000, 0x3F000000, 0x3F000000, 0x3F000000,  /* fzgx-allow: A1 retail data bytes */
    0x3F000000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_6994[92] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43A00000, 0x43600000, 0x0, 0x43700000, 0x437F0000, 0x44200000, 0x43F00000, 0x3FA2A2A3,
    0x0, 0x3F800000, 0x0, 0xC61C4000, 0x46AFC800, 0x4622F983, 0x3ECCCCCD, lbl_1_data_3DF68__fzgx_offset_0,
    lbl_1_data_3DF70__fzgx_offset_0, lbl_1_data_3DF78__fzgx_offset_0, lbl_1_data_3DF80__fzgx_offset_0, lbl_1_data_3DF8C__fzgx_offset_0, lbl_1_data_3DF98__fzgx_offset_0, lbl_1_data_3DFA4__fzgx_offset_0, lbl_1_data_3DFB0__fzgx_offset_0, lbl_1_data_3DFB8__fzgx_offset_0,
    lbl_1_data_3DFC0__fzgx_offset_0, lbl_1_data_3DFC8__fzgx_offset_0, lbl_1_data_3DFD8__fzgx_offset_0, lbl_1_data_3DFE4__fzgx_offset_0, lbl_1_data_3DFF0__fzgx_offset_0, lbl_1_data_3DFF8__fzgx_offset_0, lbl_1_data_3E004__fzgx_offset_0, lbl_1_data_3E00C__fzgx_offset_0,
    lbl_1_data_3E01C__fzgx_offset_0, lbl_1_data_3E02C__fzgx_offset_0, lbl_1_data_3E034__fzgx_offset_0, lbl_1_data_3E03C__fzgx_offset_0, lbl_1_data_3E048__fzgx_offset_0, lbl_1_data_3E058__fzgx_offset_0, lbl_1_data_3E064__fzgx_offset_0, lbl_1_data_3E070__fzgx_offset_0,
    lbl_1_data_3E07C__fzgx_offset_0, lbl_1_data_3E088__fzgx_offset_0, lbl_1_data_3E094__fzgx_offset_0, lbl_1_data_3E09C__fzgx_offset_0, lbl_1_data_3E0A4__fzgx_offset_0, lbl_1_data_3E0B0__fzgx_offset_0, lbl_1_data_3E0B8__fzgx_offset_0, lbl_1_data_3E0C0__fzgx_offset_0,
    lbl_1_data_3E0CC__fzgx_offset_0, lbl_1_data_3E0D8__fzgx_offset_0, lbl_1_data_3E0E4__fzgx_offset_0, lbl_1_data_3E0E8__fzgx_offset_0, lbl_1_data_3E0F4__fzgx_offset_0, lbl_1_data_3E100__fzgx_offset_0, lbl_1_data_3E10C__fzgx_offset_0, lbl_1_data_3E114__fzgx_offset_0,
    lbl_1_data_3E120__fzgx_offset_0, lbl_1_data_3E128__fzgx_offset_0, lbl_1_data_3E130__fzgx_offset_0, lbl_1_data_3E138__fzgx_offset_0, lbl_1_data_3E140__fzgx_offset_0, lbl_1_data_3E148__fzgx_offset_0, 0x0, 0x3F800000,
    0x0, 0xFFFFFFFF, 0x0, 0x3F800000, 0x0, 0x42480000, 0xBDCCCCCD, lbl_1_data_3E198__fzgx_offset_0,
    lbl_1_data_3E19C__fzgx_offset_0, lbl_1_data_3E1A0__fzgx_offset_0, lbl_1_data_3E1A4__fzgx_offset_0, lbl_1_data_3E1A8__fzgx_offset_0, 0xFF0000, 0xFFFFFF00, 0x43E10000, 0xFF00FF,
    0xFFFF00, 0xFF000000, 0x0, 0x0, 0x0, 0x447A0000, 0x0, 0x3F800000,
    0x0, 0x42480000, 0x0, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_6780_384[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_6780_390[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x3F800000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_6780_39C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xC0400000  /* fzgx-allow: A1 retail data bytes */
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_6780_3A0[16] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xC0000000, 0x43330000, 0x425C0000, 0x47AFC800, 0x0, 0x0, 0x3F800000, 0xFF0000,  /* fzgx-allow: A1 retail data bytes */
    0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0x43480000, 0xFFFF0000, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_rodata_6780(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_6780;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_20;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_67A8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_67B4;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_D0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_6994;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_384;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_390;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_39C;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_3A0;
}
#pragma section code_type ".text"
#endif
extern const f32 lbl_1_rodata_6780[];
#define fzgx_pool_rodata_lbl_1_rodata_6780 (pool)
#define fzgx_pool_rodata_lbl_1_rodata_6780_20 (pool+0x20)
#define fzgx_pool_rodata_lbl_1_rodata_67A8 (pool+0x28)
#define fzgx_pool_rodata_lbl_1_rodata_6780_D0 (pool+0xd0)
#define fzgx_pool_rodata_lbl_1_rodata_6780_384 (pool+0x384)
#define fzgx_pool_rodata_lbl_1_rodata_6780_390 (pool+0x390)
#define fzgx_pool_rodata_lbl_1_rodata_6780_39C (pool+0x39c)
#define fzgx_pool_rodata_lbl_1_rodata_6780_3A0 (pool+0x3a0)
extern void *game_camera_get(void);
static inline f32 E8938_lensq(E8938Vec *v) {
f32 mag;
mag=v->x*v->x;
mag=__fmadds(v->y,v->y,mag);
mag=__fmadds(v->z,v->z,mag);
return mag;
}
static inline s32 E8938_overlap(E8938Phys *a, E8938Phys *b, u8 *pool) {
E8938Vec d;
f32 r;
psvec_sub(&a->pos, &b->pos, &d);
d.y=*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_20));
r=a->scale*a->sx;
if ((r+(f32)(b->scale*b->sx))*(r+(f32)(b->scale*b->sx)) >= E8938_lensq(&d)) return 1;
return 0;
}
#pragma opt_lifetimes off
s32 fn_1_E8938(u32 arg0, u32 arg1) {
u8 *p_lbl_1_data_3DC98;
u8 *pool;
Obj_1_bss_7AE88 *p_lbl_1_bss_7AE88;
s32 v0;
s32 v1;
Sig_fn_1_24F10_Fn_1_24F10 *v2;
Sig_fn_1_24F10_Fn_1_24F10 *t0;
E8938Mtx matrix;
char name[32];
E8938Vec delta;
E8938Vec base;
E8938Vec facing;
f32 quat[4];
E8938Vec origin;
E8938Angles angles;
E8938Entry *entry;
E8938Render *render;
E8938Phys *p;
s16 j;
s16 i;
s16 k;
s32 visible;
s32 near;
s32 middle;
s16 distance;
s32 difference;
s32 mode;
f32 factor1;
f32 factor2;
f32 size;
f32 depth;
f32 f;
p_lbl_1_data_3DC98=(u8 *)&lbl_1_data_3DC98;
p_lbl_1_bss_7AE88=(Obj_1_bss_7AE88 *)&lbl_1_bss_7AE88;
pool=(u8 *)lbl_1_rodata_6780;

t0=fn_1_86254(lbl_1_bss_8B3A0.unk_9E);
v0=0;
v1=0;
v2=t0;
entry=E8938_find((char *)(p_lbl_1_data_3DC98+0x674));
render=entry->model->frames->object;
fn_80073778(render->field24,0);
fn_80073778(render->field24,1);
origin=*(E8938Vec *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_384));
lbl_8006D7DC(&origin);
lbl_8006DB74(&matrix);
lbl_8006DFE8(&matrix);
fn_80072558();
f=(*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_20))) ;
fn_1_5621C(f,f,f,f);
for (i=2;i<=34;i++) {
if (*v2->field49c->current+3 < i || *v2->field49c->current-2 > i) continue;
sprintf(name,(char *)(p_lbl_1_data_3DC98+0x680),i);
if (i==11) sprintf(name,(char *)(p_lbl_1_data_3DC98+0x68c));
entry=E8938_find(name);
render=entry->model->frames[entry->model->count-1].object;
if (fn_1_54E34(&render->center,render->radius)) fn_1_556B8(render);
}
for (j=1;j<=5;j++) {
sprintf(name,(char *)(p_lbl_1_data_3DC98+0x698),j);
entry=E8938_find(name);
render=entry->model->frames[entry->model->count-1].object;
if (fn_1_54E34(&render->center,render->radius)) fn_1_556B8(render);
}
f=(*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_67A8))) ;
fn_1_5621C(f,f,f,f);
fn_80074918(1,1,0);
for(i=0;i<6;i++) {
for(k=0;k<E8938_count_impl(p_lbl_1_bss_7AE88,i) ;k++) {
visible=0; near=0; middle=0;
p=E8938_get_impl(p_lbl_1_bss_7AE88,i,k) ;
lbl_8006DFE8(&p->matrix);
if(fn_1_54F5C(&p->render->center,p->render->radius,(((p->sx>p->sy?p->sx:p->sy))>p->sz?((p->sx>p->sy?p->sx:p->sy)):p->sz) )) visible=1;
difference=p->sector-*v2->field49c->current;
distance=difference < 0 ? -difference : difference;
if(distance<2) near=1;
else if(distance<4) middle=1;
else continue;
if (!(p->flags & 0x2000000000ULL)) continue;
if(visible!=1 && near!=1) continue;
mode=5;
if(near==1) mode=16;
else if(middle==1) mode=6;
base=*(E8938Vec *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_390));
size=p->sx*p->scale;
depth=(*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_D0))) *size;
fn_1_681C(v2->field475,&delta);
psvec_sub(&p->pos,&delta,&delta);
delta.y=(*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_20))) ;
mathutil_mtxA_rotate_x(0x4000);
{
f32 x, z, y, mag;
x=delta.x;
y=delta.y;
mag=x*x;
mag=__fmadds(y,y,mag);
z=delta.z;
mag=__fmadds(z,z,mag);
f=mag;
}
if(((*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_D0))) +size)*((*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_D0))) +size)>=f) {
if(*(s16 *)((u8 *)game_camera_get()+0xa4)==0) continue;
fn_80008BA8(&facing,&v2->field1bc,12);
fn_8006E978(quat,&base,&facing);
mathutil_mtxA_from_quat(quat);
fn_8006F6A8(&angles);
factor1=(*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_39C))) *size;
psvec_scale(&facing,factor1,&facing);
} else {
facing.x=(*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_20))) ; facing.y=(*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_67A8))) ; facing.z=(*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_20))) ;
fn_8006E978(quat,&base,&facing);
mathutil_mtxA_from_quat(quat);
fn_8006F6A8(&angles);
factor2=(*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780_3A0))) *size;
psvec_scale(&facing,factor2,&facing);
}
lbl_8006D7DC(&p->pos);
lbl_8006E0A4(&facing);
mathutil_mtxA_rotate_z(angles.z);
mathutil_mtxA_rotate_y(angles.y);
mathutil_mtxA_rotate_x(angles.x);
lbl_8006E15C(size,size,depth);
lbl_8006DB74(&matrix);
lbl_8006DFE8(&matrix);
fn_80072558();
if(p->id==4 && E8938_overlap(p,&((E8938Phys *)p_lbl_1_bss_7AE88->unk_10)[3],((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780)) ) continue;
if(p->id==15 && E8938_overlap(p,&((E8938Phys *)p_lbl_1_bss_7AE88->unk_10)[16],((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780)) ) continue;
if(p->id==22 && E8938_overlap(p,&((E8938Phys *)p_lbl_1_bss_7AE88->unk_10)[23],((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780)) ) continue;
if(p->id==63 && E8938_overlap(p,&((E8938Phys *)p_lbl_1_bss_7AE88->unk_10)[72],((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780)) ) continue;
if(p->id==69 && E8938_overlap(p,&((E8938Phys *)p_lbl_1_bss_7AE88->unk_10)[72],((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780)) ) continue;
if(p->id==103 && E8938_overlap(p,&((E8938Phys *)p_lbl_1_bss_7AE88->unk_10)[117],((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780)) ) continue;
if(p->id==104 && E8938_overlap(p,&((E8938Phys *)p_lbl_1_bss_7AE88->unk_10)[118],((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780)) ) continue;
if(p->id==115 && E8938_overlap(p,&((E8938Phys *)p_lbl_1_bss_7AE88->unk_10)[116],((u8 *)fzgx_pool_rodata_lbl_1_rodata_6780)) ) continue;
fn_80074918(1,1,0);
fn_800728A8(2,1,0,10);
fn_80072864(1);
fn_80037E30(mode);
fn_800728A8(2,1,0,10);
fn_80072864(2);
fn_80037E30(mode);
}
}
fn_80072864(2);
fn_800728A8(0,1,0,10);
fn_80074918(1,1,1);
return 0;
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_E8938 */

/* fzgx:begin fn_1_E95B4 */
typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;
    f32 unk_C;
} Camera;

extern Camera *game_camera_get(void);

void fn_1_E95B4(void) {
    f32 *table = lbl_1_rodata_6780;
    Obj_1_bss_7AEB8 *state;
    Obj_1_bss_7AEB8 *state_after;
    Obj_1_bss_7AEB8 *state_final;
    Camera *camera;
    f32 camera_y;

    if ((lbl_1_bss_7AEB8.unk_0 & (0xFFFFFFFFu << 31)) == 0) {
        return;
    }

    camera = game_camera_get();
    state = &lbl_1_bss_7AEB8;
    state->unk_254 = camera->unk_8;
    camera = game_camera_get();
    camera_y = state->unk_254;
    state_after = &lbl_1_bss_7AEB8;
    state_after->unk_258 = camera->unk_C;

    if (camera_y < table[10] || camera_y > table[233]) {
        state->unk_254 = table[234];
        state_after->unk_258 = fn_1_A6FE8();
    }

    state_final = &lbl_1_bss_7AEB8;
    state_final->unk_25C = table[12];
    state_final->unk_260 = table[235];
    fn_1_8D1C8((u8 *)state_final + 0x210, fn_1_E8938, 0);
}
/* fzgx:end fn_1_E95B4 */
