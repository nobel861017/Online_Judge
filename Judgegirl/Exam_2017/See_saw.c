//See_saw.c
#include <stdio.h>
#define swap(a,b)({int tmp; tmp = a, a = b, b = tmp;})
void print(int *a, int pos, int n){
	for(int i = 0; i < n; i++){
		if(pos != i) printf(i != n - 1 ? "%d ":"%d\n", a[i]);
		else printf("v ");
	}
}
int main(){
	int cur = 1, n, a[2049], pre[2049] = {}, find = 0, it = 0, left = 0, right = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
		if(i == 0) pre[0] = a[0];
		else pre[i] = pre[i - 1] + a[i];
	}
	while(!find){
		if(cur == 1){
			left = a[0];
			for(int i = 1; i < n - 1; i++){
				right += i * a[i+1];
			}
			if(left == right){
				print(a, 1, n);
				find = 1;
			}
			else cur++;
		}
		else{
			left += pre[cur - 1];
			right -= (pre[n - 1] - pre[cur - 1]);
			if(left == right){
				print(a, cur, n);
				find = 1;
			}
			else if(cur == n - 2){
				left = 0, right = 0, cur = 1;
				swap(a[it],a[n - 1 - it]);
				it++;
			}
			else cur++;
		}
	}
	return 0;
}