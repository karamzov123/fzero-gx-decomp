/* Non-matching: best partial attempt (85.21% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
// Graphics write-gather FIFO register.
extern volatile union { unsigned char u8; unsigned short u16; unsigned long u32; float f32; } WGPIPE;
static inline void GXPosition3f32(float x,float y,float z) { WGPIPE.f32=x; WGPIPE.f32=y; WGPIPE.f32=z; }
static inline void GXTexCoord2f32(float s,float t) { WGPIPE.f32=s; WGPIPE.f32=t; }
#include "rel/main_rel/screen_effect.h"
extern u16 fn_1_A5DB0(void);
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_8003462C(u32, u32, u32);
struct vertex { f32 x,y,z; };
static inline int in_range(f32 f) {
 if (f > 1.0f) return 0;
 if (f < 0.0f) return 0;
 return 1;
}
void fn_1_75D84(struct vertex *coords, s16 *a, s16 *b) {
 s16 x, y;
 s32 height;
 s32 i;
 f32 u[4];
 f32 v[4];
 u[0] = u[3] = (f32)(a[0]-b[0]) / (f32)b[2];
 u[1] = u[2] = (f32)(a[0]+a[2]-b[0]) / (f32)b[2];
 v[0] = v[1] = (f32)((s32)((f32)(a[1]*fn_1_A5DB0()) / 480.0f)-b[1]) / (f32)b[3];
 height = (s32)((f32)(a[3]*fn_1_A5DB0()) / 480.0f);
 v[2] = v[3] = (f32)((s32)((f32)(a[1]*fn_1_A5DB0()) / 480.0f)+height-b[1]) / (f32)b[3];
 for(i=0;i<4;i++) {
  if (!in_range(u[i]) || !in_range(v[i]))
   OSPanic((const char *)lbl_1_data_1DAC0,0x793,(const char *)lbl_1_data_1DB9C);
 }
 fn_8003462C(0x80,0,4);
 x = a[4]; y = a[5];
 GXPosition3f32(coords[0].x+x,coords[0].y+y,0.0f);
 GXTexCoord2f32(u[0],v[0]);
 GXPosition3f32(coords[1].x+x,coords[1].y+y,0.0f);
 GXTexCoord2f32(u[1],v[1]);
 GXPosition3f32(coords[2].x+x,coords[2].y+y,0.0f);
 GXTexCoord2f32(u[2],v[2]);
 GXPosition3f32(coords[3].x+x,coords[3].y+y,0.0f);
 GXTexCoord2f32(u[3],v[3]);
}
