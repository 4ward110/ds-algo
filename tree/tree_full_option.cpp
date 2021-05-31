#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	node*trai,*phai;
};
typedef node*tree;
void khoitao(tree &t){
	t=NULL;
}
void chennode(tree &t,int x){
	node*p=(node*)malloc(sizeof(node));
	p->info=x;
	p->trai=p->phai=NULL;
	if(t==NULL){
		t=p;
	}else{
		if(t->info<x){
			chennode(t->phai,x);
		}else if(t->info>x){
			chennode(t->trai,x);
		}
	}
}
void nhap(tree &t){
	int n,i,a[100];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		chennode(t,a[i]);
	}
}
void hien(tree t){
	if(t!=NULL){
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
void hienNLR(tree t){
	if(t!=NULL){
		printf("%d\t",t->info);
		hienNLR(t->trai);
		hienNLR(t->phai);
	}
}
void hienLRN(tree t){
	if(t!=NULL){
		hienLRN(t->trai);
		hienLRN(t->phai);
		printf("%d\t",t->info);
	}
}
node*Timkiem(tree t,int x){
	if(t!=NULL){
		if(t->info==x){
			node*p=t;
			return p;
		}
		if(t->info > x)
		return Timkiem(t->trai,x);
		if(t->info < x)
		return Timkiem(t->phai,x);
	}
	return NULL;
}
void huycay(tree &t){
	if(t!=NULL){
		huycay(t->trai);
		huycay(t->phai);
		delete t;
		t=NULL;
	}
}
int main(){
	tree t;
	khoitao(t);
	int k=1;
	char c;
	while(k){
		printf("0. Thoat\n");
		printf("1. Nhap,hien TT\n");
		printf("2. Duyet cay\n");
		printf("3. Tim kiem\n");
		printf("4. Huy cay\n");
		fflush(stdin);
		scanf("%c",&c);
		switch(c){
			case '0':
				k=0;
				break;
			case '1':
				nhap(t);
				hien(t);printf("\n");
				break;
			case '2':
				hienLRN(t);printf("\n");
				hienLNR(t);printf("\n");
				hienNLR(t);printf("\n");
				break;
			case '3':{
				int x;
				scanf("%d",&x);
				node*p=Timkiem(t,x);
				if(p!=NULL)
				printf("%d\n",p->info);
				else printf("node khong ton tai\n");
				break;
			}
			case '4':{
				huycay(t);
				printf("cay huy!");
				hien(t);printf("\n");
				break;
			}
		}
	}
	return 0;
}
