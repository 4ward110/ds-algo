#include <stdio.h>
#define MAX 100

struct List{
    int n;
    int a[MAX];
};

void khoitao(List &l) {
    l.n = 0;
}

void nhaplist(List &l) {
    int i;
    scanf("%d", &l.n);
    for(i = 0; i < l.n; i++) {
        scanf("%d", &l.a[i]);
    }
}


void hienlist(List &l) {
    int j;
    for(j = 0; j < l.n; j++) {
        printf("%d ", l.a[j]);
    }
    printf("\n");
}

void chenxvtk(List &l) {
    int i, x, k;
    scanf("%d%d", &x, &k);
    if (k <= 0) {
        for(i = l.n; i > k; i--) {
            l.a[i] = l.a[i-1];
        }
        l.a[0] = x;
        l.n++;
    }
    else if(k >= l.n) {
        i = l.n;
        l.a[i] = x;
        l.n++;
    }
    else {
        for(i = l.n; i > k; i--) {
            l.a[i] = l.a[i - 1];
        }
        l.a[k] = x;
        l.n++;
    }
}

void xoavtk(List &l) {
    int i, k;
    scanf("%d", &k);
    if(k <= 0) {
        for(i = 0; i < l.n; i++) {
            l.a[i] = l.a[i+1];
        }
        l.n--;
    }
    else if (k > l.n) {
        l.n--;
    }
    else {
        for(i = k; i < l.n; i++){
            l.a[i] = l.a[i+1];
        }
        l.n--;
    } 
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sapxep(List &l) {
    int i, j;
    for(i = 0; i < l.n - 1; i++) {
        for(j = 0; j < l.n - i - 1; j++) {
            if (l.a[j] > l.a[j+ 1]) {
                swap(l.a[j], l.a[j + 1]);
            }
        }
    }
}

int main() {
    List l;
    nhaplist(l);
    // chenxvtk(l);
    hienlist(l);
    // xoavtk(l);
    sapxep(l);
    hienlist(l);
    return 0;
}