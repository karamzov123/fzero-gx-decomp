#ifndef REL_MAIN_REL_RANKING_ARCHIVE_H
#define REL_MAIN_REL_RANKING_ARCHIVE_H

#include "types.h"

/* Bitmap archives that ranking.c loads on demand: lbl_1_data_4C810[4], 0x3C each.
 * Data relocations give entries 1..3 an archive path ("/bmp/bmp_cardt.arc", ...)
 * and a -1-terminated id table. fn_1_1594AC opens the archive and clears the id
 * ring; fn_1_159588, fn_1_1596DC and fn_1_159804 keep up to `limit` ids between
 * head and tail, both wrapping at 15. Words 0x30..0x38 keep observed roles only. */
typedef struct RankingArchive {
    char *path;
    s16 *ids;
    s16 queue[16];
    s16 head;
    s16 tail;
    u8 limit;
    u8 pad_2D[3];
    u32 unk_30;
    u32 unk_34;
    s32 unk_38;
} RankingArchive;

extern RankingArchive lbl_1_data_4C810[4];

#endif
