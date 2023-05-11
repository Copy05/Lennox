#!/bin/bash

C_FILES=$(find . -name *.c)
H_FILES=$(find . -name *.h)
ASM_FILES=$(find . -name *.S)

echo "$C_FILES"
echo "$H_FILES"
echo "$ASM_FILES"

mkdir build
mkdir ./build/obj
mkdir ./build/boot

nasm -f elf32 ./src/boot/boot.S -o ./build/boot/boot.o
gcc -m32 -c ./src/main.c -o ./build/obj/main.o
gcc -m32 -c ./src/terminal/terminal.c -o ./build/obj/terminal.o
gcc -m32 -c ./src/drivers/keyboard/keyboard.c -o ./build/obj/keyboard.o
gcc -m32 -c ./src/std/stdlib.c -o ./build/obj/stdlib.o
ld -m elf_i386 -T ./src/boot/linker.ld ./build/boot/boot.o ./build/obj/terminal.o ./build/obj/main.o ./build/obj/keyboard.o ./build/obj/stdlib.o -o Lennox.bin -nostdlib

mkdir -p ./iso/boot/grub
cp Lennox.bin iso/boot
cp src/grub.cfg iso/boot/grub
grub-mkrescue -o Lennox.iso iso/
rm -rf build
rm -rf iso
rm Lennox.bin
