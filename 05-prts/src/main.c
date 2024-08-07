#include <stdio.h>
#include "gpio.h"

#include <agon/vdp_vdu.h>

#include "prt.h"

int main(void)
{
    printf("This example shows how to use programmable reload timers\n");
    printf("Timer will be set to count down from 0xFFFF to 0x0000\n");
    printf("Timer will be set to single mode and clock divider set to 256\n");
    printf("When timer reaches 0 - then it will be disabled and program will finish\n");

    Prt_TMRx_CTL_t settings = {0};
    PRT_SET_SINGLE_MODE(settings);
    PRT_SET_CLK_DIV(settings, PRT_CLK_DIV_256);

    prt_init(PRT_TIMER_CTL_0, 0xFFFF, settings);

    prt_set_enable(PRT_TIMER_CTL_0, true);

    while (prt_is_enabled(PRT_TIMER_CTL_0))
    {
        uint16_t current_reload_value = prt_current_reload_value(PRT_TIMER_CTL_0);
        printf("Reload value: 0x%04X\n", current_reload_value);
        vdp_cursor_up();
    }
    printf("\n");
}
