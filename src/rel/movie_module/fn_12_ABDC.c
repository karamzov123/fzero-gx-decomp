#include "types.h"
typedef struct Sig_fn_12_ABDC_MPVContext Sig_fn_12_ABDC_MPVContext;
typedef struct Sig_fn_12_ABDC_SJInterface Sig_fn_12_ABDC_SJInterface;
typedef struct Sig_fn_12_ABDC_SJ Sig_fn_12_ABDC_SJ;
typedef struct Sig_fn_12_ABDC_MPVDecoderFields {
 union { unsigned char padding_extent[168]; struct { unsigned char padding_field_1AC[28]; s32 field_1AC; } view_field_1AC; } fields;
} Sig_fn_12_ABDC_MPVDecoderFields;
typedef union Sig_fn_12_ABDC_MPVConditionState {
 union { unsigned char padding_extent[168]; struct { int conditions[17]; } view_conditions; struct { Sig_fn_12_ABDC_MPVDecoderFields decoder; } view_decoder; } fields;
} Sig_fn_12_ABDC_MPVConditionState;
typedef struct Sig_fn_12_ABDC_MPVErrorInfo {
 union { unsigned char padding_extent[20]; struct { unsigned char padding_field_0C[12]; int field_0C; } view_field_0C; struct { unsigned char padding_field_10[16]; int field_10; } view_field_10; } fields;
} Sig_fn_12_ABDC_MPVErrorInfo;
typedef struct Sig_fn_12_ABDC_SJCK {
 union { unsigned char padding_extent[8]; struct { unsigned char *data; } view_data; struct { unsigned char padding_len[4]; int len; } view_len; } fields;
} Sig_fn_12_ABDC_SJCK;
struct Sig_fn_12_ABDC_MPVContext {
 union {
 struct { unsigned char padding_chunk[4808]; Sig_fn_12_ABDC_SJCK chunk; } view_chunk;
 unsigned char padding_extent[4992];
 struct { unsigned char padding_condition_state[400]; Sig_fn_12_ABDC_MPVConditionState condition_state; } view_condition_state;
 struct { unsigned char padding_error_info[544]; Sig_fn_12_ABDC_MPVErrorInfo error_info; } view_error_info;
 struct { unsigned char padding_field_1300[4800]; s32 field_1300; } view_field_1300;
 struct { unsigned char padding_field_1304[4804]; s32 field_1304; } view_field_1304;
 struct { unsigned char padding_field_1324[4852]; s32 field_1324; } view_field_1324;
 } fields;
};
struct Sig_fn_12_ABDC_SJInterface {
 union {
 unsigned char padding_extent[48];
 struct { unsigned char padding_get_chunk[24]; void (*get_chunk)(Sig_fn_12_ABDC_SJ *, int, int, Sig_fn_12_ABDC_SJCK *); } view_get_chunk;
 struct { unsigned char padding_unget_chunk[28]; void (*unget_chunk)(Sig_fn_12_ABDC_SJ *, int, Sig_fn_12_ABDC_SJCK *); } view_unget_chunk;
 struct { unsigned char padding_put_chunk[32]; void (*put_chunk)(Sig_fn_12_ABDC_SJ *, int, Sig_fn_12_ABDC_SJCK *); } view_put_chunk;
 } fields;
};
struct Sig_fn_12_ABDC_SJ {
 union { unsigned char padding_extent[4]; struct { const Sig_fn_12_ABDC_SJInterface *interface; } view_interface; } fields;
};
typedef struct Sig_fn_12_9744_MovieState {
 u8 _pad10[0x10]; s32 field_10; s32 field_14; s32 field_18; s32 field_1c;
} Sig_fn_12_9744_MovieState;
typedef struct Sig_fn_12_9730_MovieModule {
 u8 _pad0[0x318]; u32 field_318; u32 field_31c; u32 field_320;
} Sig_fn_12_9730_MovieModule;
typedef u32 (*fn_12_ABDC_Fn0)(u32, u32, u32, u32);
extern void fn_12_9730(Sig_fn_12_9730_MovieModule *);
extern void fn_12_9744(Sig_fn_12_9744_MovieState *);
extern u32 fn_800589BC(Sig_fn_12_ABDC_SJCK *, s32, Sig_fn_12_ABDC_SJCK *, Sig_fn_12_ABDC_SJCK *);
#pragma opt_propagation off
void fn_12_ABDC(Sig_fn_12_ABDC_MPVContext *arg0, Sig_fn_12_ABDC_SJ *arg1, u32 arg2) {
 u32 v0;
 u32 v8;
 u32 v9;
 u32 v2;
 u8 *v1;
 u32 v3;
 u32 v4;
 u32 v5;
 u32 v6;
 u32 v7;
 u32 v10;
 u32 v11;
 u32 v12;
 u32 v13;
 u32 v14;
 u32 v15;
 u32 v16;
 u32 v17;
 u32 v18;
 u32 v19;
 u32 v20;
 Sig_fn_12_ABDC_SJCK chunk;
 arg1->fields.view_interface.interface->fields.view_get_chunk.get_chunk(arg1, 1, 0x7fffffff, &arg0->fields.view_chunk.chunk);
 v0 = *(u32 *)((u8 *)arg0 + 4808);
 v1 = (u8 *)(v0 & ~3);
 v2 = (v0 - (u32)v1) << 3;
 v5 = *(u32 *)v1;
 v6 = *(u32 *)(v1 + 4);
 v1 += 8;
 v5 <<= v2;
 if ((s32)v2 >= 32) {
  v2 -= 32;
  v5 = v6 << v2;
  v6 = *(u32 *)v1;
  v1 += 4;
 }
 if ((s32)v2 != 0) {
  v8 = v6 << v2;
  v0 = v5 | (v6 >> (32 - v2));
 } else {
  v0 = v5;
  v8 = v6;
 }
 v9 = *(u32 *)v1;
 v1 += 4;
 *(u32 *)((u8 *)arg0 + 776) = (((v0 & 0xff) - 1) * *(u32 *)((u8 *)arg0 + 472)) - 1;
 if ((s32)v2 >= 27) {
  v2 -= 27;
  if (v2 != 0) {
   v8 |= v9 >> (5 - v2);
   *(u32 *)((u8 *)arg0 + 700) = v8 >> 27;
   v8 = v9 << v2;
  } else {
   v15 = v8 >> 27;
   v8 = v9;
   *(u32 *)((u8 *)arg0 + 700) = v15;
  }
  v9 = *(u32 *)v1;
  v1 += 4;
 } else {
  v16 = v8 >> 27;
  v8 <<= 5;
  *(u32 *)((u8 *)arg0 + 700) = v16;
  v2 += 5;
 }
 fn_12_9744((Sig_fn_12_9744_MovieState *)((u8 *)arg0 + 704));
 fn_12_9744((Sig_fn_12_9744_MovieState *)((u8 *)arg0 + 740));
 fn_12_9730((Sig_fn_12_9730_MovieModule *)arg0);
 for (;;) {
  if (!(v8 >> 31)) {
   v2 += 1;
   if ((s32)v2 >= 32) {
    v2 -= 32;
    v1 += 4;
   }
   break;
  }
  v2 += 9;
  if ((s32)v2 >= 32) {
   v2 -= 32;
   v8 = v9 << v2;
   v9 = *(u32 *)v1;
   v1 += 4;
  } else {
   v8 <<= 9;
  }
  v0 = (u32)v1 + (((s32)v2 + 7) >> 3);
  v19 = *(u32 *)((u8 *)arg0 + 4812);
  v18 = *(u32 *)((u8 *)arg0 + 4808);
  v20 = v0 - 8 - v18;
  if ((s32)v19 <= (s32)v20) return;
 }
 *(u32 *)((u8 *)arg0 + 4816) = v2 & 7;
 v20 = (u32)v1 + (((s32)(v2 - *(u32 *)((u8 *)arg0 + 4816)) + 7) >> 3);
 v18 = *(u32 *)((u8 *)arg0 + 4808);
 fn_800589BC(&arg0->fields.view_chunk.chunk,
 (s32)(v20 - 8 - v18),
 &arg0->fields.view_chunk.chunk, &chunk);
 arg1->fields.view_interface.interface->fields.view_put_chunk.put_chunk(arg1, 0, &arg0->fields.view_chunk.chunk);
 arg1->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(arg1, 1, &chunk);
 (*(void (**)(Sig_fn_12_ABDC_MPVContext *, Sig_fn_12_ABDC_SJ *))((u8 *)arg0 + 660))(arg0, arg1);
}
