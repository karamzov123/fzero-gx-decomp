
#include "types.h"

typedef struct MwsYccPlane {
    void *y;
    void *cb;
    void *cr;
    int y_pitch;
    int cb_pitch;
    int cr_pitch;
} MwsYccPlane;

void fn_12_3E09C(const void *source, void *destination, s32 width, s32 height);

void fn_12_339B4(void *buffer, int width, int height, MwsYccPlane *output);

static inline u32 cftPackEvenPixels(u32 luma, u16 chroma) {
    return (luma & 0xFF000000) | ((luma >> 8) & 0x0000FF00) | (((u32)chroma << 8) & 0x00FF0000) |
           ((u32)chroma >> 8);
}

static inline u32 cftPackOddPixels(u32 luma, u16 chroma) {
    return ((luma << 16) & 0xFF000000) | ((luma << 8) & 0x0000FF00) |
           (((u32)chroma << 16) & 0x00FF0000) | ((u32)chroma & 0xFF);
}

static inline void cftStorePixelQuad(u32 *first_output, u32 *second_output, u32 first_luma,
                                     u32 second_luma, u16 first_chroma, u16 second_chroma) {
    first_output[1] = cftPackOddPixels(first_luma, first_chroma);
    second_output[1] = cftPackOddPixels(second_luma, second_chroma);
    first_output[0] = cftPackEvenPixels(first_luma, first_chroma);
    second_output[0] = cftPackEvenPixels(second_luma, second_chroma);
}

void fn_12_3E09C(const void *source, void *destination, s32 width, s32 height) {
    MwsYccPlane planes;
    u8 *y0;
    u8 *y1;
    u16 *cb;
    u16 *cr;
    u32 *output0;
    u32 *output1;
    s32 y_step;
    s32 c_step;
    s32 y_rewind;
    s32 block_y;
    s32 blocks_across;
    s32 blocks_down;
    u16 *chroma_base;
    u16 *cb_next;
    u16 chroma_u;
    u16 chroma_v;
    fn_12_339B4((void *)source, width, height, &planes);
    blocks_across = width / 4;
    y0 = planes.y;
    chroma_base = planes.cb;
    y1 = (u8 *)planes.y + ((((unsigned long)chroma_base - (unsigned long)planes.y) >> 1) & ~3UL);
    cb = chroma_base;
    cr = planes.cr;
    output0 = destination;
    blocks_down = height / 4;
    output1 = output0 + 8;
    y_step = planes.y_pitch & ~3;
    c_step = planes.cb_pitch & ~1;
    y_rewind = y_step * 2;
    for (block_y = 0; block_y < blocks_down; block_y++) {
        u16 *cr_next = (u16 *)(c_step + (u32)cr);
        s32 block_x;
        cb_next = (u16 *)(c_step + (u32)cb);
        for (block_x = 0; block_x < blocks_across; block_x++) {
            if (block_x >= 0 && block_x < blocks_across) {
                u32 first_luma = *(u32 *)y1;
                u32 second_luma = *(u32 *)y0;
                u16 first_chroma = *cb;
                u16 second_chroma = *cr;
                cftStorePixelQuad(output0, output1, first_luma, second_luma, first_chroma,
                                  second_chroma);
                chroma_u = *cb;
                chroma_v = *cr;
                cftStorePixelQuad(output0 + 2, output1 + 2, *(u32 *)y1, *(u32 *)y0, chroma_u,
                                  chroma_v);
            } else {
                output1[0] = output0[0] = 0;
                output1[1] = output0[1] = 0;
                output1[2] = output0[2] = 0;
                output1[3] = output0[3] = 0;
            }
            y0 += y_step;
            y1 += y_step;
            if (block_x >= 0 && block_x < blocks_across) {
                cftStorePixelQuad(output0 + 4, output1 + 4, *(u32 *)y1, *(u32 *)y0, *cb_next,
                                  *cr_next);
                cftStorePixelQuad(output0 + 6, output1 + 6, *(u32 *)y1, *(u32 *)y0, *cb, *cr);
            } else {
                output1[4] = output0[4] = 0;
                output1[5] = output0[5] = 0;
                output1[6] = output0[6] = 0;
                output1[7] = output0[7] = 0;
            }
            y0 += y_step;
            y1 += y_step;
            y0 += 4;
            y1 += 4;
            y0 -= y_rewind;
            output0 += 16;
            output1 += 16;
            cb++;
            cb_next++;
            cr++;
            cr_next++;
            y1 -= y_rewind;
        }
        y0 += y_step;
        y1 += y_step;
        cb = (u16 *)((u8 *)cb + c_step);
        cr = (u16 *)((u8 *)cr + c_step);
    }
}
