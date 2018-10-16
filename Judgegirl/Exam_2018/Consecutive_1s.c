//Consecutive_1s.c
#include <stdio.h>
#pragma GCC optimized ("unroll-loops")
#pragma GCC optimized ("O3")
int main(){
	int N;
    scanf("%d",&N);
    int a[N][N], row[1001] = {}, col[1001] = {}, dia[2000] = {}, max = -1, d;
    d = N-1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j]){
                row[i]++,col[j]++,dia[j-i+d]++;
                if(row[i] > max) max = row[i];
                if(col[j] > max) max = col[j];
                if(dia[j-i+d] > max) max = dia[j-i+d];
            }
            else row[i] = 0,col[j] = 0, dia[j-i+d] = 0;
        }
    }
    printf("%d\n", max);
    return 0;
}