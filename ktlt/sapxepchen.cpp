#include <stdio.h>
#define MAX 100

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void hienmang(int m[], int n) {
	int i;
	for ( i = 0; i< n; i++) {
		printf("%d\t", m[i]);
	}
}

void sapxepchen(int a[], int &n) {
    int i, j, v;
    printf("%d", a[0]);
    printf("\n");
    for(i = 1; i < n ; i++) {
        v = a[i];
        j = i;
        while(a[j - 1] > v && j >= 1) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
        hienmang(a,i+1);
        printf("\n");
    }
}


int main() {
    int i,n, a[MAX];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sapxepchen(a,n);
    return 0;
}