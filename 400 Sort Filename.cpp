#include<math.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<string.h>
#include<algorithm>
#include <iomanip>
using namespace std;
using std::left;

#define MAX 61

int main(){
	int n;
	int R, C;
	string s[101];
	char buf[101];

	while(scanf("%d",&n)==1){
		int maxLen = -1;

		for(int i=0;i<n;i++){
			scanf("%s",&buf);
			s[i] = string(buf);
			int l = strlen(buf);
			if(maxLen < l)
				maxLen = l;
			//printf("Strlen %d %d\n", l, maxLen);
		}

		vector<string> v(s, s+n);
		sort(v.begin(), v.end());

		C = floor(62 / (maxLen+2));
		R = ceil((double)n / (double)C);
		//printf("n = %d R %d C %d\n", n, R, C);

		for(int i=0; i<60; i++){
			printf("-");
		}
		printf("\n");

		for(int i=0; i<R; i++){
			int l = 0;
			for(int j=0; j<C; j++){
				if(i + j*R >= n){
					break;
				}


				if(j < C-1){
					cout << left;
					cout << setw((maxLen+2)) << v[i+j*R];
					l += maxLen+2;
				}
				else{
					cout << left;
					cout << setw(maxLen) << v[i+j*R];
					l += maxLen;

					for(int k=0;k<60-l;k++)
						printf(" ");
				}
			}
			printf("\n");
		}
	}

	return 0;
}
