#include "types.h"
int sprintf(char* s, const char* format, ...);
char* strcpy(char* dst, const char* src);
int strncmp(const char* s1, const char* s2, unsigned long n);
unsigned long strlen(const char* s);
void* memcpy(void* dst, const void* src, unsigned long n);


typedef enum CvFsStatus {
    CVFS_STATUS_IDLE = 0,
    CVFS_STATUS_COMPLETE = 1,
    CVFS_STATUS_TRANSFERRING = 2,
    CVFS_STATUS_ERROR = 3
} CvFsStatus;

typedef struct CvFsInterface CvFsInterface;
typedef struct CvFsObject CvFsObject;
typedef void (*CvFsErrorCallback)(void* object, const char* message,
                                  void* handle);
typedef CvFsInterface* (*CvFsInterfaceFactory)(void);

struct CvFsInterface {
    void (*ExecServer)(void);
    void (*EntryErrFunc)(CvFsErrorCallback callback, void* object);
    int (*GetFileSize)(const char* filename);
    int (*GetFreeSize)(void);
    void* (*Open)(const char* filename, void* parameter, int mode);
    void (*Close)(void* object);
    int (*Seek)(void* object, int offset, int origin);
    int (*Tell)(void* object);
    int (*ReqRd)(void* object, int sectors, void* buffer);
    int (*ReqWr)(void* object, int sectors, void* buffer);
    void (*StopTr)(void* object);
    CvFsStatus (*GetStat)(void* object);
    int (*GetSctLen)(void* object);
    void (*SetSctLen)(void* object, int sector_length);
    int (*GetNumTr)(void* object);
    int (*ChangeDir)(const char* dirname);
    int (*IsExistFile)(const char* filename);
    int (*GetNumFiles)(void);
    int (*LoadDirInfo)(const char* dirname, void* info, int count);
    int (*GetMaxByteRate)(void* object);
    int (*MakeDir)(const char* dirname);
    int (*RemoveDir)(const char* dirname);
    int (*DeleteFile)(const char* filename);
    int (*GetFileSizeEx)(const char* filename, void* parameter);
    int (*OptFn1)(void* object, int operation, int arg2, int arg3);
    int (*OptFn2)(void* object, int arg1, int arg2, int arg3);
};

struct CvFsObject {
    CvFsInterface* interface;
    void* object;
};

typedef struct CvFsDevice {
    CvFsInterface* interface;
    char name[9];
} CvFsDevice;


#pragma section ".fzgxpool" ".fzgxpool"
#pragma push
#pragma force_active on
static const char fzgx_pool_ver[48] = "\nCVFS/GC Ver.2.33 Build:May  9 2003 17:09:56\n";
/* volatile required to keep CRI build version pointer in .rodata */
const char* const volatile lbl_80091390__fzgx_offset_30 = fzgx_pool_ver;
static const char fzgx_pool_path_format[8] = "%s:%s";
static const char fzgx_pool_set_default_volume_bad_device[40] =
    "cvFsSetDefVol #1:illegal device name";
static const char fzgx_pool_set_default_volume_bad_volume[40] =
    "cvFsSetDefVol #2:illegal volume name";
static const char fzgx_pool_set_default_volume_no_device[36] =
    "cvFsSetDefVol #3:device not found";
static const char fzgx_pool_get_volume_info_bad_device[44] =
    "cvFsGetVolumeInfo #1:illegal device name";
static const char fzgx_pool_get_volume_info_bad_volume[44] =
    "cvFsGetVolumeInfo #2:illegal volume name";
static const char fzgx_pool_get_volume_info_no_device[40] =
    "cvFsGetVolumeInfo #3:device not found";
static const char fzgx_pool_delete_volume_bad_device[40] =
    "cvFsDelVolume #1:illegal device name";
static const char fzgx_pool_delete_volume_bad_volume[40] =
    "cvFsDelVolume #2:illegal volume name";
static const char fzgx_pool_delete_volume_no_device[36] =
    "cvFsDelVolume #3:device not found";
static const char fzgx_pool_add_volume_bad_device[40] =
    "cvFsAddVolumeEx #1:illegal device name";
static const char fzgx_pool_add_volume_bad_volume[40] =
    "cvFsAddVolumeEx #2:illegal volume name";
static const char fzgx_pool_add_volume_bad_handle[40] =
    "cvFsAddVolumeEx #3:illegal image handle";
static const char fzgx_pool_add_volume_no_device[36] =
    "cvFsAddVolumeEx #3:device not found";
static const char fzgx_pool_set_volume_bad_device[40] =
    "cvFsSetCurVolume #1:illegal device name";
static const char fzgx_pool_set_volume_bad_handle[44] =
    "cvFsSetCurVolume #2:illegal image handle";
static const char fzgx_pool_set_volume_no_device[40] =
    "cvFsSetCurVolume #3:device not found";
static const char fzgx_pool_opt2_bad_handle[28] = "cvFsOptFn2 #1:handle error";
static const char fzgx_pool_opt2_bad_interface[28] = "cvFsOptFn2 #2:vtbl error";
static const char fzgx_pool_opt1_bad_handle[28] = "cvFsOptFn1 #1:handle error";
static const char fzgx_pool_opt1_bad_interface[28] = "cvFsOptFn1 #2:vtbl error";
static const char fzgx_pool_get_device_name_bad_interface[32] =
    "cvFsGetDevName #1:vtbl error";
static const char fzgx_pool_delete_file_bad_name[36] =
    "cvFsDeleteFile #1:illegal file name";
static const char fzgx_pool_delete_file_bad_device[40] =
    "cvFsDeleteFile #2:illegal device name";
static const char fzgx_pool_delete_file_no_device[36] =
    "cvFsDeleteFile #3:device not found";
static const char fzgx_pool_delete_file_bad_interface[32] =
    "cvFsDeleteFile #4:vtbl error";
static const char fzgx_pool_remove_dir_bad_name[40] =
    "cvFsRemoveDir #1:illegal directory name";
static const char fzgx_pool_remove_dir_bad_device[40] =
    "cvFsRemoveDir #2:illegal device name";
static const char fzgx_pool_remove_dir_no_device[36] =
    "cvFsRemoveDir #3:device not found";
static const char fzgx_pool_remove_dir_bad_interface[28] =
    "cvFsRemoveDir #4:vtbl error";
static const char fzgx_pool_make_dir_bad_name[40] =
    "cvFsMakeDir #1:illegal directory name";
static const char fzgx_pool_make_dir_bad_device[36] =
    "cvFsMakeDir #2:illegal device name";
static const char fzgx_pool_make_dir_no_device[32] =
    "cvFsMakeDir #3:device not found";
static const char fzgx_pool_make_dir_bad_interface[28] =
    "cvFsMakeDir #4:vtbl error";
static const char fzgx_pool_max_rate_bad_handle[36] =
    "cvFsGetMaxByteRate #1:handle error";
static const char fzgx_pool_max_rate_bad_interface[36] =
    "cvFsGetMaxByteRate #2:vtbl error";
static const char fzgx_pool_exists_bad_device[40] =
    "cvFsIsExistFile #2:illegal device name";
static const char fzgx_pool_exists_bad_name[40] =
    "cvFsIsExistFile #1:illegal file name";
static const char fzgx_pool_exists_no_device[36] =
    "cvFsIsExistFile #3:device not found";
static const char fzgx_pool_exists_bad_interface[32] =
    "cvFsIsExistFile #4:vtbl error";
static const char fzgx_pool_change_dir_bad_name[40] =
    "cvFsChangeDir #1:illegal directory name";
static const char fzgx_pool_change_dir_bad_device[40] =
    "cvFsChangeDir #2:illegal device name";
static const char fzgx_pool_change_dir_no_device[36] =
    "cvFsChangeDir #3:device not found";
static const char fzgx_pool_change_dir_bad_interface[28] =
    "cvFsChangeDir #4:vtbl error";
static const char fzgx_pool_num_transfers_bad_handle[32] =
    "cvFsGetNumTr #1:handle error";
static const char fzgx_pool_num_transfers_bad_interface[28] =
    "cvFsGetNumTr #2:vtbl error";
static const char fzgx_pool_set_sector_bad_handle[32] =
    "cvFsSetSctLen #3:handle error";
static const char fzgx_pool_set_sector_bad_interface[28] =
    "cvFsSetSctLen #4:vtbl error";
static const char fzgx_pool_get_sector_bad_handle[32] =
    "cvFsGetSctLen #1:handle error";
static const char fzgx_pool_get_sector_bad_interface[28] =
    "cvFsGetSctLen #2:vtbl error";
static const char fzgx_pool_free_size_no_device[36] =
    "cvFsGetFreeSize #5:device not found";
static const char fzgx_pool_free_size_bad_interface[32] =
    "cvFsGetFreeSize #6:vtbl error";
static const char fzgx_pool_size_by_handle_bad_handle[48] =
    "cvFsGetFileSizeByHndl #1:illegal file handle";
static const char fzgx_pool_size_ex_bad_name[40] =
    "cvFsGetFileSizeEx #1:illegal file name";
static const char fzgx_pool_size_ex_bad_device[44] =
    "cvFsGetFileSizeEx #2:illegal device name";
static const char fzgx_pool_size_ex_no_device[40] =
    "cvFsGetFileSizeEx #3:device not found";
static const char fzgx_pool_size_ex_bad_interface[32] =
    "cvFsGetFileSizeEx #4:vtbl error";
static const char fzgx_pool_size_bad_name[40] =
    "cvFsGetFileSize #1:illegal file name";
static const char fzgx_pool_size_bad_device[40] =
    "cvFsGetFileSize #2:illegal device name";
static const char fzgx_pool_size_no_device[36] =
    "cvFsGetFileSize #3:device not found";
static const char fzgx_pool_size_bad_interface[32] =
    "cvFsGetFileSize #4:vtbl error";
static const char fzgx_pool_status_bad_handle[28] = "cvFsGetStat #1:handle error";
static const char fzgx_pool_status_bad_interface[28] = "cvFsGetStat #2:vtbl error";
static const char fzgx_pool_stop_bad_handle[28] = "cvFsStopTr #1:handle error";
static const char fzgx_pool_stop_bad_interface[28] = "cvFsStopTr #2:vtbl error";
static const char fzgx_pool_write_bad_handle[28] = "cvFsReqWr #1:handle error";
static const char fzgx_pool_write_bad_interface[24] = "cvFsReqWr #2:vtbl error";
static const char fzgx_pool_read_bad_handle[28] = "cvFsReqRd #1:handle error";
static const char fzgx_pool_read_bad_interface[24] = "cvFsReqRd #2:vtbl error";
static const char fzgx_pool_seek_bad_handle[28] = "cvFsSeek #1:handle error";
static const char fzgx_pool_seek_bad_interface[24] = "cvFsSeek #2:vtbl error";
static const char fzgx_pool_tell_bad_handle[28] = "cvFsTell #1:handle error";
static const char fzgx_pool_tell_bad_interface[24] = "cvFsTell #2:vtbl error";
static const char fzgx_pool_close_bad_handle[28] = "cvFsClose #1:handle error";
static const char fzgx_pool_close_bad_interface[24] = "cvFsClose #2:vtbl error";
static const char fzgx_pool_open_bad_name[32] = "cvFsOpen #1:illegal file name";
static const char fzgx_pool_open_no_handle[36] = "cvFsOpen #3:failed handle alloced";
static const char fzgx_pool_open_bad_device[32] = "cvFsOpen #2:illegal device name";
static const char fzgx_pool_open_no_device[32] = "cvFsOpen #4:device not found";
static const char fzgx_pool_open_bad_interface[24] = "cvFsOpen #5:vtbl error";
static const char fzgx_pool_open_failed[24] = "cvFsOpen #6:open failed";
static const char fzgx_pool_set_default_bad_device[40] =
    "cvFsSetDefDev #1:illegal device name";
static const char fzgx_pool_set_default_unknown_device[40] =
    "cvFsSetDefDev #2:unknown device name";
static const char fzgx_pool_delete_device_bad_name[36] =
    "cvFsDelDev #1:illegal device name";
static const char fzgx_pool_add_device_bad_name[36] =
    "cvFsAddDev #1:illegal device name";
static const char fzgx_pool_add_device_bad_factory[36] =
    "cvFsAddDev #2:illegal I/F func name";
static const char fzgx_pool_add_device_failed[36] =
    "cvFsAddDev #3:failed added a device";

static CvFsErrorCallback lbl_80187430 = NULL;
static void* lbl_80187434 = NULL;
int lbl_80187434__fzgx_offset_4 = 0;
static char lbl_80187434__fzgx_offset_8[297];
static char lbl_80187434__fzgx_offset_134[9];
static CvFsDevice lbl_80187574[32];
static CvFsObject lbl_80187574__fzgx_offset_200[40];
#pragma pop
#define cvfs_build lbl_80091390__fzgx_offset_30
#define cvfs_errfn lbl_80187430
#define cvfs_errobj lbl_80187434
#define cvfs_init_cnt lbl_80187434__fzgx_offset_4
#define add_dev_tmp lbl_80187434__fzgx_offset_8
#define cvfs_defdev lbl_80187434__fzgx_offset_134
#define cvfs_tbl lbl_80187574
#define cvfs_obj lbl_80187574__fzgx_offset_200

void fn_80055580(void);

static inline void cvFsError(const char* message)
{
    if (cvfs_errfn != NULL) {
        cvfs_errfn(cvfs_errobj, message, NULL);
    }
}

static inline void toUpperStr(char* string)
{
    unsigned long i;
    unsigned long length = strlen(string);

    for (i = 0; i < length + 1; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 'a' - 'A';
        }
    }
}

static inline void cvfs_add_dev_inline(char* file, const char* device)
{
    strcpy(add_dev_tmp, file);
    sprintf(file, fzgx_pool_path_format, device, add_dev_tmp);
}
#pragma push
#pragma force_active on
__declspec(section ".fzgxpool") static void fzgx_pool_primer(void)
{
    cvfs_errfn = NULL;
    add_dev_tmp[0] = fzgx_pool_path_format[0];
    cvfs_defdev[0] = 0;
    cvfs_tbl[0].interface = NULL;
    cvfs_obj[0].object = NULL;
}
#pragma pop

static inline CvFsInterface* getDevice(const char* name)
{
    unsigned int length = strlen(name);
    unsigned long i;

    for (i = 0; i < 32; i++) {
        if (strncmp(name, cvfs_tbl[i].name, length) == 0) {
            return cvfs_tbl[i].interface;
        }
    }
    return NULL;
}

static inline int isExistingDevice(const char* name, int length)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (strncmp(name, cvfs_tbl[i].name, length) == 0) {
            return 1;
        }
    }
    return 0;
}

static inline void getDefaultDevice(char* name)
{
    unsigned long length = strlen(cvfs_defdev);

    if (cvfs_defdev[0] == '\0') {
        name[0] = '\0';
    } else {
        memcpy(name, cvfs_defdev, length + 1);
    }
}

static inline void splitPath(char* device, char* file, const char* path)
{
    int device_index;
    int file_index;
    int write_index;

    if (path == NULL) {
        return;
    }

    for (device_index = 0; device_index < 297; device_index++) {
        if (path[device_index] == ':' || path[device_index] == '\0') {
            break;
        }
        device[device_index] = path[device_index];
    }

    if (path[device_index] == '\0') {
        device[device_index] = '\0';
        memcpy(file, device, strlen(device) + 1);
        device[0] = '\0';
        return;
    }

    device[device_index] = '\0';
    device_index++;
    if (device_index == 2) {
        device_index = 0;
        device[0] = '\0';
    }

    write_index = device_index;
    for (file_index = device_index; file_index < 297; file_index++) {
        if (path[file_index] == '\0') {
            break;
        }
        file[write_index++ - device_index] = path[file_index];
    }
    file[write_index - device_index] = '\0';
    toUpperStr(device);
}

static inline int callPathOption(CvFsInterface* interface)
{
    int result;

    if (interface == NULL) {
        result = 0;
    } else if (interface->OptFn1 != NULL) {
        result = interface->OptFn1(NULL, 100, 0, 0);
    } else {
        result = 0;
    }
    return result;
}

static inline CvFsInterface* findDevice(CvFsDevice* table, const char* name,
                                        int length)
{
    CvFsDevice* device;
    unsigned long i;

    device = table;
    for (i = 0; i < 32; i++) {
        if (strncmp(name, device->name, length) == 0) {
            return cvfs_tbl[i].interface;
        }
        device++;
    }
    return NULL;
}

static inline CvFsInterface* searchDevice(CvFsDevice* table, const char* name)
{
    unsigned long i;
    int length;

    length = strlen(name);
    for (i = 0; i < 32; i++) {
        if (strncmp(name, table[i].name, length) == 0) {
            return cvfs_tbl[i].interface;
        }
    }
    return NULL;
}

static inline int wantsDevicePrefix(CvFsDevice* table, const char* name,
                                    int length)
{
    return callPathOption(findDevice(table, name, length)) == 1;
}

static inline CvFsInterface* resolveDevice(char* device, char* file,
                                           const char* original_path)
{
    CvFsInterface* interface;
    CvFsDevice* table;
    const char* lookup_name;
    long length;

    if (device[0] == '\0') {
        getDefaultDevice(device);
        if (device[0] == '\0') {
            return NULL;
        }
    }

    lookup_name = device;
    if (lookup_name == NULL) {
        lookup_name = cvfs_defdev;
    }
    length = strlen(lookup_name);
    table = cvfs_tbl;
    if (wantsDevicePrefix(table, lookup_name, length)) {
        cvfs_add_dev_inline(file, lookup_name);
    }
    interface = searchDevice(table, device);
    if (interface == NULL) {
        getDefaultDevice(device);
        interface = searchDevice(table, device);
        if (interface == NULL) {
            return NULL;
        }
        strcpy(file, original_path);
    }
    return interface;
}

static inline void* allocateHandle(void)
{
    int i;

    for (i = 0; i < 40; i++) {
        if (cvfs_obj[i].object == NULL) {
            break;
        }
    }
    if (i == 40) {
        return NULL;
    }
    return &cvfs_obj[i];
}

static inline void releaseHandle(CvFsObject* handle)
{
    handle->object = NULL;
    handle->interface = NULL;
}

static inline CvFsInterface* addDevice(char* name,
                                       CvFsInterfaceFactory factory)
{
    CvFsInterface* interface;
    int i;

    toUpperStr(name);
    interface = factory();
    if (getDevice(name) != NULL) {
        return interface;
    }

    for (i = 0; i < 32; i++) {
        if (cvfs_tbl[i].name[0] == '\0') {
            break;
        }
    }
    if (i == 32) {
        return NULL;
    }

    cvfs_tbl[i].interface = interface;
    memcpy(cvfs_tbl[i].name, name, strlen(name) + 1);
    return interface;
}



extern void *memset(void *, int, unsigned long);
extern char lbl_80091C80[];
extern char lbl_80091C9C[];
extern u32 lbl_80091D54[];
extern u32 lbl_80091D70[];
extern u32 lbl_80091D88[];
extern u32 lbl_80091DA4[];
extern char lbl_80091E70[37];
extern char lbl_80091E98[184];


extern char lbl_80091CEC[], lbl_80091D08[], lbl_80091D20[], lbl_80091D3C[];
void fn_8005466C(u32 arg0, u32 arg1) {
    if (arg0 == 0) {
        cvfs_errfn = 0;
        cvfs_errobj = 0;
    } else {
        cvfs_errfn = (CvFsErrorCallback)arg0;
        cvfs_errobj = (void *)arg1;
    }
}

typedef u32 (*fn_800546A0_Fn0)(u32, u32, u32);
typedef u32 (*fn_800546A0_Fn1)(u32);

struct fn_800546A0_Object {
    u32 vtable;
    u32 value;
};

extern char lbl_80091C48[28];
extern char lbl_80091C64[26];

s32 fn_800546A0(struct fn_800546A0_Object *arg0) {
    s32 result = 3;

    if (arg0 == 0) {
        if (cvfs_errfn != 0) {
            ((fn_800546A0_Fn0)cvfs_errfn)(((u32)cvfs_errobj), (u32)&lbl_80091C48, 0);
        }
        return 3;
    } else if (*(u32 *)((u8 *)arg0->vtable + 44) != 0) {
        result = ((fn_800546A0_Fn1)*(u32 *)((u8 *)arg0->vtable + 44))(arg0->value);
    } else if (cvfs_errfn != 0) {
        ((fn_800546A0_Fn0)cvfs_errfn)(((u32)cvfs_errobj), (u32)&lbl_80091C64, 0);
    }

    return result;
}

extern CvFsDevice lbl_80187574[32];

void cvFsExecServer(void) {
    int i;
    CvFsInterface *interface;
    for (i = 0; i < 32; i++) {
        interface = lbl_80187574[i].interface;
        if (interface != ((void *)0) && interface->ExecServer != ((void *)0)) {
            interface->ExecServer();
        }
    }
}

typedef u32 (*fn_800547C8_Fn0)(u32, u32, u32);
typedef u32 (*fn_800547C8_Fn1)(u32);

void fn_800547C8(u32 arg0) {
    if (arg0 == 0) {
        if (((u32)cvfs_errfn) != 0) {
            ((fn_800547C8_Fn0)((u32)cvfs_errfn))(((u32)cvfs_errobj), (u32)&lbl_80091C80, 0);
        }
    } else {
        if (*(u32 *)((u8 *)*(u32 *)(arg0) + 40) != 0) {
            ((fn_800547C8_Fn1)*(u32 *)((u8 *)*(u32 *)(arg0) + 40))(*(u32 *)(arg0 + 4));
        } else {
            if (((u32)cvfs_errfn) != 0) {
                ((fn_800547C8_Fn0)((u32)cvfs_errfn))(((u32)cvfs_errobj), (u32)&lbl_80091C9C, 0);
            }
        }
    }
}

int fn_80054870(CvFsObject *handle, int offset, int origin) {
    int result;
    if (handle == ((void *)0)) {
        cvFsError(lbl_80091CEC);
        return 0;
    }
    if (handle->interface->ReqRd != ((void *)0)) {
        result = handle->interface->ReqRd(
            handle->object, offset, (void *)origin);
    } else {
        result = 0;
        cvFsError(lbl_80091D08);
    }
    return result;
}

int fn_80054930(CvFsObject *handle, int offset, int origin) {
    int result;
    if (handle == ((void *)0)) {
        cvFsError(lbl_80091D20);
        return 0;
    }
    if (handle->interface->Seek != ((void *)0)) {
        result = handle->interface->Seek(handle->object, offset, origin);
    } else {
        result = 0;
        cvFsError(lbl_80091D3C);
    }
    return result;
}

typedef u32 (*fn_800549F0_Fn0)(u32, u32, u32);
typedef u32 (*fn_800549F0_Fn1)(u32);
typedef u32 (*fn_800549F0_Fn2)(u32, u32, u32);
s32 fn_800549F0(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0, t1, t2;
    v0 = arg0;
    if (arg0 == 0) {
    v1 = arg1;
    v2 = arg2;
    if (((u32)cvfs_errfn) != 0) {
    v2 = (u32)&lbl_80187434;
    v1 = (u32)&lbl_80091D54;
    v0 = *(u32 *)(v2);
    v2 = 0;
    t0 = ((fn_800549F0_Fn0)((u32)cvfs_errfn))(v0, v1, v2);
    v0 = t0;
    }
    v0 = 0;
    } else {
    v1 = *(u32 *)(v0);
    v2 = *(u32 *)(v1 + 28);
    if (v2 != 0) {
    v0 = *(u32 *)(v0 + 4);
    t1 = ((fn_800549F0_Fn1)v2)(v0);
    v0 = t1;
    v3 = v0;
    } else {
    v3 = 0;
    if (((u32)cvfs_errfn) != 0) {
    v0 = ((u32)cvfs_errobj);
    t2 = ((fn_800549F0_Fn2)((u32)cvfs_errfn))(v0, (u32)&lbl_80091D70, 0);
    v0 = t2;
    }
    }
    v0 = v3;
    }
    return v0;
}

typedef u32 (*fn_80054AB0_Fn0)(u32, u32, u32);
typedef u32 (*fn_80054AB0_Fn1)(u32);
typedef u32 (*fn_80054AB0_Fn2)(u32, u32, u32);
void fn_80054AB0(void *arg0) {
    s32 (*temp_r12)(s32);

    if (arg0 == NULL) {
        if (((u32)cvfs_errfn) != 0) {
            ((s32 (*)(u32, u32 *, s32))(((u32)cvfs_errfn)))(((u32)cvfs_errobj), lbl_80091D88, 0);
        }
    } else {
        temp_r12 = (s32 (*)(s32))(*(s32 (**)(s32))((u8 *)((*(void **)((u8 *)(arg0)))) + 20));
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)((u8 *)(arg0) + 4));
            (*(s32 *)((u8 *)(arg0) + 4)) = 0;
            (*(void **)((u8 *)(arg0))) = NULL;
            return;
        }
        if (((u32)cvfs_errfn) != 0) {
            ((s32 (*)(u32, u32 *, s32))(((u32)cvfs_errfn)))(((u32)cvfs_errobj), lbl_80091DA4, 0);
        }
    }
}

CvFsObject* fn_80054B6C(const char* filename, void* parameter, int mode)
{
    CvFsObject* handle;
    char device[297];
    char file[297];
    char* device_name;

    if (filename == NULL) {
        cvFsError(fzgx_pool_open_bad_name);
        return NULL;
    }

    splitPath(device, file, filename);
    if (file[0] == '\0') {
        cvFsError(fzgx_pool_open_bad_name);
        return NULL;
    }

    handle = allocateHandle();
    if (handle == NULL) {
        cvFsError(fzgx_pool_open_no_handle);
        return NULL;
    }

    device_name = device;
    handle->interface = resolveDevice(device_name, file, filename);
    if (device == NULL) {
        releaseHandle(handle);
        cvFsError(fzgx_pool_open_bad_device);
        return NULL;
    }
    if (handle->interface == NULL) {
        releaseHandle(handle);
        cvFsError(fzgx_pool_open_no_device);
        return NULL;
    }
    if (handle->interface->Open != NULL) {
        handle->object = handle->interface->Open(file, parameter, mode);
    } else {
        releaseHandle(handle);
        cvFsError(fzgx_pool_open_bad_interface);
        return NULL;
    }
    if (handle->object == NULL) {
        releaseHandle(handle);
        cvFsError(fzgx_pool_open_failed);
        return NULL;
    }
    return handle;
}

struct fn_800551D0_entry {
    u32 unk_0;
    char text[12];
};

struct fn_800551D0_state {
    void (*callback)(u32, u32, u32);
    u32 callback_arg;
    u8 unk_8[0x130];
    char buffer[0xc];
    struct fn_800551D0_entry entries[0x20];
};

static inline s32 fn_800551D0_find(char *arg0, struct fn_800551D0_entry *entry, u32 len) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        if (strncmp(arg0, entry->text, len) == 0) {
            return 1;
        }
        entry++;
    }
    return 0;
}

void fn_800551D0(char *arg0) {
    struct fn_800551D0_state *state;
    u32 len;
    u32 count;
    s32 i;

    state = ((struct fn_800551D0_state *)&lbl_80187430);
    if (arg0 == 0) {
        if (state->callback != 0) {
            state->callback(state->callback_arg, (u32)&lbl_80091E70, 0);
        }
        return;
    }
    len = strlen(arg0);
    if (len == 0) {
        state->buffer[0] = 0;
        return;
    }
    count = strlen(arg0) + 1;
    for (i = 0; i < count; i++) {
        if (arg0[i] >= 'a' && arg0[i] <= 'z') {
            arg0[i] -= 0x20;
        }
    }
    if (fn_800551D0_find(arg0, state->entries, len) == 1) {
        memcpy(state->buffer, arg0, len + 1);
        return;
    }
    if (state->callback != 0) {
        state->callback(state->callback_arg, (u32)&lbl_80091E98, 0);
    }
}

void fn_80055304(char* name, CvFsInterfaceFactory factory, void* init_parameter)
{
    CvFsInterface* interface;

    cvfs_build;

    if (name == NULL) {
        cvFsError(fzgx_pool_add_device_bad_name);
        return;
    }
    if (factory == NULL) {
        cvFsError(fzgx_pool_add_device_bad_factory);
        return;
    }

    interface = addDevice(name, factory);
    if (interface == NULL) {
        cvFsError(fzgx_pool_add_device_failed);
    } else if (interface->EntryErrFunc != NULL) {
        interface->EntryErrFunc((CvFsErrorCallback)fn_80055580, NULL);
    }
}

typedef void (*fn_80055580_Fn0)(void *);
void fn_80055580(void) {
    if (cvfs_errfn != NULL) {
        ((fn_80055580_Fn0)cvfs_errfn)(cvfs_errobj);
    }
}
