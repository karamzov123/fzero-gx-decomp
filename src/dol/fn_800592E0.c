#include "types.h"

typedef void (*SVMCallbackFunction)(void *object);
typedef void (*SVMErrorFunction)(void *object, const char *message);
typedef int (*SVMServerFunction)(void *object);

struct SVMServerCallback {
    SVMServerFunction function;
    void *object;
};

struct SVMCallback {
    SVMCallbackFunction function;
    void *object;
};

struct SVMErrorCallback {
    SVMErrorFunction function;
    void *object;
};

// Hardware or OS state can change asynchronously.
volatile int lbl_8018FEB0;
// Hardware or OS state can change asynchronously.
volatile int lbl_8018FEB0__fzgx_offset_4;
// Hardware or OS state can change asynchronously.
volatile int lbl_8018FEB0__fzgx_offset_8;
char lbl_8018FEB0__fzgx_offset_C[16];
struct SVMCallback lbl_8018FEB0__fzgx_offset_1C;
struct SVMCallback lbl_8018FEB0__fzgx_offset_24;
int (*lbl_8018FEB0__fzgx_offset_2C)(int *value);
char lbl_8018FEE0[128];
struct SVMErrorCallback lbl_8018FF60;
struct SVMCallback lbl_8018FF68;
struct SVMCallback lbl_8018FF70;
struct SVMCallback lbl_8018FF78[8];
struct SVMServerCallback lbl_8018FF78__fzgx_offset_40[8][6];
int lbl_8018FF78__fzgx_offset_1C0[8];
int lbl_8018FF78__fzgx_offset_1E0[8];

extern const char lbl_80092384[];
extern const char lbl_80092350[];
extern const char lbl_800924A4[];
extern const char lbl_800924C4[];
extern void SVM_CallErr(const char *message, ...);
extern void *memset(void *destination, int value, unsigned long size);
extern char *strncpy(char *destination, const char *source, unsigned long size);

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; // fzgx-allow: S2 BSS primer ordering
    s = *(u8 *)&lbl_8018FEB0;
    s = *(u8 *)&lbl_8018FEB0__fzgx_offset_4;
    s = *(u8 *)&lbl_8018FEB0__fzgx_offset_8;
    s = *(u8 *)&lbl_8018FEB0__fzgx_offset_C;
    s = *(u8 *)&lbl_8018FEB0__fzgx_offset_1C;
    s = *(u8 *)&lbl_8018FEB0__fzgx_offset_24;
    s = *(u8 *)&lbl_8018FEB0__fzgx_offset_2C;
    s = *(u8 *)&lbl_8018FEE0;
    s = *(u8 *)&lbl_8018FF60;
    s = *(u8 *)&lbl_8018FF68;
    s = *(u8 *)&lbl_8018FF70;
    s = *(u8 *)&lbl_8018FF78;
    s = *(u8 *)&lbl_8018FF78__fzgx_offset_40;
    s = *(u8 *)&lbl_8018FF78__fzgx_offset_1C0;
    s = *(u8 *)&lbl_8018FF78__fzgx_offset_1E0;
}
#pragma section code_type ".text"

static inline void svm_call_err1(const char *message) {
    strncpy(lbl_8018FEE0, message, sizeof(lbl_8018FEE0) - 1);
    if (lbl_8018FF60.function != 0) {
        lbl_8018FF60.function(lbl_8018FF60.object, lbl_8018FEE0);
    }
}

static inline void svm_unlock(int type) {
    if (lbl_8018FF68.function != 0) {
        lbl_8018FEB0__fzgx_offset_4 = lbl_8018FEB0__fzgx_offset_4 - 1;
        if (lbl_8018FEB0__fzgx_offset_4 == 0) {
            if (lbl_8018FEB0__fzgx_offset_8 != type) {
                SVM_CallErr(lbl_80092384, lbl_8018FEB0__fzgx_offset_8, type);
            }
            lbl_8018FEB0__fzgx_offset_8 = 0;
        }
        lbl_8018FF68.function(lbl_8018FF68.object);
    }
}

static inline void svm_lock(int type) {
    if (lbl_8018FF70.function != 0) {
        lbl_8018FF70.function(lbl_8018FF70.object);
        if (lbl_8018FEB0__fzgx_offset_4 == 0) {
            lbl_8018FEB0__fzgx_offset_8 = type;
        }
        lbl_8018FEB0__fzgx_offset_4 = lbl_8018FEB0__fzgx_offset_4 + 1;
    }
}

static inline int svm_exec_svr(int server_type) {
    struct SVMServerCallback *callback;
    int index;
    int result;

    result = 0;
    callback = lbl_8018FF78__fzgx_offset_40[server_type];
    for (index = 0; index < 6; index++) {
        if (callback->function != 0) {
            lbl_8018FF78__fzgx_offset_1C0[server_type] = 1;
            result |= callback->function(callback->object);
            lbl_8018FF78__fzgx_offset_1C0[server_type] = 0;
        }
        callback++;
    }
    lbl_8018FF78__fzgx_offset_1E0[server_type]++;
    return result;
}

static inline void svm_clear(void) {
    int index;
    int *counter;

    memset(lbl_8018FF78__fzgx_offset_1C0, 0, sizeof(lbl_8018FF78__fzgx_offset_1C0));
    memset(&lbl_8018FF70, 0, sizeof(lbl_8018FF70));
    memset(&lbl_8018FF68, 0, sizeof(lbl_8018FF68));
    memset(&lbl_8018FEB0__fzgx_offset_24, 0, sizeof(lbl_8018FEB0__fzgx_offset_24));
    memset(&lbl_8018FEB0__fzgx_offset_1C, 0, sizeof(lbl_8018FEB0__fzgx_offset_1C));
    counter = lbl_8018FF78__fzgx_offset_1E0;
    for (index = 0; index < 6; index++) {
        *counter++ = 0;
    }
    lbl_8018FEB0__fzgx_offset_2C = 0;
}

void fn_800592E0(int server_type, int id) {
    if (id < 0 || id >= 6) {
        svm_call_err1(lbl_800924A4);
    }
    svm_lock(1);
    lbl_8018FF78__fzgx_offset_40[server_type][id].function = 0;
    lbl_8018FF78__fzgx_offset_40[server_type][id].object = 0;
    svm_unlock(1);
}
