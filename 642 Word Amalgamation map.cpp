#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;

char word[110][10];
int in[110];

void reset(int* c1){
	int i;

	for(i=0;i<26;i++)
		c1[i] =0;
}

int checkAnagrams(char* s1, char *s2){
	if(strlen(s1) !=  strlen(s2))
		return 0;

	int i;

	int c1[26];
	reset(c1);

	for(i=0; s1[i]; i++)
		c1[s1[i] - 'a']++;

	for(i=0; s2[i];i++)
		c1[s2[i] - 'a']--;

	for(i=0;i<26;i++)
		if(c1[i])		return 0;

	return 1;
}

int compare(const void* p, const void* q){
	int a = *(const int *)p;
	int b = *(const int *)q;

	return strcmp(word[a], word[b]);
}

int main(){
	int n, i, flag;
	char s1[10];

	int wordCnt = 0;
	while(1){
		scanf("%s", word[wordCnt]);

		if(word[wordCnt][0]=='X')
			break;

		in[wordCnt] = wordCnt;
		wordCnt++;
	}

	qsort(in, wordCnt, sizeof(int), compare);


	while(scanf("%s",s1) == 1 && s1[0] != 'X'){
		flag = 1;

		for(i=0; i<wordCnt; i++){
			if(checkAnagrams(s1, word[in[i]]) == 1){
				// multiple words
				printf("%s\n", word[in[i]]);
				flag = 0;
			}
		}

		if(flag)
			printf("NOT A VALID WORD\n");

		printf("******\n");
	}
}
