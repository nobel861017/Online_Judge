//Fishing.c
#include <stdio.h>
#include <string.h>
long long dp[1024][10005][2];
void merge(int n, int k, long long *F, long long *D){
	for(int i = 0;i < k; i++){
		dp[n][i][0] = ( (F[n] - i*D[n] > 0)?F[n] - i*D[n]:0 );
		dp[n][i][1] = n;
	}
	int i = 0, j = 0;
	if(n > 0){
		int A[10005][2];
		for(int x = 0; x < k; x++){
			if(dp[n][i][0] > dp[n-1][j][0]){
				A[x][0] = dp[n][i][0];
				A[x][1] = dp[n][i][1];
				i++;
			}
			else{
				A[x][0] = dp[n-1][j][0];
				A[x][1] = dp[n-1][j][1];
				j++;
			}
		}
		for(int x = 0; x < k; x++){
			dp[n][x][0] = A[x][0];
			dp[n][x][1] = A[x][1];
		}
	}
}
int main(){
	int T,n,k;
	long long F[1024],D[1024];
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		scanf("%d %d",&n,&k);
		int tmp_k = k;
		for(int i = 0;i < n ; i++) scanf("%lld %lld",&F[i],&D[i]);
		long long sum[1024] = {}, max_sum = -1;
		int max_idx, counter[1024] = {}, op_num = 0;
		for(int i = 0; i < n; i++){
			merge(i,k,F,D);
			for(int j = 0;j < k; j++){
				sum[i] += dp[i][j][0];
			}
			if(sum[i] > max_sum){
				max_sum = sum[i];
				max_idx = i;
			}
			k--;
			if(k == 0) break;
		}
		/*for(int i = 0;i < n;i++){
			for(int j = 0;j < tmp_k-i;j++)
				printf(j == tmp_k-i-1 ?"%lld\n":"%lld ",dp[i][j][0]);
		}*/
		for(int i = 0; i < tmp_k - max_idx; i++){
			if(dp[max_idx][i][0])counter[dp[max_idx][i][1]]++;
		}
		for(int i = 0; i <= max_idx; i++){
			if(counter[i] != 0){
				op_num++;
				if(i != 0) op_num++;
			}
		}
		printf("%lld %d\n",max_sum, op_num);
		for(int i = 0; i <= max_idx; i++){
			if(counter[i] != 0){
				if(i == 0) printf("fish %d\n",counter[i]);
				else{
					printf("move %d\n",i+1);
					printf("fish %d\n",counter[i]);
				}
			}
		}
	}
	return 0;
}