#include<stdio.h>

#define MAX 10005
int building[MAX];

int main(){
	int L, H, R;
	int h = 0;
	int i;
	int flag;
	
	while(scanf("%d%d%d",&L,&H,&R)==3){
		for(i=L;i<R;i++){
			if(building[i] < H)
				building[i] = H;
		}
	}

	flag = 0;
	H = 0;
	for(i=0;i<MAX;i++){
		if(building[i] != h){
			if(flag)
				printf(" ");

			h = building[i];
			printf("%d %d", i, h);
			flag = 1;
		}
	}

	printf("\n");
	return 0;
}