#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int in1[256];
int in2[256];

void convert(char* s){
	for(int i=0; s[i]; i++){
		if(in1[s[i]]){
			printf("%c", in1[s[i]]);
		}
		else if(in2[s[i]]){
			printf("%c", in2[s[i]]);
		}
		else
			printf("%c", s[i]);
	}

	printf("\n");
}


int main(){
	int t;
	char s1[100];
	char s2[100];

	gets(s1);
	sscanf(s1,"%d",&t);
	gets(s1);

	for(int f=0; f<t; f++){
		if(f)	printf("\n");

		// plaintext
		gets(s1);

		// substitution text
		gets(s2);

		// reset
		for(int i=0; i<256; i++){
			in1[i] = 0;
			in2[i] = 0;
		}

		for(int i=0; s1[i]; i++){
			in1[s1[i]] = s2[i];
			in2[s2[i]] = s1[i];
		}

		printf("%s\n", s2);
		printf("%s\n", s1);

		while(gets(s1) && s1[0]){
			convert(s1);
		}
	}

	return 0;
}
