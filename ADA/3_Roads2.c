//3_Roads2.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long int ll;

typedef struct node{
    int vertex;
    struct node *next;
} Node;

int queue[100005];
int front = -1, rear = -1;
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

    newNode = createNode(src);
    newNode->next = adjLists[dest];
    adjLists[dest] = newNode;
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

ll Coloring(int N){
	ll ans = 0;
	int color[N + 1];
	for (int v = 1; v <= N; v++){
		color[v] = -1;
	}
	for (int v = 1; v <= N; v++){
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
				Node *temp = adjLists[vertex];
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
		front = -1, rear = -1;
		scanf("%d%d",&N, &M);
		for(int i = 1; i <= N; i++){
			adjLists[i] = NULL;
		}
		for(int i = 0; i < M; i++){
			scanf("%d%d",&u, &v);
			addEdge(u, v);
		}
		ll ans = Coloring(N);
		printf("%lld\n", ans);
	}
	return 0;
}