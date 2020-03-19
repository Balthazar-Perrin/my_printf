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
    while (*string != '\0' ) {
        my_putchar(*string);
        ++string;
    }
}

int my_printf(const char *str, ...) {
   
    int i;
    int int_char;
    char *arg_str;
    va_list ap;
    va_start(ap, str);
    
    for (i = 0; str[i] != '\0'; i++) {
        while (str[i]!= '%') {
            my_putchar(str[i]);
            i++;
        }
        
        switch(str[i]) {
        case 's':
            arg_str = va_arg(ap, char *);
            my_putstr(arg_str);
            break;
            
        case 'c':
            int_char = va_arg(ap, int);
            my_putchar(int_char);
            break;
            
        case 'i':
            int_char = va_arg(ap, int);
            my_putnbr(int_char);
            break;
            
        case 'd':
            int_char = va_arg(ap, int);
            my_putnbr(int_char);
            break;
            
        }
    }
    
    va_end(ap);       
    return 0;
}
