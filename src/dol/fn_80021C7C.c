#include "types.h"

u32 fzgx_obj_lbl_80160500[2][160];
u32 lbl_80160500__fzgx_offset_500[160];

/* AI/DSP interrupt callbacks read and update these AXOut state variables asynchronously. */
extern volatile u32 lbl_801A6B10;
/* AI/DSP interrupt callbacks update this AXOut state variable asynchronously. */
extern volatile u32 lbl_801A6B2C;
/* AI/DSP interrupt callbacks update this AXOut state variable asynchronously. */
extern volatile u32 lbl_801A6B14;
extern u32 lbl_801A6B20;

extern void DCFlushRange(void *, u32);
extern void fn_80021BB0(void);
extern void fn_80021AB8(void);
extern s32 fn_8001DF00(u32);
extern u32 fn_8002123C(u32, u32);
extern void AIInitDMA(u32, u32);
extern void AIStartDMA(void);

void fn_80021C7C(void) {
    u32 i;
    u32 *p;

    lbl_801A6B10 = 0;
    lbl_801A6B2C = 0;
    p = (u32 *)fzgx_obj_lbl_80160500;
    for (i = 0; i < 320; i++) {
        *p = 0;
        p++;
    }
    DCFlushRange(fzgx_obj_lbl_80160500, sizeof(fzgx_obj_lbl_80160500));
    p = lbl_80160500__fzgx_offset_500;
    for (i = 0; i < 160; i++) {
        *p = 0;
        p++;
    }
    DCFlushRange(lbl_80160500__fzgx_offset_500, sizeof(lbl_80160500__fzgx_offset_500));
    fn_80021BB0();
    fn_8001DF00((u32)fn_80021AB8);
    fn_8002123C((u32)lbl_80160500__fzgx_offset_500, (u32)&fzgx_obj_lbl_80160500[1][0]);
    lbl_801A6B14 = 1;
    lbl_801A6B20 = 0;
    AIInitDMA((u32)&fzgx_obj_lbl_80160500[lbl_801A6B10][0], sizeof(fzgx_obj_lbl_80160500[0]));
    AIStartDMA();
}
