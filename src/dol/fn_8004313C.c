#include "types.h"
#include "dol/data/lbl_8012B6F0.h"
#include "dol/data/lbl_8012B6F4.h"

extern s32 fn_8008023C(const void *, const void *, u32);

typedef struct {
    u16 formatTag;
    u16 channels;
    u32 sampleRate;
    u32 byteRate;
    u16 blockAlign;
    u16 bitsPerSample;
} WavFormat;

#define WAV_SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) & 0xFF) << 8))

/* WARNING: compiler-diff device, not original code: WAV_SWAP32 is a macro rather than a static inline
 * function only because `#pragma opt_dead_assignments off` (below) keeps the inline function's parameter
 * assignment, which changes the scratch registers of the header decode; the macro compiles exactly as the
 * inline function does without the pragma. */
#define WAV_SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))

/* WARNING: compiler-diff device, not original code: keeps the dead address compares at the start of
 * fn_8004313C alive until register allocation (see there). The body is exact with the pragma on; whether it has other dead assignments that the pragma also keeps was not checked. */
#pragma opt_dead_assignments off
s32 fn_8004313C(u8 *buf, s32 size, s16 *dataOffset, s8 *encoding, s8 *bits, s8 *blockAlign,
                s8 *channels, s32 *sampleRate, s32 *sampleCount, s32 *samplesPerBlock,
                s16 *codec) {
    WavFormat *fmt;
    s32 i;
    s32 dataSize;
    s16 *cd;
    s32 *perBlock;
    s32 *count;
    int escaped;

    /* WARNING: compiler-diff device, not original code: the three stack-passed parameters are copied into
     * locals (declared in reverse order) because the address compares below make the parameters
     * themselves address-taken; the copies keep the three loads in the entry block with retail's
     * registers (r28-r30). The honest form uses sampleCount, samplesPerBlock and codec directly. */
    count = sampleCount;
    perBlock = samplesPerBlock;
    cd = codec;
    /* WARNING: compiler-diff device, not original code: dead compares of the stack-parameter addresses,
     * kept by `#pragma opt_dead_assignments off` and deleted after register allocation, so nothing of
     * them reaches the object code. A compare of a parameter's address makes MWCC count that stack slot
     * as escaped (worst-case alias), so the final scheduler orders the three parameter loads after the
     * prologue's stmw, as retail does. Comparing two addresses (no other value) leaves the entry
     * schedule and every register as they are. CRI built ADX with a compiler build we do not have,
     * whose loads carry that dependence without help. */
    escaped = (void *)&sampleCount == (void *)&samplesPerBlock;
    escaped = (void *)&samplesPerBlock == (void *)&codec;
    for (i = 0; i < size; i++) {
        if (fn_8008023C(&buf[i], lbl_8012B6F0.at_0, 4) == 0) {
            break;
        }
    }
    if (i == size) {
        return -1;
    }
    if (i % 4 != 0) {
        return -1;
    }
    fmt = (WavFormat *)&buf[i + 8];
    if ((s16)WAV_SWAP16(fmt->formatTag) > 1) {
        return -1;
    }
    for (i = 0; i < size; i++) {
        if (fn_8008023C(&buf[i], lbl_8012B6F4.at_0, 4) == 0) {
            break;
        }
    }
    if (i == size) {
        return -1;
    }
    dataSize = WAV_SWAP32(*(u32 *)&buf[i + 4]);
    *dataOffset = i + 8;
    *encoding = -1;
    *sampleRate = WAV_SWAP32(fmt->sampleRate);
    *channels = WAV_SWAP16(fmt->channels);
    *bits = WAV_SWAP16(fmt->bitsPerSample);
    *blockAlign = WAV_SWAP16(fmt->blockAlign);
    *count = dataSize / *blockAlign;
    *perBlock = 1;
    if (*bits == 16) {
        *cd = 0;
    } else if (*bits == 8) {
        *cd = 1;
    } else if (*bits == 4) {
        *blockAlign = *channels * 2;
        *perBlock = 4;
        *count = dataSize / 2 / *channels;
        *bits = 16;
        *cd = 2;
    }
    if (*bits == 0) {
        return -1;
    }
    if (*blockAlign == 0) {
        return -1;
    }
    if (*channels <= 0 || *channels > 2) {
        return -1;
    }
    return *sampleRate == 0 ? -1 : 0;
}
#pragma opt_dead_assignments reset
