#ifndef DOLPHIN_BASE_PPCARCH_H
#define DOLPHIN_BASE_PPCARCH_H

#include <dolphin/types.h>

/* Gekko special-purpose register numbers (IBM 750CL user manual). */
#define HID0 1008
#define HID2 920
#define L2CR 1017
#define WPAR 921
#define MMCR0 952
#define MMCR1 956
#define PMC1 953
#define PMC2 954
#define PMC3 957
#define PMC4 958
#define GQR0 912
#define GQR1 913
#define GQR2 914
#define GQR3 915
#define GQR4 916
#define GQR5 917
#define GQR6 918
#define GQR7 919
#define DMA_U 922
#define DMA_L 923
#define DBAT3U 542
#define DBAT3L 543

#define HID0_SPD 0x00000200 /* speculative cache access disable */

u32 PPCMfmsr(void);
void PPCMtmsr(u32 newMSR);
u32 PPCMfhid0(void);
void PPCMthid0(u32 newHID0);
u32 PPCMfl2cr(void);
void PPCMtl2cr(u32 newL2cr);
void PPCMtdec(u32 newDec);
void PPCSync(void);
void PPCHalt(void);
void PPCMtmmcr0(u32 newMmcr0);
void PPCMtmmcr1(u32 newMmcr1);
u32 PPCMfpmc1(void);
void PPCMtpmc1(u32 newPmc1);
u32 PPCMfpmc2(void);
void PPCMtpmc2(u32 newPmc2);
u32 PPCMfpmc3(void);
void PPCMtpmc3(u32 newPmc3);
u32 PPCMfpmc4(void);
void PPCMtpmc4(u32 newPmc4);
u32 PPCMffpscr(void);
void PPCMtfpscr(u32 newFPSCR);
u32 PPCMfhid2(void);
void PPCMthid2(u32 newHID2);
u32 PPCMfwpar(void);
void PPCMtwpar(u32 newWPAR);
void PPCDisableSpeculation(void);
void PPCSetFpNonIEEEMode(void);

#endif
