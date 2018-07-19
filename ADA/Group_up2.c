//Group_up2.c
#include <stdio.h>
#include <limits.h>
#define min(a,b) a > b ? b : a

typedef unsigned long long ull;
int N,K;
ull x[100005] = {}, dp[21][100005] = {{}}, w[100005];

ull weight(int j, int N){
	ull sum = 0;
	for(int i = j; i < N; i++) sum += (N-i)*w[i];
	return sum;
}
void total_weight(){
	x[0] = w[0];
	for(int i=1;i<N;i++) x[i] = x[i-1] + w[i];
}
void one_group_leader(){
	dp[1][0] = 0;
	for(int i = 1; i < N; i++)
		dp[1][i] = dp[1][i-1] + x[i-1];
	//for(int i = 0; i < N; i++) printf(i == N-1 ? "%llu\n":"%llu ",dp[1][i]);
}
ull DP(int k, int n){
	if(dp[k][n] > 0) return dp[k][n];
	if(k == n+1) return 0;
	if(k == 1) return weight(0,n);
	else{
		ull sum = ULLONG_MAX;
		for(int i = 0; i < n; i++) sum = min(sum, DP(k-1,i) + (dp[1][n] - dp[1][i] - (ull)(n-i)*x[i]));
		dp[k][n] = sum;
	}
	return dp[k][n];
}
int main(){
	scanf("%d%d",&N,&K);
	for(int i = 0;i < N;i++) scanf("%lld",&w[i]);
	total_weight();
	one_group_leader();
	printf("%llu",DP(K,N-1));
	return 0;
}