#include<stdio.h>

#define r 6

int n,set[15],out[15],taken[15];

void combinate(int lev,int l){
	int i,last;

	if(lev == r){
		for(i = 0;i<r;i++){
			if(i)	printf(" ");
			printf("%d",out[i]);
		}

		printf("\n");
		return;
	}

	last = set[0] - 1;

	for(i = l+1;i<n;i++){
		if(set[i] == last || taken[i])
			continue;

		out[lev] = set[i];
		taken[i] = 1;

		combinate(lev+1,i);

		last = set[i];
		taken[i] = 0;
	}
}



int main(){
	int i,j = 0;

	while(scanf("%d",&n) == 1){
		if(!n)		break;
		
		if(j++)		printf("\n");

		for(i=0;i<n;i++)
			scanf("%d",&set[i]);
		
		combinate(0,-1);
	}

	return 0;
}