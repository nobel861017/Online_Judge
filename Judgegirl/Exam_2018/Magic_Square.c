//Magic_Square.c
#include <stdio.h>
#include <string.h>
int main(){
	int N,k,x,y,map[1002][1002] = { }, tmp_x, tmp_y, tx, ty;
	scanf("%d%d%d%d",&N,&k,&x,&y);
	map[x][y] = k;
	tx = x, ty = y;
	if(k != 1){
		int tmp = k;
		while(--tmp){
			tmp_y = (y - 1 + N) % N, tmp_x = (x + 1) % N;
			if(map[tmp_x][tmp_y] == 0){
				x = tmp_x, y = tmp_y;
				map[x][y] = tmp;
			}
			else{
				x = (x - 1 + N) % N;
				map[x][y] = tmp;
			}
		}
	}
	x = tx, y = ty;
	while(k < N*N){
		k++;
		tmp_y = (y + 1) % N, tmp_x = (x - 1 + N) % N;
		if(map[tmp_x][tmp_y] == 0){
			x = tmp_x, y = tmp_y;
			map[x][y] = k;
		}
		else{
			x = (x + 1) % N;
			map[x][y] = k;
		}
		
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf(j == N - 1 ? "%d":"%d ", map[i][j]);
		}
		puts("");
	}
	return 0;
}