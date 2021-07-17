#include <stdio.h>
#define MAX 100

struct graph
{
    int t;
    int V, E;
    int a[MAX][MAX];
};

int main() {
    graph g;
    scanf("%d", &g.t);
    while(g.t>0) {
        scanf("%d%d", &g.V, &g.E);
        int i, j;

        for(i = 1; i <= g.E; i++) {
            int u, v;
            scanf("%d%d",&v, &u);
            g.a[u][v] = g.a[v][u] = 1;
        }

        for(i = 1; i <= g.V; i++) {
            printf("%d:",i);
            for(j = 1; j <= g.V; j++) {
                if(g.a[i][j] == 1) {
                    printf("%3d", j);
                }
            }
            printf("\n");
        }
        g.t--;
    }
    return 0;
}