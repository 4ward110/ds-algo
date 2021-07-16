#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct graph
{
    int V, E;
    int a[MAX][MAX];
};

void docDSC(graph &g) {
    FILE*f = fopen("DSC.txt", "r");
    fscanf(f,"%d%d", &g.V, &g.E);
    int i, j;
    // tao MTK 0
    for(i = 1; i <= g.V; i++) {
        for(j = 1; j <= g.V; j++) {
            g.a[i][j] = 0;
        }
    }
    // gan gia tri MTK
    for(i = 1; i <= g.E; i++) {
        int u, v;
        fscanf(f, "%d%d",&v, &u);
        g.a[u][v] = g.a[v][u] = 1;
    }
    fclose(f);
}

void ghiMTK(graph g) {
    int i, j;
    FILE*f = fopen("MTK1.txt","w");
    fprintf(f, "%d\n", g.V);
    for(i = 1; i <= g.V; i++) {
        for(j = 1;j <= g.V; j++) {
            fprintf(f, "%3d", g.a[i][j]);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}

void ghiDSK(graph g) {
    int i, j;
    FILE*f = fopen("DSK1.txt", "w");
    fprintf(f, "%d\n", g.V);
    for(i = 1; i <= g.V; i++) {
        for(j = 1; j <= g.V; j++) {
            if(g.a[i][j] == 1) {
                fprintf(f,"%3d", j);
            }
        }
        fprintf(f, "\n");
    }
    fclose(f); 
}



int main() {
    graph g;
    docDSC(g);
    ghiDSK(g);
    ghiMTK(g);
    return 0;
}