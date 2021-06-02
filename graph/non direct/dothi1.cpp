#include <stdio.h>
#define MAX 100

struct dothi {
	// V : dinh E canh
	int V, E;
	int a[MAX][MAX];
};

void docfile(dothi &g) {
	FILE*f = fopen("MTK.txt", "r");
	// doc. dinh
	fscanf(f, "%d", &g.V);
	int i, j;
	for(i = 1; i <= g.V; i++) {
		for (j = 1; j <= g.V; j++) {
			fscanf(f, "%d", &g.a[i][j]);
		}
	}
	fclose(f);
}

void hienMTK(dothi g) {
	int i, j;
	for(i = 1; i <= g.V ; i++) {
		for (j = 1; j <= g.V ; j++) {
			printf("%3d", g.a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int demcanh(dothi &g) {
	int count = 0;
	int i, j;
	for(i = 1; i <= g.V ; i++) {
		for (j = i+1 ; j <= g.V ; j++) {
			if(g.a [i][j] == 1) {
				count++;
			}
		}
	}
	return count;
}
// chi xet 1 phia cua do thi nua tren hoac nua duoi => phai chia doi
void hienDSC(dothi &g) {
	g.E = demcanh(g);
	printf("%d%3d\n", g.V , g.E );
	int i, j;
	for(i = 1; i <= g.V ; i++) {
		for (j = i+1; j <= g.V ; j++) {
			if(g.a [i][j] == 1) {
				printf("%d%3d\n",i ,j );
			}
		}
	}
}



int main() {
	// khai bao tap dinh va canh
	dothi g;
	docfile(g);
	hienMTK(g);
	hienDSC(g);
	return 0;
}
