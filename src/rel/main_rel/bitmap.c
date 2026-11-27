#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bitmap.h"

extern s32 lbl_801A6410;
extern u32 lbl_801A66B4;
extern u8 lbl_1_bss_3E000[32];
extern u32 lbl_1_bss_3E020;
extern u8 lbl_1_bss_3E024[52];
extern char lbl_1_data_1A364[4];
extern char lbl_1_data_1A3AC[5];
extern u8 lbl_1_data_19098[0x2F0];
extern u8 lbl_1_data_19FC4[0x2F0];
extern f32 lbl_1_rodata_10C0[5];
extern f32 lbl_1_bss_3E05C;

extern void OSPanic(const void *, ...);
extern void fn_1_465D0(char *, s32);
extern int fn_1_45D0();
extern int fn_80008F88(int, int);
extern void fn_8006FDEC(void);
extern void fn_80009064(u32 value);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, s32 arg3);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);
extern void strcpy(void *arg0, void *arg1);
extern s32 fn_1_45730(void *, void *);
extern size_t strlen(const char *);
extern s32 strncmp(const char *, const char *, size_t);
extern u32 OSGetArenaHi(void);
extern void OSSetArenaHi(u32);
extern u32 OSAllocFromArenaLo(u32, u32);
extern u32 OSAllocFromArenaHi(u32, u32);
extern s32 fn_1_45B2C(void *);
extern s32 fn_1_458A0(void *, void *, u32, u32);
extern s32 fn_1_45850(void *);
extern u32 fn_1_12860(u32, u32);
extern u32 fn_1_12F78(void *, u32);
extern void DCFlushRange(void *, u32);

typedef enum { GX_TF_I4, GX_TF_I8, GX_TF_IA4, GX_TF_IA8, GX_TF_RGB565, GX_TF_RGB5A3, GX_TF_RGBA8, GX_TF_CMPR=14 } GXTexFmt;
typedef struct { u32 dummy[8]; } GXTexObj;
typedef enum { GX_CLAMP, GX_REPEAT, GX_MIRROR, GX_MAX_TEXWRAPMODE } GXTexWrapMode;
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, GXTexFmt, GXTexWrapMode, GXTexWrapMode, u8);
extern void GXInvalidateTexAll(void);

s32 fn_1_47AD4(BitmapResource *arg0, s32 arg1, s32 arg2, s32 arg3);
void fn_1_48214(s32 index, s32 enabled);
void fn_1_48418(int index);
void fn_1_484CC(s32 index);
void *fn_1_48730(u32 value);
void fn_1_4877C(void);

/* fzgx:begin fn_1_47AD4 */
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
s32 fn_1_47AD4(BitmapResource *arg0_bmp,s32 arg1,s32 arg2,s32 arg3) {
 Obj_1_47AD4_Arg0 *arg0 = (Obj_1_47AD4_Arg0 *)arg0_bmp;
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
 name=(const char *)(*((lbl_801A66B4) + arg0->unk_4));
 if(fn_1_45730((void *)name,&info)==0) return 0;
 if(arg1==0) *(&lbl_1_data_6CA0.unk_0+arg1*3)=lbl_801A6410;
 handle=*(&lbl_1_data_6CA0.unk_0+arg1*3);
 len=strlen(name);
 if(len>=3 && (len += (u32)name, strncmp((const char *)len-3,lbl_1_data_1A364,3)==0)) {
  if(fn_1_458A0(&info,lbl_1_bss_3E000,0x20,0)<0) return 0;
  sizeA=(__lwbrx(lbl_1_bss_3E000,0)+0x27)&~0x1F;
  sizeB=(__lwbrx(lbl_1_bss_3E000,4)+0x1F)&~0x1F;
  if(arg3!=0) {
   if(arg2!=0) {
    arena=OSGetArenaHi();
    dst=OSAllocFromArenaLo(sizeB+0x10,0x20);
    tmp=OSAllocFromArenaHi(sizeA,0x20);
   } else dst=fn_1_45D0(handle,sizeB+0x10,(const unsigned char *)lbl_1_data_1A368,0x12F);
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
   if(arg2!=0) dst=OSAllocFromArenaLo(sizeC+0x20,0x20);
   else dst=fn_1_45D0(handle,sizeC+0x20,(const unsigned char *)lbl_1_data_1A368,0x156);
  } else dst=arg0->unk_20;
  hdr=(dst+0x2F)&~0x1F;
  fn_1_458A0(&info,(void *)hdr,sizeC,0);
  tmp_fn_1_45850 = fn_1_45850(&info);
  tmp_fn_1_45850;
 }
 *(u32 *)dst=*(u32 *)hdr;
 *(u32 *)(dst+4)=hdr+4;
 if(arg2!=0) *(u32 *)(dst+0xC)=OSAllocFromArenaLo(*(u32 *)dst<<5,0x20);
 else *(u32 *)(dst+0xC)=fn_1_45D0(handle,*(u32 *)dst<<5,(const unsigned char *)lbl_1_data_1A368,0x168);
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
 arg0->unk_24=arg1;
 arg0->unk_0=1;
 arg0->unk_20=dst;
 fn_1_4877C();
 return 1;
}
/* fzgx:end fn_1_47AD4 */

/* fzgx:begin fn_1_47E54 */
void fn_1_47E54(s32 index) {
    s32 valid;

    if (index > 0xbb) {
        valid = 0;
    } else {
        valid = index >= 0;
    }
    if (valid == 0) {
        OSPanic(lbl_1_data_1A368, 0x18c, lbl_1_data_1A374);
    }
    fn_1_465D0(lbl_1_data_FCD4[index].paths[lbl_801A66B4], 1);
}
/* fzgx:end fn_1_47E54 */

/* fzgx:begin fn_1_47EE4 */
void fn_1_47EE4(s32 index) {
    BitmapResource *object;
    s32 valid;

    object = &lbl_1_data_FCD4[index];
    if (index > 0xbb) {
        valid = 0;
    } else {
        valid = index >= 0;
    }
    if (valid == 0) {
        OSPanic(lbl_1_data_1A368, 0x1a8, lbl_1_data_1A374);
    }
    if (object->loaded == 0) {
        fn_1_47AD4(object, 0, 1, 1);
    }
}
/* fzgx:end fn_1_47EE4 */

/* fzgx:begin fn_1_47F74 */
void fn_1_47F74(s32 index) {
    BitmapResource *object;
    s32 valid;

    object = &lbl_1_data_FCD4[index];
    if (index > 0xbb) {
        valid = 0;
    } else {
        valid = index >= 0;
    }
    if (valid == 0) {
        OSPanic(lbl_1_data_1A368, 0x1b5, lbl_1_data_1A374);
    }
    if (object->loaded == 0) {
        fn_1_47AD4(object, 0, 0, 1);
    }
}
/* fzgx:end fn_1_47F74 */

/* fzgx:begin fn_1_48004 */
void fn_1_48004(s32 index, s32 image) {
    BitmapResource *entry;
    s32 valid;

    entry = &lbl_1_data_FCD4[index];
    if (index > 0xbb) {
        valid = 0;
    } else {
        valid = index >= 0;
    }
    if (valid == 0) {
        OSPanic(lbl_1_data_1A368, 0x1c5, lbl_1_data_1A374);
    }
    if (entry->loaded == 0) {
        if (image == 0) {
            if (index > 0xbb) {
                valid = 0;
            } else {
                valid = index >= 0;
            }
            if (valid == 0) {
                OSPanic(lbl_1_data_1A368, 0x1b5, lbl_1_data_1A374);
            }
            if (entry->loaded == 0) {
                fn_1_47AD4(entry, 0, 0, 1);
            }
        } else {
            fn_1_48418(image);
            fn_1_47AD4(entry, image, 0, 1);
        }
    }
}
/* fzgx:end fn_1_48004 */

/* fzgx:begin fn_1_4811C */
// Enables the bitmap entry identified by the caller.
void fn_1_4811C(int arg) {
    fn_1_48214(arg, 1);
}
/* fzgx:end fn_1_4811C */

/* fzgx:begin fn_1_48140 */
// Disables the bitmap entry supplied by the caller.
void fn_1_48140(int index) {
    fn_1_48214(index, 0);
}
/* fzgx:end fn_1_48140 */

/* fzgx:begin fn_1_48164 */
// Enables matching bitmap entries in the shared bitmap table.
void fn_1_48164(int value) {
    s16 index;
    BitmapResource *entry;

    index = 1;
    entry = &lbl_1_data_FCD4[1];
    for (; index < 0xbc; index++, entry++) {
        if (entry->loaded != 0 && entry->heap == value) {
            fn_1_48214(index, 1);
        }
    }
}
/* fzgx:end fn_1_48164 */

/* fzgx:begin fn_1_481E8 */
// Initializes the bitmap entry and refreshes the related bitmap state.
void fn_1_481E8(int arg0) {
    fn_1_48214(arg0, 0);
    fn_1_4DDC0();
    fn_1_4F724();
}
/* fzgx:end fn_1_481E8 */

/* fzgx:begin fn_1_48214 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    s32 unk_8;
} BitmapEntry;

// Iterates texture records in a range, tearing down bitmap references and
// releasing dependent texture state.
void fn_1_48214(s32 index, s32 enabled) {
    int found;
    s32 n;
    s16 i;
    s16 end;
    BitmapResource *record;

    fn_8006FDEC();

    if (index == 0xbc) {
        i = 1;
        end = 0xbc;
    } else {
        s32 low;
        if (index >= 1) {
            low = index;
        } else {
            low = 1;
        }
        i = low;
        end = (index + 1);
    }

    record = &lbl_1_data_FCD4[i];

    while (i < end) {
        if (record->loaded != 0) {
            if (record->heap == 0) {
                fn_1_46B4(lbl_801A6410, (u32)record->images->textures,
                          (char *)lbl_1_data_1A368, 0x21e);
                fn_1_46B4(lbl_801A6410, (u32)record->images,
                          (char *)lbl_1_data_1A368, 0x21f);
                record->loaded = 0;
            } else {
                BitmapEntry *bitmap =
                    (BitmapEntry *)((u8 *)&lbl_1_data_6CA0 +
                                    record->heap * 12);

                fn_1_46B4(bitmap->unk_0, (u32)record->images->textures,
                          (char *)lbl_1_data_1A368, 0x223);
                fn_1_46B4(bitmap->unk_0, (u32)record->images,
                          (char *)lbl_1_data_1A368, 0x224);
                record->loaded = 0;
                if (enabled == 0) {
                    found = 0;
                    for (n = 0; n < 0xbc; n++) {
                        BitmapResource *scan;
                        u8 sc;
                        u8 rc;

                        scan = &lbl_1_data_FCD4[n];
                        if (scan->loaded != 0) {
                            sc = scan->heap;
                            rc = record->heap;
                            if (sc == rc) {
                                found = 1;
                            }
                        }
                    }
                    if (found == 0) {
                        fn_1_484CC(record->heap);
                    }
                }
            }
        }
        i++;
        record++;
    }
}
/* fzgx:end fn_1_48214 */

/* fzgx:begin fn_1_48418 */
typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
} BitmapSlot;

void fn_1_48418(int index) {
    BitmapSlot *obj = (BitmapSlot *)&lbl_1_data_6CA0 + index;
    int valid;
    if (index > 2) {
        valid = 0;
    } else {
        valid = index >= 0;
    }
    if (valid == 0) {
        OSPanic(lbl_1_data_1A368, 0x248, lbl_1_data_1A390);
    }
    if (obj->unk_0 == -1) {
        obj->unk_4 = fn_1_45D0(lbl_801A6410, obj->unk_8, lbl_1_data_1A368, 0x250);
        obj->unk_0 = fn_80008F88(obj->unk_4, obj->unk_4 + obj->unk_8);
    }
}
/* fzgx:end fn_1_48418 */

/* fzgx:begin fn_1_484CC */
// Releases a bitmap and invalidates dependent texture records.
void fn_1_484CC(s32 index) {
    BitmapResource *texture_record;
    s16 texture_index;
    u32 *bitmap_entry;

    bitmap_entry = (u32 *)((u8 *)&lbl_1_data_6CA0 + index * 12);
    if (*(s32 *)bitmap_entry == -1) {
        return;
    }

    fn_8006FDEC();
    texture_index = 1;
    texture_record = &lbl_1_data_FCD4[1];
    while (texture_index < 188) {
        if (texture_record->loaded != 0 && texture_record->heap == index) {
            fn_1_48214(texture_index, 1);
        }
        texture_index++;
        texture_record++;
    }

    fn_80009064(bitmap_entry[0]);
    fn_1_46B4(lbl_801A6410, bitmap_entry[1],
              (char *)lbl_1_data_1A368, 0x265);
    bitmap_entry[0] = (u32)-1;
}
/* fzgx:end fn_1_484CC */

/* fzgx:begin fn_1_485A8 */
u32 fn_1_485A8(s32 index) {
    return lbl_1_data_FCD4[index].loaded != 0;
}
/* fzgx:end fn_1_485A8 */

/* fzgx:begin fn_1_485C8 */
void fn_1_485C8(u32 arg0) {
    lbl_1_bss_3E020 = (u32)lbl_1_data_FCD4[arg0].images;
}
/* fzgx:end fn_1_485C8 */

/* fzgx:begin fn_1_485E8 */
// Find the resource matching value, load its data, and return the destination buffer.
void *fn_1_485E8(s32 index, s32 value) {
    s32 entry = 0;

    while (((s16 **)lbl_1_data_19FC4)[index][entry] != -1) {
        if (((s16 **)lbl_1_data_19FC4)[index][entry] == value) {
            strcpy(lbl_1_bss_3E024,
                        ((void ***)lbl_1_data_19098)[index][entry]);
            return lbl_1_bss_3E024;
        }
        entry++;
    }

    strcpy(lbl_1_bss_3E024, lbl_1_data_1A3AC);
    return lbl_1_bss_3E024;
}
/* fzgx:end fn_1_485E8 */

/* fzgx:begin fn_1_48690 */
// Return the current bitmap width, or the default width when no bitmap is active.
u16 fn_1_48690(u32 unused) {
    void *bitmap = fn_1_48730(unused);

    if (bitmap != 0) {
        return *(u16 *)((u8 *)bitmap + 8);
    }

    return 8;
}
/* fzgx:end fn_1_48690 */

/* fzgx:begin fn_1_486C4 */
// Return the current bitmap height, or the default height when no bitmap is active.
u16 fn_1_486C4(u32 value) {
    void *bitmap = fn_1_48730(value);

    if (bitmap != 0) {
        return *(u16 *)((u8 *)bitmap + 0xA);
    }
    return 8;
}
/* fzgx:end fn_1_486C4 */

/* fzgx:begin fn_1_486F8 */
// Return the bitmap entry flags for the slot identified by value.
u32 fn_1_486F8(u32 value) {
    void *bitmap = fn_1_48730(value);

    if (bitmap != 0) {
        return *(u32 *)bitmap & 0x1F;
    }
    return 0;
}
/* fzgx:end fn_1_486F8 */

/* fzgx:begin fn_1_48730 */
// Look up the bitmap data for the table and slot encoded in value.
void *fn_1_48730(u32 value) {
    u32 table_index = (value >> 8) & 0xffff;
    u32 slot_index = value & 0xff;
    BitmapResource *entry = &lbl_1_data_FCD4[table_index];

    if (entry != 0 && entry->loaded == 1 && entry->images != 0) {
        return &entry->images->info[(u8)slot_index];
    }
    return 0;
}
/* fzgx:end fn_1_48730 */

/* fzgx:begin fn_1_4877C */
// fn_1_4877C: empty in retail (single blr).
void fn_1_4877C(void) {
}
/* fzgx:end fn_1_4877C */

/* fzgx:begin fn_1_48780 */
void fn_1_48780(void) {
    BitmapResource *obj;
    int i;

    obj = &lbl_1_data_FCD4[1];
    for (i = 1; i < 0xBC; i++) {
        if (obj->loaded != 0) {
            fn_1_47AD4(obj, obj->heap, 0, 0);
        }
        obj++;
    }
}
/* fzgx:end fn_1_48780 */
