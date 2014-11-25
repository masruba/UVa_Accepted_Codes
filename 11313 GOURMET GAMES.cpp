#include<stdio.h>
#include<string>
using namespace std;

int main(){
	int t;
	int m, n;

	scanf("%d",&t);

	while(t--){
		scanf("%d%d",&n, &m);

		if((n-1)%(m-1) != 0)
			printf("cannot do this\n");
		else
			printf("%d\n", (n-1)/(m-1));
	}

	return 0;
}
