#include <stdio.h>
#include <stdint.h>

#include "math.h"

int main(void) {
    int16_t sum = add(255, 255);
    printf("Sum: %d\n", sum);

    int8_t diff = sub(255, 250);
    printf("Diff: %d\n", diff);

    diff = sub(250, 255);
    printf("Diff: %d\n", diff);
}