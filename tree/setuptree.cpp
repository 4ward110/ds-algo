#include <stdio.h>
#include <stdlib.h>
#define MAX 100
//bai giong trong so viettel

struct node{
	int info;
	node *trai,*phai;
};

typedef node*tree;

void khoitao(tree &t) {
	t = NULL;
}
//chen node
void chennode(tree &t, int x) {
	node*p = (node*)malloc(sizeof(node));
	p->info = x;
	p->trai = p->phai = NULL;
	if( t == NULL) {
		t=p;
	}//cay nhi phan tim kiem < goc => ben trai , > goc => ben phai
	// x la cai them vao , t la cai da co(goc)
	// luu y nhap x trung' voi node ,thay khong xet usecase nay.
	else {
		if(t->info < x) {
			// them ben phai
			chennode(t->phai, x);
		}
		else if(t->info > x) {
			chennode(t->trai, x);
		}
	}
	
}

// nhap gia tri

void nhap(tree &t){
	int n, i, a[MAX];
	scanf("%d", &n);
	for( i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		chennode(t, a[i]);
	}
}
// hien cay LRN, NLR, LNR

void hienNLR(tree t) {
	if( t!= NULL) {
		//goc
		printf("%d\t", t->info);
		//de quy hien cay trai
		hienNLR(t->trai);
		// de quy hien phai
		hienNLR(t->phai);
	}
}

void hienLNR(tree t) {
	if( t!= NULL) {
		//de quy hien cay trai
		hienLNR(t->trai);
		//goc
		printf("%d\t", t-> info);
		// de quy hien phai
		hienLNR(t->phai);
	}
}

void hienLRN(tree t) {
	if( t!= NULL) {

		//de quy hien cay trai
		hienLRN(t->trai);
		// de quy hien phai
		hienLRN(t->phai);
		//goc
		printf("%d\t", t->info);
	}
}



int main() {
	tree t;	
	khoitao(t);
	nhap(t);
	hienNLR(t);
	printf("\n");
	hienLNR(t);
	printf("\n");
	hienLRN(t);
	return 0;
}
