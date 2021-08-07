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
	l.cuoi = l.dau = NULL;
}

void themdau(list &l) {
	int x;
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

void loc(list &l) {
	node*i = l.dau;
	// lay tung diem 1 de xoa
	while(i->next != NULL && i!=NULL) {
		node*p = i;
		while(p->next != NULL) {
			if(i->info == p->next->info) {
				node*dup = p->next;
				p->next = p->next->next;
				delete (dup);
			}
			else {
				p = p->next;
			}
		}
		i = i->next;
	}
}

int main() {
	list l;
	int n;
	scanf("%d", &n);
	khoitao(l);
	for(int i = 0; i < n; i++) {
		themdau(l);
	}
	loc(l);
	hien(l);
	return 0;
}
