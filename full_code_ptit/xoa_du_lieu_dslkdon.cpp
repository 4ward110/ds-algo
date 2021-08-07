#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	node *next;
};

struct list {
	node *dau, *cuoi;
};

void khoitao(list &l) {
	l.dau = l.dau = NULL;
}

void themdau(list &l) {
	int i, x;
	scanf("%d", &x);
	node*p = (node*)malloc(sizeof(node));
	p->info = x;
	p->next = NULL;
	if(l.dau == NULL) {
		l.dau = l.cuoi = p;
	}
	else {
		l.cuoi->next = p;
		l.cuoi = p;
	}
}

void hien(list l) {
	node*i = l.dau;
	while(i) {
		printf("%d ", i->info);
		i = i->next;
	}
}

void xoa(list &l) {
	int x;
	scanf("%d", &x);
	node*i = l.dau;
	node*temp = l.dau, *pre;
	// neu gia tri can xoa la gia tri cua node dau
	while(temp != NULL && temp -> info == x) {
		l.dau = temp -> next;
		free(temp);
		temp = l.dau;
	}
	// truong hop con lai
	while(temp!=NULL) {
		while(temp != NULL && temp->info != x) {
			pre = temp;
			temp = temp->next;
		} 
		// neu gia tri khong co trong dah sach
		if(temp == NULL) {
			return;
		}
		pre->next = temp->next;
		free(temp);
		temp = pre->next;
	}
}


int main() {
	list l;
	int n;
	scanf("%d", &n);
	int a[n];
	khoitao(l);
	for(int i = 0; i < n; i++) {
		themdau(l);
	}
	xoa(l);
	hien(l);
	return 0;
}
