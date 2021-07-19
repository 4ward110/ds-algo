#include <stdio.h>

struct graph
{
    int t;
    int V, E;
    int a[1000][1000];
};

int main() {
    graph g;
    scanf("%d", &g.t);
    while(g.t>0) {
        scanf("%d %d", &g.V, &g.E);
        int i, j;

        for(i = 0; i < g.E; i++) {
            int u, v;
            scanf("%d %d",&v, &u);
            g.a[v][u] = g.a[u][v] = 1;
        }

        for(i = 1; i <= g.V; i++) {
            printf("%d: ",i);
            for(j = 1; j <= g.V; j++) {
                if(g.a[i][j] == 1) {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
        g.t--;
    }
    return 0;
}