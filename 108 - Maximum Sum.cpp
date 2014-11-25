#include<stdio.h>

#define MAX 110

int sum[MAX][MAX], num[MAX][MAX];

int main(){
	int i, j, k, l, temp;
	int n;
	int max;

	while(scanf("%d",&n) == 1){
		if(n == 0){
			printf("0\n");
			continue;
		}

		max = -127;

		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				scanf("%d",&num[i][j]);
				if(j == 0)
					sum[i][0] = num[i][0];
				else
					sum[i][j] = sum[i][j-1] + num[i][j];

				for(k=j; k>=0; k--){
					temp = 0;
					for(l=i; l>=0; l--){
						temp = temp + sum[l][j];

						if(l > 0){
							temp = temp - sum[l][k-1];
						}
						if(temp > max){
							max = temp;
						}
					}
				}
			}		
		}

		printf("%d\n", max);
	}
	return 0;
}