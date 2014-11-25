#include<stdio.h>
#include<string.h>

#define MAXWORD 1010
#define MAXLEN  30

int len[MAXWORD+1][MAXWORD+1];

int LCS(char word1[][MAXLEN], int index1, char word2[][MAXLEN], int index2){
	for(int i=0; i<=index1; i++){
		for(int j=0; j<=index2; j++){
			if(i == 0 || j == 0)
				len[i][j] = 0;
			else{
				if(strcmp(word1[i-1], word2[j-1]) == 0){
					len[i][j] = len[i-1][j-1] + 1;
				}
				else if(len[i-1][j] >= len[i][j-1]){
					len[i][j] = len[i-1][j];
				}
				else{
					len[i][j] = len[i][j-1];
				}
			}
		}
	}

	return len[index1][index2];
}

void tokenize(char word[][MAXLEN], char* s, int& index){
	int j = 0;

	for(int i=0; s[i]; i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			word[index][j++] = s[i];
		}
		else if(s[i]>='0' && s[i]<='9'){
			word[index][j++] = s[i];
		}
		else{
			if(j){
				word[index][j] = '\0';
				index++;
			}
			j = 0;
		}
	}

	if(j){
		word[index][j] = '\0';
		index++;
	}
}

int main(){
	char word1[MAXWORD][MAXLEN];
	char word2[MAXWORD][MAXLEN];
	int index1 = 0;
	int index2 = 0;
	int i, j;
	char s[10000];
	char c1, c2;

	int caseNo = 1;

	while(gets(s)){
		c1 = s[0];

		index1 = 0;
		tokenize(word1, s, index1);

		if(!gets(s))
			break;

		index2 = 0;
		tokenize(word2, s, index2);
		c2 = s[0];

		printf("%2d. ",caseNo++);
		if(!c1 || !c2){
			printf("Blank!\n");
			continue;
		}

		printf("Length of longest match: %d\n",LCS(word1, index1, word2, index2));
	}

	return 0;
}
