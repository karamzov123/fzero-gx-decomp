/* Non-matching: best partial attempt (88.88% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/hw_regs.h"
typedef struct { f32 x,y,z; } ClosureCameraVec;
extern const f32 lbl_1_rodata_78D0;
extern u8 lbl_1_bss_85298[0x220];
extern s32 lbl_1_bss_85294;
extern u32 fn_1_5948(u32);
extern s16 camera_get_mode(void);
extern void fn_1_862D4(s32,void *);
extern void fn_1_8636C(s32,void *);
extern void fn_1_627C(s32);
extern void lbl_8006D784(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DB30(void);
extern void lbl_8006DAEC(void);
extern u8 *lbl_801A6D00;
#pragma fp_contract off
void fn_1_104730(s32 index,s32 update) {
    ClosureCameraVec position;
    const u8 *r=(const u8 *)&lbl_1_rodata_78D0;
    s32 original=index;
    u8 *state;
    s32 mode;
    f32 forward,up;
    f32 forward2,up2,forward3,up3;
    fn_1_5948(index);
    mode=camera_get_mode();
    state=lbl_1_bss_85298+index*0x88;
    if(mode==-1) {
        *(f32 *)(state+0x30)=*(f32 *)(r+0xc4);
        *(f32 *)(state+0x34)=*(f32 *)(r+0xc8);
        *(f32 *)(state+0x38)=*(f32 *)(r+0xcc);
        *(f32 *)(state+0x3c)=*(f32 *)(r+0xd0);
        *(f32 *)(state+0x40)=*(f32 *)(r+0xd4);
        *(f32 *)(state+0x44)=*(f32 *)(r+0xd8);
        *(f32 *)(&position.x)=*(f32 *)(r+0xb8);
        *(f32 *)(&position.y)=*(f32 *)(r+0xbc);
        *(f32 *)(&position.z)=*(f32 *)(r+0xc0);
        lbl_8006D784(state+0x48);
    } else {
        lbl_8006DAEC();
        fn_1_862D4(mode,&position);
        if(update) {
            u8 *cam;
            volatile f32 *lc=(volatile f32 *)LC_BASE; /* fzgx-allow: S2 locked-cache hardware storage */
            fn_1_8636C(mode,lbl_801A6D00);
            { f32 zero=*(f32 *)(r+0x18); lc[3]=zero; lc[7]=zero; lc[11]=zero; }
            cam=lbl_801A6D00;
            *(f32 *)(state+0x30)=-*(f32 *)(cam+8);
            *(f32 *)(state+0x34)=-*(f32 *)(cam+0x18);
            *(f32 *)(state+0x38)=-*(f32 *)(cam+0x28);
            *(f32 *)(state+0x3c)=*(f32 *)(cam+4);
            *(f32 *)(state+0x40)=*(f32 *)(cam+0x14);
            *(f32 *)(state+0x44)=*(f32 *)(cam+0x24);
            lbl_8006DB74(state+0x48);
        }
        lbl_8006DB30();
    }
    switch(lbl_1_bss_85294%2) {
    case 0: forward=*(f32 *)(r+0xdc); up=*(f32 *)(r+0xe0); break;
    case 1:
    default: forward=*(f32 *)(r+0xe4); up=*(f32 *)(r+0xe8); break;
    }
    forward2=*(f32 *)(r+0xe4); up2=*(f32 *)(r+0xe0);
    forward3=*(f32 *)(r+0xec); up3=*(f32 *)(r+0xf0);
    *(f32 *)(state+0xc)=position.x+*(f32 *)(state+0x30)*forward+*(f32 *)(state+0x3c)*up;
    *(f32 *)(state+0x10)=position.y+*(f32 *)(state+0x34)*forward+*(f32 *)(state+0x40)*up;
    *(f32 *)(state+0x14)=position.z+*(f32 *)(state+0x38)*forward+*(f32 *)(state+0x44)*up;
    *(f32 *)(state+0x18)=position.x+forward2* *(f32 *)(state+0x30)+up2* *(f32 *)(state+0x3c);
    *(f32 *)(state+0x1c)=position.y+forward2* *(f32 *)(state+0x34)+up2* *(f32 *)(state+0x40);
    *(f32 *)(state+0x20)=position.z+forward2* *(f32 *)(state+0x38)+up2* *(f32 *)(state+0x44);
    *(f32 *)(state+0x24)=position.x+*(f32 *)(state+0x30)*forward3+*(f32 *)(state+0x3c)*up3;
    *(f32 *)(state+0x28)=position.y+*(f32 *)(state+0x34)*forward3+*(f32 *)(state+0x40)*up3;
    *(f32 *)(state+0x2c)=position.z+*(f32 *)(state+0x38)*forward3+*(f32 *)(state+0x44)*up3;
    fn_1_627C(original);
}
#pragma fp_contract reset
