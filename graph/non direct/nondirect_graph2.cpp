#include <stdio.h>
#define MAX 100

struct dothi {
	int V, E;
	int a[MAX][MAX];
};

void docfile(dothi &g) {
	FILE*f = fopen("DSC.txt", "r");
	fscanf(f,"%d%d", &g.V, &g.E);
	// tao khung MTK
	int i, j;
	for(i = 1; i <= g.V; i++) {
		for(j = 1; j <= g.V; j++) {
			g.a[i][j] = 0;
		}
	}

	// gan gia tri cho MTK
	for(i = 1; i <= g.E; i++) {
		int u, v;
		fscanf(f, "%d%d", &u, &v);
		// do thi vo huong nen a[u][v] <=> a[v][u]
		g.a[u][v] = g.a[v][u] = 1;
	}

	fclose(f);
}

void hienMTK(dothi g) {
	int i,j;
	printf("%d\n", g.V);
	for (i = 1; i<=g.V; i++) {
		for( j =1; j<= g.V; j++) {
			printf("%3d",g.a[i][j]);
		}
		printf("\n");
	}
}

void hienDSK(dothi g) {
	int i,j;
	for (i = 1; i<=g.V; i++) {
		for( j = 1; j<= g.V; j++) {
			if(g.a[i][j] == 1) {
				printf("%3d",j);
			}
		}
		printf("\n");
	}
}
int main() {
	dothi g;
	docfile(g);
//	hienMTK(g);
	hienDSK(g);
	return 0;
}
