//Flee.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
	WAIT = 0x01,
	VISITED = 0x02,
} Status;

typedef struct queue{
	char c;
	int x;
	int y;
	int d;
} Queue;

int R, C;
int front = -1, rear = -1;
int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
int status[3010][3010], dis[3010][3010];
char graph[3010][3010];
Queue queue[9000010];
int Is_Empty(){
	if(front == -1 || front > rear) return 1;
	else return 0;
}
void Insert(char c, int i, int j, int d){
    if(front == -1) front = 0;
    rear++;
    queue[rear].c = c;
    queue[rear].x = i;
    queue[rear].y = j;
    queue[rear].d = d;
}

Queue dq(){
	Queue vertex;
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        exit(1);
    }
    vertex = queue[front];
    front++;
    return vertex;
}

void BFS(char c, int x, int y, int depth){
	Insert(c,x,y,0);
	//printf("Insert: (%d,%d)\n",x,y);
	status[x][y] = WAIT;
	while(!Is_Empty()){
		Queue v = dq();
		//printf("%c ,d = %d\n",v.c, v.d);
		if(v.c == 'P' && dis[v.x][v.y] > v.d){
			dis[v.x][v.y] = v.d;
		}
		status[v.x][v.y] = VISITED;
		for(int i = 0; i < 4; i++){
			int id1 = v.x + dir[i][0];
			int id2 = v.y + dir[i][1];
			if(id1 < 0 || id2 < 0 || id1 >= R || id2 >= C) continue;
			if(status[id1][id2] == 0 && graph[id1][id2] != 'F'){
				Insert(graph[id1][id2], id1, id2, v.d + 1);
				status[id1][id2] = WAIT;
			}
		}
	}
}

int main(){
	char str[3010];
	scanf("%d%d", &R, &C);
	for(int i = 0; i < R; i++){
		scanf("%s",str);
		for(int j = 0; j < C; j++){
			graph[i][j] = str[j];
		}
	}
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			dis[i][j] = 2147483647;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if( graph[i][j] == 'E'){
				memset(status, 0, sizeof(status));
				BFS(graph[i][j], i, j, 0);
			}
		}
	}
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++){
			if(graph[i][j] == 'P'){
				if(dis[i][j] == 2147483647) puts("Died");
				else printf("%d\n",dis[i][j]);
				//printf("%c %d\n",graph[i][j],dis[i][j]);
			}
		}
	return 0;
}
