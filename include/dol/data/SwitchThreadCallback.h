#ifndef DATA_SWITCHTHREADCALLBACK_H
#define DATA_SWITCHTHREADCALLBACK_H

#include "types.h"

typedef struct {
    void (*at_0)(void);
} Data_SwitchThreadCallback;
extern Data_SwitchThreadCallback SwitchThreadCallback;

#endif
