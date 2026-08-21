typedef unsigned int u32;

extern u32 __OSArenaLo;
extern u32 __OSArenaHi;

u32 OSGetArenaHi(void)
{
    return __OSArenaHi;
}

u32 OSGetArenaLo(void)
{
    return __OSArenaLo;
}

void OSSetArenaHi(u32 newHi)
{
    __OSArenaHi = newHi;
}

void OSSetArenaLo(u32 newLo)
{
    __OSArenaLo = newLo;
}
