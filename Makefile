ASM_SOURCE := $(shell find ./src/x86_64 -name *.asm) 
OBJ_SOURCE := $(patsubst src/x86_64/%.asm, build/x86_64/%.o, $(ASM_SOURCE))

$(OBJ_SOURCE): build/x86_64/%.o : src/x86_64/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst build/kernel/%.o, src/x86_64/%.asm, $@) -o $@

.PHONY: build
build: $(OBJ_SOURCE)
	mkdir -p dist/x86_64 && \
	ld -n -o dist/x86_64/lennox.bin -T targets/x86_64/linker.ld src/x86_64/boot/boot.asm $(ASM_SOURCE) && \
	cp dist/x86_64/lennox.bin targets/x86_64/boot/lennox.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/lennox.iso targets/x86_64/dist