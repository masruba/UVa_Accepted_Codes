#include<stdio.h>

void process(int &f, int* wp){
	int w1, d1;
	int w2, d2;
	scanf("%d%d%d%d",&w1,&d1,&w2,&d2);

	if(!w1)
		process(f, &w1);

	if(!w2)
		process(f, &w2);

	if(w1*d1 == w2*d2){
		*wp = w1 + w2;
	}
	else
		f = 0;
}

int main(){
	int n;

	scanf("%d",&n);

	for(int t=0;t<n;t++){
		if(t)
			printf("\n");

		int f = 1;
		int dum = 1;
		process(f, &dum);

		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
