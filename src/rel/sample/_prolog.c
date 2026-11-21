#include "types.h"

/* the key string lives in .rodata, so the file builds its literals read-only */
#pragma readonly_strings on

extern int fn_18_3FC(int, int, int, int);
extern u32 OSGetTick(void);
extern void *memset(void *, int, u32);
struct PrologFile { u8 pad[0x34]; u32 length; u32 callback; };
struct PrologModule { u8 pad[0x20]; u32 size; u8 pad24[0x10]; u32 entry; u8 pad38[0x10]; u32 offset; };
extern int DVDOpen(const char *, struct PrologFile *);
extern int DVDClose(struct PrologFile *);
extern void *OSAllocFromArenaHi(u32,u32);
extern u32 fn_80006354(struct PrologFile *,void *,u32,u32);
extern u32 sample_lz_decode(void *,void *);
extern void *OSGetArenaLo(void);
extern void OSSetArenaLo(void *);
extern struct PrologModule *OSAllocFromArenaLo(u32,u32);
extern u32 OSLinkFixed(struct PrologModule *,void *);
static inline u32 next_key(u64 state) {
    return (u64)state * 0x180A9B36BB94ULL + 0xCD8F3;
}
u32 _prolog(void) {
    const char *magic;
    s32 v0;
    s32 v1;
    struct PrologFile file;
    struct { u8 a[121]; } loc_47;
    u32 t0;
    int t2;
    void *t3;
    u8 *name;
    u32 key;
    u32 half;
    u32 size;
    u32 *data;
    u32 i;
    void *bss;
    u32 moduleSize;
    void * lab_t0;
    magic = "FUCK";
    t0 = fn_18_3FC((0x20000 - 13115), 9561, 324, (0x310000 + 4425));
    v0 = t0 * (((OSGetTick()) & (t0 - 1)) + 1);
    t2 = fn_18_3FC((0x2CA0000 - 7570), (0x10000 - 12838), 24859, (0x680000 + 17194));
    v1 = -t2;
    name = (u8 *)(((u32)&loc_47.a[3] & ~0x3));
    lab_t0 = name;
    t3 = memset(lab_t0, 98, 40);
    __stwbrx(*(u32 *)magic ^ 11566, name, 0);
    key = v1 - 0x461CB145;
    name[2] += 0x10;
    name[3] += 0x27;
    __stwbrx(key,name,4);
    name[16] = name[15] = key >> 8;
    name[11] = name[6];
    name[12] = name[7];
    half = __lhbrx(name,10) + 0x203;
    *(u16 *)(name+8) = half;
    name[14] = half;
    name[13] = half >> 8;
    name[10] -= 0x33;
    name[17] -= 0x34;
    name[20] += 12;
    *(u32 *)(name+20) ^= 0x62A782;
    name[19] ^= 11;
    DVDOpen((char *)name,&file);
    lab_t0 = name;
    memset(lab_t0, 0, 50);
    size = (file.length + t0 - 1) & ~(t0 - 1);
    data = OSAllocFromArenaHi(size,t0);
    fn_80006354(&file,data,size,0);
    DVDClose(&file);
    for(i=0;i<size/4;i++) {
        v1 = next_key((u32)v1);
        data[i] ^= v1;
    }
{
    struct PrologModule *module;
    module = (struct PrologModule *)(v0 + (u32)OSGetArenaLo());
    sample_lz_decode(data,module);
    bss = (void *)((((((u32)module) + (31)) + module->offset)) & ~31);
    moduleSize = (u32)bss + module->size - (u32)module;
    OSSetArenaLo(module);
    module = OSAllocFromArenaLo(moduleSize,32);
    OSLinkFixed(module,bss);
    return module->entry;
}
}


// Key-schedule helper used by the line__.bin loader stub: a + (c * b - d).
int fn_18_3FC(int a, int b, int c, int d) {
    return a + (c * b - d);
}


typedef struct Fn18_444_Args {
    u8 *src;
    u8 *dst;
    void (*callback)(u32 size);
} Fn18_444_Args;

u32 *fn_18_444(Fn18_444_Args *args);

u32 sample_lz_decode(void *src, void *dst) {
    Fn18_444_Args args;
    args.src = (u8 *)src;
    args.dst = (u8 *)dst;
    args.callback = 0;
    return *fn_18_444(&args);
}

#define N 4096
#define F 18
#define THRESHOLD 2


u32 *fn_18_444(Fn18_444_Args *args) {
    u8 c;
    s32 k;
    u32 size;
    s32 r;
    void (*callback)(u32 size);
    u8 *p;
    u8 *dst;
    u8 *out;
    s32 j;
    u8 text_buf[N + F - 1];
    s32 i;
    u32 flags;
    u32 end;
    u8 *src;

    src = args->src;
    callback = args->callback;
    out = args->dst;
    end = __lwbrx(src, 0) + 8;
    size = __lwbrx(src, 4);
    if (end == 0 || size == 0) {
        return NULL;
    }
    p = src + 8;
    dst = out;
    for (i = 0; i < N - F; i++) {
        text_buf[i] = 0;
    }
    r = N - F;
    flags = 0;
    for (;;) {
        if (((flags >>= 1) & 0x100) == 0) {
            if (p - src >= end) {
                break;
            }
            flags = *p++ | 0xFF00;
        }
        if (flags & 1) {
            if (p - src >= end) {
                break;
            }
            c = *p++;
            *dst++ = c;
            text_buf[r++] = c;
            r &= N - 1;
        } else {
            if (p - src >= end) {
                break;
            }
            i = p[0];
            if (p + 1 - src >= end) {
                break;
            }
            j = p[1];
            p += 2;
            i |= (j & 0xF0) << 4;
            j = (j & 0x0F) + THRESHOLD;
            for (k = 0; k <= j; k++) {
                c = text_buf[(i + k) & (N - 1)];
                *dst++ = c;
                text_buf[r++] = c;
                r &= N - 1;
            }
        }
    }
    if (callback != NULL) {
        callback(size);
    }
    return &size;
}
