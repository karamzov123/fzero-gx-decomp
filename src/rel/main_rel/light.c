#include "types.h"

/* A light definition (0x34 bytes): position, direction, two colours and the spot/distance setup. */
typedef struct {
    f32 pos[3];
    f32 dir[3];
    u8 color[4];
    u8 ambient[4];
    u8 kind;
    f32 distance;
    f32 brightness;
    f32 unk_2C;
    f32 cutoff;
} LightDef;

/* A light definition with the definition it is used with. */
typedef struct {
    LightDef *light;
    LightDef *base;
    u32 unk_8;
} LightPair;

/* A loaded hardware light object (GXLightObj, 0x40 bytes). */
typedef struct {
    u32 data[16];
} LightObj;

/* A specular light setup (0xC bytes). */
typedef struct {
    u32 data[3];
} LightSpec;

/* A light set: its mask, its specular light and the light object of each of the 8 channels. */
typedef struct {
    u16 mask;
    u16 spec;
    u16 lights[8];
} LightSet;

extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void fn_800793D4(void *dst, int value, u32 size);
extern void fn_800356B8(void *obj, u32 mask);
extern void fn_80074D28(void *spec);
extern u32 fn_80074D08(u32 mask);

LightDef lbl_1_data_1E558 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0x64, 0x64, 0x64, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E58C = {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0x64, 0x64, 0x64, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E5C0 = {{0.0f, 0.0f, 0.0f}, {-2.0f, -1.0f, -1.5f}, {0x87, 0x87, 0x87, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E5F4 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0x64, 0x64, 0x64, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E628 = {{0.0f, 0.0f, 0.0f}, {-4.0f, -6.0f, 1.0f}, {0x55, 0x55, 0x5A, 0xFF}, {0xFF, 0xEB, 0xC8, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E65C = {{0.0f, 0.0f, 0.0f}, {-4.0f, 5.0f, -1.0f}, {0x55, 0x46, 0x37, 0xFF}, {0x64, 0x6E, 0x78, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E690 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0x64, 0x64, 0x64, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E6C4 = {{0.0f, 0.0f, 0.0f}, {-2.5f, 3.0f, -2.5f}, {0x1C, 0x15, 0x23, 0xFF}, {0xFF, 0x32, 0x00, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E6F8 = {{0.0f, 0.0f, 0.0f}, {-2.5f, 3.0f, -2.5f}, {0x1C, 0x15, 0x4B, 0xFF}, {0xFF, 0x32, 0x00, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E72C = {{0.0f, 0.0f, 0.0f}, {-22.5f, -30.8f, 31.5f}, {0x9B, 0x87, 0x50, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E760 = {{0.0f, 0.0f, 0.0f}, {-35.0f, -50.0f, -30.0f}, {0x64, 0x64, 0x64, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E794 = {{0.0f, 0.0f, 0.0f}, {0.5f, -1.5f, 0.5f}, {0x5F, 0x69, 0x4A, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E7C8 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0xB4, 0x69, 0x50, 0xFF}, {0x55, 0x46, 0x40, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E7FC = {{0.0f, 0.0f, 0.0f}, {3.0f, 4.5f, -1.0f}, {0x73, 0x69, 0x4B, 0xFF}, {0x8C, 0x46, 0x40, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E830 = {{0.0f, 250.0f, 0.0f}, {0.0f, -1.0f, 0.0f}, {0xA0, 0xA0, 0xAC, 0xFF}, {0xC0, 0xF0, 0x90, 0xFF}, 1, 1000.0f, 0.5f, 0.0f, 90.0f};
LightDef lbl_1_data_1E864 = {{0.0f, 0.0f, 0.0f}, {-2.5f, -5.0f, -2.5f}, {0x50, 0x5A, 0x50, 0xFF}, {0xBE, 0x78, 0x5A, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E898 = {{0.0f, 0.0f, 0.0f}, {35.0f, -30.0f, 9.0f}, {0x46, 0x46, 0x46, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E8CC = {{0.0f, 0.0f, 0.0f}, {35.0f, -30.0f, 9.0f}, {0x78, 0x78, 0x78, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E900 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0x64, 0x64, 0x64, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1E934 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0x3C, 0x3C, 0x3C, 0xFF}, {0x5A, 0x5A, 0x5A, 0xFF}, 1, 1000.0f, 0.95f, 0.0f, 90.0f};
LightPair lbl_1_data_1E968 = {&lbl_1_data_1E558, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1E974 = {&lbl_1_data_1E5F4, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1E980 = {&lbl_1_data_1E628, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1E98C = {&lbl_1_data_1E65C, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1E998 = {&lbl_1_data_1E690, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1E9A4 = {&lbl_1_data_1E690, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1E9B0 = {&lbl_1_data_1E6C4, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1E9BC = {&lbl_1_data_1E6F8, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1E9C8 = {&lbl_1_data_1E72C, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1E9D4 = {&lbl_1_data_1E760, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1E9E0 = {&lbl_1_data_1E794, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1E9EC = {&lbl_1_data_1E7C8, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1E9F8 = {&lbl_1_data_1E7FC, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EA04 = {&lbl_1_data_1E830, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EA10 = {&lbl_1_data_1E864, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EA1C = {&lbl_1_data_1E898, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EA28 = {&lbl_1_data_1E8CC, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EA34 = {&lbl_1_data_1E900, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EA40 = {&lbl_1_data_1E5F4, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EA4C = {&lbl_1_data_1E5F4, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EA58 = {&lbl_1_data_1E934, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EA64 = {&lbl_1_data_1E5F4, &lbl_1_data_1E58C, 0};
LightDef lbl_1_data_1EA70 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0x64, 0x64, 0x64, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1EAA4 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0x64, 0x64, 0x64, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1EAD8 = {{0.0f, 0.0f, 0.0f}, {-4.0f, -6.0f, 1.0f}, {0x73, 0x73, 0x78, 0xFF}, {0xFF, 0xEB, 0xC8, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1EB0C = {{0.0f, 0.0f, 0.0f}, {-4.0f, -1.0f, -1.0f}, {0x55, 0x46, 0x37, 0xFF}, {0xFA, 0xC8, 0x64, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1EB40 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0x64, 0x64, 0x64, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1EB74 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -5.0f, -1.0f}, {0xE1, 0xB4, 0x96, 0xFF}, {0xFF, 0xE6, 0x64, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1EBA8 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0x64, 0x5A, 0x50, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1EBDC = {{0.0f, 0.0f, 0.0f}, {-22.5f, -30.8f, 31.5f}, {0x9B, 0x87, 0x50, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1EC10 = {{0.0f, 0.0f, 0.0f}, {0.5f, -1.5f, 0.5f}, {0x5F, 0x69, 0x4A, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1EC44 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0xF0, 0xA0, 0x50, 0xFF}, {0x87, 0x78, 0x69, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1EC78 = {{0.0f, 250.0f, 0.0f}, {0.0f, -1.0f, 0.0f}, {0xA0, 0xA0, 0xAC, 0xFF}, {0xC0, 0xF0, 0x90, 0xFF}, 1, 1000.0f, 0.5f, 0.0f, 90.0f};
LightDef lbl_1_data_1ECAC = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0xCD, 0xB4, 0xA0, 0xFF}, {0x55, 0x46, 0x40, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1ECE0 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0x64, 0x64, 0x64, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightDef lbl_1_data_1ED14 = {{0.0f, 0.0f, 0.0f}, {-1.0f, -1.0f, -1.0f}, {0x64, 0x64, 0x64, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, 0, 0.0f, 0.95f, 0.0f, 90.0f};
LightPair lbl_1_data_1ED48 = {&lbl_1_data_1EA70, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1ED54 = {&lbl_1_data_1EAA4, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1ED60 = {&lbl_1_data_1EAD8, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1ED6C = {&lbl_1_data_1EB0C, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1ED78 = {&lbl_1_data_1EB40, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1ED84 = {&lbl_1_data_1EB74, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1ED90 = {&lbl_1_data_1EBA8, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1ED9C = {&lbl_1_data_1EBA8, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EDA8 = {&lbl_1_data_1EBDC, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EDB4 = {&lbl_1_data_1EBDC, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EDC0 = {&lbl_1_data_1EC10, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EDCC = {&lbl_1_data_1EC44, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EDD8 = {&lbl_1_data_1EC44, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EDE4 = {&lbl_1_data_1EC78, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EDF0 = {&lbl_1_data_1ECAC, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EDFC = {&lbl_1_data_1ECE0, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EE08 = {&lbl_1_data_1ED14, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EE14 = {&lbl_1_data_1EAA4, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EE20 = {&lbl_1_data_1EAA4, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EE2C = {&lbl_1_data_1EAA4, &lbl_1_data_1E58C, 0};
LightPair lbl_1_data_1EE38 = {&lbl_1_data_1EAA4, &lbl_1_data_1E58C, 0};

/* light manager state: capacities, buffer sizes, counts, buffers, channel map, current mask */
static u16 lbl_1_bss_6D7A8; /* light objects */
static u16 lbl_1_bss_6D7AA; /* specular setups */
static u16 lbl_1_bss_6D7AC; /* light sets */
static u32 lbl_1_bss_6D7B0;
static u32 lbl_1_bss_6D7B4;
static u32 lbl_1_bss_6D7B8;
static u16 lbl_1_bss_6D7BC;
static u16 lbl_1_bss_6D7BE;
static u16 lbl_1_bss_6D7C0;
static LightObj *lbl_1_bss_6D7C4;
static LightSpec *lbl_1_bss_6D7C8;
static LightSet *lbl_1_bss_6D7CC;
static u16 lbl_1_bss_6D7D0[8];
static s32 lbl_1_bss_6D7E0;

static inline s32 light_highest_bit(u32 mask) {
    s32 bit = 31 - __cntlzw(mask);
    if (bit > 7 || bit < 0) {
        OSPanic("light.c", 48, "illegal light mask.");
    }
    return bit;
}

/* fzgx:begin fn_1_7BA08 */
u32 fn_1_7BA08(u16 maxLights, u16 maxSpecs, u16 maxSets) {
    lbl_1_bss_6D7A8 = maxLights;
    lbl_1_bss_6D7AA = maxSpecs;
    lbl_1_bss_6D7AC = maxSets;
    lbl_1_bss_6D7B0 = maxLights * 64;
    lbl_1_bss_6D7B4 = maxSpecs * 12;
    lbl_1_bss_6D7B8 = maxSets * 20;
    return lbl_1_bss_6D7B0 + lbl_1_bss_6D7B4 + lbl_1_bss_6D7B8;
}
/* fzgx:end fn_1_7BA08 */

/* fzgx:begin fn_1_7BA48 */
void fn_1_7BA48(u8 *buf) {
    int i;

    fn_800793D4(buf, 0, lbl_1_bss_6D7B0 + lbl_1_bss_6D7B4 + lbl_1_bss_6D7B8);
    lbl_1_bss_6D7BC = lbl_1_bss_6D7BE = lbl_1_bss_6D7C0 = 0;
    lbl_1_bss_6D7C4 = (LightObj *)buf;
    lbl_1_bss_6D7C8 = (LightSpec *)(buf + lbl_1_bss_6D7B0);
    lbl_1_bss_6D7CC = (LightSet *)((u8 *)lbl_1_bss_6D7C8 + lbl_1_bss_6D7B4);
    for (i = 0; i < 8; i++) {
        lbl_1_bss_6D7D0[i] = 0xFFFF;
    }
    lbl_1_bss_6D7E0 = 0;
}
/* fzgx:end fn_1_7BA48 */

/* fzgx:begin fn_1_7BAF8 */
void fn_1_7BAF8(u8 *buf) {
    int i;

    fn_800793D4(buf, 0, lbl_1_bss_6D7B0 + lbl_1_bss_6D7B4 + lbl_1_bss_6D7B8);
    lbl_1_bss_6D7BC = lbl_1_bss_6D7BE = lbl_1_bss_6D7C0 = 0;
    for (i = 0; i < 8; i++) {
        lbl_1_bss_6D7D0[i] = 0xFFFF;
    }
    lbl_1_bss_6D7E0 = 0;
}
/* fzgx:end fn_1_7BAF8 */

/* fzgx:begin fn_1_7BB80 */
void fn_1_7BB80(LightObj *obj, u32 mask) {
    s32 bit;

    if (lbl_1_bss_6D7BC >= lbl_1_bss_6D7A8) {
        OSPanic("light.c", 121, "light obj over.");
    }
    lbl_1_bss_6D7C4[lbl_1_bss_6D7BC] = *obj;
    bit = light_highest_bit(mask);
    lbl_1_bss_6D7D0[bit] = lbl_1_bss_6D7BC;
    fn_800356B8(obj, mask);
    lbl_1_bss_6D7BC++;
}
/* fzgx:end fn_1_7BB80 */

/* fzgx:begin fn_1_7BCCC */
void fn_1_7BCCC(LightSpec *spec) {
    if (lbl_1_bss_6D7BE >= lbl_1_bss_6D7AA) {
        OSPanic("light.c", 143, "spec light over.");
    }
    lbl_1_bss_6D7C8[lbl_1_bss_6D7BE] = *spec;
    fn_80074D28(spec);
    lbl_1_bss_6D7BE++;
}
/* fzgx:end fn_1_7BCCC */

/* fzgx:begin fn_1_7BD6C */
u32 fn_1_7BD6C(s32 mask) {
    s32 bit;
    s32 i;
    LightSet *set;
    u32 result;

    if (lbl_1_bss_6D7C0 >= lbl_1_bss_6D7AC) {
        OSPanic("light.c", 165, "light mask over.");
    }
    set = &lbl_1_bss_6D7CC[lbl_1_bss_6D7C0];
    set->mask = mask;
    set->spec = lbl_1_bss_6D7BE - 1;
    lbl_1_bss_6D7E0 = mask;
    result = fn_80074D08(mask);
    bit = light_highest_bit(mask);
    i = bit;
    bit = 1; /* bit now holds the mask step */
    while (i >= 0) {
        if (lbl_1_bss_6D7D0[i] == 0xFFFF) {
            OSPanic("light.c", 177, "no set light has used.");
        }
        set->lights[i] = lbl_1_bss_6D7D0[i];
        mask &= ~(bit << i);
        i = 31 - __cntlzw(mask);
    }
    lbl_1_bss_6D7C0++;
    return result;
}
/* fzgx:end fn_1_7BD6C */

/* fzgx:begin fn_1_7BE94 */
u16 fn_1_7BE94(void) {
    return lbl_1_bss_6D7C0 - 1;
}
/* fzgx:end fn_1_7BE94 */

/* fzgx:begin fn_1_7BEAC */
void fn_1_7BEAC(u16 index) {
    u32 i;
    LightSet *set = &lbl_1_bss_6D7CC[index];
    s32 changed = 0;

    for (i = 0; i < 8; i++) {
        if (set->lights[i] != lbl_1_bss_6D7D0[i]) {
            fn_800356B8(&lbl_1_bss_6D7C4[set->lights[i]], 1 << i);
            changed = 1;
            lbl_1_bss_6D7D0[i] = set->lights[i];
        }
    }
    if (lbl_1_bss_6D7BE != set->spec && lbl_1_bss_6D7BE != 0) {
        fn_80074D28(&lbl_1_bss_6D7C8[set->spec]);
        lbl_1_bss_6D7BE = set->spec;
    }
    if (lbl_1_bss_6D7E0 != set->mask || changed != 0) {
        fn_80074D08(set->mask);
        lbl_1_bss_6D7E0 = set->mask;
    }
}
/* fzgx:end fn_1_7BEAC */
