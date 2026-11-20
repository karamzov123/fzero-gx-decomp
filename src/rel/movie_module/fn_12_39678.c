#include "types.h"


/* --- rel/movie_module/fn_12_39678.c --- */
struct fn_12_39678_Arg0 {
    u8 pad_0[8];
    s32 status;
    s32 file_type;
    u8 pad_10[0x30];
    u32 unk_40;
    void *stream;
    u8 pad_48[0x29];
    s8 stopped;
    s8 paused;
    u8 pad_73[9];
    s32 field_7c;
    s32 field_80;
    s32 field_84;
    u8 pad_88[0x88];
    char *filename;
    s32 capacity;
    s32 requested;
    s32 offset;
    s32 length;
    s32 end;
    u32 unk_128;
    u32 unk_12C;
    u8 pad_130[0xbc];
    u8 sound[0x18];
};
extern char lbl_12_rodata_2480[];
extern void fn_12_3A888(void *);
extern s32 fn_12_2B358(u32);
extern s32 fn_12_38A0C(s32);
extern void MWSFSVM_Error(const char *, ...);
extern void fn_12_3B540(void *);
extern void fn_12_34EB0(void *);
extern u32 *fn_12_38DBC(void);
extern s32 MWSFCRE_ResetSfdHn(void *);
extern void fn_12_3B2EC(void *);
extern void fn_12_33A14(void *);
extern void fn_12_353C4(void *);
extern s32 fn_12_35418(void *);
extern void fn_12_353FC(void *);
extern s32 fn_12_2AD88(u32);
extern s32 fn_12_3A36C(void *);
extern s32 fn_12_38AD0(void);
extern s32 fn_12_2D74C(u32, s32, u32 *);
extern s32 fn_12_2AF5C(u32, s32);
extern void MWSST_Pause(void *, s32);
extern void MWSST_StartSj(void *);
extern void fn_12_35014(void *, s32, s32);
extern void fn_12_35010(void *, s32, s32);
extern u32 strlen(const char *);
extern char *strncpy(char *, const char *, u32);
extern char *fn_80083DB0(char *, const char *);

void fn_12_39678(struct fn_12_39678_Arg0 *arg0, void *arg1, s32 arg2, s32 arg3) {
    char *p_lbl_12_rodata_2480 = lbl_12_rodata_2480;
    u32 v0;
    s32 v2;
    u32 loc_8;
    s32 tmp_ra3;
    arg0->unk_128 = arg0->unk_12C;
    v0 = arg0->unk_40;
    if (v0 != 0) {
        fn_12_3A888(arg0);
        arg0->status = 0;
        if (fn_12_2B358(v0) != 0) {
            fn_12_38A0C(-0x134);
            MWSFSVM_Error(p_lbl_12_rodata_2480 + 0x100);
        }
        fn_12_3B540(arg0->sound);
        if (arg0->stream != 0) fn_12_34EB0(arg0->stream);
    }
    fn_12_38DBC();
    if (arg0->unk_40 != 0) {
        if (MWSFCRE_ResetSfdHn(arg0) != 0) {
            MWSFSVM_Error(p_lbl_12_rodata_2480 + 0x14c);
            goto finish; /* Keep the verified branch to finish. */
        }
        fn_12_3B2EC(arg0);
        fn_12_33A14(arg0);
        fn_12_353C4(arg0);
        if (fn_12_35418(arg0) != 0) {
            MWSFSVM_Error(p_lbl_12_rodata_2480 + 0x178);
            goto finish; /* Keep the verified branch to finish. */
        }
        fn_12_353FC(arg0);
    }
    arg0->field_7c = 0;
    arg0->field_80 = 0;
    if (fn_12_2AD88(arg0->unk_40) != 0) {
        fn_12_38A0C(-0x137);
        MWSFSVM_Error(p_lbl_12_rodata_2480 + 0x1a4);
    }
    v2 = arg0->paused;
    if (fn_12_3A36C(arg0) == 0) {
        MWSFSVM_Error(p_lbl_12_rodata_2480 + 0x84);
    } else {
        v0 = arg0->unk_40;
        tmp_ra3 = arg0->paused;
        if (tmp_ra3 != 0 || v2 != 0) {
            if (fn_12_38AD0() == 1 && arg0->file_type == 1) {
                if (fn_12_2D74C(v0, 6, &loc_8) == 0) {
                    if ((s32)loc_8 == 1) fn_12_3A888(arg0);
                } else {
                    fn_12_3A888(arg0);
                }
            }
            if (fn_12_2AF5C(v0, v2) != 0) {
                fn_12_38A0C(-0x136);
                {
                    char *format = p_lbl_12_rodata_2480 + 0xac;
                    char *state = p_lbl_12_rodata_2480 + 0xd4;
                    if (v2 == 1) state = p_lbl_12_rodata_2480 + 0xd0;
                    MWSFSVM_Error(format, state);
                }
            }
            MWSST_Pause(arg0->sound, v2);
            arg0->paused = v2;
        }
    }
    MWSST_Pause(arg0->sound, 1);
    MWSST_StartSj(arg0->sound);
    arg0->field_84 = 0;
    arg0->stopped = 0;
    arg0->status = 1;
finish:
    if ((s32)strlen(arg1) > arg0->capacity) {
        MWSFSVM_Error(p_lbl_12_rodata_2480 + 0x28);
        strncpy(arg0->filename, arg1, arg0->capacity);
    } else {
        fn_80083DB0(arg0->filename, arg1);
    }
    arg0->offset = 0;
    arg0->length = 0;
    arg0->end = 0xfffff;
    arg0->requested = 1;
    fn_12_35014(arg0, arg2, arg3);
    fn_12_35010(arg0, arg2, arg3);
}

/* --- rel/movie_module/fn_12_39930.c --- */
/* --- rel/movie_module/fn_12_39930.c --- */
extern char lbl_12_rodata_2670[46];
extern char lbl_12_rodata_26A0[41];

void fn_12_39930(void *object, void *argument) {
    if (fn_12_3A36C(object) == 0) {
        MWSFSVM_Error(lbl_12_rodata_2670);
    } else if (argument == 0) {
        MWSFSVM_Error(lbl_12_rodata_26A0);
    } else {
        fn_12_39678(object, argument, 0, -1);
    }
}

/* --- rel/movie_module/fn_12_399B4.c --- */
typedef struct Fn12_399B4_Object {
    u8 _pad[0x40];
    u32 value;
} Fn12_399B4_Object;

extern s32 fn_12_2B138(u32 value);
extern char lbl_12_rodata_26CC[46];

s32 fn_12_399B4(Fn12_399B4_Object *object) {
    s32 result = fn_12_2B138(object->value);

    switch (result) {
    case 1:
        return 1;
    case 0:
        return 0;
    default:
        MWSFSVM_Error(lbl_12_rodata_26CC, result);
        return 0;
    }
}

/* --- rel/movie_module/fn_12_39A18.c --- */
typedef struct Fn12_39A18_Object {
    u8 unk0[0x40];
    u32 unk40;
} Fn12_39A18_Object;

extern s32 fn_12_2B634(u32 value);
extern const char lbl_12_rodata_26FC[27];

s32 fn_12_39A18(Fn12_39A18_Object *object) {
    if (fn_12_2B634(object->unk40) != 0) {
        fn_12_38A0C(-0x133);
        MWSFSVM_Error(lbl_12_rodata_26FC);
        return -0x133;
    }
    return 0;
}
