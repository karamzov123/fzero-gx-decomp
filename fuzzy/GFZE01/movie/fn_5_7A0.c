/* Non-matching: best partial attempt (63.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/movie/globals.h"

extern u32 lbl_5_bss_0[8];
extern const f32 lbl_5_rodata_0;
extern u8 lbl_5_data_0[];
extern u32 lbl_1_bss_198[];
extern u16 lbl_1_bss_968;
extern u32 lbl_1_data_370;

typedef struct InFlags InFlags;
struct InFlags {
    u8 pad_0[2];
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
    u16 unk_10;
    u16 unk_12;
};
extern InFlags lbl_1_bss_D58;

typedef struct Cursor Cursor;
struct Cursor {
    u32 unk_0;
    u8 unk_4;
};
extern Cursor lbl_1_bss_970;

typedef struct Mirror Mirror;
struct Mirror {
    u8 pad_0[4];
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    f32 unk_C;
    f32 unk_10;
};
extern Mirror lbl_1_bss_58;

extern u32 fn_5_3C44(void);
extern void fn_5_1404(u8 *);
extern void fn_5_169C(void);
extern u32 fn_1_157920(void);
extern void fn_1_157940(void);
extern void fn_80070704(s32);
extern char *fn_80083DB0(char *, const char *);
extern int sprintf(char *, const char *, ...);

typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;
typedef struct Sig_ADXT_Stop_SJErrorCallback Sig_ADXT_Stop_SJErrorCallback;
typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;
struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};
struct Sig_ADXT_Stop_SJ {
    const struct Sig_ADXT_Stop_SJInterface *interface;
};
extern Sig_ADXT_Stop_SJ *lbl_1_bss_6EAD0;
extern void ADXT_Stop(Sig_ADXT_Stop_SJ *);

/* Stream state block rooted at lbl_5_bss_0. */
struct movie_state {
    Sig_ADXT_Stop_SJ *stream;
    u8 pad_4[0x3C];
    s8 unk_40;
    s8 unk_41;
    u8 pad_42[6];
    u8 unk_48;
    u8 pad_49[1];
    u16 unk_4A;
    u16 unk_4C;
    s16 unk_4E;
    s16 unk_50;
    f32 unk_54;
    f32 unk_58;
    u8 unk_5C;
    u8 unk_5D;
    u8 unk_5E;
    u8 unk_5F;
    u8 pad_60[4];
    u16 unk_64;
};

void fn_5_7A0(void) {
    struct movie_state *p;
    Sig_ADXT_Stop_SJ *sj;
    s32 delta;
    s32 idx;
    s16 id;

    p = (struct movie_state *)&lbl_5_bss_0;

    if (p->unk_40 == 1) {
        if (p->unk_41 != 0) {
            p->unk_41 = 0;
            sj = p->stream;
            sj->interface->is_get_chunk(sj, 0, 0, 0);
        }
    } else if (p->unk_40 == -1) {
        fn_5_3C44();
    } else if (fn_1_157920() == 0 && p->unk_40 == -2) {
        delta = 0;
        if (((lbl_1_bss_D58.unk_8 >> 11) & 1) != 0) {
            p->unk_5D = p->unk_5D + 1;
            if (p->unk_5D > 5) {
                p->unk_5D = -1;
            }
        }
        fn_5_1404((u8 *)lbl_5_data_0 + 0xF0);
        if ((((lbl_1_bss_D58.unk_10 >> 12) & 1) != 0)
            || (((lbl_1_bss_D58.unk_12 >> 12) & 1) != 0)) {
            delta = -1;
        } else if ((((lbl_1_bss_D58.unk_10 >> 13) & 1) != 0)
                   || (((lbl_1_bss_D58.unk_12 >> 13) & 1) != 0)) {
            delta = 1;
        }
        if (((lbl_1_bss_D58.unk_2 >> 6) & 1) == 0) {
            if ((((lbl_1_bss_D58.unk_10 >> 14) & 1) != 0)
                || (((lbl_1_bss_D58.unk_12 >> 14) & 1) != 0)) {
                delta += 21;
            } else if ((((lbl_1_bss_D58.unk_10 >> 15) & 1) != 0)
                       || (((lbl_1_bss_D58.unk_12 >> 15) & 1) != 0)) {
                delta -= 21;
            }
        }
        if (delta != 0) {
            lbl_1_bss_970.unk_4 = (u8)((u32)(lbl_1_bss_970.unk_4 + delta + 62) % 62);
        }
    }

    if (p->unk_40 != -2 && ((lbl_1_bss_D58.unk_8 >> 6) & 1) != 0) {
        fn_1_157940();
        ADXT_Stop(lbl_1_bss_6EAD0);
        fn_5_3C44();
    }

    if (((lbl_1_bss_D58.unk_8 >> 5) & 1) != 0) {
        p->unk_48 = 1 - p->unk_48;
        fn_80070704(p->unk_48);
    }
    if (((lbl_1_bss_D58.unk_8 >> 4) & 1) != 0) {
        p->unk_5E = 1 - p->unk_5E;
    }
    if (((lbl_1_bss_D58.unk_A >> 7) & 1) != 0) {
        p->unk_5F = 1 - p->unk_5F;
    }

    if (((lbl_1_bss_D58.unk_2 >> 7) & 1) != 0) {
        if ((((lbl_1_bss_D58.unk_10 >> 12) & 1) != 0)
            || (((lbl_1_bss_D58.unk_12 >> 12) & 1) != 0)) {
            p->unk_54 += 0.1f;
            p->unk_58 += 0.1f;
        } else if ((((lbl_1_bss_D58.unk_10 >> 13) & 1) != 0)
                   || (((lbl_1_bss_D58.unk_12 >> 13) & 1) != 0)) {
            p->unk_54 -= 0.1f;
            p->unk_58 -= 0.1f;
        }
    }

    if (((lbl_1_bss_D58.unk_2 >> 6) & 1) != 0) {
        if ((((lbl_1_bss_D58.unk_10 >> 12) & 1) != 0)
            || (((lbl_1_bss_D58.unk_12 >> 12) & 1) != 0)) {
            p->unk_50 = (s16)((f32)(s32)p->unk_50 - 8.0f);
        } else if ((((lbl_1_bss_D58.unk_10 >> 13) & 1) != 0)
                   || (((lbl_1_bss_D58.unk_12 >> 13) & 1) != 0)) {
            p->unk_50 = (s16)((f32)(s32)p->unk_50 + 8.0f);
        }
        if ((((lbl_1_bss_D58.unk_10 >> 14) & 1) != 0)
            || (((lbl_1_bss_D58.unk_12 >> 14) & 1) != 0)) {
            p->unk_4E = (s16)((f32)(s32)p->unk_4E + 8.0f);
        } else if ((((lbl_1_bss_D58.unk_10 >> 15) & 1) != 0)
                   || (((lbl_1_bss_D58.unk_12 >> 15) & 1) != 0)) {
            p->unk_4E = (s16)((f32)(s32)p->unk_4E - 8.0f);
        }
    }

    if (((lbl_1_bss_D58.unk_8 >> 7) & 1) != 0) {
        if (p->unk_40 != -2) {
            fn_5_3C44();
        }
        idx = lbl_1_bss_970.unk_4;
        id = *(s16 *)((u8 *)lbl_5_data_0 + 0xF2 + idx * 0x44);

        switch (id - 3) {
        case 0:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x11AC));
            break;
        case 1:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x11BC));
            break;
        case 2:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x11CC));
            break;
        case 3:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x11DC));
            break;
        case 4:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x11EC));
            break;
        case 5:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x11FC));
            break;
        case 6:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x120C));
            break;
        case 7:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x121C));
            break;
        case 8:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x122C));
            break;
        case 9:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x123C));
            break;
        case 10:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x124C));
            break;
        case 11:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x125C));
            break;
        case 12:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x126C));
            break;
        case 13:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x127C));
            break;
        case 14:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x128C));
            break;
        case 15:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x129C));
            break;
        case 16:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x12AC));
            break;
        case 17:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x12BC));
            break;
        case 18:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x12CC));
            break;
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
            break;
        case 27:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x12E0));
            fn_80083DB0((char *)&lbl_1_bss_198[0x10], (const char *)(lbl_5_data_0 + 0x12E8));
            fn_80083DB0((char *)&lbl_1_bss_198[0x20], (const char *)(lbl_5_data_0 + 0x12CC));
            fn_80083DB0((char *)&lbl_1_bss_198[0x30], (const char *)(lbl_5_data_0 + 0x12F0));
            fn_80083DB0((char *)&lbl_1_bss_198[0x40], (const char *)(lbl_5_data_0 + 0x12F8));
            fn_80083DB0((char *)&lbl_1_bss_198[0x50], (const char *)(lbl_5_data_0 + 0x1300));
            fn_80083DB0((char *)&lbl_1_bss_198[0x60], (const char *)(lbl_5_data_0 + 0x130C));
            fn_80083DB0((char *)&lbl_1_bss_198[0x70], (const char *)(lbl_5_data_0 + 0x11CC));
            fn_80083DB0((char *)&lbl_1_bss_198[0x80], (const char *)(lbl_5_data_0 + 0x1314));
            fn_80083DB0((char *)&lbl_1_bss_198[0x90], (const char *)(lbl_5_data_0 + 0x11EC));
            fn_80083DB0((char *)&lbl_1_bss_198[0xA0], (const char *)(lbl_5_data_0 + 0x130C));
            fn_80083DB0((char *)&lbl_1_bss_198[0xB0], (const char *)(lbl_5_data_0 + 0x120C));
            fn_80083DB0((char *)&lbl_1_bss_198[0xC0], (const char *)(lbl_5_data_0 + 0x131C));
            fn_80083DB0((char *)&lbl_1_bss_198[0xD0], (const char *)(lbl_5_data_0 + 0x122C));
            fn_80083DB0((char *)&lbl_1_bss_198[0xE0], (const char *)(lbl_5_data_0 + 0x1324));
            fn_80083DB0((char *)&lbl_1_bss_198[0xF0], (const char *)(lbl_5_data_0 + 0x124C));
            fn_80083DB0((char *)&lbl_1_bss_198[0x100], (const char *)(lbl_5_data_0 + 0x132C));
            fn_80083DB0((char *)&lbl_1_bss_198[0x110], (const char *)(lbl_5_data_0 + 0x126C));
            fn_80083DB0((char *)&lbl_1_bss_198[0x120], (const char *)(lbl_5_data_0 + 0x1334));
            fn_80083DB0((char *)&lbl_1_bss_198[0x130], (const char *)(lbl_5_data_0 + 0x128C));
            fn_80083DB0((char *)&lbl_1_bss_198[0x140], (const char *)(lbl_5_data_0 + 0x133C));
            fn_80083DB0((char *)&lbl_1_bss_198[0x150], (const char *)(lbl_5_data_0 + 0x12AC));
            fn_80083DB0((char *)&lbl_1_bss_198[0x160], (const char *)(lbl_5_data_0 + 0x1344));
            fn_80083DB0((char *)&lbl_1_bss_198[0x170], (const char *)(lbl_5_data_0 + 0x1354));
            fn_80083DB0((char *)&lbl_1_bss_198[0x180], (const char *)(lbl_5_data_0 + 0x12DC));
            lbl_1_bss_970.unk_0 = 1;
            p->unk_4A = 0x280;
            lbl_1_bss_58.unk_4 = 0x280;
            p->unk_4C = 0x150;
            lbl_1_bss_58.unk_6 = 0x150;
            p->unk_54 = 0.5f;
            lbl_1_bss_58.unk_C = 0.5f;
            p->unk_58 = 0.5f;
            lbl_1_bss_58.unk_10 = 0.5f;
            p->unk_4E = 0x88;
            lbl_1_bss_58.unk_8 = 0x88;
            p->unk_50 = 0;
            lbl_1_bss_58.unk_A = 0;
            p->unk_5D = -1;
            p->unk_5E = 0;
            p->unk_48 = 1;
            p->unk_64 = 0;
            p->unk_5C = 2;
            break;
        case 28:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x12F0));
            fn_80083DB0((char *)&lbl_1_bss_198[0x10], (const char *)(lbl_5_data_0 + 0x1360));
            fn_80083DB0((char *)&lbl_1_bss_198[0x20], (const char *)(lbl_5_data_0 + 0x136C));
            fn_80083DB0((char *)&lbl_1_bss_198[0x30], (const char *)(lbl_5_data_0 + 0x1378));
            fn_80083DB0((char *)&lbl_1_bss_198[0x40], (const char *)(lbl_5_data_0 + 0x1384));
            fn_80083DB0((char *)&lbl_1_bss_198[0x50], (const char *)(lbl_5_data_0 + 0x1390));
            fn_80083DB0((char *)&lbl_1_bss_198[0x60], (const char *)(lbl_5_data_0 + 0x139C));
            fn_80083DB0((char *)&lbl_1_bss_198[0x70], (const char *)(lbl_5_data_0 + 0x12DC));
            p->unk_4E = (p->unk_5F == 0) ? 0x88 : 0;
            p->unk_4A = 0x140;
            p->unk_4C = 0xF0;
            p->unk_64 = -1;
            p->unk_54 = 1.0f;
            p->unk_58 = 1.0f;
            p->unk_5C = 1;
            p->unk_50 = 0;
            p->unk_48 = 1;
            break;
        default:
            fn_80083DB0((char *)&lbl_1_bss_198[0], (const char *)(lbl_5_data_0 + 0x12F0));
            fn_80083DB0((char *)&lbl_1_bss_198[0x10], (const char *)(lbl_5_data_0 + 0x13A8));
            sprintf((char *)&lbl_1_bss_198[0x20], (const char *)(lbl_5_data_0 + 0x13B4),
                    id - 0x28);
            fn_80083DB0((char *)&lbl_1_bss_198[0x30], (const char *)(lbl_5_data_0 + 0x13C4));
            /* the id indexes a pointer table that starts 0xA0 before lbl_1_data_370 */
            sprintf((char *)&lbl_1_bss_198[0x40], (const char *)(lbl_5_data_0 + 0x13D4),
                    *(u32 *)((u8 *)lbl_1_data_370 - 0xA0 + id * 4));
            fn_80083DB0((char *)&lbl_1_bss_198[0x50], (const char *)(lbl_5_data_0 + 0x13A8));
            fn_80083DB0((char *)&lbl_1_bss_198[0x60], (const char *)(lbl_5_data_0 + 0x1360));
            fn_80083DB0((char *)&lbl_1_bss_198[0x70], (const char *)(lbl_5_data_0 + 0x13A8));
            fn_80083DB0((char *)&lbl_1_bss_198[0x80], (const char *)(lbl_5_data_0 + 0x136C));
            fn_80083DB0((char *)&lbl_1_bss_198[0x90], (const char *)(lbl_5_data_0 + 0x13A8));
            fn_80083DB0((char *)&lbl_1_bss_198[0xA0], (const char *)(lbl_5_data_0 + 0x1378));
            fn_80083DB0((char *)&lbl_1_bss_198[0xB0], (const char *)(lbl_5_data_0 + 0x13A8));
            fn_80083DB0((char *)&lbl_1_bss_198[0xC0], (const char *)(lbl_5_data_0 + 0x1384));
            fn_80083DB0((char *)&lbl_1_bss_198[0xD0], (const char *)(lbl_5_data_0 + 0x13A8));
            fn_80083DB0((char *)&lbl_1_bss_198[0xE0], (const char *)(lbl_5_data_0 + 0x1390));
            fn_80083DB0((char *)&lbl_1_bss_198[0xF0], (const char *)(lbl_5_data_0 + 0x13A8));
            fn_80083DB0((char *)&lbl_1_bss_198[0x100], (const char *)(lbl_5_data_0 + 0x139C));
            fn_80083DB0((char *)&lbl_1_bss_198[0x110], (const char *)(lbl_5_data_0 + 0x13E4));
            fn_80083DB0((char *)&lbl_1_bss_198[0x120], (const char *)(lbl_5_data_0 + 0x13F0));
            fn_80083DB0((char *)&lbl_1_bss_198[0x130], (const char *)(lbl_5_data_0 + 0x1400));
            fn_80083DB0((char *)&lbl_1_bss_198[0x140], (const char *)(lbl_5_data_0 + 0x12DC));
            p->unk_4E = (p->unk_5F == 0) ? 0x88 : 0;
            p->unk_4A = 0x140;
            p->unk_4C = 0xF0;
            p->unk_64 = -1;
            p->unk_54 = 1.0f;
            p->unk_58 = 1.0f;
            p->unk_5C = 1;
            p->unk_50 = 0;
            p->unk_48 = 1;
            break;
        }

        fn_5_169C();
    }

    if (((lbl_1_bss_D58.unk_8 >> 3) & 1) != 0
        && ((lbl_1_bss_D58.unk_2 >> 6) & 1) == 0) {
        lbl_1_bss_968 = 0xA;
    }
}
