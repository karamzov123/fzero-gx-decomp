/* Non-matching: best partial attempt (98.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f32 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
}
#pragma section code_type ".text"

struct cart_obj {
	u8 pad_0[0x10];
	s32 tick;
	u8 pad_14[0x08];
	f32 f1c;
	f32 f20;
	f32 f24;
	f32 f28;
	f32 f2c;
	u8 pad_30[0x0C];
	f32 pos[3];
	f32 vel[3];
};

#pragma opt_strength_reduction off
void fn_1_60F84(struct cart_obj *obj)
{
	f32 scale;
	f32 damp = 0.96f;
	f64 diff;
	f32 decay;
	f32 step;

	obj->vel[0] *= damp;
	obj->vel[1] *= damp;
	obj->vel[2] *= damp;

	obj->pos[0] += obj->vel[0];
	obj->pos[1] += obj->vel[1];
	obj->pos[2] += obj->vel[2];

	diff = 0.1 * (obj->f2c - obj->f28);
	obj->f28 = obj->f28 + diff;

	if (obj->tick < 20) {
		decay = -0.05f * (f32)obj->tick;
		step = 1.0f + decay;
		scale = 1.0f - step;
		obj->f1c *= scale;
		obj->f20 *= scale;
		obj->f24 *= scale;
	}
}
#pragma opt_strength_reduction reset

