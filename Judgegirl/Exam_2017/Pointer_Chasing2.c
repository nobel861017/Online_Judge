//Pointer_Chasing.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include "chasing.h"


void chasing(int **A[], int a, int *B[], int b, int C[], int c){
	char str[70];
	while(fget(str, 70,stdin) != NULL){
		
	}
}

int main(){
	int a = 5, b = 4, c = 3;
    int **A[5] = {}, *B[4] = {}, C[3] = {2, 1, 4};
    chasing(A, a, B, b, C, c);

    int **ansA[5] = {} ,*ansB[4] = {};
    for (int i = 0; i < a; i++)
            ansA[i] = NULL;
    for (int i = 0; i < b; i++)
            ansB[i] = NULL;
    ansA[2] = &B[1], ansA[3] = &B[0], ansB[1] = &C[1], ansB[2] = &C[0];
    //ansA[0] = &B[0], ansA[1] = &B[2], ansB[0] = &C[2], ansB[1] = &C[1];
    /*Check A*/
    for (int i = 0; i < a; i++)
            if (A[i] != ansA[i] )
                    printf("A[%d] wrong answer!\n", i);

    /*Check B*/
    for (int i = 0; i < b; i++)
            if (B[i] != ansB[i] )
                    printf("B[%d] wrong answer!\n", i);
    return 0;
}