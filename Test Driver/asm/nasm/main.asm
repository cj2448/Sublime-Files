section     .text

global      start
extern      ExitProcess

start:
    push    ecx
    push    edx
    push    dword [term]
    push    dword size
    push    array
    call    arraySearch
    add     esp, 12
    pop     edx
    pop     ecx

    push    dword 0
    call    ExitProcess

arraySearch:
    push    ebp
    mov     ebp, esp

    push    dword 0                         ; subscript = 0

    push    ebx
    push    esi
    push    edi

    mov     esi, [ebp + 8]                  ; address of the array
    mov     ebx, [ebp + 12]                 ; represents size
    mov     ecx, [ebp + 12]                 ; represents loop counter
    mov     edi, [ebp + 16]                 ; term to be found
    shr     ecx, 2                          ; convert size of array to number of elements
    mov     eax, -1                         ; default value is -1

.while:
    cmp     dword [ebp - 4], ebx            ; while count < size
    jge     .wend
    cmp     dword [esi], edi
    je      .found                          ; if array[count] = term
    add     esi, 4                          ; move to the next element in the array
    inc     dword [ebp - 4]                 ; subscript += 1
    loop    .while

.found:
    mov     eax, [ebp - 4]

.wend:
    pop     edi
    pop     esi
    pop     ebx
    mov     esp, ebp
    pop     ebp
    ret



section     .bss

section     .data
    array   dd  20, 8, 12, 1, 7, 19, 15, 2, 6, 10
    size    equ $ - array
    term    dd 15