#include <stdio.h>
int a[1001][1001];

int main() {
	int V, E;
	int t;
    scanf("%d", &t);

    while(t > 0) {
    	for(int i = 0; i < 1001;i++) {
    		for(int j = 0; j < 1001; j++) {
    			a[i][j] = a[j][i] = 0;
			}
		}
        scanf("%d %d", &V, &E);
        int i, j;

        for(i = 0; i < E; i++) {
            int u, v;
            scanf("%d %d",&v, &u);
            a[v][u] = a[u][v] = 1;
        }

        for(i = 1; i <= V; i++) {
            printf("%d: ",i);
            for(j = 1; j <= V; j++) {
                if(a[i][j] == 1) {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
        t--;
    }
    return 0;
}
