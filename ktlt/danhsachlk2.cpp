#include <stdio.h>
#include <stdlib.h>

struct SinhVien {
    int masv;
    char hoten[20];
};

struct Node
{
    SinhVien info;
    Node*next;
};

struct List
{
    Node *dau, *cuoi;
};

void khoitao(List &l) {
    l.dau = l.cuoi = NULL;
}

void themdau(List &l) {
    int x;
    Node*p = (Node*)malloc(sizeof(Node));
    scanf("%d", &x);
    p->info.masv = x;
    fgets(p->info.hoten, 20, stdin);
    p->next = NULL;
    if(l.dau == NULL) {
        l.dau = l.cuoi = p;
    }
    else {
        p->next = l.dau;
        l.dau = p;
    }
}

void themcuoi(List &l) {
    int x;
    Node*p = (Node*)malloc(sizeof(Node));
    scanf("%d", &x);
    p->info.masv = x;
    fgets(p->info.hoten, 20, stdin);
    p->next = NULL;
    if((l.cuoi == NULL)) {
        l.cuoi = l.dau = p;
    }
    else {
        l.cuoi -> next = p;
        l.cuoi = p;
    }
}

void xoadau(List &l) {
    Node*q;
    Node*p = l.dau;
    q = p -> next;
    l.dau = q;
    free(p);
}

int demnode(List &l) {
    Node*i = l.dau;
    int count = 0;
    while (i)
    {
        count++;
        i = i->next;
    }
    return count;
}

void xoacuoi(List &l) {
    int t = demnode(l);
    int k = 1;
    Node*q;
    Node*p = l.dau;
    while(p != NULL && k < t) {
        k++;
        q = p;
        p = p->next;
    }
    q->next = p->next;
    l.cuoi = q;
    free(p);
}

void xoavitrik(List &l) {
    int k;
    scanf("%d", &k);
    if(k <= 0) {
        xoadau(l);
    }
    else if(k > demnode(l)) {
        xoacuoi(l);
    }
    else {
        Node*p = l.dau;
        int vt = 1;
        while(p->next != NULL && vt != k - 1) {
            vt++;
            p = p->next;
        }
        p->next = p->next->next;
    }
}

void timkiem(List &l) {
    int id;
    scanf("%d", &id);
    Node*i = l.dau;
    int count = 0;
    while(i) {
        if(i->info.masv == id) {
            printf("%d-%s",i->info.masv, i->info.hoten);
            count++;
            break;
        }
        else {
            i = i->next;
        }
    }
    if(count == 0) {
        printf("khong co trong danh sach\n");
    }
}

void hienlist(List &l) {
    Node*i = l.dau;
    while (i)
    {
        printf("%d - %s",i->info.masv, i->info.hoten);
        i = i->next;
    }
    printf("\n");
}

int main() {
    List l;
    khoitao(l);
    int i, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        // themdau(l);
        themcuoi(l);
    }
    // xoadau(l);
    // xoacuoi(l);
    // xoavitrik(l);
    timkiem(l);
    // hienlist(l);
    return 0;
}