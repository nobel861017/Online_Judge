//3_Roads.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long int ll;

typedef struct node{
    int vertex;
    struct node *next;
} Node;

typedef struct graph{
    int numVertices;
    Node** adjLists;
} Graph;

int queue[100005];
int front = -1, rear = -1;

Node *createNode(int v){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices){
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;
    g->adjLists = (Node**)malloc((vertices+1) * sizeof(Node));
    for (int i = 1; i <= vertices; i++)
        g->adjLists[i] = NULL;
    return g;
}

void addEdge(Graph *g, int src, int dest){
    Node *newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

void printGraph(Graph *graph){
    for (int v = 1; v <= graph->numVertices; v++){
        Node *temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int Is_Empty(){
	if(front == -1 || front > rear) return 1;
	else return 0;
}
void Insert(int v){
    if(front == -1) front = 0;
    rear++;
    queue[rear]= v;
}

int dq(){
	int vertex;
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        exit(1);
    }
    vertex = queue[front];
    front++;
    return vertex;
}

ll Coloring(Graph *graph){
	ll ans = 0;
	int color[graph->numVertices + 1];
	//memset(color, -1, sizeof(color));
	for (int v = 1; v <= graph->numVertices; v++){
		color[v] = -1;
	}
	for (int v = 1; v <= graph->numVertices; v++){
		if(color[v] != -1) continue;
		else{
			Insert(v);
			color[v] = 0;
			ll type = 1;
			ll edge_num = 0;
			ll ver_num_0 = 1, ver_num_1 = 0;
			while(!Is_Empty()){
				int vertex = dq();
				//printf("vertex = %d\n", vertex);
				Node *temp = graph->adjLists[vertex];
				//temp = temp->next;
				while(temp != NULL){
					//printf("vertex = %d\n", temp->vertex);
					edge_num++;
					//printf("color[%d] = %d\n", temp->vertex, color[temp->vertex]);
					if(color[temp->vertex] == -1){
						color[temp->vertex] = (color[vertex] == 0) ? 1 : 0;
						//printf("color[%d] = %d\n", temp->vertex, color[temp->vertex]);
						//(color[temp->vertex] == 0) ? ver_num_0++ : ver_num_1++;
						if(color[temp->vertex] == 0) ver_num_0++;
						else ver_num_1++;
						Insert(temp->vertex);
					}
					else if(color[temp->vertex] != -1){
						if(color[temp->vertex] == color[vertex]) type = 0;
					}
					temp = temp->next;
				}
			}
			//printf("-----\ntype = %d, ver_num_0 = %d, ver_num_1 = %d, color[%d] = %d\n----\n", type, ver_num_0, ver_num_1, v, color[v]);
			if(type){
				ans += ver_num_0*ver_num_1 - edge_num/2;
			}
			else{
				ans += (ver_num_0 + ver_num_1)*(ver_num_0 + ver_num_1 - 1)/2 - edge_num/2;
			}
		}
		
	}
	return ans;
}

int main(){
	int T, N, M, u, v;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N, &M);
		Graph *g = createGraph(N);
		for(int i = 0; i < M; i++){
			scanf("%d%d",&u, &v);
			addEdge(g, u, v);
		}
		//printGraph(g);
		ll ans = Coloring(g);
		printf("%lld\n", ans);
	}
	return 0;
}