// MSL double->float wrappers (truncf-style thunks into printf.c math
// helpers), 0x80088600-0x80088648.

#pragma push
#pragma force_active on

extern double atan(double);
extern double fn_80087E80(double);

// provenance: original
// harvested 2026-08-26 from hard's logged 100% attempt; spliced into the current head
float fn_80088600(double d){ return (float)atan(d); }

// provenance: original
// harvested 2026-08-26 from hard's logged 100% attempt; spliced into the current head
float tan(double d){ return (float)fn_80087E80(d); }

#pragma pop
