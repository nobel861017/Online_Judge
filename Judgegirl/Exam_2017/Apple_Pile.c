//Apple_Pile.c
#include <stdio.h>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n%d",(a+b)*(b-a+1) >> 1,3*b-a-2);
}