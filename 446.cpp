#include<stdio.h>
#include<string.h>

struct t{
	char str[5];
	char d;
	int p;
	char a[15],b[15];
}text[100000];


void binary(int t,int n,int c){
	int i,j = 0;

	if(c == 1){
		for(i = 12; i >= 0;i--){
			if(n&(1<<i))	text[t].a[j++] = '1';
			else			text[t].a[j++] = '0';
		}
	}

	else{
		for(i = 12; i >= 0;i--){
		if(n&(1<<i))	text[t].b[j++] = '1';
		else			text[t].b[j++] = '0';
		}
	}

}



int deci(char *s1){
	int i,l,n = 0;
	l = strlen(s1);

	for(i = 0;s1[i];i++){
		if(s1[i] >='A' && s1[i] <='F')
			n = n * 16 + (s1[i] - 'A' + 10);
		else
			n = n * 16 + (s1[i] - '0');
	}
	
	return n;
}

void compute(int t,char *s1,char *s2,char *c){
	int n1,n2,i,flag = 0;

	for(i=0;c[i];i++)
		if(c[i] == '+')
			flag = 1;

	n1 = deci(s1);
	n2 = deci(s2);

	binary(t,n1,1);
	
	if(flag){
		text[t].d = '+';
		text[t].p = n1+n2;
	}
	else{
		text[t].d = '-';
		text[t].p = n1 - n2;
	}
	
	binary(t,n2,2);
}	

int main(){
	int n,i;
	char s1[5],s2[5],c[5];

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%s",s1);
		scanf("%s",c);
		scanf("%s",s2);

		compute(0,s1,s2,c);
		
		printf("%s",text[0].a);
		printf(" %c ",text[0].d);
		printf("%s",text[0].b);
		printf(" = ");
		printf("%d\n",text[0].p);
		
	}

	return 0;
}
