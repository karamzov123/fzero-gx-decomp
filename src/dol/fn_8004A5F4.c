#include "types.h"

typedef struct ADXStream {
    s8 used;
    s8 status;
    s8 read_active;
    s8 retry_count;
    void *sj;
    void *file;
    s32 file_offset;
    s32 file_size;
    u8 pad_14[0x2D];
    s8 stop_requested;
    s8 bind_requested;
    s8 release_requested;
    s8 start_requested;
    s8 stop_pending;
    u8 pad_46[6];
    char *filename;
    void *directory;
    /* volatile: retail reloads this field from memory (lwz) after storing it */
    volatile s32 position;
} ADXStream;

extern void fn_80054AB0(void *file);
extern s32 fn_80059B44(void);
extern s32 fn_80059AB4(void);
extern void *fn_80054B6C(char *filename, void *directory, int mode);
extern char lbl_80090990[];
extern void fn_80047464(char *message, char *filename);
extern int fn_80054930(void *file, int operation, int arg2);
extern s32 fn_800549F0(void *file);
extern void fn_8004A80C(ADXStream *stream);

void fn_8004A5F4(ADXStream *arg0) {
    s32 sectors;
    s32 bytes;

    if (arg0->read_active == 0) {
        if (arg0->start_requested == 1) {
            arg0->start_requested = 0;
            if (arg0->release_requested == 0) {
                arg0->status = 1;
            }
        }
        if (arg0->bind_requested == 1) {
            void *handle = arg0->file;
            if (handle != 0) {
                arg0->file = 0;
                fn_80054AB0(handle);
            }
            arg0->bind_requested = 0;
            arg0->stop_pending = 0;
        }
        fn_80059B44();
        if (arg0->stop_requested == 1) {
            arg0->stop_pending = 1;
            fn_80059AB4();
            if (arg0->file == 0) {
                void *handle = fn_80054B6C(arg0->filename, arg0->directory, 0);
                arg0->file = handle;
                if (handle == 0) {
                    fn_80047464(lbl_80090990, arg0->filename);
                    arg0->status = 4;
                    arg0->stop_pending = 0;
                    arg0->stop_requested = 0;
                    return;
                }
                fn_80054930(arg0->file, 0, 2);
                sectors = fn_800549F0(arg0->file);
                bytes = sectors << 11;
                fn_80054930(arg0->file, 0, 0);
                if (arg0->file_size + 0x80010000u == 0xF800u) {
                    arg0->file_size = bytes;
                } else {
                    if (arg0->file_offset > sectors) {
                        arg0->file_offset = sectors;
                    }
                    if ((arg0->file_size / 0x800) + arg0->file_offset > sectors) {
                        arg0->file_size = (sectors - arg0->file_offset) * 0x800;
                    }
                }
                arg0->position = 0;
                if (arg0->position * 0x800 > arg0->file_size) {
                    arg0->position = (arg0->file_size / 0x800) +
                        (arg0->file_size % 0x800 > 0);
                }
                arg0->stop_requested = 0;
            }
        } else {
            fn_80059AB4();
        }
        if (arg0->release_requested == 1) {
            arg0->release_requested = 0;
        }
    }
    if (arg0->status == 2) {
        if (arg0->stop_pending == 1) {
            fn_8004A80C(arg0);
        }
    }
}
