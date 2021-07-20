#include <stdio.h>
#include <stdlib.h>


struct node
{
    int info;
    node*next;
};

struct danhsach
{
    node *dau,*cuoi;
};

void khoitao(danhsach &d) {
    d.dau = d.cuoi = NULL;
}

void themdau(danhsach &d) {
    int i,x;
    scanf("%d", &x);
    node*p = (node*)malloc(sizeof(node));
    p->info = x;
    p->next = NULL;
    if(d.dau == NULL) {
        d.dau = d.cuoi = p;
    }
    else {
        d.cuoi -> next = p;
        d.cuoi = p;
    }
}

void hiendanhsach(danhsach d) {
    node*i = d.dau;
    while(i) {
        printf("%d ", i->info);
        i = i->next;
    }
}

int kiemtra(int x, int a[], int n) {
    for(int i = 0; i < n; i++) {
        if(a[i] == x) return 1;
        else return 0;
    }
}

void loc(danhsach &d, int a[], int n) 
{
    node*i = d.dau;
    int k = 1;
    a[0] = i->info;
    while(i) 
    {
        if(kiemtra(i->info, a, n) == 1) 
        {
            node*p = i;
            i = i->next->next;
            free(p);
            printf("y");
        }
        else {
            a[k] = i->info;
            k++;
            i = i -> next;
        }
    }
}



int main() {
    danhsach d;
    int n;
    scanf("%d", &n);
    int a[n];
    khoitao(d);
    for(int i = 0; i < n; i++) {
        themdau(d);
    }
    loc(d,a,n);
    hiendanhsach(d);
    return 0;
}