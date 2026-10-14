/* Non-matching: best partial attempt (93.14% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

#pragma opt_propagation off

typedef struct {
    u8 pad[0x3C];
} DVDFileInfo;

typedef struct {
    u8 state;
    u8 pad1;
    s8 mode;
    u8 pad2;
    u32 f4;
    u32 f8;
    s32 status;
    u8 pad3[0x18];
    DVDFileInfo info;
} Fn80055EC0_Obj;

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 pad[3];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
} Fn80055EC0_Globals;

typedef u32 (*Fn80055EC0_Cb)(u32, u32, u32);

extern Fn80055EC0_Globals lbl_801878B8;
extern char lbl_80091F50[];
extern u32 DVDGetCommandBlockStatus(DVDFileInfo *);
extern s32 DVDGetDriveStatus(void);
extern s32 fn_80019B78(DVDFileInfo *);
extern u32 OSGetTick(void);
extern s32 DVDClose(DVDFileInfo *);
extern void *memset(void *, int, u32);

void fn_80055EC0(Fn80055EC0_Obj *arg0) {
    u8 *rodata = (u8 *)&lbl_80091F50;
    Fn80055EC0_Globals *gp = &lbl_801878B8;
    Fn80055EC0_Obj *body = arg0;
    Fn80055EC0_Obj *tail = arg0;
    Fn80055EC0_Globals *busy = gp;
    s32 res;
    u32 start;
    u32 last;
    u32 now;
    u32 elapsed;

    if (arg0 != 0) {
        if (arg0 == 0) {
            if (gp->unk_10 != 0) {
                ((Fn80055EC0_Cb)gp->unk_10)(gp->unk_C, (u32)rodata + 0x2c, 0);
            }
        } else {
            if (body->mode != 1 && (s8)body->mode != 0) {
                DVDGetCommandBlockStatus(&body->info);
                DVDGetDriveStatus();
                busy->unk_8 = 1;
                res = fn_80019B78(&body->info);
                busy->unk_8 = 0;
                if (res < 0) {
                    if (gp->unk_10 != 0) {
                        ((Fn80055EC0_Cb)gp->unk_10)(gp->unk_C, (u32)rodata + 0x90, (u32)body);
                    }
                } else {
                    start = OSGetTick() / (*(vu32 *)0x800000F8 / 4 / 1000);
                    last = -1 - start;
                    while ((body->status == 0 || body->status == 10) == 0) {
                        body->status = (s32)DVDGetCommandBlockStatus(&body->info);
                        gp->unk_0 = (u32)body->status;
                        now = OSGetTick() / (*(vu32 *)0x800000F8 / 4 / 1000);
                        elapsed = (now >= start) ? (now - start) : (last + now);
                        if (elapsed > 2000) {
                            if (gp->unk_10 != 0) {
                                ((Fn80055EC0_Cb)gp->unk_10)(gp->unk_C, (u32)rodata + 0xac, (u32)body);
                            }
                            break;
                        }
                    }
                    body->mode = 0;
                    gp->unk_4 = 0;
                    DVDGetCommandBlockStatus(&body->info);
                    DVDGetDriveStatus();
                }
            }
        }
        DVDClose(&tail->info);
        tail->state = 0;
        memset(tail, 0, 0x64);
    }
}
