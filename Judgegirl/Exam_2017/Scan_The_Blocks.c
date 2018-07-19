//Scan_The_Blocks.c
#include <stdio.h>
#include <limits.h>
int main(){
	int n, max, min, x;
	while(scanf("%d",&n) != EOF){
		max = INT_MIN, min = INT_MAX;
		while(n-- && scanf("%d",&x) != EOF){
			if(x > max) max = x;
			if(x < min) min = x;
		}
		printf("%d\n", n == -1 ? max:min);
	}
}