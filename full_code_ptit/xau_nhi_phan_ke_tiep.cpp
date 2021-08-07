#include <stdio.h>
#include <string.h>

void sinhtiep() {
	char a[1000];
	scanf("%s", &a);
	int t = strlen(a) - 1;
	while(t >= 0 && a[t] == '1') {
		a[t] = '0';
		t--;
	}
	if(t >= 0) {
		a[t] = '1';
	}
	printf("%s\n", a);
}

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		sinhtiep();
	}
	
	return 0;
}
