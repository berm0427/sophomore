%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    mov ax, 0
    mov bx, 1
    mov cx, 10
    
L1:
    cmp cx, 0
    jle L_o
    add ax, bx
    inc bx
    dec cx
    jmp L1
L_o:
    PRINT_DEC 2, ax
    NEWLINE
    
    xor rax, rax
    ret