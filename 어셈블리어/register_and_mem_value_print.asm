%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    mov ax, [a]
    mov [b], ax
    
    PRINT_HEX 2, ax
    NEWLINE
    
    PRINT_HEX 2, a
    NEWLINE
    
    PRINT_HEX 2, b
    NEWLINE
    
    PRINT_DEC 2, ax
    
    xor rax, rax
    ret
section .data
    a db 0x12
section .bss
    b resw 1