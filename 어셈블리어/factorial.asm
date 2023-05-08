%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    GET_DEC 2,a
    push word [a]
    call Myf
    add rsp, 2
    mov [sum], ax
    
    PRINT_DEC 2, sum
    NEWLINE
    
    xor rax, rax
    ret
Myf:
    push rbp
    mov rbp, rsp
    mov bx, [rbp+8+8]
    cmp bx, 1
    je L_equal
    
    dec bx
    push bx
    call Myf
    add rsp, 2
    ;return bx*Myf(bx-1)
    mov bx, [rbp+8+8]
    mul bx
    
    ;eax = dx:ax
    shl edx, 16
    and eax, 0x0000ffff
    or eax, edx ; use ax only
    
    jmp L_equal_end
L_equal:
    mov ax,bx
L_equal_end:
    
    pop rbp
    ret
section .bss
    a resw 1
    sum resw 1