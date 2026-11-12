#ifndef DOL_OS_THREAD_STATICS_H
#define DOL_OS_THREAD_STATICS_H

#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSThread.h>

/* OSThread.c's file-scope run queues (one per priority), threads and idle context. Code
 * reaches the threads and the context only through RunQueue's base (__OSThreadInit,
 * SelectThread), so dtk had no symbol for them; the names are the SDK's. */
extern OSThreadQueue RunQueue[32];
extern OSThread IdleThread;    /* 0x318 bytes */
extern OSThread DefaultThread; /* 0x318 bytes */
extern OSContext IdleContext;  /* 0x2C8 bytes */

#endif
