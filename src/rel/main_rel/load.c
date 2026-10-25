#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/load.h"

extern u32 lbl_1_bss_3DCE4[17];
extern void *fn_80006DFC(void *arg);
extern void fn_1_D3214(void);
extern s32 fn_8000700C(s32 arg0);
extern void fn_1_3BDC(s32 arg0);
extern void fn_8000659C(void);
extern u32 lbl_1_bss_384C4;
extern void fn_1_46A8C(u32 value);
extern u32 lbl_1_bss_3DCD8;
extern u32 lbl_1_bss_3DD28[179];
extern void fn_1_47EE4(s32);
extern void fn_1_485C8(s32);
extern void fn_1_48140(s32 value);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);

extern u8 lbl_1_bss_3E024[52];
extern char lbl_1_data_1A3AC[5];
extern void fn_80083DB0(void *arg0, void *arg1);
extern u32 fn_80006CE4(u32);
extern void *fn_80006DE8(void *);
extern u32 lbl_801A6410;
extern void *fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, u32 arg3);
extern void *fn_1_46B4(u32 arg0, void *arg1, u8 *arg2, u32 arg3);
extern void strcat(void *arg0, void *arg1);
extern void fn_1_48004(s32 value, s32 arg);

/* fzgx:begin fn_1_45730 noprologue */
#include "types.h"
#include "rel/main_rel/load.h"

extern int fn_1_45E98(void *arg0, void **result);
extern int fn_8000700C(void *arg0);
extern int fn_80006C2C(int status, void *arg0);

typedef struct {
    u32 flags;
    s32 unk_4;
    u32 unk_8;
    u32 unk_C;
} LoadEntry;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
    LoadEntry entry;
} LoadResult;

int fn_1_45730(void *arg0, LoadResult *result) {
    LoadEntry *entry;
    int status;
    int i;

    status = fn_1_45E98(arg0, (void **)&entry);
    if (status >= 0) {
        result->unk_0 = 1;
        result->entry = *entry;
        return 1;
    }

    if (status < 0) {
        status = fn_8000700C(arg0);
    }
    if (status < 0) {
        return 0;
    }

    entry = (LoadEntry *)&lbl_1_bss_384D8;
    for (i = 0; i < 0x400; i++) {
        if ((entry->flags & 0x40000000) != 0 &&
            (entry->flags & 0x08000000) == 0 &&
            entry->unk_4 == status) {
            result->unk_0 = 1;
            result->entry = *entry;
            return 1;
        }
        entry++;
    }

    result->unk_0 = 0;
    return fn_80006C2C(status, (u8 *)result + 4);
}
/* fzgx:end fn_1_45730 */

/* fzgx:begin fn_1_45850 */
struct fn_1_45850_Arg0 {
    u32 unk_0;
};

u32 fn_1_45850(struct fn_1_45850_Arg0 *arg0) {
    u32 v0;
    u32 t0;

    v0 = (u32)arg0;
    switch ((s32)arg0->unk_0) {
    case 1:
        v0 = 1;
        break;
    case 0:
    default:
        v0 += 4;
        t0 = fn_80006CE4(v0);
        v0 = t0;
        break;
    }
    return v0;
}
/* fzgx:end fn_1_45850 */

/* fzgx:begin fn_1_45890 */
// Clear the load-state flag before starting a new load.
void fn_1_45890(void) {
    lbl_1_bss_384D0 = 0;
}
/* fzgx:end fn_1_45890 */

/* fzgx:begin fn_1_458A0 */
typedef void (*Sig_ARQPostRequest_ARQCallback)(u32 pointerToARQRequest);
typedef struct Sig_ARQPostRequest_ARQRequest {
    struct Sig_ARQPostRequest_ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    Sig_ARQPostRequest_ARQCallback callback;
} Sig_ARQPostRequest_ARQRequest;
struct fn_1_458A0_Arg0 {
    u32 unk_0;
    u8 pad_4[0x50];
    u32 unk_54;
};
extern void ARQPostRequest(Sig_ARQPostRequest_ARQRequest *, u32, u32, u32, u32, void *, u32, Sig_ARQPostRequest_ARQCallback);
extern void DCInvalidateRange(void *, u32);
extern void fn_1_45890(void);
extern void fn_1_D3214(void);
extern int fn_1_45AD4(void);
extern u32 fn_80006D1C(void *arg0);

static inline void set_load_flag(void) {
    lbl_1_bss_384D0 = 1;
}

#pragma opt_propagation off
u32 fn_1_458A0(struct fn_1_458A0_Arg0 *arg0, void *arg1, u32 arg2, u32 arg3) {
    struct { u32 a[10]; } req;
    struct { u32 value; } len;
    struct { u32 value; } lab_t1;
    len.value = arg2;
    switch ((s32)arg0->unk_0) {
    case 1:
        set_load_flag();
        lab_t1.value = len.value;
        DCInvalidateRange(arg1, lab_t1.value);
        ARQPostRequest((Sig_ARQPostRequest_ARQRequest *)&req, 0, 1, 1, arg0->unk_54 + arg3, arg1, len.value, (Sig_ARQPostRequest_ARQCallback)fn_1_45890);
        while (fn_1_45AD4() != 0) {
            fn_1_D3214();
        }
        return len.value;
    default:
        return fn_80006D1C((u8 *)arg0 + 4);
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_458A0 */

/* fzgx:begin fn_1_45A58 noprologue */
#include "types.h"

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_384C0;
u32 lbl_1_bss_384C4;
u32 fzgx_obj_lbl_1_bss_384C8;
u32 lbl_1_bss_384CC;
u32 fzgx_obj_lbl_1_bss_384D0;
u8 lbl_1_bss_384D0__fzgx_offset_4;
u8 lbl_1_bss_384D0__fzgx_offset_5;
u16 lbl_1_bss_384D0__fzgx_offset_6;
u32 fzgx_obj_lbl_1_bss_384D8[5632];
u32 lbl_1_bss_3DCD8;
u32 fzgx_obj_lbl_1_bss_3DCDC[2];
u8 lbl_1_bss_3DCE4;
u8 lbl_1_bss_3DCE4__fzgx_offset_1;
u16 lbl_1_bss_3DCE4__fzgx_offset_2;
u32 lbl_1_bss_3DCE4__fzgx_offset_4[16];
u32 lbl_1_bss_3DD28[163];
u8 lbl_1_bss_3DD28__fzgx_offset_28C;
u8 lbl_1_bss_3DD28__fzgx_offset_28D;
u16 lbl_1_bss_3DD28__fzgx_offset_28E;
u32 lbl_1_bss_3DD28__fzgx_offset_290[15];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C0;
    s = *(u8 *)&lbl_1_bss_384C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C8;
    s = *(u8 *)&lbl_1_bss_384CC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D0;
    s = *(u8 *)&lbl_1_bss_384D0__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_384D0__fzgx_offset_5;
    s = *(u8 *)&lbl_1_bss_384D0__fzgx_offset_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D8;
    s = *(u8 *)&lbl_1_bss_3DCD8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3DCDC;
    s = *(u8 *)&lbl_1_bss_3DCE4;
    s = *(u8 *)&lbl_1_bss_3DCE4__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_3DCE4__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_3DCE4__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_3DD28;
    s = *(u8 *)&lbl_1_bss_3DD28__fzgx_offset_28C;
    s = *(u8 *)&lbl_1_bss_3DD28__fzgx_offset_28D;
    s = *(u8 *)&lbl_1_bss_3DD28__fzgx_offset_28E;
    s = *(u8 *)&lbl_1_bss_3DD28__fzgx_offset_290;
}
#pragma section code_type ".text"

typedef void (*LoadCallback)(u32);

/* arg0 is passed straight through to the slot's callback (r3 is untouched before bctrl). */
void fn_1_45A58(u32 arg0) {
    LoadCallback f;
    u8 v;
    ((u32 *)&lbl_1_bss_3DCE4)[lbl_1_bss_384D0__fzgx_offset_5] = 0;
    f = ((LoadCallback *)&lbl_1_bss_3DD28__fzgx_offset_28C)[lbl_1_bss_384D0__fzgx_offset_5];
    if (f != 0) {
        f(arg0);
    }
    lbl_1_bss_384D0__fzgx_offset_5++;
    v = lbl_1_bss_384D0__fzgx_offset_5;
    lbl_1_bss_384D0__fzgx_offset_5 = (v > 15) ? 0 : v;
}
/* fzgx:end fn_1_45A58 */

/* fzgx:begin fn_1_45AD4 */
// Reports whether loading is already active or any load slot is occupied.
int fn_1_45AD4(void) {
    s8 i;

    if ((s32)lbl_1_bss_384D0 != 0) {
        return 1;
    }

    for (i = 0; i < 16; i++) {
        if ((s32)lbl_1_bss_3DCE4[i] != 0) {
            return 1;
        }
    }

    return 0;
}
/* fzgx:end fn_1_45AD4 */

/* fzgx:begin fn_1_45B2C */
typedef struct Fn145B2CData {
    s32 kind;
    u8 pad[0x54];
    void *value;
} Fn145B2CData;

void *fn_1_45B2C(Fn145B2CData *data) {
    void *result;
    switch (data->kind) {
    case 1:
        result = data->value;
        break;
    default:
        result = fn_80006DE8(&data->kind + 1);
        break;
    }
    return result;
}
/* fzgx:end fn_1_45B2C */

/* fzgx:begin fn_1_45B68 */
typedef struct Fn45B68Object {
    s32 state;
    u8 _pad[0x50];
    void *value;
} Fn45B68Object;

void *fn_1_45B68(Fn45B68Object *obj) {
    switch (obj->state) {
    case 1:
        return obj->value;
    default:
        return fn_80006DFC((u8 *)obj + 4);
    }
}
/* fzgx:end fn_1_45B68 */

/* fzgx:begin fn_1_45BA4 */
void fn_1_45BA4(s32 value) {
    fn_1_D3214();
    lbl_1_bss_384C8 = value & (value >> 31);
}
/* fzgx:end fn_1_45BA4 */

/* fzgx:begin fn_1_45BE0 */
void fn_1_45BE0(void) {
    lbl_1_bss_384C8 = 0;
}
/* fzgx:end fn_1_45BE0 */

/* fzgx:begin fn_1_45BF0 */
extern u32 lbl_1_bss_3DCE4[17];
extern void *fn_80006DFC(void *arg);
extern void fn_1_D3214(void);
extern s32 fn_8000700C(s32 arg0);
extern void fn_1_3BDC(s32 arg0);
extern void fn_8000659C(void);
extern u32 lbl_1_bss_384C4;
extern void fn_1_46A8C(u32 value);
extern u32 lbl_1_bss_3DCD8;
extern u32 lbl_1_bss_3DD28[179];
extern void fn_1_47EE4(s32);
extern void fn_1_485C8(s32);
extern void fn_1_48140(s32 value);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);

extern u8 lbl_1_bss_3E024[52];
extern char lbl_1_data_1A3AC[5];
extern void fn_80083DB0(void *arg0, void *arg1);
extern u32 fn_80006CE4(u32);
extern void *fn_80006DE8(void *);
extern u32 lbl_801A6410;
extern void *fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, u32 arg3);
extern void *fn_1_46B4(u32 arg0, void *arg1, u8 *arg2, u32 arg3);
extern void strcat(void *arg0, void *arg1);
extern void fn_1_48004(s32 value, s32 arg);

extern u32 fn_1_45D78(u32, u32, u32 *, s32);
extern int fn_1_45CD8(int);

typedef struct LoadEntry {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_c;
} LoadEntry;

typedef struct LoadManager {
    u8 pad0[0x18];
    LoadEntry entries[1408];
    u32 unk_5818;
    u32 unk_581c;
    u32 unk_5820;
    u8 pad5824[0x5b34 - 0x5824];
    u32 unk_5b34;
} LoadManager;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_384C0;
u32 lbl_1_bss_384C4;
u32 fzgx_obj_lbl_1_bss_384C8;
u32 lbl_1_bss_384CC;
u32 fzgx_obj_lbl_1_bss_384D0[2];
LoadEntry fzgx_obj_lbl_1_bss_384D8[1408];
u32 lbl_1_bss_3DCD8;
u32 fzgx_obj_lbl_1_bss_3DCDC;
u32 lbl_1_bss_3DCDC__fzgx_offset_4;
u32 lbl_1_bss_3DCE4[17];
u32 lbl_1_bss_3DD28[179];
u32 fzgx_obj_lbl_1_bss_3DFF4;
u32 lbl_1_bss_3DFF4__fzgx_offset_4[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C0;
    s = *(u8 *)&lbl_1_bss_384C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C8;
    s = *(u8 *)&lbl_1_bss_384CC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D8;
    s = *(u8 *)&lbl_1_bss_3DCD8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3DCDC;
    s = *(u8 *)&lbl_1_bss_3DCDC__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_3DCE4;
    s = *(u8 *)&lbl_1_bss_3DD28;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3DFF4;
    s = *(u8 *)&lbl_1_bss_3DFF4__fzgx_offset_4;
}
#pragma section code_type ".text"

LoadEntry *fn_1_45BF0(u32 size) {
    s32 wrapped = 0;
    LoadEntry *entry;
    u32 addr;
    
    u32 aligned_size;
    aligned_size = (size + 0x1F) & ~0x1F;

    do {
        if (fzgx_obj_lbl_1_bss_3DFF4 - lbl_1_bss_3DCD8 > aligned_size) {
            addr = lbl_1_bss_3DCD8;
            lbl_1_bss_3DCD8 = addr + aligned_size;
        } else {
            if (fzgx_obj_lbl_1_bss_3DFF4 - fzgx_obj_lbl_1_bss_3DCDC < aligned_size) {
                return NULL;
            }
            addr = fzgx_obj_lbl_1_bss_3DCDC;
            lbl_1_bss_3DCD8 = addr + aligned_size;
            if (wrapped != 0) {
                return NULL;
            }
            wrapped = 1;
        }
    } while (fn_1_45D78(addr, aligned_size, &lbl_1_bss_3DCD8, 0) == 0);

    entry = fzgx_obj_lbl_1_bss_384D8;
    entry += lbl_1_bss_3DCDC__fzgx_offset_4;
    lbl_1_bss_3DCDC__fzgx_offset_4 = fn_1_45CD8(lbl_1_bss_3DCDC__fzgx_offset_4);
    entry->unk_0 = 0x80000000;
    entry->unk_8 = addr;
    entry->unk_c = size;

    return entry;
}
/* fzgx:end fn_1_45BF0 */

/* fzgx:begin fn_1_45CD8 */
int fn_1_45CD8(int index) {
    s32 j;

    for (j = 0; j < 0x400; j++) {
        index++;
        if ((&lbl_1_bss_384D8.unk_0)[index * 4] == 0) {
            return index;
        }
        if (index >= 0x400) {
            index = 0;
        }
    }

    return index;
}
/* fzgx:end fn_1_45CD8 */

/* fzgx:begin fn_1_45D78 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
} fn_1_45D78_LoadEntry;

int fn_1_45D78(u32 start, u32 size, u32 *out_end, s32 mode) {
    u32 limit;
    fn_1_45D78_LoadEntry *entry;
    u32 i;
    u32 total;
    u32 end;

    limit = start + size;
    entry = (fn_1_45D78_LoadEntry *)&lbl_1_bss_384D8;
    total = -1;
    for (i = 0; i < 0x400; i++, entry++) {
        if (entry->unk_0 != 0) {
            if (entry->unk_8 < limit) {
                end = entry->unk_8 + entry->unk_C;
                if (end > start) {
                    if (mode == 0 && (entry->unk_0 & 0x10000000) != 0) {
                        if (out_end != 0) {
                            *out_end = end;
                        }
                        return 0;
                    }
                    entry->unk_0 = 0;
                    if (total == (u32)-1) {
                        total = 0;
                    }
                    total += entry->unk_C;
                }
            }
        }
    }
    return total;
}
/* fzgx:end fn_1_45D78 */

/* fzgx:begin fn_1_45E84 */
s32 fn_1_45E84(s32 value) {
    value += 1;
    if (value >= 0x200) {
        value = 0;
    }
    return value;
}
/* fzgx:end fn_1_45E84 */

/* fzgx:begin fn_1_45E98 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

/* Non-owning view of load.c BSS, through its buffer pointer at +0x586c.
 * Individual retail objects retain their definitions and ownership. */
extern u8 lbl_1_bss_384C0[0x5870];

extern void fn_1_D3214(void);
extern void fn_1_45890(u32);
extern void DCInvalidateRange(void *, u32);
typedef void (*Sig_ARQPostRequest_ARQCallback)(u32);
typedef struct Sig_ARQPostRequest_ARQRequest {
    struct Sig_ARQPostRequest_ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    Sig_ARQPostRequest_ARQCallback callback;
} Sig_ARQPostRequest_ARQRequest;
extern void ARQPostRequest(Sig_ARQPostRequest_ARQRequest *, u32, u32, u32, u32, void *, u32, Sig_ARQPostRequest_ARQCallback);
typedef struct Sig_fn_8006A3DC_Fn8006A3DCHeader {
    u32 magic;
    u32 data_offset;
    u32 unk_8;
    u32 table_offset;
} Sig_fn_8006A3DC_Fn8006A3DCHeader;
typedef struct Sig_fn_8006A3DC_Fn8006A3DCResult {
    void *header, *data, *table;
    u32 count;
    void *end;
    u32 unk_14;
    u32 unk_18;
} Sig_fn_8006A3DC_Fn8006A3DCResult;
extern s32 fn_8006A3DC(Sig_fn_8006A3DC_Fn8006A3DCHeader *, Sig_fn_8006A3DC_Fn8006A3DCResult *);
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_80006FE0(char *, u32);
extern void strcat(void *, void *);
extern s32 fn_8006A554(void *, void *);
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
} fn_1_45E98_Entry;
typedef struct {
    char filename[0x88];
    char message[0x14];
    char path[0x10];
} fn_1_45E98_Data;
#pragma opt_common_subs off
static inline int is_busy(u8 *base) {
    s8 n;
    if (*(s32 *)(base + 0x10) != 0) return 1;
    for (n = 0; n < 16; n++) {
        if (((s32 *)(base + 0x5824))[n] != 0) return 1;
    }
    return 0;
}
#pragma opt_common_subs reset

extern u8 fn_1_451E4__fzgx_offset_104[];
extern u8 fn_1_451E4__fzgx_offset_110[];
extern u8 fn_1_451E4__fzgx_offset_11C[];
extern u8 fn_1_451E4__fzgx_offset_128[];
extern u8 fn_1_451E4__fzgx_offset_26C[];
extern u8 fn_1_451E4__fzgx_offset_298[];
extern u8 fn_1_451E4__fzgx_offset_39C[];
extern u8 fn_1_451E4__fzgx_offset_3D8[];
extern u8 fn_1_451E4__fzgx_offset_534[];
extern u8 fn_1_451E4__fzgx_offset_64[];
extern u8 fn_1_451E4__fzgx_offset_78[];
extern u8 fn_1_451E4__fzgx_offset_A0[];
extern u8 fn_1_451E4__fzgx_offset_C0[];
extern u8 fn_1_451E4__fzgx_offset_EC[];
extern u8 fn_1_451E4__fzgx_offset_F8[];
static union {u32 words[34]; char view[0x88];} fzgx_pool_native_lbl_1_data_6730_filename = {{0x6C6F6164, 0x2E630000, 0x63616E6E, 0x6F74206F, 0x70656E20, 0x66696C65, 0x0A000000, 0x63616E6E, 0x6F742072, 0x65616420, 0x66696C65, 0x0A000000, 0x4152414D, 0x20617263, 0x68697665, 0x20657874, 0x656E6420, 0x6572726F, 0x72000000, (u32)fn_1_451E4__fzgx_offset_534, (u32)fn_1_451E4__fzgx_offset_EC, (u32)fn_1_451E4__fzgx_offset_F8, (u32)fn_1_451E4__fzgx_offset_104, (u32)fn_1_451E4__fzgx_offset_110, (u32)fn_1_451E4__fzgx_offset_11C, (u32)fn_1_451E4__fzgx_offset_128, (u32)fn_1_451E4__fzgx_offset_26C, (u32)fn_1_451E4__fzgx_offset_298, (u32)fn_1_451E4__fzgx_offset_39C, (u32)fn_1_451E4__fzgx_offset_3D8, (u32)fn_1_451E4__fzgx_offset_A0, (u32)fn_1_451E4__fzgx_offset_78, (u32)fn_1_451E4__fzgx_offset_C0, (u32)fn_1_451E4__fzgx_offset_64}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_6730_message[0x14] = {0x6E, 0x6F, 0x74, 0x20, 0x61, 0x72, 0x63, 0x68, 0x69, 0x76, 0x65, 0x20, 0x66, 0x69, 0x6C, 0x65, 0x00, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static s8 fzgx_pool_native_lbl_1_data_6730_path[0x10] = {0x2F, 0x00, 0x00, 0x00, 0x4E, 0x6F, 0x74, 0x20, 0x41, 0x52, 0x41, 0x4D, 0x20, 0x41, 0x72, 0x63}; /* fzgx-allow: A1 measured pool bytes and bindings */

void fn_1_45E98(u32 arg0, void *arg1) {
    u8 *base;
    s32 n;
    s32 i;
    s32 result;
    Sig_fn_8006A3DC_Fn8006A3DCHeader *hdr;
    Sig_ARQPostRequest_ARQRequest arq;
    char buf[256];
    fn_1_45E98_Entry *tab;
    u32 key;
    fn_1_45E98_Entry *e;
    s32 tmp_call3;

    base = (u8 *)&lbl_1_bss_384C0;

    e = (fn_1_45E98_Entry *)(base + 0x18);
    result = -1;
    for (i = 0; i < 0x400 && result == -1; i++, e++) {
        if ((e->unk_0 & 0x04000000) != 0) {
            while (is_busy(base)) fn_1_D3214();
            *(u32 *)(base + 0x10) = 1;
            DCInvalidateRange((*(void **)(base + 0x586c)), e->unk_C);
            ARQPostRequest(&arq, 0, 1, 1, e->unk_8, *(void **)(base + 0x586c), e->unk_C, fn_1_45890);
            while (is_busy(base)) fn_1_D3214();
            hdr = *(Sig_fn_8006A3DC_Fn8006A3DCHeader **)(base + 0x586c);
{
    Sig_fn_8006A3DC_Fn8006A3DCResult res;
            tmp_call3 = fn_8006A3DC(hdr, &res);
            if (!tmp_call3) {
                OSPanic(fzgx_pool_native_lbl_1_data_6730_filename.view, 0x370, fzgx_pool_native_lbl_1_data_6730_message);
            }
            fn_80006FE0(buf, 0xff);
            strcat(buf, fzgx_pool_native_lbl_1_data_6730_path);
            strcat(buf, (void *)arg0);
            result = fn_8006A554(&res, buf);
}
            if (result > 0) {
                key = e->unk_8 + *(u32 *)(*(u8 **)(base + 0x586c) + hdr->data_offset + result * 12 + 4);
                tab = (fn_1_45E98_Entry *)(base + 0x18);
                for (n = 0; n < 0x400; n++, tab++) {
                    if ((tab->unk_0 & 0x48000000) == 0x48000000 && tab->unk_8 == key) {
                        *(fn_1_45E98_Entry **)arg1 = tab;
                        break;
                    }
                }
            }
        }
    }
}
/* fzgx:end fn_1_45E98 */

/* fzgx:begin fn_1_46144 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/load.h"
#include "types.h"

extern int fn_1_45E98(void *arg0, void **result);
extern s32 fn_8000700C();
extern int fn_80006C2C(int status, void *arg0);
extern char *fn_80083DB0(char *dst, const char *src);
extern u32 fn_1_46EC8(void);
extern u32 fn_1_46ED8(void);
extern u32 lbl_1_bss_3DCE4[17];
extern void *fn_80006DFC(void *arg);
extern void fn_1_D3214(void);
extern void fn_1_3BDC(u32 arg0);
extern void fn_8000659C(void);
extern u32 lbl_1_bss_384C4;
extern u32 fn_1_46A8C(u32 value);
extern u32 lbl_1_bss_3DCD8;
extern u32 lbl_1_bss_3DD28[179];
extern void fn_1_47EE4(s32 index);
extern void fn_1_485C8(u32 arg0);
extern void fn_1_48140(int index);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);
extern u8 lbl_1_bss_3E024[52];
extern char lbl_1_data_1A3AC[5];
extern u32 fn_80006CE4(u32);
extern void *fn_80006DE8(void *);
extern u32 lbl_801A6410;
extern u32 fn_1_4630();
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern char *strcat(char *dest, const char *src);
extern void fn_1_48004(s32 index, s32 image);

/* begin dolphin/ar.h (deltawave784/fzgx, CC0) */
#ifndef DOLPHIN_AR_H
#define DOLPHIN_AR_H

/* ARAM DMA request queue (ARQ), Dolphin SDK names. */

/* begin layout_check.h (deltawave784/fzgx, CC0) */
#ifndef LAYOUT_CHECK_H
#define LAYOUT_CHECK_H

/* Compile-time layout checks for owned types. They declare array typedefs
 * only, so they emit no code or data under MWCC: a wrong size or offset is
 * a negative array bound and fails the compile. */
#define LAYOUT_CHECK_JOIN2(a, b) a##b
#define LAYOUT_CHECK_JOIN(a, b) LAYOUT_CHECK_JOIN2(a, b)
#define CHECK_SIZE(T, size) \
    typedef char LAYOUT_CHECK_JOIN(layout_size_, T)[(sizeof(T) == (size)) ? 1 : -1]
#define CHECK_OFFSET(T, field, offset) \
    typedef char LAYOUT_CHECK_JOIN(LAYOUT_CHECK_JOIN(layout_offset_, T), __LINE__) \
        [((unsigned long)&((T *)0)->field == (offset)) ? 1 : -1]

#endif

/* end layout_check.h */

typedef void (*ARQCallback)(u32 pointerToARQRequest);

typedef struct ARQRequest {
    struct ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    ARQCallback callback;
} ARQRequest;

CHECK_OFFSET(ARQRequest, dest, 0x14);
CHECK_SIZE(ARQRequest, 0x20);

#endif

/* end dolphin/ar.h */

extern void fn_1_D3214(void);
extern void fn_1_45890(u32 request);
extern void DCInvalidateRange(void *addr, u32 size);

typedef struct Fn464BCEntry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Fn464BCEntry;

typedef struct Fn464BCObject {
    u8 unk_00[4];
    Fn464BCEntry *unk_04;
    u8 unk_08[8];
    u8 *unk_10;
} Fn464BCObject;

typedef struct {
    void *header;
    void *data;
    void *table;
    u32 count;
    void *end;
    u32 unk_14;
    u32 unk_18;
} Fn8006A3DCResult;

extern void fn_1_464BC(void *object, u32 index, void *arg2, u32 arg3);
extern s32 fn_8006A3DC(void *header, Fn8006A3DCResult *result);
extern void OSReport(const char *, ...);
extern s32 fn_8000700C(const char *);

typedef struct {
    u32 flags;
    u32 unk_4;
    u32 addr;
    u32 size;
} LoadSlot;

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u32 offset;
    u32 size;
} ArcEntry;

typedef struct {
    u32 unk_0;
    u32 offset;
    u32 size;
} ArcHeader;

typedef struct {
    u8 pad_0[8];
    u32 aram;
    u32 end;
} LoadArchive;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_384C0;
u8 fzgx_pool_lbl_1_bss_384C0_gap_384C4[12];
s32 fzgx_obj_lbl_1_bss_384D0;                /* +0x10 busy */
u32 lbl_1_bss_384D0__fzgx_offset_4;
LoadSlot fzgx_obj_lbl_1_bss_384D8[0x400];    /* +0x18 slot table */
u8 fzgx_pool_fzgx_obj_lbl_1_bss_384D8_fill_4000[0x5820 - 0x4018];
s32 lbl_1_bss_3DCDC__fzgx_offset_4;                /* +0x5820 next free slot */
s32 fzgx_obj_lbl_1_bss_3DCE4[16];            /* +0x5824 pending requests */
u32 fzgx_pool_fzgx_obj_lbl_1_bss_3DD24[2];
u8 *lbl_1_bss_3DD28__fzgx_offset_4;                /* +0x586c work buffer */

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C0;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_384C0_gap_384C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D0;
    s = *(u8 *)&lbl_1_bss_384D0__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D8;
    s = *(u8 *)&fzgx_pool_fzgx_obj_lbl_1_bss_384D8_fill_4000;
    s = *(u8 *)&lbl_1_bss_3DCDC__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3DCE4;
    s = *(u8 *)&fzgx_pool_fzgx_obj_lbl_1_bss_3DD24;
    s = *(u8 *)&lbl_1_bss_3DD28__fzgx_offset_4;
}
#pragma section code_type ".text"

static inline int fn_1_46144_busy(void) {
    s8 i;
    s32 *pending;
    if (fzgx_obj_lbl_1_bss_384D0 != 0) {
        return 1;
    }
    pending = fzgx_obj_lbl_1_bss_3DCE4;
    for (i = 0; i < 16; i++) {
        if (pending[i] != 0) {
            return 1;
        }
    }
    return 0;
}

int fn_1_46144(LoadArchive *archive, s32 locked, s32 named) {
    ARQRequest request;
    u8 name[0x40];
    Fn8006A3DCResult result;
    u32 offset;
    ArcHeader *header;
    u32 aram;
    u32 size;
    s32 count;
    ArcEntry *entry;
    s32 i;
    LoadSlot *slot;
    s32 k;
    s32 next;
    u32 slotAddr;
    u32 slotSize;

    aram = archive->aram;
    while (fn_1_46144_busy()) {
        fn_1_D3214();
    }
    fzgx_obj_lbl_1_bss_384D0 = 1;
    DCInvalidateRange(lbl_1_bss_3DD28__fzgx_offset_4, 0x20);
    ARQPostRequest(&request, 0, 1, 1, aram, (u32)lbl_1_bss_3DD28__fzgx_offset_4, 0x20, (ARQCallback)fn_1_45890);
    while (fn_1_46144_busy()) {
        fn_1_D3214();
    }
    header = (ArcHeader *)lbl_1_bss_3DD28__fzgx_offset_4;
    size = (header->size + 0x1f) & ~0x1f;
    offset = header->offset;
    archive->end = size + offset;
    fzgx_obj_lbl_1_bss_384D0 = 1;
    DCInvalidateRange(lbl_1_bss_3DD28__fzgx_offset_4 + offset, size);
    ARQPostRequest(&request, 0, 1, 1, aram + offset, (u32)(lbl_1_bss_3DD28__fzgx_offset_4 + offset), size, (ARQCallback)fn_1_45890);
    while (fn_1_46144_busy()) {
        fn_1_D3214();
    }
    if (fn_8006A3DC(header, &result) == 0) {
        OSReport((const char *)lbl_1_data_67D0);
        return 0;
    }
    entry = (ArcEntry *)(lbl_1_bss_3DD28__fzgx_offset_4 + offset);
    count = entry->size;
    for (i = 0; i < count; i++, entry++) {
        if (entry->unk_0 == 0) {
            slotAddr = entry->offset;
            slotSize = entry->size;
            slot = &fzgx_obj_lbl_1_bss_384D8[lbl_1_bss_3DCDC__fzgx_offset_4];
            slot->flags = (locked ? 0x10000000 : 0) | 0x40000000;
            slot->addr = aram + slotAddr;
            slot->size = (slotSize + 0x1f) & ~0x1f;
            if (named) {
                fn_1_464BC(&result, i, name, 0x40);
                slot->unk_4 = fn_8000700C((const char *)name);
            } else {
                slot->flags |= 0x08000000;
                slot->unk_4 = i;
            }
            next = lbl_1_bss_3DCDC__fzgx_offset_4;
            for (k = 0; k < 0x400; k++) {
                next++;
                if (fzgx_obj_lbl_1_bss_384D8[next].flags == 0) {
                    break;
                }
                if (next >= 0x400) {
                    next = 0;
                }
            }
            lbl_1_bss_3DCDC__fzgx_offset_4 = next;
        }
    }
    return 1;
}
/* fzgx:end fn_1_46144 */

/* fzgx:begin fn_1_464BC */
typedef struct Fn464BCEntry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Fn464BCEntry;

typedef struct Fn464BCObject {
    u8 unk_00[4];
    Fn464BCEntry *unk_04;
    u8 unk_08[8];
    u8 *unk_10;
} Fn464BCObject;

extern u16 lbl_1_data_67CC;
extern void fn_80083DB0(void *arg0, void *arg1);

void fn_1_464BC(Fn464BCObject *object, u32 index, void *arg2, void *arg3) {
    void *result;
    Fn464BCEntry *base;
    Fn464BCEntry *entry;
    u32 value;
    s32 flag;

    base = object->unk_04;
    entry = &base[index];
    result = fn_1_4630(lbl_801A6410, (u32)arg3, (*(u8 (*)[76])&lbl_1_data_6730), 0x3f4);
    value = entry->unk_00;
    fn_80083DB0(arg2, object->unk_10 + (value & 0x00ffffff));

    while (entry > base) {
        value = entry->unk_00;
        flag = (value & 0xff000000) != 0;
        if (flag != 0) {
            fn_80083DB0(result, object->unk_10 + (value & 0x00ffffff));
            strcat(result, &lbl_1_data_67CC);
            strcat(result, arg2);
            fn_80083DB0(arg2, result);
            entry = &base[entry->unk_04];
        } else {
            entry--;
        }
    }

    fn_1_46B4(lbl_801A6410, result, (*(u8 (*)[76])&lbl_1_data_6730), 0x402);
}
/* fzgx:end fn_1_464BC */

/* fzgx:begin fn_1_465D0 */
// Queues a completed load operation in the circular load queue.
s32 fn_1_465D0(s32 arg0, s32 arg1) {
    s32 *base = (s32 *)&lbl_1_bss_384C0;
    s32 result;
    s32 index;
    s32 *entry;
    s32 next;

    if (base[0x161A] != 0) {
        switch (arg1) {
        case 3:
        case 1:
        case 5:
            arg1++;
            break;
        }
    }

    result = fn_8000700C(arg0);
    if (result < 0) {
        return -1;
    }

    if (base[0] == base[1]) {
        fn_1_3BDC(2);
    }

    index = base[0];
    next = index + 1;
    if (next >= 0x200) {
        next = 0;
    }

    if (base[1] == next) {
        return -1;
    }

    entry = base + 0x1006;
    entry += index * 3;
    base[0] = next;
    entry[0] = arg1;
    entry[1] = result;
    return index;
}
/* fzgx:end fn_1_465D0 */

/* fzgx:begin fn_1_466B0 */
extern u32 fn_1_467F4(void);
extern void fn_1_469BC(void);

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
} LoadQueueEntry;

#pragma opt_lifetimes off
u32 fn_1_466B0(u32 arg0, s32 arg1) {
    struct { u32 value; } result;
    s32 start;
    struct { u32 value; } i;
    struct { LoadQueueEntry *value; } tab;
    u32 flags;

    if ((s32)fn_1_467F4() != 0) {
        fn_1_469BC();
    }
    result.value = -1;
    for (i.value = 0, tab.value = (LoadQueueEntry *)&lbl_1_bss_384D8;
         i.value < 0x400; i.value++, tab.value++) {
        flags = tab.value->unk_0;
        if (flags != 0) {
            start = tab.value->unk_8;
            if (start < arg0 + 1 && start + tab.value->unk_C > arg0) {
                if (arg1 == 0 && (flags & 0x10000000)) {
                    result.value = 0;
                    break;
                }
                flags = 0;
                tab.value->unk_0 = flags;
                if (result.value == (u32)-1) {
                    result.value = flags;
                }
                result.value += tab.value->unk_C;
            }
        }
    }
    {
        u32 out = result.value;
        if (result.value == (u32)-1) {
            out = 0;
        }
        return out;
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_466B0 */

/* fzgx:begin fn_1_467F4 */
u32 fn_1_467F4(void) {
    u32 value;

    fn_8000659C();
    value = lbl_1_bss_384C4;
    return lbl_1_bss_384C0 != value;
}
/* fzgx:end fn_1_467F4 */

/* fzgx:begin fn_1_46838 noprologue */
#include "types.h"
#include "dolphin/dvd.h"

typedef struct {
    u32 flag;
    s32 id;
    u32 value;
    u32 unk_0C;
} fn_1_46838_entry;

typedef struct {
    u32 unk_0;
    u32 busy;
    DVDCommandBlock block;
} fn_1_46838_queue;

typedef struct {
    u32 unk_00[6];
    fn_1_46838_entry entries[0x400];
    s32 states[0x200][3];
    u32 mirror;
    u32 unk_581C[0x16];
    fn_1_46838_queue queue;
} fn_1_46838_ctx;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_384C0;
u32 fzgx_obj_lbl_1_bss_384C4;
u32 fzgx_obj_lbl_1_bss_384C8;
u32 fzgx_obj_lbl_1_bss_384CC;
u32 fzgx_obj_lbl_1_bss_384D0[2];
u32 fzgx_obj_lbl_1_bss_384D8[4096];
u32 lbl_1_bss_384D8__fzgx_offset_4000[1536];
u32 fzgx_obj_lbl_1_bss_3DCD8;
u32 fzgx_obj_lbl_1_bss_3DCDC[2];
u32 fzgx_obj_lbl_1_bss_3DCE4[17];
u32 fzgx_obj_lbl_1_bss_3DD28[3];
fn_1_46838_queue lbl_1_bss_3DD28__fzgx_offset_C;
u32 lbl_1_bss_3DD28__fzgx_offset_44[162];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_384C0;
    s = fzgx_obj_lbl_1_bss_384C4;
    s = fzgx_obj_lbl_1_bss_384C8;
    s = fzgx_obj_lbl_1_bss_384CC;
    s = fzgx_obj_lbl_1_bss_384D0[0];
    s = fzgx_obj_lbl_1_bss_384D8[0];
    s = lbl_1_bss_384D8__fzgx_offset_4000[0];
    s = fzgx_obj_lbl_1_bss_3DCD8;
    s = fzgx_obj_lbl_1_bss_3DCDC[0];
    s = fzgx_obj_lbl_1_bss_3DCE4[0];
    s = fzgx_obj_lbl_1_bss_3DD28[0];
    s = lbl_1_bss_3DD28__fzgx_offset_C.busy;
    s = lbl_1_bss_3DD28__fzgx_offset_44[0];
}
#pragma section code_type ".text"

#pragma opt_propagation off
s32 fn_1_46838(u32 arg0) {
    u32 *fzgx_value;
    s32 *state = (s32 *)lbl_1_bss_384D8__fzgx_offset_4000;
    u32 i;
    fn_1_46838_entry *entry;
    s32 v;

    state += arg0 * 3;
    v = state[0];
    switch (v) {
    case 1:
    case 2:
    case 0xB:
    case 0xD:
        state[0] = 0xE;
        state[1] = -1;
        break;
    case 7:
    case 8:
    case 9:
    case 0xA:
        entry = (fn_1_46838_entry *)fzgx_obj_lbl_1_bss_384D8;
        if (lbl_1_bss_3DD28__fzgx_offset_C.busy == 0) {
            DVDCancelAsync(&lbl_1_bss_3DD28__fzgx_offset_C.block, NULL);
        }
        for (i = 0; i < 0x400; i++, entry++) {
            if (entry->flag != 0 && entry->id == state[1]) {
                fzgx_value = &(entry->flag);
                *fzgx_value = 0;
                fzgx_obj_lbl_1_bss_3DCD8 = entry->value;
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_46838 */

/* fzgx:begin fn_1_469BC noprologue */
#include "types.h"

extern u32 lbl_1_bss_384C0[];

// Clears invalid entries in the load table and mirrors its first value.
void fn_1_469BC(void) {
    u32 *base;
    u32 *entry;
    int i;

    base = lbl_1_bss_384C0;
    entry = base + 6;
    for (i = 0; i < 0x400;) {
        if (entry[0] == ((u32)1 << 31)) {
            entry[0] = 0;
            base[0x1606] = entry[2];
        }
        i++;
        entry += 4;
    }
    base[1] = base[0];
}
/* fzgx:end fn_1_469BC */

/* fzgx:begin fn_1_46A60 */
void fn_1_46A60(void) {
    fn_1_46A8C(lbl_1_bss_3DCDC);
}
/* fzgx:end fn_1_46A60 */

/* fzgx:begin fn_1_46A8C noprologue */
#include "types.h"

typedef struct {
    u32 type;
    u32 value;
    u32 unk_8;
} Entry;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[0x4010];
    Entry entries[0x200];
} State;

extern u32 lbl_1_bss_384C0;
extern u32 fn_1_46EC8(void);
extern u32 fn_1_46ED8(void);

u32 fn_1_46A8C(u32 value) {
    State *base;
    s32 next;
    s32 current;
    u32 initial;
    u32 arg;
    Entry *entry;

    base = (State *)&lbl_1_bss_384C0;
    arg = value;
    initial = base->unk_0;
    next = initial + 1;
    current = initial;
    if (next >= 0x200) {
        next = 0;
    }

    if ((s32)base->unk_4 == next) {
        return -1;
    }

    if (arg < fn_1_46EC8() || arg > fn_1_46ED8()) {
        arg = fn_1_46EC8();
    }

    entry = base->entries;
    entry += base->unk_0;
    base->unk_0 = next;
    entry->type = 0xb;
    entry->value = arg;

    return current;
}
/* fzgx:end fn_1_46A8C */

/* fzgx:begin fn_1_46B44 */
extern u32 lbl_1_bss_3DCE4[17];
extern void *fn_80006DFC(void *arg);
extern void fn_1_D3214(void);
extern s32 fn_8000700C(s32 arg0);
extern void fn_1_3BDC(s32 arg0);
extern void fn_8000659C(void);
extern u32 lbl_1_bss_384C4;
extern void fn_1_46A8C(u32 value);
extern u32 lbl_1_bss_3DCD8;
extern u32 lbl_1_bss_3DD28[179];
extern void fn_1_47EE4(s32);
extern void fn_1_485C8(s32);
extern void fn_1_48140(s32 value);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);

extern u8 lbl_1_bss_3E024[52];
extern char lbl_1_data_1A3AC[5];
extern void fn_80083DB0(void *arg0, void *arg1);
extern u32 fn_80006CE4(u32);
extern void *fn_80006DE8(void *);
extern u32 lbl_801A6410;
extern void *fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, u32 arg3);
extern void *fn_1_46B4(u32 arg0, void *arg1, u8 *arg2, u32 arg3);
extern void strcat(void *arg0, void *arg1);
extern void fn_1_48004(s32 value, s32 arg);

struct fn_1_46B44_entry {
    u32 type;
    u32 value;
    u32 unk_8;
};

struct fn_1_46B44_lbl_1_bss_384C0 {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[0x4010];
    struct fn_1_46B44_entry entries[0x200];
};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_384C0;
u32 lbl_1_bss_384C4;
u32 fzgx_obj_lbl_1_bss_384C8;
u32 lbl_1_bss_384CC;
u32 fzgx_obj_lbl_1_bss_384D0[2];
u32 lbl_1_bss_384D8__fzgx_offset_0[4096];
struct fn_1_46B44_entry lbl_1_bss_384D8__fzgx_offset_4000[0x200];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C0;
    s = *(u8 *)&lbl_1_bss_384C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C8;
    s = *(u8 *)&lbl_1_bss_384CC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D0;
    s = *(u8 *)&lbl_1_bss_384D8__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_384D8__fzgx_offset_4000;
}
#pragma section code_type ".text"

u32 fn_1_46B44(u32 arg0, u32 arg1) {
    u32 v0;
    s32 v1;
    struct fn_1_46B44_entry *v2;
    s32 current;

    
    v0 = fzgx_obj_lbl_1_bss_384C0;
    v1 = v0 + 1;
    current = v0;
    if (v1 >= 512) {
        v1 = 0;
    }
    if ((s32)lbl_1_bss_384C4 == v1) {
        return -1;
    }
    v2 = lbl_1_bss_384D8__fzgx_offset_4000;
    {
        u32 type = 13;
        fzgx_obj_lbl_1_bss_384C0 = v1;
        v2 += v0;
        v2->type = type;
    }
    v2->value = arg0;
    v2->unk_8 = arg1;
    return current;
}
/* fzgx:end fn_1_46B44 */

/* fzgx:begin fn_1_46BA0 */
extern u32 lbl_1_bss_3DCE4[17];
extern void *fn_80006DFC(void *arg);
extern void fn_1_D3214(void);
extern s32 fn_8000700C(s32 arg0);
extern void fn_1_3BDC(s32 arg0);
extern void fn_8000659C(void);
extern u32 lbl_1_bss_384C4;
extern void fn_1_46A8C(u32 value);
extern u32 lbl_1_bss_3DCD8;
extern u32 lbl_1_bss_3DD28[179];
extern void fn_1_47EE4(s32);
extern void fn_1_485C8(s32);
extern void fn_1_48140(s32 value);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);

extern u8 lbl_1_bss_3E024[52];
extern char lbl_1_data_1A3AC[5];
extern void fn_80083DB0(void *arg0, void *arg1);
extern u32 fn_80006CE4(u32);
extern void *fn_80006DE8(void *);
extern u32 lbl_801A6410;
extern void *fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, u32 arg3);
extern void *fn_1_46B4(u32 arg0, void *arg1, u8 *arg2, u32 arg3);
extern void strcat(void *arg0, void *arg1);
extern void fn_1_48004(s32 value, s32 arg);

struct fn_1_46BA0_lbl_1_bss_384C0 {
    u32 unk_0;
    u32 unk_4;
};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_384C0;
u32 lbl_1_bss_384C4;
u32 fzgx_obj_lbl_1_bss_384C8;
u32 lbl_1_bss_384CC;
u32 fzgx_obj_lbl_1_bss_384D0[2];
u32 lbl_1_bss_384D8__fzgx_offset_0[4096];
u8 lbl_1_bss_384D8__fzgx_offset_4000;
u8 lbl_1_bss_384D8__fzgx_offset_4001;
u16 lbl_1_bss_384D8__fzgx_offset_4002;
u32 lbl_1_bss_384D8__fzgx_offset_4004[1535];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C0;
    s = *(u8 *)&lbl_1_bss_384C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C8;
    s = *(u8 *)&lbl_1_bss_384CC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D0;
    s = *(u8 *)&lbl_1_bss_384D8__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_384D8__fzgx_offset_4000;
    s = *(u8 *)&lbl_1_bss_384D8__fzgx_offset_4001;
    s = *(u8 *)&lbl_1_bss_384D8__fzgx_offset_4002;
    s = *(u8 *)&lbl_1_bss_384D8__fzgx_offset_4004;
}
#pragma section code_type ".text"

#pragma opt_lifetimes off
u32 fn_1_46BA0(u32 arg0, u32 arg1) {
    u32 v0;
    s32 v1;
    void *v2;
    
    v0 = fzgx_obj_lbl_1_bss_384C0;
    v1 = v0 + 1;
{
    s32 current;
    current = v0;
    if (v1 >= 512) {
        v1 = 0;
    }
    if ((s32)lbl_1_bss_384C4 == v1) {
        return -1;
    }
    v2 = (void *)((u8 *)&lbl_1_bss_384D8__fzgx_offset_4000);
    v2 = (u8 *)v2 + v0 * 12;
    fzgx_obj_lbl_1_bss_384C0 = v1;
    *(u32 *)((u8 *)v2 + 0) = 12;
    *(u32 *)((u8 *)v2 + 4) = arg0;
    *(u32 *)((u8 *)v2 + 8) = arg1;
    return current;
}
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_46BA0 */

/* fzgx:begin fn_1_46BFC */
extern u32 lbl_1_bss_3DCE4[17];
extern void *fn_80006DFC(void *arg);
extern void fn_1_D3214(void);
extern s32 fn_8000700C(s32 arg0);
extern void fn_1_3BDC(s32 arg0);
extern void fn_8000659C(void);
extern u32 lbl_1_bss_384C4;
extern void fn_1_46A8C(u32 value);
extern u32 lbl_1_bss_3DCD8;
extern u32 lbl_1_bss_3DD28[179];
extern void fn_1_47EE4(s32);
extern void fn_1_485C8(s32);
extern void fn_1_48140(s32 value);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);

extern u8 lbl_1_bss_3E024[52];
extern char lbl_1_data_1A3AC[5];
extern void fn_80083DB0(void *arg0, void *arg1);
extern u32 fn_80006CE4(u32);
extern void *fn_80006DE8(void *);
extern u32 lbl_801A6410;
extern void *fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, u32 arg3);
extern void *fn_1_46B4(u32 arg0, void *arg1, u8 *arg2, u32 arg3);
extern void strcat(void *arg0, void *arg1);
extern void fn_1_48004(s32 value, s32 arg);

struct fn_1_46BFC_state {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[0x4010];
    u32 entries[0x600];
};

extern u32 lbl_1_bss_958[2];

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_384C0;
u32 lbl_1_bss_384C4;
u32 fzgx_obj_lbl_1_bss_384C8;
u32 lbl_1_bss_384CC;
u32 fzgx_obj_lbl_1_bss_384D0[2];
u32 lbl_1_bss_384D8__fzgx_offset_0[4096];
u32 lbl_1_bss_384D8__fzgx_offset_4000[0x600];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C0;
    s = *(u8 *)&lbl_1_bss_384C4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384C8;
    s = *(u8 *)&lbl_1_bss_384CC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384D0;
    s = *(u8 *)&lbl_1_bss_384D8__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_384D8__fzgx_offset_4000;
}
#pragma section code_type ".text"

s32 fn_1_46BFC(u32 arg0) {
    u32 *entry;
    u32 value;
    s32 current;
    s32 next;

    
    value = lbl_1_bss_958[0];
    current = (s32)fzgx_obj_lbl_1_bss_384C0;
    next = current + 1;
    if (next >= 0x200) {
        next = 0;
    }
    if ((s32)lbl_1_bss_384C4 == next) {
        return -1;
    }
    entry = (u32 *)lbl_1_bss_384D8__fzgx_offset_4000;
    entry += current * 3;
    fzgx_obj_lbl_1_bss_384C0 = next;
    entry[0] = 0xc;
    entry[1] = value;
    entry[2] = 0x20000 - 0x2000;
    return current;
}
/* fzgx:end fn_1_46BFC */

/* fzgx:begin fn_1_46C60 */
u32 fn_1_46C60(void) {
    return lbl_1_bss_3DCD8;
}
/* fzgx:end fn_1_46C60 */

/* fzgx:begin fn_1_46C70 noprologue */
#include "rel/main_rel/load.h"

extern s32 fn_8000700C(void);

s32 fn_1_46C70(void) {
    s32 value;
    s32 i;
    Obj_1_bss_384D8 *entry;

    value = fn_8000700C();
    if (value == -1) {
        return -1;
    }

    entry = &lbl_1_bss_384D8;
    for (i = 0; i < 0x400; ) {
        if (entry->unk_0 != 0 && (s32)entry->unk_4 == value) {
            return entry->unk_8;
        }
        i++;
        entry = (Obj_1_bss_384D8 *)((u8 *)entry + 0x10);
    }
    return -1;
}
/* fzgx:end fn_1_46C70 */

/* fzgx:begin fn_1_46DC4 */
extern s32 fn_8000700C(s32 arg0);

s32 fn_1_46DC4(s32 value) {
    u8 *entry;
    s32 count;
    s32 i;

    count = 0;
    value = fn_8000700C(value);
    entry = (u8 *)&lbl_1_bss_384D8;
    for (i = 0; i < 1024; i++, entry += 0x10) {
        if ((((Obj_1_bss_384D8 *)entry)->unk_0 & 0x10000000) != 0 &&
            (s32)((Obj_1_bss_384D8 *)entry)->unk_4 == value) {
            ((Obj_1_bss_384D8 *)entry)->unk_0 &= ~0x10000000;
            count++;
        }
    }
    return count;
}
/* fzgx:end fn_1_46DC4 */

/* fzgx:begin fn_1_46EA8 */
void fn_1_46EA8(u32 value) {
    lbl_1_bss_3DD28[0] = value;
}
/* fzgx:end fn_1_46EA8 */

/* fzgx:begin fn_1_46EB4 */
void fn_1_46EB4(u32 value, u32 value2) {
    lbl_1_bss_3DCDC = value;
    lbl_1_bss_3DFF4.unk_0 = value2;
}
/* fzgx:end fn_1_46EB4 */

/* fzgx:begin fn_1_46EC8 */
// Returns the current load-state value.
u32 fn_1_46EC8(void) {
    return lbl_1_bss_3DCDC;
}
/* fzgx:end fn_1_46EC8 */

/* fzgx:begin fn_1_46ED8 */
u32 fn_1_46ED8(void) {
    return lbl_1_bss_3DFF4.unk_0;
}
/* fzgx:end fn_1_46ED8 */

/* fzgx:begin fn_1_4706C */
typedef struct {
    u32 flag;
    s32 id;
    u32 value;
    u32 unk_0C;
} fn_1_4706C_entry;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 fzgx_obj_lbl_1_bss_384C0;
s32 fzgx_obj_lbl_1_bss_384C4;
u32 fzgx_obj_lbl_1_bss_384C8;
u32 fzgx_obj_lbl_1_bss_384CC;
u32 fzgx_obj_lbl_1_bss_384D0[2];
u32 fzgx_obj_lbl_1_bss_384D8[4096];
u32 lbl_1_bss_384D8__fzgx_offset_4000[1536];
u32 fzgx_obj_lbl_1_bss_3DCD8;
u32 fzgx_obj_lbl_1_bss_3DCDC;
u32 lbl_1_bss_3DCDC__fzgx_offset_4;
u32 fzgx_obj_lbl_1_bss_3DCE4[17];
u32 fzgx_obj_lbl_1_bss_3DD28[3];
u32 lbl_1_bss_3DD28__fzgx_offset_C[176];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_384C0;
    s = fzgx_obj_lbl_1_bss_384C4;
    s = fzgx_obj_lbl_1_bss_384C8;
    s = fzgx_obj_lbl_1_bss_384CC;
    s = (*((0) + (fzgx_obj_lbl_1_bss_384D0)));
    s = fzgx_obj_lbl_1_bss_384D8[0];
    s = lbl_1_bss_384D8__fzgx_offset_4000[0];
    s = fzgx_obj_lbl_1_bss_3DCD8;
    s = fzgx_obj_lbl_1_bss_3DCDC;
    s = lbl_1_bss_3DCDC__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_3DCE4[0];
    s = fzgx_obj_lbl_1_bss_3DD28[0];
    s = lbl_1_bss_3DD28__fzgx_offset_C[0];
}
#pragma section code_type ".text"

extern void fn_8000659C(void);

#pragma opt_common_subs off
void fn_1_4706C(void) {
    struct { u32 value; } i;
    fn_1_4706C_entry *entry;
    s32 j;

    fn_8000659C();
    if (fzgx_obj_lbl_1_bss_384C0 != fzgx_obj_lbl_1_bss_384C4) {
        entry = (fn_1_4706C_entry *)fzgx_obj_lbl_1_bss_384D8;
        for (i.value = 0; i.value < 0x400; i.value++, entry++) {
            if (entry->flag == 0x80000000) {
                entry->flag = 0;
                fzgx_obj_lbl_1_bss_3DCD8 = entry->value;
            }
        }
        fzgx_obj_lbl_1_bss_384C4 = fzgx_obj_lbl_1_bss_384C0;
    }
    entry = (fn_1_4706C_entry *)fzgx_obj_lbl_1_bss_384D8;
    for (j = 0; j < 0x400; j++, entry++) {
        entry->flag = 0;
    }
    lbl_1_bss_3DCDC__fzgx_offset_4 = 0;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_4706C */

/* fzgx:begin fn_1_47184 */
u32 fn_1_47184(void) {
    return lbl_1_bss_3DFF4.unk_0 - lbl_1_bss_3DCDC;
}
/* fzgx:end fn_1_47184 */

/* fzgx:begin fn_1_471A0 */
#include "types.h"



u32 fn_1_471A0(void) {
    u32 *p;
    u32 i;
    u32 total;

    total = 0;
    p = (*(u32 (*)[5632])&lbl_1_bss_384D8);
    for (i = 0; i < 0x400; i++, p += 4) {
        if ((p[0] & 0x64000000) != 0) {
            total += p[3];
        }
    }
    return total;
}
/* fzgx:end fn_1_471A0 */

/* fzgx:begin fn_1_47268 */
#include "types.h"



u32 fn_1_47268(void) {
    u32 *p;
    u32 i;
    u32 total;

    total = 0;
    p = (*(u32 (*)[])&lbl_1_bss_384D8);
    for (i = 0; i < 0x400; i++, p += 4) {
        if ((p[0] & 0x10000000) != 0) {
            total += p[3];
        }
    }
    return total;
}
/* fzgx:end fn_1_47268 */

/* fzgx:begin fn_1_479B0 */
// Reset the loading state and clear the associated resource markers.
void fn_1_479B0(void) {
    fn_1_47EE4(0);
    fn_1_485C8(0);
    lbl_1_data_6CA0.unk_0 = -1;
    *(u32 *)&lbl_1_data_6CA0.pad_C[0] = -1;
    *(u32 *)&lbl_1_data_6CA0.pad_C[0xc] = -1;
}
/* fzgx:end fn_1_479B0 */

/* fzgx:begin fn_1_479F0 */
void fn_1_479F0(s16 index) {
    s32 *entry;
    s32 i;

    entry = (s32 *)&lbl_1_data_67F0.unk_0 + index * 20;
    for (i = 0; i < 10; i++, entry += 2) {
        if (entry[0] != -1) {
            fn_1_48004(entry[0], entry[1]);
        } else {
            return;
        }
    }
}
/* fzgx:end fn_1_479F0 */

/* fzgx:begin fn_1_47A60 */
// Process the ten load entries associated with the selected index.
void fn_1_47A60(s16 index) {
    s32 *entry;
    s32 i;

    entry = (s32 *)&lbl_1_data_67F0.unk_0 + index * 20;
    for (i = 0; i < 10; i++) {
        if (entry[i * 2] != -1) {
            fn_1_48140(entry[i * 2]);
        } else {
            fn_1_4DDC0();
            fn_1_4F724();
            break;
        }
    }
}
/* fzgx:end fn_1_47A60 */

/* fzgx:begin fn_1_47AD4 */
extern u32 lbl_801A66B4;
extern u32 lbl_801A6410;
extern u8 lbl_1_bss_3E000[32];
extern char lbl_1_data_1A368[9];
extern void fn_8006FDEC(void);
extern s32 fn_1_45730(void *, void *);
extern size_t strlen(const char *);
extern s32 strncmp(const char *, const char *, size_t);
extern u32 OSGetArenaHi(void);
extern void OSSetArenaHi(u32);
extern u32 fn_8000B334(u32,u32);
extern u32 fn_8000B360(u32,u32);
extern void *fn_1_45D0(u32,u32,void *,u32);
extern s32 fn_1_45B2C(void *);
extern s32 fn_1_458A0(void *,void *,u32,u32);
extern s32 fn_1_45850(void *);
extern u32 fn_1_12860(u32,u32);
extern u32 fn_1_12F78(void *,u32);
extern void DCFlushRange(void *,u32);
extern void fn_1_4877C(void);
typedef enum { GX_TF_I4, GX_TF_I8, GX_TF_IA4, GX_TF_IA8, GX_TF_RGB565, GX_TF_RGB5A3, GX_TF_RGBA8, GX_TF_CMPR=14 } GXTexFmt;
typedef struct { u32 dummy[8]; } GXTexObj;
typedef enum { GX_CLAMP, GX_REPEAT, GX_MIRROR, GX_MAX_TEXWRAPMODE } GXTexWrapMode;
extern void GXInitTexObj(GXTexObj *,void *,u16,u16,GXTexFmt,GXTexWrapMode,GXTexWrapMode,u8);
extern void GXInvalidateTexAll(void);
typedef struct {
 u32 unk_0;
 u32 unk_4[1];
 u8 pad_8[0x18];
 u32 unk_20;
 u8 unk_24;
 u8 pad_25[3];
} Obj_1_47AD4_Arg0;
typedef struct { u32 unk_0; u8 pad_4[0x58]; } Sig_1_47AD4_Info;
typedef struct { u32 unk_0; u32 unk_4; u16 unk_8; u16 unk_A; } Tex_1_47AD4_Entry;
#pragma opt_common_subs off
s32 fn_1_47AD4(Obj_1_47AD4_Arg0 *arg0,s32 arg1,s32 arg2,s32 arg3) {
 Tex_1_47AD4_Entry *entry;
 Sig_1_47AD4_Info info;
 u32 dst;
 u32 hdr;
 u32 arena;
 const char *name;
 u32 sizeA;
 u32 sizeB;
 u32 sizeC;
 u32 handle;
 u32 i;
 u32 tmp;
 s32 len;
 s32 tmp_fn_1_45850;
 fn_8006FDEC();
 name=(const char *)(*((lbl_801A66B4) + (arg0->unk_4)));
 if(fn_1_45730((void *)name,&info)==0) return 0;
 if(arg1==0) *(&lbl_1_data_6CA0.unk_0+arg1*3)=lbl_801A6410;
 handle=*(&lbl_1_data_6CA0.unk_0+arg1*3);
 len=(s32)strlen(name);
 if(len>=3 && (len += (u32)name, strncmp((const char *)len-3,(const char *)&".lz",3)==0)) {
  if(fn_1_458A0(&info,lbl_1_bss_3E000,0x20,0)<0) return 0;
  sizeA=(__lwbrx(lbl_1_bss_3E000,0)+0x27)&~0x1F;
  sizeB=(__lwbrx(lbl_1_bss_3E000,4)+0x1F)&~0x1F;
  if(arg3!=0) {
   if(arg2!=0) {
    arena=OSGetArenaHi();
    dst=fn_8000B334(sizeB+0x10,0x20);
    tmp=fn_8000B360(sizeA,0x20);
   } else dst=(u32)fn_1_45D0(handle,sizeB+0x10,lbl_1_data_1A368,0x12F);
  } else dst=arg0->unk_20;
  hdr=(dst+0x2F)&~0x1F;
  if(arg2!=0) {
   if(fn_1_458A0(&info,(void *)tmp,sizeA,0)<0) return 0;
   tmp_fn_1_45850 = fn_1_45850(&info);
   if(tmp_fn_1_45850==0) return 0;
   fn_1_12860(tmp,hdr);
  } else if(fn_1_12F78((void *)name,hdr)==0) return 0;
  DCFlushRange((void *)hdr,sizeB);
  if(arg2!=0) OSSetArenaHi(arena);
 } else {
  sizeC=(fn_1_45B2C(&info)+0x1F)&~0x1F;
  if(arg3!=0) {
   if(arg2!=0) dst=fn_8000B334(sizeC+0x20,0x20);
   else dst=(u32)fn_1_45D0(handle,sizeC+0x20,lbl_1_data_1A368,0x156);
  } else dst=arg0->unk_20;
  hdr=(dst+0x2F)&~0x1F;
  fn_1_458A0(&info,(void *)hdr,sizeC,0);
  tmp_fn_1_45850 = fn_1_45850(&info);
  tmp_fn_1_45850;
 }
 *(u32 *)dst=*(u32 *)hdr;
 *(u32 *)(dst+4)=hdr+4;
 if(arg2!=0) *(u32 *)(dst+0xC)=fn_8000B334(*(u32 *)dst<<5,0x20);
 else *(u32 *)(dst+0xC)=(u32)fn_1_45D0(handle,*(u32 *)dst<<5,lbl_1_data_1A368,0x168);
 for(i=0;i<*(u32 *)dst;i++) {
  u32 flags;
  u8 *data;
  entry=(Tex_1_47AD4_Entry *)(*(u32 *)(dst+4)+i*0x10);
  flags=entry->unk_0;
  data=(u8 *)hdr+entry->unk_4;
  if((flags&0x100)==0 && entry->unk_8!=0 && entry->unk_A!=0)
   GXInitTexObj((GXTexObj *)(*(u32 *)(dst+0xC)+i*0x20),data,entry->unk_8,entry->unk_A,(GXTexFmt)(flags&0x1F),GX_CLAMP,GX_CLAMP,0);
 }
 GXInvalidateTexAll();
 arg0->unk_24=(u8)arg1;
 arg0->unk_0=1;
 arg0->unk_20=dst;
 fn_1_4877C();
 return 1;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_47AD4 */

/* fzgx:begin fn_1_485E8 */
// Find the resource matching value, load its data, and return the destination buffer.
void *fn_1_485E8(s32 index, s32 value) {
    s32 entry = 0;

    while (((s16 **)lbl_1_data_19FC4)[index][entry] != -1) {
        if (((s16 **)lbl_1_data_19FC4)[index][entry] == value) {
            fn_80083DB0(lbl_1_bss_3E024,
                        ((void ***)lbl_1_data_19098)[index][entry]);
            return lbl_1_bss_3E024;
        }
        entry++;
    }

    fn_80083DB0(lbl_1_bss_3E024, lbl_1_data_1A3AC);
    return lbl_1_bss_3E024;
}
/* fzgx:end fn_1_485E8 */
