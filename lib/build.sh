clang-18 -S -emit-llvm --target=riscv32-unknown-elf -O2 -fno-builtin-printf -fno-builtin-memcpy builtin.c -o builtin_intermediate.ll
sed 's/ptr_/ptr./g;s/builtin_/builtin./g' builtin_intermediate.ll > builtin.ll