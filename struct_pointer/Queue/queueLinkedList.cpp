#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	node *next;
};

typedef node *Pnode;

struct Queue {
	Pnode H,T;
};

void khoitao(Queue &q) {
	q.H = q.T = NULL;
}

int kiemtrarong(Queue q) {
	if(q.H == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int push(Queue &q, int x) {
	if (kiemtrarong(q)) {
		q.H = (node*)malloc(sizeof(node));
		q.H -> data = x;
		q.H -> next = q.H;
		q.T = q.H;
	}
	else {
	// day vao duoi T
	q.T->next = (node*)malloc(sizeof(node));
	q.T = q.T->next;
	q.T->data = x;
	q.T->next = NULL;
	}
}

int get(Queue &q) {
	Pnode p;
	int x;
	p = q.H;
	q.H = p->next;
	x = p->data;
	free(p);
	return x;
}

int nhap(Queue &q) {
	int i,m,x;
	scanf("%d", &m);
	for(i = 0 ; i< m; i++) {
		scanf("%d", &x);
		push(q,x);
	}
}

int hien(Queue &q) {
	while(!kiemtrarong(q)) {
		printf("%3d",get(q));
	}
}



int main() {
	Queue q;
	nhap(q);
	hien(q);
	return 0;
}
