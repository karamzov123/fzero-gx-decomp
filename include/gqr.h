#ifndef GQR_H
#define GQR_H

#include "types.h"

/* Graphics quantization register access as inline-assembly helpers, inlined into the
 * caller (MWCC has no mfspr/mtspr intrinsic: __mfspr compiles to a call). The SDK THP
 * decoder's __THPGQRSetup/__THPGQRRestore are written the same way. Retail main's image
 * decoder (fn_8003CBB0 and siblings) saves GQR2/5/6/7 into its context, loads the
 * dequantization formats with `li; oris` and restores the saved words at the end.
 * Kept in its own header so no widely included header gains inlines (include/ppc_ops.h). */

static inline u32 gqr_get2(void) { register u32 v; asm { mfspr v, GQR2 } return v; }
static inline u32 gqr_get5(void) { register u32 v; asm { mfspr v, GQR5 } return v; }
static inline u32 gqr_get6(void) { register u32 v; asm { mfspr v, GQR6 } return v; }
static inline u32 gqr_get7(void) { register u32 v; asm { mfspr v, GQR7 } return v; }

static inline void gqr_put2(register u32 v) { asm { mtspr GQR2, v } }
static inline void gqr_put5(register u32 v) { asm { mtspr GQR5, v } }
static inline void gqr_put6(register u32 v) { asm { mtspr GQR6, v } }
static inline void gqr_put7(register u32 v) { asm { mtspr GQR7, v } }

/* The decoder's formats, each loaded as `li v, lo; oris v, v, hi` (not MWCC's constant
 * materialization, so the constant lives in the asm): GQR2 0x00040004, GQR5 0x00070007,
 * GQR6 0x3D043D04, GQR7 0x01040104. */
static inline void gqr_set2_decode(void) { register u32 v; asm { li v, 0x4; oris v, v, 0x4; mtspr GQR2, v } }
static inline void gqr_set5_decode(void) { register u32 v; asm { li v, 0x7; oris v, v, 0x7; mtspr GQR5, v } }
static inline void gqr_set6_decode(void) { register u32 v; asm { li v, 0x3D04; oris v, v, 0x3D04; mtspr GQR6, v } }
static inline void gqr_set7_decode(void) { register u32 v; asm { li v, 0x104; oris v, v, 0x104; mtspr GQR7, v } }

#endif  // GQR_H
