#include "types.h"
#include "font.h"

/* pilotpoint.c: the pilot point screen after a race (fze.pilotpoint.rel, one translation unit) */

/* one scene of the pilot point screen: name and its init, main and exit functions */
typedef struct PPScene {
    char *name;
    void (*init)(void);
    void (*main)(void);
    void (*exit)(void);
} PPScene;

typedef struct Obj_1_bss_8B3A0 {
    s16 unk_0;
    u8 pad_2[0x8E];
    s16 unk_90;
    u8 pad_92[0x2];
    u32 unk_94;
    u8 pad_98[0x4];
    s16 unk_9C;
    u8 unk_9E;
    u8 pad_9F[0x85];
    u32 unk_124;
} Obj_1_bss_8B3A0;

extern struct {
    u32 unk_0;
} lbl_801A6410;
extern s32 lbl_801A66B4;
extern u32 lbl_801A66A0;

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
extern PadInput lbl_1_bss_9F8[4];

#include "game/pad.h"
extern f64 __fabs(f64);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern f32 lbl_8006D188(s16);
extern s16 fn_1_12C710(u32);
extern void fn_1_9250C(void *);

/* sprite tint, copied as one word into a packet's color */
typedef struct PPColor {
    u8 r, g, b, a;
} PPColor;

typedef struct PPVec {
    f32 x;
    f32 y;
    f32 z;
} PPVec;

/* the light state the camera setup copies and scales */
typedef struct PPLight {
    u32 unk_0[3];
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u32 unk_18[7];
} PPLight;
extern PPLight lbl_1_data_1E5C0;

/* camera eye and target */
typedef struct PPCamera {
    u32 unk_0;
    PPVec unk_4;
    PPVec unk_10;
    u8 pad_1C[8];
} PPCamera;

extern void fn_8006F038(PPVec *, PPVec *, s16);
extern void lbl_8006DCDC(void);
extern void lbl_8006DCA4(void);
extern void fn_1_F7870(PPLight *);
extern void fn_1_151BDC(void *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void fn_1_14DE80(void *, void *, void *, s16, f32);
extern void fn_1_14E054(void *, void *, s16, f32);
extern void fn_1_14E198(void *, void *, s16, f32);
extern void fn_1_A514C(s32);
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern void *lbl_1_bss_7167C[];
extern void *lbl_1_bss_71680;
extern void *lbl_1_bss_71684[];
extern void *lbl_1_bss_71688;
extern void *lbl_1_bss_7168C;
extern struct Sig_ADXT_Stop_ADXTHandle **lbl_1_bss_6EAD0;
extern const FontDrawPacket lbl_1_rodata_26F8;

extern u32 fn_1_7BA08(u32, u32, u32);
extern s32 fn_1_45D0(u32, u32, const char *, s32);
extern void fn_1_46B4(u32, s32, const char *, int);
extern void fn_1_7BA48(u32);
extern void fn_1_3CF0(u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_3CC4(u32);
extern void fn_1_41A8(void);
extern s32 fn_1_3F8C(const char *, void (*)(void *), void *, u32);
extern void fn_1_7BAF8(void *);
extern void fn_1_411A4(u32);
extern void fn_1_412A0(u32);
extern void fn_1_48418(int);
extern void fn_1_484CC(int);
extern void fn_1_479F0(s16);
extern void fn_1_47A60(s16);
extern void fn_1_159440(int, int);
extern void fn_1_1596DC(int);
extern void fn_8006CE1C(f32);
extern void fn_1_A8F78(void);
extern u32 fn_1_A0680(void);
extern void fn_1_A0AA4(void);
extern u32 fn_1_A1588(struct Sig_ADXT_Stop_ADXTHandle *, u32);
extern void fn_1_3EF14(void *);
extern u32 fn_1_12F1E8(u32);
extern u32 fn_1_A2D84(u32);
extern void fn_1_133DBC(void *);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13DC54(void);
extern u32 fn_1_13B328(u32, u32);
extern void fn_1_138120(void *);
extern void fn_1_50164(FontDrawPacket *, f32, f32, f32, f32);
typedef struct fn_14_1090_Color { u8 r, g, b, a; } fn_14_1090_Color;
typedef struct fn_14_1090_Pad { u16 unk_0; u16 unk_2; u8 pad_4[4]; u16 unk_8; } fn_14_1090_Pad;
typedef struct fn_14_1090_Result {
    u32 unk_0;
    u32 unk_4;
} fn_14_1090_Result;
extern fn_14_1090_Pad lbl_1_bss_D58;
extern u32 lbl_1_bss_6EAB4;
extern s32 lbl_1_bss_7180C;
extern void fn_1_49410(void);
extern void fn_1_49514(fn_14_1090_Color *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_4965C(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4CF3C(const char *, f32, ...);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_4FD64(void);
extern s32 fn_1_B7F58(fn_14_1090_Result *);

extern s32 fn_1_155F8C(void);
extern s32 fn_1_F1B94(void);
extern s32 fn_1_F1B84(void);
extern int sprintf(char *, const char *, ...);

extern u8 fn_14_DC2C(void);
extern void fn_14_DC28(void);

/* one reward entry of .data 0x2AB4: a part id and its flags */
typedef struct fn_14_2590_Entry {
    s16 unk_0;
    u32 unk_4;
} fn_14_2590_Entry;

/* the rewards of this visit (.bss 0x110) */
typedef struct fn_14_2590_Obj110 {
    u32 unk_0;
    s16 unk_4;
    s16 unk_6;
    fn_14_2590_Entry unk_8[8];
    u32 unk_48;
    u32 unk_4C;
} fn_14_2590_Obj110;

typedef struct fn_14_2590_Part {
    u8 unk_0;
    u32 unk_4[1];
} fn_14_2590_Part;

/* a garage record (0x81C0 bytes) */
typedef struct fn_14_2590_Record {
    u32 unk_0;
    u8 pad_4[0x81A0];
    fn_14_2590_Part unk_81A4[3];
    u8 pad_81BC[0x4];
} fn_14_2590_Record;

/* one machine part record (0xA20 bytes) */
typedef struct PPPart {
    s16 id;
    u8 pad_2[0x35E];
} PPPart;

struct PilotPoint {
    PPPart part[3];
};

typedef struct fn_14_2C80_Data {
    u8 pad_0[0x24];
    void *unk_24;
} fn_14_2C80_Data;

typedef struct fn_14_2C80_Elem {
    u8 pad_0[0x88];
    u32 unk_88;
    u8 pad_8C[0x1C];
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    u8 pad_B4[0x94];
    u8 unk_148[0x8];
    fn_14_2C80_Data *unk_150;
    u8 pad_154[0x38C];
} fn_14_2C80_Elem;

typedef struct fn_14_2C80_Rec {
    fn_14_2C80_Elem unk_0[3];
} fn_14_2C80_Rec;

/* the 0x10-byte records fn_1_14D8DC reads */
typedef struct fn_14_2C80_Slot {
    s16 unk_0[3];
    u32 unk_8;
    u8 pad_C[0x4];
} fn_14_2C80_Slot;

/* Lap-rank sprite of one score category: name table, position and scale. */
typedef struct fn_14_1090_Sprite {
    char **names;
    s32 x;
    s32 y;
    f32 scale_x;
    f32 scale_y;
} fn_14_1090_Sprite;

/* One score category: current points, previous points and per-step increment. */
/* One score category: points counted so far, points still to count and the per-frame step,
 * plus where its number is printed. */
typedef struct fn_14_1090_Score {
    s32 cur;
    s32 prev;
    s32 step;
    s32 x;
    s32 y;
    f32 scale_x;
    f32 scale_y;
} fn_14_1090_Score;

/* Display order of the score categories and how many frames each phase of a row takes. */
typedef struct fn_14_1090_Row {
    s32 index;
    s32 always;
    u8 mask;
    u8 pad_9[3];
    s32 unk_C;
    s32 sprite_frames;
    s32 count_frames;
    s32 wait_frames;
} fn_14_1090_Row;
extern u8 fn_14_DF70(void);
extern u32 lbl_801A63C0;
extern s16 fn_1_128B00(s16);
extern s16 fn_1_12C930(s16);
extern s16 fn_1_12CB04(s16);
extern s16 fn_1_12CCB0(s16, s16);
extern s16 fn_1_14F270(s16, s16, u32);
extern u16 fn_1_A5D88(void);
extern u32 fn_1_41488(void *, const char *);
extern u8 *fn_1_36AD0(void);
extern void *fn_1_4630(u32, u32, const char *, int);
extern void fn_1_12BF7C(void *, s16, u32, u32);
extern void fn_1_14D8DC(void *, void *, s16);
extern void fn_1_8F198(fn_14_2C80_Elem *, s32, u32, u32);
extern void fn_1_8F62C(void *);
extern void fn_1_933D8(fn_14_2C80_Elem *, void *, u16);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_128B60(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
extern s16 fn_1_14F19C(s16, s16, u32);
extern s16 fn_1_14D5CC(s16, u32, u32);
extern s16 fn_1_14D670(void);
extern u32 fn_1_14D6D8(s16);
extern u32 fn_1_151BE8(s16, s16);
extern void fn_1_12B4EC(s16, s16);

/* a machine's catalogue entry, filled by fn_1_14E9E4 */
typedef struct PPMachineInfo {
    s16 unk_0;
    s16 kind;
    f32 weight;
    s16 unk_8;
    u8 pad_A[0x6];
} PPMachineInfo;

/* a scissor rectangle for a sprite's vertex callback */
typedef struct PPRect {
    s16 x, y, w, h;
} PPRect;

extern void fn_1_14E9E4(int, PPMachineInfo *);
extern char *fn_1_14EA74(s16, char *, s16);
extern s16 fn_1_14F344(s16);
extern void fn_1_4962C(void);
extern void fn_1_8D3F8(void *, FontDrawPacket *, void *, s16 *);
extern u16 fn_1_A5DB0(void);
extern u32 fn_80074188(u32, u32, u32, u32);
extern char *lbl_1_data_21078[];
extern char *lbl_1_data_212A8[];
typedef struct PPDisp {
    u8 pad_0[0xB4];
} PPDisp;
extern void fn_1_13EF64(s16, s16, s32, void *, u32, fn_14_1090_Color *, s32, f32);
extern char *fn_1_13F72C(f32, s16, char *);
extern char *fn_1_14EE00(s16, char *, s16);
extern void *fn_1_14F6F8(s16, s16, s16, PPDisp *);
extern char *fn_1_14FEAC(s16, s16, s16, char *, s16);
extern void fn_1_494DC(s32);
extern void fn_1_49644(void);
extern void fn_1_4954C(f32);
extern void fn_1_1380F0(void *);
extern void fn_1_13D02C(void);
extern u32 lbl_801A66C0;
extern s32 fn_1_4C10(void);
extern s32 fn_1_12F228(void);
extern s32 lbl_1_bss_7180C;
extern u32 lbl_1_bss_6EAB4;
extern void fn_1_8F494(fn_14_2C80_Elem *);
extern s16 fn_1_12CB04(s16);
extern void fn_1_426C(s32);
extern void fn_1_14DC68(void *, s16);
extern void fn_1_12C000(void *, s16);

/* one ticket reward: kind -1 ends the list; 0 machine part, 1 character, 2-4 parts, 5 BGM, 6 tickets */
typedef struct PPReward {
    s16 kind;
    u8 id;
    u8 pad;
    u16 image;
} PPReward;

struct fn_14_8600_Obj {
    u8 pad_0[0x8];
    struct fn_14_8600_Inner *unk_8;
};
struct fn_14_8600_Inner {
    u8 pad_0[0x50];
    u32 unk_50;
};
struct fn_14_8600_Mgr {
    u8 pad_0[0x10];
    struct fn_14_8600_Obj *unk_10;
    struct fn_14_8600_Obj *unk_14;
};
extern struct fn_14_8600_Mgr lbl_1_bss_38460;
extern void fn_1_47F74(s32);
extern s32 fn_1_F8334(s16);
extern void fn_1_F83F0(s16);
extern void fn_1_F8B50(void);
extern u32 OSGetTick(void);

void fn_14_220(void);
u32 fn_14_268(void);
void fn_14_2A0(void);
void fn_14_2FC(void);
void fn_14_380(void);
void fn_14_900(void);
void fn_14_904(void);
void fn_14_1090(void);
void fn_14_258C(void);
void fn_14_7E04(void);
void fn_14_7EAC(void);
void fn_14_80B4(void);
void fn_14_B398(void);
void fn_14_B400(void);
void fn_14_B480(void);
void fn_14_8600(void);
void fn_14_8A54(void);
void fn_14_A1F4(void);
void fn_14_A244(void);
void fn_14_A2A4(void);
void fn_14_A398(void);
void fn_14_BCDC(void);
void fn_14_BCF8(void);
void fn_14_C4F4(void);
void fn_14_C4F8(void);
void fn_14_C518(void);
void fn_14_C698(void);
void fn_14_C69C(fn_14_1090_Sprite *, f32);
void fn_14_C850(fn_14_1090_Score *, f32);
void fn_14_CC70(s32);
void fn_14_D2EC(s32);
void fn_14_D600(s32);
void fn_14_D914(s32);
void fn_14_315C(u32);
void fn_14_316C(s16 *, s16 *, s16 *);
void fn_14_3230(s16 *arg0, s16 *arg1, s16 *arg2);
s16 fn_14_32DC(s16 *out);
s16 fn_14_3334(s16 *out);
s16 fn_14_3384(s16 *out);
s16 fn_14_33DC(s16 *out);

fn_14_2C80_Elem *fn_14_342C(void);
fn_14_2C80_Elem *fn_14_34A8(void);
char *fn_14_DC6C(s16, s16);
/* names of the link states, for the debug display */
char *lbl_14_data_200[45] = {
    "NON",
    "MASTER RECV",
    "MASTER SEND",
    "SLAVE SEND",
    "SLAVE RECV",
    "INIT",
    "TEST",
    "TESTEND",
    "SETUP",
    "SETUP_DONE",
    "SETUP_COUNTER",
    "SETUP_CNT_DONE",
    "UNLINK",
    "COIN",
    "ENTRY_WAIT",
    "CHALLENGER",
    "CHALLENGER_OK",
    "ENTRY",
    "ENTRY_OK",
    "SINGLECHECK",
    "SINGLECHECK_OK",
    "COURSE",
    "COURSE_OK",
    "COURSE_DATA",
    "COURSE_DATA_OK",
    "MACHINE",
    "MACHINE_OK",
    "CONFIG",
    "CONFIG_OK",
    "COUNTERADJUST",
    "LINKWAIT",
    "LINKWAITOK",
    "LINKSEL",
    "LINKDELIVERYSTART",
    "LINKDELIVERY",
    "LINKDELIVERYOK",
    "LINKSELOK",
    "COURSEVIEW",
    "COURSEVIEW_OK",
    "LINKREQ",
    "LINKSTANDBY",
    "LINKOK",
    "LINK",
    "PAUSE",
    "ERROR",
};
/* the scenes of the pilot point screen: name, init, main, exit */
PPScene lbl_14_data_308[8] = {
    {"prepare", fn_14_2FC, fn_14_380, fn_14_900},
    {"result_point", fn_14_904, fn_14_1090, fn_14_258C},
    {"garage", fn_14_7E04, fn_14_7EAC, fn_14_80B4},
    {"password", fn_14_B398, fn_14_B400, fn_14_B480},
    {"machine_get", fn_14_8600, fn_14_8A54, fn_14_A1F4},
    {"memcard", fn_14_A244, fn_14_A2A4, fn_14_A398},
    {"gameover", fn_14_BCDC, fn_14_BCF8, fn_14_C4F4},
    {"dest", fn_14_C4F8, fn_14_C518, fn_14_C698},
};
char *lbl_14_data_6C8[13][6] = {
    {"You have the required Pilot Points. Please select the parts or the pilot. ", "", "", "", "", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g\x82\xAA\x92\x99\x82\xDC\x82\xE8\x82\xDC\x82\xB5\x82\xBD\x81" "B\x8C\xF0\x8A\xB7\x82\xB5\x82\xBD\x82\xA2\x83p\x81[\x83" "c\x82\xE2\x83p\x83" "C\x83\x8D\x83" "b\x83g\x82\xF0\x91I\x91\xF0\x82\xB5\x82\xC4\x89\xBA\x82\xB3\x82\xA2\x81" "B"},
    {"You can exchange your Pilot Points for parts items. \nYou will spend your Pilot Points as you get the new parts. \nThe original parts \x81iformer pilot\x81j will be scrapped \x81ifired\x81j. \nPlease think carefully before making any decisions. ", "", "", "", "", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g\x82\xF0\x83p\x81[\x83" "c\x93\x99\x82\xC9\x8C\xF0\x8A\xB7\x82\xC5\x82\xAB\x82\xDC\x82\xB7\x81" "B\n\x8C\xF0\x8A\xB7\x82\xB7\x82\xE9\x82\xC6\x83|\x83" "C\x83\x93\x83g\x82\xCD\x8F\xC1\x94\xEF\x82\xB3\x82\xEA\x82\xDC\x82\xB7\x81" "B\n\x95\xCF\x8DX\x91O\x82\xCC\x83p\x81[\x83" "c\x81i\x83p\x83" "C\x83\x8D\x83" "b\x83g\x81j\x82\xCD\x94p\x8A\xFC\x8F\x88\x95\xAA\x81i\x89\xF0\x8C\xD9\x81j\x82\xB3\x82\xEA\x82\xDC\x82\xB7\x81" "B\n\x82\xE6\x82\xAD\x8Dl\x82\xA6\x82\xC4\x8C\x88\x92\xE8\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B"},
    {"PILOT POINTS", "", "", "", "", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g"},
    {"BODY PARTS", "", "", "", "", "\x83{\x83" "f\x83" "B\x83p\x81[\x83" "c"},
    {"COCKPIT PARTS", "", "", "", "", "\x83R\x83" "b\x83N\x83s\x83" "b\x83g\x83p\x81[\x83" "c"},
    {"BOOST PARTS", "", "", "", "", "\x83u\x81[\x83X\x83g\x83p\x81[\x83" "c"},
    {"BODY", "", "", "", "", "\x83{\x83" "f\x83" "B"},
    {"COCKPIT", "", "", "", "", "\x83R\x83" "b\x83N\x83s\x83" "b\x83g"},
    {"BOOST", "", "", "", "", "\x83u\x81[\x83X\x83g"},
    {"GRIP", "", "", "", "", "\x83O\x83\x8A\x83" "b\x83v"},
    {"PILOT", "", "", "", "", "\x83p\x83" "C\x83\x8D\x83" "b\x83g"},
    {"Weight", "", "", "", "", "\x83" "E\x83G\x83" "C\x83g"},
    {"EXIT", "", "", "", "", "\x83" "C\x83O\x83W\x83" "b\x83g"},
};
char *lbl_14_data_808[6] = {"PLACE", "PLACE", "PLACE", "PLACE", "PLACE", "PLACE"};
char *lbl_14_data_828[6] = {"DESTROY", "DESTROY", "DESTROY", "DESTROY", "DESTROY", "DESTROY"};
char *lbl_14_data_84C[6] = {"TOTAL TIME", "TOTAL TIME", "TOTAL TIME", "TOTAL TIME", "TOTAL TIME", "TOTAL TIME"};
char *lbl_14_data_86C[6] = {"RANK IN", "RANK IN", "RANK IN", "RANK IN", "RANK IN", "RANK IN"};
char *lbl_14_data_894[6] = {"SAFE DRIVING", "SAFE DRIVING", "SAFE DRIVING", "SAFE DRIVING", "SAFE DRIVING", "SAFE DRIVING"};
char *lbl_14_data_8B4[6] = {"BOOSTER", "BOOSTER", "BOOSTER", "BOOSTER", "BOOSTER", "BOOSTER"};
char *lbl_14_data_8D8[6] = {"MAX SPEED", "MAX SPEED", "MAX SPEED", "MAX SPEED", "MAX SPEED", "MAX SPEED"};
char *lbl_14_data_8FC[6] = {"CHAMPION", "CHAMPION", "CHAMPION", "CHAMPION", "CHAMPION", "CHAMPION"};
char *lbl_14_data_920[6] = {"TARGET TIME", "TARGET TIME", "TARGET TIME", "TARGET TIME", "TARGET TIME", "TARGET TIME"};
char *lbl_14_data_944[6] = {"STAFF GHOST", "STAFF GHOST", "STAFF GHOST", "STAFF GHOST", "STAFF GHOST", "STAFF GHOST"};
char *lbl_14_data_964[6] = {"SPECIAL", "SPECIAL", "SPECIAL", "SPECIAL", "SPECIAL", "SPECIAL"};
char *lbl_14_data_984[6] = {"TOTAL", "TOTAL", "TOTAL", "TOTAL", "TOTAL", "TOTAL"};
char *lbl_14_data_9B4[6] = {"CURRENT PILOT POINTS", "CURRENT PILOT POINTS", "CURRENT PILOT POINTS", "CURRENT PILOT POINTS", "CURRENT PILOT POINTS", "CURRENT PILOT POINTS"};
char *lbl_14_data_A28[6] = {"          more\npoints to get\nthe parts.", "UNTIL GET PARTS", "UNTIL GET PARTS", "UNTIL GET PARTS", "UNTIL GET PARTS", "\x83p\x81[\x83" "c\x83Q\x83" "b\x83g\x82\xDC\x82\xC5\n            pts"};
char *lbl_14_data_A7C[6] = {"Parts can be\n       gained", "UNTIL GET PARTS", "UNTIL GET PARTS", "UNTIL GET PARTS", "UNTIL GET PARTS", "\x83p\x81[\x83" "c\x82\xF0\x83Q\x83" "b\x83g\n        \x82\xC5\x82\xAB\x82\xDC\x82\xB7"};
char *lbl_14_data_A9C[6] = {"NAME", "NAME", "NAME", "NAME", "NAME", "NAME"};
char *lbl_14_data_AC0[6] = {"PILOT RANK", "PILOT RANK", "PILOT RANK", "PILOT RANK", "PILOT RANK", "PILOT RANK"};
char *lbl_14_data_AE0[6] = {"Great!", "Great!", "Great!", "Great!", "Great!", "Great!"};
char *lbl_14_data_B4C[6] = {"Pilot Rank upgraded!", "PILOT RANK\x82\xAA\x8F\xE3\x82\xAA\x82\xE8\x82\xDC\x82\xB5\x82\xBD", "PILOT RANK\x82\xAA\x8F\xE3\x82\xAA\x82\xE8\x82\xDC\x82\xB5\x82\xBD", "PILOT RANK\x82\xAA\x8F\xE3\x82\xAA\x82\xE8\x82\xDC\x82\xB5\x82\xBD", "PILOT RANK\x82\xAA\x8F\xE3\x82\xAA\x82\xE8\x82\xDC\x82\xB5\x82\xBD", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83\x89\x83\x93\x83N\x82\xAA\x8F\xE3\x82\xAA\x82\xE8\x82\xDC\x82\xB5\x82\xBD"};
char *lbl_14_data_B74[6] = {"Congratulation!", "Congratulation!", "Congratulation!", "Congratulation!", "Congratulation!", "Congratulation!"};
char *lbl_14_data_BD4[6] = {"You have the required\nPilot Points!", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g\x82\xAA\n\x92\x99\x82\xDC\x82\xE8\x82\xDC\x82\xB5\x82\xBD", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g\x82\xAA\n\x92\x99\x82\xDC\x82\xE8\x82\xDC\x82\xB5\x82\xBD", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g\x82\xAA\n\x92\x99\x82\xDC\x82\xE8\x82\xDC\x82\xB5\x82\xBD", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g\x82\xAA\n\x92\x99\x82\xDC\x82\xE8\x82\xDC\x82\xB5\x82\xBD", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g\x82\xAA\n\x92\x99\x82\xDC\x82\xE8\x82\xDC\x82\xB5\x82\xBD"};
char *lbl_14_data_BF8[6] = {"Wonderful!", "Wonderful!", "Wonderful!", "Wonderful!", "Wonderful!", "Wonderful!"};
char *lbl_14_data_C54[6] = {"Promoted to Pilot Title!", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83\x89\x83\x93\x83N\x82\xAA\x8F\xCC\x8D\x86\x82\xC9\n\x95\xCF\x82\xED\x82\xE8\x82\xDC\x82\xB5\x82\xBD", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83\x89\x83\x93\x83N\x82\xAA\x8F\xCC\x8D\x86\x82\xC9\n\x95\xCF\x82\xED\x82\xE8\x82\xDC\x82\xB5\x82\xBD", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83\x89\x83\x93\x83N\x82\xAA\x8F\xCC\x8D\x86\x82\xC9\n\x95\xCF\x82\xED\x82\xE8\x82\xDC\x82\xB5\x82\xBD", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83\x89\x83\x93\x83N\x82\xAA\x8F\xCC\x8D\x86\x82\xC9\n\x95\xCF\x82\xED\x82\xE8\x82\xDC\x82\xB5\x82\xBD", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83\x89\x83\x93\x83N\x82\xAA\x8F\xCC\x8D\x86\x82\xC9\n\x95\xCF\x82\xED\x82\xE8\x82\xDC\x82\xB5\x82\xBD"};
char *lbl_14_data_C9C[6] = {"Pilot Title upgraded!", "\x90V\x82\xBD\x82\xC8\x8F\xCC\x8D\x86\x82\xF0\x93\xBE\x82\xDC\x82\xB5\x82\xBD", "\x90V\x82\xBD\x82\xC8\x8F\xCC\x8D\x86\x82\xF0\x93\xBE\x82\xDC\x82\xB5\x82\xBD", "\x90V\x82\xBD\x82\xC8\x8F\xCC\x8D\x86\x82\xF0\x93\xBE\x82\xDC\x82\xB5\x82\xBD", "\x90V\x82\xBD\x82\xC8\x8F\xCC\x8D\x86\x82\xF0\x93\xBE\x82\xDC\x82\xB5\x82\xBD", "\x90V\x82\xBD\x82\xC8\x8F\xCC\x8D\x86\x82\xF0\x93\xBE\x82\xDC\x82\xB5\x82\xBD"};
char *lbl_14_data_D50[6] = {"You can customize your original machine as you earn the required Pilot Points. ", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g\x82\xF0\x8BK\x92\xE8\x90\x94\x92\x99\x82\xDF\x82\xE9\x82\xC6\x83I\x83\x8A\x83W\x83i\x83\x8B\x83}\x83V\x83\x93\x82\xF0\x83J\x83X\x83^\x83}\x83" "C\x83Y\x82\xC5\x82\xAB\x82\xDC\x82\xB7\x81" "B", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g\x82\xF0\x8BK\x92\xE8\x90\x94\x92\x99\x82\xDF\x82\xE9\x82\xC6\x83I\x83\x8A\x83W\x83i\x83\x8B\x83}\x83V\x83\x93\x82\xF0\x83J\x83X\x83^\x83}\x83" "C\x83Y\x82\xC5\x82\xAB\x82\xDC\x82\xB7\x81" "B", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g\x82\xF0\x8BK\x92\xE8\x90\x94\x92\x99\x82\xDF\x82\xE9\x82\xC6\x83I\x83\x8A\x83W\x83i\x83\x8B\x83}\x83V\x83\x93\x82\xF0\x83J\x83X\x83^\x83}\x83" "C\x83Y\x82\xC5\x82\xAB\x82\xDC\x82\xB7\x81" "B", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g\x82\xF0\x8BK\x92\xE8\x90\x94\x92\x99\x82\xDF\x82\xE9\x82\xC6\x83I\x83\x8A\x83W\x83i\x83\x8B\x83}\x83V\x83\x93\x82\xF0\x83J\x83X\x83^\x83}\x83" "C\x83Y\x82\xC5\x82\xAB\x82\xDC\x82\xB7\x81" "B", "\x83p\x83" "C\x83\x8D\x83" "b\x83g\x83|\x83" "C\x83\x93\x83g\x82\xF0\x8BK\x92\xE8\x90\x94\x92\x99\x82\xDF\x82\xE9\x82\xC6\x83I\x83\x8A\x83W\x83i\x83\x8B\x83}\x83V\x83\x93\x82\xF0\x83J\x83X\x83^\x83}\x83" "C\x83Y\x82\xC5\x82\xAB\x82\xDC\x82\xB7\x81" "B"};
/* memory card messages: English, German, French, Spanish, Italian, Japanese */
char *lbl_14_data_27FC[29][6] = {
    {"Now Loading. \n\tDo not pull out the Memory Card. \n\tIt can damage the file. \n", "Now Loading GER", "Now Loading FRA", "Now Loading SPA", "Now Loading ITA", "\x83\x8D\x81[\x83h\x92\x86\x82\xC5\x82\xB7\x81" "B\n\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xA9\x82\xC8\x82\xA2\x82\xC5\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n\x83t\x83@\x83" "C\x83\x8B\x82\xAA\x89\xF3\x82\xEA\x82\xE9\x82\xB1\x82\xC6\x82\xAA\x82\xA0\x82\xE8\x82\xDC\x82\xB7\x81" "B\n"},
    {"Failed to load. \n\tPlease remove the Memory Card. \n", "Load Failed GER", "Load Failed FRA", "Load Failed SPA", "Load Failed ITA", "\x83\x8D\x81[\x83h\x82\xC9\x8E\xB8\x94s\x82\xB5\x82\xDC\x82\xB5\x82\xBD\x81" "B\n\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xA2\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"},
    {"This Memory Card can not be used. \n\tThere is no F-ZERO GX game data. \n\tPlease remove the Memory Card. \n", "No File GER", "No File FRA", "No File SPA", "No File ITA", "\x82\xB1\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCD\x8Eg\x97p\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B\n\t\x82" "e\x81|\x82y\x82" "d\x82q\x82n \x82" "f\x82w\x82\xCC\x83Q\x81[\x83\x80\x83" "f\x81[\x83^\x82\xAA\x93\xFC\x82\xC1\x82\xC4\x82\xA2\x82\xDC\x82\xB9\x82\xF1\x81" "B\n\t\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xA2\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"},
    {"This Memory Card can not be used. \nF-ZERO GX game data is corrupted. \n\tPlease remove the Memory Card. \n", "File Broken GER", "File Broken FRA", "File Broken SPA", "File Broken ITA", "\x82\xB1\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCD\x8Eg\x97p\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B\n\t\x82" "e\x81|\x82y\x82" "d\x82q\x82n \x82" "f\x82w\x82\xCC\x83Q\x81[\x83\x80\x83" "f\x81[\x83^\x82\xAA\x89\xF3\x82\xEA\x82\xC4\x82\xA2\x82\xDC\x82\xB7\x81" "B\n\t\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xA2\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"},
    {"This Memory Card can not be used. \n\tThis Memory Card needs to be\n\tformatted by NINTENDO GAMECUBE. \n\tPlease remove the Memory Card. \n", "Encoding GER", "Encoding FRA", "Encoding SPA", "Encoding ITA", "\x82\xB1\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCD\x8Eg\x97p\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B\n\t\x82m\x82h\x82m\x82s\x82" "d\x82m\x82" "c\x82n\x81@\x82" "f\x82`\x82l\x82" "d\x82" "b\x82t\x82" "a\x82" "d\x82\xC5\x8F\x89\x8A\xFA\x89\xBB\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n\t\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xA2\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"},
    {"This Memory Card can not be used. \n\tThis Memory Card is broken or unformatted.  \n\tPlease remove the Memory Card. \n", "IO Error GER", "IO Error FRA", "IO Error SPA", "IO Error ITA", "\x82\xB1\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCD\x8Eg\x97p\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B\n\t\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xAA\x89\xF3\x82\xEA\x82\xC4\x82\xA2\x82\xE9\x82\xA9\x81" "A\n\t\x83t\x83H\x81[\x83}\x83" "b\x83g\x82\xB3\x82\xEA\x82\xC4\x82\xA2\x82\xDC\x82\xB9\x82\xF1\x81" "B\n\t\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xA2\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"},
    {"This Memory Card can not be used. \n\tPlease remove the Memory Card. \n", "Other Error GER", "Other Error FRA", "Other Error SPA", "Other Error ITA", "\x82\xB1\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCD\x8Eg\x97p\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B\n\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xA2\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"},
    {"Playing without the Memory Card. \n", "Memcard no use GER", "Memcard no use FRA", "Memcard no use SPA", "Memcard no use ITA", "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x8Eg\x82\xED\x82\xB8\x82\xC9\x83v\x83\x8C\x83" "C\x82\xB5\x82\xDC\x82\xB7\x81" "B\n"},
    {"Wrong Memory Card. Please remove\n\t the Memory Card and insert \n\tthe /bcff0000/Original Memory Card/bcffffff/ which you started\n\t the game. Save within the given time. \n ", "not same card GER", "not same card FRA", "not same card SPA", "not same card ITA", "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xAA\x8D\xB7\x82\xB5\x91\xD6\x82\xA6\x82\xE7\x82\xEA\x82\xC4\x82\xA2\x82\xDC\x82\xB7\x81" "B\n\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xA2\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n\t\x83Q\x81[\x83\x80\x8AJ\x8En\x8E\x9E\x82\xC9\x8Eg\x97p\x82\xB5\x82\xBD\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x8D\xB7\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n\t\x83^\x83" "C\x83\x80\x83" "A\x83" "E\x83g\x82\xC9\x82\xC8\x82\xE9\x82\xC6\x83Z\x81[\x83u\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B\n"},
    {"Canceled \n", "canceled GER\n", "canceled FRA", "canceled SPA", "not same card ITA", "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xC9\x83Z\x81[\x83u\x82\xB5\x82\xDC\x82\xB9\x82\xF1\x82\xC5\x82\xB5\x82\xBD\x81" "B\n"},
    {"Cound not read the data from the Memory Card. \n\t Please remove the Memory Card. \n", "Can not read GER", "Can not read FRA", "Can not read SPA", "Can not read ITA", "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCC\x83" "f\x81[\x83^\x82\xAA\x93\xC7\x82\xDF\x82\xDC\x82\xB9\x82\xF1\x82\xC5\x82\xB5\x82\xBD\x81" "B\n\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xA2\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"},
    {"There is no Memory Card. Please insert\n\t the /bcff0000/original/bcffffff/ Memory Card which started\n\t the game. Save within the given time. \n\tSave within the given time. \n", "Pull out Memcard GER", "Pull out Memcard FRA", "Pull out Memcard SPA", "Pull out Memcard ITA", "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xAA\x94\xB2\x82\xA9\x82\xEA\x82\xC4\x82\xA2\x82\xDC\x82\xB7\x81" "B\n\x83Q\x81[\x83\x80\x8AJ\x8En\x8E\x9E\x82\xC9\x8Eg\x97p\x82\xB5\x82\xBD\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\n\t\x8D\xB7\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n\t\x83^\x83" "C\x83\x80\x83" "A\x83" "E\x83g\x82\xC9\x82\xC8\x82\xE9\x82\xC6\x83Z\x81[\x83u\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B\n"},
    {"Now saving. \n\tDo not pull out the Memory Card. \n\tIt can damage the file. \n", "Now saving GER", "Now Saving FRA", "Now Saving SPA", "Now Saving ITA", "\x83Z\x81[\x83u\x92\x86\x82\xC5\x82\xB7\x81" "B\n\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xA9\x82\xC8\x82\xA2\x82\xC5\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n\x83t\x83@\x83" "C\x83\x8B\x82\xAA\x89\xF3\x82\xEA\x82\xE9\x82\xB1\x82\xC6\x82\xAA\x82\xA0\x82\xE8\x82\xDC\x82\xB7\x81" "B\n"},
    {"Finished saving in the Memory card. \n", "Save ok GER", "Save ok FRA", "Save ok SPA", "Save ok ITA", "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xD6\x82\xCC\x83Z\x81[\x83u\x82\xAA\x8FI\x97\xB9\x82\xB5\x82\xDC\x82\xB5\x82\xBD\x81" "B\n"},
    {"Failed to save in the Memory Card. \n\tPlease remove the Memory Card. \n", "Save failed GER", "Save failed FRA", "Save failed SPA", "Save failed ITA", "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xD6\x82\xCC\x83Z\x81[\x83u\x82\xAA\x90\xB3\x8F\xED\x82\xC9\n\t\x8Ds\x82\xC8\x82\xED\x82\xEA\x82\xDC\x82\xB9\x82\xF1\x82\xC5\x82\xB5\x82\xBD\x81" "B\n\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xA2\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"},
    {"The Memory Card is ready. \n\tDo not touch the Memory Card during the play. \n\tIt can damage the file. \n ", "Memcard ready GER", "Memcard ready FRA", "Memcard ready SPA", "Memcard ready ITA", "/bcffff00/\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCC\x8F\x80\x94\xF5\x82\xAA\x82\xC5\x82\xAB\x82\xDC\x82\xB5\x82\xBD\x81" "B/bcffffff/\n\t\x83v\x83\x8C\x83" "C\x92\x86\x82\xCC\x94\xB2\x82\xAB\x8D\xB7\x82\xB5\x82\xCD\x8Ds\x82\xC8\x82\xED\x82\xC8\x82\xA2\x82\xC5\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n\t\x83t\x83@\x83" "C\x83\x8B\x82\xAA\x89\xF3\x82\xEA\x82\xE9\x82\xB1\x82\xC6\x82\xAA\x82\xA0\x82\xE8\x82\xDC\x82\xB7\x81" "B\n"},
    {"Now checking. \nDo not pull out the Memory Card. \nIt can damage the file\n ", "Memcard checking GER", "Memcard checking FRA", "Memcard checking SPA", "Memcard checking ITA", "\x83`\x83" "F\x83" "b\x83N\x92\x86\x82\xC5\x82\xB7\x81" "B\n\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x94\xB2\x82\xA9\x82\xC8\x82\xA2\x82\xC5\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"},
    {"Please insert F-ZERO LICENSE CARD after\n\tthe data is loaded from the Memory Card. ", "Defalut GER", "Default FRA", "Default SPA", "Default ITA", "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCC\x83" "f\x81[\x83^\x83\x8D\x81[\x83h\x82\xAA\x8A\xAE\x97\xB9\x82\xB7\x82\xE9\x82\xDC\x82\xC5\n\t \x83\x89\x83" "C\x83Z\x83\x93\x83X\x83J\x81[\x83h\x82\xCC\x91}\x93\xFC\x82\xF0\x82\xA8\x91\xD2\x82\xBF\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"},
    {"Please make sure there is no foreign objectin the slot,\tbefore you insert the Memory Card. \nIt is recommended to only save F-ZERO GX data in the Memory Card.  \nDo not touch the Memory Cardduring the play. It can damage to file. \n", "Caution GER", "Caution FRA", "Caution SPA", "Caution ITA", "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x8D\xB7\x82\xB5\x8D\x9E\x82\xDE\x91O\x82\xC9\x83X\x83\x8D\x83" "b\x83g\x82\xC9\x88\xD9\x8F\xED\x82\xAA\x82\xC8\x82\xA2\x82\xA9\x8Am\x94" "F\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n\t\x81u\x82" "e\x82y\x82" "d\x82q\x82n\x81@\x82" "f\x82w\x81v\x88\xC8\x8AO\x82\xCC\x83" "f\x81[\x83^\x82\xF0\x93\xFC\x82\xEA\x82\xC8\x82\xA2\x82\xC5\x8Eg\x97p\x82\xB7\x82\xE9\x82\xB1\x82\xC6\x82\xF0\x90\x84\x8F\xA7\x82\xB5\x82\xDC\x82\xB7\x81" "B\n\t\x83v\x83\x8C\x83" "C\x92\x86\x82\xCC\x83J\x81[\x83h\x82\xCC\x94\xB2\x82\xAB\x8D\xB7\x82\xB5\x82\xCD\x81" "A\x90\xE2\x91\xCE\x82\xC9\x82\xA8\x82\xE2\x82\xDF\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B"},
    {"NINTENDO GAMECUBE Memory Card\n\tcan not\tbe used at this time. \n", "Memcard Off GER", "Memcard Off FRA", "Memcard Off SPA", "Memcard Off ITA", "\x82\xBD\x82\xBE\x8D\xA1\x81" "A\x82m\x82h\x82m\x82s\x82" "d\x82m\x82" "c\x82n\x81@\x82" "f\x82`\x82l\x82" "d\x82" "b\x82t\x82" "a\x82" "d\n\t\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x8Eg\x97p\x82\xB7\x82\xE9\x82\xB1\x82\xC6\x82\xAA\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B\n"},
    {"Memory Card ca not be used at this time. \n", "All Card Off GER", "All Card Off FRA", "All Card Off SPA", "All Card Off ITA", "\x82\xBD\x82\xBE\x8D\xA1\x81" "A\x83J\x81[\x83h\x82\xCC\x8Eg\x97p\x82\xCD\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B\n"},
    {"Error occurred in the Memory Card Slot\n\tPlease Follow the instructions on the screen", "Slot Error GER", "Slot Error FRA", "Slot Error SPA", "Slot Error ITA", "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x83X\x83\x8D\x83" "b\x83g\x82\xC9\x83G\x83\x89\x81[\x82\xAA\x94\xAD\x90\xB6\x82\xB5\x82\xDC\x82\xB5\x82\xBD\x81" "B\n\x89\xE6\x96\xCA\x82\xCC\x8Ew\x8E\xA6\x82\xC9\x8F]\x82\xC1\x82\xC4\x89\xBA\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"},
    {"Memory Cad can not be used at this time. \n", "No Receive GER", "No Receive FRA", "No Receive SPA", "No Receive ITA", "\x82\xBD\x82\xBE\x8D\xA1\x81" "A\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCC\x8E\xF3\x95t\x82\xCD\x8Ds\x82\xC8\x82\xC1\x82\xC4\x82\xA2\x82\xDC\x82\xB9\x82\xF1\x81" "B\n\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x8Eg\x97p\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B\n"},
    {"Insert the Memory Card with F-ZERO GX data. \n", "Insert Memcard GER", "Insert Memcard FRA", "Insert Memcard SPA", "Insert Memcard ITA", "\x82" "e\x81|\x82y\x82" "d\x82q\x82n\x81@\x82" "f\x82w\x82\xCC\x83" "f\x81[\x83^\x82\xAA\x93\xFC\x82\xC1\x82\xBD\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x8D\xB7\x82\xB5\x82\xC4\x89\xBA\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"},
    {"Do not insert the Memory Card with an important data. \nIt can get damaged\n", "No use Important card GER", "No use Important card FRA", "No use Important card SPA", "No use Important card ITA", "\x83" "f\x81[\x83^\x82\xAA\x8E\xB8\x82\xED\x82\xEA\x82\xE9\x8B\xB0\x82\xEA\x82\xAA\x82\xA0\x82\xE9\x82\xCC\x82\xC5\x91\xE5\x90\xD8\x82\xC8\x83J\x81[\x83h\x82\xCD\x8Eg\x97p\x82\xB5\x82\xC8\x82\xA2\x82\xC5\x89\xBA\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B"},
    {"Now checking...\n", "Now checking GER", "Now checking FRA", "Now checking SPA", "Now checking ITA", "\x83`\x83" "F\x83" "b\x83N\x82\xB5\x82\xC4\x82\xA2\x82\xDC\x82\xB7\x81" "E\x81" "E\x81" "E\n"},
    {"Succeeded to read/write\n", "Read Write OK GER", "Read Write OK FRA", "Read Write OK SPA", "Read Write OK ITA", "\x83\x8A\x81[\x83h\x81^\x83\x89\x83" "C\x83g\x82\xC5\x82\xAB\x82\xDC\x82\xB5\x82\xBD\n"},
    {"Failed to read/write\n", "Read Write falied GER", "Read Write failed FRA", "Read Write failed SPA", "Read Write failed ITA", "\x83\x8A\x81[\x83h\x81^\x83\x89\x83" "C\x83g\x82\xC9\x8E\xB8\x94s\x82\xB5\x82\xDC\x82\xB5\x82\xBD\n"},
    {"Please insert the Memory Card\nbefore you insert the F-ZERO LICENSE CARD.\n", "Read Write falied GER", "Read Write failed FRA", "Read Write failed SPA", "Read Write failed ITA", "\x83\x81\x83\x82\x83\x8A\x81|\x83J\x81[\x83h\x82\xF0\x82\xB2\x8Eg\x97p\x82\xB7\x82\xE9\x95\xFB\x82\xCD\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x90\xE6\x82\xC9\x8D\xB7\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2"},
};
fn_14_2590_Entry lbl_14_data_2AB4[8] = {
    {-1, 0x24},
    {-1, 0x8},
    {-1, 0x2A},
    {-1, 0x8},
    {-1, 0x2A},
    {-1, 0x8},
    {-1, 0x2A},
    {-1, 0x30},
};
fn_14_1090_Sprite lbl_14_data_2AF4 = {lbl_14_data_A7C, 533, 337, 0.45f, 0.55f};
fn_14_1090_Sprite lbl_14_data_2B08[14] = {
    {lbl_14_data_808, 136, 0, 0.5f, 0.5f},
    {lbl_14_data_828, 136, 0, 0.5f, 0.5f},
    {lbl_14_data_84C, 136, 0, 0.5f, 0.5f},
    {lbl_14_data_86C, 136, 0, 0.5f, 0.5f},
    {lbl_14_data_894, 136, 0, 0.5f, 0.5f},
    {lbl_14_data_8B4, 136, 0, 0.5f, 0.5f},
    {lbl_14_data_8D8, 136, 0, 0.5f, 0.5f},
    {lbl_14_data_8FC, 136, 0, 0.5f, 0.5f},
    {lbl_14_data_920, 136, 0, 0.5f, 0.5f},
    {lbl_14_data_944, 136, 0, 0.5f, 0.5f},
    {lbl_14_data_964, 136, 0, 0.5f, 0.5f},
    {lbl_14_data_984, 136, 336, 0.7f, 0.7f},
    {lbl_14_data_9B4, 136, 380, 0.5f, 0.7f},
    {lbl_14_data_A28, 533, 335, 0.45f, 0.55f},
};
fn_14_1090_Score lbl_14_data_2C20[14] = {
    {0, 0, 0, 504, 0, 0.6f, 0.6666666f},
    {0, 0, 0, 504, 0, 0.6f, 0.6666666f},
    {0, 0, 0, 504, 0, 0.6f, 0.6666666f},
    {0, 0, 0, 504, 0, 0.6f, 0.6666666f},
    {0, 0, 0, 504, 0, 0.6f, 0.6666666f},
    {0, 0, 0, 504, 0, 0.6f, 0.6666666f},
    {0, 0, 0, 504, 0, 0.6f, 0.6666666f},
    {0, 0, 0, 504, 0, 0.6f, 0.6666666f},
    {0, 0, 0, 504, 0, 0.6f, 0.6666666f},
    {0, 0, 0, 504, 0, 0.6f, 0.6666666f},
    {0, 0, 0, 504, 0, 0.6f, 0.6666666f},
    {0, 0, 0, 504, 336, 0.8f, 0.8333333f},
    {0, 0, 0, 504, 380, 0.8f, 0.8333333f},
    {0, 0, 0, 597, 344, 0.45f, 0.5833333f},
};
fn_14_1090_Row lbl_14_data_2DA8[14] = {
    {11, 0, 0x3, {0}, 0, 0, 0, 0},
    {12, 0, 0x3, {0}, 0, 0, 0, 0},
    {13, 0, 0x3, {0}, 0, 0, 0, 0},
    {0, 0, 0x1, {0}, 25, 10, 5, 10},
    {1, 0, 0x1, {0}, 25, 10, 5, 10},
    {2, 0, 0x2, {0}, 25, 10, 5, 10},
    {3, 1, 0x2, {0}, 25, 10, 5, 10},
    {4, 0, 0x3, {0}, 25, 10, 5, 10},
    {5, 0, 0x3, {0}, 25, 10, 5, 10},
    {6, 0, 0x2, {0}, 25, 10, 5, 10},
    {7, 1, 0x1, {0}, 25, 10, 5, 10},
    {8, 1, 0x2, {0}, 25, 10, 5, 10},
    {9, 1, 0x2, {0}, 25, 10, 5, 10},
    {10, 1, 0x3, {0}, 25, 10, 5, 10},
};
u32 lbl_14_data_2F30 = 0x80000000;
s16 lbl_14_data_2F34 = 30;
s16 lbl_14_data_2F36 = 1;
u32 lbl_14_data_2F38 = 0x2;
u32 lbl_14_data_2F3C = 0x10000;
u32 lbl_14_data_2F40 = 0x40000000;
u32 lbl_14_data_2F44 = 0x80000000;
s32 lbl_14_data_2F48 = -1;
s32 lbl_14_data_2F4C[6] = {-1, -1, -1, -1, -1, -1};
u32 lbl_14_data_2F64[6] = {0x8D00, 0x8D01, 0x8D02, 0x8D03, 0x8D04, 0x8D05};
u32 lbl_14_data_2F7C[3] = {0x8D12, 0x8D11, 0x8D13};
u32 lbl_14_data_2F88[10] = {0x8D06, 0x8D07, 0x8D08, 0x8D09, 0x8D0A, 0x8D0B, 0x8D0C, 0x8D0D, 0x8D0E, 0x8D0F};

s32 lbl_14_bss_0 = 0;
s32 lbl_14_bss_4 = 0;
s32 lbl_14_bss_8 = 0;
s32 lbl_14_bss_C = 0;
s32 lbl_14_bss_10 = 0;
u32 lbl_14_bss_14 = 0;
u32 lbl_14_bss_18 = 0;
u32 lbl_14_bss_1C;
u32 lbl_14_bss_20;
s32 lbl_14_bss_24;
s32 lbl_14_bss_28;
s32 lbl_14_bss_2C;
s32 lbl_14_bss_30;
s32 lbl_14_bss_34;
s32 lbl_14_bss_38;
s32 lbl_14_bss_3C;
s32 lbl_14_bss_40;
s32 lbl_14_bss_44;
s32 lbl_14_bss_48;
s32 lbl_14_bss_4C;
s32 lbl_14_bss_50;
s32 lbl_14_bss_54;
char lbl_14_bss_58[0x14];
char lbl_14_bss_6C[0x40];
char lbl_14_bss_AC[0x40];
s32 lbl_14_bss_EC;
s32 lbl_14_bss_F0;
s32 lbl_14_bss_F4;
s32 lbl_14_bss_F8;
s32 lbl_14_bss_FC;
s32 lbl_14_bss_100;
s32 lbl_14_bss_104;
s32 lbl_14_bss_108;
fn_14_2590_Obj110 lbl_14_bss_110;
s16 lbl_14_bss_160;
s16 lbl_14_bss_162;
s16 lbl_14_bss_164;
s16 lbl_14_bss_166;
fn_14_2590_Record lbl_14_bss_180 __attribute__((aligned(32)));
struct PilotPoint *lbl_14_bss_8340;
struct PilotPoint *lbl_14_bss_8344;
void *lbl_14_bss_8348;
void *lbl_14_bss_834C;
fn_14_2C80_Rec *lbl_14_bss_8350;
fn_14_2C80_Elem lbl_14_bss_8354[3];
u8 lbl_14_bss_91F4[0x64];
u8 lbl_14_bss_9258[0x64];
s32 lbl_14_bss_92BC;
s32 lbl_14_bss_92C0;
PPCamera lbl_14_bss_92C4;
PPRect lbl_14_bss_92E8;
PPRect lbl_14_bss_92F0;
s32 lbl_14_bss_92F8;
PPReward lbl_14_bss_92FC[54];

/* fzgx:begin _prolog */
void _prolog(void) {
    u32 buffer[1328];

    lbl_1_bss_7167C[0] = fn_14_220;
    lbl_1_bss_71680 = fn_14_268;
    lbl_1_bss_71684[0] = fn_14_2A0;

    lbl_14_bss_14 = fn_1_45D0(lbl_801A6410.unk_0, fn_1_7BA08(0x20, 0x20, 0x40), "pilotpoint.c", 787);
    fn_1_7BA48(lbl_14_bss_14);

    lbl_14_bss_1C = fn_1_45D0(lbl_801A6410.unk_0, 0x173C, "pilotpoint.c", 788);
    fn_1_3CF0(lbl_14_bss_1C, 0x80);

    lbl_14_bss_20 = fn_1_45D0(lbl_801A6410.unk_0, 0x173C, "pilotpoint.c", 789);
    fn_1_3CF0(lbl_14_bss_20, 0x80);

    fn_1_435C(lbl_14_bss_20);
    fn_1_3F8C("LightMain", fn_1_7BAF8, (void *)lbl_14_bss_14, 2);

    fn_1_411A4(1);
    fn_1_48418(2);
    fn_1_479F0(13);
    fn_1_479F0(1);
    fn_1_159440(2, 0);

    lbl_1_bss_96A = 0xAC;
    fn_8006CE1C(0.0f);

    fn_1_A8F78();
    fn_1_A0680();

    fn_1_A1588(*lbl_1_bss_6EAD0, 0x1F);
    fn_14_DC2C();
    fn_1_3EF14(buffer);
}
/* fzgx:end _prolog */

/* fzgx:begin _epilog */
void _epilog(void) {
    fn_1_435C(lbl_14_bss_1C);
    fn_1_41A8();
    fn_1_435C(lbl_14_bss_20);
    fn_1_41A8();
    fn_1_1596DC(2);
    fn_1_47A60(1);
    fn_1_47A60(13);
    fn_1_484CC(2);
    fn_1_412A0(1);
    fn_1_A0AA4();
    fn_1_46B4(lbl_801A6410.unk_0, lbl_14_bss_14, "pilotpoint.c", 860);
    lbl_14_bss_14 = 0;
}
/* fzgx:end _epilog */

/* fzgx:begin fn_14_220 */
void fn_14_220(void) {
    fn_1_3CC4(fn_1_407C(fn_1_435C(lbl_14_bss_1C)));
    fn_1_407C(fn_1_435C(lbl_14_bss_20));
}
/* fzgx:end fn_14_220 */

/* fzgx:begin fn_14_268 */
u32 fn_14_268(void) {
    u32 v0;

    lbl_14_bss_0--;
    v0 = lbl_1_bss_8B3A0.unk_124;
    if (v0 + 0x10000 != 0xffff) {
        lbl_1_bss_8B3A0.unk_124 = v0 - 1;
    }
    return v0;
}
/* fzgx:end fn_14_268 */

/* fzgx:begin fn_14_2A0 */
void fn_14_2A0(void) {
    PPScene *scene;
    s32 index;

    scene = lbl_14_data_308;
    index = lbl_1_bss_962;
    scene += index - 172;
    lbl_1_bss_71688 = scene->main;
    lbl_1_bss_7168C = scene->exit;
    scene->init();
}
/* fzgx:end fn_14_2A0 */

/* fzgx:begin fn_14_2FC */
void fn_14_2FC(void) {
    u32 v0;

    lbl_14_bss_0 = 60;
    v0 = lbl_1_bss_8B3A0.unk_94;
    lbl_14_bss_24 = 24;
    lbl_14_bss_28 = 24;
    lbl_14_bss_2C = 16;
    lbl_14_bss_30 = 16;
    lbl_14_bss_34 = 12;
    lbl_1_bss_8B3A0.unk_94 = v0 | 0x40000000;
    fn_1_12F1E8(539);
    lbl_1_bss_8B3A0.unk_94 = v0;
    fn_1_A2D84(0xA9110000);
}
/* fzgx:end fn_14_2FC */

/* fzgx:begin fn_14_380 */
void fn_14_380(void) {
    f32 v1;
    f32 v0;
    f32 v18;
    f32 v5;
    f32 v9;
    f32 v11;
    f32 v13;
    f64 v16;
    f32 v17;
    f32 v19;
    f32 v21;
    f32 v23;
    f32 v25;
    f32 v27;
    f32 v29;
    f32 v31;
    f32 v33;
    f32 v35;
    f32 v37;
    f32 v39;
    f32 v41;
    f32 v43;
    f32 v45;
    f32 v47;
    f32 v49;
    FontDrawPacket loc_8;

    fn_1_133DBC(NULL);
    fn_1_134AD4();
    fn_1_13DC54();
    fn_1_13B328(0x1000000, 1);
    fn_1_138120(lbl_14_data_D50[lbl_801A66B4]);
    loc_8 = lbl_1_rodata_26F8;
    v0 = 167.0f;
    v1 = 38.0f;
    loc_8.image = 0x10000 - 28155;
    loc_8.x = v0;
    loc_8.y = v1;
    loc_8.z = 90.0f;
    loc_8.flags = 10;
    fn_1_4F734(&loc_8);
    loc_8 = lbl_1_rodata_26F8;
    loc_8.image = 0x10000 - 25045;
    loc_8.flags = 10;
    lbl_14_bss_28 += lbl_14_bss_30;
    if (lbl_14_bss_28 > 190) {
        lbl_14_bss_28 = 190;
        lbl_14_bss_24 += lbl_14_bss_2C;
    }
    if (lbl_14_bss_24 > 396) {
        lbl_14_bss_24 = 396;
    }
    loc_8.x = 320.0f;
    loc_8.y = 216.0f;
    v5 = 8.0f;
    fn_1_50164(&loc_8, lbl_14_bss_24, lbl_14_bss_28, v5, v5);
    loc_8.x = 320.0f;
    loc_8.y = 96.0f;
    v9 = 8.0f;
    fn_1_50164(&loc_8, lbl_14_bss_24, 38.0f, v9, v9);
    loc_8.x = 320.0f;
    loc_8.y = 336.0f;
    v11 = 8.0f;
    fn_1_50164(&loc_8, lbl_14_bss_24, 38.0f, v11, v11);
    loc_8.x = 320.0f;
    loc_8.y = 380.0f;
    v13 = 8.0f;
    fn_1_50164(&loc_8, lbl_14_bss_24, 38.0f, v13, v13);
    if (lbl_14_bss_24 == 396 && lbl_14_bss_28 == 190) {
        v16 = 12.0;
        v17 = 1.0f;
        v18 = v16 - lbl_14_bss_34;
        v18 /= v16;
        if (v18 > v17) {
            v18 = v17;
        }
        loc_8.alpha = v18;
        loc_8.x = 99.0f;
        loc_8.y = 96.0f;
        v19 = 30.0f;
        fn_1_50164(&loc_8, v19, v19, 8.0f, 8.0f);
        loc_8.x = 99.0f;
        loc_8.y = 140.0f;
        v21 = 30.0f;
        fn_1_50164(&loc_8, v21, v21, 8.0f, 8.0f);
        loc_8.x = 99.0f;
        loc_8.y = 178.0f;
        v23 = 30.0f;
        fn_1_50164(&loc_8, v23, v23, 8.0f, 8.0f);
        loc_8.x = 99.0f;
        loc_8.y = 216.0f;
        v25 = 30.0f;
        fn_1_50164(&loc_8, v25, v25, 8.0f, 8.0f);
        loc_8.x = 99.0f;
        loc_8.y = 254.0f;
        v27 = 30.0f;
        fn_1_50164(&loc_8, v27, v27, 8.0f, 8.0f);
        loc_8.x = 99.0f;
        loc_8.y = 292.0f;
        v29 = 30.0f;
        fn_1_50164(&loc_8, v29, v29, 8.0f, 8.0f);
        loc_8.x = 99.0f;
        loc_8.y = 336.0f;
        v31 = 30.0f;
        fn_1_50164(&loc_8, v31, v31, 8.0f, 8.0f);
        loc_8.x = 99.0f;
        loc_8.y = 380.0f;
        v33 = 30.0f;
        fn_1_50164(&loc_8, v33, v33, 8.0f, 8.0f);
        loc_8.x = 541.0f;
        loc_8.y = 96.0f;
        v35 = 30.0f;
        fn_1_50164(&loc_8, v35, v35, 8.0f, 8.0f);
        loc_8.x = 541.0f;
        loc_8.y = 140.0f;
        v37 = 30.0f;
        fn_1_50164(&loc_8, v37, v37, 8.0f, 8.0f);
        loc_8.x = 541.0f;
        loc_8.y = 178.0f;
        v39 = 30.0f;
        fn_1_50164(&loc_8, v39, v39, 8.0f, 8.0f);
        loc_8.x = 541.0f;
        loc_8.y = 216.0f;
        v41 = 30.0f;
        fn_1_50164(&loc_8, v41, v41, 8.0f, 8.0f);
        loc_8.x = 541.0f;
        loc_8.y = 254.0f;
        v43 = 30.0f;
        fn_1_50164(&loc_8, v43, v43, 8.0f, 8.0f);
        loc_8.x = 541.0f;
        loc_8.y = 292.0f;
        v45 = 30.0f;
        fn_1_50164(&loc_8, v45, v45, 8.0f, 8.0f);
        loc_8.x = 575.0f;
        loc_8.y = 336.0f;
        v47 = 8.0f;
        fn_1_50164(&loc_8, 98.0f, 42.0f, v47, v47);
        loc_8.x = 541.0f;
        loc_8.y = 380.0f;
        v49 = 30.0f;
        fn_1_50164(&loc_8, v49, v49, 8.0f, 8.0f);
        lbl_14_bss_34--;
    }
    if (lbl_14_bss_0 < 0) {
        lbl_1_bss_96A = 173;
    }
}
/* fzgx:end fn_14_380 */

/* fzgx:begin fn_14_900 */
// fn_14_900: empty in retail (single blr).
void fn_14_900(void) {
}
/* fzgx:end fn_14_900 */

/* fzgx:begin fn_14_904 */
void fn_14_904(void) {
    struct { u8 a[5304]; } race;
    u8 *player;
    s32 rank;
    fn_14_1090_Score *score;
    s32 i;
    /* WARNING: compiler-diff device, not original code (volatile: retail reloads each row's index when testing display eligibility) */
    volatile fn_14_1090_Row *row;
    s32 total;
    u8 mask;
    u32 oldFlags;
    f64 product;
    s32 limit;
    s32 cap;

    lbl_14_bss_38 = 0;
    lbl_14_bss_3C = 0;
    score = lbl_14_data_2C20;
    for (i = 0; i < 14; i++, score++) {
        score->cur = 0;
        score->step = 0;
        score->prev = 0;
    }
    fn_1_3EF14(&race);
    player = race.a + fn_14_DC2C() * 160 + 212;
    lbl_14_data_2C20[0].cur = *(s16 *)(player + 0x84) / 10 * 10;
    lbl_14_data_2C20[1].cur = *(s16 *)(player + 0x86) / 10 * 10;
    lbl_14_data_2C20[2].cur = *(s16 *)(player + 0x88) / 10 * 10;
    if (race.a[5] == 2) {
        rank = fn_1_155F8C() + 1;
        if (rank == 0 || (*(u32 *)race.a & 0x1000) == 0) {
            lbl_14_data_2C20[3].cur = 0;
        } else if (rank == 1) {
            lbl_14_data_2C20[3].cur = 5000;
        } else if (rank == 2) {
            lbl_14_data_2C20[3].cur = 4000;
        } else if (rank == 3) {
            lbl_14_data_2C20[3].cur = 3000;
        } else if (rank == 4) {
            lbl_14_data_2C20[3].cur = 2000;
        } else if (rank == 5) {
            lbl_14_data_2C20[3].cur = 1500;
        } else if (rank >= 6 && rank <= 30) {
            lbl_14_data_2C20[3].cur = 999 - (rank - 5) * 10;
        } else {
            lbl_14_data_2C20[3].cur = 0;
        }
    } else {
        lbl_14_data_2C20[3].cur = 0;
    }
    lbl_14_data_2C20[3].cur = lbl_14_data_2C20[3].cur / 10 * 10;
    lbl_14_data_2C20[4].cur = *(s16 *)(player + 0x8C) / 10 * 10;
    lbl_14_data_2C20[5].cur = *(s16 *)(player + 0x8E) / 10 * 10;
    lbl_14_data_2C20[6].cur = *(s16 *)(player + 0x98) / 10 * 10;
    if (lbl_14_bss_3C != 0) {
        lbl_14_data_2C20[7].cur = *(s32 *)(player + 0x90) / 10 * 10;
    } else {
        lbl_14_data_2C20[7].cur = 0;
    }
    if (lbl_14_bss_38 != 0) {
        lbl_14_data_2C20[8].cur = *(s32 *)(player + 0x94) / 10 * 10;
    } else {
        lbl_14_data_2C20[8].cur = 0;
    }
    if (race.a[5] == 2) {
        if (fn_1_F1B84() == 1 && player[0xE] != 254) {
            lbl_14_data_2C20[9].cur = 50000;
        } else {
            lbl_14_data_2C20[9].cur = 0;
        }
    } else {
        lbl_14_data_2C20[9].cur = 0;
    }
    lbl_14_data_2C20[10].cur = *(s16 *)(player + 0x9C) / 10 * 10;
    if (race.a[5] == 2 && fn_1_F1B84() == 0 && fn_1_F1B94() == 1) {
        if (lbl_1_bss_8B3A0.unk_9C == 3) {
            lbl_14_data_2C20[10].cur += 3000;
        } else if (lbl_1_bss_8B3A0.unk_9C == 2) {
            lbl_14_data_2C20[10].cur += 2000;
        } else if (lbl_1_bss_8B3A0.unk_9C == 1) {
            lbl_14_data_2C20[10].cur += 1000;
        }
    }
    lbl_1_bss_8B3A0.unk_9C = 0;
    lbl_14_bss_10 = 0;
    mask = (lbl_1_bss_8B3A0.unk_0 == 9) ? 1 : 2;
    for (i = 0, row = lbl_14_data_2DA8; i < 14; i++, row++) {
        score = &lbl_14_data_2C20[row->index];
        if (score->cur + score->prev != 0 || row->always == 0) {
            if ((row->mask & mask) != 0) {
                s32 index = row->index;
                if (index != 11 && (u32)(index - 12) > 1) {
                    lbl_14_bss_10++;
                }
            }
        }
    }
    product = 25.0 * lbl_14_bss_10;
    lbl_14_bss_40 = 60.0 + product;
    total = 0;
    for (i = 0; i < 14; i++) {
        fn_14_1090_Row *row = lbl_14_data_2DA8;
        s32 j;

        for (j = 0; j < 14; j++, row++) {
            if (row->index == i) {
                break;
            }
        }
        total += lbl_14_data_2C20[i].cur;
        lbl_14_data_2C20[i].prev = lbl_14_data_2C20[i].cur;
        lbl_14_data_2C20[i].step = lbl_14_data_2C20[i].prev / (row->count_frames - 1);
        lbl_14_data_2C20[i].cur = 0;
    }
    lbl_14_data_2C20[11].step = total / 29.0;
    cap = 99900;
    limit = 100000;
    lbl_14_data_2C20[12].cur = cap;
    lbl_14_bss_44 = limit;
    lbl_14_bss_48 = cap;
    lbl_14_data_2C20[13].cur = 100;
    lbl_14_bss_4C = 0;
    lbl_14_bss_50 = 0;
    if (total + cap - limit >= 0) {
        lbl_14_bss_4C = 1;
        lbl_14_bss_50 = 240;
        lbl_14_bss_54 = limit;
    }
    sprintf(lbl_14_bss_58, "\x82\xBF\x82\xE6\x82\xCC\x82\xD3\x82\xB6\x82\xBA\x82\xAB\x82\xE6");
    sprintf(lbl_14_bss_6C, "\x82\xA2\x82\xEB\x82\xCD\x82\xC9\x83\x89\x83" "C\x83Z\x83\x93\x83X");
    sprintf(lbl_14_bss_AC, "\x82\xD9\x82\xD6\x82\xC6\x83\x89\x83" "C\x83Z\x83\x93\x83X");
    if (total >= 0) {
        lbl_14_bss_EC = 0;
        lbl_14_bss_F0 = 0;
    }
    lbl_14_bss_F4 = 0;
    lbl_14_bss_F8 = 0;
    lbl_14_bss_FC = 0;
    lbl_14_bss_100 = 0;
    if (lbl_14_bss_104 < 20 && lbl_14_bss_108 >= 20) {
        lbl_14_bss_FC = 1;
        lbl_14_bss_F4 = 240;
        lbl_14_bss_EC = 0;
        lbl_14_bss_F0 = 0;
    } else if (lbl_14_bss_104 != lbl_14_bss_108 && lbl_14_bss_108 >= 20) {
        lbl_14_bss_100 = 1;
        lbl_14_bss_F8 = 240;
        lbl_14_bss_EC = 0;
        lbl_14_bss_F0 = 0;
    }
    fn_14_DC28();
    oldFlags = lbl_1_bss_8B3A0.unk_94;
    lbl_14_bss_0 = 0x924;
    lbl_14_bss_8 = 0;
    lbl_14_bss_4 = 0;
    lbl_1_bss_8B3A0.unk_94 = oldFlags | 0x40000000;
    fn_1_12F1E8(0x923);
    lbl_1_bss_8B3A0.unk_94 = oldFlags;
}
/* fzgx:end fn_14_904 */

/* fzgx:begin fn_14_1090 */
/* fade-in of a rank banner from its countdown: (t - 18) / 18, clamped to [0, 1] */

#define PP_FADE(t) PP_CLAMP((f32)((t) - 18.0) / 18.0)

#define PP_CLAMP(v) ((v) < 0.0 ? 0.0 : ((v) > 1.0 ? 1.0 : (v)))

/* Pilot-point result screen, one frame: the frame grid, the pilot name and rank banners, then the
 * score rows counting up into the total (11), which then drains into the banked points (12). */

void fn_14_1090(void) {
    FontDrawPacket pkt;
    FontDrawPacket frame;
    fn_14_1090_Score *scores;
    u32 i;
    u32 elapsed;
    fn_14_1090_Sprite *sprite;
    fn_14_1090_Score *score;
    fn_14_1090_Row *row;
    s32 shown;
    s32 mask;  /* 1 when the game mode is 9, else 2; tested against each row's u8 mask */
    f32 alpha;
    f32 t;
    u32 oldFlags;

    fn_1_133DBC(NULL);
    fn_1_134AD4();
    fn_1_13DC54();
    fn_1_13B328(0x1000000, 1);
    fn_1_138120(lbl_14_data_D50[lbl_801A66B4]);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9205;
    pkt.x = 167.0f;
    pkt.y = 38.0f;
    pkt.z = 90.0f;
    pkt.flags = 10;
    fn_1_4F734(&pkt);
    frame = lbl_1_rodata_26F8;
    frame.image = 0x9E2B;
    frame.flags = 10;
    frame.x = 320.0f;
    frame.y = 96.0f;
    fn_1_50164(&frame, 396.0f, 38.0f, 8.0f, 8.0f);
    frame.x = 320.0f;
    frame.y = 216.0f;
    fn_1_50164(&frame, 396.0f, 190.0f, 8.0f, 8.0f);
    frame.x = 320.0f;
    frame.y = 336.0f;
    fn_1_50164(&frame, 396.0f, 38.0f, 8.0f, 8.0f);
    frame.x = 320.0f;
    frame.y = 380.0f;
    fn_1_50164(&frame, 396.0f, 38.0f, 8.0f, 8.0f);
    frame.x = 99.0f;
    frame.y = 96.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 99.0f;
    frame.y = 140.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 99.0f;
    frame.y = 178.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 99.0f;
    frame.y = 216.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 99.0f;
    frame.y = 254.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 99.0f;
    frame.y = 292.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 99.0f;
    frame.y = 336.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 99.0f;
    frame.y = 380.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 541.0f;
    frame.y = 96.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 541.0f;
    frame.y = 140.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 541.0f;
    frame.y = 178.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 541.0f;
    frame.y = 216.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 541.0f;
    frame.y = 254.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 541.0f;
    frame.y = 292.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);
    frame.x = 575.0f;
    frame.y = 336.0f;
    fn_1_50164(&frame, 98.0f, 42.0f, 8.0f, 8.0f);
    frame.x = 541.0f;
    frame.y = 380.0f;
    fn_1_50164(&frame, 30.0f, 30.0f, 8.0f, 8.0f);

    mask = (lbl_1_bss_8B3A0.unk_0 == 9) ? 1 : 2;
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_4965C(2);
    if (lbl_14_bss_EC != 0 && lbl_14_bss_F0 < 120) {
        alpha = PP_FADE(lbl_14_bss_F0);
    } else if (lbl_14_bss_FC != 0 && lbl_14_bss_F4 < 120) {
        alpha = PP_FADE(lbl_14_bss_F4);
    } else if (lbl_14_bss_100 != 0 && lbl_14_bss_F8 < 120) {
        alpha = PP_FADE(lbl_14_bss_F8);
    } else {
        alpha = 1.0f;
    }

    fn_1_4955C(0.5f, 0.5f);
    fn_1_495C8(8);
    {
        fn_14_1090_Color c = {0xA0, 0xFF, 0x00, 0xFF};
        fn_1_49514(&c);
    }
    fn_1_496FC(136.0f, 96.0f);
    fn_1_4AE0C("%s ", lbl_14_data_A9C[lbl_801A66B4]);
    fn_1_4955C(0.5f, 0.55f);
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(&c);
    }
    fn_1_4CF3C("%s", 108.0f, lbl_14_bss_58);
    fn_1_495A0(1.0f);

    fn_1_4955C(0.5f, 0.5f);
    {
        fn_14_1090_Color c = {0xA0, 0xFF, 0x00, 0xFF};
        fn_1_49514(&c);
    }
    fn_1_496FC(300.0f, 96.0f);
    fn_1_4CF3C("%s ", 80.0f, lbl_14_data_AC0[lbl_801A66B4]);
    fn_1_4955C(0.5f, 0.55f);
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(&c);
    }
    fn_1_495A0(alpha);
    fn_1_496FC(400.0f, 96.0f);
    fn_1_4CF3C("%s", 108.0f, lbl_14_bss_6C);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9500;
    fn_1_51564(0, 0, 20, 20, 10, 4);
    fn_1_5158C(&pkt, pkt.image, lbl_14_bss_104 % 10, lbl_14_bss_104 / 10);
    pkt.x = 388.0f;
    pkt.y = 97.0f;
    pkt.z = 0.05f;
    pkt.flags = 10;
    pkt.alpha = alpha;
    fn_1_4F734(&pkt);
    fn_1_495A0(1.0f);

    fn_1_4955C(0.5f, 0.5f);
    {
        fn_14_1090_Color c = {0xA0, 0xFF, 0x00, 0xFF};
        fn_1_49514(&c);
    }
    fn_1_496FC(300.0f, 96.0f);
    fn_1_4CF3C("%s ", 80.0f, lbl_14_data_AC0[lbl_801A66B4]);
    fn_1_4955C(0.5f, 0.55f);
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(&c);
    }
    alpha = 1.0f - alpha;
    fn_1_495A0(alpha);
    fn_1_496FC(400.0f, 96.0f);
    fn_1_4CF3C("%s", 108.0f, lbl_14_bss_AC);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9500;
    fn_1_51564(0, 0, 20, 20, 10, 4);
    fn_1_5158C(&pkt, pkt.image, lbl_14_bss_108 % 10, lbl_14_bss_108 / 10);
    pkt.x = 388.0f;
    pkt.y = 97.0f;
    pkt.z = 0.05f;
    pkt.flags = 10;
    pkt.alpha = alpha;
    fn_1_4F734(&pkt);
    fn_1_495A0(1.0f);

    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    row = lbl_14_data_2DA8;
    lbl_14_bss_C = 139;
    elapsed = 0;
    for (i = 0; i < 14; i++, row++) {
        score = &lbl_14_data_2C20[row->index];
        scores = lbl_14_data_2C20;  /* loop-invariant: hoisted after the mask conversion, live to the end */
        sprite = &lbl_14_data_2B08[row->index];
        shown = 0;
        if ((score->cur + score->prev != 0 || row->always == 0) && (row->mask & (u8)mask)) {
            {
                fn_14_1090_Color c = {0xA0, 0xFF, 0x00, 0xFF};
                fn_1_49514(&c);
            }
            fn_1_495C8(8);
            if (sprite->y == 0) {
                fn_1_496FC(sprite->x, lbl_14_bss_C);
            } else {
                fn_1_496FC(sprite->x, sprite->y);
            }
            fn_1_4955C(sprite->scale_x, sprite->scale_y);
            if (elapsed > lbl_14_bss_8) {
                t = 0.0f;
            } else if (elapsed + row->sprite_frames <= lbl_14_bss_8) {
                t = 1.0f;
            } else {
                t = (lbl_14_bss_8 - elapsed) / (f32)row->sprite_frames;
            }
            if (t > 0.0f && sprite->x != -1 && sprite->y != -1) {
                if (t < 1.0f) {
                    fn_1_A2D84(0xA9010900);
                }
                if (row->index == 13 && scores[13].cur <= 0) {
                    {
                        fn_14_1090_Color c = {0xFF, 0x80, 0x80, 0xFF};
                        fn_1_49514(&c);
                    }
                    fn_14_C69C(&lbl_14_data_2AF4, 1.0f);
                    {
                        fn_14_1090_Color c = {0xA0, 0xFF, 0x00, 0xFF};
                        fn_1_49514(&c);
                    }
                } else {
                    fn_14_C69C(sprite, t);
                    if (row->index != 11 && (u32)(row->index - 12) > 1) {
                        shown = 1;
                    }
                }
            }
            elapsed += row->sprite_frames;
            fn_1_495C8(10);
            {
                fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0x00};
                fn_1_49514(&c);
            }
            if (score->y == 0) {
                fn_1_496FC(score->x, lbl_14_bss_C);
            } else {
                fn_1_496FC(score->x, score->y);
            }
            fn_1_4955C(score->scale_x, score->scale_y);
            if (elapsed > lbl_14_bss_8) {
                t = 0.0f;
            } else if (elapsed + row->count_frames <= lbl_14_bss_8) {
                t = 1.0f;
            } else {
                t = (lbl_14_bss_8 - elapsed) / (f32)row->count_frames;
            }
            if (t > 0.0f) {
                if (row->index != 11 && (u32)(row->index - 12) > 1) {
                    if (score->step >= 0) {
                        if (score->prev <= score->step) {
                            score->cur += score->prev;
                            scores[11].cur += score->prev;
                            if (score->step != 0 || score->prev != 0) {
                                fn_1_A2D84(0xA9010B00);
                            }
                            score->prev = 0;
                            score->step = 0;
                        } else {
                            score->cur += score->step;
                            scores[11].cur += score->step;
                            score->prev -= score->step;
                            fn_1_A2D84(0xA9010A00);
                        }
                    } else {
                        if (score->prev >= score->step) {
                            score->cur += score->prev;
                            scores[11].cur += score->prev;
                            if (score->step != 0 || score->prev != 0) {
                                fn_1_A2D84(0xA9010B00);
                            }
                            score->prev = 0;
                            score->step = 0;
                        } else {
                            score->cur += score->step;
                            scores[11].cur += score->step;
                            score->prev -= score->step;
                            fn_1_A2D84(0xA9010A00);
                        }
                    }
                }
                if (row->index != 13 || scores[13].cur > 0) {
                    fn_14_C850(score, t);
                    if (row->index != 11 && (u32)(row->index - 12) > 1) {
                        shown = 1;
                    }
                }
            }
            elapsed += row->count_frames;
            elapsed += row->wait_frames;
            if (shown) {
                lbl_14_bss_C += 22;
            }
        }
    }

    if (lbl_14_bss_8 >= lbl_14_bss_40) {
        fn_14_1090_Score *bank = lbl_14_data_2C20;
        if (scores[11].step > 0) {
            if (scores[11].cur <= scores[11].step) {
                bank[12].cur += scores[11].cur;
                lbl_14_bss_48 += scores[11].cur;
                if (scores[11].step != 0 || scores[11].cur != 0) {
                    fn_1_A2D84(0xA9010800);
                }
                scores[11].step = 0;
                scores[11].cur = 0;
            } else {
                bank[12].cur += scores[11].step;
                scores[11].cur -= scores[11].step;
                lbl_14_bss_48 += scores[11].step;
                fn_1_A2D84(0xA9010700);
            }
        } else {
            if (scores[11].cur >= scores[11].step) {
                bank[12].cur += scores[11].cur;
                lbl_14_bss_48 += scores[11].cur;
                if (scores[11].step != 0 || scores[11].cur != 0) {
                    fn_1_A2D84(0xA9010800);
                }
                scores[11].step = 0;
                scores[11].cur = 0;
            } else {
                bank[12].cur += scores[11].step;
                scores[11].cur -= scores[11].step;
                lbl_14_bss_48 += scores[11].step;
                fn_1_A2D84(0xA9010700);
            }
        }
    }
    scores[13].cur = lbl_14_bss_44 - lbl_14_bss_48;
    if (scores[13].cur < 0) {
        scores[13].cur = 0;
    }

    if (lbl_14_bss_8 >= 90.0 + lbl_14_bss_40 && lbl_14_bss_F0 > 0) {
        if (lbl_14_bss_F0 == 240) {
            fn_1_A2D84(0xA9150300);
        }
        lbl_14_bss_F0--;
        lbl_14_bss_8--;
        fn_1_4FD64();
        fn_14_CC70(lbl_14_bss_F0);
    } else if (lbl_14_bss_8 >= 90.0 + lbl_14_bss_40 && lbl_14_bss_50 > 0) {
        lbl_14_bss_50--;
        lbl_14_bss_8--;
        fn_1_4FD64();
        fn_14_D2EC(lbl_14_bss_50);
    } else if (lbl_14_bss_8 >= 90.0 + lbl_14_bss_40 && lbl_14_bss_F4 > 0) {
        lbl_14_bss_F4--;
        lbl_14_bss_8--;
        fn_1_4FD64();
        fn_14_D600(lbl_14_bss_F4);
    } else if (lbl_14_bss_8 >= 90.0 + lbl_14_bss_40 && lbl_14_bss_F8 > 0) {
        lbl_14_bss_F8--;
        lbl_14_bss_8--;
        fn_1_4FD64();
        fn_14_D914(lbl_14_bss_F8);
    }

    if (lbl_14_bss_4 == 0 && ((lbl_1_bss_D58.unk_8 >> 8) & 1)) {
        if (lbl_14_bss_8 < 30.0 + lbl_14_bss_40) {
            lbl_14_bss_8 = 2.0 + (30.0 + lbl_14_bss_40);
            lbl_14_bss_0 = 540 - lbl_14_bss_8;
            for (i = 0, row = lbl_14_data_2DA8; i < 14; i++, row++) {
                s32 index = row->index;
                score = &lbl_14_data_2C20[index];
                if (index != 11 && (u32)(index - 12) > 1) {
                    score->cur += score->prev;
                    scores[11].cur += score->prev;
                    score->prev = 0;
                }
            }
            for (i = 0, row = lbl_14_data_2DA8; i < 14; i++, row++) {
                if (row->index == 11 || row->index == 12 || row->index == 13) {
                    if (scores[11].cur > 0) {
                        lbl_14_data_2C20[12].cur += scores[11].cur;
                        lbl_14_bss_48 += scores[11].cur;
                        scores[11].step = 0;
                        scores[11].cur = 0;
                    } else {
                        lbl_14_data_2C20[12].cur += scores[11].cur;
                        lbl_14_bss_48 += scores[11].cur;
                        scores[11].step = 0;
                        scores[11].cur = 0;
                    }
                }
            }
            oldFlags = lbl_1_bss_8B3A0.unk_94;
            lbl_1_bss_8B3A0.unk_94 = oldFlags | 0x40000000;
            fn_1_12F1E8(lbl_14_bss_0);
            lbl_1_bss_8B3A0.unk_94 = oldFlags;
        } else {
            lbl_14_bss_4 = 1;
            oldFlags = lbl_1_bss_8B3A0.unk_94;
            lbl_1_bss_8B3A0.unk_94 = oldFlags | 0x40000000;
            fn_1_12F1E8(0);
            lbl_1_bss_8B3A0.unk_94 = oldFlags;
        }
    }

    lbl_14_bss_8++;
    if (scores[11].cur == 0 && lbl_14_bss_8 >= 30.0 + lbl_14_bss_40 && lbl_14_bss_F0 <= 0 &&
        lbl_14_bss_50 <= 0 && lbl_14_bss_F4 <= 0 && lbl_14_bss_F8 <= 0 && lbl_14_bss_0 > 120) {
        lbl_14_bss_0 = 120;
    }
    if (lbl_14_bss_4 != 0 || lbl_14_bss_0 <= 0) {
        if (lbl_14_bss_4C != 0) {
            lbl_1_bss_96A = 0xAE;
        } else {
            fn_14_1090_Result result;
            result.unk_4 = 0;
            result.unk_0 = 0;
            if (lbl_1_bss_7180C != 0 && fn_1_B7F58(&result) != 0) {
                lbl_1_bss_96A = 0xB0;
                lbl_1_bss_6EAB4 |= 0x28;
            } else if (fn_14_DF70() == 0) {
                lbl_1_bss_96A = 0xB2;
                lbl_1_bss_6EAB4 |= 0x28;
            } else {
                lbl_1_bss_96A = 0xAF;
                lbl_1_bss_6EAB4 |= 0x20;
            }
        }
    }
}
/* fzgx:end fn_14_1090 */

/* fzgx:begin fn_14_258C */
s32 lbl_14_bss_10C = 0;

// fn_14_258C: empty in retail (single blr).

void fn_14_258C(void) {
}
/* fzgx:end fn_14_258C */

/* fzgx:begin fn_14_2590 */
/* narrower than archive.c's definitions (s32 fn_1_128B00, u32 fn_14_DC2C): retail passes and compares the
 * results without re-extending them, so they are declared as the values they hold */

/* fills lbl_14_bss_110's eight entries from .data 0x2AB4: each flag-8 entry gets a random id of its category
 * (fn_1_14D5CC) not among the three fn_1_128B60 returned for it, each flag-0x10 entry a random fn_1_14D670 id;
 * then sets a random stock colour (0-3) on the current garage record (fn_1_12B4EC) and the record copy at
 * lbl_14_bss_180. The declaration order gives retail's callee-saved registers. */

void fn_14_2590(void) {
    s16 m;
    u8 ids[3][3];
    s16 count10;
    s16 i;
    s16 k;
    s16 j;
    u8 machine;
    u32 used[3];
    s16 count8;
    s16 n;
    fn_14_2590_Record *rec;
    u32 mask;

    mask = lbl_14_data_2F30;
    count8 = 0;
    count10 = 0;
    fn_80008BEC(used, 0, sizeof(used));
    fn_80008BEC(ids, 0, sizeof(ids));
    fn_1_128B60(&ids[0][0], &ids[0][1], &ids[0][2], &ids[1][0], &ids[1][1], &ids[1][2], &ids[2][0], &ids[2][1], &ids[2][2], &machine);
    ids[0][0] = fn_1_14F270(ids[0][0], 0, mask);
    ids[0][1] = fn_1_14F270(ids[0][1], 0, mask);
    ids[0][2] = fn_1_14F270(ids[0][2], 0, mask);
    ids[1][0] = fn_1_14F270(ids[1][0], 1, mask);
    ids[1][1] = fn_1_14F270(ids[1][1], 1, mask);
    ids[1][2] = fn_1_14F270(ids[1][2], 1, mask);
    ids[2][0] = fn_1_14F270(ids[2][0], 2, mask);
    ids[2][1] = fn_1_14F270(ids[2][1], 2, mask);
    ids[2][2] = fn_1_14F270(ids[2][2], 2, mask);

    fn_80008BEC(&lbl_14_bss_110, 0, sizeof(lbl_14_bss_110));
    fn_80008BA8(lbl_14_bss_110.unk_8, lbl_14_data_2AB4, sizeof(lbl_14_bss_110.unk_8));
    for (k = 0; k < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0]); k++) {
        if (lbl_14_bss_110.unk_8[k].unk_4 & 8) {
            count8++;
        }
        if (lbl_14_bss_110.unk_8[k].unk_4 & 0x10) {
            count10++;
        }
    }
    lbl_14_bss_110.unk_6 = 1;
    lbl_14_bss_110.unk_0 |= 0x80000000;
    lbl_14_bss_160 = count8 / 3;
    lbl_14_bss_162 = count10;
    lbl_14_bss_164 = lbl_14_bss_160 + 1;
    lbl_14_bss_166 = lbl_14_bss_162 + 1;

    k = 0;
    for (i = 0; i < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0]); i++) {
        if (lbl_14_bss_110.unk_8[i].unk_4 & 8) {
            do {
                lbl_14_bss_110.unk_8[i].unk_0 = fn_1_14D5CC(k, mask, 0x10000000);
            } while (lbl_14_bss_110.unk_8[i].unk_0 == ids[k][0] ||
                     lbl_14_bss_110.unk_8[i].unk_0 == ids[k][1] ||
                     lbl_14_bss_110.unk_8[i].unk_0 == ids[k][2] ||
                     lbl_14_bss_110.unk_8[i].unk_0 == fn_1_14F270(fn_1_128B00(k), k, mask) ||
                     (used[k] & (1 << fn_1_14F19C(lbl_14_bss_110.unk_8[i].unk_0, k, mask))));
            used[k] |= 1 << fn_1_14F19C(lbl_14_bss_110.unk_8[i].unk_0, k, mask);
            if (lbl_14_bss_110.unk_8[i].unk_4 & 0x20) {
                k++;
            }
        }
        if (lbl_14_bss_110.unk_8[i].unk_4 & 0x10) {
            do {
                lbl_14_bss_110.unk_8[i].unk_0 = fn_1_14D670();
            } while (lbl_14_bss_110.unk_8[i].unk_0 == fn_1_128B00(3) ||
                     lbl_14_bss_110.unk_8[i].unk_0 == machine);
        }
    }

    ids[0][0] = lbl_14_bss_110.unk_8[1].unk_0;
    ids[0][1] = lbl_14_bss_110.unk_8[2].unk_0;
    ids[1][0] = lbl_14_bss_110.unk_8[3].unk_0;
    ids[1][1] = lbl_14_bss_110.unk_8[4].unk_0;
    ids[2][0] = lbl_14_bss_110.unk_8[5].unk_0;
    ids[2][1] = lbl_14_bss_110.unk_8[6].unk_0;
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    n = (lbl_801A63C0 >> 16) & 3;

    rec = (fn_14_2590_Record *)fn_1_36AD0() + fn_14_DC2C();
    rec->unk_0 |= (1U << 31) | (1U << 30);
    for (k = 0; k < 3; k++) {
        rec->unk_81A4[k].unk_0 = fn_1_14F270(fn_1_128B00(k), k, mask);
    }
    fn_1_12B4EC(fn_14_DC2C(), n);

    for (k = 0; k < 3; k++) {
        for (j = 0; j < 0x19; j++) {
            if (!(fn_1_14D6D8(fn_1_14F270(j, k, mask)) & 0x80000000)) {
                continue;
            }
            if (fn_1_14D6D8(fn_1_14F270(j, k, mask)) & 0x10000000) {
                continue;
            }
            lbl_14_bss_180.unk_81A4[k].unk_0 = fn_1_14F270(j, k, mask);
            for (m = 0; m < 1; m++) {
                lbl_14_bss_180.unk_81A4[k].unk_4[m] =
                    fn_1_151BE8(lbl_14_bss_180.unk_81A4[k].unk_0, n % 4 + m);
            }
            break;
        }
    }
    lbl_14_bss_180.unk_0 |= (1U << 31) | (1U << 30);

    switch (n) {
    case 0:
        lbl_14_data_2F44 = 0x80000000;
        break;
    case 1:
        lbl_14_data_2F44 = 0x40000000;
        break;
    case 2:
        lbl_14_data_2F44 = 0x20000000;
        break;
    case 3:
        lbl_14_data_2F44 = 0x10000000;
        break;
    default:
        lbl_14_data_2F44 = 0x80000000;
        break;
    }
    fn_14_315C(0xF);
}
/* fzgx:end fn_14_2590 */

/* fzgx:begin fn_14_2AFC */
void fn_14_2AFC(void) {
    struct PilotPoint *v0;
    s32 v5;
    s16 loc_10[6];
    s16 loc_C[2];
    s16 loc_A;
    s16 loc_8;
    u8 * t9;
    fn_14_316C(loc_C, &loc_A, &loc_8);
    v0 = lbl_14_bss_8340;
    loc_C[0] = v0[loc_C[0]].part[0].id;
    loc_A = v0[loc_A].part[1].id;
    loc_8 = v0[loc_8].part[2].id;
    fn_14_342C();
    fn_14_3230(loc_C, &loc_A, &loc_8);
    if (loc_C[0] != 15) {
        loc_C[0] = lbl_14_bss_8340[loc_C[0]].part[0].id;
    }
    if (loc_A != 15) {
        loc_A = lbl_14_bss_8340[loc_A].part[1].id;
    }
    if (loc_8 != 15) {
        loc_8 = lbl_14_bss_8340[loc_8].part[2].id;
    }
    fn_14_34A8();
    loc_10[0] = 75;
    loc_10[1] = 75;
    loc_10[2] = 75;
    fn_14_32DC(loc_10);
    loc_10[0] = 75;
    loc_10[1] = 75;
    loc_10[2] = 75;
    loc_10[3] = 75;
    loc_10[4] = 75;
    loc_10[5] = 75;
    fn_14_3334(loc_10);
    loc_10[0] = 41;
    fn_14_3384(loc_10);
    loc_10[0] = 41;
    fn_14_33DC(loc_10);
    v5 = (fn_14_DC2C() & 0xFF) * (0x10000 - 32320);
    t9 = (fn_1_36AD0());
    *(u32 *)((u8 *)t9 + v5) = (*(u32 *)((u8 *)t9 + v5) | 0xC0000000); /* fzgx-allow: A1 bit-set mask, not an address */
}
/* fzgx:end fn_14_2AFC */

/* fzgx:begin fn_14_2C80 */
/* narrower than archive.c's s32 definition: retail passes the result on without re-extending it */

/* sets up what fn_14_80B4 tears down: five fn_1_4630 blocks (pilotpoint.c lines 0x888-0x88D) sized by the
 * lbl_14_bss_160 counts, the slot table fn_1_14D8DC reads, and the elements at lbl_14_bss_8354 and *lbl_14_bss_8350
 * for each machine id (fn_1_12C930 gives its pilot's picture), each with a "RobExec" task (task_add, fn_1_3F8C).
 * The lbl_14_bss_8354 loop moves elem on by j + 1 elements per pass, as retail's accumulating add does. */

void fn_14_2C80(void) {
    s16 np;
    u32 mask;
    u32 word;
    s16 machine;
    s16 i;
    s16 j;
    s16 col;
    s16 n;
    s16 machines[2];
    fn_14_2C80_Slot slots[3];
    fn_14_2C80_Elem *elem;

    mask = lbl_14_data_2F30;
    lbl_14_bss_8340 = fn_1_4630(lbl_801A6410.unk_0, lbl_14_bss_164 * 0xA20, "pilotpoint.c", 0x888);
    lbl_14_bss_8344 = fn_1_4630(lbl_801A6410.unk_0, lbl_14_bss_164 * 0xA20, "pilotpoint.c", 0x889);
    lbl_14_bss_8348 = fn_1_4630(lbl_801A6410.unk_0, lbl_14_bss_160 * 0x12C, "pilotpoint.c", 0x88A);
    lbl_14_bss_834C = fn_1_4630(lbl_801A6410.unk_0, lbl_14_bss_162 * 0x64, "pilotpoint.c", 0x88B);
    lbl_14_bss_8350 = fn_1_4630(lbl_801A6410.unk_0, lbl_14_bss_162 * 0xEA0, "pilotpoint.c", 0x88D);

    word = lbl_14_data_2F38;
    for (j = 0; j < 3; j++) {
        slots[0].unk_0[j] = fn_1_14F270(fn_1_128B00(j), j, mask);
    }
    slots[0].unk_8 = word;
    machine = fn_1_128B00(j);

    np = 0;
    j = 1;
    col = 0;
    for (i = 0; i < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0]); i++) {
        if (lbl_14_bss_110.unk_8[i].unk_4 & 8) {
            slots[j].unk_0[col] = lbl_14_bss_110.unk_8[i].unk_0;
            slots[j].unk_8 = word;
            if (lbl_14_bss_110.unk_8[i].unk_4 & 0x20) {
                j = 1;
                col++;
            } else {
                j++;
            }
        }
        if (lbl_14_bss_110.unk_8[i].unk_4 & 0x10) {
            machines[np] = lbl_14_bss_110.unk_8[i].unk_0;
            np++;
        }
    }
    fn_1_14D8DC(slots, lbl_14_bss_8340, lbl_14_bss_164);
    fn_1_14D8DC(slots, lbl_14_bss_8344, lbl_14_bss_164);

    {
        char name[8] = "CAR_SEL";

        elem = lbl_14_bss_8354;
        n = 0;
        fn_1_8F198(elem, fn_1_12C930(machine), lbl_14_data_2F40, lbl_14_data_2F44);
        fn_1_435C(lbl_14_bss_1C);
        lbl_14_data_2F4C[n++] = fn_1_3F8C("RobExec", fn_1_8F62C, elem, 8);
        fn_1_933D8(elem, elem->unk_148, fn_1_41488(elem->unk_150->unk_24, name));
        for (j = 0; j < fn_1_12CB04(machine); j++) {
            elem = &elem[j] + 1;
            fn_1_8F198(elem, fn_1_12CCB0(machine, j), lbl_14_data_2F40, lbl_14_data_2F44);
            fn_1_435C(lbl_14_bss_1C);
            lbl_14_data_2F4C[n++] = fn_1_3F8C("RobExec", fn_1_8F62C, elem, 8);
            fn_1_933D8(elem, elem->unk_148, fn_1_41488(elem->unk_150->unk_24, name));
        }
        for (i = 0; i < lbl_14_bss_162; i++) {
            elem = lbl_14_bss_8350[i].unk_0;
            fn_1_8F198(elem, fn_1_12C930(machines[i]), lbl_14_data_2F40, lbl_14_data_2F44);
            fn_1_435C(lbl_14_bss_1C);
            lbl_14_data_2F4C[n++] = fn_1_3F8C("RobExec", fn_1_8F62C, elem, 8);
            fn_1_933D8(elem, elem->unk_148, fn_1_41488(elem->unk_150->unk_24, name));
            for (j = 0; j < fn_1_12CB04(machines[i]); j++) {
                elem = &lbl_14_bss_8350[i].unk_0[j] + 1;
                fn_1_8F198(elem, fn_1_12CCB0(machines[i], j), lbl_14_data_2F40, lbl_14_data_2F44);
                fn_1_435C(lbl_14_bss_1C);
                lbl_14_data_2F4C[n++] = fn_1_3F8C("RobExec", fn_1_8F62C, elem, 8);
                fn_1_933D8(elem, elem->unk_148, fn_1_41488(elem->unk_150->unk_24, name));
            }
        }
    }

    fn_1_12BF7C(lbl_14_bss_8348, lbl_14_bss_160 * 3, (fn_1_A5D88() >> 2) & 0x3FFF, 0x78);
    fn_1_12BF7C(lbl_14_bss_834C, lbl_14_bss_162, (fn_1_A5D88() >> 2) & 0x3FFF, 0x78);
    fn_1_12BF7C(lbl_14_bss_91F4, 1, fn_1_A5D88(), 0x1E0);
    fn_1_12BF7C(lbl_14_bss_9258, 1, (fn_1_A5D88() >> 1) & 0x7FFF, 0xF0);
}
/* fzgx:end fn_14_2C80 */

/* fzgx:begin fn_14_315C */
void fn_14_315C(u32 arg0) {
    lbl_14_bss_110.unk_4C = arg0;
}
/* fzgx:end fn_14_315C */

/* fzgx:begin fn_14_316C */
/* WARNING: compiler-diff device, not original code (opt_common_subs off: retail register order of the entry pointer) */
#pragma opt_common_subs off
void fn_14_316C(s16 *arg0, s16 *arg1, s16 *arg2) {
    s16 v8;
    s16 v5;
    s16 t;
    u32 flags;
    s16 i;
    s32 v1;
    s16 v0;

    v1 = 0;
    v0 = lbl_14_bss_110.unk_4;
    i = 0;
    *arg2 = 0;
    *arg1 = 0;
    *arg0 = 0;

    while (i < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0])) {
        flags = lbl_14_bss_110.unk_8[i].unk_4;
        if ((flags & 0x8) != 0) {
            if ((flags & 0x40) != 0 || i == v0) {
                t = v1;
                v8 = t / lbl_14_bss_160;
                v5 = t % lbl_14_bss_160 + 1;
                switch (v8) {
                case 0:
                    *arg0 = v5;
                    break;
                case 1:
                    *arg1 = v5;
                    break;
                case 2:
                    *arg2 = v5;
                    break;
                }
            }
            v1++;
        }
        i++;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_14_316C */

/* fzgx:begin fn_14_3230 */
void fn_14_3230(s16 *arg0, s16 *arg1, s16 *arg2) {
    s16 count;
    s16 index;

    index = 0;
    count = 0;

    *arg2 = 15;
    *arg1 = 15;
    *arg0 = 15;

    while (count < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0])) {
        if ((lbl_14_bss_110.unk_8[count].unk_4 & 0x8) && (lbl_14_bss_110.unk_8[count].unk_4 & 0x40)) {
            s16 quotient = index / lbl_14_bss_160;
            switch (quotient) {
            case 0:
                *arg0 = 0;
                break;
            case 1:
                *arg1 = 0;
                break;
            case 2:
                *arg2 = 0;
                break;
            }
        }
        index++, count++;
    }
}
/* fzgx:end fn_14_3230 */

/* fzgx:begin fn_14_32DC */
s16 fn_14_32DC(s16 *out) {
    s16 i;
    s16 count;

    count = 0;
    i = 0;
    while (i < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0])) {
        if ((lbl_14_bss_110.unk_8[i].unk_4 & 0x8) && (lbl_14_bss_110.unk_8[i].unk_4 & 0x40)) {
            out[count++] = lbl_14_bss_110.unk_8[i].unk_0;
        }
        i++;
    }
    return count;
}
/* fzgx:end fn_14_32DC */

/* fzgx:begin fn_14_3334 */
s16 fn_14_3334(s16 *out) {
    s16 i;
    s16 count;

    count = 0;
    i = 0;
    while (i < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0])) {
        if (lbl_14_bss_110.unk_8[i].unk_4 & 0x8) {
            out[count++] = lbl_14_bss_110.unk_8[i].unk_0;
        }
        i++;
    }
    return count;
}
/* fzgx:end fn_14_3334 */

/* fzgx:begin fn_14_3384 */
s16 fn_14_3384(s16 *out) {
    s16 i;
    s16 count;
    u32 flags;

    count = 0;
    i = 0;
    while (i < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0])) {
        flags = lbl_14_bss_110.unk_8[i].unk_4;
        if ((flags & 0x10) && (flags & 0x40)) {
            out[count++] = lbl_14_bss_110.unk_8[i].unk_0;
        }
        i++;
    }
    return count;
}
/* fzgx:end fn_14_3384 */

/* fzgx:begin fn_14_33DC */
s16 fn_14_33DC(s16 *out) {
    s16 i;
    s16 count;

    count = 0;
    i = 0;
    while (i < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0])) {
        if (lbl_14_bss_110.unk_8[i].unk_4 & 0x10) {
            out[count++] = lbl_14_bss_110.unk_8[i].unk_0;
        }
        i++;
    }
    return count;
}
/* fzgx:end fn_14_33DC */

/* fzgx:begin fn_14_342C */
fn_14_2C80_Elem *fn_14_342C(void) {
    fn_14_2C80_Elem *result;
    u32 flags;
    s16 i;
    s16 count;
    s16 target;

    target = lbl_14_bss_110.unk_4;
    result = lbl_14_bss_8354;
    count = 0;

    for (i = 0; i < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0]); i++) {
        flags = lbl_14_bss_110.unk_8[i].unk_4;
        if (flags & 0x10) {
            if ((flags & 0x40) || i == target) {
                result = &lbl_14_bss_8350->unk_0[count];
                break;
            }
            count++;
        }
    }
    return result;
}
/* fzgx:end fn_14_342C */

/* fzgx:begin fn_14_34A8 */
fn_14_2C80_Elem *fn_14_34A8(void) {
    fn_14_2C80_Elem *result;
    u32 flags;
    s16 i;

    result = lbl_14_bss_8350->unk_0;
    i = 0;
    while (i < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0])) {
        flags = lbl_14_bss_110.unk_8[i].unk_4;
        if ((flags & 0x10) && (flags & 0x40)) {
            result = lbl_14_bss_8354;
            break;
        }
        i++;
    }
    return result;
}
/* fzgx:end fn_14_34A8 */

/* fzgx:begin fn_14_34FC */
static inline s32 wrap34(s32 i, s32 min, s32 max) {
    return i > max ? min : i < min ? max : i;
}

static inline s32 available34(u32 flags) {
    s16 price;
    if (flags & 4) return 1;
    if (flags & 8) price = 15000;
    else if (flags & 16) price = 20000;
    else price = -1;
    if (price > 99900) return 0;
    return 1;
}

u32 fn_14_34FC(void) {
    fn_14_2590_Obj110 *sel;
    f32 v0;
    f32 v1;
    s16 direction;
    s16 horizontal;
    s16 old;
    s16 candidate;
    s16 count;
    s16 i;
    s16 parent;
    u32 result;
    f64 v3;

    sel = &lbl_14_bss_110;
    v0 = lbl_14_bss_92BC;
    v1 = (v0 - 10.0f) / 20.0f;
    result = 0;
    direction = 0;
    horizontal = 0;
    old = sel->unk_4;
    if (lbl_14_bss_92C0 == 1) {
        if (((lbl_1_bss_9F8[0].unk_8 >> 8) & 1) || lbl_14_bss_92BC > 300) {
            fn_1_A2D84(0xA9010100);
            lbl_14_bss_92C0 = 0;
            lbl_14_bss_92BC = 0;
        }
        return 0;
    }
    v3 = __fabs(v1);
    if (v3 <= 1.0 && v3 >= 0.0) return 0;
    if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 1) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 1)) direction = 1;
    if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 0) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 0)) direction--;
    if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 3) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 3)) horizontal = -1;
    if (PAD_BIT(lbl_1_bss_9F8[0].unk_10, 2) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 2)) horizontal++;
    sel->unk_4 = wrap34(sel->unk_4 + direction, 0, 7);
    while ((lbl_14_bss_110.unk_8[sel->unk_4].unk_4 & 1) || !available34(lbl_14_bss_110.unk_8[sel->unk_4].unk_4)) {
        if (!direction) direction = 1;
        sel->unk_4 = wrap34(sel->unk_4 + direction, 0, 7);
    }
    lbl_14_bss_110.unk_0 = (lbl_14_bss_110.unk_8[lbl_14_bss_110.unk_4].unk_4 & 4) ? (lbl_14_bss_110.unk_0 | 0x80000000) : (lbl_14_bss_110.unk_0 & 0x7FFFFFFF);
    if (lbl_14_bss_110.unk_0 & 0x80000000) {
        if (horizontal < 0) {
            candidate = lbl_14_bss_110.unk_6;
            count = 0;
            while ((lbl_14_bss_110.unk_8[candidate].unk_4 & 1) || !available34(lbl_14_bss_110.unk_8[candidate].unk_4)) {
                candidate = wrap34(candidate + 1, 1, 7);
                if (count > 10) { candidate = 0; break; }
                count++;
            }
            sel->unk_4 = candidate;
        }
    } else if (horizontal > 0) {
        lbl_14_bss_110.unk_6 = sel->unk_4;
        sel->unk_4 = 0;
    }
    lbl_14_bss_110.unk_0 = (lbl_14_bss_110.unk_8[sel->unk_4].unk_4 & 4) ? (lbl_14_bss_110.unk_0 | 0x80000000) : (lbl_14_bss_110.unk_0 & 0x7FFFFFFF);
    if (sel->unk_4 != old) fn_1_A2D84(0xA9010000);
    if ((lbl_1_bss_9F8[0].unk_8 >> 8) & 1) {
        parent = sel->unk_4;
        if (lbl_14_bss_110.unk_8[parent].unk_4 & 4) {
            result = 1;
            fn_1_A2D84(0xA9010200);
        } else if (available34(lbl_14_bss_110.unk_8[parent].unk_4) == 1) {
            lbl_14_bss_110.unk_8[parent].unk_4 |= 0x40;
            while (lbl_14_bss_110.unk_8[parent].unk_4 & 2) parent--;
            lbl_14_bss_110.unk_8[parent].unk_4 |= 1;
            lbl_14_bss_110.unk_48 = lbl_801A66A0;
            lbl_14_bss_110.unk_0 &= ~0x60000000;
            if (lbl_14_bss_110.unk_8[sel->unk_4].unk_4 & 8) {
                lbl_14_bss_110.unk_0 |= 0x40000000;
                fn_1_A2D84(0xA9110400);
            }
            if (lbl_14_bss_110.unk_8[sel->unk_4].unk_4 & 16) {
                lbl_14_bss_110.unk_0 |= 0x20000000;
                fn_1_A514C(lbl_14_bss_110.unk_8[sel->unk_4].unk_0);
            }
        }
    }
    for (i = 0; i < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0]); i++) {
        if (!(lbl_14_bss_110.unk_8[i].unk_4 & 1)) {
            parent = i;
            while (lbl_14_bss_110.unk_8[parent].unk_4 & 2) parent--;
            if (lbl_14_bss_110.unk_8[parent].unk_4 & 1) lbl_14_bss_110.unk_8[i].unk_4 |= 1;
        }
    }
    return result;
}
/* fzgx:end fn_14_34FC */

/* fzgx:begin fn_14_3AE8 */
s32 fn_14_3AE8(s16 *arg0) {
    PPVec *eye;
    s16 slot;
    s16 kind;
    PPVec *at;
    PPLight light;
    PPVec rot;
    s32 v;
    s32 q;
    f32 sc;
    f32 m0;
    f32 m1;
    u32 ang;

    v = *arg0;
    q = v / lbl_14_bss_160;
    kind = q;
    slot = v - q * lbl_14_bss_160 + 1;

    eye = &lbl_14_bss_92C4.unk_4;
    fn_80008BEC(eye, 0, sizeof(PPVec));
    at = &lbl_14_bss_92C4.unk_10;
    fn_80008BEC(at, 0, sizeof(PPVec));

    if (kind == 0) {
        PPVec pos = {0.0f, 5.4117646f, -3.2470589f};
        fn_80008BA8(eye, &pos, sizeof(PPVec));
    } else {
        PPVec pos = {0.0f, 5.0f, -3.0f};
        fn_80008BA8(eye, &pos, sizeof(PPVec));
    }
    {
        PPVec target = {0.0f, 0.0f, 0.0f};
        fn_80008BA8(at, &target, sizeof(PPVec));
    }
    fn_8006F038(eye, at, 0);
    lbl_8006DCDC();

    sc = 0.7f;
    light = lbl_1_data_1E5C0;
    m0 = lbl_1_data_1E5C0.unk_C * sc;
    m1 = lbl_1_data_1E5C0.unk_10 * sc;
    light.unk_C = m0 - m1;
    light.unk_10 = m0 + m1;
    light.unk_14 = lbl_1_data_1E5C0.unk_14;
    fn_1_F7870(&light);
    fn_1_151BDC(&lbl_14_bss_180);
    lbl_8006DCA4();
    mathutil_mtxA_rotate_x(0x2000);
    ang = lbl_801A66A0 % 360;
    mathutil_mtxA_rotate_y(182.04445f * ang);
    {
        static const PPVec zero = {0.0f, 0.0f, 0.0f};
        u32 zc = 0;
        u32 z8 = 0;

        rot = zero;

        switch (kind) {
        case 0:
            fn_1_14DE80(&lbl_14_bss_8344[slot], &zc, &z8, lbl_14_data_2F36, 1.0f);
            break;
        case 1:
            fn_1_14E054(&lbl_14_bss_8344[slot], &rot, lbl_14_data_2F36, 1.0f);
            break;
        case 2:
            fn_1_14E198(&lbl_14_bss_8344[slot], &rot, lbl_14_data_2F36, 1.0f);
            break;
        }
    }
    return 0;
}
/* fzgx:end fn_14_3AE8 */

/* fzgx:begin fn_14_3DF0 */
s32 fn_14_3DF0(s16 *arg0) {
    fn_14_2C80_Elem *obj;
    s16 id;
    s32 off;
    s16 i;
    PPLight light;
    f32 sc;
    f32 m0;
    f32 m1;

    obj = lbl_14_bss_8350[*arg0].unk_0;
    id = fn_1_12C710(obj->unk_88);
    lbl_14_bss_92C4.unk_4.x = 0.55 * -lbl_8006D188(0xEEE);
    lbl_14_bss_92C4.unk_4.y = 0.83f;
    lbl_14_bss_92C4.unk_4.z = 0.55 * -lbl_8006D188(0x4EEE);
    lbl_14_bss_92C4.unk_10.x = 0.0f;
    if (id == 10) {
        lbl_14_bss_92C4.unk_10.x = 0.06666667f;
    }
    lbl_14_bss_92C4.unk_10.y = 0.83f;
    lbl_14_bss_92C4.unk_10.z = 0.0f;
    fn_8006F038(&lbl_14_bss_92C4.unk_4, &lbl_14_bss_92C4.unk_10, 0);
    lbl_8006DCDC();

    sc = 0.7f;
    light = lbl_1_data_1E5C0;
    m0 = lbl_1_data_1E5C0.unk_C * sc;
    m1 = lbl_1_data_1E5C0.unk_10 * sc;
    light.unk_C = m0 - m1;
    light.unk_10 = m0 + m1;
    light.unk_14 = lbl_1_data_1E5C0.unk_14;
    fn_1_F7870(&light);
    lbl_8006DCA4();

    obj->unk_A8 = 0.0f;
    obj->unk_AC = 0.0f;
    obj->unk_B0 = 0.0f;
    fn_1_9250C(obj);
    for (i = 0, off = 0; i < fn_1_12CB04(id); i++) {
        obj = (fn_14_2C80_Elem *)((u8 *)obj + off + sizeof(*obj));
        obj->unk_A8 = 0.0f;
        obj->unk_AC = 0.0f;
        obj->unk_B0 = 0.0f;
        fn_1_9250C(obj);
        off += sizeof(*obj);
    }
    return 0;
}
/* fzgx:end fn_14_3DF0 */

/* fzgx:begin fn_14_4008 */
s32 fn_14_4008(void) {
    PPLight *camera;
    PPLight light;
    f32 y;
    f32 x;
    f32 scale;
    s32 sel0;
    s32 sel1;
    /* WARNING: compiler-diff device, not original code (one-member carriers: retail copies the loop index from the zero count) */
    struct { s16 value; } selected;
    struct { s16 value; } i;
    struct { s16 value; } count;
    s16 a;
    s16 b;
    s16 c;
    s16 q;
    s16 r;

    fn_80008BEC(&lbl_14_bss_92C4.unk_4, 0, sizeof(PPVec));
    fn_80008BEC(&lbl_14_bss_92C4.unk_10, 0, sizeof(PPVec));
    {
        PPVec eye = {0.0f, 10.0f, -5.0f};
        fn_80008BA8(&lbl_14_bss_92C4.unk_4, &eye, sizeof(PPVec));
    }
    {
        PPVec at = {0.0f, 0.0f, 0.0f};
        fn_80008BA8(&lbl_14_bss_92C4.unk_10, &at, sizeof(PPVec));
    }
    fn_8006F038(&lbl_14_bss_92C4.unk_4, &lbl_14_bss_92C4.unk_10, 0);
    lbl_8006DCDC();

    camera = &lbl_1_data_1E5C0;
    scale = 0.7f;
    x = camera->unk_C * scale;
    y = camera->unk_10 * scale;
    light = *camera;
    light.unk_C = x - y;
    light.unk_10 = x + y;
    light.unk_14 = camera->unk_14;
    fn_1_F7870(&light);

    lbl_8006DCA4();
    mathutil_mtxA_rotate_x(0x2000);
    mathutil_mtxA_rotate_y(182.04445f * (lbl_801A66A0 % 360));

    sel0 = 0;
    sel1 = 0;
    selected.value = lbl_14_bss_110.unk_4;
    count.value = 0;
    c = 0;
    b = 0;
    a = 0;
    for (i.value = count.value; i.value < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0]); i.value++) {
        if (lbl_14_bss_110.unk_8[i.value].unk_4 & 8) {
            if ((lbl_14_bss_110.unk_8[i.value].unk_4 & 0x40) || i.value == selected.value) {
                q = count.value / lbl_14_bss_160;
                r = count.value % lbl_14_bss_160 + 1;
                switch (q) {
                case 0:
                    a = r;
                    break;
                case 1:
                    b = r;
                    break;
                case 2:
                    c = r;
                    break;
                }
            }
            count.value++;
        }
    }

    if (lbl_14_bss_8340[a].part[0].id == fn_1_14F270(fn_1_128B00(0), 0, 0x80000000)) {
        fn_1_151BDC(fn_1_36AD0() + fn_14_DC2C() * sizeof(fn_14_2590_Record));
    } else {
        fn_1_151BDC(&lbl_14_bss_180);
    }
    fn_1_14DE80(&lbl_14_bss_8340[a], &sel0, &sel1, lbl_14_data_2F36, 1.0f);
    lbl_8006DAEC();

    /* WARNING: compiler-diff device, not original code (part-array view: retail adds the part offset to the record index) */
    if (((PPPart (*)[3])lbl_14_bss_8340)[b][1].id == fn_1_14F270(fn_1_128B00(1), 1, 0x80000000)) {
        fn_1_151BDC(fn_1_36AD0() + fn_14_DC2C() * sizeof(fn_14_2590_Record));
    } else {
        fn_1_151BDC(&lbl_14_bss_180);
    }
    fn_1_14E054(&((PPPart (*)[3])lbl_14_bss_8340)[b], (void *)sel0, lbl_14_data_2F36, 1.0f);
    lbl_8006DBE4();

    if (((PPPart (*)[3])lbl_14_bss_8340)[c][2].id == fn_1_14F270(fn_1_128B00(2), 2, 0x80000000)) {
        fn_1_151BDC(fn_1_36AD0() + fn_14_DC2C() * sizeof(fn_14_2590_Record));
    } else {
        fn_1_151BDC(&lbl_14_bss_180);
    }
    fn_1_14E198(&((PPPart (*)[3])lbl_14_bss_8340)[c], (void *)sel1, lbl_14_data_2F36, 1.0f);
    lbl_8006DC20();
    return 0;
}
/* fzgx:end fn_14_4008 */

/* fzgx:begin fn_14_4460 */
/* Same search as fn_14_342C: the selected or active machine's element. */
static inline fn_14_2C80_Elem *fn_14_4460_find(void) {
    u32 flags;
    s16 i;
    s16 count = 0;
    s16 sel = lbl_14_bss_110.unk_4;
    fn_14_2C80_Elem *target = lbl_14_bss_8354;

    for (i = count; i < sizeof(lbl_14_bss_110.unk_8) / sizeof(lbl_14_bss_110.unk_8[0]); i++) {
        flags = lbl_14_bss_110.unk_8[i].unk_4;
        if (flags & 0x10) {
            if ((flags & 0x40) || i == sel) {
                return &lbl_14_bss_8350->unk_0[count];
            }
            count++;
        }
    }
    return target;
}

s32 fn_14_4460(void) {
    fn_14_2C80_Elem *obj;
    s16 id;
    s32 off;
    s16 i;
    PPLight light;
    f32 sc;
    f32 m0;
    f32 m1;

    obj = fn_14_4460_find();
    id = fn_1_12C710(obj->unk_88);
    lbl_14_bss_92C4.unk_4.x = 0.55 * -lbl_8006D188(0xEEE);
    lbl_14_bss_92C4.unk_4.y = 0.83f;
    lbl_14_bss_92C4.unk_4.z = 0.55 * -lbl_8006D188(0x4EEE);
    lbl_14_bss_92C4.unk_10.x = 0.0f;
    if (id == 10) {
        lbl_14_bss_92C4.unk_10.x = 0.06666667f;
    }
    lbl_14_bss_92C4.unk_10.y = 0.83f;
    lbl_14_bss_92C4.unk_10.z = 0.0f;
    fn_8006F038(&lbl_14_bss_92C4.unk_4, &lbl_14_bss_92C4.unk_10, 0);
    lbl_8006DCDC();

    sc = 0.7f;
    light = lbl_1_data_1E5C0;
    m0 = lbl_1_data_1E5C0.unk_C * sc;
    m1 = lbl_1_data_1E5C0.unk_10 * sc;
    light.unk_C = m0 - m1;
    light.unk_10 = m0 + m1;
    light.unk_14 = lbl_1_data_1E5C0.unk_14;
    fn_1_F7870(&light);
    lbl_8006DCA4();

    obj->unk_A8 = 0.0f;
    obj->unk_AC = 0.0f;
    obj->unk_B0 = 0.0f;
    fn_1_9250C(obj);
    for (i = 0, off = 0; i < fn_1_12CB04(id); i++) {
        obj = (fn_14_2C80_Elem *)((u8 *)obj + off + sizeof(*obj));
        obj->unk_A8 = 0.0f;
        obj->unk_AC = 0.0f;
        obj->unk_B0 = 0.0f;
        fn_1_9250C(obj);
        off += sizeof(*obj);
    }
    return 0;
}
/* fzgx:end fn_14_4460 */

/* fzgx:begin fn_14_46D4 */
void fn_14_46D4(s16 x, s16 y, s16 z, s32 mode) {
    FontDrawPacket pkt;
    PPColor white = {255, 255, 255, 255};
    PPColor magenta = {255, 0, 255, 255};

    if (mode == 0) {
        pkt = lbl_1_rodata_26F8;
        pkt.flags = 0x5;
        pkt.x = x - 52;
        pkt.y = y - 43;
        pkt.z = z;
        pkt.image = 0x8403;
        *(PPColor *)pkt.color = magenta;
        fn_1_4F734(&pkt);
        pkt = lbl_1_rodata_26F8;
        pkt.flags = 0x5;
        pkt.x = x - 52;
        pkt.y = y - 43;
        pkt.z = z - 1;
        pkt.image = 0x8402;
        *(PPColor *)pkt.color = white;
        fn_1_4F734(&pkt);
        pkt.flags = 0x80007;
        pkt.x = x + 52;
        pkt.y = y - 43;
        pkt.z = z;
        pkt.image = 0x8403;
        *(PPColor *)pkt.color = magenta;
        fn_1_4F734(&pkt);
        pkt = lbl_1_rodata_26F8;
        pkt.flags = 0x80007;
        pkt.x = x + 52;
        pkt.y = y - 43;
        pkt.z = z - 1;
        pkt.image = 0x8402;
        *(PPColor *)pkt.color = white;
        fn_1_4F734(&pkt);
        pkt = lbl_1_rodata_26F8;
        pkt.flags = 0x10000D;
        pkt.x = x - 52;
        pkt.y = y + 43;
        pkt.z = z;
        pkt.image = 0x8403;
        *(PPColor *)pkt.color = magenta;
        fn_1_4F734(&pkt);
        pkt = lbl_1_rodata_26F8;
        pkt.flags = 0x10000D;
        pkt.x = x - 52;
        pkt.y = y + 43;
        pkt.z = z - 1;
        pkt.image = 0x8402;
        *(PPColor *)pkt.color = white;
        fn_1_4F734(&pkt);
        pkt = lbl_1_rodata_26F8;
        pkt.flags = 0x18000F;
        pkt.x = x + 52;
        pkt.y = y + 43;
        pkt.z = z;
        pkt.image = 0x8403;
        *(PPColor *)pkt.color = magenta;
        fn_1_4F734(&pkt);
        pkt = lbl_1_rodata_26F8;
        pkt.flags = 0x18000F;
        pkt.x = x + 52;
        pkt.y = y + 43;
        pkt.z = z - 1;
        pkt.image = 0x8402;
        *(PPColor *)pkt.color = white;
        fn_1_4F734(&pkt);
        return;
    }
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8403;
    fn_1_51678(&pkt, pkt.image, 0, 0, 24, 20);
    pkt.flags = 0x5;
    pkt.x = x - 111;
    pkt.y = y - 27;
    pkt.z = z;
    *(PPColor *)pkt.color = magenta;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8403;
    fn_1_51678(&pkt, pkt.image, 24, 0, 8, 20);
    pkt.flags = 0x5;
    pkt.x = x - 87;
    pkt.y = y - 27;
    pkt.z = z;
    pkt.scale_x *= 9.625f;
    *(PPColor *)pkt.color = magenta;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8402;
    fn_1_51678(&pkt, pkt.image, 24, 0, 8, 20);
    pkt.flags = 0x5;
    pkt.x = x - 87;
    pkt.y = y - 27;
    pkt.z = z - 1;
    pkt.scale_x *= 9.625f;
    *(PPColor *)pkt.color = white;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8402;
    fn_1_51678(&pkt, pkt.image, 0, 0, 24, 20);
    pkt.flags = 0x5;
    pkt.x = x - 111;
    pkt.y = y - 27;
    pkt.z = z - 1;
    *(PPColor *)pkt.color = white;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8403;
    fn_1_51678(&pkt, pkt.image, 0, 0, 24, 20);
    pkt.flags = 0x80007;
    pkt.x = x + 111;
    pkt.y = y - 27;
    pkt.z = z;
    *(PPColor *)pkt.color = magenta;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8403;
    fn_1_51678(&pkt, pkt.image, 24, 0, 8, 20);
    pkt.flags = 0x80007;
    pkt.x = x + 87;
    pkt.y = y - 27;
    pkt.z = z;
    pkt.scale_x *= 9.625f;
    *(PPColor *)pkt.color = magenta;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8402;
    fn_1_51678(&pkt, pkt.image, 24, 0, 8, 20);
    pkt.flags = 0x80007;
    pkt.x = x + 87;
    pkt.y = y - 27;
    pkt.z = z - 1;
    pkt.scale_x *= 9.625f;
    *(PPColor *)pkt.color = white;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8402;
    fn_1_51678(&pkt, pkt.image, 0, 0, 24, 20);
    pkt.flags = 0x80007;
    pkt.x = x + 111;
    pkt.y = y - 27;
    pkt.z = z - 1;
    *(PPColor *)pkt.color = white;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8403;
    fn_1_51678(&pkt, pkt.image, 0, 0, 24, 20);
    pkt.flags = 0x10000D;
    pkt.x = x - 111;
    pkt.y = y + 27;
    pkt.z = z;
    *(PPColor *)pkt.color = magenta;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8403;
    fn_1_51678(&pkt, pkt.image, 24, 0, 8, 20);
    pkt.flags = 0x10000D;
    pkt.x = x - 87;
    pkt.y = y + 27;
    pkt.z = z;
    pkt.scale_x *= 9.625f;
    *(PPColor *)pkt.color = magenta;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8402;
    fn_1_51678(&pkt, pkt.image, 24, 0, 8, 20);
    pkt.flags = 0x10000D;
    pkt.x = x - 87;
    pkt.y = y + 27;
    pkt.z = z - 1;
    pkt.scale_x *= 9.625f;
    *(PPColor *)pkt.color = white;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8402;
    fn_1_51678(&pkt, pkt.image, 0, 0, 24, 20);
    pkt.flags = 0x10000D;
    pkt.x = x - 111;
    pkt.y = y + 27;
    pkt.z = z - 1;
    *(PPColor *)pkt.color = white;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8403;
    fn_1_51678(&pkt, pkt.image, 0, 0, 24, 20);
    pkt.flags = 0x18000F;
    pkt.x = x + 111;
    pkt.y = y + 27;
    pkt.z = z;
    *(PPColor *)pkt.color = magenta;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8403;
    fn_1_51678(&pkt, pkt.image, 24, 0, 8, 20);
    pkt.flags = 0x18000F;
    pkt.x = x + 87;
    pkt.y = y + 27;
    pkt.z = z;
    pkt.scale_x *= 9.625f;
    *(PPColor *)pkt.color = magenta;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8402;
    fn_1_51678(&pkt, pkt.image, 24, 0, 8, 20);
    pkt.flags = 0x18000F;
    pkt.x = x + 87;
    pkt.y = y + 27;
    pkt.z = z - 1;
    pkt.scale_x *= 9.625f;
    *(PPColor *)pkt.color = white;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8402;
    fn_1_51678(&pkt, pkt.image, 0, 0, 24, 20);
    pkt.flags = 0x18000F;
    pkt.x = x + 111;
    pkt.y = y + 27;
    pkt.z = z - 1;
    *(PPColor *)pkt.color = white;
    fn_1_4F734(&pkt);
}
/* fzgx:end fn_14_46D4 */

/* fzgx:begin fn_14_58C4 */
static inline s16 fn_14_58C4_cost(u32 flags) {
    if (flags & 8) {
        return 15000;
    } else if (flags & 16) {
        return 20000;
    }
    return -1;
}

void fn_14_58C4(s16 x, s16 y) {
    char name[0x44];
    PPMachineInfo info;
    s16 cur;
    u32 flags;

    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4955C(0.458333343f, 0.458333343f);
    fn_1_495C8(9);
    {
        fn_14_1090_Color c = {0, 255, 0, 0};
        fn_1_49514(&c);
    }
    fn_1_496FC(x + 85, y + 10);
    fn_1_4AE0C(fn_14_DC6C(3, 0));
    fn_1_496FC(x + 251, y + 10);
    fn_1_4AE0C(fn_14_DC6C(4, 0));
    fn_1_496FC(x + 417, y + 10);
    fn_1_4AE0C(fn_14_DC6C(5, 0));
    fn_1_496FC(x + 545, y + 10);
    fn_1_4AE0C(fn_14_DC6C(10, 0));
    {
        fn_14_1090_Color c = {255, 255, 255, 0};
        fn_1_49514(&c);
    }
    fn_1_496FC(x + 85, y + 91);
    fn_1_4AE0C("%dpts", fn_14_58C4_cost(lbl_14_bss_110.unk_8[1].unk_4));
    fn_1_496FC(x + 251, y + 91);
    fn_1_4AE0C("%dpts", fn_14_58C4_cost(lbl_14_bss_110.unk_8[3].unk_4));
    fn_1_496FC(x + 417, y + 91);
    fn_1_4AE0C("%dpts", fn_14_58C4_cost(lbl_14_bss_110.unk_8[5].unk_4));
    fn_1_496FC(x + 545, y + 91);
    fn_1_4AE0C("%dpts", fn_14_58C4_cost(lbl_14_bss_110.unk_8[7].unk_4));
    {
        fn_14_1090_Color c = {255, 255, 255, 0};
        fn_1_49514(&c);
    }
    fn_1_4955C(0.666666687f, 0.666666687f);
    fn_1_496FC(x + 167, y + 121);
    fn_1_4AE0C(fn_14_DC6C(12, 0));
    cur = lbl_14_bss_110.unk_4;
    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    flags = lbl_14_bss_110.unk_8[cur].unk_4;
    if (flags & 8) {

        fn_1_14E9E4(lbl_14_bss_110.unk_8[cur].unk_0, &info);
        fn_1_4955C(0.616993487f, 0.666666687f);
        fn_1_495C8(8);
        {
            fn_14_1090_Color c = {0, 255, 0, 0};
            fn_1_49514(&c);
        }
        fn_1_496FC(x + 8, y + 156);
        fn_1_4962C();
        {
            s16 kinds[3] = {6, 7, 8};
            fn_1_4AE0C(fn_14_DC6C(kinds[info.kind], 0));
        }
        fn_1_4962C();
        fn_1_496FC(x + 87, y + 156);
        fn_1_4955C(0.416666657f, 0.833333313f);
        fn_1_495C8(8);
        {
            fn_14_1090_Color c = {255, 255, 255, 0};
            fn_1_49514(&c);
        }
        fn_1_4AE0C("%s", fn_1_14EA74(lbl_14_bss_110.unk_8[cur].unk_0, name, lbl_801A66B4));
        fn_1_496FC(x + 326, y + 156);
        fn_1_4955C(0.486274511f, 0.666666687f);
        fn_1_495C8(10);
        fn_1_4AE0C("%dkg\n", (s16)info.weight);
    } else if (flags & 0x10) {
        fn_1_4955C(0.616993487f, 0.666666687f);
        fn_1_495C8(8);
        {
            fn_14_1090_Color c = {0, 255, 0, 0};
            fn_1_49514(&c);
        }
        fn_1_496FC(x + 8, y + 156);
        fn_1_4AE0C(fn_14_DC6C(10, 0));
        fn_1_496FC(x + 87, y + 156);
        fn_1_4955C(0.416666657f, 0.833333313f);
        fn_1_495C8(8);
        {
            fn_14_1090_Color c = {255, 255, 255, 0};
            fn_1_49514(&c);
        }
        switch (lbl_801A66B4) {
        case 5:
            fn_1_4AE0C("%s", lbl_1_data_21078[fn_1_12C930(lbl_14_bss_110.unk_8[cur].unk_0)]);
            break;
        case 0:
        default:
            fn_1_4AE0C("%s", lbl_1_data_212A8[fn_1_12C930(lbl_14_bss_110.unk_8[cur].unk_0)]);
            break;
        }
    }
}
/* fzgx:end fn_14_58C4 */

/* fzgx:begin fn_14_600C */
void fn_14_600C(void) {
    fn_80074188(lbl_14_bss_92E8.x, lbl_14_bss_92E8.y, lbl_14_bss_92E8.w, lbl_14_bss_92E8.h);
}
/* fzgx:end fn_14_600C */

/* fzgx:begin fn_14_6044 */
/* A pilot entry is highlighted unless its time limit (15000/20000 frames) is exceeded. */

static inline s32 fn_14_6044_visible(u32 flags) {
    s16 t;
    if (flags & 4) {
        return 1;
    }
    if (flags & 8) {
        t = 15000;
    } else if (flags & 0x10) {
        t = 20000;
    } else {
        t = -1;
    }
    if (t > 99900) {
        return 0;
    }
    return 1;
}

void fn_14_6044(s16 arg0, s16 arg1) {
    s16 cnt0;
    s16 cnt1;
    f32 scale;
    FontDrawPacket spr;
    s16 i;
    f32 savedY;
    u32 flags;

    cnt0 = 0;
    cnt1 = 0;
    scale = fn_1_A5DB0() / 480.0f;
    lbl_14_bss_92E8.x = arg0 + 0x202;
    lbl_14_bss_92E8.y = (arg1 + 16) * scale;
    lbl_14_bss_92E8.w = 62;
    lbl_14_bss_92E8.h = 62.0f * scale;
    spr = lbl_1_rodata_26F8;
    spr.flags = 10;
    spr.y = arg1 + 0x31;
    for (i = 0; (u32)i < 8; i++) {
        spr.x = arg0 + 0x2e + (s32)((u32)i - 1) * 0x4e + ((s32)((u32)i - 1) / 2) * 10;
        spr.z = 50.0f;
        spr.scale_y = 1.0f;
        spr.scale_x = 1.0f;
        if (i == lbl_14_bss_110.unk_4) {
            spr.z -= spr.scale_y;
        }
        flags = lbl_14_bss_110.unk_8[i].unk_4;
        {
            PPColor white = {255, 255, 255, 255};
            *(PPColor *)spr.color = white;
        }
        if ((flags & 1) || !fn_14_6044_visible(flags)) {
            PPColor gray = {63, 63, 63, 63};
            *(PPColor *)spr.color = gray;
        }
        if (lbl_14_bss_110.unk_8[i].unk_4 & 8) {
            savedY = spr.y;
            if (fn_1_14F344(lbl_14_bss_110.unk_8[i].unk_0) == 0) {
                spr.y += 5.0f;
            }
            if (fn_1_14F344(lbl_14_bss_110.unk_8[i].unk_0) == 1) {
                spr.y += 7.0f;
            }
            fn_1_8D3F8((u8 *)lbl_14_bss_8348 + cnt0 * 100, &spr, fn_14_3AE8, &cnt0);
            spr.y = savedY;
            cnt0++;
        }
        if (lbl_14_bss_110.unk_8[i].unk_4 & 0x10) {
            spr.x = arg0 + 0x221;
            spr.flags |= 0x4000000;
            spr.vertex_callback = (void (*)(const FontDrawPacket *, FontVertex *))fn_14_600C;
            fn_1_8D3F8((u8 *)lbl_14_bss_834C + cnt1 * 100, &spr, fn_14_3DF0, &cnt1);
            cnt1++;
        }
        if (i == lbl_14_bss_110.unk_4) {
            if (lbl_14_bss_110.unk_8[i].unk_4 & 4) {
                fn_14_46D4(arg0 + 0xa7, arg1 + 0x79, 1.0f + spr.z, 1);
            } else {
                fn_14_46D4(spr.x, spr.y, 1.0f + spr.z, 0);
            }
        }
    }
}
/* fzgx:end fn_14_6044 */

/* fzgx:begin fn_14_645C */
void fn_14_645C(void) {
    fn_80074188(lbl_14_bss_92F0.x, lbl_14_bss_92F0.y, lbl_14_bss_92F0.w, lbl_14_bss_92F0.h);
}
/* fzgx:end fn_14_645C */

/* fzgx:begin fn_14_6494 */
/* Draws the points total: the label in green, the value in white. MWCC inlines it into fn_14_7584, the only
 * caller. The link strips this out-of-line copy (strip_allow.txt); its literals and strings stay here. */
static void draw_points_total(f32 label_x, f32 value_x, f32 y, s32 points) {
    fn_1_496FC(label_x, y);
    fn_1_4955C(0.666666687f, 0.666666687f);
    fn_1_495C8(8);
    {
        fn_14_1090_Color c = {0, 255, 0, 0};
        fn_1_49514(&c);
    }
    fn_1_4AE0C(fn_14_DC6C(2, 0));
    fn_1_496FC(value_x, y);
    fn_1_4955C(0.480392188f, 0.833333313f);
    fn_1_495C8(10);
    {
        fn_14_1090_Color c = {255, 255, 255, 0};
        fn_1_49514(&c);
    }
    if (__abs(points) > 1) {
        fn_1_4AE0C("%dpts\n", points);
    } else {
        fn_1_4AE0C("%dpt\n", points);
    }
}

/* Index of the first lit entry that is either marked 0x40 or is the current
 * one; the caller does not use the result (retail keeps the loop anyway). */

static inline s16 fn_14_6494_find(void) {
    s16 i;
    s16 cur;

    cur = lbl_14_bss_110.unk_4;
    for (i = 0; i < 8U; i++) {
        if (lbl_14_bss_110.unk_8[i].unk_4 & 0x10) {
            if (lbl_14_bss_110.unk_8[i].unk_4 & 0x40) {
                break;
            }
            if (i == cur) {
                break;
            }
        }
    }
    return i;
}

static inline s32 fn_14_6494_expired(void) {
    if (lbl_14_bss_110.unk_48 == 0xFFFFFFFF) {
        return 1;
    }
    if (lbl_801A66A0 - lbl_14_bss_110.unk_48 > lbl_14_bss_110.unk_4C) {
        lbl_14_bss_110.unk_48 = 0xFFFFFFFF;
        return 1;
    }
    return 0;
}

void fn_14_6494(void) {
    FontDrawPacket s;
    f32 scale;

    s = lbl_1_rodata_26F8;
    scale = fn_1_A5DB0() / 480.0f;
    lbl_14_bss_92F0.x = 0x117;
    lbl_14_bss_92F0.w = 0x54;
    lbl_14_bss_92F0.y = 314.0f * scale;
    lbl_14_bss_92F0.h = 84.0f * scale;
    s.x = 321.0f;
    s.y = 356.0f;
    s.z = 50.0f;

    fn_14_6494_find();

    s.flags = 0x0400000A;
    s.scale_y = 0.75f;
    s.scale_x = 0.75f;
    s.vertex_callback = (void (*)(const FontDrawPacket *, FontVertex *))fn_14_645C;
    fn_1_8D3F8(lbl_14_bss_9258, &s, fn_14_4460, 0);

    {
    PPColor magenta = {0xFF, 0x00, 0xFF, 0xFF};
    PPColor c = {0xFF, 0xFF, 0xFF, 0xFF};
    s = lbl_1_rodata_26F8;
    s.image = 18;
    s.flags = 10;
    s.x = 321.0f;
    s.y = 356.0f;
    s.z = 51.0f;
    *(PPColor *)s.color = magenta;
    s.alpha = 0.3f;
    if ((lbl_14_bss_110.unk_0 & 0x20000000) && !fn_14_6494_expired()) {
        if (lbl_801A66A0 % 3 != 0) {
            *(PPColor *)s.color = c;
        }
        fn_1_50164(&s, 88.0f, 88.0f, 2.0f, 2.0f);
    } else if (lbl_14_bss_110.unk_8[lbl_14_bss_110.unk_4].unk_4 & 0x10) {
        fn_1_50164(&s, 88.0f, 88.0f, 2.0f, 2.0f);
    }
    }
}
/* fzgx:end fn_14_6494 */

/* fzgx:begin fn_14_6758 */
static inline void fn_14_6758_GetSelected(s16 *pa, s16 *pb, s16 *pc) {
    s16 quot;
    s16 slot;
    s32 div;
    u32 flags;
    s16 i;
    s16 count;
    s16 selected;

    *pa = *pb = *pc = 0;
    count = 0;
    selected = lbl_14_bss_110.unk_4;
    i = 0;

    while ((u32)i < 8) {
        flags = lbl_14_bss_110.unk_8[i].unk_4;
        if ((flags & 0x8) != 0) {
            if ((flags & 0x40) != 0 || i == selected) {
                div = count / lbl_14_bss_160;
                quot = div;
                slot = count % lbl_14_bss_160 + 1;
                switch (quot) {
                case 0:
                    *pa = slot;
                    break;
                case 1:
                    *pb = slot;
                    break;
                case 2:
                    *pc = slot;
                    break;
                }
            }
            count++;
        }
        i++;
    }
}

static inline void fn_14_6758_GetActive(s16 *pa, s16 *pb, s16 *pc) {
    s16 quot;
    s16 slot;
    s32 div;
    u32 flags;
    s16 i;
    s16 count;

    *pa = *pb = *pc = 0;
    count = 0;
    i = 0;

    while ((u32)i < 8) {
        flags = lbl_14_bss_110.unk_8[i].unk_4;
        if ((flags & 0x8) != 0) {
            if ((flags & 0x40) != 0) {
                div = count / lbl_14_bss_160;
                quot = div;
                slot = count % lbl_14_bss_160 + 1;
                switch (quot) {
                case 0:
                    *pa = slot;
                    break;
                case 1:
                    *pb = slot;
                    break;
                case 2:
                    *pc = slot;
                    break;
                }
            }
            count++;
        }
        i++;
    }
}

static inline void fn_14_6758_GetSelectedLate(s16 *pa, s16 *pb, s16 *pc) {
    s16 quot;
    s16 slot;
    s32 div;
    u32 flags;
    s16 i;
    s16 count;
    s16 selected;
    s16 a;
    s16 b;
    s16 c;

    a = b = c = 0;
    count = 0;
    selected = lbl_14_bss_110.unk_4;
    i = 0;

    while ((u32)i < 8) {
        flags = lbl_14_bss_110.unk_8[i].unk_4;
        if ((flags & 0x8) != 0) {
            if ((flags & 0x40) != 0 || i == selected) {
                div = count / lbl_14_bss_160;
                quot = div;
                slot = count % lbl_14_bss_160 + 1;
                switch (quot) {
                case 0:
                    a = slot;
                    break;
                case 1:
                    b = slot;
                    break;
                case 2:
                    c = slot;
                    break;
                }
            }
            count++;
        }
        i++;
    }
    *pa = a;
    *pb = b;
    *pc = c;
}

void fn_14_6758(s16 x, s16 y) {
    static const fn_14_1090_Color selected_color = {0xFF, 0xFF, 0x00, 0x00};
    static const fn_14_1090_Color active_color = {0xFF, 0x00, 0x00, 0x00};
    PPDisp disp;
    FontDrawPacket pkt;
    char text[0x40];
    char name[0x40];
    PPMachineInfo info0;
    PPMachineInfo info1;
    s16 weight;
    s16 a0, b0, c0;
    s16 a1, b1, c1;

    fn_14_6758_GetSelected(&a0, &b0, &c0);
    a0 = lbl_14_bss_8340[a0].part[0].id;
    b0 = lbl_14_bss_8340[b0].part[1].id;
    c0 = lbl_14_bss_8340[c0].part[2].id;

    fn_14_6758_GetActive(&a1, &b1, &c1);
    a1 = lbl_14_bss_8340[a1].part[0].id;
    b1 = lbl_14_bss_8340[b1].part[1].id;
    c1 = lbl_14_bss_8340[c1].part[2].id;

    fn_1_49410();
    fn_1_495FC();
    fn_1_496FC(x + 0x92, y + 0xB);
    fn_1_4955C(0.41666666f, 0.41666666f);
    fn_1_495C8(8);
    fn_1_49590(0.5f);
    fn_1_4AE0C("%s\n", fn_1_14FEAC(a0, b0, c0, text, lbl_801A66B4));
    fn_1_49590(1.0f);
    fn_1_4962C();
    fn_1_494DC(0x23);
    fn_1_496FC(x + 0x92, y + 0x15);
    fn_1_495C8(0);
    fn_1_4955C(0.92156863f, 1.0f);
    fn_1_4AE0C("%s\n", fn_1_14FEAC(a0, b0, c0, text, 0));
    fn_1_49644();

    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4955C(0.5f, 0.5f);

    fn_1_14E9E4(a0, &info0);
    weight = 0;
    weight += info0.weight;
    fn_1_496FC(x + 0x9E, y + 0x3E);
    fn_1_495C8(8);
    fn_1_4AE0C(fn_14_DC6C(6, 0));
    fn_1_496FC(x + 0xF2, y + 0x3E);
    fn_1_495C8(9);
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0x00, 0x00};
        fn_1_49514(&c);
    }
    fn_1_4AE0C("%s", fn_1_14EE00(info0.unk_8, text, lbl_801A66B4));
    fn_1_14E9E4(a1, &info1);
    fn_1_496FC(x + 0xDC, y + 0x3E);
    fn_1_495C8(9);
    {
        fn_14_1090_Color c = {0xFF, 0x00, 0x00, 0x00};
        fn_1_49514(&c);
    }
    fn_1_4AE0C("%s", fn_1_14EE00(info1.unk_8, text, lbl_801A66B4));
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9A0C;
    pkt.x = x + 0xE6;
    pkt.y = y + 0x3E;
    pkt.scale_x *= 0.5f;
    pkt.scale_y *= 0.5f;
    pkt.flags = 0x8000A;
    fn_1_4F734(&pkt);
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(&c);
    }

    fn_1_14E9E4(c0, &info0);
    weight += info0.weight;
    fn_1_496FC(x + 0x9E, y + 0x4F);
    fn_1_495C8(8);
    fn_1_4AE0C(fn_14_DC6C(8, 0));
    fn_1_496FC(x + 0xF2, y + 0x4F);
    fn_1_495C8(9);
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0x00, 0x00};
        fn_1_49514(&c);
    }
    fn_1_4AE0C("%s", fn_1_14EE00(info0.unk_8, text, lbl_801A66B4));
    fn_1_14E9E4(c1, &info1);
    fn_1_496FC(x + 0xDC, y + 0x4F);
    fn_1_495C8(9);
    {
        fn_14_1090_Color c = {0xFF, 0x00, 0x00, 0x00};
        fn_1_49514(&c);
    }
    fn_1_4AE0C("%s", fn_1_14EE00(info1.unk_8, text, lbl_801A66B4));
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9A0C;
    pkt.x = x + 0xE6;
    pkt.y = y + 0x4F;
    pkt.scale_x *= 0.5f;
    pkt.scale_y *= 0.5f;
    pkt.flags = 0x8000A;
    fn_1_4F734(&pkt);
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(&c);
    }

    fn_1_14E9E4(b0, &info0);
    weight += info0.weight;
    fn_1_496FC(x + 0x9E, y + 0x60);
    fn_1_495C8(8);
    fn_1_4AE0C(fn_14_DC6C(9, 0));
    fn_1_496FC(x + 0xF2, y + 0x60);
    fn_1_495C8(9);
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0x00, 0x00};
        fn_1_49514(&c);
    }
    fn_1_4AE0C("%s", fn_1_14EE00(info0.unk_8, text, lbl_801A66B4));
    fn_1_14E9E4(b1, &info1);
    fn_1_496FC(x + 0xDC, y + 0x60);
    fn_1_495C8(9);
    {
        fn_14_1090_Color c = {0xFF, 0x00, 0x00, 0x00};
        fn_1_49514(&c);
    }
    fn_1_4AE0C("%s", fn_1_14EE00(info1.unk_8, text, lbl_801A66B4));
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9A0C;
    pkt.x = x + 0xE6;
    pkt.y = y + 0x60;
    pkt.scale_x *= 0.5f;
    pkt.scale_y *= 0.5f;
    pkt.flags = 0x8000A;
    fn_1_4F734(&pkt);
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(&c);
    }

    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_495C8(1);
    fn_1_49590(0.5f);
    fn_1_496FC(x + 0xBD, y + 0x82);
    if (lbl_801A66B4 == 5) {
        fn_1_495C8(2);
        fn_1_496FC(x + 0xF8, y + 0x82);
    }
    switch (lbl_801A66B4) {
    case 0:
        fn_1_4955C(0.5f, 0.5f);
        break;
    case 5:
    default:
        fn_1_4955C(0.5f, 0.5f);
        break;
    }
    fn_1_4AE0C(fn_1_13F72C(weight, lbl_801A66B4, name));

    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_495C8(0);
    fn_1_49590(0.5f);
    fn_1_4955C(0.45882353f, 0.5f);
    fn_1_496FC(x + 0x92, y + 0x6E);
    fn_1_4AE0C(fn_14_DC6C(0xB, 0));
    fn_1_4AE0C(" ");
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0x00, 0x00};
        fn_1_49514(&c);
    }
    fn_1_49590(1.0f);
    fn_1_4AE0C("%4d", weight);
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(&c);
    }
    fn_1_4AE0C("kg");

    {
        fn_14_1090_Color active;
        fn_14_1090_Color selected;

        fn_14_6758_GetSelectedLate(&a0, &b0, &c0);
        a0 = lbl_14_bss_8340[a0].part[0].id;
        b0 = lbl_14_bss_8340[b0].part[1].id;
        c0 = lbl_14_bss_8340[c0].part[2].id;
        selected = selected_color;
        fn_1_13EF64(x + 0x4B, y + 0x4B, 10, fn_1_14F6F8(a0, b0, c0, &disp), 0x8401, &selected, 0, 0.3f);

        fn_14_6758_GetActive(&a0, &b0, &c0);
        a0 = lbl_14_bss_8340[a0].part[0].id;
        b0 = lbl_14_bss_8340[b0].part[1].id;
        c0 = lbl_14_bss_8340[c0].part[2].id;
        active = active_color;
        fn_1_13EF64(x + 0x4B, y + 0x4B, 11, fn_1_14F6F8(a0, b0, c0, &disp), 0x8401, &active, 0, 0.3f);
    }
}
/* fzgx:end fn_14_6758 */

/* fzgx:begin fn_14_7584 */
/* Draws the license card slot: the card sprite and its flashing frame (compare fn_14_6494). MWCC inlines it
 * into fn_14_7584, the only caller. The link strips this out-of-line copy (strip_allow.txt); its literals stay
 * here. */
static void draw_card(void) {
    FontDrawPacket s;

    s = lbl_1_rodata_26F8;
    s.x = 492.0f;
    s.y = 332.0f;
    s.z = 40.0f;
    s.flags = 10;
    fn_1_8D3F8(lbl_14_bss_91F4, &s, fn_14_4008, 0);

    {
    static const PPColor pink = {0xFF, 0x00, 0xFF, 0xFF};
    PPColor c = {0xFF, 0xFF, 0xFF, 0xFF};
    s = lbl_1_rodata_26F8;
    s.image = 0x8404;
    s.flags = 10;
    s.x = 492.0f;
    s.y = 322.0f;
    s.z = 41.0f;
    *(PPColor *)s.color = pink;
    s.alpha = 0.3f;
    if ((lbl_14_bss_110.unk_0 & 0x40000000) && !fn_14_6494_expired()) {
        if (lbl_801A66A0 % 3 != 0) {
            *(PPColor *)s.color = c;
        }
        fn_1_50164(&s, 238.0f, 156.0f, 8.0f, 8.0f);
    } else if (lbl_14_bss_110.unk_8[lbl_14_bss_110.unk_4].unk_4 & 8) {
        fn_1_50164(&s, 238.0f, 156.0f, 8.0f, 8.0f);
    }
    }
}

#define FN_14_7584_CLAMP01(v) ((v) < 0.0f ? 0.0f : ((v) > 1.0f ? 1.0f : (v)))

/* Per-screen-mode layout (title bar edge width, text scale) and the
 * fade-in / fade-out alphas for the title bar and the headline text. */

static inline void fn_14_7584_setup(s32 *edge, f32 *scale, f32 *barAlpha, f32 *textAlpha, f32 edgeScale) {
    s32 initial;
    f32 edgeFactor;
    s32 t;

    *scale = 1.0f;
    *edge = 470;
    switch (lbl_801A66B4) {
    case 0:
        initial = 470;
        edgeFactor = initial;
        *edge = edgeFactor * edgeScale;
        *scale *= 0.83137256f;
        break;
    }
    if (lbl_14_bss_92C0 != 0) {
        t = lbl_14_bss_92BC;
        *barAlpha = FN_14_7584_CLAMP01(t / 10.0f);
        *textAlpha = FN_14_7584_CLAMP01((t - 10.0f) / 20.0f);
    } else {
        t = lbl_14_bss_92BC;
        *barAlpha = 1.0f - FN_14_7584_CLAMP01((t - 10.0f) / 20.0f);
        *textAlpha = 1.0f - FN_14_7584_CLAMP01(t / 10.0f);
    }
}

#define FN_14_7584_MIN_SIZE(v) (8.001f > (v) ? 8.001f : (v))

/* WARNING: compiler-diff device, not original code (opt_propagation off, carried from main) */
#pragma push
#pragma opt_propagation off

void fn_14_7584(void) {
    f32 v1;
    f32 v11;
    struct { f32 value; } height; /* WARNING: compiler-diff device, not original code (one-field carrier, carried from main) */
    f32 heightMin;
    f32 width;
    f32 widthMin;
    f32 v0;
    FontDrawPacket loc_C4;
    FontDrawPacket loc_6C;
    s32 edge;

    fn_14_7584_setup(&edge, &v0, &v11, &v1, 1.2901961f);
    if (0.0f != v11) {
        loc_C4 = lbl_1_rodata_26F8;
        loc_C4.image = 0x8407;
        loc_C4.x = 320.0f;
        loc_C4.y = 240.0f;
        loc_C4.z = 0.01f;
        loc_C4.flags = 10;
        heightMin = 8.001f;
        height.value = 100.0f * v11;
        if (height.value > 8.001f) heightMin = height.value;
        width = (s16)edge * v11;
        widthMin = 8.001f;
        if (width > widthMin) widthMin = width;
        fn_1_50164(&loc_C4, widthMin, heightMin, 8.0f, 8.0f);
        loc_C4.z = 0.02f;
        loc_C4.alpha = 0.5f;
        height.value = height.value > 8.001f ? height.value : 8.001f;
        fn_1_50164(&loc_C4, width > 8.001f ? width : 8.001f, height.value, 8.0f, 8.0f);
    }
    if (0.0f != v1) {
        fn_1_49410();
        fn_1_495C8(9);
        fn_1_495B0(0x80000000);
        fn_1_4965C(2);
        fn_1_4954C(0.0001f);
        fn_1_495A0(v1);
        fn_1_4955C((16.0f * v0) / 24.0f, 0.6666666865348816f);
        fn_1_496FC(320.0f, 240.0f);
        fn_1_4AE0C(fn_14_DC6C(1, lbl_801A66B4));
    }
    fn_14_58C4(24,73);
    fn_14_6044(24,73);
    loc_C4 = lbl_1_rodata_26F8;
    loc_C4.image = 0x8406;
    loc_C4.x = 24.0f;
    loc_C4.y = 73.0f;
    loc_C4.z = 90.0f;
    fn_1_4F734(&loc_C4);
    loc_6C = lbl_1_rodata_26F8;
    loc_6C.image = 0x8407;
    loc_6C.x = 368.0f;
    loc_6C.y = 193.0f;
    loc_6C.z = 90.0f;
    fn_1_50164(&loc_6C, 248.0f, 36.0f, 8.0f, 8.0f);
    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_49590(0.5f);
    draw_points_total(376.0f, 608.0f, 211.0f, 99900);
    fn_14_6494();
    draw_card();
    fn_14_6758(20,257);
    loc_C4 = lbl_1_rodata_26F8;
    loc_C4.image = 0x8400;
    loc_C4.x = 20.0f;
    loc_C4.y = 257.0f;
    loc_C4.z = 90.0f;
    fn_1_4F734(&loc_C4);
    loc_C4 = lbl_1_rodata_26F8;
    loc_C4.image = 0x8405;
    loc_C4.x = 176.0f;
    loc_C4.y = 239.0f;
    loc_C4.z = 90.0f;
    fn_1_4F734(&loc_C4);
    loc_C4 = lbl_1_rodata_26F8;
    loc_C4.image = 0x9203;
    loc_C4.x = 167.0f;
    loc_C4.y = 38.0f;
    loc_C4.z = 90.0f;
    loc_C4.flags = 10;
    fn_1_4F734(&loc_C4);
    fn_1_1380F0(fn_14_DC6C(0, lbl_801A66B4));
    fn_1_133DBC(0);
    fn_1_134AD4();
    fn_1_13B328(0x40800000,1);
    fn_1_13D02C();
}
/* fzgx:end fn_14_7584 */

/* fzgx:begin fn_14_7E04 */
#pragma pop
void fn_14_7E04(void) {
    fn_14_2590();
    fn_14_2C80();
    fn_1_12F1E8(2400);
    fn_1_435C(lbl_14_bss_20);
    lbl_14_data_2F48 = fn_1_3F8C("pilotpoint_garage_disp", (void (*)(void *))fn_14_7584, 0, 8);
    lbl_14_bss_92F8 = -1;
    fn_1_A1588(*lbl_1_bss_6EAD0, 15);
    lbl_14_bss_92C0 = 1;
    lbl_14_bss_92BC = 0;
    fn_1_A2D84(0xA9072A00);
}
/* fzgx:end fn_14_7E04 */

/* fzgx:begin fn_14_7EAC */
void fn_14_7EAC(void) {
    s32 result;
    s32 t;
    s16 i;
    fn_14_1090_Result local;

    lbl_14_bss_92BC++;
    if (lbl_801A66C0 < 30) {
        result = 1;
    } else if (fn_1_4C10() != 0) {
        if (lbl_14_bss_10C == 0) {
            u16 flags = lbl_1_bss_9F8[lbl_1_bss_8B3A0.unk_9E].unk_8;

            if ((flags >> 8) & 1) {
                lbl_14_bss_10C = 1;
            }
        }
        result = 1;
    } else {
        fn_14_2590_Obj110 *p = &lbl_14_bss_110;

        if (p->unk_48 == -1) {
            t = 1;
        } else if (lbl_801A66A0 - p->unk_48 > p->unk_4C) {
            p->unk_48 = -1;
            t = 1;
        } else {
            t = 0;
        }
        if (t == 0) {
            result = 0;
        } else {
            result = 0;
        }
    }
    if (result == 0) {
        if (lbl_14_bss_92F8 != -1) {
            lbl_1_bss_96A = lbl_14_bss_92F8;
            lbl_14_bss_92F8 = -1;
        } else if ((s16)fn_14_34FC() != 0 || fn_1_12F228() != 0) {
            local.unk_4 = 0;
            local.unk_0 = 0;
            for (i = 0; i < 8u; i++) {
                if (lbl_14_bss_110.unk_8[i].unk_4 & 4) {
                    lbl_14_bss_110.unk_4 = i;
                    break;
                }
            }
            if (lbl_1_bss_7180C != 0 && fn_1_B7F58(&local) != 0) {
                lbl_14_bss_92F8 = 0xB0;
                lbl_1_bss_6EAB4 |= 0x2C;
            } else if ((fn_14_DF70() & 0xFF) == 0) {
                lbl_1_bss_96A = 0xB2;
            } else {
                lbl_1_bss_96A = 0xAF;
            }
            fn_1_12F1E8(0);
        }
    }
}
/* fzgx:end fn_14_7EAC */

/* fzgx:begin fn_14_80B4 */
/* the three elements at lbl_14_bss_8354, then each record at *lbl_14_bss_8350 with its sub-elements; one helper
 * for both loops (j counts the first) gives retail's register colours */

static inline void elems_free(void) {
    s16 i;
    s16 j;
    fn_14_2C80_Elem *elem;
    s16 h;

    for (j = 0; j < 3; j++) {
        fn_1_8F494(&lbl_14_bss_8354[j]);
    }
    for (i = 0; i < lbl_14_bss_162; i++) {
        elem = lbl_14_bss_8350[i].unk_0;
        h = fn_1_12C710(elem->unk_88);
        fn_1_8F494(elem);
        for (j = 0; j < fn_1_12CB04(h); j++) {
            fn_1_8F494(&lbl_14_bss_8350[i].unk_0[j] + 1);
        }
    }
}

void fn_14_80B4(void) {
    s16 i;

    if (lbl_14_data_2F48 != -1) {
        fn_1_435C(lbl_14_bss_20);
        fn_1_426C(lbl_14_data_2F48);
        lbl_14_data_2F48 = -1;
    }
    for (i = 0; i < sizeof(lbl_14_data_2F4C) / sizeof(lbl_14_data_2F4C[0]); i++) {
        if (lbl_14_data_2F4C[i] != -1) {
            fn_1_435C(lbl_14_bss_1C);
            fn_1_426C(lbl_14_data_2F4C[i]);
            lbl_14_data_2F4C[i] = -1;
        }
    }
    fn_1_14DC68(lbl_14_bss_8340, lbl_14_bss_164);
    fn_1_14DC68(lbl_14_bss_8344, lbl_14_bss_164);
    elems_free();
    fn_1_12C000(lbl_14_bss_8348, lbl_14_bss_160 * 3);
    fn_1_12C000(lbl_14_bss_834C, lbl_14_bss_162);
    fn_1_12C000(lbl_14_bss_91F4, 1);
    fn_1_12C000(lbl_14_bss_9258, 1);
    fn_1_46B4(lbl_801A6410.unk_0, (s32)lbl_14_bss_8350, "pilotpoint.c", 0x90C);
    fn_1_46B4(lbl_801A6410.unk_0, (s32)lbl_14_bss_834C, "pilotpoint.c", 0x90E);
    fn_1_46B4(lbl_801A6410.unk_0, (s32)lbl_14_bss_8348, "pilotpoint.c", 0x90F);
    fn_1_46B4(lbl_801A6410.unk_0, (s32)lbl_14_bss_8340, "pilotpoint.c", 0x910);
    fn_1_46B4(lbl_801A6410.unk_0, (s32)lbl_14_bss_8344, "pilotpoint.c", 0x911);
    fn_14_2AFC();
}
/* fzgx:end fn_14_80B4 */

/* fzgx:begin fn_14_82E4 */
void fn_14_82E4(s16 arg0, s16 arg1, s16 arg2) {
    f32 x;
    s32 n;
    struct { f32 value; } y; /* WARNING: compiler-diff device, not original code (one-field carrier, carried from main) */
    f32 t;
    s32 d;

    t = lbl_8006D188(65536.0f * (((s32)lbl_801A66A0 % 60) % 120) / 120.0f);
    n = arg2 / 60;
    fn_1_49410();
    x = 320.0f + arg0;
    y.value = 240.0f + arg1;
    fn_1_496FC(x, y.value);
    fn_1_494DC(0x17);
    fn_1_495C8(9);
    fn_1_4954C(5.0f);
    fn_1_4955C(0.7f, 0.7f);
    fn_1_4AE0C("%d", d = n / 10);
    fn_1_496FC(x, y.value);
    {
        fn_14_1090_Color c = {0x00, 0x00, 0xFA, 0x00};
        fn_1_49514(&c);
    }
    t = 0.3f + (0.4f * t);
    fn_1_495A0(t);
    fn_1_494DC(0x18);
    fn_1_495C8(9);
    fn_1_4955C(0.7f, 0.7f);
    fn_1_4954C(9.0f);
    fn_1_4AE0C("%d", d);
    fn_1_49410();
    x = 20.0f + x;
    fn_1_496FC(x, y.value);
    {
        fn_14_1090_Color c = {0xFA, 0xFA, 0xFA, 0xFF};
        fn_1_49514(&c);
    }
    fn_1_494DC(0x17);
    fn_1_495C8(9);
    fn_1_4955C(0.7f, 0.7f);
    fn_1_4954C(5.0f);
    fn_1_4AE0C("%d", d = n % 10);
    fn_1_496FC(x, y.value);
    {
        fn_14_1090_Color c = {0x00, 0x00, 0xFA, 0x00};
        fn_1_49514(&c);
    }
    fn_1_495A0(t);
    fn_1_494DC(0x18);
    fn_1_495C8(9);
    fn_1_4955C(0.7f, 0.7f);
    fn_1_4954C(9.0f);
    fn_1_4AE0C("%d", d);
}
/* fzgx:end fn_14_82E4 */

/* fzgx:begin fn_14_8600 */
/* begin game/main_rel/adxt_stop_types.h (deltawave784/windows-and-types@cf9407c75) */

static inline u8 fn_14_8600_AddGroup(s16 index, u16 type, s32 kind) {
    PPReward *p;
    u8 count = 0;
    u32 mask = 1;
    u32 highBit;
    u8 i;
    u32 bit;

    highBit = 0x80000000;
    lbl_14_bss_92FC[index].kind = type;
    lbl_14_bss_92FC[index].id = 0;
    lbl_14_bss_92FC[index].image = lbl_14_data_2F7C[kind];

    p = &lbl_14_bss_92FC[index];
    for (i = 0; mask != 0 && i < 12; i++) {
        bit = 31 - __cntlzw(mask);
        if (bit < 12) {
            p->kind = type;
            p->id = fn_1_14F270(bit, kind, 0x80000000);
            p->image = lbl_14_data_2F7C[kind];
            if (fn_1_F8334(p->id) == 0) {
                fn_1_F83F0(p->id);
                p++;
                count++;
            }
        }
        mask &= ~(highBit >> (31 - bit));
    }
    return count;
}

void fn_14_8600(void) {
    s32 n;
    u8 tick;

    fn_1_47F74(0x8D);
    fn_1_47F74(0x97);
    fn_80008BEC(lbl_14_bss_92FC, 0xFF, sizeof(lbl_14_bss_92FC));

    n = 0;
    tick = OSGetTick() % 6;
    lbl_14_bss_92FC[n].kind = 0;
    lbl_14_bss_92FC[n].id = 0x20;
    lbl_14_bss_92FC[n].image = lbl_14_data_2F64[tick];
    n += lbl_14_bss_92FC[n].image != 0x8D00;

    lbl_14_bss_92FC[(s16)n].kind = 1;
    lbl_14_bss_92FC[(s16)n].id = OSGetTick() % 10 + 0x1F;
    lbl_14_bss_92FC[(s16)n].image = lbl_14_data_2F88[lbl_14_bss_92FC[(s16)n].id - 0x1F];
    n = n + 1;

    n += fn_14_8600_AddGroup(n, 2, 0);
    n += fn_14_8600_AddGroup(n, 3, 1);
    n += fn_14_8600_AddGroup(n, 4, 2);

    lbl_14_bss_92FC[(s16)n].kind = 5;
    lbl_14_bss_92FC[(s16)n].id = 0;
    lbl_14_bss_92FC[(s16)n].image = 0x8D10;
    fn_1_F8B50();
    n = (s16)n + 1;
    lbl_14_bss_92FC[(s16)n].kind = 6;
    lbl_14_bss_92FC[(s16)n].id = 0;
    lbl_14_bss_92FC[(s16)n].image = 0x8D15;
    lbl_14_bss_92FC[(s16)n + 1].kind = 0xFFFF;
    lbl_14_bss_92FC[(s16)n + 1].id = 0xFF;
    lbl_14_bss_92FC[(s16)n + 1].image = 0xFFFF;

    fn_1_A1588(*lbl_1_bss_6EAD0, 29);

    if (lbl_801A66B4 == 5) {
        fn_1_411A4(4);
        if (lbl_1_bss_38460.unk_10 != NULL) {
            lbl_14_bss_18 = lbl_1_bss_38460.unk_10->unk_8->unk_50;
        }
    } else {
        fn_1_411A4(5);
        if (lbl_1_bss_38460.unk_14 != NULL) {
            lbl_14_bss_18 = lbl_1_bss_38460.unk_14->unk_8->unk_50;
        }
    }
}
/* fzgx:end fn_14_8600 */

/* fzgx:begin fn_14_8A54 */
extern s32 fn_1_B7E98(s32);
extern void fn_1_50A90(FontDrawPacket *, s32, s32, s32, s32);
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_A71CC(void);
extern f32 fn_1_A6FE8(void);
extern void fn_1_A7024(f32, f32, f32, f32);
extern void fn_1_56000(u8, u8, u8);
extern void lbl_8006D758(void);
extern void lbl_8006E0A4(PPVec *);
extern void lbl_8006E14C(f32);
extern void fn_80072558(void);
extern void fn_1_556B8(void *);
extern void fn_1_A722C(void);
extern s32 fn_1_F8D10(void);
extern void fn_1_F8D38(s32);
extern void fn_1_56298(f32, f32, f32, f32);
extern void fn_1_55FF0(f32);
extern char *fn_1_7F49C(s16, s16, char *);
extern char *lbl_1_data_2BD54[][6];

static f32 pp_fade = 1.0f;
static s16 pp_timer = 3720;
static f32 pp_title_fade = 0.1f;
/* Unknown retail object: .data 0x3070, 4 bytes (0.1f). No code or data in any REL refers to it. */
f32 lbl_14_data_3070 = 0.1f;
static s32 pp_first = 1;

/* Unknown retail object: .bss 0x9440, 4 bytes. No code or data in any REL refers to it. */
u32 lbl_14_bss_9440 = 0;
static u8 pp_closed = 0;
static u8 pp_skip = 0;
static s16 pp_reward = 0;
/* Unknown retail object: .bss 0x9448, 8 bytes. No code or data in any REL refers to it. */
s64 lbl_14_bss_9448 = 0;
static u8 pp_frame = 0;
s16 lbl_14_bss_9452;
s32 lbl_14_bss_9454;
#define MSG(i) lbl_14_data_27FC[i][lbl_801A66B4]
#define KIND lbl_14_bss_92FC[pp_reward].kind

static void draw_bar(f32 scale) {
    FontDrawPacket pkt;

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0xC;
    pkt.x = 320.0f;
    pkt.y = 402.0f;
    pkt.z = 10.0f;
    pkt.flags = 0xA;
    fn_1_50A90(&pkt, 7, 7, (400.0f * scale), (36.0f * scale));
}

static void draw_frame(f32 alpha, f32 y) {
    FontDrawPacket pkt;

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0xC;
    pkt.x = 320.0f;
    pkt.y = y;
    pkt.z = 10.0f;
    pkt.flags = 0xA;
    if (lbl_801A66B4 != 5) {
        fn_1_50A90(&pkt, 7, 7, (548.0f * alpha), (134.0f * alpha));
    } else {
        fn_1_50A90(&pkt, 7, 7, (586.0f * alpha), (134.0f * alpha));
    }
}

static void draw_box(s16 n) {
    FontDrawPacket pkt;

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0xC;
    pkt.x = 449.0f;
    pkt.y = 329.0f;
    pkt.z = 10.0f;
    pkt.flags = 0xA;
    fn_1_50A90(&pkt, 7, 7, (14.21f * n), (3.2f * n));
}

/* Unknown retail object: .rodata 0x314, 4 bytes (colour 00 80 80 FF). No code or data in any REL refers to it. */
const fn_14_1090_Color lbl_14_rodata_314 = {0x00, 0x80, 0x80, 0xFF};

#define FN_14_8A54_DRAW_MODEL(v, scale) \
    fn_1_A71CC(); \
    fn_1_A7024(45.0f, fn_1_A6FE8(), 0.001f, 100.0f); \
    fn_1_56000(1, 7, 1); \
    lbl_8006D758(); \
    lbl_8006E0A4(v); \
    lbl_8006E14C(scale); \
    fn_80072558(); \
    fn_1_556B8((void *)lbl_14_bss_18); \
    fn_1_56000(1, 3, 1); \
    fn_1_A722C()

void fn_14_8A54(void) {
    FontDrawPacket pkt;

    fn_1_133DBC(NULL);
    if ((pp_closed == 0 && fn_1_B7E98(1) == 0) || pp_timer < 120) {
        if ((lbl_1_bss_D58.unk_8 >> 8 & 1) && pp_timer < 3240 && pp_timer >= 120) {
            pp_timer = 119;
            pp_title_fade = 1.0f;
        }
        if (pp_timer <= 120 && pp_timer > 0) {
            if (pp_timer < 15) {
                pp_fade -= 0.06f;
            }
            draw_frame(pp_fade, 375.0f);
            if (1.0f == pp_title_fade) {
                if (1.0f == pp_fade) {
                    fn_14_82E4(-20, 180, 0);
                }
                fn_1_49410();
                fn_1_49590(0.5f);
                fn_1_495C8(9);
                fn_1_49738(fn_1_5233C);
                fn_1_49748(7.0f);
                fn_1_495B0(0x80000000);
                if (lbl_801A66B4 != 5) {
                    if (pp_fade >= 0.2f) {
                        fn_1_4955C(0.8f * pp_fade, 0.8f * pp_fade);
                        fn_1_496FC(320.0f, 370.0f);
                        fn_1_4AE0C(MSG(9));
                    }
                } else if (pp_fade >= 0.2f) {
                    fn_1_496FC(320.0f, 375.0f);
                    fn_1_4955C(0.8f * pp_fade, 0.8f * pp_fade);
                    fn_1_4AE0C(MSG(9));
                }
            }
        } else if (pp_timer > 120) {
            if (pp_title_fade < 1.0f) {
                pp_title_fade += 0.06f;
            }
            draw_frame(pp_title_fade, 375.0f);
            if (1.0f == pp_title_fade) {
                fn_14_82E4(-20, 180, pp_timer - 120);
                fn_1_49410();
                fn_1_49590(0.5f);
                if (lbl_801A66B4 == 0) {
                    fn_1_4955C(0.8f * pp_title_fade, 0.8f * pp_title_fade);
                    fn_1_496FC(320.0f, 358.0f);
                } else {
                    fn_1_496FC(320.0f, 360.0f);
                    fn_1_4955C(pp_title_fade, pp_title_fade);
                }
                fn_1_49590(0.5f);
                fn_1_49738(fn_1_5233C);
                fn_1_49748(7.0f);
                fn_1_495C8(9);
                fn_1_495B0(0x80000000);
                fn_1_4AE0C(MSG(11));
            }
        } else if (fn_14_DF70() == 0) {
            lbl_1_bss_96A = 0xB2;
        } else {
            lbl_1_bss_96A = 0xAF;
        }
        if (pp_timer > 0) {
            pp_timer--;
        }
        return;
    }

    if (pp_closed == 0) {
        draw_frame(pp_title_fade, 375.0f);
        if (pp_title_fade <= 1.0f && pp_title_fade > 0.1f) {
            pp_title_fade -= 0.06f;
        } else if (pp_title_fade <= 0.1f) {
            pp_closed = 1;
        }
    }
    if (KIND == -1 || pp_skip != 0) {
        if (pp_fade > 0.1f) {
            PPVec eye = {0.02f, -8.8f, -60.0f};
            u8 n;

            pp_fade -= 0.06f;
            n = (pp_fade - 0.1f) / 0.06f;
            draw_bar(pp_fade);
            draw_box(n);
            FN_14_8A54_DRAW_MODEL(&eye, 0.23f * pp_fade);
        } else {
            lbl_1_bss_96A = 0xB1;
        }
    }
    if (pp_closed != 0) {
        PPLight light;
        PPVec eye;

        pkt = lbl_1_rodata_26F8;
        light = lbl_1_data_1E5C0;
        eye.x = 0.02f;
        eye.y = -8.8f;
        eye.z = -60.0f;
        lbl_8006DCDC();
        {
            f32 k = 0.7f;
            light.unk_C = lbl_1_data_1E5C0.unk_C * k - lbl_1_data_1E5C0.unk_10 * k;
            light.unk_10 = lbl_1_data_1E5C0.unk_C * k + lbl_1_data_1E5C0.unk_10 * k;
            light.unk_14 = lbl_1_data_1E5C0.unk_14;
        }
        fn_1_F7870(&light);
        if (pp_frame < 10 && pp_first != 0) {
            FN_14_8A54_DRAW_MODEL(&eye, 0.03f + 0.02f * pp_frame);
            draw_box(pp_frame);
            draw_bar(0.1f + 0.09f * pp_frame);
            pp_frame++;
            return;
        }
        if (pp_frame >= 65 || (pp_frame < 45 && KIND != -1)) {
            FN_14_8A54_DRAW_MODEL(&eye, 0.23f);
        }
        if (KIND != -1) {
            pp_first = 0;
            draw_bar(1.0f);
            draw_box(10);
        }
        if (pp_frame == 10 && KIND != -1) {
            fn_1_A2D84(0xA9150200);
        }
        if (KIND != -1) {
            fn_1_496FC(383.0f, 321.0f);
            fn_1_4955C(0.6f, 0.7f);
            fn_1_495B0(0x80000000);
            fn_1_49590(0.5f);
            fn_1_4AE0C("Tickets");
        }
        if (KIND != -1) {
            fn_1_49590(1.0f);
            if (KIND != 6) {
                fn_1_496FC(381.0f, 324.0f);
                fn_1_4955C(0.55f, 0.55f);
                fn_1_4AE0C("\x81\x40%9u\n", fn_1_F8D10());
            } else {
                fn_1_496FC(381.0f, 324.0f);
                fn_1_4955C(0.55f, 0.55f);
                if (pp_frame >= 105 && pp_frame < 125) {
                    fn_1_F8D38(fn_1_F8D10() + 1);
                    fn_1_4AE0C("\x81\x40%9u\n", fn_1_F8D10());
                    fn_1_A2D84(0xA9010700);
                } else if (pp_frame >= 125) {
                    fn_1_4AE0C("\x81\x40%9u\n", fn_1_F8D10());
                } else {
                    fn_1_4AE0C("\x81\x40%9u\n", fn_1_F8D10());
                }
            }
        }
        if (KIND != -1) {
            s16 kind = KIND;

            pkt.image = lbl_14_bss_92FC[pp_reward].image;
            pkt.x = 320.0f;
            pkt.y = 140.0f;
            pkt.z = 10.0f;
            pkt.flags = 0xA;
            if (kind < 2 || kind > 4) {
                if (pp_frame < 25 && pp_frame >= 10) {
                    pkt.scale_x = pkt.scale_y = 0.1f + 0.06f * (pp_frame - 10);
                } else if (pp_frame >= 10 && pp_frame < 65) {
                    pkt.scale_x = pkt.scale_y = 1.0f;
                } else if (pp_frame < 80 && pp_frame >= 65 && kind != 6) {
                    pkt.scale_x = pkt.scale_y = 1.0f - 0.06f * (pp_frame - 65);
                }
                if (kind == 6) {
                    if (pp_frame >= 150 && pp_frame < 165) {
                        pkt.scale_x = pkt.scale_y = 1.0f - 0.06f * (pp_frame - 150);
                        fn_1_4F734(&pkt);
                    }
                    if (pp_frame >= 65 && pp_frame < 150) {
                        pkt.scale_x = pkt.scale_y = 1.0f;
                        fn_1_4F734(&pkt);
                    }
                }
                if (pp_frame < 80) {
                    fn_1_4F734(&pkt);
                }
            } else {
                s32 prev = 0;
                s32 next = 0;

                if (pp_reward > 0) {
                    prev = lbl_14_bss_92FC[pp_reward - 1].kind == KIND;
                }
                if (pp_reward < 54) {
                    next = kind == lbl_14_bss_92FC[pp_reward + 1].kind;
                }
                if (prev == 0 && next != 0) {
                    if (pp_frame < 25 && pp_frame >= 10) {
                        pkt.scale_x = pkt.scale_y = 0.1f + 0.06f * (pp_frame - 10);
                    } else {
                        pkt.scale_x = pkt.scale_y = 1.0f;
                    }
                    fn_1_4F734(&pkt);
                } else if (prev != 0 && next != 0) {
                    pkt.scale_x = pkt.scale_y = 1.0f;
                    fn_1_4F734(&pkt);
                } else if (prev != 0 && next == 0) {
                    if (pp_frame < 80 && pp_frame >= 65) {
                        pkt.scale_x = pkt.scale_y = 1.0f - 0.06f * (pp_frame - 65);
                    } else {
                        pkt.scale_x = pkt.scale_y = 1.0f;
                    }
                    if (pp_frame < 80) {
                        fn_1_4F734(&pkt);
                    }
                } else {
                    if (pp_frame < 80 && pp_frame >= 65) {
                        pkt.scale_x = pkt.scale_y = 1.0f - 0.06f * (pp_frame - 65);
                    }
                    if (pp_frame < 25 && pp_frame >= 10) {
                        pkt.scale_x = pkt.scale_y = 0.1f + 0.06f * (pp_frame - 10);
                    }
                    if (pp_frame < 80) {
                        fn_1_4F734(&pkt);
                    }
                }
            }
        }
        if (pp_frame >= 25 && pp_frame < 45) {
            s32 dir;
            f32 t;
            f32 one = 1.0f;

            dir = pp_reward % 2 == 0 ? 100 : -100;
            t = pp_frame - 25;
            pkt.image = 0x8D14;
            pkt.x = 320.0f + dir * lbl_8006D188(32768.0f * (t / 20.0f));
            pkt.y = 140.0f + 10.0f * t;
            pkt.z = 7.0f;
            pkt.rotation_z = (pp_frame - 45) << 12;
            if (pp_frame - 25 <= 10) {
                pkt.scale_x = pkt.scale_y = 0.3f + 0.07f * t * one;
                pkt.alpha = 0.3f + 0.04f * t * one;
            } else if (pp_frame - 25 <= 20 && pp_frame - 25 > 10) {
                pkt.scale_x = pkt.scale_y = one - 0.1f * (t - 10.0f) * one;
                pkt.alpha = 0.7f - 0.07f * (t - 10.0f) * one;
            }
            pkt.flags = 0xA;
            fn_1_4F734(&pkt);
        } else if (pp_frame < 65 && pp_frame >= 45) {
            pkt.image = 0x8D14;
            pkt.x = 320.0f;
            pkt.y = 340.0f;
            pkt.z = 7.0f;
            pkt.flags = 0xA;
            if (pp_frame < 65) {
                s32 k = pp_frame - 45;
                u8 c;

                pkt.scale_x = pkt.scale_y = 0.01f + 0.1f * k;
                pkt.alpha = 1.0f - 0.05f * k;
                c = 12.75f * k;
                pkt.color_add[3] = 0;
                pkt.color_add[2] = c;
                pkt.color_add[1] = c;
                pkt.color_add[0] = c;
            }
            if (pp_frame == 51) {
                fn_1_A2D84(0xA9000800);
            }
            fn_1_4F734(&pkt);
        }
        if (pp_frame >= 45 && pp_frame < 65) {
            f32 s = lbl_8006D188(32768.0f * ((s16)(pp_frame - 45) / 20.0f));

            fn_1_A71CC();
            fn_1_A7024(45.0f, fn_1_A6FE8(), 0.001f, 100.0f);
            fn_1_56000(1, 7, 1);
            lbl_8006D758();
            lbl_8006E0A4(&eye);
            lbl_8006E14C(0.23f);
            fn_80072558();
            fn_1_56298(0.5f * s, 0.5f * s, 0.5f * s, 0.0f);
            fn_1_55FF0(1.0f - 0.2f * s);
            fn_1_556B8((void *)lbl_14_bss_18);
            fn_1_56298(0.0f, 0.0f, 0.0f, 0.0f);
            fn_1_56000(1, 3, 1);
            fn_1_A722C();
        }
        if (pp_frame >= 25) {
            f32 sc = 0.2f * (pp_frame - 25);
            char buf[64];

            fn_1_495C8(9);
            if (sc >= 1.0f) {
                sc = 1.0f;
            }
            fn_1_4955C(sc, sc);
            fn_1_496FC(320.0f, 402.0f);
            switch (KIND) {
            case 0:
                fn_1_4AE0C("%s", lbl_1_data_2BD54[lbl_14_bss_92FC[pp_reward].id][lbl_801A66B4]);
                break;
            case 1:
                fn_1_4AE0C("%s", fn_1_7F49C(lbl_14_bss_92FC[pp_reward].id, lbl_801A66B4, buf));
                break;
            case 2:
            case 3:
            case 4:
                fn_1_4AE0C("%s", fn_1_14EA74(lbl_14_bss_92FC[pp_reward].id, buf, lbl_801A66B4));
                break;
            case 6:
                if (lbl_801A66B4 != 5) {
                    fn_1_4AE0C("%s", "F-ZERO Tickets");
                } else {
                    fn_1_4AE0C("%s", "\x82\x65\x81\x7C\x82\x79\x82\x64\x82\x71\x82\x6E\x83\x60\x83\x50\x83\x62\x83\x67");
                }
                break;
            case 5:
                if (lbl_801A66B4 != 5) {
                    fn_1_4AE0C("%s", "Special BGM");
                } else {
                    fn_1_4AE0C("%s", "\x83\x7E\x83\x85\x81\x5B\x83\x67\x83\x56\x83\x65\x83\x42\x82\xCC\x82\x61\x82\x66\x82\x6C");
                }
                break;
            }
        }
        if ((pp_frame == 105 && KIND != 6) || pp_frame == 225) {
            pp_frame = 10;
            pp_reward++;
        } else if (KIND != -1) {
            pp_frame++;
        }
    }
}
/* fzgx:end fn_14_8A54 */

/* fzgx:begin fn_14_A1F4 */
extern void fn_1_48140(s32);
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7C6C(u32);
extern void fn_1_F7954(void);
extern u32 fn_1_B7CE4(u32, void *);
extern u32 fn_1_AA6D8(u32, u32, void *);
extern s32 fn_1_B7CD4(void);
extern u8 lbl_1_bss_718E0;
void fn_14_A3DC(void);

typedef struct PPMemcardCfg {
    u8 enabled;
    u8 pad[3];
    u32 fn;
    void *state_ptr;
    void *table;
    u8 pad_10[0x14];
} PPMemcardCfg;

void fn_14_A1F4(void) {
    fn_1_48140(151);
    fn_1_48140(141);
    if (lbl_801A66B4 == 5) {
        fn_1_412A0(4);
    } else {
        fn_1_412A0(5);
    }
}
/* fzgx:end fn_14_A1F4 */

/* fzgx:begin fn_14_A244 */
void fn_14_A244(void) {
    fn_1_47F74(151);
    fn_1_12F1E8(4800);
    fn_1_435C(lbl_14_bss_20);
    lbl_14_bss_9452 = fn_1_3F8C("pilotpoint_memcard_disp", (void (*)(void *))fn_14_A3DC, 0, 8);
}
/* fzgx:end fn_14_A244 */

/* fzgx:begin fn_14_A2A4 */
void fn_14_A2A4(void) {
    PPMemcardCfg cfg;
    u8 state[64];

    fn_1_133DBC(0);
    if (fn_1_B7C00()) {
        return;
    }
    if (fn_1_12F228()) {
        lbl_1_bss_96A = fn_14_DF70() ? 0xaf : 0xb2;
        return;
    }
    if (fn_1_B7E98(1)) {
        if (fn_1_B7C6C(1) == 0 && lbl_14_bss_9454 == 0) {
            fn_1_F7954();
            fn_1_B7CE4(1, state);
            cfg.enabled = 1;
            cfg.state_ptr = state;
            cfg.table = &lbl_1_bss_718E0;
            cfg.fn = 0xA004;
            fn_1_AA6D8(0, 1, &cfg);
            lbl_14_bss_9454 = 1;
            return;
        }
    } else {
        lbl_14_bss_9454 = 0;
    }
    fn_1_B7CD4();
}
/* fzgx:end fn_14_A2A4 */

/* fzgx:begin fn_14_A398 */
void fn_14_A398(void) {
    fn_1_48140(151);
    fn_1_435C(lbl_14_bss_20);
    fn_1_426C(lbl_14_bss_9452);
}
/* fzgx:end fn_14_A398 */

/* fzgx:begin fn_14_A3DC */
extern s32 CARDProbeEx(s32, s32 *, s32 *);
extern s32 fn_1_B7EC4(s32);
extern s32 fn_1_B7C5C(void);

static f32 pp_card_text_fade = 1.0f;
static f32 pp_card_fade = 0.1f;
static s16 pp_card_timer = 30;
static s16 pp_card_delay = 480;
static s16 pp_card_timeout = 3600;

/* Unknown retail object: .bss 0x9458, 1 byte. No code or data in any REL refers to it. */
u8 lbl_14_bss_9458 = 0;
static u8 lbl_14_bss_9459 = 0;
static u8 lbl_14_bss_945A = 0;
static u8 lbl_14_bss_945B = 0;
static u8 lbl_14_bss_945C = 0;

/* Unknown retail object: .rodata 0x384, 4 bytes (colour FF FF FF FF). No code or data in any REL refers to it. */
const fn_14_1090_Color lbl_14_rodata_384 = {0xFF, 0xFF, 0xFF, 0xFF};

#define MSG2(i) lbl_14_data_27FC[i][lbl_801A66B4]

void fn_14_A3DC(void) {
    char *msg;
    s32 result;

    if (fn_1_B7E98(1) == 0 && lbl_14_bss_945C == 0) {
        if (pp_card_fade < 1.0f) {
            pp_card_fade += 0.1f;
        }
        lbl_14_bss_9459 = 0;
        lbl_14_bss_945B = 0;
        if ((lbl_1_bss_D58.unk_8 >> 8 & 1) && pp_card_delay == 0 && pp_card_timeout > 0) {
            pp_card_timeout = 0;
        }
        draw_frame(pp_card_text_fade, 240.0f);
        if (pp_card_text_fade >= 0.8f) {
            fn_14_82E4(-20, 48, pp_card_timeout);
        }
        if (pp_card_timeout == 0) {
            if (pp_card_timer > 15) {
                pp_card_text_fade = 1.0f;
            }
            fn_1_496FC(320.0f, 215.0f);
            fn_1_49410();
            fn_1_49590(0.5f);
            fn_1_4955C(0.8f * pp_card_text_fade, 0.8f * pp_card_text_fade);
            fn_1_49738(fn_1_5233C);
            fn_1_49748(7.0f);
            fn_1_495C8(9);
            fn_1_495B0(0x80000000);
            msg = MSG2(9);
            if (pp_card_timer > 0 && pp_card_timer < 15) {
                pp_card_text_fade -= 0.06f;
            } else if (pp_card_timer == 0) {
                fn_1_12F1E8(0);
            }
            fn_1_496FC(320.0f, 240.0f);
            fn_1_4955C(0.8f * pp_card_text_fade, 0.8f * pp_card_text_fade);
            fn_1_495C8(9);
            fn_1_49738(fn_1_5233C);
            fn_1_49748(7.0f);
            fn_1_4AE0C(msg);
            pp_card_timer--;
        } else {
            fn_1_49410();
            fn_1_496FC(320.0f, 226.0f);
            fn_1_4955C(0.8f, 0.8f);
            fn_1_49590(0.5f);
            fn_1_49738(fn_1_5233C);
            fn_1_49748(7.0f);
            fn_1_495C8(9);
            fn_1_495B0(0x80000000);
            fn_1_4AE0C(MSG2(11));
            pp_card_timeout--;
            if (pp_card_delay > 0) {
                pp_card_delay--;
            }
        }
    } else if (pp_card_timeout == 0) {
        if (pp_card_timer > 15) {
            pp_card_text_fade = 1.0f;
        }
        draw_frame(pp_card_text_fade, 240.0f);
        fn_1_496FC(320.0f, 215.0f);
        fn_1_49410();
        fn_1_4955C(0.8f * pp_card_text_fade, 0.8f * pp_card_text_fade);
        fn_1_49590(0.5f);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(7.0f);
        fn_1_495C8(9);
        fn_1_495B0(0x80000000);
        msg = MSG2(9);
        if (pp_card_timer > 0 && pp_card_timer < 15) {
            pp_card_text_fade -= 0.06f;
        } else if (pp_card_timer == 0) {
            fn_1_12F1E8(0);
        }
        fn_1_496FC(320.0f, 240.0f);
        fn_1_4955C(0.8f * pp_card_text_fade, 0.8f * pp_card_text_fade);
        fn_1_495C8(9);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(7.0f);
        fn_1_4AE0C(msg);
        pp_card_timer--;
    } else if (CARDProbeEx(1, NULL, NULL) == -2) {
        if (pp_card_fade < 1.0f) {
            pp_card_fade += 0.1f;
        }
        draw_frame(pp_card_fade, 240.0f);
        fn_14_82E4(-20, 48, pp_card_timeout);
        fn_1_49410();
        fn_1_4955C(0.8f * pp_card_fade, 0.8f * pp_card_fade);
        fn_1_495C8(9);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(7.0f);
        fn_1_49590(0.5f);
        fn_1_495B0(0x80000000);
        fn_1_496FC(320.0f, 220.0f);
        fn_1_4954C(1.0f);
        fn_1_4AE0C(MSG2(6));
        if (pp_card_timeout > 0) {
            pp_card_timeout--;
        }
    } else if (fn_1_B7EC4(1) == 0 && fn_1_B7E98(1) != 0) {
        if (pp_card_fade < 1.0f) {
            pp_card_fade += 0.1f;
        }
        draw_frame(pp_card_fade, 240.0f);
        fn_1_49410();
        fn_1_496FC(320.0f, 240.0f);
        fn_1_4955C(0.8f * pp_card_fade, 0.8f * pp_card_fade);
        fn_1_495C8(9);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(7.0f);
        fn_1_49590(0.5f);
        fn_1_495B0(0x80000000);
        fn_1_4AE0C(MSG2(12));
    } else if (fn_1_B7C00()) {
        if (pp_card_fade < 1.0f) {
            pp_card_fade += 0.1f;
        }
        draw_frame(pp_card_fade, 240.0f);
        lbl_14_bss_945A = 0;
        lbl_14_bss_945B = 1;
        fn_1_49410();
        fn_1_496FC(320.0f, 240.0f);
        fn_1_4955C(0.8f * pp_card_fade, 0.8f * pp_card_fade);
        fn_1_495C8(9);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(7.0f);
        fn_1_49590(0.5f);
        fn_1_495B0(0x80000000);
        fn_1_4AE0C(MSG2(12));
    } else if (fn_1_B7CD4()) {
        if (pp_card_timer > 15) {
            pp_card_text_fade = 1.0f;
        }
        draw_frame(pp_card_text_fade, 240.0f);
        fn_1_496FC(320.0f, 240.0f);
        fn_1_4955C(0.8f * pp_card_fade, 0.8f * pp_card_fade);
        fn_1_495C8(9);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(7.0f);
        fn_1_49590(0.5f);
        fn_1_495B0(0x80000000);
        msg = MSG2(13);
        if (pp_card_timer > 0 && pp_card_timer < 15) {
            pp_card_text_fade -= 0.06f;
        } else if (pp_card_timer == 0) {
            fn_1_12F1E8(0);
        }
        fn_1_496FC(320.0f, 240.0f);
        fn_1_4955C(0.8f * pp_card_text_fade, 0.8f * pp_card_text_fade);
        fn_1_495C8(9);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(7.0f);
        fn_1_4AE0C(msg);
        lbl_14_bss_945C = 1;
        pp_card_timer--;
    } else {
        if (pp_card_fade < 1.0f) {
            pp_card_fade += 0.1f;
        }
        if (pp_card_delay == 0) {
            if ((lbl_1_bss_D58.unk_8 >> 8 & 1) && pp_card_timeout > 0) {
                pp_card_timeout = 0;
            }
        } else {
            pp_card_delay--;
        }
        if (pp_card_timeout > 0) {
            pp_card_timeout--;
        }
        result = fn_1_B7C5C();
        if (pp_card_fade > 0.2f) {
            draw_frame(pp_card_fade, 240.0f);
            fn_14_82E4(-20, 48, pp_card_timeout);
        }
        fn_1_49410();
        fn_1_4955C(0.8f * pp_card_fade, 0.8f * pp_card_fade);
        fn_1_495C8(9);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(7.0f);
        fn_1_49590(0.5f);
        fn_1_495B0(0x80000000);
        if (fn_1_B7E98(1) == 0 && lbl_14_bss_945C != 0) {
            lbl_14_bss_945C = 0;
        }
        switch (result) {
        case -4:
            fn_1_496FC(320.0f, 227.0f);
            msg = MSG2(2);
            break;
        case -5:
            if (lbl_801A66B4 != 5) {
                fn_1_496FC(328.0f, 234.0f);
            } else {
                fn_1_496FC(320.0f, 227.0f);
            }
            msg = MSG2(5);
            break;
        case -6:
        case -124:
            if (lbl_801A66B4 != 5) {
                fn_1_496FC(332.0f, 227.0f);
            } else {
                fn_1_496FC(320.0f, 227.0f);
            }
            msg = MSG2(3);
            break;
        case -13:
            if (lbl_801A66B4 != 5) {
                fn_1_496FC(317.0f, 227.0f);
            } else {
                fn_1_496FC(320.0f, 227.0f);
            }
            msg = MSG2(4);
            break;
        case -119:
            if (lbl_801A66B4 != 5) {
                fn_1_496FC(310.0f, 234.0f);
            } else {
                fn_1_496FC(315.0f, 227.0f);
            }
            msg = MSG2(8);
            break;
        default:
            fn_1_496FC(320.0f, 227.0f);
            msg = MSG2(14);
            break;
        }
        fn_1_4AE0C(msg);
    }
}
/* fzgx:end fn_14_A3DC */

/* fzgx:begin fn_14_B398 */
typedef struct PPRecord {
    u8 unk_0;
    u8 unk_1;
    u16 unk_2;
    u8 unk_4;
    u8 pad_5[0x3];
    u8 unk_8;
    u8 pad_9[0x15];
} PPRecord;

extern u8 fn_1_128DD8(u8);
extern void fn_1_128E8C(u8, PPRecord *);
extern void fn_1_159AE0(void);
void fn_14_DC90(f32);
extern u16 fn_1_48690(u32);
extern void fn_1_53B14(u8 *, f32, f32, f32, f32, f32);
extern u8 *fn_1_15AC00(void);
/* font.c defines it as void (s32); retail compares its f1 result with 500.0f */
extern f32 fn_1_4B040(const char *);
extern u8 fn_1_15B3E8(void);
extern u8 fn_1_15B3F8(void);
extern u8 fn_1_15B408(void);
extern s16 fn_1_14F090(s16, s16);
/* sel_static_disp.c defines the 5th to 8th parameters as int and void *; retail passes them sign-extended */
extern void fn_1_1358BC(s16, s16, s32, s16, s16, s16, s16, s16, f32, f32, f32);

struct { s32 unk_0; } lbl_14_bss_9460;
PPRecord lbl_14_bss_9464;

void fn_14_B484(void);

void fn_14_B398(void) {
    lbl_14_bss_9460.unk_0 = 0;
    lbl_14_bss_0 = 480;
    fn_1_128E8C(fn_1_128DD8(lbl_1_bss_8B3A0.unk_90), &lbl_14_bss_9464);
    fn_1_159AE0();
    fn_1_A2D84(0xA9122800);
}
/* fzgx:end fn_14_B398 */

/* fzgx:begin fn_14_B400 */
void fn_14_B400(void) {
    fn_1_133DBC(NULL);
    fn_1_13DC54();
    fn_14_B484();
    fn_14_DC90(1.0f);
    if (lbl_14_bss_0 < 420 && ((lbl_1_bss_D58.unk_8 >> 8 & 1) != 0 || lbl_14_bss_0 < 0)) {
        lbl_1_bss_96A = 178;
        lbl_1_bss_6EAB4 |= 44;
    }
}
/* fzgx:end fn_14_B400 */

/* fzgx:begin fn_14_B480 */
// fn_14_B480: empty in retail (single blr).

void fn_14_B480(void) {
}
/* fzgx:end fn_14_B480 */

/* fzgx:begin fn_14_B484 */
/* draws the record password screen: eight images (0x9100-0x9106) offset by dx while lbl_14_bss_0 (480 from
 * fn_14_B398) is above 450, the "Your Record PASSWORD" / "MACHINE DATA" / "BEST TOTAL TIME" captions, the website
 * notice in Japanese when lbl_801A66B4 is 5 and in English otherwise, the string from fn_1_15AC00 (scaled down past
 * 500.0f wide), the time in lbl_14_bss_9464 as minutes'seconds"milliseconds, and fn_1_1358BC with the part ids
 * fn_1_14F090 gives */
void fn_14_B484(void) {
    f32 dx;
    f32 wave;
    f32 w;
    f32 y;
    u32 cup;
    s32 cell;
    s32 v;
    u32 ms;
    s32 i;
    FontDrawPacket pkt;

    if (lbl_14_bss_0 > 450) {
        dx = 0.03333333507180214f * (640.0f * (30 - (480 - lbl_14_bss_0)));
    } else {
        dx = 0.0f;
    }
    cup = fn_1_128DD8(lbl_1_bss_8B3A0.unk_90);
    ms = lbl_14_bss_9464.unk_1 * 1000 + lbl_14_bss_9464.unk_0 * 60000 + lbl_14_bss_9464.unk_2;
    cell = lbl_14_bss_9464.unk_4;
    v = lbl_14_bss_9464.unk_8;
    wave = 0.15f * lbl_8006D188(lbl_801A66A0 * 0x444);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9105;
    pkt.x = 48.0f - dx;
    pkt.y = 87.0f;
    pkt.z = 0.101f;
    pkt.flags = 5;
    fn_1_4F734(&pkt);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9104;
    pkt.x = 320.0f - dx;
    pkt.y = 153.0f;
    pkt.z = 0.099f;
    pkt.flags = 11;
    pkt.color[0] = 0;
    pkt.color[1] = 0xFF;
    pkt.color[2] = 0xFF;
    pkt.alpha = 0.3f + wave;
    fn_1_4F734(&pkt);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9104;
    pkt.x = 320.0f - dx;
    pkt.y = 153.0f;
    pkt.z = 0.099f;
    pkt.flags = 0x80009;
    pkt.color[0] = 0;
    pkt.color[1] = 0xFF;
    pkt.color[2] = 0xFF;
    pkt.alpha = 0.3f + wave;
    fn_1_4F734(&pkt);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9102;
    pkt.x = 346.0f - dx;
    pkt.y = 217.0f;
    pkt.flags = 10;
    fn_1_4F734(&pkt);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9103;
    pkt.x = (346.0f + ((v - 50) * 15 / 50)) - dx;
    pkt.y = 217.0f;
    pkt.flags = 10;
    pkt.z -= 0.001f;
    fn_1_4F734(&pkt);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9100;
    fn_1_51678(&pkt, pkt.image, 0, cup * 36, fn_1_48690(pkt.image), 36);
    pkt.x = 228.0f - dx;
    pkt.y = 105.0f;
    pkt.scale_x *= 0.8f;
    pkt.scale_y *= 0.8f;
    pkt.flags = 10;
    pkt.z = 0.099f;
    fn_1_4F734(&pkt);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9101;
    fn_1_51678(&pkt, pkt.image, 0, cup * 28, fn_1_48690(pkt.image), 28);
    pkt.x = 466.0f - dx;
    pkt.y = 105.0f;
    pkt.flags = 10;
    pkt.z = 0.099f;
    pkt.scale_x *= 0.8f;
    pkt.scale_y *= 0.8f;
    fn_1_4F734(&pkt);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9106;
    fn_1_51564(0, 0, 64, 64, 6, 7);
    i = cell < 0 ? 0 : (cell > 41 ? 41 : cell);
    fn_1_5158C(&pkt, pkt.image, i % 6, i / 6);
    pkt.x = 286.0f - dx;
    pkt.y = 217.0f;
    pkt.flags = 10;
    pkt.z = 0.099f;
    fn_1_4F734(&pkt);

    fn_1_49410();
    {
        fn_14_1090_Color c = {0x00, 0xFF, 0x00, 0x00};
        fn_1_49514(&c);
    }
    fn_1_495C8(9);
    fn_1_496FC(320.0f + dx, 52.0f);
    fn_1_4955C(0.6666666865348816f, 0.5833333134651184f);
    fn_1_495B0(0x80000000);
    fn_1_4AE0C("Your Record PASSWORD");
    fn_1_53B14(NULL, 320.0f + dx, 52.0f, 488.0f, 28.0f, 0.101f);
    fn_1_496FC(226.0f - dx, 189.0f);
    fn_1_4955C(0.5f, 0.4166666567325592f);
    fn_1_4AE0C("MACHINE DATA");
    fn_1_496FC(470.0f - dx, 189.0f);
    fn_1_4AE0C("BEST TOTAL TIME");

    fn_1_49410();
    {
        fn_14_1090_Color c = {0xFF, 0x80, 0x00, 0x00};
        fn_1_49514(&c);
    }
    fn_1_495C8(9);
    fn_1_496FC(320.0f + dx, 280.0f);
    fn_1_495B0(0x80000000);
    fn_1_4955C(0.5f, 0.5f);
    if (lbl_801A66B4 == 5) {
        /* the same notice in Japanese, as Shift-JIS bytes */
        fn_1_4AE0C("\202e\201|\202y\202d\202q\202n\214\366\216\256\203y\201[\203W\201w"
                   "/bcffff00/http://f-zero.jp//bcff8000/"
                   "\201x\202\305\203p\203X\203\217\201[\203h\202\360\n"
                   "\223\374\227\315\202\267\202\352\202\316\201A\203C\203\223\203^\201[\203l\203b\203g"
                   "\203\211\203\223\203L\203\223\203O\202\311\216Q\211\301\202\305\202\253\202\334\202\267\201B");
    } else {
        fn_1_4AE0C("Enter your password at the F-ZERO official website\n"
                   "(/bcffff00/http://f-zero.jp/bcff8000/) to join the Internet Ranking! ");
    }
    fn_1_53B14(NULL, 320.0f + dx, 280.0f, 488.0f, 44.0f, 0.101f);

    fn_1_49410();
    fn_1_495FC();
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(&c);
    }
    fn_1_495C8(9);
    fn_1_495B0(0x80000000);
    fn_1_4954C(0.09f);
    fn_1_496FC(272.0f + (48.0f - dx), 151.0f);
    fn_1_4955C(1.25f, 1.0833333730697632f);
    w = fn_1_4B040((const char *)fn_1_15AC00());
    if (w > 500.0f) {
        fn_1_4955C(30.0f * (500.0f / w) / 24.0f, 1.0833333730697632f);
    }
    fn_1_4AE0C("%s", fn_1_15AC00());
    fn_1_496FC(422.0f + (48.0f - dx), 217.0f);
    fn_1_4955C(1.0f, 1.0833333730697632f);
    fn_1_4AE0C("%01d'%02d\"%03d", ms / 1000 / 60, ms / 1000 % 60, ms % 1000);
    /* through a local: retail converts 217.0f at run time (fctiwz), where a literal argument is folded */
    y = 217.0f;
    fn_1_1358BC(166.0f - dx, y, 10, cell, lbl_801A66B4, fn_1_14F090(0, fn_1_15B3E8()),
                fn_1_14F090(1, fn_1_15B3F8()), fn_1_14F090(2, fn_1_15B408()), 0.9f, 0.9f, 0.1f);
}
/* fzgx:end fn_14_B484 */

/* fzgx:begin fn_14_BCDC */
extern f32 lbl_8006D0B4(f32);

void fn_14_BCDC(void) {
    lbl_14_bss_9460.unk_0 = 0;
    lbl_14_bss_0 = 366;
}
/* fzgx:end fn_14_BCDC */

/* fzgx:begin fn_14_BCF8 */
static inline s32 pp_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

void fn_14_BCF8(void) {
    s32 dx;
    s32 dy;
    f32 t;
    f32 y;
    FontDrawPacket pkt;

    dx = -5.0f + 10.0f * (pp_rand() / 32767.0f);
    dy = -5.0f + 10.0f * (pp_rand() / 32767.0f);
    fn_1_133DBC(NULL);
    fn_1_13DC54();
    fn_1_13B328(0, 1);
    if (lbl_14_bss_0 == 336.0) {
        fn_1_A2D84(0xA9150100);
    } else if (lbl_14_bss_0 == 318.0) {
        fn_1_A2D84(0xA9150100);
    } else if (lbl_14_bss_0 == 306.0) {
        fn_1_A2D84(0xA9150000);
        fn_1_A2D84(0xA9110600);
    }
    if (lbl_14_bss_0 > 336.0) {
        t = (f32)(366.0 - lbl_14_bss_0) / 29.0;
        pkt = lbl_1_rodata_26F8;
        pkt.image = 0x9208;
        pkt.x = 320.0f;
        pkt.flags = 14;
        y = t * (224.0f * t * t);
        pkt.y = y;
        fn_1_4F734(&pkt);
        pkt = lbl_1_rodata_26F8;
        pkt.image = 0x9207;
        pkt.x = 320.0f;
        pkt.y = 448.0f - y;
        pkt.flags = 6;
        fn_1_4F734(&pkt);
    } else if (lbl_14_bss_0 > 318.0) {
        t = lbl_8006D0B4((f32)(336.0 - lbl_14_bss_0) / 17.0);
        t = lbl_8006D188(16384.0f + 32768.0f * t);
        t = __fabs(t);
        pkt = lbl_1_rodata_26F8;
        pkt.image = 0x9208;
        pkt.x = 320.0f;
        y = 204.0f + 20.0f * t;
        pkt.y = y;
        pkt.flags = 14;
        fn_1_4F734(&pkt);
        pkt = lbl_1_rodata_26F8;
        pkt.image = 0x9207;
        pkt.x = 320.0f;
        pkt.y = 448.0f - y;
        pkt.flags = 6;
        fn_1_4F734(&pkt);
    } else if (lbl_14_bss_0 > 306.0) {
        pkt = lbl_1_rodata_26F8;
        pkt.x = 320.0f;
        pkt.y = 224.0f;
        pkt.flags = 14;
        pkt.image = 0x9208;
        fn_1_4F734(&pkt);
        pkt.flags = 6;
        pkt.image = 0x9207;
        fn_1_4F734(&pkt);
    } else if (lbl_14_bss_0 > 300) {
        pkt = lbl_1_rodata_26F8;
        pkt.x = dx + 320;
        pkt.y = dy + 224;
        pkt.flags = 14;
        pkt.image = 0x9208;
        fn_1_4F734(&pkt);
        pkt.flags = 6;
        pkt.image = 0x9207;
        fn_1_4F734(&pkt);
    } else {
        pkt = lbl_1_rodata_26F8;
        pkt.x = 320.0f;
        pkt.y = 224.0f;
        pkt.flags = 14;
        pkt.image = 0x9208;
        fn_1_4F734(&pkt);
        pkt.flags = 6;
        pkt.image = 0x9207;
        fn_1_4F734(&pkt);
    }
    if (lbl_801A66C0 == 66.0) {
        fn_1_A1588(*lbl_1_bss_6EAD0, 39);
    }
    fn_1_49410();
    fn_1_495FC();
    fn_1_495C8(9);
    fn_1_495B0(0x80000000);
    y = 1.0f;
    if (lbl_14_bss_0 > 300) {
        y = 0.0f;
    } else if (lbl_14_bss_0 > 270.0) {
        y -= (f32)((f32)(lbl_14_bss_0 - 270.0) / 30.0);
    }
    fn_1_495A0(y);
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0xFF};
        fn_1_49514(&c);
    }
    fn_14_DC90(y);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9201;
    pkt.x = 320.0f;
    pkt.y = 224.0f;
    pkt.flags = 10;
    pkt.z = 0.09f;
    if (lbl_14_bss_0 > 318.0) {
        pkt.scale_x = 0.0f;
        pkt.scale_y = 0.0f;
        pkt.alpha = 0.0f;
    } else if (lbl_14_bss_0 > 306.0) {
        t = lbl_8006D0B4((f32)(lbl_14_bss_0 - 300 - 6.0) / 12.0);
        pkt.scale_x = 1.0f + t;
        pkt.scale_y = 1.0f + t;
        pkt.alpha = 1.0f - t;
    } else if (lbl_14_bss_0 > 300) {
        pkt.x = 320.0f + dx;
        pkt.y = 224.0f + dy;
    }
    fn_1_4F734(&pkt);
    if (lbl_14_bss_0 < 0) {
        lbl_1_bss_96A = 179;
    }
}
/* fzgx:end fn_14_BCF8 */

/* fzgx:begin fn_14_C4F4 */
extern size_t strlen(const char *);
extern char *strncpy(char *, const char *, size_t);
extern s16 lbl_1_bss_968;

// fn_14_C4F4: empty in retail (single blr).
void fn_14_C4F4(void) {
}
/* fzgx:end fn_14_C4F4 */

/* fzgx:begin fn_14_C4F8 */
void fn_14_C4F8(void) {
    lbl_14_bss_0 = 60;
    lbl_1_bss_6EAB4 |= 44;
}
/* fzgx:end fn_14_C4F8 */

/* fzgx:begin fn_14_C518 */
void fn_14_C518(void) {
    FontDrawPacket pkt;

    pkt = lbl_1_rodata_26F8;
    pkt.x = 320.0f;
    pkt.y = 224.0f;
    pkt.flags = 14;
    pkt.image = 0x9208;
    fn_1_4F734(&pkt);
    pkt.flags = 6;
    pkt.image = 0x9207;
    fn_1_4F734(&pkt);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9201;
    pkt.x = 320.0f;
    pkt.y = 224.0f;
    pkt.flags = 10;
    pkt.z = 0.09f;
    fn_1_4F734(&pkt);
    fn_1_49410();
    fn_1_495FC();
    fn_1_495C8(9);
    fn_1_495B0(0x80000000);
    {
        fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0xFF};
        fn_1_49514(&c);
    }
    fn_14_DC90(1.0f);
    if (lbl_14_bss_0 > 0) {
        fn_8006CE1C(1.0f - lbl_14_bss_0 / 60.0f);
    } else {
        lbl_1_bss_968 = 10;
    }
}
/* fzgx:end fn_14_C518 */

/* fzgx:begin fn_14_C698 */
// fn_14_C698: empty in retail (single blr).

void fn_14_C698(void) {
}
/* fzgx:end fn_14_C698 */

/* fzgx:begin fn_14_C69C */
void fn_14_C69C(fn_14_1090_Sprite *sprite, f32 t) {
    char buf[256];

    if (sprite->y != 0 || 1.0f == t) {
        sprintf(buf, "%s", sprite->names[lbl_801A66B4]);
        fn_1_4AE0C(buf);
        return;
    }
    if (t < 0.6f) {
        f32 len = strlen(sprite->names[lbl_801A66B4]);
        u32 n = len * t;
        strncpy(buf, sprite->names[lbl_801A66B4], n);
        if ((lbl_801A66A0 & 3) < 2) {
            buf[n] = '_';
            buf[n + 1] = 0;
        } else {
            buf[n] = 0;
        }
    } else if ((lbl_801A66A0 & 3) < 2) {
        sprintf(buf, "%s_", sprite->names[lbl_801A66B4]);
    } else {
        sprintf(buf, "%s", sprite->names[lbl_801A66B4]);
    }
    fn_1_4AE0C(buf);
}
/* fzgx:end fn_14_C69C */

/* fzgx:begin fn_14_C850 */
extern f32 fn_1_4B068(const char *);

void fn_14_C850(fn_14_1090_Score *score, f32 t) {
    char buf[2];
    u32 total;
    f32 t2;
    u32 i;
    u32 len;
    u8 c;
    s32 value;
    s32 offset;
    s32 y;
    s32 k;

    if (score != NULL && 0.0f != t) {
        if (1.0f == t || score->cur == 0) {
            fn_1_4955C(score->scale_x, score->scale_y);
            fn_1_4AE0C("%d", score->cur);
            return;
        }
        if (score->y == 0) {
            y = lbl_14_bss_C;
        } else {
            y = score->y;
        }
        t2 = t * t;
        for (k = 0, len = 10; k < 10; k++) {
            if (__fabs((f32)score->cur) < len) {
                len = k + 1;
                break;
            }
            len *= 10;
        }
        if (score->cur < 0) {
            len++;
        }
        total = len;
        total += 1;
        offset = 0;
        i = 0;
        value = __fabs((f32)score->cur);
        while (i < len) {
            if (score->cur < 0 && i == len - 1) {
                c = '-';
            } else {
                c = '0' + value % 10;
                value = value / 10;
            }
            if ((i + 2) / (f32)total < t2) {
                fn_1_496FC(score->x - offset, y);
                fn_1_4955C(score->scale_x, score->scale_y);
                fn_1_4AE0C("%c", c);
                buf[0] = c;
                buf[1] = 0;
                offset = offset + fn_1_4B068(buf);
            } else if ((f32)i / total < t2) {
                fn_1_496FC(score->x - offset, y);
                fn_1_4955C(score->scale_x, score->scale_y);
                c = '0' + pp_rand() % 10;
                fn_1_4AE0C("%c", c);
                buf[0] = c;
                buf[1] = 0;
                offset = offset + fn_1_4B068(buf);
            }
            i++;
        }
    }
}
/* fzgx:end fn_14_C850 */

/* fzgx:begin fn_14_CC70 */
/* WARNING: compiler-diff device, not original code (opt_propagation off, carried from main) */
#pragma push
#pragma opt_propagation off
void fn_14_CC70(s32 frame) {
    FontDrawPacket pkt;
    f32 t;

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9E2B;
    pkt.flags = 10;
    pkt.z = 0.09f;
    if (frame > 222.0) {
        f32 alpha;

        alpha = (f32)(240 - frame) / 18.0;
        pkt.x = 320.0f;
        pkt.y = 224.0f;
        pkt.alpha = alpha;
        pkt.alpha = alpha * alpha;
        fn_1_50164(&pkt, 300.0f * pkt.alpha, 160.0f * pkt.alpha, 8.0f, 8.0f);
    } else if (frame > 18.0) {
        if (222.0 == frame) {
            fn_1_A2D84(0xA9110100);
        }
        pkt.x = 320.0f;
        pkt.y = 224.0f;
        fn_1_50164(&pkt, 300.0f, 160.0f, 8.0f, 8.0f);
        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_495C8(9);
        fn_1_4955C(0.7f, 0.7f);
        fn_1_496FC(320.0f, 207.0f);
        fn_1_4AE0C("%s", lbl_14_data_B4C[lbl_801A66B4]);
        if (frame < 168.0 && frame > 138.0) {
            t = frame - 138.0;
            t /= 30.0;
            t = 0.5 - __fabs(t - 0.5f);
            t *= 2.0f;
            pkt = lbl_1_rodata_26F8;
            pkt.image = 0x944D;
            pkt.x = 320.0f;
            pkt.y = 264.0f;
            pkt.flags = 10;
            pkt.scale_x = 5.0f * t * t;
            pkt.scale_y = pkt.scale_x;
            pkt.z = 0.09f - 0.05f;
            fn_1_4F734(&pkt);
        }
        if (frame > 153.0) {
            fn_1_4955C(0.7f, 0.7f);
            fn_1_496FC(320.0f, 264.0f);
            fn_1_4AE0C("%s", lbl_14_bss_6C);
            pkt = lbl_1_rodata_26F8;
            pkt.image = 0x9500;
            fn_1_51564(0, 0, 20, 20, 10, 4);
            fn_1_5158C(&pkt, pkt.image, lbl_14_bss_104 % 10, lbl_14_bss_104 / 10);
            pkt.x = 230.0f;
            pkt.y = 264.0f;
            pkt.z = 0.05f;
            pkt.flags = 10;
            fn_1_4F734(&pkt);
            pkt.x = 410.0f;
            fn_1_4F734(&pkt);
        } else {
            fn_1_4965C(2);
            fn_1_496FC(320.0f, 264.0f);
            fn_1_4955C(0.7f, 0.7f);
            {
                fn_14_1090_Color c = {0xFF, 0xFF, 0x40, 0xFF};
                fn_1_49514(&c);
            }
            fn_1_4AE0C("%s", lbl_14_bss_AC);
            fn_1_4965C(0);
            {
                fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0xFF};
                fn_1_49514(&c);
            }
            pkt = lbl_1_rodata_26F8;
            pkt.image = 0x9500;
            fn_1_51564(0, 0, 20, 20, 10, 4);
            fn_1_5158C(&pkt, pkt.image, lbl_14_bss_108 % 10, lbl_14_bss_108 / 10);
            pkt.x = 230.0f;
            pkt.y = 264.0f;
            pkt.z = 0.05f;
            pkt.flags = 10;
            fn_1_4F734(&pkt);
            pkt.x = 410.0f;
            fn_1_4F734(&pkt);
        }
        fn_1_49738(fn_1_5233C);
        fn_1_49748(5.0f);
        pkt = lbl_1_rodata_26F8;
        pkt.image = 0x9202;
        pkt.z = 0.07f;
        pkt.x = 320.0f;
        pkt.y = 179.0f;
        {
            f32 fade;
            f32 square;

            fade = frame - 204.0;
            fade /= 18.0;
            t = fade < 0.0f ? 0.0f : fade > 1.0f ? 1.0f : fade;
            pkt.flags = 10;
            square = 1.0f - t;
            square = square * square;
            pkt.alpha = square;
            pkt.scale_x = 1.0f + 2.0f * t;
            pkt.scale_y = pkt.scale_x;
        }
        fn_1_4F734(&pkt);
    } else {
        t = (f32)frame / 18.0;
        pkt.x = 320.0f;
        pkt.y = 224.0f;
        pkt.alpha = t;
        pkt.alpha = pkt.alpha * pkt.alpha;
        fn_1_50164(&pkt, 300.0f * pkt.alpha, 160.0f * pkt.alpha, 8.0f, 8.0f);
    }
}
/* fzgx:end fn_14_CC70 */

/* fzgx:begin fn_14_D2EC */
#pragma pop

void fn_14_D2EC(s32 frame) {
    FontDrawPacket pkt;

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9E2B;
    pkt.flags = 10;
    pkt.z = 0.09f;
    if (frame > 222.0) {
        f32 alpha = (f32)(240 - frame) / 18.0;

        pkt.x = 320.0f;
        pkt.y = 224.0f;
        pkt.alpha = alpha;
        pkt.alpha *= alpha;
        fn_1_50164(&pkt, 300.0f * pkt.alpha, 160.0f * pkt.alpha, 8.0f, 8.0f);
    } else if (frame > 18.0) {
        if (222.0 == frame) {
            fn_1_A2D84(0xA9110300);
        }
        pkt.x = 320.0f;
        pkt.y = 224.0f;
        fn_1_50164(&pkt, 300.0f, 160.0f, 8.0f, 8.0f);
        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_495C8(9);
        fn_1_4955C(0.8f, 0.8f);
        fn_1_496FC(320.0f, 244.0f);
        fn_1_4AE0C(lbl_14_data_BD4[lbl_801A66B4]);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(5.0f);
        pkt = lbl_1_rodata_26F8;
        pkt.image = 0x9200;
        pkt.z = 0.07f;
        pkt.x = 320.0f;
        pkt.y = 179.0f;
        {
            f32 t = 0.0f;
            f32 fade = frame - 204.0;

            fade /= 18.0;
            t = fade < 0.0f ? 0.0f : fade > 1.0f ? 1.0f : fade;
            {
                f32 square = 1.0f - t;
                f32 scale;

                pkt.flags = 10;
                square *= square;
                pkt.alpha = square;
                scale = 1.0f + 2.0f * t;
                pkt.scale_x = scale;
                pkt.scale_y = scale;
                fn_1_4F734(&pkt);
            }
        }
    } else {
        f32 alpha = (f32)frame / 18.0;

        pkt.x = 320.0f;
        pkt.y = 224.0f;
        pkt.alpha = alpha;
        pkt.alpha *= alpha;
        fn_1_50164(&pkt, 300.0f * pkt.alpha, 160.0f * pkt.alpha, 8.0f, 8.0f);
    }
}
/* fzgx:end fn_14_D2EC */

/* fzgx:begin fn_14_D600 */
void fn_14_D600(s32 frame) {
    FontDrawPacket pkt;

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9E2B;
    pkt.flags = 10;
    pkt.z = 0.09f;
    if (frame > 222.0) {
        f32 alpha = (f32)(240 - frame) / 18.0;

        pkt.x = 320.0f;
        pkt.y = 224.0f;
        pkt.alpha = alpha;
        pkt.alpha *= alpha;
        fn_1_50164(&pkt, 300.0f * pkt.alpha, 160.0f * pkt.alpha, 8.0f, 8.0f);
    } else if (frame > 18.0) {
        if (222.0 == frame) {
            fn_1_A2D84(0xA9110200);
        }
        pkt.x = 320.0f;
        pkt.y = 224.0f;
        fn_1_50164(&pkt, 300.0f, 160.0f, 8.0f, 8.0f);
        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_495C8(9);
        fn_1_4955C(0.8f, 0.8f);
        fn_1_496FC(320.0f, 244.0f);
        fn_1_4AE0C(lbl_14_data_C54[lbl_801A66B4]);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(5.0f);
        pkt = lbl_1_rodata_26F8;
        pkt.image = 0x9206;
        pkt.x = 320.0f;
        pkt.y = 179.0f;
        {
            f32 t = 0.0f;
            f32 fade = frame - 204.0;

            fade /= 18.0;
            t = fade < 0.0f ? 0.0f : fade > 1.0f ? 1.0f : fade;
            {
                f32 square = 1.0f - t;
                f32 scale;

                pkt.flags = 10;
                square *= square;
                pkt.alpha = square;
                scale = 1.0f + 2.0f * t;
                pkt.z = 0.07f;
                pkt.scale_x = scale;
                pkt.scale_y = scale;
                fn_1_4F734(&pkt);
            }
        }
    } else {
        f32 alpha = (f32)frame / 18.0;

        pkt.x = 320.0f;
        pkt.y = 224.0f;
        pkt.alpha = alpha;
        pkt.alpha *= alpha;
        fn_1_50164(&pkt, 300.0f * pkt.alpha, 160.0f * pkt.alpha, 8.0f, 8.0f);
    }
}
/* fzgx:end fn_14_D600 */

/* fzgx:begin fn_14_D914 */
void fn_14_D914(s32 frame) {
    FontDrawPacket pkt;

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9E2B;
    pkt.flags = 10;
    pkt.z = 0.09f;
    if (frame > 222.0) {
        f32 alpha = (f32)(240 - frame) / 18.0;

        pkt.x = 320.0f;
        pkt.y = 224.0f;
        pkt.alpha = alpha;
        pkt.alpha *= alpha;
        fn_1_50164(&pkt, 300.0f * pkt.alpha, 160.0f * pkt.alpha, 8.0f, 8.0f);
    } else if (frame > 18.0) {
        if (222.0 == frame) {
            fn_1_A2D84(0xA9110200);
        }
        pkt.x = 320.0f;
        pkt.y = 224.0f;
        fn_1_50164(&pkt, 300.0f, 160.0f, 8.0f, 8.0f);
        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_495C8(9);
        fn_1_4955C(0.8f, 0.8f);
        fn_1_496FC(320.0f, 244.0f);
        fn_1_4AE0C(lbl_14_data_C9C[lbl_801A66B4]);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(5.0f);
        pkt = lbl_1_rodata_26F8;
        pkt.image = 0x9206;
        pkt.x = 320.0f;
        pkt.y = 179.0f;
        {
            f32 t = 0.0f;
            f32 fade = frame - 204.0;

            fade /= 18.0;
            t = fade < 0.0f ? 0.0f : fade > 1.0f ? 1.0f : fade;
            {
                f32 square = 1.0f - t;
                f32 scale;

                pkt.flags = 10;
                square *= square;
                pkt.alpha = square;
                scale = 1.0f + 2.0f * t;
                pkt.z = 0.07f;
                pkt.scale_x = scale;
                pkt.scale_y = scale;
                fn_1_4F734(&pkt);
            }
        }
    } else {
        f32 alpha = (f32)frame / 18.0;

        pkt.x = 320.0f;
        pkt.y = 224.0f;
        pkt.alpha = alpha;
        pkt.alpha *= alpha;
        fn_1_50164(&pkt, 300.0f * pkt.alpha, 160.0f * pkt.alpha, 8.0f, 8.0f);
    }
}
/* fzgx:end fn_14_D914 */

/* fzgx:begin fn_14_DC28 */
/* not referenced: 6-language notices */
char *lbl_14_data_3290[6] = {"Please unfasten your seatbelt.\n", "", "", "", "", "\x83V\x81[\x83g\x83x\x83\x8B\x83g\x82\xF0\x82\xCD\x82\xB8\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"};
char *lbl_14_data_32FC[6] = {"Your F-ZERO LICENSE CARD has expired.\n", "", "", "", "", "\x83\x89\x83" "C\x83Z\x83\x93\x83X\x83J\x81[\x83h\x82\xAA\x8Eg\x97p\x90\xA7\x8C\xC0\x82\xC9\x92" "B\x82\xB5\x82\xDC\x82\xB5\x82\xBD\x81" "B\n"};
char *lbl_14_data_3370[6] = {"You can transfer your play data by renewing\n", "", "", "", "", "\x82\xB1\x82\xCC\x83" "f\x81[\x83^\x82\xC5\x88\xF8\x82\xAB\x91\xB1\x82\xAB\x83v\x83\x8C\x83" "C\x82\xB7\x82\xE9\x8F\xEA\x8D\x87\x82\xCD\x8E\x9F\x89\xF1\x82\xCC\n"};
char *lbl_14_data_33F0[6] = {"your F-ZERO LICENSE CARD when you play next time.\n", "", "", "", "", "\x83v\x83\x8C\x83" "C\x8E\x9E\x82\xC9\x81u\x83J\x81[\x83h\x82\xCC\x88\xF8\x82\xAB\x8Cp\x82\xAC\x81v\x82\xF0\x8Ds\x82\xC1\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n"};
char *lbl_14_data_3448[6] = {"Please take your cards.\n", "", "", "", "", "\x83J\x81[\x83h\x82\xF0\x96Y\x82\xEA\x82\xB8\x82\xC9\x82\xA8\x8E\x9D\x82\xBF\x8B" "A\x82\xE8\x82\xAD\x82\xBE\x82\xB3\x82\xA2\n"};
char *lbl_14_data_34AC[6] = {"Please take your Memory Card.\n", "", "", "", "", "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x96Y\x82\xEA\x82\xB8\x82\xC9\x82\xA8\x8E\x9D\x82\xBF\x8B" "A\x82\xE8\x82\xAD\x82\xBE\x82\xB3\x82\xA2\n"};
char *lbl_14_data_351C[6] = {"Please take your F-ZERO LICENSE CARD.\n", "", "", "", "", "\x83\x89\x83" "C\x83Z\x83\x93\x83X\x83J\x81[\x83h\x82\xF0\x96Y\x82\xEA\x82\xB8\x82\xC9\x82\xA8\x8E\x9D\x82\xBF\x8B" "A\x82\xE8\x82\xAD\x82\xBE\x82\xB3\x82\xA2\n"};

// fn_14_DC28: empty in retail (single blr).

void fn_14_DC28(void) {
}
/* fzgx:end fn_14_DC28 */

/* fzgx:begin fn_14_DC2C */
typedef struct LocalData {
    u8 data[0x1471];
    u8 field_1479;
    u8 field_147a;
    u8 tail[0x38];
} LocalData;

u8 fn_14_DC2C(void) {
    LocalData local;
    u32 result;

    fn_1_3EF14(&local);
    if (local.field_147a != 0) {
        result = 0;
    } else {
        result = local.field_1479;
    }
    return result;
}
/* fzgx:end fn_14_DC2C */

/* fzgx:begin fn_14_DC6C */
char *fn_14_DC6C(s16 group, s16 lang) {
    return lbl_14_data_6C8[group][lang];
}
/* fzgx:end fn_14_DC6C */

/* fzgx:begin fn_14_DC90 */
extern void fn_1_4D0A0(void);
extern void fn_1_4D10C(fn_14_1090_Color *, f32, f32);

/* Unknown retail objects: .rodata 0x4F4..0x514, nine colours. No code or data in any REL refers to them. */
const fn_14_1090_Color lbl_14_rodata_4F4[9] = {
    {0x19, 0xFF, 0x19, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF},
    {0x19, 0xFF, 0x19, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF},
    {0x19, 0xFF, 0x19, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, {0x19, 0xFF, 0x19, 0xFF},
};

void fn_14_DC90(f32 alpha) {
    FontDrawPacket pkt;

    if (lbl_1_bss_962 != 0xAF) {
        fn_1_4D0A0();
    } else {
        pkt = lbl_1_rodata_26F8;
        pkt.image = 0x9E2B;
        pkt.x = 320.0f;
        pkt.y = 375.0f;
        pkt.z = 0.08f;
        pkt.flags = 10;
        pkt.alpha = alpha;
        fn_1_50164(&pkt, 428.0f, 130.0f, 8.0f, 8.0f);
        fn_1_49410();
        fn_1_495FC();
        fn_1_495C8(9);
        fn_1_495B0(0x80000000);
    }
    fn_1_49590(0.5f);
    fn_1_4954C(0.07f);
    if (fn_1_B7E98(1) != 0) {
        if (lbl_14_bss_9460.unk_0 != 0) {
            fn_1_496FC(320.0f, 364.0f);
            fn_1_4955C(0.5416667f, 0.5416667f);
            {
                fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0xFF};
                fn_1_49514(&c);
            }
            fn_1_4AE0C(lbl_14_data_32FC[lbl_801A66B4]);
            fn_1_4AE0C(lbl_14_data_3370[lbl_801A66B4]);
            fn_1_4AE0C(lbl_14_data_33F0[lbl_801A66B4]);
        } else {
            fn_1_496FC(320.0f, 375.0f);
        }
        fn_1_4955C(0.5416667f, 0.5416667f);
        {
            fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0xFF};
            fn_1_49514(&c);
        }
        fn_1_4AE0C(lbl_14_data_34AC[lbl_801A66B4]);
        {
            fn_14_1090_Color unread_520 = {0x19, 0xFF, 0x19, 0xFF}; /* Not read by any code. Kept as in the retail data order. */
            fn_14_1090_Color unread_524 = {0xFF, 0xFF, 0xFF, 0xFF}; /* Not read by any code. Kept as in the retail data order. */
            fn_14_1090_Color unread_528 = {0x19, 0xFF, 0x19, 0xFF}; /* Not read by any code. Kept as in the retail data order. */
        }
    } else if (lbl_14_bss_9460.unk_0 != 0) {
        fn_1_496FC(320.0f, 364.0f);
        fn_1_4955C(0.5416667f, 0.5416667f);
        {
            fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0xFF};
            fn_1_49514(&c);
        }
        fn_1_4AE0C(lbl_14_data_32FC[lbl_801A66B4]);
        fn_1_4AE0C(lbl_14_data_3370[lbl_801A66B4]);
        fn_1_4AE0C(lbl_14_data_33F0[lbl_801A66B4]);
    }
    if ((lbl_14_bss_9460.unk_0 != 0 || fn_1_B7E98(1) != 0) && lbl_1_bss_962 != 0xAF) {
        fn_14_1090_Color out;
        fn_14_1090_Color c = {0xFF, 0xFF, 0xFF, 0x00};

        c.a = 255.0f * alpha;
        out = c;
        fn_1_4D10C(&out, 0.08f, 30.0f);
    }
}
/* fzgx:end fn_14_DC90 */

/* fzgx:begin fn_14_DF70 */
u8 fn_14_DF70(void) {
    PPRecord rec;

    if (lbl_1_bss_8B3A0.unk_0 == 9) {
        return 0;
    }
    fn_1_128E8C(fn_1_128DD8(lbl_1_bss_8B3A0.unk_90), &rec);
    if (rec.unk_0 == 8 && rec.unk_1 == 44 && rec.unk_2 == 287) {
        return 0;
    }
    return 1;
}
/* fzgx:end fn_14_DF70 */
