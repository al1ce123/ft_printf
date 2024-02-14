#include "inc/ft_printf.h"

int main() {
    int n = 175943;

    printf("%#X\n", n);
    ft_printf("%#X\n", n);

    return 0;
}

// c s p d i u x X %
// - 0 . # ' ' +