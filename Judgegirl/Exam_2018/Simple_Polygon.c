//Simple_Polygon.c
#include <stdio.h>
#include <limits.h>
int main(){
	int x[4], y[4], x_max = INT_MIN, x_min = INT_MAX, y_max = INT_MIN, y_min = INT_MAX, per, area;
	for(int i = 0; i < 4; i++) scanf("%d%d", &x[i], &y[i]);
	for(int i = 0; i < 4; i++){
		if(x[i] > x_max) x_max = x[i];
		if(y[i] > y_max) y_max = y[i];
		if(x[i] < x_min) x_min = x[i];
		if(y[i] < y_min) y_min = y[i];
	}
	per = 2*(x_max - x_min + y_max - y_min);
	area = (x_max - x_min)*(y_max - y_min) - (y[1] - y[0])*(x[2] - x[1]) - (x[3] - x[0])*(y[2] - y[3]);
	printf("%d\n%d\n", per, area);
	return 0;
}