//test_file_reading.c
#include <stdio.h>
#include <string.h>
int main(){
	FILE *fp = fopen("test_file","r");
	char str[10];
	if(!fp) printf("NULL\n");
	fseek(fp,-1,SEEK_END);
	//fseek(fp,-8,SEEK_CUR);
	//fgets(str,9,fp);
	//	printf("str = %s\n",str);
	//char c = fgetc(fp);
	//putchar(c);
	while(!fseek(fp,-1,SEEK_CUR)){
		fseek(fp,-9,SEEK_CUR);
		fgets(str,10,fp);
		//printf("str = %s\n",str);
		if(strcmp(str,"# commit ") == 0){
			printf("find commit\n");
			char c = fgetc(fp);
            putchar(c);
			break;
		}
	}
	
	return 0;
}