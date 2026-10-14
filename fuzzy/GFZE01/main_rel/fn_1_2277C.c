/* Non-matching: best partial attempt (86.55% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

extern char *strncpy(char *, const char *, unsigned int);
extern void fn_1_22E8C(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern double fabs(double);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern void fn_1_22F90(void *, int);
extern void lbl_8006DB30(void);
extern const f32 lbl_1_rodata_840[7];

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u32 count;
    f32 value;
    Vec3 points;
    f32 scale_x;
    f32 scale_y;
    f32 scale_z;
    u8 pad20[0x24];
    f32 width;
    f32 height;
    u8 pad4c[0x10];
} Part;

typedef struct {
    Vec3 pos;
    u8 pad0c[0x18];
    f32 normal_x;
    f32 normal_y;
    f32 normal_z;
} Vertex;

typedef struct {
    u32 flags;
    u16 field04;
    u16 field06;
    f32 field08;
    u8 pad0c[0x30];
    char name[0x20];
    u8 pad5c[0x50];
    f32 field_ac;
    f32 field_b0;
    f32 field_b4;
    u8 padb8[0x170];
    f32 field228;
    u8 pad22c[0x18];
    Part parts[4];
    Vertex vertices[4];
    s8 field474;
    s8 field475;
    u8 pad476[0x10e];
    f32 max_length;
    f32 max_abs_x;
    u8 pad58c[4];
    u8 field590;
    u8 pad591[0x49];
    u16 field5da;
} ModelOut;

typedef struct {
    const char *name;
    u8 pad04[0x50];
    Vec3 points[8];
} ModelIn;

void fn_1_2277C(ModelOut *out, ModelIn *in)
{
    const f32 *pool = lbl_1_rodata_840;
    s32 i;
    f32 sum;
    f32 length;
    f32 abs_x;

    out->flags = 0;
    out->field04 = 0;
    out->field06 = 0;
    strncpy(out->name, in->name, 0x1f);
    out->name[0x1f] = 0;
    fn_1_22E8C(out, in);

    out->field_ac = out->field08 * pool[0] * pool[1];
    out->field_b0 = out->field08 * pool[2] * pool[1];
    out->field_b4 = out->field08 * pool[0] * pool[1];
    out->field228 = pool[3];
    out->parts[0].width = pool[3];
    out->parts[0].points = in->points[0];
    out->parts[0].scale_x = pool[3];
    out->parts[0].scale_y = pool[3];
    out->parts[0].scale_z = pool[3];
    out->parts[0].count = 0;
    out->parts[0].value = pool[3];
    out->parts[0].height = pool[4];
    out->parts[1].width = pool[3];
    out->parts[1].points = in->points[1];
    out->parts[1].scale_x = pool[3];
    out->parts[1].scale_y = pool[3];
    out->parts[1].scale_z = pool[3];
    out->parts[1].count = 0;
    out->parts[1].value = pool[3];
    out->parts[1].height = pool[4];
    out->parts[2].width = pool[3];
    out->parts[2].points = in->points[2];
    out->parts[2].scale_x = pool[3];
    out->parts[2].scale_y = pool[3];
    out->parts[2].scale_z = pool[3];
    out->parts[2].count = 0;
    out->parts[2].value = pool[3];
    out->parts[2].height = pool[4];
    out->parts[3].width = pool[3];
    out->parts[3].points = in->points[3];
    out->parts[3].scale_x = pool[3];
    out->parts[3].scale_y = pool[3];
    out->parts[3].scale_z = pool[3];
    out->parts[3].count = 0;
    out->parts[3].value = pool[3];
    out->parts[3].height = pool[4];
    out->max_length = pool[3];
    out->max_abs_x = pool[5];

    for (i = 0; i < 4; i++) {
        out->vertices[i].pos = in->points[i + 4];
        out->vertices[i].normal_x = pool[3];
        out->vertices[i].normal_y = pool[3];
        out->vertices[i].normal_z = pool[3];
        sum = out->vertices[i].pos.x * out->vertices[i].pos.x;
        sum = out->vertices[i].pos.y * out->vertices[i].pos.y + sum;
        sum = out->vertices[i].pos.z * out->vertices[i].pos.z + sum;
        length = lbl_8006D0B4(sum);
        if (out->max_length < length) {
            out->max_length = length;
        }
        abs_x = fabs(out->vertices[i].pos.x);
        if (out->max_abs_x < abs_x) {
            out->max_abs_x = abs_x;
        }
    }

    out->max_length = out->max_length + pool[6];
    out->field474 = -1;
    out->field475 = -1;
    out->field590 = 0;
    out->field5da = 100;
    lbl_8006DAEC();
    lbl_8006D758();
    fn_1_22F90(out, 1);
    lbl_8006DB30();
}
