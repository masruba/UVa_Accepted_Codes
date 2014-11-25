#include<stdio.h>

#define MAX 128

int edge[MAX][MAX];
int node[MAX];
int visited[MAX];

void DFS(int n){
	visited[n] = 1;

	for(int i=1; i<MAX; i++){
		if(i != n && edge[n][i] && !visited[i])
			DFS(i);
	}
}

int main(){
	int n, e;
	int nNode;
	char n1[10];
	char n2[10];

	while(scanf("%d%d",&n, &e)==2){
		for(int i=0; i<MAX; i++){
			node[i] = 0;
			visited[i] = 0;
			for(int j=0; j<MAX; j++){
				edge[i][j] = 0;
			}
		}

		nNode = 0;

		for(int i=0;i<e;i++){
			scanf("%s%s",n1, n2);
			edge[n1[0]][n2[0]] = 1;
			edge[n2[0]][n1[0]] = 1;

			if(!node[n1[0]]){
				node[n1[0]] = 1;
				nNode++;
			}

			if(!node[n2[0]]){
				node[n2[0]] = 1;
				nNode++;
			}
		}

		int cnt = -1;
		for(int i=0; i<MAX; i++){
			if(node[i] && !visited[i]){
				DFS(i);
				cnt++;
			}
		}

		// n - e + f = 2

		int face = e - nNode + 2 + cnt;
		if(face < 1)
			face = 1;

		printf("%d\n",face);
	}

	return 0;
}
