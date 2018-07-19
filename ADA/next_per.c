//next_per.c
#include <stdio.h>
#define swap(a,b){int tmp = a; a = b; b = tmp;}
int next_permutation(int *a, int len) {
	int i = len - 1;
	while (i > 0 && a[i - 1] >= a[i]) i--;
	if (i == 0) return 0;
	
	int j = len - 1;
	while (a[j] <= a[i - 1]) j--;
	swap(a[i - 1], a[j])
	
	j = len - 1;
	while (i < j) {
		swap(a[i], a[j])
		i++;
		j--;
	}
	return 1;
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	int rt = next_permutation(a, n);
	if(rt == 0) printf("last permutation");
	else
		for(int i = 0; i < n; i++) printf("%d ", a[i]);
}