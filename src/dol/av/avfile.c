#include "types.h"

typedef u32 (*fn_80006D1C_Fn0)(u32, u32, u32, u32);

struct AvFileHandle {
    u32 unk_0;
    u8 pad_4[0x30];
    void *unk_34;
    u32 unk_38;
};

extern u32 DVDReadPrio(u32, u32, u32, u32, u32);
extern u32 DVDOpen(u32, u32);
extern u32 DVDFastOpen(u32, u32);
extern u32 DVDClose(u32);
extern u32 DVDReadAsyncPrio(u32, u32, u32, u32, u32, u32);
extern BOOL DVDChangeDir(char *);
extern s32 DVDConvertPathToEntrynum(const char *);
extern void OSPanic(const char *, int, const char *, ...);
extern char *strcpy(void *, const void *);
extern size_t strlen(const char *);
extern s32 strncmp(const char *, const char *, size_t);
extern char *strcat(char *, const char *);
extern u32 strncpy(u32, u32, u32);
extern int strcmp(const char *, const char *);

extern char lbl_801220C0[];
extern u32 lbl_801220CC[];
extern u32 lbl_801220E0[];
extern u32 lbl_801220F0[];
extern u32 lbl_80122104[];
extern u8 lbl_8015BD40[256];
extern char lbl_801A63F8[2];
extern char lbl_801A63FC[3];
extern u32 lbl_801A66F8;
extern u32 lbl_801A66FC;
extern char **lbl_801A6700;
extern u32 lbl_801A6704;
extern u32 lbl_801A6708;

void fn_80006BDC(const char *fmt, ...);
u32 fn_80006C4C(s32 arg0, u32 arg1);

void fn_80006B4C(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    DVDReadPrio(arg0, arg1, arg2, arg3, 2);
}

void fn_80006B70(u32 arg0, u32 arg1) {
    fn_80006BDC(lbl_801220C0, arg0);
    fn_80006BDC((const char *)&lbl_801220CC);
    *(u32 *)((u8 *)arg1 + 0) = 0;
    DVDOpen(arg0, (arg1 + 4));
}

void fn_80006BDC(const char *fmt, ...) {
}

u32 fn_80006C2C(s32 arg0, u32 arg1) {
    return fn_80006C4C(arg0, arg1);
}

u32 fn_80006C4C(s32 arg0, u32 arg1) {
    u32 result = 0;

    if (arg0 < 0) {
        return 0;
    }

    fn_80006BDC((const char *)&lbl_801220E0, arg0);
    if ((arg0 & 0x7fff0000) == 0) {
        fn_80006BDC((const char *)&lbl_801220CC);
        result = DVDFastOpen(arg0, arg1 + 4);
        if (result != 0) {
            *(u32 *)arg1 = 0;
        }
    }

    return result;
}

u32 fn_80006CE4(struct AvFileHandle *arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 t0;
    v0 = (u32)arg0;
    v1 = arg1;
    if ((s32)arg0->unk_0 != 1) {
        v0 += 4;
        t0 = DVDClose(v0);
        v0 = t0;
        v1 = v0;
    }
    v0 = v1;
    return v0;
}

u32 fn_80006D1C(struct AvFileHandle *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 t1;
    v0 = (u32)arg0;
    v1 = arg1;
    v2 = arg2;
    v3 = arg3;
    if ((s32)arg0->unk_0 != 1) {
        v0 = (u32)&lbl_801220F0;
        fn_80006BDC((const char *)v0, v1);
        v1 = arg1;
        v2 = arg2;
        v3 = arg3;
        v0 = ((u32)arg0 + 4);
        t1 = ((fn_80006D1C_Fn0)lbl_801A6708)(v0, v1, v2, v3);
        v0 = t1;
        v4 = v0;
    }
    fn_80006BDC((const char *)&lbl_80122104, v4);
    return v4;
}

u32 fn_80006DAC(struct AvFileHandle *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    u32 v0;
    u32 v1;
    u32 t0;
    v0 = (u32)arg0;
    v1 = arg5;
    if ((s32)arg0->unk_0 != 1) {
        v0 += 4;
        v1 = 2;
        t0 = DVDReadAsyncPrio(v0, arg1, arg2, arg3, arg4, v1);
        v0 = t0;
        v1 = v0;
    }
    v0 = v1;
    return v0;
}

u32 fn_80006DE8(struct AvFileHandle *arg0) {
    if ((s32)arg0->unk_0 == 1) {
        return (u32)arg0;
    }
    return arg0->unk_38;
}

void *fn_80006DFC(struct AvFileHandle *object) {
    if ((s32)object->unk_0 != 1) {
        object = object->unk_34;
    }
    return object;
}

void fn_80006E10(const char *path) {
    u8 *p_lbl_8015BD40;
    u8 *v0;
    s32 v2;

    v0 = (u8 *)path;
    DVDChangeDir((char *)path);
    p_lbl_8015BD40 = lbl_8015BD40;
    while (*v0 != 0) {
        if (*v0 == '/') {
            for (v2 = 1; v2 < strlen((const char *)v0) + 1; v2++) {
                if (v0[v2] != '/') {
                    strcpy(lbl_8015BD40, &v0[v2 - 1]);
                    v0 += v2;
                    break;
                }
            }
        } else if (strncmp((const char *)v0, lbl_801A63FC, 2) == 0) {
            for (v2 = strlen((const char *)lbl_8015BD40) - 1; v2 >= 0; v2--) {
                if (lbl_8015BD40[v2] == '/') {
                    lbl_8015BD40[v2] = 0;
                    v0 += 2;
                    break;
                }
            }
            if (lbl_8015BD40[0] == 0) {
                strcpy(lbl_8015BD40, lbl_801A63F8);
            }
        } else {
            if (lbl_8015BD40[0] != '/' || p_lbl_8015BD40[1] != 0) {
                strcat((char *)lbl_8015BD40, lbl_801A63F8);
            }
            strcat((char *)lbl_8015BD40, (const char *)v0);
            v0 += strlen((const char *)v0);
        }
        if (p_lbl_8015BD40[0] != '/' || p_lbl_8015BD40[1] != 0) {
            v2 = strlen((const char *)lbl_8015BD40) - 1;
            if (lbl_8015BD40[v2] == '/') {
                lbl_8015BD40[v2] = 0;
            }
        }
    }
}

void fn_80006FE0(u32 arg0, u32 arg1) {
    strncpy(arg0, (u32)&lbl_8015BD40, arg1);
}

s32 fn_8000700C(const char *path) {
    char *str;
    char buf[0x88];
    s32 result;
    s32 i;

    str = lbl_801220C0;
    if (lbl_801A66F8 == 0) {
        result = DVDConvertPathToEntrynum(path);
    } else {
        if (lbl_801A6704 == 0) {
            OSPanic(str + 0x58, 749, str + 0x80);
        }
        if (path[0] == '/') {
            for (i = 1; i < strlen(path) + 1; i++) {
                if (path[i] != '/') {
                    strcpy(buf, &path[i - 1]);
                    break;
                }
            }
        } else {
            strcpy(buf, (const char *)lbl_8015BD40);
            if (lbl_8015BD40[0] != '/' || lbl_8015BD40[1] != 0) {
                strcat(buf, lbl_801A63F8);
            }
            strcat(buf, path);
        }
        fn_80006BDC(str + 0xa0, path);
        fn_80006BDC(str + 0xb0, lbl_8015BD40);
        fn_80006BDC(str + 0xc0, buf);
        i = 0;
        result = -1;
        for (; i < (s32)lbl_801A66FC; i++) {
            if (strcmp(lbl_801A6700[i], buf) == 0) {
                result = i | 0x7FFF0000;
                break;
            }
        }
        fn_80006BDC(str + 0xd0, buf, result | 0x7FFF0000);
    }
    return result;
}
