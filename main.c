#include <stdarg.h>


int my_printf(const char *, ...);

int main(int argc, char **argv) {
    argc++;
    argv++;
    my_printf("oui");
    return 0;
}
