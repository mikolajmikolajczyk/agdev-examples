assume adl=1

section .text

public _timer_interrupt_handler

_timer_interrupt_handler:
    di
    push af
    push bc
    push de
    push hl
    call _timer_interrupt
    pop hl
    pop de
    pop bc
    pop af
    ei
    reti.l

extern _timer_interrupt