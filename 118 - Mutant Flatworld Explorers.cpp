#include<stdio.h>

int grid[51][51];
int rv[] = {0, 1, 0, -1};
int cv[] = {1, 0, -1, 0};
char s[101];
char dir[] = "NESW";

int main(){
	int x, y;
	int X, Y;
	int k,i;

	scanf("%d%d",&X,&Y);

	while(scanf("%d%d%s",&x, &y, s) == 3){
		if(s[0] == 'N')
			k = 0;
		else if(s[0] == 'E')
			k = 1;
		else if(s[0] == 'S')
			k = 2;
		else if(s[0] == 'W')
			k = 3;

		scanf("%s",s);

		for(i=0; s[i]; i++){
			if(s[i] == 'R')
				k = (k+1)%4;
			else if(s[i] == 'L')
				k = (k-1+4)%4;
			else if(s[i] == 'F'){
				if(!(0<=x + rv[k] && x + rv[k]<= X) || !(0<=y + cv[k] && y + cv[k]<= Y)){
					if(grid[x][y])
						continue;

					grid[x][y] = 1;
					break;
				}

				x += rv[k];
				y += cv[k];
			}
		}
		printf("%d %d %c",x, y, dir[k]);
		if(s[i])
			printf(" LOST");
		printf("\n");
	}
		
	return 0;
}