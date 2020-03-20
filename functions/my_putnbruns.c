#include <unistd.h>

void my_putchar(char c);

void my_putnbruns(unsigned int n)
{
    unsigned int dernier;
    if (n <= 9) {
        my_putchar(n + '0');
    }
    if (n >= 10) {
        dernier = (n % 10);
        my_putnbruns(n / 10);
        my_putchar(dernier + '0');
    }
}
