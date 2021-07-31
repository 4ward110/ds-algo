#include <stdio.h>
#include <conio.h>
#include <string.h>

char s[100]; int a[100];
int b[100];

void Try(int i){
	int j;
	for(j = 0 ; j < strlen(s); j++){
		if(b[j] == 0) {
			a[i]=j;
			b[j]=1;
			if(i == strlen(s)) {
				for(int l=1; l<= strlen(s); l++){
				 	printf("%c", s[a[l]]);
				}
				printf(" ");
			}
			else{
				Try(i+1);
			}
			b[j]=0;
		}
	}
}
int main(){
	int test;
	scanf("%d\n",&test);
	while(test>0){
		gets(s);
		Try(1);
		printf("\n");
		test--;
	}
	return 0;
}
