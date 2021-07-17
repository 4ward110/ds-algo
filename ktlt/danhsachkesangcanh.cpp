#include <stdio.h>
#include <conio.h>

#define MAX 50

struct dothi {
	int V, E;
	int a[MAX][MAX];
};

void docfile(dothi &g) {
	int i, j;
	i = 0;
	char c;
	scanf("%d",&g.V);
	while(i <= g.V) {
		scanf("%c", &c);
		if(c == '\n') {
			i++;
		}
		else {
			if(c != ' ') {
				j = c - '0';
				g.a[i][j] =  1;
			}
		}
	}
}
void hienDSC(dothi g) {
	int i, j;
	for(i = 1; i <= g.V; i++) {
		for( j = i + 1; j <= g.V; j++) {
			if(g.a[i][j] == 1) {
				printf("%d %d\n", i, j);
			}
		}
	}
}
int main() {
    dothi g;
    docfile(g);
    hienDSC(g);
    return 0;
}