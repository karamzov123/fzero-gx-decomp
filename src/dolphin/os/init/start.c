typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef int BOOL;

extern void OSResetSystem(BOOL reset, u32 shutdown_flags, BOOL force_menu);
extern void __init_registers(void);
extern void __init_hardware(void);
extern void __init_data(void);
extern void InitMetroTRK(void);
extern void InitMetroTRK_BBA(void);
extern void DBInit(void);
extern void OSInit(void);
extern void __init_user(void);
extern int main(int argc, char* argv[]);
extern void exit(int status);

extern u8 Debug_BBA;
extern unsigned char ARENAHI_ADDR[];
extern unsigned char BOOTINFO2_ADDR[];
extern unsigned char DEBUGFLAG_ADDR[];
extern unsigned char DVD_DEVICECODE_ADDR[];
extern unsigned char EXCEPTIONMASK_ADDR[];

#define PAD3_BUTTON_ADDR 0x800030E4
#define ARENAHI_ADDR 0x80000034
#define EXCEPTIONMASK_ADDR 0x80000044
#define BOOTINFO2_ADDR 0x800000F4
#define DVD_DEVICECODE_ADDR 0x800030E6
#define DEBUGFLAG_ADDR 0x800030E8

#pragma push
#pragma force_active on

__declspec(section ".init") static void __check_pad3(void)
{
    if ((*(volatile u16*) PAD3_BUTTON_ADDR & 0xEEF) == 0xEEF) {
        OSResetSystem(0, 0, 0);
    }
}

__declspec(section ".init") static void __set_debug_bba(void)
{
    Debug_BBA = 1;
}

__declspec(section ".init") static u8 __get_debug_bba(void)
{
    return Debug_BBA;
}

asm __declspec(section ".init") __declspec(weak) void __start(void)
{
    nofralloc
    bl __init_registers
    bl __init_hardware
    li r0, -1
    stwu r1, -8(r1)
    stw r0, 4(r1)
    stw r0, 0(r1)
    bl __init_data
    li r0, 0
    lis r6, EXCEPTIONMASK_ADDR@ha
    addi r6, r6, EXCEPTIONMASK_ADDR@l
    stw r0, 0(r6)
    lis r6, BOOTINFO2_ADDR@ha
    addi r6, r6, BOOTINFO2_ADDR@l
    lwz r6, 0(r6)
    cmplwi r6, 0
    beq _no_bi2
    lwz r7, 0xC(r6)
    b _check_debug_flag
_no_bi2:
    lis r5, ARENAHI_ADDR@ha
    addi r5, r5, ARENAHI_ADDR@l
    lwz r5, 0(r5)
    cmplwi r5, 0
    beq _goto_main
    lis r7, DEBUGFLAG_ADDR@ha
    addi r7, r7, DEBUGFLAG_ADDR@l
    lwz r7, 0(r7)
_check_debug_flag:
    li r5, 0
    cmplwi r7, 2
    beq _goto_inittrk
    cmplwi r7, 3
    li r5, 1
    beq _goto_inittrk
    cmplwi r7, 4
    bne _goto_main
    li r5, 2
    bl __set_debug_bba
    b _goto_main
_goto_inittrk:
    lis r6, InitMetroTRK@ha
    addi r6, r6, InitMetroTRK@l
    mtlr r6
    blrl
_goto_main:
    lis r6, BOOTINFO2_ADDR@ha
    addi r6, r6, BOOTINFO2_ADDR@l
    lwz r5, 0(r6)
    cmplwi r5, 0
    beq+ _no_args
    lwz r6, 8(r5)
    cmplwi r6, 0
    beq+ _no_args
    add r6, r5, r6
    lwz r14, 0(r6)
    cmplwi r14, 0
    beq _no_args
    addi r15, r6, 4
    mtctr r14
_loop:
    addi r6, r6, 4
    lwz r7, 0(r6)
    add r7, r7, r5
    stw r7, 0(r6)
    bdnz _loop
    lis r5, ARENAHI_ADDR@ha
    addi r5, r5, ARENAHI_ADDR@l
    clrrwi r7, r15, 5
    stw r7, 0(r5)
    b _end_of_parseargs
_no_args:
    li r14, 0
    li r15, 0
_end_of_parseargs:
    bl DBInit
    bl OSInit
    lis r4, DVD_DEVICECODE_ADDR@ha
    addi r4, r4, DVD_DEVICECODE_ADDR@l
    lhz r3, 0(r4)
    andi. r5, r3, 0x8000
    beq _check_pad3
    andi. r3, r3, 0x7fff
    cmplwi r3, 1
    bne _goto_skip_init_bba
_check_pad3:
    bl __check_pad3
_goto_skip_init_bba:
    bl __get_debug_bba
    cmplwi r3, 1
    bne _goto_init_user
    bl InitMetroTRK_BBA
_goto_init_user:
    bl __init_user
    mr r3, r14
    mr r4, r15
    bl main
    b exit
}

#pragma pop
