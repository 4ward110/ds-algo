// queue based on linkedlist

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    node* next;
};

struct Queue {
    node*H,*T;
};

void khoitao(Queue &q) {
    q.H = q.T = NULL;
}

int ktrarong(Queue q) {
    if(q.H == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void put(Queue &q, int x) {
    if(ktrarong(q)) {
        q.H = (node*)malloc(sizeof(node));
        q.H->data = x;
        q.H->next = q.T;
        q.T = q.H;
        return;
    }
    else {
        q.T->next = (node*)malloc(sizeof(node));
        q.T = q.T->next;
        q.T->data = x;
        q.T->next = NULL;
    }
}

int get(Queue &q) {
    node*p;
    int x;
    p = q.H;
    q.H = p -> next;
    x = p->data;
    free(p);
    return x;
}

void nhap(Queue &q) {
    int i, m, x;
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &x);
        put(q, x);
    }
}

void hien(Queue &q) {
    while(ktrarong(q) == 0) {
        printf("%d\t", get(q));
    }
}

int main() {
    Queue q;
    khoitao(q);
    nhap(q);
    hien(q);
    return 0;
}