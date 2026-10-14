/* Non-matching: best partial attempt (65.19% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Sig_p1 {
    u8 unk_0[0x88];
    u32 unk_88;
    u32 unk_8C;
};

struct Obj_7AC48 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0x38];
    u8 unk_48;
    u8 unk_49;
    u8 unk_4A;
    u8 pad_4B;
    f32 unk_4C;
    f32 unk_50;
};

struct Obj_3D138 {
    u8 pad_0[0xF8];
    u32 unk_F8;
    u8 pad_FC[0x10];
    u8 unk_10C[0x24];
    u8 unk_130[0x100];
};

struct Obj_rodata_5168 {
    u8 pad_0[0x67C];
    f32 unk_67C;
    f64 unk_680;
    u8 pad_688[0x60];
    f64 unk_6E8;
    f64 unk_6F0;
};

struct Obj_9F8 {
    u8 pad_0[0x1C];
    u16 unk_1C;
};

typedef u32 file_handle_t;
typedef struct { u32 v; } FModeWord;
typedef struct {
    u32 io_state : 3;
    u32 free_buffer : 1;
    u8 eof;
    u8 error;
} FState;
typedef struct {
    file_handle_t handle;
    FModeWord mode;
    FState state;
    u8 is_dynamically_allocated;
    u8 char_buffer;
    u8 char_buffer_overflow;
    u8 ungetc_buffer[2];
    u16 ungetc_wide_buffer[2];
    u32 position;
    u8 *buffer;
    u32 buffer_size;
    u8 *buffer_ptr;
    u32 buffer_length;
    u32 buffer_alignment;
    u32 saved_buffer_length;
    u32 buffer_position;
    void *position_proc;
    void *read_proc;
    void *write_proc;
    void *close_proc;
    void *idle_proc;
    struct FFile *next_file;
} FFile;

extern struct Obj_7AC48 lbl_1_bss_7AC48;
extern struct Obj_3D138 lbl_1_data_3D138;
extern struct Obj_rodata_5168 lbl_1_rodata_5168;
extern struct Obj_9F8 lbl_1_bss_9F8;
extern s32 fn_1_3F164(void);
extern s8 fn_1_86624(void);
extern struct Sig_p1 * fn_1_8627C(s32);
extern f32 fn_1_8CAF4(u32, u32);
extern f32 fn_1_8CA70(u32, u32);
extern void * fn_1_86254(int);
extern u8 fn_1_8C3EC(void);
extern u8 fn_1_8C3FC(void);
extern f32 fn_1_8C40C(void);
extern f32 fn_1_8C44C(void);
extern u8 fn_1_8DB94(void);
extern void fn_80008BEC(void *, int, u32);
extern int sprintf(char *, const char *, ...);
extern FFile * fopen(const char *, const char *);
extern u32 fwrite(const void *, u32, u32, u32);
extern int fflush(FFile *);
extern int fclose(FFile *);

void fn_1_C42F4(u32 arg0) {
    u8 *buf;
    s32 num;
    s32 idx;
    s32 jdx;
    u32 wid;
    u32 eoff;
    u32 val;
    u32 mob;
    FFile *filep;
    char name[0x88];
    struct Sig_p1 *ptr1;
    struct Sig_p1 *ptr2;

    if (lbl_1_bss_7AC48.unk_48 != 0 && fn_1_3F164() == 0) {
        num = fn_1_86624();
        fn_80008BEC(*(void **)&lbl_1_bss_7AC48.unk_8, 0, 0x1e0);
        buf = (u8 *)lbl_1_bss_7AC48.unk_8;
        eoff = 0;
        for (idx = 0; idx < num; idx++) {
            ptr1 = fn_1_8627C(idx);
            jdx = idx + 1;
            wid = jdx << 2;
            *(u8 *)(buf + 0x1e0 + idx) = ptr1->unk_8C;
            for (jdx = idx + 1; jdx < num; jdx++) {
                f32 alpha = fn_1_8CAF4(idx, jdx);
                f32 bravo = fn_1_8CA70(idx, jdx);
                if (fabsf(alpha) < lbl_1_rodata_5168.unk_6E8) {
                    if (alpha < lbl_1_rodata_5168.unk_680) {
                        *(u32 *)(buf + 0x78 + eoff) |= 0x80000000 >> jdx;
                        *(u32 *)(buf + wid) |= 0x80000000 >> idx;
                    } else {
                        *(u32 *)(buf + wid + 0x78) |= 0x80000000 >> idx;
                        *(u32 *)(buf + eoff) |= 0x80000000 >> jdx;
                    }
                }
                if (fabsf(bravo) < lbl_1_rodata_5168.unk_6F0) {
                    if (bravo < lbl_1_rodata_5168.unk_67C) {
                        *(u32 *)(buf + 0xf0 + eoff) |= 0x80000000 >> jdx;
                        *(u32 *)(buf + wid + 0x168) |= 0x80000000 >> idx;
                    } else {
                        *(u32 *)(buf + wid + 0xf0) |= 0x80000000 >> idx;
                        *(u32 *)(buf + 0x168 + eoff) |= 0x80000000 >> jdx;
                    }
                }
                wid += 4;
            }
            eoff += 4;
        }
        val = arg0;
        for (idx = 0; idx < num; idx++) {
            if (*(u32 *)(val + 0) & 0x04000000) {
                mob = *(u32 *)(val + 0x484);
                if (*(u32 *)mob & 0x10000000) {
                    --*(u8 *)(mob + 0x2e);
                    if (*(u8 *)(mob + 0x2e) != 0) {
                        if (*(u8 *)(mob + 0x2e) < 0x78) {
                            u32 rnd = lbl_1_data_3D138.unk_F8;
                            rnd = rnd * 0x41c64e6d + 0x3039;
                            lbl_1_data_3D138.unk_F8 = rnd;
                            if (((rnd >> 1) & 0x7fff) < 0x111) {
                                *(u32 *)mob &= ~0x18000000;
                                *(u8 *)(mob + 0x2e) = 0;
                            }
                        }
                    } else {
                        *(u32 *)mob &= ~0x18000000;
                        *(u8 *)(mob + 0x2e) = 0;
                    }
                }
                if (*(u8 *)(mob + 0x3a) != 0) {
                    --*(u8 *)(mob + 0x3a);
                }
                ptr2 = fn_1_8627C(idx);
                if (*(u8 *)(mob + 0x34) != 0xff) {
                    *(u8 *)(buf + idx + 0x1fe) = 0;
                    *(u32 *)mob &= ~0x00010000;
                    if (*(u8 *)(mob + 0x33) == 0xff) {
                        *(u8 *)(mob + 0x33) = *(u8 *)(mob + 0x31);
                    }
                    *(u8 *)(mob + 0x31) = *(u8 *)(mob + 0x34);
                    *(u8 *)(mob + 0x34) = 0xff;
                } else if ((s32)ptr2->unk_88 > 1) {
                    if ((s32)ptr2->unk_8C != (s32)(*(u8 *)(mob + 0x31) % (ptr2->unk_88 - 1)) + 1) {
                        u32 *slot = (u32 *)fn_1_86254(idx);
                        *(u8 *)(buf + idx + 0x1fe) += 1;
                        *(u32 *)mob |= 0x00010000;
                        if (*(u8 *)(buf + idx + 0x1fe) > 0x3c || (*slot & 2) || !(*slot & 0x800000)) {
                            *(u8 *)(buf + idx + 0x1fe) = 0;
                            *(u32 *)mob &= ~0x00010000;
                            if (*(u8 *)(mob + 0x33) == 0xff) {
                                *(u8 *)(mob + 0x33) = *(u8 *)(mob + 0x31);
                            } else if (*(u8 *)(mob + 0x33) == (u8)(ptr2->unk_8C - 1)) {
                                *(u8 *)(mob + 0x33) = 0xff;
                            }
                            *(u8 *)(mob + 0x31) = (u8)(ptr2->unk_8C - 1);
                        }
                    }
                } else if (!(*(u32 *)mob & 0x02000000)) {
                    *(u8 *)(buf + idx + 0x1fe) = 0;
                    *(u32 *)mob &= ~0x00010000;
                    if (*(u8 *)(mob + 0x33) != 0xff && (s32)ptr2->unk_88 == 1) {
                        *(u8 *)(mob + 0x31) = *(u8 *)(mob + 0x33);
                        *(u8 *)(mob + 0x33) = 0xff;
                    }
                }
            }
            val += 0x620;
        }
        lbl_1_bss_7AC48.unk_49 = fn_1_8C3EC();
        lbl_1_bss_7AC48.unk_4A = fn_1_8C3FC();
        lbl_1_bss_7AC48.unk_4C = fn_1_8C40C();
        lbl_1_bss_7AC48.unk_50 = fn_1_8C44C();
        if (fn_1_8DB94() != 0 && (lbl_1_bss_9F8.unk_1C & 0x8000) != 0) {
            sprintf(name, (char *)&lbl_1_data_3D138.unk_10C, *(u8 *)&lbl_1_bss_7AC48.unk_8 + 1);
            filep = fopen(name, (char *)&lbl_1_data_3D138.unk_130);
            if (filep != 0) {
                fwrite((void *)lbl_1_bss_7AC48.unk_C, 0x800, 1, (u32)filep);
                fflush(filep);
                fclose(filep);
            }
        }
    }
}
