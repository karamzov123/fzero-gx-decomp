/* Non-matching: best partial attempt (71.43% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/spline.h"

extern u16 fn_1_F2740(u32, u32);
extern const f64 lbl_1_rodata_7478;
extern const f64 lbl_1_rodata_7470;
extern char *strncpy(char *, const char *, unsigned long);
extern s32 lbl_801A66B4;

typedef struct {
    u32 time0;
    u32 time1;
    char name[16];
    u16 unk18;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
} SplineEntry;

typedef struct {
    SplineEntry entries[10];
    u32 unk140;
    u32 unk144;
    u8 pad148[0x10];
    s16 unk158;
    u8 unk15A;
    u8 unk15B;
    u8 unk15C;
    u8 unk15D;
    u8 unk15E;
    u8 unk15F;
    s16 unk160;
    u8 unk162;
    u8 unk163;
    u8 unk164;
    u8 unk165;
    u8 unk166;
    u8 unk167;
    u8 unk168;
} SplineTable;

#pragma opt_lifetimes on
static inline SplineEntry * fn_1_FA1D8_read_pointer(SplineTable * owner) { return owner->entries; }
void fn_1_FA1D8(u32 arg0, u32 arg1, SplineTable *out) {
    u8 *data;
    u8 *bytes;
    u32 h2;
    s32 i;
    u32 m1;
    u32 m2;
    u32 v;
    u32 h1;
    const char * lab_t1;

    data = lbl_1_data_3E910;
    (void) data;  /* fzgx: keeps the web at its definition */
    v = fn_1_F2740(arg0, arg1);
    m1 = (v >> 10) & 0x3FC;
    h1 = (v >> 18) & 0x3FC;
    h2 = (u32)((f32)((v >> 20) & 0xFF) * 1.5);
    m2 = (u32)((f64)(((0xFF) & ((v >> 12)))) * 1.5);

    if (m1 >= 60) { m1 -= 60; h1++; }
    if (m1 >= 60) { m1 -= 60; h1++; }
    if (m1 >= 60) { m1 -= 60; h1++; }
    if (m1 >= 60) { m1 -= 60; h1++; }
    if (m1 >= 60) { m1 -= 60; h1++; }
    if (m2 >= 60) { m2 -= 60; h2++; }
    if (m2 >= 60) { m2 -= 60; h2++; }
    if (m2 >= 60) { m2 -= 60; h2++; }

    out->unk160 = 0;
    out->unk162 = 6;
    out->unk165 = 50;
    out->unk164 = 6;
    out->unk166 = 0xFF;
    out->unk167 = 0xFF;
    out->unk168 = 0xFF;
    out->unk163 = 1;
    out->unk140 = 0x93B3E7;
    out->unk158 = 0;
    out->unk144 = 0;
    out->unk15A = 6;
    out->unk15C = 50;
    out->unk15B = 6;
    out->unk15D = 0xFF;
    out->unk15E = 0xFF;
    out->unk15F = 0xFF;

    bytes = data + 0x3E0;
    for (i = 0; i < 10; i++, bytes++) {
        out->entries[i].time0 = (h1 << 20) | (m1 << 12);
        fn_1_FA1D8_read_pointer(out)[i].time1 = (h2 << 20) | (m2 << 12);
        out->entries[i].unk1A = *bytes;
        out->entries[i].unk18 = 0;
        out->entries[i].unk1C = 50;
        out->entries[i].unk1B = *bytes;
        out->entries[i].unk1D = 0xFF;
        out->entries[i].unk1E = 0xFF;
        out->entries[i].unk1F = 0xFF;
        if (lbl_801A66B4 == 5) {
            lab_t1 = ((char **)(data + 0x4B0))[i];
            strncpy(out->entries[i].name, lab_t1, 16);
        } else {
            lab_t1 = ((char **)(data + 0x594))[i];
            strncpy(out->entries[i].name, lab_t1, 16);
        }
        m1++;
        if (m1 >= 60) { h1++; m1 -= 60; }
        m2++;
        if (m2 >= 60) { h2++; m2 -= 60; }
    }
}
#pragma opt_lifetimes reset

