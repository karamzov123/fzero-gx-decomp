#ifndef FZERO_DOLPHIN_ASSERT_H
#define FZERO_DOLPHIN_ASSERT_H

/*
 * Retail GFZE01 is an NDEBUG build: no reference body's ASSERTLINE survives
 * into the shipped code (every adapted body that kept one produced a stray
 * `bl ASSERTLINE`). Reference bodies are spliced verbatim, so define the
 * macro away rather than editing the asserts out of each candidate.
 */
#ifdef NDEBUG
#define ASSERTLINE(line, cond) ((void)0)
#define ASSERTMSGLINE(line, cond, msg) ((void)0)
#else
#error "GFZE01 is built with NDEBUG; no assert implementation is available."
#endif

#endif
