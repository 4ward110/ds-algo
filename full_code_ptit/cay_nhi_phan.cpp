#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	node *right;
	node *left;
};

typedef struct node* tree;

void khoitao(tree &t) {
	t = NULL;
}

void chennode(tree &t, int x) {
	
	node*p = (node*)malloc(sizeof(node));
	p->info = x;
	p->right = p -> left = NULL;
	if(t == NULL) {
		t = p;
	}
	else  {
		if(t->info > x) {
			chennode(t->left, x);
		}
		else {
			chennode(t->right, x);
		}
	}
}

void hienLRN(tree t) {
	if(t!=NULL) {
		hienLRN(t->left);
		hienLRN(t->right);
		printf("%d ",t->info);
	}
}


int main() {
	int test;
	scanf("%d", &test);
	while(test > 0) {
		tree t;
		khoitao(t);
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			chennode(t, x);
		}
		hienLRN(t);
		printf("\n");
		test--;
	}
	
	return 0;
}
