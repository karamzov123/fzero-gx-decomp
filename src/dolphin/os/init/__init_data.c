extern void* memcpy(void* dst, const void* src, unsigned long n);
extern void __flush_cache(void* address, unsigned long size);
extern void* memset(void* dst, int val, unsigned long n);
typedef struct __rom_copy_info {
    char* rom;
    char* addr;
    unsigned int size;
} __rom_copy_info;

typedef struct __bss_init_info {
    char* addr;
    unsigned int size;
} __bss_init_info;

extern __rom_copy_info _rom_copy_info[];
extern __bss_init_info _bss_init_info[];

#pragma push
#pragma force_active on

asm __declspec(section ".init") void __init_data(void)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    stw     r30, 0x10(r1)
    stw     r29, 0xc(r1)
    lis     r3, _rom_copy_info@ha
    addi    r0, r3, _rom_copy_info@l
    mr      r29, r0
    b       lbl_80003368
lbl_80003368:
    b       lbl_8000336C
lbl_8000336C:
    lwz     r30, 0x8(r29)
    cmplwi  r30, 0
    beq     lbl_800033AC
    lwz     r4, 0x0(r29)
    lwz     r31, 0x4(r29)
    beq     lbl_800033A4
    cmplw   r31, r4
    beq     lbl_800033A4
    mr      r3, r31
    mr      r5, r30
    bl      memcpy
    mr      r3, r31
    mr      r4, r30
    bl      __flush_cache
lbl_800033A4:
    addi    r29, r29, 0xc
    b       lbl_8000336C
lbl_800033AC:
    lis     r3, _bss_init_info@ha
    addi    r0, r3, _bss_init_info@l
    mr      r29, r0
    b       lbl_800033BC
lbl_800033BC:
    b       lbl_800033C0
lbl_800033C0:
    lwz     r5, 0x4(r29)
    cmplwi  r5, 0
    beq     lbl_800033E4
    lwz     r3, 0x0(r29)
    beq     lbl_800033DC
    li      r4, 0
    bl      memset
lbl_800033DC:
    addi    r29, r29, 0x8
    b       lbl_800033C0
lbl_800033E4:
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    lwz     r29, 0xc(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

#pragma pop
