/* Non-matching: best partial attempt (71.49% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80068BFC_lbl_801A6C80_T {
    u8 pad_0[0x100];
    u32 unk_100;
    u32 unk_104;
    u8 pad_108[0x8C];
    u32 unk_194;
    u8 pad_198[0x8];
    u32 unk_1A0;
    u32 unk_1A4;
    u32 unk_1A8;
    u32 unk_1AC;
    u8 pad_1B0[0x8C];
    u32 unk_23C;
    u8 pad_240[0x214];
    u32 unk_454;
};

typedef void (*Sig_ARQPostRequest_ARQCallback)(u32);
typedef struct Sig_ARQPostRequest_ARQRequest {
    struct Sig_ARQPostRequest_ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    Sig_ARQPostRequest_ARQCallback callback;
} Sig_ARQPostRequest_ARQRequest;

extern u8 lbl_80193B48[];
extern u8 lbl_80193B28[];
extern u32 lbl_801A7328;
extern u32 lbl_801A6C78;
extern u32 lbl_801A6C7C;
extern struct fn_80068BFC_lbl_801A6C80_T *lbl_801A6C80;
extern u32 lbl_801A6410;
extern u32 lbl_801A7348;
extern void fn_80067F68(void);
extern void fn_800631EC(void);
extern u32 fn_8001E954(u32);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern u32 fn_80008E34(u32, u32);
extern void ARQPostRequest(Sig_ARQPostRequest_ARQRequest *, u32, u32, u32, u32, u32, u32, Sig_ARQPostRequest_ARQCallback);
extern void fn_80065AD0(u32);
extern void fn_80065AC4(u32);
extern void fn_800211E0(u32, u32);
extern void fn_800211EC(u32, u32);
s32 fn_80068BFC(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 interrupt;
    u32 buffer;
    u32 *words;
    u32 i;

    lbl_801A6C78 = 0;
    lbl_801A6C7C = 0;
    lbl_801A6C80 = (struct fn_80068BFC_lbl_801A6C80_T *)lbl_80193B48;
    fn_80067F68();
    fn_800631EC();
    if (arg1 == 0) {
        return -1;
    }
    if (arg2 == 0) {
        return -2;
    }
    lbl_801A6C80->unk_194 = arg1;
    lbl_801A6C80->unk_23C = arg2 - 0x21E0;
    lbl_801A6C80->unk_454 = arg0;
    if (arg0 != 0) {
        if (arg3 == 0) {
            return -3;
        }
        if (arg4 == 0) {
            return -4;
        }
        lbl_801A6C80->unk_1A0 = arg4;
        lbl_801A6C80->unk_1A4 = arg4;
        lbl_801A6C80->unk_100 = arg3;
    } else {
        lbl_801A6C80->unk_1A0 = fn_8001E954(arg2);
        lbl_801A6C80->unk_1A4 = lbl_801A6C80->unk_1A0;
        interrupt = OSDisableInterrupts();
        lbl_801A6C80->unk_100 = fn_80008E34(lbl_801A6410, arg1);
        OSRestoreInterrupts(interrupt);
    }
    interrupt = OSDisableInterrupts();
    buffer = fn_80008E34(lbl_801A6410, 0x100);
    OSRestoreInterrupts(interrupt);
    memset(buffer, 0, 0x100);
    lbl_801A6C7C = 1;
    ARQPostRequest((Sig_ARQPostRequest_ARQRequest *)lbl_80193B28, 0, 0, 1, buffer, lbl_801A6C80->unk_1A4, 0x100, fn_80065AD0);
    while (lbl_801A6C7C != 0) {
    }
    lbl_801A6C7C = 1;
    ARQPostRequest((Sig_ARQPostRequest_ARQRequest *)lbl_80193B28, 0, 0, 1, lbl_801A7348, lbl_801A6C80->unk_1A4 + 0x100, 0x20E0, fn_80065AC4);
    while (lbl_801A6C7C != 0) {
    }
    lbl_801A6C80->unk_1AC = lbl_801A6C80->unk_1A4 + 0x21E0;
    lbl_801A6C80->unk_1A8 = lbl_801A6C80->unk_1A4 + 0x100;
    lbl_801A6C80->unk_104 = lbl_801A6C80->unk_100;
    fn_800211E0(0, 0);
    fn_800211EC(0, 0);
    return 0;
}
