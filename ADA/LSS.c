//LSS.c
#include <stdio.h>
#include <string.h>
#define max(a,b) a > b ? a : b

int A[2000], B[2000], dp[21][2000][2000];

#pragma O3
void LSS(int N, int M, int K){
	for(int k = 0; k <= K; k++){
		for(int n = 0; n < N; n++){
			for(int m = 0; m < M; m++){
				if(A[n] == B[m]){
					if(n != 0 && m != 0) dp[k][n][m] = dp[k][n-1][m-1] + 1;
					else dp[k][n][m] = 1;	// n = 0 or m = 0, 代表A or B只有一個
					//fprintf(stderr,"dp[%d][%d][%d] = %d\n",k,n,m,dp[k][n][m]);
				}
				else{		// k == 0, dp[0][m][n] = dp[0][n][m-1] or dp[0][n-1][m] is less than the values below
					//	Lss has n doesn't have m and not going to replace B[m]		dp[k][n][m-1]
					//	has n doesn't have m and going to replace B[m] with A[n]	dp[k-1][n][m-1]+1
					//	doesn't have n has m 										dp[k][n-1][m]
					//	doesn't have n and m but going to replace B[m] with A[n]	dp[k-1][n-1][m-1]+1
					// 	dp[k][n][m-1] ≥ dp[k-1][n][m-1]+1
					int x = 1;
					if(k != 0 && n != 0 && m != 0) x = dp[k-1][n-1][m-1] + 1;
					if(!k) x = 0;
					dp[k][n][m] = max(max( ((m == 0) ? 0 : dp[k][n][m-1]), ((n == 0) ? 0 : dp[k][n-1][m])), x);
					//fprintf(stderr,"dp[%d][%d][%d] = %d\n",k,n,m,dp[k][n][m]);

				}
				if(dp[k][n][M-1] == M){
					printf("%d",dp[k][n][M-1]);
					return;
				}
			}
		}
		if(dp[k][N-1][M-1] == N || dp[k][N-1][M-1] == M){
			printf("%d",dp[k][N-1][M-1]);
			return;
		}
	}
	printf("%d",dp[K][N-1][M-1]);
	return;
}

int main(){
	memset(dp,0,sizeof(dp));
	int N, M, K;
	scanf("%d%d%d",&N, &M, &K);
	for(int i = 0; i < N; i++) scanf("%d",&A[i]);
	for(int i = 0; i < N; i++) scanf("%d",&B[i]);
	LSS(N,M,K);
	return 0;
}
