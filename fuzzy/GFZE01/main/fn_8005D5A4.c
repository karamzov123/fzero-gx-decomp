/* Non-matching: best partial attempt (49.25% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

struct Sig_fn_80020CB0_fn_80020CB0_object {
    struct Sig_fn_80020CB0_fn_80020CB0_object *next;
    struct Sig_fn_80020CB0_fn_80020CB0_object *prev;
    u8 pad_8[4];
    u32 index;
};
extern void fn_80020CB0(struct Sig_fn_80020CB0_fn_80020CB0_object *, u32);
extern u32 lbl_801A6C80;

typedef struct Slot_D5A4 { u8 b[0x118]; } Slot_D5A4;

static inline void activate_D5A4(u8 *p, u32 off) {
    u8 *s = p + off + 0x1408;
    s[1] = 2;
    if (s[0] == 3) {
        *(s32 *)(s + 0x1418 - 0x1408) = -960 / *(u16 *)(s + 0x1416 - 0x1408);
        if (*(s32 *)(p + off + 0x1418) == 0) *(s32 *)(p + off + 0x1418) = -1;
    } else {
        s32 v = *(s16 *)(*(u32 *)(s + 0x1424 - 0x1408) + 0x12);
        *(u32 *)(p + off + 0x14bc) = v != 0 ? (u32)(v << 16) : 0xFC400000;
        *(u32 *)(p + off + 0x14c0) = 0xFC400000;
        *(u16 *)(p + off + 0x1416) = 2;
    }
    if (s[0x1410 - 0x1408] >= 2 && (s[0x1410 - 0x1408] & 0x80) == 0) {
        s[0x1410 - 0x1408]--;
        fn_80020CB0(*(struct Sig_fn_80020CB0_fn_80020CB0_object **)(p + off + 0x1434),
                    s[0x1410 - 0x1408]);
    }
}
static inline int valid_D5A4(u8 state) { if (state == 1) return 1; if (state == 2) return 1; return 0; }
static inline int match_pair_D5A4(u8 *p, u32 off, u32 cmd, u32 mask, u8 id, int use_id) {
    if (valid_D5A4(p[off + 0x1408])) {
        if (p[off + 0x140d] == cmd) {
            if ((*(u32 *)(p + off + 0x1420) & mask) == (*(u32 *)(p + 0x444) & mask)) {
                if (!use_id || p[off + 0x140c] == id) return 1;
            }
        }
    }
    return 0;
}
s32 fn_8005D5A4(u8 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 flags = arg0[0x1b] & 0x8f;
    u8 *p = (u8 *)lbl_801A6C80;
    u32 i, off;
    s32 result = 0;
    if (flags != 0) {
    if (flags == 0x80) {
        for (i = 0, off = 0; i < 64; i++, off += 0x118) {
            if (match_pair_D5A4(p, off, 0x80, 0x0F7F00FF, 0, 0))
                activate_D5A4(p, off);
        }
    } else if (flags & 1) {
        for (i = 0, off = 0; i < 64; i++, off += 0x118) {
            if (match_pair_D5A4(p, off, 0x81, 0x0F00000F, arg0[0x1c], 1))
                activate_D5A4(p, off);
        }
    } else if (flags & 2) {
        for (i = 0, off = 0; i < 32; i++, off += 0x230) {
            if (match_pair_D5A4(p, off, 0x82, 0x0F00000F, arg0[0x1c], 1) ||
                match_pair_D5A4(p, off + 0x118, 0x82, 0x0F00000F, arg0[0x1c], 1)) { result = 1; break; }
        }
    } else if (flags & 4) {
        for (i = 0, off = 0; i < 64; i++, off += 0x118) {
            if (match_pair_D5A4(p, off, 0x84, 0x0F0000F0, arg0[0x1c], 1))
                activate_D5A4(p, off);
        }
    } else if (flags & 8) {
        for (i = 0, off = 0; i < 32; i++, off += 0x230) {
            if (match_pair_D5A4(p, off, 0x88, 0x0F0000F0, arg0[0x1c], 1) ||
                match_pair_D5A4(p, off + 0x118, 0x88, 0x0F0000F0, arg0[0x1c], 1)) { result = 1; break; }
        }
    }
    }
    return result;
}
