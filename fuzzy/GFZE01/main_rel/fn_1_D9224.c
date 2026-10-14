/* Non-matching: best partial attempt (61.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/bg_san.h"

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3;
    u16 unk_4;
    u8 pad_6[2];
    f32 unk_8[14];
    u32 unk_44;
} D9224Entry;
typedef struct { u8 unk_0[0x40]; } D9224Input;
typedef struct { u32 unk_0; } D9224Manager;
extern u32 lbl_1_rodata_6490[];
extern D9224Manager lbl_801A6410;
extern u8 lbl_1_data_3DC50[9];
extern u32 fn_1_4630(u32, u32, u32, u32);
extern f32 lbl_8006D0B4(f32);

void fn_1_D9224(void *obj, void *arg) {
    u32 *countPtr;
    D9224Input *input;
    D9224Entry *entries;
    u32 count, i, j, used;
    u32 *aux;
    f32 limit = *(f32 *)((u8 *)lbl_1_rodata_6490 + 0x138);
    if (arg == 0) return;
    *(u32 *)((u8 *)obj + 0xC) = 0;
    *(u32 *)((u8 *)obj + 0x10) = 0;
    countPtr = (u32 *)fn_80077B64(arg);
    input = (D9224Input *)fn_80077B14(arg);
    count = *countPtr;
    entries = (D9224Entry *)fn_1_4630(lbl_801A6410.unk_0, count * 0x44, (u32)lbl_1_data_3DC50, 0x516);
    *(D9224Entry **)((u8 *)obj + 0x14) = entries;
    aux = (u32 *)fn_1_4630(lbl_801A6410.unk_0, count * 12, (u32)lbl_1_data_3DC50, 0x517);
    *(u32 **)((u8 *)obj + 0x1C) = aux;
    {
        u32 *out = aux;
        for (i = 0; i < *countPtr; i++) {
            *out++ = *(u32 *)((u8 *)input + 0);
            *out++ = *(u32 *)((u8 *)input + 4);
            *out++ = *(u32 *)((u8 *)input + 8);
            input = (D9224Input *)((u8 *)input + 0x40);
        }
    }
    input = (D9224Input *)fn_80077B14(arg);
    used = 0;
    for (i = 0; i < count; i++, input++) {
        s32 found = -1;
        for (j = 0; j < used; j++) {
            f32 dx = entries[j].unk_8[2] - *(f32 *)((u8 *)input + 0);
            f32 dy = entries[j].unk_8[3] - *(f32 *)((u8 *)input + 4);
            f32 dz = entries[j].unk_8[4] - *(f32 *)((u8 *)input + 8);
            f32 d = dx * dx + dy * dy + dz * dz;
            if (d < *(f64 *)((u8 *)lbl_1_rodata_6490 + 0x138)) { found = j; break; }
        }
        if (found >= 0) {
            u32 offset = found * 0x44;
            u8 n = *(u8 *)((u8 *)entries + offset + 2);
            *(u16 *)((u8 *)entries + offset + 4 + n * 2) = (u16)i;
            entries[found].unk_2++;
        } else {
            D9224Entry *e = &entries[used++];
            *(u32 *)((u8 *)e + 0x28) = *(u32 *)((u8 *)input + 0);
            *(u32 *)((u8 *)e + 0x2C) = *(u32 *)((u8 *)input + 4);
            *(u32 *)((u8 *)e + 0x30) = *(u32 *)((u8 *)input + 8);
            *(u32 *)((u8 *)e + 0x1C) = *(u32 *)((u8 *)e + 0x28);
            *(u32 *)((u8 *)e + 0x20) = *(u32 *)((u8 *)e + 0x2C);
            *(u32 *)((u8 *)e + 0x24) = *(u32 *)((u8 *)e + 0x30);
            *(u32 *)((u8 *)e + 0x10) = *(u32 *)((u8 *)e + 0x1C);
            *(u32 *)((u8 *)e + 0x14) = *(u32 *)((u8 *)e + 0x20);
            *(u32 *)((u8 *)e + 0x18) = *(u32 *)((u8 *)e + 0x24);
            *(u32 *)((u8 *)e + 0x34) = *(u32 *)((u8 *)lbl_1_rodata_6490 + 0x128);
            *(u32 *)((u8 *)e + 0x38) = *(u32 *)((u8 *)lbl_1_rodata_6490 + 0x12C);
            *(u32 *)((u8 *)e + 0x3C) = *(u32 *)((u8 *)lbl_1_rodata_6490 + 0x130);
            e->unk_0 = *((u8 *)input + 0x35);
            fn_80008BEC((u8 *)e + 4, 0xFF, 8);
            e->unk_2 = 1;
            e->unk_4 = (u16)i;
            e->unk_1 = 0;
        }
    }
    *(u32 *)((u8 *)obj + 0xC) = used;
    for (i = 0; i < used; i++) {
        if (entries[i].unk_0 & 1) {
            *(f32 *)((u8 *)&entries[i] + 0x40) = -1.0f;
            entries[i].unk_0 = 0;
        } else {
            *(f32 *)((u8 *)&entries[i] + 0x40) = 0.0f;
            entries[i].unk_0 = 1;
        }
    }
    for (i = 0; i + 1 < used; i++) for (j = i + 1; j < used; j++) {
        if (!(entries[i].unk_0 & 1) && (entries[j].unk_0 & 1)) {
            D9224Entry t = entries[i]; entries[i] = entries[j]; entries[j] = t;
        }
    }
    for (i = 0; i + 1 < used; i++) for (j = i + 1; j < used; j++) {
        if (!(entries[i].unk_0 & 1) && !(entries[j].unk_0 & 1) &&
            entries[i].unk_8[2] > entries[j].unk_8[2]) {
            D9224Entry t = entries[i]; entries[i] = entries[j]; entries[j] = t;
        }
    }
    {
        D9224Entry *base = entries;
        for (i = 0; i < used; i++) if (base[i].unk_0 & 1) { base += i; break; }
        for (i = 0; i < 8; i++) for (j = i + 1; j < 9; j++)
            if (base[i].unk_8[3] < base[j].unk_8[3]) {
                D9224Entry t = base[i]; base[i] = base[j]; base[j] = t;
            }
        {
            D9224Entry *p = (D9224Entry *)((u8 *)base + 0x264);
            u32 k;
            for (k = 0; k < 10; k++) {
                for (i = 0; i < 10; i++) for (j = i + 1; j < 11; j++)
                    if (p[i].unk_8[3] < p[j].unk_8[3]) {
                        D9224Entry t = p[i]; p[i] = p[j]; p[j] = t;
                    }
                p = (D9224Entry *)((u8 *)p + 0x2EC);
            }
        }
    }
    {
        D9224Entry *best = entries;
        f32 bestD = 100000.0f;
        for (i = 0; i + 1 < used; i++) if (entries[i].unk_0 & 1) {
            f32 dx = entries[i].unk_8[2] - *(f32 *)((u8 *)entries + 0x8D4);
            f32 dy = entries[i].unk_8[3] - *(f32 *)((u8 *)entries + 0xB3C);
            f32 d = lbl_8006D0B4(dx*dx + dy*dy);
            if (bestD > d) { bestD = d; best = &entries[i]; }
        }
        { D9224Entry t = *(D9224Entry *)((u8 *)entries + 0x838);
          *(D9224Entry *)((u8 *)entries + 0x838) = *best; *best = t; }
    }
    {
        D9224Entry *best = entries;
        f32 bestD = 100000.0f;
        for (i = 0; i < used; i++) if (entries[i].unk_0 & 1) {
            f32 dx = entries[i].unk_8[2] - *(f32 *)((u8 *)entries + 0xAF4);
            f32 dy = entries[i].unk_8[3] - *(f32 *)((u8 *)entries + 0xDE4);
            f32 d = lbl_8006D0B4(dx*dx + dy*dy);
            if (bestD > d) { bestD = d; best = &entries[i]; }
        }
        { D9224Entry t = *(D9224Entry *)((u8 *)entries + 0x87C);
          *(D9224Entry *)((u8 *)entries + 0x87C) = *best; *best = t; }
    }
    *(u32 *)((u8 *)obj + 0x10) = 0xDC;
    *(u32 *)((u8 *)obj + 0x18) = fn_1_4630(lbl_801A6410.unk_0, 0xDC * 12, (u32)lbl_1_data_3DC50, 0x5C7);
    {
        D9224Entry *track = (D9224Entry *)((u8 *)entries + 0x83C);
        D9224Entry *d = (D9224Entry *)((u8 *)entries + 0x87C);
        for (i = 0; i < 0x2A; i++) d[i] = d[i - 1];
        for (i = 0; i < 0x21; i++) {
            f32 n = (f32)(i * 0x2E8C2E9ULL / 2 + 1);
            f32 x = n / 12.0f;
            if (x < 0.0f) x = 0.0f;
            else if (x > 1.0f) x = 1.0f;
            *(f32 *)((u8 *)&track[i] + 0x40) = -x;
            if (i == 0 || i == 10) *(f32 *)((u8 *)&track[i] + 0x40) = 0.0f;
        }
        {
            D9224Entry **list = (D9224Entry **)*(u32 **)((u8 *)obj + 0x18);
            u32 out = 0;
            for (i = 0; i < used - 0x20; i++) {
                if ((i + 1) % 11) {
                    list[out * 3] = &track[i];
                    list[out * 3 + 1] = &track[i + 1];
                    list[out * 3 + 2] = (D9224Entry *)(u32)(
                        (track[i].unk_8[2] - track[i + 1].unk_8[2]) *
                        (track[i].unk_8[2] - track[i + 1].unk_8[2]) +
                        (track[i].unk_8[3] - track[i + 1].unk_8[3]) *
                        (track[i].unk_8[3] - track[i + 1].unk_8[3]) +
                        (track[i].unk_8[4] - track[i + 1].unk_8[4]) *
                        (track[i].unk_8[4] - track[i + 1].unk_8[4]));
                    out++;
                }
            }
            for (i = 0; i < used - 0x2A; i++) {
                list[out * 3] = &track[i];
                list[out * 3 + 1] = (D9224Entry *)((u8 *)&track[i] + 0x2EC);
                list[out * 3 + 2] = (D9224Entry *)(u32)(
                    (track[i].unk_8[2] - *(f32 *)((u8 *)&track[i] + 0x2FC)) *
                    (track[i].unk_8[2] - *(f32 *)((u8 *)&track[i] + 0x2FC)) +
                    (track[i].unk_8[3] - *(f32 *)((u8 *)&track[i] + 0x300)) *
                    (track[i].unk_8[3] - *(f32 *)((u8 *)&track[i] + 0x300)) +
                    (track[i].unk_8[4] - *(f32 *)((u8 *)&track[i] + 0x304)) *
                    (track[i].unk_8[4] - *(f32 *)((u8 *)&track[i] + 0x304)));
                out++;
            }
        }
    }
}
