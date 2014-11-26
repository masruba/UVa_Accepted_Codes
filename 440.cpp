#include<stdio.h>

int city[151];

int main(){
	int n, i, p;
	int m, cnt;

	while(scanf("%d",&n) == 1 && n){
		for(m=2;;m++){
			for(i=0;i<n;i++)
				city[i] = 1;
		
			p = 0;
			city[0] = 0;
			cnt = 1;

			while(1){
				i = 0;
				while(1){
					p++;

					if(p >= n)
						p = p%n;

					if(city[p] == 1)
						i++;

					if(i == m)
						break;
				}

				city[p] = 0;
				cnt++;

				if(cnt == n || p == 1)
					break;
			}
			if(cnt == n && p==1)
				break;
		}
		
		printf("%d\n",m);
	}

	return 0;
}