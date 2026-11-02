#include "types.h"
#include "font.h"

struct ProfileMenuState {
    u8 pad0[0xA];
    s16 language;
    u8 padC[0x40];
    u32 flags;
    u8 pad50[2];
    s16 timer;
    s16 duration;
};
extern struct ProfileMenuState lbl_1_bss_8B614;

typedef struct {
    const char *name;
    f32 unk_4;
    u8 fields_8[0xAC];
} MachineParameterRecord;
extern MachineParameterRecord lbl_1_data_28060[];
extern s32 lbl_1_data_416B8[][3];

typedef struct {
    char unk_0[6][0x40];
    char unk_180[6][0x40];
} fn_16_3BCC_lbl_16_bss_A8_entry;
extern fn_16_3BCC_lbl_16_bss_A8_entry *lbl_16_bss_A8[];

extern const FontDrawPacket lbl_1_rodata_26F8;

extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_4955C(f32, f32);
extern f32 fn_1_4B068(const char *);
extern s32 fn_1_A5DC4(void);
extern void fn_1_50164(FontDrawPacket *, f32, f32, f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49514(u32 *);
extern int fn_1_14EE00(s16, void *, s16);

/* the retail TU's .data objects this function uses, at their retail offsets, so MWCC addresses them off one
 * section base; the table's contents do not matter here (nonzero so it stays in .data), and the string
 * literals below land after the last gap, at 0x688, 0x690 and 0x694 */
char fzgx_obj_lbl_16_data_82DB0[4] = "NO.";
u8 fzgx_pool_gap_82DB4[0x174] = {1};
char *fzgx_obj_lbl_16_data_82F28[17][6] = {{(char *)1}};
u8 fzgx_pool_gap_830C0[0x378] = {1};

#pragma push
#pragma force_active on
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_rodata_58[2] = {0xFFFF0000, 0x41A00000};
static void fzgx_pool_primer_a(void) {
    volatile f32 f; /* fzgx-allow: S2 pool primer sink */
    f = 10.0f;
}
static const u32 fzgx_pool_rodata_64[5] = {0x3F19999A, 0x43E40000, 0x3E000000, 0x40A00000, 0x3FB8E38E};
static void fzgx_pool_primer_b(void) {
    volatile f32 f; /* fzgx-allow: S2 pool primer sink */
    f = 1.0f;
}
static const u32 fzgx_pool_rodata_7C[2] = {0x42380000, 0x42500000};
static void fzgx_pool_primer_c(void) {
    volatile f32 f; /* fzgx-allow: S2 pool primer sink */
    f = 0.5f;
}
static const u32 fzgx_pool_rodata_88[6] = {0x428E0000, 0x41B00000, 0x42C40000, 0x42BAC6C7, 0x3F44C4C5, 0x00000000};
static void fzgx_pool_primer_d(void) {
    volatile f64 d; /* fzgx-allow: S2 pool primer sink */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_rodata_A8[1] = {0xFFFF0000};
static void fzgx_pool_primer_e(void) {
    volatile f32 f; /* fzgx-allow: S2 pool primer sink */
    f = 0.0f;
}
static const u32 fzgx_pool_rodata_B0[6] = {0x42000000, 0x41E00000, 0x428A0000, 0x43A90000, 0x43FC0000, 0x41C00000};
static void fzgx_pool_primer_f(void) {
    volatile f32 f; /* fzgx-allow: S2 pool primer sink */
    f = 8.0f;
}
static const u32 fzgx_pool_rodata_CC[27] = {0x3F471C72, 0x429E0000, 0x43AB8000, 0x431B0000, 0x43B68000, 0xFFFF0000, 0x42300000, 0x43780000, 0x40C00000, 0xFFFF0000, 0x43F00000, 0x430E0000, 0x436C0000, 0x42CC0000, 0x42D60000, 0x3F200000, 0x430D0000, 0x40E00000, 0x43360B61, 0x43340000, 0x43060000, 0x3DCCCCCD, 0x3F40C0C1, 0x3E99999A, 0x43B40000, 0x43300000, 0x00000000};
#pragma pop

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define clamp01(v) ((v) < 0.0f ? 0.0f : ((v) > 1.0f ? 1.0f : (v)))

static inline char *fn_16_3BCC_array_read(char **array, s32 index) {
    return array[index];
}

/* row `row` of the .data 0x82F28 text table, in the current language */
#define LABEL(row) fn_16_3BCC_array_read(fzgx_obj_lbl_16_data_82F28[row], lbl_1_bss_8B614.language)

/* a part letter of .data 0x416B8 (1 A to 5 E) as the odd grade fn_1_14EE00 prints; any other value keeps the
 * previous grade */
#define SET_GRADE(letter)  \
    switch (letter) {      \
    case 0:                \
        grade = 1;         \
        break;             \
    case 1:                \
        grade = 1;         \
        break;             \
    case 2:                \
        grade = 3;         \
        break;             \
    case 3:                \
        grade = 5;         \
        break;             \
    case 4:                \
        grade = 7;         \
        break;             \
    case 5:                \
        grade = 9;         \
        break;             \
    }

void fn_16_3BCC(s16 arg0, s16 x, s16 y) {
    f32 top;
    FontDrawPacket packet;
    f32 labelWidth;
    f32 valueWidth;
    f32 width;
    f32 alpha;
    f32 left;
    char buffer[32];
    f32 innerLeft;
    f32 innerTop;
    f32 t;
    f32 half;
    f32 height;
    s16 grade;
    s16 shift;
    s32 h;

    shift = 0;
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4955C(0.5f, 0.5f);
    labelWidth = MAX(fn_1_4B068(LABEL(11)), fn_1_4B068(LABEL(12)));
    labelWidth = MAX(labelWidth, fn_1_4B068(LABEL(13)));
    labelWidth = MAX(labelWidth, fn_1_4B068(LABEL(14)));
    labelWidth = MAX(labelWidth, fn_1_4B068(LABEL(15)));
    labelWidth = MAX(labelWidth, fn_1_4B068(LABEL(16)));
    valueWidth = MAX(fn_1_4B068(lbl_16_bss_A8[arg0]->unk_180[lbl_1_bss_8B614.language]),
                     fn_1_4B068(lbl_16_bss_A8[arg0]->unk_0[lbl_1_bss_8B614.language]));
    valueWidth = MAX(valueWidth, fn_1_4B068("1000kg"));
    if ((s8)fn_1_A5DC4()) {
        shift = 94;
    }
    width = 10.0f + (10.0f + (19.0f + (labelWidth + valueWidth)));
    height = 92.0f;
    if (lbl_1_bss_8B614.flags & 0x80000000) {
        if (lbl_1_bss_8B614.flags & 0x10000000) {
            t = clamp01((f32)lbl_1_bss_8B614.timer / ((f32)lbl_1_bss_8B614.duration / 2.0f));
            half = (f32)lbl_1_bss_8B614.duration / 2.0f;
            h = (s32)(17.0f + (f32)(75.0f * t));
            alpha = clamp01(((f32)lbl_1_bss_8B614.timer - half) / half);
        } else if (lbl_1_bss_8B614.flags & 0x08000000) {
            half = (f32)lbl_1_bss_8B614.duration / 2.0f;
            t = clamp01(((f32)lbl_1_bss_8B614.timer - half) / half);
            h = (s32)(17.0f + (f32)(75.0f * (1.0f - t)));
            alpha = 1.0f - clamp01((f32)lbl_1_bss_8B614.timer / half);
        } else {
            h = (s32)height;
            alpha = 1.0f;
        }
    } else {
        h = (s32)height;
        alpha = 1.0f;
    }
    packet = lbl_1_rodata_26F8;
    packet.image = 12;
    packet.x = (f32)shift + (left = (f32)x - width);
    packet.y = top = (f32)y - height;
    packet.z = 10.0f;
    fn_1_50164(&packet, width, (f32)(s16)h, 8.0f, 8.0f);
    fn_1_495A0(alpha);
    innerTop = 10.0f + top;
    innerLeft = 10.0f + left;
    fn_1_496FC((f32)shift + innerLeft, innerTop);
    fn_1_4AE0C("%s\n", LABEL(11));
    fn_1_4AE0C("%s\n", LABEL(12));
    fn_1_4AE0C("%s\n", LABEL(13));
    fn_1_4AE0C("%s\n", LABEL(14));
    fn_1_4AE0C("%s\n", LABEL(15));
    fn_1_4AE0C("%s\n", LABEL(16));
    fn_1_496FC((f32)shift + (19.0f + (labelWidth + innerLeft)), innerTop);
    fn_1_4AE0C("%s\n", lbl_16_bss_A8[arg0]->unk_180[lbl_1_bss_8B614.language]);
    fn_1_4AE0C("%s\n", lbl_16_bss_A8[arg0]->unk_0[lbl_1_bss_8B614.language]);
    fn_1_4AE0C("%4dkg\n", (s16)lbl_1_data_28060[arg0].unk_4);
    {
        u8 color[4] = {0xFF, 0xFF, 0x00, 0x00};
        fn_1_49514((u32 *)color);
    }
    SET_GRADE(lbl_1_data_416B8[arg0][0]);
    fn_1_4AE0C("%s\n", (const char *)fn_1_14EE00(grade, buffer, lbl_1_bss_8B614.language));
    SET_GRADE(lbl_1_data_416B8[arg0][1]);
    fn_1_4AE0C("%s\n", (const char *)fn_1_14EE00(grade, buffer, lbl_1_bss_8B614.language));
    SET_GRADE(lbl_1_data_416B8[arg0][2]);
    fn_1_4AE0C("%s\n", (const char *)fn_1_14EE00(grade, buffer, lbl_1_bss_8B614.language));
}
