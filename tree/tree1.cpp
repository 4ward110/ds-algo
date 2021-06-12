#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int info;
	node*trai,*phai;
} *tree;

//typedef node*tree;

void khoitao(tree &t) {
	t = NULL;
}

void chennode(tree &t, int x) {
	node*p = (node*)malloc(sizeof(node));
	p->info = x;
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

void hien(tree t) {
	if(t != NULL){
		printf("%d\t",t->info);
		hien(t->trai);
		hien(t->phai);
	}
}

void hienLNR(tree t){
	if(t!=NULL){
		hienLNR(t->trai);
		printf("%d\t",t->info);
		hienLNR(t->phai);
	}
}

int main() {
	tree t;
	khoitao(t);
	nhap(t);
	hien(t);
	return 0;
}
