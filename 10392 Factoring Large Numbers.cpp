#include<stdio.h>

typedef long long LL;

int main(){
	LL n;
	LL i;

	while(scanf("%lld",&n)==1){
		if(n < 0)
			break;

		while(n%2 == 0){
			printf("    2\n");
			n /= 2;
		}

		for(i=3; i*i<=n; i+=2){
			while(n%i == 0){
				printf("    %lld\n", i);
				n /= i;
			}
		}

		// remaining portion
		if(n>1)
			printf("    %lld\n",n);

		printf("\n");
	}

	return 0;
}
