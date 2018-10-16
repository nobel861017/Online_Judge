#include <stdio.h>
#include <string.h>
typedef struct{
    int k_idx;
    int step;
    int Is_visit;
}Map;
typedef struct{
    int y;
    int x;
    int stop;
    int step;
} Knight;
int main(){
    int n,m, finish = 0;
    int dir_y[8] = {-2,-1, 1, 2, 2, 1,-1,-2}, dir_x[8] = { 1, 2, 2, 1,-1,-2,-2,-1};
    Map map[101][101];
    Knight k[10001];
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            map[i][j].Is_visit = 0;
            map[i][j].k_idx = 0;
            map[i][j].step = 0;
        }
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d",&k[i].y,&k[i].x);
        map[ k[i].y ][ k[i].x ].Is_visit = 1;
        map[ k[i].y ][ k[i].x ].step = 0;
        map[ k[i].y ][ k[i].x ].k_idx = i+1;
        k[i].stop = 0;
        k[i].step = 0;
    }
    while(finish != m){
        for(int i = 0; i < m; i++){
            if(k[i].stop == 1) continue;
            int min = 2147483647, r, c, flag = 0;
            for(int j = 0; j < 8; j++){
                int sum = 0;
                int next_y = k[i].y + dir_y[j];
                int next_x = k[i].x + dir_x[j];
                if(next_y >=n || next_y < 0 || next_x >= n || next_x < 0 || map[next_y][next_x].Is_visit == 1) continue;
                flag = 1;
                for(int k = 0; k < 8; k++){
                    int next_y2 = next_y + dir_y[k];
                    int next_x2 = next_x + dir_x[k];
                    if(next_y2 >=n || next_y2 < 0 || next_x2 >= n || next_x2 < 0 || map[next_y2][next_x2].Is_visit == 1) continue;
                    sum++;
                }
                if(sum < min){
                    min = sum;
                    r = next_y, c = next_x;
                }
            }
            if(flag == 0){
                k[i].stop = 1;
                finish++;
            }
            else{
                k[i].y = r;
                k[i].x = c;
                k[i].step++;
                map[r][c].k_idx = i+1;
                map[r][c].step = k[i].step;
                map[r][c].Is_visit = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(j == n - 1 ? "%d":"%d ", map[i][j].k_idx * 10000 + map[i][j].step);
        }
      puts("");
    }
    return 0;
}