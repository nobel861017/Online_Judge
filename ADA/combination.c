//combination.c
#include <stdio.h>
#include <string.h>

int w[100005];
int N, K;
void group(int idx,int chosen_num, int *is_chosen){
    if(chosen_num == K){
        for(int i = 0; i < N; i++){
            printf("%2d",is_chosen[i]);
        }
        printf("\n");
        return;
    }
    if(idx == N) return;
    is_chosen[idx] = 1;
    group( idx + 1, chosen_num + 1,  is_chosen);
    is_chosen[idx] = 0;
    group( idx + 1, chosen_num , is_chosen);
}
int main(){

    int is_chosen[100005];
    scanf("%d%d",&N,&K);
    memset(is_chosen,0,N);
    //for(int i = 0;i < N;i++)
    //   scanf("%d",&w[i]);
    group(0, 0, is_chosen);
    return 0;
}