//Hanoi2.c
#include <stdio.h>

void hanoi(int n, int src, int buf, int des) {
    if(n == 1) {
        printf("Move sheet from %d to %d\n", src, des);
    }
    else {
        hanoi(n-1, src, des, buf);
        hanoi(1, src, buf, des);
        hanoi(n-1, buf, src, des);
    }
}

int main() {
    int n;
    printf("請輸入盤數：");
    scanf("%d", &n);
    hanoi(n,1,2,3);
    return 0;
} 