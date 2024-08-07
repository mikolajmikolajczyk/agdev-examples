assume adl=1

section .text

public _port_send
public _port_recv

; Function: _port_send
; Description: Sends a byte of data to a specified port.
; Input: (ix+6) -> port number (8-bit)
;        (ix+9) -> data byte to be sent
_port_send:
    push ix            ; Save IX register
    ld ix, 0           ; Clear IX
    add ix, sp         ; Set IX to point to the stack frame
    push bc            ; Save BC register
    ld bc, 0           ; Clear BC
    ld c, (ix+6)       ; Load port number into C
    ld a, (ix+9)       ; Load data byte into A
    out (c), a        ; Output data byte to port
    pop bc             ; Restore BC register
    pop ix             ; Restore IX register
    ret                ; Return from function

; Function: _port_recv
; Description: Receives a byte of data from a specified port.
; Input: (ix+6) -> port number (8-bit)
; Output: A register -> received data byte
_port_recv:
    push ix            ; Save IX register
    ld ix, 0           ; Clear IX
    add ix, sp         ; Set IX to point to the stack frame
    push bc            ; Save BC register
    ld bc, 0           ; Clear BC
    ld c, (ix+6)       ; Load port number into C
    in a, (c)         ; Input data byte from port (this will be return value)
    pop bc             ; Restore BC register
    pop ix             ; Restore IX register
    ret                ; Return from function