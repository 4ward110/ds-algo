#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    node*right;
    node*left;
} *tree;

void khoitao(tree &t) {
	// khoi tao root
    t = NULL;
}

void chennode(tree &t, int x) {
	// tao bien contro kieu node
    node*p = (node*)malloc(sizeof(node));
    p->info = x;
    p->right = p->left = NULL;
    if(t == NULL) {
        t = p;
    } 
    else {
        if(t->info < x) {
            chennode(t->right, x);
        }
        else if(t->info > x) {
            chennode(t->left, x);
        }
    }
}

void nhap(tree &t){
	int n,i,a[10000];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		chennode(t,a[i]);
	}
}

void hienLRN(tree t){
	if(t!=NULL){
		hienLRN(t->left);
		hienLRN(t->right);
		printf("%d ",t->info);
	}
}

int main() {
    tree t;
    int test;
    scanf("%d", &test);
    while(test > 0) {
        khoitao(t);
        nhap(t);
        hienLRN(t);
        printf("\n");
        test--;
    }
    return 0;
}
