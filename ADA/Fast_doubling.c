//Fast_doubling.c
//Fibonacci a = 1, b = 1時才對
#include <stdio.h>
int fib(int a, int b, int n){
	if(n == 1) return a;
	else if (n == 2) return b;
	else{
		if(n % 2 == 0){
			int k = n/2;
			return fib(a,b,k)*( 2*fib(a,b,(k+1)) - fib(a,b,k));
		}
		else if(n % 2 == 1){
			int k = (n-1)/2;
			return fib(a,b,k+1)*fib(a,b,k+1) + fib(a,b,k)*fib(a,b,k);
		}
	}
}
int main(){
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	printf("%d\n",fib(a,b,n));
	return 0;
}