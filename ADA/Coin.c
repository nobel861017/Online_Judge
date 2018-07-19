//Coin.c
#include <stdio.h>
/*void Initialize(int *list[],int coin_num){
	for(int i=0;i<coin_num;i++){
		list[0][i] = 1;
	}
}*/
int DP(int coin_num, int total, int *c){
	int list[total+1][coin_num];
	//int list[10001][101];
	//Initialize(list,coin_num);
	for(int i=0;i<coin_num;i++) list[0][i] = 1;
	for(int i=1;i<total+1;i++){
		for(int j=0;j<coin_num;j++){
			int value = i-c[j];
			int a,b;
			if(value >= 0) a = list[value][j];
			else a = 0;
			if(j >= 1) b = list[i][j-1];
			else b = 0;
			list[i][j] = (a + b)%1000000007;
		}
	}
	return list[total][coin_num-1];
}
int main(){
	int n, p, c[105], idx = 0;
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++) scanf("%d",&c[idx++]);
	printf("%d\n",DP(n,p,c));
	return 0;
}