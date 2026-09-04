#pragma push
#pragma force_active on

// __msl_strcpy: byte-copy loop (strncpy-like inner copy)
// provenance: natc5: register-swap - p (src) declared before q (dst) keeps src in incoming r4, dst in r5
char* __msl_strcpy(char* dst, const char* src)
{
    const unsigned char* p = (const unsigned char*)src - 1;
    unsigned char* q = (unsigned char*)dst - 1;
    do {} while (*++q);
    q -= 1;
    do {} while (*++q = *++p);
    return dst;
}


// provenance: mkdd:libs/PowerPC_EABI_Support/src/MSL_C/MSL_Common/string.c:76
char* strncpy(char* dst, const char* src, unsigned long n)
{
    const unsigned char* p = (const unsigned char*)src - 1;
    unsigned char* q = (unsigned char*)dst - 1;
    unsigned char zero = 0;

    n++;
    while (--n)
        if (!(*++q = *++p)) {
            while (--n)
                *++q = 0;
            break;
        }
    return dst;
}

#define K1 0x80808080
#define K2 0xFEFEFEFF

// provenance: tp:libs/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/string.c:18 (irreducible CFG in MSL word loop)
char* strcpy(char* dst, const char* src) {
    register unsigned char *destb, *fromb;
    register unsigned long w, t, align;

    fromb = (unsigned char*)src;
    destb = (unsigned char*)dst;

    if ((align = ((int)fromb & 3)) != ((int)destb & 3)) {
        goto bytecopy;
    }

    if (align) {
        if ((*destb = *fromb) == 0) {
            return dst;
        }

        for (align = 3 - align; align; align--) {
            if ((*(++destb) = *(++fromb)) == 0) {
                return dst;
            }
        }
        ++destb;
        ++fromb;
    }

    w = *((int*)(fromb));

    t = (w + K2) & K1;
    if (t) {
        goto bytecopy;
    }
    --((int*)(destb));

    do {
        *(++((int*)(destb))) = w;
        w = *(++((int*)(fromb)));

        t = (w + K2) & K1;
        if (t) {
            goto adjust;
        }
    } while (1);

adjust:
    ++((int*)(destb));

bytecopy:
    if ((*destb = *fromb) == 0) {
        return dst;
    }

    do {
        if ((*(++destb) = *(++fromb)) == 0) {
            return dst;
        }
    } while (1);

    return dst;
}

// provenance: sms:src/PowerPC_EABI_Support/Msl/MSL_C/MSL_Common/string.c:6
int strlen(const char* s) {
    const unsigned char* p = (const unsigned char*)s - 1;
    int len = -1;
    do { ++len; } while (*++p);
    return len;
}

#pragma pop
