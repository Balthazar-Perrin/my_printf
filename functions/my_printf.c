#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int my_printf(const char *, ...);
void my_putchar(char c);
void my_putstr(const char *string);
void my_putnbr(int n);

void my_putchar(char c) {
    write(1, &c, 1);
}

void my_putnbr(int n) {
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

void my_putstr(const char *string) {
    int i = 0;
    while (string[i] != '\0' ) {
        my_putchar(string[i]);
        ++i;
    }
}

int my_strlen(const char *str)
{
    int i = 0;
    while (*str != '\0') {
        ++i;
        ++str;
    }
    return(i);
}

int my_printf(const char *str, ...) {
   
    int i = 0;
    va_list ap;
    va_start(ap, str);
    
    while (str[i]) {
        if (str[i] == '%') {
            switch(str[i + 1]) {
            case 's':
                my_putstr(va_arg(ap, char*));
                break;
                
            case 'c':
                my_putchar(va_arg(ap, int));
                break;
                
            case 'i':
                my_putnbr(va_arg(ap, int));
                break;
                
            case 'd':
                my_putnbr(va_arg(ap, int));
                break;
                
            case '%':
                my_putchar('%');
                break;
            }
            ++i;
        }
        else {
            my_putchar(str[i]);
        }
        ++i;
    }
    va_end(ap);      
    return 0;
}
