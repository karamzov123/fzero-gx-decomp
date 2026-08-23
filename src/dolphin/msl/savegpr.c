#pragma push
#pragma force_active on

extern void _savefpr_14(void);
extern void _savefpr_15(void);
extern void _savefpr_16(void);
extern void _savefpr_17(void);
extern void _savefpr_18(void);
extern void _savefpr_19(void);
extern void _savefpr_20(void);
extern void _savefpr_21(void);
extern void _savefpr_22(void);
extern void _savefpr_23(void);
extern void _savefpr_24(void);
extern void _savefpr_25(void);
extern void _savefpr_26(void);
extern void _savefpr_27(void);
extern void _savefpr_28(void);
extern void _savefpr_29(void);
extern void _savefpr_30(void);
extern void _savefpr_31(void);
extern void _restfpr_14(void);
extern void _restfpr_15(void);
extern void _restfpr_16(void);
extern void _restfpr_17(void);
extern void _restfpr_18(void);
extern void _restfpr_19(void);
extern void _restfpr_20(void);
extern void _restfpr_21(void);
extern void _restfpr_22(void);
extern void _restfpr_23(void);
extern void _restfpr_24(void);
extern void _restfpr_25(void);
extern void _restfpr_26(void);
extern void _restfpr_27(void);
extern void _restfpr_28(void);
extern void _restfpr_29(void);
extern void _restfpr_30(void);
extern void _restfpr_31(void);
extern void _savegpr_14(void);
extern void _savegpr_15(void);
extern void _savegpr_16(void);
extern void _savegpr_17(void);
extern void _savegpr_18(void);
extern void _savegpr_19(void);
extern void _savegpr_20(void);
extern void _savegpr_21(void);
extern void _savegpr_22(void);
extern void _savegpr_23(void);
extern void _savegpr_24(void);
extern void _savegpr_25(void);
extern void _savegpr_26(void);
extern void _savegpr_27(void);
extern void _savegpr_28(void);
extern void _savegpr_29(void);
extern void _savegpr_30(void);
extern void _savegpr_31(void);
extern void _restgpr_14(void);
extern void _restgpr_15(void);
extern void _restgpr_16(void);
extern void _restgpr_17(void);
extern void _restgpr_18(void);
extern void _restgpr_19(void);
extern void _restgpr_20(void);
extern void _restgpr_21(void);
extern void _restgpr_22(void);
extern void _restgpr_23(void);
extern void _restgpr_24(void);
extern void _restgpr_25(void);
extern void _restgpr_26(void);
extern void _restgpr_27(void);
extern void _restgpr_28(void);
extern void _restgpr_29(void);
extern void _restgpr_30(void);
extern void _restgpr_31(void);

asm void __save_fpr(void)
{
    nofralloc
entry _savefpr_14
    stfd    f14, -0x90(r11)
entry _savefpr_15
    stfd    f15, -0x88(r11)
entry _savefpr_16
    stfd    f16, -0x80(r11)
entry _savefpr_17
    stfd    f17, -0x78(r11)
entry _savefpr_18
    stfd    f18, -0x70(r11)
entry _savefpr_19
    stfd    f19, -0x68(r11)
entry _savefpr_20
    stfd    f20, -0x60(r11)
entry _savefpr_21
    stfd    f21, -0x58(r11)
entry _savefpr_22
    stfd    f22, -0x50(r11)
entry _savefpr_23
    stfd    f23, -0x48(r11)
entry _savefpr_24
    stfd    f24, -0x40(r11)
entry _savefpr_25
    stfd    f25, -0x38(r11)
entry _savefpr_26
    stfd    f26, -0x30(r11)
entry _savefpr_27
    stfd    f27, -0x28(r11)
entry _savefpr_28
    stfd    f28, -0x20(r11)
entry _savefpr_29
    stfd    f29, -0x18(r11)
entry _savefpr_30
    stfd    f30, -0x10(r11)
entry _savefpr_31
    stfd    f31, -0x8(r11)
    blr
}

asm void __restore_fpr(void)
{
    nofralloc
entry _restfpr_14
    lfd    f14, -0x90(r11)
entry _restfpr_15
    lfd    f15, -0x88(r11)
entry _restfpr_16
    lfd    f16, -0x80(r11)
entry _restfpr_17
    lfd    f17, -0x78(r11)
entry _restfpr_18
    lfd    f18, -0x70(r11)
entry _restfpr_19
    lfd    f19, -0x68(r11)
entry _restfpr_20
    lfd    f20, -0x60(r11)
entry _restfpr_21
    lfd    f21, -0x58(r11)
entry _restfpr_22
    lfd    f22, -0x50(r11)
entry _restfpr_23
    lfd    f23, -0x48(r11)
entry _restfpr_24
    lfd    f24, -0x40(r11)
entry _restfpr_25
    lfd    f25, -0x38(r11)
entry _restfpr_26
    lfd    f26, -0x30(r11)
entry _restfpr_27
    lfd    f27, -0x28(r11)
entry _restfpr_28
    lfd    f28, -0x20(r11)
entry _restfpr_29
    lfd    f29, -0x18(r11)
entry _restfpr_30
    lfd    f30, -0x10(r11)
entry _restfpr_31
    lfd    f31, -0x8(r11)
    blr
}

asm void __save_gpr(void)
{
    nofralloc
entry _savegpr_14
    stw    r14, -0x48(r11)
entry _savegpr_15
    stw    r15, -0x44(r11)
entry _savegpr_16
    stw    r16, -0x40(r11)
entry _savegpr_17
    stw    r17, -0x3c(r11)
entry _savegpr_18
    stw    r18, -0x38(r11)
entry _savegpr_19
    stw    r19, -0x34(r11)
entry _savegpr_20
    stw    r20, -0x30(r11)
entry _savegpr_21
    stw    r21, -0x2c(r11)
entry _savegpr_22
    stw    r22, -0x28(r11)
entry _savegpr_23
    stw    r23, -0x24(r11)
entry _savegpr_24
    stw    r24, -0x20(r11)
entry _savegpr_25
    stw    r25, -0x1c(r11)
entry _savegpr_26
    stw    r26, -0x18(r11)
entry _savegpr_27
    stw    r27, -0x14(r11)
entry _savegpr_28
    stw    r28, -0x10(r11)
entry _savegpr_29
    stw    r29, -0xc(r11)
entry _savegpr_30
    stw    r30, -0x8(r11)
entry _savegpr_31
    stw    r31, -0x4(r11)
    blr
}

asm void __restore_gpr(void)
{
    nofralloc
entry _restgpr_14
    lwz    r14, -0x48(r11)
entry _restgpr_15
    lwz    r15, -0x44(r11)
entry _restgpr_16
    lwz    r16, -0x40(r11)
entry _restgpr_17
    lwz    r17, -0x3c(r11)
entry _restgpr_18
    lwz    r18, -0x38(r11)
entry _restgpr_19
    lwz    r19, -0x34(r11)
entry _restgpr_20
    lwz    r20, -0x30(r11)
entry _restgpr_21
    lwz    r21, -0x2c(r11)
entry _restgpr_22
    lwz    r22, -0x28(r11)
entry _restgpr_23
    lwz    r23, -0x24(r11)
entry _restgpr_24
    lwz    r24, -0x20(r11)
entry _restgpr_25
    lwz    r25, -0x1c(r11)
entry _restgpr_26
    lwz    r26, -0x18(r11)
entry _restgpr_27
    lwz    r27, -0x14(r11)
entry _restgpr_28
    lwz    r28, -0x10(r11)
entry _restgpr_29
    lwz    r29, -0xc(r11)
entry _restgpr_30
    lwz    r30, -0x8(r11)
entry _restgpr_31
    lwz    r31, -0x4(r11)
    blr
}

#pragma pop
