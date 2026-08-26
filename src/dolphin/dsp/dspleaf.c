#pragma push
#pragma force_active on

typedef unsigned int u32;

volatile u32 DSP_REGS_LEAF[] : 0xCC006C00;

struct MAILBITS {
    u32 lo24 : 24;
    u32 mid  : 8;
};
// provenance: original
u32 AIGetStreamPlayState_Leaf(void)
{
    return (DSP_REGS_LEAF[0] >> 1) & 1;
}

// provenance: original
void DSPWriteMailHi(u32 mail)
{
    u32 v = DSP_REGS_LEAF[1];
    DSP_REGS_LEAF[1] = (v & 0xFFFFFF00) | (mail & 0xFF);
}

// provenance: original
u32 DSPReadMailLo(void)
{
    return DSP_REGS_LEAF[1] & 0xFF;
}

// provenance: original
void DSPWriteMailMid(u32 mail)
{
    u32 v = DSP_REGS_LEAF[1];
    DSP_REGS_LEAF[1] = (v & 0xFFFF00FF) | ((mail & 0xFF) << 8);
}

// provenance: original
u32 DSPReadMailHi(void)
{
    return (DSP_REGS_LEAF[1] >> 8) & 0xFF;
}

#pragma pop
