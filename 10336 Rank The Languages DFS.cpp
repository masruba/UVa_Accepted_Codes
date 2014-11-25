#include<stdio.h>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

#define MAXLINE 150
#define MAXCHAR 150

char s[MAXLINE][MAXCHAR];
int visited[MAXLINE][MAXCHAR];
int r, c;
char ch;

void paint(int x, int y){
	s[x][y] = '#';

	if(x-1>=0 && s[x-1][y] == ch)	paint(x-1, y);
	if(y-1>=0 && s[x][y-1] == ch)	paint(x, y-1);
	if(x+1 < r && s[x+1][y] == ch)	paint(x+1, y);
	if(y+1 < c && s[x][y+1] == ch)	paint(x, y+1);

}


int freq[256];
int index[256];

bool comp(const int& A, const int& B){
	if(freq[A] == freq[B]){
		if(A < B)
			return true;
		return false;
	}

	if(freq[A] > freq[B])
		return true;

	return false;
}

int main(){
	int t;
	scanf("%d",&t);

	int cnt = 0;
	vector<char> order;

	for(int f=0; f<t; f++){
		scanf("%d%d",&r, &c);

		order.clear();
		for(int i=0; i<r; i++){
			scanf("%s", s[i]);
			for(int j=0; j<c; j++){
				visited[i][j] = 0;
			}
		}

		for(int i=0; i<256; i++){
			freq[i] = 0;
			index[i] = i;
		}

		cnt = 0;

		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(s[i][j]>='a' && s[i][j] <= 'z'){
					ch = s[i][j];
					freq[ch]++;
					paint(i, j);
				}
			}
		}

		sort(index, index + 256, comp);

		printf("World #%d\n", f+1);

		for(int i=0; i<256; i++){
			if(freq[index[i]])
				printf("%c: %d\n",index[i], freq[index[i]]);
			}
	}
	return 0;
}
