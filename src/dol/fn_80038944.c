#include "types.h"

typedef struct GXFifoObj {
    void *base;
    void *end;
    u32 size;
    u32 high_wtrmark;
    u32 low_wtrmark;
    void *read_ptr;
    void *write_ptr;
    s32 rw_dst;
    u8 fifo_wrap;
    u8 cpu_fifo_ready;
    u8 gp_fifo_ready;
    u8 pad_0x23;
} GXFifoObj;

typedef struct GXData {
    u16 unk_000;
    u16 bp_sent_not;
    u32 unk_004;
    u32 unk_008;
    u8 pad_00C[0x4e4];
    u8 field_0x4f0;
    u8 field_0x4f1;
    u16 pad_0x4f2;
    u32 dirty_state;
} GXData;

typedef struct FifoBackup {
    GXFifoObj fifo;
    GXData gx;
    u32 pad_51C;
} FifoBackup;

FifoBackup lbl_801783A0;
extern GXData *const gx;
extern volatile u32 *__piReg; // fzgx-allow: S2 layout primer sink: MWCC emits the literal pool in first-access order
extern void *lbl_801A6C28;
extern void fn_8003458C(void);
extern void __GXSaveCPUFifoAux(void *);
extern void GXSetCPUFifo(void *);
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32 enabled);
extern void *memcpy(void *dest, const void *src, u32 n);

s32 fn_80038944(void) {
    u32 flag;
    s32 enabled;
    u32 saved;

    if (gx->dirty_state != 0) {
        fn_8003458C();
    }
    flag = (__piReg[5] >> 26) & 1;
    __GXSaveCPUFifoAux(&lbl_801783A0);
    GXSetCPUFifo(lbl_801A6C28);
    if (gx->field_0x4f1 != 0) {
        enabled = OSDisableInterrupts();
        saved = gx->unk_008;
        memcpy(gx, &lbl_801783A0.gx, sizeof(GXData));
        gx->unk_008 = saved;
        OSRestoreInterrupts(enabled);
    }
    gx->field_0x4f0 = 0;
    if (flag == 0) {
        return lbl_801783A0.fifo.rw_dst;
    }
    return 0;
}
