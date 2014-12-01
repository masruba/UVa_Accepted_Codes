#include<stdio.h>

int main(){
	double cows, cars, shows;

	while(scanf("%lf%lf%lf",&cows, &cars, &shows) == 3){
		printf("%.5lf\n", (cars*(cars + cows-1)) / ((cars+cows) * (cars+cows-1-shows)));
	}

	return 0;
}