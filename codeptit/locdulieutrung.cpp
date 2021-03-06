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

void loc(danhsach &d) 
{
    node*i = d.dau;
    //pickelement 1 by 1
    while(i != NULL && i->next != NULL) {
        node*p = i;
        while(p->next != NULL) {
            // if duplicate => remove it
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
    danhsach d;
    int n;
    scanf("%d", &n);
    int a[n];
    khoitao(d);
    for(int i = 0; i < n; i++) {
        themdau(d);
    }
    loc(d);
    hiendanhsach(d);
    return 0;
}