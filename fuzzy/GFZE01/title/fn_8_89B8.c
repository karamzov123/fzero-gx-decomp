/* Non-matching: best partial attempt (92.64% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/title/operation.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 15.0;
    s = 320.0f;
    s = 640.0f;
    d = 1.0;
    s = 150.0f;
    s = 0.10000000149011612f;
    s = 20.0f;
    s = 0.8333333134651184f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09000000357627869f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_table4[6] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table6[4] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table7[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern const struct fn_8_89B8_lbl_8_rodata_160_pool {
    f64 unk_0;
    f32 unk_8;
    f32 unk_C;
    f64 unk_10;
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    f32 unk_24;
    u8 pad_28[0xC];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    u8 pad_4C[0x2C];
    u32 unk_78;
} lbl_8_rodata_160;

extern s32 lbl_801A66B4;
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(void *, f32);
extern u16 fn_8_CC4C(u32, u32);


#pragma peephole on
static inline const u32 *fn_8_89B8_array_read(const u32 *array) { return array; }
#pragma opt_lifetimes off
typedef struct lbl_8_bss_3D0_t {
    u32 unk_0;
    u8 pad_4[0x16c];
} lbl_8_bss_3D0_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_8_bss_3D0_t fzgx_obj_lbl_8_bss_3D0;
u8 lbl_8_bss_540;
u8 lbl_8_bss_3D0_gap_541;
u16 lbl_8_bss_3D0_gap_541_fill_542;
u32 lbl_8_bss_544[3];
u32 fzgx_obj_lbl_8_bss_550;
u8 fzgx_obj_lbl_8_bss_554;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8_bss_3D0;
    s = *(u8 *)&lbl_8_bss_540;
    s = *(u8 *)&lbl_8_bss_3D0_gap_541;
    s = *(u8 *)&lbl_8_bss_3D0_gap_541_fill_542;
    s = *(u8 *)&lbl_8_bss_544;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_550;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_554;
}
#pragma section code_type ".text"

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("NON");
}
#pragma section code_type ".text"

#pragma opt_propagation off
static inline const u32 *fn_8_89B8_array_read_(const u32 *array) { return array; }
#pragma opt_propagation reset

#pragma opt_propagation off
void fn_8_89B8(void) {
    u8 pad_0[0xBA8];
    const char * lab_t0;
    struct TextTables {
        u8 pad_0[0xBA8];
        const char *first[24];
        const u8 *second[25];
        const char *third[1];
    } *data = (struct TextTables *)(u8 *)"NON";
    const char **tblp;
    s32 x;
    f32 t;
    f32 alpha;
    u32 arg;
    struct { u8 r, g, b, a; } col;
    s32 timer = (s32)lbl_8_bss_3CC;
    if ((f64)timer < (15.0)) {
        t = (1.0) - (f32)timer / (15.0);
        x = (320.0f) + (f32)((640.0f) * t);
    } else if ((f64)timer > (f64)(s32)fzgx_obj_lbl_8_bss_3D0.unk_0 - (15.0)) {
        t = (1.0) - (f32)((s32)fzgx_obj_lbl_8_bss_3D0.unk_0 - timer) / (15.0);
        x = (320.0f) - (f32)((640.0f) * t);
    } else {
        t = (0.0f);
        x = 320;
    }
    alpha = ((1.0f) - t) * ((1.0f) - t);
    fn_1_49410();
    fn_1_495B0(1U << 31);
    fn_1_49590((0.5f));
    fn_1_495C8(9);
    fn_1_496FC((f32)x, (150.0f));
    fn_1_4954C((0.0900000036f));
    if (lbl_801A66B4 == 5) {
        fn_1_4955C((1.0f), (1.0f));
    } else {
        fn_1_4955C((0.833333313f), (0.833333313f));
    }
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748((5.0f));
    tblp = (const char **)fn_8_89B8_array_read((const u32 *)data->first);
    lab_t0 = tblp[lbl_801A66B4];
    fn_1_4AE0C(lab_t0);
    fn_1_49738(0);
    tblp = (const char **)fn_8_89B8_array_read((const u32 *)data->second);
    lab_t0 = tblp[lbl_801A66B4];
    fn_1_4AE0C(lab_t0);
    tblp = (const char **)fn_8_89B8_array_read((const u32 *)data->third);
    lab_t0 = tblp[lbl_801A66B4];
    fn_1_4AE0C(lab_t0);
    *(u32 *)&col = fn_8_89B8_array_read_(fzgx_pool_table7)[0];
    col.a = (s32)(255.0f * alpha);
    *(u32 *)&arg = *(u32 *)&col;
    fn_1_4D0D4(&arg, (20.0f));
    fn_8_CC4C(439, 177);
}
#pragma opt_propagation reset

#pragma opt_lifetimes reset

#pragma peephole reset
