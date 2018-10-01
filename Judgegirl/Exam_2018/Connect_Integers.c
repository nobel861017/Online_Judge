//Connect_Integers.c
# include <stdio.h>
# include <limits.h>
#include <stdlib.h>
#include <string.h>
 #include <ctype.h>
int head(int num){
    if(num < 10) return num;
    else{
        int first = num;
        while(first >= 10){
            first /= 10;
        }
        return first;
    }
}
 
int tail(int num){
    return num%10;
}
 
int len(int num){
    /*int first = num, count = 0;
    while(first >= 10){
        count++;
        first /= 10;
    }
    return count+1;*/
    char s[10];
    sprintf(s,"%d", num);
    return strlen(s);
}
 
int main(){
    int n, pre = -1, max = -1, counter = 0;
    while(scanf("%d", &n) != EOF){
        int h = head(n), t = tail(n), l = len(n);
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