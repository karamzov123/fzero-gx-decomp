
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
#pragma section code_type ".fzgxpool"
static const u32 color_data[1] = {0xffff0000};
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = color_data; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
    s = 10.0f;
    s = 0.6000000238418579f;
    s = 456.0f;
    s = 0.125f;
    s = 5.0f;
    s = 1.4444444179534912f;
    s = 1.0f;
    s = 46.0f;
    s = 52.0f;
    s = 0.5f;
    s = 71.0f;
    s = 22.0f;
    s = 98.0f;
    s = 93.38823699951172f;
    s = 0.7686274647712708f;
    s = 0.0f;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);

extern s32 fn_1_A5DC4(void);
extern u16 fn_1_486C4();
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_49738(void (*)(void));
extern void fn_1_52250(void);
extern void fn_1_49748(f32);
extern void fn_1_4955C(f32,f32);
extern void fn_1_4962C(void);
extern void fn_1_495A0(f32);
extern void fn_1_496FC(f32,f32);
extern void fn_1_49644(void);
extern s16 fn_1_12C930(s16);
extern void fn_1_4AE0C(const char *,...);
extern void fn_1_4965C(u8);
extern void fn_1_4954C(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern f32 fn_1_4B068(const char *);
extern void fn_1_4A0D8(const char *);
extern char *lbl_1_data_212A8[];
extern char *lbl_1_data_21078[];
struct State { u8 pad[10]; s16 mode; };
extern struct State lbl_1_bss_8B614;
typedef struct Packet { u32 id; f32 x,y,z,s; u8 pad[24]; f32 v; u8 tail[40]; } Packet;
extern u8 lbl_16_data_82DB0__fzgx_offset_0[];
extern u8 lbl_16_data_82DB4__fzgx_offset_0[];
extern u8 lbl_16_data_82DB8__fzgx_offset_0[];
extern u8 lbl_16_data_82DC0__fzgx_offset_0[];
extern u8 lbl_16_data_82DD0__fzgx_offset_0[];
extern u8 lbl_16_data_82DEC__fzgx_offset_0[];
extern u8 lbl_16_data_82E10__fzgx_offset_0[];
extern u8 lbl_16_data_82E1C__fzgx_offset_0[];
extern u8 lbl_16_data_82E24__fzgx_offset_0[];
extern u8 lbl_16_data_82E3C__fzgx_offset_0[];
extern u8 lbl_16_data_82E48__fzgx_offset_0[];
extern u8 lbl_16_data_82E54__fzgx_offset_0[];
extern u8 lbl_16_data_82E64__fzgx_offset_0[];
extern u8 lbl_16_data_82E70__fzgx_offset_0[];
extern u8 lbl_16_data_82E78__fzgx_offset_0[];
extern u8 lbl_16_data_82E80__fzgx_offset_0[];
extern u8 lbl_16_data_82E88__fzgx_offset_0[];
extern u8 lbl_16_data_82E90__fzgx_offset_0[];
extern u8 lbl_16_data_82E98__fzgx_offset_0[];
extern u8 lbl_16_data_82EA0__fzgx_offset_0[];
extern u8 lbl_16_data_82EA8__fzgx_offset_0[];
extern u8 lbl_16_data_82EB0__fzgx_offset_0[];
extern u8 lbl_16_data_82EBC__fzgx_offset_0[];
extern u8 lbl_16_data_82EC4__fzgx_offset_0[];
extern u8 lbl_16_data_82ECC__fzgx_offset_0[];
extern u8 lbl_16_data_82EDC__fzgx_offset_0[];
extern u8 lbl_16_data_82EE8__fzgx_offset_0[];
extern u8 lbl_16_data_82EF8__fzgx_offset_0[];
extern u8 lbl_16_data_82F08__fzgx_offset_0[];
extern u8 lbl_16_data_82F18__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_16_data_82DB0[94] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F2E00, 0x0, 0x4E414D45, 0x0, 0x43484152, 0x41435445, 0x52204C49, 0x53540000,
    0x53656C65, 0x63742061, 0x2050696C, 0x6F742074, 0x6F205669, 0x65772E20, 0x0, 0x8CA982BD,
    0x82A28370, 0x8343838D, 0x83628367, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    0x50494C4F, 0x54204441, 0x54410000, 0x4D414348, 0x494E4500, 0x4D616368, 0x696E6520, 0x496E7472,
    0x6F647563, 0x74696F6E, 0x73000000, 0x837D8356, 0x83938FD0, 0x89EE0000, 0x56696577, 0x204D6F76,
    0x69650000, 0x8380815B, 0x8372815B, 0x82F08CA9, 0x82E90000, 0x526F7461, 0x74696F6E, 0x0,
    0x89F1935D, 0x0, 0x5A6F6F6D, 0x0, 0x8359815B, 0x83800000, 0x4261636B, 0x0,
    0x96DF82E9, 0x0, 0x4D616465, 0x20427900, 0x90BB8DEC, 0x0, 0x456E6769, 0x6E650000,
    0x83478393, 0x83578393, 0x0, 0x57656967, 0x68740000, 0x918D8F64, 0x97CA0000, 0x426F6479,
    0x20537472, 0x656E6774, 0x68000000, 0x837B8366, 0x834290AB, 0x945C0000, 0x426F6F73, 0x74205374,
    0x72656E67, 0x74680000, 0x8375815B, 0x83588367, 0x90AB945C, 0x0, 0x47726970, 0x20537472,
    0x656E6774, 0x68000000, 0x834F838A, 0x83628376, 0x90AB945C, 0x0
};
static u32 fzgx_pool_data_lbl_16_data_82F28[102] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_16_data_82DB0__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB0__fzgx_offset_0, (u32)lbl_16_data_82DB8__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB8__fzgx_offset_0, (u32)lbl_16_data_82DC0__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DC0__fzgx_offset_0, (u32)lbl_16_data_82DD0__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DEC__fzgx_offset_0,
    (u32)lbl_16_data_82E10__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E10__fzgx_offset_0, (u32)lbl_16_data_82E1C__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E1C__fzgx_offset_0, (u32)lbl_16_data_82E24__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E3C__fzgx_offset_0, (u32)lbl_16_data_82E48__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E54__fzgx_offset_0,
    (u32)lbl_16_data_82E64__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E70__fzgx_offset_0, (u32)lbl_16_data_82E78__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E80__fzgx_offset_0, (u32)lbl_16_data_82E88__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82E90__fzgx_offset_0, (u32)lbl_16_data_82E98__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82EA0__fzgx_offset_0,
    (u32)lbl_16_data_82EA8__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82EB0__fzgx_offset_0, (u32)lbl_16_data_82EBC__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82EC4__fzgx_offset_0, (u32)lbl_16_data_82ECC__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0,
    (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82EDC__fzgx_offset_0, (u32)lbl_16_data_82EE8__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82EF8__fzgx_offset_0,
    (u32)lbl_16_data_82F08__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82DB4__fzgx_offset_0, (u32)lbl_16_data_82F18__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_16_data_830C0[217] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6500, 0x6501, 0x6502, 0x6503, 0x6D00, 0x6D01, 0x6D02, 0x6D03,
    0x8000, 0x8001, 0x8002, 0x8003, 0x5800, 0x5801, 0x5802, 0x5803,
    0x6900, 0x6901, 0x6902, 0x6903, 0x7500, 0x7501, 0x7502, 0x7503,
    0x6400, 0x6401, 0x6402, 0x6403, 0x7400, 0x7401, 0x7402, 0x7403,
    0x6300, 0x6301, 0x6302, 0x6303, 0x6C00, 0x6C01, 0x6C02, 0x6C03,
    0x5A00, 0x5A01, 0x5A02, 0x5A03, 0x6E00, 0x6E01, 0x6E02, 0x6E03,
    0x8200, 0x8201, 0x8202, 0x8203, 0x6B00, 0x6B01, 0x6B02, 0x6B03,
    0x7900, 0x7901, 0x7902, 0x7903, 0x6800, 0x6801, 0x6802, 0x6803,
    0x6A00, 0x6A01, 0x6A02, 0x6A03, 0x5900, 0x5901, 0x5902, 0x5903,
    0x6F00, 0x6F01, 0x6F02, 0x6F03, 0x5700, 0x5701, 0x5702, 0x5703,
    0x7200, 0x7201, 0x7202, 0x7203, 0x7E00, 0x7E01, 0x7E02, 0x7E03,
    0x7300, 0x7301, 0x7302, 0x7303, 0x7100, 0x7101, 0x7102, 0x7103,
    0x5B00, 0x5B01, 0x5B02, 0x5B03, 0x8100, 0x8101, 0x8102, 0x8103,
    0x6200, 0x6201, 0x6202, 0x6203, 0x7A00, 0x7A01, 0x7A02, 0x7A03,
    0x5D00, 0x5D01, 0x5D02, 0x5D03, 0x7C00, 0x7C01, 0x7C02, 0x7C03,
    0x5C00, 0x5C01, 0x5C02, 0x5C03, 0x6100, 0x6101, 0x6102, 0x6103,
    0x6000, 0x6001, 0x6002, 0x6003, 0x5E00, 0x5E01, 0x5E02, 0x5E03,
    0x7F00, 0x7F01, 0x7F02, 0x7F03, 0x5F00, 0x5F01, 0x5F02, 0x5F03,
    0x7700, 0x7701, 0x7702, 0x7703, 0x7000, 0x7001, 0x7002, 0x7003,
    0x7600, 0x7601, 0x7602, 0x7603, 0x7800, 0x7801, 0x7802, 0x7803,
    0x7D00, 0x7D01, 0x7D02, 0x7D03, 0x6700, 0x6701, 0x6702, 0x6703,
    0x7B00, 0x7B01, 0x7B02, 0x7B03, 0x6600, 0x6601, 0x6602, 0x6603,
    0x4A00, 0x5400, 0x3800, 0x3E00, 0x3700, 0x5500, 0x3000, 0x3500,
    0x3A00, 0x4000, 0x4400, 0x5000, 0x3300, 0x2E00, 0x3100, 0x4F00,
    0x3900, 0x3D00, 0x4C00, 0x3F00, 0x4800, 0x5200, 0x4500, 0x5300,
    0x3C00, 0x5600, 0x4300, 0x4200, 0x3200, 0x2F00, 0x3400, 0x3600,
    0x4D00, 0x4600, 0x4100, 0x5100, 0x4E00, 0x4700, 0x3B00, 0x4B00,
    0x4900
};
static u32 fzgx_pool_data_lbl_16_data_82DB0_674[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25732530, 0x32640000
};
static u32 fzgx_pool_data_lbl_16_data_82DB0_67C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x81F40000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_16_data_82DB0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_16_data_82DB0;
    s = *(u8 *)fzgx_pool_data_lbl_16_data_82F28;
    s = *(u8 *)fzgx_pool_data_lbl_16_data_830C0;
    s = *(u8 *)fzgx_pool_data_lbl_16_data_82DB0_674;
    s = *(u8 *)fzgx_pool_data_lbl_16_data_82DB0_67C;
}
#pragma section code_type ".text"

extern const Packet lbl_1_rodata_26F8;

static const f32 prime1=20.0f, prime2=10.0f, prime3=0.6f, prime4=456.0f, prime5=0.125f, prime6=5.0f, prime7=1.4444444f, prime8=1.0f, prime9=46.0f, prime10=52.0f, prime11=0.5f, prime12=71.0f, prime13=22.0f, prime14=98.0f, prime15=93.388237f, prime16=0.76862746f;
static inline char * fn_16_2560_array_read(char * *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
void fn_16_2560(s16 input) {
s16 a=0;
s16 b=0;

Packet p;
u32 color;
s32 x;
struct State *state;
s16 arg=input;
if ((s8)fn_1_A5DC4()) { a=94; b=110; }
p=lbl_1_rodata_26F8;
p.id=0x9305; p.x=-b; p.y=((1)==1?20.0f:(1)==2?10.0f:(1)==3?0.6f:(1)==4?456.0f:(1)==5?0.125f:(1)==6?5.0f:(1)==7?1.4444444f:(1)==8?1.0f:(1)==9?46.0f:(1)==10?52.0f:(1)==11?0.5f:(1)==12?71.0f:(1)==13?22.0f:(1)==14?98.0f:(1)==15?93.388237f:0.76862746f) ; p.z=((2)==1?20.0f:(2)==2?10.0f:(2)==3?0.6f:(2)==4?456.0f:(2)==5?0.125f:(2)==6?5.0f:(2)==7?1.4444444f:(2)==8?1.0f:(2)==9?46.0f:(2)==10?52.0f:(2)==11?0.5f:(2)==12?71.0f:(2)==13?22.0f:(2)==14?98.0f:(2)==15?93.388237f:0.76862746f) ; p.v=((3)==1?20.0f:(3)==2?10.0f:(3)==3?0.6f:(3)==4?456.0f:(3)==5?0.125f:(3)==6?5.0f:(3)==7?1.4444444f:(3)==8?1.0f:(3)==9?46.0f:(3)==10?52.0f:(3)==11?0.5f:(3)==12?71.0f:(3)==13?22.0f:(3)==14?98.0f:(3)==15?93.388237f:0.76862746f) ;
fn_1_51678((FontDrawPacket *)&p,p.id,0,0,8,(s16)fn_1_486C4());
p.s *= (((4)==1?20.0f:(4)==2?10.0f:(4)==3?0.6f:(4)==4?456.0f:(4)==5?0.125f:(4)==6?5.0f:(4)==7?1.4444444f:(4)==8?1.0f:(4)==9?46.0f:(4)==10?52.0f:(4)==11?0.5f:(4)==12?71.0f:(4)==13?22.0f:(4)==14?98.0f:(4)==15?93.388237f:0.76862746f) +b*2)/8.0f;
fn_1_4F734((FontDrawPacket *)&p);
p=lbl_1_rodata_26F8;
p.id=0x9305; p.x=b+456; p.y=((1)==1?20.0f:(1)==2?10.0f:(1)==3?0.6f:(1)==4?456.0f:(1)==5?0.125f:(1)==6?5.0f:(1)==7?1.4444444f:(1)==8?1.0f:(1)==9?46.0f:(1)==10?52.0f:(1)==11?0.5f:(1)==12?71.0f:(1)==13?22.0f:(1)==14?98.0f:(1)==15?93.388237f:0.76862746f) ; p.z=((2)==1?20.0f:(2)==2?10.0f:(2)==3?0.6f:(2)==4?456.0f:(2)==5?0.125f:(2)==6?5.0f:(2)==7?1.4444444f:(2)==8?1.0f:(2)==9?46.0f:(2)==10?52.0f:(2)==11?0.5f:(2)==12?71.0f:(2)==13?22.0f:(2)==14?98.0f:(2)==15?93.388237f:0.76862746f) ; p.v=((3)==1?20.0f:(3)==2?10.0f:(3)==3?0.6f:(3)==4?456.0f:(3)==5?0.125f:(3)==6?5.0f:(3)==7?1.4444444f:(3)==8?1.0f:(3)==9?46.0f:(3)==10?52.0f:(3)==11?0.5f:(3)==12?71.0f:(3)==13?22.0f:(3)==14?98.0f:(3)==15?93.388237f:0.76862746f) ;
fn_1_51678((FontDrawPacket *)&p,p.id,8,0,24,(s16)fn_1_486C4());
fn_1_4F734((FontDrawPacket *)&p);
p=lbl_1_rodata_26F8;
p.id=0x9305; p.x=b+480; p.y=((1)==1?20.0f:(1)==2?10.0f:(1)==3?0.6f:(1)==4?456.0f:(1)==5?0.125f:(1)==6?5.0f:(1)==7?1.4444444f:(1)==8?1.0f:(1)==9?46.0f:(1)==10?52.0f:(1)==11?0.5f:(1)==12?71.0f:(1)==13?22.0f:(1)==14?98.0f:(1)==15?93.388237f:0.76862746f) ; p.z=((2)==1?20.0f:(2)==2?10.0f:(2)==3?0.6f:(2)==4?456.0f:(2)==5?0.125f:(2)==6?5.0f:(2)==7?1.4444444f:(2)==8?1.0f:(2)==9?46.0f:(2)==10?52.0f:(2)==11?0.5f:(2)==12?71.0f:(2)==13?22.0f:(2)==14?98.0f:(2)==15?93.388237f:0.76862746f) ; p.v=((3)==1?20.0f:(3)==2?10.0f:(3)==3?0.6f:(3)==4?456.0f:(3)==5?0.125f:(3)==6?5.0f:(3)==7?1.4444444f:(3)==8?1.0f:(3)==9?46.0f:(3)==10?52.0f:(3)==11?0.5f:(3)==12?71.0f:(3)==13?22.0f:(3)==14?98.0f:(3)==15?93.388237f:0.76862746f) ;
fn_1_51678((FontDrawPacket *)&p,p.id,32,0,8,(s16)fn_1_486C4());
p.s *= ((1)==1?20.0f:(1)==2?10.0f:(1)==3?0.6f:(1)==4?456.0f:(1)==5?0.125f:(1)==6?5.0f:(1)==7?1.4444444f:(1)==8?1.0f:(1)==9?46.0f:(1)==10?52.0f:(1)==11?0.5f:(1)==12?71.0f:(1)==13?22.0f:(1)==14?98.0f:(1)==15?93.388237f:0.76862746f) ;
fn_1_4F734((FontDrawPacket *)&p);
fn_1_49410(); fn_1_494DC(5); fn_1_495B0(0x80000000);
fn_1_49738(fn_1_52250); fn_1_49748(((6)==1?20.0f:(6)==2?10.0f:(6)==3?0.6f:(6)==4?456.0f:(6)==5?0.125f:(6)==6?5.0f:(6)==7?1.4444444f:(6)==8?1.0f:(6)==9?46.0f:(6)==10?52.0f:(6)==11?0.5f:(6)==12?71.0f:(6)==13?22.0f:(6)==14?98.0f:(6)==15?93.388237f:0.76862746f) ); fn_1_4955C(((7)==1?20.0f:(7)==2?10.0f:(7)==3?0.6f:(7)==4?456.0f:(7)==5?0.125f:(7)==6?5.0f:(7)==7?1.4444444f:(7)==8?1.0f:(7)==9?46.0f:(7)==10?52.0f:(7)==11?0.5f:(7)==12?71.0f:(7)==13?22.0f:(7)==14?98.0f:(7)==15?93.388237f:0.76862746f) ,((7)==1?20.0f:(7)==2?10.0f:(7)==3?0.6f:(7)==4?456.0f:(7)==5?0.125f:(7)==6?5.0f:(7)==7?1.4444444f:(7)==8?1.0f:(7)==9?46.0f:(7)==10?52.0f:(7)==11?0.5f:(7)==12?71.0f:(7)==13?22.0f:(7)==14?98.0f:(7)==15?93.388237f:0.76862746f) );
fn_1_4962C(); fn_1_495A0(((8)==1?20.0f:(8)==2?10.0f:(8)==3?0.6f:(8)==4?456.0f:(8)==5?0.125f:(8)==6?5.0f:(8)==7?1.4444444f:(8)==8?1.0f:(8)==9?46.0f:(8)==10?52.0f:(8)==11?0.5f:(8)==12?71.0f:(8)==13?22.0f:(8)==14?98.0f:(8)==15?93.388237f:0.76862746f) );
fn_1_496FC((24-a),((9)==1?20.0f:(9)==2?10.0f:(9)==3?0.6f:(9)==4?456.0f:(9)==5?0.125f:(9)==6?5.0f:(9)==7?1.4444444f:(9)==8?1.0f:(9)==9?46.0f:(9)==10?52.0f:(9)==11?0.5f:(9)==12?71.0f:(9)==13?22.0f:(9)==14?98.0f:(9)==15?93.388237f:0.76862746f) );
state=&lbl_1_bss_8B614;
if(state->mode!=5) fn_1_496FC((24-a),((10)==1?20.0f:(10)==2?10.0f:(10)==3?0.6f:(10)==4?456.0f:(10)==5?0.125f:(10)==6?5.0f:(10)==7?1.4444444f:(10)==8?1.0f:(10)==9?46.0f:(10)==10?52.0f:(10)==11?0.5f:(10)==12?71.0f:(10)==13?22.0f:(10)==14?98.0f:(10)==15?93.388237f:0.76862746f) );
if(arg==9) fn_1_49644();
fn_1_4AE0C(fn_16_2560_array_read(lbl_1_data_212A8, fn_1_12C930(arg)));
if(state->mode==5) {
fn_1_49410(); fn_1_495B0(0x80000000); fn_1_4965C(2);
fn_1_4955C(((11)==1?20.0f:(11)==2?10.0f:(11)==3?0.6f:(11)==4?456.0f:(11)==5?0.125f:(11)==6?5.0f:(11)==7?1.4444444f:(11)==8?1.0f:(11)==9?46.0f:(11)==10?52.0f:(11)==11?0.5f:(11)==12?71.0f:(11)==13?22.0f:(11)==14?98.0f:(11)==15?93.388237f:0.76862746f) ,((11)==1?20.0f:(11)==2?10.0f:(11)==3?0.6f:(11)==4?456.0f:(11)==5?0.125f:(11)==6?5.0f:(11)==7?1.4444444f:(11)==8?1.0f:(11)==9?46.0f:(11)==10?52.0f:(11)==11?0.5f:(11)==12?71.0f:(11)==13?22.0f:(11)==14?98.0f:(11)==15?93.388237f:0.76862746f) ); fn_1_495A0(((8)==1?20.0f:(8)==2?10.0f:(8)==3?0.6f:(8)==4?456.0f:(8)==5?0.125f:(8)==6?5.0f:(8)==7?1.4444444f:(8)==8?1.0f:(8)==9?46.0f:(8)==10?52.0f:(8)==11?0.5f:(8)==12?71.0f:(8)==13?22.0f:(8)==14?98.0f:(8)==15?93.388237f:0.76862746f) ); fn_1_496FC((24-a),((12)==1?20.0f:(12)==2?10.0f:(12)==3?0.6f:(12)==4?456.0f:(12)==5?0.125f:(12)==6?5.0f:(12)==7?1.4444444f:(12)==8?1.0f:(12)==9?46.0f:(12)==10?52.0f:(12)==11?0.5f:(12)==12?71.0f:(12)==13?22.0f:(12)==14?98.0f:(12)==15?93.388237f:0.76862746f) );
fn_1_4AE0C(fn_16_2560_array_read(lbl_1_data_21078, fn_1_12C930(arg)));
}
fn_1_49410(); fn_1_494DC(5); fn_1_495B0(0x80000000);
fn_1_49738(fn_1_52250); fn_1_49748(((6)==1?20.0f:(6)==2?10.0f:(6)==3?0.6f:(6)==4?456.0f:(6)==5?0.125f:(6)==6?5.0f:(6)==7?1.4444444f:(6)==8?1.0f:(6)==9?46.0f:(6)==10?52.0f:(6)==11?0.5f:(6)==12?71.0f:(6)==13?22.0f:(6)==14?98.0f:(6)==15?93.388237f:0.76862746f) ); fn_1_4955C(((8)==1?20.0f:(8)==2?10.0f:(8)==3?0.6f:(8)==4?456.0f:(8)==5?0.125f:(8)==6?5.0f:(8)==7?1.4444444f:(8)==8?1.0f:(8)==9?46.0f:(8)==10?52.0f:(8)==11?0.5f:(8)==12?71.0f:(8)==13?22.0f:(8)==14?98.0f:(8)==15?93.388237f:0.76862746f) ,((8)==1?20.0f:(8)==2?10.0f:(8)==3?0.6f:(8)==4?456.0f:(8)==5?0.125f:(8)==6?5.0f:(8)==7?1.4444444f:(8)==8?1.0f:(8)==9?46.0f:(8)==10?52.0f:(8)==11?0.5f:(8)==12?71.0f:(8)==13?22.0f:(8)==14?98.0f:(8)==15?93.388237f:0.76862746f) );
fn_1_4962C(); fn_1_495A0(((8)==1?20.0f:(8)==2?10.0f:(8)==3?0.6f:(8)==4?456.0f:(8)==5?0.125f:(8)==6?5.0f:(8)==7?1.4444444f:(8)==8?1.0f:(8)==9?46.0f:(8)==10?52.0f:(8)==11?0.5f:(8)==12?71.0f:(8)==13?22.0f:(8)==14?98.0f:(8)==15?93.388237f:0.76862746f) ); fn_1_4954C(((6)==1?20.0f:(6)==2?10.0f:(6)==3?0.6f:(6)==4?456.0f:(6)==5?0.125f:(6)==6?5.0f:(6)==7?1.4444444f:(6)==8?1.0f:(6)==9?46.0f:(6)==10?52.0f:(6)==11?0.5f:(6)==12?71.0f:(6)==13?22.0f:(6)==14?98.0f:(6)==15?93.388237f:0.76862746f) );
fn_1_496FC(a+616,((13)==1?20.0f:(13)==2?10.0f:(13)==3?0.6f:(13)==4?456.0f:(13)==5?0.125f:(13)==6?5.0f:(13)==7?1.4444444f:(13)==8?1.0f:(13)==9?46.0f:(13)==10?52.0f:(13)==11?0.5f:(13)==12?71.0f:(13)==13?22.0f:(13)==14?98.0f:(13)==15?93.388237f:0.76862746f) );
color=color_data[0]; fn_1_49514(&color); fn_1_495C8(2);
fn_1_4AE0C(((char *)fzgx_pool_data_lbl_16_data_82DB0_674),((char **)(((char *)fzgx_pool_data_lbl_16_data_82F28)))[state->mode],arg==30?0:arg>30?arg:arg+1);
fn_1_49410(); fn_1_495B0(0x80000000); fn_1_4965C(2); fn_1_4955C(((11)==1?20.0f:(11)==2?10.0f:(11)==3?0.6f:(11)==4?456.0f:(11)==5?0.125f:(11)==6?5.0f:(11)==7?1.4444444f:(11)==8?1.0f:(11)==9?46.0f:(11)==10?52.0f:(11)==11?0.5f:(11)==12?71.0f:(11)==13?22.0f:(11)==14?98.0f:(11)==15?93.388237f:0.76862746f) ,((11)==1?20.0f:(11)==2?10.0f:(11)==3?0.6f:(11)==4?456.0f:(11)==5?0.125f:(11)==6?5.0f:(11)==7?1.4444444f:(11)==8?1.0f:(11)==9?46.0f:(11)==10?52.0f:(11)==11?0.5f:(11)==12?71.0f:(11)==13?22.0f:(11)==14?98.0f:(11)==15?93.388237f:0.76862746f) );
fn_1_495FC(); fn_1_495A0(((8)==1?20.0f:(8)==2?10.0f:(8)==3?0.6f:(8)==4?456.0f:(8)==5?0.125f:(8)==6?5.0f:(8)==7?1.4444444f:(8)==8?1.0f:(8)==9?46.0f:(8)==10?52.0f:(8)==11?0.5f:(8)==12?71.0f:(8)==13?22.0f:(8)==14?98.0f:(8)==15?93.388237f:0.76862746f) ); fn_1_4954C(((6)==1?20.0f:(6)==2?10.0f:(6)==3?0.6f:(6)==4?456.0f:(6)==5?0.125f:(6)==6?5.0f:(6)==7?1.4444444f:(6)==8?1.0f:(6)==9?46.0f:(6)==10?52.0f:(6)==11?0.5f:(6)==12?71.0f:(6)==13?22.0f:(6)==14?98.0f:(6)==15?93.388237f:0.76862746f) );
x=a+624;
fn_1_496FC(x,((14)==1?20.0f:(14)==2?10.0f:(14)==3?0.6f:(14)==4?456.0f:(14)==5?0.125f:(14)==6?5.0f:(14)==7?1.4444444f:(14)==8?1.0f:(14)==9?46.0f:(14)==10?52.0f:(14)==11?0.5f:(14)==12?71.0f:(14)==13?22.0f:(14)==14?98.0f:(14)==15?93.388237f:0.76862746f) ); fn_1_495C8(2);
switch(state->mode) {
case 5:
fn_1_4AE0C(fn_16_2560_array_read(lbl_1_data_21078, fn_1_12C930(arg)));
fn_1_496FC(x-fn_1_4B068(fn_16_2560_array_read(lbl_1_data_21078, fn_1_12C930(arg))),((15)==1?20.0f:(15)==2?10.0f:(15)==3?0.6f:(15)==4?456.0f:(15)==5?0.125f:(15)==6?5.0f:(15)==7?1.4444444f:(15)==8?1.0f:(15)==9?46.0f:(15)==10?52.0f:(15)==11?0.5f:(15)==12?71.0f:(15)==13?22.0f:(15)==14?98.0f:(15)==15?93.388237f:0.76862746f) );
break;
case 0:
default:
fn_1_4AE0C(fn_16_2560_array_read(lbl_1_data_212A8, fn_1_12C930(arg)));
fn_1_496FC(x-fn_1_4B068(fn_16_2560_array_read(lbl_1_data_212A8, fn_1_12C930(arg))),((15)==1?20.0f:(15)==2?10.0f:(15)==3?0.6f:(15)==4?456.0f:(15)==5?0.125f:(15)==6?5.0f:(15)==7?1.4444444f:(15)==8?1.0f:(15)==9?46.0f:(15)==10?52.0f:(15)==11?0.5f:(15)==12?71.0f:(15)==13?22.0f:(15)==14?98.0f:(15)==15?93.388237f:0.76862746f) );
break;
}
fn_1_4955C(((16)==1?20.0f:(16)==2?10.0f:(16)==3?0.6f:(16)==4?456.0f:(16)==5?0.125f:(16)==6?5.0f:(16)==7?1.4444444f:(16)==8?1.0f:(16)==9?46.0f:(16)==10?52.0f:(16)==11?0.5f:(16)==12?71.0f:(16)==13?22.0f:(16)==14?98.0f:(16)==15?93.388237f:0.76862746f) ,((16)==1?20.0f:(16)==2?10.0f:(16)==3?0.6f:(16)==4?456.0f:(16)==5?0.125f:(16)==6?5.0f:(16)==7?1.4444444f:(16)==8?1.0f:(16)==9?46.0f:(16)==10?52.0f:(16)==11?0.5f:(16)==12?71.0f:(16)==13?22.0f:(16)==14?98.0f:(16)==15?93.388237f:0.76862746f) ); fn_1_4A0D8(((char *)fzgx_pool_data_lbl_16_data_82DB0_67C));
}
#pragma opt_dead_assignments reset

