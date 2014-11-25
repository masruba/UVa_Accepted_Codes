#include<stdio.h>
#include<string.h>

bool isAlphabet(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c=='y')
		return true;
	return false;
}

int main(){
	int cnt[] = {5, 7, 5};
	char s[500];
	int c[3];

	while(gets(s) && strcmp(s,"e/o/i") != 0){
		c[0] = 0;
		c[1] = 0;
		c[2] = 0;

		int in = 0;
		for(int i=0; s[i]; i++){
			if(s[i] == '/'){
				if(c[in] != cnt[in])
					break;
				in++;
			}
			else if(i == 0 && isAlphabet(s[i])){
				c[0]++;
			}
			else if(i && isAlphabet(s[i]) && !isAlphabet(s[i-1])){
				c[in]++;
			}
		}

		if(in < 3){
			if(c[in] != cnt[in])
				printf("%d\n", in+1);
			else
				printf("Y\n");
		}
	}
	return 0;
}
