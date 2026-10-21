


typedef signed long s32;


typedef unsigned char u8;


typedef unsigned long u32;
typedef unsigned long long u64;


typedef int BOOL;


typedef struct TRKBuffer {
u32 mutex;
BOOL isInUse;
u32 length;
u32 position;
u8 data[(0x800 + 0x80) ];
} TRKBuffer;


struct fn_8008C124_gTRKExceptionStatus {
u8 pad_0[0xC];
u32 unk_C;
};
extern struct fn_8008C124_gTRKExceptionStatus gTRKExceptionStatus;
typedef struct InstructionBuffer { u32 words[10]; } InstructionBuffer;
extern InstructionBuffer lbl_80095B80;
extern InstructionBuffer lbl_80095B30;
extern u8 lbl_801A5624[20];
extern u32 fn_8008B0E0(void);
extern void fn_8008B0E8(u32);
extern void fn_8008AFF0(u32, u32);

#pragma use_lmw_stmw on

static inline s32 ExecuteInstructions(u64 *value, InstructionBuffer *instructions) {
instructions->words[9] = 0x4E800020;
fn_8008AFF0((u32)instructions, 40);
((void (*)(u64 *, void *))instructions)(value, lbl_801A5624);
return 0;
}
static inline s32 AccessFPSCR(u64 *value, s32 read) {
InstructionBuffer instructions = lbl_80095B30;
if (read) {
instructions.words[0] = 0x7C9EFAA6;
instructions.words[1] = 0x90830000;
} else {
instructions.words[0] = (32u << 26) | (4u << 21) | (3u << 16);
instructions.words[1] = 0x7C9EFBA6;
}
return ExecuteInstructions(value, &instructions);
}
static inline u64 ShiftFPValue(u64 value) {
return value >> 32;
}
static inline s32 AccessFP(u32 reg, u64 *value, s32 read) {
s32 result = 0;
InstructionBuffer instructions = lbl_80095B80;
if (reg < 32) {
u32 instruction = (reg << 21) | 0xC8030000;
if (read) instruction = (reg << 21) | 0xD8030000;
instructions.words[0] = instruction;
result = ExecuteInstructions(value, &instructions);
} else if (reg == 32) {
*value &= 0xFFFFFFFFULL;
} else if (reg == 33) {
if (!read) *(u32 *)value = ((u32 *)value)[1];
result = AccessFPSCR(value, read);
if (read) *value = (u64)*(u32 *)value & 0xFFFFFFFFULL;
}
return result;
}
s32 fn_8008C124(u32 arg0, u32 arg1, TRKBuffer *arg2, u32 *arg3, s32 arg4) {
struct fn_8008C124_gTRKExceptionStatus *p_gTRKExceptionStatus;
struct fn_8008C124_gTRKExceptionStatus save;
u64 value;
u32 reg;
s32 result;
if (arg1 > 33) return 0x701;
p_gTRKExceptionStatus = (struct fn_8008C124_gTRKExceptionStatus *)&gTRKExceptionStatus;
save = *p_gTRKExceptionStatus;
((u8 *)p_gTRKExceptionStatus)[13] = 0;
fn_8008B0E8(fn_8008B0E0() | 0x2000);
*arg3 = 0;
reg = arg0;
result = 0;
while (reg <= arg1 && result == 0) {
if (arg4) {
AccessFP(reg, &value, arg4);
result = TRKAppendBuffer1_ui64(arg2, value);
} else {
TRKReadBuffer1_ui64(arg2, &value);
result = AccessFP(reg, &value, arg4);
}
*arg3 += 8;
reg++;
}
if (((u8 *)p_gTRKExceptionStatus)[13] != 0) {
*arg3 = 0;
result = 0x702;
}
gTRKExceptionStatus = save;
return result;
}
