#include "types.h"
#include "dol/globals.h"

struct fn_80064FDC_Arg1 {
    u8 unk_0;
};

static inline u8 fn_80064FDC_array_read(s32 index, u8 *array) { return array[index]; }
void fn_80064FDC(u8 arg0, struct fn_80064FDC_Arg1 *arg1) {
    s32 tmp_call9;
    u8 *v1;
    u32 v2;
    u8 *v3;
    u8 v4;
    u32 v7;
    u8 v6;
    struct { u32 value; } v25;
    u32 v8;
    u8 *v11;
    u32 v22;
    s8 adjustment;
    struct { u8 value; } volume;
    s32 v11_2;
    s16 v15;
    struct { u16 *value; } v24;
    u8 *v18;
    u32 v19;
    u8 v41;
    u8 *v23;
    u8 fzgx_loop_v4_658;
    u8 *v17;
    u8 v29;
    u16 *v31;
    struct { u8 *value; } v30;
    u32 v32;
    u16 v36;
    u8 v12;
    u32 v44;
    u32 v43;
    u8 count;
    u8 v5;
{
    u8 * fzgx_loop_v3_658;
    fzgx_loop_v3_658 = (u8 *)arg1 + 8;
    fzgx_loop_v4_658 = 0;
    count = arg1->unk_0;
    v1 = (u8 *)(arg0 << 4);
    v2 = arg0 << 6;
    while (fzgx_loop_v4_658 <= count) {
        v5 = 255;
        if (fn_80064FDC_array_read(0, fzgx_loop_v3_658) & 0x80) {
            for (v6 = 0; v6 < 64; v6++) {
                if (*(u8 *)(lbl_801A6C80 + (v6 << 5) + 0x588) == 0) {
                    v5 = v6;
                    break;
                }
            }
            v7 = v6 << 5;
            v8 = v5 << 5;
            *(u8 *)(lbl_801A6C80 + v7 + 0x588) = 1;
            *(u8 *)(lbl_801A6C80 + v7 + 0x589) = fn_80064FDC_array_read(0, fzgx_loop_v3_658);
            *(u8 *)(lbl_801A6C80 + v7 + 0x58c) = fn_80064FDC_array_read(2, fzgx_loop_v3_658);
            *(u8 *)(lbl_801A6C80 + v7 + 0x58d) = fn_80064FDC_array_read(3, fzgx_loop_v3_658);
            *(u8 *)(lbl_801A6C80 + v7 + 0x58e) = fn_80064FDC_array_read(10, fzgx_loop_v3_658);
            *(u8 *)(lbl_801A6C80 + v7 + 0x58f) = fn_80064FDC_array_read(9, fzgx_loop_v3_658);
            *(u8 *)(lbl_801A6C80 + v7 + 0x590) = fn_80064FDC_array_read(11, fzgx_loop_v3_658);
            *(u8 *)(lbl_801A6C80 + v7 + 0x591) = fn_80064FDC_array_read(12, fzgx_loop_v3_658);
            tmp_call9 = fn_80064FDC_array_read(6, fzgx_loop_v3_658);
            *(u8 *)(lbl_801A6C80 + v7 + 0x592) = tmp_call9;
            *(u8 *)(lbl_801A6C80 + v7 + 0x593) = fn_80064FDC_array_read(7, fzgx_loop_v3_658);
            *(u8 *)(lbl_801A6C80 + v7 + 0x594) = fn_80064FDC_array_read(8, fzgx_loop_v3_658);
            *(u8 *)(lbl_801A6C80 + v7 + 0x595) = fn_80064FDC_array_read(13, fzgx_loop_v3_658);
            *(u8 *)(lbl_801A6C80 + v7 + 0x596) = fn_80064FDC_array_read(13, fzgx_loop_v3_658);
            *(u8 *)(lbl_801A6C80 + v7 + 0x597) = fn_80064FDC_array_read(14, fzgx_loop_v3_658);
            *(u8 *)(lbl_801A6C80 + v7 + 0x58b) = fn_80064FDC_array_read(1, fzgx_loop_v3_658);
            *(u32 *)(lbl_801A6C80 + v7 + 0x5a0) = (u32)fzgx_loop_v3_658;
            adjustment = 0;
            if (*(u8 *)(lbl_801A6C80 + v8 + 0x589) & 2) {
                v11 = v1 + lbl_801A6C80;
                v12 = *(u8 *)(v11 + 0x495);
                volume.value = *(u8 *)(v11 + 0x493);
                if (v12 != 64) adjustment = ((s8)v12 - 64) << 1;
            } else {
                v11 = v1 + lbl_801A6C80;
                v12 = *(u8 *)(v11 + 0x494);
                volume.value = *(u8 *)(v11 + 0x492);
                if (v12 != 64) adjustment = ((s8)v12 - 64) << 1;
            }
            v15 = (s8)volume.value + adjustment;
            if (v15 < 0) v15 = 0;
            else if (v15 > 127) v15 = 127;
            *(u8 *)(lbl_801A6C80 + v7 + 0x598) = v15;
            v17 = (u8 *)(lbl_801A6C80 + v8);
            v18 = *(u8 **)(v1 + lbl_801A6C80 + 8);
            if (fn_80064FDC_array_read(0x589, v17) & 2) {
                v19 = *(u32 *)(v18 + 40);
                if (v19 != 0) *(u8 **)(v17 + 0x5a4) = v18 + v19;
                else *(u8 **)(v17 + 0x5a4) = 0;
            } else {
                v22 = (*((u8 *)v17 + 0x58c));
                v23 = v18 + *(u32 *)(v18 + 28);
                v24.value = (u16 *)v23;
                for (v25.value = 0; v25.value <= v22; v25.value++) v24.value++;
                v29 = fn_80064FDC_array_read(0x58d, v17);
                v30.value = v23 + *v24.value;
                v31 = (u16 *)v30.value;
                for (v32 = 0; v32 <= v29; v32++) v31++;
                v36 = *v31;
                if (v36 != 0) *(u8 **)(v17 + 0x5a4) = (u8 *)(v36 + (u32)v30.value);
                else *(u8 **)(v17 + 0x5a4) = 0;
            }
        }
        if (v5 != 255) {
            v11_2 = lbl_801A6C80;
            {
    u8 fzgx_loop_v41_3506;
for (fzgx_loop_v41_3506 = 0; fzgx_loop_v41_3506 < 4; fzgx_loop_v41_3506++) {
                v43 = fzgx_loop_v41_3506;
                v44 = fn_80064FDC_array_read(1, fzgx_loop_v3_658) << 2;
                if (((u8 *)(v11_2 + v2))[v44 + v43 + 0xd88] & 1) {
                    *(u8 *)(v2 + v11_2 + v44 + v43 + 0xd88) = v5;
                    break;
                }
            }
    v41 = fzgx_loop_v41_3506;
}
        }
        fzgx_loop_v3_658 += 16;
        fzgx_loop_v4_658++;
    }
    v3 = fzgx_loop_v3_658;
    v4 = fzgx_loop_v4_658;
}
}
