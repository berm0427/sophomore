%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    mov ax, 1
    mov bx, 3
    sub ax, bx
    PRINT_DEC 2, ax
    NEWLINE

    mov [a], word 7
    sub ax, [a]
    PRINT_DEC 2, ax
    NEWLINE
    
    mov bx, 2
    sub [a], bx
    PRINT_DEC 2, a
    NEWLINE
    
    mov [b], byte 2
    
    xor rax, rax
    ret
section .bss
    a resw 1
    b resw 1