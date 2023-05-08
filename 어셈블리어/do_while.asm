%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    mov ax, 0
    mov bx, 0
    
L1:
    add ax, bx
    inc bx
    cmp bx, 10
    jle L1

    PRINT_DEC 2, ax
    NEWLINE
    
    xor rax, rax
    ret