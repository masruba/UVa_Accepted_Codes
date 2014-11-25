#include<stdio.h>

double x1,y1,x2,y2,x3,y3,x4,y4;

int main(){
	while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)==4){
		x3=(x1+x2+y1-y2)/2.;
		y3=(y1+y2-x1+x2)/2.;
		x4=(x1+x2-y1+y2)/2.;
		y4=(y1+y2+x1-x2)/2.;
		printf("%.10lf %.10lf %.10lf %.10lf\n",x3,y3,x4,y4);
	}

	return 0;
}
