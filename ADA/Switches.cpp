//Switches.cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <random>
using namespace std;
int switch_ans;
char cell[3][3005];
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> num(1, (1 << 26) - 1);
void print_2(int x){
	for(int i = 0; i < 26; i++){
		printf("%d",(x & (1 << (25 - i))) != 0);
	}
	puts("");
}
int Test(int M){
	for(int z = 0; z < 40; z++){
		int ran_num = num(gen);
		//print_2(ran_num);
		int s = ran_num;
		for(int y = 0; y < 26; y++){
			for(int x = 0; x < 26; x++){
				s = ran_num;
				if((ran_num & (1 << x)) != 0) s &= ~(1 << x);
				else s |= (1 << x);
				int total_flag = 1;
				for(int i = 0; i < M; i++){
					int flag = 0, c[3][2];
					for(int j = 0; j < 3; j++){
						if(islower(cell[j][3*i+1]) && (s & (1 << (cell[j][3*i+1] - 'a'))) != 0){
							c[j][0] = toupper(cell[j][3*i+1]);
						}
						else c[j][0] = cell[j][3*i+1];
						if(islower(cell[j][3*i+2]) && (s & (1 << (cell[j][3*i+2] - 'a'))) != 0){
							c[j][1] = toupper(cell[j][3*i+2]);
						}
						else c[j][1] = cell[j][3*i+2];
						if(isupper(cell[j][3*i+1]) && (s & (1 << (cell[j][3*i+1] - 'A'))) != 0){
							c[j][0] = tolower(cell[j][3*i+1]);
						}
						else c[j][0] = cell[j][3*i+1];
						if(isupper(cell[j][3*i+2]) && (s & (1 << (cell[j][3*i+2] - 'A'))) != 0){
							c[j][1] = tolower(cell[j][3*i+2]);
						}
						else c[j][1] = cell[j][3*i+2];
						if(isupper(c[j][0]) && isupper(c[j][1])){
							flag = 1;
							break;
						}
					}
					if(flag == 0){
						total_flag = 0;
						break;
					}
				}
				if(total_flag == 0) continue;
				else{
					switch_ans = s;
					return 1;
				}
			}
			ran_num = s;
		}
	}
	return 0;
}
void print_ans(int x){
	int count = 0;
	for(int i = 0; i < 26; i++){
		if((x & (1 << i)) != 0) count++;
	}
	printf("%d", count);
	for(int i = 0; i < 26; i++){
		if((x & (1 << i)) != 0){
			printf(" %c", i + 65);
		}
	}
	puts("");
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, M;
	scanf("%d", &T);
	while(T--){
		memset(cell, 0, sizeof(cell));
		scanf("%d",&M);
		for(int i = 0; i < 3; i++){
			scanf("%s", cell[i]);
			//for(int j = 0; j < 3*M + 1; j++) scanf("%c", &cell[i][j]);
		}
		if(Test(M) == 1){
			print_ans(switch_ans);
		}
		else puts("-1");
	}
	return 0;
}