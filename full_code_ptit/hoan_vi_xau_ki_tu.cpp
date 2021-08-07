#include <stdio.h>
#include <string.h>

char s[10]; //input
int a[10]; //out put
int chuaxet[10];//danh dau

void Try(int i) {
	for(int j = 0; j < strlen(s) ; j++) {
		if(!chuaxet[j]) {
			a[i] = j;
			chuaxet[j] = 1;
			if(i == strlen(s)) {
				for(int l = 1; l <= strlen(s); l++) 
                {
                    printf("%c",s[a[l]]);
                }
                printf(" ");
			}
			else {
				Try(i + 1);
			}
			chuaxet[j] = 0;
		}
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while(t > 0) {
		scanf("%s", &s);
		Try(1);
		printf("\n");
		t--;
	}
	
	return 0;
}
