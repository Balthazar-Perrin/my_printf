#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <../include/my.h>


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

            case 'o':
                my_putnbrbase(va_arg(ap, int), 8);
                break;

            case 'x':
                my_putnbrbaselow(va_arg(ap, int), 16);
                break;
                
            case 'X':
                my_putnbrbase(va_arg(ap, int), 16);
                break;
                
            case 'u':
                my_putnbruns(va_arg(ap, unsigned int));
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
