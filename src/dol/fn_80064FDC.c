#include "types.h"
#include "dol/globals.h"

struct fn_80064FDC_Arg1 {
    u8 unk_0;
};

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
        if (((fzgx_loop_v3_658)[0]) & 0x80) {
            for (v6 = 0; v6 < 64; v6++) {
                if (*(u8 *)(lbl_801A6C80 + (v6 << 5) + 0x588) == 0) {
                    v5 = v6;
                    break;
                }
            }
            v7 = v6 << 5;
            v8 = v5 << 5;
            *(u8 *)(lbl_801A6C80 + v7 + 0x588) = 1;
            *(u8 *)(lbl_801A6C80 + v7 + 0x589) = ((fzgx_loop_v3_658)[0]);
            *(u8 *)(lbl_801A6C80 + v7 + 0x58c) = ((fzgx_loop_v3_658)[2]);
            *(u8 *)(lbl_801A6C80 + v7 + 0x58d) = ((fzgx_loop_v3_658)[3]);
            *(u8 *)(lbl_801A6C80 + v7 + 0x58e) = ((fzgx_loop_v3_658)[10]);
            *(u8 *)(lbl_801A6C80 + v7 + 0x58f) = ((fzgx_loop_v3_658)[9]);
            *(u8 *)(lbl_801A6C80 + v7 + 0x590) = ((fzgx_loop_v3_658)[11]);
            *(u8 *)(lbl_801A6C80 + v7 + 0x591) = ((fzgx_loop_v3_658)[12]);
            tmp_call9 = ((fzgx_loop_v3_658)[6]);
            *(u8 *)(lbl_801A6C80 + v7 + 0x592) = tmp_call9;
            *(u8 *)(lbl_801A6C80 + v7 + 0x593) = ((fzgx_loop_v3_658)[7]);
            *(u8 *)(lbl_801A6C80 + v7 + 0x594) = ((fzgx_loop_v3_658)[8]);
            *(u8 *)(lbl_801A6C80 + v7 + 0x595) = ((fzgx_loop_v3_658)[13]);
            *(u8 *)(lbl_801A6C80 + v7 + 0x596) = ((fzgx_loop_v3_658)[13]);
            *(u8 *)(lbl_801A6C80 + v7 + 0x597) = ((fzgx_loop_v3_658)[14]);
            *(u8 *)(lbl_801A6C80 + v7 + 0x58b) = ((fzgx_loop_v3_658)[1]);
            *(u32 *)(lbl_801A6C80 + v7 + 0x5a0) = (u32)fzgx_loop_v3_658;
            adjustment = 0;
            if (*(u8 *)(lbl_801A6C80 + v8 + 0x589) & 2) {
                v11 = v1 + lbl_801A6C80;
                v12 = *(v11 + 0x495);
                volume.value = *(v11 + 0x493);
                if (v12 != 64) adjustment = ((s8)v12 - 64) << 1;
            } else {
                v11 = v1 + lbl_801A6C80;
                v12 = *(v11 + 0x494);
                volume.value = *(v11 + 0x492);
                if (v12 != 64) adjustment = ((s8)v12 - 64) << 1;
            }
            v15 = (s8)volume.value + adjustment;
            if (v15 < 0) v15 = 0;
            else if (v15 > 127) v15 = 127;
            *(u8 *)(lbl_801A6C80 + v7 + 0x598) = v15;
            v17 = (u8 *)(lbl_801A6C80 + v8);
            v18 = *(u8 **)(v1 + lbl_801A6C80 + 8);
            if (((v17)[0x589]) & 2) {
                v19 = *(u32 *)(v18 + 40);
                if (v19 != 0) *(u8 **)(v17 + 0x5a4) = v18 + v19;
                else *(u8 **)(v17 + 0x5a4) = 0;
            } else {
                v22 = (*(v17 + 0x58c));
                v23 = v18 + *(u32 *)(v18 + 28);
                v24.value = (u16 *)v23;
                for (v25.value = 0; v25.value <= v22; v25.value++) v24.value++;
                v29 = ((v17)[0x58d]);
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
                v44 = ((fzgx_loop_v3_658)[1]) << 2;
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
