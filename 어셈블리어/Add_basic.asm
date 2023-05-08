%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    GET_DEC 2, [a]
    GET_DEC 2, [b]
  
    push word [a] ;para1
    push word [b] ;para2
    call MyAdd
    add rsp, 4
    mov [c], ax ;return
    
    PRINT_DEC 2,c
    NEWLINE
    
    xor rax, rax
    ret
MyAdd: ; #input para1 (2byte), para2 (2byte) #output: ax
    push rbp
    mov rbp, rsp
    mov ax, [rbp+8+8]
    mov bx, [rbp+8+8+2]
    add ax, bx
    pop rbp
    ret
    
section .bss
    a resw 1
    b resw 1
    c resw 1