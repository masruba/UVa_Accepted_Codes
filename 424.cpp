//AC
#include<stdio.h>
#include<string.h>

int k;

void reverse(char *A,int LA){
	int i,j;
	char t;

	for(i=0,j = LA-1;i<j;i++,j--){
		t = A[i];
		A[i] = A[j];
		A[j] = t;
	}
}


int main(){
	
/*
	array size at least 101 korba.
	again, 2 ta 100 digit number jog kore kintu jogfol 101 digit hote pare. so actually 102 lagbe.
	tai 5/6 beshi niba.	
*/
//	char A[100],B[100],s[100];
	char A[105],B[105],s[105];
	int l1,l2,L,i = 0,carry = 0,a,b,j,flag = 1,c;

//	for(j=1;j<=100;j++){	//input at most 100 ta. so condition dorkar nai
	for(j=1;;j++){
		carry = 0;
		flag = 1;
		k = 0;
		if(j == 1){
			gets(A);
			gets(B);
		
			if(A[k] == '0' || B[k] == '0')
				flag = 0;
	
			l1 = strlen(A);
			l2 = strlen(B);
			reverse(A,l1);
			reverse(B,l2);
		}
		else{
			gets(B);
			l2 = strlen(B);
		
			if(B[k] == '0')
				flag = 0;
				
			reverse(B,l2);
		
		}


	
		for(i=0;i<l1 || i<l2 || carry;i++){
			if(i<l1)
				a = A[i]-'0';
			else
				a = 0;

			if(i<l2)
				b = B[i]-'0';
			else
				b = 0;

			s[i] = (a+b+carry)%10+'0';
			carry = (a+b+carry)/10;
		}

		L = i;

		s[i] = '\0';
	

		if(flag == 0){
			reverse(s,L);
			break;
		}
		else{
			for(c = 0; s[c] ;c++)
				A[c] = s[c];
			A[c] = '\0';
			l1 = L;
		}

	}
	
	printf("%s\n",s);
	
	return 0;
}
