#include<stdio.h>

long a[5850];
char suf[][5] = {"st", "nd", "rd"};

void genHumble(){
	int i;
	int p2, p3, p5, p7;
	long n2, n3, n5, n7;

	p2 = 0;
	p3 = 0;
	p5 = 0;
	p7 = 0;
	a[0] = 1;

	for(i=1; i <= 5842; i++){
		n2 = a[p2] * 2;
		n3 = a[p3] * 3;
		n5 = a[p5] * 5;
		n7 = a[p7] * 7;

		if(n2<=n3 && n2<=n5 && n2<=n7){
			a[i] = n2;
			p2++;
		}

		if(n3<=n2 && n3<=n5 && n3<=n7){
			a[i] = n3;
			p3++;
		}

		if(n5<=n2 && n5<=n3 && n5<=n7){
			a[i] = n5;
			p5++;
		}

		if(n7<=n2 && n7<=n3 && n7<=n5){
			a[i] = n7;
			p7++;
		}
	}
}

int main(){
	int n;
	genHumble();

	while(scanf("%d",&n) == 1){
		if(n == 0)	break;

		printf("The %d", n);

		if(n%10 > 0 && n%10 < 4 && (n%100)/10 != 1)
			printf("%s",suf[n%10 - 1]);
		else
			printf("th");

		printf(" humble number is %d.\n", a[n-1]);
	}

	return 0;
}