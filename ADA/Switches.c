//Switches.c
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

char str[3][3010];
int lock[1010][3][2], a_to_i[27], i_to_a[27], num_of_character, T, M, tmp, check[2], found, mask, min_fail_times, fail, min_fail_times_index, cur_mask;

void print_ans(){
	int counter = 0;
	for(int i = ( 1 << (num_of_character - 1)); i > 1; i >>= 1)
		if(mask & i) counter++;
	printf("%d", counter);
	for(int i = num_of_character - 1; i > 0; i--)
		if( mask & (1 << i)) printf(" %c", i_to_a[i] + 'A' - 1);
	puts("");
}

void parse(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < M; j++){
			if(str[i][3*j + 1] < 91){
				tmp = str[i][3*j + 1] - 'A' + 1;
				if(!a_to_i[tmp]){
					a_to_i[tmp] = num_of_character;
					i_to_a[num_of_character] = tmp;
					num_of_character++;
				}
				lock[j][i][0] = a_to_i[tmp];
			} 
			else{
				tmp = str[i][3*j+1] - 'a' + 1;
				if(!a_to_i[tmp]){
					a_to_i[tmp] = num_of_character;
					i_to_a[num_of_character] = tmp;
					num_of_character++;
				}
				lock[j][i][0] = -a_to_i[tmp];
			} 
			if(str[i][3*j + 2] < 91){
				tmp = str[i][3*j + 2] - 'A' + 1;
				if(!a_to_i[tmp]){
					a_to_i[tmp] = num_of_character;
					i_to_a[num_of_character] = tmp;
					num_of_character++;
				}
				lock[j][i][1] = a_to_i[tmp];
			} 
			else{
				tmp = str[i][3*j + 2] - 'a' + 1;
				if(!a_to_i[tmp]){
					a_to_i[tmp] = num_of_character;
					i_to_a[num_of_character] = tmp;
					num_of_character++;
				}
				lock[j][i][1] = -a_to_i[tmp];
			}
		}
	}
}

void Test(){
	found = 0;
	for(int z = 0; z < 40; z++){
		if(found) return;
		mask = rand();
		for(int k = 0; k < 26; k++){
			if(found) return;
			min_fail_times = M;
			for(int j = 1; j < num_of_character; j++){
				cur_mask = mask^(1 << j);
				fail = 0;
				for(int i = 0; i < M; i++){
					tmp = lock[i][0][0];
					check[0] = ( (tmp > 0 && !(cur_mask & (1 << tmp))) || (tmp < 0 && (cur_mask & (1 << -tmp))) ) ? 1 : 0;
					tmp = lock[i][0][1];
					check[1] = ( (tmp > 0 && !(cur_mask & (1 << tmp))) || (tmp < 0 && (cur_mask & (1 << -tmp))) ) ? 1 : 0;
					if(check[0] && check[1]) continue;
					tmp = lock[i][1][0];
					check[0] = ( (tmp > 0 && !(cur_mask & (1 << tmp))) || (tmp < 0 && (cur_mask & (1 << -tmp))) ) ? 1 : 0;
					tmp = lock[i][1][1];
					check[1] = ( (tmp > 0 && !(cur_mask & (1 << tmp))) || (tmp < 0 && (cur_mask & (1 << -tmp))) ) ? 1 : 0;
					if(check[0] && check[1]) continue;
					tmp = lock[i][2][0];
					check[0] = ( (tmp > 0 && !(cur_mask & (1 << tmp))) || (tmp < 0 && (cur_mask & (1 << -tmp))) ) ? 1 : 0;
					tmp = lock[i][2][1];
					check[1] = ( (tmp > 0 && !(cur_mask & (1 << tmp))) || (tmp < 0 && (cur_mask & (1 << -tmp))) ) ? 1 : 0;
					if(check[0] && check[1]) continue;
					fail++;
				}
				if(fail <= min_fail_times){
					min_fail_times = fail, min_fail_times_index = j;
				}
			}
			if(min_fail_times == 0) found = 1; 
			mask ^= (1 << min_fail_times_index);
		}
	}
}

int main(){
	srand(time(NULL));
	scanf("%d", &T);
	while(T--){
		num_of_character = 1;
		memset(a_to_i, 0, sizeof(a_to_i));
		scanf("%d%s%s%s", &M, str[0], str[1], str[2]);
		parse();
		Test();
		if(found) print_ans();
		else puts("-1");
	}
	return 0;
}

