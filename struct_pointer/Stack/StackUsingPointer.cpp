#include <stdio.h> 
#include <stdlib.h>
#define MAX 100

struct node {
	int info;
	node*next;
};

struct stack {
	node*n;
};

void khoitao(stack &s) {
	s.n = NULL;
}

int kiemtrarong(stack s) {
	if(s.n == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(stack &s, int x) {
	node*p = (node*)malloc(sizeof(node));
	p->info = x;
	p->next = NULL;
	if(kiemtrarong(s)) {
		s.n = p;
	}
	else {
		p->next = s.n;
		s.n = p;
	}
}

int pop(stack &s) {
	int x;
	if(!kiemtrarong(s)){
		x = s.n->info;
		s.n = s.n->next;
	}
	return x;
}

void nhapstack(stack &s) {
	int i, m, x;
	scanf("%d", &m);
	for(i = 0; i < m; i++) {
		scanf("%d",&x);
		push(s, x);
	}
}

void hienstack(stack &s) {
	while(kiemtrarong(s) == 0){
		printf("%d\t",pop(s));
	}	
}


int main() {
	stack s;
	khoitao(s);
	nhapstack(s);
	hienstack(s);
	return 0;
}
