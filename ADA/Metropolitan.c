//Metropolitan.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    int vertex;
    struct node *next;
} Node;

Node *createNode(int v){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node **adjLists, int src, int dest, int *degree){
    Node *newNode = createNode(dest);
    newNode->next = adjLists[src];
    adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjLists[dest];
    adjLists[dest] = newNode;

    degree[src]++;
    degree[dest]++;
}
void cut_edge(Node **adjLists, int src, int dest, int *degree){
	if(adjLists[src]->vertex == dest){
		adjLists[src] = adjLists[src]->next;
	}
	else{
		Node *tmp = adjLists[src];
		while(tmp){
			if(tmp->next != NULL)
				if(tmp->next->vertex == dest){
					tmp->next = tmp->next->next;
				}
			tmp = tmp->next;
		}
	}
	if(adjLists[dest]->vertex == src){
		adjLists[dest] = adjLists[dest]->next;
	}
	else{
		Node *tmp = adjLists[dest];
		while(tmp){
			if(tmp->next != NULL)
				if(tmp->next->vertex == src){
					tmp->next = tmp->next->next;
				}
			tmp = tmp->next;
		}
	}
	degree[src]--;
    degree[dest]--;	
}
void Traverse(Node **adjLists, int N, int *degree){
	int ans = 0;
	int clock = 0;
	for (int v = 0; v < N; v++){
		if(degree[v] == 0)
			if(ans < 1) ans = 1; 
		if(degree[v] == 1){
			Node *tmp = adjLists[v];
			//puts("d = 1");
			if(ans < 2) ans = 2;
			cut_edge(adjLists,v,tmp->vertex,degree);
			//cut_edge(adjLists,tmp->vertex,v,degree);
			clock++;
			if(clock >= 10000000){
				printf("%d", ans);
				return;
			}
		}
		else if(degree[v] == 2){
			int x, y;
			x = adjLists[v]->vertex;
			/*if(adjLists[v]->next != NULL)
				y = adjLists[v]->next->vertex;
			else continue;*/
			y = adjLists[v]->next->vertex;
			int flag = 0;
			Node *tmp = adjLists[x];
			while(tmp){
				if(tmp->vertex == y){
					flag = 1;
					break;
				}
				tmp = tmp->next;
				clock++;
				if(clock >= 10000000){
					printf("%d", ans);
					return;
				}
			}
			if(flag){
				//puts("d = 2");
				if(ans < 3) ans = 3;
				cut_edge(adjLists,v,x,degree);
				cut_edge(adjLists,v,y,degree);
				//cut_edge(adjLists,x,v,degree);
				//cut_edge(adjLists,y,v,degree);
			}
		}
		else if(degree[v] == 3){
			int x, y, z;
			x = adjLists[v]->vertex;
			/*if(adjLists[v]->next != NULL){
				y = adjLists[v]->next->vertex;
				if(adjLists[v]->next->next != NULL) z = adjLists[v]->next->next->vertex;
				else continue;
			}
			else continue;*/
			y = adjLists[v]->next->vertex;
			z = adjLists[v]->next->next->vertex;
			int flag1 = 0, flag2 = 0, flag3 = 0;
			Node *tmp = adjLists[x];
			while(tmp){
				if(tmp->vertex == y){
					flag1 = 1;
					if(flag1 && flag3) break;
				}
				else if(tmp->vertex == z){
					flag3 = 1;
					if(flag1 && flag3) break;
				}
				tmp = tmp->next;
				clock++;
				if(clock >= 10000000){
					printf("%d", ans);
					return;
				}
			}
			tmp = adjLists[y];
			while(tmp){
				if(tmp->vertex == z){
					flag2 = 1;
					break;
				}
				tmp = tmp->next;
				clock++;
				if(clock >= 10000000){
					printf("%d", ans);
					return;
				}
			}
			if(flag1 && flag2 && flag3){
				//puts("d = 3");
				if(ans < 4) ans = 4;
				cut_edge(adjLists,v,x,degree);
				cut_edge(adjLists,v,y,degree);
				cut_edge(adjLists,v,z,degree);
				//cut_edge(adjLists,x,v,degree);
				//cut_edge(adjLists,y,v,degree);
				//cut_edge(adjLists,z,v,degree);
			}
		}
	}
	printf("%d", ans);
}
/*void printGraph(int N, Node **adjLists){
    for (int v = 0; v < N; v++){
        Node *temp = adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}*/
int main(){
	int N, M, u, v;
	scanf("%d%d", &N, &M);
	int degree[N+1];
	memset(degree, 0, sizeof(degree));
	Node *adjLists[N+1];
	for(int i = 0; i < N; i++) adjLists[i] = NULL;
	for(int i = 0; i < M; i++){
		scanf("%d%d", &u, &v);
		addEdge(adjLists, u, v, degree);
	}
	//printGraph(N,adjLists);
	//for(int i = 0; i < N; i++) printf("degree[%d] = %d\n", i, degree[i]);
	Traverse(adjLists, N, degree);
}