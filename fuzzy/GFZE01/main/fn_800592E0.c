/* Non-matching: best partial attempt (92.57% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

typedef void (*Callback)(u32);
typedef void (*ErrorCallback)(u32, void *);
typedef struct { u32 function; u32 argument; } CallbackSlot;
typedef struct { u32 a; u32 b; } Entry;
typedef struct { Entry entries[6]; } Row;
#pragma opt_propagation off
static void invoke(u32 address) { CallbackSlot *slot = (CallbackSlot *)address; ((Callback)slot->function)(*(u32 *)(address + 4)); }
static void invokeError(u32 address, void *message) { CallbackSlot *slot = (CallbackSlot *)address; ((ErrorCallback)slot->function)(*(u32 *)(address + 4), message); }
#define invoke(slot) invoke((u32)(slot))
#define invokeError(slot, message) invokeError((u32)(slot), message)
extern char lbl_800924A4[32];
extern u8 lbl_80092384[288];
extern void strncpy(void *, void *, int);
extern u32 SVM_CallErr(u32, ...);

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_800592E0(s32 arg0, s32 arg1) {
    Obj_8018FEB0 *p = (Obj_8018FEB0 *)&lbl_8018FEB0;
    if (arg1 < 0 || arg1 >= 6) {
        strncpy((u8 *)p + 0x30, lbl_800924A4, 127);
        if (((CallbackSlot *)((u8 *)p + 0xB0))->function != 0) {
            invokeError((CallbackSlot *)((u8 *)p + 0xB0), (u8 *)p + 0x30);
        }
    }
    if (((CallbackSlot *)((u8 *)p + 0xC0))->function != 0) {
        invoke((CallbackSlot *)((u8 *)p + 0xC0));
        if ((s32)p->unk_4 == 0) p->unk_8 = 1;
        p->unk_4++;
    }
    {
        u8 *table = (u8 *)p + 0x108;
        u32 finish = ((CallbackSlot *)((u8 *)p + 0xB8))->function;
        *(u32 *)(table + (arg0 * 0x30 + arg1 * 8)) = 0;
        ((Row *)table)[arg0].entries[arg1].b = 0;
    if (finish != 0) {
        p->unk_4--;
        if ((s32)((volatile Obj_8018FEB0 *)p)->unk_4 == 0) {
            if ((s32)p->unk_8 != 1) SVM_CallErr((u32)lbl_80092384, ((volatile Obj_8018FEB0 *)p)->unk_8, 1);
            p->unk_8 = 0;
        }
        invoke((CallbackSlot *)((u8 *)p + 0xB8));
    }
    }
}
