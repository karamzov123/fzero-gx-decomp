/* Non-matching: best partial attempt (42.20% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/memcard.h"

extern void *lbl_801A6410;
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern s32 CARDUnmount(u8);
extern void fn_1_46B4(u32, u32, const char *, int);
extern const char *fn_80019C48(void);
extern size_t strlen(const char *);
extern u8 *fn_80083970(u8 *, const u8 *);
extern s32 strncmp(const char *, const char *, size_t);
extern char *strncpy(char *, const char *, size_t);
extern f32 lbl_1_rodata_4CA8;
extern f32 lbl_1_rodata_4AE0[114];
extern u8 jumptable_1_data_3CB68[0x9C];

typedef struct {
    u8 pad0[1];
    u8 kind;
    u8 pad2[2];
    s32 result;
    u32 flags;
    u8 padc[0x10];
    char name[0x28];
    char ext[2];
    u8 pad4a[0x4a];
    u32 ptr;
    u8 pad98[0xA8];
    u32 options;
} MCSub;

typedef struct {
    u8 state;
    s8 error;
    u8 mode;
    u8 status;
    u8 command;
    u8 prev;
    u8 next;
    u8 unk7;
    s16 a;
    s16 b;
    u32 ptr;
    u8 pad10[0x14];
    u32 sub;
    s8 timeout;
    u8 pad29;
    u8 flags;
    u8 pad2b;
    u8 count;
    u8 index;
    u8 pad2e[2];
    u32 ptr30;
    f32 f34;
    f32 f38;
} MC;

void fn_1_B171C(MC *p) {
    u8 *base = (u8 *)&lbl_1_data_35AC8;
    u8 *global = (u8 *)&lbl_1_bss_716C0;
#define s ((MCSub *)p->sub)
    OSReport((const char *)(base + 0x708c), p->command);
    if (p->command != 0xff) {
        if (p->command > 0x26) {
            OSReport((const char *)(base + 0x6ddc));
            OSReport((const char *)(base + 0x6df0), p->status);
            OSPanic((const char *)(base + 0x6cf0), 0x151c, (const char *)(base + 0x6e04));
        } else switch (p->command) {
        case 1:
            s->flags &= ~0x100;
            if (s->flags & 0x10000) {
                p->status = 0x1b;
            } else if (lbl_1_bss_9F8.unk_8 & 0x100) {
                p->status = 0x1b;
            } else if (lbl_1_bss_9F8.unk_8 & 0x10) {
                if (!(s->flags & 0x40000000)) {
                    if (p->command == 3 && p->ptr) {
                        while (CARDUnmount(p->state) == -1) {}
                        fn_1_46B4(*(u32 *)lbl_801A6410, p->ptr, (const char *)(base + 0x6cf0), 0x152e);
                        p->unk7 = 0; p->ptr = 0; s->ptr = 0; *((u32 *)s + 6) = 0;
                    }
                    if (p->next != 0xff) { p->status = p->next; p->next = 0xff; }
                    else p->status = p->command;
                    p->a = -1; p->b = -1; p->flags &= ~2;
                }
            } else if ((lbl_1_bss_9F8.unk_8 & 0x40) && (s->flags & 0x20000000)) {
                p->status = 5; s->flags &= ~0x200; s->flags |= 0x200; p->flags = (p->flags & ~2) | 0x10;
            }
            global[0x5c49] = 0;
            break;
        case 27:
            if (s->flags & 0x10000) p->mode = 0xfe;
            else if (lbl_1_bss_9F8.unk_8 & 0x100) p->mode = 0xfe;
            break;
        case 3:
            if ((s32)p->error == -127) { s->result = p->error; p->status = 1; break; }
            switch (s->result) {
            case -5: s->flags |= 2; p->status = 1; break;
            case -128: case -3: p->status = 1; break;
            case -13:
                if (s->flags & 0x10000) { p->flags |= 4; p->mode=0xfe; }
                else if (*(s32 *)0x801A66B4 == 5) p->status=5;
                else { s->flags |= 0x400; p->status=1; }
                break;
            case -6: case 0: p->status=4; break;
            case -1: break;
            default: p->status=0; break;
            }
            break;
        case 4:
            switch (s->result) {
            case -5: s->flags |= 2; p->status=1; break;
            case -128: case -3: p->status=1; break;
            case -13:
                if (s->flags & 0x10000) { p->flags |= 4; p->mode=0xfe; }
                else if (*(s32 *)0x801A66B4 == 5) p->status=5;
                else { s->flags |= 0x400; p->status=1; }
                break;
            case -6: p->status=7; break;
            case -1: break;
            case 0: p->status=5; break;
            default: p->status=0; break;
            }
            break;
        case 5:
            if (s->result != 0) {
                if (!(p->flags & 1)) { p->timeout=12; p->flags |= 1; }
                else if ((s8)p->timeout > 0) p->timeout--;
                else { p->status=6; s->flags |= 0x200; break; }
                if (s->result == 2 || s->kind == 1) { s->result=-126; p->status=1; }
                else { p->status=6; s->flags |= 0x200; }
            }
            break;
        case 6:
            switch(s->result) {
            case -3: case -128: p->status=1; break;
            case -5: s->flags|=2; p->status=1; break;
            case 0: p->status=0x16; s->flags &= ~0x100; break;
            case -1: break;
            default: p->status=0; break;
            }
            break;
        case 7:
            if (lbl_1_bss_9F8.unk_8 & 0x100) { p->status=0x1b; s->result=-121; }
            break;
        case 25:
            switch (s->result) {
            case -4: case -10: p->count++; break;
            case -128: p->status=1; goto finish25;
            case -1: break;
            case -2: p->status=1; break;
            case 0: p->status=0; break;
            default: p->status=0; break;
            }
            break;
        finish25:
            if (p->count == 0x7f || p->status == 0xff) {
                ((u32 *)((u8 *)s + 0x94))[p->index * 12 + 9] = 0;
                if (p->status == 0xff) p->status=0x1a;
            }
            break;
        case 22:
            if (lbl_1_bss_9F8.unk_8 & 0x100) {
                p->status=0x1b; s->result=-121;
            }
            break;
        case 38:
            p->status=3;
            break;
        case 26:
            if (s->flags & 0x20000000) {
                if (!(s->flags & 0x10000000)) { p->timeout=0x2d; s->flags |= 8; }
                else if ((s8)p->timeout > 0) p->timeout--;
                else {
                    fn_1_46B4(*(u32 *)lbl_801A6410, s->result, (const char *)(base + 0x6cf0), 0x3ec);
                    p->sub=0; p->mode=p->status=p->command=p->prev=p->next=0xff; p->unk7=0; p->a=p->b=-1; p->ptr=0; p->f34=0.0f; p->f38=0.0f; p->flags &= ~2; global[0x5c08]=0; global[0x1f8]=1;
                }
            } else if (lbl_1_bss_9F8.unk_8 & 0x100) {
                fn_1_46B4(*(u32 *)lbl_801A6410, s->result, (const char *)(base + 0x6cf0), 0x3ec);
                p->sub=0; p->mode=p->status=p->command=p->prev=p->next=0xff; p->unk7=0; p->a=p->b=-1; p->ptr=0; p->f34=0.0f; p->f38=0.0f; p->flags &= ~2; global[0x5c08]=0; global[0x1f8]=1;
            }
            break;
        default:
            break;
        }
    }
    if (p->sub) s->result = ((MCSub *)p->sub)->result;
}
