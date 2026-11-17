#ifndef GAME_PAD_H
#define GAME_PAD_H

/* Pad button test: bit n of a pad button word (lbl_1_bss_9F8 / lbl_1_bss_D58 entries).
 * REVIEW NOTE (accepted for now): PAD_BIT is a reconstruction. Retail tests a pad bit with
 * lhz + rlwinm and loads the word again in each statement; only the CodeWarrior __rlwinm
 * intrinsic reproduces that (a plain shift keeps the word in a register, a volatile view
 * reloads inside one condition, a 1-bit bit-field reads it with lbz). No retail name proves it. */
#define PAD_BIT(word, n) __rlwinm((word), (32 - (n)) & 31, 31, 31)

#endif
