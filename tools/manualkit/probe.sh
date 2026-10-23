#!/bin/sh
# probe.sh FILE.c [MW] [EXTRA FLAGS...]: compile a scratch C file with the REL-default flags and
# print the disassembly (function labels + instructions). For quick codegen questions.
F=$1; MW=${2:-GC/1.3.2}; shift; [ $# -gt 0 ] && shift
O=${F%.c}.o
build/tools/wibo build/compilers/$MW/mwcceppc.exe -nodefaults -proc gekko -align powerpc -enum int \
  -fp hardware -Cpp_exceptions off -O4,p -inline auto -pragma "cats off" -nosyspath -RTTI off \
  -fp_contract on -str reuse -multibyte -i include "$@" -c "$F" -o "$O" || exit 1
build/binutils/powerpc-eabi-objdump -d -r "$O" | grep -E "^[0-9a-f]+ <|^ +[0-9a-f]+:" | sed -E 's/^ +[0-9a-f]+:\t([0-9a-f]{2} ){4}\t/  /'
