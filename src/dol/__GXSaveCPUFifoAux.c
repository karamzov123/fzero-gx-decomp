#include <types.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>

typedef struct _GXFifoObj {
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
    u8 field_0x23[93];
} GXFifoObj;

typedef u8 GXBool;

extern u32 *__piReg;

extern u16 *__cpReg;

void GXFlush(void);

extern GXBool lbl_801A6BFC;

void __GXSaveCPUFifoAux(GXFifoObj *fifo) {
    int interrupts = OSDisableInterrupts();
    GXFlush();
    fifo->base = ((void *)((u32)((*(vu32 *)((vu32 *)(__piReg) + (3)))) + (0x8000 << 16)));
    fifo->end = ((void *)((u32)((*(vu32 *)((vu32 *)(__piReg) + (4)))) + (0x8000 << 16)));
    fifo->write_ptr =
        ((void *)((u32)((*(vu32 *)((vu32 *)(__piReg) + (5))) & ~0x4000000) + (0x8000 << 16)));
    if (lbl_801A6BFC != 0) {
        do {
            u32 temp = (*(vu16 *)((vu16 *)(__cpReg) + (29))) << 16;
            temp |= (*(vu16 *)((vu16 *)(__cpReg) + (28)));
            fifo->read_ptr = ((void *)((u32)(temp) + (0x8000 << 16)));
        } while (0);
        do {
            u32 temp = (*(vu16 *)((vu16 *)(__cpReg) + (25))) << 16;
            temp |= (*(vu16 *)((vu16 *)(__cpReg) + (24)));
            fifo->rw_dst = temp;
        } while (0);
    } else {
        fifo->rw_dst = (u32)fifo->write_ptr - (u32)fifo->read_ptr;
        if (fifo->rw_dst < 0) {
            fifo->rw_dst += fifo->size;
        }
    }
    OSRestoreInterrupts(interrupts);
}
