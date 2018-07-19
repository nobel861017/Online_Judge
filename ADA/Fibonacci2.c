//Fibonacci2.c
#include <stdio.h>
int Cal(int a,int b, int n){
	if(n == 1) return a;
	if(n == 2) return b;
	return Cal(a,b,n-1) + Cal(a,b,n-2);
}
int main(){
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	printf("%d\n",Cal(a,b,n));
	return 0;
}
