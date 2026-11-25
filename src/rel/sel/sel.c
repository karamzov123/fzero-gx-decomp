#include "types.h"
#include "sofdec/sj.h"

/* ---- sel.c: character, course and machine select (fze.sel.rel, first translation unit) ---- */

typedef struct {
    u8 pad_0[0x2];
    s16 car;
    u8 pad_4[0x4];
    u8 unk_8;
    u8 pad_9[0x17];
} SelPlayer;

typedef struct {
    s16 unk_0;
    u8 pad_2[0x1A];
} SelRecord;

/* one course entry of the table at SelState.unk_A4 */
typedef struct {
    s16 unk_0;
    u8 pad_2[0x12];
    s16 unk_14;
    u8 unk_16;
    u8 unk_17;
    u8 pad_18;
    u8 unk_19;
    u8 unk_1A;
    u8 pad_1B[0x5];
    u16 unk_20;
    u8 unk_22;
    u8 pad_23;
    SelRecord unk_24[4];
} SelCourse;

typedef struct {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    s16 unk_A;
    SelPlayer players[4];
    s16 unk_8C;
    s16 unk_8E;
    s16 unk_90;
    s16 unk_92;
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[0x2];
    u8 unk_9E;
    u8 unk_9F[4];
    u8 pad_A3[0x1];
    SelCourse *unk_A4;
    u8 pad_A8[0x7C];
    u32 unk_124;
    u8 unk_128;
    u8 unk_129;
    u8 unk_12A;
    u8 unk_12B;
    s16 unk_12C;
    s16 unk_12E;
    s16 unk_130;
    s16 unk_132;
    s16 unk_134;
    s16 unk_136;
    s16 unk_138;
    s16 unk_13A;
    s16 unk_13C;
    u8 pad_13E[0x2];
    u32 unk_140;
    u32 unk_144;
    u32 unk_148;
} SelState;

typedef struct {
    u8 pad_0[0x58];
    void *value;
} SelArcInfo;

typedef struct {
    u8 pad_0[0x324];
    s32 unk_324;
    u8 pad_328[0x440 - 0x328];
} SelCarEntry;

typedef struct {
    u32 unk_0;
    u8 unk_4;
} SelLight;

typedef struct {
    u8 pad_0[2];
    u8 value_2;
    u8 pad_3[1];
    u16 value_4;
    u8 pad_6[2];
    u32 value_8;
} SelEvent;

typedef struct {
    void *a;
    void *b;
} SelADXT;

typedef struct {
    s16 id;
    u8 pad_2[2];
    u32 flags;
} SelCell;

/* main_rel game state and interfaces */
extern SelState lbl_1_bss_8B3A0;
extern volatile u32 lbl_1_bss_8B5F4[8];  /* fzgx-allow: S2 handle slots: fn_10_C654 callbacks queued through fn_1_46B44 write them later */
extern s16 lbl_1_bss_960;
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_968;
extern s16 lbl_1_bss_96A;
extern SelLight lbl_1_bss_970;
extern SelEvent lbl_1_bss_9C;
extern s16 lbl_1_bss_8CA26;
extern u8 lbl_1_bss_8CA28;
extern SelADXT *lbl_1_bss_6EAD0;
extern void *lbl_1_bss_7167C;
extern void *lbl_1_bss_71680;
extern void *lbl_1_bss_71684;
extern u32 lbl_801A6410;

extern s32 fn_1_152970(s16 *, s16 *, s16, u32, SelCell *, s16, s16);
extern s32 fn_1_45730(const char *, SelArcInfo *);
extern void OSPanic(const char *, int, const char *, ...);
extern void *fn_1_45B2C(SelArcInfo *);
extern void fn_1_45850(SelArcInfo *);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_A0680(void);
extern void *fn_1_4630(u32, u32, const char *, s32);
extern u32 fn_1_45D0(u32, u32, const char *, u32);
extern void fn_1_46B4(u32, void *, const char *, int);
extern u32 fn_1_7BA08(u16, u16, u16);
extern void fn_1_7BA48(void *);
extern void fn_1_3CF0(u32, u32);
extern void fn_1_5124(u32, u32);
extern void fn_1_411A4(u32);
extern void fn_1_48418(int);
extern void fn_1_479F0(s16);
extern void fn_1_469BC(void);
extern void fn_1_4706C(void);
extern void fn_1_46A60(void);
extern void fn_1_159440(int, int);
extern void fn_1_47F74(s32);
extern void fn_1_52070(u32);
extern u32 fn_1_4404(void);
extern u32 fn_800090A4(u32);
extern void fn_1_46BA0(void *, u32);
extern u32 fn_1_46ED8(void);
extern void fn_1_46A8C(u32);
extern void fn_1_465D0(const char *, s32);
extern void fn_1_46B44(void *, volatile void *);  /* fzgx-allow: S2 the queued callback writes its argument later (the two handle slots below) */
extern void fn_1_41104(u32);
extern void fn_1_47E54(s32);
extern void fn_1_46BFC(void);
extern void fn_80008E84(u32);
extern void fn_8006CE1C(f32);
extern u32 fn_1_435C(u32);
extern s32 fn_1_3F8C(const char *, void *, void *, u32);
extern void fn_1_7BAF8(void);
extern void fn_1_A5330(u8, s16);
extern s16 fn_1_12EF24(s16, s16);
extern s16 fn_1_8D7C8(void);
extern void fn_1_12F17C(void);
extern void fn_1_36ADC(void);
extern void fn_1_407C(void);
extern void fn_1_3CC4(void);
extern int fn_1_4C10(void);
extern void fn_1_12C060(void *);
extern void fn_1_A266C(void);
extern void fn_1_A2D84(u32);
extern void fn_1_41A8(void);
extern void fn_1_6400(void);
extern void fn_1_46DC4(s32);
extern void fn_8004BF0C(void *, u32);
extern void ADXT_Stop(void *);
extern void fn_1_A0AA4(void);
extern void fn_1_1596DC(int);
extern void fn_1_47A60(s16);
extern void fn_1_484CC(s32);
extern void fn_1_48140(int);
extern void fn_1_412A0(u32);

/* functions of this file used before their definition */
void fn_10_834(void);
void fn_10_AB8(void);
void fn_10_D2C(void);
void fn_10_CF50(void);
void fn_10_CFDC(void);

/* ---- .data ---- */

/* link state names: a static table of a header that both sel translation units include */
static char *lbl_10_data_200[45] = {
    "NON", "MASTER RECV", "MASTER SEND", "SLAVE SEND", "SLAVE RECV", "INIT", "TEST", "TESTEND", "SETUP",
    "SETUP_DONE", "SETUP_COUNTER", "SETUP_CNT_DONE", "UNLINK", "COIN", "ENTRY_WAIT", "CHALLENGER",
    "CHALLENGER_OK", "ENTRY", "ENTRY_OK", "SINGLECHECK", "SINGLECHECK_OK", "COURSE", "COURSE_OK", "COURSE_DATA",
    "COURSE_DATA_OK", "MACHINE", "MACHINE_OK", "CONFIG", "CONFIG_OK", "COUNTERADJUST", "LINKWAIT", "LINKWAITOK",
    "LINKSEL", "LINKDELIVERYSTART", "LINKDELIVERY", "LINKDELIVERYOK", "LINKSELOK", "COURSEVIEW", "COURSEVIEW_OK",
    "LINKREQ", "LINKSTANDBY", "LINKOK", "LINK", "PAUSE", "ERROR"
};

s8 lbl_10_data_2B4[0x70] = {
    0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1,
    1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
s16 lbl_10_data_324[114] = {
    -1, -1, -1, -1, 41, 31, 32, 6, 2, 5, 4, 1,
    33, 34, 45, -1, -1, -1, -1, -1, -1, -1, -1, 42,
    3, 7, 8, 9, 0, 10, 11, 12, 13, 46, -1, -1,
    -1, -1, -1, -1, -1, -1, 43, 14, 15, 16, 17, 18,
    19, 20, 21, 22, 47, -1, -1, -1, -1, -1, -1, -1,
    -1, 44, 35, 36, 23, 24, 25, 26, 27, 37, 38, 48,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, 54, 55, 39,
    28, 29, 30, 40, 56, 57, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1
};
s16 lbl_10_data_408[38] = {
    49, -1, 2, -1, 5, -1, 36, -1, 32, -1, 33, -1,
    34, -1, 31, -1, 46, -1, 48, -1, 6, -1, 4, -1,
    40, -1, 39, -1, 35, -1, 37, -1, 38, -1, 45, -1,
    47, -1
};
s16 lbl_10_data_454 = 1;
s16 lbl_10_data_456 = 1;
s16 lbl_10_data_458 = 1;
s16 lbl_10_data_45A = 4;
u32 lbl_10_data_45C = 0x40000000;

/* button sequences: {kind, 0, buttons, frames} steps, ended by -1 */
u8 lbl_10_data_460[48] = {
    0x02, 0x00, 0x04, 0x01, 0x01, 0x00, 0x08, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x00, 0x11,
    0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x10, 0x01, 0x01, 0x00, 0x40, 0x01, 0x01, 0x00, 0x02, 0x01,
    0x01, 0x00, 0x20, 0x01, 0x01, 0x00, 0x08, 0x01, 0x01, 0x00, 0x00, 0x11, 0xFF, 0xFF, 0xFF, 0xFF
};
u8 lbl_10_data_490[48] = {
    0x02, 0x00, 0x00, 0x11, 0x01, 0x00, 0x04, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x04, 0x01,
    0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x10, 0x01, 0x01, 0x00, 0x04, 0x01, 0x01, 0x00, 0x80, 0x01,
    0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x08, 0x01, 0x01, 0x00, 0x10, 0x01, 0xFF, 0xFF, 0xFF, 0xFF
};
u8 lbl_10_data_4C0[48] = {
    0x02, 0x00, 0x08, 0x01, 0x01, 0x00, 0x00, 0x11, 0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x20, 0x01,
    0x01, 0x00, 0x04, 0x01, 0x01, 0x00, 0x40, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x00, 0x11,
    0x01, 0x00, 0x40, 0x01, 0x01, 0x00, 0x04, 0x01, 0x01, 0x00, 0x02, 0x01, 0xFF, 0xFF, 0xFF, 0xFF
};
u8 lbl_10_data_4F0[36] = {
    0x01, 0x00, 0x10, 0x03, 0x01, 0x00, 0x02, 0x03, 0x01, 0x00, 0x00, 0x13, 0x01, 0x00, 0x20, 0x03,
    0x01, 0x00, 0x08, 0x03, 0x01, 0x00, 0x08, 0x03, 0x01, 0x00, 0x40, 0x03, 0x01, 0x00, 0x40, 0x03,
    0xFF, 0xFF, 0xFF, 0xFF
};
u8 lbl_10_data_514[36] = {
    0x01, 0x00, 0x40, 0x03, 0x01, 0x00, 0x04, 0x03, 0x01, 0x00, 0x08, 0x03, 0x01, 0x00, 0x40, 0x03,
    0x01, 0x00, 0x00, 0x13, 0x01, 0x00, 0x02, 0x03, 0x01, 0x00, 0x80, 0x03, 0x01, 0x00, 0x10, 0x03,
    0xFF, 0xFF, 0xFF, 0xFF
};
u8 *lbl_10_data_538[5] = {
    lbl_10_data_460, lbl_10_data_490, lbl_10_data_4C0, lbl_10_data_4F0, lbl_10_data_514
};
struct {
    u32 count;
    u8 **sequences;
} lbl_10_data_54C = { 5, lbl_10_data_538 };
s16 lbl_10_data_554[4] = { 6, 2, 5, 4 };
s16 lbl_10_data_55C[4] = { 6, 2, 5, 4 };
s32 lbl_10_data_564[2] = { -1, -1 };
char *lbl_10_data_574 = "CAR_SEL";
/* heap handle: fn_10_C5E0, queued through fn_1_46B44, frees the heap and writes -1 here */
void *volatile lbl_10_data_578 = (void *)-1;
char lbl_10_data_57C[] = "sel.c";
char lbl_10_data_584[] = "Wrong CarMap col row\n";

/* ---- .bss ---- */
void *lbl_10_bss_0 = 0;
void *lbl_10_bss_4 = 0;
s16 lbl_10_bss_8 = 0;
s16 lbl_10_bss_A = 0;
s8 lbl_10_bss_C = 0;
u32 lbl_10_bss_10 = 0;
s32 lbl_10_bss_14 = 0;
s16 lbl_10_bss_18 = 0;
s16 lbl_10_bss_1A = 0;
SelCell lbl_10_bss_1C[6][19];
/* 9 records of 0x81C0 bytes, each a multiple of 32. The buffer starts at a 32-byte boundary
   (0x3C0, after the 0x390-byte grid). */
u8 lbl_10_bss_3C0[0x48FC0] __attribute__((aligned(32)));
SelCarEntry *lbl_10_bss_49380;
u32 lbl_10_bss_49384;
u32 lbl_10_bss_49388;
s16 lbl_10_bss_4938C;
s8 lbl_10_bss_4938E;
u8 lbl_10_bss_4938F;
u8 lbl_10_bss_49390[0x10];
u8 lbl_10_bss_493A0[0x5B20];
u8 lbl_10_bss_4EEC0[0x2880];
/* ---- private types of the TU1 blocks */
/* fn_10_D2C */
typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[4];
    u8 unk_14;
    u8 pad_15[0xB];
} fn_10_D2C_SelPlayer;

/* fn_10_D2C */
typedef struct {
    s16 unk_0;
    u8 pad_2[0x2];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0x84];
    s16 unk_8C;
    u8 pad_8E[0x2];
    s16 unk_90;
    u8 pad_92[0x2];
    u32 unk_94;
    u8 pad_98[7];
    u8 unk_9F[4];
    u8 pad_A3[0x89];
    s16 unk_12C;
    s16 unk_12E;
    s16 unk_130;
    s16 unk_132;
    s16 unk_134;
    s16 unk_136;
    s16 unk_138;
    s16 unk_13A;
    s16 unk_13C;
} fn_10_D2C_SelState;

/* fn_10_D2C */
typedef struct {
    u8 unk_0;
    u8 pad_1[5];
} SelD5B8;

/* fn_10_D2C */
typedef struct {
    u16 unk_0;
    u8 pad_2[0xA];
    u16 unk_C;
    u16 unk_E;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
} SelWindow;

/* fn_10_D2C */
typedef struct {
    u8 pad_0[0x2C];
    SelWindow window;
    u8 pad_42[0x2C];
} SelD5DC;

/* fn_10_D2C */
typedef struct {
    u32 unk_0;
    u32 unk_4;
} SelD888;

/* fn_10_D2C */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6[5];
    u8 unk_B;
} TitleSlotInfo;

/* fn_10_12D8 */
struct State {
    s16 current;
    s16 previous;
    u8 pad4[0x90];
    u32 flags;
    u8 pad98[0xC];
    u8 *entries;
    u8 padA8[0x81];
    u8 active;
};

/* fn_10_1544 */
typedef struct {
    u8 pad_0[0xA];
    s8 unk_a;
    u8 pad_b[1];
} SelRow;

/* fn_10_1544 */
typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[0x4];
    u16 unk_8;
    u8 pad_a[0x6];
    u16 unk_10;
    u16 unk_12;
} SelInput;

/* fn_10_1544 */
typedef struct {
    s16 state;
    u8 pad_2[0x90];
    s16 unk_92;
    u32 unk_94;
    u32 unk_98;
    u8 pad_9c[0x129 - 0x9C];
    u8 unk_129;
    u8 pad_12a[0x140 - 0x12A];
    u32 unk_140;
} SelMenu;

/* fn_10_1F9C */
typedef struct AdxSjdHandle AdxSjdHandle;

/* fn_10_1F9C */
typedef struct ADXStream ADXStream;

/* fn_10_1F9C */
typedef struct AXRNAHandle AXRNAHandle;

/* fn_10_1F9C */
typedef struct LSCObject LSCObject;

/* fn_10_1F9C */
typedef struct ADX_AMP ADX_AMP;

/* fn_10_1F9C */
typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 minimum_buffer_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 field_46;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 link_data_length;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle;

/* fn_10_1F9C */
typedef struct {
    s16 unk_0;
    u8 pad_2[0x8A];
    s16 unk_8C;
    s16 unk_8E;
    u8 pad_90[0x4];
    u32 unk_94;
    u8 pad_98[0xC];
    u8 *unk_A4;
    u8 pad_A8[0x81];
    u8 unk_129;
} fn_10_1F9C_SelState;

/* fn_10_21EC */
struct fn_10_21EC_SelState {
    u8 pad_0[0x8];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[0x8];
    s32 unk_14;
};

/* fn_10_21EC */
struct SelSub {
    u8 pad_0[0x1a];
    u8 unk_1a;
};

/* fn_10_21EC */
struct SelObject {
    s16 unk_0;
    u8 pad_2[0x8e];
    s16 unk_90;
    u8 pad_92[0x2];
    u32 unk_94;
    s32 unk_98;
    u8 pad_9C[0x8];
    struct SelSub *unk_A4;
    u8 pad_A8[0x81];
    u8 unk_129;
    u8 pad_12A[0x16];
    u32 unk_140;
};

/* fn_10_21EC */
struct SelTile {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0xa];
    u16 unk_14;
};

/* fn_10_3350 */
typedef signed short s16;

/* fn_10_3350 */
typedef signed long s32;

/* fn_10_3350 */
typedef unsigned char u8;

/* fn_10_3350 */
typedef unsigned short u16;

/* fn_10_3350 */
typedef unsigned long u32;

/* fn_10_3350 */
typedef struct {
u8 pad0[0xe];
s16 unk_e;
u8 pad10[0x10];
} Player;

/* fn_10_3350 */
typedef struct {
u8 pad0[4];
s16 mode;
u8 pad6[0x94 - 6];
u32 flags;
u8 pad98[6];
u8 index;
u8 pad9f[5];
u8 *data;
u8 padA8[0x129 - 0xa8];
u8 unk_129;
} Global;

/* fn_10_3350 */
typedef struct {
s32 a;
s32 b;
} Pair;

/* fn_10_3350 */
typedef struct {
u32 a, b;
} Result;

/* fn_10_3954 */
typedef struct {
    u8 a;
    u8 pad[3];
    u32 arr[1];
} fn_10_3954_SelEnt;

/* fn_10_3954 */
typedef struct {
    u8 pad0[0x40e00];
    u32 flags;
    u8 b4;
    u8 b5;
    u8 pad1[0x48FA0 - 0x40e06];
    u8 x;
    u8 pad2[3];
    fn_10_3954_SelEnt e[3];
} SelBig;

/* fn_10_3A98 */
typedef struct {
    u32 unk_0;  
    u32 unk_4;  
    s16 unk_8;  
    s16 unk_A;  
    u8 unk_C;  
    u8 pad_D[0x3];
    u32 unk_10;  
} Obj_10_bss_0;

/* fn_10_3A98 */
typedef struct {
    u32 unk_0;  
    u8 pad_4[0x3];
    u8 unk_7;  
    u8 pad_8[0x48FB8];
} Obj_10_bss_3C0;

/* fn_10_3A98 */
typedef struct {
    u8 pad[4];
    u32 flags;
} fn_10_3A98_SelSlot;

/* fn_10_3A98 */
typedef struct {
    u8 pad[0x18];
    s16 index_x;
    s16 index_y;
    fn_10_3A98_SelSlot slots[][19];
} fn_10_3A98_SelState;

/* fn_10_3A98 */
typedef struct {
    u8 pad[0x94];
    u32 flags;
} fn_10_3A98_GlobalState;

/* fn_10_3B44 */
typedef struct {
    u8 pad[4];
    u32 flags;
} fn_10_3B44_SelSlot;

/* fn_10_3B44 */
typedef struct {
    u8 pad[0x18];
    s16 index_x;
    s16 index_y;
    fn_10_3B44_SelSlot slots[][19];
} fn_10_3B44_SelState;

/* fn_10_3B44 */
typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 pad[0x81C0 - 6];
} fn_10_3B44_SelEnt;

/* fn_10_3B44 */
typedef struct {
    s16 key;
    u16 pad;
    u32 mask;
} SelFnEntry;

/* fn_10_3C14 */
typedef struct {
    u8 pad[4];
    u32 flags;
} fn_10_3C14_SelSlot;

/* fn_10_3C14 */
typedef struct {
    u8 pad[0x94];
    u32 flags;
} fn_10_3C14_GlobalState;

/* fn_10_3DE0 */
typedef struct fn_10_3DE0_SelEntry {
    u32 flags;                  /* 0x0 */
    u8 pad04;                   /* 0x4 */
    u8 value5;                  /* 0x5 */
    u8 pad06;                   /* 0x6 */
    u8 type7;                   /* 0x7 */
    u8 pad08[0x81a0 - 0x8];
    u8 source_index;            /* 0x81a0 */
    u8 pad81a1[0x81c0 - 0x81a1];
} fn_10_3DE0_SelEntry;

/* fn_10_3DE0 */
typedef struct fn_10_3DE0_SelObject {
    u8 pad000[0x390];
    u32 flags390;               /* 0x390 */
    u8 pad394[0xc];
    void *data3a0;              /* 0x3a0 */
    u32 result3a4;              /* 0x3a4 */
    u8 pad3a8[0x12];
    s16 slot3ba;                /* 0x3ba */
} fn_10_3DE0_SelObject;

/* fn_10_3DE0 */
typedef struct SelResult {
    fn_10_3DE0_SelObject *object;          /* 0x0 */
    u8 kind4;                   /* 0x4 */
    u8 pad05[0x10420 - 0x5];
    u32 zero10420;              /* 0x10420 */
    void (*cb10424)(void);      /* 0x10424 */
    void (*cb10428)(void);      /* 0x10428 */
    void (*cb1042c)(void);      /* 0x1042c */
} SelResult;

/* fn_10_3DE0 */
typedef struct CopyData {
    u32 words[0x110];           /* 0x440 bytes */
} CopyData;

/* fn_10_3F54 */
typedef signed char s8;

/* fn_10_3F54 */
typedef double f64;

/* fn_10_3F54 */
typedef struct SelWork {
u32 unk_0;
u32 unk_4;
s16 unk_8;
s16 unk_A;
s8 unk_C;
u8 pad_D[0x7];
s32 unk_14;
} SelWork;

/* fn_10_3F54 */
typedef struct GameState {
s16 unk_0;
u8 pad_2[0x92];
u32 unk_94;
u32 unk_98;
u8 pad_9C[0xA4];
u32 unk_140;
} GameState;

/* fn_10_3F54 */
typedef struct Entry9C8 {
u8 pad_0[0xA];
s8 unk_A;
u8 pad_B;
} Entry9C8;

/* fn_10_3F54 */
typedef struct Entry9F8 {
volatile u16 unk_0;  /* fzgx-allow: S2 volatile keeps the verified access order */
u8 pad_2[0x12];
} Entry9F8;

/* fn_10_436C */
typedef struct {
    u8 pad0[0x94];
    u32 flags;
    u8 pad98[7];
    u8 value;
    u8 padA0[4];
    u8 *items;
} fn_10_436C_SelState;

/* fn_10_4600 */
struct S9F8 {
    u8 pad0[8];
    u16 f8;
    u8 pad1[0x14 - 0xa];
};

/* fn_10_4790 */
typedef struct {
    u8 pad_0[0x14];
    s32 unk_14;
} SelBase;

/* fn_10_4838 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
} Sig_fn_1_B7F58_Result;

/* fn_10_4838 */
struct fn_10_4838_lbl_10_bss_55CE0 {
    u8 unk_0;
};

/* fn_10_4838 */
struct fn_10_4838_lbl_10_bss_14 {
    u32 unk_0;
};

/* fn_10_4838 */
struct fn_10_4838_lbl_1_bss_8B3A0 {
    u8 pad_0[146];
    u32 unk_94;
    u8 pad_98[0x6];
    u8 unk_9E;
    u8 pad_9F[0x5];
    u32 unk_A4;
    u8 pad_A8[0x98];
    s32 unk_140;

    u8 fzgx_tail_padding[2];
};

/* fn_10_4838 */
struct fn_10_4838_lbl_10_bss_4938C {
    s16 unk_0;
};

/* fn_10_4AE0 */
typedef struct fn_10_4AE0_Sig_fn_1_152840_Entry {
    s16 id;
    u8 pad[2];
    u32 flags;
} fn_10_4AE0_Sig_fn_1_152840_Entry;

/* fn_10_4AE0 */
typedef struct {
    u16 unk0;
    u32 unk4;
    u8 unk8;
    u8 pad9[3];
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
} Sig_fn_1_12C0EC_FnData;

/* fn_10_4D78 */
typedef struct Sig_fn_1_152840_Entry { s16 id; u8 pad[2]; u32 flags; } Sig_fn_1_152840_Entry;

/* fn_10_4D78 */
typedef struct { s16 key; u16 pad; u32 mask; } Sig_fn_1_152970_Fn152970Entry;

/* fn_10_4D78 */
struct fn_10_4D78_lbl_10_bss_0 { u8 pad[0x18]; s16 unk_18; s16 unk_1A; Sig_fn_1_152840_Entry unk_1C[1]; };

/* fn_10_4D78 */
struct fn_10_4D78_lbl_1_bss_8B3A0 {
u8 pad_0[4]; s16 unk_4; u8 pad_6[8]; s16 unk_E;
u8 pad_10[0x1E]; s16 unk_2E; u8 pad_30[0x1E]; s16 unk_4E;
u8 pad_50[0x1E]; s16 unk_6E; u8 pad_70[0x24]; u32 unk_94;
u8 pad_98[6]; u8 unk_9E;
};

/* fn_10_5230 */
typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x4];
    u8 unk_14;
    u8 pad_15[0xB];
} fn_10_5230_Entry;

/* fn_10_5230 */
typedef struct {
    u8 pad_0[0x2];
    s16 unk_2;
    u8 pad_4[0x4];
    u8 unk_8;
    u8 pad_9[0x17];
} fn_10_5230_Record;

/* fn_10_5230 */
typedef struct {
    u32 unk_0;
    u8 *unk_4;
    u8 *unk_8;
    u32 unk_C;
    u8 *unk_10;
    s16 unk_14;
    s16 unk_16;
    u32 unk_18;
    u8 *unk_1C;
    u8 *unk_20;
    u8 *unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x28];
    u32 unk_60;
    u8 pad_64[0x4];
} fn_10_5230_Desc;

/* fn_10_5230 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
} fn_10_5230_lbl_1_bss_8B5F4;

/* fn_10_5780 */
struct Fn105780 {
    u8 pad[0x92];
    u16 value;
};

/* fn_10_578C */
typedef struct fn_10_578C_AdxSjdHandle fn_10_578C_AdxSjdHandle;

/* fn_10_578C */
typedef struct fn_10_578C_ADXStream fn_10_578C_ADXStream;

/* fn_10_578C */
typedef struct fn_10_578C_AXRNAHandle fn_10_578C_AXRNAHandle;

/* fn_10_578C */
typedef struct fn_10_578C_LSCObject fn_10_578C_LSCObject;

/* fn_10_578C */
typedef struct fn_10_578C_ADX_AMP fn_10_578C_ADX_AMP;

/* fn_10_578C */
typedef struct fn_10_578C_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    fn_10_578C_AdxSjdHandle *decoder;
    fn_10_578C_ADXStream *stream;
    fn_10_578C_AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 minimum_buffer_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 field_46;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 link_data_length;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    fn_10_578C_ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    fn_10_578C_LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} fn_10_578C_ADXTHandle;

/* fn_10_578C */
struct fn_10_578C_lbl_1_bss_8B3A0 {
    u8 pad_0[0x98];
    u32 unk_98;
};

/* fn_10_5E94 */
typedef signed char fn_10_5E94_s8;

/* fn_10_5E94 */
typedef signed short fn_10_5E94_s16;

/* fn_10_5E94 */
typedef signed long fn_10_5E94_s32;

/* fn_10_5E94 */
typedef unsigned char fn_10_5E94_u8;

/* fn_10_5E94 */
typedef unsigned short fn_10_5E94_u16;

/* fn_10_5E94 */
typedef unsigned long fn_10_5E94_u32;

/* fn_10_5E94 */
typedef float fn_10_5E94_f32;

/* fn_10_5E94 */
typedef struct {
fn_10_5E94_u8 pad_0[0x19];
fn_10_5E94_u8 unk_19;
} fn_10_5E94_Obj_1_bss_8B3A0_AtA4;

/* fn_10_5E94 */
typedef struct {
fn_10_5E94_s16 unk_0;
fn_10_5E94_u8 pad_2[0x2];
fn_10_5E94_s16 unk_4;
fn_10_5E94_u8 pad_6[0x2];
fn_10_5E94_s16 unk_8;
fn_10_5E94_u8 pad_A[0x4];
fn_10_5E94_s16 unk_E;
fn_10_5E94_u8 pad_10[0x4];
fn_10_5E94_u8 unk_14;
fn_10_5E94_u8 pad_15[0x19];
fn_10_5E94_s16 unk_2E;
fn_10_5E94_u8 pad_30[0x5C];
fn_10_5E94_s16 unk_8C;
fn_10_5E94_u8 pad_8E[0x2];
fn_10_5E94_s16 unk_90;
fn_10_5E94_s16 unk_92;
fn_10_5E94_u32 unk_94;
fn_10_5E94_u8 pad_98[0x6];
fn_10_5E94_u8 unk_9E;
fn_10_5E94_u8 unk_9F;
fn_10_5E94_u8 pad_A0[0x4];
fn_10_5E94_Obj_1_bss_8B3A0_AtA4 *unk_A4;
fn_10_5E94_u8 pad_A8[0x8];
fn_10_5E94_s16 unk_B0;
fn_10_5E94_s16 unk_B2;
fn_10_5E94_u8 pad_B4[0xC];
fn_10_5E94_s16 unk_C0;
fn_10_5E94_s16 unk_C2;
fn_10_5E94_u8 pad_C4[0xC];
fn_10_5E94_s16 unk_D0;
fn_10_5E94_s16 unk_D2;
fn_10_5E94_u8 pad_D4[0xC];
fn_10_5E94_u32 unk_E0;
fn_10_5E94_u32 unk_E4;
fn_10_5E94_u32 unk_E8;
fn_10_5E94_u32 unk_EC;
fn_10_5E94_u32 unk_F0;
fn_10_5E94_u32 unk_F4;
fn_10_5E94_u32 unk_F8;
fn_10_5E94_u32 unk_FC;
fn_10_5E94_u32 unk_100;
fn_10_5E94_u32 unk_104;
fn_10_5E94_u32 unk_108;
fn_10_5E94_u32 unk_10C;
fn_10_5E94_u32 unk_110;
fn_10_5E94_u32 unk_114;
fn_10_5E94_u32 unk_118;
fn_10_5E94_u32 unk_11C;
fn_10_5E94_u32 unk_120;
fn_10_5E94_u32 unk_124;
fn_10_5E94_u8 unk_128;
fn_10_5E94_u8 unk_129;
fn_10_5E94_u8 pad_12A[0x2];
fn_10_5E94_s16 unk_12C;
fn_10_5E94_s16 unk_12E;
fn_10_5E94_s16 unk_130;
fn_10_5E94_s16 unk_132;
fn_10_5E94_s16 unk_134;
fn_10_5E94_s16 unk_136;
fn_10_5E94_s16 unk_138;
fn_10_5E94_s16 unk_13A;
fn_10_5E94_s16 unk_13C;
fn_10_5E94_u8 pad_13E[0x2];
fn_10_5E94_u32 unk_140;
fn_10_5E94_u8 pad_144[0x2];
fn_10_5E94_s16 unk_146;
fn_10_5E94_s16 unk_148;
fn_10_5E94_u8 pad_14A[0x2];
} fn_10_5E94_Obj_1_bss_8B3A0;

/* fn_10_5E94 */
typedef struct {
fn_10_5E94_u16 unk_0;
fn_10_5E94_u16 unk_2;
fn_10_5E94_u8 pad_4[0x4];
fn_10_5E94_u16 unk_8;
fn_10_5E94_u16 unk_A;
fn_10_5E94_u8 pad_C[0x4];
fn_10_5E94_u16 unk_10;
fn_10_5E94_u16 unk_12;
fn_10_5E94_u8 pad_14[0x3C];
} fn_10_5E94_Obj_1_bss_9F8;

/* fn_10_5E94 */
typedef struct fn_10_5E94_FontDrawPacket fn_10_5E94_FontDrawPacket;

/* fn_10_5E94 */
typedef struct fn_10_5E94_FontVertex {
fn_10_5E94_f32 x, y, z;
} fn_10_5E94_FontVertex;

/* fn_10_5E94 */
struct fn_10_5E94_lbl_1_bss_8B3A0 {
fn_10_5E94_u8 pad_0[0x98];
fn_10_5E94_u32 unk_98;
};

/* fn_10_6518 */
typedef struct {
    u8 pad_0[0x19];
    u8 unk_19;
} fn_10_6518_Course;

/* fn_10_6518 */
typedef struct {
    s16 unk_0;
    u8 pad_2[0x6];
    s16 unk_8;
    s16 unk_A;
    u8 pad_C[0x84];
    s16 unk_90;
    s16 unk_92;
    u32 unk_94;
    u8 pad_98[0xC];
    fn_10_6518_Course *unk_A4;
    u8 pad_A8[0x84];
    s16 unk_12C;
    s16 unk_12E;
    s16 unk_130;
    s16 unk_132;
    s16 unk_134;
    s16 unk_136;
    s16 unk_138;
    s16 unk_13A;
    s16 unk_13C;
    u8 pad_13E[0x2];
    u32 unk_140;
    u8 pad_144[0x8];
} Obj_1_bss_8B3A0;

/* fn_10_6518 */
typedef struct {
    u32 unk_0;
} Obj_1_bss_6EAB4;

/* fn_10_6518 */
typedef struct {
    u32 unk_0;
    u8 *unk_4;
    u8 *unk_8;
    u32 unk_C;
    u8 *unk_10;
    s16 unk_14;
    s16 unk_16;
    u32 unk_18;
    u8 *unk_1C;
    u8 *unk_20;
    u8 *unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x28];
    u32 unk_60;
    u8 pad_64[0x4];
} fn_10_6518_Desc;

/* fn_10_6518 */
typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x10];
} fn_10_6518_Player;

/* fn_10_6518 */
typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0xA];
} fn_10_6518_Pad;

/* fn_10_6518 */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
} fn_10_6518_Bss9C;

/* fn_10_7130 */
typedef struct {
    u8 pad[0xe];
    s16 value;
} fn_10_7130_SelEntry;

/* fn_10_7130 */
typedef struct {
    s16 state;
    u8 pad[0x92];
    u32 flags_94;
} fn_10_7130_SelGlobals;

/* fn_10_73AC */
struct S8B3A0 {
    u8 pad0[0x94];
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[2];
    u8 unk_9E;
    u8 pad_9F[0xA1];
    u32 unk_140;
};

/* fn_10_73AC */
struct fn_10_73AC_S9C8 {
    u8 pad0[0xA];
    s8 fA;
    u8 pad1[0xC - 0xB];
};

/* fn_10_73AC */
struct fn_10_73AC_S9F8 {
    u8 pad0[8];
    u16 f8;
    u8 pad1[0x14 - 0xA];
};

/* fn_10_75D4 */
typedef struct {
    u8 unk_0;
    u8 pad_1[0x3];
    u32 unk_4[1];
} fn_10_75D4_Slot;

/* fn_10_75D4 */
typedef struct {
    u32 unk_0;
    u8 pad_4;
    u8 unk_5;
    u8 pad_6[0x819A];
    u8 unk_81A0;
    u8 pad_81A1[0x3];
    fn_10_75D4_Slot unk_81A4[3];
    u8 pad_81BC[0x4];
} fn_10_75D4_Entry;

/* fn_10_75D4 */
typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x10];
} fn_10_75D4_Player;

/* fn_10_7A10 */
typedef struct {
    u8 pad_0[0xA];
    s8 unk_a;
    u8 pad_b[1];
} fn_10_7A10_Pad;

/* fn_10_7A10 */
typedef struct {
    u8 pad_0[0x98];
    u32 unk_98;
} fn_10_7A10_State;

/* fn_10_804C */
struct fn_10_804C_lbl_1_bss_8B3A0 {
    u8 pad_0[0x94];
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[2];
    u8 unk_9E;
    u8 pad_9F[0xA1];
    u32 unk_140;
};

/* fn_10_804C */
struct fn_10_804C_S9F8 {
    u8 pad0[8];
    u16 f8;
    u8 pad1[10];
};

/* fn_10_804C */
struct S9C8 {
    u8 pad0[10];
    s8 fA;
    u8 fB;
};

/* fn_10_8314 */
typedef struct fn_10_8314_SelWork {
    u8 pad_0[0x14];
    s32 unk_14;
} fn_10_8314_SelWork;

/* fn_10_8314 */
typedef struct fn_10_8314_SelState {
    u8 pad_0[0x9E];
    u8 unk_9E;
    u8 pad_9F[0x129 - 0x9F];
    u8 unk_129;
} fn_10_8314_SelState;

/* fn_10_83C0 */
typedef struct fn_10_83C0_SelState {
    u8 pad_0[0x94];
    u32 flags_94;
    u8 pad_98[0x91];
    u8 field_129;
    u8 pad_12A[0x16];
    u32 field_140;
} fn_10_83C0_SelState;

/* fn_10_8538 */
typedef struct {
    u8 pad[0xa4];
    u8 *ptr;
} BssObject;

/* fn_10_8600 */
typedef struct {
    u8 pad0[0x14];
    s32 state;
} fn_10_8600_SelState;

/* fn_10_8600 */
typedef struct {
    u8 *value;
} WorkBox;

/* fn_10_8600 */
typedef struct {
    u8 pad0[0x94];
    u32 flags94;
    u8 pad98[0xc];
    u8 *object;
    u8 padA8[0x98];
    u32 flags140;
} GlobalSel;

/* fn_10_8870 */
typedef struct Sig_ADXT_Stop_ADXTHandle Sig_ADXT_Stop_ADXTHandle;

/* fn_10_8870 */
typedef struct {
    u8 pad0[12];
    s32 unk_14;
    u8 pad18[0x49370];
    u32 unk_49388;
    s16 unk_4938C;
    u8 pad4938E[0x83B2];
    s32 unk_51740;
    s32 unk_51744;
} fn_10_8870_SelState;

/* fn_10_8870 */
typedef struct {
    u8 pad0[0xa4];
    u8 *unk_a4;
} SelCtl;

/* fn_10_8930 */
typedef struct fn_10_8930_SelState {
    s16 state;
    u8 pad2[0x92];
    u32 flags;
    u8 pad98[6];
    u8 mode;
    u8 pad9f[0xa1];
    u32 unk140;
} fn_10_8930_SelState;

/* fn_10_8930 */
typedef struct SelEntry {
    u8 pad0[8];
    u16 flags;
    u8 pad0a[0xa];
} SelEntry;

/* fn_10_8B0C */
typedef struct { u8 pad[0x94]; u32 flags; } fn_10_8B0C_SelGlobal;

/* fn_10_8BB8 */
struct S14 {
    u32 f;
};

/* fn_10_8BB8 */
struct fn_10_8BB8_lbl_1_bss_8B3A0 {
    u8 pad_0[0x94];
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[2];
    u8 unk_9E;
    u8 pad_9F[0xA1];
    u32 unk_140;
};

/* fn_10_8BB8 */
struct fn_10_8BB8_S9F8 {
    u8 pad0[8];
    u16 f8;
    u8 pad1[0xA];
};

/* fn_10_8D90 */
typedef struct {
    u8 pad[0x94];
    u32 flags;
} fn_10_8D90_SelGlobal;

/* fn_10_8DFC */
typedef struct {
    u8 pad_0[0x16];
    u8 unk_16;
    u8 unk_17;
    u8 pad_18[0x8];
    s16 unk_20;
} Obj_8B3A0_A4;

/* fn_10_8F0C */
typedef struct { u16 unk_0; } U16Box;

/* fn_10_8F0C */
typedef struct {
    u8 pad_0[0x16];
    u8 unk_16;
    u8 unk_17;
    u8 pad_18[8];
    u16 unk_20;
} fn_10_8F0C_SelSub;

/* fn_10_8F0C */
typedef struct {
    u8 pad_0[0x94];
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[2];
    u8 unk_9E;
    u8 pad_9F[5];
    fn_10_8F0C_SelSub *unk_A4;
    u8 pad_A8[0x98];
    u32 unk_140;
} fn_10_8F0C_SelState;

/* fn_10_8F0C */
typedef struct {
    u8 pad_0[0xA];
    s8 unk_A;
    u8 pad_B;
} SelSlot;

/* fn_10_8F0C */
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[0xA];
} Sel9F8;

/* fn_10_9154 */
typedef struct {
    u32 unk_0;  
    u8 pad_4[0x38];
} Obj_10_data_7B0;

/* fn_10_924C */
typedef struct {
    u8 pad0[0x458];
    s16 f458;
    s16 f45a;
    u8 pad1[0x108];
    s32 f564;
    u8 pad2[0x34];
    u8 str59c[0x174];
    u8 obj710[0xc];
    u8 obj71c[0x10];
    u8 obj72c[0xac];
    char fmt[0x20];
} SelData;

/* fn_10_924C */
typedef struct {
    s16 f0;
    u16 f2;
    u32 f4;
    u8 f8;
    u8 pad[0x17];
} SelEnt;

/* fn_10_924C */
typedef struct {
    u8 pad324[0x324];
    u32 f324;
    u8 pad[0x118];
} fn_10_924C_SelCell;

/* fn_10_948C */
typedef struct {
    u32 flags;
    u8 pad[0x81bc];
} fn_10_948C_SelEntry;

/* fn_10_95A0 */
typedef struct {
    u8 pad[0x94];
    u32 flags;
} fn_10_95A0_SelGlobal;

/* fn_10_95A0 */
typedef struct {
    u8 pad[0x324];
    u32 a;
    u8 pad0[0x43c];
    u32 b;
    u8 pad1[0x43c];
    u32 c;
    u8 pad2[0x43c];
    u32 d;
    u8 pad3[0x43c];
    u32 e;
    u8 pad4[0x43c];
    u32 f;
    u8 pad5[0x43c];
    u32 g;
    u8 pad6[0x43c];
    u32 h;
    u8 tail[0x11c];
} fn_10_95A0_SelBlock;

/* fn_10_9788 */
struct fn_10_9788_lbl_1_bss_962 {
    s16 unk_0;
};

/* fn_10_9788 */
struct NavigationTable { s16 entry[12][8]; };

/* fn_10_9788 */
struct PadState {
    u16 unk_0, unk_2;
    u8 pad_4[4];
    volatile u16 unk_8; /* input registers are reread at each test */
    u8 pad_A[6];
    volatile u16 unk_10, unk_12; /* input registers are reread at each test */
};

/* fn_10_9788 */
struct ControllerState { u8 pad_0[10]; s8 unk_A; u8 pad_B; };

/* fn_10_A0E8 */
struct SelState98 {
    u8 pad_0[0x98];
    u32 unk_98;
};

/* fn_10_A0E8 */
typedef struct {
    u8 pad_0[0xa];
    s8 unk_a;
    u8 pad_1[1];
} SelSlot9C8;

/* fn_10_A0E8 */
typedef struct {
    u8 pad_0[0x10];
    u16 unk_10;
    u16 unk_12;
} SelSlot9F8;

/* fn_10_A25C */
typedef struct {
    u8 pad_0[0xA];
    s8 unk_a;
    u8 pad_1[1];
} SelRowA25C;

/* fn_10_A25C */
typedef struct {
    u8 pad_0[0x10];
    u16 unk_10;
    u16 unk_12;
} SelInfoA25C;

/* fn_10_A25C */
typedef struct {
    u8 pad_0[0x94];
    u32 unk_94;
    u32 unk_98;
} SelGlobA25C;

/* fn_10_A25C */
typedef struct {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
} SelObjA25C;

/* fn_10_A480 */
typedef signed char fn_10_A480_s8;

/* fn_10_A480 */
typedef signed short fn_10_A480_s16;

/* fn_10_A480 */
typedef signed long fn_10_A480_s32;

/* fn_10_A480 */
typedef unsigned char fn_10_A480_u8;

/* fn_10_A480 */
typedef unsigned short fn_10_A480_u16;

/* fn_10_A480 */
typedef unsigned long fn_10_A480_u32;

/* fn_10_A480 */
typedef float fn_10_A480_f32;

/* fn_10_A480 */
typedef struct {
fn_10_A480_u8 pad_0[0x19];
fn_10_A480_u8 unk_19;
} fn_10_A480_Obj_1_bss_8B3A0_AtA4;

/* fn_10_A480 */
typedef struct {
fn_10_A480_s16 unk_0;
fn_10_A480_u8 pad_2[0x2];
fn_10_A480_s16 unk_4;
fn_10_A480_u8 pad_6[0x2];
fn_10_A480_s16 unk_8;
fn_10_A480_u8 pad_A[0x4];
fn_10_A480_s16 unk_E;
fn_10_A480_u8 pad_10[0x4];
fn_10_A480_u8 unk_14;
fn_10_A480_u8 pad_15[0x19];
fn_10_A480_s16 unk_2E;
fn_10_A480_u8 pad_30[0x5C];
fn_10_A480_s16 unk_8C;
fn_10_A480_u8 pad_8E[0x2];
fn_10_A480_s16 unk_90;
fn_10_A480_s16 unk_92;
fn_10_A480_u32 unk_94;
fn_10_A480_u8 pad_98[0x6];
fn_10_A480_u8 unk_9E;
fn_10_A480_u8 unk_9F;
fn_10_A480_u8 pad_A0[0x4];
fn_10_A480_Obj_1_bss_8B3A0_AtA4 *unk_A4;
fn_10_A480_u8 pad_A8[0x8];
fn_10_A480_s16 unk_B0;
fn_10_A480_s16 unk_B2;
fn_10_A480_u8 pad_B4[0xC];
fn_10_A480_s16 unk_C0;
fn_10_A480_s16 unk_C2;
fn_10_A480_u8 pad_C4[0xC];
fn_10_A480_s16 unk_D0;
fn_10_A480_s16 unk_D2;
fn_10_A480_u8 pad_D4[0xC];
fn_10_A480_u32 unk_E0;
fn_10_A480_u32 unk_E4;
fn_10_A480_u32 unk_E8;
fn_10_A480_u32 unk_EC;
fn_10_A480_u32 unk_F0;
fn_10_A480_u32 unk_F4;
fn_10_A480_u32 unk_F8;
fn_10_A480_u32 unk_FC;
fn_10_A480_u32 unk_100;
fn_10_A480_u32 unk_104;
fn_10_A480_u32 unk_108;
fn_10_A480_u32 unk_10C;
fn_10_A480_u32 unk_110;
fn_10_A480_u32 unk_114;
fn_10_A480_u32 unk_118;
fn_10_A480_u32 unk_11C;
fn_10_A480_u32 unk_120;
fn_10_A480_u32 unk_124;
fn_10_A480_u8 unk_128;
fn_10_A480_u8 unk_129;
fn_10_A480_u8 pad_12A[0x2];
fn_10_A480_s16 unk_12C;
fn_10_A480_s16 unk_12E;
fn_10_A480_s16 unk_130;
fn_10_A480_s16 unk_132;
fn_10_A480_s16 unk_134;
fn_10_A480_s16 unk_136;
fn_10_A480_s16 unk_138;
fn_10_A480_s16 unk_13A;
fn_10_A480_s16 unk_13C;
fn_10_A480_u8 pad_13E[0x2];
fn_10_A480_u32 unk_140;
fn_10_A480_u8 pad_144[0x2];
fn_10_A480_s16 unk_146;
fn_10_A480_s16 unk_148;
fn_10_A480_u8 pad_14A[0x2];
} fn_10_A480_Obj_1_bss_8B3A0;

/* fn_10_A480 */
typedef struct {
fn_10_A480_u16 unk_0;
fn_10_A480_u16 unk_2;
fn_10_A480_u8 pad_4[0x4];
fn_10_A480_u16 unk_8;
fn_10_A480_u16 unk_A;
fn_10_A480_u8 pad_C[0x4];
fn_10_A480_u16 unk_10;
fn_10_A480_u16 unk_12;
fn_10_A480_u8 pad_14[0x3C];
} fn_10_A480_Obj_1_bss_9F8;

/* fn_10_A480 */
typedef struct fn_10_A480_FontDrawPacket fn_10_A480_FontDrawPacket;

/* fn_10_A480 */
typedef struct fn_10_A480_FontVertex {
fn_10_A480_f32 x, y, z;
} fn_10_A480_FontVertex;

/* fn_10_A480 */
struct fn_10_A480_E9C8 { fn_10_A480_u8 pad[10]; fn_10_A480_s8 id; fn_10_A480_u8 pad2; };

/* fn_10_A480 */
struct fn_10_A480_Arg0 {
fn_10_A480_u8 pad_0[4];
fn_10_A480_s16 unk_4;
fn_10_A480_s16 unk_6;
fn_10_A480_u8 pad_8[0x8C];
fn_10_A480_u32 unk_94;
};

/* fn_10_A480 */
struct fn_10_A480_lbl_1_bss_8B3A0 {
fn_10_A480_u8 pad_0[0x98];
fn_10_A480_u32 unk_98;
};

/* fn_10_A480 */
struct fn_10_A480_E9F8 { fn_10_A480_u8 pad[0x10]; fn_10_A480_u16 a; fn_10_A480_u16 b; };

/* fn_10_A634 */
typedef signed char fn_10_A634_s8;

/* fn_10_A634 */
typedef signed short fn_10_A634_s16;

/* fn_10_A634 */
typedef signed long fn_10_A634_s32;

/* fn_10_A634 */
typedef unsigned char fn_10_A634_u8;

/* fn_10_A634 */
typedef unsigned short fn_10_A634_u16;

/* fn_10_A634 */
typedef unsigned long fn_10_A634_u32;

/* fn_10_A634 */
typedef float fn_10_A634_f32;

/* fn_10_A634 */
typedef struct {
fn_10_A634_u8 pad_0[0x19];
fn_10_A634_u8 unk_19;
} fn_10_A634_Obj_1_bss_8B3A0_AtA4;

/* fn_10_A634 */
typedef struct {
fn_10_A634_s16 unk_0;
fn_10_A634_u8 pad_2[0x2];
fn_10_A634_s16 unk_4;
fn_10_A634_u8 pad_6[0x2];
fn_10_A634_s16 unk_8;
fn_10_A634_u8 pad_A[0x4];
fn_10_A634_s16 unk_E;
fn_10_A634_u8 pad_10[0x4];
fn_10_A634_u8 unk_14;
fn_10_A634_u8 pad_15[0x19];
fn_10_A634_s16 unk_2E;
fn_10_A634_u8 pad_30[0x5C];
fn_10_A634_s16 unk_8C;
fn_10_A634_u8 pad_8E[0x2];
fn_10_A634_s16 unk_90;
fn_10_A634_s16 unk_92;
fn_10_A634_u32 unk_94;
fn_10_A634_u8 pad_98[0x6];
fn_10_A634_u8 unk_9E;
fn_10_A634_u8 unk_9F;
fn_10_A634_u8 pad_A0[0x4];
fn_10_A634_Obj_1_bss_8B3A0_AtA4 *unk_A4;
fn_10_A634_u8 pad_A8[0x8];
fn_10_A634_s16 unk_B0;
fn_10_A634_s16 unk_B2;
fn_10_A634_u8 pad_B4[0xC];
fn_10_A634_s16 unk_C0;
fn_10_A634_s16 unk_C2;
fn_10_A634_u8 pad_C4[0xC];
fn_10_A634_s16 unk_D0;
fn_10_A634_s16 unk_D2;
fn_10_A634_u8 pad_D4[0xC];
fn_10_A634_u32 unk_E0;
fn_10_A634_u32 unk_E4;
fn_10_A634_u32 unk_E8;
fn_10_A634_u32 unk_EC;
fn_10_A634_u32 unk_F0;
fn_10_A634_u32 unk_F4;
fn_10_A634_u32 unk_F8;
fn_10_A634_u32 unk_FC;
fn_10_A634_u32 unk_100;
fn_10_A634_u32 unk_104;
fn_10_A634_u32 unk_108;
fn_10_A634_u32 unk_10C;
fn_10_A634_u32 unk_110;
fn_10_A634_u32 unk_114;
fn_10_A634_u32 unk_118;
fn_10_A634_u32 unk_11C;
fn_10_A634_u32 unk_120;
fn_10_A634_u32 unk_124;
fn_10_A634_u8 unk_128;
fn_10_A634_u8 unk_129;
fn_10_A634_u8 pad_12A[0x2];
fn_10_A634_s16 unk_12C;
fn_10_A634_s16 unk_12E;
fn_10_A634_s16 unk_130;
fn_10_A634_s16 unk_132;
fn_10_A634_s16 unk_134;
fn_10_A634_s16 unk_136;
fn_10_A634_s16 unk_138;
fn_10_A634_s16 unk_13A;
fn_10_A634_s16 unk_13C;
fn_10_A634_u8 pad_13E[0x2];
fn_10_A634_u32 unk_140;
fn_10_A634_u8 pad_144[0x2];
fn_10_A634_s16 unk_146;
fn_10_A634_s16 unk_148;
fn_10_A634_u8 pad_14A[0x2];
} fn_10_A634_Obj_1_bss_8B3A0;

/* fn_10_A634 */
typedef struct {
fn_10_A634_u16 unk_0;
fn_10_A634_u16 unk_2;
fn_10_A634_u8 pad_4[0x4];
fn_10_A634_u16 unk_8;
fn_10_A634_u16 unk_A;
fn_10_A634_u8 pad_C[0x4];
fn_10_A634_u16 unk_10;
fn_10_A634_u16 unk_12;
fn_10_A634_u8 pad_14[0x3C];
} fn_10_A634_Obj_1_bss_9F8;

/* fn_10_A634 */
typedef struct fn_10_A634_FontDrawPacket fn_10_A634_FontDrawPacket;

/* fn_10_A634 */
typedef struct fn_10_A634_FontVertex {
fn_10_A634_f32 x, y, z;
} fn_10_A634_FontVertex;

/* fn_10_A634 */
struct fn_10_A634_E9C8 { fn_10_A634_u8 pad[10]; fn_10_A634_s8 id; fn_10_A634_u8 pad2; };

/* fn_10_A634 */
struct fn_10_A634_lbl_1_bss_8B3A0 {
fn_10_A634_u8 pad_0[0x98];
fn_10_A634_u32 unk_98;
};

/* fn_10_A634 */
struct fn_10_A634_E9F8 { fn_10_A634_u8 pad[0x10]; fn_10_A634_u16 a; fn_10_A634_u16 b; };

/* fn_10_A7DC */
struct fn_10_A7DC_SelState {
    s16 value;
    u8 padding[0x90];
    u32 flags;
};

/* fn_10_A90C */
struct fn_10_A90C_lbl_1_bss_8B3A0 {
    s16 value;
    u8 pad_0[0x92];
    u32 flags;
    u32 unk_98;
};

/* fn_10_AB98 */
typedef signed char fn_10_AB98_s8;

/* fn_10_AB98 */
typedef signed short fn_10_AB98_s16;

/* fn_10_AB98 */
typedef signed long fn_10_AB98_s32;

/* fn_10_AB98 */
typedef unsigned char fn_10_AB98_u8;

/* fn_10_AB98 */
typedef unsigned short fn_10_AB98_u16;

/* fn_10_AB98 */
typedef unsigned long fn_10_AB98_u32;

/* fn_10_AB98 */
typedef float fn_10_AB98_f32;

/* fn_10_AB98 */
typedef struct {
fn_10_AB98_u8 pad_0[0x19];
fn_10_AB98_u8 unk_19;
} fn_10_AB98_Obj_1_bss_8B3A0_AtA4;

/* fn_10_AB98 */
typedef struct {
fn_10_AB98_s16 unk_0;
fn_10_AB98_u8 pad_2[0x2];
fn_10_AB98_s16 unk_4;
fn_10_AB98_u8 pad_6[0x2];
fn_10_AB98_s16 unk_8;
fn_10_AB98_u8 pad_A[0x4];
fn_10_AB98_s16 unk_E;
fn_10_AB98_u8 pad_10[0x4];
fn_10_AB98_u8 unk_14;
fn_10_AB98_u8 pad_15[0x19];
fn_10_AB98_s16 unk_2E;
fn_10_AB98_u8 pad_30[0x5C];
fn_10_AB98_s16 unk_8C;
fn_10_AB98_u8 pad_8E[0x2];
fn_10_AB98_s16 unk_90;
fn_10_AB98_s16 unk_92;
fn_10_AB98_u32 unk_94;
fn_10_AB98_u8 pad_98[0x6];
fn_10_AB98_u8 unk_9E;
fn_10_AB98_u8 unk_9F;
fn_10_AB98_u8 pad_A0[0x4];
fn_10_AB98_Obj_1_bss_8B3A0_AtA4 *unk_A4;
fn_10_AB98_u8 pad_A8[0x8];
fn_10_AB98_s16 unk_B0;
fn_10_AB98_s16 unk_B2;
fn_10_AB98_u8 pad_B4[0xC];
fn_10_AB98_s16 unk_C0;
fn_10_AB98_s16 unk_C2;
fn_10_AB98_u8 pad_C4[0xC];
fn_10_AB98_s16 unk_D0;
fn_10_AB98_s16 unk_D2;
fn_10_AB98_u8 pad_D4[0xC];
fn_10_AB98_u32 unk_E0;
fn_10_AB98_u32 unk_E4;
fn_10_AB98_u32 unk_E8;
fn_10_AB98_u32 unk_EC;
fn_10_AB98_u32 unk_F0;
fn_10_AB98_u32 unk_F4;
fn_10_AB98_u32 unk_F8;
fn_10_AB98_u32 unk_FC;
fn_10_AB98_u32 unk_100;
fn_10_AB98_u32 unk_104;
fn_10_AB98_u32 unk_108;
fn_10_AB98_u32 unk_10C;
fn_10_AB98_u32 unk_110;
fn_10_AB98_u32 unk_114;
fn_10_AB98_u32 unk_118;
fn_10_AB98_u32 unk_11C;
fn_10_AB98_u32 unk_120;
fn_10_AB98_u32 unk_124;
fn_10_AB98_u8 unk_128;
fn_10_AB98_u8 unk_129;
fn_10_AB98_u8 pad_12A[0x2];
fn_10_AB98_s16 unk_12C;
fn_10_AB98_s16 unk_12E;
fn_10_AB98_s16 unk_130;
fn_10_AB98_s16 unk_132;
fn_10_AB98_s16 unk_134;
fn_10_AB98_s16 unk_136;
fn_10_AB98_s16 unk_138;
fn_10_AB98_s16 unk_13A;
fn_10_AB98_s16 unk_13C;
fn_10_AB98_u8 pad_13E[0x2];
fn_10_AB98_u32 unk_140;
fn_10_AB98_u8 pad_144[0x2];
fn_10_AB98_s16 unk_146;
fn_10_AB98_s16 unk_148;
fn_10_AB98_u8 pad_14A[0x2];
} fn_10_AB98_Obj_1_bss_8B3A0;

/* fn_10_AB98 */
typedef struct fn_10_AB98_FontDrawPacket fn_10_AB98_FontDrawPacket;

/* fn_10_AB98 */
typedef struct fn_10_AB98_FontVertex {
fn_10_AB98_f32 x, y, z;
} fn_10_AB98_FontVertex;

/* fn_10_AB98 */
typedef struct fn_10_AB98_fn_10_AB98_SelCursor {
fn_10_AB98_u8 pad_0[0x8C];
fn_10_AB98_s16 unk_8C;
fn_10_AB98_s16 unk_8E;
fn_10_AB98_s16 unk_90;
fn_10_AB98_u8 pad_92[2];
fn_10_AB98_u32 unk_94;
} fn_10_AB98_fn_10_AB98_SelCursor;

/* fn_10_AB98 */
struct fn_10_AB98_SelState {
fn_10_AB98_s16 value;
};

/* fn_10_AE14 */
typedef struct fn_10_AE14_Cursor {
    u8 pad_0[0x8C];
    s16 group;      /* 0x8C: 0 = flat list, else grid row */
    s16 column;     /* 0x8E */
    s16 index;      /* 0x90 */
    u8 pad_92[0x2];
    u32 flags;      /* 0x94 */
} fn_10_AE14_Cursor;

/* fn_10_AE14 */
typedef struct fn_10_AE14_Sel {
    s16 mode;
    u8 pad_2[0x96];
    u32 players;    /* 0x98: active player mask, bit n+1 = player n */
    s16 option;     /* 0x9C */
} fn_10_AE14_Sel;

/* fn_10_AE14 */
typedef struct fn_10_AE14_Pad {
    u8 pad_0[0x2];
    u16 held;
} fn_10_AE14_Pad;

/* fn_10_B2C8 */
typedef struct {
    s16 unk_0;
    u8 pad_2[0x1A];
} fn_10_B2C8_Record;

/* fn_10_B2C8 */
typedef struct {
    u8 pad_0[0x24];
    fn_10_B2C8_Record unk_24[4];
} fn_10_B2C8_Course;

/* fn_10_B2C8 */
typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x4];
    u8 unk_14;
    u8 pad_15[0xB];
} fn_10_B2C8_Player;

/* fn_10_B2C8 */
typedef struct {
    union {
        fn_10_B2C8_Player players[4];
        struct {
            s16 unk_0;
            u8 pad_2[0x2];
            s16 unk_4;
        } hdr;
    } u;
    u8 pad_80[0xC];
    s16 unk_8C;
    u8 pad_8E[0x6];
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[0x8];
    fn_10_B2C8_Course *unk_A4;
    u8 pad_A8[0x81];
    u8 unk_129;
    u8 pad_12A[0x22];
} fn_10_B2C8_Obj_1_bss_8B3A0;

/* fn_10_B2C8 */
typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} fn_10_B2C8_Pad;

/* fn_10_B2C8 */
typedef struct {
    s16 key;
    u16 pad;
    u32 mask;
} fn_10_B2C8_Cell;

/* fn_10_B2C8 */
typedef struct {
    u32 unk_0;
    u8 pad_4;
    u8 unk_5;
    u8 pad_6[0x819A];
    u8 unk_81A0;
    u8 pad_81A1[0x1F];
} fn_10_B2C8_Custom;

/* fn_10_B2C8 */
typedef struct {
    u8 pad_0[0x12];
    s8 unk_12;
    u8 pad_13;
} fn_10_B2C8_Slot;

/* fn_10_BD64 */
typedef struct fn_10_BD64_Fn10BD64 {
    s16 unk0;
    s16 unk2;
    s16 value4;
    s16 value6;
    s16 unk8;
    u8 padA[0x8A];
    u32 flags94;
} fn_10_BD64_Fn10BD64;

/* fn_10_BD64 */
typedef struct {
    u8 pad0[0x94];
    u32 flags;
} fn_10_BD64_SelGlobal;

/* fn_10_BEF8 */
typedef struct {
    s16 unk0;
    u8 pad2[2];
    s16 field4;
    s16 field6;
    s16 field8;
    u8 padA[0x8A];
    u32 flags;
} fn_10_BEF8_SelState;

/* fn_10_BEF8 */
typedef struct {
    u8 pad0[0x94];
    u32 flags;
} fn_10_BEF8_SelGlobal;

/* fn_10_C084 */
typedef struct fn_10_C084_SelState {
    short value;
    unsigned char pad_02[2];
    short minimum;
    short maximum;
    short extra;
    unsigned char pad_0A[0x8A];
    unsigned int flags;
} fn_10_C084_SelState;

/* fn_10_C084 */
typedef struct fn_10_C084_SelGlobal {
    unsigned char pad_0094[0x94];
    unsigned int flags;
} fn_10_C084_SelGlobal;

/* fn_10_C210 */
typedef struct fn_10_C210_SelOwner {
    unsigned char pad_00A4[0xA4];
    void *entries;
} fn_10_C210_SelOwner;

/* fn_10_C210 */
typedef struct fn_10_C210_SelEntry {
    unsigned char pad_0014[0x14];
    short value;
    unsigned char pad_0024[0x0E];
    unsigned char pad_0032[0x70];
} fn_10_C210_SelEntry;

/* fn_10_C258 */
typedef struct fn_10_C258_SelContext {
    u8 pad[0xa4];
    u8 *entries;
} fn_10_C258_SelContext;

/* fn_10_C274 */
typedef struct {
    u8 _pad_00[0xa4];
    u8 *entries;
} fn_10_C274_SelObject;

/* fn_10_C298 */
typedef struct fn_10_C298_SelObject {
    u8 _pad_a4[0xa4];
    u8 *entries;
} fn_10_C298_SelObject;

/* fn_10_C328 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    s16 unk_8;
    s16 unk_A;
    u8 unk_C;
    u8 pad_D[7];
    u32 unk_10;
} fn_10_C328_Obj_10_bss_0;

/* fn_10_C328 */
typedef struct {
    u8 pad_0[0x94];
    u32 unk_94;
    u8 pad_98[0xA8];
    u32 unk_140;
} GState;

/* fn_10_C49C */
typedef struct {
    u8 unk_0;  
    u8 pad_1[0xF];
} Obj_10_bss_49390;

/* fn_10_C5E0 */
struct Fn10C5E0 {
    u32 field_0;
};

/* fn_10_C8E4 */
typedef struct {
    u32 unk_0;  
    u8 pad_4[0xC];
} Obj_10_bss_55670;

/* fn_10_C958 */
typedef struct Fn10C958Data {
    u8 unk00;
    u8 unk01[3];
    u32 unk04;
    u8 unk08[4];
    void *unk0c;
    u8 unk10[20];
} Fn10C958Data;

/* fn_10_CB20 */
typedef struct fn_10_CB20_S9F8 {
    u8 pad_0[8];
    u16 f8;
    u8 pad_1[0x14 - 0xA];
} fn_10_CB20_S9F8;

/* fn_10_CB20 */
typedef struct fn_10_CB20_S9C8 {
    u8 pad_0[0xA];
    s8 fA;
    u8 pad_1[1];
} fn_10_CB20_S9C8;

/* fn_10_CB20 */
typedef struct fn_10_CB20_SelState {
    u8 pad_0[0x94];
    u32 flags_94;
    u32 bits_98;
    u8 pad_9C[2];
    u8 idx_9E;
    u8 pad_9F[0xA1];
    u32 field_140;
} fn_10_CB20_SelState;

/* fn_10_CD90 */
struct fn_10_CD90_lbl_10_bss_51740 {
    u32 unk_0;
};

/* fn_10_CF50 */
typedef struct {
    u8 pad_0[0x20];
    u32 unk_20;  
    u32 unk_24;  
    u32 unk_28;  
    u8 pad_2C[0x3CC];
} Obj_10_data_908;

/* fn_10_CF50 */
typedef void (*SelCallback)(void);

/* fn_10_CF50 */
typedef struct fn_10_CF50_SelEntry {
    u8 pad[0x20];
    SelCallback callback;
    u32 value_24;
    u32 value_28;
} fn_10_CF50_SelEntry;

/* fn_10_CFAC */
struct fn_10_CFAC_lbl_1_bss_8B3A0 {
    u8 pad_0[0x140];
    u32 unk_140;
    u16 unk_144;
    u16 unk_146;
    u16 unk_148;
};

/* fn_10_CFDC */
typedef struct fn_10_CFDC_SelState {
    u8 _pad140[0x140];
    u32 flags;
    s16 step;
    s16 value;
    s16 limit;
} fn_10_CFDC_SelState;

typedef struct SelScene {
    char name[32];
    void (*init)(void);
    void (*main)(void);
    void (*disp)(void);
} SelScene;

extern SelScene lbl_10_data_908[];
/* ---- one declaration per symbol */
void fn_10_12D8(void);
void fn_10_1544(void);
void fn_10_1F28(void);
void fn_10_1F9C(void);
void fn_10_21EC(void);
void fn_10_3268(void);
void fn_10_3350(void);
void fn_10_3954(void);
void fn_10_3A98(void);
void fn_10_3B44(void);
void fn_10_3C14(void);
s16 fn_10_3D64(void);
void fn_10_3DE0(u8 index, fn_10_3DE0_SelEntry *entries, s16 slot);
void fn_10_3F54(void);
void fn_10_436C(void);
void fn_10_4568(void);
void fn_10_4600(void);
void fn_10_472C(void);
void fn_10_4790(void);
void fn_10_4838(void);
void fn_10_4A84(void);
u32 fn_10_4AE0(u32 arg0, u32 initial_count);
void fn_10_4D78(void);
void fn_10_5148(void);
void fn_10_51BC(void);
void fn_10_51CC(void);
void fn_10_5230(void);
void fn_10_5780(struct Fn105780 *obj);
s16 fn_10_578C(void *arg0);
fn_10_5E94_s16 fn_10_5E94(void *arg0);
void fn_10_6518(void);
void fn_10_7130(void);
void fn_10_7320(void);
void fn_10_73AC(void);
void fn_10_757C(void);
void fn_10_75D4(void);
void fn_10_7A10(void);
void fn_10_7E84(void);
void fn_10_7FC0(void);
void fn_10_804C(void);
void fn_10_82BC(void);
void fn_10_8314(void);
void fn_10_83C0(void);
void fn_10_84DC(void);
void fn_10_8538(void);
void fn_10_8600(void);
u8 fn_10_8780(void);
void fn_10_8800(void);
void fn_10_8870(void);
void fn_10_8930(void);
void fn_10_8AAC(void);
void fn_10_8B0C(void);
void fn_10_8BB8(void);
void fn_10_8D90(void);
void fn_10_8DFC(void);
void fn_10_8F0C(void);
void fn_10_9154(void);
int fn_10_91E8(void);
void fn_10_924C(u8 *arg0);
void fn_10_948C(void *context, void *arg);
void fn_10_95A0(fn_10_95A0_SelBlock *data);
void fn_10_96F8(void *first, void *second);
void fn_10_9788(void *argInput);
s16 fn_10_A0E8(SelState *state);
void fn_10_A25C(SelObjA25C *obj);
void fn_10_A480(struct fn_10_A480_Arg0 *arg0);
void fn_10_A634(void *arg0);
int fn_10_A7DC(s16 mode);
void fn_10_A90C(SelState *state);
void fn_10_AB98(fn_10_AB98_fn_10_AB98_SelCursor *cursor);
void fn_10_AE14(fn_10_AE14_Cursor *cursor);
s16 fn_10_B2C8(fn_10_B2C8_Obj_1_bss_8B3A0 *arg0);
void fn_10_BD64(SelState *self);
void fn_10_BEF0(SelState *state);
void fn_10_BEF4(SelState *state);
void fn_10_BEF8(fn_10_BEF8_SelState *state);
void fn_10_C084(fn_10_C084_SelState *state);
void fn_10_C210(fn_10_C210_SelOwner *, s16);
s16 fn_10_C258(fn_10_C258_SelContext *self, s32 index);
void fn_10_C274(fn_10_C274_SelObject *object, int index);
void fn_10_C298(fn_10_C298_SelObject *self, int index);
void fn_10_C2BC(void);
void fn_10_C328(void);
void fn_10_C49C(void);
void fn_10_C594(void);
void fn_10_C5E0(void **handle);
void fn_10_C654(u32 *value);
u32 fn_10_C684(void);
u8 fn_10_C694(void);
void fn_10_C6A4(void);
void fn_10_C8A8(void);
void fn_10_C8E4(void);
// fn_10_C954: empty in retail (single blr). void fn_10_C954(void);
void fn_10_C958(void);
void fn_10_C9B0(void);
// fn_10_C9F4: empty in retail (single blr). void fn_10_C9F4(void);
void fn_10_C9F8(void);
void fn_10_CA58(void);
// fn_10_CA90: empty in retail (single blr). void fn_10_CA90(void);
void fn_10_CA94(void);
void fn_10_CB20(void);
void fn_10_CD90(void);
void fn_10_CDE8(void);
void fn_10_CE5C(void);
void fn_10_CE6C(void);
void fn_10_CEC4(u32 flags);
void fn_10_CF30(u32 shift);
void fn_10_CFAC(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern SelD5B8 lbl_1_rodata_D5B8[];
extern SelD5DC lbl_1_rodata_D5DC[];
extern u32 lbl_1_rodata_D870[];
extern SelD888 lbl_1_rodata_D888[];
extern u16 lbl_1_rodata_D8B8[];
extern u8 fn_1_128DD8(u8);
extern void fn_1_3EF8C(u8);
extern void fn_1_3FCB0(s32);
extern void fn_1_3FCD4(u32);
extern void fn_1_3ED8C(u32, u32, u32, u32, u32, u32, u32);
extern void fn_1_52E0(u8);
extern void fn_1_5328(u8);
extern u8 * fn_1_36AD0(void);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_3EC88(u32, TitleSlotInfo *);
extern void fn_1_3F4B8(s32, s32, s32, s32, s32, u8);
extern void fn_1_3F800(u32);
extern void fn_1_3F810(u8, u32);
extern void fn_1_3F834(u8);
extern void fn_1_3F844(u16);
extern s16 lbl_1_bss_964;
extern void fn_1_4A00(s32, u8, u32);
extern u32 fn_8004CD70(u32, void *, u32);
extern void fn_1_A176C(void *, u32);
extern void fn_1_12F1E8(s32);
extern void fn_10_E294(void);
s32 lbl_10_bss_51740;
u32 lbl_10_bss_51744;
extern SelRow lbl_1_bss_9C8[4];
extern SelInput lbl_1_bss_9F8[4];
extern void fn_1_12F150(s16, u32, u32);
extern u32 fn_1_426C(u32);
extern u8 lbl_1_bss_8CA24;
extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;
extern u32 fn_10_F57C(void);
extern u32 fn_1_EB29C(void);
extern int fn_1_F89E4(u8);
u16 lbl_10_bss_5174E;
u8 lbl_10_bss_51750;
u16 lbl_10_bss_51752;
extern u8 fn_1_D6690(void);
extern u8 fn_1_D6698(void);
extern s32 fn_1_12F228(void);
extern u32 fn_1_EB4BC(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_12EF80(u32, void *, void *);
extern void fn_1_7B218(s32);
extern void fn_1_7B2E8(u32);
extern void fn_1_A51C8(s16);
extern void fn_1_EB330(void);
extern void fn_1_EC910(void);
extern void fn_1_7B4C0(void);
u8 lbl_10_bss_51754;
s32 lbl_10_bss_51758[4];
Pair lbl_10_bss_51768[4];
u8 lbl_10_bss_51788[0x64];
u8 lbl_10_bss_517EC[0x190];
u8 lbl_10_bss_5197C[0x190];
extern s16 lbl_1_bss_966;
extern void fn_1_12C0EC(void *);
extern void fn_1_151EF8(s16 *, s16, void *, s16, s16);
extern void fn_1_12F10C(void *);
extern u16 fn_1_A5D88(void);
extern void fn_1_12BF7C(void *, s16, u32, u32);
extern void fn_10_FF08(void);
extern int fn_1_B7F58(s64 *);
extern void fn_1_13F81C(void);
extern void fn_1_13F948(void);
extern void fn_1_FE004(void);
extern void fn_10_2324C(void);
extern u8 fn_10_12D8__fzgx_offset_1C0[];
extern u8 fn_10_12D8__fzgx_offset_1CC[];
extern u8 fn_10_12D8__fzgx_offset_1D8[];
extern u8 fn_10_12D8__fzgx_offset_1E4[];
extern u8 fn_10_12D8__fzgx_offset_1F0[];
extern u8 fn_10_12D8__fzgx_offset_1F8[];
extern u8 fn_10_D2C__fzgx_offset_118[];
extern u8 fn_10_D2C__fzgx_offset_150[];
extern u8 fn_10_D2C__fzgx_offset_5C[];
extern u8 fn_10_D2C__fzgx_offset_68[];
extern u8 fn_10_D2C__fzgx_offset_FC[];
extern u8 fn_1_128B00(s16);
extern s16 fn_1_14F270(u8, s16, u32);
extern u32 fn_1_151BE8(u8, s32);
extern int lbl_1_bss_7180C;
extern int fn_1_B7E98(int);
extern void fn_1_13F848(u8);
extern void fn_1_13F974(u8);
extern SelResult *fn_1_13F8B0(u8);
extern fn_10_3DE0_SelObject *fn_1_13F9DC(u8);
extern u32 fn_1_7F254(fn_10_3DE0_SelEntry *, s16);
extern void fn_1_FD324(void);
extern void fn_1_FDC00(void);
extern void fn_1_FD27C(void);
extern u32 fn_1_FD844(fn_10_3DE0_SelEntry *, void *);
extern const f64 lbl_10_rodata_48;
extern u32 lbl_1_bss_6EAB4;
extern void fn_10_2323C(void);
extern void fn_1_1280(u32);
extern void fn_1_FDFF4(void);
extern void fn_1_4BB0(void);
extern void fn_1_12C000(void *, s32);
extern void fn_1_12AF7C(void);
extern void fn_1_13F8C4(void);
extern void fn_1_13F9F0(void);
extern void fn_10_21E30(void);
extern void fn_1_34E08(void);
extern u32 lbl_801A66C0;
extern s32 fn_1_467F4(void);
extern void fn_10_2228C(void);
extern void fn_10_25E1C(void);
extern u32 fn_1_15BB34(void *);
extern struct fn_10_4838_lbl_10_bss_55CE0 lbl_10_bss_55CE0;
extern u32 fn_1_15BBC4(void);
extern u8 fn_10_26000(void);
extern void fn_1_14BD44(void *, void *);
extern void fn_10_260D4(void);
extern s32 lbl_1_bss_980[4];
extern int fn_1_152840(s16, fn_10_4AE0_Sig_fn_1_152840_Entry *, s16, s16);
extern void fn_10_13D64(void);
extern u8 *lbl_1_bss_718C0;
extern u32 lbl_801A63C0;
extern int fn_1_8623C(void);
extern void fn_1_12B4EC(s16, s16);
extern void fn_1_12B120(u8 *, void *, void *, s32 *, void *, s32 *);
extern void fn_1_7B084(void *, int);
extern void fn_1_9A958(int, int);
extern void fn_1_46EA8(u32);
extern void fn_1_4100C(void);
extern void fn_1_8001C(void);
s32 lbl_10_bss_51B0C;
s32 lbl_10_bss_51B10;
fn_10_5230_Desc lbl_10_bss_51B14;
extern u32 lbl_801A66A8;
extern int fn_1_13FB24(u32);
extern u32 fn_1_F9FEC(void);
extern void fn_1_12F128(s16);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);
extern int fn_1_4F734(fn_10_5E94_FontDrawPacket *);
extern void fn_1_4EDAC(fn_10_5E94_FontDrawPacket *, fn_10_5E94_f32, fn_10_5E94_f32);
extern void fn_1_51678(fn_10_5E94_FontDrawPacket *, fn_10_5E94_u32, fn_10_5E94_s16, fn_10_5E94_s16, fn_10_5E94_s16, fn_10_5E94_s16);
extern void fn_1_517EC(fn_10_5E94_FontDrawPacket *, fn_10_5E94_s16, fn_10_5E94_s16, fn_10_5E94_s16, fn_10_5E94_s16, fn_10_5E94_s16, fn_10_5E94_s16);
extern fn_10_5E94_u32 fn_1_13FA88(fn_10_5E94_s16);
extern u8 fn_1_D6740(u8);
extern u8 fn_1_D66B0(void);
extern void fn_1_D66F8(u8, s8 *, s8 *);
extern u8 fn_1_D66B8(u8);
extern void fn_1_12B5B4(s16, s16);
extern s16 fn_1_12B3BC(void *, void *, void *, void *, void *, s32 *, s32);
extern void fn_1_7B184(s32);
extern void fn_1_9AA2C(s32);
extern void fn_1_12E0B8(s16, s16, void *, void *, s32, const char * *, u32);
extern void fn_800713E0(u32, u32);
extern void fn_1_8019C(u32);
extern void fn_1_12B3F8(void *, u32, u32, void *, void *, void *);
extern void fn_1_12C6BC(u32);
extern void fn_10_1B658(void);
extern int __rlwnm(int, int, int, int);
extern u32 lbl_1_bss_6D82C;
extern void fn_1_12AB38(void *);
extern u32 fn_1_D3884(void *);
extern s16 fn_1_12C930(s16);
extern void fn_1_8F198(void *, s32, u32, u32);
extern s16 fn_1_12CCB0(s16, s16);
extern s32 fn_1_12CB04(s16);
extern void fn_10_1AD5C(void);
u8 lbl_10_bss_51B7C[0x1380];
extern void fn_1_8F62C(void *);
extern u32 fn_1_12F258(void);
extern void fn_1_8F494(void *);
extern void fn_80071718(void *);
extern void fn_10_1B65C(void);
extern void fn_10_1B664(void);
extern u32 fn_10_25610(u32, u32, u32);
extern void fn_10_25CB0(void);
extern s32 fn_10_25888(void);
extern void fn_10_25BC8(void);
extern void fn_10_1B684(void);
extern u8 fn_1_D6688(void);
u8 lbl_10_bss_52EFC[0x2700];
s32 lbl_10_bss_555FC;
extern u8 fn_1_D66A8(void);
extern u8 fn_1_D66A0(int);
extern void fn_10_1B6A8(void);
extern u32 fn_10_1B2F4(void);
extern void fn_10_1E41C(void);
extern void fn_1_B7F24(void);
u8 lbl_10_bss_55600;
extern void * fn_1_7F518(s16, void *, s32);
extern int sprintf(char *, const char *, ...);
extern s32 fn_1_12A32C(void *);
extern void fn_1_12A2B8(u32);
extern void fn_1_80270(void *, void *);
extern void fn_1_80058(s8, u8 *);
extern void fn_1_80C18(u8 *, u8 *, s8);
extern void fn_1_14DB48(fn_10_948C_SelEntry *, void *, u32);
extern void fn_1_12A2D0(s32);
extern void fn_1_12C5E4(void *);
extern void fn_1_12A734(s32);
extern void fn_1_14DBCC(void *);
extern u32 fn_1_A2A70(u32, u32);
extern int fn_1_D6680(void);
extern void fn_1_D66F4(void);
u8 lbl_10_bss_55601;
extern int fn_1_FA070(void);
extern int fn_1_FA0BC(int);
extern void fn_1_12F358(s16);
extern fn_10_AE14_Pad lbl_1_bss_D58;
extern const char *lbl_1_data_407BC[];
extern s16 fn_1_152FAC(s16, s16, s16, s16, fn_10_B2C8_Cell *, s16, s16);
extern s16 fn_1_152A28(s16, s16, s16, fn_10_B2C8_Cell *, s16, s16);
extern void fn_1_12ECA8(s16, s16, void *, void *, void *);
extern void fn_1_A50C8(s32);
extern void * fn_1_12D254(s16, u32);
extern void fn_80006E10(const char *);
extern void fn_1_7F58C(s16, char *, u8, s32);
extern void fn_1_36A94(u8, fn_10_B2C8_Custom *);
u32 lbl_10_bss_55604;
s16 lbl_10_bss_55608;
extern void fn_1_130EE8(u32, u32);
extern s32 fn_1_1310E0(void);
extern void fn_1_131084(u32, s32);
fn_10_B2C8_Slot lbl_10_bss_5560C[4];
extern int fn_1_1317B4(void);
extern int fn_1_B7C5C(void);
extern void fn_1_131004(void);
extern void fn_1_451E4(void);
extern void fn_1_3308(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern s32 fn_1_13018(void);
extern void fn_8006FDEC(void);
extern u32 fn_1_46C60(void);
u32 lbl_10_bss_5565C;
s32 lbl_10_bss_55660;
extern u32 lbl_1_bss_718E0;
extern s32 fn_1_B7C6C(u32);
extern u32 fn_1_B7CD4(void);
extern void fn_1_AA6D8(int, int, void *);
extern void fn_1_F79C8(void);
u32 lbl_10_bss_55668;
extern void fn_10_1B660(void);
extern void fn_10_13E18(void);
extern void (*lbl_1_bss_71688)(void);
extern void (*lbl_1_bss_7168C)(void);
u8 lbl_10_bss_5566C;
Obj_10_bss_55670 lbl_10_bss_55670;

/* fzgx:begin fn_10_0 */
s16 fn_10_0(s16 *first, s16 *second, s16 third, u32 fourth) {
    return fn_1_152970(second, first, third, fourth, lbl_10_bss_1C[0], lbl_10_bss_1A, lbl_10_bss_18);
}
/* fzgx:end fn_10_0 */

/* fzgx:begin _prolog */
static inline void sel_reset_players(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        lbl_1_bss_8B3A0.players[i].car = -1;
        lbl_1_bss_8B3A0.unk_9F[i] = 50;
        fn_1_A5330(50, i);
    }
}

void _prolog(void) {
    SelArcInfo info;
    SelState *state;
    u32 heap;
    u32 size;
    s16 i;

    if (lbl_1_bss_8B3A0.unk_A != -1) {
        lbl_1_bss_8B3A0.unk_8 = lbl_1_bss_8B3A0.unk_A;
    }
    state = &lbl_1_bss_8B3A0;
    state->unk_9E = 0;
    state->unk_94 &= ~0x200;
    if (!(state->unk_94 & 0x40000000)) {
        state->unk_94 |= 0x100;
    }
    if (fn_1_45730("vehicle/vehicle_sel.arc.lz", &info) == 0) {
        OSPanic(lbl_10_data_57C, 0x298, "vehicle archive file is nothing");
    }
    lbl_10_bss_10 = ((u32)fn_1_45B2C(&info) + 0x1F) & ~0x1F;
    fn_1_45850(&info);
    lbl_1_bss_8B5F4[0] = 0;
    lbl_1_bss_8B5F4[1] = 0;
    lbl_1_bss_8B5F4[2] = 0;
    lbl_1_bss_8B5F4[3] = 0;
    lbl_1_bss_8B5F4[4] = 0;
    lbl_1_bss_8B5F4[5] = 0;
    lbl_1_bss_8B5F4[6] = 0;
    lbl_1_bss_8B5F4[7] = 0;
    fn_80008BEC(lbl_10_bss_3C0, 0, sizeof(lbl_10_bss_3C0));
    fn_1_A0680();
    lbl_10_bss_4 = fn_1_4630(lbl_801A6410, 0xC24, lbl_10_data_57C, 0x2A9);
    lbl_10_bss_49380 = fn_1_4630(lbl_801A6410, 41 * sizeof(SelCarEntry), lbl_10_data_57C, 0x2AA);
    for (i = 0; i < 41; i++) {
        lbl_10_bss_49380[i].unk_324 = -1;
    }
    lbl_10_bss_0 = (void *)fn_1_45D0(lbl_801A6410, fn_1_7BA08(32, 32, 64), lbl_10_data_57C, 0x2AC);
    fn_1_7BA48(lbl_10_bss_0);
    lbl_10_bss_49384 = fn_1_45D0(lbl_801A6410, 0x173C, lbl_10_data_57C, 0x2AD);
    fn_1_3CF0(lbl_10_bss_49384, 0x80);
    lbl_10_bss_49388 = fn_1_45D0(lbl_801A6410, 0x173C, lbl_10_data_57C, 0x2AE);
    fn_1_3CF0(lbl_10_bss_49388, 0x80);
    fn_1_5124(lbl_10_bss_49384, lbl_10_bss_49388);
    fn_1_411A4(1);
    if (state->unk_94 & 0x40000000) {
        fn_1_48418(2);
        fn_1_479F0(lbl_1_bss_960);
        fn_1_469BC();
        fn_1_4706C();
        fn_1_46A60();
        fn_1_159440(1, 0);
        fn_1_159440(2, 0);
        fn_1_159440(3, 0);
    } else if (state->unk_94 & 0x02000000) {
        fn_1_47F74(0x9A);
        fn_1_47F74(0x9B);
        fn_1_47F74(0x30);
    } else {
        fn_1_48418(2);
        fn_1_47F74(0x9A);
        fn_1_47F74(0x9B);
        fn_1_47F74(0x9D);
        fn_1_47F74(0xA1);
        fn_1_47F74(0x9C);
        fn_1_47F74(0xA2);
        fn_1_469BC();
        fn_1_4706C();
        fn_1_46A60();
        fn_1_159440(2, 1);
    }
    fn_1_52070(0x140);
    if (!(state->unk_94 & 0x02000000) && !(state->unk_94 & 0x80000000)) {
        heap = fn_1_4404();
        size = fn_800090A4(lbl_801A6410) - 0x10000;
        lbl_10_data_578 = (void *)fn_1_45D0(lbl_801A6410, size, lbl_10_data_57C, 0x2ED);
        fn_1_46BA0(lbl_10_data_578, size);
        fn_1_46A8C((fn_1_46ED8() & ~0x1F) - lbl_10_bss_10);
        fn_1_465D0("vehicle/vehicle_sel.arc.lz", 2);
        fn_1_46B44(fn_10_C654, lbl_1_bss_8B5F4);
        if (!(state->unk_94 & 0x20)) {
            fn_1_41104(1);
            fn_1_41104(6);
            fn_1_47E54(0x9A);
            fn_1_47E54(0x9B);
            fn_1_47E54(0xBA);
            fn_1_47E54(0xA0);
        }
        fn_1_46BFC();
        lbl_10_bss_C = 1;
        fn_1_46B44(fn_10_C5E0, &lbl_10_data_578);
        fn_80008E84(heap);
    }
    lbl_1_bss_970.unk_0 = 0;
    lbl_1_bss_970.unk_4 = 13;
    fn_8006CE1C(0.0f);
    fn_1_435C(lbl_10_bss_49388);
    fn_1_3F8C("LightMain", fn_1_7BAF8, lbl_10_bss_0, 2);
    lbl_1_bss_8B3A0.unk_129 = 1;
    lbl_1_bss_8B3A0.unk_A4 = lbl_10_bss_4;
    if (!(state->unk_94 & 0x30)) {
        lbl_1_bss_8B3A0.unk_0 = -1;
    }
    state->unk_94 &= ~0x08000000;
    state->unk_94 &= ~0x04000000;
    state->unk_94 &= ~0x01000000;
    state->unk_94 &= ~0x00200000;
    state->unk_94 &= ~0x00100000;
    state->unk_94 &= ~0x00080000;
    state->unk_94 &= ~0x80;
    state->unk_94 &= ~0x40;
    if (state->unk_94 & 0x40000000) {
        s16 mode;

        mode = 0x1A;
        if (state->unk_94 & 0x2000) {
            mode = 0x16;
        }
        lbl_1_bss_96A = mode;
        for (i = 0; i < 4; i++) {
            lbl_1_bss_8B3A0.unk_9F[i] = 50;
            fn_1_A5330(50, i);
        }
        lbl_1_bss_8B3A0.unk_0 = 9;
        lbl_1_bss_8B3A0.unk_4 = 1;
        lbl_1_bss_8B3A0.unk_6 = 30;
        lbl_1_bss_8B3A0.unk_8 = 1;
        sel_reset_players();
        lbl_1_bss_8B3A0.players[0].car = 6;
        lbl_1_bss_8B3A0.unk_8C = 6;
        lbl_1_bss_8B3A0.unk_8E = 0;
        lbl_1_bss_8B3A0.unk_90 = fn_1_12EF24(6, 0);
        lbl_1_bss_8B3A0.unk_12A = 1;
        lbl_1_bss_8B3A0.unk_12B = 0;
        lbl_1_bss_8CA26 = 0;
        lbl_10_bss_18 = 0x13;
        lbl_10_bss_1A = 2;
        lbl_10_bss_4938C = 0xF;
    } else {
        lbl_1_bss_96A = 0xE;
        lbl_10_bss_18 = 0x13;
        lbl_10_bss_1A = 6;
        lbl_10_bss_4938C = 0xF;
        if (state->unk_94 & 0x20) {
            lbl_1_bss_96A = 0xF;
        } else if (state->unk_94 & 0x10) {
            lbl_1_bss_96A = 0x10;
        } else {
            lbl_1_bss_8B3A0.unk_A4->unk_0 = -1;
            fn_10_5780((struct Fn105780 *)&lbl_1_bss_8B3A0);
        }
    }
    if ((state->unk_94 & 0x40000000) || (state->unk_94 & 0x02000000)) {
        state->unk_94 |= 0x20000000;
    }
    lbl_1_bss_8B3A0.unk_98 = 0;
    lbl_1_bss_8B3A0.unk_98 |= 0x80000000 >> state->unk_9E;
    lbl_10_bss_4938E = fn_1_8D7C8() < 30 ? fn_1_8D7C8() : 30;
    lbl_1_bss_7167C = fn_10_834;
    lbl_1_bss_71680 = fn_10_AB8;
    lbl_1_bss_71684 = fn_10_CF50;
    if (state->unk_94 & 0x02000000) {
        s16 player = state->unk_9E;

        lbl_1_bss_8B3A0.unk_0 = 4;
        lbl_1_bss_8B3A0.unk_4 = 1;
        lbl_1_bss_8B3A0.unk_6 = 1;
        for (i = 0; i < 4; i++) {
            lbl_1_bss_8B3A0.players[i].car = -1;
        }
        lbl_1_bss_8B3A0.players[player].car = 6;
        lbl_1_bss_8B3A0.players[player].unk_8 = 1;
        lbl_1_bss_8B3A0.unk_9F[player] = 50;
        lbl_1_bss_8B3A0.unk_90 = 1;
        lbl_1_bss_8B3A0.unk_8C = 1;
        lbl_1_bss_8B3A0.unk_8E = 0;
        fn_1_A5330(50, player);
        lbl_10_data_45C = 0x80000000;
        lbl_1_bss_96A = 0x12;
    }
    fn_1_12F17C();
    fn_1_36ADC();
    fn_80008BEC(&lbl_1_bss_8B3A0.unk_140, 0, 0xC);
    lbl_10_bss_4938F = lbl_10_bss_49390[0] = 0;
}
/* fzgx:end _prolog */

/* fzgx:begin fn_10_834 */
void fn_10_834(void) {
    SelState *state;
    u8 *entry;
    s16 i;

    fn_10_CFDC();
    lbl_1_bss_8CA28 = 0;
    if (lbl_1_bss_8B3A0.unk_124 != 0xFFFFFFFF && lbl_1_bss_8B3A0.unk_128 == 0) {
        lbl_1_bss_8B3A0.unk_124 -= 1;
    }

    state = &lbl_1_bss_8B3A0;
    if (((state->unk_94 >> 11) & 1) == 0 && lbl_1_bss_8B3A0.unk_124 <= 300) {
        if (lbl_1_bss_8B3A0.unk_124 % 60 == 0 && lbl_1_bss_8B3A0.unk_124 != 0 && fn_1_4C10() == 0) {
            fn_1_A2D84(0xA9010C00);
        }
    }
    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    {
        int active;
        if ((lbl_1_bss_8B3A0.unk_140 & 0x80000000) != 0 &&
            (lbl_1_bss_8B3A0.unk_140 & 0x40000000) == 0 &&
            (state->unk_94 & 0x8) == 0) {
            active = 1;
        } else {
            if (fn_1_4C10()) active = 1;
            else active = 0;
        }
        if (active == 0) {
            entry = (u8 *)lbl_1_bss_8B3A0.unk_A4 + (s16)(lbl_1_bss_962 - 14) * 148;
            for (i = 0; i < 4; i++) {
                fn_1_12C060(entry + 36);
                entry += 28;
            }
            if (lbl_1_bss_962 != 20) {
                if (fn_1_4C10() == 0) {
                    if ((state->unk_94 & 0x8000000) != 0) {
                        if ((state->unk_94 & 0x200000) != 0) {
                            lbl_1_bss_9C.value_2 = lbl_1_bss_8B3A0.unk_9E;
                            lbl_1_bss_9C.value_4 = 6;
                            lbl_1_bss_9C.value_8 = 134;
                            lbl_1_bss_968 = 9;
                        } else if ((state->unk_94 & 0x100000) != 0) {
                            lbl_1_bss_968 = 3;
                        } else if ((state->unk_94 & 0x80000) != 0) {
                            lbl_1_bss_968 = 5;
                        } else if ((state->unk_94 & 0x80) != 0) {
                            lbl_1_bss_968 = 12;
                        } else if ((state->unk_94 & 0x40) != 0) {
                            lbl_1_bss_968 = 15;
                        } else {
                            lbl_1_bss_968 = 2;
                        }
                    } else if ((state->unk_94 & 0x4000000) != 0) {
                        lbl_1_bss_968 = 10;
                    } else if ((state->unk_94 & 0x1000000) != 0) {
                        lbl_1_bss_968 = 9;
                    }
                }
                fn_1_A266C();
            }
        }
    }
}
/* fzgx:end fn_10_834 */

/* fzgx:begin fn_10_AB8 */
void fn_10_AB8(void) {
    fn_1_435C(lbl_10_bss_49384);
    fn_1_407C();
    fn_1_3CC4();
    fn_1_435C(lbl_10_bss_49388);
    fn_1_407C();
}
/* fzgx:end fn_10_AB8 */

/* fzgx:begin _epilog */
void _epilog(void) {
    u32 f;

    /* The `& (v | ~v)` identity is exact for u32 (v | ~v == 0xFFFFFFFF). Finding 388. */
    f = lbl_1_bss_8B3A0.unk_94 & (lbl_1_bss_8B3A0.unk_94 | ~lbl_1_bss_8B3A0.unk_94);

    lbl_1_bss_8B3A0.unk_94 = f & 0xFFFFFFEF;
    lbl_1_bss_8B3A0.unk_94 = f & 0xFFFFFFCF;
    if (!(f & 0x80000000)) {
        fn_10_95A0((fn_10_95A0_SelBlock *)lbl_10_bss_49380);
        fn_10_96F8(lbl_10_bss_493A0, lbl_10_bss_4EEC0);
    }

    fn_1_46B4(lbl_801A6410, lbl_10_bss_4, lbl_10_data_57C, 0x424);
    fn_1_46B4(lbl_801A6410, lbl_10_bss_49380, lbl_10_data_57C, 0x425);
    fn_1_46B4(lbl_801A6410, lbl_10_bss_0, lbl_10_data_57C, 0x426);

    fn_1_435C(lbl_10_bss_49384);
    fn_1_41A8();
    fn_1_435C(lbl_10_bss_49388);
    fn_1_41A8();
    fn_1_6400();
    fn_1_46BFC();
    fn_1_46DC4((s32)"vehicle/vehicle_sel.arc.lz");

    if (lbl_1_bss_960 != 1 || lbl_1_bss_962 != 0x10) {
        if (lbl_1_bss_6EAD0 != 0) {
            fn_8004BF0C(lbl_1_bss_6EAD0->a, -999);
            fn_8004BF0C(lbl_1_bss_6EAD0->b, -999);
            ADXT_Stop(lbl_1_bss_6EAD0->a);
            ADXT_Stop(lbl_1_bss_6EAD0->b);
        }
    }

    fn_1_A0AA4();
    if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) {
        fn_1_1596DC(3);
        fn_1_1596DC(2);
        fn_1_1596DC(1);
        fn_1_47A60(lbl_1_bss_960);
        fn_1_484CC(2);
    } else {
        fn_1_1596DC(2);
        fn_1_48140(0xa2);
        fn_1_48140(0x9c);
        fn_1_48140(0xa1);
        fn_1_48140(0x9d);
        fn_1_48140(0x9b);
        fn_1_48140(0x9a);
        fn_1_48140(0x95);
        fn_1_484CC(2);
    }
    fn_1_412A0(1);
    if (lbl_1_bss_968 == 2) {
        fn_10_D2C();
    }
}
const f32 lbl_10_rodata_4[8] = {0.0f, 320.0f, 240.0f, 1e-5f, 1e-4f, 0.5f, 480.0f, 2.0f};
/* WARNING: compiler-diff device, not original code.
   Retail .rodata 0x28 holds the u32->f64 conversion constant ahead of every function that uses
   it (fn_10_6518 reads it at 0x28). The code that created it there is not in the retail .text.
   This primer in the .fzgxpool section creates the constant at its retail offset; the unit's
   pool step (poolfix.py) drops the section. */
#pragma section code_type ".fzgxpool"
static void fzgx_rodata_28(u32 i) {
    volatile f64 d;  /* fzgx-allow: S2 part of the WARNING primer above */
    d = i;
}
#pragma section code_type ".text"
/* fzgx:end _epilog */

/* fzgx:begin fn_10_D2C */
#define PLAYER(i) ((fn_10_D2C_SelPlayer *)&(*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)))[i]

#define PLAYER_DATA_SIZE 0x81C0

void fn_10_D2C(void) {
    u8 i;
    TitleSlotInfo slots[4];
    u32 arg6;
    u32 course;
    u32 count;
    s32 arg2;
    s32 sel;
    u32 playerDataSize;
    s16 bit;
    s16 v;
    u8 *pd;
    u8 loopIndex;
    u8 idx;

    idx = fn_1_128DD8((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_90);
    course = (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_90 & 0xFF;
    switch ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_0) {
    case 9:
    case 11:
        fn_1_3EF8C(6);
        break;
    case 0:
        fn_1_3EF8C(0);
        if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_6 > 4) {
            fn_1_3EF8C(6);
        }
        if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_4 < 2) {
            fn_1_3EF8C(3);
        }
        v = (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_6;
        (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_6 = v < 1 ? 1 : (v > 4 ? 4 : v);
        v = (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_4;
        (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_4 = v < 1 ? 1 : (v > 4 ? 4 : v);
        break;
    case 1:
        fn_1_3EF8C(1);
        course = (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_8C & 0xFF;
        break;
    case 3:
        if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_13A == 0) {
            fn_1_3EF8C(3);
        } else {
            fn_1_3EF8C(6);
            fn_1_3FCB0(0x4000010);
        }
        fn_1_3FCD4(0x20000);
        break;
    default:
        fn_1_3EF8C(2);
        break;
    }

    arg6 = (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_6 & 0xFF;
    count = (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_4 & 0xFF;
    if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_94 & 0x40000000) {
        u8 n = lbl_1_rodata_D5B8[idx].unk_0;
        fn_1_3ED8C(0, n, n, course, 10, arg6, 0);
    } else {
        arg2 = 3;
        if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_0 == 0) {
            arg2 = (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_13C;
            if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_130 == 1) {
                arg6 = 4;
            }
            fn_1_52E0((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_134 != 0);
            sel = 4;
            if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_12E == 0) {
                sel = 3;
            }
            fn_1_5328(sel);
            if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_132 == 1) {
                fn_1_3FCB0(0x20000);
            } else {
                fn_1_3FCD4(0x20000);
            }
            if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_138 == 1) {
                fn_1_3FCB0(0x8000);
            } else {
                fn_1_3FCD4(0x8000);
            }
        } else if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_0 == 3) {
            arg2 = (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_13A;
            arg6 = ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_12C + (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_4) & 0xFF;
            if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_136 == 1) {
                fn_1_3FCB0(0x8000);
            } else {
                fn_1_3FCD4(0x8000);
            }
        }
        fn_1_3ED8C(0, arg2 & 0xFF, 1, course, 1, arg6, 0);
    }

    if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_94 & 0x40000000) {
        for (bit = 0; bit <= 3; bit++) {
            if (PLAYER(0).unk_14 & (1 << bit)) {
                break;
            }
        }
        playerDataSize = PLAYER_DATA_SIZE;
        for (i = 0; (loopIndex = i, (s32)loopIndex < 1); i++) {
            u32 n = i;
            s8 level = PLAYER(i).unk_E;
            if (level > 40) {
                pd = fn_1_36AD0() + n * PLAYER_DATA_SIZE;
                if (!(*(u32 *)pd & 0x40000000)) {
                    level = pd[0x81A0];
                } else {
                    level = loopIndex + 50;
                }
            }
            slots[n].unk_1 = level;
            slots[n].unk_2 = PLAYER(i).unk_14;
            slots[n].unk_4 = fn_1_36AD0()[n * playerDataSize + 8];
            slots[n].unk_3 = fn_1_36AD0()[n * playerDataSize + 7];
            slots[n].unk_B = (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_9F[n];
            fn_80008BA8(slots[n].unk_6, "AV   ", 5);
        }
        fn_1_3EC88(1, slots);
    } else {
        for (i = 0; i < 4U; i++) {
            u8 n = i;
            u32 index = i;
            s16 value;
            if (PLAYER(i).unk_E > 40) {
                pd = fn_1_36AD0() + index * PLAYER_DATA_SIZE;
                PLAYER(i).unk_E = n + 50;
                if (!(*(u32 *)pd & 0x40000000)) {
                    PLAYER(i).unk_E = pd[0x81A0];
                }
            }
            value = PLAYER(i).unk_E;
            slots[index].unk_1 = value;
            slots[index].unk_2 = PLAYER(i).unk_14;
            slots[index].unk_B = (*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_9F[index];
            slots[index].unk_4 = fn_1_36AD0()[index * PLAYER_DATA_SIZE + 8];
            slots[index].unk_3 = fn_1_36AD0()[index * PLAYER_DATA_SIZE + 7];
            slots[index].unk_5 = 0;
            slots[index].unk_0 = 0;
            fn_80008BA8(slots[index].unk_6, "AV   ", 5);
        }
        fn_1_3EC88(count, slots);
    }

    if ((*((fn_10_D2C_SelState *)&lbl_1_bss_8B3A0)).unk_94 & 0x40000000) {
        SelWindow *w;
        arg6 = idx;
        w = &lbl_1_rodata_D5DC[arg6].window;
        fn_1_3F4B8(w->unk_0, (u16)(w->unk_C + w->unk_14), w->unk_E, w->unk_10, w->unk_12, w->unk_14);
        fn_1_3F800(lbl_1_rodata_D870[arg6]);
        fn_1_3F810(lbl_1_rodata_D888[arg6].unk_0, lbl_1_rodata_D888[arg6].unk_4);
        fn_1_3F834(idx);
        fn_1_3F844(lbl_1_rodata_D8B8[arg6]);
    }
}
/* fzgx:end fn_10_D2C */

/* fzgx:begin fn_10_12D8 */
#pragma opt_dead_assignments off

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_12D8(void) {
    u8 * fzgx_live;

    struct State *state;
    u32 high;
    u32 flags;
    u8 *entries;
    s32 offset;
    s16 result;
    s16 value;
    s16 finalValue;
    u8 *audio;
    u32 finalAddress;
    fn_1_435C(lbl_10_bss_49388);
    lbl_10_bss_51740 = (fn_1_3F8C("SelModeDisp", fn_10_E294, 0, 8));
    fn_1_4A00(1, lbl_10_bss_4938C, lbl_10_bss_49388);
    audio = ((u8 *)lbl_1_bss_6EAD0);
    lbl_10_bss_51744 = 0;
    if (audio != 0) {
        if (*(u32 *)audio == 0) {
            *(u32 *)((u8 *)lbl_1_bss_6EAD0) = fn_8004CD70(2, audio + 0x10, 0x25124);
        }
        if (*(u32 *)(((u8 *)lbl_1_bss_6EAD0) + 4) == 0) {
            *(u32 *)(((u8 *)lbl_1_bss_6EAD0) + 4) = fn_8004CD70(2, ((u8 *)lbl_1_bss_6EAD0) + 0x4A258, 0x25124);
        }
        fn_1_A176C( (void *)(*(u32 *)(lbl_1_bss_6EAD0)), 45);
    }
    state = (struct State *)&(*((struct State *)&lbl_1_bss_8B3A0));
    flags = state->flags;
    state->flags = flags & 0xFFBFFFFF;
    if (0x40000000 & flags) {
        entries = state->entries;
        high = (lbl_1_bss_962 - 14) * 148;
        offset = high;
        value = *(s16 *)(entries + offset);
        result = lbl_1_bss_962;
        if (value < 9) {
            result = 9;
        } else {
            result = 10;
            if (value <= 10) result = value;
        }
        *(s16 *)(entries + offset) = result;
    } else {
        entries = state->entries;
        offset = (lbl_1_bss_962 - 14) * 148;
        if ((s16)*(s16 *)(entries + offset) < 0 || *(s16 *)(entries + offset) > 8) {
            *(s16 *)(entries + offset) = 1;
            switch (lbl_1_bss_964) {
            case 12: *(s16 *)(entries + offset) = 7; break;
            case 15: *(s16 *)(entries + offset) = 8; break;
            case 3: *(s16 *)(entries + offset) = 6; break;
            case 5: *(s16 *)(entries + offset) = 5; break;
            case 9: *(s16 *)(entries + offset) = 4; break;
            }
        }
    }
    lbl_10_bss_14 = (-1);
    (*((struct State *)&lbl_1_bss_8B3A0)).current = -1;
    (*((struct State *)&lbl_1_bss_8B3A0)).active = 1;
    fn_1_12F1E8(360);
    finalValue = (*((struct State *)&lbl_1_bss_8B3A0)).previous;
    state->flags &= 0xFFFFFFFB;
    if (finalValue != -1) {
        fzgx_live = (*((struct State *)&lbl_1_bss_8B3A0)).entries;
        finalAddress = (u32)fzgx_live + lbl_1_bss_962 * 148;
        *(s16 *)((u8 *)finalAddress - 0x818) = finalValue;
    }
}

#pragma opt_dead_assignments reset
/* fzgx:end fn_10_12D8 */

/* fzgx:begin fn_10_1544 */
#define SCAN_PLAYERS(i, sound)                                                         \
    for (i = 0; i < 4; i++) {                                                       \
        if (lbl_1_bss_9C8[i].unk_a == -1) {                                         \
            continue;                                                               \
        }                                                                           \
        if (__rlwnm(lbl_1_bss_8B3A0.unk_98, (i + 1) & 31, 31, 31) == 0) {           \
            continue;                                                               \
        }                                                                           \
        if ((lbl_1_bss_9F8[i].unk_8 >> 9) & 1) {                                     \
            delta--;                                                                \
        }                                                                           \
        if ((lbl_1_bss_9F8[i].unk_8 >> 8) & 1) {                                     \
            delta++;                                                                \
        }                                                                           \
        if ((lbl_1_bss_9F8[i].unk_8 >> 8) & 1) {                                     \
            fn_1_12F150(i, sound, 1);                                               \
        } else if ((lbl_1_bss_9F8[i].unk_8 >> 9) & 1) {                              \
            fn_1_12F150(i, sound, 0);                                               \
        }                                                                           \
    }

static inline void confirm(void) {
    lbl_10_bss_14 = (0xF);
    fn_1_12F17C();
    fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    fn_1_A2D84(0xA9010100);
}

#define MAY_CANCEL() (!(menu->unk_94 & 0x40000000) || (menu->unk_94 & 0x4000))

#define MAY_CANCEL_G() (!(lbl_1_bss_8B3A0.unk_94 & 0x40000000) || (lbl_1_bss_8B3A0.unk_94 & 0x4000))

static inline s32 is_busy(void) {
    u32 flags = lbl_1_bss_8B3A0.unk_140;
    if ((flags & 0x80000000) && !(flags & 0x40000000) && !(lbl_1_bss_8B3A0.unk_94 & 8)) {
        return 1;
    }
    if (fn_1_4C10() != 0) {
        return 1;
    }
    return 0;
}

#pragma opt_common_subs off

void fn_10_1544(void) {
    s16 fzgx_value;
    s16 delta;
    s16 i;
    s16 i2;
    s16 i3;
    SelState *menu;
    s16 row;
    s32 v;
    s32 tmp_ra1;
    s32 tmp_ra3;
    SelState * lab_t0;

    row = fn_10_C258( (fn_10_C258_SelContext *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }
    if (is_busy()) {
        return;
    }
    if ((lbl_10_bss_14) != -1) {
        v = lbl_10_bss_14;
        lbl_10_bss_14 = (-1);
        lbl_1_bss_96A = v;
        return;
    }
    menu = &lbl_1_bss_8B3A0;
    tmp_ra1 = menu->unk_0;
    if (tmp_ra1 == -1) {
        fn_10_9788( (SelState *)(menu));
        return;
    }
    delta = 0;
    switch (menu->unk_0) {
    case 0:
        if (menu->unk_94 & 0x200) {
            switch (row) {
            case 0:
                fn_10_A634( (SelState *)(menu));
                SCAN_PLAYERS(i, 2);
                if (delta > 0) {
                    lab_t0 = &lbl_1_bss_8B3A0;
                    fn_10_C274( (fn_10_C274_SelObject *)(SelState *)(lab_t0), lbl_1_bss_962);
                    fn_1_A2D84(0xA9010100);
                }
                if (delta < 0 && MAY_CANCEL()) {
                    lbl_1_bss_8B3A0.unk_0 = -1;
                    fn_1_A2D84(0xA9010200);
                }
                break;
            case 1:
                fn_10_A25C( (SelObjA25C *)(SelState *)(menu));
                SCAN_PLAYERS(i, 3);
                if (delta > 0) {
                    lab_t0 = &lbl_1_bss_8B3A0;
                    fn_10_C274( (fn_10_C274_SelObject *)(SelState *)(lab_t0), lbl_1_bss_962);
                    fn_1_A2D84(0xA9010100);
                }
                if (delta < 0 && MAY_CANCEL()) {
                    fn_10_C298( (fn_10_C298_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                    fn_1_A2D84(0xA9010200);
                }
                break;
            case 2:
                fn_10_A480( (struct fn_10_A480_Arg0 *)(SelState *)(menu));
                SCAN_PLAYERS(i, 4);
                if (delta > 0) {
                    confirm();
                    lbl_1_bss_8B3A0.unk_129 = 0;
                }
                if (delta < 0 && MAY_CANCEL()) {
                    fn_10_C298( (fn_10_C298_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                    fn_1_A2D84(0xA9010200);
                }
                break;
            }
        } else {
            switch (row) {
            case 0:
                fn_10_A25C( (SelObjA25C *)(SelState *)(menu));
                SCAN_PLAYERS(i, 3);
                if (delta > 0) {
                    confirm();
                    lbl_1_bss_8B3A0.unk_129 = 0;
                }
                if (delta < 0 || ((s16)fn_10_91E8()) < 2) {
                    if (MAY_CANCEL()) {
                        lbl_1_bss_8B3A0.unk_0 = -1;
                        fn_1_A2D84(0xA9010200);
                        fn_10_CFAC(1, 0, 0x1E, 9);
                    }
                }
                break;
            }
        }
        break;
    case 1:
    case 11:
        switch (row) {
        case 0:
            fn_10_A634( &lbl_1_bss_8B3A0);
            SCAN_PLAYERS(i2, 2);
            if (delta > 0) {
                confirm();
                lbl_1_bss_8B3A0.unk_129 = 0;
                if (lbl_1_bss_8B3A0.unk_0 == 1) {
                    lbl_1_bss_8B3A0.unk_94 |= 0x400000;
                }
            }
            if (delta < 0 && MAY_CANCEL_G()) {
                lbl_1_bss_8B3A0.unk_0 = -1;
                fn_1_A2D84(0xA9010200);
                fn_10_CFAC(1, 0, 0x1E, 5);
            }
            break;
        }
        break;
    case 2:
        switch (row) {
        case 0:
            fzgx_value = fn_10_A0E8( (SelState *)(SelState *)(menu));
            lab_t0 = &lbl_1_bss_8B3A0;
            lab_t0->unk_92 = fzgx_value;
            SCAN_PLAYERS(i3, 3);
            if (delta > 0) {
                tmp_ra3 = lab_t0->unk_92;
                if (tmp_ra3 == 1) {
                    lbl_1_bss_8B3A0.unk_94 |= 4;
                }
                confirm();
                lbl_1_bss_8B3A0.unk_129 = 0;
            }
            if (delta < 0 && MAY_CANCEL_G()) {
                fzgx_value = -1;
                lbl_1_bss_8B3A0.unk_0 = fzgx_value;
                fn_1_A2D84(0xA9010200);
                fn_10_CFAC(1, 0, 0x1E, 0x11);
            }
            break;
        }
        break;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_10_1544 */

/* fzgx:begin fn_10_1F28 */
void fn_10_1F28(void) {
    SelState *state;

    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    state = &lbl_1_bss_8B3A0;
    fn_10_BD64(state);
    fn_10_C594();
    state->unk_2 = state->unk_0;
}
s32 lbl_10_bss_51748 = 0;
s16 lbl_10_bss_5174C = 0;
/* fzgx:end fn_10_1F28 */

/* fzgx:begin fn_10_1F9C */
/* begin sofdec/adxt.h (deltawave784/fzgx@7d73e43f (CC0)) */

#ifndef SOFDEC_ADXT_H

#define SOFDEC_ADXT_H

/* CRI ADX talker (ADXT) handle, shared by the ADXT_* / adxt_* units of the DOL. */

/* begin layout_check.h (deltawave784/fzgx@7d73e43f (CC0)) */

#ifndef LAYOUT_CHECK_H

/* Compile-time layout checks for owned types. They declare array typedefs
 * only, so they emit no code or data under MWCC: a wrong size or offset is
 * a negative array bound and fails the compile. */

#endif

/* end layout_check.h */

#endif

/* end sofdec/adxt.h */

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_1F9C(void) {

    SelState *st;
    SelState *st2;
    s32 v;

    fn_1_435C( lbl_10_bss_49388);
    lbl_10_bss_51740 = fn_1_3F8C( ("SelCourseDisp"), fn_10_F57C, (0), 8);
    fn_1_4A00(1, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    if (lbl_1_bss_8B3A0.unk_0 == 2 || lbl_1_bss_8B3A0.unk_0 == 10) {
        fn_1_EB29C();
    }
    st = &lbl_1_bss_8B3A0;
    if (st->unk_94 & 0x40000000) {
        st->unk_8C = 6;
    } else {
        while (!fn_10_A7DC(st->unk_8C)) {
            v = st->unk_8C + 1;
            st->unk_8C = v > 10 ? 0 : (v < 0 ? 10 : v);
        }
    }
    st2 = &lbl_1_bss_8B3A0;
    if (st2->unk_8C == 5) {
        while ((st2->unk_8E == 5 && !fn_1_F89E4(0)) ||
               (st2->unk_8E != 5 && !fn_1_F89E4(st2->unk_8E + 1))) {
            v = st2->unk_8E + 1;
            st2->unk_8E = v > 5 ? 0 : (v < 0 ? 5 : v);
        }
    }
    if (st->unk_94 & 0x40000000) {
        st2->unk_8C = 6;
    }
    fn_10_AB98( (fn_10_AB98_fn_10_AB98_SelCursor *)&lbl_1_bss_8B3A0);
    if (lbl_1_bss_8B3A0.unk_0 != 1) {
        fn_1_46A60();
        fn_1_159440(3, 0);
    }
    lbl_10_bss_14 = -1;
    fn_1_12F1E8(0x2D0);
    lbl_1_bss_8B3A0.unk_A4->unk_19 = 0;
    lbl_10_bss_5174E = 0;
    lbl_10_bss_51750 = 0;
    lbl_10_bss_51752 = 0;
    lbl_1_bss_8B3A0.unk_A4->unk_1A = 0;
    lbl_1_bss_8B3A0.unk_129 = 1;
    lbl_1_bss_8CA24 = 0;
    lbl_1_bss_8B5F0 = 0;
    lbl_1_bss_8B5F1 = 0;
    lbl_10_bss_51754 = 1;
    fn_1_A176C( (ADXTHandle *)((*(ADXTHandle * * (*)[])&lbl_1_bss_6EAD0)[0][0]), 0x2D);
    lbl_10_bss_5174C = 0;
}
/* fzgx:end fn_10_1F9C */

/* fzgx:begin fn_10_21EC */
#pragma opt_common_subs off

void fn_10_21EC(void) {
    u32 fzgx_condition_19430;
    s16 ret;
    s16 count;
    s32 v3;
    SelState *sel;
    struct { s16 value; } i;
    struct { u8 * value; } p9F8;
    struct { u8 * value; } p9C8;
    SelState *psel;
    s16 t;
    u32 v;
    s16 locE;
    s16 locC;
    s16 locA;
    s16 loc8;
    s32 old;
    s32 cond;
    u32 lab_v;

    ret = fn_10_C258( (fn_10_C258_SelContext *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
    count = 0;
    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }
    lab_v = lbl_1_bss_8B3A0.unk_140;
    if (((lab_v & 0x80000000) != 0) &&
        ((lab_v & 0x40000000) == 0) &&
        ((lbl_1_bss_8B3A0.unk_94 & 0x8) == 0)) {
        cond = 1;
    } else {
        if (fn_1_4C10() != 0) {
            cond = 1;
        } else {
            cond = 0;
        }
    }
    if (cond != 0) {
        return;
    }
    if (fn_1_B7C00() != 0) {
        return;
    }
    old = lbl_10_bss_14;
    if (old != -1) {
        lbl_10_bss_14 = -1;
        lbl_1_bss_96A = old;
        return;
    }
    if (((2) == lbl_1_bss_8B3A0.unk_0) || lbl_1_bss_8B3A0.unk_0 == 10) {
        old = (fn_1_EB4BC() == 0);
        v3 = old;
    } else {
        v3 = 1;
    }
    sel = &lbl_1_bss_8B3A0;
    if ((sel->unk_94 & 0x40000000) != 0 && v3 != 0) {
        if ((sel->unk_94 & 0x200) != 0) {
            switch (ret) {
            case 0:
                if (fn_1_12F228() == 0) {
                    fn_10_A90C( (SelState *)&lbl_1_bss_8B3A0);
                }
{
    struct { s16 value; } fzgx_loop_i_3463;
    struct { u8 * value; } fzgx_loop_p9C8_3463;
    struct { u8 * value; } fzgx_loop_p9F8_3463;
    SelState * fzgx_loop_psel_3463;
                fzgx_loop_p9C8_3463.value = (*(u8 (*)[])&lbl_1_bss_9C8);
                fzgx_loop_p9F8_3463.value = (u8 *)&(*((struct SelTile *)&lbl_1_bss_9F8));
                fzgx_loop_i_3463.value = 0;
                fzgx_loop_psel_3463 = &lbl_1_bss_8B3A0;
                while (fzgx_loop_i_3463.value < 4) {
                    if (((-1) != ((s8)fzgx_loop_p9C8_3463.value[0xa])) &&
                        (__rlwnm(fzgx_loop_psel_3463->unk_98, (fzgx_loop_i_3463.value + 1) & 31, 31, 31)) != 0) {
                        if (((*(u16 *)(fzgx_loop_p9F8_3463.value + 8) >> 9) & 1) != 0) {
                            count--;
                        }
                        if ((((*(u16 *)(fzgx_loop_p9F8_3463.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                            count++;
                        }
                        if ((((*(u16 *)(fzgx_loop_p9F8_3463.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                            fn_1_12F150(fzgx_loop_i_3463.value, 5, 1);
                        } else if (((*(u16 *)(fzgx_loop_p9F8_3463.value + 8) >> 9) & 1) != 0) {
                            fn_1_12F150(fzgx_loop_i_3463.value, 5, 0);
                        }
                    }
                    fzgx_loop_p9C8_3463.value += 12;
                    fzgx_loop_p9F8_3463.value += 20;
                    fzgx_loop_i_3463.value++;
                }
    i.value = fzgx_loop_i_3463.value;
    p9C8.value = fzgx_loop_p9C8_3463.value;
    p9F8.value = fzgx_loop_p9F8_3463.value;
    psel = fzgx_loop_psel_3463;
}
                if (count > 0) {
                    fn_10_C274( (fn_10_C274_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                    fn_10_AB98( (fn_10_AB98_fn_10_AB98_SelCursor *)&lbl_1_bss_8B3A0);
                    fn_1_A2D84(0xA9010100);
                }
                if (count < 0 &&
                    ((sel->unk_94 & 0x40000000) == 0 || (sel->unk_94 & 0x4000) != 0)) {
                    lbl_10_bss_14 = 14;
                    t = fn_10_C258( (fn_10_C258_SelContext *)&lbl_1_bss_8B3A0, 14);
                    if (t == 0) {
                        lbl_10_bss_51748 = 1;
                    }
                    fn_1_12F17C();
                    fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
                    lbl_10_bss_51744 = 0;
                    fn_1_A2D84(0xA9010200);
                    fn_10_C210( (fn_10_C210_SelOwner *)&lbl_1_bss_8B3A0, lbl_10_bss_14);
                }
                break;
            case 1:
                if (lbl_10_bss_51750 > 1) {
                    lbl_10_bss_51750 -= 1;
                }
                if (lbl_10_bss_51752 > 1) {
                    lbl_10_bss_51752 -= 1;
                }
                if (lbl_10_bss_5174E != 0) {
                    u16 c = lbl_10_bss_5174E;
                    c--;
                    lbl_10_bss_5174E = c;
                    if (c == 0xb3) {
                        if (lbl_1_bss_8B3A0.unk_90 != 0x24) {
                            lbl_1_bss_8CA24 = 0;
                        } else if (lbl_1_bss_8CA24 != 0) {
                            fn_1_A2D84(0xA9000400);
                        }
                        lbl_10_bss_51754 = 0;
                    }
                    if (lbl_10_bss_5174E == 0xaa) {
                        fn_1_12EF80(lbl_1_bss_8B3A0.unk_90, &locE, &locC);
                        fn_1_A51C8(locC);
                    }
                    if (lbl_10_bss_5174E == 1) {
                        lbl_10_bss_14 = 16;
                        fn_1_12F17C();
                        fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
                        lbl_10_bss_51744 = 0;
                    }
                } else {
                    if (fn_1_12F228() == 0) {
                        fn_10_AE14( (fn_10_AE14_Cursor *)&lbl_1_bss_8B3A0);
                    }
                    p9C8.value = (*(u8 (*)[])&lbl_1_bss_9C8);
                    i.value = 0;
                    p9F8.value = (u8 *)&(*((struct SelTile *)&lbl_1_bss_9F8));
                    psel = &lbl_1_bss_8B3A0;
                    while (i.value < 4) {
                        if (((-1) != ((s8)p9C8.value[0xa])) &&
                            (__rlwnm(psel->unk_98, (i.value + 1) & 31, 31, 31)) != 0) {
                            if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                count--;
                            }
                            if ((((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                                count++;
                            }
                            if ((((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                                fn_1_12F150(i.value, 6, 1);
                            } else if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                fn_1_12F150(i.value, 6, 0);
                            }
                        }
                        p9C8.value += 12;
                        p9F8.value += 20;
                        i.value++;
                    }
                    if (count > 0) {
                        psel = &lbl_1_bss_8B3A0;
                        if (psel->unk_A4->unk_1A == 0) {
                            fn_1_A2D84(0xA9010100);
                            psel->unk_A4->unk_1A = 1;
                        }
                        fn_1_12F1E8(0);
                        if (fn_1_D6698() != 0 || fn_1_D6690() == 0) {
                            if (lbl_10_bss_51752 == 1) {
                                fn_1_7B2E8(lbl_1_bss_8B3A0.unk_90);
                                lbl_10_bss_5174E = 180;
                            }
                        }
                        if (lbl_10_bss_51752 == 0) {
                            if (lbl_1_bss_8B3A0.unk_0 != 2 && lbl_1_bss_8B3A0.unk_0 != 10) {
                                lbl_10_bss_51752 = 60;
                            } else {
                                lbl_10_bss_51752 = 1;
                            }
                        }
                        if (lbl_10_bss_51750 == 0) {
                            lbl_10_bss_51750 = 20;
                        }
                        if ((((*((struct SelTile *)&lbl_1_bss_9F8)).unk_8 >> 12) & 1) != 0 &&
                            lbl_10_bss_51754 != 0 &&
                            ((*((struct SelTile *)&lbl_1_bss_9F8)).unk_14 & 0xb) == 0xb &&
                            (((*((struct SelTile *)&lbl_1_bss_9F8)).unk_14 >> 2) & 1) == 0) {
                            lbl_10_bss_51754 = 0;
                            lbl_1_bss_8CA24 = 1;
                        }
                        lbl_1_bss_8B3A0.unk_129 = 0;
                    }
                    if (count < 0 &&
                        ((sel->unk_94 & 0x40000000) == 0 || (sel->unk_94 & 0x4000) != 0)) {
                        fn_10_C298( (fn_10_C298_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                        psel = &lbl_1_bss_8B3A0;
                        if (psel->unk_A4->unk_1A == 0) {
                            fn_1_A2D84(0xA9010200);
                            psel->unk_A4->unk_1A = 1;
                        }
                    }
                }
                break;
            }
        } else {
            if (lbl_10_bss_51750 > 1) {
                lbl_10_bss_51750 -= 1;
            }
            if (lbl_10_bss_51752 > 1) {
                lbl_10_bss_51752 -= 1;
            }
            if (lbl_10_bss_5174E != 0) {
                u16 c = lbl_10_bss_5174E;
                c--;
                lbl_10_bss_5174E = c;
                if (c == 0xb3) {
                    if (lbl_1_bss_8B3A0.unk_90 != 0x24) {
                        lbl_1_bss_8CA24 = 0;
                    } else if (lbl_1_bss_8CA24 != 0) {
                        fn_1_A2D84(0xA9000400);
                    }
                    lbl_10_bss_51754 = 0;
                }
                if (lbl_10_bss_5174E == 0xaa) {
                    fn_1_12EF80(lbl_1_bss_8B3A0.unk_90, &locA, &loc8);
                    fn_1_A51C8(loc8);
                }
                if (lbl_10_bss_5174E == 1) {
                    lbl_10_bss_14 = 16;
                    fn_1_12F17C();
                    fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
                    lbl_10_bss_51744 = 0;
                }
            } else {
                if (fn_1_12F228() == 0) {
                    fn_10_AE14( (fn_10_AE14_Cursor *)&lbl_1_bss_8B3A0);
                }
                p9C8.value = (*(u8 (*)[])&lbl_1_bss_9C8);
                i.value = 0;
                p9F8.value = (u8 *)&(*((struct SelTile *)&lbl_1_bss_9F8));
                psel = &lbl_1_bss_8B3A0;
                while (i.value < 4) {
                    if (((-1) != ((s8)p9C8.value[0xa])) &&
                        (__rlwnm(psel->unk_98, (i.value + 1) & 31, 31, 31)) != 0) {
                        if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                            count--;
                        }
                        if ((((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                            count++;
                        }
                        if ((((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                            fn_1_12F150(i.value, 6, 1);
                        } else if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                            fn_1_12F150(i.value, 6, 0);
                        }
                    }
                    p9C8.value += 12;
                    p9F8.value += 20;
                    i.value++;
                }
                if (count > 0) {
                    fn_1_12F1E8(0);
                    if (fn_1_D6698() != 0 || fn_1_D6690() == 0) {
                        if (lbl_10_bss_51752 == 1) {
                            fn_1_7B2E8(lbl_1_bss_8B3A0.unk_90);
                            lbl_10_bss_5174E = 180;
                        }
                    }
                    psel = &lbl_1_bss_8B3A0;
                    if (psel->unk_A4->unk_1A == 0) {
                        fn_1_A2D84(0xA9010100);
                        psel->unk_A4->unk_1A = 1;
                    }
                    if (lbl_10_bss_51752 == 0) {
                        if (lbl_1_bss_8B3A0.unk_0 != 2 && lbl_1_bss_8B3A0.unk_0 != 10) {
                            lbl_10_bss_51752 = 60;
                        } else {
                            lbl_10_bss_51752 = 1;
                        }
                    }
                    if (lbl_10_bss_51750 == 0) {
                        lbl_10_bss_51750 = 20;
                    }
                    if ((((*((struct SelTile *)&lbl_1_bss_9F8)).unk_8 >> 12) & 1) != 0 &&
                        lbl_10_bss_51754 != 0 &&
                        ((*((struct SelTile *)&lbl_1_bss_9F8)).unk_14 & 0xb) == 0xb &&
                        (((*((struct SelTile *)&lbl_1_bss_9F8)).unk_14 >> 2) & 1) == 0) {
                        lbl_10_bss_51754 = 0;
                        lbl_1_bss_8CA24 = 1;
                    }
                    lbl_1_bss_8B3A0.unk_129 = 0;
                }
                if (count < 0 &&
                    ((sel->unk_94 & 0x40000000) == 0 || (sel->unk_94 & 0x4000) != 0)) {
                    fn_10_C298( (fn_10_C298_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                    psel = &lbl_1_bss_8B3A0;
                    if (psel->unk_A4->unk_1A == 0) {
                        fn_1_A2D84(0xA9010200);
                        psel->unk_A4->unk_1A = 1;
                    }
                    fn_1_12F1E8(0);
                }
            }
        }
    } else {
        if (v3 != 0) {
            if (lbl_1_bss_8B3A0.unk_0 == 1) {
                switch (ret) {
                case 0:
                    fn_10_A90C( (SelState *)&lbl_1_bss_8B3A0);
                    p9C8.value = (*(u8 (*)[])&lbl_1_bss_9C8);
                    i.value = 0;
                    p9F8.value = (u8 *)&(*((struct SelTile *)&lbl_1_bss_9F8));
                    psel = &lbl_1_bss_8B3A0;
                    while (i.value < 4) {
                        if (((-1) != ((s8)p9C8.value[0xa])) &&
                            (__rlwnm(psel->unk_98, (i.value + 1) & 31, 31, 31)) != 0) {
                            if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                count--;
                            }
                            if (((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) {
                                count = (count + 1);
                            }
                            if (((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) {
                                fn_1_12F150(i.value, 5, 1);
                                fn_1_12F17C();
                            } else if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                fn_1_12F150(i.value, 5, 0);
                                fn_1_12F17C();
                            }
                        }
                        p9C8.value += 12;
                        p9F8.value += 20;
                        i.value++;
                    }
                    if (count > 0) {
                        t = fn_10_3D64();
                        v = sel->unk_94;
                        lbl_10_bss_A = t;
                        lbl_10_bss_8 = t;
                        if ((v & 0x400) != 0 && t != 0) {
                            lbl_10_bss_14 = 20;
                        } else {
                            lbl_10_bss_A = 0;
                            lbl_10_bss_8 = 0;
                            lbl_10_bss_14 = 16;
                        }
                        fn_10_AB98( (fn_10_AB98_fn_10_AB98_SelCursor *)&lbl_1_bss_8B3A0);
                        fn_1_A2D84(0xA9010100);
                        lbl_1_bss_8B3A0.unk_129 = 0;
                    }
                    if (count < 0 &&
                        ((sel->unk_94 & 0x40000000) == 0 || (sel->unk_94 & 0x4000) != 0)) {
                        v = sel->unk_94;
                        lbl_10_bss_14 = 14;
                        sel->unk_94 &= 0xffffffefU;
                        sel->unk_94 &= 0xffffffcfU;
                        t = fn_10_C258( (fn_10_C258_SelContext *)&lbl_1_bss_8B3A0, 14);
                        if (t == 0) {
                            lbl_10_bss_51748 = 1;
                        }
                        fn_1_A2D84(0xA9010200);
                        fn_10_C210( (fn_10_C210_SelOwner *)&lbl_1_bss_8B3A0, lbl_10_bss_14);
                    }
                    if (count != 0) {
                        fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
                        lbl_10_bss_51744 = 0;
                    }
                    break;
                }
            } else {
                switch (ret) {
                case 0:
                    fn_10_A90C( (SelState *)&lbl_1_bss_8B3A0);
                    p9C8.value = (*(u8 (*)[])&lbl_1_bss_9C8);
                    i.value = 0;
                    p9F8.value = (u8 *)&(*((struct SelTile *)&lbl_1_bss_9F8));
                    psel = &lbl_1_bss_8B3A0;
                    while (i.value < 4) {
                        if (((-1) != ((s8)p9C8.value[0xa])) &&
                            (__rlwnm(psel->unk_98, (i.value + 1) & 31, 31, 31)) != 0) {
                            if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                count--;
                            }
                            if (((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) {
                                count = (count + 1);
                            }
                            if (((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) {
                                fn_1_12F150(i.value, 5, 1);
                            } else if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                fn_1_12F150(i.value, 5, 0);
                            }
                        }
                        p9C8.value += 12;
                        p9F8.value += 20;
                        i.value++;
                    }
                    if (count > 0) {
                        lbl_10_bss_5174C = 1;
                        fn_1_A2D84(0xA9010100);
                        fn_1_7B218(0);
                        fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
                        lbl_10_bss_51744 = 0;
                        return;
                    }
                    if (lbl_10_bss_5174C > 0) {
                        fn_1_4A00(1, lbl_10_bss_4938C, lbl_10_bss_49388);
                        v = sel->unk_94;
                        lbl_10_bss_51744 = 0;
                        lbl_10_bss_5174C = 0;
                        if ((v & 0x4) != 0) {
                            lbl_10_bss_14 = 33;
                            fn_1_12F17C();
                            fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
                            lbl_10_bss_51744 = 0;
                            fn_1_12F1E8(0);
                        } else {
                            fn_10_C274( (fn_10_C274_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                            fn_10_AB98( (fn_10_AB98_fn_10_AB98_SelCursor *)&lbl_1_bss_8B3A0);
                        }
                    }
                    if (count < 0 &&
                        (((fzgx_condition_19430 = sel->unk_94) & 0x40000000) == 0 || (fzgx_condition_19430 & 0x4000) != 0) &&
                        (fzgx_condition_19430 & 0x20) == 0) {
                        v = sel->unk_94;
                        lbl_10_bss_14 = 14;
                        sel->unk_94 &= 0xffffffefU;
                        sel->unk_94 &= 0xffffffcfU;
                        t = fn_10_C258( (fn_10_C258_SelContext *)&lbl_1_bss_8B3A0, 14);
                        if (t == 0) {
                            lbl_10_bss_51748 = 1;
                        }
                        fn_1_12F17C();
                        fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
                        lbl_10_bss_51744 = 0;
                        fn_1_A2D84(0xA9010200);
                        fn_10_C210( (fn_10_C210_SelOwner *)&lbl_1_bss_8B3A0, lbl_10_bss_14);
                    }
                    break;
                case 1:
                    if (((2) == lbl_1_bss_8B3A0.unk_0) && (((*((struct SelTile *)&lbl_1_bss_9F8)).unk_8 >> 11) & 1) != 0) {
                        fn_1_EB330();
                    } else {
                        fn_10_AE14( (fn_10_AE14_Cursor *)&lbl_1_bss_8B3A0);
                        p9C8.value = (*(u8 (*)[])&lbl_1_bss_9C8);
                        i.value = 0;
                        p9F8.value = (u8 *)&(*((struct SelTile *)&lbl_1_bss_9F8));
                        psel = &lbl_1_bss_8B3A0;
                        while (i.value < 4) {
                            if (((-1) != ((s8)p9C8.value[0xa])) &&
                                (__rlwnm(psel->unk_98, (i.value + 1) & 31, 31, 31)) != 0) {
                                if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                    count--;
                                }
                                if ((((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                                    count++;
                                }
                                if ((((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                                    fn_1_12F150(i.value, 6, 1);
                                } else if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                    fn_1_12F150(i.value, 6, 0);
                                }
                            }
                            p9C8.value += 12;
                            p9F8.value += 20;
                            i.value++;
                        }
                        if (count > 0) {
                            t = fn_10_3D64();
                            v = sel->unk_94;
                            lbl_10_bss_A = t;
                            lbl_10_bss_8 = t;
                            if ((v & 0x400) != 0 && t != 0) {
                                lbl_10_bss_14 = 20;
                            } else {
                                lbl_10_bss_A = 0;
                                lbl_10_bss_8 = 0;
                                lbl_10_bss_14 = 16;
                            }
                            fn_1_12F17C();
                            fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
                            lbl_10_bss_51744 = 0;
                            fn_1_A2D84(0xA9010100);
                            fn_1_12F1E8(0);
                            lbl_1_bss_8B3A0.unk_129 = 0;
                        }
                        if (count < 0 &&
                            ((sel->unk_94 & 0x40000000) == 0 || (sel->unk_94 & 0x4000) != 0)) {
                            lbl_10_bss_5174C = -1;
                            fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
                            lbl_10_bss_51744 = 0;
                            fn_1_A2D84(0xA9010200);
                            return;
                        }
                        if (lbl_10_bss_5174C < 0) {
                            fn_1_4A00(1, lbl_10_bss_4938C, lbl_10_bss_49388);
                            lbl_10_bss_51744 = 0;
                            lbl_10_bss_5174C = 0;
                            fn_10_C298( (fn_10_C298_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                            fn_1_46A60();
                            fn_1_1596DC(3);
                            fn_1_159440(3, 0);
                        }
                    }
                    break;
                }
            }
        }
    }
    if (v3 == 0) {
        lbl_1_bss_96A = -1;
    }
}

#pragma opt_common_subs reset
/* fzgx:end fn_10_21EC */

/* fzgx:begin fn_10_3268 */
void fn_10_3268(void) {
    if (lbl_10_bss_51748 == 1) {
        lbl_10_bss_51748 = 0;
        lbl_1_bss_8B3A0.unk_0 = -1;
    }
    if (lbl_1_bss_8B3A0.unk_0 != 1) {
        fn_1_1596DC(3);
    }
    fn_10_C594();
    fn_1_EC910();
    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    {
        SelState *state = &lbl_1_bss_8B3A0;
        if (!(state->unk_94 & 0x80000000)) {
            fn_1_7B4C0();
        }
        fn_10_BEF0(&lbl_1_bss_8B3A0);
        if (state->unk_94 & 0x40000000) {
            lbl_1_bss_8B3A0.players[0].car = 6;
        }
    }
}
/* fzgx:end fn_10_3268 */

/* fzgx:begin fn_10_3350 */
#pragma opt_unroll_loops off

void fn_10_3350(void) {
Global *g;
s16 j;
s16 i;
s16 count;
s16 mode;
s64 result;
count = 4;
fn_1_48140(159);
g = &(*((Global *)&lbl_1_bss_8B3A0));
if (!(g->flags & 0x80000000) && lbl_1_bss_966 != 20) {
fn_10_924C( (u8 *)(lbl_10_bss_49380));
}
if (lbl_1_bss_966 != 20 && lbl_1_bss_966 != 16) {
for (j = 0; j < 4; j++) {
fn_80008BEC(fn_1_36AD0() + j * 0x81c0 , 0, 0x81c0 );
fn_1_12C0EC((*((Global *)&lbl_1_bss_8B3A0)).data + (lbl_1_bss_962 - 14) * 0x94 + j * 0x1c + 0x24);
}
for (i = 0; i < 9; i++) {
fn_80008BEC(lbl_10_bss_3C0 + i * 0x81c0 , 0, 0x81c0 );
}
lbl_10_bss_49390[0] = 0;
lbl_10_bss_4938F = 0;
}
if (!lbl_10_bss_4938F) {
for (i = 41; i <= 44; i++) {
fn_80008BEC(lbl_10_bss_3C0 + (i - 41) * 0x81c0 , 0, 0x81c0 );
}
}
if (!lbl_10_bss_49390[0]) {
for (i = 45; i <= 48; i++) {
fn_80008BEC(lbl_10_bss_3C0 + (i - 41) * 0x81c0 , 0, 0x81c0 );
}
}
lbl_10_bss_18 = (19);
lbl_10_bss_1A = (6);
if (g->flags & 0x40000000) {
if (lbl_1_bss_8CA26 == 0) {
lbl_10_bss_18 = (19);
lbl_10_bss_1A = (2);
fn_1_151EF8(lbl_10_data_408, 38, (*(u8 (*)[0x3A4])&lbl_10_bss_1C), 2, 19);
} else {
fn_1_151EF8(lbl_10_data_324, 114, (*(u8 (*)[0x3A4])&lbl_10_bss_1C), 6, 19);
}
} else {
fn_1_151EF8(lbl_10_data_324, 114, (*(u8 (*)[0x3A4])&lbl_10_bss_1C), 6, 19);
}
fn_10_3954();
fn_10_3A98();
fn_10_3B44();
fn_10_3C14();
fn_1_12F10C(lbl_10_bss_3C0 );
for (i = 0; i < 4; i++) {
(*(s32 (*)[4])&lbl_10_bss_51758)[i] = -1;
lbl_10_bss_51768[i].a = -1;
lbl_10_bss_51768[i].b = -1;
}
{
u32 table[5] = {0x80000000, 0x80000000, 0x40000000, 0x20000000, 0x20000000};
mode = (*((Global *)&lbl_1_bss_8B3A0)).mode;
lbl_10_data_45C = table[mode];
}
if (mode == 0) {
g->flags |= 0x08000000;
((Player *)&(*((Global *)&lbl_1_bss_8B3A0)))[0].unk_e = -1;
((Player *)&(*((Global *)&lbl_1_bss_8B3A0)))[1].unk_e = -1;
((Player *)&(*((Global *)&lbl_1_bss_8B3A0)))[2].unk_e = -1;
((Player *)&(*((Global *)&lbl_1_bss_8B3A0)))[3].unk_e = -1;
((Player *)&(*((Global *)&lbl_1_bss_8B3A0)))[(*((Global *)&lbl_1_bss_8B3A0)).index].unk_e = 6;
} else {
fn_10_4D78();
}
if (g->flags & 0x20000000) {
count = 1;
}
if (!(g->flags & 0x80000000)) {
if (lbl_1_bss_966 != 20) {
fn_1_12BF7C(lbl_10_bss_51788, 1, fn_1_A5D88(), 480);
if ((g->flags & 0x40000000) && lbl_1_bss_8CA26 == 0) {
fn_1_12BF7C(lbl_10_bss_517EC, count, fn_1_A5D88(), 480);
if (g->flags & 0x1000) {
fn_1_12BF7C(lbl_10_bss_5197C, count, fn_1_A5D88(), 480);
} else {
fn_1_12BF7C(lbl_10_bss_5197C, count, fn_1_A5D88() >> 1, 240);
}
} else {
fn_1_12BF7C(lbl_10_bss_517EC, count, fn_1_A5D88() >> 1, 240);
if (!(g->flags & 0x100)) {
fn_1_12BF7C(lbl_10_bss_5197C, count, fn_1_A5D88() >> 1, 240);
}
}
if (g->flags & 0x100) {
fn_1_47F74(160);
}
}
fn_10_948C(lbl_10_bss_493A0, lbl_10_bss_4EEC0);
}
fn_1_435C( (lbl_10_bss_49388));
if (lbl_10_bss_51740 == -1) {
lbl_10_bss_51740 = fn_1_3F8C("SelCarMapDisp", fn_10_FF08, 0, 8);
}
fn_1_4A00(1, lbl_10_bss_4938C, (lbl_10_bss_49388));
lbl_10_bss_51744 = 0;
lbl_10_bss_14 = (-1);
lbl_10_bss_51B0C = -1;
lbl_10_bss_51B10 = 90;
if (lbl_1_bss_966 != 16) {
fn_1_12F1E8(720);
}
(*((Global *)&lbl_1_bss_8B3A0)).data[0x19] = 0;
if (fn_1_B7F58( (s64 *)(Result *)(&result)) == 1) {
fn_1_A2D84(0xa9122600);
}
(*((Global *)&lbl_1_bss_8B3A0)).unk_129 = 1;
if (g->flags & 0x40000000) {
fn_1_13F81C();
fn_1_13F948();
for (i = 4; i < 8; i++) {
if ((*(lbl_10_bss_3C0 + (i) * 0x81c0 + (7))) ) {
fn_10_3DE0(i, (fn_10_3DE0_SelEntry *)lbl_10_bss_3C0, lbl_10_data_456);
}
}
}
fn_1_13F81C();
fn_1_13F948();
for (i = 0; i < 8; i++) {
if ((*(lbl_10_bss_3C0 + (i) * 0x81c0 + (7))) ) {
if (__rlwnm((*(u32 *)(lbl_10_bss_3C0 + (i) * 0x81c0 + (0))) , 2, 31, 31)) {
fn_10_3DE0(i, (fn_10_3DE0_SelEntry *)lbl_10_bss_3C0, lbl_10_data_456);
} else {
fn_10_3DE0(i, (fn_10_3DE0_SelEntry *)lbl_10_bss_3C0, 1);
}
}
}
fn_1_FE004();
fn_10_2324C();
return;
}
#pragma opt_unroll_loops reset
/* fzgx:end fn_10_3350 */

/* fzgx:begin fn_10_3954 */
#define SEL ((SelBig *)(*(u32 (*)[74736])&lbl_10_bss_3C0))

void fn_10_3954(void) {
    s16 i;
    s16 j;

    if ((*(u32 *)(0x94 + (*(u8 (*)[])&lbl_1_bss_8B3A0.unk_0)) & ((u32)1 << 30)) == 0) {
        SEL->flags &= ~((u32)3 << 30);
        return;
    }

    if ((SEL->flags & ((u32)1 << 31)) != 0 &&
        (SEL->flags & ((u32)1 << 30)) != 0) {
        return;
    }

    SEL->flags |= ((u32)3 << 30);
    SEL->b5 = 0x31;

    for (i = 0; i < 3; i++) {
        SEL->e[i].a = fn_1_14F270(fn_1_128B00(i), i, (u32)1 << 31);
    }

    SEL->x = fn_1_128B00(i);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            SEL->e[i].arr[j] = fn_1_151BE8(SEL->e[i].a, j);
        }
    }
}
/* fzgx:end fn_10_3954 */

/* fzgx:begin fn_10_3A98 */
#pragma opt_propagation off

void fn_10_3A98(void) {
    fn_10_3A98_SelSlot (* fzgx_live)[19];
    fn_10_3A98_SelState *sel = &(*(fn_10_3A98_SelState *)&(*((Obj_10_bss_0 *)&lbl_10_bss_0)));
    s16 slot_y;
    s16 slot_x;
    u32 state;

    if (!((*(fn_10_3A98_GlobalState *)&lbl_1_bss_8B3A0.unk_0).flags & 0x40000000)) {
        return;
    }

    state = *(u32 *)((u8 *)(*(u32 (*)[74736])&(*((Obj_10_bss_3C0 *)&lbl_10_bss_3C0))) + 0x40e00);
    if (!(state & ((u32)1 << 31)) || !(state & 0x40000000)) {
        return;
    }

    fn_1_152970(&slot_y, &slot_x, 0x31, 0, (SelCell *)((fn_10_3A98_SelSlot *)&sel->slots[0][0]),
                 sel->index_y, sel->index_x);
    fzgx_live = sel->slots;
    fzgx_live[slot_y][slot_x].flags &= ~0x40000000;
}

#pragma opt_propagation reset
/* fzgx:end fn_10_3A98 */

/* fzgx:begin fn_10_3B44 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_3B44(void) {
    s16 i;
    s16 row;
    s16 col;
    fn_10_3B44_SelEnt *e;

    for (i = 0x29; i <= 0x30; i++) {
        s16 idx;

        fn_1_152970(&row, &col, i, 0, (SelCell *)((SelFnEntry *)(*(u32 (*)[233])&lbl_10_bss_1C)),
                    lbl_10_bss_1A, lbl_10_bss_18);
        idx = i - 0x29;
        ((fn_10_3B44_SelSlot (*)[19])(*(u32 (*)[233])&lbl_10_bss_1C))[row][col].flags |= 0x20000000;
        e = (fn_10_3B44_SelEnt *)((u8 *)(*(u32 (*)[74736])&(*((Obj_10_bss_3C0 *)&lbl_10_bss_3C0))) + idx * 0x81C0);
        if (e->unk_0 & 0x80000000) {
            e->unk_5 = i;
            ((fn_10_3B44_SelSlot (*)[19])(*(u32 (*)[233])&lbl_10_bss_1C))[row][col].flags &= ~0x40000000;
        }
    }
}
/* fzgx:end fn_10_3B44 */

/* fzgx:begin fn_10_3C14 */
void fn_10_3C14(void) {
    u8 *flags;
    s16 slot_y;
    s16 slot_x;

    if (lbl_1_bss_8B3A0.unk_94 & 0x20000000) {
        return;
    }
    fn_1_152970(&slot_y, &slot_x, 0x36, 0, lbl_10_bss_1C[0], lbl_10_bss_1A, lbl_10_bss_18);
    flags = (u8 *)&lbl_10_bss_1C[0][0].flags;
    *(u32 *)(flags + slot_y * 0x98 + slot_x * 8) |= 0x10000000;
    fn_1_152970(&slot_y, &slot_x, 0x37, 0, lbl_10_bss_1C[0], lbl_10_bss_1A, lbl_10_bss_18);
    *(u32 *)(flags + slot_y * 0x98 + slot_x * 8) |= 0x10000000;
    fn_1_152970(&slot_y, &slot_x, 0x38, 0, lbl_10_bss_1C[0], lbl_10_bss_1A, lbl_10_bss_18);
    *(u32 *)(flags + slot_y * 0x98 + slot_x * 8) |= 0x10000000;
    fn_1_152970(&slot_y, &slot_x, 0x39, 0, lbl_10_bss_1C[0], lbl_10_bss_1A, lbl_10_bss_18);
    *(u32 *)(flags + slot_y * 0x98 + slot_x * 8) |= 0x10000000;
}
/* fzgx:end fn_10_3C14 */

/* fzgx:begin fn_10_3D64 */
s16 fn_10_3D64(void) {
    s16 result = 0;

    if (lbl_1_bss_7180C == 1 && fn_1_B7E98(0) == 1) {
        result |= 1;
    }
    if (lbl_1_bss_7180C == 1 && fn_1_B7E98(1) == 1) {
        result |= 2;
    }
    return result;
}
/* fzgx:end fn_10_3D64 */

/* fzgx:begin fn_10_3DE0 */
void fn_10_3DE0(u8 index, fn_10_3DE0_SelEntry *entries, s16 slot) {
    u32 i = index & 0xff;
    fn_10_3DE0_SelEntry *entry = (fn_10_3DE0_SelEntry *)((u8 *)entries + i * 0x81c0);
    fn_10_3DE0_SelObject *object;
    SelResult *result;
    u8 old_value;
    u8 value;

    if ((entry->flags & ((u32)1 << 31)) != 0 && entry->type7 <= 4 &&
        entry->type7 != 0) {
        fn_1_13F848(index);
        fn_1_13F974(index);
        result = fn_1_13F8B0(index);
        object = fn_1_13F9DC(index);
        old_value = entry->value5;
        value = entry->source_index;

        if (entry->flags & 0x40000000) {
            object->flags390 |= 0x04000000;
            object->data3a0 = &(*(u8 (*)[23328])&lbl_10_bss_493A0)[i * 0xa20];
        } else {
            entry->value5 = value;
            *(CopyData *)object =
                *(CopyData *)((u8 *)((u32)lbl_10_bss_49380) + value * 0x440);
        }

        object->slot3ba = slot;
        object->result3a4 = fn_1_7F254(entry, (1 << object->slot3ba));
        result->object = object;
        result->kind4 = 4;
        result->cb10424 = fn_1_FD324;
        result->cb10428 = fn_1_FDC00;
        result->cb1042c = fn_1_FD27C;
        result->zero10420 = 0;
        fn_1_FD844(entry, result);
        entry->value5 = old_value;
    }
}
/* fzgx:end fn_10_3DE0 */

/* fzgx:begin fn_10_3F54 */
/* Fields of the selection work area addressed from its 0x50000 upper half. */

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_3F54(void) {
s16 final_selector;
u8 * upper;
GameState *gs;
s16 selector;
struct { s16 value; } pressed;
s16 count;
s16 i;
int skip;
s32 next;
s16 status;
u32 mask;
    u8 lab_t1;
s32 tmp_ra6;


if (lbl_10_bss_14 == -1) {
fn_1_4C10();
}
if (((*((GameState *)&lbl_1_bss_8B3A0)).unk_140 & 0x80000000) && !((*((GameState *)&lbl_1_bss_8B3A0)).unk_140 & 0x40000000) &&
!((*((GameState *)&lbl_1_bss_8B3A0)).unk_94 & 8)) {
skip = 1;
} else if (fn_1_4C10() != 0) {
skip = 1;
} else {
skip = 0;
}
if (skip) {
return;
}
if (((s32)lbl_10_bss_14) != -1) {
lbl_1_bss_96A = lbl_10_bss_14;
lbl_10_bss_14 = (-1);
if ((lbl_10_bss_51B0C) != -1) {
lbl_10_bss_51B0C = -1;
lbl_1_bss_8CA26 = !lbl_1_bss_8CA26;
}
return;
}
status = fn_10_B2C8( (fn_10_B2C8_Obj_1_bss_8B3A0 *)(&(*((GameState *)&lbl_1_bss_8B3A0))));
gs = &(*((GameState *)&lbl_1_bss_8B3A0));
if (!(gs->unk_94 & 0x40000000)) {
pressed.value = 0;
if (lbl_1_bss_7180C == 1 && fn_1_B7E98(0) == 1) {
pressed.value |= 1;
}
if (lbl_1_bss_7180C == 1 && fn_1_B7E98(1) == 1) {
pressed.value |= 2;
}
lbl_10_bss_A = pressed.value - lbl_10_bss_8;
if (pressed.value != 0) {
lbl_10_bss_A = pressed.value ;
if (gs->unk_94 & 0x400) {
fn_1_A2D84(0xA9010100);
lbl_10_bss_14 = (20);
fn_1_1280(1);
fn_10_2323C();
fn_1_FDFF4();
lbl_10_bss_8 = pressed.value ;
if (lbl_10_bss_C == 0) {
fn_1_46BFC();
lbl_10_bss_C = 1;
fn_1_46B44(fn_10_C5E0, &lbl_10_data_578);
}
} else if (status == 0) {
count = 0;
for (i = 0; i < 4; i++) {
if ((*(Entry9C8 (*)[])&lbl_1_bss_9C8)[i].unk_A != -1 &&
__rlwnm((*((GameState *)&lbl_1_bss_8B3A0)).unk_98, (i + 1) & 31, 31, 31)) {
if (((*(Entry9F8 (*)[])&lbl_1_bss_9F8)[i].unk_0 >> 11) & 1) {
count++;
}
if (((*(Entry9F8 (*)[])&lbl_1_bss_9F8)[i].unk_0 >> 11) & 1) {
fn_1_12F150(i, 2, 1);
}
}
}
if (count != 0) {
fn_1_A2D84(0xA9010100);
fn_10_2323C();
fn_1_FDFF4();
lbl_10_bss_14 = (20);
fn_1_1280(1);
lbl_10_bss_8 = pressed.value ;
if (lbl_10_bss_C == 0) {
fn_1_46BFC();
lbl_10_bss_C = 1;
fn_1_46B44(fn_10_C5E0, &lbl_10_data_578);
}
return;
}
}
}
if ((lbl_10_bss_14) != -1) {
return;
}
}
if (status == 0) {
lbl_10_bss_51B10 = 90;
}
if (status == 1) {
if (lbl_10_bss_51B10 -- > 0) {
return;
}
next = 18;
if (gs->unk_94 & 0x400000) {
next = 34;
}
selector = lbl_10_bss_4938C ;
lbl_10_bss_14 = next;
fn_1_4A00(0, selector, (lbl_10_bss_49388));
lbl_10_bss_51744 = (0);
fn_1_12F17C();
if ((*((GameState *)&lbl_1_bss_8B3A0)).unk_0 == 1) {
lbl_1_bss_6EAB4 |= 0x24;
}
} else if (status == -1) {
tmp_ra6 = gs->unk_94;
if (tmp_ra6 & 0x2000000) {
gs->unk_94 |= 0x4000000;
}
lbl_10_bss_14 = (15);
selector = lbl_10_bss_4938C ;
lab_t1 = selector;
fn_1_4A00(0, lab_t1, (lbl_10_bss_49388));
lbl_10_bss_51744 = (0);
fn_1_12F17C();
} else if (status == 2) {
if (90.0 == lbl_10_bss_51B10) {
lbl_10_bss_14 = (16);
final_selector = lbl_10_bss_4938C ;
fn_1_4A00(0, final_selector, (lbl_10_bss_49388));
lbl_10_bss_51744 = (0);
fn_1_12F17C();
lbl_10_bss_51B0C = 1;
}
}
}
/* fzgx:end fn_10_3F54 */

/* fzgx:begin fn_10_436C */
void fn_10_436C(void) {
    fn_10_436C_SelState *s;
    u8 *base;
    s32 offset;
    s16 i;
    s32 n;
    base = (*(u8 (*)[0x50004])&(*((Obj_10_bss_0 *)&lbl_10_bss_0))) + 0x50000;
    fn_1_4BB0();
    fn_10_C594();

    if (lbl_1_bss_96A == 0x12) {
        s16 *ids;

        s = (fn_10_436C_SelState *)(*(u8 (*)[])&lbl_1_bss_8B3A0.unk_0);
        i = 0;
        ids = (*(s16 (*)[4])&lbl_1_bss_962);
        offset = 0;
        while (i < 4) {
            fn_1_12C0EC(s->items + (*ids - 0xe) * 0x94 + offset + 0x24);
            offset += 0x1c;
            i++;
        }
    }

    if (lbl_1_bss_96A != 0x14 && *(s32 *)(base + 0x1740) != -1) {
        fn_1_435C(*(u32 *)(base - 0x6c78));
        fn_1_426C(*(u32 *)(base + 0x1740));
        *(s32 *)(base + 0x1740) = -1;
    }

    fn_10_BEF4(&lbl_1_bss_8B3A0);

    s = (fn_10_436C_SelState *)(*(u8 (*)[])&lbl_1_bss_8B3A0.unk_0);

    if ((s->flags & 0x80000000) == 0 && lbl_1_bss_96A != 0x14) {
        n = 4;
        if (s->flags & 0x20000000) {
            n = 1;
        }
        fn_1_12C000(base + 0x197c, n);
        fn_1_12C000(base + 0x17ec, n);
        fn_1_12C000(base + 0x1788, 1);
        if (s->flags & 0x100) {
            fn_1_48140(0xa0);
        }
    }

    fn_10_96F8(base - 0x6c60, base - 0x1140);

    if (lbl_1_bss_96A != 0x14) {
        fn_1_12F10C(fn_1_36AD0());
        fn_1_12AF7C();
    }

    if (s->flags & 0x40000000) {
        if (*(s16 *)((*(u8 (*)[])&lbl_1_bss_8B3A0.unk_0) + 0xe) == 6) {
            *(u8 *)((*(u8 (*)[])&lbl_1_bss_8B3A0.unk_0) + 0x9f) = 0x32;
        }
        fn_1_A5330(*((*(u8 (*)[])&lbl_1_bss_8B3A0.unk_0) + 0x9f), 0);
    }

    if (s->flags & 0x40000000) {
        fn_1_13F8C4();
        fn_1_13F9F0();
    } else {
        s16 mode = *(s16 *)(*(u8 (*)[])&lbl_1_bss_8B3A0.unk_0);
        if ((u16)mode <= 1 || mode == 3 || mode == 2) {
            fn_1_13F8C4();
            fn_1_13F9F0();
            fn_1_FDFF4();
        }
    }
}
/* fzgx:end fn_10_436C */

/* fzgx:begin fn_10_4568 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_4568(void) {
    fn_1_435C( (lbl_10_bss_49388));
    lbl_10_bss_51740 = (fn_1_3F8C( ((*(char (*)[18])&"SelStartYourEngineDisp")), fn_10_21E30, (0), 8));
    fn_1_4A00(1, lbl_10_bss_4938C, (lbl_10_bss_49388));
    lbl_10_bss_51744 = 0;
    lbl_10_bss_14 = (-1);
    fn_1_47F74(0x8b);
    fn_1_47F74(0xa1);
    fn_1_34E08();
}
/* fzgx:end fn_10_4568 */

/* fzgx:begin fn_10_4600 */
void fn_10_4600(void) {
    s32 ready;
    u32 flags;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }
    flags = lbl_1_bss_8B3A0.unk_140;
    if ((flags & 0x80000000) != 0 && (flags & 0x40000000) == 0 && (lbl_1_bss_8B3A0.unk_94 & 8) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }
    if (ready != 0) {
        return;
    }
    if (lbl_10_bss_14 != -1) {
        lbl_1_bss_96A = lbl_10_bss_14;
        lbl_10_bss_14 = -1;
        return;
    }
    if (lbl_801A66C0 <= 300 && ((lbl_1_bss_9F8[lbl_1_bss_8B3A0.unk_9E].unk_8 >> 8) & 1) == 0) {
        return;
    }
    if (fn_1_467F4() != 0) {
        return;
    }
    lbl_1_bss_8B3A0.unk_94 |= 0x08000000;
    fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    fn_1_12F17C();
}
/* fzgx:end fn_10_4600 */

/* fzgx:begin fn_10_472C */
void fn_10_472C(void) {
    fn_10_C594();
    fn_1_48140(0x8b);
    if ((lbl_10_bss_51740) != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = (-1);
    }
}
/* fzgx:end fn_10_472C */

/* fzgx:begin fn_10_4790 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_4790(void) {
    fn_1_435C(lbl_10_bss_49388);
    lbl_10_bss_51740 = (fn_1_3F8C("SelRecordDisp", fn_10_2228C, 0, 8));
    fn_1_4A00(1, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    lbl_10_bss_14 = (-1);
    fn_10_25E1C();
    fn_1_15BB34((*(u8 (*)[8])&lbl_10_data_54C));
    (*(u8 **)((*(u8 (*)[])&lbl_1_bss_8B3A0.unk_0) + 0xA4))[0x22] = 0;
}
/* fzgx:end fn_10_4790 */

/* fzgx:begin fn_10_4838 */
void fn_10_4838(void) {
    u32 buttons;
    SelState *state;
    s32 busy;
    s64 result;
    s16 mode;
    u16 sub;

    buttons = fn_1_15BBC4();
    fn_1_12EF80(lbl_10_bss_55CE0.unk_0, &mode, &sub);
    if (fn_1_B7C00() != 0) {
        return;
    }
    if (((u16)buttons == 0 && mode == 1) || ((u16)buttons == 1 && mode == 2) ||
        ((u16)buttons == 2 && mode == 3) || ((u16)buttons == 3 && mode == 4) ||
        ((u16)buttons == 4 && mode == 5)) {
        if (fn_1_B7F58(&result) != 0) {
            lbl_1_bss_8B3A0.unk_A4->unk_22 = 1;
        }
    }
    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }
    if ((lbl_1_bss_8B3A0.unk_140 & 0x80000000) != 0 && (lbl_1_bss_8B3A0.unk_140 & 0x40000000) == 0 &&
        (lbl_1_bss_8B3A0.unk_94 & 8) == 0) {
        busy = 1;
    } else if (fn_1_4C10() != 0) {
        busy = 1;
    } else {
        busy = 0;
    }
    if (busy != 0) {
        return;
    }
    if (lbl_10_bss_14 != -1) {
        lbl_1_bss_96A = lbl_10_bss_14;
        lbl_10_bss_14 = -1;
        return;
    }
    state = &lbl_1_bss_8B3A0;
    if (state->unk_A4->unk_22 == 0) {
        busy = fn_10_26000();
    } else {
        fn_1_14BD44(&lbl_10_bss_55CE0, (void *)state->unk_9E);
        busy = 0;
    }
    if (busy != 0) {
        return;
    }
    if ((u16)buttons != 0xFFFF) {
        return;
    }
    if (((lbl_1_bss_9F8[lbl_1_bss_8B3A0.unk_9E].unk_8 >> 9) & 1) == 0) {
        return;
    }
    if (state->unk_A4->unk_22 != 0) {
        state->unk_A4->unk_22 = 0;
        return;
    }
    lbl_10_bss_14 = 15;
    fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    fn_1_12F17C();
}
/* fzgx:end fn_10_4838 */

/* fzgx:begin fn_10_4A84 */
void fn_10_4A84(void) {
    if ((lbl_10_bss_51740) != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    fn_10_260D4();
}
/* fzgx:end fn_10_4A84 */

/* fzgx:begin fn_10_4AE0 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

#pragma opt_dead_assignments off

u32 fn_10_4AE0(u32 arg0, u32 initial_count) {
    s16 v0;
    s64 *mask;
    s64 masks[4];
    s16 *slot;
    s16 i;
    s16 selected;
    u32 arg1;
    u8 *base;
    u8 *p_lbl_10_bss_0;
    base = (u8 *)&lbl_1_bss_8B3A0.unk_0;
    v0 = arg0;
    p_lbl_10_bss_0 = (u8 *)&(*(u32 (*)[5])&lbl_10_bss_0);
    arg1 = initial_count;
    slot = (s16 *)(base + v0 * 32);
    selected = *(slot += 7);
    if (selected == -1) {
        if (*(u32 *)((u8 *)&(lbl_1_bss_8B3A0.unk_0) + 0x94) & 0x40000000)
            selected = (*(s16 (*)[0x4])&lbl_10_data_55C)[v0];
        else
            selected = (&(*((s16 *)&lbl_10_data_554)))[v0];
    }
    mask = &masks[v0];
    *mask = 0;
    for (i = 0; i < 4; i++) {
        if ((s16)arg0 != i) {
            if ((s16)fn_1_152840(*(s16 *)((u8 *)&(lbl_1_bss_8B3A0.unk_0) + i * 32 + 14),
                 (fn_10_4AE0_Sig_fn_1_152840_Entry *)lbl_10_bss_1C,
                 lbl_10_bss_1A, lbl_10_bss_18) == 1) {
                *mask |= (s32)(1 << *(s16 *)((u8 *)&(*(u8 *)&lbl_1_bss_8B3A0.unk_0) + i * 32 + 14));
            }
        }
    }
    if ((*(u32 (*)[])&lbl_1_bss_980)[v0] == 0x09000000 ||
        (*(u32 (*)[])&lbl_1_bss_980)[v0] == 0x88000000 ||
        (*(u32 (*)[])&lbl_1_bss_980)[v0] == 0x8B100000 ||
        (*(u32 (*)[])&lbl_1_bss_980)[v0] == 0x08000000 ||
        (s16)arg0 == *((u8 *)&(lbl_1_bss_8B3A0.unk_0) + 0x9E)) {
        if (*(s16 *)((u8 *)&(lbl_1_bss_8B3A0.unk_0) + 4) > (s16)arg1) {
            if (*(u32 *)((u8 *)&(lbl_1_bss_8B3A0.unk_0) + 0x94) & 0x10000000) {
                while (!(s16)fn_1_152840(selected,
                       (fn_10_4AE0_Sig_fn_1_152840_Entry *)lbl_10_bss_1C,
                       lbl_10_bss_1A, lbl_10_bss_18) ||
                       ((((1 << selected)) & (*mask))) != 0) {
                    selected = (selected + 1) % 41;
                }
            }
            *slot = selected;
            arg1++;
        } else {
            *slot = -1;
            fn_1_12C0EC( (Sig_fn_1_12C0EC_FnData *)((Sig_fn_1_12C0EC_FnData *)(*(u8 **)((u8 *)&(lbl_1_bss_8B3A0.unk_0) + 0xA4) +
                (lbl_1_bss_962 - 14) * 0x94 + v0 * 0x1C + 0x24)));
        }
    } else {
        *slot = -1;
        fn_1_12C0EC( (Sig_fn_1_12C0EC_FnData *)((Sig_fn_1_12C0EC_FnData *)(*(u8 **)((u8 *)&(lbl_1_bss_8B3A0.unk_0) + 0xA4) +
            (lbl_1_bss_962 - 14) * 0x94 + v0 * 0x1C + 0x24)));
    }
    return arg1;
}

#pragma opt_dead_assignments reset
/* fzgx:end fn_10_4AE0 */

/* fzgx:begin fn_10_4D78 */
void fn_10_4D78(void) {
struct fn_10_4D78_lbl_10_bss_0 *p_lbl_10_bss_0;
struct { struct fn_10_4D78_lbl_1_bss_8B3A0 *value; } main_storage;
struct {u8 *value;} v4_storage;
s32 v0;
u8 *final_ptr;
u8 *v5;
u8 *v6;
u8 *v18;
s32 final_index;
s16 *v13;
s32 v7;
s16 v16;
s16 v8;
s16 v11;
s32 v15;
u32 v17;
s32 v19;
struct {u8 *value;} v2_storage;
struct {u8 *value;} v3_storage;
p_lbl_10_bss_0 = (struct fn_10_4D78_lbl_10_bss_0 *)&(*((Obj_10_bss_0 *)&lbl_10_bss_0));
main_storage.value = &(*((struct fn_10_4D78_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0));
v0 = main_storage.value ->unk_9E;
if (main_storage.value ->unk_94 & 0x30) {
struct {s16 *value;} defaults;
struct {u8 *value;} flags;
defaults.value = &(*((s16 *)&lbl_10_data_554));
flags.value = (u8 *)main_storage.value ;
for(v8=0; v8<4; main_storage.value =(struct fn_10_4D78_lbl_1_bss_8B3A0 *)((u8 *)main_storage.value +32), defaults.value++, flags.value++, v8++) {
s16 v1 = main_storage.value ->unk_E;
if(v1 != -1 && (v1 > 40 || (s16)fn_1_152840(v1, (fn_10_4AE0_Sig_fn_1_152840_Entry *)(Sig_fn_1_152840_Entry *)(p_lbl_10_bss_0->unk_1C), *(s16 *)((u8 *)p_lbl_10_bss_0+26), *(s16 *)((u8 *)p_lbl_10_bss_0+24)) == 0)) {
main_storage.value ->unk_E = *defaults.value;
*(flags.value+159) = 50;
fn_1_A5330(50,v8);
}
}
} else {
if(main_storage.value ->unk_4 == 0) {
v13=&main_storage.value ->unk_E;
v13[0]=-1;
v13[16]=-1;
v13[32]=-1;
v13[48]=-1;
v13[(s16)v0 * 16]=6;
}
v4_storage.value = (u8 *)&(*((struct fn_10_4D78_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0));
v3_storage.value =v4_storage.value ;
v2_storage.value =v4_storage.value ;
for(v11=0;v11<4;v3_storage.value +=32,v2_storage.value ++,v11++) {
if((s16)fn_1_152840(*(s16 *)(v3_storage.value +14), (fn_10_4AE0_Sig_fn_1_152840_Entry *)(Sig_fn_1_152840_Entry *)(p_lbl_10_bss_0->unk_1C), *(s16 *)((u8 *)p_lbl_10_bss_0+26), *(s16 *)((u8 *)p_lbl_10_bss_0+24))==0) {
if((lbl_1_bss_966 == 20 || lbl_1_bss_966 == 16) && *(s16 *)(v3_storage.value +14)>=54 && *(s16 *)(v3_storage.value +14)<=57) continue;
*(s16 *)(v3_storage.value +14)=-1;
*(v2_storage.value +159)=50;
fn_1_A5330(50,v11);
} else fn_1_A5330(*(v2_storage.value +159),v11);
}
{ s32 selected = (s16)v0;
v13=(s16 *)&(*((struct fn_10_4D78_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0));
v13 += selected * 16;
if(*(v13 += 7) == -1) {
if(main_storage.value ->unk_94 & 0x40000000) *v13=(*(s16 (*)[4])&lbl_10_data_55C)[(s16)v0];
else *v13=(&(*((s16 *)&lbl_10_data_554)))[(s16)v0];
*((u8 *)&(*((struct fn_10_4D78_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0))+selected+159)=50;
fn_1_A5330(50,(u8)v0);
}
}
v3_storage.value =v4_storage.value ;
v2_storage.value =v4_storage.value ;
v15=1;
for(v16=0;v16<4;v3_storage.value +=32,v2_storage.value ++,v16++) {
if(v16 != (s16)v0 && *(s16 *)(v3_storage.value +14) != -1) {
if(main_storage.value ->unk_4 <= (s16)v15) {
*(s16 *)(v3_storage.value +14)=-1;
*(v2_storage.value +159)=50;
fn_1_A5330(50,v16);
}
v15++;
}
}
v17=fn_10_4AE0(v0,0);
for(v7=0;(s16)v7<4;v7++) {
if((s16)v7 != (s16)v0) v17=fn_10_4AE0(v7,v17);
}
while((s16)v17 < main_storage.value ->unk_4) {
for(v19=0;(s16)v19<4;v19++) {
if(*(s16 *)(v4_storage.value +v19*32+14)==-1) {
*(s16 *)((u8 *)&(*((struct fn_10_4D78_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0))+((s16)v19<<5)+14)=(&(*((s16 *)&lbl_10_data_554)))[(s16)v19];
v17++;
break;
}
}
}
if(main_storage.value ->unk_94 & 0x18000) {
v5=(u8 *)&(*((struct fn_10_4D78_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0))+192;
v6=(u8 *)&(*((struct fn_10_4D78_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0))+176;
v18=(u8 *)&(*((struct fn_10_4D78_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0))+208;
final_ptr=v4_storage.value ;
for(final_index=0;(s16)final_index<4;v4_storage.value +=32,final_ptr+=4,final_index++) {
s16 v21=*(s16 *)(v4_storage.value +14);
if(v21 != -1) {
fn_1_152970((s16 *)(final_ptr+176),(s16 *)(final_ptr+178),v21,(3u << 30), (SelCell *)((Sig_fn_1_152970_Fn152970Entry *)p_lbl_10_bss_0->unk_1C),*(s16 *)((u8 *)p_lbl_10_bss_0+26),*(s16 *)((u8 *)p_lbl_10_bss_0+24));
fn_80008BEC(v5,0,16);
fn_80008BA8(v18,v6,16);
}
}
}
}
}
/* fzgx:end fn_10_4D78 */

/* fzgx:begin fn_10_5148 */
void fn_10_5148(void) {
    fn_1_435C(lbl_10_bss_49388);
    lbl_10_bss_51740 = fn_1_3F8C("SelComDisp", fn_10_13D64, 0, 8);
    fn_1_4A00(1, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
}
/* fzgx:end fn_10_5148 */

/* fzgx:begin fn_10_51BC */
void fn_10_51BC(void) {
    lbl_1_bss_96A = 0x12;
}
/* fzgx:end fn_10_51BC */

/* fzgx:begin fn_10_51CC */
void fn_10_51CC(void) {
    if ((lbl_10_bss_51740) != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    fn_10_BEF8( (fn_10_BEF8_SelState *)(&lbl_1_bss_8B3A0.unk_0));
}
/* fzgx:end fn_10_51CC */

/* fzgx:begin fn_10_5230 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

/* the retail TU's .data objects this function uses, at their retail offsets */

static inline s32 fn_10_5230_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

void fn_10_5230(void) {
    SelState *gs;
    SelState *gs2;
    fn_10_5230_Desc *desc;
    fn_10_5230_Entry *entries;
    fn_10_5230_Record records[4];
    u32 heap;
    u32 size;
    s16 shift;
    s16 i;
    u8 j;
    u8 selector;
    u8 index;
    fn_10_5230_Entry *entry;

    fn_10_C594();
    if (lbl_1_bss_8B3A0.unk_4 == 0) {
        entries = (fn_10_5230_Entry *)&lbl_1_bss_8B3A0;
        lbl_1_bss_8B3A0.unk_94 |= 0x08000000;
        entries[0].unk_E = -1;
        entries[1].unk_E = -1;
        entries[2].unk_E = -1;
        entries[3].unk_E = -1;
        entries[lbl_1_bss_8B3A0.unk_9E].unk_E = 6;
    }
    gs = &lbl_1_bss_8B3A0;
    if (gs->unk_94 & 0x40000000) {
        index = gs->unk_9E;
        entry = (fn_10_5230_Entry *)gs + index;
        if (entry->unk_E == 0x31 || entry->unk_E < 0x29) {
            shift = fn_10_5230_rand() & 3;
            ((fn_10_5230_Entry *)&lbl_1_bss_8B3A0)[index].unk_14 = 1 << shift;
            fn_1_12B4EC(fn_1_8623C(), shift);
        }
    }
    if (!(gs->unk_94 & 0x02000000)) {
        fn_80008BA8(records, lbl_1_bss_718C0 + 0xE, sizeof(records));
        for (i = 0; i < 4; i++) {
            if (((fn_10_5230_Entry *)&lbl_1_bss_8B3A0)[i].unk_E == records[i].unk_2) {
                ((fn_10_5230_Entry *)&lbl_1_bss_8B3A0)[i].unk_14 = records[i].unk_8;
            }
        }
    } else {
        ((fn_10_5230_Entry *)&lbl_1_bss_8B3A0)[0].unk_14 = 1;
    }
    gs2 = &lbl_1_bss_8B3A0;
    desc = &lbl_10_bss_51B14;
    desc->unk_4 = lbl_10_bss_51B7C;
    desc->unk_8 = lbl_10_bss_52EFC;
    desc->unk_C = ((u32)lbl_10_bss_49380);
    desc->unk_10 = lbl_10_bss_493A0;
    desc->unk_1C = (u8 *)gs2->unk_A4 + (lbl_1_bss_962 - 14) * 0x94 + 0x24;
    desc->unk_14 = lbl_10_data_454;
    desc->unk_16 = lbl_10_data_45A;
    desc->unk_18 = lbl_10_data_45C;
    desc->unk_20 = lbl_10_bss_517EC;
    desc->unk_24 = (*(u8 (*)[0x198])&lbl_10_bss_5197C);
    desc->unk_2C = 8;
    desc->unk_28 = 8;
    desc->unk_30 = 0xF0000000;
    desc->unk_34 = 1;
    desc->unk_60 = 1;
    fn_1_12B120((u8 *)desc, ((void *)lbl_10_bss_49384), ((void *)lbl_10_bss_49388),
                (*(s32 (*)[4])&lbl_10_bss_51758), (*(u8 (*)[0x20])&lbl_10_bss_51768),
                &lbl_10_bss_51740);
    selector = lbl_10_bss_4938C;
    lbl_10_bss_14 = (-1);
    fn_1_4A00(1, selector, (lbl_10_bss_49388));
    lbl_10_bss_51744 = 0;
    gs2->unk_A4->unk_19 = 0;
    if (gs->unk_94 & 0x40000000) {
        fn_1_13F81C();
        fn_1_13F948();
        fn_10_3DE0(fn_1_8623C(), (fn_10_3DE0_SelEntry *)(fn_1_36AD0()), 1);
    } else if (lbl_1_bss_8B3A0.unk_0 == 3 || lbl_1_bss_8B3A0.unk_0 == 2) {
        fn_1_13F948();
        fn_1_13F81C();
        fn_10_3DE0(0, (fn_10_3DE0_SelEntry *)(fn_1_36AD0()), 1);
        fn_1_FE004();
    } else if (lbl_1_bss_8B3A0.unk_0 == 0) {
        fn_1_13F948();
        fn_1_13F81C();
        for (j = 0; j < 4; j++) {
            fn_10_3DE0(j, (fn_10_3DE0_SelEntry *)(fn_1_36AD0()), 1);
        }
        fn_1_FE004();
    }
    heap = fn_1_4404();
    size = fn_800090A4(lbl_801A6410) - 0x10000;
    lbl_10_data_578 = (void *)fn_1_45D0(lbl_801A6410, size, lbl_10_data_57C, 0xC60);
    fn_1_46BA0(lbl_10_data_578, size);
    if (gs->unk_94 & 0x02000000) {
        s32 kinds[10] = {0, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D};

        fn_1_46A60();
        fn_1_46B44(fn_10_C654, (&(*((fn_10_5230_lbl_1_bss_8B5F4 *)&lbl_1_bss_8B5F4)).unk_0));
        fn_1_7B084((void *)kinds[(*((s8 *)&lbl_1_bss_9C))], 1);
        fn_1_9A958(kinds[(*((s8 *)&lbl_1_bss_9C))], 1);
        fn_1_46B44(fn_10_C654, (&(*((fn_10_5230_lbl_1_bss_8B5F4 *)&lbl_1_bss_8B5F4)).unk_4));
        /* fzgx-allow: S2 retail reads unk_4 again off a fresh base after the call */
        (*((fn_10_5230_lbl_1_bss_8B5F4 *)&lbl_1_bss_8B5F4)).unk_8 = ((fn_10_5230_lbl_1_bss_8B5F4 *)&(*((fn_10_5230_lbl_1_bss_8B5F4 *)&lbl_1_bss_8B5F4)))->unk_4;
        fn_1_46EA8(1);
        fn_1_4100C();
        fn_1_41104(2);
        fn_1_47E54(0xBA);
        fn_1_47E54(0xBB);
        fn_1_8001C();
        fn_1_47E54(0x94);
        fn_1_46EA8(0);
        fn_1_46B44(fn_10_C654, (&(*((fn_10_5230_lbl_1_bss_8B5F4 *)&lbl_1_bss_8B5F4)).unk_C));
    } else {
        fn_1_46A8C((*((fn_10_5230_lbl_1_bss_8B5F4 *)&lbl_1_bss_8B5F4)).unk_0);
        gs = &lbl_1_bss_8B3A0;
        fn_1_7B084((void *)gs->unk_90, 1);
        fn_1_9A958(gs->unk_90, 1);
        fn_1_46B44(fn_10_C654, (&(*((fn_10_5230_lbl_1_bss_8B5F4 *)&lbl_1_bss_8B5F4)).unk_4));
        /* fzgx-allow: S2 retail reads unk_4 again off a fresh base after the call */
        (*((fn_10_5230_lbl_1_bss_8B5F4 *)&lbl_1_bss_8B5F4)).unk_8 = ((fn_10_5230_lbl_1_bss_8B5F4 *)&(*((fn_10_5230_lbl_1_bss_8B5F4 *)&lbl_1_bss_8B5F4)))->unk_4;
        fn_1_4100C();
        fn_1_41104(2);
        fn_1_47E54(0xBB);
        fn_1_46B44(fn_10_C654, (&(*((fn_10_5230_lbl_1_bss_8B5F4 *)&lbl_1_bss_8B5F4)).unk_C));
    }
    fn_1_46BFC();
    lbl_10_bss_C = (1);
    fn_1_46B44(fn_10_C5E0, &lbl_10_data_578);
    fn_80008E84(heap);
}
/* fzgx:end fn_10_5230 */

/* fzgx:begin fn_10_5780 */
void fn_10_5780(struct Fn105780 *obj) {
    obj->value = 8;
}
/* fzgx:end fn_10_5780 */

/* fzgx:begin fn_10_578C */
#include "game/pad.h"
/* begin sofdec/adxt.h (deltawave784/fzgx, CC0) */

#ifndef SOFDEC_ADXT_H

#define SOFDEC_ADXT_H

/* CRI ADX talker (ADXT) handle, shared by the ADXT_* / adxt_* units of the DOL. */

/* begin layout_check.h (deltawave784/fzgx, CC0) */

#ifndef LAYOUT_CHECK_H

/* Compile-time layout checks for owned types. They declare array typedefs
 * only, so they emit no code or data under MWCC: a wrong size or offset is
 * a negative array bound and fails the compile. */

#endif

/* end layout_check.h */

#endif

/* end sofdec/adxt.h */

s16 fn_10_578C(void *arg0) {
    struct fn_10_578C_lbl_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    struct { s32 value; } v0;
    struct { u8 *value; } p_lbl_1_bss_9C8;
    struct { u8 *value; } p_lbl_1_bss_9F8;
    struct { u8 *value; } v4;
    struct { u8 *value; } v3;
    u8 *v19;
    u8 *v20;
    s32 v26;
    s16 v30;
    s32 v2 = 0;
    s16 v1;
    s16 v8;
    s32 v9;
    s32 v10;
    s16 v11 = 0;
    s16 v12;
    s16 v17;
    s16 v23;
    s16 old;
    s32 next;
    u32 v7;
    u32 v5;
    u32 t0;
    s32 v46;
    s16 v13;
    u32 v29;
    u32 v27;
    s16 v45;

    /* Controller state is sampled separately for each test. */
    t0 = fn_1_F9FEC();
    p_lbl_1_bss_9C8.value = (*(u8 (*)[])&lbl_1_bss_9C8);
    v1 = 0;
    v0.value = t0 != 0;
    p_lbl_1_bss_9F8.value = (*(u8 (*)[])&lbl_1_bss_9F8);
    p_lbl_1_bss_8B3A0 = &(*(struct fn_10_578C_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0);
    v4.value = p_lbl_1_bss_9C8.value;
    v3.value = p_lbl_1_bss_9F8.value;
    for (; v1 < 4; v4.value += 12, v3.value += 20, v1++) {
        if ((s8)v4.value[10] != -1 && __rlwnm(p_lbl_1_bss_8B3A0->unk_98, (v1 + 1) & 31, 31, 31)) {
            if (PAD_BIT(*(u16 *)(v3.value + 16), 3) || PAD_BIT(*(u16 *)(v3.value + 18), 3)) v2--;
            if (PAD_BIT(*(u16 *)(v3.value + 16), 2) || PAD_BIT(*(u16 *)(v3.value + 18), 2)) v2++;
            v5 = *(u16 *)(v3.value + 16);
            if (((v5 >> 2) & 1) || (((v7 = *(u16 *)(v3.value + 18)) >> 2) & 1)) fn_1_12F128(v1);
            else if (((v5 >> 3) & 1) || ((v7 >> 3) & 1)) fn_1_12F128(v1);
        }
    }
    v8 = *(s16 *)((u8 *)arg0 + 146);
    if ((s16)v2 != 0) {
        v9 = (s16)v2;
        do {
            v10 = *(s16 *)((u8 *)arg0 + 146) + v9;
            *(s16 *)((u8 *)arg0 + 146) = v10 > 8 ? 0 : v10 < 0 ? 8 : v10;
        } while ((s16)fn_1_13FB24(*(s16 *)((u8 *)arg0 + 146)) != 0);
    }
    if (v8 != *(s16 *)((u8 *)arg0 + 146)) {
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
    }
    v13 = 0;
    if (*(s16 *)((u8 *)arg0 + 146) == 8) {
        for (v12 = 0; v12 < 4; v12++) {
            if ((s8)p_lbl_1_bss_9C8.value[v12 * 12 + 10] != -1 && __rlwnm(p_lbl_1_bss_8B3A0->unk_98, (v12 + 1) & 31, 31, 31)) {
                if (PAD_BIT(*(u16 *)(p_lbl_1_bss_9F8.value + v12 * 20 + 8), 9)) v13--;
                if (PAD_BIT(*(u16 *)(p_lbl_1_bss_9F8.value + v12 * 20 + 8), 8)) v13 = (v13 + 1);
                v5 = *(u16 *)(p_lbl_1_bss_9F8.value + v12 * 20 + 8);
                if ((v5 >> 8) & 1) fn_1_12F150(v12, 9, 1);
                else if ((v5 >> 9) & 1) fn_1_12F150(v12, 9, 0);
            }
        }
        if (v13 != 0) fn_1_A2D84(0xA9010100);
        v11 = v13;
    } else {
        v19 = p_lbl_1_bss_9C8.value;
        v20 = p_lbl_1_bss_9F8.value;
        for (v17 = 0; v17 < 4; v19 += 12, v20 += 20, v17++) {
            if ((s8)v19[10] != -1 && __rlwnm(p_lbl_1_bss_8B3A0->unk_98, (v17 + 1) & 31, 31, 31)) {
                if (PAD_BIT(*(u16 *)(v20 + 8), 9)) v13--;
                if (PAD_BIT(*(u16 *)(v20 + 8), 8)) v13 = (v13 + 1);
                v5 = *(u16 *)(v20 + 8);
                if ((v5 >> 8) & 1) fn_1_12F150(v17, 9, 1);
                else if ((v5 >> 9) & 1) fn_1_12F150(v17, 9, 0);
            }
        }
        if (v13 < 0) {
            v11 = -1;
            fn_1_A2D84(0xA9010200);
        } else if (v13 > 0) {
            *(s16 *)((u8 *)arg0 + 146) = 8;
            fn_1_A2D84(0xA9010100);
        }
        v26 = 0;
        for (v23 = 0; v23 < 4; v23++) {
            if ((s8)p_lbl_1_bss_9C8.value[v23 * 12 + 10] != -1 && __rlwnm(p_lbl_1_bss_8B3A0->unk_98, (v23 + 1) & 31, 31, 31)) {
                if (PAD_BIT(*(u16 *)(p_lbl_1_bss_9F8.value + v23 * 20 + 16), 0) || PAD_BIT(*(u16 *)(p_lbl_1_bss_9F8.value + v23 * 20 + 18), 0)) v26--;
                if (PAD_BIT(*(u16 *)(p_lbl_1_bss_9F8.value + v23 * 20 + 16), 1) || PAD_BIT(*(u16 *)(p_lbl_1_bss_9F8.value + v23 * 20 + 18), 1)) v26++;
                v27 = *(u16 *)(p_lbl_1_bss_9F8.value + v23 * 20 + 16);
                if (((v27 >> 1) & 1) || (((v29 = *(u16 *)(p_lbl_1_bss_9F8.value + v23 * 20 + 18)) >> 1) & 1)) fn_1_12F128(v23);
                else if ((v27 & 1) || (v29 & 1)) fn_1_12F128(v23);
            }
        }
        v30 = *(s16 *)((u8 *)arg0 + 146);
        switch (v30) {
        case 4:
            old = *(s16 *)((u8 *)arg0 + 300);
            next = old + (s16)v26;
            *(s16 *)((u8 *)arg0 + 300) = next > 29 ? 0 : next < 0 ? 29 : next;
            if (old != *(s16 *)((u8 *)arg0 + 300)) {
                fn_1_A2D84(0xA9010000);
                lbl_801A66A8 = 0;
            }
            break;
        case 6:
            old = *(s16 *)((u8 *)arg0 + 302);
            next = old + (s16)v26;
            *(s16 *)((u8 *)arg0 + 302) = next > 1 ? 0 : next < 0 ? 1 : next;
            if (old != *(s16 *)((u8 *)arg0 + 302)) {
                fn_1_A2D84(0xA9010000);
                lbl_801A66A8 = 0;
            }
            break;
        case 3:
            old = *(s16 *)((u8 *)arg0 + 304);
            next = old + (s16)v26;
            *(s16 *)((u8 *)arg0 + 304) = next > 1 ? 0 : next < 0 ? 1 : next;
            if (old != *(s16 *)((u8 *)arg0 + 304)) {
                fn_1_A2D84(0xA9010000);
                lbl_801A66A8 = 0;
            }
            break;
        case 1:
            old = *(s16 *)((u8 *)arg0 + 306);
            next = old + (s16)v26;
            *(s16 *)((u8 *)arg0 + 306) = next > 1 ? 0 : next < 0 ? 1 : next;
            if (old != *(s16 *)((u8 *)arg0 + 306)) {
                fn_1_A2D84(0xA9010000);
                lbl_801A66A8 = 0;
            }
            break;
        case 7:
            old = *(s16 *)((u8 *)arg0 + 308);
            next = old + (s16)v26;
            *(s16 *)((u8 *)arg0 + 308) = next > 1 ? 0 : next < 0 ? 1 : next;
            if (old != *(s16 *)((u8 *)arg0 + 308)) {
                fn_1_A2D84(0xA9010000);
                lbl_801A66A8 = 0;
            }
            break;
        case 2:
            old = *(s16 *)((u8 *)arg0 + 310);
            next = old + (s16)v26;
            *(s16 *)((u8 *)arg0 + 310) = next > 1 ? 0 : next < 0 ? 1 : next;
            if (old != *(s16 *)((u8 *)arg0 + 310)) {
                fn_1_A2D84(0xA9010000);
                lbl_801A66A8 = 0;
            }
            break;
        case 0:
            old = *(s16 *)((u8 *)arg0 + 314);
            next = old + (s16)v26;
            *(s16 *)((u8 *)arg0 + 314) = next > 20 ? 0 : next < 0 ? 20 : next;
            if (old != *(s16 *)((u8 *)arg0 + 314)) {
                fn_1_A2D84(0xA9010000);
                lbl_801A66A8 = 0;
            }
            break;
        case 5:
            v45 = *(s16 *)((u8 *)arg0 + 8);
            v46 = 2;
            if (v0.value) v46 = 3;
            next = v45 + (s16)v26;
            if (next > v46) next = 0;
            else if (next < 0) {
                next = 2;
                if (v0.value) next = 3;
            }
            *(s16 *)((u8 *)arg0 + 8) = next;
            if (v45 != *(s16 *)((u8 *)arg0 + 8)) {
                fn_1_A2D84(0xA9010000);
                lbl_801A66A8 = 0;
            }
            *(s16 *)((u8 *)arg0 + 10) = *(s16 *)((u8 *)arg0 + 8);
            break;
        }
        if (v30 != *(s16 *)((u8 *)arg0 + 146)) {
            fn_1_A2D84(0xA9010000);
            lbl_801A66A8 = 0;
        }
    }
    return v11;
}
/* fzgx:end fn_10_578C */

/* fzgx:begin fn_10_5E94 */
#pragma opt_common_subs off

fn_10_5E94_s16 fn_10_5E94(void *arg0) {



struct { fn_10_5E94_s16 value; } v29;
struct { fn_10_5E94_s16 value; } v25;
fn_10_5E94_s16 v7;
fn_10_5E94_s32 v8;
fn_10_5E94_s32 v9;
fn_10_5E94_s16 v30, v32, v34, v36, v38, v40, v42;
fn_10_5E94_s32 v31, v33, v35, v37, v39, v41, v43;
fn_10_5E94_u32 v6;
fn_10_5E94_u32 v4;
fn_10_5E94_s16 v16;
fn_10_5E94_s16 v0;
fn_10_5E94_s16 v1;
struct { fn_10_5E94_u8 *value; } v2;
struct { fn_10_5E94_u8 *value; } v3;
union { fn_10_5E94_u8 *value; } p_lbl_1_bss_9F8;
union { fn_10_5E94_u8 *value; } p_lbl_1_bss_9C8;
struct { fn_10_5E94_u8 *value; } v18;
struct { fn_10_5E94_u8 *value; } v19;
struct fn_10_5E94_lbl_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
fn_10_5E94_s16 v10;
fn_10_5E94_s16 v22;
fn_10_5E94_s16 v11;
v3.value = 0;
v2.value = 0;
p_lbl_1_bss_9C8.value = (fn_10_5E94_u8 *)&(*(fn_10_5E94_u8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9C8));
p_lbl_1_bss_9F8.value = (fn_10_5E94_u8 *)((fn_10_5E94_u8 (*)[])&(*(fn_10_5E94_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8)));
v3.value = p_lbl_1_bss_9C8.value;
v1 = 0;
v2.value = p_lbl_1_bss_9F8.value;
p_lbl_1_bss_8B3A0 = (struct fn_10_5E94_lbl_1_bss_8B3A0 *)((struct fn_10_5E94_lbl_1_bss_8B3A0 *)&(*(fn_10_5E94_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0));
v10 = 0;
for (v0 = 0; (fn_10_5E94_s16)v0 < 4; v0++) {
if ((fn_10_5E94_s8)*((fn_10_5E94_u8 *)v3.value + 10) != -1 && (__rlwnm(p_lbl_1_bss_8B3A0->unk_98, ((fn_10_5E94_s16)(v0) + 1) & 31, 31, 31)) ) {
if (((((*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(v2.value) + (16))) >> 3) & 1)) || ((((*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(v2.value) + (18))) >> 3) & 1))) v1--;
if (((((*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(v2.value) + (16))) >> 2) & 1)) || ((((*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(v2.value) + (18))) >> 2) & 1))) v1++;
v4 = (*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(v2.value) + (16))) ;
if (((v4 >> 2) & 1) || (((v6 = (*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(v2.value) + (18))) ) >> 2) & 1)) fn_1_12F128(v0);
else if (((v4 >> 3) & 1) || ((v6 >> 3) & 1)) fn_1_12F128(v0);
}
v3.value = (fn_10_5E94_u8 *)v3.value + 12;
v2.value = (fn_10_5E94_u8 *)v2.value + 20;
}
v7 = (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (146))) ;
if ((fn_10_5E94_s16)v1 != 0) {
v8 = (fn_10_5E94_s16)v1;
do {
v9 = (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (146))) + v8;
if (v9 > 8) v9 = 0;
else v9 = v9 < 0 ? 8 : v9;
(*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (146))) = v9;
} while ((fn_10_5E94_s16)fn_1_13FA88((*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (146))) ) != 0);
}
if (v7 != (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (146))) ) {
fn_1_A2D84(0xA9010000);
(*(fn_10_5E94_u32 *)&lbl_801A66A8) = 0;
}
v1 = 0;
if ((*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (146))) == 8) {
for (v11 = 0; (fn_10_5E94_s16)v11 < 4; v11++) {
if ((fn_10_5E94_s8)*((fn_10_5E94_u8 *)p_lbl_1_bss_9C8.value + 10) != -1 && (__rlwnm(p_lbl_1_bss_8B3A0->unk_98, ((fn_10_5E94_s16)(v11) + 1) & 31, 31, 31)) ) {
if ((((*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(p_lbl_1_bss_9F8.value) + (8))) >> 9) & 1)) v1--;
if ((((*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(p_lbl_1_bss_9F8.value) + (8))) >> 8) & 1)) v1 = (fn_10_5E94_s16)(v1 + 1);
v4 = (*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(p_lbl_1_bss_9F8.value) + (8))) ;
if ((v4 >> 8) & 1) fn_1_12F150(v11, 9, 1);
else if ((v4 >> 9) & 1) fn_1_12F150(v11,9,0);
}
p_lbl_1_bss_9C8.value = (fn_10_5E94_u8 *)p_lbl_1_bss_9C8.value + 12;
p_lbl_1_bss_9F8.value = (fn_10_5E94_u8 *)p_lbl_1_bss_9F8.value + 20;
}
if ((fn_10_5E94_s16)v1 != 0) fn_1_A2D84(0xA9010100);
v10 = v1;
} else {
v18.value = p_lbl_1_bss_9C8.value;
v19.value = p_lbl_1_bss_9F8.value;
for (v16 = 0; (fn_10_5E94_s16)v16 < 4; v16++) {
if ((fn_10_5E94_s8)*((fn_10_5E94_u8 *)v18.value + 10) != -1 && (__rlwnm(p_lbl_1_bss_8B3A0->unk_98, ((fn_10_5E94_s16)(v16) + 1) & 31, 31, 31)) ) {
if ((((*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(v19.value) + (8))) >> 9) & 1)) v1--;
if ((((*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(v19.value) + (8))) >> 8) & 1)) v1 = (fn_10_5E94_s16)(v1 + 1);
v4 = (*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(v19.value) + (8))) ;
if ((v4 >> 8) & 1) fn_1_12F150(v16, 9, 1);
else if ((v4 >> 9) & 1) fn_1_12F150(v16,9,0);
}
v18.value = (fn_10_5E94_u8 *)v18.value + 12;
v19.value = (fn_10_5E94_u8 *)v19.value + 20;
}
if ((fn_10_5E94_s16)v1 < 0) {
v10 = -1;
fn_1_A2D84(0xA9010200);
} else if ((fn_10_5E94_s16)v1 > 0) {
(*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (146))) = 8;
fn_1_A2D84(0xA9010100);
}
v25.value = 0;
for (v22 = 0; (fn_10_5E94_s16)v22 < 4; v22++) {
if ((fn_10_5E94_s8)*((fn_10_5E94_u8 *)p_lbl_1_bss_9C8.value + 10) != -1 && (__rlwnm(p_lbl_1_bss_8B3A0->unk_98, ((fn_10_5E94_s16)(v22) + 1) & 31, 31, 31)) ) {
if (((*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(p_lbl_1_bss_9F8.value) + (16))) & 1) || ((*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(p_lbl_1_bss_9F8.value) + (18))) & 1)) v25.value--;
if (((((*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(p_lbl_1_bss_9F8.value) + (16))) >> 1) & 1)) || ((((*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(p_lbl_1_bss_9F8.value) + (18))) >> 1) & 1))) v25.value++;
v6 = (*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(p_lbl_1_bss_9F8.value) + (16))) ;
if (((v6 >> 1) & 1) || (((v4 = (*(fn_10_5E94_u16 *)((fn_10_5E94_u8 *)(p_lbl_1_bss_9F8.value) + (18))) ) >> 1) & 1)) fn_1_12F128(v22);
else if (((v6 >> 0) & 1) || ((v4 >> 0) & 1)) fn_1_12F128(v22);
}
p_lbl_1_bss_9C8.value = (fn_10_5E94_u8 *)p_lbl_1_bss_9C8.value + 12;
p_lbl_1_bss_9F8.value = (fn_10_5E94_u8 *)p_lbl_1_bss_9F8.value + 20;
}
v29.value = (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (146))) ;
switch (v29.value) {
case 4: v30 = (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (300))); v31 = v30 + (fn_10_5E94_s16)v25.value; if ((fn_10_5E94_s32)v31 > 29) v31 = 0; else v31 = (fn_10_5E94_s32)v31 < 0 ? 29 : v31; (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (300))) = v31; if (v30 != (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (300)))) { fn_1_A2D84(0xA9010000); (*(fn_10_5E94_u32 *)&lbl_801A66A8) = 0; } ; break;
case 6: v32 = (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (302))); v33 = v32 + (fn_10_5E94_s16)v25.value; if ((fn_10_5E94_s32)v33 > 1) v33 = 0; else v33 = (fn_10_5E94_s32)v33 < 0 ? 1 : v33; (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (302))) = v33; if (v32 != (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (302)))) { fn_1_A2D84(0xA9010000); (*(fn_10_5E94_u32 *)&lbl_801A66A8) = 0; } ; break;
case 3: v34 = (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (304))); v35 = v34 + (fn_10_5E94_s16)v25.value; if ((fn_10_5E94_s32)v35 > 1) v35 = 0; else v35 = (fn_10_5E94_s32)v35 < 0 ? 1 : v35; (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (304))) = v35; if (v34 != (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (304)))) { fn_1_A2D84(0xA9010000); (*(fn_10_5E94_u32 *)&lbl_801A66A8) = 0; } ; break;
case 1: v36 = (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (306))); v37 = v36 + (fn_10_5E94_s16)v25.value; if ((fn_10_5E94_s32)v37 > 1) v37 = 0; else v37 = (fn_10_5E94_s32)v37 < 0 ? 1 : v37; (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (306))) = v37; if (v36 != (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (306)))) { fn_1_A2D84(0xA9010000); (*(fn_10_5E94_u32 *)&lbl_801A66A8) = 0; } ; break;
case 7: v38 = (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (308))); v39 = v38 + (fn_10_5E94_s16)v25.value; if ((fn_10_5E94_s32)v39 > 1) v39 = 0; else v39 = (fn_10_5E94_s32)v39 < 0 ? 1 : v39; (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (308))) = v39; if (v38 != (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (308)))) { fn_1_A2D84(0xA9010000); (*(fn_10_5E94_u32 *)&lbl_801A66A8) = 0; } ; break;
case 2: v40 = (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (312))); v41 = v40 + (fn_10_5E94_s16)v25.value; if ((fn_10_5E94_s32)v41 > 1) v41 = 0; else v41 = (fn_10_5E94_s32)v41 < 0 ? 1 : v41; (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (312))) = v41; if (v40 != (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (312)))) { fn_1_A2D84(0xA9010000); (*(fn_10_5E94_u32 *)&lbl_801A66A8) = 0; } ; break;
case 0: v42 = (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (316))); v43 = v42 + (fn_10_5E94_s16)v25.value; if ((fn_10_5E94_s32)v43 > 20) v43 = 1; else v43 = (fn_10_5E94_s32)v43 < 1 ? 20 : v43; (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (316))) = v43; if (v42 != (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (316)))) { fn_1_A2D84(0xA9010000); (*(fn_10_5E94_u32 *)&lbl_801A66A8) = 0; } ; break;
case 5: break;
}
if (v29.value != (*(fn_10_5E94_s16 *)((fn_10_5E94_u8 *)arg0 + (146))) ) {
fn_1_A2D84(0xA9010000);
(*(fn_10_5E94_u32 *)&lbl_801A66A8) = 0;
}
}
return v10;
}
#pragma opt_common_subs reset
/* fzgx:end fn_10_5E94 */

/* fzgx:begin fn_10_6518 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

/* the retail TU's .rodata ahead of this function's objects (lbl_10_rodata_0..0x80) */

/* +0x20 2.0 and +0x28 the unsigned int-to-float constant are compiler literals */

/* +0x48 90.0 and +0x50 the signed int-to-float constant are compiler literals */

static inline s32 fn_10_6518_busy(void) {
    u32 flags = lbl_1_bss_8B3A0.unk_140;

    if ((flags & (1U << 31)) && !(flags & 0x40000000) && !(lbl_1_bss_8B3A0.unk_94 & 8)) {
        return 1;
    }
    if (fn_1_4C10() != 0) {
        return 1;
    }
    return 0;
}

static inline s32 fn_10_6518_limit(void) {
    s32 r = (fn_1_F9FEC());
    s32 n = 2;

    if (r != 0) {
        n = 3;
    }
    return n;
}

#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

void fn_10_6518(void) {
    SelState *gs;
    fn_10_6518_Player *players;
    fn_10_6518_Pad *pads;
    s16 result;
    s16 j;
    s16 i;
    s16 k;
    s8 level;
    s8 slot;
    u32 flags;

    if (lbl_801A66C0 == 30.0) {
        fn_1_A2D84(0xA9120500);
    }
    gs = &lbl_1_bss_8B3A0;
    if ((gs->unk_94 & 0x40000000) && !fn_1_D6698()) {
        for (j = 0; j < 4; j++) {
            if (!fn_1_D6740(j)) {
                continue;
            }
            if (j == fn_1_D66B0()) {
                continue;
            }
            fn_1_D66F8(j, &level, &slot);
            if (slot < 0 || slot > 3) {
                slot = CLAMP(slot, 0, 3);
            }
            if (level >= 41) {
                level = fn_1_36AD0()[fn_1_D66B8(j) * 0x81C0 + 5];
                if (level == 49) {
                    fn_1_12B4EC(fn_1_D66B8(j), slot);
                } else if (level > 40) {
                    fn_1_12B5B4(fn_1_D66B8(j), slot);
                }
            }
        }
    }
    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }
    if (fn_10_6518_busy()) {
        return;
    }
    if (((s32)lbl_10_bss_14) != -1) {
        s32 v = lbl_10_bss_14;

        lbl_10_bss_14 = (-1);
        lbl_1_bss_96A = v;
        return;
    }
    if (!(gs->unk_94 & 0x40000000) && lbl_1_bss_8B3A0.unk_0 == 0) {
        switch (fn_10_C258( (fn_10_C258_SelContext *)&lbl_1_bss_8B3A0, lbl_1_bss_962)) {
        case 0:
            result = fn_1_12B3BC( (fn_10_6518_Desc *)(&(*((fn_10_6518_Desc *)&lbl_10_bss_51B14))), ((void *)lbl_10_bss_49384), ((void *)lbl_10_bss_49388),
                                 (*(s32 (*)[4])&lbl_10_bss_51758), (*(u8 (*)[0x20])&lbl_10_bss_51768),
                                 &lbl_10_bss_51740, 1);
            if (result == 1) {
                lbl_1_bss_8B3A0.unk_92 = 8;
                fn_10_C274( (fn_10_C274_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                fn_1_A2D84(0xA9010100);
                lbl_1_bss_8B3A0.unk_12C = CLAMP(lbl_1_bss_8B3A0.unk_12C, 0, 29);
                lbl_1_bss_8B3A0.unk_12E = CLAMP(lbl_1_bss_8B3A0.unk_12E, 0, 1);
                lbl_1_bss_8B3A0.unk_130 = CLAMP(lbl_1_bss_8B3A0.unk_130, 0, 1);
                lbl_1_bss_8B3A0.unk_132 = CLAMP(lbl_1_bss_8B3A0.unk_132, 0, 1);
                lbl_1_bss_8B3A0.unk_134 = CLAMP(lbl_1_bss_8B3A0.unk_134, 0, 1);
                lbl_1_bss_8B3A0.unk_138 = CLAMP(lbl_1_bss_8B3A0.unk_138, 0, 1);
                lbl_1_bss_8B3A0.unk_13C = CLAMP(lbl_1_bss_8B3A0.unk_13C, 1, 20);
                lbl_1_bss_8B3A0.unk_8 = 1;
                fn_10_CFAC(1, 0, 30, 34);
            } else if (result == -1) {
                flags = gs->unk_94;
                if (flags & 0x02000000) {
                    (*((fn_10_6518_Bss9C *)&lbl_1_bss_9C)).unk_8 = 0x87;
                    gs->unk_94 = flags | 0x01000000;
                } else if (flags & 0x00400000) {
                    gs->unk_94 = flags | 0x04000000;
                } else {
                    lbl_10_bss_14 = (0x10);
                }
                fn_1_4A00(0, lbl_10_bss_4938C, (lbl_10_bss_49388));
                lbl_10_bss_51744 = 0;
                fn_1_12F17C();
                fn_1_469BC();
                fn_1_7B184(lbl_1_bss_8B3A0.unk_90);
                fn_1_9AA2C(lbl_1_bss_8B3A0.unk_90);
                fn_1_46BFC();
                lbl_10_bss_C = (1);
                fn_1_46B44(fn_10_C5E0, &lbl_10_data_578);
            }
            break;
        case 1:
            result = fn_10_5E94(&lbl_1_bss_8B3A0);
            if (result > 0) {
                flags = gs->unk_94;
                if (flags & 0x02000000) {
                    gs->unk_94 = flags | 0x01000000;
                } else {
                    gs->unk_94 = flags | 0x08000000;
                }
                (*((Obj_1_bss_6EAB4 *)&lbl_1_bss_6EAB4)).unk_0 |= 0x24;
                fn_1_4A00(0, lbl_10_bss_4938C, (lbl_10_bss_49388));
                lbl_10_bss_51744 = 0;
                fn_1_12F17C();
            }
            if (result < 0) {
                flags = gs->unk_94;
                if (!(flags & 0x40000000) || (flags & 0x4000)) {
                    players = (fn_10_6518_Player *)&lbl_1_bss_8B3A0;
                    pads = (fn_10_6518_Pad *)&(*(u8 (*)[])&lbl_1_bss_9F8);
                    for (i = 0; i < 4; i++) {
                        if ((pads[i].unk_8 >> 9) & 1) {
                            const char *names[1] = {"SEL_WAIT"};

                            fn_1_12E0B8(i, players[i].unk_E, (*((fn_10_6518_Desc *)&lbl_10_bss_51B14)).unk_4 + i * 0x4E0, (*((fn_10_6518_Desc *)&lbl_10_bss_51B14)).unk_8 + i * 0x9C0, 0,
                                        names, 1);
                            fn_1_12C0EC((u8 *)lbl_1_bss_8B3A0.unk_A4 + (lbl_1_bss_962 - 14) * 0x94 + i * 0x1C + 0x24);
                        }
                    }
                    fn_10_C298( (fn_10_C298_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                    fn_1_A2D84(0xA9010200);
                    fn_10_CFAC(1, 0, 30, 33);
                }
            }
            break;
        }
    } else if (!(gs->unk_94 & 0x40000000) && lbl_1_bss_8B3A0.unk_0 == 3) {
        switch (fn_10_C258( (fn_10_C258_SelContext *)&lbl_1_bss_8B3A0, lbl_1_bss_962)) {
        case 0:
            result = fn_1_12B3BC( (fn_10_6518_Desc *)(&(*((fn_10_6518_Desc *)&lbl_10_bss_51B14))), ((void *)lbl_10_bss_49384), ((void *)lbl_10_bss_49388),
                                 (*(s32 (*)[4])&lbl_10_bss_51758), (*(u8 (*)[0x20])&lbl_10_bss_51768),
                                 &lbl_10_bss_51740, 1);
            if (result == 1) {
                lbl_1_bss_8B3A0.unk_92 = 8;
                fn_10_C274( (fn_10_C274_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                fn_1_A2D84(0xA9010100);
                lbl_1_bss_8B3A0.unk_12C = CLAMP(lbl_1_bss_8B3A0.unk_12C, 0, 29);
                lbl_1_bss_8B3A0.unk_12E = CLAMP(lbl_1_bss_8B3A0.unk_12E, 0, 1);
                lbl_1_bss_8B3A0.unk_130 = CLAMP(lbl_1_bss_8B3A0.unk_130, 0, 1);
                lbl_1_bss_8B3A0.unk_132 = CLAMP(lbl_1_bss_8B3A0.unk_132, 0, 1);
                lbl_1_bss_8B3A0.unk_134 = CLAMP(lbl_1_bss_8B3A0.unk_134, 0, 1);
                lbl_1_bss_8B3A0.unk_136 = CLAMP(lbl_1_bss_8B3A0.unk_136, 0, 1);
                lbl_1_bss_8B3A0.unk_13A = CLAMP(lbl_1_bss_8B3A0.unk_13A, 0, 20);
                lbl_1_bss_8B3A0.unk_A = lbl_1_bss_8B3A0.unk_8 = CLAMP(lbl_1_bss_8B3A0.unk_8, 0, fn_10_6518_limit());
                fn_10_CFAC(1, 0, 30, 34);
            } else if (result == -1) {
                flags = gs->unk_94;
                if (flags & 0x02000000) {
                    (*((fn_10_6518_Bss9C *)&lbl_1_bss_9C)).unk_8 = 0x87;
                    gs->unk_94 = flags | 0x01000000;
                } else if (flags & 0x00400000) {
                    gs->unk_94 = flags | 0x04000000;
                } else {
                    lbl_10_bss_14 = (0x10);
                }
                fn_1_4A00(0, lbl_10_bss_4938C, (lbl_10_bss_49388));
                lbl_10_bss_51744 = 0;
                fn_1_12F17C();
                fn_1_469BC();
                fn_1_7B184(lbl_1_bss_8B3A0.unk_90);
                fn_1_9AA2C(lbl_1_bss_8B3A0.unk_90);
                fn_1_46BFC();
                lbl_10_bss_C = (1);
                fn_1_46B44(fn_10_C5E0, &lbl_10_data_578);
            }
            break;
        case 1:
            result = fn_10_578C(&lbl_1_bss_8B3A0);
            if (result > 0) {
                flags = gs->unk_94;
                if (flags & 0x02000000) {
                    gs->unk_94 = flags | 0x01000000;
                } else {
                    gs->unk_94 = flags | 0x08000000;
                }
                (*((Obj_1_bss_6EAB4 *)&lbl_1_bss_6EAB4)).unk_0 |= 0x24;
                fn_1_4A00(0, lbl_10_bss_4938C, (lbl_10_bss_49388));
                lbl_10_bss_51744 = 0;
                fn_1_12F17C();
            }
            if (result < 0) {
                flags = gs->unk_94;
                if (!(flags & 0x40000000) || (flags & 0x4000)) {
                    players = (fn_10_6518_Player *)&lbl_1_bss_8B3A0;
                    pads = (fn_10_6518_Pad *)&(*(u8 (*)[])&lbl_1_bss_9F8);
                    for (k = 0; k < 4; k++) {
                        if ((pads[k].unk_8 >> 9) & 1) {
                            const char *names[1] = {"SEL_WAIT"};

                            fn_1_12E0B8(k, players[k].unk_E, (*((fn_10_6518_Desc *)&lbl_10_bss_51B14)).unk_4 + k * 0x4E0, (*((fn_10_6518_Desc *)&lbl_10_bss_51B14)).unk_8 + k * 0x9C0, 0,
                                        names, 1);
                            fn_1_12C0EC((u8 *)lbl_1_bss_8B3A0.unk_A4 + (lbl_1_bss_962 - 14) * 0x94 + k * 0x1C + 0x24);
                        }
                    }
                    fn_10_C298( (fn_10_C298_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                    fn_1_A2D84(0xA9010200);
                    fn_10_CFAC(1, 0, 30, 33);
                }
            }
            break;
        }
    } else {
        result = fn_1_12B3BC( (fn_10_6518_Desc *)(&(*((fn_10_6518_Desc *)&lbl_10_bss_51B14))), ((void *)lbl_10_bss_49384), ((void *)lbl_10_bss_49388),
                             (*(s32 (*)[4])&lbl_10_bss_51758), (*(u8 (*)[0x20])&lbl_10_bss_51768),
                             &lbl_10_bss_51740, 0);
        if (result == 1) {
            flags = gs->unk_94;
            if (flags & 0x02000000) {
                gs->unk_94 = flags | 0x01000000;
            } else {
                gs->unk_94 = flags | 0x08000000;
            }
            (*((Obj_1_bss_6EAB4 *)&lbl_1_bss_6EAB4)).unk_0 |= 0x24;
            fn_1_4A00(0, lbl_10_bss_4938C, (lbl_10_bss_49388));
            lbl_10_bss_51744 = 0;
            fn_1_12F17C();
        } else if (result == -1) {
            flags = gs->unk_94;
            if (flags & 0x02000000) {
                (*((fn_10_6518_Bss9C *)&lbl_1_bss_9C)).unk_8 = 0x87;
                gs->unk_94 = flags | 0x01000000;
            } else if (flags & 0x00400000) {
                gs->unk_94 = flags | 0x04000000;
            } else {
                lbl_10_bss_14 = (0x10);
            }
            fn_1_4A00(0, lbl_10_bss_4938C, (lbl_10_bss_49388));
            lbl_10_bss_51744 = 0;
            fn_1_12F17C();
            fn_1_469BC();
            fn_1_7B184(lbl_1_bss_8B3A0.unk_90);
            fn_1_9AA2C(lbl_1_bss_8B3A0.unk_90);
            fn_1_46BFC();
            lbl_10_bss_C = (1);
            fn_1_46B44(fn_10_C5E0, &lbl_10_data_578);
        }
    }
}
/* fzgx:end fn_10_6518 */

/* fzgx:begin fn_10_7130 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */



void fn_10_7130(void) {
    struct { fn_10_7130_SelEntry *value; } entry;
    s16 value;
    s32 offset;
    s32 off;
    u32 flags;
    s16 i;

    fn_10_C594();
    fn_10_C084( (fn_10_C084_SelState *)(&(*(fn_10_7130_SelGlobals *)&lbl_1_bss_8B3A0.unk_0)));
    i = 0;
    entry.value = (fn_10_7130_SelEntry *)&(*(fn_10_7130_SelGlobals *)&lbl_1_bss_8B3A0.unk_0);
    offset = 0;
    while (i < 4) {
        value = entry.value->value;
        if (value < 0 || value > 0x28) {
            u8 *p = fn_1_36AD0() + offset;
            flags = *(u32 *)p;
            if ((flags & 0x80000000) == 0)
                goto skip; /* skip this entry: shared loop tail advances to the next one */
            if (lbl_1_bss_96A == 0x10)
                *(u32 *)p = flags & 0x3fffffff;
            if ((*(u32 *)p & 0x40000000) != 0)
                goto skip; /* skip this entry: shared loop tail advances to the next one */
            value = ((p)[0x81a0]);
        }
        off = value * 0x440;
        if ((lbl_10_data_45A) !=
            (s16)((lbl_10_data_45A) +
                  *(s16 *)((u8 *)((u32)lbl_10_bss_49380) + off + 0x3b8) % 4)) {
            fn_800713E0(
                *(u32 *)((u8 *)((u32)lbl_10_bss_49380) + off +
                         (lbl_10_data_454) * 0xc + 0x338),
                *(u32 *)((u8 *)((u32)lbl_10_bss_49380) + off +
                         lbl_10_data_45A % 4 * 4 + 0x37c));
            fn_1_8019C(*(u32 *)((u8 *)(lbl_10_bss_49380) + off +
                                (lbl_10_data_454) * 0xc + 0x338));
            *(s16 *)((u8 *)((u32)lbl_10_bss_49380) + off + 0x3b8) =
                lbl_10_data_45A;
        }
skip:
        offset += 0x81c0;
        i++;
        entry.value = (fn_10_7130_SelEntry *)((u8 *)entry.value + 0x20);
    }
    fn_1_12B3F8((*(u8 (*)[0x14])&lbl_10_bss_51B14),
                lbl_10_bss_49384,
                lbl_10_bss_49388,
                (*(u8 (*)[0x10])&lbl_10_bss_51758),
                (*(u8 (*)[0x20])&lbl_10_bss_51768),
                &lbl_10_bss_51740);
    {
        fn_1_12C6BC(((u32 *)(*(u8 (*)[0x14])&lbl_10_bss_51B14))[4]);
    }
    if (((*(fn_10_7130_SelGlobals *)&lbl_1_bss_8B3A0.unk_0).flags_94 & 0x40000000) != 0) {
        fn_1_13F8C4();
        fn_1_13F9F0();
    } else {
        value = (*(fn_10_7130_SelGlobals *)&lbl_1_bss_8B3A0.unk_0).state;
        if ((u16)(value - 2) <= 1 || value == 0) {
            fn_1_FDFF4();
            fn_1_13F9F0();
            fn_1_13F8C4();
        }
    }
}
/* fzgx:end fn_10_7130 */

/* fzgx:begin fn_10_7320 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_7320(void) {
    fn_1_4A00(1, lbl_10_bss_4938C, (lbl_10_bss_49388));
    lbl_10_bss_51744 = 0;
    fn_1_435C( (lbl_10_bss_49388));
    lbl_10_bss_51740 = (fn_1_3F8C( ((*(char (*)[18])&"SelMagCardCheckDisp")), fn_10_1B658, (0), 8));
    fn_1_12F1E8(480);
    lbl_10_bss_14 = (-1);
}
/* fzgx:end fn_10_7320 */

/* fzgx:begin fn_10_73AC */
void fn_10_73AC(void) {
    struct { struct fn_10_73AC_S9C8 *p; } rows;
    /* volatile: the manager fields are re-read after each call in the loop */
    volatile struct S8B3A0 *base;
    s16 count = 0;
    s16 i;
    s32 *sp;
    s32 value;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    {
        u32 flags = (*(struct S8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_140;
        s32 ready;

        if ((flags & 0x80000000) != 0 &&
            (flags & 0x40000000) == 0 &&
            ((*(struct S8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 8) == 0) {
            ready = 1;
        } else {
            if (fn_1_4C10() != 0) {
                ready = 1;
            } else {
                ready = 0;
            }
        }

        if (ready != 0) {
            return;
        }
    }

    sp = &lbl_10_bss_14;
    if (*sp != -1) {
        value = *sp;
        *sp = -1;
        lbl_1_bss_96A = value;
        return;
    }

    rows.p = &(*(struct fn_10_73AC_S9C8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9C8))[0];
    base = &(*(struct S8B3A0 *)&lbl_1_bss_8B3A0.unk_0);
    for (i = 0; i < 4;
         rows.p = (struct fn_10_73AC_S9C8 *)((u8 *)rows.p + 0xC), i++) {
        if (rows.p->fA == -1) {
            continue;
        }

        if (__rlwnm(base->unk_98, (i + 1) & 31, 31, 31) == 0) {
            continue;
        }

        if ((((*(struct fn_10_73AC_S9F8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9F8))[base->unk_9E].f8 >> 12) & 1) != 0) {
            count++;
        }

        if ((((*(struct fn_10_73AC_S9F8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9F8))[base->unk_9E].f8 >> 12) & 1) != 0) {
            fn_1_12F150(i, 2, 1);
        }
    }

    if (count == 0 && fn_1_12F228() == 0) {
        return;
    }

    fn_10_CF30(0);
    lbl_10_bss_14 = 27;
    fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
}
/* fzgx:end fn_10_73AC */

/* fzgx:begin fn_10_757C */
void fn_10_757C(void) {
    if ((lbl_10_bss_51740) != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = (-1);
    }
}
/* fzgx:end fn_10_757C */

/* fzgx:begin fn_10_75D4 */
/* one 0x20-byte player record of lbl_1_bss_8B3A0; globals.h types the object as one struct */

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

/* the retail TU's .data objects this function uses, at their retail offsets */

static inline s32 fn_10_75D4_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

static inline void fn_10_75D4_slots(void) {
    s16 i;

    for (i = 0; i < 3; i++) {
        (*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0)[8].unk_81A4[i].unk_0 = fn_1_14F270(fn_1_128B00(i), i, 1U << 31);
    }
    (*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0)[8].unk_81A0 = fn_1_128B00(i);
}

static inline void fn_10_75D4_fill(s16 row, s16 first) {
    s16 i;

    for (i = 0; i < 1; i++) {
        (*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0)[8].unk_81A4[row].unk_4[i] =
            fn_1_151BE8((*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0)[8].unk_81A4[row].unk_0, first + i);
    }
}

void fn_10_75D4(void) {
    SelState *gs;
    s16 shift;
    u8 index;
    s16 player;
    u32 mask;
    fn_10_75D4_Player *players;
    s16 j;
    s16 i;
    s16 k;
    s16 n;

    gs = &lbl_1_bss_8B3A0;
    shift = fn_10_75D4_rand() & 3;
    index = gs->unk_9E;
    lbl_10_bss_555FC = 1;
    if (!(gs->unk_94 & 0x40000000)) {
        (*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0)[8].unk_0 &= 0x3FFFFFFF;
    } else if (!((*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0)[8].unk_0 & (1U << 31)) ||
               !((*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0)[8].unk_0 & 0x40000000)) {
        (*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0)[8].unk_0 |= (1U << 31) | (1U << 30);
        (*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0)[8].unk_5 = 0x31;
        fn_10_75D4_slots();
        for (k = 0; k < 3; k++) {
            fn_10_75D4_fill(k, 0);
        }
    }
    if (gs->unk_94 & 0x40000000) {
        for (j = 0; j < 3; j++) {
            for (n = 0; n < 1; n++) {
                (*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0)[8].unk_81A4[j].unk_4[n] =
                    fn_1_151BE8((*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0)[8].unk_81A4[j].unk_0, (s16)(shift + n));
            }
        }
        fn_1_12F10C((*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0));
    }
    if (lbl_1_bss_6D82C == 0) {
        fn_1_12AB38("vehicle/");
        lbl_1_bss_6D82C = fn_1_D3884("carcmntex.tpl");
        fn_1_12AB38("..");
    }
    fn_10_948C(lbl_10_bss_493A0, 0);
    player = index;
    players = (fn_10_75D4_Player *)&lbl_1_bss_8B3A0;
    players[player].unk_E = 0x31;
    if (!(gs->unk_94 & (1U << 31))) {
        fn_1_12BF7C(lbl_10_bss_517EC, 1, fn_1_A5D88(), 0x1E0);
        fn_1_12BF7C((*(u8 (*)[0x200])&lbl_10_bss_5197C), 1, fn_1_A5D88(), 0x1E0);
    }
    if (!(gs->unk_94 & (1U << 31))) {
        const char *names[1] = {"SEL_WAIT"};

        switch (shift) {
        case 0:
            mask = 1U << 31;
            break;
        case 1:
            mask = 0x40000000;
            break;
        case 2:
            mask = 0x20000000;
            break;
        case 3:
            mask = 0x10000000;
            break;
        default:
            mask = 1U << 31;
            break;
        }
        fn_1_8F198((*(u8 (*)[4][0x4E0])&lbl_10_bss_51B7C)[player], fn_1_12C930((*(fn_10_75D4_Entry (*)[9])&lbl_10_bss_3C0)[8].unk_81A0),
                   1U << 31, mask);
        for (i = 0; i < (s16)fn_1_12CB04(0x31); i++) {
            fn_1_8F198((*(u8 (*)[4][2][0x4E0])&lbl_10_bss_52EFC)[player][i], fn_1_12CCB0(0x31, i), 1U << 31, mask);
        }
        fn_1_12E0B8(index, 0x31, (*(u8 (*)[4][0x4E0])&lbl_10_bss_51B7C)[player], (*(u8 (*)[4][2][0x4E0])&lbl_10_bss_52EFC)[player], 0,
                    names, 1);
    }
    fn_1_435C(lbl_10_bss_49388);
    lbl_10_bss_51740 = fn_1_3F8C("SelMagCardDataDisp", fn_10_1AD5C, 0, 8);
    if (lbl_10_bss_555FC == 1) {
        fn_1_12F1E8(0x1E0);
    } else {
        fn_1_12F1E8(0xF0);
    }
    fn_1_4A00(1, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    lbl_10_bss_14 = (-1);
    fn_1_A2D84(0xA9100100);
    gs->unk_94 |= 0x800;
    lbl_1_bss_8B3A0.unk_129 = 1;
}
/* fzgx:end fn_10_75D4 */

/* fzgx:begin fn_10_7A10 */
#include "game/pad.h"
/* globals.h has no field at lbl_1_bss_8B3A0+0x98 (padding there); retail reads it as a word */

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

static inline u16 fn_10_7A10_input(s16 port) {
    return ((SelInput *)((u8 *)&lbl_1_bss_9F8 + port * 0x14))->unk_8;
}

static inline s32 fn_10_7A10_busy(void) {
    u32 flags = lbl_1_bss_8B3A0.unk_140;

    if ((flags & (1U << 31)) && !(flags & 0x40000000) && !(lbl_1_bss_8B3A0.unk_94 & 8)) {
        return 1;
    }
    if (fn_1_4C10() != 0) {
        return 1;
    }
    return 0;
}

void fn_10_7A10(void) {
    s16 count;
    s16 index;
    s32 done;
    s16 row;
    SelState *gs;
    s16 player;
    s16 i;
    s16 j;
    s16 k;
    s16 n;

    index = lbl_1_bss_8B3A0.unk_9E;
    count = 0;
    row = fn_10_C258( (fn_10_C258_SelContext *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
    done = 0;
    if (lbl_801A66C0 == 0x78) {
        fn_1_A2D84(0xA9122000);
    }
    gs = &lbl_1_bss_8B3A0;
    if (!(gs->unk_94 & (1U << 31))) {
        player = index;
        fn_1_8F62C((*(u8 (*)[4][0x4E0])&lbl_10_bss_51B7C)[player]);
        for (i = 0; i < (s16)fn_1_12CB04(lbl_1_bss_8B3A0.players[player].car);
             i++) {
            fn_1_8F62C((*(u8 (*)[4][2][0x4E0])&lbl_10_bss_52EFC)[player][i]);
        }
    }
    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }
    if (fn_10_7A10_busy()) {
        return;
    }
    if (((s32)lbl_10_bss_14) != -1) {
        s32 v = lbl_10_bss_14;

        lbl_10_bss_14 = (-1);
        lbl_1_bss_96A = v;
        return;
    }
    if (lbl_10_bss_555FC == 1) {
        switch (row) {
        case 0:
            for (j = 0; j < 4; j++) {
                if ((*(fn_10_7A10_Pad (*)[4])&lbl_1_bss_9C8)[j].unk_a == -1) {
                    continue;
                }
                if (__rlwnm(((fn_10_7A10_State *)&lbl_1_bss_8B3A0)->unk_98, (j + 1) & 31, 31, 31) == 0) {
                    continue;
                }
                if (PAD_BIT(fn_10_7A10_input(index), 8)) {
                    count++;
                }
                if (PAD_BIT(fn_10_7A10_input(index), 8)) {
                    fn_1_12F150(j, 0, 1);
                }
            }
            if (count != 0 || (0x1E0 - (fn_1_12F258())) > 0xF0 || fn_1_12F228() != 0) {
                fn_10_C274( (fn_10_C274_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                fn_1_12F150(index, 0, 1);
            }
            break;
        case 1:
            for (k = 0; k < 4; k++) {
                if ((*(fn_10_7A10_Pad (*)[4])&lbl_1_bss_9C8)[k].unk_a == -1) {
                    continue;
                }
                if (__rlwnm(((fn_10_7A10_State *)&lbl_1_bss_8B3A0)->unk_98, (k + 1) & 31, 31, 31) == 0) {
                    continue;
                }
                if (PAD_BIT(fn_10_7A10_input(index), 8)) {
                    count++;
                }
                if (PAD_BIT(fn_10_7A10_input(index), 8)) {
                    fn_1_12F150(k, 0, 1);
                    fn_1_12F17C();
                }
            }
            if (count != 0 || fn_1_12F228() != 0) {
                fn_10_C274( (fn_10_C274_SelObject *)&lbl_1_bss_8B3A0, lbl_1_bss_962);
                done = 1;
            }
            break;
        }
    } else {
        for (n = 0; n < 4; n++) {
            if ((*(fn_10_7A10_Pad (*)[4])&lbl_1_bss_9C8)[n].unk_a == -1) {
                continue;
            }
            if (__rlwnm(((fn_10_7A10_State *)&lbl_1_bss_8B3A0)->unk_98, (n + 1) & 31, 31, 31) == 0) {
                continue;
            }
            if (PAD_BIT(fn_10_7A10_input(index), 8)) {
                count++;
            }
            if (PAD_BIT(fn_10_7A10_input(index), 8)) {
                fn_1_12F150(n, 0, 1);
                fn_1_12F17C();
            }
        }
        if (count != 0 || fn_1_12F228() != 0) {
            done = 1;
        }
    }
    if (done == 1) {
        lbl_10_bss_14 = ((gs->unk_94 & 0x2000) ? 0x15 : 0xE);
        fn_1_12F1E8(0);
        fn_1_4A00(0, lbl_10_bss_4938C, (lbl_10_bss_49388));
        lbl_10_bss_51744 = 0;
        lbl_1_bss_6EAB4 |= 0x24;
        lbl_1_bss_8B3A0.unk_129 = 0;
    }
}
/* fzgx:end fn_10_7A10 */

/* fzgx:begin fn_10_7E84 */
#pragma opt_lifetimes off

void fn_10_7E84(void) {
    u8 *state;
    s16 index;
    u32 flags;
    u8 *rec;
    u8 *call_ptr;
    u8 *ptr;
    s32 i;
    u8 *base;
    s16 count;

    base = (*(u8 (*)[])&(*((Obj_10_bss_0 *)&lbl_10_bss_0))) + 0x50000;
    state = (*(u8 (*)[])&lbl_1_bss_8B3A0.unk_0);
    index = ((state)[0x9e]);
    flags = *(u32 *)(state + 0x94);
    rec = state + (index << 5);
    count = *(s16 *)(rec + 0xe);
    rec = (u8 *)(rec + 0xe);

    if ((flags & (1u << 31)) == 0) {
        call_ptr = base + 0x1b7c;
        call_ptr += index * 0x4e0;
        fn_1_8F494(call_ptr);
        ptr = base + 0x2efc;
        ptr += index * 0x9c0;
        i = 0;
        while ((s16)i < (s16)fn_1_12CB04(count)) {
            fn_1_8F494(ptr);
            ptr += 0x4e0;
            i++;
        }
    }

    flags = *(u32 *)(state + 0x94);
    if ((flags & (1u << 31)) == 0) {
        fn_1_12C000(base + 0x17ec, 1);
        fn_1_12C000(base + 0x197c, 1);
    }

    if (*(s32 *)(base + 0x1740) != -1) {
        fn_1_435C(*(u32 *)(base - 0x6c78));
        fn_1_426C(*(s32 *)(base + 0x1740));
        *(s32 *)(base + 0x1740) = -1;
    }

    fn_10_96F8(base - 0x6c60, (0));
    if (*(void **)(*(u8 (*)[])&lbl_1_bss_6D82C) != 0) {
        fn_80071718(*(void **)(*(u8 (*)[])&lbl_1_bss_6D82C));
        *(u32 **)(*(u8 (*)[])&lbl_1_bss_6D82C) = 0;
    }

    *(s16 *)rec = -1;
    flags = *(u32 *)(state + 0x94);
    *(u32 *)(state + 0x94) = flags & 0xfffff7ff;
}

#pragma opt_lifetimes reset
/* fzgx:end fn_10_7E84 */

/* fzgx:begin fn_10_7FC0 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_7FC0(void) {
    fn_1_435C( (lbl_10_bss_49388));
    lbl_10_bss_51740 = (fn_1_3F8C( ((*(char (*)[18])&"SelMagCardBuyDisp")), fn_10_1B65C, (0), 8));
    fn_1_12F1E8(480);
    fn_1_4A00(1, lbl_10_bss_4938C, (lbl_10_bss_49388));
    lbl_10_bss_51744 = 0;
    lbl_10_bss_14 = (-1);
}
/* fzgx:end fn_10_7FC0 */

/* fzgx:begin fn_10_804C */
void fn_10_804C(void) {
    u32 flags;
    s32 ready;
    volatile u16 *buttons;  /* fzgx-allow: S2 controller flags are sampled independently for each test (as main) */
    s16 j;
    s16 i;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }
    flags = lbl_1_bss_8B3A0.unk_140;
    if ((flags & 0x80000000) != 0 && (flags & 0x40000000) == 0 && (lbl_1_bss_8B3A0.unk_94 & 8) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }
    if (ready != 0) {
        return;
    }
    if (lbl_10_bss_14 != -1) {
        lbl_1_bss_96A = lbl_10_bss_14;
        lbl_10_bss_14 = -1;
        return;
    }
    for (i = 0; i < 4; i++) {
        if (lbl_1_bss_9C8[i].unk_a != -1 && __rlwnm(lbl_1_bss_8B3A0.unk_98, (i + 1) & 31, 31, 31) &&
            ((lbl_1_bss_9F8[lbl_1_bss_8B3A0.unk_9E].unk_8 >> 8) & 1)) {
            fn_1_12F150(i, 2, 1);
        }
    }
    buttons = &lbl_1_bss_9F8[0].unk_8;
    if ((*(volatile u16 *)((u8 *)buttons + lbl_1_bss_8B3A0.unk_9E * 20) >> 8) & 1) {  /* fzgx-allow: S2 see buttons */
        fn_1_12F1E8(0);
    }
    for (j = 0; j < 4; j++) {
        if (lbl_1_bss_9C8[j].unk_a != -1 && __rlwnm(lbl_1_bss_8B3A0.unk_98, (j + 1) & 31, 31, 31) &&
            ((lbl_1_bss_9F8[lbl_1_bss_8B3A0.unk_9E].unk_8 >> 12) & 1)) {
            fn_1_12F150(j, 2, 1);
        }
    }
    if (((*(volatile u16 *)((u8 *)buttons + lbl_1_bss_8B3A0.unk_9E * 20) >> 12) & 1) || fn_1_12F228() != 0) {  /* fzgx-allow: S2 see buttons */
        lbl_10_bss_14 = 24;
        fn_1_12F1E8(0);
        fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        if (lbl_10_bss_14 == 14) {
            lbl_1_bss_6EAB4 |= 36;
        }
    }
}
/* fzgx:end fn_10_804C */

/* fzgx:begin fn_10_82BC */
void fn_10_82BC(void) {
    s32 state = lbl_10_bss_51740;

    if (state != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
}
/* fzgx:end fn_10_82BC */

/* fzgx:begin fn_10_8314 */
void fn_10_8314(void) {
    fn_1_435C(lbl_10_bss_49388);
    lbl_10_bss_51740 = fn_1_3F8C("SelMagNameInputDisp", fn_10_1B664, 0, 8);
    fn_1_12F1E8(3600);
    fn_1_4A00(1, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    lbl_10_bss_14 = -1;
    lbl_1_bss_8B3A0.unk_129 = 1;
    fn_10_25610(lbl_10_bss_49384, lbl_10_bss_49388, lbl_1_bss_8B3A0.unk_9E);
}
/* fzgx:end fn_10_8314 */

/* fzgx:begin fn_10_83C0 */
void fn_10_83C0(void) {
    s32 ready;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    if (((*(fn_10_83C0_SelState *)&lbl_1_bss_8B3A0.unk_0).field_140 & ((u32)1 << 31)) != 0 &&
        ((*(fn_10_83C0_SelState *)&lbl_1_bss_8B3A0.unk_0).field_140 & 0x40000000) == 0 &&
        ((*(fn_10_83C0_SelState *)&lbl_1_bss_8B3A0.unk_0).flags_94 & 0x8) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready == 0) {
        if ((lbl_10_bss_14) != -1) {
            s32 state = lbl_10_bss_14;
            lbl_10_bss_14 = -1;
            lbl_1_bss_96A = state;
        } else {
            if (fn_1_12F228() != 0) {
                fn_1_12F1E8(0);
                fn_10_25CB0();
            }
            if (fn_10_25888() != 0) {
                (*(fn_10_83C0_SelState *)&lbl_1_bss_8B3A0.unk_0).field_129 = 0;
                fn_1_12F1E8(0);
                fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
                lbl_10_bss_51744 = 0;
                lbl_10_bss_14 = 0x19;
            }
        }
    }
}
/* fzgx:end fn_10_83C0 */

/* fzgx:begin fn_10_84DC */
void fn_10_84DC(void) {
    fn_10_25BC8();
    if ((lbl_10_bss_51740) != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = ((u32)-1);
    }
}
/* fzgx:end fn_10_84DC */

/* fzgx:begin fn_10_8538 */
void fn_10_8538(void) {
    fn_1_435C(lbl_10_bss_49388);
    lbl_10_bss_51740 = fn_1_3F8C("SelChallengerStandbyDisp", fn_10_1B684, 0, 8);
    fn_1_4A00(1, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    fn_1_12F1E8(900);
    lbl_1_bss_8B3A0.unk_A4->unk_19 = 0;
    lbl_10_bss_14 = -1;
    fn_1_A176C(lbl_1_bss_6EAD0->a, 0x1F);
    lbl_10_bss_55600 = 180;
    lbl_10_bss_55601 = 0;
}
/* fzgx:end fn_10_8538 */

/* fzgx:begin fn_10_8600 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_8600(void) {
    u8 result;
    s32 ready;
    u8 *obj;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    if (((*((GlobalSel *)&lbl_1_bss_8B3A0)).flags140 & 0x80000000) != 0 &&
        ((*((GlobalSel *)&lbl_1_bss_8B3A0)).flags140 & 0x40000000) == 0 &&
        ((*((GlobalSel *)&lbl_1_bss_8B3A0)).flags94 & 8) == 0) {
        ready = 1;
    } else {
        if (fn_1_4C10() != 0) {
            ready = 1;
        } else {
            ready = 0;
        }
    }

    if (ready == 0) {
        if (((s32)lbl_10_bss_14) != -1) {
            s16 value = lbl_10_bss_14;
            lbl_10_bss_14 = (-1);
            lbl_1_bss_96A = value;
        } else {
            result = fn_1_D6688();
            if (result != 0 || lbl_10_bss_55600 < 0xb4) {
                if (lbl_10_bss_55600 != 0) {
                    lbl_10_bss_55600--;
                }
            }
            if (fn_1_12F258() == 0x12c) {
                fn_1_A2D84(0xA9122100u);
            }
            if (fn_1_12F228() != 0) {
                lbl_10_bss_55601 = 1;
                obj = (*((GlobalSel *)&lbl_1_bss_8B3A0)).object;
                obj[0x19] = 1;
                if (result == 0) {
                    if (lbl_10_bss_55600 != 0) {
                        return;
                    }
                }
                if (fn_10_8780() != 0) {
                    lbl_10_bss_14 = (0xf);
                    fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
                    lbl_10_bss_51744 = 0;
                    lbl_1_bss_6EAB4 |= 0x24;
                }
            }
        }
    }
}
/* fzgx:end fn_10_8600 */

/* fzgx:begin fn_10_8780 */
u8 fn_10_8780(void) {
    if (fn_1_4C10() != 0) {
        return 1;
    }
    if (lbl_10_bss_55601 == 0) {
        return 0;
    }
    if (fn_1_D66A8() == 0) {
        if (fn_1_D66A0(0x10) == 0) {
            /* Retail converges both failure paths here. */
            goto fail;
        }
    }
    if (lbl_10_bss_55600 == 0) {
        /* Retail places the success block after the failure block. */
        goto success;
    }
fail:
    return 0;
success:
    return 1;
}
/* fzgx:end fn_10_8780 */

/* fzgx:begin fn_10_8800 */
void fn_10_8800(void) {
    if ((lbl_10_bss_51740) != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    fn_1_A176C( (void *)(*((u32 *)lbl_1_bss_6EAD0)), 0x2d);
}
/* fzgx:end fn_10_8800 */

/* fzgx:begin fn_10_8870 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_8870(void) {
    s32 lab_t0;

    fn_1_435C(lbl_10_bss_49388);
    lbl_10_bss_51740 = fn_1_3F8C("SelChallengerWaitDisp", fn_10_1B6A8, 0, 8);
    fn_1_4A00(1, lbl_10_bss_4938C, (lbl_10_bss_49388));
    lbl_10_bss_51744 = (0);
    lab_t0 = 0x384;
    fn_1_12F1E8(lab_t0);
    ((*(SelCtl *)&lbl_1_bss_8B3A0.unk_0).unk_a4)[0x19] = 0;
    lbl_10_bss_14 = (-1);
    fn_1_A176C( (Sig_ADXT_Stop_ADXTHandle *)(*(*(Sig_ADXT_Stop_ADXTHandle ** *)((u32 * *)&lbl_1_bss_6EAD0))), 0x1f);
    fn_1_47F74(2);
}
/* fzgx:end fn_10_8870 */

/* fzgx:begin fn_10_8930 */
void fn_10_8930(void) {
    s32 ready;
    u32 flags;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    flags = lbl_1_bss_8B3A0.unk_140;
    if ((flags & 0x80000000) != 0 && (flags & 0x40000000) == 0 && (lbl_1_bss_8B3A0.unk_94 & 8) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready != 0) {
        return;
    }

    if (lbl_10_bss_14 != -1) {
        lbl_1_bss_96A = lbl_10_bss_14;
        lbl_10_bss_14 = -1;
        return;
    }

    if ((lbl_1_bss_9F8[lbl_1_bss_8B3A0.unk_9E].unk_8 >> 12) & 1) {
        lbl_1_bss_8B3A0.unk_0 = 9;
        fn_10_BD64(&lbl_1_bss_8B3A0);
        lbl_10_bss_14 = 26;
        fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        if (lbl_10_bss_14 != 21) {
            lbl_1_bss_6EAB4 |= 0x24;
        }
    } else if (fn_1_12F228() != 0 && fn_1_D66A0(13) == 0 && fn_1_D66A0(15) == 0) {
        lbl_1_bss_8B3A0.unk_94 |= 0x4000000;
    }
}
/* fzgx:end fn_10_8930 */

/* fzgx:begin fn_10_8AAC */
void fn_10_8AAC(void) {
    fn_1_48140(2);
    if ((lbl_10_bss_51740) != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
}
/* fzgx:end fn_10_8AAC */

/* fzgx:begin fn_10_8B0C */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_8B0C(void) {
    fn_1_435C(lbl_10_bss_49388);
    lbl_10_bss_51740 = (fn_1_3F8C("SelCautionDisp", fn_10_1B2F4, 0, 8));
    fn_1_4A00(1, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    lbl_10_bss_14 = (-1);
    fn_1_12F1E8(0x1e0);
    (*(fn_10_8B0C_SelGlobal *)&lbl_1_bss_8B3A0.unk_0).flags |= 0x800;
    fn_1_A2D84(0xa9121500);
}
/* fzgx:end fn_10_8B0C */

/* fzgx:begin fn_10_8BB8 */
#pragma opt_common_subs off


#pragma opt_dead_assignments off

void fn_10_8BB8(void) {
    struct fn_10_8BB8_lbl_1_bss_8B3A0 * p_lbl_1_bss_8B3A0;
    u8 * p_lbl_1_bss_9C8;
    u32 v0;
    int v1;
    s16 v3;
    s16 v4 = 0;
    struct S14 *p14;

    if ((s32)(*(struct S14 *)(&lbl_10_bss_14)).f == -1) {
        fn_1_4C10();
    }
    v0 = (*(struct fn_10_8BB8_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_140;
    if ((v0 & 0x80000000) != 0 && (v0 & 0x40000000) == 0 &&
        ((*(struct fn_10_8BB8_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 8) == 0) {
        v1 = 1;
    } else {
        if (fn_1_4C10() != 0) v1 = 1;
        else v1 = 0;
    }
    if (v1 != 0) return;
    p14 = &(*(struct S14 *)(&lbl_10_bss_14));
    if ((s32)p14->f != -1) {
        lbl_1_bss_96A = p14->f;
        p14->f = -1;
        return;
    }
    {
    s16 fzgx_loop_v3_1334;
    p_lbl_1_bss_9C8 = (u8 *)&(*(u8 (*)[])&lbl_1_bss_9C8);
    p_lbl_1_bss_8B3A0 = &(*(struct fn_10_8BB8_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0);
    fzgx_loop_v3_1334 = 0;
    while (fzgx_loop_v3_1334 < 4) {
        if ((s8)p_lbl_1_bss_9C8[fzgx_loop_v3_1334 * 12 + 10] != -1 &&
            __rlwnm(p_lbl_1_bss_8B3A0->unk_98, (fzgx_loop_v3_1334 + 1) & 31, 31, 31) != 0) {
            if (((((struct fn_10_8BB8_S9F8 *)((*(struct fn_10_8BB8_S9F8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9F8))))[p_lbl_1_bss_8B3A0->unk_9E].f8 >> 8) & 1) != 0)
                v4 = (v4 + 1);
                (void) v4;  /* fzgx: keeps the web at its definition */
            if (((((struct fn_10_8BB8_S9F8 *)((*(struct fn_10_8BB8_S9F8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9F8))))[p_lbl_1_bss_8B3A0->unk_9E].f8 >> 8) & 1) != 0)
                fn_1_12F150(fzgx_loop_v3_1334, 2, 1);
        }
        fzgx_loop_v3_1334++;
    }
    v3 = fzgx_loop_v3_1334;
    }
    if ((v4 != 0 && fn_1_12F258() < 300) || fn_1_12F228() != 0) {
        fn_1_12F1E8(0);
        fn_1_4A00(0, lbl_10_bss_4938C, (lbl_10_bss_49388));
        lbl_10_bss_51744 = 0;
        (*(struct S14 *)(&lbl_10_bss_14)).f = 31;
    }
}

#pragma opt_dead_assignments reset
#pragma opt_common_subs reset
/* fzgx:end fn_10_8BB8 */

/* fzgx:begin fn_10_8D90 */
void fn_10_8D90(void) {
    if ((lbl_10_bss_51740) != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    (*(fn_10_8D90_SelGlobal *)&lbl_1_bss_8B3A0.unk_0).flags &= ~0x00000800;
}
/* fzgx:end fn_10_8D90 */

/* fzgx:begin fn_10_8DFC */
s32 lbl_10_data_7B0 = -1;

void fn_10_8DFC(void) {
    fn_1_435C(lbl_10_bss_49388);
    lbl_10_bss_51740 = fn_1_3F8C("SelCardAllDisp", fn_10_1E41C, NULL, 8);
    fn_1_4A00(1, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    lbl_10_bss_14 = -1;
    fn_1_12F1E8(900);
    lbl_1_bss_8B3A0.unk_A4->unk_16 = 0;
    lbl_1_bss_8B3A0.unk_A4->unk_17 = 0;
    if (lbl_1_bss_7180C != 0) {
        fn_1_B7F24();
        fn_1_435C(lbl_10_bss_49384);
        lbl_10_data_7B0 = fn_1_3F8C("memcard_load_calc", fn_10_C6A4, &lbl_10_bss_55604, 8);
    }
    fn_1_A176C(lbl_1_bss_6EAD0->a, 3);
    lbl_1_bss_8B3A0.unk_A4->unk_20 = 0x4F;
}
/* fzgx:end fn_10_8DFC */

/* fzgx:begin fn_10_8F0C */
#pragma opt_dead_assignments off

#pragma opt_common_subs off

void fn_10_8F0C(void) {
    u32 fzgx_condition_1630;
    fn_10_8F0C_SelState *st;
    SelSlot *slot;
    fn_10_8F0C_SelState *g;
    fn_10_8F0C_SelState *h;
    u16 *val;
    s32 ready;
    s16 count = 0;
    s16 i;
    u8 flag;

    *(u16 *)&(*((U16Box *)&lbl_1_bss_96A)) = 14;
    st = &(*((fn_10_8F0C_SelState *)&lbl_1_bss_8B3A0));
    if ((st->unk_A4)->unk_20 != 0) {
        val = &st->unk_A4->unk_20;
        *val = (st->unk_A4)->unk_20 - 1;
        if ((st->unk_A4)->unk_20 == 0) {
            fn_1_A2D84(0xA9121E00);
        }
    }
    if ((lbl_10_bss_14) == -1) {
        fn_1_4C10();
    }
    if (((fzgx_condition_1630 = (*((fn_10_8F0C_SelState *)&lbl_1_bss_8B3A0)).unk_140) & 0x80000000) != 0 &&
        (fzgx_condition_1630 & 0x40000000) == 0 &&
        ((*((fn_10_8F0C_SelState *)&lbl_1_bss_8B3A0)).unk_94 & 0x8) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }
    if (ready == 0) {
        if ((lbl_10_bss_14) != -1) {
            s32 value = lbl_10_bss_14;
            lbl_10_bss_14 = (-1);
            (*((U16Box *)&lbl_1_bss_96A)).unk_0 = value;
        } else {
            slot = (*(SelSlot (*)[])&lbl_1_bss_9C8);
            g = &(*((fn_10_8F0C_SelState *)&lbl_1_bss_8B3A0));
            h = &(*((fn_10_8F0C_SelState *)&lbl_1_bss_8B3A0));
            for (i = 0; i < 4; i++) {
                if (((i)[slot]).unk_A != -1) {
                    if (__rlwnm(g->unk_98, ((i + 1) & 31), 31, 31) != 0) {
                        if (((((g->unk_9E)[(*(Sel9F8 (*)[])&lbl_1_bss_9F8)]).unk_8 >> 12) & 1) != 0) {
                            count++;
                        }
                        if (((((h->unk_9E)[(*(Sel9F8 (*)[])&lbl_1_bss_9F8)]).unk_8 >> 12) & 1) != 0) {
                            fn_1_12F150(i, 0, 1);
                        }
                    }
                }
            }
            if (count != 0 || fn_1_12F228() != 0) {
                (st->unk_A4)->unk_16 = 1;
                fn_1_12F1E8(0);
            }
            if (count != 0 || fn_1_12F228() != 0) {
                fn_1_12F1E8(0);
                flag = (st->unk_A4)->unk_17;
                lbl_10_bss_14 = (0x19 + ((-flag | flag) >> 31));
                fn_1_4A00(0, lbl_10_bss_4938C, (lbl_10_bss_49388));
                lbl_10_bss_51744 = 0;
            }
        }
    }
}

#pragma opt_common_subs reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_10_8F0C */

/* fzgx:begin fn_10_9154 */
void fn_10_9154(void) {
    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    if (lbl_10_data_7B0 != -1) {
        fn_1_435C(lbl_10_bss_49384);
        fn_1_426C(lbl_10_data_7B0);
        lbl_10_data_7B0 = -1;
    }
}
/* fzgx:end fn_10_9154 */

/* fzgx:begin fn_10_91E8 */
int fn_10_91E8(void) {
    int count = 0;
    u32 value;
    s16 i = 0;

    while (i < 4) {
        value = (*(u32 (*)[])&lbl_1_bss_980)[i];

        if (value == 0x09000000 ||
            value == 0x88000000 ||
            value == 0x8B100000 ||
            value == 0x08000000) {
            count++;
        }
        i++;
    }

    return count;
}
/* fzgx:end fn_10_91E8 */

/* fzgx:begin fn_10_924C */
void fn_10_924C(u8 *arg0) {
    s16 i;

    if (*(u32 *)((u8 *)(*(u32 (*)[])&lbl_1_bss_8B3A0) + 0x94) & 0x2000000u) {
        if (lbl_10_data_564[0] == -1) {
            char out[0x20];
            u8 str[0x20];
            u32 buf[8];
            u32 one = 1;

            fn_80008BEC(buf, 0, 0x20);
            i = lbl_10_data_45A;
            ((s16 *)buf)[1] = 6;
            ((u8 *)buf)[8] = (one << i);
            (buf)[1] = one << lbl_10_data_458;
            sprintf(out, "vehicle/%s_e.arc.lz", fn_1_7F518(6, str, 0));
            lbl_10_data_564[0] = fn_1_12A32C(out);
            if (lbl_1_bss_6D82C == 0) {
                fn_1_12AB38("vehicle/");
                lbl_1_bss_6D82C = fn_1_D3884("carcmntex.tpl");
                fn_1_12AB38("..");
            }
            fn_1_12A2B8(1);
            fn_1_12AB38("vehicle/");
            fn_1_80270(buf, arg0 + 0x1980);
            fn_1_12AB38("..");
            fn_1_12A2B8(0);
            *(u32 *)(((0x1ca4) + (arg0))) = lbl_10_data_564[0];
        }
    } else if (lbl_10_data_564[0] == -1) {
        SelEnt entries[41];
        i = 0;
        {
            SelEnt *p = entries;
            u32 zero = i;
            u32 one = 1;

            while (i < 41) {
                fn_1_80058(i, (u8 *)p);
                p->f0 = i;
                i++;
                p->f8 = zero;
                p->f8 = p->f8 | (one << lbl_10_data_45A);
                p->f4 = one << lbl_10_data_458;
                p++;
            }
            lbl_10_data_564[0] = fn_1_12A32C("vehicle/vehicle_sel.arc.lz");
            fn_1_12A2B8(1);
            fn_1_80C18(arg0, (u8 *)entries, 41);
            fn_1_12A2B8(0);
            for (i = 0; i < 33; i += 8) {
                ((fn_10_924C_SelCell *)arg0 + i)->f324 = lbl_10_data_564[0];
                ((fn_10_924C_SelCell *)arg0 + i + 1)->f324 = lbl_10_data_564[0];
                ((fn_10_924C_SelCell *)arg0 + i + 2)->f324 = lbl_10_data_564[0];
                ((fn_10_924C_SelCell *)arg0 + i + 3)->f324 = lbl_10_data_564[0];
                ((fn_10_924C_SelCell *)arg0 + i + 4)->f324 = lbl_10_data_564[0];
                ((fn_10_924C_SelCell *)arg0 + i + 5)->f324 = lbl_10_data_564[0];
                ((fn_10_924C_SelCell *)arg0 + i + 6)->f324 = lbl_10_data_564[0];
                ((fn_10_924C_SelCell *)arg0 + i + 7)->f324 = lbl_10_data_564[0];
            }
            for (; i < 41; i++) {
                ((fn_10_924C_SelCell *)arg0 + i)->f324 = lbl_10_data_564[0];
            }
        }
    }
}
/* fzgx:end fn_10_924C */

/* fzgx:begin fn_10_948C */
void fn_10_948C(void *context, void *arg) {
    fn_10_948C_SelEntry *entry;
    s16 i;
    u32 one;

    if (*(u32 *)((u8 *)(*(u32 (*)[])&lbl_1_bss_8B3A0.unk_0) + 0x94) & ((u32)1 << 31)) {
        return;
    }

    i = 0;
    one = 1;
    while (i < 9U) {
        entry = &(*(fn_10_948C_SelEntry (*)[])&(*((Obj_10_bss_3C0 *)&lbl_10_bss_3C0)))[i];
        if ((entry->flags & ((u32)1 << 31)) &&
            (entry->flags & ((u32)1 << 30))) {
            fn_1_14DB48(entry, (u8 *)context + i * 0xa20, one << lbl_10_data_456);
        }
        i++;
    }

    if (arg != 0) {
        i = 0;
        one = 1;
        while (i < 4) {
            entry = &((fn_10_948C_SelEntry *)fn_1_36AD0())[i];
            if ((entry->flags & ((u32)1 << 31)) &&
                (entry->flags & ((u32)1 << 30))) {
                fn_1_14DB48(entry, (u8 *)arg + i * 0xa20, one << lbl_10_data_456);
            }
            i++;
        }
    }
}
/* fzgx:end fn_10_948C */

/* fzgx:begin fn_10_95A0 */
void fn_10_95A0(fn_10_95A0_SelBlock *data) {
    s16 i;
    fn_10_95A0_SelBlock *block;
    s32 value = (*(u32 (*)[])&lbl_10_data_564)[0];

    if (((*(fn_10_95A0_SelGlobal *)&lbl_1_bss_8B3A0.unk_0).flags & ((u32)1 << 31)) == 0) {
        if (value != -1) {
            fn_1_12A2B8(1);
            fn_1_12A2D0(value);
        } else {
            fn_1_12A2B8(0);
        }

        fn_1_12C5E4(data);
        fn_1_12A2B8(0);

        if ((*(void * *)&lbl_1_bss_6D82C) != 0) {
            fn_80071718((*(void * *)&lbl_1_bss_6D82C));
            (*(void * *)&lbl_1_bss_6D82C) = 0;
        }

        if (value != -1) {
            fn_1_12A734(value);
            (*(u32 (*)[])&lbl_10_data_564)[0] = -1;
        }

        block = data;
        i = 0;
        while (i < 0x21) {
            block->a = (*(u32 (*)[])&lbl_10_data_564)[0];
            block->b = (*(u32 (*)[])&lbl_10_data_564)[0];
            block->c = (*(u32 (*)[])&lbl_10_data_564)[0];
            block->d = (*(u32 (*)[])&lbl_10_data_564)[0];
            block->e = (*(u32 (*)[])&lbl_10_data_564)[0];
            block->f = (*(u32 (*)[])&lbl_10_data_564)[0];
            block->g = (*(u32 (*)[])&lbl_10_data_564)[0];
            block->h = (*(u32 (*)[])&lbl_10_data_564)[0];
            i += 8;
            block = (fn_10_95A0_SelBlock *)((u8 *)block + 0x2200);
        }

        block = (fn_10_95A0_SelBlock *)((u8 *)data + i * 0x440);
        while (i < 0x29) {
            block->a = (*(u32 (*)[])&lbl_10_data_564)[0];
            i++;
            block = (fn_10_95A0_SelBlock *)((u8 *)block + 0x440);
        }
    }
}
/* fzgx:end fn_10_95A0 */

/* fzgx:begin fn_10_96F8 */
void fn_10_96F8(void *first, void *second) {
    s16 i;
    u8 *ptr;

    ptr = first;
    for (i = 0; i < 9U; i++) {
        fn_1_14DBCC(ptr);
        ptr += 0xa20;
    }

    if (second != 0) {
        ptr = second;
        i = 0;
        for (; i < 4; i++) {
            fn_1_14DBCC(ptr);
            ptr += 0xa20;
        }
    }
}
/* fzgx:end fn_10_96F8 */

/* fzgx:begin fn_10_9788 */
static inline s16 countControllers(void) {
    s16 i;
    s16 count = 0;
    for (i = 0; i < 4; i++) {
        if ((*(u32 (*)[])&lbl_1_bss_980)[i] == 0x09000000 || (*(u32 (*)[])&lbl_1_bss_980)[i] == 0x88000000 ||
            (*(u32 (*)[])&lbl_1_bss_980)[i] == 0x8B100000 || (*(u32 (*)[])&lbl_1_bss_980)[i] == 0x08000000) count++;
    }
    return count;
}

void fn_10_9788(void *argInput) {
    u32 v0;
    s16 v1;
    u32 v3;
    static const struct NavigationTable nav = {{
        {-1, 4, 1, 2, -1, 3, -1, 7},
        {-1, 3, -1, 0, -1, -1, -1, 4},
        {-1, 7, 0, -1, -1, 4, -1, -1},
        {1, 5, -1, 4, -1, -1, 0, 6},
        {0, 6, 3, 7, 1, 5, 2, 8},
        {3, -1, -1, 6, -1, -1, 4, -1},
        {4, -1, 5, 8, 3, -1, 7, -1},
        {2, 8, 4, -1, 0, 6, -1, -1},
        {7, -1, 6, -1, 4, -1, -1, -1},
        {-1, -1, -1, 10, -1, -1, -1, -1},
        {-1, -1, 9, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1},
    }};
    struct NavigationTable loc_4;
    struct { u32 value; } v4;
    s16 movement;
    s16 i;
    s16 j;
    u8 *state;
    s16 direction;
    void *arg0 = argInput;

    v0 = *(u32 *)((u8 *)arg0 + 164);
    v1 = ((*((struct fn_10_9788_lbl_1_bss_962 *)&lbl_1_bss_962)).unk_0 - 14);
    v3 = v0 + v1 * 148;
    v4.value = *(s16 *)(v3 + 20) << 2;
    loc_4 = nav;

    for (i = 0; i < 4; i++) {
        direction = -1;
        if (((*(u32 (*)[])&lbl_1_bss_980)[i] == 0x09000000 || (*(u32 (*)[])&lbl_1_bss_980)[i] == 0x88000000 ||
             (*(u32 (*)[])&lbl_1_bss_980)[i] == 0x8B100000 || (*(u32 (*)[])&lbl_1_bss_980)[i] == 0x08000000) &&
            __rlwnm(*(u32 *)((*(u8 (*)[])&lbl_1_bss_8B3A0) + 0x98), (i + 1) & 31, 31, 31)) {
            if ((((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_10 >> 3) & 1) || (((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_12 >> 3) & 1)) direction = 0;
            if ((((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_10 >> 2) & 1) || (((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_12 >> 2) & 1)) direction = 1;
            if (((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_10 & 1) || ((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_12 & 1)) direction = 2;
            if ((((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_10 >> 1) & 1) || (((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_12 >> 1) & 1)) direction = 3;
            if ((((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_10 & 1) || ((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_12 & 1)) &&
                ((((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_10 >> 3) & 1) || (((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_12 >> 3) & 1))) direction = 4;
            if ((((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_10 & 1) || ((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_12 & 1)) &&
                ((((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_10 >> 2) & 1) || (((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_12 >> 2) & 1))) direction = 5;
            if (((((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_10 >> 1) & 1) || (((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_12 >> 1) & 1)) &&
                ((((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_10 >> 3) & 1) || (((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_12 >> 3) & 1))) direction = 6;
            if (((((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_10 >> 1) & 1) || (((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_12 >> 1) & 1)) &&
                ((((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_10 >> 2) & 1) || (((*(struct PadState (*)[])&lbl_1_bss_9F8)[i].unk_12 >> 2) & 1))) direction = 7;
            if (direction != -1) {
                s16 next = loc_4.entry[*(s16 *)(v3 + v4.value)][direction];
                if (next != -1) {
                    *(s16 *)(v3 + v4.value) = next;
                    fn_1_12F128(i);
                    fn_1_A2D84(0xA9010000);
                    lbl_801A66A8 = 0;
                }
            }
        }
    }
    movement = 0;
    for (j = 0; j < 4; j++) {
        if ((*(struct ControllerState (*)[])&lbl_1_bss_9C8)[j].unk_A != -1 &&
            __rlwnm(*(u32 *)((*(u8 (*)[])&lbl_1_bss_8B3A0) + 0x98), (j + 1) & 31, 31, 31)) {
            if (((*(struct PadState (*)[])&lbl_1_bss_9F8)[j].unk_8 >> 9) & 1) movement--;
            if ((((*(struct PadState (*)[])&lbl_1_bss_9F8)[j].unk_8 >> 8) & 1) || fn_1_12F228()) movement++;
            if ((((*(struct PadState (*)[])&lbl_1_bss_9F8)[j].unk_8 >> 8) & 1) || fn_1_12F228()) {
                fn_1_12F150(j, 1, 1);
            } else if (((*(struct PadState (*)[])&lbl_1_bss_9F8)[j].unk_8 >> 9) & 1) {
                fn_1_12F150(j, 1, 0);
            }
        }
    }
    state = (*(u8 (*)[])&lbl_1_bss_8B3A0);
    if (*(u32 *)(state + 0x94) & 0x200) {
        if (movement > 0) {
            *(s16 *)arg0 = *(s16 *)(v3 + v4.value);
            fn_1_A2D84(0xA9010100);
            switch (*(s16 *)arg0) {
            case 10: fn_1_A2D84(0xA9100300); break;
            case 9: fn_1_A2D84(0xA9100200); break;
            }
            fn_1_12F1E8(0);
        }
    } else if (movement > 0) {
        s16 value = *(s16 *)(v3 + v4.value);
        if (value != 0 || countControllers() >= 2) {
            *(s16 *)arg0 = value;
            fn_1_A2D84(0xA9010100);
            switch (*(s16 *)arg0) {
            case 10: fn_1_A2D84(0xA9100300); break;
            case 9: fn_1_A2D84(0xA9100200); break;
            }
            fn_1_12F1E8(0);
        }
    }
    if (movement < 0 &&
        ((*(u32 *)(state + 0x94) & 0x40000000) == 0 ||
         (*(u32 *)(state + 0x94) & 0x4000) != 0)) {
        fn_1_12F17C();
        *(u32 *)(state + 0x94) |= 0x04000000;
        fn_1_4BB0();
        fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        fn_1_A2D84(0xA9010200);
        lbl_1_bss_6EAB4 |= 0x24;
    }
    switch (*(s16 *)arg0) {
    case 3:
        lbl_10_bss_14 = 15;
        fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        break;
    case 4:
        *(u32 *)(state + 0x94) |= 0x08000000;
        *(u32 *)(state + 0x94) |= 0x00200000;
        fn_1_4A00(0, 60, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        lbl_1_bss_6EAB4 |= 0x2C;
        fn_1_A2A70(44, 60);
        break;
    case 6:
        *(u32 *)(state + 0x94) |= 0x08000000;
        *(u32 *)(state + 0x94) |= 0x00100000;
        fn_1_4A00(0, 60, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        lbl_1_bss_6EAB4 |= 0x2C;
        fn_1_A2A70(44, 60);
        break;
    case 5:
        *(u32 *)(state + 0x94) |= 0x08000000;
        *(u32 *)(state + 0x94) |= 0x00080000;
        fn_1_4A00(0, 60, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        lbl_1_bss_6EAB4 |= 0x2C;
        fn_1_A2A70(44, 60);
        break;
    case 7:
        *(u32 *)(state + 0x94) |= 0x08000000;
        *(u32 *)(state + 0x94) |= 0x80;
        fn_1_4A00(0, 60, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        lbl_1_bss_6EAB4 |= 0x2C;
        fn_1_A2A70(44, 60);
        break;
    case 8:
        *(u32 *)(state + 0x94) |= 0x08000000;
        *(u32 *)(state + 0x94) |= 0x40;
        fn_1_4A00(0, 60, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        lbl_1_bss_6EAB4 |= 0x2C;
        fn_1_A2A70(44, 60);
        break;
    case 9:
        if (((lbl_1_bss_9F8[lbl_1_bss_8B3A0.unk_9E].unk_2 >> 8) & 1) || !(u8)fn_1_D6680()) {
            fn_1_D66F4();
            lbl_10_bss_14 = (15);
        } else {
            lbl_10_bss_14 = (21);
        }
        fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        break;
    case 10:
        lbl_10_bss_14 = 15;
        fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        break;
    default:
        switch (*(s16 *)arg0) {
        case 0:
            fn_10_CFAC(1, 0, 30, 10);
            *(s16 *)((u8 *)arg0 + 4) = *(s16 *)((u8 *)arg0 + 4) < 2 ? 2 :
                (*(s16 *)((u8 *)arg0 + 4) > countControllers() ? countControllers() : *(s16 *)((u8 *)arg0 + 4));
            break;
        case 1:
        case 11:
            fn_10_CFAC(1, 0, 30, 6);
            break;
        case 2:
            fn_10_CFAC(1, 0, 30, 18);
            break;
        }
        break;
    }
}
/* fzgx:end fn_10_9788 */

/* fzgx:begin fn_10_A0E8 */
#pragma opt_common_subs off

s16 fn_10_A0E8(SelState *state) {
    s32 res;
    s32 sum;
    s16 old;
    s16 counter;
    s16 i;

    old = lbl_10_bss_55608;
    counter = 0;
    for (i = 0; i < 4; i++) {
        if ((*(SelSlot9C8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9C8))[i].unk_a == -1) {
            continue;
        }
        if (__rlwnm((&(*(struct SelState98 *)&lbl_1_bss_8B3A0.unk_0))->unk_98, ((i + 1) & 31), 31, 31) != 0) {
            if ((((*(SelSlot9F8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9F8))[i].unk_10 >> 3) & 1) ||
                (((*(SelSlot9F8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9F8))[i].unk_12 >> 3) & 1)) {
                counter--;
            }
            if ((((*(SelSlot9F8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9F8))[i].unk_10 >> 2) & 1) ||
                (((*(SelSlot9F8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9F8))[i].unk_12 >> 2) & 1)) {
                counter++;
            }
            if ((((*(SelSlot9F8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9F8))[i].unk_10 >> 2) & 1) ||
                (((*(SelSlot9F8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9F8))[i].unk_12 >> 2) & 1)) {
                fn_1_12F128(i);
            } else if ((((*(SelSlot9F8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9F8))[i].unk_10 >> 3) & 1) ||
                       (((*(SelSlot9F8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9F8))[i].unk_12 >> 3) & 1)) {
                fn_1_12F128(i);
            }
        }
    }

    sum = lbl_10_bss_55608 + counter;
    if (sum < 0) {
        res = 0;
    } else {
        res = 1;
        if (sum <= 1) {
            res = sum;
        }
    }
    lbl_10_bss_55608 = res;
    if ((s16)res != old) {
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
    }
    return lbl_10_bss_55608;
}
#pragma opt_common_subs reset
/* fzgx:end fn_10_A0E8 */

/* fzgx:begin fn_10_A25C */
#pragma opt_common_subs off

void fn_10_A25C(SelObjA25C *obj) {
    struct { s16 value; } count;
    struct { s16 value; } i;
    s16 delta = 0;
    s16 j;
    s32 val;
    s32 t;
    s32 c;
    count.value = 0;

    for (i.value = 0; i.value < 4; i.value++) {
        val = ((i.value)[lbl_1_bss_980]);
        if (val == 0x9000000 || val == -0x78000000 || val == -0x74F00000 ||
            val == 0x8000000) {
            count.value++;
        }
    }

    for (j = 0; j < 4; j++) {
        if (((j)[(*(SelRowA25C (*)[4])&(*(u8 (*)[])&lbl_1_bss_9C8))]).unk_a == -1) {
            continue;
        }

        if (__rlwnm((*(SelGlobA25C *)&lbl_1_bss_8B3A0.unk_0).unk_98, ((((1) + j)) & 31), 31, 31) != 0) {
            if (((((j)[(*(SelInfoA25C (*)[4])&(*(u8 (*)[])&lbl_1_bss_9F8))]).unk_10 >> 3) & 1) ||
                ((((j)[(*(SelInfoA25C (*)[4])&(*(u8 (*)[])&lbl_1_bss_9F8))]).unk_12 >> 3) & 1)) {
                delta--;
            }

            if (((((j)[(*(SelInfoA25C (*)[4])&(*(u8 (*)[])&lbl_1_bss_9F8))]).unk_10 >> 2) & 1) ||
                (((1) & ((((j)[(*(SelInfoA25C (*)[4])&(*(u8 (*)[])&lbl_1_bss_9F8))]).unk_12 >> 2))))) {
                delta++;
            }

            if (((((j)[(*(SelInfoA25C (*)[4])&(*(u8 (*)[])&lbl_1_bss_9F8))]).unk_10 >> 2) & 1) ||
                ((((j)[(*(SelInfoA25C (*)[4])&(*(u8 (*)[])&lbl_1_bss_9F8))]).unk_12 >> 2) & 1)) {
                fn_1_12F128(j);
            } else if (((((j)[(*(SelInfoA25C (*)[4])&(*(u8 (*)[])&lbl_1_bss_9F8))]).unk_10 >> 3) & 1) ||
                       ((((j)[(*(SelInfoA25C (*)[4])&(*(u8 (*)[])&lbl_1_bss_9F8))]).unk_12 >> 3) & 1)) {
                fn_1_12F128(j);
            }
        }
    }

    if (((*(SelGlobA25C *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x200) != 0) {
        c = count.value;
        t = ((obj->unk_4) + delta);
        if (t > c) {
            t = 0;
        } else if (t < 0) {
            t = c;
        }
        obj->unk_4 = t;
    } else {
        c = count.value;
        t = ((obj->unk_4) + delta);
        if (t > c) {
            t = 2;
        } else if (t < 2) {
            t = c;
        }
        obj->unk_4 = t;
    }

    if (delta != 0) {
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
    }

    if (obj->unk_0 == 0) {
        obj->unk_6 = obj->unk_4;
        if (obj->unk_4 == 1) {
            obj->unk_6 = 30;
        }
    }
}

#pragma opt_common_subs reset
/* fzgx:end fn_10_A25C */

/* fzgx:begin fn_10_A480 */
#pragma opt_common_subs off

void fn_10_A480(struct fn_10_A480_Arg0 *arg0) {
fn_10_A480_s16 v4 = 0;
fn_10_A480_s32 temp;
fn_10_A480_s16 v1;
fn_10_A480_s16 v2;
fn_10_A480_s16 v3;
fn_10_A480_u16 v9;
fn_10_A480_u16 v8;
fn_10_A480_s32 v12;
fn_10_A480_s32 lower;
fn_10_A480_s32 v10;
fn_10_A480_s32 v5;
temp = 30;
if ((arg0->unk_94 & 2) != 0) {
temp = (*(fn_10_A480_s8 (*)[1])&(*(fn_10_A480_u8 *)(&lbl_10_bss_4938E)))[0];
}
v1 = (fn_10_A480_s16)temp ;
v2 = 0;
goto loop_test; /* Keep the verified branch to loop_test. */
loop_body:
v2++;
loop_test:
if (v2 < 4) goto loop_body; /* Keep the verified branch to loop_body. */
for (v3 = 0; v3 < 4; v3++) {
if ((((struct fn_10_A480_E9C8 *)&(*(fn_10_A480_u8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9C8))))[v3].id != -1 && __rlwnm((*((struct fn_10_A480_lbl_1_bss_8B3A0 *)&(*(fn_10_A480_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0))).unk_98, (v3 + 1) & 31, 31, 31)) {
if ((((((struct fn_10_A480_E9F8 *)&(*(fn_10_A480_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8))))[v3].a >> 3) & 1) || (((((struct fn_10_A480_E9F8 *)&(*(fn_10_A480_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8))))[v3].b >> 3) & 1)) {
v4--;
}
if ((((((struct fn_10_A480_E9F8 *)&(*(fn_10_A480_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8))))[v3].a >> 2) & 1) || (((((struct fn_10_A480_E9F8 *)&(*(fn_10_A480_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8))))[v3].b >> 2) & 1)) {
v4++;
}
v8 = (((struct fn_10_A480_E9F8 *)&(*(fn_10_A480_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8))))[v3].a;
if (((v8 >> 2) & 1) || (((v9 = (((struct fn_10_A480_E9F8 *)&(*(fn_10_A480_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8))))[v3].b) >> 2) & 1)) {
fn_1_12F128(v3);
} else if (((v8 >> 3) & 1) || ((v9 >> 3) & 1)) {
fn_1_12F128(v3);
}
}
}
v10 = arg0->unk_6 + v4;
v5 = v1;
if (v10 > v1) {
v10 = 1;
if (arg0->unk_4 > 1) {
v10 = arg0->unk_4;
}
} else {
lower = arg0->unk_4;
v12 = 1;
if (lower > 1) {
v12 = lower;
}
if (v10 < v12) {
v10 = v5;
}
}
arg0->unk_6 = v10;
if (v4 != 0) {
fn_1_A2D84(0xA9010000);
(*(fn_10_A480_u32 *)&lbl_801A66A8) = 0;
}
}

#pragma opt_common_subs reset
/* fzgx:end fn_10_A480 */

/* fzgx:begin fn_10_A634 */
#pragma opt_common_subs off

void fn_10_A634(void *arg0) {
struct { fn_10_A634_s32 value; } v0;
fn_10_A634_s16 v2;
fn_10_A634_s16 v1;
fn_10_A634_u16 v7;
fn_10_A634_u16 v6;
fn_10_A634_s32 out;
fn_10_A634_s32 v8;
fn_10_A634_s32 v9;
v0.value = ((fn_10_A634_u32)fn_1_F9FEC()) != 0;
v2 = 0;
for (v1 = 0; v1 < 4; v1++) {
if ((((struct fn_10_A634_E9C8 *)&(*(fn_10_A634_u8 (*)[])&(*(u8 (*)[])&lbl_1_bss_9C8))))[v1].id != -1 &&
__rlwnm((*((struct fn_10_A634_lbl_1_bss_8B3A0 *)&(*(fn_10_A634_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0))).unk_98, (v1 + 1) & 31, 31, 31)) {
if ((((((struct fn_10_A634_E9F8 *)&(*(fn_10_A634_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8))))[v1].a >> 3) & 1) || (((((struct fn_10_A634_E9F8 *)&(*(fn_10_A634_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8))))[v1].b >> 3) & 1)) {
v2--;
}
if ((((((struct fn_10_A634_E9F8 *)&(*(fn_10_A634_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8))))[v1].a >> 2) & 1) || (((((struct fn_10_A634_E9F8 *)&(*(fn_10_A634_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8))))[v1].b >> 2) & 1)) {
v2++;
}
v6 = (((struct fn_10_A634_E9F8 *)&(*(fn_10_A634_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8))))[v1].a;
if (((v6 >> 2) & 1) || (((v7 = (((struct fn_10_A634_E9F8 *)&(*(fn_10_A634_Obj_1_bss_9F8 *)&(*(u8 (*)[])&lbl_1_bss_9F8))))[v1].b) >> 2) & 1)) {
fn_1_12F128(v1);
} else if (((v6 >> 3) & 1) || ((v7 >> 3) & 1)) {
fn_1_12F128(v1);
}
}
}
if (v0.value) {
v8 = *(fn_10_A634_s16 *)((fn_10_A634_u8 *)arg0 + 8) + v2;
if (v8 > 3) out = 0;
else {
out = 3;
if (v8 >= 0) out = v8;
}
*(fn_10_A634_s16 *)((fn_10_A634_u8 *)arg0 + 8) = out;
} else {
v9 = *(fn_10_A634_s16 *)((fn_10_A634_u8 *)arg0 + 8) + v2;
if (v9 > 2) out = 0;
else {
out = 2;
if (v9 >= 0) out = v9;
}
*(fn_10_A634_s16 *)((fn_10_A634_u8 *)arg0 + 8) = out;
}
*(fn_10_A634_s16 *)((fn_10_A634_u8 *)arg0 + 10) = *(fn_10_A634_s16 *)((fn_10_A634_u8 *)arg0 + 8);
if (v2 != 0) {
fn_1_A2D84(0xA9010000);
(*(fn_10_A634_u32 *)&lbl_801A66A8) = 0;
}
}

#pragma opt_common_subs reset
/* fzgx:end fn_10_A634 */

/* fzgx:begin fn_10_A7DC */
inline int fn_10_A7DC(s16 mode) {
    if ((lbl_1_bss_8B3A0.unk_94 & 0x200) != 0) {
        if (mode == 0) {
            return 1;
        }
        if (mode >= 1 && mode <= 3) {
            return 1;
        }
        if (mode == 4) {
            if (fn_1_FA070() != 0) {
                return 1;
            }
        }
        if (mode == 5) {
            if (fn_1_FA0BC(lbl_1_bss_8B3A0.unk_0 == 1) != 0) {
                return 1;
            }
        }
    } else {
        if (mode >= 1 && mode <= 3) {
            return 1;
        }
        if (mode == 4) {
            if (fn_1_FA070() != 0) {
                return 1;
            }
        }
        if (mode == 5) {
            if (fn_1_FA0BC(lbl_1_bss_8B3A0.unk_0 == 1) != 0) {
                return 1;
            }
        }
    }

    return 0;
}
/* fzgx:end fn_10_A7DC */

/* fzgx:begin fn_10_A90C */
#include "game/pad.h"
#pragma opt_loop_invariants off
#pragma opt_dead_assignments off
void fn_10_A90C(SelState *state) {
    u8 *p_lbl_1_bss_9C8;
    s16 delta;
    SelState *p_lbl_1_bss_8B3A0;
    s16 i;
    void *v2;
    p_lbl_1_bss_9C8 = (u8 *)&lbl_1_bss_9C8;
    v2 = &lbl_1_bss_9F8;
    p_lbl_1_bss_8B3A0 = &lbl_1_bss_8B3A0;
    delta = 0;
    i = 0;
    while (i < 4) {
        if (lbl_1_bss_9C8[i].unk_a != -1) {
            if (__rlwnm(p_lbl_1_bss_8B3A0->unk_98, (i + 1) & 31, 31, 31)) {
                if (PAD_BIT(((SelInput *)lbl_1_bss_9F8)[i].unk_10, 0) || PAD_BIT(((SelInput *)lbl_1_bss_9F8)[i].unk_12, 0)) delta--;
                if (PAD_BIT(((SelInput *)lbl_1_bss_9F8)[i].unk_10, 1) || PAD_BIT(((SelInput *)lbl_1_bss_9F8)[i].unk_12, 1)) delta++;
                if (PAD_BIT(((SelInput *)lbl_1_bss_9F8)[i].unk_10, 1) || PAD_BIT(((SelInput *)lbl_1_bss_9F8)[i].unk_12, 1)) {
                    fn_1_12F128(i);
                } else if (PAD_BIT(((SelInput *)lbl_1_bss_9F8)[i].unk_10, 0) || PAD_BIT(((SelInput *)lbl_1_bss_9F8)[i].unk_12, 0)) {
                    fn_1_12F128(i);
                }
            }
        }
        i++;
    }
    if (delta != 0) {
        if (state->unk_94 & 0x40000000) {
            s32 value = state->unk_8C + delta;
            state->unk_8C = value > 8 ? 6 : value < 6 ? 8 : value;
        } else {
            v2 = (void *)delta;
            do {
                s32 value = state->unk_8C + (s32)v2;
                state->unk_8C = value > 10 ? 0 : value < 0 ? 10 : value;
            } while (!fn_10_A7DC(state->unk_8C));
        }
        state->unk_8E = 0;
        fn_1_A2D84(0xa9010000);
    }
}
#pragma opt_loop_invariants reset
#pragma opt_dead_assignments reset
/* fzgx:end fn_10_A90C */

/* fzgx:begin fn_10_AB98 */
static inline fn_10_AB98_s16 sel_sign(fn_10_AB98_s16 x) {
return x < 0 ? -1 : (x > 0);
}

static inline void sel_move_cursor(fn_10_AB98_fn_10_AB98_SelCursor *cursor, fn_10_AB98_s32 step) {
fn_10_AB98_s8 i;
fn_10_AB98_s32 blocked;
fn_10_AB98_s32 pos;
fn_10_AB98_s32 next;
fn_10_AB98_s16 count;
fn_10_AB98_s16 dir;
fn_10_AB98_s32 tmp_ra6;
if (cursor->unk_8C == 0) {
pos = cursor->unk_90;
pos = pos < 0 ? step : (pos > 110 ? 110 : pos);
if ((cursor->unk_94 & 2) != 0 && (fn_10_AB98_s8)(*(fn_10_AB98_u8 (*)[0x1A0])&(*(u8 (*)[0x1A0])&lbl_10_data_2B4))[pos] == 0) {
step = 1;
}
count = __abs((fn_10_AB98_s16)step);
dir = sel_sign(step);
while (count-- > 0) {
next = pos + dir;
pos = next > 110 ? 0 : (next < 0 ? 110 : next);
if ((cursor->unk_94 & 2) != 0) {
while ((fn_10_AB98_s8)(*(fn_10_AB98_u8 (*)[0x1A0])&(*(u8 (*)[0x1A0])&lbl_10_data_2B4))[pos] == 0) {
next = pos + dir;
pos = next > 110 ? 0 : (next < 0 ? 110 : next);
}
}
}
cursor->unk_8E = pos;
cursor->unk_90 = cursor->unk_8E;
} else {
i = step;
do {
blocked = 0;
next = cursor->unk_8E + step;
cursor->unk_8E = next > 5 ? blocked : (next < 0 ? 5 : next);
cursor->unk_90 = ((fn_10_AB98_s16)fn_1_12EF24( (s16)(cursor->unk_8C), (s16)(cursor->unk_8E)));
if (cursor->unk_90 == -1 && step == 0) {
step = 1;
}
if (cursor->unk_8C == 5) {
tmp_ra6 = cursor->unk_8E;
if ((tmp_ra6 == 5 && ((fn_10_AB98_s32)fn_1_F89E4(0)) == 0) ||
(cursor->unk_8E != 5 && ((fn_10_AB98_s32)fn_1_F89E4(cursor->unk_8E + 1)) == 0)) {
blocked = 1;
if (step == 0) {
step = blocked;
}
}
}
i++;
if (cursor->unk_90 != -1 && (fn_10_AB98_s8)(*(fn_10_AB98_u8 (*)[0x1A0])&(*(u8 (*)[0x1A0])&lbl_10_data_2B4))[cursor->unk_90] != 0 && blocked == 0) {
break;
}
} while (i < 6);
}
if ((*((struct fn_10_AB98_SelState *)&(*(fn_10_AB98_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0))).value != 1) {
fn_10_C594();
}
if ((*((struct fn_10_AB98_SelState *)&(*(fn_10_AB98_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0))).value != 1 && (cursor->unk_94 & 0x80000000) == 0) {
fn_1_7B2E8(cursor->unk_90);
}
}

void fn_10_AB98(fn_10_AB98_fn_10_AB98_SelCursor *cursor) {
sel_move_cursor(cursor, 0);
}
/* fzgx:end fn_10_AB98 */

/* fzgx:begin fn_10_AE14 */
#include "game/pad.h"
/* WARNING: compiler-diff device, not original code. Byte-offset view of lbl_1_bss_9F8 (carried from main): the
 * generated header types it as one 0x14 record, retail has four. */
#define PADW(p, o) (*(u16 *)((p) + (o)))

#define WRAP(v, max) ((v) > (max) ? 0 : (v) < 0 ? (max) : (v))



static inline s16 fn_10_AE14_option_input(u8 *ctrls, u8 *pads) {
    s16 i;
    u32 rep;
    s16 vdir = 0;
    for (i = 0; i < 4; ctrls += 12, pads += 20, i++) {
        if (ctrls[10] != -1 && __rlwnm((*(fn_10_AE14_Sel *)&lbl_1_bss_8B3A0.unk_0).players, (i + 1) & 31, 31, 31)) {
            if ((PADW(pads, 18) >> 8) & 1) vdir--;
            if ((PADW(pads, 18) >> 9) & 1) vdir++;
            rep = PADW(pads, 18);
            if ((rep >> 9) & 1) fn_1_12F128(i);
            else if ((rep >> 8) & 1) fn_1_12F128(i);
        }
    }
    return vdir;
}

static inline void fn_10_AE14_tail(fn_10_AE14_Cursor *cursor, s32 dir, s16 old) {
    s32 move_;
    s16 fmove;
    s8 tries;
    s16 step;
    s16 steps;
    s32 next;
    s32 skip;
    move_ = dir;
    if (cursor->group == 0) {
        /* flat list 0..0x6E, skipping locked entries */
        fmove = dir;
        next = old;
        next = next < 0 ? 0 : next > 0x6E ? 0x6E : next;
        if ((cursor->flags & 2) && fmove == 0 && (*(s8 (*)[])&(*(u8 (*)[0x1A0])&lbl_10_data_2B4))[next] == 0) {
            fmove = 1;
        }
        steps = __abs(fmove);
        step = fmove < 0 ? -1 : fmove > 0;
        while (steps-- > 0) {
            next = WRAP(next + step, 0x6E);
            if (cursor->flags & 2) {
                while ((*(s8 (*)[])&(*(u8 (*)[0x1A0])&lbl_10_data_2B4))[next] == 0) {
                    next = WRAP(next + step, 0x6E);
                }
            }
        }
        cursor->column = next;
        cursor->index = cursor->column;
    } else {
        /* grid row: columns 0..5, skipping empty or locked slots */
        tries = 0;
        do {
            skip = 0;
            cursor->column = WRAP(cursor->column + move_, 5);
            cursor->index = fn_1_12EF24(cursor->group, cursor->column);
            if (cursor->index == -1 && move_ == 0) {
                move_ = 1;
            }
            if (cursor->group == 5 &&
                ((cursor->column == 5 && fn_1_F89E4(0) == 0) ||
                 (cursor->column != 5 && fn_1_F89E4(cursor->column + 1) == 0))) {
                skip = 1;
                if (move_ == 0) {
                    move_ = skip;
                }
            }
            tries++;
        } while ((cursor->index == -1 || (*(s8 (*)[])&(*(u8 (*)[0x1A0])&lbl_10_data_2B4))[cursor->index] == 0 || skip) && tries < 6);
    }
    if (old != cursor->index) {
        fn_1_A2D84(0xA9010000);
    }
    fn_1_12F358(cursor->index);

}

void fn_10_AE14(fn_10_AE14_Cursor *cursor) {
    struct { s16 value; } i;
    u8 *pad;
    s32 dir;
    dir = 0;
    for (i.value = 0; i.value < 4; i.value++) {
        if ((s8)(*(u8 (*)[])&lbl_1_bss_9C8)[i.value * 12 + 10] != -1 && __rlwnm((*(fn_10_AE14_Sel *)&lbl_1_bss_8B3A0.unk_0).players, (i.value + 1) & 31, 31, 31)) {
            if (PAD_BIT(PADW((*(u8 (*)[])&lbl_1_bss_9F8) + i.value * 20, 16), 0) || PAD_BIT(PADW((*(u8 (*)[])&lbl_1_bss_9F8) + i.value * 20, 18), 0)) dir--;
            if (PAD_BIT(PADW((*(u8 (*)[])&lbl_1_bss_9F8) + i.value * 20, 16), 1) || PAD_BIT(PADW((*(u8 (*)[])&lbl_1_bss_9F8) + i.value * 20, 18), 1)) dir++;
            if (PAD_BIT(PADW((*(u8 (*)[])&lbl_1_bss_9F8) + i.value * 20, 16), 1) || PAD_BIT(PADW((*(u8 (*)[])&lbl_1_bss_9F8) + i.value * 20, 18), 1)) fn_1_12F128(i.value);
            else if (PAD_BIT(PADW((*(u8 (*)[])&lbl_1_bss_9F8) + i.value * 20, 16), 0) || PAD_BIT(PADW((*(u8 (*)[])&lbl_1_bss_9F8) + i.value * 20, 18), 0)) fn_1_12F128(i.value);
        }
    }
    if ((*(fn_10_AE14_Sel *)&lbl_1_bss_8B3A0.unk_0).mode == 1) {
        dir = 0;
    }

    fn_10_AE14_tail(cursor, dir, cursor->index);
    if ((*(fn_10_AE14_Sel *)&lbl_1_bss_8B3A0.unk_0).mode == 10) {
        s16 vdir = 0;
        s16 j;
        for (j = 0; j < 4; j++) {
            if ((s8)(*(u8 (*)[])&lbl_1_bss_9C8)[j * 12 + 10] != -1 && __rlwnm((*(fn_10_AE14_Sel *)&lbl_1_bss_8B3A0.unk_0).players, (j + 1) & 31, 31, 31)) {
                if (PAD_BIT(PADW((*(u8 (*)[])&lbl_1_bss_9F8) + j * 20, 18), 8)) vdir--;
                if (PAD_BIT(PADW((*(u8 (*)[])&lbl_1_bss_9F8) + j * 20, 18), 9)) vdir++;
                if (PAD_BIT(PADW((*(u8 (*)[])&lbl_1_bss_9F8) + j * 20, 18), 9)) fn_1_12F128(j);
                else if (PAD_BIT(PADW((*(u8 (*)[])&lbl_1_bss_9F8) + j * 20, 18), 8)) fn_1_12F128(j);
            }
        }
        if (vdir != 0) {
            (*(fn_10_AE14_Sel *)&lbl_1_bss_8B3A0.unk_0).option = WRAP((*(fn_10_AE14_Sel *)&lbl_1_bss_8B3A0.unk_0).option + vdir, 3);
            fn_1_A2D84(0xA9010000);
        }
        if ((*(fn_10_AE14_Sel *)&lbl_1_bss_8B3A0.unk_0).option == 3 && PAD_BIT(lbl_1_bss_D58.held, 8)) {
            (*(fn_10_AE14_Sel *)&lbl_1_bss_8B3A0.unk_0).option = 5;
        }
        if ((*(fn_10_AE14_Sel *)&lbl_1_bss_8B3A0.unk_0).option == 5 && !PAD_BIT(lbl_1_bss_D58.held, 8)) {
            (*(fn_10_AE14_Sel *)&lbl_1_bss_8B3A0.unk_0).option = 3;
        }
    }
    if (dir != 0 && !(cursor->flags & 0x80000000)) {
        fn_1_7B2E8(cursor->index);
    }
}
/* fzgx:end fn_10_AE14 */

/* fzgx:begin fn_10_B2C8 */
/* one 0x20-byte player record of lbl_1_bss_8B3A0.unk_0 */

/* fzgx-allow: S2 registers the handle for its destroy callback, which writes it */

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

/* the retail TU's .data objects this function uses, at their retail offsets */

/* fzgx-allow: S2 heap handle: fn_10_C5E0 ( (void * *)(void *)(registered via fn_1_46B44)) frees the heap and writes -1 here */

static inline void fn_10_B2C8_start(void) {
    fn_1_46BFC();
    lbl_10_bss_C = 1;
    fn_1_46B44(fn_10_C5E0, &lbl_10_data_578);
}

static inline s16 fn_10_B2C8_saved(s16 who) {
    fn_10_B2C8_Custom *save = &((fn_10_B2C8_Custom *)fn_1_36AD0())[who];

    if ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x40000000) {
        save = &((fn_10_B2C8_Custom *)fn_1_36AD0())[fn_1_8623C()];
    }
    return -1;
}

static inline void fn_10_B2C8_restore(s16 player) {
    s16 *slot;
    s16 custom;
    fn_10_B2C8_Custom *src;
    u8 value;
    s16 idx;

    idx = player;
    if ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x40000000) {
        idx = 0;
    }
    slot = &((fn_10_B2C8_Player *)&(*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0))[idx].unk_E;
    if (*slot != -1 && (custom = *slot - 41) >= 0) {
        src = &(*(fn_10_B2C8_Custom (*)[9])&lbl_10_bss_3C0)[custom];
        if (src->unk_0 & 0x80000000) {
            if ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x40000000) {
                fn_1_36A94(fn_1_8623C(), src);
                value = *slot;
                ((fn_10_B2C8_Custom *)fn_1_36AD0())[fn_1_8623C()].unk_5 = value;
            } else {
                fn_1_36A94(idx, src);
                value = *slot;
                ((fn_10_B2C8_Custom *)fn_1_36AD0())[idx].unk_5 = value;
            }
            if (!((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x20000000)) {
                *slot = idx + 0x36;
            }
        }
    }
}

s16 fn_10_B2C8(fn_10_B2C8_Obj_1_bss_8B3A0 *arg0) {
    s16 count;
    fn_10_B2C8_Course *course;
    s16 i;
    s16 j;
    s16 k;
    s16 vehicle;
    s16 next;
    s16 ready;
    s16 machine;
    s16 dx;
    s16 dy;
    s16 cur;
    s16 who;
    s16 custom;
    fn_10_B2C8_Pad *pad;
    fn_10_B2C8_Slot *kind;
    fn_10_B2C8_Record *rec;
    s16 *slot;
    s64 used;
    u32 heap;
    u32 size;
    char name[0x40];
    char path[0x40];
    char gma[0x20];
    char tpl[0x20];
    s16 col;
    s16 row;
    s32 stage;

    course = &arg0->unk_A4[(s16)(lbl_1_bss_962 - 14)];
    ready = 0;
    count = 0;
    for (j = 0; j < 4; j++) {
        if (arg0->u.players[j].unk_E != -1) {
            count++;
        }
    }
    for (i = 0; i < 4; i++) {
        dx = 0;
        machine = arg0->u.players[i].unk_E;
        dy = 0;
        pad = &(*(fn_10_B2C8_Pad (*)[4])&(*(u8 (*)[])&lbl_1_bss_9F8))[i];
        kind = &lbl_10_bss_5560C[i];
        if ((rec = &course->unk_24[i])->unk_0 == 0) {
            if (__rlwnm((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_98, (i + 1) & 31, 31, 31) && ((pad->unk_8 >> 9) & 1) &&
                (!((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x40000000) || ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x4000))) {
                fn_1_A2D84(0xA9010200);
                if (lbl_10_bss_C == 0) {
                    fn_10_B2C8_start();
                    fn_10_C594();
                }
                return -1;
            }
            if (((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x40000000) && ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x1000) && kind->unk_12 == 4) {
                fn_1_12E0B8(i, machine, (*(u8 (*)[4][0x4E0])&lbl_10_bss_51B7C)[i], (*(u8 (*)[4][0x9C0])&lbl_10_bss_52EFC)[i], 1,
                            lbl_1_data_407BC, 4);
            }
        } else if (((pad->unk_8 >> 9) & 1) && (!((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x40000000) || ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x4000))) {
            fn_1_12C0EC(&rec->unk_0);
            fn_1_12F150(i, 0, 0);
            fn_1_A2D84(0xA9010200);
            who = i;
            if ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x40000000) {
                who = 0;
            }
            slot = &((fn_10_B2C8_Player *)&(*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0))[who].unk_E;
            if (*slot != -1 && (*slot >= 0x36 || ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x20000000))) {
                if ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x40000000) {
                    fn_80008BEC(&((fn_10_B2C8_Custom *)fn_1_36AD0())[fn_1_8623C()], 0, sizeof(fn_10_B2C8_Custom));
                } else {
                    fn_80008BEC(&((fn_10_B2C8_Custom *)fn_1_36AD0())[who], 0, sizeof(fn_10_B2C8_Custom));
                }
                if (!((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x20000000)) {
                    if ((*slot = fn_10_B2C8_saved(who)) == -1) {
                        if ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x40000000) {
                            *slot = lbl_10_data_55C[who];
                        } else {
                            *slot = lbl_10_data_554[who];
                        }
                    }
                }
            }
            machine = arg0->u.players[i].unk_E;
            fn_1_469BC();
            if (lbl_10_data_578 != (void *)-1) {
                fn_10_B2C8_start();
            }
        } else {
            if (rec->unk_0 == 2) {
                ready++;
                continue;
            }
            if (rec->unk_0 == 1) {
                if (((*(fn_10_B2C8_Pad (*)[4])&(*(u8 (*)[])&lbl_1_bss_9F8))[i].unk_8 >> 8) & 1) {
                    rec->unk_0 = 2;
                }
                continue;
            }
        }
        if (fn_1_12F228() == 0) {
            if ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x40000000) {
                if (i == 0) {
                    if (lbl_1_bss_8CA26 != 0) {
                        if (((pad->unk_10 >> 3) & 1) || ((pad->unk_12 >> 3) & 1)) {
                            dy--;
                            fn_1_A2D84(0xA9010000);
                        }
                        if (((pad->unk_10 >> 2) & 1) || ((pad->unk_12 >> 2) & 1)) {
                            dy++;
                            fn_1_A2D84(0xA9010000);
                        }
                    }
                    if ((pad->unk_10 & 1) || (pad->unk_12 & 1) ||
                        ((pad->unk_12 >> 8) & 1)) {
                        dx--;
                        fn_1_A2D84(0xA9010000);
                    }
                    if (((pad->unk_10 >> 1) & 1) || ((pad->unk_12 >> 1) & 1) ||
                        ((pad->unk_12 >> 9) & 1)) {
                        dx++;
                        fn_1_A2D84(0xA9010000);
                    }
                }
            } else if (arg0->u.players[i].unk_E != -1) {
                if (((pad->unk_10 >> 3) & 1) || ((pad->unk_12 >> 3) & 1)) {
                    dy--;
                    fn_1_A2D84(0xA9010000);
                }
                if (((pad->unk_10 >> 2) & 1) || ((pad->unk_12 >> 2) & 1)) {
                    dy++;
                    fn_1_A2D84(0xA9010000);
                }
                if ((pad->unk_10 & 1) || (pad->unk_12 & 1)) {
                    dx--;
                    fn_1_A2D84(0xA9010000);
                }
                if (((pad->unk_10 >> 1) & 1) || ((pad->unk_12 >> 1) & 1)) {
                    dx++;
                    fn_1_A2D84(0xA9010000);
                }
            }
        }
        if (dx != 0 || dy != 0) {
            cur = arg0->u.players[i].unk_E;
            if (count + 1 > arg0->u.hdr.unk_4 && cur == -1) {
                continue;
            }
            if ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x18000) {
                next = fn_1_152FAC(i, cur, dy, dx, (*(fn_10_B2C8_Cell (*)[6][19])&lbl_10_bss_1C)[0], lbl_10_bss_1A,
                                   lbl_10_bss_18);
            } else {
                next = fn_1_152A28(cur, dy, dx, (*(fn_10_B2C8_Cell (*)[6][19])&lbl_10_bss_1C)[0], lbl_10_bss_1A,
                                   lbl_10_bss_18);
            }
            if (cur != next) {
                fn_1_12F128(i);
            }
            if (arg0->unk_94 & 0x10000000) {
                used = 0;
                for (j = 0; j < 4; j++) {
                    if (i != j && arg0->u.players[j].unk_E != -1) {
                        used |= 1 << arg0->u.players[j].unk_E;
                    }
                }
                while (used & (1 << next)) {
                    if ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x18000) {
                        next = fn_1_152FAC(i, next, dy, dx, (*(fn_10_B2C8_Cell (*)[6][19])&lbl_10_bss_1C)[0], lbl_10_bss_1A,
                                           lbl_10_bss_18);
                    } else {
                        next = fn_1_152A28(next, dy, dx, (*(fn_10_B2C8_Cell (*)[6][19])&lbl_10_bss_1C)[0], lbl_10_bss_1A,
                                           lbl_10_bss_18);
                    }
                }
            }
            arg0->u.players[i].unk_E = next;
        }
        if (arg0->u.players[i].unk_E == -1) {
            continue;
        }
        arg0->u.players[i].unk_14 = 1;
        if (!((pad->unk_8 >> 8) & 1) && fn_1_12F228() == 0) {
            continue;
        }
        fn_1_12F1E8(0);
        fn_1_152970(&row, &col, arg0->u.players[i].unk_E, 0, lbl_10_bss_1C[0], lbl_10_bss_1A, lbl_10_bss_18);
        if (!((*(fn_10_B2C8_Cell (*)[6][19])&lbl_10_bss_1C)[row][col].mask & 0xC0000000)) {  /* fzgx-allow: A1 entry state flag bits, not an address */
            if (((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x40000000) && ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x1000)) {
                fn_1_12ECA8(i, machine, (*(u8 (*)[4][0x4E0])&lbl_10_bss_51B7C)[i], (*(u8 (*)[4][0x9C0])&lbl_10_bss_52EFC)[i], &rec->unk_0);
                rec->unk_0 = 1;
            } else {
                if (rec->unk_0 != 2) {
                    ready++;
                }
                rec->unk_0 = 2;
            }
            fn_1_12F150(i, 0, 1);
            custom = arg0->u.players[i].unk_E - 41;
            if (custom >= 0) {
                fn_10_B2C8_Custom *p = &(*(fn_10_B2C8_Custom (*)[9])&lbl_10_bss_3C0)[custom];

                if ((p->unk_0 & 0x80000000) && !(p->unk_0 & 0x40000000)) {
                    fn_1_A50C8(p->unk_81A0);
                } else {
                    fn_1_A50C8(arg0->u.players[i].unk_E);
                }
            } else {
                fn_1_A50C8(arg0->u.players[i].unk_E);
            }
            fn_1_A2D84(0xA9010100);
            if (lbl_10_data_578 == (void *)-1) {
                heap = fn_1_4404();
                size = fn_800090A4(lbl_801A6410) - 0x10000;
                lbl_10_data_578 = (void *)fn_1_45D0(lbl_801A6410, size, lbl_10_data_57C, 0x16AD);
                if (size > 0x1E000) {
                    fn_1_46BA0(lbl_10_data_578, size);
                    lbl_10_bss_C = 0;
                }
                fn_80008E84(heap);
            }
            if ((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).u.hdr.unk_0 != 1) {
                vehicle = arg0->u.players[i].unk_E;
                if (!((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x80000000) && vehicle <= 40) {
                    fn_1_465D0( (fn_1_12D254(vehicle, lbl_10_data_45C)), 1);
                    fn_80006E10("vehicle");
                    fn_80006E10((fn_1_7F518(vehicle, path, 0)));
                    for (k = 5; k <= 7; k++) {
                        fn_1_7F58C(vehicle, name, k, 0);
                        fn_1_465D0( name, 1);
                    }
                    fn_80006E10("../../");
                }
            } else {
                stage = fn_1_12EF24((*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_8C, 0);
                fn_1_4100C();
                fn_1_47E54(0xBB);
                fn_1_47E54(0x9A);
                fn_1_47E54(0x9B);
                fn_1_47E54(0xA1);
                fn_1_41104(1);
                sprintf(tpl, "stage/selst%02d.tpl.lz", stage);
                sprintf(gma, "stage/selst%02d.gma.lz", stage);
                fn_1_465D0( tpl, 1);
                fn_1_465D0( gma, 1);
                fn_1_46EA8(0);
            }
            fn_1_12F1E8(0);
            fn_10_B2C8_restore(i);
        }
        (*(fn_10_B2C8_Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0.unk_0).unk_129 = 0;
    }
    if (ready >= arg0->u.hdr.unk_4) {
        if (lbl_10_bss_C == 0) {
            fn_10_B2C8_start();
        }
        return 1;
    }
    return 0;
}
/* fzgx:end fn_10_B2C8 */

/* fzgx:begin fn_10_BD64 */
#define SEL_MAX(x, y) ((x) > (y) ? (x) : (y))

void fn_10_BD64(SelState *self) {
    s32 value;

    switch (self->unk_0) {
    case 1:
    case 11:
        self->unk_4 = 1;
        value = 30;
        if (self->unk_94 & 0x2) {
            value = lbl_10_bss_4938E;
        }
        self->unk_6 = value;
        break;
    case 0:
        if (lbl_1_bss_8B3A0.unk_94 & 0x200) {
            self->unk_6 = SEL_MAX(1, SEL_MAX(self->unk_6, SEL_MAX(self->unk_4, 1)));
        } else {
            self->unk_6 = self->unk_4;
        }
        break;
    case 2:
        self->unk_4 = 1;
        self->unk_6 = 1;
        break;
    case 3:
        self->unk_4 = 1;
        self->unk_6 = 1;
        break;
    case 9:
        self->unk_6 = 30;
        self->unk_4 = 1;
        self->unk_8 = 1;
        break;
    case 10:
        self->unk_4 = 1;
        self->unk_6 = 1;
        self->unk_8 = 1;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    default:
        break;
    }

    if (self->unk_4 <= 1) {
        self->unk_94 |= 0x20000000;
        return;
    }
    self->unk_94 &= 0xDFFFFFFF;
    if (self->unk_4 == 2) {
        self->unk_94 |= 0x00040000;
        return;
    }
    self->unk_94 &= ~0x00040000;
}
/* fzgx:end fn_10_BD64 */

/* fzgx:begin fn_10_BEF0 */
void fn_10_BEF0(SelState *state) {
}
/* fzgx:end fn_10_BEF0 */

/* fzgx:begin fn_10_BEF4 */
void fn_10_BEF4(SelState *state) {
}
/* fzgx:end fn_10_BEF4 */

/* fzgx:begin fn_10_BEF8 */
#define SEL_MAX(x, y) ((x) > (y) ? (x) : (y))

void fn_10_BEF8(fn_10_BEF8_SelState *state) {
    s32 value;

    switch (state->unk0) {
    case 1:
    case 11:
        state->field4 = 1;
        value = 30;
        if (state->flags & 0x2) {
            value = lbl_10_bss_4938E;
        }
        state->field6 = value;
        break;
    case 0:
        if ((*(fn_10_BEF8_SelGlobal *)&lbl_1_bss_8B3A0.unk_0).flags & 0x200) {
            state->field6 = SEL_MAX(1, SEL_MAX(state->field6, SEL_MAX(state->field4, 1)));
        } else {
            state->field6 = state->field4;
        }
        break;
    case 2:
        state->field4 = 1;
        state->field6 = 1;
        break;
    case 3:
        state->field4 = 1;
        state->field6 = 1;
        break;
    case 9:
        state->field6 = 30;
        state->field4 = 1;
        state->field8 = 1;
        break;
    case 10:
        state->field4 = 1;
        state->field6 = 1;
        state->field8 = 1;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    default:
        break;
    }

    if (state->field4 <= 1) {
        state->flags |= 0x20000000;
        return;
    }
    state->flags &= 0xDFFFFFFF;
    if (state->field4 == 2) {
        state->flags |= 0x00040000;
        return;
    }
    state->flags &= ~0x00040000;
}
/* fzgx:end fn_10_BEF8 */

/* fzgx:begin fn_10_C084 */
#define SEL_MAX(x, y) ((x) > (y) ? (x) : (y))

void fn_10_C084(fn_10_C084_SelState *state) {
    int value;

    switch (state->value) {
    case 1:
    case 11:
        state->minimum = 1;
        value = 30;
        if (state->flags & 0x2) {
            value = *(signed char *)&(*(unsigned char *)(&lbl_10_bss_4938E));
        }
        state->maximum = value;
        break;
    case 0:
        if ((*(fn_10_C084_SelGlobal *)&lbl_1_bss_8B3A0.unk_0).flags & 0x200) {
            state->maximum = SEL_MAX(1, SEL_MAX(state->maximum, SEL_MAX(state->minimum, 1)));
        } else {
            state->maximum = state->minimum;
        }
        break;
    case 2:
        state->minimum = 1;
        state->maximum = 1;
        break;
    case 3:
        state->minimum = 1;
        state->maximum = 1;
        break;
    case 9:
        state->maximum = 30;
        state->minimum = 1;
        state->extra = 1;
        break;
    case 10:
        state->minimum = 1;
        state->maximum = 1;
        state->extra = 1;
        break;
    default:
        break;
    }

    if (state->minimum <= 1) {
        state->flags |= 0x20000000;
        return;
    }
    state->flags &= 0xDFFFFFFF;
    if (state->minimum == 2) {
        state->flags |= 0x00040000;
        return;
    }
    state->flags &= ~0x00040000;
}
/* fzgx:end fn_10_C084 */

/* fzgx:begin fn_10_C210 */
void fn_10_C210(fn_10_C210_SelOwner *owner, s16 index) {
    fn_10_C210_SelEntry *entry = (fn_10_C210_SelEntry *)owner->entries + (short)(index - 0xE);
    entry->value = 0;
    fn_80008BEC((unsigned char *)entry + 0x24, 0, 0x70);
}
/* fzgx:end fn_10_C210 */

/* fzgx:begin fn_10_C258 */
s16 fn_10_C258(fn_10_C258_SelContext *self, s32 index) {
    return *(s16 *)(self->entries + (s16)(index - 14) * 0x94 + 0x14);
}
/* fzgx:end fn_10_C258 */

/* fzgx:begin fn_10_C274 */
void fn_10_C274(fn_10_C274_SelObject *object, int index) {
    index = (s16)(index - 0xe);
    *(s16 *)(object->entries + index * 0x94 + 0x14) += 1;
}
/* fzgx:end fn_10_C274 */

/* fzgx:begin fn_10_C298 */
void fn_10_C298(fn_10_C298_SelObject *self, int index) {
    s16 *value = (s16 *)(self->entries + (s16)(index - 0xe) * 0x94 + 0x14);
    (*value)--;
}
/* fzgx:end fn_10_C298 */

/* fzgx:begin fn_10_C2BC */
void fn_10_C2BC(void) {
    u32 value;

    value = ((u32)fn_1_4630(lbl_801A6410, 0x20700, lbl_10_data_57C, 0x1766));
    (*(u32 (*)[2])&lbl_10_bss_5565C)[0] = value;
    fn_1_130EE8(lbl_10_bss_49384, lbl_10_bss_49388);
    lbl_10_bss_14 = (-1);
}
/* fzgx:end fn_10_C2BC */

/* fzgx:begin fn_10_C328 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_C328(void) {
    s32 v;
    s16 dir;

    if (fn_1_1310E0() != 0) {
        return;
    }

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    {
        s32 ok;
        if (((*(GState *)&lbl_1_bss_8B3A0.unk_0).unk_140 & 0x80000000)
            && !((*(GState *)&lbl_1_bss_8B3A0.unk_0).unk_140 & 0x40000000)
            && !((*(GState *)&lbl_1_bss_8B3A0.unk_0).unk_94 & 0x8)) {
            ok = 1;
        } else if (fn_1_4C10() != 0) {
            ok = 1;
        } else {
            ok = 0;
        }
        if (ok != 0) {
            return;
        }
    }

    v = lbl_10_bss_14;
    if (v != -1) {
        lbl_10_bss_14 = (-1);
        lbl_1_bss_96A = v;
        return;
    }

    if (lbl_10_bss_55660 != 0) {
        s16 a = lbl_10_bss_A;
        lbl_10_bss_55660 = 0;
        if (a != 0) {
            lbl_10_bss_14 = (0x14);
            fn_1_1280(1);
        } else {
            lbl_10_bss_14 = (0x10);
            fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
            lbl_10_bss_51744 = 0;
        }
        fn_1_12F10C((*(u32 (*)[74736])&(*(u32 (*)[74736])&lbl_10_bss_3C0)));
    } else {
        s16 a = lbl_10_bss_A;
        lbl_10_bss_55660 = 1;
        dir = 4;
        if (a & 1) {
            lbl_10_bss_A = a & ~1;
            dir = 0;
        } else if (a & 2) {
            lbl_10_bss_A = a & ~2;
            dir = 1;
        }
        fn_1_131084(lbl_10_bss_5565C, dir);
    }
}
/* fzgx:end fn_10_C328 */

/* fzgx:begin fn_10_C49C */
void fn_10_C49C(void) {
    if (fn_1_1317B4() == 0) {
        if (fn_1_B7C5C() == 0) {
            fn_80008BA8((*(u32 (*)[74736])&(*((Obj_10_bss_3C0 *)&lbl_10_bss_3C0))), (void *)((*(u32 (*)[2])&lbl_10_bss_5565C)[0]), 0x20700);
            lbl_10_bss_4938F = 1;
        } else {
            lbl_10_bss_4938F = 0;
        }
    }
    if (fn_1_1317B4() == 1) {
        if (fn_1_B7C5C() == 0) {
            fn_80008BA8((*(u32 (*)[74736])&(*((Obj_10_bss_3C0 *)&lbl_10_bss_3C0))) + 0x81c0, (void *)((*(u32 (*)[2])&lbl_10_bss_5565C)[0]), 0x20700);
            (*(u8 (*)[16])&(*((Obj_10_bss_49390 *)&lbl_10_bss_49390)))[0] = 1;
        } else {
            (*(u8 (*)[16])&(*((Obj_10_bss_49390 *)&lbl_10_bss_49390)))[0] = 0;
        }
    }
    fn_1_131004();
    fn_1_46B4(lbl_801A6410, (void *)((*(u32 (*)[2])&lbl_10_bss_5565C)[0]), lbl_10_data_57C, 0x17a0);
}
/* fzgx:end fn_10_C49C */

/* fzgx:begin fn_10_C594 */
void fn_10_C594(void) {
    // The retail loop checks its continuation conditions before entering the body.
    goto check;
body:
    fn_1_451E4();
    fn_1_3308();
    fn_1_D3214();
    VIWaitForRetrace();
check:
    if (fn_1_467F4() != 0) {
        goto body; // Continue the irreducible retail loop.
    }
    if (fn_1_13018() != 0) {
        goto body; // Continue the irreducible retail loop.
    }
    fn_8006FDEC();
}
/* fzgx:end fn_10_C594 */

/* fzgx:begin fn_10_C5E0 */
void fn_10_C5E0(void **handle) {
    u32 level;

    level = fn_1_4404();
    if (*handle != (void *)-1) {
        fn_1_46B4(lbl_801A6410, *handle, lbl_10_data_57C, 0x181E);
        *handle = (void *)-1;
    }
    fn_80008E84(level);
}
/* fzgx:end fn_10_C5E0 */

/* fzgx:begin fn_10_C654 */
void fn_10_C654(u32 *value) {
    *value = fn_1_46C60();
}

u32 lbl_10_bss_55664 = 0;
/* fzgx:end fn_10_C654 */

/* fzgx:begin fn_10_C684 */
u32 fn_10_C684(void) {
    return lbl_10_bss_55668;
}
/* fzgx:end fn_10_C684 */

/* fzgx:begin fn_10_C694 */
u8 fn_10_C694(void) {
    return lbl_10_bss_5566C;
}
/* fzgx:end fn_10_C694 */

/* fzgx:begin fn_10_C6A4 */
void fn_10_C6A4(void) {
    struct { u8 type; u8 pad[3]; u32 code; u32 unk_8; void *data; u8 rest[20]; } loc_8;
    if (fn_1_B7C00() != 0) return;
    if ((lbl_1_bss_7180C) != 0 && fn_1_B7E98(1) != 0) {
        if (__rlwnm(lbl_10_bss_55664, 5, 31, 31)) return;
        if (__rlwnm(lbl_10_bss_55664, 6, 31, 31)) return;
        if ((s32)lbl_10_bss_55664 == 0) {
            lbl_10_bss_55664 = lbl_10_bss_55664 | 0x80000000;
        } else {
            switch (__cntlzw(lbl_10_bss_55664)) {
            case 0:
                if (fn_1_B7C6C(1) == 0) {
                    lbl_10_bss_5566C = 1;
                    fn_80008BEC(&loc_8, 0, 36);
                    loc_8.type = 1;
                    loc_8.code = 0xA004;
                    loc_8.data = &lbl_1_bss_718E0;
                    fn_1_AA6D8(2, 4, &loc_8);
                    lbl_10_bss_55664 &= 0x7FFFFFFF;
                    lbl_10_bss_55664 |= 0x20000000;
                }
                break;
            case 2:
                lbl_10_bss_55668 = fn_1_B7CD4();
                fn_1_F79C8();
                if (fn_1_B7C5C() == 0) {
                    fn_80008BEC(&loc_8, 0, 36);
                    loc_8.type = 3;
                    loc_8.code = 0xA004;
                    loc_8.data = (u8 *)&(*(u32 (*)[74736])&(*((Obj_10_bss_3C0 *)&lbl_10_bss_3C0))) + 0x20700;
                    fn_1_AA6D8(2, 4, &loc_8);
                    lbl_10_bss_55664 &= 0xDFFFFFFF;
                    lbl_10_bss_55664 |= 0x10000000;
                }
                break;
            case 3:
                lbl_10_bss_55664 = lbl_10_bss_55664 & 0xEFFFFFFF;
                lbl_10_bss_55664 |= 0x08000000;
                break;
            }
        }
    } else {
        lbl_10_bss_55664 = 0;
        lbl_10_bss_5566C = 0;
        lbl_10_bss_55664 |= 0x80000000;
        fn_80008BEC(&(*(u32 (*)[74736])&(*((Obj_10_bss_3C0 *)&lbl_10_bss_3C0))), 0, 0x40E00);
        lbl_10_bss_55668 = 0;
        fn_1_B7F24();
    }
}
/* fzgx:end fn_10_C6A4 */

/* fzgx:begin fn_10_C8A8 */
void fn_10_C8A8(void) {
    fn_1_4A00(1, 0xf, lbl_10_bss_49388);
    fn_1_12F1E8(0x1e0);
}
/* fzgx:end fn_10_C8A8 */

/* fzgx:begin fn_10_C8E4 */
void fn_10_C8E4(void) {
    if (lbl_1_bss_7180C == 0) {
        fn_10_CEC4((*(u32 (*)[4])&lbl_10_bss_55670)[0]);
    } else if (fn_1_B7E98(1) == 0) {
        fn_10_CEC4((*(u32 (*)[4])&lbl_10_bss_55670)[0]);
    } else {
        lbl_1_bss_96A = 0x1c;
    }
}
/* fzgx:end fn_10_C8E4 */

/* fzgx:begin fn_10_C954 */
// fn_10_C954: empty in retail (single blr).
void fn_10_C954(void) {
}
/* fzgx:end fn_10_C954 */

/* fzgx:begin fn_10_C958 */
void fn_10_C958(void) {
    Fn10C958Data data;

    fn_80008BEC(&data, 0, 0x24);
    data.unk00 = 1;
    data.unk04 = 0x2004;
    data.unk0c = &lbl_1_bss_718E0;
    fn_1_AA6D8(2, 4, &data);
}
/* fzgx:end fn_10_C958 */

/* fzgx:begin fn_10_C9B0 */
void fn_10_C9B0(void) {
    if (!fn_1_B7C00()) {
        if (!fn_1_B7C5C()) {
            fn_1_F79C8();
        }
        lbl_1_bss_96A = 0x1d;
    }
}
/* fzgx:end fn_10_C9B0 */

/* fzgx:begin fn_10_C9F4 */
// fn_10_C9F4: empty in retail (single blr).
void fn_10_C9F4(void) {
}
/* fzgx:end fn_10_C9F4 */

/* fzgx:begin fn_10_C9F8 */
void fn_10_C9F8(void) {
    struct {
        u8 kind;
        u8 pad[3];
        u32 value;
        u8 pad2[4];
        u32 buffer;
        u8 tail[0x18];
    } local;

    fn_80008BEC(&local, 0, 0x24);
    local.kind = 3;
    local.value = 0x2004;
    local.buffer = (u32)((u8 *)(*(u32 (*)[74736])&(*((Obj_10_bss_3C0 *)&lbl_10_bss_3C0))) + 0x20700);
    fn_1_AA6D8(2, 1, &local);
}
/* fzgx:end fn_10_C9F8 */

/* fzgx:begin fn_10_CA58 */
void fn_10_CA58(void) {
    if (!fn_1_B7C00()) {
        fn_10_CEC4((*(u32 (*)[4])&lbl_10_bss_55670)[0]);
    }
}
/* fzgx:end fn_10_CA58 */

/* fzgx:begin fn_10_CA90 */
// fn_10_CA90: empty in retail (single blr).
void fn_10_CA90(void) {
}
/* fzgx:end fn_10_CA90 */

/* fzgx:begin fn_10_CA94 */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

void fn_10_CA94(void) {
    fn_1_435C( (lbl_10_bss_49388));
    lbl_10_bss_51740 = (fn_1_3F8C( ((*(char (*)[18])&"SelMagCardSucceedDisp")), fn_10_1B660, (0), 8));
    fn_1_12F1E8(480);
    fn_1_4A00(1, lbl_10_bss_4938C, (lbl_10_bss_49388));
    lbl_10_bss_51744 = 0;
    lbl_10_bss_14 = (-1);
}
/* fzgx:end fn_10_CA94 */

/* fzgx:begin fn_10_CB20 */
void fn_10_CB20(void) {
    u32 flags;
    s32 ready;
    s16 i;
    u8 idx;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }
    flags = lbl_1_bss_8B3A0.unk_140;
    if ((flags & 0x80000000) != 0 && (flags & 0x40000000) == 0 && (lbl_1_bss_8B3A0.unk_94 & 8) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }
    if (ready != 0) {
        return;
    }
    if (lbl_10_bss_14 != -1) {
        lbl_1_bss_96A = lbl_10_bss_14;
        lbl_10_bss_14 = -1;
        return;
    }
    for (i = 0; i < 4; i++) {
        if (lbl_1_bss_9C8[i].unk_a != -1 && __rlwnm(lbl_1_bss_8B3A0.unk_98, (i + 1) & 31, 31, 31) &&
            ((lbl_1_bss_9F8[lbl_1_bss_8B3A0.unk_9E].unk_8 >> 8) & 1)) {
            fn_1_12F150(i, 2, 1);
        }
    }
    if ((lbl_1_bss_9F8[lbl_1_bss_8B3A0.unk_9E].unk_8 >> 8) & 1) {
        fn_1_12F1E8(0);
    }
    for (i = 0; i < 4; i++) {
        if (lbl_1_bss_9C8[i].unk_a != -1 && __rlwnm(lbl_1_bss_8B3A0.unk_98, (i + 1) & 31, 31, 31) &&
            ((lbl_1_bss_9F8[lbl_1_bss_8B3A0.unk_9E].unk_8 >> 12) & 1)) {
            fn_1_12F150(i, 2, 1);
        }
    }
    idx = lbl_1_bss_8B3A0.unk_9E;
    if (((lbl_1_bss_9F8[idx].unk_8 >> 12) & 1) || fn_1_12F228() != 0) {
        lbl_10_bss_14 = 25;
        fn_1_12F1E8(0);
        fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        if (lbl_10_bss_14 == 14) {
            lbl_1_bss_6EAB4 |= 0x24;
        }
    }
}
/* fzgx:end fn_10_CB20 */

/* fzgx:begin fn_10_CD90 */
void fn_10_CD90(void) {
    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
}
/* fzgx:end fn_10_CD90 */

/* fzgx:begin fn_10_CDE8 */
void fn_10_CDE8(void) {
    fn_1_435C(lbl_10_bss_49388);
    lbl_10_bss_51740 = fn_1_3F8C("SelSinglecheckDisp", fn_10_13E18, 0, 8);
    fn_1_4A00(1, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
}
/* fzgx:end fn_10_CDE8 */

/* fzgx:begin fn_10_CE5C */
void fn_10_CE5C(void) {
    lbl_1_bss_96A = 0xf;
}
/* fzgx:end fn_10_CE5C */

/* fzgx:begin fn_10_CE6C */
void fn_10_CE6C(void) {
    if ((lbl_10_bss_51740) != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = (-1);
    }
}
/* fzgx:end fn_10_CE6C */

/* fzgx:begin fn_10_CEC4 */
void fn_10_CEC4(u32 flags) {
    u32 shift;
    u16 value;

    shift = 1;
    if (__rlwnm(flags, shift, 31, 31)) {
        value = 0x17;
    } else {
        shift = 2;
        if (__rlwnm(flags, shift, 31, 31)) {
            value = 0x19;
        } else {
            shift = 3;
            if (__rlwnm(flags, shift, 31, 31)) {
                value = 0x15;
            } else {
                shift = 4;
                if (__rlwnm(flags, shift, 31, 31) ||
                    (shift = 5, __rlwnm(flags, shift, 31, 31))) {
                    value = 0x0e;
                } else {
                    value = 0x17;
                }
            }
        }
    }
    lbl_1_bss_96A = value;
}
/* fzgx:end fn_10_CEC4 */

/* fzgx:begin fn_10_CF30 */
void fn_10_CF30(u32 shift) {
    (*(u32 (*)[4])&lbl_10_bss_55670)[0] |= (1u << 31) >> shift;
}
/* fzgx:end fn_10_CF30 */

/* fzgx:begin fn_10_CF50 */
void fn_10_CF50(void) {
    SelScene *scene = lbl_10_data_908;

    scene += lbl_1_bss_962 - 0xd;

    lbl_1_bss_71688 = scene->main;
    lbl_1_bss_7168C = scene->disp;
    scene->init();
}
/* fzgx:end fn_10_CF50 */

/* fzgx:begin fn_10_CFAC */
void fn_10_CFAC(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    (*((struct fn_10_CFAC_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0)).unk_140 = 0;
    (*((struct fn_10_CFAC_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0)).unk_140 |= 0x80000000;
    (*((struct fn_10_CFAC_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0)).unk_140 |= arg3;
    (*((struct fn_10_CFAC_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0)).unk_144 = arg0;
    (*((struct fn_10_CFAC_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0)).unk_146 = arg1;
    (*((struct fn_10_CFAC_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0)).unk_148 = arg2;
}
/* fzgx:end fn_10_CFAC */

/* fzgx:begin fn_10_CFDC */
void fn_10_CFDC(void) {
    fn_10_CFDC_SelState *state = &(*((fn_10_CFDC_SelState *)&lbl_1_bss_8B3A0));

    if ((state->flags & 0x80000000u) == 0) {
        return;
    }

    state->value += state->step;
    do {
        if (state->step > 0) {
            if (state->value >= state->limit) {
                break;
            }
        }
        if (state->step >= 0) {
            return;
        }
        if (state->value > (*((fn_10_CFDC_SelState *)&lbl_1_bss_8B3A0)).limit) {
            return;
        }
    } while (0);
    state->flags = 0;
}

extern void fn_1_12B4(void);
extern void fn_1_12FC(void);
extern void fn_1_1300(void);

SelScene lbl_10_data_908[] = {
    { "SMD_SEL_TOP", fn_1_12B4, fn_1_12FC, fn_1_1300 },
    { "SMD_SEL_MODE", fn_10_12D8, fn_10_1544, fn_10_1F28 },
    { "SMD_SEL_COURSE", fn_10_1F9C, fn_10_21EC, fn_10_3268 },
    { "SMD_SEL_MACHINE", fn_10_3350, fn_10_3F54, fn_10_436C },
    { "SMD_SEL_COM", fn_10_5148, fn_10_51BC, fn_10_51CC },
    { "SMD_SEL_CONFIG", fn_10_5230, fn_10_6518, fn_10_7130 },
    { "SMD_SEL_MAGCARD", fn_10_7320, fn_10_73AC, fn_10_757C },
    { "SMD_SEL_CUST_LOAD", fn_10_C2BC, fn_10_C328, fn_10_C49C },
    { "SMD_SEL_CHALLNGER_STANDBY", fn_10_8538, fn_10_8600, fn_10_8800 },
    { "SMD_SEL_CHALLNGER_WAIT", fn_10_8870, fn_10_8930, fn_10_8AAC },
    { "SMD_SEL_MAGCARD_BUY", fn_10_7FC0, fn_10_804C, fn_10_82BC },
    { "SMD_SEL_MAG_NAME_INPUT", fn_10_8314, fn_10_83C0, fn_10_84DC },
    { "SMD_SEL_MAGCARD_DATA", fn_10_75D4, fn_10_7A10, fn_10_7E84 },
    { "SMD_SEL_CAUTION", fn_10_8B0C, fn_10_8BB8, fn_10_8D90 },
    { "SMD_SEL_MEMCARD_CHECK", fn_10_C8A8, fn_10_C8E4, fn_10_C954 },
    { "SMD_SEL_GAMEDATA_LOAD", fn_10_C958, fn_10_C9B0, fn_10_C9F4 },
    { "SMD_SEL_CUSTDATA_LOAD", fn_10_C9F8, fn_10_CA58, fn_10_CA90 },
    { "SMD_SEL_MAGCARD_SUCCEED", fn_10_CA94, fn_10_CB20, fn_10_CD90 },
    { "SMD_SEL_CARD_ALL", fn_10_8DFC, fn_10_8F0C, fn_10_9154 },
    { "SMD_SEL_SINGLECHECK", fn_10_CDE8, fn_10_CE5C, fn_10_CE6C },
    { "SMD_SEL_RECORD", fn_10_4790, fn_10_4838, fn_10_4A84 },
    { "SMD_SEL_START_YOUR_ENGINE", fn_10_4568, fn_10_4600, fn_10_472C },
    { "SMD_SEL_BOTTOM", fn_1_12B4, fn_1_12FC, fn_1_1300 },
};
/* fzgx:end fn_10_CFDC */
