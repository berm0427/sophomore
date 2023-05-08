%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    mov al, [a]
    PRINT_HEX 1, al
    NEWLINE
    
    mov eax, a
    PRINT_HEX 1, eax
    NEWLINE
    
    mov [a], byte 0x34
    PRINT_HEX 1, a
    NEWLINE
    
    xor rax, rax
    ret
section .data
    a db 0x1