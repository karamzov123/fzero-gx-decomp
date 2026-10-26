/* Non-matching: best partial attempt (95.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/stcoli.h"
typedef struct { f32 x,y,z; } V3;
typedef struct { s32 key; u8 *ents; u32 *id; } Node;
extern f32 lbl_1_rodata_6C8[12];
extern s16 fn_1_7B054(void);
extern u8 *lbl_801A66CC;
static inline u8 * fn_1_210A8_address_1794(s32 offset, u8 *base) { return base + offset; }
static inline f32 fn_1_210A8_read_pointer(V3 *owner) { return owner->x; }
#pragma peephole off
#pragma opt_strength_reduction off
static inline f32 fn_1_210A8_read_pointer_(V3 * owner) { return owner->y; }
#pragma opt_propagation off
s32 fn_1_210A8(V3 *pos, f32 *t, s32 idx, s32 sub, V3 *out) {
    f32 *rp = lbl_1_rodata_6C8;
    s32 flag;
    s32 i, cnt;
    u32 id;
    s32 key;
    Node *nodes;
    f32 lim;
    s32 cnts[2];
    s32 bad[2];
    s32 prevA[2];
    s32 result;
    s32 dir, k;
    s32 okA, okB;
    f32 a,b;
    u8 *e;
    if (fn_1_7B054() == 25) lim = rp[10];
    else lim = rp[11];
    *t = rp[2];
    if (out != 0) *out = *pos;
    if (lbl_1_bss_3BE0 == 0) return -1;
    cnt = lbl_1_bss_3BE0->unk_8;
    nodes = (Node *)lbl_1_bss_3BE0->unk_C;
    if (cnt == 0) return -1;
    if (idx < 0 || cnt <= idx) return -1;
    lim = -lim;
    cnts[0] = 0;
    cnts[1] = -1;
    bad[1] = 0;
    flag = lbl_1_bss_3BE0->unk_7D;
    bad[0] = 0;
    id = *nodes[idx].id;
    result = -1;
    key = nodes[idx].key;
    {
        s32 prevB[2];
        prevB[1] = 1;
        prevB[0] = 1;
        prevA[1] = 1;
        prevA[0] = 1;
        for(i=0;i<cnt;i++) {
            if ((s32)flag != 0) dir = 0;
            else dir = i & 1;
            {
                s32 offset = ((dir)[cnts]) + cnt;
                k = (idx + offset) % cnt;
            }
            if (sub != 0) {
                if (id != *nodes[k].id || key != nodes[k].key) bad[dir]=1;
            }
            if(dir != 0) cnts[dir] = cnts[dir]-1;
            else cnts[dir]++;
            if(bad[dir] == 0) {
                e = fn_1_210A8_address_1794(sub * 0x50, nodes[k].ents);
                {
                    f32 x = pos->x;
                    f32 y = fn_1_210A8_read_pointer_(pos);
                    f32 z = pos->z;
                    f32 dotA = x * *(f32 *)(e+0xC);
                    f32 dotB = x * *(f32 *)(e+0x28);
                    dotA = y * *(f32 *)(e+0x10) + dotA;
                    dotB = y * *(f32 *)(e+0x2C) + dotB;
                    dotA = z * *(f32 *)(e+0x14) + dotA;
                    dotB = z * *(f32 *)(e+0x30) + dotB;
                    a = *(f32 *)(e+8) + dotA;
                    b = *(f32 *)(e+0x24) + dotB;
                }
                if (k == 0) {
                    okB = lim <= b;
                    okA = pos->z < rp[2];
                    if(flag != 0) okA=1;
                } else if (k == cnt-1) {
                    okB = pos->z >= rp[2];
                    okA = lim <= a;
                    if ((s32)flag != 0 && fn_1_7B054() != 41) okB=1;
                } else {
                    okB = lim <= b;
                    okA = lim <= a;
                }
                if (okA != 0 && okB != 0) {
                    result = k;
                    *t = a/(a+b);
                    if (out != 0) {
                        psvec_sub(e+0x34,e+0x18,lbl_801A66CC+0xD4);
                        psvec_scale_add(e+0x18,lbl_801A66CC+0xD4,*t,out);
                    }
                    break;
                }
                if ((dir == 0 && prevB[dir] == 0 && okA == 0) ||
                    (dir != 0 && prevA[dir] == 0 && okB == 0)) {
                    result = -1;
                    break;
                }
                prevA[dir] = okA;
                prevB[dir] = okB;
            }
        }
    }
    return result;
}
#pragma opt_propagation reset

