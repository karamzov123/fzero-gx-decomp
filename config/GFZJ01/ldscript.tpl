MEMORY
{
    text : origin = $ORIGIN
}

SECTIONS
{
    GROUP:
    {
        $SECTIONS
        .stack ALIGN(0x100):{}
    } > text

    _stack_end = $LAST_SECTION_SYMBOL + SIZEOF($LAST_SECTION_NAME);
    _stack_addr = (_stack_end + $STACKSIZE + 0x7) & ~0x7;
    _db_stack_addr = (_stack_addr + 0x2000);
    _db_stack_end = _stack_addr;
    __ArenaLo = (_db_stack_addr + 0x1f) & ~0x1f;
    __ArenaHi = $ARENAHI;

    /* Hardware register blocks: retail addresses them through linker-defined absolute symbols
       (lis/addi of the symbol, never a folded literal), as the SDK's own link script did.
       Declare them `extern vu32 __DIRegs[];` (or a register struct) in C. A name here must
       not exist in symbols.txt: GX's __cpReg/__peReg/__piReg/__memReg are .sbss pointer
       variables, not these. */
    __VIRegs = 0xCC002000;
    __PIRegs = 0xCC003000;
    __MEMRegs = 0xCC004000;
    __DSPRegs = 0xCC005000;
    __DIRegs = 0xCC006000;
    __DVDRegs = 0xCC006000;
    __SIRegs = 0xCC006400;
    SIRegs = 0xCC006400;
    __EXIRegs = 0xCC006800;
    EXIRegs = 0xCC006800;
    __AIRegs = 0xCC006C00;
    __OSBusClock = 0x800000F8;
    GameChoice = 0x800030E3;
    __GXFifo = 0xCC008000;
    /* SDK absolute globals; configure.py generates their C constants. */
    DAT_800030e2 = 0x800030E2;
    DAT_cc003000 = 0xCC003000;
    OS_CURRENT_FPU_CONTEXT = 0x800000D8;
    __OSCurrentThread = 0x800000E4;
    __OSDeviceCode = 0x800030E6;
    __OSFPUContext = 0x800000D8;
    __OSModuleInfoList = 0x800030C8;
    __OSModuleList = 0x800030C8;
    __OSStringTable = 0x800030D0;
    /* SDK absolute globals; configure.py generates their C constants. */
    __EXIProbeStartTime = 0x800030C0;
    /* SDK absolute globals; configure.py generates their C constants. */
    OS_CURRENT_CONTEXT = 0x800000D4;
    __OSCurrentContext = 0x800000D4;
    /* SDK absolute globals; configure.py generates their C constants. */
    __OSGlobalInterruptMask = 0x800000C4;
    __OSLocalInterruptMask = 0x800000C8;
    __OSSystemCallVectorAddress = 0x80000C00;
    __OSTimeAdjust = 0x800030D8;
    /* SDK absolute globals; configure.py generates their C constants. */
    __OSAudioInitBuffer = 0x81000000;
    __OSPhysicalMemSize = 0x80000028;
    __OSSimulatedMemSize = 0x800000F0;
    __OSUnmappedMemory = 0x81800000;
    /* SDK absolute globals; configure.py generates their C constants. */
    BOOT_REGION_END = 0x812FDFEC;
    BOOT_REGION_START = 0x812FDFF0;
    OS_CURRENT_THREAD = 0x800000E4;
    OS_REBOOT_BOOL = 0x800030E2;
    OS_THREAD_QUEUE = 0x800000DC;
    UNK_817FFFF8 = 0x817FFFF8;
    UNK_817FFFFC = 0x817FFFFC;
    __OSActiveThreadQueue = 0x800000DC;
    __OSTVMode = 0x800000CC;
    /* SDK absolute globals; configure.py generates their C constants. */
    GXFIFO = 0xCC008000;
    /* SDK absolute globals; configure.py generates their C constants. */
    __gUnknown800030E3 = 0x800030E3;
    /* Retail labels sharing a C function entry. */
    __OSDBJUMPEND = __OSSetExceptionHandler;
    /* SDK absolute globals; configure.py generates their C constants. */
    __OSRebootBuffer = 0x81300000;
    /* SDK absolute globals; configure.py generates their C constants. */
    __OSBI2DebugFlag = 0x800030E8;
    __OSBI2Pointer = 0x800000F4;
    __OSPadSpecByte = 0x800030E9;
    /* SDK absolute globals; configure.py generates their C constants. */
    __OSWirelessPadFixMode = 0x800030E0;
}

FORCEACTIVE
{
    $FORCEACTIVE
}
