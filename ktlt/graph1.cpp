#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct graph
{
    int E,V;
    int a[100][100];
};

void docfile(graph &g) {
    FILE*f = fopen("MTK.txt","r");
    fscanf(f,"%d",&g.V);
    int i, j;
    for(i = 1; i <= g.V; i++) {
        for(j = 1; j <= g.V; j++) {
            fscanf(f,"%d",&g.a[i][j]);
        }
    }
    fclose(f);
}

void hienMTK(graph g) {
    int i, j;
    for(i = 1; i <= g.V; i++) {
        for(j = 1; j <= g.V; j++) {
            printf("%3d", g.a[i][j]);
        }
        printf("\n");
    }
}

int demcanh(graph g) {
    int i, j;
    int count = 0;
    for(i = 1; i <= g.V; i++) {
        for(j = i + 1; j <= g.V; j++) {
            if(g.a[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}


void ghiDSC(graph g) {
    int i, j, sc;
    sc = demcanh(g);
    FILE*f = fopen("DSC.txt", "w");
    fprintf(f, "%3d%3d\n",g.V,sc);
    for(i = 1; i <= g.V; i++) {
        for(j = i + 1; j <= g.V; j++) {
            if(g.a[i][j] == 1) {
                fprintf(f,"%3d%3d\n",i, j);
            }
        }
    }
    fclose(f);
}

void ghiDSK(graph g) {
    int i, j;
    FILE*f = fopen("DSK.txt", "w");
    fprintf(f,"%d\n",g.V);
    for(i = 1; i <= g.V; i++) {
        for(j = 1;j <= g.V; j++) {
            if(g.a[i][j] == 1) {
                fprintf(f, "%3d",j);
            }
        }
        fprintf(f,"\n");
    }
    fclose(f);
}


int main() {
    graph g;
    docfile(g);
    hienMTK(g);
    ghiDSC(g);
    ghiDSK(g);
    return 0;
}