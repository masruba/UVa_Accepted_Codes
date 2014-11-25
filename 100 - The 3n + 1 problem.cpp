#include<stdio.h>

int main(){
	int i,j,n,n1,count,maxcount,p,q;

	while(scanf("%d%d",&i,&j)==2){
		p = i;
		q = j;

		if(i>j){
			n = i;
			i = j;
			j = n;
		}

		maxcount = 0;
		for(n = i;n <= j;n++){
			n1 = n;
			count = 1;
			while(1){
				if(n1 == 1)
					break;

				if(n1%2!=0)
					n1 = 3*n1+1;
				else
					n1 = n1/2;
				count++;
			}
			if(count > maxcount)
				maxcount = count;
		}
		if(maxcount)	printf("%d %d %d\n",p,q,maxcount);
	}

	return 0;
}





