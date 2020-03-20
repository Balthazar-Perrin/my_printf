int my_strlen(char *str);
void my_putchar(char c);

void my_putnbrbase(int n, int base) {
    char buff[100];
    char lettre[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    int cpt = 0;
    int tmp;
    tmp = 0;

    if(n < 0) {
        my_putchar('-');
        n = n * -1; 
    }

    while(n != 0) {
        tmp = n % base;
        buff[cpt] = lettre[tmp];
        ++cpt;
        n /= base;
    }
    
    for(cpt = cpt - 1; cpt >= 0; cpt--) {
        my_putchar(buff[cpt]);
    }
    
}
