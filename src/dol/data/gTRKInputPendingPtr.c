/* MetroTRK shares this pointer between initialization and the main loop. */
#ifdef VERSION_GFZE01
void *gTRKInputPendingPtr __attribute__((aligned(32)));
#else
void *gTRKInputPendingPtr __attribute__((aligned(16)));
#endif
