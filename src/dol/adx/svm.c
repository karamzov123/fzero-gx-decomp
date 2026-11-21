#include "types.h"

typedef struct MkVaListState {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} __va_list[1];

int fn_8008077C(char *output, const char *format, __va_list args);

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

const char *const lbl_80092350__fzgx_offset_30 = "\nSVM/GC Ver.1.51 Build:May  9 2003 17:10:11\n";
extern const char lbl_80092350[];
static const char lbl_80092384[] = "2103102:SVM:svm_unlock:lock type miss match.(type org=%d, type now=%d)";
static const char lbl_80092384__fzgx_offset_48[] = "1071301:SVM_ExecSvrFuncId:illegal id";
static const char lbl_80092384__fzgx_offset_70[] = "1071302:SVM_ExecSvrFuncId:illegal svtype";
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
    s = *(u8 *)&lbl_80092384;
    s = *(u8 *)&lbl_80092384__fzgx_offset_48;
    s = *(u8 *)&lbl_80092384__fzgx_offset_70;
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


unsigned int fn_80058A40(int *value) {
    unsigned int result;
    int previous;
    if (lbl_8018FEB0__fzgx_offset_2C != 0) {
        result = lbl_8018FEB0__fzgx_offset_2C(value);
    } else {
        svm_lock(1);
        previous = *value;
        *value = 1;
        result = (unsigned int)((1 - previous) | (previous - 1)) >> 31;
        svm_unlock(1);
    }
    return result;
}



static inline void svm_clear(void) {
    int index;
    int *counter;

    memset(lbl_8018FF78__fzgx_offset_1C0, 0, sizeof(lbl_8018FF78__fzgx_offset_1C0));
    memset(&lbl_8018FF70, 0, sizeof(lbl_8018FF70));
    memset(&lbl_8018FF68, 0, sizeof(lbl_8018FF68));
    counter = lbl_8018FF78__fzgx_offset_1E0;
    for (index = 0; index < 6; index++) {
        *counter++ = 0;
    }
    lbl_8018FEB0__fzgx_offset_2C = 0;
}

void fn_80058B54(void) {
    lbl_8018FEB0--;
    if (lbl_8018FEB0 == 0) {
        svm_clear();
        memset(&lbl_8018FF60, 0, sizeof(lbl_8018FF60));
    }
}





void fn_80058BFC(void) {
    if (lbl_8018FEB0 == 0) {
        svm_clear();
    }
    lbl_8018FEB0++;
}




int fn_80058C94(void) { return svm_exec_svr(6); }




int fn_80058D24(void) { return svm_exec_svr(5); }




int fn_80058DB4(void) { return svm_exec_svr(4); }




int fn_80058E44(void) { return svm_exec_svr(2); }

void fn_80058ED4(SVMCallbackFunction func, void *obj) {
    lbl_8018FF68.function = func;
    lbl_8018FF68.object = obj;
}

void fn_80058EE4(SVMCallbackFunction func, void *obj) {
    lbl_8018FF70.function = func;
    lbl_8018FF70.object = obj;
}




void fn_80058EF4(SVMErrorFunction function, void *object) {
    svm_lock(1);
    lbl_8018FF60.function = function;
    lbl_8018FF60.object = object;
    svm_unlock(1);
}

void fn_80058FE4(int idx) {
    if (lbl_8018FF78[idx].function != 0) {
        lbl_8018FF78[idx].function(lbl_8018FF78[idx].object);
    }
}




void fn_80059028(int server_id, SVMCallbackFunction function, void *object) {
    svm_lock(1);
    lbl_8018FF78[server_id].function = function;
    lbl_8018FF78[server_id].object = object;
    svm_unlock(1);
}




void fn_8005912C(int server_type, int id, SVMServerFunction function, void *object) {
    struct SVMServerCallback *callback;

    if (id < 0 || id >= 6) {
        svm_call_err1("1071201:SVM_SetCbSvrId:illegal id");
    }
    if (server_type < 0 || id >= 8) {
        svm_call_err1("1071202:SVM_SetCbSvrId:illegal svtype");
    }
    svm_lock(1);
    callback = &lbl_8018FF78__fzgx_offset_40[server_type][id];
    if (callback->function != 0) {
        svm_call_err1("2100801:SVM_SetCbSvrId:over write callback function.");
    }
    callback->function = function;
    callback->object = object;
    svm_unlock(1);
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




int fn_80059428(int server_type, SVMServerFunction function, void *object) {
    int id;
    struct SVMServerCallback *callback;

    svm_lock(1);
    callback = lbl_8018FF78__fzgx_offset_40[server_type];
    for (id = 0; id < 6; callback++, id++) {
        if (callback->function == 0) {
            callback->function = function;
            callback->object = object;
            break;
        }
    }
    if (id == 6) {
        svm_call_err1(lbl_800924C4);
    }
    svm_unlock(1);
    if (id == 6) {
        return -1;
    }
    return id;
}

void fn_800595A4(const char *msg) {
    strncpy(lbl_8018FEE0, msg, 127);
    if (lbl_8018FF60.function != 0) {
        lbl_8018FF60.function(lbl_8018FF60.object, lbl_8018FEE0);
    }
}

void SVM_CallErr(const char *message, ...) {
    __va_list arguments;
    memset(lbl_8018FEE0, 0, sizeof(lbl_8018FEE0));
    ((void)(message), __builtin_va_info(&(arguments)));
    fn_8008077C(lbl_8018FEE0, message, arguments);
    if (lbl_8018FF60.function != 0) {
        lbl_8018FF60.function(lbl_8018FF60.object, lbl_8018FEE0);
    }
    ((void)0);
}




void fn_800596D4(void) { svm_unlock(5); }




void fn_80059764(void) { svm_unlock(4); }




void fn_800597F4(void) { svm_unlock(3); }




void fn_80059884(void) { svm_unlock(2); }




void fn_80059914(void) { svm_lock(5); }




void fn_8005997C(void) { svm_lock(4); }




void fn_800599E4(void) { svm_lock(3); }




void fn_80059A4C(void) { svm_lock(2); }




void fn_80059AB4(void) { svm_unlock(1); }




void fn_80059B44(void) { svm_lock(1); }
