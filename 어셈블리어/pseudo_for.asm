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
    add ax, bx
    inc bx
    loop L1
    
    PRINT_DEC 2, ax
    NEWLINE
    
    xor rax, rax
    ret