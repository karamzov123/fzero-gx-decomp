#include "types.h"

typedef struct fn_12_68D4_MovieValues {
    u32 value_00;
    u32 value_04;
    u32 value_08;
    u32 value_0c;
    u32 value_10;
    u32 value_14;
    u32 value_18;
    u32 value_1c;
} fn_12_68D4_MovieValues;

typedef struct fn_12_68D4_MovieModule {
    u8 _pad00[0x20];
    fn_12_68D4_MovieValues values;
} fn_12_68D4_MovieModule;

typedef struct fn_12_696C_MovieValues {
    u32 value_00;
    u32 value_04;
    u32 value_08;
    u32 value_0c;
    u32 value_10;
    u32 value_14;
    u32 value_18;
    u32 value_1c;
} fn_12_696C_MovieValues;

typedef struct fn_12_696C_MovieModule {
    u8 _pad00[0x40];
    fn_12_696C_MovieValues values[1];
} fn_12_696C_MovieModule;

typedef struct fn_12_6A18_MovieValues {
    u32 value_14;
    u32 value_18;
    u32 value_1c;
} fn_12_6A18_MovieValues;

typedef struct fn_12_6A18_MovieModule {
    u8 pad[0x14];
    fn_12_6A18_MovieValues values;
} fn_12_6A18_MovieModule;
extern s32 fn_12_6C78(u32 arg0);
extern int fn_12_6D5C(int arg0, int arg1);

/* fzgx:begin fn_12_68D4 */



int fn_12_68D4(fn_12_68D4_MovieModule *module, fn_12_68D4_MovieValues *result) {
    if (fn_12_6C78( (u32)(fn_12_68D4_MovieModule *)(module))) {
        return fn_12_6D5C(0, 0xff020202);
    }
    *result = module->values;
    return 0;
}
/* fzgx:end fn_12_68D4 */

/* fzgx:begin fn_12_696C */



int fn_12_696C(fn_12_696C_MovieModule *module, fn_12_696C_MovieValues *result, int index) {
    if (fn_12_6C78( (u32)(fn_12_696C_MovieModule *)(module))) {
        return fn_12_6D5C(0, 0xff020202);
    }
    *result = module->values[index];
    return 0;
}
/* fzgx:end fn_12_696C */

/* fzgx:begin fn_12_6A18 */
/* --- rel/movie_module/fn_12_6A18.c --- */
/* --- rel/movie_module/fn_12_6A18.c --- */



int fn_12_6A18(fn_12_6A18_MovieModule *module, fn_12_6A18_MovieValues *result) {
    if (fn_12_6C78( (u32)(fn_12_6A18_MovieModule *)(module))) {
        return fn_12_6D5C(0, 0xff020201);
    }
    *result = module->values;
    return 0;
}
/* fzgx:end fn_12_6A18 */

/* fzgx:begin fn_12_6A88 */
/* --- rel/movie_module/fn_12_6A88.c --- */
// fn_12_6A88: empty in retail (single blr).
void fn_12_6A88(void) {
}
/* fzgx:end fn_12_6A88 */

/* fzgx:begin fn_12_6A8C */
/* --- rel/movie_module/fn_12_6A8C.c --- */
// fn_12_6A8C: empty in retail (single blr).
void fn_12_6A8C(void) {
}
/* fzgx:end fn_12_6A8C */
