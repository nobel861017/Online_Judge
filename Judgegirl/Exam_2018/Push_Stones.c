//Push_Stones.c
#include <stdio.h>

int main(){
	int N, M, y, x, yt, xt, e, map[501][501] = {{ }}, w, O, ins, tmp_y, tmp_x, flag = 1;
	int dir_y[5] = {0, 0, 1, 0, -1};
	int dir_x[5] = {0, 1, 0, -1, 0};
	scanf("%d%d%d%d%d%d",&N, &M, &y, &x, &e, &O);
	map[y][x] = e;
	for(int i = 0; i < O; i++){
		scanf("%d%d%d", &yt, &xt, &w);
		map[yt][xt] = w;
	}
	while(scanf("%d", &ins) != EOF){
		if(ins == 0){
			for(int i = 0; i < N; i++){
				for(int j = 0; j < M; j++){
					printf(j != (M-1) ? "%d ":"%d\n", map[i][j]);
				}
			}
			continue;
		}
		int sum = 0;
		tmp_y = y + dir_y[ins], tmp_x = x + dir_x[ins];
		if(tmp_y < 0 || tmp_y >= N || tmp_x < 0 || tmp_x >= M) continue;
		if(map[tmp_y][tmp_x] == 0){
			map[tmp_y][tmp_x] = map[y][x];
			map[y][x] = 0;
			y = tmp_y, x = tmp_x;
			continue;
		}
		while(map[tmp_y][tmp_x] != 0){
			sum += map[tmp_y][tmp_x];
			tmp_y +=  dir_y[ins], tmp_x += dir_x[ins];
			if(tmp_y < 0 || tmp_y >= N || tmp_x < 0 || tmp_x >= M){
				flag = 0;
				break;
			}
		}
		if(flag == 0){
			flag = 1;
			continue;
		}
		if(map[y][x] < sum) continue;
		else{
			map[y][x] -= sum;
			while(tmp_y != y || tmp_x != x){
				map[tmp_y][tmp_x] = map[tmp_y - dir_y[ins]][tmp_x - dir_x[ins]];
				tmp_y -= dir_y[ins], tmp_x -= dir_x[ins];
			}
			map[y][x] = 0;
			y += dir_y[ins], x += dir_x[ins];
		}
	}
	return 0;
}