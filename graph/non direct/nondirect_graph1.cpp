#include <stdio.h>
#define MAX 100

struct dothi {
	int V, E;
	int a[MAX][MAX];
};

void docfile(dothi &g) {
	FILE*f = fopen("MTK.txt","r");
	fscanf(f,"%d",&g.V);
	int i,j;
	for(i = 1; i <= g.V; i++) {
		for(j = 1; j <= g.V; j++) {
			fscanf(f,"%d", &g.a[i][j]);
		}
	}
	fclose(f);
}

void hienMTK(dothi g) {
	int i,j;
	for(i = 1; i <= g.V; i++) {
		for(j = 1; j <= g.V; j++) {
			printf("%3d", g.a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


int demcanh(dothi &g) {
	int count = 0;
	int i, j;
	for(i = 1; i <= g.V; i++) {
		for(j = i + 1; j <= g.V; j++) {
			if(g.a[i][j] == 1) {
				count++;
			}
		}
	}
	return count;
}

void hienDSC(dothi &g) {
	g.E = demcanh(g);
	printf("%d%3d\n", g.V, g.E);
	int i, j;
	for(i = 1; i <= g.V; i++) {
		for(j = i + 1; j <= g.V; j++) {
			if(g.a[i][j] == 1) {
				printf("%d%3d\n",i, j);
			}
		}
	}
}


void hienDSK(dothi &g) {
	int i,j;
	printf("%d\n",g.V);
	for(i = 1; i <= g.V; i++) {
		for(j = 1; j <= g.V; j++) {
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
//	hienDSC(g);
	hienDSK(g);
	return 0;
}
