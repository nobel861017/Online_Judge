#include <stdio.h>
#include <stdlib.h>
__int128 one = 1;
__int128 adj[101];
int max_clique = 0;
int popcount(__int128 val){
    return __builtin_popcountll(val >> 50) + __builtin_popcountll(val & ((one << 50) - 1));
}

int lowbit(__int128 val){
    if((val & ((one << 50) - 1)) == 0)
        return __builtin_ctzll(val >> 50) + 50;
    return __builtin_ctzll(val & ((one << 50) - 1));
}

/* candi needs to be sorted by degenerate*/

void maxclique(int elem_num, __int128 candi){
    if(elem_num > max_clique) max_clique = elem_num;

    int potential = elem_num + popcount(candi);
    if(potential <= max_clique) return;
    int pivot = lowbit(candi);
    __int128 smaller_candi = candi & (~adj[pivot]);
    while(smaller_candi && potential > max_clique){
        int next = lowbit(smaller_candi);
        candi ^= one << next;
        smaller_candi ^= one << next;
        potential --;

    if(next == pivot || (smaller_candi & adj[next]))
        maxclique(elem_num + 1, candi & adj[next]);
    }
}
int main(){
    int N, M, u, v;
    scanf("%d%d", &N, &M);
    while(M--){
        scanf("%d%d", &u, &v);
        adj[u] |= (one << v); 
        adj[v] |= (one << u);
    }
    maxclique(0, (one << N) - 1);
    printf("%d\n", max_clique);
    return 0;
}

