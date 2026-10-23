#include "font.h"

extern void fn_16_2528(void);
struct fn_16_4490_Copy88 { u32 a[22]; };
struct fn_16_4490_lbl_1_bss_8B614 {
    u8 pad_0[0x30];
    s16 unk_30;
};
extern struct fn_16_4490_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern u32 lbl_16_data_830C0[][4];
extern u8 lbl_16_data_83440[];
extern u32 lbl_1_rodata_26F8;

const u32 fzgx_pool_pool_0[8] = {0xFFFF0000,0x41A00000,0x41200000,0x3F19999A,0x43E40000,0x3E000000,0x40A00000,0x3FB8E38E};
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_20(void) { return 1.0f; }
const u32 fzgx_pool_pool_24[9] = {0x42380000,0x42500000,0x3F000000,0x428E0000,0x41B00000,0x42C40000,0x42BAC6C7,0x3F44C4C5,0x00000000};
f64 fzgx_pool_48(void) { return 4503601774854144.0; }
const u32 fzgx_pool_pool_50[41] = {0xFFFF0000,0x00000000,0x42000000,0x41E00000,0x428A0000,0x43A90000,0x43FC0000,0x41C00000,0x41000000,0x3F471C72,0x429E0000,0x43AB8000,0x431B0000,0x43B68000,0xFFFF0000,0x42300000,0x43780000,0x40C00000,0xFFFF0000,0x43F00000,0x430E0000,0x436C0000,0x42CC0000,0x42D60000,0x3F200000,0x430D0000,0x40E00000,0x43360B61,0x43340000,0x43060000,0x3DCCCCCD,0x3F40C0C1,0x3E99999A,0x43B40000,0x43300000,0x00000000,0xFFFF0000,0x41980000,0x41880000,0x42960000,0x42B80000};
const u32 fzgx_pool_pool_f4[1] = {0x00FFFF00};
const u32 fzgx_pool_pool_f8[1] = {0x00FFFF00};
const u32 fzgx_pool_pool_fc[1] = {0x00FFFF00};
const u32 fzgx_pool_pool_100[1] = {0x00FFFF00};
const u32 fzgx_pool_pool_104[1] = {0x00FFFF00};
const u32 fzgx_pool_pool_108[1] = {0x00FFFF00};
const u32 fzgx_pool_pool_10c[1] = {0x00FFFF00};
f32 fzgx_pool_110(void) { return 0.75f; }
f32 fzgx_pool_114(void) { return 37.0f; }
f32 fzgx_pool_118(void) { return 74.0f; }
f32 fzgx_pool_11c(void) { return 26.0f; }
f32 fzgx_pool_120(void) { return 63.0f; }
f32 fzgx_pool_124(void) { return 70.0f; }
#pragma section code_type ".text"

extern char *lbl_1_data_212A8[];
extern int fn_1_4F734(FontDrawPacket *);
extern s16 fn_1_12C930(s16);
extern void fn_1_51564(u16,u16,u16,u16,u16,u16);
extern void fn_1_5158C(FontDrawPacket *,u32,s16,s16);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32,f32);
extern void fn_1_4954C(f32);
extern void fn_1_4962C(void);
extern void fn_1_495A0(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_49738(void *);
extern u32 strlen(const char *);
extern f32 fn_1_4B040(const char *);
extern void fn_1_4955C(f32,f32);
extern void fn_1_4AE0C(const char *,...);

#define PF(n) (*(f32 *)&packet.a[(n)/4])
#define PW(n) (packet.a[(n)/4])
#define RF(n) (*(f32 *)(p_pool+(n)))
#define RW(n) (*(u32 *)(p_pool+(n)))

static inline f32 fn_16_4490_float(s16 value) { return value; }

static inline s32 fn_16_4490_number(s16 arg) {
    return arg==30 ? 0 : (arg>30 ? arg : arg+1);
}

static inline void fn_16_4490_digits(FontDrawPacket *packet, u32 code, s32 number, int tens) {
    s16 digit = tens ? number/10 : number%10;
    fn_1_5158C(packet, code, (s16)(digit%10), (s16)(digit/10));
}

void fn_16_4490(s16 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    u8 *p_pool;
    s32 number;
    s16 digit;
    s16 i;
    f32 y;
    f32 ratio;
    u32 color;
    char buffer[64];
    struct fn_16_4490_Copy88 packet;
    p_pool = (u8 *)&fzgx_pool_pool_0;
    packet = *(struct fn_16_4490_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=0x8919;
    PF(4)=(s16)arg1; PF(8)=(s16)arg2; PF(12)=(s16)arg3;
    PF(0x2c)=arg4; PW(0x30)=0x0400000f; (*(void (**)(void))&PW(0x50))=fn_16_2528;
    PW(0x38)=fzgx_pool_pool_f4[0]; PF(0x10)*=arg5; PF(0x14)*=arg5;
    fn_1_4F734((FontDrawPacket *)&packet);
    packet = *(struct fn_16_4490_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=0x8919;
    PF(4)=(s16)arg1; PF(8)=(s16)arg2; PF(12)=(s16)arg3;
    PF(0x2c)=arg4; PW(0x30)=0x0408000d; (*(void (**)(void))&PW(0x50))=fn_16_2528;
    PW(0x38)=fzgx_pool_pool_f8[0]; PF(0x10)*=arg5; PF(0x14)*=arg5;
    fn_1_4F734((FontDrawPacket *)&packet);
    packet = *(struct fn_16_4490_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=0x8919;
    PF(4)=(s16)arg1; PF(8)=(s16)arg2; PF(12)=(s16)arg3;
    PF(0x2c)=arg4; PW(0x30)=0x04100007; (*(void (**)(void))&PW(0x50))=fn_16_2528;
    PW(0x38)=fzgx_pool_pool_fc[0]; PF(0x10)*=arg5; PF(0x14)*=arg5;
    fn_1_4F734((FontDrawPacket *)&packet);
    packet = *(struct fn_16_4490_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=0x8919;
    PF(4)=(s16)arg1; PF(8)=(s16)arg2; PF(12)=(s16)arg3;
    PF(0x2c)=arg4; PW(0x30)=0x04180005; (*(void (**)(void))&PW(0x50))=fn_16_2528;
    PW(0x38)=fzgx_pool_pool_100[0]; PF(0x10)*=arg5; PF(0x14)*=arg5;
    fn_1_4F734((FontDrawPacket *)&packet);
    packet = *(struct fn_16_4490_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=lbl_16_data_830C0[fn_1_12C930(arg0)][lbl_1_bss_8B614.unk_30];
    PF(4)=(s16)arg1; PF(8)=(s16)arg2; PF(12)=(s16)arg3-1;
    PF(0x2c)=arg4; PW(0x30)=0x0400000a; (*(void (**)(void))&PW(0x50))=fn_16_2528;
    PF(0x10)*=0.75f; PF(0x14)*=0.75f;
    PF(0x10)*=arg6; PF(0x14)*=arg6;
    fn_1_4F734((FontDrawPacket *)&packet);
    number=fn_16_4490_number(arg0);
    packet = *(struct fn_16_4490_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=0x891a;
    PF(4)=fn_16_4490_float(arg1)-(f32)(37.0f*arg5);
    y=fn_16_4490_float(arg2)-(f32)(74.0f*arg5);
    PF(8)=y; PF(12)=fn_16_4490_float(arg3);
    PF(0x2c)=arg4; PW(0x30)=0x04000005; (*(void (**)(void))&PW(0x50))=fn_16_2528;
    PW(0x38)=fzgx_pool_pool_104[0]; PF(0x10)*=arg5; PF(0x14)*=arg5;
    fn_1_51564(0,0,12,16,10,1);
    fn_16_4490_digits((FontDrawPacket *)&packet,PW(0),number,1);
    fn_1_4F734((FontDrawPacket *)&packet);
    number=fn_16_4490_number(arg0);
    packet = *(struct fn_16_4490_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=0x891a;
    PF(4)=(s16)arg1-(f32)(26.0f*arg5); PF(8)=y; PF(12)=(s16)arg3;
    PF(0x2c)=arg4; PW(0x30)=0x04000005; (*(void (**)(void))&PW(0x50))=fn_16_2528;
    PW(0x38)=fzgx_pool_pool_108[0]; PF(0x10)*=arg5; PF(0x14)*=arg5;
    fn_1_51564(0,0,12,16,10,1);
    fn_16_4490_digits((FontDrawPacket *)&packet,PW(0),number,0);
    fn_1_4F734((FontDrawPacket *)&packet);
    {
        fn_1_49410(); fn_1_494DC(9); fn_1_495C8(1);
        fn_1_496FC((s16)arg1,(s16)arg2+(f32)(63.0f*arg5));
        fn_1_4954C((s16)arg3);
        fn_1_4962C(); fn_1_495A0(arg4);
        color=fzgx_pool_pool_10c[0]; fn_1_49514(&color); fn_1_49738(fn_16_2528);
        for(i=0;i<strlen(lbl_1_data_212A8[fn_1_12C930(arg0)]);i++) {
            if ((u8)lbl_1_data_212A8[fn_1_12C930(arg0)][i]=='&') buffer[i]='_';
            else if ((u8)lbl_1_data_212A8[fn_1_12C930(arg0)][i]==0x8145U) buffer[i]='^';
            else if ((u8)lbl_1_data_212A8[fn_1_12C930(arg0)][i]=='-') buffer[i]='\\';
            else if ((u8)lbl_1_data_212A8[fn_1_12C930(arg0)][i]=='.') buffer[i]='[';
            else buffer[i]=lbl_1_data_212A8[fn_1_12C930(arg0)][i];
        }
        buffer[i]=0;
        ratio=70.0f/fn_1_4B040(buffer);
        if (ratio<1.0f) ratio=70.0f/fn_1_4B040(buffer); else ratio=1.0f;
        fn_1_4955C(ratio,1.0f);
        fn_1_4AE0C((const char *)lbl_16_data_83440,buffer);
    }
}
