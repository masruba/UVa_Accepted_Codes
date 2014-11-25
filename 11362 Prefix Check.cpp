#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

string ph[10010];

bool isPrefix(string a, string b){
	// check whether a is prefix of b
	if(b.size() < a.size())
		return false;

	for(int i=0; a[i]; i++){
		if(a[i] != b[i])
			return false;
	}

	return true;
}

int main(){
	int t;
	int n;

	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);

		for(int i=0; i<n; i++){
			cin >> ph[i];
		}

		int i;

		sort(ph, ph+n);

		for(i=0; i<n-1; i++){
			if(isPrefix(ph[i], ph[i+1])){
				printf("NO\n");
				break;
			}
		}

		if(i == n-1){
			printf("YES\n");
		}
	}

	return 0;
}
