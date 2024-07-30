assume adl=1

section .text

; Public symbols for add and sub functions
public _add
public _sub

_add:
    push ix             ; Save the current value of index register IX on the stack
    ld   ix, 0          ; Initialize IX to 0
    add  ix, sp         ; Adjust IX to point to the current stack frame

    push bc             ; Save the current value of BC on the stack

    ; Load the first 8-bit integer (function argument) into HL register pair
    ld h, 0             ; Clear H register (upper byte of HL)
    ld l, (ix+6)        ; Load the first argument from stack offset 6 into L register (lower byte of HL)

    ; Load the second 8-bit integer (function argument) into BC register pair
    ld b, 0             ; Clear B register (upper byte of BC)
    ld c, (ix+9)        ; Load the second argument from stack offset 9 into C register (lower byte of BC)

    add hl, bc          ; Add BC to HL, result is stored in HL

    pop bc              ; Restore the original value of BC from the stack
    pop ix              ; Restore the original value of IX from the stack

    ret                 ; Return to caller, result is in HL

_sub:
    push ix             ; Save the current value of index register IX on the stack
    ld   ix, 0          ; Initialize IX to 0
    add  ix, sp         ; Adjust IX to point to the current stack frame

    push bc             ; Save the current value of BC on the stack

    ; Load the first 8-bit integer (function argument) into A register
    ld a, (ix+6)        ; Load the first argument from stack offset 6 into A register

    ; Load the second 8-bit integer (function argument) into B register
    ld b, (ix+9)        ; Load the second argument from stack offset 9 into B register

    sub b               ; Subtract B from A, result is stored in A

    pop bc              ; Restore the original value of BC from the stack
    pop ix              ; Restore the original value of IX from the stack

    ret                 ; Return to caller, result is in A