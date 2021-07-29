#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct sinhvien{
	int masv;
	char hoten[20];
	
};
struct node{
	sinhvien info;
	node*trai,*phai;
};
typedef node*tree;
void khoitao(tree &t){
	t=NULL;
}
void chennode(tree &t,sinhvien sv){
	node*p=(node*)malloc(sizeof(node));
	p->info=sv;
	p->trai=p->phai=NULL;
	if(t == NULL){
		t=p;
	}else{
		if(t->info.masv < sv.masv){
			chennode(t->phai,sv);
		}
	}
}
int main(){
	tree t;
	khoitao(t);
	return 0;
}
