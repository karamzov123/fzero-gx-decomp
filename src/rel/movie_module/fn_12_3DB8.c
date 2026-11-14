
#include "types.h"

typedef struct SFXZObject SFXZObject;

extern const f32 lbl_12_rodata_570;
extern f64 lbl_12_rodata_578[3];

typedef void (*SFXZConvertCallback)(u32 *source, void *destination, f32 near_clip, f32 far_clip);

struct SFXZObject {
    s32 active;
    s32 z_bit;
    s32 tag_info_set;
    u8 *tag_data;
    s32 tag_size;
    u8 reserved_14[4];
    s32 header_info_set;
    u8 *header_data;
    s32 header_size;
    u8 reserved_24[4];
    s32 frame_info_set;
    u8 *frame_data;
    s32 frame_size;
    u8 reserved_34[8];
    f32 near_clip;
    f32 far_clip;
    SFXZConvertCallback convert_callback;
    void *field_48;
};

void fn_12_3DB8(SFXZObject *object, u32 near_z, u32 far_z, u32 *table);

static inline u8 fn_12_3DB8_array_read(s32 index, u8 *array) { return array[index]; }
void fn_12_3DB8(SFXZObject *object, u32 near_z, u32 far_z, u32 *table) {
    s32 i;
    s32 j;
    u8 *ccir_table;
    u32 *z_table;
    z_table = table + 0x100;
    ccir_table = (u8 *)(z_table + 0x100);
    { s32 index_0;
for (index_0 = 0; index_0 <= 15; index_0++) {
        ccir_table[index_0] = 0;
    }
i = index_0;
}
    for (j = 16; j <= 235; j++) {
        ccir_table[j] = (u8)(lbl_12_rodata_570 * (f32)(j - 16));
    }
    { s32 index_1;
for (index_1 = 236; index_1 <= 255; index_1++) {
        ccir_table[index_1] = 255;
    }
i = index_1;
}
    if (far_z == 0x80000000U) {
        far_z = 0x7FFFFFFF;
    }
    if (near_z == 0x80000000U) {
        near_z = 0x7FFFFFFF;
    }
    { s32 index_2;
for (index_2 = 0; index_2 < 9; index_2++) {
        z_table[index_2] = 0;
    }
i = index_2;
}
    for (i = 9; i < 17; i++) {
        z_table[i] = near_z;
    }
    if (near_z == far_z) {
        for (i = 17; i < 224; i++) {
            z_table[i] = near_z;
        }
    } else {
        for (i = 17; i < 224; i++) {
            z_table[i] = near_z + (i - 17) * ((far_z - near_z) / 207);
        }
    }
    { s32 index_6;
for (index_6 = 224; index_6 < 240; index_6++) {
        z_table[index_6] = far_z;
    }
i = index_6;
}
    { s32 index_7;
for (index_7 = 240; index_7 < 256; index_7++) {
        z_table[index_7] = 0x7FFFFFFF;
    }
i = index_7;
}
    { s32 index_8;
for (index_8 = 0; index_8 <= 255; index_8++) {
        table[index_8] = z_table[fn_12_3DB8_array_read(index_8, ccir_table)];
    }
i = index_8;
}
}

