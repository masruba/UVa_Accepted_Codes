#include<stdio.h>

int n;
int taken[20];
int ring[20];
int num[] =     {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
int isPrime[] = {
	0,0,1,1,0, 1,0,1,0,0,
	0,1,0,1,0, 0,0,1,0,1,
	0,0,0,1,0, 0,0,0,0,1,
	0,1,0,0,0, 0,0,1,0,0
};
								//0 1 2 ... 16
void bktk(int lev){
	if(lev == n){
		// last Number + first Number = 1
		if(isPrime[ring[n-1] + 1] == 1){
			printf("1");
			for(int i=0; i<lev; i++)
				printf(" %d",ring[i]);
			printf("\n");
		}
		return;
	}

	for(int i=0; i<n; i++){
		ring[lev] = num[i];
		if(taken[i])
			continue;

		// first number = 1 + last number
		if(lev == 0 && isPrime[1 + ring[lev]] == 0)
			continue;

		if(lev && isPrime[ring[lev-1] + ring[lev]] == 0)
			continue;

		taken[i] = 1;
		bktk(lev+1);
		taken[i] = 0;
	}
}


int main(){
	int t = 0;

	while(scanf("%d",&n) == 1){
		if(t)	printf("\n");
		printf("Case %d:\n",++t);

		n--;
		bktk(0);
	}
	return 0;
}
