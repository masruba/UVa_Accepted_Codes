#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 50005

int x[MAX];
int y[MAX];

int median(int* a, int n){
	// odd
	if(n % 2 == 1){
		return a[(n-1)/2];
	}
	else{
		// smaller one
		return a[n/2-1];
	}
}

int main(){
	int t;
	int X;
	int Y;
	int n;

	scanf("%d",&t);

	for(int f=0;f<t;f++){
		scanf("%d%d%d",&X, &Y, &n);

		for(int i=0; i<n; i++){
			scanf("%d%d",&x[i], &y[i]);
		}

		sort(x, x+n);
		sort(y, y+n);

		int street =  median(x, n);
		int avn =  median(y, n);

		printf("(Street: %d, Avenue: %d)\n", street, avn);
	}

	return 0;
}
