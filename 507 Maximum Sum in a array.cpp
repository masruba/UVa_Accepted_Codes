#include<stdio.h>
#include<string>
using namespace std;

void getMaxSum(int* a, int n, int r){

}

int main(){
	int a[20000];
	int t, n;

	scanf("%d",&t);
	for(int f=0; f<t;f++){
		scanf("%d",&n);

		int p = -1;
		int q = -1;
		int maxSum = 0;

		for(int i=0; i<n-1;i++){
			scanf("%d",&a[i]);

			if(a[i] > maxSum){
				maxSum = a[i];
				// for only one element
				p = i+1;
				q = i+2;
			}
		}

	int sum = 0;
	int p1 = 1;

	for(int i=0; i<n-1; i++){
		sum += a[i];

		if(maxSum < sum){
			maxSum = sum;
			q = i+2;
			p = p1;
		}
		else if(sum < 0){
			p1 = i+2; // next element
			sum = 0;
		}
		else if(sum == maxSum && p == p1){
			q = i+2;
		}
	}

	if(maxSum>0)
		printf("The nicest part of route %d is between stops %d and %d\n",f+1,p,q);
	else
		printf("Route %d has no nice parts\n",f+1);
	}
	return 0;
}
