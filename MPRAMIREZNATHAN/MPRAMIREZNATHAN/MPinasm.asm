; Ramirez, Benmar | Andres, Nathan | XX22

section .data
SDot   dq 12.0  ; Declare a double-precision floating-point variable SDot and initialize it to 12.0

section .text
bits 64         
default rel     
global getDPx64 ; Declare the function getDPx64 as global so it can be called from other files

getDPx64:       
    push rsi    ; Save the value of rsi on the stack
    push rdi    ; Save the value of rdi on the stack

    mov rsi, r8 ; Move the value of r8 to rsi
    mov rdi, r9 ; Move the value of r9 to rdi
   
    xorpd xmm0, xmm0 ; Set xmm0 to zero

dp_loop:        
    movsd xmm1, [rsi] ; Load a double-precision floating-point value from the memory location pointed by rsi to xmm1
    mulsd xmm1, [rdi] ; Multiply the value in xmm1 with the value at the memory location pointed by rdi
    addsd xmm0, xmm1  ; Add the value in xmm1 to xmm0
    add rsi, 8        ; Increment rsi by 8 to point to the next element in the array
    add rdi, 8        ; Increment rdi by 8 to point to the next element in the array
    dec rcx           ; Decrement rcx
    jnz dp_loop       ; Jump if not zero to the start of dp_loop

    movsd [rdx], xmm0 ; Store the result in xmm0 to the memory location pointed by rdx

    pop rdi           ; Restore the original value of rdi from the stack
    pop rsi           ; Restore the original value of rsi from the stack
    ret               
