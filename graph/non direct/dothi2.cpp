#include <stdio.h>
#define MAX 100

struct dothi {
	int V, E;
	int a[MAX][MAX];
};

void docfile(dothi &g) {
	// doc so dinh va so canh(dinh 5 canh 8)
	FILE*f = fopen("DSC.txt","r");
	fscanf(f,"%d%d", &g.V, &g.E);
//	printf("%d%3d",g.V, g.E);
	// tao khung ma tran ke ( ma tran bang 0 )
	int i,j;
	for( i = 1; i<=g.V; i++) {
		for( j =1; j<=g.V; j++) {
			g.a[i][j] == 0;
		}
	}
	int u,v;
	for( i = 1; i<=g.E; i++) {
		fscanf(f,"%d%d",&u,&v);
		g.a[u][v] = g.a[v][u] = 1;
	}
	
	fclose(f);
}

void hienMTK(dothi &g) {
	int i,j;
	printf("%d\n", g.V);
	for (i = 1; i<=g.V; i++) {
		for( j =1; j<= g.V; j++) {
			printf("%3d",g.a[i][j]);
		}
		printf("\n");
	}
}

void hienDSK(dothi &g) {
	int i,j;
	printf("%d\n",g.V);
	for(i = 1; i<= g.V; i++) {
		for( j = 1; j<= g.V; j++) {
			if(g.a[i][j] == 1)
			printf("%3d",j);
		}
		printf("\n");
	}
}


int main() {
	dothi g;
	docfile(g);
	hienMTK(g);
	hienDSK(g);
	return 0;
}
