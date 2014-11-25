#include<stdio.h>

#define mymax(a, b) (((a)>(b))?(a):(b))

#define MAX 1005
int n, w[MAX], p[MAX];
int m[1005][1005];
int limit[101];

int MW = 31;

int main(){
	int t, s;
	int g;
	int j, k;

	int r;
	scanf("%d",&r);
	for(int t=0;t<r;t++){
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i], &w[i]);
		}

		for(j=0;j<n;j++)		// items
			m[j][0] = 0;

		for(j=0;j<MW;j++)		// weight
			m[0][j] = 0;

		for(j=1;j<=n;j++){		// items
			for(k=0;k<MW;k++){		// weight
				if(w[j-1] <= k){
					m[j][k] = mymax(m[j-1][k], m[j-1][k-w[j-1]]+p[j-1]);
				}
				else
					m[j][k] = m[j-1][k];
			}
		}

		scanf("%d",&g);
		int goodSum = 0;
		for(int i=0;i<g;i++){
			scanf("%d",&limit[i]);
			goodSum += m[n][limit[i]];
		}

		printf("%d\n", goodSum);
	}
	return 0;
}
