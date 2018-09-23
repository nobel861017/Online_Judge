// Count_Pointers.c
#include <stdio.h>
#include <stdlib.h>
// #include "count.h"
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512

typedef struct{
	int num;
	int count;
	int *add;
} Pair;


static int cmp(const void *a, const void *b){
	int c = (*(Pair*)a).count;
	int d = (*(Pair*)b).count;
	if(c != d) return c > d;
	else{
		int e = (*(Pair*)a).num;
		int f = (*(Pair*)b).num;
		return e > f;
	}

}

void count(int **p[]){
	int ***ptr = p, idx = 0;
	Pair a[MAX_NUM_INTVAR] = {0, 0, NULL};
	while(*ptr != NULL){
		int find = 0;
		for(int i = 0; i < idx; i++){
			if(a[i].add == **ptr){
				a[i].count++;
				find = 1;
			}
		}
		if(find == 0){
			a[idx].num = ***ptr;
			a[idx].count ++;
			a[idx].add = **ptr;
			idx++;
		}
		ptr++;
	}
	qsort(a, idx, sizeof(Pair), cmp);
	for(int i = 0; i < idx; i++) if(a[i].count) printf("%d %d\n", a[i].num, a[i].count);
}

int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 7;
  intVar[2] = 6;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[2];
  ptrArray[4] = &intPtr[3];
  ptrArray[5] = &intPtr[4];
  ptrArray[6] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[2];
  intPtr[4] = &intVar[1];

 
  count(ptrArray);
  //printf("Still alive in main.\n");
  return 0;
}