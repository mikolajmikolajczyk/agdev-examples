#include <stdio.h>
#include <agon/vdp_vdu.h>
#include <mos_api.h>
#include "../../lib/prt.h"
#include "interrupts.h"

#define PRT_TIMER PRT_TIMER_CTL_2
// 0x0E is the interrupt vector for timer 2 according to page 45 of ez80 product spec
// https://www.zilog.com/docs/ez80acclaim/PS0153.pdf
#define PRT_INTERRUPT 0x0E

static volatile uint16_t count = 0;

void timer_interrupt(void)
{
    prt_is_enabled(PRT_TIMER); //
    printf("Timer interrupt!\n");
    printf("Count: %d\n", count);
    count++;
}

int main(void)
{
    printf("This example shows how to use programmable reload timers\n");
    printf("to generate interrupts\n");
    printf("Timer will be disabled after 10 interrupts and program will finish\n");

    mos_setintvector(PRT_INTERRUPT, timer_interrupt_handler);

    Prt_TMRx_CTL_t settings = {0};
    PRT_SET_CONTINUOUS_MODE(settings);
    PRT_SET_CLK_DIV(settings, PRT_CLK_DIV_256);
    PRT_ENABLE_IRQ_EN(settings);

    printf("Settings: 0x%02X\n", *(uint8_t *)&settings);

    prt_init(PRT_TIMER, 0x0000, settings);

    prt_set_enable(PRT_TIMER, true);

    for (;;)
    {
        // count is set from interrupt routine
        if (count >= 10)
        {
            break;
        }
    }
    prt_set_enable(PRT_TIMER, false);
}