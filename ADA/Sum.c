//Sum.c
#include <stdio.h>
typedef unsigned long long ull;

int main(){
	int T, n;
	ull k;
	scanf("%d",&T);
	while(T--){
		int idx = -1;
		scanf("%d%llu",&n,&k);
		ull s[n+1][2];
		for(int i = 0; i < n; i++) s[i][1] = 0;
		for(int i = 0; i < n; i++) scanf("%llu",&s[i][0]);
		/*for(int i = n - 1; i >= 0; i--){
			if(s[i][0] > k){
				continue;
			}
			else{
				idx = i;
				break;
			}
		}
		if(idx == -1){
			printf("-1\n");
			continue;
		}
		//printf("idx = %d\n",idx);*/
		idx = n - 1;
		ull counter = 0;
		int flag = 0;
		while(k > 0 && idx >= 0){
			while(s[idx][0] > k){
				idx--;
				if(idx == -1){
					printf("-1\n");
					flag = 1;
					break;
				}
				continue;
			}
			if(flag) break;
			if(s[idx][0] <= k/2){
				printf("-1\n");
				flag = 1;
				break;
			}
			else if(s[idx][0] <= k){
				s[idx][1] = 1;
				k -= s[idx][0];
				counter++;
			}
			idx--;
		}
		if(flag) continue;
		printf("%llu\n",counter);
		idx = 0;
		ull tmp = counter;
		while(1){
			if(s[idx][1] == 1){
				tmp --;
				printf(tmp == 0 ? "%llu\n":"%llu ",s[idx][0]);
			}
			idx++;
			if(!tmp) break;
		}
	}
	return 0;
}











