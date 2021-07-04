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
    printf("%d\t", a[i]);
  }
}

void sapxepnoibot(int a[], int &n) {
  int kt;
  int i,j;
  for (i = 0; i < n - 1; i++) {
    kt = 0;
    for(j = 0; j < n - i -1; j++) {
      if(a[j] > a[j + 1]) {
        swap(a[i], a[j + 1]);
        kt = 1;
      }
    }
    if(kt == 0) break;
    printf("Buoc %d:", i + 1);
    hienmang(a,n);
    printf("\n");
  }
}



int main() {
  int i, n, a[MAX];
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sapxepnoibot(a,n);
  return 0;
}
