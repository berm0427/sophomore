%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    GET_DEC 2, [a]
    GET_DEC 2, [b]
  
    push word [a] ;para1
    push word [b] ;para2
    
    call MyAdd
    mov [sum_plu], ax ;return
    
    call MySub
    mov [sum_min], ax ;return
    
    call MyMul
    mov [sum_mul], ax ;return
    
    call MyDiv
    mov [sum_div], al ;return

    add rsp, 4
    PRINT_DEC 2,sum_plu
    NEWLINE
    PRINT_DEC 2,sum_min
    NEWLINE
    PRINT_DEC 2,sum_mul
    NEWLINE
    PRINT_DEC 2,sum_div
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
MySub:
    push rbp
    mov rbp, rsp
    mov ax, [rbp+8+8+2] 
    mov bx, [rbp+8+8] 
    cmp ax, bx
    jl sub_l
    jg sub_L
sub_l:
    mov ax, [rbp+8+8]
    mov bx, [rbp+8+8+2]
    jmp calc
sub_L:
    mov ax, [rbp+8+8+2]
    mov bx, [rbp+8+8]
    jmp calc
calc:
    sub ax, bx
end:
    pop rbp
    ret
MyMul:
    push rbp
    mov rbp, rsp
    mov al, [rbp+8+8]
    mov bl, [rbp+8+8+2]
    mul bx
    pop rbp
    ret 
MyDiv:
    push rbp
    mov rbp, rsp
    mov ax, [rbp+8+8+2]
    mov bl, [rbp+8+8]
    div bx
    pop rbp
    ret
section .bss
    a resw 1
    b resw 1
    sum_plu resw 1
    sum_min resw 1
    sum_mul resw 1
    sum_div resw 1
