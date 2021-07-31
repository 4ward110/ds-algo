#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

bool ok[1005];
int truoc[1005];

struct dsk{
	int dinhke[1005];
	int n;
};

struct dsk dinh[1005];

struct node {
	int info;
	node *next;
};

typedef struct node *Pnode;

struct Queue {
	Pnode H, T;
};

int ktrong(Queue q) {
	if(q.H == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void put(Queue &q, int x) {
	if(ktrong(q)) {
		q.H = (node*)malloc(sizeof(node));
		q.H->info = x;
		q.H->next = q.T;
		q.T = q.H;
		return;
	}
	else {
		q.T->next = (node*)malloc(sizeof(node));
		q.T = q.T->next;
		q.T->info = x;
		q.T->next = NULL;
	}
}

int get(Queue &q) {
	Pnode p;
	int x;
	p = q.H;
	q.H = p->next;
	if(ktrong(q)) {
		q.T = NULL;
	}
	x = p->info;
	free(p);
	return x;
}

void khoitao(Queue &q) {
	q.H = q.T = NULL;
}

void BFS(int start, int end) {
	Queue q;
	khoitao(q);
	if(ok[end]) return;
	put(q,start);
	while(!ktrong(q)) {
		int top = get(q);
		ok[top] = true;
		for(int i = 0; i < dinh[top].n; i++) {
			if(!ok[dinh[top].dinhke[i]]) {
				ok[dinh[top].dinhke[i]] = true;
				truoc[dinh[top].dinhke[i]] = top;
				put(q, dinh[top].dinhke[i]);
			}
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
		int count = 0;
		for(i = 0; i < e; i++) {
			int a, b;
			scanf("%d %d",&a, &b);
			dinh[a].dinhke[dinh[a].n] = b;
			dinh[a].n++;
			dinh[b].dinhke[dinh[b].n] = a;
			dinh[b].n++;
		}
		
		BFS(start, end);
		trace(end, start);
		printf("\n");
		t--;	
	}
	return 0;
}
