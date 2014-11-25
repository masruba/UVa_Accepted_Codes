#include<stdio.h>

#define MAX 30001

int parent[MAX];
int rank[MAX];
int stack[MAX];

void makeSet(int x){
	parent[x] = x;
	rank[x] = 0;
}

int findSet(int x, int& index){
	if(parent[x] == x)
		return x;
	else{
		stack[index++] = x;
		return findSet(parent[x], index);
	}
}


void link(int x, int y){
	if(rank[x] > rank[y]){
		parent[y] = x;
	}
	else{
		parent[x] = y;

		if(rank[x] == rank[y])
			rank[y]++;
	}
}

int main(){
	int t;
	int n, m;
	int a, b;
	int k;
	int par;

	scanf("%d",&t);

	for(int l=0; l<t; l++){
		scanf("%d%d",&n,&m);

		for(int i=1; i<=n; i++){
			makeSet(i);
		}

		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			if(parent[a] == parent[b])
				continue;

			// path compression
			k = 0;
			par = findSet(a, k);
			parent[findSet(b, k)] = par;
			parent[b] = par;

			for(int f=0; f<k; f++)
				parent[stack[f]] = par;
		}

		int max = 0;

		for(int i=1; i<=n; i++){
			parent[i] = findSet(parent[i], k);
			rank[parent[i]]++;

			if(rank[parent[i]] > max)
				max = rank[parent[i]];
		}

		printf("%d\n",max);
	}

	return 0;
}
