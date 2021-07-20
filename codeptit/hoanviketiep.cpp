#include <stdio.h>

bool ok  = false;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// tim vi tri i = n - 1 -> i => a[i] < a[i+1]
// tiep tuc duyet tu cuoi len tuwf vi tri j = n-> i + 1 
//-> tim ra min a[j] > a[i] => swap(a[j], a[i]) 
//=> i + 1 -> n swap(a[i + 1 ], a[n]);

void sinhtiep() {
    int n;
    scanf("%d", &n);
    int x[n+5];
    for(int i = 1;i <= n; i++) {
        scanf("%d", &x[i]);
    }
    int i = n - 1;
    while(i > 0 && x[i] > x[i + 1]) i-=1;
    if(i <= 0) {
        for(int i = 1; i <= n; i++) {
            printf("%d ", i);
        }
        printf("\n");
    }
    else{
        int k = n;
        while (x[k] < x[i]) k--;
        swap(x[i], x[k]);
        int l = i + 1, r = n;
        while(l < r) {
            swap(x[l], x[r]);
            l++;
            r--;
        }
        for(int i = 1; i <= n; i++) {
            printf("%d ", x[i]);
        }
        printf("\n");
    }
}



int main() {
    // doc so luong test
    int t;
    scanf("%d", &t);
    while(t > 0) {
        sinhtiep();
        t--;
    }
    return 0;
}