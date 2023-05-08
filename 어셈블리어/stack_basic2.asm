%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    GET_DEC 2, ax
    GET_DEC 2, bx
    
    push ax
    push bx
     
    call MyCheck
    
    PRINT_DEC 2,ax
    NEWLINE
    
    pop bx
    pop ax
    
    PRINT_DEC 2,ax
    NEWLINE
    
    xor rax, rax
    ret
MyCheck:
    cmp ax, bx
    jl L_less
    add ax, bx
    jmp L_less_end
L_less:
    sub ax, bx
L_less_end:
    ret
    