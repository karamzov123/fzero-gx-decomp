/* Non-matching: best partial attempt (74.20% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

/*types*/

typedef struct AXPBMIX {
    unsigned short vL, vDeltaL, vR, vDeltaR;
    unsigned short vAuxAL, vDeltaAuxAL, vAuxAR, vDeltaAuxAR;
    unsigned short vAuxBL, vDeltaAuxBL, vAuxBR, vDeltaAuxBR;
    unsigned short vAuxBS, vDeltaAuxBS, vS, vDeltaS;
    unsigned short vAuxAS, vDeltaAuxAS;
} AXPBMIX;
typedef struct AXPBITD {
    unsigned short flag, bufferHi, bufferLo, shiftL, shiftR;
    unsigned short targetShiftL, targetShiftR;
} AXPBITD;
typedef struct AXPBUPDATE {
    unsigned short updNum[5];
    unsigned short dataHi, dataLo;
} AXPBUPDATE;
typedef struct AXPBDPOP {
    short aL, aAuxAL, aAuxBL, aR, aAuxAR, aAuxBR, aS, aAuxAS, aAuxBS;
} AXPBDPOP;
typedef struct AXPBVE {
    unsigned short currentVolume;
    short currentDelta;
} AXPBVE;
typedef struct AXPBFIR {
    unsigned short numCoefs, coefsHi, coefsLo;
} AXPBFIR;
typedef struct AXPBADDR {
    unsigned short loopFlag, format;
    unsigned short loopAddressHi, loopAddressLo;
    unsigned short endAddressHi, endAddressLo;
    unsigned short currentAddressHi, currentAddressLo;
} AXPBADDR;
typedef struct AXPBADPCM {
    unsigned short a[8][2];
    unsigned short gain, pred_scale, yn1, yn2;
} AXPBADPCM;
typedef struct AXPBSRC {
    unsigned short ratioHi, ratioLo, currentAddressFrac;
    unsigned short last_samples[4];
} AXPBSRC;
typedef struct AXPBADPCMLOOP {
    unsigned short loop_pred_scale, loop_yn1, loop_yn2;
} AXPBADPCMLOOP;
typedef struct AXPBLPF {
    unsigned short on, yn1, a0, b0;
} AXPBLPF;
typedef struct AXPB {
    unsigned short nextHi, nextLo, currHi, currLo;
    unsigned short srcSelect, coefSelect, mixerCtrl, state, type;
    AXPBMIX mix;
    AXPBITD itd;
    AXPBUPDATE update;
    AXPBDPOP dpop;
    AXPBVE ve;
    AXPBFIR fir;
    AXPBADDR addr;
    AXPBADPCM adpcm;
    AXPBSRC src;
    AXPBADPCMLOOP adpcmLoop;
    AXPBLPF lpf;
    unsigned short pad[25];
} AXPB;
typedef struct _AXVPB {
    struct _AXVPB *next;
    struct _AXVPB *prev;
    struct _AXVPB *next1;
    unsigned long priority;
    void (*callback)(void *);
    unsigned long user_context;
    unsigned long index, sync, depop;
    unsigned long updateMS, updateCounter, updateTotal;
    unsigned short *updateWrite;
    unsigned short updateData[128];
    void *itdBuffer;
    AXPB pb;
} AXVPB;
typedef struct AXPBITDBUFFER {
    short data[32];
} AXPBITDBUFFER;
typedef struct AXPBU {
    unsigned short data[128];
} AXPBU;
typedef struct AXSPB {
    unsigned short dpopLHi, dpopLLo;
    short dpopLDelta;
    unsigned short dpopRHi, dpopRLo;
    short dpopRDelta;
    unsigned short dpopSHi, dpopSLo;
    short dpopSDelta;
    unsigned short dpopALHi, dpopALLo;
    short dpopALDelta;
    unsigned short dpopARHi, dpopARLo;
    short dpopARDelta;
    unsigned short dpopASHi, dpopASLo;
    short dpopASDelta;
    unsigned short dpopBLHi, dpopBLLo;
    short dpopBLDelta;
    unsigned short dpopBRHi, dpopBRLo;
    short dpopBRDelta;
    unsigned short dpopBSHi, dpopBSLo;
    short dpopBSDelta;
} AXSPB;
typedef AXPBSRC AXVoiceSrc;
typedef struct _AXPROFILE {
    unsigned long long axFrameStart, auxProcessingStart, auxProcessingEnd;
    unsigned long long userCallbackStart, userCallbackEnd, axFrameEnd;
    unsigned long axNumVoices;
} AXPROFILE;
typedef struct AX_AUX_DATA {
    signed long *l;
    signed long *r;
    signed long *s;
} AX_AUX_DATA;
typedef struct AX_AUX_DATA_DPL2 {
    signed long *l;
    signed long *r;
    signed long *ls;
    signed long *rs;
} AX_AUX_DATA_DPL2;
typedef void (*AXVoiceCallback)(void *callback_data);
typedef void (*AXCallback)(void);
AXVPB *AXAcquireVoice(unsigned long priority, AXVoiceCallback callback, unsigned long user_context);
void AXFreeVoice(AXVPB *voice);
void AXSetVoicePriority(AXVPB *voice, unsigned long priority);
void AXSetVoiceSrcType(AXVPB *voice, unsigned long type);
void AXSetVoiceSrc(AXVPB *voice, AXPBSRC *source);
void AXSetVoiceAdpcm(AXVPB *voice, AXPBADPCM *adpcm);
void AXSetVoiceState(AXVPB *voice, unsigned short state);
void AXSetVoiceAddr(AXVPB *voice, AXPBADDR *address);
void AXInitEx(unsigned long output_buffer_mode);
void AXSetMode(unsigned long mode);
AXCallback AXRegisterCallback(AXCallback callback);
void MIXInit(void);
int MIXGetSoundMode(void);
void MIXUpdateSettings(void);
void MIXInitChannel(AXVPB *voice, unsigned long mode, int input, int aux_a, int aux_b, int pan,
                    int surround_pan, int fader);
void MIXSetPan(AXVPB *voice, int pan);
void MIXSetSPan(AXVPB *voice, int pan);
void MIXSetInput(AXVPB *voice, long volume);
void MIXSetFader(AXVPB *voice, int volume);
void MIXReleaseChannel(AXVPB *voice);
extern u16 __AXCompressorTable[3360];
extern u16 axDspSlave[];
extern u16 axDspSlaveLength;
extern u32 __AXClMode;
extern AXPROFILE __AXLocalProfile;
void __AXAllocInit(void);
AXVPB *__AXGetStackHead(u32 priority);
void __AXServiceCallbackStack(void);
void __AXPushFreeStack(AXVPB *voice);
void __AXPushCallbackStack(AXVPB *voice);
AXVPB *__AXPopCallbackStack(void);
void __AXRemoveFromStack(AXVPB *voice);
void __AXAuxInit(void);
void __AXGetAuxAInput(u32 *address);
void __AXGetAuxAInputDpl2(u32 *address);
void __AXGetAuxAOutput(u32 *address);
void __AXGetAuxAOutputDpl2R(u32 *address);
void __AXGetAuxAOutputDpl2Ls(u32 *address);
void __AXGetAuxAOutputDpl2Rs(u32 *address);
void __AXGetAuxBInput(u32 *address);
void __AXGetAuxBOutput(u32 *address);
void __AXGetAuxBForDPL2(u32 *address);
void __AXGetAuxBOutputDPL2(u32 *address);
void __AXProcessAux(void);
u32 __AXGetCommandListCycles(void);
u32 __AXGetCommandListAddress(void);
void __AXNextFrame(void *sbuffer, void *buffer);
void __AXClInit(void);
void __AXOutNewFrame(u32 less_dsp_cycles);
void __AXOutAiCallback(void);
void __AXOutInitDSP(void);
void __AXOutInit(u32 output_buffer_mode);
AXPROFILE *__AXGetCurrentProfile(void);
u32 __AXGetStudio(void);
void __AXPrintStudio(void);
void __AXSPBInit(void);
void __AXDepopVoice(AXPB *pb);
u32 __AXGetNumVoices(void);
void __AXSyncPBs(u32 less_dsp_cycles);
AXPB *__AXGetPBs(void);
void __AXSetPBDefault(AXVPB *voice);
void __AXVPBInit(void);
void DCFlushRangeNoSync(void *address, unsigned long length);
void DCStoreRange(void *address, unsigned long length);
void DCFlushRange(void *address, unsigned long length);
void DCInvalidateRange(void *address, unsigned long length);
void DCEnable(void);
void ICInvalidateRange(void *address, unsigned long length);
void ICFlashInvalidate(void);
void ICEnable(void);
void LCDisable(void);
void L2GlobalInvalidate(void);
void __OSCacheInit(void);
typedef int OSHeapHandle;
typedef struct OSContext OSContext;
typedef struct OSThread OSThread;
typedef struct OSMutex OSMutex;
struct OSContext {
    unsigned long gpr[32];
    unsigned long cr, lr, ctr, xer;
    double fpr[32];
    unsigned long fpscr_pad, fpscr, srr0, srr1;
    unsigned short mode, state;
    unsigned long gqr[8];
    unsigned long psf_pad;
    double psf[32];
};
typedef struct OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;
typedef struct OSThreadLink {
    OSThread *next;
    OSThread *prev;
} OSThreadLink;
typedef struct OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
} OSMutexQueue;
typedef struct OSMutexLink {
    OSMutex *next;
    OSMutex *prev;
} OSMutexLink;
struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    signed long count;
    OSMutexLink link;
};
struct OSThread {
    OSContext context;
    unsigned short state;
    unsigned short attr;
    signed long suspend;
    signed long priority;
    signed long base;
    void *value;
    OSThreadQueue *queue;
    OSThreadLink link;
    OSThreadQueue queueJoin;
    OSMutex *mutex;
    OSMutexQueue queueMutex;
    OSThreadLink linkActive;
    unsigned char *stackBase;
    unsigned long *stackEnd;
    signed long error;
    void *specific[2];
};
typedef struct OSCond {
    OSThreadQueue queue;
} OSCond;
struct OSAlarm {
    void (*handler)(struct OSAlarm *alarm, OSContext *context);
    unsigned long tag;
    signed long long fire;
    struct OSAlarm *prev;
    struct OSAlarm *next;
    signed long long period;
    signed long long start;
};
typedef struct OSAlarm OSAlarm;
struct OSContext;
struct OSAlarm;
typedef struct DVDDiskID {
    char gameName[4];
    char company[2];
    unsigned char diskNumber;
    unsigned char gameVersion;
    unsigned char streaming;
    unsigned char streamingBufSize;
    unsigned char padding[22];
} DVDDiskID;
typedef struct DVDCommandBlock DVDCommandBlock;
typedef struct DVDFileInfo DVDFileInfo;
typedef struct DVDDriveInfo {
    unsigned short revision_level;
    unsigned short device_code;
    unsigned long release_date;
    unsigned char padding[24];
} DVDDriveInfo;
typedef void (*DVDCBCallback)(long result, DVDCommandBlock *block);
typedef void (*DVDCallback)(long result, DVDFileInfo *file_info);
typedef void (*DVDLowCallback)(unsigned long interrupt_type);
typedef void (*DVDCommandCheckerCallback)(unsigned long result);
typedef void (*DVDCommandChecker)(DVDCommandBlock *block, DVDCommandCheckerCallback callback);
struct DVDCommandBlock {
    DVDCommandBlock *next;
    DVDCommandBlock *prev;
    unsigned long command;
    long state;
    unsigned long offset;
    unsigned long length;
    void *address;
    unsigned long current_transfer_size;
    unsigned long transferred_size;
    DVDDiskID *id;
    DVDCBCallback callback;
    void *user_data;
};
struct DVDFileInfo {
    DVDCommandBlock cb;
    unsigned long start_address;
    unsigned long length;
    DVDCallback callback;
};
typedef struct DVDBB2 {
    unsigned long boot_file_position;
    unsigned long fst_position;
    unsigned long fst_length;
    unsigned long fst_max_length;
    void *fst_address;
    unsigned long user_position;
    unsigned long user_length;
    unsigned long padding0;
} DVDBB2;
int DVDCheckDisk(void);
signed long DVDGetDriveStatus(void);
void DVDInit(void);
DVDCommandChecker __DVDSetOptionalCommandChecker(DVDCommandChecker checker);
int DVDInquiryAsync(DVDCommandBlock *block, DVDDriveInfo *info, DVDCBCallback callback);
void __DVDPrintFatalMessage(void);
int DVDCompareDiskID(const DVDDiskID *first, const DVDDiskID *second);
void __DVDStoreErrorCode(unsigned long error);
void __DVDClearWaitingQueue(void);
int __DVDPushWaitingQueue(int priority, DVDCommandBlock *block);
DVDCommandBlock *__DVDPopWaitingQueue(void);
int __DVDCheckWaitingQueue(void);
int __DVDDequeueWaitingQueue(DVDCommandBlock *block);
int __DVDIsBlockInWaitingQueue(DVDCommandBlock *block);
int DVDReadAbsAsyncForBS(DVDCommandBlock *block, void *address, signed long length,
                         signed long offset, DVDCBCallback callback);
int DVDReadDiskID(DVDCommandBlock *block, DVDDiskID *id, DVDCBCallback callback);
int DVDReadAbsAsyncPrio(DVDCommandBlock *block, void *address, long length, long offset,
                        DVDCBCallback callback, long priority);
signed long DVDCancel(volatile DVDCommandBlock *block);
long DVDGetCommandBlockStatus(const DVDCommandBlock *block);
int DVDSetAutoInvalidation(int enabled);
void DVDResume(void);
DVDDiskID *DVDGetCurrentDiskID(void);
int DVDCancelStreamAsync(DVDCommandBlock *block, DVDCBCallback callback);
void __DVDPrepareResetAsync(DVDCBCallback callback);
void __DVDInitWA(void);
void __DVDInterruptHandler(short interrupt, struct OSContext *context);
int DVDLowRead(void *address, unsigned long length, unsigned long offset, DVDLowCallback callback);
int DVDLowSeek(unsigned long offset, DVDLowCallback callback);
int DVDLowWaitCoverClose(DVDLowCallback callback);
int DVDLowReadDiskID(DVDDiskID *disk_id, DVDLowCallback callback);
int DVDLowStopMotor(DVDLowCallback callback);
int DVDLowRequestError(DVDLowCallback callback);
int DVDLowInquiry(DVDDriveInfo *info, DVDLowCallback callback);
int DVDLowAudioStream(unsigned long subcommand, unsigned long length, unsigned long offset,
                      DVDLowCallback callback);
int DVDLowRequestAudioStatus(unsigned long subcommand, DVDLowCallback callback);
int DVDLowAudioBufferConfig(int enable, unsigned long size, DVDLowCallback callback);
void DVDLowReset(void);
int DVDLowBreak(void);
DVDLowCallback DVDLowClearCallback(void);
void __DVDLowSetWAType(unsigned long type, signed long seek_location);
int __DVDLowTestAlarm(const struct OSAlarm *alarm);
int __DVDTestAlarm(const struct OSAlarm *alarm);
void __DVDFSInit(void);
long DVDConvertPathToEntrynum(const char *path);
int DVDFastOpen(long entry_number, DVDFileInfo *file_info);
int DVDOpen(const char *file_name, DVDFileInfo *file_info);
int DVDClose(DVDFileInfo *file_info);
int DVDGetCurrentDir(char *path, unsigned long max_length);
int DVDReadAsyncPrio(DVDFileInfo *file_info, void *address, long length, long offset,
                     DVDCallback callback, long priority);
long DVDReadPrio(DVDFileInfo *file_info, void *address, long length, long offset, long priority);
long DVDGetTransferredSize(DVDFileInfo *file_info);
void DVDReset(void);
void __fstLoad(void);
extern OSThreadQueue __DVDThreadQueue;
typedef signed long long OSTime;
typedef unsigned long OSTick;
typedef struct OSResetFunctionInfo OSResetFunctionInfo;
typedef struct OSExecParams {
    int valid;
    unsigned long restart_code;
    unsigned long boot_dol;
    void *region_start;
    void *region_end;
    int args_use_default;
    void *args_address;
} OSExecParams;
typedef struct OSFontHeader {
    unsigned short fontType;
    unsigned short firstChar;
    unsigned short lastChar;
    unsigned short invalChar;
    unsigned short ascent;
    unsigned short descent;
    unsigned short width;
    unsigned short leading;
    unsigned short cellWidth;
    unsigned short cellHeight;
    unsigned long sheetSize;
    unsigned short sheetFormat;
    unsigned short sheetColumn;
    unsigned short sheetRow;
    unsigned short sheetWidth;
    unsigned short sheetHeight;
    unsigned short widthTable;
    unsigned long sheetImage;
    unsigned long sheetFullSize;
    unsigned char c0, c1, c2, c3;
} OSFontHeader;
typedef unsigned char __OSException;
typedef unsigned short OSError;
typedef unsigned long OSInterruptMask;
typedef void (*OSAlarmHandler)(OSAlarm *alarm, OSContext *context);
typedef void (*OSSwitchThreadCallback)(OSThread *from, OSThread *to);
typedef struct OSSramEx {
    unsigned char flashID[2][12];
    unsigned long wirelessKeyboardID;
    unsigned short wirelessPadID[4];
    unsigned char dvdErrorCode;
    unsigned char padding0;
    unsigned char flashIDCheckSum[2];
    unsigned short gbs;
    unsigned char padding1[2];
} OSSramEx;
typedef struct OSSram {
    unsigned short checkSum;
    unsigned short checkSumInv;
    unsigned long ead0;
    unsigned long ead1;
    unsigned long counterBias;
    signed char displayOffsetH;
    unsigned char ntd;
    unsigned char language;
    unsigned char flags;
} OSSram;
typedef void *OSMessage;
typedef struct OSMessageQueue {
    OSThreadQueue queueSend;
    OSThreadQueue queueReceive;
    OSMessage *msgArray;
    signed long msgCount;
    signed long firstIndex;
    signed long usedCount;
} OSMessageQueue;
typedef signed short __OSInterrupt;
typedef void (*__OSInterruptHandler)(__OSInterrupt, OSContext *);
typedef void (*OSExceptionHandler)(__OSException, OSContext *);
typedef void (*OSErrorHandler)(OSError error, OSContext *context, ...);
typedef int (*OSResetFunction)(int final);
struct OSResetFunctionInfo {
    OSResetFunction func;
    unsigned long priority;
    OSResetFunctionInfo *next;
    OSResetFunctionInfo *prev;
};
typedef struct OSBootInfo {
    DVDDiskID disk_id;
    unsigned long magic;
    unsigned long version;
    unsigned long memory_size;
    unsigned long console_type;
    void *arena_lo;
    void *arena_hi;
    void *fst_location;
    unsigned long fst_max_length;
} OSBootInfo;
extern unsigned long __OSBusClock : 0x800000F8;
void OSReport(const char *format, ...);
void OSInit(void);
unsigned long OSGetConsoleType(void);
void __OSInitSystemCall(void);
void __OSInitMemoryProtection(void);
void __OSModuleInit(void);
void __OSInterruptInit(void);
void __OSContextInit(void);
void __OSCacheInit(void);
void __OSPSInit(void);
void __OSFPRInit(void);
void __RAS_OSDisableInterrupts_begin(void);
void __RAS_OSDisableInterrupts_end(void);
void __OSInitSram(void);
void __OSThreadInit(void);
void __OSInitAudioSystem(void);
void __OSStopAudioSystem(void);
unsigned long __OSGetDIConfig(void);
void __OSReboot(unsigned long reset_code, unsigned long boot_dol);
void OSGetSaveRegion(void **start, void **end);
void __OSBootDol(unsigned long boot_dol, unsigned long reset_code, char **argv);
void __OSBootDolSimple(unsigned long boot_dol, unsigned long reset_code, void *region_start,
                       void *region_end, int args_use_default, int argc, char **argv);
void __OSGetExecParams(OSExecParams *params);
void OSPanic(const char *file, int line, const char *format, ...);
int OSDisableInterrupts(void);
int OSEnableInterrupts(void);
int OSRestoreInterrupts(int enabled);
unsigned short OSGetFontEncode(void);
int OSInitFont(OSFontHeader *font_data);
char *OSGetFontWidth(const char *string, int *width);
char *OSGetFontTexture(const char *string, void **image, int *x, int *y, int *width);
OSTime OSGetTime(void);
OSTick OSGetTick(void);
OSTime __OSGetSystemTime(void);
OSTime __OSTimeToSystemTime(OSTime time);
void OSRegisterVersion(const char *version);
void OSRegisterResetFunction(OSResetFunctionInfo *info);
void OSClearContext(OSContext *context);
void OSDumpContext(OSContext *context);
void OSSetCurrentContext(OSContext *context);
OSContext *OSGetCurrentContext(void);
unsigned long OSSaveContext(OSContext *context);
void OSSaveFPUContext(OSContext *context);
void OSLoadContext(OSContext *context);
void *OSGetStackPointer(void);
void OSInitContext(OSContext *context, unsigned long program_counter, unsigned long stack_pointer);
void OSInitThreadQueue(OSThreadQueue *queue);
void OSWakeupThread(OSThreadQueue *queue);
void OSSleepThread(OSThreadQueue *queue);
void OSInitMessageQueue(OSMessageQueue *queue, OSMessage *messages, signed long count);
int OSSendMessage(OSMessageQueue *queue, OSMessage message, signed long flags);
int OSReceiveMessage(OSMessageQueue *queue, OSMessage *message, signed long flags);
int OSJamMessage(OSMessageQueue *queue, OSMessage message, signed long flags);
OSThread *OSGetCurrentThread(void);
int OSSuspendThread(OSThread *thread);
int OSResumeThread(OSThread *thread);
int OSDisableScheduler(void);
int OSEnableScheduler(void);
void __OSReschedule(void);
void OSYieldThread(void);
int OSCreateThread(OSThread *thread, void *(*entry)(void *), void *parameter, void *stack,
                   unsigned long stack_size, signed long priority, unsigned short attributes);
void OSExitThread(void *value);
void OSCancelThread(OSThread *thread);
int OSJoinThread(OSThread *thread, void **value);
int OSSetThreadPriority(OSThread *thread, signed long priority);
signed long OSGetThreadPriority(OSThread *thread);
void OSClearStack(unsigned char value);
void __OSPromoteThread(OSThread *thread, signed long priority);
signed long __OSGetEffectivePriority(OSThread *thread);
void OSInitMutex(OSMutex *mutex);
void OSLockMutex(OSMutex *mutex);
void OSUnlockMutex(OSMutex *mutex);
void __OSUnlockAllMutex(OSThread *thread);
int OSTryLockMutex(OSMutex *mutex);
void OSInitCond(OSCond *condition);
void OSWaitCond(OSCond *condition, OSMutex *mutex);
void OSSignalCond(OSCond *condition);
__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);
__OSInterruptHandler __OSGetInterruptHandler(__OSInterrupt interrupt);
OSExceptionHandler __OSGetExceptionHandler(__OSException exception);
OSExceptionHandler __OSSetExceptionHandler(__OSException exception, OSExceptionHandler handler);
OSInterruptMask __OSMaskInterrupts(OSInterruptMask mask);
OSInterruptMask __OSUnmaskInterrupts(OSInterruptMask mask);
OSErrorHandler OSSetErrorHandler(OSError error, OSErrorHandler handler);
void __OSUnhandledException(__OSException exception, OSContext *context, unsigned long cause,
                            unsigned long address);
extern OSErrorHandler __OSErrorTable[17];
extern unsigned short __OSDeviceCode : 0x800030E6;
unsigned int OSGetResetCode(void);
unsigned int OSGetProgressiveMode(void);
void OSSetProgressiveMode(unsigned int mode);
unsigned char OSGetLanguage(void);
unsigned short OSGetWirelessID(signed long channel);
void OSSetWirelessID(signed long channel, unsigned short id);
unsigned short OSGetGbsMode(void);
void OSSetGbsMode(unsigned short mode);
int __OSSyncSram(void);
int __OSReadROM(void *buffer, signed long length, signed long offset);
void OSCreateAlarm(OSAlarm *alarm);
void OSCancelAlarm(OSAlarm *alarm);
void OSInitAlarm(void);
void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);
void OSSetPeriodicAlarm(OSAlarm *alarm, OSTime start, OSTime period, OSAlarmHandler handler);
int OSGetResetButtonState(void);
void __OSResetSWInterruptHandler(__OSInterrupt interrupt, OSContext *context);
void OSResetSystem(int reset, unsigned long reset_code, int force_menu);
int __OSCallResetFunctions(int final);
void __OSDoHotReset(unsigned long reset_code);
OSSramEx *__OSLockSramEx(void);
int __OSUnlockSramEx(int commit);
OSSram *__OSLockSram(void);
int __OSUnlockSram(int commit);
extern u32 __AXSrcCycles[5];
extern u32 __AXMainMixCycles[16];
extern u32 __AXAuxMixCycles[32];
extern AXPB lbl_80164D60[64] __attribute__((aligned(32)));
extern AXPBITDBUFFER __AXITD[64] __attribute__((aligned(32)));
extern AXPBU __AXUpdates[64] __attribute__((aligned(32)));
extern AXVPB __AXVPB[64];
extern u32 __AXMaxDspCycles;
extern u32 __AXRecDspCycles;
extern u32 lbl_801A6B68;

void fn_800224EC(AXVPB *pvpb) {
    AXPB *ppbDsp;
    AXPB *ppbUser;
    u32 sync;
    ((void)0);
    lbl_801A6B68 += 1;
    ppbDsp = &lbl_80164D60[pvpb->index];
    ppbUser = &pvpb->pb;
    sync = pvpb->sync;
    if (sync == 0) {
        ppbUser->state = ppbDsp->state;
        ppbUser->ve.currentVolume = ppbDsp->ve.currentVolume;
        ppbUser->addr.currentAddressHi = ppbDsp->addr.currentAddressHi;
        ppbUser->addr.currentAddressLo = ppbDsp->addr.currentAddressLo;
        return;
    }
    if (sync & (1UL << 31)) {
        u32 *src;
        u32 *dst;
        src = (u32 *)ppbUser;
        dst = (u32 *)ppbDsp;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        if (pvpb->updateCounter != 0) {
            u32 count;
            src = (u32 *)&__AXUpdates[pvpb->index];
            dst = (u32 *)pvpb->updateData;
            for (count = pvpb->updateCounter; count; count--) {
                *(dst) = *(src);
                dst += 1;
                src += 1;
            }
        }
        return;
    }
    if (sync & (1UL << 0)) {
        ppbDsp->srcSelect = ppbUser->srcSelect;
        ppbDsp->coefSelect = ppbUser->coefSelect;
    }
    if (sync & (1UL << 1)) {
        ppbDsp->mixerCtrl = ppbUser->mixerCtrl;
    }
    if (sync & (1UL << 2)) {
        ppbDsp->state = ppbUser->state;
    } else {
        ppbUser->state = ppbDsp->state;
    }
    if (sync & (1UL << 3)) {
        ppbDsp->type = ppbUser->type;
    }
    if (sync & (1UL << 4)) {
        u16 *src;
        u16 *dst;
        src = (u16 *)&ppbUser->mix;
        dst = (u16 *)&ppbDsp->mix;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
    }
    if (sync & (1UL << 6)) {
        ppbDsp->itd.targetShiftL = ppbUser->itd.targetShiftL;
        ppbDsp->itd.targetShiftR = ppbUser->itd.targetShiftR;
    } else if (sync & (1UL << 5)) {
        u16 *src;
        u16 *dst;
        u32 *dst_;
        src = (u16 *)&ppbUser->itd;
        dst = (u16 *)&ppbDsp->itd;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        src += 1;
        dst_ = pvpb->itdBuffer;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
        dst_ += 1;
        *(dst_) = 0;
    }
    if (sync & (1UL << 7)) {
        u16 *src;
        u16 *dst;
        dst = (u16 *)&ppbDsp->update;
        src = (u16 *)&ppbUser->update;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        if (pvpb->updateCounter) {
            u32 *src_;
            u32 *dst_;
            u32 count;
            dst_ = (u32 *)&__AXUpdates[pvpb->index];
            src_ = (u32 *)&pvpb->updateData;
            for (count = pvpb->updateCounter; count; count--) {
                *(dst_) = *(src_);
                dst_ += 1;
                src_ += 1;
            }
        }
    }
    if (sync & (1UL << 8)) {
        u16 *src;
        u16 *dst;
        dst = (u16 *)&ppbDsp->dpop;
        src = (u16 *)&ppbUser->dpop;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
    }
    if (sync & (1UL << 10)) {
        ppbUser->ve.currentVolume = ppbDsp->ve.currentVolume;
        ppbDsp->ve.currentDelta = ppbUser->ve.currentDelta;
    } else if (sync & (1UL << 9)) {
        ppbDsp->ve.currentVolume = ppbUser->ve.currentVolume;
        ppbDsp->ve.currentDelta = ppbUser->ve.currentDelta;
    }
    if (sync & (1UL << 11)) {
        u16 *src;
        u16 *dst;
        dst = (u16 *)&ppbDsp->fir;
        src = (u16 *)&ppbUser->fir;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
    }
    if (sync & ((1UL << 13) | (1UL << 14) | (1UL << 15) | (1UL << 16))) {
        if (sync & (1UL << 13)) {
            ppbDsp->addr.loopFlag = ppbUser->addr.loopFlag;
        }
        if (sync & (1UL << 14)) {
            *(u32 *)&ppbDsp->addr.loopAddressHi = *(u32 *)&ppbUser->addr.loopAddressHi;
        }
        if (sync & (1UL << 15)) {
            *(u32 *)&ppbDsp->addr.endAddressHi = *(u32 *)&ppbUser->addr.endAddressHi;
        }
        if (sync & (1UL << 16)) {
            *(u32 *)&ppbDsp->addr.currentAddressHi = *(u32 *)&ppbUser->addr.currentAddressHi;
        } else {
            *(u32 *)&ppbUser->addr.currentAddressHi = *(u32 *)&ppbDsp->addr.currentAddressHi;
        }
    } else if (sync & (1UL << 12)) {
        u32 *src;
        u32 *dst;
        dst = (u32 *)&ppbDsp->addr;
        src = (u32 *)&ppbUser->addr;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
    } else {
        ppbUser->addr.currentAddressHi = ppbDsp->addr.currentAddressHi;
        ppbUser->addr.currentAddressLo = ppbDsp->addr.currentAddressLo;
    }
    if (sync & (1UL << 17)) {
        u32 *src;
        u32 *dst;
        dst = (u32 *)&ppbDsp->adpcm;
        src = (u32 *)&ppbUser->adpcm;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
    }
    if (sync & (1UL << 19)) {
        ppbDsp->src.ratioHi = ppbUser->src.ratioHi;
        ppbDsp->src.ratioLo = ppbUser->src.ratioLo;
    } else if (sync & (1UL << 18)) {
        u16 *src;
        u16 *dst;
        dst = (u16 *)&ppbDsp->src;
        src = (u16 *)&ppbUser->src;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
    }
    if (sync & (1UL << 20)) {
        u16 *src;
        u16 *dst;
        dst = (u16 *)&ppbDsp->adpcmLoop;
        src = (u16 *)&ppbUser->adpcmLoop;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
    }
    if (sync & 0x400000) {
        ppbDsp->lpf.a0 = ppbUser->lpf.a0;
        ppbDsp->lpf.b0 = ppbUser->lpf.b0;
        return;
    }
    if (sync & 0x200000) {
        u16 *src;
        u16 *dst;
        dst = (u16 *)&ppbDsp->lpf;
        src = (u16 *)&ppbUser->lpf;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
        dst += 1;
        src += 1;
        *(dst) = *(src);
    }
}
