#include "types.h"

typedef struct SJ SJ;
typedef struct ADXStream ADXStream;

typedef struct LSCStreamInfo {
    s32 id;
    const char *filename;
    u32 filename_checksum;
    void *directory;
    s32 offset;
    s32 sector_count;
    s32 state;
    s32 read_sectors;
} LSCStreamInfo;

typedef struct LSCObject {
    s8 used;
    s8 state;
    s8 reading;
    s8 loop;
    s8 paused;
    u8 reserved_05[3];
    SJ *sj;
    s32 reserved_0C;
    s32 reserved_10;
    s32 minimum_buffer_size;
    s32 buffer_size;
    s32 write_position;
    s32 read_position;
    s32 stream_count;
    ADXStream *stream;
    s32 file_sectors;
    s32 reserved_30;
    s32 reserved_34;
    LSCStreamInfo stream_info[16];
} LSCObject;

extern u32 lbl_80188A88[];
extern LSCObject lbl_80188A8C[16];
/* read through a volatile lvalue so the access is not optimised away */
extern volatile u32 lbl_800922C0[];
extern s32 lbl_8018AE10[];
extern s32 lbl_8018AE14[];

extern void fn_80056710(void *);
extern void fn_80057114(void *);
extern void *memset(void *, int, u32);
extern void fn_800566BC(int, int);
extern void fn_800566F0();
extern void fn_800565FC(const char *format, ...);
extern void fn_8005676C(void);
extern s32 fn_80056E9C(LSCObject *lsc, const char *filename, void *directory, s32 offset, s32 sector_count);
extern s32 fn_8004AEE4(ADXStream *stream);
extern s32 fn_8004AE78(ADXStream *stream);
extern void fn_8004AD84(ADXStream *stream);
extern void fn_8004B0EC(ADXStream *stream);
extern void fn_8004B180(ADXStream *stream, const char *filename, void *directory, s32 offset, s32 sector_count);
extern void fn_8004AC04(ADXStream *stream, s32 sector_count);
extern s32 fn_8004A550(ADXStream *stream, s32 minimum_size, s32 buffer_size);
extern void fn_8004AE94(ADXStream *stream, s32 position);
extern void fn_8004ADF4(ADXStream *stream);
extern u32 OSRestoreInterrupts(u32);
extern u32 OSDisableInterrupts(void);

#pragma use_lmw_stmw off
void fn_80057378(void) {
    u8 local[16];
    int i;

    fn_80056710(local);
    if (--lbl_80188A88[0] == 0) {
        i = 0;
        do {
            if (lbl_80188A8C[i].used == 1) {
                fn_80057114(&lbl_80188A8C[i]);
            }
            i++;
        } while (i < 0x10);
        memset(lbl_80188A8C, 0, 0x2380);
        fn_800566BC(0, 0);
    }
    fn_800566F0(local);
}
#pragma use_lmw_stmw on

void fn_8005741C(void) {
    f64 loc_8[1];
    u32 value;

    (void)lbl_800922C0[0];
    fn_80056710((u32 *)&loc_8);
    if ((s32)lbl_80188A88[0] == 0) {
        memset(&lbl_80188A8C, 0, 0x2380);
        fn_800566BC(0, 0);
    }
    value = lbl_80188A88[0];
    lbl_80188A88[0] = value + 1;
    fn_800566F0((u32 *)&loc_8, value, lbl_80188A88);
}
