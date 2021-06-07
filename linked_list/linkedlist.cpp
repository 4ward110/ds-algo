#include <stdio.h>
#include <stdlib.h>


struct node{
	int info;
	node*next;
};

struct danhsach {
	node *dau,*cuoi;
};

void khoitao(danhsach &d) {
	d.dau = d.cuoi = NULL;
}



void themdau(danhsach &d) {
	int i,x;
	scanf("%d", &x);
	node*p = (node*)malloc(sizeof(node));
	p -> info = x;
	p -> next = NULL;
	if(d.dau == NULL) {
		d.dau = d.cuoi = p;
	}	
	else {
		p->next = d.dau;
		d.dau = p;
	}
}

void themcuoi(danhsach &d) {
	int x;
	scanf("%d",&x);
	node*p = (node*)malloc(sizeof(node));
	p -> info = x;
	p -> next = NULL;
	if(d.cuoi == NULL) {
		d.dau = d.cuoi = p;
	}
	else {
		d.cuoi -> next = p;
		d.cuoi = p;
	}
}


int demnode(danhsach &d) {
	node*i = d.dau;
	int dem = 0;
	while(i) {
		dem++;
		i = i->next;
	}
	return dem;
}

void themvitrik(danhsach &d) {
	int k;
	scanf("%d", &k);
	if(k <= 0) {
		themdau(d);
	}
	else if(k >= demnode(d)){
		themcuoi(d);
	}
	else {
		int vt = 0;
		node*p = d.dau;
		int x;
		scanf("%d",&x);
		node*q = (node*)malloc(sizeof(node));
		q->info = x;
		q->next = NULL;
		while (vt != k - 1 && p->next != NULL) {
			vt++;
			p = p-> next;
		}
		q -> next = p -> next;
		p -> next = q;
	}
}



void hiendanhsach(danhsach &d) {
	node*i = d.dau;
	while(i) {
		printf("%d\t", i->info);
		i = i->next;
	}
}



void xoadau(danhsach &d) {
//	node*p = (node*)malloc(sizeof(node));
	if(!d.dau) {
		return;
	}
	else if(d.dau == d.cuoi) {
		d.dau = d.cuoi = NULL;
	}
	else {
		node*p = d.dau;
		d.dau = p->next;
	}
}

void xoacuoi(danhsach &d) {
	if(!d.cuoi) {
		return;
	}
	else if(d.dau == d.cuoi) {
		d.dau = d.cuoi = NULL;
	}
	else {
		node*p = d.dau;
		node*q = (node*)malloc(sizeof(node));
		while(p->next != NULL) {
			q = p;
			p = p->next;
		}
		q -> next = NULL;
		d.cuoi = q;
	}
}

void xoavitrik(danhsach &d) {
	int k;
	scanf("%d", &k);
	if( k < 0) {
		xoadau(d);
	}
	else if( k >= demnode(d)){
		xoacuoi(d);
	}
	else {
		int vt = 0;
		node*p = d.dau;
		while(p){
			vt++;
			if(vt == k - 1 ){
				p->next = p->next->next;	
			}
			else{
				p = p->next;
			}
		}
	}
}

// sapxep
void sapxep(danhsach &d) {
	node*i,*j;
	int count = 1;
	for(i = d.dau; i; i = i -> next){
		for(j = i -> next; j;j = j -> next ){
			if(i -> info > j -> info) {
				int tg = i -> info;
				i -> info = j -> info;
				j -> info = tg;
			}
		}
		printf("buoc %d:",count);
		count++;
		hiendanhsach(d);
		printf("\n");
	}
}


int main() {
	danhsach d;
	khoitao(d);
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		themcuoi(d);
	}
	sapxep(d);
	hiendanhsach(d);
	printf("\n");
//	printf("%d",demnode(d));
//	xoadau(d);
//	xoacuoi(d);
//	xoavitrik(d);
	themvitrik(d);
	hiendanhsach(d);
	
	return 0;
}
