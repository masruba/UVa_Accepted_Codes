#include<stdio.h>
#include<string.h>

int ref_p10[] = {100, 1000, 1000000};
char p10[][10] = {"hundred", "thousand", "million"};

char tens[][10] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

char ones[][10] = {
	"zero", "one", "two", "three", "four",
	"five", "six", "seven", "eight", "nine",
	"ten",	"eleven", "twelve", "thirteen", "fourteen",
	"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

int main(){
	int n, n1;
	int i;
	int num;
	char s[500], c[50];

	while(gets(s)){
		char* t = strtok(s, " ");
		sscanf(t,"%s", c);

		n = 0;
		if(strcmp(c, "negative") == 0){
			num = -1;
			t = strtok(NULL," ");
		}
		else
			num = 1;

		n1 = 0;
		while(t != NULL){
			sscanf(t,"%s",c);

			//ones:
			for(i=0; i<20; i++){
				if(strcmp(c, ones[i])==0)
					break;
			}

			if(i < 20){
				n1 += i;

				t = strtok(NULL, " ");
				continue;
			}

			//tens:
			for(i=0; i<8; i++){
				if(strcmp(c, tens[i])==0)
					break;
			}
			if(i < 8){
				n1 += (i+2)*10;		// starts from twenty
				t = strtok(NULL," \n\r");
				continue;
			}

			//p10s
			for(i=0;i<3;i++){
				if(strcmp(c, p10[i])==0)
					break;
			}
			if(i < 3){
				n1 *= ref_p10[i];
				if(i){
					n += n1;
					n1 = 0;
				}
				t = strtok(NULL," ");
			}
		}

		if(n1)
			n += n1;

		printf("%d\n",num*n);
	}
	return 0;
}
