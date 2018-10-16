//Paper_Scissors_Stone.c
#include <stdio.h>
int main(){
	int x, a, b, c, y, d, e, f, n, count = 1;
	int map[3][3] = {{-1,1,0}, {0,-1,1}, {1,0,-1}};
	scanf("%d%d%d%d%d%d%d%d%d", &x, &a, &b, &c, &y, &d, &e, &f, &n);
	while(1){
		//printf("%d %d\n", x%3, y%3);
		if(x%3 != y%3){
			printf("%d %d\n", map[x%3][y%3], count);
			x = (a*x + b)%c, y = (d*y + e)%f;
			count = 1;
			n--;
			if(n == 0) break;
			continue;
		}
		while(x%3 == y%3){
			x = (a*x + b)%c, y = (d*y + e)%f;
			//printf("%d %d\n", x%3, y%3);
			count++;
		}
	}
	return 0;
}