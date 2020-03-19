#include <stdarg.h>


int my_printf(const char *, ...);

int main(int argc, char **argv) {
    my_printf("%c", '\n');
    return 0;
}
