//max_sum_nondecreasing_subsequence.c
#include <stdio.h>
#define max(a,b) a > b ? a : b
int main(){
	int n,S[100],dp[100] = {};
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&S[i]);
	dp[0] = S[0];
	for(int i = 1; i < n; i++){
		int pre_idx = -1, pre_max_sum = -1;
		for(int j = i-1; j >= 0; j--){
	    	if(S[i] >= S[j] && (dp[j] > pre_max_sum)){
	    		pre_idx = j;
	    		pre_max_sum = dp[j];
	    	}
		}
		if(pre_idx != -1) dp[i] = dp[pre_idx] + S[i];
		else dp[i] = S[i];
	}
	int max = -1;
	for(int i = 0; i < n; i++){
		printf(i == n-1 ?"%d\n":"%d ",dp[i]);
		if(dp[i] > max) max = dp[i];
	}
	printf("max sum: %d\n",max);
	return 0;
}