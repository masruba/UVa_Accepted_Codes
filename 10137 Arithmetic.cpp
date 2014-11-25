#include<stdio.h>
#include<math.h>

int main(){
	int ex[1005];
	int sum, avg;
	int n;
	double x;

	while(scanf("%d",&n)==1 && n){
		sum = 0;

		for(int i=0; i<n; i++){
			scanf("%lf", &x);
			ex[i] = (int)(x*100+0.5);
			sum += ex[i];
		}

		avg = sum/n;

		int tot1 = 0;
		int tot2 = 0;

		for(int i=0; i<n; i++){
			if(ex[i] < avg)
				tot1 += (avg - ex[i]);
			if(ex[i] > avg+1)
				tot2 += (ex[i] - avg - 1);
		}

		if(tot2 > tot1)
			tot1 = tot2;

		printf("$%.2lf\n",tot1/100.0);
	}

	return 0;
}
