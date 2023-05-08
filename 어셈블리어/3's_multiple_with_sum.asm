%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    PRINT_STRING msg_input
    GET_DEC 2, data_max
    NEWLINE
    
    mov eax, 0 ; for easy debugging
    ;check 3's multiple
    mov [data_size], word 0
    mov edx, 1 ;index: edx ~ 100

L1: ; AX / bl = AH (remainder)
    mov bl, 3
    mov ax ,dx
    div bl
    cmp ah, 0
    jnz L_next
    mov eax, 0
    mov ax, [data_size]
    mov [data + eax*2], dx
    inc eax
    mov [data_size], ax
L_next:
    inc edx
    cmp dx, [data_max]
    jle L1
    
    ;print number
    PRINT_STRING msg_count
    PRINT_DEC 2, [data_size]
    NEWLINE
    mov eax, 0
L_print:
    PRINT_DEC 2, [data+eax*2]
    NEWLINE
    inc eax
    cmp ax, word [data_size]
    jl L_print 
    
    ; calculate the sum of multiples of 3
    mov eax, 0
    mov ebx, 0
    mov cx, [data_size]
L_sum:
    cmp cx, 0
    jle L_exit
    add ebx, [data+eax*2]
    inc eax
    dec cx
    jmp L_sum
L_exit:
    ; print the total
    mov [total], ebx
    NEWLINE
    PRINT_STRING msg_total
    PRINT_DEC 2, total
    NEWLINE

    mov [total], word 0
    mov eax, 0
    mov edx, 0
    xor rax, rax
    ret
section .data
   msg_input db '# input max number:',0x00
   msg_count db '# number:',0x00
   msg_total db 'total:', 0x00
section .bss
    data_max resw 1
    data_size resw 1
    data resw 100
    total resw 1
