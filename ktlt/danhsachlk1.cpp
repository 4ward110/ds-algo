#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int SoNguyen;

struct Node
{
    SoNguyen info;
    Node*next;
};

struct List
{
    Node*dau,*cuoi;
};

void khoitao(List &l) {
    l.dau = l.cuoi = NULL;
}

void themdau(List &l) {
    SoNguyen x;
    scanf("%d", &x);
    Node*p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    if(l.dau == NULL) {
        l.dau = l.cuoi = p;
    }
    else {
        p -> next = l.dau;
        l.dau = p;
    }
}

void themcuoi(List &l) {
    SoNguyen x;
    scanf("%d", &x);
    Node*p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    if(l.cuoi == NULL) {
        l.dau = l.cuoi = p;
    }
    else {
        l.cuoi -> next = p;
        l.cuoi = p;
    }
}

void hienList(List l) {
    Node*i = l.dau;
    while(i) {
        printf("%d\t", i->info);
        i = i->next;
    }
    printf("\n");
}

int demnode(List &l) {
    Node*i = l.dau;
    int dem = 0;
    while(i) {
        dem++;
        i = i->next;
    }
    return dem;
}

void themvtk(List &l) {
    SoNguyen x,k,t = demnode(l);
    scanf("%d", &k);
    if(k <= 0) {
        themdau(l);
    }
    else if(k > t) {
        themcuoi(l);
    }
    else {
        scanf("%d", &x);
        Node*p = l.dau;
        Node*q = (Node*)malloc(sizeof(Node));
        q->info=x;
        q->next=NULL;
        int vt = 0;
        while(vt!=k-1 && p->next != NULL) {
            p = p->next;
            vt++;
        }
        q->next = p->next;
        p->next = q;
    }
}

void xoadau(List &l) {
    Node*p = l.dau;
    l.dau = l.dau->next;
    free(p);
    return;
}

void xoacuoi(List &l, int t) {
    int k = 1;
    Node*p = l.dau;
    Node*q;
    // int t = demnode(l);
    while(p != NULL && k < t) {
        k++;
        q = p;
        p = p->next;
    }
    q->next = p->next;
    l.cuoi = q;
    free(p);
}


void xoavtk(List &l) {
    int k, t = demnode(l);
    scanf("%d",&k);
    if(k <= 0) {
        xoadau(l);
    }
    else if(k > t) {
        xoacuoi(l,t);
    }
    else {
        Node*p = l.dau;
        int vt = 0;
        while(vt != k - 1 && p->next != NULL) {
            p = p->next;
            vt++;
        }
        p->next = p->next->next;
    }
}

void huylist(List &l) {
    Node*p = l.dau, *q;
    while(p) {
        q = p ->next;
        free(p);
        p = q;
    }
    l.dau = l.cuoi = NULL;
}

int main() {
    List l;
    khoitao(l);
    int n,i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        themcuoi(l);
    }
    hienList(l);
    // themvtk(l);
    xoavtk(l);
    // huylist(l);
    // themvtk(l);
    hienList(l);
    printf("%d", l.cuoi->info);

    return 0;
}