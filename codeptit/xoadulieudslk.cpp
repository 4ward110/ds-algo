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

void xoa(danhsach &d) 
{
    int x;
    scanf("%d", &x);
    node*i = d.dau;
    node*temp = d.dau, *pre;
    // if headnode itselfs hold the value need to delete
    while(temp != NULL && temp->info == x) {
        d.dau = temp->next;
        free(temp);
        temp = d.dau;
    }

    // other than head
    while (temp != NULL)
    {
        while (temp != NULL && temp->info != x)
        {
            pre = temp;
            temp = temp->next;
        }
        //if value not in linked list
        if(temp == NULL) {
            return;
        }
        pre->next = temp->next;
        free(temp);
        //update temp for next loop
        temp = pre->next;
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
    xoa(d);
    hiendanhsach(d);
    return 0;
}