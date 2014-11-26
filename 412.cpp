#include<stdio.h>
#include<math.h>


int check(int n,int m){
	int r;

	while(1){
		r = n % m;
		if(!r)	break;
		n = m;
		m = r;	
	}
	
	return m;

}



void pair(int *a,int n){
	int i,j;
	double count = 0,p = 0;
//	int c,b;
	double result,pi;

	for(i = 0;i<n-1;i++){
		for(j = i+1;j<n;j++){
		//	b = a[i];
		//	c = a[j];
			p++;
			if(check(a[i],a[j]) == 1){
				count++;
			//	printf("%d %d\n",a[i],a[j]);
			}
		}
	
	}

	if(count){
		result = (6.0 * p ) / count;
		pi = sqrt(result);
		printf("%.6lf\n",pi);
	}

	else printf("No estimate for this data set.\n");

}

int main(){
	int n,i;
	int a[51];

	while(scanf("%d",&n) == 1){
		if(!n)		break;
		
		for(i = 0;i<n;i++)
			scanf("%d",&a[i]);

		 pair(a,n);
	}

	return 0;
}