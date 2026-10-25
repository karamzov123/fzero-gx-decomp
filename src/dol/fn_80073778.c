#include "types.h"
#include "dol/globals.h"

typedef struct {
    u8 pad_00[0x20];
    u16 width;
    u16 height;
} TexEntry;

extern u16 GXGetTexObjWidth(void *obj);
extern u16 GXGetTexObjHeight(void *obj);
extern void GXLoadTexObj(void *obj, s32 index);

void fn_80073778(void *obj, s32 index) {
    TexEntry *entry;

    entry = (TexEntry *)(lbl_801A6D38 + index * 0x24 + 0x720);
    entry->width = GXGetTexObjWidth(obj);
    entry->height = GXGetTexObjHeight(obj);
    GXLoadTexObj(obj, index);
}
