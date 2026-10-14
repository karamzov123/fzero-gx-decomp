/* Non-matching: best partial attempt (55.46% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct Entry {
    u8 flag;
    u8 pad0[0xf];
    f32 v[3];
    u8 pad1[0x24];
    f32 weight;
} Entry;
typedef struct Obj {
    u8 pad0[0x18];
    u32 count;
    u32 num;
    u8 pad20[4];
    Entry *entries;
    void *out;
} Obj;
typedef struct Sig_fn_1_1289BC_Point1024C4 {
    u8 pad[0x10];
    f32 v[3];
} Sig_fn_1_1289BC_Point1024C4;
extern f32 fn_1_1289BC(const Sig_fn_1_1289BC_Point1024C4 *, const Sig_fn_1_1289BC_Point1024C4 *);
extern f32 lbl_8006D188(u32);
extern u32 fn_1_10846C(u32);
extern u32 fn_1_4630(u32, u32);
extern u32 lbl_1_data_40530;
extern u32 lbl_801A6410;
extern u8 lbl_1_rodata_7AB8[];
extern void fn_1_128884(void *, void *, int);

void fn_1_1137E4(Obj *obj) {
    u32 width, i, j, k;
    u32 groups, span;
    Entry *a, *b;
    volatile u32 count;
    if (!obj) return;
    width = 13;
    if (*(s32 *)((u8 *)*(u32 *)((u8 *)obj + 12) + 0x8c) == 2)
        width = 9;
    fn_1_10846C((u32)obj);
    count = obj->count;
    for (i = 0; i < count; i++) {
        a = &obj->entries[i];
        if (a->flag & 1) {
            a->flag = 0;
            a->weight = -1.0f;
        } else {
            a->flag = 1;
            a->weight = 0.0f;
        }
    }
    a = obj->entries;
    span = 0;
    for (i = 0; i < count; i++) {
        j = i + 1;
        b = (Entry *)((u8 *)obj->entries + span + 0x44);
        while (j < count) {
            if (a->v[0] < b->v[0])
                fn_1_128884(a, b, 0x44);
            j++;
            b++;
        }
        span += 0x44;
        a++;
    }
    groups = count / width;
    span = width * 0x44;
    for (i = 0; i < groups; i++)
        for (j = 0; j < width; j++)
            for (k = j + 1; k < width; k++)
                if (obj->entries[i * width + j].v[2] > obj->entries[i * width + k].v[2])
                    fn_1_128884(&obj->entries[i * width + j], &obj->entries[i * width + k], 0x44);
    for (i = 0; i < groups; i++)
        for (j = 0; j < width; j++)
            for (k = j + 1; k < width; k++) {
                Entry *x = &obj->entries[i * width + j];
                Entry *y = &obj->entries[i * width + k];
                if (x->v[2] > 0.0f && y->v[2] > 0.0f && x->v[1] < y->v[1])
                    fn_1_128884(x, y, 0x44);
                else if (x->v[2] <= 0.0f && y->v[2] <= 0.0f && x->v[1] > y->v[1])
                    fn_1_128884(x, y, 0x44);
            }
    groups = count / width;
    for (i = 0; i < groups; i++)
        for (j = 0; j < width; j++) {
            Entry *x = &obj->entries[i * width + j];
            if (x->flag & 1) x->weight = 0.0f;
            else {
                x->weight = (f32)j / (f32)groups;
                x->weight = -x->weight * (1.0f - 0.8f * lbl_8006D188((s32)(32768.0f * (f32)(i + 1) / 12.0f)));
            }
        }
    obj->num = (groups * (width - 1)) + ((groups - 1) * width);
    obj->out = (void *)fn_1_4630(lbl_801A6410, obj->num * 12);
    j = 0;
    k = 0;
    for (i = 0; i < count - 1; i++)
        if ((i + 1) % width) {
            ((void **)obj->out)[j++] = &obj->entries[i];
            ((void **)obj->out)[j++] = &obj->entries[i + 1];
            ((f32 *)obj->out)[(j * 4) / 12] = fn_1_1289BC((void *)&obj->entries[i], (void *)&obj->entries[i + 1]);
            k++;
        }
    j = k * 3;
    for (i = 0; i < count - width; i++) {
        ((void **)obj->out)[j / 3 * 2] = &obj->entries[i];
        ((void **)obj->out)[j / 3 * 2 + 1] = &obj->entries[i + width];
        ((f32 *)obj->out)[j / 3 * 3 + 2] = fn_1_1289BC((void *)&obj->entries[i], (void *)&obj->entries[i + width]);
        j += 3;
    }
}
