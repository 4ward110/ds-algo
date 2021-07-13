// Stack based linkedlist
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    node*next;
} *Pnode;

void khoitao(Pnode &H) {
    H = NULL;
}

int ktrarong(Pnode H) {
    return (H == NULL);
}

// them 

void push(Pnode &H, int x) {
    node*p;
    p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = H;
    H = p;
}

int pop(Pnode &H) {
    int x;
    node*p;
    x = H->data;
    p = H;
    H = H->next;
    free(p);
    return x;
}

void nhapstack(Pnode &H) {
    int i, m, x;
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &x);
        push(H,x);
    }
}

void hienstack(Pnode &H) {
    while(ktrarong(H) == 0) {
        printf("%d\t", pop(H));
    }
}

int main() {
    Pnode H;
    khoitao(H);
    nhapstack(H);
    hienstack(H);
    return 0;
}