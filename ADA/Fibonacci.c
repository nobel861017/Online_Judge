//Fibonacci.c
#include <stdio.h>

void Matrix(long long *a, long long *b, long long *c, long long *d){
	a[0] = 1, b[0] = 1, c[0] = 1, d[0] = 0;
	for (int i = 1; i <= 30;i++){
		int idx = i-1;
		a[i] = (a[idx]*a[idx]%1000000007+b[idx]*c[idx]%1000000007) % 1000000007;
		b[i] = (a[idx]*b[idx]%1000000007+b[idx]*d[idx]%1000000007) % 1000000007;
		c[i] = (a[idx]*c[idx]%1000000007+c[idx]*d[idx]%1000000007) % 1000000007;
		d[i] = (b[idx]*c[idx]%1000000007+d[idx]*d[idx]%1000000007) % 1000000007;
		//printf("|a[%d] b[%d]| |%lld %lld|\n",i,i,a[i],b[i]);
		//printf("|c[%d] d[%d]| |%lld %lld|\n",i,i,c[i],d[i]);
	}
}
int main(){
	long long a[32], b[32], c[32], d[32];
	//	|a b|
	//	|c d|
	Matrix(a,b,c,d);
	int T;
	long long a0, b0, n;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&a0,&b0,&n);
		long long x = 1;
		if(n == 1){
			printf("%lld\n",a0);
			continue;
		}
		long long A = 1,B = 0,C = 0,D = 1;
		//printf("%d %d\n",x <= (n-2),x&(n-2));
		for(x = 1; x <= (n-2); x *= 2){
			if(!(x&(n-2))) continue;
			int idx = 0;
			long long tmp = x;
			long long Atmp,Btmp,Ctmp,Dtmp;
			while((tmp/=2) >= 1) idx++;
			Atmp = (A*a[idx]%1000000007+C*b[idx]%1000000007)%1000000007;
			Btmp = (B*a[idx]%1000000007+D*b[idx]%1000000007)%1000000007;
			Ctmp = (A*c[idx]%1000000007+C*d[idx]%1000000007)%1000000007;
			Dtmp = (B*c[idx]%1000000007+D*d[idx]%1000000007)%1000000007;
			A = Atmp, B = Btmp, C = Ctmp, D = Dtmp;
			//printf("|%lld %lld|\n",A,B);
			//printf("|%lld %lld|\n",C,D);
		}
		long long ans;
		ans = (A*b0%1000000007 + B*a0%1000000007)%1000000007;
		printf("%lld\n",ans);
	}
	return 0;
}