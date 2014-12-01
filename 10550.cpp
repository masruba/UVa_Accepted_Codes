#include<stdio.h>

int main(){
	int a, b, c, start;
	int tot = 0;

	while(scanf("%d%d%d%d",&start,&a,&b,&c)==4){
		if(!a && !b && !c && !start)
			break;

		tot = 40*2;

		if(a <= start)
			tot += start - a;
		else
			tot += 40 + (start - a);

		tot += 40;


		if(a <= b)
			tot += (b - a);
		else
			tot += 40 + (b - a);

		if(c <= b)
			tot += (b - c);
		else
			tot += 40 + (b - c);

		printf("%d\n", tot*9);
	}

	return 0;
}
