#include <stdio.h>
#include "gpio.h"

void delay_some()
{
    uint32_t count = 7;
    uint32_t cycles_per_count = 18000;
    uint32_t iterations_per_count = cycles_per_count / 4;

    while (count--)
    {
        volatile uint32_t count2 = iterations_per_count;
        while (count2--)
        {
            // Busy-wait loop
        }
    }
}

int main(void)
{
    printf("This example needs 8 diodes connected to PC0-7\n");
    port_send(PC_DIR, 0x00); // set whole PC port as output

    for (uint8_t i = 0; i < 255; i++)
    {
        port_send(PC_DAT, i);
        printf("PC0-7: 0x%02X\n", port_recv(PC_DAT));
        delay_some();
    }
    // turn off all diodes
    port_send(PC_DAT, 0x00);
}
