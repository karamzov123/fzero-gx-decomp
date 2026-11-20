#include "types.h"


/* --- dol/fn_8005BE48.c --- */
/* --- dol/fn_8005BE48.c --- */
extern u32 fn_8005A614(void);

void fn_8005BE48(void) {
    fn_8005A614();
}

/* --- dol/fn_8005BE68.c --- */
/* --- dol/fn_8005BE68.c --- */
u32 fn_8005BE68(u32 arg0) {
    u32 v0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = 0;
    return v0;
    }
    v0 = *(u32 *)((u8 *)v0 + 8);
    return v0;
}

/* --- dol/fn_8005BE80.c --- */
typedef struct {
    int unk00;
    int unk04;
} Fn8005BE80Object;

int fn_8005BE80(Fn8005BE80Object* object) {
    if (object == 0) {
        return 0;
    }
    return object->unk04;
}

/* --- dol/fn_8005BE98.c --- */
struct fn_8005BE98_Arg0 {
    u32 unk_0;
};

void fn_8005BE98(struct fn_8005BE98_Arg0 *arg0) {
    if (arg0 == 0) { return; }
    arg0->unk_0 = 0;
}

/* --- dol/RNARES_Create.c --- */
typedef struct RNAResource {
    int used;
    u32 buffer;
    u32 size;
} RNAResource;

void fn_8005A5BC(const char *message);

extern RNAResource lbl_80192BE4[32];

RNAResource *RNARES_Create(void) {
    int i;
    RNAResource *resource;
    for (i = 0; i < 32; i++) {
        if (lbl_80192BE4[i].used == 0) {
            break;
        }
    }
    if (i == 32) {
        fn_8005A5BC("E1070313:Not enough RNARES handle.\n");
        return 0;
    }
    resource = &lbl_80192BE4[i];
    resource->used = 1;
    return resource;
}

/* --- dol/fn_8005BFB4.c --- */
typedef struct RNAResEntry {
    s32 used;
    u32 unk_4;
    u32 unk_8;
} RNAResEntry;

typedef struct fn_8005BFB4_Globals {
    u32 count;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    RNAResEntry entries[32];
} fn_8005BFB4_Globals;

extern fn_8005BFB4_Globals lbl_80192BD0;
extern u32 ARFree(u32 *);
extern void fn_8005A5BC(const char *message);
extern char lbl_800929AC[43];
extern void *memset(void *, int, u32);

void fn_8005BFB4(void) {
    fn_8005BFB4_Globals *p;
    RNAResEntry *e;
    u32 stamp;
    u32 zero;
    u32 i;
    u32 k;
    u32 j;

    p = &lbl_80192BD0;
    if (--p->count == 0) {
        e = &p->entries[0];
        zero = 0;
        for (i = 0; i < 32; i++) {
            if (e->used == 1 && e != 0) {
                e->used = zero;
            }
            e++;
        }
        e = &p->entries[0];
        memset(e, 0, 0x180);
        if (((0) == (p->unk_4))) {
            ARFree(&stamp);
            if (stamp != p->unk_C) {
                fn_8005A5BC(lbl_800929AC);
            }
            p->unk_8 = 0;
            p->unk_C = 0;
            p->unk_10 = 0;
        }
    }
}
