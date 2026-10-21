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
#pragma opt_common_subs off
#pragma optimize_for_size on
#pragma load_store_multiple on
#pragma use_lmw_stmw on
void fn_8006AE90(PadStatus *arg0, PadStatus *arg1, Calibration *arg2) {
 s32 out, range, max;
 s32 min;
 s8 deadByte;
 s8 value;
 s32 dead, signedValue;
 value=arg1->unk_3;
 min=arg2->unk_3;
 max=arg2->unk_D;
 deadByte=arg2->unk_17;
 signedValue=value;
 if(signedValue<min) {arg2->unk_3=value; min=signedValue;}
 if(signedValue>max) {max=value; arg2->unk_D=value;}
 dead=deadByte;
 range=max-min-(dead<<1);
 if(range==0) range=1;
 out=(signedValue-(min+dead))*255/range-127;
 if(out < -128) out=-128;
 if(out > 127) out=127;
 arg0->unk_3=out;
 fn_8006AA44(arg0,arg1,arg2);
 fn_8006AC44(arg0,arg1,arg2);
 arg0->unk_0=arg1->unk_0;
 arg0->unk_2=arg1->unk_2;
 arg2->unk_1E=*arg1;
 arg0->unk_9=0;
}
