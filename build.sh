#!/bin/bash

mkdir build
mkdir ./build/obj
mkdir ./build/boot

nasm -f elf32 ./src/boot/boot.S -o ./build/boot/boot.o
gcc -m32 -Iinclude -c ./src/main.c -o ./build/obj/main.o
gcc -m32 -Iinclude -c ./lib/terminal.c -o ./build/obj/terminal.o
gcc -m32 -Iinclude -c ./drivers/keyboard/keyboard.c -o ./build/obj/keyboard.o
gcc -m32 -Iinclude -c ./lib/stdlib.c -o ./build/obj/stdlib.o
gcc -m32 -Iinclude -c ./lib/color.c -o ./build/obj/color.o
gcc -m32 -Iinclude -c ./lib/interrupt.c -o ./build/obj/interrupt.o
gcc -m32 -Iinclude -c ./lib/asm.c -o ./build/obj/asm.o
ld -m elf_i386 -T ./src/boot/linker.ld ./build/boot/boot.o ./build/obj/terminal.o ./build/obj/main.o ./build/obj/keyboard.o ./build/obj/stdlib.o ./build/obj/color.o ./build/obj/interrupt.o ./build/obj/asm.o -o Lennox.bin -nostdlib

mkdir -p ./iso/boot/grub
cp Lennox.bin iso/boot
cp src/grub.cfg iso/boot/grub
grub-mkrescue -o Lennox.iso iso/
rm -rf build
rm -rf iso
rm Lennox.bin

# Start the OS
qemu-system-x86_64 -cdrom Lennox.iso
