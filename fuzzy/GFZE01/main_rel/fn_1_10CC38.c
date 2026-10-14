/* Non-matching: best partial attempt (42.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

extern void *fn_80077B14(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006E250(void *, void *);
extern f32 lbl_1_rodata_7AB8[88];

typedef struct { u8 b[0x44]; } AccessoryNode;
typedef struct { u8 b[0x18C]; } AccessoryModel;
static inline f32 *F(void *p, int o) { return (f32 *)((u8 *)p + o); }
static inline u32 *W(void *p, int o) { return (u32 *)((u8 *)p + o); }

void fn_1_10CC38(void *arg0) {
    u32 i;
    AccessoryNode *node;
    void *manager;
    AccessoryModel *model;
    f32 d[3], len, scale;
    if (!arg0 || !*W(arg0, 0x10)) return;
    fn_80077B14(*(void **) ((u8 *)arg0 + 0x10));
    if (*(u8 *)arg0 & 2) {
        *(u8 *)arg0 &= ~2;
        model = (AccessoryModel *)*(void **)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x0C) + 0x150) + 8);
        model = (AccessoryModel *)((u8 *)model + ((u32)((u32 *)&lbl_1_data_3FFBC)[*(u32 *)((u8 *)arg0 + 8)] * 0x18C) + 0x88);
        lbl_8006DBAC(model); lbl_8006DAEC();
        node = *(AccessoryNode **)((u8 *)arg0 + 0x24);
        for (i=0; i<*W(arg0,0x18); ++i,node++) {
            lbl_8006DBE4(); lbl_8006E1B0(node->b+0x28,node->b+0x10);
        }
        lbl_8006DC20();
    }
    node = *(AccessoryNode **)((u8 *)arg0 + 0x24);
    for (i=0;i<*W(arg0,0x18);++i,node++) if (!(*(u8 *)node->b&1)) {
        *W(node,0x1C)=*W(node,0x10); *W(node,0x20)=*W(node,0x14); *W(node,0x24)=*W(node,0x18);
        *F(node,0x10)+=*F(node,0x34); *F(node,0x14)+=*F(node,0x38); *F(node,0x18)+=*F(node,0x3C);
        *F(node,0x14)-=0.0013611111376020642;
        *F(node,0x38)-=0.0027222223579883575f;
    }
    manager=*(void **)((u8 *)arg0+0x0C);
    model=(AccessoryModel *)((u8 *)*(void **)((u8 *)manager+0x150)+8);
    model=(AccessoryModel *)((u8 *)model + (((u32 *)&lbl_1_data_3FFBC)[*(u32 *)((u8 *)arg0+8)]*0x18C));
    node=*(AccessoryNode **)((u8 *)arg0+0x24);
    for(i=0;i<*W(arg0,0x18);i++,node++){ lbl_8006DBAC(model->b+0x88); lbl_8006DAEC(); if(*(u8 *)node->b&1){lbl_8006DBE4();lbl_8006E1B0(node->b+0x28,node->b+0x10);} lbl_8006DC20(); }
    node=*(AccessoryNode **)((u8 *)arg0+0x24);
    for(i=0;i<*W(arg0,0x18);i++,node++){
        lbl_8006DBAC(model->b+0x88); lbl_8006E1B0(node->b+0x28,node->b+8);
        d[0]=*F(node,0x10)-*F(node,8); d[1]=*F(node,0x14)-*F(node,0x0C); d[2]=*F(node,0x18)-*F(node,0x10);
        len=d[0]*d[0]+d[1]*d[1]+d[2]*d[2];
        if(len>0.0001f){scale=lbl_8006D0B4(0.0001f/len); *F(node,0x10)=*F(node,8)+d[0]*scale; *F(node,0x14)=*F(node,0x0C)+d[1]*scale; *F(node,0x18)=*F(node,0x10)+d[2]*scale; *W(node,0x1C)=*W(node,0x10);*W(node,0x20)=*W(node,0x14);*W(node,0x24)=*W(node,0x18);}
    }
    {
      f32 mat[12]; u32 *p=(u32 *)lbl_1_rodata_7AB8;
      void *m=*(void **)((u8 *)*(void **)((u8 *)manager+0x150)+8);
      mat[0]=p[0x148/4];mat[1]=p[0x14C/4];mat[2]=p[0x150/4];
      lbl_8006DBAC((u8 *)m+0x844);
      *(f32 *)(0xE0000000+0x0C)=*(f32 *)(0xE0000000+0x08)*0.04899999871850014f+*(f32 *)(0xE0000000+0x0C);
      *(f32 *)(0xE0000000+0x1C)=*(f32 *)(0xE0000000+0x18)*0.04899999871850014f+*(f32 *)(0xE0000000+0x1C);
      *(f32 *)(0xE0000000+0x2C)=*(f32 *)(0xE0000000+0x28)*0.04899999871850014f+*(f32 *)(0xE0000000+0x2C);
      lbl_8006E1B0(mat,mat);
    }
    node=*(AccessoryNode **)((u8 *)arg0+0x24);
    for(i=0;i<*W(arg0,0x18);i++,node++) if(!(*(u8 *)node->b&1)){
      d[0]=*F(node,0x10)-0; d[1]=*F(node,0x14)-0; d[2]=*F(node,0x18)-0;
      len=d[0]*d[0]+d[1]*d[1]+d[2]*d[2];
      if(len<0.002500000176951289f){scale=0.05000000074505806f/lbl_8006D0B4(len);*F(node,0x10)+=d[0]*scale;*F(node,0x14)+=d[1]*scale;*F(node,0x18)+=d[2]*scale;}
    }
    node=*(AccessoryNode **)((u8 *)arg0+0x24);
    for(i=0;i<*W(arg0,0x18);i++,node++){
      lbl_8006DBAC(model->b+0x88); lbl_8006E1B0(node->b+0x28,node->b+0x10);
      *W(node,0x1C)=*W(node,0x10);*W(node,0x20)=*W(node,0x14);*W(node,0x24)=*W(node,0x18);
    }
}
