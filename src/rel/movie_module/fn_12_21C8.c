#include "types.h"
#pragma use_lmw_stmw on
#pragma pool_data on
#pragma readonly_strings on

typedef struct SFXHandle {
    s32 active;
    s32 stream_info;
    s32 field_count;
    u8 reserved_0c[0x20];
    void *alpha;
    u8 reserved_30[4];
    s32 table_compo;
    void *work_0;
} SFXHandle;

typedef struct SFXPlaneBuffer {
    void *pixels;
    s32 width;
    s32 height;
    s32 pitch;
} SFXPlaneBuffer;

typedef struct SFXFrameInfo {
    s32 format;
    SFXPlaneBuffer y;
    SFXPlaneBuffer cb;
    SFXPlaneBuffer cr;
    u8 reserved_34[0x10];
    s32 field_44;
    s32 field_48;
    s32 color_adjustment;
    u8 reserved_50[0x24];
    s32 field_74;
} SFXFrameInfo;

typedef struct CFTYcc420Planar {
    void *y;
    void *cb;
    void *cr;
    s32 y_stride;
    s32 cb_stride;
    s32 cr_stride;
    u8 reserved_18[4];
} CFTYcc420Planar;

typedef struct CFTArgb8888Output {
    SFXPlaneBuffer plane;
    u8 reserved_10[8];
} CFTArgb8888Output;

extern int fn_12_748(SFXHandle *handle);
extern void fn_12_309C(void *object, void *frame, const char *message);
extern void fn_12_3D144(CFTYcc420Planar *source, CFTArgb8888Output *destination);
extern void fn_12_3CB74(CFTYcc420Planar *source, CFTArgb8888Output *destination, void *table);
extern void fn_12_3D740(void *table);
extern void fn_12_3E09C(const void *source, void *destination, s32 width, s32 height);
extern void fn_12_1F84(SFXHandle *handle, SFXFrameInfo *frame, void *output);
extern int fn_12_34DC(void *alpha);
extern void fn_12_3508(void *alpha, s32 adjustment, void *table);
extern void fn_12_34E4(void *alpha, s32 adjustment, void *table);

#pragma force_active on
#pragma section code_type ".fzgxpool"
static f32 fzgx_pool_primer_before(s32 value) {
    fn_12_309C(0, 0, "E201312: sfxcnv_IsCnvUpHalf : compo is invalid.");
    fn_12_309C(0, 0, "E301282: CnvToRgb888 : compo is not support.");
    fn_12_309C(0, 0, "COMPO");
    fn_12_309C(0, 0, "E301281: SFX_CnvFrmRgb888 : frmfmt is not support.");
    fn_12_309C(0, 0, "E202281: SFX_MakeTblZ32 : zclip is not set.");
    fn_12_309C(0, 0, "E202282: SFX_MakeTblZ16 : zclip is not set.");
    return 1.164f * (f32)value;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_after(void) {
    fn_12_309C(0, 0, "E201311: sfxcnv_MakeTable : compo is not support.");
    fn_12_309C(0, 0, "E201313: sfxcnv_CnvZbitToCft : zbit is invalid.");
    fn_12_309C(0, 0, "E201315: sfxcnv_CnvFrmZcmn : zclip is not set.");
    fn_12_309C(0, 0, "E201191: SFX_CnvFrmZcmn : frmfmt is not support.");
    fn_12_309C(0, 0, "E201192: CnvToY84C44 : compo is not support.");
    fn_12_309C(0, 0, "E201193: SFX_CnvFrmY84C44 : frmfmt is not support.");
    fn_12_309C(0, 0, "E201182: CnvToYuv422 : compo is not support.");
    fn_12_309C(0, 0, "E201183: SFX_CnvFrmYUV422 : frmfmt is not support.");
    fn_12_309C(0, 0, "E212182: CnvToArgb8888mb : compo is not support.");
    fn_12_309C(0, 0, "E212173: sfxcnv_CnvFrmYcc420mbToArgb8888mb() : compo is not support.");
    fn_12_309C(0, 0, "E212171: SFX_CnvFrmARGB8888Mb : function is not support.");
    fn_12_309C(0, 0, "E212172: SFX_CnvFrmMbARGB8888 : frmfmt is not support.");
}
#pragma section code_type ".text"
#pragma force_active off

static inline s32 sfxcnv_IsCnvUpHalf(SFXHandle *handle)
{
    switch (handle->stream_info) {
    case 0x11:
    case 0x31:
    case 0x41:
    case 0xF1:
    case 0x1001:
        return 0;
    case 0x21:
    case 0x101:
        return 1;
    default:
        fn_12_309C(0, 0, "E201312: sfxcnv_IsCnvUpHalf : compo is invalid.");
        return 0;
    }
}

static inline void SFX_MakeTable(SFXHandle *handle, SFXFrameInfo *frame, s32 compo)
{
    s32 cur = handle->table_compo;
    s32 make_table = 1;
    s32 i;
    u8 *table;

    if (cur == 100) {
        make_table = 0;
    } else if (cur == compo) {
        switch (compo) {
        case 2:
            if (fn_12_34DC(handle->alpha) != 1) {
                make_table = 0;
            }
            break;
        default:
            make_table = 0;
            break;
        }
    }

    if (make_table != 1) {
        return;
    }

    handle->table_compo = compo;
    switch (compo) {
    case 2:
        fn_12_3508(handle->alpha, frame->color_adjustment, handle->work_0);
        break;
    case 3:
        fn_12_34E4(handle->alpha, frame->color_adjustment, handle->work_0);
        break;
    case 0x15:
        fn_12_3D740(handle->work_0);
        break;
    case 1:
        table = handle->work_0;
        for (i = 0; i <= 15; i++) {
            table[i] = 0;
        }
        for (i = 16; i <= 235; i++) {
            table[i] = 1.164f * (i - 16);
        }
        for (i = 236; i <= 255; i++) {
            table[i] = 255;
        }
        break;
    }
}

static inline void sfxcnv_CnvNormalYcc420plnToArgb8888(SFXHandle *handle, SFXFrameInfo *frame, void *output, s32 use_table)
{
    CFTYcc420Planar source;
    CFTArgb8888Output destination;
    void *table;
    s32 err;

    source.y = frame->y.pixels;
    source.cb = frame->cb.pixels;
    source.cr = frame->cr.pixels;
    source.y_stride = frame->y.width;
    source.cb_stride = frame->cb.width;
    source.cr_stride = frame->cr.width;

    destination.plane.pixels = output;
    destination.plane.width = frame->field_44;
    if (sfxcnv_IsCnvUpHalf(handle) == 1) {
        destination.plane.height = frame->field_48 / 2;
    } else {
        destination.plane.height = frame->field_48;
    }

    if (handle->field_count == 0) {
        destination.plane.pitch = frame->y.width * 4;
    } else {
        destination.plane.pitch = handle->field_count;
    }

    err = 0;
    if (use_table == 1) {
        table = handle->work_0;
    } else {
        table = 0;
    }

    if (frame->field_74 == 1) {
        if (table != 0) {
            if (err != 1) {
                fn_12_3CB74(&source, &destination, table);
            }
        } else {
            if (err != 1) {
                fn_12_3D144(&source, &destination);
            }
        }
    } else {
        if (table != 0) {
            if (err != 1) {
                fn_12_3CB74(&source, &destination, table);
            }
        } else {
            if (err != 1) {
                fn_12_3D144(&source, &destination);
            }
        }
    }
}

void fn_12_21C8(SFXHandle *handle, SFXFrameInfo *frame, void *output)
{
    switch (handle->stream_info) {
    case 0x11:
        if (fn_12_748(handle) != 1) {
            sfxcnv_CnvNormalYcc420plnToArgb8888(handle, frame, output, 0);
            break;
        }
        SFX_MakeTable(handle, frame, 0x15);
        sfxcnv_CnvNormalYcc420plnToArgb8888(handle, frame, output, 1);
        break;
    case 0x101:
        sfxcnv_CnvNormalYcc420plnToArgb8888(handle, frame, output, 0);
        break;
    case 0xF1:
        fn_12_3E09C(frame->y.pixels, output, frame->y.width, frame->y.height);
        break;
    case 0x21:
        SFX_MakeTable(handle, frame, 1);
        fn_12_1F84(handle, frame, output);
        break;
    case 0x31:
        SFX_MakeTable(handle, frame, 2);
        sfxcnv_CnvNormalYcc420plnToArgb8888(handle, frame, output, 1);
        break;
    case 0x41:
        SFX_MakeTable(handle, frame, 3);
        sfxcnv_CnvNormalYcc420plnToArgb8888(handle, frame, output, 1);
        break;
    case 0x1001:
        SFX_MakeTable(handle, frame, 0x15);
        sfxcnv_CnvNormalYcc420plnToArgb8888(handle, frame, output, 1);
        break;
    default:
        fn_12_309C(handle, frame, "E201182: CnvToArgb8888 : compo is not support.");
        break;
    }
}
