//Tank_Simulation.c
#include <stdio.h>
int N, M, L, W, O, map[501][501] = { }, x, y, tmp_x, tmp_y, ins, count = 0;
//int dir_x[6] = {0,1,0,-1,0,1}, dir_y[6] = {0,0,1,0,-1,1};
int main(){
	scanf("%d%d%d%d%d",&N, &M, &L, &W, &O);
	for(int i = 0; i < O; i++){
		scanf("%d%d", &x, &y);
		map[y][x] = 2;
	}
	x = 0, y = 0;
	for(int i = 0; i < L; i++)
		for(int j = 0; j < W; j++)
			map[i][j] = 1;
	while(scanf("%d", &ins) != EOF){
		count = 0;
		switch(ins){
			case 0:
				for(int i = 0; i < N; i++){
					for(int j = 0; j < M; j++){
						printf(j != M-1 ? "%d":"%d\n", map[i][j]);
					}
				}
				break;
			case 1:
				if(x + 1 + W - 1 >= M) continue;
				for(int i = 0; i < L; i++)
					if(map[y+i][x+W] == 2){
						count++;
						if(count > 1) break;
					}
				if(count > 1) break;
				for(int i = 0; i < L; i++) map[y+i][x] = 0, map[y+i][x+W] = 1;
				x += 1;
				break;
			case 2:
				if(y + 1 + L - 1 >= N) continue;
				for(int i = 0; i < W; i++)
					if(map[y+L][x+i] == 2){
						count++;
						if(count > 1) break;
					}
				if(count > 1) break;
				for(int i = 0; i < W; i++) map[y][x+i] = 0, map[y+L][x+i] = 1;
				y += 1;
				break;
			case 3:
				tmp_x = x - 1;
				if(tmp_x < 0) continue;
				for(int i = 0; i < L; i++)
					if(map[y+i][tmp_x] == 2){
						count++;
						if(count > 1) break;
					}
				if(count > 1) break;
				for(int i = 0; i < L; i++) map[y+i][x+W-1] = 0;
				x -= 1;
				for(int i = 0; i < L; i++) map[y+i][x] = 1;
				break;
			case 4:
				tmp_y = y - 1;
				if(tmp_y < 0) continue;
				for(int i = 0; i < W; i++)
					if(map[tmp_y][x+i] == 2){
						count++;
						if(count > 1) break;
					}
				if(count > 1) break;
				for(int i = 0; i < W; i++) map[y+L-1][x+i] = 0;
				y = tmp_y;
				for(int i = 0; i < W; i++) map[y][x+i] = 1;
				break;
			case 5:
				if(x + 1 + W - 1 >= M || y + 1 + L - 1 >= N) continue;
				for(int i = 0; i < L; i++)
					if(map[y+i+1][x+W] == 2){
						count++;
						if(count > 1) break;
					}
				if(count > 1) break;
				for(int i = 0; i < W - 1; i++)
					if(map[y+L][x+1+i] == 2){
						count++;
						if(count > 1) break;
					}
				if(count > 1) break;
				for(int i = 0; i < L; i++) map[y+i][x] = 0, map[y+i][x+W] = 1;
				x += 1;
				for(int i = 0; i < W; i++) map[y][x+i] = 0, map[y+L][x+i] = 1;
				y += 1;
				break;	
		}
		/*
		printf("ins = %d\n", ins);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				printf(j != M-1 ? "%d":"%d\n", map[i][j]);
		printf("-------------------\n");
		*/
		/*
		if(ins == 0){
			for(int i = 0; i < N; i++)
				for(int j = 0; j < M; j++)
					printf(j != M-1 ? "%d":"%d\n", map[i][j]);
			continue;
		}
		tmp_x = x + dir_x[ins], tmp_y = y + dir_y[ins];
		if(tmp_x < 0 || tmp_y < 0 || tmp_x + W - 1 >= M || tmp_y + L - 1 >= N) continue;
		else{
			//printf("ins = %d\n", ins);
			int count = 0;
			for(int i = tmp_y; i < tmp_y + L; i++){
				for(int j = tmp_x; j < tmp_x + W; j++){
					if(map[i][j] == 2) count++;
					if(count > 1) break;
				}
			}
			if(count <= 1){
				for(int i = y; i < y + L; i++)
					for(int j = x; j < x + W; j++)
						map[i][j] = 0;
				x = tmp_x, y = tmp_y;
				for(int i = y; i < y + L; i++)
					for(int j = x; j < x + W; j++)
						map[i][j] = 1;
				for(int i = 0; i < N; i++)
					for(int j = 0; j < M; j++)
						printf(j != M-1 ? "%d":"%d\n", map[i][j]);
			}
		}
		*/
	}
	return 0;
}