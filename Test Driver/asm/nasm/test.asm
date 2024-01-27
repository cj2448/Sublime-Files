STD_OUTPUT_HANDLE   equ -11

global start
extern ExitProcess, GetStdHandle, WriteConsoleA

section .data
msg                 db "Hello World!", 13, 10, 0
msg.len             equ $ - msg

section .bss
dummy               resd 1

section .text
start:
    push    STD_OUTPUT_HANDLE
    call    GetStdHandle                    ; returns GENERIC_WRITE access if successful

    push    dword 0                         ; reserved parameter must be null
    push    dummy                           ; variable that will be updated with number of chars actually written
    push    msg.len                         ; size of buffer
    push    msg                             ; pointer to buffer of array of char
    push    eax                             ; Handle permission
    call    WriteConsoleA

    push    dword 0                         ; exit code for processes and threads
    call    ExitProcess                     ; calls system32 shell exit function
    ; xor     eax, eax                        
    ; ret                                   ; ret can alternatively end the program