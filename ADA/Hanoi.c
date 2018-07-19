//Hanoi.c
#include <stdio.h>
int flag;
void Hanoi(int n,int src,int buf,int des){
	if(n == 1){
		flag++;
			printf("Step %d: #%d -> #%d\n",flag,src,des);
	}
	else{
		Hanoi(n-1,src,des,buf);
		Hanoi(1,src,buf,des);
		Hanoi(n-1,buf,src,des);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	flag = 0;
	Hanoi(n,1,2,3);
	return 0;
}