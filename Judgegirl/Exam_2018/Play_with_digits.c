// Play_with_digits.c
#include <stdio.h>

int main(){
	int d, count = 0, sum1 = 0, sum2 = 0, even = 0, eleven = 0, zeros = 0, flag = 0;
	while(scanf("%d", &d) != EOF){
		count++;
		if(d == 0) zeros ++;
		if(flag == 0){
			sum1 += d;
			flag = 1;
		}
		else{
			sum2 += d;
			flag = 0;
		}
	}
	if(d % 2 == 0) even = 1;
	if((sum1 - sum2) % 11 == 0) eleven = 1;
	printf("%d\n%d\n%d\n%d\n", count, even, zeros, eleven);
	return 0;
}
