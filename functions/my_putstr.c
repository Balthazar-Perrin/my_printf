/*
** ETNA PROJECT, 01/10/2019 by perrin_a
** Pointers and Arrays
** File description:
**      display the characters of a string
*/

void my_putchar(char c);

/* Function to display the characters of a string */
void my_putstr(const char *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        ++str;
    }
}
