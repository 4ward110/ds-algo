#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

struct node {
    int info;
    node*right,*left;
};

typedef node *tree;

void khoitao(tree &t) {
    t = NULL;
}

void chennode(tree &t, int x) {
    node*p = (node*)malloc(sizeof(node));
    p->info = x;
    p->left = p->right = NULL;
    if(t==NULL) {
        t = p;
    }
    else {
        if(t->info > x) {
            chennode(t->left, x);
        }
        else {
            chennode(t->right, x);
        }
    }
}

void nhap(tree &t) {
    int n, i, a[MAX];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        chennode(t, a[i]);
    }
}

void hien(tree t) {
    if(t != NULL) {
        printf("%d\t", t->info);
        hien(t->left);
        hien(t->right);
    }
}

void hienLNR(tree t) {
    if(t != NULL) {
        hienLNR(t->left);
        printf("%d\t", t->info);
        hienLNR(t->right);
    }
}

void hienNLR(tree t) {
    if(t != NULL) {
        printf("%d\t", t->info);
        hienNLR(t->left);
        hienNLR(t->right);
    }
}

void hienLRN(tree t) {
    if(t != NULL) {
        hienLRN(t->left);
        hienLRN(t->right);
        printf("%d\t", t->info);
    }
}

node*Timkiem(tree t, int x) {
    if(t != NULL) {
        if(t->info == x) {
            node*p = t;
            return p;
        }
        if(t->info > x) {
            return Timkiem(t->left, x);
        }
        if(t->info < x) {
            return Timkiem(t->right, x);
        }
    }
    return NULL;
}

void huycay(tree &t) {
    if(t != NULL) {
        huycay(t->left);
        huycay(t->right);
        delete t;
        t = NULL;
    }
}

int main() {
    tree t;
    khoitao(t);
    int k = 1;
    char c;
    while(k) {
        printf("0. thoat\n");
        printf("1. nhap/ hien\n");
        printf("2. duyetcay\n");
        printf("3. timkiem\n");
        printf("4. delete\n");
        fflush(stdin);
        scanf("%c", &c);
        switch (c)
        {
        case '0':
            k = 0;
            break;
        
        case '1':
            nhap(t);
            hien(t);
            printf("\n");
            break;
        case '2':
            hienLRN(t);
            printf("\n");
            break;
        case '3':
        {
            int x;
            scanf("%d", &x);
            node*p = Timkiem(t,x);
            if(p != NULL) {
                printf("%d\n", p->info);
            }
            else {
                printf("khong ton tai node\n");   
            }
            break;
        }
        case '4': {
            huycay(t);
            printf("cay huy\n");
            hien(t);
            break;
        }
        }  
    }
    return 0;
}