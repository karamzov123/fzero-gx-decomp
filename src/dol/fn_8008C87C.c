
#include "types.h"

typedef enum {
    DS_NoError = 0x0,
    DS_StepError = 0x1,
    DS_ParameterError = 0x2,
    DS_EventQueueFull = 0x100,
    DS_NoMessageBufferAvailable = 0x300,
    DS_MessageBufferOverflow = 0x301,
    DS_MessageBufferReadError = 0x302,
    DS_DispatchError = 0x500,
    DS_InvalidMemory = 0x700,
    DS_InvalidRegister = 0x701,
    DS_CWDSException = 0x702,
    DS_UnsupportedError = 0x703,
    DS_InvalidProcessID = 0x704,
    DS_InvalidThreadID = 0x705,
    DS_OSError = 0x706,
    DS_Error800 = 0x800,
} DSError;

typedef enum {
    VALIDMEM_Readable = 0,
    VALIDMEM_Writeable = 1,
} ValidMemoryOptions;

typedef struct memRange {
    u8 *start;
    u8 *end;
    BOOL readable;
    BOOL writeable;
} memRange;

DSError fn_8008C87C(const void *addr, size_t length, ValidMemoryOptions readWriteable);

extern const memRange lbl_80095B20[1];

DSError fn_8008C87C(const void *addr, size_t length, ValidMemoryOptions readWriteable) {
    DSError err = DS_InvalidMemory;
    const u8 *start;
    const u8 *end;
    int i;
    start = addr;
    end = ((const u8 *)addr + (length - 1));
    if (end < start)
        return DS_InvalidMemory;
    for (i = 0; (i < (sizeof(lbl_80095B20) / sizeof(memRange))); i++) {
        if ((start <= lbl_80095B20[i].end) &&
            (end >= lbl_80095B20[i].start)) {
            if (((readWriteable == VALIDMEM_Readable) && !lbl_80095B20[i].readable) ||
                ((readWriteable == VALIDMEM_Writeable) && !lbl_80095B20[i].writeable)) {
                err = DS_InvalidMemory;
            } else {
                err = DS_NoError;
                if (start < lbl_80095B20[i].start)
                    err = fn_8008C87C(start, (lbl_80095B20[i].start - start),
                                      readWriteable);
                if ((err == DS_NoError) && (end > lbl_80095B20[i].end))
                    err = fn_8008C87C(lbl_80095B20[i].end,
                                      (end - lbl_80095B20[i].end), readWriteable);
            }
            break;
        }
    }
    return err;
}
