#include <stdio.h>
#define MAX 100


bool ok = false;
int t, n, k, a[MAX];

void khoitao() {
    scanf("%d", &t);
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i = 1; i <= k; i++) {
        a[i] = i;
    }
}

void chht() {
    int i;
    for(i = 1; i <= k; i++) {
        printf("%d", a[i]);
    }
    printf(" ");
}

void sinhtiep() {
    int i = k;
    while(a[i] == n - k + i && i> 0) {
        i--;
    }
    if (i == 0) ok = true;
    else {
        a[i]++;
        for(int j = i + 1; j <= k; j++) {
            a[j] = a[i] + j - i;
        }
    }
}

int main() {
    khoitao();
    while(t > 0) {
        while(!ok) {
            chht();
            sinhtiep();
        }
        t--;
    }
    
    return 0;
}