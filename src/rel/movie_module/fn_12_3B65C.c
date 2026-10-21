#include "types.h"

struct fn_12_3B65C_Arg0 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    f32 unk_6C;
    f32 unk_70;
    f32 unk_74;
    f32 unk_78;
    f32 unk_7C;
    f32 unk_80;
    f32 unk_84;
    f32 unk_88;
    f32 unk_8C;
    f32 unk_90;
    f32 unk_94;
    f32 unk_98;
    f32 unk_9C;
    f32 unk_A0;
    f32 unk_A4;
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    f32 unk_BC;
    f32 unk_C0;
    f32 unk_C4;
    f32 unk_C8;
    f32 unk_CC;
    f32 unk_D0;
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
    f32 unk_E0;
    f32 unk_E4;
    f32 unk_E8;
    f32 unk_EC;
    f32 unk_F0;
    f32 unk_F4;
    f32 unk_F8;
    f32 unk_FC;
    u8 pad_100[0x700];
    f32 unk_800;
    f32 unk_804;
    f32 unk_808;
    f32 unk_80C;
    f32 unk_810;
    f32 unk_814;
    f32 unk_818;
    f32 unk_81C;
    f32 unk_820;
    f32 unk_824;
    f32 unk_828;
    f32 unk_82C;
    f32 unk_830;
    f32 unk_834;
    f32 unk_838;
    f32 unk_83C;
    f32 unk_840;
    f32 unk_844;
    f32 unk_848;
    f32 unk_84C;
    f32 unk_850;
    f32 unk_854;
    f32 unk_858;
    f32 unk_85C;
    f32 unk_860;
    f32 unk_864;
    f32 unk_868;
    f32 unk_86C;
    f32 unk_870;
    f32 unk_874;
    f32 unk_878;
    f32 unk_87C;
    f32 unk_880;
    f32 unk_884;
    f32 unk_888;
    f32 unk_88C;
    f32 unk_890;
    f32 unk_894;
    f32 unk_898;
    f32 unk_89C;
    f32 unk_8A0;
    f32 unk_8A4;
    f32 unk_8A8;
    f32 unk_8AC;
    f32 unk_8B0;
    f32 unk_8B4;
    f32 unk_8B8;
    f32 unk_8BC;
    f32 unk_8C0;
    f32 unk_8C4;
    f32 unk_8C8;
    f32 unk_8CC;
    f32 unk_8D0;
    f32 unk_8D4;
    f32 unk_8D8;
    f32 unk_8DC;
    f32 unk_8E0;
    f32 unk_8E4;
    f32 unk_8E8;
    f32 unk_8EC;
    f32 unk_8F0;
    f32 unk_8F4;
    f32 unk_8F8;
    f32 unk_8FC;
};

const char lbl_12_rodata_2E10[] = "\nCRI CFT/GC Ver.1.29 Build:May  9 2003 15:17:25\n";

void fn_12_3B65C(struct fn_12_3B65C_Arg0 *arg0) {
    s32 v12;
    s32 v24;
    s32 v55;
    f32 *v10 = (f32 *)((u8 *)arg0 + 4096);
    f32 *v11 = (f32 *)((u8 *)arg0 + 8192);
    f32 *v18 = (f32 *)arg0;
    f32 v23;
    s32 v15;

    for (v12 = 0; v12 < 256; v12++) {
        v10[v12 * 4 + 3] = 0.5f + 2.017f * (f32)(v12 - 128);
        v10[v12 * 4 + 2] = 0.5f + -0.392f * (f32)(v12 - 128);
        v10[v12 * 4 + 1] = 0.0f;
        v10[v12 * 4 + 0] = 0.0f;
        v11[v12 * 4 + 3] = 0.0f;
        v11[v12 * 4 + 2] = 0.5f + -0.813f * (f32)(v12 - 128);
        v11[v12 * 4 + 1] = 0.5f + 1.596f * (f32)(v12 - 128);
        v11[v12 * 4 + 0] = 0.0f;
    }
    for (v24 = 0; v24 < 16; v24++) {
        v18[v24 * 4 + 3] = 0.0f;
        v18[v24 * 4 + 2] = 0.0f;
        v18[v24 * 4 + 1] = 0.0f;
        v18[v24 * 4 + 0] = 0.0f;
    }
    for (v24 = 16; v24 < 128; v24++) {
        v15 = ((v24 - 16) << 8) / 112;
        v23 = 0.5f + 1.164f * (f32)(v15 - 16);
        v18[v24 * 4 + 3] = v23;
        v18[v24 * 4 + 2] = v23;
        v18[v24 * 4 + 1] = v23;
        v18[v24 * 4 + 0] = 127.0f;
    }
    for (v55 = 128; v55 < 144; v55++) {
        v18[v55 * 4 + 3] = 278.696f;
        v18[v55 * 4 + 2] = 278.696f;
        v18[v55 * 4 + 1] = 278.696f;
        v18[v55 * 4 + 0] = 255.0f;
    }
    for (v55 = 144; v55 < 256; v55++) {
        v15 = 255 - (((v55 - 144) << 8) / 112);
        v23 = 0.5f + 1.164f * (f32)(v15 - 16);
        v18[v55 * 4 + 3] = v23;
        v18[v55 * 4 + 2] = v23;
        v18[v55 * 4 + 1] = v23;
        v18[v55 * 4 + 0] = 255.0f;
    }
}
