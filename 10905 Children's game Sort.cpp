#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define MAX 55


struct Num{
    char m[100];
}a[MAX];

bool comp(const Num& A, const Num& B){
	char s1[300], s2[300];

	int i, j;
	for(i=0; A.m[i]; i++){
		s1[i] = A.m[i];
	}

	for(j=0; B.m[j]; j++, i++){
		s1[i] = B.m[j];
	}

	s1[i] = '\0';

	for(i=0; B.m[i]; i++){
		s2[i] = B.m[i];
	}

	for(j=0; A.m[j]; j++, i++){
		s2[i] = A.m[j];
	}

	s2[i] = '\0';

	return (strcmp(s1, s2) > 0);
}

int main(){
	int n;

	while(scanf("%d",&n)==1 && n){
		for(int i=0;i<n;i++){
			scanf("%s",&a[i].m);
		}

		sort(a, a+n, comp);

		for(int i=0;i<n;i++)
			printf("%s", a[i].m);
		printf("\n");
	}

	return 0;
}
