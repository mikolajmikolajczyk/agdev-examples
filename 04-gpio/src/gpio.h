#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define PB_DAT 0x009A
#define PB_DIR 0x009B
#define PC_DAT 0x009E
#define PC_DIR 0x009F
#define PD_DAT 0x00A2
#define PD_DIR 0x00A3

extern void port_send(uint8_t port, uint8_t value);
extern uint8_t port_recv(uint8_t port);
#endif