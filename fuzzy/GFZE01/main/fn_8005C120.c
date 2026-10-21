/* Non-matching: best partial attempt (72.27% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef void (*ARQCallback)(unsigned long request_address);
typedef void (*ARDMACallback)(void);
typedef struct ARQRequest {
    struct ARQRequest *next;
    unsigned long owner;
    unsigned long type;
    unsigned long priority;
    unsigned long source;
    unsigned long destination;
    unsigned long length;
    ARQCallback callback;
} ARQRequest;
unsigned long ARInit(unsigned long *stack_index, unsigned long entry_count);
unsigned long ARGetSize(void);
unsigned long ARGetBaseAddress(void);
unsigned long fn_8001E954(unsigned long length);
unsigned long ARFree(unsigned long *length);
int ARCheckInit(void);
ARDMACallback ARRegisterDMACallback(ARDMACallback callback);
unsigned long ARGetDMAStatus(void);
void ARStartDMA(unsigned long type, unsigned long main_memory, unsigned long aram,
                unsigned long length);
void ARReset(void);
void ARSetSize(void);
unsigned long ARGetInternalSize(void);
void ARClear(unsigned long flag);
void __ARClearInterrupt(void);
unsigned short __ARGetInterruptStatus(void);
void __ARQPopTaskQueueHi(void);

void *memcpy(void *destination, const void *source, unsigned long size);
void *memset(void *destination, int value, unsigned int size);
int memcmp(const void *lhs, const void *rhs, unsigned long size);
char *strcpy(char *destination, const char *source);
char *strncpy(char *destination, const char *source, unsigned long count);
char *strcat(char *destination, const char *source);
char *strncat(char *destination, const char *source, unsigned long count);
char *strchr(const char *string, int character);
char *strrchr(const char *string, int character);
char *strstr(const char *string, const char *substring);
unsigned long strlen(const char *string);
int strcmp(const char *lhs, const char *rhs);
int strncmp(const char *lhs, const char *rhs, unsigned long count);
int stricmp(const char *lhs, const char *rhs);
int strnicmp(const char *lhs, const char *rhs, unsigned long count);
char *strtok(char *string, const char *delimiters);
char *strupr(char *string);
typedef struct RNAResource {
    int used;
    u32 buffer;
    u32 size;
} RNAResource;
void RNAERR_CallErrFunc(const char *message);
extern u32 rnares_init_cnt;
extern u32 rnares_setup_fg;
extern u32 lbl_80192BD0;
extern u32 lbl_80192BD0;
extern u32 rnares_aram_ptr;
RNAResource rnares_obj[32];

void fn_8005C120(void) {
    u32 offset;
    u32 sum;
    u32 base;
    u32 i;
    u32 nbuf;
    RNAResource *resource;
    if (rnares_init_cnt == 0) {
        if (rnares_setup_fg == 0) {
            lbl_80192BD0 = 32;
            lbl_80192BD0 = 0x40000;
            rnares_aram_ptr = fn_8001E954(lbl_80192BD0);
        }
        memset(rnares_obj, 0, sizeof(rnares_obj));
        nbuf = lbl_80192BD0;
        resource = rnares_obj;
        base = rnares_aram_ptr;
        offset = 0;
        for (i = 0; i < nbuf; i++, resource++) {
            sum = base + offset;
            offset += 0x2000;
            resource->buffer = sum >> 1;
            resource->size = 0x1000;
        }
    }
    rnares_init_cnt++;
}
