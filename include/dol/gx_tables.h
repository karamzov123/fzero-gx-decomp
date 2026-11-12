#ifndef DOL_GX_TABLES_H
#define DOL_GX_TABLES_H

#include "types.h"

/* The Dolphin SDK render-mode descriptor (60 bytes). The enum fields of the SDK type
 * (VITVMode, VIXFBMode, GXBool) are spelled with their storage width here. */
typedef struct {
    u32 viTVmode;             /* 0x00 */
    u16 fbWidth;              /* 0x04 */
    u16 efbHeight;            /* 0x06 */
    u16 xfbHeight;            /* 0x08 */
    u16 viXOrigin;            /* 0x0A */
    u16 viYOrigin;            /* 0x0C */
    u16 viWidth;              /* 0x0E */
    u16 viHeight;             /* 0x10 */
    u32 xFBmode;              /* 0x14 */
    u8 field_rendering;       /* 0x18 */
    u8 aa;                    /* 0x19 */
    u8 sample_pattern[12][2]; /* 0x1A */
    u8 vfilter[7];            /* 0x32 */
} GXRenderModeObj;

extern GXRenderModeObj lbl_8012B0E4; /* 640x480 render mode, TV mode 0x14 */

/* GXTev.c's TEV operation tables, laid out back to back; GXSetTevOp indexes them by
 * GXTevMode for stage 0 and for the other stages. */
typedef struct {
    u32 TEVCOpTableST0[5];
    u32 TEVCOpTableST1[5];
    u32 TEVAOpTableST0[5];
    u32 TEVAOpTableST1[5];
} GXTevData;

extern GXTevData lbl_8012B368;

#endif
