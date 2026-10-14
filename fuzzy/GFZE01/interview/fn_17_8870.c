/* Non-matching: best partial attempt (98.76% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/interview/interview.h"
extern f32 lbl_17_rodata_0[];
extern u32 lbl_1_rodata_26F8[];
extern u8 lbl_17_bss_FA[];
extern u32 lbl_801A66B4;
extern void fn_1_520A0(void);
extern void fn_1_52070(u32);
extern void fn_1_4F734(void *);
extern void fn_1_141360(u32, s32, s32, s32, f32, f32);
extern void fn_1_520CC(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4AE0C(const char *, ...);
typedef struct { u32 value; } Index;
typedef struct { u8 pad[16]; char *text; u32 tail; } Entry24;
typedef struct { u8 pad[12]; char *text; } Entry16;
typedef struct {
    u8 pad0[0x282c];
    char *table1[24];
    char *table2[23];
    Entry24 table3[8];
    u8 pad1[0x10];
    Entry16 table4[1];
    u8 pad2[0x44d4 - 0x29c8];
    char format1[4];
    char format2[8];
    char format3[4];
} InterviewData;
typedef struct {
    u32 word04;
    f32 float08;
    f32 float0c;
    f32 float10;
    f32 float14;
    f32 float18;
    u32 word1c[5];
    f32 float30;
    u32 word34;
    u32 word38[9];
} InterviewParams;
static inline Entry24 *fn_17_8870_array_read(Entry24 *array) { return array; }
#pragma opt_propagation off
static inline Entry16 *fn_17_8870_array_read_(Entry16 *array) { return array; }
#pragma opt_dead_assignments off
static inline char * *fn_17_8870_array_read__(char * *array) { return array; }
static inline Entry24 * fn_17_8870_read_pointer(InterviewData * owner) { return owner->table3; }
#pragma opt_strength_reduction off
u32 fn_17_8870(f32 value) {
    f32 offset;
    InterviewData * data;
    f32 lab_t0;
    f32 *rodata = lbl_17_rodata_0;
    InterviewParams params;
    data = (InterviewData *)((u8 *)&lbl_17_data_0 + 0x60000);
    if (lbl_17_bss_FA[0]) offset = rodata[170];
    else offset = rodata[8];
    fn_1_520A0();
    fn_1_52070(320);
    params = *(InterviewParams *)lbl_1_rodata_26F8;
    params.word04 = 0xa105;
    params.float08 = rodata[40];
    params.float0c = rodata[171] + offset;
    params.float10 = rodata[108];
    params.float14 = rodata[6];
    params.float18 = rodata[6];
    params.float30 = value;
    params.word34 = 10;
    fn_1_4F734(&params.word04);
    fn_1_141360(4, (s32)params.float08, (s32)params.float0c, 2, rodata[6], value);
    fn_1_520CC();
    fn_1_49410();
    fn_1_494DC(6);
    fn_1_495B0(0xc0000000);
    fn_1_495C8(1);
    fn_1_49590(rodata[15]);
    lab_t0 = rodata[172];
    fn_1_4955C(lab_t0, rodata[172]);
    fn_1_496FC(rodata[40], rodata[173] + offset);
    fn_1_495A0(value);
    fn_1_4AE0C(&data->format1[0], fn_17_8870_array_read__(data->table1)[((Index *)&lbl_801A66B4)->value]);
    offset = rodata[174] + offset;
    fn_1_496FC(rodata[40], offset);
    lab_t0 = rodata[158];
    fn_1_4955C(lab_t0, rodata[158]);
    fn_1_4AE0C(&data->format1[0], fn_17_8870_array_read__(data->table2)[((Index *)&lbl_801A66B4)->value]);
    fn_1_496FC(rodata[40], offset);
    lab_t0 = rodata[158];
    fn_1_4955C(lab_t0, rodata[158]);
    if (lbl_17_bss_FA[0]) {
        fn_1_496FC(rodata[40], rodata[175]);
        lab_t0 = rodata[122];
        fn_1_4955C(lab_t0, rodata[122]);
        fn_1_4AE0C(&data->format2[0], fn_17_8870_array_read(fn_17_8870_read_pointer(data))[((Index *)&lbl_17_bss_54)->value].text);
        fn_1_496FC(rodata[40], rodata[176]);
        lab_t0 = rodata[122];
        fn_1_4955C(lab_t0, rodata[122]);
        fn_1_4AE0C(&data->format3[0], fn_17_8870_array_read_(data->table4)[((Index *)&lbl_17_bss_54)->value].text);
    } else {
        fn_1_496FC(rodata[40], rodata[177]);
        lab_t0 = rodata[122];
        fn_1_4955C(lab_t0, rodata[122]);
        fn_1_4AE0C(&data->format2[0], fn_17_8870_array_read(fn_17_8870_read_pointer(data))[((Index *)&lbl_17_bss_54)->value].text);
    }

}
#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset

#pragma opt_propagation reset

