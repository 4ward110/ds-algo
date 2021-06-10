#include <stdio.h>
#define MAX 100


struct Queue {
	int a[MAX];
	int dau,cuoi;
};

void khoitao(Queue &q) {
	q.dau = 0;
	q.cuoi = -1;
}

int kiemtraday(Queue &q) {
	if(q.cuoi == MAX) {
		return 1;
	}
	else {
		return 0;
	}
}

int kiemtrarong(Queue &q) {
	if(q.dau < 0 || q.dau > q.cuoi) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(Queue &q, int x) {
	if(!kiemtraday(q)) {
		q.cuoi++;
		q.a[q.cuoi] = x;
	}
}

int get(Queue &q) {
	int x;
	if(!kiemtrarong(q)) {
		x = q.a[q.dau];
		q.dau++;
	}
	return x;
}

void nhap(Queue &q) {
	int m,i,b[MAX];
	scanf("%d",&m);
	for( i =0; i< m; i++) {
		scanf("%d",&b[i]);
		push(q,b[i]);
	}
}

void hien(Queue q){
	while(!kiemtrarong(q))
	printf("%d\t",get(q));
}



int main() {
	Queue q;
	khoitao(q);
	nhap(q);
	hien(q);
	return 0;
}
