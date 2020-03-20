#include <unistd.h>

void my_putchar(char c);

void my_putnbr(int n)
{
    int dernier;
    if (n < 0) {
        n = n * (-1);
        my_putchar('-');
    }
    if (n >= 0 && n <= 9) {
        my_putchar(n + '0');
    }
    if (n >= 10) {
        dernier = (n % 10);
        my_putnbr(n / 10);
        my_putchar(dernier + '0');
    }
}
