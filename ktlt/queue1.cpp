#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct queue
{
    int f, r;
    int e[MAX];
};

void khoitao(queue &q) {
    q.f = 0;
    q.r = -1;
}

int ktrarong(queue q) {
    if(q.f > q.r || q.f < 0) {
        return 1;
    }
    else {
        return 0;
    }
} 

int ktraday(queue q) {
    if(q.r == MAX) {
        return 1;
    }
    else {
        return 0;
    }
}

void put(queue &q, int x) {
    q.r++;
    if(ktraday(q)) {
        printf("queue day");
    }
    else {
        q.e[q.r] = x;
    }
}

int get(queue &q) {
    int x;
    if(ktrarong(q)) {
        printf("queue rong");
    }
    else {
        x = q.e[q.f];
        q.f++;
    }
    return x;
}


void nhap(queue &q) {
    int i,m ,x;
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &x);
        put(q,x);
    }
}

void hien(queue &q) {
    while(ktrarong(q) == 0){
        printf("%d\t", get(q));
    }
    printf("\n");
}


int main() {
    queue q;
    khoitao(q);
    nhap(q);
    hien(q);
    return 0;
}