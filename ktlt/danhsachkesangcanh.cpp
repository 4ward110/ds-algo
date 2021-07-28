#include <stdio.h>
#include <string.h>
#define MAX 100

struct dothi {
	int V, E;
	int a[MAX][MAX];
};

void docfile(dothi &g) {
	char c[MAX];
	scanf("%d",&g.V);
	int i, j;
	i = 0;
	while(i < g.V) {
		gets(c);
		int len = strlen(c);
		int so = 0;
		j = 0; 
		while(j < len) 
		{
			if(j == strlen(c)) {
				i++;
			}
			else {
				if(c[j] != ' ') {
					so = 10*so + (int)(c[j] - '0');
				}
				else if (so > 0){
					g.a[i][so] =  1;
					so = 0;
				}
			}
			j++;
		}
	}
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}


void hienDSC(dothi g) {
	int i, j;
	for(i = 1; i <= g.V; i++) {
		for( j = i + 1; j <= g.V; j++) {
			if(g.a[i][j] == 1) {
				printf("%d %d\n", i, j);
			}
		}
	}
}

int main() {
    dothi g;
    docfile(g);
    hienDSC(g);
    return 0;
}
