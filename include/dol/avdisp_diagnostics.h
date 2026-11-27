#ifndef DOL_AVDISP_DIAGNOSTICS_H
#define DOL_AVDISP_DIAGNOSTICS_H

#include "types.h"

typedef struct AvDispDiagnostics {
    char ineffectiveModel[0x20];
    char nonSkinningModel[0x20];
    u32 descriptorSizes[21];
    char modelError[0xC];
    char sourceFile[0xC];
    char textureObjectMemory[0x1C];
    char invalidTextureIndex[0x48];
} AvDispDiagnostics;

extern char lbl_8015AD38[14];
extern AvDispDiagnostics lbl_8015AD48;

#endif
