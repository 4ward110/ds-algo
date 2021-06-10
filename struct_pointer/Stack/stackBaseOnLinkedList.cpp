#include <stdio.h>
#include <stdlib.h>


struct node {
	int info;
	node* next;
};

typedef node *Pnode;

void khoitao(Pnode &H) {
	H = NULL;
}

int kiemtrarong(Pnode H) {
	if(H == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int push(Pnode &H, int x) {
	Pnode p;
	p = (node*)malloc(sizeof(node));
	p -> info = x;
	p -> next = H;
	H = p;
//	printf("dia chi %d\n",p);
}

int pop(Pnode &H) {
	int x;
	Pnode p;
	x = H -> info;
	p = H;
	H = H -> next;
	free(p);
	return x;
}

int nhapstack(Pnode &H) {
	int n, i, x;
	scanf("%d", &n);
	for(i = 0; i< n; i++) {
		scanf("%d", &x);
		push(H,x);
	}
}

int hienstack(Pnode &H) {
	while(!kiemtrarong(H)) {
		printf("%3d",pop(H));
	}
}

int main() {
	Pnode H;
	khoitao(H);
	nhapstack(H);
	hienstack(H);
	return 0;
}
