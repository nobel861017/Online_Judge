//Pointer_Chasing.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//#include "chasing.h"

int isint(char *s1, char *s2){
    int len = strlen(s1);
    for(int i = 0; i < len; i++){
        if(!isdigit(s1[i])){
            //printf("%c ", s1[i]);
            return 0;
        }
    }
    len = strlen(s2);
    for(int i = 0; i < len - 1; i++){
        if(!isdigit(s2[i])){
            //printf("%c ", s1[i]);
            return 0;
        }
    }
    return 1;
}

void chasing(int **A[], int a, int *B[], int b, int C[], int c){
	char line[70], *str[5];
    memset(A, 0, sizeof(A[0])*a);
    memset(B, 0, sizeof(B[0])*b);
	while(fgets(line, 70, stdin) != NULL){
        int idx = 0, flag = 1;
		str[0] = strtok(line, " ");
        for(int i = 1; i < 5; i++) str[i] = strtok(NULL, " ");
        //printf("%s %s %s %s", str[0],str[1],str[2],str[3]);
        for(int i = 0; i < 4; i++) if(str[i] == NULL) flag = 0;
        if(str[4] != NULL) flag = 0;
        if(flag == 0){
            //fprintf(stderr, "too many variables!\n");
            puts("0");
            continue;
        }
        if(str[0][0] == 'A' || str[0][0] == 'B'){
            if(str[0][0] == 'A' && str[2][0] == 'B'){
                //printf("%s %s", str[1], str[3]);
                if(!isint(str[1], str[3])){
                    //fprintf(stderr, "wrong int format!\n");
                    puts("0");
                    continue;
                }
                int n1 = atoi(str[1]), n2 = atoi(str[3]);
                //printf("n1 = %d, n2 = %d\n", n1, n2);
                if(n1 >= a || n2 >= b){
                    //fprintf(stderr, "out of bounds!\n");
                    puts("0");
                    continue;
                }
                A[n1] = &B[n2];
                puts("1");
                continue;
            }
            else if(str[0][0] == 'B' && str[2][0] == 'C'){
                //printf("%s %s", str[1], str[3]);
                if(!isint(str[1], str[3])){
                    //fprintf(stderr, "wrong int format!\n");
                    puts("0");
                    continue;
                }
                int n1 = atoi(str[1]), n2 = atoi(str[3]);
                if(n1 >= b || n2 >= c){
                    //fprintf(stderr, "out of bounds!\n");
                    puts("0");
                    continue;
                }
                B[n1] = &C[n2];
                puts("1");
                continue;
            }
            else{
                //fprintf(stderr, "wrong char format!!\n");
                puts("0");
                continue;
            }
        }
        else{
            //fprintf(stderr, "wrong char format!!\n");
            puts("0");
            continue;
        }
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
    //ansA[2] = &B[1], ansA[3] = &B[0], ansB[1] = &C[1], ansB[2] = &C[0];
    //ansA[0] = &B[0], ansA[1] = &B[2], ansB[0] = &C[2], ansB[1] = &C[1];
    ansA[0] = &B[1];;
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