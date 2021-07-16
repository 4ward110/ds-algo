#include <stdio.h>
#include <conio.h>
#define MAX 100

struct graph
{
    int V;
    int a[MAX][MAX];
};

void docfile(graph &g) {
    int i;
    int j;
    i = 0;
    char c;
    FILE*f = fopen("DSK.txt", "r");
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
    // int i, j;
    printf("%d\n", g.V);
    for(i = 1; i <= g.V; i++) {
        for(j = 1; j <= g.V; j++) {
            printf("%3d",g.a[i][j]);
        }
        printf("\n");
    }

}

void ghiDSC(graph g) {
    int i, j;
    int canh = 0;
    FILE*f = fopen("DSC2.txt", "w");
    for(i = 1; i <= g.V; i++) {
        for(j = 1; j <= g.V; j++) {
            if(g.a[i][j]==1) canh++;
        }
    }
    fprintf(f,"%3d%3d",g.V,canh);
    for(i = 1; i <= g.V; i++) {
        for (j = i + 1; j <= g.V; j++) {
            if(g.a[i][j] == 1) {
                fprintf(f, "%3d%3d\n", i, j);
            }
        }
    }
    fclose(f);
}

int main() {
    graph g;
    docfile(g);
    // ghiDSC(g);
    return 0;
}