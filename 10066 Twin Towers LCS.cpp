#include<stdio.h>
using namespace std;

#define MAX 1005

int lcs[MAX][MAX];

int LCSLength(int* a, int n, int* b, int m){
	for(int i=0; i<n; i++)
		lcs[i][0] = 0;

	for(int i=0; i<m; i++)
		lcs[0][i] = 0;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i-1] == b[j-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
			}
			else if(lcs[i-1][j] >= lcs[i][j-1])
				lcs[i][j] = lcs[i-1][j];
			else
				lcs[i][j] = lcs[i][j-1];
		}
	}

	return lcs[n][m];
}

int main(){
	int a[MAX];
	int b[MAX];
	int n, m;

	int c = 0;
	while(scanf("%d%d",&n, &m)==2 && (n||m)){

		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);

		for(int i=0; i<m; i++)
			scanf("%d",&b[i]);

		printf("Twin Towers #%d\n", ++c);
		printf("Number of Tiles : %d\n", LCSLength(a, n, b, m));
		printf("\n");
	}

	return 0;
}
