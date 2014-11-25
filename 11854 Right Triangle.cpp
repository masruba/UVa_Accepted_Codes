#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int a[3];
	int mx, mn;
	int mid;

	while(scanf("%d%d%d", &a[0], &a[1], &a[2]) && (a[0] || a[1] || a[2])){
		if(a[0] == a[1] + a[2] || a[1] == a[0] + a[2] || a[2] == a[1] + a[0]){
			printf("wrong\n");
			continue;
		}

		sort(a, a+3);

		if(a[2]*a[2] == a[1]*a[1] + a[0]*a[0])
			printf("right\n");
		else
			printf("wrong\n");

	}
	return 0;
}
