//special cases: 0 coins can be given as input!!!
#include<stdio.h>

#define MAX 101

#define myabs(x) ( ((x) > 0) ? (x):-(x) )

int n, m[MAX];

int q[50005], nq;
int vis[50005];

int main(){
	int min;
	int k;
	int t, s;
	char buf[100];

	scanf("%d",&k);
	gets(buf);

	for(int t=1;t<=k;t++){
		buf[0] = '\0';
		gets(buf);

		int num = 0;
		n = 0;
		for(int i=0; buf[i]; i++){
			if(buf[i] >= '0' && buf[i] <= '9')
				num = num*10 + (buf[i] - '0');

			else if(buf[i] == ' '){
				m[n++] = num;
				num = 0;
			}
		}
		m[n++] = num;

		int sum = 0;
		for(int i=0;i<n;i++){
			sum += m[i];
		}

		q[0] = 0;
		vis[0] = t;
		nq = 1;

		min = (1<<30);
		for(int i=0; i<n; i++){
			for(int j=nq-1; j>=0; j--){
				s = q[j] + m[i];
				if(myabs((s - (sum-s))) < min)
					min = myabs(s - (sum-s));

				if(vis[s] != t){
					vis[s] = t;
					q[nq++] = s;
				}
			}
		}

		if(min == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
