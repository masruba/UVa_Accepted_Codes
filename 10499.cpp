#include<stdio.h>

typedef long long ll;
#define c '%'

int main(){
	ll n;

	while(scanf("%lld",&n) == 1){
		if(n < 0)	break;
	
		if(n == 1) 		
			printf("0%c\n",c);
		else
			printf("%lld%c\n",25*n,c);
	}

	return 0;
}