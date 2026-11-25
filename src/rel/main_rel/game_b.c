#include "types.h"
#include "rel/main_rel/globals.h"

typedef struct RelocData {
    u32 count;
    u32 values[1];
} RelocData;

typedef struct StringTable {
    u32 count;
    char *strings;
} StringTable;

extern void fn_1_48B0(u32 size, u32 align);
extern u32 fn_80070DE0(u32 callback);
extern void *fn_1_D3884(char *path);
extern void *fn_1_D358C(char *path, void *texture);
extern void fn_1_465D0(char *path, u32 flag);
extern void fn_800711A8(Obj_1_bss_38458_Target *model);
extern void fn_80071718(void *texture);
extern int sprintf(char *buffer, const char *format, ...);
extern s32 DVDConvertPathToEntrynum(char *path);
extern u32 strlen(const char *s);
extern int strcmp(const char *a, const char *b);
extern u32 lbl_801A6CE0;

char *lbl_1_data_66A0[8] = {
    "init/ptnfz",
    "init/sel",
    "init/race",
    "init/custom",
    "init/operation",
    "init/operation_us",
    "init/story",
    NULL,
};

u32 lbl_1_bss_38450;
u32 lbl_1_bss_38454;
Obj_1_bss_38458_Target *lbl_1_bss_38458;
u32 lbl_1_bss_3845C;
u32 lbl_1_bss_38460[7];
s32 lbl_1_bss_3847C[7];
void *lbl_1_bss_38498[7];
u32 lbl_1_bss_384B4;

void fn_1_41134(u32 index, char *name);
void fn_1_411D4(u32 index, char *name);
void fn_1_412A0(u32 index);

/* fzgx:begin fn_1_40F54 */
// Initializes the related game state with the standard allocation size.
void fn_1_40F54(void *arg0) {
    fn_1_48B0((u32)arg0, 0x20);
}
/* fzgx:end fn_1_40F54 */

/* fzgx:begin fn_1_40F78 */
// Initializes the shared resource handles when the subsystem is enabled.
void fn_1_40F78(void) {
    u32 previous;
    void *decoded_data;
    if ((lbl_801A6CE0 & 1) == 0) {
        lbl_1_bss_38450 = 0;
        lbl_1_bss_38454 = 0;
        return;
    }
    previous = fn_80070DE0((u32)fn_1_40F54);
    decoded_data = fn_1_D3884("init/common.tpl");
    lbl_1_bss_38450 = (u32)decoded_data;
    lbl_1_bss_38454 = (u32)fn_1_D358C("init/common.gma", decoded_data);
    fn_80070DE0(previous);
}
/* fzgx:end fn_1_40F78 */

/* fzgx:begin fn_1_4100C */
// Initializes both shared data blocks with their default state.
void fn_1_4100C(void) {
    fn_1_465D0("init/efcmdl.tpl", 1);
    fn_1_465D0("init/efcmdl.gma", 1);
}
/* fzgx:end fn_1_4100C */

/* fzgx:begin fn_1_41048 */
void fn_1_41048(void) {
    void *value;
    if (lbl_1_bss_38458 == 0) {
        value = fn_1_D3884("init/efcmdl.tpl");
        lbl_1_bss_3845C = (u32)value;
        lbl_1_bss_38458 = (Obj_1_bss_38458_Target *)fn_1_D358C("init/efcmdl.gma", value);
    }
}
/* fzgx:end fn_1_41048 */

/* fzgx:begin fn_1_410A0 */
void fn_1_410A0(void) {
    if (lbl_1_bss_38458 != 0) {
        fn_800711A8(lbl_1_bss_38458);
        lbl_1_bss_38458 = 0;
    }
    if (lbl_1_bss_3845C != 0) {
        fn_80071718((void *)lbl_1_bss_3845C);
        lbl_1_bss_3845C = 0;
    }
}
/* fzgx:end fn_1_410A0 */

/* fzgx:begin fn_1_41104 */
// Forwards the selected message entry to the formatter.
void fn_1_41104(u32 index) {
    fn_1_41134(index, lbl_1_data_66A0[index]);
}
/* fzgx:end fn_1_41104 */

/* fzgx:begin fn_1_41134 */
// Format the value with each registered template and publish both results.
void fn_1_41134(u32 index, char *name) {
    char buffer[128];
    sprintf(buffer, "%s.tpl", name);
    fn_1_465D0(buffer, 1);
    sprintf(buffer, "%s.gma", name);
    fn_1_465D0(buffer, 1);
}
/* fzgx:end fn_1_41134 */

/* fzgx:begin fn_1_411A4 */
// Forwards the indexed message entry to the follow-up handler.
void fn_1_411A4(u32 index) {
    fn_1_411D4(index, lbl_1_data_66A0[index]);
}
/* fzgx:end fn_1_411A4 */

/* fzgx:begin fn_1_411D4 */
void fn_1_411D4(u32 index, char *name) {
    char tpl_path[128];
    char gma_path[128];
    s32 entry;
    sprintf(gma_path, "%s.gma", name);
    entry = DVDConvertPathToEntrynum(gma_path);
    if (lbl_1_bss_38460[index] == 0 || lbl_1_bss_3847C[index] != entry) {
        fn_1_412A0(index);
        lbl_1_bss_3847C[index] = entry;
        sprintf(tpl_path, "%s.tpl", name);
        lbl_1_bss_38498[index] = fn_1_D3884(tpl_path);
        lbl_1_bss_38460[index] = (u32)fn_1_D358C(gma_path, lbl_1_bss_38498[index]);
    }
}
/* fzgx:end fn_1_411D4 */

/* fzgx:begin fn_1_412A0 */
void fn_1_412A0(u32 index) {
    if (lbl_1_bss_38498[index] != 0) {
        fn_80071718(lbl_1_bss_38498[index]);
    }
    if (lbl_1_bss_38460[index] != 0) {
        fn_800711A8((Obj_1_bss_38458_Target *)lbl_1_bss_38460[index]);
    }
    lbl_1_bss_38498[index] = 0;
    lbl_1_bss_38460[index] = 0;
    lbl_1_bss_3847C[index] = -1;
}
/* fzgx:end fn_1_412A0 */

/* fzgx:begin fn_1_41328 */
void fn_1_41328(RelocData *data) {
    u32 *values = data->values;
    u32 count = data->count;
    u32 i = 0;

    if (count & ((u32)1 << 31)) {
        return;
    }

    for (i = 0; i <= count; i++) {
        values[i] += (u32)data;
    }

    data->count |= ((u32)1 << 31);
}
/* fzgx:end fn_1_41328 */

/* fzgx:begin fn_1_41418 */
char *fn_1_41418(StringTable *table, u32 index) {
    u32 count = table->count & 0x7fffffff;
    char *str = table->strings;

    if (index >= count) {
        return 0;
    }

    while (index != 0) {
        str += strlen(str) + 1;
        index -= 1;
    }

    return str;
}
/* fzgx:end fn_1_41418 */

/* fzgx:begin fn_1_41488 */
int fn_1_41488(StringTable *table, const char *value) {
    u32 count = table->count & 0x7fffffff;
    char *str = table->strings;
    u32 index = 0;

    while (index < count) {
        if (strcmp(value, str) == 0) {
            return index;
        }
        str += strlen(str) + 1;
        index += 1;
    }

    return -1;
}
/* fzgx:end fn_1_41488 */
