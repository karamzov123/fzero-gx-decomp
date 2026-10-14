/* Non-matching: best partial attempt (32.78% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/sel/sel.h"

struct fn_10_19F70_Copy88 { u32 a[22]; };

struct fn_10_19F70_Packet {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x20];
    u32 unk_30;
    u8 pad_34[0x1C];
    u32 unk_50;
    f32 unk_54;
};

extern u32 fn_10_19EC8(void *);
extern u32 fn_10_19F1C(void *);
extern void _savegpr_27(void);
extern void _restgpr_27(void);
extern int fn_1_4C10(void);
extern u32 fn_1_4CAC(void);
extern f32 fn_1_4C24(void);
extern u16 fn_1_A5DB0(void);
extern f32 fn_1_520F8(s32);
extern f32 fn_1_521B8(s32);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 lbl_1_rodata_26F8;
extern const f32 lbl_10_rodata_158[19];

void fn_10_19F70(u32 arg0, u8 arg1) {
    const f32 *pool = (const f32 *)&lbl_10_rodata_158;
    s16 id;
    s32 base;
    u32 idx = arg1;
    f32 ft = pool[19];
    f32 v1;
    f32 scale;
    f32 off;
    f32 c;
    s32 w2;
    s32 w3;
    struct fn_10_19F70_Copy88 buf;

    if ((s16)arg0 != -1) {
        if (fn_1_4C10() == 0) {
            ft = pool[17];
        } else if (fn_1_4CAC() == 0) {
            ft = pool[17] - fn_1_4C24();
        } else {
            ft = fn_1_4C24();
        }
    }

    v1 = (f32)(u32)(fn_1_A5DB0() & 0xFFFF);
    scale = (v1 - *(const f64 *)&pool[36]) / pool[704];
    if (ft < pool[19]) {
        c = pool[19];
    } else if (ft > pool[17]) {
        c = pool[17];
    } else {
        c = ft;
    }
    off = pool[709] * c;

    base = idx * 150;
    id = (s16)(base + 23);
    ((Obj_10_bss_55AE4 *)((u8 *)&lbl_10_bss_55AE4 + idx * 8))->unk_0 = (s32)fn_1_520F8(id);
    ((Obj_10_bss_55AE4 *)((u8 *)&lbl_10_bss_55AE4 + idx * 8))->unk_2 = (s32)(pool[712] * scale);
    w2 = (s32)fn_1_521B8(144);
    w3 = (s32)(pool[710] * scale);
    buf = *(struct fn_10_19F70_Copy88 *)((u32 *)&lbl_1_rodata_26F8 - 4);
    ((Obj_10_bss_55AE4 *)((u8 *)&lbl_10_bss_55AE4 + idx * 8))->unk_4 = w2;
    ((Obj_10_bss_55AE4 *)((u8 *)&lbl_10_bss_55AE4 + idx * 8))->unk_6 = w3;

    {
        struct fn_10_19F70_Packet pkt;
        pkt.unk_0 = 0x9D0D;
        pkt.unk_4 = v1 - *(const f64 *)&pool[34] - off;
        pkt.unk_8 = pool[712];
        pkt.unk_C = pool[26];
        pkt.unk_30 = 0x400005;
        pkt.unk_50 = (u32)fn_10_19EC8;
        pkt.unk_54 = v1 - *(const f64 *)&pool[36];
        fn_1_4F734((FontDrawPacket *)&pkt);
    }

    v1 = (f32)(u32)(fn_1_A5DB0() & 0xFFFF);
    scale = (v1 - *(const f64 *)&pool[36]) / pool[704];
    if (ft < pool[19]) {
        c = pool[19];
    } else if (ft > pool[17]) {
        c = pool[17];
    } else {
        c = ft;
    }
    off = pool[711] * c;

    base = base + 15;
    ((Obj_10_bss_55B04 *)((u8 *)&lbl_10_bss_55B04 + idx * 8))->unk_0 = (s32)fn_1_520F8((s16)base);
    ((Obj_10_bss_55B04 *)((u8 *)&lbl_10_bss_55B04 + idx * 8))->unk_2 = (s32)(pool[713] * scale);
    w2 = (s32)fn_1_521B8(28);
    w3 = (s32)(pool[240] * scale);
    buf = *(struct fn_10_19F70_Copy88 *)((u32 *)&lbl_1_rodata_26F8 - 4);
    ((Obj_10_bss_55B04 *)((u8 *)&lbl_10_bss_55B04 + idx * 8))->unk_4 = w2;
    ((Obj_10_bss_55B04 *)((u8 *)&lbl_10_bss_55B04 + idx * 8))->unk_6 = w3;

    {
        struct fn_10_19F70_Packet pkt;
        pkt.unk_0 = 0x9D0E;
        pkt.unk_4 = v1 - *(const f64 *)&pool[34] - off;
        pkt.unk_8 = pool[713];
        pkt.unk_C = pool[17];
        pkt.unk_30 = 0x400007;
        pkt.unk_50 = (u32)fn_10_19F1C;
        pkt.unk_54 = v1 - *(const f64 *)&pool[36];
        fn_1_4F734((FontDrawPacket *)&pkt);
    }
}
