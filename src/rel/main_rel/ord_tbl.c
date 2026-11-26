#include "types.h"
#include "dolphin/types.h"

/* Depth ordering table (retail TU between sprite.c and objput.c; SMB1 calls the same module ord_tbl.c).
 * The entries form a linked list ordered by view depth; drawing nodes are inserted after an entry. */

typedef struct OrdTblNode {
    struct OrdTblNode *next;
    void (*drawFunc)(struct OrdTblNode *);
} OrdTblNode;

typedef struct {
    f32 x, y, z;
} OrdTblVec;

/* The game's shared work block; only the fields this TU uses are named. */
typedef struct OrdTblWork {
    u8 unk_0[0x30];
    OrdTblNode *entries;
    s32 maxEntries;
    f32 depthOffset;
    f32 minDepth;
    f32 maxDepth;
    OrdTblNode *lastEntry;
    OrdTblNode *firstEntry;
    f32 depthRange;
    u8 unk_50[0x1A0 - 0x50];
    u8 *currPtr;
    u8 *initPtr;
    u32 initSize;
    u32 currSize;
} OrdTblWork;

extern OrdTblWork *lbl_801A66CC;
extern void lbl_8006E1B0(OrdTblVec *src, OrdTblVec *dst);
extern f32 lbl_8006D0B4(f32 x);
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);

void fn_1_54320(void);
void fn_1_54668(OrdTblNode *ordTbl, s32 count, u32 order);
void fn_1_547F8(OrdTblNode *node);
void fn_1_54848(void);

/* The table's entries (0x1000 nodes); _prolog passes it to fn_1_542C4.
 * 16-byte aligned: sprite.c's .bss ends at 0x64708 and retail places this array at 0x64710. */
OrdTblNode lbl_1_bss_64710[0x1000] __attribute__((aligned(16)));

/* fzgx:begin fn_1_542C4 */
/* Sets the table buffer and depth range, then resets the table (SMB1 ord_tbl_init). */
void fn_1_542C4(OrdTblNode *buffer, s32 maxEntries, f32 depthOffset, f32 minDepth, f32 maxDepth) {
    lbl_801A66CC->entries = buffer;
    lbl_801A66CC->maxEntries = maxEntries;
    lbl_801A66CC->depthOffset = depthOffset;
    lbl_801A66CC->minDepth = minDepth;
    lbl_801A66CC->maxDepth = maxDepth;
    lbl_801A66CC->depthRange = maxDepth - minDepth;
    fn_1_54320();
}
/* fzgx:end fn_1_542C4 */

/* fzgx:begin fn_1_54320 */
/* Relinks every entry and resets the used range (SMB1 ord_tbl_reset). */
void fn_1_54320(void) {
    fn_1_54668(lbl_801A66CC->entries, lbl_801A66CC->maxEntries, 1);
    lbl_801A66CC->lastEntry = &lbl_801A66CC->entries[lbl_801A66CC->maxEntries - 1];
    lbl_801A66CC->firstEntry = &lbl_801A66CC->entries[0];
}
/* fzgx:end fn_1_54320 */

/* fzgx:begin fn_1_54384 */
/* Returns the entry for a view-space depth z. */
OrdTblNode *fn_1_54384(f32 z) {
    f32 depth;
    s32 index;
    OrdTblNode *entry;

    depth = -z + lbl_801A66CC->depthOffset - lbl_801A66CC->minDepth;
    if (depth < 0.0f) {
        index = 0;
    } else {
        index = lbl_801A66CC->maxEntries * depth / (depth + lbl_801A66CC->depthRange);
        if (index >= lbl_801A66CC->maxEntries) {
            index = lbl_801A66CC->maxEntries - 1;
        }
    }

    entry = &lbl_801A66CC->entries[index];
    if (lbl_801A66CC->lastEntry > entry) {
        lbl_801A66CC->lastEntry = entry;
    }
    if (lbl_801A66CC->firstEntry < entry) {
        lbl_801A66CC->firstEntry = entry;
    }
    return entry;
}
/* fzgx:end fn_1_54384 */

/* fzgx:begin fn_1_54448 */
/* Returns the entry at a fixed index. */
OrdTblNode *fn_1_54448(s32 index) {
    OrdTblNode *entry;

    entry = &lbl_801A66CC->entries[index];
    if (lbl_801A66CC->lastEntry > entry) {
        lbl_801A66CC->lastEntry = entry;
    }
    if (lbl_801A66CC->firstEntry < entry) {
        lbl_801A66CC->firstEntry = entry;
    }
    return entry;
}
/* fzgx:end fn_1_54448 */

/* fzgx:begin fn_1_5448C */
/* Returns the entry for the view depth of pos (SMB1 ord_tbl_get_entry_for_pos). */
OrdTblNode *fn_1_5448C(OrdTblVec *pos) {
    OrdTblVec posView;
    f32 x, y, z;
    f32 minDepth;
    f32 depth;
    s32 index;
    OrdTblNode *entry;

    lbl_8006E1B0(pos, &posView);
    minDepth = lbl_801A66CC->minDepth;
    posView.z = -posView.z;
    if (posView.z < minDepth) {
        posView.z = minDepth;
    }
    x = posView.x;
    y = posView.y;
    z = posView.z;
    depth = x * x;
    depth += y * y;
    depth += z * z;
    depth = lbl_8006D0B4(depth) + lbl_801A66CC->depthOffset - minDepth;

    if (depth < 0.0f) {
        index = 0;
    } else {
        index = lbl_801A66CC->maxEntries * depth / (depth + lbl_801A66CC->depthRange);
        if (index >= lbl_801A66CC->maxEntries) {
            index = lbl_801A66CC->maxEntries - 1;
        }
    }

    entry = &lbl_801A66CC->entries[index];
    if (lbl_801A66CC->lastEntry > entry) {
        lbl_801A66CC->lastEntry = entry;
    }
    if (lbl_801A66CC->firstEntry < entry) {
        lbl_801A66CC->firstEntry = entry;
    }
    return entry;
}
/* fzgx:end fn_1_5448C */

/* fzgx:begin fn_1_545B8 */
/* Draws the used range of the table, then resets it (SMB1 ord_tbl_draw_nodes). */
void fn_1_545B8(void) {
    if (lbl_801A66CC->firstEntry >= lbl_801A66CC->lastEntry) {
        if (lbl_801A66CC->lastEntry > &lbl_801A66CC->entries[0]) {
            lbl_801A66CC->lastEntry[-1].next = NULL;
        }
        fn_1_547F8(lbl_801A66CC->firstEntry);
    }
    fn_1_54320();
    fn_1_9FA18();
    fn_1_58248();
}
/* fzgx:end fn_1_545B8 */

/* fzgx:begin fn_1_54668 */
/* Clears the nodes and links them first-to-last or last-to-first (SMB1 clear_ord_table). */
void fn_1_54668(OrdTblNode *ordTbl, s32 count, u32 order) {
    s32 i;
    OrdTblNode *node;

    if (order == 0) {
        node = ordTbl;
        for (i = count - 1; i > 0; i--) {
            node->next = node + 1;
            node->drawFunc = NULL;
            node++;
        }
        node->next = NULL;
        node->drawFunc = NULL;
    } else {
        node = &ordTbl[count - 1];
        for (i = count - 1; i > 0; i--) {
            node->next = node - 1;
            node->drawFunc = NULL;
            node--;
        }
        node->next = NULL;
        node->drawFunc = NULL;
    }
    fn_1_54848();
}
/* fzgx:end fn_1_54668 */

/* fzgx:begin fn_1_547F8 */
/* Calls the draw callback of each node in the list (SMB1 draw_nodes). */
void fn_1_547F8(OrdTblNode *node) {
    while (node != NULL) {
        if (node->drawFunc != NULL) {
            node->drawFunc(node);
        }
        node = node->next;
    }
}
/* fzgx:end fn_1_547F8 */

/* fzgx:begin fn_1_54848 */
/* Rewinds the node allocator (SMB1 reset_alloc_info). */
void fn_1_54848(void) {
    lbl_801A66CC->currPtr = lbl_801A66CC->initPtr;
    lbl_801A66CC->currSize = lbl_801A66CC->initSize;
}
/* fzgx:end fn_1_54848 */

/* fzgx:begin fn_1_54868 */
/* Sets the node allocator's buffer (SMB1 ord_tbl_init_buffer). */
void fn_1_54868(void *addr, u32 size) {
    lbl_801A66CC->initPtr = addr;
    lbl_801A66CC->initSize = size;
    fn_1_54848();
}
/* fzgx:end fn_1_54868 */

/* fzgx:begin fn_1_5489C */
/* Inserts a node after a table entry (SMB1 ord_tbl_insert_node). */
void fn_1_5489C(OrdTblNode *tblEntry, OrdTblNode *newNode) {
    newNode->next = tblEntry->next;
    tblEntry->next = newNode;
}
/* fzgx:end fn_1_5489C */

/* fzgx:begin fn_1_548AC */
/* Allocates from the node buffer; NULL when it is full (SMB1 ord_tbl_alloc_node panics instead). */
void *fn_1_548AC(u32 size) {
    void *ptr;

    if (lbl_801A66CC->currSize < size) {
        return NULL;
    }
    ptr = lbl_801A66CC->currPtr;
    lbl_801A66CC->currPtr += size;
    lbl_801A66CC->currSize -= size;
    return ptr;
}
/* fzgx:end fn_1_548AC */

/* fzgx:begin fn_1_548EC */
/* Returns the index of a table entry, or -1. */
s32 fn_1_548EC(OrdTblNode *entry) {
    s32 i;

    for (i = 0; i < 0x1000; i++) {
        if (entry == &lbl_801A66CC->entries[i]) {
            return i;
        }
    }
    return -1;
}
/* fzgx:end fn_1_548EC */
