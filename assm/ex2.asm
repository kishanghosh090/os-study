global _start

section .data
    msg db "Hello, World!", 0x0a
    len1 equ $ - msg

section .text
_start:
    mov eax, 4      ; sys_write system call
    mov ebx, 1      ; stdout file descriptor
    mov ecx, msg    ; message bytes to write
    mov edx, len1    ; number of bytes to write
    int 0x80        ; perform system call

    mov eax, 1      ; sys_exit system call
    mov ebx, 0      ; exit code
    int 0x80        ; perform system call