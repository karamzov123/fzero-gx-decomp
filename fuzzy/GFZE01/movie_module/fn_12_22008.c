/* Non-matching: best partial attempt (98.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieObject MovieObject;
typedef struct MovieVtable MovieVtable;
typedef void (*MovieGetRange)(MovieObject *, int, int, void *);
typedef void (*MovieSetRange)(MovieObject *, int, void *);
typedef int (*MovieGetValue)(MovieObject *, int);

struct MovieVtable {
    char pad0[0x18];
    MovieGetRange get_range;
    MovieSetRange set_range2;
    MovieSetRange set_range;
    MovieGetValue get_value;
};

struct MovieObject {
    MovieVtable *vtable;
};

typedef struct MovieState {
    char pad0[4];
    MovieObject *object;
    char pad1[0x10];
    u32 lower;
    u32 upper;
    char pad2[4];
    int progress;
} MovieState;

typedef struct MovieEntry {
    char pad0[4];
    MovieObject *object;
    char pad1[0x10];
    u32 lower;
    u32 upper;
    char pad2[4];
    int progress;
} MovieEntry;

extern void fn_12_24970(void *);
extern int fn_12_24A88(void *, int);
extern void fn_12_24950(void *);

static inline int fn_12_22008_call_fn_12_24A88(void * a0, int a1) { return fn_12_24A88(a0, a1); }

#pragma opt_common_subs off
int fn_12_22008(void *module, int index, int amount, u32 lab_unused0, u32 lab_unused1) {
    MovieVtable * fzgx_live;
    u32 range1[2];
    u32 range2[2];
    u32 range3[2];
    u32 range4[2];
    u32 movie[1];
    MovieEntry *entry;
    MovieObject *object;
    int result;
    int value;
    u32 position;
    int value_2;

    entry = (MovieEntry *)((u8 *)module + index * 0x74 + 0x1150);
    object = *(MovieObject **)((((u8 *)module) + ((index * 0x74) + (0x1154))));
    result = 0;
    if (amount == 0) {
        return result;
    }
    if (*(int *)((((u8 *)module) + ((index * 0x74) + (0x1144)))) == 0 || object == 0) {
        result = 0;
    } else {
        fn_12_24970(movie);
        object->vtable->get_range(object, 1, amount, range1);
        object->vtable->set_range(object, 0, range1);
        if ((s32)(*((range1) + (1))) < amount) {
            value = amount - (*((range1) + (1)));
            object->vtable->get_range(object, 1, value, range2);
            object->vtable->set_range(object, 0, range2);
            if ((s32)(*((range2) + (1))) < value) {
                result = fn_12_22008_call_fn_12_24A88(module, 0xff00040b);
            }
        }
        if (index == 1) {
            object = entry->object;
            value_2 = object->vtable->get_value(object, 1);
            object->vtable->get_range(object, 1, 0x7fffffff, range4);
            if ((s32)(*((range4) + (1))) < value_2) {
                object->vtable->get_range(object, 1, 0x7fffffff, range3);
                object->vtable->set_range2(object, 1, range3);
            } else {
                range3[0] = 0;
                range3[1] = 0;
            }
            fzgx_live = object->vtable;
            fzgx_live->set_range2(object, 1, range4);
            position = entry->lower;
            if (position < (*((range4) + (0))) ||
                position >= (*((range4) + (0))) + (*((range4) + (1)))) {
                if (position < (*((range3) + (0))) ||
                    position >= (*((range3) + (0))) + (*((range3) + (1)))) {
                    entry->lower = 0;
                    entry->upper = 0;
                }
            }
        }
        if (entry->progress >= 0) {
            entry->progress += amount;
        }
        *(int *)((u8 *)module + 0x44) = 1;
        fn_12_24950(movie);
    }
    return result;
}
#pragma opt_common_subs reset

