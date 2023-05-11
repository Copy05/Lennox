ENTRY(start)
SECTIONS {
	. = 0x1000000;

	.text BLOCK(4K) : ALIGN(4K) {
		*(.multiboot)
		*(.text)
	}

	.bss : {
		*(COMMON)
		*(.bss)
	}
}
