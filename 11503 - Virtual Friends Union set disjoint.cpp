#include<stdio.h>
#include<map>
#include<string>
using namespace std;

#define MAX 200005

int parent[MAX];
int rank[MAX];

void makeSet(int x){
	parent[x] = x;
	rank[x] = 1;
}

int findSet(int x){
	if(parent[x] == x)
		return x;
	else{
		return (parent[x] = findSet(parent[x]));
	}
}

int main(){
	int t;
	int n, m;
	char a[30], b[30];
	int k;
	int par;

	map<string, int> M;

	scanf("%d",&t);

	int max = 0;
	for(int l=0; l<t; l++){
		scanf("%d", &m);
		M.clear();

		// atmost 2*m people
		for(int i=1;i<2*m;i++)
			makeSet(i);

		int n = 1;
		int x, y;
		for(int o=0;o<m;o++){
			scanf("%s%s",a, b);

			if(M.find(string(a)) == M.end()){
				M[string(a)] = n;
				x = n;
				n++;
			}
			else
				x = M[string(a)];

			if(M.find(string(b)) == M.end()){
				M[string(b)] = n;
				y = n;
				n++;
			}
			else
				y = M[string(b)];

			//if(parent[x] == parent[y])
				//continue;

			int p1 = findSet(x);
			int p2 = findSet(y);

			if(p1 != p2){
				rank[p1] += rank[p2];
				parent[p2] = p1;
			}
			printf("%d\n",rank[p1]);
		}
	}

	return 0;
}
