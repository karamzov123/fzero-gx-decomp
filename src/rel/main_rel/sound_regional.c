/* Previously matched Japan/PAL units of sound.c, retained until that TU matches those releases as one unit. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"

extern void *lbl_801A6410;
extern void fn_1_44A4(void);
extern void *fn_80008E84(void *arg);
extern u32 fn_1_45D0(void *arg0, void *arg1, u32 *arg2, int arg3);
extern void fn_1_46B4(u32, void *, void *, u32);
extern s8 lbl_1_bss_6EAA6;
extern u8 lbl_1_bss_6EAA4;
extern void fn_80067974(void);
extern void AXARTServiceSounds(void);
extern void fn_80026FE0(void);
extern u8 lbl_1_bss_6EAA8[8];
extern u8 lbl_1_bss_6EAB0;
extern void ARInit(u8 *arg0, int arg1);
extern void ARQInit(void);
extern u8 lbl_1_bss_6F1E1;
extern void fn_1_A2DF4(s32, void *, s32);
extern void fn_1_A2E24(u32 arg0, u32 arg1, s32 arg2);
extern void fn_80008BEC(void *, s32, s32);
extern void fn_1_A0680(void);
extern void fn_80067898(u32);
extern void fn_800674FC(u16 arg0, u32 arg1, s16 arg2);
extern s32 camera_get_mode(void);
extern u8 lbl_1_bss_6F2D8[62];
extern void fn_80067344(s32, s32, u32, s32);
extern void fn_1_A5470(s32 value);
extern u32 fn_1_3F13C(void);
extern u32 fn_1_EB0B0(void);
extern s32 fn_1_F1B94(void);
extern u32 lbl_1_rodata_45D0[];
extern u32 lbl_1_rodata_4718[];
extern u32 lbl_1_rodata_4730[];
extern u32 lbl_1_rodata_47A8[];
extern u8 lbl_1_bss_6F41C[260];
extern s32 fn_1_86690(s32 value);
extern const u32 lbl_1_rodata_4820[41];
extern int fn_8004C658(u32 obj);
extern int fn_8004BBCC(u32 obj);
extern void ADXT_Pause(u32 obj, int arg);
extern int fn_1_3FC38(void);

extern void fn_1_A2DF4(s32, void *, s32);
extern void fn_80008BEC(void *, s32, s32);
extern s32 fn_1_86690(s32 value);
extern void fn_80067344(s32 arg0, s32 arg1, u32 arg2, s32 arg3);
extern void fn_80067898(u32 value);
extern const u32 lbl_1_rodata_4820[41];

extern void *lbl_801A6410;
extern void *fn_80008E84();
extern void fn_1_44A4(void);

extern void *lbl_801A6410;
extern void fn_1_44A4(void);
extern void *fn_80008E84();
extern u32 fn_1_45D0(void *arg0, void *arg1, u32 *arg2, int arg3);
extern void fn_80063094(s32 arg0, void *arg1, s32 arg2);
extern void fn_80065D70(int);

/* fzgx:begin fn_1_A2D84 */
void fn_1_A2D84(u32 arg0) {
    if (lbl_1_bss_6F1D8 == 0 && lbl_1_bss_6F1DC <= 0x2D) {
        fn_80067898(arg0);
    }
}
/* fzgx:end fn_1_A2D84 */

/* fzgx:begin fn_1_A2DC4 */
void fn_1_A2DC4(u32 arg0) {
    if (lbl_1_bss_6F1DC <= 0x2D) {
        fn_80067898(arg0);
    }
}
/* fzgx:end fn_1_A2DC4 */
