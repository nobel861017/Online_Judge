//Marathon2.c
#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long ull;
int N, M, u, v, c[41] = {}, min_cost, degree[41] = {};
ull bitmap[41] = {}, one = 1;
typedef struct node{
    int vertex;
    struct node *next;
} Node;
Node *adjLists[41];
Node *createNode(int v){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(int src, int dest){
    Node *newNode = createNode(dest);
    newNode->next = adjLists[src];
    adjLists[src] = newNode;
}
void print_2(ull x){
	for(int i = 0; i < N; i++){
		printf("%d",(x & (one << (N - i))) != 0);
	}
	puts("");
}
int cal_cost(ull Is_Visited){
	if(Is_Visited == 0) return 0;
	int cost = 0;
	ull cost_bit = 0;
	for(int i = 1; i <= N; i++){
		if((Is_Visited & (one << i)) != 0){
			cost_bit |= bitmap[i];
		}
	}
	for(int i = 1; i <= N; i++){
		if((cost_bit & (one << i)) != 0){
			cost += c[i];
		}
	}
	return cost;
}
/*int Is_connected_to_path(int v, ull Is_Visited){
	int flag = 1;
	for(int i = 1; i <= N; i++){
		if((bitmap[v] & (one << i)) != 0){
			if((Is_Visited & (one << i)) != 0){
				flag = 0;
				break;
			}
		}
	}
	if(flag == 0) return 1;
	else return 0;
}*/
int IsValid(int v, ull Is_Visited, int pre){
	int flag = 1;
	for(int i = 1; i <= N; i++){
		if(i == pre) continue;
		if((bitmap[v] & (one << i)) != 0){
			if((Is_Visited & (one << i)) != 0){
				flag = 0;
			}
			break;
		}
	}
	if(flag == 0) return 0;
	else return 1;
}
void dfs(int pre, int pre_pre, int pre_pre_pre, int v, ull Is_Visited){
	if(pre_pre != -1)
		if((bitmap[v] & (one << pre_pre)) != 0) return;
	if(pre_pre_pre != -1)
		if((bitmap[v] & (one << pre_pre_pre)) != 0) return;
	pre_pre_pre = pre_pre;
	pre_pre = pre;
	pre = v;
	int cost = cal_cost(Is_Visited);
	//printf("cost = %d, Is_Visited = ", cost);
	//print_2(Is_Visited);
	if(cost > min_cost) return;
	if(v == 1){
		//int cost = cal_cost(Is_Visited);
		if(cost < min_cost) min_cost = cost;
		return;
	}
	for(int i = 1; i < N; i++){
		if(((bitmap[v] & (one << i)) != 0) && ((Is_Visited & (one << i)) == 0)){
			//printf("i = %d\n",i);
			if(!IsValid(i, Is_Visited, v)) continue;
			Is_Visited |= (one << i);
			dfs(pre, pre_pre, pre_pre_pre, i, Is_Visited);
			Is_Visited &= (~(one << i));
		}
	}
	return;
}
void print_bitmap(){
	for(int i = 1; i <= N; i++){
		printf("%d: %llu\n", i, bitmap[i]);
	}
}
void print_degree(){
	for(int i = 1; i <= N; i++){
		printf("deg_%d: %d\n", i, degree[i]);
	}
}
int main(){
	min_cost = 2147483647;
	scanf("%d%d", &N, &M);
	ull Is_Visited = 0;
	for(int i = 1; i <= N; i++) scanf("%d", &c[i]);
	while(M--){
		scanf("%d%d", &u, &v);
		//addEdge(u, v), addEdge(v, u);
		//if((bitmap[u] & (one << v)) != 0) continue;
		//degree[u]++, degree[v]++;
		bitmap[u] |= (one << v);
		bitmap[v] |= (one << u);
	}
	//print_graph(n);
	//print_bitmap();
	//print_degree();
	Is_Visited |= (one << N);
	dfs(-1, -1, -1, N, Is_Visited);
	printf("%d", min_cost);
	return 0;
}
