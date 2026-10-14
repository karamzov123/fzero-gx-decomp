/* Non-matching: best partial attempt (87.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct Sig_fn_80089EEC_TRKBuffer {
    u32 mutex;
    u32 isInUse;
    u32 length;
    u32 position;
    u8 data[0x880];
} Sig_fn_80089EEC_TRKBuffer;
struct Sig_fn_80089174_fn_80089174_Arg0 {
    u8 pad_0[8];
    u32 unk_8;
    u32 unk_C;
};
typedef int Sig_TRKAppendBuffer_ui8_DSError;
typedef struct Sig_TRKAppendBuffer_ui8_TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[0x880];
} Sig_TRKAppendBuffer_ui8_TRKBuffer;
typedef enum {
    Sig_TRKTargetAccessDefault_DS_NoError = 0,
    Sig_TRKTargetAccessDefault_DS_InvalidRegister = 0x701,
    Sig_TRKTargetAccessDefault_DS_CWDSException = 0x702,
    Sig_TRKTargetAccessDefault_DS_UnsupportedError = 0x703,
    Sig_TRKTargetAccessDefault_DS_InvalidProcessID = 0x704,
    Sig_TRKTargetAccessDefault_DS_InvalidThreadID = 0x705,
    Sig_TRKTargetAccessDefault_DS_OSError = 0x706
} Sig_TRKTargetAccessDefault_DSError;
typedef struct Sig_TRKTargetAccessDefault_TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[0x880];
} Sig_TRKTargetAccessDefault_TRKBuffer;
typedef int Sig_fn_8008BFB4_DSError;
typedef struct Sig_fn_8008BFB4_TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[0x880];
} Sig_fn_8008BFB4_TRKBuffer;
struct Sig_fn_80088B00_fn_80088B00_Arg0 { u8 pad_0[8]; u32 unk_8; };
struct fn_80089EEC_Header { u32 unk_0; u8 unk_4; u8 pad_5[3]; u8 unk_8; u8 pad_9[0x37]; };
extern Sig_TRKAppendBuffer_ui8_DSError TRKAppendBuffer_ui8(Sig_TRKAppendBuffer_ui8_TRKBuffer *, const u8 *, int);
extern Sig_TRKTargetAccessDefault_DSError TRKTargetAccessDefault(u32,u32,Sig_TRKTargetAccessDefault_TRKBuffer *,size_t *,BOOL);
extern Sig_fn_8008BFB4_DSError fn_8008BFB4(u32,u32,Sig_fn_8008BFB4_TRKBuffer *,size_t *,BOOL);
extern s32 fn_80088B00(struct Sig_fn_80088B00_fn_80088B00_Arg0 *);
extern u32 fn_8008D398(u32,u32);
extern u32 fn_80089174(struct Sig_fn_80089174_fn_80089174_Arg0 *,u32);
extern u32 fn_8008BB7C(u32,u32,u32,void *,u32);
extern u32 fn_8008C124(u32,u32,u32,void *,u32);
extern u8 lbl_80095890[];
extern void *memset(void *,s32,u32);
extern u32 MWTRACE(u32,...);

#pragma opt_common_subs off
#pragma opt_lifetimes off
s32 fn_80089EEC(Sig_fn_80089EEC_TRKBuffer *arg0) {
    u8 *p_lbl_80095890 = (u8 *)&lbl_80095890;
    s32 v10;
    struct { s32 value; } v12;
    struct { struct fn_80089EEC_Header header; u8 extra[8]; } loc_8C;
    struct fn_80089EEC_Header loc_4C;
    struct fn_80089EEC_Header loc_C;
    u32 loc_8;
    void * lab_t0;
    if (*(u16 *)((u8 *)arg0 + 28) > *(u16 *)((u8 *)arg0 + 32)) {
        memset(&loc_4C,0,64);
        loc_4C.unk_4 = 128;
        loc_4C.unk_0 = 64;
        loc_4C.unk_8 = 20;
        fn_8008D398((u32)&loc_4C,64);
        return 0;
    }
    loc_8C.header.unk_4 = 128;
    loc_8C.header.unk_0 = 1128;
    fn_80089174((struct Sig_fn_80089174_fn_80089174_Arg0 *)arg0,0);
    MWTRACE(4,(u32)(p_lbl_80095890+152),arg0->length);
    TRKAppendBuffer_ui8((Sig_TRKAppendBuffer_ui8_TRKBuffer *)arg0,(const u8 *)&loc_8C,64);
    MWTRACE(4,(u32)(p_lbl_80095890+152),arg0->length);
    v10 = TRKTargetAccessDefault(0,36,(Sig_TRKTargetAccessDefault_TRKBuffer *)arg0,(size_t *)&loc_8,1);
    MWTRACE(4,(u32)(p_lbl_80095890+192),v10);
    MWTRACE(4,(u32)(p_lbl_80095890+152),arg0->length);
    if (!v10) v10 = fn_8008C124(0,33,(u32)arg0,&loc_8,1);
    MWTRACE(4,(u32)(p_lbl_80095890+248),v10);
    MWTRACE(4,(u32)(p_lbl_80095890+152),arg0->length);
    if (!v10) v10 = fn_8008BFB4(0,96,(Sig_fn_8008BFB4_TRKBuffer *)arg0,(size_t *)&loc_8,1);
    MWTRACE(4,(u32)(p_lbl_80095890+288),v10);
    MWTRACE(4,(u32)(p_lbl_80095890+152),arg0->length);
    if (!v10) v10 = fn_8008BB7C(0,31,(u32)arg0,&loc_8,1);
    MWTRACE(4,(u32)(p_lbl_80095890+336),v10);
    MWTRACE(4,(u32)(p_lbl_80095890+152),arg0->length);
    if (v10) {
        switch (v10) {
        case 1795: v10 = 18; break;
        case 1793: v10 = 20; break;
        case 1794: v10 = 21; break;
        case 1796: v10 = 33; break;
        case 1797: v10 = 34; break;
        case 1798: v10 = 32; break;
        default: v10 = 3; break;
        }
        lab_t0 = &loc_C;
        memset(lab_t0, 0, 64);
        loc_C.unk_4 = 128;
        loc_C.unk_0 = 64;
        loc_C.unk_8 = v10;
        fn_8008D398((u32)&loc_C,64);
        return 0;
    }
    MWTRACE(1,(u32)(p_lbl_80095890+96));
    v12.value = fn_80088B00((struct Sig_fn_80088B00_fn_80088B00_Arg0 *)arg0);
    MWTRACE(1,(u32)(p_lbl_80095890+128),v12.value);
    return v12.value;
}
#pragma opt_lifetimes reset

#pragma opt_common_subs reset

