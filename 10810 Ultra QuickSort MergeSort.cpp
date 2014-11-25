#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;

#define MAX 500005
#define INF 1000000000
#define LL long long

void merge(int* a, int p, int q, int r, LL& cnt){
	int llen = q - p + 1;	// q included
	int rlen = r - q;

	vector<int> left;
	vector<int> right;

	for(int i=0; i<llen; i++)
		left.push_back(a[p + i]);

	left.push_back(INF);
	for(int i=1; i<=rlen; i++)
		right.push_back(a[q + i]);
	right.push_back(INF);


	int lIndex = 0;
	int rIndex = 0;

	for(int i=p; i<=r; i++){
		if(left[lIndex] <= right[rIndex]){
			a[i] = left[lIndex++];
		}
		else{
			// swap required
			a[i] = right[rIndex++];
			// swap all the elements upto lindex
			cnt += llen - lIndex;
		}
	}
}

void mergeSort(int* a, int start, int end, LL &cnt){
	if(start < end){
		int mid = (int)(floor)((start + end)/2.0);
		mergeSort(a, start, mid, cnt);
		mergeSort(a, mid+1, end, cnt);
		merge(a, start, mid, end, cnt);
	}
}

int main(){
	LL sCnt;
	int num[MAX];
	int t;
	int n;

	while(scanf("%d",&n)==1 && n){
		for(int f=0; f<n; f++){
			scanf("%d",&num[f]);
		}

		sCnt = 0;
		mergeSort(num, 0, n-1, sCnt);
		printf("%lld\n", sCnt);
	}
	return 0;
}
