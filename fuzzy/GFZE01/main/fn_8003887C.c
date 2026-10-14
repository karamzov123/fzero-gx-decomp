/* Non-matching: best partial attempt (97.78% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 field_00[5];
    u32 field_14;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u8 field_24[0x4f8];
} GXFifoContext;

extern u32 lbl_801783A0[328];
extern u32 *gx;
extern u32 fn_80032360(void);
extern void fn_8003458C(void);
extern u32 fn_80031FF4(u32);
extern u32 lbl_801A6C28[2];
extern u32 GXSetCPUFifo(u32);

void fn_8003887C(u16 *arg0, u8 *arg1) {
    struct { GXFifoContext *value; } fifo;
    u32 result;
    fifo.value = (GXFifoContext *)lbl_801783A0;
    result = fn_80032360();

    if (gx[0x13d] != 0) {
        fn_8003458C();
    }

    if (((u8 *)gx)[0x4f1] != 0) {
        memcpy(fifo.value->field_24, gx, 0x4f8);
    }

    fifo.value->field_00[0] = (u32)arg0;
    fifo.value->field_00[1] = (u32)(arg0 + (u32)(arg1 - 4));
    fifo.value->field_00[2] = (u32)arg1;
    fifo.value->field_1c = 0;
    fifo.value->field_14 = (u32)arg0;
    fifo.value->field_18 = (u32)arg0;
    ((u8 *)gx)[0x4f0] = 1;

    fn_80031FF4(result);
    lbl_801A6C28[0] = result;
    GXSetCPUFifo((u32)fifo.value);
}
