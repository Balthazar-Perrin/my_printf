/*
** ETNA PROJECT, 01/10/2019 by perrin_a
** Pointers ands arrays
** File description:
**      count length of of a string
*/

void my_putchar(char c);

/* function to count the characters of a string */ 
int my_strlen(const char *str)
{
    int i = 0;
    while (*str != '\0') {
        ++i;
        ++str;
    }
    return(i);
}
