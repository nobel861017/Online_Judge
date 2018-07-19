//Robot_Simulation.c
#include <stdio.h>
int main(){
	int x_max, y_max, n, x = 0, y = 0;
	scanf("%d%d",&x_max, &y_max);
	printf("0\n0\n");
	while(scanf("%d", &n) != EOF){
		switch(n%5){
			case 0:
				break;
			case 1:
				if(x+n < x_max){
					x += n;
					printf("%d\n%d\n", x, y);
				}
				break;
			case 2:
				if(x-n >= 0){
					x -= n;
					printf("%d\n%d\n", x, y);
				}
				break;
			case 3:
				if(y+n < y_max){
					y += n;
					printf("%d\n%d\n", x, y);
				}
				break;
			case 4:
				if(y-n >= 0){
					y -= n;
					printf("%d\n%d\n", x, y);
				}
				break;
		}
	}
}