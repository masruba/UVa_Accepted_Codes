#include<stdio.h>
#include<math.h>

#define MAX 30

int a[MAX];

int checkalloff(int* a, int n){
	for(int j = 0; j<n; j++)
		if(a[j] == 1)
			return false;

	return true;
}

int main(){
	int n, k, m;
	int i;
	int pos1, pos2;

	while(scanf("%d%d%d",&n,&k,&m)==3 && (n || k || m)){
		for(int j = 0; j<n; j++)
			a[j] = 1;

		pos1 = -1;
		pos2 = n;

		while(1){
			i = 0;
			while(1){
				pos1 = (pos1+1)%n;
				if(a[pos1] == 1)
					i++;

				if(i == k)
					break;
			}

			i = 0;
			while(1){
				pos2 = (pos2 - 1 + n)%n;
				if(a[pos2] == 1)
					i++;

				if(i == m)
					break;
			}

			a[pos1] = 0;
			a[pos2] = 0;

			if(pos1 != pos2)
				printf("%3d%3d",pos1+1,pos2+1);
			else
				printf("%3d",pos1+1);

			if(checkalloff(a, n)==1)
					break;
			else
				printf(",");
		}
		printf("\n");
	}

	return 0;
}
