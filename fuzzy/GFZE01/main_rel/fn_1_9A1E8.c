/* Non-matching: best partial attempt (68.84% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/burner.h"
typedef struct { u32 x,y,z; } Triple;
typedef struct { u32 a,b,c,d; } Quad;
#pragma pack(push,1)
typedef struct {
 s16 id; u32 type; u8 flags[4]; u8 padA[2];
 u32 counters[4]; f32 values[4]; u8 pad2C[0x10];
 u32 save3C,save40,random; u8 pad48[0x28];
 u8 save70; u8 pad71[7];
 u32 save78,save7C,save80;
 s32 flag84; u32 value88; Quad config; f32 value9C; u16 mask; u8 padA2[2];
} State;
#pragma pack(pop)
typedef struct Entry {u32 a; void (*call)(struct Entry*); u8 pad[0x1C];} Entry;
extern const f32 lbl_1_rodata_41FC;
extern Triple lbl_1_rodata_41F0;
extern Triple lbl_1_bss_6EA10[4];
extern u32 lbl_1_bss_6EA40[4];
extern u32 lbl_801A63C0, lbl_801A66A0;
extern u8 lbl_1_bss_9C;
extern void fn_80008BEC(void*,int,u32);
extern void fn_1_9D9E4(void),fn_1_102FD0(void),fn_1_9AD20(void);
extern s16 fn_1_7B054(void);
extern s32 fn_1_58C4(void);
static inline u32 random15(void) {
 lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
 return (lbl_801A63C0 >> 16) & 0x7FFF;
}

void fn_1_9A1E8(void) {
 u8 *base = (u8*)&lbl_1_data_2A0C0;
 u32 id;
 u8 *p;
 u32 a,b,c,d,e;
 u8 f;
 u32 old;
 u32 next;
 u32 seed;
 s16 mode;
 Quad *q;
 s32 game;
 p = base+0x720;
 id = *(s16*)(base+0x720);
 a=*(u32*)(p+0x3C); b=*(u32*)(p+0x40); c=*(u32*)(p+0x78); d=*(u32*)(p+0x7C); e=*(u32*)(p+0x80); f=*(u8*)(p+0x70);
 fn_80008BEC(p,0,0xA4);
 old = random15();
 { Triple t = lbl_1_rodata_41F0;
 Triple u = t;
 lbl_801A63C0 = b ^ 0xCAE87FB5;
 next = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
 *(s16*)(base+0x720) = id;
 *(u32*)(p+0x3C) = a;
 *(u32*)(p+0x40) = b; *(u32*)(p+0x78)=c; *(u32*)(p+0x7C)=d; *(u32*)(p+0x80)=e; *(u8*)(p+0x70)=f;
 *(u8*)(p+6)=0; *(u32*)(p+12)=0; *(f32*)(p+28)=lbl_1_rodata_41FC;
 *(u8*)(p+7)=0; *(u32*)(p+16)=0; *(f32*)(p+32)=lbl_1_rodata_41FC;
 *(u8*)(p+8)=0; *(u32*)(p+20)=0; *(f32*)(p+36)=lbl_1_rodata_41FC;
 *(u8*)(p+9)=0; *(u32*)(p+24)=0; *(f32*)(p+40)=lbl_1_rodata_41FC;
 *(u32*)(p+2) = ((u32*)(base+0x7C4))[(s16)id>0?(s16)id:0];
 {
 lbl_1_bss_6EA10[0] = t;
 lbl_1_bss_6EA40[0] = 0;
 lbl_1_bss_6EA10[1] = u;
 lbl_1_bss_6EA40[1] = 0;
 lbl_1_bss_6EA10[2] = u;
 lbl_1_bss_6EA40[2] = 0;
 lbl_1_bss_6EA10[3] = u;
 lbl_1_bss_6EA40[3] = 0;
 }
 lbl_801A63C0 = next;
 *(u32*)(p+0x44) = (next >> 16) & 0x7FFF;
 }
 fn_1_9D9E4(); fn_1_102FD0();
 if(*(s16*)(base+0x720)>0) {
 Entry *entry = (Entry*)(base+0xAEC)+*(s16*)(base+0x720);
 entry->call(entry);
 } else fn_1_9AD20();
 *(u32*)(p+0x40) = lbl_801A66A0 + random15();
 lbl_801A63C0 = old ^ 0xCAE87FB5;
 mode = fn_1_7B054();
 ((State*)(base+0x720))->value88 = ((State*)(base+0x720))->flag84 ? 4 : fn_1_58C4();
 q = (Quad*)(base+0x2840);
 if((u32)mode < 37) q = (Quad*)((u8*)(base+0x2850)+(mode*16));
 ((State*)(base+0x720))->config = *q;
 ((State*)(base+0x720))->value9C = lbl_1_rodata_41FC;
 game = (s16)lbl_1_bss_960;
 if(game == 9 && lbl_1_bss_84.unk_14) {
 ((State*)(base+0x720))->value9C = *(f32*)lbl_1_bss_84.unk_14;
 lbl_1_bss_84.unk_14=0;
 }
 ((State*)(base+0x720))->mask = 0xF00;
 if(game == 9) {
 switch(((s8*)&lbl_1_bss_9C)[1]) {
 case 0:((State*)(base+0x720))->mask=0x100;break;
 case 1:((State*)(base+0x720))->mask=0x200;break;
 case 2:((State*)(base+0x720))->mask=0x400;break;
 }
 }
}
