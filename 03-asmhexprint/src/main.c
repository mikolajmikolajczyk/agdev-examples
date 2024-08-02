#include <stdio.h>

extern void hexprint(void);

int main(void) {
    printf("Example of printing hex value in assembly\n");
    hexprint();

    printf("Please note that printf is perfectly capable of printing hex values!\n");
    printf("This example is just an example of how to print hex values in assembly!\n");
    printf("Useful for debugging assembly code!\n");

    printf("Hex value using printf: 0x%02X\n", 0xBC);
}