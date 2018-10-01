//Divide_a_number.c
#include <stdio.h>
 
int main() {
    int z = 0, n = 0;
    char c;
    int k = getchar() - '0';
    getchar();
    while ((c = getchar())!= EOF) {
        if (c == '\n') continue;
        n = n * 10 + (c - '0');
        if (z || n/k != 0) {
            putchar('0' + n/k);
            puts("");
            z = 1;
        }
        n %= k;
    }
    if(z == 0) puts("0");
}