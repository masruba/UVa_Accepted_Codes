#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;

struct Array{
	string num;
	int index;
}a[10000];


bool compare(Array a1, Array a2){
	if(a1.index < a2.index)
		return true;

	return false;
}

int main(){
	int t;
	int n;
	char s[100000];

	gets(s);
	sscanf(s, "%d", &t);

	for(int f=0;f<t;f++){
		gets(s);	// blank

		gets(s);
		char* x = strtok(s, " ");
		int index = 0;

		while(x != NULL){
			a[index++].index = atoi(x);
			x = strtok(NULL, " ");
		}

		// numbers
		gets(s);
		x = strtok(s, " ");
		index = 0;

		while(x != NULL){
			a[index++].num = x;
			x = strtok(NULL, " ");
		}

		sort(a, a+index, compare);

		if(f)
			printf("\n");

		for(int i=0; i<index; i++)
			cout << a[i].num.c_str() << endl;
	}

	return 0;
}
