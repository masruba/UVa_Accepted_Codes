// pls submit this again. eta ac kora dorkar.vul koi?? pls submit kro. 

/*
	AC code!
	just "i" er kechchha!
	see below for details
*/

#include<stdio.h>
#include<string.h>

char ref[] 	= "AEHIJLMOSTUVWXYZ12358";
char mir[] 	= "A3HILJMO2TUVWXY51SEZ8";

char temp[25];

int check_palin(char *s){
	int i,j, l  = strlen(s);

	for(i=0,j=l-1;i<j;i++,j--){
		if(s[i] != s[j])
			break;
	}
	
	if(i<j)	return 0;
	else	return 1;

}

void rev(char *s){
	int i,j,l  = strlen(s);
	char t;

	for(i = 0,j = l-1;i<j;i++,j--){
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}
	

int check_mirror(char *s){
	int i,j,m = 1;
	
	strcpy(temp,s);

	for(i = 0;s[i];i++){
		for(j = 0;ref[j];j++)
			if(temp[i] == ref[j])
				break;

		if(ref[j] == '\0'){
			m = 0;
			break;
		}

		temp[i] = mir[j];
	}

	if(m){
		rev(temp);
		if(strcmp(temp,s))
			m = 0;
	}

	return m;
}


int main(){
	char s[25];		
	int i,j;

	while(scanf("%s",s)==1){

		i = check_palin(s);
		j = check_mirror(s);

		if(i){
//			if(!j)	printf("%s -- is a regular palindriome.\n",s);		//extra I silo! in palindr *i* ome
			if(!j)	printf("%s -- is a regular palindrome.\n",s);
			else 		printf("%s -- is a mirrored palindrome.\n",s);
		}

		else{
//			if(!j)	printf("%s -- is not a palindriome.\n",s);			//extra I silo!
			if(!j)	printf("%s -- is not a palindrome.\n",s);
			else 		printf("%s -- is a mirrored string.\n",s);
		}

		printf("\n");

	}

	return 0;
}
