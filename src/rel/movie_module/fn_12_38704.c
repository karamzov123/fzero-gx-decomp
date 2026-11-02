#include "types.h"

/* the create parameters fn_12_3763C reads (its MwsCreateParams); 0x24 is the buffer format its error string names */
typedef struct MwsCreateParams {
    int file_type;
    int maximum_bps;
    int width;
    int height;
    int frame_count;
    int decoder_count;
    void *work;
    int work_size;
    int composition_mode;
    int buffer_format;
} MwsCreateParams;

extern void MWSFSVM_Error(const char *, ...);
extern const char lbl_12_rodata_2184[];

static inline int mwsfcre_CalcFrameSize(int source_width, int source_height) {
    int height;
    int width;
    int luma_size;
    int chroma_size;

    width = (source_width + 15) / 16 * 16;
    height = (source_height + 15) / 16 * 16;
    luma_size = height * ((width + 31) / 32 * 32);
    chroma_size = (height / 2) * ((width / 2 + 31) / 32 * 32);
    return luma_size + chroma_size * 2 + 0x20;
}

#pragma use_lmw_stmw on
#pragma opt_propagation off

/* Adds up the sizes fn_12_3763C allocates for these parameters; work_<off> are the sizes fn_12_3763C keeps at
 * lbl_12_bss_1B9B0+<off>. MWCC folds a sum's constants only within one type, so the int, long and u32 terms keep
 * retail's three separate constants (0x20, 0x840, 0x4800). */
int fn_12_38704(MwsCreateParams *params) {
    int frame_count;
    long work_1C;
    int work_18;
    int work_10;
    u32 work_00;
    u32 work_04;
    int height;
    int width;
    int work_14;
    int bps;
    int file_type;
    int sector_count;
    int frame_size;
    int work_08;
    int work_0C;

    sector_count = params->decoder_count;
    file_type = params->file_type;
    bps = params->maximum_bps;
    if (sector_count <= 0) {
        sector_count = 1;
    }
    if (file_type == 2) {
        work_1C = sector_count * (bps / 8 / 0x800 * 0x800);
        work_18 = 0;
        work_14 = 0;
        work_10 = 0;
        work_00 = 0;
        work_04 = 0;
    } else if (file_type == 3) {
        work_1C = sector_count * (bps / 8 / 0x800 * 0x800);
        work_14 = bps / 8 / 0x800 * 0x800 / 2 + 0x800;
        work_18 = 0;
        work_10 = 0;
        work_00 = 0;
        work_04 = 0;
    } else {
        work_1C = sector_count * (bps / 8 / 0x800 * 0x800);
        work_14 = bps / 8 / 0x800 * 0x800 / 2 + 0x800;
        work_18 = 0;
        work_10 = 0x5DCC;
        work_00 = 0x5F0C;
        work_04 = 0xC1C0;
    }

    frame_count = params->frame_count;
    width = params->width;
    height = params->height;
    if (params->buffer_format >= 4 || params->buffer_format < 0) {
        MWSFSVM_Error(lbl_12_rodata_2184);
    }
    frame_size = mwsfcre_CalcFrameSize(width, height);
    work_0C = frame_size * 2;
    work_08 = frame_count * frame_size;
    return work_18 + work_14 + work_10 + 0x20 + work_1C + 0x40 + 0x800 + work_0C + work_08 + work_00 + work_04 + 0x4000 +
           0x700 + 0x100;
}
#pragma opt_propagation reset
