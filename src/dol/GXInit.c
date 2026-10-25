#include "dolphin/types.h"
#include "dolphin/os/OSReset.h"
struct Sig_GXInitFifoBase_GXInitFifoBase_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x10];
    u32 unk_1C;
};
typedef struct Sig_GXSetGPFifo__GXFifoObj {
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
} Sig_GXSetGPFifo_GXFifoObj;
typedef struct Sig_GXInitTexCacheRegion_GXTexRegion {
    u32 tmem_even;
    u32 tmem_odd;
    u8 pad_08[4];
    u8 enable;
    u8 is_32bit;
} Sig_GXInitTexCacheRegion_GXTexRegion;
struct Sig_GXInitTlutRegion_GXInitTlutRegion_Arg0 {
    u32 unk_0;
};
struct GXInit_TlutSlot {
    struct Sig_GXInitTlutRegion_GXInitTlutRegion_Arg0 region;
    u8 pad_4[12];
};
struct GXInit_gx_T {
    u8 pad_0[0x1C];
    u32 unk_1C[8];
    u32 unk_3C[8];
    u8 pad_5C[0x20];
    u32 unk_7C;
    u8 pad_80[0x38];
    u32 unk_B8[8];
    u32 unk_D8[8];
    u32 unk_F8;
    u32 unk_FC;
    u32 unk_100[8];
    u32 unk_120;
    u32 unk_124;
    u8 pad_128[8];
    u32 unk_130[16];
    u32 unk_170[16];
    u32 unk_1B0[8];
    u32 unk_1D0;
    u32 unk_1D4;
    u32 unk_1D8;
    u32 unk_1DC;
    u8 pad_1E0[0x1C];
    u32 unk_1FC;
    u32 unk_200;
    u32 unk_204;
    Sig_GXInitTexCacheRegion_GXTexRegion texRegions[8];
    Sig_GXInitTexCacheRegion_GXTexRegion texRegions2[4];
    u8 pad_2C8[8];
    struct GXInit_TlutSlot tlutRegions[20];
    u8 pad_410[0x8C];
    u32 unk_49C[16];
    u32 unk_4DC;
    u32 unk_4E0;
    u8 pad_4E4[0x8];
    u32 unk_4EC;
    u8 unk_4F0;
    u8 unk_4F1;
    u8 unk_4F2;
    u8 unk_4F3;
    u32 unk_4F4;
};
struct GXInit___cpReg_T {
    u8 pad_0[0x6];
    u16 unk_6;
};
struct GXInitStorage {
    struct GXInit_gx_T state;
    Sig_GXSetGPFifo_GXFifoObj fifo;
};
extern struct GXInit___cpReg_T *__cpReg;
extern struct GXInit_gx_T * const gx;
extern u32 GXResetFuncInfo_8012AD30[];
extern u32 GXSetCPUFifo(u32);
extern u32 PPCMfhid2(void);
extern u32 __GXFifoInit(void);
extern u32 __GXInitGX(void);
extern u32 __GXVersion;
extern u32 __memReg;
extern u32 __peReg;
extern u32 __piReg;
extern u8 gxData_80177BA0[];
extern void GXInitFifoBase(struct Sig_GXInitFifoBase_GXInitFifoBase_Arg0 *, u32, u32);
extern void GXInitTexCacheRegion(Sig_GXInitTexCacheRegion_GXTexRegion *, u8, u32, s32, u32, s32);
extern void GXInitTlutRegion(struct Sig_GXInitTlutRegion_GXInitTlutRegion_Arg0 *, u32, u32);
extern void GXSetGPFifo(Sig_GXSetGPFifo_GXFifoObj *);
extern void GXSetMisc(u32, u32);
extern void OSRegisterResetFunction(OSResetFunctionInfo *);
extern void OSRegisterVersion(const char *);
extern void PPCMthid2(u32);
extern void PPCMtwpar(u32);
extern void __GXFlushTextureState(void);
extern void __GXPEInit(void);
extern void __GXSetTmemConfig(u32);
extern vu32 __MEMRegs[];
__declspec(section ".data") extern const u32 __OSBusClock;
extern vu32 __PIRegs[];
extern vu32 __CPRegs[];
#define GX_FIFO_U8 (*(volatile u8 *)0xCC008000) /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
#define GX_FIFO_U32 (*(volatile u32 *)0xCC008000) /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
#pragma peephole off
void * GXInit(u32 arg0, u32 arg1, u32 arg2) {
    static u32 resetFuncRegistered;
    u8 *p_gxData_80177BA0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v4;
    s32 v11;
    u32 v5;
    u32 v6;
    u32 v12;
    u32 v30;
    s32 v34;
    s32 v66;
    u32 v63;
    u32 v65;
    s32 v88;
    s32 v94;
    s32 v101;
    s32 v106;
    u32 v109;
    u32 v110;
    u32 v111;
    u32 t8;
    p_gxData_80177BA0 = (u8 *)&gxData_80177BA0;
    OSRegisterVersion((const char *)__GXVersion);
    gx->unk_4F0 = 0;
    gx->unk_4F1 = 1;
    gx->unk_4F2 = 1;
    gx->unk_4DC = 0;
    gx->unk_4E0 = 0;
    GXSetMisc(1, 0);
    v0 = 0xCC000000; /* fzgx-allow: A1,A2 OSPhysicalToUncached(0x0C000000), as in the SDK */
    __piReg = 0xCC003000; /* fzgx-allow: A1,A2 OSPhysicalToUncached(0x0C003000) */
    __cpReg = (struct GXInit___cpReg_T *)0xCC000000; /* fzgx-allow: A1,A2 OSPhysicalToUncached(0x0C000000) */
    __peReg = 0xCC001000; /* fzgx-allow: A1,A2 OSPhysicalToUncached(0x0C001000) */
    __memReg = 0xCC004000; /* fzgx-allow: A1,A2 OSPhysicalToUncached(0x0C004000) */
    __GXFifoInit();
    GXInitFifoBase((struct Sig_GXInitFifoBase_GXInitFifoBase_Arg0 *)(p_gxData_80177BA0 + 1272), arg0, arg1);
    GXSetCPUFifo((u32)p_gxData_80177BA0 + 1272);
    GXSetGPFifo((Sig_GXSetGPFifo_GXFifoObj *)((u32)&gxData_80177BA0 + 1272));
    if (resetFuncRegistered == 0) {
        OSRegisterResetFunction((OSResetFunctionInfo *)&GXResetFuncInfo_8012AD30);
        resetFuncRegistered = 1;
    }
    __GXPEInit();
    t8 = PPCMfhid2();
    PPCMtwpar((0xC010000 + -32768));
    PPCMthid2((t8 | 0x40000000));
    gx->unk_204 = 0;
    v4 = ((u32)gx + 516);
    v5 = ((u32)gx + 292);
    v6 = ((u32)gx + 124);
    *(u32 *)v4 = (*(u32 *)v4 & 0xFFFFFF);
    gx->unk_124 = 255;
    *(u32 *)v5 = ((*(u32 *)v5 & 0xFFFFFF) | 0xF000000);
    gx->unk_7C = 0;
    *(u32 *)v6 = ((*(u32 *)v6 & 0xFFFFFF) | 0x22000000);
    for (v11 = 0; (u32)v11 < 16; v11++) {
        gx->unk_130[v11] = 0;
        gx->unk_170[v11] = 0;
        gx->unk_100[(u32)v11 >> 1] = 0;
        gx->unk_49C[v11] = 255;
        gx->unk_130[v11] = (gx->unk_130[v11] & 0xFFFFFF) | ((0xC0 + v11 * 2) << 24);
        gx->unk_170[v11] = (gx->unk_170[v11] & 0xFFFFFF) | ((0xC1 + v11 * 2) << 24);
        gx->unk_1B0[(u32)v11 >> 1] = (gx->unk_1B0[(u32)v11 >> 1] & 0xFFFFFF) | ((((u32)v11 >> 1) + 0xF6) << 24);
        gx->unk_100[(u32)v11 >> 1] = (gx->unk_100[(u32)v11 >> 1] & 0xFFFFFF) | ((((u32)v11 >> 1) + 0x28) << 24);
    }
    gx->unk_120 = 0;
    v30 = ((u32)gx + 288);
    *(u32 *)v30 = ((*(u32 *)v30 & 0xFFFFFF) | 0x27000000);
    for (v34 = 0; (u32)v34 < 8; v34++) {
        gx->unk_B8[v34] = 0;
        gx->unk_D8[v34] = 0;
        gx->unk_B8[v34] = (gx->unk_B8[v34] & 0xFFFFFF) | ((0x30 + v34 * 2) << 24);
        gx->unk_D8[v34] = (gx->unk_D8[v34] & 0xFFFFFF) | ((0x31 + v34 * 2) << 24);
    }
    gx->unk_F8 = (gx->unk_F8 & 0xFFFFFF) | 0x20000000;
    gx->unk_FC = (gx->unk_FC & 0xFFFFFF) | 0x21000000;
    gx->unk_1D0 = (gx->unk_1D0 & 0xFFFFFF) | 0x41000000;
    gx->unk_1D4 = (gx->unk_1D4 & 0xFFFFFF) | 0x42000000;
    gx->unk_1D8 = (gx->unk_1D8 & 0xFFFFFF) | 0x40000000;
    gx->unk_1DC = (gx->unk_1DC & 0xFFFFFF) | 0x43000000;
    v63 = (u32)gx + 508;
    *(u32 *)v63 = *(u32 *)v63 & 0xFFFFFE7F;
    gx->unk_4F4 = 0;
    gx->unk_4F3 = 0;
    v65 = *(u32 *)0x800000F8 / 500; /* fzgx-allow: A1,A2 __OSBusClock lowmem global */
    __GXFlushTextureState();
    GX_FIFO_U8 = 97;
    GX_FIFO_U32 = (v65 >> 11) | 0x69000400;
    __GXFlushTextureState();
    GX_FIFO_U8 = 97;
    GX_FIFO_U32 = (v65 / 4224) | 0x46000200;
    for (v11 = 0; (u32)v11 < 8; v11++) {
        gx->unk_1C[v11] = (gx->unk_1C[v11] & 0xBFFFFFFF) | 0x40000000;
        gx->unk_3C[v11] = (gx->unk_3C[v11] & 0x7FFFFFFF) | 0x80000000;
        GX_FIFO_U8 = 8;
        GX_FIFO_U8 = v11 | 0x80;
        GX_FIFO_U32 = gx->unk_3C[v11];
    }
    GX_FIFO_U8 = 16;
    GX_FIFO_U32 = 4096;
    GX_FIFO_U32 = 63;
    GX_FIFO_U8 = 16;
    GX_FIFO_U32 = 4114;
    GX_FIFO_U32 = 1;
    GX_FIFO_U8 = 97;
    GX_FIFO_U32 = 0x5800000F;
    for (v88 = 0; (u32)v88 < 8; v88++) {
        GXInitTexCacheRegion(&gx->texRegions[v88], 0, v88 << 15, 0, (v88 << 15) + 0x80000, 0);
    }
    for (v94 = 0; (u32)v94 < 4; v94++) {
        GXInitTexCacheRegion(&gx->texRegions2[v94], 0, (v94 * 2 + 8) << 15, 0, (v94 * 2 + 9) << 15, 0);
    }
    for (v101 = 0; (u32)v101 < 16; v101++) {
        GXInitTlutRegion(&gx->tlutRegions[v101].region, (v101 << 13) + 0xC0000, 16);
    }
    for (v106 = 0; (u32)v106 < 4; v106++) {
        GXInitTlutRegion(&gx->tlutRegions[v106 + 16].region, (v106 << 15) + 0xE0000, 64);
    }
    __cpReg->unk_6 = 0;
    v110 = (u32)gx + 1260;
    *(u32 *)v110 = *(u32 *)v110 & 0xFFFFFF0F;
    GX_FIFO_U8 = 8;
    GX_FIFO_U8 = 32;
    GX_FIFO_U32 = gx->unk_4EC;
    GX_FIFO_U8 = 16;
    GX_FIFO_U32 = 4102;
    GX_FIFO_U32 = 0;
    GX_FIFO_U8 = 97;
    GX_FIFO_U32 = 0x23000000;
    GX_FIFO_U8 = 97;
    GX_FIFO_U32 = 0x24000000;
    GX_FIFO_U8 = 97;
    GX_FIFO_U32 = 0x67000000;
    __GXSetTmemConfig(0);
    __GXInitGX();
    return ((u8 *)(u32)p_gxData_80177BA0 + 1272);
}
#pragma peephole reset
