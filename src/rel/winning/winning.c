#include "types.h"
#include "font.h"

/* winning.c: the winning run and the award scene (fze.winning.rel, one translation unit) */

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

/* one pad's button words: held, trigger and repeat */
typedef struct PadInput {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
    u16 unk_10;
    u16 unk_12;
} PadInput;

typedef struct LightObj {
    u8 data[0x40];
} LightObj;

typedef struct CameraState {
    u8 pad_0[0x1C];
    f32 unk_1C;
    s16 unk_20;
} CameraState;

typedef struct LiveCamera {
    u8 pad_0[0x5C];
    s16 unk_5C;
} LiveCamera;

/* the machine data of a custom machine */
typedef struct WinMachine {
    u32 flags;
    u8 pad_4[0x819C];
    u8 unk_81A0;
    u8 pad_81A1[3];
    u8 unk_81A4;
    u8 pad_81A5[7];
    u8 unk_81AC;
    u8 pad_81AD[7];
    u8 unk_81B4;
} WinMachine;

/* one racer of the result list (8 bytes) */
typedef struct WinRacer {
    WinMachine *machine;
    u8 unk_4;
    u8 id;
    u8 color;
    u8 pad_7;
} WinRacer;

/* the race result snapshot (0xA0 bytes) */
typedef struct WinResult {
    u8 pad_0[4];
    u16 unk_4;
    u16 unk_6;
    u8 rank;
    u8 unk_9[5];
    u8 unk_E[5];
    u8 unk_13[5];
    u16 unk_18[6];
    u32 unk_24[5];
    u32 unk_38[5];
    u8 pad_4C[0x54];
} WinResult;

/* the winning run entry (lbl_1_bss_525C, 0x198 bytes) */
typedef struct WinEntry {
    WinRacer racers[30];
    WinResult result;
    u8 unk_190;
    u8 unk_191;
    u8 unk_192;
    u8 pad_193;
    u8 order[4];
} WinEntry;

typedef struct RobMotion {
    u8 pad_0[0x8];
    u8 *data;
} RobMotion;

/* the animation state of a robot (0x37C bytes) */
typedef struct RobAnim {
    u8 pad_0[0x8];
    RobMotion *motion;
    u8 pad_C[0x370];
} RobAnim;

/* a robot (staff roll machine) object, 0x4E0 bytes */
typedef struct WinRob {
    u8 pad_0[0x18];
    u32 flags;
    u8 pad_1C[0x6C];
    s32 unk_88;
    u32 unk_8C;
    u8 pad_90[0x8];
    u8 unk_98;
    u8 pad_99[0xF];
    Vec3 unk_A8;
    u8 pad_B4[0x4];
    f32 unk_B8;
    u8 pad_BC[0x8C];
    RobAnim anim;
    u8 unk_4C4;
    u8 pad_4C5[0x1B];
} WinRob;

typedef struct WinModel {
    u32 flags;
    u8 pad_4[0x8];
    f32 unk_C;
    u8 pad_10[0x22];
    u8 unk_32;
} WinModel;

/* a race machine object, 0x620 bytes */
typedef struct WinCar {
    u32 flags;
    u8 pad_4[0x8];
    f32 unk_C;
    u8 pad_10[0x6C];
    f32 unk_7C;
    u8 pad_80[0x4];
    f32 unk_84;
    u8 pad_88[0xC];
    f32 unk_94;
    f32 unk_98;
    f32 unk_9C;
    u8 pad_A0[0x3C];
    f32 unk_DC;
    u8 pad_E0[0x120];
    f32 unk_200;
    u8 pad_204[0x280];
    WinModel *model;
    u8 pad_488[0x198];
} WinCar;

typedef struct CarParam {
    u8 data[0xB4];
} CarParam;

typedef struct RaceCar {
    u8 pad_0[0x390];
    u32 unk_390;
    u8 pad_394[0x26];
    s16 unk_3BA;
} RaceCar;

/* one machine entry for fn_1_80058 / fn_1_83070 (0x20 bytes) */
typedef struct CarEntry {
    s16 index;
    s16 id;
    s32 type;
    u8 color;
    u8 pad_9[3];
    u32 flags;
    u16 parts[4];
    s32 type_copy;
    u8 pad_1C[4];
} CarEntry;

typedef struct AdxWork {
    void *adxt0;
    void *adxt1;
    u8 pad_8[0x8];
    u8 work0[0x4A248];
    u8 work1[0x4A248];
    u8 work2[0x3000];
} AdxWork;

typedef struct StageDst {
    u8 pad_0[0xC];
    Vec3 pos;
} StageDst;

typedef struct StageInfo {
    u8 pad_0[0x10];
    u8 mtx[0xC];
    Vec3 unk_1C;
    Vec3 unk_28;
    Vec3 unk_34;
    u8 pad_40[0xC];
    StageDst *unk_4C[2];
    StageDst *unk_54;
} StageInfo;

typedef struct StageData {
    u8 pad_0[0x3C];
    StageInfo *info;
} StageData;

typedef struct StageModel {
    u32 model;
    u32 unk_4;
} StageModel;

typedef struct StageModelList {
    u8 pad_0[0x8];
    StageModel *models;
} StageModelList;

typedef struct WinningScene {
    char *name;
    void (*init)(void);
    void (*main)(void);
    void (*exit)(void);
} WinningScene;

typedef struct WinningTimeline {
    u32 unk_0;
    s32 results_start;
    s32 results_end;
    s32 hide_result_at;
    s32 exit_at;
} WinningTimeline;

typedef struct InputStatus {
    u8 pad_0[0xE0];
    u8 held_frames;
    u8 unk_E1;
    u8 skip;
} InputStatus;

typedef struct ResultAnimation {
    f32 ease;
    f32 acceleration;
    f32 velocity;
    f32 x;
    f32 y;
    s16 unk_14;
    char label[20];
    char value[50];
} ResultAnimation;

typedef struct ResultRow {
    u32 unk_0;
    ResultAnimation anim;
} ResultRow;

extern u32 lbl_801A6410;
extern u32 lbl_801A63C0;
extern s32 lbl_801A66B4;
extern PadInput lbl_1_bss_D58;
extern PadInput lbl_1_bss_9F8[4];
#include "game/pad.h"
extern u8 lbl_1_bss_25E98;
extern InputStatus lbl_1_bss_5138;
extern WinEntry lbl_1_bss_525C;
extern AdxWork *lbl_1_bss_6EAD0;
extern StageModelList *lbl_1_bss_38458;
extern u32 lbl_1_bss_6EAB4;
extern s16 lbl_1_bss_960;
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_964;
extern u16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern void (*lbl_1_bss_7167C)(void);
extern void (*lbl_1_bss_71680)(void);
extern void (*lbl_1_bss_71684)(void);
extern void (*lbl_1_bss_71688)(void);
extern void (*lbl_1_bss_7168C)(void);
extern u32 lbl_1_data_20B14[];
extern u8 lbl_1_data_28060[];
extern StageData lbl_1_data_2A7E0;
extern u8 lbl_1_data_2B0D4[];
extern char *lbl_1_data_2BD54[][6];
extern const FontDrawPacket lbl_1_rodata_26F8;

extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);
extern int sprintf(char *, const char *, ...);
extern f64 __fabs(f64);
extern void *fn_1_4630(u32, u32, const char *, s32);
extern u32 fn_1_45D0(u32, u32, const char *, s32);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_3CF0(u32, u32);
extern u16 fn_1_3F8C(const char *, void (*)(), void *, s32);
extern u32 fn_1_435C(u32);
extern void fn_1_407C(void);
extern void fn_1_3CC4(void);
extern void fn_1_41A8(void);
extern void fn_1_4310(u32);
extern void fn_1_4A00(s32, u8, u32);
extern int fn_1_4C10(void);
extern void fn_1_5124(u32, u32);
extern void fn_1_5370(s32, s32);
extern u32 fn_1_58C4(void);
extern void fn_1_5948(s16);
extern void fn_1_627C(s16);
extern void fn_1_6400(void);
extern void fn_1_3FDA8(u32, u32);
extern u32 fn_1_3FC9C(void);
extern void fn_1_3EF14(void *);
extern void fn_1_41048(void);
extern void fn_1_410A0(void);
extern void fn_1_469BC(void);
extern u32 fn_1_467F4(void);
extern void fn_1_4706C(void);
extern void fn_1_479F0(u32);
extern void fn_1_47A60(u32);
extern void fn_1_47F74(u32);
extern void fn_1_48140(u32);
extern u16 fn_1_48690(u32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(GXColor *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_1_4962C(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_50A90(FontDrawPacket *, s32, s32, s32, s32);
extern void fn_1_52070(u32);
extern void fn_1_520A0(void);
extern void fn_1_520CC(void);
extern char *fn_1_5415C(s32, s32);
extern void fn_1_584D4(void);
extern void fn_1_58854(void);
extern void fn_1_7BA48(u32);
extern u32 fn_1_7BA08(u32, u32, u32);
extern void fn_1_7BAF8(void);
extern void fn_1_7BB80(LightObj *, int);
extern void fn_1_7BCCC(Vec3 *);
extern void fn_1_7BD6C(int);
extern void fn_1_789E8(void);
extern void fn_1_78EBC(void);
extern u32 fn_1_79100(void);
extern void fn_1_7ACDC(u32);
extern void fn_1_7E9C4(void);
extern void fn_1_7EAE8();
extern void *fn_1_7F49C(s16, s16, void *);
extern void fn_1_80058(s8, CarEntry *);
extern void fn_1_817C0(void);
extern void fn_1_81834(u8, s8, s8);
extern void fn_1_82724(u32, u32, CarEntry *, s16, u32);
extern WinCar *fn_1_83070(u32, u32, CarEntry *, s16);
extern void fn_1_835E0(u32 *, u32, void *);
extern void fn_1_85878(void);
extern void fn_1_86194(f32);
extern void fn_1_861B4(void);
extern void *fn_1_86254(u32);
extern RaceCar *fn_1_868C0(s8);
extern s32 fn_1_8DB94(void);
extern void fn_1_8E4A4(s32, u32, u32);
extern void fn_1_8E728(WinRob *, u8);
extern void fn_1_8F198(WinRob *, s32, u32, u32);
extern void fn_1_8F45C(WinRob *, s32, u32, u32);
extern void fn_1_8F494(void *);
extern void fn_1_8F62C(WinRob *);
extern void fn_1_92530(WinRob *);
extern void fn_1_934CC(WinRob *, RobAnim *, const char *);
extern void fn_1_981C4(void);
extern void fn_1_982C4(void);
extern void fn_1_98230(void);
extern void fn_1_9835C(void);
extern void fn_1_9A578(void);
extern void fn_1_9A5CC(void);
extern void fn_1_9A770(void);
extern void fn_1_9A7BC(void);
extern void fn_1_A0680(void);
extern void fn_1_A0AA4(void);
extern void fn_1_A1588(void *, u32);
extern void fn_1_A2A70(s32, s16);
extern void fn_1_A2D84(u32);
extern f32 fn_1_A71AC(void);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8E78(const char *);
extern void fn_1_A8EB0(int, int);
extern void fn_1_A8F40(u8);
extern u8 fn_1_B7C00(void);
extern void fn_1_C2454(void);
extern s32 fn_1_C24A4(void);
extern void fn_1_C3A0C(void *);
extern void fn_1_C42F4(void);
extern void fn_1_C47B4(void);
extern void fn_1_C6F80(u32);
extern void fn_1_CFCA4(const char *, f32, f32, f32);
extern void fn_1_DCF54(Vec3 *, Vec3 *, Vec3 *);
extern s32 fn_1_FA004(void);
extern void fn_1_FA01C(void);
extern s32 fn_1_FA088(void);
extern void fn_1_FA0A0(void);
extern void fn_1_106EB0(void);
extern void fn_1_129D9C(void *, Vec3 *, u32, u32, u32, u32, u32, f32);
extern s16 fn_1_12C710(s32);
extern s16 fn_1_12C7B8(s32);
extern s16 fn_1_12C930(s16);
extern s16 fn_1_12CB04(s16);
extern s16 fn_1_12CCB0(s16, s16);
extern s16 fn_1_12EF24(s16, s16);
extern void fn_1_141360(u8, s32, s32, s32, f32, f32);
extern void fn_1_15B544(void);
extern void fn_1_15B588(void);
extern void fn_1_15B5CC(void);
extern void fn_1_15B610(void);
extern void fn_1_15B654(void);
extern void fn_1_157820(void);
extern void fn_1_1577D0(u32, u32, f32);
extern void fn_1_1578C4(void);
extern void fn_1_22E8C(WinCar *, CarParam *);
extern void fn_80007AB4(GXColor *);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_8004BF0C(void *, s32);
extern void *fn_8004CD70(u32, void *, u32);
extern void fn_80051E64(void *, void *, u32);
extern void fn_800674FC(u32, u32, s16);
extern void fn_80067898(u32);
extern void fn_8006CE1C(f32);
extern void fn_80074CF4(f32, f32, f32);
extern void fn_80035420(LightObj *, f32, int);
extern void fn_80035680(LightObj *, f32, f32, f32);
extern void fn_80035690(LightObj *, f32, f32, f32);
extern void fn_800356AC(LightObj *, GXColor);
extern void GXInitLightDistAttn(LightObj *, f32, f32, int);
extern void ADXT_Pause(void *, s32);
extern void ADXT_Stop(void *);
extern void lbl_8006D758(void);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1B0(Vec3 *, Vec3 *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern s32 camera_get_flags(void);
extern void camera_update(void);
extern void camera_enable_flags(void);
extern void camera_disable_flags(void);
extern void camera_set_state_flag(u8);
extern void camera_set_entry_field_0xa8(u8, s16);
extern CameraState *camera_get_state_object(void);
extern BOOL camera_are_flags_enabled(void);
extern LiveCamera *live_camera_get(void);

void fn_15_1F4(void);
void fn_15_260(void);
void fn_15_350(void);
void fn_15_3AC(void);
void fn_15_644(void);
void fn_15_B8C(void);
void fn_15_B90(void);
void fn_15_DD8(void);
void fn_15_FCC(void);
void fn_15_11DC(void);
void fn_15_1D7C(void);
void fn_15_1DF4(void);
void fn_15_1EE0(void);
void fn_15_1F28(u32 arg0, u32 arg1);
void fn_15_2228(void);
void fn_15_2274(void);
void fn_15_236C(u32 arg0, u32 arg1);
void fn_15_2458(s16 id, s16 slot, s16 index, u32 kind);
void fn_15_2620(WinRob *rob);
void fn_15_27D4(WinRob *rob);
void fn_15_2AE4(void);
void fn_15_2CEC(void);
void fn_15_2CF0(void);
void fn_15_2D74(void);
void fn_15_2E8C(void);
void fn_15_30E8(void);
void fn_15_3174(WinRob *rob);
void fn_15_3368(s32 racer);
void fn_15_38FC(void);
void fn_15_398C(void);
void fn_15_3A14(void);
void fn_15_3AFC(void);
void fn_15_3B00(void);
void fn_15_3B24(void);
void fn_15_401C(void);
void fn_15_405C(void);
void fn_15_4060(void);
void fn_15_4124(void);
void fn_15_435C(void);
void fn_15_4568(void);
void fn_15_4578(void);
void fn_15_537C(void);
void fn_15_545C(void);
void fn_15_5460(f32 alpha);
void fn_15_5730(f32 alpha);

/* fzgx:begin _prolog */
char *lbl_15_data_20[4] = {"WIN_1ST", "WIN_2ND", "WIN_3RD", "WIN_4TH"};
char *lbl_15_data_50[4] = {"BLACK", "GRAY", "BLUE", "WHITE?"};
WinningScene lbl_15_data_70[2] = {
    {"menu", fn_15_3AC, fn_15_644, fn_15_B8C},
    {"winning", fn_15_1D7C, fn_15_1DF4, fn_15_1EE0},
};
WinningTimeline lbl_15_data_90 = {0, 4680, 4860, 4990, 6600};

u32 lbl_15_bss_0 = 0;
u8 lbl_15_bss_4 = 0;
u32 lbl_15_bss_8 = 0;
u32 lbl_15_bss_C;
u32 lbl_15_bss_10;
u32 lbl_15_bss_14;
s32 lbl_15_bss_18;
s32 lbl_15_bss_1C;
u8 lbl_15_bss_20;
u8 lbl_15_bss_21;
u8 lbl_15_bss_22;
u8 lbl_15_bss_23;
u32 lbl_15_bss_24;
u32 lbl_15_bss_28;
WinEntry *lbl_15_bss_2C;
int lbl_15_bss_30;
u8 lbl_15_bss_34;
u8 lbl_15_bss_35;
u8 lbl_15_bss_36;
s16 lbl_15_bss_38;
s16 lbl_15_bss_3A;
s16 lbl_15_bss_3C;
u8 lbl_15_bss_3E;
u16 lbl_15_bss_40;
f32 lbl_15_bss_44;
f32 lbl_15_bss_48;
WinCar *lbl_15_bss_4C;
s32 lbl_15_bss_50;
s32 lbl_15_bss_54;
s32 lbl_15_bss_58;
u32 lbl_15_bss_5C;
f32 lbl_15_bss_60;
u32 lbl_15_bss_64;
s32 lbl_15_bss_68;
int lbl_15_bss_6C;
s32 lbl_15_bss_70;
u32 lbl_15_bss_74;
u32 lbl_15_bss_78;
Vec3 lbl_15_bss_7C;
Vec3 lbl_15_bss_88;
s16 lbl_15_bss_94;
s16 lbl_15_bss_96;
s16 lbl_15_bss_98;
WinRob *lbl_15_bss_9C[12];
s16 lbl_15_bss_CC;
s16 lbl_15_bss_CE;
u8 lbl_15_bss_D0;
WinRob *lbl_15_bss_D4[30];
s16 lbl_15_bss_14C;
u32 *lbl_15_bss_150;
s16 lbl_15_bss_154;
ResultRow lbl_15_bss_158[7];
LightObj lbl_15_bss_3F8;
u8 lbl_15_bss_438[0x48];

void _prolog(void) {
    lbl_15_bss_C = fn_1_45D0(lbl_801A6410, 0x173C, "winning.c", 0x158);
    lbl_15_bss_10 = fn_1_45D0(lbl_801A6410, 0x173C, "winning.c", 0x159);
    fn_1_3CF0(lbl_15_bss_C, 0x80);
    fn_1_3CF0(lbl_15_bss_10, 0x80);
    fn_1_479F0(0xE);
    fn_1_47F74(0x8C);
    fn_1_47F74(0xBB);
    lbl_15_bss_14 = 0;
    lbl_15_bss_14 |= 0x40000000;
    lbl_15_bss_18 = 0;
    lbl_15_bss_1C = 30;
    lbl_15_bss_20 = 1;
    lbl_15_bss_21 = 0;
    lbl_15_bss_22 = 0;
    lbl_15_bss_23 = 0;
    lbl_1_bss_96A = 0xB7;
    fn_1_4A00(1, 30, lbl_15_bss_10);
    fn_1_C2454();
    lbl_1_bss_7167C = fn_15_1F4;
    lbl_1_bss_71680 = fn_15_260;
    lbl_1_bss_71684 = fn_15_350;
}
/* fzgx:end _prolog */

/* fzgx:begin _epilog */
void _epilog(void) {
    fn_8006CE1C(0.0f);
    lbl_1_bss_6EAB4 &= ~0x28;
    fn_1_435C(lbl_15_bss_C);
    fn_1_41A8();
    fn_1_435C(lbl_15_bss_10);
    fn_1_41A8();
    fn_1_47A60(0xE);
    fn_1_48140(0x8C);
    fn_1_48140(0xBB);
    fn_1_46B4(lbl_801A6410, lbl_15_bss_C, "winning.c", 0x192);
    fn_1_46B4(lbl_801A6410, lbl_15_bss_10, "winning.c", 0x193);
}
/* fzgx:end _epilog */

/* fzgx:begin fn_15_1F4 */
/* retail .rodata 0x4: no code reads this table */
const GXColor lbl_15_rodata_4[3] = {
    {0x00, 0xFF, 0x00, 0xFF},
    {0x80, 0x80, 0x80, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
};

void fn_15_1F4(void) {
    if (lbl_15_bss_14 & 0x10000000) {
        if (lbl_15_bss_1C != 0) {
            lbl_15_bss_1C--;
        }
        if (lbl_15_bss_1C == 0) {
            lbl_15_bss_14 &= ~0x10000000;
            fn_15_B90();
        }
    }
}
/* fzgx:end fn_15_1F4 */

/* fzgx:begin fn_15_260 */
void fn_15_260(void) {
    u32 count;
    s16 index;
    s32 i;

    if (lbl_15_bss_21 != 0) {
        fn_1_435C(lbl_15_bss_24);
        fn_1_407C();
    }
    fn_1_435C(lbl_15_bss_C);
    fn_1_407C();
    fn_1_3CC4();
    if (fn_1_8DB94() != 0) {
        fn_1_86254(0);
        fn_1_106EB0();
    }
    if (camera_get_flags() != 0) {
        camera_update();
    }
    count = fn_1_58C4();
    i = 0;
    while ((s16)i < count) {
        index = i;
        fn_1_5948(index);
        fn_1_9A770();
        if (lbl_15_bss_21 != 0) {
            fn_1_435C(lbl_15_bss_28);
            fn_1_407C();
        }
        fn_1_435C(lbl_15_bss_10);
        fn_1_407C();
        fn_1_627C(index);
        i++;
    }
}
/* fzgx:end fn_15_260 */

/* fzgx:begin fn_15_350 */
void fn_15_350(void) {
    WinningScene *scene = lbl_15_data_70;

    scene += lbl_1_bss_962 - 0xB7;

    lbl_1_bss_71688 = scene->main;
    lbl_1_bss_7168C = scene->exit;
    scene->init();
}
/* fzgx:end fn_15_350 */

/* fzgx:begin fn_15_3AC */
void fn_15_3AC(void) {
    u32 r;
    WinRacer *slot;
    s32 i;
    u64 mask;
    WinEntry *entry;
    s16 idx;

    lbl_15_bss_2C = &lbl_1_bss_525C;
    entry = lbl_15_bss_2C;
    slot = entry->racers;
    mask = 0;
    lbl_15_bss_30 = 0;
    lbl_15_bss_20 = 1;
    lbl_15_bss_23 = 0;
    lbl_15_bss_4 = 0;
    lbl_15_bss_34 = 0;
    lbl_15_bss_35 = 0;
    lbl_15_bss_36 = 0;
    lbl_15_bss_38 = 3;
    fn_1_469BC();
    fn_1_4706C();
    if (lbl_1_bss_964 == 10) {
        memset(lbl_15_bss_2C, 0, sizeof(WinEntry));
        lbl_15_bss_3A = 3;
        lbl_15_bss_14 |= 0x20000000;
        lbl_15_bss_2C->unk_192 = 3;
        lbl_15_bss_3C = 0;
        lbl_15_bss_34 = 1;
        lbl_15_bss_35 = 1;
        lbl_15_bss_36 = 1;
        for (i = 0; (s16)i < 4; i++, slot++) {
            slot->unk_4 = i;
            slot->id = i;
            slot->color = 0x10;
            idx = fn_1_12C7B8(slot->id);
            mask |= (u64)1 << idx;
        }
        for (; (s16)i < 30; i++, slot++) {
            r = lbl_801A63C0;
            do {
                r = r * 0x676A4B6B + 0x33CB;
                idx = ((s32)((r >> 16) & 0x7FFF) % 41);
            } while ((mask & ((u64)1 << idx)) != 0);
            lbl_801A63C0 = r;
            mask |= (u64)1 << idx;
            slot->unk_4 = idx;
            slot->id = idx;
            slot->color = 0x10;
        }
    } else {
        lbl_15_bss_14 &= ~0xFE;
        lbl_15_bss_14 |= 1;
        lbl_15_bss_3C = (u8)fn_1_3FC9C();
        if (lbl_15_bss_2C->unk_191 & 2) {
            lbl_15_bss_14 |= 0x80;
            lbl_15_bss_38 = lbl_15_bss_2C->unk_192;
        } else {
            switch (entry->result.rank) {
            case 0:
                lbl_15_bss_14 |= 0x8;
                break;
            case 1:
                lbl_15_bss_14 |= 0x10;
                break;
            case 2:
                lbl_15_bss_14 |= 0x20;
                break;
            default:
                lbl_15_bss_14 |= 0x40;
                break;
            }
        }
        lbl_15_bss_3A = (lbl_15_bss_14 & 0x40) ? 1 : 3;
        lbl_1_bss_96A = 0xB8;
    }
}
/* fzgx:end fn_15_3AC */

/* fzgx:begin fn_15_644 */
/* Moves a menu cursor by dir and wraps it in 0..count-1. The cursors are int objects and the
   parameter is an s32 pointer, so each call has a cast. MWCC does not follow the cast pointer to
   its object: the store ends every cached load (the pad words, lbl_15_bss_38), as retail does. */
static inline s32 cursor_move(s32 *cursor, s32 dir, s32 count) {
    *cursor = (*cursor + dir + count) % count;
    return *cursor;
}

void fn_15_644(void) {
    WinEntry *entry;
    WinRacer *racer;
    u16 name[18];
    s16 dir;
    s16 i;
    s16 id;
    /* WARNING: compiler-diff device, not original code: one-field carriers of j and flags (as main) */
    struct { s16 value; } j;
    u32 color;
    u32 *colors;
    struct { u32 value; } flags;

    if (!(lbl_15_bss_14 & 0x20000000)) {
        return;
    }
    entry = lbl_15_bss_2C;
    if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 3) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 3)) {
        dir = -1;
    } else if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 2) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 2)) {
        dir = 1;
    } else {
        dir = 0;
    }
    cursor_move((s32 *)&lbl_15_bss_30, dir, 9);

    if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 0) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 0)) {
        dir = -1;
    } else if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 1) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 1)) {
        dir = 1;
    } else {
        dir = 0;
    }

    if (dir != 0) {
        if (lbl_15_bss_30 >= 0 && lbl_15_bss_30 < 4) {
            entry->racers[lbl_15_bss_30].unk_4 = (entry->racers[lbl_15_bss_30].unk_4 + dir + 41) % 41;
            entry->racers[lbl_15_bss_30].id = entry->racers[lbl_15_bss_30].unk_4;
        } else {
            switch (lbl_15_bss_30 - 4) {
            case 0:
                lbl_15_bss_14 ^= 0x80000000;
                break;
            case 1:
                break;
            case 2:
                lbl_15_bss_2C->unk_192 += dir;
                if (lbl_15_bss_2C->unk_192 == 0) {
                    lbl_15_bss_2C->unk_192 = 4;
                }
                if (lbl_15_bss_2C->unk_192 > 4) {
                    lbl_15_bss_2C->unk_192 = 1;
                }
                break;
            }
        }
    }

    racer = lbl_15_bss_2C->racers;
    fn_1_A8EB0(10, 19);
    fn_1_A8F40(255);
    fn_1_A8E78("Push <A> to winning run mode!\n");
    colors = lbl_1_data_20B14;
    for (i = 0; i < 4; i++) {
        if (i == lbl_15_bss_30) {
            fn_1_A8F40(51);
        } else {
            fn_1_A8F40(255);
        }
        id = racer->unk_4;
        fn_1_A8DD4("CAR:%2d, TYPE:%2d ", i, id);
        color = colors[fn_1_12C930(id)];
        fn_1_7F49C(fn_1_12C710(id), 0, name);
        fn_1_A8DD4(" %s(%s) \n", color, name);
        racer++;
    }
    for (; i < 9; i++) {
        if (i == lbl_15_bss_30) {
            fn_1_A8F40(51);
        } else {
            fn_1_A8F40(255);
        }
        switch (i - 4) {
        case 0:
            if (lbl_15_bss_14 & 0x80000000) {
                fn_1_A8E78("SEL: ON\n");
            } else {
                fn_1_A8E78("SEL: OFF\n");
            }
            break;
        case 1:
            fn_1_A8E78("SEQ: GC WINNING RUN\n");
            break;
        case 2:
            fn_1_A8DD4("SEQ: GC VS : %1d\n", lbl_15_bss_2C->unk_192);
            break;
        case 3:
            fn_1_A8E78("SEQ: AC 1st\n");
            break;
        case 4:
            fn_1_A8E78("SEQ: AC END\n");
            break;
        }
    }
    fn_1_A8F40(255);

    if (((lbl_1_bss_D58.unk_8 >> 8) & 1) && !fn_1_B7C00()) {
        flags.value = lbl_15_bss_14 & 0xFFFFFF01;
        lbl_1_bss_525C.unk_191 = 0;
        lbl_15_bss_14 = flags.value;
        switch (lbl_15_bss_30 - 4) {
        case 1:
            lbl_15_bss_14 = flags.value | 9;
            lbl_1_bss_525C.unk_191 |= 1;
            lbl_1_bss_96A = 0xB8;
            lbl_15_bss_20 = 1;
            break;
        case 2:
            lbl_15_bss_14 = flags.value | 0x81;
            lbl_1_bss_525C.unk_191 |= 2;
            lbl_15_bss_38 = lbl_15_bss_2C->unk_192;
            lbl_1_bss_96A = 0xB8;
            lbl_15_bss_20 = 1;
            for (j.value = 0; j.value < lbl_15_bss_38; j.value++) {
                lbl_15_bss_2C->order[j.value] = j.value;
            }
            break;
        case 3:
            lbl_15_bss_14 = flags.value | 5;
            lbl_1_bss_96A = 0xB8;
            lbl_15_bss_20 = 1;
            break;
        case 4:
            lbl_15_bss_14 = flags.value | 3;
            lbl_1_bss_525C.unk_191 |= 1;
            lbl_1_bss_96A = 0xB8;
            lbl_15_bss_20 = 0;
            break;
        default:
            lbl_15_bss_14 &= ~1;
            lbl_15_bss_20 = 1;
            break;
        }
        if ((lbl_15_bss_14 & 0x78) == 0) {
            fn_1_4A00(1, 30, lbl_15_bss_10);
        } else {
            fn_1_4A00(0, 0, lbl_15_bss_10);
        }
        lbl_1_bss_96A = 0xB8;
    }
    if (((lbl_1_bss_D58.unk_8 >> 12) & 1) && !fn_1_B7C00() && lbl_15_bss_20 &&
        (lbl_15_bss_14 & 0x20000000) && lbl_1_bss_962 == 0xB7) {
        lbl_1_bss_968 = 10;
    }
}
/* fzgx:end fn_15_644 */

/* fzgx:begin fn_15_B8C */
// fn_15_B8C: empty in retail (single blr).
void fn_15_B8C(void) {
}
/* fzgx:end fn_15_B8C */

/* fzgx:begin fn_15_B90 */
void fn_15_B90(void) {
    WinResult result;
    u32 flags;
    WinEntry *entry;

    flags = lbl_15_bss_14;
    lbl_1_bss_6EAB4 &= ~0x28;
    if (!(flags & 0x20000000)) {
        if (flags & 0x80) {
            lbl_1_bss_968 = lbl_15_bss_2C->unk_190;
        } else {
            entry = lbl_15_bss_2C;
            result = entry->result;
            if (result.rank == 0 && lbl_15_bss_3E == 0) {
                lbl_1_bss_968 = 0x10;
            } else if (lbl_15_bss_40 < 1) {
                lbl_15_bss_40 = 1;
                lbl_15_bss_18 = lbl_15_data_90.results_start;
                camera_disable_flags();
                fn_1_5370(3, 0);
                {
                    Vec3 pos = {-345.869f, 504.895f, 656.313f};
                    Vec3 look = {-346.419f, 508.693f, 656.996f};
                    Vec3 up = {0.0f, 1.0f, 0.0f};

                    fn_1_DCF54(&pos, &look, &up);
                }
                fn_1_4A00(1, 30, lbl_15_bss_10);
            } else {
                lbl_1_bss_968 = entry->unk_190;
            }
        }
    } else if (flags & 0x80) {
        lbl_1_bss_96A = 0xB7;
    } else if (lbl_15_bss_40 < 1) {
        lbl_15_bss_40 = 1;
        lbl_15_bss_18 = lbl_15_data_90.results_start;
        camera_disable_flags();
        fn_1_5370(3, 0);
        {
            Vec3 pos = {-345.869f, 504.895f, 656.313f};
            Vec3 look = {-346.419f, 508.693f, 656.996f};
            Vec3 up = {0.0f, 1.0f, 0.0f};

            fn_1_DCF54(&pos, &look, &up);
        }
        fn_1_4A00(1, 30, lbl_15_bss_10);
    } else {
        lbl_1_bss_96A = 0xB7;
    }
}
/* fzgx:end fn_15_B90 */

/* fzgx:begin fn_15_DD8 */
void fn_15_DD8(void) {
    s32 time;
    u32 flags;
    u32 busy;
    WinResult result;

    if (fn_1_4C10() != 0) {
        return;
    }
    flags = lbl_15_bss_14;
    busy = flags & 0x10000000;
    if (busy == 0 && ((flags & 1) == 0 || lbl_15_bss_18 >= 60)) {
        if ((lbl_15_bss_34 != 0 || lbl_15_bss_35 != 0) && lbl_15_bss_36 != 0 && lbl_15_bss_40 >= 1) {
            return;
        }
        result = lbl_15_bss_2C->result;
        time = (lbl_15_bss_23 != 0) ? 480 : 30;
        if ((result.rank == 0 && lbl_15_bss_3E == 0) || lbl_15_bss_40 < 1 || (flags & 0x80) != 0) {
            if (busy == 0) {
                lbl_15_bss_1C = (s16)time;
                lbl_15_bss_14 |= 0x10000000;
            }
            lbl_1_bss_6EAB4 |= 0xAC;
            fn_1_A2A70(12, time);
            fn_1_4A00(0, time, lbl_15_bss_10);
        } else {
            if (lbl_15_bss_22 == 0) {
                fn_1_3FDA8(lbl_15_bss_C, lbl_15_bss_10);
            }
            lbl_15_bss_22 = 1;
            if ((s32)lbl_1_bss_5138.skip == 0 && fn_1_C24A4() == 0 && fn_1_B7C00() == 0) {
                if ((lbl_15_bss_14 & 0x10000000) == 0) {
                    lbl_15_bss_1C = (s16)time;
                    lbl_15_bss_14 |= 0x10000000;
                }
                lbl_15_bss_14 |= 0x10000000;
                lbl_1_bss_6EAB4 |= 0xAC;
                fn_1_A2A70(12, time);
                fn_1_4A00(0, time, lbl_15_bss_10);
                lbl_15_bss_22 = 0;
            }
        }
    }
}
/* fzgx:end fn_15_DD8 */

/* fzgx:begin fn_15_FCC */
void fn_15_FCC(void) {
    CarParam param;
    u8 *preset;
    s16 i;
    WinCar *car;
    WinModel *model;
    f32 zero;
    f32 scale;
    u32 flags;

    lbl_15_bss_18 = 0;
    lbl_15_bss_40 = 0;
    lbl_15_bss_44 = 0.0f;
    lbl_15_bss_48 = 0.0f;
    camera_enable_flags();
    if (lbl_15_bss_14 & 6) {
        car = lbl_15_bss_4C;
        scale = 200.0f;
        zero = 0.0f;
        preset = lbl_1_data_28060 + 0x438;
        i = 0;
        while (i < lbl_15_bss_3A) {
            fn_80008BA8(&param, preset, sizeof(CarParam));
            fn_1_22E8C(car, &param);
            model = car->model;
            i++;
            car->unk_C = scale;
            car->unk_200 = zero;
            model->unk_C = zero;
            car->unk_DC = zero;
            car->flags |= 0x100000 | 0x8001;
            car++;
        }
    }
    if (lbl_15_bss_14 & 2) {
        fn_1_1577D0(1, 1, 1.0f);
        fn_1_435C(lbl_15_bss_C);
        fn_1_3F8C("StaffRollMain", fn_1_157820, NULL, 2);
        fn_1_435C(lbl_15_bss_10);
        fn_1_3F8C("StaffRollDisp", fn_1_1578C4, NULL, 2);
    }
    flags = lbl_15_bss_14;
    lbl_15_bss_50 = 0;
    lbl_15_bss_54 = 0;
    lbl_15_bss_58 = 0;
    lbl_15_bss_5C = 0;
    if (flags & 0x78) {
        lbl_15_bss_14 &= ~0x04000000;
        lbl_15_bss_14 |= 0x40000000;
        fn_1_5370(0, 0);
    } else if (flags & 0x80) {
        lbl_15_bss_14 = flags | 0x04000000;
        fn_1_5370(4, 0);
    } else {
        lbl_15_bss_14 = flags & 0xBBFFFFFF;
        fn_1_5370(0, 0);
    }
    fn_15_4568();
    fn_1_15B610();
    ADXT_Pause(lbl_1_bss_6EAD0->adxt0, 0);
    fn_80067898(0xA91A0000);
    fn_80067898(0xA91A0200);
}
/* fzgx:end fn_15_FCC */

/* fzgx:begin fn_15_11DC */
static inline f32 winning_clamp(f32 value, f32 low, f32 high) {
    if (value < low) {
        return low;
    } else if (value > high) {
        return high;
    } else {
        return value;
    }
}

/* WARNING: compiler-diff device, not original code (carried from main: opt_propagation off) */
#pragma opt_propagation off
void fn_15_11DC(void) {
    WinningTimeline *timeline;
    WinCar *car;
    s32 index;
    s32 first_index;
    WinCar *first_car;
    FontDrawPacket packet;
    WinResult result;
    CameraState *camera;
    LiveCamera *live;
    f32 fade;
    f32 value;
    f32 previous_scale;
    f64 scale_step;
    s32 frame;
    u8 skip;

    if (lbl_15_bss_14 & 0x78) {
        camera_set_entry_field_0xa8(0, 2);
    } else {
        camera_set_entry_field_0xa8(0, 2);
    }
    if (lbl_15_bss_14 & 0x78) {
        fn_15_4578();
    }
    if (lbl_15_bss_14 & 0x10000000) {
        return;
    }

    if (lbl_15_bss_14 & 4) {
        for (first_car = lbl_15_bss_4C, first_index = 0; (s16)first_index < lbl_15_bss_3A; ++first_index, ++first_car) {
            first_car->flags |= 0x100000;
            if (lbl_15_bss_18 <= 350) {
                first_car->unk_200 = 0.0f;
                first_car->unk_DC = 0.0f;
            }
        }
        if (lbl_15_bss_18 == 1) {
            for (car = lbl_15_bss_4C, index = 0; (s16)index < lbl_15_bss_38; ++index, ++car) {
                car->flags |= 0x400;
            }
            lbl_15_bss_20 = 1;
        }
        if (lbl_15_bss_18 == 350) {
            for (car = lbl_15_bss_4C, index = 0; (s16)index < lbl_15_bss_3A; ++index, ++car) {
                car->flags &= ~0x8000;
            }
            lbl_15_bss_14 |= 0x40000000;
        }
        if (lbl_15_bss_18 == 1029) {
            fn_1_4A00(0, 12, lbl_15_bss_10);
        }
        if (lbl_15_bss_18 == 1041) {
            fn_15_4060();
            fn_1_5370(4, 0);
        }
        if (lbl_15_bss_18 == 1044) {
            if ((s32)fn_1_467F4() == 0) {
                fn_15_30E8();
            }
            fn_1_5370(4, 0);
            fn_1_4A00(1, 15, lbl_15_bss_10);
            fn_15_398C();
            fn_1_15B544();
            fn_1_15B5CC();
            fn_1_15B588();
            lbl_15_bss_58 = 1;
        }
        if (lbl_15_bss_18 == 2280) {
            fn_1_4A00(0, 120, lbl_15_bss_10);
            lbl_1_bss_6EAB4 |= 0xAC;
            fn_1_A2A70(12, 120);
        }
        if (lbl_15_bss_18 == 2400) {
            fn_15_B90();
        }
        frame = lbl_15_bss_18;
        if (frame == 1219) lbl_15_bss_54 = 1;
        if (frame == 1393) lbl_15_bss_50 = 1;
        if (frame == 1586) lbl_15_bss_50 = 2;
        if (frame == 1739) lbl_15_bss_54 = 0;
        if (frame == 2087) {
            lbl_15_bss_54 = 1;
            lbl_15_bss_50 = 0;
        }
    } else if (lbl_15_bss_14 & 2) {
        for (car = lbl_15_bss_4C, index = 0; (s16)index < lbl_15_bss_3A; ++index, ++car) {
            car->flags |= 0x100000;
            if (lbl_15_bss_18 <= 350) {
                car->unk_200 = 0.0f;
                car->unk_DC = 0.0f;
            }
        }
        if (lbl_15_bss_18 == 1) {
            for (car = lbl_15_bss_4C, index = 0; (s16)index < lbl_15_bss_38; ++index, ++car) {
                car->flags |= 0x400;
            }
        }
        if (lbl_15_bss_18 == 350) {
            for (car = lbl_15_bss_4C, index = 0; (s16)index < lbl_15_bss_3A; ++index, ++car) {
                car->flags &= ~0x8000;
            }
            lbl_15_bss_14 |= 0x40000000;
        }
        frame = lbl_15_bss_18;
        if (frame == 523) lbl_15_bss_20 = 1;
        if (frame == 3292) fn_1_4A00(0, 12, lbl_15_bss_10);
        if (lbl_15_bss_18 == 3304) {
            fn_15_4060();
            fn_1_5370(4, 0);
        }
        if (lbl_15_bss_18 == 3307) {
            if ((s32)fn_1_467F4() == 0) fn_15_30E8();
            fn_1_5370(4, 0);
            fn_1_4A00(1, 15, lbl_15_bss_10);
            fn_15_398C();
            fn_1_15B544();
            fn_1_15B5CC();
            fn_1_15B588();
            lbl_15_bss_58 = 1;
        }
        if (lbl_15_bss_18 == 4680) fn_1_15B654();
        if (lbl_15_bss_18 == lbl_15_data_90.results_start) fn_15_DD8();
        frame = lbl_15_bss_18;
        if (frame == 3662) lbl_15_bss_54 = 1;
        if (frame == 4011) lbl_15_bss_54 = 0;
    } else if (lbl_15_bss_14 & 0x78) {
        lbl_15_bss_20 = 1;
        if (lbl_15_bss_18 == 15) fn_1_4A00(1, 244, lbl_15_bss_10);
        if (lbl_15_bss_18 == 3292) fn_1_4A00(0, 12, lbl_15_bss_10);
        if (lbl_15_bss_18 == 3304 && !(lbl_15_bss_14 & 0x40)) {
            fn_15_4060();
            fn_1_5370(4, 0);
        }
        if (lbl_15_bss_18 == 3307) {
            if (lbl_15_bss_14 & 0x40) {
                fn_15_B90();
                return;
            }
            if ((s32)fn_1_467F4() == 0 && !(lbl_15_bss_14 & 0x40)) fn_15_30E8();
            fn_1_5370(4, 0);
            fn_1_4A00(1, 15, lbl_15_bss_10);
            fn_15_398C();
            fn_1_15B544();
            fn_1_15B5CC();
            fn_1_15B588();
            lbl_15_bss_58 = 1;
        }
        if (lbl_15_bss_18 == 4680) fn_1_15B654();
        timeline = &lbl_15_data_90;
        {
        s32 trigger_frame = timeline->results_start;
        s32 current_frame = lbl_15_bss_18;
        if (current_frame == trigger_frame) {
            result = lbl_15_bss_2C->result;
            if (result.rank == 0 && lbl_15_bss_3E == 0 && !(lbl_15_bss_14 & 0x20000000)) {
                lbl_15_bss_23 = 1;
                fn_15_DD8();
            } else {
                lbl_15_bss_40 = 1;
            }
        }
        }
        if (lbl_15_bss_40 >= 1) {
            camera = camera_get_state_object();
            /* Retail reads this phase counter as signed with lha. */
            camera->unk_20 += 2;
            if (camera_are_flags_enabled()) {
                live = live_camera_get();
                live->unk_5C += 2;
            }
            frame = lbl_15_bss_18;
            value = 1.0f - (timeline->results_start + 30 - frame) / 30.0f;
            fade = winning_clamp(value, 0.0f, 1.0f);
            if (frame >= lbl_15_data_90.results_end && (lbl_15_bss_34 || lbl_15_bss_35)) {
                value = (lbl_15_data_90.results_end + 30 - frame) / 30.0f;
                fade = winning_clamp(value, 0.0f, 1.0f);
            }
            previous_scale = lbl_15_bss_60;
            scale_step = 0.01 * (2.0f - previous_scale);
            lbl_15_bss_60 = (previous_scale + scale_step);
            packet = lbl_1_rodata_26F8;
            packet.x = 320.0f;
            packet.y = 240.0f;
            packet.z = 20.0f;
            packet.image = 0x8C04;
            packet.flags = 0xA;
            packet.alpha = fade;
            fn_1_4F734(&packet);

            packet.image = 0x8C06;
            packet.z = 10.0f;
            if (lbl_15_bss_18 > timeline->results_start + 20) {
                packet.scale_x = 2.0f * lbl_15_bss_60;
                packet.scale_y = packet.scale_x;
                if (packet.scale_y > 2.0f) {
                    value = 2.0f - (packet.scale_x - 2.0f);
                    packet.scale_y = winning_clamp(value, 0.0f, 2.0f);
                }
            } else {
                packet.scale_x = 0.0f;
                packet.scale_y = 0.0f;
            }
            packet.alpha = packet.scale_y / 2.0f;
            fn_1_4F734(&packet);

            packet.z = 30.0f;
            packet.image = 0x8C06;
            {
                static const GXColor gold = {0xFF, 0xC8, 0x00, 0xFF};
                *(GXColor *)packet.color = gold;
            }
            if (lbl_15_bss_18 > timeline->results_start + 20) {
                packet.scale_x = 3.0f * lbl_15_bss_60;
                packet.scale_y = packet.scale_x;
                if (packet.scale_y > 3.0f) {
                    value = 3.0f - (packet.scale_x - 3.0f);
                    packet.scale_y = winning_clamp(value, 0.0f, 3.0f);
                }
            } else {
                packet.scale_x = 0.0f;
                packet.scale_y = 0.0f;
            }
            packet.alpha = packet.scale_y / 3.0f;
            fn_1_4F734(&packet);
            if (lbl_15_bss_18 == timeline->results_start + 60) {
                fn_8004BF0C(lbl_1_bss_6EAD0->adxt1, 0);
                fn_800674FC(3, 0xA0100000, 0x7F);
                fn_1_A2D84(0xA91A0600);
            }
        } else {
            lbl_15_bss_60 = 0.0f;
        }
        timeline = &lbl_15_data_90;
        if (lbl_15_bss_18 == timeline->results_end + 40 && (lbl_15_bss_34 || lbl_15_bss_35)) {
            fn_1_A2D84(0xA91A0700);
        }
        if (lbl_15_bss_18 >= timeline->results_end && lbl_15_bss_34) {
            skip = lbl_1_bss_5138.skip;
            if (lbl_15_bss_18 >= lbl_15_data_90.hide_result_at) {
                lbl_15_bss_36 = 0;
            } else {
                value = 1.0f - (timeline->results_end + 30 - lbl_15_bss_18) / 30.0f;
                lbl_15_bss_44 = winning_clamp(value, 0.0f, 1.0f);
            }
            if ((s32)skip != 0) {
                value = lbl_15_bss_44 - 0.04f;
                lbl_15_bss_44 = winning_clamp(value, 0.0f, 1.0f);
            }
            fn_15_5460(lbl_15_bss_44);
        }
        if (lbl_15_bss_18 >= timeline->results_end && lbl_15_bss_35 && !lbl_15_bss_34) {
            skip = lbl_1_bss_5138.skip;
            if (lbl_15_bss_18 >= lbl_15_data_90.hide_result_at) {
                lbl_15_bss_36 = 0;
            } else {
                value = 1.0f - (timeline->results_end + 30 - lbl_15_bss_18) / 30.0f;
                lbl_15_bss_48 = winning_clamp(value, 0.0f, 1.0f);
            }
            if ((s32)skip != 0) {
                value = lbl_15_bss_48 - 0.04f;
                lbl_15_bss_48 = winning_clamp(value, 0.0f, 1.0f);
            }
            fn_15_5730(lbl_15_bss_48);
        }
        if (lbl_15_bss_18 == lbl_15_data_90.exit_at) {
            lbl_15_bss_40 = 4;
            lbl_15_bss_23 = 1;
            fn_15_DD8();
        }
        frame = lbl_15_bss_18;
        if (frame == 3517) lbl_15_bss_54 = 1;
        if (frame == 3866) lbl_15_bss_54 = 0;
    } else if (lbl_15_bss_14 & 0x80) {
        fn_1_15B544();
        fn_1_15B5CC();
        fn_1_15B588();
        fn_15_398C();
        lbl_15_bss_58 = 1;
    }
    if (lbl_15_bss_18 < 18000) {
        ++lbl_15_bss_18;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_15_11DC */

/* fzgx:begin fn_15_1D7C */
void fn_15_1D7C(void) {
    if ((lbl_15_bss_14 & 0x78) == 0) {
        fn_1_4A00(1, 30, lbl_15_bss_10);
    } else {
        fn_1_4A00(0, 0, lbl_15_bss_10);
    }
    fn_15_1F28(lbl_15_bss_C, lbl_15_bss_10);
    if (lbl_15_bss_14 & 1) {
        fn_15_FCC();
    }
}
/* fzgx:end fn_15_1D7C */

/* fzgx:begin fn_15_1DF4 */
void fn_15_1DF4(void) {
    s32 skip;
    s32 pressed;

    if (lbl_15_bss_14 & 1) {
        fn_15_11DC();
    }
    if ((((lbl_1_bss_9F8[lbl_1_bss_25E98].unk_8 >> 8) & 1) || ((lbl_1_bss_9F8[lbl_1_bss_25E98].unk_8 >> 12) & 1)) &&
        fn_1_B7C00() == 0 && lbl_15_bss_20 != 0 || lbl_15_bss_22 != 0) {
        fn_15_DD8();
    }
    skip = lbl_1_bss_5138.skip;
    if (skip != 0) {
        pressed = (lbl_1_bss_9F8[lbl_1_bss_25E98].unk_8 >> 8) & 1;
        if (lbl_1_bss_5138.skip != 0 && pressed != 0 &&
            lbl_1_bss_5138.held_frames >= 15 && lbl_1_bss_5138.held_frames <= 120) {
            lbl_1_bss_5138.held_frames = 120;
        }
    }
}
/* fzgx:end fn_15_1DF4 */

/* fzgx:begin fn_15_1EE0 */
void fn_15_1EE0(void) {
    fn_15_236C(lbl_15_bss_C, lbl_15_bss_10);
    if (lbl_15_bss_14 & 1) {
        camera_enable_flags();
    }
}
/* fzgx:end fn_15_1EE0 */

/* fzgx:begin fn_15_1F28 */
void fn_15_1F28(u32 arg0, u32 arg1) {
    lbl_15_bss_64 = 0;
    lbl_15_bss_68 = 0;
    lbl_15_bss_6C = 0;
    lbl_15_bss_70 = 0;
    lbl_15_bss_3E = 0;
    fn_1_A0680();
    fn_1_41048();
    lbl_15_bss_74 = arg0;
    lbl_15_bss_78 = arg1;
    fn_15_2AE4();
    if (!(lbl_15_bss_14 & 0x80)) {
        fn_15_2E8C();
    }
    lbl_15_bss_8 = fn_1_45D0(lbl_801A6410, fn_1_7BA08(0x20, 0x20, 0x40), "winning.c", 0x647);
    fn_1_435C(arg0);
    fn_1_3F8C("WinningCalc", fn_15_2228, NULL, 5);
    fn_1_435C(arg1);
    fn_1_7BA48(lbl_15_bss_8);
    fn_1_3F8C("LightMain", fn_1_7BAF8, (void *)lbl_15_bss_8, 3);
    fn_1_3F8C("mot_light_calc", fn_15_537C, NULL, 5);
    fn_1_3F8C("WinningDisp", fn_15_2274, NULL, 10);
    fn_1_3F8C("mot_light_disp", fn_15_545C, NULL, 11);
    fn_15_3A14();
    {
        Vec3 dir = {0.0f, 0.0f, 200.0f};

        lbl_15_bss_7C = lbl_15_bss_88 = dir;
    }
    lbl_15_bss_94 = -0x2000;
    lbl_15_bss_96 = 0x2000;
    lbl_8006D758();
    mathutil_mtxA_rotate_y(lbl_15_bss_96);
    mathutil_mtxA_rotate_x(lbl_15_bss_94);
    lbl_8006E1B0(&lbl_15_bss_7C, &lbl_15_bss_88);
    fn_80074CF4(0.6f, 0.6f, 0.6f);
    if (lbl_1_bss_6EAD0->adxt0 == NULL) {
        lbl_1_bss_6EAD0->adxt0 = fn_8004CD70(2, lbl_1_bss_6EAD0->work0, sizeof(lbl_1_bss_6EAD0->work0));
    }
    if (lbl_1_bss_6EAD0->adxt1 == NULL) {
        lbl_1_bss_6EAD0->adxt1 = fn_8004CD70(2, lbl_1_bss_6EAD0->work1, sizeof(lbl_1_bss_6EAD0->work1));
    }
    fn_80051E64(lbl_1_bss_6EAD0->adxt1, lbl_1_bss_6EAD0->work2, sizeof(lbl_1_bss_6EAD0->work2));
    fn_1_A1588(lbl_1_bss_6EAD0->adxt0, 0x35);
    ADXT_Pause(lbl_1_bss_6EAD0->adxt0, 1);
    lbl_15_bss_98 = 0;
    fn_8004BF0C(lbl_1_bss_6EAD0->adxt0, -0x50);
    fn_8004BF0C(lbl_1_bss_6EAD0->adxt1, -0x50);
    camera_set_state_flag(1);
    fn_1_5124(arg0, arg1);
    if (!(lbl_15_bss_14 & 1)) {
        fn_1_5370(4, 0);
    }
    fn_1_9A578();
    if (!(lbl_15_bss_14 & 0x80)) {
        fn_15_3B24();
    }
}
/* fzgx:end fn_15_1F28 */

/* fzgx:begin fn_15_2228 */
void fn_15_2228(void) {
    if (lbl_15_bss_14 & 0x80000000) {
        fn_15_4124();
    }
    fn_15_2CEC();
    fn_15_3AFC();
    if (lbl_15_bss_21 != 0) {
        fn_15_401C();
    }
}
/* fzgx:end fn_15_2228 */

/* fzgx:begin fn_15_2274 */
void fn_15_2274(void) {
    if (lbl_15_bss_14 & 0x80000000) {
        fn_15_435C();
    }
    switch (lbl_15_bss_70) {
    case 0: {
        GXColor color = {0x00, 0x00, 0x00, 0xFF};
        fn_80007AB4(&color);
        break;
    }
    case 1: {
        GXColor color = {0x40, 0x40, 0x40, 0xFF};
        fn_80007AB4(&color);
        break;
    }
    case 2: {
        GXColor color = {0x40, 0x40, 0x88, 0xFF};
        fn_80007AB4(&color);
        break;
    }
    case 3: {
        GXColor color = {0xAA, 0xAA, 0xAA, 0xFF};
        fn_80007AB4(&color);
        break;
    }
    default: {
        GXColor color = {0xFF, 0x00, 0x00, 0xFF};
        fn_80007AB4(&color);
        break;
    }
    }
    if (lbl_15_bss_21 != 0) {
        fn_15_405C();
    }
    if (lbl_15_bss_14 & 0x80) {
        fn_15_2D74();
    }
}
/* fzgx:end fn_15_2274 */

/* fzgx:begin fn_15_236C */
void fn_15_236C(u32 arg0, u32 arg1) {
    fn_1_469BC();
    ADXT_Stop(lbl_1_bss_6EAD0->adxt0);
    ADXT_Stop(lbl_1_bss_6EAD0->adxt1);
    fn_1_A0AA4();
    fn_15_2CF0();
    if (!(lbl_15_bss_14 & 0x80)) {
        fn_15_38FC();
    }
    fn_15_3B00();
    if (lbl_15_bss_21 != 0) {
        fn_15_4060();
    }
    if (lbl_15_bss_8 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_15_bss_8, "winning.c", 0x6E8);
        lbl_15_bss_8 = 0;
    }
    fn_1_435C(arg0);
    fn_1_41A8();
    fn_1_435C(arg1);
    fn_1_41A8();
    fn_1_410A0();
    fn_1_6400();
}
/* fzgx:end fn_15_236C */

/* fzgx:begin fn_15_2458 */
void fn_15_2458(s16 id, s16 slot, s16 index, u32 kind) {
    u32 color;
    WinRob *rob;

    switch ((31 - __cntlzw(lbl_15_bss_2C->racers[index].color)) & 3) {
    case 0:
        color = 0x80000000;
        break;
    case 1:
        color = 0x40000000;
        break;
    case 2:
        color = 0x20000000;
        break;
    case 3:
        color = 0x10000000;
        break;
    default:
        color = 0x80000000;
        break;
    }
    lbl_15_bss_9C[slot] = fn_1_4630(lbl_801A6410, sizeof(WinRob), "winning.c", 0x719);
    rob = lbl_15_bss_9C[slot];
    if (kind == 0x30000000 || kind == 0x30000000) {
        if (lbl_15_bss_14 & 0x80) {
            fn_1_8F45C(rob, id, kind, color);
        } else {
            fn_1_8F198(rob, id, kind, color);
        }
    } else {
        fn_1_8F198(rob, id, kind, color);
    }
    fn_1_934CC(rob, &rob->anim, lbl_15_data_20[index]);
    rob->flags |= 0xC0000000U;
    rob->unk_4C4 = index;
    fn_1_435C(lbl_15_bss_74);
    fn_1_3F8C("RobExec", fn_1_8F62C, rob, 10);
    fn_1_3F8C("set_winner_rank", fn_15_27D4, rob, 11);
    fn_1_435C(lbl_15_bss_78);
    fn_1_3F8C("RobDispClip", fn_1_92530, rob, 10);
}
/* fzgx:end fn_15_2458 */

/* fzgx:begin fn_15_2620 */
void fn_15_2620(WinRob *rob) {
    u32 color;

    switch (rob->unk_88) {
    case 33:
    case 42:
    case 43:
        if (lbl_15_bss_54 != 0 && rob->unk_4C4 == lbl_15_bss_50) {
            rob->unk_8C = 2;
        } else {
            rob->unk_8C = 3;
        }
        break;
    case 21:
    case 41:
        if (lbl_15_bss_54 != 0 && rob->unk_4C4 == lbl_15_bss_50) {
            rob->unk_8C = 2;
        } else {
            rob->unk_8C = 3;
        }
        break;
    default:
        if ((lbl_15_bss_14 & 0x04000000) && !(lbl_15_bss_14 & 0x80)) {
            if (lbl_15_bss_54 != 0 && rob->unk_4C4 == lbl_15_bss_50) {
                rob->unk_8C = 1;
            } else {
                rob->unk_8C = 2;
            }
        } else {
            rob->unk_8C = 1;
        }
        break;
    }
    if (lbl_15_bss_58 != 0) {
        rob->flags &= ~0x20000000;
    } else {
        rob->flags |= 0x20000000;
    }
    switch ((31 - __cntlzw(lbl_15_bss_2C->racers[rob->unk_4C4].color)) & 3) {
    case 0:
        color = 0;
        break;
    case 1:
        color = 1;
        break;
    case 2:
        color = 2;
        break;
    case 3:
        color = 3;
        break;
    default:
        color = 0;
        break;
    }
    if (rob->unk_98 != color) {
        fn_1_8E728(rob, color);
    }
}
/* fzgx:end fn_15_2620 */

/* fzgx:begin fn_15_27D4 */
void fn_15_27D4(WinRob *rob) {
    StageInfo *info = lbl_1_data_2A7E0.info;

    switch (rob->unk_4C4) {
    case 0:
        rob->unk_A8 = info->unk_1C;
        break;
    case 1:
        rob->unk_A8 = info->unk_28;
        break;
    case 2:
        rob->unk_A8 = info->unk_34;
        break;
    default:
        rob->unk_A8 = info->unk_34;
        rob->unk_A8.x -= 1.0f;
        rob->unk_A8.y -= 0.5f;
        break;
    }
    if (lbl_15_bss_14 & 0x80) {
        switch (lbl_15_bss_2C->unk_192) {
        case 4:
            switch (rob->unk_4C4) {
            case 0:
                rob->unk_A8.x = 1.0f + info->unk_1C.x;
                rob->unk_A8.y = 0.5f + info->unk_1C.y;
                rob->unk_A8.z = 1.5f + info->unk_1C.z;
                break;
            case 1:
                rob->unk_A8.x = 1.0f + info->unk_28.x;
                rob->unk_A8.y = 0.5f + info->unk_28.y;
                rob->unk_A8.z = 1.5f + info->unk_28.z;
                break;
            case 2:
                rob->unk_A8.x = 1.0f + info->unk_34.x;
                rob->unk_A8.y = 0.5f + info->unk_34.y;
                rob->unk_A8.z = 1.5f + info->unk_34.z;
                break;
            default:
                rob->unk_A8.x = -0.9f + info->unk_34.x;
                rob->unk_A8.y = info->unk_34.y;
                rob->unk_A8.z = 1.5f + info->unk_34.z;
                break;
            }
            break;
        case 3:
            rob->unk_A8.z += 1.5f;
            break;
        case 2:

            switch (rob->unk_4C4) {
            case 0:
                rob->unk_A8.x = 1.0f + info->unk_1C.x;
                rob->unk_A8.y = info->unk_1C.y;
                rob->unk_A8.z = 1.5f + info->unk_1C.z;
                break;
            case 1:
                rob->unk_A8.x = 1.0f + info->unk_34.x;
                rob->unk_A8.y = info->unk_34.y;
                rob->unk_A8.z = 1.5f + info->unk_34.z;
                break;
            }
            info->unk_54->pos = (Vec3){0.0f, 0.0f, 0.0f};
            break;
        }
        info->unk_4C[rob->unk_4C4]->pos = rob->unk_A8;
    }
    rob->unk_B8 = 1.0f;
    fn_15_2620(rob);
    if (rob->unk_88 == 1) {
        rob->flags |= 0x20000000;
    }
}
/* fzgx:end fn_15_27D4 */

/* fzgx:begin fn_15_2AE4 */
void fn_15_2AE4(void) {
    WinRacer *racers;
    s16 i;
    s16 k;

    lbl_15_bss_58 = 1;
    lbl_15_bss_54 = 1;
    lbl_15_bss_5C = 1;
    lbl_15_bss_4 = 0;
    racers = lbl_15_bss_2C->racers;
    for (i = 0; i < 12; i++) {
        lbl_15_bss_9C[i] = NULL;
    }
    for (i = 0; i < lbl_15_bss_38; i++) {
        s16 c = racers[i].unk_4;

        if (c >= 41) {
            // Wide codes collapse to one representative byte.
            c = racers[i].machine->unk_81A0;
        }
        if (c == 34) {
            lbl_15_bss_4++;
        }
    }
    for (i = 0; i < lbl_15_bss_38; i++) {
        s16 c = racers[i].unk_4;

        if (c >= 41) {
            c = racers[i].machine->unk_81A0;
        }
        switch (fn_1_12CB04(c)) {
        case 2:
            k = lbl_15_bss_38 + i * 2;
            fn_15_2458(c, i, i, 0x30000000);
            fn_15_2458(fn_1_12CCB0(c, 0), k, i, 0x30000000);
            fn_15_2458(fn_1_12CCB0(c, 1), k + 1, i, 0x30000000);
            break;
        case 1:
            k = lbl_15_bss_38 + i * 2;
            fn_15_2458(c, i, i, 0x30000000);
            fn_15_2458(fn_1_12CCB0(c, 0), k, i, 0x30000000);
            break;
        case 0:
            fn_15_2458(c, i, i, 0x60000000);
            break;
        }
    }
}
/* fzgx:end fn_15_2AE4 */

/* fzgx:begin fn_15_2CEC */
// fn_15_2CEC: empty in retail (single blr).
void fn_15_2CEC(void) {
}
/* fzgx:end fn_15_2CEC */

/* fzgx:begin fn_15_2CF0 */
void fn_15_2CF0(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (lbl_15_bss_9C[i] != NULL) {
            fn_1_8F494(lbl_15_bss_9C[i]);
            fn_1_46B4(lbl_801A6410, (u32)lbl_15_bss_9C[i], "winning.c", 0x8CF);
            lbl_15_bss_9C[i] = NULL;
        }
    }
}
/* fzgx:end fn_15_2CF0 */

/* fzgx:begin fn_15_2D74 */
void fn_15_2D74(void) {
    s16 table[4] = {0, 3, 4, 6};
    Vec3 pos = {0.0f, 1.0f, 0.0f};
    f32 mtx[3][4];
    f32 scale;
    WinRob **robs;
    s16 i;
    u8 *motion;

    scale = fn_1_A71AC();
    robs = lbl_15_bss_9C;
    for (i = 0; i < lbl_15_bss_38; i++) {
        motion = (*robs)->anim.motion->data;
        lbl_8006D7DC(&(*robs)->unk_A8);
        lbl_8006DFC4(motion + 0x214);
        lbl_8006DB74(mtx);
        fn_1_129D9C(mtx, &pos, 0, lbl_1_bss_38458->models[table[lbl_15_bss_2C->order[i]]].model, 0, 0, 1, scale);
        robs++;
    }
}
/* fzgx:end fn_15_2D74 */

/* fzgx:begin fn_15_2E8C */
void fn_15_2E8C(void) {
    WinRacer *racers;
    s16 c;
    s16 i;
    u8 bonus;
    s16 j;

    lbl_15_bss_CC = lbl_15_bss_CE = 0;
    racers = lbl_15_bss_2C->racers;
    lbl_15_bss_D0 = 0;
    for (i = 0; i < 29; i++) {
        lbl_15_bss_D4[i] = NULL;
    }
    bonus = 0;
    for (i = 0; i < lbl_15_bss_38; i++) {
        switch (racers[i].id) {
        case 19:
            bonus += 3;
            break;
        case 30:
            bonus += 1;
            break;
        case 34:
            if (i == 0) {
                bonus += 6;
            } else {
                bonus += 3;
            }
            break;
        case 40:
            bonus += 1;
            break;
        case 16:
            bonus += 2;
            break;
        }
    }
    lbl_15_bss_14C = 26 - bonus;
    for (j = 0; j < lbl_15_bss_14C; j++) {
        c = racers[j + lbl_15_bss_38].id;
        if (c >= 41) {
            c = racers[j + lbl_15_bss_38].machine->unk_81A0;
        }
        switch (fn_1_12CB04(c)) {
        case 2:
            lbl_15_bss_D0 = 1;
            fn_1_8E4A4(c, 0x10000000, 0x80000000);
            fn_1_8E4A4(fn_1_12CCB0(c, 0), 0x10000000, 0x80000000);
            fn_1_8E4A4(fn_1_12CCB0(c, 1), 0x10000000, 0x80000000);
            break;
        case 1:
            fn_1_8E4A4(c, 0x10000000, 0x80000000);
            fn_1_8E4A4(fn_1_12CCB0(c, 0), 0x10000000, 0x80000000);
            break;
        case 0:
            fn_1_8E4A4(c, 0x10000000, 0x80000000);
            break;
        }
    }
}
/* fzgx:end fn_15_2E8C */

/* fzgx:begin fn_15_30E8 */
void fn_15_30E8(void) {
    WinRacer *racers;
    s32 i;
    s16 id;

    racers = lbl_15_bss_2C->racers;
    for (i = 0; i < lbl_15_bss_14C; i++) {
        id = racers[i + lbl_15_bss_38].id;
        if (id >= 41) {
            id = racers[i + lbl_15_bss_38].machine->unk_81A0;
        }
        fn_15_3368(id);
    }
}
/* fzgx:end fn_15_30E8 */

/* fzgx:begin fn_15_3174 */
/* WARNING: compiler-diff device, not original code (carried from main: opt_propagation off, and
   the locals that hold the y and z constants before the x store) */
#pragma opt_propagation off
void fn_15_3174(WinRob *rob) {
    u8 index;
    StageInfo *info;
    s16 n;
    f32 y1;
    f32 half2;
    f32 y2;
    f32 y3;
    f32 z3;
    f32 half4;
    f32 base4;
    f32 y4;
    f32 z4;
    f32 y5;
    f32 z5;
    f32 y6;

    index = rob->unk_4C4;
    info = lbl_1_data_2A7E0.info;
    n = index;
    if (n < 8) {
        y1 = 0.0f;
        rob->unk_A8.x = -1.5f + 0.5f * n;
        rob->unk_A8.y = y1;
        rob->unk_A8.z = y1;
    } else if (n < 17) {
        half2 = 0.5f;
        y2 = 0.0f;
        rob->unk_A8.x = -2.25f + half2 * (n - 8);
        rob->unk_A8.y = y2;
        rob->unk_A8.z = half2;
    } else if (n < 26) {
        y3 = 0.0f;
        z3 = 1.0f;
        rob->unk_A8.x = -2.0f + 0.5f * (n - 17);
        rob->unk_A8.y = y3;
        rob->unk_A8.z = z3;
    } else {
        half4 = 0.5f;
        base4 = -2.25f;
        z4 = 1.5f;
        y4 = 0.2f;
        rob->unk_A8.x = base4 + half4 * (n - 26);
        rob->unk_A8.y = y4;
        rob->unk_A8.z = z4;
    }
    if (rob->unk_88 == 33 || rob->unk_88 == 42 || rob->unk_88 == 43) {
        y5 = 0.0f;
        z5 = -0.2f;
        rob->unk_A8.x = -2.2f;
        rob->unk_A8.y = y5;
        rob->unk_A8.z = z5;
    }
    if ((s16)index == 26 && lbl_15_bss_D0 == 0) {
        y6 = 0.0f;
        rob->unk_A8.x = -2.0f;
        rob->unk_A8.y = y6;
        rob->unk_A8.z = y6;
    }
    lbl_8006D7DC(info->mtx);
    lbl_8006E1B0(&rob->unk_A8, &rob->unk_A8);
    rob->unk_B8 = 1.0f;
}
#pragma opt_propagation reset
/* fzgx:end fn_15_3174 */

/* fzgx:begin fn_15_3368 */
static inline void winning_rob_create(s16 id) {
    WinRob *rob;

    lbl_15_bss_D4[lbl_15_bss_CC] = fn_1_4630(lbl_801A6410, sizeof(WinRob), "winning.c", 0x993);
    rob = lbl_15_bss_D4[lbl_15_bss_CC];
    fn_1_8F45C(rob, id, 0x10000000, 0x80000000);
    fn_1_934CC(rob, &rob->anim, "WIN_WAIT");
    rob->flags |= 0xC0000000U;
    rob->unk_4C4 = lbl_15_bss_CE;
    fn_1_435C(lbl_15_bss_74);
    fn_1_3F8C("RobExec", fn_1_8F62C, rob, 10);
    fn_1_3F8C("set_other_rob_pos", fn_15_3174, rob, 11);
    fn_1_435C(lbl_15_bss_78);
    fn_1_3F8C("RobDispClip", fn_1_92530, rob, 10);
}

void fn_15_3368(s32 racer) {
    s16 id = racer;

    switch (fn_1_12CB04(id)) {
    case 2:
        winning_rob_create(id);
        lbl_15_bss_CC++;
        winning_rob_create(fn_1_12CCB0(id, 0));
        lbl_15_bss_CC++;
        winning_rob_create(fn_1_12CCB0(id, 1));
        lbl_15_bss_CC++;
        break;
    case 1:
        winning_rob_create(id);
        lbl_15_bss_CC++;
        winning_rob_create(fn_1_12CCB0(id, 0));
        lbl_15_bss_CC++;
        lbl_15_bss_CE++;
        break;
    case 0:
        winning_rob_create(id);
        lbl_15_bss_CC++;
        lbl_15_bss_CE++;
        break;
    }
}
/* fzgx:end fn_15_3368 */

/* fzgx:begin fn_15_38FC */
#undef WINNING_ROB_CREATE

void fn_15_38FC(void) {
    s16 i;

    fn_1_469BC();
    for (i = 0; i < 29; i++) {
        if (lbl_15_bss_D4[i] != NULL) {
            fn_1_8F494(lbl_15_bss_D4[i]);
            fn_1_46B4(lbl_801A6410, (u32)lbl_15_bss_D4[i], "winning.c", 0x9DA);
            lbl_15_bss_D4[i] = NULL;
        }
    }
}
/* fzgx:end fn_15_38FC */

/* fzgx:begin fn_15_398C */
void fn_15_398C(void) {
    WinRob **p;
    WinRob *rob;
    s16 i;

    lbl_15_bss_14 |= 0x04000000;
    p = lbl_15_bss_9C;
    for (i = 0; i < 12; i++) {
        rob = *p;
        if (rob != NULL) {
            rob->flags &= 0x3FFFFFFF;
        }
        p++;
    }
    p = lbl_15_bss_D4;
    for (i = 0; i < 29; i++) {
        rob = *p;
        if (rob != NULL) {
            rob->flags &= 0x3FFFFFFF;
        }
        p++;
    }
}
/* fzgx:end fn_15_398C */

/* fzgx:begin fn_15_3A14 */
void fn_15_3A14(void) {
    fn_1_435C(lbl_15_bss_74);
    fn_1_3F8C("StageCalc", fn_1_789E8, NULL, 21);
    fn_1_3F8C("BackGroundCalc", fn_1_9A5CC, NULL, 23);
    fn_1_435C(lbl_15_bss_78);
    fn_1_3F8C("FogMain", fn_1_7E9C4, NULL, 4);
    fn_1_3F8C("FogOff", fn_1_7EAE8, NULL, 29);
    fn_1_3F8C("StageDisp", fn_1_78EBC, NULL, 7);
    fn_1_3F8C("BackGroundDisp", fn_1_9A7BC, NULL, 10);
    fn_1_7EAE8();
    fn_1_7ACDC(50);
}
/* fzgx:end fn_15_3A14 */

/* fzgx:begin fn_15_3AFC */
// fn_15_3AFC: empty in retail (single blr).
void fn_15_3AFC(void) {
}
/* fzgx:end fn_15_3AFC */

/* fzgx:begin fn_15_3B00 */
void fn_15_3B00(void) {
    fn_1_79100();
    fn_1_7EAE8();
}
/* fzgx:end fn_15_3B00 */

/* fzgx:begin fn_15_3B24 */
/* WARNING: compiler-diff device, not original code (carried from main: the .fzgxpool literal primer
   of these two .rodata words, fzgx_pool_prime11 in main). Retail has 9.0f at .rodata 0xFC and 1.04f
   at 0x100 here, before the literals of fn_15_3B24. No retail code reads 9.0f, and fn_15_4578 reads
   1.04f again (a deduplicated literal). No function with a retail inlined copy makes these two words.
   The unit has a one-entry pool map (units.json) only so that the build drops the .fzgxpool section. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime_suffix(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 9.0f;
    s = 1.04f;
}
#pragma section code_type ".text"

/* WARNING: compiler-diff device, not original code (carried from main: opt_propagation off) */
#pragma opt_propagation off
void fn_15_3B24(void) {
    CarEntry *entry;
    WinRacer *racer;
    WinEntry *win;
    WinRacer *racers;
    s16 i;
    WinRacer *src;
    WinModel *model;
    RaceCar *rcar;
    WinCar *car;
    s16 j;
    u8 *preset;
    s16 slot;
    WinMachine *machine;
    f32 scale;
    f32 x;
    CarEntry entries[3];
    CarParam param;

    win = lbl_15_bss_2C;
    racers = win->racers;
    lbl_15_bss_21 = 1;
    lbl_15_bss_24 = fn_1_45D0(lbl_801A6410, 0x173C, "winning.c", 0xA4E);
    lbl_15_bss_28 = fn_1_45D0(lbl_801A6410, 0x173C, "winning.c", 0xA4F);
    fn_1_3CF0(lbl_15_bss_24, 128);
    fn_1_3CF0(lbl_15_bss_28, 128);
    fn_1_981C4();
    fn_1_435C(lbl_15_bss_24);
    fn_1_3F8C("Burner", fn_1_98230, NULL, 10);
    fn_1_435C(lbl_15_bss_28);
    fn_1_3F8C("BurnerDisp", fn_1_9835C, NULL, 21);
    fn_1_584D4();
    lbl_15_bss_150 = fn_1_4630(lbl_801A6410, 0x14B8, "winning.c", 0xA66);
    *lbl_15_bss_150 |= 0x20C040;

    racer = racers;
    entry = entries;
    for (i = 0; i < lbl_15_bss_3A; i++) {
        fn_1_80058(racer->id, entry);
        if (lbl_15_bss_14 & 0x40) {
            slot = win->result.rank;
        } else {
            slot = i;
        }
        entry->index = i;
        src = &racers[slot];
        entry->id = src->id;
        entry->color = src->color;
        switch ((31 - __cntlzw(entry->color)) & 3) {
        case 0:
            entry->color = 0x10;
            break;
        case 1:
            entry->color = 0x20;
            break;
        case 2:
            entry->color = 0x40;
            break;
        case 3:
            entry->color = 0x80;
            break;
        default:
            entry->color = 0x10;
            break;
        }
        entry->type = 2;
        if (entry->id >= 41) {
            machine = src->machine;
            if (machine != NULL && (machine->flags & 0x80000000)) {
                fn_80008BEC(entry->parts, 0, 16);
                if (machine->flags & 0x40000000) {
                    lbl_15_bss_3E = 1;
                    if (slot == 0) {
                        if (fn_1_FA088()) {
                            lbl_15_bss_34 = 1;
                            lbl_15_bss_36 = 1;
                            fn_1_FA0A0();
                        }
                        if (fn_1_FA004()) {
                            lbl_15_bss_35 = 1;
                            lbl_15_bss_36 = 1;
                            fn_1_FA01C();
                        }
                    }
                    entry->flags |= 0x4000000;
                    entry->parts[0] = machine->unk_81A4;
                    entry->parts[1] = machine->unk_81AC;
                    entry->parts[2] = machine->unk_81B4;
                } else {
                    entry->id = machine->unk_81A0;
                }
                entry->type_copy = entry->type;
            }
        }
        entry++;
        racer++;
    }

    fn_1_81834(0, -1, 0);
    lbl_15_bss_4C = fn_1_83070(lbl_15_bss_24, lbl_15_bss_28, entries, lbl_15_bss_3A);
    fn_1_82724(lbl_15_bss_24, lbl_15_bss_28, entries, lbl_15_bss_3A, 1);
    fn_1_835E0(lbl_15_bss_150, lbl_15_bss_24, NULL);
    if (!(lbl_15_bss_14 & 1)) {
        fn_1_86194(1000.0f);
    } else if (lbl_15_bss_14 & 0x78) {
        fn_1_86194(0.0f);
    } else {
        fn_1_86194(0.0f);
        fn_1_817C0();
    }
    fn_1_C3A0C(fn_1_86254(0));
    fn_1_435C(lbl_15_bss_24);
    fn_1_3F8C("EnemyTotalControlMain", fn_1_C42F4, fn_1_86254(0), 2);
    fn_1_4310(0);
    fn_1_861B4();
    if (lbl_15_bss_14 & 0x40000000) {
        fn_1_C6F80(1);
    }

    car = lbl_15_bss_4C;
    preset = lbl_1_data_28060 + 0x438;
    scale = 200.0f;
    for (j = 0; j < lbl_15_bss_3A; j++, car++) {
        model = car->model;
        rcar = fn_1_868C0(j);
        rcar->unk_3BA = 1;
        if (!(lbl_15_bss_14 & 0x78)) {
            model->unk_C = 0.0f;
        }
        rcar->unk_390 |= 0x40000;
        model->flags |= 2;
        switch (j) {
        case 0:
            model->unk_32 = 0x22;
            x = 0.0f;
            car->unk_7C = x;
            car->unk_84 = 1.0f;
            x = 0.0f;
            car->unk_94 = x;
            car->unk_98 = x;
            car->unk_9C = x;
            break;
        case 1:
            model->unk_32 = 0x23;
            x = 4.0f;
            car->unk_7C = x;
            car->unk_84 = 5.0f;
            x = 0.0f;
            car->unk_94 = x;
            car->unk_98 = x;
            car->unk_9C = x;
            break;
        case 2:
            model->unk_32 = 0x24;
            x = -4.0f;
            car->unk_7C = x;
            car->unk_84 = 5.0f;
            x = 0.0f;
            car->unk_94 = x;
            car->unk_98 = x;
            car->unk_9C = x;
            break;
        }
        fn_80008BA8(&param, preset, sizeof(CarParam));
        fn_1_22E8C(car, &param);
        car->unk_C = scale;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_15_3B24 */

/* fzgx:begin fn_15_401C */
void fn_15_401C(void) {
    if (lbl_15_bss_14 & 0x40000000) {
        fn_1_C6F80(1);
    } else {
        fn_1_C6F80(0);
    }
}
/* fzgx:end fn_15_401C */

/* fzgx:begin fn_15_405C */
// fn_15_405C: empty in retail (single blr).
void fn_15_405C(void) {
}
/* fzgx:end fn_15_405C */

/* fzgx:begin fn_15_4060 */
void fn_15_4060(void) {
    fn_1_85878();
    fn_1_982C4();
    fn_1_58854();
    fn_1_C47B4();
    fn_1_C6F80(0);
    fn_1_46B4(lbl_801A6410, (u32)lbl_15_bss_150, "winning.c", 0xB21);
    fn_1_435C(lbl_15_bss_24);
    fn_1_41A8();
    fn_1_435C(lbl_15_bss_28);
    fn_1_41A8();
    fn_1_46B4(lbl_801A6410, lbl_15_bss_24, "winning.c", 0xB26);
    fn_1_46B4(lbl_801A6410, lbl_15_bss_28, "winning.c", 0xB27);
    lbl_15_bss_21 = 0;
}
/* fzgx:end fn_15_4060 */

/* fzgx:begin fn_15_4124 */
void fn_15_4124(void) {
    CameraState *camera;
    s32 dir;
    s32 sel;
    s32 m;
    s32 n;
    s32 last;

    camera = camera_get_state_object();

    if ((lbl_1_bss_D58.unk_10 >> 3) & 1) {
        dir = -1;
    } else if ((lbl_1_bss_D58.unk_10 >> 2) & 1) {
        dir = 1;
    } else {
        dir = 0;
    }

    n = lbl_15_bss_38;
    m = n + 3;
    sel = cursor_move((s32 *)&lbl_15_bss_6C, dir, m);
    if (sel < 0) {
        sel = 0;
    } else {
        last = n - 1;
        if (sel > last) {
            sel = last;
        }
    }
    lbl_15_bss_68 = sel;

    if (((lbl_1_bss_D58.unk_0 >> 11) & 1) == 0) {
        if (lbl_1_bss_D58.unk_10 & 1) {
            dir = -1;
        } else if ((lbl_1_bss_D58.unk_10 >> 1) & 1) {
            dir = 1;
        } else {
            dir = 0;
        }
    } else {
        dir = 0;
    }

    if (dir != 0) {
        switch (lbl_15_bss_6C - lbl_15_bss_38) {
        case 0:
            lbl_15_bss_70 = (lbl_15_bss_70 + dir + 4) % 4;
            break;
        case 1:
            camera->unk_1C += dir;
            if (camera->unk_1C > 55.0f) {
                camera->unk_1C = 55.0f;
            }
            if (camera->unk_1C < 30.0f) {
                camera->unk_1C = 30.0f;
            }
            break;
        case 2:
            lbl_15_bss_98 += dir;
            switch (lbl_15_bss_98 % 3) {
            case 0:
                fn_1_A1588(lbl_1_bss_6EAD0->adxt0, 0x11);
                break;
            case 1:
                fn_1_A1588(lbl_1_bss_6EAD0->adxt0, 0x35);
                break;
            default:
                fn_1_A1588(lbl_1_bss_6EAD0->adxt0, 0x42);
                break;
            }
            break;
        }
    }
}
/* fzgx:end fn_15_4124 */

/* fzgx:begin fn_15_435C */
void fn_15_435C(void) {
    u16 name[16];
    GXColor colors[3] = {
        {0x00, 0xFF, 0x00, 0xFF},
        {0x80, 0x80, 0x80, 0xFF},
        {0xFF, 0xFF, 0xFF, 0xFF},
    };
    GXColor current;
    GXColor color;
    GXColor normal;
    CameraState *camera;
    WinRob **robs;
    s32 i;

    camera = camera_get_state_object();
    fn_1_49410();
    fn_1_4954C(2.0f);
    fn_1_4955C(0.5f, 0.5f);
    fn_1_495FC();
    fn_1_496FC(10.0f, 40.0f);
    normal = colors[2];
    robs = lbl_15_bss_9C;
    i = 0;

    while (i < lbl_15_bss_38 + 3) {
        if (i == lbl_15_bss_6C) {
            current = colors[0];
            fn_1_49514(&current);
        } else {
            color = normal;
            fn_1_49514(&color);
        }

        if (i < lbl_15_bss_38) {
            WinRob *rob = *robs;
            u32 char_color = lbl_1_data_20B14[fn_1_12C930(rob->unk_88)];

            fn_1_7F49C(fn_1_12C710(rob->unk_88), 5, name);
            fn_1_4AE0C("%1d\x88\xCA : %s(%s) \n", i + 1, char_color, name);
        } else {
            switch (i - lbl_15_bss_38) {
            case 0:
                fn_1_4AE0C("\x94w\x8Ci \x81" "F %s \n", lbl_15_data_50[lbl_15_bss_70]);
                break;
            case 1:
                fn_1_4AE0C("\x83p\x81[\x83X: %5.2f\n", camera->unk_1C);
                break;
            case 2:
                switch (lbl_15_bss_98 % 3) {
                case 0:
                    fn_1_4A0D8("BGM: \x81\xF4\x95\\\x8F\xB2" "AC");
                    break;
                case 1:
                    fn_1_4A0D8("BGM: \x81\xF4\x95\\\x8F\xB2GC \x83" "E\x83" "C\x83j\x83\x93\x83O\x83\x89\x83\x93");
                    break;
                default:
                    fn_1_4A0D8("BGM: \x81\xF4\x83t\x83@\x83\x8B\x83R\x83\x93\x82\xCC\x83" "e\x81[\x83}\x81iAC\x83G\x83\x93\x83" "f\x83" "B\x83\x93\x83O\x81j");
                    break;
                }
                break;
            default:
                fn_1_4AE0C("DUMMY\n");
                break;
            }
        }
        robs++;
        i++;
    }
}
/* fzgx:end fn_15_435C */

/* fzgx:begin fn_15_4568 */
void fn_15_4568(void) {
    lbl_15_bss_154 = 0;
}
/* fzgx:end fn_15_4568 */

/* fzgx:begin fn_15_4578 */
ResultRow lbl_15_data_36C[6][7] = {
    {
        {0x006400C8, {0.1f, 0.07f, 0.0f, 700.0f, 0.0f, -1, "MUTECITY", ""}},
        {0xFFFFFFFF, {0.09f, 0.08f, 0.0f, 700.0f, 60.0f, -1, "RANK", "1"}},
        {0xFFFFFFFF, {0.08f, 0.09f, 0.0f, 700.0f, 90.0f, -1, "TIME", "01'59\"980"}},
        {0xFFFFFFFF, {0.075f, 0.1f, 0.0f, 700.0f, 120.0f, -1, "BEST LAP", "00'12\"882"}},
        {0xFFFFFFFF, {0.07f, 0.11f, 0.0f, 700.0f, 150.0f, -1, "MAX SPEED", "1024"}},
        {0xFFFFFFFF, {0.065f, 0.13f, 0.0f, 700.0f, 180.0f, -1, "POINTS", "98"}},
        {0xFFFFFFFF, {0.06f, 0.16f, 0.0f, 700.0f, 210.0f, -1, "ATTACK", "NONE"}},
    },
    {
        {0x006400C8, {0.1f, 0.07f, 0.0f, 700.0f, 0.0f, -1, "MUTECITY", ""}},
        {0xFFFFFFFF, {0.09f, 0.08f, 0.0f, 700.0f, 60.0f, -1, "RANK", "1"}},
        {0xFFFFFFFF, {0.08f, 0.09f, 0.0f, 700.0f, 90.0f, -1, "TIME", "01'59\"980"}},
        {0xFFFFFFFF, {0.075f, 0.1f, 0.0f, 700.0f, 120.0f, -1, "BEST LAP", "00'12\"882"}},
        {0xFFFFFFFF, {0.07f, 0.11f, 0.0f, 700.0f, 150.0f, -1, "MAX SPEED", "1024"}},
        {0xFFFFFFFF, {0.065f, 0.13f, 0.0f, 700.0f, 180.0f, -1, "POINTS", "98"}},
        {0xFFFFFFFF, {0.06f, 0.16f, 0.0f, 700.0f, 210.0f, -1, "ATTACK", "NONE"}},
    },
    {
        {0x006400C8, {0.1f, 0.07f, 0.0f, 700.0f, 0.0f, -1, "MUTECITY", ""}},
        {0xFFFFFFFF, {0.09f, 0.08f, 0.0f, 700.0f, 60.0f, -1, "RANK", "1"}},
        {0xFFFFFFFF, {0.08f, 0.09f, 0.0f, 700.0f, 90.0f, -1, "TIME", "01'59\"980"}},
        {0xFFFFFFFF, {0.075f, 0.1f, 0.0f, 700.0f, 120.0f, -1, "BEST LAP", "00'12\"882"}},
        {0xFFFFFFFF, {0.07f, 0.11f, 0.0f, 700.0f, 150.0f, -1, "MAX SPEED", "1024"}},
        {0xFFFFFFFF, {0.065f, 0.13f, 0.0f, 700.0f, 180.0f, -1, "POINTS", "98"}},
        {0xFFFFFFFF, {0.06f, 0.16f, 0.0f, 700.0f, 210.0f, -1, "ATTACK", "NONE"}},
    },
    {
        {0x006400C8, {0.1f, 0.07f, 0.0f, 700.0f, 0.0f, -1, "MUTECITY", ""}},
        {0xFFFFFFFF, {0.09f, 0.08f, 0.0f, 700.0f, 60.0f, -1, "RANK", "1"}},
        {0xFFFFFFFF, {0.08f, 0.09f, 0.0f, 700.0f, 90.0f, -1, "TIME", "01'59\"980"}},
        {0xFFFFFFFF, {0.075f, 0.1f, 0.0f, 700.0f, 120.0f, -1, "BEST LAP", "00'12\"882"}},
        {0xFFFFFFFF, {0.07f, 0.11f, 0.0f, 700.0f, 150.0f, -1, "MAX SPEED", "1024"}},
        {0xFFFFFFFF, {0.065f, 0.13f, 0.0f, 700.0f, 180.0f, -1, "POINTS", "98"}},
        {0xFFFFFFFF, {0.06f, 0.16f, 0.0f, 700.0f, 210.0f, -1, "ATTACK", "NONE"}},
    },
    {
        {0x006400C8, {0.1f, 0.07f, 0.0f, 700.0f, 0.0f, -1, "MUTECITY", ""}},
        {0xFFFFFFFF, {0.09f, 0.08f, 0.0f, 700.0f, 60.0f, -1, "RANK", "1"}},
        {0xFFFFFFFF, {0.08f, 0.09f, 0.0f, 700.0f, 90.0f, -1, "TIME", "01'59\"980"}},
        {0xFFFFFFFF, {0.075f, 0.1f, 0.0f, 700.0f, 120.0f, -1, "BEST LAP", "00'12\"882"}},
        {0xFFFFFFFF, {0.07f, 0.11f, 0.0f, 700.0f, 150.0f, -1, "MAX SPEED", "1024"}},
        {0xFFFFFFFF, {0.065f, 0.13f, 0.0f, 700.0f, 180.0f, -1, "POINTS", "98"}},
        {0xFFFFFFFF, {0.06f, 0.16f, 0.0f, 700.0f, 210.0f, -1, "ATTACK", "NONE"}},
    },
    {
        {0x006400C8, {0.1f, 0.07f, 0.0f, 700.0f, 0.0f, -1, "MUTECITY", ""}},
        {0xFFFFFFFF, {0.09f, 0.08f, 0.0f, 700.0f, 60.0f, -1, "RANK", "1"}},
        {0xFFFFFFFF, {0.08f, 0.09f, 0.0f, 700.0f, 90.0f, -1, "TIME", "01'59\"980"}},
        {0xFFFFFFFF, {0.075f, 0.1f, 0.0f, 700.0f, 120.0f, -1, "BEST LAP", "00'12\"882"}},
        {0xFFFFFFFF, {0.07f, 0.11f, 0.0f, 700.0f, 150.0f, -1, "MAX SPEED", "1024"}},
        {0xFFFFFFFF, {0.065f, 0.13f, 0.0f, 700.0f, 180.0f, -1, "POINTS", "98"}},
        {0xFFFFFFFF, {0.06f, 0.16f, 0.0f, 700.0f, 210.0f, -1, "ATTACK", "NONE"}},
    },
};
ResultRow lbl_15_data_132C[6][4] = {
    {
        {0x006400C8, {0.1f, 0.07f, 0.0f, 700.0f, 0.0f, -1, "RUBY CUP", ""}},
        {0xFFFFFFFF, {0.09f, 0.08f, 0.0f, 700.0f, 60.0f, -1, "TOTAL RANK", "1"}},
        {0xFFFFFFFF, {0.08f, 0.09f, 0.0f, 700.0f, 90.0f, -1, "TOTAL POINTS", "230"}},
        {0xFFFFFFFF, {0.06f, 0.16f, 0.0f, 700.0f, 120.0f, -1, "TOTAL ATTACK", "NONE"}},
    },
    {
        {0x006400C8, {0.1f, 0.07f, 0.0f, 700.0f, 0.0f, -1, "RUBY CUP", ""}},
        {0xFFFFFFFF, {0.09f, 0.08f, 0.0f, 700.0f, 60.0f, -1, "TOTAL RANK", "1"}},
        {0xFFFFFFFF, {0.08f, 0.09f, 0.0f, 700.0f, 90.0f, -1, "TOTAL POINTS", "230"}},
        {0xFFFFFFFF, {0.06f, 0.16f, 0.0f, 700.0f, 120.0f, -1, "TOTAL ATTACK", "NONE"}},
    },
    {
        {0x006400C8, {0.1f, 0.07f, 0.0f, 700.0f, 0.0f, -1, "RUBY CUP", ""}},
        {0xFFFFFFFF, {0.09f, 0.08f, 0.0f, 700.0f, 60.0f, -1, "TOTAL RANK", "1"}},
        {0xFFFFFFFF, {0.08f, 0.09f, 0.0f, 700.0f, 90.0f, -1, "TOTAL POINTS", "230"}},
        {0xFFFFFFFF, {0.06f, 0.16f, 0.0f, 700.0f, 120.0f, -1, "TOTAL ATTACK", "NONE"}},
    },
    {
        {0x006400C8, {0.1f, 0.07f, 0.0f, 700.0f, 0.0f, -1, "RUBY CUP", ""}},
        {0xFFFFFFFF, {0.09f, 0.08f, 0.0f, 700.0f, 60.0f, -1, "TOTAL RANK", "1"}},
        {0xFFFFFFFF, {0.08f, 0.09f, 0.0f, 700.0f, 90.0f, -1, "TOTAL POINTS", "230"}},
        {0xFFFFFFFF, {0.06f, 0.16f, 0.0f, 700.0f, 120.0f, -1, "TOTAL ATTACK", "NONE"}},
    },
    {
        {0x006400C8, {0.1f, 0.07f, 0.0f, 700.0f, 0.0f, -1, "RUBY CUP", ""}},
        {0xFFFFFFFF, {0.09f, 0.08f, 0.0f, 700.0f, 60.0f, -1, "TOTAL RANK", "1"}},
        {0xFFFFFFFF, {0.08f, 0.09f, 0.0f, 700.0f, 90.0f, -1, "TOTAL POINTS", "230"}},
        {0xFFFFFFFF, {0.06f, 0.16f, 0.0f, 700.0f, 120.0f, -1, "TOTAL ATTACK", "NONE"}},
    },
    {
        {0x006400C8, {0.1f, 0.07f, 0.0f, 700.0f, 0.0f, -1, "RUBY CUP", ""}},
        {0xFFFFFFFF, {0.09f, 0.08f, 0.0f, 700.0f, 60.0f, -1, "TOTAL RANK", "1"}},
        {0xFFFFFFFF, {0.08f, 0.09f, 0.0f, 700.0f, 90.0f, -1, "TOTAL POINTS", "230"}},
        {0xFFFFFFFF, {0.06f, 0.16f, 0.0f, 700.0f, 120.0f, -1, "TOTAL ATTACK", "NONE"}},
    },
};
char *lbl_15_data_1C80[6][6] = {
    {"ALL CUP", "RUBY CUP", "SAPPHIRE CUP", "EMERALD CUP", "DIAMOND CUP", "AX CUP"},
    {"GER", "GER", "GER", "GER", "GER", NULL},
    {"FRA", "FRA", "FRA", "FRA", "FRA", NULL},
    {"SPA", "SPA", "SPA", "SPA", "SPA", NULL},
    {"ITA", "ITA", "ITA", "ITA", "ITA", NULL},
    {"ALL CUP", "RUBY CUP", "SAPPHIRE CUP", "EMERALD CUP", "DIAMOND CUP", "AX CUP"},
};
char *lbl_15_data_1D50[6][4] = {
    {"NOVICE CLASS", "STANDARD CLASS", "EXPERT CLASS", "MASTER CLASS"},
    {"GER", "GER", "GER", "GER"},
    {"FRA", "FRA", "FRA", "FRA"},
    {"SPA", "SPA", "SPA", "SPA"},
    {"ITA", "ITA", "ITA", "ITA"},
    {"NOVICE CLASS", "STANDARD CLASS", "EXPERT CLASS", "MASTER CLASS"},
};
char *lbl_15_data_1DB4[6] = {"PTS", "PTS", "PTS", "PTS", "PTS", "PTS"};
char *lbl_15_data_1DD4[6] = {"KM/H", "KM/H", "KM/H", "KM/H", "KM/H", "KM/H"};
s16 lbl_15_data_1DEC[6] = {700, 1100, 1500, 1900, 2300, 2700};
char *lbl_15_data_1E6C[6] = {"CONGRATULATIONS!!", "CONGRATULATIONS!!(GER)", "CONGRATULATIONS!!(FRA)", "CONGRATULATIONS!!(SPA)", "CONGRATULATIONS!!(ITA)", "CONGRATULATIONS!!"};
char *lbl_15_data_1ECC[6] = {"YOU GOT", "YOU GOT(GER)", "YOU GOT(FRA)", "YOU GOT(SPA)", "YOU GOT(ITA)", "YOU GOT"};
/* WARNING: compiler-diff device, not original code (carried from main: opt_lifetimes off, struct carriers) */
/* Keep phase-local coordinate homes; the scan, easing and clamp inputs are separate locals. */
#pragma opt_lifetimes off
void fn_15_4578(void) {
    s32 count;
    u8 snapshot[0x14B8];
    FontDrawPacket packet;
    FontDrawPacket course_packet;
    s32 i;
    s32 timeline_i;
    s32 fade_start;
    WinResult *course; /* Declaration order sets allocation priority: after count/fade_start, before result/image/anim. */
    WinResult *result;
    s32 image;
    s32 icon; /* Valid course IDs map to switch cases; retail has no default store. */
    s16 racer;
    struct { s32 value; } frame;
    char *suffix;
    s32 rank;
    struct { s16 value; } start;
    s16 end;
    struct ResultRow *row;
    struct ResultAnimation *anim;
    f32 width;
    f32 t;
    f32 ease;
    f32 banner_t;
    f32 backdrop_t;
    f32 x;
    struct { f32 value; } y;
    f32 height;
    f32 alpha;
    f32 height_2;
    u32 time;
    f32 offset_2;

    if (!(lbl_15_bss_14 & 0x78)) return;
    if (lbl_15_bss_14 & 0x20000000) {
        racer = 1;
    } else {
        fn_1_3EF14(snapshot);
        racer = snapshot[0xA6];
    }
    if (lbl_15_bss_18 >= 300 && lbl_15_bss_18 < 600) {
        if (lbl_15_bss_18 > 540.0f) {
            banner_t = 1.0f - (lbl_15_bss_18 - 540.0f) / 60.0f;
            alpha = winning_clamp(banner_t, 0.0f, 1.0f);
        } else {
            banner_t = (lbl_15_bss_18 - 300) / 60.0f;
            alpha = winning_clamp(banner_t, 0.0f, 1.0f);
        }
        switch (racer) {
        case 1: image = 0xA102; break;
        case 2: image = 0xA103; break;
        case 3: image = 0xA104; break;
        case 4: image = 0xA105; break;
        default: image = 0xA106; break;
        }
        fn_1_520A0();
        fn_1_52070(320);
        packet = lbl_1_rodata_26F8;
        packet.image = image;
        packet.x = 320.0f;
        packet.y = 234.0f;
        packet.z = 11.0f;
        packet.flags = 10;
        packet.alpha = alpha;
        fn_1_4F734(&packet);
        fn_1_141360(racer, packet.x, packet.y, 10, 1.0f, alpha);
        fn_1_520CC();
        fn_1_49410();
        fn_1_494DC(6);
        fn_1_495B0(0xC0000000U); 
        fn_1_495C8(1);
        fn_1_49590(0.5f);
        fn_1_4955C(1.5f, 1.5f);
        fn_1_496FC(320.0f, 142.0f);
        fn_1_495A0(alpha);
        fn_1_4A0D8("F-ZERO GRAND PRIX\n");
        fn_1_496FC(320.0f, 296.0f);
        fn_1_4955C(1.5f, 1.5f);
        fn_1_4AE0C("%s\n", lbl_15_data_1C80[lbl_801A66B4][racer]);
        fn_1_496FC(320.0f, 324.0f);
        fn_1_4955C(0.8f, 0.8f);
        fn_1_4AE0C("%s", lbl_15_data_1D50[lbl_801A66B4][lbl_15_bss_3C]);
        packet = lbl_1_rodata_26F8;
        packet.x = 320.0f;
        packet.y = 240.0f;
        packet.z = 20.0f;
        packet.flags = 10;
        packet.image = 2;
        packet.alpha = alpha;
        fn_1_50A90(&packet, 18, 45, 940, 234);
    }
    fn_1_49410();
    fn_1_49590(0.5f);
    frame.value = lbl_15_bss_18;
    for (timeline_i = 0; (s16)timeline_i < 6; timeline_i++) {
        if (frame.value == lbl_15_data_1DEC[timeline_i]) lbl_15_bss_154 = timeline_i;
    }
    start.value = lbl_15_data_1DEC[lbl_15_bss_154];
    if (start.value > frame.value) return;
    if (lbl_15_bss_18 >= start.value + 400) return;
    end = start.value;
    end += 400;
    count = 7;
    fade_start = (end - 60.0f);
    if (lbl_15_bss_154 == 5) count = 4;
    if (frame.value == start.value) {
        if (lbl_15_bss_154 == 5) {
            memcpy(lbl_15_bss_158, lbl_15_data_132C[lbl_801A66B4], (s16)count * sizeof(ResultRow));
            sprintf(lbl_15_bss_158[0].anim.label, "%s", lbl_15_data_1C80[lbl_801A66B4][racer]);
            if (!(lbl_15_bss_14 & 0x20000000)) {
                result = &lbl_15_bss_2C->result;
                sprintf(lbl_15_bss_158[1].anim.value, "%d", result->rank + 1);
                sprintf(lbl_15_bss_158[2].anim.value, "%d", result->unk_4);
                sprintf(lbl_15_bss_158[3].anim.value, "%d", result->unk_6);
            }
        } else {
            memcpy(lbl_15_bss_158, lbl_15_data_36C[lbl_801A66B4], (s16)count * sizeof(ResultRow));
            sprintf(lbl_15_bss_158[0].anim.label, "%s", lbl_1_data_2BD54[fn_1_12EF24(racer,lbl_15_bss_154)][lbl_801A66B4]);
            if (!(lbl_15_bss_14 & 0x20000000)) {
                course = &lbl_15_bss_2C->result;
                sprintf(lbl_15_bss_158[1].anim.value, "%d", course->unk_E[lbl_15_bss_154] + 1);
                time = course->unk_24[lbl_15_bss_154];
                sprintf(lbl_15_bss_158[2].anim.value, "%02d'%02d\"%03d", (time>>20)&255, (time>>12)&255, time&0xFFF);
                time = course->unk_38[lbl_15_bss_154];
                sprintf(lbl_15_bss_158[3].anim.value, "%02d'%02d\"%03d", (time>>20)&255, (time>>12)&255, time&0xFFF);
                sprintf(lbl_15_bss_158[4].anim.value, "%d", course->unk_18[lbl_15_bss_154]);
                sprintf(lbl_15_bss_158[5].anim.value, "%d", course->unk_9[lbl_15_bss_154]);
                sprintf(lbl_15_bss_158[6].anim.value, "%d", course->unk_13[lbl_15_bss_154]);
            }
        }
    }
    row = lbl_15_bss_158;
    width = 940.0f;
    for (i = 0; (s16)i < (s16)count; row++, i++) {
        anim = &row->anim;
        if (lbl_15_bss_18 < (s16)fade_start) {
            ease = anim->ease;
            if ((s16)i == 0 || lbl_15_bss_154 == 5) {
                anim->x += (320.0f - anim->x) * ease;
            } else {
                anim->x += (296.0f - anim->x) * ease;
            }
        } else {
            anim->velocity += 10.0f * anim->acceleration;
            anim->x -= anim->velocity;
        }
        if ((s16)i == 0) {
            x = 103.0f + anim->y;
            y.value = anim->y;
            height = anim->x;
            if (lbl_15_bss_154 == 5) {
                fn_1_49410();
                fn_1_494DC(6);
                fn_1_495B0(0xC0000000U); 
                fn_1_495C8(9);
                fn_1_49590(0.5f);
                fn_1_4955C(1.44f, 1.44f);
                fn_1_496FC(height, 160.0f + y.value);
                fn_1_495A0(1.0f);
                fn_1_4A0D8("F-ZERO GRAND PRIX\n");
                fn_1_4AE0C("%s", lbl_15_data_1C80[lbl_801A66B4][racer]);
                offset_2 = anim->x;
                x = 211.0f + anim->y;
                fn_1_4955C(0.84f, 0.84f);
                fn_1_496FC(offset_2,x);
                fn_1_4AE0C("%s", lbl_15_data_1D50[lbl_801A66B4][lbl_15_bss_3C]);
            } else {
                switch (lbl_1_data_2B0D4[fn_1_12EF24(racer,lbl_15_bss_154)]) {
                case 1: case 17: case 18: icon = 0; break;
                case 2: case 3: icon = 1; break;
                case 4: case 5: icon = 2; break;
                case 6: case 7: icon = 3; break;
                case 8: case 9: icon = 4; break;
                case 10: icon = 5; break;
                case 11: case 12: icon = 6; break;
                case 13: icon = 7; break;
                case 14: icon = 8; break;
                case 15: icon = 9; break;
                case 16: icon = 10; break;
                case 19: icon = 11; break;
                }
                course_packet = lbl_1_rodata_26F8;
                course_packet.image = 0xBB00;
                fn_1_51678(&course_packet, course_packet.image, 0, icon * 36, fn_1_48690(0xBB00), 36);
                course_packet.x = height;
                course_packet.y = x;
                course_packet.flags = 6;
                fn_1_4F734(&course_packet);
                fn_1_CFCA4(anim->label, anim->x, 141.0f + anim->y, 1.0f);
            }
        } else {
            x = anim->x;
            if (lbl_15_bss_154 == 5) {
                y.value = 180.0f + anim->y;
                offset_2 = 0.0f;
                x = 27.0f + x;
                height_2 = 224.0f;
            } else {
                y.value = 117.0f + anim->y;
                height_2 = 200.0f;
                offset_2 = 23.0f;
            }
            fn_1_49410();
            fn_1_495B0(0xC0000000U); 
            fn_1_494DC(6);
            fn_1_4955C(1.3f,1.3f);
            y.value = 23.0f + y.value;
            fn_1_496FC(x,y.value);
            fn_1_495C8(18);
            fn_1_49514(&(GXColor){0x00, 0xFF, 0xFF, 0xFF});
            fn_1_4AE0C("%s", anim->label);
            fn_1_49590(0.5f);
            fn_1_496FC(x,y.value);
            fn_1_495C8(16);
            fn_1_49514(&(GXColor){0xFF, 0xFF, 0xFF, 0xFF});
            fn_1_4AE0C(" : %s", anim->value);
            if ((s16)i == 1) {
                result = &lbl_15_bss_2C->result;
                fn_1_4962C();
                fn_1_4955C(1.04f, 1.04f);
                if (lbl_15_bss_154 == 5) {
                    rank = result->rank + 1;
                    if (lbl_801A66B4 == 5) suffix = fn_1_5415C(rank, 0);
                    else suffix = fn_1_5415C(rank, lbl_801A66B4);
                    fn_1_4AE0C(" %s", suffix);
                } else {
                    rank = result->unk_E[lbl_15_bss_154] + 1;
                    if (lbl_801A66B4 == 5) suffix = fn_1_5415C(rank, 0);
                    else suffix = fn_1_5415C(rank, lbl_801A66B4);
                    fn_1_4AE0C(" %s", suffix);
                }
            }
            if ((s16)i == 2 && lbl_15_bss_154 == 5) {
                fn_1_4955C(1.04f, 1.04f);
                fn_1_4AE0C(" %s", lbl_15_data_1DB4[lbl_801A66B4]);
            }
            if ((s16)i == 4) {
                fn_1_4955C(1.04f, 1.04f);
                fn_1_4AE0C(" %s", lbl_15_data_1DD4[lbl_801A66B4]);
            }
            if ((s16)i == 5) {
                fn_1_4955C(1.04f, 1.04f);
                fn_1_4AE0C(" %s", lbl_15_data_1DB4[lbl_801A66B4]);
            }
            if ((s16)i == 1) {
                packet = lbl_1_rodata_26F8;
                packet.x = 320.0f;
                packet.y = 240.0f + offset_2;
                packet.z = 20.0f;
                packet.flags = 10;
                packet.image = 2;
                alpha = __fabs(lbl_15_bss_158[0].anim.x - 320.0f) / 320.0;
                backdrop_t = 1.0f - alpha;
                alpha = winning_clamp(backdrop_t,0.0f,1.0f);
                packet.alpha = alpha;
                fn_1_50A90(&packet,18,45,width,(height_2*alpha));
            }
            if (lbl_15_bss_154 == 5 && (s16)i == 1) {
                switch (racer) {
                case 1: image = 0xA102; break;
                case 2: image = 0xA103; break;
                case 3: image = 0xA104; break;
                case 4: image = 0xA105; break;
                default: image = 0xA106; break;
                }
                fn_1_520A0();
                fn_1_52070(320);
                packet = lbl_1_rodata_26F8;
                packet.image = image;
                packet.x = 320.0f;
                packet.y = 250.0f;
                packet.z = 11.0f;
                packet.scale_x = 1.56f * alpha;
                packet.scale_y = 1.56f * alpha;
                alpha = 0.4f * alpha;
                packet.alpha = alpha;
                packet.flags = 10;
                fn_1_4F734(&packet);
                fn_1_141360(racer, packet.x, packet.y, 10, 1.56f, alpha);
                fn_1_520CC();
            }
        }
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_15_4578 */

/* fzgx:begin fn_15_537C */
void fn_15_537C(void) {
    static const GXColor color = {0xFF, 0xFF, 0xFF, 0xFF};

    fn_1_7BCCC(&lbl_15_bss_88);
    fn_80035680(&lbl_15_bss_3F8, lbl_15_bss_88.x, lbl_15_bss_88.y, lbl_15_bss_88.z);
    fn_80035690(&lbl_15_bss_3F8, lbl_15_bss_88.x, lbl_15_bss_88.y, lbl_15_bss_88.z);
    fn_80035420(&lbl_15_bss_3F8, 0.0f, 0);
    fn_800356AC(&lbl_15_bss_3F8, color);
    GXInitLightDistAttn(&lbl_15_bss_3F8, 0.0f, 0.0f, 0);
    fn_1_7BB80(&lbl_15_bss_3F8, 1);
    fn_1_7BD6C(1);
}
/* fzgx:end fn_15_537C */

/* fzgx:begin fn_15_545C */
// fn_15_545C: empty in retail (single blr).
void fn_15_545C(void) {
}
/* fzgx:end fn_15_545C */

/* fzgx:begin fn_15_5460 */
/* retail .rodata 0x1A0: no code reads these */
const Vec3 lbl_15_rodata_1A0[2] = {
    {0.0f, 1.7f, 0.0f},
    {0.0f, 1.2f, 0.0f},
};
const f32 lbl_15_rodata_1B8 = 6.0f;

void fn_15_5460(f32 alpha) {
    FontDrawPacket packet;
    f32 offset;

    if (lbl_15_bss_35) {
        offset = -22.0f;
    } else {
        offset = 0.0f;
    }
    fn_1_520A0();
    fn_1_52070(320);
    packet = lbl_1_rodata_26F8;
    packet.image = 0xA105;
    packet.x = 320.0f;
    packet.y = 238.0f + offset;
    packet.z = 3.0f;
    packet.scale_x = 1.0f;
    packet.scale_y = 1.0f;
    packet.alpha = alpha;
    packet.flags = 10;
    fn_1_4F734(&packet);
    fn_1_141360(4, packet.x, packet.y, 2, 1.0f, alpha);
    fn_1_520CC();
    fn_1_49410();
    fn_1_494DC(6);
    fn_1_495B0(0xC0000000U);
    fn_1_495C8(1);
    fn_1_49590(0.5f);
    fn_1_4955C(1.4f, 1.4f);
    fn_1_496FC(320.0f, 146.0f + offset);
    fn_1_495A0(alpha);
    fn_1_4AE0C("%s", lbl_15_data_1E6C[lbl_801A66B4]);
    offset = 303.0f + offset;
    fn_1_496FC(320.0f, offset);
    fn_1_4955C(1.2f, 1.2f);
    fn_1_4AE0C("%s", lbl_15_data_1ECC[lbl_801A66B4]);
    fn_1_496FC(320.0f, offset);
    fn_1_4955C(1.2f, 1.2f);
    if (lbl_15_bss_35) {
        fn_1_496FC(320.0f, 308.0f);
        fn_1_4955C(1.5f, 1.5f);
        fn_1_4AE0C("%s!!\n", lbl_15_data_1C80[lbl_801A66B4][4]);
        fn_1_496FC(320.0f, 340.0f);
        fn_1_4955C(1.5f, 1.5f);
        fn_1_4AE0C("%s!!", lbl_15_data_1D50[lbl_801A66B4][3]);
    } else {
        fn_1_496FC(320.0f, 330.0f);
        fn_1_4955C(1.5f, 1.5f);
        fn_1_4AE0C("%s!!\n", lbl_15_data_1C80[lbl_801A66B4][4]);
    }
}
/* fzgx:end fn_15_5460 */

/* fzgx:begin fn_15_5730 */
void fn_15_5730(f32 alpha) {
    fn_1_49410();
    fn_1_494DC(6);
    fn_1_495B0(0xC0000000U);
    fn_1_495C8(1);
    fn_1_49590(0.5f);
    fn_1_4955C(1.4f, 1.4f);
    fn_1_496FC(320.0f, 185.0f);
    fn_1_495A0(alpha);
    fn_1_4AE0C("%s", lbl_15_data_1E6C[lbl_801A66B4]);
    fn_1_496FC(320.0f, 242.0f);
    fn_1_4955C(1.2f, 1.2f);
    fn_1_4AE0C("%s", lbl_15_data_1ECC[lbl_801A66B4]);
    fn_1_496FC(320.0f, 270.0f);
    fn_1_4955C(1.5f, 1.5f);
    fn_1_4AE0C("%s!!", lbl_15_data_1D50[lbl_801A66B4][3]);
}
/* fzgx:end fn_15_5730 */

/* fzgx:begin fn_15_5864 */
s32 fn_15_5864(void) {
    return (lbl_1_bss_960 == 14) ? lbl_15_bss_4 : 0;
}
/* fzgx:end fn_15_5864 */
