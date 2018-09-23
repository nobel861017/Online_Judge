// Two_level_Table.c
#include <stdio.h>
//#include "constructTable.h"

int **first[100], *second[5000], idx_B = 0, idx_sec = 0, idx_fir = 0;

int ***constructTable(int A[], int B[]){
	for(int i = 0; A[i] != 0; i++){
		first[idx_fir] = &second[idx_sec];
		idx_fir ++;
		for(int j = 0; j < A[i]; j++){
			second[idx_sec] = &B[idx_B];
			idx_sec ++;
			while(B[idx_B] != 0){
				idx_B ++;
			}
			if(B[idx_B] == 0) idx_B ++;
		}
		second[idx_sec] = NULL;
		idx_sec ++;
	}
	first[idx_fir] = NULL;
	return first;
}

int main(){
	int N, M;
    int A[100] = {}, B[500] = {};
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &B[i]);
 
    int ***ptr;
    ptr = constructTable(A, B);
    for(int i = 0; *(ptr+i) != NULL; i++)
        for(int j = 0; j < A[i]; j++)
            for(int k = 0; *(*(*(ptr+i)+j)+k) != 0; k++)
                printf("%d ", *(*(*(ptr+i)+j)+k));
	return 0;
}