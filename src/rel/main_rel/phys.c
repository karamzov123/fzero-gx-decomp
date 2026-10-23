#include "types.h"
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
extern u32 fn_80083970(const u8* left, const char* right);
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

#pragma opt_common_subs off
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
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (u32)(count * 0x1A8),
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
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (u32)(count * 0x1A8),
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
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (u32)(count * 0x1A8),
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
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (u32)(count * 0x1A8),
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
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (u32)(count * 0x1A8),
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
        ptr = (Elem1A8 *)fn_1_4630(lbl_801A6410, (u32)(count * 0x1A8),
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
#pragma opt_common_subs reset
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
extern char *fn_80083DB0(char *dst, const char *src);
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
struct { const char *value; } strtab;
s16 result;
Obj_1_data_2A7E0_At3C *state;
s32 i;
fn_1_E1E9C_PhysEntry *entry;
s16 j;
state = lbl_1_data_2A7E0.unk_3C;
strtab.value = (const char *)&lbl_1_data_3DC98;
if ((obj->flags & 0x2000000ULL) != 0) {
switch (lbl_1_data_2B0D4[fn_1_7B054()]) {
case 1:
switch (obj->kind) {
case 1:
result = (s16)state->unk_0;
break;
default:
result = -1;
break;
}
break;
case 13:
switch (obj->kind) {
case 4:
result = (s16)state->unk_0;
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
result = (s16)lbl_1_bss_85288[0];
break;
case 5:
result = (s16)lbl_1_bss_85288[1];
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
fn_80083DB0(buf, strtab.value + 0x124);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { result = i; break; } } ;
fn_80083DB0(buf, strtab.value + 0x134);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { obj->slots[0] = i; break; } } ;
fn_80083DB0(buf, strtab.value + 0x14C);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { obj->slots[1] = i; break; } } ;
fn_80083DB0(buf, strtab.value + 0x164);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { obj->slots[2] = i; break; } } ;
break;
case 1:
fn_80083DB0(buf, strtab.value + 0x17C);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { result = i; break; } } ;
fn_80083DB0(buf, strtab.value + 0x180);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { obj->slots[0] = i; break; } } ;
fn_80083DB0(buf, strtab.value + 0x18C);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { obj->slots[1] = i; break; } } ;
fn_80083DB0(buf, strtab.value + 0x198);
for (i = 0; i < (s32)lbl_1_bss_3BE0->unk_48; i++) { if (fn_8006FC5C((*(fn_1_E1E9C_PhysEntry **)(lbl_1_bss_3BE0->unk_54 + i * 0x40 + 8))->info->name, buf, strlen(buf))) { obj->slots[2] = i; break; } } ;
break;
case 4:
fn_80083DB0(buf, strtab.value + 0x20);
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

/* fzgx:begin fn_1_E252C noprologue */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/phys.h"

#pragma force_active on
static const u32 fzgx_pool_table_0[10] = {0xbf800000, 0x3f7ffffe, 0x3f800001, 0xbf800001, 0xbf7ffffe, 0x0, 0x3e800000, 0x0, 0x0, 0x40a00000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_0(s32 value) {
    volatile f32 f; /* Intentional volatile: retain shared retail pool literals. */
    volatile f64 d; /* Intentional volatile: retain shared retail pool literals. */
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
    volatile f64 d; /* Intentional volatile: retain shared retail pool literals. */
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
    volatile f64 d; /* Intentional volatile: retain shared retail pool literals. */
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
    volatile f64 d; /* Intentional volatile: retain shared retail pool literals. */
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
extern const struct fn_1_E252C_lbl_1_rodata_6780 lbl_1_rodata_6780;
extern struct fn_1_E252C_lbl_801A63C0 lbl_801A63C0;
extern u32 fn_1_E86FC(Sig_fn_1_E86FC_StringValueTable *, const char *);
extern void fn_1_E1E9C(Sig_fn_1_E1E9C_fn_1_E1E9C_PhysObj *);

void fn_1_E252C(u32 arg0, u32 arg1, Sig_fn_1_E1E9C_fn_1_E1E9C_PhysObj * arg2) {
    const struct fn_1_E252C_lbl_1_rodata_6780 *p_lbl_1_rodata_6780;
    s16 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    f32 unk_1;
    f32 v5;
    f32 v6;
    f32 v7;
    f32 v8;
    f32 v9;
    f32 v10;
    f32 v11;
    u32 v12;
    u32 v13;
    f32 v14;
    struct { f32 value; } v15;
    f32 v16;
    f32 v17;
    u32 v18;
    u32 v19;
    u32 v20;
    f32 v21;
    f32 v22;
    f32 v23;
    f32 v24;
    f32 v25;
    u32 v26;
    u32 v27;
    u32 v28;
    f32 v29;
    f32 v30;
    f32 v31;
    f32 v32;
    f32 v33;
    f64 v34;
    f32 v35;
    u32 v36;
    f32 v37;
    u32 v38;
    f32 v39;
    s32 v40;
    f32 v41;
    f32 v42;
    f32 v43;
    f32 v44;
    f32 v45;
    u32 v46;
    u32 v47;
    f32 v48;
    struct { f32 value; } v49;
    f32 v50;
    f32 v51;
    u32 v52;
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
    v0 = (s16)arg0;
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
    v49.value = 1.0f;
    *(f32 *)((u8 *)arg2 + 24) = v48;
    v50 = 0.5f;
    *(f32 *)((u8 *)arg2 + 28) = v49.value;
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

/* fzgx:begin fn_1_E2AE8 noprologue */
#include "types.h"
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

extern PoolType lbl_1_rodata_6780;
extern s16 fn_1_E5430(s16);
extern Obj *fn_1_E54A8(s16, s16);
extern u8 *fn_1_14F04(void);
extern u32 fn_1_20A5C(void *, void *);
extern void fn_1_17920(u32, u32, f32);
extern s16 fn_1_7B054(void);
extern void fn_80008BA8(void *, void *, u32);
extern f32 lbl_8006D668(void *);

static inline f32 fn_1_E2AE8_read_pointer(PoolType * owner) { return owner->f0; }
#pragma opt_dead_assignments off
static inline void fn_1_E2AE8_call_fn_1_17920(u32 a0, u32 a1, f32 a2) { fn_1_17920(a0, a1, a2); }
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
        str = (u8 *)fn_1_14F04() + 0x45c;
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
    fn_1_8D168((Sig_fn_1_8D168_Fn1_8D168State *)((u32 *)&lbl_1_bss_7AEB8 + 132));
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
            fn_80077E0C(*(void **)((u8 *)*(void **)((u8 *)*(void **)((u8 *)lbl_1_bss_3BE0->unk_54 +
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

/* fzgx:begin fn_1_E39F0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
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
extern void fn_1_9C724(void);
extern s16 fn_1_E5430(s16);
extern Obj_1A8 *fn_1_E54A8(s16, s32);
extern void fn_1_DD890(Obj_1A8 *);
extern void fn_1_9CC40(void);
extern void fn_80077E0C(void *);
extern void fn_80076134(void);

void fn_1_E39F0(void) {

    if (lbl_1_bss_7AEB8.unk_0 & (1U << 31)) {
        LocalStruct sp8 = lbl_1_rodata_26F8;
        sp8.unk_4 = (320.0f);
        sp8.unk_8 = (240.0f);
        sp8.unk_C = (255.0f);
        sp8.unk_10 *= ((640.0f) / (f32)lbl_1_bss_7AEB8.unk_240);
        sp8.unk_14 *= ((480.0f) / (f32)lbl_1_bss_7AEB8.unk_242);
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
extern char * fn_80083DB0(char *, const char *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8EF8(u16, u16);

static inline u32 *fn_1_E4A38_array_read(u32 *array) { return array; }
#pragma opt_propagation off
static inline u32 fn_1_E4A38_array_read_(u32 *array, s32 index) { return array[index]; }
#pragma opt_lifetimes off
static inline u32 * fn_1_E4A38_read_pointer(struct D * owner) { return owner->unk_30; }
static inline char * fn_1_E4A38_call_strcat(const char * a1, char * a0) { return strcat(a0, a1); }
void fn_1_E4A38(u32 arg0, u16 arg1, u16 arg2, Cb arg3) {
    u8 * fzgx_live;
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
        fn_1_496FC((f32)(s32)(s16)arg1, (f32)(s32)(s16)arg2);
        fn_1_4955C(lbl_1_rodata_69CC, lbl_1_rodata_69CC);
    } else {
        if ((u32)arg3 == (u32)fn_1_A8DD4) {
            fn_1_A8EF8(arg1, arg2);
        }
    }
    v0 = *(u32 *)((u8 *)arg0 + 316);
    if ((*(u64 *)((u8 *)arg0 + 312) & 0x20000) != 0) {
        arg3(p_lbl_1_data_3DC98->s1b0, (s32)(s16)fn_1_E5724((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s1b0, (s32)(s16)fn_1_E573C((Sig_fn_1_E573C_E573CObj *)arg0));
    } else {
        arg3(p_lbl_1_data_3DC98->s1b8, (s32)(s16)fn_1_E5724((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s1c4, fn_1_E4A38_array_read_(fn_1_E4A38_read_pointer(p_lbl_1_data_3DC98), (s32)(s16)fn_1_E572C((void *)arg0)));
        arg3(p_lbl_1_data_3DC98->s1d0, fn_1_E57A4((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s1e0, fn_1_E57AC((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s1f0, fn_1_E57B4((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s200, fn_1_E57BC((void *)arg0));
        arg3(p_lbl_1_data_3DC98->s210, lbl_1_rodata_6808 * fn_1_E57EC((void *)arg0));
        fv = (f32 *)fn_1_E57CC((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s220);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        fv = (f32 *)fn_1_E57D4((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s238);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        fv = (f32 *)fn_1_E5750((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s240);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        arg3(p_lbl_1_data_3DC98->s248, fn_1_E5758((void *)arg0));
        fv = (f32 *)fn_1_E5748((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s258);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        fv = (f32 *)fn_1_E57DC((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s260);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        fv = (f32 *)fn_1_E5760((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s268);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, ((1)[fv]));
        arg3(p_lbl_1_data_3DC98->s230, ((2)[fv]));
        arg3(p_lbl_1_data_3DC98->s270, fn_1_E57E4((void *)arg0));
        fv = (f32 *)fn_1_E5768((void *)arg0);
        arg3(p_lbl_1_data_3DC98->s280);
        arg3(p_lbl_1_data_3DC98->s228, fv[0]);
        arg3(p_lbl_1_data_3DC98->s228, fv[1]);
        arg3(p_lbl_1_data_3DC98->s230, fv[2]);
        arg3(p_lbl_1_data_3DC98->s288, *(u32 *)((u8 *)arg0 + 0x100));
        arg3(p_lbl_1_data_3DC98->s294);
        arg3(p_lbl_1_data_3DC98->s228, *(f32 *)((u8 *)arg0 + 0x128));
        arg3(p_lbl_1_data_3DC98->s228, *(f32 *)((u8 *)arg0 + 0x12c));
        arg3(p_lbl_1_data_3DC98->s230, *(f32 *)((u8 *)arg0 + 0x130));
        loc_8[0] = 0;
        v1 = *(u32 *)((u8 *)arg0 + 316);
        if ((*(u64 *)((u8 *)arg0 + 312) & 0x80000000) != 0) {
            fn_80083DB0(loc_8, (const char *)p_lbl_1_data_3DC98->s29c);
        }
        v2 = *(u32 *)((u8 *)arg0 + 316);
        if ((*(u64 *)((u8 *)arg0 + 312) & 0x40000000) != 0) {
            fn_1_E4A38_call_strcat((const char *)p_lbl_1_data_3DC98->s2a4, loc_8);
        }
        v0 = *(u32 *)((u8 *)arg0 + 316);
        if ((*(u64 *)((u8 *)arg0 + 312) & 0x20000000) != 0) {
            strcat(loc_8, (const char *)(p_lbl_1_data_3DC98->s2ac));
        }
        arg3(p_lbl_1_data_3DC98->s2b4, loc_8);
        arg3(p_lbl_1_data_3DC98->s2c0);
        v3 = 0;
        while ((s16)v3 < 32) {
            t24 = fn_1_E57C4((void *)arg0);
            v4 = (s16)v3;
            if (((1 << v4) & t24) != 0) {
                arg3(p_lbl_1_data_3DC98->s2c8, v4);
            }
            v3++;
        }
        arg3(p_lbl_1_data_3DC98->s2cc);
    }
}
#pragma opt_lifetimes reset

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
    fn_1_E4A38(base, (s32)locals.values[0], (s32)locals.values[1], arg);
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
    v1 = (s32)out.v1;
    v0 = (s32)out.v0;
    tab = *(Tab *)&lbl_1_rodata_69D0;

    if (arg1 == (void *)fn_1_4AE0C) {
        fn_1_496FC((f32)(s16)v0, (f32)(s16)v1);
        fn_1_4955C(lbl_1_rodata_69CC, lbl_1_rodata_69CC);
    } else if (arg1 == (void *)fn_1_A8DD4) {
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

static inline f32 fn_1_E52F8_read_pointer(Sig_fn_8006F828_Fn8006F828Data * owner) { return owner->value1; }
#pragma opt_dead_assignments off
void fn_1_E52F8(Sig_fn_1_E52F8_Arg *arg0, void (*fmt)(const char *, ...))
{
    Sig_fn_8006F828_Fn8006F828Data v;
    s16 b;
    s16 a;

    lbl_8006DCA4(arg0, (void *)fmt);
    fn_1_A71AC();
    fn_8006F828(arg0->unk_54, &v);
    b = (s16)fn_1_E52F8_read_pointer(&v);
    a = (s16)v.value0;
    if (fmt == fn_1_4AE0C) {
        fn_1_496FC((f32)a, (f32)b);
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
#pragma opt_dead_assignments reset
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
        return (void *)((char *)base->unk_0 + index * 0x1a8);
    case 1:
        return (void *)((char *)base->unk_8 + index * 0x1a8);
    case 2:
        return (void *)((char *)base->unk_10 + index * 0x1a8);
    case 3:
        return (void *)((char *)base->unk_18 + index * 0x1a8);
    case 4:
        return (void *)((char *)base->unk_20 + index * 0x1a8);
    case 5:
        return (void *)((char *)base->unk_28 + index * 0x1a8);
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
extern u32 fn_80083970(const u8* left, const char* right);
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
    inv3 = ~(s32)arg3;
    value138 = arg0->unk_138;
    inv2 = ~(s32)arg2;
    arg0->unk_13C = ((value13c) & ((u32)inv3));
    arg0->unk_138 = ((value138) & ((u32)inv2));
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
        fn_80008BEC((void *)((char *)base + 0x54), NULL, 0xC);
    } else {
        fn_80008BA8((void *)((char *)base + 0x54), value, 0xC);
    }

    if (value == NULL) {
        fn_80008BEC((void *)((char *)base + 0x60), NULL, 0xC);
    } else {
        fn_80008BA8((void *)((char *)base + 0x60), value, 0xC);
    }
}
/* fzgx:end fn_1_E5988 */

/* fzgx:begin fn_1_E5A0C */
void fn_1_E5A0C(void *base, void *value) {
    if (value == NULL) {
        fn_80008BEC((void *)((char *)base + 0x2C), NULL, 0xC);
    } else {
        fn_80008BA8((void *)((char *)base + 0x2C), value, 0xC);
    }
}
/* fzgx:end fn_1_E5A0C */

/* fzgx:begin fn_1_E5A50 */
void fn_1_E5A50(void *base, void *value) {
    if (value == NULL) {
        fn_80008BEC((void *)((char *)base + 0x38), NULL, 0xC);
    } else {
        fn_80008BA8((void *)((char *)base + 0x38), value, 0xC);
    }
}
/* fzgx:end fn_1_E5A50 */

/* fzgx:begin fn_1_E5A94 */
void fn_1_E5A94(void *base, void *value) {
    if (value == NULL) {
        fn_80008BEC((void *)((char *)base + 0x6C), NULL, 0xC);
    } else {
        fn_80008BA8((void *)((char *)base + 0x6C), value, 0xC);
    }
}
/* fzgx:end fn_1_E5A94 */

/* fzgx:begin fn_1_E5AD8 */
void fn_1_E5AD8(void *base, f32 value) {
    *(f32 *)((char *)base + 0x28) = value;
}
/* fzgx:end fn_1_E5AD8 */

/* fzgx:begin fn_1_E5AE0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/phys.h"

extern u32 lbl_1_rodata_6A98[50];
extern void fn_1_57714(u8 arg);
extern f32 lbl_1_rodata_67B4[19];
extern const f64 lbl_1_rodata_6800;
typedef struct { f32 x; f32 y; f32 z; } E5AE0Vec;
extern void fn_1_5773C(E5AE0Vec *a, E5AE0Vec *b, u8 *c);
extern void fn_80008BEC(void *dst, int value, u32 size);

static inline u32 fn_1_E5AE0_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_common_subs off
void fn_1_E5AE0(s16 a, s16 b, f32 w, f32 h) {
    u32 flag = fn_1_E5AE0_array_read(lbl_1_rodata_6A98, 0);
    E5AE0Vec o1;
    E5AE0Vec o2;
    s16 i;
    f32 xpos;
    f32 zpos;
    f32 stepx;
    f32 stepz;
    f32 cur;

    fn_1_57714(6);
    stepx = w / (f32)a;
    stepz = h / (f32)b;
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
    fn_1_8D168((Sig_fn_1_8D168_Fn1_8D168State *)((u8 *)((u8 *)&lbl_1_bss_7AEB8) + 528));
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

        if (fn_80083970(entry->string, string) != 0) {
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

    converted0 = (s32)value0;
    converted1 = (s32)value1;
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

/* fzgx:begin fn_1_E9680 noprologue */
#include "types.h"
#include "rel/main_rel/phys.h"

extern void fn_80008BEC(void* dst, int value, int size);

void fn_1_E9680(void) {
    u8* base = (u8*)&lbl_1_bss_7B180;
    u32* p0;
    u32* p1;
    u32* p2;
    u32* p3;
    u32* p4;
    u32* p5;
    u32* p6;
    u32* p7;
    u32* p8;
    u32* p9;
    int i;

    fn_80008BEC(base + 0x2c, 0, 0x13d8);
    fn_80008BEC(base + 0x1404, 0, 0x1fc);

    p0 = (u32*)(base + 0x1600);
    p1 = (u32*)(base + 0x1614);
    p2 = (u32*)(base + 0x1628);
    p3 = (u32*)(base + 0x163c);
    p4 = (u32*)(base + 0x1650);
    p5 = (u32*)(base + 0x1664);
    p6 = (u32*)(base + 0x1678);
    p7 = (u32*)(base + 0x168c);
    p8 = (u32*)(base + 0x16a0);
    p9 = (u32*)(base + 0x16b4);

    for (i = 5; i != 0; i--) {
        *p0++ = 0;
        *p1++ = 0;
        *p2++ = 0;
        *p3++ = 0;
        *p4++ = 0;
        *p5++ = 0;
        *p6++ = 0;
        *p7++ = 0;
        *p8++ = 0;
        *p9++ = 0;
    }

    *(s32*)(base + 0x16c8) = -1;
    *(u8*)(base + 0x16cc) = 0xff;
    *(u32*)(base + 0x16d0) = 0;
}
/* fzgx:end fn_1_E9680 */

/* fzgx:begin fn_1_E9BA8 */
extern int fn_1_4C10(void);
extern u32 fn_1_3F8C0(void);
extern u32 fn_80008E84(u32);

typedef void (*GhostHandler)(void);

extern u8 fn_1_ECDFC__fzgx_offset_0[];
extern u8 fn_1_ECE00__fzgx_offset_0[];
extern u8 fn_1_ECE04__fzgx_offset_0[];
extern u8 fn_1_ECF68__fzgx_offset_0[];
extern u8 fn_1_ECF88__fzgx_offset_0[];
extern u8 fn_1_ED540__fzgx_offset_0[];
extern u8 fn_1_EE3F4__fzgx_offset_0[];
extern u8 fn_1_EE530__fzgx_offset_0[];
extern u8 fn_1_EEB44__fzgx_offset_0[];
extern u8 fn_1_EF0A0__fzgx_offset_0[];
extern u8 fn_1_EF0A4__fzgx_offset_0[];
extern u8 fn_1_EF0A8__fzgx_offset_0[];
extern u8 fn_1_EF484__fzgx_offset_0[];
extern u8 fn_1_EF488__fzgx_offset_0[];
extern u8 fn_1_EF4F4__fzgx_offset_0[];
extern u8 fn_1_EF4F8__fzgx_offset_0[];
extern u8 fn_1_EF5DC__fzgx_offset_0[];
extern u8 fn_1_EF5E0__fzgx_offset_0[];
extern u8 fn_1_EF764__fzgx_offset_0[];
extern u8 fn_1_EF768__fzgx_offset_0[];
extern u8 fn_1_EF85C__fzgx_offset_0[];
extern u8 fn_1_EF860__fzgx_offset_0[];
extern u8 fn_1_EF920__fzgx_offset_0[];
extern u8 fn_1_EF924__fzgx_offset_0[];
extern u8 fn_1_EF978__fzgx_offset_0[];
extern u8 fn_1_EF97C__fzgx_offset_0[];
extern u8 fn_1_EFA18__fzgx_offset_0[];
extern u8 fn_1_EFA1C__fzgx_offset_0[];
extern u8 fn_1_EFA4C__fzgx_offset_0[];
extern u8 fn_1_EFA88__fzgx_offset_0[];
extern u8 fn_1_EFA8C__fzgx_offset_0[];
extern u8 fn_1_F0164__fzgx_offset_0[];
extern u8 fn_1_F0168__fzgx_offset_0[];
extern u8 ghost_reset__fzgx_offset_0[];
extern u8 lbl_1_data_3E358__fzgx_offset_0[];
extern u8 lbl_1_data_3E364__fzgx_offset_0[];
extern u8 lbl_1_data_3E36C__fzgx_offset_0[];
extern u8 lbl_1_data_3E378__fzgx_offset_0[];
extern u8 lbl_1_data_3E380__fzgx_offset_0[];
extern u8 lbl_1_data_3E38C__fzgx_offset_0[];
extern u8 lbl_1_data_3E394__fzgx_offset_0[];
extern u8 lbl_1_data_3E39C__fzgx_offset_0[];
extern u8 lbl_1_data_3E3C0__fzgx_offset_0[];
extern u8 lbl_1_data_3E3CC__fzgx_offset_0[];
extern u8 lbl_1_data_3E3D8__fzgx_offset_0[];
extern u8 lbl_1_data_3E478__fzgx_offset_0[];
extern u8 lbl_1_data_3E48C__fzgx_offset_0[];
extern u8 lbl_1_data_3E490__fzgx_offset_0[];
extern u8 lbl_1_data_3E4BC__fzgx_offset_0[];
extern u8 lbl_1_data_3E4C8__fzgx_offset_0[];
extern u8 lbl_1_data_3E4F4__fzgx_offset_0[];
extern u8 lbl_1_data_3E504__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_1_data_3E358_gap_0[38] = {0x4F564552, 0x54414B45, 0x00000000, 0x4A554D50, 0x00000000, 0x454E454D, 0x59484954, 0x00000000, 0x57414C4C, 0x48495400, 0x53494445, 0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C, 0x00000000, 0x4C415000, (u32)lbl_1_data_3E358__fzgx_offset_0, (u32)lbl_1_data_3E364__fzgx_offset_0, (u32)lbl_1_data_3E36C__fzgx_offset_0, (u32)lbl_1_data_3E378__fzgx_offset_0, (u32)lbl_1_data_3E380__fzgx_offset_0, (u32)lbl_1_data_3E38C__fzgx_offset_0, (u32)lbl_1_data_3E394__fzgx_offset_0, (u32)lbl_1_data_3E39C__fzgx_offset_0, 0x67686F73, 0x7430302E, 0x62696E00, 0x67686F73, 0x7430312E, 0x62696E00, 0x67686F73, 0x7430322E, 0x62696E00, (u32)lbl_1_data_3E3C0__fzgx_offset_0, (u32)lbl_1_data_3E3CC__fzgx_offset_0, (u32)lbl_1_data_3E3D8__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static GhostHandler fzgx_pool_native_lbl_1_data_3E358_handlers[17] = {(GhostHandler)fn_1_ECDFC__fzgx_offset_0, (GhostHandler)fn_1_ECE04__fzgx_offset_0, (GhostHandler)fn_1_ECF88__fzgx_offset_0, (GhostHandler)fn_1_EE3F4__fzgx_offset_0, (GhostHandler)fn_1_EEB44__fzgx_offset_0, (GhostHandler)fn_1_EF5DC__fzgx_offset_0, (GhostHandler)fn_1_EF764__fzgx_offset_0, (GhostHandler)fn_1_EF85C__fzgx_offset_0, (GhostHandler)fn_1_EF920__fzgx_offset_0, (GhostHandler)fn_1_EF978__fzgx_offset_0, (GhostHandler)fn_1_EFA18__fzgx_offset_0, (GhostHandler)fn_1_EF0A4__fzgx_offset_0, (GhostHandler)fn_1_EF484__fzgx_offset_0, (GhostHandler)fn_1_EF4F4__fzgx_offset_0, (GhostHandler)fn_1_EFA88__fzgx_offset_0, (GhostHandler)fn_1_EFA4C__fzgx_offset_0, (GhostHandler)fn_1_F0164__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_3E358_gap_DC[62] = {(u32)fn_1_ECE00__fzgx_offset_0, (u32)fn_1_ECF68__fzgx_offset_0, (u32)fn_1_ED540__fzgx_offset_0, (u32)fn_1_EE530__fzgx_offset_0, (u32)fn_1_EF0A0__fzgx_offset_0, (u32)fn_1_EF5E0__fzgx_offset_0, (u32)fn_1_EF768__fzgx_offset_0, (u32)fn_1_EF860__fzgx_offset_0, (u32)fn_1_EF924__fzgx_offset_0, (u32)fn_1_EF97C__fzgx_offset_0, (u32)fn_1_EFA1C__fzgx_offset_0, (u32)fn_1_EF0A8__fzgx_offset_0, (u32)fn_1_EF488__fzgx_offset_0, (u32)fn_1_EF4F8__fzgx_offset_0, (u32)fn_1_EFA8C__fzgx_offset_0, (u32)ghost_reset__fzgx_offset_0, (u32)fn_1_F0168__fzgx_offset_0, 0x4F726967, 0x696E616C, 0x204D6163, 0x68696E65, 0x00000000, 0x00000000, 0x8349838A, 0x83578369, 0x838B837D, 0x83568393, 0x00000000, (u32)lbl_1_data_3E478__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E490__fzgx_offset_0, 0x53746166, 0x66204768, 0x6F737400, 0x8358835E, 0x83628374, 0x8353815B, 0x83588367, 0x00000000, (u32)lbl_1_data_3E4BC__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E4C8__fzgx_offset_0, 0x53454C45, 0x43542047, 0x484F5354, 0x00000000, 0x47484F53, 0x54205345, 0x4C454354, 0x00000000, (u32)lbl_1_data_3E4F4__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E48C__fzgx_offset_0, (u32)lbl_1_data_3E504__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static s32 fzgx_pool_native_lbl_1_data_3E358_current = 0xFFFFFFFF; /* fzgx-allow: A1 measured pool bytes and bindings */
static s32 fzgx_pool_native_lbl_1_data_3E358_pending[2] = {0xFFFFFFFF, 0xFFFF0000}; /* fzgx-allow: A1 measured pool bytes and bindings */

void fn_1_E9BA8(void) {
    
    s32 next;
    if ((s32)lbl_1_bss_7B188 == 0) return;
    if (fn_1_4C10() != 0) return;
    if (*(s16 *)&lbl_1_bss_960 == 9) {
        lbl_1_bss_7C85C.unk_0 = fn_80008E84(fn_1_3F8C0());
    }
    next = fzgx_pool_native_lbl_1_data_3E358_pending[0];
    if (next >= 0) {
        fzgx_pool_native_lbl_1_data_3E358_current = next;
        fzgx_pool_native_lbl_1_data_3E358_pending[0] = -1;
    }
    if (fzgx_pool_native_lbl_1_data_3E358_current >= 0) {
        fzgx_pool_native_lbl_1_data_3E358_handlers[fzgx_pool_native_lbl_1_data_3E358_current]();
    }
    if (*(s16 *)&lbl_1_bss_960 == 9) {
        fn_80008E84(lbl_1_bss_7C85C.unk_0);
    }
}
/* fzgx:end fn_1_E9BA8 */

/* fzgx:begin fn_1_E9C68 */
// Updates the active physics callback and refreshes its associated state.
void fn_1_E9C68(void) {
    u32 value;

    if ((s32)lbl_1_bss_7B188 == 0) {
        return;
    }

    if (*(s16 *)&lbl_1_bss_960 == 9) {
        value = fn_80008E84(fn_1_3F8C0());
        lbl_1_bss_7C85C.unk_0 = value;
    }

    if ((s32)lbl_1_data_3E52C >= 0) {
        ((void (**)(void))lbl_1_data_3E434)[lbl_1_data_3E52C]();
    }

    if (*(s16 *)&lbl_1_bss_960 == 9) {
        fn_80008E84(lbl_1_bss_7C85C.unk_0);
    }
}
/* fzgx:end fn_1_E9C68 */

/* fzgx:begin fn_1_EB074 */
void fn_1_EB074(u32 value) {
    lbl_1_bss_7C94C[0] = value;
}
/* fzgx:end fn_1_EB074 */

/* fzgx:begin fn_1_EB080 */
// Preserve the previous mode when switching to mode 11, then update the active mode.
void fn_1_EB080(int mode) {
    u32* state = (u32*)lbl_1_data_3E358;

    if ((int)lbl_1_bss_7B188 == 0) {
        return;
    }

    if (mode == 11) {
        state[0x1e0 / 4] = state[0x1d4 / 4];
    }

    state[0x1d8 / 4] = mode;
}
/* fzgx:end fn_1_EB080 */

/* fzgx:begin fn_1_EB0B0 */
extern u32 lbl_1_bss_7B188;
extern u8 lbl_1_bss_7C8CE;

int fn_1_EB0B0(void) {
    return (lbl_1_bss_7B188 != 0) ? lbl_1_bss_7C8CE : 0;
}
/* fzgx:end fn_1_EB0B0 */

/* fzgx:begin fn_1_EB0D8 noprologue */
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"

/* begin rel/main_rel/globals.h (deltawave784/fzgx, CC0) */
#ifndef REL_MAIN_REL_GLOBALS_H
#define REL_MAIN_REL_GLOBALS_H


// Generated by `fzgx headers --module main_rel`: layouts recovered from every access in the
// module's disassembly (matched or not). Field names are offsets until the librarian names them;
// offsets and widths are facts, names are not. Regenerate rather than hand-edit padding.

// lbl_1_bss_960: .bss size 0x2, referenced by 110 functions, shape {'object': 231}
extern s16 lbl_1_bss_960;  // typedefs.json decl override

// lbl_1_data_2A7E0: .data size 0xF8, referenced by 99 functions, shape {'object': 160}
// object reached through lbl_1_data_2A7E0.unk_3C
typedef struct {
    u32 unk_0;  // 29 loads, 17 stores
    u32 unk_4;  // 6 loads, 12 stores
    u32 unk_8;  // 6 loads, 10 stores
    u32 unk_C;  // 3 loads, 11 stores
    u32 unk_10;  // 10 loads, 9 stores
    u32 unk_14;  // 0 loads, 3 stores
    u32 unk_18;  // 0 loads, 3 stores
    u32 unk_1C;  // 0 loads, 3 stores
    u32 unk_20;  // 0 loads, 4 stores
    u32 unk_24;  // 0 loads, 4 stores
    u32 unk_28;  // 0 loads, 5 stores
    u32 unk_2C;  // 2 loads, 5 stores
    u32 unk_30;  // 2 loads, 6 stores
    u32 unk_34;  // 2 loads, 6 stores
    u8 unk_38;  // 2 loads, 6 stores
    u8 unk_39;  // 0 loads, 1 stores
    u8 unk_3A;  // 0 loads, 1 stores
    u8 unk_3B;  // 0 loads, 1 stores
    u32 unk_3C;  // 0 loads, 4 stores
    u32 unk_40;  // 0 loads, 2 stores
    u32 unk_44;  // 0 loads, 2 stores
    u32 unk_48;  // 0 loads, 2 stores
    u32 unk_4C;  // 0 loads, 3 stores
    u32 unk_50;  // 0 loads, 3 stores
    u32 unk_54;  // 0 loads, 3 stores
    u16 unk_58;  // 0 loads, 3 stores
    u16 unk_5A;  // 0 loads, 1 stores
    u8 unk_5C;  // 4 loads, 3 stores
    u8 unk_5D;  // 13 loads, 6 stores
    u8 unk_5E;  // 4 loads, 2 stores
    u8 pad_5F[0x1];
    u32 unk_60;  // 1 loads, 1 stores
    u8 pad_64[0x10];
    u32 unk_74;  // 2 loads, 5 stores
    u8 pad_78[0xC];
    u32 unk_84;  // 22 loads, 5 stores
    u32 unk_88;  // 0 loads, 4 stores
    u8 pad_8C[0x4];
    u32 unk_90;  // 10 loads, 10 stores
    u8 pad_94[0x18];
    u32 unk_AC;  // 0 loads, 1 stores
    u32 unk_B0;  // 0 loads, 1 stores
    u32 unk_B4;  // 0 loads, 1 stores
    u32 unk_B8;  // 0 loads, 1 stores
    u32 unk_BC;  // 0 loads, 1 stores
    u32 unk_C0;  // 0 loads, 1 stores
    u32 unk_C4;  // 1 loads, 2 stores
    u32 unk_C8;  // 0 loads, 1 stores
    u32 unk_CC;  // 0 loads, 1 stores
    u32 unk_D0;  // 0 loads, 1 stores
    u32 unk_D4;  // 0 loads, 1 stores
    u32 unk_D8;  // 0 loads, 1 stores
    u32 unk_DC;  // 0 loads, 1 stores
    u32 unk_E0;  // 0 loads, 1 stores
    u32 unk_E4;  // 0 loads, 1 stores
    u32 unk_E8;  // 0 loads, 1 stores
    u32 unk_EC;  // 0 loads, 1 stores
    u32 unk_F0;  // 0 loads, 1 stores
    u32 unk_F4;  // 0 loads, 1 stores
    u32 unk_F8;  // 0 loads, 1 stores
    u8 pad_FC[0x8];
    u32 unk_104;  // 0 loads, 1 stores
    u8 pad_108[0xC];
    u32 unk_114;  // 0 loads, 1 stores
    u32 unk_118;  // 0 loads, 1 stores
    u32 unk_11C;  // 0 loads, 1 stores
    u32 unk_120;  // 0 loads, 1 stores
    u32 unk_124;  // 0 loads, 1 stores
    u8 pad_128[0x24];
    u32 unk_14C;  // 0 loads, 1 stores
    u32 unk_150;  // 0 loads, 1 stores
    u32 unk_154;  // 0 loads, 1 stores
    u32 unk_158;  // 0 loads, 1 stores
    u32 unk_15C;  // 0 loads, 1 stores
    u32 unk_160;  // 0 loads, 1 stores
    u32 unk_164;  // 0 loads, 1 stores
    u32 unk_168;  // 0 loads, 1 stores
    u32 unk_16C;  // 3 loads, 2 stores
    u32 unk_170;  // 4 loads, 3 stores
    u32 unk_174;  // 0 loads, 1 stores
    u32 unk_178;  // 0 loads, 1 stores
    u32 unk_17C;  // 0 loads, 1 stores
    u32 unk_180;  // 0 loads, 1 stores
    u32 unk_184;  // 0 loads, 1 stores
    u32 unk_188;  // 0 loads, 1 stores
    u32 unk_18C;  // 0 loads, 1 stores
    u32 unk_190;  // 0 loads, 1 stores
    u32 unk_194;  // 0 loads, 1 stores
    u32 unk_198;  // 0 loads, 1 stores
    u8 pad_19C[0x50];
    u32 unk_1EC;  // 0 loads, 1 stores
    u32 unk_1F0;  // 0 loads, 1 stores
    u32 unk_1F4;  // 0 loads, 1 stores
    u32 unk_1F8;  // 0 loads, 1 stores
    u32 unk_1FC;  // 0 loads, 1 stores
    u32 unk_200;  // 0 loads, 1 stores
    u32 unk_204;  // 0 loads, 2 stores
    u32 unk_208;  // 0 loads, 1 stores
    u32 unk_20C;  // 0 loads, 1 stores
    u32 unk_210;  // 0 loads, 1 stores
    u32 unk_214;  // 0 loads, 1 stores
    u32 unk_218;  // 0 loads, 1 stores
    u32 unk_21C;  // 0 loads, 1 stores
    u32 unk_220;  // 0 loads, 1 stores
    u32 unk_224;  // 0 loads, 1 stores
    u32 unk_228;  // 0 loads, 1 stores
    u32 unk_22C;  // 0 loads, 1 stores
    u32 unk_230;  // 0 loads, 1 stores
    u32 unk_234;  // 0 loads, 1 stores
    u32 unk_238;  // 0 loads, 1 stores
    u8 pad_23C[0xC8];
    f32 unk_304;  // 1 loads, 1 stores
    u8 pad_308[0xFC];
    f32 unk_404;  // 0 loads, 1 stores
    u8 pad_408[0x1C];
    u32 unk_424;  // 0 loads, 1 stores
    u32 unk_428;  // 0 loads, 1 stores
    u32 unk_42C;  // 0 loads, 1 stores
    f32 unk_430;  // 0 loads, 1 stores
    u8 pad_434[0x28C];
    f32 unk_6C0;  // 1 loads, 1 stores
    u8 pad_6C4[0x8];
    u32 unk_6CC;  // 2 loads, 1 stores
    u32 unk_6D0;  // 0 loads, 1 stores
    u32 unk_6D4;  // 5 loads, 2 stores
    u32 unk_6D8;  // 0 loads, 1 stores
    u8 pad_6DC[0x4];
    u32 unk_6E0;  // 2 loads, 2 stores
    u8 pad_6E4[0x2BC];
    u32 unk_9A0;  // 1 loads, 2 stores
    u32 unk_9A4;  // 1 loads, 1 stores
    u32 unk_9A8;  // 1 loads, 1 stores
    u32 unk_9AC;  // 1 loads, 1 stores
    u32 unk_9B0;  // 1 loads, 1 stores
    u32 unk_9B4;  // 1 loads, 1 stores
    u32 unk_9B8;  // 1 loads, 1 stores
    u32 unk_9BC;  // 1 loads, 1 stores
    u8 pad_9C0[0x130];
    f32 unk_AF0;  // 0 loads, 1 stores
    u8 pad_AF4[0xE0];
    u32 unk_BD4;  // 2 loads, 1 stores
    u32 unk_BD8;  // 0 loads, 1 stores
    u8 pad_BDC[0x528];
    u32 unk_1104;  // 0 loads, 1 stores
    u32 unk_1108;  // 1 loads, 0 stores
    u8 pad_110C[0x4];
    u32 unk_1110;  // 0 loads, 1 stores
    u8 pad_1114[0x470];
    u32 unk_1584;  // 1 loads, 1 stores
    u32 unk_1588;  // 0 loads, 1 stores
    u8 pad_158C[0x320];
    u32 unk_18AC;  // 0 loads, 1 stores
    u8 pad_18B0[0x3A8];
    u32 unk_1C58;  // 7 loads, 2 stores
    u32 unk_1C5C;  // 7 loads, 2 stores
    u8 pad_1C60[0x5FC];
    u32 unk_225C;  // 0 loads, 1 stores
    u32 unk_2260;  // 0 loads, 1 stores
    u8 pad_2264[0x4C0];
    u32 unk_2724;  // 3 loads, 2 stores
} Obj_1_data_2A7E0_At3C;
typedef struct {
    s16 unk_0;  // 10 loads, 0 stores
    u8 unk_2;  // 0 loads, 1 stores
    u8 pad_3[0x11];
    u32 unk_14;  // 0 loads, 1 stores
    u8 pad_18[0x4];
    f32 unk_1C;  // 6 loads, 0 stores
    u8 pad_20[0xC];
    u32 unk_2C;  // 0 loads, 3 stores
    u8 pad_30[0x4];
    u32 unk_34;  // 0 loads, 1 stores
    u32 unk_38;  // 1 loads, 0 stores
    Obj_1_data_2A7E0_At3C *unk_3C;  // 75 loads, 0 stores
    u8 pad_40[0x8];
    u32 unk_48;  // 2 loads, 1 stores
    u32 unk_4C;  // 2 loads, 1 stores
    u32 unk_50;  // 3 loads, 1 stores
    u32 unk_54;  // 0 loads, 2 stores
    u32 unk_58;  // 0 loads, 1 stores
    u32 unk_5C;  // 3 loads, 1 stores
    u32 unk_60;  // 5 loads, 1 stores
    u32 unk_64;  // 0 loads, 1 stores
    u32 unk_68;  // 2 loads, 1 stores
    u32 unk_6C;  // 2 loads, 1 stores
    u8 unk_70;  // 3 loads, 2 stores
    u8 pad_71[0x3];
    u32 unk_74;  // 2 loads, 2 stores
    u32 unk_78;  // 3 loads, 0 stores
    u32 unk_7C;  // 5 loads, 1 stores
    u32 unk_80;  // 3 loads, 1 stores
    u8 pad_84[0x4];
    u32 unk_88;  // 3 loads, 0 stores
    u32 unk_8C;  // 1 loads, 0 stores
    u8 pad_90[0xC];
    f32 unk_9C;  // 2 loads, 1 stores
    u16 unk_A0;  // 2 loads, 0 stores
    u8 pad_A2[0x56];
} Obj_1_data_2A7E0;
extern Obj_1_data_2A7E0 lbl_1_data_2A7E0;

// lbl_1_bss_3C30: .bss size 0x14BC, referenced by 95 functions, shape {'object': 411}
typedef struct {
    u32 unk_0;  // 35 loads, 5 stores
    u8 unk_4;  // 3 loads, 0 stores
    u8 unk_5;  // 34 loads, 2 stores
    u8 unk_6;  // 12 loads, 0 stores
    u8 unk_7;  // 1 loads, 0 stores
    u8 unk_8;  // 47 loads, 0 stores
    u8 unk_9;  // 55 loads, 0 stores
    u8 pad_A[0x3];
    u8 unk_D;  // 1 loads, 0 stores
    u8 unk_E;  // 4 loads, 0 stores
    u8 unk_F;  // 1 loads, 0 stores
    u8 pad_10[0x1C];
    u32 unk_2C;  // 1 loads, 0 stores
    u8 pad_30[0x74];
    u16 unk_A4;  // 2 loads, 0 stores
    u8 unk_A6;  // 3 loads, 0 stores
    u8 unk_A7;  // 39 loads, 0 stores
    u8 pad_A8[0x2C];
    u32 unk_D4;  // 2 loads, 0 stores
    u16 unk_D8;  // 5 loads, 6 stores
    u16 unk_DA;  // 1 loads, 2 stores
    u8 unk_DC;  // 7 loads, 3 stores
    u8 unk_DD;  // 2 loads, 3 stores
    u8 unk_DE;  // 1 loads, 0 stores
    u8 unk_DF;  // 1 loads, 0 stores
    u8 unk_E0;  // 1 loads, 0 stores
    u8 unk_E1;  // 1 loads, 0 stores
    u8 unk_E2;  // 1 loads, 2 stores
    u8 pad_E3[0x4];
    u8 unk_E7;  // 0 loads, 2 stores
    u8 pad_E8[0x4];
    u16 unk_EC;  // 1 loads, 2 stores
    u8 pad_EE[0xA];
    u32 unk_F8;  // 2 loads, 1 stores
    u8 pad_FC[0x10];
    u32 unk_10C;  // 1 loads, 1 stores
    u8 pad_110[0x10];
    u16 unk_120;  // 3 loads, 3 stores
    u16 unk_122;  // 1 loads, 0 stores
    u16 unk_124;  // 1 loads, 0 stores
    u16 unk_126;  // 1 loads, 0 stores
    u16 unk_128;  // 1 loads, 0 stores
    u8 pad_12A[0x2];
    u32 unk_12C;  // 0 loads, 1 stores
    u8 pad_130[0x1C];
    u32 unk_14C;  // 2 loads, 3 stores
    u8 pad_150[0x4];
    u8 unk_154;  // 4 loads, 0 stores
    u8 unk_155;  // 2 loads, 0 stores
    u8 unk_156;  // 3 loads, 0 stores
    u8 unk_157;  // 1 loads, 3 stores
    u8 pad_158[0x1A];
    u16 unk_172;  // 1 loads, 2 stores
    u8 pad_174[0x4];
    u16 unk_178;  // 0 loads, 1 stores
    u8 pad_17A[0x1];
    u8 unk_17B;  // 7 loads, 0 stores
    u8 unk_17C;  // 0 loads, 1 stores
    u8 pad_17D[0x7A];
    u8 unk_1F7;  // 0 loads, 1 stores
    u8 pad_1F8[0x20];
    u16 unk_218;  // 0 loads, 1 stores
    u8 pad_21A[0x2];
    u8 unk_21C;  // 0 loads, 1 stores
    u8 pad_21D[0x7A];
    u8 unk_297;  // 0 loads, 1 stores
    u8 pad_298[0x20];
    u16 unk_2B8;  // 0 loads, 1 stores
    u8 pad_2BA[0x2];
    u8 unk_2BC;  // 0 loads, 1 stores
    u8 pad_2BD[0x7A];
    u8 unk_337;  // 0 loads, 1 stores
    u8 pad_338[0x20];
    u16 unk_358;  // 0 loads, 1 stores
    u8 pad_35A[0x2];
    u8 unk_35C;  // 0 loads, 1 stores
    u8 pad_35D[0x7A];
    u8 unk_3D7;  // 0 loads, 1 stores
    u8 pad_3D8[0x20];
    u16 unk_3F8;  // 0 loads, 1 stores
    u8 pad_3FA[0x2];
    u8 unk_3FC;  // 0 loads, 1 stores
    u8 pad_3FD[0x7A];
    u8 unk_477;  // 0 loads, 1 stores
    u8 pad_478[0xF1C];
    u8 unk_1394;  // 1 loads, 0 stores
    u8 pad_1395[0x1F];
    u32 unk_13B4;  // 2 loads, 1 stores
    u8 pad_13B8[0x1C];
    u32 unk_13D4;  // 1 loads, 1 stores
    u8 pad_13D8[0x1C];
    u8 unk_13F4;  // 4 loads, 1 stores
    u8 unk_13F5;  // 3 loads, 1 stores
    u8 unk_13F6;  // 2 loads, 0 stores
    u8 pad_13F7[0x1];
    u16 unk_13F8;  // 0 loads, 1 stores
    u16 unk_13FA;  // 0 loads, 1 stores
    u16 unk_13FC;  // 0 loads, 1 stores
    u16 unk_13FE;  // 0 loads, 1 stores
    u16 unk_1400;  // 0 loads, 1 stores
    u8 unk_1402;  // 0 loads, 1 stores
    u8 pad_1403[0x2];
    u8 unk_1405;  // 2 loads, 0 stores
    u8 pad_1406[0x5E];
    u32 unk_1464;  // 5 loads, 1 stores
    u8 pad_1468[0x4];
    u8 unk_146C;  // 1 loads, 1 stores
    u8 unk_146D;  // 1 loads, 1 stores
    u16 unk_146E;  // 1 loads, 1 stores
    u8 unk_1470;  // 1 loads, 1 stores
    u8 pad_1471[0x3];
    u32 unk_1474;  // 3 loads, 1 stores
    u16 unk_1478;  // 2 loads, 1 stores
    u16 unk_147A;  // 0 loads, 1 stores
    u16 unk_147C;  // 0 loads, 1 stores
    u16 unk_147E;  // 0 loads, 1 stores
    u32 unk_1480;  // 3 loads, 1 stores
    u32 unk_1484;  // 0 loads, 1 stores
    u32 unk_1488;  // 0 loads, 1 stores
    u32 unk_148C;  // 0 loads, 1 stores
    u32 unk_1490;  // 0 loads, 1 stores
    u32 unk_1494;  // 0 loads, 1 stores
    u32 unk_1498;  // 0 loads, 1 stores
    u32 unk_149C;  // 0 loads, 1 stores
    u32 unk_14A0;  // 0 loads, 1 stores
    u32 unk_14A4;  // 0 loads, 1 stores
    u32 unk_14A8;  // 1 loads, 1 stores
    u8 pad_14AC[0x10];
} Obj_1_bss_3C30;
extern Obj_1_bss_3C30 lbl_1_bss_3C30;

// lbl_1_bss_8B3A0: .bss size 0x14C, referenced by 87 functions, shape {'object': 253}
// object reached through lbl_1_bss_8B3A0.unk_A4
typedef struct {
    u8 pad_0[0x19];
    u8 unk_19;  // 1 loads, 0 stores
} Obj_1_bss_8B3A0_AtA4;
typedef struct {
    s16 unk_0;  // 12 loads, 2 stores
    u8 pad_2[0x2];
    s16 unk_4;  // 13 loads, 0 stores
    u8 pad_6[0x2];
    s16 unk_8;  // 7 loads, 2 stores
    u8 pad_A[0x4];
    s16 unk_E;  // 24 loads, 0 stores
    u8 pad_10[0x4];
    u8 unk_14;  // 7 loads, 2 stores
    u8 pad_15[0x19];
    s16 unk_2E;  // 1 loads, 0 stores
    u8 pad_30[0x5C];
    s16 unk_8C;  // 2 loads, 0 stores
    u8 pad_8E[0x2];
    s16 unk_90;  // 15 loads, 0 stores
    s16 unk_92;  // 1 loads, 0 stores
    u32 unk_94;  // 60 loads, 3 stores
    u8 pad_98[0x6];
    u8 unk_9E;  // 7 loads, 0 stores
    u8 unk_9F;  // 8 loads, 3 stores
    u8 pad_A0[0x4];
    Obj_1_bss_8B3A0_AtA4 *unk_A4;  // 4 loads, 0 stores
    u8 pad_A8[0x8];
    s16 unk_B0;  // 1 loads, 1 stores
    s16 unk_B2;  // 1 loads, 1 stores
    u8 pad_B4[0xC];
    s16 unk_C0;  // 2 loads, 4 stores
    s16 unk_C2;  // 2 loads, 4 stores
    u8 pad_C4[0xC];
    s16 unk_D0;  // 1 loads, 2 stores
    s16 unk_D2;  // 1 loads, 2 stores
    u8 pad_D4[0xC];
    u32 unk_E0;  // 0 loads, 2 stores
    u32 unk_E4;  // 0 loads, 1 stores
    u32 unk_E8;  // 0 loads, 1 stores
    u32 unk_EC;  // 0 loads, 1 stores
    u32 unk_F0;  // 2 loads, 2 stores
    u32 unk_F4;  // 0 loads, 1 stores
    u32 unk_F8;  // 0 loads, 1 stores
    u32 unk_FC;  // 0 loads, 1 stores
    u32 unk_100;  // 2 loads, 2 stores
    u32 unk_104;  // 0 loads, 1 stores
    u32 unk_108;  // 0 loads, 1 stores
    u32 unk_10C;  // 0 loads, 1 stores
    u32 unk_110;  // 2 loads, 2 stores
    u32 unk_114;  // 0 loads, 1 stores
    u32 unk_118;  // 0 loads, 1 stores
    u32 unk_11C;  // 0 loads, 1 stores
    u32 unk_120;  // 0 loads, 2 stores
    u32 unk_124;  // 1 loads, 2 stores
    u8 unk_128;  // 0 loads, 1 stores
    u8 unk_129;  // 1 loads, 2 stores
    u8 pad_12A[0x2];
    s16 unk_12C;  // 4 loads, 0 stores
    s16 unk_12E;  // 1 loads, 0 stores
    s16 unk_130;  // 1 loads, 0 stores
    s16 unk_132;  // 1 loads, 0 stores
    s16 unk_134;  // 1 loads, 0 stores
    s16 unk_136;  // 1 loads, 0 stores
    s16 unk_138;  // 1 loads, 0 stores
    s16 unk_13A;  // 1 loads, 0 stores
    s16 unk_13C;  // 1 loads, 0 stores
    u8 pad_13E[0x2];
    u32 unk_140;  // 3 loads, 0 stores
    u8 pad_144[0x2];
    s16 unk_146;  // 4 loads, 0 stores
    s16 unk_148;  // 2 loads, 0 stores
    u8 pad_14A[0x2];
} Obj_1_bss_8B3A0;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;

// lbl_1_bss_3BE0: .bss size 0x4, referenced by 77 functions, shape {'object': 259, 'pointer': 61}
typedef struct {
    u32 unk_0;  // 7 loads, 0 stores
    f32 unk_4;  // 1 loads, 0 stores
    u32 unk_8;  // 28 loads, 0 stores
    u32 unk_C;  // 40 loads, 0 stores
    u8 pad_10[0x4];
    u32 unk_14;  // 2 loads, 1 stores
    u32 unk_18;  // 9 loads, 0 stores
    u32 unk_1C;  // 11 loads, 1 stores
    u8 pad_20[0x4];
    u32 unk_24;  // 2 loads, 1 stores
    u8 pad_28[0x4];
    u32 unk_2C;  // 1 loads, 1 stores
    u8 pad_30[0xC];
    u32 unk_3C;  // 1 loads, 1 stores
    u8 pad_40[0x4];
    u32 unk_44;  // 1 loads, 1 stores
    u32 unk_48;  // 22 loads, 0 stores
    u32 unk_4C;  // 1 loads, 0 stores
    u32 unk_50;  // 1 loads, 0 stores
    u32 unk_54;  // 40 loads, 1 stores
    u8 pad_58[0x4];
    u32 unk_5C;  // 1 loads, 0 stores
    u32 unk_60;  // 1 loads, 1 stores
    u32 unk_64;  // 3 loads, 0 stores
    u32 unk_68;  // 6 loads, 1 stores
    u32 unk_6C;  // 1 loads, 0 stores
    u32 unk_70;  // 2 loads, 1 stores
    u32 unk_74;  // 1 loads, 0 stores
    u32 unk_78;  // 1 loads, 1 stores
    u8 pad_7C[0x1];
    u8 unk_7D;  // 11 loads, 0 stores
    u8 pad_7E[0x2];
    u32 unk_80;  // 5 loads, 1 stores
    u32 unk_84;  // 2 loads, 1 stores
    u32 unk_88;  // 1 loads, 0 stores
    u32 unk_8C;  // 1 loads, 1 stores
    u32 unk_90;  // 10 loads, 1 stores
    u32 unk_94;  // 1 loads, 0 stores
    u32 unk_98;  // 2 loads, 1 stores
    u32 unk_9C;  // 1 loads, 0 stores
    u32 unk_A0;  // 2 loads, 1 stores
    u32 unk_A4;  // 7 loads, 0 stores
    u32 unk_A8;  // 7 loads, 1 stores
    u32 unk_AC;  // 1 loads, 0 stores
    u32 unk_B0;  // 2 loads, 1 stores
    u32 unk_B4;  // 6 loads, 0 stores
    u32 unk_B8;  // 4 loads, 1 stores
    u32 unk_BC;  // 5 loads, 1 stores
    f32 unk_C0;  // 1 loads, 0 stores
    f32 unk_C4;  // 1 loads, 0 stores
    f32 unk_C8;  // 1 loads, 0 stores
    f32 unk_CC;  // 1 loads, 0 stores
    u32 unk_D0;  // 3 loads, 0 stores
    u32 unk_D4;  // 2 loads, 0 stores
} Obj_1_bss_3BE0_Target;
extern Obj_1_bss_3BE0_Target *lbl_1_bss_3BE0;

// lbl_1_bss_9F8: .bss size 0x50, referenced by 67 functions, shape {'object': 304}
typedef struct {
    u16 unk_0;  // 25 loads, 0 stores
    u16 unk_2;  // 35 loads, 0 stores
    u8 pad_4[0x4];
    u16 unk_8;  // 108 loads, 0 stores
    u16 unk_A;  // 22 loads, 0 stores
    u8 pad_C[0x4];
    u16 unk_10;  // 56 loads, 0 stores
    u16 unk_12;  // 53 loads, 0 stores
    u8 pad_14[0x3C];
} Obj_1_bss_9F8;
extern Obj_1_bss_9F8 lbl_1_bss_9F8;

// lbl_1_bss_7F0C0: .bss size 0x5360, referenced by 66 functions, shape {'object': 191}
typedef struct {
    u32 unk_0;  // 4 loads, 1 stores
    u32 unk_4;  // 4 loads, 1 stores
    u32 unk_8;  // 2 loads, 1 stores
    u32 unk_C;  // 2 loads, 1 stores
    u32 unk_10;  // 2 loads, 1 stores
    u32 unk_14;  // 2 loads, 1 stores
    u32 unk_18;  // 3 loads, 1 stores
    u32 unk_1C;  // 3 loads, 1 stores
    u32 unk_20;  // 3 loads, 1 stores
    u32 unk_24;  // 3 loads, 1 stores
    u32 unk_28;  // 3 loads, 1 stores
    u32 unk_2C;  // 3 loads, 1 stores
    u8 pad_30[0x18];
    u32 unk_48;  // 3 loads, 3 stores
    u32 unk_4C;  // 3 loads, 3 stores
    u32 unk_50;  // 3 loads, 3 stores
    u32 unk_54;  // 3 loads, 3 stores
    u32 unk_58;  // 3 loads, 3 stores
    u32 unk_5C;  // 3 loads, 3 stores
    u8 pad_60[0x4];
    u16 unk_64;  // 2 loads, 2 stores
    u16 unk_66;  // 2 loads, 2 stores
    u16 unk_68;  // 2 loads, 2 stores
    u16 unk_6A;  // 3 loads, 3 stores
    u8 pad_6C[0x8C];
    u32 unk_F8;  // 4 loads, 2 stores
    u32 unk_FC;  // 2 loads, 0 stores
    u32 unk_100;  // 12 loads, 12 stores
    u32 unk_104;  // 5 loads, 2 stores
    u32 unk_108;  // 2 loads, 0 stores
    u32 unk_10C;  // 2 loads, 0 stores
    u32 unk_110;  // 12 loads, 9 stores
    u32 unk_114;  // 6 loads, 3 stores
    u8 pad_118[0x120];
    u32 unk_238;  // 2 loads, 0 stores
    u32 unk_23C;  // 2 loads, 0 stores
    u32 unk_240;  // 2 loads, 0 stores
    u32 unk_244;  // 2 loads, 0 stores
    u32 unk_248;  // 2 loads, 0 stores
    u32 unk_24C;  // 2 loads, 0 stores
    u32 unk_250;  // 2 loads, 0 stores
    u32 unk_254;  // 2 loads, 0 stores
    u16 unk_258;  // 2 loads, 0 stores
    u8 pad_25A[0x5106];
} Obj_1_bss_7F0C0;
extern Obj_1_bss_7F0C0 lbl_1_bss_7F0C0;

// lbl_1_bss_6D838: .bss size 0x4, referenced by 66 functions, shape {'object': 72, 'pointer': 33}
typedef struct {
    u32 unk_0;  // 1 loads, 0 stores
    s16 unk_4;  // 2 loads, 0 stores
    s16 unk_6;  // 1 loads, 0 stores
    u8 pad_8[0x2C];
    f32 unk_34;  // 1 loads, 0 stores
    f32 unk_38;  // 1 loads, 0 stores
    u8 pad_3C[0x40];
    u32 unk_7C;  // 1 loads, 0 stores
    u32 unk_80;  // 1 loads, 0 stores
    u32 unk_84;  // 1 loads, 0 stores
    u32 unk_88;  // 1 loads, 0 stores
    u32 unk_8C;  // 1 loads, 0 stores
    u32 unk_90;  // 1 loads, 0 stores
    u8 pad_94[0xE8];
    f32 unk_17C;  // 1 loads, 0 stores
    u8 pad_180[0x4];
    f32 unk_184;  // 1 loads, 0 stores
    s16 unk_188;  // 1 loads, 0 stores
    u8 pad_18A[0x32];
    u32 unk_1BC;  // 1 loads, 0 stores
    u32 unk_1C0;  // 1 loads, 0 stores
    u32 unk_1C4;  // 1 loads, 0 stores
    u8 pad_1C8[0x2C];
    f32 unk_1F4;  // 1 loads, 0 stores
    f32 unk_1F8;  // 1 loads, 0 stores
    f32 unk_1FC;  // 1 loads, 0 stores
    f32 unk_200;  // 1 loads, 0 stores
    f32 unk_204;  // 1 loads, 0 stores
    u8 pad_208[0xC];
    u16 unk_214;  // 1 loads, 0 stores
    u8 pad_216[0x2];
    u32 unk_218;  // 1 loads, 0 stores
    u8 pad_21C[0x8];
    f32 unk_224;  // 1 loads, 0 stores
    u8 pad_228[0x24C];
    u8 unk_474;  // 3 loads, 0 stores
    u8 unk_475;  // 1 loads, 0 stores
    u8 pad_476[0xE];
    u32 unk_484;  // 2 loads, 0 stores
    u8 pad_488[0x14];
    u32 unk_49C;  // 5 loads, 0 stores
    u32 unk_4A0;  // 1 loads, 0 stores
    u32 unk_4A4;  // 1 loads, 0 stores
    u32 unk_4A8;  // 1 loads, 0 stores
    u8 pad_4AC[0xE0];
    u32 unk_58C;  // 1 loads, 0 stores
    u8 pad_590[0x90];
} Obj_1_bss_6D838_Target;
extern Obj_1_bss_6D838_Target *lbl_1_bss_6D838;  // array of 0x620-byte records

// lbl_1_bss_3C00: .bss size 0x4, referenced by 58 functions, shape {'object': 2442}
// the stcoli/game .bss run from 0x3C00 as one view: retail addresses every object of the TU off this base (dtk sizes it 4; the objects at 3C04..38200 are separate symbols). Offsets from base-relative loads/stores in retail.
typedef struct {
    u8 unk_0;
    u8 pad_1[0x3];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 unk_10;
    u8 pad_11[0x1];
    u8 unk_12;
    u8 pad_13[0x1];
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 unk_20;
    u8 pad_21[0x3];
    u32 unk_24;
    u8 pad_28[0x2];
    s16 unk_2A;
    u8 pad_2C[0x4];
    u32 unk_30;
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E;
    u8 pad_3F[0x1D];
    u32 unk_5C;
    u8 pad_60[0x70];
    u8 arr_D0[0x4];
    u16 unk_D4;
    u8 unk_D6;
    u8 unk_D7;
    u32 unk_D8;
    u32 unk_DC;
    u32 unk_E0;
    u32 unk_E4;
    u32 unk_E8;
    u32 unk_EC;
    u32 unk_F0;
    u32 unk_F4;
    u32 unk_F8;
    u32 unk_FC;
    u32 unk_100;
    u8 arr_104[0x8];
    u8 unk_10C;
    u8 pad_10D[0x73];
    u8 unk_180;
    u8 unk_181;
    u8 unk_182;
    u8 pad_183[0x1];
    u8 unk_184;
    u8 unk_185;
    u8 unk_186;
    u8 unk_187;
    u8 pad_188[0x125C];
    u32 unk_13E4;
    u32 unk_13E8;
    u32 unk_13EC;
    u8 pad_13F0[0x14];
    u32 unk_1404;
    u32 unk_1408;
    u32 unk_140C;
    u8 pad_1410[0x14];
    u8 unk_1424;
    u8 unk_1425;
    u8 unk_1426;
    u8 pad_1427[0x1];
    u16 unk_1428;
    u16 unk_142A;
    u16 unk_142C;
    u16 unk_142E;
    u16 unk_1430;
    u8 unk_1432;
    u8 unk_1433;
    u8 unk_1434;
    u8 unk_1435;
    u8 pad_1436[0x3E];
    u32 unk_1474;
    u32 unk_1478;
    u8 pad_147C[0x10];
    u16 unk_148C;
    u8 unk_148E;
    u8 unk_148F;
    u8 unk_1490;
    u8 unk_1491;
    u8 unk_1492;
    u8 unk_1493;
    u32 unk_1494;
    u8 unk_1498;
    u8 unk_1499;
    u8 unk_149A;
    u8 unk_149B;
    u8 unk_149C;
    u8 unk_149D;
    u16 unk_149E;
    u8 unk_14A0;
    u8 unk_14A1;
    u8 unk_14A2;
    u8 unk_14A3;
    u32 unk_14A4;
    u8 pad_14A8[0x18];
    u32 unk_14C0;
    u32 unk_14C4;
    u32 unk_14C8;
    u32 unk_14CC;
    u32 unk_14D0;
    u32 unk_14D4;
    u32 unk_14D8;
    u8 pad_14DC[0xC];
    u16 unk_14E8;
    u8 pad_14EA[0x2];
    u16 unk_14EC;
    u16 unk_14EE;
    u16 unk_14F0;
    u16 unk_14F2;
    u8 unk_14F4;
    u8 pad_14F5[0x3];
    u32 unk_14F8;
    u16 unk_14FC;
    u8 pad_14FE[0x2];
    u32 unk_1500;
    u8 unk_1504;
    u8 pad_1505[0x3];
    u8 unk_1508;
    u8 unk_1509;
    u8 pad_150A[0x1];
    u8 unk_150B;
    u32 unk_150C;
    u8 pad_1510[0x28];
    u16 unk_1538;
    u8 unk_153A;
    u8 unk_153B;
    u8 pad_153C[0xC];
    u16 unk_1548;
    u16 unk_154A;
    u8 pad_154C[0x8];
    f32 unk_1554;
    u8 unk_1558;
    u8 pad_1559[0xBF];
    u8 unk_1618;
    u8 unk_1619;
    u8 unk_161A;
    u8 unk_161B;
    u8 unk_161C;
    u8 unk_161D;
    u8 pad_161E[0x5];
    u8 unk_1623;
    u8 unk_1624;
    u8 pad_1625[0x3];
    u32 unk_1628;
    u32 unk_162C;
    char *unk_1630;
    u8 unk_1634;
    u8 pad_1635[0x3];
    u32 unk_1638;
    u8 unk_163C;
    u8 unk_163D;
    u8 unk_163E;
    u8 unk_163F;
    u8 unk_1640;
    u8 unk_1641;
    u8 unk_1642;
    u8 unk_1643;
    u8 unk_1644;
    u8 unk_1645;
    u8 arr_1646[0x16];
    u8 arr_165C[0xF0];
    u8 arr_174C[0xA0];
    u8 unk_17EC;
    u8 unk_17ED;
    u8 unk_17EE;
    u8 pad_17EF[0x5];
    u16 unk_17F4;
    u8 pad_17F6[0x2];
    u32 unk_17F8;
    u32 unk_17FC;
    u32 unk_1800;
    u32 unk_1804;
    u32 unk_1808;
    u32 unk_180C;
    u8 arr_1810[0x20770];
    u16 unk_21F80;
    u8 pad_21F82[0x2];
    u32 unk_21F84;
    u32 unk_21F88;
    u32 unk_21F8C;
    u32 unk_21F90;
    u32 unk_21F94;
    u16 unk_21F98;
    u8 pad_21F9A[0x2];
    u32 unk_21F9C;
    u32 unk_21FA0;
    u32 unk_21FA4;
    u8 unk_21FA8;
    u8 arr_21FA9[0x1F];
    u8 unk_21FC8;
    u8 unk_21FC9;
    u8 unk_21FCA;
    u8 unk_21FCB;
    u8 unk_21FCC;
    u8 unk_21FCD;
    u8 unk_21FCE;
    u8 unk_21FCF;
    u8 arr_21FD0[0x16];
    u16 unk_21FE6;
    u16 unk_21FE8;
    u8 unk_21FEA;
    u8 pad_21FEB[0x1];
    u32 unk_21FEC;
    u32 unk_21FF0;
    u32 unk_21FF4;
    f32 unk_21FF8;
    f32 unk_21FFC;
    u32 unk_22000;
    u32 unk_22004;
    u32 unk_22008;
    u32 unk_2200C;
    u32 unk_22010;
    u32 unk_22014;
    u32 unk_22018;
    u32 unk_2201C;
    u32 unk_22020;
    u32 unk_22024;
    u32 unk_22028;
    u32 unk_2202C;
    f32 unk_22030;
    f32 unk_22034;
    u32 unk_22038;
    u32 unk_2203C;
    u32 unk_22040;
    u32 unk_22044;
    u16 unk_22048;
    u8 arr_2204A[0x3A];
    u8 arr_22084[0x20];
    u32 unk_220A4;
    u32 unk_220A8;
    u32 unk_220AC;
    u32 unk_220B0;
    u32 unk_220B4;
    u32 unk_220B8;
    u32 unk_220BC;
    u32 unk_220C0;
    u32 unk_220C4;
    u32 unk_220C8;
    u32 unk_220CC;
    u32 unk_220D0;
    u8 arr_220D4[0x163];
    u8 unk_22237;
    u8 pad_22238[0x1C];
    u32 unk_22254;
    u32 unk_22258;
    u32 unk_2225C;
    u32 unk_22260;
    u32 unk_22264;
    u32 unk_22268;
    u32 unk_2226C;
    u32 unk_22270;
    u32 unk_22274;
    u32 unk_22278;
    u32 unk_2227C;
    u32 unk_22280;
    u32 unk_22284;
    u32 unk_22288;
    u32 unk_2228C;
    u8 unk_22290;
    u8 pad_22291[0x3];
    u32 unk_22294;
    u8 unk_22298;
    u8 arr_22299[0x3];
    u16 unk_2229C;
    u8 pad_2229E[0x2];
    u32 unk_222A0;
    u8 unk_222A4;
    u8 pad_222A5[0x3];
    u32 unk_222A8;
    u8 pad_222AC[0x10];
    u8 arr_222BC[0x3A0];
    u8 unk_2265C;
    u8 unk_2265D;
    u8 unk_2265E;
    u8 unk_2265F;
    u8 unk_22660;
    u8 unk_22661;
    u8 arr_22662[0x1A];
    u32 unk_2267C;
    u32 unk_22680;
    u32 unk_22684;
    u32 unk_22688;
    u32 unk_2268C;
    u32 unk_22690;
    u8 arr_22694[0x60];
    u8 unk_226F4;
    u8 pad_226F5[0x3];
    u32 unk_226F8;
    u8 arr_226FC[0x4];
    u16 unk_22700;
    u8 pad_22702[0x2];
    f32 unk_22704;
    f32 unk_22708;
    f32 unk_2270C;
    f32 unk_22710;
    u8 arr_22714[0x7F0];
    u8 arr_22F04[0x4];
    u32 unk_22F08;
    u32 unk_22F0C;
    u32 unk_22F10;
    u32 unk_22F14;
    u8 unk_22F18;
    u8 unk_22F19;
    u8 unk_22F1A;
    u8 unk_22F1B;
    u8 unk_22F1C;
    u8 unk_22F1D;
    u8 unk_22F1E;
    u8 pad_22F1F[0x1];
    u8 unk_22F20;
    u8 unk_22F21;
    u8 unk_22F22;
    u8 unk_22F23;
    u8 unk_22F24;
    u8 unk_22F25;
    u8 unk_22F26;
    u8 unk_22F27;
    u8 arr_22F28[0x18];
    f32 unk_22F40;
    f32 unk_22F44;
    u32 unk_22F48;
    u32 unk_22F4C;
    u32 unk_22F50;
    u8 unk_22F54;
    u8 pad_22F55[0x3];
    u32 unk_22F58;
    u8 arr_22F5C[0x1E];
    u16 unk_22F7A;
    u8 unk_22F7C;
    u8 pad_22F7D[0x3];
    u8 arr_22F80[0x96];
    u8 unk_23016;
    u8 pad_23017[0x1];
    u32 unk_23018;
    u32 unk_2301C;
    u32 unk_23020;
    u8 unk_23024;
    u8 pad_23025[0x3];
    u32 unk_23028;
    u32 unk_2302C;
    u32 unk_23030;
    u32 unk_23034;
    u32 unk_23038;
    u32 unk_2303C;
    u32 unk_23040;
    u32 unk_23044;
    f32 unk_23048;
    f32 unk_2304C;
    f32 unk_23050;
    f32 unk_23054;
    u8 unk_23058;
    u8 pad_23059[0x3];
    u32 unk_2305C;
    u32 unk_23060;
    u32 unk_23064;
    u16 unk_23068;
    u8 unk_2306A;
    u8 pad_2306B[0x1];
    u8 arr_2306C[0x4];
    u8 arr_23070[0x4];
    u32 unk_23074;
    u32 unk_23078;
    u32 unk_2307C;
    u32 unk_23080;
    u16 unk_23084;
    u16 unk_23086;
    u32 unk_23088;
    u32 unk_2308C;
    u32 unk_23090;
    u32 unk_23094;
    u32 unk_23098;
    u32 unk_2309C;
    u32 unk_230A0;
    u32 unk_230A4;
    u8 pad_230A8[0x28];
    u32 unk_230D0;
    u8 pad_230D4[0x4];
    u8 arr_230D8[0x70];
    u8 arr_23148[0x1380];
    u8 arr_244C8[0x2718];
    u8 arr_26BE0[0x324];
    u32 unk_26F04;
    u8 unk_26F08;
    u8 pad_26F09[0x43B];
    u32 unk_27344;
    u8 unk_27348;
    u8 pad_27349[0x43B];
    u32 unk_27784;
    u8 unk_27788;
    u8 pad_27789[0x43B];
    u32 unk_27BC4;
    u8 unk_27BC8;
    u8 pad_27BC9[0x43B];
    u32 unk_28004;
    u8 unk_28008;
    u8 pad_28009[0x43B];
    u32 unk_28444;
    u8 unk_28448;
    u8 pad_28449[0x43B];
    u32 unk_28884;
    u8 unk_28888;
    u8 pad_28889[0x43B];
    u32 unk_28CC4;
    u8 unk_28CC8;
    u8 pad_28CC9[0x117];
    u8 arr_28DE0[0x8C40];
    u8 arr_31A20[0xA20];
    u8 arr_32440[0x1E60];
    u8 arr_342A0[0x190];
    u8 arr_34430[0x190];
    u8 arr_345C0[0x10];
    u8 arr_345D0[0x20];
    u8 arr_345F0[0x4];
    u8 unk_345F4;
    u8 pad_345F5[0xB];
    u8 unk_34600;
} Obj_1_bss_3C00;
extern Obj_1_bss_3C00 lbl_1_bss_3C00;  // typedefs.json decl override

// lbl_1_bss_38458: .bss size 0x4, referenced by 43 functions, shape {'object': 62, 'pointer': 9}
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;  // 58 loads, 0 stores
} Obj_1_bss_38458_Target;
extern Obj_1_bss_38458_Target *lbl_1_bss_38458;

// lbl_1_bss_F68: .bss size 0x4, referenced by 42 functions, shape {'object': 140, 'pointer': 7}
typedef struct {
    u32 unk_0;  // 10 loads, 1 stores
    u16 unk_4;  // 0 loads, 2 stores
    u8 pad_6[0x1C];
    s16 unk_22;  // 4 loads, 4 stores
    u16 unk_24;  // 0 loads, 1 stores
    u8 pad_26[0x1E];
    s16 unk_44;  // 1 loads, 1 stores
    u16 unk_46;  // 0 loads, 1 stores
    u8 unk_48;  // 30 loads, 13 stores
    u8 unk_49;  // 2 loads, 1 stores
    u8 unk_4A;  // 2 loads, 1 stores
    u8 unk_4B;  // 2 loads, 2 stores
    u8 unk_4C;  // 2 loads, 2 stores
    u8 unk_4D;  // 1 loads, 1 stores
    u8 pad_4E[0x2];
    u32 unk_50;  // 5 loads, 1 stores
    u32 unk_54;  // 2 loads, 1 stores
    f32 unk_58;  // 0 loads, 3 stores
    f32 unk_5C;  // 1 loads, 3 stores
} Obj_1_bss_F68_Target;
extern Obj_1_bss_F68_Target *lbl_1_bss_F68;

// lbl_1_data_1D628: .data size 0x4, referenced by 41 functions, shape {'object': 189}
extern u32 lbl_1_data_1D628;

// lbl_1_bss_4B9CC: .bss size 0x5C, referenced by 38 functions, shape {'object': 237}
typedef struct {
    f32 unk_0;  // 2 loads, 10 stores
    f32 unk_4;  // 3 loads, 8 stores
    f32 unk_8;  // 2 loads, 7 stores
    s16 unk_C;  // 9 loads, 7 stores
    s16 unk_E;  // 2 loads, 3 stores
    u32 unk_10;  // 2 loads, 9 stores
    u32 unk_14;  // 0 loads, 6 stores
    f32 unk_18;  // 2 loads, 3 stores
    f32 unk_1C;  // 7 loads, 15 stores
    f32 unk_20;  // 3 loads, 11 stores
    f32 unk_24;  // 0 loads, 3 stores
    f32 unk_28;  // 2 loads, 3 stores
    u32 unk_2C;  // 11 loads, 11 stores
    u16 unk_30;  // 0 loads, 2 stores
    u16 unk_32;  // 0 loads, 3 stores
    u16 unk_34;  // 0 loads, 3 stores
    u8 unk_36;  // 0 loads, 3 stores
    u8 unk_37;  // 0 loads, 4 stores
    f32 unk_38;  // 0 loads, 3 stores
    f32 unk_3C;  // 6 loads, 3 stores
    f32 unk_40;  // 1 loads, 3 stores
    u8 unk_44;  // 3 loads, 3 stores
    u8 unk_45;  // 3 loads, 3 stores
    u8 unk_46;  // 6 loads, 3 stores
    u8 unk_47;  // 3 loads, 3 stores
    s16 unk_48;  // 3 loads, 3 stores
    s16 unk_4A;  // 3 loads, 3 stores
    s16 unk_4C;  // 3 loads, 3 stores
    s16 unk_4E;  // 3 loads, 3 stores
    f32 unk_50;  // 0 loads, 3 stores
    u32 unk_54;  // 2 loads, 3 stores
    u32 unk_58;  // 3 loads, 3 stores
} Obj_1_bss_4B9CC;
extern Obj_1_bss_4B9CC lbl_1_bss_4B9CC;

// lbl_1_bss_6EA98: .bss size 0x4, referenced by 33 functions, shape {'object': 584}
extern u32 lbl_1_bss_6EA98;

// lbl_1_bss_716C0: .bss size 0x8, referenced by 32 functions, shape {'object': 780}
extern u8 lbl_1_bss_716C0;

// lbl_1_data_3FFBC: .data size 0x574, referenced by 31 functions, shape {}
extern u8 lbl_1_data_3FFBC[0x574];

// lbl_1_bss_7B180: .bss size 0x8, referenced by 29 functions, shape {'object': 873}
// the ghost .bss run from 0x7B180 as one view: retail addresses the TU's objects off this base (dtk sizes it 8; the objects at 7B188..7ED5C are separate symbols). Offsets from base-relative loads/stores in retail; mixed-width offsets are byte arrays.
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
    u8 pad_28[0x4];
    u8 arr_2C[0x1];
    u8 unk_2D;
    u8 unk_2E;
    u8 unk_2F;
    u8 arr_30[0x1];
    u8 unk_31;
    u8 unk_32;
    u8 unk_33;
    u8 arr_34[0x1];
    u8 unk_35;
    u8 unk_36;
    u8 pad_37[0x1];
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u8 arr_44[0x4];
    u32 unk_48;
    u32 unk_4C;
    u8 arr_50[0x1];
    u8 unk_51;
    u16 unk_52;
    u8 arr_54[0x13B0];
    u32 unk_1404;
    u8 arr_1408[0x1F8];
    u32 unk_1600;
    u8 arr_1604[0x10];
    u32 unk_1614;
    u8 arr_1618[0x10];
    u32 unk_1628;
    u8 arr_162C[0x10];
    u32 unk_163C;
    u8 arr_1640[0x10];
    u32 unk_1650;
    u8 arr_1654[0x10];
    u32 unk_1664;
    u8 arr_1668[0x10];
    u32 unk_1678;
    u8 arr_167C[0x10];
    u32 unk_168C;
    u8 arr_1690[0x10];
    u32 unk_16A0;
    u8 arr_16A4[0x10];
    u32 unk_16B4;
    u8 arr_16B8[0x10];
    u32 unk_16C8;
    u8 unk_16CC;
    u8 pad_16CD[0x3];
    u32 unk_16D0;
    u32 unk_16D4;
    u32 unk_16D8;
    u32 unk_16DC;
    u8 unk_16E0;
    u8 pad_16E1[0x3];
    u32 unk_16E4;
    u32 unk_16E8;
    u32 unk_16EC;
    u32 unk_16F0;
    u32 unk_16F4;
    u32 unk_16F8;
    u32 unk_16FC;
    u32 unk_1700;
    u32 unk_1704;
    u32 unk_1708;
    u32 unk_170C;
    u32 unk_1710;
    u32 unk_1714;
    u32 unk_1718;
    u32 unk_171C;
    u32 unk_1720;
    u32 unk_1724;
    u32 unk_1728;
    u32 unk_172C;
    u32 unk_1730;
    u32 unk_1734;
    u32 unk_1738;
    u32 unk_173C;
    u32 unk_1740;
    u32 unk_1744;
    u32 unk_1748;
    u8 unk_174C;
    u8 unk_174D;
    u8 unk_174E;
    u8 pad_174F[0x1];
    u32 unk_1750;
    u8 unk_1754;
    u8 pad_1755[0x3];
    f32 unk_1758;
    f32 unk_175C;
    f32 unk_1760;
    u8 pad_1764[0x30];
    u32 unk_1794;
    u8 arr_1798[0x10];
    u32 unk_17A8;
    u8 arr_17AC[0x10];
    u32 unk_17BC;
    u32 unk_17C0;
    u32 unk_17C4;
    u32 unk_17C8;
    u32 unk_17CC;
    u16 unk_17D0;
    u16 unk_17D2;
    u16 unk_17D4;
    u16 unk_17D6;
    u16 unk_17D8;
    u8 pad_17DA[0x2];
    u32 unk_17DC;
    u32 unk_17E0;
    u32 unk_17E4;
    u32 unk_17E8;
    u32 unk_17EC;
    u8 unk_17F0;
    u8 unk_17F1;
    u8 unk_17F2;
    u8 unk_17F3;
    u8 unk_17F4;
    u8 unk_17F5;
    u8 unk_17F6;
    u8 unk_17F7;
    u8 unk_17F8;
    u8 unk_17F9;
    u8 unk_17FA;
    u8 unk_17FB;
    u8 unk_17FC;
    u8 unk_17FD;
    u8 unk_17FE;
    u8 pad_17FF[0x1];
    u16 unk_1800;
    u8 arr_1802[0xA];
    u8 arr_180C[0x14];
    u32 unk_1820;
    u32 unk_1824;
    u8 arr_1828[0x10];
    u16 unk_1838;
    s16 unk_183A;
    u32 unk_183C;
    u8 pad_1840[0x18];
    u8 arr_1858[0x80];
    u8 arr_18D8[0x30];
    u8 arr_1908[0xC0];
    u8 arr_19C8[0x620];
    u32 unk_1FE8;
    u16 unk_1FEC;
    u8 pad_1FEE[0x76];
    u32 unk_2064;
    u32 unk_2068;
    u32 unk_206C;
    u8 pad_2070[0x64];
    u8 arr_20D4[0x60];
    u8 arr_2134[0xB4];
    f32 unk_21E8;
    u8 pad_21EC[0x20];
    f32 unk_220C;
    u8 pad_2210[0x24D];
    u8 unk_245D;
    u8 pad_245E[0x141A];
    u32 unk_3878;
    u32 unk_387C;
    u8 unk_3880;
    u8 pad_3881[0x3];
    u32 unk_3884;
    u32 unk_3888;
    u8 unk_388C;
    u8 pad_388D[0x3];
    u32 unk_3890;
    u32 unk_3894;
    u32 unk_3898;
    f32 unk_389C;
    f32 unk_38A0;
    u8 unk_38A4;
    u8 unk_38A5;
    u8 unk_38A6;
    u8 pad_38A7[0x1];
    u32 unk_38A8;
    u32 unk_38AC;
    u32 unk_38B0;
    u32 unk_38B4;
    u32 unk_38B8;
    f32 unk_38BC;
    u32 unk_38C0;
    u8 arr_38C4[0x30];
    u8 arr_38F4[0xC0];
    u32 unk_39B4;
    u32 unk_39B8;
    u32 unk_39BC;
    u8 arr_39C0[0x30];
    u32 unk_39F0;
    u8 arr_39F4[0x10];
    u8 arr_3A04[0x30];
    u8 arr_3A34[0xC0];
    u8 arr_3AF4[0xC];
    u8 arr_3B00[0x30];
    u32 unk_3B30;
    u8 arr_3B34[0x8];
    u32 unk_3B3C;
    u32 unk_3B40;
    u32 unk_3B44;
    u8 pad_3B48[0x2];
    u16 unk_3B4A;
    u8 pad_3B4C[0x30];
    u32 unk_3B7C;
    u8 arr_3B80[0x58];
    u32 unk_3BD8;
} Obj_1_bss_7B180;
extern Obj_1_bss_7B180 lbl_1_bss_7B180;  // typedefs.json decl override

// lbl_1_data_3D544: .data size 0x10, referenced by 26 functions, shape {'object': 11}
typedef struct {
    u32 unk_0;  // 4 loads, 4 stores
    u8 pad_4[0x4];
    u8 unk_8;  // 1 loads, 0 stores
    u8 pad_9[0x7];
} Obj_1_data_3D544;
extern Obj_1_data_3D544 lbl_1_data_3D544;

// lbl_1_data_40530: .data size 0x6C, referenced by 26 functions, shape {}
extern char lbl_1_data_40530[0x6C];  // 'accessory.c'

// lbl_1_data_35AC8: .data size 0x4, referenced by 25 functions, shape {'object': 108}
extern u32 lbl_1_data_35AC8;

// lbl_1_bss_6D820: .bss size 0x4, referenced by 23 functions, shape {'object': 283}
extern u8 lbl_1_bss_6D820;

// lbl_1_bss_6C7A4: .bss size 0x28, referenced by 23 functions, shape {'object': 84}
typedef struct {
    u32 unk_0;  // 5 loads, 1 stores
    u8 unk_4;  // 5 loads, 2 stores
    u8 unk_5;  // 0 loads, 1 stores
    u8 unk_6;  // 0 loads, 1 stores
    u8 unk_7;  // 0 loads, 1 stores
    f32 unk_8;  // 9 loads, 2 stores
    u8 unk_C;  // 6 loads, 1 stores
    u8 unk_D;  // 1 loads, 1 stores
    u8 unk_E;  // 1 loads, 1 stores
    u8 unk_F;  // 1 loads, 0 stores
    u8 unk_10;  // 6 loads, 1 stores
    u8 unk_11;  // 1 loads, 1 stores
    u8 unk_12;  // 0 loads, 1 stores
    u8 unk_13;  // 0 loads, 1 stores
    u8 unk_14;  // 5 loads, 1 stores
    u8 unk_15;  // 0 loads, 1 stores
    u8 unk_16;  // 0 loads, 1 stores
    u8 pad_17[0x1];
    u32 unk_18;  // 5 loads, 1 stores
    u32 unk_1C;  // 5 loads, 1 stores
    u32 unk_20;  // 6 loads, 1 stores
    u32 unk_24;  // 6 loads, 1 stores
} Obj_1_bss_6C7A4;
extern Obj_1_bss_6C7A4 lbl_1_bss_6C7A4;

// lbl_1_bss_7EFD8: .bss size 0x44, referenced by 22 functions, shape {'object': 121}
// object reached through lbl_1_bss_7EFD8.unk_40
typedef struct {
    u8 unk_0;  // 1 loads, 0 stores
    u8 pad_1[0x97];
    u32 unk_98;  // 1 loads, 1 stores
    u32 unk_9C;  // 1 loads, 1 stores
    u16 unk_A0;  // 5 loads, 4 stores
    u16 unk_A2;  // 1 loads, 0 stores
} Obj_1_bss_7EFD8_At40;
typedef struct {
    u32 unk_0;  // 11 loads, 8 stores
    u32 unk_4;  // 1 loads, 2 stores
    u32 unk_8;  // 2 loads, 1 stores
    u32 unk_C;  // 3 loads, 1 stores
    u32 unk_10;  // 0 loads, 2 stores
    u32 unk_14;  // 2 loads, 2 stores
    u8 unk_18;  // 1 loads, 1 stores
    u8 unk_19;  // 0 loads, 4 stores
    u8 unk_1A;  // 1 loads, 3 stores
    u8 unk_1B;  // 1 loads, 3 stores
    u8 unk_1C;  // 0 loads, 2 stores
    u8 unk_1D;  // 0 loads, 1 stores
    u8 unk_1E;  // 0 loads, 1 stores
    u8 unk_1F;  // 0 loads, 1 stores
    u8 unk_20;  // 0 loads, 3 stores
    u8 unk_21;  // 0 loads, 2 stores
    u8 unk_22;  // 0 loads, 2 stores
    u8 unk_23;  // 0 loads, 2 stores
    u8 unk_24;  // 1 loads, 1 stores
    u8 unk_25;  // 0 loads, 1 stores
    u8 unk_26;  // 0 loads, 1 stores
    u8 unk_27;  // 0 loads, 1 stores
    u32 unk_28;  // 1 loads, 0 stores
    u8 pad_2C[0xC];
    u8 unk_38;  // 1 loads, 0 stores
    u8 pad_39[0x3];
    u8 unk_3C;  // 1 loads, 0 stores
    u8 pad_3D[0x3];
    Obj_1_bss_7EFD8_At40 *unk_40;  // 50 loads, 0 stores
} Obj_1_bss_7EFD8;
extern Obj_1_bss_7EFD8 lbl_1_bss_7EFD8;

// lbl_1_data_5730: .data size 0xC, referenced by 21 functions, shape {'object': 98}
extern char lbl_1_data_5730[0xC];  // 'OVERTAKE'

// lbl_1_bss_6EAB4: .bss size 0x12, referenced by 21 functions, shape {'object': 69}
typedef struct {
    u32 unk_0;  // 43 loads, 26 stores
    u8 pad_4[0xE];
} Obj_1_bss_6EAB4;
extern Obj_1_bss_6EAB4 lbl_1_bss_6EAB4;

// lbl_1_bss_4C688: .bss size 0x2000, referenced by 21 functions, shape {'object': 39}
typedef struct {
    u32 unk_0;  // 3 loads, 3 stores
    u8 pad_4[0x4];
    u32 unk_8;  // 1 loads, 0 stores
    u32 unk_C;  // 1 loads, 0 stores
    u8 pad_10[0x68];
    u32 unk_78;  // 1 loads, 0 stores
    u32 unk_7C;  // 1 loads, 0 stores
    u32 unk_80;  // 8 loads, 3 stores
    u8 pad_84[0x7C];
    u32 unk_100;  // 0 loads, 3 stores
    u8 pad_104[0x7C];
    u32 unk_180;  // 0 loads, 3 stores
    u8 pad_184[0x7C];
    u32 unk_200;  // 0 loads, 3 stores
    u8 pad_204[0x7C];
    u32 unk_280;  // 0 loads, 3 stores
    u8 pad_284[0x7C];
    u32 unk_300;  // 0 loads, 3 stores
    u8 pad_304[0x7C];
    u32 unk_380;  // 0 loads, 3 stores
    u8 pad_384[0x1C7C];
} Obj_1_bss_4C688;
extern Obj_1_bss_4C688 lbl_1_bss_4C688;

// lbl_1_data_3C7B8: .data size 0xA, referenced by 21 functions, shape {'object': 52}
extern char lbl_1_data_3C7B8[0xA];  // 'memcard.c'

// lbl_1_bss_84420: .bss size 0x8, referenced by 21 functions, shape {'object': 32, 'pointer': 10}
extern u32 lbl_1_bss_84420;

#endif  // REL_MAIN_REL_GLOBALS_H

/* end rel/main_rel/globals.h */
/* begin rel/main_rel/phys.h (deltawave784/fzgx, CC0) */
#ifndef REL_MAIN_REL_PHYS_H
#define REL_MAIN_REL_PHYS_H

/* rel/main_rel/globals.h: inlined above */

// Generated by `fzgx headers --module main_rel --tu phys.c`: globals of phys.c (referenced by its
// functions or living in its .data block), layouts recovered from every access in the module.

// lbl_1_bss_7AE88: .bss size 0x30, 11 refs from phys.c
#ifndef FZGX_TYPES_LBL_1_BSS_7AE88
#define FZGX_TYPES_LBL_1_BSS_7AE88
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u8 pad_0[0x554];
    f32 unk_554;  // 1 loads, 0 stores
    u8 pad_558[0x24];
    f32 unk_57C;  // 1 loads, 0 stores
    u8 pad_580[0x6C];
    f32 unk_5EC;  // 1 loads, 0 stores
    u8 pad_5F0[0x14EC];
    f32 unk_1ADC;  // 1 loads, 0 stores
    u8 pad_1AE0[0x24];
    f32 unk_1B04;  // 1 loads, 0 stores
    u8 pad_1B08[0x6C];
    f32 unk_1B74;  // 1 loads, 0 stores
    u8 pad_1B78[0xAFC];
    f32 unk_2674;  // 1 loads, 0 stores
    u8 pad_2678[0x24];
    f32 unk_269C;  // 1 loads, 0 stores
    u8 pad_26A0[0x6C];
    f32 unk_270C;  // 1 loads, 0 stores
    u8 pad_2710[0x508C];
    f32 unk_779C;  // 2 loads, 0 stores
    u8 pad_77A0[0x24];
    f32 unk_77C4;  // 2 loads, 0 stores
    u8 pad_77C8[0x6C];
    f32 unk_7834;  // 2 loads, 0 stores
} Obj_1_bss_7AE88_At10;
typedef struct {
    u32 unk_0;  // 13 loads, 3 stores
    s16 unk_4;  // 12 loads, 3 stores
    u8 pad_6[0x2];
    u32 unk_8;  // 12 loads, 3 stores
    s16 unk_C;  // 11 loads, 5 stores
    u8 pad_E[0x2];
    Obj_1_bss_7AE88_At10 *unk_10;  // 20 loads, 3 stores
    s16 unk_14;  // 11 loads, 5 stores
    u8 pad_16[0x2];
    u32 unk_18;  // 12 loads, 3 stores
    s16 unk_1C;  // 11 loads, 3 stores
    u8 pad_1E[0x2];
    u32 unk_20;  // 12 loads, 3 stores
    s16 unk_24;  // 11 loads, 4 stores
    u8 pad_26[0x2];
    u32 unk_28;  // 12 loads, 3 stores
    s16 unk_2C;  // 12 loads, 5 stores
    u8 pad_2E[0x2];
} Obj_1_bss_7AE88;
#endif
extern Obj_1_bss_7AE88 lbl_1_bss_7AE88;  // typedefs.json decl override

// lbl_1_bss_7B188: .bss size 0x8, 6 refs from phys.c
extern u32 lbl_1_bss_7B188;

// lbl_1_data_3E52C: .data size 0x4, 5 refs from phys.c (own data block)
extern u32 lbl_1_data_3E52C;

// lbl_1_data_3E358: .data size 0xC, 5 refs from phys.c (own data block)
extern u8 lbl_1_data_3E358[0xC];

// lbl_1_bss_7AEB8: .bss size 0x294, 4 refs from phys.c
typedef struct {
    u32 unk_0;  // 2 loads, 0 stores
    u8 pad_4[0x1E0];
    s16 unk_1E4;  // 1 loads, 0 stores
    u8 pad_1E6[0x6];
    f32 unk_1EC;  // 1 loads, 0 stores
    f32 unk_1F0;  // 1 loads, 0 stores
    f32 unk_1F4;  // 1 loads, 0 stores
    f32 unk_1F8;  // 1 loads, 0 stores
    f32 unk_1FC;  // 1 loads, 0 stores
    f32 unk_200;  // 1 loads, 0 stores
    f32 unk_204;  // 1 loads, 0 stores
    f32 unk_208;  // 1 loads, 0 stores
    f32 unk_20C;  // 1 loads, 0 stores
    u8 pad_210[0x30];
    u16 unk_240;  // 2 loads, 0 stores
    u16 unk_242;  // 2 loads, 0 stores
    u32 unk_244;  // 1 loads, 0 stores
    u8 pad_248[0xC];
    f32 unk_254;  // 1 loads, 2 stores
    f32 unk_258;  // 0 loads, 2 stores
    f32 unk_25C;  // 0 loads, 1 stores
    f32 unk_260;  // 0 loads, 1 stores
    u8 pad_264[0xC];
    u32 unk_270;  // 1 loads, 0 stores
    u8 pad_274[0x20];
} Obj_1_bss_7AEB8;
extern Obj_1_bss_7AEB8 lbl_1_bss_7AEB8;

// lbl_1_data_3DC98: .data size 0x6, 4 refs from phys.c
extern u32 lbl_1_data_3DC98;

// lbl_1_data_3E184: .data size 0xC, 3 refs from phys.c (own data block)
typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;  // 1 loads, 0 stores
} Obj_1_data_3E184;
extern Obj_1_data_3E184 lbl_1_data_3E184;

// lbl_1_data_3DDB4: .data size 0x88, 3 refs from phys.c (own data block)
extern u8 lbl_1_data_3DDB4[0x88];

// lbl_1_bss_7C85C: .bss size 0x71, 2 refs from phys.c
typedef struct {
    u32 unk_0;  // 2 loads, 2 stores
    u8 pad_4[0x6D];
} Obj_1_bss_7C85C;
extern Obj_1_bss_7C85C lbl_1_bss_7C85C;

// lbl_1_data_3E538: .data size 0x4, 2 refs from phys.c (own data block)
extern u32 lbl_1_data_3E538;

// lbl_1_data_3E5B4: .data size 0x78, 2 refs from phys.c (own data block)
extern u8 lbl_1_data_3E5B4[0x78];

// lbl_1_data_3E434: .data size 0x44, 1 refs from phys.c (own data block)
extern u8 lbl_1_data_3E434[0x44];

// lbl_1_data_3DE3C: .data size 0x4, 1 refs from phys.c (own data block)
extern u32 lbl_1_data_3DE3C;

// lbl_1_data_3E530: .data size 0x8, 1 refs from phys.c (own data block)
extern u32 lbl_1_data_3E530;

// lbl_1_data_3E53C: .data size 0x78, 1 refs from phys.c (own data block)
extern u8 lbl_1_data_3E53C[0x78];

// lbl_1_data_3E190: .data size 0x7, 1 refs from phys.c (own data block)
extern u32 lbl_1_data_3E190;

// lbl_1_data_3E154: .data size 0xC, 1 refs from phys.c (own data block)
extern u8 lbl_1_data_3E154[0xC];

// lbl_1_data_3E160: .data size 0x24, 1 refs from phys.c (own data block)
extern u8 lbl_1_data_3E160[0x24];

// lbl_1_data_3E150: .data size 0x4, 1 refs from phys.c (own data block)
extern u32 lbl_1_data_3E150;

// lbl_1_data_3DE40: .data size 0x128, 1 refs from phys.c (own data block)
extern u8 lbl_1_data_3DE40[0x128];

#endif  // REL_MAIN_REL_PHYS_H

/* end rel/main_rel/phys.h */
/* begin game/main_rel/phys_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_PHYS_TYPES_H
#define GAME_MAIN_REL_PHYS_TYPES_H

// Types (and the externs that name them) of phys.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

/* rel/main_rel/globals.h: inlined above */
/* rel/main_rel/phys.h: inlined above */

typedef struct Sig_fn_1_8D168_Fn1_8D168State {
    u8 pad[0x60];
    u32 field_60;
} Sig_fn_1_8D168_Fn1_8D168State;

struct fn_1_E35F0_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_E7E00_lbl_801A6410 {
    u32 unk_0;
};

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

typedef struct Obj_1A8 {
    u8 pad_0[0xA];
    s16 unk_A;
    u8 pad_C[2];
    s16 unk_E;
    u8 pad_10[0x128];
    u64 unk_138;
    u8 pad_140[0x1A8 - 0x140];
} Obj_1A8;

typedef struct {
    u8 unk0[0x100];
    s32 value;
} E573CObj;

typedef struct {
    u8 pad_0[0x8];
    f32 unk_8;
    f32 unk_C;
} Camera;

typedef void (*Cb)(void *, ...);
extern void fn_1_8D168(Sig_fn_1_8D168_Fn1_8D168State *);
extern void fn_1_E4A38(u32 arg0, u16 arg1, u16 arg2, Cb arg3);
extern const LocalStruct lbl_1_rodata_26F8;
extern void fn_1_4E92C(LocalStruct *, u32, u16, u16, u32);
extern s16 fn_1_E573C(E573CObj *self);
extern Camera *game_camera_get(void);

#endif  // GAME_MAIN_REL_PHYS_TYPES_H

/* end game/main_rel/phys_types.h */

extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 fn_1_E3C38(u32, u32);
extern s16 fn_1_E5430(s16 index);
extern void * fn_1_E54A8(s16 type, s16 index);
extern void lbl_8006DCA4(void *base, void *arg);
extern f32 fn_1_A71AC(void);
extern void fn_8006F828(void *base, f32 *out);
extern s16 fn_1_7B054(void);
extern u8 lbl_1_data_2B0D4[112];
extern u32 lbl_1_bss_85288[2];
extern char *fn_80083DB0(char *dst, const char *src);
extern size_t strlen(const char *str);
extern s32 fn_8006FC5C(void *, void *, size_t);
extern s32 fn_1_A5DC4(void);
extern void fn_1_9C724(void);
extern void fn_1_DD890(void *);
extern void fn_1_9CC40(void);
extern void fn_80077E0C(void *);
extern void fn_80076134(void);
extern char *strcat(char *dest, const char *src);
extern f32 lbl_1_rodata_6808;
extern f32 lbl_1_rodata_69CC;
extern f64 lbl_1_rodata_6800;
extern s16 fn_1_E5724(void *base);
extern s16 fn_1_E572C(void *base);
extern u32 fn_1_E57C4(void *base);
extern u8 *fn_1_E5748(u8 *self);
extern u8 *fn_1_E5750(u8 *self);
extern f32 fn_1_E5758(u8 *self);
extern u8 *fn_1_E5760(u8 *self);
extern u8 *fn_1_E5768(u8 *self);
extern f32 fn_1_E57A4(void *base);
extern f32 fn_1_E57AC(void *base);
extern f32 fn_1_E57B4(void *base);
extern f32 fn_1_E57BC(void *base);
extern void * fn_1_E57CC(void *base);
extern void * fn_1_E57D4(void *base);
extern void * fn_1_E57DC(void *base);
extern f32 fn_1_E57E4(void *base);
extern f32 fn_1_E57EC(void *base);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4AE0C(const char* format, ...);
extern void fn_1_A8DD4(const char *format, ...);
extern void fn_1_A8EF8(u16 arg0, u16 arg1);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_12EF80(s16 arg, s16 *out_group, s16 *out_entry);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern f32 lbl_1_rodata_67A8;
extern u32 lbl_1_rodata_6A8C[3];
extern u32 fn_80083970(const u8* left, const char* right);
extern void fn_1_8CED0(void* object, s32 value0, s32 value1);
extern void fn_1_8D0A4(void* object);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80073778(void *obj, s32 index);
extern void fn_80015C1C(f32 *out, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern void lbl_8006DFFC(void *, void *, void *);
extern void GXLoadTexMtxImm(void *, u32, s32);
extern f32 lbl_1_rodata_6780[236];
extern f32 fn_1_A6FE8(void);
extern void fn_1_E8938(void);
extern void fn_1_8D1C8(u32 arg0, u32 arg1, u32 arg2);
extern u32 fn_1_3F8C0(void);
extern u32 fn_80008E84(u32 arg0);
extern u32 lbl_1_bss_7C94C[67];
extern void fn_1_EE530(void);
extern u8 lbl_1_bss_7ECB4[72];
extern void fn_1_BC29C();
extern void fn_1_B9C0C(void);
extern void fn_1_1596DC(int index);
extern void fn_1_484CC(s32 index);
extern u32 fn_1_4630();
extern u8 lbl_1_bss_7C8CE;

#pragma opt_propagation off
void *fn_1_EB0D8(u32 i) {
    u32 *lengths;
    f32 **values;
    u32 n;
    Obj_1_bss_7B180 *base = &lbl_1_bss_7B180;
    u32 off;
    if ((s32)base->unk_8 == 0) {
        return 0;
    }
    off = i << 2;
    {
        u32 *a = &base->unk_1794;
        if (*(u32 *)((u8 *)a + off) == 0) {
            u32 *b = &base->unk_17A8;
            if (*(u32 *)((u8 *)b + off) == 0) {
                return 0;
            }
        }
    }
    {
        u32 off = i << 1;
        u16 *counts = &base->unk_1800;
        n = *(u16 *)((u8 *)counts + off);
    }
    if (n <= 1) {
        goto fail; /* Keep the verified branch to fail. */
    }
    {
        lengths = &base->unk_1824;
        values = (f32 **)&base->unk_1600;
        if ((*(f32 **)((u8 *)values + off))[*(u32 *)((u8 *)lengths + off) - 1] <= (f32)n) {
fail:
            return 0;
        }
    }
    if ((s32)base->unk_20 != 0 && base->unk_16CC != 255) {
        u32 c = base->unk_174E;
        u32 d = c - 2;
        if (i == d) {
            u32 j = c - 1;
            u8 *result = (u8 *)&base->unk_1758;
            return result + j * 12;
        }
        if (i == c - 1) {
            u32 off = d * 12;
            u8 *result = (u8 *)&base->unk_1758;
            return result + off;
        }
        {
            u32 off = i * 12;
            u8 *result = (u8 *)&base->unk_1758;
            return result + off;
        }
    }
    {
        u32 off = i * 12;
        u8 *result = (u8 *)&base->unk_1758;
        return result + off;
    }
}
/* fzgx:end fn_1_EB0D8 */

/* fzgx:begin fn_1_EB200 */
// Return whether the active state is one of the physics states.
int fn_1_EB200(void) {
    if ((s32)lbl_1_bss_7B188 == 0) {
        return 0;
    }

    if ((s32)lbl_1_data_3E52C == 14 ||
        (s32)lbl_1_data_3E52C == 16 ||
        (s32)lbl_1_data_3E52C == 15) {
        return 1;
    }

    return 0;
}
/* fzgx:end fn_1_EB200 */

/* fzgx:begin fn_1_EB248 */
// Return whether the current state is one of the supported race states.
int fn_1_EB248(void) {
    if ((s32)lbl_1_bss_7B188 == 0) {
        return 0;
    }

    {
        s32 state = lbl_1_data_3E52C;

        if ((u32)(state - 9) <= 4 ||
            (u32)(state - 5) <= 2 ||
            state == 8) {
            return 1;
        }
    }

    return 0;
}
/* fzgx:end fn_1_EB248 */

/* fzgx:begin fn_1_EB29C */
extern void lbl_8006DCA4(void *base, void *arg);
extern void fn_1_A71AC(void);
extern void fn_8006F828(void *base, f32 *out);
extern void fn_1_E4A38(void *base, s32 x, s32 y, void *arg);
extern void fn_80008BEC(void *dst, void *value, u32 size);
extern void fn_80008BA8(void *dst, void *value, u32 size);
extern f32 lbl_1_rodata_67A8;
extern u32 lbl_1_rodata_6A8C[3];
extern u32 fn_80083970(const u8* left, const char* right);
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

typedef struct {
    u8 pad_0[0x16CC];
    u8 unk_16CC;
    u8 pad_16CD[0x174E - 0x16CD];
    u8 unk_174E;
    u8 pad_174F[0x1754 - 0x174F];
    u8 unk_1754;
    u8 pad_1755[0x17D0 - 0x1755];
    s16 unk_17D0[5];
    u32 unk_17DC[5];
    u8 unk_17F0[15];
} PhysState_7B180;

// Reset the per-track physics state table.
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C[2];
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
u32 fzgx_obj_lbl_1_bss_7B1AC[1270];
u32 fzgx_obj_lbl_1_bss_7C584[177];
u32 lbl_1_bss_7C848__fzgx_offset_0;
u8 lbl_1_bss_7C848__fzgx_offset_4;
u8 lbl_1_bss_7C848__fzgx_offset_5;
u16 lbl_1_bss_7C848__fzgx_offset_6;
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C__fzgx_offset_70;
u8 lbl_1_bss_7C8CD;
u8 lbl_1_bss_7C8CE;
u8 lbl_1_bss_7C8CE__fzgx_offset_1;
u32 lbl_1_bss_7C8CE__fzgx_offset_2;
u8 lbl_1_bss_7C8CE__fzgx_offset_6;
u8 lbl_1_bss_7C8CE__fzgx_offset_7;
u16 lbl_1_bss_7C8CE__fzgx_offset_8;
u32 lbl_1_bss_7C8CE__fzgx_offset_A[15];
u32 lbl_1_bss_7C914[13];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C__fzgx_offset_0;
s16 lbl_1_bss_7C94C__fzgx_offset_4[5];
u16 lbl_1_bss_7C94C__fzgx_offset_E;
u32 lbl_1_bss_7C94C__fzgx_offset_10[5];
u8 lbl_1_bss_7C94C__fzgx_offset_24[15];
u8 lbl_1_bss_7C94C__fzgx_offset_33;
u32 lbl_1_bss_7C94C__fzgx_offset_34[54];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C848__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7C848__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7C848__fzgx_offset_5;
    s = *(u8 *)&lbl_1_bss_7C848__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_7;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_A;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_E;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_24;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_33;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_34;
}
#pragma section code_type ".text"

void fn_1_EB29C(void) {
    

    lbl_1_bss_7C848__fzgx_offset_4 = 0xFF;
    lbl_1_bss_7C8CE = 0;
    lbl_1_bss_7C8CE__fzgx_offset_6 = 0;
    lbl_1_bss_7C94C__fzgx_offset_4[0] = -1;
    lbl_1_bss_7C94C__fzgx_offset_10[0] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[0] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[1] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[2] = 0;
    lbl_1_bss_7C94C__fzgx_offset_4[1] = -1;
    lbl_1_bss_7C94C__fzgx_offset_10[1] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[3] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[4] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[5] = 0;
    lbl_1_bss_7C94C__fzgx_offset_4[2] = -1;
    lbl_1_bss_7C94C__fzgx_offset_10[2] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[6] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[7] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[8] = 0;
    lbl_1_bss_7C94C__fzgx_offset_4[3] = -1;
    lbl_1_bss_7C94C__fzgx_offset_10[3] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[9] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[10] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[11] = 0;
    lbl_1_bss_7C94C__fzgx_offset_4[4] = -1;
    lbl_1_bss_7C94C__fzgx_offset_10[4] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[12] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[13] = 0;
    lbl_1_bss_7C94C__fzgx_offset_24[14] = 0;
}
/* fzgx:end fn_1_EB29C */

/* fzgx:begin fn_1_ECE04 noprologue */
#include "rel/main_rel/phys.h"

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wc;
    u32 w10;
    u32 w14;
    u8 pad18[0x16e4 - 0x18];
    u32 w16e4;
    u32 w16e8;
    u8 pad16ec[0x174c - 0x16ec];
    u8 b174c;
    u8 b174d;
    u8 count;
    u8 pad174f[0x1794 - 0x174f];
    void *a1794[5];
    void *a17a8[13];
    s32 a17dc[8];
    u8 pad17fc[0x1820 - 0x17fc];
    u32 w1820;
    u8 pad1824[0x19c8 - 0x1824];
    u8 e19c8_row0[0x620]; u8 e19c8_row1[0x620]; u8 e19c8_row2[0x620]; u8 e19c8_row3[0x620];
    u8 pad_e[0x3894 - 0x19c8 - 4 * 0x620];
    u32 w3894;
    void *p3898;
    f32 f389c;
    f32 f38a0;
    u8 b38a4;
    u8 b38a5;
    u8 b38a6;
    u8 pad38a7;
    u32 w38a8;
    u32 w38ac;
    u32 w38b0;
    u32 w38b4;
    u32 w38b8;
} PhysBlk;

extern void *fn_1_8627C(s32);
extern const f32 lbl_1_rodata_6B60;
extern const f32 lbl_1_rodata_6C90;
extern s32 fn_1_F2F34(void);
extern void fn_1_ECF88(void);
extern void fn_1_98634(f32);
extern void fn_1_983CC(void *, void *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180;
u32 lbl_1_bss_7B180__fzgx_offset_4;
u32 fzgx_obj_lbl_1_bss_7B188;
u32 lbl_1_bss_7B188__fzgx_offset_4;
u32 lbl_1_bss_7B190;
u32 lbl_1_bss_7B190__fzgx_offset_4;
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C[2];
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
u32 fzgx_obj_lbl_1_bss_7B1AC[1270];
u32 fzgx_obj_lbl_1_bss_7C584[177];
u32 lbl_1_bss_7C848[2];
u32 lbl_1_bss_7C850[3];
u32 fzgx_obj_lbl_1_bss_7C85C[2];
u32 lbl_1_bss_7C85C__fzgx_offset_8;
u32 lbl_1_bss_7C85C__fzgx_offset_C;
u32 lbl_1_bss_7C85C__fzgx_offset_10[24];
u8 lbl_1_bss_7C85C__fzgx_offset_70;
u8 lbl_1_bss_7C8CD;
u8 lbl_1_bss_7C8CE;
u8 lbl_1_bss_7C8CE__fzgx_offset_1;
u32 lbl_1_bss_7C8CE__fzgx_offset_2[17];
void *lbl_1_bss_7C914[5];
u8 lbl_1_bss_7C914__fzgx_offset_14;
u8 lbl_1_bss_7C914__fzgx_offset_15;
u16 lbl_1_bss_7C914__fzgx_offset_16;
u32 lbl_1_bss_7C914__fzgx_offset_18[7];
u32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C[4];
s32 lbl_1_bss_7C94C__fzgx_offset_10[8];
u32 lbl_1_bss_7C94C__fzgx_offset_30[9];
u32 lbl_1_bss_7C94C__fzgx_offset_54;
u32 lbl_1_bss_7C94C__fzgx_offset_58[45];
u32 lbl_1_bss_7CA58[60];
u8 lbl_1_bss_7CA58__fzgx_offset_F0[0x620];
u32 lbl_1_bss_7CA58__fzgx_offset_710[1568];
u32 fzgx_obj_lbl_1_bss_7E9E8[6];
u32 lbl_1_bss_7EA00[5];
u32 lbl_1_bss_7EA00__fzgx_offset_14;
void *lbl_1_bss_7EA00__fzgx_offset_18;
f32 lbl_1_bss_7EA00__fzgx_offset_1C;
f32 lbl_1_bss_7EA00__fzgx_offset_20;
u8 lbl_1_bss_7EA00__fzgx_offset_24;
u8 lbl_1_bss_7EA00__fzgx_offset_25;
u8 lbl_1_bss_7EA00__fzgx_offset_26;
u8 lbl_1_bss_7EA00__fzgx_offset_27;
u32 lbl_1_bss_7EA00__fzgx_offset_28;
u32 lbl_1_bss_7EA00__fzgx_offset_2C;
u32 lbl_1_bss_7EA00__fzgx_offset_30;
u32 lbl_1_bss_7EA00__fzgx_offset_34;
u32 lbl_1_bss_7EA38;
u32 lbl_1_bss_7EA38__fzgx_offset_4[158];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&lbl_1_bss_7B180__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B188__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B190__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C584;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_7C8CE__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C914__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_7C914__fzgx_offset_15;
    s = *(u8 *)&lbl_1_bss_7C914__fzgx_offset_16;
    s = *(u8 *)&lbl_1_bss_7C914__fzgx_offset_18;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_30;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_54;
    s = *(u8 *)&lbl_1_bss_7C94C__fzgx_offset_58;
    s = *(u8 *)&lbl_1_bss_7CA58;
    s = *(u8 *)&lbl_1_bss_7CA58__fzgx_offset_F0;
    s = *(u8 *)&lbl_1_bss_7CA58__fzgx_offset_710;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7E9E8;
    s = *(u8 *)&lbl_1_bss_7EA00;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_18;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_24;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_25;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_26;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_27;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_28;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_2C;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_30;
    s = *(u8 *)&lbl_1_bss_7EA00__fzgx_offset_34;
    s = *(u8 *)&lbl_1_bss_7EA38;
    s = *(u8 *)&lbl_1_bss_7EA38__fzgx_offset_4;
}
#pragma section code_type ".text"

void fn_1_ECE04(void)
{
    

    lbl_1_bss_7EA00__fzgx_offset_14 = 0;
    lbl_1_bss_7C85C__fzgx_offset_70 = 0;
    lbl_1_bss_7C8CD = 0;
    lbl_1_bss_7EA00__fzgx_offset_18 = fn_1_8627C(0);
    lbl_1_bss_7EA00__fzgx_offset_24 = 0;
    lbl_1_bss_7EA00__fzgx_offset_1C = lbl_1_rodata_6B60;
    lbl_1_bss_7EA00__fzgx_offset_20 = lbl_1_rodata_6B60;
    lbl_1_bss_7EA00__fzgx_offset_25 = 0;
    lbl_1_bss_7EA00__fzgx_offset_26 = 0;
    lbl_1_bss_7EA00__fzgx_offset_28 = 0;
    if (fn_1_F2F34() == 0) {
        lbl_1_bss_7C94C__fzgx_offset_54 = 0;
        lbl_1_bss_7EA00__fzgx_offset_2C = lbl_1_bss_7C85C__fzgx_offset_8;
        lbl_1_bss_7EA00__fzgx_offset_30 = lbl_1_bss_7C85C__fzgx_offset_C;
        lbl_1_bss_7B188__fzgx_offset_4 = 0;
        fzgx_obj_lbl_1_bss_7B180 = 0;
        lbl_1_bss_7B190__fzgx_offset_4 = 0;
        fn_1_ECF88();
        lbl_1_data_3E530 = 2;
        lbl_1_bss_7EA00__fzgx_offset_34 = 0;
        lbl_1_bss_7EA38 = 0;
    } else {
        lbl_1_data_3E530 = 3;
    }
    {
        s32 *pd = lbl_1_bss_7C94C__fzgx_offset_10;
        void **pa = lbl_1_bss_7C914;
        u8 *pe = lbl_1_bss_7CA58__fzgx_offset_F0;
        void **pc = (*(void * (*)[13])&lbl_1_bss_7C914__fzgx_offset_14);
        u32 i;
        for (i = 0; i < lbl_1_bss_7C8CE; i++) {
            if (*pd == 0) {
                fn_1_98634(lbl_1_rodata_6C90);
                fn_1_983CC(pe, *pa);
                fn_1_98634(lbl_1_rodata_6B60);
            } else {
                fn_1_98634(lbl_1_rodata_6C90);
                fn_1_983CC(pe, (u8 *)*pc + 0x6e0);
                fn_1_98634(lbl_1_rodata_6B60);
            }
            pd++;
            pa++;
            pe += 0x620;
            pc++;
        }
    }
}
/* fzgx:end fn_1_ECE04 */

/* fzgx:begin fn_1_EF924 */
void fn_1_EF924(void) {
    fn_1_EE530();
    lbl_1_data_3E52C = lbl_1_data_3E538;
    fn_1_BC29C(lbl_1_bss_7ECB4);
    fn_1_B9C0C();
    fn_1_1596DC(2);
    fn_1_484CC(2);
}
/* fzgx:end fn_1_EF924 */

/* fzgx:begin fn_1_EFA1C */
void fn_1_EFA1C(void) {
    fn_1_EE530();
    lbl_1_data_3E52C = lbl_1_data_3E538;
}
/* fzgx:end fn_1_EFA1C */

/* fzgx:begin fn_1_F22E4 */
// Maps a course selection to its associated data value.
s16 fn_1_F22E4(s32 arg) {
    s16 group;
    s16 entry;
    s32 index;

    fn_1_12EF80((s16)arg, &group, &entry);
    index = (group - 1) * 6 + entry;
    return (s16)((s32 *)lbl_1_data_3E53C)[index];
}
/* fzgx:end fn_1_F22E4 */

/* fzgx:begin fn_1_F2338 */
#include "types.h"

extern void fn_1_12EF80(s16 value, s16 *arg1, s16 *arg2);



u32 fn_1_F2338(s32 value, u32 target) {
    s16 group;
    s16 entry;
    u32 packed;
    u32 hour;
    u32 minute;
    u32 low;

    value = (s16)value;
    fn_1_12EF80(value, &group, &entry);
    packed = (*(u32 (*)[30])&lbl_1_data_3E5B4)[(group - 1) * 6 + entry];
    minute = (packed >> 12) & 0xff;
    hour = (packed >> 20) & 0xff;
    minute += 0xa;
    low = packed & 0xfff;

    if (minute > 0x3c) {
        minute -= 0x3c;
        hour += 1;
    }

    packed = (hour << 20) | (minute << 12) | low;
    if (packed > target) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_F2338 */

/* fzgx:begin fn_1_F2740 */
u32 fn_1_F2740(u32 a, u32 b) {
    if (a >= 6) {
        return 0;
    }
    if (b >= 6) {
        return 0;
    }
    return ((u32 *)lbl_1_data_3E5B4)[(a - 1) * 6 + b];
}
/* fzgx:end fn_1_F2740 */
