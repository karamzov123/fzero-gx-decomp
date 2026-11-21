#include "types.h"


/* --- dol/fn_8004D18C.c --- */
extern u32 fn_800474E4(u32);
extern u32 ADXT_Stop(u32);
extern u32 lbl_80091068[];
extern void fn_80083DB0(void *, void *);

void fn_8004D18C(u32 arg0, u32 arg1);

/* --- dol/fn_8004D220.c --- */
typedef s32 (*Fn1)(u32, s32);
typedef s32 (*Fn2)(u32, s32, u32, void *);
typedef s32 (*Fn3)(u32, s32, void *);

struct Vec {
	u32 *a;
	u32 b;
};

extern u32 lbl_8017E5A8[];
extern u32 lbl_80091098[];
extern u32 lbl_80178CB8[];

extern s32 fn_800421C0(u32);
extern s32 fn_80041660(u32);
extern s32 fn_80041618(u32);
extern void fn_8004EEC4(u32, u32);
extern s32 fn_8004EE84(u32);
extern s32 fn_8004EE64(u32);
extern void fn_8004EEA4(u32, u32);
extern void fn_8004D528(u32);
extern s32 fn_8004C05C(u32);
extern void *memset(void *, int, u32);
extern s32 fn_8004C658(char *);
extern s32 fn_8004AEE4(u32);
extern void fn_8004216C(u32);
extern s32 fn_80056C20(u32);

void fn_8004D220(u32 arg0) {
	struct Vec loc;
	u32 g = (u32)&lbl_8017E5A8;

	if (arg0 == 0) {
		fn_800474E4((u32)lbl_80091098);
	} else {
		if (*(s8 *)(arg0 + 1) == 3) {
			if (fn_800421C0(*(u32 *)(arg0 + 4)) == 3) {
				s32 n = fn_80041660(*(u32 *)(arg0 + 4));
				s32 i;
				u32 q = arg0;

				*(u32 *)(g + 8) = n;
				for (i = 0; i < n; i++) {
					u32 v = *(u32 *)(q + 0x18);
					s32 res = ((Fn1)*(u32 *)((u8 *)*(u32 *)v + 0x24))(v, 1);

					*(u32 *)(g + 4) = res;
					if (res >= 0x40) {
						break;
					}
					q += 4;
				}
				if (i == n) {
					fn_8004EEC4(*(u32 *)(arg0 + 0xc), 0);
					*(u8 *)((u8 *)arg0 + 1) = 4;
				}
			}
		} else if (*(s8 *)(arg0 + 1) == 1) {
			fn_8004D528(arg0);
		} else if (*(s8 *)(arg0 + 1) == 2) {
			u32 b;
			u32 a = *(u32 *)(arg0 + 0xc);
			s32 n1;
			s32 n2;

			b = *(u32 *)(arg0 + 4);
			n1 = fn_8004EE84(a);
			n2 = fn_8004EE64(a);
			if (n1 < (*(s32 *)(arg0 + 0x48) << 1) &&
			    n2 > fn_80041618(b) &&
			    fn_800421C0(*(u32 *)(arg0 + 4)) != 3) {
				goto L390; /* Keep the verified branch to L390. */
			}
			if (*(s8 *)(arg0 + 0x70) == 0) {
				if (*(s8 *)(arg0 + 0x72) == 0) {
					fn_8004EEA4(a, 1);
					*(u32 *)((u8 *)arg0 + 0x9c) = 0;
					*(u32 *)((u8 *)arg0 + 0xa0) = lbl_80178CB8[0];
				}
				*(u8 *)((u8 *)arg0 + 1) = 3;
			}
			*(u8 *)((u8 *)arg0 + 0x71) = 1;
		L390:
			if (fn_800421C0(*(u32 *)(arg0 + 4)) == 3) {
				s32 cnt = fn_8004C05C(arg0);
				s32 i;
				u32 v;
				u32 sz;
				u32 q;

				q = arg0;
				i = 0;
				sz = (*(s32 *)(arg0 + 0x48) * cnt) << 1;
				while (i < cnt) {
					v = *(u32 *)(q + 0x18);
					((Fn2)*(u32 *)((u8 *)*(u32 *)v + 0x18))(v, 0, sz, &loc);
					memset(loc.a, 0, loc.b);
					((Fn3)*(u32 *)((u8 *)*(u32 *)v + 0x20))(v, 1, &loc);
					q += 4;
					i++;
				}
			}
		} else if (*(s8 *)(arg0 + 1) == 4) {
			*(u32 *)(g + 0) = fn_8004EE84(*(u32 *)((u8 *)arg0 + 0xc));
			if (fn_8004EE84(*(u32 *)(arg0 + 0xc)) <= 0) {
				fn_8004EEA4(*(u32 *)(arg0 + 0xc), 0);
				*(u8 *)((u8 *)arg0 + 1) = 5;
			}
		}

		if (*(u32 *)(arg0 + 8) != 0) {
			if (fn_8004C658((char *)arg0) != 0) {
				switch (*(s8 *)(arg0 + 2)) {
				case 0:
				case 1:
					if (fn_8004AEE4(*(u32 *)(arg0 + 8)) == 3) {
						fn_8004216C(*(u32 *)(arg0 + 4));
					}
					break;
				case 2:
					fn_8004216C(*(u32 *)(arg0 + 4));
					break;
				case 3:
					break;
				}
			}
		}
		if (*(u32 *)(arg0 + 8) != 0) {
			if (fn_8004AEE4(*(u32 *)(arg0 + 8)) == 4) {
				*(s16 *)((u8 *)arg0 + 0x60) = -1;
				*(u8 *)((u8 *)arg0 + 1) = 6;
			}
		}
		if (*(u32 *)(arg0 + 0x94) != 0) {
			if (fn_80056C20(*(u32 *)(arg0 + 0x94)) == 3) {
				*(s16 *)((u8 *)arg0 + 0x60) = -1;
				*(u8 *)((u8 *)arg0 + 1) = 6;
			}
		}
	}
}
