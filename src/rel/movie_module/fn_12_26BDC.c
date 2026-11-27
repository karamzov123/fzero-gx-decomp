#include "types.h"

/* --- rel/movie_module/fn_12_26BDC.c --- */
/* --- rel/movie_module/fn_12_26BDC.c --- */
extern void fn_12_24A88(void *, int);

void fn_12_26BDC(void *arg) {
    fn_12_24A88(arg, 0xff000f0d);
}

/* --- rel/movie_module/fn_12_26C04.c --- */
// fn_12_26C04: returns a constant.
int fn_12_26C04(void) {
    return 0;
}

typedef struct SfdHandle SfdHandle;

typedef struct SfdTransportState {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_context[8];
            void *context;
        } view_context;
    } fields;
} SfdTransportState;

struct SfdHandle {
    union {
        unsigned char padding_extent[13720];
        struct {
            unsigned char padding_transports[6816];
            SfdTransportState transports[9];
        } view_transports;
    } fields;
};

static inline int sfmpv_StopSub(SfdHandle *handle) {
    int result;
    result = 0;
    if (handle->fields.view_transports.transports[2].fields.view_context.context == 0) {
        result = 0;
    }
    return result;
}

int fn_12_26C0C(SfdHandle *handle) { return sfmpv_StopSub(handle); }
