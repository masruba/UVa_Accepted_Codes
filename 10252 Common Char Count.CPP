#include<stdio.h>

#define MAX 1050
#define ALP 26

char s1[MAX], s2[MAX];
int ar1[ALP],ar2[ALP],mn[ALP];

void clear(){
	int i;
	for(i=0;i<ALP;i++)
		ar1[i]=ar2[i]=mn[i]=0;
}

int main(){
	int i,j;
	while(gets(s1)){
		gets(s2);
		for(i=0;s1[i];i++)
			ar1[s1[i]-'a']++;
		for(i=0;s2[i];i++)
			ar2[s2[i]-'a']++;
		for(i=0;i<ALP;i++){
			if(ar1[i]<=ar2[i])
				mn[i]=ar1[i];
			else
				mn[i]=ar2[i];
		}
		for(i=0;i<ALP;i++)
			for(j=0;j<mn[i];j++)
				printf("%c",'a'+i);
		printf("\n");
		clear();
	}
	return 0;
}
