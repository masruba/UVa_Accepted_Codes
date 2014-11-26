#include<stdio.h>

#define MAXNUM 10001
#define MAX_PRIMES 1501

int num[MAXNUM];
int prime[MAX_PRIMES];

void primeGen(){
	int i, j, k;

	k = 0;
	num[0]= 1;
	num[1]= 0;

	prime[k] = 1;
	k++;

	for(i=2; i<MAXNUM && k<MAX_PRIMES; i++){
		if(!num[i]){
			prime[k++] = i;
			for(j=2*i;j<MAXNUM;j+=i)
				num[j] = 1;
		}
	}
}


int main(){
	int i, n, c;
	int cnt;

	primeGen();

	while(scanf("%d%d",&n,&c)==2){
		cnt = 0;

		for(i=1;i<=n;i++){
			if(num[i] == 0)
				cnt++;
		}

		printf("%d %d:", n, c);

		for(i=cnt/2-c+cnt%2; i<cnt/2+c && i<cnt;i++){
			if(i>=0)
				printf(" %d",prime[i]);
		}

		printf("\n\n");	
	}

	return 0;
}