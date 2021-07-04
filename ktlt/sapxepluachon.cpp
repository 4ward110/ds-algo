#include <stdio.h>
#define MAX 100

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void hienmang(int a[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d", a[i]);
    }
}

void sapxepluachon(int a[], int n) {
    int i, j, min, temp;
    for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        if(min != i) {
            swap(a[i], a[min]);
        }
        printf("Buoc %d: ", i + 1);
        hienmang(a,n);
        printf("\n");
    }
}

int main() {
    int i,n, a[MAX];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sapxepluachon(a,n);
    return 0;
}