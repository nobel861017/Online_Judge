//Students_and_Party.c
#include <stdio.h>
//#include <string.h>
int main(){
	int N, E, vi, vj, id;
	scanf("%d%d", &N, &E);
	static int v[32768][256] = { {0} }, idx[32768] = { }, party[32768] = { };
	//memset(v, 0, sizeof(v));
	//memset(idx, 0, sizeof(idx));
	//memset(party, 0, sizeof(party));
	for(int i = 0; i < E; i++){
		scanf("%d%d", &vi, &vj);
		v[vi][ idx[vi]++ ] = vj;
		v[vj][ idx[vj]++ ] = vi;
	}
	/*
	for(int i = 0; i < N; i++){
		if(idx[i]) printf("%d: ",i);
		for(int j = 0; j < idx[i]; j++){
			printf(j != idx[i] - 1 ? "%d ":"%d\n", v[i][j]);
		}
	}
	*/
	while(scanf("%d", &id) != EOF){
		party[id] = 1;
		for(int i = 0; i < idx[id]; i++){
			party[ v[id][i] ] = 1;
		}
	}
	//for(int i = 0; i < N; i++) printf("%d ", party[i]);
	//puts("");
	for(int i = 0; i < N; i++)
		if(party[i] == 0)
			printf("%d\n", i);
	return 0;
}