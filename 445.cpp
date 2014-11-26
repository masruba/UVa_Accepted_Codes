#include<stdio.h>
#include<string.h>

char s[150];

int main(){
	int flag=0,ks=0,len,i,j,count;
	while(1){
		if(ks>0)
			printf("\n");
		while(1){
			if(gets(s)==0){
				flag=-1;
				break;
			}
			len=strlen(s);
			if(len==0)
				break;
			count=0;
			for(i=0;i<len;i++){
				if(s[i]>='0'&&s[i]<='9')
					count+=s[i]-'0';
				else if(s[i]=='!'){
					count=0;
					printf("\n");
				}
				else if(s[i]=='b'){
					for(j=0;j<count;j++){
						printf(" ");
					}
					count=0;
				}
				else if( (s[i]>='A'&&s[i]<='Z') || s[i]=='*'){
					for(j=0;j<count;j++){
						printf("%c",s[i]);
					}
					count=0;
				}
				if(i==len-1){
					if(s[i]!='!'){
						printf("\n");
					}
				}
			}
		}
		if(flag==-1)
			break;
		ks++;
	}

	return 0;
}