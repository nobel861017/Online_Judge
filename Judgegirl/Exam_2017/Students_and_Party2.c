//Students_and_Party.c
#include <stdio.h>
#include <string.h>
int v[32768][256], idx[32768], party[32768];
int main(){
    int N, E, vi, vj, id;
    scanf("%d%d", &N, &E);
    memset(v, 0, sizeof(v));
    memset(idx, 0, sizeof(idx));
    memset(party, 0, sizeof(party));
    for(int i = 0; i < E; i++){
        scanf("%d%d", &vi, &vj);
        v[vi][ idx[vi]++ ] = vj;
        v[vj][ idx[vj]++ ] = vi;
    }
    while(scanf("%d", &id) != EOF){
        party[id] = 1;
        for(int i = 0; i < idx[id]; i++){
            party[ v[id][i] ] = 1;
        }
    }
    for(int i = 0; i < N; i++)
        if(!party[i])
            printf("%d\n", i);
    return 0;
}