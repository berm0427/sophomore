%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    mov ax, 7
    mov bl, 2
    div bl
    
    mov bl, ah
    
    
    PRINT_DEC 1, al
    NEWLINE
    
    PRINT_DEC 1, bl
    NEWLINE
    
    xor rax, rax
    ret