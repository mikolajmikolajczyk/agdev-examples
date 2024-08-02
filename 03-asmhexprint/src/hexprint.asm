assume adl=1

section .text

private _convert_to_hex_string
public _hexprint

_hexprint:
    ; converts 0xBC into hex into 2 characters
    ; and stores them into buffer
    ld a, 0xBC
    call _convert_to_hex_string

    ; pushes registers to stack and calls MOS print function
    ; on buffer
    push hl
    push bc
    push af
    ld hl, buffer
    ld bc, 0
    ld a, 0
    rst.lis 18h
    pop af
    pop bc
    pop hl
    ret

; Subroutine to convert the value in register A to a hexadecimal string
_convert_to_hex_string:
    push af              ; Preserve the current value of A
    push bc              ; Preserve BC

    ld b, a              ; Copy the value in A to B

    ; Convert the high nibble to a character
    ld a, b
    rlc a                ; Rotate left through carry
    rlc a                ; Rotate left through carry
    rlc a                ; Rotate left through carry
    rlc a                ; Rotate left through carry
    and a, 0x0F          ; Mask out all but the low nibble
    call nibble_to_hex   ; Convert the high nibble
    ld (buffer+2), a     ; Store the resulting character in the buffer

    ; Convert the low nibble to a character
    ld a, b              ; Load the original value back into A
    and a, 0x0F          ; Mask out the high nibble
    call nibble_to_hex   ; Convert the low nibble
    ld (buffer+3), a     ; Store the resulting character in the buffer

    pop bc               ; Restore BC
    pop af               ; Restore AF
    ret

; Subroutine to convert a single nibble (0-15) in A to its hexadecimal character
nibble_to_hex:
    add a, 0x30          ; Convert 0-9 to '0'-'9'
    cp a, 0x3A           ; Compare with ':'
    jr c, .done          ; If less, we're done
    add a, 0x07          ; Convert A-F to 'A'-'F'
.done:
    ret



buffer db '0x00', 13,10,0  ; Buffer to store the hexadecimal string