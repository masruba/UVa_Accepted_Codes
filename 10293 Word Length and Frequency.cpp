#include<stdio.h>
#include<assert.h>
#include<string.h>

char word[1000][100];
char s[1000];

#define MAX 81
#define WORDLEN 31

int freq[WORDLEN];

void process(char word[][100], int cnt){
	int l;
	int flag;
	int prevLen = -1, curLen;

	for(int i=0;i<WORDLEN; i++)
		freq[i] = 0;

	flag = false;

	for(int i=0; i<cnt; i++){
		int l = strlen(word[i]);
		curLen = 0;

		for(int j=0; word[i][j]; j++){
			if(j == l-1 && word[i][j] == '-'){
				flag = true;
				prevLen = curLen;
				curLen = 0;
			}
			else if(word[i][j] == ' ' || word[i][j] == '?' || word[i][j] == '!' || word[i][j] == ',' || word[i][j] == '.'){
				if(flag){
					freq[prevLen + curLen]++;
					prevLen = -1;
					flag = false;
				}
				else if(curLen)
					freq[curLen]++;

				curLen = 0;
			}
			else if(word[i][j] != '-' && word[i][j] != '\''){
					curLen++;
			}
		}
		if(curLen && !flag)
			freq[curLen]++;
	}

	for(int i=1;i<WORDLEN; i++){
		if(freq[i]){
			printf("%d %d\n", i, freq[i]);
		}
	}
	printf("\n");
}

int main(){
	int flag;

	int cnt = 0;
	while(gets(s) && s[0]){
		if(s[0] == '#'){
			process(word, cnt);
			cnt = 0;
			continue;
		}
		strcpy(word[cnt++], s);
	}
	return 0;
}
