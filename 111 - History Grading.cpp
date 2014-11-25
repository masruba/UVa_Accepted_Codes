#include<stdio.h>

#define MAX 30

int len[MAX][MAX];
int n, a[MAX],b[MAX];

int LCS(int *a, int *b){
	int i, j;
	int p,q,r;

	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			if(i == 0 || j == 0)
				len[i][j] = 0;
			else{
				p = len[i-1][j-1];
				if(a[i-1] == b[j-1])
					p++;

				q = len[i-1][j];
				r = len[i][j-1];
				
				if(q > p)
					p = q;
				if(r > p)
					p = r;

				len[i][j]=p;
			}
		}
	}
	return len[n][n];
}

int main(){
	int i,p;

	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&p);
		a[p-1] = i;	// correct order
	}

	while(scanf("%d",&p) == 1){
		b[p-1] = 0;

		for(i=1;i<n;i++){
			scanf("%d",&p);
			b[p-1] = i;
		}

		printf("%d\n",LCS(a,b));
	}

	return 0;
}

