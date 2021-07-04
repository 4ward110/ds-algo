#include <stdio.h>
#define MAX 100


int n,k, a[MAX], f[MAX];

void hien() {
  int i;
  for (i = 1; i <= k; i++) {
    printf("%d", a[i]);
  }
  printf("\n");
}

// quay lui nhi phan
void Try1(int i) {
  int j;
  for (j = 0; j <= 1 ; j++) {
    a[i] = j;
    if(i == n) {
      hien();
    }
    else {
      Try1(i + 1);
    }
  }
}

// quay lui chinh hop
void Try2(int i) {
  int j;
  for (j = 1; j<= n; j++) {
    if (f[j] == 0) {
      a[i] = j;
      if(i == n) {
        hien();
      }
      else {
        f[j] = 1;
        Try2(i + 1);
        f[j] = 0;
      }
    }
  }
}

// quay lui to hop

void Try3(int i) {
  int j;
  for(j = a[i - 1] + 1; j <= (n - k + i); j++) {
    a[i] = j;
    if( i == k) {
      hien();
    }
    else {
      Try1(i + 1);
    }
  }
}


int main() {

  scanf("%d%d", &n, &k);
  Try2(1);
  return 0;
}
