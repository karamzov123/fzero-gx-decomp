#include "types.h"


extern s32 lbl_801A6B80;
extern s32 lbl_801A6B84;
extern u32 lbl_801A6B88;
extern u32 lbl_801A6B8C;


typedef struct AXPBMIX {
    unsigned short vL, vDeltaL, vR, vDeltaR;
    unsigned short vAuxAL, vDeltaAuxAL, vAuxAR, vDeltaAuxAR;
    unsigned short vAuxBL, vDeltaAuxBL, vAuxBR, vDeltaAuxBR;
    unsigned short vAuxBS, vDeltaAuxBS, vS, vDeltaS;
    unsigned short vAuxAS, vDeltaAuxAS;
} AXPBMIX;
typedef struct AXPBITD {
    unsigned short flag, bufferHi, bufferLo, shiftL, shiftR;
    unsigned short targetShiftL, targetShiftR;
} AXPBITD;
typedef struct AXPBUPDATE {
    unsigned short updNum[5];
    unsigned short dataHi, dataLo;
} AXPBUPDATE;
typedef struct AXPBDPOP {
    short aL, aAuxAL, aAuxBL, aR, aAuxAR, aAuxBR, aS, aAuxAS, aAuxBS;
} AXPBDPOP;
typedef struct AXPBVE {
    unsigned short currentVolume;
    short currentDelta;
} AXPBVE;
typedef struct AXPBFIR {
    unsigned short numCoefs, coefsHi, coefsLo;
} AXPBFIR;
typedef struct AXPBADDR {
    unsigned short loopFlag, format;
    unsigned short loopAddressHi, loopAddressLo;
    unsigned short endAddressHi, endAddressLo;
    unsigned short currentAddressHi, currentAddressLo;
} AXPBADDR;
typedef struct AXPBADPCM {
    unsigned short a[8][2];
    unsigned short gain, pred_scale, yn1, yn2;
} AXPBADPCM;
typedef struct AXPBSRC {
    unsigned short ratioHi, ratioLo, currentAddressFrac;
    unsigned short last_samples[4];
} AXPBSRC;
typedef struct AXPBADPCMLOOP {
    unsigned short loop_pred_scale, loop_yn1, loop_yn2;
} AXPBADPCMLOOP;
typedef struct AXPBLPF {
    unsigned short on, yn1, a0, b0;
} AXPBLPF;
typedef struct AXPB {
    unsigned short nextHi, nextLo, currHi, currLo;
    unsigned short srcSelect, coefSelect, mixerCtrl, state, type;
    AXPBMIX mix;
    AXPBITD itd;
    AXPBUPDATE update;
    AXPBDPOP dpop;
    AXPBVE ve;
    AXPBFIR fir;
    AXPBADDR addr;
    AXPBADPCM adpcm;
    AXPBSRC src;
    AXPBADPCMLOOP adpcmLoop;
    AXPBLPF lpf;
    unsigned short pad[25];
} AXPB;
typedef struct _AXVPB {
    struct _AXVPB *next;
    struct _AXVPB *prev;
    struct _AXVPB *next1;
    unsigned long priority;
    void (*callback)(void *);
    unsigned long user_context;
    unsigned long index, sync, depop;
    unsigned long updateMS, updateCounter, updateTotal;
    unsigned short *updateWrite;
    unsigned short updateData[128];
    void *itdBuffer;
    AXPB pb;
} AXVPB;
int OSDisableInterrupts(void);
int OSRestoreInterrupts(int enabled);
struct MIXChannel {
    AXVPB *voice;
    u32 mode;
    s32 input;
    s32 aux_a;
    s32 aux_b;
    s32 pan;
    s32 surround_pan;
    s32 fader;
    s32 volumes[6];
    u16 v;
    u16 v1;
    u16 vL;
    u16 vL1;
    u16 vR;
    u16 vR1;
    u16 vS;
    u16 vS1;
    u16 vAL;
    u16 vAL1;
    u16 vAR;
    u16 vAR1;
    u16 vAS;
    u16 vAS1;
    u16 vBL;
    u16 vBL1;
    u16 vBR;
    u16 vBR1;
    u16 vBS;
    u16 vBS1;
};
extern struct MIXChannel lbl_80176160[64];
/* defined in the retail TU: MWCC hoists its address */
extern u8 lbl_80128990[];
static u16 __MIXVolumeTable[965] = {
    0x0000, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002,
    0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002,
    0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002,
    0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0003, 0x0003, 0x0003,
    0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003,
    0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003,
    0x0003, 0x0003, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
    0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
    0x0004, 0x0005, 0x0005, 0x0005, 0x0005, 0x0005, 0x0005, 0x0005, 0x0005, 0x0005,
    0x0005, 0x0005, 0x0005, 0x0005, 0x0005, 0x0005, 0x0005, 0x0006, 0x0006, 0x0006,
    0x0006, 0x0006, 0x0006, 0x0006, 0x0006, 0x0006, 0x0006, 0x0006, 0x0006, 0x0006,
    0x0007, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007,
    0x0007, 0x0007, 0x0008, 0x0008, 0x0008, 0x0008, 0x0008, 0x0008, 0x0008, 0x0008,
    0x0008, 0x0008, 0x0009, 0x0009, 0x0009, 0x0009, 0x0009, 0x0009, 0x0009, 0x0009,
    0x0009, 0x000A, 0x000A, 0x000A, 0x000A, 0x000A, 0x000A, 0x000A, 0x000A, 0x000A,
    0x000B, 0x000B, 0x000B, 0x000B, 0x000B, 0x000B, 0x000B, 0x000C, 0x000C, 0x000C,
    0x000C, 0x000C, 0x000C, 0x000C, 0x000D, 0x000D, 0x000D, 0x000D, 0x000D, 0x000D,
    0x000D, 0x000E, 0x000E, 0x000E, 0x000E, 0x000E, 0x000E, 0x000F, 0x000F, 0x000F,
    0x000F, 0x000F, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0011, 0x0011, 0x0011,
    0x0011, 0x0011, 0x0012, 0x0012, 0x0012, 0x0012, 0x0012, 0x0013, 0x0013, 0x0013,
    0x0013, 0x0013, 0x0014, 0x0014, 0x0014, 0x0014, 0x0015, 0x0015, 0x0015, 0x0015,
    0x0016, 0x0016, 0x0016, 0x0016, 0x0017, 0x0017, 0x0017, 0x0018, 0x0018, 0x0018,
    0x0018, 0x0019, 0x0019, 0x0019, 0x001A, 0x001A, 0x001A, 0x001A, 0x001B, 0x001B,
    0x001B, 0x001C, 0x001C, 0x001C, 0x001D, 0x001D, 0x001D, 0x001E, 0x001E, 0x001E,
    0x001F, 0x001F, 0x0020, 0x0020, 0x0020, 0x0021, 0x0021, 0x0021, 0x0022, 0x0022,
    0x0023, 0x0023, 0x0023, 0x0024, 0x0024, 0x0025, 0x0025, 0x0026, 0x0026, 0x0026,
    0x0027, 0x0027, 0x0028, 0x0028, 0x0029, 0x0029, 0x002A, 0x002A, 0x002B, 0x002B,
    0x002C, 0x002C, 0x002D, 0x002D, 0x002E, 0x002E, 0x002F, 0x002F, 0x0030, 0x0031,
    0x0031, 0x0032, 0x0032, 0x0033, 0x0033, 0x0034, 0x0035, 0x0035, 0x0036, 0x0037,
    0x0037, 0x0038, 0x0038, 0x0039, 0x003A, 0x003A, 0x003B, 0x003C, 0x003D, 0x003D,
    0x003E, 0x003F, 0x003F, 0x0040, 0x0041, 0x0042, 0x0042, 0x0043, 0x0044, 0x0045,
    0x0046, 0x0046, 0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004B, 0x004C, 0x004D,
    0x004E, 0x004F, 0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
    0x0058, 0x0059, 0x005A, 0x005B, 0x005C, 0x005D, 0x005E, 0x005F, 0x0060, 0x0061,
    0x0062, 0x0064, 0x0065, 0x0066, 0x0067, 0x0068, 0x006A, 0x006B, 0x006C, 0x006D,
    0x006F, 0x0070, 0x0071, 0x0072, 0x0074, 0x0075, 0x0076, 0x0078, 0x0079, 0x007B,
    0x007C, 0x007E, 0x007F, 0x0080, 0x0082, 0x0083, 0x0085, 0x0087, 0x0088, 0x008A,
    0x008B, 0x008D, 0x008F, 0x0090, 0x0092, 0x0094, 0x0095, 0x0097, 0x0099, 0x009B,
    0x009C, 0x009E, 0x00A0, 0x00A2, 0x00A4, 0x00A6, 0x00A8, 0x00AA, 0x00AB, 0x00AD,
    0x00AF, 0x00B2, 0x00B4, 0x00B6, 0x00B8, 0x00BA, 0x00BC, 0x00BE, 0x00C0, 0x00C3,
    0x00C5, 0x00C7, 0x00CA, 0x00CC, 0x00CE, 0x00D1, 0x00D3, 0x00D6, 0x00D8, 0x00DB,
    0x00DD, 0x00E0, 0x00E2, 0x00E5, 0x00E7, 0x00EA, 0x00ED, 0x00F0, 0x00F2, 0x00F5,
    0x00F8, 0x00FB, 0x00FE, 0x0101, 0x0104, 0x0107, 0x010A, 0x010D, 0x0110, 0x0113,
    0x0116, 0x011A, 0x011D, 0x0120, 0x0124, 0x0127, 0x012A, 0x012E, 0x0131, 0x0135,
    0x0138, 0x013C, 0x0140, 0x0143, 0x0147, 0x014B, 0x014F, 0x0153, 0x0157, 0x015B,
    0x015F, 0x0163, 0x0167, 0x016B, 0x016F, 0x0173, 0x0178, 0x017C, 0x0180, 0x0185,
    0x0189, 0x018E, 0x0193, 0x0197, 0x019C, 0x01A1, 0x01A6, 0x01AB, 0x01AF, 0x01B4,
    0x01BA, 0x01BF, 0x01C4, 0x01C9, 0x01CE, 0x01D4, 0x01D9, 0x01DF, 0x01E4, 0x01EA,
    0x01EF, 0x01F5, 0x01FB, 0x0201, 0x0207, 0x020D, 0x0213, 0x0219, 0x021F, 0x0226,
    0x022C, 0x0232, 0x0239, 0x0240, 0x0246, 0x024D, 0x0254, 0x025B, 0x0262, 0x0269,
    0x0270, 0x0277, 0x027E, 0x0286, 0x028D, 0x0295, 0x029D, 0x02A4, 0x02AC, 0x02B4,
    0x02BC, 0x02C4, 0x02CC, 0x02D5, 0x02DD, 0x02E6, 0x02EE, 0x02F7, 0x0300, 0x0309,
    0x0312, 0x031B, 0x0324, 0x032D, 0x0337, 0x0340, 0x034A, 0x0354, 0x035D, 0x0367,
    0x0371, 0x037C, 0x0386, 0x0390, 0x039B, 0x03A6, 0x03B1, 0x03BB, 0x03C7, 0x03D2,
    0x03DD, 0x03E9, 0x03F4, 0x0400, 0x040C, 0x0418, 0x0424, 0x0430, 0x043D, 0x0449,
    0x0456, 0x0463, 0x0470, 0x047D, 0x048A, 0x0498, 0x04A5, 0x04B3, 0x04C1, 0x04CF,
    0x04DD, 0x04EC, 0x04FA, 0x0509, 0x0518, 0x0527, 0x0536, 0x0546, 0x0555, 0x0565,
    0x0575, 0x0586, 0x0596, 0x05A6, 0x05B7, 0x05C8, 0x05D9, 0x05EB, 0x05FC, 0x060E,
    0x0620, 0x0632, 0x0644, 0x0657, 0x066A, 0x067D, 0x0690, 0x06A4, 0x06B7, 0x06CB,
    0x06DF, 0x06F4, 0x0708, 0x071D, 0x0732, 0x0748, 0x075D, 0x0773, 0x0789, 0x079F,
    0x07B6, 0x07CD, 0x07E4, 0x07FB, 0x0813, 0x082B, 0x0843, 0x085C, 0x0874, 0x088E,
    0x08A7, 0x08C1, 0x08DA, 0x08F5, 0x090F, 0x092A, 0x0945, 0x0961, 0x097D, 0x0999,
    0x09B5, 0x09D2, 0x09EF, 0x0A0D, 0x0A2A, 0x0A48, 0x0A67, 0x0A86, 0x0AA5, 0x0AC5,
    0x0AE5, 0x0B05, 0x0B25, 0x0B47, 0x0B68, 0x0B8A, 0x0BAC, 0x0BCF, 0x0BF2, 0x0C15,
    0x0C39, 0x0C5D, 0x0C82, 0x0CA7, 0x0CCC, 0x0CF2, 0x0D19, 0x0D3F, 0x0D67, 0x0D8E,
    0x0DB7, 0x0DDF, 0x0E08, 0x0E32, 0x0E5C, 0x0E87, 0x0EB2, 0x0EDD, 0x0F09, 0x0F36,
    0x0F63, 0x0F91, 0x0FBF, 0x0FEE, 0x101D, 0x104D, 0x107D, 0x10AE, 0x10DF, 0x1111,
    0x1144, 0x1177, 0x11AB, 0x11DF, 0x1214, 0x124A, 0x1280, 0x12B7, 0x12EE, 0x1326,
    0x135F, 0x1399, 0x13D3, 0x140D, 0x1449, 0x1485, 0x14C2, 0x14FF, 0x153E, 0x157D,
    0x15BC, 0x15FD, 0x163E, 0x1680, 0x16C3, 0x1706, 0x174A, 0x178F, 0x17D5, 0x181C,
    0x1863, 0x18AC, 0x18F5, 0x193F, 0x198A, 0x19D5, 0x1A22, 0x1A6F, 0x1ABE, 0x1B0D,
    0x1B5D, 0x1BAE, 0x1C00, 0x1C53, 0x1CA7, 0x1CFC, 0x1D52, 0x1DA9, 0x1E01, 0x1E5A,
    0x1EB4, 0x1F0F, 0x1F6B, 0x1FC8, 0x2026, 0x2086, 0x20E6, 0x2148, 0x21AA, 0x220E,
    0x2273, 0x22D9, 0x2341, 0x23A9, 0x2413, 0x247E, 0x24EA, 0x2557, 0x25C6, 0x2636,
    0x26A7, 0x271A, 0x278E, 0x2803, 0x287A, 0x28F2, 0x296B, 0x29E6, 0x2A62, 0x2AE0,
    0x2B5F, 0x2BDF, 0x2C61, 0x2CE5, 0x2D6A, 0x2DF1, 0x2E79, 0x2F03, 0x2F8E, 0x301B,
    0x30AA, 0x313A, 0x31CC, 0x325F, 0x32F5, 0x338C, 0x3425, 0x34BF, 0x355B, 0x35FA,
    0x369A, 0x373C, 0x37DF, 0x3885, 0x392C, 0x39D6, 0x3A81, 0x3B2F, 0x3BDE, 0x3C90,
    0x3D43, 0x3DF9, 0x3EB1, 0x3F6A, 0x4026, 0x40E5, 0x41A5, 0x4268, 0x432C, 0x43F4,
    0x44BD, 0x4589, 0x4657, 0x4727, 0x47FA, 0x48D0, 0x49A8, 0x4A82, 0x4B5F, 0x4C3E,
    0x4D20, 0x4E05, 0x4EEC, 0x4FD6, 0x50C3, 0x51B2, 0x52A4, 0x5399, 0x5491, 0x558C,
    0x5689, 0x578A, 0x588D, 0x5994, 0x5A9D, 0x5BAA, 0x5CBA, 0x5DCD, 0x5EE3, 0x5FFC,
    0x6119, 0x6238, 0x635C, 0x6482, 0x65AC, 0x66D9, 0x680A, 0x693F, 0x6A77, 0x6BB2,
    0x6CF2, 0x6E35, 0x6F7B, 0x70C6, 0x7214, 0x7366, 0x74BC, 0x7616, 0x7774, 0x78D6,
    0x7A3D, 0x7BA7, 0x7D16, 0x7E88, 0x7FFF, 0x817B, 0x82FB, 0x847F, 0x8608, 0x8795,
    0x8927, 0x8ABE, 0x8C59, 0x8DF9, 0x8F9E, 0x9148, 0x92F6, 0x94AA, 0x9663, 0x9820,
    0x99E3, 0x9BAB, 0x9D79, 0x9F4C, 0xA124, 0xA302, 0xA4E5, 0xA6CE, 0xA8BC, 0xAAB0,
    0xACAA, 0xAEAA, 0xB0B0, 0xB2BC, 0xB4CE, 0xB6E5, 0xB904, 0xBB28, 0xBD53, 0xBF84,
    0xC1BC, 0xC3FA, 0xC63F, 0xC88B, 0xCADD, 0xCD37, 0xCF97, 0xD1FE, 0xD46D, 0xD6E3,
    0xD960, 0xDBE4, 0xDE70, 0xE103, 0xE39E, 0xE641, 0xE8EB, 0xEB9E, 0xEE58, 0xF11B,
    0xF3E6, 0xF6B9, 0xF994, 0xFC78, 0xFF64,
};

void fn_80025D5C(struct MIXChannel *channel);

static inline u32 __MIXGetVolume(s32 attenuation) {
    u32 volume;
    if (attenuation <= -904) {
        volume = 0;
    } else if (attenuation >= 60) {
        volume = 0xFF64;
    } else {
        volume = __MIXVolumeTable[attenuation + 904];
    }
    return volume;
}



typedef struct {
    u8 pad0[0x14];
    u32 x;
    u32 y;
    u32 pad1c;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2c;
    u32 unk30;
    u32 unk34;
    u8 pad1[0x950];
    s16 half[128];
    s16 extra[128];
} Fn80025D5CObject;

typedef struct {
    u8 pad0[0x78c];
    u32 words[128];
    s16 half[128];
    s16 extra[128];
} Fn80025D5CTable;

typedef struct SoundChan {
    u8 pad_00[0x1C];
    u32 unk_1C;
    u8 pad_20[0x124];
    u16 unk_144;
    u8 pad_146[4];
    u16 unk_14A[18];
    u8 pad_16E[0x2E];
    u16 unk_19C;
    s16 unk_19E;
} SoundChan;

typedef struct SoundEntry {
    SoundChan *chan;
    u32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u8 pad_14[8];
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    u16 unk_38;
    u16 unk_3A;
    u16 unk_3C;
    u16 unk_3E;
    u16 unk_40;
    u16 unk_42;
    u16 unk_44;
    u16 unk_46;
    u16 unk_48;
    u16 unk_4A;
    u16 unk_4C;
    u16 unk_4E;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
    u16 unk_56;
    u16 unk_58;
    u16 unk_5A;
    u16 unk_5C;
    u16 unk_5E;
} SoundEntry;



void fn_80025D5C(struct MIXChannel *channel) {
    Fn80025D5CObject *obj = (Fn80025D5CObject *)channel;
    Fn80025D5CTable *table = (Fn80025D5CTable *)lbl_80128990;
    u32 x = obj->x;
    u32 y = obj->y;
    u32 dx = 0x7f - x;
    u32 dy = 0x7f - y;

    if (lbl_801A6B88 == 3) {
        obj->unk20 = table->half[x];
        obj->unk24 = table->half[dx];
        obj->unk28 = table->half[dy];
        obj->unk2c = table->half[y];
        obj->unk30 = table->extra[dx];
        obj->unk34 = table->extra[x];
    } else {
        obj->unk20 = table->words[x];
        obj->unk24 = table->words[dx];
        obj->unk28 = table->words[dy];
        obj->unk2c = table->words[y];
    }
}

typedef struct {
    s16 v;
    s16 pad;
} Fn80025E18Pair;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    s32 unkC;
    s32 unk10;
    u32 x;
    u32 y;
    u32 unk1C;
    u32 unk20[6];
    Fn80025E18Pair pairs[10];
} Fn80025E18Entry;



void fn_80025E18(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        lbl_80176160[i].mode = 0x50000000;
        lbl_80176160[i].input = 0;
        lbl_80176160[i].aux_a = -0x3c0;
        lbl_80176160[i].aux_b = -0x3c0;
        lbl_80176160[i].fader = 0;
        lbl_80176160[i].pan = 0x40;
        lbl_80176160[i].surround_pan = 0x7f;
        lbl_80176160[i].vBS = 0;
        lbl_80176160[i].vBR = 0;
        lbl_80176160[i].vBL = 0;
        lbl_80176160[i].vAS = 0;
        lbl_80176160[i].vAR = 0;
        lbl_80176160[i].vAL = 0;
        lbl_80176160[i].vS = 0;
        lbl_80176160[i].vR = 0;
        lbl_80176160[i].vL = 0;
        lbl_80176160[i].v = 0;
        fn_80025D5C(&lbl_80176160[i]);
    }
    lbl_801A6B80 = 0;
    lbl_801A6B84 = 0;
    lbl_801A6B88 = 1;
}

void fn_80025EE0(void) {
}

void fn_80025EE4(u32 arg0) {
    lbl_801A6B88 = arg0;
}

u32 fn_80025EEC(void) {
    return lbl_801A6B88;
}

void fn_80025EF4(AXVPB *voice, u32 mode, int input, int aux_a, int aux_b, int pan, int surround_pan,
                 int fader) {
    struct MIXChannel *channel;
    BOOL enabled;
    u16 mixer_control;
    u16 *mix;
    channel = &lbl_80176160[voice->index];
    channel->voice = voice;
    channel->mode = mode & 7;
    channel->input = input;
    channel->aux_a = aux_a;
    channel->aux_b = aux_b;
    channel->pan = pan;
    channel->surround_pan = surround_pan;
    channel->fader = fader;
    fn_80025D5C(channel);
    if (channel->mode & 4) {
        channel->v = 0;
    } else {
        channel->v = __MIXGetVolume(input);
    }
    mixer_control = 0;
    switch (lbl_801A6B88) {
    case 0:
        channel->vL = __MIXGetVolume(channel->fader + channel->volumes[2]);
        channel->vR = __MIXGetVolume(channel->fader + channel->volumes[2]);
        channel->vS = __MIXGetVolume(channel->fader + channel->volumes[3] - 30);
        if (channel->mode & 1) {
            channel->vAL = __MIXGetVolume(channel->aux_a + channel->volumes[2]);
            channel->vAR = __MIXGetVolume(channel->aux_a + channel->volumes[2]);
            channel->vAS = __MIXGetVolume(channel->aux_a + channel->volumes[3] - 30);
        } else {
            channel->vAL = __MIXGetVolume(channel->fader + channel->aux_a + channel->volumes[2]);
            channel->vAR = __MIXGetVolume(channel->fader + channel->aux_a + channel->volumes[2]);
            channel->vAS =
                __MIXGetVolume(channel->fader + channel->aux_a + channel->volumes[3] - 30);
        }
        if (channel->mode & 2) {
            channel->vBL = __MIXGetVolume(channel->aux_b + channel->volumes[2]);
            channel->vBR = __MIXGetVolume(channel->aux_b + channel->volumes[2]);
            channel->vBS = __MIXGetVolume(channel->aux_b + channel->volumes[3] - 30);
        } else {
            channel->vBL = __MIXGetVolume(channel->fader + channel->aux_b + channel->volumes[2]);
            channel->vBR = __MIXGetVolume(channel->fader + channel->aux_b + channel->volumes[2]);
            channel->vBS =
                __MIXGetVolume(channel->fader + channel->aux_b + channel->volumes[3] - 30);
        }
        break;
    case 1:
    case 2:
        channel->vL = __MIXGetVolume(channel->fader + channel->volumes[0] + channel->volumes[2]);
        channel->vR = __MIXGetVolume(channel->fader + channel->volumes[1] + channel->volumes[2]);
        channel->vS = __MIXGetVolume(channel->fader + channel->volumes[3] - 30);
        if (channel->mode & 1) {
            channel->vAL =
                __MIXGetVolume(channel->aux_a + channel->volumes[0] + channel->volumes[2]);
            channel->vAR =
                __MIXGetVolume(channel->aux_a + channel->volumes[1] + channel->volumes[2]);
            channel->vAS = __MIXGetVolume(channel->aux_a + channel->volumes[3] - 30);
        } else {
            channel->vAL = __MIXGetVolume(channel->fader + channel->aux_a + channel->volumes[0] +
                                          channel->volumes[2]);
            channel->vAR = __MIXGetVolume(channel->fader + channel->aux_a + channel->volumes[1] +
                                          channel->volumes[2]);
            channel->vAS =
                __MIXGetVolume(channel->fader + channel->aux_a + channel->volumes[3] - 30);
        }
        if (channel->mode & 2) {
            channel->vBL =
                __MIXGetVolume(channel->aux_b + channel->volumes[0] + channel->volumes[2]);
            channel->vBR =
                __MIXGetVolume(channel->aux_b + channel->volumes[1] + channel->volumes[2]);
            channel->vBS = __MIXGetVolume(channel->aux_b + channel->volumes[3] - 30);
        } else {
            channel->vBL = __MIXGetVolume(channel->fader + channel->aux_b + channel->volumes[0] +
                                          channel->volumes[2]);
            channel->vBR = __MIXGetVolume(channel->fader + channel->aux_b + channel->volumes[1] +
                                          channel->volumes[2]);
            channel->vBS =
                __MIXGetVolume(channel->fader + channel->aux_b + channel->volumes[3] - 30);
        }
        break;
    case 3:
        channel->vL = __MIXGetVolume(channel->fader + channel->volumes[0] + channel->volumes[2]);
        channel->vR = __MIXGetVolume(channel->fader + channel->volumes[1] + channel->volumes[2]);
        channel->vBL = __MIXGetVolume(channel->fader + channel->volumes[4] + channel->volumes[3]);
        channel->vBR = __MIXGetVolume(channel->fader + channel->volumes[5] + channel->volumes[3]);
        if (channel->mode & 1) {
            channel->vAL =
                __MIXGetVolume(channel->aux_a + channel->volumes[0] + channel->volumes[2]);
            channel->vAR =
                __MIXGetVolume(channel->aux_a + channel->volumes[1] + channel->volumes[2]);
            channel->vAS =
                __MIXGetVolume(channel->aux_a + channel->volumes[4] + channel->volumes[3]);
            channel->vBS =
                __MIXGetVolume(channel->aux_a + channel->volumes[5] + channel->volumes[3]);
        } else {
            channel->vAL = __MIXGetVolume(channel->fader + channel->aux_a + channel->volumes[0] +
                                          channel->volumes[2]);
            channel->vAR = __MIXGetVolume(channel->fader + channel->aux_a + channel->volumes[1] +
                                          channel->volumes[2]);
            channel->vAS = __MIXGetVolume(channel->fader + channel->aux_a + channel->volumes[4] +
                                          channel->volumes[3]);
            channel->vBS = __MIXGetVolume(channel->fader + channel->aux_a + channel->volumes[5] +
                                          channel->volumes[3]);
        }
        mixer_control |= 0x4000;
        break;
    }
    enabled = OSDisableInterrupts();
    voice->pb.ve.currentVolume = channel->v;
    voice->pb.ve.currentDelta = 0;
    mix = (u16 *)&voice->pb.mix;
    if ((*mix++ = channel->vL) != 0)
        mixer_control |= 1;
    *mix++ = 0;
    if ((*mix++ = channel->vR) != 0)
        mixer_control |= 2;
    *mix++ = 0;
    if ((*mix++ = channel->vAL) != 0)
        mixer_control |= 0x10;
    *mix++ = 0;
    if ((*mix++ = channel->vAR) != 0)
        mixer_control |= 0x20;
    *mix++ = 0;
    if ((*mix++ = channel->vBL) != 0)
        mixer_control |= 0x200;
    *mix++ = 0;
    if ((*mix++ = channel->vBR) != 0)
        mixer_control |= 0x400;
    *mix++ = 0;
    if ((*mix++ = channel->vBS) != 0)
        mixer_control |= 0x1000;
    *mix++ = 0;
    if ((*mix++ = channel->vS) != 0)
        mixer_control |= 4;
    *mix++ = 0;
    if ((*mix++ = channel->vAS) != 0)
        mixer_control |= 0x80;
    *mix++ = 0;
    voice->pb.mixerCtrl = mixer_control;
    voice->sync |= (1UL << 1) | (1UL << 4) | (1UL << 9);
    OSRestoreInterrupts(enabled);
}

struct fn_80026D70_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

struct fn_80026D90_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

struct fn_80026DB8_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

u32 fn_80026D70(struct fn_80026D70_Arg0 *arg0) {
    u32 v0;
    v0 = (u32)((u8 *)&lbl_80176160 + (arg0->unk_18 * 96));
    *(u32 *)((u8 *)v0 + 0) = 0;
    return v0;
}

u32 fn_80026D90(struct fn_80026D90_Arg0 *arg0, u32 arg1) {
    u32 v0;
    v0 = (u32)((u8 *)&lbl_80176160 + (arg0->unk_18 * 96));
    *(u32 *)((u8 *)v0 + 8) = arg1;
    *(u32 *)((u8 *)v0 + 4) = (*(u32 *)((u8 *)v0 + 4) | 0x10000000);
    return v0;
}

u32 fn_80026DB8(struct fn_80026DB8_Arg0 *arg0) {
    return *(u32 *)((u8 *)&lbl_80176160 + (arg0->unk_18 * 96) + 8);
}

struct fn_80026DD4_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

u32 fn_80026DD4(struct fn_80026DD4_Arg0 *arg0) {
    u32 v0;
    v0 = (u32)((u8 *)&lbl_80176160 + (arg0->unk_18 * 96));
    *(u32 *)((u8 *)v0 + 4) = (lbl_80176160[arg0->unk_18].mode & ~0x1);
    *(u32 *)((u8 *)v0 + 4) = (*(u32 *)((u8 *)v0 + 4) | 0x40000000);
    return v0;
}

struct fn_80026E04_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

u32 fn_80026E04(struct fn_80026E04_Arg0 *arg0) {
    u32 v0;
    v0 = (u32)((u8 *)&lbl_80176160 + (arg0->unk_18 * 96));
    *(u32 *)((u8 *)v0 + 4) = ((lbl_80176160[arg0->unk_18].mode | 0x40000000) | 1);
    return v0;
}

struct fn_80026E2C_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

u32 fn_80026E2C(struct fn_80026E2C_Arg0 *arg0, u32 arg1) {
    u32 v0;
    v0 = (u32)((u8 *)&lbl_80176160 + (arg0->unk_18 * 96));
    *(u32 *)((u8 *)v0 + 12) = arg1;
    *(u32 *)((u8 *)v0 + 4) = (*(u32 *)((u8 *)v0 + 4) | 0x40000000);
    return v0;
}

void fn_80026E54(AXVPB *p) {
    struct MIXChannel *c = &lbl_80176160[p->index];
    *(volatile u32 *)&c->mode &= 0xFFFFFFFD; /* fzgx-allow: S2 two-step flag update */
    *(volatile u32 *)&c->mode |= 0x40000000; /* fzgx-allow: S2 two-step flag update */
}

struct fn_80026E84_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

u32 fn_80026E84(struct fn_80026E84_Arg0 *arg0) {
    u32 v0;
    v0 = (u32)((u8 *)&lbl_80176160 + (arg0->unk_18 * 96));
    *(u32 *)((u8 *)v0 + 4) = ((lbl_80176160[arg0->unk_18].mode | 0x40000000) | 2);
    return v0;
}

struct fn_80026EAC_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

u32 fn_80026EAC(struct fn_80026EAC_Arg0 *arg0, u32 arg1) {
    u32 v0;
    if (lbl_801A6B88 == 3) { return (u32)arg0; }
    v0 = (u32)((u8 *)&lbl_80176160 + (arg0->unk_18 * 96));
    *(u32 *)((u8 *)v0 + 16) = arg1;
    *(u32 *)((u8 *)v0 + 4) = (*(u32 *)((u8 *)v0 + 4) | 0x40000000);
    return v0;
}

struct fn_80026EE0_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

struct fn_80026F4C_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

struct fn_80026FB8_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

void fn_80026EE0(struct fn_80026EE0_Arg0 *arg0, s32 arg1) {
    u32 v0;
    v0 = (u32)((u8 *)&lbl_80176160 + (arg0->unk_18 * 96));
    if (arg1 < 0) {
        arg1 = 0;
    } else if (arg1 > 127) {
        arg1 = 127;
    }
    *(u32 *)((u8 *)v0 + 20) = arg1;
    fn_80025D5C((struct MIXChannel *)v0);
    *(u32 *)((u8 *)v0 + 4) = (*(u32 *)((u8 *)v0 + 4) | 0x40000000);
}

void fn_80026F4C(struct fn_80026F4C_Arg0 *arg0, s32 arg1) {
    u32 v0;

    v0 = (u32)((u8 *)&lbl_80176160 + (arg0->unk_18 * 96));
    if (arg1 < 0) {
        arg1 = 0;
    } else if (arg1 > 0x7f) {
        arg1 = 0x7f;
    }
    *(s32 *)((u8 *)v0 + 24) = arg1;
    fn_80025D5C((struct MIXChannel *)v0);
    *(u32 *)((u8 *)v0 + 4) = (*(u32 *)((u8 *)v0 + 4) | 0x40000000);
}

u32 fn_80026FB8(struct fn_80026FB8_Arg0 *arg0, u32 arg1) {
    u32 v0;
    v0 = (u32)((u8 *)&lbl_80176160 + (arg0->unk_18 * 96));
    *(u32 *)((u8 *)v0 + 28) = arg1;
    *(u32 *)((u8 *)v0 + 4) = (*(u32 *)((u8 *)v0 + 4) | 0x40000000);
    return v0;
}

static inline s32 get_curve(u8 *base, s32 idx) {
    s32 r;
    if (idx <= -904) {
        r = 0;
    } else if (idx >= 60) {
        r = 0xFF64;
    } else {
        r = *(u16 *)(base + (idx << 1) + 0x710);
    }
    return r;
}

void fn_80026FE0(void) {
    SoundEntry *e;
    s32 f6;
    SoundChan *c;
    s32 f7;
    u32 flags;
    u8 *base;
    u16 *p;
    s32 d;
    s32 i;

    base = (u8 *)lbl_80128990;
    for (i = 0; i < 64; i++) {
        e = &((SoundEntry *)lbl_80176160)[i];
        c = e->chan;
        f7 = 0;
        f6 = 0;
        if (c == NULL) {
            continue;
        }
        flags = 0;
        if (e->unk_04 & 0x20000000) {
            e->unk_38 = e->unk_3A;
            f7 = 1;
            e->unk_04 &= ~0x20000000;
        }
        if (e->unk_04 & 0x10000000) {
            if (e->unk_04 & 0x4) {
                e->unk_3A = 0;
            } else {
                e->unk_3A = get_curve(base, e->unk_08);
            }
            e->unk_04 &= ~0x10000000;
            e->unk_04 |= 0x20000000;
            f7 = 1;
        }
        if (e->unk_04 & 0x80000000) {
            e->unk_3C = e->unk_3E;
            e->unk_40 = e->unk_42;
            e->unk_44 = e->unk_46;
            e->unk_48 = e->unk_4A;
            e->unk_4C = e->unk_4E;
            e->unk_50 = e->unk_52;
            e->unk_54 = e->unk_56;
            e->unk_58 = e->unk_5A;
            e->unk_5C = e->unk_5E;
            e->unk_04 &= ~0x80000000;
            f6 = 1;
        }
        if (e->unk_04 & 0x40000000) {
            switch (lbl_801A6B88) {
            case 0:
                e->unk_3E = get_curve(base, e->unk_1C + e->unk_28);
                e->unk_42 = get_curve(base, e->unk_1C + e->unk_28);
                e->unk_46 = get_curve(base, ((((e->unk_1C) + e->unk_2C) + ((-30)))));
                if (e->unk_04 & 0x1) {
                    e->unk_4A = get_curve(base, e->unk_0C + e->unk_28);
                    e->unk_4E = get_curve(base, e->unk_0C + e->unk_28);
                    e->unk_52 = get_curve(base, ((((e->unk_0C) + e->unk_2C) + ((-30)))));
                } else {
                    e->unk_4A = get_curve(base, e->unk_1C + e->unk_0C + e->unk_28);
                    e->unk_4E = get_curve(base, e->unk_1C + e->unk_0C + e->unk_28);
                    e->unk_52 = get_curve(base, e->unk_1C + e->unk_0C + e->unk_2C - 30);
                }
                if (e->unk_04 & 0x2) {
                    e->unk_56 = get_curve(base, e->unk_10 + e->unk_28);
                    e->unk_5A = get_curve(base, e->unk_10 + e->unk_28);
                    e->unk_5E = get_curve(base, e->unk_10 + e->unk_2C - 30);
                } else {
                    e->unk_56 = get_curve(base, e->unk_1C + e->unk_10 + e->unk_28);
                    e->unk_5A = get_curve(base, e->unk_1C + e->unk_10 + e->unk_28);
                    e->unk_5E = get_curve(base, e->unk_1C + e->unk_10 + e->unk_2C - 30);
                }
                break;
            case 1:
            case 2:
                e->unk_3E = get_curve(base, e->unk_1C + e->unk_20 + e->unk_28);
                e->unk_42 = get_curve(base, e->unk_1C + e->unk_24 + e->unk_28);
                e->unk_46 = get_curve(base, e->unk_1C + e->unk_2C - 30);
                if (e->unk_04 & 0x1) {
                    e->unk_4A = get_curve(base, e->unk_0C + e->unk_20 + e->unk_28);
                    e->unk_4E = get_curve(base, e->unk_0C + e->unk_24 + e->unk_28);
                    e->unk_52 = get_curve(base, e->unk_0C + e->unk_2C - 30);
                } else {
                    e->unk_4A = get_curve(base, e->unk_1C + e->unk_0C + e->unk_20 + e->unk_28);
                    e->unk_4E = get_curve(base, e->unk_1C + e->unk_0C + e->unk_24 + e->unk_28);
                    e->unk_52 = get_curve(base, e->unk_1C + e->unk_0C + e->unk_2C - 30);
                }
                if (e->unk_04 & 0x2) {
                    e->unk_56 = get_curve(base, e->unk_10 + e->unk_20 + e->unk_28);
                    e->unk_5A = get_curve(base, e->unk_10 + e->unk_24 + e->unk_28);
                    e->unk_5E = get_curve(base, e->unk_10 + e->unk_2C - 30);
                } else {
                    e->unk_56 = get_curve(base, e->unk_1C + e->unk_10 + e->unk_20 + e->unk_28);
                    e->unk_5A = get_curve(base, e->unk_1C + e->unk_10 + e->unk_24 + e->unk_28);
                    e->unk_5E = get_curve(base, e->unk_1C + e->unk_10 + e->unk_2C - 30);
                }
                break;
            case 3:
                e->unk_3E = get_curve(base, e->unk_1C + e->unk_20 + e->unk_28);
                e->unk_42 = get_curve(base, e->unk_1C + e->unk_24 + e->unk_28);
                e->unk_56 = get_curve(base, e->unk_1C + e->unk_30 + e->unk_2C);
                e->unk_5A = get_curve(base, e->unk_1C + e->unk_34 + e->unk_2C);
                if (e->unk_04 & 0x1) {
                    e->unk_4A = get_curve(base, e->unk_0C + e->unk_20 + e->unk_28);
                    e->unk_4E = get_curve(base, e->unk_0C + e->unk_24 + e->unk_28);
                    e->unk_52 = get_curve(base, e->unk_0C + e->unk_30 + e->unk_2C);
                    e->unk_5E = get_curve(base, e->unk_0C + e->unk_34 + e->unk_2C);
                } else {
                    e->unk_4A = get_curve(base, e->unk_1C + e->unk_0C + e->unk_20 + e->unk_28);
                    e->unk_4E = get_curve(base, e->unk_1C + e->unk_0C + e->unk_24 + e->unk_28);
                    e->unk_52 = get_curve(base, e->unk_1C + e->unk_0C + e->unk_30 + e->unk_2C);
                    e->unk_5E = get_curve(base, e->unk_1C + e->unk_0C + e->unk_34 + e->unk_2C);
                }
                flags |= 0x4000;
                break;
            }
            e->unk_04 &= ~0x40000000;
            e->unk_04 |= 0x80000000;
            f6 = 1;
        }
        if (f7 != 0) {
            c->unk_19C = e->unk_38;
            c->unk_19E = ((e->unk_3A - e->unk_38) / 160);
            c->unk_1C |= 0x200;
        }
        if (f6 != 0) {
            u16 v;

            p = c->unk_14A;
            v = e->unk_3C;
            *p++ = v;
            if (v != 0) {
                flags |= 0x1;
            }
            d = (e->unk_3E - e->unk_3C) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x8;
            }
            v = e->unk_40;
            *p++ = v;
            if (v != 0) {
                flags |= 0x2;
            }
            d = (e->unk_42 - e->unk_40) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x8;
            }
            v = e->unk_48;
            *p++ = v;
            if (v != 0) {
                flags |= 0x10;
            }
            d = (e->unk_4A - e->unk_48) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x40;
            }
            v = e->unk_4C;
            *p++ = v;
            if (v != 0) {
                flags |= 0x20;
            }
            d = (e->unk_4E - e->unk_4C) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x40;
            }
            v = e->unk_54;
            *p++ = v;
            if (v != 0) {
                flags |= 0x200;
            }
            d = (e->unk_56 - e->unk_54) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x800;
            }
            v = e->unk_58;
            *p++ = v;
            if (v != 0) {
                flags |= 0x400;
            }
            d = (e->unk_5A - e->unk_58) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x800;
            }
            v = e->unk_5C;
            *p++ = v;
            if (v != 0) {
                flags |= 0x1000;
            }
            d = (e->unk_5E - e->unk_5C) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x2000;
            }
            v = e->unk_44;
            *p++ = v;
            if (v != 0) {
                flags |= 0x4;
            }
            d = (e->unk_46 - e->unk_44) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x8;
            }
            v = e->unk_50;
            *p++ = v;
            if (v != 0) {
                flags |= 0x80;
            }
            d = (e->unk_52 - e->unk_50) / 160;
            *p++ = d;
            if ((u16)d != 0) {
                flags |= 0x100;
            }
            c->unk_144 = flags;
            c->unk_1C |= 0x12;
        }
    }
    if (lbl_801A6B84 > lbl_801A6B80) {
        lbl_801A6B80++;
        AISetStreamVolLeft(base[0xB8C + lbl_801A6B80]);
        AISetStreamVolRight(base[0xB8C + lbl_801A6B80]);
    } else if (lbl_801A6B84 < lbl_801A6B80) {
        lbl_801A6B80--;
        AISetStreamVolLeft(base[0xB8C + lbl_801A6B80]);
        AISetStreamVolRight(base[0xB8C + lbl_801A6B80]);
    }
}
