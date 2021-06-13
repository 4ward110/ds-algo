#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	node*trai,*phai;
} *tree;

void khoitao(tree &t) {
	t = NULL;
}

void chennode(tree &t, int x) {
	node*p = (node*)malloc(sizeof(node));
	p->info  = x;
	p->trai = p->phai = NULL;
	if(t == NULL) {
		t = p;
	}
	else {
		if(t->info < x) {
			chennode(t->phai, x);
		}
		else if(t->info > x) {
			chennode(t->trai, x);
		}
	}
}

void nhap(tree &t) {
	int n,i, a[100];
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		chennode(t, a[i]);
	}
}

void hienNLR(tree t) {
	if(t != NULL){
		printf("%d\t",t->info);
		hienNLR(t->trai);
		hienNLR(t->phai);
	}
}

void hienLNR(tree t){
	if(t!=NULL){
		hienLNR(t->trai);
		printf("%d\t",t->info);
		hienLNR(t->phai);
	}
}

void hienLRN(tree t) {
	if(t != NULL) {
		hienLRN(t->trai);
		hienLRN(t->phai);
		printf("%d\t",t->info);
	}
}

node*Timkiem(tree t, int x) {
	if(t != NULL) {
		if(t->info == x) {
			node*p = t;
			return p;
		}
		if(t->info > x) {
			return Timkiem(t->trai, x);
		}
		if(t->info < x) {
			return Timkiem(t->phai, x);
		}
	}
	return NULL;
}

void huycay(tree &t) {
	if(t != NULL) {
		huycay(t->trai);
		huycay(t->phai);
		delete t;
		t = NULL;
	}
}

int main() {
	tree t;
	khoitao(t);
	nhap(t);
	hienNLR(t);
	int x;
	scanf("%d", &x);
	node*p = Timkiem(t,x);
	if(p != NULL){
		printf("%d\n",p->info);
	}
	else {
		printf("khong ton tai node");
	}
	return 0;
}
