#include<stdio.h>
#include<string.h>

int n[100];
int a[100];

int main(){
	char s[10], buf[10];
	int j, ans;
	int honest, i;

	while(1){
		i = 0;

		while(scanf("%d",&n[i]) == 1){		
			
			if(n[i] == 0)
				break;
			
			scanf("%s%s",buf, s);
		
			if(s[0] == 'h')
				a[i] = 1;

			else if(s[0] == 'l')
				a[i] = -1;

			else if(s[0] == 'o'){
				a[i] = 0;
				break;
			}
			i++;
		}		

		if(n[i] == 0)
			break;

		ans = n[i];
		honest = 1;

		for(j=0; j < i; j++){
			if(n[j] < ans && a[j] != -1){
				honest = 0;
				break;
			}
			else if(n[j] > ans && a[j] != 1){
				honest = 0;
				break;
			}
			else if(n[j] == ans && a[j] != 0){
				honest = 0;
				break;
			}	
		}

		if(honest == 0)
			printf("Stan is dishonest\n");
		else
			printf("Stan may be honest\n");

	}
	return 0;
}