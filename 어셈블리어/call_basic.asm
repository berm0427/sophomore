%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    mov ax, 10
    call MyShow
    
    xor rax, rax
    ret
MyShow:
    PRINT_STRING msg1
    NEWLINE
    ret
section .data
    msg1 db 'haha', 0x00