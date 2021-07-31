#include <stdio.h>
#include <memory.h>

bool ok[1005];

struct dsk{
	int dinhke[1005];
	int n;
};

struct dsk dinh[1005];

void DFS(int start) {
	ok[start] = true;
	printf("%d ", start);
	for(int i = 0; i < dinh[start].n; i++) {
		if(!ok[dinh[start].dinhke[i]]) {
			DFS(dinh[start].dinhke[i]);
		}
	}
}

int main() {
	int i, j, t, start;
	scanf("%d", &t);
	while(t > 0) {
		for(i=1;i<=1001;i++){
			dinh[i].n=0;
		}
		memset(ok, false, sizeof(ok));
		int v, e;
		scanf("%d %d %d", &v, &e, &start);
		int count = 0;
		for(i = 0; i < e; i++) {
			int a, b;
			scanf("%d %d",&a, &b);
			dinh[a].dinhke[dinh[a].n] = b;
			dinh[a].n++;
			dinh[b].dinhke[dinh[b].n] = a;
			dinh[b].n++;
		}
		
		DFS(start);
		printf("\n");
		t--;	
	}
	return 0;
}
