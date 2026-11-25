#include "types.h"

/* A modified Dolphin SDK OSAlloc: the heap state can be switched between eight saved contexts. */

#define ALIGNMENT 32

#define InRange(cell, arenaStart, arenaEnd) ((u32)arenaStart <= (u32)cell) && ((u32)cell < (u32)arenaEnd)
#define OFFSET(n, a) (((u32)(n)) & ((a) - 1))

typedef struct Cell {
    struct Cell *prev;
    struct Cell *next;
    long size;
    u8 pad_C[0x14];
} Cell;

#define HEADERSIZE ((sizeof(Cell) + ALIGNMENT - 1) & ~(ALIGNMENT - 1))
#define MINOBJSIZE (HEADERSIZE + ALIGNMENT)

typedef struct HeapDesc {
    long size;
    Cell *free;
    Cell *allocated;
} HeapDesc;

typedef struct HeapContext {
    int currHeap;
    HeapDesc *heapArray;
    int numHeaps;
    void *arenaStart;
    void *arenaEnd;
} HeapContext;

extern void OSReport(const char *msg, ...);

extern int lbl_801A6410;            /* __OSCurrHeap */
extern HeapContext lbl_8015BE40[8]; /* saved heap contexts */
extern HeapContext lbl_8015BEE0;    /* the state a context switch displaced */
extern int lbl_801A6730;            /* active context, -1 for none */
extern int lbl_801A6734;
extern void *lbl_801A6738;          /* ArenaEnd */
extern void *lbl_801A673C;          /* ArenaStart */
extern int lbl_801A6740;            /* NumHeaps */
extern HeapDesc *lbl_801A6744;      /* HeapArray */

#define CurrHeap lbl_801A6410
#define HeapArray lbl_801A6744
#define NumHeaps lbl_801A6740
#define ArenaStart lbl_801A673C
#define ArenaEnd lbl_801A6738

void *fn_80009830(int heap, u32 size, const char *file, int line);
void fn_80009AA8(int heap, void *ptr, const char *file, int line);
long fn_80009CD4(void *ptr, u32 size, const char *file, int line);
void fn_80009468(void *arena);
void fn_8000951C(int heap);
void fn_800095A4(void);
int fn_80008FB0(void *start, void *end);

void *fn_80008E34(int heap, u32 size) {
    return fn_80009830(heap, size, "", 0);
}

void fn_80008E5C(int heap, void *ptr) {
    fn_80009AA8(heap, ptr, "", 0);
}

int fn_80008E84(int heap) {
    int prev;

    fn_8000951C(heap);
    prev = CurrHeap;
    CurrHeap = heap;
    fn_800095A4();
    return prev;
}

void *fn_80008EC8(void *arenaStart, void *arenaEnd, int maxHeaps) {
    u32 arraySize;
    int i;
    HeapDesc *hd;
    u8 *end;
    void *start;

    arraySize = maxHeaps * sizeof(HeapDesc);
    HeapArray = arenaStart;
    NumHeaps = maxHeaps;
    for (i = 0; i < NumHeaps; i++) {
        hd = &HeapArray[i];
        hd->size = -1;
        hd->free = hd->allocated = NULL;
    }
    end = (u8 *)HeapArray + arraySize;
    ArenaEnd = (void *)((u32)arenaEnd & ~(ALIGNMENT - 1));
    CurrHeap = -1;
    start = (void *)(((u32)end + ALIGNMENT - 1) & ~(ALIGNMENT - 1));
    ArenaStart = start;
    fn_80009468(end);
    return start;
}

int fn_80008F60(void *start, void *end) {
    lbl_801A6734 = 0;
    return fn_80008FB0(start, end);
}

int fn_80008F88(void *start, void *end) {
    lbl_801A6734 = 1;
    return fn_80008FB0(start, end);
}

#pragma opt_propagation off
int fn_80008FB0(void *start, void *end) {
    int heap;
    HeapDesc *hd;
    Cell *cell;

    fn_8000951C((int)start);
    start = (void *)(((u32)start + ALIGNMENT - 1) & ~(ALIGNMENT - 1));
    end = (void *)((u32)end & ~(ALIGNMENT - 1));
    hd = HeapArray;
    heap = 0;
    while (heap < NumHeaps) {
        if (hd->size < 0) {
            hd->size = (u8 *)end - (u8 *)start;
            cell = (Cell *)start;
            cell->prev = NULL;
            cell->next = NULL;
            cell->size = hd->size;
            hd->free = cell;
            hd->allocated = NULL;
            fn_800095A4();
            return heap;
        }
        hd++;
        heap++;
    }
    fn_800095A4();
    return -1;
}
#pragma opt_propagation reset

void fn_80009064(int heap) {
    fn_8000951C(heap);
    HeapArray[heap].size = -1;
    fn_800095A4();
}

#define CHECK(line, condition)                                          \
    if (!(condition)) {                                                 \
        OSReport("OSCheckHeap: Failed " #condition " in %d", line);     \
        fn_800095A4();                                                  \
        return -1;                                                      \
    }

long fn_800090A4(int heap) {
    HeapDesc *hd;
    Cell *cell;
    long atotal = 0;
    long ftotal = 0;
    long free = 0;
    long total;

    fn_8000951C(heap);
    CHECK(0x350, HeapArray);
    CHECK(0x351, 0 <= heap && heap < NumHeaps);

    hd = &HeapArray[heap];
    CHECK(0x354, 0 <= hd->size);

    CHECK(0x356, hd->allocated == NULL || hd->allocated->prev == NULL);

    for (cell = hd->allocated; cell; cell = cell->next) {
        CHECK(0x359, InRange(cell, ArenaStart, ArenaEnd));
        CHECK(0x35A, OFFSET(cell, ALIGNMENT) == 0);
        CHECK(0x35B, cell->next == NULL || cell->next->prev == cell);
        CHECK(0x35C, MINOBJSIZE <= cell->size);
        CHECK(0x35D, OFFSET(cell->size, ALIGNMENT) == 0);

        atotal += cell->size;
        CHECK(0x360, 0 < atotal && atotal <= hd->size);
    }

    CHECK(0x368, hd->free == NULL || hd->free->prev == NULL);

    for (cell = hd->free; cell; cell = cell->next) {
        CHECK(0x36B, InRange(cell, ArenaStart, ArenaEnd));
        CHECK(0x36C, OFFSET(cell, ALIGNMENT) == 0);
        CHECK(0x36D, cell->next == NULL || cell->next->prev == cell);
        CHECK(0x36E, MINOBJSIZE <= cell->size);
        CHECK(0x36F, OFFSET(cell->size, ALIGNMENT) == 0);
        CHECK(0x370, cell->next == NULL || (char*) cell + cell->size < (char*) cell->next);

        ftotal += cell->size;
        free += cell->size - sizeof(Cell);
        CHECK(0x374, 0 < ftotal && ftotal <= hd->size);
    }

    total = ftotal + atotal;
    CHECK(0x37C, total == hd->size);

    fn_800095A4();
    return free;
}

void fn_80009468(void *arena) {
    HeapContext *context;
    int i;

    for (i = 0, context = lbl_8015BE40; i < 8; i++, context++) {
        context->currHeap = -1;
        context->heapArray = NULL;
        context->numHeaps = 0;
        context->arenaStart = NULL;
        context->arenaEnd = NULL;
    }
    lbl_801A6730 = -1;
}

void fn_8000951C(int heap) {
    if (lbl_801A6730 != -1) {
        lbl_8015BEE0.currHeap = CurrHeap;
        lbl_8015BEE0.heapArray = HeapArray;
        lbl_8015BEE0.numHeaps = NumHeaps;
        lbl_8015BEE0.arenaStart = ArenaStart;
        lbl_8015BEE0.arenaEnd = ArenaEnd;
        CurrHeap = lbl_8015BE40[lbl_801A6730].currHeap;
        HeapArray = lbl_8015BE40[lbl_801A6730].heapArray;
        NumHeaps = lbl_8015BE40[lbl_801A6730].numHeaps;
        ArenaStart = lbl_8015BE40[lbl_801A6730].arenaStart;
        ArenaEnd = lbl_8015BE40[lbl_801A6730].arenaEnd;
    }
}

void fn_800095A4(void) {
    if (lbl_801A6730 != -1) {
        lbl_8015BE40[lbl_801A6730].currHeap = CurrHeap;
        lbl_8015BE40[lbl_801A6730].heapArray = HeapArray;
        lbl_8015BE40[lbl_801A6730].numHeaps = NumHeaps;
        lbl_8015BE40[lbl_801A6730].arenaStart = ArenaStart;
        lbl_8015BE40[lbl_801A6730].arenaEnd = ArenaEnd;
        CurrHeap = lbl_8015BEE0.currHeap;
        HeapArray = lbl_8015BEE0.heapArray;
        NumHeaps = lbl_8015BEE0.numHeaps;
        ArenaStart = lbl_8015BEE0.arenaStart;
        ArenaEnd = lbl_8015BEE0.arenaEnd;
    }
}

HeapDesc *fn_8000961C(int heap) {
    HeapDesc *hd;

    fn_8000951C(heap);
    if (heap < 0 || heap >= NumHeaps) {
        fn_800095A4();
        return NULL;
    }
    hd = &HeapArray[heap];
    if (hd->size < 0) {
        fn_800095A4();
        return NULL;
    }
    fn_800095A4();
    return hd;
}

static inline Cell *DLAddFront(Cell *list, Cell *cell) {
    cell->next = list;
    cell->prev = NULL;
    if (list != NULL) {
        list->prev = cell;
    }
    return cell;
}

static inline Cell *DLExtract(Cell *list, Cell *cell) {
    if (cell->next != NULL) {
        cell->next->prev = cell->prev;
    }
    if (cell->prev == NULL) {
        list = cell->next;
    } else {
        cell->prev->next = cell->next;
    }
    return list;
}

static inline Cell *DLInsert(Cell *list, Cell *cell) {
    Cell *prev;
    Cell *next;

    for (next = list, prev = NULL; next != NULL; prev = next, next = next->next) {
        if (cell <= next) {
            break;
        }
    }
    cell->next = next;
    cell->prev = prev;
    if (next != NULL) {
        next->prev = cell;
        if ((u8 *)cell + cell->size == (u8 *)next) {
            cell->size += next->size;
            next = next->next;
            cell->next = next;
            if (next != NULL) {
                next->prev = cell;
            }
        }
    }
    if (prev != NULL) {
        prev->next = cell;
        if ((u8 *)prev + prev->size == (u8 *)cell) {
            prev->size += cell->size;
            prev->next = next;
            if (next != NULL) {
                next->prev = prev;
            }
        }
        return list;
    }
    return cell;
}

/* WARNING: compiler-diff device, not original code: hd and list live in an inner block so that they
   take retail's registers (inner-scope locals are numbered below the function's own). */
void *fn_80009830(int heap, u32 size, const char *file, int line) {
    Cell *cell;
    Cell *next;
    Cell *prev;
    Cell *newCell;
    Cell *t;
    long allocSize;
    long leftoverSize;

    fn_8000951C(heap);
    {
        HeapDesc *hd;
        Cell *list;

        hd = &HeapArray[heap];
        allocSize = (size + HEADERSIZE + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
        list = hd->free;
        for (cell = list; cell != NULL; cell = cell->next) {
            if (allocSize <= cell->size) {
                break;
            }
        }
        if (cell == NULL) {
            fn_800095A4();
            return NULL;
        }
        leftoverSize = cell->size - allocSize;
        if (leftoverSize < MINOBJSIZE) {
            t = cell->next;
            if (t != NULL) {
                t->prev = cell->prev;
            }
            next = cell->prev;
            if (next == NULL) {
                list = cell->next;
            } else {
                next->next = cell->next;
            }
            hd->free = list;
        } else {
            cell->size = allocSize;
            newCell = (Cell *)((u8 *)cell + allocSize);
            newCell->size = leftoverSize;
            newCell->prev = cell->prev;
            newCell->next = cell->next;
            prev = newCell->next;
            if (prev != NULL) {
                prev->prev = newCell;
            }
            next = newCell->prev;
            if (next != NULL) {
                next->next = newCell;
            } else {
                hd->free = newCell;
            }
        }
        prev = hd->allocated;
        cell->next = prev;
        cell->prev = NULL;
        if (prev != NULL) {
            prev->prev = cell;
        }
        hd->allocated = cell;
    }
    fn_800095A4();
    return (u8 *)cell + HEADERSIZE;
}


void fn_80009AA8(int heap, void *ptr, const char *file, int line) {
    HeapDesc *hd;
    Cell *cell;

    fn_8000951C(heap);
    cell = (Cell *)((u8 *)ptr - HEADERSIZE);
    hd = &HeapArray[heap];
    hd->allocated = DLExtract(hd->allocated, cell);
    hd->free = DLInsert(hd->free, cell);
    fn_800095A4();
}

long fn_80009CAC(void *ptr, u32 size) {
    return fn_80009CD4(ptr, size, "", 0);
}

static inline u32 find_block(u32 link, u32 address) {
    while (link) {
        if (link == address) return link;
        link = *(u32 *)(link + 4);
    }
    return 0;
}

long fn_80009CD4(void *ptr, u32 arg1, const char *file, int line) {
    u32 arg0 = (u32)ptr;
    u32 v0;
    u32 v7, v11, v14, v16, v13, v15, v20, v21, v23, v24, v28, v29, v30, v31;
    u32 v19, v17, v9, v18, v25, v26, v12, v8, v27, v22, v10;
    /* WARNING: compiler-diff device, not original code: the volatile read keeps the current heap */
    /* loaded before the context switch, as retail does. */
    v0 = *(volatile int *)&lbl_801A6410;
    fn_8000951C(0);
    v7 = v0 * 12;
    v8 = arg0 - 32;
    v9 = *(u32 *)(v8 + 8);
    v12 = (u32)lbl_801A6744 + v7;
    v10 = v8 + v9;
    v11 = find_block(*(u32 *)(v12 + 4), v10);
    if (!v11 && v9 <= arg1 + 64) return 0;
    v13 = *(u32 *)(v8 + 4);
    v14 = *(u32 *)(v12 + 8);
    if (v13 != 0) {
        *(u32 *)v13 = *(u32 *)v8;
    }
    v15 = *(u32 *)v8;
    v16 = v14;
    if (v15 == 0) {
        v16 = *(u32 *)(v8 + 4);
    } else {
        *(u32 *)(v15 + 4) = *(u32 *)(v8 + 4);
    }
    *(u32 *)(v12 + 8) = v16;
    v17 = *(u32 *)(v12 + 4);
    v18 = v17;
    v19 = 0;
    while (v18 != 0) {
        if (v8 <= v18) break;
        v19 = v18;
        v18 = *(u32 *)(v18 + 4);
    }
    v20 = v17;
    *(u32 *)(v8 + 4) = v18;
    *(u32 *)v8 = v19;
    v21 = v18;
    if (v18 != 0) {
        *(u32 *)v21 = v8;
        v24 = *(u32 *)(v8 + 8);
        v22 = v8 + v24;
        if (v22 == v21) {
            *(u32 *)(v8 + 8) = v24 + *(u32 *)(v21 + 8);
            v21 = *(u32 *)(v21 + 4);
            *(u32 *)(v8 + 4) = v21;
            if (v21 != 0) *(u32 *)v21 = v8;
        }
    }
    v17 = v20;
    if (v19 != 0) {
        *(u32 *)(v19 + 4) = v8;
        v24 = *(u32 *)(v19 + 8);
        v22 = v19 + v24;
        if (v22 == v8) {
            *(u32 *)(v19 + 8) = v24 + *(u32 *)(v8 + 8);
            *(u32 *)(v19 + 4) = v21;
            if (v21 != 0) *(u32 *)v21 = v19;
        }
    } else {
        v17 = v8;
    }
    *(u32 *)(v12 + 4) = v17;
    v25 = (arg1 + 63) & ~31;
    v26 = v8 + v25;
    v27 = v9 - v25;
    v28 = *(u32 *)(v8 + 8);
    *(u32 *)(v8 + 8) = v25;
    *(u32 *)(v26 + 8) = v28 - v25;
    *(u32 *)v26 = *(u32 *)v8;
    *(u32 *)(v26 + 4) = *(u32 *)(v8 + 4);
    v29 = *(u32 *)(v26 + 4);
    if (v29 != 0) *(u32 *)v29 = v26;
    v30 = *(u32 *)v26;
    if (v30 != 0) *(u32 *)(v30 + 4) = v26;
    else *(u32 *)(v12 + 4) = v26;
    v31 = *(u32 *)(v12 + 8);
    *(u32 *)(v8 + 4) = v31;
    *(u32 *)v8 = 0;
    if (v31 != 0) *(u32 *)v31 = v8;
    *(u32 *)(v12 + 8) = v8;
    if (lbl_801A6730 != -1) {
        lbl_8015BE40[lbl_801A6730].currHeap = lbl_801A6410;
        lbl_8015BE40[lbl_801A6730].heapArray = lbl_801A6744;
        lbl_8015BE40[lbl_801A6730].numHeaps = lbl_801A6740;
        lbl_8015BE40[lbl_801A6730].arenaStart = (void *)lbl_801A673C;
        lbl_8015BE40[lbl_801A6730].arenaEnd = (void *)lbl_801A6738;
        lbl_801A6410 = lbl_8015BEE0.currHeap;
        lbl_801A6744 = lbl_8015BEE0.heapArray;
        lbl_801A6740 = lbl_8015BEE0.numHeaps;
        lbl_801A673C = lbl_8015BEE0.arenaStart;
        lbl_801A6738 = lbl_8015BEE0.arenaEnd;
    }
    return -v27;
}


long fn_80009FA4(int heap) {
    return HeapArray[heap].size;
}

long fn_80009FB4(void *ptr) {
    return ((Cell *)((u8 *)ptr - HEADERSIZE))->size;
}
