//Tower_of_Hanoi.c
#include <stdio.h>
unsigned long long flag;
void Hanoi(int n,unsigned long long l,unsigned long long r,int src,int buf,int des,unsigned long long head,unsigned long long tail){
	unsigned long long x = (1 << n) - 1;
	if(n == 1){
		flag++;
		if(flag <= r && flag >= l)
			printf("Step %llu: #%d -> #%d\n",flag,src,des);
		return;
	}
	else{
		//  head ~ head+(x-3)/2	 (head + tail)/2	tail-(x-3)/2 ~ tail
		//printf("x = %d\n",x);
		if(!(l > (head+(x-3)/2) ) )
			Hanoi(n-1,l,r,src,des,buf,head,head+(x-3)/2);
		else flag += (x-1)/2;

		if((head + tail)/2 >= l && (head + tail)/2 <= r)
			Hanoi(1,l,r,src,buf,des,(head + tail)/2,(head + tail)/2);
		else flag++;

		if(!(r < (tail-(x-3)/2) ) )
			Hanoi(n-1,l,r,buf,src,des,tail-(x-3)/2,tail);
		else flag += (x-1)/2;
	}
}
int main(){
	int T,n;
	unsigned long long l, r;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d%llu%llu",&n,&l,&r);
		printf("Case #%d:\n",i+1);
		flag = 0;
		Hanoi(n,l,r,1,2,3,1,(1 << n) - 1);
	}
	return 0;
}