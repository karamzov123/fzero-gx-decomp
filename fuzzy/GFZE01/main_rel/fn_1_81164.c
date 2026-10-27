/* Non-matching: best partial attempt (97.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
/* fzgx:begin fn_1_81164 noprologue */
#include "types.h"
#include "rel/main_rel/car.h"

typedef struct Fn81164Model {
    u8 pad_0[0x8];
    u32 unk_8;
} Fn81164Model;

typedef struct Fn81164Car {
    u8 pad_0[0x328];
    s8 unk_328;
    u8 pad_329[0x37C - 0x329];
    Fn81164Model *unk_37C[4];
    u32 unk_38C;
    u32 unk_390;
    u8 pad_394[0x3A8 - 0x394];
    u32 unk_3A8;
    u8 pad_3AC[0x3B8 - 0x3AC];
    s16 unk_3B8;
} Fn81164Car;
extern u8 fn_1_87750__fzgx_offset_0[];
extern u8 fn_1_877E8__fzgx_offset_0[];
extern u8 fn_1_87880__fzgx_offset_0[];
extern u8 fn_1_87918__fzgx_offset_0[];
extern u8 fn_1_879B0__fzgx_offset_0[];
extern u8 fn_1_87AD8__fzgx_offset_0[];
extern u8 fn_1_87B70__fzgx_offset_0[];
extern u8 fn_1_87C08__fzgx_offset_0[];
extern u8 fn_1_87CA0__fzgx_offset_0[];
extern u8 fn_1_87D38__fzgx_offset_0[];
extern u8 fn_1_87DD0__fzgx_offset_0[];
extern u8 fn_1_87E68__fzgx_offset_0[];
extern u8 fn_1_87F00__fzgx_offset_0[];
extern u8 fn_1_87F98__fzgx_offset_0[];
extern u8 fn_1_88030__fzgx_offset_0[];
extern u8 fn_1_880C8__fzgx_offset_0[];
extern u8 fn_1_88160__fzgx_offset_0[];
extern u8 fn_1_881F8__fzgx_offset_0[];
extern u8 fn_1_88290__fzgx_offset_0[];
extern u8 fn_1_88328__fzgx_offset_0[];
extern u8 fn_1_883C0__fzgx_offset_0[];
extern u8 fn_1_88458__fzgx_offset_0[];
extern u8 fn_1_8856C__fzgx_offset_0[];
extern u8 fn_1_88604__fzgx_offset_0[];
extern u8 fn_1_8869C__fzgx_offset_0[];
extern u8 fn_1_88734__fzgx_offset_0[];
extern u8 fn_1_887CC__fzgx_offset_0[];
extern u8 fn_1_88864__fzgx_offset_0[];
extern u8 fn_1_888FC__fzgx_offset_0[];
extern u8 fn_1_88994__fzgx_offset_0[];
extern u8 fn_1_88A2C__fzgx_offset_0[];
extern u8 fn_1_88AC4__fzgx_offset_0[];
extern u8 fn_1_88B5C__fzgx_offset_0[];
extern u8 fn_1_88BF4__fzgx_offset_0[];
extern u8 fn_1_88C8C__fzgx_offset_0[];
extern u8 fn_1_88D24__fzgx_offset_0[];
extern u8 fn_1_88DBC__fzgx_offset_0[];
extern u8 fn_1_88E54__fzgx_offset_0[];
extern u8 fn_1_88EEC__fzgx_offset_0[];
extern u8 fn_1_88F84__fzgx_offset_0[];
extern u8 fn_1_8901C__fzgx_offset_0[];
extern u8 lbl_1_data_1F1D8__fzgx_offset_0[];
extern u8 lbl_1_data_1F1E0__fzgx_offset_0[];
extern u8 lbl_1_data_1F1E8__fzgx_offset_0[];
extern u8 lbl_1_data_1F1F0__fzgx_offset_0[];
extern u8 lbl_1_data_1F1F8__fzgx_offset_0[];
extern u8 lbl_1_data_1F200__fzgx_offset_0[];
extern u8 lbl_1_data_1F208__fzgx_offset_0[];
extern u8 lbl_1_data_1F210__fzgx_offset_0[];
extern u8 lbl_1_data_1F218__fzgx_offset_0[];
extern u8 lbl_1_data_1F220__fzgx_offset_0[];
extern u8 lbl_1_data_1F224__fzgx_offset_0[];
extern u8 lbl_1_data_1F22C__fzgx_offset_0[];
extern u8 lbl_1_data_1F234__fzgx_offset_0[];
extern u8 lbl_1_data_1F23C__fzgx_offset_0[];
extern u8 lbl_1_data_1F244__fzgx_offset_0[];
extern u8 lbl_1_data_1F24C__fzgx_offset_0[];
extern u8 lbl_1_data_1F254__fzgx_offset_0[];
extern u8 lbl_1_data_1F25C__fzgx_offset_0[];
extern u8 lbl_1_data_1F264__fzgx_offset_0[];
extern u8 lbl_1_data_1F26C__fzgx_offset_0[];
extern u8 lbl_1_data_1F274__fzgx_offset_0[];
extern u8 lbl_1_data_1F27C__fzgx_offset_0[];
extern u8 lbl_1_data_1F284__fzgx_offset_0[];
extern u8 lbl_1_data_1F28C__fzgx_offset_0[];
extern u8 lbl_1_data_1F294__fzgx_offset_0[];
extern u8 lbl_1_data_1F29C__fzgx_offset_0[];
extern u8 lbl_1_data_1F2A4__fzgx_offset_0[];
extern u8 lbl_1_data_1F2A8__fzgx_offset_0[];
extern u8 lbl_1_data_1F2B0__fzgx_offset_0[];
extern u8 lbl_1_data_1F2B8__fzgx_offset_0[];
extern u8 lbl_1_data_1F2C0__fzgx_offset_0[];
extern u8 lbl_1_data_1F2C8__fzgx_offset_0[];
extern u8 lbl_1_data_1F2D0__fzgx_offset_0[];
extern u8 lbl_1_data_1F2D8__fzgx_offset_0[];
extern u8 lbl_1_data_1F2E0__fzgx_offset_0[];
extern u8 lbl_1_data_1F2E8__fzgx_offset_0[];
extern u8 lbl_1_data_1F2F0__fzgx_offset_0[];
extern u8 lbl_1_data_1F2F8__fzgx_offset_0[];
extern u8 lbl_1_data_1F300__fzgx_offset_0[];
extern u8 lbl_1_data_1F308__fzgx_offset_0[];
extern u8 lbl_1_data_1F310__fzgx_offset_0[];
extern u8 lbl_1_data_1F3BC__fzgx_offset_0[];
extern u8 lbl_1_data_1F3C4__fzgx_offset_0[];
extern u8 lbl_1_data_1F3CC__fzgx_offset_0[];
extern u8 lbl_1_data_1F3D4__fzgx_offset_0[];
extern u8 lbl_1_data_1F3DC__fzgx_offset_0[];
extern u8 lbl_1_data_1F3E4__fzgx_offset_0[];
extern u8 lbl_1_data_1F3EC__fzgx_offset_0[];
extern u8 lbl_1_data_1F3F4__fzgx_offset_0[];
extern u8 lbl_1_data_1F3FC__fzgx_offset_0[];
extern u8 lbl_1_data_1F404__fzgx_offset_0[];
extern u8 lbl_1_data_1F408__fzgx_offset_0[];
extern u8 lbl_1_data_1F410__fzgx_offset_0[];
extern u8 lbl_1_data_1F418__fzgx_offset_0[];
extern u8 lbl_1_data_1F420__fzgx_offset_0[];
extern u8 lbl_1_data_1F428__fzgx_offset_0[];
extern u8 lbl_1_data_1F430__fzgx_offset_0[];
extern u8 lbl_1_data_1F438__fzgx_offset_0[];
extern u8 lbl_1_data_1F440__fzgx_offset_0[];
extern u8 lbl_1_data_1F448__fzgx_offset_0[];
extern u8 lbl_1_data_1F450__fzgx_offset_0[];
extern u8 lbl_1_data_1F458__fzgx_offset_0[];
extern u8 lbl_1_data_1F460__fzgx_offset_0[];
extern u8 lbl_1_data_1F468__fzgx_offset_0[];
extern u8 lbl_1_data_1F470__fzgx_offset_0[];
extern u8 lbl_1_data_1F478__fzgx_offset_0[];
extern u8 lbl_1_data_1F480__fzgx_offset_0[];
extern u8 lbl_1_data_1F488__fzgx_offset_0[];
extern u8 lbl_1_data_1F48C__fzgx_offset_0[];
extern u8 lbl_1_data_1F494__fzgx_offset_0[];
extern u8 lbl_1_data_1F49C__fzgx_offset_0[];
extern u8 lbl_1_data_1F4A4__fzgx_offset_0[];
extern u8 lbl_1_data_1F4AC__fzgx_offset_0[];
extern u8 lbl_1_data_1F4B4__fzgx_offset_0[];
extern u8 lbl_1_data_1F4BC__fzgx_offset_0[];
extern u8 lbl_1_data_1F4C4__fzgx_offset_0[];
extern u8 lbl_1_data_1F4CC__fzgx_offset_0[];
extern u8 lbl_1_data_1F4D4__fzgx_offset_0[];
extern u8 lbl_1_data_1F4DC__fzgx_offset_0[];
extern u8 lbl_1_data_1F4E4__fzgx_offset_0[];
extern u8 lbl_1_data_1F4EC__fzgx_offset_0[];
extern u8 lbl_1_data_1F4F4__fzgx_offset_0[];
extern u8 lbl_1_data_1F644__fzgx_offset_0[];
extern u8 lbl_1_data_1F650__fzgx_offset_0[];
extern u8 lbl_1_data_1F65C__fzgx_offset_0[];
extern u8 lbl_1_data_1F668__fzgx_offset_0[];
extern u8 lbl_1_data_1F674__fzgx_offset_0[];
extern u8 lbl_1_data_1F680__fzgx_offset_0[];
extern u8 lbl_1_data_1F68C__fzgx_offset_0[];
extern u8 lbl_1_data_1F698__fzgx_offset_0[];
extern u8 lbl_1_data_1F6A4__fzgx_offset_0[];
extern u8 lbl_1_data_1F6B0__fzgx_offset_0[];
extern u8 lbl_1_data_1F6BC__fzgx_offset_0[];
extern u8 lbl_1_data_1F6C8__fzgx_offset_0[];
extern u8 lbl_1_data_1F6D4__fzgx_offset_0[];
extern u8 lbl_1_data_1F6E0__fzgx_offset_0[];
extern u8 lbl_1_data_1F6EC__fzgx_offset_0[];
extern u8 lbl_1_data_1F6F8__fzgx_offset_0[];
extern u8 lbl_1_data_1F704__fzgx_offset_0[];
extern u8 lbl_1_data_1F710__fzgx_offset_0[];
extern u8 lbl_1_data_1F71C__fzgx_offset_0[];
extern u8 lbl_1_data_1F728__fzgx_offset_0[];
extern u8 lbl_1_data_1F734__fzgx_offset_0[];
extern u8 lbl_1_data_1F740__fzgx_offset_0[];
extern u8 lbl_1_data_1F74C__fzgx_offset_0[];
extern u8 lbl_1_data_1F758__fzgx_offset_0[];
extern u8 lbl_1_data_1F764__fzgx_offset_0[];
extern u8 lbl_1_data_1F770__fzgx_offset_0[];
extern u8 lbl_1_data_1F77C__fzgx_offset_0[];
extern u8 lbl_1_data_1F788__fzgx_offset_0[];
extern u8 lbl_1_data_1F794__fzgx_offset_0[];
extern u8 lbl_1_data_1F7A0__fzgx_offset_0[];
extern u8 lbl_1_data_1F7AC__fzgx_offset_0[];
extern u8 lbl_1_data_1F7C4__fzgx_offset_0[];
extern u8 lbl_1_data_1F7DC__fzgx_offset_0[];
extern u8 lbl_1_data_1F7E8__fzgx_offset_0[];
extern u8 lbl_1_data_1F7F4__fzgx_offset_0[];
extern u8 lbl_1_data_1F89C__fzgx_offset_0[];
extern u8 lbl_1_data_1F944__fzgx_offset_0[];
extern u8 lbl_1_data_1F950__fzgx_offset_0[];
extern u8 lbl_1_data_1F95C__fzgx_offset_0[];
extern u8 lbl_1_data_1F968__fzgx_offset_0[];
extern u8 lbl_1_data_1F974__fzgx_offset_0[];
extern u8 lbl_1_data_1F980__fzgx_offset_0[];
extern u8 lbl_1_data_1F98C__fzgx_offset_0[];
extern u8 lbl_1_data_1F998__fzgx_offset_0[];
extern u8 lbl_1_data_1F9A4__fzgx_offset_0[];
extern u8 lbl_1_data_1F9B0__fzgx_offset_0[];
extern u8 lbl_1_data_1F9BC__fzgx_offset_0[];
extern u8 lbl_1_data_1F9C8__fzgx_offset_0[];
extern u8 lbl_1_data_1F9D4__fzgx_offset_0[];
extern u8 lbl_1_data_1F9E0__fzgx_offset_0[];
extern u8 lbl_1_data_1F9EC__fzgx_offset_0[];
extern u8 lbl_1_data_1F9F8__fzgx_offset_0[];
extern u8 lbl_1_data_1FA04__fzgx_offset_0[];
extern u8 lbl_1_data_1FA10__fzgx_offset_0[];
extern u8 lbl_1_data_1FA1C__fzgx_offset_0[];
extern u8 lbl_1_data_1FA28__fzgx_offset_0[];
extern u8 lbl_1_data_1FA34__fzgx_offset_0[];
extern u8 lbl_1_data_1FA40__fzgx_offset_0[];
extern u8 lbl_1_data_1FA4C__fzgx_offset_0[];
extern u8 lbl_1_data_1FA58__fzgx_offset_0[];
extern u8 lbl_1_data_1FA64__fzgx_offset_0[];
extern u8 lbl_1_data_1FA70__fzgx_offset_0[];
extern u8 lbl_1_data_1FA7C__fzgx_offset_0[];
extern u8 lbl_1_data_1FA88__fzgx_offset_0[];
extern u8 lbl_1_data_1FA94__fzgx_offset_0[];
extern u8 lbl_1_data_1FAA0__fzgx_offset_0[];
extern u8 lbl_1_data_1FAAC__fzgx_offset_0[];
extern u8 lbl_1_data_1FAB8__fzgx_offset_0[];
extern u8 lbl_1_data_1FAC4__fzgx_offset_0[];
extern u8 lbl_1_data_1FAD0__fzgx_offset_0[];
extern u8 lbl_1_data_1FADC__fzgx_offset_0[];
extern u8 lbl_1_data_1FAE8__fzgx_offset_0[];
extern u8 lbl_1_data_1FAF4__fzgx_offset_0[];
extern u8 lbl_1_data_1FB00__fzgx_offset_0[];
extern u8 lbl_1_data_1FB0C__fzgx_offset_0[];
extern u8 lbl_1_data_1FB18__fzgx_offset_0[];
extern u8 lbl_1_data_1FB24__fzgx_offset_0[];
extern u8 lbl_1_data_1FB30__fzgx_offset_0[];
extern u8 lbl_1_data_1FB3C__fzgx_offset_0[];
extern u8 lbl_1_data_1FB48__fzgx_offset_0[];
extern u8 lbl_1_data_1FB54__fzgx_offset_0[];
extern u8 lbl_1_data_1FB60__fzgx_offset_0[];
extern u8 lbl_1_data_1FCB4__fzgx_offset_0[];
extern u8 lbl_1_data_1FCB8__fzgx_offset_0[];
extern u8 lbl_1_data_1FCC4__fzgx_offset_0[];
extern u8 lbl_1_data_1FCD0__fzgx_offset_0[];
extern u8 lbl_1_data_1FCDC__fzgx_offset_0[];
extern u8 lbl_1_data_1FCE8__fzgx_offset_0[];
extern u8 lbl_1_data_1FCF0__fzgx_offset_0[];
extern u8 lbl_1_data_1FCF8__fzgx_offset_0[];
extern u8 lbl_1_data_1FD00__fzgx_offset_0[];
extern u8 lbl_1_data_1FD08__fzgx_offset_0[];
extern u8 lbl_1_data_1FD14__fzgx_offset_0[];
extern u8 lbl_1_data_1FD24__fzgx_offset_0[];
extern u8 lbl_1_data_1FD34__fzgx_offset_0[];
extern u8 lbl_1_data_1FD3C__fzgx_offset_0[];
extern u8 lbl_1_data_1FD44__fzgx_offset_0[];
extern u8 lbl_1_data_1FD50__fzgx_offset_0[];
extern u8 lbl_1_data_1FD5C__fzgx_offset_0[];
extern u8 lbl_1_data_1FD6C__fzgx_offset_0[];
extern u8 lbl_1_data_1FD74__fzgx_offset_0[];
extern u8 lbl_1_data_1FD80__fzgx_offset_0[];
extern u8 lbl_1_data_1FD8C__fzgx_offset_0[];
extern u8 lbl_1_data_1FD9C__fzgx_offset_0[];
extern u8 lbl_1_data_1FDA4__fzgx_offset_0[];
extern u8 lbl_1_data_1FDB0__fzgx_offset_0[];
extern u8 lbl_1_data_1FDBC__fzgx_offset_0[];
extern u8 lbl_1_data_1FDCC__fzgx_offset_0[];
extern u8 lbl_1_data_1FDD4__fzgx_offset_0[];
extern u8 lbl_1_data_1FDE0__fzgx_offset_0[];
extern u8 lbl_1_data_1FDE8__fzgx_offset_0[];
extern u8 lbl_1_data_1FDF4__fzgx_offset_0[];
extern u8 lbl_1_data_1FE04__fzgx_offset_0[];
extern u8 lbl_1_data_1FE10__fzgx_offset_0[];
extern u8 lbl_1_data_1FE1C__fzgx_offset_0[];
extern u8 lbl_1_data_1FE24__fzgx_offset_0[];
extern u8 lbl_1_data_1FE38__fzgx_offset_0[];
extern u8 lbl_1_data_1FE48__fzgx_offset_0[];
extern u8 lbl_1_data_1FE58__fzgx_offset_0[];
extern u8 lbl_1_data_1FE64__fzgx_offset_0[];
extern u8 lbl_1_data_1FE70__fzgx_offset_0[];
extern u8 lbl_1_data_1FE80__fzgx_offset_0[];
extern u8 lbl_1_data_1FE88__fzgx_offset_0[];
extern u8 lbl_1_data_1FE94__fzgx_offset_0[];
extern u8 lbl_1_data_1FE9C__fzgx_offset_0[];
extern u8 lbl_1_data_1FEA4__fzgx_offset_0[];
extern u8 lbl_1_data_1FEAC__fzgx_offset_0[];
extern u8 lbl_1_data_1FF74__fzgx_offset_0[];
extern u8 lbl_1_data_1FF80__fzgx_offset_0[];
extern u8 lbl_1_data_1FF88__fzgx_offset_0[];
extern u8 lbl_1_data_1FF94__fzgx_offset_0[];
extern u8 lbl_1_data_1FF9C__fzgx_offset_0[];
extern u8 lbl_1_data_1FFA8__fzgx_offset_0[];
extern u8 lbl_1_data_1FFB0__fzgx_offset_0[];
extern u8 lbl_1_data_1FFB8__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_1F1D8[201] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x5247415A, 0x45000000, 0x57434154, 0x0, 0x47464F58, 0x0, 0x49544947, 0x45520000,
    0x46535449, 0x4E470000, 0x57474F4F, 0x53450000, 0x4246414C, 0x434F4E00, 0x44434C41, 0x57000000,
    0x47535441, 0x52000000, 0x4C575900, 0x4D574F4C, 0x46000000, 0x53504952, 0x41000000, 0x44414E43,
    0x0, 0x41524F42, 0x494E0000, 0x4246414E, 0x47000000, 0x53504841, 0x4E000000, 0x4750414E,
    0x0, 0x48535045, 0x45440000, 0x53414E47, 0x0, 0x4B4D4554, 0x45000000, 0x514D4554,
    0x45000000, 0x544E4F52, 0x49000000, 0x4E544855, 0x4E000000, 0x57424F41, 0x52000000, 0x48484157,
    0x4B000000, 0x57574153, 0x50000000, 0x4D545900, 0x4D485552, 0x52000000, 0x43424541, 0x52000000,
    0x4242554C, 0x4C000000, 0x4441524B, 0x53000000, 0x46415453, 0x0, 0x53434152, 0x50000000,
    0x50494E4B, 0x53000000, 0x4D47554C, 0x4C000000, 0x53524154, 0x0, 0x534D4F4F, 0x4E000000,
    0x50524142, 0x42495400, 0x47544158, 0x49000000, 0x52524F43, 0x4B000000, 0x5241494E, 0x50000000,
    (u32)lbl_1_data_1F1D8__fzgx_offset_0, (u32)lbl_1_data_1F1E0__fzgx_offset_0, (u32)lbl_1_data_1F1E8__fzgx_offset_0, (u32)lbl_1_data_1F1F0__fzgx_offset_0, (u32)lbl_1_data_1F1F8__fzgx_offset_0, (u32)lbl_1_data_1F200__fzgx_offset_0, (u32)lbl_1_data_1F208__fzgx_offset_0, (u32)lbl_1_data_1F210__fzgx_offset_0,
    (u32)lbl_1_data_1F218__fzgx_offset_0, (u32)lbl_1_data_1F220__fzgx_offset_0, (u32)lbl_1_data_1F224__fzgx_offset_0, (u32)lbl_1_data_1F22C__fzgx_offset_0, (u32)lbl_1_data_1F234__fzgx_offset_0, (u32)lbl_1_data_1F23C__fzgx_offset_0, (u32)lbl_1_data_1F244__fzgx_offset_0, (u32)lbl_1_data_1F24C__fzgx_offset_0,
    (u32)lbl_1_data_1F254__fzgx_offset_0, (u32)lbl_1_data_1F25C__fzgx_offset_0, (u32)lbl_1_data_1F264__fzgx_offset_0, (u32)lbl_1_data_1F26C__fzgx_offset_0, (u32)lbl_1_data_1F274__fzgx_offset_0, (u32)lbl_1_data_1F27C__fzgx_offset_0, (u32)lbl_1_data_1F284__fzgx_offset_0, (u32)lbl_1_data_1F28C__fzgx_offset_0,
    (u32)lbl_1_data_1F294__fzgx_offset_0, (u32)lbl_1_data_1F29C__fzgx_offset_0, (u32)lbl_1_data_1F2A4__fzgx_offset_0, (u32)lbl_1_data_1F2A8__fzgx_offset_0, (u32)lbl_1_data_1F2B0__fzgx_offset_0, (u32)lbl_1_data_1F2B8__fzgx_offset_0, (u32)lbl_1_data_1F2C0__fzgx_offset_0, (u32)lbl_1_data_1F2C8__fzgx_offset_0,
    (u32)lbl_1_data_1F2D0__fzgx_offset_0, (u32)lbl_1_data_1F2D8__fzgx_offset_0, (u32)lbl_1_data_1F2E0__fzgx_offset_0, (u32)lbl_1_data_1F2E8__fzgx_offset_0, (u32)lbl_1_data_1F2F0__fzgx_offset_0, (u32)lbl_1_data_1F2F8__fzgx_offset_0, (u32)lbl_1_data_1F300__fzgx_offset_0, (u32)lbl_1_data_1F308__fzgx_offset_0,
    (u32)lbl_1_data_1F310__fzgx_offset_0, 0x7267617A, 0x65000000, 0x77636174, 0x0, 0x67666F78, 0x0, 0x69746967,
    0x65720000, 0x66737469, 0x6E670000, 0x77676F6F, 0x73650000, 0x6266616C, 0x636F6E00, 0x64636C61,
    0x77000000, 0x67737461, 0x72000000, 0x6C777900, 0x6D776F6C, 0x66000000, 0x73706972, 0x61000000,
    0x64616E63, 0x0, 0x61726F62, 0x696E0000, 0x6266616E, 0x67000000, 0x73706861, 0x6E000000,
    0x6770616E, 0x0, 0x68737065, 0x65640000, 0x73616E67, 0x0, 0x6B6D6574, 0x65000000,
    0x716D6574, 0x65000000, 0x746E6F72, 0x69000000, 0x6E746875, 0x6E000000, 0x77626F61, 0x72000000,
    0x68686177, 0x6B000000, 0x77776173, 0x70000000, 0x6D747900, 0x6D687572, 0x72000000, 0x63626561,
    0x72000000, 0x6262756C, 0x6C000000, 0x6461726B, 0x73000000, 0x66617473, 0x0, 0x73636172,
    0x70000000, 0x70696E6B, 0x73000000, 0x6D67756C, 0x6C000000, 0x73726174, 0x0, 0x736D6F6F,
    0x6E000000, 0x70726162, 0x62697400, 0x67746178, 0x69000000, 0x72726F63, 0x6B000000, 0x7261696E,
    0x70000000
};
static u32 fzgx_pool_data_lbl_1_data_1F4FC[41] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_1F3BC__fzgx_offset_0, (u32)lbl_1_data_1F3C4__fzgx_offset_0, (u32)lbl_1_data_1F3CC__fzgx_offset_0, (u32)lbl_1_data_1F3D4__fzgx_offset_0, (u32)lbl_1_data_1F3DC__fzgx_offset_0, (u32)lbl_1_data_1F3E4__fzgx_offset_0, (u32)lbl_1_data_1F3EC__fzgx_offset_0, (u32)lbl_1_data_1F3F4__fzgx_offset_0,
    (u32)lbl_1_data_1F3FC__fzgx_offset_0, (u32)lbl_1_data_1F404__fzgx_offset_0, (u32)lbl_1_data_1F408__fzgx_offset_0, (u32)lbl_1_data_1F410__fzgx_offset_0, (u32)lbl_1_data_1F418__fzgx_offset_0, (u32)lbl_1_data_1F420__fzgx_offset_0, (u32)lbl_1_data_1F428__fzgx_offset_0, (u32)lbl_1_data_1F430__fzgx_offset_0,
    (u32)lbl_1_data_1F438__fzgx_offset_0, (u32)lbl_1_data_1F440__fzgx_offset_0, (u32)lbl_1_data_1F448__fzgx_offset_0, (u32)lbl_1_data_1F450__fzgx_offset_0, (u32)lbl_1_data_1F458__fzgx_offset_0, (u32)lbl_1_data_1F460__fzgx_offset_0, (u32)lbl_1_data_1F468__fzgx_offset_0, (u32)lbl_1_data_1F470__fzgx_offset_0,
    (u32)lbl_1_data_1F478__fzgx_offset_0, (u32)lbl_1_data_1F480__fzgx_offset_0, (u32)lbl_1_data_1F488__fzgx_offset_0, (u32)lbl_1_data_1F48C__fzgx_offset_0, (u32)lbl_1_data_1F494__fzgx_offset_0, (u32)lbl_1_data_1F49C__fzgx_offset_0, (u32)lbl_1_data_1F4A4__fzgx_offset_0, (u32)lbl_1_data_1F4AC__fzgx_offset_0,
    (u32)lbl_1_data_1F4B4__fzgx_offset_0, (u32)lbl_1_data_1F4BC__fzgx_offset_0, (u32)lbl_1_data_1F4C4__fzgx_offset_0, (u32)lbl_1_data_1F4CC__fzgx_offset_0, (u32)lbl_1_data_1F4D4__fzgx_offset_0, (u32)lbl_1_data_1F4DC__fzgx_offset_0, (u32)lbl_1_data_1F4E4__fzgx_offset_0, (u32)lbl_1_data_1F4EC__fzgx_offset_0,
    (u32)lbl_1_data_1F4F4__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_1_data_1F5A0[657] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)fn_1_87750__fzgx_offset_0, (u32)fn_1_877E8__fzgx_offset_0, (u32)fn_1_87880__fzgx_offset_0, (u32)fn_1_87918__fzgx_offset_0, (u32)fn_1_879B0__fzgx_offset_0, (u32)fn_1_87AD8__fzgx_offset_0, (u32)fn_1_87B70__fzgx_offset_0, (u32)fn_1_87C08__fzgx_offset_0,
    (u32)fn_1_87CA0__fzgx_offset_0, (u32)fn_1_87D38__fzgx_offset_0, (u32)fn_1_87DD0__fzgx_offset_0, (u32)fn_1_87E68__fzgx_offset_0, (u32)fn_1_87F00__fzgx_offset_0, (u32)fn_1_87F98__fzgx_offset_0, (u32)fn_1_88030__fzgx_offset_0, (u32)fn_1_880C8__fzgx_offset_0,
    (u32)fn_1_88160__fzgx_offset_0, (u32)fn_1_881F8__fzgx_offset_0, (u32)fn_1_88290__fzgx_offset_0, (u32)fn_1_88328__fzgx_offset_0, (u32)fn_1_883C0__fzgx_offset_0, (u32)fn_1_88458__fzgx_offset_0, (u32)fn_1_8856C__fzgx_offset_0, (u32)fn_1_88604__fzgx_offset_0,
    (u32)fn_1_8869C__fzgx_offset_0, (u32)fn_1_88734__fzgx_offset_0, (u32)fn_1_887CC__fzgx_offset_0, (u32)fn_1_88864__fzgx_offset_0, (u32)fn_1_888FC__fzgx_offset_0, (u32)fn_1_88994__fzgx_offset_0, (u32)fn_1_88A2C__fzgx_offset_0, (u32)fn_1_88AC4__fzgx_offset_0,
    (u32)fn_1_88B5C__fzgx_offset_0, (u32)fn_1_88BF4__fzgx_offset_0, (u32)fn_1_88C8C__fzgx_offset_0, (u32)fn_1_88D24__fzgx_offset_0, (u32)fn_1_88DBC__fzgx_offset_0, (u32)fn_1_88E54__fzgx_offset_0, (u32)fn_1_88EEC__fzgx_offset_0, (u32)fn_1_88F84__fzgx_offset_0,
    (u32)fn_1_8901C__fzgx_offset_0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000,
    0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0,
    0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0,
    0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000,
    0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0,
    0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0,
    0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000,
    0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0,
    0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0,
    0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000,
    0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0,
    0xFFFF0000, 0x0, 0x0, 0x30000, 0x0, 0x0, 0xFFFF0000, 0x0,
    0x0, 0x30000, 0xFF000000, 0xFF000000, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000,
    0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x10000, 0x0, 0x0, 0x20000, 0x0, 0x0, 0x30000, 0x0,
    0x0, 0x40000, 0x0, 0x0, 0x50000, 0x0, 0x0, 0x60000,
    0x0, 0x0, 0x70000, 0x0, 0x0, 0x80000, 0x0, 0x0,
    0x90000, 0x0, 0x0, 0xA0000, 0x0, 0x0, 0xB0000, 0x0,
    0x0, 0xC0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0x0,
    0xFFFFFF00, 0xFFFFFF00, 0x10000, 0xFFFFFF00, 0xFFFFFF00, 0x20000, 0xFFFFFF00, 0xFFFFFF00,
    0x30000, 0xFFFFFF00, 0xFFFFFF00, 0x40000, 0xFFFFFF00, 0xFFFFFF00, 0x50000, 0xFFFFFF00,
    0xFFFFFF00, 0x60000, 0xFFFFFF00, 0xFFFFFF00, 0x70000, 0xFFFFFF00, 0xFFFFFF00, 0x80000,
    0xFFFFFF00, 0xFFFFFF00, 0x90000, 0xFFFFFF00, 0xFFFFFF00, 0xA0000, 0xFFFFFF00, 0xFFFFFF00,
    0xB0000, 0xFFFFFF00, 0xFFFFFF00, 0xC0000, 0xFFFFFF00, 0xFFFFFF00, 0xFFFF0000, 0x0,
    0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000,
    0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0,
    0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0,
    0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000,
    0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0,
    0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0,
    0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000,
    0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0,
    0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0,
    0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000,
    0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0,
    0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0,
    0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000,
    0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0,
    0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0,
    0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000,
    0x0, 0x0, 0xFFFF0000, 0x0, 0x0, 0xFFFF0000, 0x0, 0x0,
    0xFFFF0000, 0x0, 0x0, (u32)lbl_1_data_1F644__fzgx_offset_0, (u32)lbl_1_data_1F65C__fzgx_offset_0, (u32)lbl_1_data_1F674__fzgx_offset_0, (u32)lbl_1_data_1F68C__fzgx_offset_0, (u32)lbl_1_data_1F6A4__fzgx_offset_0,
    (u32)lbl_1_data_1F6BC__fzgx_offset_0, (u32)lbl_1_data_1F6D4__fzgx_offset_0, (u32)lbl_1_data_1F6EC__fzgx_offset_0, (u32)lbl_1_data_1F704__fzgx_offset_0, (u32)lbl_1_data_1F71C__fzgx_offset_0, (u32)lbl_1_data_1F734__fzgx_offset_0, (u32)lbl_1_data_1F74C__fzgx_offset_0, (u32)lbl_1_data_1F764__fzgx_offset_0,
    (u32)lbl_1_data_1F77C__fzgx_offset_0, (u32)lbl_1_data_1F794__fzgx_offset_0, (u32)lbl_1_data_1F7AC__fzgx_offset_0, (u32)lbl_1_data_1F7DC__fzgx_offset_0, (u32)lbl_1_data_1F7F4__fzgx_offset_0, (u32)lbl_1_data_1F944__fzgx_offset_0, (u32)lbl_1_data_1F95C__fzgx_offset_0, (u32)lbl_1_data_1F974__fzgx_offset_0,
    (u32)lbl_1_data_1F98C__fzgx_offset_0, (u32)lbl_1_data_1F9A4__fzgx_offset_0, (u32)lbl_1_data_1F9BC__fzgx_offset_0, (u32)lbl_1_data_1F9D4__fzgx_offset_0, (u32)lbl_1_data_1F9EC__fzgx_offset_0, (u32)lbl_1_data_1FA04__fzgx_offset_0, (u32)lbl_1_data_1FA1C__fzgx_offset_0, (u32)lbl_1_data_1FA34__fzgx_offset_0,
    (u32)lbl_1_data_1FA4C__fzgx_offset_0, (u32)lbl_1_data_1FA64__fzgx_offset_0, (u32)lbl_1_data_1FA7C__fzgx_offset_0, (u32)lbl_1_data_1FA94__fzgx_offset_0, (u32)lbl_1_data_1FAAC__fzgx_offset_0, (u32)lbl_1_data_1FAC4__fzgx_offset_0, (u32)lbl_1_data_1FADC__fzgx_offset_0, (u32)lbl_1_data_1FAF4__fzgx_offset_0,
    (u32)lbl_1_data_1FB0C__fzgx_offset_0, (u32)lbl_1_data_1FB24__fzgx_offset_0, (u32)lbl_1_data_1FB3C__fzgx_offset_0, (u32)lbl_1_data_1FB54__fzgx_offset_0, (u32)lbl_1_data_1F650__fzgx_offset_0, (u32)lbl_1_data_1F668__fzgx_offset_0, (u32)lbl_1_data_1F680__fzgx_offset_0, (u32)lbl_1_data_1F698__fzgx_offset_0,
    (u32)lbl_1_data_1F6B0__fzgx_offset_0, (u32)lbl_1_data_1F6C8__fzgx_offset_0, (u32)lbl_1_data_1F6E0__fzgx_offset_0, (u32)lbl_1_data_1F6F8__fzgx_offset_0, (u32)lbl_1_data_1F710__fzgx_offset_0, (u32)lbl_1_data_1F728__fzgx_offset_0, (u32)lbl_1_data_1F740__fzgx_offset_0, (u32)lbl_1_data_1F758__fzgx_offset_0,
    (u32)lbl_1_data_1F770__fzgx_offset_0, (u32)lbl_1_data_1F788__fzgx_offset_0, (u32)lbl_1_data_1F7A0__fzgx_offset_0, (u32)lbl_1_data_1F7C4__fzgx_offset_0, (u32)lbl_1_data_1F7E8__fzgx_offset_0, (u32)lbl_1_data_1F89C__fzgx_offset_0, (u32)lbl_1_data_1F950__fzgx_offset_0, (u32)lbl_1_data_1F968__fzgx_offset_0,
    (u32)lbl_1_data_1F980__fzgx_offset_0, (u32)lbl_1_data_1F998__fzgx_offset_0, (u32)lbl_1_data_1F9B0__fzgx_offset_0, (u32)lbl_1_data_1F9C8__fzgx_offset_0, (u32)lbl_1_data_1F9E0__fzgx_offset_0, (u32)lbl_1_data_1F9F8__fzgx_offset_0, (u32)lbl_1_data_1FA10__fzgx_offset_0, (u32)lbl_1_data_1FA28__fzgx_offset_0,
    (u32)lbl_1_data_1FA40__fzgx_offset_0, (u32)lbl_1_data_1FA58__fzgx_offset_0, (u32)lbl_1_data_1FA70__fzgx_offset_0, (u32)lbl_1_data_1FA88__fzgx_offset_0, (u32)lbl_1_data_1FAA0__fzgx_offset_0, (u32)lbl_1_data_1FAB8__fzgx_offset_0, (u32)lbl_1_data_1FAD0__fzgx_offset_0, (u32)lbl_1_data_1FAE8__fzgx_offset_0,
    (u32)lbl_1_data_1FB00__fzgx_offset_0, (u32)lbl_1_data_1FB18__fzgx_offset_0, (u32)lbl_1_data_1FB30__fzgx_offset_0, (u32)lbl_1_data_1FB48__fzgx_offset_0, (u32)lbl_1_data_1FB60__fzgx_offset_0, 0x4E4F4E00, 0x4D415354, 0x45522052,
    0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156, 0x45205345, 0x4E440000, 0x534C4156,
    0x45205245, 0x43560000, 0x494E4954, 0x0, 0x54455354, 0x0, 0x54455354, 0x454E4400,
    0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000, 0x53455455, 0x505F434F, 0x554E5445,
    0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000, 0x434F494E,
    0x0, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C, 0x4C454E47, 0x45520000, 0x4348414C,
    0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B, 0x0,
    0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000, 0x434F5552,
    0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552, 0x53455F44, 0x41544100, 0x434F5552,
    0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F, 0x4F4B0000,
    0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241, 0x444A5553,
    0x54000000, 0x4C494E4B, 0x57414954, 0x0, 0x4C494E4B, 0x57414954, 0x4F4B0000, 0x4C494E4B,
    0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152, 0x54000000, 0x4C494E4B, 0x44454C49,
    0x56455259, 0x0, 0x4C494E4B, 0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B, 0x53454C4F,
    0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552, 0x53455649, 0x45575F4F, 0x4B000000,
    0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000, 0x4C494E4B,
    0x0, 0x50415553, 0x45000000, 0x4552524F, 0x52000000, (u32)lbl_1_data_1FCB4__fzgx_offset_0, (u32)lbl_1_data_1FCB8__fzgx_offset_0, (u32)lbl_1_data_1FCC4__fzgx_offset_0,
    (u32)lbl_1_data_1FCD0__fzgx_offset_0, (u32)lbl_1_data_1FCDC__fzgx_offset_0, (u32)lbl_1_data_1FCE8__fzgx_offset_0, (u32)lbl_1_data_1FCF0__fzgx_offset_0, (u32)lbl_1_data_1FCF8__fzgx_offset_0, (u32)lbl_1_data_1FD00__fzgx_offset_0, (u32)lbl_1_data_1FD08__fzgx_offset_0, (u32)lbl_1_data_1FD14__fzgx_offset_0,
    (u32)lbl_1_data_1FD24__fzgx_offset_0, (u32)lbl_1_data_1FD34__fzgx_offset_0, (u32)lbl_1_data_1FD3C__fzgx_offset_0, (u32)lbl_1_data_1FD44__fzgx_offset_0, (u32)lbl_1_data_1FD50__fzgx_offset_0, (u32)lbl_1_data_1FD5C__fzgx_offset_0, (u32)lbl_1_data_1FD6C__fzgx_offset_0, (u32)lbl_1_data_1FD74__fzgx_offset_0,
    (u32)lbl_1_data_1FD80__fzgx_offset_0, (u32)lbl_1_data_1FD8C__fzgx_offset_0, (u32)lbl_1_data_1FD9C__fzgx_offset_0, (u32)lbl_1_data_1FDA4__fzgx_offset_0, (u32)lbl_1_data_1FDB0__fzgx_offset_0, (u32)lbl_1_data_1FDBC__fzgx_offset_0, (u32)lbl_1_data_1FDCC__fzgx_offset_0, (u32)lbl_1_data_1FDD4__fzgx_offset_0,
    (u32)lbl_1_data_1FDE0__fzgx_offset_0, (u32)lbl_1_data_1FDE8__fzgx_offset_0, (u32)lbl_1_data_1FDF4__fzgx_offset_0, (u32)lbl_1_data_1FE04__fzgx_offset_0, (u32)lbl_1_data_1FE10__fzgx_offset_0, (u32)lbl_1_data_1FE1C__fzgx_offset_0, (u32)lbl_1_data_1FE24__fzgx_offset_0, (u32)lbl_1_data_1FE38__fzgx_offset_0,
    (u32)lbl_1_data_1FE48__fzgx_offset_0, (u32)lbl_1_data_1FE58__fzgx_offset_0, (u32)lbl_1_data_1FE64__fzgx_offset_0, (u32)lbl_1_data_1FE70__fzgx_offset_0, (u32)lbl_1_data_1FE80__fzgx_offset_0, (u32)lbl_1_data_1FE88__fzgx_offset_0, (u32)lbl_1_data_1FE94__fzgx_offset_0, (u32)lbl_1_data_1FE9C__fzgx_offset_0,
    (u32)lbl_1_data_1FEA4__fzgx_offset_0, (u32)lbl_1_data_1FEAC__fzgx_offset_0, 0x10507, 0x80C0D10, 0x12170000, 0x4F564552, 0x54414B45, 0x0,
    0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0, 0x57414C4C, 0x48495400, 0x53494445,
    0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C, 0x0, 0x4C415000, (u32)lbl_1_data_1FF74__fzgx_offset_0,
    (u32)lbl_1_data_1FF80__fzgx_offset_0, (u32)lbl_1_data_1FF88__fzgx_offset_0, (u32)lbl_1_data_1FF94__fzgx_offset_0, (u32)lbl_1_data_1FF9C__fzgx_offset_0, (u32)lbl_1_data_1FFA8__fzgx_offset_0, (u32)lbl_1_data_1FFB0__fzgx_offset_0, (u32)lbl_1_data_1FFB8__fzgx_offset_0, 0x6080000,
    0x40A00000
};
static u32 fzgx_pool_data_lbl_1_data_1F1D8_E0C[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x76656869, 0x636C652F, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_1FFF0[336] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6361722E, 0x63000000, 0x2E2E0000, 0x52656420, 0x47617A65, 0x6C6C6500, 0x838C8362, 0x8368834B,
    0x835B838B, 0x0, 0x57686974, 0x65204361, 0x74000000, 0x837A838F, 0x83438367, 0x834C8383,
    0x83628367, 0x0, 0x476F6C64, 0x656E2046, 0x6F780000, 0x8353815B, 0x838B8366, 0x83938374,
    0x83488362, 0x834E8358, 0x0, 0x49726F6E, 0x20546967, 0x65720000, 0x83418343, 0x83418393,
    0x835E8343, 0x834B815B, 0x0, 0x46697265, 0x20537469, 0x6E677261, 0x79000000, 0x83748340,
    0x83438341, 0x83588365, 0x83428393, 0x834F838C, 0x83430000, 0x57696C64, 0x20476F6F, 0x73650000,
    0x838F8343, 0x838B8368, 0x834F815B, 0x83580000, 0x426C7565, 0x2046616C, 0x636F6E00, 0x8375838B,
    0x815B8374, 0x8340838B, 0x83528393, 0x0, 0x44656570, 0x20436C61, 0x77000000, 0x83668342,  /* fzgx-allow: A1 retail data bytes */
    0x815B8376, 0x834E838D, 0x815B0000, 0x47726561, 0x74205374, 0x61720000, 0x834F838C, 0x815B8367,  /* fzgx-allow: A1 retail data bytes */
    0x8358835E, 0x815B0000, 0x4C697474, 0x6C652057, 0x79766572, 0x6E000000, 0x838A8367, 0x838B838F,  /* fzgx-allow: A1 retail data bytes */
    0x8343836F, 0x815B8393, 0x0, 0x4D616420, 0x576F6C66, 0x0, 0x837D8362, 0x83688345,  /* fzgx-allow: A1 retail data bytes */
    0x838B8374, 0x0, 0x53757065, 0x72205069, 0x72616E68, 0x61000000, 0x8358815B, 0x8370815B,
    0x83738389, 0x836A8341, 0x0, 0x44656174, 0x6820416E, 0x63686F72, 0x0, 0x83668358,
    0x83418393, 0x834A815B, 0x0, 0x41737472, 0x6F20526F, 0x62696E00, 0x83418358, 0x8367838D,
    0x838D8372, 0x83930000, 0x42696720, 0x46616E67, 0x0, 0x83728362, 0x834F8374, 0x83408393,
    0x834F0000, 0x536F6E69, 0x63205068, 0x616E746F, 0x6D000000, 0x835C836A, 0x8362834E, 0x83748340,
    0x83938367, 0x83800000, 0x47726565, 0x6E205061, 0x6E746865, 0x72000000, 0x834F838A, 0x815B8393,  /* fzgx-allow: A1 retail data bytes */
    0x83708393, 0x8354815B, 0x0, 0x48797065, 0x72205370, 0x65656465, 0x72000000, 0x836E8343,
    0x8370815B, 0x83588373, 0x815B835F, 0x815B0000, 0x53706163, 0x6520416E, 0x676C6572, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x83588379, 0x815B8358, 0x83418393, 0x834F8389, 0x815B0000, 0x4B696E67, 0x204D6574, 0x656F7200,  /* fzgx-allow: A1 retail data bytes */
    0x834C8393, 0x834F8381, 0x83658349, 0x0, 0x51756565, 0x6E204D65, 0x74656F72, 0x0,
    0x834E8343, 0x815B8393, 0x83818365, 0x83490000, 0x5477696E, 0x204E6F72, 0x69747461, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x83638343, 0x8393836D, 0x838A8362, 0x835E0000, 0x4E696768, 0x74205468, 0x756E6465, 0x72000000,
    0x83698343, 0x83678354, 0x8393835F, 0x815B0000, 0x57696C64, 0x20426F61, 0x72000000, 0x838F8343,  /* fzgx-allow: A1 retail data bytes */
    0x838B8368, 0x837B8341, 0x0, 0x426C6F6F, 0x64204861, 0x776B0000, 0x83758389, 0x83628368,
    0x837A815B, 0x834E0000, 0x576F6E64, 0x65722057, 0x61737000, 0x838F8393, 0x835F815B, 0x838F8358,
    0x83760000, 0x4D696768, 0x74792054, 0x7970686F, 0x6F6E0000, 0x837D8343, 0x83658342, 0x815B835E,  /* fzgx-allow: A1 retail data bytes */
    0x83438374, 0x815B8393, 0x0, 0x4D696768, 0x74792048, 0x75727269, 0x63616E65, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x837D8343, 0x83658342, 0x836E838A, 0x8350815B, 0x83930000, 0x4372617A, 0x79204265, 0x61720000,
    0x834E838C, 0x83438357, 0x815B8378, 0x83410000, 0x426C6163, 0x6B204275, 0x6C6C0000, 0x83758389,  /* fzgx-allow: A1 retail data bytes */
    0x8362834E, 0x8375838B, 0x0, 0x4461726B, 0x20536368, 0x6E656964, 0x65720000, 0x835F815B,
    0x834E8356, 0x83858369, 0x8343835F, 0x815B0000, 0x46617420, 0x53686172, 0x6B000000, 0x83748340,  /* fzgx-allow: A1 retail data bytes */
    0x83628367, 0x83568383, 0x815B834E, 0x0, 0x436F736D, 0x69632044, 0x6F6C7068, 0x696E0000,  /* fzgx-allow: A1 retail data bytes */
    0x83528359, 0x837E8362, 0x834E8368, 0x838B8374, 0x83428393, 0x0, 0x50696E6B, 0x20537069,
    0x64657200, 0x83738393, 0x834E8358, 0x83708343, 0x835F815B, 0x0, 0x4D616769, 0x63205365,
    0x6167756C, 0x6C000000, 0x837D8357, 0x8362834E, 0x8356815B, 0x834B838B, 0x0, 0x53696C76,
    0x65722052, 0x61740000, 0x8356838B, 0x836F815B, 0x83898362, 0x83670000, 0x53706172, 0x6B204D6F,
    0x6F6E0000, 0x83588370, 0x815B834E, 0x8380815B, 0x83930000, 0x42756E6E, 0x7920466C, 0x61736800,  /* fzgx-allow: A1 retail data bytes */
    0x836F836A, 0x815B8374, 0x83898362, 0x83568385, 0x0, 0x47726F6F, 0x76792054, 0x61786900,  /* fzgx-allow: A1 retail data bytes */
    0x834F838B, 0x815B8372, 0x815B835E, 0x834E8356, 0x815B0000, 0x526F6C6C, 0x696E6720, 0x54757274,  /* fzgx-allow: A1 retail data bytes */
    0x6C650000, 0x838D815B, 0x838A8393, 0x834F835E, 0x815B8367, 0x838B0000, 0x5261696E, 0x626F7720,  /* fzgx-allow: A1 retail data bytes */
    0x50686F65, 0x6E697800, 0x838C8343, 0x8393837B, 0x815B8374, 0x8346836A, 0x8362834E, 0x83580000  /* fzgx-allow: A1 retail data bytes */
};
static u32 fzgx_pool_data_lbl_1_data_1F1D8_1358[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25735F73, 0x7625642E, 0x74706C00
};
static u32 fzgx_pool_data_lbl_1_data_1F1D8_1364[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25735F63, 0x7625642E, 0x74706C00
};
static u32 fzgx_pool_data_lbl_1_data_1F1D8_1370[13] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25732E74, 0x706C0000, 0x25732E67, 0x6D610000, 0x25735F63, 0x72617368, 0x2E676D61, 0x0,
    0x25735F30, 0x25642E67, 0x6D610000, 0x25732E66, 0x6D690000
};
static u32 fzgx_pool_data_lbl_1_data_2057C[16] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x76656869, 0x636C652F, 0x63617263, 0x6D6E7465, 0x782E7470, 0x6C000000, 0x696E6974, 0x2F637261,
    0x73686D64, 0x6C2E7470, 0x6C000000, 0x696E6974, 0x2F637261, 0x73686D64, 0x6C2E676D, 0x61000000
};
static u32 fzgx_pool_data_lbl_1_data_1F1D8_13E4[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x636D6E5F, 0x61000000
};
static u32 fzgx_pool_data_lbl_1_data_1F1D8_13EC[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x636D6E5F, 0x62000000
};
static u32 fzgx_pool_data_lbl_1_data_1F1D8_13F4[34] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x636D6E5F, 0x63000000, 0x76656869, 0x636C655F, 0x70617274, 0x732F0000, 0x63617263, 0x6D6E7465,
    0x782E7470, 0x6C000000, 0x76656869, 0x636C652F, 0x25735F65, 0x2E617263, 0x2E6C7A00, 0x76656869,
    0x636C652F, 0x25735F70, 0x2E617263, 0x2E6C7A00, 0x25735F30, 0x2564656D, 0x622E7470, 0x6C000000,
    0x25735F65, 0x6D622E74, 0x706C0000, 0x25735F30, 0x2564656D, 0x622E676D, 0x61000000, 0x25735F65,
    0x6D622E67, 0x6D610000
};
static u32 fzgx_pool_data_lbl_1_data_1F1D8_147C[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x2E2E2F2E, 0x2E000000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_1F1D8(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1F1D8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1F4FC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1F5A0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1F1D8_E0C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1FFF0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1F1D8_1358;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1F1D8_1364;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1F1D8_1370;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_2057C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1F1D8_13E4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1F1D8_13EC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1F1D8_13F4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1F1D8_147C;
}
#pragma section code_type ".text"


extern void fn_80006E10(char *);
extern char *fn_80083DB0(char *, const char *);
extern int sprintf(char *, const char *, ...);
extern Fn81164Model *fn_1_D3884(char *);
extern u32 fn_80077D40(Fn81164Model *);
extern u32 fn_80071470(u32, u32);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_80071718(Fn81164Model *);

static inline void fn81164Finish(Fn81164Car *car, s16 from, s16 toSlot, s16 to, char *buf) {
    Fn81164Model *model;
    u32 a;
        model = fn_1_D3884(buf);
        fn_80006E10((char *)(((u8 *)fzgx_pool_data_lbl_1_data_1F1D8_147C)));
        car->unk_3A8 = fn_80077D40(model);
        a = fn_80071470(model->unk_8, 0);
        fn_80008BA8(fn_80071470(car->unk_37C[from]->unk_8, 0), a, car->unk_3A8);
        fn_80071718(model);
        car->unk_37C[toSlot] = car->unk_37C[from];
        car->unk_37C[from] = NULL;
        car->unk_3B8 = to;
}

static inline void fn81164Core(Fn81164Car *car, s16 from, s16 to) {
    char buf[0x28];
    s32 flag;
    s16 toSlot;

    if (car->unk_390 & 0x04000000) {
        car->unk_3B8 = to;
        return;
    }
    if (from == to) {
        return;
    }
    {
        s16 fromSlot = from % 4;
        toSlot = to % 4;
        if (from / 4 != to / 4) {
            return;
        }
        from = fromSlot;
        if (car->unk_37C[from] == NULL) {
            return;
        }
        if (car->unk_37C[toSlot] == NULL) {
            return;
        }
        flag = 0;
        fn_80006E10((char *)(((u8 *)fzgx_pool_data_lbl_1_data_1F1D8_E0C)));
        if (car->unk_390 & 0x100000) {
            flag = 1;
        }
        {
        s32 kindFrom = car->unk_328;
        fn_80083DB0(buf, ((char **)(((u8 *)fzgx_pool_data_lbl_1_data_1F4FC)))[kindFrom]);
        if (flag == 1) {
            switch (kindFrom) {
            case 6:
                fn_80083DB0(buf, (char *)(((u8 *)fzgx_pool_data_lbl_1_data_1F1D8_13E4)));
                break;
            case 0:
                fn_80083DB0(buf, (char *)(((u8 *)fzgx_pool_data_lbl_1_data_1F1D8_13EC)));
                break;
            case 1:
                fn_80083DB0(buf, (char *)(((u8 *)fzgx_pool_data_lbl_1_data_1F1D8_13F4)));
                break;
            }
        }
        }
        fn_80006E10(buf);
        {
        s32 kindTo = car->unk_328;
        fn_80083DB0(buf, ((char **)(((u8 *)fzgx_pool_data_lbl_1_data_1F4FC)))[kindTo]);
        if (flag == 1) {
            switch (kindTo) {
            case 6:
                fn_80083DB0(buf, (char *)(((u8 *)fzgx_pool_data_lbl_1_data_1F1D8_13E4)));
                break;
            case 0:
                fn_80083DB0(buf, (char *)(((u8 *)fzgx_pool_data_lbl_1_data_1F1D8_13EC)));
                break;
            case 1:
                fn_80083DB0(buf, (char *)(((u8 *)fzgx_pool_data_lbl_1_data_1F1D8_13F4)));
                break;
            }
        }
        }
        if ((u8)to != 0) {
            if ((u8)to >= 4) {
                sprintf(buf, (char *)(((u8 *)fzgx_pool_data_lbl_1_data_1F1D8_1358)), buf, (u8)to - 4);
            } else {
                sprintf(buf, (char *)(((u8 *)fzgx_pool_data_lbl_1_data_1F1D8_1364)), buf);
            }
        } else {
            sprintf(buf, (char *)(((u8 *)fzgx_pool_data_lbl_1_data_1F1D8_1370)), buf);
        }
        fn81164Finish(car, from, toSlot, to, buf);
    }
}
#pragma opt_dead_assignments off
void fn_1_81164(Fn81164Car *car, s16 from, s16 to) {
    fn81164Core(car, from, to);
}
#pragma opt_dead_assignments reset

/* fzgx:end fn_1_81164 */
