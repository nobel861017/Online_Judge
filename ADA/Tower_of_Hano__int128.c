//Tower_of_Hano__int128.c
#include <stdio.h>
__int128 flag;
void Hanoi(int n,unsigned long long l,unsigned long long r,int src,int buf,int des,__int128 head,__int128 tail){
	__int128 x = ((__int128)1 << n) - 1;
	if(n == 1){
		flag++;
		if(flag <= r && flag >= l)
			printf("Step %llu: #%d -> #%d\n",(unsigned long long)flag,src,des);
		return;
	}
	else{
		//  head ~ head+(x-3)/2	 (head + tail)/2	tail-(x-3)/2 ~ tail
		//printf("x = %d\n",x);
		__int128 y = (x-1)/2;
		__int128 z = (x-3)/2;
		if(!(l > (head+z)) )
			Hanoi(n-1,l,r,src,des,buf,head,head+z);
		else flag += y;
		flag++;
		if((head + tail)/2 >= l && (head + tail)/2 <= r){
			//Hanoi(1,l,r,src,buf,des,(head + tail)/(__int128)2,(head + tail)/(__int128)2);
			//flag++;
			if(flag <= r && flag >= l)
				printf("Step %llu: #%d -> #%d\n",(unsigned long long)flag,src,des);
		}
		//else flag++;

		if(!( r < (tail-z) ))
			Hanoi(n-1,l,r,buf,src,des,tail-z,tail);
		else flag += y;
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
		Hanoi(n,l,r,1,2,3,1,((__int128)1 << n) - 1);
	}
	return 0;
}