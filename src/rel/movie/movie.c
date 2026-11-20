#include "types.h"
#include "font.h"
#include "dolphin/gx.h"

/* main_rel and DOL interfaces used by the movie module */
typedef struct GXTexObj { u32 dummy[8]; } GXTexObj;
typedef struct GXColor { u8 r, g, b, a; } GXColor;
typedef struct GXColorS10 { s16 r, g, b, a; } GXColorS10;

typedef struct MoviePlayer MoviePlayer;
typedef struct MoviePlayerVtbl {
    u8 pad_0[0x14];
    void (*stop)(MoviePlayer *);                /* 0x14 */
    void (*start)(MoviePlayer *, void *);       /* 0x18 */
    void (*close)(MoviePlayer *);               /* 0x1C */
    s32 (*getState)(MoviePlayer *);             /* 0x20 */
    u8 pad_24[4];
    void (*setPause)(MoviePlayer *, s32);       /* 0x28 */
    void (*setVolume)(MoviePlayer *, s32);      /* 0x2C */
} MoviePlayerVtbl;
struct MoviePlayer {
    MoviePlayerVtbl *vtbl;
};

typedef struct MovieFrame {
    u32 valid;
    u8 pad_4[0x18];
    s32 rate;
    u8 pad_20[0x10];
    s32 frame;
    u8 pad_34[0x18];
} MovieFrame;

typedef struct MovieCommand {
    s16 type;
    s16 arg;
    s16 duration;
} MovieCommand;

typedef struct MovieInit {
    f32 rate;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0x10];
} MovieInit;

typedef struct MovieConfig {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    void *unk_18;
    u32 unk_1C;
    u32 unk_20;
    u8 pad_24[0xC];
} MovieConfig;

typedef struct { u32 words[0x18]; } MovieLoadResult;

typedef struct MovieSubtitle {
    s32 start;
    s32 length;
    s32 size;
    s32 line;
    u8 text[0x100];
} MovieSubtitle;

typedef struct MovieTask {
    char name[0x20];
    void (*init)(void);
    void (*main)(void);
    void (*disp)(void);
} MovieTask;

typedef struct MovieMenuEntry {
    u8 x;
    u8 y;
    s16 id;
    char name[0x40];
} MovieMenuEntry;

typedef struct ARQRequest {
    struct ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    void (*callback)(u32);
} ARQRequest;

typedef struct MovieDisplay {
    s8 unk_0;
    s8 unk_1;
    s8 unk_2;
    s8 unk_3;
    s16 width;
    s16 height;
    s16 x;
    s16 y;
    f32 scaleX;
    f32 scaleY;
    s8 unk_14;
    u8 pad_15[1];
    s8 unk_16;
    s8 unk_17;
    s16 unk_18;
    u8 pad_1A[2];
    u32 unk_1C;
} MovieDisplay;

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

typedef struct SystemCursor {
    u32 unk_0;
    u8 unk_4;
} SystemCursor;

typedef struct AdxHandleHolder {
    void **unk_0;
} AdxHandleHolder;

extern u32 lbl_801A6410;
extern u32 lbl_801A66B4;
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_964;
extern s16 lbl_1_bss_968;
extern s16 lbl_1_bss_96A;
extern SystemCursor lbl_1_bss_970;
extern char lbl_1_bss_198[][64];
extern MovieDisplay lbl_1_bss_58;
extern PadInput lbl_1_bss_9F8[];
extern PadInput lbl_1_bss_D58;
extern AdxHandleHolder lbl_1_bss_6EAD0;
extern u32 lbl_1_bss_6EAB4;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern u32 lbl_1_bss_71684;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 lbl_1_bss_8B614[2];
extern char *lbl_1_data_370[];
extern void (*lbl_1_bss_194)(MovieInit *);
extern u32 (*lbl_1_bss_18C)(MovieConfig *);
extern MoviePlayer *(*lbl_1_bss_188)(MovieConfig *);
extern void (*lbl_1_bss_190)(void);
extern void (*lbl_1_bss_184)(MoviePlayer *, MovieFrame *);
extern void (*lbl_1_bss_E4)(MoviePlayer *, MovieFrame *, void *, void *);
extern void (*lbl_1_bss_180)(MoviePlayer *);
extern s32 (*lbl_1_bss_170)(MoviePlayer *);
extern FontDrawPacket lbl_1_rodata_26F8;

extern void fn_1_12B4(void);
extern void fn_1_12FC(void);
extern void fn_1_1300(void);
extern void *fn_1_45D0(u32, u32, const char *, s32);
extern void *fn_1_4630(u32, u32, const char *, s32);
extern void fn_1_46B4(u32, void *, const char *, s32);
extern void fn_1_3CF0(u32, u32);
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_435C(u32);
extern void fn_1_41A8(u32);
extern void fn_1_3C78(void);
extern s32 fn_1_3F8C(const char *, void (*)(void), u32, u32);
extern void fn_1_4A00(s32, u8, u32);
extern int fn_1_4C10(void);
extern void fn_1_157940(void);
extern s32 fn_1_157920(void);
extern s32 fn_1_157930(void);
extern f32 fn_1_1577D0(u32, u32, f32);
extern void fn_1_157820(void);
extern void fn_1_1578C4(void);
extern void fn_1_479F0(s16);
extern void fn_1_47A60(u32);
extern void fn_1_47F74(s32);
extern void fn_1_48140(s32);
extern void fn_1_411A4(u32);
extern void fn_1_412A0(u32);
extern void fn_1_A0680(void);
extern void fn_1_A0AA4(void);
extern void fn_1_A5AA0(const char *, void *);
extern void fn_1_A5C98(void *);
extern s32 fn_1_A5DC4(void);
extern u32 fn_1_FA638(void);
extern void fn_1_FA650(void);
extern void fn_1_49410(void);
extern void fn_1_49514(GXColor *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_1_4965C(u8);
extern void fn_1_496FC(f32, f32);
extern u32 fn_1_4AEC0(u32);
extern u32 fn_1_4AEE8(u32);
extern int fn_1_45730(const char *, MovieLoadResult *);
extern u32 fn_1_45B2C(MovieLoadResult *);
extern void fn_1_458A0(MovieLoadResult *, void *, u32, u32);
extern u32 fn_1_A1588(void *, u32);
extern void fn_1_A2A70(u32, s32);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_133DBC(void *);
extern void fn_1_134AD4(void);
extern void fn_1_1380F0(const char *);
extern void fn_1_52070(u32);
extern void fn_1_52088(void);
extern void fn_1_520A0(void);
extern void fn_1_520CC(void);
extern s32 fn_1_4E724(FontDrawPacket *);
extern s32 fn_1_4E92C(FontDrawPacket *, u32, s16, s16, void *);
extern u8 fn_1_40ED4(void);
extern void ADXT_Stop(void *);
extern void ADXT_Pause(void *, s32);
extern void ARQPostRequest(ARQRequest *, u32, u32, u32, u32, void *, u32, void (*)(u32));
extern void DCInvalidateRange(void *, u32);
extern void DCFlushRangeNoSync(void *, u32);
extern void GXInvalidateTexAll(void);
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(GXTexObj *, u32, u32, f32, f32, f32, u8, u8, u32);
extern u32 VIGetNextField(void);
extern void VIWaitForRetrace(void);
extern void OSPanic(const char *, int, const char *, ...);
extern int sprintf(char *, const char *, ...);
extern int strncmp(const char *, const char *, u32);
extern char *strchr(const char *, int);
extern char *fn_80083DB0(char *, const char *);
extern int fn_80083BCC(const char *, const char *);
extern s32 fn_80082928(const char *, const char *, ...);
extern void fn_80008BEC(void *, int, u32);
extern u32 fn_800068F4(void (*)(void));
extern u32 fn_80006904(void (*)(void));
extern void fn_8006CE1C(f32);
extern f32 fn_8006CD40(f32);
extern void fn_8006CD50(void);
extern void fn_80070704(s32);
extern void fn_80036058(GXTexObj *, void *);
extern void fn_80074660(u32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_8003726C(u32, GXColorS10 *);
extern void fn_800736C0(u32, GXColor *);
extern void fn_800729B0(s32, s32, s32, s32, s32);
extern void fn_80074788(u32);
extern void fn_80073898(u32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80073778(GXTexObj *, s32);
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void fn_8007264C(u32, s32, s32, s32, u8);
extern void fn_80072864(u32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_80072808(void);

void fn_5_200(void);
void fn_5_220(void);
void fn_5_320(void);
void fn_5_37C(void);
void fn_5_4C8(void);
void fn_5_684(void);
void fn_5_6E8(void);
void fn_5_7A0(void);
void fn_5_13B0(void);
void fn_5_1404(MovieMenuEntry *menu);
void fn_5_169C(void);
void fn_5_20FC(void);
s16 fn_5_2C54(u8 *text, s8 start, s8 count);
void fn_5_2E00(void);
void fn_5_3BF8(void);
void fn_5_3C44(void);
void fn_5_3E54(s8 index);
u32 fn_5_3E74(MovieSubtitle *subtitle);
void fn_5_3F94(void);
void fn_5_3FF0(void);

/* .bss: the player state block, then the module variables in first-use order */
static MoviePlayer *sPlayer = NULL;     /* 0x00 */
static s32 sBgmId = 0;                  /* 0x04 */
static s32 sBgmWait = 0;                /* 0x08 */
static s32 sBgmFade = 0;                /* 0x0C */
static s8 sBgmMode = 0;                 /* 0x10 */
static s8 sBgmSync = 0;                 /* 0x11 */
static u8 sBufIndex = 0;                /* 0x12 */
static s8 sLineCount = 0;               /* 0x13 */
static s8 sCmdIndex = 0;                /* 0x14 */
static s32 sTimer = 0;                  /* 0x18 */
static u8 sAdvance = 0;                 /* 0x1C */
static void (*sPrevMain)(void) = NULL;  /* 0x20 */
static void (*sPrevDisp)(void) = NULL;  /* 0x24 */
static u32 sHeap0 = 0;                  /* 0x28 */
static u32 sHeap1 = 0;                  /* 0x2C */
static u32 sHeap2 = 0;                  /* 0x30 */
static u32 sHeap3 = 0;                  /* 0x34 */
static u8 sRelInfo[8];                  /* 0x38 */
static s8 sMode;            /* 0x40 */
static s8 sPauseReq;        /* 0x41 */
static void *sWork;         /* 0x44 */
static u8 sDeflicker;       /* 0x48 */
static s16 sWidth;          /* 0x4A */
static s16 sHeight;         /* 0x4C */
static s16 sPosX;           /* 0x4E */
static s16 sPosY;           /* 0x50 */
static f32 sScaleX;         /* 0x54 */
static f32 sScaleY;         /* 0x58 */
static s8 sKind;            /* 0x5C */
static s8 sLanguage;        /* 0x5D */
static s8 sFurigana;        /* 0x5E */
static s8 sBackground;      /* 0x5F */
static s8 sSkipMask;        /* 0x60 */
static s8 sLogo;            /* 0x61 */
static s8 sPadPort;         /* 0x62 */
static s16 sVolume;         /* 0x64 */
static s8 sSubtitles;       /* 0x66 */
static s8 sFadeMode;        /* 0x67 */
static f32 sFade;           /* 0x68 */
static f32 sFadeStep;       /* 0x6C */
static u32 sTexSizeY;       /* 0x70 */
static u32 sTexSizeUV;      /* 0x74 */
static void *sPlaneY[2];    /* 0x78 */
static void *sPlaneUV[2];   /* 0x80 */
static GXTexObj sTexY;      /* 0x88 */
static GXTexObj sTexUV;     /* 0xA8 */
static u32 sCaptureSize;    /* 0xC8 */
static void *sCapture;      /* 0xCC */
static MovieFrame sFrame;   /* 0xD0 */
static MovieCommand sCommands[100];         /* 0x11C */
static char sMovieFiles[30][64];            /* 0x374 */
static char *sSubtitleFiles[30];            /* 0xAF4 */
static s32 sStaffRoll;      /* 0xB6C */
static ARQRequest sArq;     /* 0xB70 */
static char *sSubtitleText; /* 0xB90 */
static u8 lbl_5_bss_B94[0x24];  /* 0xB94 */

/* .data */
u16 lbl_5_data_0[10] = { 0x2E4, 0x19A, 0x1F4, 0x1FE, 0x2DA, 0x140, 0x280, 0x3CA, 0x2D0, 0x000 };

/* fzgx:begin _prolog */
void _prolog(void) {
    u32 heap;

    sHeap0 = (u32)fn_1_45D0(lbl_801A6410, 0x584, "movie.c", 0xF4);
    sHeap1 = (u32)fn_1_45D0(lbl_801A6410, 0x584, "movie.c", 0xF5);
    fn_1_3CF0(sHeap0, 2);
    fn_1_3CF0(sHeap1, 2);
    sHeap2 = (u32)fn_1_45D0(lbl_801A6410, 0x584, "movie.c", 0xF8);
    heap = (u32)fn_1_45D0(lbl_801A6410, 0x584, "movie.c", 0xF9);
    sHeap3 = heap;
    fn_1_3CF0(sHeap2, 2);
    fn_1_3CF0(sHeap3, 2);
    fn_1_157940();
    if (lbl_1_bss_964 != 9) {
        fn_1_479F0(8);
    }
    lbl_1_bss_970.unk_0 = 0;
    lbl_1_bss_970.unk_4 = 0;
    if (fn_80083BCC(lbl_1_bss_198[0], "TESTMODE") != 0) { lbl_1_bss_96A = 0x83; } else { lbl_1_bss_96A = 0x82; }
    lbl_1_bss_7167C = (u32)&fn_5_200;
    lbl_1_bss_71680 = (u32)&fn_5_220;
    lbl_1_bss_71684 = (u32)&fn_5_320;
    fn_1_A5AA0("fze.movie_module.rel", sRelInfo);
    if (lbl_1_bss_964 != 0xF) {
        fn_8006CE1C(0.0f);
    } else {
        fn_1_4A00(1, 0xF, sHeap1);
        lbl_1_bss_8B614[1] |= 0x20000000;
    }
    sPlayer = 0;
    sPrevMain = (void (*)(void))fn_800068F4(fn_5_3F94);
    sPrevDisp = (void (*)(void))fn_80006904(fn_5_3FF0);
    fn_1_A0680();
}
/* fzgx:end _prolog */

/* fzgx:begin fn_5_200 */
void fn_5_200(void) {
    if ((s32)lbl_1_bss_970.unk_0 > 0) {
        lbl_1_bss_970.unk_0 -= 1;
    }
}
/* fzgx:end fn_5_200 */

/* fzgx:begin fn_5_220 */
void fn_5_220(void) {
    fn_1_407C(fn_1_435C(sHeap0));
    fn_1_3CC4(fn_1_407C(fn_1_435C(sHeap2)));
    fn_1_407C(fn_1_435C(sHeap1));
    fn_1_407C(fn_1_435C(sHeap3));
}
/* fzgx:end fn_5_220 */

/* fzgx:begin _epilog */
void _epilog(void) {
    fn_8006CE1C(0.0f);
    fn_1_3C78();
    fn_1_157940();
    fn_1_41A8(fn_1_435C(sHeap0));
    fn_1_41A8(fn_1_435C(sHeap1));
    fn_1_41A8(fn_1_435C(sHeap2));
    fn_1_41A8(fn_1_435C(sHeap3));
    fn_1_A0AA4();
    fn_1_47A60(8);
    fn_800068F4(sPrevMain);
    fn_80006904(sPrevDisp);
    sPrevMain = 0;
    sPrevDisp = 0;
    fn_1_A5C98(sRelInfo);
}
/* fzgx:end _epilog */

MovieTask lbl_5_data_40[4] = {
    { "SMD_MOVIE_TOP", fn_1_12B4, fn_1_12FC, fn_1_1300 },
    { "SMD_MOVIE_TEST", fn_5_6E8, fn_5_7A0, fn_5_13B0 },
    { "SMD_MOVIE_MPEG", fn_5_37C, fn_5_4C8, fn_5_684 },
    { "SMD_MOVIE_BOTTOM", fn_1_12B4, fn_1_12FC, fn_1_1300 },
};

MovieMenuEntry lbl_5_data_F0[63] = {
    {2, 0, 3, "\x81" "E\x83v\x83\x8D\x83\x8D\x81[\x83O"},
    {2, 1, 4, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82PA"},
    {2, 2, 5, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82PB"},
    {2, 3, 6, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82QA"},
    {2, 4, 7, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82QB"},
    {2, 5, 8, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82RA"},
    {2, 6, 9, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82RB"},
    {2, 7, 10, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82SA"},
    {2, 8, 11, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82SB"},
    {2, 9, 12, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82TA"},
    {2, 10, 13, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82TB"},
    {2, 11, 14, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82UA"},
    {2, 12, 15, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82UB"},
    {2, 13, 16, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82VA"},
    {2, 14, 17, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82VB"},
    {2, 15, 18, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82WA"},
    {2, 16, 19, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82WB"},
    {2, 17, 20, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82XA"},
    {2, 18, 21, "\x81" "E\x83V\x83i\x83\x8A\x83I\x81@\x82XB"},
    {2, 19, 30, "\x81" "E\x83G\x83\x93\x83" "f\x83" "B\x83\x93\x83O"},
    {2, 20, 31, "\x81" "E\x83L\x83\x83\x83v\x83`\x83\x83\x81[\x83" "e\x83X\x83g"},
    {14, 0, 40, "\x81" "EE)\x83" "f\x83X\x83{\x81[\x83\x93"},
    {14, 1, 41, "\x81" "EE)\x83}\x83" "C\x83" "e\x83" "B\x81[\x83K\x83[\x83\x8B"},
    {14, 2, 42, "\x81" "EE)\x83W\x83\x87\x83" "f\x83" "B\x81[\x83T\x83}\x81["},
    {14, 3, 43, "\x81" "EE)\x83h\x83N\x83^\x81[\x83X\x83`\x83\x85\x83\x8F\x81[\x83g"},
    {14, 4, 44, "\x81" "EE)\x83o\x83o"},
    {14, 5, 45, "\x81" "EE)\x83T\x83\x80\x83\x89\x83" "C\x83S\x83\x8D\x81["},
    {14, 6, 46, "\x81" "EE)\x83s\x83R"},
    {14, 7, 47, "\x81" "EE)\x83L\x83\x83\x83v\x83" "e\x83\x93\x83t\x83@\x83\x8B\x83R\x83\x93"},
    {14, 8, 48, "\x81" "EE)\x83I\x83N\x83g\x83}\x83\x93"},
    {14, 9, 49, "\x81" "EE)Mr.EAD"},
    {14, 10, 50, "\x81" "EE)\x83W\x83" "F\x81[\x83\x80\x83X\x83}\x83N\x83\x89\x83" "E\x83h"},
    {14, 11, 51, "\x81" "EE)\x83r\x83\x8A\x81["},
    {14, 12, 52, "\x81" "EE)\x83P\x83" "C\x83g\x83" "A\x83\x8C\x83\x93"},
    {14, 13, 53, "\x81" "EE)\x83]\x81[\x83_"},
    {14, 14, 54, "\x81" "EE)\x83W\x83\x83\x83" "b\x83N\x83\x8C\x83r\x83\x93"},
    {14, 15, 55, "\x81" "EE)\x83o\x83" "C\x83I\x83\x8C\x83" "b\x83N\x83X"},
    {14, 16, 56, "\x81" "EE)\x83U\x81" "E\x83X\x83J\x83\x8B"},
    {14, 17, 57, "\x81" "EE)\x83" "A\x83\x93\x83g\x83j\x83I\x83K\x83X\x83^\x81["},
    {14, 18, 58, "\x81" "EE)\x83r\x81[\x83X\x83g\x83}\x83\x93"},
    {14, 19, 59, "\x81" "EE)\x83\x8C\x83I\x83\x93"},
    {14, 20, 60, "\x81" "EE)\x83X\x81[\x83p\x81[\x83" "A\x83\x8D\x81["},
    {30, 0, 61, "\x81" "EE)\x83~\x83Z\x83X\x83" "A\x83\x8D\x81["},
    {30, 1, 62, "\x81" "EE)\x83S\x83}\x81[\x81\x95\x83V\x83I\x81["},
    {30, 2, 63, "\x81" "EE)\x83V\x83\x8B\x83o\x81[\x83j\x81[\x83\x8B\x83Z\x83\x93"},
    {30, 3, 64, "\x81" "EE)\x83}\x83" "C\x83P\x83\x8B\x83`\x83" "F\x81[\x83\x93"},
    {30, 4, 65, "\x81" "EE)\x83u\x83\x89\x83" "b\x83h\x83t\x83@\x83\x8B\x83R\x83\x93"},
    {30, 5, 66, "\x81" "EE)\x83W\x83\x87\x83\x93\x83^\x83i\x83J"},
    {30, 6, 67, "\x81" "EE)\x83h\x83\x89\x83N"},
    {30, 7, 68, "\x81" "EE)\x83\x8D\x83W\x83\x83\x81[\x83o\x83X\x83^\x81["},
    {30, 8, 69, "\x81" "EE)\x83h\x83N\x83^\x81[\x83N\x83\x89\x83" "b\x83V\x83\x85"},
    {30, 9, 70, "\x81" "EE)\x83u\x83\x89\x83" "b\x83N\x83V\x83\x83\x83h\x81["},
    {30, 10, 71, "\x81" "EE)\x83h\x83\x93\x83W\x81[\x83j\x81["},
    {30, 11, 72, "\x81" "EE)\x83" "f\x83W\x83{\x81[\x83" "C"},
    {30, 12, 73, "\x81" "EE)\x83_\x83" "C\x83T\x83\x93\x83Q\x83\x93"},
    {30, 13, 74, "\x81" "EE)\x83X\x83y\x81[\x83h"},
    {30, 14, 75, "\x81" "EE)\x83_\x83" "C\x83S\x83\x8D\x81["},
    {30, 15, 76, "\x81" "EE)\x83v\x83\x8A\x83\x93\x83V\x83" "A\x83\x89\x83\x82\x81[\x83h"},
    {30, 16, 77, "\x81" "EE)\x83\x8A\x83\x8A\x81[\x83t\x83\x89\x83" "C\x83\x84\x81["},
    {30, 17, 78, "\x81" "EE)PJ"},
    {30, 18, 79, "\x81" "EE)QQQ"},
    {30, 19, 80, "\x81" "EE)\x83t\x83" "F\x83j\x83" "b\x83N\x83X"},
    {0, 0, -1, ""},
};

/* fzgx:begin fn_5_320 */
void fn_5_320(void) {
    MovieTask *task;

    task = lbl_5_data_40;
    task += lbl_1_bss_962 - 129;
    lbl_1_bss_71688 = (u32)task->main;
    lbl_1_bss_7168C = (u32)task->disp;
    task->init();
}
/* fzgx:end fn_5_320 */

/* fzgx:begin fn_5_37C */
void fn_5_37C(void) {
    s8 subtitles;

    sMode = 0;
    sPauseReq = 0;
    sWork = 0;
    sDeflicker = 1;
    sWidth = lbl_1_bss_58.width;
    sHeight = lbl_1_bss_58.height;
    sPosX = lbl_1_bss_58.x;
    sPosY = lbl_1_bss_58.y;
    sScaleX = lbl_1_bss_58.scaleX;
    sScaleY = lbl_1_bss_58.scaleY;
    sKind = lbl_1_bss_58.unk_3;
    sLanguage = lbl_1_bss_58.unk_0;
    sFurigana = lbl_1_bss_58.unk_1;
    sBackground = lbl_1_bss_58.unk_2;
    sSkipMask = lbl_1_bss_58.unk_14;
    sLogo = lbl_1_bss_58.unk_16;
    sPadPort = lbl_1_bss_58.unk_17;
    sVolume = lbl_1_bss_58.unk_18;
    if (sBackground) {
        fn_1_47F74(0x9a);
        fn_1_47F74(0x9b);
        fn_1_47F74(0x93);
        fn_1_411A4(1);
    }
    if (sLogo) {
        fn_1_47F74(1);
    }
    sSubtitles = sLanguage == 0 ? (s8)fn_1_FA638() : 1;
    lbl_1_bss_58.unk_1C = 0;
    if (sKind == 2) {
        lbl_1_bss_970.unk_0 = 1;
    }
    fn_5_169C();
}
/* fzgx:end fn_5_37C */

/* fzgx:begin fn_5_4C8 */
static inline u16 padWord(u16 *field, s32 port) {
    port *= sizeof(PadInput) / sizeof(u16);
    field += port;
    return *field;
}

void fn_5_4C8(void) {
    u32 flags;
    s32 a;
    s32 b;
    s32 y;
    s32 x;

    if (sMode == 1 || sMode == 0) {
        flags = 0;
        if (sFadeMode == 1) {
            x = 0;
            y = 0;
            b = 0;
            a = 0;
        } else if (!(sPadPort < 0 || sPadPort >= 4)) {
            u16 buttons = padWord(&lbl_1_bss_9F8->unk_8, sPadPort);
            a = (buttons >> 8) & 1;
            b = (buttons >> 9) & 1;
            x = (buttons >> 4) & 1;
            y = (buttons >> 12) & 1;
        } else {
            u16 buttons = lbl_1_bss_9F8[0].unk_8;
            a = (buttons >> 8) & 1;
            b = (buttons >> 9) & 1;
            x = (buttons >> 4) & 1;
            y = (buttons >> 12) & 1;
        }
        if ((sSkipMask & 1) && a != 0) {
            flags |= 1;
        } else if ((sSkipMask & 2) && b != 0) {
            flags |= 2;
        } else if ((sSkipMask & 4) && y != 0) {
            flags |= 4;
        }
        if (x != 0) {
            sSubtitles = !sSubtitles;
            fn_1_FA650();
        }
        if (flags != 0) {
            fn_5_3C44();
            lbl_1_bss_58.unk_1C = flags;
        }
    } else if (sMode == -1) {
        if (lbl_1_bss_964 == 15) {
            sMode = 2;
            fn_1_4A00(0, 15, sHeap1);
        } else {
            fn_5_3C44();
        }
    } else if (sMode == 2) {
        if (fn_1_4C10() == 0) {
            fn_5_3C44();
        }
    } else if (sMode != 0) {
        lbl_1_bss_968 = lbl_1_bss_964;
    }
}
/* fzgx:end fn_5_4C8 */

/* fzgx:begin fn_5_684 */
void fn_5_684(void) {
    if (sBackground != 0) {
        fn_1_48140(154);
        fn_1_48140(155);
        fn_1_48140(147);
        fn_1_412A0(1);
    }
    if (sLogo != 0) {
        fn_1_48140(1);
    }
}
/* fzgx:end fn_5_684 */

/* fzgx:begin fn_5_6E8 */
void fn_5_6E8(void) {
    f32 one;

    one = 1.0f;
    sMode = -2;
    sPauseReq = 0;
    sWork = 0;
    sLanguage = lbl_801A66B4;
    sFurigana = 1;
    sPosX = 0;
    sPosY = 0;
    sScaleX = one;
    sScaleY = one;
    sDeflicker = 1;
    sBackground = 0;
    sVolume = -1;
    sSubtitles = 1;
    lbl_1_bss_970.unk_4 = 0;
    fn_1_47F74(154);
    fn_1_47F74(155);
    fn_1_47F74(147);
    fn_1_411A4(1);
    fn_8006CE1C(0.0f);
}
/* fzgx:end fn_5_6E8 */

/* fzgx:begin fn_5_7A0 */
#define CUR_ID (lbl_5_data_F0[lbl_1_bss_970.unk_4].id)

void fn_5_7A0(void) {
    s32 delta;
    s8 v;
    MoviePlayer *player;

    if (sMode == 1) {
        if (sPauseReq != 0) {
            sPauseReq = 0;
            player = sPlayer;
            player->vtbl->setPause(player, 0);
        }
    } else if (sMode == -1) {
        fn_5_3C44();
    } else if (fn_1_157920() == 0 && sMode == -2) {
        delta = 0;
        if (__rlwinm(lbl_1_bss_D58.unk_8, 28, 31, 31)) {
            sLanguage++;
            v = sLanguage;
            sLanguage = (v > 5) ? -1 : v;
        }
        fn_5_1404(lbl_5_data_F0);
        if (__rlwinm(lbl_1_bss_D58.unk_10, 29, 31, 31) || __rlwinm(lbl_1_bss_D58.unk_12, 29, 31, 31)) {
            delta = -1;
        } else if (__rlwinm(lbl_1_bss_D58.unk_10, 30, 31, 31) || __rlwinm(lbl_1_bss_D58.unk_12, 30, 31, 31)) {
            delta = 1;
        }
        if (!__rlwinm(lbl_1_bss_D58.unk_2, 23, 31, 31)) {
            if (__rlwinm(lbl_1_bss_D58.unk_10, 31, 31, 31) || __rlwinm(lbl_1_bss_D58.unk_12, 31, 31, 31)) {
                delta += 21;
            } else if (__rlwinm(lbl_1_bss_D58.unk_10, 0, 31, 31) || __rlwinm(lbl_1_bss_D58.unk_12, 0, 31, 31)) {
                delta -= 21;
            }
        }
        if (delta != 0) {
            lbl_1_bss_970.unk_4 = (lbl_1_bss_970.unk_4 + (u32)delta + 62) % 62;
        }
    }

    if (sMode != -2 && __rlwinm(lbl_1_bss_D58.unk_8, 23, 31, 31)) {
        fn_1_157940();
        ADXT_Stop(*lbl_1_bss_6EAD0.unk_0);
        fn_5_3C44();
    }

    if (__rlwinm(lbl_1_bss_D58.unk_8, 22, 31, 31)) {
        sDeflicker = 1 - sDeflicker;
        fn_80070704(sDeflicker);
    }
    if (__rlwinm(lbl_1_bss_D58.unk_8, 21, 31, 31)) {
        sFurigana = 1 - sFurigana;
    }
    if (__rlwinm(lbl_1_bss_D58.unk_A, 24, 31, 31)) {
        sBackground = 1 - sBackground;
    }

    if (__rlwinm(lbl_1_bss_D58.unk_2, 24, 31, 31)) {
        if (__rlwinm(lbl_1_bss_D58.unk_10, 29, 31, 31) || __rlwinm(lbl_1_bss_D58.unk_12, 29, 31, 31)) {
            sScaleX += 0.1f;
            sScaleY += 0.1f;
        } else if (__rlwinm(lbl_1_bss_D58.unk_10, 30, 31, 31) || __rlwinm(lbl_1_bss_D58.unk_12, 30, 31, 31)) {
            sScaleX -= 0.1f;
            sScaleY -= 0.1f;
        }
    }

    if (__rlwinm(lbl_1_bss_D58.unk_2, 23, 31, 31)) {
        if (__rlwinm(lbl_1_bss_D58.unk_10, 29, 31, 31) || __rlwinm(lbl_1_bss_D58.unk_12, 29, 31, 31)) {
            sPosY -= 8.0f;
        } else if (__rlwinm(lbl_1_bss_D58.unk_10, 30, 31, 31) || __rlwinm(lbl_1_bss_D58.unk_12, 30, 31, 31)) {
            sPosY += 8.0f;
        }
        if (__rlwinm(lbl_1_bss_D58.unk_10, 31, 31, 31) || __rlwinm(lbl_1_bss_D58.unk_12, 31, 31, 31)) {
            sPosX += 8.0f;
        } else if (__rlwinm(lbl_1_bss_D58.unk_10, 0, 31, 31) || __rlwinm(lbl_1_bss_D58.unk_12, 0, 31, 31)) {
            sPosX -= 8.0f;
        }
    }

    if (__rlwinm(lbl_1_bss_D58.unk_8, 24, 31, 31)) {
        if (sMode != -2) {
            fn_5_3C44();
        }
        switch (CUR_ID) {
        case 3: fn_80083DB0(lbl_1_bss_198[0], "movie/story00"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 4: fn_80083DB0(lbl_1_bss_198[0], "movie/story01A"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 5: fn_80083DB0(lbl_1_bss_198[0], "movie/story01B"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 6: fn_80083DB0(lbl_1_bss_198[0], "movie/story02A"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 7: fn_80083DB0(lbl_1_bss_198[0], "movie/story02B"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 8: fn_80083DB0(lbl_1_bss_198[0], "movie/story03A"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 9: fn_80083DB0(lbl_1_bss_198[0], "movie/story03B"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 10: fn_80083DB0(lbl_1_bss_198[0], "movie/story04A"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 11: fn_80083DB0(lbl_1_bss_198[0], "movie/story04B"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 12: fn_80083DB0(lbl_1_bss_198[0], "movie/story05A"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 13: fn_80083DB0(lbl_1_bss_198[0], "movie/story05B"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 14: fn_80083DB0(lbl_1_bss_198[0], "movie/story06A"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 15: fn_80083DB0(lbl_1_bss_198[0], "movie/story06B"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 16: fn_80083DB0(lbl_1_bss_198[0], "movie/story07A"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 17: fn_80083DB0(lbl_1_bss_198[0], "movie/story07B"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 18: fn_80083DB0(lbl_1_bss_198[0], "movie/story08A"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 19: fn_80083DB0(lbl_1_bss_198[0], "movie/story08B"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 20: fn_80083DB0(lbl_1_bss_198[0], "movie/story09A"); goto single; /* fzgx-allow: S1 cases 3-21 share the single-movie tail */
        case 21:
            fn_80083DB0(lbl_1_bss_198[0], "movie/story09B");
        single:
            fn_80083DB0(lbl_1_bss_198[1], "end");
            sKind = 0;
            sVolume = -1;
            sScaleX = 1.0f;
            sScaleY = 1.0f;
            sWidth = 0x280;
            sHeight = 0x150;
            sPosX = 0;
            sPosY = 0;
            sDeflicker = 1;
            break;
        case 30:
            fn_80083DB0(lbl_1_bss_198[0], "MAXON");
            fn_80083DB0(lbl_1_bss_198[1], "BGMED");
            fn_80083DB0(lbl_1_bss_198[2], "movie/story09B");
            fn_80083DB0(lbl_1_bss_198[3], "STRL");
            fn_80083DB0(lbl_1_bss_198[4], "MAXOFF");
            fn_80083DB0(lbl_1_bss_198[5], "WAIT_0100");
            fn_80083DB0(lbl_1_bss_198[6], "CUT0010");
            fn_80083DB0(lbl_1_bss_198[7], "movie/story01B");
            fn_80083DB0(lbl_1_bss_198[8], "CUT0140");
            fn_80083DB0(lbl_1_bss_198[9], "movie/story02B");
            fn_80083DB0(lbl_1_bss_198[10], "CUT0010");
            fn_80083DB0(lbl_1_bss_198[11], "movie/story03B");
            fn_80083DB0(lbl_1_bss_198[12], "CUT0065");
            fn_80083DB0(lbl_1_bss_198[13], "movie/story04B");
            fn_80083DB0(lbl_1_bss_198[14], "CUT0070");
            fn_80083DB0(lbl_1_bss_198[15], "movie/story05B");
            fn_80083DB0(lbl_1_bss_198[16], "CUT0080");
            fn_80083DB0(lbl_1_bss_198[17], "movie/story06B");
            fn_80083DB0(lbl_1_bss_198[18], "CUT1190");
            fn_80083DB0(lbl_1_bss_198[19], "movie/story07B");
            fn_80083DB0(lbl_1_bss_198[20], "CUT0000");
            fn_80083DB0(lbl_1_bss_198[21], "movie/story08B");
            fn_80083DB0(lbl_1_bss_198[22], "BGMOU_0500_0500");
            fn_80083DB0(lbl_1_bss_198[23], "WAIT_1200");
            fn_80083DB0(lbl_1_bss_198[24], "end");
            sKind = 2;
            lbl_1_bss_970.unk_0 = 1;
            sWidth = 0x280;
            lbl_1_bss_58.width = 0x280;
            sHeight = 0x150;
            lbl_1_bss_58.height = 0x150;
            sScaleX = 0.5f;
            lbl_1_bss_58.scaleX = 0.5f;
            sScaleY = 0.5f;
            lbl_1_bss_58.scaleY = 0.5f;
            sPosX = 0x88;
            lbl_1_bss_58.x = 0x88;
            sPosY = 0;
            lbl_1_bss_58.y = 0;
            sLanguage = -1;
            sFurigana = 0;
            sDeflicker = 1;
            sVolume = 0;
            break;
        case 31:
            fn_80083DB0(lbl_1_bss_198[0], "STRL");
            fn_80083DB0(lbl_1_bss_198[1], "CAP01_0900");
            fn_80083DB0(lbl_1_bss_198[2], "CAP02_0900");
            fn_80083DB0(lbl_1_bss_198[3], "CAP03_0900");
            fn_80083DB0(lbl_1_bss_198[4], "CAP04_0900");
            fn_80083DB0(lbl_1_bss_198[5], "CAP05_0900");
            fn_80083DB0(lbl_1_bss_198[6], "CAP06_0900");
            fn_80083DB0(lbl_1_bss_198[7], "end");
            sWidth = 0x140;
            sHeight = 0xF0;
            if (sBackground != 0) {
                sPosX = 0;
            } else {
                sPosX = 0x88;
            }
            sVolume = -1;
            sScaleX = 1.0f;
            sScaleY = 1.0f;
            sKind = 1;
            sPosY = 0;
            sDeflicker = 1;
            break;
        case 40: case 41: case 42: case 43: case 44: case 45: case 46: case 47:
        case 48: case 49: case 50: case 51: case 52: case 53: case 54: case 55:
        case 56: case 57: case 58: case 59: case 60: case 61: case 62: case 63:
        case 64: case 65: case 66: case 67: case 68: case 69: case 70: case 71:
        case 72: case 73: case 74: case 75: case 76: case 77: case 78: case 79:
        case 80:
            fn_80083DB0(lbl_1_bss_198[0], "STRL");
            fn_80083DB0(lbl_1_bss_198[1], "WAIT_0200");
            sprintf(lbl_1_bss_198[2], "BMP%02d_0300", CUR_ID - 40);
            fn_80083DB0(lbl_1_bss_198[3], "BGMINM0120_0240");
            sprintf(lbl_1_bss_198[4], "movie/ending/%s", lbl_1_data_370[CUR_ID - 40]);
            fn_80083DB0(lbl_1_bss_198[5], "WAIT_0200");
            fn_80083DB0(lbl_1_bss_198[6], "CAP01_0900");
            fn_80083DB0(lbl_1_bss_198[7], "WAIT_0200");
            fn_80083DB0(lbl_1_bss_198[8], "CAP02_0900");
            fn_80083DB0(lbl_1_bss_198[9], "WAIT_0200");
            fn_80083DB0(lbl_1_bss_198[10], "CAP03_0900");
            fn_80083DB0(lbl_1_bss_198[11], "WAIT_0200");
            fn_80083DB0(lbl_1_bss_198[12], "CAP04_0900");
            fn_80083DB0(lbl_1_bss_198[13], "WAIT_0200");
            fn_80083DB0(lbl_1_bss_198[14], "CAP05_0900");
            fn_80083DB0(lbl_1_bss_198[15], "WAIT_0200");
            fn_80083DB0(lbl_1_bss_198[16], "CAP06_0900");
            fn_80083DB0(lbl_1_bss_198[17], "STRLWAIT");
            fn_80083DB0(lbl_1_bss_198[18], "BGMOU_0200_0500");
            fn_80083DB0(lbl_1_bss_198[19], "WAIT_0600");
            fn_80083DB0(lbl_1_bss_198[20], "end");
            sWidth = 0x140;
            sHeight = 0xF0;
            if (sBackground != 0) {
                sPosX = 0;
            } else {
                sPosX = 0x88;
            }
            sVolume = -1;
            sScaleX = 1.0f;
            sScaleY = 1.0f;
            sKind = 1;
            sPosY = 0;
            sDeflicker = 1;
            break;
        }
        fn_5_169C();
    }

    if (__rlwinm(lbl_1_bss_D58.unk_8, 20, 31, 31) && !__rlwinm(lbl_1_bss_D58.unk_2, 23, 31, 31)) {
        lbl_1_bss_968 = 10;
    }
}
/* fzgx:end fn_5_7A0 */

/* fzgx:begin fn_5_13B0 */
void fn_5_13B0(void) {
    if (sMode != -2) {
        fn_5_3C44();
    }
    fn_1_48140(154);
    fn_1_48140(155);
    fn_1_48140(147);
    fn_1_412A0(1);
}
/* fzgx:end fn_5_13B0 */

/* fzgx:begin fn_5_1404 */
void fn_5_1404(MovieMenuEntry *menu) {
    MovieMenuEntry *entry;
    s32 i;
    f32 x;
    f32 y;

    fn_1_49410();
    fn_1_4955C(0.5f, 0.5f);
    {
        GXColor color = {0x80, 0xFF, 0x80, 0xFF};
        fn_1_49514(&color);
    }
    for (entry = menu, i = 0; entry->id != -1; entry++, i++) {
        x = entry->x * 12 + 50;
        y = entry->y * 12 + 50;
        fn_1_496FC(x, y);
        fn_1_4AE0C("%s", entry->name);
        if (i == lbl_1_bss_970.unk_4) {
            fn_1_496FC(x - 12.0f - 4.0f, y);
            {
                GXColor color = {0xFF, 0x00, 0x00, 0xFF};
                fn_1_49514(&color);
            }
            fn_1_4A0D8("\x81\x84");
            {
                GXColor color = {0x80, 0xFF, 0x80, 0xFF};
                fn_1_49514(&color);
            }
        }
    }
    {
        GXColor color = {0xFF, 0xFF, 0x80, 0xFF};
        fn_1_49514(&color);
    }
    fn_1_496FC(80.0f, 360.0f);
    fn_1_4955C(0.6f, 0.6f);
    fn_1_4965C(2);
    fn_1_4AE0C("\x83" "f\x83t\x83\x8A\x83" "b\x83J\x81[ : %-3s     ( CHANGE:X )\n", sDeflicker ? "ON" : "OFF");
    fn_1_4AE0C("\x83X\x83P\x81[\x83\x8B   : %3.1f     ( CHANGE:L\x83g\x83\x8A\x83K\x81[+\x83p\x83" "b\x83hUD )\n", sScaleX);
    fn_1_4AE0C("\x83|\x83W\x83V\x83\x87\x83\x93  : %3d,%3d ( CHANGE:R\x83g\x83\x8A\x83K\x81[+\x83p\x83" "b\x83h )\n", sPosX, sPosY);
    fn_1_4AE0C("\x82\xB0\x82\xF1\x82\xB2    : %8s( CHANGE:Z )\n",
               sLanguage == 5 ? "JAPANESE" :
               sLanguage == 0 ? "ENGLISH " :
               sLanguage == 1 ? "GERMAN  " :
               sLanguage == 2 ? "FRENCH  " :
               sLanguage == 3 ? "SPANISH " :
               sLanguage == 4 ? "ITALIAN " : "");
    fn_1_4AE0C("\x82\xD3\x82\xE8\x82\xAA\x82\xC8   : %-3s     ( CHANGE:Y )\n", sFurigana ? "ON" : "OFF");
    fn_1_4AE0C("\x94w\x8Ci     : %-3s     ( CHANGE:L )\n", sBackground ? "ON" : "OFF");
}
/* fzgx:end fn_5_1404 */

/* fzgx:begin fn_5_169C */
void fn_5_169C(void) {
    MovieCommand *command;
    s16 pending;
    s8 i;
    u32 size;
    MovieLoadResult result;
    MovieConfig config;
    MovieInit init;
    char path[32];

    pending = 0;
    GXInvalidateTexAll();
    sFadeMode = 0;
    sFade = 1.0f;
    sFadeStep = 0.0f;
    sTexSizeY = (GXGetTexBufferSize(sWidth, sHeight, 1, 0, 0) + 31) & ~31;
    sTexSizeUV = (GXGetTexBufferSize(sWidth / 2, sHeight / 2, 3, 0, 0) + 31) & ~31;
    for (i = 0; i < 2; i++) {
        sPlaneY[i] = fn_1_45D0(lbl_801A6410, sTexSizeY, "movie.c", 0x432);
        sPlaneUV[i] = fn_1_45D0(lbl_801A6410, sTexSizeUV, "movie.c", 0x433);
        DCInvalidateRange(sPlaneY[i], sTexSizeY);
        DCInvalidateRange(sPlaneUV[i], sTexSizeUV);
        fn_80008BEC(sPlaneY[i], 0, sTexSizeY);
        fn_80008BEC(sPlaneUV[i], 0x80, sTexSizeUV);
    }
    GXInitTexObj(&sTexY, sPlaneY[0], sWidth, sHeight, 1, 0, 0, 0);
    GXInitTexObj(&sTexUV, sPlaneUV[0], sWidth / 2, sHeight / 2, 3, 0, 0, 0);
    GXInitTexObjLOD(&sTexY, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    GXInitTexObjLOD(&sTexUV, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    if (lbl_1_bss_964 != 15) {
        sCaptureSize = (GXGetTexBufferSize(320, 224, 1, 0, 0) + 31) & ~31;
        sCapture = fn_1_45D0(lbl_801A6410, sCaptureSize, "movie.c", 0x441);
        DCInvalidateRange(sCapture, sCaptureSize);
    } else {
        sCapture = 0;
    }
    fn_80008BEC(&init, 0, 0x20);
    init.rate = 59.94f;
    init.unk_4 = 1;
    init.unk_8 = 1;
    init.unk_C = 0;
    lbl_1_bss_194(&init);
    fn_80008BEC(&config, 0, 0x30);
    config.unk_20 = 0;
    config.unk_0 = 1;
    config.unk_4 = 0xC00000;
    config.unk_8 = 640;
    config.unk_C = 448;
    config.unk_10 = 3;
    config.unk_14 = 4;
    config.unk_1C = lbl_1_bss_18C(&config);
    config.unk_18 = fn_1_45D0(lbl_801A6410, config.unk_1C, "movie.c", 0x459);
    sPlayer = lbl_1_bss_188(&config);
    sWork = config.unk_18;
    fn_80008BEC(&sFrame, 0, 0x4C);
    sLineCount = 0;
    command = sCommands;
    while (fn_80083BCC(lbl_1_bss_198[sLineCount], "end") != 0) {
        char language[2] = "";
        command->type = 0;
        if (strncmp(lbl_1_bss_198[sLineCount], "CUT", 3) == 0) {
            pending = fn_5_2C54((u8 *)lbl_1_bss_198[sLineCount], 3, 4);
            command->type = 0;
            command->arg = 0;
            command->duration = 0;
        } else if (strncmp(lbl_1_bss_198[sLineCount], "STRLWAIT", 8) == 0) {
            command->type = 11;
            command->arg = 0;
            command->duration = 0;
        } else if (strncmp(lbl_1_bss_198[sLineCount], "STRL", 4) == 0) {
            command->type = 10;
            command->arg = 0;
            command->duration = 0;
        } else if (strncmp(lbl_1_bss_198[sLineCount], "MAX", 3) == 0) {
            if (strncmp(lbl_1_bss_198[sLineCount], "MAXON", 5) == 0) {
                command->type = 9;
                command->arg = 1;
                command->duration = 0;
            } else {
                command->type = 9;
                command->arg = 0;
                command->duration = 0;
            }
        } else if (strncmp(lbl_1_bss_198[sLineCount], "WAIT_", 5) == 0) {
            command->type = 1;
            command->arg = 0;
            command->duration = fn_5_2C54((u8 *)lbl_1_bss_198[sLineCount], 5, 4);
        } else if (strncmp(lbl_1_bss_198[sLineCount], "BMP", 3) == 0) {
            command->type = 3;
            command->arg = fn_5_2C54((u8 *)lbl_1_bss_198[sLineCount], 3, 2);
            command->duration = fn_5_2C54((u8 *)lbl_1_bss_198[sLineCount], 6, 4);
        } else if (strncmp(lbl_1_bss_198[sLineCount], "CAP", 3) == 0) {
            command->type = 4;
            command->arg = fn_5_2C54((u8 *)lbl_1_bss_198[sLineCount], 3, 2) - 1;
            command->duration = fn_5_2C54((u8 *)lbl_1_bss_198[sLineCount], 6, 4);
        } else if (strncmp(lbl_1_bss_198[sLineCount], "BGM", 3) == 0) {
            if (strncmp(lbl_1_bss_198[sLineCount], "BGMED", 5) == 0) {
                command->type = 5;
                command->arg = 0;
                command->duration = 0;
            } else {
                if (strncmp(lbl_1_bss_198[sLineCount], "BGMINM", 6) == 0) {
                    command->type = 7;
                } else if (strncmp(lbl_1_bss_198[sLineCount], "BGMIN", 5) == 0) {
                    command->type = 6;
                } else if (strncmp(lbl_1_bss_198[sLineCount], "BGMOU", 5) == 0) {
                    command->type = 8;
                }
                command->arg = fn_5_2C54((u8 *)lbl_1_bss_198[sLineCount], 6, 4);
                command->duration = fn_5_2C54((u8 *)lbl_1_bss_198[sLineCount], 11, 4);
            }
        } else {
            sprintf(sMovieFiles[sLineCount], "%s.sfd", lbl_1_bss_198[sLineCount]);
            command->type = 2;
            command->arg = 0;
            command->duration = pending;
            pending = 0;
            if (sLanguage != -1) {
                switch (sLanguage) {
                case 0: language[0] = 'e'; break;
                case 1: language[0] = 'g'; break;
                case 2: language[0] = 'f'; break;
                case 4: language[0] = 'i'; break;
                default: language[0] = 0; break;
                }
                sprintf(path, "%s%s.txt", lbl_1_bss_198[sLineCount], language);
                if (fn_1_45730(path, &result) == 0) {
                    sSubtitleFiles[sLineCount] = NULL;
                } else {
                    size = (fn_1_45B2C(&result) + 31) & ~31;
                    if (sSubtitleFiles[sLineCount] != NULL) {
                        OSPanic("movie.c", 0x4C7, "QA");
                    }
                    sSubtitleFiles[sLineCount] = fn_1_4630(lbl_801A6410, size, "movie.c", 0x4C8);
                    fn_1_458A0(&result, sSubtitleFiles[sLineCount], size, 0);
                }
            }
        }
        command++;
        sLineCount++;
    }
    command->type = 12;
    command->arg = 0;
    command->duration = 0;
    if (VIGetNextField() != 0) {
        VIWaitForRetrace();
    }
    fn_1_435C(sHeap2);
    fn_1_3F8C("movie_mpeg_play_main", fn_5_20FC, 0, 1);
    fn_1_435C(sHeap3);
    fn_1_3F8C("movie_mpeg_play_disp", fn_5_2E00, 0, 1);
    fn_80070704(sDeflicker);
    sFadeMode = 0;
    sFade = 1.0f;
    sFadeStep = 0.0f;
    sStaffRoll = 0;
    sCmdIndex = -1;
    sAdvance = 1;
    sMode = 0;
}
/* fzgx:end fn_5_169C */

/* fzgx:begin fn_5_20FC */
void fn_5_20FC(void) {
    u16 maxDuration;
    MovieCommand *command;
    u32 aram;
    MovieSubtitle subtitle;
    u16 duration;
    f32 frameScale;
    f32 textY;
    s16 start, end;

    maxDuration = 0;

    if (sAdvance != 0) {
        sCmdIndex++;
        if (sCmdIndex >= 30) {
            sCmdIndex = 29;
            sCommands[29].type = 12;
        }
        command = &sCommands[sCmdIndex];
        switch (command->type) {
        case 11:
            sAdvance = 0;
            break;
        case 10:
            if (sStaffRoll == 0) {
                fn_1_1577D0(0, 0, 0.75f);
                fn_1_435C(sHeap0);
                fn_1_3F8C("StaffRollMain", fn_1_157820, 0, 2);
                fn_1_435C(sHeap1);
                fn_1_3F8C("StaffRollDisp", fn_1_1578C4, 0, 2);
                sStaffRoll = 1;
            }
            break;
        case 9:
            if (command->arg != 0) {
                sWidth = 640;
                sHeight = 336;
                sPosX = 0;
                sPosY = 0;
                sScaleX = 1.0f;
                sScaleY = 1.0f;
            } else {
                sWidth = lbl_1_bss_58.width;
                sHeight = lbl_1_bss_58.height;
                sPosX = lbl_1_bss_58.x;
                sPosY = lbl_1_bss_58.y;
                sScaleX = lbl_1_bss_58.scaleX;
                sScaleY = lbl_1_bss_58.scaleY;
            }
            break;
        case 1:
            sTimer = command->duration;
            sAdvance = 0;
            break;
        case 2:
            sPlayer->vtbl->start(sPlayer, sMovieFiles[sCmdIndex]);
            sFadeMode = 1;
            sFade = 0.0f;
            sFadeStep = 0.016666668f;
            sMode = 1;
            sAdvance = 0;
            break;
        case 3:
            sFadeMode = 1;
            sFade = 0.0f;
            sFadeStep = 0.016666668f;
            sTimer = command->duration;
            sAdvance = 0;
            break;
        case 4:
            sFadeMode = 1;
            sFade = 0.0f;
            sFadeStep = 0.016666668f;
            sTimer = command->duration;
            sAdvance = 0;
            aram = 0xF24000;
            aram += command->arg * sCaptureSize;
            DCInvalidateRange(sCapture, sCaptureSize);
            ARQPostRequest(&sArq, 0, 1, 1, aram, sCapture, sCaptureSize, 0);
            GXInvalidateTexAll();
            break;
        case 5:
            sBgmId = 49;
            sBgmSync = 1;
            sBgmMode = 4;
            fn_1_A1588(*lbl_1_bss_6EAD0.unk_0, 49);
            ADXT_Pause(*lbl_1_bss_6EAD0.unk_0, 1);
            sBgmWait = 0;
            break;
        case 7:
            sBgmId = 40;
            sBgmSync = 1;
            sBgmMode = 2;
            sBgmWait = command->arg;
            sBgmFade = command->duration;
            break;
        case 6:
            sBgmId = 40;
            sBgmSync = 0;
            sBgmMode = 1;
            sBgmWait = command->arg;
            sBgmFade = command->duration;
            break;
        case 8:
            sBgmSync = 0;
            sBgmMode = 3;
            sBgmWait = command->arg;
            sBgmFade = command->duration;
            break;
        case 12:
            sMode = -1;
            lbl_1_bss_970.unk_0 = 1;
            break;
        }
    } else {
        command = &sCommands[sCmdIndex];
    }
    switch (command->type) {
    case 11:
        if (fn_1_157930() != 0) {
            sAdvance = 1;
        }
        break;
    case 1:
        if (sTimer > 0) {
            sTimer--;
        } else {
            sAdvance = 1;
        }
        break;
    case 3:
        if (sTimer == 60) {
            sFadeMode = 2;
            sFade = 1.0f;
            sFadeStep = 0.016666668f;
        }
        if (sTimer > 0) {
            sTimer--;
        } else {
            sAdvance = 1;
        }
        break;
    case 4:
        if (sTimer == 60) {
            sFadeMode = 2;
            sFade = 1.0f;
            sFadeStep = 0.016666668f;
        }
        if (sTimer > 0) {
            sTimer--;
        } else {
            sAdvance = 1;
        }
        break;
    case 2:
        lbl_1_bss_184(sPlayer, &sFrame);
        fn_5_3E54(sCmdIndex);
        frameScale = 30000.0f / sFrame.rate;
        while (sSubtitleText != 0) {
            fn_5_3E74(&subtitle);
            start = subtitle.start * frameScale;
            end = frameScale * (subtitle.start + subtitle.length);
            duration = end - start;
            if (start > sFrame.frame || sFrame.frame >= end) {
                continue;
            }
            textY = ((s8)fn_1_A5DC4() ? 360 : 334);
            maxDuration = duration > maxDuration ? duration : maxDuration;
            if (!sSubtitles) {
                continue;
            }
            fn_1_49410();
            fn_1_495FC();
            fn_1_495B0(0x80000000);
            if (sLanguage == 5) {
                fn_1_4965C(4);
            } else {
                fn_1_4965C(2);
                fn_1_4955C(subtitle.size / 32.0f, subtitle.size / 24.0f);
            }
            fn_1_495C8(1);
            fn_1_49590(0.5f);
            fn_1_4AEE8(sFurigana);
            fn_1_4AEC0(1);
            fn_1_496FC(320.0f, textY + ((subtitle.size + 14) * subtitle.line));
            fn_1_4AE0C("%s", subtitle.text);
            fn_1_496FC(321.0f, textY + ((subtitle.size + 14) * subtitle.line));
            fn_1_4AE0C("%s", subtitle.text);
            fn_1_4AEC0(0);
        }
        if (sFrame.valid != 0) {
            GXInvalidateTexAll();
            fn_80036058(&sTexY, sPlaneY[sBufIndex]);
            fn_80036058(&sTexUV, sPlaneUV[sBufIndex]);
            lbl_1_bss_E4(sPlayer, &sFrame, sPlaneY[sBufIndex], sPlaneUV[sBufIndex]);
            DCFlushRangeNoSync(sPlaneY[sBufIndex], sTexSizeY);
            DCFlushRangeNoSync(sPlaneUV[sBufIndex], sTexSizeUV);
            sBufIndex++;
            if (sBufIndex >= 2) {
                sBufIndex = 0;
            }
            lbl_1_bss_180(sPlayer);
            if (sFrame.frame >= lbl_1_bss_170(sPlayer) - command->duration - 30 && !sFadeMode) {
                sFadeMode = 2;
                sFade = 1.0f;
                sFadeStep = 0.016666668f;
            }
        }
        break;
    }
    if (sBgmMode != 0 && (!sBgmSync || sPlayer->vtbl->getState(sPlayer) == 2)) {
        if (sBgmMode == 2) {
            if (sFrame.frame >= lbl_1_bss_170(sPlayer) - sBgmWait / 2) {
                lbl_1_bss_6EAB4 |= 1;
                fn_1_A2A70(1, sBgmFade);
                fn_1_A1588(*lbl_1_bss_6EAD0.unk_0, (u8)sBgmId);
                sBgmMode = 0;
            }
        } else if (sBgmWait > 0) {
            sBgmWait--;
        } else if (sBgmWait == 0) {
            switch (sBgmMode) {
            case 1:
                lbl_1_bss_6EAB4 |= 1;
                fn_1_A2A70(1, sBgmFade);
                fn_1_A1588(*lbl_1_bss_6EAD0.unk_0, (u8)sBgmId);
                break;
            case 3:
                lbl_1_bss_6EAB4 |= 4;
                fn_1_A2A70(4, sBgmFade);
                break;
            case 4:
                ADXT_Pause(*lbl_1_bss_6EAD0.unk_0, 0);
                break;
            }
            sBgmMode = 0;
        }
    }
    switch (sFadeMode) {
    case 1:
        if (sFade + sFadeStep < 1.0f) {
            if (command->type != 2 || sPlayer->vtbl->getState(sPlayer) == 2) {
                sFade += sFadeStep;
            }
        } else {
            sFade = 1.0f;
            sFadeMode = 0;
        }
        if (sVolume == -1 && sMode == 1) {
            sPlayer->vtbl->setVolume(sPlayer, 0);
        } else {
            sPlayer->vtbl->setVolume(sPlayer, sVolume - 999);
        }
        break;
    case 2:
        if (sFade - sFadeStep > 0.0f) {
            sFade -= sFadeStep;
        } else {
            sFade = 0.0f;
            sFadeMode = 0;
            if (sMode == 1) {
                fn_5_3BF8();
            }
            sAdvance = 1;
        }
        if (sVolume == -1 && sMode == 1) {
            sPlayer->vtbl->setVolume(sPlayer, (s32)(500.0f * sFade) - 499);
        } else {
            sPlayer->vtbl->setVolume(sPlayer, sVolume - 999);
        }
        break;
    }
}
/* fzgx:end fn_5_20FC */

/* fzgx:begin fn_5_2C54 */
s16 fn_5_2C54(u8 *text, s8 start, s8 count) {
    s16 value = 0;
    s8 i;

    for (i = 0; i < count; i++) {
        value *= 10;
        value += text[start + i] - '0';
    }
    return value;
}
/* fzgx:end fn_5_2C54 */

/* fzgx:begin fn_5_2E00 */
#define TEMPLATE lbl_1_rodata_26F8
#define FIFO_Z 0.00010000000474974513f

void fn_5_2E00(void) {
    MovieCommand *entry;
    f32 screenW;
    f32 screenH;
    f32 savedAspect;
    s32 x;
    s32 y;
    f32 right;
    f32 left;
    f32 top;
    f32 bottom;
    f32 width;
    s16 h;
    FontDrawPacket loc_128;
    FontDrawPacket loc_D0;
    FontDrawPacket loc_78;
    FontDrawPacket loc_20;

    entry = &sCommands[sCmdIndex];
    if (sBackground != 0) {
        fn_1_134AD4();
        fn_1_13ABA8(0x20000000);
        fn_1_1380F0("Now Playing a Movie. ");
        loc_128 = TEMPLATE;
        loc_128.image = 0x9301;
        loc_128.x = 167.0f;
        loc_128.y = 38.0f;
        loc_128.z = 90.0f;
        loc_128.flags = 10;
        fn_1_4F734(&loc_128);
        fn_1_133DBC(NULL);
    }
    if (sLogo != 0) {
        fn_1_52070(16);
        loc_D0 = TEMPLATE;
        loc_D0.image = 256;
        loc_D0.x = 16.0f;
        loc_D0.y = 464.0f;
        loc_D0.z = 0.01f;
        loc_D0.flags = 13;
        loc_D0.alpha = sFade;
        fn_1_51678(&loc_D0, 256, 0, 0, 250, 34);
        fn_1_4F734(&loc_D0);
        fn_1_52088();
        fn_1_52070(624);
        loc_D0 = TEMPLATE;
        loc_D0.image = 257;
        loc_D0.x = 616.0f;
        loc_D0.y = 424.0f;
        loc_D0.z = 2.0f;
        loc_D0.flags = 7;
        loc_D0.alpha = sFade;
        fn_1_4F734(&loc_D0);
        loc_D0.image = 259;
        loc_D0.alpha = 0.75f * sFade;
        loc_D0.z = 3.0f;
        fn_1_4F734(&loc_D0);
        fn_1_52088();
    }
    if ((s8)fn_1_A5DC4() != 0) {
        screenW = 640.0f;
        screenH = 360.0f;
    } else {
        screenW = 640.0f;
        screenH = 480.0f;
    }
    savedAspect = fn_8006CD40(screenH);
    fn_8006CD50();
    switch (entry->type) {
    case 3:
    case 4:
        fn_1_520A0();
        fn_1_52088();
        x = sPosX + (f32)((screenW - (s16)(sWidth * sScaleX)) / 2.0f);
        h = sHeight;
        y = sPosY + (f32)((screenH - (s16)(h * sScaleX)) / 2.0f);
        loc_78 = TEMPLATE;
        width = (sWidth * sScaleX) / 8.0f;
        loc_78.x = (s16)x;
        loc_78.y = (480.0f * (s16)y) / screenH;
        loc_78.z += 0.1f;
        loc_78.image = 18;
        loc_78.scale_x *= width;
        loc_78.scale_y *= ((480.0f * (h * sScaleY)) / screenH) / 8.0f;
        *(GXColor *)loc_78.color = (GXColor){0, 0, 0, 255};
        fn_1_4E724(&loc_78);
        if (entry->type == 3) {
            loc_78 = TEMPLATE;
            loc_78.y = (480.0f * (s16)y) / screenH;
            loc_78.x = (s16)x;
            loc_78.scale_x *= (sWidth * sScaleX) / 320.0f;
            loc_78.scale_y *= ((480.0f * (sHeight * sScaleY)) / screenH) / 240.0f;
            loc_78.image = entry->arg + 0x8701;
            fn_1_4E724(&loc_78);
        } else if (entry->type == 4) {
            if (entry->arg < fn_1_40ED4()) {
                loc_78 = TEMPLATE;
                loc_78.y = (480.0f * (s16)y) / screenH;
                loc_78.x = (s16)x;
                loc_78.scale_x *= (sWidth * sScaleX) / 320.0f;
                loc_78.scale_y *= ((480.0f * (sHeight * sScaleY)) / screenH) / 224.0f;
                loc_78.color_add[0] = 160;
                loc_78.color_add[1] = 128;
                loc_78.color_add[2] = 80;
                loc_78.color[0] = 160;
                loc_78.color[1] = 160;
                loc_78.color[2] = 160;
                fn_1_4E92C(&loc_78, 1, 320, 224, sCapture);
            }
        }
        fn_1_520CC();
        break;
    case 2:
        if (sPlayer->vtbl->getState(sPlayer) == 2) {
            fn_80074660(2);
            fn_800745A4(0, 1, 4, 60, 0, 125);
            fn_800745A4(1, 1, 4, 60, 0, 125);
            fn_80073678(4);
            fn_80073C6C(0);
            fn_80073C6C(1);
            fn_80073C6C(2);
            fn_80073C6C(3);
            fn_800734A8(0, 0, 1, 255);
            fn_80072C24(0, 15, 8, 14, 2);
            fn_80072D64(0, 0, 0, 0, 0, 0);
            fn_80072CC4(0, 7, 4, 6, 1);
            fn_80072E20(0, 1, 0, 0, 0, 0);
            fn_800735C8(0, 12);
            fn_80073620(0, 28);
            fn_80072AB0(0, 0, 1);
            fn_800734A8(1, 1, 0, 255);
            fn_80072C24(1, 15, 8, 14, 0);
            fn_80072D64(1, 0, 0, 1, 0, 0);
            fn_80072CC4(1, 7, 4, 6, 0);
            fn_80072E20(1, 0, 0, 1, 0, 0);
            fn_800735C8(1, 13);
            fn_80073620(1, 29);
            fn_80072AB0(1, 0, 0);
            fn_800734A8(2, 0, 1, 255);
            fn_80072C24(2, 15, 8, 14, 0);
            fn_80072D64(2, 0, 0, 0, 1, 0);
            fn_80072CC4(2, 7, 4, 6, 0);
            fn_80072E20(2, 1, 0, 0, 1, 0);
            fn_800735C8(2, 14);
            fn_80073620(2, 30);
            fn_80072AB0(2, 0, 2);
            fn_800734A8(3, 255, 255, 255);
            fn_80072C24(3, 0, 1, 14, 15);
            fn_80072D64(3, 0, 0, 0, 1, 0);
            fn_80072CC4(3, 7, 7, 7, 7);
            fn_80072E20(3, 0, 0, 0, 1, 0);
            fn_80072AB0(3, 0, 0);
            fn_800735C8(3, 15);
            { GXColorS10 color_18 = {-111, 0, -138, 68};
              fn_8003726C(1, &color_18); }
            { GXColor color_14 = {102, 0, 255, 50};
              fn_800736C0(0, &color_14); }
            { GXColor color_10 = {148, 0, 148, 148};
              fn_800736C0(1, &color_10); }
            { GXColor color_C = {203, 0, 5, 207};
              fn_800736C0(2, &color_C); }
            { GXColor color_8 = {0, 255, 0, 0};
              fn_800736C0(3, &color_8); }
            fn_800729B0(0, 0, 1, 2, 3);
            fn_800729B0(1, 0, 3, 3, 3);
            fn_800729B0(2, 0, 0, 3, 0);
            fn_80074788(0);
            fn_80073898(0);
            fn_80074918(1, 7, 0);
            fn_800728A8(1, 1, 0, 0);
            fn_80073778(&sTexY, 0);
            fn_80073778(&sTexUV, 1);
            fn_800724C8();
            fn_8007245C(0x2200);
            fn_8007264C(0, 9, 1, 4, 0);
            fn_8007264C(0, 13, 1, 3, 0);
            fn_80072864(2);
            fn_8003462C(128, 0, 4);
            h = sHeight;
            left = sPosX + (f32)((screenW - (sWidth * sScaleX)) / 2.0f);
            top = sPosY + (f32)((screenH - (f32)(h * sScaleX)) / 2.0f);
            right = left + (sWidth * sScaleX);
            GXWGFifo.f32 = right;
            GXWGFifo.f32 = top;
            GXWGFifo.f32 = FIFO_Z;
            GXWGFifo.u16 = 1;
            GXWGFifo.u16 = 0;
            GXWGFifo.f32 = right;
            bottom = top + (f32)(h * sScaleY);
            GXWGFifo.f32 = bottom;
            GXWGFifo.f32 = FIFO_Z;
            GXWGFifo.u16 = 1;
            GXWGFifo.u16 = 1;
            GXWGFifo.f32 = left;
            GXWGFifo.f32 = bottom;
            GXWGFifo.f32 = FIFO_Z;
            GXWGFifo.u16 = 0;
            GXWGFifo.u16 = 1;
            GXWGFifo.f32 = left;
            GXWGFifo.f32 = top;
            GXWGFifo.f32 = FIFO_Z;
            GXWGFifo.u16 = 0;
            GXWGFifo.u16 = 0;
            fn_80072808();
        }
        break;
    }
    fn_1_520A0();
    fn_1_52088();
    loc_20 = TEMPLATE;
    loc_20.x = (s16)(sPosX + (f32)((screenW - (s16)(sWidth * sScaleX)) / 2.0f));
    loc_20.y = (480.0f * (s16)(sPosY + (f32)((screenH - (s16)(sHeight * sScaleX)) / 2.0f))) / screenH;
    loc_20.z = 0.10001f;
    loc_20.scale_x = (sWidth * sScaleX) / 8.0f;
    loc_20.scale_y = ((480.0f * (sHeight * sScaleY)) / screenH) / 8.0f;
    loc_20.flags = 5;
    loc_20.image = 18;
    *(GXColor *)loc_20.color = (GXColor){0, 0, 0, 0};
    loc_20.alpha = 1.0f - sFade;
    fn_1_4E724(&loc_20);
    fn_1_520CC();
    fn_8006CD40(savedAspect);
}
/* fzgx:end fn_5_2E00 */

/* fzgx:begin fn_5_3BF8 */
void fn_5_3BF8(void) {
    sPlayer->vtbl->close(sPlayer);
    sMode = 0;
    sPauseReq = 0;
}
/* fzgx:end fn_5_3BF8 */

/* fzgx:begin fn_5_3C44 */
void fn_5_3C44(void) {
    MoviePlayer *player;
    u8 i;
    s8 n;

    if (sMode == 1) {
        player = sPlayer;
        player->vtbl->close(player);
        sMode = 0;
        sPauseReq = 0;
    }
    player = sPlayer;
    player->vtbl->stop(player);
    lbl_1_bss_190();
    sPlayer = 0;
    fn_1_46B4(lbl_801A6410, sWork, "movie.c", 1945);
    sWork = 0;
    sSubtitleText = 0;

    while ((n = sLineCount) >= 0) {
        if (sSubtitleFiles[n] != 0) {
            fn_1_46B4(lbl_801A6410, sSubtitleFiles[n], "movie.c", 1951);
        }
        sSubtitleFiles[sLineCount] = 0;
        sLineCount--;
    }

    for (i = 0; i < 2; i++) {
        if (sPlaneY[i] != 0) {
            fn_1_46B4(lbl_801A6410, sPlaneY[i], "movie.c", 1957);
            sPlaneY[i] = 0;
        }
        if (sPlaneUV[i] != 0) {
            fn_1_46B4(lbl_801A6410, sPlaneUV[i], "movie.c", 1958);
            sPlaneUV[i] = 0;
        }
    }
    if (sCapture != 0) {
        fn_1_46B4(lbl_801A6410, sCapture, "movie.c", 1960);
        sCapture = 0;
    }
    fn_1_157940();
    fn_1_41A8(fn_1_435C(sHeap0));
    fn_1_41A8(fn_1_435C(sHeap1));
    fn_1_41A8(fn_1_435C(sHeap2));
    fn_1_41A8(fn_1_435C(sHeap3));
    fn_80070704(1);
    sMode = -2;
}
/* fzgx:end fn_5_3C44 */

/* fzgx:begin fn_5_3E54 */
void fn_5_3E54(s8 index) {
    sSubtitleText = sSubtitleFiles[index];
}
/* fzgx:end fn_5_3E54 */

/* fzgx:begin fn_5_3E74 */
u32 fn_5_3E74(MovieSubtitle *subtitle) {
    u32 count;
    s32 bracket;
    s16 i;
    u8 c;

    count = 0;
    bracket = 0;
    fn_80082928(sSubtitleText, "%d,%d,%d,%d,%255c", &subtitle->start, &subtitle->length,
                &subtitle->size, &subtitle->line, subtitle->text);
    if (subtitle->start == -1) {
        sSubtitleText = 0;
    } else {
        i = 0;
        while ((c = subtitle->text[i]) != '*' && i < 255) {
            if (c == '[') {
                bracket = 1;
            } else if (c == ']') {
                bracket = 0;
            }
            i++;
            if (bracket == 0) {
                count++;
            }
        }
        subtitle->text[i] = 0;
        sSubtitleText = strchr(sSubtitleText, '\n') + 1;
    }
    if (sLanguage == 5) {
        count = (count >> 1) & 0x7f;
    }
    return count;
}
/* fzgx:end fn_5_3E74 */

/* fzgx:begin fn_5_3F94 */
void fn_5_3F94(void) {
    MoviePlayer *player;

    if (sPrevMain != 0) {
        sPrevMain();
    }
    player = sPlayer;
    if (player != 0) {
        player->vtbl->setPause(player, 1);
    }
}
/* fzgx:end fn_5_3F94 */

/* fzgx:begin fn_5_3FF0 */
void fn_5_3FF0(void) {
    MoviePlayer *player;

    if (sPrevMain != 0) {
        sPrevDisp();
    }
    player = sPlayer;
    if (player != 0) {
        player->vtbl->setPause(player, 0);
    }
}
/* fzgx:end fn_5_3FF0 */
