#include<stdio.h>
#include<math.h>


int main(){
	double x1,y1,x2,y2,x3,y3,s,area,a,b,c,r,C,pi;

	pi = 2 * acos(0);
	
	while(scanf("%lf",&x1)==1){
		scanf("%lf%lf%lf%lf%lf",&y1,&x2,&y2,&x3,&y3);

		a = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		b = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
		c = sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));

		s = (a+b+c) /2;

		area = sqrt(s*(s-a)*(s-b)*(s-c));

		r = (a*b*c)/(4*area);

		C = 2 * pi * r;

		printf("%.2lf\n",C);
	}

	return 0;
}