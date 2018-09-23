// Buckets_and_Balls_Again
#include<stdio.h>

void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]){
	if(method == 0){
		for(int i = 0; i < M; i++){
			int find = 0;
			for(int j = 0; j < N; j++){
				if(ball[i] <= bucket[j]){
					result[i] = j;
					bucket[j] -= ball[i];
					find = 1;
					break;
				}
			}
			if(find == 0) result[i] = -1;
		}
	}
	else if(method == 1){
		for(int i = 0; i < M; i++){
			int min = 2147483647, min_idx;
			for(int j = 0; j < N; j++){
				if(ball[i] <= bucket[j] && bucket[j] < min){
					min = bucket[j];
					min_idx = j;
				}
			}
			if(min == 2147483647) result[i] = -1;
			else{
				result[i] = min_idx;
				bucket[min_idx] -= ball[i];
			}
		}
	}
	else{
		for(int i = 0; i < M; i++){
			int max = -1, max_idx;
			for(int j = N-1; j >= 0; j--){
				if(ball[i] <= bucket[j] && bucket[j] > max){
					max = bucket[j];
					max_idx = j;
				}
			}
			if(max == -1) result[i] = -1;
			else{
				result[i] = max_idx;
				bucket[max_idx] -= ball[i];
			}
		}
	}
}

int main(){
    int N,M,method;
    scanf("%d%d%d",&N,&M,&method);
    int buckets[N];
    for(int i=0;i<N;i++)
        scanf("%d",&buckets[i]);
    int balls[M];
    for(int i=0;i<M;i++)
        scanf("%d",&balls[i]);
    int result[M];
    place(buckets,N,balls,M,method,result);
    for(int i=0;i<M;i++)
        printf("%d%s",result[i],i==M-1?"":" ");
    return 0;
}
