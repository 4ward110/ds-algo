#include <stdio.h>
#include <string.h>

int main() {
	int a[100][100];
	// doc gia tri
	int i, j;
	i = 0;
	j = 0;
	char c[100];
	int v;
	scanf("%d", &v);
	while(i <= v) {
		fgets(c, 100, stdin);
		int sum = 0;
		while(j <= strlen(c) - 1) {
			if(c[j] <= '9' && c[j] >= '0') {
				sum = 10*sum + (c[j] - '0');
			}
			else {
				a[i][sum] = 1;
				sum = 0;
			}
			j++;
		}
		i++;
		j = 0;
	}
	// in gia tri
	for(int i = 1; i <= v; i++) {
		for(int j = i + 1; j <= v; j++) {
			if(a[i][j] == 1) {
				printf("%d %d\n", i, j);
			}
		}
	}
	
	return 0;
}
