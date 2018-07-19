//Buckets_and_Balls.c
#include <stdio.h>

int main(){
	int N, M, R, x;
	scanf("%d%d%d", &N, &M, &R);
	if(R){	// best fit
		while(scanf("%d", &x) != EOF){
			if( ((N - x <= M - x) || (M < x) ) && N >= x) N -= x;
			else if(M >= x) M -= x;
			printf("%d %d\n", N, M);
		}
	}
	else if(!R){	// first fit
		while(scanf("%d", &x) != EOF){
			if(x <= N) N -= x;
			else if(x <= M) M -= x;
			printf("%d %d\n", N, M);
		}
	}
}