/* Non-matching: best partial attempt (58.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"

extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern u32 lbl_1_data_35AC8;
struct AAF1CNode {
    u16 unk_2;
    s32 unk_4;
    u32 unk_8;
    u8 pad_C[0x80];
    void *unk_8c;
};
struct AAF1CObject {
    u8 pad_0[2];
    u8 unk_2;
    u8 pad_3[5];
    s16 unk_8;
    s16 unk_A;
    u8 pad_C[0x18];
    struct AAF1CNode *unk_24;
    u8 pad_28[2];
    u8 unk_2a;
};

void fn_1_AAF1C(void *arg0) {
    struct AAF1CObject *obj = (struct AAF1CObject *)arg0;
    struct AAF1CNode *node = obj->unk_24;
    s32 kind = node->unk_4;
    switch (kind) {
    case -13: obj->unk_8 = 0x21; break;
    case -124: obj->unk_8 = 0x36; break;
    case -127: obj->unk_8 = 0x1f; break;
    case -128: obj->unk_8 = 2; break;
    case -126: obj->unk_8 = ((u8 *)node->unk_8c)[0x3f] >= 0x4f && ((u8 *)node->unk_8c)[0x3f] < 0x55 ? 0x2a : 0x2b; break;
    case -125: obj->unk_8 = ((u8 *)node->unk_8c)[0x3f] >= 0x4f && ((u8 *)node->unk_8c)[0x3f] < 0x55 ? 0x2c : 0x2d; break;
    case -123: obj->unk_8 = 0x37; break;
    case -122: obj->unk_8 = 3; break;
    case -121: obj->unk_8 = 0x2f; break;
    case -119: obj->unk_8 = lbl_1_bss_960 == 3 ? 0x4d : 0x4c; break;
    case -9: obj->unk_8 = ((u8 *)node->unk_8c)[0x3f] >= 0x4f && ((u8 *)node->unk_8c)[0x3f] < 0x55 ? 0x2c : 0x2d; break;
    case -8: obj->unk_8 = ((u8 *)node->unk_8c)[0x3f] >= 0x4f && ((u8 *)node->unk_8c)[0x3f] < 0x55 ? 0x2b : 0x2a; break;
    case -6: case -5: obj->unk_8 = 0x20; break;
    case -4: obj->unk_8 = 0x38; break;
    case -3: obj->unk_8 = 0x37; break;
    case -2: obj->unk_8 = 1; break;
    case -1: obj->unk_8 = 0; break;
    default:
        OSReport((const char *)((u8 *)&lbl_1_data_35AC8 + 0x6d94));
        OSPanic((const char *)((u8 *)&lbl_1_data_35AC8 + 0x6cf0), 0x5a3, (const char *)((u8 *)&lbl_1_data_35AC8 + 0x6da0));
    }
    switch (obj->unk_2) {
    case 0: case 1: case 2: case 3: case 4: case 5: {
        u32 flags = node->unk_8;
        u16 value;
        switch (obj->unk_2) {
        case 2: switch (flags & 0xc03) { case 1: value=4; break; case 2: case 3: value=0xe; break; case 0x400: value=0x15; break; case 0x802: value=0xf; break; default: value=4; break; } break;
        case 0: switch (flags & 0x403) { case 1: value=5; break; case 2: case 3: value=0xe; break; case 0x400: value=0x16; break; default: value=5; break; } break;
        case 1: switch (flags & 0x403) { case 1: value=6; break; case 2: case 3: value=0xe; break; case 0x400: value=0x17; break; case 0x800: value=0xf; break; default: value=6; break; } break;
        case 5: switch (flags & 0x403) { case 1: value=7; break; case 2: case 3: value=0xe; break; case 0x400: value=0x18; break; default: value=7; break; } break;
        default: switch (flags & 0x403) { case 1: value=8; break; case 2: case 3: value=0xe; break; case 0x400: value=0x19; break; default: value=8; break; } break;
        }
        obj->unk_A = value;
        break;
    }
    default:
        OSPanic((const char *)((u8 *)&lbl_1_data_35AC8 + 0x6cf0), 0x627, (const char *)((u8 *)&lbl_1_data_35AC8 + 0x6db8));
    }
    obj->unk_2a |= 4;
    node->unk_8 &= ~4;
    node->unk_2 = 0;
}
