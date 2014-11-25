#include<stdio.h>
#include<math.h>

#define min(a,b) ((a<b)?(a):(b))
#define LMT 1e-9

double abs(double x){
	if(x > 0)
		return x;

	return -x;
}

int p, q, r, s, t, u;

double Function(double x){
	return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

int main(){
	double x, y, c;
	double high, low, mid;

	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)==6){
		if(Function(0)*Function(1) > 0)
			printf("No solution\n");
		else{
			high = 1;
			low = 0;

			if(Function(1) < Function(0)){
				high = 0;
				low = 1;
			}

			while(abs(high - low) > LMT){
				mid = (low + high)/2;

				if(Function(mid) < 0)
					low = mid;
				else
					high = mid;
			}
			printf("%.4lf\n", (high + low) / 2);
		}
	}

	return 0;
}

