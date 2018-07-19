//Max_mood_change.c
#include <stdio.h>
#include <stdlib.h>

typedef struct A{
	int ans_l_idx, ans_r_idx, min_idx, max_idx;
}A;
int max(int mood_change[][3]){
	int max_change = -2147483648, x;
	for(int i = 0; i < 3; i++){
		if(max_change < mood_change[i][0]){
			max_change = mood_change[i][0];
			x = i;
		}
	}
	return x;
}
A Max_mood_change(int *M, int start, int end){
	if(start == end - 1){	//只剩兩個
		if(M[start] > M[end]){
			A tmp = {start,end,end,start};
			return tmp;
		}
		else{
			A tmp = {start,end,start,end};
			return tmp;
		}
	}
	else if(start == end){	//	只剩一個
		A tmp = {end,end,end,end};
		return tmp;
	}
	A left = Max_mood_change(M,start,(start + end)/2);
	A right = Max_mood_change(M,(start + end)/2 + 1,end);
	int mood_change[3][3] = {{M[left.ans_r_idx] - M[left.ans_l_idx],left.ans_l_idx,left.ans_r_idx},{M[right.ans_r_idx] - M[right.ans_l_idx],right.ans_l_idx,right.ans_r_idx},{M[right.max_idx] - M[left.min_idx],left.min_idx,right.max_idx}};
	int idx = max(mood_change);
	A tmp = {mood_change[idx][1],mood_change[idx][2],M[left.min_idx] < M[right.min_idx] ? left.min_idx : right.min_idx,M[left.max_idx] > M[right.max_idx] ? left.max_idx : right.max_idx};
	return tmp;
}
int main(){
	int n = 0, M[100];
	while(scanf("%d",&M[n++]) != EOF){}
	A ans = Max_mood_change(M,0,n-1);
	printf("%d %d\n",ans.ans_l_idx,ans.ans_r_idx);
	return 0;
}