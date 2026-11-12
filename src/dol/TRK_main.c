#include "types.h"

extern void MWTRACE(int level, const char *message, ...);
extern int TRKInitializeNub(void);
extern void TRKNubWelcome(void);
extern void TRKNubMainLoop(void);
extern int TRKTerminateNub(void);
extern int TRK_mainError __attribute__((section(".data")));

void TRK_main(void) {
    int error;

    MWTRACE(1, "TRK_Main \n");
    error = TRKInitializeNub();
    TRK_mainError = error;
    if (error == 0) {
        TRKNubWelcome();
        TRKNubMainLoop();
    }
    error = TRKTerminateNub();
    TRK_mainError = error;
}
