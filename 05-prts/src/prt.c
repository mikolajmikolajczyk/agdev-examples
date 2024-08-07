#include "prt.h"
#include "gpio.h"

#include "stdio.h"

uint16_t prt_init(uint8_t timer_ctl_addr, uint16_t initial_reload_value, Prt_TMRx_CTL_t settings)
{
    // Disable timer and clear all other flags
    port_send(timer_ctl_addr, 0x00);
    // Set reload value
    // Set low byte of reload value
    port_send(timer_ctl_addr + 1, initial_reload_value);
    // Set high byte of reload value
    port_send(timer_ctl_addr + 2, initial_reload_value >> 8);
    // Set settings
    port_send(timer_ctl_addr, *(uint8_t *)&settings);

    return initial_reload_value;
}

void prt_set_enable(uint8_t timer_ctl_addr, bool enable)
{
    uint8_t settings = port_recv(timer_ctl_addr);
    settings &= 0xFC;         // Clear PRT_EN bit and RST_EN bit
    settings |= (enable | 2); // Set RST_EN bit always and PRT_EN bit if enable is true
    printf("Settings: 0x%02X\n", settings);
    port_send(timer_ctl_addr, settings);
}
uint16_t prt_current_reload_value(uint8_t timer_ctl_addr)
{
    uint8_t l = port_recv(timer_ctl_addr + 1);
    uint8_t h = port_recv(timer_ctl_addr + 2);
    return (h << 8) | l;
}
bool prt_is_enabled(uint8_t timer_ctl_addr)
{
    uint8_t settings = port_recv(timer_ctl_addr);
    settings &= 0x01; // Check PRT_EN bit
    if (settings)
        return true;
    return false;
}