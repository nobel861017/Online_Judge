//Machines_an_Jobs.c
#include <stdio.h>
#include <limits.h>
#define max(a,b)(a > b ? a : b)
int main(){
	int N, M, n[501], task_m[501][501], task_t[501][501], task_f[501] = {}, ready_time[501] = { }, count = 0, job_rt[501] = {}, ans[501];
	scanf("%d%d",&N, &M);
	for(int i = 0; i < M; i++){
		scanf("%d%d",&job_rt[i], &n[i]);
		for(int j = 0; j < n[i]; j++) scanf("%d%d",&task_m[i][j], &task_t[i][j]);
	}
	while(1){
		int min = INT_MAX, min_i;
		for(int i = 0; i < M; i++){
			if(task_f[i] == n[i]) continue;
			if(ready_time[task_m[i][task_f[i]]] >= job_rt[i]){
				if(min > ready_time[task_m[i][task_f[i]]] + task_t[i][task_f[i]] && min > job_rt[i] + task_t[i][task_f[i]]){
					min = max(ready_time[task_m[i][task_f[i]]], job_rt[i]) + task_t[i][task_f[i]];
					min_i = i;
				}
			}
			else{
				if(min > job_rt[i] + task_t[i][task_f[i]]){
					min = job_rt[i] + task_t[i][task_f[i]];
					min_i = i;
				}
			}
		}
		ready_time[ task_m[min_i][ task_f[min_i] ] ] = min, job_rt[min_i] = min;
		task_f[min_i]++;
		if(task_f[min_i] == n[min_i]){
			ans[min_i] = min;
			count++;
		}
		if(count == M) break;
	}
	for(int i = 0; i < M; i++) printf("%d\n", ans[i]);
	return 0;
}