#include<stdio.h>
#include<math.h>

#define min(a,b) ((a<b)?(a):(b))
#define LMT 1e-4

double crossedLadderFormula(double x, double y, double w){
	double p = sqrt(x*x - w*w);
	double q = sqrt(y*y - w*w);
	return (1.0/p + 1.0/q);
}

int main(){
	double x, y, c;
	double high, low, mid;

	while(scanf("%lf%lf%lf",&x,&y,&c)==3){
		double r = 1.0/c;
		low = 0;
		high = min(x, y);

		while(high - low > LMT){
			mid = (low + high)/2;

			if(crossedLadderFormula(x, y, mid) < r)
				low = mid;
			else
				high = mid;
		}
		printf("%.3lf\n", (high + low) / 2);
	}

	return 0;
}

