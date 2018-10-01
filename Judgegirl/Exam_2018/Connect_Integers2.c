//Connect_Integers2.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int head(char *s){
    return s[0] - '0';
}
 
int tail(int num){
    return num%10;
}
 
int len(char *s){
    return strlen(s);
}
 
int main(){
    int pre = -1, max = -1, counter = 0;
    char str[12];
    while(scanf("%s",str) != EOF){
        int h = head(str), t = tail(atoi(str)), l = len(str);
        //printf("h = %d, t = %d, l = %d\n", h, t, l);
        if(max < l) max = l;
        if(pre == h){
            counter += l;
            if(counter > max) max = counter;
            pre = t;
        }
        else{
            counter = l;
            pre = t;
        }
    }
    printf("%d\n", max);
    return 0;
}