/* Non-matching: best partial attempt (98.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieSubEntry {
    u32 field_0;
    u32 field_4;
    u32 field_8;
} MovieSubEntry;

typedef struct MovieChannel {
    u8 pad_0000[0x1158];
    u32 field_1158;
    u32 field_115c;
    u8 pad_1160[0x18];
    MovieSubEntry *field_1178;
    s32 field_117c;
    s32 field_1180;
    u32 field_1184;
    s32 field_1188;
} MovieChannel;

s32 fn_12_2CDD0(MovieChannel *arg0, s32 arg1, u32 arg2, MovieSubEntry *arg3) {
    MovieChannel *ch;
    s32 idx;
    s32 offset;
    MovieSubEntry *ent;
    u32 total;
    u32 time;
    s32 count;
    MovieSubEntry *table;
    s32 head;
    s32 maxc;
    u32 loop_start;
    u32 loop_len;
    u32 entry_len;
    s32 nxt;

    arg3->field_0 = 0xFFFFFFFF;
    ch = (MovieChannel *)((u8 *)arg0 + arg1 * 0x74);
    table = ch->field_1178;
    loop_start = ch->field_1158;
    loop_len = ch->field_115c;
    if (table == 0) {
        return 0;
    }
    total = loop_start + loop_len;
    time = arg2;
    if (time >= total) {
        time -= loop_len;
    }
    count = ch->field_1180;
    if (count == 0) {
        goto end;
    }
    head = ch->field_1188;
    maxc = ch->field_117c;
    idx = head;
    offset = 0;
    while (count > 0) {
        ent = &table[idx];
        entry_len = ent->field_8;
        if (ent->field_4 + entry_len <= total) {
            if (ent->field_4 > time) {
                goto next;
            }
            if (time >= ent->field_4 + entry_len) {
                goto next;
            }
            goto found;
        }
        if (ent->field_4 > time) {
            goto second;
        }
        if (time < total) {
            goto found;
        }
    second:
        if (loop_start > time) {
            goto next;
        }
        if (time >= ent->field_4 + entry_len - loop_len) {
            goto next;
        }
        goto found;
    next:
        nxt = idx + 1;
        idx = nxt - maxc;
        if (nxt < maxc) {
            idx = nxt;
        }
        offset = offset + 1;
        count--;
    }
    offset = -1;
found:
    if (offset == -1) {
        goto end;
    }
    nxt = head + offset;
    idx = nxt - maxc;
    if (nxt < maxc) {
        idx = nxt;
    }
    ch->field_1180 -= offset;
    ch->field_1188 = idx;
    ent = &ch->field_1178[idx];
    *arg3 = *ent;
end:
    return 0;
}
