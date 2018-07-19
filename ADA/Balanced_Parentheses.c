//Balanced_Parentheses.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define swap(a,b)  {int temp = a; a = b; b = temp;}

int heap_size = 0;

int Left(int i){
	return 2*i;
}
int Right(int i){
	return 2*i+1;
}

void Min_Heapify(int A[],int i){
	int l = Left(i);
	int r = Right(i);
	int smallest;
	if(l <= heap_size && A[l] < A[i]){
		smallest = l;
	}
	else smallest = i;
	if(r <= heap_size && A[r] < A[smallest]){
		smallest = r;
	}
	if(smallest != i){
		swap(A[i],A[smallest]);
		Min_Heapify(A,smallest);
	}
}
int HEAP_EXTRACT_MIN(int A[]){
	if(heap_size < 1) fprintf(stderr,"heap underflow\n");
	int min = A[1];
	A[1] = A[heap_size];
	heap_size--;
	Min_Heapify(A,1);
	return min;
}
void HEAP_DECREASE_KEY(int A[], int i, int key){
	//if(key > A[i]) fprintf(stderr,"new key is larger than current key\n");
	A[i] = key;
	while(i > 1 && A[i/2] > A[i]){
		swap(A[i],A[i/2]);
		i /= 2; 
	}
}
void MIN_HEAP_INSERT(int A[], int key){
	heap_size++;
	A[heap_size] = INT_MIN;
	HEAP_DECREASE_KEY(A,heap_size,key);
}

int main(){
	unsigned long long total_cost = 0;
	char S[1000005];
	int l[1005], r[1005], A[1005];
	memset(S,0,sizeof(S));
	int idx = 0, counter = 0, prefix_sum = 0;
	scanf("%s",S);
	int len = strlen(S);
	while(scanf("%d%d",&l[idx],&r[idx]) != EOF){
		idx++;
	}
	//puts(S);
	//for(int i=0;i<idx;i++) printf("l[%d] = %d, r[%d] = %d\n",i,l[i],i,r[i]);
	for(int i = 0; i < len; i++){
		//printf("i = %d\n",i);
		if(S[i] == '('){
			prefix_sum++;
		}
		else if(S[i] == ')'){
			prefix_sum--;
			if(prefix_sum < 0){
				if(heap_size == 0){
					puts("Impossible");
					exit(0);
				}
				else{
					prefix_sum += 2;
					total_cost += HEAP_EXTRACT_MIN(A);
				}
			}
		}
		else if(S[i] == '?'){	//	一律先當成')'
			prefix_sum--;
			//fprintf(stderr,"差：%d, counter = %d\n",l[counter] - r[counter],counter);
			MIN_HEAP_INSERT(A,l[counter] - r[counter]);
			total_cost += r[counter];
			if(prefix_sum >= 0){
				S[i] = ')';
				counter++;
				continue;
			}
			else if(prefix_sum < 0){
				if(heap_size == 0){
					puts("Impossible");
					exit(0);
				}
				int tmp = HEAP_EXTRACT_MIN(A);
				total_cost += tmp;
				//fprintf(stderr,"tmp = %d\n",tmp);
				//fprintf(stderr,"A[1] = %d, A[2] = %d\n",A[1],A[2]);
				//total_cost += HEAP_EXTRACT_MIN(A);
				prefix_sum += 2;
			}
			counter++;
		}
	}
	if(prefix_sum != 0) puts("Impossible");
	else printf("%llu",total_cost);

	return 0;
}