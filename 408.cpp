#include<stdio.h>

#define MAX 100005

int main(){
	int step, mod;
	int f[MAX];
	int seed, i;

	while(scanf("%d%d",&step, &mod) == 2){
		printf("%10d%10d    ",step,mod);

		if(mod == 1){
			printf("Good Choice\n\n");
			continue;
		}
		for(i=0; i<MAX;i++){
			f[i] = 0;
		}
		seed = 0;
		for(i=0; i<mod-1;i++){
			seed = (seed + step)%mod;
			
			if(f[seed] == 1)
				break;
			else
				f[seed] = 1;
		}

		if(i<mod-1)
			printf("Bad Choice\n\n");
		else
			printf("Good Choice\n\n");

	}

	return 0;
}