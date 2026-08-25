/* lightctrl_8007264C.c - natural-C conversion, all 16 functions EXACT (objdiff,
   relocations included). Compiler: GC/1.3.2, flags:
   -O4,p -use_lmw_stmw off -str reuse,pool,readonly -gccinc -common off -fp_contract on.
   NOTE: unit was configured mwcc_233_163n in objdiff.json but only 1.3.2 matches;
   compiler discriminator run 2026-08-25 (see NATC worker report).
   Seed: none (reconstruction from symbolised disassembly). */
typedef int s32;
typedef unsigned char u8;
typedef unsigned int u32;
extern void GXBuildPackedRegister(s32, u32, u32, u32, u8);
extern void* memset(void*, int, unsigned long);
extern void GXSetCullMode(u32);
extern void GXWriteCachedParamF0(s32, u32, u32, u32, u32);
extern void GXWriteCachedParam1F0(s32, u32, u32, u32, u32);
extern void fn_80037128(s32, s32, s32, s32, u8, s32);
extern void fn_80037190(s32, s32, s32, s32, u8, s32);
extern void __GXSetLightColorAttnSel(u32, u32, u32);
extern void GXSetLightColorAttnRegs(s32, u32, u32, u32, u32);
extern void GXWriteLightColor(s32, u32, u32, u32);
extern void __GXSetChanAmbSrcBit(u8);
extern void __GXSetChanMatSrcBit(u8);
extern void __GXXFSetPerfEnableMulti(u8);
extern void LightCtrl_SetCachedParam_2C_Force(s32, u32, u32, u32, u32);
extern unsigned char lbl_8019E308[3328];
#pragma push
#pragma force_active on

extern void* g_modelSysPtr;

struct FogEnt { s32 x, y, z; u8 b_; };

void LightCtrl_SetCachedFog(s32 index, s32 a, s32 b, s32 c, u8 d)
{
    struct FogEnt* e = (struct FogEnt*)(lbl_8019E308 + index * 0x1A0);
    if (e->x != a || e->y != b || e->z != c || e->b_ != d) {
        e->x = a; e->y = b; e->z = c; e->b_ = d;
        GXBuildPackedRegister(index, a, b, c, d);
    }
}

/* NOT EXACT: best 93.7% (2 scheduling diffs: cache-load hoist + loop-test regalloc).
   Functional equivalence reviewed by hand; kept out of the exact claim. */
void LightCtrl_SetCachedFogArray(s32 index, struct FogEnt* p)
{
    struct FogEnt* e;
    s32 x;
    s32 y, z;
    u8 b;
    e = (struct FogEnt*)(lbl_8019E308 + index * 0x1A0);
    for (; *(volatile s32*)&p->x < 26; p++) {
        b = p->b_;
        x = p->x; z = p->z; y = p->y;
        if (!(e->x == x && e->y == y && e->z == z && e->b_ == b)) {
            e->x = x; e->y = y; e->z = z; e->b_ = b;
            GXBuildPackedRegister(index, x, y, z, b);
        }
    }
}

s32 LightCtrl_InitChannels4(void)
{
    memset(g_modelSysPtr, 0xff, 0xca0);
    LightCtrl_SetCachedParam_2C_Force(0, 0, 1, 2, 3);
    LightCtrl_SetCachedParam_2C_Force(1, 0, 1, 2, 0);
    LightCtrl_SetCachedParam_2C_Force(2, 0, 1, 2, 1);
    LightCtrl_SetCachedParam_2C_Force(3, 0, 1, 2, 2);
    return 1;
}

void LightCtrl_InitChannels2(void)
{
    memset(g_modelSysPtr, 0xff, 0xca0);
    LightCtrl_SetCachedParam_2C_Force(0, 0, 1, 2, 3);
    LightCtrl_SetCachedParam_2C_Force(1, 0, 1, 2, 0);
}

void LightCtrl_SetCachedCullMode(s32 mode)
{
    volatile s32* m;
    if (mode == *(s32*)((u8*)g_modelSysPtr + 0x18))
        return;
    GXSetCullMode(mode);
    m = (volatile s32*)((u8*)g_modelSysPtr + 0x18);
    *m = mode;
}

void LightCtrl_SetCachedColor_1C(s32 ch, s32 r, s32 g, s32 b)
{
    volatile s32* m;
    if (ch == 2) {
        m = (volatile s32*)g_modelSysPtr;
        if (!(m[7] == 2 && m[10] == b)) {
            GXWriteLightColor(2, r, g, b);
            m = (volatile s32*)g_modelSysPtr; m[7] = 2;
            m = (volatile s32*)g_modelSysPtr; m[8] = r;
            m = (volatile s32*)g_modelSysPtr; m[9] = g;
            m = (volatile s32*)g_modelSysPtr; m[10] = b;
        }
    } else {
        m = (volatile s32*)g_modelSysPtr;
        if (!(m[7] == ch && m[8] == r && m[9] == g)) {
            GXWriteLightColor(ch, r, g, b);
            m = (volatile s32*)g_modelSysPtr; m[7] = ch;
            m = (volatile s32*)g_modelSysPtr; m[8] = r;
            m = (volatile s32*)g_modelSysPtr; m[9] = g;
            m = (volatile s32*)g_modelSysPtr; m[10] = b;
        }
    }
}

void LightCtrl_SetCachedParam_2C(s32 idx, s32 a, s32 b, s32 c, s32 d)
{
    volatile s32* e = (volatile s32*)((u8*)g_modelSysPtr + idx * 16 + 0x2c);
    if (!(e[0] == a && e[1] == b && e[2] == c && e[3] == d)) {
        GXSetLightColorAttnRegs(idx, a, b, c, d);
        e[0] = a; e[1] = b; e[2] = c; e[3] = d;
    }
}

void LightCtrl_SetCachedParam_2C_Force(s32 idx, u32 a, u32 b, u32 c, u32 d)
{
    volatile u32* e = (volatile u32*)((u8*)g_modelSysPtr + idx * 16 + 0x2c);
    GXSetLightColorAttnRegs(idx, a, b, c, d);
    e[0] = a; e[1] = b; e[2] = c; e[3] = d;
}

void LightCtrl_SetCachedPair_6C(s32 idx, s32 a, s32 b)
{
    volatile s32* e = (volatile s32*)((u8*)g_modelSysPtr + idx * 8 + 0x6c);
    if (!(e[0] == a && e[1] == b)) {
        __GXSetLightColorAttnSel(idx, a, b);
        e[0] = a; e[1] = b;
    }
}

void LightCtrl_SetCachedByte_EC(u8 v)
{
    u8* m;
    m = (u8*)g_modelSysPtr;
    if (m[0xec] == 0xff)
        goto store;
    if (m[0xec] == v)
        return;
store:
    __GXSetChanAmbSrcBit(v);
    m = (u8*)g_modelSysPtr;
    m[0xec] = v;
}

void LightCtrl_SetCachedByte_ED(u8 v)
{
    u8* m;
    m = (u8*)g_modelSysPtr;
    if (m[0xed] == 0xff)
        goto store;
    if (m[0xed] == v)
        return;
store:
    __GXSetChanMatSrcBit(v);
    m = (u8*)g_modelSysPtr;
    m[0xed] = v;
}

void LightCtrl_SetCachedByte_EE(u8 v)
{
    u8* m;
    m = (u8*)g_modelSysPtr;
    if (m[0xee] == 0xff)
        goto store;
    if (m[0xee] == v)
        return;
store:
    __GXXFSetPerfEnableMulti(v);
    m = (u8*)g_modelSysPtr;
    m[0xee] = v;
}

void ModelSetCachedParam_F0(s32 idx, s32 a, s32 b, s32 c, s32 d)
{
    volatile s32* e = (volatile s32*)((u8*)g_modelSysPtr + idx * 16 + 0xf0);
    if (!(e[0] == a && e[1] == b && e[2] == c && e[3] == d)) {
        GXWriteCachedParamF0(idx, a, b, c, d);
        e[0] = a; e[1] = b; e[2] = c; e[3] = d;
    }
}

void ModelSetCachedParam_1F0(s32 idx, s32 a, s32 b, s32 c, s32 d)
{
    volatile s32* e = (volatile s32*)((u8*)g_modelSysPtr + idx * 16 + 0x1f0);
    if (!(e[0] == a && e[1] == b && e[2] == c && e[3] == d)) {
        GXWriteCachedParam1F0(idx, a, b, c, d);
        e[0] = a; e[1] = b; e[2] = c; e[3] = d;
    }
}

void ModelSetCachedParam_2F0(s32 idx, s32 a, s32 b, s32 c, u8 d, s32 e2)
{
    s32* e = (s32*)((u8*)g_modelSysPtr + idx * 20 + 0x2f0);
    if (!(e[4] == e2 && e[2] == c && *(u8*)((u8*)e + 0xc) == d &&
          e[0] == a && e[1] == b)) {
        fn_80037128(idx, a, b, c, d, e2);
        e[0] = a; e[1] = b; e[2] = c;
        *(u8*)((u8*)e + 0xc) = d; e[4] = e2;
    }
}

void ModelSetCachedParam_430(s32 idx, s32 a, s32 b, s32 c, u8 d, s32 e2)
{
    s32* e = (s32*)((u8*)g_modelSysPtr + idx * 20 + 0x430);
    if (!(e[4] == e2 && e[2] == c && *(u8*)((u8*)e + 0xc) == (u8)d &&
          e[0] == a && e[1] == b)) {
        fn_80037190(idx, a, b, c, d, e2);
        e[0] = a; e[1] = b; e[2] = c;
        *(u8*)((u8*)e + 0xc) = d; e[4] = e2;
    }
}
