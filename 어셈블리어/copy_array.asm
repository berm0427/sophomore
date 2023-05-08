%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    mov eax, my1
    mov ebx, you1
    
    mov edx, 0 
    mov ecx, 3
L1:
    cmp ecx, 0
    jle exit
    mov eax, [my1+edx*2]
    mov [you1+ edx*2], eax
    inc edx
    dec ecx
    jmp L1
exit:
    mov edx, 0
L2:
    PRINT_HEX 2, my1+edx*2
    NEWLINE
    inc edx
    cmp edx, 3
    jl L2    
    
    xor rax, rax
    ret
section .data
   my1 dw 0x1234,0x4567,10

section .bss
    you1 resw 3 