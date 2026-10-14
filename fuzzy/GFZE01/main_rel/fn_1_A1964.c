/* Non-matching: best partial attempt (95.56% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"
extern char lbl_1_rodata_42FC[42];
extern const f32 lbl_1_rodata_42E0;
extern const f32 lbl_1_rodata_42E4;
extern const f32 lbl_1_rodata_42E8;
extern void fn_8004D18C(u32, u32);
extern u32 fn_8004BF0C(u32, u32);
typedef struct {
 u8 pad0[0x1c]; u32 flags; u8 pad20[4]; f32 rate[2];
 u8 track; u8 pad2d[0xb]; u32 *handles; u8 pad3c[0x846];
 u8 busy; u8 pad883; s16 volume[2]; f32 fade[2];
} SoundState;
static inline void set_fade_impl(SoundState *s, f32 rate, s16 volume, u32 channel) {
 s->rate[channel] = rate;
 s->fade[channel] = (f32)volume;
}
#define set_fade(s,v,r,c) do { f32 speed = (r); f32 converted = (f32)(v); (s)->rate[c] = speed; (s)->fade[c] = converted; } while (0)
#pragma opt_propagation off
static inline void set_volume(s16 *volumes, u32 channel, s16 volume) {
 struct { s16 *p; } dest;
 dest.p = volumes;
 dest.p[channel] = volume;
}
#pragma opt_propagation off
static inline void setup(s32 h, u32 *handles, SoundState *s, u8 id) {
 u32 flags;
 s16 *volumes = s->volume;
 if (h == handles[0]) {
  flags = s->flags; s->flags = flags & ~4;
  if (flags & 1) volumes[0] = ((s16 *)&lbl_1_data_2D93C)[id];
  else {
   set_fade(s, ((s16 *)&lbl_1_data_2D93C)[id], lbl_1_rodata_42E0, 0);
  }
 }
 if (h == handles[1]) {
  flags = s->flags; s->flags = flags & ~8;
  if (flags & 2) set_volume(volumes, 1, ((s16 *)&lbl_1_data_2D93C)[id]);
  else {
   set_fade(s, ((s16 *)&lbl_1_data_2D93C)[id], lbl_1_rodata_42E4, 1);
  }
 }
 fn_8004D18C(h, ((u32 *)&lbl_1_data_2D7B8)[id]);
 flags = s->flags;
 if (flags & 3) {
  if (flags & 1) s->fade[0] = lbl_1_rodata_42E8;
  if (flags & 2) s->fade[1] = lbl_1_rodata_42E8;
  fn_8004BF0C(h, -400);
 } else fn_8004BF0C(h, ((s16 *)&lbl_1_data_2D93C)[id]);
 s->track = id;
}
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_propagation off
void fn_1_A1964(u8 arg) {
 SoundState *s = (SoundState *)&lbl_1_bss_6EA98;
 u32 *handles = s->handles;
 s8 id;
 u32 h;
 if (!handles) return;
 if (arg >= 41) id = -1;
 else id = lbl_1_rodata_42FC[arg];
 if (id == -1) {
  h = handles[0];
  if (!s->busy && h != 0 && h != -1) setup(h, handles, s, 66);
 } else {
  h = handles[0];
  if (!s->busy && h != 0 && h != -1) setup(h, handles, s, (u8)id);
 }
}
#pragma opt_propagation reset
#pragma opt_strength_reduction reset
#pragma opt_loop_invariants reset
