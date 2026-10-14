/* Non-matching: best partial attempt (79.28% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/custom_memcard.h"
#include "font.h"
extern void fn_1_13D02C(void); extern void fn_1_49410(void);
extern void fn_1_139F18(void *); extern void fn_1_139D60(void *);
extern void fn_1_13A460(void *); extern void fn_1_13A038(void *);
extern u32 fn_1_13A654(u32); extern void fn_1_13A21C(void *);
extern const f64 lbl_1_rodata_8600; extern const f32 lbl_1_rodata_8658;
extern void fn_1_496FC(f32, f32); extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_133DBC(void *); extern void fn_1_134AD4(void); extern void fn_1_134A4C(void);
extern u32 lbl_801A66B4; extern u32 fn_1_13F7F8(s16, s16); extern void fn_1_1380F0(void *);
extern u32 fn_1_13ABA8(u32); extern const f32 lbl_1_rodata_861C, lbl_1_rodata_863C, lbl_1_rodata_85F0;
extern void fn_1_134EE4(s32, s32, s32, f32);
extern void fn_1_135894(void *, void *, void *, void *, void *, void *, void *, f32, f32);
extern void fn_1_136174(u32, u32, void *, s16, void *, u32, u32, f32, f32);
extern void fn_1_1363F0(u32, u32, u32);
extern const f32 lbl_1_rodata_865C, lbl_1_rodata_8644, lbl_1_rodata_8660;
extern void fn_1_1368A0(s32, s16, s32, f32, f32, f32, f32, f32);
extern void fn_1_13750C(void *, void *, void *, void *);
extern const f32 lbl_1_rodata_864C, lbl_1_rodata_8650, lbl_1_rodata_8664;
extern void fn_1_13A848(s16, s16, void *, void *, int, f32, f32);
extern void fn_1_13A994(void *, void *, void *, void *, void *, void *, f32, f32);
extern f32 lbl_1_rodata_26F8[22]; extern const f32 lbl_1_rodata_8668, lbl_1_rodata_866C, lbl_1_rodata_8670, lbl_1_rodata_8674, lbl_1_rodata_8678, lbl_1_rodata_867C;
extern int fn_1_4F734(FontDrawPacket *); extern u16 fn_1_48690(u32), fn_1_486C4(u32);
extern const f64 lbl_1_rodata_8608; extern const f32 lbl_1_rodata_8680, lbl_1_rodata_8684, lbl_1_rodata_8688;
extern u32 lbl_1_rodata_8654; extern void fn_1_1332FC(s32,s32,u8);
extern u32 fn_1_133748(u32,u32); extern void fn_1_13354C(s32,s32,u32); extern void fn_1_133968(void); extern void fn_1_133A8C(void);
extern u32 fn_1_138A04(u32,u32,u32); extern void fn_1_137548(void*,void*,void*,void*); extern void fn_1_133BD8(void);
extern u8 fn_1_141F94(u32); extern u32 fn_1_138E44(u32,u32,u32); extern void fn_1_137584(void*,void*,void*,void*);
extern void fn_1_13923C(u32,u32); extern const f32 lbl_1_rodata_868C, lbl_1_rodata_8690;
extern u32 fn_1_13FB8C(u32,u32,u32,u32,u32,f32); extern void fn_1_14083C(u32,u32,u32,u32,u32,f32,f32);
typedef struct { u32 w[22]; } PacketStorage;
void fn_1_132774(void *arg0) {
    s16 i;
    s32 digit, count, v, idx;
    s16 ch;
    u8 *b;
    fn_1_13D02C(); fn_1_49410();
    b=(u8 *)&lbl_1_bss_8B3A0;
    if ((lbl_1_bss_8B3A0.unk_94 & 0x80000000)==0) {
        if (lbl_1_bss_8B3A0.unk_94 & 0x20000000) {
            *(u16 *)arg0=lbl_1_bss_8B3A0.unk_9E; fn_1_139F18(arg0); fn_1_139D60(arg0);
        } else if (lbl_1_bss_8B3A0.unk_94 & 0x00040000) {
            fn_1_13A460(arg0); fn_1_13A038(arg0);
        } else { fn_1_13A654((u32)arg0); fn_1_13A21C(arg0); }
    } else {
        for (i=0;i<4;i++) {
            if (((s16 *)(b+i*0x20))[7] != -1) {
                digit=0;
                while (digit<8 && !(b[i*0x20+0x14] & (1<<digit))) digit++;
                v=100+i*24;
                fn_1_496FC((f32)v,lbl_1_rodata_8658);
                fn_1_4AE0C((const char *)lbl_1_data_41930,i+1,digit);
            }
        }
    }
    fn_1_133DBC((void *)1); fn_1_134AD4(); fn_1_134A4C(); fn_1_13F7F8(2,(s16)lbl_801A66B4); fn_1_1380F0(0);
    if (lbl_1_bss_8B3A0.unk_94&4) {
        if ((s16)lbl_1_bss_960==2) fn_1_13ABA8(0x88000000);
        else if ((s16)lbl_1_bss_960==9) fn_1_13ABA8(0x08000000);
        else if (lbl_1_bss_8B3A0.unk_94&0x40) fn_1_13ABA8(0x28000000); else fn_1_13ABA8(0xA8000000);
    }
    if (lbl_1_bss_8B3A0.unk_94&4) {
        ch=lbl_1_bss_8B3A0.unk_9E; idx=(s8)ch; count=((s16 *)((u8 *)&lbl_1_bss_8B3A0+idx*0x20))[7];
        fn_1_134EE4(0,0,0,lbl_1_rodata_861C);
        v=lbl_801A66B4==5?0:(count<=0x28?7:4);
        fn_1_135894((void*)0xE7,(void*)(0x16E-v),(void*)6,(void*)count,(void*)(s16)*(s16*)arg0,(void*)0,(void*)0,lbl_1_rodata_863C,lbl_1_rodata_863C);
        fn_1_136174(0xE7,0x163,(void*)1,*(s16*)arg0,(void*)count,lbl_801A66B4,0,lbl_1_rodata_85F0,lbl_1_rodata_85F0);
        fn_1_1363F0(ch,0,0);
        fn_1_1368A0(count,ch,0,lbl_1_rodata_865C,lbl_1_rodata_8644,lbl_1_rodata_8660,lbl_1_rodata_863C,lbl_1_rodata_863C);
        fn_1_13750C((void*)0x12,(void*)0x3A,(void*)count,(void*)(s8)ch);
        fn_1_13A848(0x1c0,0x114,(void*)count,(void*)1,0,lbl_1_rodata_864C,lbl_1_rodata_8650);
        fn_1_13A994((void*)0x1c0,(void*)0x128,(void*)1,(void*)count,(void*)(s16)lbl_801A66B4,0,lbl_1_rodata_8664,lbl_1_rodata_8664);
    } else {
        PacketStorage packet;
        packet=*(PacketStorage*)lbl_1_rodata_26F8;
        *(u32*)&packet.w[1]=0x19D11; *(f32*)&packet.w[2]=lbl_1_rodata_8668; *(f32*)&packet.w[3]=lbl_1_rodata_866C; *(f32*)&packet.w[4]=lbl_1_rodata_8670;
        fn_1_4F734((FontDrawPacket*)&packet.w[1]); *(u32*)&packet.w[14]=7; *(f32*)&packet.w[2]=lbl_1_rodata_8674-*(f32*)&packet.w[2]; fn_1_4F734((FontDrawPacket*)&packet.w[1]);
        packet=*(PacketStorage*)lbl_1_rodata_26F8; *(u32*)&packet.w[1]=0x12; *(f32*)&packet.w[2]=lbl_1_rodata_8678; *(f32*)&packet.w[3]=lbl_1_rodata_867C;
        count=fn_1_48690(0x12); *(f32*)&packet.w[6]*=lbl_1_rodata_8680/(f32)count;
        count=fn_1_486C4(*(u32*)&packet.w[1]); *(f32*)&packet.w[5]=lbl_1_rodata_8688; *(u32*)&packet.w[15]=lbl_1_rodata_8654; *(f32*)&packet.w[13]=lbl_1_rodata_85F0; *(f32*)&packet.w[7]*=lbl_1_rodata_8684/(f32)count;
        fn_1_4F734((FontDrawPacket*)&packet.w[1]);
        fn_1_1332FC(0xF,0x38,0); fn_1_1332FC(0x269,0x38,1); fn_1_133748(0x7e,0xfd); fn_1_13354C(7,0x42,0); fn_1_13354C(0x279,0x42,1); fn_1_133968();
        if (lbl_1_bss_8B3A0.unk_94&0x2000) {
            fn_1_133A8C(); count=0;
            for(i=0;i<4;i++) { v=*(s16*)(b+i*0x20+0xe); if(v!=-1) { if(count==0) { fn_1_138A04(0xe,0x41,i); fn_1_137548((void*)0x26,(void*)0x7b,(void*)v,(void*)i); } else if(count==1) { fn_1_138A04(0xe,0x10a,i); fn_1_137548((void*)0x26,(void*)0x144,(void*)v,(void*)i); } count++; } }
        } else {
            fn_1_1332FC(0x13c,0x38,0); fn_1_133BD8();
            for(i=0;i<4;i++) { v=*(s16*)(b+i*0x20+0xe); idx=fn_1_141F94(i); if(v!=-1) { if(idx==0) { fn_1_138E44(0xe,0x41,i); fn_1_137584((void*)0x1e,(void*)0x88,(void*)v,(void*)i); } else if(idx==1) { fn_1_138E44(0x13a,0x41,i); fn_1_137584((void*)0x14b,(void*)0x88,(void*)v,(void*)i); } else if(idx==2) { fn_1_138E44(0xe,0x10a,i); fn_1_137584((void*)0x1e,(void*)0x151,(void*)v,(void*)i); } else if(idx==3) { fn_1_138E44(0x13a,0x10a,i); fn_1_137584((void*)0x14b,(void*)0x151,(void*)v,(void*)i); } } }
            idx=(u8)lbl_1_bss_8B3A0.unk_4; while((u8)idx<4) { fn_1_13923C(((idx&1)*0x12d)+0x1e,((idx>>1)*0xc9)+0x88); idx++; }
        }
    }
    if(lbl_1_bss_960!=2 && !(lbl_1_bss_8B3A0.unk_94&0x40)) {
        s16 selected=lbl_1_bss_962; s16 car=lbl_1_bss_8B3A0.unk_0;
        v=*(s16*)(lbl_1_bss_8B3A0.unk_A4+selected*0x4a);
        count=car?0x9e:(lbl_1_bss_8B3A0.unk_4==4?0x7e:0xab);
        if(v>0||(lbl_1_bss_8B3A0.unk_140&1)) { fn_1_13FB8C(0x140,0xf0,0x16d,count,car!=3,lbl_1_rodata_868C); fn_1_14083C(0x140,0xf0,0x16d,count,10,lbl_1_rodata_8690,lbl_1_rodata_863C); }
    }
}
