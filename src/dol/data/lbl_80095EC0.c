/* An initialized 0x8C000-byte (640 x 448 x 2) buffer in main .data: about 90 KB of CMPR-like
 * texture blocks, the rest zero. Nothing references it from code. It is a game asset, so its
 * bytes are not in the repository: dtk extracts them from the user's disc at split time
 * (config/GFZE01/config.yml `extract`, written to build/GFZE01/include/assets/). */
#include "types.h"

#pragma explicit_zero_data on
__declspec(section ".data") u8 lbl_80095EC0[0x8C000] __attribute__((aligned(32))) = {
#include "assets/lbl_80095EC0.inc"
};
#pragma explicit_zero_data reset
