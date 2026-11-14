#include "types.h"
typedef struct PadStatus {
 u16 unk_0;
 u8 unk_2;
 s8 unk_3;
 u8 pad_4[5];
 s8 unk_9;
} PadStatus;
typedef struct Calibration {
 u8 pad_0[3];
 s8 unk_3;
 u8 pad_4[9];
 s8 unk_D;
 u8 pad_E[9];
 s8 unk_17;
 u8 pad_18[6];
 PadStatus unk_1E;
} Calibration;
extern void fn_8006AA44(PadStatus *, PadStatus *, Calibration *);
extern u32 fn_8006AC44(PadStatus *, PadStatus *, Calibration *);
static inline s8 fn_8006AE90_scale(s8 value, s8 *min, s8 *max, s8 dead) {
 s32 lo;
 s32 hi;
 s32 range;
 s32 result;
 lo=*min;
 hi=*max;
 if(value<lo) {*min=value; lo=value;}
 if(value>hi) {hi=value; *max=value;}
 range=hi-lo-dead*2;
 if(range==0) range=1;
 result=(value-(lo+dead))*255/range-127;
 if(result < -128) result=-128;
 if(result > 127) result=127;
 return result;
}
void fn_8006AE90(PadStatus *arg0, PadStatus *arg1, Calibration *arg2) {
 arg0->unk_3=fn_8006AE90_scale(arg1->unk_3,&arg2->unk_3,&arg2->unk_D,arg2->unk_17);
 fn_8006AA44(arg0,arg1,arg2);
 fn_8006AC44(arg0,arg1,arg2);
 arg0->unk_0=arg1->unk_0;
 arg0->unk_2=arg1->unk_2;
 arg2->unk_1E=*arg1;
 arg0->unk_9=0;
}
