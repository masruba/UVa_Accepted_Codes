#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
	int n;
	char s[1000];
	int l;

	while(gets(s)){
		l = strlen(s);

		if(l == 1 && s[0] == '0')
			break;

		int sum = 0;
		int r = 0;

		for(int i=0;s[i]; i++){
			sum = r*10 + (s[i]-'0');
			r = sum%17;
		}
		if(r == 0)
			printf("1\n");
		else
			printf("0\n");
	}
}

