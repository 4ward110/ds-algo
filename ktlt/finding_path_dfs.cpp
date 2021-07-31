#include <stdio.h>
#include <memory.h>

bool ok[1005];
int truoc[1005];

struct dsk{
	int dinhke[1005];
	int n;
};

struct dsk dinh[1005];

void DFS(int start, int end) {
	if(ok[end]) return;
	ok[start] = true;
	for(int i = 0; i < dinh[start].n; i++) {
		if(!ok[dinh[start].dinhke[i]]) {
			truoc[dinh[start].dinhke[i]] = start;
			DFS(dinh[start].dinhke[i], end);
		}
	}
}

void trace(int start, int end) {
	if(!ok[end]) {
		printf("-1");
		return;
	}
	
	int count = 0;
	int a[1001];
	
	while(start != end) {
		a[count] = start;
		start = truoc[start];
		count++;
	}
	a[count] = end;
	for(int i = count;i >= 0; i--) {
		printf("%d ", a[i]);
	}
}

int main() {
	int i, j, t, start, end;
	scanf("%d", &t);
	while(t > 0) {
		for(i=1;i<=1001;i++){
			dinh[i].n=0;
		}
		memset(ok, false, sizeof(ok));
		int v, e;
		scanf("%d %d %d %d", &v, &e, &start, &end);
		for(i = 0; i < e; i++) {
			int a, b;
			scanf("%d %d",&a, &b);
			dinh[a].dinhke[dinh[a].n] = b;
			dinh[a].n++;
			dinh[b].dinhke[dinh[b].n] = a;
			dinh[b].n++;
		}
		
		DFS(start, end);
		trace(end, start);
		printf("\n");
		t--;	
	}
	return 0;
}
