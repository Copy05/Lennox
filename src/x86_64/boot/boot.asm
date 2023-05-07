; Boot.asm
; Is responsible for the booting
;
; Author: Copy05
; Copyright 2023 Copy05. All Rights Reserved

[BITS 32]                    ; Use 32-bit mode

SECTION .multiboot HEADER     
    DD 0x1BADB002             ; set magic number for bootloader
    DD 0x0                    ; set flags

SECTION .text
GLOBAL _start
EXTERN main                    ; int main()

_start:
    cli                        ; disable interrupts
    mov esp, stack_space       ; set stack pointer
    call main                  ; call main() function
    hlt                        ; halt the CPU

SECTION .bss                   ; uninitialized data
STACK_SIZE equ 16 * 1024       ; set stack size to 16KB
RESB STACK_SIZE                ; reserve space for the stack
stack_space:                   