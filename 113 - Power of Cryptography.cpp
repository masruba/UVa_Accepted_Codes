#include<stdio.h>
#include<math.h>

int main(){
	long double p,result;
	double n;

	while(scanf("%lf%Lf",&n,&p)==2){
		result = pow(p,1/n);
		printf("%.Lf\n",result);
	}

	return 0;
}