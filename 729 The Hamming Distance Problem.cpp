#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
	int t;
	int n, h;

	scanf("%d",&t);
	for(int l=0; l<t; l++){
		if(l)
			printf("\n");

		scanf("%d%d",&n, &h);

		int a[18];
		memset(a, 0, 18*sizeof(int));

		int in = n-1;
		for(int i=h-1; i>=0; i--){
			a[in--] = 1;
		}

		do{
			for(int i=0; i<n; i++)
				printf("%d", a[i]);
			printf("\n");
		}while(next_permutation(a, a+n));
	}
}

