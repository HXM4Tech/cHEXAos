section .multiboot_header

header_start:
    ; multiboot2 magic number
    dd 0xe85250d6

    ; architecture
    dd 0 ; i386 - protected mode

    ; header lenght
    dd header_end - header_start

    ; checksum
    dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

    ; end tag
    dw 0
    dw 0
    dd 8
header_end: