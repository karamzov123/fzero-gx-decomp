#pragma push
#pragma force_active on

__declspec(section ".init") void* memcpy(void* dst, const void* src,
                                         unsigned long n)
{
    const unsigned char* s;
    unsigned char* d;

    if ((unsigned long) src >= (unsigned long) dst) {
        s = (const unsigned char*) src - 1;
        d = (unsigned char*) dst - 1;
        n++;
        while (--n != 0) {
            *++d = *++s;
        }
    } else {
        s = (const unsigned char*) src + n;
        d = (unsigned char*) dst + n;
        n++;
        while (--n != 0) {
            *--d = *--s;
        }
    }
    return dst;
}

#pragma pop
