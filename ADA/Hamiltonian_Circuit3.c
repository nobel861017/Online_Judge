//Hamiltonian_Circuit3.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int from[100005] = {}, to[100005] = {};
int in_degree[100005] = {}, out_degree[100005] = {};
int start[100005] = {}, end[100005] = {}, length[100005] = {};
int all_deg1_loop = 1;
int one_index, var;
int node_table[45], node_table_idx = 0;
typedef struct node{
    int vertex;
    struct node *next;
} Node;
Node *adjLists[100005];
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
int Is_adjacent(int u, int v){
	Node *tmp_adjLists = adjLists[u];
	while(tmp_adjLists){
		if(tmp_adjLists->vertex == v) return 1;
		else tmp_adjLists = tmp_adjLists->next;
	}
	return 0;
}
void make_table(int N){
	for(int i = 1; i <= N; i++){
		if (adjLists[i] == NULL){
			printf("-1");
			exit(0);
		}
		//printf("make:%d\n", i);
		if(in_degree[i] < 1 || out_degree[i] < 1){
			printf("-1");
			exit(0);
		}
		if(in_degree[i] > 1){
			from[i] = 0;
		}
		if(out_degree[i] > 1){
			to[i] = 0;
		}
		if(out_degree[i] == 1){
			to[i] = adjLists[i]->vertex;
			if(in_degree[adjLists[i]->vertex] == 1)
				from[adjLists[i]->vertex] = i;
		}
	}
}
int get_last_vertex(int i){
	int tmp_i = i, pre = i;
	int len = 1;
	while(to[i] != 0 && in_degree[to[i]] == 1){
		len++;
		pre = i;
		i = to[i];
	}
	length[tmp_i] = len;
	if(in_degree[i] == 1) return i;
	else return pre;
}
void Construct_Node(int N){
	for(int i = 1; i <= N; i++){
		if(to[from[i]] == 0){
			start[i] = 1;
			end[i] = get_last_vertex(i);
			node_table[node_table_idx] = i;
			node_table_idx++;
		}
	}
}
void print_Node(int N){
	int Is_Visited[N+1];
	memset(Is_Visited, 0, sizeof(Is_Visited));
	for(int i = 1; i <= N; i++){
		if(start[i] == 1 && !Is_Visited[i]){
			printf("%d ",i);
			Is_Visited[i] = 1;
			int idx = i;
			while(to[idx] != 0 && !Is_Visited[to[idx]]){
				Is_Visited[to[idx]] = 1;
				idx = to[idx];
				printf("%d ",idx);
			}
			Is_Visited[to[idx]] = 1;
			puts("");
		}
	}
}
void print_degree(int n){
	for(int i = 1; i <= n; i++){
		printf("%d in:%d, out:%d\n", i, in_degree[i], out_degree[i]);
	}
}
void print_table(int n){
	for(int i = 1; i <= n; i++) printf("%2d ", i);
	puts("");
	for(int i = 1; i <= n; i++) printf("%2d ", from[i]);
	puts("");
	for(int i = 1; i <= n; i++) printf("%2d ", to[i]);
	puts("");
}
void print_graph(int n){
	for(int i = 1; i <= n; i++){
		printf("%d",i);
		Node *tmp_adjLists = adjLists[i];
		while(tmp_adjLists){
			printf("->%d", tmp_adjLists->vertex);
			tmp_adjLists = tmp_adjLists->next;
		}
		puts("");
	}
}
void print_loop(int n){
	Node *tmp = adjLists[1];
	int Is_Visited[n+1];
	memset(Is_Visited, 0, sizeof(Is_Visited));
	printf("1 ");
	Is_Visited[1] = 1;
	while(tmp){
		if(Is_Visited[tmp->vertex]) break;
		Is_Visited[tmp->vertex] = 1;
		printf("%d ",tmp->vertex);
		tmp = adjLists[tmp->vertex];

	}
	printf("1");
}
void check_loop(int n){
	Node *tmp = adjLists[1];
	int counter = 1, Is_Visited[n+1];
	memset(Is_Visited, 0, sizeof(Is_Visited));
	while(tmp){
		counter++;
		if(Is_Visited[tmp->vertex] && counter != n) break;
		Is_Visited[tmp->vertex] = 1;
		if(counter == n){
			print_loop(n);
			exit(0);
		}
		tmp = adjLists[tmp->vertex];
	}
	printf("-1");
	exit(0);
}
void print_node_status(int n){
	for(int i = 1; i <= n; i++){
		printf("%d: start = %d, end = %d, length = %d\n", i, start[i], end[i], length[i]);
	}
}
void concatenate(int *path, int idx, int n, int v){
	for(int i = idx; i < n; i++){
		if(v == 1) one_index = i;
		path[i] = v;
		v = to[v];
	}
}
int dfs(int n, int len, int *Is_Visited, int pre, int *path, int head, int level, int clock){
	/*if(time(NULL) - var > 1.9){
		printf("-1");
		exit(0);
	}*/
	if(len == n){
		if(Is_adjacent(pre, head)) return 1;
		else return 0;
	}
	for(int i = 0; i <= 40 && node_table[i] != 0; i++){
		int idx = node_table[i];
		if(start[idx] == 1 && !Is_Visited[idx]){
			//printf("i = %d\n",i);
			if(head == 0) head = idx;
			if(pre != -1)
				if(!Is_adjacent(pre, idx)) continue;
			Is_Visited[idx] = 1;
			if(dfs(n, len + length[idx], Is_Visited, end[idx], path, head, 1, clock + 1)){
				concatenate(path, len, len + length[idx], idx);
				return 1;
			}
			else if(level == 0) return 0;
			Is_Visited[idx] = 0;
		}
	}
	return 0;
}
void print_path(int n, int *path){
	for(int i = 0; i < n; i++)
		printf("%d ", path[(one_index + i) % n]);
	printf("1");
}
void print_node_table(){
	for(int i = 0; i < 40; i++)
		printf("%d ",node_table[i]);
	puts("");
}
int main(){
	var = time(NULL);
	int n, m, u, v;
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d", &u, &v);
		if(Is_adjacent(u, v)) continue;
		addEdge(u, v);
		in_degree[v]++, out_degree[u]++;
	}
	for(int i = 1; i <= n; i++){
		if(in_degree[i] != 1 || out_degree[i] != 1){
			all_deg1_loop = 0;
			break;
		}
	}
	//printf("all_deg1_loop = %d\n", all_deg1_loop);
	if(all_deg1_loop) check_loop(n);
	//print_graph(n);
	//print_degree(n);
	make_table(n);
	print_table(n);
	Construct_Node(n);
	//print_node_table();
	//print_node_status(n);
	//print_Node(n);
	int Is_Visited[n+1], path[n+1];
	memset(path, 0, sizeof(path));
	memset(Is_Visited, 0, sizeof(Is_Visited));
	int rt = dfs(n, 0, Is_Visited, -1, path, 0, 0, 0);
	memset(node_table, 0, sizeof(node_table));
	if(rt) print_path(n, path);
	else printf("-1");
	return 0;
}
/*
10 12
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 8
8 9
9 4
9 10
10 1

5 5
1 2
2 3
3 4
4 5
5 1

8 12
1 2
1 3
4 1
2 3
2 4
3 5
6 4
5 7
5 8
7 6
6 8
8 7
*/