#include "types.h"
#include "sofdec/sfd.h"

/* fzgx:begin fn_12_2B138 noprologue */
#include "types.h"

extern u32 fn_12_24990(u32);
extern u32 fn_12_24A88(u32, u32);

u32 fn_12_2B138(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    t0 = fn_12_24990(arg0);
    v0 = t0;
    if ((s32)t0 != 0) {
    v0 = 0;
    t1 = fn_12_24A88(v0, (0xFF000000 + 321));
    v0 = t1;
    v0 = 0;
    } else {
    v0 = *(u32 *)((u8 *)arg0 + 80);
    }
    return v0;
}
/* fzgx:end fn_12_2B138 */

/* fzgx:begin fn_12_2B188 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_2B188.c --- */
extern int fn_12_24990(void);
extern void fn_12_24A88(int arg0, u32 arg1);
extern void fn_12_226D0(void *arg0, void *arg1);

void fn_12_2B188(void *arg0, void *arg1) {
    if (fn_12_24990()) {
        fn_12_24A88(0, 0xff000139);
    } else {
        fn_12_226D0(arg0, arg1);
    }
}
/* fzgx:end fn_12_2B188 */

/* fzgx:begin fn_12_2B1E8 noprologue */

/* --- rel/movie_module/fn_12_2B1E8.c --- */
struct MovieModule {
    char pad_960[0x960];
    int value_960;
};

extern void fn_12_24A88(int value, u32 code);
extern void fn_12_2F210(struct MovieModule *module, int value, int size, void *data, int flags);

void fn_12_2B1E8(struct MovieModule *module, void *data) {
    if (fn_12_24990()) {
        fn_12_24A88(0, 0xff000137);
    } else {
        module->value_960 = 0;
        fn_12_2F210(module, 6, 12, data, 0);
    }
}
/* fzgx:end fn_12_2B1E8 */

/* fzgx:begin fn_12_2B25C noprologue */
#include "types.h"

struct MovieModule {
    char pad_960[0x960];
    int value_960;
};

extern int fn_12_24990(struct MovieModule *module);
extern void fn_12_24A88(int value, u32 code);
extern void fn_12_2F210(struct MovieModule *module, int value, int size, void *data, int flags);

void fn_12_2B25C(struct MovieModule *module, void *data) {
    *(u32 *)data = 0;
    if (fn_12_24990(module)) {
        fn_12_24A88(0, 0xff000136);
    } else {
        fn_12_2F210(module, 6, 11, data, 0);
        if (*(u32 *)data != 0) {
            module->value_960 = 1;
        }
    }
}
/* fzgx:end fn_12_2B25C */

/* fzgx:begin fn_12_2B2E4 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_2B2E4.c --- */
struct MovieModule {
    char pad_44[0x44];
    int value;
    char pad_1ab4[0x1a6c];
    int field_1ab4;
};

extern int fn_12_24990(struct MovieModule *module);
extern int fn_12_24A88(int arg0, u32 arg1);
extern void fn_12_21D40(struct MovieModule *module, int value, int arg2);

int fn_12_2B2E4(struct MovieModule *module) {
    if (fn_12_24990(module)) {
        return fn_12_24A88(0, 0xff000135);
    } else {
        fn_12_21D40(module, module->field_1ab4, 1);
        module->value = 1;
        return 0;
    }
}
/* fzgx:end fn_12_2B2E4 */

/* fzgx:begin fn_12_2B348 noprologue */

/* --- rel/movie_module/fn_12_2B348.c --- */
extern u32 lbl_12_bss_7C64[137];

u32 fn_12_2B348(void) {
    return lbl_12_bss_7C64[127];
}
/* fzgx:end fn_12_2B348 */

/* fzgx:begin fn_12_2B358 noprologue */
#include "types.h"
struct fn_12_2B358_Copy64 { u32 a[17]; };
typedef struct Sig_fn_12_248D4_MovieModule {
 u32 unk_00; u8 pad_04[8]; u32 unk_0c; u8 pad_10[0x80]; u32 unk_90;
} Sig_fn_12_248D4_MovieModule;
struct Sig_fn_12_2F210_fn_12_2F210_Arg0;
struct Sig_fn_12_2F264_Movie;
extern int fn_12_24990(u32);
extern int fn_12_24A88(void *, u32);
extern int fn_12_2F210(struct Sig_fn_12_2F210_fn_12_2F210_Arg0 *, int, int, void *, int);
extern int fn_12_2F264(struct Sig_fn_12_2F264_Movie *, int);
extern void fn_12_24970(void *);
extern void fn_12_24950(void *);
extern u32 lbl_12_bss_7C64[137];
extern void fn_12_248D4(Sig_fn_12_248D4_MovieModule *);
extern void fn_12_22888(u32);
extern void *fn_12_57F0(void *, const void *, u32);
extern s32 fn_12_2BAE0(void *, s32);
extern void fn_12_21D40(void *, int, int);
static inline s32 reset_state(u32 arg0) {
 s32 result;
 if (*(s32 *)(arg0+0x48)==4) {
  result=fn_12_2F210((void *)arg0,7,7,0,0);
  if(result) return result;
 }
 *(s32 *)(arg0+0x48)=1;
 *(s32 *)(arg0+0x4c)=1;
 return 0;
}
static inline s32 reset_body(u32 arg0) {
 u32 *p_lbl_12_bss_7C64;
 s32 v0;
 s32 v6;
 s32 v3;
 struct { s32 value; } saved;
 s32 final_result;
#define v4 saved.value
 struct { u32 a[100]; } loc_6C;
 struct fn_12_2B358_Copy64 loc_28;
 struct { u32 a[7]; } loc_C;
 u32 loc_8;
 if (*(s32 *)(arg0+0x48)==1) return 0;
 v0=reset_state(arg0);
 if(v0) return v0;
 fn_12_24970(&loc_8);
 lbl_12_bss_7C64[127]=1;
 p_lbl_12_bss_7C64=lbl_12_bss_7C64;
 v4=0;
 loc_28=*(struct fn_12_2B358_Copy64 *)arg0;
 v3=*(s32 *)(arg0+0x9c0);
 if(v3) {
  if(fn_12_24990(arg0)) fn_12_24A88(0,0xff000134);
  else fn_12_2F210((void *)arg0,0,9,&loc_C,0);
  v4=loc_C.a[5];
 }
 fn_12_248D4((void *)(arg0+0x78));
 fn_12_22888(arg0);
 *(s32 *)(arg0+0x48)=0;
 *(s32 *)(arg0+0x4c)=0;
#undef v4
#define v4 final_result
 v0=fn_12_2F264((void *)arg0,4);
 if(v0) { v4=v0; goto cleanup; } /* Shared cleanup restores the module lock. */
 fn_12_57F0(&loc_6C,(void *)(arg0+0xb30),0x190);
 v6=fn_12_2BAE0(&loc_28,0);
 if(!v6) { v4=fn_12_24A88(0,0xff000202); goto cleanup; } /* Shared cleanup restores the module lock. */
 fn_12_57F0((void *)(v6+0x9a0),&loc_6C,0x190);
 fn_12_57F0((void *)(v6+0xb30),&loc_6C,0x190);
 if(v3) {
  if(fn_12_24990(v6)) v0=fn_12_24A88(0,0xff000134);
  else v0=fn_12_2F210((void *)v6,0,9,&loc_C,0);
  if(v0) { v4=v0; goto cleanup; } /* Shared cleanup restores the module lock. */
  v3=loc_C.a[5];
  if(fn_12_24990(v6)) v0=fn_12_24A88(0,0xff000135);
  else v0=fn_12_2F210((void *)v6,0,10,(void *)saved.value,v3);
  if(v0) { v4=v0; goto cleanup; } /* Shared cleanup restores the module lock. */
  if(fn_12_24990(v6)) fn_12_24A88(0,0xff000135);
  else {
   fn_12_21D40((void *)v6,*(s32 *)(v6+0x1ab4),1);
   *(s32 *)(v6+0x44)=1;
  }
 }
 v4=0;
cleanup:
 p_lbl_12_bss_7C64[127]=0;
 fn_12_24950(&loc_8);
 if(v4) return v4;
 return 0;
}
s32 fn_12_2B358(u32 arg0) {
 s32 result;
 if(fn_12_24990(arg0)) return fn_12_24A88(0,0xff000133);
 result=reset_body(arg0);
 *(s32 *)(arg0+0x44)=1;
 return result;
}
/* fzgx:end fn_12_2B358 */

/* fzgx:begin fn_12_2B634 noprologue */
#include "types.h"

struct MovieModule {
    char pad_44[0x44];
    int field_44;
    int field_48;
    int field_4c;
};

extern int fn_12_24990(struct MovieModule *module);
extern int fn_12_24A88(int arg0, u32 arg1);
extern int fn_12_2D73C(struct MovieModule *module, int arg1);
extern int fn_12_2AD78(struct MovieModule *module);

int fn_12_2B634(struct MovieModule *module) {
    int result;

    if (fn_12_24990(module)) {
        return fn_12_24A88(0, 0xff000132);
    } else {
        if (fn_12_2D73C(module, 0x2f) == 1) {
            result = fn_12_2AD78(module);
        } else {
            result = 0;
            module->field_4c = 4;
        }
        module->field_44 = 1;
        return result;
    }
}
/* fzgx:end fn_12_2B634 */

/* fzgx:begin fn_12_2B6B0 noprologue */
#include "types.h"
#pragma use_lmw_stmw on

struct fn_12_2B6B0_Copy64 { u32 a[17]; };
extern int fn_12_24990(u32);
extern int fn_12_24A88(void *, u32);
extern int fn_12_2F210(void *, int, int, u32, u32);
extern void fn_12_24970(void *);
extern void fn_12_24950(void *);
extern void fn_12_248D4(void *);
extern void fn_12_22888(u32);
extern int fn_12_2F264(void *, int);
extern void *fn_12_57F0(void *, const void *, u32);
extern u32 fn_12_2BAE0(void *, int);
extern void fn_12_21D40(void *, int, int);
extern u32 lbl_12_bss_7C64[137];

static inline void setFlag(int value) { lbl_12_bss_7C64[127]=value; }
static inline int prepare(u32 arg0) {
 if (*(int *)(arg0+0x48)==4) {
  int result=fn_12_2F210((void *)arg0,7,7,0,0);
  if (result!=0) return result;
 }
 *(int *)(arg0+0x48)=1;
 *(int *)(arg0+0x4c)=1;
 return 0;
}
int fn_12_2B6B0(u32 arg0) {
 u8 loc_6C[400];
 struct fn_12_2B6B0_Copy64 loc_28;
 u32 loc_C[7];
 u32 loc_8;
 u32 current;
 u32 *p_lbl_12_bss_7C64;
 u32 v3;
 struct { u32 value; } saved;
 u32 v5;
 u32 v6;
 u32 zero;
 int result;
 int i;
 if (fn_12_24990(arg0)) {
  return fn_12_24A88(0,0xff000131);
 }
 if (*(int *)(arg0+0x48)!=1) {
  result=prepare(arg0);
  if (result==0) {
   fn_12_24970(&loc_8);
   setFlag(1);
   p_lbl_12_bss_7C64=lbl_12_bss_7C64;
   saved.value=0;
   loc_28=*(struct fn_12_2B6B0_Copy64 *)arg0;
   v3=*(u32 *)(arg0+0x9c0);
   if ((int)v3!=0) {
    if (fn_12_24990(arg0)) fn_12_24A88(0,0xff000134);
    else fn_12_2F210((void *)arg0,0,9,(u32)loc_C,0);
    saved.value=loc_C[5];
   }
   fn_12_248D4((void *)(arg0+0x78));
   fn_12_22888(arg0);
   *(int *)(arg0+0x48)=0;
   *(int *)(arg0+0x4c)=0;
   if (fn_12_2F264((void *)arg0,4)==0) {
    fn_12_57F0(loc_6C,(void *)(arg0+0xb30),400);
    v5=fn_12_2BAE0(&loc_28,0);
    if (!v5) fn_12_24A88(0,0xff000202);
    else {
     fn_12_57F0((void *)(v5+0x9a0),loc_6C,400);
     fn_12_57F0((void *)(v5+0xb30),loc_6C,400);
     if ((int)v3!=0) {
      if (fn_12_24990(v5)) result=fn_12_24A88(0,0xff000134);
      else result=fn_12_2F210((void *)v5,0,9,(u32)loc_C,0);
      if (!result) {
       v3=loc_C[5];
       if (fn_12_24990(v5)) result=fn_12_24A88(0,0xff000135);
       else result=fn_12_2F210((void *)v5,0,10,saved.value,v3);
       if (!result) {
        if (fn_12_24990(v5)) fn_12_24A88(0,0xff000135);
        else {
         fn_12_21D40((void *)v5,*(int *)(v5+0x1ab4),1);
         *(int *)(v5+0x44)=1;
        }
       }
      }
     }
    }
   }
   p_lbl_12_bss_7C64[127]=0;
   fn_12_24950(&loc_8);
  }
 }
 fn_12_248D4((void *)(arg0+0x78));
 fn_12_22888(arg0);
 *(int *)(arg0+0x48)=0;
 *(int *)(arg0+0x4c)=0;
 result=fn_12_2F264((void *)arg0,4);
 p_lbl_12_bss_7C64=lbl_12_bss_7C64+129;
 zero=0;
 for (i=0;i<8;i++) {
  current=*p_lbl_12_bss_7C64;
  if (current==arg0) *p_lbl_12_bss_7C64=zero;
  p_lbl_12_bss_7C64++;
 }
 return result;
}
/* fzgx:end fn_12_2B6B0 */

/* fzgx:begin fn_12_2B9F8 noprologue */

/* --- rel/movie_module/fn_12_2B9F8.c --- */
struct MovieState {
    char pad_0[4];
    int value;
};

struct MovieModule {
    char pad_0[0x94c];
    struct MovieState state;
};

typedef void (*MovieCallback)(struct MovieModule *, void *, struct MovieState *);

extern MovieCallback fn_12_2D73C(struct MovieModule *, int);

void fn_12_2B9F8(struct MovieModule *module, int delta, void *context) {
    struct MovieState *state;
    MovieCallback callback;

    state = &module->state;
    module->state.value += delta;
    callback = fn_12_2D73C(module, 0x25);
    if (callback != 0) {
        callback(module, context, state);
    }
}
/* fzgx:end fn_12_2B9F8 */

/* fzgx:begin fn_12_2BA6C noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_2BA6C.c --- */
struct MovieModule {
    char pad_94c[0x94c];
    int value_94c;
};

typedef void (*MovieCallback)(struct MovieModule *, void *, int *);

extern MovieCallback fn_12_2D73C(struct MovieModule *, int);

void fn_12_2BA6C(struct MovieModule *module, int delta, void *arg) {
    int *value = &module->value_94c;
    MovieCallback callback;

    *value += delta;
    callback = fn_12_2D73C(module, 0x24);
    if (callback != 0) {
        callback(module, arg, value);
    }
}
/* fzgx:end fn_12_2BA6C */

/* fzgx:begin fn_12_2BAE0 noprologue */

/* --- rel/movie_module/fn_12_2BAE0.c --- */
typedef struct Sig_fn_12_248E8_MovieModule {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u8 pad_10[0x80];
    u32 unk_90;
} Sig_fn_12_248E8_MovieModule;

struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

typedef struct Sig_fn_12_2D450_MovieModuleState {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
} Sig_fn_12_2D450_MovieModuleState;

typedef int (*Sig_fn_12_2F264_MovieHandler)(struct Sig_fn_12_2F264_Movie *, int, int, int);

struct Sig_fn_12_2F264_MovieItem {
    char pad0[0xc];
    Sig_fn_12_2F264_MovieHandler *handlers;
    char pad1[0x30];
    char pad2[4];
};

struct Sig_fn_12_2F264_Movie;
struct Sig_fn_12_2F264_Movie {
    char pad0[0x1aa0];
    struct Sig_fn_12_2F264_MovieItem items[1];
};
extern u32 lbl_12_bss_7C64;
extern void fn_12_33428(u32 *, u32, u32);
extern void fn_12_248E8(Sig_fn_12_248E8_MovieModule *);
extern void fn_12_2FE30(struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 *);
extern void fn_12_24B64(int *);
extern void * fn_12_57F0(void *, const void *, u32);
extern void fn_12_2D450(Sig_fn_12_2D450_MovieModuleState *);
extern int fn_12_2F264(struct Sig_fn_12_2F264_Movie *, int);

struct FzgxCopy_68 { u32 words[17]; };
s32 fn_12_22954(s32, s32, void *);                  /* extern */
s32 fn_12_2EE7C(s32, s32);                      /* extern */
s32 fn_12_2F63C(s32, s32, void *, s32);         /* extern */

s32 fn_12_2BAE0(void *arg0, s32 arg1) {
    s32 temp_r31;
    s32 var_r28;
    struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 *var_r27;
    u32 *temp_r27;

    temp_r27 = (u32 *)(*(u32 **)((u8 *)(arg0) + 60));
    fn_12_33428((u32 *)(temp_r27), (u32)(0U), (u32)((u32) (*(u32 *)((u8 *)(arg0) + 64)) >> 2U));
    temp_r31 = ((s32)(((u8 *)(temp_r27) + 0x1F))) & 0xFFFFFFE0;
    (*(s32 *)((u8 *)(temp_r31) + 76)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 72)) = 0;
    (*(s32 *)((u8 *)(arg0) + 4)) = (s32) (((*(s32 *)((u8 *)(arg0) + 4)) + 0x1F) & 0xFFFFFFE0);
    *(struct FzgxCopy_68 *)(temp_r31) = *(const struct FzgxCopy_68 *)(arg0);
    (*(s32 *)((u8 *)(temp_r31) + 68)) = 1;
    (*(s32 *)((u8 *)(temp_r31) + 80)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 84)) = 0;
    fn_12_248E8((Sig_fn_12_248E8_MovieModule *)(temp_r31 + 0x78));
    fn_12_33428((u32 *)(temp_r31 + 0x90C), (u32)(0U), (u32)(0x10U));
    (*(s32 *)((u8 *)(temp_r31) + 2316)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2320)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2324)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2328)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2332)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2336)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2340)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2344)) = 1;
    (*(s32 *)((u8 *)(temp_r31) + 2348)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2352)) = -1;
    (*(s32 *)((u8 *)(temp_r31) + 2356)) = -1;
    (*(s32 *)((u8 *)(temp_r31) + 2360)) = -1;
    fn_12_33428((u32 *)(temp_r31 + 0x94C), (u32)(0U), (u32)(0x10U));
    (*(s32 *)((u8 *)(temp_r31) + 2380)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2384)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2388)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2392)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2396)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2400)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2404)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2408)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2412)) = 0;
    (*(s32 *)((u8 *)(temp_r31) + 2416)) = 0;
    fn_12_33428((u32 *)(temp_r31 + 0x2918), (u32)(0U), (u32)(0x30U));
    var_r28 = 0;
    var_r27 = (struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 *)(temp_r31 + 0x2918);
    do {
        fn_12_2FE30((struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 *)(var_r27));
        var_r28 += 1;
        var_r27 = (struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 *)((u8 *)(var_r27) + 0x20);
    } while (var_r28 < 5);
    fn_12_2FE30((struct Sig_fn_12_2FE30_fn_12_2FE30_Arg0 *)(temp_r31 + 0x29B8));
    fn_12_24B64((int *)(temp_r31 + 0x98C));
    fn_12_57F0((void *)(temp_r31 + 0x9A0), (const void *)(&lbl_12_bss_7C64), (u32)(0x190U));
    fn_12_57F0((void *)(temp_r31 + 0xB30), (const void *)(&lbl_12_bss_7C64), (u32)(0x190U));
    fn_12_2EE7C((s32)(temp_r31), (s32)(temp_r31 + 0xCC0));
    if (fn_12_22954((s32)(temp_r31), (s32)(temp_r31 + 0x1140), (void *)(arg0)) != 0) {
        return 0;
    }
    fn_12_2F63C((s32)(temp_r31), (s32)(temp_r31 + 0x1AA0), (void *)(arg0), (s32)(arg1));
    fn_12_2D450((Sig_fn_12_2D450_MovieModuleState *)(temp_r31 + 0x2908));
    if (fn_12_2F264((struct Sig_fn_12_2F264_Movie *)((struct Sig_fn_12_2F264_Movie *)(temp_r31)), (s32)(3)) != 0) {
        return 0;
    }
    (*(s32 *)((u8 *)(temp_r31) + 76)) = 1;
    (*(s32 *)((u8 *)(temp_r31) + 72)) = 1;
    return temp_r31;
}
/* fzgx:end fn_12_2BAE0 */

/* fzgx:begin fn_12_2BCF4 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_2BCF4.c --- */
struct MovieModule {
    u32 pad_0;
    void *field_4;
    char pad_8[0x38];
    u32 field_40;
};

extern void *lbl_12_bss_7C64[137];
extern s32 fn_12_24A88(int arg0, u32 arg1);
extern void *fn_12_2BAE0(struct MovieModule *module, s32 arg);

void *fn_12_2BCF4(struct MovieModule *module, s32 arg) {
    int index;
    int i;
    void **table;
    void **p;
    int valid;
    void *movie;

    table = &lbl_12_bss_7C64[129];
    if (module->field_4 == 0) {
        valid = -1;
    } else if (module->field_40 < 0x29f8) {
        valid = -1;
    } else {
        valid = 0;
    }
    if (valid != 0) {
        fn_12_24A88(0, 0xff000203);
        return 0;
    }
    p = table;
    for (i = 0; i < 8; i++) {
        if (*p == 0) {
            index = i;
            goto found; /* search result, common exit */
        }
        p++;
    }
    index = -1;
found:
    if (index == -1) {
        return 0;
    }
    movie = fn_12_2BAE0(module, arg);
    table[index] = movie;
    return movie;
}
/* fzgx:end fn_12_2BCF4 */

/* fzgx:begin fn_12_2BE3C noprologue */

/* --- rel/movie_module/fn_12_2BE3C.c --- */
typedef struct MovieObj MovieObj;
typedef struct MovieObjVtbl {
    void *pad[9];
    int (*func_24)(MovieObj *obj, int arg);
} MovieObjVtbl;
struct MovieObj {
    MovieObjVtbl *vtbl;
};

typedef struct MovieSub {
    int field_0;
    MovieObj *obj;
    int field_8;
    int field_c;
} MovieSub;

typedef struct MovieEntry {
    int field_0;
    MovieSub sub;
    u8 pad_14[0x60];
} MovieEntry;

typedef struct MovieModule_u1 {
    u8 pad_0000[0x48];
    int field_48;
    int field_4c;
    int field_50;
    u8 pad_0054[0x96c - 0x54];
    int field_96c;
    u8 pad_0970[0xf00 - 0x970];
    int field_f00;
    int field_f04;
    u8 pad_0f08[0x114c - 0xf08];
    MovieEntry entries[1];
    u8 pad_11c0[0x1b38 - 0x11c0];
    int field_1b38;
} MovieModule_u1;

extern int fn_12_2D73C(MovieModule_u1 *module, int value);
extern int fn_12_2F1D0(MovieModule_u1 *module, int value);
extern int fn_12_21D30(MovieModule_u1 *module, int value);
extern int fn_12_21C00(MovieModule_u1 *module, int value);
extern int fn_12_2F1B4(MovieModule_u1 *module, int value);
extern s32 fn_12_2E714(MovieModule_u1 *module, s32 *a, s32 *b);
extern int UTY_MulDiv(int, int, int);
extern int fn_12_2E42C(int, int, int, int);

static inline int busy(MovieModule_u1 *module) {
    int i;

    if (fn_12_2D73C(module, 5) != 0 && fn_12_2F1D0(module, 6) != 0) {
        return 1;
    }
    if (fn_12_2D73C(module, 6) != 0 && fn_12_2F1D0(module, 7) != 0) {
        return 1;
    }
    for (i = 0; i < 8; i++) {
        if (fn_12_21D30(module, i) != 0) {
            return 1;
        }
    }
    return 0;
}

static inline int full(MovieModule_u1 *module) {
    MovieSub *sub = &module->entries[module->field_1b38].sub;
    int v = sub->obj->vtbl->func_24(sub->obj, 1);

    if (v >= sub->field_c * 80 / 100 || v >= fn_12_2D73C(module, 0x46)) {
        return 1;
    }
    return 0;
}

int fn_12_2BE3C(MovieModule_u1 *module) {
    s32 a;
    s32 b;
    int total;
    int rate;

    if (fn_12_2D73C(module, 0x43) == 0) {
        return 0;
    }
    if (fn_12_2D73C(module, 0xf) == 0) {
        return 0;
    }
    if (module->field_50 != 0) {
        return 0;
    }
    if (module->field_48 != 4) {
        return 0;
    }
    if (busy(module)) {
        return 0;
    }
    if (fn_12_2D73C(module, 5) == 1 && module->field_96c == 0) {
        return 0;
    }
    if (fn_12_2D73C(module, 6) == 1 && fn_12_21C00(module, 2) > 0) {
        return 0;
    }
    if (fn_12_2F1B4(module, 1) != 0 && fn_12_21C00(module, 0) > 0) {
        return 0;
    }
    if (fn_12_2D73C(module, 5) == 1 && full(module)) {
        return 0;
    }
    fn_12_2E714(module, &a, &b);
    total = module->field_f00;
    rate = module->field_f04;
    total -= UTY_MulDiv(fn_12_2D73C(module, 0x44), rate, 1000000);
    if (a <= 0 || total <= 0) {
        return 0;
    }
    return fn_12_2E42C(a, b, total, rate) == 0;
}
/* fzgx:end fn_12_2BE3C */

/* fzgx:begin fn_12_2C0F8 noprologue */

#include "types.h"

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

struct SJInterface {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_get_num_data[36];
            int (*get_num_data)(SJ *sj, int channel);
        } view_get_num_data;
    } fields;
};

struct SJ {
    union {
        unsigned char padding_extent[4];
        struct {
            const SJInterface *interface;
        } view_interface;
    } fields;
};

typedef int SfdConditionValue;

typedef int SfdTransportValue;

typedef struct SfdHandle SfdHandle;

typedef struct SfdPlaybackRuntime {
    union {
        unsigned char padding_extent[160];
        struct {
            unsigned char padding_field_1C[28];
            int field_1C;
        } view_field_1C;
        struct {
            unsigned char padding_field_20[32];
            int field_20;
        } view_field_20;
    } fields;
} SfdPlaybackRuntime;

typedef struct SfdTimerState {
    union {
        unsigned char padding_extent[1504];
        struct {
            unsigned char padding_field_0284[644];
            int field_0284;
        } view_field_0284;
        struct {
            unsigned char padding_field_0288[648];
            int field_0288;
        } view_field_0288;
    } fields;
} SfdTimerState;

typedef struct SfdTransportInterface SfdTransportInterface;

typedef struct SfdBufferSupply {
    union {
        unsigned char padding_extent[24];
        struct {
            unsigned char padding_stream_joint[4];
            SJ *stream_joint;
        } view_stream_joint;
        struct {
            unsigned char padding_buffer_size[12];
            int buffer_size;
        } view_buffer_size;
    } fields;
} SfdBufferSupply;

typedef struct SfdBufferRingWork {
    union {
        unsigned char padding_extent[60];
        struct {
            SfdBufferSupply supply;
        } view_supply;
    } fields;
} SfdBufferRingWork;

typedef union SfdBufferWork {
    union {
        unsigned char padding_extent[60];
        struct {
            SfdBufferRingWork ring;
        } view_ring;
    } fields;
} SfdBufferWork;

typedef int (*SfdTransportLifecycleFn)(SfdHandle *handle);

typedef int (*SfdTransportPauseFn)(SfdHandle *handle, int state);

typedef int (*SfdTransportTransferFn)(SfdHandle *handle, SfdTransportValue parameter, int value);

typedef int (*SfdTransportBufferFn)(SfdHandle *handle, void *buffer);

struct SfdTransportInterface {
    SfdTransportLifecycleFn init;
    SfdTransportLifecycleFn finish;
    SfdTransportLifecycleFn exec_server;
    SfdTransportLifecycleFn create;
    SfdTransportLifecycleFn destroy;
    SfdTransportLifecycleFn standby;
    SfdTransportLifecycleFn start;
    SfdTransportLifecycleFn stop;
    SfdTransportPauseFn pause;
    SfdTransportBufferFn get_write;
    SfdTransportTransferFn add_write;
    SfdTransportBufferFn get_read;
    SfdTransportTransferFn add_read;
    SfdTransportTransferFn seek;
};

typedef struct SfdBufferState {
    union {
        unsigned char padding_extent[116];
        struct {
            unsigned char padding_work[16];
            SfdBufferWork work;
        } view_work;
    } fields;
} SfdBufferState;

typedef struct SfdTransportState {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_interface[12];
            const SfdTransportInterface *interface;
        } view_interface;
        struct {
            unsigned char padding_parameter_10[16];
            int parameter_10;
        } view_parameter_10;
    } fields;
} SfdTransportState;

struct SfdHandle {
    union {
        unsigned char padding_extent[13720];
        struct {
            unsigned char padding_playback_state[72];
            int playback_state;
        } view_playback_state;
        struct {
            unsigned char padding_requested_state[76];
            int requested_state;
        } view_requested_state;
        struct {
            unsigned char padding_field_0050[80];
            int field_0050;
        } view_field_0050;
        struct {
            unsigned char padding_playback_runtime[2376];
            SfdPlaybackRuntime playback_runtime;
        } view_playback_runtime;
        struct {
            unsigned char padding_conditions_primary[2464];
            SfdConditionValue conditions_primary[100];
        } view_conditions_primary;
        struct {
            unsigned char padding_timer_state[3196];
            SfdTimerState timer_state;
        } view_timer_state;
        struct {
            unsigned char padding_buffers[4416];
            SfdBufferState buffers[8];
        } view_buffers;
        struct {
            unsigned char padding_transports[6816];
            SfdTransportState transports[9];
        } view_transports;
    } fields;
};

void fn_12_24970(int *token);

void fn_12_24950(int *token);

int fn_12_2E714(SfdHandle *handle, int *seconds, int *subsecond);

int fn_12_2E7C8(SfdHandle *handle, int *seconds, int *subsecond);

int fn_12_2EAC4(SfdHandle *handle);

int fn_12_2E42C(int lhs_seconds, int lhs_subsecond, int rhs_seconds, int rhs_subsecond);

SfdConditionValue fn_12_2D73C(SfdHandle *handle, int condition);

int fn_12_21D30(SfdHandle *handle, int buffer_index);

int fn_12_2F1D0(SfdHandle *handle, int transport_index);

int fn_12_2F210(SfdHandle *handle, int transport_index, int callback_index,
                SfdTransportValue parameter, int value);

int fn_12_2ADDC(SfdHandle *handle, int paused);

unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);

int fn_12_332DC(int lhs_value, int lhs_scale, int rhs_value, int rhs_scale);

static inline int sfply_StopTr(SfdHandle *handle) {
    int result;
    if (handle->fields.view_playback_state.playback_state == 4) {
        result = fn_12_2F210(handle, 7, 7, 0, 0);
        if (result != 0) {
            return result;
        }
    }
    handle->fields.view_playback_state.playback_state = 1;
    handle->fields.view_requested_state.requested_state = 1;
    return 0;
}

static inline int sfply_IsVidBufFull(SfdHandle *handle) {
    int buffer_index =
        handle->fields.view_transports.transports[2].fields.view_parameter_10.parameter_10;
    SfdBufferRingWork *ring = &handle->fields.view_buffers.buffers[buffer_index]
                                   .fields.view_work.work.fields.view_ring.ring;
    int data_size =
        ring->fields.view_supply.supply.fields.view_stream_joint.stream_joint->fields.view_interface
            .interface->fields.view_get_num_data.get_num_data(
                ring->fields.view_supply.supply.fields.view_stream_joint.stream_joint, 1);
    if (data_size >=
            (ring->fields.view_supply.supply.fields.view_buffer_size.buffer_size * 80) / 100 ||
        data_size >= fn_12_2D73C(handle, 0x46)) {
        return 1;
    }
    return 0;
}

int fn_12_2BE3C(SfdHandle *handle);

static inline int sfply_IsEndTime(SfdHandle *handle) {
    int current_seconds;
    int current_subsecond;
    int end_seconds = handle->fields.view_conditions_primary.conditions_primary[20];
    int end_subsecond = handle->fields.view_conditions_primary.conditions_primary[21];
    if (end_seconds == -4)
        return 0;
    fn_12_2E714(handle, &current_seconds, &current_subsecond);
    if (current_seconds < 0)
        return 0;
    if (fn_12_332DC(current_seconds, current_subsecond, end_seconds, end_subsecond) != 0)
        return 0;
    return 1;
}

static inline int sfply_IsTermAll(SfdHandle *handle) {
    int video_terminated;
    int audio_terminated;
    int terminated;
    if (handle->fields.view_conditions_primary.conditions_primary[6] == 0 &&
        handle->fields.view_conditions_primary.conditions_primary[5] == 0)
        return 1;
    terminated = 0;
    video_terminated = fn_12_2F1D0(handle, 6);
    audio_terminated = fn_12_2F1D0(handle, 7);
    switch (fn_12_2D73C(handle, 0x19)) {
    case 1:
        terminated = audio_terminated;
        break;
    case 2:
        terminated = video_terminated;
        break;
    case 3:
        terminated = audio_terminated | video_terminated;
        break;
    case 0:
        terminated = audio_terminated & video_terminated;
        break;
    }
    return terminated;
}

static inline int sfply_IsStagnant(SfdHandle *handle) {
    if (handle->fields.view_playback_state.playback_state != 4 ||
        handle->fields.view_field_0050.field_0050 == 1 ||
        handle->fields.view_playback_runtime.playback_runtime.fields.view_field_1C.field_1C == 1)
        return 0;
    if (fn_12_2EAC4(handle) != 0)
        return 1;
    return 0;
}

static inline int sfply_IsOverTime(SfdHandle *handle) {
    int current_seconds;
    int current_subsecond;
    int stop_seconds;
    if (handle->fields.view_playback_state.playback_state != 4 ||
        handle->fields.view_field_0050.field_0050 == 1 ||
        handle->fields.view_playback_runtime.playback_runtime.fields.view_field_1C.field_1C == 1)
        return 0;
    if (fn_12_2E7C8(handle, &current_seconds, &current_subsecond) != 0)
        return 0;
    if (current_seconds < 0)
        return 0;
    stop_seconds = fn_12_2D73C(handle, 0x36);
    if (fn_12_2E42C(stop_seconds, 1000, current_seconds, current_subsecond) != 0)
        return 1;
    return 0;
}

static inline int sfply_StopPlay(SfdHandle *handle) {
    int result = sfply_StopTr(handle);
    if (result != 0)
        return result;
    handle->fields.view_requested_state.requested_state = 6;
    return 0;
}

static inline int sfply_IsTermAny(SfdHandle *handle) {
    int buffer_index;
    if (fn_12_2D73C(handle, 5) != 0 && fn_12_2F1D0(handle, 6) != 0)
        return 1;
    if (fn_12_2D73C(handle, 6) != 0 && fn_12_2F1D0(handle, 7) != 0)
        return 1;
    for (buffer_index = 0; buffer_index < 8; buffer_index++) {
        if (fn_12_21D30(handle, buffer_index) != 0)
            return 1;
    }
    return 0;
}

static inline int sfply_IsAudBufFull(SfdHandle *handle) {
    int buffer_index =
        handle->fields.view_transports.transports[3].fields.view_parameter_10.parameter_10;
    SfdBufferRingWork *ring = &handle->fields.view_buffers.buffers[buffer_index]
                                   .fields.view_work.work.fields.view_ring.ring;
    int data_size =
        ring->fields.view_supply.supply.fields.view_stream_joint.stream_joint->fields.view_interface
            .interface->fields.view_get_num_data.get_num_data(
                ring->fields.view_supply.supply.fields.view_stream_joint.stream_joint, 1);
    return data_size >=
           (ring->fields.view_supply.supply.fields.view_buffer_size.buffer_size * 80) / 100;
}

static inline int sfply_IsBpaOff(SfdHandle *handle) {
    int current_seconds;
    int current_subsecond;
    int reference_seconds;
    int reference_scale;
    if (sfply_IsTermAny(handle) != 0)
        return 1;
    if (fn_12_2D73C(handle, 5) == 1) {
        if (sfply_IsVidBufFull(handle) != 0)
            return 1;
    }
    if (fn_12_2D73C(handle, 6) == 1) {
        if (sfply_IsAudBufFull(handle) != 0)
            return 1;
    }
    fn_12_2E714(handle, &current_seconds, &current_subsecond);
    reference_seconds =
        handle->fields.view_timer_state.timer_state.fields.view_field_0284.field_0284;
    reference_scale = handle->fields.view_timer_state.timer_state.fields.view_field_0288.field_0288;
    reference_seconds -= UTY_MulDiv(fn_12_2D73C(handle, 0x45), reference_scale, 1000000);
    if (fn_12_2E42C(current_seconds, current_subsecond, reference_seconds, reference_scale) != 0)
        return 1;
    return 0;
}

int fn_12_2C0F8(SfdHandle *handle) {
    int result;
    int state;
    int token;
    if (sfply_IsEndTime(handle) != 0 || sfply_IsTermAll(handle) != 0 ||
        sfply_IsStagnant(handle) != 0 || sfply_IsOverTime(handle) != 0) {
        result = sfply_StopPlay(handle);
    } else {
        result = 0;
    }
    if (result != 0) {
        return handle->fields.view_playback_state.playback_state;
    }
    fn_12_24970(&token);
    result = 0;
    if (handle->fields.view_playback_runtime.playback_runtime.fields.view_field_1C.field_1C == 0) {
        if (fn_12_2BE3C(handle) != 0) {
            handle->fields.view_playback_runtime.playback_runtime.fields.view_field_1C.field_1C = 1;
            handle->fields.view_playback_runtime.playback_runtime.fields.view_field_20.field_20++;
            result = fn_12_2ADDC(handle, 1);
        }
    } else {
        if (sfply_IsBpaOff(handle) != 0) {
            handle->fields.view_playback_runtime.playback_runtime.fields.view_field_1C.field_1C = 0;
            result = fn_12_2ADDC(handle, 0);
        }
    }
    fn_12_24950(&token);
    if (result != 0) {
        return handle->fields.view_playback_state.playback_state;
    }
    state = handle->fields.view_playback_state.playback_state;
    if (handle->fields.view_requested_state.requested_state != 5) {
        if (handle->fields.view_requested_state.requested_state < 5) {
            return state;
        }
        if (handle->fields.view_requested_state.requested_state < 7) {
            state = 6;
        }
    }
    return state;
}
/* fzgx:end fn_12_2C0F8 */

/* fzgx:begin fn_12_2C640 noprologue */
#include "types.h"

struct fn_12_2C640_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
    u32 unk_4C;
};

extern int fn_12_21E94(void *, int);
extern int fn_12_21F28(void *, int);
extern int fn_12_2D73C(void *, int);
extern int fn_12_2F1D0(void *, int);
extern int fn_12_2F1F0(void *, int);
extern u32 fn_12_2F210(void *, u32, u32, u32, u32);
extern void fn_12_2D420(void *, u32, u32);
extern void fn_12_2D7DC(void *, int, int);

#define FIELD(off) (*(s32 *)((u8 *)arg0 + (off)))

#pragma opt_dead_assignments off
s32 fn_12_2C640(struct fn_12_2C640_Arg0 *arg0) {
    s32 tmp_fn_12_2D73C;
    struct { s32 value; } v0;
    int v4;
    int v2;
    int v3;
    struct { u32 value; } v1;
    u32 v5;
    int v6;
    int v7;
    int t1;
    int t2;
    int t15;
    int t1_2;
    int t16;
    int ready;
    s32 tmp_fn_12_2F1D0;
    s32 tmp_call7;
    v0.value = arg0->unk_48;
    v1.value = arg0->unk_4C;
    tmp_fn_12_2D73C = fn_12_2D73C(arg0, 5);
    if (tmp_fn_12_2D73C == 0) {
        v2 = 1;
    } else {
        t1 = fn_12_2F1F0(arg0, 6);
        tmp_fn_12_2F1D0 = fn_12_2F1D0(arg0, 6);
        t2 = tmp_fn_12_2F1D0;
        v2 = t1 | t2;
    }
    tmp_fn_12_2D73C = fn_12_2D73C(arg0, 6);
    if (tmp_fn_12_2D73C == 0) {
        v3 = 1;
    } else {
        t1_2 = fn_12_2F1F0(arg0, 7);
        tmp_fn_12_2F1D0 = fn_12_2F1D0(arg0, 7);
        t2 = tmp_fn_12_2F1D0;
        v3 = t1_2 | t2;
    }
    if (v2 == 0 || v3 == 0) ready = 0;
    else ready = 1;
    if (ready == 0) {
        return v0.value;
    }
    tmp_call7 = FIELD(0x9b4);
    if (tmp_call7 == 1 && fn_12_21E94(arg0, 1) == 0 && fn_12_21F28(arg0, 1) == 0) {
        FIELD(0x9b4) = 0;
    }
    if (FIELD(0x9b8) == 1 && fn_12_21E94(arg0, 2) == 0 && fn_12_21F28(arg0, 2) == 0) {
        FIELD(0x9b8) = 0;
    }
    fn_12_2D420(arg0, FIELD(0x9b4), FIELD(0x9b8));
    if (FIELD(0x9b8) == 0 && FIELD(0x9dc) == 2) {
        fn_12_2D7DC(arg0, 15, 1);
    }
    if (FIELD(0x9b4) == 0 && FIELD(0x9dc) == 1) {
        fn_12_2D7DC(arg0, 15, 2);
    }
    v3 = 0;
    if (FIELD(0x9b8) == 1) v3 |= 1;
    if (FIELD(0x9b4) == 1) v3 |= 2;
    switch (v3) {
    case 1: v4 = 1; break;
    case 2: v4 = 2; break;
    case 3: v4 = fn_12_2D73C(arg0, 25); break;
    default: v4 = 3; break;
    }
    fn_12_2D7DC(arg0, 25, v4);
    switch ((s32)v1.value) {
    case 2: v0.value = 2; break;
    case 3: v0.value = 3; break;
    case 4:
    case 6:
        if (FIELD(0x9d8) == 0) {
            ready = 1;
        } else if (FIELD(0x9b4) == 0) {
            ready = 1;
        } else if (FIELD(0xf2c) != 0) {
            ready = 1;
        } else if (FIELD(0xf48) >= FIELD(0xa54)) {
            ready = 1;
        } else {
            if (FIELD(0x9b8) == 0 && FIELD(0x9b4) == 0) {
                v6 = 1;
            } else {
                v6 = 0;
                tmp_fn_12_2F1D0 = fn_12_2F1D0(arg0, 6);
                v0.value = tmp_fn_12_2F1D0;
                tmp_fn_12_2F1D0 = fn_12_2F1D0(arg0, 7);
                v2 = tmp_fn_12_2F1D0;
                v7 = v2;
                tmp_fn_12_2D73C = fn_12_2D73C(arg0, 25);
                switch (tmp_fn_12_2D73C) {
                case 1: v6 = v7; break;
                case 2: v6 = v0.value; break;
                case 3: v6 = v7 | v0.value; break;
                case 0: v6 = v7 & v0.value; break;
                }
            }
            if (v6 != 0) ready = 1;
            else ready = 0;
        }
        if (ready) {
            fn_12_2F210(arg0, 7, 6, 0, 0);
            v0.value = 4;
        } else {
            v0.value = 3;
        }
        break;
    }
    return v0.value;
}
#pragma opt_dead_assignments reset

/* fzgx:end fn_12_2C640 */

/* fzgx:begin fn_12_2C9C4 noprologue */
#include "types.h"
#include "sofdec/sfd.h"

/* sfply_ExecOne, from the CC0 MK Deception decomp (sfd_ply.c) */

typedef struct SfplyHandle {
    u8 unknown_0000[0x44];
    int field_0044;
    int playback_state;
    int requested_state;
    u8 unknown_0050[0x9A0 - 0x50];
    int conditions_primary[64];
    u8 unknown_0AA0[0xF2C - 0xAA0];
    int timer_field_02B0;
    u8 unknown_0F30[0xF48 - 0xF30];
    int timer_field_02CC;
    u8 unknown_0F4C[0x2918 - 0xF4C];
    SfdTimerSummary timer_summaries[8];
} SfplyHandle;

extern unsigned long long fn_12_335B8(void);
extern void fn_12_2F264(SfplyHandle *handle, int kind);
extern void fn_12_2D288(SfplyHandle *handle);
extern int fn_12_2C640(SfplyHandle *handle);
extern int fn_12_2C0F8(SfplyHandle *handle);
extern int fn_12_2F1D0(SfplyHandle *handle, int kind);
extern int fn_12_2D73C(SfplyHandle *handle, int id);
extern void fn_12_2F210(SfplyHandle *handle, int a, int b, int c, int d);

static inline int sfply_IsTermAll(SfplyHandle *handle)
{
    int video_terminated;
    int audio_terminated;
    int terminated;

    if (handle->conditions_primary[6] == 0 &&
        handle->conditions_primary[5] == 0) return 1;
    terminated = 0;
    video_terminated = fn_12_2F1D0(handle, 6);
    audio_terminated = fn_12_2F1D0(handle, 7);
    switch (fn_12_2D73C(handle, 0x19)) {
    case 1: terminated = audio_terminated; break;
    case 2: terminated = video_terminated; break;
    case 3: terminated = audio_terminated | video_terminated; break;
    case 0: terminated = audio_terminated & video_terminated; break;
    }
    return terminated;
}

static inline int sfply_IsStartable(SfplyHandle *handle)
{
    if (handle->conditions_primary[14] == 0) return 1;
    if (handle->conditions_primary[5] == 0) return 1;
    if (handle->timer_field_02B0 != 0) return 1;
    if (handle->timer_field_02CC >= handle->conditions_primary[45]) return 1;
    if (sfply_IsTermAll(handle) != 0) return 1;
    return 0;
}

static inline int sfply_StatStby(SfplyHandle *handle, int state)
{
    switch (handle->requested_state) {
    case 2:
        state = 2;
        break;
    case 3:
        state = 3;
        break;
    case 4:
    case 6:
        if (sfply_IsStartable(handle) != 0) {
            fn_12_2F210(handle, 7, 6, 0, 0);
            state = 4;
        }
        break;
    }
    return state;
}

void fn_12_2C9C4(SfplyHandle *handle)
{
    int state;
    unsigned long long start;

    state = handle->playback_state;
    if ((unsigned int)(state - 1) > 3) {
        return;
    }
    if (handle->field_0044 == 0) {
        return;
    }
    handle->field_0044 = 0;
    start = fn_12_335B8();
    if ((unsigned int)(state - 2) <= 1 || state == 4) {
        fn_12_2F264(handle, 2);
        fn_12_2D288(handle);
    }

    state = handle->playback_state;
    switch (state) {
    case 0:
        break;
    case 1:
        switch (handle->requested_state) {
        case 2:
        case 3:
        case 4:
        case 6:
            state = 2;
            break;
        }
        break;
    case 2:
        state = fn_12_2C640(handle);
        break;
    case 3:
        state = sfply_StatStby(handle, state);
        break;
    case 4:
        state = fn_12_2C0F8(handle);
        break;
    case 5:
        state = handle->playback_state;
        break;
    case 6:
        state = handle->playback_state;
        break;
    }
    handle->playback_state = state;
    SFTMR_AddTsum(&handle->timer_summaries[5], fn_12_335B8() - start);
}
/* fzgx:end fn_12_2C9C4 */

/* fzgx:begin fn_12_2CC24 noprologue */
#include "types.h"
#include "sofdec/sfd.h"


/* --- rel/movie_module/fn_12_2CC24.c --- */
typedef struct MovieModuleState {
    u8 _pad_0[0x44];
    u32 field_44;
} MovieModuleState;

extern int fn_12_24990(MovieModuleState *state);
extern int fn_12_24A88(int arg0, u32 arg1);
extern void fn_12_2C9C4(MovieModuleState *state);

int fn_12_2CC24(MovieModuleState *state) {
    if (fn_12_24990(state)) {
        return fn_12_24A88(0, 0xFF000138);
    }
    state->field_44 = 1;
    fn_12_2C9C4(state);
    return 0;
}
/* fzgx:end fn_12_2CC24 */

/* fzgx:begin SFD_IsSvrWait noprologue */

/* --- rel/movie_module/SFD_IsSvrWait.c --- */
extern SfdLibraryWork lbl_12_bss_7C64;



int SFD_IsSvrWait(void) {
    SfdHandle **handles = lbl_12_bss_7C64.handles;
    int i;
    int waiting;
    SfdHandle *handle;
    for (i = 0; i < 8; i++) {
        handle = *handles;
        if (handle != 0) {
            if ((unsigned int)(handle->playback_state - 1) > 3) {
                waiting = 1;
            } else if (handle->field_0044 != 0) {
                waiting = 0;
            } else {
                waiting = 1;
            }
            if (waiting == 0) {
                return 0;
            }
        }
        handles++;
    }
    return 1;
}
/* fzgx:end SFD_IsSvrWait */

/* fzgx:begin fn_12_2CD44 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_2CD44.c --- */
/* --- rel/movie_module/fn_12_2CD44.c --- */
typedef struct MovieModuleState {
    u8 _pad_0[0x44];
    u32 field_44;
    u32 field_48;
} MovieModuleState;

u32 fn_12_2CD44(MovieModuleState *state) {
    if (state->field_48 - 1 > 3) {
        return 1;
    }
    return state->field_44 == 0;
}
/* fzgx:end fn_12_2CD44 */

/* fzgx:begin fn_12_2CD6C noprologue */

/* --- rel/movie_module/fn_12_2CD6C.c --- */
extern void fn_12_2EBAC(void);

void fn_12_2CD6C(void) {
    fn_12_2EBAC();
}
#undef v12

/* fzgx:end fn_12_2CD6C */
