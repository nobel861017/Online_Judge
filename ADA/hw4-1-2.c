#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char string[3][3010];
int set[1010][3][2], voc_to_num[27], num_to_voc[27], num_index;
void print_bit(int n){
	for(int i = 1<<26;i;i=i>>1)
		printf(n&i?"1":"0");
	printf("\n");
	return;
}
void print(){
	int i, j;
	/*
	for(i=0;i<3;i++){
		for(j=0;j<n;j++){
			printf("%2d %2d, ", set[j][i][0], set[j][i][1]);
		}
		printf("\n");
	}
	*/
	for(i=1;i<27;i++)
		printf(" %c ", 'A'+i-1);
	printf("\n");
	for(i=1;i<27;i++)
		printf("%2d ", voc_to_num[i]);
	printf("\n");
	for(i=1;i<num_index;i++)
		printf("%2d ", num_to_voc[i]);
	printf("\n");
	return;
}
int main (int argc, char *argv[]) {
	int T, n, i, j, k, tmp, check[2], find, mask, min_fail, fail, min_fail_index, mask_try, mytime;
	srand(time(NULL));
	scanf("%d", &T);
	while(T--){
		for(i=1;i<27;i++)
			voc_to_num[i] = 0;
		num_index = 1;
		scanf("%d%s%s%s", &n, string[0], string[1], string[2]);
		for(i=0;i<3;i++){
			for(j=0;j<n;j++){
				if(string[i][3*j+1]<91){
					tmp = string[i][3*j+1] - 'A' + 1;
					if(!voc_to_num[tmp]){
						voc_to_num[tmp] = num_index;
						num_to_voc[num_index] = tmp;
						num_index++;
					}
					set[j][i][0] = voc_to_num[tmp];
				} 
				else{
					tmp = string[i][3*j+1] - 'a' + 1;
					if(!voc_to_num[tmp]){
						voc_to_num[tmp] = num_index;
						num_to_voc[num_index] = tmp;
						num_index++;
					}
					set[j][i][0] = -voc_to_num[tmp];
				} 
				if(string[i][3*j+2]<91){
					tmp = string[i][3*j+2] - 'A' + 1;
					if(!voc_to_num[tmp]){
						voc_to_num[tmp] = num_index;
						num_to_voc[num_index] = tmp;
						num_index++;
					}
					set[j][i][1] = voc_to_num[tmp];
				} 
				else{
					tmp = string[i][3*j+2] - 'a' + 1;
					if(!voc_to_num[tmp]){
						voc_to_num[tmp] = num_index;
						num_to_voc[num_index] = tmp;
						num_index++;
					}
					set[j][i][1] = -voc_to_num[tmp];
				} 
			}
		}
		//print(n);
		find = 0;
		for(mytime=0;mytime<40 && !find;mytime++){
			mask = rand();
			for(k=0;k<26&&!find;k++){
				min_fail = n;
				for(j=1;j<num_index;j++){
					mask_try = mask^(1<<j);
					fail = 0;
					for(i=0;i<n;i++){
						tmp = set[i][0][0];
						check[0] = ( (tmp>0 && !(mask_try&(1<<tmp))) || (tmp<0 && (mask_try&(1<<-tmp))) )?1:0;
						tmp = set[i][0][1];
						check[1] = ( (tmp>0 && !(mask_try&(1<<tmp))) || (tmp<0 && (mask_try&(1<<-tmp))) )?1:0;
						if(check[0]&&check[1])
							continue;
						tmp = set[i][1][0];
						check[0] = ( (tmp>0 && !(mask_try&(1<<tmp))) || (tmp<0 && (mask_try&(1<<-tmp))) )?1:0;
						tmp = set[i][1][1];
						check[1] = ( (tmp>0 && !(mask_try&(1<<tmp))) || (tmp<0 && (mask_try&(1<<-tmp))) )?1:0;
						if(check[0]&&check[1])
							continue;
						tmp = set[i][2][0];
						check[0] = ( (tmp>0 && !(mask_try&(1<<tmp))) || (tmp<0 && (mask_try&(1<<-tmp))) )?1:0;
						tmp = set[i][2][1];
						check[1] = ( (tmp>0 && !(mask_try&(1<<tmp))) || (tmp<0 && (mask_try&(1<<-tmp))) )?1:0;
						if(check[0]&&check[1])
							continue;
						fail++;
					}
					if(fail <= min_fail){
						min_fail = fail;
						min_fail_index = j;
					}
				}
				if(min_fail == 0)
					find = 1; 
				mask = mask^(1<<min_fail_index);
			}
		}
		if(find){
			//print_bit(mask);
			//print();
			tmp = 0;
			for(i=(1<<(num_index-1));i>1;i=i>>1)
				if(mask&i)
					tmp++;
			printf("%d", tmp);
			for(i=num_index-1;i>0;i--)
				if(mask&(1<<i)){
					printf(" %c", num_to_voc[i]+'A'-1);
					//printf(" %d", i);
				}
			printf("\n");
		}
		else{
			printf("-1\n");
		}
		
	}
	return 0;
}

