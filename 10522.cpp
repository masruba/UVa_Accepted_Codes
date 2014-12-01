#include<stdio.h>
#include<math.h>

int main(){
	int n;
	int cnt;

	double area, ha, hb, hc;

	scanf("%d",&n);		
	cnt = 0;

	while(scanf("%lf%lf%lf",&ha, &hb, &hc)==3){
		if(cnt == n)	break;
		
		if((ha > 0 && hb > 0 && hc > 0) &&
			( (1/ha) + (1/hb) - (1/hc)) > 0 &&
			( (1/ha) - (1/hb) + (1/hc)) > 0 &&
		    (-(1/ha) + (1/hb) + (1/hc)) > 0 
		){	
			area = (ha*ha*hb*hb*hc*hc)/
			sqrt(( + hb*hc + hc*ha + ha*hb )
				*( + hb*hc + hc*ha - ha*hb )
				*( + hb*hc - hc*ha + ha*hb )
				*( - hb*hc + hc*ha + ha*hb ));
			printf("%.3lf\n",area);
		}
		else{
			cnt++;
			printf("These are invalid inputs!\n");
			continue;
		}
	}

	return 0;
}