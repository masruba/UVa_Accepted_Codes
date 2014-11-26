#include<stdio.h>
#include<string.h>
using namespace std;

char s[500];

void decode(){
	int i, n1, n2, cnt, j, l;

	l = strlen(s);

	for(i=0;i<l;){
		n1 = 0;
		n2 =  0;

		if(i+2<l)
			n2 = (s[i] - '0')*100 + (s[i+1] - '0')*10 + s[i+2] - '0';
		n1 = (s[i] - '0')*10 + s[i+1] - '0';

		if((n1 >= 65 && n1 <= 90) || (n1 >= 97 && n1 <= 99) || n1 == 32 || n1 == 33 || n1 == 44 || n1 == 46 || n1 == 58 || n1 == 59 || n1 == 63){
			printf("%c", n1);
			i += 2;
		}
		else{
			printf("%c", n2);
			i += 3;
		}
	}
	printf("\n");
}

void encode(){
	int i, n, cnt, j, l;
	char t[500];

	for(i=0;s[i];i++){
		n = (int)s[i];

		cnt = 0;
		t[0] = '\0';
		while(n){
			t[cnt++] = n%10 + '0';
			n/=10;
		}

		t[cnt] = '\0';

		for(j=0;t[j];j++)
			printf("%c", t[j]);
	}

	printf("\n");
}

int main(){
	char s1[500];
	int i, l, j;

	while(gets(s1)){
		l =strlen(s1);

		for(i=l-1, j=0;i>=0;i--,j++){
			s[i] = s1[j];
		}
		s[l] = '\0';

		if(s[0] >= '0' && s[0] <= '9')
			decode();
		else
			encode();
	}

	return 0;
}
