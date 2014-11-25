#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 505

struct faculty{
	char title[MAX];
	char firstName[MAX];
	char lastName[MAX];
	char dept[MAX];
	char homePh[MAX];
	char workPh[MAX];
	char address[MAX];
	char campusBox[MAX];
};


bool sortByLastName(const faculty& A, const faculty& B){
	return (strcmp(A.lastName, B.lastName) < 0);
}

int main(){
	int n;
	char s[MAX];

	scanf("%d", &n);
	gets(s);

	vector<faculty> P;
	struct faculty X;

	for(int i=0; i<n; i++){
		gets(s);
		strcpy(X.dept, s);

		while(gets(s) && s[0]){
			int cnt = 0;

			char* sep = strtok(s, ",");
			while(sep != NULL){
				if(cnt == 0){
					strcpy(X.title, sep);
				}
				else if(cnt == 1){
					strcpy(X.firstName, sep);
				}
				else if(cnt == 2){
					strcpy(X.lastName, sep);
				}
				else if(cnt == 3){
					strcpy(X.address, sep);
				}
				else if(cnt == 4){
					strcpy(X.homePh, sep);
				}
				else if(cnt == 5){
					strcpy(X.workPh, sep);
				}
				else if(cnt == 6){
					strcpy(X.campusBox, sep);
				}

				sep = strtok(NULL, ",");
				cnt++;
			}

			P.push_back(X);
		}
	}

	sort(P.begin(), P.end(), sortByLastName);

	for(int i=0; i<P.size(); i++){
		printf("----------------------------------------\n");
		printf("%s %s %s\n", P[i].title, P[i].firstName, P[i].lastName);
		printf("%s\n", P[i].address);
		printf("Department: %s\n", P[i].dept);
		printf("Home Phone: %s\n", P[i].homePh);
		printf("Work Phone: %s\n", P[i].workPh);
		printf("Campus Box: %s\n", P[i].campusBox);
	}

	return 0;
}
