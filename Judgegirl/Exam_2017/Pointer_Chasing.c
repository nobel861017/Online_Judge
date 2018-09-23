//Pointer_Chasing.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include "chasing.h"

int first = 1, first_int = 1, pre_is_char = 0, pre_is_int = 0, pre_int = -1, cur_int = -1;

void read_all(){
	char c;
	first = 1, first_int = 1, pre_is_char = 0, pre_is_int = 0, pre_int = -1, cur_int = -1;
	while(scanf("%c", &c) != EOF){
		if(c == '\n') return;
	}
}

int link(int **A[], int *B[], int C[], char char1, char char2, int int1, int int2, int a, int b, int c){
	//fprintf(stderr, "%c[%d] = &%c[%d]\n", char1, int1, char2, int2);
	if(char1 == 'A'){
		if(int1 > a || int2 > b){
			//read_all();
			//fprintf(stderr,"index out of bounds!!\n");
			return 0;
		}
		A[int1] = &B[int2];
		return 1;
	}
	else if(char1 == 'B'){
		if(int1 > a || int2 > b){
			//read_all();
			//fprintf(stderr,"index out of bounds!!\n");
			return 0;
		}
		B[int1] = &C[int2];
		return 1;
	}
}

void chasing(int **A[], int a, int *B[], int b, int C[], int c){
	char ch, pre_char, cur_char;
	for (int i = 0; i < a; i++) A[i] = NULL;
    for (int i = 0; i < b; i++) B[i] = NULL;
	while(scanf("%c", &ch) != EOF){
		if(ch == ' ') continue;
		if(first){
			if(ch != 'A' && ch != 'B' && ch != 'C'){
				read_all();
				//fprintf(stderr,"first is not char!!\n");
				puts("0");
				continue;
			}
			pre_char = ch;
		}
		// printf("%c", ch);
		if(isdigit(ch)){
			//fprintf(stderr, "first_int = %d\n", first_int);
			//fprintf(stderr, "%c is digit!!\n", ch);
			if(pre_is_int){
				read_all();
				//fprintf(stderr,"%c pre should be char!!\n", ch);
				puts("0");
				continue;
			}
			pre_is_int = 1, pre_is_char = 0;
			if(first_int){
				//fprintf(stderr, "int1 = %c\n", ch);
				pre_int = atoi(&ch);
				first_int = 0;
			}
			else cur_int = atoi(&ch);
		}
		else if(ch == 'A' || ch == 'B' || ch == 'C'){
			if(pre_is_char){
				read_all();
				//fprintf(stderr,"%c pre should be int!!\n", ch);
				puts("0");
				continue;
			}
			pre_is_char = 1, pre_is_int = 0;
			if(first){
				if(ch == 'C'){
					read_all();
					//fprintf(stderr, "C Invalid level pointer!!\n");
					puts("0");
					continue;
				}
				pre_char = ch;
			}
			else{
				cur_char = ch;
				//fprintf(stderr,"pre_char = %d, cur_char = %d\n", pre_char, cur_char);
				if(cur_char != pre_char + 1){
					read_all();
					//fprintf(stderr, "Invalid level pointer!!\n");
					puts("0");
					continue;
				}
				
			}
		}
		else if(ch == '\n'){
			if(cur_int == -1){
				read_all();
				//fprintf(stderr,"Varible num invalid!!\n");
				puts("0");
			}
			int rt = link(A, B, C, pre_char, cur_char, pre_int, cur_int, a, b, c);
			first = 1, first_int = 1, pre_is_char = 0, pre_is_int = 0, pre_int = -1, cur_int = -1;
			if(rt) puts("1");
			else puts("0");
			continue;
		}
		else if(!(48 <= ch && ch <= 57) || !(65 <= ch && ch <= 67)){
			read_all();
			//fprintf(stderr,"%c is invalid!!\n", ch);
			puts("0");
			continue;
		}
		first = 0;
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