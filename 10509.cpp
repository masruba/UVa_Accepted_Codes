#include<stdio.h>

int main(){
	int i;
	double n;
	double m;

	while(scanf("%lf",&n) == 1 && n){
		i = 0;

		while(1){
			if(i*i*i > n)
				break;
			i++;
		}
		
		i--;
		
		m = (n - i*i*i)/(3*i*i);
		printf("%.04lf\n",i + m);

	}

	return 0;
}