#include <types.h>
#include "sdk_addresses.h"
#include "types.h"
#include <dolphin/gx/GXPriv.h>

/* --- dol/__GXSetGenMode.c --- */
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void __GXSetGenMode(void);

/* --- dol/GXAdjustForOverscan.c --- */

void GXAdjustForOverscan(GXRenderModeObj *rmin, GXRenderModeObj *rmout, u16 hor, u16 ver) {
    unsigned short hor2 = hor * 2;
    unsigned short ver2 = ver * 2;
    unsigned long verf;
    if (rmin != rmout) {
        *rmout = *rmin;
    }
    rmout->fbWidth = rmin->fbWidth - hor2;
    verf = (ver2 * rmin->efbHeight) / (u32)rmin->xfbHeight;
    rmout->efbHeight = rmin->efbHeight - verf;
    if (rmin->xFBmode == VI_XFBMODE_SF && (rmin->viTVmode & 2) != 2) {
        rmout->xfbHeight = rmin->xfbHeight - ver;
    } else {
        rmout->xfbHeight = rmin->xfbHeight - ver2;
    }
    rmout->viWidth = rmin->viWidth - hor2;
    rmout->viHeight = rmin->viHeight - ver2;
    rmout->viXOrigin = rmin->viXOrigin + hor;
    rmout->viYOrigin = rmin->viYOrigin + ver;
}
