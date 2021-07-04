// sinh chinh hop chap k tu n phan tu tuong tu nhu sinh nhi phan

#include <stdio.h>
#include <math.h>
#define MAX 100

int n,k,a[MAX], ok = 0;

void khoitao() {
    int i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        a[i] = 1;
    }
}

void chht() {
    int j;
    for(j = 1; j <= n; j++) {
        printf("%d", a[j]);
    }
    printf("\n");
}

void sinhtiep() {
    int i = n;
    while(a[i] == 9 && i > 0) {
        i--;
    }
    if(i == 0) ok = 1;
    else {
        a[i]++;
        int j;
        for(j = i + 1; j <= n; j++) {
            a[j]  = 0;
        }
    }
}

int kiemtrasonguyento(int m) {
    int count = 0;
    int i;
    for(i = 2; i <= sqrt(m); i++) {
        if(m % i == 0)
            count = count + 1;
    }
    return count;
}

long gt(int *a, int n) {
    int s = 0, t = 1;
    int i;
    for(i = n; i >= 1; i--) {
        s = s + t*a[i];
        t  = t*10;
    }
    return s;
}

int main() {
    khoitao();
    while(!ok) {
        long b = gt(a,n);
        if(kiemtrasonguyento(b) == 0) {
            chht();
        }
        sinhtiep();
    }
    return 0;
}