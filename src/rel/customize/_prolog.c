#include "types.h"

/* fzgx:begin fn_3_0 */
typedef struct {
    volatile u8 field_0; /* Preserve the retail reload after calls and stores. */
    u8 pad[3];
    u32 field_4[1];
} Part;

typedef struct {
    Part parts[3];
    u8 pad_18[2];
    volatile s16 indices[3]; /* Preserve the retail reload after calls and stores. */
} Bss20;

extern u16 lbl_3_bss_20[104];
extern u8 lbl_3_bss_140[];

extern void fn_80008BA8(void *, void *, u32);
extern s16 fn_1_14F118(s16, s16);
extern s32 fn_1_F809C(s32);
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 fn_1_151BE8(s16, s16);
extern s32 fn_1_8D690(s16);

static inline void helper(Bss20 *bss20) {
    s16 i;
    volatile s16 *pIndex; /* Preserve the retail reload after calls and stores. */
    s32 j;

    for (i = 0; i < 3; i++) {
        bss20->indices[i] = 0;
        bss20->parts[i].field_0 = fn_1_14F090(i, bss20->indices[i]);
        pIndex = &bss20->indices[i];
        while (fn_1_F809C(bss20->parts[i].field_0) == 0) {
            s32 val;

            if ((val = *pIndex + 1) > fn_1_14F01C(i) - 1) {
                val = 0;
            } else if (val < 0) {
                val = fn_1_14F01C(i) - 1;
            }
            *pIndex = val;
            bss20->parts[i].field_0 = fn_1_14F090(i, *pIndex);
        }
        for (j = 0; (s16)j < 1; j++) {
            bss20->parts[i].field_4[j] = fn_1_151BE8(bss20->parts[i].field_0, (s16)j);
        }
    }
    lbl_3_bss_20[103] = 6;
}

static inline void helper_b(Bss20 *bss20) {
    s16 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        bss20->indices[i] = 0;
        bss20->parts[i].field_0 = fn_1_14F090(i, bss20->indices[i]);
        while (fn_1_F809C(bss20->parts[i].field_0) == 0) {
            s32 val;

            if ((val = bss20->indices[i] + 1) > fn_1_14F01C(i) - 1) {
                val = 0;
            } else if (val < 0) {
                val = fn_1_14F01C(i) - 1;
            }
            bss20->indices[i] = val;
            bss20->parts[i].field_0 = fn_1_14F090(i, bss20->indices[i]);
        }
        for (j = 0; (s16)j < 1; j++) {
            bss20->parts[i].field_4[j] = fn_1_151BE8(bss20->parts[i].field_0, (s16)j);
        }
    }
    lbl_3_bss_20[103] = 6;
}

static inline void helper_c(Bss20 *bss20) {
    s16 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        bss20->indices[i] = 0;
        bss20->parts[i].field_0 = fn_1_14F090(i, bss20->indices[i]);
        while (fn_1_F809C(bss20->parts[i].field_0) == 0) {
            s32 val;

            if ((val = bss20->indices[i] + 1) > fn_1_14F01C(i) - 1) {
                val = 0;
            } else if (val < 0) {
                val = fn_1_14F01C(i) - 1;
            }
            bss20->indices[i] = val;
            bss20->parts[i].field_0 = fn_1_14F090(i, bss20->indices[i]);
        }
        for (j = 0; (s16)j < 1; j++) {
            bss20->parts[i].field_4[j] = fn_1_151BE8(bss20->parts[i].field_0, (s16)j);
        }
    }
    lbl_3_bss_20[103] = 6;
}

static inline u32 fn_3_0_operand(u32 right, u32 left) { left *= right; return left; }
#pragma opt_dead_assignments off
static inline volatile s16 *fn_3_0_array_read(volatile s16 *array) { return array; } /* Preserve the retail reload after calls and stores. */
void fn_3_0(u32 arg0, s32 arg1) {
    struct { Bss20 *value; } bss20;
    s32 offset = (fn_3_0_operand(((0x81c0)), (((s16)arg0))));
    u8 *p = (u8 *)&lbl_3_bss_140 + offset;
    u32 flags = *(u32 *)p;

    if (flags & 0x80000000) {
        if (flags & 0x40000000) {
            s16 i;
            s32 flag = 0;

            fn_80008BA8(lbl_3_bss_20, p + 0x81A4, 0x18);
            bss20.value = (Bss20 *)lbl_3_bss_20;
            for (i = 0; i < 3; i++) {
                bss20.value->indices[i] = fn_1_14F118(bss20.value->parts[i].field_0, i);
                if (fn_3_0_array_read(bss20.value->indices)[i] == -1) {
                    flag = 1;
                }
                if (arg1 != 0 && fn_1_F809C(bss20.value->parts[i].field_0) == 0) {
                    flag = 1;
                }
                if (flag == 1) {
                    helper(bss20.value);
                    return;
                }
            }

            if (arg1 != 0 && fn_1_8D690(lbl_3_bss_140[offset + 0x81A0]) == 0) {
                lbl_3_bss_20[103] = 6;
            } else {
                lbl_3_bss_20[103] = lbl_3_bss_140[offset + 0x81A0];
            }
        } else {
            helper_b((Bss20 *)lbl_3_bss_20);
            lbl_3_bss_20[103] = lbl_3_bss_140[offset + 0x81A0];
        }
    } else {
        helper_c((Bss20 *)lbl_3_bss_20);
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_3_0 */

/* fzgx:begin fn_3_844 */
extern void fn_3_2B774(void);
extern void fn_3_BD30(void);
extern void fn_1_4A00(u32, u32, u32);
extern void fn_1_A2D84(u32);

extern s16 lbl_1_bss_962;
extern struct {
    u8 pad[8];
    u16 flags;
} lbl_1_bss_9F8;
extern s32 lbl_1_bss_970;
extern s16 lbl_1_bss_968;
extern u32 lbl_1_bss_6EAB4;
extern u32 lbl_3_bss_20850;

void fn_3_844(void) {
    fn_3_2B774();
    fn_3_BD30();

    if (lbl_1_bss_962 == 0x5c) {
        if ((lbl_1_bss_9F8.flags >> 9) & 1) {
            fn_1_4A00(0, 0xf, lbl_3_bss_20850);
            lbl_1_bss_970 = 0x10;
            fn_1_A2D84(0xA9010200);
            lbl_1_bss_6EAB4 |= 0x24;
        }

        if (lbl_1_bss_970 > 0) {
            if (--lbl_1_bss_970 == 0) {
                lbl_1_bss_968 = 1;
            }
        }
    }
}
/* fzgx:end fn_3_844 */

/* fzgx:begin fn_3_8F8 */
extern u32 lbl_3_bss_2084C;
extern u32 lbl_3_bss_20850;

extern void fn_1_435C(u32 value);
extern void fn_1_407C(void);
extern void fn_1_3CC4(void);
extern void camera_update(void);

void fn_3_8F8(void) {
    fn_1_435C(lbl_3_bss_2084C);
    fn_1_407C();
    fn_1_3CC4();
    camera_update();
    fn_1_435C(lbl_3_bss_20850);
    fn_1_407C();
}
/* fzgx:end fn_3_8F8 */

/* fzgx:begin fn_3_AF8 */
extern u8 lbl_3_bss_140[132868];

typedef struct {
    s16 index;
} Fn3AF8Arg;

int fn_3_AF8(Fn3AF8Arg *arg) {
    u32 *entry = (u32 *)(lbl_3_bss_140 + arg->index * 0x81c0);

    *entry |= (u32)1 << 31;
    *entry &= 0xBFFFFFFF;
    return 0;
}
/* fzgx:end fn_3_AF8 */

/* fzgx:begin fn_3_B30 */
extern u8 lbl_3_bss_140[132868];

typedef struct {
    s16 index;
} Fn3B30Data;

s32 fn_3_B30(Fn3B30Data *data) {
    s16 index = data->index;
    u32 *entry = (u32 *)(lbl_3_bss_140 + index * 0x81c0);
    *entry |= (u32)1 << 31;
    *entry |= (u32)1 << 30;
    return 0;
}
/* fzgx:end fn_3_B30 */

/* fzgx:begin fn_3_B68 */
extern u8 lbl_3_bss_140[132868];

s32 fn_3_B68(const s16 *value) {
    u8 *base = lbl_3_bss_140;
    s32 offset = (s32)*value * 0x81c0;
    u32 *entry = (u32 *)(base + offset);

    *entry &= 0xbfffffffu;
    *entry &= 0x7fffffffu;
    return 0;
}
/* fzgx:end fn_3_B68 */

/* fzgx:begin fn_3_BA0 */
typedef struct CustomizeEntry {
    u8 pad[0x20];
    void (*function)(void);
    u32 value24;
    u32 value28;
} CustomizeEntry;

extern u8 lbl_3_data_1230[924];
extern s16 lbl_1_bss_962;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;

void fn_3_BA0(void) {
    CustomizeEntry *entry;
    s16 index;

    entry = (CustomizeEntry *)lbl_3_data_1230;
    index = lbl_1_bss_962;
    entry += index - 0x5b;
    lbl_1_bss_71688 = entry->value24;
    lbl_1_bss_7168C = entry->value28;
    entry->function();
}
/* fzgx:end fn_3_BA0 */

/* fzgx:begin fn_3_BFC */
extern void fn_80083DB0(char *destination, const char *source);
extern char *fn_80083970(char *buffer, const char *source);
extern unsigned int strlen(const char *string);
extern char *strncpy(char *destination, const char *source, unsigned int count);
extern char *strcat(char *destination, const char *source);

void fn_3_BFC(char *destination, void *unused, const char *source, const char *suffix) {
    char buffer[0x400];
    char *prefix;
    unsigned int source_length;
    unsigned int prefix_length;

    fn_80083DB0(buffer, unused);
    prefix = fn_80083970(buffer, source);
    if (prefix == 0) {
        fn_80083DB0(destination, buffer);
    } else {
        source_length = strlen(source);
        if (prefix != buffer) {
            prefix_length = (unsigned int)(prefix - buffer);
            strncpy(destination, buffer, prefix_length);
            destination[prefix_length] = 0;
        } else {
            destination[0] = 0;
        }
        strcat(destination, suffix);
        strcat(destination, prefix + source_length);
    }
}
/* fzgx:end fn_3_BFC */

/* fzgx:begin fn_3_10A4 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 320.0f;
    s = 240.0f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = 0.5f;
    s = 480.0f;
    s = 2.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table2[7] = {0x00000000, 0x00000000, 0x41200000, 0x41200000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.25f;
}
static const u32 fzgx_pool_table4[2] = {0x00000000, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 500.0f;
    s = 300.0f;
    s = 0.10000000149011612f;
}
static const u32 fzgx_pool_table6[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = -1.0f;
    s = 8.0f;
    s = 4.0f;
    s = 150.0f;
    s = 0.09000000357627869f;
    s = 30.0f;
    s = 0.550000011920929f;
    s = 0.75f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table8[8] = {0xA0505000, 0xA0A0A000, 0xFFFFFF00, 0x70707000, 0x00000000, 0x70707000, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 288.0f;
    s = 0.07999999821186066f;
    s = 10.0f;
    s = 352.0f;
}
#pragma section code_type ".text"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

extern const char *lbl_3_data_E80[12];
extern char lbl_3_data_15D4[];
extern s32 lbl_801A66B4;

extern u32 fn_800081C8(Color a, Color b, f32 t);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_49514(Color c);
extern void fn_1_4AE0C(const char *, ...);
extern u32 fn_1_4D4C8(Color c, f32, f32);
extern void fn_1_49528(Color c);

void fn_3_10A4(u8 *arg0) {
    /* Interpret the packed interpolation result as RGBA bytes. */
    union {
        Color c;
        u32 v;
    } col;
    Color a = {0xA0, 0x50, 0x50, 0x00};
    Color b = {0xA0, 0xA0, 0xA0, 0x00};
    u32 tmp_call1;
    Color lab_t0;

{
    tmp_call1 = fn_800081C8(a, b, 1.0f);
    col.v = tmp_call1;
}
    fn_1_49410();
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4954C(0.09f);
    fn_1_495C8(9);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 4.0f);
    }
    fn_1_496FC(288.0f, 300.0f);
    fn_1_495C8(10);
    if (((0) == (*arg0))) {
        fn_1_4D494();
        {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(c);
        }
        fn_1_4AE0C(lbl_3_data_15D4, lbl_3_data_E80[lbl_801A66B4]);
        fn_1_4D4C8(col.c, 0.09f, 10.0f);
    } else {
        {
            Color c = {0x70, 0x70, 0x70, 0x00};
            fn_1_49514(c);
        }
        {
            Color c = {0x00, 0x00, 0x00, 0x00};
            fn_1_49528(c);
        }
        fn_1_4AE0C("%s", lbl_3_data_E80[lbl_801A66B4]);
    }
    fn_1_496FC(352.0f, 300.0f);
    fn_1_495C8(8);
    if (((0) == (*arg0))) {
        {
            Color c = {0x70, 0x70, 0x70, 0x00};
            fn_1_49514(c);
        }
        {
            Color c = {0x00, 0x00, 0x00, 0x00};
            fn_1_49528(c);
        }
        fn_1_4AE0C(lbl_3_data_15D4, lbl_3_data_E80[lbl_801A66B4 + 6]);
    } else {
        fn_1_4D494();
        {
            Color c = {0xFF, 0xFF, 0xFF, 0x00};
            fn_1_49514(c);
        }
        fn_1_4AE0C(lbl_3_data_15D4, lbl_3_data_E80[lbl_801A66B4 + 6]);
        lab_t0 = col.c;
        fn_1_4D4C8(lab_t0, 0.09f, 10.0f);
    }
}
/* fzgx:end fn_3_10A4 */

/* fzgx:begin fn_3_12D4 noprologue */
#include "types.h"
#include "dolphin/types.h"

extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);

typedef struct Color {
    u8 r, g, b, a;
} Color;

extern void fzgx_pool_f32(f32);
extern void fzgx_pool_f64(f64);
extern void fzgx_pool_addr(void *);

#pragma section code_type ".fzgxpool"

void fzgx_pool_primer0(void)
{
    fzgx_pool_f32(0.0f);
    fzgx_pool_f32(320.0f);
    fzgx_pool_f32(240.0f);
    fzgx_pool_f32(0.001f);
    fzgx_pool_f32(0.01f);
    fzgx_pool_f32(0.5f);
    fzgx_pool_f32(480.0f);
    fzgx_pool_f32(2.0f);
    fzgx_pool_f64(4503599627370496.0);
}

void fzgx_pool_primer1(void)
{
    f32 values[6] = {0.0f, 10.0f, 10.0f, 0.0f, 0.0f, 0.0f};
    fzgx_pool_addr(values);
    fzgx_pool_f32(0.25f);
}

void fzgx_pool_primer2(void)
{
    Color color = {0, 0, 0, 0};
    fzgx_pool_addr(&color);
}

#pragma section code_type ".text"

void fn_3_12D4(void)
{
    Color color = { 255, 255, 255, 255 };
    fn_1_53BD8(&color, 320.0f, 240.0f, 500.0f, 300.0f, 0.1f);
}
/* fzgx:end fn_3_12D4 */

/* fzgx:begin fn_3_131C */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = 0.5f;
    s = 480.0f;
    s = 2.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table3[7] = {0x00000000, 0x00000000, 0x41200000, 0x41200000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.25f;
    s = 0.0f;
}
static const u32 fzgx_pool_table5[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 500.0f;
    s = 300.0f;
    s = 0.10000000149011612f;
}
static const u32 fzgx_pool_table7[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = -1.0f;
    s = 8.0f;
    s = 4.0f;
    s = 150.0f;
    s = 0.09000000357627869f;
    s = 30.0f;
    s = 0.550000011920929f;
    s = 0.75f;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

extern u8 lbl_3_bss_2437C[];
extern u8 lbl_3_data_E80[];
extern char lbl_3_data_15CC[];
extern s32 lbl_801A66B4;

extern u32 fn_1_4AEC0(u32);
extern void fn_1_4AEB4(f32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_3_BFC(char *, void *, const char *, const char *);

void fn_3_131C(s32 arg0, void *arg1) {
    f32 v0;
    char scratch[0x400];

    fn_1_4AEC0(1);
    fn_1_4AEB4(1.5f);
    fn_1_49410();
    v0 = 0.75f;
    fn_1_4955C(v0, v0);
    fn_1_4954C(0.09000000357627869f);
    fn_1_495C8(9);
    fn_1_496FC(320.0f, (f32)arg0);
    fn_1_4966C(-1.0f, 8.0f);

    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 4.0f);
    }

    fn_3_BFC(scratch, arg1, lbl_3_data_15CC,
             *(const char **)(lbl_3_data_E80 +
                              (u32)lbl_3_bss_2437C[0] * 0x18 +
                              (u32)lbl_801A66B4 * 4));
    fn_3_BFC(scratch, scratch, lbl_3_data_15CC,
             *(const char **)(lbl_3_data_E80 +
                              (u32)lbl_3_bss_2437C[0] * 0x18 +
                              (u32)lbl_801A66B4 * 4));
    fn_3_BFC(scratch, scratch, lbl_3_data_15CC,
             *(const char **)(lbl_3_data_E80 +
                              (u32)lbl_3_bss_2437C[0] * 0x18 +
                              (u32)lbl_801A66B4 * 4));
    fn_1_4A0D8(scratch);
    fn_1_4AEC0(0);
    fn_1_4AEB4(0.0f);
}
/* fzgx:end fn_3_131C */

/* fzgx:begin fn_3_14C4 */
extern void fn_3_E64(void);

void fn_3_14C4(void) {
    fn_3_E64();
}
/* fzgx:end fn_3_14C4 */

/* fzgx:begin fn_3_33A0 */
extern void fn_1_131004(void);
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_47F74(int value);

extern u32 lbl_3_data_BC[2];
extern u32 lbl_3_bss_20850;
extern u16 lbl_3_bss_F0[24];

void fn_3_33A0(void) {
    fn_1_131004();
    if (*(s32 *)lbl_3_data_BC != -1) {
        fn_1_435C(lbl_3_bss_20850);
        fn_1_426C(lbl_3_data_BC[0]);
        lbl_3_data_BC[0] = (u32)-1;
    }
    if (*(u32 *)lbl_3_bss_F0 & ((u32)1 << 31)) {
        fn_1_47F74(0x85);
        fn_1_47F74(0xa1);
    }
    *(u32 *)lbl_3_bss_F0 &= 0x02ffffff;
}
/* fzgx:end fn_3_33A0 */

/* fzgx:begin fn_3_3438 */
struct fn_3_3438_lbl_3_bss_F0 {
    u32 unk_0;
};
struct fn_3_3438_lbl_3_data_B8 {
    u32 unk_0;
};
struct fn_3_3438_lbl_3_bss_20850 {
    u32 unk_0;
};
extern s16 lbl_1_bss_96A;
extern struct fn_3_3438_lbl_3_bss_20850 lbl_3_bss_20850;
extern struct fn_3_3438_lbl_3_bss_F0 lbl_3_bss_F0;
extern struct fn_3_3438_lbl_3_data_B8 lbl_3_data_B8;
extern void fn_3_968C(void);
extern u32 fn_1_435C(u32);
extern void fn_3_4A84(void);
extern void fn_1_48140(int);

s32 fn_1_426C(u32);                             /* extern */
s32 fn_3_5A50();                                /* extern */
s32 fn_3_AC4C();                                /* extern */

void fn_3_3438(void) {
    if ((lbl_3_bss_F0.unk_0 & 0x40000000) && ((s16) (*(s16 *)((u8 *)(&lbl_1_bss_96A) + 0)) != 0x6B)) {
        fn_3_968C();
        if ((s32) lbl_3_data_B8.unk_0 != -1) {
            fn_1_435C(lbl_3_bss_20850.unk_0);
            fn_1_426C(lbl_3_data_B8.unk_0);
            lbl_3_data_B8.unk_0 = -1U;
        }
    } else if ((lbl_3_bss_F0.unk_0 & 0x20000000) && ((s16) (*(s16 *)((u8 *)(&lbl_1_bss_96A) + 0)) != 0x6C)) {
        fn_3_AC4C();
        if ((s32) lbl_3_data_B8.unk_0 != -1) {
            fn_1_435C(lbl_3_bss_20850.unk_0);
            fn_1_426C(lbl_3_data_B8.unk_0);
            lbl_3_data_B8.unk_0 = -1U;
        }
    } else if ((lbl_3_bss_F0.unk_0 & 0x10000000) && ((s16) (*(s16 *)((u8 *)(&lbl_1_bss_96A) + 0)) != 0x60)) {
        fn_3_4A84();
        if ((s32) lbl_3_data_B8.unk_0 != -1) {
            fn_1_435C(lbl_3_bss_20850.unk_0);
            fn_1_426C(lbl_3_data_B8.unk_0);
            lbl_3_data_B8.unk_0 = -1U;
        }
    } else if ((lbl_3_bss_F0.unk_0 & 0x08000000) && ((s16) (*(s16 *)((u8 *)(&lbl_1_bss_96A) + 0)) != 0x68)) {
        if ((s32) lbl_3_data_B8.unk_0 != -1) {
            fn_1_435C(lbl_3_bss_20850.unk_0);
            fn_1_426C(lbl_3_data_B8.unk_0);
            lbl_3_data_B8.unk_0 = -1U;
        }
    } else if ((lbl_3_bss_F0.unk_0 & 0x04000000) && ((s16) (*(s16 *)((u8 *)(&lbl_1_bss_96A) + 0)) != 0x5F)) {
        fn_3_5A50();
        if ((s32) lbl_3_data_B8.unk_0 != -1) {
            fn_1_435C(lbl_3_bss_20850.unk_0);
            fn_1_426C(lbl_3_data_B8.unk_0);
            lbl_3_data_B8.unk_0 = -1U;
        }
    } else if (lbl_3_bss_F0.unk_0 & 0x01000000) {
        fn_1_48140(0xA3);
        if ((s32) lbl_3_data_B8.unk_0 != -1) {
            fn_1_435C(lbl_3_bss_20850.unk_0);
            fn_1_426C(lbl_3_data_B8.unk_0);
            lbl_3_data_B8.unk_0 = -1U;
        }
    }
    lbl_3_bss_F0.unk_0 &= 0x02FFFFFF;
}
/* fzgx:end fn_3_3438 */

/* fzgx:begin fn_3_368C */
struct fn_3_368C_lbl_3_data_0 {
    u8 pad_0[0xB8];
    u32 unk_B8;
};
struct fn_3_368C_lbl_3_bss_0 {
    u8 pad_0[0xF0];
    u32 unk_F0;
    u8 pad_F4[0x2C];
    u32 unk_120;
};

extern struct fn_3_368C_lbl_3_bss_0 lbl_3_bss_0;
extern struct fn_3_368C_lbl_3_data_0 lbl_3_data_0;
extern u32 fn_1_130EE8(u32, u32);
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_47F74(u32);
extern u32 fn_3_4218(void);
extern u32 fn_3_4C58(void);
extern u32 fn_3_7CF8(void);
extern u32 fn_3_9800(void);
extern void fn_3_255DC(void);
extern void fn_3_273F4(void);
extern void fn_3_29508(void);
extern void fn_3_29C94(void);
extern void fn_3_2AAF4(void);

u32 fn_3_368C(void) {
    struct fn_3_368C_lbl_3_data_0 *p_lbl_3_data_0;
    struct fn_3_368C_lbl_3_bss_0 *p_lbl_3_bss_0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
    p_lbl_3_bss_0 = (struct fn_3_368C_lbl_3_bss_0 *)&lbl_3_bss_0;
    p_lbl_3_data_0 = &lbl_3_data_0;
    v0 = ((u32)p_lbl_3_bss_0 + 0x20000);
    *(u8 *)((u8 *)v0 + 17316) = 0;
    v1 = *(u32 *)((u8 *)v0 + 2124);
    *(u32 *)((u8 *)v0 + 17312) = 0;
    fn_1_130EE8(v1, *(u32 *)((u8 *)v0 + 2128));
    v2 = p_lbl_3_bss_0->unk_F0;
    p_lbl_3_bss_0->unk_120 = -1;
    v3 = v2;
    if ((v2 & 0x40000000) != 0 && (s32)p_lbl_3_data_0->unk_B8 == -1) {
    t1 = fn_3_7CF8();
    v3 = t1;
    v3 = (u32)((u8 *)(u32)p_lbl_3_data_0 + 5736);
    t2 = fn_1_3F8C((u32)v3, (u32)fn_3_255DC, 0, 8);
    v3 = t2;
    p_lbl_3_data_0->unk_B8 = v3;
    } else {
    if ((v3 & 0x20000000) != 0 && (s32)p_lbl_3_data_0->unk_B8 == -1) {
    t3 = fn_3_9800();
    v3 = t3;
    v3 = (u32)((u8 *)(u32)p_lbl_3_data_0 + 5752);
    t4 = fn_1_3F8C((u32)v3, (u32)fn_3_273F4, 0, 8);
    v3 = t4;
    p_lbl_3_data_0->unk_B8 = v3;
    } else {
    if ((v3 & 0x10000000) != 0 && (s32)p_lbl_3_data_0->unk_B8 == -1) {
    t5 = fn_3_4218();
    v3 = t5;
    v3 = (u32)((u8 *)(u32)p_lbl_3_data_0 + 5768);
    t6 = fn_1_3F8C((u32)v3, (u32)fn_3_29508, 0, 8);
    v3 = t6;
    p_lbl_3_data_0->unk_B8 = v3;
    } else {
    if ((v3 & 0x8000000) == 0 || (s32)p_lbl_3_data_0->unk_B8 != -1) {
    if ((v3 & 0x4000000) != 0 && (s32)p_lbl_3_data_0->unk_B8 == -1) {
    t7 = fn_3_4C58();
    v3 = t7;
    v3 = (u32)((u8 *)(u32)p_lbl_3_data_0 + 5784);
    t8 = fn_1_3F8C((u32)v3, (u32)fn_3_29C94, 0, 8);
    v3 = t8;
    p_lbl_3_data_0->unk_B8 = v3;
    } else {
    if ((v3 & 0x1000000) != 0 && (s32)p_lbl_3_data_0->unk_B8 == -1) {
    v3 = 163;
    t9 = fn_1_47F74(v3);
    v3 = t9;
    v3 = (u32)((u8 *)(u32)p_lbl_3_data_0 + 5800);
    t10 = fn_1_3F8C((u32)v3, (u32)fn_3_2AAF4, 0, 8);
    v3 = t10;
    p_lbl_3_data_0->unk_B8 = v3;
    }
    }
    }
    }
    }
    }
    return v3;
}
/* fzgx:end fn_3_368C */

/* fzgx:begin fn_3_381C pool */
typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    u8 pad_C[0xE4];
    u32 unk_F0;
    u8 pad_F4[0x20];
    u32 unk_114;
    u8 pad_118[8];
    s32 unk_120;
} ObjA;

typedef struct {
    u8 pad_0[0x850];
    void *unk_850;
    u8 pad_854[0x3B28];
    u8 unk_437C;
    u8 pad_437D[0x23];
    u32 unk_43A0;
    u8 unk_43A4;
    u8 pad_43A5[3];
    u32 unk_43A8;
} ObjB;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 fzgx_obj_lbl_3_bss_0;
s32 lbl_3_bss_0__fzgx_offset_4;
s32 fzgx_obj_lbl_3_bss_8;
u32 fzgx_obj_lbl_3_bss_C[3];
u32 fzgx_obj_lbl_3_bss_18[2];
u32 fzgx_obj_lbl_3_bss_20[52];
u32 fzgx_obj_lbl_3_bss_F0[12];
s32 fzgx_obj_lbl_3_bss_120;
u32 lbl_3_bss_120__fzgx_offset_4[7];
u32 fzgx_obj_lbl_3_bss_140[33217];
u16 fzgx_obj_lbl_3_bss_20844;
u32 fzgx_obj_lbl_3_bss_20848;
u32 fzgx_obj_lbl_3_bss_2084C;
u32 fzgx_obj_lbl_3_bss_20850;
u32 fzgx_obj_lbl_3_bss_20854[3];
u32 fzgx_obj_lbl_3_bss_20860[1088];
u32 fzgx_obj_lbl_3_bss_21960[2592];
u32 fzgx_obj_lbl_3_bss_241E0[100];
u32 fzgx_obj_lbl_3_bss_24370[3];
u8 fzgx_obj_lbl_3_bss_2437C;
u8 lbl_3_bss_2437C__fzgx_offset_1;
u8 lbl_3_bss_2437C__fzgx_offset_1__b1;
u8 lbl_3_bss_2437C__fzgx_offset_1__b2;
u8 lbl_3_bss_2437C__fzgx_offset_1__b3;
u8 lbl_3_bss_2437C__fzgx_offset_1__b4;
u8 lbl_3_bss_2437C__fzgx_offset_1__b5;
u8 lbl_3_bss_2437C__fzgx_offset_1__b6;
u8 lbl_3_bss_2437C__fzgx_offset_1__b7;
u8 lbl_3_bss_2437C__fzgx_offset_1__b8;
u8 lbl_3_bss_2437C__fzgx_offset_1__b9;
u8 lbl_3_bss_2437C__fzgx_offset_1__b10;
u8 lbl_3_bss_2437C__fzgx_offset_1__b11;
u8 lbl_3_bss_2437C__fzgx_offset_1__b12;
u8 lbl_3_bss_2437C__fzgx_offset_1__b13;
u8 lbl_3_bss_2437C__fzgx_offset_1__b14;
u8 lbl_3_bss_2437C__fzgx_offset_1__b15;
u8 lbl_3_bss_2437C__fzgx_offset_1__b16;
u8 lbl_3_bss_2437C__fzgx_offset_1__b17;
u8 lbl_3_bss_2437C__fzgx_offset_1__b18;
u8 lbl_3_bss_2437C__fzgx_offset_1__b19;
u8 lbl_3_bss_2437C__fzgx_offset_1__b20;
u8 lbl_3_bss_2437C__fzgx_offset_1__b21;
u8 lbl_3_bss_2437C__fzgx_offset_1__b22;
u8 lbl_3_bss_2437C__fzgx_offset_1__b23;
u8 lbl_3_bss_2437C__fzgx_offset_1__b24;
u8 lbl_3_bss_2437C__fzgx_offset_1__b25;
u8 lbl_3_bss_2437C__fzgx_offset_1__b26;
u8 lbl_3_bss_2437C__fzgx_offset_1__b27;
u8 lbl_3_bss_2437C__fzgx_offset_1__b28;
u8 lbl_3_bss_2437C__fzgx_offset_1__b29;
u8 lbl_3_bss_2437C__fzgx_offset_1__b30;
u8 lbl_3_bss_2437C__fzgx_offset_1__b31;
u8 lbl_3_bss_2437C__fzgx_offset_1__b32;
u8 lbl_3_bss_2437C__fzgx_offset_1__b33;
u8 lbl_3_bss_2437C__fzgx_offset_1__b34;
u32 lbl_3_bss_2437C__fzgx_offset_24;
u8 lbl_3_bss_2437C__fzgx_offset_28;
u8 lbl_3_bss_2437C__fzgx_offset_29;
u8 lbl_3_bss_2437C__fzgx_offset_29__b1;
u8 lbl_3_bss_2437C__fzgx_offset_29__b2;
u32 fzgx_obj_lbl_3_bss_243A8[6];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_3_bss_0;
    s = lbl_3_bss_0__fzgx_offset_4;
    s = fzgx_obj_lbl_3_bss_8;
    s = fzgx_obj_lbl_3_bss_C[0];
    s = fzgx_obj_lbl_3_bss_18[0];
    s = fzgx_obj_lbl_3_bss_20[0];
    s = fzgx_obj_lbl_3_bss_F0[0];
    s = fzgx_obj_lbl_3_bss_120;
    s = lbl_3_bss_120__fzgx_offset_4[0];
    s = fzgx_obj_lbl_3_bss_140[0];
    s = fzgx_obj_lbl_3_bss_20844;
    s = fzgx_obj_lbl_3_bss_20848;
    s = fzgx_obj_lbl_3_bss_2084C;
    s = fzgx_obj_lbl_3_bss_20850;
    s = fzgx_obj_lbl_3_bss_20854[0];
    s = fzgx_obj_lbl_3_bss_20860[0];
    s = fzgx_obj_lbl_3_bss_21960[0];
    s = fzgx_obj_lbl_3_bss_241E0[0];
    s = fzgx_obj_lbl_3_bss_24370[0];
    s = fzgx_obj_lbl_3_bss_2437C;
    s = lbl_3_bss_2437C__fzgx_offset_1;
    s = lbl_3_bss_2437C__fzgx_offset_1__b1;
    s = lbl_3_bss_2437C__fzgx_offset_1__b2;
    s = lbl_3_bss_2437C__fzgx_offset_1__b3;
    s = lbl_3_bss_2437C__fzgx_offset_1__b4;
    s = lbl_3_bss_2437C__fzgx_offset_1__b5;
    s = lbl_3_bss_2437C__fzgx_offset_1__b6;
    s = lbl_3_bss_2437C__fzgx_offset_1__b7;
    s = lbl_3_bss_2437C__fzgx_offset_1__b8;
    s = lbl_3_bss_2437C__fzgx_offset_1__b9;
    s = lbl_3_bss_2437C__fzgx_offset_1__b10;
    s = lbl_3_bss_2437C__fzgx_offset_1__b11;
    s = lbl_3_bss_2437C__fzgx_offset_1__b12;
    s = lbl_3_bss_2437C__fzgx_offset_1__b13;
    s = lbl_3_bss_2437C__fzgx_offset_1__b14;
    s = lbl_3_bss_2437C__fzgx_offset_1__b15;
    s = lbl_3_bss_2437C__fzgx_offset_1__b16;
    s = lbl_3_bss_2437C__fzgx_offset_1__b17;
    s = lbl_3_bss_2437C__fzgx_offset_1__b18;
    s = lbl_3_bss_2437C__fzgx_offset_1__b19;
    s = lbl_3_bss_2437C__fzgx_offset_1__b20;
    s = lbl_3_bss_2437C__fzgx_offset_1__b21;
    s = lbl_3_bss_2437C__fzgx_offset_1__b22;
    s = lbl_3_bss_2437C__fzgx_offset_1__b23;
    s = lbl_3_bss_2437C__fzgx_offset_1__b24;
    s = lbl_3_bss_2437C__fzgx_offset_1__b25;
    s = lbl_3_bss_2437C__fzgx_offset_1__b26;
    s = lbl_3_bss_2437C__fzgx_offset_1__b27;
    s = lbl_3_bss_2437C__fzgx_offset_1__b28;
    s = lbl_3_bss_2437C__fzgx_offset_1__b29;
    s = lbl_3_bss_2437C__fzgx_offset_1__b30;
    s = lbl_3_bss_2437C__fzgx_offset_1__b31;
    s = lbl_3_bss_2437C__fzgx_offset_1__b32;
    s = lbl_3_bss_2437C__fzgx_offset_1__b33;
    s = lbl_3_bss_2437C__fzgx_offset_1__b34;
    s = lbl_3_bss_2437C__fzgx_offset_24;
    s = lbl_3_bss_2437C__fzgx_offset_28;
    s = lbl_3_bss_2437C__fzgx_offset_29;
    s = lbl_3_bss_2437C__fzgx_offset_29__b1;
    s = lbl_3_bss_2437C__fzgx_offset_29__b2;
    s = fzgx_obj_lbl_3_bss_243A8[0];
}
#pragma section code_type ".text"

extern u32 lbl_3_data_B4;
extern u16 lbl_1_bss_96A;

extern s32 fn_1_1310E0(void);
extern int fn_1_4C10(void);
extern void fn_1_131050(void *, u32);
extern void fn_1_1310B8(void);
extern void fn_1_4A00(s32, u8, void *);

void fn_3_381C(void) {
    s32 res;

    if (fn_1_1310E0() != 0) {
        return;
    }
    if (fzgx_obj_lbl_3_bss_120 == -1) {
        fn_1_4C10();
    }
    if ((fzgx_obj_lbl_3_bss_F0[9] & 0x80000000) && !(fzgx_obj_lbl_3_bss_F0[9] & 0x1) && !(fzgx_obj_lbl_3_bss_F0[0] & 0x2)) {
        res = 1;
    } else if (fn_1_4C10() != 0) {
        res = 1;
    } else {
        res = 0;
    }
    if (res != 0) {
        return;
    }
    if (fzgx_obj_lbl_3_bss_120 != -1) {
        lbl_1_bss_96A = (u16)fzgx_obj_lbl_3_bss_120;
        fzgx_obj_lbl_3_bss_120 = -1;
        return;
    }
    if (fzgx_obj_lbl_3_bss_0 != 0) {
        lbl_3_bss_2437C__fzgx_offset_24 = 1;
        fzgx_obj_lbl_3_bss_0 = 0;
        fn_1_131050(fzgx_obj_lbl_3_bss_140, fzgx_obj_lbl_3_bss_2437C);
        return;
    }
    if (lbl_3_bss_0__fzgx_offset_4 != 0) {
        lbl_3_bss_2437C__fzgx_offset_24 = 1;
        lbl_3_bss_0__fzgx_offset_4 = 0;
        fn_1_131050(fzgx_obj_lbl_3_bss_140, 4);
        return;
    }
    if (fzgx_obj_lbl_3_bss_8 != 0) {
        lbl_3_bss_2437C__fzgx_offset_28 = 1;
        lbl_3_bss_2437C__fzgx_offset_24 = 1;
        fzgx_obj_lbl_3_bss_8 = 0;
        fn_1_1310B8();
        return;
    }
    if (fn_1_1310E0() != 0) {
        return;
    }
    fzgx_obj_lbl_3_bss_120 = 0x5f;
    {
        u32 *p = &lbl_3_data_B4;
        if ((s32)*p != -1) {
            fzgx_obj_lbl_3_bss_120 = *p;
            *p = -1;
        }
    }
    if ((fzgx_obj_lbl_3_bss_120 == 0x5f && !(fzgx_obj_lbl_3_bss_F0[0] & 0x04000000)) || (fzgx_obj_lbl_3_bss_F0[0] & 0x01000000)) {
        fn_1_4A00(0, 0xf, (void *)fzgx_obj_lbl_3_bss_20850);
        fzgx_obj_lbl_3_bss_243A8[0] = 0;
    } else if (fzgx_obj_lbl_3_bss_120 == 0x5f && (fzgx_obj_lbl_3_bss_F0[0] & 0x04000000)) {
        fzgx_obj_lbl_3_bss_F0[0] |= 0x02000000;
    }
}
/* fzgx:end fn_3_381C */

/* fzgx:begin fn_3_39F0 pool */
#include "rel/customize/globals.h"

extern void fn_3_3438(void);
extern u32 fn_1_B7F08(void);
extern void fn_80008BA8(void *, void *, u32);
extern s32 fn_1_F7954(void);
extern void fn_1_131004(void);
struct Selection {
    u8 pad_0[8];
    s16 unk_8;
};
struct State {
    u8 pad_0[0x4374];
    void (*unk_4374)(u32);
    u32 unk_4378;
    u8 pad_437C[0x24];
    s32 unk_43A0;
    u8 unk_43A4;
    u8 pad_43A5[0x1B];
    u8 unk_43C0[1];
};
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 fzgx_obj_lbl_3_bss_0;
s32 lbl_3_bss_0__fzgx_offset_4;
u32 fzgx_obj_lbl_3_bss_8;
u32 fzgx_obj_lbl_3_bss_C[3];
u32 fzgx_obj_lbl_3_bss_18[2];
u32 fzgx_obj_lbl_3_bss_20[52];
u32 fzgx_obj_lbl_3_bss_F0[12];
s32 fzgx_obj_lbl_3_bss_120;
u32 lbl_3_bss_120__fzgx_offset_4[7];
u32 fzgx_obj_lbl_3_bss_140[33217];
u16 fzgx_obj_lbl_3_bss_20844;
u32 fzgx_obj_lbl_3_bss_20848;
u32 fzgx_obj_lbl_3_bss_2084C;
u32 fzgx_obj_lbl_3_bss_20850;
u32 fzgx_obj_lbl_3_bss_20854[3];
u32 fzgx_obj_lbl_3_bss_20860[1088];
u32 fzgx_obj_lbl_3_bss_21960[2592];
u32 fzgx_obj_lbl_3_bss_241E0[100];
u32 fzgx_obj_lbl_3_bss_24370;
u32 lbl_3_bss_24370__fzgx_offset_4;
u32 lbl_3_bss_24370__fzgx_offset_8;
u8 fzgx_obj_lbl_3_bss_2437C;
u8 lbl_3_bss_2437C__fzgx_offset_1;
u8 lbl_3_bss_2437C__fzgx_offset_1__b1;
u8 lbl_3_bss_2437C__fzgx_offset_1__b2;
u8 lbl_3_bss_2437C__fzgx_offset_1__b3;
u8 lbl_3_bss_2437C__fzgx_offset_1__b4;
u8 lbl_3_bss_2437C__fzgx_offset_1__b5;
u8 lbl_3_bss_2437C__fzgx_offset_1__b6;
u8 lbl_3_bss_2437C__fzgx_offset_1__b7;
u8 lbl_3_bss_2437C__fzgx_offset_1__b8;
u8 lbl_3_bss_2437C__fzgx_offset_1__b9;
u8 lbl_3_bss_2437C__fzgx_offset_1__b10;
u8 lbl_3_bss_2437C__fzgx_offset_1__b11;
u8 lbl_3_bss_2437C__fzgx_offset_1__b12;
u8 lbl_3_bss_2437C__fzgx_offset_1__b13;
u8 lbl_3_bss_2437C__fzgx_offset_1__b14;
u8 lbl_3_bss_2437C__fzgx_offset_1__b15;
u8 lbl_3_bss_2437C__fzgx_offset_1__b16;
u8 lbl_3_bss_2437C__fzgx_offset_1__b17;
u8 lbl_3_bss_2437C__fzgx_offset_1__b18;
u8 lbl_3_bss_2437C__fzgx_offset_1__b19;
u8 lbl_3_bss_2437C__fzgx_offset_1__b20;
u8 lbl_3_bss_2437C__fzgx_offset_1__b21;
u8 lbl_3_bss_2437C__fzgx_offset_1__b22;
u8 lbl_3_bss_2437C__fzgx_offset_1__b23;
u8 lbl_3_bss_2437C__fzgx_offset_1__b24;
u8 lbl_3_bss_2437C__fzgx_offset_1__b25;
u8 lbl_3_bss_2437C__fzgx_offset_1__b26;
u8 lbl_3_bss_2437C__fzgx_offset_1__b27;
u8 lbl_3_bss_2437C__fzgx_offset_1__b28;
u8 lbl_3_bss_2437C__fzgx_offset_1__b29;
u8 lbl_3_bss_2437C__fzgx_offset_1__b30;
u8 lbl_3_bss_2437C__fzgx_offset_1__b31;
u8 lbl_3_bss_2437C__fzgx_offset_1__b32;
u8 lbl_3_bss_2437C__fzgx_offset_1__b33;
u8 lbl_3_bss_2437C__fzgx_offset_1__b34;
s32 lbl_3_bss_2437C__fzgx_offset_24;
u8 lbl_3_bss_2437C__fzgx_offset_28;
u8 lbl_3_bss_2437C__fzgx_offset_29;
u8 lbl_3_bss_2437C__fzgx_offset_29__b1;
u8 lbl_3_bss_2437C__fzgx_offset_29__b2;
u32 fzgx_obj_lbl_3_bss_243A8[6];
u32 fzgx_obj_lbl_3_bss_243C0[8304];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_3_bss_0;
    s = lbl_3_bss_0__fzgx_offset_4;
    s = fzgx_obj_lbl_3_bss_8;
    s = fzgx_obj_lbl_3_bss_C[0];
    s = fzgx_obj_lbl_3_bss_18[0];
    s = fzgx_obj_lbl_3_bss_20[0];
    s = fzgx_obj_lbl_3_bss_F0[0];
    s = fzgx_obj_lbl_3_bss_120;
    s = lbl_3_bss_120__fzgx_offset_4[0];
    s = fzgx_obj_lbl_3_bss_140[0];
    s = fzgx_obj_lbl_3_bss_20844;
    s = fzgx_obj_lbl_3_bss_20848;
    s = fzgx_obj_lbl_3_bss_2084C;
    s = fzgx_obj_lbl_3_bss_20850;
    s = fzgx_obj_lbl_3_bss_20854[0];
    s = fzgx_obj_lbl_3_bss_20860[0];
    s = fzgx_obj_lbl_3_bss_21960[0];
    s = fzgx_obj_lbl_3_bss_241E0[0];
    s = fzgx_obj_lbl_3_bss_24370;
    s = lbl_3_bss_24370__fzgx_offset_4;
    s = lbl_3_bss_24370__fzgx_offset_8;
    s = fzgx_obj_lbl_3_bss_2437C;
    s = lbl_3_bss_2437C__fzgx_offset_1;
    s = lbl_3_bss_2437C__fzgx_offset_1__b1;
    s = lbl_3_bss_2437C__fzgx_offset_1__b2;
    s = lbl_3_bss_2437C__fzgx_offset_1__b3;
    s = lbl_3_bss_2437C__fzgx_offset_1__b4;
    s = lbl_3_bss_2437C__fzgx_offset_1__b5;
    s = lbl_3_bss_2437C__fzgx_offset_1__b6;
    s = lbl_3_bss_2437C__fzgx_offset_1__b7;
    s = lbl_3_bss_2437C__fzgx_offset_1__b8;
    s = lbl_3_bss_2437C__fzgx_offset_1__b9;
    s = lbl_3_bss_2437C__fzgx_offset_1__b10;
    s = lbl_3_bss_2437C__fzgx_offset_1__b11;
    s = lbl_3_bss_2437C__fzgx_offset_1__b12;
    s = lbl_3_bss_2437C__fzgx_offset_1__b13;
    s = lbl_3_bss_2437C__fzgx_offset_1__b14;
    s = lbl_3_bss_2437C__fzgx_offset_1__b15;
    s = lbl_3_bss_2437C__fzgx_offset_1__b16;
    s = lbl_3_bss_2437C__fzgx_offset_1__b17;
    s = lbl_3_bss_2437C__fzgx_offset_1__b18;
    s = lbl_3_bss_2437C__fzgx_offset_1__b19;
    s = lbl_3_bss_2437C__fzgx_offset_1__b20;
    s = lbl_3_bss_2437C__fzgx_offset_1__b21;
    s = lbl_3_bss_2437C__fzgx_offset_1__b22;
    s = lbl_3_bss_2437C__fzgx_offset_1__b23;
    s = lbl_3_bss_2437C__fzgx_offset_1__b24;
    s = lbl_3_bss_2437C__fzgx_offset_1__b25;
    s = lbl_3_bss_2437C__fzgx_offset_1__b26;
    s = lbl_3_bss_2437C__fzgx_offset_1__b27;
    s = lbl_3_bss_2437C__fzgx_offset_1__b28;
    s = lbl_3_bss_2437C__fzgx_offset_1__b29;
    s = lbl_3_bss_2437C__fzgx_offset_1__b30;
    s = lbl_3_bss_2437C__fzgx_offset_1__b31;
    s = lbl_3_bss_2437C__fzgx_offset_1__b32;
    s = lbl_3_bss_2437C__fzgx_offset_1__b33;
    s = lbl_3_bss_2437C__fzgx_offset_1__b34;
    s = lbl_3_bss_2437C__fzgx_offset_24;
    s = lbl_3_bss_2437C__fzgx_offset_28;
    s = lbl_3_bss_2437C__fzgx_offset_29;
    s = lbl_3_bss_2437C__fzgx_offset_29__b1;
    s = lbl_3_bss_2437C__fzgx_offset_29__b2;
    s = fzgx_obj_lbl_3_bss_243A8[0];
    s = fzgx_obj_lbl_3_bss_243C0[0];
}
#pragma section code_type ".text"

#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_3_39F0(void) {
    void * lab_t0;
    if ((s32)fn_1_B7F08() == 1 && lbl_3_bss_2437C__fzgx_offset_28 == 0 || lbl_3_bss_2437C__fzgx_offset_24 == 0) {
        lab_t0 = (u8 *)fzgx_obj_lbl_3_bss_140 + ((struct Selection *)fzgx_obj_lbl_3_bss_F0)->unk_8 * 0x81C0;
        fn_80008BA8(lab_t0, fzgx_obj_lbl_3_bss_243C0, 0x81C0);
    } else if ((s32)fn_1_B7F08() != 0 && lbl_3_bss_2437C__fzgx_offset_28 != 0) {
        fn_1_F7954();
    } else {
        if (lbl_3_bss_24370__fzgx_offset_4 != 0) {
            ((void (*)(u32))lbl_3_bss_24370__fzgx_offset_4)(lbl_3_bss_24370__fzgx_offset_8);
            lbl_3_bss_24370__fzgx_offset_4 = 0;
        }
        fn_80008BA8(fzgx_obj_lbl_3_bss_243C0, (u8 *)fzgx_obj_lbl_3_bss_140 + ((struct Selection *)fzgx_obj_lbl_3_bss_F0)->unk_8 * 0x81C0, 0x81C0);
    }
    fn_1_131004();
    fn_3_3438();
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset
/* fzgx:end fn_3_39F0 */

/* fzgx:begin fn_3_3E58 */
extern struct fn_3_3E58_lbl_3_bss_20850 lbl_3_bss_20850;
extern struct fn_3_3E58_lbl_3_data_0 lbl_3_data_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_47F74(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_1_A176C(u32, u32);
extern u32 lbl_1_bss_6EAD0;
extern u32 lbl_3_bss_120;
extern u32 lbl_3_bss_243A8;
extern void fn_3_2C164(void);

struct fn_3_3E58_lbl_3_data_0 {
    u8 pad_0[0xB8];
    u32 unk_B8;
    u8 pad_BC[0x8];
    s16 unk_C4;
};
struct fn_3_3E58_lbl_3_bss_20850 {
    u32 unk_0;
};

u32 fn_3_3E58(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    struct fn_3_3E58_lbl_3_data_0 *p_lbl_3_data_0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t1, t2, t3, t4, t5;
    p_lbl_3_data_0 = (struct fn_3_3E58_lbl_3_data_0 *)&lbl_3_data_0;
    fn_1_4A00(1, 15, lbl_3_bss_20850.unk_0);
    lbl_3_bss_243A8 = 0;
    p_lbl_3_data_0->unk_C4 = -1;
    t1 = fn_1_435C(lbl_3_bss_20850.unk_0);
    v0 = arg1;
    v1 = t1;
    v2 = arg2;
    v3 = arg3;
    if ((s32)p_lbl_3_data_0->unk_B8 == -1) {
    v1 = (u32)((u8 *)p_lbl_3_data_0 + 6144);
    v0 = (u32)fn_3_2C164;
    v2 = 0;
    v3 = 8;
    t2 = fn_1_3F8C((u32)v1, (u32)v0, v2, v3);
    v1 = t2;
    p_lbl_3_data_0->unk_B8 = v1;
    }
    v0 = 46;
    v1 = (u32)&lbl_1_bss_6EAD0;
    v1 = *(u32 *)((u8 *)v1 + 0);
    v1 = *(u32 *)((u8 *)v1 + 0);
    t3 = fn_1_A176C(v1, v0);
    v1 = t3;
    v0 = (u32)&lbl_3_bss_120;
    v1 = 133;
    *(u32 *)((u8 *)v0 + 0) = -1;
    t4 = fn_1_47F74(v1);
    v1 = t4;
    v1 = 161;
    t5 = fn_1_47F74(v1);
    v1 = t5;
    return v1;
}
/* fzgx:end fn_3_3E58 */

/* fzgx:begin fn_3_3F20 */
#include "rel/customize/globals.h"

struct fn_3_3F20_entry {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
};
extern s32 lbl_3_bss_120;
extern u16 lbl_1_bss_96A;
extern struct fn_3_3F20_entry lbl_1_bss_9F8[1];
extern u32 lbl_3_bss_243A8[6];
extern u32 lbl_801A66A8;
extern s32 fn_1_4C10(void);
extern void fn_1_4A00(s32, s32, u32);
extern void fn_1_A2D84(u32);

void fn_3_3F20(void) {
    u32 flags;
    s32 ready;
    struct { s16 value; } err;
    struct { s16 value; } errCount;
    s16 idx;
    s32 val;
    Obj_3_bss_F0 *pObj;
    /* retail re-reads unk_8 through a pointer (lhzu then lhz), so it is volatile */
    volatile u16 *buttons;

    if (lbl_3_bss_120 == -1) {
        fn_1_4C10();
    }
    flags = lbl_3_bss_F0.unk_24;
    if ((flags & (~((u32)-1 >> 1))) != 0 &&
        (flags & 1) == 0 &&
        (*(u32 *)&lbl_3_bss_F0 & 2) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }
    if (!ready) {
        if (lbl_3_bss_120 != -1) {
            s32 value = lbl_3_bss_120;
            lbl_3_bss_120 = -1;
            lbl_1_bss_96A = (u16)value;
        } else {
            err.value = 0;
            errCount.value = 0;
            idx = lbl_3_bss_F0.unk_6;
            if ((lbl_1_bss_9F8[idx].unk_10 & 1) != 0 ||
                (lbl_1_bss_9F8[idx].unk_12 & 1) != 0) {
                errCount.value--;
                fn_1_A2D84(0xA9010000);
                lbl_801A66A8 = 0;
            }
            if (((lbl_1_bss_9F8[idx].unk_10 >> 1) & 1) != 0 ||
                ((lbl_1_bss_9F8[idx].unk_12 >> 1) & 1) != 0) {
                errCount.value++;
                fn_1_A2D84(0xA9010000);
                lbl_801A66A8 = 0;
            }
            pObj = &lbl_3_bss_F0;
            val = pObj->unk_4 + errCount.value;
            pObj->unk_4 = val > 2 ? 0 : val < 0 ? 2 : val;
            buttons = &lbl_1_bss_9F8[idx].unk_8;
            if (((*buttons >> 8) & 1) != 0) {
                err.value = 1;
                fn_1_A2D84(0xA9010100);
            } else if (((*buttons >> 9) & 1) != 0) {
                fn_1_A2D84(0xA9010200);
                err.value = -1;
            }
            if (err.value) {
                fn_1_4A00(0, 15, lbl_3_bss_20850);
                lbl_3_bss_243A8[0] = 0;
            }
            if (err.value == -1) {
                lbl_3_bss_120 = 0x5e;
            } else if (err.value == 1) {
                switch (pObj->unk_4) {
                case 0:
                    lbl_3_bss_120 = 0x5e;
                    break;
                case 1:
                    lbl_3_bss_120 = 0x64;
                    break;
                case 2:
                    lbl_3_bss_120 = 0x6e;
                    break;
                default:
                    lbl_3_bss_120 = 0x5e;
                    break;
                }
            }
        }
    }
}
/* fzgx:end fn_3_3F20 */

/* fzgx:begin fn_3_41B0 */
extern s32 lbl_3_data_B8;
extern s32 lbl_3_bss_20850;
extern void fn_1_435C(s32);
extern void fn_1_426C(s32);
extern void fn_1_48140(int);

void fn_3_41B0(void) {
    if (lbl_3_data_B8 != -1) {
        fn_1_435C(lbl_3_bss_20850);
        fn_1_426C(lbl_3_data_B8);
        lbl_3_data_B8 = -1;
    }
    fn_1_48140(0x85);
    fn_1_48140(0xa1);
}
/* fzgx:end fn_3_41B0 */

/* fzgx:begin fn_3_4218 */
extern void fn_3_5F28(void);
extern void fn_1_47F74(int);

void fn_3_4218(void) {
    fn_3_5F28();
    fn_1_47F74(0x4a);
    fn_1_47F74(0x54);
    fn_1_47F74(0x38);
    fn_1_47F74(0x3e);
    fn_1_47F74(0x37);
    fn_1_47F74(0x55);
    fn_1_47F74(0x30);
    fn_1_47F74(0x35);
    fn_1_47F74(0x3a);
    fn_1_47F74(0x40);
    fn_1_47F74(0x44);
    fn_1_47F74(0x50);
    fn_1_47F74(0x33);
    fn_1_47F74(0x2e);
    fn_1_47F74(0x31);
    fn_1_47F74(0x4f);
    fn_1_47F74(0x39);
    fn_1_47F74(0x3d);
    fn_1_47F74(0x4c);
    fn_1_47F74(0x3f);
    fn_1_47F74(0x48);
    fn_1_47F74(0x52);
    fn_1_47F74(0x45);
    fn_1_47F74(0x53);
    fn_1_47F74(0x3c);
    fn_1_47F74(0x56);
    fn_1_47F74(0x43);
    fn_1_47F74(0x42);
    fn_1_47F74(0x32);
    fn_1_47F74(0x2f);
    fn_1_47F74(0x34);
    fn_1_47F74(0x36);
    fn_1_47F74(0x4d);
    fn_1_47F74(0x46);
    fn_1_47F74(0x41);
    fn_1_47F74(0x51);
    fn_1_47F74(0x4e);
    fn_1_47F74(0x47);
    fn_1_47F74(0x3b);
    fn_1_47F74(0x4b);
    fn_1_47F74(0x49);
}
/* fzgx:end fn_3_4218 */

/* fzgx:begin fn_3_4380 pool */
extern u8 lbl_3_bss_140;
extern struct fn_3_4380_lbl_3_data_0 lbl_3_data_0;

struct fn_3_4380_lbl_3_data_0 {
    u8 pad_0[0xB8];
    s32 unk_B8;
    u8 pad_BC[0x8];
    s16 unk_C4;
};
struct fn_3_4380_lbl_1_bss_8B3A0 {
    u8 pad_0[0x9E];
    u8 unk_9E;
};
typedef struct {
    s16 key;
    u16 pad;
    u32 mask;
} Sig_fn_1_152970_Fn152970Entry;
extern s16 lbl_1_bss_966;
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern s32 fn_8006FDEC(void);
extern struct fn_3_4380_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern u32 fn_1_152208(void *, u32, void *, u32, u32);
extern u32 lbl_3_bss_2C584[98];
extern void fn_1_4A00(s32, u8, void *);
extern void fn_3_29508(void);
extern void fn_3_4218(void);
extern void fn_3_7A08(s16 *, s16 *, int);
extern s32 fn_1_152970(s16 *, s16 *, s16, u32, Sig_fn_1_152970_Fn152970Entry *, s16, s16);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_3_bss_0[2];
u32 lbl_3_bss_8;
u32 lbl_3_bss_C[3];
u32 fzgx_obj_lbl_3_bss_18[2];
s16 fzgx_obj_lbl_3_bss_20[0x68];
u8 fzgx_obj_lbl_3_bss_F0;
u8 lbl_3_bss_F0_fill_F1;
u16 lbl_3_bss_F0_fill_F2;
u32 lbl_3_bss_F0_fill_F4[11];
s32 lbl_3_bss_120;
u32 lbl_3_bss_120_fill_124[7];
u32 lbl_3_bss_140_fill_140[32688];
u8 lbl_3_bss_140_1FEC0;
u8 lbl_3_bss_140_fill_20001;
u16 lbl_3_bss_140_fill_20002;
u32 lbl_3_bss_140_fill_20004[528];
u16 lbl_3_bss_20844;
u16 lbl_3_bss_20844_fill_20846;
u32 lbl_3_bss_20848;
u32 lbl_3_bss_2084C;
u32 lbl_3_bss_20850;
u32 lbl_3_bss_20854[3];
u32 lbl_3_bss_20860[0x440];
u8 lbl_3_bss_21960[0x2880];
f32 lbl_3_bss_241E0[100];
u32 lbl_3_bss_24370[3];
u8 lbl_3_bss_2437C[0x2C];
u32 lbl_3_bss_243A8;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_0;
    s = *(u8 *)&lbl_3_bss_8;
    s = *(u8 *)&lbl_3_bss_C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_F0;
    s = *(u8 *)&lbl_3_bss_F0_fill_F1;
    s = *(u8 *)&lbl_3_bss_F0_fill_F2;
    s = *(u8 *)&lbl_3_bss_F0_fill_F4;
    s = *(u8 *)&lbl_3_bss_120;
    s = *(u8 *)&lbl_3_bss_120_fill_124;
    s = *(u8 *)&lbl_3_bss_140_fill_140;
    s = *(u8 *)&lbl_3_bss_140_1FEC0;
    s = *(u8 *)&lbl_3_bss_140_fill_20001;
    s = *(u8 *)&lbl_3_bss_140_fill_20002;
    s = *(u8 *)&lbl_3_bss_140_fill_20004;
    s = *(u8 *)&lbl_3_bss_20844;
    s = *(u8 *)&lbl_3_bss_20844_fill_20846;
    s = *(u8 *)&lbl_3_bss_20848;
    s = *(u8 *)&lbl_3_bss_2084C;
    s = *(u8 *)&lbl_3_bss_20850;
    s = *(u8 *)&lbl_3_bss_20854;
    s = *(u8 *)&lbl_3_bss_20860;
    s = *(u8 *)&lbl_3_bss_21960;
    s = *(u8 *)&lbl_3_bss_241E0;
    s = *(u8 *)&lbl_3_bss_24370;
    s = *(u8 *)&lbl_3_bss_2437C;
    s = *(u8 *)&lbl_3_bss_243A8;
}
#pragma section code_type ".text"

void fn_3_4380(u32 arg0, u32 lab_unused0, u32 lab_unused1) {
    s32 v3;
    struct fn_3_4380_lbl_3_data_0 *p_lbl_3_data_0;
    s16 value, unused, lower, upper;
    s32 t2;
    s16 v1;
    s32 v2;
    p_lbl_3_data_0 = &lbl_3_data_0;
    v1 = *(s16 *)((u8 *)&fzgx_obj_lbl_3_bss_F0 + 6);
    if (lbl_1_bss_966 != 93) {
        fn_1_4A00(1, 15, (void *)lbl_3_bss_20850);
        lbl_3_bss_243A8 = 0;
        if (p_lbl_3_data_0->unk_B8 == -1) {
            fn_8006FDEC();
            t2 = fn_1_3F8C((u32)p_lbl_3_data_0 + 5768, (u32)fn_3_29508, 0, 8);
            p_lbl_3_data_0->unk_B8 = t2;
        }
        fn_3_4218();
        fzgx_obj_lbl_3_bss_20[0x62] = 0;
    }
    v3 = *(s16 *)((u8 *)&fzgx_obj_lbl_3_bss_F0 + 8) * 0x81C0;
    *(u32 *)((u8 *)&lbl_3_bss_140 + v3) |= 0x80000000;
    *(u32 *)((u8 *)&lbl_3_bss_140 + v3) &= 0xBFFFFFFF;
    fn_1_152208((u8 *)p_lbl_3_data_0 + 84, 42, lbl_3_bss_2C584, 7, 7);
    v2 = p_lbl_3_data_0->unk_C4;
    lbl_1_bss_8B3A0.unk_9E = v1;
    if (v2 == -1) {
        p_lbl_3_data_0->unk_C4 = 6;
    } else {
        do {
            fn_1_152970(&value, &unused, p_lbl_3_data_0->unk_C4, 0, (Sig_fn_1_152970_Fn152970Entry *)lbl_3_bss_2C584, 7, 7);
            fn_3_7A08(&lower, &upper, 3);
            if (value < lower || value > upper) {
                fzgx_obj_lbl_3_bss_20[0x62]--;
            }
        } while (value < lower || value > upper);
    }
    lbl_3_bss_120 = -1;
}
/* fzgx:end fn_3_4380 */

/* fzgx:begin fn_3_4538 */
#include "rel/customize/globals.h"

extern s16 lbl_3_data_C4;
extern u32 fn_1_152CB4(s16, s32, s32, void *, s16, s16);
extern u32 fn_1_8D5F0(s32);
extern s32 fn_1_F7BE4(s32);
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[6];
    volatile u16 unk_10; /* Volatile: retail rereads controller flags for each direction. */
    volatile u16 unk_12; /* Volatile: retail rereads alternate controller flags for each direction. */
} Controller;
extern Controller lbl_1_bss_9F8[];
extern u32 lbl_3_bss_2C584[98];
extern void fn_1_A2D84(u32);
extern s32 fn_1_152970(s16 *, s16 *, s16, u32, void *, s16, s16);
extern void fn_3_7A08(s16 *, s16 *, int);
extern void fn_3_BD00(u32, u32, u32, u32);
extern s16 lbl_3_bss_20[104];
extern u32 lbl_3_bss_243C0[8304];
extern s32 fn_3_837C(s16);

struct SaveRecord {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_6[0x819A];
    u8 machine;
    u8 pad_81A1[0x1F];
};
#pragma opt_common_subs on

s32 fn_3_4538(void) {
    Obj_3_bss_F0 *p_lbl_3_bss_F0;
    s32 v1;
    s32 result;
    s32 v7;
    s32 v9;
    s16 v2;
    s16 v0;
    s32 v4;
    s32 v3;
    s16 lo, hi, x, y;
    p_lbl_3_bss_F0 = (Obj_3_bss_F0 *)&lbl_3_bss_F0;
    v0 = lbl_3_data_C4;
    v1 = p_lbl_3_bss_F0->unk_6;
    v2 = p_lbl_3_bss_F0->unk_8;
    result = 0;
    v7 = 0;
    v9 = 0;
    v4 = 0;
    for (v3 = 0; (s16)v3 < 41; v3++) {
        if ((fn_1_8D5F0(v3) & 0x10000000) && fn_1_F7BE4(v3)) {
            v4 = 1;
            break;
        }
    }
    if (((lbl_1_bss_9F8[v1].unk_10 >> 3) & 1) || ((lbl_1_bss_9F8[v1].unk_12 >> 3) & 1)) v7 = -1;
    if (((lbl_1_bss_9F8[v1].unk_10 >> 2) & 1) || ((lbl_1_bss_9F8[v1].unk_12 >> 2) & 1)) v7++;
    if ((lbl_1_bss_9F8[v1].unk_10 & 1) || (lbl_1_bss_9F8[v1].unk_12 & 1)) v9 = -1;
    if (((lbl_1_bss_9F8[v1].unk_10 >> 1) & 1) || ((lbl_1_bss_9F8[v1].unk_12 >> 1) & 1)) v9++;
    if ((s16)v9 != 0 || (s16)v7 != 0) {
        s32 selected = fn_1_152CB4(lbl_3_data_C4, v7, v9, lbl_3_bss_2C584, 7, 7);
        *(u16 *)&lbl_3_data_C4 = selected;
        if (!v4) {
            selected = (s16)selected;
            if (((u16)(selected - 24) <= 2 || selected == 27) && (s16)v7 > 0 && v0 == selected)
                lbl_3_data_C4 = 30;
        } else {
            if ((s16)selected == 34 && (s16)v7 > 0 && v0 == (s16)selected)
                lbl_3_data_C4 = 40;
        }
    }
    if (v0 != lbl_3_data_C4) fn_1_A2D84(0xA9010000);
    fn_1_152970(&x, &y, lbl_3_data_C4, 0, lbl_3_bss_2C584, 7, 7);
    fn_3_7A08(&lo, &hi, 3);
    if (x < lo || x > hi) {
        fn_3_BD00(v7, 0, (s16)(v7 * 10), 0x800000);
        lbl_3_bss_20[98] -= v7;
    }
    if (fn_1_F7BE4(lbl_3_data_C4)) {
        s16 selection = lbl_3_data_C4;
        s32 offset = v2 * 0x81C0;
        *(u8 *)((u32)&lbl_3_bss_140 + 0x81A0 + offset) = selection;
        ((Obj_3_bss_140 *)((u8 *)&lbl_3_bss_140 + offset))->unk_5 = selection;
    } else {
        u8 selection = ((struct SaveRecord *)lbl_3_bss_243C0)->machine;
        s32 offset = v2 * 0x81C0;
        *(u8 *)((u32)&lbl_3_bss_140 + 0x81A0 + offset) = selection;
        ((Obj_3_bss_140 *)((u8 *)&lbl_3_bss_140 + offset))->unk_5 = selection;
    }
    if (fn_1_F7BE4(lbl_3_data_C4) && fn_3_837C(p_lbl_3_bss_F0->unk_8) == 1) {
        u16 *buttons = &lbl_1_bss_9F8[v1].unk_8;
        /* First controller read is independent of the subsequent tests. */
        if (((*(volatile u16 *)buttons >> 12) & 1) || ((*buttons >> 11) & 1)) {
            result = 12;
            fn_1_A2D84(0xA9010100);
        } else if ((*buttons >> 8) & 1) {
            result = 11;
            fn_1_A2D84(0xA9010100);
        }
    }
    if ((lbl_1_bss_9F8[v1].unk_8 >> 9) & 1) {
        result = -1;
        fn_1_A2D84(0xA9010200);
    }
    return result;
}
/* fzgx:end fn_3_4538 */

/* fzgx:begin fn_3_4A84 */
extern void fn_3_60C8(void);
extern void fn_1_48140(int);

void fn_3_4A84(void) {
    fn_3_60C8();
    fn_1_48140(0x4a);
    fn_1_48140(0x54);
    fn_1_48140(0x38);
    fn_1_48140(0x3e);
    fn_1_48140(0x37);
    fn_1_48140(0x55);
    fn_1_48140(0x30);
    fn_1_48140(0x35);
    fn_1_48140(0x3a);
    fn_1_48140(0x40);
    fn_1_48140(0x44);
    fn_1_48140(0x50);
    fn_1_48140(0x33);
    fn_1_48140(0x2e);
    fn_1_48140(0x31);
    fn_1_48140(0x4f);
    fn_1_48140(0x39);
    fn_1_48140(0x3d);
    fn_1_48140(0x4c);
    fn_1_48140(0x3f);
    fn_1_48140(0x48);
    fn_1_48140(0x52);
    fn_1_48140(0x45);
    fn_1_48140(0x53);
    fn_1_48140(0x3c);
    fn_1_48140(0x56);
    fn_1_48140(0x43);
    fn_1_48140(0x42);
    fn_1_48140(0x32);
    fn_1_48140(0x2f);
    fn_1_48140(0x34);
    fn_1_48140(0x36);
    fn_1_48140(0x4d);
    fn_1_48140(0x46);
    fn_1_48140(0x41);
    fn_1_48140(0x51);
    fn_1_48140(0x4e);
    fn_1_48140(0x47);
    fn_1_48140(0x3b);
    fn_1_48140(0x4b);
    fn_1_48140(0x49);
}
/* fzgx:end fn_3_4A84 */

/* fzgx:begin fn_3_4BEC */
struct fn_3_4BEC_lbl_3_data_B8 {
    u32 unk_0;
};

extern struct fn_3_4BEC_lbl_3_data_B8 lbl_3_data_B8;
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);
extern u32 fn_3_4A84(void);
extern u32 lbl_3_bss_20850;
extern u32 lbl_3_bss_F0;

void fn_3_4BEC(u32 arg0) {
    u32 v0;
    u32 t0, t1, t2;
    v0 = arg0;
    if ((lbl_3_bss_F0 & 0x10000000) == 0) {
    t0 = fn_3_4A84();
    v0 = t0;
    if ((s32)lbl_3_data_B8.unk_0 != -1) {
    v0 = (u32)&lbl_3_bss_20850;
    v0 = *(u32 *)((u8 *)v0 + 0);
    t1 = fn_1_435C(v0);
    v0 = t1;
    v0 = (u32)&lbl_3_data_B8;
    v0 = *(u32 *)((u8 *)v0 + 0);
    t2 = fn_1_426C(v0);
    v0 = t2;
    lbl_3_data_B8.unk_0 = -1;
    }
    }
}
/* fzgx:end fn_3_4BEC */

/* fzgx:begin fn_3_4C58 */
#include "rel/customize/globals.h"

typedef struct {
    u8 pad_0[0x390];
    u32 unk_390;
    u8 pad_394[0x3a0 - 0x394];
    void *unk_3a0;
    u32 unk_3a4;
    u8 pad_3a8[0x3ba - 0x3a8];
    u16 unk_3ba;
    u8 pad_3bc[0x440 - 0x3bc];
} Entry;

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[7];
    u32 unk_c;
    u8 pad_10[0x10420 - 0x10];
    u32 unk_420;
    u32 unk_424;
    u32 unk_428;
    u32 unk_42c;
    u8 pad_430[0x10440 - 0x10430];
} Dst;

typedef struct { u32 w[41]; } Copy164;
extern void fn_3_5D84(s32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_47F74(s32);
extern void *fn_1_7F254(void *, void *);
extern void fn_1_FD844(void *, void *);
extern s32 fn_1_FD324(void *);
extern void fn_1_FD27C(void *, void *);
extern void fn_1_FDC00(void *, void *, f32);
extern s32 lbl_3_bss_2C70C[45];
extern Copy164 lbl_3_rodata_F8;
extern Entry lbl_3_bss_20860[4];
extern u8 lbl_3_bss_21960[4 * 0xa20];
extern Dst lbl_3_bss_2C7C0[4];

void fn_3_4C58(void) {
    s32 i;
    s32 j;
    for (i = 0; (s16)i < 4; i++) fn_3_5D84(i);
    fn_80008BEC(lbl_3_bss_2C70C, 0, 0xa4);

    for (j = 0; (s16)j < 4; j++) {
        volatile Copy164 loc = lbl_3_rodata_F8; /* Complete the table copy before selecting an entry. */
        Obj_3_bss_140 *m = (Obj_3_bss_140 *)((u8 *)&lbl_3_bss_140 + ((0x81c0) * (j)));
        u32 flags = *(volatile u32 *)&m->unk_0; /* Read after the initialization copy. */
        if ((flags & 0x80000000) != 0 && (flags & 0x40000000) == 0) {
            if (lbl_3_bss_2C70C[m->pad_9[0x81a0 - 9]] == 0) {
                fn_1_47F74(loc.w[m->pad_9[0x81a0 - 9]]);
                lbl_3_bss_2C70C[m->pad_9[0x81a0 - 9]] = 1;
            }
        }
    }

    fn_80008BEC(lbl_3_bss_2C7C0, 0, 0x41100);
    for (i = 0; (s16)i < 4; i++) {
        Obj_3_bss_140 *m = (Obj_3_bss_140 *)((u8 *)&lbl_3_bss_140 + i * 0x81c0);
        Dst *dst = &lbl_3_bss_2C7C0[i];
        Entry *entry = &lbl_3_bss_20860[i];
        u8 *src = &lbl_3_bss_21960[i * 0xa20];
        u8 v5 = m->unk_5;
        dst->unk_c = 0x80000000;
        if (m->unk_7 == 0) continue;
        if ((m->unk_0 & 0x80000000) == 0) continue;
        if ((m->unk_0 & 0x40000000) != 0) {
            m->unk_8 = 3;
            entry->unk_390 = 0x04000000;
            entry->unk_3a0 = src;
        } else {
            m->unk_5 = *((u8 *)m + 0x81a0);
            if (m->unk_5 == 40) m->unk_8 = 3;
            else if (m->unk_5 == 4) m->unk_8 = 2;
            else m->unk_8 = 1;
        }
        if (m->unk_7 != 0 && m->unk_7 <= 4) {
            if (entry->unk_3a4 == 0) entry->unk_3a4 = (u32)fn_1_7F254(m, (void *)2);
            entry->unk_3ba = 1;
            dst->unk_4 = 4;
            dst->unk_0 = (u32)entry;
            *(volatile u32 *)&dst->unk_428 = (u32)fn_1_FDC00; /* Ordered callback setup. */
            *(volatile u32 *)&dst->unk_42c = (u32)fn_1_FD27C; /* Ordered callback setup. */
            *(volatile u32 *)&dst->unk_424 = (u32)fn_1_FD324; /* Ordered callback setup. */
            *(volatile u32 *)&dst->unk_420 = 0; /* Ordered callback setup. */
            dst->unk_c = 0x20000000;
            fn_1_FD844(m, dst);
            if ((m->unk_0 & 0x40000000) != 0) {
                entry->unk_390 &= ~0x04000000;
                entry->unk_3a0 = 0;
            } else m->unk_5 = v5;
        }
    }
}
/* fzgx:end fn_3_4C58 */

/* fzgx:begin fn_3_5A50 */
extern void fn_3_5E88(s16);
extern void fn_1_48140(s32);
extern void fn_1_7F3AC(void *);

struct InitData { u32 words[41]; };
struct Entry { u8 pad_390[0x390]; u32 flags; u8 pad_394[0x10]; u32 ready; u8 pad_3a8[0x98]; };
struct Meta { u32 value; u8 pad[0x81bc]; };
extern struct InitData lbl_3_rodata_1A4;
extern s32 lbl_3_bss_2C70C[45];
extern struct Entry lbl_3_bss_20860[4];
extern struct Meta lbl_3_bss_140[4];

void fn_3_5A50(void) {
    s16 i;
    struct InitData init;
    for (i = 0; i < 4; i++) fn_3_5E88(i);
    init = lbl_3_rodata_1A4;
    for (i = 0; i < 0x29U; i++) {
        if (lbl_3_bss_2C70C[i] != 0) fn_1_48140(init.words[i]);
    }
    for (i = 0; i < 4; i++) {
        struct Entry *entry = &lbl_3_bss_20860[i];
        u32 shift = 1;
        if (entry->ready != 0) {
            if (__rlwnm(lbl_3_bss_140[i].value, shift, 31, 31)) {
                entry->flags |= 0x04000000;
                fn_1_7F3AC(entry);
                entry->flags &= ~0x04000000;
            } else fn_1_7F3AC(entry);
            entry->ready = 0;
        }
    }
}
/* fzgx:end fn_3_5A50 */

/* fzgx:begin fn_3_5B9C */
extern u8 lbl_3_bss_140[132868];
extern u32 lbl_3_bss_6DD70;
extern s16 lbl_3_bss_F0[24];
extern u8 lbl_3_bss_2437C[44];
extern void fn_80008BEC(u8 *, int, int);
extern void fn_3_11FB4(u8, u8, u8 *);

void fn_3_5B9C(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        if (lbl_3_bss_6DD70 & (1 << i)) {
            fn_80008BEC(&lbl_3_bss_140[i * 0x81c0], 0, 0x81c0);
        }
    }

    fn_3_11FB4(lbl_3_bss_2437C[0], lbl_3_bss_F0[4], lbl_3_bss_140);
}
/* fzgx:end fn_3_5B9C */

/* fzgx:begin fn_3_5C4C */
extern u8 lbl_1_bss_970[];
extern u32 lbl_3_bss_20850;
extern void fn_1_4A00(int, int, u32);

void fn_3_5C4C(void) {
    lbl_1_bss_970[4] = 0;
    fn_1_4A00(1, 15, lbl_3_bss_20850);
}
/* fzgx:end fn_3_5C4C */

/* fzgx:begin fn_3_5C8C */
extern u8 lbl_3_data_1814[208];
extern void fn_3_3AE8(int, u8 *, int);

void fn_3_5C8C(void) {
    fn_3_3AE8(2, lbl_3_data_1814, 0x5d);
}
/* fzgx:end fn_3_5C8C */

/* fzgx:begin fn_3_5CBC */
extern f32 lbl_3_rodata_44[45];
extern void fn_8006CE1C(f32);

void fn_3_5CBC(void) {
    fn_8006CE1C(lbl_3_rodata_44[0]);
}
/* fzgx:end fn_3_5CBC */

/* fzgx:begin fn_3_5CE4 */
extern u32 lbl_3_rodata_248[6];
extern u32 lbl_3_bss_6DD78[42];
extern void fn_80008BA8(void *, const void *, int);
extern void fn_1_A6FE8(void);
extern void fn_1_DCE60(void *);

struct InitBlock {
    u32 first;
    u32 second;
    u32 values[3];
};

void fn_3_5CE4(u32 arg0, u32 arg1) {
    struct InitBlock block;

    block.first = arg0;
    block.second = arg1;
    block.values[0] = lbl_3_rodata_248[0];
    block.values[1] = lbl_3_rodata_248[1];
    block.values[2] = lbl_3_rodata_248[2];

    fn_80008BA8(lbl_3_bss_6DD78, &block.first, 0xc);
    fn_80008BA8(lbl_3_bss_6DD78 + 6, &block.first + 1, 0xc);

    {
        struct Triple { u32 a; u32 b; u32 c; };
        *(struct Triple *)&lbl_3_bss_6DD78[9] = *(struct Triple *)block.values;
    }

    fn_1_A6FE8();
    fn_1_DCE60(lbl_3_bss_6DD78);
}
/* fzgx:end fn_3_5CE4 */

/* fzgx:begin fn_3_5E88 */
typedef struct {
    u8 pad[0x324];
    s32 value;
    u8 tail[0x118];
} CustomizeEntry;

extern CustomizeEntry lbl_3_bss_20860[4];
extern u8 lbl_3_bss_21960[10368];
extern u32 lbl_1_bss_6D82C;

extern void fn_1_80F1C(s32, CustomizeEntry *);
extern void fn_1_14DBCC(void *);
extern void fn_80071718(u32);

void fn_3_5E88(s16 arg0) {
    s32 index;

    index = arg0;
    if (lbl_3_bss_20860[index].value != -1) {
        fn_1_80F1C((s16)lbl_3_bss_20860[index].value, &lbl_3_bss_20860[index]);
        lbl_3_bss_20860[index].value = -1;
    }

    fn_1_14DBCC((u8 *)lbl_3_bss_21960 + index * 0xa20);

    if (lbl_1_bss_6D82C != 0) {
        fn_80071718(lbl_1_bss_6D82C);
        lbl_1_bss_6D82C = 0;
    }
}
/* fzgx:end fn_3_5E88 */

/* fzgx:begin fn_3_5F28 */
struct Entry {
    u16 unk_0;
    u8 pad_2[2];
    u32 unk_4;
    u8 unk_8;
    u8 pad_9[0x17];
};

struct Data {
    u8 pad_0[0x11D0];
    s16 unk_11D0;
    u8 pad_11D2[2];
    u32 unk_11D4;
};

struct Base {
    struct Slot *unk_0;
};

struct Slot {
    u8 pad_0[0x324];
    u32 unk_324;
    u8 pad_328[0x118];
};

extern struct Entry lbl_3_bss_7DB60[41];
extern struct Data lbl_3_data_0;
extern struct Base lbl_3_bss_20854;

extern void fn_1_80058(s8, u8 *);
extern u32 fn_1_12A32C(void *);
extern void fn_1_12A2B8(u32);
extern void fn_1_80C18(u8 *, u8 *, s8);

void fn_3_5F28(u32 arg0) {
    s32 shift;
    struct Data *p_data;
    struct { struct Entry *value; } p_entry;
    s16 i;

    p_data = (struct Data *)&lbl_3_data_0;
    p_entry.value = (struct Entry *)&lbl_3_bss_7DB60;
    i = 0;
    while ((s16)i < 41) {
        fn_1_80058((s8)i, (u8 *)p_entry.value);
        p_entry.value->unk_0 = i;
        i++;
        shift = (s16)(p_data->unk_11D0);
        p_entry.value->unk_8 = 0;
        p_entry.value->unk_8 |= 0x10;
        p_entry.value->unk_4 = 1 << shift;
        p_entry.value = (struct Entry *)((u8 *)p_entry.value + 0x20);
    }

    p_data->unk_11D4 = fn_1_12A32C((void *)((u8 *)p_data + 0x1164));
    fn_1_12A2B8(1);
    fn_1_80C18((u8 *)lbl_3_bss_20854.unk_0, (u8 *)lbl_3_bss_7DB60, 41);
    fn_1_12A2B8(0);

    i = 0;
    while ((s16)i < 41) {
        lbl_3_bss_20854.unk_0[i].unk_324 = p_data->unk_11D4;
        i++;
    }
}
/* fzgx:end fn_3_5F28 */

/* fzgx:begin fn_3_60C8 */
struct fn_3_60C8_lbl_3_data_11D4 {
    u32 unk_0;
};
struct fn_3_60C8_lbl_3_bss_20854 {
    u32 unk_0;
};
struct fn_3_60C8_lbl_1_bss_6D82C {
    u32 unk_0;
};

extern struct fn_3_60C8_lbl_1_bss_6D82C lbl_1_bss_6D82C;
extern struct fn_3_60C8_lbl_3_bss_20854 lbl_3_bss_20854;
extern struct fn_3_60C8_lbl_3_data_11D4 lbl_3_data_11D4;
extern u32 fn_1_12A734(u32);
extern void fn_1_12A2B8(u32);
extern void fn_1_12A2D0(s32);
extern void fn_1_7F934(void *);
extern void fn_80071718(void *);

void fn_3_60C8(void) {
    struct fn_3_60C8_lbl_3_bss_20854 *p_lbl_3_bss_20854;
    u32 v0;
    s32 v2;
    u32 v3;
    u32 v4;
    u32 t5;
    if ((s32)lbl_3_data_11D4.unk_0 != -1) {
    v0 = 1;
    fn_1_12A2B8(v0);
    v0 = (u32)&lbl_3_data_11D4;
    v0 = *(u32 *)((u8 *)v0 + 0);
    fn_1_12A2D0(v0);
    } else {
    v0 = 0;
    fn_1_12A2B8(v0);
    }
    p_lbl_3_bss_20854 = (struct fn_3_60C8_lbl_3_bss_20854 *)&lbl_3_bss_20854;
{
    s32 v1;
    v1 = 0;
    v2 = 0;
    while ((s16)v1 < 41) {
    fn_1_7F934((void *)(p_lbl_3_bss_20854->unk_0 + v2));
    v2 += 1088;
    v1++;
}
    }
    v3 = lbl_1_bss_6D82C.unk_0;
    v4 = v3;
    if (v3 != 0) {
    fn_80071718((void *)v4);
    lbl_1_bss_6D82C.unk_0 = 0;
    }
    v4 = (u32)&lbl_3_data_11D4;
    v4 = *(u32 *)((u8 *)v4 + 0);
    if ((s32)v4 != -1) {
    t5 = fn_1_12A734(v4);
    v4 = t5;
    }
    v4 = 0;
    lbl_3_data_11D4.unk_0 = -1;
    fn_1_12A2B8(v4);
}
/* fzgx:end fn_3_60C8 */

/* fzgx:begin fn_3_61B8 */
struct fn_3_61B8_lbl_3_data_0 {
    u8 pad_0[0xB8];
    u32 unk_B8;
};
struct fn_3_61B8_lbl_3_bss_20850 {
    u32 unk_0;
};
struct fn_3_61B8_lbl_3_bss_243A8 {
    u32 unk_0;
};
struct fn_3_61B8_lbl_3_bss_120 {
    u32 unk_0;
};
struct fn_3_61B8_lbl_1_bss_6EAD0 {
    u32 unk_0;
};

extern struct fn_3_61B8_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct fn_3_61B8_lbl_3_bss_120 lbl_3_bss_120;
extern struct fn_3_61B8_lbl_3_bss_20850 lbl_3_bss_20850;
extern struct fn_3_61B8_lbl_3_bss_243A8 lbl_3_bss_243A8;
extern struct fn_3_61B8_lbl_3_data_0 lbl_3_data_0;
extern u32 fn_1_15BB34(u32);
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_47F74(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_1_A176C(u32, u32);
extern u32 fn_8006FDEC(void);
extern void fn_3_2AAF4(void);

void fn_3_61B8(void) {
    struct fn_3_61B8_lbl_3_data_0 *p_lbl_3_data_0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0, t1;
    p_lbl_3_data_0 = (struct fn_3_61B8_lbl_3_data_0 *)&lbl_3_data_0;
    if ((s32)p_lbl_3_data_0->unk_B8 == -1) {
    t0 = fn_8006FDEC();
    v1 = t0;
    v1 = (u32)((u8 *)(u32)p_lbl_3_data_0 + 5800);
    v0 = (u32)fn_3_2AAF4;
    v2 = 0;
    v3 = 8;
    t1 = fn_1_3F8C((u32)v1, (u32)v0, v2, v3);
    v1 = t1;
    p_lbl_3_data_0->unk_B8 = v1;
    }
    fn_1_4A00(1, 15, lbl_3_bss_20850.unk_0);
    lbl_3_bss_243A8.unk_0 = 0;
    lbl_3_bss_120.unk_0 = -1;
    fn_1_47F74(163);
    fn_1_A176C(*(u32 *)((u8 *)lbl_1_bss_6EAD0.unk_0 + 0), 15);
    fn_1_15BB34((u32)((u8 *)(u32)p_lbl_3_data_0 + 4444));
}
/* fzgx:end fn_3_61B8 */

/* fzgx:begin fn_3_6540 */
extern s16 lbl_1_bss_96A;
extern s32 lbl_3_data_B8;
extern u32 lbl_3_bss_20850;
extern void fn_1_435C(u32);
extern void fn_1_426C(s32);
extern void fn_1_48140(int);

void fn_3_6540(void) {
    if (lbl_1_bss_96A != 0x5d) {
        if (lbl_3_data_B8 != -1) {
            fn_1_435C(lbl_3_bss_20850);
            fn_1_426C(lbl_3_data_B8);
            lbl_3_data_B8 = -1;
        }
        fn_1_48140(0xa3);
    }
}
/* fzgx:end fn_3_6540 */

/* fzgx:begin fn_3_65B0 */
extern u8 jumptable_3_data_18E4[40];

extern void fn_1_F7D6C(void);
extern void fn_1_F7E24(void);
extern void fn_1_F7D18(void);
extern void fn_1_F7DC0(void);
extern s32 fn_1_F8A38(s32);
extern void fn_1_F8AD4(s32);
extern void fn_1_F8A58(s32);
extern void fn_1_F83F0(s32);
extern u8 fn_1_F8C50(s32);
extern void fn_1_F8C74(s32);
extern void fn_1_F8C00(s32);

void fn_3_65B0(u32 value) {
    switch ((u16)value) {
    case 0:
        fn_1_F7D6C();
        fn_1_F7E24();
        break;
    case 1:
        fn_1_F7D18();
        fn_1_F7DC0();
        break;
    case 2:
        if (fn_1_F8A38(0) == 0) {
            fn_1_F8AD4(0);
        }
        fn_1_F8A58(0);
        if (fn_1_F8A38(1) == 0) {
            fn_1_F8AD4(1);
        }
        fn_1_F8A58(1);
        if (fn_1_F8A38(2) == 0) {
            fn_1_F8AD4(2);
        }
        fn_1_F8A58(2);
        if (fn_1_F8A38(3) == 0) {
            fn_1_F8AD4(3);
        }
        fn_1_F8A58(3);
        if (fn_1_F8A38(4) == 0) {
            fn_1_F8AD4(4);
        }
        fn_1_F8A58(4);
        if (fn_1_F8A38(5) == 0) {
            fn_1_F8AD4(5);
        }
        fn_1_F8A58(5);
        break;
    case 3:
        fn_1_F83F0(0x11);
        fn_1_F83F0(0x26);
        fn_1_F83F0(0x34);
        break;
    case 4:
        fn_1_F83F0(0x16);
        fn_1_F83F0(0x30);
        fn_1_F83F0(0x3e);
        break;
    case 5:
        fn_1_F83F0(8);
        fn_1_F83F0(0x2c);
        fn_1_F83F0(0x49);
        break;
    case 6:
        fn_1_F83F0(0xb);
        fn_1_F83F0(0x2e);
        fn_1_F83F0(0x39);
        break;
    case 7:
        fn_1_F83F0(1);
        fn_1_F83F0(0x1a);
        fn_1_F83F0(0x46);
        break;
    case 8:
        if (fn_1_F8C50(1) == 0) {
            fn_1_F8C74(1);
        }
        fn_1_F8C00(1);
        break;
    case 9:
        if (fn_1_F8C50(0) == 0) {
            fn_1_F8C74(0);
        }
        fn_1_F8C00(0);
        break;
    }
}
/* fzgx:end fn_3_65B0 */

/* fzgx:begin fn_3_679C */
struct fn_3_679C_lbl_3_bss_7E080 {
    u32 unk_0;
};

extern struct fn_3_679C_lbl_3_bss_7E080 lbl_3_bss_7E080;
extern u32 fn_1_15BBC4(void);
extern u32 lbl_3_bss_8;
extern void fn_1_A2D84(u32);
extern void fn_3_65B0(u32);

void fn_3_679C(void) {
    u32 v0;
    u32 t0;

    t0 = fn_1_15BBC4();
    v0 = t0;
    if ((t0 & 0xFFFF) != 65535) {
        if ((s32)lbl_3_bss_7E080.unk_0 == 0) {
            lbl_3_bss_7E080.unk_0 = 1;
            fn_3_65B0(v0);
            v0 = 0xA9000000;
            v0 += 1024;
            fn_1_A2D84(v0);
            lbl_3_bss_8 = 1;
        }
    } else {
        lbl_3_bss_7E080.unk_0 = 0;
    }
}
/* fzgx:end fn_3_679C */

/* fzgx:begin fn_3_6D2C */
extern s32 lbl_3_bss_120;
extern u32 lbl_3_bss_F0[12];
extern s32 fn_1_4C10(void);
extern s16 fn_3_6AC4(void);
extern u16 lbl_1_bss_96A;
extern u32 lbl_3_bss_20850;
extern u32 lbl_3_bss_243A8[6];
extern void fn_1_4A00(s32, s32, u32);
extern u16 lbl_3_bss_20[104];
extern u32 lbl_3_bss_2C7C0[66624];
extern void fn_80008BEC(void *, s32, s32);
extern void fn_1_FDFF4(void);
extern void fn_1_FC4E0(void *, s32);
extern u32 lbl_3_bss_7EBA4;
extern u32 lbl_3_bss_7EBA8;
extern u8 lbl_3_data_11DC[84];
extern u32 lbl_801A6410;
extern void fn_1_7F3AC(u32);
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern void fn_1_BC29C(u32 *arg0);
extern void fn_1_B9C0C(void);
extern char lbl_3_data_1A1C[17];
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char *, ...);
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A14;

void fn_3_6D2C(void) {
    u32 flags;
    s32 ready;

    if (lbl_3_bss_120 == -1) {
        fn_1_4C10();
    }

    flags = lbl_3_bss_F0[9];
    if ((flags & (~((u32)-1 >> 1))) != 0 &&
        (flags & 1) == 0 &&
        (lbl_3_bss_F0[0] & 2) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready == 0) {
        if (lbl_3_bss_120 != -1) {
            s32 value = lbl_3_bss_120;
            lbl_3_bss_120 = -1;
            lbl_1_bss_96A = (u16)value;
        } else if (fn_3_6AC4() == (s16)-1) {
            fn_1_4A00(0, 15, lbl_3_bss_20850);
            lbl_3_bss_243A8[0] = 0;
            lbl_3_bss_120 = 110;
        }
    }
}
/* fzgx:end fn_3_6D2C */

/* fzgx:begin fn_3_6E14 */
#include "rel/customize/globals.h"

struct Obj3_Idx {
    u8 pad_0[0xC2];
    s16 idx;
};

struct Obj3_Tab {
    u8 pad_0[0x850];
    u32 arg;
    u32 base;
};

extern u16 lbl_3_bss_7E084[220];
extern s32 lbl_3_data_11D4;
extern s32 lbl_3_data_B8;
extern u32 lbl_1_bss_6D82C;

extern void fn_1_7B4C0(void);
extern void fn_1_12A2B8(u32);
extern void fn_1_12A2D0(s32);
extern void fn_1_12A734(s32);
extern void fn_1_7F934(void *);
extern void fn_80071718(void *);
extern u32 fn_1_F9A80(void);
extern u32 fn_1_435C(u32);
extern u32 fn_1_426C(u32);
extern void fn_1_48140(int);

typedef struct lbl_3_bss_C_t {
    s32 unk_C;
    u8 pad_4[0x8];
} lbl_3_bss_C_t;

typedef struct lbl_3_bss_20_t {
    u8 fzgx_byte_20;
    u8 pad_1[0xcf];
} lbl_3_bss_20_t;

typedef struct lbl_3_bss_20854_t {
    u32 base;
    u8 pad_4[0x8];
} lbl_3_bss_20854_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_3_bss_0[2];
s32 lbl_3_bss_8;
lbl_3_bss_C_t lbl_3_bss_C;
u32 fzgx_obj_lbl_3_bss_18[2];
lbl_3_bss_20_t fzgx_obj_lbl_3_bss_20;
u32 fzgx_obj_lbl_3_bss_F0[12];
u32 lbl_3_bss_120[8];
u8 fzgx_obj_lbl_3_bss_140[0x20704];
s16 lbl_3_bss_20844;
u32 lbl_3_bss_20848;
u32 lbl_3_bss_2084C;
u32 lbl_3_bss_20850;
lbl_3_bss_20854_t lbl_3_bss_20854;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_0;
    s = *(u8 *)&lbl_3_bss_8;
    s = *(u8 *)&lbl_3_bss_C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_F0;
    s = *(u8 *)&lbl_3_bss_120;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_140;
    s = *(u8 *)&lbl_3_bss_20844;
    s = *(u8 *)&lbl_3_bss_20848;
    s = *(u8 *)&lbl_3_bss_2084C;
    s = *(u8 *)&lbl_3_bss_20850;
    s = *(u8 *)&lbl_3_bss_20854;
}
#pragma section code_type ".text"

#pragma opt_dead_assignments off
static inline void fn_3_6E14_each(void) {
    s16 i;
    for (i = 0; i < 0x29; i++) {
        fn_1_7F934((void *)(lbl_3_bss_20854.base + i * 0x440));
    }
}

void fn_3_6E14(void) {
    u8 *arr = (u8 *)lbl_3_bss_7E084;

    if (*(s16 *)(arr + ((struct Obj3_Idx *)((u8 *)&fzgx_obj_lbl_3_bss_20.fzgx_byte_20))->idx * 10 + 2) == 1) {
        fn_1_7B4C0();
    }

    if (lbl_3_data_11D4 != -1) {
        fn_1_12A2B8(1);
        fn_1_12A2D0(lbl_3_data_11D4);
    } else {
        fn_1_12A2B8(0);
    }

    fn_3_6E14_each();

    if (lbl_1_bss_6D82C != 0) {
        fn_80071718((void *)lbl_1_bss_6D82C);
        lbl_1_bss_6D82C = 0;
    }

    if (lbl_3_data_11D4 != -1) {
        fn_1_12A734(lbl_3_data_11D4);
    }

    lbl_3_data_11D4 = -1;
    fn_1_12A2B8(0);

    if (lbl_3_bss_8 != 0 && lbl_3_bss_C.unk_C != 0) {
        fn_1_F9A80();
    }

    if (-1 != lbl_3_data_B8) {
        fn_1_435C(lbl_3_bss_20850);
        fn_1_426C(lbl_3_data_B8);
        lbl_3_data_B8 = -1;
    }

    fn_1_48140(0xa3);
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_3_6E14 */

/* fzgx:begin fn_3_6F90 */
extern s16 lbl_3_bss_6D8C0[600];
extern u8 lbl_3_bss_7E240[1200];

extern void fn_80008BEC(s16 *values, s32 value, s32 count);
extern void fn_80008BA8(u8 *destination, s16 *entry, s32 size);
extern s16 fn_1_14F014(void);

static inline s16 fn_3_6F90_array_read(s32 index, s16 *array) { return array[index]; }
void fn_3_6F90(void) {
    s16 values[6];
    struct { s16 * value; } entry;
    u8 *base;
    s16 i;
    s32 k;

    fn_80008BEC(values, 0, 6);
    entry.value = (s16 *)lbl_3_bss_6D8C0;
    i = 0;
    while (i < fn_1_14F014()) {
        k = fn_3_6F90_array_read(1, entry.value);
        fn_80008BA8((lbl_3_bss_7E240) + k * 0x190 + fn_3_6F90_array_read(k, values) * 0x10, entry.value, 0x10);
        values[k]++;
        entry.value += 8;
        i++;
    }
}
/* fzgx:end fn_3_6F90 */

/* fzgx:begin fn_3_7594 */
extern s32 lbl_3_bss_120;
extern u32 lbl_3_bss_F0[12];
extern s32 fn_1_4C10(void);
extern s16 fn_3_7360(void);
extern u16 lbl_1_bss_96A;
extern u32 lbl_3_bss_20850;
extern u32 lbl_3_bss_243A8[6];
extern void fn_1_4A00(s32, s32, u32);
extern u32 lbl_3_bss_6DD78[42];
extern void fn_1_DCED0(u32 *);

void fn_3_7594(void) {
    u32 flags;
    s32 ready;

    if (lbl_3_bss_120 == -1) {
        fn_1_4C10();
    }

    flags = lbl_3_bss_F0[9];
    if ((flags & (~((u32)-1 >> 1))) != 0 &&
        (flags & 1) == 0 &&
        (lbl_3_bss_F0[0] & 2) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready == 0) {
        if (lbl_3_bss_120 != -1) {
            s32 value = lbl_3_bss_120;
            lbl_3_bss_120 = -1;
            lbl_1_bss_96A = (u16)value;
        } else {
            fn_1_DCED0(lbl_3_bss_6DD78);
            if (fn_3_7360() == -1) {
                fn_1_4A00(0, 15, lbl_3_bss_20850);
                lbl_3_bss_243A8[0] = 0;
                lbl_3_bss_120 = 110;
            }
        }
    }
}
/* fzgx:end fn_3_7594 */

/* fzgx:begin fn_3_7688 */
extern s32 lbl_3_bss_8;
extern s32 lbl_3_bss_C[3];
extern s32 lbl_3_data_11D8;
extern u8 lbl_3_bss_6DE20[64832];
extern s32 lbl_3_data_B8;
extern s32 lbl_3_bss_20850;

extern void fn_1_F8580(void);
extern void fn_1_12A2B8(int);
extern void fn_1_12A2D0(int);
extern void fn_1_14DC68(void *, int);
extern void fn_1_12A734(int);
extern void fn_1_435C(int);
extern void fn_1_426C(int);
extern void fn_1_48140(int);

void fn_3_7688(void) {
    if (lbl_3_bss_8 != 0 && lbl_3_bss_C[0] != 0) {
        fn_1_F8580();
    }

    if (lbl_3_data_11D8 != -1) {
        fn_1_12A2B8(1);
        fn_1_12A2D0(lbl_3_data_11D8);
    }

    fn_1_14DC68(lbl_3_bss_6DE20, 25);
    fn_1_12A2B8(0);

    if (lbl_3_data_11D8 != -1) {
        fn_1_12A734(lbl_3_data_11D8);
    }

    lbl_3_data_11D8 = -1;

    if (lbl_3_data_B8 != -1) {
        fn_1_435C(lbl_3_bss_20850);
        fn_1_426C(lbl_3_data_B8);
        lbl_3_data_B8 = -1;
    }

    fn_1_48140(163);
}
/* fzgx:end fn_3_7688 */

/* fzgx:begin fn_3_7770 */
extern u32 lbl_3_bss_20850;
extern s16 lbl_3_data_A8[6];
extern void fn_1_4A00(s32, s32, u32);

void fn_3_7770(void) {
    fn_1_4A00(1, 0xf, lbl_3_bss_20850);
    lbl_3_data_A8[0] = (u16)-1;
}
/* fzgx:end fn_3_7770 */

/* fzgx:begin fn_3_77B0 */
extern u8 lbl_1_bss_9F8[];
extern u16 lbl_1_bss_96A;
extern u32 lbl_3_bss_20850;
extern s16 lbl_3_data_A8[6];
extern const f32 lbl_3_rodata_260;
extern u8 lbl_3_data_1930[40];

extern int fn_1_4C10(void);
extern void fn_1_4A00(int, int, u32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);

void fn_3_77B0(void) {
    if (((*(u16 *)(lbl_1_bss_9F8 + 8) >> 9) & 1) != 0 && fn_1_4C10() == 0) {
        fn_1_4A00(0, 15, lbl_3_bss_20850);
        lbl_3_data_A8[0] = 0x10;
    }
    if (lbl_3_data_A8[0] > 0 && --lbl_3_data_A8[0] == 0) {
        lbl_1_bss_96A = 0x61;
    } else {
        fn_1_496FC(lbl_3_rodata_260, lbl_3_rodata_260);
        fn_1_4AE0C((const char *)lbl_3_data_1930);
    }
}
/* fzgx:end fn_3_77B0 */

/* fzgx:begin fn_3_7864 */
// fn_3_7864: empty in retail (single blr).
void fn_3_7864(void) {
}
/* fzgx:end fn_3_7864 */

/* fzgx:begin fn_3_7868 */
// fn_3_7868: empty in retail (single blr).
void fn_3_7868(void) {
}
/* fzgx:end fn_3_7868 */

/* fzgx:begin fn_3_786C */
// fn_3_786C: empty in retail (single blr).
void fn_3_786C(void) {
}
/* fzgx:end fn_3_786C */

/* fzgx:begin fn_3_7870 */
extern s32 lbl_3_data_B8;
extern u32 lbl_3_bss_20850;
extern void fn_1_435C(u32);
extern void fn_1_426C(s32);

void fn_3_7870(void) {
    if (lbl_3_data_B8 != -1) {
        fn_1_435C(lbl_3_bss_20850);
        fn_1_426C(lbl_3_data_B8);
        lbl_3_data_B8 = -1;
    }
}
/* fzgx:end fn_3_7870 */

/* fzgx:begin fn_3_78C8 */
typedef struct CustomizeEntry {
    u8 pad[0x20];
    s16 count;
    s16 values[0x0a];
} CustomizeEntry;

extern CustomizeEntry lbl_3_bss_20[3];
extern void fn_80008BEC(void *, s32, u32);
extern s32 fn_1_F8334(s32);
extern s32 fn_1_14D6D8(s32);
extern s16 fn_1_14F344(s32);
extern s32 fn_1_F809C(s32);

void fn_3_78C8(s32 enabled) {
    s32 i;

    fn_80008BEC((u8 *)lbl_3_bss_20 + 0x20, 0, 0xa2);
    i = 0;
    while ((s16)i < 0x4b) {
        if (enabled != 0) {
            if (fn_1_F8334(i) != 0 &&
                (fn_1_14D6D8(i) & 0x40000000) == 0) {
                s16 index = fn_1_14F344(i);
                CustomizeEntry *entry = &lbl_3_bss_20[index];

                entry->values[entry->count++] = (s16)i;
            }
        } else if (fn_1_F809C(i) != 0) {
            s16 index = fn_1_14F344(i);
            CustomizeEntry *entry = &lbl_3_bss_20[index];

            entry->values[entry->count++] = (s16)i;
        }
        i++;
    }
    lbl_3_bss_20[0].values[lbl_3_bss_20[0].count] = -1;
    lbl_3_bss_20[1].values[lbl_3_bss_20[1].count] = -1;
    lbl_3_bss_20[2].values[lbl_3_bss_20[2].count] = -1;
}
/* fzgx:end fn_3_78C8 */

/* fzgx:begin fn_3_7A08 */
extern s16 lbl_3_bss_20[104];

void fn_3_7A08(s16 *arg0, s16 *arg1, int arg2) {
    *arg0 = -lbl_3_bss_20[98];
    *arg1 = *arg0 + arg2 - 1;
}
/* fzgx:end fn_3_7A08 */

/* fzgx:begin fn_3_7A30 */
extern void fn_1_47F74(int);

void fn_3_7A30(void) {
    fn_1_47F74(0x65);
    fn_1_47F74(0x6d);
    fn_1_47F74(0x80);
    fn_1_47F74(0x58);
    fn_1_47F74(0x69);
    fn_1_47F74(0x75);
    fn_1_47F74(0x64);
    fn_1_47F74(0x74);
    fn_1_47F74(0x63);
    fn_1_47F74(0x6c);
    fn_1_47F74(0x5a);
    fn_1_47F74(0x6e);
    fn_1_47F74(0x82);
    fn_1_47F74(0x6b);
    fn_1_47F74(0x79);
    fn_1_47F74(0x68);
    fn_1_47F74(0x6a);
    fn_1_47F74(0x59);
    fn_1_47F74(0x6f);
    fn_1_47F74(0x57);
    fn_1_47F74(0x72);
    fn_1_47F74(0x7e);
    fn_1_47F74(0x73);
    fn_1_47F74(0x71);
    fn_1_47F74(0x5b);
    fn_1_47F74(0x81);
    fn_1_47F74(0x62);
    fn_1_47F74(0x7a);
    fn_1_47F74(0x5d);
    fn_1_47F74(0x7c);
    fn_1_47F74(0x5c);
    fn_1_47F74(0x61);
    fn_1_47F74(0x60);
    fn_1_47F74(0x5e);
    fn_1_47F74(0x7f);
    fn_1_47F74(0x5f);
    fn_1_47F74(0x77);
    fn_1_47F74(0x70);
    fn_1_47F74(0x76);
    fn_1_47F74(0x78);
    fn_1_47F74(0x7d);
}
/* fzgx:end fn_3_7A30 */

/* fzgx:begin fn_3_7B94 */
extern void fn_1_48140(int);

void fn_3_7B94(void) {
    fn_1_48140(0x65);
    fn_1_48140(0x6d);
    fn_1_48140(0x80);
    fn_1_48140(0x58);
    fn_1_48140(0x69);
    fn_1_48140(0x75);
    fn_1_48140(0x64);
    fn_1_48140(0x74);
    fn_1_48140(0x63);
    fn_1_48140(0x6c);
    fn_1_48140(0x5a);
    fn_1_48140(0x6e);
    fn_1_48140(0x82);
    fn_1_48140(0x6b);
    fn_1_48140(0x79);
    fn_1_48140(0x68);
    fn_1_48140(0x6a);
    fn_1_48140(0x59);
    fn_1_48140(0x6f);
    fn_1_48140(0x57);
    fn_1_48140(0x72);
    fn_1_48140(0x7e);
    fn_1_48140(0x73);
    fn_1_48140(0x71);
    fn_1_48140(0x5b);
    fn_1_48140(0x81);
    fn_1_48140(0x62);
    fn_1_48140(0x7a);
    fn_1_48140(0x5d);
    fn_1_48140(0x7c);
    fn_1_48140(0x5c);
    fn_1_48140(0x61);
    fn_1_48140(0x60);
    fn_1_48140(0x5e);
    fn_1_48140(0x7f);
    fn_1_48140(0x5f);
    fn_1_48140(0x77);
    fn_1_48140(0x70);
    fn_1_48140(0x76);
    fn_1_48140(0x78);
    fn_1_48140(0x7d);
}
/* fzgx:end fn_3_7B94 */

/* fzgx:begin fn_3_7CF8 */
extern u16 lbl_3_bss_6D8C0[600];
extern u8 lbl_3_data_0[];
extern u8 lbl_3_bss_7E240[1200];
extern u32 lbl_3_bss_20848;
extern u8 lbl_3_bss_6DE20[64832];
extern u32 lbl_1_bss_6D82C;

extern s16 fn_1_14F014(void);
extern void fn_1_14E9E4(s16, void *);
extern void fn_80008BEC(void *, s32, s32);
extern void fn_80008BA8(void *, void *, s32);
extern void fn_1_12AB38(void *);
extern u32 fn_1_D3884(void *);
extern u32 fn_1_12A32C(void *);
extern void fn_1_12A2B8(s32);
extern void fn_1_12A2C4(s32);
extern void fn_1_14D994(void *, u32, s32);
extern void fn_3_7A30(void);

void fn_3_7CF8(void) {
    u8 *data;
    struct { u16 *value; } p;
    struct { s16 value; } i;
    s16 counts[3];
    struct { s16 value; } k;

    i.value = 0;
    data = lbl_3_data_0;
    p.value = lbl_3_bss_6D8C0;
    while (i.value < fn_1_14F014()) {
        fn_1_14E9E4(i.value, p.value + i.value * 8);
        i.value++;
    }

    fn_80008BEC(counts, 0, 6);
    k.value = 0;
    while (k.value < fn_1_14F014()) {
        s32 index;
        index = (s16)(*(s16 *)((u8 *)p.value + 2));
        fn_80008BA8(lbl_3_bss_7E240 + index * 0x190 + counts[index] * 0x10, p.value, 0x10);
        p.value += 8;
        k.value++;
        counts[index] += 1;
    }

    if (lbl_1_bss_6D82C == 0) {
        fn_1_12AB38(data + 0x18a4);
        lbl_1_bss_6D82C = fn_1_D3884(data + 0x18b0);
        fn_1_12AB38(data + 0x18c0);
    }
    *(u32 *)(data + 0x11d8) = fn_1_12A32C(data + 0x1180);
    fn_1_12A2B8(1);
    fn_1_12A2C4(1);
    fn_1_14D994(lbl_3_bss_6DE20, 1u << lbl_3_bss_20848, 1);
    fn_1_12A2B8(0);
    fn_1_12A2C4(0);
    fn_3_7A30();
}
/* fzgx:end fn_3_7CF8 */

/* fzgx:begin fn_3_837C */
extern u32 lbl_3_bss_140;
extern u32 lbl_3_bss_243C0;
extern s32 fn_8008023C(u32, u32, u32);

s32 fn_3_837C(s16 arg0) {
    return fn_8008023C((u32)(&lbl_3_bss_243C0), (u32)(((u8 *)(&lbl_3_bss_140) + (arg0 * 0x81C0))), 0x81C0U) != 0;
}
/* fzgx:end fn_3_837C */

/* fzgx:begin fn_3_968C */
struct fn_3_968C_lbl_3_data_11D8 {
    u32 unk_0;
};

extern struct fn_3_968C_lbl_3_data_11D8 lbl_3_data_11D8;
extern u32 fn_1_12A2B8(u32);
extern u32 fn_1_12A2D0(u32);
extern u32 fn_1_12A734(u32);
extern u32 fn_1_14DC68(u32, u32);
extern u32 fn_3_7B94(void);
extern u32 lbl_3_bss_6DE20;

void fn_3_968C(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 t0, t1;
    v0 = arg0;
    if ((s32)lbl_3_data_11D8.unk_0 != -1) {
    v0 = 1;
    t0 = fn_1_12A2B8(v0);
    v0 = t0;
    v0 = (u32)&lbl_3_data_11D8;
    v0 = *(u32 *)((u8 *)v0 + 0);
    t1 = fn_1_12A2D0(v0);
    v0 = t1;
    }
    fn_1_14DC68((u32)&lbl_3_bss_6DE20, 25);
    fn_1_12A2B8(0);
    v1 = lbl_3_data_11D8.unk_0;
    if ((s32)v1 != -1) {
    fn_1_12A734(v1);
    }
    lbl_3_data_11D8.unk_0 = -1;
    fn_3_7B94();
}
/* fzgx:end fn_3_968C */

/* fzgx:begin fn_3_9710 */
struct fn_3_9710_lbl_3_data_11D8 {
    u32 unk_0;
};
struct fn_3_9710_lbl_3_data_B8 {
    u32 unk_0;
};

extern struct fn_3_9710_lbl_3_data_11D8 lbl_3_data_11D8;
extern struct fn_3_9710_lbl_3_data_B8 lbl_3_data_B8;
extern u32 fn_1_12A734(u32);
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);
extern u32 lbl_3_bss_20850;
extern u32 lbl_3_bss_6DE20;
extern u32 lbl_3_bss_F0;
extern void fn_1_12A2B8(u32);
extern void fn_1_12A2D0(s32);
extern void fn_1_14DC68(void *, int);
extern void fn_1_151BDC(u32);
extern void fn_1_FE5C4(u8, u32, u32, u8);
extern void fn_3_7B94(void);
extern void fn_3_BC60(void);

void fn_3_9710(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 t4, t6, t7;
    v1 = arg1;
    if ((lbl_3_bss_F0 & 0x40000000) == 0) {
    if ((s32)lbl_3_data_11D8.unk_0 != -1) {
    v0 = 1;
    fn_1_12A2B8(v0);
    v0 = (u32)&lbl_3_data_11D8;
    v0 = *(u32 *)((u8 *)v0 + 0);
    fn_1_12A2D0(v0);
    }
    v1 = 25;
    v0 = (u32)&lbl_3_bss_6DE20;
    fn_1_14DC68((void *)(u32)v0, v1);
    v0 = 0;
    fn_1_12A2B8(v0);
    v0 = (u32)&lbl_3_data_11D8;
    v0 = *(u32 *)((u8 *)v0 + 0);
    if ((s32)v0 != -1) {
    t4 = fn_1_12A734(v0);
    v0 = t4;
    }
    lbl_3_data_11D8.unk_0 = -1;
    fn_3_7B94();
    if ((s32)lbl_3_data_B8.unk_0 != -1) {
    v0 = (u32)&lbl_3_bss_20850;
    v0 = *(u32 *)((u8 *)v0 + 0);
    t6 = fn_1_435C(v0);
    v0 = t6;
    v0 = (u32)&lbl_3_data_B8;
    v0 = *(u32 *)((u8 *)v0 + 0);
    t7 = fn_1_426C(v0);
    v0 = t7;
    lbl_3_data_B8.unk_0 = -1;
    }
    v0 = 0;
    fn_1_151BDC(v0);
    }
    fn_3_BC60();
    fn_1_FE5C4(0, 0, 0, 0);
}
/* fzgx:end fn_3_9710 */

/* fzgx:begin fn_3_9800 */
typedef struct { u8 pad[0x8]; s16 unk_8; } Obj_F0;
typedef struct { u32 unk_0; u8 pad_4[0x1]; u8 unk_5; u8 pad_6[0x81ba]; } Obj_140;
typedef struct { u8 pad[0x324]; s32 value; u8 tail[0x118]; } CustomizeEntry;

extern Obj_F0 lbl_3_bss_F0;
extern Obj_140 lbl_3_bss_140[4];
extern CustomizeEntry lbl_3_bss_20860[4];
extern u32 lbl_3_bss_20848;
extern u8 lbl_3_bss_21960[10368];
extern u8 lbl_3_data_0[0x20704];
extern u32 lbl_1_bss_6D82C;
extern s16 fn_1_80CC4(u8, s32, s32, void *);
extern void fn_1_12AB38(void *);
extern u32 fn_1_D3884(void *);
extern void fn_1_14DB48(u32 *, void *, u32);

#pragma opt_propagation off
void fn_3_9800(void) {
    s16 index;
    Obj_140 *meta;
    u8 *data;
    s32 off;

    index = lbl_3_bss_F0.unk_8;
    off = index * 0x81c0;
    data = lbl_3_data_0;
    lbl_3_bss_20860[index].value = -1;
    meta = (Obj_140 *)((u8 *)&lbl_3_bss_140 + off);
    if (meta->unk_0 & 0x80000000) {
        if (!(meta->unk_0 & 0x40000000)) {
            lbl_3_bss_20860[index].value = fn_1_80CC4(meta->unk_5, 1, 0, &lbl_3_bss_20860[index]);
        } else {
            if (lbl_1_bss_6D82C == 0) {
                fn_1_12AB38(data + 0x18a4);
                lbl_1_bss_6D82C = fn_1_D3884(data + 0x18b0);
                fn_1_12AB38(data + 0x18c0);
            }
            fn_1_14DB48(&meta->unk_0, lbl_3_bss_21960 + index * 0xa20, 1U << lbl_3_bss_20848);
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_3_9800 */
