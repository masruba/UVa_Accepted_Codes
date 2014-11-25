#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 1010

struct Job{
	int index;
	int time;
	int fine;
}job[MAX];

bool comp(const Job& A, const Job& B){
	if(A.time*B.fine  == A.fine*B.time){
		return (A.index < B.index);
	}

	return (A.time*B.fine  < A.fine*B.time);
}

int main(){
	int n;
	int t;

	scanf("%d",&t);
	for(int f=0; f<t; f++){
	    scanf("%d",&n);

	    for(int i=0;i<n;i++){
	    	scanf("%d%d",&job[i].time, &job[i].fine);
	    	job[i].index = i+1;
	 	}

	 	sort(job, job+n, comp);

		if(f)			printf("\n");

		for(int i=0; i<n; i++){
			if(i)	printf(" ");
			printf("%d",job[i].index);
		}

		printf("\n");
	}

	return 0;
}
