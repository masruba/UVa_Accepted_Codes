#include<stdio.h>
#include<limits.h>
#include<algorithm>
using namespace std;

#define MAX 1005
int a[MAX];


int closestSum(int* a, int start, int end, int sum){
	int first = start;
	int last = end;
	int minDiff = INT_MAX;
	int closeSum = 0;
	int csum = 0;

	while(first < last){
		csum = a[first] + a[last];

		if(minDiff > abs(csum - sum)){
			minDiff = abs(csum - sum);
			closeSum = csum;
		}

		if(csum == sum){
			closeSum = sum;
			break;
		}
		if(csum < sum){
			first++;
		}
		else
			last--;
	}

	return closeSum;
}

int main(){
	int n;
	int m; // query
	int q;

	int c = 0;
	while(scanf("%d",&n)==1 && n){

		for(int i=0; i<n; i++){
			scanf("%d",&a[i]);
		}

		sort(a, a+n);

		scanf("%d",&m);

		printf("Case %d:\n", ++c);
		for(int i=0; i<m; i++){
			scanf("%d",&q);
			if(n == 1){
				printf("Closest sum to %d is %d.\n",q, a[0]);
				continue;
			}

			printf("Closest sum to %d is %d.\n", q, closestSum(a, 0, n-1, q));
		}
	}

	return 0;
}
