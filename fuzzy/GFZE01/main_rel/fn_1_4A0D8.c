/* Non-matching: best partial attempt (35.60% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#include "rel/main_rel/bitmap.h"
#include "psvec.h"

extern f32 lbl_1_rodata_FD0[60];
extern f32 fn_1_4B090(const char *);
extern f32 fn_1_4B040(const char *);
extern s32 fn_1_4B1A0(const char *);
extern u16 fn_1_499BC(const u8 *);
extern s32 fn_1_49B70(u8 *, void *);
extern u32 fn_1_49794(u32);
extern u32 fn_1_49F08(u32, void *, void *);
extern void fn_1_4A0D8(const char *);
extern void *fn_1_4B6D4(void *, void *, void *, f32);
extern void *fn_1_4B788(void *, void *, void *, f32);
extern void fn_1_4AC20(void *);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(void *, const void *, u32);

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    s16 glyph;
    s16 unk_e;
    u32 unk10;
    u32 unk14;
    f32 x;
    f32 spacing;
    f32 scaleY;
    f32 unk24;
    f32 y;
    u32 flags;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    u8 mode;
    s8 unk37;
    f32 unk38;
    f32 unk3c;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4c;
    f32 unk50;
    u32 unk54;
    u32 unk58;
} FontState;

typedef struct {
    s32 glyph;
    u8 pad4[8];
    f32 x;
    u8 pad10[0x18];
    s16 unk28;
    u8 pad2a[2];
    f32 y;
    u32 flags;
    u8 pad34[4];
    u32 unk38;
    u32 unk3c;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4c;
    u32 unk50;
    u32 unk54;
    u32 unk58;
} DrawData;

void fn_1_4A0D8(const char *s) {
    FontState *state;
    FontState *state2;
    DrawData draw;
    u8 *text;
    u8 *glyph;
    u8 *mgr;
    u8 *pool;
    u16 ch;
    u32 code, flags;
    s32 index, found, i, n, wide;
    f32 advance, limit, ratio, offset, baseline;
    int first;
    mgr = (u8 *)&lbl_1_bss_3E058;
    pool = (u8 *)lbl_1_rodata_FD0;
    state = (FontState *)(mgr + 0x10000 - 0x268c);
    first = 1;
    ratio = 0.0f;
    if (s == 0) {
        if (*(s32 *)(mgr + 0x10000 - 0x268c + 0x5c) == 0)
            *(s32 *)(mgr + 0x10000 - 0x268c + 0x5c) = 1;
        return;
    }
    state2 = (FontState *)(mgr + 0x10000 - 0x268c);
    glyph = (u8 *)&lbl_1_data_1AEA8 + (s16)state->glyph * 0x38;
    fn_80008BEC(&draw, 0, 0x58);
    draw.glyph = *(s32 *)glyph;
    draw.x = state->x;
    draw.y = state->y;
    draw.unk28 = state->unk_e;
    draw.unk38 = state->unk10;
    draw.unk3c = state->unk14;
    flags = state->flags | state->unk58;
    if (draw.glyph == -1)
        flags |= 0x40000000;
    draw.flags = flags;
    if ((state->mode & 0x18) == 8)
        state->y -= fn_1_4B090(s) * 0.5f;
    if ((state->mode & 0x18) == 16)
        state->y -= fn_1_4B090(s);
    text = (u8 *)s;
    for (;;) {
        u8 *p;
        if ((state->flags & 0x10000) != 0)
            state->x += 0.01f;
        if (first) {
            advance = fn_1_4B040(s);
            limit = (f32)fn_1_4B1A0(s);
            if ((state->mode & 4) && state->unk30 > advance)
                ratio = (limit - 1.0f - advance) / limit;
            else
                ratio = 0.0f;
            first = 0;
        }
        ch = *text;
        if ((state->flags & 4) && ch >= 'a' && ch <= 'z')
            ch -= 32;
        if (ch >= 0x80) {
            ch = (ch << 8) | *++text;
            if (ch == 0x8140) {
                index = fn_1_49F08(ch, state, glyph);
                state->unk4 += (f32)(u16)index * state->spacing + state->unk3c;
                goto nextchar;
            }
            found = -2;
            i = 0;
            while (((u16 *)(*(u32 *)(glyph + 0x2c)))[i] != 0) {
                if (((u16 *)(*(u32 *)(glyph + 0x2c)))[i] == ch) {
                    index = fn_1_49F08(ch, state, glyph);
                    found = ((s16 *)(*(u32 *)(glyph + 0x30)))[i];
                    break;
                }
                i++;
            }
            if (found >= 0) {
                wide = 1;
            } else {
                goto advance_char;
            }
        } else {
            wide = 0;
            index = fn_1_49F08(ch, state, glyph);
            if (ch == 10) {
                state->x = *(u8 *)(glyph + 5);
                state->y += *(u8 *)(glyph + 5) * state->scaleY + state->unk40 + state->unk8;
                goto nextchar;
            }
            if (ch == 32) {
                state->x += (f32)(u16)index * state->spacing + state->unk3c;
                goto nextchar;
            }
            if (ch == '[' && *(s32 *)mgr != 0) {
                u8 buf[32];
                int len = 0;
                do {
                    text++;
                    ch = fn_1_499BC(text);
                    if (ch >= 0x80) {
                        fn_80008BA8(buf + (u8)len, text, 2);
                        text++;
                        len += 2;
                    } else if (ch != ']') {
                        buf[(u8)len++] = *text;
                    }
                } while (ch != ']');
                buf[(u8)len] = 0;
                if (lbl_1_data_1BCC4 != 0) {
                    fn_80008BA8((u8 *)&draw + 0x28, state, 0x5c);
                    fn_1_4A0D8((char *)buf);
                    fn_80008BA8(state, (u8 *)&draw + 0x28, 0x5c);
                }
                goto nextchar;
            }
            if (ch < *(u32 *)(glyph + 8) || ch > *(u32 *)(glyph + 0xc))
                goto advance_char;
        }
        if (wide == 0)
            found = index;
        if (found < 0)
            goto advance_char;
        if ((state->mode & 3) == 2)
            offset = state->x - advance;
        else if ((state->mode & 3) == 1)
            offset = state->x - advance * 0.5f;
        else
            offset = state->x;
        draw.x = offset;
        draw.y = state->unk8;
        draw.unk38 = state->scaleY;
        draw.unk3c = state->unk24;
        draw.unk40 = state->y;
        draw.unk44 = state->unk44;
        draw.unk48 = state->unk48;
        draw.unk4c = state->unk4c;
        draw.unk50 = state->unk50;
        if (state->unk54 != 0) {
            draw.unk54 = state->unk54;
            draw.unk48 = state->unk50;
            draw.flags |= 0x400;
        }
        if (*(s32 *)(mgr + 0x10000 - 0x2628)) {
            draw.y += advance;
            fn_1_4B6D4(&draw, state, glyph, limit);
            draw.y -= advance;
        }
        if (*(s32 *)(mgr + 0x10000 - 0x2614)) {
            draw.y += advance;
            fn_1_4B788(&draw, state, glyph, limit);
            draw.y -= advance;
        }
        if (wide) {
            u16 *table = (u16 *)(*(u32 *)(glyph + 0x2c));
            if (table && table[0] >= 0x839f && table[0] <= 0x83b8)
                draw.flags |= 0x1000;
            else
                draw.flags &= ~0x1000;
        } else {
            draw.flags &= ~0x1000;
        }
        if ((draw.flags & 0x10000) && (state->flags & 2)) {
            draw.x += state->unk32;
            draw.y += state->unk34;
            draw.unk3c += 0.02f;
            draw.unk48 = state->y * state->unk38;
            draw.unk38 = *(u32 *)(pool + 0x1698);
            fn_1_4AC20(&draw);
            draw.x -= state->unk32;
            draw.y -= state->unk34;
            draw.unk3c -= 0.02f;
            draw.unk38 = state->unk10;
        }
        fn_1_4AC20(&draw);
advance_char:
        state->x += (f32)(u16)index * state->spacing + state->unk3c + ratio;
nextchar:
        text++;
        if (*text == 0)
            break;
    }
    if ((state2->mode & 0x18) == 8)
        state2->y += fn_1_4B090(s) * 0.5f;
    if ((state2->mode & 0x18) == 16)
        state2->y += fn_1_4B090(s);
}
