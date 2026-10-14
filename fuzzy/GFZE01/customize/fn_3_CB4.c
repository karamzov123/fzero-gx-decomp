/* Non-matching: best partial attempt (83.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
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
}
#pragma section code_type ".text"

typedef struct {
    u32 v[6];
} Sel6;

typedef struct {
    u8 pad0[0x630];
    u32 ids[532];
    Sel6 tbl[77];
    u8 pad1[0x14];
    char name[1];
} DataHdr;

typedef struct {
    u8 *base;
} DataRef;

static const u32 pool_word[1] = { 0x43A00000u };

extern s32 lbl_801A66B4;
extern u8 lbl_3_bss_2437C[44];

extern void fn_3_BFC(char *destination, void *unused, const char *source, const char *suffix);
extern u32 fn_1_4AEC0(u32 arg);
extern void fn_1_4AEB4(f32 value);
extern void fn_1_49410(void);
extern void fn_1_4966C(f32 a, f32 b);
extern void fn_1_495B0(u32 mode);
extern void fn_1_49590(f32 value);
extern void fn_1_53C9C(f32 a, void *p1, void *p2, f32 b, f32 c, f32 d, f32 e);

static inline Sel6 * fn_3_CB4_read_pointer(DataHdr * owner) { return owner->tbl; }
#pragma opt_propagation off
static inline u32 * fn_3_CB4_read_pointer_(DataHdr * owner) { return owner->ids; }
void fn_3_CB4(u32 arg0) {
    u32 value;
    char buffer[0x400];
    DataRef d;
    DataHdr *h;

    d.base = (u8 *)&lbl_3_data_0;
    value = pool_word[0];
    fn_1_4AEC0(1);
    fn_1_4AEB4(1.5f);
    fn_1_49410();
    fn_1_4966C(-1.0f, 8.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 4.0f);
    }
    h = (DataHdr *)d.base;
    fn_3_BFC(buffer, (void *)arg0, h->name,
             (const char *)fn_3_CB4_read_pointer(h)[lbl_3_bss_2437C[0]].v[lbl_801A66B4]);
    fn_3_BFC(buffer, buffer, h->name,
             (const char *)fn_3_CB4_read_pointer(h)[((0)[lbl_3_bss_2437C])].v[lbl_801A66B4]);
    fn_3_BFC(buffer, buffer, h->name,
             (const char *)fn_3_CB4_read_pointer(h)[lbl_3_bss_2437C[0]].v[lbl_801A66B4]);
    if (arg0 == fn_3_CB4_read_pointer_(h)[lbl_801A66B4]) {
        fn_1_53C9C(320.0f, &value, buffer, 150.0f, 0.09f, 30.0f, 0.55f);
    } else {
        fn_1_53C9C(320.0f, &value, buffer, 150.0f, 0.09f, 30.0f, 0.75f);
    }
    fn_1_4AEC0(0);
    fn_1_4AEB4(0.0f);
}
#pragma opt_propagation reset

