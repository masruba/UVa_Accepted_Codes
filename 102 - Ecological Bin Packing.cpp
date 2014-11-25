#include<stdio.h>

int a[10];

//char r[7][4] = {"BCG","BGC","GBC","GCB","CBG","CGB"};
char r[7][5] = {"BCG","BGC","CBG","CGB","GBC","GCB"};

int check(int d,int b,int c){
	int sum = 0,i;

	for(i=0;i<9;i++)
		if(i!= d && i!= b && i!= c)
			sum += a[i];

	return sum;
}

int main(){
	int i,j,l,sum,min,k,p;
	int b[6];

	while(scanf("%d",&a[0]) == 1){
		sum = 0;
		j = 0;

		for(i = 1;i<9;i++)
			scanf("%d",&a[i]);

/*
		b[j++] = check(0,5,7);
		b[j++] = check(0,4,8);
		b[j++] = check(1,3,8);
		b[j++] = check(1,5,6);
		b[j++] = check(2,3,7);
		b[j++] = check(2,4,6);
*/

		b[j++] = check(0,5,7);
		b[j++] = check(0,4,8);
		b[j++] = check(2,3,7);
		b[j++] = check(2,4,6);
		b[j++] = check(1,3,8);
		b[j++] = check(1,5,6);
		
		min = b[0];
		p = 0;

		for(k = 1;k<6;k++){
			if(b[k] < min){
				p = k; 
				min = b[k];
			}
		}
		
/*		for(l=0;l<3;l++)
			printf("%c",r[p][l]);
		printf(" %d\n",min);
*/
		printf("%s %d\n",r[p],min);
	}

	return 0;
}
