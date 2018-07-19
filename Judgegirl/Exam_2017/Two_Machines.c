//Two_Machines.c
#include <stdio.h>

int main(){
	//int f = 1;
	int A_ready_time = 0, B_ready_time = 0, t, a, b, A_available = 1, B_available = 1, clock = 0, complete_time;
	while(scanf("%d%d%d",&t, &a, &b) != EOF){
		int cur_task_fin = 0;
		while(1){
			if(clock >= t){
				/*if(f){
					puts("");
					f = 0;
				}
				*/
				if(A_ready_time <= t) A_ready_time = t + a;
				else A_ready_time += a;

				if(B_ready_time < A_ready_time) B_ready_time = A_ready_time + b;
				else B_ready_time += b;
				clock = (A_ready_time > B_ready_time ? A_ready_time:B_ready_time);
				//clock = B_ready_time;
				//printf("%d %d ",A_ready_time,B_ready_time);
				/*if(a == 0) printf("%d\n",B_ready_time);
				else if(b == 0) printf("%d\n",A_ready_time);
				else printf("%d\n",B_ready_time);*/
				printf("%d\n", B_ready_time);
				break;
			}
			else{
				clock = A_ready_time = B_ready_time = t;
			}
		}
	}
}
/*
1 2 1
4 1 0
4 0 1

0 8 5
15 10 5
20 2 10
*/