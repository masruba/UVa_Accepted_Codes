#include<stdio.h>
#include<map>
#include<string>
using namespace std;

char s[10];

int main(){
	int n, i, j, k, l, p;
	map<string, int> m;
	string str;

	int cnt = 1;
	int flag;

	for(i=0;i<26;i++){
		s[0] ='a'+i;
		s[1] = '\0';

		str = string(s);
		m[str] = cnt++;
	}

	for(i=0;i<25;i++){
		for(j=i+1;j<26;j++){
			s[0] = 'a' + i;
			s[1] = 'a' + j;
			s[2] = '\0';

			str = string(s);
			m[str] = cnt++;
		}
	}

	for(i=0;i<24;i++){
		for(j=i+1;j<25;j++){
			for(k=j+1;k<26;k++){
				s[0] = 'a' + i;
				s[1] = 'a' + j;
				s[2] = 'a' + k;
				s[3] = '\0';

				str = string(s);
				m[str] = cnt++;
			}
		}
	}

	for(i=0;i<23;i++){
		for(j=i+1;j<24;j++){
			for(k=j+1;k<25;k++){
				for(l=k+1;l<26;l++){
					s[0] = 'a' + i;
					s[1] = 'a' + j;
					s[2] = 'a' + k;
					s[3] = 'a' + l;
					s[4] = '\0';

					str = string(s);
					m[str] = cnt++;
				}
			}
		}
	}

	for(i=0;i<22;i++){
		for(j=i+1;j<23;j++){
			for(k=j+1;k<24;k++){
				for(l=k+1;l<25;l++){
					for(p=l+1;p<26;p++){
						s[0] = 'a' + i;
						s[1] = 'a' + j;
						s[2] = 'a' + k;
						s[3] = 'a' + l;
						s[4] = 'a' + p;
						s[5] = '\0';

						str = string(s);
						m[str] = cnt++;
					}
				}
			}
		}
	}


	while(scanf("%s",s)==1){
		str = string(s);

		if(m.find(s)==m.end())
			printf("0\n");
		else{
			printf("%d\n", m[str]);
		}
	}

	return 0;
}
