#include "types.h"

#pragma fp_contract off

typedef struct {
    void *image;
    u16 code;
    u16 width;
} FontGlyph;

typedef struct {
    u8 **lines;
    s32 count;
} StringGroup;

extern s32 (*lbl_801A66DC)(void);
extern void (*lbl_801A66E0)(void);
extern void (*lbl_801A66E4)(void);
extern void (*lbl_801A66E8)(void);
extern u8 lbl_801A66D8;
extern StringGroup *lbl_801A66F4;
extern s16 lbl_801A66EC;
extern FontGlyph lbl_8015B940[];
extern char lbl_801A63F0[4];
extern char lbl_801A63F4[4];

extern s32 DVDGetDriveStatus(void);
extern int fn_80083BCC(const char *, const char *);
extern void fn_80005EDC(void);
/* Parameter order comes from this caller: the floats are evaluated before the
   string, which only a (f32, f32, f32, u8 *) prototype gives. */
extern void fn_800060D8(f32 x, f32 y, f32 z, u8 *str);
extern void fn_80007B68(void);
extern s32 fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);

/* fn_80006334's body: it is defined after fn_800060D8 (which calls it) and
   before this function, so MWCC auto-inlines it here. */
static inline u32 is_wide(u8 *str) {
    return (*str >> 7) & 1;
}

/* Same glyph lookup as fn_800060D8.c. */
static inline FontGlyph *find_glyph(s32 code) {
    FontGlyph *glyph = lbl_8015B940;
    s32 i;

    for (i = 0; i < lbl_801A66EC; i++, glyph++) {
        if (glyph->code == code) {
            return glyph;
        }
    }
    return NULL;
}

static inline s32 get_text_width(u8 *str) {
    s32 width = 0;
    u32 code;
    FontGlyph *glyph;

    while (*str != 0) {
        /* A trailing Shift-JIS full stop or comma (lbl_801A63F0 / lbl_801A63F4)
           does not count towards the width. */
        if (fn_80083BCC((char *)str, lbl_801A63F0) == 0) {
            break;
        }
        if (fn_80083BCC((char *)str, lbl_801A63F4) == 0) {
            break;
        }
        if (is_wide(str)) {
            code = *(u16 *)str;
            str += 2;
        } else {
            code = *str;
            str += 1;
        }
        if (code == 0x20) {
            width += 8.0;
            continue;
        }
        glyph = find_glyph(code);
        if (glyph != NULL) {
            width += glyph->width;
        }
    }
    return width;
}

static inline void show_message(s32 msg) {
    StringGroup *group;
    s32 i;

    fn_80007B68();
    if (msg >= 0) {
        fn_80005EDC();
        group = &lbl_801A66F4[msg];
        for (i = 0; i < group->count; i++) {
            fn_800060D8(320.0 - 0.5 * get_text_width(group->lines[i]),
                        240.0 - 0.5 * (24.0 * group->count) + 24.0 * i,
                        10.0f, group->lines[i]);
        }
    }
    fn_8006FDEC();
    fn_8006FEFC();
    fn_8006FD1C();
}

static inline BOOL is_done(s32 status, s32 shown) {
    if (status == 0) {
        return TRUE;
    }
    if (!shown && status == 1) {
        return TRUE;
    }
    return FALSE;
}

void fn_8000659C(void) {
    s32 status;
    s32 shown;
    s32 msg;

    if (lbl_801A66DC != NULL && lbl_801A66DC() != 0) {
        return;
    }
    msg = -1;
    shown = 0;
    do {
        status = DVDGetDriveStatus();
        if (status != -1) {
            lbl_801A66D8 = 1;
            lbl_801A66E0();
            lbl_801A66D8 = 0;
        }
        /* DVD_STATE_*: -1 fatal error, 0 end, 1 busy, 4 no disk, 5 cover open,
           6 wrong disk, 11 retry */
        switch (status) {
        case 4:
            msg = 1;
            break;
        case 5:
            msg = 0;
            break;
        case 6:
            msg = 2;
            break;
        case 11:
            msg = 3;
            break;
        case -1:
            msg = 4;
            break;
        default:
            if (shown) {
                msg = 5;
            }
            break;
        case 0:
            msg = -1;
            break;
        }
        if (msg >= 0) {
            if (!shown) {
                if (lbl_801A66E8 != NULL) {
                    lbl_801A66E8();
                }
                shown = 1;
            }
            show_message(msg);
        }
    } while (!is_done(status, shown));
    if (shown && lbl_801A66E4 != NULL) {
        lbl_801A66E4();
    }
}
