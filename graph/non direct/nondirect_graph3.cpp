#include <stdio.h>
#include <conio.h>

#define MAX 100

struct dothi {
	int V, E;
	int a[MAX][MAX];
};

void docfile(dothi &g) {
	int i, j;
	i = 0;
	char c;
	FILE*f = fopen("DSK.txt","r");
	fscanf(f,"%d",&g.V);
	while(i <= g.V) {
		fscanf(f, "%c", &c);
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
	fclose(f);
}

void hienMTK(dothi g) {
	int i, j;
	printf("%d\n", g.V);
	for(i = 1; i <= g.V; i++) {
		for(j = 1; j <= g.V; j++) {
			printf("%3d", g.a[i][j]);
		}
		printf("\n");
	}
}


int demcanh(dothi g) {
	int i, j;
	int count = 0;
	for(i = 1; i <= g.V; i++) {
		for (j = i + 1; j <= g.V; j++) {
			if(g.a[i][j] == 1) {
				count++;
			}
		}
	}
	return count;
}

void hienDSC(dothi g) {
	g.E = demcanh(g);
	printf("%d%3d\n", g.V, g.E);
	int i, j;
	for(i = 1; i <= g.V; i++) {
		for( j = i + 1; j <= g.V; j++) {
			if(g.a[i][j] == 1) {
				printf("%d%3d\n", i, j);
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
