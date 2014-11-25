#include<stdio.h>
#include<string.h>

#define MAX 20

char name[MAX][MAX];
int u[MAX];
long money[MAX];

int main(){
	int n, i, amt, num, j, cnt, k;
	char sender[MAX], recvr[MAX];

	cnt = 0;

	while(scanf("%d",&n) == 1){
		if(cnt)	printf("\n");

		for(i=0; i < n; i++){
			scanf("%s",name[i]);
			money[i] = 0;
			u[i] = 0;
		}

		for(i=0; i < n; i++){
			scanf("%s",sender);
			scanf("%d%d",&amt,&num);
		
			if(num > 0){
				for(j=0; j < n; j++){
					if(u[j] == 0){
						if(strcmp(sender, name[j]) == 0){
							money[j] = money[j] - amt + (amt % num);
							u[j] = 1;
							break;
						}
					}
				}
			}

			for(j=0;j<num;j++){
				scanf("%s",recvr);

				for(k=0; k < n; k++){
					if(strcmp(recvr, name[k]) == 0){
						money[k] += (amt / num);
						break;
					}
				}
			}
		}
		for(i=0; i < n; i++)
			printf("%s %ld\n",name[i], money[i]);
		
		cnt++;		
	}

	return 0;
}