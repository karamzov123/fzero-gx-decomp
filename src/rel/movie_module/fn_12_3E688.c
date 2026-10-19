
#include "types.h"

typedef unsigned char CFTConvTable[256];

void fn_12_3E688(CFTConvTable luma, CFTConvTable chroma_u, CFTConvTable chroma_v);

void fn_12_3E688(CFTConvTable luma, CFTConvTable chroma_u, CFTConvTable chroma_v) {
    int i;
    int j;
    int v;
    int t;
    j = 0;
    v = 0;
    while (j < 0x10) {
        luma[j++] = v++;
        luma[j++] = v;
        v += 2;
    }
    while (j < 0xB0) {
        luma[j] = v;
        luma[j + 1] = v;
        j += 2;
        v++;
    }
    while (j < 0xC0) {
        luma[j] = v;
        v++;
        j++;
    }
    while (j < 0x100) {
        t = 0xFF;
        if (v < 0xFF) {
            t = v;
        }
        luma[j] = t;
        v += 2;
        j++;
    }
    j = 0x80;
    v = j;
    while (j > 0x68) {
        chroma_u[j] = v;
        chroma_v[j] = v;
        chroma_u[j - 1] = v;
        chroma_v[j - 1] = v;
        chroma_u[j - 2] = v;
        chroma_v[j - 2] = v;
        j -= 3;
        v--;
    }
    for (i = j; i >= 0; i--) {
        chroma_u[i] = i * v / j;
        chroma_v[i] = i * v / j;
    }
    v = 0x80;
    t = v;
    while (v < 0x98) {
        chroma_u[v] = t;
        chroma_v[v] = t;
        chroma_u[v + 1] = t;
        chroma_v[v + 1] = t;
        chroma_u[v + 2] = t;
        chroma_v[v + 2] = t;
        v += 3;
        t++;
    }
    i = v;
    for (; v <= 0xFF; v++) {
        chroma_u[v] = t + (0xFF - t) * (v - i) / (0xFF - i);
        chroma_v[v] = t + (0xFF - t) * (v - i) / (0xFF - i);
    }
}
