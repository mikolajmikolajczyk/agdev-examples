#ifndef PRT_H
#define PRT_H

#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"

// Define the structure for TMRx_CTL register with bit fields
typedef struct
{
    uint8_t PRT_EN : 1;   // Bit 0
    uint8_t RST_EN : 1;   // Bit 1
    uint8_t CLK_DIV : 2;  // Bits 2-3
    uint8_t PRT_MODE : 1; // Bit 4
    uint8_t : 1;          // Bit 5 (reserved)
    uint8_t IRQ_EN : 1;   // Bit 6
    uint8_t PRT_IRQ : 1;  // Bit 7
} Prt_TMRx_CTL_t;

// Macros to set individual fields
#define PRT_ENABLE_PRT_EN(settings) ((settings).PRT_EN = 1)
#define PRT_DISABLE_PRT_EN(settings) ((settings).PRT_EN = 0)
#define PRT_ENABLE_RST_EN(settings) ((settings).RST_EN = 1)
#define PRT_DISABLE_RST_EN(settings) ((settings).RST_EN = 0)
#define PRT_SET_CLK_DIV(settings, value) ((settings).CLK_DIV = (value))
#define PRT_SET_CONTINUOUS_MODE(settings) ((settings).PRT_MODE = 1)
#define PRT_SET_SINGLE_MODE(settings) ((settings).PRT_MODE = 0)
#define PRT_ENABLE_IRQ_EN(settings) ((settings).IRQ_EN = 1)
#define PRT_DISABLE_IRQ_EN(settings) ((settings).IRQ_EN = 0)
#define PRT_ENABLE_PRT_IRQ(settings) ((settings).PRT_IRQ = 1)
#define PRT_DISABLE_PRT_IRQ(settings) ((settings).PRT_IRQ = 0)

// CLK_DIV values
#define PRT_CLK_DIV_4   0x00  // 00
#define PRT_CLK_DIV_16  0x01  // 01
#define PRT_CLK_DIV_64  0x02  // 10
#define PRT_CLK_DIV_256 0x03  // 11

// TMRx_CTL registers
#define PRT_TIMER_CTL_0 0x80
#define PRT_TIMER_CTL_1 0x83
#define PRT_TIMER_CTL_2 0x86
#define PRT_TIMER_CTL_3 0x89
#define PRT_TIMER_CTL_4 0x8C
#define PRT_TIMER_CTL_5 0x8F

uint16_t prt_init(uint8_t timer_number, uint16_t initial_reload_value, Prt_TMRx_CTL_t settings);
void prt_set_enable(uint8_t timer_number, bool enable);
uint16_t prt_current_reload_value(uint8_t timer_number);
bool prt_is_enabled(uint8_t timer_number);

#endif
