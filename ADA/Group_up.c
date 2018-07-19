//combination.c
#include <stdio.h>
#include <string.h>
#define ull unsigned long long
int w[100005];
int N, K;
ull ans = (ull)1 << 63;

void group(int idx,int chosen_num, int *is_chosen, ull cost, int last_idx){
    if(cost > ans) return;
    if(chosen_num == K){
    	if(is_chosen[N-1] == 0) return;
    	if(cost < ans) ans = cost;
        /*for(int i = 0; i < N; i++){
            printf("%2d",is_chosen[i]);
        }
        printf(" cost = %d\n",cost);*/
        return;
    }
    if(chosen_num == K - 1){
    	ull sum2 = 0;
    	for(int i = last_idx + 1; i < N - 1; i++ ){
    		sum2 += (N - i - 1)*w[i];
    		if(sum2 > ans) return;
    	}
    	is_chosen[N-1] = 1;
    	group( N, K,  is_chosen, cost + sum2, N-1);
    	is_chosen[N-1] = 0;
    	return;
    }
    if(idx == N) return;
    ull sum = 0;
    for(int i = last_idx + 1; i < idx; i++ ){
    	sum += (idx - i)*w[i];
    	if(sum > ans) return;
    }
    is_chosen[idx] = 1;
    group( idx + 1, chosen_num + 1,  is_chosen, cost + sum, idx);
    is_chosen[idx] = 0;
    group( idx + 1, chosen_num , is_chosen, cost, last_idx);
}
int main(){
    int is_chosen[100005];
    scanf("%d%d",&N,&K);
    memset(is_chosen,0,N);
    for(int i = 0;i < N;i++)
    	scanf("%d",&w[i]);
    group(0, 0, is_chosen, 0, -1);
    printf("%llu\n",ans);
    return 0;
}
