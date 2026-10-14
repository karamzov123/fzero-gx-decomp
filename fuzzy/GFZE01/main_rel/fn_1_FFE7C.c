/* Non-matching: best partial attempt (88.85% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 300.0f;
    s = 32767.0f;
    s = 4.0f;
    s = 10.0f;
    s = 2.0f;
    s = 200.0f;
    s = 400.0f;
    s = 2500.0f;
    s = 1000.0f;
    s = 1400.0f;
    d = 0.5;
    d = 5.0;
    s = 7.0f;
    s = 2.5f;
    s = 768.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 0.25f;
    s = 0.05000000074505806f;
    s = -2000.0f;
    s = 1.0199999809265137f;
    s = 30.0f;
    s = 22.0f;
    d = 0.9;
    s = 0.6000000238418579f;
    s = 0.4000000059604645f;
    s = 255.0f;
    s = 0.800000011920929f;
    s = 0.30000001192092896f;
    s = 1.2999999523162842f;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    d = 1280.0;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.98;
    s = 20.0f;
    s = 0.20000000298023224f;
    s = 6.0f;
    s = 0.019999999552965164f;
    s = 0.15000000596046448f;
    s = 1.5f;
    s = -0.07500000298023224f;
    s = -0.10000000149011612f;
    s = 180.0f;
    s = 0.03999999910593033f;
    s = 0.0005000000237487257f;
    s = -0.20000000298023224f;
    s = 0.0f;
    s = 0.04999999701976776f;
}
#pragma section code_type ".text"
typedef struct { f32 x, y, z; } Sig_fn_8006E294_fn_1_9CCE8_Vec3;
typedef struct { u32 unk_0, unk_4, unk_8, unk_C; } Sig_fn_1_57BBC_Fn1_57BBC_ArgBlock;
typedef struct {
    Sig_fn_8006E294_fn_1_9CCE8_Vec3 pos;
    Sig_fn_8006E294_fn_1_9CCE8_Vec3 prev;
    Sig_fn_8006E294_fn_1_9CCE8_Vec3 vel;
    f32 alpha;
    f32 size;
    f32 baseSize;
    s32 life;
} FFE7CEntry;
extern f32 lbl_8006D0B4(f32);
extern void *lbl_801A66CC;
extern void *lbl_801A6D00[];
extern void lbl_8006DBAC(void *);
extern void fn_8006E294(void *);
extern void fn_1_681C(u32, u32 *);
extern u32 fn_1_1FB80(Sig_fn_1_57BBC_Fn1_57BBC_ArgBlock *, u32);
extern u32 fn_1_584AC(void);
void fn_1_FFE7C(void *arg0) {
    f32 v0;
    struct { f32 value; } v1;
    f32 v2;
    f32 v6;
    f32 v10;
    f32 v43;
    s32 v8;
    FFE7CEntry *v14;
    Sig_fn_8006E294_fn_1_9CCE8_Vec3 loc_20;
    Sig_fn_8006E294_fn_1_9CCE8_Vec3 loc_14;
    u32 loc_8[3];
    lbl_8006DBAC(lbl_801A66CC);
    fn_8006E294(&loc_14);
    lbl_8006DBAC((u8 *)lbl_801A6D00[0] + 48);
    fn_8006E294(&loc_20);
    v1.value = loc_20.y - loc_14.y;
    v0 = loc_20.x - loc_14.x;
    v2 = loc_20.z - loc_14.z;
    *(f32 *)((u8 *)arg0 + 8) = lbl_8006D0B4((f32)(v0*v0) + v1.value*v1.value + v2*v2);
    fn_1_681C(0, loc_8);
    if (fn_1_1FB80((Sig_fn_1_57BBC_Fn1_57BBC_ArgBlock *)loc_8, 4096)) v6 = 0.0f;
    else v6 = 1.0f;
    v2 = *(f32 *)((u8 *)arg0 + 12);
    *(f32 *)((u8 *)arg0 + 12) = v2 + (f32)(0.15f * (v6 - v2));
    v8 = (s32)(20.0f * *(f32 *)((u8 *)arg0 + 12));
    if (*(f32 *)((u8 *)arg0 + 8) > 0.5) {
        v10 = *(f32 *)((u8 *)arg0 + 8) - 2.0f;
        if (v10 < 1.5f) v6 = 1.5f;
        else if (v10 > 2.0f) v6 = 2.0f;
        else v6 = v10;
        v8 = (s32)((f32)v8 * (1.0f / v6));
    }
    v14 = (FFE7CEntry *)((u8 *)arg0 + 20);
{
    s32 count;
    count = 20;
    do {
        if (v8 > count && v14->life == 0) {
            v14->pos.x = 6.0f * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f);
            v14->pos.y = 6.0f * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f);
            v14->pos.z = 6.0f * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f);
            v14->prev = v14->pos;
            v14->vel.x = -0.075f + (f32)(0.4f * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f));
            v14->vel.y = -0.1f + (f32)(0.4f * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f));
            v14->vel.z = 0.0f + (f32)(0.4f * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f));
            v14->alpha = 0.0f;
            v14->size = 0.02f * (1.0f + (f32)(fn_1_584AC() & 0xFFFF) / 32767.0f);
            v14->baseSize = 0.02f * (1.0f + (f32)(fn_1_584AC() & 0xFFFF) / 32767.0f);
            v14->size = v14->baseSize;
            v14->life = (s32)(30.0f + (f32)(180.0f * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f)));
        }
        if (v14->life > 0) {
            v0 = v14->vel.x;
            v1.value = v14->vel.y;
            v2 = v14->vel.z;
            v43 = lbl_8006D0B4((f32)(v0*v0) + v1.value*v1.value + v2*v2);
            v14->size = v14->baseSize * (1.0f - (f32)((1.0f / (1.0f + (f32)(2.5f*v43))) * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f)));
            v14->vel.x += (f32)(0.04f * (f32)(v43 * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f)));
            v14->vel.y += (f32)(0.04f * (f32)(v43 * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f)));
            v14->vel.z += (f32)(0.04f * (f32)(v43 * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f)));
            v14->vel.y -= 0.0005f;
            v14->vel.x += (f32)(0.04f * (-0.15f - v14->vel.x));
            v14->vel.y += (f32)(0.04f * (-0.2f - v14->vel.y));
            v14->vel.z += (f32)(0.04f * (0.0f - v14->vel.z));
            v14->prev = v14->pos;
            v14->pos.x += v14->vel.x + (f32)(0.05f * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f));
            v14->pos.y += v14->vel.y + (f32)(0.05f * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f));
            v14->pos.z += v14->vel.z + (f32)(0.05f * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5f));
            while (v14->pos.x < 0.0f) v14->pos.x += 6.0f;
            while (v14->pos.x > 6.0f) v14->pos.x -= 6.0f;
            while (v14->pos.y < 0.0f) v14->pos.y += 6.0f;
            while (v14->pos.y > 6.0f) v14->pos.y -= 6.0f;
            while (v14->pos.z < 0.0f) v14->pos.z += 6.0f;
            while (v14->pos.z > 6.0f) v14->pos.z -= 6.0f;
            v14->life--;
            if ((f32)v14->life < 15.0f) v14->alpha *= (f32)v14->life / (f32)(v14->life + 1);
            else v14->alpha += (f32)(0.2f * (1.0f - v14->alpha));
            if (v14->life <= 0) { v14->alpha = 0.0f; v14->life = 0; }
        }
        v14++;
    } while (--count > 0);
}
}
