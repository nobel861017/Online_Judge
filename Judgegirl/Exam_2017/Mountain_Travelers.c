//Mountain_Travelers.c
#include <stdio.h>
#include <limits.h>
#include <string.h>

int out_range(int x, int y, int N, int M){
    if(x < 0 || y < 0) return 1;
    if(x >= N || y >= M) return 1;
    return 0;
}

void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[]){
    int dr[8] = {0, 0, 1, -1, 1, -1, -1, 1};
	int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int pre[8] = {1, 0, 3, 2, 5, 4, 7, 6};
	int vis[N][M], flag_a = 1, flag_b = 1, idx = 0, pre_A = -1, pre_B = -1;
    memset(vis, 0, sizeof(vis));
    vis[A_r][A_c] = 1, vis[B_r][B_c] = 1;
	while(flag_a || flag_b){
        if(flag_a){
            int max = INT_MIN, max_i;
            for(int i = 0; i < 8; i++){
                if(i == pre_A) continue;
                if(out_range(A_r+dr[i], A_c+dc[i], N, M)) continue;
                int h = map[A_r+dr[i]][A_c+dc[i]];
                if(h > max && h > map[A_r][A_c]){
                    max = h;
                    max_i = i;
                }
            }
            if(max == INT_MIN){
                flag_a = 0;
                directionA[idx] = -1;
                //fprintf(stderr,"A can't find uphill.\n");
            }
            else if(vis[A_r+dr[max_i]][A_c+dc[max_i]] == 0){
                A_r = A_r+dr[max_i], A_c = A_c+dc[max_i];
                directionA[idx] = max_i, pre_A = pre[max_i];
                vis[A_r][A_c] = 1;
                //fprintf(stderr, "A is at (%d,%d)\n", A_r, A_c);
            }
            else{
                directionA[idx] = max_i;
                directionA[idx+1] = -1;
                flag_a = 0;
                //fprintf(stderr,"A's destination (%d,%d) is visited.\n", A_r+dr[max_i], A_c+dc[max_i]);
            }
            //printf("(A_r, A_c) = (%d,%d)\n", A_r, A_c);
        }
        
        if(flag_b){
            int min = INT_MAX, min_i;
            for(int i = 0; i < 8; i++){
                if(pre_B == i) continue;
                if(out_range(B_r+dr[i], B_c+dc[i], N, M)) continue;
                int h = map[B_r+dr[i]][B_c+dc[i]];
                if(h < min && h < map[B_r][B_c]){
                    min = h;
                    min_i = i;
                }   
            }
            if(min == INT_MAX){
                flag_b = 0;
                directionB[idx] = -1;
                //fprintf(stderr,"B can't find downhill.\n");
            }
            else if(vis[B_r+dr[min_i]][B_c+dc[min_i]] == 0){
                B_r = B_r+dr[min_i], B_c = B_c+dc[min_i];
                directionB[idx] = min_i, pre_B = pre[min_i];
                vis[B_r][B_c] = 1;
                //fprintf(stderr, "B is at (%d,%d)\n", B_r, B_c);
            }
            else{
                directionB[idx] = min_i;
                directionB[idx+1] = -1;
                flag_b = 0;
                //fprintf(stderr,"B's destination (%d,%d) is visited.\n", B_r+dr[min_i], B_c+dc[min_i]);
                if(A_r == B_r+dr[min_i] && A_c == B_c+dc[min_i]){
                    directionA[idx+1] = -1;
                    break;
                }
            }
            //printf("(B_r, B_c) = (%d,%d)\n", B_r, B_c);
        }


        /*if(A_r == B_r && A_c == B_c){
            directionA[idx+1] = -1, directionB[idx+1] = -1;
            fprintf(stderr,"AB in same cell.\n");
            //flag_a = 0, flag_b = 0;
            break;
        }*/
        idx ++;
	}
	
}

int main() {
    int N, M;
    int map[1024][1024];
    int A_r, A_c, B_r, B_c;
    int directionA[1024], directionB[1024];
 
    scanf("%d%d", &N, &M);
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
 
    scanf("%d%d%d%d", &A_r, &A_c, &B_r, &B_c);
 
    travel(map, N, M, A_r, A_c, B_r, B_c, directionA, directionB);
    
    int i = 0;
    while (directionA[i] != -1) {
        printf("%d ", directionA[i]);
        i++;
    }
    printf("-1\n");
    i = 0;
    while (directionB[i] != -1) {
        printf("%d ", directionB[i]);
        i++;
    }
    printf("-1\n");
    
    return 0;

}