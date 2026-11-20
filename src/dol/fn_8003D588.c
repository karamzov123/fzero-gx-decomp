#include "types.h"

struct fn_8003D588___memReg_T {
    u8 pad_0[0x32];
    u16 unk_32[20];
};

extern struct fn_8003D588___memReg_T *__memReg;
extern void GXReadXfRasMetric(u32 *, u32 *, u32 *, u32 *);

#pragma opt_propagation off
void fn_8003D588(u32 arg0, u32 arg1) {
    u32 v0 = arg0 + (arg1 << 2);
    u16 *s;

    GXReadXfRasMetric((u32 *)(v0 + 0x90), (u32 *)(v0 + 0x98), (u32 *)(v0 + 0xA0), (u32 *)(v0 + 0xA8));
    s = (u16 *)__memReg;
    {
        u16 hi = (*((25) + s));
        u16 lo = (*((26) + s));
        *(u32 *)(v0 + 0x40) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((27) + s));
        u16 lo = (*((28) + s));
        *(u32 *)(v0 + 0x48) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((29) + s));
        u16 lo = (*((30) + s));
        *(u32 *)(v0 + 0x50) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((31) + s));
        u16 lo = (*((32) + s));
        *(u32 *)(v0 + 0x58) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((33) + s));
        u16 lo = (*((34) + s));
        *(u32 *)(v0 + 0x60) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((35) + s));
        u16 lo = (*((36) + s));
        *(u32 *)(v0 + 0x68) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((37) + s));
        u16 lo = (*((38) + s));
        *(u32 *)(v0 + 0x70) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    {
        u16 hi = (*((39) + s));
        u16 lo = (*((40) + s));
        *(u32 *)(v0 + 0x78) = ((u32)hi << 16) | lo;
    }
    s = (u16 *)__memReg;
    *(u32 *)(v0 + 0x80) = (u32)(*((42) + (s))) | ((u32)(*((41) + (s))) << 16);
    s = (u16 *)__memReg;
    *(u32 *)(v0 + 0x88) = ((u32)(*((43) + (s))) << 16) | (u32)(*((44) + (s)));
}
#pragma opt_propagation reset

